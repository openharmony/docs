# OH_AudioCapturer_Callbacks_Struct

## Overview

The struct defines a pointer to the callback functions related to an audio capturer.

To avoid unexpected behavior, ensure that every member variable of the struct is initialized by a custom callback method or a null pointer when setting the audio callback functions. For details, see [Using OHAudio for Audio Recording](../../media/audio/using-ohaudio-for-recording.md).

**Since**: 10

**Deprecated from**: 20

**Substitute**

Use the following callback types for substitute:

[OH_AudioCapturer_OnReadDataCallback](capi-native-audiocapturer-h.md#oh_audiocapturer_onreaddatacallback), [OH_AudioCapturer_OnDeviceChangeCallback](capi-native-audiocapturer-h.md#oh_audiocapturer_ondevicechangecallback), [OH_AudioCapturer_OnInterruptCallback](capi-native-audiocapturer-h.md#oh_audiocapturer_oninterruptcallback), and [OH_AudioCapturer_OnErrorCallback](capi-native-audiocapturer-h.md#oh_audiocapturer_onerrorcallback)

**Related module**: [OHAudio](capi-ohaudio.md)

**Header file**: [native_audiostream_base.h](capi-native-audiostream-base-h.md)

## Summary

### Member Functions

| Name| Description|
| -- | -- |
| [int32_t (\*OH_AudioCapturer_OnReadData)(OH_AudioCapturer* capturer,void* userData,void* buffer,int32_t length)](#oh_audiocapturer_onreaddata) | Defines a function pointer to the callback function used to read audio data.|
| [int32_t (\*OH_AudioCapturer_OnStreamEvent)(OH_AudioCapturer* capturer,void* userData,OH_AudioStream_Event event)](#oh_audiocapturer_onstreamevent) | Defines a function pointer to the callback function used to process audio recording stream events.|
| [int32_t (\*OH_AudioCapturer_OnInterruptEvent)(OH_AudioCapturer* capturer,void* userData,OH_AudioInterrupt_ForceType type,OH_AudioInterrupt_Hint hint)](#oh_audiocapturer_oninterruptevent) | Defines a function pointer to the callback function used to process audio recording interruption events.|
| [int32_t (\*OH_AudioCapturer_OnError)(OH_AudioCapturer* capturer, void* userData, OH_AudioStream_Result error)](#oh_audiocapturer_onerror)| Defines a function pointer to the callback function used to process audio recording errors.|

## Member Function Description

> **NOTE**
>
> No enumerated values are defined as the return values of the following callbacks. In the current version, no processing specific to the return value is provided. To support expansion in later versions, the default value **0** is used.

### OH_AudioCapturer_OnReadData()

```
int32_t (*OH_AudioCapturer_OnReadData)(OH_AudioCapturer* capturer,void* userData,void* buffer,int32_t length)
```

**Description**

Defines a function pointer to the callback function used to read audio data.

The callback function is used only to read audio data. Do not call AudioCapturer APIs in it.

**Since**: 10

**Deprecated from**: 20

**Substitute**: [OH_AudioCapturer_OnReadDataCallback](capi-native-audiocapturer-h.md#oh_audiocapturer_onreaddatacallback)

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| void* userData | Pointer to the data storage area customized by the application.    |
| void* buffer | Pointer to the playback data storage area, which is used by the application to fill in playback data.     |
| int32_t length | Length of the buffer.    |

### OH_AudioCapturer_OnStreamEvent()

```
int32_t (*OH_AudioCapturer_OnStreamEvent)(OH_AudioCapturer* capturer,void* userData,OH_AudioStream_Event event)
```

**Description**

Defines a function pointer to the callback function used to process audio recording stream events.

**Since**: 10

**Deprecated from**: 20

**Substitute**: [OH_AudioCapturer_OnDeviceChangeCallback](capi-native-audiocapturer-h.md#oh_audiocapturer_ondevicechangecallback)

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| void* userData | Pointer to the data storage area customized by the application.|
| [OH_AudioStream_Event](capi-native-audiostream-base-h.md#oh_audiostream_event) event | Audio event.|

### OH_AudioCapturer_OnInterruptEvent()

```
int32_t (*OH_AudioCapturer_OnInterruptEvent)(OH_AudioCapturer* capturer,void* userData,OH_AudioInterrupt_ForceType type,OH_AudioInterrupt_Hint hint)
```

**Description**

Defines a function pointer to the callback function used to process audio recording interruption events.

**Since**: 10

**Deprecated from**: 20

**Substitute**: [OH_AudioCapturer_OnInterruptCallback](capi-native-audiocapturer-h.md#oh_audiocapturer_oninterruptcallback)

**Parameters**

| Name | Description|
|--| -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| void* userData | Pointer to the data storage area customized by the application.|
| [OH_AudioInterrupt_ForceType](capi-native-audiostream-base-h.md#oh_audiointerrupt_forcetype) type | Type of force that causes audio interruption.|
| [OH_AudioInterrupt_Hint](capi-native-audiostream-base-h.md#oh_audiointerrupt_hint) hint | Hint provided along with audio interruption.|


### OH_AudioCapturer_OnError()

```
int32_t (*OH_AudioCapturer_OnError)(OH_AudioCapturer* capturer, void* userData, OH_AudioStream_Result error)
```

**Description**

Defines a function pointer to the callback function used to process audio recording errors.

**Since**: 10

**Deprecated from**: 20

**Substitute**: [OH_AudioCapturer_OnErrorCallback](capi-native-audiocapturer-h.md#oh_audiocapturer_onerrorcallback)

**Parameters**

| Name | Description|
|--| -- |
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)* capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer).|
| void* userData | Pointer to the data storage area customized by the application.|
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) error | Audio recording error result, which may be **AUDIOSTREAM_ERROR_INVALID_PARAM**, **AUDIOSTREAM_ERROR_ILLEGAL_STATE**, or **AUDIOSTREAM_ERROR_SYSTEM**.|
