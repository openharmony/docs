# Power（V1_3）


## 概述

提供休眠/唤醒操作、订阅休眠/唤醒状态、运行锁管理的接口。

电源模块为电源服务提供的休眠/唤醒操作、订阅休眠/唤醒状态和运行锁管理的接口。 服务获取此模块的对象或代理后，可以调用相关的接口对设备进行休眠/唤醒、订阅休眠/唤醒状态和管理运行锁。

电源模块为电源服务提供的休眠/唤醒操作、订阅休眠/唤醒状态和运行锁管理的接口。 服务获取此模块的对象或代理后，可以调用相关的接口对设备进行休眠/唤醒、订阅休眠/唤醒状态和管理运行锁。

**起始版本：** 3.1


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IPowerHdiCallbackExt.idl](_i_power_hdi_callback_ext_8idl.md) | 提供带标记的休眠/唤醒状态变化的回调接口。电源模块为电源服务提供的订阅带标记的休眠/唤醒状态变化的回调。 | 
| [IPowerInterface.idl](_i_power_interface_8idl.md) | 休眠/唤醒操作、订阅休眠/唤醒状态、运行锁管理的接口。电源模块为电源服务提供休眠/唤醒操作、订阅休眠/唤醒状态和运行锁管理的接口。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IPowerHdiCallbackExt](interface_i_power_hdi_callback_ext.md) | 带标记的休眠/唤醒状态的回调。服务创建此回调对象后，可以调用 [IPowerInterface](interface_i_power_interface.md)的接口注册回调，从而订阅带标记的休眠/唤醒状态的变化。这个回调必须通过调用[IPowerInterface](interface_i_power_interface.md)的RegisterPowerCallbackExt接口与UnRegisterRunningLockCallback接口进行注册回调与注销回调。 | 
| interface&nbsp;&nbsp;[IPowerInterface](interface_i_power_interface.md) | 休眠/唤醒操作、订阅休眠/唤醒状态、运行锁管理的接口。 | 
