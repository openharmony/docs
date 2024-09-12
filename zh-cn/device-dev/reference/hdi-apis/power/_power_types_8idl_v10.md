# PowerTypes.idl


## 概述

电源相关的数据类型。

电源管理中使用的数据类型，包括命令参数、回调参数和系统状态。

模块包路径：ohos.hdi.power.v1_0

**起始版本：** 3.1

**相关模块：**[Power](power_v10.md)


## 汇总


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [PowerHdfCmd](power_v10.md#powerhdfcmd) { CMD_REGISTER_CALLBCK = 0, CMD_START_SUSPEND, CMD_STOP_SUSPEND, CMD_FORCE_SUSPEND,&nbsp;&nbsp;&nbsp;CMD_SUSPEND_BLOCK, CMD_SUSPEND_UNBLOCK, CMD_DUMP } | 枚举电源命令的参数。 | 
| [PowerHdfCallbackCmd](power_v10.md#powerhdfcallbackcmd) { CMD_ON_SUSPEND = 0, CMD_ON_WAKEUP } | 枚举电源状态回调的参数。 | 
| [PowerHdfState](power_v10.md#powerhdfstate) { AWAKE = 0, INACTIVE, SLEEP } | 枚举电源的状态。 | 
