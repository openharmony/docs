# native_buffer.h


## Overview

The **native_buffer.h** file declares the functions for obtaining and using **NativeBuffer**.

**Library**: libnative_buffer.so

**System capability**: SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

**Since**: 9

**Related module**: [OH_NativeBuffer](_o_h___native_buffer.md)


## Summary


### Structs

| Name| Description:|
| -------- | -------- |
| [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) | Defines the **OH_NativeBuffer** attribute configuration, which is used when you apply for a new **OH_NativeBuffer** instance or query the attributes of an existing instance.|


### Types

| Name| Description:|
| -------- | -------- |
| [OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) | Provides the declaration of an **OH_NativeBuffer** struct.|


### Enums

| Name| Description:|
| -------- | -------- |
| [OH_NativeBuffer_Usage](_o_h___native_buffer.md#oh_nativebuffer_usage) { NATIVEBUFFER_USAGE_CPU_READ = (1ULL &lt;&lt; 0), NATIVEBUFFER_USAGE_CPU_WRITE = (1ULL &lt;&lt; 1), NATIVEBUFFER_USAGE_MEM_DMA = (1ULL &lt;&lt; 3) } | Enumerates the **OH_NativeBuffer** usages.|
| [OH_NativeBuffer_Format](_o_h___native_buffer.md#oh_nativebuffer_format) {<br>NATIVEBUFFER_PIXEL_FMT_RGB_565 = 3, NATIVEBUFFER_PIXEL_FMT_RGBA_5658, NATIVEBUFFER_PIXEL_FMT_RGBX_4444, NATIVEBUFFER_PIXEL_FMT_RGBA_4444,<br>NATIVEBUFFER_PIXEL_FMT_RGB_444, NATIVEBUFFER_PIXEL_FMT_RGBX_5551, NATIVEBUFFER_PIXEL_FMT_RGBA_5551, NATIVEBUFFER_PIXEL_FMT_RGB_555,<br>NATIVEBUFFER_PIXEL_FMT_RGBX_8888, NATIVEBUFFER_PIXEL_FMT_RGBA_8888, NATIVEBUFFER_PIXEL_FMT_RGB_888, NATIVEBUFFER_PIXEL_FMT_BGR_565,<br>NATIVEBUFFER_PIXEL_FMT_BGRX_4444, NATIVEBUFFER_PIXEL_FMT_BGRA_4444, NATIVEBUFFER_PIXEL_FMT_BGRX_5551, NATIVEBUFFER_PIXEL_FMT_BGRA_5551,<br>NATIVEBUFFER_PIXEL_FMT_BGRX_8888, NATIVEBUFFER_PIXEL_FMT_BGRA_8888, NATIVEBUFFER_PIXEL_FMT_BUTT = 0X7FFFFFFF<br>} | Enumerates the **OH_NativeBuffer** formats.|
| [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace) {<br>OH_COLORSPACE_NONE, OH_COLORSPACE_BT601_EBU_FULL, OH_COLORSPACE_BT601_SMPTE_C_FULL, OH_COLORSPACE_BT709_FULL,<br>OH_COLORSPACE_BT2020_HLG_FULL, OH_COLORSPACE_BT2020_PQ_FULL, OH_COLORSPACE_BT601_EBU_LIMIT, OH_COLORSPACE_BT601_SMPTE_C_LIMIT,<br>OH_COLORSPACE_BT709_LIMIT, OH_COLORSPACE_BT2020_HLG_LIMIT, OH_COLORSPACE_BT2020_PQ_LIMIT, OH_COLORSPACE_SRGB_FULL,<br>OH_COLORSPACE_P3_FULL, OH_COLORSPACE_P3_HLG_FULL, OH_COLORSPACE_P3_PQ_FULL, OH_COLORSPACE_ADOBERGB_FULL,<br>OH_COLORSPACE_SRGB_LIMIT, OH_COLORSPACE_P3_LIMIT, OH_COLORSPACE_P3_HLG_LIMIT, OH_COLORSPACE_P3_PQ_LIMIT,<br>OH_COLORSPACE_ADOBERGB_LIMIT, OH_COLORSPACE_LINEAR_SRGB, OH_COLORSPACE_LINEAR_BT709, OH_COLORSPACE_LINEAR_P3,<br>OH_COLORSPACE_LINEAR_BT2020, OH_COLORSPACE_DISPLAY_SRGB, OH_COLORSPACE_DISPLAY_P3_SRGB, OH_COLORSPACE_DISPLAY_P3_HLG,<br>OH_COLORSPACE_DISPLAY_P3_PQ, OH_COLORSPACE_DISPLAY_BT2020_SRGB, OH_COLORSPACE_DISPLAY_BT2020_HLG, OH_COLORSPACE_DISPLAY_BT2020_PQ<br>} | Enumerates the color spaces of an **OH_NativeBuffer** instance.|


### Functions

| Name| Description:|
| -------- | -------- |
| [OH_NativeBuffer_Alloc](_o_h___native_buffer.md#oh_nativebuffer_alloc) (const [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) \*config) | Creates an **OH_NativeBuffer** instance based on an **OH_NativeBuffer_Config** struct. A new **OH_NativeBuffer** instance is created each time this function is called.|
| [OH_NativeBuffer_Reference](_o_h___native_buffer.md#oh_nativebuffer_reference) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer) | Increases the reference count of an **OH_NativeBuffer** instance by 1.|
| [OH_NativeBuffer_Unreference](_o_h___native_buffer.md#oh_nativebuffer_unreference) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer) | Decreases the reference count of an **OH_NativeBuffer** instance by 1 and, when the reference count reaches 0, destroys the instance.|
| [OH_NativeBuffer_GetConfig](_o_h___native_buffer.md#oh_nativebuffer_getconfig) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer, [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) \*config) | Obtains the attributes of an **OH_NativeBuffer** instance.|
| [OH_NativeBuffer_Map](_o_h___native_buffer.md#oh_nativebuffer_map) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer, void \*\*virAddr) | Maps the ION memory corresponding to an **OH_NativeBuffer** instance to the process address space.|
| [OH_NativeBuffer_Unmap](_o_h___native_buffer.md#oh_nativebuffer_unmap) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer) | Unmaps the ION memory corresponding to an **OH_NativeBuffer** instance from the process address space.|
| [OH_NativeBuffer_GetSeqNum](_o_h___native_buffer.md#oh_nativebuffer_getseqnum) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer) | Obtains the sequence number of an **OH_NativeBuffer** instance.|
| [OH_NativeBuffer_SetColorSpace](_o_h___native_buffer.md#oh_nativebuffer_setcolorspace) ([OH_NativeBuffer](_o_h___native_buffer.md#oh_nativebuffer) \*buffer, [OH_NativeBuffer_ColorSpace](_o_h___native_buffer.md#oh_nativebuffer_colorspace) colorSpace) | Sets the color space for an **OH_NativeBuffer** instance.|
