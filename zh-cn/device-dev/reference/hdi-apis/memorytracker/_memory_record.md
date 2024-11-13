# MemoryRecord


## 概述

设备内存信息

**起始版本：** 3.2

**相关模块：**[MemoryTracker](_memory_tracker.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [flags](#flags) | 内存类型标记，可选类型请参考[MemoryTrackerFlag](_memory_tracker.md#memorytrackerflag)。 | 
| long [size](#size) | 该类型内存大小，以字节为单位。 | 


## 类成员变量说明


### flags

```
int MemoryRecord::flags
```

**描述**

内存类型标记，可选类型请参考[MemoryTrackerFlag](_memory_tracker.md#memorytrackerflag)。


### size

```
long MemoryRecord::size
```

**描述**

该类型内存大小，以字节为单位。
