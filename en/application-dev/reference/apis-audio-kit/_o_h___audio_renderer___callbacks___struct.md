# OH_AudioRenderer_Callbacks_Struct


## Overview

The **OH_AudioRenderer_Callbacks_Struct** struct defines a pointer to the callback functions related to an audio renderer.

To avoid unexpected behavior, ensure that every member variable of the struct is initialized by a custom callback method or a null pointer when setting the audio callback functions. For details, see [Using OHAudio for Audio Playback](../../media/audio/using-ohaudio-for-playback.md).

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

**Related module**: [OHAudio](_o_h_audio.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int32_t (\*[OH_AudioRenderer_OnWriteData](#oh_audiorenderer_onwritedata))([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, void \*buffer, int32_t length) | Defines a function pointer to the callback function used to write audio data. | 
| int32_t (\*[OH_AudioRenderer_OnStreamEvent](#oh_audiorenderer_onstreamevent))([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioStream_Event](_o_h_audio.md#oh_audiostream_event) event) | Defines a function pointer to the callback function used to process audio playback stream events. | 
| int32_t (\*[OH_AudioRenderer_OnInterruptEvent](#oh_audiorenderer_oninterruptevent))([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioInterrupt_ForceType](_o_h_audio.md#oh_audiointerrupt_forcetype) type, [OH_AudioInterrupt_Hint](_o_h_audio.md#oh_audiointerrupt_hint) hint) | Defines a function pointer to the callback function used to process audio playback interruption events. | 
| int32_t (\*[OH_AudioRenderer_OnError](#oh_audiorenderer_onerror))([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) error) | Defines a function pointer to the callback function used to process audio playback errors. | 


## Member Variable Description

> **NOTE**
>
> No enumerated values are defined as the return values of the following callbacks. In the current version, no processing specific to the return value is provided. To support expansion in later versions, the default value **0** is used.


### OH_AudioRenderer_OnError

```
int32_t (*OH_AudioRenderer_Callbacks_Struct::OH_AudioRenderer_OnError)(OH_AudioRenderer *renderer, void *userData, OH_AudioStream_Result error)
```

**Description**

Defines a function pointer to the callback function used to process audio playback errors.

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](_o_h_audio.md#oh_audiostreambuilder_generaterenderer).|
| userData | Pointer to the data storage area customized by the application.|
| error | Audio playback error result defined by [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result), which can be **AUDIOSTREAM_ERROR_INVALID_PARAM**, **AUDIOSTREAM_ERROR_ILLEGAL_STATE**, or **AUDIOSTREAM_ERROR_SYSTEM**.|
| length | Length of the buffer.|


### OH_AudioRenderer_OnInterruptEvent

```
int32_t (*OH_AudioRenderer_Callbacks_Struct::OH_AudioRenderer_OnInterruptEvent)(OH_AudioRenderer *renderer, void *userData, OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)
```

**Description**

Defines a function pointer to the callback function used to process audio playback interruption events.

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](_o_h_audio.md#oh_audiostreambuilder_generaterenderer).|
| userData | Pointer to the data storage area customized by the application.|
| type | Type of force that causes audio interruption. For details about the available options, see [OH_AudioInterrupt_ForceType](_o_h_audio.md#oh_audiointerrupt_forcetype).|
| hint | Hint provided along with audio interruption. For details about the available options, see [OH_AudioInterrupt_Hint](_o_h_audio.md#oh_audiointerrupt_hint).|

### OH_AudioRenderer_OnStreamEvent

```
int32_t (*OH_AudioRenderer_Callbacks_Struct::OH_AudioRenderer_OnStreamEvent)(OH_AudioRenderer *renderer, void *userData, OH_AudioStream_Event event)
```

**Description**

Defines a function pointer to the callback function used to process audio playback stream events.

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](_o_h_audio.md#oh_audiostreambuilder_generaterenderer).|
| userData | Pointer to the data storage area customized by the application.|
| event | Audio event defined in [OH_AudioStream_Event](_o_h_audio.md#oh_audiostream_event).|


### OH_AudioRenderer_OnWriteData

```
int32_t (*OH_AudioRenderer_Callbacks_Struct::OH_AudioRenderer_OnWriteData)(OH_AudioRenderer *renderer, void *userData, void *buffer, int32_t length)
```

**Description**

Defines a function pointer to the callback function used to write audio data.

Once the callback function finishes its execution, the audio service queues the data pointed to by **buffer** for playback. Therefore, do not change the data outside the callback. It is crucial to fill **buffer** with the exact length (specified by **length**) of data designated for playback; otherwise, noises may occur during playback.

**Parameters**

| Name| Description| 
| -------- | -------- |
| renderer | Pointer to an audio renderer instance, which is created by calling [OH_AudioStreamBuilder_GenerateRenderer](_o_h_audio.md#oh_audiostreambuilder_generaterenderer).|
| userData | Pointer to the data storage area customized by the application.|
| buffer | Pointer to the playback data storage area, which is used by the application to fill in playback data.|
| length | Length of the buffer.|
