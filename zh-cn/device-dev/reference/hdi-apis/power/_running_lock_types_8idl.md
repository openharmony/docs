# RunningLockTypes.idl


## 概述

枚举与运行锁管理相关的数据类型。

这些数据类型包括运行锁类型和运行锁信息。

**起始版本：** 4.0

**相关模块：**[Power](power-v12.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[RunningLockInfo](_running_lock_info.md) | 定义运行锁的信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [BaseRunningLockType](power-v12.md#baserunninglocktype) { <br/>[RUNNINGLOCK_SCREEN](power-v12.md) = 0, <br/>[RUNNINGLOCK_BACKGROUND](power-v12.md) = 1, <br/>[RUNNINGLOCK_PROXIMITY_SCREEN_CONTROL](power-v12.md) = 2 <br/>} | 枚举基本运行锁类型。 | 
| [RunningLockType](power-v12.md#runninglocktype) {<br/>[RUNNINGLOCK_BACKGROUND_PHONE](power-v12.md) = 3, <br/>[RUNNINGLOCK_BACKGROUND_NOTIFICATION](power-v12.md) = 5, <br/>[RUNNINGLOCK_BACKGROUND_AUDIO](power-v12.md) = 9, <br/>[RUNNINGLOCK_BACKGROUND_SPORT](power-v12.md) = 17,<br/>[RUNNINGLOCK_BACKGROUND_NAVIGATION](power-v12.md) = 33, <br/>[RUNNINGLOCK_BACKGROUND_TASK](power-v12.md) = 65, <br/>[RUNNINGLOCK_BUTT](power-v12.md)<br/>} | 枚举运行锁类型。 | 
