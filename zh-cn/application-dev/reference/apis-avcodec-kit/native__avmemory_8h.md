# native_avmemory.h


## 概述

声明了媒体数据结构AVMemory的定义。

**库：** libnative_media_core.so

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**相关模块：**[Core](_core.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AVMemory](_core.md#oh_avmemory) [OH_AVMemory](_core.md#oh_avmemory) | 为音视频内存接口定义native层对象。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVMemory](_core.md#oh_avmemory) \* [OH_AVMemory_Create](_core.md#oh_avmemory_create) (int32_t size) | 创建OH_AVMemory实例的指针。（API11废弃）  |
| uint8_t \* [OH_AVMemory_GetAddr](_core.md#oh_avmemory_getaddr) (struct [OH_AVMemory](_core.md#oh_avmemory) \*mem) | 获取内存虚拟地址。 （API11废弃） |
| int32_t [OH_AVMemory_GetSize](_core.md#oh_avmemory_getsize) (struct [OH_AVMemory](_core.md#oh_avmemory) \*mem) | 获取内存长度。（API11废弃）  |
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMemory_Destroy](_core.md#oh_avmemory_destroy) (struct [OH_AVMemory](_core.md#oh_avmemory) \*mem) | 释放OH_AVMemory实例指针的资源。 （API11废弃） |