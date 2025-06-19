# EffectKit


## Overview

The EffectKit module provides the basic image processing capabilities, including brightness adjustment, blurring, and grayscale adjustment.

**System capability**: SystemCapability.Multimedia.Image.Core

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [effect_filter.h](effect__filter_8h.md) | Declares the APIs of an image effect filter.| 
| [effect_types.h](effect__types_8h.md) | Declares the data types of the image effect filter.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OH_Filter_ColorMatrix](_o_h___filter___color_matrix.md) | Describes a matrix used to create an effect filter.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_Filter](#oh_filter) [OH_Filter](#oh_filter) | Defines a struct for a filter used to generate a filter PixelMap.| 
| typedef struct [OH_PixelmapNative](#oh_pixelmapnative) [OH_PixelmapNative](#oh_pixelmapnative) | Defines a struct for a PixelMap.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [EffectErrorCode](#effecterrorcode) { EFFECT_SUCCESS = 0, EFFECT_BAD_PARAMETER = 401, EFFECT_UNSUPPORTED_OPERATION = 7600201, EFFECT_UNKNOWN_ERROR = 7600901 } | Enumerates the status codes that may be used by the effect filter.| 
| [EffectTileMode](#effecttilemode) { CLAMP = 0, REPEAT, MIRROR, DECAL } | Enumerates the tile modes of the shader effect.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [EffectErrorCode](#effecterrorcode) [OH_Filter_CreateEffect](#oh_filter_createeffect) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, [OH_Filter](#oh_filter) \*\*filter) | Creates an **OH_Filter** object.| 
| [EffectErrorCode](#effecterrorcode) [OH_Filter_Release](#oh_filter_release) ([OH_Filter](#oh_filter) \*filter) | Releases an **OH_Filter** object.| 
| [EffectErrorCode](#effecterrorcode) [OH_Filter_Blur](#oh_filter_blur) ([OH_Filter](#oh_filter) \*filter, float radius) | Creates the frosted glass effect and adds it to a filter.| 
| [EffectErrorCode](#effecterrorcode) [OH_Filter_BlurWithTileMode](#oh_filter_blurwithtilemode) ([OH_Filter](#oh_filter) \*filter, float radius, [EffectTileMode](#effecttilemode) tileMode) | Creates the frosted glass effect and adds it to a filter.| 
| [EffectErrorCode](#effecterrorcode) [OH_Filter_Brighten](#oh_filter_brighten) ([OH_Filter](#oh_filter) \*filter, float brightness) | Creates the brightening effect and adds it to a filter.| 
| [EffectErrorCode](#effecterrorcode) [OH_Filter_GrayScale](#oh_filter_grayscale) ([OH_Filter](#oh_filter) \*filter) | Creates the grayscale effect and adds it to a filter.| 
| [EffectErrorCode](#effecterrorcode) [OH_Filter_Invert](#oh_filter_invert) ([OH_Filter](#oh_filter) \*filter) | Creates the inverted color effect and adds it to a filter.| 
| [EffectErrorCode](#effecterrorcode) [OH_Filter_SetColorMatrix](#oh_filter_setcolormatrix) ([OH_Filter](#oh_filter) \*filter, [OH_Filter_ColorMatrix](_o_h___filter___color_matrix.md) \*matrix) | Creates a custom effect through a matrix and adds it to a filter.| 
| [EffectErrorCode](#effecterrorcode) [OH_Filter_GetEffectPixelMap](#oh_filter_geteffectpixelmap) ([OH_Filter](#oh_filter) \*filter, [OH_PixelmapNative](#oh_pixelmapnative) \*\*pixelmap) | Obtains the PixelMap used to create a filter.| 


## Type Description


### OH_Filter

```
typedef struct OH_Filter OH_Filter
```

**Description**

Defines a struct for a filter used to generate a filter PixelMap.

**Since**: 12


### OH_PixelmapNative

```
typedef struct OH_PixelmapNative OH_PixelmapNative
```

**Description**

 

**Since**: 12


## Enum Description


### EffectErrorCode

```
enum EffectErrorCode
```

**Description**

Enumerates the status codes that may be used by the effect filter.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| EFFECT_SUCCESS | Operation successful.| 
| EFFECT_BAD_PARAMETER | Invalid parameter.| 
| EFFECT_UNSUPPORTED_OPERATION | Unsupported operation.| 
| EFFECT_UNKNOWN_ERROR | Unknown error.| 


### EffectTileMode

```
enum EffectTileMode
```

**Description**

Enumerates the tile modes of the shader effect.

**Since**: 14

| Value| Description| 
| -------- | -------- |
| CLAMP | Replicates the edge color if the shader effect draws outside of its original boundary.| 
| REPEAT | Repeats the shader effect in both horizontal and vertical directions.| 
| MIRROR | Repeats the shader effect in both horizontal and vertical directions, alternating mirror images.| 
| DECAL | Renders the shader effect only within the original boundary.| 


## Function Description


### OH_Filter_Blur()

```
EffectErrorCode OH_Filter_Blur (OH_Filter* filter, float radius )
```

**Description**

Creates the frosted glass effect and adds it to a filter.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to the filter.| 
| radius | Blur radius of the frosted glass effect, in px.| 

**Returns**

Returns a status code defined in [EffectErrorCode](#effecterrorcode).


### OH_Filter_BlurWithTileMode()

```
EffectErrorCode OH_Filter_BlurWithTileMode (OH_Filter* filter, float radius, EffectTileMode tileMode )
```

**Description**

Creates the frosted glass effect and adds it to a filter.

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to the filter.| 
| radius | Blur radius of the frosted glass effect, in px.| 
| tileMode | Tile mode of the shader effect. For details about the available options, see [EffectTileMode](#effecttilemode).| 

**Returns**

Returns a status code defined in [EffectErrorCode](#effecterrorcode).

If the operation is successful, **EFFECT_SUCCESS** is returned.

If a parameter is invalid, **EFFECT_BAD_PARAMETER** is returned.


### OH_Filter_Brighten()

```
EffectErrorCode OH_Filter_Brighten (OH_Filter* filter, float brightness )
```

**Description**

Creates the brightening effect and adds it to a filter.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to the filter.| 
| brightness | Luminance of the brightening effect. The value ranges from 0 to 1. When the value is **0**, the image remains unchanged.| 

**Returns**

Returns a status code defined in [EffectErrorCode](#effecterrorcode).


### OH_Filter_CreateEffect()

```
EffectErrorCode OH_Filter_CreateEffect (OH_PixelmapNative* pixelmap, OH_Filter** filter )
```

**Description**

Creates an **OH_Filter** object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| pixelmap | Pointer to the PixelMap.| 
| filter | Double pointer to the filter created.| 

**Returns**

Returns a status code defined in [EffectErrorCode](#effecterrorcode).


### OH_Filter_GetEffectPixelMap()

```
EffectErrorCode OH_Filter_GetEffectPixelMap (OH_Filter* filter, OH_PixelmapNative** pixelmap )
```

**Description**

Obtains the PixelMap used to create a filter.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to the filter.| 
| pixelmap | Double pointer to the PixelMap obtained.| 

**Returns**

Returns a status code defined in [EffectErrorCode](#effecterrorcode).


### OH_Filter_GrayScale()

```
EffectErrorCode OH_Filter_GrayScale (OH_Filter* filter)
```

**Description**

Creates the grayscale effect and adds it to a filter.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to the filter.| 

**Returns**

Returns a status code defined in [EffectErrorCode](#effecterrorcode).


### OH_Filter_Invert()

```
EffectErrorCode OH_Filter_Invert (OH_Filter* filter)
```

**Description**

Creates the inverted color effect and adds it to a filter.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to the filter.| 

**Returns**

Returns a status code defined in [EffectErrorCode](#effecterrorcode).


### OH_Filter_Release()

```
EffectErrorCode OH_Filter_Release (OH_Filter* filter)
```

**Description**

Releases an **OH_Filter** object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to the filter.| 

**Returns**

Returns a status code defined in [EffectErrorCode](#effecterrorcode).


### OH_Filter_SetColorMatrix()

```
EffectErrorCode OH_Filter_SetColorMatrix (OH_Filter* filter, OH_Filter_ColorMatrix* matrix )
```

**Description**

Creates a custom effect through a matrix and adds it to a filter.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to the filter.| 
| matrix | Pointer to a custom matrix, which is an [OH_Filter_ColorMatrix](_o_h___filter___color_matrix.md) object.| 

**Returns**

Returns a status code defined in [EffectErrorCode](#effecterrorcode).
