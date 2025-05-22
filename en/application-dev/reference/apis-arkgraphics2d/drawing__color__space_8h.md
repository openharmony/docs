# drawing_color_space.h


## Overview

The **drawing_color_space.h** file declares the functions related to the color space in the drawing module.

**File to include**: &lt;native_drawing/drawing_color_space.h&gt;

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_ColorSpace](_drawing.md#oh_drawing_colorspace) \* [OH_Drawing_ColorSpaceCreateSrgb](_drawing.md#oh_drawing_colorspacecreatesrgb) (void) | Creates an sRGB color space.| 
| [OH_Drawing_ColorSpace](_drawing.md#oh_drawing_colorspace) \* [OH_Drawing_ColorSpaceCreateSrgbLinear](_drawing.md#oh_drawing_colorspacecreatesrgblinear) (void) | Creates an sRGB linear (Gamma 1.0) color space.| 
| void [OH_Drawing_ColorSpaceDestroy](_drawing.md#oh_drawing_colorspacedestroy) ([OH_Drawing_ColorSpace](_drawing.md#oh_drawing_colorspace) \*) | Destroys an **OH_Drawing_ColorSpace** object and reclaims the memory occupied by the object.| 
