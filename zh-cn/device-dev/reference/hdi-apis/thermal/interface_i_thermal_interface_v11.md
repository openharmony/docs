# IThermalInterface


## 概述

备温度管理、控制及订阅接口。

**起始版本：** 3.1

**相关模块：**[Thermal](thermal_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [SetCpuFreq](#setcpufreq) ([in] int freq) | 设置CPU频率。  | 
| [SetGpuFreq](#setgpufreq) ([in] int freq) | 设置GPU频率。  | 
| [SetBatteryCurrent](#setbatterycurrent) ([in] int current) | 设置充电电流。  | 
| [GetThermalZoneInfo](#getthermalzoneinfo) ([out] struct [HdfThermalCallbackInfo](_hdf_thermal_callback_info_v11.md) event) | 获取设备发热的信息。  | 
| [IsolateCpu](#isolatecpu) ([in] int num) | 隔离内核CPU。  | 
| [Register](#register) ([in] [IThermalCallback](interface_i_thermal_callback_v11.md) callbackObj) | 注册设备热状态回调。  | 
| [Unregister](#unregister) () | 注册设备热状态回调。  | 
| [RegisterFanCallback](#registerfancallback) ([in] [IFanCallback](interface_i_fan_callback_v11.md) callbackObj) | 注册风扇故障检测的回调。  | 
| [UnregisterFanCallback](#unregisterfancallback) () | 取消注册风扇故障检测的回调。  | 


## 成员函数说明


### GetThermalZoneInfo()

```
IThermalInterface::GetThermalZoneInfo ([out] struct HdfThermalCallbackInfo event)
```
**描述**
获取设备发热的信息。

**起始版本：** 3.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 输出参数，设备发热信息，包括器件类型、器件温度。 | 

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。

**参见：**

[HdfThermalCallbackInfo](_hdf_thermal_callback_info_v11.md)


### IsolateCpu()

```
IThermalInterface::IsolateCpu ([in] int num)
```
**描述**
隔离内核CPU。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| num | 输入参数，CPU内核编号。 | 

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。


### Register()

```
IThermalInterface::Register ([in] IThermalCallback callbackObj)
```
**描述**
注册设备热状态回调。

**起始版本：** 3.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 输入参数，要注册的回调函数。 | 

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。

**参见：**

[IThermalCallback](interface_i_thermal_callback_v11.md)


### RegisterFanCallback()

```
IThermalInterface::RegisterFanCallback ([in] IFanCallback callbackObj)
```
**描述**
注册风扇故障检测的回调。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 输入参数，要注册的回调函数。 | 

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。

**参见：**

[IFanCallback](interface_i_fan_callback_v11.md)


### SetBatteryCurrent()

```
IThermalInterface::SetBatteryCurrent ([in] int current)
```
**描述**
设置充电电流。

**起始版本：** 3.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| current | 输入参数，充电电流，单位毫安。 | 

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。


### SetCpuFreq()

```
IThermalInterface::SetCpuFreq ([in] int freq)
```
**描述**
设置CPU频率。

**起始版本：** 3.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| freq | 输入参数，设置CPU频率的值。 | 

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。


### SetGpuFreq()

```
IThermalInterface::SetGpuFreq ([in] int freq)
```
**描述**
设置GPU频率。

**起始版本：** 3.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| freq | 输入参数，设置GPU频率的值。 | 

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。


### Unregister()

```
IThermalInterface::Unregister ()
```
**描述**
注册设备热状态回调。

**起始版本：** 3.1

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。


### UnregisterFanCallback()

```
IThermalInterface::UnregisterFanCallback ()
```
**描述**
取消注册风扇故障检测的回调。

**起始版本：** 4.0

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。
