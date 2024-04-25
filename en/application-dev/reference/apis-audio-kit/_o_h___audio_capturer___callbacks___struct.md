# OH_AudioCapturer_Callbacks_Struct


## Overview

The **OH_AudioCapturer_Callbacks_Struct** struct defines a pointer to the callback functions related to an audio capturer.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

**Related module**: [OHAudio](_o_h_audio.md)


## Summary


### Member Variables

| Name                   | Description|
|------------------------------------------------------| -------- |
| int32_t (\*[OH_AudioCapturer_OnReadData](#oh_audiocapturer_onreaddata))([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, void \*buffer, int32_t lenth)                                                                                                                                 | Defines a function pointer to the callback function used to read audio data.| 
| int32_t (\*[OH_AudioCapturer_OnStreamEvent](#oh_audiocapturer_onstreamevent))([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, [OH_AudioStream_Event](_o_h_audio.md#oh_audiostream_event) event)                                                                                       | Defines a function pointer to the callback function used to process audio recording stream events.| 
| int32_t (\*[OH_AudioCapturer_OnInterruptEvent](#oh_audiocapturer_oninterruptevent))([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, [OH_AudioInterrupt_ForceType](_o_h_audio.md#oh_audiointerrupt_forcetype) type, [OH_AudioInterrupt_Hint](_o_h_audio.md#oh_audiointerrupt_hint) hint) | Defines a function pointer to the callback function used to process audio recording interruption events.| 
| int32_t (\*[OH_AudioCapturer_OnError](#oh_audiocapturer_onerror))([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) error)                                                                                                 | Defines a function pointer to the callback function used to process audio recording errors.| 


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



### OH_AudioCapturer_OnInterruptEvent

```
int32_t (*OH_AudioCapturer_Callbacks_Struct::OH_AudioCapturer_OnInterruptEvent)(OH_AudioCapturer *capturer, void *userData, OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)
```

**Description**

Defines a function pointer to the callback function used to process audio recording interruption events.



### OH_AudioCapturer_OnReadData

```
int32_t (*OH_AudioCapturer_Callbacks_Struct::OH_AudioCapturer_OnReadData)(OH_AudioCapturer *capturer, void *userData, void *buffer, int32_t lenth)
```

**Description**

Defines a function pointer to the callback function used to read audio data.


### OH_AudioCapturer_OnStreamEvent

```
int32_t (*OH_AudioCapturer_Callbacks_Struct::OH_AudioCapturer_OnStreamEvent)(OH_AudioCapturer *capturer, void *userData, OH_AudioStream_Event event)
```

**Description**

Defines a function pointer to the callback function used to process audio recording stream events.
