# IPowerInterface.idl


## 概述

休眠/唤醒状态的回调。

电源模块为电源服务提供的订阅休眠/唤醒状态的回调。

**起始版本：** 3.1

**相关模块：**[Power](power-v12.md)


## 汇总


### 结构体

| 名称 | 描述                                                                       | 
| -------- |--------------------------------------------------------------------------|
| interface&nbsp;&nbsp;[IPowerHdiCallback](interface_i_power_hdi_callback.md) | 休眠/唤醒状态的回调。<br>服务创建此回调对象后，可以调用[IPowerInterface](interface_i_power_interface.md)的接口注册回调，从而订阅休眠/唤醒状态的变化。 | 
