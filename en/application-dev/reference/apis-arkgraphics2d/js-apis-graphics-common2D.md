# @ohos.graphics.common2D (Common Data Types of 2D Graphics)

The common2D module defines some common data types in the 2D graphics field.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { common2D } from '@kit.ArkGraphics2D';
```

## Color

Describes a color in ARGB format.

**System capability**: SystemCapability.Graphics.Drawing

| Name | Type  | Readable | Writable | Description                                    |
| ----- | ------ | ---- | ---- | ---------------------------------------- |
| alpha | number | Yes  | Yes  | Alpha component of the color. The value is an integer ranging from 0 to 255. |
| red   | number | Yes  | Yes  | Red component of the color. The value is an integer ranging from 0 to 255. |
| green | number | Yes  | Yes  | Green component of the color. The value is an integer ranging from 0 to 255. |
| blue  | number | Yes  | Yes  | Blue component of the color. The value is an integer ranging from 0 to 255. |

## Rect

Describes a rectangle, which can be defined by two coordinate points: upper left corner point and lower right corner point.

**System capability**: SystemCapability.Graphics.Drawing

| Name  | Type  | Readable | Writable | Description                          |
| ------ | ------ | ---- | ---- | ------------------------------ |
| left   | number | Yes  | Yes  | X coordinate of the upper left corner of the rectangle. The value is a floating point number. |
| top    | number | Yes  | Yes  | Y coordinate of the upper left corner of the rectangle. The value is a floating point number. |
| right  | number | Yes  | Yes  | X coordinate of the lower right corner of the rectangle. The value is a floating point number. |
| bottom | number | Yes  | Yes  | Y coordinate of the lower right corner of the rectangle. The value is a floating point number. |

## Point<sup>12+</sup>

Describes a coordinate point.

**System capability**: SystemCapability.Graphics.Drawing

| Name  | Type  | Readable | Writable | Description                          |
| ------ | ------ | ---- | ---- | ------------------------------ |
| x      | number | Yes  | Yes  | Horizontal coordinate. The value is a floating point number.              |
| y      | number | Yes  | Yes  | Vertical coordinate. The value is a floating point number.              |

## Point3d<sup>12+</sup>

Describes a 3D coordinate point. It inherits from [Point](#point12).

**System capability**: SystemCapability.Graphics.Drawing

| Name  | Type  | Readable | Writable | Description                          |
| ------ | ------ | ---- | ---- | ------------------------------ |
| z      | number | Yes  | Yes  | Z-axis coordinate. The value is a floating point number.              |
