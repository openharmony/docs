# Interface (CameraInput)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

CameraInput defines the camera input object.

It provides camera device information used in [Session](arkts-apis-camera-Session.md).

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## open

open(callback: AsyncCallback\<void\>): void

Opens this camera device. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                 | Mandatory| Description                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the camera device is opened successfully, **err** is **undefined**; otherwise, **err** is an error object with an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode).|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400107                |  Can not use camera cause of conflict.               |
| 7400108                |  Camera disabled cause of security reason.                                  |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function openCameraInput(cameraInput: camera.CameraInput): void {
  cameraInput.open((err: BusinessError) => {
    if (err) {
      console.error(`Failed to open the camera, error code: ${err.code}.`);
      return;
    }
    console.info('Callback returned with camera opened.');
  });
}
```

## open

open(): Promise\<void\>

Opens this camera device. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type          | Description                     |
| -------------- | ----------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                                     |
|---------|-------------------------------------------|
| 7400102 | Operation not allowed.                    |
| 7400107 | Can not use camera cause of conflict.     |
| 7400108 | Camera disabled cause of security reason. |
| 7400201 | Camera service fatal error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function openCameraInput(cameraInput: camera.CameraInput): void {
  cameraInput.open().then(() => {
    console.info('Promise returned with camera opened.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to open the camera, error code: ${error.code}.`);
  });
}
```

## open<sup>12+</sup>

open(isSecureEnabled: boolean): Promise\<bigint\>

Opens this camera device. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                 | Mandatory| Description                                                                     |
| -------- | -------------------- | ---- |-------------------------------------------------------------------------|
| isSecureEnabled | boolean | Yes  | Whether to open the camera device in secure mode. **true** to open in secure mode, **false** otherwise. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Return value**

| Type          | Description                     |
| -------------- | ----------------------- |
| Promise\<bigint\> | Promise used to return the handle to the camera device in secure mode.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400107                |  Can not use camera cause of conflict.               |
| 7400108                |  Camera disabled cause of security reason.                                  |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function openCameraInput(cameraInput: camera.CameraInput): void {
  cameraInput.open(true).then(() => {
    console.info('Promise returned with camera opened.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to open the camera, error code: ${error.code}.`);
  });
}
```

## open<sup>18+</sup>

open(type: CameraConcurrentType): Promise\<void\>

Opens the camera with the specified concurrency type. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                 | Mandatory| Description                                                                     |
| -------- | -------------------- | ---- |-------------------------------------------------------------------------|
| type | [CameraConcurrentType](arkts-apis-camera-e.md#cameraconcurrenttype18) | Yes  | Concurrency type. If the API fails to be called, an error code is returned.|

**Return value**

| Type          | Description                     |
| -------------- | ----------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                                     |
|---------|-------------------------------------------|
| 7400102 | Operation not allowed.                    |
| 7400107 | Can not use camera cause of conflict.     |
| 7400108 | Camera disabled cause of security reason. |
| 7400201 | Camera service fatal error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function openCameraInput(cameraInput: camera.CameraInput): void {
  cameraInput.open(0).then(() => {
    console.info('Promise returned with camera opened.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to open the camera, error code: ${error.code}.`);
  });
}
```

## close

close(callback: AsyncCallback\<void\>\): void

Closes this camera device. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. If the camera device is closed successfully, **err** is **undefined**. Otherwise, **err** is an error object with an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode).|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function closeCameraInput(cameraInput: camera.CameraInput): void {
  cameraInput.close((err: BusinessError) => {
    if (err) {
      console.error(`Failed to close the cameras, error code: ${err.code}.`);
      return;
    }
    console.info('Callback returned with camera closed.');
  });
}
```

## close

close(): Promise\<void\>

Closes this camera device. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type          | Description                     |
| -------------- | ----------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function closeCameraInput(cameraInput: camera.CameraInput): void {
  cameraInput.close().then(() => {
    console.info('Promise returned with camera closed.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to close the cameras, error code: ${error.code}.`);
  }); 
}
```

## on('error')

on(type: 'error', camera: CameraDevice, callback: ErrorCallback): void

Subscribes to CameraInput error events. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Currently, you cannot use **off()** to unregister the callback in the callback method of **on()**.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a CameraInput instance is created. This event is triggered and the result is returned when an error occurs on the camera device. For example, if the camera device is unavailable or a conflict occurs, the error information is returned.|
| camera   | [CameraDevice](arkts-apis-camera-i.md#cameradevice)    | Yes  | Camera device.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | Yes  | Callback used to return an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode). |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Camera input error code: ${err.code}`);
}

function registerCameraInputError(cameraInput: camera.CameraInput, camera: camera.CameraDevice): void {
  cameraInput.on('error', camera, callback);
}
```

## off('error')

off(type: 'error', camera: CameraDevice, callback?: ErrorCallback): void

Unsubscribes from CameraInput error events.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a CameraInput instance is created. This event is triggered and the result is returned when an error occurs on the camera device. For example, if the camera device is unavailable or a conflict occurs, the error information is returned.|
| camera   | [CameraDevice](arkts-apis-camera-i.md#cameradevice)    | Yes  | Camera device.|
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | No  | Callback used to return the result. If this parameter is specified, the subscription to the specified event with the specified callback is canceled. (The callback object cannot be an anonymous function.) Otherwise, the subscriptions to the specified event with all the callbacks are canceled.|

**Example**

```ts
function unregisterCameraInputError(cameraInput: camera.CameraInput, camera: camera.CameraDevice): void {
  cameraInput.off('error', camera);
}
```

## isPhysicalCameraOrientationVariable<sup>21+</sup>

isPhysicalCameraOrientationVariable(): boolean

Checks whether the physical camera orientation is adjustable in different fold states.

**Atomic service API**: This API can be used in atomic services since API version 21.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                                        |
| ---------- | -------------------------------------------- |
| boolean    | Check result for whether the physical camera orientation is adjustable. **true** if adjustable, **false** otherwise.|

**Example**

```ts
function isPhysicalCameraOrientationVariable(cameraInput: camera.CameraInput): boolean {
  let isVariable: boolean = cameraInput.isPhysicalCameraOrientationVariable();
  return isVariable;
}
```

## getPhysicalCameraOrientation<sup>21+</sup>

getPhysicalCameraOrientation(): number

Obtains the physical camera orientation in the current fold state.

**Atomic service API**: This API can be used in atomic services since API version 21.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                                        |
| ---------- | -------------------------------------------- |
| number    | Physical camera orientation.|

**Example**

```ts
function getPhysicalCameraOrientation(cameraInput: camera.CameraInput): number {
  let physicalCameraOrientation: number = cameraInput.getPhysicalCameraOrientation();
  return physicalCameraOrientation;
}
```

## usePhysicalCameraOrientation<sup>21+</sup>

usePhysicalCameraOrientation(isUsed: boolean): void

Enables or disables the use of the physical camera orientation.

**Atomic service API**: This API can be used in atomic services since API version 21.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description                                              |
| -------- | ------------------------------------------- | ---- |--------------------------------------------------|
| isUsed  | boolean         | Yes  | Whether to enable the use of the physical camera orientation. **true** to enable, **false** otherwise.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message                                     |
|---------|-------------------------------------------|
| 7400102 | Operation not allowed.                    |
| 7400201 | Camera service fatal error.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function usePhysicalCameraOrientation(cameraInput: camera.CameraInput, isUsed: boolean): void {
  try {
    cameraInput.usePhysicalCameraOrientation(isUsed);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The usePhysicalCameraOrientation call failed. error code: ${err.code}`);
  }
}
```
