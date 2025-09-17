# Class (RectUtils)

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
> - The initial APIs of this class are supported since API version 20.
>
> - This module uses the physical pixel unit, px.
>
> - This module operates under a single-threaded model. The caller needs to manage thread safety and context state transitions.

This module provides tools for processing rectangles.

Use scenarios:

1. Quickly create rectangles and get their basic features, like making a new rectangle, copying one, and obtaining its width, height, and center point.

2. Calculate and adjust boundaries, such as obtaining the inclusion relationship, calculating and updating intersections and unions between rectangles, and updating boundary values.

## Modules to Import

```ts
import { drawing } from '@kit.ArkGraphics2D';
```

## makeEmpty<sup>20+</sup>

static makeEmpty(): common2D.Rect

Creates a rectangle with the top, bottom, left, and right boundary coordinates all being 0.

**System capability**: SystemCapability.Graphics.Drawing

**Returns**

| Type   | Description                      |
| ------- | ------------------------- |
| [common2D.Rect](js-apis-graphics-common2D.md#rect) | Created rectangle object.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';

let rect = drawing.RectUtils.makeEmpty();
```

## makeLtrb<sup>20+</sup>

static makeLtrb(left: number, top: number, right: number, bottom: number): common2D.Rect

Creates a rectangle with specified top, bottom, left, and right boundaries.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| left   | number | Yes  | X coordinate of the upper left corner of the rectangle. The value is a floating point number. **0** indicates the coordinate origin. A positive value places the point to the right of the coordinate origin, while a negative value places the point to the left.|
| top    | number | Yes  | Y coordinate of the upper left corner of the rectangle. The value is a floating point number. **0** indicates the coordinate origin. A positive value places the point below the coordinate origin, while a negative value places the point above the coordinate origin.|
| right  | number | Yes  | X coordinate of the lower right corner of the rectangle. The value is a floating point number. **0** indicates the coordinate origin. A positive value places the point to the right of the coordinate origin, while a negative value places the point to the left.|
| bottom | number | Yes  | Y coordinate of the lower right corner of the rectangle. The value is a floating point number. **0** indicates the coordinate origin. A positive value places the point below the coordinate origin, while a negative value places the point above the coordinate origin.|

**Returns**

| Type   | Description                      |
| ------- | ------------------------- |
| [common2D.Rect](js-apis-graphics-common2D.md#rect) | Created rectangle.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';

let rect = drawing.RectUtils.makeLtrb(10, 10, 20, 20);
```

## makeCopy<sup>20+</sup>

static makeCopy(src: common2D.Rect): common2D.Rect

Copies a rectangle.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| src   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Rectangle to be copied.|


**Returns**

| Type   | Description                      |
| ------- | ------------------------- |
| [common2D.Rect](js-apis-graphics-common2D.md#rect) | Created rectangle.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(10, 10, 20, 20);
let rect2 = drawing.RectUtils.makeCopy(rect);
console.info('rect2.left:', rect2.left);
console.info('rect2.top: ', rect2.top);
console.info('rect2.right: ', rect2.right);
console.info('rect2.bottom: ', rect2.bottom);
```

## getWidth<sup>20+</sup>

static getWidth(rect: common2D.Rect): number

Obtains the width of a rectangle.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Rectangle object.|


**Returns**

| Type   | Description                      |
| ------- | ------------------------- |
| number | Width of a rectangle. If the left boundary is greater than the right, the width is negative. If the left boundary is less than the right, the width is positive.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(10, 10, 20, 20);
let width = drawing.RectUtils.getWidth(rect);
console.info('width:', width);
```

## getHeight<sup>20+</sup>

static getHeight(rect: common2D.Rect): number

Obtains the height of a rectangle.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Rectangle object.|

**Returns**

| Type   | Description                      |
| ------- | ------------------------- |
| number | Height of the rectangle. If the top boundary is greater than the bottom, the height is negative. If the top boundary is less than the bottom, the height is positive.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(10, 10, 20, 20);
let height = drawing.RectUtils.getHeight(rect);
```

## centerX<sup>20+</sup>

static centerX(rect: common2D.Rect): number

Obtains the X coordinate of the rectangle center.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Rectangle object.|

**Returns**

| Type   | Description                      |
| ------- | ------------------------- |
| number | X coordinate of the rectangle center.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(20, 30, 30, 40);
let x = drawing.RectUtils.centerX(rect);
```

## centerY<sup>20+</sup>

static centerY(rect: common2D.Rect): number

Obtains the Y coordinate of the rectangle center.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Rectangle object.|

**Returns**

| Type   | Description                      |
| ------- | ------------------------- |
| number | Y coordinate of the rectangle center.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(20, 30, 30, 40);
let x = drawing.RectUtils.centerY(rect);
```

## contains<sup>20+</sup>

static contains(rect: common2D.Rect, other: common2D.Rect): boolean

Checks whether a rectangle completely contains another rectangle.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Rectangle object.|
| other   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Another rectangle object.|

**Returns**

| Type   | Description                      |
| ------- | ------------------------- |
| boolean | Check result. **true** means yes; **false** otherwise. An empty rectangle does not contain any other rectangle.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(10, 10, 20, 20);
let rect2 = drawing.RectUtils.makeLtrb(0, 0, 40, 40);
let isContains = drawing.RectUtils.contains(rect2, rect);
console.info('isContains: ', isContains);
```

## contains<sup>20+</sup>

static contains(rect: common2D.Rect, left: number, top: number, right: number, bottom: number): boolean

Checks whether a rectangle completely contains another rectangle (which is marked by the coordinates of the upper left and lower right corners).

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Rectangle object.|
| left   | number | Yes  | X coordinate of the upper left corner of the rectangle. The value is a floating point number. **0** indicates the coordinate origin. A positive value places the point to the right of the coordinate origin, while a negative value places the point to the left.|
| top    | number | Yes  | Y coordinate of the upper left corner of the rectangle. The value is a floating point number. **0** indicates the coordinate origin. A positive value places the point below the coordinate origin, while a negative value places the point above the coordinate origin.|
| right  | number | Yes  | X coordinate of the lower right corner of the rectangle. The value is a floating point number. **0** indicates the coordinate origin. A positive value places the point to the right of the coordinate origin, while a negative value places the point to the left.|
| bottom | number | Yes  | Y coordinate of the lower right corner of the rectangle. The value is a floating point number. **0** indicates the coordinate origin. A positive value places the point below the coordinate origin, while a negative value places the point above the coordinate origin.|

**Returns**

| Type   | Description                      |
| ------- | ------------------------- |
| boolean | Check result. **true** means yes; **false** otherwise. An empty rectangle does not contain any other rectangle.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(0, 0, 100, 100);
let isContains = drawing.RectUtils.contains(rect, 10, 20, 30, 40);
console.info('isContains :', isContains);
```

## contains<sup>20+</sup>

static contains(rect: common2D.Rect, x: number, y: number): boolean

Checks whether a rectangle completely contains a specified point.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Rectangle object.|
| x   | number | Yes  | X coordinate of a point. The value is a floating point number. **0** indicates the coordinate origin. A positive value places the point to the right of the coordinate origin, while a negative value places the point to the left.|
| y    | number | Yes | Y coordinate of a point. The value is a floating point number. **0** indicates the coordinate origin. A positive value places the point below the coordinate origin, while a negative value places the point above the coordinate origin.|

**Returns**

| Type   | Description                      |
| ------- | ------------------------- |
| boolean | Whether the rectangle completely contains the point **(x, y)**. **true** means yes; **false** otherwise.  An empty rectangle does not contain any point.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(0, 0, 100, 100);
let isContains = drawing.RectUtils.contains(rect, 10, 20);
console.info('isContains: ', isContains);
```

## inset<sup>20+</sup>

static inset(rect: common2D.Rect, left: number, top: number, right: number, bottom: number): void

Adds the values of the left, top, right, and bottom boundaries of a specified rectangle to the input values of the left, top, right, and bottom boundaries, respectively.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Rectangle object.|
| left   | number | Yes  | Value to be added to the left boundary of the rectangle (X coordinate of the upper left corner of the rectangle). The value is a floating point number. 0 indicates that no operation is performed. A positive number indicates addition, and a negative number indicates subtraction.|
| top    | number | Yes  | Value to be added to the top boundary of the rectangle (Y coordinate of the upper left corner of the rectangle). The value is a floating point number. 0 indicates that no operation is performed. A positive number indicates addition, and a negative number indicates subtraction.|
| right  | number | Yes  | Value to be added to the right boundary of the rectangle (X coordinate of the lower right corner of the rectangle). The value is a floating point number. 0 indicates that no operation is performed. A positive number indicates addition, and a negative number indicates subtraction.|
| bottom | number | Yes  | Value to be added to the bottom boundary of the rectangle (Y coordinate of the lower right corner of the rectangle). The value is a floating point number. 0 indicates that no operation is performed. A positive number indicates addition, and a negative number indicates subtraction.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(10, 10, 20, 20);
drawing.RectUtils.inset(rect, 10, -20, 30, 60);
console.info('rect.left:', rect.left);
console.info('rect.top: ', rect.top);
console.info('rect.right: ', rect.right);
console.info('rect.bottom: ', rect.bottom);
```

## intersect<sup>20+</sup>

static intersect(rect: common2D.Rect, other: common2D.Rect): boolean

Calculates the intersection of two rectangles and updates the intersection result to the rectangle represented by the first input parameter.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Original rectangle used to calculate the intersection.|
| other   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes | Another rectangle used to calculate the intersection.|

**Returns**

| Type   | Description                      |
| ------- | ------------------------- |
| boolean |  Whether two rectangles have an intersection. **true** means yes; **false** otherwise.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(0, 0, 20, 20);
let rect2 = drawing.RectUtils.makeLtrb(10, 10, 40, 40);
let isIntersect = drawing.RectUtils.intersect(rect, rect2);
console.info('isIntersect :', isIntersect);
console.info('rect.left:', rect.left);
console.info('rect.top: ', rect.top);
console.info('rect.right: ', rect.right);
console.info('rect.bottom: ', rect.bottom);
```

## isIntersect<sup>20+</sup>

static isIntersect(rect: common2D.Rect, other: common2D.Rect): boolean

Checks whether two rectangles intersect.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Original rectangle used to calculate the intersection.|
| other   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes | Another rectangle used to calculate the intersection.|

**Returns**

| Type   | Description                      |
| ------- | ------------------------- |
| boolean |  Whether two rectangles have an intersection. **true** means yes; **false** otherwise. If the two rectangles only overlap on the edge or intersect at a point, **false** is returned.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(0, 0, 20, 20);
let rect2 = drawing.RectUtils.makeLtrb(10, 10, 40, 40);
let isIntersect = drawing.RectUtils.isIntersect(rect, rect2);
console.info('isIntersect :', isIntersect);
```

## union<sup>20+</sup>

static union(rect: common2D.Rect, other: common2D.Rect): void

Calculates the union of two rectangles and updates the union result to the rectangle represented by the first input parameter. If the first input parameter is empty, the union result is updated to the rectangle represented by the second input parameter. If the second input parameter is empty, no operation is performed.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Original rectangle used to calculate the union.|
| other   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes | Another rectangle used to calculate the union.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(0, 0, 20, 20);
let rect2 = drawing.RectUtils.makeLtrb(10, 10, 40, 40);
drawing.RectUtils.union(rect, rect2);
console.info('rect.left:', rect.left);
console.info('rect.top: ', rect.top);
console.info('rect.right: ', rect.right);
console.info('rect.bottom: ', rect.bottom);
```

## isEmpty<sup>20+</sup>

static isEmpty(rect: common2D.Rect): boolean

Checks whether a rectangle is empty (the left boundary is greater than or equal to the right boundary or the top boundary is greater than or equal to the bottom boundary).

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description           |
| ------ | ------ | ---- | --------------  |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Rectangle object to be checked.|

**Returns**

| Type   | Description                      |
| ------- | ------------------------- |
| boolean | Whether the rectangle is empty. **true** means yes; **false** otherwise.      |

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeEmpty();
let isEmpty = drawing.RectUtils.isEmpty(rect);
console.info('isEmpty :', isEmpty);
let rect2 = drawing.RectUtils.makeLtrb(0, 0, 20, 20);
isEmpty = drawing.RectUtils.isEmpty(rect2);
console.info('isEmpty :', isEmpty);
```

## offset<sup>20+</sup>

static offset(rect: common2D.Rect, dx: number, dy: number): void

Translates a rectangle.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Rectangle to be translated.|
| dx   | number | Yes   | Horizontal translation distance. The value is a floating point number. 0 indicates no translation. A negative value indicates translation to the left, and a positive value indicates translation to the right.|
| dy    | number | Yes  | Vertical translation distance. The value is a floating point number. 0 indicates no translation. A negative value indicates translation upwards, and a positive value indicates translation downwards.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(0, 0, 20, 20);
drawing.RectUtils.offset(rect, 10, 20);
console.info('rect.left:', rect.left);
console.info('rect.top: ', rect.top);
console.info('rect.right: ', rect.right);
console.info('rect.bottom: ', rect.bottom);
```

## offsetTo<sup>20+</sup>

static offsetTo(rect: common2D.Rect, newLeft: number, newTop: number): void

Translates a rectangle to a specified position.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Rectangle to be translated.|
| newLeft   | number | Yes  | X coordinate of the position to which the rectangle is translated. The value is a floating point number. **0** indicates the coordinate origin. A positive value places the point to the right of the coordinate origin, while a negative value places the point to the left.|
| newTop    | number | Yes  | Y coordinate of the position to which the rectangle is translated. The value is a floating point number. **0** indicates the coordinate origin. A positive value places the point below the coordinate origin, while a negative value places the point above the coordinate origin.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(20, 20, 40, 40);
drawing.RectUtils.offsetTo(rect, 10, 20);
console.info('rect.left:', rect.left);
console.info('rect.top: ', rect.top);
console.info('rect.right: ', rect.right);
console.info('rect.bottom: ', rect.bottom);
```

## setRect<sup>20+</sup>

static setRect(rect: common2D.Rect, other: common2D.Rect): void

Assigns the existing rectangle with another rectangle.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  |  Original rectangle.|
| other   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Another rectangle.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(10, 20, 30, 40);
let rect2 = drawing.RectUtils.makeEmpty();
drawing.RectUtils.setRect(rect2, rect);
console.info('rect2.left:', rect2.left);
console.info('rect2.top: ', rect2.top);
console.info('rect2.right: ', rect2.right);
console.info('rect2.bottom: ', rect2.bottom);
```

## setLtrb<sup>20+</sup>

static setLtrb(rect: common2D.Rect, left: number, top: number, right: number, bottom: number): void

Updates the top, bottom, left, and right boundary values of the existing rectangle using the input values of top, bottom, left, and right.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Rectangle object.|
| left   | number | Yes  | X coordinate of the upper left corner of the rectangle. The value is a floating point number. **0** indicates the coordinate origin. A positive value places the point to the right of the coordinate origin, while a negative value places the point to the left.|
| top    | number | Yes  | Y coordinate of the upper left corner of the rectangle. The value is a floating point number. **0** indicates the coordinate origin. A positive value places the point below the coordinate origin, while a negative value places the point above the coordinate origin.|
| right  | number | Yes  | X coordinate of the lower right corner of the rectangle. The value is a floating point number. **0** indicates the coordinate origin. A positive value places the point to the right of the coordinate origin, while a negative value places the point to the left.|
| bottom | number | Yes  | Y coordinate of the lower right corner of the rectangle. The value is a floating point number. **0** indicates the coordinate origin. A positive value places the point below the coordinate origin, while a negative value places the point above the coordinate origin.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeEmpty();
drawing.RectUtils.setLtrb(rect, 10, 20, 30, 60);
console.info('rect.left:', rect.left);
console.info('rect.top: ', rect.top);
console.info('rect.right: ', rect.right);
console.info('rect.bottom: ', rect.bottom);
```

## setEmpty<sup>20+</sup>

static setEmpty(rect: common2D.Rect): void

Sets the left, right, top, and bottom boundaries of the rectangle to **0**.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description           |
| ------ | ------ | ---- | --------------  |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Empty rectangle object.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(10, 20, 20, 30);
drawing.RectUtils.setEmpty(rect)
console.info('rect.left:', rect.left);
console.info('rect.top: ', rect.top);
console.info('rect.right: ', rect.right);
console.info('rect.bottom: ', rect.bottom);
```

## sort<sup>20+</sup>

static sort(rect: common2D.Rect): void

If the rectangle is reversed (that is, the left boundary is greater than the right boundary or the top boundary is greater than the bottom boundary), the top and bottom (left and right) boundary values of the rectangle are exchanged, so that the top boundary is less than the bottom boundary (the left boundary is less than the right boundary).

If the rectangle is not reversed (that is, the left boundary is less than or equal to the right boundary or the top boundary is less than or equal to the bottom boundary), no operation is performed.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description           |
| ------ | ------ | ---- | --------------  |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Rectangle object.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(20, 40, 30, 30);
drawing.RectUtils.sort(rect);
console.info('rect.left:', rect.left);
console.info('rect.top: ', rect.top);
console.info('rect.right: ', rect.right);
console.info('rect.bottom: ', rect.bottom);
```

## isEqual<sup>20+</sup>

static isEqual(rect: common2D.Rect, other: common2D.Rect): boolean

Checks whether two rectangles are equal.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**

| Name| Type   | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| rect   | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes   | Original rectangle.|
| other  | [common2D.Rect](js-apis-graphics-common2D.md#rect) | Yes  | Another rectangle.|

**Returns**

| Type   | Description                      |
| ------- | ------------------------- |
| boolean | Whether two rectangles are equal. **true** means yes; **false** otherwise.|

**Example**

```ts
import { drawing, common2D } from '@kit.ArkGraphics2D';
let rect = drawing.RectUtils.makeLtrb(10, 20, 20, 30);
let rect2 = drawing.RectUtils.makeEmpty();
let isEqual = drawing.RectUtils.isEqual(rect, rect2);
console.info('isEqual :', isEqual);
```
