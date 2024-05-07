# drawing_bitmap.h


## Overview

The **drawing_bitmap.h** declares the functions related to the bitmap in the drawing module.

**File to include**: &lt;native_drawing/drawing_bitmap.h&gt;

**Library**: libnative_drawing.so

**Since**: 8

**Related module**: [Drawing](_drawing.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) | Defines the pixel format of a bitmap, including the color type and alpha type.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \* [OH_Drawing_BitmapCreate](_drawing.md#oh_drawing_bitmapcreate) (void) | Creates an **OH_Drawing_Bitmap** object.|
| void [OH_Drawing_BitmapDestroy](_drawing.md#oh_drawing_bitmapdestroy) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | Destroys an **OH_Drawing_Bitmap** object and reclaims the memory occupied by the object.|
| void [OH_Drawing_BitmapBuild](_drawing.md#oh_drawing_bitmapbuild) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*, const uint32_t width, const uint32_t height, const [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) \*) | Initializes the width and height of a bitmap and sets the pixel format for the bitmap.|
| uint32_t [OH_Drawing_BitmapGetWidth](_drawing.md#oh_drawing_bitmapgetwidth) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | Obtains the width of a bitmap.|
| uint32_t [OH_Drawing_BitmapGetHeight](_drawing.md#oh_drawing_bitmapgetheight) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | Obtains the height of a bitmap.|
| void \* [OH_Drawing_BitmapGetPixels](_drawing.md#oh_drawing_bitmapgetpixels) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | Obtains the pixel address of a bitmap. You can use this address to obtain the pixel data of the bitmap.|
