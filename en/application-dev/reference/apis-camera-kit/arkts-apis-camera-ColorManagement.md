# Interface (ColorManagement)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=e78a6cc17babc03b49d63c81464e0e9d7953f5bb translatedAt=2026-08-11T01:58:14.487Z pushedAt=2026-08-11T09:25:20.192Z -->

**ColorManagement** inherits from [ColorManagementQuery](arkts-apis-camera-ColorManagementQuery.md).

It provides the APIs for color space settings.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 12.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## setColorSpace<sup>12+</sup>

setColorSpace(colorSpace: colorSpaceManager.ColorSpace): void

Sets a color space.

Before the setting, call [getSupportedColorSpaces](arkts-apis-camera-ColorManagementQuery.md#getsupportedcolorspaces12) to obtain the supported color spaces. You are advised to call this API after [addOutput](arkts-apis-camera-Session.md#addoutput11) and before [commitConfig](arkts-apis-camera-Session.md#commitconfig11-1). If this API is called after [commitConfig](arkts-apis-camera-Session.md#commitconfig11-1), the camera session configuration will take a longer time.

P3 wide color gamut and HDR imaging:

An application can deliver different color space parameters to declare its support for P3 and HDR. If an application does not proactively set the color space, SDR is used by default in photo and video recording modes.

For different modes, enabling HDR, setting the color space, and configuring [CameraFormat](arkts-apis-camera-e.md#cameraformat) in the camera output stream [profile](arkts-apis-camera-i.md#profile) should match. For details, see the table below. For example, to enable HDR in video recording mode, set [CameraFormat](arkts-apis-camera-e.md#cameraformat) in the camera preview and video output stream [profiles](arkts-apis-camera-i.md#profile) to **CAMERA_FORMAT_YCRCB_P010** and the color space to **BT2020_HLG_LIMIT**.

To obtain HDR images in photo mode, set the color space to **DISPLAY_P3** or **BT2020_HLG**. **BT2020_HLG** provides a wider color gamut, and should be used together with the **CameraFormat**, including **CAMERA_FORMAT_YCRCB_P010** and **CAMERA_FORMAT_YCBCR_P010**, to improve the image quality.

In video recording mode, you can set the color space to **H_LOG** to record LOG videos. This is not supported in front camera and macro modes.

Since API version 23, you can call the [getSupportedFullOutputCapability](arkts-apis-camera-CameraManager.md#getsupportedfulloutputcapability23) API to check whether the preview format P010 is supported in photo mode.

 - If the application does not set the color space, the default color space in photo mode is SRGB when the **CameraFormat** is **CAMERA_FORMAT_YUV_420_SP**, and the default color space is **BT2020_HLG** when the **CameraFormat** is **CAMERA_FORMAT_YCRCB_P010** or **CAMERA_FORMAT_YCBCR_P010**.

 - If the application sets the color space, in photo mode, the **CameraFormat** and **ColorSpace** must be configured according to the following mapping table. Otherwise, an error code will be returned in [setColorSpace](arkts-apis-camera-ColorManagement.md#setcolorspace12) or [commitConfig](arkts-apis-camera-Session.md#commitconfig11-1).

Photo mode:

  | SDR/HDR Photo Capture       | CameraFormat| ColorSpace|
  |--------------------|------------| ------------|
  | SDR(Default)       | CAMERA_FORMAT_YUV_420_SP       | SRGB       |
  | HDR P3               | CAMERA_FORMAT_YUV_420_SP | DISPLAY_P3 |
  | HDR BT.2020 | CAMERA_FORMAT_YCRCB_P010,<br>CAMERA_FORMAT_YCBCR_P010 | BT2020_HLG |

In video recording mode, if SDR or HDR VIVID is enabled, the camera format and color space must be configured according to the relationships specified in the table below. Configurations that do not match the table will cause issues such as preview exceptions.

Recording mode:

| SDR/HDR Photo Capture        | CameraFormat             | ColorSpace       |
|--------------------|--------------------------|------------------|
| SDR(Default)               | CAMERA_FORMAT_YUV_420_SP | BT709_LIMIT      |
| HDR_VIVID          | CAMERA_FORMAT_YCRCB_P010 | BT2020_HLG_LIMIT,<br>BT2020_HLG |
| HDR_VIVID          | CAMERA_FORMAT_YCBCR_P010 | BT2020_HLG_LIMIT,<br>BT2020_HLG |

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