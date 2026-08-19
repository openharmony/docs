# Interface (OISQuery)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leoqsl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=b760a2cd044b1f4d1f1ca244edc82437a32735ff translatedAt=2026-08-11T01:59:32.391Z pushedAt=2026-08-11T11:00:50.557Z -->

This module describes the optical image stabilization (OIS) query object.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 24.

## Modules to Import

```ts
import { camera } from '@kit.CameraKit';
```

## isOISModeSupported<sup>24+</sup>

isOISModeSupported(mode: OISMode): boolean

Checks whether the specified OIS mode is supported.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Parameter    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| mode | [OISMode](arkts-apis-camera-e.md#oismode24) | Yes| OIS mode.|

**Returns**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Whether the device supports the specified OIS mode. The value **true** indicates that the device supports the specified OIS mode, and the value **false** indicates the opposite. |

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102 | Operation not allowed, the inputDevice or the session is abnormal. |
| 7400103 | Session not config. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isOISModeSupported(photoSession: camera.PhotoSession, mode: camera.OISMode): boolean {
  let isSupported = false;
  try {
    isSupported = photoSession.isOISModeSupported(mode);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The isOISModeSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```

## getSupportedOISBiasRange<sup>24+</sup>

getSupportedOISBiasRange(oisAxis: OISAxes): Array\<number\>

Obtains the supported bias range on the specified OIS axis.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Parameter    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| oisAxis | [OISAxes](arkts-apis-camera-e.md#oisaxes24) | Yes| OIS axis.|

**Returns**

| Type       | Description                         |
| ---------- | ----------------------------- |
| Array\<number\>    | Bias range.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102 | Operation not allowed, the inputDevice or the session is abnormal. |
| 7400103 | Session not config. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getSupportedOISBiasRange(photoSession: camera.PhotoSession, oisAxis: camera.OISAxes): Array<number> {
  let biasRange: Array<number> = [];
  try {
    biasRange = photoSession.getSupportedOISBiasRange(oisAxis);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The getSupportedOISBiasRange call failed. error code: ${err.code}`);
  }
  return biasRange;
}
```

## getSupportedOISBiasStep<sup>24+</sup>

getSupportedOISBiasStep(oisAxis: OISAxes): number

Obtains the bias step on the specified OIS axis.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Parameter    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| oisAxis | [OISAxes](arkts-apis-camera-e.md#oisaxes24) | Yes| OIS axis.|

**Returns**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Bias step.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102 | Operation not allowed, the inputDevice or the session is abnormal. |
| 7400103 | Session not config. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getSupportedOISBiasStep(photoSession: camera.PhotoSession, oisAxis: camera.OISAxes): number {
  let biasStep = 0.0;
  try {
    biasStep = photoSession.getSupportedOISBiasStep(oisAxis);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The getSupportedOISBiasStep call failed. error code: ${err.code}`);
  }
  return biasStep;
}
```

## getCurrentOISMode<sup>24+</sup>

getCurrentOISMode(): OISMode

Obtains the OIS mode.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Returns**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [OISMode](arkts-apis-camera-e.md#oismode24)    | OIS mode.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102 | Operation not allowed, the inputDevice or the session is abnormal. |
| 7400103 | Session not config. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getCurrentOISMode(photoSession: camera.PhotoSession): camera.OISMode {
  let mode: camera.OISMode = camera.OISMode.OFF;
  try {
    mode = photoSession.getCurrentOISMode();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The getCurrentOISMode call failed. error code: ${err.code}`);
  }
  return mode;
}
```

## getCurrentCustomOISBias<sup>24+</sup>

getCurrentCustomOISBias(oisAxis: OISAxes): number

Obtains the custom bias on the specified OIS axis.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 24.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Parameter    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| oisAxis | [OISAxes](arkts-apis-camera-e.md#oisaxes24) | Yes| OIS axis.|

**Returns**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Current bias.|

**Error codes**

For details about the error codes, see [Camera Error Codes](errorcode-camera.md).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102 | Operation not allowed, the inputDevice or the session is abnormal. |
| 7400103 | Session not config. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getCurrentCustomOISBias(photoSession: camera.PhotoSession, oisAxis: camera.OISAxes): number {
  let bias = 0.0;
  try {
    bias = photoSession.getCurrentCustomOISBias(oisAxis);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The getCurrentCustomOISBias call failed. error code: ${err.code}`);
  }
  return bias;
}
```