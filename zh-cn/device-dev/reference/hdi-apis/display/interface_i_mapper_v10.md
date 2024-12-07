# IMapper


## 概述

定义释放显示内存接口。

**起始版本：** 3.2

**相关模块：**[Display](_display_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [FreeMem](#freemem) ([in] NativeBuffer handle) | 释放显示内存。  | 
| [Mmap](#mmap) ([in] NativeBuffer handle) | 显示内存映射，将内存映射到对应的进程地址空间中。  | 
| [Unmap](#unmap) ([in] NativeBuffer handle) | 内存反映射，将内存进行反映射。  | 
| [FlushCache](#flushcache) ([in] NativeBuffer handle) | 刷新Cache，刷新Cache里的内容到内存并且使Cache里的内容无效。  | 
| [InvalidateCache](#invalidatecache) ([in] NativeBuffer handle) | 使cache中的内容无效用以存储更新内存内容。  | 


## 成员函数说明


### FlushCache()

```
IMapper::FlushCache ([in] NativeBuffer handle)
```
**描述**

刷新Cache，刷新Cache里的内容到内存并且使Cache里的内容无效。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 待刷新Cache的handle指针。 | 

**返回：**

返回0 表示执行成功。

返回其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### FreeMem()

```
IMapper::FreeMem ([in] NativeBuffer handle)
```
**描述**

释放显示内存。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 待释放的内存handle指针。 | 

**返回：**

返回0 表示执行成功。

返回其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### InvalidateCache()

```
IMapper::InvalidateCache ([in] NativeBuffer handle)
```
**描述**

使cache中的内容无效用以存储更新内存内容。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 待无效cache的handle指针。 | 

**返回：**

返回0 表示执行成功。

返回其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### Mmap()

```
IMapper::Mmap ([in] NativeBuffer handle)
```
**描述**

显示内存映射，将内存映射到对应的进程地址空间中。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 待映射内存handle指针。 | 

**返回：**

返回0 表示执行成功。

返回其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。


### Unmap()

```
IMapper::Unmap ([in] NativeBuffer handle)
```
**描述**

内存反映射，将内存进行反映射。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| handle | 待反映射内存handle指针。 | 

**返回：**

返回0 表示执行成功。

返回其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。
