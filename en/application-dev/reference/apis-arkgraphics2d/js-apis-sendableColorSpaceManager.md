# @ohos.graphics.sendableColorSpaceManager (Sendable Color Space Management)

The **sendableColorSpaceManager** module provides APIs for creating and managing sendable color space objects and obtaining basic attributes of sendable color spaces.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { sendableColorSpaceManager } from '@kit.ArkGraphics2D';
```

## ISendable
type ISendable = lang.ISendable

**ISendable** is the parent type of all sendable types except null and undefined. It does not have any necessary methods or properties.

**System capability**: SystemCapability.Utils.Lang

| Type               | Description                    |
| ------------------ | ------------------------ |
| [lang.ISendable](../apis-arkts/js-apis-arkts-lang.md#langisendable)  | Parent type of all sendable types.              |

## sendableColorSpaceManager.create

create(colorSpaceName: colorSpaceManager.ColorSpace): ColorSpaceManager

Creates a standard color space object that is sendable.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Parameters**

| Name          | Type                    | Mandatory | Description                         |
| --------------- | ------------------------ | ---- | -----------------------------|
| colorSpaceName  | [colorSpaceManager.ColorSpace](js-apis-colorSpaceManager.md#colorspace)| Yes  | Type of the color space.<br>**UNKNOWN** and **CUSTOM** cannot be used when creating standard color space objects.      |

**Return value**

| Type               | Description                    |
| ------------------ | ------------------------ |
| [ColorSpaceManager](#colorspacemanager)  | Sendable color space object created.<br>This instance inherits from **ISendable** and can be passed by reference between concurrent ArkTS instances (including the main thread and the worker threads of TaskPool or Worker). For details, see [When to Use](../../arkts-utils/arkts-sendable.md#when-to-use).                |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [colorSpaceManager Error Codes](errorcode-colorspace-manager.md).

| ID | Error Message |
| ------- | ----------------------- |
| 401 | Parameter error. Possible cause: 1.Incorrect parameter type. 2.Parameter verification failed.|
| 18600001 | The parameter value is abnormal. |

**Example**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';
let colorSpace: sendableColorSpaceManager.ColorSpaceManager;
colorSpace = sendableColorSpaceManager.create(colorSpaceManager.ColorSpace.SRGB);
```

## sendableColorSpaceManager.create

create(primaries: colorSpaceManager.ColorSpacePrimaries, gamma: number): ColorSpaceManager

Creates a custom color space object that is sendable.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Parameters**

| Name          | Type                                      | Mandatory | Description                         |
| --------------- | ------------------------------------------ | ---- | -----------------------------|
| primaries       | [colorSpaceManager.ColorSpacePrimaries](js-apis-colorSpaceManager.md#colorspaceprimaries)| Yes  | Primaries of the color space.              |
| gamma           | number                                     | Yes  | Gamma of the color space.                |

**Return value**

| Type               | Description                    |
| ------------------ | ------------------------ |
| [ColorSpaceManager](#colorspacemanager)  | Sendable color space object created.<br>The color space type is **CUSTOM**, which is one of the enumerated values of [colorSpaceManager.ColorSpace](js-apis-colorSpaceManager.md#colorspace).<br>This instance inherits from **ISendable** and can be passed by reference between concurrent ArkTS instances (including the main thread and the worker threads of TaskPool or Worker). For details, see [When to Use](../../arkts-utils/arkts-sendable.md#when-to-use). |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [colorSpaceManager Error Codes](errorcode-colorspace-manager.md).

| ID | Error Message |
| ------- | ----------------------- |
| 401 | Parameter error. Possible cause: 1.Incorrect parameter type. 2.Parameter verification failed.|
| 18600001 | The parameter value is abnormal. |

**Example**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';
let colorSpace: sendableColorSpaceManager.ColorSpaceManager;
let primaries: colorSpaceManager.ColorSpacePrimaries = {
  redX: 0.1,
  redY: 0.1,
  greenX: 0.2,
  greenY: 0.2,
  blueX: 0.3,
  blueY: 0.3,
  whitePointX: 0.4,
  whitePointY: 0.4
};
let gamma: number = 2.2;
colorSpace = sendableColorSpaceManager.create(primaries, gamma);
```

## ColorSpaceManager

Implements management of color space objects.

Before calling any of the following APIs, you must use [create()](#sendablecolorspacemanagercreate) to create a color space manager.

### getColorSpaceName

getColorSpaceName(): colorSpaceManager.ColorSpace

Obtains the color space type.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Return value**

| Type               | Description                    |
| ------------------ | ------------------------ |
| [colorSpaceManager.ColorSpace](js-apis-colorSpaceManager.md#colorspace)  | Color space type. |

**Error codes**

For details about the error codes, see [colorSpaceManager Error Codes](errorcode-colorspace-manager.md).

| ID | Error Message |
| ------- | ----------------------- |
| 18600001 | The parameter value is abnormal. |

**Example**

```ts
let spaceName: colorSpaceManager.ColorSpace = colorSpace.getColorSpaceName();
```

### getWhitePoint

getWhitePoint(): collections.Array\<number\>

Obtains the coordinates of the white point in the color space.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Return value**

| Type               | Description                    |
| ------------------ | ------------------------ |
| [collections.Array\<number\>](../apis-arkts/js-apis-arkts-collections.md#collectionsarray)  | Coordinates [x, y] of the white point. |

**Error codes**

For details about the error codes, see [colorSpaceManager Error Codes](errorcode-colorspace-manager.md).

| ID | Error Message |
| ------- | ----------------------- |
| 18600001 | The parameter value is abnormal. |

**Example**

```ts
import { collections } from '@kit.ArkTS';
let point: collections.Array<number> = colorSpace.getWhitePoint();
```

### getGamma

getGamma(): number

Obtains the gamma of the color space.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Return value**

| Type               | Description                    |
| ------------------ | ------------------------ |
| number  | Gamma of the color space. |

**Error codes**

For details about the error codes, see [colorSpaceManager Error Codes](errorcode-colorspace-manager.md).

| ID | Error Message |
| ------- | ----------------------- |
| 18600001 | The parameter value is abnormal. |

**Example**

```ts
let gamma: number = colorSpace.getGamma();
```
