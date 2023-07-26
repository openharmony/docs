# native_avscreen_capture_base.h

## 概述

声明运行屏幕录制通用的结构体、字符常量、枚举

\@syscap SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10

**相关模块：**

[AVScreenCapture](_a_v_screen_capture.md)

## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCaptureInfo](_a_v_screen_capture_base.md#oh_audiocaptureinfo) | 定义音频录制audiocapture实例的描述信息。 |
| [OH_AudioEncInfo](_a_v_screen_capture_base.md#oh_audioencinfo) | 定义音频的编码数据的描述信息。 |
| [OH_AudioInfo](_a_v_screen_capture_base.md#oh_audioinfo) | 定义屏幕录制时音频的描述信息。 |
| [OH_VideoCaptureInfo](_a_v_screen_capture_base.md#oh_videocaptureinfo) | 定义屏幕录制中视频录制capture的描述信息。 |
| [OH_VideoEncInfo](_a_v_screen_capture_base.md#oh_videoencinfo) | 定义屏幕录制中视频的编码数据描述信息。 |
| [OH_VideoInfo](_a_v_screen_capture_base.md#oh_videoinfo) | 定义屏幕录制时视频的描述信息。 |
| [OH_AVScreenCaptureConfig](_a_v_screen_capture_base.md#oh_avscreencaptureconfig) | 定义整体avscreencapture的配置信息。 |
| [OH_AVScreenCaptureCallback](_a_v_screen_capture_callback.md) | 定义avscreencapture的回调信息，包含不同的回调函数类型。 |
| [OH_Rect](_a_v_screen_capture_base.md#oh_rect) | 定义录屏的宽高以及画面信息。 |
| [OH_AudioBuffer](_a_v_screen_capture_base.md#oh_audiobuffer) | 定义了音频数据的大小，类型，时间戳等配置信息。 |

### 类型定义
| 名称 | 描述 | 
| -------- | -------- |
| (\*[OH_AVScreenCaptureOnError](_a_v_screen_capture_base.md#oh_avscreencaptureonerror)) (OH_AVScreenCapture \*capture, int32_t errorCode)| 当screencapture在运行过程中执行某一流程出现错误，则调用该函数指针并上报错误码。 |
| (\*[OH_AVScreenCaptureOnAudioBufferAvailable](_a_v_screen_capture_base.md#avscreencaptureonaudiobufferavailable)) (OH_AVScreenCapture \*capture, bool isReady, OH_AudioCaptureSourceType type)| 当screencapture在运行，音频缓冲可用时，调用该函数指针并更新状态信息。 |
| (\*[OH_AVScreenCaptureOnVideoBufferAvailable](_a_v_screen_capture_base.md#avscreencaptureonvideobufferavailable)) (OH_AVScreenCapture \*capture, bool isReady)| 当screencapture在运行，视频缓冲可用时，调用该函数指针并更新状态信息。 |

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_CaptureMode](_a_v_screen_capture_base.md#oh_capturemode) {<br/>**OH_CAPTURE_HOME_SCREEN** = 0，**OH_CAPTURE_SPECIFIED_SCREEN** = 1, **OH_CAPTURE_SPECIFIED_WINDOW** = 2, **OH_CAPTURE_INVAILD** = -1<br/>} | 屏幕录制的不同模式。 |
| [OH_AudioCaptureSourceType](_a_v_screen_capture_base.md#oh_audiocapturesourcetype) {<br/>**OH_SOURCE_INVALID** = -1, **OH_SOURCE_DEFAULT** = 0, **OH_MIC** = 1, **OH_ALL_PLAYBACK** = 2, **OH_APP_PLAYBACK** = 3<br/>} | 屏幕录制音频的不同source类型。 |
| [OH_AudioCodecFormat](_a_v_screen_capture_base.md#oh_audiocodecformat) {<br/>**OH_AUDIO_DEFAULT** = 0, **OH_AAC_LC** = 3, **OH_AUDIO_CODEC_FORMAT_BUTT**,<br/>} | 屏幕录制音频的不同的编码格式。 |
| [OH_VideoCodecFormat](_a_v_screen_capture_base.md#oh_videocodecformat) {<br/>**OH_VIDEO_DEFAULT** = 0, **OH_H264** = 2, **OH_H265** = 4, **OH_MPEG4** = 6, **OH_VP8** = 8, **OH_VP9** = 10, **OH_VIDEO_CODEC_FORMAT_BUTT**<br/>} | 屏幕录制视频的不同编码格式。 |
| [OH_DataType](_a_v_screen_capture_base.md#oh_datatype) {<br/>**OH_ORIGINAL_STREAM** = 0, **OH_ENCODED_STREAM** = 1, **OH_CAPTURE_FILE** = 2, **OH_INVAILD** = -1<br/>} | 屏幕录制流的数据格式，编码格式，以及保存文件格式等参数。 |
| [OH_VideoSourceType](_a_v_screen_capture_base.md#oh_videosourcetype) {<br/>**OH_VIDEO_SOURCE_SURFACE_YUV** = 0, **OH_VIDEO_SOURCE_SURFACE_ES**, **OH_VIDEO_SOURCE_SURFACE_RGBA**, **OH_VIDEO_SOURCE_BUTT**<br/>} | 屏幕录制视频的不同source类型。 |
| [OH_ContainerFormatType](_a_v_screen_capture_base.md#oh_containerformattype) {<br/>**CFT_MPEG_4A** = 0, **CFT_MPEG_4** = 1<br/>} | 屏幕录制生成物的不同音视频格式类型。 |
