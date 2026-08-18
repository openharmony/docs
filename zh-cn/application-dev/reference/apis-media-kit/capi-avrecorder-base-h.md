# avrecorder_base.h
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_dyOv3Sds-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @zzs911-->

## 概述

定义了媒体AVRecorder的结构体、枚举和回调函数。

**引用文件：** &lt;multimedia/player_framework/avrecorder_base.h&gt;

**库：** libavrecorder.so

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

**相关模块：** [AVRecorder](capi-avrecorder.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AVRecorder_Profile](capi-avrecorder-oh-avrecorder-profile.md) | OH_AVRecorder_Profile | 定义音视频录制的详细参数。通过配置音频/视频编码格式、比特率、采样率、帧率、分辨率、容器格式、HDR录制、是否启用时域可分层视频编码功能等参数，可以灵活控制录制质量和录制文件大小，适用于需要自定义录制质量、选择录制内容类型（仅音频/仅视频/音视频同时录制）、启用HDR录制或时域可分层视频编码功能的场景。<br>通过参数设置可以选择仅录制音频或视频，或者同时录制音视频：<br>1. 当 audioBitrate 或 audioChannels 为 0 时，不录制音频。<br>2. 当 videoFrameWidth 或 videoFrameHeight 为 0 时，不录制视频。<br>各参数的范围请参见[AVRecorderProfile](arkts-apis-media-i.md#avrecorderprofile9)。 |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) | OH_AVRecorder | 音视频录制的结构体类型，用于表示AVRecorder实例，支持音视频数据的采集与录制，提供录制流程控制及回调事件监听等能力。适用于需要将音视频内容录制保存为文件的场景，如视频会议录制、屏幕录制应用、安防监控录像等。 |
| [OH_AVRecorder_Location](capi-avrecorder-oh-avrecorder-location.md) | OH_AVRecorder_Location | 提供媒体资源的地理位置信息，支持在音视频录制过程中标注纬度和经度。该结构体通过AVRecorder的[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)接口将经纬度信息写入录制文件的元数据中，开发者需在录制前设置该结构体的latitude和longitude参数，录制过程中地理位置信息将自动嵌入到生成的媒体文件中。适用于需要在录制结果中嵌入地理位置的场景，如在视频拍摄时标记拍摄地点、运动记录应用中标记轨迹位置、旅行日记应用中记录行程坐标等，便于后续按位置检索和分类管理媒体资源。 |
| [OH_AVRecorder_MetadataTemplate](capi-avrecorder-oh-avrecorder-metadatatemplate.md) | OH_AVRecorder_MetadataTemplate | 定义音视频录制过程中元数据的基本模板，通过键值对（key-value）形式组织元数据，适用于需要在录制输出中附加自定义元数据（如标题、作者、描述等）的场景，便于对录制文件进行分类、检索和管理。开发者可通过AVRecorder的[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)接口将该结构体中的元数据设置到录制输出文件中。 |
| [OH_AVRecorder_Metadata](capi-avrecorder-oh-avrecorder-metadata.md) | OH_AVRecorder_Metadata | 定义录制的元数据结构，用于描述媒体资源的体裁分类、视频旋转角度、地理位置及自定义参数等元数据信息，适用于录制过程中需要携带或读取媒体元数据的场景。 |
| [OH_AVRecorder_Config](capi-avrecorder-oh-avrecorder-config.md) | OH_AVRecorder_Config | 提供媒体AVRecorder的配置定义，用于设置音视频录制时的音频源类型、视频源类型、编码配置、输出文件URL、文件生成模式、元数据及最大录制时长参数，适用于需要自定义录制配置的场景。 |
| [OH_AVRecorder_Range](capi-avrecorder-oh-avrecorder-range.md) | OH_AVRecorder_Range | 表示AVRecorder相关参数（如比特率、帧率等）的取值范围，用于限定录制参数的可配置范围。开发者可通过[OH_AVRecorder_GetAvailableEncoder](capi-avrecorder-h.md#oh_avrecorder_getavailableencoder)接口获取编码器相关参数取值范围，并在min和max所界定的范围内设置参数值，以确保配置有效。 |
| [OH_AVRecorder_EncoderInfo](capi-avrecorder-oh-avrecorder-encoderinfo.md) | OH_AVRecorder_EncoderInfo | 提供AVRecorder编码器能力信息，包括编码器的MIME类型、比特率范围、帧率范围等参数，适用于在录制前查询和选择合适的音频或视频编码器配置的场景，帮助开发者根据编码器能力参数选择最优编码配置。开发者可通过[OH_AVRecorder_GetAvailableEncoder](capi-avrecorder-h.md#oh_avrecorder_getavailableencoder)接口获取该结构体对象。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AVRecorder_AudioSourceType](#oh_avrecorder_audiosourcetype) | OH_AVRecorder_AudioSourceType | AVRecorder的音频源类型。 |
| [OH_AVRecorder_VideoSourceType](#oh_avrecorder_videosourcetype) | OH_AVRecorder_VideoSourceType | AVRecorder的视频源类型。 |
| [OH_AVRecorder_CodecMimeType](#oh_avrecorder_codecmimetype) | OH_AVRecorder_CodecMimeType | 编码器MIME类型，用于指定录制时音视频数据的编码格式。编码器类型需与容器格式类型匹配使用，不匹配时将导致录制失败，具体匹配关系请参见对应编码器类型的枚举项说明。 |
| [OH_AVRecorder_ContainerFormatType](#oh_avrecorder_containerformattype) | OH_AVRecorder_ContainerFormatType | 容器格式类型（CFT），用于指定录制文件的封装格式。容器格式需与编码器MIME类型兼容，不兼容时将导致录制失败，各容器格式支持的编码器类型请参见对应容器格式类型的枚举项说明。 |
| [OH_AVRecorder_State](#oh_avrecorder_state) | OH_AVRecorder_State | AVRecorder状态，用于表示录制器在生命周期中的不同阶段，不同状态下可执行的操作不同。 |
| [OH_AVRecorder_StateChangeReason](#oh_avrecorder_statechangereason) | OH_AVRecorder_StateChangeReason | AVRecorder状态变化的原因，用于区分状态变化是由用户操作还是后台事件触发，便于应用根据不同原因执行相应的处理逻辑。 |
| [OH_AVRecorder_FileGenerationMode](#oh_avrecorder_filegenerationmode) | OH_AVRecorder_FileGenerationMode | 录制文件的生成模式，用于指定媒体文件的创建方式，适用于需要选择由应用自行管理文件还是由系统自动管理文件的录制场景。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (*OH_AVRecorder_OnStateChange)(OH_AVRecorder *recorder, OH_AVRecorder_State state, OH_AVRecorder_StateChangeReason reason, void *userData)](#oh_avrecorder_onstatechange) | OH_AVRecorder_OnStateChange | 当录制状态发生变化时调用。 |
| [typedef void (*OH_AVRecorder_OnError)(OH_AVRecorder *recorder, int32_t errorCode, const char *errorMsg, void *userData)](#oh_avrecorder_onerror) | OH_AVRecorder_OnError | 当录制过程中发生错误时调用。 |
| [typedef void (*OH_AVRecorder_OnUri)(OH_AVRecorder *recorder, OH_MediaAsset *asset, void *userData)](#oh_avrecorder_onuri) | OH_AVRecorder_OnUri | 当录制文件的生成模式为[OH_AVRecorder_FileGenerationMode](#oh_avrecorder_filegenerationmode).AVRECORDER_AUTO_CREATE_CAMERA_SCENE时调用，用于通知应用获取录制生成的媒体资源。 |

## 枚举类型说明

### OH_AVRecorder_AudioSourceType

```c
enum OH_AVRecorder_AudioSourceType
```

**描述**

AVRecorder的音频源类型。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| AVRECORDER_DEFAULT = 0 | 默认音频源类型。适用于无需指定特定音频源类型的通用录制场景。 |
| AVRECORDER_MIC = 1 | 麦克风音频源类型。 |
| AVRECORDER_VOICE_RECOGNITION = 2 | 语音识别场景的音频源。 |
| AVRECORDER_VOICE_COMMUNICATION = 7 | 语音通话场景的音频源。 |
| AVRECORDER_VOICE_MESSAGE = 10 | 语音消息的音频源。 |
| AVRECORDER_CAMCORDER = 13 | 相机录像的音频源。 |

### OH_AVRecorder_VideoSourceType

```c
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

```c
enum OH_AVRecorder_CodecMimeType
```

**描述**

编码器MIME类型，用于指定录制时音视频数据的编码格式。编码器类型需与容器格式类型匹配使用，不匹配时将导致录制失败，具体匹配关系请参见对应编码器类型的枚举项说明。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| AVRECORDER_VIDEO_AVC = 2 | H.264视频编码器MIME类型。需与mp4容器格式匹配使用。 |
| AVRECORDER_AUDIO_AAC = 3 | AAC音频编码器MIME类型。需与aac、mp4或m4a容器格式匹配使用。 |
| AVRECORDER_AUDIO_MP3 = 4 | MP3音频编码器MIME类型。需与mp3容器格式匹配使用。 |
| AVRECORDER_AUDIO_G711MU = 5 | G711-mulaw音频编码器MIME类型。需与wav容器格式匹配使用。 |
| AVRECORDER_VIDEO_MPEG4 = 6 | MPEG4视频编码器MIME类型。需与mp4容器格式匹配使用。 |
| AVRECORDER_VIDEO_HEVC = 8 | H.265视频编码器MIME类型。需与mp4容器格式匹配使用。 |
| AVRECORDER_AUDIO_AMR_NB = 9 | AMR_NB音频编码器MIME类型。需与amr容器格式匹配使用。 |
| AVRECORDER_AUDIO_AMR_WB = 10 | AMR_WB音频编码器MIME类型。需与amr容器格式匹配使用。 |

### OH_AVRecorder_ContainerFormatType

```c
enum OH_AVRecorder_ContainerFormatType
```

**描述**

容器格式类型（CFT），用于指定录制文件的封装格式。容器格式需与编码器MIME类型兼容，不兼容时将导致录制失败，各容器格式支持的编码器类型请参见对应容器格式类型的枚举项说明。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| AVRECORDER_CFT_MPEG_4 = 2 | 视频容器格式类型mp4。支持AAC音频编码器及MPEG4、H.264或H.265视频编码器。 |
| AVRECORDER_CFT_MPEG_4A = 6 | 音频容器格式类型m4a。支持AAC音频编码器。 |
| AVRECORDER_CFT_AMR = 8 | 音频容器格式类型amr。支持AMR_NB、AMR_WB音频编码器。 |
| AVRECORDER_CFT_MP3 = 9 | 音频容器格式类型mp3。支持MP3音频编码器。 |
| AVRECORDER_CFT_WAV = 10 | 音频容器格式类型wav。支持G711-mulaw音频编码器。 |
| AVRECORDER_CFT_AAC = 11 | 音频容器格式类型aac（带ADTS头）。支持AAC音频编码器。<br>**起始版本：** 20 |

### OH_AVRecorder_State

```c
enum OH_AVRecorder_State
```

**描述**

AVRecorder状态，用于表示录制器在生命周期中的不同阶段，不同状态下可执行的操作不同。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| AVRECORDER_IDLE = 0 | 空闲状态，为AVRecorder实例创建后的默认初始状态。此时可以调用[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)接口设置录制参数，进入AVRECORDER_PREPARED状态。 |
| AVRECORDER_PREPARED = 1 | 准备状态。参数设置完成，此时可以调用[OH_AVRecorder_Start](capi-avrecorder-h.md#oh_avrecorder_start)接口开始录制，进入AVRECORDER_STARTED状态。 |
| AVRECORDER_STARTED = 2 | 启动状态。正在录制，此时可以调用[OH_AVRecorder_Pause](capi-avrecorder-h.md#oh_avrecorder_pause)接口暂停录制，进入AVRECORDER_PAUSED状态。<br>也可以调用[OH_AVRecorder_Stop](capi-avrecorder-h.md#oh_avrecorder_stop)接口结束录制，进入AVRECORDER_STOPPED状态。 |
| AVRECORDER_PAUSED = 3 | 暂停状态。此时可以调用[OH_AVRecorder_Resume](capi-avrecorder-h.md#oh_avrecorder_resume)接口继续录制，进入AVRECORDER_STARTED状态。<br>也可以调用[OH_AVRecorder_Stop](capi-avrecorder-h.md#oh_avrecorder_stop)接口结束录制，进入AVRECORDER_STOPPED状态。 |
| AVRECORDER_STOPPED = 4 | 停止状态。此时可以调用[OH_AVRecorder_Prepare](capi-avrecorder-h.md#oh_avrecorder_prepare)接口设置录制参数，重新进入AVRECORDER_PREPARED状态。 |
| AVRECORDER_RELEASED = 5 | 释放状态。录制资源释放，此时不能再进行任何操作。在任何其他状态下，均可以通过调用[OH_AVRecorder_Release](capi-avrecorder-h.md#oh_avrecorder_release)接口进入AVRECORDER_RELEASED状态。 |
| AVRECORDER_ERROR = 6 | 错误状态。当AVRecorder实例发生不可逆错误，会转换至该状态。<br>在AVRECORDER_ERROR状态时，不能再进行录制相关操作，用户需要调用[OH_AVRecorder_Reset](capi-avrecorder-h.md#oh_avrecorder_reset)接口重置AVRecorder实例，或者调用[OH_AVRecorder_Release](capi-avrecorder-h.md#oh_avrecorder_release)接口释放资源。 |

### OH_AVRecorder_StateChangeReason

```c
enum OH_AVRecorder_StateChangeReason
```

**描述**

AVRecorder状态变化的原因，用于区分状态变化是由用户操作还是后台事件触发，便于应用根据不同原因执行相应的处理逻辑。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| AVRECORDER_USER = 0 | 用户操作导致的状态变化。 |
| AVRECORDER_BACKGROUND = 1 | 后台操作导致的状态变化。 |

### OH_AVRecorder_FileGenerationMode

```c
enum OH_AVRecorder_FileGenerationMode
```

**描述**

录制文件的生成模式，用于指定媒体文件的创建方式，适用于需要选择由应用自行管理文件还是由系统自动管理文件的录制场景。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| AVRECORDER_APP_CREATE = 0 | 由应用自行在沙箱中创建媒体文件，此模式下不会触发[OH_AVRecorder_OnUri](#oh_avrecorder_onuri)回调。 |
| AVRECORDER_AUTO_CREATE_CAMERA_SCENE = 1 | 由系统创建媒体文件，此模式下会触发[OH_AVRecorder_OnUri](#oh_avrecorder_onuri)回调，应用可通过回调获取录制生成的媒体资源对象。 |


## 函数说明

### OH_AVRecorder_OnStateChange()

```c
typedef void (*OH_AVRecorder_OnStateChange)(OH_AVRecorder *recorder, OH_AVRecorder_State state, OH_AVRecorder_StateChangeReason reason, void *userData)
```

**描述**

当录制状态发生变化时调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | OH_AVRecorder实例的指针。 |
| [OH_AVRecorder_State](#oh_avrecorder_state) state | 表示录制状态。 |
| [OH_AVRecorder_StateChangeReason](#oh_avrecorder_statechangereason) reason | 录制状态变化的原因。 |
|  void *userData | 用户注册回调时传入的自定义数据指针，在回调触发时由系统回传给调用方。 |

### OH_AVRecorder_OnError()

```c
typedef void (*OH_AVRecorder_OnError)(OH_AVRecorder *recorder, int32_t errorCode, const char *errorMsg, void *userData)
```

**描述**

当录制过程中发生错误时调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | OH_AVRecorder实例的指针。 |
|  int32_t errorCode | 错误码，详细说明请参见[OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode)。 |
|  const char *errorMsg | 描述错误详情的字符串。 |
| void *userData | 用户注册回调时传入的自定义数据指针，在回调触发时由系统回传给调用方。 |

### OH_AVRecorder_OnUri()

```c
typedef void (*OH_AVRecorder_OnUri)(OH_AVRecorder *recorder, OH_MediaAsset *asset, void *userData)
```

**描述**

当录制文件的生成模式为[OH_AVRecorder_FileGenerationMode](#oh_avrecorder_filegenerationmode).AVRECORDER_AUTO_CREATE_CAMERA_SCENE时调用，用于通知应用获取录制生成的媒体资源。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVRecorder](capi-avrecorder-oh-avrecorder.md) *recorder | OH_AVRecorder实例的指针。 |
| [OH_MediaAsset](../apis-media-library-kit/capi-mediaassetmanager-oh-mediaasset.md) *asset | OH_MediaAsset实例的指针，用于返回系统自动创建的媒体资源对象，应用可通过该对象访问录制生成的媒体文件。 |
|  void *userData | 用户注册回调时传入的自定义数据指针，在回调触发时由系统回传给调用方。 |


