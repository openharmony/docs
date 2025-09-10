# OH_AudioRenderer_Callbacks_Struct
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

## Overview

The struct defines a pointer to the callback functions related to an audio renderer.

To avoid unexpected behavior, ensure that every member variable of the struct is initialized by a custom callback method or a null pointer when setting the audio callback functions.

For details, see [Using OHAudio for Audio Playback](../../media/audio/using-ohaudio-for-playback.md).

**Since**: 10

**Deprecated from**: 20

**Substitute**

Use the following callback types for substitute:

[OH_AudioRenderer_OnWriteDataCallback](capi-native-audiostream-base-h.md#oh_audiorenderer_onwritedatacallback), [OH_AudioRenderer_OutputDeviceChangeCallback](capi-native-audiostream-base-h.md#oh_audiorenderer_outputdevicechangecallback), [OH_AudioRenderer_OnInterruptCallback](capi-native-audiorenderer-h.md#oh_audiorenderer_oninterruptcallback), and [OH_AudioRenderer_OnErrorCallback](capi-native-audiorenderer-h.md#oh_audiorenderer_onerrorcallback)

**Related module**: [OHAudio](capi-ohaudio.md)

**Header file**: [native_audiostream_base.h](capi-native-audiostream-base-h.md)

## Summary

### Member Functions

| Name| Description|
| -- | -- |
| [int32_t (\*OH_AudioRenderer_OnWriteData)(OH_AudioRenderer* renderer, void* userData, void* buffer, int32_t length)](#oh_audiorenderer_onwritedata) | Defines a function pointer to the callback function used to write audio data.|
| [int32_t (\*OH_AudioRenderer_OnStreamEvent)(OH_AudioRenderer* renderer, void* userData, OH_AudioStream_Event event)](#oh_audiorenderer_onstreamevent) | Defines a function pointer to the callback function used to process audio playback stream events.|
| [int32_t (\*OH_AudioRenderer_OnInterruptEvent)(OH_AudioRenderer* renderer, void* userData, OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)](#oh_audiorenderer_oninterruptevent) | Defines a function pointer to the callback function used to process audio playback interruption events.|
| [int32_t (\*OH_AudioRenderer_OnError)(OH_AudioRenderer* renderer, void* userData, OH_AudioStream_Result error)](#oh_audiorenderer_onerror) | Defines a function pointer to the callback function used to process audio playback errors.|

## Member Function Description

> **NOTE**
>
> No enumerated values are defined as the return values of the following callbacks. In the current version, no processing specific to the return value is provided. To support expansion in later versions, the default value **0** is used.

### OH_AudioRenderer_OnWriteData()

```
int32_t (*OH_AudioRenderer_OnWriteData)(OH_AudioRenderer* renderer, void* userData, void* buffer, int32_t length)
```

**Description**

Defines a function pointer to the callback function used to write audio data.

The callback function is used only to write audio data. Do not call AudioRenderer APIs in it.

Once the callback function finishes its execution, the audio service queues the data pointed to by **buffer** for playback. Therefore, do not change the data outside the callback. It is crucial to fill **buffer** with the exact length (specified by **length**) of data designated for playback; otherwise, noises may occur during playback.

**Since**: 10

**Deprecated from**: 20

**Substitute**: [OH_AudioRenderer_OnWriteDataCallback](capi-native-audiostream-base-h.md#oh_audiorenderer_onwritedatacallback)

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| void* userData | Pointer to the data storage area customized by the application.|
| void* buffer | Pointer to the playback data storage area, which is used by the application to fill in playback data.|
| int32_t length | Length of the buffer.|

### OH_AudioRenderer_OnStreamEvent()

```
int32_t (*OH_AudioRenderer_OnStreamEvent)(OH_AudioRenderer* renderer, void* userData, OH_AudioStream_Event event)
```

**Description**

Defines a function pointer to the callback function used to process audio playback stream events.

**OH_AudioRenderer_OnStreamEvent** is a reserved API and does not trigger callbacks. Starting from API version 11, if you need to listen for device changes, use [OH_AudioRenderer_OutputDeviceChangeCallback](capi-native-audiostream-base-h.md#oh_audiorenderer_outputdevicechangecallback) instead.

**Since**: 10

**Deprecated from**: 20

**Substitute**: [OH_AudioRenderer_OutputDeviceChangeCallback](capi-native-audiostream-base-h.md#oh_audiorenderer_outputdevicechangecallback)

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| void* userData | Pointer to the data storage area customized by the application.|
| [OH_AudioStream_Event](capi-native-audiostream-base-h.md#oh_audiostream_event) event | Audio event.|

### OH_AudioRenderer_OnInterruptEvent()

```
int32_t (*OH_AudioRenderer_OnInterruptEvent)(OH_AudioRenderer* renderer, void* userData, OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)
```

**Description**

Defines a function pointer to the callback function used to process audio playback interruption events.

**Since**: 10

**Deprecated from**: 20

**Substitute**: [OH_AudioRenderer_OnInterruptCallback](capi-native-audiorenderer-h.md#oh_audiorenderer_oninterruptcallback)

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| void* userData | Pointer to the data storage area customized by the application.|
| [OH_AudioInterrupt_ForceType](capi-native-audiostream-base-h.md#oh_audiointerrupt_forcetype) type | Type of force that causes audio interruption.|
| [OH_AudioInterrupt_Hint](capi-native-audiostream-base-h.md#oh_audiointerrupt_hint) hint | Hint provided along with audio interruption.|

### OH_AudioRenderer_OnError()

```
int32_t (*OH_AudioRenderer_OnError)(OH_AudioRenderer* renderer, void* userData, OH_AudioStream_Result error)
```

**Description**

Defines a function pointer to the callback function used to process audio playback errors.

**Since**: 10

**Deprecated from**: 20

**Substitute**: [OH_AudioRenderer_OnErrorCallback](capi-native-audiorenderer-h.md#oh_audiorenderer_onerrorcallback)

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)* renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generaterenderer).|
| void* userData | Pointer to the data storage area customized by the application.|
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) error | Audio playback error result, which may be **AUDIOSTREAM_ERROR_INVALID_PARAM**, **AUDIOSTREAM_ERROR_ILLEGAL_STATE**, or **AUDIOSTREAM_ERROR_SYSTEM**.|
