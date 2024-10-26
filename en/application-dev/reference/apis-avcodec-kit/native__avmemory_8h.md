# native_avmemory.h


## Overview

The **native_avmemory.h** file declares the attribute definition of the media struct **AVMemory**.

**Library**: libnative_media_core.so

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Related module**: [Core](_core.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_AVMemory](_core.md#oh_avmemory) [OH_AVMemory](_core.md#oh_avmemory) | Defines a struct that describes a native object for the audio and video memory interface. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AVMemory](_core.md#oh_avmemory) \* [OH_AVMemory_Create](_core.md#oh_avmemory_create) (int32_t size) | Creates an **OH_AVMemory** instance. (This function is deprecated in API version 11.) |
| uint8_t \* [OH_AVMemory_GetAddr](_core.md#oh_avmemory_getaddr) (struct [OH_AVMemory](_core.md#oh_avmemory) \*mem) | Obtains the virtual memory address. (This function is deprecated in API version 11.)|
| int32_t [OH_AVMemory_GetSize](_core.md#oh_avmemory_getsize) (struct [OH_AVMemory](_core.md#oh_avmemory) \*mem) | Obtains the memory length. (This function is deprecated in API version 11.) |
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMemory_Destroy](_core.md#oh_avmemory_destroy) (struct [OH_AVMemory](_core.md#oh_avmemory) \*mem) | Releases an **OH_AVMemory** instance. (This function is deprecated in API version 11.)|
