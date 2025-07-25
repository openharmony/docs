# native_audiorenderer.h

## 概述

声明输出类型的音频流相关接口。

**引用文件：** <ohaudio/native_audiorenderer.h>

**库：** libohaudio.so

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

**相关模块：** [OHAudio](capi-ohaudio.md)

## 汇总

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AudioStream_Result OH_AudioRenderer_Release(OH_AudioRenderer* renderer)](#oh_audiorenderer_release) | - | 释放输出音频流。 |
| [OH_AudioStream_Result OH_AudioRenderer_Start(OH_AudioRenderer* renderer)](#oh_audiorenderer_start) | - | 开始输出音频数据。 |
| [OH_AudioStream_Result OH_AudioRenderer_Pause(OH_AudioRenderer* renderer)](#oh_audiorenderer_pause) | - | 暂停输出音频流。 |
| [OH_AudioStream_Result OH_AudioRenderer_Stop(OH_AudioRenderer* renderer)](#oh_audiorenderer_stop) | - | 停止输出音频流。 |
| [OH_AudioStream_Result OH_AudioRenderer_Flush(OH_AudioRenderer* renderer)](#oh_audiorenderer_flush) | - | 清空缓冲区的音频数据。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetCurrentState(OH_AudioRenderer* renderer,OH_AudioStream_State* state)](#oh_audiorenderer_getcurrentstate) | - | 查询当前输出音频流状态。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetSamplingRate(OH_AudioRenderer* renderer, int32_t* rate)](#oh_audiorenderer_getsamplingrate) | - | 查询当前输出音频流采样率。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetStreamId(OH_AudioRenderer* renderer, uint32_t* streamId)](#oh_audiorenderer_getstreamid) | - | 查询当前输出音频流ID。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetChannelCount(OH_AudioRenderer* renderer, int32_t* channelCount)](#oh_audiorenderer_getchannelcount) | - | 查询当前输出音频流通道数。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetSampleFormat(OH_AudioRenderer* renderer,OH_AudioStream_SampleFormat* sampleFormat)](#oh_audiorenderer_getsampleformat) | - | 查询当前输出音频流采样格式。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetLatencyMode(OH_AudioRenderer* renderer,OH_AudioStream_LatencyMode* latencyMode)](#oh_audiorenderer_getlatencymode) | - | 查询当前输出音频流时延模式。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetRendererInfo(OH_AudioRenderer* renderer,OH_AudioStream_Usage* usage)](#oh_audiorenderer_getrendererinfo) | - | 查询当前输出音频流的使用类型。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetEncodingType(OH_AudioRenderer* renderer,OH_AudioStream_EncodingType* encodingType)](#oh_audiorenderer_getencodingtype) | - | 查询当前输出音频流编码类型。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetFramesWritten(OH_AudioRenderer* renderer, int64_t* frames)](#oh_audiorenderer_getframeswritten) | - | 查询自创建流以来已写入的帧数。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetTimestamp(OH_AudioRenderer* renderer, clockid_t clockId,int64_t* framePosition, int64_t* timestamp)](#oh_audiorenderer_gettimestamp) | - | 获取输出音频流时间戳和位置信息。<br> 该接口可以获取到音频通道实际播放位置（framePosition）以及播放到该位置时候的时间戳（timestamp），时间戳单位为纳秒。<br> 当设备切换或暂停恢复时，由于播放通路本身需要一段时间恢复，调用该接口获取的播放位置和时间戳会短暂地保持在切换或暂停前的状态。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetAudioTimestampInfo(OH_AudioRenderer* renderer,int64_t* framePosition, int64_t* timestamp)](#oh_audiorenderer_getaudiotimestampinfo) | - | 获取输出音频流时间戳和位置信息，适配倍速接口。<br> 获取输出音频流时间戳和位置信息，通常用于进行音画同步对齐。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetFrameSizeInCallback(OH_AudioRenderer* renderer, int32_t* frameSize)](#oh_audiorenderer_getframesizeincallback) | - | 在回调中查询帧大小，它是一个固定的长度，每次回调都要填充流。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetSpeed(OH_AudioRenderer* renderer, float* speed)](#oh_audiorenderer_getspeed) | - | 获取音频渲染速率。 |
| [OH_AudioStream_Result OH_AudioRenderer_SetSpeed(OH_AudioRenderer* renderer, float speed)](#oh_audiorenderer_setspeed) | - | 设置音频渲染速率。 |
| [OH_AudioStream_Result OH_AudioRenderer_SetMarkPosition(OH_AudioRenderer* renderer, uint32_t samplePos,OH_AudioRenderer_OnMarkReachedCallback callback, void* userData)](#oh_audiorenderer_setmarkposition) | - | 在当前渲染器上设置标记位置。调用此函数将覆盖已设置的标记位置。 |
| [OH_AudioStream_Result OH_AudioRenderer_CancelMark(OH_AudioRenderer* renderer)](#oh_audiorenderer_cancelmark) | - | 取消由[OH_AudioRenderer_SetMarkPosition](#oh_audiorenderer_setmarkposition)设置的标记。 |
| [OH_AudioStream_Result OH_AudioRenderer_SetVolume(OH_AudioRenderer* renderer, float volume)](#oh_audiorenderer_setvolume) | - | 设置当前音频流音量值。 |
| [OH_AudioStream_Result OH_AudioRenderer_SetVolumeWithRamp(OH_AudioRenderer* renderer, float volume, int32_t durationMs)](#oh_audiorenderer_setvolumewithramp) | - | 在指定时间范围内使用渐变更改音量。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetVolume(OH_AudioRenderer* renderer, float* volume)](#oh_audiorenderer_getvolume) | - | 获取当前音频流音量值。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetUnderflowCount(OH_AudioRenderer* renderer, uint32_t* count)](#oh_audiorenderer_getunderflowcount) | - | 获取当前播放音频流欠载数。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetChannelLayout(OH_AudioRenderer* renderer,OH_AudioChannelLayout* channelLayout)](#oh_audiorenderer_getchannellayout) | - | 查询当前音频流声道布局。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetEffectMode(OH_AudioRenderer* renderer,OH_AudioStream_AudioEffectMode* effectMode)](#oh_audiorenderer_geteffectmode) | - | 查询当前音频流音效模式。 |
| [OH_AudioStream_Result OH_AudioRenderer_SetEffectMode(OH_AudioRenderer* renderer,OH_AudioStream_AudioEffectMode effectMode)](#oh_audiorenderer_seteffectmode) | - | 设置当前音频流音效模式。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetRendererPrivacy(OH_AudioRenderer* renderer,OH_AudioStream_PrivacyType* privacy)](#oh_audiorenderer_getrendererprivacy) | - | 查询当前播放音频流是否会被其它应用录制。 |
| [OH_AudioStream_Result OH_AudioRenderer_SetSilentModeAndMixWithOthers(OH_AudioRenderer* renderer, bool on)](#oh_audiorenderer_setsilentmodeandmixwithothers) | - | 设置静音并发播放模式。<br> 当设置为true，打开静音并发播放模式，系统将让此音频流静音播放，并且不会打断其他音频流。设置为false，将关闭静音并发播放，音频流可根据系统焦点策略抢占焦点。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetSilentModeAndMixWithOthers(OH_AudioRenderer* renderer, bool* on)](#oh_audiorenderer_getsilentmodeandmixwithothers) | - | 获取当前音频流是否开启静音并发播放。 |
| [OH_AudioStream_Result OH_AudioRenderer_SetDefaultOutputDevice(OH_AudioRenderer* renderer, OH_AudioDevice_Type deviceType)](#oh_audiorenderer_setdefaultoutputdevice) | - | 设置默认本机内置发声设备。<br> 本接口仅适用于音频流类型[OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage)为语音消息、VoIP语音通话或者VoIP视频通话的场景使用，以及可选的设备类型为听筒、扬声器和系统默认设备。<br> 本接口允许在AudioRenderer创建以后的任何时间被调用，系统会记录应用设置的默认本机内置发声设备。在应用启动播放时，若有外接设备如蓝牙耳机/有线耳机接入，系统优先从外接设备发声；否则系统遵循应用设置的默认本机内置发声设备发声。<br> |
| [typedef void (\*OH_AudioRenderer_OnInterruptCallback)(OH_AudioRenderer* renderer, void* userData,OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)](#oh_audiorenderer_oninterruptcallback) | OH_AudioRenderer_OnInterruptCallback | 音频流中断事件回调函数。 |
| [typedef void (\*OH_AudioRenderer_OnErrorCallback)(OH_AudioRenderer* renderer, void* userData,OH_AudioStream_Result error)](#oh_audiorenderer_onerrorcallback) | OH_AudioRenderer_OnErrorCallback | 音频流错误事件回调函数。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetFastStatus(OH_AudioRenderer* renderer,OH_AudioStream_FastStatus* status)](#oh_audiorenderer_getfaststatus) | - | 获取音频播放过程中的运行状态，是否在低时延状态下工作。 |
| [typedef void (\*OH_AudioRenderer_OnFastStatusChange)(OH_AudioRenderer* renderer,void* userData,OH_AudioStream_FastStatus status)](#oh_audiorenderer_onfaststatuschange) | OH_AudioRenderer_OnFastStatusChange | 音频播放过程中低时延状态改变事件的回调函数。 |
| [OH_AudioStream_Result OH_AudioRenderer_SetLoudnessGain(OH_AudioRenderer* renderer, float loudnessGain)](#oh_audiorenderer_setloudnessgain) | - | 设置音频播放的响度值。默认的响度值是0.0dB。音频流播放类型必须是音乐[OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_MUSIC，<br> 电影或视频[OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_MUSIC，<br> 有声读物（包括听书、相声、评书）、听新闻、播客等[OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_AUDIOBOOK。<br> 音频流的时延模式必须是普通时延[OH_AudioStream_LatencyMode](capi-native-audiostream-base-h.md#oh_audiostream_latencymode).AUDIOSTREAM_LATENCY_MODE_NORMAL。<br> 本接口不支持通过高清通路播放的音频流设置响度。<br> 由于音频框架与硬件之间存在缓冲区，响度调节实际生效存在延迟，时长取决于缓冲区长度。<br> 建议在不同音频开始播放前预先设置响度，以实现最佳均衡效果。 |
| [OH_AudioStream_Result OH_AudioRenderer_GetLoudnessGain(OH_AudioRenderer* renderer, float* loudnessGain)](#oh_audiorenderer_getloudnessgain) | - | 获取音频流的响度值。 |

## 函数说明

### OH_AudioRenderer_Release()

```
OH_AudioStream_Result OH_AudioRenderer_Release(OH_AudioRenderer* renderer)
```

**描述**

释放输出音频流。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。 |

### OH_AudioRenderer_Start()

```
OH_AudioStream_Result OH_AudioRenderer_Start(OH_AudioRenderer* renderer)
```

**描述**

开始输出音频数据。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。 |

### OH_AudioRenderer_Pause()

```
OH_AudioStream_Result OH_AudioRenderer_Pause(OH_AudioRenderer* renderer)
```

**描述**

暂停输出音频流。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。 |

### OH_AudioRenderer_Stop()

```
OH_AudioStream_Result OH_AudioRenderer_Stop(OH_AudioRenderer* renderer)
```

**描述**

停止输出音频流。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。 |

### OH_AudioRenderer_Flush()

```
OH_AudioStream_Result OH_AudioRenderer_Flush(OH_AudioRenderer* renderer)
```

**描述**

清空缓冲区的音频数据。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。 |

### OH_AudioRenderer_GetCurrentState()

```
OH_AudioStream_Result OH_AudioRenderer_GetCurrentState(OH_AudioRenderer* renderer,OH_AudioStream_State* state)
```

**描述**

查询当前输出音频流状态。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| [OH_AudioStream_State](capi-native-audiostream-base-h.md#oh_audiostream_state)* state | 指向一个用来接收音频流状态的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_GetSamplingRate()

```
OH_AudioStream_Result OH_AudioRenderer_GetSamplingRate(OH_AudioRenderer* renderer, int32_t* rate)
```

**描述**

查询当前输出音频流采样率。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| int32_t* rate | 指向一个用来接收音频流采样率的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_GetStreamId()

```
OH_AudioStream_Result OH_AudioRenderer_GetStreamId(OH_AudioRenderer* renderer, uint32_t* streamId)
```

**描述**

查询当前输出音频流ID。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| uint32_t* streamId | 指向一个用来接收音频流ID的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_GetChannelCount()

```
OH_AudioStream_Result OH_AudioRenderer_GetChannelCount(OH_AudioRenderer* renderer, int32_t* channelCount)
```

**描述**

查询当前输出音频流通道数。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| int32_t* channelCount | 指向一个用来接收音频流通道数的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_GetSampleFormat()

```
OH_AudioStream_Result OH_AudioRenderer_GetSampleFormat(OH_AudioRenderer* renderer,OH_AudioStream_SampleFormat* sampleFormat)
```

**描述**

查询当前输出音频流采样格式。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| [OH_AudioStream_SampleFormat](capi-native-audiostream-base-h.md#oh_audiostream_sampleformat)* sampleFormat | 指向一个用来接收音频流采样格式的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_GetLatencyMode()

```
OH_AudioStream_Result OH_AudioRenderer_GetLatencyMode(OH_AudioRenderer* renderer,OH_AudioStream_LatencyMode* latencyMode)
```

**描述**

查询当前输出音频流时延模式。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| [OH_AudioStream_LatencyMode](capi-native-audiostream-base-h.md#oh_audiostream_latencymode)* latencyMode | 指向一个用来接收音频流时延模式的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_GetRendererInfo()

```
OH_AudioStream_Result OH_AudioRenderer_GetRendererInfo(OH_AudioRenderer* renderer,OH_AudioStream_Usage* usage)
```

**描述**

查询当前输出音频流的使用类型。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage)* usage | 指向一个用来接收输出类型音频流的使用类型的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_GetEncodingType()

```
OH_AudioStream_Result OH_AudioRenderer_GetEncodingType(OH_AudioRenderer* renderer,OH_AudioStream_EncodingType* encodingType)
```

**描述**

查询当前输出音频流编码类型。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| [OH_AudioStream_EncodingType](capi-native-audiostream-base-h.md#oh_audiostream_encodingtype)* encodingType | 指向一个用来接收音频流编码类型的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_GetFramesWritten()

```
OH_AudioStream_Result OH_AudioRenderer_GetFramesWritten(OH_AudioRenderer* renderer, int64_t* frames)
```

**描述**

查询自创建流以来已写入的帧数。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| int64_t* frames | 指向将为帧计数设置的变量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_GetTimestamp()

```
OH_AudioStream_Result OH_AudioRenderer_GetTimestamp(OH_AudioRenderer* renderer, clockid_t clockId,int64_t* framePosition, int64_t* timestamp)
```

**描述**

获取输出音频流时间戳和位置信息。<br> 该接口可以获取到音频通道实际播放位置（framePosition）以及播放到该位置时候的时间戳（timestamp），时间戳单位为纳秒。<br> 当设备切换或暂停恢复时，由于播放通路本身需要一段时间恢复，调用该接口获取的播放位置和时间戳会短暂地保持在切换或暂停前的状态。<br> 该接口一般用来实现音画同步，建议频率不要太频繁，可以每分钟一次，最好不要低200ms一次。频繁调用可能会带来功耗问题，因此在能保证音画同步效果的情况下，不需要频繁的查询时间戳。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| clockid_t clockId | 时钟标识符，使用CLOCK_MONOTONIC。 |
| int64_t* framePosition | 指向要接收位置的变量的指针。 |
| int64_t* timestamp | 指向接收时间戳的变量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：<br>                                                 1. 参数renderer为nullptr；<br>                                                 2. 参数clockId无效。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。 |

### OH_AudioRenderer_GetAudioTimestampInfo()

```
OH_AudioStream_Result OH_AudioRenderer_GetAudioTimestampInfo(OH_AudioRenderer* renderer,int64_t* framePosition, int64_t* timestamp)
```

**描述**

获取输出音频流时间戳和位置信息，适配倍速接口。<br> 获取输出音频流时间戳和位置信息，通常用于进行音画同步对齐。<br> 注意，当实际播放位置（framePosition）为0时，时间戳（timestamp）是固定值，直到流真正跑起来时才会更新。当调用Flush接口时实际播放位置也会被重置。<br> 当音频流路由（route）变化时，例如设备变化或者输出类型变化时，播放位置也会被重置，但此时时间戳仍会持续增长。推荐当实际播放位置和时间戳的变化稳定后再使用该接口获取的值。该接口适配倍速接口，例如当播放速度设置为2倍时，播放位置的增长速度也会返回为正常的2倍。<br>

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| int64_t* framePosition | 指向要接收位置的变量的指针。 |
| int64_t* timestamp | 指向接收时间戳的变量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：<br>                                                 1. 参数renderer为nullptr；<br>                                                 2. 参数framePosition或timestamp为nullptr。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：当前流状态不为合法状态时返回。<br>         AUDIOSTREAM_ERROR_SYSTEM：<br>                                          1. 系统进程崩溃或被阻塞；<br>                                          2. 内部系统其他错误。 |

### OH_AudioRenderer_GetFrameSizeInCallback()

```
OH_AudioStream_Result OH_AudioRenderer_GetFrameSizeInCallback(OH_AudioRenderer* renderer, int32_t* frameSize)
```

**描述**

在回调中查询帧大小，它是一个固定的长度，每次回调都要填充流。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| int32_t* frameSize | 指向将为帧大小设置的变量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_GetSpeed()

```
OH_AudioStream_Result OH_AudioRenderer_GetSpeed(OH_AudioRenderer* renderer, float* speed)
```

**描述**

获取音频渲染速率。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| float* speed | 指向接收播放倍速值的变量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_SetSpeed()

```
OH_AudioStream_Result OH_AudioRenderer_SetSpeed(OH_AudioRenderer* renderer, float speed)
```

**描述**

设置音频渲染速率。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| float speed | 设置播放的倍速值（倍速范围：0.25-4.0）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_SetMarkPosition()

```
OH_AudioStream_Result OH_AudioRenderer_SetMarkPosition(OH_AudioRenderer* renderer, uint32_t samplePos,OH_AudioRenderer_OnMarkReachedCallback callback, void* userData)
```

**描述**

在当前渲染器上设置标记位置。调用此函数将覆盖已设置的标记位置。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| uint32_t samplePos | 设置目标标记位置。 |
| [OH_AudioRenderer_OnMarkReachedCallback](capi-native-audiostream-base-h.md#oh_audiorenderer_onmarkreachedcallback) callback | 当到达目标标记位置时回调。 |
| void* userData | 指向通过回调函数传递的应用数据指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：<br>                                                 1. 参数renderer为nullptr；<br>                                                 2. 参数samplePos无效。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。<br>         AUDIOSTREAM_ERROR_SYSTEM：出现系统错误。 |

### OH_AudioRenderer_CancelMark()

```
OH_AudioStream_Result OH_AudioRenderer_CancelMark(OH_AudioRenderer* renderer)
```

**描述**

取消由[OH_AudioRenderer_SetMarkPosition](#oh_audiorenderer_setmarkposition)设置的标记。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_SetVolume()

```
OH_AudioStream_Result OH_AudioRenderer_SetVolume(OH_AudioRenderer* renderer, float volume)
```

**描述**

设置当前音频流音量值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| float volume | 设置当前音频流音量，音量值范围[0.0, 1.0]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：<br>                                                 1. 参数renderer为nullptr；<br>                                                 2. 参数volume无效。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。<br>         AUDIOSTREAM_ERROR_SYSTEM：出现系统错误。 |

### OH_AudioRenderer_SetVolumeWithRamp()

```
OH_AudioStream_Result OH_AudioRenderer_SetVolumeWithRamp(OH_AudioRenderer* renderer, float volume, int32_t durationMs)
```

**描述**

在指定时间范围内使用渐变更改音量。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| float volume | 目标音量值，取值范围[0.0, 1.0]。 |
| int32_t durationMs | 音量渐变的持续时间，以毫秒为单位。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：<br>                                                 1. 参数renderer为nullptr；<br>                                                 2. 参数volume无效。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。<br>         AUDIOSTREAM_ERROR_SYSTEM：出现系统错误。 |

### OH_AudioRenderer_GetVolume()

```
OH_AudioStream_Result OH_AudioRenderer_GetVolume(OH_AudioRenderer* renderer, float* volume)
```

**描述**

获取当前音频流音量值。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| float* volume | 指向一个获取当前音频流音量值的指针。音量值的范围是[0.0, 1.0]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：<br>                                                 1. 参数renderer为nullptr；<br>                                                 2. 参数volume为nullptr。 |

### OH_AudioRenderer_GetUnderflowCount()

```
OH_AudioStream_Result OH_AudioRenderer_GetUnderflowCount(OH_AudioRenderer* renderer, uint32_t* count)
```

**描述**

获取当前播放音频流欠载数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| uint32_t* count | 指向一个用来接收音频流欠载数的变量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：<br>                                                 1. 参数renderer为nullptr；<br>                                                 2. 参数count为nullptr。 |

### OH_AudioRenderer_GetChannelLayout()

```
OH_AudioStream_Result OH_AudioRenderer_GetChannelLayout(OH_AudioRenderer* renderer,OH_AudioChannelLayout* channelLayout)
```

**描述**

查询当前音频流声道布局。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| [OH_AudioChannelLayout](../apis-avcodec-kit/_core.md#oh_audiochannellayout-1)* channelLayout | 指向一个用来接收音频流声道布局的变量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_GetEffectMode()

```
OH_AudioStream_Result OH_AudioRenderer_GetEffectMode(OH_AudioRenderer* renderer,OH_AudioStream_AudioEffectMode* effectMode)
```

**描述**

查询当前音频流音效模式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| [OH_AudioStream_AudioEffectMode](capi-native-audiostream-base-h.md#oh_audiostream_audioeffectmode)* effectMode | 指向一个用来接收音频流音效模式的变量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_SetEffectMode()

```
OH_AudioStream_Result OH_AudioRenderer_SetEffectMode(OH_AudioRenderer* renderer,OH_AudioStream_AudioEffectMode effectMode)
```

**描述**

设置当前音频流音效模式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| [OH_AudioStream_AudioEffectMode](capi-native-audiostream-base-h.md#oh_audiostream_audioeffectmode) effectMode | 设置当前音频流的目标音效模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_GetRendererPrivacy()

```
OH_AudioStream_Result OH_AudioRenderer_GetRendererPrivacy(OH_AudioRenderer* renderer,OH_AudioStream_PrivacyType* privacy)
```

**描述**

查询当前播放音频流是否会被其它应用录制。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| [OH_AudioStream_PrivacyType](capi-native-audiostream-base-h.md#oh_audiostream_privacytype)* privacy | 用于返回当前流的内录策略。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_SetSilentModeAndMixWithOthers()

```
OH_AudioStream_Result OH_AudioRenderer_SetSilentModeAndMixWithOthers(OH_AudioRenderer* renderer, bool on)
```

**描述**

设置静音并发播放模式。<br> 当设置为true，打开静音并发播放模式，系统将让此音频流静音播放，并且不会打断其他音频流。设置为false，将关闭静音并发播放，音频流可根据系统焦点策略抢占焦点。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| bool on | 设置当前音频流的静音并发状态。<br>     true：设置当前播放的音频流静音播放，并且不会打断其它音频流播放。<br>     false：取消当前播放的音频流静音播放，音频流可根据系统焦点策略抢占焦点。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_GetSilentModeAndMixWithOthers()

```
OH_AudioStream_Result OH_AudioRenderer_GetSilentModeAndMixWithOthers(OH_AudioRenderer* renderer, bool* on)
```

**描述**

获取当前音频流是否开启静音并发播放。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| bool* on | 用于返回当前流的静音并发状态。返回true表示打开，返回false表示关闭。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。 |

### OH_AudioRenderer_SetDefaultOutputDevice()

```
OH_AudioStream_Result OH_AudioRenderer_SetDefaultOutputDevice(OH_AudioRenderer* renderer, OH_AudioDevice_Type deviceType)
```

**描述**

设置默认本机内置发声设备。<br> 本接口仅适用于音频流类型[OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage)为语音消息、VoIP语音通话或者VoIP视频通话的场景使用，以及可选的设备类型为听筒、扬声器和系统默认设备。<br> 本接口允许在AudioRenderer创建以后的任何时间被调用，系统会记录应用设置的默认本机内置发声设备。在应用启动播放时，若有外接设备如蓝牙耳机/有线耳机接入，系统优先从外接设备发声；否则系统遵循应用设置的默认本机内置发声设备发声。<br>

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| [OH_AudioDevice_Type](capi-native-audio-device-base-h.md#oh_audiodevice_type) deviceType | 指向[OH_AudioDevice_Type](capi-native-audio-device-base-h.md#oh_audiodevice_type)用于设置发声设备类型。可设置的设备类型包括:<br>                                             AUDIO_DEVICE_TYPE_EARPIECE：听筒<br>                                             AUDIO_DEVICE_TYPE_SPEAKER：扬声器<br>                                             AUDIO_DEVICE_TYPE_DEFAULT：系统默认设备 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：<br>                                                  1. 参数renderer为nullptr;<br>                                                  2. 参数deviceType无效。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。<br>         AUDIOSTREAM_ERROR_SYSTEM：出现系统错误。 |

### OH_AudioRenderer_OnInterruptCallback()

```
typedef void (*OH_AudioRenderer_OnInterruptCallback)(OH_AudioRenderer* renderer, void* userData,OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)
```

**描述**

音频流中断事件回调函数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
|  void* userData | 指向应用自定义的数据存储区域。 |
| [OH_AudioInterrupt_ForceType](capi-native-audiostream-base-h.md#oh_audiointerrupt_forcetype) type | 音频流中断类型。 |
| [OH_AudioInterrupt_Hint](capi-native-audiostream-base-h.md#oh_audiointerrupt_hint) hint | 音频流中断提示类型。 |

### OH_AudioRenderer_OnErrorCallback()

```
typedef void (*OH_AudioRenderer_OnErrorCallback)(OH_AudioRenderer* renderer, void* userData,OH_AudioStream_Result error)
```

**描述**

音频流错误事件回调函数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
|  void* userData | 指向应用自定义的数据存储区域。 |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) error | 音频流播放错误结果。 |

### OH_AudioRenderer_GetFastStatus()

```
OH_AudioStream_Result OH_AudioRenderer_GetFastStatus(OH_AudioRenderer* renderer,OH_AudioStream_FastStatus* status)
```

**描述**

获取音频播放过程中的运行状态，是否在低时延状态下工作。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| [OH_AudioStream_FastStatus](capi-native-audiostream-base-h.md#oh_audiostream_faststatus)* status | 指向接收低时延状态的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数renderer为nullptr。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常，仅在释放状态之前可用。 |

### OH_AudioRenderer_OnFastStatusChange()

```
typedef void (*OH_AudioRenderer_OnFastStatusChange)(OH_AudioRenderer* renderer,void* userData,OH_AudioStream_FastStatus status)
```

**描述**

音频播放过程中低时延状态改变事件的回调函数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| void* userData | 指向应用自定义的数据存储区域。 |
| status | 返回当前低时延状态。 |

### OH_AudioRenderer_SetLoudnessGain()

```
OH_AudioStream_Result OH_AudioRenderer_SetLoudnessGain(OH_AudioRenderer* renderer, float loudnessGain)
```

**描述**

设置音频播放的响度值。默认的响度值是0.0dB。音频流播放类型必须是音乐[OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_MUSIC，<br> 电影或视频[OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_MUSIC，<br> 有声读物（包括听书、相声、评书）、听新闻、播客等[OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_AUDIOBOOK。<br> 音频流的时延模式必须是普通时延[OH_AudioStream_LatencyMode](capi-native-audiostream-base-h.md#oh_audiostream_latencymode).AUDIOSTREAM_LATENCY_MODE_NORMAL。<br> 本接口不支持通过高清通路播放的音频流设置响度。<br> 由于音频框架与硬件之间存在缓冲区，响度调节实际生效存在延迟，时长取决于缓冲区长度。<br> 建议在不同音频开始播放前预先设置响度，以实现最佳均衡效果。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| float loudnessGain | 设置播放的响度值（响度值范围为[-90.0, 24.0]，单位为dB）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：<br>                                                 1. 参数renderer为nullptr，或音频流不支持设置响度；<br>                                                 2. 参数loudnessGain不在响度值范围内。 |

### OH_AudioRenderer_GetLoudnessGain()

```
OH_AudioStream_Result OH_AudioRenderer_GetLoudnessGain(OH_AudioRenderer* renderer, float* loudnessGain)
```

**描述**

获取音频流的响度值。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | 指向[OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer)创建的音频流实例。 |
| float* loudnessGain | 指向接收播放响度值的变量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：<br>                                                 1. 参数renderer为nullptr；<br>                                                 2. 参数loudnessGain为nullptr。 |


