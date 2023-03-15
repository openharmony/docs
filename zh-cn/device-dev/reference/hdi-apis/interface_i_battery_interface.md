# IBatteryInterface


## **概述**

获取、订阅电池信息的接口。

服务获取此对象后，可以调用相关的接口获取、订阅电池信息。

**Since:**

3.1

**相关模块:**

[Battery](battery.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [Register](#register)&nbsp;([in]&nbsp;[IBatteryCallback](interface_i_battery_callback.md)&nbsp;event) | 注册电池信息的回调。 | 
| [UnRegister](#unregister)&nbsp;() | 取消注册电池信息的回调。 | 
| [ChangePath](#changepath)&nbsp;([in]&nbsp;String&nbsp;path) | 设置电池信息节点的路径。 | 
| [GetCapacity](#getcapacity)&nbsp;([out]&nbsp;int&nbsp;capacity) | 获取电池的电量百分比。 | 
| [GetVoltage](#getvoltage)&nbsp;([out]&nbsp;int&nbsp;voltage) | 获取电池的电压，单位微伏。 | 
| [GetTemperature](#gettemperature)&nbsp;([out]&nbsp;int&nbsp;temperature) | 获取电池的充电温度，单位0.1摄氏度。 | 
| [GetHealthState](#gethealthstate)&nbsp;([out]&nbsp;enum&nbsp;[BatteryHealthState](battery.md#batteryhealthstate)&nbsp;healthState) | 获取电池的健康状态。 | 
| [GetPluggedType](#getpluggedtype)&nbsp;([out]&nbsp;enum&nbsp;[BatteryPluggedType](battery.md#batterypluggedtype)&nbsp;pluggedType) | 获取充电设备类型。 | 
| [GetChargeState](#getchargestate)&nbsp;([out]&nbsp;enum&nbsp;[BatteryChargeState](battery.md#batterychargestate)&nbsp;chargeState) | 获取充电状态。 | 
| [GetPresent](#getpresent)&nbsp;([out]&nbsp;boolean&nbsp;present) | 获取是否支持电池或者电池是否在位。 | 
| [GetTechnology](#gettechnology)&nbsp;([out]&nbsp;String&nbsp;technology) | 获取电池的技术型号。 | 
| [GetTotalEnergy](#gettotalenergy)&nbsp;([out]&nbsp;int&nbsp;totalEnergy) | 获取电池的总容量。 | 
| [GetCurrentAverage](#getcurrentaverage)&nbsp;([out]&nbsp;int&nbsp;curAverage) | 获取电池的平均电流。 | 
| [GetCurrentNow](#getcurrentnow)&nbsp;([out]&nbsp;int&nbsp;curNow) | 获取电池的电流。 | 
| [GetRemainEnergy](#getremainenergy)&nbsp;([out]&nbsp;int&nbsp;remainEnergy) | 获取电池的剩余容量。 | 
| [GetBatteryInfo](#getbatteryinfo)&nbsp;([out]&nbsp;struct&nbsp;[BatteryInfo](_battery_info.md)&nbsp;info) | 获取电池的全部信息。 | 


## **成员函数说明**


### ChangePath()

  
```
IBatteryInterface::ChangePath ([in] String path)
```

**描述：**

设置电池信息节点的路径。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| path | 输入参数，电池信息节点的路径。 | 

**返回:**

HDF_SUCCESS 表示路径设置成功。


### GetBatteryInfo()

  
```
IBatteryInterface::GetBatteryInfo ([out] struct BatteryInfo info)
```

**描述：**

获取电池的全部信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| info | 电池的全部信息。 | 

**返回:**

HDF_SUCCESS 表示获取成功。

**参见:**

[BatteryInfo](_battery_info.md)


### GetCapacity()

  
```
IBatteryInterface::GetCapacity ([out] int capacity)
```

**描述：**

获取电池的电量百分比。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| capacity | 表示电量的百分比值。 | 

**返回:**

HDF_SUCCESS 表示获取成功。


### GetChargeState()

  
```
IBatteryInterface::GetChargeState ([out] enum BatteryChargeState chargeState)
```

**描述：**

获取充电状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| chargeState | 表示充电状态。 | 

**返回:**

HDF_SUCCESS 表示获取成功。

**参见:**

[BatteryChargeState](battery.md#batterychargestate)


### GetCurrentAverage()

  
```
IBatteryInterface::GetCurrentAverage ([out] int curAverage)
```

**描述：**

获取电池的平均电流。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| totalEnergy | 表示电池的平均电流，单位毫安。 | 

**返回:**

HDF_SUCCESS 表示获取成功。


### GetCurrentNow()

  
```
IBatteryInterface::GetCurrentNow ([out] int curNow)
```

**描述：**

获取电池的电流。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| curNow | 表示电池的实时电流，单位毫安。 | 

**返回:**

HDF_SUCCESS 表示获取成功。


### GetHealthState()

  
```
IBatteryInterface::GetHealthState ([out] enum BatteryHealthState healthState)
```

**描述：**

获取电池的健康状态。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| healthState | 表示电池健康状态。 | 

**返回:**

HDF_SUCCESS 表示获取成功。

**参见:**

[BatteryHealthState](battery.md#batteryhealthstate)


### GetPluggedType()

  
```
IBatteryInterface::GetPluggedType ([out] enum BatteryPluggedType pluggedType)
```

**描述：**

获取充电设备类型。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| pluggedType | 表示充电设备类型。 | 

**返回:**

HDF_SUCCESS 表示获取成功。

**参见:**

[BatteryPluggedType](battery.md#batterypluggedtype)


### GetPresent()

  
```
IBatteryInterface::GetPresent ([out] boolean present)
```

**描述：**

获取是否支持电池或者电池是否在位。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| present | 表示是否支持电池或者电池是否在位。true表示支持或在位，false表示不支持或不在位。 | 

**返回:**

HDF_SUCCESS 表示获取成功。


### GetRemainEnergy()

  
```
IBatteryInterface::GetRemainEnergy ([out] int remainEnergy)
```

**描述：**

获取电池的剩余容量。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| remainEnergy | 表示电池的剩余容量，单位毫安时。 | 

**返回:**

HDF_SUCCESS 表示获取成功。


### GetTechnology()

  
```
IBatteryInterface::GetTechnology ([out] String technology)
```

**描述：**

获取电池的技术型号。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| technology | 当前电池技术型号。 | 

**返回:**

HDF_SUCCESS 表示获取成功。


### GetTemperature()

  
```
IBatteryInterface::GetTemperature ([out] int temperature)
```

**描述：**

获取电池的充电温度，单位0.1摄氏度。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| temperature | 表示电池温度。 | 

**返回:**

HDF_SUCCESS 表示获取成功。


### GetTotalEnergy()

  
```
IBatteryInterface::GetTotalEnergy ([out] int totalEnergy)
```

**描述：**

获取电池的总容量。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| totalEnergy | 表示电池的总容量，单位毫安时。 | 

**返回:**

HDF_SUCCESS 表示获取成功。


### GetVoltage()

  
```
IBatteryInterface::GetVoltage ([out] int voltage)
```

**描述：**

获取电池的电压，单位微伏。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| voltage | 表示电池的电压。 | 

**返回:**

HDF_SUCCESS 表示获取成功。


### Register()

  
```
IBatteryInterface::Register ([in] IBatteryCallback event)
```

**描述：**

注册电池信息的回调。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| event | 服务注册的回调。 | 

**返回:**

HDF_SUCCESS 表示注册成功。


### UnRegister()

  
```
IBatteryInterface::UnRegister ()
```

**描述：**

取消注册电池信息的回调。

**返回:**

HDF_SUCCESS 表示取消注册成功。
