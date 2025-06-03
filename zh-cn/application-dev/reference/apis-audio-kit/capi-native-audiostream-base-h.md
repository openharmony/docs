# native_audiostream_base.h

## 概述

声明OHAudio基础的数据结构。

**库：** libohaudio.so

**引用文件：** <ohaudio/native_audiostream_base.h>

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

**相关模块：** [OHAudio](capi-ohaudio.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AudioStreamInfo](capi-oh-audiostreaminfo.md) | OH_AudioStreamInfo | 定义音频流信息，用于描述基本音频格式。 |
| [OH_AudioRenderer_Callbacks_Struct](capi-oh-audiorenderer-callbacks-struct.md) | OH_AudioRenderer_Callbacks | 声明输出音频流的回调函数指针。 |
| [OH_AudioCapturer_Callbacks_Struct](capi-oh-audiocapturer-callbacks-struct.md) | OH_AudioCapturer_Callbacks | 声明输入音频流的回调函数指针。 |
| [OH_AudioStreamBuilderStruct](capi-oh-audiostreambuilderstruct.md) | OH_AudioStreamBuilder | 声明音频流的构造器。构造器实例通常被用来设置音频流属性和创建音频流。 |
| [OH_AudioRendererStruct](capi-oh-audiorendererstruct.md) | OH_AudioRenderer | 声明输出音频流。输出音频流的实例被用来播放音频数据。 |
| [OH_AudioCapturerStruct](capi-oh-audiocapturerstruct.md) | OH_AudioCapturer | 声明输入音频流。输入音频流的实例被用来获取音频数据。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AudioStream_Result](#oh_audiostream_result) | OH_AudioStream_Result | 音频错误码。 |
| [OH_AudioStream_Type](#oh_audiostream_type) | OH_AudioStream_Type | 音频流类型。 |
| [OH_AudioStream_SampleFormat](#oh_audiostream_sampleformat) | OH_AudioStream_SampleFormat | 定义音频流采样格式。 |
| [OH_AudioStream_EncodingType](#oh_audiostream_encodingtype) | OH_AudioStream_EncodingType | 定义音频流编码类型。 |
| [OH_AudioStream_Usage](#oh_audiostream_usage) | OH_AudioStream_Usage | 定义音频流使用场景。<br>通常用来描述音频输出流的使用场景。 |
| [OH_AudioStream_LatencyMode](#oh_audiostream_latencymode) | OH_AudioStream_LatencyMode | 定义音频时延模式。 |
| [OH_AudioStream_DirectPlaybackMode](#oh_audiostream_directplaybackmode) | OH_AudioStream_DirectPlaybackMode | 定义音频流direct通路播放模式。 |
| [OH_AudioStream_VolumeMode](#oh_audiostream_volumemode) | OH_AudioStream_VolumeMode | 定义音频流音量模式。 |
| [OH_AudioStream_State](#oh_audiostream_state) | OH_AudioStream_State | 定义音频流的状态。 |
| [OH_AudioStream_SourceType](#oh_audiostream_sourcetype) | OH_AudioStream_SourceType | 定义音频流使用场景。<br>通常用来描述音频输入流的使用场景。 |
| [OH_AudioStream_Event](#oh_audiostream_event) | OH_AudioStream_Event | 定义音频事件。 |
| [OH_AudioInterrupt_ForceType](#oh_audiointerrupt_forcetype) | OH_AudioInterrupt_ForceType | 定义音频中断类型。<br>当用户监听到音频中断时，将获取此信息。<br>此类型表示本次音频打断的操作是否已由系统强制执行，具体操作信息（如音频暂停、停止等）可通过[OH_AudioInterrupt_Hint](capi-native-audiostream-base-h.md#oh_audiointerrupt_hint)获取。 |
| [OH_AudioInterrupt_Hint](#oh_audiointerrupt_hint) | OH_AudioInterrupt_Hint | 定义音频中断提示类型。<br>当用户监听到音频中断时，将获取此信息。<br>此类型表示根据焦点策略，当前需要对音频流的具体操作（如暂停、调整音量等）。<br>可以结合[OH_AudioInterrupt_ForceType](capi-native-audiostream-base-h.md#oh_audiointerrupt_forcetype)信息，判断该操作是否已由系统强制执行。 |
| [OH_AudioInterrupt_Mode](#oh_audiointerrupt_mode) | OH_AudioInterrupt_Mode | 定义音频中断模式。 |
| [OH_AudioStream_AudioEffectMode](#oh_audiostream_audioeffectmode) | OH_AudioStream_AudioEffectMode | 定义音效模式。 |
| [OH_AudioStream_DeviceChangeReason](#oh_audiostream_devicechangereason) | OH_AudioStream_DeviceChangeReason | 流设备变更原因。 |
| [OH_AudioStream_PrivacyType](#oh_audiostream_privacytype) | OH_AudioStream_PrivacyType | 用于标识对应播放音频流是否支持被其他应用录制。 |
| [OH_AudioData_Callback_Result](#oh_audiodata_callback_result) | OH_AudioData_Callback_Result | 定义音频数据回调结果。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_AudioRenderer_OutputDeviceChangeCallback)(OH_AudioRenderer* renderer, void* userData,OH_AudioStream_DeviceChangeReason reason)](#oh_audiorenderer_outputdevicechangecallback) | OH_AudioRenderer_OutputDeviceChangeCallback | 输出音频流设备变更的回调函数。 |
| [typedef void (\*OH_AudioRenderer_OnMarkReachedCallback)(OH_AudioRenderer* renderer, uint32_t samplePos, void* userData)](#oh_audiorenderer_onmarkreachedcallback) | OH_AudioRenderer_OnMarkReachedCallback | 到达标记位置时回调。 |
| [typedef int32_t (\*OH_AudioRenderer_WriteDataWithMetadataCallback)(OH_AudioRenderer* renderer,void* userData, void* audioData, int32_t audioDataSize, void* metadata, int32_t metadataSize)](#oh_audiorenderer_writedatawithmetadatacallback) | OH_AudioRenderer_WriteDataWithMetadataCallback | 该函数指针将指向用于同时写入音频数据和元数据的回调函数。 |
| [typedef OH_AudioData_Callback_Result (\*OH_AudioRenderer_OnWriteDataCallback)(OH_AudioRenderer* renderer, void* userData,void* audioData, int32_t audioDataSize)](#oh_audiorenderer_onwritedatacallback) | OH_AudioRenderer_OnWriteDataCallback | 该函数指针将指向用于写入音频数据的回调函数。<br>回调函数仅用来写入音频数据，请勿在回调函数中调用AudioRenderer相关接口。<br>该函数的返回结果表示填充到缓冲区的数据是否有效。如果结果无效，用户填写的数据将不被播放。回调函数结束后，音频服务会把audioData指针数据放入队列里等待播放，因此请勿在回调外再次更改audioData指向的数据, 且务必保证往audioData填满audioDataSize长度的待播放数据, 否则会导致音频服务播放杂音。 |

## 枚举类型说明

### OH_AudioStream_Result

```
enum OH_AudioStream_Result
```

**描述**

音频错误码。

**起始版本：** 10

| 枚举项 | 描述        |
| -- |--------------------------------------------|
| AUDIOSTREAM_SUCCESS = 0 | 操作成功。          |
| AUDIOSTREAM_ERROR_INVALID_PARAM = 1 | 入参错误。          |
| AUDIOSTREAM_ERROR_ILLEGAL_STATE = 2 | 非法状态。          |
| AUDIOSTREAM_ERROR_SYSTEM = 3 | 系统通用错误。        |
| AUDIOSTREAM_ERROR_UNSUPPORTED_FORMAT = 4 | 不支持的音频格式，如不支持的编码类型、采样格式等。<br/>**起始版本：** 19 |

### OH_AudioStream_Type

```
enum OH_AudioStream_Type
```

**描述**

音频流类型。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| AUDIOSTREAM_TYPE_RENDERER = 1 | 该类型代表音频流是输出流。 |
| AUDIOSTREAM_TYPE_CAPTURER = 2 | 该类型代表音频流是输入流。 |

### OH_AudioStream_SampleFormat

```
enum OH_AudioStream_SampleFormat
```

**描述**

定义音频流采样格式。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| AUDIOSTREAM_SAMPLE_U8 = 0 | Unsigned 8位。 |
| AUDIOSTREAM_SAMPLE_S16LE = 1 | Short 16位小端。 |
| AUDIOSTREAM_SAMPLE_S24LE = 2 | Short 24位小端。 |
| AUDIOSTREAM_SAMPLE_S32LE = 3 | Short 32位小端。 |
| AUDIOSTREAM_SAMPLE_F32LE = 4 | Float 32位小端。<br/>**起始版本：** 17 |

### OH_AudioStream_EncodingType

```
enum OH_AudioStream_EncodingType
```

**描述**

定义音频流编码类型。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| AUDIOSTREAM_ENCODING_TYPE_RAW = 0 | PCM编码。        |
| AUDIOSTREAM_ENCODING_TYPE_AUDIOVIVID = 1 | AudioVivid编码。<br/>**起始版本：** 12 |
| AUDIOSTREAM_ENCODING_TYPE_E_AC3 = 2 | E_AC3编码。<br/>**起始版本：** 19      |

### OH_AudioStream_Usage

```
enum OH_AudioStream_Usage
```

**描述**

定义音频流使用场景。

通常用来描述音频输出流的使用场景。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| AUDIOSTREAM_USAGE_UNKNOWN = 0 | 未知类型。 |
| AUDIOSTREAM_USAGE_MUSIC = 1 | 音乐。 |
| AUDIOSTREAM_USAGE_COMMUNICATION = 2 | VoIP语音通话。 |
| AUDIOSTREAM_USAGE_VOICE_ASSISTANT = 3 | 语音播报。 |
| AUDIOSTREAM_USAGE_ALARM = 4 | 闹钟。 |
| AUDIOSTREAM_USAGE_VOICE_MESSAGE = 5 | 语音消息。 |
| AUDIOSTREAM_USAGE_RINGTONE = 6 | 铃声。 |
| AUDIOSTREAM_USAGE_NOTIFICATION = 7 | 通知。 |
| AUDIOSTREAM_USAGE_ACCESSIBILITY = 8 | 无障碍。 |
| AUDIOSTREAM_USAGE_MOVIE = 10 | 电影或视频。 |
| AUDIOSTREAM_USAGE_GAME = 11 | 游戏。 |
| AUDIOSTREAM_USAGE_AUDIOBOOK = 12 | 有声读物（包括听书、相声、评书）、听新闻、播客等。 |
| AUDIOSTREAM_USAGE_NAVIGATION = 13 | 导航。 |
| AUDIOSTREAM_USAGE_VIDEO_COMMUNICATION = 17 | VoIP视频通话。<br/>**起始版本：** 12 |

### OH_AudioStream_LatencyMode

```
enum OH_AudioStream_LatencyMode
```

**描述**

定义音频时延模式。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| AUDIOSTREAM_LATENCY_MODE_NORMAL = 0 | 该模式代表一个普通时延的音频流。 |
| AUDIOSTREAM_LATENCY_MODE_FAST = 1 | 该模式代表一个低时延的音频流。 |

### OH_AudioStream_DirectPlaybackMode

```
enum OH_AudioStream_DirectPlaybackMode
```

**描述**

定义音频流direct通路播放模式。

**起始版本：** 19

| 枚举项 | 描述 |
| -- | -- |
| AUDIOSTREAM_DIRECT_PLAYBACK_NOT_SUPPORTED = 0 | 该模式代表不支持direct通路播放。      |
| AUDIOSTREAM_DIRECT_PLAYBACK_BITSTREAM_SUPPORTED = 1 | 该模式代表支持不解码的direct通路播放。   |
| AUDIOSTREAM_DIRECT_PLAYBACK_PCM_SUPPORTED = 2 | 该模式代表支持pcm编码的direct通路播放。 |

### OH_AudioStream_VolumeMode

```
enum OH_AudioStream_VolumeMode
```

**描述**

定义音频流音量模式。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| AUDIOSTREAM_VOLUMEMODE_SYSTEM_GLOBAL = 0 | 系统级音量（默认模式）。|
| AUDIOSTREAM_VOLUMEMODE_APP_INDIVIDUAL = 1 | 应用级音量。<br>设置为该模式后可以通过提供的接口设置、查询应用音量。 |

### OH_AudioStream_State

```
enum OH_AudioStream_State
```

**描述**

定义音频流的状态。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| AUDIOSTREAM_STATE_INVALID = -1 | 不合法的状态。 |
| AUDIOSTREAM_STATE_NEW = 0 | 新创建时的状态。      |
| AUDIOSTREAM_STATE_PREPARED = 1 | 准备状态。         |
| AUDIOSTREAM_STATE_RUNNING = 2 | 工作状态。         |
| AUDIOSTREAM_STATE_STOPPED = 3 | 停止状态。         |
| AUDIOSTREAM_STATE_RELEASED = 4 | 释放状态。         |
| AUDIOSTREAM_STATE_PAUSED = 5 | 暂停状态。         |

### OH_AudioStream_SourceType

```
enum OH_AudioStream_SourceType
```

**描述**

定义音频流使用场景。

通常用来描述音频输入流的使用场景。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| AUDIOSTREAM_SOURCE_TYPE_INVALID = -1 | 不合法状态。    |
| AUDIOSTREAM_SOURCE_TYPE_MIC = 0      | 录音。       |
| AUDIOSTREAM_SOURCE_TYPE_VOICE_RECOGNITION = 1   | 语音识别。     |
| AUDIOSTREAM_SOURCE_TYPE_PLAYBACK_CAPTURE = 2    | 播放录音。     |
| AUDIOSTREAM_SOURCE_TYPE_VOICE_COMMUNICATION = 7 | 通话。       |
| AUDIOSTREAM_SOURCE_TYPE_VOICE_MESSAGE = 10      | 语音消息。<br/>**起始版本：** 12     |
| AUDIOSTREAM_SOURCE_TYPE_CAMCORDER = 13          | 录像。<br/>**起始版本：** 13       |
| AUDIOSTREAM_SOURCE_TYPE_UNPROCESSED = 14        | 麦克风纯净录音（系统不做任何算法处理）。<br/>**起始版本：** 14 |
| AUDIOSTREAM_SOURCE_TYPE_LIVE = 17        | 直播。<br/>**起始版本：** 20 |

### OH_AudioStream_Event

```
enum OH_AudioStream_Event
```

**描述**

定义音频事件。

**起始版本：** 10

**废弃版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| AUDIOSTREAM_EVENT_ROUTING_CHANGED = 0 | 音频的路由已更改。<br/>**起始版本：** 10<br/>**废弃版本：** 18<br/>**替代接口：** [OH_AudioRenderer_OutputDeviceChangeCallback](#oh_audiorenderer_outputdevicechangecallback) |

### OH_AudioInterrupt_ForceType

```
enum OH_AudioInterrupt_ForceType
```

**描述**

定义音频中断类型。

当用户监听到音频中断时，将获取此信息。

此类型表示本次音频打断的操作是否已由系统强制执行，具体操作信息（如音频暂停、停止等）可通过[OH_AudioInterrupt_Hint](capi-native-audiostream-base-h.md#oh_audiointerrupt_hint)获取。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| AUDIOSTREAM_INTERRUPT_FORCE = 0 | 强制打断类型，即具体操作已由系统强制执行。       |
| AUDIOSTREAM_INTERRUPT_SHAR = 1 | 共享打断类型，即系统不执行具体操作，通过[OH_AudioInterrupt_Hint](#oh_audiointerrupt_hint)提示并建议应用操作，应用可自行决策下一步处理方式。 |

### OH_AudioInterrupt_Hint

```
enum OH_AudioInterrupt_Hint
```

**描述**

定义音频中断提示类型。

当用户监听到音频中断时，将获取此信息。

此类型表示根据焦点策略，当前需要对音频流的具体操作（如暂停、调整音量等）。可以结合[OH_AudioInterrupt_ForceType](capi-native-audiostream-base-h.md#oh_audiointerrupt_forcetype)信息，判断该操作是否已由系统强制执行。

**起始版本：** 10

| 枚举项 | 描述 |
| -- | -- |
| AUDIOSTREAM_INTERRUPT_HINT_NONE = 0 | 不提示。 |
| AUDIOSTREAM_INTERRUPT_HINT_RESUME = 1 | 提示音频恢复，应用可主动触发开始渲染或开始采集的相关操作。<br>此操作无法由系统强制执行，其对应的[OH_AudioInterrupt_ForceType](#oh_audiointerrupt_forcetype)一定为AUDIOSTREAM_INTERRUPT_SHARE类型。 |
| AUDIOSTREAM_INTERRUPT_HINT_PAUSE = 2 | 提示音频暂停，暂时失去音频焦点。<br>后续待焦点可用时，会出现AUDIOSTREAM_INTERRUPT_HINT_RESUME事件。     |
| AUDIOSTREAM_INTERRUPT_HINT_STOP = 3 | 提示音频停止，彻底失去音频焦点。         |
| AUDIOSTREAM_INTERRUPT_HINT_DUCK = 4 | 提示音频躲避开始，音频降低音量播放，而不会停止。 |
| AUDIOSTREAM_INTERRUPT_HINT_UNDUCK = 5 | 提示音量躲避结束，音频恢复正常音量。       |

### OH_AudioInterrupt_Mode

```
enum OH_AudioInterrupt_Mode
```

**描述**

定义音频中断模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| AUDIOSTREAM_INTERRUPT_MODE_SHARE = 0 | 共享模式。 |
| AUDIOSTREAM_INTERRUPT_MODE_INDEPENDENT = 1 | 独立模式。 |

### OH_AudioStream_AudioEffectMode

```
enum OH_AudioStream_AudioEffectMode
```

**描述**

定义音效模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| EFFECT_NONE = 0 | 无音效模式。 |
| EFFECT_DEFAULT = 1 | 默认音效模式。 |

### OH_AudioStream_DeviceChangeReason

```
enum OH_AudioStream_DeviceChangeReason
```

**描述**

流设备变更原因。

**起始版本：** 11

| 枚举项 | 描述 |
| -- | -- |
| REASON_UNKNOWN = 0 | 未知原因。 |
| REASON_NEW_DEVICE_AVAILABLE = 1 | 新设备可用。 |
| REASON_OLD_DEVICE_UNAVAILABLE = 2 | 旧设备不可用。当报告此原因时，应用程序应考虑暂停音频播放。 |
| REASON_OVERRODE = 3 | 用户或系统强制选择切换。 |

### OH_AudioStream_PrivacyType

```
enum OH_AudioStream_PrivacyType
```

**描述**

用于标识对应播放音频流是否支持被其他应用录制。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| AUDIO_STREAM_PRIVACY_TYPE_PUBLIC = 0 | 表示音频流可以被其他应用录制。 |
| AUDIO_STREAM_PRIVACY_TYPE_PRIVATE = 1 | 表示音频流不可以被其他应用录制。 |

### OH_AudioData_Callback_Result

```
enum OH_AudioData_Callback_Result
```

**描述**

定义音频数据回调结果。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| AUDIO_DATA_CALLBACK_RESULT_INVALID = -1 | 表示音频数据回调结果无效，且音频数据不播放。 |
| AUDIO_DATA_CALLBACK_RESULT_VALID = 0 | 表示音频数据回调结果有效，将播放音频数据。 |


## 函数说明

### OH_AudioRenderer_OutputDeviceChangeCallback()

```
typedef void (*OH_AudioRenderer_OutputDeviceChangeCallback)(OH_AudioRenderer* renderer, void* userData,OH_AudioStream_DeviceChangeReason reason)
```

**描述**

输出音频流设备变更的回调函数。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
|  void* userData | 指向通过回调函数传递的应用数据指针。 |
| [OH_AudioStream_DeviceChangeReason](#oh_audiostream_devicechangereason) reason | 流设备变更原因。 |

### OH_AudioRenderer_OnMarkReachedCallback()

```
typedef void (*OH_AudioRenderer_OnMarkReachedCallback)(OH_AudioRenderer* renderer, uint32_t samplePos, void* userData)
```

**描述**

到达标记位置时回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
|  uint32_t samplePos | 设置目标标记位置。         |
|  void* userData | 指向通过回调函数传递的应用数据指针。|

### OH_AudioRenderer_WriteDataWithMetadataCallback()

```
typedef int32_t (*OH_AudioRenderer_WriteDataWithMetadataCallback)(OH_AudioRenderer* renderer,void* userData, void* audioData, int32_t audioDataSize, void* metadata, int32_t metadataSize)
```

**描述**

该函数指针将指向用于同时写入音频数据和元数据的回调函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| void* userData | 指向通过回调函数传递的应用数据指针。 |
|  void* audioData | 指向用户写入的音频数据的指针。 |
|  int32_t audioDataSize | 用户写入的音频数据的数据长度，以字节为单位。 |
|  void* metadata | 指向用户写入的元数据的指针。 |
|  int32_t metadataSize | 用户写入的元数据的数据长度，以字节为单位。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 用户返回的回调函数的错误码。 |

### OH_AudioRenderer_OnWriteDataCallback()

```
typedef OH_AudioData_Callback_Result (*OH_AudioRenderer_OnWriteDataCallback)(OH_AudioRenderer* renderer, void* userData,void* audioData, int32_t audioDataSize)
```

**描述**

该函数指针将指向用于写入音频数据的回调函数。

回调函数仅用来写入音频数据，请勿在回调函数中调用AudioRenderer相关接口。

该函数的返回结果表示填充到缓冲区的数据是否有效。如果结果无效，用户填写的数据将不被播放。回调函数结束后，音频服务会把audioData指针数据放入队列里等待播放，因此请勿在回调外再次更改audioData指向的数据, 且务必保证往audioData填满audioDataSize长度的待播放数据, 否则会导致音频服务播放杂音。

参数audioDataSize可以通过[OH_AudioStreamBuilder_SetFrameSizeInCallback](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setframesizeincallback)设置。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
|  void* userData | 指向通过回调函数传递的应用数据指针。 |
| void* audioData | 指向用户写入的音频数据的指针。 |
|  int32_t audioDataSize | 用户写入的音频数据的数据长度，以字节为单位。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioData_Callback_Result](#oh_audiodata_callback_result) | AUDIO_DATA_CALLBACK_RESULT_INVALID：音频数据回调结果无效，且音频数据不播放。<br>AUDIO_DATA_CALLBACK_RESULT_VALID：音频数据回调结果有效，将播放音频数据。 |
