# IMemoryTrackerInterface


## 概述

用于获取指定类型的设备内存信息的接口。

需要查询GPU等外设内存占用时使用，例如hidumper中使用本接口列出每个进程的GPU内存占用。

**起始版本：** 3.2

**相关模块：**[MemoryTracker](_memory_tracker.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetDevMem](#getdevmem) ([in] int pid, [in] enum [MemoryTrackerType](_memory_tracker.md#memorytrackertype) type, [out] struct [MemoryRecord](_memory_record.md)[] records) | 获取指定类型的设备内存信息。 | 


## 成员函数说明


### GetDevMem()

```
IMemoryTrackerInterface::GetDevMem ([in] int pid, [in] enum MemoryTrackerType type, [out] struct MemoryRecord[] records )
```

**描述**

获取指定类型的设备内存信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pid | 表示进程的id，若pid为0则表示获取所有进程的内存记录。 | 
| type | 表示内存类型。 | 
| records | 表示内存记录列表。 | 

**返回：**

若操作成功，返回值为**0**。

若操作失败，返回值为负值。
