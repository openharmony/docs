# Interface (FocusQuery)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=f0e09e3de648081eea4659387ebc6bc9008f04fc translatedAt=2026-08-11T01:58:54.515Z pushedAt=2026-08-11T10:29:08.333Z -->

FocusQuery provides APIs to check whether a focus mode is supported.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This interface was first introduced in API version 12. In this version, a compatibility change was made that preserved the initial version information of inner elements. As a result, you might see outer element's @since version number being higher than that of the inner elements. However, this discrepancy does not affect the functionality of the interface.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## isFocusModeSupported<sup>11+</sup>

isFocusModeSupported(afMode: FocusMode): boolean

Checks whether a focus mode is supported.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                             |
| -------- | ----------------------- | ---- | -------------------------------- |
| afMode   | [FocusMode](arkts-apis-camera-e.md#focusmode) | Yes  | Focus mode. If the input parameter is null or undefined, it is treated as 0 and manual focus is used.                   |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Check result for the support of the focus mode. **true** if supported, **false** otherwise. If the operation fails, undefined is returned and an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is thrown.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config, only throw in session usage.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isFocusModeSupported(photoSession: camera.PhotoSession): boolean {
  let status: boolean = false;
  try {
    status = photoSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_AUTO);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isFocusModeSupported call failed. error code: ${err.code}`);
  }
  return status;
}
```

## isLockFocusTrackingSupported

isLockFocusTrackingSupported(): boolean

Checks whether the device supports locking focus tracking.

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**Model restriction:** This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type        | Description                          |
| ---------- | ----------------------------- |
| boolean    | Whether locking focus tracking is supported. The value **true** indicates it is supported, and **false** indicates otherwise. If the API fails to be called, an error code is thrown and **undefined** is returned. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID         | Error Message        |
| --------------- | --------------- |
| 7400103                | The session is not configured. This error is only thrown during session usage.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isLockFocusTrackSupported(photoSession: camera.PhotoSession): boolean {
  let isSupported: boolean = false;
  try {
    isSupported = photoSession.isLockFocusTrackingSupported();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isLockFocusTrackingSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```