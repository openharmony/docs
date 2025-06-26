# ImageEffect_FilterDelegate

## 概述

自定义滤镜回调函数结构体。

**起始版本：** 12

**相关模块：** [ImageEffect](capi-imageeffect.md)

**所在头文件：** [image_effect_filter.h](capi-image-effect-filter-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [OH_EffectFilterDelegate_SetValue](capi-image-effect-filter-h.md#oh_effectfilterdelegate_setvalue) setValue | 参数设置函数指针。 |
| [OH_EffectFilterDelegate_Render](capi-image-effect-filter-h.md#oh_effectfilterdelegate_render) render | 滤镜渲染函数指针。 |
| [OH_EffectFilterDelegate_Save](capi-image-effect-filter-h.md#oh_effectfilterdelegate_save) save | 序列化效果器函数指针。 |
| [OH_EffectFilterDelegate_Restore](capi-image-effect-filter-h.md#oh_effectfilterdelegate_restore) restore | 反序列化效果器函数指针。 |
