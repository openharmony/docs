# Class (RoundRect)

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

Rounded rectangle.

## Modules to Import

```ts
import { drawing } from '@kit.ArkGraphics2D';
```

## constructor<sup>20+</sup>

constructor(roundRect: RoundRect)

Copies a rounded rectangle.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name        | Type                                      | Mandatory  | Description                 |
| ----------- | ---------------------------------------- | ---- | ------------------- |
| roundRect        | [RoundRect](arkts-apis-graphics-drawing-RoundRect.md) | Yes   |  Rounded rectangle to be copied.  |

**Example**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

let rect: common2D.Rect = {left : 100, top : 100, right : 500, bottom : 300};
let roundRect = new drawing.RoundRect(rect, 50, 50);
let roundRect2 = new drawing.RoundRect(roundRect);
```

## constructor<sup>12+</sup>

constructor(rect: common2D.Rect, xRadii: number, yRadii: number)

A constructor used to create a **RoundRect** object. A rounded rectangle is created when both **xRadii** and **yRadii** are greater than 0. Otherwise, only a rectangle is created.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name        | Type                                      | Mandatory  | Description                 |
| ----------- | ---------------------------------------- | ---- | ------------------- |
| rect        | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes   | Rectangle that encloses the rounded rectangle to create.     |
| xRadii        | number                  | Yes   | Radius of the rounded corner on the X axis. The value is a floating point number. A negative number is invalid.    |
| yRadii        | number                  | Yes   | Radius of the rounded corner on the Y axis. The value is a floating point number. A negative number is invalid.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { common2D, drawing } from '@kit.ArkGraphics2D';

let rect: common2D.Rect = {left : 100, top : 100, right : 500, bottom : 300};
let roundRect = new drawing.RoundRect(rect, 50, 50);
```
## setCorner<sup>12+</sup>

setCorner(pos: CornerPos, x: number, y: number): void

Sets the radii of the specified rounded corner in this rounded rectangle.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                                        | Mandatory| Description                           |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| pos | [CornerPos](arkts-apis-graphics-drawing-e.md#cornerpos12) | Yes  | Position of the rounded corner.                |
| x     | number                 | Yes  | Radius of the rounded corner on the X axis. The value is a floating point number. A negative number is invalid.|
| y     | number      | Yes  | Radius of the rounded corner on the Y axis. The value is a floating point number. A negative number is invalid.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let roundRect : drawing.RoundRect = new drawing.RoundRect({left: 0, top: 0, right: 300, bottom: 300}, 50, 50);
roundRect.setCorner(drawing.CornerPos.TOP_LEFT_POS, 150, 150);
```

## getCorner<sup>12+</sup>

getCorner(pos: CornerPos): common2D.Point

Obtains the radii of the specified rounded corner in this rounded rectangle.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                                        | Mandatory| Description                           |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| pos | [CornerPos](arkts-apis-graphics-drawing-e.md#cornerpos12) | Yes  | Position of the rounded corner.                |

**Returns**

| Type                 | Description          |
| --------------------- | -------------- |
| [common2D.Point](js-apis-graphics-common2D.md#point12)  | Point. The horizontal coordinate indicates the radius of the rounded corner on the X axis, and the vertical coordinate indicates the radius on the Y axis.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types;3.Parameter verification failed. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let roundRect : drawing.RoundRect = new drawing.RoundRect({left: 0, top: 0, right: 300, bottom: 300}, 50, 50);
let cornerRadius = roundRect.getCorner(drawing.CornerPos.BOTTOM_LEFT_POS);
console.info("getCorner---"+cornerRadius.x)
console.info("getCorner---"+cornerRadius.y)
```

## offset<sup>12+</sup>

offset(dx: number, dy: number): void

Translates this rounded rectangle by an offset along the X axis and Y axis.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name  | Type                                        | Mandatory| Description                           |
| -------- | -------------------------------------------- | ---- | ------------------------------- |
| dx | number | Yes  | Horizontal distance to translate. A positive number indicates a translation towards the positive direction of the X axis, and a negative number indicates a translation towards the negative direction of the X axis. The value is a floating point number.                |
| dy | number | Yes  | Vertical distance to translate. A positive number indicates a translation towards the positive direction of the Y axis, and a negative number indicates a translation towards the negative direction of the Y axis. The value is a floating point number.                |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error.Possible causes:1.Mandatory parameters are left unspecified;2.Incorrect parameter types. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let roundRect : drawing.RoundRect = new drawing.RoundRect({left: 0, top: 0, right: 300, bottom: 300}, 50, 50);
roundRect.offset(100, 100);
```
