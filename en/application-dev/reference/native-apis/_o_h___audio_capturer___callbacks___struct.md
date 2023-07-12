# OH_AudioCapturer_Callbacks_Struct


## Overview

The **OH_AudioCapturer_Callbacks_Struct** struct defines a pointer to the callback functions related to an audio capturer.

\@syscap SystemCapability.Multimedia.Audio.Core

**Since**

10

**Related Modules**

[OHAudio](_o_h_audio.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| (\*[OH_AudioCapturer_OnReadData](_o_h_audio.md#oh_audiocapturer_onreaddata) )([OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*capturer, void \*userData, void \*buffer, int32_t lenth) | Defines a function pointer to the callback function used to read audio data.| 
