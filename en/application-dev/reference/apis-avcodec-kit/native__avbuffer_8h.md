# native_avbuffer.h


## Overview

The **native_avbuffer.h** file declares the functions of the media struct **AVBuffer**.

**Library**: libnative_media_core.so

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

**Related module**: [Core](_core.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_AVBuffer](_core.md#oh_avbuffer) [OH_AVBuffer](_core.md#oh_avbuffer) | Defines a struct that describes a native object for the media memory interface. | 
| typedef struct [OH_NativeBuffer](_core.md#oh_nativebuffer) [OH_NativeBuffer](_core.md#oh_nativebuffer) | Defines a struct that describes a native object for the graphics memory interface. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AVBuffer](_core.md#oh_avbuffer) \* [OH_AVBuffer_Create](_core.md#oh_avbuffer_create) (int32_t capacity) | Creates an **OH_AVBuffer** instance. The caller must call [OH_AVBuffer_Destroy](_core.md#oh_avbuffer_destroy) to manually release the **OH_AVBuffer** instance returned.| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVBuffer_Destroy](_core.md#oh_avbuffer_destroy) (OH_AVBuffer \*buffer) | Releases an **OH_AVBuffer** instance.| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVBuffer_GetBufferAttr](_core.md#oh_avbuffer_getbufferattr) (OH_AVBuffer \*buffer, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr) | Obtains the basic attributes, including **pts**, **size**, **offset**, and **flags**, of a buffer.| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVBuffer_SetBufferAttr](_core.md#oh_avbuffer_setbufferattr) (OH_AVBuffer \*buffer, const [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr) | Sets the basic attributes, including **pts**, **size**, **offset**, and **flags**, of a buffer.| 
| [OH_AVFormat](_core.md#oh_avformat) \* [OH_AVBuffer_GetParameter](_core.md#oh_avbuffer_getparameter) (OH_AVBuffer \*buffer) | Obtains parameters except basic attributes of a buffer. The information is carried in an **OH_AVFormat** instance.| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVBuffer_SetParameter](_core.md#oh_avbuffer_setparameter) (OH_AVBuffer \*buffer, const OH_AVFormat \*format) | Sets parameters except basic attributes of a buffer. The information is carried in an **OH_AVFormat** instance.| 
| uint8_t \* [OH_AVBuffer_GetAddr](_core.md#oh_avbuffer_getaddr) (OH_AVBuffer \*buffer) | Obtains the virtual address of a data buffer.| 
| int32_t [OH_AVBuffer_GetCapacity](_core.md#oh_avbuffer_getcapacity) (OH_AVBuffer \*buffer) | Obtains the capacity (in bytes) of a buffer.| 
| [OH_NativeBuffer](_core.md#oh_nativebuffer) \* [OH_AVBuffer_GetNativeBuffer](_core.md#oh_avbuffer_getnativebuffer) (OH_AVBuffer \*buffer) | Obtains the pointer to an **OH_NativeBuffer** instance.| 
