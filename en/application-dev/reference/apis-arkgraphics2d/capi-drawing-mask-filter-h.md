# drawing_mask_filter.h

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphic-->
<!--Owner: @hangmengxin-->
<!--Designer: @wangyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

## Overview

The **drawing_mask_filter.h** file declares the functions related to the mask filter in the drawing module.

**Header file**: <native_drawing/drawing_mask_filter.h>

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](capi-drawing.md)

## Total

### Enumerated value

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_Drawing_BlurType](#oh_drawing_blurtype) | OH_Drawing_BlurType | Defines an enum for the blur types.|

### Functions

| Name| Description|
| -- | -- |
| [OH_Drawing_MaskFilter* OH_Drawing_MaskFilterCreateBlur(OH_Drawing_BlurType blurType, float sigma, bool respectCTM)](#oh_drawing_maskfiltercreateblur) | Creates an **OH_Drawing_MaskFilter** object with a blur type.|
| [void OH_Drawing_MaskFilterDestroy(OH_Drawing_MaskFilter* maskFilter)](#oh_drawing_maskfilterdestroy) | Destroys an **OH_Drawing_MaskFilter** object and reclaims the memory occupied by the object.|

## Enum Description

### OH_Drawing_BlurType

```
enum OH_Drawing_BlurType
```

**Description**

Enumerates the blur types.

**Since**: 11

| Value| Description|
| -- | -- |
| NORMAL | Blurs both inside and outside the original border.|
| SOLID | Draws solid inside the border, and blurs outside.|
| OUTER | Draws nothing inside the border, and blurs outside.|
| INNER | Blurs inside the border, and draws nothing outside.|


## Function Description

### OH_Drawing_MaskFilterCreateBlur()

```
OH_Drawing_MaskFilter* OH_Drawing_MaskFilterCreateBlur(OH_Drawing_BlurType blurType, float sigma, bool respectCTM)
```

**Description**

Creates an **OH_Drawing_MaskFilter** object with a blur type.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_BlurType](#oh_drawing_blurtype) blurType | Blur type.|
| float sigma | Standard deviation of the Gaussian blur to apply. The value must be greater than 0.|
| bool respectCTM | Whether the blur's sigma is modified by the CTM. The default value is **true**.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_Drawing_MaskFilter](capi-drawing-oh-drawing-maskfilter.md)* | Pointer to the created mask filter object.|

### OH_Drawing_MaskFilterDestroy()

```
void OH_Drawing_MaskFilterDestroy(OH_Drawing_MaskFilter* maskFilter)
```

**Description**

Destroys an **OH_Drawing_MaskFilter** object and reclaims the memory occupied by the object.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeDrawing

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Drawing_MaskFilter](capi-drawing-oh-drawing-maskfilter.md)* maskFilter | Pointer to an **OH_Drawing_MaskFilter** object.|
