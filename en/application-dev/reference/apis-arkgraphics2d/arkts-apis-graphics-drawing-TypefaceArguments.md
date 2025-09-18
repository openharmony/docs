# Class (TypefaceArguments)

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
> - The module operates under a single-threaded model. The caller needs to manage thread safety and context state transitions.

This module defines a struct for setting typeface arguments.

## Modules to Import

```ts
import { drawing } from '@kit.ArkGraphics2D';
```

## constructor<sup>20+</sup>

constructor()

Constructor for typeface arguments.

**System capability**: SystemCapability.Graphics.Drawing

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';
let typeFaceArgument = new drawing.TypefaceArguments();
```

## addVariation<sup>20+</sup>

addVariation(axis: string, value: number)

Defines the typeface weight.

**System capability**: SystemCapability.Graphics.Drawing

**Parameters**
| Name        | Type                                      | Mandatory  | Description            |
| ----------- | ---------------------------------------- | ---- | -------------------   |
| axis  | string           | Yes  | The **'wght'** tag for the weight variation in the **typeFaceArgument** object. Whether the tag is supported depends on the loaded typeface file. For details, check the typeface file.  |
| value | number           | Yes  | Value linked to the **'wght'** tag for the weight variation in the **typeFaceArgument** object. The value must be within the range defined in the typeface file. Otherwise, the value does not take effect. Values below the minimum will be set to the minimum and values above the maximum to the maximum. For details, check the typeface file.   |

**Error codes**

For details about the following error code, see [Drawing and Display Error Codes](../apis-arkgraphics2d/errorcode-drawing.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 25900001 | Parameter error.Possible causes: Incorrect parameter range. |

**Example**

```ts
import { drawing } from '@kit.ArkGraphics2D';

let typeFaceArgument = new drawing.TypefaceArguments();
typeFaceArgument.addVariation('wght', 10);
```
