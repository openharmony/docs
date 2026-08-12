# native_audiocapturer.h
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zyy0412-->
<!--Designer: @weixin_41398971-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

## 概述

声明音频采集的相关接口。

**引用文件：** <ohaudio/native_audiocapturer.h>

**库：** libohaudio.so

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 10

**相关模块：** [OHAudio](capi-ohaudio.md)

## 汇总

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AudioStream_Result OH_AudioCapturer_Release(OH_AudioCapturer* capturer)](#oh_audiocapturer_release) | - | 释放输入音频流。 |
| [OH_AudioStream_Result OH_AudioCapturer_Start(OH_AudioCapturer* capturer)](#oh_audiocapturer_start) | - | 启动音频采集器，开始获取音频数据。 |
| [OH_AudioStream_Result OH_AudioCapturer_Pause(OH_AudioCapturer* capturer)](#oh_audiocapturer_pause) | - | 暂停输入音频流。在暂停音频后，后续需要恢复录音的场景，建议使用pause。 |
| [OH_AudioStream_Result OH_AudioCapturer_Stop(OH_AudioCapturer* capturer)](#oh_audiocapturer_stop) | - | 停止音频采集器，停止输入音频流后，如果需要彻底结束录音，建议使用stop。 |
| [OH_AudioStream_Result OH_AudioCapturer_Flush(OH_AudioCapturer* capturer)](#oh_audiocapturer_flush) | - | 丢弃获取的音频数据。 |
| [OH_AudioStream_Result OH_AudioCapturer_GetCurrentState(OH_AudioCapturer* capturer, OH_AudioStream_State* state)](#oh_audiocapturer_getcurrentstate) | - | 查询当前音频流状态。 |
| [OH_AudioStream_Result OH_AudioCapturer_GetLatencyMode(OH_AudioCapturer* capturer, OH_AudioStream_LatencyMode* latencyMode)](#oh_audiocapturer_getlatencymode) | - | 查询当前音频流时延模式。 |
| [OH_AudioStream_Result OH_AudioCapturer_GetStreamId(OH_AudioCapturer* capturer, uint32_t* streamId)](#oh_audiocapturer_getstreamid) | - | 查询当前输入音频流ID。 |
| [OH_AudioStream_Result OH_AudioCapturer_GetSamplingRate(OH_AudioCapturer* capturer, int32_t* rate)](#oh_audiocapturer_getsamplingrate) | - | 查询当前输入音频流采样率。 |
| [OH_AudioStream_Result OH_AudioCapturer_GetChannelCount(OH_AudioCapturer* capturer, int32_t* channelCount)](#oh_audiocapturer_getchannelcount) | - | 查询当前音频流通道数。 |
| [OH_AudioStream_Result OH_AudioCapturer_GetSampleFormat(OH_AudioCapturer* capturer, OH_AudioStream_SampleFormat* sampleFormat)](#oh_audiocapturer_getsampleformat) | - | 查询当前输入音频流采样格式。 |
| [OH_AudioStream_Result OH_AudioCapturer_GetEncodingType(OH_AudioCapturer* capturer, OH_AudioStream_EncodingType* encodingType)](#oh_audiocapturer_getencodingtype) | - | 查询当前音频流编码类型。 |
| [OH_AudioStream_Result OH_AudioCapturer_GetCapturerInfo(OH_AudioCapturer* capturer, OH_AudioStream_SourceType* sourceType)](#oh_audiocapturer_getcapturerinfo) | - | 查询当前音频流工作场景类型。 |
| [OH_AudioStream_Result OH_AudioCapturer_GetFrameSizeInCallback(OH_AudioCapturer* capturer, int32_t* frameSize)](#oh_audiocapturer_getframesizeincallback) | - | 查询回调帧数。frameSize表示每次回调对应的采样帧数。 |
| [OH_AudioStream_Result OH_AudioCapturer_GetTimestamp(OH_AudioCapturer* capturer, clockid_t clockId,int64_t* framePosition, int64_t* timestamp)](#oh_audiocapturer_gettimestamp) | - | 获取输入音频流时间戳和当前数据帧位置信息。<br> 该接口可以获取到音频通道实际录制位置（framePosition）以及录制到该位置时候的时间戳（timestamp），时间戳单位为纳秒。 |
| [OH_AudioStream_Result OH_AudioCapturer_GetFramesRead(OH_AudioCapturer* capturer, int64_t* frames)](#oh_audiocapturer_getframesread) | - | 查询自创建流以来已读取的帧数。 |
| [OH_AudioStream_Result OH_AudioCapturer_SetMuteHint(OH_AudioCapturer* capturer, bool mute)](#oh_audiocapturer_setmutehint) | - | 应用将当前录音流的自身静音状态传递给系统音频模块。该接口用于向系统音频模块上报应用自身的静音状态，不会改变录音流的实际静音状态。当前仅在部分PC/2in1设备上，系统音频模块会基于设置的状态调整策略以降低功耗。该接口仅在录音流处于运行态时允许调用，否则返回错误AUDIOSTREAM_ERROR_ILLEGAL_STATE。同一录音流同时设置流级静音提示接口（本接口）和会话级静音提示接口时，流级（本接口）优先级更高，数值以流级（本接口）设置值为准。 |
| [OH_AudioStream_Result OH_AudioCapturer_GetOverflowCount(OH_AudioCapturer* capturer, uint32_t* count)](#oh_audiocapturer_getoverflowcount) | - | 查询当前录制音频流过载数。 |
| [typedef void (\*OH_AudioCapturer_OnReadDataCallback)(OH_AudioCapturer* capturer, void* userData, void* audioData, int32_t audioDataSize)](#oh_audiocapturer_onreaddatacallback) | OH_AudioCapturer_OnReadDataCallback | 读取音频数据的回调函数。为了消除麦克风硬件设计带来的上电杂音，通常会对录音启动后的前100ms数据进行静音。 |
| [typedef void (\*OH_AudioCapturer_OnDeviceChangeCallback)(OH_AudioCapturer* capturer, void* userData, OH_AudioDeviceDescriptorArray* deviceArray)](#oh_audiocapturer_ondevicechangecallback) | OH_AudioCapturer_OnDeviceChangeCallback | 音频录制流的设备变化事件回调函数。 |
| [typedef void (\*OH_AudioCapturer_OnInterruptCallback)(OH_AudioCapturer* capturer, void* userData, OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)](#oh_audiocapturer_oninterruptcallback) | OH_AudioCapturer_OnInterruptCallback | 音频录制流的中断事件回调函数。 |
| [typedef void (\*OH_AudioCapturer_OnErrorCallback)(OH_AudioCapturer* capturer, void* userData, OH_AudioStream_Result error)](#oh_audiocapturer_onerrorcallback) | OH_AudioCapturer_OnErrorCallback | 音频录制流的错误事件回调函数。 |
| [OH_AudioStream_Result OH_AudioCapturer_GetFastStatus(OH_AudioCapturer* capturer, OH_AudioStream_FastStatus* status)](#oh_audiocapturer_getfaststatus) | - | 获取音频录制过程中的运行状态，是否在低时延状态下工作。 |
| [typedef void (\*OH_AudioCapturer_OnFastStatusChange)(OH_AudioCapturer* capturer, void* userData, OH_AudioStream_FastStatus status)](#oh_audiocapturer_onfaststatuschange) | OH_AudioCapturer_OnFastStatusChange | 音频录制过程中低时延状态改变事件的回调函数。 |
| [typedef void (\*OH_AudioCapturer_OnPlaybackCaptureStartCallback)(OH_AudioCapturer* capturer, void* userData, OH_AudioStream_PlaybackCaptureStartState state)](#oh_audiocapturer_onplaybackcapturestartcallback) | OH_AudioCapturer_OnPlaybackCaptureStartCallback | 音频录制过程中用于内录（录制的是设备内部应用的声音）启动结果的回调函数。该API暂不对外支持。 |
| [OH_AudioStream_Result OH_AudioCapturer_RequestPlaybackCaptureStart(OH_AudioCapturer* capturer, OH_AudioCapturer_OnPlaybackCaptureStartCallback callback, void* userData)](#oh_audiocapturer_requestplaybackcapturestart) | - | 异步请求启动内录流。该函数是非阻塞的，意味着系统在接收到启动请求后，将继续处理用户授权和内录流的启动。<br> 最终结果将通过回调函数返回。该API暂不对外支持。 |
| [OH_AudioStream_Result OH_AudioCapturer_SetIndependentAudioSessionStrategy(OH_AudioCapturer* capturer, const OH_AudioSession_Strategy* strategy, uint32_t behavior)](#oh_audiocapturer_setindependentaudiosessionstrategy) | - | 设置独立的音频会话策略和行为参数。当音频采集器在运行状态时调用此接口后，必须重新调用接口[OH_AudioCapturer_Start](capi-native-audiocapturer-h.md#oh_audiocapturer_start)使其生效。 |
| [OH_AudioStream_Result OH_AudioCapturer_SetNoiseReductionMode(OH_AudioCapturer* capturer, OH_AudioNoiseReductionMode noiseReductionMode)](#oh_audiocapturer_setnoisereductionmode) | - | 设置当前录音流的降噪模式。 |
| [OH_AudioStream_Result OH_AudioCapturer_GetNoiseReductionMode(OH_AudioCapturer* capturer, OH_AudioNoiseReductionMode* noiseReductionMode)](#oh_audiocapturer_getnoisereductionmode) | - | 获取当前录音流的降噪模式。 |
| [OH_AudioStream_Result OH_AudioCapturer_GetSupportedNoiseReductionModes(OH_AudioCapturer* capturer, OH_AudioNoiseReductionMode* noiseReductionModeArray, uint32_t inModeArraySize, uint32_t *outModeArraySize)](#oh_audiocapturer_getsupportednoisereductionmodes) | - | 获取当前设备平台支持的录音降噪模式。 |
| [typedef void (\*OH_AudioCapturer_SensitiveRecordPermitCallback)(OH_AudioCapturer* capturer, void* userData, bool isPermitted)](#oh_audiocapturer_sensitiverecordpermitcallback) | OH_AudioCapturer_SensitiveRecordPermitCallback | 蜂窝通话录音场景下，风险提示语播放结束的回调函数。应用必须等待回调返回许可结果，且isPermitted为true时，方可开始蜂窝通话录音。 |

## 函数说明

### OH_AudioCapturer_Release()

```c
OH_AudioStream_Result OH_AudioCapturer_Release(OH_AudioCapturer* capturer)
```

**描述**

释放输入音频流。

**需要权限：** ohos.permission.MICROPHONE

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。 |

### OH_AudioCapturer_Start()

```c
OH_AudioStream_Result OH_AudioCapturer_Start(OH_AudioCapturer* capturer)
```

**描述**

启动音频采集器，开始获取音频数据。

**需要权限：** ohos.permission.MICROPHONE

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。 |

### OH_AudioCapturer_Pause()

```c
OH_AudioStream_Result OH_AudioCapturer_Pause(OH_AudioCapturer* capturer)
```

**描述**

暂停输入音频流。在暂停音频后，后续需要恢复录音的场景，建议使用pause。

**需要权限：** ohos.permission.MICROPHONE

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。 |

### OH_AudioCapturer_Stop()

```c
OH_AudioStream_Result OH_AudioCapturer_Stop(OH_AudioCapturer* capturer)
```

**描述**

停止音频采集器，停止输入音频流后，如果需要彻底结束录音，建议使用stop。

**需要权限：** ohos.permission.MICROPHONE

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。 |

### OH_AudioCapturer_Flush()

```c
OH_AudioStream_Result OH_AudioCapturer_Flush(OH_AudioCapturer* capturer)
```

**描述**

丢弃获取的音频数据。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。 |

### OH_AudioCapturer_GetCurrentState()

```c
OH_AudioStream_Result OH_AudioCapturer_GetCurrentState(OH_AudioCapturer* capturer, OH_AudioStream_State* state)
```

**描述**

查询当前音频流状态。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| [OH_AudioStream_State](capi-native-audiostream-base-h.md#oh_audiostream_state)* state | 指向一个用来接收音频流状态的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。 |

### OH_AudioCapturer_GetLatencyMode()

```c
OH_AudioStream_Result OH_AudioCapturer_GetLatencyMode(OH_AudioCapturer* capturer,OH_AudioStream_LatencyMode* latencyMode)
```

**描述**

查询当前音频流时延模式。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| [OH_AudioStream_LatencyMode](capi-native-audiostream-base-h.md#oh_audiostream_latencymode)* latencyMode | 指向一个用来接收音频流时延模式的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。 |

### OH_AudioCapturer_GetStreamId()

```c
OH_AudioStream_Result OH_AudioCapturer_GetStreamId(OH_AudioCapturer* capturer, uint32_t* streamId)
```

**描述**

查询当前输入音频流ID。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| uint32_t* streamId | 指向一个用来接收音频流ID的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。 |

### OH_AudioCapturer_GetSamplingRate()

```c
OH_AudioStream_Result OH_AudioCapturer_GetSamplingRate(OH_AudioCapturer* capturer, int32_t* rate)
```

**描述**

查询当前输入音频流采样率。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| int32_t* rate | 指向一个用来接收音频流采样率的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。 |

### OH_AudioCapturer_GetChannelCount()

```c
OH_AudioStream_Result OH_AudioCapturer_GetChannelCount(OH_AudioCapturer* capturer, int32_t* channelCount)
```

**描述**

查询当前音频流通道数。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| int32_t* channelCount | 指向一个用来接收音频流通道数的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。 |

### OH_AudioCapturer_GetSampleFormat()

```c
OH_AudioStream_Result OH_AudioCapturer_GetSampleFormat(OH_AudioCapturer* capturer,OH_AudioStream_SampleFormat* sampleFormat)
```

**描述**

查询当前输入音频流采样格式。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| [OH_AudioStream_SampleFormat](capi-native-audiostream-base-h.md#oh_audiostream_sampleformat)* sampleFormat | 指向一个用来接收音频流采样格式的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。 |

### OH_AudioCapturer_GetEncodingType()

```c
OH_AudioStream_Result OH_AudioCapturer_GetEncodingType(OH_AudioCapturer* capturer,OH_AudioStream_EncodingType* encodingType)
```

**描述**

查询当前音频流编码类型。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| [OH_AudioStream_EncodingType](capi-native-audiostream-base-h.md#oh_audiostream_encodingtype)* encodingType | 指向一个用来接收音频流编码类型的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。 |

### OH_AudioCapturer_GetCapturerInfo()

```c
OH_AudioStream_Result OH_AudioCapturer_GetCapturerInfo(OH_AudioCapturer* capturer,OH_AudioStream_SourceType* sourceType)
```

**描述**

查询当前音频流工作场景类型。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| [OH_AudioStream_SourceType](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype)* sourceType | 指向一个用来接收输入类型音频流的工作场景的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。 |

### OH_AudioCapturer_GetFrameSizeInCallback()

```c
OH_AudioStream_Result OH_AudioCapturer_GetFrameSizeInCallback(OH_AudioCapturer* capturer,int32_t* frameSize)
```

**描述**

查询回调帧数。frameSize表示每次回调对应的采样帧数。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| int32_t* frameSize | 指向将为采样帧数设置的变量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。 |

### OH_AudioCapturer_GetTimestamp()

```c
OH_AudioStream_Result OH_AudioCapturer_GetTimestamp(OH_AudioCapturer* capturer, clockid_t clockId,int64_t* framePosition, int64_t* timestamp)
```

**描述**

获取输入音频流时间戳和当前数据帧位置信息。<br> 该接口可以获取到音频通道实际录制位置（framePosition）以及录制到该位置时的时间戳（timestamp），时间戳单位为纳秒。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| clockid_t clockId | 时钟标识符，使用CLOCK_MONOTONIC。 |
| int64_t* framePosition | 指向要接收位置的变量的指针。 |
| int64_t* timestamp | 指向接收时间戳的变量的指针，单位为纳秒。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：<br>                                                 1. 参数capturer为nullptr；<br>                                                 2. 参数clockId无效。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。 |

### OH_AudioCapturer_GetFramesRead()

```c
OH_AudioStream_Result OH_AudioCapturer_GetFramesRead(OH_AudioCapturer* capturer, int64_t* frames)
```

**描述**

查询自创建流以来已读取的帧数。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| int64_t* frames | 指向将为帧计数设置的变量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。 |

### OH_AudioCapturer_SetMuteHint()

```c
OH_AudioStream_Result OH_AudioCapturer_SetMuteHint(OH_AudioCapturer* capturer, bool mute)
```

**描述**

应用将当前录音流的自身静音状态传递给系统音频模块。该接口用于向系统音频模块上报应用自身的静音状态，不会改变录音流的实际静音状态。当前仅在部分PC/2in1设备上，系统音频模块会基于设置的状态调整策略以降低功耗。该接口仅在录音流处于运行态时允许调用，否则返回错误AUDIOSTREAM_ERROR_ILLEGAL_STATE。同一录音流同时设置流级静音提示接口（本接口）和会话级静音提示接口时，流级（本接口）优先级更高，数值以流级（本接口）设置值为准。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| OH_AudioCapturer* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| bool mute | 应用向系统音频模块上报的自身静音状态，作用于第一个参数`capturer`指定的录制流实例。true表示上报该录制流为静音状态，false表示上报该录制流为非静音状态。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AudioStream_Result | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：操作状态异常，录音流未处于running状态。<br>         AUDIOSTREAM_ERROR_SYSTEM：系统异常，例如系统服务异常退出等。 |

### OH_AudioCapturer_GetOverflowCount()

```c
OH_AudioStream_Result OH_AudioCapturer_GetOverflowCount(OH_AudioCapturer* capturer, uint32_t* count)
```

**描述**

查询当前录制音频流过载数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| uint32_t* count | 指向一个用来接收音频流过载数的变量的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。 |

### OH_AudioCapturer_OnReadDataCallback()

```c
typedef void (*OH_AudioCapturer_OnReadDataCallback)(OH_AudioCapturer* capturer, void* userData, void* audioData,int32_t audioDataSize)
```

**描述**

读取音频数据的回调函数。为了消除麦克风硬件设计带来的上电杂音，通常会对录音启动后的前100ms数据进行静音。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
|  void* userData | 指向应用自定义的数据存储区域，方便应用给自身传递数据。 |
|  void* audioData | 指向录制数据存储区域，用于应用读取录制数据。 |
| int32_t audioDataSize | 录制数据的长度，单位为字节。 |

### OH_AudioCapturer_OnDeviceChangeCallback()

```c
typedef void (*OH_AudioCapturer_OnDeviceChangeCallback)(OH_AudioCapturer* capturer, void* userData,OH_AudioDeviceDescriptorArray* deviceArray)
```

**描述**

音频录制流的设备变化事件回调函数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
|  void* userData | 指向应用自定义的数据存储区域。 |
| [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md)* deviceArray | 音频设备描述符数组。 |

### OH_AudioCapturer_OnInterruptCallback()

```c
typedef void (*OH_AudioCapturer_OnInterruptCallback)(OH_AudioCapturer* capturer, void* userData,OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)
```

**描述**

音频录制流的中断事件回调函数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
|  void* userData | 指向应用自定义的数据存储区域。 |
| [OH_AudioInterrupt_ForceType](capi-native-audiostream-base-h.md#oh_audiointerrupt_forcetype) type | 音频流中断类型。 |
|  [OH_AudioInterrupt_Hint](capi-native-audiostream-base-h.md#oh_audiointerrupt_hint) hint | 音频流中断提示类型。 |

### OH_AudioCapturer_OnErrorCallback()

```c
typedef void (*OH_AudioCapturer_OnErrorCallback)(OH_AudioCapturer* capturer, void* userData,OH_AudioStream_Result error)
```

**描述**

音频录制流的错误事件回调函数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
|  void* userData | 指向应用自定义的数据存储区域。 |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) error | 音频流录制错误结果。 |

### OH_AudioCapturer_GetFastStatus()

```c
OH_AudioStream_Result OH_AudioCapturer_GetFastStatus(OH_AudioCapturer* capturer,OH_AudioStream_FastStatus* status)
```

**描述**

获取音频录制过程中的运行状态，是否在低时延状态下工作。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| [OH_AudioStream_FastStatus](capi-native-audiostream-base-h.md#oh_audiostream_faststatus)* status | 指向接收低时延状态的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常，仅在释放状态之前可用。 |

### OH_AudioCapturer_OnFastStatusChange()

```c
typedef void (*OH_AudioCapturer_OnFastStatusChange)(OH_AudioCapturer* capturer,void* userData,OH_AudioStream_FastStatus status)
```

**描述**

音频录制过程中低时延状态改变事件的回调函数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| void* userData | 指向应用自定义的数据存储区域。 |
| [OH_AudioStream_FastStatus](capi-native-audiostream-base-h.md#oh_audiostream_faststatus) status | 返回当前低时延状态。 |

### OH_AudioCapturer_OnPlaybackCaptureStartCallback()

```c
typedef void (*OH_AudioCapturer_OnPlaybackCaptureStartCallback)(OH_AudioCapturer* capturer, void* userData, OH_AudioStream_PlaybackCaptureStartState state)
```

**描述**

音频录制过程中用于内录（录制的是设备内部应用的声音）启动结果的回调函数。该API暂不对外支持。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| void\* userData | 通过[OH_AudioCapturer_RequestPlaybackCaptureStart](capi-native-audiocapturer-h.md#oh_audiocapturer_requestplaybackcapturestart)指向应用自定义的数据存储区域。 |
| [OH_AudioStream_PlaybackCaptureStartState](capi-native-audiostream-base-h.md#oh_audiostream_playbackcapturestartstate) state | 表示内录请求是否成功的状态。 |

### OH_AudioCapturer_RequestPlaybackCaptureStart()

```c
OH_AudioStream_Result OH_AudioCapturer_RequestPlaybackCaptureStart(OH_AudioCapturer* capturer, OH_AudioCapturer_OnPlaybackCaptureStartCallback callback, void* userData)
```

**描述**

异步请求启动内录流。该函数是非阻塞的，意味着系统在接收到启动请求后，将继续处理用户授权和内录流的启动。<br> 最终结果将通过回调函数返回。该API暂不对外支持。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| [OH_AudioCapturer_OnPlaybackCaptureStartCallback](capi-native-audiocapturer-h.md#oh_audiocapturer_onplaybackcapturestartcallback) callback | 用于接收启动请求最终结果的回调函数。 |
| void* userData | 指向应用自定义的数据存储区域，该结构将传递给回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：capturer或callback是无效的。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：如果流已经在运行中或者已释放则是非法状态。<br>         AUDIOSTREAM_ERROR_SYSTEM：系统内部错误，比如音频服务错误。 |

### OH_AudioCapturer_SetIndependentAudioSessionStrategy()

```c
OH_AudioStream_Result OH_AudioCapturer_SetIndependentAudioSessionStrategy(OH_AudioCapturer* capturer, const OH_AudioSession_Strategy* strategy, uint32_t behavior)
```

**描述**

设置独立的音频会话策略和行为参数。当音频采集器在运行状态时调用此接口后，必须重新调用接口[OH_AudioCapturer_Start](capi-native-audiocapturer-h.md#oh_audiocapturer_start)使其生效。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| [const OH_AudioSession_Strategy](capi-ohaudio-oh-audiosession-strategy.md)* strategy | 用于设置独立的音频会话策略。 |
| uint32_t behavior | 音频会话行为标志，可以是单个标志，也可以是多个标志的按位OR组合。当前支持的音频会话行为详见[OH_AudioSession_BehaviorFlags](capi-native-audio-session-base-h.md#oh_audiosession_behaviorflags)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数为空指针或超出范围。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：执行状态异常。 |

### OH_AudioCapturer_SetNoiseReductionMode()

```c
OH_AudioStream_Result OH_AudioCapturer_SetNoiseReductionMode(OH_AudioCapturer* capturer, OH_AudioNoiseReductionMode noiseReductionMode)
```

**描述**

设置当前录音流的降噪模式。建议先调用[OH_AudioCapturer_GetSupportedNoiseReductionModes](#oh_audiocapturer_getsupportednoisereductionmodes)获取当前录音流支持的降噪模式后，再通过本接口进行设置。

当前仅支持使用[AUDIOSTREAM_SOURCE_TYPE_VOICE_MESSAGE](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype)创建的录音流进行降噪模式设置，其他录音流默认仅支持[AUDIO_NOISE_REDUCTION_MODE_FIDELITY](capi-native-audio-common-h.md#oh_audionoisereductionmode)。降噪效果受设备平台、音频设备和录音并发情况影响。存在多个录音流同时运行时，设置的降噪模式可能不生效。

该接口仅可在录音流创建后未开始录音，或停止录音后调用；录音流处于运行态或已释放时调用将返回[AUDIOSTREAM_ERROR_ILLEGAL_STATE](capi-native-audiostream-base-h.md#oh_audiostream_result)。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| [OH_AudioNoiseReductionMode](capi-native-audio-common-h.md#oh_audionoisereductionmode) noiseReductionMode | 要设置的降噪模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr，或参数noiseReductionMode无效。<br>         AUDIOSTREAM_ERROR_ILLEGAL_STATE：录音流处于运行态或已释放。<br>         AUDIOSTREAM_ERROR_UNSUPPORTED_ABILITY：设置的降噪模式不支持。<br>         AUDIOSTREAM_ERROR_SERVICE_DIED：音频服务进程异常结束。 |

### OH_AudioCapturer_GetNoiseReductionMode()

```c
OH_AudioStream_Result OH_AudioCapturer_GetNoiseReductionMode(OH_AudioCapturer* capturer, OH_AudioNoiseReductionMode* noiseReductionMode)
```

**描述**

获取当前录音流的降噪模式。返回结果仅反映当前录音流的降噪模式。默认值为[AUDIO_NOISE_REDUCTION_MODE_FIDELITY](capi-native-audio-common-h.md#oh_audionoisereductionmode)。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| [OH_AudioNoiseReductionMode](capi-native-audio-common-h.md#oh_audionoisereductionmode)* noiseReductionMode | 指向接收当前降噪模式的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr，或参数noiseReductionMode为nullptr。 |

### OH_AudioCapturer_GetSupportedNoiseReductionModes()

```c
OH_AudioStream_Result OH_AudioCapturer_GetSupportedNoiseReductionModes(OH_AudioCapturer* capturer, OH_AudioNoiseReductionMode* noiseReductionModeArray, uint32_t inModeArraySize, uint32_t *outModeArraySize)
```

**描述**

获取当前设备平台支持的录音降噪模式。当前仅使用[AUDIOSTREAM_SOURCE_TYPE_VOICE_MESSAGE](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype)创建的录音流会根据设备平台查询支持的降噪模式，其他录音流默认仅返回[AUDIO_NOISE_REDUCTION_MODE_FIDELITY](capi-native-audio-common-h.md#oh_audionoisereductionmode)。返回结果仅考虑音频格式和设备平台，不考虑当前输入设备和录音并发情况。

当支持的模式数量大于入参inModeArraySize时，仅向noiseReductionModeArray写入前inModeArraySize个模式，outModeArraySize等于inModeArraySize。建议应用预留较大的数组长度，例如20，以兼容后续新增模式。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| [OH_AudioNoiseReductionMode](capi-native-audio-common-h.md#oh_audionoisereductionmode)* noiseReductionModeArray | 指向应用分配的数组，用于接收支持的录音降噪模式，默认支持[AUDIO_NOISE_REDUCTION_MODE_FIDELITY](capi-native-audio-common-h.md#oh_audionoisereductionmode)。 |
| uint32_t inModeArraySize | noiseReductionModeArray数组的元素个数。 |
| uint32_t* outModeArraySize | 指向接收实际写入模式数量的变量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | AUDIOSTREAM_SUCCESS：函数执行成功。<br>         AUDIOSTREAM_ERROR_INVALID_PARAM：参数capturer为nullptr，或参数noiseReductionModeArray为nullptr，或参数outModeArraySize为nullptr。<br>         AUDIOSTREAM_ERROR_SERVICE_DIED：音频服务进程死亡。 |

### OH_AudioCapturer_SensitiveRecordPermitCallback()

```c
typedef void (*OH_AudioCapturer_SensitiveRecordPermitCallback)(OH_AudioCapturer* capturer, void* userData, bool isPermitted)
```

**描述**

蜂窝通话录音场景下，风险提示语播放结束的回调函数。应用必须等待回调返回许可结果，且isPermitted为true时，方可开始蜂窝通话录音。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | 指向[OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer)创建的音频流实例。 |
| void* userData | 通过[OH_AudioStreamBuilder_SetSensitiveRecordPermitCallback](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setsensitiverecordpermitcallback)指向应用自定义的数据存储区域。 |
| bool isPermitted | 表示风险提示语是否播放结束。若结果为true，表示可以开始录音；若为false，表示录音未被允许。 |


