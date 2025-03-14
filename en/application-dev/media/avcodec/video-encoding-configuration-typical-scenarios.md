# Video Encoding Configurations for Typical Scenarios

This topic provides recommended configuration parameters for AVCodec video encoding in various scenarios. It aims to help you configure video encoders according to your specific needs.

Video encoding is used in many scenarios, including video calls, video meetings, live streaming, video editing, and video sharing. Based on user experience requirements, these scenarios can be grouped into three main categories: low-latency, real-time streaming, and offline encoding.

This topic offers the recommended parameter settings for video encoding in these three categories. You can select the appropriate configurations based on service requirements.


## General Development Steps

**Linking Dynamic Link Libraries in the CMake Script**

```cmake
target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
target_link_libraries(sample PUBLIC libnative_media_venc.so)
```

> **NOTE**
>
> The word 'sample' in the preceding code snippet is only an example. Use the actual project directory name.
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

Low-latency encoding scenarios include video calls, video meetings, and interactive live streaming applications that require low end-to-end latency.

**How to Develop**

This section describes only the steps involved in the encoder configuration phase. You can learn the basic encoding process in [Video Encoding](video-encoding.md).

1. Verify the support for the low-latency feature.
   
   Before creating an encoder instance, check whether the video encoder supports the low-latency feature. If the feature is supported, enable it during the encoder configuration phase. Otherwise, do not configure the relevant parameters.

    ```c++
    // 1.1 Obtain the handle to the capability of the video encoder. The following uses H.265 as an example.
    OH_AVCapability *cap = OH_AVCodec_GetCapability(OH_AVCODEC_MIMETYPE_VIDEO_HEVC, true);
    // 1.2 Check whether the low-latency feature is supported.
    bool isSupported = OH_AVCapability_IsFeatureSupported(cap, VIDEO_LOW_LATENCY);
    ```

2. Set encoder parameters.

    Configure parameters suitable for low-latency encoding scenarios.

    In low-latency encoding scenarios, the recommended encoding parameters for typical resolution (using H.265 as an example) are as follows.

    | Resolution           | Frame Rate (fps)| Bit Rate (kbit/s)| Key Frame Interval (ms)| Bit Rate Control Mode|
    | ------------------| -------- | -------- | ------ | ------ |
    | 1902x1080  | 30       | 1500     | -1 |  CBR  |
    | 1280x720  | 30       | 1000     | -1 |  CBR  |
    | 960x540  | 30       | 700    | -1 |  CBR  |
    | 640x360  | 30       | 550     | -1 |  CBR  |
    | 320x180  | 20       | 200     | -1 |  CBR  |

    In the code snippet below, the following variables are used:

    **videoEnc**: pointer to a video encoder instance. For details, see step 2 in [Video Encoding Surface Mode](video-encoding.md#surface-input).

    ```c++
    // 2.1 Create an AVFormat parameter instance.
    OH_AVFormat *format = OH_AVFormat_Create();
    
    // 2.2 Fill in the encoding parameter key-value pairs (using the 1080p@30 fps SDR input source as an example).
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, 1920); // (Mandatory) Video width.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, 1080); // (Mandatory) Video height.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, AV_PIXEL_FORMAT_NV12); // (Mandatory) Format of the video source data.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_RANGE_FLAG, 0); // VUI information. The value 0 means a limited range, and 1 means a full range.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_COLOR_PRIMARIES, OH_ColorPrimary::COLOR_PRIMARY_BT709); // VUI information, color gamut of the video source.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_TRANSFER_CHARACTERISTICS, OH_TransferCharacteristic::TRANSFER_CHARACTERISTIC_BT709); // VUI information, OETF/EOTF curve.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_MATRIX_COEFFICIENTS, OH_MatrixCoefficient:: MATRIX_COEFFICIENT_BT709); // VUI information, YUV and RGB conversion matrix.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_PROFILE, OH_HEVCProfile::HEVC_PROFILE_MAIN); // Video encoder profile.
    OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, 30.0); // (Mandatory) Video frame rate.
    if (isSupported) {
        // Enable the low-latency feature: one YUV frame in, one stream data frame out.
        // Mandatory if the video encoder supports the low-latency feature (isSupported = true).
        OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENABLE_LOW_LATENCY, 1)
    }
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_I_FRAME_INTERVAL, -1); // (Mandatory) Key frame interval.
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, OH_BitrateMode::BITRATE_MODE_CBR); // (Mandatory) Set the bit rate control mode to CBR.
    OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, 1500000); // (Mandatory). Bit rate, in bit/s.
    
    // 2.3 Set the encoding parameters of the video encoder.
    int32_t ret = OH_VideoEncoder_Configure(videoEnc, format);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    // 2.4 Destroy the AVFormat instance after the configuration is complete.
    OH_AVFormat_Destroy(format);
    ```

    > **NOTE**
    > 
    > A key frame interval of -1 indicates that only the first frame is a key frame. You can dynamically configure encoder parameters during running based on transmission conditions and image quality to insert new key frames (IDR).

3. (Optional) Dynamically configure encoder parameters during running.

    For details, see step 9 in [Video Encoding Surface Mode](video-encoding.md#surface-input).

    ```c++
    // 3.1 Create an AVFormat parameter instance.
    OH_AVFormat *format = OH_AVFormat_Create();
    // 3.2 Fill in the encoding parameter key-value pairs (dynamically requesting IDR frames).
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_REQUEST_I_FRAME, true);
    // 3.3 Make the encoder parameters take effect.
    ret = OH_VideoEncoder_SetParameter(videoEnc, format);
    if (ret != AV_ERR_OK) {
        // Handle exceptions.
    }
    // 3.4 Destroy the AVFormat instance after the configuration is complete.
    OH_AVFormat_Destroy(format);
    ```
    To adapt to network fluctuations, you are advised to use the [temporally scalable video encoding](video-encoding-temporal-scalability.md) configuration.

## Real-Time Streaming Encoding Scenarios

Real-time streaming encoding is used in scenarios like entertainment live streaming and gaming live streaming, where the latency requirements for video are relatively low.

**How to Develop**

This section describes how to configure encoder parameters for real-time streaming scenarios in the encoder configuration phase. You can learn the basic encoding process in [Video Encoding](video-encoding.md).

In entertainment live streaming scenarios, the recommended encoding parameters for typical resolution (using H.265 as an example) are as follows.

| Resolution           | Frame Rate (fps)| Bit Rate (kbit/s)| Key Frame Interval (ms)| Bit Rate Control Mode|
| ------------------| -------- | -------- | ------ | ------ |
| 1080x1920  | 25       | 3000     | 2000 |  VBR  |
| 720x1080  | 25       | 1500     | 2000 |  VBR  |
| 544x960  | 25       | 1000    | 2000 |  VBR  |
| 480x864  | 25       | 800     | 2000 |  VBR  |

In gaming live streaming scenarios, the recommended encoding parameters for typical resolution (using H.265 as an example) are as follows.

| Resolution           | Frame Rate (fps)| Bit Rate (kbit/s)| Key Frame Interval (ms)| Bit Rate Control Mode|
| ------------------| -------- | -------- | ------ | ------ |
| 1080x1920  | 60      | 6000     | 5000 |  VBR  |

```c++
// 1. Create an AVFormat parameter instance.
OH_AVFormat *format = OH_AVFormat_Create();
// 2. Fill in the encoding parameter key-value pair (using the 1080p@25 fps SDR input source as an example).
OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, 1080); // (Mandatory) Video width.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, 1920); // (Mandatory) Video height.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, AV_PIXEL_FORMAT_NV12); // (Mandatory) Format of the video source data.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_RANGE_FLAG, 0); // VUI information. The value 0 means a limited range, and 1 means a full range.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_COLOR_PRIMARIES, OH_ColorPrimary::COLOR_PRIMARY_BT709); // VUI information, color gamut of the video source.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_TRANSFER_CHARACTERISTICS, OH_TransferCharacteristic::TRANSFER_CHARACTERISTIC_BT709); // VUI information, OETF/EOTF curve.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_MATRIX_COEFFICIENTS, OH_MatrixCoefficient:: MATRIX_COEFFICIENT_BT709); // VUI information, YUV and RGB conversion matrix.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PROFILE, OH_HEVCProfile::HEVC_PROFILE_MAIN); // Video encoder profile.
OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, 25.0); // (Mandatory) Video frame rate.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_I_FRAME_INTERVAL, 2000); // (Mandatory) Key frame interval, in ms.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, OH_BitrateMode::BITRATE_MODE_VBR); // (Mandatory) Set the bit rate control mode to VBR.
OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, 3000000); // (Mandatory). Bit rate, in bit/s.
// 3. Set the encoding parameters of the video encoder.
int32_t ret = OH_VideoEncoder_Configure(videoEnc, format);
if (ret != AV_ERR_OK) {
    // Handle exceptions.
}
// 4. Destroy the AVFormat instance after the configuration is complete.
OH_AVFormat_Destroy(format);
```


## Offline Encoding Scenarios

Offline encoding is used in scenarios such as video editing and video sharing.


**How to Develop**

This section describes how to configure encoder parameters for offline editing scenarios in the encoder configuration phase. You can learn the basic encoding process in [Video Encoding](video-encoding.md).

In video editing scenarios, the recommended encoding parameters for typical resolution (using H.265 as an example) are as follows.

| Resolution           | Frame Rate (fps)| Bit Rate (kbit/s)| Key Frame Interval (ms)| Bit Rate Control Mode|
| ------------------| -------- | -------- | ------ | ------ |
| 3840x2160  | 30       | 25000     | 5000 |  VBR  |
| 2560x1440  | 30       | 15000     | 5000 |  VBR  |
| 1920x1080  | 30       | 10000    | 5000 |  VBR  |
| 1280x720  | 30       | 5000     | 5000 |  VBR  |
| 854x480  | 30       | 2000     | 5000 |  VBR  |

In video sharing scenarios, the recommended encoding parameters for typical resolution (using H.265 as an example) are as follows.

| Resolution           | Frame Rate (fps)| Bit Rate (kbit/s)| Key Frame Interval (ms)| Bit Rate Control Mode|
| ------------------| -------- | -------- | ------ | ------ |
| 3840x2160  | 30       | 5600     | 5000 |  VBR  |
| 2560x1440  | 30       | 4900     | 5000 |  VBR  |
| 1920x1080  | 30       | 2100    | 5000 |  VBR  |
| 1280x720  | 30       | 1400     | 5000 |  VBR  |
| 854x480  | 30       | 400     | 5000 |  VBR  |

```c++
// 1. Create an AVFormat parameter instance.
OH_AVFormat *format = OH_AVFormat_Create();
// 2. Fill in the encoding parameter key-value pair (using the 1080p@30 fps SDR input source as an example).
OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, 1920); // (Mandatory) Video width.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, 1080); // (Mandatory) Video height.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, AV_PIXEL_FORMAT_NV12); // (Mandatory) Format of the video source data.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_RANGE_FLAG, 0); // VUI information. The value 0 means a limited range, and 1 means a full range.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_COLOR_PRIMARIES, OH_ColorPrimary::COLOR_PRIMARY_BT709); // VUI information, color gamut of the video source.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_TRANSFER_CHARACTERISTICS, OH_TransferCharacteristic::TRANSFER_CHARACTERISTIC_BT709); // VUI information, OETF/EOTF curve.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_MATRIX_COEFFICIENTS, OH_MatrixCoefficient:: MATRIX_COEFFICIENT_BT709); // YUV and RGB conversion matrix.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PROFILE, OH_HEVCProfile::HEVC_PROFILE_MAIN); // Video encoder profile.
OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, 30.0); // (Mandatory) Video frame rate.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_I_FRAME_INTERVAL, 5000); // (Mandatory) Key frame interval, in ms.
OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, OH_BitrateMode::BITRATE_MODE_VBR); // (Mandatory) Set the bit rate control mode to VBR.
OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, 2100000); // (Mandatory). Bit rate, in bit/s.
// 3. Set the encoding parameters of the video encoder.
int32_t ret = OH_VideoEncoder_Configure(videoEnc, format);
if (ret != AV_ERR_OK) {
    // Handle exceptions.
}
// 4. Destroy the AVFormat instance after the configuration is complete.
OH_AVFormat_Destroy(format);
```
