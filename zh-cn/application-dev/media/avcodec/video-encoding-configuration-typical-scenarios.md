# 典型场景的视频编码配置

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @fanghuameng-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @zengyawen-->

此文档描述了AVCodec视频编码能力在不同应用场景下的推荐配置参数，供开发者根据实际应用场景进行视频编码应用的开发。

视频编码在视频通话、视频会议、直播、视频编辑、视频分享等场景均有广泛使用，按照体验要求，上述场景可归纳划分为低时延、实时流媒体、离线编码三大类别应用场景。

本文将给出三大类别应用场景下视频编码的推荐参数配置，供开发者根据不同的应用场景下的需求进行参数配置选择。


## 通用开发步骤

**在CMake脚本中链接动态库**

```cmake
target_link_libraries(sample PUBLIC libnative_media_codecbase.so)
target_link_libraries(sample PUBLIC libnative_media_core.so)
target_link_libraries(sample PUBLIC libnative_media_venc.so)
```

> **说明：**
>
> 上述'sample'字样仅为示例，此处由开发者根据实际工程目录自定义。
>

**添加头文件**

```c++
#include <multimedia/player_framework/native_avcodec_videoencoder.h>
#include <multimedia/player_framework/native_avcapability.h>
#include <multimedia/player_framework/native_avcodec_base.h>
#include <multimedia/player_framework/native_avformat.h>
#include <fstream>
```

## 低时延场景

低时延编码场景包括视频通话、视频会议、连麦直播等对端到端时延要求较高的交互式应用。

**开发指导**

基础编码流程请参考[视频编码](video-encoding.md)，下面仅针对编码器配置阶段做具体说明。

1. 配置编码器参数。

    在配置编码器参数阶段，配置适合低时延编码场景的参数。
    
    低时延编码场景，典型分辨率的编码参数（以H.265为例）推荐如下：

    | 分辨率            | 帧率（fps） | 码率（kpbs）| 接入帧间隔（ms） | 码控模式 |
    | ------------------| -------- | -------- | ------ | ------ |
    | 1920x1080  | 30       | 1500     | -1 |  CBR  |
    | 1280x720  | 30       | 1000     | -1 |  CBR  |
    | 960x540  | 30       | 700    | -1 |  CBR  |
    | 640x360  | 30       | 550     | -1 |  CBR  |
    | 320x180  | 20       | 200     | -1 |  CBR  |


    示例中的变量说明如下：
    - videoEnc：视频编码器实例的指针。创建方式可参考[视频编码Surface模式](video-encoding.md#surface模式)“步骤-2：创建编码器实例对象”。

    ```c++
    // 1.1 创建AVFormat参数实例。
    OH_AVFormat *format = OH_AVFormat_Create();

    // 1.2 填充编码参数键值对（以1080p@30fps SDR输入源为例）。
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, 1920); // 必须配置，视频宽。
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, 1080); // 必须配置，视频高。
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, AV_PIXEL_FORMAT_NV12); // 必须配置，视频源数据排布格式。
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_RANGE_FLAG, 0); // VUI信息，0:limited range 1:full range。
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_COLOR_PRIMARIES, OH_ColorPrimary::COLOR_PRIMARY_BT709); // VUI信息，视频源色域。
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_TRANSFER_CHARACTERISTICS, OH_TransferCharacteristic::TRANSFER_CHARACTERISTIC_BT709); // VUI信息，OETF/EOTF曲线。
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_MATRIX_COEFFICIENTS, OH_MatrixCoefficient:: MATRIX_COEFFICIENT_BT709); // VUI信息，YUV和RGB转换矩阵。
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_PROFILE, OH_HEVCProfile::HEVC_PROFILE_MAIN); // 视频编码器profile。
    OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, 30.0); // 必须配置，视频帧率。
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_I_FRAME_INTERVAL, -1); // 必须配置，接入帧间隔。
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, OH_BitrateMode::BITRATE_MODE_CBR); // 必须配置，码控模式配置为CBR。
    OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, 1500000); // 必须配置，设置码率，单位为bps。

    // 1.3 配置视频编码器的编码参数。
    int32_t ret = OH_VideoEncoder_Configure(videoEnc, format);
    if (ret != AV_ERR_OK) {
        // 异常处理。
    }
    // 1.4 配置完成后销毁AVFormat实例。
    OH_AVFormat_Destroy(format);
    ```
    > **注意：**
    > 接入帧间隔-1表示只有第一帧为接入帧，开发者可以根据传输情况和画质情况，在运行过程中动态配置编码器参数，实现插入新的接入帧（IDR）功能。
    > 

2. （可选）在运行过程中动态配置编码器参数。

    详情可参考[视频编码Surface模式](video-encoding.md#surface模式)“步骤-9：OH_VideoEncoder_SetParameter()在运行过程中动态配置编码器参数”。

    ```c++
    // 2.1 创建AVFormat参数实例。
    OH_AVFormat *format = OH_AVFormat_Create();
    // 2.2 填充编码参数键值对（动态请求IDR帧）。
    OH_AVFormat_SetIntValue(format, OH_MD_KEY_REQUEST_I_FRAME, 1);
    // 2.3 设置编码器参数生效。
    ret = OH_VideoEncoder_SetParameter(videoEnc, format);
    if (ret != AV_ERR_OK) {
        // 异常处理。
    }
    // 2.4 配置完成后销毁AVFormat实例。
    OH_AVFormat_Destroy(format);
    ```
    如果需要适配网络波动，推荐结合采用[时域可分层视频编码](video-encoding-temporal-scalability.md)配置。

## 实时流媒体编码

实时流媒体编码场景包括泛娱乐直播、游戏直播等对视频端到端时延要求不高的应用场景。

**开发指导**

基础编码流程请参考[视频编码](video-encoding.md)，下面仅针对编码器配置阶段，对配置实时流媒体编码场景的参数做具体说明。

娱乐直播场景，典型分辨率的编码参数（以H.265为例）推荐如下：

| 分辨率            | 帧率（fps） | 码率（kpbs）| 接入帧间隔（ms） | 码控模式 |
| ------------------| -------- | -------- | ------ | ------ |
| 1920x1080  | 25       | 3000     | 2000 |  VBR  |
| 1080x720  | 25       | 1500     | 2000 |  VBR  |
| 960x544  | 25       | 1000    | 2000 |  VBR  |
| 864x480  | 25       | 800     | 2000 |  VBR  |

游戏直播场景，典型分辨率的编码参数（以H.265为例）推荐如下：

| 分辨率            | 帧率（fps） | 码率（kpbs）| 接入帧间隔（ms） | 码控模式 |
| ------------------| -------- | -------- | ------ | ------ |
| 1920x1080  | 60      | 6000     | 5000 |  VBR  |

```c++
// 1. 创建AVFormat参数实例。
OH_AVFormat *format = OH_AVFormat_Create();
// 2. 填充编码参数键值对（以1080p@25fps SDR输入源为例）。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, 1080); // 必须配置，视频宽。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, 1920); // 必须配置，视频高。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, AV_PIXEL_FORMAT_NV12); // 必须配置，视频源数据排布格式。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_RANGE_FLAG, 0); // VUI信息，0:limited range 1:full range。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_COLOR_PRIMARIES, OH_ColorPrimary::COLOR_PRIMARY_BT709); // VUI信息，视频源色域。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_TRANSFER_CHARACTERISTICS, OH_TransferCharacteristic::TRANSFER_CHARACTERISTIC_BT709); // VUI信息，OETF/EOTF曲线。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_MATRIX_COEFFICIENTS, OH_MatrixCoefficient:: MATRIX_COEFFICIENT_BT709); // VUI信息，YUV和RGB转换矩阵。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PROFILE, OH_HEVCProfile::HEVC_PROFILE_MAIN); // 视频编码器profile。
OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, 25.0); // 必须配置，视频帧率。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_I_FRAME_INTERVAL, 2000); // 必须配置，接入帧间隔，单位为ms。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, OH_BitrateMode::BITRATE_MODE_VBR); // 必须配置，码控模式配置为VBR。
OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, 3000000); // 必须配置，设置码率，单位为bps。
// 3. 配置视频编码器的编码参数。
int32_t ret = OH_VideoEncoder_Configure(videoEnc, format);
if (ret != AV_ERR_OK) {
    // 异常处理。
}
// 4. 配置完成后销毁AVFormat实例。
OH_AVFormat_Destroy(format);
```


## 离线编码场景

离线编码场景包括视频编辑、视频分享等多种应用场景。


**开发指导**

基础编码流程请参考[视频编码](video-encoding.md)，下面仅针对编码器配置阶段，对配置离线编码场景的编码参数做具体说明。

视频编辑场景，典型分辨率的编码参数（以H.265为例）推荐如下：

| 分辨率            | 帧率（fps） | 码率（kpbs）| 接入帧间隔（ms） | 码控模式 |
| ------------------| -------- | -------- | ------ | ------ |
| 3840x2160  | 30       | 25000     | 5000 |  VBR  |
| 2560x1440  | 30       | 15000     | 5000 |  VBR  |
| 1920x1080  | 30       | 10000    | 5000 |  VBR  |
| 1280x720  | 30       | 5000     | 5000 |  VBR  |
| 854x480  | 30       | 2000     | 5000 |  VBR  |

视频分享场景，典型分辨率的编码参数（以H.265为例）推荐如下：

| 分辨率            | 帧率（fps） | 码率（kpbs）| 接入帧间隔（ms） | 码控模式 |
| ------------------| -------- | -------- | ------ | ------ |
| 3840x2160  | 30       | 5600     | 5000 |  VBR  |
| 2560x1440  | 30       | 4900     | 5000 |  VBR  |
| 1920x1080  | 30       | 2100    | 5000 |  VBR  |
| 1280x720  | 30       | 1400     | 5000 |  VBR  |
| 854x480  | 30       | 400     | 5000 |  VBR  |

```c++
// 1. 创建AVFormat参数实例。
OH_AVFormat *format = OH_AVFormat_Create();
// 2. 填充编码参数键值对（以1080p@30fps SDR输入源为例）。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_WIDTH, 1920); // 必须配置，视频宽。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_HEIGHT, 1080); // 必须配置，视频高。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PIXEL_FORMAT, AV_PIXEL_FORMAT_NV12); // 必须配置，视频源数据排布格式。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_RANGE_FLAG, 0); // VUI信息，0:limited range 1:full range。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_COLOR_PRIMARIES, OH_ColorPrimary::COLOR_PRIMARY_BT709); // VUI信息，视频源色域。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_TRANSFER_CHARACTERISTICS, OH_TransferCharacteristic::TRANSFER_CHARACTERISTIC_BT709); // VUI信息，OETF/EOTF曲线。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_MATRIX_COEFFICIENTS, OH_MatrixCoefficient:: MATRIX_COEFFICIENT_BT709); // YUV和RGB转换矩阵。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_PROFILE, OH_HEVCProfile::HEVC_PROFILE_MAIN); // 视频编码器profile。
OH_AVFormat_SetDoubleValue(format, OH_MD_KEY_FRAME_RATE, 30.0); // 必须配置，视频帧率。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_I_FRAME_INTERVAL, 5000); // 必须配置，接入帧间隔，单位为ms。
OH_AVFormat_SetIntValue(format, OH_MD_KEY_VIDEO_ENCODE_BITRATE_MODE, OH_BitrateMode::BITRATE_MODE_VBR); // 必须配置，码控模式配置为VBR。
OH_AVFormat_SetLongValue(format, OH_MD_KEY_BITRATE, 2100000); // 必须配置，设置码率，单位为bps。
// 3. 配置视频编码器的编码参数。
int32_t ret = OH_VideoEncoder_Configure(videoEnc, format);
if (ret != AV_ERR_OK) {
    // 异常处理。
}
// 4. 配置完成后销毁AVFormat实例。
OH_AVFormat_Destroy(format);
```
