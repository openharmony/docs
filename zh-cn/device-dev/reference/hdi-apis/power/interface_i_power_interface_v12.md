# IPowerInterface


## 概述

休眠/唤醒操作、订阅休眠/唤醒状态、运行锁管理的接口。

**起始版本：** 3.1

**相关模块：**[Power](power-v12.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [RegisterCallback](#registercallback) ([in] [IPowerHdiCallback](interface_i_power_hdi_callback.md) ipowerHdiCallback) | 注册休眠/唤醒状态的回调。 | 
| [StartSuspend](#startsuspend) () | 执行设备休眠操作。 | 
| [StopSuspend](#stopsuspend) () | 执行设备唤醒操作。 | 
| [ForceSuspend](#forcesuspend) () | 执行设备强制休眠操作。 | 
| [SuspendBlock](#suspendblock) ([in] String name) | 打开运行锁，阻止休眠。 | 
| [SuspendUnblock](#suspendunblock) ([in] String name) | 关闭运行锁，取消阻止休眠。 | 
| [PowerDump](#powerdump) ([out] String info) | 获取电源的Dump信息。 | 
| [HoldRunningLock](#holdrunninglock) ([in] struct [RunningLockInfo](_running_lock_info.md) info) | 持有运行锁，阻止设备休眠。 | 
| [UnholdRunningLock](#unholdrunninglock) ([in] struct [RunningLockInfo](_running_lock_info.md) info) | 解除运行锁，解除设备休眠。 | 
| [GetWakeupReason](#getwakeupreason) ([out] String reason) | 获取系统唤醒原因。 | 
| [HoldRunningLockExt](#holdrunninglockext) ([in] struct [RunningLockInfo](_running_lock_info.md) info, [in] unsigned long lockid, [in] String bundleName) | 持有运行锁，阻止设备休眠。 | 
| [UnholdRunningLockExt](#unholdrunninglockext) ([in] struct [RunningLockInfo](_running_lock_info.md) info, [in] unsigned long lockid, [in] String bundleName) | 解除运行锁，解除设备休眠。 | 
| [RegisterRunningLockCallback](#registerrunninglockcallback) ([in] [IPowerRunningLockCallback](interface_i_power_running_lock_callback.md) iPowerRunningLockCallback) | 注册运行锁状态的回调函数。 | 
| [UnRegisterRunningLockCallback](#unregisterrunninglockcallback) () | 取消注册运行锁状态的回调函数。 | 
| [Hibernate](#hibernate) () | 使设备进入S4休眠状态。 | 
| [SetSuspendTag](#setsuspendtag) ([in] String tag) | 在休眠前设置休眠标签。 通过设置特殊的休眠标签触发休眠，触发内核和硬件支持的特殊休眠模式。 如果没有设置休眠标签，则在休眠时触发标准S3休眠模式。 | 
| [SetPowerConfig](#setpowerconfig) ([in] String scene, [in] String value) | 设置与场景名称相关的设置路径文件值。 | 
| [GetPowerConfig](#getpowerconfig) ([in] String scene, [out] String value) | 获取与场景名称相关的获取路径文件值。 | 


## 成员函数说明


### ForceSuspend()

```
IPowerInterface::ForceSuspend()
```

**描述**

执行设备强制休眠操作。

**起始版本：** 3.1

**返回：**

HDF_SUCCESS 表示强制休眠成功；返回其他值表示强制休眠失败。


### GetPowerConfig()

```
IPowerInterface::GetPowerConfig([in] String scene, [out] String value)
```

**描述**

获取与场景名称相关的获取路径文件值。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| scene | 电源配置json文件中定义的场景名称。 | 
| value | 获取路径文件的值。 | 

**返回：**

HDF_SUCCESS 表示操作成功；返回其他值表示操作失败。


### GetWakeupReason()

```
IPowerInterface::GetWakeupReason([out] String reason)
```

**描述**

获取系统唤醒原因。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| reason | 唤醒原因。 | 

**返回：**

HDF_SUCCESS 表示操作成功；返回其他值表示操作失败。


### Hibernate()

```
IPowerInterface::Hibernate()
```

**描述**

使设备进入S4休眠状态。

**起始版本：** 5.0

**返回：**

HDF_SUCCESS 表示操作成功；返回其他值表示操作失败。


### HoldRunningLock()

```
IPowerInterface::HoldRunningLock([in] struct RunningLockInfo info)
```

**描述**

持有运行锁，阻止设备休眠。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 输入参数，运行锁信息。 | 

**返回：**

HDF_SUCCESS 表示操作成功；返回其他值表示操作失败。


### HoldRunningLockExt()

```
IPowerInterface::HoldRunningLockExt([in] struct RunningLockInfo info, [in] unsigned long lockid, [in] String bundleName)
```

**描述**

持有运行锁，阻止设备休眠。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 输入参数，运行锁扩展信息。 | 
| lockid | 输入参数，运行锁id。 | 
| bundleName | 输入参数，应用包名。 | 

**返回：**

HDF_SUCCESS 表示操作成功；返回其他值表示操作失败。


### PowerDump()

```
IPowerInterface::PowerDump([out] String info)
```

**描述**

获取电源的Dump信息。

**起始版本：** 3.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 输出参数，电源的Dump信息。 | 

**返回：**

HDF_SUCCESS 表示操作成功；返回其他值表示操作失败。


### RegisterCallback()

```
IPowerInterface::RegisterCallback([in] IPowerHdiCallback ipowerHdiCallback)
```

**描述**

注册休眠/唤醒状态的回调。

**起始版本：** 3.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ipowerHdiCallback | 输入参数，服务注册的回调。 | 

**返回：**

HDF_SUCCESS 表示注册成功，其它返回值表示注册失败。

**参见：**

[IPowerHdiCallback](interface_i_power_hdi_callback.md)


### RegisterRunningLockCallback()

```
IPowerInterface::RegisterRunningLockCallback([in] IPowerRunningLockCallback iPowerRunningLockCallback)
```

**描述**

注册运行锁状态的回调函数。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| iPowerRunningLockCallback | 注册的回调信息。 | 

**返回：**

HDF_SUCCESS 表示操作成功；返回其他值表示操作失败。

**参见：**

[IPowerRunningLockCallback](interface_i_power_running_lock_callback.md)


### SetPowerConfig()

```
IPowerInterface::SetPowerConfig([in] String scene, [in] String value)
```

**描述**

设置与场景名称相关的设置路径文件值。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| scene | 在电源配置JSON文件中定义的场景名称。 | 
| value | 设置路径文件的值。 | 

**返回：**

HDF_SUCCESS 表示操作成功；返回其他值表示操作失败。


### SetSuspendTag()

```
IPowerInterface::SetSuspendTag([in] String tag)
```

**描述**

在休眠前设置休眠标签。 通过设置特殊的休眠标签触发休眠，触发内核和硬件支持的特殊休眠模式。 如果没有设置休眠标签，则在休眠时触发标准S3休眠模式。

**起始版本：** 5.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tag | 休眠标签。 | 

**返回：**

HDF_SUCCESS 表示操作成功；返回其他值表示操作失败。


### StartSuspend()

```
IPowerInterface::StartSuspend()
```

**描述**

执行设备休眠操作。

**起始版本：** 3.1

**返回：**

HDF_SUCCESS 表示休眠成功，其它返回值表示休眠失败。


### StopSuspend()

```
IPowerInterface::StopSuspend()
```

**描述**

执行设备唤醒操作。

**起始版本：** 3.1

**返回：**

HDF_SUCCESS 表示唤醒成功；返回其他值表示唤醒失败。


### SuspendBlock()

```
IPowerInterface::SuspendBlock([in] String name)
```

**描述**

打开运行锁，阻止休眠。

**起始版本：** 3.1

**废弃版本：** 从4.0版本起废弃，使用WriteWakeCount替代。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 输入参数，运行锁的名称。 | 

**返回：**

HDF_SUCCESS 表示操作成功；返回其他值表示操作失败。


### SuspendUnblock()

```
IPowerInterface::SuspendUnblock([in] String name)
```

**描述**

关闭运行锁，取消阻止休眠。

**起始版本：** 3.1

**废弃版本：** 从4.0版本起废弃，使用WriteWakeCount替代。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 输入参数，运行锁的名称。 | 

**返回：**

HDF_SUCCESS 表示操作成功；返回其他值表示操作失败。


### UnholdRunningLock()

```
IPowerInterface::UnholdRunningLock([in] struct RunningLockInfo info)
```

**描述**

解除运行锁，解除设备休眠。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 输入参数，运行锁信息。 | 

**返回：**

HDF_SUCCESS 表示操作成功；返回其他值表示操作失败。


### UnholdRunningLockExt()

```
IPowerInterface::UnholdRunningLockExt([in] struct RunningLockInfo info, [in] unsigned long lockid, [in] String bundleName)
```

**描述**

解除运行锁，解除设备休眠。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 输入参数，运行锁扩展信息。 | 
| lockid | 输入参数，运行锁id。 | 
| bundleName | 输入参数，应用包名。 | 

**返回：**

HDF_SUCCESS 表示操作成功；返回其他值表示操作失败。


### UnRegisterRunningLockCallback()

```
IPowerInterface::UnRegisterRunningLockCallback()
```

**描述**

取消注册运行锁状态的回调函数。

**起始版本：** 4.1

**返回：**

HDF_SUCCESS 表示操作成功；返回其他值表示操作失败。