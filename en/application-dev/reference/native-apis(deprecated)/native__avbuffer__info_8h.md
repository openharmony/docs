# native_avbuffer_info.h


## Overview

The **native_avbuffer_info.h** file declares the attribute definition of the media struct **AVBuffer**.

**Library**: libnative_media_core.so

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Related module**: [Core](_core.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) | Defines the description information about the buffer of an **OH_AVCodec** instance.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [OH_AVCodecBufferFlags](_core.md#oh_avcodecbufferflags)[OH_AVCodecBufferFlags](_core.md#oh_avcodecbufferflags) | Defines an enum that enumerates the flags for the buffer of an **OH_AVCodec** instance.| 
| typedef struct [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md)[OH_AVCodecBufferAttr](_core.md#oh_avcodecbufferattr) | Defines the description information about the buffer of an **OH_AVCodec** instance.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_AVCodecBufferFlags](_core.md#oh_avcodecbufferflags) {<br>AVCODEC_BUFFER_FLAGS_NONE = 0,<br>AVCODEC_BUFFER_FLAGS_EOS = 1 &lt;&lt; 0, AVCODEC_BUFFER_FLAGS_SYNC_FRAME = 1 &lt;&lt; 1, AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME = 1 &lt;&lt; 2,<br>AVCODEC_BUFFER_FLAGS_CODEC_DATA = 1 &lt;&lt; 3<br>} | Enumerates the flags for the buffer of an **OH_AVCodec** instance.| 
