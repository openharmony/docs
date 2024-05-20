# @ohos.graphics.drawing (Drawing)

The Drawing module provides basic drawing capabilities, such as drawing rectangles, circles, points, straight lines, custom paths, and fonts.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This module uses the physical pixel unit, px.

## Modules to Import

```ts
import drawing from '@ohos.graphics.drawing'
```

## BlendMode

Enumerates the blend modes. In blend mode, each operation generates a new color from two colors (source color and target color). These operations are the same on the four channels (red, green, blue, and alpha). The operations for the alpha channel are used as examples.

For brevity, the following abbreviations are used:

**s**: source. **d**: destination. **sa**: source alpha. **da**: destination alpha.

The following abbreviations are used in the calculation result:

**r**: The calculation methods of the four channels are the same. **ra**: Only the alpha channel is manipulated. **rc**: The other three color channels are manipulated.

**System capability**: SystemCapability.Graphics.Drawing

| Name       | Value  | Description                                                        |
| ----------- | ---- | ------------------------------------------------------------ |
| CLEAR       | 0    | Clear mode. r = 0.                                           |
| SRC         | 1    | r = s (The four channels of **result** are equal to the four channels of **source**, that is, the result is equal to the source.)|
| DST         | 2    | r = d (The four channels of **result** are equal to the four channels of **destination**, that is, the result is equal to the destination.)|
| SRC_OVER    | 3    | r = s + (1 - sa) * d                                         |
| DST_OVER    | 4    | r = d + (1 - da) * s                                         |
| SRC_IN      | 5    | r = s * da                                                   |
| DST_IN      | 6    | r = d * sa                                                   |
| SRC_OUT     | 7    | r = s * (1 - da)                                             |
| DST_OUT     | 8    | r = d * (1 - sa)                                             |
| SRC_ATOP    | 9    | r = s * da + d * (1 - sa)                                    |
| DST_ATOP    | 10   | r = d * sa + s * (1 - da)                                    |
| XOR         | 11   | r = s * (1 - da) + d * (1 - sa)                              |
| PLUS        | 12   | r = min(s + d, 1)                                            |
| MODULATE    | 13   | r = s * d                                                    |
| SCREEN      | 14   | Screen mode. r = s + d - s * d                                  |
| OVERLAY     | 15   | Overlay mode.                                                    |
| DARKEN      | 16   | Darken mode. rc = s + d - max(s * da, d * sa), ra = s + (1 - sa) * d |
| LIGHTEN     | 17   | Lighten mode. rc = rc = s + d - min(s * da, d * sa), ra = s + (1 - sa) * d |
| COLOR_DODGE | 18   | Color dodge mode.                                                |
| COLOR_BURN  | 19   | Color burn mode.                                                |
| HARD_LIGHT  | 20   | Hard light mode.                                                    |
| SOFT_LIGHT  | 21   | Soft light mode.                                                    |
| DIFFERENCE  | 22   | Difference mode. rc = s + d - 2 * (min(s * da, d * sa)), ra = s + (1 - sa) * d |
| EXCLUSION   | 23   | Exclusion mode. rc = s + d - two(s * d), ra = s + (1 - sa) * d     |
| MULTIPLY    | 24   | Multiply mode. r = s * (1 - da) + d * (1 - sa) + s * d            |
| HUE         | 25   | Hue mode.                                                    |
| SATURATION  | 26   | Saturation mode.                                                  |
| COLOR       | 27   | Color mode.                                                    |
| LUMINOSITY  | 28   | Luminosity mode.                                                    |

## Path

A compound geometric path consisting of line segments, arcs, quadratic Bezier curves, and cubic Bezier curves.

### moveTo

moveTo(x: number, y: number) : void

Sets the start point of a path.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type  | Mandatory| Description                   |
| ------ | ------ | ---- | ----------------------- |
| x      | number | Yes  | X coordinate of the start point. The value is a floating point number.|
| y      | number | Yes  | Y coordinate of the start point. The value is a floating point number.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let path = new drawing.Path();
path.moveTo(10,10);
```

### lineTo

lineTo(x: number, y: number) : void

Draws a line segment from the last point of a path to the target point.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type  | Mandatory| Description                   |
| ------ | ------ | ---- | ----------------------- |
| x      | number | Yes  | X coordinate of the target point. The value is a floating point number.|
| y      | number | Yes  | Y coordinate of the target point. The value is a floating point number.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let path = new drawing.Path();
path.moveTo(10,10);
path.lineTo(10, 15);
```

### arcTo

arcTo(x1: number, y1: number, x2: number, y2: number, startDeg: number, sweepDeg: number): void

Draws an arc to a path. This is done by using angle arc mode. In this mode, a rectangle that encloses an ellipse is specified first, and then a start angle and a sweep angle are specified. The arc is a portion of the ellipse defined by the start angle and the sweep angle. By default, a line segment from the last point of the path to the start point of the arc is also added.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type  | Mandatory| Description                      |
| -------- | ------ | ---- | -------------------------- |
| x1       | number | Yes  | X coordinate of the upper left corner of the rectangle. The value is a floating point number.|
| y1       | number | Yes  | Y coordinate of the upper left corner of the rectangle. The value is a floating point number.|
| x2       | number | Yes  | X coordinate of the lower right corner of the rectangle. The value is a floating point number.|
| y2       | number | Yes  | Y coordinate of the lower right corner of the rectangle. The value is a floating point number.|
| startDeg | number | Yes  | Start angle, in degrees. The value is a floating point number.|
| sweepDeg | number | Yes  | Sweep degree. The value is a floating point number.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let path = new drawing.Path();
path.moveTo(10,10);
path.arcTo(10, 15, 10, 10, 10, 10);
```

### quadTo

quadTo(ctrlX: number, ctrlY: number, endX: number, endY: number): void

Draws a quadratic Bezier curve from the last point of a path to the target point.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type  | Mandatory| Description                 |
| ------ | ------ | ---- | --------------------- |
| ctrlX  | number | Yes  | X coordinate of the control point. The value is a floating point number.|
| ctrlY  | number | Yes  | Y coordinate of the control point. The value is a floating point number.|
| endX   | number | Yes  | X coordinate of the target point. The value is a floating point number.|
| endY   | number | Yes  | Y coordinate of the target point. The value is a floating point number.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let path = new drawing.Path();
path.moveTo(10,10);
path.quadTo(10, 15, 10, 10);
```

### cubicTo

cubicTo(ctrlX1: number, ctrlY1: number, ctrlX2: number, ctrlY2: number, endX: number, endY: number): void

Draws a cubic Bezier curve from the last point of a path to the target point.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type  | Mandatory| Description                       |
| ------ | ------ | ---- | --------------------------- |
| ctrlX1 | number | Yes  | X coordinate of the first control point. The value is a floating point number.|
| ctrlY1 | number | Yes  | Y coordinate of the first control point. The value is a floating point number.|
| ctrlX2 | number | Yes  | X coordinate of the second control point. The value is a floating point number.|
| ctrlY2 | number | Yes  | Y coordinate of the second control point. The value is a floating point number.|
| endX   | number | Yes  | X coordinate of the target point. The value is a floating point number.|
| endY   | number | Yes  | Y coordinate of the target point. The value is a floating point number.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let path = new drawing.Path();
path.moveTo(10,10);
path.cubicTo(10, 10, 10, 10, 15, 15);
```

### close

close(): void

Draws a line segment from the current point to the start point of a path.

**System capability**: SystemCapability.Graphics.Drawing

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let path = new drawing.Path();
path.moveTo(10,10);
path.cubicTo(10, 10, 10, 10, 15, 15);
path.close();
```

### reset

reset(): void

Resets path data.

**System capability**: SystemCapability.Graphics.Drawing

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let path = new drawing.Path();
path.moveTo(10,10);
path.cubicTo(10, 10, 10, 10, 15, 15);
path.reset();
```

## Canvas

A carrier that carries the drawn content and drawing status.

### constructor

constructor(pixelmap: image.PixelMap)

A constructor used to create a **Canvas** object.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                                        | Mandatory| Description          |
| -------- | -------------------------------------------- | ---- | -------------- |
| pixelmap | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | Yes  | Pixel map used to create the object.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
import image from '@ohos.multimedia.image';
const color = new ArrayBuffer(96);
let opts : image.InitializationOptions = {
  editable: true,
  pixelFormat: 3,
  size: {
    height: 4,
    width: 6
  }
}
image.createPixelMap(color, opts).then((pixelMap) => {
  const canvas = new drawing.Canvas(pixelMap);
})
```

### drawRect

drawRect(rect: common2D.Rect): void

Draws a rectangle. By default, black is used for filling.

> **NOTE**
>
> If the coordinates of the upper left corner point are greater than those of the lower right corner point, a rectangle is drawn. If the upper left corner and lower right corner are on the same x-axis or y-axis, a line segment is drawn. If the coordinates of the upper left corner point are the same as those of the lower right corner point, nothing is drawn.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                                              | Mandatory| Description          |
| ------ | -------------------------------------------------- | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Rectangle to draw.|

**Example**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
import common2D from "@ohos.graphics.common2D"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const pen = new drawing.Pen();
    pen.setStrokeWidth(5);
    pen.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachPen(pen);
    canvas.drawRect({ left : 0, right : 0, top : 10, bottom : 10 });
    canvas.detachPen();
  }
}
```

### drawCircle

drawCircle(x: number, y: number, radius: number): void

Draws a circle. If the radius is less than or equal to zero, nothing is drawn. By default, black is used for filling.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type  | Mandatory| Description               |
| ------ | ------ | ---- | ------------------- |
| x      | number | Yes  | X coordinate of the center of the circle. The value is a floating point number.|
| y      | number | Yes  | Y coordinate of the center of the circle. The value is a floating point number.|
| radius | number | Yes  | Radius of the circle. The value is a floating point number.|

**Example**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const pen = new drawing.Pen();
    pen.setStrokeWidth(5);
    pen.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachPen(pen);
    canvas.drawCircle(10, 10, 2);
    canvas.detachPen();
  }
}
```

### drawImage

drawImage(pixelmap: image.PixelMap, left: number, top: number): void

Draws an image. The coordinates of the upper left corner of the image are (left, top).

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                                        | Mandatory| Description                           |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| pixelmap | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | Yes  | Pixel map of the image.                 |
| left     | number                                       | Yes  | X coordinate of the upper left corner of the image. The value is a floating point number.|
| top      | number                                       | Yes  | Y coordinate of the upper left corner of the image. The value is a floating point number.|

**Example**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import image from "@ohos.multimedia.image"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  pixelMap: image.PixelMap | null = null;

  async draw(context : DrawContext) {
    const canvas = context.canvas;
    if (this.pixelMap != null) {
      canvas.drawImage(this.pixelMap, 0, 0);
    }
  }
}
```

### drawColor

drawColor(color: common2D.Color, blendMode?: BlendMode): void

Draws the background color.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name   | Type                                                | Mandatory| Description                            |
| --------- | ---------------------------------------------------- | ---- | -------------------------------- |
| color     | [common2D.Color](js-apis-graphics-common2D.md#color) | Yes  | Color. The value is an integer.                  |
| blendMode | [BlendMode](#blendmode)                              | No  | Blend mode. The default mode is **SRC_OVER**.|

**Example**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
import common2D from "@ohos.graphics.common2D"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    let color: common2D.Color = {
      alpha : 255,
      red: 0,
      green: 10,
      blue: 10
    }
    canvas.drawColor(color, drawing.BlendMode.CLEAR);
  }
}
```

### drawPoint

drawPoint(x: number, y: number): void

Draws a point.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type  | Mandatory| Description               |
| ------ | ------ | ---- | ------------------- |
| x      | number | Yes  | X coordinate of the point. The value is a floating point number.|
| y      | number | Yes  | Y coordinate of the point. The value is a floating point number.|

**Example**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const pen = new drawing.Pen();
    pen.setStrokeWidth(5);
    pen.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachPen(pen);
    canvas.drawPoint(10, 10);
    canvas.detachPen();
  }
}
```

### drawPath

drawPath(path: Path): void

Draws a custom path, which contains a set of path outlines. Each path outline can be open or closed.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type         | Mandatory| Description              |
| ------ | ------------- | ---- | ------------------ |
| path   | [Path](#path) | Yes  | **Path** object to draw.|

**Example**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const pen = new drawing.Pen();
    pen.setStrokeWidth(5);
    pen.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    let path = new drawing.Path();
    path.moveTo(10,10);
    path.cubicTo(10, 10, 10, 10, 15, 15);
    path.close();
    canvas.attachPen(pen);
    canvas.drawPath(path);
    canvas.detachPen();
  }
}
```

### drawLine

drawLine(x0: number, y0: number, x1: number, y1: number): void

Draws a line segment from the start point to the end point. If the coordinates of the start point are the same as those of the end point, nothing is drawn.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type  | Mandatory| Description                   |
| ------ | ------ | ---- | ----------------------- |
| x0     | number | Yes  | X coordinate of the start point of the line segment. The value is a floating point number.|
| y0     | number | Yes  | Y coordinate of the start point of the line segment. The value is a floating point number.|
| x1     | number | Yes  | X coordinate of the end point of the line segment. The value is a floating point number.|
| y1     | number | Yes  | Y coordinate of the end point of the line segment. The value is a floating point number.|

**Example**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const pen = new drawing.Pen();
    pen.setStrokeWidth(5);
    pen.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachPen(pen);
    canvas.drawLine(0, 0, 20, 20);
    canvas.detachPen();
  }
}
```

### drawTextBlob

drawTextBlob(blob: TextBlob, x: number, y: number): void

Draws a text blob.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                 | Mandatory| Description                                      |
| ------ | --------------------- | ---- | ------------------------------------------ |
| blob   | [TextBlob](#textblob) | Yes  | **TextBlob** object.                            |
| x      | number                | Yes  | X coordinate of the left point (red point in the figure below) of the text baseline (blue line in the figure below). The value is a floating point number.|
| y      | number                | Yes  | Y coordinate of the left point (red point in the figure below) of the text baseline (blue line in the figure below). The value is a floating point number.|

![image_Text_Blob.png](figures/image_Text_Blob.png)

**Example**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const brush = new drawing.Brush();
    brush.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    const font = new drawing.Font();
    font.setSize(20);
    const textBlob = drawing.TextBlob.makeFromString("Hello, drawing", font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
    canvas.attachBrush(brush);
    canvas.drawTextBlob(textBlob, 20, 20);
    canvas.detachBrush();
  }
}
```

### attachPen

attachPen(pen: Pen): void

Attaches a pen to a canvas so that the canvas can use the style and color of the pen to outline a shape.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type       | Mandatory| Description      |
| ------ | ----------- | ---- | ---------- |
| pen    | [Pen](#pen) | Yes  | **Pen** object.|

**Example**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const pen = new drawing.Pen();
    pen.setStrokeWidth(5);
    pen.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachPen(pen);
    canvas.drawRect({ left : 0, right : 0, top : 10, bottom : 10 });
    canvas.detachPen();
  }
}
```

### attachBrush

attachBrush(brush: Brush): void

Attaches a brush to a canvas so that the canvas can use the style and color of the brush to fill in a shape.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type           | Mandatory| Description      |
| ------ | --------------- | ---- | ---------- |
| brush  | [Brush](#brush) | Yes  | **Brush** object.|

**Example**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const brush = new drawing.Brush();
    brush.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachBrush(brush);
    canvas.drawRect({ left : 0, right : 0, top : 10, bottom : 10 });
    canvas.detachBrush();
  }
}
```

### detachPen

detachPen(): void

Detaches the pen from a canvas so that the canvas can no longer use the style and color of the pen to outline a shape.

**System capability**: SystemCapability.Graphics.Drawing

**Example**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const pen = new drawing.Pen();
    pen.setStrokeWidth(5);
    pen.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachPen(pen);
    canvas.drawRect({ left : 0, right : 0, top : 10, bottom : 10 });
    canvas.detachPen();
  }
}
```

### detachBrush

detachBrush(): void

Detaches the brush from a canvas so that the canvas can no longer use the style and color of the brush to fill in a shape.

**System capability**: SystemCapability.Graphics.Drawing

**Example**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const brush = new drawing.Brush();
    brush.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachBrush(brush);
    canvas.drawRect({ left : 0, right : 0, top : 10, bottom : 10 });
    canvas.detachBrush();
  }
}
```

## TextBlobRunBuffer

Describes a series of consecutive glyphs with the same attributes in a text blob.

**System capability**: SystemCapability.Graphics.Drawing

| Name     | Type  | Readable| Writable| Description                     |
| --------- | ------ | ---- | ---- | ------------------------- |
| glyph     | number | Yes  | Yes  | Index of the glyph. The value is an integer. If a floating point number is passed in, the value is rounded down.|
| positionX | number | Yes  | Yes  | X coordinate of the start point of the text blob. The value is a floating point number.|
| positionY | number | Yes  | Yes  | Y coordinate of the start point of the text blob. The value is a floating point number.|

## TextEncoding

Enumerates the text encoding types.

**System capability**: SystemCapability.Graphics.Drawing

| Name                  | Value  | Description                          |
| ---------------------- | ---- | ------------------------------ |
| TEXT_ENCODING_UTF8     | 0    | One byte is used to indicate UTF-8 or ASCII characters. |
| TEXT_ENCODING_UTF16    | 1    | Two bytes are used to indicate most Unicode characters.|
| TEXT_ENCODING_UTF32    | 2    | Four bytes are used to indicate all Unicode characters.  |
| TEXT_ENCODING_GLYPH_ID | 3    | Two bytes are used to indicate the glyph index.  |

## TextBlob

Defines a block consisting of one or more characters with the same font.

### makeFromString

static makeFromString(text: string, font: Font, encoding?: TextEncoding): TextBlob

Converts a value of the string type into a **TextBlob** object.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                         | Mandatory| Description                                  |
| -------- | ----------------------------- | ---- | -------------------------------------- |
| text     | string                        | Yes  | Content to be used for drawing the text blob.                  |
| font     | [Font](#font)                 | Yes  | Text size, font, and text scale.          |
| encoding | [TextEncoding](#textencoding) | No  | Encoding type. The default value is **TEXT_ENCODING_UTF8**.|

**Return value**

| Type                 | Description          |
| --------------------- | -------------- |
| [TextBlob](#textblob) | **TextBlob** object.|

**Example**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const brush = new drawing.Brush();
    brush.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    const font = new drawing.Font();
    font.setSize(20);
    const textBlob = drawing.TextBlob.makeFromString("drawing", font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
    canvas.attachBrush(brush);
    canvas.drawTextBlob(textBlob, 20, 20);
    canvas.detachBrush();
  }
}
```

### makeFromRunBuffer

static makeFromRunBuffer(pos: Array\<TextBlobRunBuffer>, font: Font, bounds?: common2D.Rect): TextBlob

Creates a **Textblob** object based on the RunBuffer information.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                                              | Mandatory| Description                          |
| ------ | -------------------------------------------------- | ---- | ------------------------------ |
| pos    | Array\<[TextBlobRunBuffer](#textblobrunbuffer)>    | Yes  | **TextBlobRunBuffer** array.       |
| font   | [Font](#font)                                      | Yes  | Text size, font, and text scale.  |
| bounds | [common2D.Rect](js-apis-graphics-common2D.md#rect) | No  | Bounding box. If this parameter is not set, there is no bounding box.|

**Return value**

| Type                 | Description          |
| --------------------- | -------------- |
| [TextBlob](#textblob) | **TextBlob** object.|

**Example**

```ts
import { RenderNode, DrawContext } from "@ohos.arkui.node"
import drawing from "@ohos.graphics.drawing"
import common2D from "@ohos.graphics.common2D"
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const font = new drawing.Font();
    font.setSize(20);
    let runBuffer : Array<drawing.TextBlobRunBuffer> = [
      { glyph: 65, positionX: 0, positionY: 0 },
      { glyph: 227, positionX: 14.9, positionY: 0 },
      { glyph: 283, positionX: 25.84, positionY: 0 },
      { glyph: 283, positionX: 30.62, positionY: 0 },
      { glyph: 299, positionX: 35.4, positionY: 0}
    ];
    const textBlob = drawing.TextBlob.makeFromRunBuffer(runBuffer, font, null);
    const brush = new drawing.Brush();
    brush.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachBrush(brush);
    canvas.drawTextBlob(textBlob, 20, 20);
    canvas.detachBrush();
  }
}
```

### bounds

bounds(): common2D.Rect

Obtains the rectangular bounding box of the text blob.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type                                              | Description                  |
| -------------------------------------------------- | ---------------------- |
| [common2D.Rect](js-apis-graphics-common2D.md#rect) | Rectangular bounding box.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
import common2D from "@ohos.graphics.common2D"
const font = new drawing.Font();
font.setSize(20);
const textBlob = drawing.TextBlob.makeFromString("drawing", font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
textBlob.bounds();
```

## Typeface

Describes the typeface such as SimSun and Kaiti.

### getFamilyName

getFamilyName(): string

Obtains the name of the typeface, that is, the name of the font family.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| string | Typeface name.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
const font = new drawing.Font();
let typeface = font.getTypeface();
typeface.getFamilyName();
```

## Font

Describes the attributes, such as the size, used for drawing text.

### enableSubpixel

enableSubpixel(isSubpixel: boolean): void

Enables subpixel font rendering.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name    | Type   | Mandatory| Description                                                        |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| isSubpixel | boolean | Yes  | Whether to enable subpixel font rendering. The value **true** means to enable subpixel font rendering, and **false** means the opposite.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
font.enableSubpixel(true);
```

### enableEmbolden

enableEmbolden(isEmbolden: boolean): void

Enables emboldened fonts.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name    | Type   | Mandatory| Description                                                 |
| ---------- | ------- | ---- | ----------------------------------------------------- |
| isEmbolden | boolean | Yes  | Whether to enable emboldened fonts. The value **true** means to enable emboldened fonts, and **false** means the opposite.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
font.enableEmbolden(true);
```

### enableLinearMetrics

enableLinearMetrics(isLinearMetrics: boolean): void

Enables linear font scaling.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name         | Type   | Mandatory| Description                                                       |
| --------------- | ------- | ---- | ----------------------------------------------------------- |
| isLinearMetrics | boolean | Yes  | Whether to enable linear font scaling. The value **true** means to enable linear font scaling, and **false** means the opposite.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
font.enableLinearMetrics(true);
```

### setSize

setSize(textSize: number): void

Sets the text size. A value less than or equal to 0 is invalid.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type  | Mandatory| Description            |
| -------- | ------ | ---- | ---------------- |
| textSize | number | Yes  | Text size. The value is a floating point number.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
font.setSize(5);
```

### getSize

getSize(): number

Obtains the text size.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type  | Description            |
| ------ | ---------------- |
| number | Text size. The value is a floating point number.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
font.setSize(5);
font.getSize();
```

### setTypeface

setTypeface(typeface: Typeface): void

Sets the typeface.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                 | Mandatory| Description  |
| -------- | --------------------- | ---- | ------ |
| typeface | [Typeface](#typeface) | Yes  | **Typeface** object.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
font.setTypeface(new drawing.Typeface());
```

### getTypeface

getTypeface(): Typeface

Obtains the typeface.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type                 | Description  |
| --------------------- | ------ |
| [Typeface](#typeface) | **Typeface** object.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
font.getTypeface();
```

### getMetrics

getMetrics(): FontMetrics

Obtains the font metrics of the typeface.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type                       | Description             |
| --------------------------- | ----------------- |
| [FontMetrics](#fontmetrics) | Font metrics.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
let metrics = font.getMetrics();
```

### measureText

measureText(text: string, encoding: TextEncoding): number

Measures the text width.

> **NOTE**
>
> This API is used to measure the text width of the original string. To measure the text width after typesetting, call [measure.measureText](../apis-arkui/js-apis-measure.md#measuremeasuretext).

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                         | Mandatory| Description      |
| -------- | ----------------------------- | ---- | ---------- |
| text     | string                        | Yes  | Text content.|
| encoding | [TextEncoding](#textencoding) | Yes  | Encoding format.|

**Return value**

| Type  | Description            |
| ------ | ---------------- |
| number | Width of the text. The value is a floating point number.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let font = new drawing.Font();
font.measureText("drawing", drawing.TextEncoding.TEXT_ENCODING_UTF8);
```

## FontMetrics

Describes the attributes that describe the font size and layout. A typeface has similar font metrics.

**System capability**: SystemCapability.Graphics.Drawing

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| top     | number | Yes  | Yes  | Maximum distance from the baseline to the highest coordinate of the text. The value is a floating point number.                        |
| ascent  | number | Yes  | Yes  | Distance from the baseline to the highest coordinate of the text. The value is a floating point number.                            |
| descent | number | Yes  | Yes  | Distance from the baseline to the lowest coordinate of the text. The value is a floating point number.                            |
| bottom  | number | Yes  | Yes  | Maximum distance from the baseline to the lowest coordinate of the text. The value is a floating point number.                        |
| leading | number | Yes  | Yes  | Interline spacing, that is, the distance from the descent of one line of text to the ascent of the next line. The value is a floating point number.|

## ColorFilter

Defines a color filter.

### createBlendModeColorFilter

createBlendModeColorFilter(color: common2D.Color, mode: BlendMode) : ColorFilter

Creates a **ColorFilter** object with a given color and blend mode.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                                                | Mandatory| Description            |
| ------ | ---------------------------------------------------- | ---- | ---------------- |
| color  | [common2D.Color](js-apis-graphics-common2D.md#color) | Yes  | Color in ARGB format.|
| mode   | [BlendMode](#blendmode)                              | Yes  | Blend mode.|

**Return value**

| Type                       | Description              |
| --------------------------- | ------------------ |
| [ColorFilter](#colorfilter) | **ColorFilter** object created.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
import common2D from "@ohos.graphics.common2D"
const color : common2D.Color = { alpha: 255, red: 255, green: 0, blue: 0 };
let colorFilter = drawing.ColorFilter.createBlendModeColorFilter(color, drawing.BlendMode.SRC);
```

### createComposeColorFilter

createComposeColorFilter(outer: ColorFilter, inner: ColorFilter) : ColorFilter

Creates a **ColorFilter** object by combining another two color filters.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                       | Mandatory| Description                            |
| ------ | --------------------------- | ---- | -------------------------------- |
| outer  | [ColorFilter](#colorfilter) | Yes  | Color filter that takes effect later in the new filter.|
| inner  | [ColorFilter](#colorfilter) | Yes  | Color filter that takes effect first in the new filter.|

**Return value**

| Type                       | Description              |
| --------------------------- | ------------------ |
| [ColorFilter](#colorfilter) | **ColorFilter** object created.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
import common2D from "@ohos.graphics.common2D"
const color : common2D.Color = { alpha: 255, red: 255, green: 0, blue: 0 };
let colorFilter1 = drawing.ColorFilter.createBlendModeColorFilter(color, drawing.BlendMode.SRC);
let colorFilter2 = drawing.ColorFilter.createBlendModeColorFilter(color, drawing.BlendMode.DST);
let colorFilter = drawing.ColorFilter.createComposeColorFilter(colorFilter1, colorFilter2);
```

### createLinearToSRGBGamma

createLinearToSRGBGamma() : ColorFilter

Creates a **ColorFilter** object that applies the sRGB gamma curve to the RGB channels.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type                       | Description              |
| --------------------------- | ------------------ |
| [ColorFilter](#colorfilter) | **ColorFilter** object created.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let colorFilter = drawing.ColorFilter.createLinearToSRGBGamma();
```

### createSRGBGammaToLinear

createSRGBGammaToLinear() : ColorFilter

Creates a **ColorFilter** object that applies the RGB channels to the sRGB gamma curve.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type                       | Description              |
| --------------------------- | ------------------ |
| [ColorFilter](#colorfilter) | **ColorFilter** object created.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let colorFilter = drawing.ColorFilter.createSRGBGammaToLinear();
```

### createLumaColorFilter

createLumaColorFilter() : ColorFilter

Creates a **ColorFilter** object that multiplies the luma into the alpha channel.

**System capability**: SystemCapability.Graphics.Drawing

**Return value**

| Type                       | Description              |
| --------------------------- | ------------------ |
| [ColorFilter](#colorfilter) | **ColorFilter** object created.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
let colorFilter = drawing.ColorFilter.createLumaColorFilter();
```

## Pen

Defines a pen, which is used to describe the style and color to outline a shape.

### setColor

setColor(color: common2D.Color) : void

Sets a color for this pen.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                                                | Mandatory| Description            |
| ------ | ---------------------------------------------------- | ---- | ---------------- |
| color  | [common2D.Color](js-apis-graphics-common2D.md#color) | Yes  | Color in ARGB format.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
import common2D from "@ohos.graphics.common2D"
const color : common2D.Color = { alpha: 255, red: 255, green: 0, blue: 0 };
const pen = new drawing.Pen();
pen.setColor(color);
```

### setStrokeWidth

setStrokeWidth(width: number) : void

Sets a stroke width for this pen.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| width  | number | Yes  | Stroke width. The value is a floating point number. If a value less than 1 is passed in, the value **1** is used.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
const pen = new drawing.Pen();
pen.setStrokeWidth(5);
```

### setAntiAlias

setAntiAlias(aa: boolean) : void

Enables anti-aliasing for this pen. Anti-aliasing makes the edges of the content smoother.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description                                             |
| ------ | ------- | ---- | ------------------------------------------------- |
| aa     | boolean | Yes  | Whether to enable anti-aliasing. The value **true** means to enable anti-aliasing, and **false** means the opposite.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
const pen = new drawing.Pen();
pen.setAntiAlias(true);
```

### setAlpha

setAlpha(alpha: number) : void

Sets an alpha value for this pen.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| alpha  | number | Yes  | Alpha value. The value is an integer in the range [0, 255]. If a floating point number is passed in, the value is rounded down.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
const pen = new drawing.Pen();
pen.setAlpha(128);
```

### setColorFilter

setColorFilter(filter: ColorFilter) : void

Sets a color filter for this pen.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                       | Mandatory| Description        |
| ------ | --------------------------- | ---- | ------------ |
| filter | [ColorFilter](#colorfilter) | Yes  | Color filter.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
const pen = new drawing.Pen();
let colorFilter = drawing.ColorFilter.createLinearToSRGBGamma();
pen.setColorFilter(colorFilter);
```

### setBlendMode

setBlendMode(mode: BlendMode) : void

Sets a blend mode for this pen.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                   | Mandatory| Description            |
| ------ | ----------------------- | ---- | ---------------- |
| mode   | [BlendMode](#blendmode) | Yes  | Blend mode.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
const pen = new drawing.Pen();
pen.setBlendMode(drawing.BlendMode.SRC);
```

### setDither

setDither(dither: boolean) : void

Enables dithering for this pen. Dithering make the drawn color more realistic.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description                                                     |
| ------ | ------- | ---- | --------------------------------------------------------- |
| dither | boolean | Yes  | Whether to enable dithering. The value **true** means to enable dithering, and **false** means the opposite.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
const pen = new drawing.Pen();
pen.setDither(true);
```

## Brush

Defines a brush, which is used to describe the style and color to fill in a shape.

### setColor

setColor(color: common2D.Color) : void

Sets a color for this brush.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                                                | Mandatory| Description            |
| ------ | ---------------------------------------------------- | ---- | ---------------- |
| color  | [common2D.Color](js-apis-graphics-common2D.md#color) | Yes  | Color in ARGB format.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
import common2D from "@ohos.graphics.common2D"
const color : common2D.Color = { alpha: 255, red: 255, green: 0, blue: 0 };
const brush = new drawing.Brush();
brush.setColor(color);
```

### setAntiAlias

setAntiAlias(aa: boolean) : void

Enables anti-aliasing for this brush. Anti-aliasing makes the edges of the content smoother.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description                                             |
| ------ | ------- | ---- | ------------------------------------------------- |
| aa     | boolean | Yes  | Whether to enable anti-aliasing. The value **true** means to enable anti-aliasing, and **false** means the opposite.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
const brush = new drawing.Brush();
brush.setAntiAlias(true);
```

### setAlpha

setAlpha(alpha: number) : void

Sets an alpha value for this brush.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| alpha  | number | Yes  | Alpha value. The value is an integer in the range [0, 255]. If a floating point number is passed in, the value is rounded down.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
const brush = new drawing.Brush();
brush.setAlpha(128);
```

### setColorFilter

setColorFilter(filter: ColorFilter) : void

Sets a color filter for this brush.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                       | Mandatory| Description        |
| ------ | --------------------------- | ---- | ------------ |
| filter | [ColorFilter](#colorfilter) | Yes  | Color filter.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
const brush = new drawing.Brush();
let colorFilter = drawing.ColorFilter.createLinearToSRGBGamma();
brush.setColorFilter(colorFilter);
```

### setBlendMode

setBlendMode(mode: BlendMode) : void

Sets a blend mode for this brush.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                   | Mandatory| Description            |
| ------ | ----------------------- | ---- | ---------------- |
| mode   | [BlendMode](#blendmode) | Yes  | Blend mode.|

**Example**

```ts
import drawing from "@ohos.graphics.drawing"
const brush = new drawing.Brush();
brush.setBlendMode(drawing.BlendMode.SRC);
```
