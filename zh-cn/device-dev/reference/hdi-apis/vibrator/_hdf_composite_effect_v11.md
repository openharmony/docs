# HdfCompositeEffect


## 概述

定义复合振动效果参数。

参数包括复合效果的类型和顺序。

**起始版本：** 3.2

**相关模块：**[Vibrator](_vibrator_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [type](#type) | 复合效果的类型，请参见[HdfEffectType](_vibrator_v11.md#hdfeffecttype)。 | 
| union [CompositeEffect](union_composite_effect_v11.md)[] [compositeEffects](#compositeeffects) | 合成效果的序列，请参见[CompositeEffect](union_composite_effect_v11.md)。 | 


## 类成员变量说明


### compositeEffects

```
union CompositeEffect [] HdfCompositeEffect::compositeEffects
```

**描述**


合成效果的序列，请参见[CompositeEffect](union_composite_effect_v11.md)。


### type

```
int HdfCompositeEffect::type
```

**描述**


复合效果的类型，请参见[HdfEffectType](_vibrator_v11.md#hdfeffecttype)。
