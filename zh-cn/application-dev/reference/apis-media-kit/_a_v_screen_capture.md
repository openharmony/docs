# AVScreenCapture


## 概述

调用本模块下的接口，应用可以完成屏幕录制的功能。

开发者可根据实际的开发需求，参考对应的开发指南及样例：

- [使用AVScreenCapture录屏取码流](../../media/media/using-avscreencapture-for-buffer.md)
- [使用AVScreenCapture录屏写文件](../../media/media/using-avscreencapture-for-file.md)

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_avscreen_capture.h](native__avscreen__capture_8h.md) | 声明用于构造屏幕录制对象的API。 | 
| [native_avscreen_capture_base.h](native__avscreen__capture__base_8h.md) | 声明用于运行屏幕录制通用的结构体、字符常量、枚举。 | 
| [native_avscreen_capture_errors.h](native__avscreen__capture__errors_8h.md) | 声明用于运行屏幕录制过程中接口调用的错误码说明。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) | 音频采样信息。 | 
| struct  [OH_AudioEncInfo](_o_h___audio_enc_info.md) | 音频编码信息。 | 
| struct  [OH_AudioInfo](_o_h___audio_info.md) | 音频信息。 | 
| struct  [OH_VideoCaptureInfo](_o_h___video_capture_info.md) | 视频录制信息。 | 
| struct  [OH_VideoEncInfo](_o_h___video_enc_info.md) | 视频编码信息。 | 
| struct  [OH_VideoInfo](_o_h___video_info.md) |视频信息。 | 
| struct  [OH_RecorderInfo](_o_h___recorder_info.md) | 录制文件信息。 | 
| struct  [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) | 屏幕录制配置参数。 | 
| struct  [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) | OH_AVScreenCapture中所有异步回调函数指针的集合。 | 
| struct  [OH_Rect](_o_h___rect.md) | 定义录屏界面的宽高以及画面信息。 | 
| struct  [OH_AudioBuffer](_o_h___audio_buffer.md) | 定义了音频数据的大小，类型，时间戳等配置信息。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_NativeBuffer](#oh_nativebuffer) [OH_NativeBuffer](#oh_nativebuffer) | 提供录屏的视频原始码流类。 | 
| typedef struct [OH_AVScreenCapture](#oh_avscreencapture) [OH_AVScreenCapture](#oh_avscreencapture) | 通过OH_AVScreenCapture可以获取视频与音频的原始码流。 | 
| typedef struct [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) | 通过OH_AVScreenCapture_ContentFilter过滤音视频内容。 | 
| typedef enum [OH_CaptureMode](#oh_capturemode-1) [OH_CaptureMode](#oh_capturemode) | 枚举，表示屏幕录制的不同模式。 | 
| typedef enum [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype-1) [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) | 枚举，表示屏幕录制时的音频源类型。 | 
| typedef enum [OH_AudioCodecFormat](#oh_audiocodecformat-1) [OH_AudioCodecFormat](#oh_audiocodecformat) | 枚举，表示音频编码格式。 | 
| typedef enum [OH_VideoCodecFormat](#oh_videocodecformat-1) [OH_VideoCodecFormat](#oh_videocodecformat) | 枚举，表示视频编码格式。 | 
| typedef enum [OH_DataType](#oh_datatype-1) [OH_DataType](#oh_datatype) | 枚举，表示屏幕录制流的数据格式。 | 
| typedef enum [OH_VideoSourceType](#oh_videosourcetype-1) [OH_VideoSourceType](#oh_videosourcetype) | 枚举，表示视频源格式。当前仅支持RGBA格式。 | 
| typedef enum [OH_ContainerFormatType](#oh_containerformattype-1) [OH_ContainerFormatType](#oh_containerformattype) | 枚举，表示屏幕录制生成的文件类型。 | 
| typedef struct [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) [OH_AudioCaptureInfo](#oh_audiocaptureinfo) | 音频采样信息。 | 
| typedef struct [OH_AudioEncInfo](_o_h___audio_enc_info.md) [OH_AudioEncInfo](#oh_audioencinfo) | 音频编码信息。 | 
| typedef struct [OH_AudioInfo](_o_h___audio_info.md) [OH_AudioInfo](#oh_audioinfo) | 音频信息。 | 
| typedef struct [OH_VideoCaptureInfo](_o_h___video_capture_info.md) [OH_VideoCaptureInfo](#oh_videocaptureinfo) | 视频录制信息。 | 
| typedef struct [OH_VideoEncInfo](_o_h___video_enc_info.md) [OH_VideoEncInfo](#oh_videoencinfo) | 视频编码信息。 | 
| typedef struct [OH_VideoInfo](_o_h___video_info.md) [OH_VideoInfo](#oh_videoinfo) | 视频信息。 | 
| typedef struct [OH_RecorderInfo](_o_h___recorder_info.md) [OH_RecorderInfo](#oh_recorderinfo) | 录制文件信息。 | 
| typedef struct [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) [OH_AVScreenCaptureConfig](#oh_avscreencaptureconfig) | 屏幕录制配置参数。 | 
| typedef void(\* [OH_AVScreenCaptureOnError](#oh_avscreencaptureonerror)) ([OH_AVScreenCapture](#oh_avscreencapture) \*capture, int32_t errorCode) | 当OH_AVScreenCapture实例运行出错时，将调用函数指针。 | 
| typedef void(\* [OH_AVScreenCaptureOnAudioBufferAvailable](#oh_avscreencaptureonaudiobufferavailable)) ([OH_AVScreenCapture](#oh_avscreencapture) \*capture, bool isReady, [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) type) | 当OH_AVScreenCapture操作期间音频缓冲区可用时，将调用函数指针。 | 
| typedef void(\* [OH_AVScreenCaptureOnVideoBufferAvailable](#oh_avscreencaptureonvideobufferavailable)) ([OH_AVScreenCapture](#oh_avscreencapture) \*capture, bool isReady) | 当OH_AVScreenCapture操作期间视频缓冲区可用时，将调用函数指针。 | 
| typedef struct [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) [OH_AVScreenCaptureCallback](#oh_avscreencapturecallback) | OH_AVScreenCapture中所有异步回调函数指针的集合。 | 
| typedef struct [OH_Rect](_o_h___rect.md) [OH_Rect](#oh_rect) | 定义录屏界面的宽高以及画面信息。 | 
| typedef struct [OH_AudioBuffer](_o_h___audio_buffer.md) [OH_AudioBuffer](#oh_audiobuffer) | 定义了音频数据的大小，类型，时间戳等配置信息。 | 
| typedef enum [OH_AVScreenCaptureStateCode](#oh_avscreencapturestatecode-1) [OH_AVScreenCaptureStateCode](#oh_avscreencapturestatecode) | 枚举，表示状态码。 | 
| typedef enum [OH_AVScreenCaptureBufferType](#oh_avscreencapturebuffertype-1) [OH_AVScreenCaptureBufferType](#oh_avscreencapturebuffertype) | 枚举，表示buffer类型。 | 
| typedef enum [OH_AVScreenCaptureFilterableAudioContent](#oh_avscreencapturefilterableaudiocontent-1) [OH_AVScreenCaptureFilterableAudioContent](#oh_avscreencapturefilterableaudiocontent) | 枚举，表示可过滤的音频类型。 | 
| typedef void(\* [OH_AVScreenCapture_OnStateChange](#oh_avscreencapture_onstatechange)) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AVScreenCaptureStateCode](#oh_avscreencapturestatecode) stateCode, void \*userData) | 当OH_AVScreenCapture实例操作期间发生状态变更时，将调用函数指针。 | 
| typedef void(\* [OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror)) ([OH_AVScreenCapture](#oh_avscreencapture) \*capture, int32_t errorCode, void \*userData) | 当OH_AVScreenCapture实例操作期间发生错误时，将调用函数指针。 | 
| typedef void(\* [OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)) ([OH_AVScreenCapture](#oh_avscreencapture) \*capture, OH_AVBuffer \*buffer, [OH_AVScreenCaptureBufferType](#oh_avscreencapturebuffertype) bufferType, int64_t timestamp, void \*userData) | 当OH_AVScreenCapture实例操作期间音频或视频缓存区可用时，将调用该函数指针。 | 
| typedef enum [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1) [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) | 屏幕录制过程中产生的不同结果码。 | 
| typedef void(\* [OH_AVScreenCapture_OnDisplaySelected](#oh_avscreencapture_ondisplayselected)) ([OH_AVScreenCapture](#oh_avscreencapture) \*capture, uint64_t displayId, void \*userData) | 当录屏事件开始时，将调用函数指针。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_CaptureMode](#oh_capturemode-1) {<br/>OH_CAPTURE_HOME_SCREEN = 0,<br/>OH_CAPTURE_SPECIFIED_SCREEN = 1,<br/>OH_CAPTURE_SPECIFIED_WINDOW = 2,<br/>OH_CAPTURE_INVAILD = -1<br/>} | 枚举，表示屏幕录制的不同模式。 | 
| [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype-1) {<br/>OH_SOURCE_INVALID = -1,<br/>OH_SOURCE_DEFAULT = 0,<br/>OH_MIC = 1,<br/>OH_ALL_PLAYBACK = 2,<br/>OH_APP_PLAYBACK = 3<br/>} | 枚举，表示屏幕录制时的音频源类型。 | 
| [OH_AudioCodecFormat](#oh_audiocodecformat-1) {<br/>OH_AUDIO_DEFAULT = 0,<br/>OH_AAC_LC = 3,<br/>OH_AUDIO_CODEC_FORMAT_BUTT<br/>} | 枚举，表示音频编码格式。 | 
| [OH_VideoCodecFormat](#oh_videocodecformat-1) {<br/>OH_VIDEO_DEFAULT = 0,<br/>OH_H264 = 2,<br/>OH_H265 = 4,<br/>OH_MPEG4 = 6,<br/>OH_VP8 = 8,<br/>OH_VP9 = 10,<br/>OH_VIDEO_CODEC_FORMAT_BUTT<br/>} | 枚举，表示视频编码格式。 | 
| [OH_DataType](#oh_datatype-1) {<br/>OH_ORIGINAL_STREAM = 0,<br/>OH_ENCODED_STREAM = 1,<br/>OH_CAPTURE_FILE = 2,<br/>OH_INVAILD = -1<br/>} | 枚举，表示屏幕录制流的数据格式。 | 
| [OH_VideoSourceType](#oh_videosourcetype-1) {<br/>OH_VIDEO_SOURCE_SURFACE_YUV = 0,<br/>OH_VIDEO_SOURCE_SURFACE_ES,<br/>OH_VIDEO_SOURCE_SURFACE_RGBA,<br/>OH_VIDEO_SOURCE_BUTT<br/>} | 枚举，表示视频源格式。当前仅支持RGBA格式。 | 
| [OH_ContainerFormatType](#oh_containerformattype) {<br/>CFT_MPEG_4A = 0,<br/>CFT_MPEG_4 = 1<br/>} | 枚举，表示屏幕录制生成的文件类型。 | 
| [OH_AVScreenCaptureStateCode](#oh_avscreencapturestatecode-1) {<br/>OH_SCREEN_CAPTURE_STATE_STARTED = 0,<br/>OH_SCREEN_CAPTURE_STATE_CANCELED = 1,<br/>OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER = 2,<br/>OH_SCREEN_CAPTURE_STATE_INTERRUPTED_BY_OTHER = 3,<br/>OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL = 4,<br/>OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE = 5,<br/>OH_SCREEN_CAPTURE_STATE_MIC_MUTED_BY_USER = 6,<br/>OH_SCREEN_CAPTURE_STATE_MIC_UNMUTED_BY_USER = 7,<br/>OH_SCREEN_CAPTURE_STATE_ENTER_PRIVATE_SCENE = 8,<br/>OH_SCREEN_CAPTURE_STATE_EXIT_PRIVATE_SCENE = 9<br/>OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES = 10<br/>} | 枚举，表示状态码。 | 
| [OH_AVScreenCaptureBufferType](#oh_avscreencapturebuffertype-1) {<br/>OH_SCREEN_CAPTURE_BUFFERTYPE_VIDEO = 0,<br/>OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_INNER = 1,<br/>OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_MIC = 2<br/>} | 枚举，表示buffer类型。 | 
| [OH_AVScreenCaptureFilterableAudioContent](#oh_avscreencapturefilterableaudiocontent-1) {<br/>OH_SCREEN_CAPTURE_NOTIFICATION_AUDIO = 0, <br/>OH_SCREEN_CAPTURE_CURRENT_APP_AUDIO = 1 <br/>} | 枚举，表示可过滤的音频类型。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1) {<br/>AV_SCREEN_CAPTURE_ERR_BASE = 0,<br/>AV_SCREEN_CAPTURE_ERR_OK = AV_SCREEN_CAPTURE_ERR_BASE,<br/>AV_SCREEN_CAPTURE_ERR_NO_MEMORY = AV_SCREEN_CAPTURE_ERR_BASE + 1,<br/>AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT = AV_SCREEN_CAPTURE_ERR_BASE + 2,<br/>AV_SCREEN_CAPTURE_ERR_INVALID_VAL = AV_SCREEN_CAPTURE_ERR_BASE + 3,<br/>AV_SCREEN_CAPTURE_ERR_IO = AV_SCREEN_CAPTURE_ERR_BASE + 4,<br/>AV_SCREEN_CAPTURE_ERR_TIMEOUT = AV_SCREEN_CAPTURE_ERR_BASE + 5,<br/>AV_SCREEN_CAPTURE_ERR_UNKNOWN = AV_SCREEN_CAPTURE_ERR_BASE + 6,<br/>AV_SCREEN_CAPTURE_ERR_SERVICE_DIED = AV_SCREEN_CAPTURE_ERR_BASE + 7,<br/>AV_SCREEN_CAPTURE_ERR_INVALID_STATE = AV_SCREEN_CAPTURE_ERR_BASE + 8,<br/>AV_SCREEN_CAPTURE_ERR_UNSUPPORT = AV_SCREEN_CAPTURE_ERR_BASE + 9,<br/>AV_SCREEN_CAPTURE_ERR_EXTEND_START = AV_SCREEN_CAPTURE_ERR_BASE + 100<br/>} | 屏幕录制过程中产生的不同结果码。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| struct [OH_AVScreenCapture](#oh_avscreencapture) \* [OH_AVScreenCapture_Create](#oh_avscreencapture_create) (void) | 创建OH_AVScreenCapture。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_Init](#oh_avscreencapture_init) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) config) | 初始化OH_AVScreenCapture相关参数，包括下发的音频麦克风采样相关参数（可选），音频内录采样相关参数，视频分辨率相关参数。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_StartScreenCapture](#oh_avscreencapture_startscreencapture) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | 开始录屏，采集原始码流。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_StartScreenCaptureWithSurface](#oh_avscreencapture_startscreencapturewithsurface) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, OHNativeWindow \*window) | 使用Surface模式录屏。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_StopScreenCapture](#oh_avscreencapture_stopscreencapture) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | 结束录屏，与OH_AVScreenCapture_StartScreenCapture配合使用。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_StartScreenRecording](#oh_avscreencapture_startscreenrecording) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | 启动录屏，调用此接口，可将录屏文件保存。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_StopScreenRecording](#oh_avscreencapture_stopscreenrecording) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | 停止录屏，与OH_AVScreenCapture_StartScreenRecording配合使用。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AudioBuffer](_o_h___audio_buffer.md) \*\*audiobuffer, [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) type) | 获取音频buffer，应用在调用时，需要对audiobuffer分配对应结构体大小的内存，否则会影响音频buffer的获取。  | 
| [OH_NativeBuffer](#oh_nativebuffer) \* [OH_AVScreenCapture_AcquireVideoBuffer](#oh_avscreencapture_acquirevideobuffer) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, int32_t \*fence, int64_t \*timestamp, struct [OH_Rect](_o_h___rect.md) \*region) | 获取视频buffer，应用在调用时，通过此接口来获取到视频的buffer以及时间戳等信息。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ReleaseAudioBuffer](#oh_avscreencapture_releaseaudiobuffer) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) type) | 根据音频类型释放buffer。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ReleaseVideoBuffer](#oh_avscreencapture_releasevideobuffer) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | 根据视频类型释放buffer。当某一帧视频buffer使用完成后，调用此接口进行释放对应的视频buffer。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetCallback](#oh_avscreencapture_setcallback) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, struct [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) callback) | 设置监听接口，通过设置监听，可以监听到调用过程中的错误信息，以及是否有可用的视频buffer和音频buffer。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_Release](#oh_avscreencapture_release) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | 释放创建的OH_AVScreenCapture实例，对应OH_AVScreenCapture_Create。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetMicrophoneEnabled](#oh_avscreencapture_setmicrophoneenabled) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, bool isMicrophone) | 设置麦克风开关。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetStateCallback](#oh_avscreencapture_setstatecallback) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AVScreenCapture_OnStateChange](#oh_avscreencapture_onstatechange) callback, void \*userData) | 设置状态变更处理回调方法，在开始录制前调用。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetDataCallback](#oh_avscreencapture_setdatacallback) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable) callback, void \*userData) | 设置数据处理回调方法，在开始录制前调用。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetErrorCallback](#oh_avscreencapture_seterrorcallback) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror) callback, void \*userData) | 设置错误处理回调方法，在开始录制前调用。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetCanvasRotation](#oh_avscreencapture_setcanvasrotation) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, bool canvasRotation) | 设置录屏屏幕数据旋转。  | 
| struct [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) \* [OH_AVScreenCapture_CreateContentFilter](#oh_avscreencapture_createcontentfilter) (void) | 创建ContentFilter。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ReleaseContentFilter](#oh_avscreencapture_releasecontentfilter) (struct [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) \*filter) | 释放ContentFilter。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ContentFilter_AddAudioContent](#oh_avscreencapture_contentfilter_addaudiocontent) (struct [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) \*filter, [OH_AVScreenCaptureFilterableAudioContent](#oh_avscreencapturefilterableaudiocontent) content) | 向ContentFilter实例添加可被过滤的声音类型。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ExcludeContent](#oh_avscreencapture_excludecontent) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, struct [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) \*filter) | 向OH_AVScreenCapture实例设置内容过滤器ContentFilter。  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ContentFilter_AddWindowContent](#oh_avscreencapture_contentfilter_addwindowcontent) (struct [OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter) \*filter, int32_t \*windowIDs, int32_t windowCount) | 向ContentFilter实例添加可被过滤的窗口ID列表  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_ResizeCanvas](#oh_avscreencapture_resizecanvas) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, int32_t width, int32_t height) | 调整屏幕的分辨率  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SkipPrivacyMode](#oh_avscreencapture_skipprivacymode) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, int32_t \*windowIDs, int32_t windowCount) | 录屏时豁免隐私窗口  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetMaxVideoFrameRate](#oh_avscreencapture_setmaxvideoframerate) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, int32_t frameRate) | 设置录屏的最大帧率  | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode)[OH_AVScreenCapture_ShowCursor](#oh_avscreencapture_showcursor) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, bool showCursor) | 设置光标显示开关。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) [OH_AVScreenCapture_SetDisplayCallback](#oh_avscreencapture_setdisplaycallback) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AVScreenCapture_OnDisplaySelected](#oh_avscreencapture_ondisplayselected) callback, void \*userData) | 设置获取录屏屏幕Id的回调。 | 


## 类型定义说明


### OH_AudioBuffer

```
typedef struct OH_AudioBuffer OH_AudioBuffer
```
**描述**
定义了音频数据的大小，类型，时间戳等配置信息。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_AudioCaptureInfo

```
typedef struct OH_AudioCaptureInfo OH_AudioCaptureInfo
```
**描述**
音频采样信息。

当audioSampleRate和audioChannels同时为0时，忽略该类型音频相关参数，不录制该类型音频数据。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_AudioCaptureSourceType

```
typedef enum OH_AudioCaptureSourceType OH_AudioCaptureSourceType
```
**描述**
枚举，表示屏幕录制时的音频源类型。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_AudioCodecFormat

```
typedef enum OH_AudioCodecFormat OH_AudioCodecFormat
```
**描述**
枚举，表示音频编码格式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_AudioEncInfo

```
typedef struct OH_AudioEncInfo OH_AudioEncInfo
```
**描述**
音频编码信息。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_AudioInfo

```
typedef struct OH_AudioInfo OH_AudioInfo
```
**描述**
音频信息。

同时采集音频麦克风和音频内录数据时，两路音频的audioSampleRate和audioChannels采样参数需要相同。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_AVSCREEN_CAPTURE_ErrCode

```
typedef enum OH_AVSCREEN_CAPTURE_ErrCode OH_AVSCREEN_CAPTURE_ErrCode
```
**描述**
屏幕录制过程中产生的不同结果码。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_AVScreenCapture

```
typedef struct OH_AVScreenCaptureOH_AVScreenCapture
```
**描述**
通过OH_AVScreenCapture可以获取视频与音频的原始码流。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_AVScreenCapture_ContentFilter

```
typedef struct OH_AVScreenCapture_ContentFilterOH_AVScreenCapture_ContentFilter
```
**描述**
通过OH_AVScreenCapture_ContentFilter过滤音视频内容。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


### OH_AVScreenCapture_OnBufferAvailable

```
typedef void(* OH_AVScreenCapture_OnBufferAvailable) (OH_AVScreenCapture *capture, OH_AVBuffer *buffer, OH_AVScreenCaptureBufferType bufferType, int64_t timestamp, void *userData)
```
**描述**
当OH_AVScreenCapture实例操作期间音频或视频缓存区可用时，将调用该函数指针。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。  | 
| buffer | 指向OH_AVBuffer缓存区实例的指针，该回调方法执行结束返回后，数据缓存区不再有效。  | 
| bufferType | 可用缓冲区的数据类型。  | 
| timestamp | 时间戳, 单位纳秒。  | 
| userData | 指向应用设置该回调处理方法时提供的自定义数据的指针。 | 


### OH_AVScreenCapture_OnDisplaySelected

```
typedef void (*OH_AVScreenCapture_OnDisplaySelected)(OH_AVScreenCapture *capture, uint64_t displayId, void *userData)
```

**描述**

当录屏事件开始时，将调用函数指针。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 
| displayId | 录屏屏幕的Id。 | 
| userData | 指向应用设置该回调处理方法时提供的自定义数据的指针。 | 


### OH_AVScreenCapture_OnError

```
typedef void(* OH_AVScreenCapture_OnError) (OH_AVScreenCapture *capture, int32_t errorCode, void *userData)
```
**描述**
当OH_AVScreenCapture实例操作期间发生错误时，将调用函数指针。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。  | 
| errorCode | 指定错误码。  | 
| userData | 指向应用设置该回调处理方法时提供的自定义数据的指针。 | 


### OH_AVScreenCapture_OnStateChange

```
typedef void(* OH_AVScreenCapture_OnStateChange) (struct OH_AVScreenCapture *capture, OH_AVScreenCaptureStateCode stateCode, void *userData)
```
**描述**
当OH_AVScreenCapture实例操作期间发生状态变更时，将调用函数指针。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。  | 
| stateCode | 指定状态码。  | 
| userData | 指向应用设置该回调处理方法时提供的自定义数据的指针。 | 


### OH_AVScreenCaptureBufferType

```
typedef enum OH_AVScreenCaptureBufferTypeOH_AVScreenCaptureBufferType
```
**描述**
枚举，表示buffer类型。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


### OH_AVScreenCaptureCallback

```
typedef struct OH_AVScreenCaptureCallback OH_AVScreenCaptureCallback
```
**描述**
OH_AVScreenCapture中所有异步回调函数指针的集合。将该结构体的实例注册到OH_AVScreenCapture实例中， 并处理回调上报的信息，以保证OH_AVScreenCapture的正常运行。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**废弃版本：** 12

**替代接口：**

[OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror) [OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| onError | 监控录屏调用操作错误，请参见[OH_AVScreenCaptureOnError](#oh_avscreencaptureonerror)。 | 
| onAudioBufferAvailable | 监控音频码流是否有数据产生，请参见[OH_AVScreenCaptureOnAudioBufferAvailable](#oh_avscreencaptureonaudiobufferavailable)。 | 
| onVideoBufferAvailable | 监控视频码流是否有数据产生，请参见[OH_AVScreenCaptureOnVideoBufferAvailable](#oh_avscreencaptureonvideobufferavailable)。 | 


### OH_AVScreenCaptureConfig

```
typedef struct OH_AVScreenCaptureConfig OH_AVScreenCaptureConfig
```
**描述**
录屏配置信息

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_AVScreenCaptureFilterableAudioContent

```
typedef enum OH_AVScreenCaptureFilterableAudioContent OH_AVScreenCaptureFilterableAudioContent
```
**描述**
枚举，表示可过滤的音频类型。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


### OH_AVScreenCaptureOnAudioBufferAvailable

```
typedef void(* OH_AVScreenCaptureOnAudioBufferAvailable) (OH_AVScreenCapture *capture, bool isReady, OH_AudioCaptureSourceType type)
```
**描述**
当OH_AVScreenCapture操作期间音频缓冲区可用时，将调用函数指针。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**废弃版本：** 12

**替代接口：**[OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。  | 
| isReady | 音频缓冲区是否可用。  | 
| type | 音频源类型。 | 


### OH_AVScreenCaptureOnError

```
typedef void(* OH_AVScreenCaptureOnError) (OH_AVScreenCapture *capture, int32_t errorCode)
```
**描述**
当OH_AVScreenCapture实例运行出错时，将调用函数指针。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**废弃版本：** 12

**替代接口：**[OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。  | 
| errorCode | 指定错误码。 | 


### OH_AVScreenCaptureOnVideoBufferAvailable

```
typedef void(* OH_AVScreenCaptureOnVideoBufferAvailable) (OH_AVScreenCapture *capture, bool isReady)
```
**描述**
当OH_AVScreenCapture操作期间视频缓冲区可用时，将调用函数指针。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**废弃版本：** 12

**替代接口：**[OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。  | 
| isReady | 视频缓冲区是否可用。 | 


### OH_AVScreenCaptureStateCode

```
typedef enum OH_AVScreenCaptureStateCode OH_AVScreenCaptureStateCode
```
**描述**
枚举，表示状态码。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


### OH_CaptureMode

```
typedef enum OH_CaptureMode OH_CaptureMode
```
**描述**
枚举，表示屏幕录制的不同模式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_ContainerFormatType

```
typedef enum OH_ContainerFormatType OH_ContainerFormatType
```
**描述**
枚举，表示屏幕录制生成的文件类型。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_DataType

```
typedef enum OH_DataType OH_DataType
```
**描述**
枚举，表示屏幕录制流的数据格式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_NativeBuffer

```
typedef struct OH_NativeBuffer OH_NativeBuffer
```
**描述**
提供录屏的视频原始码流类。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_RecorderInfo

```
typedef struct OH_RecorderInfo OH_RecorderInfo
```
**描述**
录制文件信息。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_Rect

```
typedef struct OH_Rect OH_Rect
```
**描述**
定义录屏界面的宽高以及画面信息。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_VideoCaptureInfo

```
typedef struct OH_VideoCaptureInfo OH_VideoCaptureInfo
```
**描述**
视频录制信息。

当videoFrameWidth和videoFrameHeight同时为0时，忽略视频相关参数不录制屏幕数据。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_VideoCodecFormat

```
typedef enum OH_VideoCodecFormat OH_VideoCodecFormat
```
**描述**
枚举，表示视频编码格式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_VideoEncInfo

```
typedef struct OH_VideoEncInfo OH_VideoEncInfo
```
**描述**
视频编码参数。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_VideoInfo

```
typedef struct OH_VideoInfo OH_VideoInfo
```
**描述**
视频信息。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


### OH_VideoSourceType

```
typedef enum OH_VideoSourceType OH_VideoSourceType
```
**描述**
枚举，表示视频源格式。当前仅支持RGBA格式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


## 枚举类型说明


### OH_AudioCaptureSourceType

```
enum OH_AudioCaptureSourceType
```
**描述**
枚举，表示屏幕录制时的音频源类型。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_SOURCE_INVALID  | 无效音频源。   | 
| OH_SOURCE_DEFAULT  | 默认音频源，默认为MIC。   | 
| OH_MIC  | 麦克风录制的外部音频流。   | 
| OH_ALL_PLAYBACK  | 系统播放的所有内部音频流。   | 
| OH_APP_PLAYBACK  | 指定应用播放的内部音频流。   | 


### OH_AudioCodecFormat

```
enum OH_AudioCodecFormat
```
**描述**
枚举，表示音频编码格式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_AUDIO_DEFAULT  | 默认音频编码，默认为AAC_LC。   | 
| OH_AAC_LC  | AAC_LC音频编码。   | 
| OH_AUDIO_CODEC_FORMAT_BUTT  | 无效格式。   | 


### OH_AVSCREEN_CAPTURE_ErrCode

```
enum OH_AVSCREEN_CAPTURE_ErrCode
```

**描述**

屏幕录制过程中产生的不同结果码。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| AV_SCREEN_CAPTURE_ERR_BASE | 接口调用错误返回的基础值。 | 
| AV_SCREEN_CAPTURE_ERR_OK | 操作成功。 | 
| AV_SCREEN_CAPTURE_ERR_NO_MEMORY | 内存不足。 | 
| AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT | 不允许操作。 | 
| AV_SCREEN_CAPTURE_ERR_INVALID_VAL | 无效参数。 | 
| AV_SCREEN_CAPTURE_ERR_IO | 输入输出流异常。 | 
| AV_SCREEN_CAPTURE_ERR_TIMEOUT | 网络超时。 | 
| AV_SCREEN_CAPTURE_ERR_UNKNOWN | 未知错误。 | 
| AV_SCREEN_CAPTURE_ERR_SERVICE_DIED | 媒体服务已终止。 | 
| AV_SCREEN_CAPTURE_ERR_INVALID_STATE | 当前状态不支持此操作。 | 
| AV_SCREEN_CAPTURE_ERR_UNSUPPORT | 不支持的接口。 | 
| AV_SCREEN_CAPTURE_ERR_EXTEND_START | 预期之外的错误。 | 


### OH_AVScreenCaptureBufferType

```
enum OH_AVScreenCaptureBufferType
```
**描述**
枚举，表示buffer类型。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_SCREEN_CAPTURE_BUFFERTYPE_VIDEO  | 视频数据。   | 
| OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_INNER  | 内录音频数据。   | 
| OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_MIC  | 麦克风音频数据。   | 


### OH_AVScreenCaptureFilterableAudioContent

```
enum OH_AVScreenCaptureFilterableAudioContent
```
**描述**
枚举，表示可过滤的音频类型。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_SCREEN_CAPTURE_NOTIFICATION_AUDIO  | 通知音。   | 
| OH_SCREEN_CAPTURE_CURRENT_APP_AUDIO  | 应用自身声音。   | 


### OH_AVScreenCaptureStateCode

```
enum OH_AVScreenCaptureStateCode
```
**描述**
枚举，表示状态码。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_SCREEN_CAPTURE_STATE_STARTED  | 已开始录屏。   | 
| OH_SCREEN_CAPTURE_STATE_CANCELED  | 已取消录屏。   | 
| OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER  | 已停止录屏。   | 
| OH_SCREEN_CAPTURE_STATE_INTERRUPTED_BY_OTHER  | 录屏被其他录屏中断。   | 
| OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL  | 录屏被通话中断。   | 
| OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE  | 麦克风不可用。   | 
| OH_SCREEN_CAPTURE_STATE_MIC_MUTED_BY_USER  | 麦克风被静音。   | 
| OH_SCREEN_CAPTURE_STATE_MIC_UNMUTED_BY_USER  | 麦克风被取消静音。    | 
| OH_SCREEN_CAPTURE_STATE_ENTER_PRIVATE_SCENE  | 进入隐私弹窗。    | 
| OH_SCREEN_CAPTURE_STATE_EXIT_PRIVATE_SCENE  | 隐私弹窗退出。    | 
| OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES   | 系统用户切换，录屏中断。 | 


### OH_CaptureMode

```
enum OH_CaptureMode
```
**描述**
枚举，表示屏幕录制的不同模式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_CAPTURE_HOME_SCREEN  | 录制主屏幕。   | 
| OH_CAPTURE_SPECIFIED_SCREEN  | 录制指定屏幕。   | 
| OH_CAPTURE_SPECIFIED_WINDOW  | 录制指定窗口。   | 
| OH_CAPTURE_INVAILD  | 无效模式。   | 


### OH_ContainerFormatType

```
enum OH_ContainerFormatType
```
**描述**
枚举，表示屏幕录制生成的文件类型。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| CFT_MPEG_4A  | 音频格式 m4a。   | 
| CFT_MPEG_4  | 视频格式 mp4。   | 


### OH_DataType

```
enum OH_DataType
```
**描述**
枚举，表示屏幕录制流的数据格式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_ORIGINAL_STREAM  | 原始流格式，如YUV/RGBA/PCM等。   | 
| OH_ENCODED_STREAM  | 编码格式，如H264/AAC等。 当前版本暂不支持。   | 
| OH_CAPTURE_FILE  | 保存文件格式，支持mp4。   | 
| OH_INVAILD  | 无效格式。   | 


### OH_VideoCodecFormat

```
enum OH_VideoCodecFormat
```
**描述**
枚举，表示视频编码格式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_VIDEO_DEFAULT | 默认视频编码，默认为H.264。 | 
| OH_H264 | H.264。 | 
| OH_H265 | H.265/HEVC。 | 
| OH_MPEG4 | MPEG4。 | 
| OH_VP8 | VP8。 | 
| OH_VP9 | VP9。 | 
| OH_VIDEO_CODEC_FORMAT_BUTT | 无效格式。 | 


### OH_VideoSourceType

```
enum OH_VideoSourceType
```
**描述**
枚举，表示视频源格式。当前仅支持RGBA格式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_VIDEO_SOURCE_SURFACE_YUV  | YUV格式。当前版本暂不支持。   | 
| OH_VIDEO_SOURCE_SURFACE_ES  | raw格式。当前版本暂不支持。  | 
| OH_VIDEO_SOURCE_SURFACE_RGBA  | RGBA格式。   | 
| OH_VIDEO_SOURCE_BUTT  | 无效格式。   | 


## 函数说明


### OH_AVScreenCapture_AcquireAudioBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_AcquireAudioBuffer (struct OH_AVScreenCapture * capture, OH_AudioBuffer ** audiobuffer, OH_AudioCaptureSourceType type )
```
**描述**
获取音频buffer，应用在调用时，需要对audiobuffer分配对应结构体大小的内存，否则会影响音频buffer的获取。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**废弃版本：** 12

**替代接口：**[OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 
| audiobuffer | 保存音频buffer的结构体，通过该结构体获取到音频buffer以及buffer的时间戳等信息。 | 
| type | 音频buffer的类型，区分是麦克风录制的外部流还是系统内部播放音频的内录流，详情请参阅[OH_AudioCaptureSourceType](#oh_audiocapturesourcetype)。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针或输入参数audiobuffer为空指针。

AV_SCREEN_CAPTURE_ERR_NO_MEMORY：内存不足，audiobuffer分配失败。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置隐私权限启用失败或获取音频buffer失败。



### OH_AVScreenCapture_AcquireVideoBuffer()

```
OH_NativeBuffer* OH_AVScreenCapture_AcquireVideoBuffer (struct OH_AVScreenCapture * capture, int32_t * fence, int64_t * timestamp, struct OH_Rect * region )
```
**描述**
获取视频buffer，应用在调用时，通过此接口来获取到视频的buffer以及时间戳等信息。 buffer使用完成后，调用[OH_AVScreenCapture_ReleaseVideoBuffer](#oh_avscreencapture_releasevideobuffer)接口进行视频buffer的释放。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**废弃版本：** 12

**替代接口：**[OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。  | 
| fence | 用于同步的显示相关参数信息。  | 
| timestamp | 视频帧的时间戳。  | 
| region | 视频显示相关的坐标信息。  | 

**返回：**

执行成功返回OH_NativeBuffer对象，通过OH_NativeBuffer对象相关接口可以获取到视频buffer和分辨率等信息参数。


### OH_AVScreenCapture_ContentFilter_AddAudioContent()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ContentFilter_AddAudioContent (struct OH_AVScreenCapture_ContentFilter * filter, OH_AVScreenCaptureFilterableAudioContent content )
```
**描述**
向ContentFilter实例添加可被过滤的声音类型。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 指向[OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter)实例的指针。 | 
| content | [OH_AVScreenCaptureFilterableAudioContent](#oh_avscreencapturefilterableaudiocontent)实例。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数filter为空指针或输入参数content无效。


### OH_AVScreenCapture_ContentFilter_AddWindowContent()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ContentFilter_AddWindowContent (struct OH_AVScreenCapture_ContentFilter *filter, int32_t *windowIDs, int32_t windowCount)
```
**描述**
向ContentFilter实例添加可被过滤的窗口ID列表。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 指向OH_AVScreenCapture_ContentFilter实例的指针。  | 
| windowIDs | 指向窗口ID的指针。  | 
| windowCount | 窗口ID列表的长度。  | 

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK，否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)。


### OH_AVScreenCapture_Create()

```
struct OH_AVScreenCapture* OH_AVScreenCapture_Create (void )
```
**描述**
实例化对象，创建OH_AVScreenCapture。可以通过调用[OH_AVScreenCapture_Release](#oh_avscreencapture_release)释放实例。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**返回：**

返回一个指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。


### OH_AVScreenCapture_CreateContentFilter()

```
struct OH_AVScreenCapture_ContentFilter* OH_AVScreenCapture_CreateContentFilter (void )
```
**描述**
创建ContentFilter。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**返回：**

执行成功返回[OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter)实例，否则返回空指针。


### OH_AVScreenCapture_ExcludeContent()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ExcludeContent (struct OH_AVScreenCapture * capture, struct OH_AVScreenCapture_ContentFilter * filter )
```
**描述**
向OH_AVScreenCapture实例设置内容过滤器ContentFilter。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 
| filter | 指向[OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter)实例的指针。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针或输入参数filter为空指针。

AV_SCREEN_CAPTURE_ERR_UNSUPPORT：操作不支持，对于流，在启动时应该调用AudioCapturer接口生效；对于capture文件，在启动时应该调用Recorder接口生效。


### OH_AVScreenCapture_Init()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Init (struct OH_AVScreenCapture * capture, OH_AVScreenCaptureConfig config )
```
**描述**
初始化[OH_AVScreenCapture](#oh_avscreencapture)相关参数，包括下发的音频麦克风采样相关参数（可选），音频内录采样相关参数，视频分辨率相关参数。

录屏存文件场景，应用需要保证视频编码参数、视频采样参数、音频编码参数、音频内录采样参数均合法，音频麦克风采样参数合法（可选）。

录屏出码流场景，应用需要保证音频内录采样参数、视频采样参数至少一个合法，音频麦克风采样参数合法（可选）。

由于结构体变量在初始化时不会对成员进行初始化，应用必须根据使用场景正确设置各项参数。建议应用先将
OH_AVScreenCaptureConfig结构体变量的所有内存字节均设置为0，然后再根据录屏场景设置合法参数。

音频采样参数结构体[OH_AudioCaptureInfo](#oh_audiocaptureinfo)，若audioSampleRate和audioChannels同时为0，
则录屏实例OH_AVScreenCapture将忽略该类型的音频参数，且不采集该类型的音频数据。

视频采样参数结构体[OH_AudioCaptureInfo](#oh_audiocaptureinfo)，若videoFrameWidth和videoFrameHeight同时为0，
则录屏实例OH_AVScreenCapture将忽略对应视频参数，且不采集屏幕数据。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 
| config | 录屏初始化相关参数。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，初始化配置失败。


### OH_AVScreenCapture_Release()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Release (struct OH_AVScreenCapture * capture)
```
**描述**
释放创建的OH_AVScreenCapture实例，对应[OH_AVScreenCapture_Create](#oh_avscreencapture_create)。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，OH_AVScreenCapture实例释放失败。

### OH_AVScreenCapture_ReleaseAudioBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseAudioBuffer (struct OH_AVScreenCapture * capture, OH_AudioCaptureSourceType type )
```
**描述**
根据音频类型释放buffer。当某一帧音频buffer使用完成后，调用此接口进行释放对应的音频buffer。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**废弃版本：** 12

**替代接口：**[OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 
| type | 音频buffer的类型，区分麦克风录制的外部流还是系统内部播放音频的内录流。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，不允许用于已设置过DataCallback或释放音频buffer失败。


### OH_AVScreenCapture_ReleaseContentFilter()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseContentFilter (struct OH_AVScreenCapture_ContentFilter * filter)
```
**描述**
释放ContentFilter。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| filter | 指向[OH_AVScreenCapture_ContentFilter](#oh_avscreencapture_contentfilter)实例的指针。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数filter为空指针。


### OH_AVScreenCapture_ReleaseVideoBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseVideoBuffer (struct OH_AVScreenCapture * capture)
```
**描述**
根据视频类型释放buffer。当某一帧视频buffer使用完成后，调用此接口进行释放对应的视频buffer。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**废弃版本：** 12

**替代接口：**[OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，不允许用于已设置过DataCallback或释放视频buffer失败。


### OH_AVScreenCapture_SetCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCallback (struct OH_AVScreenCapture * capture, struct OH_AVScreenCaptureCallback callback )
```
**描述**
设置监听接口，通过设置监听，可以监听到调用过程中的错误信息，以及是否有可用的视频buffer和音频buffer。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**废弃版本：** 12

**替代接口： **[OH_AVScreenCapture_SetErrorCallback](#oh_avscreencapture_seterrorcallback) [OH_AVScreenCapture_SetDataCallback](#oh_avscreencapture_setdatacallback)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 
| callback | [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md)的结构体，保存相关回调函数指针。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针或输入参数callback为空指针。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置监听接口失败。


### OH_AVScreenCapture_SetCanvasRotation()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCanvasRotation (struct OH_AVScreenCapture * capture, bool canvasRotation )
```
**描述**
设置录屏屏幕数据旋转。

调用该方法可以设置录屏屏幕数据是否旋转，当canvasRotation为true时，打开录屏屏幕数据旋转功能，录制的屏幕数据保持正向。

默认为false。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 
| canvasRotation | 指示屏幕数据旋转参数。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置录屏屏幕数据旋转失败。


### OH_AVScreenCapture_SetDataCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetDataCallback (struct OH_AVScreenCapture * capture, OH_AVScreenCapture_OnBufferAvailable callback, void * userData )
```
**描述**
设置数据处理回调方法，在开始录制前调用。

调用该方法设置数据处理回调方法，当OH_AVScreenCapture操作期间有音频或视频数据缓存区可用时，将调用该数据处理回调方法。

应用需要在该数据处理回调方法中根据数据类型完成处理麦克风音频、内录音频、视频数据，当该数据处理回调方法返回后数据缓存区将不再有效。

调用该方法成功后：

1. 当OH_AVScreenCapture操作期间有音视频缓存区可用时，将不再调用通过[OH_AVScreenCapture_SetCallback](#oh_avscreencapture_setcallback)设置的数据回调方法[OH_AVScreenCaptureOnAudioBufferAvailable](#oh_avscreencaptureonaudiobufferavailable)和[OH_AVScreenCaptureOnVideoBufferAvailable](#oh_avscreencaptureonvideobufferavailable)。
2. 不允许应用调用如下4个方法[OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer)、[OH_AVScreenCapture_ReleaseAudioBuffer](#oh_avscreencapture_releaseaudiobuffer)、[OH_AVScreenCapture_AcquireVideoBuffer](#oh_avscreencapture_acquirevideobuffer)和[OH_AVScreenCapture_ReleaseVideoBuffer](#oh_avscreencapture_releasevideobuffer)，直接返回失败。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 
| callback | 指向数据处理回调方法实例的指针[OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)。 | 
| userData | 指向应用提供的自定义数据的指针，在数据处理回调方法被调用时作为入参回传。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针或输入参数callback为空指针。

AV_SCREEN_CAPTURE_ERR_NO_MEMORY：内存不足，内存分配失败。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置DataCallback失败。


### OH_AVScreenCapture_SetDisplayCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetDisplayCallback(struct OH_AVScreenCapture *capture, OH_AVScreenCapture_OnDisplaySelected callback, void *userData)
```

**描述**

设置获取录屏屏幕Id的回调。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | OH_AVScreenCapture实例的指针。 | 
| callback | 指向录屏屏幕Id回调方法实例的指针[OH_AVScreenCapture_OnDisplaySelected](#oh_avscreencapture_ondisplayselected)。 | 
| userData | 指向应用提供的自定义数据的指针，在状态处理回调方法被调用时作为入参回传。 | 

**返回：**

函数结果代码： AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针或输入参数callback为空指针。

AV_SCREEN_CAPTURE_ERR_NO_MEMORY：内存不足，内存分配失败。

AV_SCREEN_CAPTURE_ERR_INVALID_STATE：当前状态不支持此操作，回调必须在start方法前调用。


### OH_AVScreenCapture_SetErrorCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetErrorCallback (struct OH_AVScreenCapture * capture, OH_AVScreenCapture_OnError callback, void * userData )
```
**描述**
设置错误处理回调方法，在开始录制前调用。

调用该方法设置错误处理回调方法，当OH_AVScreenCapture实例发生错误时，该错误处理回调方法将会被调用。

调用该设置方法成功后：当OH_AVScreenCapture实例发生错误时，将不再调用通过[OH_AVScreenCapture_SetCallback](#oh_avscreencapture_setcallback)设置的错误处理回调方法[OH_AVScreenCaptureOnError](#oh_avscreencaptureonerror)。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 
| callback | 指向错误处理回调方法实例的指针[OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror)。 | 
| userData | 指向应用提供的自定义数据的指针，在错误处理回调方法被调用时作为入参回传。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针或输入参数callback为空指针。

AV_SCREEN_CAPTURE_ERR_NO_MEMORY：内存不足，内存分配失败。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置ErrorCallback失败。


### OH_AVScreenCapture_SetMicrophoneEnabled()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMicrophoneEnabled (struct OH_AVScreenCapture * capture, bool isMicrophone )
```
**描述**
设置麦克风开关。当isMicrophone为true时，则打开麦克风，通过调用[OH_AVScreenCapture_StartScreenCapture](#oh_avscreencapture_startscreencapture)和[OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer)可以正常获取到音频的麦克风原始PCM数据；isMicrophone为false时，获取到的音频数据为无声数据。

默认麦克风开关为开启。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 
| isMicrophone | 麦克风开关参数。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置麦克风开关失败。


### OH_AVScreenCapture_SetStateCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetStateCallback (struct OH_AVScreenCapture * capture, OH_AVScreenCapture_OnStateChange callback, void * userData )
```
**描述**
设置状态变更处理回调方法，在开始录制前调用。

调用该方法设置状态变更处理回调方法，当OH_AVScreenCapture实例发生状态变更时，该状态变更处理回调方法将会被调用。

调用该设置方法成功后，在启动录屏时将通过隐私弹窗方式征求用户同意：

1. 如果用户同意则开始启动录屏流程，在启动录屏成功后，通过该状态处理回调方法上报[OH_SCREEN_CAPTURE_STATE_STARTED](#oh_avscreencapturestatecode-1)状态，告知应用启动录屏成功，并在屏幕显示录屏通知。

   如果启动录屏失败，则通过该状态处理回调方法上报失败状态信息（如，若麦克风不可用则上报[OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE](#oh_avscreencapturestatecode-1)状态），或通过错误处理回调方法[OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror)上报错误信息。

2. 如果用户拒绝，则终止启动录屏，通过该状态处理回调方法上报[OH_SCREEN_CAPTURE_STATE_CANCELED](#oh_avscreencapturestatecode-1)状态，告知应用用户拒绝启动录屏，启动录屏失败。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 
| callback | 指向状态处理回调方法实例的指针[OH_AVScreenCapture_OnStateChange](#oh_avscreencapture_onstatechange) | 
| userData | 指向应用提供的自定义数据的指针，在状态处理回调方法被调用时作为入参回传。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针或输入参数callback为空指针。

AV_SCREEN_CAPTURE_ERR_NO_MEMORY：内存不足，内存分配失败。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置StateCallback失败。


### OH_AVScreenCapture_StartScreenCapture()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCapture (struct OH_AVScreenCapture * capture)
```
**描述**
开始录屏，采集原始码流。调用后可以通过回调的监听([OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable))来监听当前是否有码流的产生,通过回调的监听([OH_AVScreenCapture_OnStateChange](#oh_avscreencapture_onstatechange))来监听启动状态。

通过调用获取音频buffer([OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer))和视频buffer([OH_AVScreenCapture_ReleaseVideoBuffer](#oh_avscreencapture_releasevideobuffer))的接口来获取录屏的原始码流。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置隐私权限启用失败或启动录屏失败。


### OH_AVScreenCapture_StartScreenCaptureWithSurface()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCaptureWithSurface (struct OH_AVScreenCapture * capture, OHNativeWindow * window )
```
**描述**
使用Surface模式录屏。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 
| window | 指向[OHNativeWindow](../apis-arkgraphics2d/_native_window.md#ohnativewindow)实例的指针。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针、输入参数window为空指针或window指向的windowSurface为空指针。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置隐私权限启用失败或启动ScreenCaptureWithSurface失败。


### OH_AVScreenCapture_StartScreenRecording()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenRecording (struct OH_AVScreenCapture * capture)
```
**描述**
启动录屏，调用此接口，可将录屏文件保存。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置隐私权限启用失败或启用屏幕录制失败。


### OH_AVScreenCapture_StopScreenCapture()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenCapture (struct OH_AVScreenCapture * capture)
```
**描述**
结束录屏，与[OH_AVScreenCapture_StartScreenCapture](#oh_avscreencapture_startscreencapture)配合使用。调用后针对调用该接口的应用会停止录屏或屏幕共享，释放麦克风。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，结束录屏失败。


### OH_AVScreenCapture_StopScreenRecording()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenRecording (struct OH_AVScreenCapture * capture)
```
**描述**
停止录屏，与[OH_AVScreenCapture_StartScreenRecording](#oh_avscreencapture_startscreenrecording)配合使用。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，停止屏幕录制失败。

### OH_AVScreenCapture_ResizeCanvas()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ResizeCanvas (struct OH_AVScreenCapture * capture, int32_t width, int32_t height)
```
**描述**
调整屏幕的分辨率。

调用该方法可以设置录屏屏幕数据的分辨率，width为屏幕的宽度，height为屏幕的高度。

该接口目前仅支持录屏取码流的场景，不支持录屏存文件的场景。并且调用该接口的调用者以及视频数据的消费者需要确保自身能够支持收到的视频数据分辨率发生变化。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 
| width | 录屏屏幕的宽度。 | 
| height | 录屏屏幕的高度。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作。


### OH_AVScreenCapture_ShowCursor()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ShowCursor(struct OH_AVScreenCapture *capture, bool showCursor)
```

**描述**

设置光标显示开关。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 
| showCursor | 光标显示参数。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作，设置光标失败。


### OH_AVScreenCapture_SkipPrivacyMode()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SkipPrivacyMode (struct OH_AVScreenCapture * capture, int32_t *windowIDs, int32_t windowCount)
```
**描述**
录屏时豁免隐私窗口。

调用该方法可以豁免隐私窗口，windowIDs为需要豁免的隐私窗口ID指针，windowCount 为隐私窗口ID列表的长度，目前豁免需要传入所有隐私子窗口和主窗口ID。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 
| windowIDs | 向隐私窗口ID的指针。 | 
| windowCount | 隐私窗口ID列表的长度。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：不允许操作。


### OH_AVScreenCapture_SetMaxVideoFrameRate()
```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMaxVideoFrameRate (struct OH_AVScreenCapture * capture, int32_t frameRate)
```
**描述**
设置录屏的最大帧率。

调用该方法可以设置录屏时的最大帧率，frameRate为想要设置的最大帧率。

该接口设置最大帧率时，实际设置的帧率受限设备的能力，由底层的系统能力决定。

调用该接口设置录屏最大帧率时，实际帧率将受限于设备能力。目前接口入参的最大值不设限制，但当前支持的最高帧率为60FPS，当入参设置超过60FPS，将以60FPS处理。不超过上限时，则按照实际入参值处理。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 14

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向[OH_AVScreenCapture](#oh_avscreencapture)实例的指针。 | 
| frameRate | 设置录屏的最大帧率。 | 

**返回：**

函数结果代码[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode-1)：

AV_SCREEN_CAPTURE_ERR_OK：执行成功。

AV_SCREEN_CAPTURE_ERR_INVALID_VAL：输入参数capture为空指针，或者输入参数frameRate不支持。

AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT：操作受限，建议重试。