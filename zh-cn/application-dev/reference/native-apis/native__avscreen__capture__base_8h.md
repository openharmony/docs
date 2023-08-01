# native_avscreen_capture_base.h


## 概述

声明用于运行屏幕录制通用的结构体、字符常量、枚举。

**起始版本：**

10

**相关模块:**

[AVScreenCapture](_a_v_screen_capture.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) | 音频录制信息。 | 
| [OH_AudioEncInfo](_o_h___audio_enc_info.md) | 音频编码信息。<br>**说明：** 预留接口，将在后续版本提供。 | 
| [OH_AudioInfo](_o_h___audio_info.md) | 音频录制参数。 | 
| [OH_VideoCaptureInfo](_o_h___video_capture_info.md) | 视频采集信息。 | 
| [OH_VideoEncInfo](_o_h___video_enc_info.md) | 视频编码信息。<br>**说明：** 预留接口，将在后续版本提供。 | 
| [OH_VideoInfo](_o_h___video_info.md) | 视频录制参数。 | 
| [OH_RecorderInfo](_o_h___recorder_info.md) | 录制文件信息。 | 
| [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) | 屏幕录制配置参数。 | 
| [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) | OH_AVScreenCapture中所有异步回调函数指针的集合。 | 
| [OH_Rect](_o_h___rect.md) | 定义录屏界面的宽高以及画面信息。 | 
| [OH_AudioBuffer](_o_h___audio_buffer.md) | 定义了音频数据的大小，类型，时间戳等配置信息。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NativeBuffer](_a_v_screen_capture.md#oh_nativebuffer) | 提供录屏的视频原始码流类。 | 
| [OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) | 通过OH_AVScreenCapture可以获取视频与音频的原始码流。 | 
| [OH_CaptureMode](_a_v_screen_capture.md#oh_capturemode) | 枚举，表示屏幕录制的不同模式。 | 
| [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) | 枚举，表示屏幕录制时的音频源类型。 | 
| [OH_AudioCodecFormat](_a_v_screen_capture.md#oh_audiocodecformat) | 枚举，表示音频编码格式。 | 
| [OH_VideoCodecFormat](_a_v_screen_capture.md#oh_videocodecformat) | 枚举，表示视频编码格式。 | 
| [OH_DataType](_a_v_screen_capture.md#oh_datatype) | 枚举，表示屏幕录制流的数据格式。 | 
| [OH_VideoSourceType](_a_v_screen_capture.md#oh_videosourcetype) | 枚举，表示视频源格式。 | 
| [OH_ContainerFormatType](_a_v_screen_capture.md#oh_containerformattype) | 枚举，表示屏幕录制生成的文件类型。<br>**说明：** 预留接口，将在后续版本提供。 | 
| [OH_AudioCaptureInfo](_a_v_screen_capture.md#oh_audiocaptureinfo) | 音频录制信息。 | 
| [OH_AudioEncInfo](_a_v_screen_capture.md#oh_audioencinfo) | 音频编码信息。<br>**说明：** 预留接口，将在后续版本提供。 | 
| [OH_AudioInfo](_a_v_screen_capture.md#oh_audioinfo) | 音频录制参数。 | 
| [OH_VideoCaptureInfo](_a_v_screen_capture.md#oh_videocaptureinfo) | 视频采集信息。 | 
| [OH_VideoEncInfo](_a_v_screen_capture.md#oh_videoencinfo) | 视频编码信息。 <br>**说明：** 预留接口，将在后续版本提供。| 
| [OH_VideoInfo](_a_v_screen_capture.md#oh_videoinfo) | 视频录制参数。 | 
| [OH_RecorderInfo](_a_v_screen_capture.md#oh_recorderinfo) | 录制文件信息。 | 
| [OH_AVScreenCaptureConfig](_a_v_screen_capture.md#oh_avscreencaptureconfig) | 屏幕录制配置参数。 | 
| (\*[OH_AVScreenCaptureOnError](_a_v_screen_capture.md#oh_avscreencaptureonerror)) ([OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, int32_t errorCode) | 当OH_AVScreenCapture实例运行出错时，将调用函数指针。 | 
| (\*[OH_AVScreenCaptureOnAudioBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonaudiobufferavailable)) ([OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, bool isReady, [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) type) | 当OH_AVScreenCapture操作期间音频缓冲区可用时，将调用函数指针。 | 
| (\*[OH_AVScreenCaptureOnVideoBufferAvailable](_a_v_screen_capture.md#oh_avscreencaptureonvideobufferavailable)) ([OH_AVScreenCapture](_a_v_screen_capture.md#oh_avscreencapture) \*capture, bool isReady) | 当OH_AVScreenCapture操作期间视频缓冲区可用时，将调用函数指针。 | 
| [OH_AVScreenCaptureCallback](_a_v_screen_capture.md#oh_avscreencapturecallback) | OH_AVScreenCapture中所有异步回调函数指针的集合。 | 
| [OH_Rect](_a_v_screen_capture.md#oh_rect) | 定义录屏界面的宽高以及画面信息。 | 
| [OH_AudioBuffer](_a_v_screen_capture.md#oh_audiobuffer) | 定义了音频数据的大小，类型，时间戳等配置信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_CaptureMode](_a_v_screen_capture.md#oh_capturemode) { [OH_CAPTURE_HOME_SCREEN](_a_v_screen_capture.md) = 0, [OH_CAPTURE_SPECIFIED_SCREEN](_a_v_screen_capture.md) = 1, [OH_CAPTURE_SPECIFIED_WINDOW](_a_v_screen_capture.md) = 2, [OH_CAPTURE_INVAILD](_a_v_screen_capture.md) = -1 } | 枚举，表示屏幕录制的不同模式。 | 
| [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) {<br/>[OH_SOURCE_INVALID](_a_v_screen_capture.md) = -1, [OH_SOURCE_DEFAULT](_a_v_screen_capture.md) = 0, [OH_MIC](_a_v_screen_capture.md) = 1, [OH_ALL_PLAYBACK](_a_v_screen_capture.md) = 2,<br/>[OH_APP_PLAYBACK](_a_v_screen_capture.md) = 3<br/>} | 枚举，表示屏幕录制时的音频源类型。 | 
| [OH_AudioCodecFormat](_a_v_screen_capture.md#oh_audiocodecformat) { [OH_AUDIO_DEFAULT](_a_v_screen_capture.md) = 0, [OH_AAC_LC](_a_v_screen_capture.md) = 3, [OH_AUDIO_CODEC_FORMAT_BUTT](_a_v_screen_capture.md) } | 枚举，表示音频编码格式。 | 
| [OH_VideoCodecFormat](_a_v_screen_capture.md#oh_videocodecformat) {<br/>[OH_VIDEO_DEFAULT](_a_v_screen_capture.md) = 0, [OH_H264](_a_v_screen_capture.md) = 2, [OH_H265](_a_v_screen_capture.md) = 4, [OH_MPEG4](_a_v_screen_capture.md) = 6,<br/>[OH_VP8](_a_v_screen_capture.md) = 8, [OH_VP9](_a_v_screen_capture.md) = 10, [OH_VIDEO_CODEC_FORMAT_BUTT](_a_v_screen_capture.md)<br/>} | 枚举，表示视频编码格式。 | 
| [OH_DataType](_a_v_screen_capture.md#oh_datatype) { [OH_ORIGINAL_STREAM](_a_v_screen_capture.md) = 0, [OH_ENCODED_STREAM](_a_v_screen_capture.md) = 1, [OH_CAPTURE_FILE](_a_v_screen_capture.md) = 2, OH_INVAILD = -1 } | 枚举，表示屏幕录制流的数据格式。 | 
| [OH_VideoSourceType](_a_v_screen_capture.md#oh_videosourcetype) { [OH_VIDEO_SOURCE_SURFACE_YUV](_a_v_screen_capture.md) = 0, [OH_VIDEO_SOURCE_SURFACE_ES](_a_v_screen_capture.md), [OH_VIDEO_SOURCE_SURFACE_RGBA](_a_v_screen_capture.md), [OH_VIDEO_SOURCE_BUTT](_a_v_screen_capture.md) } | 枚举，表示视频源格式。 | 
| [OH_ContainerFormatType](_a_v_screen_capture.md#oh_containerformattype) { [CFT_MPEG_4A](_a_v_screen_capture.md) = 0, [CFT_MPEG_4](_a_v_screen_capture.md) = 1 } | 枚举，表示屏幕录制生成的文件类型。<br>**说明：** 预留接口，将在后续版本提供。 | 
