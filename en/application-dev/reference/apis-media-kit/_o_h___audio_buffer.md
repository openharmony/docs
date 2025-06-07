# OH_AudioBuffer


## Overview

The **OH_AudioBuffer** struct defines the configuration such as the size, type, and timestamp of audio data.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Related module**: [AVScreenCapture](_a_v_screen_capture.md)

**Header file**: [native_avscreen_capture_base.h](native__avscreen__capture__base_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint8_t \* [buf](#buf) | Defines the pointer to an audio buffer. | 
| int32_t [size](#size) | Defines the size of the audio buffer. | 
| int64_t [timestamp](#timestamp) | Defines the timestamp of the audio buffer. | 
| [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) [type](#type) | Defines the type of the audio capture source. | 


## Member Variable Description


### buf

```
uint8_t* OH_AudioBuffer::buf
```
**Description**
Defines the pointer to an audio buffer.


### size

```
int32_t OH_AudioBuffer::size
```
**Description**
Defines the size of the audio buffer.


### timestamp

```
int64_t OH_AudioBuffer::timestamp
```
**Description**
Defines the timestamp of the audio buffer.


### type

```
OH_AudioCaptureSourceType OH_AudioBuffer::type
```
**Description**
Defines the type of the audio capture source.
