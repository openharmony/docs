# ImageEffect_FilterDelegate


## Overview

The **ImageEffect_FilterDelegate** struct describes the callback functions of a custom image effect filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Related module**: [ImageEffect](_image_effect.md)

**Header file**: [image_effect_filter.h](image__effect__filter_8h.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [OH_EffectFilterDelegate_SetValue](_image_effect.md#oh_effectfilterdelegate_setvalue) [setValue](#setvalue) | Pointer to the parameter setting function. |
| [OH_EffectFilterDelegate_Render](_image_effect.md#oh_effectfilterdelegate_render) [render](#render) | Pointer to the filter rendering function. |
| [OH_EffectFilterDelegate_Save](_image_effect.md#oh_effectfilterdelegate_save) [save](#save) | Pointer to the filter serialization function. |
| [OH_EffectFilterDelegate_Restore](_image_effect.md#oh_effectfilterdelegate_restore) [restore](#restore) | Pointer to the filter deserialization function. |


## Member Variable Description


### render

```
OH_EffectFilterDelegate_Render ImageEffect_FilterDelegate::render
```
**Description**

Pointer to the filter rendering function.


### restore

```
OH_EffectFilterDelegate_Restore ImageEffect_FilterDelegate::restore
```
**Description**

Pointer to the filter deserialization function.


### save

```
OH_EffectFilterDelegate_Save ImageEffect_FilterDelegate::save
```
**Description**

Pointer to the filter serialization function.


### setValue

```
OH_EffectFilterDelegate_SetValue ImageEffect_FilterDelegate::setValue
```
**Description**

Pointer to the parameter setting function.
