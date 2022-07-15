# PowerTypes.idl


## **概述**

**所属模块:**

[Power](power.md)


## **汇总**


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [PowerHdfCmd](power.md#powerhdfcmd)&nbsp;{&nbsp;&nbsp;&nbsp;[CMD_REGISTER_CALLBCK](power.md#gga0c9f68a1cf4b1b76a8253281688a499fadb8d2fd75158645b1cd01cab62a11e48)&nbsp;=&nbsp;0,&nbsp;[CMD_START_SUSPEND](power.md#gga0c9f68a1cf4b1b76a8253281688a499fab1d1e95415b8a9ab070fed3200b5f1d3),&nbsp;[CMD_STOP_SUSPEND](power.md#gga0c9f68a1cf4b1b76a8253281688a499fa65c754fdc432aa2a6f13c27cb97c27de),&nbsp;[CMD_FORCE_SUSPEND](power.md#gga0c9f68a1cf4b1b76a8253281688a499faa96402e649008dcafce89c7a47c6f266),&nbsp;&nbsp;&nbsp;[CMD_SUSPEND_BLOCK](power.md#gga0c9f68a1cf4b1b76a8253281688a499fa0766f8c155a9de9fc7168a498c8317da),&nbsp;[CMD_SUSPEND_UNBLOCK](power.md#gga0c9f68a1cf4b1b76a8253281688a499fa840d1fd2227dfea25fcee7217deb82ed),&nbsp;[CMD_DUMP](power.md#gga0c9f68a1cf4b1b76a8253281688a499fab92b7d7125239e258bd22cd1a35aba0d)&nbsp;} | 枚举电源命令的参数。&nbsp;[更多...](power.md#powerhdfcmd) | 
| [PowerHdfCallbackCmd](power.md#powerhdfcallbackcmd)&nbsp;{&nbsp;[CMD_ON_SUSPEND](power.md#gga4bbb7ca0dc24efe3980c39cd409b4109a6d4a3ebd4580d7303df66d5ea9ad98d1)&nbsp;=&nbsp;0,&nbsp;[CMD_ON_WAKEUP](power.md#gga4bbb7ca0dc24efe3980c39cd409b4109a4d0194285647be62fe2c191cad95e72f)&nbsp;} | 枚举电源状态回调的参数。&nbsp;[更多...](power.md#powerhdfcallbackcmd) | 
| [PowerHdfState](power.md#powerhdfstate)&nbsp;{&nbsp;[AWAKE](power.md#ggadf82dc0e2ae04729ac8fabb3e3d28ecda65e803ac3fb48fa726e326f3c63c2d83)&nbsp;=&nbsp;0,&nbsp;[INACTIVE](power.md#ggadf82dc0e2ae04729ac8fabb3e3d28ecda3ff8ba88da6f8947ab7c22b7825c6bb6),&nbsp;[SLEEP](power.md#ggadf82dc0e2ae04729ac8fabb3e3d28ecdad6137abebe4fdc59e2f0f2c84bdbe3fa)&nbsp;} | 枚举电源的状态。&nbsp;[更多...](power.md#powerhdfstate) | 


### 变量

  | 变量&nbsp;名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.power.v1_0 | 电源管理接口的包路径 | 


## **详细描述**

电源相关的数据类型。

电源管理中使用的数据类型，包括命令参数、回调参数和系统状态。

**Since：**

3.1

**Version：**

1.0
