# Thermal (V1_1)


## 概述

提供设备温度管理、控制及订阅接口。

热模块为热服务提供的设备温度管理、控制及订阅接口。 服务获取此模块的对象或代理后，可以调用相关的接口管理、控制和订阅设备温度。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IFanCallback.idl](_i_fan_callback_8idl_v11.md) | 提供风扇故障检测回调。 | 
| [IThermalCallback.idl](_i_thermal_callback_8idl_v11.md) | 设备发热状态的回调。 | 
| [IThermalInterface.idl](_i_thermal_interface_8idl_v11.md) | 设备温度管理、控制及订阅接口。 | 
| [ThermalTypes.idl](_thermal_types_8idl_v11.md) | 设备发热状态相关的数据类型。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IFanCallback](interface_i_fan_callback_v11.md) | 代表风扇状态变化的回调。 | 
| interface&nbsp;&nbsp;[IThermalCallback](interface_i_thermal_callback_v11.md) | 订阅设备发热状态的回调。 | 
| interface&nbsp;&nbsp;[IThermalInterface](interface_i_thermal_interface_v11.md) | 备温度管理、控制及订阅接口。 | 
| struct&nbsp;&nbsp;[ThermalZoneInfo](_thermal_zone_info_v11.md) | 设备发热的信息。 | 
| struct&nbsp;&nbsp;[HdfThermalCallbackInfo](_hdf_thermal_callback_info_v11.md) | 设备发热的信息列表。 | 
