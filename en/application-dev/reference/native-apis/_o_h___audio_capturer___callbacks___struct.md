# OH_AudioCapturer_Callbacks_Struct


## Overview

The **OH_AudioCapturer_Callbacks_Struct** struct defines a pointer to the callback functions related to an audio capturer.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

**Related module**: [OHAudio](_o_h_audio.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| (\*[OH_AudioCapturer_OnReadData](_o_h_audio.md#oh_audiocapturer_onreaddata) )([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, void \*buffer, int32_t lenth) | Defines a function pointer to the callback function used to read audio data.| 
| OH_AudioCapturer_OnStreamEvent ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, [OH_AudioStream_Event](_o_h_audio.md#oh_audiostream_event) event) | Defines a function pointer to the callback function used to process audio recording stream events.| 
| OH_AudioCapturer_OnInterruptEvent ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, [OH_AudioInterrupt_ForceType](_o_h_audio.md#oh_audiointerrupt_forcetype) type, [OH_AudioInterrupt_Hint](_o_h_audio.md#oh_audiointerrupt_hint) hint) | Defines a function pointer to the callback function used to process audio recording interruption events.| 
| OH_AudioCapturer_OnError ([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) error) | Defines a function pointer to the callback function used to process audio recording errors.| 
