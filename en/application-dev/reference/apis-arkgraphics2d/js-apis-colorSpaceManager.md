# @ohos.graphics.colorSpaceManager (Color Space Management)

The **colorSpaceManager** module provides APIs for creating and managing color space objects and obtaining basic color space attributes.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';
```

## ColorSpace

Enumerates the color space types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

| Name                        | Value    | Description                   |
| --------------------------- | ------ | ----------------------- |
| UNKNOWN                           | 0      | Unknown type.|
| ADOBE_RGB_1998                    | 1      | Adobe RGB (1998).<br>The conversion function is of the Adobe RGB (1998) type.<br>The encoding range is of the Full type. |
| DCI_P3                            | 2      | DCI-P3.<br>The conversion function is of the Gamma 2.6 type.<br>The encoding range is of the Full type.|
| DISPLAY_P3                        | 3      | Display P3.<br>The conversion function is of the SRGB type.<br>The encoding range is of the Full type. |
| SRGB                              | 4      | SRGB.<br>The conversion function is of the SRGB type.<br>The encoding range is of the Full type.<br>This is the default color space type. |
| CUSTOM                            | 5      | Custom type.|
| BT709<sup>11+</sup>                | 6      | BT709.<br>The conversion function is of the BT709 type.<br>The encoding range is of the Full type. |
| BT601_EBU<sup>11+</sup>            | 7      | BT601_P.<br>The conversion function is of the BT709 type.<br>The encoding range is of the Full type. |
| BT601_SMPTE_C<sup>11+</sup>        | 8      | BT601_N.<br>The conversion function is of the BT709 type.<br>The encoding range is of the Full type. |
| BT2020_HLG<sup>11+</sup>           | 9      | BT2020.<br>The conversion function is of the HLG type.<br>The encoding range is of the Full type. |
| BT2020_PQ<sup>11+</sup>            | 10     | BT2020.<br>The conversion function is of the PQ type.<br>The encoding range is of the Full type. |
| P3_HLG<sup>11+</sup>               | 11     | Display P3.<br>The conversion function is of the HLG type.<br>The encoding range is of the Full type. |
| P3_PQ<sup>11+</sup>                | 12     | Display P3.<br>The conversion function is of the PQ type.<br>The encoding range is of the Full type. |
| ADOBE_RGB_1998_LIMIT<sup>11+</sup> | 13     | Adobe RGB (1998).<br>The conversion function is of the Adobe RGB (1998) type.<br>The encoding range is of the Limit type. |
| DISPLAY_P3_LIMIT<sup>11+</sup>     | 14     | Display P3.<br>The conversion function is of the SRGB type.<br>The encoding range is of the Limit type. |
| SRGB_LIMIT<sup>11+</sup>           | 15     | SRGB.<br>The conversion function is of the SRGB type.<br>The encoding range is of the Limit type. |
| BT709_LIMIT<sup>11+</sup>          | 16     | BT709.<br>The conversion function is of the BT709 type.<br>The encoding range is of the Limit type. |
| BT601_EBU_LIMIT<sup>11+</sup>      | 17     | BT601_P.<br>The conversion function is of the BT709 type.<br>The encoding range is of the Limit type. |
| BT601_SMPTE_C_LIMIT<sup>11+</sup>  | 18     | BT601_N.<br>The conversion function is of the BT709 type.<br>The encoding range is of the Limit type. |
| BT2020_HLG_LIMIT<sup>11+</sup>     | 19     | BT2020.<br>The conversion function is of the HLG type.<br>The encoding range is of the Limit type. |
| BT2020_PQ_LIMIT<sup>11+</sup>      | 20     | BT2020.<br>The conversion function is of the PQ type.<br>The encoding range is of the Limit type. |
| P3_HLG_LIMIT<sup>11+</sup>         | 21     | Display P3.<br>The conversion function is of the HLG type.<br>The encoding range is of the Limit type. |
| P3_PQ_LIMIT<sup>11+</sup>          | 22     | Display P3.<br>The conversion function is of the PQ type.<br>The encoding range is of the Limit type. |
| LINEAR_P3<sup>11+</sup>            | 23     | Display P3.<br>The conversion function is of the Linear type. |
| LINEAR_SRGB<sup>11+</sup>          | 24     | SRGB.<br>The conversion function is of the Linear type. |
| LINEAR_BT709<sup>11+</sup>         | 24     | Same as that of LINEAR_SRGB.<br>BT709.<br>The conversion function is of the Linear type. |
| LINEAR_BT2020<sup>11+</sup>        | 25     | BT2020.<br>The conversion function is of the Linear type. |
| DISPLAY_SRGB<sup>11+</sup>         | 4      | Same as that of SRGB.<br>SRGB.<br>The conversion function is of the SRGB type.<br>The encoding range is of the Full type. |
| DISPLAY_P3_SRGB<sup>11+</sup>      | 3      | Same as that of DISPLAY_P3.<br>Display P3.<br>The conversion function is of the SRGB type.<br>The encoding range is of the Full type. |
| DISPLAY_P3_HLG<sup>11+</sup>       | 11     | Same as that of P3_HLG.<br>Display P3.<br>The conversion function is of the HLG type.<br>The encoding range is of the Full type. |
| DISPLAY_P3_PQ<sup>11+</sup>        | 12     | Same as that of P3_PQ.<br>Display P3.<br>The conversion function is of the PQ type.<br>The encoding range is of the Full type. |

## ColorSpacePrimaries

Defines the color space primaries. A color space is defined by chromaticity coordinates of the red, green, and blue additive primaries, the white point, and the gamma.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

| Name                         | Type | Readable | Writable | Description                                                        |
| ---------------------------- | -------- | ---- | ---- | ----------------------------------------------------- |
| redX                         | number   | Yes  | Yes  | X coordinate of the red color in the color space. |
| redY                         | number   | Yes  | Yes  | Y coordinate of the red color in the color space. |
| greenX                       | number   | Yes  | Yes  | X coordinate of the green color in the color space. |
| greenY                       | number   | Yes  | Yes  | Y coordinate of the green color in the color space. |
| blueX                        | number   | Yes  | Yes  | X coordinate of the blue color in the color space. |
| blueY                        | number   | Yes  | Yes  | Y coordinate of the blue color in the color space. |
| whitePointX                  | number   | Yes  | Yes  | X coordinate of the white point in the color space. |
| whitePointY                  | number   | Yes  | Yes  | Y coordinate of the white point in the color space. |

## colorSpaceManager.create

create(colorSpaceName: ColorSpace): ColorSpaceManager

Creates a standard color space object.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Parameters**

| Parameter          | Type                    | Mandatory | Description                         |
| --------------- | ------------------------ | ---- | -----------------------------|
| colorSpaceName  | [ColorSpace](#colorspace)| Yes  | Type of the color space.<br>**UNKNOWN** and **CUSTOM** cannot be used when creating standard color space objects.         |

**Return value**

| Type               | Description                    |
| ------------------ | ------------------------ |
| [ColorSpaceManager](#colorspacemanager)  | Color space object created.              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [colorSpaceManager Error Codes](errorcode-colorspace-manager.md).

| ID | Error Message |
| ------- | ----------------------- |
| 401 | Parameter error. Possible cause: 1.Incorrect parameter type. 2.Parameter verification failed.|
| 18600001 | The parameter value is abnormal. |

**Example**

```ts
let colorSpace: colorSpaceManager.ColorSpaceManager;
try {
    colorSpace = colorSpaceManager.create(colorSpaceManager.ColorSpace.SRGB);
} catch (err) {
    console.log(`Failed to create SRGB colorSpace. Cause: ` + JSON.stringify(err));
}
```

## colorSpaceManager.create

create(primaries: ColorSpacePrimaries, gamma: number): ColorSpaceManager

Creates a custom color space object.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Parameters**

| Parameter          | Type                                      | Mandatory | Description                         |
| --------------- | ------------------------------------------ | ---- | -----------------------------|
| primaries       | [ColorSpacePrimaries](#colorspaceprimaries)| Yes  | Primaries of the color space.              |
| gamma           | number                                     | Yes  | Gamma of the color space.                |

**Return value**

| Type               | Description                    |
| ------------------ | ------------------------ |
| [ColorSpaceManager](#colorspacemanager)  | Color space object created.<br>The color space type is **CUSTOM** of [ColorSpace](#colorspace). |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [colorSpaceManager Error Codes](errorcode-colorspace-manager.md).

| ID | Error Message |
| ------- | ----------------------- |
| 401 | Parameter error. Possible cause: 1.Incorrect parameter type. 2.Parameter verification failed.|
| 18600001 | The parameter value is abnormal. |

**Example**

```ts
let colorSpace: colorSpaceManager.ColorSpaceManager;
try {
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
    let gamma = 2.2;
    colorSpace = colorSpaceManager.create(primaries, gamma);
} catch (err) {
    console.log(`Failed to create colorSpace with customized primaries and gamma. Cause: ` + JSON.stringify(err));
}
```

## ColorSpaceManager

Implements management of color space objects.

Before calling any of the following APIs, you must use [create()](#colorspacemanagercreate) to create a color space manager.

### getColorSpaceName

getColorSpaceName(): ColorSpace

Obtains the color space type.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Return value**

| Type               | Description                    |
| ------------------ | ------------------------ |
| [ColorSpace](#colorspace)  | Color space type. |

**Error codes**

For details about the error codes, see [colorSpaceManager Error Codes](errorcode-colorspace-manager.md).

| ID | Error Message |
| ------- | ----------------------- |
| 18600001 | The parameter value is abnormal. |

**Example**

```ts
try {
    let spaceName = colorSpace.getColorSpaceName();
} catch (err) {
    console.log(`Fail to get colorSpace's name. Cause: ` + JSON.stringify(err));
}
```

### getWhitePoint

getWhitePoint(): Array\<number\>

Obtains the coordinates of the white point in the color space.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Return value**

| Type               | Description                    |
| ------------------ | ------------------------ |
| Array\<number\>  | Coordinates [x, y] of the white point. |

**Error codes**

For details about the error codes, see [colorSpaceManager Error Codes](errorcode-colorspace-manager.md).

| ID | Error Message |
| ------- | ----------------------- |
| 18600001 | The parameter value is abnormal. |

**Example**

```ts
try {
    let point = colorSpace.getWhitePoint();
} catch (err) {
    console.log(`Failed to get white point. Cause: ` + JSON.stringify(err));
}
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
try {
    let gamma = colorSpace.getGamma();
} catch (err) {
    console.log(`Failed to get gamma. Cause: ` + JSON.stringify(err));
}
```
