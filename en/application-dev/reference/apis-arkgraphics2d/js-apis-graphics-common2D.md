# @ohos.graphics.common2D (Common Data Types of 2D Graphics)

The common2D module defines some common data types in the 2D graphics field.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This module uses the physical pixel unit, px.

## Modules to Import

```ts
import { common2D } from '@kit.ArkGraphics2D';
```

## Color

Describes a color in ARGB format.

**System capability**: SystemCapability.Graphics.Drawing

| Name | Type  | Read-Only| Optional| Description                                    |
| ----- | ------ | ---- | ---- | ---------------------------------------- |
| alpha | number | No  | No  | Alpha component of the color. The value is an integer ranging from 0 to 255.|
| red   | number | No  | No  | Red component of the color. The value is an integer ranging from 0 to 255.|
| green | number | No  | No  | Green component of the color. The value is an integer ranging from 0 to 255.|
| blue  | number | No  | No  | Blue component of the color. The value is an integer ranging from 0 to 255.|

## Rect

Describes a rectangle, which can be defined by two coordinate points: upper left corner point and lower right corner point.

**System capability**: SystemCapability.Graphics.Drawing

| Name  | Type  | Read-Only| Optional| Description                          |
| ------ | ------ | ---- | ---- | ------------------------------ |
| left   | number | No  | No  | X coordinate of the upper left corner of the rectangle. The value is a floating point number.|
| top    | number | No  | No  | Y coordinate of the upper left corner of the rectangle. The value is a floating point number.|
| right  | number | No  | No  | X coordinate of the lower right corner of the rectangle. The value is a floating point number.|
| bottom | number | No  | No  | Y coordinate of the lower right corner of the rectangle. The value is a floating point number.|

## Point<sup>12+</sup>

Describes a coordinate point.

**System capability**: SystemCapability.Graphics.Drawing

| Name  | Type  | Read-Only| Optional| Description                          |
| ------ | ------ | ---- | ---- | ------------------------------ |
| x      | number | No  | No  | Horizontal coordinate. The value is a floating point number.              |
| y      | number | No  | No  | Vertical coordinate. The value is a floating point number.              |

## Color4f<sup>20+</sup>

Describes a color in ARGB format.

**System capability**: SystemCapability.Graphics.Drawing

| Name | Type  | Read-Only| Optional| Description                                    |
| ----- | ------ | ---- | ---- | ---------------------------------------- |
| alpha | number | No  | No  | Alpha component (transparency) of the color. The value is a floating point number ranging from 0.0 to 1.0.|
| red   | number | No  | No  | R component of the color, which is a floating point number ranging from 0.0 to 1.0.|
| green | number | No  | No  | G component of the color, which is a floating point number ranging from 0.0 to 1.0.|
| blue  | number | No  | No  | B component of the color, which is a floating point number ranging from 0.0 to 1.0.|

## Point3d<sup>12+</sup>

Describes a 3D coordinate point. It inherits from [Point](#point12).

**System capability**: SystemCapability.Graphics.Drawing

| Name  | Type  | Read-Only| Optional| Description                          |
| ------ | ------ | ---- | ---- | ------------------------------ |
| z      | number | No  | No  | Z-axis coordinate. The value is a floating point number.              |
