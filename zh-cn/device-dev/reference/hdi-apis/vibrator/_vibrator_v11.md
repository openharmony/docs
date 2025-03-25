# Vibrator (V1_1)


## 概述

马达驱动对马达服务提供通用的接口能力。

模块提供马达服务对马达驱动访问的统一接口，服务获取驱动对象或者代理后，控制马达的单次振动、周期性振动、停止振动、设置马达振幅与频率。

**起始版本：** 3.2


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IVibratorInterface.idl](_i_vibrator_interface_8idl_v11.md) | 定义马达的通用API，可用于控制马达执行单次或周期性振动、设置马达振幅与频率。 | 
| [VibratorTypes.idl](_vibrator_types_8idl_v11.md) | 定义马达数据结构，包括马达振动模式和马达参数。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IVibratorInterface](interface_i_vibrator_interface_v11.md) | Vibrator模块向上层服务提供统一的接口。 | 
| struct&nbsp;&nbsp;[HdfVibratorInfo](_hdf_vibrator_info_v11.md) | 定义马达参数。 | 
| struct&nbsp;&nbsp;[TimeEffect](_time_effect_v11.md) | 定义时间效果参数。 | 
| struct&nbsp;&nbsp;[PrimitiveEffect](_primitive_effect_v11.md) | 定义基本效果参数。 | 
| union&nbsp;&nbsp;[CompositeEffect](union_composite_effect_v11.md) | 定义复合效果定义两种效果。 | 
| struct&nbsp;&nbsp;[HdfCompositeEffect](_hdf_composite_effect_v11.md) | 定义复合振动效果参数。 | 
| struct&nbsp;&nbsp;[HdfEffectInfo](_hdf_effect_info_v11.md) | 定义振动效果信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [HdfVibratorMode](#hdfvibratormode) { HDF_VIBRATOR_MODE_ONCE , HDF_VIBRATOR_MODE_PRESET , HDF_VIBRATOR_MODE_BUTT } | 枚举马达的振动模式。 | 
| [HdfEffectType](#hdfeffecttype) { HDF_EFFECT_TYPE_TIME , HDF_EFFECT_TYPE_PRIMITIVE , HDF_EFFECT_TYPE_BUTT } | 枚举复合效果的效果类型。 | 


## 枚举类型说明


### HdfEffectType

```
enum HdfEffectType
```

**描述**


枚举复合效果的效果类型。

**起始版本：** 3.2

| 枚举值 | 描述 | 
| -------- | -------- |
| HDF_EFFECT_TYPE_TIME | 表示给定时间序列的时间效果类型。 | 
| HDF_EFFECT_TYPE_PRIMITIVE | 表示给定基本振动序列的基本振动效果类型。 | 
| HDF_EFFECT_TYPE_BUTT | 表示效果类型无效。 | 


### HdfVibratorMode

```
enum HdfVibratorMode
```

**描述**


枚举马达的振动模式。

**起始版本：** 2.2

| 枚举值 | 描述 | 
| -------- | -------- |
| HDF_VIBRATOR_MODE_ONCE | 表示给定持续时间内的单次振动。 | 
| HDF_VIBRATOR_MODE_PRESET | 表示具有预置效果的周期性振动。 | 
| HDF_VIBRATOR_MODE_BUTT | 表示效果模式无效。 | 
