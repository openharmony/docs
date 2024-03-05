# native_avmemory.h


## Overview

The **native_avmemory.h** file declares the attribute definition of the media struct **AVMemory**.

**Library**: libnative_media_core.so

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Related module**: [Core](_core.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| OH_AVMemory \* [OH_AVMemory_Create](_core.md#oh_avmemory_create) (int32_t size) | Creates an **OH_AVMemory** instance.| 
| uint8_t \* [OH_AVMemory_GetAddr](_core.md#oh_avmemory_getaddr) (struct OH_AVMemory \*mem) | Obtains the virtual memory address of an **OH_AVMemory** instance.| 
| int32_t [OH_AVMemory_GetSize](_core.md#oh_avmemory_getsize) (struct OH_AVMemory \*mem) | Obtains the memory size of an **OH_AVMemory** instance.| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMemory_Destroy](_core.md#oh_avmemory_destroy) (struct OH_AVMemory \*mem) | Releases an **OH_AVMemory** instance.| 
