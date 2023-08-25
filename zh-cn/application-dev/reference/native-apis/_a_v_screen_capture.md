# AVScreenCapture


## 概述

调用本模块下的接口，应用可以完成屏幕录制的功能。

**系统能力**：SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：**

10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_avscreen_capture.h](native__avscreen__capture_8h.md) | 声明用于构造屏幕录制对象的Native API。<br>**引用文件**：<multimedia/player_framework/native_avscreen_capture.h> <br>**库**：libnative_avscreen_capture.so | 
| [native_avscreen_capture_base.h](native__avscreen__capture__base_8h.md) | 声明用于运行屏幕录制通用的结构体、字符常量、枚举。<br>**引用文件**：<multimedia/player_framework/native_avscreen_capture_base.h> <br>**库**：libnative_avscreen_capture.so | 
| [native_avscreen_capture_errors.h](native__avscreen__capture__errors_8h.md) | 声明用于运行屏幕录制过程中接口调用的错误码说明。<br>**引用文件**：<multimedia/player_framework/native_avscreen_capture_errors.h> <br>**库**：libnative_avscreen_capture.so | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCaptureInfo](_o_h___audio_capture_info.md) | 音频录制信息。 | 
| [OH_AudioEncInfo](_o_h___audio_enc_info.md) | 音频编码信息。<br>**说明：** 预留接口，将在后续版本提供。 | 
| [OH_AudioInfo](_o_h___audio_info.md) | 音频录制参数。 | 
| [OH_VideoCaptureInfo](_o_h___video_capture_info.md) | 视频采集信息。 | 
| [OH_VideoEncInfo](_o_h___video_enc_info.md) | 视频编码信息。 <br>**说明：** 预留接口，将在后续版本提供。| 
| [OH_VideoInfo](_o_h___video_info.md) | 视频录制参数。 | 
| [OH_RecorderInfo](_o_h___recorder_info.md) | 录制文件信息。 <br>**说明：** 预留接口，将在后续版本提供。| 
| [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) | 屏幕录制配置参数。 | 
| [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) | OH_AVScreenCapture中所有异步回调函数指针的集合。 | 
| [OH_Rect](_o_h___rect.md) | 定义录屏界面的宽高以及画面信息。 | 
| [OH_AudioBuffer](_o_h___audio_buffer.md) | 定义了音频数据的大小，类型，时间戳等配置信息。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NativeBuffer](#oh_nativebuffer) | 提供录屏的视频原始码流类。 | 
| [OH_AVScreenCapture](#oh_avscreencapture) | 通过OH_AVScreenCapture可以获取视频与音频的原始码流。 | 
| [OH_CaptureMode](#oh_capturemode) | 枚举，表示屏幕录制的不同模式。 | 
| [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) | 枚举，表示屏幕录制时的音频源类型。 | 
| [OH_AudioCodecFormat](#oh_audiocodecformat) | 枚举，表示音频编码格式。 | 
| [OH_VideoCodecFormat](#oh_videocodecformat) | 枚举，表示视频编码格式。 | 
| [OH_DataType](#oh_datatype) | 枚举，表示屏幕录制流的数据格式。 | 
| [OH_VideoSourceType](#oh_videosourcetype) | 枚举，表示视频源格式。 | 
| [OH_ContainerFormatType](#oh_containerformattype) | 枚举，表示屏幕录制生成的文件类型。<br>**说明：** 预留接口，将在后续版本提供。 | 
| [OH_AudioCaptureInfo](#oh_audiocaptureinfo) | 音频录制信息。 | 
| [OH_AudioEncInfo](#oh_audioencinfo) | 音频编码信息。 <br>**说明：** 预留接口，将在后续版本提供。| 
| [OH_AudioInfo](#oh_audioinfo) | 音频录制参数。 | 
| [OH_VideoCaptureInfo](#oh_videocaptureinfo) | 视频采集信息。 | 
| [OH_VideoEncInfo](#oh_videoencinfo) | 视频编码信息。<br>**说明：** 预留接口，将在后续版本提供。 | 
| [OH_VideoInfo](#oh_videoinfo) | 视频录制参数。 | 
| [OH_RecorderInfo](#oh_recorderinfo) | 录制文件信息。 | 
| [OH_AVScreenCaptureConfig](#oh_avscreencaptureconfig) | 屏幕录制配置参数。 | 
| (\*[OH_AVScreenCaptureOnError](#oh_avscreencaptureonerror)) ([OH_AVScreenCapture](#oh_avscreencapture) \*capture, int32_t errorCode) | 当OH_AVScreenCapture实例运行出错时，将调用函数指针。 | 
| (\*[OH_AVScreenCaptureOnAudioBufferAvailable](#oh_avscreencaptureonaudiobufferavailable)) ([OH_AVScreenCapture](#oh_avscreencapture) \*capture, bool isReady, [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) type) | 当OH_AVScreenCapture操作期间音频缓冲区可用时，将调用函数指针。 | 
| (\*[OH_AVScreenCaptureOnVideoBufferAvailable](#oh_avscreencaptureonvideobufferavailable)) ([OH_AVScreenCapture](#oh_avscreencapture) \*capture, bool isReady) | 当OH_AVScreenCapture操作期间视频缓冲区可用时，将调用函数指针。 | 
| [OH_AVScreenCaptureCallback](#oh_avscreencapturecallback) | OH_AVScreenCapture中所有异步回调函数指针的集合。 | 
| [OH_Rect](#oh_rect) | 定义录屏界面的宽高以及画面信息。 | 
| [OH_AudioBuffer](#oh_audiobuffer) | 定义了音频数据的大小，类型，时间戳等配置信息。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) | 屏幕录制过程中产生的不同结果码。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_CaptureMode](#oh_capturemode) { OH_CAPTURE_HOME_SCREEN = 0, OH_CAPTURE_SPECIFIED_SCREEN = 1, OH_CAPTURE_SPECIFIED_WINDOW = 2, OH_CAPTURE_INVAILD = -1 } | 枚举，表示屏幕录制的不同模式。 | 
| [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) {<br/>OH_SOURCE_INVALID = -1, OH_SOURCE_DEFAULT = 0, OH_MIC = 1, OH_ALL_PLAYBACK = 2,<br/>OH_APP_PLAYBACK = 3<br/>} | 枚举，表示屏幕录制时的音频源类型。 | 
| [OH_AudioCodecFormat](#oh_audiocodecformat) { OH_AUDIO_DEFAULT = 0, OH_AAC_LC = 3, OH_AUDIO_CODEC_FORMAT_BUTT } | 枚举，表示音频编码格式。 | 
| [OH_VideoCodecFormat](#oh_videocodecformat) {<br/>OH_VIDEO_DEFAULT = 0, OH_H264 = 2, OH_H265 = 4, OH_MPEG4 = 6,<br/>OH_VP8 = 8, OH_VP9 = 10, OH_VIDEO_CODEC_FORMAT_BUTT<br/>} | 枚举，表示视频编码格式。 | 
| [OH_DataType](#oh_datatype) { OH_ORIGINAL_STREAM = 0, OH_ENCODED_STREAM = 1, OH_CAPTURE_FILE = 2, OH_INVAILD = -1 } | 枚举，表示屏幕录制流的数据格式。 | 
| [OH_VideoSourceType](#oh_videosourcetype) { OH_VIDEO_SOURCE_SURFACE_YUV = 0, OH_VIDEO_SOURCE_SURFACE_ES, OH_VIDEO_SOURCE_SURFACE_RGBA, OH_VIDEO_SOURCE_BUTT } | 枚举，表示视频源格式。 | 
| [OH_ContainerFormatType](#oh_containerformattype) { CFT_MPEG_4A = 0, CFT_MPEG_4 = 1 } | 枚举，表示屏幕录制生成的文件类型。<br>**说明：** 预留接口，将在后续版本提供。 | 
| [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode) {<br/>AV_SCREEN_CAPTURE_ERR_BASE = 0, AV_SCREEN_CAPTURE_ERR_OK = AV_SCREEN_CAPTURE_ERR_BASE, AV_SCREEN_CAPTURE_ERR_NO_MEMORY = AV_SCREEN_CAPTURE_ERR_BASE + 1, AV_SCREEN_CAPTURE_ERR_OPERATE_NOT_PERMIT = AV_SCREEN_CAPTURE_ERR_BASE + 2,<br/>AV_SCREEN_CAPTURE_ERR_INVALID_VAL = AV_SCREEN_CAPTURE_ERR_BASE + 3, AV_SCREEN_CAPTURE_ERR_IO = AV_SCREEN_CAPTURE_ERR_BASE + 4, AV_SCREEN_CAPTURE_ERR_TIMEOUT = AV_SCREEN_CAPTURE_ERR_BASE + 5, AV_SCREEN_CAPTURE_ERR_UNKNOWN = AV_SCREEN_CAPTURE_ERR_BASE + 6,<br/>AV_SCREEN_CAPTURE_ERR_SERVICE_DIED = AV_SCREEN_CAPTURE_ERR_BASE + 7, AV_SCREEN_CAPTURE_ERR_INVALID_STATE = AV_SCREEN_CAPTURE_ERR_BASE + 8, AV_SCREEN_CAPTURE_ERR_UNSUPPORT = AV_SCREEN_CAPTURE_ERR_BASE + 9, AV_SCREEN_CAPTURE_ERR_EXTEND_START = AV_SCREEN_CAPTURE_ERR_BASE + 100<br/>} | 屏幕录制过程中产生的不同结果码。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVScreenCapture_Create](#oh_avscreencapture_create) (void) | 实例化对象，创建OH_AVScreenCapture。 | 
| [OH_AVScreenCapture_Init](#oh_avscreencapture_init) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AVScreenCaptureConfig](_o_h___a_v_screen_capture_config.md) config) | 初始化OH_AVScreenCapture相关参数。 | 
| [OH_AVScreenCapture_StartScreenCapture](#oh_avscreencapture_startscreencapture) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | 开始录屏，采集原始码流。调用后可以通过回调的监听(OH_AVScreenCaptureOnAudioBufferAvailable，OH_AVScreenCaptureOnVideoBufferAvailable)来监听当前是否有码流的产生。 | 
| [OH_AVScreenCapture_StopScreenCapture](#oh_avscreencapture_stopscreencapture) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | 结束录屏，与OH_AVScreenCapture_StartScreenCapture配合使用。调用后针对调用该接口的应用会停止录屏或屏幕共享，释放麦克风。 | 
| [OH_AVScreenCapture_StartScreenRecording](#oh_avscreencapture_startscreenrecording) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | 启动录屏，调用此接口，可采集编码后的码流。<br>**说明：** 预留接口，将在后续版本提供。 | 
| [OH_AVScreenCapture_StopScreenRecording](#oh_avscreencapture_stopscreenrecording) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | 停止录屏，与OH_AVScreenCapture_StartScreenRecording配合使用。 <br>**说明：** 预留接口，将在后续版本提供。| 
| [OH_AVScreenCapture_AcquireAudioBuffer](#oh_avscreencapture_acquireaudiobuffer) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AudioBuffer](_o_h___audio_buffer.md) \*\*audiobuffer, [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) type) | 获取音频buffer，应用在调用时，需要对audiobuffer分配对应结构体大小的内存，否则会影响拿到音频buffer的获取。 | 
| [OH_AVScreenCapture_AcquireVideoBuffer](#oh_avscreencapture_acquirevideobuffer) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, int32_t \*fence, int64_t \*timestamp, struct [OH_Rect](_o_h___rect.md) \*region) | 获取视频buffer，应用在调用时，通过此接口来获取到视频的buffer以及时间戳等信息。 | 
| [OH_AVScreenCapture_ReleaseAudioBuffer](#oh_avscreencapture_releaseaudiobuffer) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) type) | 根据音频类型释放buffer。 | 
| [OH_AVScreenCapture_ReleaseVideoBuffer](#oh_avscreencapture_releasevideobuffer) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | 根据视频类型释放buffer。 | 
| [OH_AVScreenCapture_SetCallback](#oh_avscreencapture_setcallback) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, struct [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md) callback) | 设置监听接口，通过设置监听，可以监听到调用过程中的错误信息，以及是否有可用的视频buffer和音频buffer。 | 
| [OH_AVScreenCapture_Release](#oh_avscreencapture_release) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture) | 释放创建的OH_AVScreenCapture实例，对应OH_AVScreenCapture_Create。 | 
| [OH_AVScreenCapture_SetMicrophoneEnabled](#oh_avscreencapture_setmicrophoneenabled) (struct [OH_AVScreenCapture](#oh_avscreencapture) \*capture, bool isMicrophone) | 设置麦克风开关。 | 


## 类型定义说明


### OH_AudioBuffer

```
typedef struct OH_AudioBuffer OH_AudioBuffer
```

**描述：**

定义了音频数据的大小，类型，时间戳等配置信息。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AudioCaptureInfo

```
typedef struct OH_AudioCaptureInfo OH_AudioCaptureInfo
```

**描述：**

音频录制信息。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AudioCaptureSourceType

```
typedef enum OH_AudioCaptureSourceType OH_AudioCaptureSourceType
```

**描述：**

枚举，表示屏幕录制时的音频源类型。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AudioCodecFormat

```
typedef enum OH_AudioCodecFormat OH_AudioCodecFormat
```

**描述：**

枚举，表示音频编码格式。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AudioEncInfo

```
typedef struct OH_AudioEncInfo OH_AudioEncInfo
```

**描述：**

音频编码信息。

> **说明：** 
> 
> 预留接口，将在后续版本提供。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AudioInfo

```
typedef struct OH_AudioInfo OH_AudioInfo
```

**描述：**

音频录制参数。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AVSCREEN_CAPTURE_ErrCode

```
typedef enum OH_AVSCREEN_CAPTURE_ErrCode OH_AVSCREEN_CAPTURE_ErrCode
```

**描述：**

屏幕录制过程中产生的不同结果码。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AVScreenCapture

```
typedef struct OH_AVScreenCapture OH_AVScreenCapture
```

**描述：**

通过OH_AVScreenCapture可以获取视频与音频的原始码流。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AVScreenCaptureCallback

```
typedef struct OH_AVScreenCaptureCallback OH_AVScreenCaptureCallback
```

**描述：**

OH_AVScreenCapture中所有异步回调函数指针的集合。将该结构体的实例注册到OH_AVScreenCapture实例中， 并处理回调上报的信息，以保证OH_AVScreenCapture的正常运行。

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| onError | 监控录屏调用操作错误，请参见[OH_AVScreenCaptureOnError](#oh_avscreencaptureonerror)。 | 
| onAudioBufferAvailable | 监控音频码流是否有数据产生，请参见[OH_AVScreenCaptureOnAudioBufferAvailable](#oh_avscreencaptureonaudiobufferavailable)。 | 
| onVideoBufferAvailable | 监控视频码流是否有数据产生，请参见[OH_AVScreenCaptureOnVideoBufferAvailable](#oh_avscreencaptureonvideobufferavailable)。 | 

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AVScreenCaptureConfig

```
typedef struct OH_AVScreenCaptureConfig OH_AVScreenCaptureConfig
```

**描述：**

屏幕录制配置参数。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AVScreenCaptureOnAudioBufferAvailable

```
typedef void(* OH_AVScreenCaptureOnAudioBufferAvailable) (OH_AVScreenCapture *capture, bool isReady, OH_AudioCaptureSourceType type)
```

**描述：**

当OH_AVScreenCapture操作期间音频缓冲区可用时，将调用函数指针。

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 
| isReady | 音频缓冲区是否可用。 | 
| type | 音频源类型。 | 

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AVScreenCaptureOnError

```
typedef void(* OH_AVScreenCaptureOnError) (OH_AVScreenCapture *capture, int32_t errorCode)
```

**描述：**

当OH_AVScreenCapture实例运行出错时，将调用函数指针。

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 
| errorCode | 指定错误码。 | 

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_AVScreenCaptureOnVideoBufferAvailable

```
typedef void(* OH_AVScreenCaptureOnVideoBufferAvailable) (OH_AVScreenCapture *capture, bool isReady)
```

**描述：**

当OH_AVScreenCapture操作期间视频缓冲区可用时，将调用函数指针。

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 
| isReady | 视频缓冲区是否可用。 | 

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_CaptureMode

```
typedef enum OH_CaptureModeOH_CaptureMode
```

**描述：**

枚举，表示屏幕录制的不同模式。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_ContainerFormatType

```
typedef enum OH_ContainerFormatType OH_ContainerFormatType
```

**描述：**

枚举，表示屏幕录制生成的文件类型。

> **说明：**
>
> 预留接口，将在后续版本提供。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_DataType

```
typedef enum OH_DataType OH_DataType
```

**描述：**

枚举，表示屏幕录制流的数据格式。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_NativeBuffer

```
typedef struct OH_NativeBuffer OH_NativeBuffer
```

**描述：**

提供录屏的视频原始码流类。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_RecorderInfo

```
typedef struct OH_RecorderInfo OH_RecorderInfo
```

**描述：**

录制文件信息。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_Rect

```
typedef struct OH_Rect OH_Rect
```

**描述：**

定义录屏界面的宽高以及画面信息。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_VideoCaptureInfo

```
typedef struct OH_VideoCaptureInfo OH_VideoCaptureInfo
```

**描述：**

视频采集信息。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_VideoCodecFormat

```
typedef enum OH_VideoCodecFormat OH_VideoCodecFormat
```

**描述：**

枚举，表示视频编码格式。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_VideoEncInfo

```
typedef struct OH_VideoEncInfo OH_VideoEncInfo
```

**描述：**

视频编码参数。

> **说明：** 
> 
> 预留接口，将在后续版本提供。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_VideoInfo

```
typedef struct OH_VideoInfo OH_VideoInfo
```

**描述：**

视频录制参数。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


### OH_VideoSourceType

```
typedef enum OH_VideoSourceType OH_VideoSourceType
```

**描述：**

枚举，表示视频源格式。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture


## 枚举类型说明


### OH_AudioCaptureSourceType

```
enum OH_AudioCaptureSourceType
```

**描述：**

枚举，表示屏幕录制时的音频源类型。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_SOURCE_INVALID | 无效音频源。 | 
| OH_SOURCE_DEFAULT | 默认音频源，默认为MIC。 | 
| OH_MIC | 麦克风录制的外部音频流。 | 
| OH_ALL_PLAYBACK | 系统播放的所有内部音频流。 | 
| OH_APP_PLAYBACK | 指定应用播放的内部音频流。 | 


### OH_AudioCodecFormat

```
enum OH_AudioCodecFormat
```

**描述：**

枚举，表示音频编码格式。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_AUDIO_DEFAULT | 默认音频编码，默认为AAC_LC。 | 
| OH_AAC_LC | AAC_LC音频编码。 | 
| OH_AUDIO_CODEC_FORMAT_BUTT | 无效格式。 | 


### OH_AVSCREEN_CAPTURE_ErrCode

```
enum OH_AVSCREEN_CAPTURE_ErrCode
```

**描述：**

屏幕录制过程中产生的不同结果码。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

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


### OH_CaptureMode

```
enum OH_CaptureMode
```

**描述：**

枚举，表示屏幕录制的不同模式。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_CAPTURE_HOME_SCREEN | 录制主屏幕。 | 
| OH_CAPTURE_SPECIFIED_SCREEN | 录制指定屏幕。<br>**说明：** 预留接口，将在后续版本提供。 | 
| OH_CAPTURE_SPECIFIED_WINDOW | 录制指定窗口。 <br>**说明：** 预留接口，将在后续版本提供。| 
| OH_CAPTURE_INVAILD | 无效模式。 | 


### OH_ContainerFormatType

```
enum OH_ContainerFormatType
```

**描述：**

枚举，表示屏幕录制生成的文件类型。

> **说明：**
>
> 预留接口，将在后续版本提供。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

| 枚举值 | 描述 | 
| -------- | -------- |
| CFT_MPEG_4A | 音频格式 m4a。 | 
| CFT_MPEG_4 | 视频格式 mp4。 | 


### OH_DataType

```
enum OH_DataType
```

**描述：**

枚举，表示屏幕录制流的数据格式。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_ORIGINAL_STREAM | 原始流格式，如YUV/RGBA/PCM等。 | 
| OH_ENCODED_STREAM | 编码格式，如H264/AAC等。 <br>**说明：** 预留接口，将在后续版本提供。 | 
| OH_CAPTURE_FILE | 保存文件格式，支持mp4。<br>**说明：** 预留接口，将在后续版本提供。 | 
| OH_INVAILD | 无效格式。 | 


### OH_VideoCodecFormat

```
enum OH_VideoCodecFormat
```

**描述：**

枚举，表示视频编码格式。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_VIDEO_DEFAULT | 默认视频编码，默认为H.264。 | 
| OH_H264 | H.264 | 
| OH_H265 | H.265/HEVC | 
| OH_MPEG4 | MPEG4 | 
| OH_VP8 | VP8 | 
| OH_VP9 | VP9 | 
| OH_VIDEO_CODEC_FORMAT_BUTT | 无效格式。 | 


### OH_VideoSourceType

```
enum OH_VideoSourceType
```

**描述：**

枚举，表示视频源格式。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_VIDEO_SOURCE_SURFACE_YUV | YUV格式。 | 
| OH_VIDEO_SOURCE_SURFACE_ES | raw格式。 | 
| OH_VIDEO_SOURCE_SURFACE_RGBA | RGBA格式。 | 
| OH_VIDEO_SOURCE_BUTT | 无效格式。 | 


## 函数说明


### OH_AVScreenCapture_AcquireAudioBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_AcquireAudioBuffer (struct OH_AVScreenCapture * capture, OH_AudioBuffer ** audiobuffer, OH_AudioCaptureSourceType type )
```

**描述：**

获取音频buffer，应用在调用时，需要对audiobuffer分配对应结构体大小的内存，否则会影响拿到音频buffer的获取。

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 
| audiobuffer | 保存音频buffer的结构体，通过该结构体获取到音频buffer以及buffer的时间戳等信息。 | 
| type | 音频buffer的类型，区分是麦克风录制的外部流还是系统内部播放音频的内录流，详情请参阅[OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) | 

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK， 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode)。


### OH_AVScreenCapture_AcquireVideoBuffer()

```
OH_NativeBuffer* OH_AVScreenCapture_AcquireVideoBuffer (struct OH_AVScreenCapture * capture, int32_t * fence, int64_t * timestamp, struct OH_Rect * region )
```

**描述：**

获取视频buffer，应用在调用时，通过此接口来获取到视频的buffer以及时间戳等信息。 buffer使用完成后，调用OH_AVScreenCapture_ReleaseVideoBuffer接口进行视频buffer的释放。

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 
| fence | 用于同步的显示相关参数信息。 | 
| timestamp | 视频帧的时间戳。 | 
| region | 视频显示相关的坐标信息。 | 

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

**返回：**

执行成功返回OH_NativeBuffer对象，通过OH_NativeBuffer对象相关接口可以获取到视频buffer和分辨率等信息参数。


### OH_AVScreenCapture_Create()

```
struct OH_AVScreenCapture* OH_AVScreenCapture_Create (void )
```

**描述：**

实例化对象，创建OH_AVScreenCapture。可以通过调用OH_AVScreenCapture_Release释放实例。

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

**返回：**

返回一个指向OH_AVScreenCapture实例的指针。


### OH_AVScreenCapture_Init()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Init (struct OH_AVScreenCapture * capture, OH_AVScreenCaptureConfig config )
```

**描述：**

初始化OH_AVScreenCapture相关参数，包括下发的音频麦克风采样信息参数，音频内录相关参数(可选)，视频分辨率相关参数。

调用此函数，需要申请麦克风权限（ohos.permission.MICROPHONE）和截屏权限（ohos.permission.CAPTURE_SCREEN）,否则会初始化失败导致无法正常录屏。

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 
| config | 录屏初始化相关参数。 | 

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK, 否则返回具体错误码，请参阅 [OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode)。


### OH_AVScreenCapture_Release()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_Release (struct OH_AVScreenCapture * capture)
```

**描述：**

释放创建的OH_AVScreenCapture实例，对应OH_AVScreenCapture_Create。

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK， 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode)。


### OH_AVScreenCapture_ReleaseAudioBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseAudioBuffer (struct OH_AVScreenCapture * capture, OH_AudioCaptureSourceType type )
```

**描述：**

根据音频类型释放buffer。当某一帧音频buffer使用完成后，调用此接口进行释放对应的音频buffer。

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 
| type | 音频buffer的类型，区分麦克风录制的外部流还是系统内部播放音频的内录流。 | 

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK， 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode)。


### OH_AVScreenCapture_ReleaseVideoBuffer()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_ReleaseVideoBuffer (struct OH_AVScreenCapture * capture)
```

**描述：**

根据视频类型释放buffer。当某一帧视频buffer使用完成后，调用此接口进行释放对应的视频buffer。

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK， 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode)。


### OH_AVScreenCapture_SetCallback()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetCallback (struct OH_AVScreenCapture * capture, struct OH_AVScreenCaptureCallback callback )
```

**描述：**

设置监听接口，通过设置监听，可以监听到调用过程中的错误信息，以及是否有可用的视频buffer和音频buffer。

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 
| callback | [OH_AVScreenCaptureCallback](_o_h___a_v_screen_capture_callback.md)的结构体，保存相关回调函数指针。 | 

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK， 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode)。


### OH_AVScreenCapture_SetMicrophoneEnabled()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_SetMicrophoneEnabled (struct OH_AVScreenCapture * capture, bool isMicrophone )
```

**描述：**

设置麦克风开关。当isMicrophone为true时，则打开麦克风，通过调用OH_AVScreenCapture_StartScreenRecording和OH_AVScreenCapture_AcquireAudioBuffer可以正常获取到音频的麦克风原始PCM数据；isMicrophone为false时，获取到的音频数据为无声数据。

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 
| isMicrophone | 麦克风开关参数。 | 

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK，否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode)。


### OH_AVScreenCapture_StartScreenCapture()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenCapture (struct OH_AVScreenCapture * capture)
```

**描述：**

开始录屏，采集原始码流。调用后可以通过回调的监听(OH_AVScreenCaptureOnAudioBufferAvailable，OH_AVScreenCaptureOnVideoBufferAvailable)来监听当前是否有码流的产生。

通过调用获取音频buffer(OH_AVScreenCapture_AcquireAudioBuffer)和视频buffer(OH_AVScreenCapture_ReleaseVideoBuffer)的接口来获取录屏的原始码流

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK, 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode)。


### OH_AVScreenCapture_StartScreenRecording()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StartScreenRecording (struct OH_AVScreenCapture * capture)
```

**描述：**

启动录屏，调用此接口，可采集编码后的码流。

> **说明：** 
> 
> 预留接口，将在后续版本提供。

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK， 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode)。


### OH_AVScreenCapture_StopScreenCapture()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenCapture (struct OH_AVScreenCapture * capture)
```

**描述：**

结束录屏，与OH_AVScreenCapture_StartScreenCapture配合使用。调用后针对调用该接口的应用会停止录屏或屏幕共享，释放麦克风。

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK， 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode)。


### OH_AVScreenCapture_StopScreenRecording()

```
OH_AVSCREEN_CAPTURE_ErrCode OH_AVScreenCapture_StopScreenRecording (struct OH_AVScreenCapture * capture)
```

**描述：**

停止录屏，与OH_AVScreenCapture_StartScreenRecording配合使用。

> **说明：** 
> 
> 预留接口，将在后续版本提供。

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| capture | 指向OH_AVScreenCapture实例的指针。 | 

**系统能力：**

SystemCapability.Multimedia.Media.AVScreenCapture

**返回：**

执行成功返回AV_SCREEN_CAPTURE_ERR_OK， 否则返回具体错误码，请参阅[OH_AVSCREEN_CAPTURE_ErrCode](#oh_avscreen_capture_errcode)。
