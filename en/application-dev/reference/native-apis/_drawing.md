# Drawing


The **Drawing** module provides functions for 2D graphics rendering, text drawing, and image display.


It provides the 2D drawing capability.


@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing


**Since**


8


## Summary


### Files

| Name                                                    | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [drawing_bitmap.h](drawing__bitmap_8h.md)                    | Declares functions related to the **bitmap** object in the drawing module.<br>File to include: <native_drawing/drawing_bitmap.h> <br>Library: libnative_drawing.so                         |
| [drawing_brush.h](drawing__brush_8h.md)                      | Declares functions related to the **brush** object in the drawing module.<br>File to include: <native_drawing/drawing_brush.h> <br>Library: libnative_drawing.so                      |
| [drawing_canvas.h](drawing__canvas_8h.md)                    | Declares functions related to the **canvas** object in the drawing module.<br>File to include: <native_drawing/drawing_canvas.h> <br>Library: libnative_drawing.so                         |
| [drawing_color.h](drawing__color_8h.md)                      | Declares functions related to the **color** object in the drawing module.<br>File to include: <native_drawing/drawing_color.h> <br>Library: libnative_drawing.so                          |
| [drawing_font_collection.h](drawing__font__collection_8h.md) | Declares functions related to **FontCollection** in the drawing module.<br>File to include: <native_drawing/drawing_font_collection.h><br>Library: libnative_drawing.so                 |
| [drawing_path.h](drawing__path_8h.md)                        | Declares functions related to the **path** object in the drawing module.<br>File to include: <native_drawing/drawing_path.h><br>Library: libnative_drawing.so                    |
| [drawing_pen.h](drawing__pen_8h.md)                          | Declares functions related to the **pen** object in the drawing module.<br>File to include: <native_drawing/drawing_pen.h><br>Library: libnative_drawing.so                          |
| [drawing_text_declaration.h](drawing__text__declaration_8h.md) | Declares the struct related to text in 2D drawing.<br>File to include: <native_drawing/drawing_text_declaration.h><br>Library: libnative_drawing.so                      |
| [drawing_text_typography.h](drawing__text__typography_8h.md) | Declares functions related to **typography** in the drawing module.<br>File to include: <native_drawing/drawing_text_typography.h><br>Library: libnative_drawing.so                              |
| [drawing_types.h](drawing__types_8h.md)                      | Declares the data types for drawing 2D graphics, including the canvas, brush, pen, bitmap, and path.<br>File to include: <native_drawing/drawing_types.h><br>Library: libnative_drawing.so|


### Structs

| Name                                                  | Description                                                    |
| ------------------------------------------------------------ | -------------------------------------------------------- |
| [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) | Defines the pixel format of a bitmap, including the color type and alpha type.|


### Types

| Name                                               | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| [OH_Drawing_FontCollection](#oh_drawing_fontcollection)     | Defines an **OH_Drawing_FontCollection**, which is used to load fonts.                     |
| [OH_Drawing_Typography](#oh_drawing_typography)             | Defines an **OH_Drawing_Typography**, which is used to manage the typography layout and display.           |
| [OH_Drawing_TextStyle](#oh_drawing_textstyle)               | Defines an **OH_Drawing_TextStyle**, which is used to manage text colors and decorations.              |
| [OH_Drawing_TypographyStyle](#oh_drawing_typographystyle)   | Defines an **OH_Drawing_TypographyStyle**, which is used to manage the typography style, such as the text direction.  |
| [OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) | Defines an **OH_Drawing_TypographyCreate**, which is used to create an **OH_Drawing_Typography** object.  |
| [OH_Drawing_Canvas](#oh_drawing_canvas)                     | Defines a rectangular canvas on which various shapes, images, and texts can be drawn by using the brush and pen.|
| [OH_Drawing_Pen](#oh_drawing_pen)                           | Defines a pen, which is used to describe the style and color to outline a shape.|
| [OH_Drawing_Brush](#oh_drawing_brush)                       | Defines a brush, which is used to describe the style and color to fill in a shape.|
| [OH_Drawing_Path](#oh_drawing_path)                         | Defines a path, which is used to customize various shapes.     |
| [OH_Drawing_Bitmap](#oh_drawing_bitmap)                     | Defines a bitmap, which is a memory area that contains the pixel data of a shape.|


### Enums

| Name                                                    | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle) { LINE_FLAT_CAP, LINE_SQUARE_CAP, LINE_ROUND_CAP } | Enumerates the line cap styles of a pen. The line cap style defines the style of both ends of a line segment drawn by the pen.|
| [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle) { LINE_MITER_JOIN, LINE_ROUND_JOIN, LINE_BEVEL_JOIN } | Enumerates the line join styles of a pen. The line join style defines the shape of the joints of a polyline segment drawn by the pen.|
| [OH_Drawing_TextDirection](#oh_drawing_textdirection) { TEXT_DIRECTION_RTL, TEXT_DIRECTION_LTR } | Enumerates the text directions.                                                  |
| [OH_Drawing_TextAlign](#oh_drawing_textalign) { TEXT_ALIGN_LEFT, TEXT_ALIGN_RIGHT, TEXT_ALIGN_CENTER, TEXT_ALIGN_JUSTIFY,   TEXT_ALIGN_START, TEXT_ALIGN_END } | Enumerates the text alignment modes.                                              |
| [OH_Drawing_FontWeight](#oh_drawing_fontweight) {  FONT_WEIGHT_100, FONT_WEIGHT_200, FONT_WEIGHT_300, FONT_WEIGHT_400,   FONT_WEIGHT_500, FONT_WEIGHT_600, FONT_WEIGHT_700, FONT_WEIGHT_800,  FONT_WEIGHT_900  } | Enumerates the font weights.                                                      |
| [OH_Drawing_TextBaseline](#oh_drawing_textbaseline) { TEXT_BASELINE_ALPHABETIC, TEXT_BASELINE_IDEOGRAPHIC } | Enumerates the text baselines.                                                  |
| [OH_Drawing_TextDecoration](#oh_drawing_textdecoration) { TEXT_DECORATION_NONE = 0x0, TEXT_DECORATION_UNDERLINE = 0x1, TEXT_DECORATION_OVERLINE = 0x2, TEXT_DECORATION_LINE_THROUGH = 0x4 } | Enumerates the text decorations.                                                  |
| [OH_Drawing_FontStyle](#oh_drawing_fontstyle) { FONT_STYLE_NORMAL, FONT_STYLE_ITALIC } | Enumerates the font styles.                                        |
| [OH_Drawing_ColorFormat](#oh_drawing_colorformat) {  COLOR_FORMAT_UNKNOWN, COLOR_FORMAT_ALPHA_8, COLOR_FORMAT_RGB_565, COLOR_FORMAT_ARGB_4444,   COLOR_FORMAT_RGBA_8888, COLOR_FORMAT_BGRA_8888 } | Enumerates the storage formats of bitmap pixels.          |
| [OH_Drawing_AlphaFormat](#oh_drawing_alphaformat) { ALPHA_FORMAT_UNKNOWN, ALPHA_FORMAT_OPAQUE, ALPHA_FORMAT_PREMUL, ALPHA_FORMAT_UNPREMUL } | Enumerates the alpha formats of bitmap pixels.        |


### Functions

| Name                                                    | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Drawing_BitmapCreate](#oh_drawing_bitmapcreate) (void)   | Creates an **OH_Drawing_Bitmap** object.                                          |
| [OH_Drawing_BitmapDestroy](#oh_drawing_bitmapdestroy) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Destroys an **OH_Drawing_Bitmap** object and reclaims the memory occupied by the object.                          |
| [OH_Drawing_BitmapBuild](#oh_drawing_bitmapbuild) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*, const uint32_t width, const uint32_t height, const [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) \*) | Initializes the width and height of an **OH_Drawing_Bitmap** object and sets its pixel format.      |
| [OH_Drawing_BitmapGetWidth](#oh_drawing_bitmapgetwidth) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Obtains the width of a bitmap.                                        |
| [OH_Drawing_BitmapGetHeight](#oh_drawing_bitmapgetheight) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Obtains the height of a bitmap.                                        |
| [OH_Drawing_BitmapGetPixels](#oh_drawing_bitmapgetpixels) ([OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Obtains the pixel address of a bitmap. You can use this address to obtain the pixel data of the bitmap.|
| [OH_Drawing_BrushCreate](#oh_drawing_brushcreate) (void)     | Creates an **OH_Drawing_Brush** object.                                          |
| [OH_Drawing_BrushDestroy](#oh_drawing_brushdestroy) ([OH_Drawing_Brush](#oh_drawing_brush) \*) | Destroys an **OH_Drawing_Brush** object and reclaims the memory occupied by the object.                        |
| [OH_Drawing_BrushIsAntiAlias](#oh_drawing_brushisantialias) (const [OH_Drawing_Brush](#oh_drawing_brush) \*) | Checks whether anti-aliasing is enabled for a brush. If anti-aliasing is enabled, edges will be drawn with partial transparency.|
| [OH_Drawing_BrushSetAntiAlias](#oh_drawing_brushsetantialias) ([OH_Drawing_Brush](#oh_drawing_brush) \*, bool) | Enables or disables anti-aliasing for a brush. If anti-aliasing is enabled, edges will be drawn with partial transparency.|
| [OH_Drawing_BrushGetColor](#oh_drawing_brushgetcolor) (const [OH_Drawing_Brush](#oh_drawing_brush) \*) | Obtains the color of a brush. The color is used by the brush to fill in a shape.|
| [OH_Drawing_BrushSetColor](#oh_drawing_brushsetcolor) ([OH_Drawing_Brush](#oh_drawing_brush) \*, uint32_t color) | Sets the color for a brush. The color will be used by the brush to fill in a shape.|
| [OH_Drawing_CanvasCreate](#oh_drawing_canvascreate) (void)   | Creates an **OH_Drawing_Canvas** object.                                          |
| [OH_Drawing_CanvasDestroy](#oh_drawing_canvasdestroy) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Destroys an **OH_Drawing_Canvas** object and reclaims the memory occupied by the object.                        |
| [OH_Drawing_CanvasBind](#oh_drawing_canvasbind) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, [OH_Drawing_Bitmap](#oh_drawing_bitmap) \*) | Binds a bitmap to a canvas so that the content drawn on the canvas is output to the bitmap. (This process is called CPU rendering.)|
| [OH_Drawing_CanvasAttachPen](#oh_drawing_canvasattachpen) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Attaches a pen to a canvas so that the canvas will use the style and color of the pen to outline a shape.|
| [OH_Drawing_CanvasDetachPen](#oh_drawing_canvasdetachpen) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Detaches the pen from a canvas so that the canvas will not use the style and color of the pen to outline a shape.    |
| [OH_Drawing_CanvasAttachBrush](#oh_drawing_canvasattachbrush) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Brush](#oh_drawing_brush) \*) | Attaches a brush to a canvas so that the canvas will use the style and color of the brush to fill in a shape.|
| [OH_Drawing_CanvasDetachBrush](#oh_drawing_canvasdetachbrush) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Detaches the brush from a canvas so that the canvas will not use the style and color of the brush to fill in a shape.          |
| [OH_Drawing_CanvasSave](#oh_drawing_canvassave) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Saves the current canvas status (canvas matrix) to the top of the stack.                  |
| [OH_Drawing_CanvasRestore](#oh_drawing_canvasrestore) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*) | Restores the canvas status (canvas matrix) saved on the top of the stack.                      |
| [OH_Drawing_CanvasDrawLine](#oh_drawing_canvasdrawline) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, float x1, float y1, float x2, float y2) | Draws a line segment.                                              |
| [OH_Drawing_CanvasDrawPath](#oh_drawing_canvasdrawpath) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, const [OH_Drawing_Path](#oh_drawing_path) \*) | Draws a path.                                          |
| [OH_Drawing_CanvasClear](#oh_drawing_canvasclear) ([OH_Drawing_Canvas](#oh_drawing_canvas) \*, uint32_t color) | Clears a canvas by using a specified color.                                    |
| [OH_Drawing_ColorSetArgb](#oh_drawing_colorsetargb) (uint32_t alpha, uint32_t red, uint32_t green, uint32_t blue) | Converts four variables (alpha, red, green, and blue) into a 32-bit (ARGB) variable that describes a color.|
| [OH_Drawing_CreateFontCollection](#oh_drawing_createfontcollection) (void) | Creates an **OH_Drawing_FontCollection** object.                             |
| [OH_Drawing_DestroyFontCollection](#oh_drawing_destroyfontcollection) ([OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*) | Destroys an **OH_Drawing_FontCollection** object and reclaims the memory occupied by the object.             |
| [OH_Drawing_PathCreate](#oh_drawing_pathcreate) (void)       | Creates an **OH_Drawing_Path** object.                                          |
| [OH_Drawing_PathDestroy](#oh_drawing_pathdestroy) ([OH_Drawing_Path](#oh_drawing_path) \*) | Destroys an **OH_Drawing_Path** object and reclaims the memory occupied by the object.                        |
| [OH_Drawing_PathMoveTo](#oh_drawing_pathmoveto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x, float y) | Sets the start point of a path.                                |
| [OH_Drawing_PathLineTo](#oh_drawing_pathlineto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x, float y) | Draws a line segment from the last point of a path to the target point.              |
| [OH_Drawing_PathArcTo](#oh_drawing_patharcto) ([OH_Drawing_Path](#oh_drawing_path) \*, float x1, float y1, float x2, float y2, float startDeg, float sweepDeg) | Draws an arc to a path. This is done by using angle arc mode. In this mode, a rectangle that encloses an ellipse is specified first, and then a start angle and a sweep angle are specified. The arc is a portion of the ellipse defined by the start angle and the sweep angle. By default, a line segment from the last point of the path to the start point of the arc is also added.|
| [OH_Drawing_PathQuadTo](#oh_drawing_pathquadto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX, float ctrlY, float endX, float endY) | Draws a quadratic Bezier curve from the last point of a path to the target point.  |
| [OH_Drawing_PathCubicTo](#oh_drawing_pathcubicto) ([OH_Drawing_Path](#oh_drawing_path) \*, float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY) | Draws a cubic Bezier curve from the last point of a path to the target point.  |
| [OH_Drawing_PathClose](#oh_drawing_pathclose) ([OH_Drawing_Path](#oh_drawing_path) \*) | Closes a path. A line segment from the start point to the last point of the path is added.      |
| [OH_Drawing_PathReset](#oh_drawing_pathreset) ([OH_Drawing_Path](#oh_drawing_path) \*) | Resets path data.                                        |
| [OH_Drawing_PenCreate](#oh_drawing_pencreate) (void)         | Creates an **OH_Drawing_Pen** object.                                          |
| [OH_Drawing_PenDestroy](#oh_drawing_pendestroy) ([OH_Drawing_Pen](#oh_drawing_pen) \*) | Destroys an **OH_Drawing_Pen** object and reclaims the memory occupied by the object.                        |
| [OH_Drawing_PenIsAntiAlias](#oh_drawing_penisantialias) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Checks whether anti-aliasing is enabled for a pen. If anti-aliasing is enabled, edges will be drawn with partial transparency.|
| [OH_Drawing_PenSetAntiAlias](#oh_drawing_pensetantialias) ([OH_Drawing_Pen](#oh_drawing_pen) \*, bool) | Enables or disables anti-aliasing for a pen. If anti-aliasing is enabled, edges will be drawn with partial transparency.|
| [OH_Drawing_PenGetColor](#oh_drawing_pengetcolor) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Obtains the color of a pen. The color is used by the pen to outline a shape.|
| [OH_Drawing_PenSetColor](#oh_drawing_pensetcolor) ([OH_Drawing_Pen](#oh_drawing_pen) \*, uint32_t color) | Sets the color for a pen. The color is used by the pen to outline a shape.|
| [OH_Drawing_PenGetWidth](#oh_drawing_pengetwidth) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Obtains the thickness of a pen. This thickness determines the width of the outline of a shape.  |
| [OH_Drawing_PenSetWidth](#oh_drawing_pensetwidth) ([OH_Drawing_Pen](#oh_drawing_pen) \*, float width) | Sets the thickness for a pen. This thickness determines the width of the outline of a shape.  |
| [OH_Drawing_PenGetMiterLimit](#oh_drawing_pengetmiterlimit) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Obtains the stroke miter limit of a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.|
| [OH_Drawing_PenSetMiterLimit](#oh_drawing_pensetmiterlimit) ([OH_Drawing_Pen](#oh_drawing_pen) \*, float miter) | Sets the stroke miter limit for a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.|
| [OH_Drawing_PenGetCap](#oh_drawing_pengetcap) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Obtains the line cap style of a pen.                                        |
| [OH_Drawing_PenSetCap](#oh_drawing_pensetcap) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_PenLineCapStyle](#oh_drawing_penlinecapstyle)) | Sets the line cap style for a pen.                                          |
| [OH_Drawing_PenGetJoin](#oh_drawing_pengetjoin) (const [OH_Drawing_Pen](#oh_drawing_pen) \*) | Obtains the line join style of a pen.                                |
| [OH_Drawing_PenSetJoin](#oh_drawing_pensetjoin) ([OH_Drawing_Pen](#oh_drawing_pen) \*, [OH_Drawing_PenLineJoinStyle](#oh_drawing_penlinejoinstyle)) | Sets the line join style for a pen.                                    |
| [OH_Drawing_CreateTypographyStyle](#oh_drawing_createtypographystyle) (void) | Creates an **OH_Drawing_TypographyStyle** object.                            |
| [OH_Drawing_DestroyTypographyStyle](#oh_drawing_destroytypographystyle) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*) | Destroys an **OH_Drawing_TypographyStyle** object and reclaims the memory occupied by the object.            |
| [OH_Drawing_SetTypographyTextDirection](#oh_drawing_settypographytextdirection) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the text direction.                                              |
| [OH_Drawing_SetTypographyTextAlign](#oh_drawing_settypographytextalign) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the text alignment mode.                                          |
| [OH_Drawing_SetTypographyTextMaxLines](#oh_drawing_settypographytextmaxlines) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, int) | Sets the maximum number of lines in the text.                                          |
| [OH_Drawing_CreateTextStyle](#oh_drawing_createtextstyle) (void) | Creates an **OH_Drawing_TextStyle** object.                                  |
| [OH_Drawing_DestroyTextStyle](#oh_drawing_destroytextstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Destroys an **OH_Drawing_TextStyle** object and reclaims the memory occupied by the object.                  |
| [OH_Drawing_SetTextStyleColor](#oh_drawing_settextstylecolor) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, uint32_t) | Sets the text color.                                              |
| [OH_Drawing_SetTextStyleFontSize](#oh_drawing_settextstylefontsize) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | Sets the font size.                                                  |
| [OH_Drawing_SetTextStyleFontWeight](#oh_drawing_settextstylefontweight) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Sets the font weight.                                                  |
| [OH_Drawing_SetTextStyleBaseLine](#oh_drawing_settextstylebaseline) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Sets the text baseline.                                          |
| [OH_Drawing_SetTextStyleDecoration](#oh_drawing_settextstyledecoration) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Sets the text decoration.                                                  |
| [OH_Drawing_SetTextStyleDecorationColor](#oh_drawing_settextstyledecorationcolor) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, uint32_t) | Sets the color for the text decoration.                                              |
| [OH_Drawing_SetTextStyleFontHeight](#oh_drawing_settextstylefontheight) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, double) | Sets the font height.                                              |
| [OH_Drawing_SetTextStyleFontFamilies](#oh_drawing_settextstylefontfamilies) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int, const char \*fontFamilies[]) | Sets the font families.                                              |
| [OH_Drawing_SetTextStyleFontStyle](#oh_drawing_settextstylefontstyle) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, int) | Sets the font style.                                              |
| [OH_Drawing_SetTextStyleLocale](#oh_drawing_settextstylelocale) ([OH_Drawing_TextStyle](#oh_drawing_textstyle) \*, const char \*) | Sets the locale.                                              |
| [OH_Drawing_CreateTypographyHandler](#oh_drawing_createtypographyhandler) ([OH_Drawing_TypographyStyle](#oh_drawing_typographystyle) \*, [OH_Drawing_FontCollection](#oh_drawing_fontcollection) \*) | Creates an **OH_Drawing_TypographyCreate** object.             |
| [OH_Drawing_DestroyTypographyHandler](#oh_drawing_destroytypographyhandler) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*) | Destroys an **OH_Drawing_TypographyCreate** object and reclaims the memory occupied by the object.           |
| [OH_Drawing_TypographyHandlerPushTextStyle](#oh_drawing_typographyhandlerpushtextstyle) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*, [OH_Drawing_TextStyle](#oh_drawing_textstyle) \*) | Sets the text style.                                              |
| [OH_Drawing_TypographyHandlerAddText](#oh_drawing_typographyhandleraddtext) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*, const char \*) | Sets the text content.                                              |
| [OH_Drawing_TypographyHandlerPopTextStyle](#oh_drawing_typographyhandlerpoptextstyle) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*) | Removes the topmost style in the stack, leaving the remaining styles in effect.                                                  |
| [OH_Drawing_CreateTypography](#oh_drawing_createtypography) ([OH_Drawing_TypographyCreate](#oh_drawing_typographycreate) \*) | Creates an **OH_Drawing_Typography** object.                                 |
| [OH_Drawing_DestroyTypography](#oh_drawing_destroytypography) ([OH_Drawing_Typography](#oh_drawing_typography) \*) | Destroys an **OH_Drawing_Typography** object and reclaims the memory occupied by the object.                   |
| [OH_Drawing_TypographyLayout](#oh_drawing_typographylayout) ([OH_Drawing_Typography](#oh_drawing_typography) \*, double) | Lays out the typography.                                                  |
| [OH_Drawing_TypographyPaint](#oh_drawing_typographypaint) ([OH_Drawing_Typography](#oh_drawing_typography) \*, [OH_Drawing_Canvas](#oh_drawing_canvas) \*, double, double) | Paints text on the canvas.                                                  |
| [OH_Drawing_TypographyGetMaxWidth](#oh_drawing_typographygetmaxwidth) ([OH_Drawing_Typography](#oh_drawing_typography) *) | Obtains the maximum width.                                              |
| [OH_Drawing_TypographyGetHeight](#oh_drawing_typographygetheight) ([OH_Drawing_Typography](#oh_drawing_typography) *) | Obtains the height.                                                  |
| [OH_Drawing_TypographyGetLongestLine](#oh_drawing_typographygetlongestline) ([OH_Drawing_Typography](#oh_drawing_typography) *) | Obtains the longest line.                                                |
| [OH_Drawing_TypographyGetMinIntrinsicWidth](#oh_drawing_typographygetminintrinsicwidth) ([OH_Drawing_Typography](#oh_drawing_typography) *) | Obtains the minimum intrinsic width.                                          |
| [OH_Drawing_TypographyGetMaxIntrinsicWidth](#oh_drawing_typographygetmaxintrinsicwidth) ([OH_Drawing_Typography](#oh_drawing_typography) *) | Obtains the maximum intrinsic width.                                          |
| [OH_Drawing_TypographyGetAlphabeticBaseline](#oh_drawing_typographygetalphabeticbaseline)([OH_Drawing_Typography](#oh_drawing_typography) *) | Obtains the alphabetic baseline.                                          |
| [OH_Drawing_TypographyGetIdeographicBaseline](#oh_drawing_typographygetideographicbaseline) ([OH_Drawing_Typography](#oh_drawing_typography) *) | Obtains the ideographic baseline.                                          |


## Type Description


### OH_Drawing_Bitmap


```
typedef struct OH_Drawing_Bitmap OH_Drawing_Bitmap
```

**Description**

Defines a bitmap, which is a memory area that contains the pixel data of a shape.

**Since**

8


### OH_Drawing_Brush


```
typedef struct OH_Drawing_Brush OH_Drawing_Brush
```

**Description**

Defines a brush, which is used to describe the style and color to fill in a shape.

**Since**

8


### OH_Drawing_Canvas


```
typedef struct OH_Drawing_Canvas OH_Drawing_Canvas
```

**Description**

Defines a rectangular canvas on which various shapes, images, and texts can be drawn by using the brush and pen.

**Since**

8


### OH_Drawing_FontCollection


```
typedef struct OH_Drawing_FontCollection OH_Drawing_FontCollection
```

**Description**

Defines an **OH_Drawing_FontCollection**, which is used to load fonts.

**Since**

8


### OH_Drawing_Path


```
typedef struct OH_Drawing_Path OH_Drawing_Path
```

**Description**

Defines a path, which is used to customize various shapes.

**Since**

8


### OH_Drawing_Pen


```
typedef struct OH_Drawing_Pen OH_Drawing_Pen
```

**Description**

Defines a pen, which is used to describe the style and color to outline a shape.

**Since**

8


### OH_Drawing_TextStyle


```
typedef struct OH_Drawing_TextStyle OH_Drawing_TextStyle
```

**Description**

Defines an **OH_Drawing_TextStyle**, which is used to manage text colors and decorations.

**Since**

8


### OH_Drawing_Typography


```
typedef struct OH_Drawing_Typography OH_Drawing_Typography
```

**Description**

Defines an **OH_Drawing_Typography**, which is used to manage the typography layout and display.

**Since**

8


### OH_Drawing_TypographyCreate


```
typedef struct OH_Drawing_TypographyCreate OH_Drawing_TypographyCreate
```

**Description**

Defines an **OH_Drawing_TypographyCreate**, which is used to create an **OH_Drawing_Typography** object.

**Since**

8


### OH_Drawing_TypographyStyle


```
typedef struct OH_Drawing_TypographyStyle OH_Drawing_TypographyStyle
```

**Description**

Defines an **OH_Drawing_TypographyStyle**, which is used to manage the typography style, such as the text direction.

**Since**

8


## Enum Description


### OH_Drawing_AlphaFormat


```
enum OH_Drawing_AlphaFormat
```

**Description**

Enumerates the alpha formats of bitmap pixels.

| Value               | Description                                    |
| --------------------- | ---------------------------------------- |
| ALPHA_FORMAT_UNKNOWN  | Unknown format.                                |
| ALPHA_FORMAT_OPAQUE   | The bitmap does not have the alpha component.                            |
| ALPHA_FORMAT_PREMUL   | The color component of each pixel is premultiplied by the alpha component.  |
| ALPHA_FORMAT_UNPREMUL | The color component of each pixel is not premultiplied by the alpha component.|

**Since**

8


### OH_Drawing_ColorFormat


```
enum OH_Drawing_ColorFormat
```

**Description**

Enumerates the storage formats of bitmap pixels.

| Value                | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| COLOR_FORMAT_UNKNOWN   | Unknown format.                                                   |
| COLOR_FORMAT_ALPHA_8   | Each pixel is represented by 8 bits, which together indicate alpha.            |
| COLOR_FORMAT_RGB_565   | Each pixel is represented by 16 bits. From the most significant bit to the least significant bit, the first 5 bits indicate red, the subsequent 6 bits indicate green, and the last 5 bits indicate blue.|
| COLOR_FORMAT_ARGB_4444 | Each pixel is represented by 16 bits. From the most significant bit to the least significant bit, every 4 bits indicate alpha, red, green, and blue, respectively.|
| COLOR_FORMAT_RGBA_8888 | Each pixel is represented by 32 bits. From the most significant bit to the least significant bit, every 8 bits indicate alpha, red, green, and blue, respectively.|
| COLOR_FORMAT_BGRA_8888 | Each pixel is represented by 32 bits. From the most significant bit to the least significant bit, every 8 bits indicate blue, green, red, and alpha, respectively.|

**Since**

8


### OH_Drawing_FontStyle


```
enum OH_Drawing_FontStyle
```

**Description**

Enumerates the font styles.

| Value           | Description  |
| ----------------- | ------ |
| FONT_STYLE_NORMAL | Normal style.|
| FONT_STYLE_ITALIC | Italic.  |

**Since**

8


### OH_Drawing_FontWeight


```
enum OH_Drawing_FontWeight
```

**Description**

Enumerates the font weights.

| Value         | Description                |
| --------------- | -------------------- |
| FONT_WEIGHT_100 | Thin.          |
| FONT_WEIGHT_200 | Extra-light.   |
| FONT_WEIGHT_300 | Light.         |
| FONT_WEIGHT_400 | .Normal/Regular.|
| FONT_WEIGHT_500 | Medium.        |
| FONT_WEIGHT_600 | Semi-bold.     |
| FONT_WEIGHT_700 | Bold.          |
| FONT_WEIGHT_800 | Extra-bold.    |
| FONT_WEIGHT_900 | Black.         |

**Since**

8


### OH_Drawing_PenLineCapStyle


```
enum OH_Drawing_PenLineCapStyle
```

**Description**

Enumerates the line cap styles of a pen. The line cap style defines the style of both ends of a line segment drawn by the pen.

| Value         | Description                                                        |
| --------------- | ------------------------------------------------------------ |
| LINE_FLAT_CAP   | There is no cap style. Both ends of the line segment are cut off square.                            |
| LINE_SQUARE_CAP | Square cap style. Both ends have a square, the height of which is half of the width of the line segment, with the same width.|
| LINE_ROUND_CAP  | Round cap style. Both ends have a semicircle centered, the diameter of which is the same as the width of the line segment.|

**Since**

8


### OH_Drawing_PenLineJoinStyle


```
enum OH_Drawing_PenLineJoinStyle
```

**Description**

Enumerates the line join styles of a pen. The line join style defines the shape of the joints of a polyline segment drawn by the pen.

| Value         | Description                                                        |
| --------------- | ------------------------------------------------------------ |
| LINE_MITER_JOIN | Mitered corner. If the angle of a polyline is small, its miter length may be inappropriate. In this case, you need to use the miter limit to limit the miter length.|
| LINE_ROUND_JOIN | Round corner.                                              |
| LINE_BEVEL_JOIN | Beveled corner.                                              |

**Since**

8


### OH_Drawing_TextAlign


```
enum OH_Drawing_TextAlign
```

**Description**

Enumerates the text alignment modes.

| Value            | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| TEXT_ALIGN_LEFT    | Left-aligned.                                                      |
| TEXT_ALIGN_RIGHT   | Right-aligned.                                                      |
| TEXT_ALIGN_CENTER  | Center-aligned.                                                    |
| TEXT_ALIGN_JUSTIFY | Justified, which means that each line (except the last line) is stretched so that every line has equal width, and the left and right margins are straight.|
| TEXT_ALIGN_START   | **TEXT_ALIGN_START** achieves the same effect as **TEXT_ALIGN_LEFT** when **OH_Drawing_TextDirection** is **TEXT_DIRECTION_LTR**; it achieves the same effect as **TEXT_ALIGN_RIGHT** when **OH_Drawing_TextDirection** is **TEXT_DIRECTION_RTL**.|
| TEXT_ALIGN_END     | **TEXT_ALIGN_END** achieves the same effect as **TEXT_ALIGN_RIGHT** when **OH_Drawing_TextDirection** is **TEXT_DIRECTION_LTR**; it achieves the same effect as **TEXT_ALIGN_LEFT** when **OH_Drawing_TextDirection** is **TEXT_DIRECTION_RTL**.|

**Since**

8


### OH_Drawing_TextBaseline


```
enum OH_Drawing_TextBaseline
```

**Description**

Enumerates the text baselines.

| Value                   | Description                              |
| ------------------------- | ---------------------------------- |
| TEXT_BASELINE_ALPHABETIC  | Alphabetic, where the letters in alphabets like English sit on.|
| TEXT_BASELINE_IDEOGRAPHIC | Ideographic. The baseline is at the bottom of the text area.        |

**Since**

8


### OH_Drawing_TextDecoration


```
enum OH_Drawing_TextDecoration
```

**Description**

Enumerates the text decorations.

| Value                      | Description  |
| ---------------------------- | ------ |
| TEXT_DECORATION_NONE         | No decoration.|
| TEXT_DECORATION_UNDERLINE    | An underline is used for decoration.|
| TEXT_DECORATION_OVERLINE     | An overline is used for decoration.|
| TEXT_DECORATION_LINE_THROUGH | A strikethrough is used for decoration.|

**Since**

8


### OH_Drawing_TextDirection


```
enum OH_Drawing_TextDirection
```

**Description**

Enumerates the text directions.

| Value            | Description          |
| ------------------ | -------------- |
| TEXT_DIRECTION_RTL | Right to left (RTL).|
| TEXT_DIRECTION_LTR | Left to right (LTR).|

**Since**

8


## Function Description


### OH_Drawing_BitmapBuild()


```
void OH_Drawing_BitmapBuild (OH_Drawing_Bitmap * , const uint32_t width, const uint32_t height, const OH_Drawing_BitmapFormat *  )
```

**Description**

Initializes the width and height of an **OH_Drawing_Bitmap** object and sets its pixel format.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                                                         | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_Drawing_Bitmap                                            | Pointer to an **OH_Drawing_Bitmap** object.                                |
| width                                                        | Width of the bitmap to be initialized.                                |
| height                                                       | Height of the bitmap to be initialized.                                |
| [OH_Drawing_BitmapFormat](_o_h___drawing___bitmap_format.md) | Pixel format of the bitmap to be initialized, including the pixel color type and alpha type.|

**Since**

8


### OH_Drawing_BitmapCreate()


```
OH_Drawing_Bitmap* OH_Drawing_BitmapCreate (void )
```

**Description**

Creates an **OH_Drawing_Bitmap** object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Returns**

Returns the pointer to the **OH_Drawing_Bitmap** object created.

**Since**

8


### OH_Drawing_BitmapDestroy()


```
void OH_Drawing_BitmapDestroy (OH_Drawing_Bitmap * )
```

**Description**

Destroys an **OH_Drawing_Bitmap** object and reclaims the memory occupied by the object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name              | Description                        |
| ----------------- | ---------------------------- |
| OH_Drawing_Bitmap | Pointer to an **OH_Drawing_Bitmap** object.|

**Since**

8


### OH_Drawing_BitmapGetHeight()


```
uint32_t OH_Drawing_BitmapGetHeight (OH_Drawing_Bitmap * )
```

**Description**

Obtains the height of a bitmap.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name              | Description                        |
| ----------------- | ---------------------------- |
| OH_Drawing_Bitmap | Pointer to an **OH_Drawing_Bitmap** object.|

**Returns**

Returns the height.

**Since**

8


### OH_Drawing_BitmapGetPixels()


```
void* OH_Drawing_BitmapGetPixels (OH_Drawing_Bitmap * )
```

**Description**

Obtains the pixel address of a bitmap. You can use this address to obtain the pixel data of the bitmap.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name              | Description                        |
| ----------------- | ---------------------------- |
| OH_Drawing_Bitmap | Pointer to an **OH_Drawing_Bitmap** object.|

**Returns**

Returns the pixel address.

**Since**

8


### OH_Drawing_BitmapGetWidth()


```
uint32_t OH_Drawing_BitmapGetWidth (OH_Drawing_Bitmap * )
```

**Description**

Obtains the width of a bitmap.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name              | Description                        |
| ----------------- | ---------------------------- |
| OH_Drawing_Bitmap | Pointer to an **OH_Drawing_Bitmap** object.|

**Returns**

Returns the width.

**Since**

8


### OH_Drawing_BrushCreate()


```
OH_Drawing_Brush* OH_Drawing_BrushCreate (void )
```

**Description**

Creates an **OH_Drawing_Brush** object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Returns**

Returns the pointer to the **OH_Drawing_Brush** object created.

**Since**

8


### OH_Drawing_BrushDestroy()


```
void OH_Drawing_BrushDestroy (OH_Drawing_Brush * )
```

**Description**

Destroys an **OH_Drawing_Brush** object and reclaims the memory occupied by the object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name             | Description                        |
| ---------------- | ---------------------------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.|

**Since**

8


### OH_Drawing_BrushGetColor()


```
uint32_t OH_Drawing_BrushGetColor (const OH_Drawing_Brush * )
```

**Description**

Obtains the color of a brush. The color is used by the brush to fill in a shape.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name             | Description                        |
| ---------------- | ---------------------------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.|

**Returns**

Returns a 32-bit (ARGB) variable that describes the color.

**Since**

8


### OH_Drawing_BrushIsAntiAlias()


```
bool OH_Drawing_BrushIsAntiAlias (const OH_Drawing_Brush * )
```

**Description**

Checks whether anti-aliasing is enabled for a brush. If anti-aliasing is enabled, edges will be drawn with partial transparency.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name             | Description                        |
| ---------------- | ---------------------------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.|

**Returns**

Returns **true** if anti-aliasing is enabled; returns **false** otherwise.

**Since**

8


### OH_Drawing_BrushSetAntiAlias()


```
void OH_Drawing_BrushSetAntiAlias (OH_Drawing_Brush * , bool  )
```

**Description**

Enables or disables anti-aliasing for a brush. If anti-aliasing is enabled, edges will be drawn with partial transparency.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name             | Description                                  |
| ---------------- | -------------------------------------- |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.          |
| bool             | Whether to enable anti-aliasing. The value **true** means to enable anti-aliasing, and **false** means the opposite.|

**Since**

8


### OH_Drawing_BrushSetColor()


```
void OH_Drawing_BrushSetColor (OH_Drawing_Brush * , uint32_t color )
```

**Description**

Sets the color for a brush. The color will be used by the brush to fill in a shape.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name             | Description                                |
| ---------------- | ------------------------------------ |
| OH_Drawing_Brush | Pointer to an **OH_Drawing_Brush** object.        |
| color            | Color to set, which is a 32-bit (ARGB) variable.|

**Since**

8


### OH_Drawing_CanvasAttachBrush()


```
void OH_Drawing_CanvasAttachBrush (OH_Drawing_Canvas * , const OH_Drawing_Brush *  )
```

**Description**

Attaches a brush to a canvas so that the canvas will use the style and color of the brush to fill in a shape.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name              | Description                        |
| ----------------- | ---------------------------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|
| OH_Drawing_Brush  | Pointer to an **OH_Drawing_Brush** object.|

**Since**

8


### OH_Drawing_CanvasAttachPen()


```
void OH_Drawing_CanvasAttachPen (OH_Drawing_Canvas * , const OH_Drawing_Pen *  )
```

**Description**

Attaches a pen to a canvas so that the canvas will use the style and color of the pen to outline a shape.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name              | Description                        |
| ----------------- | ---------------------------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|
| OH_Drawing_Pen    | Pointer to an **OH_Drawing_Pen** object.|

**Since**

8


### OH_Drawing_CanvasBind()


```
void OH_Drawing_CanvasBind (OH_Drawing_Canvas * , OH_Drawing_Bitmap *  )
```

**Description**

Binds a bitmap to a canvas so that the content drawn on the canvas is output to the bitmap. (This process is called CPU rendering.)

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name              | Description                        |
| ----------------- | ---------------------------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|
| OH_Drawing_Bitmap | Pointer to an **OH_Drawing_Bitmap** object.|

**Since**

8


### OH_Drawing_CanvasClear()


```
void OH_Drawing_CanvasClear (OH_Drawing_Canvas * , uint32_t color )
```

**Description**

Clears a canvas by using a specified color.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name              | Description                                |
| ----------------- | ------------------------------------ |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.        |
| color             | Color to set, which is a 32-bit (ARGB) variable.|

**Since**

8


### OH_Drawing_CanvasCreate()


```
OH_Drawing_Canvas* OH_Drawing_CanvasCreate (void )
```

**Description**

Creates an **OH_Drawing_Canvas** object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Returns**

Returns the pointer to the **OH_Drawing_Canvas** object created.

**Since**

8


### OH_Drawing_CanvasDestroy()


```
void OH_Drawing_CanvasDestroy (OH_Drawing_Canvas * )
```

**Description**

Destroys an **OH_Drawing_Canvas** object and reclaims the memory occupied by the object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name              | Description                        |
| ----------------- | ---------------------------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|

**Since**

8


### OH_Drawing_CanvasDetachBrush()


```
void OH_Drawing_CanvasDetachBrush (OH_Drawing_Canvas * )
```

**Description**

Detaches the brush from a canvas so that the canvas will not use the style and color of the brush to fill in a shape.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name              | Description                        |
| ----------------- | ---------------------------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|

**Since**

8


### OH_Drawing_CanvasDetachPen()


```
void OH_Drawing_CanvasDetachPen (OH_Drawing_Canvas * )
```

**Description**

Detaches the pen from a canvas so that the canvas will not use the style and color of the pen to outline a shape.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name              | Description                        |
| ----------------- | ---------------------------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|

**Since**

8


### OH_Drawing_CanvasDrawLine()


```
void OH_Drawing_CanvasDrawLine (OH_Drawing_Canvas * , float x1, float y1, float x2, float y2 )
```

**Description**

Draws a line segment.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name              | Description                        |
| ----------------- | ---------------------------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|
| x1                | X coordinate of the start point of the line segment.    |
| y1                | Y coordinate of the start point of the line segment.    |
| x2                | X coordinate of the end point of the line segment.    |
| y2                | Y coordinate of the end point of the line segment.    |

**Since**

8


### OH_Drawing_CanvasDrawPath()


```
void OH_Drawing_CanvasDrawPath (OH_Drawing_Canvas * , const OH_Drawing_Path *  )
```

**Description**

Draws a path.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name              | Description                        |
| ----------------- | ---------------------------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|
| OH_Drawing_Path   | Pointer to an **OH_Drawing_Path** object.|

**Since**

8


### OH_Drawing_CanvasRestore()


```
void OH_Drawing_CanvasRestore (OH_Drawing_Canvas * )
```

**Description**

Restores the canvas status (canvas matrix) saved on the top of the stack.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name              | Description                        |
| ----------------- | ---------------------------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|

**Since**

8


### OH_Drawing_CanvasSave()


```
void OH_Drawing_CanvasSave (OH_Drawing_Canvas * )
```

**Description**

Saves the current canvas status (canvas matrix) to the top of the stack.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name              | Description                        |
| ----------------- | ---------------------------- |
| OH_Drawing_Canvas | Pointer to an **OH_Drawing_Canvas** object.|

**Since**

8


### OH_Drawing_ColorSetArgb()


```
uint32_t OH_Drawing_ColorSetArgb (uint32_t alpha, uint32_t red, uint32_t green, uint32_t blue )
```

**Description**

Converts four variables (alpha, red, green, and blue) into a 32-bit (ARGB) variable that describes a color.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name  | Description                                           |
| ----- | ----------------------------------------------- |
| alpha | Variable that describes alpha. The value ranges from 0x00 to 0xFF.|
| red   | Variable that describes red. The value ranges from 0x00 to 0xFF.  |
| green | Variable that describes green. The value ranges from 0x00 to 0xFF.  |
| blue  | Variable that describes blue. The value ranges from 0x00 to 0xFF.  |

**Returns**

Returns a 32-bit (ARGB) variable that describes the color.

**Since**

8


### OH_Drawing_CreateFontCollection()


```
OH_Drawing_FontCollection* OH_Drawing_CreateFontCollection (void )
```

**Description**

Creates an **OH_Drawing_FontCollection** object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Returns**

Returns the pointer to the **OH_Drawing_FontCollection** object created.

**Since**

8


### OH_Drawing_CreateTextStyle()


```
OH_Drawing_TextStyle* OH_Drawing_CreateTextStyle (void )
```

**Description**

Creates an **OH_Drawing_TextStyle** object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Returns**

Returns the pointer to the **OH_Drawing_TextStyle** object created.

**Since**

8


### OH_Drawing_CreateTypography()


```
OH_Drawing_Typography* OH_Drawing_CreateTypography (OH_Drawing_TypographyCreate * )
```

**Description**

Creates an **OH_Drawing_Typography** object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                        | Description                                     |
| --------------------------- | ----------------------------------------- |
| OH_Drawing_TypographyCreate | Pointer to an **OH_Drawing_TypographyCreate** object.|

**Returns**

Returns the pointer to the **OH_Drawing_Typography** object created.

**Since**

8


### OH_Drawing_CreateTypographyHandler()


```
OH_Drawing_TypographyCreate* OH_Drawing_CreateTypographyHandler (OH_Drawing_TypographyStyle * , OH_Drawing_FontCollection *  )
```

**Description**

Creates an **OH_Drawing_TypographyCreate** object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                       | Description                                |
| -------------------------- | ------------------------------------ |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object.|
| OH_Drawing_FontCollection  | Pointer to an **OH_Drawing_FontCollection** object. |

**Returns**

Returns the pointer to the **OH_Drawing_TypographyCreate** object created.

**Since**

8


### OH_Drawing_CreateTypographyStyle()


```
OH_Drawing_TypographyStyle* OH_Drawing_CreateTypographyStyle (void )
```

**Description**

Creates an **OH_Drawing_TypographyStyle** object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Returns**

Returns the pointer to the **OH_Drawing_TypographyStyle** object created.

**Since**

8


### OH_Drawing_DestroyFontCollection()


```
void OH_Drawing_DestroyFontCollection (OH_Drawing_FontCollection * )
```

**Description**

Destroys an **OH_Drawing_FontCollection** object and reclaims the memory occupied by the object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                      | Description                                   |
| ------------------------- | --------------------------------------- |
| OH_Drawing_FontCollection | Pointer to an **OH_Drawing_FontCollection** object.|

**Since**

8


### OH_Drawing_DestroyTextStyle()


```
void OH_Drawing_DestroyTextStyle (OH_Drawing_TextStyle * )
```

**Description**

Destroys an **OH_Drawing_TextStyle** object and reclaims the memory occupied by the object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                              |
| -------------------- | ---------------------------------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object.|

**Since**

8


### OH_Drawing_DestroyTypography()


```
void OH_Drawing_DestroyTypography (OH_Drawing_Typography * )
```

**Description**

Destroys an **OH_Drawing_Typography** object and reclaims the memory occupied by the object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                  | Description                               |
| --------------------- | ----------------------------------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object.|

**Since**

8


### OH_Drawing_DestroyTypographyHandler()


```
void OH_Drawing_DestroyTypographyHandler (OH_Drawing_TypographyCreate * )
```

**Description**

Destroys an **OH_Drawing_TypographyCreate** object and reclaims the memory occupied by the object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                        | Description                                     |
| --------------------------- | ----------------------------------------- |
| OH_Drawing_TypographyCreate | Pointer to an **OH_Drawing_TypographyCreate** object.|

**Since**

8


### OH_Drawing_DestroyTypographyStyle()


```
void OH_Drawing_DestroyTypographyStyle (OH_Drawing_TypographyStyle * )
```

**Description**

Destroys an **OH_Drawing_TypographyStyle** object and reclaims the memory occupied by the object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                       | Description                                    |
| -------------------------- | ---------------------------------------- |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object.|

**Since**

8


### OH_Drawing_PathArcTo()


```
void OH_Drawing_PathArcTo (OH_Drawing_Path * , float x1, float y1, float x2, float y2, float startDeg, float sweepDeg )
```

**Description**

Draws an arc to a path. This is done by using angle arc mode. In this mode, a rectangle that encloses an ellipse is specified first, and then a start angle and a sweep angle are specified. The arc is a portion of the ellipse defined by the start angle and the sweep angle. By default, a line segment from the last point of the path to the start point of the arc is also added.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name            | Description                                    |
| --------------- | ---------------------------------------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.            |
| x1              | X coordinate of the upper left corner of the rectangle.|
| y1              | Y coordinate of the upper left corner of the rectangle.|
| x2              | X coordinate of the lower right corner of the rectangle.|
| y2              | Y coordinate of the lower right corner of the rectangle.|
| startDeg        | Start angle, in degrees.                        |
| sweepDeg        | Angle to sweep, in degrees.                        |

**Since**

8


### OH_Drawing_PathClose()


```
void OH_Drawing_PathClose (OH_Drawing_Path * )
```

**Description**

Closes a path. A line segment from the start point to the last point of the path is added.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name            | Description                        |
| --------------- | ---------------------------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.|

**Since**

8


### OH_Drawing_PathCreate()


```
OH_Drawing_Path* OH_Drawing_PathCreate (void )
```

**Description**

Creates an **OH_Drawing_Path** object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Returns**

Returns the pointer to the **OH_Drawing_Path** object created.

**Since**

8


### OH_Drawing_PathCubicTo()


```
void OH_Drawing_PathCubicTo (OH_Drawing_Path * , float ctrlX1, float ctrlY1, float ctrlX2, float ctrlY2, float endX, float endY )
```

**Description**

Draws a cubic Bezier curve from the last point of a path to the target point.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name            | Description                          |
| --------------- | ------------------------------ |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.  |
| ctrlX1          | X coordinate of the first control point.|
| ctrlY1          | Y coordinate of the first control point.|
| ctrlX2          | X coordinate of the second control point.|
| ctrlY2          | Y coordinate of the second control point.|
| endX            | X coordinate of the target point.      |
| endY            | Y coordinate of the target point.      |

**Since**

8


### OH_Drawing_PathDestroy()


```
void OH_Drawing_PathDestroy (OH_Drawing_Path * )
```

**Description**

Destroys an **OH_Drawing_Path** object and reclaims the memory occupied by the object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name            | Description                        |
| --------------- | ---------------------------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.|

**Since**

8


### OH_Drawing_PathLineTo()


```
void OH_Drawing_PathLineTo (OH_Drawing_Path * , float x, float y )
```

**Description**

Draws a line segment from the last point of a path to the target point.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name            | Description                        |
| --------------- | ---------------------------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.|
| x               | X coordinate of the target point.        |
| y               | Y coordinate of the target point.        |

**Since**

8


### OH_Drawing_PathMoveTo()


```
void OH_Drawing_PathMoveTo (OH_Drawing_Path * , float x, float y )
```

**Description**

Sets the start point of a path.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name            | Description                        |
| --------------- | ---------------------------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.|
| x               | X coordinate of the start point.        |
| y               | Y coordinate of the start point.        |

**Since**

8


### OH_Drawing_PathQuadTo()


```
void OH_Drawing_PathQuadTo (OH_Drawing_Path * , float ctrlX, float ctrlY, float endX, float endY )
```

**Description**

Draws a quadratic Bezier curve from the last point of a path to the target point.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name            | Description                        |
| --------------- | ---------------------------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.|
| ctrlX           | X coordinate of the control point.    |
| ctrlY           | Y coordinate of the control point.    |
| endX            | X coordinate of the target point.    |
| endY            | Y coordinate of the target point.    |

**Since**

8


### OH_Drawing_PathReset()


```
void OH_Drawing_PathReset (OH_Drawing_Path * )
```

**Description**

Resets path data.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name            | Description                        |
| --------------- | ---------------------------- |
| OH_Drawing_Path | Pointer to an **OH_Drawing_Path** object.|

**Since**

8


### OH_Drawing_PenCreate()


```
OH_Drawing_Pen* OH_Drawing_PenCreate (void )
```

**Description**

Creates an **OH_Drawing_Pen** object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Returns**

Returns the pointer to the **OH_Drawing_Pen** object created.

**Since**

8


### OH_Drawing_PenDestroy()


```
void OH_Drawing_PenDestroy (OH_Drawing_Pen * )
```

**Description**

Destroys an **OH_Drawing_Pen** object and reclaims the memory occupied by the object.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name           | Description                        |
| -------------- | ---------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.|

**Since**

8


### OH_Drawing_PenGetCap()


```
OH_Drawing_PenLineCapStyle OH_Drawing_PenGetCap (const OH_Drawing_Pen * )
```

**Description**

Obtains the line cap style of a pen.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name           | Description                        |
| -------------- | ---------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.|

**Returns**

Returns the line cap style.

**Since**

8


### OH_Drawing_PenGetColor()


```
uint32_t OH_Drawing_PenGetColor (const OH_Drawing_Pen * )
```

**Description**

Obtains the color of a pen. The color is used by the pen to outline a shape.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name           | Description                        |
| -------------- | ---------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.|

**Returns**

Returns a 32-bit (ARGB) variable that describes the color.

**Since**

8


### OH_Drawing_PenGetJoin()


```
OH_Drawing_PenLineJoinStyle OH_Drawing_PenGetJoin (const OH_Drawing_Pen * )
```

**Description**

Obtains the line join style of a pen.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name           | Description                        |
| -------------- | ---------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.|

**Returns**

Returns the line join style.

**Since**

8


### OH_Drawing_PenGetMiterLimit()


```
float OH_Drawing_PenGetMiterLimit (const OH_Drawing_Pen * )
```

**Description**

Obtains the stroke miter limit of a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name           | Description                        |
| -------------- | ---------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.|

**Returns**

Returns the miter limit.

**Since**

8


### OH_Drawing_PenGetWidth()


```
float OH_Drawing_PenGetWidth (const OH_Drawing_Pen * )
```

**Description**

Obtains the thickness of a pen. This thickness determines the width of the outline of a shape.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name           | Description                        |
| -------------- | ---------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.|

**Returns**

Returns the thickness.

**Since**

8


### OH_Drawing_PenIsAntiAlias()


```
bool OH_Drawing_PenIsAntiAlias (const OH_Drawing_Pen * )
```

**Description**

Checks whether anti-aliasing is enabled for a pen. If anti-aliasing is enabled, edges will be drawn with partial transparency.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name           | Description                        |
| -------------- | ---------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.|

**Returns**

Returns **true** if anti-aliasing is enabled; returns **false** otherwise.

**Since**

8


### OH_Drawing_PenSetAntiAlias()


```
void OH_Drawing_PenSetAntiAlias (OH_Drawing_Pen * , bool  )
```

**Description**

Enables or disables anti-aliasing for a pen. If anti-aliasing is enabled, edges will be drawn with partial transparency.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name           | Description                                  |
| -------------- | -------------------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.          |
| bool           | Whether to enable anti-aliasing. The value **true** means to enable anti-aliasing, and **false** means the opposite.|

**Since**

8


### OH_Drawing_PenSetCap()


```
void OH_Drawing_PenSetCap (OH_Drawing_Pen * , OH_Drawing_PenLineCapStyle  )
```

**Description**

Sets the line cap style for a pen.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                       | Description                            |
| -------------------------- | -------------------------------- |
| OH_Drawing_Pen             | Pointer to an **OH_Drawing_Pen** object.    |
| OH_Drawing_PenLineCapStyle | Variable that describes the line cap style.|

**Since**

8


### OH_Drawing_PenSetColor()


```
void OH_Drawing_PenSetColor (OH_Drawing_Pen * , uint32_t color )
```

**Description**

Sets the color for a pen. The color is used by the pen to outline a shape.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name           | Description                                |
| -------------- | ------------------------------------ |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.        |
| color          | Color to set, which is a 32-bit (ARGB) variable.|

**Since**

8


### OH_Drawing_PenSetJoin()


```
void OH_Drawing_PenSetJoin (OH_Drawing_Pen * , OH_Drawing_PenLineJoinStyle  )
```

**Description**

Sets the line join style for a pen.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                        | Description                            |
| --------------------------- | -------------------------------- |
| OH_Drawing_Pen              | Pointer to an **OH_Drawing_Pen** object.    |
| OH_Drawing_PenLineJoinStyle | Variable that describes the line join style.|

**Since**

8


### OH_Drawing_PenSetMiterLimit()


```
void OH_Drawing_PenSetMiterLimit (OH_Drawing_Pen * , float miter )
```

**Description**

Sets the stroke miter limit for a polyline drawn by a pen. When the corner type is bevel, a beveled corner is displayed if the miter limit is exceeded, and a mitered corner is displayed if the miter limit is not exceeded.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name           | Description                          |
| -------------- | ------------------------------ |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.  |
| miter          | Variable that describes the miter limit.|

**Since**

8


### OH_Drawing_PenSetWidth()


```
void OH_Drawing_PenSetWidth (OH_Drawing_Pen * , float width )
```

**Description**

Sets the thickness for a pen. This thickness determines the width of the outline of a shape.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name           | Description                        |
| -------------- | ---------------------------- |
| OH_Drawing_Pen | Pointer to an **OH_Drawing_Pen** object.|
| width          | Thickness to set, which is a variable.|

**Since**

8


### OH_Drawing_SetTextStyleBaseLine()


```
void OH_Drawing_SetTextStyleBaseLine (OH_Drawing_TextStyle * , int  )
```

**Description**

Sets the text baseline.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                              |
| -------------------- | ---------------------------------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object.|
| int                  | Text baseline to set. For details, see the enum **OH_Drawing_TextBaseline**.   |

**Since**

8


### OH_Drawing_SetTextStyleColor()


```
void OH_Drawing_SetTextStyleColor (OH_Drawing_TextStyle * , uint32_t  )
```

**Description**

Sets the text color.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                              |
| -------------------- | ---------------------------------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object.|
| uint32_t             | Color to set.                              |

**Since**

8


### OH_Drawing_SetTextStyleDecoration()


```
void OH_Drawing_SetTextStyleDecoration (OH_Drawing_TextStyle * , int  )
```

**Description**

Sets the text decoration.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                              |
| -------------------- | ---------------------------------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object.|
| int                  | Text decoration to set. For details, see the enum **OH_Drawing_TextDecoration**. |

**Since**

8


### OH_Drawing_SetTextStyleDecorationColor()


```
void OH_Drawing_SetTextStyleDecorationColor (OH_Drawing_TextStyle * , uint32_t  )
```

**Description**

Sets the color for the text decoration.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                              |
| -------------------- | ---------------------------------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object.|
| uint32_t             | Color to set.                              |

**Since**

8


### OH_Drawing_SetTextStyleFontFamilies()


```
void OH_Drawing_SetTextStyleFontFamilies (OH_Drawing_TextStyle * , int , const char * fontFamilies[] )
```

**Description**

Sets the font families.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                              |
| -------------------- | ---------------------------------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object.|
| int                  | Number of font families to set.                      |
| fontFamilies         | Pointer to the font families to set.            |

**Since**

8


### OH_Drawing_SetTextStyleFontHeight()


```
void OH_Drawing_SetTextStyleFontHeight (OH_Drawing_TextStyle * , double  )
```

**Description**

Sets the font height.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                              |
| -------------------- | ---------------------------------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object.|
| double               | Font height to set.                          |

**Since**

8


### OH_Drawing_SetTextStyleFontSize()


```
void OH_Drawing_SetTextStyleFontSize (OH_Drawing_TextStyle * , double  )
```

**Description**

Sets the font size.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                              |
| -------------------- | ---------------------------------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object.|
| double               | Font size to set.                              |

**Since**

8


### OH_Drawing_SetTextStyleFontStyle()


```
void OH_Drawing_SetTextStyleFontStyle (OH_Drawing_TextStyle * , int  )
```

**Description**

Sets the font style.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                              |
| -------------------- | ---------------------------------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object.|
| int                  | Font style to set. For details, see the enum **OH_Drawing_FontStyle**.      |

**Since**

8


### OH_Drawing_SetTextStyleFontWeight()


```
void OH_Drawing_SetTextStyleFontWeight (OH_Drawing_TextStyle * , int  )
```

**Description**

Sets the font weight.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                              |
| -------------------- | ---------------------------------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object.|
| int                  | Font weight to set. For details, see the enum **OH_Drawing_FontWeight**.     |

**Since**

8


### OH_Drawing_SetTextStyleLocale()


```
void OH_Drawing_SetTextStyleLocale (OH_Drawing_TextStyle * , const char *  )
```

**Description**

Sets the locale.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                              |
| -------------------- | ---------------------------------- |
| OH_Drawing_TextStyle | Pointer to an **OH_Drawing_TextStyle** object.|
| char                 | Pointer to the locale to set.|

**Since**

8


### OH_Drawing_SetTypographyTextAlign()


```
void OH_Drawing_SetTypographyTextAlign (OH_Drawing_TypographyStyle * , int  )
```

**Description**

Sets the text alignment mode.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                       | Description                                    |
| -------------------------- | ---------------------------------------- |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object.|
| int                        | Text alignment mode to set. For details, see the enum **OH_Drawing_TextAlign**.            |

**Since**

8


### OH_Drawing_SetTypographyTextDirection()


```
void OH_Drawing_SetTypographyTextDirection (OH_Drawing_TypographyStyle * , int  )
```

**Description**

Sets the text direction.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                       | Description                                    |
| -------------------------- | ---------------------------------------- |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object.|
| int                        | Text direction to set. For details, see the enum **OH_Drawing_TextDirection**.        |

**Since**

8


### OH_Drawing_SetTypographyTextMaxLines()


```
void OH_Drawing_SetTypographyTextMaxLines (OH_Drawing_TypographyStyle * , int  )
```

**Description**

Sets the maximum number of lines in the text.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                       | Description                                    |
| -------------------------- | ---------------------------------------- |
| OH_Drawing_TypographyStyle | Pointer to an **OH_Drawing_TypographyStyle** object.|
| int                        | Maximum number of lines to set.                                |

**Since**

8

### OH_Drawing_TypographyGetAlphabeticBaseline()

```
double OH_Drawing_TypographyGetAlphabeticBaseline (OH_Drawing_Typography * )
```

**Description**

Obtains the alphabetic baseline.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                               |
| --------------------- | ----------------------------------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object.|

**Returns**

Returns the alphabetic baseline.

**Since**

9

### OH_Drawing_TypographyGetHeight()

```
double OH_Drawing_TypographyGetHeight (OH_Drawing_Typography * )
```

**Description**

Obtains the height.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                               |
| --------------------- | ----------------------------------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object.|

**Returns**

Returns the height.

**Since**

9

### OH_Drawing_TypographyGetIdeographicBaseline()

```
double OH_Drawing_TypographyGetIdeographicBaseline (OH_Drawing_Typography * )
```

**Description**

Obtains the ideographic baseline.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                               |
| --------------------- | ----------------------------------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object.|

**Returns**

Returns the ideographic baseline.

**Since**

9

### OH_Drawing_TypographyGetLongestLine()

**Description**

Obtains the longest line.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                               |
| --------------------- | ----------------------------------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object.|

**Returns**

Returns the longest line.

**Since**

9

### OH_Drawing_TypographyGetMaxIntrinsicWidth()

```
double OH_Drawing_TypographyGetMaxIntrinsicWidth (OH_Drawing_Typography * )
```

**Description**

Obtains the maximum intrinsic width.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                               |
| --------------------- | ----------------------------------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object.|

**Returns**

Returns the maximum intrinsic width.

**Since**

9

### OH_Drawing_TypographyGetMaxWidth()

```
double OH_Drawing_TypographyGetMaxWidth (OH_Drawing_Typography * )
```

**Description**

Obtains the maximum width.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                               |
| --------------------- | ----------------------------------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object.|

**Returns**

Returns the maximum width.

**Since**

9

### OH_Drawing_TypographyGetMinIntrinsicWidth()

```
double OH_Drawing_TypographyGetMinIntrinsicWidth (OH_Drawing_Typography * )
```

**Description**

Obtains the minimum intrinsic width.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                 | Description                               |
| --------------------- | ----------------------------------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object.|

**Returns**

Returns the minimum intrinsic width.

**Since**

9

### OH_Drawing_TypographyHandlerAddText()


```
void OH_Drawing_TypographyHandlerAddText (OH_Drawing_TypographyCreate * , const char *  )
```

**Description**

Sets the text content.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                        | Description                                     |
| --------------------------- | ----------------------------------------- |
| OH_Drawing_TypographyCreate | Pointer to an **OH_Drawing_TypographyCreate** object.|
| char                        | Pointer to the text content to set.                       |

**Since**

8


### OH_Drawing_TypographyHandlerPopTextStyle()


```
void OH_Drawing_TypographyHandlerPopTextStyle (OH_Drawing_TypographyCreate * )
```

**Description**

Removes the topmost style in the stack, leaving the remaining styles in effect.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                        | Description                                     |
| --------------------------- | ----------------------------------------- |
| OH_Drawing_TypographyCreate | Pointer to an **OH_Drawing_TypographyCreate** object.|

**Since**

8


### OH_Drawing_TypographyHandlerPushTextStyle()


```
void OH_Drawing_TypographyHandlerPushTextStyle (OH_Drawing_TypographyCreate * , OH_Drawing_TextStyle *  )
```

**Description**

Sets the text style.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                        | Description                                     |
| --------------------------- | ----------------------------------------- |
| OH_Drawing_TypographyCreate | Pointer to an **OH_Drawing_TypographyCreate** object.|
| OH_Drawing_TextStyle        | Pointer to an **OH_Drawing_TextStyle** object.       |

**Since**

8


### OH_Drawing_TypographyLayout()


```
void OH_Drawing_TypographyLayout (OH_Drawing_Typography * , double  )
```

**Description**

Lays out the typography.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                  | Description                               |
| --------------------- | ----------------------------------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object.|
| double                | Maximum text width to set.                       |

**Since**

8


### OH_Drawing_TypographyPaint()


```
void OH_Drawing_TypographyPaint (OH_Drawing_Typography * , OH_Drawing_Canvas * , double , double  )
```

**Description**

Paints text on the canvas.

@syscap SystemCapability.Graphic.Graphic2D.NativeDrawing

**Parameters**

| Name                  | Description                               |
| --------------------- | ----------------------------------- |
| OH_Drawing_Typography | Pointer to an **OH_Drawing_Typography** object.|
| OH_Drawing_Canvas     | Pointer to an **OH_Drawing_Canvas** object.    |
| double                | X coordinate.                              |
| double                | Y coordinate.                               |

**Since**

8
