# InputManager


## 概述

提供Input设备管理相关的接口。

此类接口包含Input设备的扫描、打开和关闭、特定设备信息查询，以及所有设备列表信息获取等接口。

**起始版本：** 1.0

**相关模块：**[Input](_input.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int32_t(\* [ScanInputDevice](#scaninputdevice) )([InputDevDesc](_input_dev_desc.md) \*staArr, uint32_t arrLen) | Input服务用于扫描所有在线设备。  | 
| int32_t(\* [OpenInputDevice](#openinputdevice) )(uint32_t devIndex) | Input服务打开对应设备的设备文件。  | 
| int32_t(\* [CloseInputDevice](#closeinputdevice) )(uint32_t devIndex) | Input服务关闭对应设备的设备文件。  | 
| int32_t(\* [GetInputDevice](#getinputdevice) )(uint32_t devIndex, [InputDeviceInfo](_input_device_info.md) \*\*devInfo) | Input服务获取对应ID的设备信息。  | 
| int32_t(\* [GetInputDeviceList](#getinputdevicelist) )(uint32_t \*devNum, [InputDeviceInfo](_input_device_info.md) \*\*devList, uint32_t size) | Input服务获取所有Input设备列表的设备信息。  | 


## 类成员变量说明


### CloseInputDevice

```
int32_t(* InputManager::CloseInputDevice) (uint32_t devIndex)
```
**描述**

Input服务关闭对应设备的设备文件。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。


### GetInputDevice

```
int32_t(* InputManager::GetInputDevice) (uint32_t devIndex, InputDeviceInfo **devInfo)
```
**描述**

Input服务获取对应ID的设备信息。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。  | 
| devInfo | 输出参数，即devIndex对应的设备的设备信息，具体参考[InputDeviceInfo](_input_device_info.md)。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。


### GetInputDeviceList

```
int32_t(* InputManager::GetInputDeviceList) (uint32_t *devNum, InputDeviceInfo **devList, uint32_t size)
```
**描述**

Input服务获取所有Input设备列表的设备信息。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devNum | 输出参数，当前已经注册过的所有Input设备的总数。  | 
| devList | 输出参数，Input设备列表所对应的设备信息，具体参考[InputDeviceInfo](_input_device_info.md)。  | 
| size | 输入参数，即指定deviceList数组对应的元素个数。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。


### OpenInputDevice

```
int32_t(* InputManager::OpenInputDevice) (uint32_t devIndex)
```
**描述**

Input服务打开对应设备的设备文件。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。


### ScanInputDevice

```
int32_t(* InputManager::ScanInputDevice) (InputDevDesc *staArr, uint32_t arrLen)
```
**描述**

Input服务用于扫描所有在线设备。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| staArr | 输出参数，存放Input设备扫描信息的数组，信息包含设备索引以及设备类型。  | 
| arrLen | 输入参数，staArr数组的长度信息。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。
