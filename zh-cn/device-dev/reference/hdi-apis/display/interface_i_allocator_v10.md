# IAllocator


## 概述

定义显示内存分配接口。

**起始版本：** 3.2

**相关模块：**[Display](_display_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [AllocMem](#allocmem) ([in] struct [AllocInfo](_alloc_info_v10.md) info, [out] NativeBuffer handle) | 显示内存分配。  | 


## 成员函数说明


### AllocMem()

```
IAllocator::AllocMem ([in] struct AllocInfo info, [out] NativeBuffer handle )
```
**描述**

显示内存分配。

根据GUI图形系统传递的参数分配内存，分配的内存根据类型可分为共享内存、Cache内存和非Cache内存等。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 表示申请内存AllocInfo信息。  | 
| handle | 指向申请的内存handle指针。 | 

**返回：**

返回0 表示执行成功。

返回其他值表示执行失败，具体错误码查看[DispErrCode](_display_v10.md#disperrcode)。
