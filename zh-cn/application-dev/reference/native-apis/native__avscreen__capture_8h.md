# native_avscreen_capture.h


## 概述

声明用于构造屏幕录制对象的Native API。

**起始版本：**

10

**相关模块:**

[AVScreenCapture](_a_v_screen_capture.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVScreenCapture_Create](_a_v_screen_capture.md#oh_avscreencapture_create) (void) | 实例化对象，创建OH_AVScreenCapture。 | 
| [OH_AVScreenCapture_Init](_a_v_screen_capture.md#oh_avscreencapture_init) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) config) | 初始化OH_AVScreenCapture相关参数。 | 
| [OH_AVScreenCapture_StartScreenCapture](_a_v_screen_capture.md#oh_avscreencapture_startscreencapture) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | 开始录屏，采集原始码流。调用后可以通过回调的监听(OH_AVScreenCaptureOnAudioBufferAvailable，OH_AVScreenCaptureOnVideoBufferAvailable)来监听当前是否有码流的产生。 | 
| [OH_AVScreenCapture_StopScreenCapture](_a_v_screen_capture.md#oh_avscreencapture_stopscreencapture) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | 结束录屏，与OH_AVScreenCapture_StartScreenCapture配合使用。调用后针对调用该接口的应用会停止录屏或屏幕共享，释放麦克风。 | 
| [OH_AVScreenCapture_StartScreenRecording](_a_v_screen_capture.md#oh_avscreencapture_startscreenrecording) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | 启动录屏，调用此接口，可采集编码后的码流。<br>**说明：** 预留接口，将在后续版本提供。 | 
| [OH_AVScreenCapture_StopScreenRecording](_a_v_screen_capture.md#oh_avscreencapture_stopscreenrecording) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | 停止录屏，与OH_AVScreenCapture_StartScreenRecording配合使用。<br>**说明：** 预留接口，将在后续版本提供。 | 
| [OH_AVScreenCapture_AcquireAudioBuffer](_a_v_screen_capture.md#oh_avscreencapture_acquireaudiobuffer) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, [OH_AudioBuffer](_o_h___audio_buffer.md) \*\*audiobuffer, [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) type) | 获取音频buffer，应用在调用时，需要对audiobuffer分配对应结构体大小的内存，否则会影响拿到音频buffer的获取。 | 
| [OH_AVScreenCapture_AcquireVideoBuffer](_a_v_screen_capture.md#oh_avscreencapture_acquirevideobuffer) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, int32_t \*fence, int64_t \*timestamp, struct [OH_Rect](_o_h___rect.md) \*region) | 获取视频buffer，应用在调用时，通过此接口来获取到视频的buffer以及时间戳等信息。 | 
| [OH_AVScreenCapture_ReleaseAudioBuffer](_a_v_screen_capture.md#oh_avscreencapture_releaseaudiobuffer) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) type) | 根据音频类型释放buffer。 | 
| [OH_AVScreenCapture_ReleaseVideoBuffer](_a_v_screen_capture.md#oh_avscreencapture_releasevideobuffer) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | 根据视频类型释放buffer。 | 
| [OH_AVScreenCapture_SetCallback](_a_v_screen_capture.md#oh_avscreencapture_setcallback) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, struct [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) callback) | 设置监听接口，通过设置监听，可以监听到调用过程中的错误信息，以及是否有可用的视频buffer和音频buffer。 | 
| [OH_AVScreenCapture_Release](_a_v_screen_capture.md#oh_avscreencapture_release) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | 释放创建的OH_AVScreenCapture实例，对应OH_AVScreenCapture_Create。 | 
| [OH_AVScreenCapture_SetMicrophoneEnabled](_a_v_screen_capture.md#oh_avscreencapture_setmicrophoneenabled) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, bool isMicrophone) | 设置麦克风开关。 | 
