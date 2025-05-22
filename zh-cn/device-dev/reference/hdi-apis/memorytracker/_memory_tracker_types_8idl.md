# MemoryTrackerTypes.idl


## 概述

设备内存跟踪模块中使用的数据类型，包括内存类型、内存类型标记、设备内存信息。

需要查询外设内存占用时使用，定义的内存类型、内存类型标记、内存设备信息配合模块中其他部分使用。

模块包路径：ohos.hdi.memorytracker.v1_0

**起始版本：** 3.2

**相关模块：**[MemoryTracker](_memory_tracker.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[MemoryRecord](_memory_record.md) | 设备内存信息 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [MemoryTrackerType](_memory_tracker.md#memorytrackertype) {<br/>MEMORY_TRACKER_TYPE_MM = 0 , MEMORY_TRACKER_TYPE_GL = 1 , MEMORY_TRACKER_TYPE_CAM = 2 , MEMORY_TRACKER_TYPE_GRAPH = 3 , MEMORY_TRACKER_TYPE_OTHER = 4 , MEMORY_TRACKER_TYPE_COUNTS<br/>} | 内存类型 | 
| [MemoryTrackerFlag](_memory_tracker.md#memorytrackerflag) {<br/>FLAG_SHARED_RSS = 2 , FLAG_SHARED_PSS = 4 , FLAG_PRIVATE = 8 , FLAG_MAPPED = 16 , FLAG_UNMAPPED = 32 , FLAG_PROTECTED = 64 , FLAG_UNPROTECTED = 128 , FLAG_SYSTEM = 256 , FLAG_SYSTEM_EXCEPT = 512<br/>} | 内存类型标记 | 
