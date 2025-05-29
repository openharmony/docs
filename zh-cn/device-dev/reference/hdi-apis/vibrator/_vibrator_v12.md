# Vibrator (V1_2)


## 概述

马达驱动对马达服务提供通用的接口能力。

模块提供马达服务对马达驱动访问的统一接口，服务获取驱动对象或者代理后，控制马达的单次振动、周期性振动、高清振动、停止振动、设置马达振幅与频率。

**起始版本：** 4.1


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IVibratorInterface.idl](_i_vibrator_interface_8idl_v12.md) | 定义马达的通用API，可用于控制马达执行单次、周期性振动或高清振动、设置马达振幅与频率。 | 
| [VibratorTypes.idl](_vibrator_types_8idl_v12.md) | 定义马达数据结构，包括马达振动模式和马达参数。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IVibratorInterface](interface_i_vibrator_interface_v12.md) | Vibrator模块向上层服务提供统一的接口。 | 
| struct&nbsp;&nbsp;[CurvePoint](_curve_point_v12.md) | 表示振动点。 | 
| struct&nbsp;&nbsp;[HapticEvent](_haptic_event_v12.md) | 表示振动事件。 | 
| struct&nbsp;&nbsp;[HapticPaket](_haptic_paket_v12.md) | 高清振动数据包。 | 
| struct&nbsp;&nbsp;[HapticCapacity](_haptic_capacity_v12.md) | 振动能力数据包。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [EVENT_TYPE](#event_type) { CONTINUOUS = 0 , TRANSIENT = 1 } | 表示振动类型。 | 
| [HdfVibratorModeV1_2](#hdfvibratormodev1_2) { HDF_VIBRATOR_MODE_ONCE , HDF_VIBRATOR_MODE_PRESET , HDF_VIBRATOR_MODE_HDHAPTIC , HDF_VIBRATOR_MODE_BUTT } | 表示StopV1_2接口可传入参数枚举。 | 


## 枚举类型说明


### EVENT_TYPE

```
enum EVENT_TYPE
```

**描述**


表示振动类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| CONTINUOUS | 表示振动是连续的。 | 
| TRANSIENT | 表示振动是瞬时的。 | 


### HdfVibratorModeV1_2

```
enum HdfVibratorModeV1_2
```

**描述**


表示StopV1_2接口可传入参数枚举。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| HDF_VIBRATOR_MODE_ONCE | 表示给定持续时间内的单次振动。 | 
| HDF_VIBRATOR_MODE_PRESET | 表示具有预置效果的周期性振动。 | 
| HDF_VIBRATOR_MODE_HDHAPTIC | 表示高清振动。 | 
| HDF_VIBRATOR_MODE_BUTT | 表示效果模式无效。 | 
