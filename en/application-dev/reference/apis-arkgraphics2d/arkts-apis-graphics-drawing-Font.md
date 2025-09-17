# Class (Font)

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
> - This module operates under a single-threaded model. The caller needs to manage thread safety and context state transitions.

Describes the attributes used for text rendering, such as size and typeface.

## Modules to Import

```ts
import { drawing } from '@kit.ArkGraphics2D';
```

## isSubpixel<sup>12+</sup>

isSubpixel(): boolean

Checks whether sub-pixel rendering is used for a font.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type  | Description                |
| ------ | -------------------- |
| boolean | Check result. The value **true** means that sub-pixel rendering is used, and **false** means the opposite.|

**Example**

```ts
import {drawing} from '@kit.ArkGraphics2D';

let font: drawing.Font = new drawing.Font();
font.enableSubpixel(true)
console.info("values=" + font.isSubpixel());
```

## isLinearMetrics<sup>12+</sup>

isLinearMetrics(): boolean

Checks whether linear scaling is used for this font.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type  | Description                |
| ------ | -------------------- |
| boolean | Check result. The value **true** means that linear scaling is used, and **false** means the opposite.|

**Example**

```ts
import {drawing} from '@kit.ArkGraphics2D';

let font: drawing.Font = new drawing.Font();
font.enableLinearMetrics(true)
console.info("values=" + font.isLinearMetrics());
```

## getSkewX<sup>12+</sup>

getSkewX(): number

Obtains the horizontal skew factor of this font.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type  | Description                |
| ------ | -------------------- |
| number | Horizontal skew factor.|

**Example**

```ts
import {drawing} from '@kit.ArkGraphics2D';

let font: drawing.Font = new drawing.Font();
font.setSkewX(-1)
console.info("values=" + font.getSkewX());
```

## isEmbolden<sup>12+</sup>

isEmbolden(): boolean

Checks whether the bold effect is set for this font.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type  | Description                |
| ------ | -------------------- |
| boolean  | Check result. The value **true** means that the bold effect is set, and **false** means the opposite.|

**Example**

```ts
import {drawing} from '@kit.ArkGraphics2D';

let font: drawing.Font = new drawing.Font();
font.enableEmbolden(true);
console.info("values=" + font.isEmbolden());
```

## getScaleX<sup>12+</sup>

getScaleX(): number

Obtains the horizontal scale ratio of this font.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type  | Description                |
| ------ | -------------------- |
| number  | Horizontal scale ratio.|

**Example**

```ts
import {drawing} from '@kit.ArkGraphics2D';

let font: drawing.Font = new drawing.Font();
font.setScaleX(2);
console.info("values=" + font.getScaleX());
```

## getHinting<sup>12+</sup>

getHinting(): FontHinting

Obtains the font hinting effect.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type  | Description                |
| ------ | -------------------- |
| [FontHinting](arkts-apis-graphics-drawing-e.md#fonthinting12)  | Font hinting effect.|

**Example**

```ts
import {drawing} from '@kit.ArkGraphics2D';

let font: drawing.Font = new drawing.Font();
console.info("values=" + font.getHinting());
```

## getEdging<sup>12+</sup>

getEdging(): FontEdging

Obtains the font edging effect.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type  | Description                |
| ------ | -------------------- |
| [FontEdging](arkts-apis-graphics-drawing-e.md#fontedging12)  | Font edging effect.|

**Example**

```ts
import {drawing} from '@kit.ArkGraphics2D';

let font: drawing.Font = new drawing.Font();
console.info("values=" + font.getEdging());
```

## enableSubpixel

enableSubpixel(isSubpixel: boolean): void

Enables subpixel font rendering.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name    | Type   | Mandatory| Description                                                        |
| ---------- | ------- | ---- | ------------------------------------------------------------ |
| isSubpixel | boolean | Yes  | Whether to enable subpixel font rendering. **true** to enable, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font = new drawing.Font();
font.enableSubpixel(true);
```

## enableEmbolden

enableEmbolden(isEmbolden: boolean): void

Enables emboldened fonts.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name    | Type   | Mandatory| Description                                                 |
| ---------- | ------- | ---- | ----------------------------------------------------- |
| isEmbolden | boolean | Yes  | Whether to enable emboldened fonts. **true** to enable, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font = new drawing.Font();
font.enableEmbolden(true);
```

## enableLinearMetrics

enableLinearMetrics(isLinearMetrics: boolean): void

Enables linear font scaling.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name         | Type   | Mandatory| Description                                                       |
| --------------- | ------- | ---- | ----------------------------------------------------------- |
| isLinearMetrics | boolean | Yes  | Whether to enable linear font scaling. **true** to enable, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font = new drawing.Font();
font.enableLinearMetrics(true);
```

## setSize

setSize(textSize: number): void

Sets the font size.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type  | Mandatory| Description            |
| -------- | ------ | ---- | ---------------- |
| textSize | number | Yes  | Font size. The value is a floating point number. If a negative number is passed in, the size is set to 0. If the size is 0, the text drawn will not be displayed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font = new drawing.Font();
font.setSize(5);
```

## getSize

getSize(): number

Obtains the font size.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type  | Description            |
| ------ | ---------------- |
| number | Font size. The value is a floating point number.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font = new drawing.Font();
font.setSize(5);
let fontSize = font.getSize();
```

## setTypeface

setTypeface(typeface: Typeface): void

Sets the typeface style (including attributes such as font name, weight, and italic) for the font.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                 | Mandatory| Description  |
| -------- | --------------------- | ---- | ------ |
| typeface | [Typeface](arkts-apis-graphics-drawing-Typeface.md) | Yes  | Typeface style (including attributes such as font name, weight, and italic).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font = new drawing.Font();
font.setTypeface(new drawing.Typeface());
```

## getTypeface

getTypeface(): Typeface

Obtains the typeface.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type                 | Description  |
| --------------------- | ------ |
| [Typeface](arkts-apis-graphics-drawing-Typeface.md) | Font.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font = new drawing.Font();
let typeface = font.getTypeface();
```

## getMetrics

getMetrics(): FontMetrics

Obtains the font metrics of the typeface.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type                       | Description             |
| --------------------------- | ----------------- |
| [FontMetrics](arkts-apis-graphics-drawing-i.md#fontmetrics) | Font metrics.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font = new drawing.Font();
let metrics = font.getMetrics();
```

## measureText

measureText(text: string, encoding: TextEncoding): number

Measures the text width.

> **NOTE**
>
> This API is used to measure the text width of the original string. To measure the text width after typesetting, call **measure.measureText**.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                         | Mandatory| Description      |
| -------- | ----------------------------- | ---- | ---------- |
| text     | string                        | Yes  | Content of the item in the operation area.|
| encoding | [TextEncoding](arkts-apis-graphics-drawing-e.md#textencoding) | Yes  | Pointer to the encoding format.|

**Returns**

| Type  | Description            |
| ------ | ---------------- |
| number | Width of the text. The value is a floating point number.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font = new drawing.Font();
font.measureText("drawing", drawing.TextEncoding.TEXT_ENCODING_UTF8);
```

## measureSingleCharacter<sup>12+</sup>

measureSingleCharacter(text: string): number

Measures the width of a single character. If the typeface of the current font does not support the character to measure, the system typeface is used to measure the character width.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type               | Mandatory| Description       |
| ------ | ------------------- | ---- | ----------- |
| text   | string | Yes  | Single character to measure. The length of the string must be 1. |

**Returns**

| Type  | Description            |
| ------ | ---------------- |
| number | Width of the character. The value is a floating point number.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**Example**

```ts
import { RenderNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    const font = new drawing.Font();
    font.setSize(20);
    let width = font.measureSingleCharacter ("Hello");
  }
}
```

## measureSingleCharacterWithFeatures<sup>20+</sup>

measureSingleCharacterWithFeatures(text: string, features: Array\<FontFeature\>): number

Measures the width of a single character with font features. If the typeface of the current font does not support the character to measure, the system typeface is used to measure the character width.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type               | Mandatory| Description       |
| ------ | ------------------- | ---- | ----------- |
| text | string | Yes| Pointer to the single character to measure. The string size must be 1.|
| features | Array\<[FontFeature](arkts-apis-graphics-drawing-i.md#fontfeature20)\> | Yes| Array of the font feature object. For an empty array, the preset font features in the TrueType Font (TTF) file are used.|

**Returns**

| Type  | Description            |
| ------ | ---------------- |
| number | Width of the character. The value is a floating point number in px.|

**Error codes**

For details about the following error code, see [Drawing and Display Error Codes](../apis-arkgraphics2d/errorcode-drawing.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 25900001 | Parameter error. Possible causes: Incorrect parameter range. |

**Example**

```ts
import { RenderNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const font = new drawing.Font();
    font.setSize(20);
    let fontFeatures : Array<drawing.FontFeature> = [];
    fontFeatures.push({name: 'calt', value: 0});
    let width = font.measureSingleCharacterWithFeatures("A", fontFeatures);
  }
}
```

## setScaleX<sup>12+</sup>

setScaleX(scaleX: number): void

Sets a horizontal scale factor for this font.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                         | Mandatory| Description      |
| -------- | ----------------------------- | ---- | ---------- |
| scaleX     | number                      | Yes  | Horizontal scale factor. The value is a floating point number.|

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
    const pen = new drawing.Pen();
    pen.setStrokeWidth(5);
    pen.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachPen(pen);
    let font = new drawing.Font();
    font.setSize(100);
    font.setScaleX(2);
    const textBlob = drawing.TextBlob.makeFromString("hello", font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
    canvas.drawTextBlob(textBlob, 200, 200);
  }
}
```

## setSkewX<sup>12+</sup>

setSkewX(skewX: number): void

Sets a horizontal skew factor for this font.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                         | Mandatory| Description      |
| -------- | ----------------------------- | ---- | ---------- |
| skewX     | number                      | Yes  | Horizontal skew factor. A positive number means a skew to the left, and a negative number means a skew to the right. The value is a floating point number.|

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
    const pen = new drawing.Pen();
    pen.setStrokeWidth(5);
    pen.setColor({alpha: 255, red: 255, green: 0, blue: 0});
    canvas.attachPen(pen);
    let font = new drawing.Font();
    font.setSize(100);
    font.setSkewX(1);
    const textBlob = drawing.TextBlob.makeFromString("hello", font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
    canvas.drawTextBlob(textBlob, 200, 200);
  }
}
```

## setEdging<sup>12+</sup>

setEdging(edging: FontEdging): void

Sets a font edging effect.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                         | Mandatory| Description      |
| -------- | ----------------------------- | ---- | ---------- |
| edging | [FontEdging](arkts-apis-graphics-drawing-e.md#fontedging12) | Yes  | Font edging effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font = new drawing.Font();
font.setEdging(drawing.FontEdging.SUBPIXEL_ANTI_ALIAS);
```

## setHinting<sup>12+</sup>

setHinting(hinting: FontHinting): void

Sets a font hinting effect.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                         | Mandatory| Description      |
| -------- | ----------------------------- | ---- | ---------- |
| hinting | [FontHinting](arkts-apis-graphics-drawing-e.md#fonthinting12) | Yes  | Font hinting effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font = new drawing.Font();
font.setHinting(drawing.FontHinting.FULL);
```

## countText<sup>12+</sup>

countText(text: string): number

Obtains the number of glyphs represented by text.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                         | Mandatory| Description      |
| -------- | ----------------------------- | ---- | ---------- |
| text     | string                        | Yes  | Content of the item in the operation area.|

**Returns**

| Type  | Description            |
| ------ | ---------------- |
| number | Number of glyphs represented by the text. The value is an integer.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font = new drawing.Font();
let resultNumber: number = font.countText('ABCDE');
console.info("count text number: " + resultNumber);
```

## setBaselineSnap<sup>12+</sup>

setBaselineSnap(isBaselineSnap: boolean): void

Sets whether to request that baselines be snapped to pixels when the current canvas matrix is axis aligned.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name         | Type   | Mandatory| Description                                      |
| --------------- | ------- | ---- | ---------------------------------------- |
| isBaselineSnap | boolean | Yes  | Check result. The value **true** means to request that baselines be snapped to pixels, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font : drawing.Font = new drawing.Font();
font.setBaselineSnap(true);
console.info("drawing font isBaselineSnap: " + font.isBaselineSnap());
```

## isBaselineSnap()<sup>12+</sup>

isBaselineSnap(): boolean

Checks whether baselines are requested to be snapped to pixels when the current canvas matrix is axis aligned.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type  | Description            |
| ------ | ---------------- |
| boolean | Check result. The value **true** means that the baselines are requested to be snapped to pixels, and **false** means the opposite.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font : drawing.Font = new drawing.Font();
font.setTypeface(new drawing.Typeface());
font.setBaselineSnap(true);
console.info("drawing font isBaselineSnap: " + font.isBaselineSnap());
```

## setEmbeddedBitmaps<sup>12+</sup>

setEmbeddedBitmaps(isEmbeddedBitmaps: boolean): void

Sets whether to use bitmaps in this font.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type  | Mandatory| Description            |
| -------- | ------ | ---- | ---------------- |
| isEmbeddedBitmaps | boolean | Yes  | Whether to use bitmaps in the font. The value **true** means to use bitmaps in the font, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font : drawing.Font = new drawing.Font();
font.setTypeface(new drawing.Typeface());
font.setEmbeddedBitmaps(false);
console.info("draw isEmbeddedBitmaps: " + font.isEmbeddedBitmaps());
```

## isEmbeddedBitmaps()<sup>12+</sup>

isEmbeddedBitmaps(): boolean

Checks whether bitmaps are used in this font.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type  | Description            |
| ------ | ---------------- |
| boolean | Check result. The value **true** means that the bitmaps are used, and **false** means the opposite.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font : drawing.Font = new drawing.Font();
font.setTypeface(new drawing.Typeface());
font.setEmbeddedBitmaps(true);
console.info("draw isEmbeddedBitmaps: " + font.isEmbeddedBitmaps());
```

## setForceAutoHinting<sup>12+</sup>

setForceAutoHinting(isForceAutoHinting: boolean): void

Sets whether to forcibly use auto hinting, that is, whether to always hint glyphs.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type  | Mandatory| Description            |
| -------- | ------ | ---- | ---------------- |
| isForceAutoHinting | boolean | Yes  | Check result. The value **true** means to forcibly use auto hinting, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font : drawing.Font = new drawing.Font();
font.setTypeface(new drawing.Typeface());
font.setForceAutoHinting(false);
console.info("drawing isForceAutoHinting:  " + font.isForceAutoHinting());
```

## isForceAutoHinting<sup>12+</sup>

isForceAutoHinting(): boolean

Checks whether auto hinting is forcibly used.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type  | Description            |
| ------ | ---------------- |
| boolean | Check result. The value **true** means that auto hinting is forcibly used, and **false** means the opposite.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font : drawing.Font = new drawing.Font();
font.setTypeface(new drawing.Typeface());
font.setForceAutoHinting(false);
console.info("drawing isForceAutoHinting:  " + font.isForceAutoHinting());
```

## getWidths<sup>12+</sup>

getWidths(glyphs: Array\<number>): Array\<number>

Obtains the width of each glyph in an array.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                 | Mandatory| Description  |
| -------- | --------------------- | ---- | ------ |
| glyphs | Array\<number> | Yes  | Glyph array, which can be generated by [textToGlyphs](#texttoglyphs12).|

**Returns**

| Type  | Description            |
| ------ | ---------------- |
| Array\<number> | Glyph width array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font: drawing.Font = new drawing.Font();
let text: string = 'hello world';
let glyphs: number[] = font.textToGlyphs(text);
let fontWidths: Array<number> = font.getWidths(glyphs);
for (let index = 0; index < fontWidths.length; index++) {
  console.info("get fontWidths[", index, "]:", fontWidths[index]);
}
```

## textToGlyphs<sup>12+</sup>

textToGlyphs(text: string, glyphCount?: number): Array\<number>

Converts text into glyph indexes.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                         | Mandatory| Description      |
| -------- | ----------------------------- | ---- | ---------- |
| text     | string                        | Yes  | Text string.|
| glyphCount | number | No  | Number of glyphs represented by the text. The value must be the same as the value obtained from [countText](#counttext12). The default value is the number of characters in the text string. The value is an integer.|

**Returns**

| Type  | Description            |
| ------ | ---------------- |
| Array\<number> | Array that holds the glyph indexes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font : drawing.Font = new drawing.Font();
let text : string = 'hello world';
let glyphs : number[] = font.textToGlyphs(text);
console.info("drawing text toglyphs OnTestFunction num =  " + glyphs.length );
```

## getBounds<sup>18+</sup>

getBounds(glyphs: Array\<number>): Array\<common2D.Rect>

Obtains the rectangular bounding box of each glyph in an array.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                 | Mandatory| Description  |
| -------- | --------------------- | ---- | ------ |
| glyphs | Array\<number> | Yes  | Glyph array, which can be generated by [textToGlyphs](#texttoglyphs12).|

**Returns**

| Type  | Description            |
| ------ | ---------------- |
| Array\<[common2D.Rect](js-apis-graphics-common2D.md#rect)> | Array that holds the rectangular bounding boxes.|

**Example**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

let font: drawing.Font = new drawing.Font();
let text: string = 'hello world';
let glyphs: number[] = font.textToGlyphs(text);
let fontBounds: Array<common2D.Rect> = font.getBounds(glyphs);
for (let index = 0; index < fontBounds.length; index++) {
  console.info("get fontWidths[", index, "] left:", fontBounds[index].left, " top:", fontBounds[index].top,
    " right:", fontBounds[index].right, " bottom:", fontBounds[index].bottom);
}
```

## getTextPath<sup>18+</sup>

getTextPath(text: string, byteLength: number, x: number, y: number): Path

Obtains the outline path of a text.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name   | Type                                              | Mandatory| Description                   |
| ------   | ------------------------------------------------   | ---- | ---------------------- |
|   text   |    string                                          | Yes  | UTF-8 text-encoded characters.|
|byteLength|    number                                          | Yes  | Length of the outline path, which is obtained based on the minimum value between the passed value of **byteLength** and the actual text byte size.|
|    x     |    number                                          | Yes  | X coordinate of the text in the drawing area, with the origin as the start point.|
|    y     |    number                                          | Yes  | Y coordinate of the text in the drawing area, with the origin as the start point.|

**Returns**

| Type  | Description            |
| ------ | ---------------- |
| [Path](arkts-apis-graphics-drawing-Path.md) | Outline path of the text.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';
import { buffer } from '@kit.ArkTS';
import { RenderNode } from '@kit.ArkUI';

class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    let font = new drawing.Font();
    font.setSize(50);
    let myString: string = "Hello, HarmonyOS";
    let length: number = myString.length;
    let path = font.getTextPath(myString, length, 0, 100);
    canvas.drawPath(path);
  }
}
```

## createPathForGlyph<sup>18+</sup>

createPathForGlyph(index: number): Path

Obtains the outline path of a glyph.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                 | Mandatory| Description  |
| -------- | --------------------- | ---- | ------ |
| index | number | Yes  | Index of the glyph.|

**Returns**

| Type  | Description            |
| ------ | ---------------- |
| [Path](arkts-apis-graphics-drawing-Path.md) | Outline path of the glyph.|

**Example**

```ts
import { FrameNode, NodeController, RenderNode } from '@kit.ArkUI';
import { drawing } from '@kit.ArkGraphics2D';

class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    let font = new drawing.Font();
    font.setSize(50)
    let text: string = 'Hello'
    let glyphs: number[] = font.textToGlyphs(text);
    for (let index = 0; index < glyphs.length; index++) {
      let path: drawing.Path = font.createPathForGlyph(glyphs[index])
      canvas.drawPath(path)
    }
  }
}
```

## setThemeFontFollowed<sup>15+</sup>

setThemeFontFollowed(followed: boolean): void

Sets whether to follow the theme font. When **followed** is set to **true**, the theme font is used if it is enabled by the system and no typeface is set.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type  | Mandatory| Description            |
| -------- | ------ | ---- | ---------------- |
| followed | boolean | Yes  | Whether to follow the theme font. The value **true** means to follow the theme font, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font : drawing.Font = new drawing.Font();
font.setThemeFontFollowed(true);
console.info("font is theme font followed: " + font.isThemeFontFollowed());
```

## isThemeFontFollowed()<sup>15+</sup>

isThemeFontFollowed(): boolean

Checks whether the font follows the theme font. By default, the font follows the theme font.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type  | Description            |
| ------ | ---------------- |
| boolean | Check result. The value **true** means that the theme font is followed, and **false** means the opposite.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let font : drawing.Font = new drawing.Font();
font.setThemeFontFollowed(true);
console.info("font is theme font followed: " + font.isThemeFontFollowed());
```
