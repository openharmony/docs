# Color Space Management

The **colorSpaceManager** module provides APIs for creating and managing color space objects and obtaining basic color space attributes.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import colorSpaceManager from '@ohos.graphics.colorSpaceManager';
```

## ColorSpace

Enumerates the color space types.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

| Name                        | Value    | Description                   |
| --------------------------- | ------ | ----------------------- |
| UNKNOWN        | 0      | Unknown type.|
| ADOBE_RGB_1998 | 1      | Adobe RGB (1998).|
| DCI_P3         | 2      | DCI-P3.|
| DISPLAY_P3     | 3      | Display P3.|
| SRGB           | 4      | SRGB.<br>This is the default color space type.|
| CUSTOM         | 5      | Custom type.|

## ColorSpacePrimaries

Defines the color space primaries. A color space is defined by chromaticity coordinates of the red, green, and blue additive primaries, the white point, and the gamma.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

| Name                         | Type| Readable| Writable| Description                                                        |
| ---------------------------- | -------- | ---- | ---- | ----------------------------------------------------- |
| redX                         | number   | Yes  | Yes  | X coordinate of the red color in the color space.|
| redY                         | number   | Yes  | Yes  | Y coordinate of the red color in the color space.|
| greenX                       | number   | Yes  | Yes  | X coordinate of the green color in the color space.|
| greenY                       | number   | Yes  | Yes  | Y coordinate of the green color in the color space.|
| blueX                        | number   | Yes  | Yes  | X coordinate of the blue color in the color space.|
| blueY                        | number   | Yes  | Yes  | Y coordinate of the blue color in the color space.|
| whitePointX                  | number   | Yes  | Yes  | X coordinate of the white point in the color space.|
| whitePointY                  | number   | Yes  | Yes  | Y coordinate of the white point in the color space.|

## colorSpaceManager.create

create(colorSpaceName: ColorSpace): ColorSpaceManager

Creates a standard color space object.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Parameters**

| Parameter          | Type                    | Mandatory| Description                         |
| --------------- | ------------------------ | ---- | -----------------------------|
| colorSpaceName  | [ColorSpace](#colorspace)| Yes  | Type of the color space.<br>**UNKNOWN** and **CUSTOM** cannot be used when creating standard color space objects.         |

**Return value**

| Type               | Description                    |
| ------------------ | ------------------------ |
| [ColorSpaceManager](#colorspacemanager)  | Color space object created.              |

**Example**

```js
let colorSpace = null;
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

| Parameter          | Type                                      | Mandatory| Description                         |
| --------------- | ------------------------------------------ | ---- | -----------------------------|
| primaries       | [ColorSpacePrimaries](#colorspaceprimaries)| Yes  | Primaries of the color space.              |
| gamma           | number                                     | Yes  | Gamma of the color space.                |

**Return value**

| Type               | Description                    |
| ------------------ | ------------------------ |
| [ColorSpaceManager](#colorspacemanager)  | Color space object created.<br>The color space type is **CUSTOM** of [ColorSpace](#colorspace).|

**Example**

```js
let colorSpace = null;
try {
    let primaries = {
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

Before calling any of the following APIs, you must use [create()](#colorspacemanagercreate) to create a color space object.

### getColorSpaceName

getColorSpaceName(): ColorSpace

Obtains the color space type.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Return value**

| Type               | Description                    |
| ------------------ | ------------------------ |
| [ColorSpace](#colorspace)  | Color space type.|

**Example**

```js
try {
    colorSpace.getColorSpaceName();
} catch (err) {
    console.log(`Fail to get colorSpace's name. Cause: ` + JSON.stringify(err));
}
```

### getWhitePoint

getWhitePoint(): Array\<number\>

Obtains the coordinates of the white point of the color space.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Return value**

| Type               | Description                    |
| ------------------ | ------------------------ |
| Array\<number\>  | Coordinates [x, y] of the white point.|

**Example**

```js
try {
    colorSpace.getWhitePoint();
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
| number  | Gamma of the color space.|

**Example**

```js
try {
    colorSpace.getGamma();
} catch (err) {
    console.log(`Failed to get gamma. Cause: ` + JSON.stringify(err));
}
```
