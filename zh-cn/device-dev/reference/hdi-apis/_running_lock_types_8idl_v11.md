# RunningLockTypes.idl


## 概述

枚举与运行锁管理相关的数据类型。

这些数据类型包括运行锁类型和运行锁信息。

模块包路径：ohos.hdi.power.v1_1

**起始版本：** 4.0

**相关模块：**[Power](power_v11.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[RunningLockInfo](_running_lock_info_v11.md) | 定义运行锁的信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [BaseRunningLockType](power_v11.md#baserunninglocktype) { RUNNINGLOCK_SCREEN = 0 , RUNNINGLOCK_BACKGROUND = 1 , RUNNINGLOCK_PROXIMITY_SCREEN_CONTROL = 2 }<br/>[RunningLockType](power_v11.md#runninglocktype) {<br/>RUNNINGLOCK_BACKGROUND_PHONE = 3 , RUNNINGLOCK_BACKGROUND_NOTIFICATION = 5 , RUNNINGLOCK_BACKGROUND_AUDIO = 9 , RUNNINGLOCK_BACKGROUND_SPORT = 17 , RUNNINGLOCK_BACKGROUND_NAVIGATION = 33 , RUNNINGLOCK_BACKGROUND_TASK = 65 , RUNNINGLOCK_BUTT<br/>} | 枚举基本运行锁类型。 | 
| [BaseRunningLockType](power_v11.md#baserunninglocktype) { RUNNINGLOCK_SCREEN = 0 , RUNNINGLOCK_BACKGROUND = 1 , RUNNINGLOCK_PROXIMITY_SCREEN_CONTROL = 2 }<br/>[RunningLockType](power_v11.md#runninglocktype) {<br/>RUNNINGLOCK_BACKGROUND_PHONE = 3 , RUNNINGLOCK_BACKGROUND_NOTIFICATION = 5 , RUNNINGLOCK_BACKGROUND_AUDIO = 9 , RUNNINGLOCK_BACKGROUND_SPORT = 17 , RUNNINGLOCK_BACKGROUND_NAVIGATION = 33 , RUNNINGLOCK_BACKGROUND_TASK = 65 , RUNNINGLOCK_BUTT<br/>} | 枚举运行锁类型。 | 
