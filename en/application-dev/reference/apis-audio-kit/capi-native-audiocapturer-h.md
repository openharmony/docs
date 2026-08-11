# native_audiocapturer.h

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zyy0412-->
<!--Designer: @weixin_41398971-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=a560ca455272b87c773fafec048564b7357cd71d translatedAt=2026-08-10T01:23:39.365Z pushedAt=2026-08-10T04:19:05.972Z -->

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
| [OH_AudioStream_Result OH_AudioCapturer_Pause(OH_AudioCapturer* capturer)](#oh_audiocapturer_pause) | - | Pauses the audio capture stream. If you need to resume recording later, it is recommended to use this API. |
| [OH_AudioStream_Result OH_AudioCapturer_Stop(OH_AudioCapturer* capturer)](#oh_audiocapturer_stop) | - | Stops the audio capturer. If you need to completely end recording, it is recommended to use this API. |
| [OH_AudioStream_Result OH_AudioCapturer_Flush(OH_AudioCapturer* capturer)](#oh_audiocapturer_flush) | - | Flushes audio data captured by an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetCurrentState(OH_AudioCapturer* capturer, OH_AudioStream_State* state)](#oh_audiocapturer_getcurrentstate) | - | Obtains the state of an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetLatencyMode(OH_AudioCapturer* capturer, OH_AudioStream_LatencyMode* latencyMode)](#oh_audiocapturer_getlatencymode) | - | Obtains the latency mode of an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetStreamId(OH_AudioCapturer* capturer, uint32_t* streamId)](#oh_audiocapturer_getstreamid) | - | Obtains the stream ID of an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetSamplingRate(OH_AudioCapturer* capturer, int32_t* rate)](#oh_audiocapturer_getsamplingrate) | - | Obtains the sampling rate of an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetChannelCount(OH_AudioCapturer* capturer, int32_t* channelCount)](#oh_audiocapturer_getchannelcount) | - | Obtains the number of channels for an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetSampleFormat(OH_AudioCapturer* capturer, OH_AudioStream_SampleFormat* sampleFormat)](#oh_audiocapturer_getsampleformat) | - | Obtains the sampling format of an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetEncodingType(OH_AudioCapturer* capturer, OH_AudioStream_EncodingType* encodingType)](#oh_audiocapturer_getencodingtype) | - | Obtains the encoding type of an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetCapturerInfo(OH_AudioCapturer* capturer, OH_AudioStream_SourceType* sourceType)](#oh_audiocapturer_getcapturerinfo) | - | Obtains the usage scenario of an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetFrameSizeInCallback(OH_AudioCapturer* capturer, int32_t* frameSize)](#oh_audiocapturer_getframesizeincallback) | - | Queries the callback frame count. **frameSize** indicates the number of sample frames per callback. |
| [OH_AudioStream_Result OH_AudioCapturer_GetTimestamp(OH_AudioCapturer* capturer, clockid_t clockId,int64_t* framePosition, int64_t* timestamp)](#oh_audiocapturer_gettimestamp) | - | Obtains the information about the input audio stream timestamp and the current data frame position.<br> This function obtains the actual recording position (specified by **framePosition**) of the audio channel and the timestamp when recording to that position (specified by **timestamp**, in nanoseconds).|
| [OH_AudioStream_Result OH_AudioCapturer_GetFramesRead(OH_AudioCapturer* capturer, int64_t* frames)](#oh_audiocapturer_getframesread) | - | Obtains the number of frames that have been read since the stream was created.|
| [OH_AudioStream_Result OH_AudioCapturer_SetMuteHint(OH_AudioCapturer* capturer, bool mute)](#oh_audiocapturer_setmutehint) | - | Passes the mute state of the current recording stream from the app to the system audio module. This API is used to report the app's own mute state to the system audio module, and does not change the actual mute state of the recording stream. Currently, only on some PC/2-in-1 devices, the system audio module adjusts policies based on the set state to reduce power consumption. This API can be called only when the recording stream is in the running state; otherwise, the error **AUDIOSTREAM_ERROR_ILLEGAL_STATE** is returned. When both the stream-level mute hint API (this API) and the session-level mute hint API are set for the same recording stream, the stream-level API (this API) takes higher priority, and the value set by the stream-level API (this API) prevails. |
| [OH_AudioStream_Result OH_AudioCapturer_GetOverflowCount(OH_AudioCapturer* capturer, uint32_t* count)](#oh_audiocapturer_getoverflowcount) | - | Obtains the number of overloaded audio streams of an audio capturer.|
| [typedef void (\*OH_AudioCapturer_OnReadDataCallback)(OH_AudioCapturer* capturer, void* userData, void* audioData, int32_t audioDataSize)](#oh_audiocapturer_onreaddatacallback) | OH_AudioCapturer_OnReadDataCallback | Defines the callback used to read audio data. To eliminate power-on noise caused by the microphone hardware design, the first 100 ms of data after recording starts is typically muted.|
| [typedef void (\*OH_AudioCapturer_OnDeviceChangeCallback)(OH_AudioCapturer* capturer, void* userData, OH_AudioDeviceDescriptorArray* deviceArray)](#oh_audiocapturer_ondevicechangecallback) | OH_AudioCapturer_OnDeviceChangeCallback | Defines the callback for audio capturer device change events.|
| [typedef void (\*OH_AudioCapturer_OnInterruptCallback)(OH_AudioCapturer* capturer, void* userData, OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)](#oh_audiocapturer_oninterruptcallback) | OH_AudioCapturer_OnInterruptCallback | Defines the callback for interruption events of an audio capturer.|
| [typedef void (\*OH_AudioCapturer_OnErrorCallback)(OH_AudioCapturer* capturer, void* userData, OH_AudioStream_Result error)](#oh_audiocapturer_onerrorcallback) | OH_AudioCapturer_OnErrorCallback | Defines the callback for error events of an audio capturer.|
| [OH_AudioStream_Result OH_AudioCapturer_GetFastStatus(OH_AudioCapturer* capturer, OH_AudioStream_FastStatus* status)](#oh_audiocapturer_getfaststatus) | - | Obtains the running status of an audio capturer to determine whether it is running in low-latency mode.|
| [typedef void (\*OH_AudioCapturer_OnFastStatusChange)(OH_AudioCapturer* capturer, void* userData, OH_AudioStream_FastStatus status)](#oh_audiocapturer_onfaststatuschange) | OH_AudioCapturer_OnFastStatusChange | Defines a callback function for low-latency status changes during audio recording.|
| [typedef void (\*OH_AudioCapturer_OnPlaybackCaptureStartCallback)(OH_AudioCapturer* capturer, void* userData, OH_AudioStream_PlaybackCaptureStartState state)](#oh_audiocapturer_onplaybackcapturestartcallback) | OH_AudioCapturer_OnPlaybackCaptureStartCallback | Defines the callback function for the starting result of internal audio recording (capturing sound from the applications on the device) during audio recording. This API is currently not available for public use.|
| [OH_AudioStream_Result OH_AudioCapturer_RequestPlaybackCaptureStart(OH_AudioCapturer* capturer, OH_AudioCapturer_OnPlaybackCaptureStartCallback callback, void* userData)](#oh_audiocapturer_requestplaybackcapturestart) | - | Asynchronously requests to start the internal recording stream. This API works in non-blocking mode, which means that the system continues to process user authorization and start the internal recording stream after receiving a start request.<br> The final result is returned through a callback. This API is currently not available for public use.|
| [OH_AudioStream_Result OH_AudioCapturer_SetIndependentAudioSessionStrategy(OH_AudioCapturer* capturer, const OH_AudioSession_Strategy* strategy, uint32_t behavior)](#oh_audiocapturer_setindependentaudiosessionstrategy) | - | Sets the independent audio session policy and behavior parameters. If this API is called while an audio capturer is running, you must call the [OH_AudioCapturer_Start](capi-native-audiocapturer-h.md#oh_audiocapturer_start) API again for the settings to take effect.|
| [OH_AudioStream_Result OH_AudioCapturer_SetNoiseReductionMode(OH_AudioCapturer* capturer, OH_AudioNoiseReductionMode noiseReductionMode)](#oh_audiocapturer_setnoisereductionmode) | - | Sets the noise reduction mode of the current recording stream. |
| [OH_AudioStream_Result OH_AudioCapturer_GetNoiseReductionMode(OH_AudioCapturer* capturer, OH_AudioNoiseReductionMode* noiseReductionMode)](#oh_audiocapturer_getnoisereductionmode) | - | Obtains the noise reduction mode of the current recording stream. |
| [OH_AudioStream_Result OH_AudioCapturer_GetSupportedNoiseReductionModes(OH_AudioCapturer* capturer, OH_AudioNoiseReductionMode* noiseReductionModeArray, uint32_t inModeArraySize, uint32_t *outModeArraySize)](#oh_audiocapturer_getsupportednoisereductionmodes) | - | Obtains the recording noise reduction modes supported by the current device platform. |
| [typedef void (\*OH_AudioCapturer_SensitiveRecordPermitCallback)(OH_AudioCapturer* capturer, void* userData, bool isPermitted)](#oh_audiocapturer_sensitiverecordpermitcallback) | OH_AudioCapturer_SensitiveRecordPermitCallback | Callback function invoked when the risk warning prompt finishes playing in a cellular call recording scenario. The app must wait for the callback to return the permission result, and may start cellular call recording only when **isPermitted** is **true**. |

## Function Description

### OH_AudioCapturer_Release()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.<br>         **AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.|

### OH_AudioCapturer_Start()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.<br>         **AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.|

### OH_AudioCapturer_Pause()

```c
OH_AudioStream_Result OH_AudioCapturer_Pause(OH_AudioCapturer* capturer)
```

**Description**

Pauses the input audio stream. If you need to resume recording after pausing, it is recommended to use this API.

**Required permissions**: ohos.permission.MICROPHONE

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.<br>         **AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.|

### OH_AudioCapturer_Stop()

```c
OH_AudioStream_Result OH_AudioCapturer_Stop(OH_AudioCapturer* capturer)
```

**Description**

Stops the audio capturer. If you need to completely end recording, it is recommended to use this API.

**Required permissions**: ohos.permission.MICROPHONE

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.<br>         **AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.|

### OH_AudioCapturer_Flush()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.<br>         **AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.|

### OH_AudioCapturer_GetCurrentState()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.|

### OH_AudioCapturer_GetLatencyMode()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.|

### OH_AudioCapturer_GetStreamId()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.|

### OH_AudioCapturer_GetSamplingRate()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.|

### OH_AudioCapturer_GetChannelCount()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.|

### OH_AudioCapturer_GetSampleFormat()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.|

### OH_AudioCapturer_GetEncodingType()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.|

### OH_AudioCapturer_GetCapturerInfo()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.|

### OH_AudioCapturer_GetFrameSizeInCallback()

```c
OH_AudioStream_Result OH_AudioCapturer_GetFrameSizeInCallback(OH_AudioCapturer* capturer,int32_t* frameSize)
```

**Description**

Queries the callback frame count. **frameSize** indicates the number of sampling frames per callback.

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| int32_t* frameSize | Pointer to the variable where the number of sample frames will be set. |

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.<br>         **AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.|

### OH_AudioCapturer_GetTimestamp()

```c
OH_AudioStream_Result OH_AudioCapturer_GetTimestamp(OH_AudioCapturer* capturer, clockid_t clockId,int64_t* framePosition, int64_t* timestamp)
```

**Description**

Obtains the timestamp and current data frame position information of the input audio stream.<br> This API can obtain the actual recording position (**framePosition**) of the audio channel and the timestamp when the recording reaches that position. The timestamp is in nanoseconds.

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| clockid_t clockId | Clock identifier. Use **CLOCK_MONOTONIC**.|
| int64_t* framePosition | Pointer to a variable used to receive the position information.|
| int64_t* timestamp | Pointer to a variable used to receive the timestamp, in nanoseconds.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>                                                 1. The **capturer** parameter is nullptr.<br>                                                 2. The **clockId** parameter is invalid.<br>         **AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.|

### OH_AudioCapturer_GetFramesRead()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.|

### OH_AudioCapturer_SetMuteHint()

```c
OH_AudioStream_Result OH_AudioCapturer_SetMuteHint(OH_AudioCapturer* capturer, bool mute)
```

**Description**

Reports the mute state of the current recording stream from the app to the system audio module. This API is used to report the app's own mute state to the system audio module, without changing the actual mute state of the recording stream. Currently, only on some PC/2-in-1 devices, the system audio module adjusts policies based on the set state to reduce power consumption. This API can be called only when the recording stream is in the running state; otherwise, AUDIOSTREAM_ERROR_ILLEGAL_STATE is returned. When both the stream-level mute hint API (this API) and the session-level mute hint API are set for the same recording stream, the stream-level API (this API) takes higher priority, and the value set by the stream-level API (this API) prevails.

**Since**: 24

**Parameters**

| Name | Description |
| -- | -- |
| OH_AudioCapturer* capturer | Pointer to the audio stream instance created by [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer). |
| bool mute | Self-mute state reported by the app to the system audio module, which applies to the recording stream instance specified by the first parameter `capturer`. The value **true** indicates that the recording stream is reported as muted, and **false** indicates that the recording stream is reported as unmuted. |

**Returns**

| Type | Description |
| -- | -- |
| OH_AudioStream_Result | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: **capturer** is nullptr.<br>         **AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The operation state is abnormal. The recording stream is not in the running state.<br>         **AUDIOSTREAM_ERROR_SYSTEM**: System exception, for example, the system service exits unexpectedly. |

### OH_AudioCapturer_GetOverflowCount()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.|

### OH_AudioCapturer_OnReadDataCallback()

```c
typedef void (*OH_AudioCapturer_OnReadDataCallback)(OH_AudioCapturer* capturer, void* userData, void* audioData,int32_t audioDataSize)
```

**Description**

Defines the callback used to read audio data. To eliminate power-on noise caused by the microphone hardware design, the first 100 ms of data after recording starts is typically muted.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
|  void* userData | Pointer to the data storage region customized by an application, allowing the application to transfer data to itself.|
|  void* audioData | Pointer to the captured data storage area, which is used by the application to read captured data.|
| int32_t audioDataSize | Length of the captured data, in bytes.|

### OH_AudioCapturer_OnDeviceChangeCallback()

```c
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

```c
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

```c
typedef void (*OH_AudioCapturer_OnErrorCallback)(OH_AudioCapturer* capturer, void* userData,OH_AudioStream_Result error)
```

**Description**

Defines the callback for error events of an audio capturer.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
|  void* userData | Pointer to the data storage area customized by the application.|
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) error | Audio capturer error.|

### OH_AudioCapturer_GetFastStatus()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **capturer** parameter is nullptr.<br>         **AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The function is called in an incorrect state.|

### OH_AudioCapturer_OnFastStatusChange()

```c
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
| [OH_AudioStream_FastStatus](capi-native-audiostream-base-h.md#oh_audiostream_faststatus) status | Low-latency status.|

### OH_AudioCapturer_OnPlaybackCaptureStartCallback()

```c
typedef void (*OH_AudioCapturer_OnPlaybackCaptureStartCallback)(OH_AudioCapturer* capturer, void* userData, OH_AudioStream_PlaybackCaptureStartState state)
```

**Description**

Defines the callback function for the starting result of internal audio recording (capturing sound from the applications on the device) during audio recording. This API is currently not available for public use.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| void\* userData | Pointer to the custom data storage region of an application via [OH_AudioCapturer_RequestPlaybackCaptureStart](capi-native-audiocapturer-h.md#oh_audiocapturer_requestplaybackcapturestart).|
| [OH_AudioStream_PlaybackCaptureStartState](capi-native-audiostream-base-h.md#oh_audiostream_playbackcapturestartstate) state | Whether the internal recording request is successful.|

### OH_AudioCapturer_RequestPlaybackCaptureStart()

```c
OH_AudioStream_Result OH_AudioCapturer_RequestPlaybackCaptureStart(OH_AudioCapturer* capturer, OH_AudioCapturer_OnPlaybackCaptureStartCallback callback, void* userData)
```

**Description**

Asynchronously requests to start the internal recording stream. This API works in non-blocking mode, which means that the system continues to process user authorization and start the internal recording stream after receiving a start request.<br> The final result is returned through a callback. This API is currently not available for public use.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| [OH_AudioCapturer_OnPlaybackCaptureStartCallback](capi-native-audiocapturer-h.md#oh_audiocapturer_onplaybackcapturestartcallback) callback | Callback function used to receive the final result of the start request.|
| void* userData | Pointer to the data storage region customized by an application. This struct will be passed to the callback function.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: Invalid capturer or callback.<br>         **AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The stream is either active or has been released.<br>         **AUDIOSTREAM_ERROR_SYSTEM**: Internal system error, for example, abnormal audio service error.|

### OH_AudioCapturer_SetIndependentAudioSessionStrategy()

```c
OH_AudioStream_Result OH_AudioCapturer_SetIndependentAudioSessionStrategy(OH_AudioCapturer* capturer, const OH_AudioSession_Strategy* strategy, uint32_t behavior)
```

**Description**

Sets the independent audio session policy and behavior parameters. If this API is called while an audio capturer is running, you must call the [OH_AudioCapturer_Start](capi-native-audiocapturer-h.md#oh_audiocapturer_start) API again for the settings to take effect.

**Since**: 24

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| [const OH_AudioSession_Strategy](capi-ohaudio-oh-audiosession-strategy.md)* strategy | Pointer to the independent audio session policy.|
| uint32_t behavior | Audio session behavior flag. This can be a single flag or a bitwise OR combination of multiple flags. For details about the supported audio session behaviors, see [OH_AudioSession_BehaviorFlags](capi-native-audio-session-base-h.md#oh_audiosession_behaviorflags).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: The parameter value is a null pointer or out of range.<br>         **AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.|

### OH_AudioCapturer_SetNoiseReductionMode()

```c
OH_AudioStream_Result OH_AudioCapturer_SetNoiseReductionMode(OH_AudioCapturer* capturer, OH_AudioNoiseReductionMode noiseReductionMode)
```

**Description**

Sets the noise reduction mode of the current recording stream. It is recommended to call [OH_AudioCapturer_GetSupportedNoiseReductionModes](#oh_audiocapturer_getsupportednoisereductionmodes) first to obtain the noise reduction modes supported by the current recording stream, and then set the mode through this API.

Currently, only recording streams created with [AUDIOSTREAM_SOURCE_TYPE_VOICE_MESSAGE](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype) support noise reduction mode setting. Other recording streams support only [AUDIO_NOISE_REDUCTION_MODE_FIDELITY](capi-native-audio-common-h.md#oh_audionoisereductionmode) by default. The noise reduction effect is affected by the device platform, audio device, and concurrent recording conditions. When multiple recording streams are running simultaneously, the set noise reduction mode may not take effect.

This API can be called only after the recording stream is created but before recording starts, or after recording stops. If called when the recording stream is in the running state or has been released, [AUDIOSTREAM_ERROR_ILLEGAL_STATE](capi-native-audiostream-base-h.md#oh_audiostream_result) is returned.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to the audio stream instance created by [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer). |
| [OH_AudioNoiseReductionMode](capi-native-audio-common-h.md#oh_audionoisereductionmode) noiseReductionMode | Noise reduction mode to set. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: **capturer** is nullptr, or **noiseReductionMode** is invalid.<br>         **AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The recording stream is in the running state or has been released.<br>         **AUDIOSTREAM_ERROR_UNSUPPORTED_ABILITY**: The set noise reduction mode is not supported.<br>         **AUDIOSTREAM_ERROR_SERVICE_DIED**: The audio service process exits unexpectedly. |

### OH_AudioCapturer_GetNoiseReductionMode()

```c
OH_AudioStream_Result OH_AudioCapturer_GetNoiseReductionMode(OH_AudioCapturer* capturer, OH_AudioNoiseReductionMode* noiseReductionMode)
```

**Description**

Obtains the noise reduction mode of the current recording stream. The returned result reflects only the noise reduction mode of the current recording stream. The default value is [AUDIO_NOISE_REDUCTION_MODE_FIDELITY](capi-native-audio-common-h.md#oh_audionoisereductionmode).

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to the audio stream instance created by [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer). |
| [OH_AudioNoiseReductionMode](capi-native-audio-common-h.md#oh_audionoisereductionmode)* noiseReductionMode | Pointer to the variable that receives the current noise reduction mode. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: **capturer** is nullptr, or **noiseReductionMode** is nullptr. |

### OH_AudioCapturer_GetSupportedNoiseReductionModes()

```c
OH_AudioStream_Result OH_AudioCapturer_GetSupportedNoiseReductionModes(OH_AudioCapturer* capturer, OH_AudioNoiseReductionMode* noiseReductionModeArray, uint32_t inModeArraySize, uint32_t *outModeArraySize)
```

**Description**

Obtains the recording noise reduction modes supported by the current device platform. Currently, only recording streams created with [AUDIOSTREAM_SOURCE_TYPE_VOICE_MESSAGE](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype) supports query of supported noise reduction modes based on the device platform. Other recording streams return only [AUDIO_NOISE_REDUCTION_MODE_FIDELITY](capi-native-audio-common-h.md#oh_audionoisereductionmode) by default. The returned result considers only the audio format and device platform, without considering the current input device and concurrent recording conditions.

When the number of supported modes exceeds the input parameter **inModeArraySize**, only the first **inModeArraySize** modes are written to **noiseReductionModeArray**, and **outModeArraySize** equals **inModeArraySize**. It is recommended that the app reserve a larger array length, for example, 20, to accommodate future mode additions.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to the audio stream instance created by [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer). |
| [OH_AudioNoiseReductionMode](capi-native-audio-common-h.md#oh_audionoisereductionmode)* noiseReductionModeArray | Pointer to the array allocated by the app, used to receive the supported recording noise reduction modes. [AUDIO_NOISE_REDUCTION_MODE_FIDELITY](capi-native-audio-common-h.md#oh_audionoisereductionmode) is supported by default. |
| uint32_t inModeArraySize | Number of elements in the **noiseReductionModeArray** array. |
| uint32_t* outModeArraySize | Pointer to the variable that receives the actual number of modes written. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: **capturer** is nullptr, **noiseReductionModeArray** is nullptr, or **outModeArraySize** is nullptr.<br>         **AUDIOSTREAM_ERROR_SERVICE_DIED**: The audio service process dies. |

### OH_AudioCapturer_SensitiveRecordPermitCallback()

```c
typedef void (*OH_AudioCapturer_SensitiveRecordPermitCallback)(OH_AudioCapturer* capturer, void* userData, bool isPermitted)
```

**Description**

Callback function invoked when the risk warning prompt finishes playing in the cellular call recording scenario. The app must wait for the callback to return the permission result, and can start cellular call recording only when **isPermitted** is **true**.

**Since**: 26.0.0

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to the audio stream instance created by [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer). |
| void* userData | Pointer to the app-defined data storage area, passed through [OH_AudioStreamBuilder_SetSensitiveRecordPermitCallback](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setsensitiverecordpermitcallback). |
| bool isPermitted | Whether the risk warning prompt has finished playing. The value **true** indicates that recording can be started, and **false** indicates that recording is not permitted. |