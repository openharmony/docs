# Class (ShadowLayer)

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

Implements a shadow layer.

## Modules to Import

```ts
import { drawing } from '@kit.ArkGraphics2D';
```

## create<sup>12+</sup>

static create(blurRadius: number, x: number, y: number, color: common2D.Color): ShadowLayer

Creates a **ShadowLayer** object.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name    | Type     | Mandatory| Description                                |
| ---------- | -------- | ---- | ----------------------------------- |
| blurRadius  | number   | Yes  | Radius of the shadow layer. The value must be a floating point number greater than 0.    |
| x           | number   | Yes  | Offset on the X axis. The value is a floating point number.       |
| y           | number   | Yes  | Offset on the Y axis. The value is a floating point number.       |
| color       | [common2D.Color](js-apis-graphics-common2D.md#color) | Yes  | Color in ARGB format. The value of each color channel is an integer ranging from 0 to 255.|

**Returns**

| Type                       | Description                 |
| --------------------------- | -------------------- |
| [ShadowLayer](arkts-apis-graphics-drawing-ShadowLayer.md) | **ShadowLayer** object created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**Example**

```ts
import { RenderNode } from '@kit.ArkUI';
import { common2D, drawing } from '@kit.ArkGraphics2D';

class DrawingRenderNode extends RenderNode {
  draw(context : DrawContext) {
    const canvas = context.canvas;
    let color : common2D.Color = {alpha: 0xFF, red: 0x00, green: 0xFF, blue: 0x00};
    let shadowLayer = drawing.ShadowLayer.create(3, -3, 3, color);
  }
}
```

## create<sup>18+</sup>

static create(blurRadius: number, x: number, y: number, color: common2D.Color | number): ShadowLayer

Creates a **ShadowLayer** object.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name    | Type     | Mandatory| Description                                |
| ---------- | -------- | ---- | ----------------------------------- |
| blurRadius  | number   | Yes  | Radius of the shadow layer. The value must be a floating point number greater than 0.    |
| x           | number   | Yes  | Offset on the X axis. The value is a floating point number.       |
| y           | number   | Yes  | Offset on the Y axis. The value is a floating point number.       |
| color       | [common2D.Color](js-apis-graphics-common2D.md#color) \| number   | Yes  | Color, represented by an unsigned integer in hexadecimal ARGB format. |

**Returns**

| Type                       | Description                 |
| --------------------------- | -------------------- |
| [ShadowLayer](arkts-apis-graphics-drawing-ShadowLayer.md) | **ShadowLayer** object created.|

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
    let shadowLayer = drawing.ShadowLayer.create(3, -3, 3, 0xff00ff00);
  }
}
```
