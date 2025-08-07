# native_audiorenderer.h

## Overview

The file declares the functions related to an audio renderer.

**File to include**: <ohaudio/native_audiorenderer.h>

**Library**: libohaudio.so

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

**Related module**: [OHAudio](capi-ohaudio.md)

## Summary

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioStream_Result OH_AudioRenderer_Release(OH_AudioRenderer* renderer)](#oh_audiorenderer_release) | - | Releases an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_Start(OH_AudioRenderer* renderer)](#oh_audiorenderer_start) | - | Starts an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_Pause(OH_AudioRenderer* renderer)](#oh_audiorenderer_pause) | - | Pauses an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_Stop(OH_AudioRenderer* renderer)](#oh_audiorenderer_stop) | - | Stops an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_Flush(OH_AudioRenderer* renderer)](#oh_audiorenderer_flush) | - | Clears audio data in the buffer.|
| [OH_AudioStream_Result OH_AudioRenderer_GetCurrentState(OH_AudioRenderer* renderer,OH_AudioStream_State* state)](#oh_audiorenderer_getcurrentstate) | - | Obtains the state of an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_GetSamplingRate(OH_AudioRenderer* renderer, int32_t* rate)](#oh_audiorenderer_getsamplingrate) | - | Obtains the sampling rate of an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_GetStreamId(OH_AudioRenderer* renderer, uint32_t* streamId)](#oh_audiorenderer_getstreamid) | - | Obtains the stream ID of an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_GetChannelCount(OH_AudioRenderer* renderer, int32_t* channelCount)](#oh_audiorenderer_getchannelcount) | - | Obtains the number of channels for an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_GetSampleFormat(OH_AudioRenderer* renderer,OH_AudioStream_SampleFormat* sampleFormat)](#oh_audiorenderer_getsampleformat) | - | Obtains the sampling format of an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_GetLatencyMode(OH_AudioRenderer* renderer,OH_AudioStream_LatencyMode* latencyMode)](#oh_audiorenderer_getlatencymode) | - | Obtains the latency mode of an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_GetRendererInfo(OH_AudioRenderer* renderer,OH_AudioStream_Usage* usage)](#oh_audiorenderer_getrendererinfo) | - | Obtains the usage type of an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_GetEncodingType(OH_AudioRenderer* renderer,OH_AudioStream_EncodingType* encodingType)](#oh_audiorenderer_getencodingtype) | - | Obtains the encoding type of an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_GetFramesWritten(OH_AudioRenderer* renderer, int64_t* frames)](#oh_audiorenderer_getframeswritten) | - | Obtains the number of frames that have been written since the stream was created.|
| [OH_AudioStream_Result OH_AudioRenderer_GetTimestamp(OH_AudioRenderer* renderer, clockid_t clockId,int64_t* framePosition, int64_t* timestamp)](#oh_audiorenderer_gettimestamp) | - | Obtains the timestamp and position information of an output audio stream.<br>This function obtains the actual playback position (specified by **framePosition**) of the audio channel and the timestamp when playing to that position (specified by **timestamp**, in nanoseconds).<br>When you switch devices or resume playback after a pause, the playback position and timestamp retrieved via this function will temporarily stay in the state they were in before the switch or pause, since the playback channel requires a moment to stabilize. |
| [OH_AudioStream_Result OH_AudioRenderer_GetAudioTimestampInfo(OH_AudioRenderer* renderer,int64_t* framePosition, int64_t* timestamp)](#oh_audiorenderer_getaudiotimestampinfo) | - | Obtains the timestamp and position information of an output audio stream. It adapts to the speed adjustment interface.<br>This information is commonly used for audio and video synchronization. |
| [OH_AudioStream_Result OH_AudioRenderer_GetFrameSizeInCallback(OH_AudioRenderer* renderer, int32_t* frameSize)](#oh_audiorenderer_getframesizeincallback) | - | Obtains the frame size in the callback. The frame size is the fixed length of the buffer returned by each callback.|
| [OH_AudioStream_Result OH_AudioRenderer_GetSpeed(OH_AudioRenderer* renderer, float* speed)](#oh_audiorenderer_getspeed) | - | Obtains the rate of an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_SetSpeed(OH_AudioRenderer* renderer, float speed)](#oh_audiorenderer_setspeed) | - | Sets the rate for an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_SetMarkPosition(OH_AudioRenderer* renderer, uint32_t samplePos,OH_AudioRenderer_OnMarkReachedCallback callback, void* userData)](#oh_audiorenderer_setmarkposition) | - | Sets the mark position for an audio renderer. When this function is called, the mark position that has been set will be overwritten.|
| [OH_AudioStream_Result OH_AudioRenderer_CancelMark(OH_AudioRenderer* renderer)](#oh_audiorenderer_cancelmark) | - | Cancels the mark set by [OH_AudioRenderer_SetMarkPosition](#oh_audiorenderer_setmarkposition).|
| [OH_AudioStream_Result OH_AudioRenderer_SetVolume(OH_AudioRenderer* renderer, float volume)](#oh_audiorenderer_setvolume) | - | Sets the volume for an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_SetVolumeWithRamp(OH_AudioRenderer* renderer, float volume, int32_t durationMs)](#oh_audiorenderer_setvolumewithramp) | - | Sets the volume with a ramp within the specified duration for an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_GetVolume(OH_AudioRenderer* renderer, float* volume)](#oh_audiorenderer_getvolume) | - | Obtains the volume of an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_GetUnderflowCount(OH_AudioRenderer* renderer, uint32_t* count)](#oh_audiorenderer_getunderflowcount) | - | Obtains the number of underloaded audio streams of an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_GetChannelLayout(OH_AudioRenderer* renderer,OH_AudioChannelLayout* channelLayout)](#oh_audiorenderer_getchannellayout) | - | Obtains the channel layout of an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_GetEffectMode(OH_AudioRenderer* renderer,OH_AudioStream_AudioEffectMode* effectMode)](#oh_audiorenderer_geteffectmode) | - | Obtains the effect mode of an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_SetEffectMode(OH_AudioRenderer* renderer,OH_AudioStream_AudioEffectMode effectMode)](#oh_audiorenderer_seteffectmode) | - | Sets the effect mode for an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_GetRendererPrivacy(OH_AudioRenderer* renderer,OH_AudioStream_PrivacyType* privacy)](#oh_audiorenderer_getrendererprivacy) | - | Checks whether the audio stream being played can be recorded by other applications.|
| [OH_AudioStream_Result OH_AudioRenderer_SetSilentModeAndMixWithOthers(OH_AudioRenderer* renderer, bool on)](#oh_audiorenderer_setsilentmodeandmixwithothers) | - | Sets the silent mode in concurrent playback for an audio renderer.<br>If the silent mode in concurrent playback is enabled, the system mutes the audio stream and does not interrupt other audio streams. If the silent mode in concurrent playback is disabled, the audio stream can gain focus based on the system focus policy. |
| [OH_AudioStream_Result OH_AudioRenderer_GetSilentModeAndMixWithOthers(OH_AudioRenderer* renderer, bool* on)](#oh_audiorenderer_getsilentmodeandmixwithothers) | - | Checks whether the silent mode in concurrent playback is enabled for an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_SetDefaultOutputDevice(OH_AudioRenderer* renderer, OH_AudioDevice_Type deviceType)](#oh_audiorenderer_setdefaultoutputdevice) | - | Sets the default built-in audio output device.<br>This function applies only to the scenario where [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage) is set to voice messages, VoIP voice calls, and VoIP video calls and the available device types are the receiver, speaker, and system default device.<br>This function can be called at any time after an AudioRenderer instance is created. The system records the default built-in audio output device set by the application. When the application is started, if an external device such as a Bluetooth or wired headset is connected, the system preferentially uses the external device to play sound. Otherwise, the system uses this default device to play sound.<br> |
| [typedef void (\*OH_AudioRenderer_OnInterruptCallback)(OH_AudioRenderer* renderer, void* userData,OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)](#oh_audiorenderer_oninterruptcallback) | OH_AudioRenderer_OnInterruptCallback | Defines the callback for interruption events of an audio renderer.|
| [typedef void (\*OH_AudioRenderer_OnErrorCallback)(OH_AudioRenderer* renderer, void* userData,OH_AudioStream_Result error)](#oh_audiorenderer_onerrorcallback) | OH_AudioRenderer_OnErrorCallback | Defines the callback for error events of an audio renderer.|
| [OH_AudioStream_Result OH_AudioRenderer_GetFastStatus(OH_AudioRenderer* renderer,OH_AudioStream_FastStatus* status)](#oh_audiorenderer_getfaststatus) | - | Obtains the running status of an audio renderer to determine whether it is running in low-latency mode.|
| [typedef void (\*OH_AudioRenderer_OnFastStatusChange)(OH_AudioRenderer* renderer,void* userData,OH_AudioStream_FastStatus status)](#oh_audiorenderer_onfaststatuschange) | OH_AudioRenderer_OnFastStatusChange | Defines a callback function for low-latency status changes during audio playback.|
| [OH_AudioStream_Result OH_AudioRenderer_SetLoudnessGain(OH_AudioRenderer* renderer, float loudnessGain)](#oh_audiorenderer_setloudnessgain) | - | Sets the loudness of audio playback. The default loudness value is 0.0 dB. The audio stream playback type must be one of the following: Music: [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_MUSIC<br>Movies or videos: [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_MUSIC<br>Audiobooks (including books, crosstalk, and storytelling), listening to news, podcasts, and others: [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_AUDIOBOOK<br>The latency mode of the audio stream must be [OH_AudioStream_LatencyMode](capi-native-audiostream-base-h.md#oh_audiostream_latencymode).AUDIOSTREAM_LATENCY_MODE_NORMAL.<br>Loudness settings are not supported for high-definition audio channels.<br>Due to the buffer between the audio framework and hardware, there may be a delay in the actual effect of loudness adjustment. The delay duration depends on the buffer length.<br>You are advised to set the loudness before starting playback of different audio streams to achieve the optimal balance effect. |
| [OH_AudioStream_Result OH_AudioRenderer_GetLoudnessGain(OH_AudioRenderer* renderer, float* loudnessGain)](#oh_audiorenderer_getloudnessgain) | - | Obtains the loudness of audio playback.|

## Function Description

### OH_AudioRenderer_Release()

```
OH_AudioStream_Result OH_AudioRenderer_Release(OH_AudioRenderer* renderer)
```

**Description**

Releases an audio renderer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal. |

### OH_AudioRenderer_Start()

```
OH_AudioStream_Result OH_AudioRenderer_Start(OH_AudioRenderer* renderer)
```

**Description**

Starts an audio renderer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal. |

### OH_AudioRenderer_Pause()

```
OH_AudioStream_Result OH_AudioRenderer_Pause(OH_AudioRenderer* renderer)
```

**Description**

Pauses an audio renderer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal. |

### OH_AudioRenderer_Stop()

```
OH_AudioStream_Result OH_AudioRenderer_Stop(OH_AudioRenderer* renderer)
```

**Description**

Stops an audio renderer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal. |

### OH_AudioRenderer_Flush()

```
OH_AudioStream_Result OH_AudioRenderer_Flush(OH_AudioRenderer* renderer)
```

**Description**

Clears audio data in the buffer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal. |

### OH_AudioRenderer_GetCurrentState()

```
OH_AudioStream_Result OH_AudioRenderer_GetCurrentState(OH_AudioRenderer* renderer,OH_AudioStream_State* state)
```

**Description**

Obtains the state of an audio renderer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| [OH_AudioStream_State](capi-native-audiostream-base-h.md#oh_audiostream_state)* state | Pointer to a variable used to receive the state.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_GetSamplingRate()

```
OH_AudioStream_Result OH_AudioRenderer_GetSamplingRate(OH_AudioRenderer* renderer, int32_t* rate)
```

**Description**

Obtains the sampling rate of an audio renderer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| int32_t* rate | Pointer to a variable used to receive the sampling rate.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_GetStreamId()

```
OH_AudioStream_Result OH_AudioRenderer_GetStreamId(OH_AudioRenderer* renderer, uint32_t* streamId)
```

**Description**

Obtains the stream ID of an audio renderer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| uint32_t* streamId | Pointer to a variable used to receive the stream ID.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_GetChannelCount()

```
OH_AudioStream_Result OH_AudioRenderer_GetChannelCount(OH_AudioRenderer* renderer, int32_t* channelCount)
```

**Description**

Obtains the number of channels for an audio renderer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| int32_t* channelCount | Pointer to a variable used to receive the channel count.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_GetSampleFormat()

```
OH_AudioStream_Result OH_AudioRenderer_GetSampleFormat(OH_AudioRenderer* renderer,OH_AudioStream_SampleFormat* sampleFormat)
```

**Description**

Obtains the sampling format of an audio renderer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| [OH_AudioStream_SampleFormat](capi-native-audiostream-base-h.md#oh_audiostream_sampleformat)* sampleFormat | Pointer to a variable used to receive the sampling format.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_GetLatencyMode()

```
OH_AudioStream_Result OH_AudioRenderer_GetLatencyMode(OH_AudioRenderer* renderer,OH_AudioStream_LatencyMode* latencyMode)
```

**Description**

Obtains the latency mode of an audio renderer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| [OH_AudioStream_LatencyMode](capi-native-audiostream-base-h.md#oh_audiostream_latencymode)* latencyMode | Pointer to a variable used to receive the latency mode.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_GetRendererInfo()

```
OH_AudioStream_Result OH_AudioRenderer_GetRendererInfo(OH_AudioRenderer* renderer,OH_AudioStream_Usage* usage)
```

**Description**

Obtains the usage type of an audio renderer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage)* usage | Pointer to a variable used to receive the usage type.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_GetEncodingType()

```
OH_AudioStream_Result OH_AudioRenderer_GetEncodingType(OH_AudioRenderer* renderer,OH_AudioStream_EncodingType* encodingType)
```

**Description**

Obtains the encoding type of an audio renderer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| [OH_AudioStream_EncodingType](capi-native-audiostream-base-h.md#oh_audiostream_encodingtype)* encodingType | Pointer to a variable used to receive the encoding type.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_GetFramesWritten()

```
OH_AudioStream_Result OH_AudioRenderer_GetFramesWritten(OH_AudioRenderer* renderer, int64_t* frames)
```

**Description**

Obtains the number of frames that have been written since the stream was created.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| int64_t* frames | Pointer to a variable used to receive the frame count.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_GetTimestamp()

```
OH_AudioStream_Result OH_AudioRenderer_GetTimestamp(OH_AudioRenderer* renderer, clockid_t clockId,int64_t* framePosition, int64_t* timestamp)
```

**Description**

Obtains the timestamp and position information of an output audio stream.

This function obtains the actual playback position (specified by **framePosition**) of the audio channel and the timestamp when playing to that position (specified by **timestamp**, in nanoseconds).

When you switch devices or resume playback after a pause, the playback position and timestamp retrieved via this function will temporarily stay in the state they were in before the switch or pause, since the playback channel requires a moment to stabilize.

This function is used to implement audio and video synchronization. It is recommended that the function be called once every minute (at least every 200 ms). Frequent calls may increase power consumption. Therefore, do not frequently query the timestamp when the audio-visual synchronization effect can be ensured.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| clockid_t clockId | Clock identifier. Use **CLOCK_MONOTONIC**.|
| int64_t* framePosition | Pointer to a variable used to receive the position information.|
| int64_t* timestamp | Pointer to a variable used to receive the timestamp.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **renderer** parameter is nullptr.<br>2. The **clockId** parameter is set to an invalid value.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal. |

### OH_AudioRenderer_GetAudioTimestampInfo()

```
OH_AudioStream_Result OH_AudioRenderer_GetAudioTimestampInfo(OH_AudioRenderer* renderer,int64_t* framePosition, int64_t* timestamp)
```

**Description**

Obtains the timestamp and position information of an output audio stream. It adapts to the speed adjustment interface.

This information is commonly used for audio and video synchronization.

Note that when the actual playback position (**framePosition**) is 0, the timestamp remains fixed until the stream begins to play. The playback position is also reset when **Flush** is called.

Additionally, changes in the audio stream route, such as switching devices or output types, will reset the playback position, whereas the timestamp keeps increasing. You are advised to call this function to obtain the corresponding value only when the actual playback position and timestamp are stable. This function adapts to the speed adjustment interface. For example, if the playback speed is set to 2x, the rate at which the playback position increases is also twice the normal speed.

**Since**: 15


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| int64_t* framePosition | Pointer to a variable used to receive the position information.|
| int64_t* timestamp | Pointer to a variable used to receive the timestamp.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **renderer** parameter is nullptr.<br>2. The **framePosition** or **timestamp** parameter is nullptr.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The current stream status is invalid.<br>**AUDIOSTREAM_ERROR_SYSTEM**:<br>1. The system process breaks down or is blocked.<br>2. An internal system error occurs. |

### OH_AudioRenderer_GetFrameSizeInCallback()

```
OH_AudioStream_Result OH_AudioRenderer_GetFrameSizeInCallback(OH_AudioRenderer* renderer, int32_t* frameSize)
```

**Description**

Obtains the frame size in the callback. The frame size is the fixed length of the buffer returned by each callback.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| int32_t* frameSize | Pointer to a variable used to receive the frame size.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_GetSpeed()

```
OH_AudioStream_Result OH_AudioRenderer_GetSpeed(OH_AudioRenderer* renderer, float* speed)
```

**Description**

Obtains the rate of an audio renderer.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| float* speed | Pointer to the variable that receives the playback rate.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_SetSpeed()

```
OH_AudioStream_Result OH_AudioRenderer_SetSpeed(OH_AudioRenderer* renderer, float speed)
```

**Description**

Sets the rate for an audio renderer.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| float speed | Playback rate, which ranges from 0.25 to 4.0.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_SetMarkPosition()

```
OH_AudioStream_Result OH_AudioRenderer_SetMarkPosition(OH_AudioRenderer* renderer, uint32_t samplePos,OH_AudioRenderer_OnMarkReachedCallback callback, void* userData)
```

**Description**

Sets the mark position for an audio renderer. When this function is called, the mark position that has been set will be overwritten.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| uint32_t samplePos | Mark position.|
| [OH_AudioRenderer_OnMarkReachedCallback](capi-native-audiostream-base-h.md#oh_audiorenderer_onmarkreachedcallback) callback | Callback invoked when the target mark position is reached.|
| void* userData | Pointer to the application data passed through the callbacks.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **renderer** parameter is nullptr.<br>2. The **samplePos** parameter is set to an invalid value.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.<br>**AUDIOSTREAM_ERROR_SYSTEM**: A system error occurs. |

### OH_AudioRenderer_CancelMark()

```
OH_AudioStream_Result OH_AudioRenderer_CancelMark(OH_AudioRenderer* renderer)
```

**Description**

Cancels the mark set by [OH_AudioRenderer_SetMarkPosition](#oh_audiorenderer_setmarkposition).

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_SetVolume()

```
OH_AudioStream_Result OH_AudioRenderer_SetVolume(OH_AudioRenderer* renderer, float volume)
```

**Description**

Sets the volume for an audio renderer.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| float volume | Target volume, in the range of [0.0, 1.0].|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **renderer** parameter is nullptr.<br>2. The **volume** parameter is set to an invalid value.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.<br>**AUDIOSTREAM_ERROR_SYSTEM**: A system error occurs. |

### OH_AudioRenderer_SetVolumeWithRamp()

```
OH_AudioStream_Result OH_AudioRenderer_SetVolumeWithRamp(OH_AudioRenderer* renderer, float volume, int32_t durationMs)
```

**Description**

Sets the volume with a ramp within the specified duration for an audio renderer.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| float volume | Target volume, in the range of [0.0, 1.0].|
| int32_t durationMs | Duration, in milliseconds.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **renderer** parameter is nullptr.<br>2. The **volume** parameter is set to an invalid value.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.<br>**AUDIOSTREAM_ERROR_SYSTEM**: A system error occurs. |

### OH_AudioRenderer_GetVolume()

```
OH_AudioStream_Result OH_AudioRenderer_GetVolume(OH_AudioRenderer* renderer, float* volume)
```

**Description**

Obtains the volume of an audio renderer.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| float* volume | Pointer to the audio volume, in the range of [0.0, 1.0].|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **renderer** parameter is nullptr.<br>2. The **volume** parameter is nullptr. |

### OH_AudioRenderer_GetUnderflowCount()

```
OH_AudioStream_Result OH_AudioRenderer_GetUnderflowCount(OH_AudioRenderer* renderer, uint32_t* count)
```

**Description**

Obtains the number of underloaded audio streams of an audio renderer.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| uint32_t* count | Pointer to a variable used to receive the number of underloaded audio streams.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **renderer** parameter is nullptr.<br>2. The **count** parameter is nullptr. |

### OH_AudioRenderer_GetChannelLayout()

```
OH_AudioStream_Result OH_AudioRenderer_GetChannelLayout(OH_AudioRenderer* renderer,OH_AudioChannelLayout* channelLayout)
```

**Description**

Obtains the channel layout of an audio renderer.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| [OH_AudioChannelLayout](../apis-avcodec-kit/_core.md#oh_audiochannellayout-1)* channelLayout | Pointer to a variable used to receive the channel layout.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_GetEffectMode()

```
OH_AudioStream_Result OH_AudioRenderer_GetEffectMode(OH_AudioRenderer* renderer,OH_AudioStream_AudioEffectMode* effectMode)
```

**Description**

Obtains the effect mode of an audio renderer.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| [OH_AudioStream_AudioEffectMode](capi-native-audiostream-base-h.md#oh_audiostream_audioeffectmode)* effectMode | Pointer to a variable used to receive the effect mode.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_SetEffectMode()

```
OH_AudioStream_Result OH_AudioRenderer_SetEffectMode(OH_AudioRenderer* renderer,OH_AudioStream_AudioEffectMode effectMode)
```

**Description**

Sets the effect mode for an audio renderer.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| [OH_AudioStream_AudioEffectMode](capi-native-audiostream-base-h.md#oh_audiostream_audioeffectmode) effectMode | Effect mode to set.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_GetRendererPrivacy()

```
OH_AudioStream_Result OH_AudioRenderer_GetRendererPrivacy(OH_AudioRenderer* renderer,OH_AudioStream_PrivacyType* privacy)
```

**Description**

Checks whether the audio stream being played can be recorded by other applications.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| [OH_AudioStream_PrivacyType](capi-native-audiostream-base-h.md#oh_audiostream_privacytype)* privacy | Pointer to the privacy type, which specifies whether the audio stream being played can be recorded by other applications.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_SetSilentModeAndMixWithOthers()

```
OH_AudioStream_Result OH_AudioRenderer_SetSilentModeAndMixWithOthers(OH_AudioRenderer* renderer, bool on)
```

**Description**

Sets the silent mode in concurrent playback for an audio renderer.

If the silent mode in concurrent playback is enabled, the system mutes the audio stream and does not interrupt other audio streams. If the silent mode in concurrent playback is disabled, the audio stream can gain focus based on the system focus policy.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| bool on | Status of the silent mode in concurrent playback.<br>The value **true** means that the audio stream being played is muted and the playback of other audio streams is not interrupted.<br>The value **false** means that the audio stream being played is unmuted and can gain focus based on the system focus policy. |

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_GetSilentModeAndMixWithOthers()

```
OH_AudioStream_Result OH_AudioRenderer_GetSilentModeAndMixWithOthers(OH_AudioRenderer* renderer, bool* on)
```

**Description**

Checks whether the silent mode in concurrent playback is enabled for an audio renderer.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| bool* on | Whether the silent mode in concurrent playback is enabled. The value **true** means that the silent mode in concurrent playback is enabled, and **false** means the opposite.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr. |

### OH_AudioRenderer_SetDefaultOutputDevice()

```
OH_AudioStream_Result OH_AudioRenderer_SetDefaultOutputDevice(OH_AudioRenderer* renderer, OH_AudioDevice_Type deviceType)
```

**Description**

Sets the default built-in audio output device.

This function applies only to the scenario where [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage) is set to voice messages, VoIP voice calls, and VoIP video calls and the available device types are the receiver, speaker, and system default device.

This function can be called at any time after an AudioRenderer instance is created. The system records the default built-in audio output device set by the application. When the application is started, if an external device such as a Bluetooth or wired headset is connected, the system preferentially uses the external device to play sound. Otherwise, the system uses this default device to play sound.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| [OH_AudioDevice_Type](capi-native-audio-device-base-h.md#oh_audiodevice_type) deviceType | Device type. For details about the available options, see [OH_AudioDevice_Type](capi-native-audio-device-base-h.md#oh_audiodevice_type). The device types that can be set are as follows:<br>**AUDIO_DEVICE_TYPE_EARPIECE**: receiver.<br>**AUDIO_DEVICE_TYPE_SPEAKER**: speaker.<br>**AUDIO_DEVICE_TYPE_DEFAULT**: system default device. |

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **renderer** parameter is nullptr.<br>2. The **deviceType** parameter is set to an invalid value.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.<br>**AUDIOSTREAM_ERROR_SYSTEM**: A system error occurs. |

### OH_AudioRenderer_OnInterruptCallback()

```
typedef void (*OH_AudioRenderer_OnInterruptCallback)(OH_AudioRenderer* renderer, void* userData,OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)
```

**Description**

Defines the callback for interruption events of an audio renderer.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
|  void* userData | Pointer to the data storage area customized by the application.|
| [OH_AudioInterrupt_ForceType](capi-native-audiostream-base-h.md#oh_audiointerrupt_forcetype) type | Type of force that causes audio interruption.|
|  [OH_AudioInterrupt_Hint](capi-native-audiostream-base-h.md#oh_audiointerrupt_hint) hint | Hint provided along with audio interruption.|

### OH_AudioRenderer_OnErrorCallback()

```
typedef void (*OH_AudioRenderer_OnErrorCallback)(OH_AudioRenderer* renderer, void* userData,OH_AudioStream_Result error)
```

**Description**

Defines the callback for error events of an audio renderer.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
|  void* userData | Pointer to the data storage area customized by the application.|
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) error | Audio renderer error.|

### OH_AudioRenderer_GetFastStatus()

```
OH_AudioStream_Result OH_AudioRenderer_GetFastStatus(OH_AudioRenderer* renderer,OH_AudioStream_FastStatus* status)
```

**Description**

Obtains the running status of an audio renderer to determine whether it is running in low-latency mode.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| [OH_AudioStream_FastStatus](capi-native-audiostream-base-h.md#oh_audiostream_faststatus)* status | Pointer to the running status.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **renderer** parameter is nullptr.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The function is called in an incorrect state. |

### OH_AudioRenderer_OnFastStatusChange()

```
typedef void (*OH_AudioRenderer_OnFastStatusChange)(OH_AudioRenderer* renderer,void* userData,OH_AudioStream_FastStatus status)
```

**Description**

Defines a callback function for low-latency status changes during audio playback.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| void* userData | Pointer to the data storage area customized by the application.|
| status | Low-latency status.|

### OH_AudioRenderer_SetLoudnessGain()

```
OH_AudioStream_Result OH_AudioRenderer_SetLoudnessGain(OH_AudioRenderer* renderer, float loudnessGain)
```

**Description**

Sets the loudness of audio playback. The default loudness value is 0.0 dB.

The audio stream playback type must be one of the following: 

- Music: [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_MUSIC
- Movies or videos: [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_MUSIC
- Audiobooks (including books, crosstalk, and storytelling), listening to news, podcasts, and others: [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage).AUDIOSTREAM_USAGE_AUDIOBOOK

The latency mode of the audio stream must be [OH_AudioStream_LatencyMode](capi-native-audiostream-base-h.md#oh_audiostream_latencymode).AUDIOSTREAM_LATENCY_MODE_NORMAL.

Loudness settings are not supported for high-definition audio channels.

Due to the buffer between the audio framework and hardware, there may be a delay in the actual effect of loudness adjustment. The delay duration depends on the buffer length.

You are advised to set the loudness before starting playback of different audio streams to achieve the optimal balance effect.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| float loudnessGain | Loudness, in the range [-90.0, 24.0], in dB. |

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **renderer** parameter is nullptr, or audio streams do not support setting the loudness.<br>2. The **loudnessGain** parameter is not within the allowed range. |

### OH_AudioRenderer_GetLoudnessGain()

```
OH_AudioStream_Result OH_AudioRenderer_GetLoudnessGain(OH_AudioRenderer* renderer, float* loudnessGain)
```

**Description**

Obtains the loudness of audio playback.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| float* loudnessGain | Pointer to the variable that receives the loudness.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **renderer** parameter is nullptr.<br>2. The **loudnessGain** parameter is nullptr. |
