# InputReporter


## 概述

提供Input设备数据上报相关的接口。

此类接口包含Input设备的数据上报回调函数的注册和注销。

**起始版本：** 1.0

**相关模块：**[Input](_input.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int32_t(\* [RegisterReportCallback](#registerreportcallback) )(uint32_t devIndex, [InputEventCb](_input_event_cb.md) \*callback) | 注册对应设备的回调函数。  | 
| int32_t(\* [UnregisterReportCallback](#unregisterreportcallback) )(uint32_t devIndex) | 注销对应设备的回调函数。  | 
| int32_t(\* [RegisterHotPlugCallback](#registerhotplugcallback) )([InputHostCb](_input_host_cb.md) \*callback) | 注册Input设备的热插拔回调函数。  | 
| int32_t(\* [UnregisterHotPlugCallback](#unregisterhotplugcallback) )(void) | 注销Input设备的热插拔回调函数。  | 


## 类成员变量说明


### RegisterHotPlugCallback

```
int32_t(* InputReporter::RegisterHotPlugCallback) (InputHostCb *callback)
```
**描述**

注册Input设备的热插拔回调函数。

Input服务通过此接口注册回调函数到hdi中，所有Input设备由此函数进行热插拔事件上报。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callback | 输入参数，回调函数的函数指针。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。


### RegisterReportCallback

```
int32_t(* InputReporter::RegisterReportCallback) (uint32_t devIndex, InputEventCb *callback)
```
**描述**

注册对应设备的回调函数。

Input服务通过此接口注册数据回调函数到hdi中，hdi通过此回调函数上报Input事件。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。  | 
| callback | 输入参数，回调函数的函数指针。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。


### UnregisterHotPlugCallback

```
int32_t(* InputReporter::UnregisterHotPlugCallback) (void)
```
**描述**

注销Input设备的热插拔回调函数。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| 无。 |  | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。


### UnregisterReportCallback

```
int32_t(* InputReporter::UnregisterReportCallback) (uint32_t devIndex)
```
**描述**

注销对应设备的回调函数。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。
