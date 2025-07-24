# native_audiocapturer.h

## Overview

The file declares the functions related to an audio capturer.

**File to include**: <ohaudio/native_audiocapturer.h>

**Library**: libohaudio.so

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

**Related module**: [OHAudio](capi-ohaudio.md)

## Summary

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioStream_Result OH_AudioCapturer_Release(OH_AudioCapturer* capturer)](#oh_audiocapturer_release) | - | Releases an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_Start(OH_AudioCapturer* capturer)](#oh_audiocapturer_start) | - | Starts an audio capturer to start capturing audio data.|
| [OH_AudioStream_Result OH_AudioCapturer_Pause(OH_AudioCapturer* capturer)](#oh_audiocapturer_pause) | - | Pauses an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_Stop(OH_AudioCapturer* capturer)](#oh_audiocapturer_stop) | - | Stops an audio capturer, ceasing the input audio stream.|
| [OH_AudioStream_Result OH_AudioCapturer_Flush(OH_AudioCapturer* capturer)](#oh_audiocapturer_flush) | - | Flushes audio data captured by an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetCurrentState(OH_AudioCapturer* capturer, OH_AudioStream_State* state)](#oh_audiocapturer_getcurrentstate) | - | Obtains the state of an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetLatencyMode(OH_AudioCapturer* capturer,OH_AudioStream_LatencyMode* latencyMode)](#oh_audiocapturer_getlatencymode) | - | Obtains the latency mode of an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetStreamId(OH_AudioCapturer* capturer, uint32_t* streamId)](#oh_audiocapturer_getstreamid) | - | Obtains the stream ID of an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetSamplingRate(OH_AudioCapturer* capturer, int32_t* rate)](#oh_audiocapturer_getsamplingrate) | - | Obtains the sampling rate of an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetChannelCount(OH_AudioCapturer* capturer, int32_t* channelCount)](#oh_audiocapturer_getchannelcount) | - | Obtains the number of channels for an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetSampleFormat(OH_AudioCapturer* capturer,OH_AudioStream_SampleFormat* sampleFormat)](#oh_audiocapturer_getsampleformat) | - | Obtains the sampling format of an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetEncodingType(OH_AudioCapturer* capturer,OH_AudioStream_EncodingType* encodingType)](#oh_audiocapturer_getencodingtype) | - | Obtains the encoding type of an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetCapturerInfo(OH_AudioCapturer* capturer,OH_AudioStream_SourceType* sourceType)](#oh_audiocapturer_getcapturerinfo) | - | Obtains the usage scenario of an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetFrameSizeInCallback(OH_AudioCapturer* capturer,int32_t* frameSize)](#oh_audiocapturer_getframesizeincallback) | - | Obtains the frame size in the callback. The frame size is the fixed length of the buffer returned by each callback.|
| [OH_AudioStream_Result OH_AudioCapturer_GetTimestamp(OH_AudioCapturer* capturer, clockid_t clockId,int64_t* framePosition, int64_t* timestamp)](#oh_audiocapturer_gettimestamp) | - | Obtains the information about the input audio stream timestamp and the current data frame position.<br>This function obtains the actual recording position (specified by **framePosition**) of the audio channel and the timestamp when recording to that position (specified by **timestamp**, in nanoseconds). |
| [OH_AudioStream_Result OH_AudioCapturer_GetFramesRead(OH_AudioCapturer* capturer, int64_t* frames)](#oh_audiocapturer_getframesread) | - | Obtains the number of frames that have been read since the stream was created.|
| [OH_AudioStream_Result OH_AudioCapturer_GetOverflowCount(OH_AudioCapturer* capturer, uint32_t* count)](#oh_audiocapturer_getoverflowcount) | - | Obtains the number of overloaded audio streams of an audio capturer.|
| [typedef void (\*OH_AudioCapturer_OnReadDataCallback)(OH_AudioCapturer* capturer, void* userData, void* audioData,int32_t audioDataSize)](#oh_audiocapturer_onreaddatacallback) | OH_AudioCapturer_OnReadDataCallback | Defines the callback used to read audio data.|
| [typedef void (\*OH_AudioCapturer_OnDeviceChangeCallback)(OH_AudioCapturer* capturer, void* userData,OH_AudioDeviceDescriptorArray* deviceArray)](#oh_audiocapturer_ondevicechangecallback) | OH_AudioCapturer_OnDeviceChangeCallback | Defines the callback for audio capturer device change events.|
| [typedef void (\*OH_AudioCapturer_OnInterruptCallback)(OH_AudioCapturer* capturer, void* userData,OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)](#oh_audiocapturer_oninterruptcallback) | OH_AudioCapturer_OnInterruptCallback | Defines the callback for interruption events of an audio capturer.|
| [typedef void (\*OH_AudioCapturer_OnErrorCallback)(OH_AudioCapturer* renderer, void* userData,OH_AudioStream_Result error)](#oh_audiocapturer_onerrorcallback) | OH_AudioCapturer_OnErrorCallback | Defines the callback for error events of an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetFastStatus(OH_AudioCapturer* capturer,OH_AudioStream_FastStatus* status)](#oh_audiocapturer_getfaststatus) | - | Obtains the running status of an audio capturer to determine whether it is running in low-latency mode.|
| [typedef void (\*OH_AudioCapturer_OnFastStatusChange)(OH_AudioCapturer* capturer,void* userData,OH_AudioStream_FastStatus status)](#oh_audiocapturer_onfaststatuschange) | OH_AudioCapturer_OnFastStatusChange | Defines a callback function for low-latency status changes during audio recording.|

## Function Description

### OH_AudioCapturer_Release()

```
OH_AudioStream_Result OH_AudioCapturer_Release(OH_AudioCapturer* capturer)
```

**Description**

Releases an audio capturer.

**Required permissions**: ohos.permission.MICROPHONE

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal. |

### OH_AudioCapturer_Start()

```
OH_AudioStream_Result OH_AudioCapturer_Start(OH_AudioCapturer* capturer)
```

**Description**

Starts an audio capturer to start capturing audio data.

**Required permissions**: ohos.permission.MICROPHONE

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal. |

### OH_AudioCapturer_Pause()

```
OH_AudioStream_Result OH_AudioCapturer_Pause(OH_AudioCapturer* capturer)
```

**Description**

Pauses an audio capturer.

**Required permissions**: ohos.permission.MICROPHONE

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal. |

### OH_AudioCapturer_Stop()

```
OH_AudioStream_Result OH_AudioCapturer_Stop(OH_AudioCapturer* capturer)
```

**Description**

Stops an audio capturer, ceasing the input audio stream.

**Required permissions**: ohos.permission.MICROPHONE

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal. |

### OH_AudioCapturer_Flush()

```
OH_AudioStream_Result OH_AudioCapturer_Flush(OH_AudioCapturer* capturer)
```

**Description**

Flushes audio data captured by an audio capturer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal. |

### OH_AudioCapturer_GetCurrentState()

```
OH_AudioStream_Result OH_AudioCapturer_GetCurrentState(OH_AudioCapturer* capturer, OH_AudioStream_State* state)
```

**Description**

Obtains the state of an audio capturer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| [OH_AudioStream_State](capi-native-audiostream-base-h.md#oh_audiostream_state)* state | Pointer to a variable used to receive the state.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr. |

### OH_AudioCapturer_GetLatencyMode()

```
OH_AudioStream_Result OH_AudioCapturer_GetLatencyMode(OH_AudioCapturer* capturer,OH_AudioStream_LatencyMode* latencyMode)
```

**Description**

Obtains the latency mode of an audio capturer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| [OH_AudioStream_LatencyMode](capi-native-audiostream-base-h.md#oh_audiostream_latencymode)* latencyMode | Pointer to a variable used to receive the latency mode.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr. |

### OH_AudioCapturer_GetStreamId()

```
OH_AudioStream_Result OH_AudioCapturer_GetStreamId(OH_AudioCapturer* capturer, uint32_t* streamId)
```

**Description**

Obtains the stream ID of an audio capturer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| uint32_t* streamId | Pointer to a variable used to receive the stream ID.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr. |

### OH_AudioCapturer_GetSamplingRate()

```
OH_AudioStream_Result OH_AudioCapturer_GetSamplingRate(OH_AudioCapturer* capturer, int32_t* rate)
```

**Description**

Obtains the sampling rate of an audio capturer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| int32_t* rate | Pointer to a variable used to receive the sampling rate.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr. |

### OH_AudioCapturer_GetChannelCount()

```
OH_AudioStream_Result OH_AudioCapturer_GetChannelCount(OH_AudioCapturer* capturer, int32_t* channelCount)
```

**Description**

Obtains the number of channels for an audio capturer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| int32_t* channelCount | Pointer to a variable used to receive the channel count.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr. |

### OH_AudioCapturer_GetSampleFormat()

```
OH_AudioStream_Result OH_AudioCapturer_GetSampleFormat(OH_AudioCapturer* capturer,OH_AudioStream_SampleFormat* sampleFormat)
```

**Description**

Obtains the sampling format of an audio capturer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| [OH_AudioStream_SampleFormat](capi-native-audiostream-base-h.md#oh_audiostream_sampleformat)* sampleFormat | Pointer to a variable used to receive the sampling format.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr. |

### OH_AudioCapturer_GetEncodingType()

```
OH_AudioStream_Result OH_AudioCapturer_GetEncodingType(OH_AudioCapturer* capturer,OH_AudioStream_EncodingType* encodingType)
```

**Description**

Obtains the encoding type of an audio capturer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| [OH_AudioStream_EncodingType](capi-native-audiostream-base-h.md#oh_audiostream_encodingtype)* encodingType | Pointer to a variable used to receive the encoding type.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr. |

### OH_AudioCapturer_GetCapturerInfo()

```
OH_AudioStream_Result OH_AudioCapturer_GetCapturerInfo(OH_AudioCapturer* capturer,OH_AudioStream_SourceType* sourceType)
```

**Description**

Obtains the usage scenario of an audio capturer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| [OH_AudioStream_SourceType](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype)* sourceType | Pointer to a variable used to receive the usage scenario.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr. |

### OH_AudioCapturer_GetFrameSizeInCallback()

```
OH_AudioStream_Result OH_AudioCapturer_GetFrameSizeInCallback(OH_AudioCapturer* capturer,int32_t* frameSize)
```

**Description**

Obtains the frame size in the callback. The frame size is the fixed length of the buffer returned by each callback.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| int32_t* frameSize | Pointer to a variable used to receive the frame size.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal. |

### OH_AudioCapturer_GetTimestamp()

```
OH_AudioStream_Result OH_AudioCapturer_GetTimestamp(OH_AudioCapturer* capturer, clockid_t clockId,int64_t* framePosition, int64_t* timestamp)
```

**Description**

Obtains the information about the input audio stream timestamp and the current data frame position.<br> This function obtains the actual recording position (specified by **framePosition**) of the audio channel and the timestamp when recording to that position (specified by **timestamp**, in nanoseconds).

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| clockid_t clockId | Clock identifier. Use **CLOCK_MONOTONIC**.|
| int64_t* framePosition | Pointer to a variable used to receive the position information.|
| int64_t* timestamp | Pointer to a variable used to receive the timestamp.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **capturer** parameter is nullptr.<br>2. The **clockId** parameter is invalid.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal. |

### OH_AudioCapturer_GetFramesRead()

```
OH_AudioStream_Result OH_AudioCapturer_GetFramesRead(OH_AudioCapturer* capturer, int64_t* frames)
```

**Description**

Obtains the number of frames that have been read since the stream was created.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| int64_t* frames | Pointer to a variable used to receive the frame count.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr. |

### OH_AudioCapturer_GetOverflowCount()

```
OH_AudioStream_Result OH_AudioCapturer_GetOverflowCount(OH_AudioCapturer* capturer, uint32_t* count)
```

**Description**

Obtains the number of overloaded audio streams of an audio capturer.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| uint32_t* count | Pointer to a variable used to receive the number of overloaded audio streams.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr. |

### OH_AudioCapturer_OnReadDataCallback()

```
typedef void (*OH_AudioCapturer_OnReadDataCallback)(OH_AudioCapturer* capturer, void* userData, void* audioData,int32_t audioDataSize)
```

**Description**

Defines the callback used to read audio data.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
|  void* userData | Pointer to the data storage area customized by the application.|
|  void* audioData | Pointer to the captured data storage area, which is used by the application to fill in captured data.|
| int32_t audioDataSize | Length of the captured data.|

### OH_AudioCapturer_OnDeviceChangeCallback()

```
typedef void (*OH_AudioCapturer_OnDeviceChangeCallback)(OH_AudioCapturer* capturer, void* userData,OH_AudioDeviceDescriptorArray* deviceArray)
```

**Description**

Defines the callback for audio capturer device change events.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
|  void* userData | Pointer to the data storage area customized by the application.|
| [OH_AudioDeviceDescriptorArray](capi-ohaudio-oh-audiodevicedescriptorarray.md)* deviceArray | Pointer to the audio device descriptors in the array.|

### OH_AudioCapturer_OnInterruptCallback()

```
typedef void (*OH_AudioCapturer_OnInterruptCallback)(OH_AudioCapturer* capturer, void* userData,OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)
```

**Description**

Defines the callback for interruption events of an audio capturer.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
|  void* userData | Pointer to the data storage area customized by the application.|
| [OH_AudioInterrupt_ForceType](capi-native-audiostream-base-h.md#oh_audiointerrupt_forcetype) type | Type of force that causes audio interruption.|
|  [OH_AudioInterrupt_Hint](capi-native-audiostream-base-h.md#oh_audiointerrupt_hint) hint | Hint provided along with audio interruption.|

### OH_AudioCapturer_OnErrorCallback()

```
typedef void (*OH_AudioCapturer_OnErrorCallback)(OH_AudioCapturer* renderer, void* userData,OH_AudioStream_Result error)
```

**Description**

Defines the callback for error events of an audio capturer.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* renderer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
|  void* userData | Pointer to the data storage area customized by the application.|
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) error | Audio capturer error.|

### OH_AudioCapturer_GetFastStatus()

```
OH_AudioStream_Result OH_AudioCapturer_GetFastStatus(OH_AudioCapturer* capturer,OH_AudioStream_FastStatus* status)
```

**Description**

Obtains the running status of an audio capturer to determine whether it is running in low-latency mode.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| [OH_AudioStream_FastStatus](capi-native-audiostream-base-h.md#oh_audiostream_faststatus)* status | Pointer to the running status.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The function is called in an incorrect state. |

### OH_AudioCapturer_OnFastStatusChange()

```
typedef void (*OH_AudioCapturer_OnFastStatusChange)(OH_AudioCapturer* capturer,void* userData,OH_AudioStream_FastStatus status)
```

**Description**

Defines a callback function for low-latency status changes during audio recording.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| void* userData | Pointer to the data storage area customized by the application.|
| status | Low-latency status.|
