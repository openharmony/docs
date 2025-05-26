# OH_AVScreenCaptureCallback

## 概述

OH_AVScreenCapture中所有异步回调函数指针的集合。将该结构体的实例注册到OH_AVScreenCapture实例中， 并处理回调上报的信息，以保证OH_AVScreenCapture的正常运行。

**起始版本：** 10

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

**所在头文件：** [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| OH_AVScreenCaptureOnError onError |  |
| OH_AVScreenCaptureOnAudioBufferAvailable onAudioBufferAvailable |  |
| OH_AVScreenCaptureOnVideoBufferAvailable onVideoBufferAvailable |  |


