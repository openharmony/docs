# native_avscreen_capture.h


## 概述

声明屏幕录制相关接口,

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

**相关模块：**

[AVScreenCapture](_a_v_screen_capture.md)

## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_AVScreenCapture_Create](_a_v_screen_capture.md#oh_avscreencapture_create) (void) | 创建一个AVScreenCapture实例。 | 
| [OH_AVScreenCapture_Init](_a_v_screen_capture.md#oh_avscreencapture_init) (struct OH_AVScreenCapture \*capture, OH_AVScreenCaptureConfig config) | 根据config配置初始化一个capture对象。 |
| [OH_AVScreenCapture_StartScreenCapture](_a_v_screen_capture.md#oh_avscreencapture_startscreencapture) (struct OH_AVScreenCapture \*capture) | 启动屏幕录制。 |
| [OH_AVScreenCapture_StopScreenCapture](_a_v_screen_capture.md#oh_avscreencapture_stopscreencapture) (struct OH_AVScreenCapture \*capture) | 停止屏幕录制。 |
| [OH_AVScreenCapture_AcquireAudioBuffer](_a_v_screen_capture.md#oh_avscreencapture_acquireaudiobuffer) (struct OH_AVScreenCapture \*capture, OH_AudioBuffer \*\*audiobuffer, OH_AudioCaptureSourceType type) | 调用开始录制接口后，调用该接口进行音频buffer的申请，获取音频buffer信息。 |
| [OH_AVScreenCapture_AcquireVideoBuffer](_a_v_screen_capture.md#oh_avscreencapture_acquirevideobuffer) (struct OH_AVScreenCapture \*capture, int32_t \*fence, int64_t \*timestamp, OH_Rect \*region) | 调用开始录制接口后，调用该接口进行视频buffer的申请，获取视频buffer信息。 |
| [OH_AVScreenCapture_ReleaseAudioBuffer](_a_v_screen_capture.md#oh_avscreencapture_releaseaudiobuffer) (struct OH_AVScreenCapture \*capture, OH_AudioCaptureSourceType type) | 调用接口释放指定screencapture实例中的音频数据。 |
| [OH_AVScreenCapture_ReleaseVideoBuffer](_a_v_screen_capture.md#oh_avscreencapture_releasevideobuffer) (struct OH_AVScreenCapture \*capture) |调用接口释放指定screencapture实例中的视频数据。|
| [OH_AVScreenCapture_SetCallback](_a_v_screen_capture.md#oh_avscreencapture_setcallback) (struct OH_AVScreenCapture \*capture, struct OH_AVScreenCaptureCallback callback) | 设置回调接口通过设置监听，可以监听到调用过程中的错误信息，以及是否有可用的视频buffer和音频buffer |
| [OH_AVScreenCapture_Release](_a_v_screen_capture.md#oh_avscreencapture_release) (struct OH_AVScreenCapture \*capture) | 停止录制流程结束后，调用接口进行指定avscreencapture实例的释放。 |
| [OH_AVScreenCapture_SetMicrophoneEnabled](_a_v_screen_capture.md#oh_avscreencapture_setmicrophoneenabled) (struct OH_AVScreenCapture \*capture, bool isMicrophone) | 设置麦克风在屏幕录制期间是否启用。 |