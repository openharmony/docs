# MemoryTracker


## 概述

实现对设备（如GPU）内存占用的统一查询，如GPU占用的GL和Graphic内存等。

需要查询GPU等外设内存占用时使用，例如hidumper中使用本模块IMemoryTrackerInterface接口列出每个进程的GPU内存占用。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IMemoryTrackerInterface.idl](_i_memory_tracker_interface_8idl.md) | 包含IMemoryTrackerInterface接口的声明、各项参数及返回值的意义。 | 
| [MemoryTrackerTypes.idl](_memory_tracker_types_8idl.md) | 设备内存跟踪模块中使用的数据类型，包括内存类型、内存类型标记、设备内存信息。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IMemoryTrackerInterface](interface_i_memory_tracker_interface.md) | 用于获取指定类型的设备内存信息的接口。 | 
| struct&nbsp;&nbsp;[MemoryRecord](_memory_record.md) | 设备内存信息 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [MemoryTrackerType](#memorytrackertype) {<br/>MEMORY_TRACKER_TYPE_MM = 0 , MEMORY_TRACKER_TYPE_GL = 1 , MEMORY_TRACKER_TYPE_CAM = 2 , MEMORY_TRACKER_TYPE_GRAPH = 3 , MEMORY_TRACKER_TYPE_OTHER = 4 , MEMORY_TRACKER_TYPE_COUNTS<br/>} | 内存类型 | 
| [MemoryTrackerFlag](#memorytrackerflag) {<br/>FLAG_SHARED_RSS = 2 , FLAG_SHARED_PSS = 4 , FLAG_PRIVATE = 8 , FLAG_MAPPED = 16 , FLAG_UNMAPPED = 32 , FLAG_PROTECTED = 64 , FLAG_UNPROTECTED = 128 , FLAG_SYSTEM = 256 , FLAG_SYSTEM_EXCEPT = 512<br/>} | 内存类型标记 | 


## 枚举类型说明


### MemoryTrackerFlag

```
enum MemoryTrackerFlag
```

**描述**

内存类型标记

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| FLAG_SHARED_RSS | 与其他进程共享内存 | 
| FLAG_SHARED_PSS | 与其他进程共享内存 / 共享内存计数 | 
| FLAG_PRIVATE | 不与其他进程共享内存 | 
| FLAG_MAPPED | 内存映射到smaps中 | 
| FLAG_UNMAPPED | 内存不映射到smaps中 | 
| FLAG_PROTECTED | CPU安全模式相关 | 
| FLAG_UNPROTECTED | CPU安全模式无关 | 
| FLAG_SYSTEM | 系统管理内存 | 
| FLAG_SYSTEM_EXCEPT | 系统管理例外情况 | 


### MemoryTrackerType

```
enum MemoryTrackerType
```

**描述**

内存类型

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| MEMORY_TRACKER_TYPE_MM | 多媒体相关 | 
| MEMORY_TRACKER_TYPE_GL | GL相关 | 
| MEMORY_TRACKER_TYPE_CAM | 相机相关 | 
| MEMORY_TRACKER_TYPE_GRAPH | 图形相关 | 
| MEMORY_TRACKER_TYPE_OTHER | 其他 | 
| MEMORY_TRACKER_TYPE_COUNTS | 内存类型总数 | 
