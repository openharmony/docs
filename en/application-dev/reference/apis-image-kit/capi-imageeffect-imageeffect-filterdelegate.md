# ImageEffect_FilterDelegate

## Overview

The struct describes the callback functions of a custom image effect filter.

**Since**: 12

**Related module**: [ImageEffect](capi-imageeffect.md)

**Header file**: [image_effect_filter.h](capi-image-effect-filter-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [OH_EffectFilterDelegate_SetValue](capi-image-effect-filter-h.md#oh_effectfilterdelegate_setvalue) setValue | Pointer to the parameter setting function.|
| [OH_EffectFilterDelegate_Render](capi-image-effect-filter-h.md#oh_effectfilterdelegate_render) render | Pointer to the filter rendering function.|
| [OH_EffectFilterDelegate_Save](capi-image-effect-filter-h.md#oh_effectfilterdelegate_save) save | Pointer to the filter serialization function.|
| [OH_EffectFilterDelegate_Restore](capi-image-effect-filter-h.md#oh_effectfilterdelegate_restore) restore | Pointer to the filter deserialization function.|
