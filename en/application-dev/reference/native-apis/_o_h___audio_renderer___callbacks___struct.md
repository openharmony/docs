# OH_AudioRenderer_Callbacks_Struct


## Overview

The **OH_AudioRenderer_Callbacks_Struct** struct defines a pointer to the callback functions related to an audio renderer.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

**Related module**: [OHAudio](_o_h_audio.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| (\*[OH_AudioRenderer_OnWriteData](_o_h_audio.md#oh_audiorenderer_onwritedata) )([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, void \*buffer, int32_t lenth) | Defines a function pointer to the callback function used to write audio data.| 
| (\*OH_AudioRenderer_Callbacks::OH_AudioRenderer_OnStreamEvent )([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioStream_Event](_o_h_audio.md#oh_audiostream_event) event); | Defines a function pointer to the callback function used to process audio playback stream events.| 
| (\*OH_AudioRenderer_Callbacks::OH_AudioRenderer_OnInterruptEvent )([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioInterrupt_ForceType](_o_h_audio.md#oh_audiointerrupt_forcetype) type, [OH_AudioInterrupt_Hint](_o_h_audio.md#oh_audiointerrupt_hint) hint) | Defines a function pointer to the callback function used to process audio playback interruption events.| 
| (\*OH_AudioRenderer_Callbacks_Struct::OH_AudioRenderer_OnError)( [OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) error) | Defines a function pointer to the callback function used to process audio playback errors.| 
