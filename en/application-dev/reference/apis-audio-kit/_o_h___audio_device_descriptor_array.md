# OH_AudioDeviceDescriptorArray


## Overview

The **OH_AudioDeviceDescriptorArray** struct describes an array of audio device descriptors.

**Since**: 12

**Related module**: [OHAudio](_o_h_audio.md)

**Header file**: [native_audio_device_base.h](native__audio__device__base_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [size](#size) | Size of the audio device descriptor array.| 
| [OH_AudioDeviceDescriptor](_o_h_audio.md#oh_audiodevicedescriptor) \*\* [descriptors](#descriptors) | Double pointer to the audio device descriptors in the array.| 


## Member Variable Description


### size

```
uint32_t size
```


**Description**


Size of the audio device descriptor array.


### descriptors

```
OH_AudioDeviceDescriptor **descriptors
```

**Description**

Double pointer to the audio device descriptors in the array.
