# ICellbatchingCallback


## 概述

定义基站轨迹数据记录模块的回调函数。

用户在开启基站轨迹数据记录功能前，需要先注册该回调函数。当应用主动获取基站轨迹数据时，会通过回调函数进行上报。 详情可参考[ICellbatchingInterface](interface_i_cellbatching_interface.md)。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceCellbatching](_hdi_lpfence_cellbatching.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnCellbatchingChanged](#oncellbatchingchanged) ([in] struct [CellTrajectoryData](_cell_trajectory_data.md)[] data) | 定义基站轨迹数据上报的回调函数。 | 
| [OnCellbatchingReset](#oncellbatchingreset) () | 定义低功耗围栏服务复位事件通知的回调函数。 | 


## 成员函数说明


### OnCellbatchingChanged()

```
ICellbatchingCallback::OnCellbatchingChanged ([in] struct CellTrajectoryData[] data)
```

**描述**


定义基站轨迹数据上报的回调函数。

基站轨迹数据会通过该回调函数进行上报。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| data | 上报的基站轨迹数据。详见[CellTrajectoryData](_cell_trajectory_data.md)定义。 | 

**返回：**

如果回调函数上报数据成功，则返回0。

如果回调函数上报数据失败，则返回负值。


### OnCellbatchingReset()

```
ICellbatchingCallback::OnCellbatchingReset ()
```

**描述**


定义低功耗围栏服务复位事件通知的回调函数。

低功耗围栏服务发生复位时会通过该回调函数进行事件上报。

**起始版本：** 4.0

**返回：**

如果回调函数上报事件成功，则返回0。

如果回调函数上报事件失败，则返回负值。
