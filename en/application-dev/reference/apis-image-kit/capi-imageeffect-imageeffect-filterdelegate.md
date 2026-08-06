# ImageEffect_FilterDelegate

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=9329f19aa2995f079ff9cf109a20aad0033a91a3 translatedAt=2026-08-03T04:05:36.704Z pushedAt=2026-08-04T02:21:00.091Z -->

```c
typedef struct ImageEffect_FilterDelegate {...} ImageEffect_FilterDelegate
```

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