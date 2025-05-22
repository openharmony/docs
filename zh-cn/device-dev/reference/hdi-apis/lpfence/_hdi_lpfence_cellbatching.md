# HdiLpfenceCellbatching


## 概述

为低功耗围栏服务提供基站轨迹数据记录的API。

本模块能够控制设备对接收的基站数据进行缓存和上报。 应用场景：根据设备接收的基站轨迹数据，判断用户的大致活动区域，进而进行一些服务提醒。

**起始版本：** 4.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [CellbatchingTypes.idl](_cellbatching_types_8idl.md) | 定义基站轨迹数据记录模块使用的数据类型。 | 
| [ICellbatchingCallback.idl](_i_cellbatching_callback_8idl.md) | 定义基站轨迹数据记录模块回调接口。 | 
| [ICellbatchingInterface.idl](_i_cellbatching_interface_8idl.md) | 声明基站轨迹数据记录模块提供的API，用于使能和去使能基站轨迹数据记录功能，主动获取基站轨迹数据。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[CellbatchingRequest](_cellbatching_request.md) | 定义设置基站轨迹数据上报功能的数据结构。 | 
| struct&nbsp;&nbsp;[CellTrajectoryData](_cell_trajectory_data.md) | 定义上报的基站轨迹数据的数据结构。 | 
| interface&nbsp;&nbsp;[ICellbatchingCallback](interface_i_cellbatching_callback.md) | 导入基站轨迹数据记录模块的数据类型。 | 
| interface&nbsp;&nbsp;[ICellbatchingInterface](interface_i_cellbatching_interface.md) | 定义对基站轨迹数据记录模块进行基本操作的接口。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [CellbatchingSwitch](#cellbatchingswitch) { SWITCH_OFF = 0 , SWITCH_ON = 1 } | 枚举对基站轨迹数据记录的开关操作。 | 


## 枚举类型说明


### CellbatchingSwitch

```
enum CellbatchingSwitch
```

**描述**


枚举对基站轨迹数据记录的开关操作。

**起始版本：** 4.0

| 枚举值 | 描述 | 
| -------- | -------- |
| SWITCH_OFF | 关闭基站轨迹数据记录功能。 | 
| SWITCH_ON | 打开基站轨迹数据记录功能。 | 
