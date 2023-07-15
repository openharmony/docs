# OH_AVCodecBufferAttr


## Overview

The **OH_AVCodecBufferAttr** struct defines the description information about the buffer of an **OH_AVCodec** instance.

\@syscap SystemCapability.Multimedia.Media.CodecBase

**Since**

9

**Related Modules**

[CodecBase](_codec_base.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [pts](#pts) | Defines the display timestamp of the buffer, in microseconds.| 
| [size](#size) | Defines the size of data contained in the buffer, in bytes.| 
| [offset](#offset) | Defines the offset of valid data in the buffer.| 
| [flags](#flags) | Defines the flags of the buffer. It is a combination of multiple [OH_AVCodecBufferFlags](_codec_base.md#oh_avcodecbufferflags).| 


## Member Variable Description


### pts

  
```
int64_t pts
```

**Description**

Defines the display timestamp of the buffer, in microseconds.

**Since**

9


### size

  
```
int32_t size
```

**Description**

Defines the size of data contained in the buffer, in bytes.

**Since**

9


### offset

  
```
int32_t offset
```

**Description**

Defines the offset of valid data in the buffer.

**Since**

9


### flags

  
```
uint32_t flags
```

**Description**

Defines the flags of the buffer. It is a combination of multiple [OH_AVCodecBufferFlags](_codec_base.md#oh_avcodecbufferflags).

**Since**

9
