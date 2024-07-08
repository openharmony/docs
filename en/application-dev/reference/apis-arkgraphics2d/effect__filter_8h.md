# effect_filter.h


## Overview

The **effect_filter.h** file declares the APIs of an image effect filter.

**File to include**: &lt;native_effect/effect_filter.h&gt;

**Library**: libnative_effect.so

**System capability**: SystemCapability.Multimedia.Image.Core

**Since**: 12

**Related module**: [EffectKit](effect_kit.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [EffectErrorCode](effect_kit.md#effecterrorcode) [OH_Filter_CreateEffect](effect_kit.md#oh_filter_createeffect) (OH_PixelmapNative \*pixelmap, [OH_Filter](_o_h___filter.md) \*\*filter) | Creates an **OH_Filter** object.| 
| [EffectErrorCode](effect_kit.md#effecterrorcode) [OH_Filter_Release](effect_kit.md#oh_filter_release) ([OH_Filter](_o_h___filter.md) \*filter) | Releases an **OH_Filter** object.| 
| [EffectErrorCode](effect_kit.md#effecterrorcode) [OH_Filter_Blur](effect_kit.md#oh_filter_blur) ([OH_Filter](_o_h___filter.md) \*filter, float radius) | Creates the frosted glass effect and adds it to a filter.| 
| [EffectErrorCode](effect_kit.md#effecterrorcode) [OH_Filter_Brighten](effect_kit.md#oh_filter_brighten) ([OH_Filter](_o_h___filter.md) \*filter, float brightness) | Creates the brightening effect and adds it to a filter.| 
| [EffectErrorCode](effect_kit.md#effecterrorcode) [OH_Filter_GrayScale](effect_kit.md#oh_filter_grayscale) ([OH_Filter](_o_h___filter.md) \*filter) | Creates the grayscale effect and adds it to a filter.| 
| [EffectErrorCode](effect_kit.md#effecterrorcode) [OH_Filter_Invert](effect_kit.md#oh_filter_invert) ([OH_Filter](_o_h___filter.md) \*filter) | Creates the inverted color effect and adds it to a filter.| 
| [EffectErrorCode](effect_kit.md#effecterrorcode) [OH_Filter_SetColorMatrix](effect_kit.md#oh_filter_setcolormatrix) ([OH_Filter](_o_h___filter.md) \*filter, [OH_Filter_ColorMatrix](_o_h___filter___color_matrix.md) \*matrix) | Creates a custom effect through a matrix and adds it to a filter.| 
| [EffectErrorCode](effect_kit.md#effecterrorcode) [OH_Filter_GetEffectPixelMap](effect_kit.md#oh_filter_geteffectpixelmap) ([OH_Filter](_o_h___filter.md) \*filter, OH_PixelmapNative \*\*pixelmap) | Obtains the pixel map used to create a filter.| 
