# OH_AVScreenCaptureCallback
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

```c
typedef struct OH_AVScreenCaptureCallback {...} OH_AVScreenCaptureCallback
```

## 概述

OH_AVScreenCaptureCallback是OH_AVScreenCapture中所有异步回调函数指针的集合。应用将该结构体的实例注册到OH_AVScreenCapture实例中，以便处理回调上报的信息，从而保证OH_AVScreenCapture的正常运行。该回调集合用于监控录屏过程中的错误、音频数据和视频数据的产生，适用于需要实时获取和处理录屏数据的场景，具有异步处理的特点，能有效提升录屏数据处理的效率。

从API version 12开始，推荐使用接口[OH_AVScreenCapture_OnError](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onerror)、[OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable)替代。

**起始版本：** 10

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

**所在头文件：** [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [OH_AVScreenCaptureOnError](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonerror) onError | 录屏调用操作发生错误时触发的回调函数。当录屏过程中出现权限缺失、编码异常等错误时触发回调，开发者可根据错误类型进行重试或向用户提示。需先将包含该回调的结构体实例注册到OH_AVScreenCapture实例中，才能接收错误回调上报信息。可能上报的错误码请参考[OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode)。<br>从API version 12开始，推荐使用接口[OH_AVScreenCapture_OnError](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onerror)替代。 |
| [OH_AVScreenCaptureOnAudioBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonaudiobufferavailable) onAudioBufferAvailable | 音频缓冲区有数据可用时触发的回调函数，当录屏过程中音频数据就绪时触发回调，开发者可在此回调中获取音频缓冲区数据进行音频录制、编码或直播推流等处理。需先将包含该回调的结构体实例注册到OH_AVScreenCapture实例中，才能接收音频数据回调上报信息。<br>从API version 12开始，推荐使用接口[OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable)替代。 |
| [OH_AVScreenCaptureOnVideoBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencaptureonvideobufferavailable) onVideoBufferAvailable | 视频缓冲区有数据可用时触发的回调函数，当录屏过程中视频数据就绪时触发回调，开发者可在此回调中获取视频缓冲区数据进行视频录制、编码或直播推流等处理。需先将包含该回调的结构体实例注册到OH_AVScreenCapture实例中，才能接收视频数据回调上报信息。<br>从API version 12开始，推荐使用接口[OH_AVScreenCapture_OnBufferAvailable](capi-native-avscreen-capture-base-h.md#oh_avscreencapture_onbufferavailable)替代。 |


