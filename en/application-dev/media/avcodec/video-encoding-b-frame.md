# B-Frame Video Encoding

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @jiangfan56-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @zengyawen-->

Starting from API version 20, B-frame video encoding is supported.

B-frames, short for Bidirectional Predictive Frames, are one of the primary frame types defined in video encoding standards. The main difference between B-frames and P-frames is that while P-frames support only forward prediction, B-frames support bidirectional prediction.

The prediction process in B-frame encoding utilizes information from both preceding and succeeding frames, which can significantly reduce temporal redundancy in the signal and achieve higher compression efficiency.

Enabling B-frames has the following impacts:
- Enabling B-frames increases the distance between reference frames for P-frame encoding, which may affect the compression ratio and visual quality of P-frames. Generally, in scenarios with complex temporal dynamics, the combined impact of P-frames and B-frames should be considered.
- Enabling B-frames also increases the end-to-end latency for both encoding and decoding.

## When to Use

- Video recording
- Editing and exporting
- Video transcoding
- Non-low-latency live streaming

## Constraints

- **Supported platforms**: This feature is platform-dependent. You can query the support using the [OH_AVCapability_IsFeatureSupported](../../reference/apis-avcodec-kit/capi-native-avcapability-h.md#oh_avcapability_isfeaturesupported) API.
- **Supported API versions**: API version 20 and later.
- **Supported encoders**: This feature is encoder-dependent. You can query the support using the [OH_AVCodec_GetCapabilityByCategory](../../reference/apis-avcodec-kit/capi-native-avcapability-h.md#oh_avcodec_getcapabilitybycategory) API.
- **Supported bit rate control modes**: VBR, CBR, SQR, and CQ.
- B-frame encoding is not supported alongside temporally scalable video encoding.
- B-frame encoding is not supported alongside long-term reference frames.

## Available APIs

B-frame encoding must be configured at the initialization phase and takes effect throughout the process. Dynamic modification is not supported.

The configuration parameters are as follows:

|Parameter|Description|Format|
|------- |------- |------- |
|OH_MD_KEY_VIDEO_ENCODER_ENABLE_B_FRAME |Enabled status of B-frame video recording.<br>B-frame encoding can be enabled only when it is supported.|int |
|OH_MD_KEY_VIDEO_ENCODER_MAX_B_FRAMES |Maximum number of B-frames supported by video encoding.<br>It is used only for query.|int |

## How to Develop

For details about basic encoding functionality, see [Video Encoding](video-encoding.md). The following are specific instructions for B-frame encoding.

1. When creating an encoder instance, check whether the video encoder supports B-frame encoding.

    ```c++
    // 1.1 Obtain the video encoder capability instance. The following uses H.265 as an example.
    OH_AVCapability *cap = OH_AVCodec_GetCapabilityByCategory(OH_AVCODEC_MIMETYPE_VIDEO_HEVC, true, HARDWARE);
    if (cap != nullptr) {
        OH_LOG_INFO("Get codec Capability sucess!");
        // 1.2 Check whether B-frame encoding is supported.
        bool isSupported = OH_AVCapability_IsFeatureSupported(cap, VIDEO_ENCODER_B_FRAME);
        int32_t supportedMaxBFrameCount = 0;
        if (isSupported) {
            OH_LOG_INFO("Feature VIDEO_ENCODER_B_FRAME is Supported!");
            // 1.3 Query the maximum number of B-frames that can be supported.
            OH_AVFormat *property = OH_AVCapability_GetFeatureProperties(cap, VIDEO_ENCODER_B_FRAME);
            OH_AVFormat_GetIntValue(property, OH_MD_KEY_VIDEO_ENCODER_MAX_B_FRAMES, &supportedMaxBFrameCount);
            OH_LOG_INFO("Get supportedMaxBFrameCount,value is %{public}d!", supportedMaxBFrameCount);
            // 1.4 Destroy the temporary AVFormat.
            OH_AVFormat_Destroy(property);
        } else {
            OH_LOG_ERROR("Feature VIDEO_ENCODER_B_FRAME is not Supported!");
        }
    } else {
        OH_LOG_ERROR("codec Capability is null!");
    }
    ```

    If B-frame encoding is supported, you can enable it.

2. Configure B-frame encoding during the configuration phase.

    ```c++
    // 2.1 Create a temporary AVFormat used for configuration.
    OH_AVFormat *format = OH_AVFormat_Create();
    // 2.2 Fill in the key-value pair of the parameter used to enable the feature.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODER_ENABLE_B_FRAME, 1);
    // 2.3 Set parameters.
    int32_t ret = OH_VideoEncoder_Configure(videoEnc, format);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    // 2.4 Destroy the temporary AVFormat after the configuration is complete.
    OH_AVFormat_Destroy(format);
    ```

    >**NOTE**
    > - Enabling B-frame encoding is weakly checked during the configure phase. If the parameter configuration is incorrect or the encoder does not support the feature, **AV_ERR_OK** is returned, with a warning message printed. Check whether the feature is truly enabled based on the encoded stream and runtime logs.
    > - When B-frame encoding is enabled, the actual B-frame structure and number of B-frames in the encoded stream depend on the platform's capabilities.
    >
