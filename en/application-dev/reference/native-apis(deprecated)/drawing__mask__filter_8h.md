# drawing_mask_filter.h


## Overview

The **drawing_mask_filter.h** file declares the functions related to the mask filter in the drawing module.

**File to include**: &lt;native_drawing/drawing_mask_filter.h&gt;

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Enums

| Name| Description|
| -------- | -------- |
| [OH_Drawing_BlurType](_drawing.md#oh_drawing_blurtype) {<br>NORMAL, SOLID, OUTER, INNER<br>} | Enumerates the blur types.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_MaskFilter](_drawing.md#oh_drawing_maskfilter) \* [OH_Drawing_MaskFilterCreateBlur](_drawing.md#oh_drawing_maskfiltercreateblur) ([OH_Drawing_BlurType](_drawing.md#oh_drawing_blurtype) blurType, float sigma, bool respectCTM) | Creates an **OH_Drawing_MaskFilter** object with a given blur type.|
| void [OH_Drawing_MaskFilterDestroy](_drawing.md#oh_drawing_maskfilterdestroy) ([OH_Drawing_MaskFilter](_drawing.md#oh_drawing_maskfilter) \*) | Destroys an **OH_Drawing_MaskFilter** object and reclaims the memory occupied by the object.|
