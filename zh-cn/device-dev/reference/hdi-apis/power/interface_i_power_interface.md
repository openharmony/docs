# IPowerInterface


## 概述

休眠/唤醒操作、订阅休眠/唤醒状态、运行锁管理的接口。

**起始版本：** 3.1

**相关模块：**[Power](power-v13.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [RegisterPowerCallbackExt](#registerpowercallbackext) ([in] [IPowerHdiCallbackExt](interface_i_power_hdi_callback_ext.md) ipowerHdiCallback) | 注册带标记的休眠/唤醒状态的回调。 | 
| [UnRegisterPowerCallbackExt](#unregisterpowercallbackext) ([in] [IPowerHdiCallbackExt](interface_i_power_hdi_callback_ext.md) ipowerHdiCallback) | 注销带标记的休眠/唤醒状态的回调。 | 


## 成员函数说明


### RegisterPowerCallbackExt()

```
IPowerInterface::RegisterPowerCallbackExt([in] IPowerHdiCallbackExt ipowerHdiCallback)
```

**描述**

注册带标记的休眠/唤醒状态的回调。

**起始版本：** 6.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ipowerHdiCallback | 输入参数，服务注册的回调。 | 

**返回：**

HDF_SUCCESS 表示注册成功，其它返回值表示注册失败。

**参见：**

[IPowerHdiCallbackExt](interface_i_power_hdi_callback_ext.md)


### UnRegisterPowerCallbackExt()

```
IPowerInterface::UnRegisterPowerCallbackExt([in] IPowerHdiCallbackExt ipowerHdiCallback)
```

**描述**

注销带标记的休眠/唤醒状态的回调。

**起始版本：** 6.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ipowerHdiCallback | 输入参数，服务注销的回调。 | 

**返回：**

HDF_SUCCESS 表示注销成功，其它返回值表示注销失败。

**参见：**

[IPowerHdiCallbackExt](interface_i_power_hdi_callback_ext.md)
