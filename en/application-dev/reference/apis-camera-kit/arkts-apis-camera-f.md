# Functions
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## camera.getCameraManager

getCameraManager(context: Context): CameraManager

Obtains a CameraManager instance. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md)      | Yes  | Application context.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [CameraManager](arkts-apis-camera-CameraManager.md)           | CameraManager instance obtained.                  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

function getCameraManager(context: common.BaseContext): camera.CameraManager | undefined {
  let cameraManager: camera.CameraManager | undefined = undefined;
  try {
    cameraManager = camera.getCameraManager(context);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The getCameraManager call failed. error code: ${err.code}`);
  }
  return cameraManager;
}
```
