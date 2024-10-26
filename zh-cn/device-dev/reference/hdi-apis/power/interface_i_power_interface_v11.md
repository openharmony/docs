# IPowerInterface


## 概述

休眠/唤醒操作、订阅休眠/唤醒状态、运行锁管理的接口。

**起始版本：** 3.1

**相关模块：**[Power](power_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [RegisterCallback](#registercallback) ([in] [IPowerHdiCallback](interface_i_power_hdi_callback_v11.md) ipowerHdiCallback) | 注册休眠/唤醒状态的回调。  | 
| [StartSuspend](#startsuspend) () | 执行设备休眠操作。  | 
| [StopSuspend](#stopsuspend) () | 执行设备唤醒操作。  | 
| [ForceSuspend](#forcesuspend) () | 执行设备强制休眠操作。  | 
| [SuspendBlock](#suspendblock) ([in] String name) | 打开运行锁，阻止休眠。  | 
| [SuspendUnblock](#suspendunblock) ([in] String name) | 关闭运行锁，取消阻止休眠。  | 
| [PowerDump](#powerdump) ([out] String info) | 获取电源的Dump信息。  | 
| [HoldRunningLock](#holdrunninglock) ([in] struct [RunningLockInfo](_running_lock_info_v11.md) info) | 持有运行锁，阻止设备休眠。  | 
| [UnholdRunningLock](#unholdrunninglock) ([in] struct [RunningLockInfo](_running_lock_info_v11.md) info) | 解除运行锁，解除设备休眠。  | 


## 成员函数说明


### ForceSuspend()

```
IPowerInterface::ForceSuspend ()
```
**描述**

执行设备强制休眠操作。

**起始版本：** 3.1

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。


### HoldRunningLock()

```
IPowerInterface::HoldRunningLock ([in] struct RunningLockInfo info)
```
**描述**

持有运行锁，阻止设备休眠。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 输入参数，运行锁信息。 | 

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。


### PowerDump()

```
IPowerInterface::PowerDump ([out] String info)
```
**描述**

获取电源的Dump信息。

**起始版本：** 3.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 输出参数，电源的Dump信息。 | 

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。


### RegisterCallback()

```
IPowerInterface::RegisterCallback ([in] IPowerHdiCallback ipowerHdiCallback)
```
**描述**

注册休眠/唤醒状态的回调。

**起始版本：** 3.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ipowerHdiCallback | 输入参数，服务注册的回调。 | 

**返回：**

HDF_SUCCESS 表示注册成功。

HDF_FAILED 表示注册失败。

**参见：**

[IPowerHdiCallback](interface_i_power_hdi_callback_v11.md)


### StartSuspend()

```
IPowerInterface::StartSuspend ()
```
**描述**

执行设备休眠操作。

**起始版本：** 3.1

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。


### StopSuspend()

```
IPowerInterface::StopSuspend ()
```
**描述**

执行设备唤醒操作。

**起始版本：** 3.1

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。


### SuspendBlock()

```
IPowerInterface::SuspendBlock ([in] String name)
```
**描述**

打开运行锁，阻止休眠。

**起始版本：** 3.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 输入参数，运行锁的名称。 | 

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。


### SuspendUnblock()

```
IPowerInterface::SuspendUnblock ([in] String name)
```
**描述**

关闭运行锁，取消阻止休眠。

**起始版本：** 3.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 输入参数，运行锁的名称。 | 

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。


### UnholdRunningLock()

```
IPowerInterface::UnholdRunningLock ([in] struct RunningLockInfo info)
```
**描述**

解除运行锁，解除设备休眠。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 输入参数，运行锁信息。 | 

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。
