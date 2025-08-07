# Deprecated Interface (CaptureSession, deprecated)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [PhotoSession](arkts-apis-camera-PhotoSession.md) and [VideoSession](arkts-apis-camera-VideoSession.md) instead.

CaptureSession implements a capture session, which saves all [CameraInput](arkts-apis-camera-CameraInput.md) and [CameraOutput](arkts-apis-camera-CameraOutput.md) instances required to run the camera and requests the camera to complete shooting or video recording.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## beginConfig<sup>(deprecated)</sup>

beginConfig(): void

Starts configuration for the session.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.beginConfig](arkts-apis-camera-Session.md#beginconfig11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400105         |  Session config locked.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function beginConfig(captureSession: camera.CaptureSession): void {
  try {
    captureSession.beginConfig();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The beginConfig call failed. error code: ${err.code}`);
  }
}
```

## commitConfig<sup>(deprecated)</sup>

commitConfig(callback: AsyncCallback\<void\>): void

Commits the configuration for this session. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.commitConfig](arkts-apis-camera-Session.md#commitconfig11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102                |  Operation not allowed.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function commitConfig(captureSession: camera.CaptureSession): void {
  captureSession.commitConfig((err: BusinessError) => {
    if (err) {
      console.error(`The commitConfig call failed. error code: ${err.code}`);
      return;
    }
    console.info('Callback invoked to indicate the commit config success.');
  });
}
```

## commitConfig<sup>(deprecated)</sup>

commitConfig(): Promise\<void\>

Commits the configuration for this session. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.commitConfig](arkts-apis-camera-Session.md#commitconfig11-1) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description               |
| -------------- |-------------------|
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102                |  Operation not allowed.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function commitConfig(captureSession: camera.CaptureSession): void {
  captureSession.commitConfig().then(() => {
    console.info('Promise returned to indicate the commit config success.');
  }).catch((error: BusinessError) => {
    // If the operation fails, error.code is returned and processed.
    console.error(`The commitConfig call failed. error code: ${error.code}`);
  });
}
```

## addInput<sup>(deprecated)</sup>

addInput(cameraInput: CameraInput): void

Adds a [CameraInput](arkts-apis-camera-CameraInput.md) instance to this session.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.addInput](arkts-apis-camera-Session.md#addinput11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                    |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](arkts-apis-camera-CameraInput.md) | Yes  | CameraInput instance to add.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                                         |
|---------|-----------------------------------------------|
| 7400101 | Parameter missing or parameter type incorrect. |
| 7400102 | Operation not allowed.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function addInput(captureSession: camera.CaptureSession, cameraInput: camera.CameraInput): void {
  try {
    captureSession.addInput(cameraInput);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The addInput call failed. error code: ${err.code}`);
  }
}
```

## removeInput<sup>(deprecated)</sup>

removeInput(cameraInput: CameraInput): void

Removes a [CameraInput](arkts-apis-camera-CameraInput.md) instance from this session.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.removeInput](arkts-apis-camera-Session.md#removeinput11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                     |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](arkts-apis-camera-CameraInput.md) | Yes  | CameraInput instance to remove.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allowed.                                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function removeInput(captureSession: camera.CaptureSession, cameraInput: camera.CameraInput): void {
  try {
    captureSession.removeInput(cameraInput);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The removeInput call failed. error code: ${err.code}`);
  }
}
```

## addOutput<sup>(deprecated)</sup>

addOutput(cameraOutput: CameraOutput): void

Adds a [CameraOutput](arkts-apis-camera-CameraOutput.md) instance to this session.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.addOutput](arkts-apis-camera-Session.md#addoutput11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                            | Mandatory| Description                     |
| ------------- | ------------------------------- | ---- | ------------------------ |
| cameraOutput  | [CameraOutput](arkts-apis-camera-CameraOutput.md)   | Yes  | CameraOutput instance to add.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allowed.                                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function addOutput(captureSession: camera.CaptureSession, cameraOutput: camera.CameraOutput): void {
  try {
    captureSession.addOutput(cameraOutput);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The addOutput call failed. error code: ${err.code}`);
  }
}
```

## removeOutput<sup>(deprecated)</sup>

removeOutput(cameraOutput: CameraOutput): void

Removes a [CameraOutput](arkts-apis-camera-CameraOutput.md) instance from this session.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.removeOutput](arkts-apis-camera-Session.md#removeoutput11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                            | Mandatory| Description                     |
| ------------- | ------------------------------- | ---- | ------------------------ |
| cameraOutput  | [CameraOutput](arkts-apis-camera-CameraOutput.md)   | Yes  | CameraOutput instance to remove.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allowed.                                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function removeOutput(captureSession: camera.CaptureSession, previewOutput: camera.PreviewOutput): void {
  try {
    captureSession.removeOutput(previewOutput);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The removeOutput call failed. error code: ${err.code}`);
  }
}
```

## start<sup>(deprecated)</sup>

start(callback: AsyncCallback\<void\>): void

Starts this session. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.start](arkts-apis-camera-Session.md#start11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function startCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.start((err: BusinessError) => {
    if (err) {
      console.error(`Failed to start the session, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate the session start success.');
  });
}
```

## start<sup>(deprecated)</sup>

start(): Promise\<void\>

Starts this session. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.start](arkts-apis-camera-Session.md#start11-1) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function startCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.start().then(() => {
    console.info('Promise returned to indicate the session start success.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to start the session, error code: ${err.code}.`);
  });
}
```

## stop<sup>(deprecated)</sup>

stop(callback: AsyncCallback\<void\>): void

Stops this session. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.stop](arkts-apis-camera-Session.md#stop11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.stop((err: BusinessError) => {
    if (err) {
      console.error(`Failed to stop the session, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate the session stop success.');
  });
}
```

## stop<sup>(deprecated)</sup>

stop(): Promise\<void\>

Stops this session. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.stop](arkts-apis-camera-Session.md#stop11-1) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.stop().then(() => {
    console.info('Promise returned to indicate the session stop success.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to stop the session, error code: ${err.code}.`);
  });
}
```

## release<sup>(deprecated)</sup>

release(callback: AsyncCallback\<void\>): void

Releases this session. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.release](arkts-apis-camera-Session.md#release11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function releaseCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release the CaptureSession instance, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate that the CaptureSession instance is released successfully.');
  });
}
```

## release<sup>(deprecated)</sup>

release(): Promise\<void\>

Releases this session. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Session.release](arkts-apis-camera-Session.md#release11-1) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function releaseCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.release().then(() => {
    console.info('Promise returned to indicate that the CaptureSession instance is released successfully.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to release the CaptureSession instance, error code: ${err.code}.`);
  });
}
```

## hasFlash<sup>(deprecated)</sup>

hasFlash(): boolean

Checks whether the camera device has flash.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Flash.hasFlash](arkts-apis-camera-FlashQuery.md#hasflash11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Check result for whether the camera device has flash. **true** if it has flash, **false** otherwise. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function hasFlash(captureSession: camera.CaptureSession): boolean {
  let status: boolean = false;
  try {
    status = captureSession.hasFlash();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The hasFlash call failed. error code: ${err.code}`);
  }
  return status;
}
```

## isFlashModeSupported<sup>(deprecated)</sup>

isFlashModeSupported(flashMode: FlashMode): boolean

Checks whether a flash mode is supported.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Flash.isFlashModeSupported](arkts-apis-camera-FlashQuery.md#isflashmodesupported11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                    | Mandatory| Description                              |
| --------- | ----------------------- | ---- | --------------------------------- |
| flashMode | [FlashMode](arkts-apis-camera-e.md#flashmode) | Yes  | Flash mode.                    |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Check result for the support of the flash mode. **true** if supported, **false** otherwise. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isFlashModeSupported(captureSession: camera.CaptureSession): boolean {
  let status: boolean = false;
  try {
    status = captureSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isFlashModeSupported call failed. error code: ${err.code}`);
  }
  return status;
}
```

## setFlashMode<sup>(deprecated)</sup>

setFlashMode(flashMode: FlashMode): void

Sets a flash mode.

Before the setting, do the following checks:

1. Use [hasFlash](#hasflashdeprecated) to check whether the camera device has flash.
2. Use [isFlashModeSupported](#isflashmodesupporteddeprecated) to check whether the camera device supports the flash mode.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Flash.setFlashMode](arkts-apis-camera-Flash.md#setflashmode11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                |
| --------- | ----------------------- | ---- | -------------------- |
| flashMode | [FlashMode](arkts-apis-camera-e.md#flashmode) | Yes  | Flash mode.      |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFlashMode(captureSession: camera.CaptureSession): void {
  try {
    captureSession.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setFlashMode call failed. error code: ${err.code}`);
  }
}
```

## getFlashMode<sup>(deprecated)</sup>

getFlashMode(): FlashMode

Obtains the flash mode in use.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Flash.getFlashMode](arkts-apis-camera-Flash.md#getflashmode11) instead.

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

function getFlashMode(captureSession: camera.CaptureSession): camera.FlashMode | undefined {
  let flashMode: camera.FlashMode | undefined = undefined;
  try {
    flashMode = captureSession.getFlashMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFlashMode call failed.error code: ${err.code}`);
  }
  return flashMode;
}
```

## isExposureModeSupported<sup>(deprecated)</sup>

isExposureModeSupported(aeMode: ExposureMode): boolean

Checks whether an exposure mode is supported.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [AutoExposure.isExposureModeSupported](arkts-apis-camera-AutoExposureQuery.md#isexposuremodesupported11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                          | Mandatory | Description                          |
| -------- | -------------------------------| ---- | ----------------------------- |
| aeMode   | [ExposureMode](arkts-apis-camera-e.md#exposuremode)  | Yes  | Exposure mode.                     |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Check result for the support of the exposure mode. **true** if supported, **false** otherwise. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isExposureModeSupported(captureSession: camera.CaptureSession): boolean {
  let isSupported: boolean = false;
  try {
    isSupported = captureSession.isExposureModeSupported(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isExposureModeSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```

## getExposureMode<sup>(deprecated)</sup>

getExposureMode(): ExposureMode

Obtains the exposure mode in use.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [AutoExposure.getExposureMode](arkts-apis-camera-AutoExposure.md#getexposuremode11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [ExposureMode](arkts-apis-camera-e.md#exposuremode)    | Exposure mode obtained. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureMode(captureSession: camera.CaptureSession): camera.ExposureMode | undefined {
  let exposureMode: camera.ExposureMode | undefined = undefined;
  try {
    exposureMode = captureSession.getExposureMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getExposureMode call failed. error code: ${err.code}`);
  }
  return exposureMode;
}
```

## setExposureMode<sup>(deprecated)</sup>

setExposureMode(aeMode: ExposureMode): void

Sets an exposure mode. Before the setting, call [isExposureModeSupported](#isexposuremodesupporteddeprecated) to check whether the target exposure mode is supported.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [AutoExposure.setExposureMode](arkts-apis-camera-AutoExposure.md#setexposuremode11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                           | Mandatory| Description                   |
| -------- | -------------------------------| ---- | ----------------------- |
| aeMode   | [ExposureMode](arkts-apis-camera-e.md#exposuremode)  | Yes  | Exposure mode.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setExposureMode(captureSession: camera.CaptureSession): void {
  try {
    captureSession.setExposureMode(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setExposureMode call failed. error code: ${err.code}`);
  }
}
```

## getMeteringPoint<sup>(deprecated)</sup>

getMeteringPoint(): Point

Obtains the metering point of the camera device.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [AutoExposure.getMeteringPoint](arkts-apis-camera-AutoExposure.md#getmeteringpoint11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [Point](arkts-apis-camera-i.md#point)    | Metering point obtained. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getMeteringPoint(captureSession: camera.CaptureSession): camera.Point | undefined {
  let exposurePoint: camera.Point | undefined = undefined;
  try {
    exposurePoint = captureSession.getMeteringPoint();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getMeteringPoint call failed. error code: ${err.code}`);
  }
  return exposurePoint;
}
```

## setMeteringPoint<sup>(deprecated)</sup>

setMeteringPoint(point: Point): void

Sets the metering point, which is the center point of the metering rectangle.

The metering point must be in the coordinate system (0-1), where the upper left corner is {0, 0} and the lower right corner is {1, 1}.

The coordinate system is based on the horizontal device direction with the device's charging port on the right. If the layout of the preview screen of an application is based on the vertical direction with the charging port on the lower side, the layout width and height are {w, h}, and the touch point is {x, y}, then the coordinate point after conversion is {y/h, 1-x/w}.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [AutoExposure.setMeteringPoint](arkts-apis-camera-AutoExposure.md#setmeteringpoint11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                           | Mandatory| Description                |
| ------------- | -------------------------------| ---- | ------------------- |
| point | [Point](arkts-apis-camera-i.md#point)                | Yes  | Metering point. The value range of x and y must be within [0,1]. If a value less than 0 is passed, the value **0** is used. If a value greater than **1** is passed, the value **1** is used.            |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setMeteringPoint(captureSession: camera.CaptureSession): void {
  const point: camera.Point = {x: 1, y: 1};
  try {
    captureSession.setMeteringPoint(point);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setMeteringPoint call failed. error code: ${err.code}`);
  }
}
```

## getExposureBiasRange<sup>(deprecated)</sup>

getExposureBiasRange(): Array\<number\>

Obtains the exposure compensation values of the camera device.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [AutoExposure.getExposureBiasRange](arkts-apis-camera-AutoExposureQuery.md#getexposurebiasrange11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| Array\<number\>   | Array of compensation values. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureBiasRange(captureSession: camera.CaptureSession): Array<number> {
  let biasRangeArray: Array<number> = [];
  try {
    biasRangeArray = captureSession.getExposureBiasRange();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getExposureBiasRange call failed. error code: ${err.code}`);
  }
  return biasRangeArray;
}
```

## setExposureBias<sup>(deprecated)</sup>

setExposureBias(exposureBias: number): void

Sets an exposure compensation value (EV).

Before the setting, you are advised to use [getExposureBiasRange](#getexposurebiasrangedeprecated) to obtain the supported values.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [AutoExposure.setExposureBias](arkts-apis-camera-AutoExposure.md#setexposurebias11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory | Description      |
| -------- | -----------|-----|-----------------|
| exposureBias   | number                   | Yes | EV. The supported EV range can be obtained by calling [getExposureBiasRange](arkts-apis-camera-AutoExposureQuery.md#getexposurebiasrange11). If the value passed is not within the supported range, the nearest critical point is used. There is a step for EV. For example, if the step is 0.5 and this parameter is set to 1.2, the EV that takes effect is 1.0. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned. If the input parameter is null or undefined, the EV is set to 0.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setExposureBias(captureSession: camera.CaptureSession, biasRangeArray: Array<number>): void {
  if (biasRangeArray && biasRangeArray.length > 0) {
    let exposureBias = biasRangeArray[0];
    try {
      captureSession.setExposureBias(exposureBias);
    } catch (error) {
      // If the operation fails, error.code is returned and processed.
      let err = error as BusinessError;
      console.error(`The setExposureBias call failed. error code: ${err.code}`);
    }
  }
}
```

## getExposureValue<sup>(deprecated)</sup>

getExposureValue(): number

Obtains the exposure value in use.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [AutoExposure.getExposureValue](arkts-apis-camera-AutoExposure.md#getexposurevalue11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Exposure value obtained. There is a step for EV. For example, if the step is 0.5 and this parameter is set to 1.2, the EV that takes effect is 1.0. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureValue(captureSession: camera.CaptureSession): number {
  const invalidValue: number = -1;
  let exposureValue: number = invalidValue;
  try {
    exposureValue = captureSession.getExposureValue();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getExposureValue call failed. error code: ${err.code}`);
  }
  return exposureValue;
}
```

## isFocusModeSupported<sup>(deprecated)</sup>

isFocusModeSupported(afMode: FocusMode): boolean

Checks whether a focus mode is supported.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Focus.isFocusModeSupported](arkts-apis-camera-FocusQuery.md#isfocusmodesupported11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                             |
| -------- | ----------------------- | ---- | -------------------------------- |
| afMode   | [FocusMode](arkts-apis-camera-e.md#focusmode) | Yes  | Focus mode.                   |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Check result for the support of the focus mode. **true** if supported, **false** otherwise. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isFocusModeSupported(captureSession: camera.CaptureSession): boolean {
  let status: boolean = false;
  try {
    status = captureSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_AUTO);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isFocusModeSupported call failed. error code: ${err.code}`);
  }
  return status;
}
```

## setFocusMode<sup>(deprecated)</sup>

setFocusMode(afMode: FocusMode): void

Sets a focus mode.

Before the setting, call [isFocusModeSupported](#isfocusmodesupporteddeprecated) to check whether the focus mode is supported.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Focus.setFocusMode](arkts-apis-camera-Focus.md#setfocusmode11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| afMode   | [FocusMode](arkts-apis-camera-e.md#focusmode) | Yes  | Focus mode.      |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFocusMode(captureSession: camera.CaptureSession): void {
  try {
    captureSession.setFocusMode(camera.FocusMode.FOCUS_MODE_AUTO);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setFocusMode call failed. error code: ${err.code}`);
  }
}
```

## getFocusMode<sup>(deprecated)</sup>

getFocusMode(): FocusMode

Obtains the focus mode in use.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Focus.getFocusMode](arkts-apis-camera-Focus.md#getfocusmode11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [FocusMode](arkts-apis-camera-e.md#focusmode)   | Focus mode obtained. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocusMode(captureSession: camera.CaptureSession): camera.FocusMode | undefined {
  let afMode: camera.FocusMode | undefined = undefined;
  try {
    afMode = captureSession.getFocusMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFocusMode call failed. error code: ${err.code}`);
  }
  return afMode;
}
```

## setFocusPoint<sup>(deprecated)</sup>

setFocusPoint(point: Point): void

Sets the focal point. The focal point must be in the coordinate system (0-1), where the upper left corner is {0, 0} and the lower right corner is {1, 1}.

The coordinate system is based on the horizontal device direction with the device's charging port on the right. If the layout of the preview screen of an application is based on the vertical direction with the charging port on the lower side, the layout width and height are {w, h}, and the touch point is {x, y}, then the coordinate point after conversion is {y/h, 1-x/w}.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Focus.setFocusPoint](arkts-apis-camera-Focus.md#setfocuspoint11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type                    | Mandatory | Description                |
|-------| ----------------------- |-----| ------------------- |
| point | [Point](arkts-apis-camera-i.md#point)         | Yes | Focal point. The value range of x and y must be within [0,1]. If a value less than 0 is passed, the value **0** is used. If a value greater than **1** is passed, the value **1** is used.  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFocusPoint(captureSession: camera.CaptureSession): void {
  const focusPoint: camera.Point = {x: 1, y: 1};
  try {
    captureSession.setFocusPoint(focusPoint);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setFocusPoint call failed. error code: ${err.code}`);
  }
}
```

## getFocusPoint<sup>(deprecated)</sup>

getFocusPoint(): Point

Obtains the focal point of the camera device.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Focus.getFocusPoint](arkts-apis-camera-Focus.md#getfocuspoint11) instead.

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

function getFocusPoint(captureSession: camera.CaptureSession): camera.Point | undefined {
  let point: camera.Point | undefined = undefined;
  try {
    point = captureSession.getFocusPoint();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFocusPoint call failed. error code: ${err.code}`);
  }
  return point;
}
```

## getFocalLength<sup>(deprecated)</sup>

getFocalLength(): number

Obtains the focal length of the camera device.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Focus.getFocalLength](arkts-apis-camera-Focus.md#getfocallength11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Focal length obtained. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocalLength(captureSession: camera.CaptureSession): number {
  const invalidValue: number = -1;
  let focalLength: number = invalidValue;
  try {
    focalLength = captureSession.getFocalLength();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getFocalLength call failed. error code: ${err.code}`);
  }
  return focalLength;
}
```

## getZoomRatioRange<sup>(deprecated)</sup>

getZoomRatioRange(): Array\<number\>

Obtains the supported zoom ratio range.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Zoom.getZoomRatioRange](arkts-apis-camera-ZoomQuery.md#getzoomratiorange11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| Array\<number\>   | Array containing the minimum and maximum zoom ratios. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getZoomRatioRange(captureSession: camera.CaptureSession): Array<number> {
  let zoomRatioRange: Array<number> = [];
  try {
    zoomRatioRange = captureSession.getZoomRatioRange();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getZoomRatioRange call failed. error code: ${err.code}`);
  }
  return zoomRatioRange;
}
```

## setZoomRatio<sup>(deprecated)</sup>

setZoomRatio(zoomRatio: number): void

Sets a zoom ratio, with a maximum precision of two decimal places.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Zoom.setZoomRatio](arkts-apis-camera-Zoom.md#setzoomratio11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                 | Mandatory | Description                |
| --------- | -------------------- |-----| ------------------- |
| zoomRatio | number               | Yes | Zoom ratio. The supported zoom ratio range can be obtained by calling [getZoomRatioRange](arkts-apis-camera-ZoomQuery.md#getzoomratiorange11). If the value passed in is not within the supported range, the value within the precision range is retained. If the input parameter is null or undefined, it is treated as 0 and the minimum zoom ratio is used.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setZoomRatio(captureSession: camera.CaptureSession, zoomRatioRange: Array<number>): void {
  if (zoomRatioRange === undefined || zoomRatioRange.length <= 0) {
    return;
  }
  let zoomRatio = zoomRatioRange[0];
  try {
    captureSession.setZoomRatio(zoomRatio);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setZoomRatio call failed. error code: ${err.code}`);
  }
}
```

## getZoomRatio<sup>(deprecated)</sup>

getZoomRatio(): number

Obtains the zoom ratio in use.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Zoom.getZoomRatio](arkts-apis-camera-Zoom.md#getzoomratio11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Zoom ratio obtained. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getZoomRatio(captureSession: camera.CaptureSession): number {
  const invalidValue: number = -1;
  let zoomRatio: number = invalidValue;
  try {
    zoomRatio = captureSession.getZoomRatio();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getZoomRatio call failed. error code: ${err.code}`);
  }
  return zoomRatio;
}
```

## isVideoStabilizationModeSupported<sup>(deprecated)</sup>

isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean

Checks whether a video stabilization mode is supported. 

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Stabilization.isVideoStabilizationModeSupported](arkts-apis-camera-StabilizationQuery.md#isvideostabilizationmodesupported11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                             | Mandatory| Description                            |
| -------- | ------------------------------------------------- | ---- | ------------------------------ |
| vsMode   | [VideoStabilizationMode](arkts-apis-camera-e.md#videostabilizationmode) | Yes  | Video stabilization mode. If the input parameter is null or undefined, it is treated as 0 and video stabilization is disabled.             |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Check result for the support of the video stabilization mode. **true** if supported, **false** otherwise. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isVideoStabilizationModeSupported(captureSession: camera.CaptureSession): boolean {
  let isSupported: boolean = false;
  try {
    isSupported = captureSession.isVideoStabilizationModeSupported(camera.VideoStabilizationMode.OFF);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The isVideoStabilizationModeSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```

## getActiveVideoStabilizationMode<sup>(deprecated)</sup>

getActiveVideoStabilizationMode(): VideoStabilizationMode

Obtains the video stabilization mode in use.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Stabilization.getActiveVideoStabilizationMode](arkts-apis-camera-Stabilization.md#getactivevideostabilizationmode11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [VideoStabilizationMode](arkts-apis-camera-e.md#videostabilizationmode)    | Video stabilization mode obtained. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getActiveVideoStabilizationMode(captureSession: camera.CaptureSession): camera.VideoStabilizationMode | undefined {
  let vsMode: camera.VideoStabilizationMode | undefined = undefined;
  try {
    vsMode = captureSession.getActiveVideoStabilizationMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getActiveVideoStabilizationMode call failed. error code: ${err.code}`);
  }
  return vsMode;
}
```

## setVideoStabilizationMode<sup>(deprecated)</sup>

setVideoStabilizationMode(mode: VideoStabilizationMode): void

Sets a video stabilization mode. Before the setting, call [isVideoStabilizationModeSupported](#isvideostabilizationmodesupporteddeprecated) to check whether the target video stabilization mode is supported.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [Stabilization.setVideoStabilizationMode](arkts-apis-camera-Stabilization.md#setvideostabilizationmode11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                             | Mandatory| Description                   |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| mode     | [VideoStabilizationMode](arkts-apis-camera-e.md#videostabilizationmode) | Yes  | Video stabilization mode. If the input parameter is null or undefined, it is treated as 0 and video stabilization is disabled.  |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setVideoStabilizationMode(captureSession: camera.CaptureSession): void {
  try {
    captureSession.setVideoStabilizationMode(camera.VideoStabilizationMode.OFF);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setVideoStabilizationMode call failed. error code: ${err.code}`);
  }
}
```

## on('focusStateChange')<sup>(deprecated)</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

Subscribes to focus state change events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [VideoSession.on('focusStateChange')](arkts-apis-camera-VideoSession.md#onfocusstatechange11) instead.
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback\<[FocusState](arkts-apis-camera-e.md#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function registerFocusStateChange(captureSession: camera.CaptureSession): void {
  captureSession.on('focusStateChange', (err: BusinessError, focusState: camera.FocusState) => {
    if (err !== undefined && err.code !== 0) {
      console.error(`Callback Error, errorCode: ${err.code}`);
      return;
    }
    console.info(`Focus state: ${focusState}`);
  });
}
```

## off('focusStateChange')<sup>(deprecated)</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

Unsubscribes from focus state change events.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [VideoSession.off('focusStateChange')](arkts-apis-camera-VideoSession.md#offfocusstatechange11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created.|
| callback | AsyncCallback\<[FocusState](arkts-apis-camera-e.md#focusstate)\> | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterFocusStateChange(captureSession: camera.CaptureSession): void {
  captureSession.off('focusStateChange');
}
```

## on('error')<sup>(deprecated)</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to CaptureSession error events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [VideoSession.on('error')](arkts-apis-camera-VideoSession.md#onerror11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                                      | Mandatory| Description                          |
| -------- |--------------------------------------------------------------------------| ---- | ------------------------------ |
| type     | string                                                                   | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as [beginConfig](#beginconfigdeprecated), [commitConfig](#commitconfigdeprecated-1), and [addInput](#addinputdeprecated).|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback used to return an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode).       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function registerCaptureSessionError(captureSession: camera.CaptureSession): void {
  captureSession.on('error', (error: BusinessError) => {
    console.error(`Capture session error code: ${error.code}`);
  });
}
```

## off('error')<sup>(deprecated)</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from CaptureSession error events. This API uses a callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [VideoSession.off('error')](arkts-apis-camera-VideoSession.md#offerror11) instead.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                         | Mandatory| Description                          |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterCaptureSessionError(captureSession: camera.CaptureSession): void {
  captureSession.off('error');
}
```
