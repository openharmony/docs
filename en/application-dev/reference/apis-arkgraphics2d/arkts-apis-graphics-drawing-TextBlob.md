# Class (TextBlob)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @hangmengxin-->
<!--Designer: @wangyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This module uses the physical pixel unit, px.
>
> - The module operates under a single-threaded model. The caller needs to manage thread safety and context state transitions.

Defines a block consisting of one or more characters with the same font.

## Modules to Import

```ts
import { drawing } from '@kit.ArkGraphics2D';
```

## makeFromPosText<sup>12+</sup>

static makeFromPosText(text: string, len: number, points: common2D.Point[], font: Font): TextBlob

Creates a **TextBlob** object from the text. The coordinates of each font in the **TextBlob** object are determined by the coordinate information in the **points** array.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                         | Mandatory| Description                                  |
| -------- | ----------------------------- | ---- | -------------------------------------- |
| text     | string             | Yes  | Content to be used for drawing the text blob.                  |
| len      | number             | Yes  | Number of glyphs, which is an integer obtained from [countText](arkts-apis-graphics-drawing-Font.md#counttext12).|
| points   |[common2D.Point](js-apis-graphics-common2D.md#point12)[]     | Yes  |Array of points, which are used to specify the coordinates of each font. The array length must be the same as the value of **len**.|
| font     | [Font](arkts-apis-graphics-drawing-Font.md)      | Yes  | **Font** object.|

**Returns**

| Type                 | Description          |
| --------------------- | -------------- |
| [TextBlob](arkts-apis-graphics-drawing-TextBlob.md) | **TextBlob** object.|


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types. |

**Example**

```ts
import { RenderNode } from '@kit.ArkUI';
import { drawing,common2D} from '@kit.ArkGraphics2D';

class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    let text : string = 'makeFromPosText';
    let font : drawing.Font = new drawing.Font();
    font.setSize(100);
    let length = font.countText(text);
    let points : common2D.Point[] = [];
    for (let i = 0; i !== length; ++i) {
      points.push({ x: i * 35, y: i * 35 });
    }
    let textblob : drawing.TextBlob =drawing.TextBlob.makeFromPosText(text, points.length, points, font);
    canvas.drawTextBlob(textblob, 100, 100);
  }
}
```

## uniqueID<sup>12+</sup>

uniqueID(): number

Obtains the unique, non-zero identifier of this **TextBlob** object.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type                 | Description          |
| --------------------- | -------------- |
| number | Unique, non-zero identifier of this **TextBlob** object.|

**Example**

```ts
import {drawing} from "@kit.ArkGraphics2D";

let text : string = 'TextBlobUniqueId';
let font : drawing.Font = new drawing.Font();
font.setSize(100);
let textBlob = drawing.TextBlob.makeFromString(text, font, 0);
let id = textBlob.uniqueID();
console.info("uniqueID---------------" +id);
```

## makeFromString

static makeFromString(text: string, font: Font, encoding?: TextEncoding): TextBlob

Converts a value of the string type into a **TextBlob** object.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                         | Mandatory| Description                                  |
| -------- | ----------------------------- | ---- | -------------------------------------- |
| text     | string                        | Yes  | Content to be used for drawing the text blob.                  |
| font     | [Font](arkts-apis-graphics-drawing-Font.md)                 | Yes  | **Font** object.          |
| encoding | [TextEncoding](arkts-apis-graphics-drawing-e.md#textencoding) | No  | Encoding type. The default value is **TEXT_ENCODING_UTF8**. Currently, only **TEXT_ENCODING_UTF8** takes effect, and other encoding types are treated as **TEXT_ENCODING_UTF8**.|

**Returns**

| Type                 | Description          |
| --------------------- | -------------- |
| [TextBlob](arkts-apis-graphics-drawing-TextBlob.md) | **TextBlob** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { RenderNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

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

## makeFromRunBuffer

static makeFromRunBuffer(pos: Array\<TextBlobRunBuffer>, font: Font, bounds?: common2D.Rect): TextBlob

Creates a **TextBlob** object based on the **RunBuffer** information.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                                              | Mandatory| Description                          |
| ------ | -------------------------------------------------- | ---- | ------------------------------ |
| pos    | Array\<[TextBlobRunBuffer](arkts-apis-graphics-drawing-i.md#textblobrunbuffer)>    | Yes  | **TextBlobRunBuffer** array.       |
| font   | [Font](arkts-apis-graphics-drawing-Font.md)                                      | Yes  | **Font** object.  |
| bounds | [common2D.Rect](js-apis-graphics-common2D.md#rect) | No  | Bounding box. If this parameter is not set, there is no bounding box.|

**Returns**

| Type                 | Description          |
| --------------------- | -------------- |
| [TextBlob](arkts-apis-graphics-drawing-TextBlob.md) | **TextBlob** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { RenderNode } from '@kit.ArkUI';
import { common2D, drawing } from '@kit.ArkGraphics2D';

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

## bounds

bounds(): common2D.Rect

Obtains the rectangular bounding box of the text blob.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type                                              | Description                  |
| -------------------------------------------------- | ---------------------- |
| [common2D.Rect](js-apis-graphics-common2D.md#rect) | Rectangular bounding box.|

**Example**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

const font = new drawing.Font();
font.setSize(20);
const textBlob = drawing.TextBlob.makeFromString("drawing", font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
let bounds = textBlob.bounds();
```
