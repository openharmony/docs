# ddk_api.h


## Overview

Declares the BASE DDK APIs used by the host to access the device.

**Since**

12

**Related module**

[Base DDK](_base_ddk.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_DDK_CreateAshmem](_base_ddk.md#oh_ddk_createashmem) (const uint8_t *name, [DDK_Ashmem](_ddk_ashmem.md) \*\*ashmem) | Creates an **Ashmem** object. | 
| [OH_DDK_MapAshmem](_base_ddk.md#oh_ddk_mapashmem) ([DDK_Ashmem](_ddk_ashmem.md) \*ashmem), const uint8_t ashmemMapType| Maps an **Ashmem** object. | 
| [OH_DDK_UnmapAshmem](_base_ddk.md#oh_ddk_unmapashmem) ([DDK_Ashmem](_ddk_ashmem.md) \*ashmem) | Unmaps an **Ashmem** object. | 
| [OH_DDK_DestoryAshmem](_base_ddk.md#oh_ddk_destoryashmem) ([DDK_Ashmem](_ddk_ashmem.md) \*ashmem) | Destroys an **Ashmem** object. | 
