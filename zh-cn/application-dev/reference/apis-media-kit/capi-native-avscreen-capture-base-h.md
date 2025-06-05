# native_avscreen_capture_base.h

## 概述

声明用于运行屏幕录制通用的结构体、字符常量、枚举。

**库：** libnative_avscreen_capture.so

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AudioCaptureInfo](capi-oh-audiocaptureinfo.md) | OH_AudioCaptureInfo | 音频采样信息。<br>当audioSampleRate和audioChannels同时为0时，忽略该类型音频相关参数，不录制该类型音频数据。 |
| [OH_NativeBuffer](capi-oh-nativebuffer.md) | OH_NativeBuffer | 提供录屏的视频原始码流类。 |
| [OH_AVScreenCapture](capi-oh-avscreencapture.md) | OH_AVScreenCapture | 通过OH_AVScreenCapture可以获取视频与音频的原始码流。 |
| [OH_AVScreenCapture_ContentFilter](capi-oh-avscreencapture-contentfilter.md) | OH_AVScreenCapture_ContentFilter | 通过OH_AVScreenCapture_ContentFilter过滤音视频内容。 |
| [OH_AVScreenCapture_CaptureStrategy](capi-oh-avscreencapture-capturestrategy.md) | OH_AVScreenCapture_CaptureStrategy | 通过OH_AVScreenCapture_CaptureStrategy设置录屏策略。 |
| [OH_AudioEncInfo](capi-oh-audioencinfo.md) | OH_AudioEncInfo | 音频编码信息。 |
| [OH_AudioInfo](capi-oh-audioinfo.md) | OH_AudioInfo | 音频信息。<br>同时采集音频麦克风和音频内录数据时，两路音频的audioSampleRate和audioChannels采样参数需要相同。 |
| [OH_VideoCaptureInfo](capi-oh-videocaptureinfo.md) | OH_VideoCaptureInfo | 视频录制信息，当videoFrameWidth和videoFrameHeight同时为0时，忽略视频相关参数不录制屏幕数据。 |
| [OH_VideoEncInfo](capi-oh-videoencinfo.md) | OH_VideoEncInfo | 视频编码参数。 |
| [OH_VideoInfo](capi-oh-videoinfo.md) | OH_VideoInfo | 视频信息。 |
| [OH_RecorderInfo](capi-oh-recorderinfo.md) | OH_RecorderInfo | 录制文件信息。 |
| [OH_AVScreenCaptureConfig](capi-oh-avscreencaptureconfig.md) | OH_AVScreenCaptureConfig | 屏幕录制配置参数。 |
| [OH_AVScreenCaptureCallback](capi-oh-avscreencapturecallback.md) | OH_AVScreenCaptureCallback | OH_AVScreenCapture中所有异步回调函数指针的集合。将该结构体的实例注册到OH_AVScreenCapture实例中， 并处理回调上报的信息，以保证OH_AVScreenCapture的正常运行。<br>从API 12开始，推荐使用接口[OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror)、[OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)替代。 |
| [OH_Rect](capi-oh-rect.md) | OH_Rect | 定义录屏界面的宽高以及画面信息。 |
| [OH_AudioBuffer](capi-oh-audiobuffer.md) | OH_AudioBuffer | 定义了音频数据的大小、类型、时间戳等配置信息。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CaptureMode](#oh_capturemode) | OH_CaptureMode | 枚举，表示屏幕录制的不同模式。 |
| [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) | OH_AudioCaptureSourceType | 枚举，表示屏幕录制时的音频源类型。 |
| [OH_AudioCodecFormat](#oh_audiocodecformat) | OH_AudioCodecFormat | 枚举，表示音频编码格式。 |
| [OH_VideoCodecFormat](#oh_videocodecformat) | OH_VideoCodecFormat | 枚举，表示视频编码格式。 |
| [OH_DataType](#oh_datatype) | OH_DataType | 枚举，表示屏幕录制流的数据格式。 |
| [OH_VideoSourceType](#oh_videosourcetype) | OH_VideoSourceType | 枚举，表示视频源格式。 |
| [OH_ContainerFormatType](#oh_containerformattype) | OH_ContainerFormatType | 枚举，表示屏幕录制生成的文件类型。 |
| [OH_AVScreenCaptureStateCode](#oh_avscreencapturestatecode) | OH_AVScreenCaptureStateCode | 枚举，表示状态码。 |
| [OH_AVScreenCaptureBufferType](#oh_avscreencapturebuffertype) | OH_AVScreenCaptureBufferType | 枚举，表示buffer类型。 |
| [OH_AVScreenCaptureFilterableAudioContent](#oh_avscreencapturefilterableaudiocontent) | OH_AVScreenCaptureFilterableAudioContent | 枚举，表示可过滤的音频类型。 |
| [OH_AVScreenCaptureContentChangedEvent](#oh_avscreencapturecontentchangedevent) | OH_AVScreenCaptureContentChangedEvent | 枚举，表示录屏内容变更事件。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_AVScreenCaptureOnError)(OH_AVScreenCapture *capture, int32_t errorCode)](#oh_avscreencaptureonerror) | OH_AVScreenCaptureOnError | 当OH_AVScreenCapture实例操作期间发生错误时，将调用函数指针。 |
| [typedef void (\*OH_AVScreenCaptureOnAudioBufferAvailable)(OH_AVScreenCapture *capture, bool isReady,OH_AudioCaptureSourceType type)](#oh_avscreencaptureonaudiobufferavailable) | OH_AVScreenCaptureOnAudioBufferAvailable | 当OH_AVScreenCapture操作期间音频缓存区可用时，将调用函数指针。 |
| [typedef void (\*OH_AVScreenCaptureOnVideoBufferAvailable)(OH_AVScreenCapture *capture, bool isReady)](#oh_avscreencaptureonvideobufferavailable) | OH_AVScreenCaptureOnVideoBufferAvailable | 当OH_AVScreenCapture操作期间视频缓存区可用时，将调用函数指针。 |
| [typedef void (\*OH_AVScreenCapture_OnStateChange)(struct OH_AVScreenCapture *capture,OH_AVScreenCaptureStateCode stateCode, void *userData)](#oh_avscreencapture_onstatechange) | OH_AVScreenCapture_OnStateChange | 当OH_AVScreenCapture实例操作期间发生状态变更时，将调用函数指针。 |
| [typedef void (\*OH_AVScreenCapture_OnError)(OH_AVScreenCapture *capture, int32_t errorCode, void *userData)](#oh_avscreencapture_onerror) | OH_AVScreenCapture_OnError | 当OH_AVScreenCapture实例操作期间发生错误时，将调用函数指针。 |
| [typedef void (\*OH_AVScreenCapture_OnBufferAvailable)(OH_AVScreenCapture *capture, OH_AVBuffer *buffer,OH_AVScreenCaptureBufferType bufferType, int64_t timestamp, void *userData)](#oh_avscreencapture_onbufferavailable) | OH_AVScreenCapture_OnBufferAvailable | 当OH_AVScreenCapture实例操作期间音频或视频缓存区可用时，将调用该函数指针。 |
| [typedef void (\*OH_AVScreenCapture_OnDisplaySelected)(OH_AVScreenCapture *capture, uint64_t displayId, void *userData)](#oh_avscreencapture_ondisplayselected) | OH_AVScreenCapture_OnDisplaySelected | 当录屏事件开始时，将调用函数指针。 |
| [typedef void (\*OH_AVScreenCapture_OnCaptureContentChanged)(OH_AVScreenCapture* capture,OH_AVScreenCaptureContentChangedEvent event, OH_Rect* area, void *userData)](#oh_avscreencapture_oncapturecontentchanged) | OH_AVScreenCapture_OnCaptureContentChanged | 当录屏内容变更时，将调用函数指针。 |

## 枚举类型说明

### OH_CaptureMode

```
enum OH_CaptureMode
```

**描述**

枚举，表示屏幕录制的不同模式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OH_CAPTURE_HOME_SCREEN = 0 | 录制主屏幕。 |
| OH_CAPTURE_SPECIFIED_SCREEN = 1 | 录制指定屏幕。 |
| OH_CAPTURE_SPECIFIED_WINDOW = 2 | 录制指定窗口。 |
| OH_CAPTURE_INVAILD = -1 | 无效模式。 |

### OH_AudioCaptureSourceType

```
enum OH_AudioCaptureSourceType
```

**描述**

枚举，表示屏幕录制时的音频源类型。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OH_SOURCE_INVALID = -1 | 无效音频源。 |
| OH_SOURCE_DEFAULT = 0 | 默认音频源，默认为麦克风。 |
| OH_MIC = 1 | 麦克风录制的外部音频流。 |
| OH_ALL_PLAYBACK = 2 | 系统播放的所有内部音频流。 |
| OH_APP_PLAYBACK = 3 | 指定应用播放的内部音频流。 |

### OH_AudioCodecFormat

```
enum OH_AudioCodecFormat
```

**描述**

枚举，表示音频编码格式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OH_AUDIO_DEFAULT = 0 | 默认音频编码，默认为AAC_LC。 |
| OH_AAC_LC = 3 | AAC_LC音频编码。 |
| OH_AUDIO_CODEC_FORMAT_BUTT | 无效格式。 |

### OH_VideoCodecFormat

```
enum OH_VideoCodecFormat
```

**描述**

枚举，表示视频编码格式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OH_VIDEO_DEFAULT = 0 | 默认视频编码，默认为H.264。 |
| OH_H264 = 2 | H.264。 |
| OH_H265 = 4 | H.265/HEVC。 |
| OH_MPEG4 = 6 | MPEG4。|
| OH_VP8 = 8 | VP8。 |
| OH_VP9 = 10 | VP9。 |
| OH_VIDEO_CODEC_FORMAT_BUTT | 无效格式。 |

### OH_DataType

```
enum OH_DataType
```

**描述**

枚举，表示屏幕录制流的数据格式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OH_ORIGINAL_STREAM = 0 | 原始流格式，如YUV/RGBA/PCM等。 |
| OH_ENCODED_STREAM = 1 | 编码格式，如H264/AAC等。当前版本暂不支持。 |
| OH_CAPTURE_FILE = 2 | 保存文件格式，支持mp4。 |
| OH_INVAILD = -1 | 无效格式。 |

### OH_VideoSourceType

```
enum OH_VideoSourceType
```

**描述**

枚举，表示视频源格式。当前仅支持RGBA格式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OH_VIDEO_SOURCE_SURFACE_YUV = 0 | YUV格式。当前版本暂不支持。 |
| OH_VIDEO_SOURCE_SURFACE_ES | raw格式。当前版本暂不支持。 |
| OH_VIDEO_SOURCE_SURFACE_RGBA | RGBA格式。 |
| OH_VIDEO_SOURCE_BUTT | 无效格式。 |

### OH_ContainerFormatType

```
enum OH_ContainerFormatType
```

**描述**

枚举，表示屏幕录制生成的文件类型。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| CFT_MPEG_4A = 0 | 音频格式 m4a。 |
| CFT_MPEG_4 = 1 | 视频格式 mp4。 |

### OH_AVScreenCaptureStateCode

```
enum OH_AVScreenCaptureStateCode
```

**描述**

枚举，表示状态码。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| OH_SCREEN_CAPTURE_STATE_STARTED = 0 | 已开始录屏。 |
| OH_SCREEN_CAPTURE_STATE_CANCELED = 1 | 已取消录屏。 |
| OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER = 2 | 已停止录屏。 |
| OH_SCREEN_CAPTURE_STATE_INTERRUPTED_BY_OTHER = 3 | 录屏被其他录屏中断。 |
| OH_SCREEN_CAPTURE_STATE_STOPPED_BY_CALL = 4 | 录屏被通话中断。 |
| OH_SCREEN_CAPTURE_STATE_MIC_UNAVAILABLE = 5 | 麦克风不可用。 |
| OH_SCREEN_CAPTURE_STATE_MIC_MUTED_BY_USER = 6 | 麦克风被静音。 |
| OH_SCREEN_CAPTURE_STATE_MIC_UNMUTED_BY_USER = 7 | 麦克风被取消静音。 |
| OH_SCREEN_CAPTURE_STATE_ENTER_PRIVATE_SCENE = 8 | 进入隐私界面。 |
| OH_SCREEN_CAPTURE_STATE_EXIT_PRIVATE_SCENE = 9 | 隐私界面退出。 |
| OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER_SWITCHES = 10 | 系统用户切换，录屏中断。 |

### OH_AVScreenCaptureBufferType

```
enum OH_AVScreenCaptureBufferType
```

**描述**

枚举，表示buffer类型。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| OH_SCREEN_CAPTURE_BUFFERTYPE_VIDEO = 0 | 视频数据。 |
| OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_INNER = 1 | 内录音频数据。 |
| OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_MIC = 2 | 麦克风音频数据。 |

### OH_AVScreenCaptureFilterableAudioContent

```
enum OH_AVScreenCaptureFilterableAudioContent
```

**描述**

枚举，表示可过滤的音频类型。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| OH_SCREEN_CAPTURE_NOTIFICATION_AUDIO = 0 | 通知音。 |
| OH_SCREEN_CAPTURE_CURRENT_APP_AUDIO = 1 | 应用自身声音。 |

### OH_AVScreenCaptureContentChangedEvent

```
enum OH_AVScreenCaptureContentChangedEvent
```

**描述**

枚举，表示录屏内容变更事件。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| OH_SCREEN_CAPTURE_CONTENT_HIDE = 0 | 录屏内容变为隐藏。 |
| OH_SCREEN_CAPTURE_CONTENT_VISIBLE = 1 | 录屏内容变为可见。 |
| OH_SCREEN_CAPTURE_CONTENT_UNAVAILABLE = 2 | 录屏内容状态变化为不可用，如录屏窗口关闭。 |


## 函数说明

### OH_AVScreenCaptureOnError()

```
typedef void (*OH_AVScreenCaptureOnError)(OH_AVScreenCapture *capture, int32_t errorCode)
```

**描述**

当OH_AVScreenCapture实例运行出错时，将调用函数指针。

从API 12开始，推荐使用接口[OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror)替代。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
|  int32_t errorCode | 指定错误码。 |

### OH_AVScreenCaptureOnAudioBufferAvailable()

```
typedef void (*OH_AVScreenCaptureOnAudioBufferAvailable)(OH_AVScreenCapture *capture, bool isReady,OH_AudioCaptureSourceType type)
```

**描述**

当OH_AVScreenCapture实例操作期间音频缓存区可用时，将调用函数指针。

从API 12开始，推荐使用接口[OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)替代。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
|  bool isReady | 音频缓存区是否可用。 |
| [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) type | 音频源类型。 |

### OH_AVScreenCaptureOnVideoBufferAvailable()

```
typedef void (*OH_AVScreenCaptureOnVideoBufferAvailable)(OH_AVScreenCapture *capture, bool isReady)
```

**描述**

当OH_AVScreenCapture实例操作期间视频缓存区可用时，将调用函数指针。

从API 12开始，推荐使用接口[OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)替代。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
|  bool isReady | 视频缓存区是否可用。 |

### OH_AVScreenCapture_OnStateChange()

```
typedef void (*OH_AVScreenCapture_OnStateChange)(struct OH_AVScreenCapture *capture,OH_AVScreenCaptureStateCode stateCode, void *userData)
```

**描述**

当OH_AVScreenCapture实例操作期间发生状态变更时，将调用函数指针。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AVScreenCaptureStateCode](#oh_avscreencapturestatecode) stateCode | 指定状态码。 |
|  void *userData | 指向应用设置该回调处理方法时提供的自定义数据的指针。 |

### OH_AVScreenCapture_OnError()

```
typedef void (*OH_AVScreenCapture_OnError)(OH_AVScreenCapture *capture, int32_t errorCode, void *userData)
```

**描述**

当OH_AVScreenCapture实例操作期间发生错误时，将调用函数指针。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
|  int32_t errorCode | 指定错误码。 |
|  void *userData | 指向应用设置该回调处理方法时提供的自定义数据的指针。 |

### OH_AVScreenCapture_OnBufferAvailable()

```
typedef void (*OH_AVScreenCapture_OnBufferAvailable)(OH_AVScreenCapture *capture, OH_AVBuffer *buffer,OH_AVScreenCaptureBufferType bufferType, int64_t timestamp, void *userData)
```

**描述**

当OH_AVScreenCapture实例操作期间音频或视频缓存区可用时，将调用该函数指针。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
|  [OH_AVBuffer](../apis-avcodec-kit/_core.md#oh_avbuffer) *buffer | 指向OH_AVBuffer缓存区实例的指针，该回调方法执行结束返回后，数据缓存区不再有效。 |
| [OH_AVScreenCaptureBufferType](#oh_avscreencapturebuffertype) bufferType | 可用缓存区的数据类型。 |
|  int64_t timestamp | 时间戳，单位纳秒。 |
|  void *userData | 指向应用设置该回调处理方法时提供的自定义数据的指针。 |

### OH_AVScreenCapture_OnDisplaySelected()

```
typedef void (*OH_AVScreenCapture_OnDisplaySelected)(OH_AVScreenCapture *capture, uint64_t displayId, void *userData)
```

**描述**

当录屏事件开始时，将调用函数指针。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture](capi-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
|  uint64_t displayId | 录屏屏幕的Id。 |
|  void *userData | 指向应用设置该回调处理方法时提供的自定义数据的指针。 |

### OH_AVScreenCapture_OnCaptureContentChanged()

```
typedef void (*OH_AVScreenCapture_OnCaptureContentChanged)(OH_AVScreenCapture* capture,OH_AVScreenCaptureContentChangedEvent event, OH_Rect* area, void *userData)
```

**描述**

当OH_AVScreenCapture实例操作期间录屏内容变化时，将调用函数指针。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture](capi-oh-avscreencapture.md)* capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AVScreenCaptureContentChangedEvent](#oh_avscreencapturecontentchangedevent) event | 录屏内容变更事件。 |
|  [OH_Rect](capi-oh-rect.md)* area | 录屏内容可见时，对应位置信息。 |
|  void *userData | 指向应用设置该回调处理方法时提供的自定义数据的指针。 |


