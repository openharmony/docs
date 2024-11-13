# native_avscreen_capture_base.h


## 概述

声明用于运行屏幕录制通用的结构体、字符常量、枚举。

**库：** libnative_avscreen_capture.so

**引用文件：** <multimedia/player_framework/native_avscreen_capture_base.h>

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**相关模块：**[AVScreenCapture](_a_v_screen_capture.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) | 音频采样信息。 | 
| struct  [OH_AudioEncInfo](_o_h___audio_enc_info.md) | 音频编码信息。 | 
| struct  [OH_AudioInfo](_o_h___audio_info.md) | 音频信息。 | 
| struct  [OH_VideoCaptureInfo](_o_h___video_capture_info.md) | 视频录制信息。 | 
| struct  [OH_VideoEncInfo](_o_h___video_enc_info.md) | 视频编码信息。 | 
| struct  [OH_VideoInfo](_o_h___video_info.md) | 视频信息。 | 
| struct  [OH_RecorderInfo](_o_h___recorder_info.md) | 录制文件信息。 | 
| struct  [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) | 屏幕录制配置参数。 | 
| struct  [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) | OH_AVScreenCapture中所有异步回调函数指针的集合。 | 
| struct  [OH_Rect](_o_h___rect.md) | 定义录屏界面的宽高以及画面信息。 | 
| struct  [OH_AudioBuffer](_o_h___audio_buffer.md) | 定义了音频数据的大小，类型，时间戳等配置信息。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_NativeBuffer](_a_v_screen_capture.md#oh_nativebuffer) [OH_NativeBuffer](_a_v_screen_capture.md#oh_nativebuffer) | 提供录屏的视频原始码流类。 | 
| typedef struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) | 通过OH_AVScreenCapture可以获取视频与音频的原始码流。 | 
| typedef struct [OH_AVScreenCapture_ContentFilter](_a_v_screen_capture.md#oh_avscreencapture_contentfilter) [OH_AVScreenCapture_ContentFilter](_a_v_screen_capture.md#oh_avscreencapture_contentfilter) | 通过OH_AVScreenCapture_ContentFilter过滤音视频内容。 | 
| typedef enum [OH_CaptureMode](_a_v_screen_capture.md#oh_capturemode-1) [OH_CaptureMode](_a_v_screen_capture.md#oh_capturemode) | 枚举，表示屏幕录制的不同模式。 | 
| typedef enum [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype-1) [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) | 枚举，表示屏幕录制时的音频源类型。 | 
| typedef enum [OH_AudioCodecFormat](_a_v_screen_capture.md#oh_audiocodecformat-1) [OH_AudioCodecFormat](_a_v_screen_capture.md#oh_audiocodecformat) | 枚举，表示音频编码格式。 | 
| typedef enum [OH_VideoCodecFormat](_a_v_screen_capture.md#oh_videocodecformat-1) [OH_VideoCodecFormat](_a_v_screen_capture.md#oh_videocodecformat) | 枚举，表示视频编码格式。 | 
| typedef enum [OH_DataType](_a_v_screen_capture.md#oh_datatype-1) [OH_DataType](_a_v_screen_capture.md#oh_datatype) | 枚举，表示屏幕录制流的数据格式。 | 
| typedef enum [OH_VideoSourceType](_a_v_screen_capture.md#oh_videosourcetype-1) [OH_VideoSourceType](_a_v_screen_capture.md#oh_videosourcetype) | 枚举，表示视频源格式。 | 
| typedef enum [OH_ContainerFormatType](_a_v_screen_capture.md#oh_containerformattype-1) [OH_ContainerFormatType](_a_v_screen_capture.md#oh_containerformattype) | 枚举，表示屏幕录制生成的文件类型。 | 
| typedef struct [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) [OH_AudioCaptureInfo](_a_v_screen_capture.md#oh_audiocaptureinfo) | 音频采样信息。 | 
| typedef struct [OH_AudioEncInfo](_o_h___audio_enc_info.md) [OH_AudioEncInfo](_a_v_screen_capture.md#oh_audioencinfo) | 音频编码信息。 | 
| typedef struct [OH_AudioInfo](_o_h___audio_info.md) [OH_AudioInfo](_a_v_screen_capture.md#oh_audioinfo) | 音频信息。 | 
| typedef struct [OH_VideoCaptureInfo](_o_h___video_capture_info.md) [OH_VideoCaptureInfo](_a_v_screen_capture.md#oh_videocaptureinfo) | 视频录制信息。 | 
| typedef struct [OH_VideoEncInfo](_o_h___video_enc_info.md) [OH_VideoEncInfo](_a_v_screen_capture.md#oh_videoencinfo) | 视频编码信息。 | 
| typedef struct [OH_VideoInfo](_o_h___video_info.md) [OH_VideoInfo](_a_v_screen_capture.md#oh_videoinfo) | 视频信息。 | 
| typedef struct [OH_RecorderInfo](_o_h___recorder_info.md) [OH_RecorderInfo](_a_v_screen_capture.md#oh_recorderinfo) | 录制文件信息。 | 
| typedef struct [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) [OH_AVScreenCaptureConfig](_a_v_screen_capture.md#oh_avscreencaptureconfig) | 屏幕录制配置参数。 | 
| typedef void(\* [OH_AVScreenCaptureOnError](_a_v_screen_capture.md#oh_avscreencaptureonerror)) ([OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, int32_t errorCode) | 当OH_AVScreenCapture实例运行出错时，将调用函数指针。 | 
| typedef void(\* [OH_AVScreenCaptureOnAudioBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonaudiobufferavailable)) ([OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, bool isReady, [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) type) | 当OH_AVScreenCapture操作期间音频缓冲区可用时，将调用函数指针。 | 
| typedef void(\* [OH_AVScreenCaptureOnVideoBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonvideobufferavailable)) ([OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, bool isReady) | 当OH_AVScreenCapture操作期间视频缓冲区可用时，将调用函数指针。 | 
| typedef struct [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) [OH_AVScreenCaptureCallback](_a_v_screen_capture.md#oh_avscreencapturecallback) | OH_AVScreenCapture中所有异步回调函数指针的集合。 | 
| typedef struct [OH_Rect](_o_h___rect.md) [OH_Rect](_a_v_screen_capture.md#oh_rect) | 定义录屏界面的宽高以及画面信息。 | 
| typedef struct [OH_AudioBuffer](_o_h___audio_buffer.md) [OH_AudioBuffer](_a_v_screen_capture.md#oh_audiobuffer) | 定义了音频数据的大小，类型，时间戳等配置信息。 | 
| typedef enum [OH_AVScreenCaptureStateCode](_a_v_screen_capture.md#oh_avscreencapturestatecode-1) [OH_AVScreenCaptureStateCode](_a_v_screen_capture.md#oh_avscreencapturestatecode) | 枚举，表示状态码。 | 
| typedef enum [OH_AVScreenCaptureBufferType](_a_v_screen_capture.md#oh_avscreencapturebuffertype-1) [OH_AVScreenCaptureBufferType](_a_v_screen_capture.md#oh_avscreencapturebuffertype) | 枚举，表示buffer类型。 | 
| typedef enum [OH_AVScreenCaptureFilterableAudioContent](_a_v_screen_capture.md#oh_avscreencapturefilterableaudiocontent-1) [OH_AVScreenCaptureFilterableAudioContent](_a_v_screen_capture.md#oh_avscreencapturefilterableaudiocontent) | 枚举，表示可过滤的音频类型。 | 
| typedef void(\* [OH_AVScreenCapture_OnStateChange](_a_v_screen_capture.md#oh_avscreencapture_onstatechange)) (struct [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, [OH_AVScreenCaptureStateCode](_a_v_screen_capture.md#oh_avscreencapturestatecode) stateCode, void \*userData) | 当OH_AVScreenCapture实例操作期间发生状态变更时，将调用函数指针。 | 
| typedef void(\* [OH_AVScreenCapture_OnError](_a_v_screen_capture.md#oh_avscreencapture_onerror)) ([OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, int32_t errorCode, void \*userData) | 当OH_AVScreenCapture实例操作期间发生错误时，将调用函数指针。 | 
| typedef void(\* [OH_AVScreenCapture_OnBufferAvailable](_a_v_screen_capture.md#oh_avscreencapture_onbufferavailable)) ([OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, OH_AVBuffer \*buffer, [OH_AVScreenCaptureBufferType](_a_v_screen_capture.md#oh_avscreencapturebuffertype) bufferType, int64_t timestamp, void \*userData) | 当OH_AVScreenCapture实例操作期间音频或视频缓存区可用时，将调用该函数指针。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_CaptureMode](_a_v_screen_capture.md#oh_capturemode-1) {<br/>OH_CAPTURE_HOME_SCREEN = 0,<br/>OH_CAPTURE_SPECIFIED_SCREEN = 1,<br/>OH_CAPTURE_SPECIFIED_WINDOW = 2,<br/>OH_CAPTURE_INVAILD = -1<br/>} | 枚举，表示屏幕录制的不同模式。 | 
| [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype-1) {<br/>OH_SOURCE_INVALID = -1,<br/>OH_SOURCE_DEFAULT = 0,<br/>OH_MIC = 1,<br/>OH_ALL_PLAYBACK = 2,<br/>OH_APP_PLAYBACK = 3<br/>} | 枚举，表示屏幕录制时的音频源类型。 | 
| [OH_AudioCodecFormat](_a_v_screen_capture.md#oh_audiocodecformat-1) {<br/>OH_AUDIO_DEFAULT = 0,<br/>OH_AAC_LC = 3,<br/>OH_AUDIO_CODEC_FORMAT_BUTT<br/>} | 枚举，表示音频编码格式。 | 
| [OH_VideoCodecFormat](_a_v_screen_capture.md#oh_videocodecformat-1) {<br/>OH_VIDEO_DEFAULT = 0,<br/>OH_H264 = 2,<br/>OH_H265 = 4,<br/>OH_MPEG4 = 6,<br/>OH_VP8 = 8,<br/>OH_VP9 = 10,<br/>OH_VIDEO_CODEC_FORMAT_BUTT<br/>} | 枚举，表示视频编码格式。 | 
| [OH_DataType](_a_v_screen_capture.md#oh_datatype-1) {<br/>OH_ORIGINAL_STREAM = 0,<br/>OH_ENCODED_STREAM = 1,<br/>OH_CAPTURE_FILE = 2,<br/>OH_INVAILD = -1<br/>} | 枚举，表示屏幕录制流的数据格式。 | 
| [OH_VideoSourceType](_a_v_screen_capture.md#oh_videosourcetype-1) {<br/>OH_VIDEO_SOURCE_SURFACE_YUV = 0,<br/>OH_VIDEO_SOURCE_SURFACE_ES,<br/>OH_VIDEO_SOURCE_SURFACE_RGBA,<br/>OH_VIDEO_SOURCE_BUTT<br/>} | 枚举，表示视频源格式。 | 
| [OH_ContainerFormatType](_a_v_screen_capture.md#oh_containerformattype-1) {<br/>CFT_MPEG_4A = 0,<br/>CFT_MPEG_4 = 1<br/>} | 枚举，表示屏幕录制生成的文件类型。 | 
| [OH_AVScreenCaptureStateCode](_a_v_screen_capture.md#oh_avscreencapturestatecode-1) {<br/>OH_SCREEN_CAPTURE_STATE_STARTED = 0,<br/>OH_SCREEN_CAPTURE_STATE_CANCELED = 1,<br/>OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER = 2,<br/>OH_SCREEN_CAPTURE_STATE_INTERRUPTED_BY_OTHER = 3,<br/>OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL = 4,<br/>OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE = 5,<br/>OH_SCREEN_CAPTURE_STATE_MIC_MUTED_BY_USER = 6,<br/>OH_SCREEN_CAPTURE_STATE_MIC_UNMUTED_BY_USER = 7,<br/>OH_SCREEN_CAPTURE_STATE_ENTER_PRIVATE_SCENE = 8,<br/>OH_SCREEN_CAPTURE_STATE_EXIT_PRIVATE_SCENE = 9<br/>,<br/>OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES = 10<br/>} | 枚举，表示状态码。 | 
| [OH_AVScreenCaptureBufferType](_a_v_screen_capture.md#oh_avscreencapturebuffertype-1) {<br/>OH_SCREEN_CAPTURE_BUFFERTYPE_VIDEO = 0,<br/>OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_INNER = 1,<br/>OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_MIC = 2<br/>} | 枚举，表示buffer类型。 | 
| [OH_AVScreenCaptureFilterableAudioContent](_a_v_screen_capture.md#oh_avscreencapturefilterableaudiocontent-1) {<br/>OH_SCREEN_CAPTURE_NOTIFICATION_AUDIO = 0, <br/>OH_SCREEN_CAPTURE_CURRENT_APP_AUDIO = 1 <br/>} | 枚举，表示可过滤的音频类型。  | 
