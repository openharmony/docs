# Class (ColorFilter)

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

Defines a color filter.

## Modules to Import

```ts
import { drawing } from '@kit.ArkGraphics2D';
```

## createBlendModeColorFilter

createBlendModeColorFilter(color: common2D.Color, mode: BlendMode) : ColorFilter

Creates a **ColorFilter** object with a given color and blend mode.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                                                | Mandatory| Description            |
| ------ | ---------------------------------------------------- | ---- | ---------------- |
| color  | [common2D.Color](js-apis-graphics-common2D.md#color) | Yes  | Color in ARGB format. The value of each color channel is an integer ranging from 0 to 255.|
| mode   | [BlendMode](arkts-apis-graphics-drawing-e.md#blendmode)                              | Yes  | Blend mode.|

**Returns**

| Type                       | Description              |
| --------------------------- | ------------------ |
| [ColorFilter](arkts-apis-graphics-drawing-ColorFilter.md) | Color filter.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**Example**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

const color : common2D.Color = { alpha: 255, red: 255, green: 0, blue: 0 };
let colorFilter = drawing.ColorFilter.createBlendModeColorFilter(color, drawing.BlendMode.SRC);
```

## createBlendModeColorFilter<sup>18+</sup>

static createBlendModeColorFilter(color: common2D.Color | number, mode: BlendMode) : ColorFilter

Creates a **ColorFilter** object with a given color and blend mode.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                                                | Mandatory| Description            |
| ------ | ---------------------------------------------------- | ---- | ---------------- |
| color  | [common2D.Color](js-apis-graphics-common2D.md#color) \| number | Yes  | Color, represented by an unsigned integer in hexadecimal ARGB format.|
| mode   | [BlendMode](arkts-apis-graphics-drawing-e.md#blendmode)                              | Yes  | Blend mode.|

**Returns**

| Type                       | Description              |
| --------------------------- | ------------------ |
| [ColorFilter](arkts-apis-graphics-drawing-ColorFilter.md) | Color filter.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let colorFilter = drawing.ColorFilter.createBlendModeColorFilter(0xffff0000, drawing.BlendMode.SRC);
```

## createComposeColorFilter

createComposeColorFilter(outer: ColorFilter, inner: ColorFilter) : ColorFilter

Creates a **ColorFilter** object by combining another two color filters.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type                       | Mandatory| Description                            |
| ------ | --------------------------- | ---- | -------------------------------- |
| outer  | [ColorFilter](arkts-apis-graphics-drawing-ColorFilter.md) | Yes  | Color filter that takes effect later in the new filter.|
| inner  | [ColorFilter](arkts-apis-graphics-drawing-ColorFilter.md) | Yes  | Color filter that takes effect first in the new filter.|

**Returns**

| Type                       | Description              |
| --------------------------- | ------------------ |
| [ColorFilter](arkts-apis-graphics-drawing-ColorFilter.md) | Color filter.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

const color : common2D.Color = { alpha: 255, red: 255, green: 0, blue: 0 };
let colorFilter1 = drawing.ColorFilter.createBlendModeColorFilter(color, drawing.BlendMode.SRC);
let colorFilter2 = drawing.ColorFilter.createBlendModeColorFilter(color, drawing.BlendMode.DST);
let colorFilter = drawing.ColorFilter.createComposeColorFilter(colorFilter1, colorFilter2);
```

## createLinearToSRGBGamma

createLinearToSRGBGamma() : ColorFilter

Creates a **ColorFilter** object that applies the sRGB gamma curve to the RGB channels.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type                       | Description              |
| --------------------------- | ------------------ |
| [ColorFilter](arkts-apis-graphics-drawing-ColorFilter.md) | Color filter.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let colorFilter = drawing.ColorFilter.createLinearToSRGBGamma();
```

## createSRGBGammaToLinear

createSRGBGammaToLinear() : ColorFilter

Creates a **ColorFilter** object that applies the RGB channels to the sRGB gamma curve.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type                       | Description              |
| --------------------------- | ------------------ |
| [ColorFilter](arkts-apis-graphics-drawing-ColorFilter.md) | Color filter.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let colorFilter = drawing.ColorFilter.createSRGBGammaToLinear();
```

## createLumaColorFilter

createLumaColorFilter() : ColorFilter

Creates a **ColorFilter** object that multiplies the luma into the alpha channel and sets the RGB channels to zero.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type                       | Description              |
| --------------------------- | ------------------ |
| [ColorFilter](arkts-apis-graphics-drawing-ColorFilter.md) | Color filter.|

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let colorFilter = drawing.ColorFilter.createLumaColorFilter();
```

## createMatrixColorFilter<sup>12+</sup>

static createMatrixColorFilter(matrix: Array\<number>): ColorFilter

Creates a color filter object with a 4*5 color matrix.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                                        | Mandatory| Description                           |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| matrix | Array\<number> | Yes  | An array of 20 numbers, indicating the 4*5 matrix.                |

**Returns**

| Type                       | Description              |
| --------------------------- | ------------------ |
| [ColorFilter](arkts-apis-graphics-drawing-ColorFilter.md) | Color filter.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let matrix: Array<number> = [
  1, 0, 0, 0, 0,
  0, 1, 0, 0, 0,
  0, 0, 100, 0, 0,
  0, 0, 0, 1, 0
];
let colorFilter = drawing.ColorFilter.createMatrixColorFilter(matrix);
```
## createLightingColorFilter<sup>20+</sup>

static createLightingColorFilter(mutColor: common2D.Color | number, addColor: common2D.Color | number): ColorFilter

Creates a lighting color filter. It multiplies the RGB channel values by one color and then adds another color value. The final output stays between 0 and 255.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                                        | Mandatory| Description                           |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| mutColor | [common2D.Color](js-apis-graphics-common2D.md#color) \| number | Yes  | Color used for multiplication. The value is in the ARGB format, and each color channel is an integer ranging from 0 to 255. If the value is of the number type, it must be an unsigned integer in the hexadecimal ARGB format.|
| addColor | [common2D.Color](js-apis-graphics-common2D.md#color) \| number | Yes  | Color used for addition. The value is in the ARGB format, and each color channel is an integer ranging from 0 to 255. If the value is of the number type, it must be an unsigned integer in the hexadecimal ARGB format.|

**Returns**

| Type                       | Description               |
| --------------------------- | ------------------ |
| [ColorFilter](arkts-apis-graphics-drawing-ColorFilter.md) | **ColorFilter** object created.|

**Example**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';
let mulColor : common2D.Color = { alpha: 0, red: 0, green: 0, blue: 20 };
let addColor : common2D.Color = { alpha: 0, red: 0, green: 0, blue: 125 };
let colorFilter = drawing.ColorFilter.createLightingColorFilter(mulColor, addColor);
```
