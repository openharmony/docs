# OH_AudioRenderer_Callbacks_Struct


## Overview

The **OH_AudioRenderer_Callbacks_Struct** struct defines a pointer to the callback functions related to an audio renderer.

\@syscap SystemCapability.Multimedia.Audio.Core

**Since**

10

**Related Modules**

[OHAudio](_o_h_audio.md)


## Summary


### Member Variables

| Name| Description |
| -------- | -------- |
| (\*[OH_AudioRenderer_OnWriteData](_o_h_audio.md#oh_audiorenderer_onwritedata) )([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, void \*userData, void \*buffer, int32_t lenth) | Defines a function pointer to the callback function used to write audio data.|
