# Interface (AutoExposure)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 11.

AutoExposure inherits from [AutoExposureQuery](arkts-apis-camera-AutoExposureQuery.md).

It provides APIs related to auto exposure.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## getExposureMode<sup>11+</sup>

getExposureMode(): ExposureMode

Obtains the exposure mode in use.

**Atomic service API**: This API can be used in atomic services since API version 19.

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

function getExposureMode(photoSession: camera.PhotoSession): camera.ExposureMode | undefined {
  let exposureMode: camera.ExposureMode | undefined = undefined;
  try {
    exposureMode = photoSession.getExposureMode();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getExposureMode call failed. error code: ${err.code}`);
  }
  return exposureMode;
}
```

## setExposureMode<sup>11+</sup>

setExposureMode(aeMode: ExposureMode): void

Sets an exposure mode. Before the setting, call [isExposureModeSupported](arkts-apis-camera-AutoExposureQuery.md#isexposuremodesupported11) to check whether the exposure mode is supported.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                           | Mandatory| Description                   |
| -------- | -------------------------------| ---- | ----------------------- |
| aeMode   | [ExposureMode](arkts-apis-camera-e.md#exposuremode)  | Yes  | Exposure mode. If the input parameter is null or undefined, it is treated as 0 and exposure is locked.               |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102                | Operation not allowed.                                 |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setExposureMode(photoSession: camera.PhotoSession): void {
  try {
    photoSession.setExposureMode(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setExposureMode call failed. error code: ${err.code}`);
  }
}
```

## getMeteringPoint<sup>11+</sup>

getMeteringPoint(): Point

Obtains the metering point of the camera device.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [Point](arkts-apis-camera-i.md#point)    | Metering point obtained. If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID  | Error Message       |
|---------| --------------- |
| 7400103 |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getMeteringPoint(photoSession: camera.PhotoSession): camera.Point | undefined {
  let exposurePoint: camera.Point | undefined = undefined;
  try {
    exposurePoint = photoSession.getMeteringPoint();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getMeteringPoint call failed. error code: ${err.code}`);
  }
  return exposurePoint;
}
```

## setMeteringPoint<sup>11+</sup>

setMeteringPoint(point: Point): void

Sets the metering point, which is the center point of the metering rectangle.

The metering point must be in the coordinate system (0-1), where the upper left corner is {0, 0} and the lower right corner is {1, 1}.

The coordinate system is based on the horizontal device direction with the device's charging port on the right. If the layout of the preview screen of an application is based on the vertical direction with the charging port on the lower side, the layout width and height are {w, h}, and the touch point is {x, y}, then the coordinate point after conversion is {y/h, 1-x/w}.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                           | Mandatory| Description                |
| ------------- | -------------------------------| ---- | ------------------- |
| point | [Point](arkts-apis-camera-i.md#point)                | Yes  | Metering point. The value range of x and y must be within [0, 1]. If a value less than 0 is passed, the value **0** is used. If a value greater than **1** is passed, the value **1** is used.            |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setMeteringPoint(photoSession: camera.PhotoSession): void {
  const point: camera.Point = {x: 1, y: 1};
  try {
    photoSession.setMeteringPoint(point);
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The setMeteringPoint call failed. error code: ${err.code}`);
  }
}
```

## setExposureBias<sup>11+</sup>

setExposureBias(exposureBias: number): void

Sets an exposure compensation value (EV).

Before the setting, you are advised to use [getExposureBiasRange](arkts-apis-camera-AutoExposureQuery.md#getexposurebiasrange11) to obtain the supported values.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                           | Mandatory| Description                                                                                                                                                                                           |
| -------- | -------------------------------| ---- |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| exposureBias   | number                   | Yes  | EV. The supported EV range can be obtained by calling [getExposureBiasRange](arkts-apis-camera-AutoExposureQuery.md#getexposurebiasrange11). If the value passed is not within the supported range, the nearest critical point is used.<br>There is a step for EV. For example, if the step is 0.5 and this parameter is set to 1.2, the EV that takes effect is 1.0.<br>If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102                |  Operation not allowed.                                |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setExposureBias(photoSession: camera.PhotoSession, biasRangeArray: Array<number>): void {
  if (biasRangeArray && biasRangeArray.length > 0) {
    let exposureBias = biasRangeArray[0];
    try {
      photoSession.setExposureBias(exposureBias);
    } catch (error) {
      // If the operation fails, error.code is returned and processed.
      let err = error as BusinessError;
      console.error(`The setExposureBias call failed. error code: ${err.code}`);
    }
  }
}
```

## getExposureValue<sup>11+</sup>

getExposureValue(): number

Obtains the exposure value in use.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Exposure value obtained. There is a step for EV. For example, if the step is 0.5 and this parameter is set to 1.2, the EV that takes effect is 1.0.<br>If the operation fails, an error code defined in [CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureValue(photoSession: camera.PhotoSession): number {
  const invalidValue: number = -1;
  let exposureValue: number = invalidValue;
  try {
    exposureValue = photoSession.getExposureValue();
  } catch (error) {
    // If the operation fails, error.code is returned and processed.
    let err = error as BusinessError;
    console.error(`The getExposureValue call failed. error code: ${err.code}`);
  }
  return exposureValue;
}
```
