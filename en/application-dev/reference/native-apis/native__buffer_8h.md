# native_buffer.h


## Overview

The **native_buffer.h** file declares the functions for obtaining and using **NativeBuffer**.

**Since**

9

**Related Modules**

[OH_NativeBuffer](_o_h___native_buffer.md)


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

### Functions

| Name| Description:|
| -------- | -------- |
| [OH_NativeBuffer_Alloc](_o_h___native_buffer.md#oh_nativebuffer_alloc) (const OH_NativeBuffer_Config \*config) | Creates an **OH_NativeBuffer** instance based on an **OH_NativeBuffer_Config** struct. A new **OH_NativeBuffer** instance is created each time this function is called.|
| [OH_NativeBuffer_Reference](_o_h___native_buffer.md#oh_nativebuffer_reference) (OH_NativeBuffer \*buffer) | Increases the reference count of an **OH_NativeBuffer** instance by 1.|
| [OH_NativeBuffer_Unreference](_o_h___native_buffer.md#oh_nativebuffer_unreference) (OH_NativeBuffer \*buffer) | Decreases the reference count of an **OH_NativeBuffer** instance by 1 and, when the reference count reaches 0, destroys the instance.|
| [OH_NativeBuffer_GetConfig](_o_h___native_buffer.md#oh_nativebuffer_getconfig) (OH_NativeBuffer \*buffer, OH_NativeBuffer_Config \*config) | Obtains the attributes of an **OH_NativeBuffer** instance.|
| [OH_NativeBuffer_Map](_o_h___native_buffer.md#oh_nativebuffer_map) (OH_NativeBuffer \*buffer, void \*\*virAddr) | Maps the ION memory corresponding to an **OH_NativeBuffer** instance to the process address space.|
| [OH_NativeBuffer_Unmap](_o_h___native_buffer.md#oh_nativebuffer_unmap) (OH_NativeBuffer \*buffer) | Unmaps the ION memory corresponding to an **OH_NativeBuffer** instance from the process address space.|
| [OH_NativeBuffer_GetSeqNum](_o_h___native_buffer.md#oh_nativebuffer_getseqnum) (OH_NativeBuffer \*buffer) | Obtains the sequence number of an **OH_NativeBuffer** instance.|
