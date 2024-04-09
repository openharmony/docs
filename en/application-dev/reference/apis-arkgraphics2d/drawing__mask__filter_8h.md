# drawing_mask_filter.h


## Overview

The **drawing_mask_filter.h** file declares the functions related to the mask filter in the drawing module.

**File to include**: &lt;native_drawing/drawing_mask_filter.h&gt;

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [OH_Drawing_BlurType](_drawing.md#oh_drawing_blurtype)  [OH_Drawing_BlurType](_drawing.md#oh_drawing_blurtype) | Defines an enum for blur types.|


### Enums

| Name| Description|
| -------- | -------- |
| [OH_Drawing_BlurType](_drawing.md#oh_drawing_blurtype) { NORMAL, SOLID, OUTER, INNER } | Enumerates the blur types.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_MaskFilter](_drawing.md#oh_drawing_maskfilter) \* [OH_Drawing_MaskFilterCreateBlur](_drawing.md#oh_drawing_maskfiltercreateblur) ([OH_Drawing_BlurType](_drawing.md#oh_drawing_blurtype) blurType, float sigma, bool respectCTM) | Creates an **OH_Drawing_MaskFilter** object with a blur type.|
| void [OH_Drawing_MaskFilterDestroy](_drawing.md#oh_drawing_maskfilterdestroy) ([OH_Drawing_MaskFilter](_drawing.md#oh_drawing_maskfilter) \*) | Destroys an **OH_Drawing_MaskFilter** object and reclaims the memory occupied by the object.|
