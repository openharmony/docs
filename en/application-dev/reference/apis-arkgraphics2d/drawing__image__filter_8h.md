# drawing_image_filter.h


## Overview

The **drawing_image_filter.h** file declares the functions related to the image filter in the drawing module.

**File to include**: &lt;native_drawing/drawing_image_filter.h&gt;

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_ImageFilter](_drawing.md#oh_drawing_imagefilter) \* [OH_Drawing_ImageFilterCreateBlur](_drawing.md#oh_drawing_imagefiltercreateblur) (float sigmaX, float sigmaY, [OH_Drawing_TileMode](_drawing.md#oh_drawing_tilemode), [OH_Drawing_ImageFilter](_drawing.md#oh_drawing_imagefilter) \*input) | Creates an **OH_Drawing_ImageFilter** object with a given blur type.| 
| [OH_Drawing_ImageFilter](_drawing.md#oh_drawing_imagefilter) \* [OH_Drawing_ImageFilterCreateFromColorFilter](_drawing.md#oh_drawing_imagefiltercreatefromcolorfilter) ([OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \*colorFilter, [OH_Drawing_ImageFilter](_drawing.md#oh_drawing_imagefilter) \*input) | Creates an **OH_Drawing_ImageFilter** object with a color filter effect.| 
| void [OH_Drawing_ImageFilterDestroy](_drawing.md#oh_drawing_imagefilterdestroy) ([OH_Drawing_ImageFilter](_drawing.md#oh_drawing_imagefilter) \*) | Destroys an **OH_Drawing_ImageFilter** object and reclaims the memory occupied by the object.| 
