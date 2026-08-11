# Intelligent Smooth High-Speed Playback Decoding

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yang-xiaoyu5-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=1ac1aa9f0919ac958e276337b28f315b33979ec5 translatedAt=2026-08-06T13:51:25.394Z pushedAt=2026-08-07T10:25:32.450Z -->

## Overview

Starting from API version 26.0.0, the intelligent smooth high-speed playback decoding capability is introduced, which combines hardware decoding capabilities with a human factor perception model to achieve system-level decoding performance optimization.

In traditional multimedia architectures, enabling high-speed playback causes the theoretical video frame rate to increase proportionally (for example, a 60 fps video at 3.0x requires processing 180 frames per second), leading to the following issues.

1. The display frame rate of videos on mobile devices is typically constrained by system-wide power management (often capped at 60 fps), which is far lower than the theoretical frame rate under high-speed playback. Furthermore, during high-motion scenes, due to the persistence of vision effect and reduced dynamic visual sensitivity of the human eye, forcibly decoding and rendering micro-motion frames that exceed perceptual resolution results in wasted computational resources.

2. In traditional architectures, frame dropping during speed playback is typically triggered passively at the rendering end of the app layer, by which point the decoding computation for the excess frames has already been consumed. If the app layer attempts to perform content-aware analysis proactively before decoding, it must introduce computationally expensive pixel-level calculations (such as optical flow analysis), which in turn increases overall power consumption.

With the capability, the system eliminates the need for complex pixel-level image analysis. Instead, it directly utilizes the motion vectors (MV) output by the hardware decoder and the temporal layer features of the video bitstream to precisely discard non-key frames with low visual perception weight before decoding, thereby avoiding unnecessary decoding computations. While reducing the decoding and rendering load and effectively controlling device heating, this capability delivers a smoother and more coherent playback experience than simple uniform frame dropping.

## Frame Retention Modes

The system provides the following three frame retention modes for on-demand switching.

| Mode | Working Principle | Use Scenario |
| :--- | :--- | :--- |
| **Perceptual Adaptive (ADAPTIVE)** | The system dynamically analyzes video motion characteristics based on the current playback speed passed in by the app, and prioritizes discarding non-key frames with lower visual perception weight. | **Recommended mode**. Primarily used in high-speed playback scenarios, providing a smoother experience that better aligns with human visual continuity than uniform frame dropping without content differentiation. |
| **Full Pass-Through (FULL)** | All input frames are decoded and output without frame dropping. | Suitable for non-speed or slow playback scenarios. |
| **Smooth Uniform (UNIFORM)** | The system drops frames evenly at a fixed ratio specified by the developer. | Suitable for special load reduction and speed-up scenarios, such as load reduction and cooling in high-temperature scenarios, as well as improved dragging smoothness in editing preview scenarios. |

## Parameter Description

This capability takes effect only after you actively deliver the configuration. Precisely control the behavior by configuring the following key-value pairs in [OH_AVFormat](../../reference/apis-avcodec-kit/capi-core-oh-avformat.md).

1. **OH_MD_KEY_VIDEO_DECODER_FRAME_RETENTION_MODE (Mode Configuration)**

   - Type: `int32_t`

   - Value Range: See [OH_FrameRetentionMode](../../reference/apis-avcodec-kit/capi-native-avcodec-base-h.md#oh_frameretentionmode).

   - Description: Master switch and mode selection for the capability. It is recommended to configure this parameter during the initialization stage.

2. **OH_MD_KEY_VIDEO_DECODER_SPEED (decoding speed)**

   - Type: `double`

   - Value range: strictly greater than 0.0.

   - Description: **This parameter must be configured synchronously in `ADAPTIVE` mode**, serving as the basis for dynamic system calculation.

3. **OH_MD_KEY_VIDEO_DECODER_FRAME_RETENTION_RATIO**

   - Type: `double`

   - Value Range: `[0.01, 1.0]` (for example, 0.5 indicates retaining 50% of decoded frames).

   - Description: This parameter takes effect only in `UNIFORM` mode. When the configured value is out of range or invalid, the system defaults to a target frame rate of 30 fps as a fallback.

## Constraints

- **Format Support**: This capability takes effect only in the video decoding pipeline and currently supports only H.264, H.265, and H.266 bitstream formats.

- **Parameter exception fallback**: In `UNIFORM` mode, if the specified retention ratio is invalid or not explicitly provided, the system defaults to decoding and rendering at a target output frame rate of 30 fps.

- **Hardware capability degradation**: The `ADAPTIVE` mode relies on the hardware decoder's ability to output motion vector (MV) information. On hardware platforms that cannot provide MV data, the system automatically triggers a basic fallback strategy at the underlying level (while still reporting the `ADAPTIVE` mode status externally). In this case, the system can still maintain basic smooth playback, but the optimal benefits of content-aware processing are not achieved.

- **MV information output**: The frame-dropping decision module in adaptive mode depends on MV information from the decoding process. MV information output during decoding must be enabled by configuring the `ADAPTIVE` mode at the initialization stage; enabling it mid-stream during a mode switch is not supported. If the `ADAPTIVE` mode is not configured at the initialization stage, the frame-dropping decision module cannot obtain MV information and falls back to dropping frames at fixed intervals (when the decoding frame rate is ≥ 45 fps, the target output frame rate is 45 fps; otherwise, no frames are dropped), reducing the benefits of perceptual adaptive processing. It is recommended that services requiring the `ADAPTIVE` mode complete the configuration at the initialization stage.

- **Audio-video synchronization (AV sync) safety**: The smart fluency frame-dropping mechanism only determines whether a frame is retained or discarded. It does not modify the original PTS (presentation timestamp) and DTS (decoding timestamp) information of retained frames, and therefore does not affect audio-video synchronization.

## Speed Playback Scenario Development Practice

For conventional video playback services, a strategy that combines initialization-stage configuration with dynamic switching is recommended.

- **Initialization Configuration**: It is recommended to directly configure the Perceptual Adaptive (`ADAPTIVE`) mode during the initialization stage before video playback starts. Only when the `ADAPTIVE` mode is configured during the initialization stage does the decoder output MV information for frame dropping decisions. MV information output is not supported after switching modes midway. If the `ADAPTIVE` mode is not configured during the initialization stage and is switched to midway, the frame dropping decision module cannot obtain MV information and degrades to dropping frames at fixed intervals, reducing the benefits of Perceptual Adaptive.

- **Dynamic Switching**: During playback, when the speed changes, the mode and speed parameters can still be dynamically switched through `OH_VideoDecoder_SetParameter`. When the speed returns to 1.0x or lower, full-frame decoding output is restored.

### Initialization Stage Configuration

During the initialization stage before video playback starts, only the `ADAPTIVE` mode needs to be configured. The speed parameters can be dynamically delivered as the playback speed changes during playback.

<!-- @[configure_full_baseline](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/BasicFeature/Media/AVCodec/entry/src/main/cpp/capbilities/video_decoder.cpp) -->

``` C++
int32_t VideoDecoder::Configure(const SampleInfo &sampleInfo)
{
    OH_AVFormat *format = OH_AVFormat_Create();
    CHECK_AND_RETURN_RET_LOG(format != nullptr, AVCODEC_SAMPLE_ERR_ERROR, "AVFormat create failed");

    OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, sampleInfo.videoWidth);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, sampleInfo.videoHeight);
    OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, sampleInfo.frameRate);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, sampleInfo.pixelFormat);
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_ROTATION, sampleInfo.rotation);
    if (sampleInfo.codecSyncMode) {
        OH_AVFormat_SetIntValue(format, OH_MD_KEY_ENABLE_SYNC_MODE, sampleInfo.codecSyncMode);
    }
    if (sampleInfo.isSmartFluencySupported) {
        // Configure the ADAPTIVE mode during the initialization stage to ensure that MV information is output to the frame dropping decision module during decoding.
        // MV information output requires the ADAPTIVE mode to be enabled during the initialization stage and does not support midway enabling.
        // If the ADAPTIVE mode is dynamically switched to midway, the frame dropping decision module cannot obtain MV information and falls back to dropping frames at fixed intervals.
        OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_DECODER_FRAME_RETENTION_MODE,
                                OH_FRAME_RETENTION_MODE_ADAPTIVE);
    }

    int ret = OH_VideoDecoder_Configure(decoder_, format);
    OH_AVFormat_Destroy(format);
    format = nullptr;
    CHECK_AND_RETURN_RET_LOG(ret == AV_ERR_OK, AVCODEC_SAMPLE_ERR_ERROR, "Config failed, ret: %{public}d", ret);
    return AVCODEC_SAMPLE_ERR_OK;
}
```

### On-Demand Switching at Runtime

The system supports dynamic switching of the frame retention mode at runtime. You can call `OH_VideoDecoder_SetParameter` to apply the configuration in real time. The timing at which the parameter takes effect follows the standard behavior of this API.

<!-- @[onUserSpeedChanged](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/BasicFeature/Media/AVCodec/entry/src/main/cpp/capbilities/video_decoder.cpp) -->

``` C++
int32_t VideoDecoder::OnUserSpeedChanged(double targetSpeed)
{
    OH_AVFormat *param = OH_AVFormat_Create();
    CHECK_AND_RETURN_RET_LOG(param != nullptr, AVCODEC_SAMPLE_ERR_ERROR, "AVFormat create failed");

    // Introduce epsilon to handle precision comparison for the double type.
    const double EPSILON = 1e-6;

    if (targetSpeed > 1.0 + EPSILON) {
        // Scenario: high-speed playback (e.g., 1.5x, 2.0x, 3.0x).
        // Strategy: enable the Perceptual Adaptive mode.
        OH_AVFormat_SetIntValue(param, OH_MD_KEY_VIDEO_DECODER_FRAME_RETENTION_MODE,
                                OH_FRAME_RETENTION_MODE_ADAPTIVE);
        OH_AVFormat_SetDoubleValue(param, OH_MD_KEY_VIDEO_DECODER_SPEED, targetSpeed);
    } else {
        // Scenario: Normal playback (1.0x) or slow playback (&lt;1.0x).
        // Strategy: Switch to Full Pass-through mode to ensure every frame is displayed.
        OH_AVFormat_SetIntValue(param, OH_MD_KEY_VIDEO_DECODER_FRAME_RETENTION_MODE,
                                OH_FRAME_RETENTION_MODE_FULL);
    }

    // Deliver parameters in real time to dynamically adjust the system frame retention strategy.
    int32_t ret = OH_VideoDecoder_SetParameter(decoder_, param);
    OH_AVFormat_Destroy(param);
    CHECK_AND_RETURN_RET_LOG(ret == AV_ERR_OK, AVCODEC_SAMPLE_ERR_ERROR,
                             "SetParameter failed, ret: %{public}d", ret);
    return AVCODEC_SAMPLE_ERR_OK;
}
```

## Development Practices for Other Beneficial Scenarios

In addition to the recommended use of this capability in speed playback scenarios, the following scenarios can also benefit from improved performance and user experience.

- **Load reduction and cooling in high-temperature scenarios**: When a device heats up and triggers a thermal alarm, controlling power consumption takes priority over maintaining a high frame rate. The developer can switch to `UNIFORM` mode and configure a lower frame retention ratio (for example, 0.3), reducing system load by lowering the decoding and display frame rates, thereby effectively assisting device cooling.

- **Improved drag smoothness in editing preview scenarios**: In scenarios such as video editing that require frequent progress bar dragging, decoding all intermediate frames can significantly slow down the screen refresh response. The developer can temporarily switch to `UNIFORM` mode in this state and configure a lower frame retention ratio, trading a moderate reduction in decoded intermediate frames for faster screen refresh speeds, thereby notably improving the responsiveness and smoothness of interactions.

**Example (responding to a thermal alarm):**

<!-- @[onThermalWarningReceived](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/BasicFeature/Media/AVCodec/entry/src/main/cpp/capbilities/video_decoder.cpp) -->

``` C++
int32_t VideoDecoder::OnThermalWarningReceived(double ratio)
{
    OH_AVFormat *param = OH_AVFormat_Create();
    CHECK_AND_RETURN_RET_LOG(param != nullptr, AVCODEC_SAMPLE_ERR_ERROR, "AVFormat create failed");

    // Use the UNIFORM smooth fixed-ratio mode.
    OH_AVFormat_SetIntValue(param, OH_MD_KEY_VIDEO_DECODER_FRAME_RETENTION_MODE,
                            OH_FRAME_RETENTION_MODE_UNIFORM);

    // Set the retention ratio (for example, 0.3 means only 30% of decoded frames are output).
    OH_AVFormat_SetDoubleValue(param, OH_MD_KEY_VIDEO_DECODER_FRAME_RETENTION_RATIO, ratio);

    // The setting takes effect in real time, and the system performs uniform frame dropping to reduce the overall device load.
    int32_t ret = OH_VideoDecoder_SetParameter(decoder_, param);
    OH_AVFormat_Destroy(param);
    CHECK_AND_RETURN_RET_LOG(ret == AV_ERR_OK, AVCODEC_SAMPLE_ERR_ERROR,
                             "SetParameter failed, ret: %{public}d", ret);
    return AVCODEC_SAMPLE_ERR_OK;
}
```