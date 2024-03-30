# VibratorTypes.idl


## 概述

定义马达数据结构，包括马达振动模式和马达参数。

模块包路径：ohos.hdi.vibrator.v1_1

**起始版本：** 3.2

**相关模块：**[Vibrator](_vibrator_v11.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[HdfVibratorInfo](_hdf_vibrator_info_v11.md) | 定义马达参数。 | 
| struct&nbsp;&nbsp;[TimeEffect](_time_effect_v11.md) | 定义时间效果参数。 | 
| struct&nbsp;&nbsp;[PrimitiveEffect](_primitive_effect_v11.md) | 定义基本效果参数。 | 
| union&nbsp;&nbsp;[CompositeEffect](union_composite_effect_v11.md) | 定义复合效果定义两种效果。 | 
| struct&nbsp;&nbsp;[HdfCompositeEffect](_hdf_composite_effect_v11.md) | 定义复合振动效果参数。 | 
| struct&nbsp;&nbsp;[HdfEffectInfo](_hdf_effect_info_v11.md) | 定义振动效果信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [HdfVibratorMode](_vibrator_v11.md#hdfvibratormode) { HDF_VIBRATOR_MODE_ONCE , HDF_VIBRATOR_MODE_PRESET , HDF_VIBRATOR_MODE_BUTT } | 枚举马达的振动模式。 | 
| [HdfEffectType](_vibrator_v11.md#hdfeffecttype) { HDF_EFFECT_TYPE_TIME , HDF_EFFECT_TYPE_PRIMITIVE , HDF_EFFECT_TYPE_BUTT } | 枚举复合效果的效果类型。 | 
