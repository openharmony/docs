# Base DDK


## Overview

Provides APIs for creating, mapping, unmapping, and destroying an **Ashmem** object.

**System capability**: SystemCapability.Driver.DDK.Extension

**Since**

12

## Summary


### File

| Name| Description| 
| -------- | -------- |
| [ddk_api.h](ddk_api.md) | Declares the HID DDK functions for accessing an input device from the host.<br>File to include: &lt;base/ddk_api.h&gt; <br>Library: libddk_base.z.so| 
| [ddk_types.h](ddk_types.md) | Defines the enum variables and structs used in the HID DDK.<br>File to include: <base/ddk_types.h><br>Library: libddk_base.z.so| 


### Structs

| Name| Description| 
| -------- | -------- |
| [DDK_Ashmem](_ddk_ashmem.md) | Shared memory. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [DDK_RetCode](#ddk_retcode) | Base DDK error code definitions. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_DDK_CreateAshmem](#oh_ddk_createashmem) (const uint8_t *name, [DDK_Ashmem](_ddk_ashmem.md) \*\*ashmem) | Creates an **Ashmem** object. | 
| [OH_DDK_MapAshmem](#oh_ddk_mapashmem) ([DDK_Ashmem](_ddk_ashmem.md) \*ashmem, const uint8_t ashmemMapType) | Maps an **Ashmem** object. | 
| [OH_DDK_UnmapAshmem](#oh_ddk_unmapashmem) ([DDK_Ashmem](_ddk_ashmem.md) \*ashmem) | Unmaps an **Ashmem** object. | 
| [OH_DDK_DestroyAshmem](#oh_ddk_destroyashmem) ([DDK_Ashmem](_ddk_ashmem.md) \*ashmem) | Destroys an **Ashmem** object. | 


## Enum Description


### DDK_RetCode


```
enum DDK_RetCode
```

**Description**

Base DDK error code definitions.

| Value| Description|
| -------- | -------- |
| DDK_SUCCESS | The operation is successful.|
| DDK_FAILED | Operation failed.|
| DDK_INVALID_PARAMETER | Invalid parameter.|
| DDK_INVALID_OPERATION | Invalid operation.|
| DDK_NULL_PTR | Null pointer.|


## Function Description


### OH_DDK_CreateAshmem()


```
DDK_RetCode OH_DDK_CreateAshmem(const uint8_t *name, uint32_t size, DDK_Ashmem **ashmem);
```

**Description**

Creates an **Ashmem** object.

**Parameters**

| Name| Description|
| -------- | -------- |
| name | Name of the **Ashmem** object.|
| size | Buffer size of the **Ashmem** object.|
| ashmem | Pointer to the **Ashmem** object.|

**Returns**

- [DK_SUCCESS](#ddk_retcode) if the API is called successfully.
- [DDK_INVALID_PARAMETER](#ddk_retcode) if the input **name** or **ashmem** is a null pointer, or **size** is **0**.
- [DDK_FAILURE] (#ddk_retcode) if the attempt to create the shared memory or the **DDK_Ashmem** structure fails.


### OH_DDK_MapAshmem()


```
DDK_RetCode OH_DDK_MapAshmem(DDK_Ashmem *ashmem, const uint8_t ashmemMapType);
```

**Description**

Maps an **Ashmem** object.

**Parameters**

| Name| Description|
| -------- | -------- |
| ashmem | Pointer to the **Ashmem** object.|
| ashmemMapType | Mapping type for the **Ashmem** object.|

**Returns**

- [DK_SUCCESS](#ddk_retcode) if the API is called successfully.
- [DDK_NULL_PTR](#ddk_retcode) if the input **ashmem** is a null pointer.
- [DDK_FAILURE] (#ddk_retcode) if the file descriptor of the shared memory is invalid.
- [DDK_INVALID_OPERATION](#ddk_retcode) if calling the **MapAshmem** API fails.


### OH_DDK_UnmapAshmem()


```
DDK_RetCode OH_DDK_UnmapAshmem(DDK_Ashmem *ashmem);
```

**Description**

Unmaps an **Ashmem** object.

**Parameters**

| Name| Description|
| -------- | -------- |
|  ashmem | Pointer to the **Ashmem** object.|

**Returns**

- [DK_SUCCESS](#ddk_retcode) if the API is called successfully.
- [DDK_NULL_PTR](#ddk_retcode) if the input **ashmem** is a null pointer.
- [DDK_FAILURE] (#ddk_retcode) if the file descriptor of the shared memory is invalid.

### OH_DDK_DestroyAshmem()


```
DDK_RetCode OH_DDK_DestroyAshmem(DDK_Ashmem *ashmem);
```

**Description**

Destroys the created shared memory.

**Parameters**

| Name| Description|
| -------- | -------- |
|  ashmem | Pointer to the **Ashmem** object.|

**Returns**

- [DK_SUCCESS](#ddk_retcode) if the API is called successfully.
- [DDK_NULL_PTR](#ddk_retcode) if the input **ashmem** is a null pointer.
- [DDK_FAILURE] (#ddk_retcode) if the file descriptor of the shared memory is invalid.
