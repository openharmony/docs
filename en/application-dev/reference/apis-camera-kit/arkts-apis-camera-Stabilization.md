# Interface (Stabilization)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 11.

Stabilization extends [StabilizationQuery](arkts-apis-camera-StabilizationQuery.md).

It provides APIs to set video stabilization.

 > **NOTE**
 >
 > You can set video stabilization only when a [VideoOutput](arkts-apis-camera-VideoOutput.md) stream exists in the session.
 > The enumerated value **HIGH** of [VideoStabilizationMode](arkts-apis-camera-e.md#videostabilizationmode) takes effect only when the resolution of [Profile](arkts-apis-camera-i.md#profile) is 1920 x 1080.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## getActiveVideoStabilizationMode<sup>11+</sup>

getActiveVideoStabilizationMode(): VideoStabilizationMode

Obtains the video stabilization mode in use.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description         |
| ---------- |-------------|
| [VideoStabilizationMode](arkts-apis-camera-e.md#videostabilizationmode)    | Video stabilization mode obtained.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getActiveVideoStabilizationMode(videoSession: camera.VideoSession): camera.VideoStabilizationMode | undefined {
  let vsMode: camera.VideoStabilizationMode | undefined = undefined;
  try {
    vsMode = videoSession.getActiveVideoStabilizationMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getActiveVideoStabilizationMode call failed. error code: ${err.code}`);
  }
  return vsMode;
}
```

## setVideoStabilizationMode<sup>11+</sup>

setVideoStabilizationMode(mode: VideoStabilizationMode): void

Sets a video stabilization mode. Before the setting, call [isVideoStabilizationModeSupported](arkts-apis-camera-StabilizationQuery.md#isvideostabilizationmodesupported11) to check whether the target video stabilization mode is supported.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                             | Mandatory| Description                   |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| mode     | [VideoStabilizationMode](arkts-apis-camera-e.md#videostabilizationmode) | Yes  | Video stabilization mode.  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setVideoStabilizationMode(videoSession: camera.VideoSession): void {
  try {
    videoSession.setVideoStabilizationMode(camera.VideoStabilizationMode.OFF);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setVideoStabilizationMode call failed. error code: ${err.code}`);
  }
}
```
