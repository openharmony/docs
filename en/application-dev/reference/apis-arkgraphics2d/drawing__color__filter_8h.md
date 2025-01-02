# drawing_color_filter.h


## Overview

The **drawing_color_filter.h** file declares the functions related to the color filter in the drawing module.

**File to include**: &lt;native_drawing/drawing_color_filter.h&gt;

**Library**: libnative_drawing.so

**Since**: 11

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateBlendMode](_drawing.md#oh_drawing_colorfiltercreateblendmode) (uint32_t color, [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode)) | Creates an **OH_Drawing_ColorFilter** object with a given blend mode.| 
| [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateCompose](_drawing.md#oh_drawing_colorfiltercreatecompose) ([OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \*colorFilter1, [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \*colorFilter2) | Creates an **OH_Drawing_ColorFilter** object by combining another two color filters.| 
| [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateMatrix](_drawing.md#oh_drawing_colorfiltercreatematrix) (const float matrix[20]) | Creates an **OH_Drawing_ColorFilter** object with a given 5x4 color matrix.| 
| [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateLinearToSrgbGamma](_drawing.md#oh_drawing_colorfiltercreatelineartosrgbgamma) (void) | Creates an **OH_Drawing_ColorFilter** object that applies the sRGB gamma curve to the RGB channels.| 
| [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateSrgbGammaToLinear](_drawing.md#oh_drawing_colorfiltercreatesrgbgammatolinear) (void) | Creates an **OH_Drawing_ColorFilter** object that applies the RGB channels to the sRGB gamma curve.| 
| [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \* [OH_Drawing_ColorFilterCreateLuma](_drawing.md#oh_drawing_colorfiltercreateluma) (void) | Creates an **OH_Drawing_ColorFilter** object that multiplies the passed-in luma into the alpha channel and sets the RGB channels to zero.| 
| void [OH_Drawing_ColorFilterDestroy](_drawing.md#oh_drawing_colorfilterdestroy) ([OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) \*) | Destroys an **OH_Drawing_ColorFilter** object and reclaims the memory occupied by the object.| 
