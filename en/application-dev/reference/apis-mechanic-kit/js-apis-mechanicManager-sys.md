# @ohos.distributedHardware.mechanicManager (Mechanic Manager) (System API)
<!--Kit: Mechanic Kit-->
<!--Subsystem: Mechanic-->
<!--Owner: @hobbycao-->
<!--Designer: @saga2025-->
<!--Tester: @zhaodengqi-->
<!--Adviser: @foryourself-->

The **mechanicManager** module provides the mechanic device interaction capabilities, such as connection management, device control, and monitoring.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.distributedHardware.mechanicManager (Mechanic Manager)](js-apis-mechanicManager.md).

## Modules to Import

```js
import { mechanicManager } from '@kit.MechanicKit';
```

## mechanicManager.setUserOperation

setUserOperation(operation: Operation, mac: string, params: string): void

Sets the the user operation, such as connection or disconnection.

**Required permissions**: ohos.permission.CONNECT_MECHANIC_HARDWARE

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                   | Mandatory| Description  |
| ---------- | ---------------------- | ---- | ----- |
| operation | [Operation](#operation) | Yes| Operation type.|
| mac | string | Yes| MAC address of the mechanic device.|
| params | string | Yes| Operation parameters.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 33300001 | Service exception. |

**Example**

```ts
console.info('User operate');
mechanicManager.setUserOperation(mechanicManager.Operation.CONNECT, "58:51:9e:e7:79:6d", "operatingParams");
console.info('User operation was successful');
```

## mechanicManager.setCameraTrackingLayout

setCameraTrackingLayout(trackingLayout: CameraTrackingLayout): void

Sets the camera tracking layout of the current mechanic device.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                   | Mandatory| Description  |
| ---------- | ---------------------- | ---- | ----- |
| trackingLayout | [CameraTrackingLayout](js-apis-mechanicManager.md#cameratrackinglayout) | Yes| Camera tracking layout.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message          |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |
| 33300003 | Feature not supported. |

**Example**

```ts
console.info('Set layout');
mechanicManager.setCameraTrackingLayout(mechanicManager.CameraTrackingLayout.LEFT);
console.info('Set layout successful');
```

## mechanicManager.rotate

rotate(mechId: number, angles: RotationAngles, duration: number): Promise\<Result>

Rotates a mechanic device to the relative angles. This API uses a promise to return the result.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                   | Mandatory| Description  |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | Yes| ID of the mechanic device.|
| angles | [RotationAngles](#rotationangles) | Yes| Rotation angle relative to the current position.|
| duration | number | Yes| Rotation duration, in milliseconds.|

**Return value**

| Type                                       | Description       |
| ------------------------------------------- | --------- |
| Promise\<[Result](#result)> | Promise used to return the rotation result.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message          |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**Example**

```ts
console.info('Start rotate');
let degree: mechanicManager.RotationAngles = {
  yaw: 0.1 * Math.PI,
  roll: 0.0,
  pitch: 0.0
}
mechanicManager.rotate(0, degree, 500)
  .then((result: mechanicManager.Result) => {
    console.info(`'Rotate result:' ${result}`);
  });
console.info('End rotation');
```

## mechanicManager.rotateToEulerAngles

rotateToEulerAngles(mechId: number, angles: EulerAngles, duration: number): Promise\<Result>

Rotates a mechanic device to the absolute angles. This API uses a promise to return the result.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                   | Mandatory| Description  |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | Yes| ID of the mechanic device.|
| angles | [EulerAngles](#eulerangles) | Yes| Absolute angle.|
| duration | number | Yes| Rotation duration, in milliseconds.|

**Return value**

| Type                                       | Description       |
| ------------------------------------------- | --------- |
| Promise\<[Result](#result)> | Promise used to return the rotation result.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message          |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**Example**

```ts
let degree: mechanicManager.EulerAngles = {
  yaw: 0.9 * Math.PI,
  roll: 0.9 * Math.PI,
  pitch: 0.9 * Math.PI
}
mechanicManager.rotateToEulerAngles(0, degree, 500)
  .then((result: mechanicManager.Result) => {
    console.info(`'Rotate result:' ${result}`);
  });
console.info('End rotation');
```

## mechanicManager.getMaxRotationTime

getMaxRotationTime(mechId: number): number

Obtains the maximum duration for continuous rotation of a mechanic device.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                   | Mandatory| Description  |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | Yes| ID of the mechanic device.|

**Return value**

| Type                                       | Description       |
| ------------------------------------------- | --------- |
| number | Maximum rotation duration, in milliseconds.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message |
| -------- | -------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**Example**

```ts
console.info('Query maximum rotation time');
let maxTime = mechanicManager.getMaxRotationTime(0);
console.info(`'Query maximum rotation time successful, maximum time:' ${maxTime}`);
```

## mechanicManager.getMaxRotationSpeed

getMaxRotationSpeed(mechId: number): RotationSpeed

Obtains the maximum rotation speed of a mechanic device.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                   | Mandatory| Description  |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | Yes| ID of the mechanic device.|

**Return value**

| Type                                       | Description       |
| ------------------------------------------- | --------- |
| [RotationSpeed](#rotationspeed) | Maximum rotation speed (absolute value).|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message          |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**Example**

```ts
console.info('Query rotation speed');
let speedLimit: mechanicManager.RotationSpeed = mechanicManager.getMaxRotationSpeed(0);
console.info(`'Query rotation speed successful, speed limit information:' ${speedLimit}`);
```

## mechanicManager.rotateBySpeed

rotateBySpeed(mechId: number, speed: RotationSpeed, duration: number): Promise\<Result>

Rotates the current body at the specified speed.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                   | Mandatory| Description  |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | Yes| ID of the mechanic device.|
| speed | [RotationSpeed](#rotationspeed) | Yes| Specified rotation speed. If the specified value is greater than the value returned by **getMaxRotationSpeed**, the value returned by **getMaxRotationSpeed** is used by default.|
| duration | number | Yes| Rotation duration, in milliseconds. If the specified value is greater than the value returned by **getMaxRotationTime**, the value returned by **getMaxRotationTime** is used by default.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message          |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**Example**

```ts
console.info('Start rotate');
let degree: mechanicManager.RotationSpeed = {
  yawSpeed: 3 * Math.PI,
  rollSpeed: 3 * Math.PI,
  pitchSpeed: 3 * Math.PI
}
mechanicManager.rotateBySpeed(0, degree, 500)
  .then((result) => {
    console.info(`'Rotate result:' ${result}`);
  });
console.info('Rotate finish');
```

## mechanicManager.stopMoving

stopMoving(mechId: number): Promise\<void>

Stops movement of a mechanic device. This API uses a promise to return the result.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                   | Mandatory| Description  |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | Yes| ID of the mechanic device.|

**Return value**

| Type                                       | Description       |
| ------------------------------------------- | --------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message          |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**Example**

```ts
console.info('Stop moving');
mechanicManager.stopMoving(0)
  .then(() => {
    console.info('Get stop complete');
  });
console.info('Stop succeeded');
```

## mechanicManager.getCurrentAngles

getCurrentAngles(mechId: number): EulerAngles

Obtains the maximum rotation angle of a mechanic device relative to the initial position.

> **NOTE**
>
> The coordinates of the initial position are (0, 0, 0).

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                   | Mandatory| Description  |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | Yes| ID of the mechanic device.|

**Return value**

| Type                                       | Description       |
| ------------------------------------------- | --------- |
| [EulerAngles](#eulerangles) | Current rotation angle of the mechanic device.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message          |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**Example**

```ts
console.info('Query current location');
let currentAngles: mechanicManager.EulerAngles = mechanicManager.getCurrentAngles(0);
console.info(`'Query current location, location:' ${currentAngles}`);
```

## mechanicManager.getRotationLimits

getRotationLimits(mechId: number): RotationLimits

Obtains the maximum rotation angle of a mechanic device relative to the initial position.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                   | Mandatory| Description  |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | Yes| ID of the mechanic device.|

**Return value**

| Type                                       | Description       |
| ------------------------------------------- | --------- |
| [RotationLimits](#rotationlimits) | Maximum rotation angle.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message          |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**Example**

```ts
console.info('Query rotation limit information');
let degreeLimit: mechanicManager.RotationLimits = mechanicManager.getRotationLimits(0);
console.info(`'Query the rotation limit information successfully, limit information:' ${degreeLimit}`);
```

## mechanicManager.on('rotationAxesStatusChange')

on(type: 'rotationAxesStatusChange', callback: Callback\<RotationAxesStateChangeInfo>): void

Registers a callback listener for rotation axis state change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                   | Mandatory| Description  |
| ---------- | ---------------------- | ---- | ----- |
| type | 'rotationAxesStatusChange' | Yes| Event type. The value **rotationAxesStatusChange** indicates a rotation axis state change.|
| callback | Callback\<[RotationAxesStateChangeInfo](#rotationaxesstatechangeinfo)> | Yes| Callback used to return the rotation axis state change.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message          |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |

**Example**

```ts
console.info('Register Axis Status listener');
mechanicManager.on("rotationAxesStatusChange", (result: mechanicManager.RotationAxesStateChangeInfo) => {
  console.info(`'result:' ${result}`);
});
console.info('Successful registration');
```

## mechanicManager.off('rotationAxesStatusChange')

off(type: 'rotationAxesStatusChange', callback?: Callback\<RotationAxesStateChangeInfo>): void

Unregisters the callback listener for rotation axis state changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                   | Mandatory| Description  |
| ---------- | ---------------------- | ---- | ----- |
| type | 'rotationAxesStatusChange' | Yes| Event type. The value **rotationAxesStatusChange** indicates a rotation axis state change.|
| callback | Callback\<[RotationAxesStateChangeInfo](#rotationaxesstatechangeinfo)> | No|  Callback to unregister. If this parameter is not specified, all callbacks for the specified type of events are unregistered.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message          |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |

**Example**

```ts
console.info('Unregister Axis Status listener');
mechanicManager.off("rotationAxesStatusChange", (result: mechanicManager.RotationAxesStateChangeInfo) => {
  console.info(`'result:' ${result}`);
});
console.info('Unregister successfully');
```

## mechanicManager.getRotationAxesStatus

getRotationAxesStatus(mechId: number): RotationAxesStatus

Obtains the rotation axis status of the current mechanic device.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                   | Mandatory| Description  |
| ---------- | ---------------------- | ---- | ----- |
| mechId | number | Yes| ID of the mechanic device.|

**Return value**

| Type                                       | Description       |
| ------------------------------------------- | --------- |
| [RotationAxesStatus](#rotationaxesstatus) | Rotation axis status.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message          |
| -------- | ----------------- |
| 202 | Not system application. |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**Example**

```ts
console.info('Query the rotation axis status');
let axisStatus: mechanicManager.RotationAxesStatus = mechanicManager.getRotationAxesStatus(0);
console.info(`'Query the rotation axis status successfully, axis state:' ${axisStatus}`);
```

## RotationAngles

Defines the rotation angle relative to the current position.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

| Name  | Type| Read-Only| Optional| Description|
| ----- | ---- | ---- | --- | --- |
| yaw | number | No| Yes| Yaw angle, in radians. The value range is [-2\*Math.PI, 2\*Math.PI].|
| roll | number | No| Yes| Roll angle, in radians. The value range is [-2\*Math.PI, 2\*Math.PI].|
| pitch | number | No| Yes| Pitch angle, in radians. The value range is [-2\*Math.PI, 2\*Math.PI].|

## EulerAngles

Defines the absolute Euler angle relative to the initial position.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

| Name  | Type| Read-Only| Optional| Description|
| ----- | ---- | ---- | --- | --- |
| yaw | number | No| Yes| Yaw angle, in radians. The value range is [-2\*Math.PI, 2\*Math.PI].|
| roll | number | No| Yes| Roll angle, in radians. The value range is [-2\*Math.PI, 2\*Math.PI].|
| pitch | number | No| Yes| Pitch angle, in radians. The value range is [-2\*Math.PI, 2\*Math.PI].|

## RotationSpeed

Defines the rotation speed. A negative value indicates clockwise rotation, and a positive value indicates anticlockwise rotation.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

| Name  | Type| Read-Only| Optional| Description|
| ----- | ---- | ---- | --- | --- |
| yawSpeed | number | No| Yes| Yaw speed, in radians per second.|
| rollSpeed | number | No| Yes| Roll speed, in radians per second.|
| pitchSpeed | number | No| Yes| Pitch speed, in radians per second.|

## RotationLimits

Defines the limit of the rotation angle relative to the initial position.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

| Name  | Type| Read-Only| Optional| Description|
| ----- | ---- | ---- | --- | --- |
| negativeYawMax | number | No| No| Maximum yaw rotation angle (negative direction). The value range is [-2\*Math.PI, 0], in radians. If the value is less than or equal to **-2\*Math.PI**, there is no limitation on the rotation angle.|
| positiveYawMax | number | No| No| Maximum yaw rotation angle (positive direction). The value range is [0, 2\*Math.PI], in radians. If the value is greater than or equal to **2\*Math.PI**, there is no limitation on the rotation angle.|
| negativeRollMax | number | No| No| Maximum roll rotation angle (negative direction), in radians. The value range is [–2 x Math.PI, 0]. If the value is less than or equal to **-2\*Math.PI**, there is no limitation on the rotation angle.|
| positiveRollMax | number | No| No| Maximum roll rotation angle (positive direction), in radians. The value range is [0, 2 x Math.PI]. If the value is greater than or equal to **2\*Math.PI**, there is no limitation on the rotation angle.|
| negativePitchMax | number | No| No| Maximum pitch rotation angle (negative direction), in radians. The value range is [–2 x Math.PI, 0]. If the value is less than or equal to **-2\*Math.PI**, there is no limitation on the rotation angle.|
| positivePitchMax | number | No| No| Maximum pitch rotation angle (positive direction), in radians. The value range is [0, 2 x Math.PI]. If the value is greater than or equal to **2\*Math.PI**, there is no limitation on the rotation angle.|

## RotationAxesStatus

Enumerates the rotation axis states.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

| Name  | Type| Read-Only| Optional| Description|
| ----- | ---- | ---- | --- | --- |
| yawEnabled | boolean | No| No| Whether the yaw axis is enabled. The value **true** indicates that the yaw axis is enabled, and the value **false** indicates the opposite.|
| rollEnabled | boolean | No| No| Whether the roll axis is enabled. The value **true** indicates that the roll axis is enabled, and the value **false** indicates the opposite.|
| pitchEnabled | boolean | No| No| Whether the pitch axis is enabled. The value **true** indicates that the pitch axis is enabled, and the value **false** indicates the opposite.|
| yawLimited | [RotationAxisLimited](#rotationaxislimited) | No| Yes| Yaw axis limited.|
| rollLimited | [RotationAxisLimited](#rotationaxislimited) | No| Yes| Roll axis limited.|
| pitchLimited | [RotationAxisLimited](#rotationaxislimited) | No| Yes| Pitch axis limited.|

## RotationAxisLimited

Enumerates the rotation axis limit states.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

| Name        | Value | Description             |
| ----------- | ---- | --------------- |
| NOT_LIMITED | 0 | Unlimited.|
| NEGATIVE_LIMITED | 1 | Rotation is restricted in the negative direction and allowed in the positive direction.|
| POSITIVE_LIMITED | 2 | Rotation is restricted in the positive direction and allowed in the negative direction.|

## RotationAxesStateChangeInfo

Defines the rotation axis state change information.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

| Name  | Type| Read-Only| Optional| Description|
| ----- | ---- | ---- | --- | --- |
| mechId | number | No| No| ID of the mechanic device.|
| status | [RotationAxesStatus](#rotationaxesstatus)| No| No| Rotation axis status.|

## Operation

Enumerates user operations.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

| Name        | Value | Description             |
| ----------- | ---- | --------------- |
| CONNECT | 0 | Connection.|
| DISCONNECT | 1 | Disconnection.|

## Result

Enumerates the rotation results.

**System capability**: SystemCapability.Mechanic.Core

**System API**: This is a system API.

| Name        | Value | Description             |
| ----------- | ---- | --------------- |
| COMPLETED | 0 | Completed.|
| INTERRUPTED | 1 | Interrupted.|
| LIMITED | 2 | Restricted by the maximum rotation angle.|
| TIMEOUT | 3 | Operation timeout.|
| SYSTEM_ERROR | 100 | System error.|
