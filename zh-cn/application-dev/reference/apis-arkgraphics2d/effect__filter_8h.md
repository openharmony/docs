# effect_filter.h


## 概述

声明滤镜效果的接口。

**引用文件：**&lt;native_effect/effect_filter.h&gt;

**库：** libnative_effect.so

**系统能力：** SystemCapability.Multimedia.Image.Core

**起始版本：** 12

**相关模块：**[EffectKit](effect_kit.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [EffectErrorCode](effect_kit.md#effecterrorcode) [OH_Filter_CreateEffect](effect_kit.md#oh_filter_createeffect) (OH_PixelmapNative \*pixelmap, [OH_Filter](_o_h___filter.md) \*\*filter) | 创建一个OH_Filter对象。 | 
| [EffectErrorCode](effect_kit.md#effecterrorcode) [OH_Filter_Release](effect_kit.md#oh_filter_release) ([OH_Filter](_o_h___filter.md) \*filter) | 释放OH_Filter对象。 | 
| [EffectErrorCode](effect_kit.md#effecterrorcode) [OH_Filter_Blur](effect_kit.md#oh_filter_blur) ([OH_Filter](_o_h___filter.md) \*filter, float radius) | 创建一个毛玻璃滤镜效果，然后添加到滤镜里面。 | 
| [EffectErrorCode](effect_kit.md#effecterrorcode) [OH_Filter_BlurWithTileMode](effect_kit.md#oh_filter_blurwithtilemode) ([OH_Filter](_o_h___filter.md) \*filter, float radius, [EffectTileMode](effect_kit.md#effecttilemode) tileMode) | 创建一个毛玻璃滤镜效果，然后添加到滤镜里面。 | 
| [EffectErrorCode](effect_kit.md#effecterrorcode) [OH_Filter_Brighten](effect_kit.md#oh_filter_brighten) ([OH_Filter](_o_h___filter.md) \*filter, float brightness) | 创建一个提亮效果并且添加到滤镜中。 | 
| [EffectErrorCode](effect_kit.md#effecterrorcode) [OH_Filter_GrayScale](effect_kit.md#oh_filter_grayscale) ([OH_Filter](_o_h___filter.md) \*filter) | 创建一个灰度效果并且添加到滤镜中。 | 
| [EffectErrorCode](effect_kit.md#effecterrorcode) [OH_Filter_Invert](effect_kit.md#oh_filter_invert) ([OH_Filter](_o_h___filter.md) \*filter) | 创建一个反色效果并且添加到滤镜中。 | 
| [EffectErrorCode](effect_kit.md#effecterrorcode) [OH_Filter_SetColorMatrix](effect_kit.md#oh_filter_setcolormatrix) ([OH_Filter](_o_h___filter.md) \*filter, [OH_Filter_ColorMatrix](_o_h___filter___color_matrix.md) \*matrix) | 通过矩阵创建一个自定义的效果并且添加到滤镜中。 | 
| [EffectErrorCode](effect_kit.md#effecterrorcode) [OH_Filter_GetEffectPixelMap](effect_kit.md#oh_filter_geteffectpixelmap) ([OH_Filter](_o_h___filter.md) \*filter, OH_PixelmapNative \*\*pixelmap) | 获取滤镜生成的位图。 | 
