# OH_AudioRenderer_Callbacks_Struct


## Overview

The **OH_AudioRenderer_Callbacks_Struct** struct defines a pointer to the callback functions related to an audio renderer.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

**Related module**: [OHAudio](_o_h_audio.md)


## Summary


### Member Variables

| Name                                                                                                                                                                                                                                                                                                               | Description| 
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------| -------- |
| int32_t (\*[OH_AudioRenderer_OnWriteData](#oh_audiorenderer_onwritedata))([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, void \*buffer, int32_t lenth)                                                                                                                           | Defines a function pointer to the callback function used to write audio data.| 
| int32_t (\*[OH_AudioRenderer_OnStreamEvent](#oh_audiorenderer_onstreamevent))([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioStream_Event](_o_h_audio.md#oh_audiostream_event) event)                                                                                   | Defines a function pointer to the callback function used to process audio playback stream events.| 
| int32_t (\*[OH_AudioRenderer_OnInterruptEvent](#oh_audiorenderer_oninterruptevent))([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioInterrupt_ForceType](_o_h_audio.md#oh_audiointerrupt_forcetype) type, [OH_AudioInterrupt_Hint](_o_h_audio.md#oh_audiointerrupt_hint) hint) | Defines a function pointer to the callback function used to process audio playback interruption events.| 
| int32_t (\*[OH_AudioRenderer_OnError](#oh_audiorenderer_onerror))([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) error)                                                                                             | Defines a function pointer to the callback function used to process audio playback errors.| 


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



### OH_AudioRenderer_OnInterruptEvent

```
int32_t (*OH_AudioRenderer_Callbacks_Struct::OH_AudioRenderer_OnInterruptEvent)(OH_AudioRenderer *renderer, void *userData, OH_AudioInterrupt_ForceType type, OH_AudioInterrupt_Hint hint)
```

**Description**

Defines a function pointer to the callback function used to process audio playback interruption events.


### OH_AudioRenderer_OnStreamEvent

```
int32_t (*OH_AudioRenderer_Callbacks_Struct::OH_AudioRenderer_OnStreamEvent)(OH_AudioRenderer *renderer, void *userData, OH_AudioStream_Event event)
```

**Description**

Defines a function pointer to the callback function used to process audio playback stream events.


### OH_AudioRenderer_OnWriteData

```
int32_t (*OH_AudioRenderer_Callbacks_Struct::OH_AudioRenderer_OnWriteData)(OH_AudioRenderer *renderer, void *userData, void *buffer, int32_t lenth)
```

**Description**

Defines a function pointer to the callback function used to write audio data.
