# PowerTypes.idl


## **概述**

电源相关的数据类型。

电源管理中使用的数据类型，包括命令参数、回调参数和系统状态。

**Since:**

3.1

**Version:**

1.0

**相关模块:**

[Power](power.md)


## **汇总**


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [PowerHdfCmd](power.md#powerhdfcmd)&nbsp;{&nbsp;&nbsp;&nbsp;CMD_REGISTER_CALLBCK&nbsp;=&nbsp;0,&nbsp;CMD_START_SUSPEND,&nbsp;CMD_STOP_SUSPEND,&nbsp;CMD_FORCE_SUSPEND,&nbsp;&nbsp;&nbsp;CMD_SUSPEND_BLOCK,&nbsp;CMD_SUSPEND_UNBLOCK,&nbsp;CMD_DUMP&nbsp;} | 枚举电源命令的参数。 | 
| [PowerHdfCallbackCmd](power.md#powerhdfcallbackcmd)&nbsp;{&nbsp;CMD_ON_SUSPEND&nbsp;=&nbsp;0,&nbsp;CMD_ON_WAKEUP&nbsp;} | 枚举电源状态回调的参数。 | 
| [PowerHdfState](power.md#powerhdfstate)&nbsp;{&nbsp;AWAKE&nbsp;=&nbsp;0,&nbsp;INACTIVE,&nbsp;SLEEP&nbsp;} | 枚举电源的状态。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.power.v1_0 | 电源模块接口的包路径。 | 
