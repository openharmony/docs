# native_audiocapturer.h

## Overview

The file declares the functions related to an audio capturer.

**Library**: libohaudio.so

**File to include**: <ohaudio/native_audiocapturer.h>

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
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|

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
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|

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
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|

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
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|

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
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|

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
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
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
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
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
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
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
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
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
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
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
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
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
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
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
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
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
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
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
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
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
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
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
| [OH_AudioCapturer](capi-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| uint32_t* count | Pointer to a variable used to receive the number of overloaded audio streams.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr. |
