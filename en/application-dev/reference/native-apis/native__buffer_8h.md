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
