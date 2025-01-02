# Power (V1_1)


## 概述

提供休眠/唤醒操作、订阅休眠/唤醒状态、运行锁管理的接口。

电源模块为电源服务提供的休眠/唤醒操作、订阅休眠/唤醒状态和运行锁管理的接口。 服务获取此模块的对象或代理后，可以调用相关的接口对设备进行休眠/唤醒、订阅休眠/唤醒状态和管理运行锁。

**起始版本：** 3.1


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IPowerHdiCallback.idl](_i_power_hdi_callback_8idl_v11.md) | 休眠/唤醒状态的回调。 | 
| [IPowerInterface.idl](_i_power_interface_8idl_v11.md) | 休眠/唤醒操作、订阅休眠/唤醒状态、运行锁管理的接口。 | 
| [PowerTypes.idl](_power_types_8idl_v11.md) | 电源相关的数据类型。 | 
| [RunningLockTypes.idl](_running_lock_types_8idl_v11.md) | 枚举与运行锁管理相关的数据类型。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IPowerHdiCallback](interface_i_power_hdi_callback_v11.md) | 休眠/唤醒状态的回调。 | 
| interface&nbsp;&nbsp;[IPowerInterface](interface_i_power_interface_v11.md) | 休眠/唤醒操作、订阅休眠/唤醒状态、运行锁管理的接口。 | 
| struct&nbsp;&nbsp;[RunningLockInfo](_running_lock_info_v11.md) | 定义运行锁的信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [PowerHdfCmd](#powerhdfcmd) {<br/>CMD_REGISTER_CALLBCK = 0, CMD_START_SUSPEND, CMD_STOP_SUSPEND, CMD_FORCE_SUSPEND,&nbsp;&nbsp;&nbsp;CMD_SUSPEND_BLOCK, CMD_SUSPEND_UNBLOCK, CMD_DUMP<br/>} | 枚举电源命令的参数。 | 
| [PowerHdfCallbackCmd](#powerhdfcallbackcmd) { CMD_ON_SUSPEND = 0, CMD_ON_WAKEUP } | 枚举电源状态回调的参数。 | 
| [PowerHdfState](#powerhdfstate) { AWAKE = 0, INACTIVE, SLEEP } | 枚举电源的状态。 | 
| [BaseRunningLockType](#baserunninglocktype) { RUNNINGLOCK_SCREEN = 0 , RUNNINGLOCK_BACKGROUND = 1 , RUNNINGLOCK_PROXIMITY_SCREEN_CONTROL = 2 } | 枚举基本运行锁类型。 | 
| [RunningLockType](#runninglocktype) {<br/>RUNNINGLOCK_BACKGROUND_PHONE = 3 , RUNNINGLOCK_BACKGROUND_NOTIFICATION = 5 , RUNNINGLOCK_BACKGROUND_AUDIO = 9 , RUNNINGLOCK_BACKGROUND_SPORT = 17 , RUNNINGLOCK_BACKGROUND_NAVIGATION = 33 , RUNNINGLOCK_BACKGROUND_TASK = 65 , RUNNINGLOCK_BUTT<br/>} | 枚举运行锁类型。 | 


## 枚举类型说明


### BaseRunningLockType

```
enum BaseRunningLockType
```

**描述**


枚举基本运行锁类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| RUNNINGLOCK_SCREEN | 用于保持屏幕处于开启状态。 | 
| RUNNINGLOCK_BACKGROUND | 用于保持 CPU 处于运行状态，锁屏状态下继续完成后台任务。 | 
| RUNNINGLOCK_PROXIMITY_SCREEN_CONTROL | 通过传感器控制屏幕的开关。 | 


### PowerHdfCallbackCmd

```
enum PowerHdfCallbackCmd
```

**描述**


枚举电源状态回调的参数。

**起始版本：** 3.1

| 枚举值 | 描述 | 
| -------- | -------- |
| CMD_ON_SUSPEND | 休眠回调的命令参数。 | 
| CMD_ON_WAKEUP | 唤醒回调的命令参数。 | 


### PowerHdfCmd

```
enum PowerHdfCmd
```

**描述**


枚举电源命令的参数。

**起始版本：** 3.1

| 枚举值 | 描述 | 
| -------- | -------- |
| CMD_REGISTER_CALLBCK | 订阅状态的命令参数 | 
| CMD_START_SUSPEND | 休眠的命令参数 | 
| CMD_STOP_SUSPEND | 唤醒的命令参数 | 
| CMD_FORCE_SUSPEND | 强制休眠的命令参数 | 
| CMD_SUSPEND_BLOCK | 打开运行锁的命令参数 | 
| CMD_SUSPEND_UNBLOCK | 关闭运行锁的命令参数 | 
| CMD_DUMP | Dump的命令参数 | 


### PowerHdfState

```
enum PowerHdfState
```

**描述**


枚举电源的状态。

**起始版本：** 3.1

| 枚举值 | 描述 | 
| -------- | -------- |
| AWAKE | 唤醒状态。 | 
| INACTIVE | 非活动状态。 | 
| SLEEP | 休眠状态。 | 


### RunningLockType

```
enum RunningLockType
```

**描述**


枚举运行锁类型。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| RUNNINGLOCK_BACKGROUND_PHONE | 用于保持后台手机任务的完成。 | 
| RUNNINGLOCK_BACKGROUND_NOTIFICATION | 用于保持后台通知任务完成。 | 
| RUNNINGLOCK_BACKGROUND_AUDIO | 用于保持后台音频任务完成。 | 
| RUNNINGLOCK_BACKGROUND_SPORT | 用于保持后台运动任务的完成。 | 
| RUNNINGLOCK_BACKGROUND_NAVIGATION | 用于保持后台导航任务的完成。 | 
| RUNNINGLOCK_BACKGROUND_TASK | 用于保持后台常见任务的完成。 | 
| RUNNINGLOCK_BUTT | 预留运行锁类型。 | 
