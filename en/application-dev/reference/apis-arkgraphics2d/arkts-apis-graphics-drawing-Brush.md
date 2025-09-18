# Class (Brush)

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

Defines a brush, which is used to describe the style and color to fill in a shape.

## Modules to Import

```ts
import { drawing } from '@kit.ArkGraphics2D';
```

## constructor<sup>12+</sup>

constructor()

A constructor used to create a **Brush** object.

**System capability**: SystemCapability.Graphics.Drawing

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
```

## constructor<sup>12+</sup>

constructor(brush: Brush)

Copies a **Brush** object to create a new one.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type       | Mandatory| Description             |
| ------| ----------- | ---- | ---------------- |
| brush     | [Brush](arkts-apis-graphics-drawing-Brush.md) | Yes  | **Brush** object to copy.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
const brushColor: common2D.Color = { alpha: 255, red: 0, green: 255, blue: 0 };
brush.setColor(brushColor);
const newBrush = new drawing.Brush(brush);
```

## setColor

setColor(color: common2D.Color) : void

Sets a color for this brush.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                                                | Mandatory| Description            |
| ------ | ---------------------------------------------------- | ---- | ---------------- |
| color  | [common2D.Color](js-apis-graphics-common2D.md#color) | Yes  | Color in ARGB format. The value of each color channel is an integer ranging from 0 to 255.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**Example**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

const color : common2D.Color = { alpha: 255, red: 255, green: 0, blue: 0 };
const brush = new drawing.Brush();
brush.setColor(color);
```

## setColor<sup>12+</sup>

setColor(alpha: number, red: number, green: number, blue: number): void

Sets a color for this brush. This API provides better performance than [setColor](#setcolor) and is recommended.

**System capability**: SystemCapability.Graphics.Drawing
 
**Parameters**

| Name| Type   | Mandatory| Description                                              |
| ------ | ------ | ---- | -------------------------------------------------- |
| alpha  | number | Yes  | Alpha channel value of the color in ARGB format. The value is an integer ranging from 0 to 255. Any passed-in floating point number is rounded down.|
| red    | number | Yes  | Red channel value of the color in ARGB format. The value is an integer ranging from 0 to 255. Any passed-in floating point number is rounded down.  |
| green  | number | Yes  | Green channel value of the color in ARGB format. The value is an integer ranging from 0 to 255. Any passed-in floating point number is rounded down.  |
| blue   | number | Yes  | Blue channel value of the color in ARGB format. The value is an integer ranging from 0 to 255. Any passed-in floating point number is rounded down.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
brush.setColor(255, 255, 0, 0);
```

## setColor<sup>18+</sup>

setColor(color: number) : void

Sets a color for this brush.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                                                | Mandatory| Description            |
| ------ | ---------------------------------------------------- | ---- | ---------------- |
| color  | number | Yes  | Color in hexadecimal ARGB format.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
brush.setColor(0xffff0000);
```

## setColor4f<sup>20+</sup>

setColor4f(color4f: common2D.Color4f, colorSpace: colorSpaceManager.ColorSpaceManager | null): void

Sets the color and standard color gamut for this brush. The difference between this method and [setColor](#setcolor) is that the color gamut can be set separately.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                                                | Mandatory| Description            |
| ------ | ---------------------------------------------------- | ---- | ---------------- |
| color4f  | [common2D.Color4f](js-apis-graphics-common2D.md#color4f20) | Yes  | Color in the ARGB format. The value of each color channel is a floating point number ranging from 0.0 to 1.0. Values above 1.0 default to 1.0, and values below 0.0 default to 0.0.|
| colorSpace  | [colorSpaceManager.ColorSpaceManager](js-apis-colorSpaceManager.md#colorspacemanager) \| null | Yes  | Standard color gamut object. null indicates SRGB.|

**Example**

```ts
import { common2D, drawing, colorSpaceManager } from "@kit.ArkGraphics2D";

const brush = new drawing.Brush();
let colorSpace = colorSpaceManager.create(colorSpaceManager.ColorSpace.BT2020_HLG);
let color4f:common2D.Color4f = {alpha:1, red:0.5, green:0.4, blue:0.7};
brush.setColor4f(color4f, colorSpace);
```

## getColor<sup>12+</sup>

getColor(): common2D.Color

Obtains the color of this brush.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type          | Description           |
| -------------- | -------------- |
| common2D.Color | Color of the brush.|

**Example**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

const color : common2D.Color = { alpha: 255, red: 255, green: 0, blue: 0 };
const brush = new drawing.Brush();
brush.setColor(color);
let colorGet = brush.getColor();
```

## getColor4f<sup>20+</sup>

getColor4f(): common2D.Color4f

Obtains the brush color. The difference between this method and [getColor](#getcolor12) is that this method returns a floating point number.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type          | Description           |
| -------------- | -------------- |
| [common2D.Color4f](js-apis-graphics-common2D.md#color4f20) | Color of the brush.|

**Example**

```ts
import { common2D, drawing, colorSpaceManager } from "@kit.ArkGraphics2D";

const brush = new drawing.Brush();
let colorSpace = colorSpaceManager.create(colorSpaceManager.ColorSpace.BT2020_HLG);
let color4f:common2D.Color4f = {alpha:1, red:0.5, green:0.4, blue:0.7};
brush.setColor4f(color4f, colorSpace);
let color = brush.getColor4f();
```

## getHexColor<sup>18+</sup>

getHexColor(): number

Obtains the color of this brush.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type          | Description           |
| -------------- | -------------- |
| number | Color, represented as a 32-bit unsigned integer in hexadecimal ARGB format.|

**Example**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

let color : common2D.Color = { alpha: 255, red: 255, green: 0, blue: 0 };
let brush = new drawing.Brush();
brush.setColor(color);
let hex_color: number = brush.getHexColor();
console.info('getHexColor: ', hex_color.toString(16));
```

## setAntiAlias

setAntiAlias(aa: boolean) : void

Enables anti-aliasing for this brush. Anti-aliasing makes the edges of the content smoother. If this API is not called, anti-aliasing is disabled by default.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description                                             |
| ------ | ------- | ---- | ------------------------------------------------- |
| aa     | boolean | Yes  | Whether to enable anti-aliasing. The value **true** means to enable anti-aliasing, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
brush.setAntiAlias(true);
```

## isAntiAlias<sup>12+</sup>

isAntiAlias(): boolean

Checks whether anti-aliasing is enabled for this brush.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type   | Description                      |
| ------- | ------------------------- |
| boolean | Check result. The value **true** means that anti-aliasing is enabled, and **false** means the opposite.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
let isAntiAlias = brush.isAntiAlias();
```

## setAlpha

setAlpha(alpha: number) : void

Sets an alpha value for this brush.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| alpha  | number | Yes  | Alpha value. The value is an integer in the range [0, 255]. If a floating point number is passed in, the value is rounded down.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
brush.setAlpha(128);
```

## getAlpha<sup>12+</sup>

getAlpha(): number

Obtains the alpha value of this brush.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type  | Description             |
| ------ | ---------------- |
| number | Alpha value of the brush. The return value is an integer ranging from 0 to 255.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
let alpha = brush.getAlpha();
```

## setColorFilter

setColorFilter(filter: ColorFilter) : void

Sets a color filter for this brush.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                       | Mandatory| Description        |
| ------ | --------------------------- | ---- | ------------ |
| filter | [ColorFilter](arkts-apis-graphics-drawing-ColorFilter.md) | Yes  | Defines a color filter. If null is passed in, the color filter is cleared.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
let colorFilter = drawing.ColorFilter.createLinearToSRGBGamma();
brush.setColorFilter(colorFilter);
```

## setMaskFilter<sup>12+</sup>

setMaskFilter(filter: MaskFilter): void

Adds a mask filter for this brush.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                      | Mandatory| Description     |
| ------ | ------------------------- | ---- | --------- |
| filter | [MaskFilter](arkts-apis-graphics-drawing-MaskFilter.md) | Yes  | Mask filter. If null is passed in, the mask filter is cleared.|

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
    const brush = new drawing.Brush();
    let maskFilter = drawing.MaskFilter.createBlurMaskFilter(drawing.BlurType.OUTER, 10);
    brush.setMaskFilter(maskFilter);
  }
}
```

## setShaderEffect<sup>12+</sup>

setShaderEffect(shaderEffect: ShaderEffect): void

Sets the shader effect for this brush.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name | Type                      | Mandatory| Description        |
| ------- | ------------------------- | ---- | ------------ |
| shaderEffect  | [ShaderEffect](arkts-apis-graphics-drawing-ShaderEffect.md) | Yes  | **ShaderEffect** object. If null is passed in, the shader effect will be cleared.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
let shaderEffect = drawing.ShaderEffect.createLinearGradient({x: 100, y: 100}, {x: 300, y: 300}, [0xFF00FF00, 0xFFFF0000], drawing.TileMode.REPEAT);
brush.setShaderEffect(shaderEffect);
```

## setShadowLayer<sup>12+</sup>

setShadowLayer(shadowLayer: ShadowLayer): void

Sets a shadow layer for this brush. The shadow layer effect takes effect only when text is drawn.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name | Type                      | Mandatory| Description     |
| ------- | ------------------------- | ---- | --------- |
| shadowLayer  | [ShadowLayer](arkts-apis-graphics-drawing-ShadowLayer.md) | Yes  | Implements a shadow layer. If null is passed in, the shadow layer is cleared.|

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
    let font = new drawing.Font();
    font.setSize(60);

    let textBlob = drawing.TextBlob.makeFromString("hello", font, drawing.TextEncoding.TEXT_ENCODING_UTF8);
    let pen = new drawing.Pen();
    pen.setStrokeWidth(2.0);

    let pen_color : common2D.Color = {alpha: 0xFF, red: 0xFF, green: 0x00, blue: 0x00};
    pen.setColor(pen_color);
    canvas.attachPen(pen);
    canvas.drawTextBlob(textBlob, 100, 100);
    canvas.detachPen();

    let color : common2D.Color = {alpha: 0xFF, red: 0x00, green: 0xFF, blue: 0x00};
    let shadowLayer = drawing.ShadowLayer.create(3, -3, 3, color);
    pen.setShadowLayer(shadowLayer);
    canvas.attachPen(pen);
    canvas.drawTextBlob(textBlob, 100, 200);
    canvas.detachPen();

    let brush = new drawing.Brush();
    let brush_color : common2D.Color = {alpha: 0xFF, red: 0xFF, green: 0x00, blue: 0x00};
    brush.setColor(brush_color);
    canvas.attachBrush(brush);
    canvas.drawTextBlob(textBlob, 300, 100);
    canvas.detachBrush();

    brush.setShadowLayer(shadowLayer);
    canvas.attachBrush(brush);
    canvas.drawTextBlob(textBlob, 300, 200);
    canvas.detachBrush();
  }
}
```

## setBlendMode

setBlendMode(mode: BlendMode) : void

Sets a blend mode for this brush. If this API is not called, the default blend mode is **SRC_OVER**.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                   | Mandatory| Description            |
| ------ | ----------------------- | ---- | ---------------- |
| mode   | [BlendMode](arkts-apis-graphics-drawing-e.md#blendmode) | Yes  | Blend mode.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
brush.setBlendMode(drawing.BlendMode.SRC);
```

## setImageFilter<sup>12+</sup>

setImageFilter(filter: ImageFilter | null): void

Sets an image filter for this brush.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type  | Mandatory| Description                   |
| ------ | ------ | ---- | ----------------------- |
| filter    | [ImageFilter](arkts-apis-graphics-drawing-ImageFilter.md) \| null | Yes  | Image filter. If null is passed in, the image filter effect of the brush will be cleared.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types. | 

**Example**

```ts
import {drawing} from '@kit.ArkGraphics2D';

let brush = new drawing.Brush();
let imgFilter = drawing.ImageFilter.createBlurImageFilter(5, 10, drawing.TileMode.DECAL);
brush.setImageFilter(imgFilter);
brush.setImageFilter(null);
```

## getColorFilter<sup>12+</sup>

getColorFilter(): ColorFilter

Obtains the color filter of this brush.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type                       | Description              |
| --------------------------- | ------------------ |
| [ColorFilter](arkts-apis-graphics-drawing-ColorFilter.md) | Color filter.|

**Example**

```ts 
import {drawing} from '@kit.ArkGraphics2D';

let brush = new drawing.Brush();
let setColorFilter = drawing.ColorFilter.createSRGBGammaToLinear();
brush.setColorFilter(setColorFilter);
let filter = brush.getColorFilter();   
```

## reset<sup>12+</sup>

reset(): void

Resets this brush to the initial state.

**System capability**: SystemCapability.Graphics.Drawing

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

const brush = new drawing.Brush();
brush.reset();
```
