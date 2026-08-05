# @ohos.distributedHardware.mechanicManager (Mechanic Manager)

<!--Kit: Mechanic Kit-->
<!--Subsystem: Mechanic-->
<!--Owner: @qxqxqxqxqx-->
<!--Designer: @peter__1024-->
<!--Tester: @Aullar-->
<!--Adviser: @hu-zhiqiong-->
<!-- md-trans-meta sourceCommit=bc68323f1c1e5ede3ca50670c5ffb68762f3f748 translatedAt=2026-08-05T01:26:51.110Z pushedAt=2026-08-05T01:55:24.450Z -->

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
// Define the callback for device connection state changes. The result parameter carries the device connection state change information.
let callback = (result: mechanicManager.AttachStateChangeInfo) => {
  console.info(`'callback result:' ${result}`);
};

// Print a log indicating the listener registration starts.
console.info('Register');
// Register the attachStateChange event listener. The callback is triggered when the device connection state changes.
mechanicManager.on("attachStateChange", callback);
// Print a log indicating that the listener is registered successfully.
console.info('Succeeded in registering callback.');
```

## mechanicManager.off('attachStateChange')

off(type: 'attachStateChange', callback?: Callback\<AttachStateChangeInfo>): void

Unregisters the callback listener for connection state changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Mechanic.Core

**Parameters**

| Name    | Type          | Mandatory| Description  |
| ---------- | ------------- | ---- | ----- |
| type | 'attachStateChange' | Yes| Event type. The value **attachStateChange** indicates a connection state change.|
| callback | Callback\<[AttachStateChangeInfo](#attachstatechangeinfo)> | No| Callback used to return the connection state change of the mechanic device.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md).

| ID| Error Message          |
| -------- | ----------------- |
| 33300001 | Service exception. |

**Example**

```ts
// Define the callback function for device connection state changes.
let callback = (result: mechanicManager.AttachStateChangeInfo) => {
  console.info(`'callback result:' ${result}`);
};

console.info('Unregister');
// Unregister the attachStateChange event listener.
mechanicManager.off("attachStateChange", callback);
console.info('Succeeded in unregistering callback.');
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
// Call getAttachedMechDevices to obtain the list of attached mechanic devices.
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
| isEnabled | boolean | Yes| Whether to enable camera tracking. The value **true** indicates yes, and the value **false** indicates no.|

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
// Call the setCameraTrackingEnabled method. The value true indicates enabling camera tracking.
mechanicManager.setCameraTrackingEnabled(true);
console.info('Succeeded in enabling tracking.');
```

## mechanicManager.getCameraTrackingEnabled

getCameraTrackingEnabled(): boolean

Checks whether camera tracking is enabled for the current mechanic device.

**System capability**: SystemCapability.Mechanic.Core

**Return value**

| Type   | Description      |
| ------- | --------- |
| boolean | Whether camera tracking is enabled. The value **true** indicates yes, and the value **false** indicates no.|

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md).

| ID| Error Message          |
| -------- | ----------------- |
| 33300001 | Service exception. |
| 33300002 | Device not connected. |

**Example**

```ts
console.info('Get tracking status');
// Call getCameraTrackingEnabled to obtain whether camera tracking is currently enabled.
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
// Define the callback for tracking state changes. The result is the tracking event information.
let callback = (result: mechanicManager.TrackingEventInfo) => {
  console.info(`'callback result:' ${result}`);
};

console.info('Register');
// Register the trackingStateChange event listener. The callback is triggered when the tracking state changes.
mechanicManager.on("trackingStateChange", callback);
console.info('Succeeded in registering callback.');
```

## mechanicManager.off('trackingStateChange')

off(type: 'trackingStateChange', callback?: Callback\<TrackingEventInfo>): void

Unregisters the callback listener for tracking state changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Mechanic.Core

**Parameters**

| Name    | Type                   | Mandatory| Description  |
| ---------- | ---------------------- | ---- | ----- |
| type | 'trackingStateChange' | Yes| Event type. The value **trackingStateChange** indicates a tracking state change.|
| callback | Callback\<[TrackingEventInfo](#trackingeventinfo)> | No | Callback used to return the tracking event information. |

**Error codes**

For details about the error codes, see [Mechanic Manager Error Codes](errorcode-mechanic.md).

| ID| Error Message                                                       |
| -------- | --------------------------------------------------------------- |
| 33300001 | Service exception. |

**Example**

```ts
// Define the callback function for tracking state changes.
let callback = (result: mechanicManager.TrackingEventInfo) => {
  console.info(`'callback result:' ${result}`);
};

console.info('Unregister');
// Unregister the trackingStateChange event listener.
mechanicManager.off("trackingStateChange", callback);
console.info('Succeeded in unregistering callback.');
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
// Call getCameraTrackingLayout to obtain the current camera tracking layout.
let layout = mechanicManager.getCameraTrackingLayout();
console.info(`'Succeeded in querying layout, current layout:' ${layout}`);
```

## mechanicManager.isControlSupported()

isControlSupported(mechDeviceType?: MechDeviceType): boolean

Determines whether the current device supports mechanic device control for a specific device type, so that the app can make appropriate feature selections. For example, the app can decide whether to use its own tracking control function or the system's default control function, or provide a prompt to the user. Third-party vendor apps can use this API to determine whether the current device supports mechanic control and intelligent tracking for a specific device type, and then decide whether to use the app's own tracking control function, or directly use the tracking function provided by the system, or provide a prompt to the user.

**Since**: 26.0.0

**System capability:** SystemCapability.Mechanic.Core

**Parameters**

| Name     | Type                    | Mandatory | Description   |
| ---------- | ---------------------- | ---- | ----- |
| mechDeviceType | [MechDeviceType](#mechdevicetype)  | No | Type of the mechanic device.|

**Return value**

| Type                                        | Description        |
| ------------------------------------------- | --------- |
| boolean | Whether the current device supports mechanic device control for a certain type of device. The value **true** indicates yes, and **false** indicates no.|

**Example**

```ts
console.info('Check whether control is supported');
// Call the isControlSupported method and pass MechDeviceType.GIMBAL_DEVICE to check whether gimbal device control is supported.
let isSupported = mechanicManager.isControlSupported(mechanicManager.MechDeviceType.GIMBAL_DEVICE);
console.info(`isSupported: ${isSupported}`);
```

## MechInfo

Defines information about the mechanic device.

**System capability**: SystemCapability.Mechanic.Core

| Name  | Type| Read-Only| Optional| Description|
| ----- | ---- | ---- | --- | --- |
| mechId | number | No| No| ID of the mechanic device. The value is an integer greater than or equal to 0.|
| mechDeviceType | [MechDeviceType](#mechdevicetype) | No| No| Type of the mechanic device.|
| mechName | string | No | No | Mechanic device name. The length cannot exceed 64 characters. |

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