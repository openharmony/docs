# drawing_filter.h


## Overview

The **drawing_filter.h** file declares the functions related to the filter in the drawing module.

**File to include**: &lt;native_drawing/drawing_filter.h&gt;

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \* [OH_Drawing_FilterCreate](_drawing.md#oh_drawing_filtercreate) (void) | Creates an **OH_Drawing_Filter** object.|
| void [OH_Drawing_FilterSetImageFilter](_drawing.md#oh_drawing_filtersetimagefilter) ([OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \*, [OH_Drawing_ImageFilter](_drawing.md#oh_drawing_imagefilter) \*) | Sets an **OH_Drawing_ImageFilter** object for an **OH_Drawing_Filter** object.| 
| void [OH_Drawing_FilterSetMaskFilter](_drawing.md#oh_drawing_filtersetmaskfilter) ([OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \*, [OH_Drawing_MaskFilter](_drawing.md#oh_drawing_maskfilter) \*) | Sets an **OH_Drawing_MaskFilter** object for an **OH_Drawing_Filter** object.|
| void [OH_Drawing_FilterSetColorFilter](_drawing.md#oh_drawing_filtersetcolorfilter) ([OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \*, [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \*) | Sets an **OH_Drawing_ColorFilter** object for an **OH_Drawing_Filter** object.|
| void [OH_Drawing_FilterDestroy](_drawing.md#oh_drawing_filterdestroy) ([OH_Drawing_Filter](_drawing.md#oh_drawing_filter) \*) | Destroys an **OH_Drawing_Filter** object and reclaims the memory occupied by the object.|
