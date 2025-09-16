# Interface (ControlCenter)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 20.

ControlCenter inherits from [ControlCenterQuery](arkts-apis-camera-ControlCenterQuery.md).

It is used to enable the camera controller.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## enableControlCenter<sup>20+</sup>

enableControlCenter(enabled: boolean): void

Enables the camera controller.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                 |
| -------- | -------------------- | ---- | -------------------- |
| enabled | boolean | Yes| Whether to enable or disable the camera controller. **true** to enable, **false** otherwise.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID   | Error Message                    |
|----------|--------------------------|
| 7400103  | Session not config.      |

**Example**

```ts
function enableControlCenter(videoSession: camera.VideoSession, enable: boolean): void {
    let isSupported: boolean = videoSession.isControlCenterSupported();
    if (isSupported) {
        videoSession.enableControlCenter(enable);
    }
}
```
