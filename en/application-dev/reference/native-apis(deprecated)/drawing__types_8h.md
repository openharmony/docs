# drawing_types.h


## Overview

The **drawing_types.h** file declares the data types of the canvas, brush, pen, bitmap, and path used to draw 2D graphics.

**File to include**: &lt;native_drawing/drawing_types.h&gt;

**Library**: libnative_drawing.so

**Since**: 8

**Related module**: [Drawing](_drawing.md)


## Summary


### Types

| Name| Description|
| -------- | -------- |
| [OH_Drawing_Canvas](_drawing.md#oh_drawing_canvas) | Defines a rectangular canvas on which various shapes, images, and texts can be drawn by using the brush and pen.|
| [OH_Drawing_Pen](_drawing.md#oh_drawing_pen) | Defines a pen, which is used to describe the style and color to outline a shape.|
| [OH_Drawing_Brush](_drawing.md#oh_drawing_brush) | Defines a brush, which is used to describe the style and color to fill in a shape.|
| [OH_Drawing_Path](_drawing.md#oh_drawing_path) | Defines a path, which is used to customize various shapes.|
| [OH_Drawing_Bitmap](_drawing.md#oh_drawing_bitmap) | Defines a bitmap, which is a memory area that contains the pixel data of a shape.|
| [OH_Drawing_Point](_drawing.md#oh_drawing_point) | Defines a coordinate point.|
| [OH_Drawing_Rect](_drawing.md#oh_drawing_rect) | Defines a rectangle.|
| [OH_Drawing_RoundRect](_drawing.md#oh_drawing_roundrect) | Defines a rounded rectangle.|
| [OH_Drawing_Matrix](_drawing.md#oh_drawing_matrix) | Defines a matrix, which is used to describe coordinate transformation.|
| [OH_Drawing_ShaderEffect](_drawing.md#oh_drawing_shadereffect) | Defines a shader, which is used to describe the source color of the drawn content.|
| [OH_Drawing_Filter](_drawing.md#oh_drawing_filter) | Defines a filter, which consists of a color filter and mask filter.|
| [OH_Drawing_MaskFilter](_drawing.md#oh_drawing_maskfilter) | Defines a mask filter, which is used to convert the mask into a new one.|
| [OH_Drawing_ColorFilter](_drawing.md#oh_drawing_colorfilter) | Defines a color filter, which is used to convert a color into a new one.|
| [OH_Drawing_Font](_drawing.md#oh_drawing_font) | Defines a font.|
| [OH_Drawing_Typeface](_drawing.md#oh_drawing_typeface) | Defines a typeface.|
| [OH_Drawing_TextBlob](_drawing.md#oh_drawing_textblob) | Defines a TextBlob, an immutable container that holds multiple texts. Each text line consists of a glyph and position.|
| [OH_Drawing_TextBlobBuilder](_drawing.md#oh_drawing_textblobbuilder) | Defines a TextBlob builder, which is used to build a TextBlob.|


### Enums

| Name| Description|
| -------- | -------- |
| [OH_Drawing_ColorFormat](_drawing.md#oh_drawing_colorformat) {<br>COLOR_FORMAT_UNKNOWN, COLOR_FORMAT_ALPHA_8, COLOR_FORMAT_RGB_565, COLOR_FORMAT_ARGB_4444,COLOR_FORMAT_RGBA_8888, COLOR_FORMAT_BGRA_8888<br>} | Enumerates the storage formats of bitmap pixels.|
| [OH_Drawing_AlphaFormat](_drawing.md#oh_drawing_alphaformat) {<br>ALPHA_FORMAT_UNKNOWN, ALPHA_FORMAT_OPAQUE, ALPHA_FORMAT_PREMUL, ALPHA_FORMAT_UNPREMUL<br>} | Enumerates the alpha formats of bitmap pixels.|
| [OH_Drawing_BlendMode](_drawing.md#oh_drawing_blendmode) {<br>BLEND_MODE_CLEAR, BLEND_MODE_SRC, BLEND_MODE_DST, BLEND_MODE_SRC_OVER,<br>BLEND_MODE_DST_OVER, BLEND_MODE_SRC_IN, BLEND_MODE_DST_IN, BLEND_MODE_SRC_OUT,<br>BLEND_MODE_DST_OUT, BLEND_MODE_SRC_ATOP, BLEND_MODE_DST_ATOP, BLEND_MODE_XOR,<br>BLEND_MODE_PLUS, BLEND_MODE_MODULATE, BLEND_MODE_SCREEN, BLEND_MODE_OVERLAY,<br>BLEND_MODE_DARKEN, BLEND_MODE_LIGHTEN, BLEND_MODE_COLOR_DODGE, BLEND_MODE_COLOR_BURN,<br>BLEND_MODE_HARD_LIGHT, BLEND_MODE_SOFT_LIGHT, BLEND_MODE_DIFFERENCE, BLEND_MODE_EXCLUSION,<br>BLEND_MODE_MULTIPLY, BLEND_MODE_HUE, BLEND_MODE_SATURATION, BLEND_MODE_COLOR,<br>BLEND_MODE_LUMINOSITY<br>} | Enumerates the blend modes. In blend mode, each operation generates a new color for the two colors (source color and target color). These operations are the same on the four channels (red, green, blue, and alpha). The operations for the alpha channel are used as examples.|
