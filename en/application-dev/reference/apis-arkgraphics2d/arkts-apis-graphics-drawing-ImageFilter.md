# Class (ImageFilter)

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
> - The initial APIs of this class are supported since API version 12.
>
> - This module uses the physical pixel unit, px.
>
> - This module operates under a single-threaded model. The caller needs to manage thread safety and context state transitions.

Implements an image filter.

## Modules to Import

```ts
import { drawing } from '@kit.ArkGraphics2D';
```

## createBlurImageFilter<sup>12+</sup>

static createBlurImageFilter(sigmaX: number, sigmaY: number, tileMode: TileMode, imageFilter?: ImageFilter | null ): ImageFilter

Creates an image filter with a given blur effect.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name         | Type   | Mandatory| Description                                                       |
| --------------- | ------- | ---- | ----------------------------------------------------------- |
| sigmaX | number | Yes  | Standard deviation of the Gaussian blur along the X axis. The value must be a floating point number greater than 0.|
| sigmaY | number | Yes  | Standard deviation of the Gaussian blur along the Y axis. The value must be a floating point number greater than 0.|
| tileMode | [TileMode](arkts-apis-graphics-drawing-e.md#tilemode12)| Yes  | Tile mode to apply to the edges.|
| imageFilter | [ImageFilter](arkts-apis-graphics-drawing-ImageFilter.md) \| null | No  | Filter to which the image filter will be applied. The default value is null, indicating that the image filter is directly applied to the original image.|

**Returns**

| Type                 | Description          |
| --------------------- | -------------- |
| [ImageFilter](arkts-apis-graphics-drawing-ImageFilter.md) | Image filter created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let imgFilter = drawing.ImageFilter.createBlurImageFilter(5, 10, drawing.TileMode.CLAMP);
```
## createFromImage<sup>20+</sup>

static createFromImage(pixelmap: image.PixelMap, srcRect?: common2D.Rect | null, dstRect?: common2D.Rect | null): ImageFilter

Creates an image filter from a given image. You are advised not to use the function for the canvas of the capture type because it affects the performance.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name         | Type   | Mandatory| Description                                                       |
| --------------- | ------- | ---- | ----------------------------------------------------------- |
| pixelmap | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)  | Yes  | Image object.|
| srcRect      | [common2D.Rect](js-apis-graphics-common2D.md#rect) \| null           | No  | (Optional) Pixel area of the image to be applied to the filter. This parameter is left empty by default, which means that the entire PixelMap area is applied.|
| dstRect      | [common2D.Rect](js-apis-graphics-common2D.md#rect) \| null           | No  | (Optional) Area to be rendered. This parameter is left empty by default, which means that the value is the same as that of **srcRect**.|

**Returns**

| Type                 | Description          |
| --------------------- | -------------- |
| [ImageFilter](arkts-apis-graphics-drawing-ImageFilter.md) | Image filter created.|

**Example**

```ts
import { RenderNode } from '@kit.ArkUI';
import { image } from '@kit.ImageKit';
import { common2D, drawing } from '@kit.ArkGraphics2D';
class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const width = 1000;
    const height = 1000;
    const bufferSize = width * height * 4;
    const color: ArrayBuffer = new ArrayBuffer(bufferSize);

    const colorData = new Uint8Array(color);
    for (let i = 0; i < colorData.length; i += 4) {
      colorData[i] = 255;
      colorData[i+1] = 156;
      colorData[i+2] = 0;
      colorData[i+3] = 255;
    }

    let opts : image.InitializationOptions = {
      editable: true,
      pixelFormat: 3,
      size: { height, width }
    }

    let pixelMap: image.PixelMap = image.createPixelMapSync(color, opts);
    let srcRect: common2D.Rect = { left: 10, top: 10, right: 80, bottom: 80 };
    let dstRect: common2D.Rect = { left: 200, top: 200, right: 400, bottom: 400 };
    if (pixelMap != null) {
      let filter = drawing.ImageFilter.createFromImage(pixelMap, srcRect, dstRect);
    }
  }
}
```
## createBlendImageFilter<sup>20+</sup>

static createBlendImageFilter(mode: BlendMode, background: ImageFilter, foreground: ImageFilter): ImageFilter

Creates a filter by blending two existing filters in a certain way.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name         | Type   | Mandatory| Description                                                       |
| --------------- | ------- | ---- | ----------------------------------------------------------- |
| mode   | [BlendMode](arkts-apis-graphics-drawing-e.md#blendmode)                              | Yes  | Blend mode.|
| background | [ImageFilter](arkts-apis-graphics-drawing-ImageFilter.md) | Yes  | Filter that serves as the destination color in blend mode.|
| foreground | [ImageFilter](arkts-apis-graphics-drawing-ImageFilter.md) | Yes  | Filter that serves as the source color in blend mode.|

**Returns**

| Type                 | Description           |
| --------------------- | -------------- |
| [ImageFilter](arkts-apis-graphics-drawing-ImageFilter.md) | Image filter created.|

**Error codes**

For details about the following error code, see [Drawing and Display Error Codes](../apis-arkgraphics2d/errorcode-drawing.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 25900001 | Parameter error.Possible causes: Incorrect parameter range. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let dx = 15.0;
let dy = 10.0;
let offsetFilter1 = drawing.ImageFilter.createOffsetImageFilter(dx, dy, null);
let x = 15.0;
let y = 30.0;
let offsetFilter2 = drawing.ImageFilter.createOffsetImageFilter(x, y, null);
let blendImageFilter = drawing.ImageFilter.createBlendImageFilter(drawing.BlendMode.SRC_IN, offsetFilter1, offsetFilter2);
```
## createComposeImageFilter<sup>20+</sup>

static createComposeImageFilter(cOuter: ImageFilter, cInner: ImageFilter): ImageFilter

Cascades two image filters to create a new image filter. The first filter's output becomes the second filter's input. The second filter then processes this input to produce the final result.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name         | Type   | Mandatory| Description                                                         |
| --------------- | ------- | ---- | ----------------------------------------------------------- |
| cOuter | [ImageFilter](arkts-apis-graphics-drawing-ImageFilter.md) | Yes  | The second filter in the cascade, which processes the first filter's output. If the second filter is empty and the first filter is not empty, the final result is the first filter's output. The two filters cannot be empty at the same time.|
| cInner | [ImageFilter](arkts-apis-graphics-drawing-ImageFilter.md) | Yes  | The first filter in the cascade, which directly processes the original image content. If the first filter is empty and the second filter is not empty, the final result is the second filter's output. The two filters cannot be empty at the same time.|

**Returns**

| Type                 | Description          |
| --------------------- | -------------- |
| [ImageFilter](arkts-apis-graphics-drawing-ImageFilter.md) | Image filter created.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let blurSigmaX = 10.0;
let blurSigmaY = 10.0;
let blurFilter = drawing.ImageFilter.createBlurImageFilter(blurSigmaX, blurSigmaY, drawing.TileMode.CLAMP, null);
let colorMatrix:Array<number> = [
  0, 0, 0, 0, 0,
  0, 1, 0, 0, 0,
  0, 0, 1, 0, 0,
  0, 0, 0, 1, 0
];
let redRemovalFilter = drawing.ColorFilter.createMatrixColorFilter(colorMatrix);
let colorFilter = drawing.ImageFilter.createFromColorFilter(redRemovalFilter, null);
let composedImageFilter = drawing.ImageFilter.createComposeImageFilter(colorFilter, blurFilter);
```
## createFromColorFilter<sup>12+</sup>

static createFromColorFilter(colorFilter: ColorFilter, imageFilter?: ImageFilter | null): ImageFilter

Creates an image filter object with a given color filter effect.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name         | Type   | Mandatory| Description                                                       |
| --------------- | ------- | ---- | ----------------------------------------------------------- |
| colorFilter | [ColorFilter](arkts-apis-graphics-drawing-ColorFilter.md) | Yes  | Color filter.|
| imageFilter | [ImageFilter](arkts-apis-graphics-drawing-ImageFilter.md) \| null | No  | Filter to which the image filter will be applied. The default value is null, indicating that the image filter is directly applied to the original image.|

**Returns**

| Type                 | Description          |
| --------------------- | -------------- |
| [ImageFilter](arkts-apis-graphics-drawing-ImageFilter.md) | Image filter created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';
let imgFilter = drawing.ImageFilter.createBlurImageFilter(5, 10, drawing.TileMode.CLAMP);
let clolorfilter = drawing.ColorFilter.createSRGBGammaToLinear();
let imgFilter1 = drawing.ImageFilter.createFromColorFilter(clolorfilter, imgFilter);
```
## createOffsetImageFilter<sup>20+</sup>

static createOffsetImageFilter(dx: number, dy: number, input?: ImageFilter | null): ImageFilter

Creates an offset filter to translate the input filter based on the specified vector.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name         | Type   | Mandatory| Description                                                       |
| --------------- | ------- | ---- | ----------------------------------------------------------- |
| dx | number | Yes  | Horizontal translation distance. The value is a floating point number.|
| dy | number | Yes  | Vertical translation distance. The value is a floating point number.|
| input | [ImageFilter](arkts-apis-graphics-drawing-ImageFilter.md) \| null | No  | Filter to be translated. This parameter is left empty by default, which means that the drawing result without the filtering effect is translated.|

**Returns**

| Type                 | Description          |
| --------------------- | -------------- |
| [ImageFilter](arkts-apis-graphics-drawing-ImageFilter.md) | Image filter created.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let dx = 15.0;
let dy = 10.0;
let offsetFilter = drawing.ImageFilter.createOffsetImageFilter(dx, dy, null);
```

## createFromShaderEffect<sup>20+</sup>

static createFromShaderEffect(shader: ShaderEffect): ImageFilter

Creates an **ImageFilter** object based on a shader.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name         | Type   | Mandatory| Description                                                       |
| --------------- | ------- | ---- | ----------------------------------------------------------- |
| shader   | [ShaderEffect](arkts-apis-graphics-drawing-ShaderEffect.md) | Yes  | Shader effect to be applied to the image.|

**Returns**

| Type                 | Description          |
| --------------------- | -------------- |
| [ImageFilter](arkts-apis-graphics-drawing-ImageFilter.md) | Image filter created.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let shaderEffect = drawing.ShaderEffect.createColorShader(0xFF00FF00);
let renderEffect = drawing.ImageFilter.createFromShaderEffect(shaderEffect);
```
