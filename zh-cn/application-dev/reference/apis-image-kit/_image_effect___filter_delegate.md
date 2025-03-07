# ImageEffect_FilterDelegate


## 概述

自定义滤镜回调函数结构体。

**系统能力：** SystemCapability.Multimedia.ImageEffect.Core

**起始版本：** 12

**相关模块：**[ImageEffect](_image_effect.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_EffectFilterDelegate_SetValue](_image_effect.md#oh_effectfilterdelegate_setvalue) [setValue](#setvalue) | 参数设置函数指针。  | 
| [OH_EffectFilterDelegate_Render](_image_effect.md#oh_effectfilterdelegate_render) [render](#render) | 滤镜渲染函数指针。  | 
| [OH_EffectFilterDelegate_Save](_image_effect.md#oh_effectfilterdelegate_save) [save](#save) | 序列化效果器函数指针。  | 
| [OH_EffectFilterDelegate_Restore](_image_effect.md#oh_effectfilterdelegate_restore) [restore](#restore) | 反序列化效果器函数指针。  | 


## 结构体成员变量说明


### render

```
OH_EffectFilterDelegate_Render ImageEffect_FilterDelegate::render
```
**描述**
滤镜渲染函数指针。


### restore

```
OH_EffectFilterDelegate_Restore ImageEffect_FilterDelegate::restore
```
**描述**
反序列化效果器函数指针。


### save

```
OH_EffectFilterDelegate_Save ImageEffect_FilterDelegate::save
```
**描述**
序列化效果器函数指针。


### setValue

```
OH_EffectFilterDelegate_SetValue ImageEffect_FilterDelegate::setValue
```
**描述**
参数设置函数指针。
