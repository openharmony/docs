# OH_NativeBuffer


## Overview

The **OH_NativeBuffer** module provides the capabilities of **NativeBuffer**. Using the functions provided by this module, you can apply for, use, and release the shared memory, and query its attributes.

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

**Since**

9


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [native_buffer.h](native__buffer_8h.md) | Declares the functions for obtaining and using **NativeBuffer**.<br>File to include: &lt;native_buffer/native_buffer.h&gt; |


### Structs

| Name| Description|
| -------- | -------- |
| [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) | Defines the **OH_NativeBuffer** attribute configuration, which is used when you apply for a new **OH_NativeBuffer** instance or query the attributes of an existing instance.|


### Types

| Name| Description|
| -------- | -------- |
| [OH_NativeBuffer](#oh_nativebuffer) | Provides the declaration of an **OH_NativeBuffer** struct.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_NativeBuffer_Alloc](#oh_nativebuffer_alloc) (const [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) \*config) | Creates an **OH_NativeBuffer** instance based on an **OH_NativeBuffer_Config** struct. A new **OH_NativeBuffer** instance is created each time this function is called.|
| [OH_NativeBuffer_Reference](#oh_nativebuffer_reference) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | Increases the reference count of an **OH_NativeBuffer** instance by 1.|
| [OH_NativeBuffer_Unreference](#oh_nativebuffer_unreference) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer) | Decreases the reference count of an **OH_NativeBuffer** instance by 1 and, when the reference count reaches 0, destroys the instance.|
| [OH_NativeBuffer_GetConfig](#oh_nativebuffer_getconfig) ([OH_NativeBuffer](#oh_nativebuffer) \*buffer, [OH_NativeBuffer_Config](_o_h___native_buffer___config.md) \*config) | Obtains the attributes of an **OH_NativeBuffer** instance.|
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


## Function Description


### OH_NativeBuffer_Alloc()


```
OH_NativeBuffer* OH_NativeBuffer_Alloc (const OH_NativeBuffer_Config * config)
```

**Description**

Creates an **OH_NativeBuffer** instance based on an **OH_NativeBuffer_Config** struct. A new **OH_NativeBuffer** instance is created each time this function is called.

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

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

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

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

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

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

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

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

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

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

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

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

\@syscap SystemCapability.Graphic.Graphic2D.OH_NativeBuffer

**Parameters**

| Name| Description|
| -------- | -------- |
| buffer | Pointer to an **OH_NativeBuffer** instance.|

**Returns**

Returns **0** if the operation is successful.
