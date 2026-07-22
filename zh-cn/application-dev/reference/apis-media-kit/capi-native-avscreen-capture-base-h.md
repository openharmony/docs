# native_avscreen_capture_base.h
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

## 概述

声明用于运行屏幕录制相关的结构体、字符常量、枚举、变量和函数。屏幕录制通过配置参数设置录制模式与音视频信息，通过回调函数获取录制数据、状态变更和隐私保护事件通知。支持多种录制模式（主屏幕、指定屏幕、指定窗口）、音频源类型（麦克风、内录、指定应用音频）配置及隐私保护、内容过滤等功能，适用于需要捕获屏幕画面和音频数据的应用场景。详细设计逻辑请参见[AVScreenCapture](capi-avscreencapture.md)。

**引用文件：** <multimedia/player_framework/native_avscreen_capture_base.h>

**库：** libnative_avscreen_capture.so

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**相关模块：** [AVScreenCapture](capi-avscreencapture.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AudioCaptureInfo](capi-avscreencapture-oh-audiocaptureinfo.md) | OH_AudioCaptureInfo | 音频采样信息。<br> 当audioSampleRate和audioChannels同时为0时，忽略该类型音频相关参数，不录制该类型音频数据。<br> 同时采集音频麦克风和音频内录数据时，两路音频的audioSampleRate和audioChannels采样参数需要相同。 |
| [OH_AudioEncInfo](capi-avscreencapture-oh-audioencinfo.md) | OH_AudioEncInfo | 音频编码信息。 |
| [OH_AudioInfo](capi-avscreencapture-oh-audioinfo.md) | OH_AudioInfo | 音频信息。<br> 同时采集音频麦克风和音频内录数据时，两路音频的audioSampleRate和audioChannels采样参数需要相同，若不相同将导致录制失败。<br> 当某类型音频的audioSampleRate和audioChannels同时为0时，将忽略该类型音频相关参数，不录制该类型音频数据。 |
| [OH_VideoCaptureInfo](capi-avscreencapture-oh-videocaptureinfo.md) | OH_VideoCaptureInfo | 视频录制信息。当videoFrameWidth和videoFrameHeight同时为0时，忽略视频相关参数不录制屏幕数据。 |
| [OH_VideoEncInfo](capi-avscreencapture-oh-videoencinfo.md) | OH_VideoEncInfo | 视频编码参数。 |
| [OH_VideoInfo](capi-avscreencapture-oh-videoinfo.md) | OH_VideoInfo | 视频信息。<br> 当videoFrameWidth和videoFrameHeight同时为0时，将忽略视频相关参数，不录制屏幕数据。 |
| [OH_RecorderInfo](capi-avscreencapture-oh-recorderinfo.md) | OH_RecorderInfo | 录制文件信息。 |
| [OH_AVScreenCaptureConfig](capi-avscreencapture-oh-avscreencaptureconfig.md) | OH_AVScreenCaptureConfig | 屏幕录制配置参数。<br> 注意：当某类型音频的audioSampleRate和audioChannels同时为0时，将忽略该类型音频参数；同时采集麦克风和内录音频时，两路音频采样参数需相同；当videoFrameWidth和videoFrameHeight同时为0时，将忽略视频参数。 |
| [OH_PrivacyProtectInfo](capi-avscreencapture-oh-privacyprotectinfo.md) | OH_PrivacyProtectInfo | 隐私保护信息结构体。 |
| [OH_AVScreenCaptureCallback](capi-avscreencapture-oh-avscreencapturecallback.md) | OH_AVScreenCaptureCallback | OH_AVScreenCapture中所有异步回调函数指针的集合。应用将该结构体的实例注册到OH_AVScreenCapture实例中，并处理回调上报的信息，以保证OH_AVScreenCapture的正常运行。<br> 从API版本12开始，推荐使用接口[OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror)、[OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)替代。 |
| [OH_Rect](capi-avscreencapture-oh-rect.md) | OH_Rect | 定义录屏界面的宽高以及画面信息。 |
| [OH_AudioBuffer](capi-avscreencapture-oh-audiobuffer.md) | OH_AudioBuffer | 定义了音频缓冲区数据及其大小、类型、时间戳等配置信息。 |
| [OH_AVScreenCaptureHighlightConfig](capi-avscreencapture-oh-avscreencapturehighlightconfig.md) | OH_AVScreenCaptureHighlightConfig | 表示高亮边框的样式，包括高亮边框的模式、边框宽度和边框颜色。 |
| [OH_MultiDisplayCapability](capi-avscreencapture-oh-multidisplaycapability.md) | OH_MultiDisplayCapability | 多屏幕录制能力信息。多屏场景下，用户选择的多屏幕是否支持联合录制，以及联合录制的屏幕宽度和高度。 |
| [OH_NativeBuffer](capi-avscreencapture-avscreencapture-oh-nativebuffer.md) | OH_NativeBuffer | 提供录屏的视频原始码流类。 |
| [OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) | OH_AVScreenCapture | 通过OH_AVScreenCapture可以获取视频与音频的原始码流。 |
| [OH_AVScreenCapture_ContentFilter](capi-avscreencapture-oh-avscreencapture-contentfilter.md) | OH_AVScreenCapture_ContentFilter | 通过OH_AVScreenCapture_ContentFilter过滤音视频内容。 |
| [OH_AVScreenCapture_CaptureStrategy](capi-avscreencapture-oh-avscreencapture-capturestrategy.md) | OH_AVScreenCapture_CaptureStrategy | 通过OH_AVScreenCapture_CaptureStrategy设置录屏策略。 |
| [OH_AVScreenCapture_UserSelectionInfo](capi-avscreencapture-oh-avscreencapture-userselectioninfo.md) | OH_AVScreenCapture_UserSelectionInfo | 通过OH_AVScreenCapture_UserSelectionInfo获取用户在授权界面（选择界面）选择的参数。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_CaptureMode](#oh_capturemode) | OH_CaptureMode | 枚举，表示屏幕录制的不同模式。 |
| [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) | OH_AudioCaptureSourceType | 枚举，表示屏幕录制时的音频源类型。 |
| [OH_AudioCodecFormat](#oh_audiocodecformat) | OH_AudioCodecFormat | 枚举，表示音频编码格式。 |
| [OH_VideoCodecFormat](#oh_videocodecformat) | OH_VideoCodecFormat | 枚举，表示视频编码格式。 |
| [OH_DataType](#oh_datatype) | OH_DataType | 枚举，表示屏幕录制流的数据格式。 |
| [OH_VideoSourceType](#oh_videosourcetype) | OH_VideoSourceType | 枚举，表示视频源格式。此枚举类型当前仅支持RGBA格式。 |
| [OH_ContainerFormatType](#oh_containerformattype) | OH_ContainerFormatType | 枚举，表示屏幕录制生成的文件类型。 |
| [OH_AVScreenCaptureStateCode](#oh_avscreencapturestatecode) | OH_AVScreenCaptureStateCode | 枚举，表示状态码。 |
| [OH_AVScreenCaptureBufferType](#oh_avscreencapturebuffertype) | OH_AVScreenCaptureBufferType | 枚举，表示buffer类型。 |
| [OH_AVScreenCaptureFilterableAudioContent](#oh_avscreencapturefilterableaudiocontent) | OH_AVScreenCaptureFilterableAudioContent | 枚举，表示可过滤的音频类型。 |
| [OH_AVScreenCaptureContentChangedEvent](#oh_avscreencapturecontentchangedevent) | OH_AVScreenCaptureContentChangedEvent | 枚举，表示录屏内容变更事件。 |
| [OH_AVScreenCapture_FillMode](#oh_avscreencapture_fillmode) | OH_AVScreenCapture_FillMode | 枚举，图像填充模式。 |
| [OH_ScreenCaptureHighlightMode](#oh_screencapturehighlightmode) | OH_ScreenCaptureHighlightMode | 枚举，表示屏幕录制高亮边框的模式。 |
| [OH_CapturePickerMode](#oh_capturepickermode) | OH_CapturePickerMode | 枚举，表示Picker显示模式。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_AVScreenCaptureOnError)(OH_AVScreenCapture *capture, int32_t errorCode)](#oh_avscreencaptureonerror) | OH_AVScreenCaptureOnError | 当OH_AVScreenCapture实例运行出错时，系统将调用该函数指针通知应用程序。<br> 从API版本12开始，推荐使用接口[OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror)替代。 |
| [typedef void (\*OH_AVScreenCaptureOnAudioBufferAvailable)(OH_AVScreenCapture *capture, bool isReady, OH_AudioCaptureSourceType type)](#oh_avscreencaptureonaudiobufferavailable) | OH_AVScreenCaptureOnAudioBufferAvailable | 当OH_AVScreenCapture实例操作期间音频缓冲区可用时，系统将调用该函数指针通知应用程序。<br> 从API版本12开始，推荐使用接口[OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)替代。OH_AVScreenCapture_OnBufferAvailable将音频和视频缓冲区回调统一为一个接口，通过bufferType参数区分缓冲区数据类型，同时增加了timestamp和userData参数支持，开发者无需分别注册音频和视频回调。 |
| [typedef void (\*OH_AVScreenCaptureOnVideoBufferAvailable)(OH_AVScreenCapture *capture, bool isReady)](#oh_avscreencaptureonvideobufferavailable) | OH_AVScreenCaptureOnVideoBufferAvailable | 当OH_AVScreenCapture实例操作期间视频缓冲区可用时，系统将调用该函数指针通知应用程序。<br> 从API版本12开始，推荐使用接口[OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)替代。 |
| [typedef void (\*OH_AVScreenCapture_OnStateChange)(struct OH_AVScreenCapture *capture, OH_AVScreenCaptureStateCode stateCode, void *userData)](#oh_avscreencapture_onstatechange) | OH_AVScreenCapture_OnStateChange | 当OH_AVScreenCapture实例操作期间发生状态变更时，将调用函数指针。 |
| [typedef void (\*OH_AVScreenCapture_OnError)(OH_AVScreenCapture *capture, int32_t errorCode, void *userData)](#oh_avscreencapture_onerror) | OH_AVScreenCapture_OnError | 当OH_AVScreenCapture实例操作期间发生错误时，系统将调用该函数指针通知应用程序。使用前需将该回调注册到OH_AVScreenCapture实例中。应在录屏开始前注册该错误回调以便及时处理错误。 |
| [typedef void (\*OH_AVScreenCapture_OnBufferAvailable)(OH_AVScreenCapture *capture, OH_AVBuffer *buffer, OH_AVScreenCaptureBufferType bufferType, int64_t timestamp, void *userData)](#oh_avscreencapture_onbufferavailable) | OH_AVScreenCapture_OnBufferAvailable | 当OH_AVScreenCapture实例操作期间音频或视频缓冲区可用时，系统将调用该函数指针通知应用程序。使用前需将该回调注册到OH_AVScreenCapture实例中。 |
| [typedef void (\*OH_AVScreenCapture_OnDisplaySelected)(OH_AVScreenCapture *capture, uint64_t displayId, void *userData)](#oh_avscreencapture_ondisplayselected) | OH_AVScreenCapture_OnDisplaySelected | 当录屏事件开始时，将调用函数指针。 |
| [typedef void (\*OH_AVScreenCapture_OnCaptureContentChanged)(OH_AVScreenCapture* capture, OH_AVScreenCaptureContentChangedEvent event, OH_Rect* area, void *userData)](#oh_avscreencapture_oncapturecontentchanged) | OH_AVScreenCapture_OnCaptureContentChanged | 当OH_AVScreenCapture实例操作期间录屏内容变化时，将调用函数指针。 |
| [typedef void (\*OH_AVScreenCapture_OnUserSelected)(OH_AVScreenCapture* capture, OH_AVScreenCapture_UserSelectionInfo* selections, void *userData)](#oh_avscreencapture_onuserselected) | OH_AVScreenCapture_OnUserSelected | 当用户在授权界面（选择界面）选择参数时，通过该回调函数将用户选择的参数返回给应用程序。 |
| [typedef void (\*OH_AVScreenCapture_OnPrivacyProtect)(OH_AVScreenCapture* capture, OH_PrivacyProtectInfo* privacyProtect, void *userData)](#oh_avscreencapture_onprivacyprotect) | OH_AVScreenCapture_OnPrivacyProtect | 当OH_AVScreenCapture实例在运行过程中发生隐私保护事件时，函数指针将被调用。 |

### 变量

| 名称 | 描述 |
| -- | -- |
| const char * OH_SCREEN_CAPTURE_CONTENT_RECT | 获取录屏图像帧中有效内容区域信息的key。<br>通过此key获取到的返回值是一个int32_t数组，单位为像素（px）。数组长度为4。数组元素定义为[top, left, width, height]，其中top表示矩形窗口左上角纵坐标，left表示矩形窗口左上角横坐标，width表示矩形窗口的宽度，height表示矩形窗口的高度。数组元素可以从[OH_AVFormat_GetIntBuffer](../apis-avcodec-kit/capi-native-avformat-h.md#oh_avformat_getintbuffer)中获取。<br>**起始版本：** 26.0.0 |

## 枚举类型说明

### OH_CaptureMode

```c
enum OH_CaptureMode
```

**描述**

枚举，表示屏幕录制的不同模式。

根据录制需求选择合适的模式：录制主屏幕适用于全屏录制场景；录制指定屏幕适用于多屏环境下选择特定屏幕的场景；录制指定窗口适用于仅录制单个应用窗口的场景。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OH_CAPTURE_HOME_SCREEN = 0 | 录制主屏幕。 |
| OH_CAPTURE_SPECIFIED_SCREEN = 1 | 录制指定屏幕。使用此模式需在OH_AVScreenCaptureConfig中指定displayId。 |
| OH_CAPTURE_SPECIFIED_WINDOW = 2 | 录制指定窗口。使用此模式需在OH_AVScreenCaptureConfig中指定windowId。 |
| OH_CAPTURE_INVAILD = -1 | 无效模式。 |

### OH_AudioCaptureSourceType

```c
enum OH_AudioCaptureSourceType
```

**描述**

枚举，表示屏幕录制时的音频源类型。

适用于不同的音频录制需求：OH_MIC适用于需要录制外部声音（如解说、旁白）的场景；OH_ALL_PLAYBACK适用于需要录制系统播放的所有内部音频流（如系统音效、应用音频）的场景；OH_APP_PLAYBACK适用于需要仅录制指定应用播放音频的场景。

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

```c
enum OH_AudioCodecFormat
```

**描述**

枚举，表示音频编码格式。

OH_AUDIO_DEFAULT为默认编码，适用于大多数音视频录制场景；OH_AAC_LC为AAC_LC编码，适用于需要较好音质和较小文件大小的通用音视频应用场景。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OH_AUDIO_DEFAULT = 0 | 默认音频编码，默认为AAC_LC。 |
| OH_AAC_LC = 3 | AAC_LC音频编码。 |
| OH_AUDIO_CODEC_FORMAT_BUTT | 无效格式。 |

### OH_VideoCodecFormat

```c
enum OH_VideoCodecFormat
```

**描述**

枚举，表示视频编码格式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OH_VIDEO_DEFAULT = 0 | 默认视频编码，默认为H.264。 |
| OH_H264 = 2 | H.264。适用于大多数录制场景，兼容性最好，是最广泛支持的视频编码格式。 |
| OH_H265 = 4 | H.265/HEVC。适用于对压缩效率要求高的场景，相同画质下文件更小，但兼容性低于H.264。 |
| OH_MPEG4 = 6 | MPEG4。适用于对兼容性要求不高的场景，压缩效率低于H.264/H.265。 |
| OH_VP8 = 8 | VP8。适用于Web场景的开源编码格式，兼容性有限。 |
| OH_VP9 = 10 | VP9。适用于Web高清场景的开源编码格式，压缩效率优于VP8，兼容性有限。 |
| OH_VIDEO_CODEC_FORMAT_BUTT | 无效格式。 |

### OH_DataType

```c
enum OH_DataType
```

**描述**

枚举，表示屏幕录制流的数据格式。

根据使用需求选择合适的数据格式：原始流格式适用于需要实时处理音视频数据的场景（如实时预览、流式传输）；保存文件格式适用于直接录制为文件的场景。

当前仅支持原始流格式和保存文件格式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OH_ORIGINAL_STREAM = 0 | 原始流格式，如YUV/RGBA/PCM等。 |
| OH_ENCODED_STREAM = 1 | 编码流格式，如H.264/AAC等。当前版本暂不支持。 |
| OH_CAPTURE_FILE = 2 | 保存文件格式，支持mp4。 |
| OH_INVAILD = -1 | 无效格式。 |

### OH_VideoSourceType

```c
enum OH_VideoSourceType
```

**描述**

枚举，表示视频源格式。此枚举类型当前仅支持RGBA格式。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| OH_VIDEO_SOURCE_SURFACE_YUV = 0 | YUV格式。当前版本暂不支持。 |
| OH_VIDEO_SOURCE_SURFACE_ES | raw格式。当前版本暂不支持。 |
| OH_VIDEO_SOURCE_SURFACE_RGBA | RGBA格式。 |
| OH_VIDEO_SOURCE_BUTT | 无效格式。 |

### OH_ContainerFormatType

```c
enum OH_ContainerFormatType
```

**描述**

枚举，表示屏幕录制生成的文件类型。

适用于不同的文件输出需求：CFT_MPEG_4A为音频格式m4a，适用于仅需要录制音频的场景；CFT_MPEG_4为视频格式mp4，适用于需要同时录制音视频的场景。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| CFT_MPEG_4A = 0 | 音频格式 m4a。 |
| CFT_MPEG_4 = 1 | 视频格式 mp4。 |

### OH_AVScreenCaptureStateCode

```c
enum OH_AVScreenCaptureStateCode
```

**描述**

枚举，表示状态码。

状态码反映了录屏的生命周期变化，包括开始、暂停、恢复、停止、中断及隐私场景切换等状态，状态变更通过OH_AVScreenCapture_OnStateChange回调通知应用。

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
| OH_SCREEN_CAPTURE_STATE_PAUSED_BY_USER = 11 | 录屏已由用户暂停。<br>**起始版本：** 26.0.0 |
| OH_SCREEN_CAPTURE_STATE_RESUMED_BY_USER = 12 | 录屏已由用户恢复。<br>**起始版本：** 26.0.0 |
| OH_SCREEN_CAPTURE_STATE_PAUSED_BY_APP = 13 | 录屏已由应用程序暂停。<br>**起始版本：** 26.0.0 |
| OH_SCREEN_CAPTURE_STATE_RESUMED_BY_APP = 14 | 录屏已由应用程序恢复。<br>**起始版本：** 26.0.0 |

### OH_AVScreenCaptureBufferType

```c
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

```c
enum OH_AVScreenCaptureFilterableAudioContent
```

**描述**

枚举，表示可过滤的音频类型。

在录屏场景中，可通过过滤特定音频类型来控制录制内容：过滤通知音适用于避免系统通知声音干扰录屏内容的场景；过滤应用自身声音适用于仅录制应用内音频而排除其他声音的场景。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| OH_SCREEN_CAPTURE_NOTIFICATION_AUDIO = 0 | 通知音。 |
| OH_SCREEN_CAPTURE_CURRENT_APP_AUDIO = 1 | 应用自身声音。 |

### OH_AVScreenCaptureContentChangedEvent

```c
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

### OH_AVScreenCapture_FillMode

```c
enum OH_AVScreenCapture_FillMode
```

**描述**

枚举，图像填充模式。

OH_SCREENCAPTURE_FILLMODE_ASPECT_SCALE_FIT适用于需要保持图像原始宽高比、避免变形的场景；<br> OH_SCREENCAPTURE_FILLMODE_SCALE_TO_FILL适用于需要完全填充目标区域、可接受图像变形的场景。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| OH_SCREENCAPTURE_FILLMODE_ASPECT_SCALE_FIT = 0 | 保持图像原始宽高比匹配目标图像大小，若比例不一致可能存在黑边。 |
| OH_SCREENCAPTURE_FILLMODE_SCALE_TO_FILL = 1 | 图像拉伸匹配目标图像大小，若比例不一致可能会导致图像变形。 |

### OH_ScreenCaptureHighlightMode

```c
enum OH_ScreenCaptureHighlightMode
```

**描述**

枚举，表示屏幕录制高亮边框的模式。

**起始版本：** 22

| 枚举项 | 描述 |
| -- | -- |
| OH_HIGHLIGHT_MODE_CLOSED = 0 | 默认模式，用方形全包边框高亮显示录制区域。 |
| OH_HIGHLIGHT_MODE_CORNER_WRAP = 1 | 用四角包裹边框高亮显示录制区域。 |

### OH_CapturePickerMode

```c
enum OH_CapturePickerMode
```

**描述**

枚举，表示Picker显示模式。

根据应用需求选择合适的Picker模式：仅显示窗口模式适用于只允许用户选择窗口进行录制的场景；仅显示屏幕模式适用于只允许用户选择整个屏幕的场景；同时显示屏幕和窗口模式为默认模式，适用于需要灵活选择录制目标的场景；仅显示应用模式适用于只允许录制单个应用的场景。

**起始版本：** 22

| 枚举项 | 描述 |
| -- | -- |
| OH_CAPTURE_PICKER_MODE_WINDOW_ONLY = 0 | 仅显示窗口模式。 |
| OH_CAPTURE_PICKER_MODE_SCREEN_ONLY = 1 | 仅显示屏幕模式。 |
| OH_CAPTURE_PICKER_MODE_SCREEN_AND_WINDOW = 2 | 显示屏幕和窗口模式（默认模式）。 |
| OH_CAPTURE_PICKER_MODE_APP_ONLY = 3 | 仅显示应用模式。<br>**起始版本：** 26.0.0 |
| OH_CAPTURE_PICKER_MODE_WINDOW_AND_APP = 4 | 同时显示窗口和应用模式。<br>**起始版本：** 26.0.0 |
| OH_CAPTURE_PICKER_MODE_SCREEN_AND_APP = 5 | 同时显示屏幕和应用模式。<br>**起始版本：** 26.0.0 |
| OH_CAPTURE_PICKER_MODE_SCREEN_WINDOW_AND_APP = 6 | 同时显示屏幕、窗口和应用模式。<br>**起始版本：** 26.0.0 |


## 函数说明

### OH_AVScreenCaptureOnError()

```c
typedef void (*OH_AVScreenCaptureOnError)(OH_AVScreenCapture *capture, int32_t errorCode)
```

**描述**

当OH_AVScreenCapture实例运行出错时，系统将调用该函数指针通知应用程序。<br> 从API版本12开始，推荐使用接口[OH_AVScreenCapture_OnError](#oh_avscreencapture_onerror)替代。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
|  int32_t errorCode | 指定错误码，具体错误码值及含义请参考[OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode)说明。 |

### OH_AVScreenCaptureOnAudioBufferAvailable()

```c
typedef void (*OH_AVScreenCaptureOnAudioBufferAvailable)(OH_AVScreenCapture *capture, bool isReady, OH_AudioCaptureSourceType type)
```

**描述**

当OH_AVScreenCapture实例操作期间音频缓冲区可用时，系统将调用该函数指针通知应用程序。<br> 从API版本12开始，推荐使用接口[OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)替代。OH_AVScreenCapture_OnBufferAvailable将音频和视频缓冲区回调统一为一个接口，通过bufferType参数区分缓冲区数据类型，同时增加了timestamp和userData参数支持，开发者无需分别注册音频和视频回调。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
|  bool isReady | 音频缓冲区是否可用。true表示音频缓冲区可用，false表示音频缓冲区不可用。 |
| [OH_AudioCaptureSourceType](#oh_audiocapturesourcetype) type | 音频源类型，用于标识音频数据的来源。OH_MIC表示麦克风音频数据；OH_ALL_PLAYBACK表示系统内录音频数据；OH_APP_PLAYBACK表示指定应用播放的音频数据。开发者应根据type值对音频数据进行相应处理。 |

### OH_AVScreenCaptureOnVideoBufferAvailable()

```c
typedef void (*OH_AVScreenCaptureOnVideoBufferAvailable)(OH_AVScreenCapture *capture, bool isReady)
```

**描述**

当OH_AVScreenCapture实例操作期间视频缓冲区可用时，系统将调用该函数指针通知应用程序。<br> 从API版本12开始，推荐使用接口[OH_AVScreenCapture_OnBufferAvailable](#oh_avscreencapture_onbufferavailable)替代。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
|  bool isReady | 视频缓冲区是否可用。true表示视频缓冲区可用，false表示视频缓冲区不可用。 |

### OH_AVScreenCapture_OnStateChange()

```c
typedef void (*OH_AVScreenCapture_OnStateChange)(struct OH_AVScreenCapture *capture, OH_AVScreenCaptureStateCode stateCode, void *userData)
```

**描述**

当OH_AVScreenCapture实例操作期间发生状态变更时，将调用函数指针。<br> 需通过OH_AVScreenCapture相关接口设置该回调后方可生效，未设置时回调不会被调用。

此回调通过stateCode参数返回状态码。状态变更包括录屏开始、暂停、恢复、停止、中断及隐私场景切换等，具体状态码见[OH_AVScreenCaptureStateCode](#oh_avscreencapturestatecode)。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AVScreenCaptureStateCode](#oh_avscreencapturestatecode) stateCode | 指定状态码，用于标识录屏状态的变化。常见状态包括：OH_SCREEN_CAPTURE_STATE_STARTED（录屏已开始）、OH_SCREEN_CAPTURE_STATE_CANCELED（用户取消录屏）、OH_SCREEN_CAPTURE_STATE_STOPPED_BY_USER（用户停止录屏）等。开发者应根据不同状态执行相应操作。 |
|  void *userData | 指向应用设置该回调处理方法时提供的自定义数据的指针。 |

### OH_AVScreenCapture_OnError()

```c
typedef void (*OH_AVScreenCapture_OnError)(OH_AVScreenCapture *capture, int32_t errorCode, void *userData)
```

**描述**

当OH_AVScreenCapture实例操作期间发生错误时，系统将调用该函数指针通知应用程序。使用前需将该回调注册到OH_AVScreenCapture实例中。应在录屏开始前注册该错误回调以便及时处理错误。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
|  int32_t errorCode | 指定错误码，具体错误码值及含义请参考[OH_AVSCREEN_CAPTURE_ErrCode](capi-native-avscreen-capture-errors-h.md#oh_avscreen_capture_errcode)说明。 |
|  void *userData | 指向应用设置该回调处理方法时提供的自定义数据的指针。 |

### OH_AVScreenCapture_OnBufferAvailable()

```c
typedef void (*OH_AVScreenCapture_OnBufferAvailable)(OH_AVScreenCapture *capture, OH_AVBuffer *buffer, OH_AVScreenCaptureBufferType bufferType, int64_t timestamp, void *userData)
```

**描述**

当OH_AVScreenCapture实例操作期间音频或视频缓冲区可用时，系统将调用该函数指针通知应用程序。使用前需将该回调注册到OH_AVScreenCapture实例中。

该回调方法执行结束返回后，数据缓冲区不再有效，应用需要在回调内及时处理数据。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AVBuffer](../apis-avcodec-kit/capi-core-oh-avbuffer.md) *buffer | 指向OH_AVBuffer缓冲区实例的指针，该回调方法执行结束返回后，数据缓冲区不再有效。 |
| [OH_AVScreenCaptureBufferType](#oh_avscreencapturebuffertype) bufferType | 可用缓冲区的数据类型，指示当前可用缓冲区的数据类型。<br>OH_SCREEN_CAPTURE_BUFFERTYPE_VIDEO表示视频数据缓冲区可用；OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_INNER表示内录音频缓冲区可用；OH_SCREEN_CAPTURE_BUFFERTYPE_AUDIO_MIC表示麦克风音频缓冲区可用。<br>开发者应根据bufferType类型对buffer数据进行相应处理。 |
|  int64_t timestamp | 时间戳，单位：纳秒（ns）。 |
|  void *userData | 指向应用设置该回调处理方法时提供的自定义数据的指针。 |

### OH_AVScreenCapture_OnDisplaySelected()

```c
typedef void (*OH_AVScreenCapture_OnDisplaySelected)(OH_AVScreenCapture *capture, uint64_t displayId, void *userData)
```

**描述**

当录屏事件开始时，将调用函数指针。使用前需将该回调注册到OH_AVScreenCapture实例中。应在录屏开始前完成注册。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md) *capture | 指向OH_AVScreenCapture实例的指针。 |
|  uint64_t displayId | 录屏屏幕的ID。用于标识用户选择的具体屏幕。 |
|  void *userData | 指向应用设置该回调处理方法时提供的自定义数据的指针。 |

### OH_AVScreenCapture_OnCaptureContentChanged()

```c
typedef void (*OH_AVScreenCapture_OnCaptureContentChanged)(OH_AVScreenCapture* capture, OH_AVScreenCaptureContentChangedEvent event, OH_Rect* area, void *userData)
```

**描述**

当OH_AVScreenCapture实例操作期间录屏内容变化时，将调用函数指针。使用前需将该回调注册到OH_AVScreenCapture实例中。

此回调通过event参数返回内容变更事件，具体事件值参见[OH_AVScreenCaptureContentChangedEvent](#oh_avscreencapturecontentchangedevent)枚举。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md)* capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AVScreenCaptureContentChangedEvent](#oh_avscreencapturecontentchangedevent) event | 录屏内容变更事件，指示录屏内容的状态变化。<br>OH_SCREEN_CAPTURE_CONTENT_HIDE表示录屏内容变为隐藏（如进入隐私界面）；OH_SCREEN_CAPTURE_CONTENT_VISIBLE表示录屏内容从隐藏变为可见；OH_SCREEN_CAPTURE_CONTENT_UNAVAILABLE表示录屏内容不可用（如窗口关闭）。<br>开发者应根据不同事件类型调整录屏状态。 |
| [OH_Rect](capi-avscreencapture-oh-rect.md)* area | 录屏内容可见时，对应位置信息；录屏内容隐藏或不可见时，该参数无效。 |
|  void *userData | 指向应用设置该回调处理方法时提供的自定义数据的指针。 |

### OH_AVScreenCapture_OnUserSelected()

```c
typedef void (*OH_AVScreenCapture_OnUserSelected)(OH_AVScreenCapture* capture, OH_AVScreenCapture_UserSelectionInfo* selections, void *userData)
```

**描述**

当用户在授权界面（选择界面）选择参数时，系统通过该回调函数将用户选择的参数返回给应用程序。

需要通过相关注册方法设置到OH_AVScreenCapture实例中。应在启动授权流程前完成注册以便接收用户选择结果。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md)* capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_AVScreenCapture_UserSelectionInfo](capi-avscreencapture-oh-avscreencapture-userselectioninfo.md)* selections | 用户在授权界面选择的录制参数信息。 |
|  void *userData | 指向应用设置该回调处理方法时提供的自定义数据的指针。 |

### OH_AVScreenCapture_OnPrivacyProtect()

```c
typedef void (*OH_AVScreenCapture_OnPrivacyProtect)(OH_AVScreenCapture* capture, OH_PrivacyProtectInfo* privacyProtect, void *userData)
```
 
**描述**

当[OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md)实例在运行过程中发生隐私保护事件时，函数指针将调用。
  
**起始版本：** 24

**参数：**
  
| 参数项 | 描述 |
| -- | -- |
| [OH_AVScreenCapture](capi-avscreencapture-oh-avscreencapture.md)* capture | 指向OH_AVScreenCapture实例的指针。 |
| [OH_PrivacyProtectInfo](capi-avscreencapture-oh-privacyprotectinfo.md)* privacyProtect | 隐私保护信息指针。指向包含隐私保护事件详细信息的结构体，用于处理录屏过程中的隐私保护回调事件。 |
| void *userData | 指向应用设置该回调处理方法时提供的自定义数据的指针。 |
