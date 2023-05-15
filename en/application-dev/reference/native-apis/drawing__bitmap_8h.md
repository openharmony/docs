# drawing_bitmap.h


## Overview

Declares functions related to the **bitmap** object in the drawing module.

**Since:**
8

**Related Modules:**

[Drawing](_drawing.md)


## Summary


### Structs

| Name | Description | 
| -------- | -------- |
| [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) | Defines the pixel format of a bitmap, including the color type and alpha type.  | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_Drawing_BitmapCreate](_drawing.md#oh_drawing_bitmapcreate) (void) | Creates an **OH_Drawing_Bitmap** object.  | 
| [OH_Drawing_BitmapDestroy](_drawing.md#oh_drawing_bitmapdestroy) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | Destroys an **OH_Drawing_Bitmap** object and reclaims the memory occupied by the object.  | 
| [OH_Drawing_BitmapBuild](_drawing.md#oh_drawing_bitmapbuild) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*, const uint32_t width, const uint32_t height, const [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) \*) | Initializes the width and height of an **OH_Drawing_Bitmap** object and sets the pixel format for the bitmap.  | 
| [OH_Drawing_BitmapGetWidth](_drawing.md#oh_drawing_bitmapgetwidth) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | Obtains the width of a bitmap.  | 
| [OH_Drawing_BitmapGetHeight](_drawing.md#oh_drawing_bitmapgetheight) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | Obtains the height of a bitmap.  | 
| [OH_Drawing_BitmapGetPixels](_drawing.md#oh_drawing_bitmapgetpixels) ([OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) \*) | Obtains the pixel address of a bitmap. You can use this address to obtain the pixel data of the bitmap.  | 
