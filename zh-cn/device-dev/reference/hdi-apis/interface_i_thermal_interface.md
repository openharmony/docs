# IThermalInterface


## **概述**

设备温度管理、控制及订阅接口。

服务获取此对象后，可以调用相关的接口管理、控制和订阅设备温度。

**Since：**

3.1

**相关模块:**

[Thermal](thermal.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [SetCpuFreq](#setcpufreq)&nbsp;([in]&nbsp;int&nbsp;freq) | 设置CPU频率。 | 
| [SetGpuFreq](#setgpufreq)&nbsp;([in]&nbsp;int&nbsp;freq) | 设置GPU频率。 | 
| [SetBatteryCurrent](#setbatterycurrent)&nbsp;([in]&nbsp;int&nbsp;current) | 设置充电电流。 | 
| [GetThermalZoneInfo](#getthermalzoneinfo)&nbsp;([out]&nbsp;struct&nbsp;[HdfThermalCallbackInfo](_hdf_thermal_callback_info.md)&nbsp;event) | 获取设备发热的信息。 | 
| [Register](#register)&nbsp;([in]&nbsp;[IThermalCallback](interface_i_thermal_callback.md)&nbsp;callbackObj) | 注册设备发热状态的回调。 | 
| [Unregister](#unregister)&nbsp;() | 取消注册设备发热状态的回调。 | 


## **成员函数说明**


### GetThermalZoneInfo()

  
```
IThermalInterface::GetThermalZoneInfo ([out] struct HdfThermalCallbackInfo event)
```

**描述：**

获取设备发热的信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| event | 输出参数，设备发热信息，包括器件类型、器件温度。 | 

**返回:**

HDF_SUCCESS 表示获取成功。

**参见:**

[HdfThermalCallbackInfo](_hdf_thermal_callback_info.md)


### Register()

  
```
IThermalInterface::Register ([in] IThermalCallback callbackObj)
```

**描述：**

注册设备发热状态的回调。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 输入参数，服务注册的回调。 | 

**返回:**

HDF_SUCCESS 表示注册成功。

**参见:**

[IThermalCallback](interface_i_thermal_callback.md)


### SetBatteryCurrent()

  
```
IThermalInterface::SetBatteryCurrent ([in] int current)
```

**描述：**

设置充电电流。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| current | 输入参数，充电电流，单位毫安。 | 

**返回:**

HDF_SUCCESS 表示设置成功


### SetCpuFreq()

  
```
IThermalInterface::SetCpuFreq ([in] int freq)
```

**描述：**

设置CPU频率。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| freq | 输入参数，设置CPU频率的值。 | 

**返回:**

HDF_SUCCESS 表示设置成功。


### SetGpuFreq()

  
```
IThermalInterface::SetGpuFreq ([in] int freq)
```

**描述：**

设置GPU频率。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| freq | 输入参数，设置GPU频率的值。 | 

**返回:**

HDF_SUCCESS 表示设置成功。


### Unregister()

  
```
IThermalInterface::Unregister ()
```

**描述：**

取消注册设备发热状态的回调。

**返回:**

HDF_SUCCESS 表示取消注册成功。
