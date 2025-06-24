# Drawing TextBlobs (C/C++)


## When to Use

A TextBlob is a set of texts. Both a single text and a large text block can be drawn by using a TextBlob.

This section focuses on the text drawing effect. In addition to the basic TextBlob drawing, you can add various drawing effects to the text. Common TextBlob drawing scenarios include [text stroke](#text-stroke) and [text gradient](#text-gradient). For more effects, see [Drawing Effects](drawing-effect-overview.md).


## Basic TextBlob Drawing

Use the OH_Drawing_CanvasDrawTextBlob() API to draw a TextBlob. The API accepts four parameters: canvas object, TextBlob object, and X-coordinate and Y-coordinate of the left endpoint of the text baseline.


For details about the canvas object, see [Obtaining a Canvas and Displaying Drawing Results (C/C++)](canvas-get-result-draw-c.md).


A TextBlob object can be created in multiple modes. For details, see [drawing_text_blob.h](../reference/apis-arkgraphics2d/drawing__text__blob_8h.md).


The following uses the OH_Drawing_TextBlobCreateFromString() API as an example to describe how to create a TextBlob. The API accepts the following three parameters:


- Text string to be displayed.

- Pointer to the OH_Drawing_Font font object. OH_Drawing_Font is used to set and obtain font attributes, such as the font size, text style, font alignment mode, font rendering mode, and font stroke mode. For details about the APIs, see [draw_font](../reference/apis-arkgraphics2d/drawing__font_8h.md).

- Text encoding mode.


The following figure shows a simple example.


```c++
// Create a font object.
OH_Drawing_Font *font = OH_Drawing_FontCreate();
// Set the font scale.
OH_Drawing_FontSetTextSize(font, 100);
// Text to be drawn.
const char *str = "Hello world";
// Create a TextBlob object.
OH_Drawing_TextBlob *textBlob =
    OH_Drawing_TextBlobCreateFromString(str, font, OH_Drawing_TextEncoding::TEXT_ENCODING_UTF8);
// Draw a TextBlob.
OH_Drawing_CanvasDrawTextBlob(canvas, textBlob, 200, 800); 
// Release the TextBlob object.
OH_Drawing_TextBlobDestroy(textBlob);
// Release the font object.
OH_Drawing_FontDestroy(font);
```


![Screenshot_20241225164926098](figures/Screenshot_20241225164926098.jpg)


## Text Stroke

You can also use a pen to implement the text stroke effect based on the basic TextBlob drawing. For details about the stroke effect, see [Stroke Effect](basic-drawing-effect-c.md#stroke-effect).

The following figure shows a brief example of text strokes.

```c++
// Create a pen.
OH_Drawing_Pen *pen = OH_Drawing_PenCreate();
// Set the anti-aliasing function.
OH_Drawing_PenSetAntiAlias(pen, true);
// Set the stroke color.
OH_Drawing_PenSetColor(pen, OH_Drawing_ColorSetArgb(0xFF, 0xFF, 0x00, 0x00));
// Set the stroke width.
OH_Drawing_PenSetWidth(pen, 3);
// Set the stroke effect.
OH_Drawing_CanvasAttachPen(canvas, pen);
// Create a font object.
OH_Drawing_Font *font = OH_Drawing_FontCreate();
// Set the font scale.
OH_Drawing_FontSetTextSize(font, 150);
const char *str = "Hello world";
// Create a TextBlob object.
OH_Drawing_TextBlob *textBlob =
    OH_Drawing_TextBlobCreateFromString(str, font, OH_Drawing_TextEncoding::TEXT_ENCODING_UTF8);
// Draw a TextBlob.
OH_Drawing_CanvasDrawTextBlob(canvas, textBlob, 200, 800);
// Remove the stroke effect.
OH_Drawing_CanvasDetachPen(canvas);
// Destroy various objects.
OH_Drawing_TextBlobDestroy(textBlob);
OH_Drawing_FontDestroy(font);
OH_Drawing_PenDestroy(pen);
```

![Screenshot_20241225171259621](figures/Screenshot_20241225171259621.jpg)


## Text Gradient

You can also use a shader to implement the text gradient effect. For details about the shader, see [Shader Effects](complex-drawing-effect-c.md#shader-effects).

The following is a brief example and schematic diagram of adding a linear gradient shader effect to the text:

```c++
// Start point.
OH_Drawing_Point *startPt = OH_Drawing_PointCreate(100, 100);
// End point.
OH_Drawing_Point *endPt = OH_Drawing_PointCreate(900, 900);
// Color array.
uint32_t colors[] = {0xFFFFFF00, 0xFFFF0000, 0xFF0000FF};
// Relative position array
float pos[] = {0.0f, 0.5f, 1.0f};
// Create a linear gradient shader effect.
OH_Drawing_ShaderEffect *colorShaderEffect =
    OH_Drawing_ShaderEffectCreateLinearGradient(startPt, endPt, colors, pos, 3, OH_Drawing_TileMode::CLAMP);
// Create a brush object.
OH_Drawing_Brush *brush = OH_Drawing_BrushCreate();
// Set the shader effect based on the brush.
OH_Drawing_BrushSetShaderEffect(brush, colorShaderEffect);
// Set the brush filling effect.
OH_Drawing_CanvasAttachBrush(canvas, brush);
// Create a font object.
OH_Drawing_Font *font = OH_Drawing_FontCreate();
// Set the font scale.
OH_Drawing_FontSetTextSize(font, 150);
const char *str = "Hello world";
// Create a TextBlob object.
OH_Drawing_TextBlob *textBlob =
    OH_Drawing_TextBlobCreateFromString(str, font, OH_Drawing_TextEncoding::TEXT_ENCODING_UTF8);
// Draw a TextBlob.
OH_Drawing_CanvasDrawTextBlob(canvas, textBlob, 200, 800);
// Cancel the filling effect.
OH_Drawing_CanvasDetachBrush(canvas);
// Destroy various objects.
OH_Drawing_TextBlobDestroy(textBlob);
OH_Drawing_FontDestroy(font);
OH_Drawing_BrushDestroy(brush);
```

![Screenshot_20241225173900576](figures/Screenshot_20241225173900576.jpg)
