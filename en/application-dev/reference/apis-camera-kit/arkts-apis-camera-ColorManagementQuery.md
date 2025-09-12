# Interface (ColorManagementQuery)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 12.

ColorManagementQuery provides the APIs for color space query.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## getSupportedColorSpaces<sup>12+</sup>

getSupportedColorSpaces(): Array\<colorSpaceManager.ColorSpace\>

Obtains the supported color spaces.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| Array<[colorSpaceManager.ColorSpace](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspace)>| Array of color spaces supported.    |

**Example**

```ts
import { colorSpaceManager } from '@kit.ArkGraphics2D';

function getSupportedColorSpaces(session: camera.PhotoSession): Array<colorSpaceManager.ColorSpace> {
  let colorSpaces: Array<colorSpaceManager.ColorSpace> = [];
  colorSpaces = session.getSupportedColorSpaces();
  return colorSpaces;
}
```
