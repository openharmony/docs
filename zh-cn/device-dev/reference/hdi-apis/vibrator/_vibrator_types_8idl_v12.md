# VibratorTypes.idl


## 概述

定义马达数据结构，包括马达振动模式和马达参数。

模块包路径：ohos.hdi.vibrator.v1_2

引用：ohos.hdi.vibrator.v1_1.VibratorTypes

**起始版本：** 4.1

**相关模块：**[Vibrator](_vibrator_v12.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[CurvePoint](_curve_point_v12.md) | 表示振动点。 | 
| struct&nbsp;&nbsp;[HapticEvent](_haptic_event_v12.md) | 表示振动事件。 | 
| struct&nbsp;&nbsp;[HapticPaket](_haptic_paket_v12.md) | 高清振动数据包。 | 
| struct&nbsp;&nbsp;[HapticCapacity](_haptic_capacity_v12.md) | 振动能力数据包。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [EVENT_TYPE](_vibrator_v12.md#event_type) { CONTINUOUS = 0 , TRANSIENT = 1 } | 表示振动类型。 | 
| [HdfVibratorModeV1_2](_vibrator_v12.md#hdfvibratormodev1_2) { HDF_VIBRATOR_MODE_ONCE , HDF_VIBRATOR_MODE_PRESET , HDF_VIBRATOR_MODE_HDHAPTIC , HDF_VIBRATOR_MODE_BUTT } | 表示StopV1_2接口可传入参数枚举。 | 
