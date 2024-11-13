# HdiInput


## 概述

Input模块向上层服务提供了统一接口。

上层服务开发人员可根据Input模块提供的向上统一接口获取如下能力：Input设备的打开和关闭、Input事件获取、设备信息查询、回调函数注册、特性状态控制等。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IInputCallback.idl](_i_input_callback_8idl.md) | Input模块为Input服务提供的数据上报和热插拔事件上报的回调。  | 
| [IInputInterfaces.idl](_i_input_interfaces_8idl.md) | Input设备的打开和关闭、Input事件获取、设备信息查询、回调函数注册、特性状态控制等接口。  | 
| [InputTypes.idl](_input_types_8idl.md) | Input设备相关的数据类型定义。  | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IInputCallback](interface_i_input_callback_v10.md) | 定义Input模块的回调函数。  | 
| interface&nbsp;&nbsp;[IInputInterfaces](interface_i_input_interfaces_v10.md) | Input模块向上层服务提供了统一接口。  | 
| struct&nbsp;&nbsp;[DevDesc](_dev_desc_v10.md) | Input设备描述信息。  | 
| struct&nbsp;&nbsp;[DevIdentify](_dev_identify_v10.md) | Input设备的识别信息。  | 
| struct&nbsp;&nbsp;[DimensionInfo](_dimension_info_v10.md) | Input设备的维度信息。  | 
| struct&nbsp;&nbsp;[DevAttr](_dev_attr_v10.md) | Input设备属性。  | 
| struct&nbsp;&nbsp;[DevAbility](_dev_ability_v10.md) | Input设备的能力属性，存储支持事件的位图。  | 
| struct&nbsp;&nbsp;[DeviceInfo](_device_info_v10.md) | Input设备基础设备信息。  | 
| struct&nbsp;&nbsp;[ExtraCmd](_extra_cmd_v10.md) | 扩展指令的数据结构。  | 
| struct&nbsp;&nbsp;[HotPlugEvent](_hot_plug_event_v10.md) | 热插拔事件数据包结构。  | 
| struct&nbsp;&nbsp;[EventPackage](_event_package_v10.md) | Input事件数据包结构。  | 
