# HdiLpfenceCellbatching


## 概述

为低功耗围栏服务提供基站轨迹数据记录的API。

本模块能够控制设备对接收的基站数据进行缓存和上报。

应用场景：根据设备接收的基站轨迹数据，判断用户的大致活动区域，进而进行一些服务提醒。

**Since:**

4.0

**Version:**

1.0


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
| [CellbatchingRequest](_cellbatching_request.md) | struct<br/>定义设置基站轨迹数据上报功能的数据结构。 | 
| [CellTrajectoryData](_cell_trajectory_data.md) | struct<br/>定义上报的基站轨迹数据的数据结构。 | 
| [ICellbatchingCallback](interface_i_cellbatching_callback.md) | interface<br/>导入基站轨迹数据记录模块的数据类型。 | 
| [ICellbatchingInterface](interface_i_cellbatching_interface.md) | interface<br/>导入基站轨迹数据记录模块的数据类型。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [CellbatchingSwitch](#cellbatchingswitch)&nbsp;{&nbsp;SWITCH_OFF&nbsp;=&nbsp;0&nbsp;,&nbsp;SWITCH_ON&nbsp;=&nbsp;1&nbsp;} | 枚举对基站轨迹数据记录的开关操作。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.location.lpfence.cellbatching.v1_0 | 基站轨迹数据记录模块接口的包路径。 | 


## 枚举类型说明


### CellbatchingSwitch

  
```
enum CellbatchingSwitch
```

**描述:**

枚举对基站轨迹数据记录的开关操作。

  | 枚举值 | 描述 | 
| -------- | -------- |
| SWITCH_OFF | 关闭基站轨迹数据记录功能。 | 
| SWITCH_ON | 打开基站轨迹数据记录功能。 | 
