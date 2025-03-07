# IFanCallback


## 概述

代表风扇状态变化的回调。

创建回调对象后，热服务可调用 [IThermalInterface](interface_i_thermal_interface_v11.md) 借口注册回调，以便订阅风扇状态变化。

**起始版本：** 4.0

**相关模块：**[Thermal](thermal_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnFanDataEvent](#onfandataevent) ([in] struct [HdfThermalCallbackInfo](_hdf_thermal_callback_info_v11.md) event) | 回调风扇状态变化。  | 


## 成员函数说明


### OnFanDataEvent()

```
IFanCallback::OnFanDataEvent ([in] struct HdfThermalCallbackInfo event)
```
**描述**
回调风扇状态变化。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 输入参数，设备的风扇信息，包括设备温度和风扇速度。  | 

**参见：**

[HdfThermalCallbackInfo](_hdf_thermal_callback_info_v11.md)
