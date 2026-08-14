# Interface (Focus)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=f0e09e3de648081eea4659387ebc6bc9008f04fc translatedAt=2026-08-11T01:58:58.234Z pushedAt=2026-08-11T10:20:44.524Z -->

**Focus** inherits from [FocusQuery](arkts-apis-camera-FocusQuery.md).

It provides APIs related to focus operations.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 11.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## setFocusMode<sup>11+</sup>

setFocusMode(afMode: FocusMode): void

Sets a focus mode.

Before the setting, call [isFocusModeSupported](arkts-apis-camera-FocusQuery.md#isfocusmodesupported11) to check whether the focus mode is supported.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| afMode   | [FocusMode](arkts-apis-camera-e.md#focusmode) | Yes  | Focus mode. If the input parameter is null or undefined, it is treated as 0 and manual focus is used.      |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFocusMode(photoSession: camera.PhotoSession): void {
  try {
    photoSession.setFocusMode(camera.FocusMode.FOCUS_MODE_AUTO);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setFocusMode call failed. error code: ${err.code}`);
  }
}
```

## getFocusMode<sup>11+</sup>

getFocusMode(): FocusMode

Obtains the focus mode in use.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [FocusMode](arkts-apis-camera-e.md#focusmode)   | Focus mode obtained. If the operation fails, undefined is returned and an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is thrown.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocusMode(photoSession: camera.PhotoSession): camera.FocusMode | undefined {
  let afMode: camera.FocusMode | undefined = undefined;
  try {
    afMode = photoSession.getFocusMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFocusMode call failed. error code: ${err.code}`);
  }
  return afMode;
}
```

## setFocusPoint<sup>11+</sup>

setFocusPoint(point: Point): void

Sets the focal point. The focal point must be in the coordinate system (0-1), where the top-left corner is {0, 0} and the bottom-right corner is {1, 1}.

The coordinate system is based on the horizontal device direction with the device's charging port on the right. If the layout of the preview screen of an application is based on the vertical direction with the charging port on the lower side, the layout width and height are {w, h}, and the touch point is {x, y}, then the coordinate point after conversion is {y/h, 1-x/w}.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| point    | [Point](arkts-apis-camera-i.md#point)         | Yes  | Focal point. The value range of x and y must be within [0, 1]. If a value less than 0 is passed, the value **0** is used. If a value greater than **1** is passed, the value **1** is used.  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFocusPoint(photoSession: camera.PhotoSession): void {
  const focusPoint: camera.Point = {x: 1, y: 1};
  try {
    photoSession.setFocusPoint(focusPoint);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setFocusPoint call failed. error code: ${err.code}`);
  }
}
```

## getFocusPoint<sup>11+</sup>

getFocusPoint(): Point

Obtains the focal point in use.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [Point](arkts-apis-camera-i.md#point)    | Focal point obtained. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocusPoint(photoSession: camera.PhotoSession): camera.Point | undefined {
  let point: camera.Point | undefined = undefined;
  try {
    point = photoSession.getFocusPoint();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFocusPoint call failed. error code: ${err.code}`);
  }
  return point;
}
```

## getFocalLength<sup>11+</sup>

getFocalLength(): number

Obtains the focal length in use.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Focal length, in mm. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocalLength(photoSession: camera.PhotoSession): number {
  const invalidValue: number = -1;
  let focalLength: number = invalidValue;
  try {
    focalLength = photoSession.getFocalLength();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFocalLength call failed. error code: ${err.code}`);
  }
  return focalLength;
}
```

## lockFocusTracking

lockFocusTracking(focusPoint: Point): void

Locks focus tracking to continuously track a specified object. The tracking object is specified by the **focusPoint** parameter.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                     | Mandatory | Description                 |
| -------- | ----------------------- | ---- | ------------------- |
| focusPoint    | [Point](arkts-apis-camera-i.md#point)         | Yes   | Focus point. Both x and y is within the range of [0, 1]. If the value is out of the range, the setting does not take effect. (0, 0) indicates the upper left corner of the image, and (1, 1) indicates the lower right corner of the image.  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID         | Error Message        |
| --------------- | --------------- |
| 7400103                | Session not config, only throw in session usage.   |
| 7400201                | Camera service fatal error.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function lockFocusTracking(photoSession: camera.PhotoSession): void {
  try {
    const focusPoint: camera.Point = {x: 0, y: 0};
    photoSession.lockFocusTracking(focusPoint);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The lockFocusTrack call failed. error code: ${err.code}`);
  }
}
```

## unlockFocusTracking

unlockFocusTracking(): void

Unlocks focus tracking.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID         | Error Message        |
| --------------- | --------------- |
| 7400103                | Session not config, only throw in session usage.   |
| 7400201                | Camera service fatal error.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function unlockFocusTracking(photoSession: camera.PhotoSession): void {
  try {
    photoSession.unlockFocusTracking();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The unlockFocusTrack call failed. error code: ${err.code}`);
  }
}
```