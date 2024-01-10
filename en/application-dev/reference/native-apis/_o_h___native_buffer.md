# OH_NativeBuffer


## Overview

The **OH_NativeBuffer** module provides the capabilities of **NativeBuffer**. Using the functions provided by this module, you can apply for, use, and release the shared memory, and query its attributes.

\@syscap SystemCapability.Graphic.Graphic2D.NativeBuffer

**Since**

9


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [native_buffer.h](native__buffer_8h.md) | Declares the functions for obtaining and using **NativeBuffer**.<br>**File to include**: &lt;native_buffer/native_buffer.h&gt;<br>**Library**: libnative_buffer.so|


### Structs

| Name| Description|
| -------- | -------- |
| [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) | Defines the **OH_NativeBuffer** attribute configuration, which is used when you apply for a new **OH_NativeBuffer** instance or query the attributes of an existing instance.|


### Types

| Name| Description|
| -------- | -------- |
| [OH_NativeBuffer](#oh_nativebuffer) | Provides the declaration of an **OH_NativeBuffer** struct.|

### Enums

| Name| Description|
| -------- | -------- |
| [OH_NativeBuffer_Usage](#oh_nativebuffer_usage) { NATIVEBUFFER_USAGE_CPU_READ = (1ULL &lt;&lt; 0), NATIVEBUFFER_USAGE_CPU_WRITE = (1ULL &lt;&lt; 1), NATIVEBUFFER_USAGE_MEM_DMA = (1ULL &lt;&lt; 3) } | Enumerates the **OH_NativeBuffer** usages.|
| [OH_NativeBuffer_Format](#oh_nativebuffer_format) {<br>NATIVEBUFFER_PIXEL_FMT_RGB_565 = 3, NATIVEBUFFER_PIXEL_FMT_RGBA_5658, NATIVEBUFFER_PIXEL_FMT_RGBX_4444, NATIVEBUFFER_PIXEL_FMT_RGBA_4444,<br>NATIVEBUFFER_PIXEL_FMT_RGB_444, NATIVEBUFFER_PIXEL_FMT_RGBX_5551, NATIVEBUFFER_PIXEL_FMT_RGBA_5551, NATIVEBUFFER_PIXEL_FMT_RGB_555,<br>NATIVEBUFFER_PIXEL_FMT_RGBX_8888, NATIVEBUFFER_PIXEL_FMT_RGBA_8888, NATIVEBUFFER_PIXEL_FMT_RGB_888, NATIVEBUFFER_PIXEL_FMT_BGR_565,<br>NATIVEBUFFER_PIXEL_FMT_BGRX_4444, NATIVEBUFFER_PIXEL_FMT_BGRA_4444, NATIVEBUFFER_PIXEL_FMT_BGRX_5551, NATIVEBUFFER_PIXEL_FMT_BGRA_5551,<br>NATIVEBUFFER_PIXEL_FMT_BGRX_8888, NATIVEBUFFER_PIXEL_FMT_BGRA_8888, NATIVEBUFFER_PIXEL_FMT_BUTT = 0X7FFFFFFF<br>} | Enumerates the **OH_NativeBuffer** formats.|

### Functions

| Name| Description|
| -------- | -------- |
| [OH_NativeBuffer_Alloc](#oh_nativebuffer_alloc) (const [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) \*config) | Creates an **OH_NativeBuffer** instance based on an **OH_NativeBuffer_Config** struct. A new **OH_NativeBuffer** instance is created each time this function is called.|
| [OH_NativeBuffer_Reference](#oh_nativebuffer_reference) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | Increases the reference count of an **OH_NativeBuffer** instance by 1.|
| [OH_NativeBuffer_Unreference](#oh_nativebuffer_unreference) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | Decreases the reference count of an **OH_NativeBuffer** instance by 1 and, when the reference count reaches 0, destroys the instance.|
| [OH_NativeBuffer_GetConfig](#oh_nativebuffer_getconfig) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) \*config) | Obtains the properties of an **OH_NativeBuffer** instance.|
| [OH_NativeBuffer_Map](#oh_nativebuffer_map) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, void \*\*virAddr) | Maps the ION memory corresponding to an **OH_NativeBuffer** instance to the process address space.|
| [OH_NativeBuffer_Unmap](#oh_nativebuffer_unmap) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | Unmaps the ION memory corresponding to an **OH_NativeBuffer** instance from the process address space.|
| [OH_NativeBuffer_GetSeqNum](#oh_nativebuffer_getseqnum) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | Obtains the sequence number of an **OH_NativeBuffer** instance.|


## Type Description


### OH_NativeBuffer


```
typedef struct OH_NativeBuffer OH_NativeBuffer
```

**Description**

Provides the declaration of an **OH_NativeBuffer** struct.

## Enum Description


### OH_NativeBuffer_Format

```
enum OH_NativeBuffer_Format
```

**Description**

Enumerates the **OH_NativeBuffer** formats.

\@SysCap SystemCapability.Graphic.Graphic2D.NativeBuffer

| Value| Description|
| -------- | -------- |
| NATIVEBUFFER_PIXEL_FMT_RGB_565 | RGB565.|
| NATIVEBUFFER_PIXEL_FMT_RGBA_5658 | RGBA5658.|
| NATIVEBUFFER_PIXEL_FMT_RGBX_4444 | RGBX4444.|
| NATIVEBUFFER_PIXEL_FMT_RGBA_4444 | RGBA4444.|
| NATIVEBUFFER_PIXEL_FMT_RGB_444 | RGB444.|
| NATIVEBUFFER_PIXEL_FMT_RGBX_5551 | RGBX5551.|
| NATIVEBUFFER_PIXEL_FMT_RGBA_5551 | RGBA5551.|
| NATIVEBUFFER_PIXEL_FMT_RGB_555 | RGB555.|
| NATIVEBUFFER_PIXEL_FMT_RGBX_8888 | RGBX8888.|
| NATIVEBUFFER_PIXEL_FMT_RGBA_8888 | RGBA8888.|
| NATIVEBUFFER_PIXEL_FMT_RGB_888 | RGB888.|
| NATIVEBUFFER_PIXEL_FMT_BGR_565 | BGR565.|
| NATIVEBUFFER_PIXEL_FMT_BGRX_4444 | BGRX4444.|
| NATIVEBUFFER_PIXEL_FMT_BGRA_4444 | BGRA4444.|
| NATIVEBUFFER_PIXEL_FMT_BGRX_5551 | BGRX5551.|
| NATIVEBUFFER_PIXEL_FMT_BGRA_5551 | BGRA5551.|
| NATIVEBUFFER_PIXEL_FMT_BGRX_8888 | BGRX8888.|
| NATIVEBUFFER_PIXEL_FMT_BGRA_8888 | BGRA8888.|
| NATIVEBUFFER_PIXEL_FMT_BUTT | Invalid format.|

**Since**

10


### OH_NativeBuffer_Usage

```
enum OH_NativeBuffer_Usage
```

**Description**

Enumerates the **OH_NativeBuffer** usages.

\@SysCap SystemCapability.Graphic.Graphic2D.NativeBuffer

| Value| Description|
| -------- | -------- |
| NATIVEBUFFER_USAGE_CPU_READ | Read by the CPU.|
| NATIVEBUFFER_USAGE_CPU_WRITE | Write by the CPU.|
| NATIVEBUFFER_USAGE_MEM_DMA | Direct memory access to the buffer.|

**Since**

10


## Function Description


### OH_NativeBuffer_Alloc()


```
OH_NativeBuffer* OH_NativeBuffer_Alloc (const OH_NativeBuffer_Config * config)
```

**Description**

Creates an **OH_NativeBuffer** instance based on an **OH_NativeBuffer_Config** struct. A new **OH_NativeBuffer** instance is created each time this function is called.

\@syscap SystemCapability.Graphic.Graphic2D.NativeBuffer

**Parameters**

| Name| Description|
| -------- | -------- |
| config | Pointer to an **OH_NativeBuffer_Config** instance.|

**Returns**

Returns the pointer to the **OH_NativeBuffer** instance created if the operation is successful; returns **NULL** otherwise.


### OH_NativeBuffer_GetConfig()


```
void OH_NativeBuffer_GetConfig (OH_NativeBuffer * buffer, OH_NativeBuffer_Config * config )
```

**Description**

Obtains the attributes of an **OH_NativeBuffer** instance.

\@syscap SystemCapability.Graphic.Graphic2D.NativeBuffer

**Parameters**

| Name| Description|
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.|
| config | Pointer to an **OH_NativeBuffer_Config** instance, which is used to receive the attributes of **OH_NativeBuffer**.|


### OH_NativeBuffer_GetSeqNum()


```
uint32_t OH_NativeBuffer_GetSeqNum (OH_NativeBuffer * buffer)
```

**Description**

Obtains the sequence number of an **OH_NativeBuffer** instance.

\@syscap SystemCapability.Graphic.Graphic2D.NativeBuffer

**Parameters**

| Name| Description|
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.|

**Returns**

Returns the unique sequence number of the **OH_NativeBuffer** instance.


### OH_NativeBuffer_Map()


```
int32_t OH_NativeBuffer_Map (OH_NativeBuffer * buffer, void ** virAddr )
```

**Description**

Maps the ION memory corresponding to an **OH_NativeBuffer** instance to the process address space.

\@syscap SystemCapability.Graphic.Graphic2D.NativeBuffer

**Parameters**

| Name| Description|
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.|
| virAddr | Double pointer to the address of the virtual memory.|

**Returns**

Returns **0** if the operation is successful.


### OH_NativeBuffer_Reference()


```
int32_t OH_NativeBuffer_Reference (OH_NativeBuffer * buffer)
```

**Description**

Increases the reference count of an **OH_NativeBuffer** instance by 1.

\@syscap SystemCapability.Graphic.Graphic2D.NativeBuffer

**Parameters**

| Name| Description|
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.|

**Returns**

Returns **0** if the operation is successful.


### OH_NativeBuffer_Unmap()


```
int32_t OH_NativeBuffer_Unmap (OH_NativeBuffer * buffer)
```

**Description**

Unmaps the ION memory corresponding to an **OH_NativeBuffer** instance from the process address space.

\@syscap SystemCapability.Graphic.Graphic2D.NativeBuffer

**Parameters**

| Name| Description|
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.|

**Returns**

Returns **0** if the operation is successful.


### OH_NativeBuffer_Unreference()


```
int32_t OH_NativeBuffer_Unreference (OH_NativeBuffer * buffer)
```

**Description**

Decreases the reference count of an **OH_NativeBuffer** instance by 1 and, when the reference count reaches 0, destroys the instance.

\@syscap SystemCapability.Graphic.Graphic2D.NativeBuffer

**Parameters**

| Name| Description|
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.|

**Returns**

Returns **0** if the operation is successful.
