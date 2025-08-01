# avrecorder_base.h
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @shiwei75-->
<!--SE: @HmQQQ-->
<!--TSE: @xdlinc-->

## 概述

定义了媒体AVRecorder的结构体和枚举。

**引用文件：** avrecorder_base.h

**库：** libavrecorder.so

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**相关模块：** [AVRecorder](capi-avrecorder.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AVRecorder_Profile](capi-avrecorder-oh-avrecorder-profile.md) | OH_AVRecorder_Profile | 定义音视频录制的详细参数。 |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) | OH_AVRecorder | 初始化AVRecorder。 |
| [OH_AVRecorder_Location](capi-avrecorder-oh-avrecorder-location.md) | OH_AVRecorder_Location | 提供媒体资源的地理位置信息。 |
| [OH_AVRecorder_MetadataTemplate](capi-avrecorder-oh-avrecorder-metadatatemplate.md) | OH_AVRecorder_MetadataTemplate | 定义元数据的基本模板。 |
| [OH_AVRecorder_Metadata](capi-avrecorder-oh-avrecorder-metadata.md) | OH_AVRecorder_Metadata | 元数据信息数据结构。 |
| [OH_AVRecorder_Config](capi-avrecorder-oh-avrecorder-config.md) | OH_AVRecorder_Config | 提供媒体AVRecorder的配置定义。 |
| [OH_AVRecorder_Range](capi-avrecorder-oh-avrecorder-range.md) | OH_AVRecorder_Range | 表示类型的范围。 |
| [OH_AVRecorder_EncoderInfo](capi-avrecorder-oh-avrecorder-encoderinfo.md) | OH_AVRecorder_EncoderInfo | 提供编码器信息。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AVRecorder_AudioSourceType](#oh_avrecorder_audiosourcetype) | OH_AVRecorder_AudioSourceType | AVRecorder的音频源类型。 |
| [OH_AVRecorder_VideoSourceType](#oh_avrecorder_videosourcetype) | OH_AVRecorder_VideoSourceType | AVRecorder的视频源类型。 |
| [OH_AVRecorder_CodecMimeType](#oh_avrecorder_codecmimetype) | OH_AVRecorder_CodecMimeType | 编码器MIME类型。 |
| [OH_AVRecorder_ContainerFormatType](#oh_avrecorder_containerformattype) | OH_AVRecorder_ContainerFormatType | 容器格式类型（容器格式类型的缩写是 CFT）。 |
| [OH_AVRecorder_State](#oh_avrecorder_state) | OH_AVRecorder_State | AVRecorder状态。 |
| [OH_AVRecorder_StateChangeReason](#oh_avrecorder_statechangereason) | OH_AVRecorder_StateChangeReason | AVRecorder状态变化的原因。 |
| [OH_AVRecorder_FileGenerationMode](#oh_avrecorder_filegenerationmode) | OH_AVRecorder_FileGenerationMode | 创建录制文件的模式。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_AVRecorder_OnStateChange)(OH_AVRecorder *recorder,OH_AVRecorder_State state, OH_AVRecorder_StateChangeReason reason, void *userData)](#oh_avrecorder_onstatechange) | OH_AVRecorder_OnStateChange | 当录制状态发生变化时调用。 |
| [typedef void (\*OH_AVRecorder_OnError)(OH_AVRecorder *recorder, int32_t errorCode, const char *errorMsg,void *userData)](#oh_avrecorder_onerror) | OH_AVRecorder_OnError | 当录制过程中发生错误时调用。 |
| [typedef void (\*OH_AVRecorder_OnUri)(OH_AVRecorder *recorder, OH_MediaAsset *asset, void *userData)](#oh_avrecorder_onuri) | OH_AVRecorder_OnUri | 当录制在[OH_AVRecorder_FileGenerationMode](#oh_avrecorder_filegenerationmode).AVRECORDER_AUTO_CREATE_CAMERA_SCENE模式时调用。 |

## 枚举类型说明

### OH_AVRecorder_AudioSourceType

```
enum OH_AVRecorder_AudioSourceType
```

**描述**

AVRecorder的音频源类型。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| AVRECORDER_DEFAULT = 0 | 默认音频源类型。 |
| AVRECORDER_MIC = 1 | 麦克风音频源类型。 |
| AVRECORDER_VOICE_RECOGNITION = 2 | 语音识别场景的音频源。 |
| AVRECORDER_VOICE_COMMUNICATION = 7 | 语音通话场景的音频源。 |
| AVRECORDER_VOICE_MESSAGE = 10 | 短语音消息的音频源。 |
| AVRECORDER_CAMCORDER = 13 | 相机录像的音频源。 |

### OH_AVRecorder_VideoSourceType

```
enum OH_AVRecorder_VideoSourceType
```

**描述**

AVRecorder的视频源类型。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| AVRECORDER_SURFACE_YUV = 0 | 原始数据Surface。 |
| AVRECORDER_SURFACE_ES = 1 | ES数据Surface。 |

### OH_AVRecorder_CodecMimeType

```
enum OH_AVRecorder_CodecMimeType
```

**描述**

编码器MIME类型。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| AVRECORDER_VIDEO_AVC = 2 | H.264 编码器MIME类型。 |
| AVRECORDER_AUDIO_AAC = 3 | AAC 编码器MIME类型。 |
| AVRECORDER_AUDIO_MP3 = 4 | mp3 编码器MIME类型。 |
| AVRECORDER_AUDIO_G711MU = 5 | G711-mulaw 编码器MIME类型。 |
| AVRECORDER_VIDEO_MPEG4 = 6 | MPEG4 编码器MIME类型。 |
| AVRECORDER_VIDEO_HEVC = 8 | H.265 编码器MIME类型。 |
| AVRECORDER_AUDIO_AMR_NB = 9 | AMR_NB 编解码器MIME类型。 |
| AVRECORDER_AUDIO_AMR_WB = 10 | AMR_WB 编解码器MIME类型。 |

### OH_AVRecorder_ContainerFormatType

```
enum OH_AVRecorder_ContainerFormatType
```

**描述**

容器格式类型（容器格式类型的缩写是 CFT）。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| AVRECORDER_CFT_MPEG_4 = 2 | 视频容器格式类型mp4。 |
| AVRECORDER_CFT_MPEG_4A = 6 | 音频容器格式类型m4a。 |
| AVRECORDER_CFT_AMR = 8 | 音频容器格式类型amr。 |
| AVRECORDER_CFT_MP3 = 9 | 音频容器格式类型mp3。 |
| AVRECORDER_CFT_WAV = 10 | 音频容器格式类型wav。 |
| AVRECORDER_CFT_AAC = 11 | 音频容器格式类型aac（带ADTS头）。<br>**起始版本：** 20 |

### OH_AVRecorder_State

```
enum OH_AVRecorder_State
```

**描述**

AVRecorder状态。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| AVRECORDER_IDLE = 0 | 空闲状态。此时可以调用[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)方法设置录制参数，进入AVRECORDER_PREPARED状态。 |
| AVRECORDER_PREPARED = 1 | 准备状态。参数设置完成，此时可以调用[OH_AVRecorder_Start](capi-avrecorder-h.md#oh_avrecorder_start)方法开始录制，进入AVRECORDER_STARTED状态。 |
| AVRECORDER_STARTED = 2 | 启动状态。正在录制，此时可以调用[OH_AVRecorder_Pause](capi-avrecorder-h.md#oh_avrecorder_pause)方法暂停录制，进入AVRECORDER_PAUSED状态。<br>也可以调用[OH_AVRecorder_Stop](capi-avrecorder-h.md#oh_avrecorder_stop)方法结束录制，进入AVRECORDER_STOPPED状态。 |
| AVRECORDER_PAUSED = 3 | 暂停状态。此时可以调用[OH_AVRecorder_Resume](capi-avrecorder-h.md#oh_avrecorder_resume)方法继续录制，进入AVRECORDER_STARTED状态。<br>也可以调用[OH_AVRecorder_Stop](capi-avrecorder-h.md#oh_avrecorder_stop)方法结束录制，进入AVRECORDER_STOPPED状态。 |
| AVRECORDER_STOPPED = 4 | 停止状态。此时可以调用[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)方法设置录制参数，重新进入AVRECORDER_PREPARED状态。 |
| AVRECORDER_RELEASED = 5 | 释放状态。录制资源释放，此时不能再进行任何操作。在任何其他状态下，均可以通过调用[OH_AVRecorder_Release](capi-avrecorder-h.md#oh_avrecorder_release)方法进入AVRECORDER_RELEASED状态。 |
| AVRECORDER_ERROR = 6 | 错误状态。当AVRecorder实例发生不可逆错误，会转换至当前状态。<br>切换至AVRECORDER_ERROR状态时会伴随[OH_AVRecorder_OnError](#oh_avrecorder_onerror)事件，该事件会上报详细错误原因。<br>在AVRECORDER_ERROR状态时，用户需要调用[OH_AVRecorder_Reset](capi-avrecorder-h.md#oh_avrecorder_reset)方法重置AVRecorder实例，或者调用[OH_AVRecorder_Release](capi-avrecorder-h.md#oh_avrecorder_release)方法释放资源。 |

### OH_AVRecorder_StateChangeReason

```
enum OH_AVRecorder_StateChangeReason
```

**描述**

AVRecorder状态变化的原因。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| AVRECORDER_USER = 0 | 用户操作导致的状态变化。 |
| AVRECORDER_BACKGROUND = 1 | 后台操作导致的状态变化。 |

### OH_AVRecorder_FileGenerationMode

```
enum OH_AVRecorder_FileGenerationMode
```

**描述**

创建录制文件的模式。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| AVRECORDER_APP_CREATE = 0 | 由应用自行在沙箱中创建媒体文件。 |
| AVRECORDER_AUTO_CREATE_CAMERA_SCENE = 1 | 由系统创建媒体文件，当前仅在相机录制场景下生效。 |


## 函数说明

### OH_AVRecorder_OnStateChange()

```
typedef void (*OH_AVRecorder_OnStateChange)(OH_AVRecorder *recorder,OH_AVRecorder_State state, OH_AVRecorder_StateChangeReason reason, void *userData)
```

**描述**

当录制状态发生变化时调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | OH_AVRecorder实例的指针。 |
| [OH_AVRecorder_State](#oh_avrecorder_state) state | 表示录制器状态。 |
| [OH_AVRecorder_StateChangeReason](#oh_avrecorder_statechangereason) reason | 录制器状态变化的原因。 |
|  void *userData | 用户特定数据的指针。 |

### OH_AVRecorder_OnError()

```
typedef void (*OH_AVRecorder_OnError)(OH_AVRecorder *recorder, int32_t errorCode, const char *errorMsg,void *userData)
```

**描述**

当录制过程中发生错误时调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | OH_AVRecorder实例的指针。 |
|  int32_t errorCode | 错误码，详细说明请参见[AVErrorCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)。 |
|  const char *errorMsg | 错误信息。 |
| void *userData | 用户特定数据的指针。 |

### OH_AVRecorder_OnUri()

```
typedef void (*OH_AVRecorder_OnUri)(OH_AVRecorder *recorder, OH_MediaAsset *asset, void *userData)
```

**描述**

当录制在[OH_AVRecorder_FileGenerationMode](#oh_avrecorder_filegenerationmode).AVRECORDER_AUTO_CREATE_CAMERA_SCENE模式下时调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | OH_AVRecorder实例的指针。 |
| [OH_MediaAsset](../apis-media-library-kit/capi-mediaassetmanager-oh-mediaasset.md) *asset | OH_MediaAsset实例的指针。 |
|  void *userData | 用户特定数据的指针。 |


