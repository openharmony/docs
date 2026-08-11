# Video Encoding Configurations for Typical Scenarios

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @fanghuameng-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=f14aa63875cd96aa08061c51eb046c8f033e04bc translatedAt=2026-08-06T13:49:48.618Z pushedAt=2026-08-07T08:34:44.674Z -->

This topic provides recommended configuration parameters for AVCodec video encoding in various scenarios. It aims to help you configure video encoders according to your specific needs.

Video encoding is widely used in scenarios such as short-range projection (typically screen encoding and delivery between multiple devices within 10 meters), video calls, video conferencing, live streaming, video editing, and video sharing. Based on user experience requirements, these scenarios can be grouped into three categories: low-latency, real-time streaming, and offline encoding.

This topic provides the recommended encoding parameter configurations for video encoding in these three categories, helping you select appropriate parameters based on your service requirements.

## General Development Steps

**Linking Dynamic Libraries in the CMake Script**

```cmake
target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
target_link_libraries(sample PUBLIC libnative_media_venc.so)
```

> **NOTE**
>
> The word **sample** in the preceding code snippet is only an example. Use the actual project directory name.
>

**Adding Header Files**

```c++
#include <multimedia/player_framework/native_avcodec_videoencoder.h>
#include <multimedia/player_framework/native_avcapability.h>
#include <multimedia/player_framework/native_avcodec_base.h>
#include <multimedia/player_framework/native_avformat.h>
#include <fstream>
```

## Low-Latency Encoding Scenarios

Low-latency encoding scenarios include short-range projection, video calls, video conferencing, and co-host live streaming — interactive apps that require low end-to-end latency.

**How to Develop**

This section describes only the steps involved in the encoder configuration phase. You can learn the basic encoding process in [Video Encoding](video-encoding.md).

1. Set encoder parameters.

   In the encoder parameter configuration phase, configure parameters suitable for low-latency encoding scenarios.

   In low-latency short-range projection scenarios, the recommended encoding parameters for typical resolution (using H.265 as an example) are as follows:

   | Resolution (px)    | Frame Rate (fps) | Bitrate (kbps)| Access Frame Interval (ms) | Rate Control Mode |
   | ------------------| -------- | -------- | ------ | ------ |
   | 2560x1600  | 60       | 5000     | 5000 |  CBR  |
   | 1920x1080  | 60       | 3500     | 5000 |  CBR  |
   | 1280x720  | 60       | 2500     | 5000 |  CBR  |
   | 960x540  | 60       | 1500    | 5000 |  CBR  |

   In low-latency scenarios such as video calls, video conferencing, and co-host live streaming, the recommended encoding parameters for typical resolution (using H.265 as an example) are as follows:

   | Resolution (px)    | Frame Rate (fps) | Bitrate (kbps)| Access Frame Interval (ms) | Rate Control Mode |
   | ------------------| -------- | -------- | ------ | ------ |
   | 1920x1080  | 30       | 1500     | -1 |  CBR  |
   | 1280x720  | 30       | 1000     | -1 |  CBR  |
   | 960x540  | 30       | 700    | -1 |  CBR  |
   | 640x360  | 30       | 550     | -1 |  CBR  |
   | 320x180  | 20       | 200     | -1 |  CBR  |

   > **NOTE**
   > 
   > An access frame interval of -1 indicates that only the first frame is an access frame. You can dynamically configure encoder parameters during running based on transmission conditions and image quality to insert new access frames (IDR frames).

   The following uses a low-latency video call scenario as an example. The variables in the example are described as follows:

   videoEnc: pointer to a video encoder instance. For details about how to create one, see "Step 2: Create an encoder instance" in [Video Encoding in Surface Mode](video-encoding.md#surface-mode).

   ```c++
   // 1. Create an AVFormat parameter instance.
   OH_AVFormat *format = OH_AVFormat_Create(); 
   // 2. Populate encoding parameter key-value pairs (using a 1080p@30fps SDR input source as an example).
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, 1920); // Mandatory. Video pixel width.
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, 1080); // Mandatory. Video pixel height.
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, AV_PIXEL_FORMAT_NV12); // Mandatory. Video source data layout format.
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_RANGE_FLAG, 0); // VUI (Video Usability Information). Video YUV range flag. 0: limited range, 1: full range.
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_COLOR_PRIMARIES, OH_ColorPrimary::COLOR_PRIMARY_BT709); // VUI. Video source color gamut.
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_TRANSFER_CHARACTERISTICS, OH_TransferCharacteristic::TRANSFER_CHARACTERISTIC_BT709); // VUI. OETF/EOTF curve.
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_MATRIX_COEFFICIENTS, OH_MatrixCoefficient::MATRIX_COEFFICIENT_BT709); // VUI. YUV-to-RGB conversion matrix.
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_PROFILE, OH_HEVCProfile::HEVC_PROFILE_MAIN); // Video encoder profile.
   OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, 30.0); // Mandatory. Video frame rate.
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_I_FRAME_INTERVAL, -1); // Mandatory. Access frame interval.
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, OH_BitrateMode::BITRATE_MODE_CBR); // Mandatory. Rate control mode set to CBR.
   OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, 1500000); // Mandatory. Set the bitrate, in bps.
   // 3. Configure encoding parameters for the video encoder.
   int32_t ret = OH_VideoEncoder_Configure(videoEnc, format);
   if (ret != AV_ERR_OK) {
       // Exception handling.
   }
   // 4. Destroy the AVFormat instance after configuration is complete.
   OH_AVFormat_Destroy(format);
   ```

2. (Optional) Dynamically configure encoder parameters during running.

   For details, see "Step 9: Dynamically configure encoder parameters during running using `OH_VideoEncoder_SetParameter()`" in [Video Encoding in Surface Mode](video-encoding.md#surface-mode).

   ```c++
   // 1. Create an AVFormat parameter instance.
   OH_AVFormat *format = OH_AVFormat_Create();
   // 2. Populate encoding parameter key-value pairs (dynamically request an IDR frame).
   OH_AVFormat_SetIntValue(format, OH_MD_KEY_REQUEST_I_FRAME, 1);
   // 3. Apply the encoder parameters.
   ret = OH_VideoEncoder_SetParameter(videoEnc, format);
   if (ret != AV_ERR_OK) {
       // Exception handling.
   }
   // 4. Destroy the AVFormat instance after configuration.
   OH_AVFormat_Destroy(format);
   ```

   If you need to adapt to network fluctuations, it is recommended to combine this with [temporally scalable video coding](video-encoding-temporal-scalability.md) configuration.

Starting from API version 26.0.0, on platforms that support high-quality constant bitrate mode (CBRHQ), it is recommended to use the CBRHQ rate control method instead of constant bitrate (CBR). If CBRHQ is configured but the platform does not support it, the CBR rate control mode is automatically used as a fallback.

Taking a video call scenario as an example, the recommended encoding parameters for typical resolution (using H.265 as an example) are as follows:

| Resolution (px)    | Frame Rate (fps) | Bitrate (kbps)| Access Frame Interval (ms) | Rate Control Mode |
| ------------------| -------- | -------- | ------ | ------ |
| 1920x1080  | 30       | 1500     | -1 |  CBRHQ  |
| 1280x720  | 30       | 1000     | -1 |  CBRHQ  |
| 960x540  | 30       | 700    | -1 |  CBRHQ  |
| 640x360  | 30       | 550     | -1 |  CBRHQ  |
| 320x180  | 20       | 200     | -1 |  CBRHQ  |

The CBRHQ rate control method is configured as follows:

```c++
// 1. Create an AVFormat parameter instance.
OH_AVFormat *format = OH_AVFormat_Create();
// 2. Populate encoding parameter key-value pairs (using a 1080p@15fps SDR input source as an example).
OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, 1080); // Mandatory. Video pixel width.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, 1920); // Mandatory. Video pixel height.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, AV_PIXEL_FORMAT_NV12); // Mandatory. Video source data layout format.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_RANGE_FLAG, 0); // VUI, video YUV range flag. 0: limited range, 1: full range.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_COLOR_PRIMARIES, OH_ColorPrimary::COLOR_PRIMARY_BT709); // VUI, video source color gamut.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_TRANSFER_CHARACTERISTICS, OH_TransferCharacteristic::TRANSFER_CHARACTERISTIC_BT709); // VUI, OETF/EOTF curve.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_MATRIX_COEFFICIENTS, OH_MatrixCoefficient::MATRIX_COEFFICIENT_BT709); // VUI, YUV-to-RGB conversion matrix.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PROFILE, OH_HEVCProfile::HEVC_PROFILE_MAIN); // Video encoder profile.
OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, 15.0); // Mandatory. Video frame rate.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_I_FRAME_INTERVAL,10000); // Mandatory. Access frame interval, in ms.

// 3. Query CBRHQ support and select an appropriate rate control configuration.
OH_AVCapability *cap = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_HEVC, true);
if (cap == nullptr || !OH_AVCapability_IsEncoderBitrateModeSupported(cap, OH_BitrateMode::BITRATE_MODE_CBR_HIGH_QUALITY)) {
    //     // CBRHQ is not supported. Use CBR instead.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, OH_BitrateMode::BITRATE_MODE_CBR); //     // Mandatory. Rate control mode set to CBR.
} else {
    //     // CBRHQ is supported. Configure the CBRHQ rate control mode.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, OH_BitrateMode::BITRATE_MODE_CBR_HIGH_QUALITY); //     // Mandatory. Rate control mode set to CBRHQ.
}
OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, 1520000); // Mandatory. Set the bitrate, in bps.

// 4. Configure encoding parameters for the video encoder.
int32_t ret = OH_VideoEncoder_Configure(videoEnc, format);
if (ret != AV_ERR_OK) {
    //     // Exception handling.
}
// 5. Destroy the AVFormat instance after configuration is complete.
OH_AVFormat_Destroy(format);
```

## Real-Time Streaming Encoding Scenarios

Real-time streaming encoding is used in scenarios like entertainment live streaming and gaming live streaming, where the latency requirements for video are relatively low.

**How to Develop**

This section describes how to configure encoder parameters for real-time streaming scenarios in the encoder configuration phase. You can learn the basic encoding process in [Video Encoding](video-encoding.md).

In entertainment live streaming scenarios, the recommended encoding parameters for typical resolution (using H.265 as an example) are as follows.

| Resolution (px)     | Frame Rate (fps) | Bitrate (kbps)| Access Frame Interval (ms) | Rate Control Mode |
| ------------------| -------- | -------- | ------ | ------ |
| 1920x1080  | 25       | 3000     | 2000 |  VBR  |
| 1080x720  | 25       | 1500     | 2000 |  VBR  |
| 960x544  | 25       | 1000    | 2000 |  VBR  |
| 864x480  | 25       | 800     | 2000 |  VBR  |

In gaming live streaming scenarios, the recommended encoding parameters for typical resolution (using H.265 as an example) are as follows.

| Resolution (px)     | Frame Rate (fps) | Bitrate (kbps)| Access Frame Interval (ms) | Rate Control Mode |
| ------------------| -------- | -------- | ------ | ------ |
| 1920x1080  | 60      | 6000     | 5000 |  VBR  |

```c++
// 1. Create an AVFormat parameter instance.
OH_AVFormat *format = OH_AVFormat_Create();
// 2. Populate encoding parameter key-value pairs (using a 1080p@25fps SDR input source as an example).
OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, 1080); // Mandatory. Video pixel width.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, 1920); // Mandatory. Video pixel height.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, AV_PIXEL_FORMAT_NV12); // Mandatory. Video source data layout format.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_RANGE_FLAG, 0); // VUI, video YUV range flag. 0: limited range, 1: full range.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_COLOR_PRIMARIES, OH_ColorPrimary::COLOR_PRIMARY_BT709); // VUI, video source color gamut.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_TRANSFER_CHARACTERISTICS, OH_TransferCharacteristic::TRANSFER_CHARACTERISTIC_BT709); // VUI, OETF/EOTF curve.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_MATRIX_COEFFICIENTS, OH_MatrixCoefficient::MATRIX_COEFFICIENT_BT709); // VUI, YUV-to-RGB conversion matrix.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PROFILE, OH_HEVCProfile::HEVC_PROFILE_MAIN); // Video encoder profile.
OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, 25.0); // Mandatory. Video frame rate.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_I_FRAME_INTERVAL, 2000); // Mandatory. Access frame interval, in ms.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, OH_BitrateMode::BITRATE_MODE_VBR); // Mandatory. Rate control mode set to VBR.
OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, 3000000); // Mandatory. Set the bitrate, in bps.
// 3. Configure encoding parameters for the video encoder.
int32_t ret = OH_VideoEncoder_Configure(videoEnc, format);
if (ret != AV_ERR_OK) {
    //     // Exception handling.
}
// 4. Destroy the AVFormat instance after configuration is complete.
OH_AVFormat_Destroy(format);
```

Starting from API version 20, on platforms that support stable quality rate control (SQR), it is recommended to use the SQR rate control method instead of variable bitrate (VBR).

In entertainment live streaming scenarios, the recommended encoding parameters for typical resolution (using H.265 as an example) are as follows:

| Resolution (px)    | Frame Rate (fps) | SQR Quality Factor | Peak Bitrate (kbps)| Access Frame Interval (ms) | Rate Control Mode |
| ------------------| -------- | -------- | ------ | ------ | -------- |
| 1920x1080  | 25 |  25    | 3000     | 2000 |  SQR  |
| 1080x720  | 25  |  25   | 1500     | 2000 |  SQR  |
| 960x544  | 25  |  25  | 1000    | 2000 |  SQR  |
| 864x480  | 25  |  25  | 800     | 2000 |  SQR  |

In game live streaming scenarios, the recommended encoding parameters for typical resolution (using H.265 as an example) are as follows:

| Resolution (px)    | Frame Rate (fps) | SQR Quality Factor | Peak Bitrate (kbps)| Access Frame Interval (ms) | Rate Control Mode |
| ------------------| -------- | -------- | ------ | ------ | -------- |
| 1920x1080  | 60   |  25   | 6000     | 5000 |  SQR  |

The SQR rate control method is configured as follows:

```c++
// 1. Create an AVFormat parameter instance.
OH_AVFormat *format = OH_AVFormat_Create();
// 2. Fill in the encoding parameter key-value pair (using the 1080p@25 fps SDR input source as an example).
OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, 1080); // Mandatory. Video pixel width.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, 1920); // Mandatory. Video pixel height.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, AV_PIXEL_FORMAT_NV12); // (Mandatory) Format of the video source data.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_RANGE_FLAG, 0); // VUI, video YUV range flag. 0: limited range, 1: full range.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_COLOR_PRIMARIES, OH_ColorPrimary::COLOR_PRIMARY_BT709); // VUI, video source color primaries.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_TRANSFER_CHARACTERISTICS, OH_TransferCharacteristic::TRANSFER_CHARACTERISTIC_BT709); // VUI, OETF/EOTF transfer characteristics.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_MATRIX_COEFFICIENTS, OH_MatrixCoefficient::MATRIX_COEFFICIENT_BT709); // VUI, YUV-to-RGB conversion matrix.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PROFILE, OH_HEVCProfile::HEVC_PROFILE_MAIN); // Video encoder profile.
OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, 25.0); // (Mandatory) Video frame rate.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_I_FRAME_INTERVAL, 2000); // (Mandatory) Key frame interval, in ms.

// 3. Query SQR support and select an appropriate rate control configuration.
OH_AVCapability *cap = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_HEVC, true);
if (cap == nullptr || !OH_AVCapability_IsEncoderBitrateModeSupported(cap, OH_BitrateMode::BITRATE_MODE_SQR)) { 
    // SQR is not supported. Use VBR instead.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, OH_BitrateMode::BITRATE_MODE_VBR); // Mandatory. Set the rate control mode to VBR.
    OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, 3000000); // Mandatory. Set the bitrate in bps.
} else {
    // SQR is supported. Configure SQR rate control parameters.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, OH_BitrateMode::BITRATE_MODE_SQR); // Mandatory. Set the rate control mode to SQR.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_SQR_FACTOR, 25); // Required. Set the SQR quality factor. Value range: [0, 51]. A smaller value indicates higher quality.
    OH_AVFormat_SetLongValue(format, OH_MD_KEY_MAX_BITRATE, 3000000); // Mandatory. Set the peak bitrate in bps.
}

// 4. Configure encoding parameters for the video encoder.
int32_t ret = OH_VideoEncoder_Configure(videoEnc, format);
if (ret != AV_ERR_OK) {
    // Handle exceptions.
}
// 5. Destroy the AVFormat instance after configuration.
OH_AVFormat_Destroy(format);
```

## Offline Encoding Scenarios

Offline encoding is used in scenarios such as video editing and video sharing.

**How to Develop**

This section describes how to configure encoder parameters for offline editing scenarios in the encoder configuration phase. You can learn the basic encoding process in [Video Encoding](video-encoding.md).

In video editing scenarios, the recommended encoding parameters for typical resolution (using H.265 as an example) are as follows.

| Resolution (px)  | Frame Rate (fps) | Bitrate (kbps)| Access Frame Interval (ms) | Rate Control Mode |
| ------------------| -------- | -------- | ------ | ------ |
| 3840x2160  | 30       | 25000     | 5000 |  VBR  |
| 2560x1440  | 30       | 15000     | 5000 |  VBR  |
| 1920x1080  | 30       | 10000    | 5000 |  VBR  |
| 1280x720  | 30       | 5000     | 5000 |  VBR  |
| 854x480  | 30       | 2000     | 5000 |  VBR  |

In video sharing scenarios, the recommended encoding parameters for typical resolution (using H.265 as an example) are as follows.

| Resolution (px)    | Frame Rate (fps) | Bitrate (kbps)| Access Frame Interval (ms) | Rate Control Mode |
| ------------------| -------- | -------- | ------ | ------ |
| 3840x2160  | 30       | 5600     | 5000 |  VBR  |
| 2560x1440  | 30       | 4900     | 5000 |  VBR  |
| 1920x1080  | 30       | 2100    | 5000 |  VBR  |
| 1280x720  | 30       | 1400     | 5000 |  VBR  |
| 854x480  | 30       | 400     | 5000 |  VBR  |

```c++
// 1. Create an AVFormat parameter instance.
OH_AVFormat *format = OH_AVFormat_Create();
// 2. Populate encoding parameter key-value pairs (using a 1080p@30fps SDR input source as an example).
OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, 1920); // Mandatory. Video pixel width.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, 1080); // Mandatory. Video pixel height.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, AV_PIXEL_FORMAT_NV12); // Mandatory. Video source data layout format.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_RANGE_FLAG, 0); // VUI, video YUV range flag. 0: limited range, 1: full range.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_COLOR_PRIMARIES, OH_ColorPrimary::COLOR_PRIMARY_BT709); // VUI, video source color gamut.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_TRANSFER_CHARACTERISTICS, OH_TransferCharacteristic::TRANSFER_CHARACTERISTIC_BT709); // VUI, OETF/EOTF curve.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_MATRIX_COEFFICIENTS, OH_MatrixCoefficient::MATRIX_COEFFICIENT_BT709); // VUI, YUV-to-RGB conversion matrix.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PROFILE, OH_HEVCProfile::HEVC_PROFILE_MAIN); // Video encoder profile.
OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, 30.0); // Mandatory. Video frame rate.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_I_FRAME_INTERVAL, 5000); // Mandatory. Access frame interval, in ms.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, OH_BitrateMode::BITRATE_MODE_VBR); // Mandatory. Rate control mode set to VBR.
OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, 2100000); // Mandatory. Set the bitrate, in bps.
// 3. Configure encoding parameters for the video encoder.
int32_t ret = OH_VideoEncoder_Configure(videoEnc, format);
if (ret != AV_ERR_OK) {
    //     // Exception handling.
}
// 4. Destroy the AVFormat instance after configuration is complete.
OH_AVFormat_Destroy(format);
```

Starting from API version 20, on platforms that support SQR, it is recommended to use the SQR rate control method instead of VBR.

In video editing scenarios, the recommended encoding parameters for typical resolution (using H.265 as an example) are as follows:

| Resolution (px)    | Frame Rate (fps) | SQR Quality Factor | Peak Bitrate (kbps)| Access Frame Interval (ms) | Rate Control Mode |
| ------------------| -------- | -------- | ------ | ------ | ------ |
| 3840x2160  | 30   | 25    | 25000     | 5000 |  SQR  |
| 2560x1440  | 30   | 25    | 15000     | 5000 |  SQR  |
| 1920x1080  | 30   | 25    | 10000    | 5000 |  SQR  |
| 1280x720  | 30   | 25    | 5000     | 5000 |  SQR  |
| 854x480  | 30   | 25    | 2000     | 5000 |  SQR  |

In video sharing scenarios, the recommended encoding parameters for typical resolution (using H.265 as an example) are as follows:

| Resolution (px)    | Frame Rate (fps) | SQR Quality Factor | Peak Bitrate (kbps)| Access Frame Interval (ms) | Rate Control Mode |
| ------------------| -------- | -------- | ------ | ------ |-------- |
| 3840x2160  | 30   | 25    | 5600     | 5000 |  SQR  |
| 2560x1440  | 30   | 25    | 4900     | 5000 |  SQR  |
| 1920x1080  | 30   | 25    | 2100    | 5000 |  SQR  |
| 1280x720  | 30   | 25    | 1400     | 5000 |  SQR  |
| 854x480  | 30   | 25    | 400     | 5000 |  SQR  |

The SQR rate control method is configured as follows:

```c++
// 1. Create an AVFormat parameter instance.
OH_AVFormat *format = OH_AVFormat_Create();
// 2. Fill in the encoding parameter key-value pair (using the 1080p@30 fps SDR input source as an example).
OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, 1920); // Mandatory. Video pixel width.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, 1080); // Mandatory. Video pixel height.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, AV_PIXEL_FORMAT_NV12); // (Mandatory) Format of the video source data.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_RANGE_FLAG, 0); // VUI. Video YUV range flag. 0: limited range, 1: full range.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_COLOR_PRIMARIES, OH_ColorPrimary::COLOR_PRIMARY_BT709); // VUI. Video source color primaries.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_TRANSFER_CHARACTERISTICS, OH_TransferCharacteristic::TRANSFER_CHARACTERISTIC_BT709); // VUI. OETF/EOTF transfer characteristics.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_MATRIX_COEFFICIENTS, OH_MatrixCoefficient::MATRIX_COEFFICIENT_BT709); // VUI. YUV-to-RGB conversion matrix.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PROFILE, OH_HEVCProfile::HEVC_PROFILE_MAIN); // Video encoder profile.
OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, 30.0); // (Mandatory) Video frame rate.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_I_FRAME_INTERVAL, 5000); // (Mandatory) Key frame interval, in ms.

// 3. Query SQR support and select an appropriate rate control configuration.
OH_AVCapability *cap = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_HEVC, true);
if (cap == nullptr || !OH_AVCapability_IsEncoderBitrateModeSupported(cap, OH_BitrateMode::BITRATE_MODE_SQR)) { 
    //     // SQR is not supported. Use VBR instead.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, OH_BitrateMode::BITRATE_MODE_VBR); //     // Mandatory. Set the rate control mode to VBR.
    OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, 2100000); //     // Mandatory. Set the bitrate in bps.
} else {
    //     // SQR is supported. Configure SQR rate control parameters.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, OH_BitrateMode::BITRATE_MODE_SQR); //     // Mandatory. Set the rate control mode to SQR.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_SQR_FACTOR, 25); //     // Mandatory. Set the SQR quality factor. Value range: [0, 51]. A smaller value indicates higher quality.
    OH_AVFormat_SetLongValue(format, OH_MD_KEY_MAX_BITRATE, 2100000); //     // Mandatory. Set the peak bitrate in bps.
}

// 4. Configure the encoding parameters of the video encoder.
int32_t ret = OH_VideoEncoder_Configure(videoEnc, format);
if (ret != AV_ERR_OK) {
    // Handle exceptions.
}
// 5. Destroy the AVFormat instance after configuration is complete.
OH_AVFormat_Destroy(format);
```

## Precautions

The encoding recommendations in this guide should be further optimized based on specific service conditions in actual use. At a given bitrate, the encoding quality of a video can vary significantly depending on the spatiotemporal complexity of the video content being encoded. Generally, video content with complex motion and rich texture is prone to blurring or blocking artifacts when the bitrate is insufficient. In such cases, a higher bitrate must be configured.