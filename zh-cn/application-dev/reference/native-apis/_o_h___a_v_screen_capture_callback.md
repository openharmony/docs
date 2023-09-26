# OH_AVScreenCaptureCallback


## 概述

OH_AVScreenCapture中所有异步回调函数指针的集合。将该结构体的实例注册到OH_AVScreenCapture实例中， 并处理回调上报的信息，以保证OH_AVScreenCapture的正常运行。

**系统能力**：SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

**相关模块:**

[AVScreenCapture](_a_v_screen_capture.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| **onError** | [OH_AVScreenCaptureOnError](_a_v_screen_capture.md#oh_avscreencaptureonerror) | 
| **onAudioBufferAvailable** | [OH_AVScreenCaptureOnAudioBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonaudiobufferavailable) | 
| **onVideoBufferAvailable** | [OH_AVScreenCaptureOnVideoBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonvideobufferavailable) | 
