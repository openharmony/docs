# purgeable_memory.h


## 概述

声明从native层管理可丢弃内存的方法。

**起始版本：**

10

**相关模块:**

[Memory](memory.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_PurgeableMemory](memory.md#oh_purgeablememory) | 用于定义OH_PurgeableMemory数据类型名称。 | 
| (\*[OH_PurgeableMemory_ModifyFunc](memory.md#oh_purgeablememory_modifyfunc)) (void \*, size_t, void \*) | 用于重建可丢弃内存PurgeableMemory数据的方法。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_PurgeableMemory_Create](memory.md#oh_purgeablememory_create) (size_t size, [OH_PurgeableMemory_ModifyFunc](memory.md#oh_purgeablememory_modifyfunc) func, void \*funcPara) | 创建**PurgeableMemory**对象。 | 
| [OH_PurgeableMemory_Destroy](memory.md#oh_purgeablememory_destroy) ([OH_PurgeableMemory](memory.md#oh_purgeablememory) \*purgObj) | 销毁**PurgeableMemory**对象。 | 
| [OH_PurgeableMemory_BeginRead](memory.md#oh_purgeablememory_beginread) ([OH_PurgeableMemory](memory.md#oh_purgeablememory) \*purgObj) | 开始读取**PurgeableMemory**对象。检查PurgeableMemory是否被回收， 若被回收则调用重建方法进行重建 | 
| [OH_PurgeableMemory_EndRead](memory.md#oh_purgeablememory_endread) ([OH_PurgeableMemory](memory.md#oh_purgeablememory) \*purgObj) | 结束读取**PurgeableMemory**对象。表示系统可回收该**PurgeableMemory**对象内存数据。 | 
| [OH_PurgeableMemory_BeginWrite](memory.md#oh_purgeablememory_beginwrite) ([OH_PurgeableMemory](memory.md#oh_purgeablememory) \*purgObj) | 开始修改**PurgeableMemory**对象。检查PurgeableMemory是否被回收， 若被回收则调用重建方法进行重建 | 
| [OH_PurgeableMemory_EndWrite](memory.md#oh_purgeablememory_endwrite) ([OH_PurgeableMemory](memory.md#oh_purgeablememory) \*purgObj) | 结束修改**PurgeableMemory**对象。表示系统可回收该**PurgeableMemory**对象内存数据。 | 
| [OH_PurgeableMemory_GetContent](memory.md#oh_purgeablememory_getcontent) ([OH_PurgeableMemory](memory.md#oh_purgeablememory) \*purgObj) | 获取**PurgeableMemory**对象内存数据。 | 
| [OH_PurgeableMemory_ContentSize](memory.md#oh_purgeablememory_contentsize) ([OH_PurgeableMemory](memory.md#oh_purgeablememory) \*purgObj) | 获取**PurgeableMemory**对象内存数据大小。 | 
| [OH_PurgeableMemory_AppendModify](memory.md#oh_purgeablememory_appendmodify) ([OH_PurgeableMemory](memory.md#oh_purgeablememory) \*purgObj, [OH_PurgeableMemory_ModifyFunc](memory.md#oh_purgeablememory_modifyfunc) func, void \*funcPara) | 添加**PurgeableMemory**对象的修改方法。 | 
