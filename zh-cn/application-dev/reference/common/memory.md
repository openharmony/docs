# Memory


## 概述

提供内存管理能力。

@Syscap SystemCapability.CommonLibrary.PurgeableMemory

**起始版本：**

10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [purgeable_memory.h](purgeable__memory_8h.md) | 声明从native层管理可丢弃内存的方法。<br>**引用文件**：<purgeable_memory/purgeable_memory.h> <br>**库**：libpurgeable_memory_ndk.z.so | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_PurgeableMemory](#oh_purgeablememory) | 用于定义OH_PurgeableMemory数据类型名称。 | 
| (\*[OH_PurgeableMemory_ModifyFunc](#oh_purgeablememory_modifyfunc)) (void \*, size_t, void \*) | 用于重建可丢弃内存PurgeableMemory数据的方法。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_PurgeableMemory_Create](#oh_purgeablememory_create) (size_t size, [OH_PurgeableMemory_ModifyFunc](#oh_purgeablememory_modifyfunc) func, void \*funcPara) | 创建**PurgeableMemory**对象。 | 
| [OH_PurgeableMemory_Destroy](#oh_purgeablememory_destroy) ([OH_PurgeableMemory](#oh_purgeablememory) \*purgObj) | 销毁**PurgeableMemory**对象。 | 
| [OH_PurgeableMemory_BeginRead](#oh_purgeablememory_beginread) ([OH_PurgeableMemory](#oh_purgeablememory) \*purgObj) | 开始读取**PurgeableMemory**对象。检查PurgeableMemory是否被回收，若被回收则调用重建方法进行重建。 |
| [OH_PurgeableMemory_EndRead](#oh_purgeablememory_endread) ([OH_PurgeableMemory](#oh_purgeablememory) \*purgObj) | 结束读取**PurgeableMemory**对象。表示系统可回收该**PurgeableMemory**对象内存数据。 | 
| [OH_PurgeableMemory_BeginWrite](#oh_purgeablememory_beginwrite) ([OH_PurgeableMemory](#oh_purgeablememory) \*purgObj) | 开始修改**PurgeableMemory**对象。检查PurgeableMemory是否被回收，若被回收则调用重建方法进行重建。 |
| [OH_PurgeableMemory_EndWrite](#oh_purgeablememory_endwrite) ([OH_PurgeableMemory](#oh_purgeablememory) \*purgObj) | 结束修改**PurgeableMemory**对象。表示系统可回收该**PurgeableMemory**对象内存数据。 | 
| [OH_PurgeableMemory_GetContent](#oh_purgeablememory_getcontent) ([OH_PurgeableMemory](#oh_purgeablememory) \*purgObj) | 获取**PurgeableMemory**对象内存数据。 | 
| [OH_PurgeableMemory_ContentSize](#oh_purgeablememory_contentsize) ([OH_PurgeableMemory](#oh_purgeablememory) \*purgObj) | 获取**PurgeableMemory**对象内存数据大小。 | 
| [OH_PurgeableMemory_AppendModify](#oh_purgeablememory_appendmodify) ([OH_PurgeableMemory](#oh_purgeablememory) \*purgObj, [OH_PurgeableMemory_ModifyFunc](#oh_purgeablememory_modifyfunc) func, void \*funcPara) | 添加**PurgeableMemory**对象的修改方法。 | 


## 类型定义说明


### OH_PurgeableMemory

  
```
typedef struct PurgMem OH_PurgeableMemory
```

**描述:**

用于定义OH_PurgeableMemory数据类型名称。

**起始版本：**

10


### OH_PurgeableMemory_ModifyFunc

  
```
typedef bool(* OH_PurgeableMemory_ModifyFunc) (void *, size_t, void *)
```

**描述:**

用于重建可丢弃内存PurgeableMemory数据的方法。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| void \* | 指向PurgeableMemory内容的内存地址。 | 
| size_t | 重建内容的大小。 | 
| void \* | 重建参数。 | 

**返回:**

操作成功则返回成功；如果操作失败，则返回失败。

**起始版本：**

10


## 函数说明


### OH_PurgeableMemory_AppendModify()

  
```
bool OH_PurgeableMemory_AppendModify (OH_PurgeableMemory * purgObj, OH_PurgeableMemory_ModifyFunc func, void * funcPara )
```

**描述:**

添加**PurgeableMemory**对象的修改方法。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| purgObj | 待添加修改方法的PurgeableMemory对象。 | 
| func | 关于数据修改方法的函数指针，用于PurgeableMemory内存数据重建后进一步修改。 | 
| funcPara | 修改方法的参数。 | 

**返回:**

如果添加成功则返回成功，否则返回失败。

**起始版本：**

10


### OH_PurgeableMemory_BeginRead()

  
```
bool OH_PurgeableMemory_BeginRead (OH_PurgeableMemory * purgObj)
```

**描述:**

开始读取**PurgeableMemory**对象。检查PurgeableMemory是否被回收，若被回收则调用重建方法进行重建

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| purgObj | 待读取的PurgeableMemory对象。 | 

**返回:**

如果PurgeableMemory内存数据准备好则返回成功； 如果PurgeableMemory内存数据已被回收且重建失败则返回失败。

**起始版本：**

10


### OH_PurgeableMemory_BeginWrite()

  
```
bool OH_PurgeableMemory_BeginWrite (OH_PurgeableMemory * purgObj)
```

**描述:**

开始修改**PurgeableMemory**对象。检查PurgeableMemory是否被回收，若被回收则调用重建方法进行重建

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| purgObj | 待修改的PurgeableMemory对象。 | 

**返回:**

如果PurgeableMemory内存数据准备好则返回成功； 如果PurgeableMemory内存数据已被回收且重建失败则返回失败。

**起始版本：**

10


### OH_PurgeableMemory_ContentSize()

  
```
size_t OH_PurgeableMemory_ContentSize (OH_PurgeableMemory * purgObj)
```

**描述:**

获取**PurgeableMemory**对象内存数据大小。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| purgObj | 待读取内存数据的PurgeableMemory对象。 | 

**返回:**

返回PurgeableMemory对象内存数据大小。

**起始版本：**

10


### OH_PurgeableMemory_Create()

  
```
OH_PurgeableMemory* OH_PurgeableMemory_Create (size_t size, OH_PurgeableMemory_ModifyFunc func, void * funcPara )
```

**描述:**

创建**PurgeableMemory**对象。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| size | PurgeableMemory对象大小。 | 
| func | 关于重建方法的函数指针，用于恢复被回收的PurgeableMemory内存数据。 | 
| funcPara | 用于重建的参数。 | 

**返回:**

返回PurgeableMemory对象。

**起始版本：**

10


### OH_PurgeableMemory_Destroy()

  
```
bool OH_PurgeableMemory_Destroy (OH_PurgeableMemory * purgObj)
```

**描述:**

销毁**PurgeableMemory**对象。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| purgObj | 需要销毁的PurgeableMemory对象。 | 

**返回:**

操作成功则返回成功；如果操作失败，则返回失败。如果purgObj为空则返回失败； 如果返回成功，purgObj会置空避免Use-After-Free。

**起始版本：**

10


### OH_PurgeableMemory_EndRead()

  
```
void OH_PurgeableMemory_EndRead (OH_PurgeableMemory * purgObj)
```

**描述:**

结束读取**PurgeableMemory**对象。表示系统可回收该**PurgeableMemory**对象内存数据。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| purgObj | 结束读取的PurgeableMemory对象。 | 

**起始版本：**

10


### OH_PurgeableMemory_EndWrite()

  
```
void OH_PurgeableMemory_EndWrite (OH_PurgeableMemory * purgObj)
```

**描述:**

结束修改**PurgeableMemory**对象。表示系统可回收该**PurgeableMemory**对象内存数据。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| purgObj | 结束修改的**PurgeableMemory**对象。 | 

**起始版本：**

10


### OH_PurgeableMemory_GetContent()

  
```
void* OH_PurgeableMemory_GetContent (OH_PurgeableMemory * purgObj)
```

**描述:**

获取**PurgeableMemory**对象内存数据。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| purgObj | 待读取内存数据的PurgeableMemory对象。 | 

**返回:**

返回PurgeableMemory对象内存地址。

**起始版本：**

10
