# IThermalInterface


## 概述

设备温度管理、控制及订阅接口。

服务获取此对象后，可以调用相关的接口管理、控制和订阅设备温度。

**起始版本：** 3.1

**相关模块：**[Thermal](thermal_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [SetCpuFreq](#setcpufreq) ([in] int freq) | 设置CPU频率。  | 
| [SetGpuFreq](#setgpufreq) ([in] int freq) | 设置GPU频率。  | 
| [SetBatteryCurrent](#setbatterycurrent) ([in] int current) | 设置充电电流。  | 
| [GetThermalZoneInfo](#getthermalzoneinfo) ([out] struct [HdfThermalCallbackInfo](_hdf_thermal_callback_info_v10.md) event) | 获取设备发热的信息。  | 
| [Register](#register) ([in] [IThermalCallback](interface_i_thermal_callback_v10.md) callbackObj) | 注册设备发热状态的回调。  | 
| [Unregister](#unregister) () | 取消注册设备发热状态的回调。  | 


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

[HdfThermalCallbackInfo](_hdf_thermal_callback_info_v10.md)


### Register()

```
IThermalInterface::Register ([in] IThermalCallback callbackObj)
```
**描述**
注册设备发热状态的回调。

**起始版本：** 3.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 输入参数，服务注册的回调。 | 

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。

**参见：**

[IThermalCallback](interface_i_thermal_callback_v10.md)


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
取消注册设备发热状态的回调。

**起始版本：** 3.1

**返回：**

HDF_SUCCESS 表示操作成功。

HDF_FAILED 表示操作失败。
