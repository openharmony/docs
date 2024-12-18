# effect_types.h


## 概述

声明滤镜效果的数据类型。

**引用文件：**&lt;native_effect/effect_types.h&gt;

**库：** libnative_effect.so

**系统能力：** SystemCapability.Multimedia.Image.Core

**起始版本：** 12

**相关模块：**[EffectKit](effect_kit.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_Filter](_o_h___filter.md) | 滤镜结构体，用来生成滤镜位图。 | 
| struct  [OH_Filter_ColorMatrix](_o_h___filter___color_matrix.md) | 定义一个用来创建滤镜效果的矩阵。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_Filter](_o_h___filter.md)  [pixelMap](effect_kit.md#pixelmap) | 滤镜结构体，用来生成滤镜位图。 | 
| typedef enum [EffectErrorCode](effect_kit.md#effecterrorcode)  [EffectErrorCode](effect_kit.md#effecterrorcode) | 定义滤镜效果的状态码。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [EffectErrorCode](effect_kit.md#effecterrorcode) { EFFECT_SUCCESS = 0, EFFECT_BAD_PARAMETER = 401, EFFECT_UNSUPPORTED_OPERATION = 7600201, EFFECT_UNKNOWN_ERROR = 7600901 } | 定义滤镜效果的状态码。 | 
| [EffectTileMode](effect_kit.md#effecttilemode) { CLAMP = 0, REPEAT, MIRROR, DECAL } | 定义着色器效果平铺模式的枚举。 | 