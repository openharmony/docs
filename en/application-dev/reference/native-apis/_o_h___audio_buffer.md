# OH_AudioBuffer


## Overview

The **OH_AudioBuffer** struct defines the configuration such as the size, type, and timestamp of audio data.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**

10

**Related Modules**

[AVScreenCapture](_a_v_screen_capture.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [buf](#buf) | Defines the pointer to an audio buffer.| 
| [size](#size) | Defines the size of the audio buffer.| 
| [timestamp](#timestamp) | Defines the timestamp of the audio buffer.| 
| [type](#type) | Defines the type of the audio capture source.| 


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
