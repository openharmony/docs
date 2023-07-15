# drawing_types.h


## Overview

Declares the data types for drawing 2D graphics, including the canvas, brush, pen, bitmap, and path.

**Since:**
8

**Related Modules:**

[Drawing](_drawing.md)


## Summary


### Types

| Name | Description | 
| -------- | -------- |
| [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) | Defines a rectangular canvas on which various shapes, images, and texts can be drawn by using the brush and pen.  | 
| [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) | Defines a pen, which is used to describe the style and color to outline a shape.  | 
| [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) | Defines as a brush, which is used to describe the style and color to fill in a shape.  | 
| [OH_Drawing_Path](_drawing.md#oh_drawing_path) | Defines a path, which is used to customize various shapes.  | 
| [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) | Defines a bitmap, which is a memory that contains the pixel data of a shape.  | 


### Enums

| Name | Description | 
| -------- | -------- |
| [OH_Drawing_ColorFormat](_drawing.md#oh_drawing_colorformat) {<br/>COLOR_FORMAT_UNKNOWN, COLOR_FORMAT_ALPHA_8, COLOR_FORMAT_RGB_565, COLOR_FORMAT_ARGB_4444,<br/>COLOR_FORMAT_RGBA_8888, COLOR_FORMAT_BGRA_8888<br/>} | Enumerates storage formats of bitmap pixels.  | 
| [OH_Drawing_AlphaFormat](_drawing.md#oh_drawing_alphaformat) { ALPHA_FORMAT_UNKNOWN, ALPHA_FORMAT_OPAQUE, ALPHA_FORMAT_PREMUL, ALPHA_FORMAT_UNPREMUL } | Enumerates alpha formats of bitmap pixels.  | 
