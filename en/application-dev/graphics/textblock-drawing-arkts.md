# Drawing TextBlobs (ArkTS)


## When to Use

A TextBlob is a set of texts. Both a single text and a large text block can be drawn by using a TextBlob.


This section focuses on the text drawing effect. In addition to the basic TextBlob drawing, you can add various drawing effects to the text. Common TextBlob drawing scenarios include [text stroke](#text-stroke) and [text gradient](#text-gradient). For more effects, see [Drawing Effects](drawing-effect-overview.md).


## Basic TextBlob Drawing

Canvas uses drawTextBlob() to draw TextBlobs. The function takes three arguments: a TextBlob object, and the x-coordinate and y-coordinate of the left endpoint of the text baseline.


For details about the canvas object, see [Obtaining a Canvas and Displaying Drawing Results (ArkTS)](canvas-get-result-draw-arkts.md).


A TextBlob object can be created in multiple ways. For details about how to create a TextBlob and how to use the API, see [TextBlob](../reference/apis-arkgraphics2d/js-apis-graphics-drawing.md#textblob).


The following uses the makeFromString() API as an example to describe how to create a TextBlob. The API accepts the following three parameters:


- Character string text to be displayed.

- Font object. font is used to set and obtain font attributes, such as the font size, text style, font alignment mode, font rendering mode, and font stroke mode. For details about the APIs, see [Font](../reference/apis-arkgraphics2d/js-apis-graphics-drawing.md#font).

- Text encoding mode. Currently, the following text encoding modes are supported:
  - TEXT_ENCODING_UTF8: One byte is used to indicate UTF-8 or ASCII characters.
  - TEXT_ENCODING_UTF16: Two bytes are used to indicate most Unicode characters.
  - TEXT_ENCODING_UTF32: Four bytes are used to indicate all Unicode characters.
  - TEXT_ENCODING_GLYPH_ID: Two bytes are used to indicate the glyph index.


The sample code and effect drawing of the basic effect are as follows:


```ts
// Create a font object.
const font = new drawing.Font();
// Set the font scale.
font.setSize(100);
// Create a TextBlob object.
const textBlob = drawing.TextBlob.makeFromString('Hello world', font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
// Draw a TextBlob.
canvas.drawTextBlob(textBlob, 200, 300);
```


![Screenshot_20241225151030139](figures/Screenshot_20241225151030139.jpg)


## Text Stroke

You can also use a pen to implement the text stroke effect based on the basic TextBlob drawing. For details about the stroke effect, see [Stroke Effects](basic-drawing-effect-arkts.md#stroke-effects).

The following figure shows a brief example of text strokes.

```ts
// Create a pen.
let pen = new drawing.Pen();
// Set the anti-aliasing function.
pen.setAntiAlias(true);
// Set the stroke width.
pen.setStrokeWidth(3.0);
// Set the stroke color.
pen.setColor(0xFF, 0xFF,  0x00, 0x00);
// Create a font object.
const font = new drawing.Font();
// Set the font scale.
font.setSize(100);
// Add the stroke effect.
canvas.attachPen(pen);
// Create a TextBlob object.
const textBlob = drawing.TextBlob.makeFromString('Hello world', font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
// Draw a TextBlob.
canvas.drawTextBlob(textBlob, 200, 300);
// Remove the stroke effect.
canvas.detachPen();
```

![Screenshot_20241225152446749](figures/Screenshot_20241225152446749.jpg)


## Text Gradient

You can also use a shader to implement the text gradient effect. For details about the shader, see [Shader Effects](complex-drawing-effect-arkts.md#shader-effects).

The following is a brief example and schematic diagram of adding a linear gradient shader effect to the text:

```ts
let startPt: common2D.Point = { x: 100, y: 100 };
let endPt: common2D.Point = { x: 900, y: 900 };
let colors = [0xFFFFFF00, 0xFFFF0000, 0xFF0000FF];
// Create a linear gradient shader.
let shaderEffect = drawing.ShaderEffect.createLinearGradient(startPt, endPt, colors, drawing.TileMode.CLAMP);
// Create a brush.
let brush = new drawing.Brush();
// Set the shader.
brush.setShaderEffect(shaderEffect);
// Add the brush filling effect.
canvas.attachBrush(brush);
// Create a font.
const font = new drawing.Font();
// Set the font scale.
font.setSize(200);
// Create a TextBlob.
const textBlob = drawing.TextBlob.makeFromString('Hello world', font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
// Draw a TextBlob.
canvas.drawTextBlob(textBlob, 100, 300);
// Remove the filling effect.
canvas.detachBrush();
```

![Screenshot_20241225155707415](figures/Screenshot_20241225155707415.jpg)
