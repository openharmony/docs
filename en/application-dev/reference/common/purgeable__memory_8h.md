# purgeable_memory.h


## Overview

The **purgeable_memory.h** file declares the APIs for managing purgeable memory at the native layer.

**Since**

10

**Related Modules**

[Memory](memory.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| [OH_PurgeableMemory](memory.md#oh_purgeablememory) | Defines the type name of the **OH_PurgeableMemory** data.| 
| (\*[OH_PurgeableMemory_ModifyFunc](memory.md#oh_purgeablememory_modifyfunc)) (void \*, size_t, void \*) | Defines the function for rebuilding purgeable memory data.| 


### Functions

| Name| Description| 
| -------- | -------- |
| \*[OH_PurgeableMemory_Create](memory.md#oh_purgeablememory_create) (size_t size, [OH_PurgeableMemory_ModifyFunc](memory.md#oh_purgeablememory_modifyfunc) func, void \*funcPara) | Creates a **PurgeableMemory** object.| 
| [OH_PurgeableMemory_Destroy](memory.md#oh_purgeablememory_destroy) ([OH_PurgeableMemory](memory.md#oh_purgeablememory) \*purgObj) | Destroys a **PurgeableMemory** object.| 
| [OH_PurgeableMemory_BeginRead](memory.md#oh_purgeablememory_beginread) ([OH_PurgeableMemory](memory.md#oh_purgeablememory) \*purgObj) | Starts a read operation on a **PurgeableMemory** object. If purgeable memory is reclaimed, the rebuilding function is called to rebuild it.| 
| [OH_PurgeableMemory_EndRead](memory.md#oh_purgeablememory_endread) ([OH_PurgeableMemory](memory.md#oh_purgeablememory) \*purgObj) | Ends a read operation on a **PurgeableMemory** object. Now the system can reclaim purgeable memory.| 
| [OH_PurgeableMemory_BeginWrite](memory.md#oh_purgeablememory_beginwrite) ([OH_PurgeableMemory](memory.md#oh_purgeablememory) \*purgObj) | Begins a write operation on the **PurgeableMemory** object. If purgeable memory is reclaimed, the rebuilding function is called to rebuild it.| 
| [OH_PurgeableMemory_EndWrite](memory.md#oh_purgeablememory_endwrite) ([OH_PurgeableMemory](memory.md#oh_purgeablememory) \*purgObj) | Ends a write operation on the **PurgeableMemory** object. Now the system can reclaim purgeable memory.| 
| [OH_PurgeableMemory_GetContent](memory.md#oh_purgeablememory_getcontent) ([OH_PurgeableMemory](memory.md#oh_purgeablememory) \*purgObj) | Obtains the memory data of a **PurgeableMemory** object.| 
| [OH_PurgeableMemory_ContentSize](memory.md#oh_purgeablememory_contentsize) ([OH_PurgeableMemory](memory.md#oh_purgeablememory) \*purgObj) | Obtains the memory data size of a **PurgeableMemory** object.| 
| [OH_PurgeableMemory_AppendModify](memory.md#oh_purgeablememory_appendmodify) ([OH_PurgeableMemory](memory.md#oh_purgeablememory) \*purgObj, [OH_PurgeableMemory_ModifyFunc](memory.md#oh_purgeablememory_modifyfunc) func, void \*funcPara) | Adds a function for modifying a **PurgeableMemory** object.| 
