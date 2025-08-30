# @ohos.distributedHardware.mechanicManager (Mechanic Manager)
<!--Kit: Mechanic Kit-->
<!--Subsystem: Mechanic-->
<!--Owner: @hobbycao-->
<!--Designer: @saga2025-->
<!--Tester: @zhaodengqi-->
<!--Adviser: @foryourself-->

The **mechanicManager** module provides the mechanic device interaction capabilities, such as listening for the device connection status, tracking control, and listening for the tracking status.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { mechanicManager } from '@kit.MechanicKit';
```

## mechanicManager.on('attachStateChange')

on(type: 'attachStateChange', callback: Callback\<AttachStateChangeInfo>): void

Registers a callback listener for connection state changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Mechanic.Core

**Parameters**

| Name    | Type          | Mandatory| Description    |
| ---------- | ------------- | ---- | ------- |
| type | 'attachStateChange' | Yes| Event type. The value **attachStateChange** indicates a connection state change.|
| callback | Callback\<[AttachStateChangeInfo](#attachstatechangeinfo)> | Yes| Callback used to return the connection state change of the mechanic device.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md).

| ID| Error Message          |
| -------- | ----------------- |
| 33300001 | Service exception. |

**Example**

```ts
let callback = (result: mechanicManager.AttachStateChangeInfo) => {
  console.info(`'callback result:' ${result}`);
};

console.info('Register');
mechanicManager.on("attachStateChange", callback);
console.info('Register: success');
```

## mechanicManager.off('attachStateChange')

off(type: 'attachStateChange', callback?: Callback\<AttachStateChangeInfo>): void

Unregisters the callback listener for connection state changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Mechanic.Core

**Parameters**

| Name    | Type          | Mandatory| Description  |
| ---------- | ------------- | ---- | ----- |
| type | 'attachStateChange' | Yes| Event type. The value **attachStateChange** indicates a connection state change.|
| callback | Callback\<[AttachStateChangeInfo](#attachstatechangeinfo)> | No| Callback to unregister. If this parameter is not specified, all callbacks for the specified type of events are unregistered.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md).

| ID| Error Message          |
| -------- | ----------------- |
| 33300001 | Service exception. |

**Example**

```ts
let callback = (result: mechanicManager.AttachStateChangeInfo) => {
  console.info(`'callback result:' ${result}`);
};

console.info('Unregister');
mechanicManager.off("attachStateChange", callback);
console.info('Unregister: success');
```

## mechanicManager.getAttachedMechDevices

getAttachedMechDevices(): MechInfo[]

Obtain the list of connected mechanic devices.

**System capability**: SystemCapability.Mechanic.Core

**Return value**

| Type                                       | Description       |
| ------------------------------------------- | --------- |
| [MechInfo](#mechinfo)[] | List of connected mechanic devices.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md).

| ID| Error Message          |
| -------- | ----------------- |
| 33300001 | Service exception. |

**Example**

```ts
console.info('Query device list');
let mechanicInfos = mechanicManager.getAttachedMechDevices();
console.info(`'device list:' ${mechanicInfos}`);
```

## mechanicManager.setCameraTrackingEnabled

setCameraTrackingEnabled(isEnabled: boolean): void

Enables or disables camera tracking for the current mechanic device.

**System capability**: SystemCapability.Mechanic.Core

**Parameters**

| Name    | Type   | Mandatory| Description           |
| --------- | ------- | ---- | -------------  |
| isEnabled | boolean | Yes| Whether to enable camera tracking. The value **true** means to enable camera tracking, and the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md).

| ID| Error Message |
| -------- | ------- |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |
| 33300003 | Feature not supported. |

**Example**

```ts
console.info('Enable tracing');
mechanicManager.setCameraTrackingEnabled(true);
console.info('Enable Tracking Success');
```

## mechanicManager.getCameraTrackingEnabled

getCameraTrackingEnabled(): boolean

Checks whether camera tracking is enabled for the current mechanic device.

**System capability**: SystemCapability.Mechanic.Core

**Return value**

| Type   | Description      |
| ------- | --------- |
| boolean | Whether camera tracking is enabled. The value **true** indicates that camera tracking is enabled, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md).

| ID| Error Message          |
| -------- | ----------------- |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**Example**

```ts
console.info('Get tracking status');
let enabled = mechanicManager.getCameraTrackingEnabled();
console.info(`'current tracking status:' ${enabled}`);
```

## mechanicManager.on('trackingStateChange')

on(type: 'trackingStateChange', callback: Callback\<TrackingEventInfo>): void

Registers a callback listener for tracking state changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Mechanic.Core

**Parameters**

| Name    | Type                   | Mandatory| Description  |
| ---------- | ---------------------- | ---- | ----- |
| type | 'trackingStateChange' | Yes| Event type. The value **trackingStateChange** indicates a tracking state change.|
| callback | Callback\<[TrackingEventInfo](#trackingeventinfo)> | Yes| Callback used to return the tracking state change of the mechanic device.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 33300001 | Service exception. |

**Example**

```ts
let callback = (result: mechanicManager.TrackingEventInfo) => {
  console.info(`'callback result:' ${result}`);
};

console.info('Register');
mechanicManager.on("trackingStateChange", callback);
console.info('Register: success');
```

## mechanicManager.off('trackingStateChange')

off(type: 'trackingStateChange', callback?: Callback\<TrackingEventInfo>): void

Unregisters the callback listener for tracking state changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Mechanic.Core

**Parameters**

| Name    | Type                   | Mandatory| Description  |
| ---------- | ---------------------- | ---- | ----- |
| type | 'trackingStateChange' | Yes| Event type. The value **trackingStateChange** indicates a tracking state change.|
| callback | Callback\<[TrackingEventInfo](#trackingeventinfo)> | No| Callback to unregister. If this parameter is not specified, all callbacks for the specified type of events are unregistered.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 33300001 | Service exception. |

**Example**

```ts
let callback = (result: mechanicManager.TrackingEventInfo) => {
  console.info(`'callback result:' ${result}`);
};

console.info('Unregister');
mechanicManager.off("trackingStateChange", callback);
console.info('Unregister: success');
```

## mechanicManager.getCameraTrackingLayout

getCameraTrackingLayout(): CameraTrackingLayout

Obtains the camera tracking layout of the current mechanic device.

**System capability**: SystemCapability.Mechanic.Core

**Return value**

| Type                                       | Description       |
| ------------------------------------------- | --------- |
| [CameraTrackingLayout](#cameratrackinglayout) | Camera tracking layout of the current mechanic device.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md).

| ID| Error Message          |
| -------- | ----------------- |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**Example**

```ts
console.info('Query layout');
let layout = mechanicManager.getCameraTrackingLayout();
console.info(`'Query layout successful, current layout:' ${layout}`);
```

## MechInfo

Defines information about the mechanic device.

**System capability**: SystemCapability.Mechanic.Core

| Name  | Type| Read-Only| Optional| Description|
| ----- | ---- | ---- | --- | --- |
| mechId | number | No| No| ID of the mechanic device.|
| mechDeviceType | [MechDeviceType](#mechdevicetype) | No| No| Type of the mechanic device.|
| mechName | string | No| No| Name of the mechanic device.|

## TrackingEventInfo

Defines the tracking event information.

**System capability**: SystemCapability.Mechanic.Core

| Name  | Type| Read-Only| Optional| Description|
| ----- | ---- | ---- | --- | --- |
| event | [TrackingEvent](#trackingevent) | No| No| Tracking event.|

## AttachStateChangeInfo

Defines the connection state change information.

**System capability**: SystemCapability.Mechanic.Core

| Name  | Type| Read-Only| Optional| Description|
| ----- | ---- | ---- | --- | --- |
| state | [AttachState](#attachstate) | No| No| Device connection state.|
| mechInfo | [MechInfo](#mechinfo) | No| No| Device information.|

## TrackingEvent

Enumerates the camera tracking events.

**System capability**: SystemCapability.Mechanic.Core

| Name        | Value | Description             |
| ----------- | ---- | --------------- |
| CAMERA_TRACKING_USER_ENABLED | 0 | Camera tracking is enabled.|
| CAMERA_TRACKING_USER_DISABLED | 1 | Camera tracking is disabled.|
| CAMERA_TRACKING_LAYOUT_CHANGED | 2 | The camera tracking layout is changed.|

## MechDeviceType

Enumerates the mechanic device types.

**System capability**: SystemCapability.Mechanic.Core

| Name        | Value | Description             |
| ----------- | ---- | --------------- |
| GIMBAL_DEVICE | 0 | Portable gimbal device.|

## AttachState

Enumerates the device connection states.

**System capability**: SystemCapability.Mechanic.Core

| Name        | Value | Description             |
| ----------- | ---- | --------------- |
| ATTACHED | 0 | Device connected.|
| DETACHED | 1 | Device disconnected.|

## CameraTrackingLayout

Enumerates the camera tracking layouts.

**System capability**: SystemCapability.Mechanic.Core

| Name        | Value | Description             |
| ----------- | ---- | --------------- |
| DEFAULT | 0 | Default tracking layout.|
| LEFT | 1 | Left layout.|
| MIDDLE | 2 | Center layout.|
| RIGHT | 3 | Right layout.|
