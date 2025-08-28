# PowerTypes.idl


## 概述

电源相关的数据类型。

电源管理中使用的数据类型，包括命令参数、回调参数和系统状态。

**起始版本：** 3.1

**相关模块：**[Power](power-v12.md)


## 汇总


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [PowerHdfCmd](power-v12.md#powerhdfcmd) {<br/>[CMD_REGISTER_CALLBCK](power-v12.md) = 0,<br/>[CMD_START_SUSPEND](power-v12.md), <br/>[CMD_STOP_SUSPEND](power-v12.md), <br/>[CMD_FORCE_SUSPEND](power-v12.md),<br/>[CMD_SUSPEND_BLOCK](power-v12.md), <br/>[CMD_SUSPEND_UNBLOCK](power-v12.md), <br/>[CMD_DUMP](power-v12.md)<br/>} | 枚举电源命令的参数。 | 
| [PowerHdfCallbackCmd](power-v12.md#powerhdfcallbackcmd) { <br/>[CMD_ON_SUSPEND](power-v12.md) = 0, <br/>[CMD_ON_WAKEUP](power-v12.md) } | 枚举电源状态回调的参数。 | 
| [PowerHdfState](power-v12.md#powerhdfstate) { <br/>[AWAKE](power-v12.md) = 0, <br/>[INACTIVE](power-v12.md), <br/>[SLEEP](power-v12.md) } | 枚举电源的状态。 | 
