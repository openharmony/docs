# Interface (Flash)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 11.

Flash inherits from [FlashQuery](arkts-apis-camera-FlashQuery.md).

It provides APIs related to the flash.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## setFlashMode<sup>11+</sup>

setFlashMode(flashMode: FlashMode): void

Sets a flash mode.

Before the setting, do the following checks:

1. Use [hasFlash](arkts-apis-camera-FlashQuery.md#hasflash11) to check whether the camera device has flash.
2. Use [isFlashModeSupported](arkts-apis-camera-FlashQuery.md#isflashmodesupported11) to check whether the camera device supports the flash mode.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                    | Mandatory| Description                 |
| --------- | ----------------------- | ---- | --------------------- |
| flashMode | [FlashMode](arkts-apis-camera-e.md#flashmode) | Yes  | Flash mode. If the input parameter is null or undefined, it is treated as 0 and the flash is turned off.      |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFlashMode(photoSession: camera.PhotoSession): void {
  try {
    photoSession.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setFlashMode call failed. error code: ${err.code}`);
  }
}
```

## getFlashMode<sup>11+</sup>

getFlashMode(): FlashMode

Obtains the flash mode in use.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [FlashMode](arkts-apis-camera-e.md#flashmode)    | Flash mode obtained. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFlashMode(photoSession: camera.PhotoSession): camera.FlashMode | undefined {
  let flashMode: camera.FlashMode | undefined = undefined;
  try {
    flashMode = photoSession.getFlashMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFlashMode call failed.error code: ${err.code}`);
  }
  return flashMode;
}
```
