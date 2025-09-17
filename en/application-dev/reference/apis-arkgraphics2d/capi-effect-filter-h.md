# effect_filter.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Multimedia-->
<!--Owner: @hanamaru-->
<!--Designer: @gaoweihua-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @ge-yafang-->

## Overview

The **effect_filter.h** file declares the APIs of an image effect filter.

**File to import**: <native_effect/effect_filter.h>

**Library**: libnative_effect.so

**System capability**: SystemCapability.Multimedia.Image.Core

**Since**: 12

**Related module**: [effectKit](capi-effectkit.md)

## Total

### Functions

| Name| Description|
| -- | -- |
| [EffectErrorCode OH_Filter_CreateEffect(OH_PixelmapNative* pixelmap, OH_Filter** filter)](#oh_filter_createeffect) | Creates an **OH_Filter** object.|
| [EffectErrorCode OH_Filter_Release(OH_Filter* filter)](#oh_filter_release) | Releases an **OH_Filter** object.|
| [EffectErrorCode OH_Filter_Blur(OH_Filter* filter, float radius)](#oh_filter_blur) | Creates the frosted glass effect and adds it to a filter.|
| [EffectErrorCode OH_Filter_BlurWithTileMode(OH_Filter* filter, float radius, EffectTileMode tileMode)](#oh_filter_blurwithtilemode) | Creates a frosted glass filter effect and adds it to the filter. The tiling mode of the shader effect can be selected.|
| [EffectErrorCode OH_Filter_Brighten(OH_Filter* filter, float brightness)](#oh_filter_brighten) | Creates the brightening effect and adds it to a filter.|
| [EffectErrorCode OH_Filter_GrayScale(OH_Filter* filter)](#oh_filter_grayscale) | Creates the grayscale effect and adds it to a filter.|
| [EffectErrorCode OH_Filter_Invert(OH_Filter* filter)](#oh_filter_invert) | Creates the inverted color effect and adds it to a filter.|
| [EffectErrorCode OH_Filter_SetColorMatrix(OH_Filter* filter, OH_Filter_ColorMatrix* matrix)](#oh_filter_setcolormatrix) | Creates a custom effect through a matrix and adds it to a filter.|
| [EffectErrorCode OH_Filter_GetEffectPixelMap(OH_Filter* filter, OH_PixelmapNative** pixelmap)](#oh_filter_geteffectpixelmap) | Obtains the pixel map used to create a filter.|

## Function Description

### OH_Filter_CreateEffect()

```
EffectErrorCode OH_Filter_CreateEffect(OH_PixelmapNative* pixelmap, OH_Filter** filter)
```

**Description**

Creates an **OH_Filter** object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_PixelmapNative](capi-drawing-oh-pixelmapnative.md)* pixelmap | Pointer to the PixelMap.|
| [OH_Filter](capi-effectkit-oh-filter.md)** filter | Double pointer to the filter created.|

**Return value**

| Type| Description|
| -- | -- |
| [EffectErrorCode](capi-effect-types-h.md#effecterrorcode) | For details about the return value, see status code [EffectErrorCode](capi-effect-types-h.md#effecterrorcode).|

### OH_Filter_Release()

```
EffectErrorCode OH_Filter_Release(OH_Filter* filter)
```

**Description**

Releases an **OH_Filter** object.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Filter](capi-effectkit-oh-filter.md)* filter | Pointer to the filter.|

**Return value**

| Type| Description|
| -- | -- |
| [EffectErrorCode](capi-effect-types-h.md#effecterrorcode) | For details about the return value, see status code [EffectErrorCode](capi-effect-types-h.md#effecterrorcode).|

### OH_Filter_Blur()

```
EffectErrorCode OH_Filter_Blur(OH_Filter* filter, float radius)
```

**Description**

Creates the frosted glass effect and adds it to a filter.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Filter](capi-effectkit-oh-filter.md)* filter | Pointer to the filter.|
| float radius | Blur radius of the frosted glass effect, in px.|

**Return value**

| Type| Description|
| -- | -- |
| [EffectErrorCode](capi-effect-types-h.md#effecterrorcode) | For details about the return value, see status code [EffectErrorCode](capi-effect-types-h.md#effecterrorcode).|

### OH_Filter_BlurWithTileMode()

```
EffectErrorCode OH_Filter_BlurWithTileMode(OH_Filter* filter, float radius, EffectTileMode tileMode)
```

**Description**

Creates a frosted glass filter effect and adds it to the filter. The tiling mode of the shader effect can be selected.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Filter](capi-effectkit-oh-filter.md)* filter | Pointer to the filter.|
| float radius | Blur radius of the frosted glass effect, in px.|
| [EffectTileMode](capi-effect-types-h.md#effecttilemode) tileMode | Tile mode of the shader effect. For details about the supported modes, see [EffectTileMode](capi-effect-types-h.md#effecttilemode).|

**Return value**

| Type| Description|
| -- | -- |
| [EffectErrorCode](capi-effect-types-h.md#effecterrorcode) | For details, see [EffectErrorCode](capi-effect-types-h.md#effecterrorcode).<br> If the operation is successful, **EFFECT_SUCCESS** is returned.<br> If the parameter is invalid, EFFECT_BAD_PARAMETER is returned.|

### OH_Filter_Brighten()

```
EffectErrorCode OH_Filter_Brighten(OH_Filter* filter, float brightness)
```

**Description**

Creates the brightening effect and adds it to a filter.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Filter](capi-effectkit-oh-filter.md)* filter | Pointer to the filter.|
| float brightness | Brightness value of the brightening effect. The value ranges from 0 to 1. When the value is 0, the image remains unchanged. When the value is 1, the image is all white.|

**Return value**

| Type| Description|
| -- | -- |
| [EffectErrorCode](capi-effect-types-h.md#effecterrorcode) | For details, see [EffectErrorCode](capi-effect-types-h.md#effecterrorcode).|

### OH_Filter_GrayScale()

```
EffectErrorCode OH_Filter_GrayScale(OH_Filter* filter)
```

**Description**

Creates the grayscale effect and adds it to a filter.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Filter](capi-effectkit-oh-filter.md)* filter | Pointer to the filter.|

**Return value**

| Type| Description|
| -- | -- |
| [EffectErrorCode](capi-effect-types-h.md#effecterrorcode) | For details, see [EffectErrorCode](capi-effect-types-h.md#effecterrorcode).|

### OH_Filter_Invert()

```
EffectErrorCode OH_Filter_Invert(OH_Filter* filter)
```

**Description**

Creates the inverted color effect and adds it to a filter.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Filter](capi-effectkit-oh-filter.md)* filter | Pointer to the filter.|

**Return value**

| Type| Description|
| -- | -- |
| [EffectErrorCode](capi-effect-types-h.md#effecterrorcode) | For details, see [EffectErrorCode](capi-effect-types-h.md#effecterrorcode).|

### OH_Filter_SetColorMatrix()

```
EffectErrorCode OH_Filter_SetColorMatrix(OH_Filter* filter, OH_Filter_ColorMatrix* matrix)
```

**Description**

Creates a custom effect through a matrix and adds it to a filter.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Filter](capi-effectkit-oh-filter.md)* filter | Pointer to the filter.|
| [OH_Filter_ColorMatrix](capi-effectkit-oh-filter-colormatrix.md)* matrix | Custom matrix [OH_Filter_ColorMatrix](capi-effectkit-oh-filter-colormatrix.md) used to create the filter.|

**Return value**

| Type| Description|
| -- | -- |
| [EffectErrorCode](capi-effect-types-h.md#effecterrorcode) | For details about the returned result, see status code [EffectErrorCode](capi-effect-types-h.md#effecterrorcode).|

### OH_Filter_GetEffectPixelMap()

```
EffectErrorCode OH_Filter_GetEffectPixelMap(OH_Filter* filter, OH_PixelmapNative** pixelmap)
```

**Description**

Obtains the PixelMap used to create a filter.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Filter](capi-effectkit-oh-filter.md)* filter | Pointer to the filter.|
| [OH_PixelmapNative](capi-drawing-oh-pixelmapnative.md)** pixelmap | Double pointer to the PixelMap obtained.|

**Return value**

| Type| Description|
| -- | -- |
| [EffectErrorCode](capi-effect-types-h.md#effecterrorcode) | For details about the returned result, see status code [EffectErrorCode](capi-effect-types-h.md#effecterrorcode).|
