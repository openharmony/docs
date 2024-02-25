# native_avbuffer.h


## Overview

The **native_avbuffer.h** file declares the functions of the media struct **AVBuffer**.

**Library**: libnative_media_core.so

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

**Related module**: [Core](_core.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| OH_AVBuffer \* [OH_AVBuffer_Create](_core.md#oh_avbuffer_create) (int32_t capacity) | Creates an **OH_AVBuffer** instance. The caller must call [OH_AVBuffer_Destroy](_core.md#oh_avbuffer_destroy) to manually release the **OH_AVBuffer** instance returned.| 
| [OH_AVErrCode](_core.md#oh_averrcode)[OH_AVBuffer_Destroy](_core.md#oh_avbuffer_destroy) (OH_AVBuffer \*buffer) | Releases an **OH_AVBuffer** instance.| 
| [OH_AVErrCode](_core.md#oh_averrcode)[OH_AVBuffer_GetBufferAttr](_core.md#oh_avbuffer_getbufferattr) (OH_AVBuffer \*buffer, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr) | Obtains the high-frequency attribute of a data buffer.| 
| [OH_AVErrCode](_core.md#oh_averrcode)[OH_AVBuffer_SetBufferAttr](_core.md#oh_avbuffer_setbufferattr) (OH_AVBuffer \*buffer, const [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr) | Sets the high-frequency attribute for a data buffer.| 
| OH_AVFormat \* [OH_AVBuffer_GetParameter](_core.md#oh_avbuffer_getparameter) (OH_AVBuffer \*buffer) | Obtains the frame parameter of a data buffer.| 
| [OH_AVErrCode](_core.md#oh_averrcode)[OH_AVBuffer_SetParameter](_core.md#oh_avbuffer_setparameter) (OH_AVBuffer \*buffer, const OH_AVFormat \*format) | Sets the frame parameter for a data buffer.| 
| uint8_t \* [OH_AVBuffer_GetAddr](_core.md#oh_avbuffer_getaddr) (OH_AVBuffer \*buffer) | Obtains the virtual address of a data buffer.| 
| int32_t [OH_AVBuffer_GetCapacity](_core.md#oh_avbuffer_getcapacity) (OH_AVBuffer \*buffer) | Obtains the capacity of a data buffer.| 
| OH_NativeBuffer \* [OH_AVBuffer_GetNativeBuffer](_core.md#oh_avbuffer_getnativebuffer) (OH_AVBuffer \*buffer) | Obtains the pointer of an **OH_NativeBuffer** instance.| 
