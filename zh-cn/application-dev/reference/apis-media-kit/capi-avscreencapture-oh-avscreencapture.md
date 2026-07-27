# OH_AVScreenCapture
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_AVScreenCapture OH_AVScreenCapture
```

## 概述

通过OH_AVScreenCapture可以获取视频与音频的原始码流。

开发者需通过相关接口创建实例并配置采集参数后进行屏幕录制以获取码流数据。详细的模块设计逻辑与实现机制请参见[AVScreenCapture](capi-avscreencapture.md)。适用于屏幕录制、直播推流等需要捕获屏幕内容及系统/麦克风音频的场景，可帮助应用实现高质量的屏幕采集与音视频数据获取。

**起始版本：** 10

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

**所在头文件：** [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

