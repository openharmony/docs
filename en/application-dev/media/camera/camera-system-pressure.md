# Pressure Management (ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

Starting from API version 20, the camera framework supports monitoring of system pressure levels.

In scenarios requiring prolonged camera usage (such as live streaming), applications can dynamically adjust image quality parameters (such as the frame rate or resolution) based on system pressure level changes. This helps balance power consumption, heat generation, and system load, ensuring stable and extended camera functionality.

## Status Listening

To monitor system pressure status changes, register the [systemPressureLevelChange](../../reference/apis-camera-kit/arkts-apis-camera-PhotoSession.md#onsystempressurelevelchange20) callback.

When the system pressure level changes, the callback returns the **SystemPressureLevel** parameter.

For details about this parameter, see [SystemPressureLevel](../../reference/apis-camera-kit/arkts-apis-camera-e.md#systempressurelevel20).

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, systemPressureLevel: camera.SystemPressureLevel): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`systemPressureLevel: ${systemPressureLevel}`);
}

function registerSystemPressureLevelChangeCallback(photoSession: camera.PhotoSession): void {
    photoSession.on('systemPressureLevelChange', callback);
}
```
