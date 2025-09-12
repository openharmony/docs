# native_avmemory.h

## Overview

The file declares the attribute definition of the media struct AVMemory.

**File to include**: <multimedia/player_framework/native_avmemory.h>

**Library**: libnative_media_core.so

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Related module**: [Core](capi-core.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVMemory](capi-core-oh-avmemory.md) | OH_AVMemory | Describes a native object for the audio and video memory interface.|

### Functions

| Name| Description|
| -- | -- |
| [OH_AVMemory *OH_AVMemory_Create(int32_t size)](#oh_avmemory_create) | Creates an OH_AVMemory instance.|
| [uint8_t *OH_AVMemory_GetAddr(struct OH_AVMemory *mem)](#oh_avmemory_getaddr) | Obtains the virtual memory address.|
| [int32_t OH_AVMemory_GetSize(struct OH_AVMemory *mem)](#oh_avmemory_getsize) | Obtains the memory length.|
| [OH_AVErrCode OH_AVMemory_Destroy(struct OH_AVMemory *mem)](#oh_avmemory_destroy) | Releases an OH_AVMemory instance.|

## Function Description

### OH_AVMemory_Create()

```
OH_AVMemory *OH_AVMemory_Create(int32_t size)
```

**Description**

Creates an OH_AVMemory instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 10

**Deprecated from**: 11

**Substitute**: [OH_AVBuffer_Create](capi-native-avbuffer-h.md#oh_avbuffer_create)


**Parameters**

| Name| Description|
| -- | -- |
| int32_t size | Size of the created memory, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVMemory](capi-core-oh-avmemory.md) * | Pointer to the OH_AVMemory instance created. If the operation fails, NULL is returned.<br>The instance must be released by calling **OH_AVMemory_Destroy** when it is no longer required.<br>The possible causes of an operation failure are as follows:<br>1. The value of **size** is less than or equal to **0**.<br>2. The OH_AVMemory instance fails to be created.<br>3. Memory allocation fails.|

### OH_AVMemory_GetAddr()

```
uint8_t *OH_AVMemory_GetAddr(struct OH_AVMemory *mem)
```

**Description**

Obtains the virtual memory address.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_AVBuffer_GetAddr](capi-native-avbuffer-h.md#oh_avbuffer_getaddr)


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVMemory](capi-core-oh-avmemory.md) *mem | Pointer to an OH_AVMemory instance.|

**Returns**

| Type| Description|
| -- | -- |
| uint8_t * | Pointer to the virtual memory address. If the memory is invalid, NULL is returned.<br>The possible causes of an operation failure are as follows:<br>1. The value of **mem** is nullptr.<br>2. The value of **mem** fails parameter structure verification.<br>3. The memory in the passed-in value of **mem** is nullptr.|

### OH_AVMemory_GetSize()

```
int32_t OH_AVMemory_GetSize(struct OH_AVMemory *mem)
```

**Description**

Obtains the memory length.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_AVBuffer_GetCapacity](capi-native-avbuffer-h.md#oh_avbuffer_getcapacity)


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVMemory](capi-core-oh-avmemory.md) *mem | Pointer to an OH_AVMemory instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Memory size. If the memory is invalid, **-1** is returned.<br>The possible causes of an operation failure are as follows:<br>1. The value of **mem** is nullptr.<br>2. The value of **mem** fails parameter structure verification.<br>3. The memory in the passed-in value of **mem** is nullptr.|

### OH_AVMemory_Destroy()

```
OH_AVErrCode OH_AVMemory_Destroy(struct OH_AVMemory *mem)
```

**Description**

Releases an OH_AVMemory instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 10

**Deprecated from**: 11

**Substitute**: [OH_AVBuffer_Destroy](capi-native-avbuffer-h.md#oh_avbuffer_destroy)


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVMemory](capi-core-oh-avmemory.md) *mem | Pointer to an OH_AVMemory instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) |  **AV_ERR_OK**: The release operation is successful.<br>**AV_ERR_INVALID_VAL**:<br>1. The value of **mem** is nullptr.<br>2. The value of **mem** fails parameter structure verification.<br>3. The value of **mem** is not created by the caller.|
