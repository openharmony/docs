# Memory


## Overview

Provides APIs for memory management.

@Syscap SystemCapability.CommonLibrary.PurgeableMemory

**Since**

10


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [purgeable_memory.h](purgeable__memory_8h.md) | Declares the APIs for managing purgeable memory at the native layer.<br>**File to include**: <purgeable_memory/purgeable_memory.h><br>**Library**: libpurgeable_memory_ndk.z.so| 


### Types

| Name| Description| 
| -------- | -------- |
| [OH_PurgeableMemory](#oh_purgeablememory) | Defines the type name of the **OH_PurgeableMemory** data.| 
| (\*[OH_PurgeableMemory_ModifyFunc](#oh_purgeablememory_modifyfunc)) (void \*, size_t, void \*) | Defines the function for rebuilding purgeable memory data.| 


### Functions

| Name| Description| 
| -------- | -------- |
| \*[OH_PurgeableMemory_Create](#oh_purgeablememory_create) (size_t size, [OH_PurgeableMemory_ModifyFunc](#oh_purgeablememory_modifyfunc) func, void \*funcPara) | Creates a **PurgeableMemory** object.| 
| [OH_PurgeableMemory_Destroy](#oh_purgeablememory_destroy) ([OH_PurgeableMemory](#oh_purgeablememory) \*purgObj) | Destroys a **PurgeableMemory** object.| 
| [OH_PurgeableMemory_BeginRead](#oh_purgeablememory_beginread) ([OH_PurgeableMemory](#oh_purgeablememory) \*purgObj) | Starts a read operation on a **PurgeableMemory** object. If purgeable memory is reclaimed, the rebuilding function is called to rebuild it.| 
| [OH_PurgeableMemory_EndRead](#oh_purgeablememory_endread) ([OH_PurgeableMemory](#oh_purgeablememory) \*purgObj) | Ends a read operation on a **PurgeableMemory** object. Now the system can reclaim purgeable memory.| 
| [OH_PurgeableMemory_BeginWrite](#oh_purgeablememory_beginwrite) ([OH_PurgeableMemory](#oh_purgeablememory) \*purgObj) | Begins a write operation on the **PurgeableMemory** object. If purgeable memory is reclaimed, the rebuilding function is called to rebuild it.| 
| [OH_PurgeableMemory_EndWrite](#oh_purgeablememory_endwrite) ([OH_PurgeableMemory](#oh_purgeablememory) \*purgObj) | Ends a write operation on the **PurgeableMemory** object. Now the system can reclaim purgeable memory.| 
| [OH_PurgeableMemory_GetContent](#oh_purgeablememory_getcontent) ([OH_PurgeableMemory](#oh_purgeablememory) \*purgObj) | Obtains the memory data of a **PurgeableMemory** object.| 
| [OH_PurgeableMemory_ContentSize](#oh_purgeablememory_contentsize) ([OH_PurgeableMemory](#oh_purgeablememory) \*purgObj) | Obtains the memory data size of a **PurgeableMemory** object.| 
| [OH_PurgeableMemory_AppendModify](#oh_purgeablememory_appendmodify) ([OH_PurgeableMemory](#oh_purgeablememory) \*purgObj, [OH_PurgeableMemory_ModifyFunc](#oh_purgeablememory_modifyfunc) func, void \*funcPara) | Adds a function for modifying a **PurgeableMemory** object.| 


## Type Description


### OH_PurgeableMemory

  
```
typedef struct PurgMem OH_PurgeableMemory
```

**Description**

Defines the type name of the **OH_PurgeableMemory** data.

**Since**

10


### OH_PurgeableMemory_ModifyFunc

  
```
typedef bool(* OH_PurgeableMemory_ModifyFunc) (void *, size_t, void *)
```

**Description**

Defines the function for rebuilding purgeable memory data.

**Parameters**

| Name| Description| 
| -------- | -------- |
| void \* | Pointer to the address of purgeable memory.| 
| size_t | Size of the memory data to rebuild.| 
| void \* | Pointer to the parameters used for rebuilding.| 

**Returns**

Returns a success message if the operation is successful; returns a failure message otherwise.

**Since**

10


## Function Description


### OH_PurgeableMemory_AppendModify()

  
```
bool OH_PurgeableMemory_AppendModify (OH_PurgeableMemory * purgObj, OH_PurgeableMemory_ModifyFunc func, void * funcPara )
```

**Description**

Adds a function for modifying a **PurgeableMemory** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| purgObj | Pointer to the **PurgeableMemory** object.| 
| func | Function pointer to the modify function, which is used for further modification after the purgeable memory data is rebuilt.| 
| funcPara | Pointer to the parameters of the modify function.| 

**Returns**

Returns a success message if the operation is successful; returns a failure message otherwise.

**Since**

10


### OH_PurgeableMemory_BeginRead()

  
```
bool OH_PurgeableMemory_BeginRead (OH_PurgeableMemory * purgObj)
```

**Description**

Starts a read operation on a **PurgeableMemory** object. If purgeable memory is reclaimed, the rebuilding function is called to rebuild it.

**Parameters**

| Name| Description| 
| -------- | -------- |
| purgObj | Pointer to the **PurgeableMemory** object.| 

**Returns**

Returns a success message if the purgeable memory data is ready; returns a failure message if purgeable memory has been reclaimed and fails to be rebuilt.

**Since**

10


### OH_PurgeableMemory_BeginWrite()

  
```
bool OH_PurgeableMemory_BeginWrite (OH_PurgeableMemory * purgObj)
```

**Description**

Begins a write operation on the **PurgeableMemory** object. If purgeable memory is reclaimed, the rebuilding function is called to rebuild it.

**Parameters**

| Name| Description| 
| -------- | -------- |
| purgObj | Pointer to the **PurgeableMemory** object.| 

**Returns**

Returns a success message if the purgeable memory data is ready; returns a failure message if purgeable memory has been reclaimed and fails to be rebuilt.

**Since**

10


### OH_PurgeableMemory_ContentSize()

  
```
size_t OH_PurgeableMemory_ContentSize (OH_PurgeableMemory * purgObj)
```

**Description**

Obtains the memory data size of a **PurgeableMemory** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| purgObj | Pointer to the **PurgeableMemory** object.| 

**Returns**

Returns the memory data size.

**Since**

10


### OH_PurgeableMemory_Create()

  
```
OH_PurgeableMemory* OH_PurgeableMemory_Create (size_t size, OH_PurgeableMemory_ModifyFunc func, void * funcPara )
```

**Description**

Creates a **PurgeableMemory** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| size | Size of the **PurgeableMemory** object.| 
| func | Function pointer to the rebuilding function, which is used to restore the reclaimed purgeable memory data.| 
| funcPara | Pointer to the parameters of the rebuilding function.| 

**Returns**

Returns the **PurgeableMemory** object.

**Since**

10


### OH_PurgeableMemory_Destroy()

  
```
bool OH_PurgeableMemory_Destroy (OH_PurgeableMemory * purgObj)
```

**Description**

Destroys a **PurgeableMemory** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| purgObj | Pointer to the **PurgeableMemory** object.| 

**Returns**

Returns a success message if the operation is successful; returns a failure message otherwise. If no value is passed, a failure message is returned. If a success message is returned, the value of **purgObj** will be cleared to avoid Use-After-Free (UAF).

**Since**

10


### OH_PurgeableMemory_EndRead()

  
```
void OH_PurgeableMemory_EndRead (OH_PurgeableMemory * purgObj)
```

**Description**

Ends a read operation on a **PurgeableMemory** object. Now the system can reclaim purgeable memory.

**Parameters**

| Name| Description| 
| -------- | -------- |
| purgObj | Pointer to the **PurgeableMemory** object.| 

**Since**

10


### OH_PurgeableMemory_EndWrite()

  
```
void OH_PurgeableMemory_EndWrite (OH_PurgeableMemory * purgObj)
```

**Description**

Ends a write operation on the **PurgeableMemory** object. Now the system can reclaim purgeable memory.

**Parameters**

| Name| Description| 
| -------- | -------- |
| purgObj | Pointer to the **PurgeableMemory** object.| 

**Since**

10


### OH_PurgeableMemory_GetContent()

  
```
void* OH_PurgeableMemory_GetContent (OH_PurgeableMemory * purgObj)
```

**Description**

Obtains the memory data of a **PurgeableMemory** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| purgObj | Pointer to the **PurgeableMemory** object.| 

**Returns**

Returns the pointer to the purgeable memory address.

**Since**

10
