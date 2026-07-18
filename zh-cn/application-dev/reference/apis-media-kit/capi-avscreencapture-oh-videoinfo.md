# OH_VideoInfo
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_VideoInfo {...} OH_VideoInfo
```

## 概述

视频信息。

用于配置屏幕录制时的视频采集参数和编码参数。该结构体包含视频采集参数（如分辨率、采集格式等）和视频编码参数，适用于需要自定义屏幕录制视频输出参数的场景。开发者根据实际需求配置相关参数后，在调用屏幕录制相关接口时使用。

**起始版本：** 10

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

**所在头文件：** [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [OH_VideoCaptureInfo](capi-avscreencapture-oh-videocaptureinfo.md) videoCapInfo | 视频采集信息，用于配置屏幕录制时的视频采集区域、分辨率等参数。 |
| [OH_VideoEncInfo](capi-avscreencapture-oh-videoencinfo.md) videoEncInfo | 视频编码参数，用于配置屏幕录制输出的编码格式、比特率和帧率，不同编码配置将影响输出视频的画质、文件大小和编码效率。 |


