# Interface (ColorManagement)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 12.

ColorManagement extends [ColorManagementQuery](arkts-apis-camera-ColorManagementQuery.md).

It provides the APIs for color space settings.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## setColorSpace<sup>12+</sup>

setColorSpace(colorSpace: colorSpaceManager.ColorSpace): void

Sets a color space.

Before the setting, call [getSupportedColorSpaces](arkts-apis-camera-ColorManagementQuery.md#getsupportedcolorspaces12) to obtain the supported color spaces. You are advised to call this API after [addOutput](arkts-apis-camera-Session.md#addoutput11) and before [commitConfig](arkts-apis-camera-Session.md#commitconfig11-1). If this API is called after [commitConfig](arkts-apis-camera-Session.md#commitconfig11-1), the camera session configuration will take a longer time.

**P3 and HDR Imaging**  

An application can deliver different color space parameters to declare its support for P3 and HDR.

If an application does not proactively set the color space, SDR is used by default in photo capture scenarios.

To obtain HDR images in photo capture scenarios, set the color space to P3.

For different modes, enabling HDR, setting the color space, and configuring [CameraFormat](arkts-apis-camera-e.md#cameraformat) in the camera output stream [profile](arkts-apis-camera-i.md#profile) should match. For details, see the table below. For example, to enable HDR, set [CameraFormat](arkts-apis-camera-e.md#cameraformat) in the camera preview and video output stream [profiles](arkts-apis-camera-i.md#profile) to **CAMERA_FORMAT_YCRCB_P010** and the color space to **2020_HLG_LIMIT**.

**Recording Mode**

| SDR/HDR Photo Capture        | CameraFormat             | ColorSpace       |
|--------------------|--------------------------|------------------|
| SDR                | CAMERA_FORMAT_YUV_420_SP | BT709_LIMIT      |
| HDR_VIVID          | CAMERA_FORMAT_YCRCB_P010/CAMERA_FORMAT_YCBCR_P010 | BT2020_HLG_LIMIT/BT2020_HLG_FULL |

**Photo Mode**

| SDR/HDR Photo Capture       | ColorSpace |
|--------------------|------------|
| SDR(Default)       | SRGB       |
| HDR                | DISPLAY_P3 |

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                | Mandatory| Description                     |
| ------------ |---------------------- | -- | -------------------------- |
| colorSpace | [colorSpaceManager.ColorSpace](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspace)  | Yes| Color space, which is obtained by calling [getSupportedColorSpaces](arkts-apis-camera-ColorManagementQuery.md#getsupportedcolorspaces12).  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101         |  Parameter missing or parameter type incorrect.     |
| 7400102         |  The colorSpace does not match the format.     |
| 7400103         |  Session not config.                           |
| 7400201         |  Camera service fatal error.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { colorSpaceManager } from '@kit.ArkGraphics2D';

function setColorSpace(session: camera.PhotoSession, colorSpaces: Array<colorSpaceManager.ColorSpace>): void {
  if (colorSpaces === undefined || colorSpaces.length <= 0) {
    return;
  }
  try {
    session.setColorSpace(colorSpaces[0]);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The setColorSpace call failed, error code: ${err.code}`);
  }
}
```

## getActiveColorSpace<sup>12+</sup>

getActiveColorSpace(): colorSpaceManager.ColorSpace

Obtains the color space in use.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [colorSpaceManager.ColorSpace](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspace)               | Color space.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { colorSpaceManager } from '@kit.ArkGraphics2D';

function getActiveColorSpace(session: camera.PhotoSession): colorSpaceManager.ColorSpace | undefined {
  let colorSpace: colorSpaceManager.ColorSpace | undefined = undefined;
  try {
    colorSpace = session.getActiveColorSpace();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The getActiveColorSpace call failed. error code: ${err.code}`);
  }
  return colorSpace;
}
```
