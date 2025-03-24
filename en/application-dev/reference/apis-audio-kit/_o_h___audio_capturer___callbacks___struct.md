# OH_AudioCapturer_Callbacks_Struct


## Overview

The OH_AudioCapturer_Callbacks_Struct struct defines a pointer to the callback functions related to an audio capturer.

To avoid unexpected behavior, ensure that every member variable of the struct is initialized by a custom callback method or a null pointer when setting the audio callback functions. For details, see [Using OHAudio for Audio Recording](../../media/audio/using-ohaudio-for-recording.md).

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

**Related module**: [OHAudio](_o_h_audio.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int32_t (\*[OH_AudioCapturer_OnReadData](#oh_audiocapturer_onreaddata))([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, void \*buffer, int32_t length) | Defines a function pointer to the callback function used to read audio data. | 
| int32_t (\*[OH_AudioCapturer_OnStreamEvent](#oh_audiocapturer_onstreamevent))([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, [OH_AudioStream_Event](_o_h_audio.md#oh_audiostream_event) event) | Defines a function pointer to the callback function used to process audio recording stream events. | 
| int32_t (\*[OH_AudioCapturer_OnInterruptEvent](#oh_audiocapturer_oninterruptevent))([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, [OH_AudioInterrupt_ForceType](_o_h_audio.md#oh_audiointerrupt_forcetype) type, [OH_AudioInterrupt_Hint](_o_h_audio.md#oh_audiointerrupt_hint) hint) | Defines a function pointer to the callback function used to process audio recording interruption events. | 
| int32_t (\*[OH_AudioCapturer_OnError](#oh_audiocapturer_onerror))([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) error) | Defines a function pointer to the callback function used to process audio recording errors. | 


## Member Variable Description

> **NOTE**
>
> No enumerated values are defined as the return values of the following callbacks. In the current version, no processing specific to the return value is provided. To support expansion in later versions, the default value **0** is used.


### OH_AudioCapturer_OnError

```
int32_t (*OH_AudioCapturer_Callbacks_Struct::OH_AudioCapturer_OnError)(OH_AudioCapturer *capturer, void *userData, OH_AudioStream_Result error)
```

**Description**

Defines a function pointer to the callback function used to process audio recording errors.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](_o_h_audio.md#oh_audiostreambuilder_generatecapturer).|
| userData | Pointer to the data storage area customized by the application.|
| error | Audio recording error result defined by [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result), which can be **AUDIOSTREAM_ERROR_INVALID_PARAM**, **AUDIOSTREAM_ERROR_ILLEGAL_STATE**, or **AUDIOSTREAM_ERROR_SYSTEM**.|


### OH_AudioCapturer_OnInterruptEvent

```
int32_t (*OH_AudioCapturer_Callbacks_Struct::OH_AudioCapturer_OnInterruptEvent)(OH_AudioCapturer *capturer, void *userData, OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)
```

**Description**

Defines a function pointer to the callback function used to process audio recording interruption events.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](_o_h_audio.md#oh_audiostreambuilder_generatecapturer).|
| userData | Pointer to the data storage area customized by the application.|
| type | Type of force that causes audio interruption. For details about the available options, see [OH_AudioInterrupt_ForceType](_o_h_audio.md#oh_audiointerrupt_forcetype).|
| hint | Hint provided along with audio interruption. For details about the available options, see [OH_AudioInterrupt_Hint](_o_h_audio.md#oh_audiointerrupt_hint).|


### OH_AudioCapturer_OnReadData

```
int32_t (*OH_AudioCapturer_Callbacks_Struct::OH_AudioCapturer_OnReadData)(OH_AudioCapturer *capturer, void *userData, void *buffer, int32_t length)
```

**Description**

Defines a function pointer to the callback function used to read audio data.

The callback function is used only to read audio data. Do not call AudioCapturer APIs in it.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](_o_h_audio.md#oh_audiostreambuilder_generatecapturer).|
| userData | Pointer to the data storage area customized by the application.|
| buffer | Pointer to the captured data storage area, which is used by the application to fill in captured data.|
| length | Length of the buffer.|


### OH_AudioCapturer_OnStreamEvent

```
int32_t (*OH_AudioCapturer_Callbacks_Struct::OH_AudioCapturer_OnStreamEvent)(OH_AudioCapturer *capturer, void *userData, OH_AudioStream_Event event)
```

**Description**

Defines a function pointer to the callback function used to process audio recording stream events.

**Parameters**

| Name| Description| 
| -------- | -------- |
| capturer | Pointer to an audio capturer instance, which is created by calling [OH_AudioStreamBuilder_GenerateCapturer](_o_h_audio.md#oh_audiostreambuilder_generatecapturer).|
| userData | Pointer to the data storage area customized by the application.|
| event | Audio event defined in [OH_AudioStream_Event](_o_h_audio.md#oh_audiostream_event).|
