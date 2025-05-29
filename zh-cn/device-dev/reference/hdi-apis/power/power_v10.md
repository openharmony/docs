# Power (V1_0)


## 概述

提供休眠/唤醒操作、订阅休眠/唤醒状态和运行锁管理的接口。

电源模块为电源服务提供的休眠/唤醒操作、订阅休眠/唤醒状态和运行锁管理的接口。 服务获取此模块的对象或代理后，可以调用相关的接口对设备进行休眠/唤醒、订阅休眠/唤醒状态和管理运行锁。

**起始版本：** 3.1


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IPowerHdiCallback.idl](_i_power_hdi_callback_8idl_v10.md) | 休眠/唤醒状态的回调。 | 
| [IPowerInterface.idl](_i_power_interface_8idl_v10.md) | 休眠/唤醒操作、订阅休眠/唤醒状态、运行锁管理的接口。 | 
| [PowerTypes.idl](_power_types_8idl_v10.md) | 电源相关的数据类型。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IPowerHdiCallback](interface_i_power_hdi_callback_v10.md) | 休眠/唤醒状态的回调。 | 
| interface&nbsp;&nbsp;[IPowerInterface](interface_i_power_interface_v10.md) | 休眠/唤醒操作、订阅休眠/唤醒状态、运行锁管理的接口。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [PowerHdfCmd](#powerhdfcmd) { CMD_REGISTER_CALLBCK = 0, CMD_START_SUSPEND, CMD_STOP_SUSPEND, CMD_FORCE_SUSPEND,&nbsp;&nbsp;&nbsp;CMD_SUSPEND_BLOCK, CMD_SUSPEND_UNBLOCK, CMD_DUMP } | 枚举电源命令的参数。 | 
| [PowerHdfCallbackCmd](#powerhdfcallbackcmd) { CMD_ON_SUSPEND = 0, CMD_ON_WAKEUP } | 枚举电源状态回调的参数。 | 
| [PowerHdfState](#powerhdfstate) { AWAKE = 0, INACTIVE, SLEEP } | 枚举电源的状态。 | 


## 枚举类型说明


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
| CMD_REGISTER_CALLBCK | 订阅状态的命令参数。 | 
| CMD_START_SUSPEND | 休眠的命令参数。 | 
| CMD_STOP_SUSPEND | 唤醒的命令参数。 | 
| CMD_FORCE_SUSPEND | 强制休眠的命令参数。 | 
| CMD_SUSPEND_BLOCK | 打开运行锁的命令参数。 | 
| CMD_SUSPEND_UNBLOCK | 关闭运行锁的命令参数。 | 
| CMD_DUMP | Dump的命令参数。 | 


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
