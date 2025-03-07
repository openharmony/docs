# drawing_pixel_map.h


## Overview

The **drawing_pixel_map.h** file declares the functions related to the pixel map in the drawing module.

**File to include**: &lt;native_drawing/drawing_pixel_map.h&gt;

**Library**: libnative_drawing.so

**Since**: 12

**Related module**: [Drawing](_drawing.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Drawing_PixelMap](_drawing.md#oh_drawing_pixelmap) \* [OH_Drawing_PixelMapGetFromNativePixelMap](_drawing.md#oh_drawing_pixelmapgetfromnativepixelmap) (NativePixelMap_ \*) | Obtains the pixel map defined by this module from a pixel map defined by the image framework.| 
| [OH_Drawing_PixelMap](_drawing.md#oh_drawing_pixelmap) \* [OH_Drawing_PixelMapGetFromOhPixelMapNative](_drawing.md#oh_drawing_pixelmapgetfromohpixelmapnative) (OH_PixelmapNative \*) | Obtains the pixel map defined by this module from a pixel map defined by the image framework.| 
| void [OH_Drawing_PixelMapDissolve](_drawing.md#oh_drawing_pixelmapdissolve) ([OH_Drawing_PixelMap](_drawing.md#oh_drawing_pixelmap) \*) | Removes the relationship between a pixel map defined by this module and a pixel map defined by the image framework. The relationship is established by calling [OH_Drawing_PixelMapGetFromNativePixelMap](_drawing.md#oh_drawing_pixelmapgetfromnativepixelmap) or [OH_Drawing_PixelMapGetFromOhPixelMapNative](_drawing.md#oh_drawing_pixelmapgetfromohpixelmapnative).| 
