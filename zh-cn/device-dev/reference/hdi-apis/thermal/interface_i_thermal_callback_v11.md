# IThermalCallback


## 概述

订阅设备发热状态的回调。

服务创建此回调对象后，可以调用[IThermalInterface](interface_i_thermal_interface_v11.md)的接口注册回调，从而订阅设备发热状态的变化。

**起始版本：** 3.1

**相关模块：**[Thermal](thermal_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnThermalDataEvent](#onthermaldataevent) ([in] struct [HdfThermalCallbackInfo](_hdf_thermal_callback_info_v11.md) event) | 热状态变化的回调。  | 


## 成员函数说明


### OnThermalDataEvent()

```
IThermalCallback::OnThermalDataEvent ([in] struct HdfThermalCallbackInfo event)
```
**描述**
热状态变化的回调。

**起始版本：** 3.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 输入参数，设备发热信息，包括器件类型、器件温度。  | 

**参见：**

[HdfThermalCallbackInfo](_hdf_thermal_callback_info_v11.md)
