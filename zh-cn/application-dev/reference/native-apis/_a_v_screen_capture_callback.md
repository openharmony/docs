# OH_AVScreenCaptureCallback


## 概述

OH_AVScreenCapture中所有异步回调函数指针的集合。将该结构体的实例注册到OH_AVScreenCapture实例中， 并处理回调上报的信息，以保证OH_AVScreenCapture的正常运行。

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

9

**相关模块：**

[AVSCreenCaptureBase](_a_v_screen_capture_base.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [onError](#onerror) | 监控录屏调用操作错误，请参见[OH_AVScreenCaptureOnError](_a_v_screen_capture_base.md#oh_avscreencaptureonerror)。 | 
| [onAudioBufferAvailable](#onaudiobufferavailable) | 监控音频码流是否有数据产生[OH_AVScreenCaptureOnAudioBufferAvailable](_a_v_screen_capture_base.md#oh_avscreencaptureonaudiobufferavailable)。 | 
| [onVideoBufferAvailable](#onvideobufferavailable) | 监控视频码流是否有数据产生[OH_AVScreenCaptureOnVideoBufferAvailable](_a_v_screen_capture_base.md#oh_avscreencaptureonvideobufferavailable)。 |


## 结构体成员变量说明


### onError

  
```
OH_AVScreenCaptureOnError onError
```

**描述：**

监控录屏调用操作错误，请参见[OH_AVScreenCaptureOnError](_a_v_screen_capture_base.md#oh_avscreencaptureonerror)

**起始版本：**

10


### onAudioBufferAvailable

  
```
OH_AVScreenCaptureOnAudioBufferAvailable onAudioBufferAvailable
```

**描述：**

监控音频码流是否有数据产生[OH_AVScreenCaptureOnAudioBufferAvailable](_a_v_screen_capture_base.md#oh_avscreencaptureonaudiobufferavailable)

**起始版本：**

10


### onVideoBufferAvailable

  
```
OH_AVScreenCaptureOnVideoBufferAvailable onVideoBufferAvailable
```

**描述：**

监控视频码流是否有数据产生[OH_AVScreenCaptureOnVideoBufferAvailable](_a_v_screen_capture_base.md#oh_avscreencaptureonvideobufferavailable)

**起始版本：**

10