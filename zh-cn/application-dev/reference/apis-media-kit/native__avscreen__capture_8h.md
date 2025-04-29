# native_avscreen_capture.h


## 概述

声明用于构造屏幕录制对象的API。

**库：** libnative_avscreen_capture.so

**引用文件：** <multimedia/player_framework/native_avscreen_capture.h>

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**相关模块：**[AVScreenCapture](_a_v_screen_capture.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \* [OH_AVScreenCapture_Create](_a_v_screen_capture.md#oh_avscreencapture_create) (void) | 实例化对象，创建OH_AVScreenCapture。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_Init](_a_v_screen_capture.md#oh_avscreencapture_init) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) config) | 初始化OH_AVScreenCapture相关参数，包括下发的音频麦克风采样相关参数（可选），音频内录采样相关参数，视频分辨率相关参数。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_StartScreenCapture](_a_v_screen_capture.md#oh_avscreencapture_startscreencapture) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | 开始录屏，采集原始码流。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_StartScreenCaptureWithSurface](_a_v_screen_capture.md#oh_avscreencapture_startscreencapturewithsurface) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, [OHNativeWindow](../apis-arkgraphics2d/_native_window.md#ohnativewindow) \*window) | 使用Surface模式录屏。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_StopScreenCapture](_a_v_screen_capture.md#oh_avscreencapture_stopscreencapture) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | 结束录屏，与OH_AVScreenCapture_StartScreenCapture配合使用。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_StartScreenRecording](_a_v_screen_capture.md#oh_avscreencapture_startscreenrecording) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | 启动录屏，调用此接口，可将录屏文件保存。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_StopScreenRecording](_a_v_screen_capture.md#oh_avscreencapture_stopscreenrecording) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | 停止录屏，与OH_AVScreenCapture_StartScreenRecording配合使用。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_AcquireAudioBuffer](_a_v_screen_capture.md#oh_avscreencapture_acquireaudiobuffer) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, [OH_AudioBuffer](_o_h___audio_buffer.md) \*\*audiobuffer, [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) type) | 获取音频buffer，应用在调用时，需要对audiobuffer分配对应结构体大小的内存，否则会影响音频buffer的获取。 | 
| [OH_NativeBuffer](_a_v_screen_capture.md#oh_nativebuffer) \* [OH_AVScreenCapture_AcquireVideoBuffer](_a_v_screen_capture.md#oh_avscreencapture_acquirevideobuffer) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, int32_t \*fence, int64_t \*timestamp, struct [OH_Rect](_o_h___rect.md) \*region) | 获取视频buffer，应用在调用时，通过此接口来获取到视频的buffer以及时间戳等信息。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ReleaseAudioBuffer](_a_v_screen_capture.md#oh_avscreencapture_releaseaudiobuffer) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) type) | 根据音频类型释放buffer。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ReleaseVideoBuffer](_a_v_screen_capture.md#oh_avscreencapture_releasevideobuffer) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | 根据视频类型释放buffer。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetCallback](_a_v_screen_capture.md#oh_avscreencapture_setcallback) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, struct [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) callback) | 设置监听接口，通过设置监听，可以监听到调用过程中的错误信息，以及是否有可用的视频buffer和音频buffer。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_Release](_a_v_screen_capture.md#oh_avscreencapture_release) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture) | 释放创建的OH_AVScreenCapture实例，对应OH_AVScreenCapture_Create。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetMicrophoneEnabled](_a_v_screen_capture.md#oh_avscreencapture_setmicrophoneenabled) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, bool isMicrophone) | 设置麦克风开关。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetStateCallback](_a_v_screen_capture.md#oh_avscreencapture_setstatecallback) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, [OH_AVScreenCapture_OnStateChange](_a_v_screen_capture.md#oh_avscreencapture_onstatechange) callback, void \*userData) | 设置状态变更处理回调方法，在开始录制前调用。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetDataCallback](_a_v_screen_capture.md#oh_avscreencapture_setdatacallback) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, [OH_AVScreenCapture_OnBufferAvailable](_a_v_screen_capture.md#oh_avscreencapture_onbufferavailable) callback, void \*userData) | 设置数据处理回调方法，在开始录制前调用。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetErrorCallback](_a_v_screen_capture.md#oh_avscreencapture_seterrorcallback) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, [OH_AVScreenCapture_OnError](_a_v_screen_capture.md#oh_avscreencapture_onerror) callback, void \*userData) | 设置错误处理回调方法，在开始录制前调用。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetCanvasRotation](_a_v_screen_capture.md#oh_avscreencapture_setcanvasrotation) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, bool canvasRotation) | 设置录屏屏幕数据旋转。 | 
| struct [OH_AVScreenCapture_ContentFilter](_a_v_screen_capture.md#oh_avscreencapture_contentfilter) \* [OH_AVScreenCapture_CreateContentFilter](_a_v_screen_capture.md#oh_avscreencapture_createcontentfilter) (void) | 创建ContentFilter。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ReleaseContentFilter](_a_v_screen_capture.md#oh_avscreencapture_releasecontentfilter) (struct [OH_AVScreenCapture_ContentFilter](_a_v_screen_capture.md#oh_avscreencapture_contentfilter) \*filter) | 释放ContentFilter。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ContentFilter_AddAudioContent](_a_v_screen_capture.md#oh_avscreencapture_contentfilter_addaudiocontent) (struct [OH_AVScreenCapture_ContentFilter](_a_v_screen_capture.md#oh_avscreencapture_contentfilter) \*filter, [OH_AVScreenCaptureFilterableAudioContent](_a_v_screen_capture.md#oh_avscreencapturefilterableaudiocontent) content) | 向ContentFilter实例添加可被过滤的声音类型。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ExcludeContent](_a_v_screen_capture.md#oh_avscreencapture_excludecontent) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, struct [OH_AVScreenCapture_ContentFilter](_a_v_screen_capture.md#oh_avscreencapture_contentfilter) \*filter) | 向OH_AVScreenCapture实例设置内容过滤器ContentFilter。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ContentFilter_AddWindowContent](_a_v_screen_capture.md#oh_avscreencapture_contentfilter_addwindowcontent) (struct [OH_AVScreenCapture_ContentFilter](_a_v_screen_capture.md#oh_avscreencapture_contentfilter) \*filter, int32_t \*windowIDs, int32_t windowCount) | 向ContentFilter实例添加可被过滤的窗口ID列表。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ResizeCanvas](_a_v_screen_capture.md#oh_avscreencapture_resizecanvas) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, int32_t width, int32_t height) | 调整屏幕的分辨率。 |  
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SkipPrivacyMode](_a_v_screen_capture.md#oh_avscreencapture_skipprivacymode) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, int32_t \*windowIDs, int32_t windowCount) | 录屏时豁免隐私窗口。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetMaxVideoFrameRate](_a_v_screen_capture.md#oh_avscreencapture_setmaxvideoframerate) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, int32_t frameRate) | 设置录屏的最大帧率。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ShowCursor](_a_v_screen_capture.md#oh_avscreencapture_showcursor) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, bool showCursor) | 设置光标显示开关。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](_a_v_screen_capture.md#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetDisplayCallback](_a_v_screen_capture.md#oh_avscreencapture_setdisplaycallback) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, [OH_AVScreenCapture_OnDisplaySelected](_a_v_screen_capture.md#oh_avscreencapture_ondisplayselected) callback, void \*userData) | 设置获取录屏屏幕Id的回调。 | 