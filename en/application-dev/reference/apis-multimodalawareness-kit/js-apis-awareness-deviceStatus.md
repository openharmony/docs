# @ohos.multimodalAwareness.deviceStatus (Device Status Awareness)

The deviceStatus module provides the device status awareness functionality.

> **NOTE**
>
> The initial APIs of this module are supported since API version 18. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

  ```ts
  import { deviceStatus } from '@kit.MultimodalAwarenessKit';
  ```

## SteadyStandingStatus

Defines the steady standing state (that is, stand mode).

A device enters stand mode when it is stationary, and its screen is at an angle between 45 and 135 degrees relative to the horizontal plane. For foldable smartphones, the device must be in a folded state or fully unfolded state.

**System capability**: SystemCapability.MultimodalAwareness.DeviceStatus

| Name               | Value  | Description                  |
| ------------------- | ---- | ---------------------- |
| STATUS_EXIT  | 0    | Exit of the stand mode.|
| STATUS_ENTER | 1    | Entry to the stand mode.|

## deviceStatus.on('steadyStandingDetect')

 on(type: 'steadyStandingDetect', callback: Callback&lt;SteadyStandingStatus&gt;): void;

Subscribes to steady standing state events.

**System capability**: SystemCapability.MultimodalAwareness.DeviceStatus

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | Yes  | Event type. This field has a fixed value of **steadyStandingDetect**.|
| callback | Callback&lt;[SteadyStandingStatus](#steadystandingstatus)&gt; | Yes  | Callback used to return the steady standing state of the device.|

**Error codes**

For details about the error codes, see [Device Status Awareness Error Codes](errorcode-deviceStatus.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 32500001 | Service exception. |
| 32500002 | Subscription failed. |

**Example**

  ```ts
  try {
    deviceStatus.on('steadyStandingDetect', (data:deviceStatus.SteadyStandingStatus) => {
      console.info('now status = ' + data);
    });
  } catch (err) {
    console.info('on failed, err = ' + err);
  }
  ```

## deviceStatus.off('steadyStandingDetect')

off(type: 'steadyStandingDetect', callback?: Callback&lt;SteadyStandingStatus&gt;): void;

Unsubscribes from steady standing state events.

**System capability**: SystemCapability.MultimodalAwareness.DeviceStatus

**Parameters**

| Name  | Type                            | Mandatory| Description                                                        |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                           | Yes  | Event type. This field has a fixed value of **steadyStandingDetect**.|
| callback | Callback&lt;[SteadyStandingStatus](#steadystandingstatus)&gt; | Yes  | Callback used to return the steady standing state of the device.|

**Error codes**

For details about the error codes, see [Device Status Awareness Error Codes](errorcode-deviceStatus.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 32500001 | Service exception. |
| 32500003 | Unsubscription failed. |

**Example**

Example 1: Unsubscribe from all callbacks of steady standing state change events.

  ```ts
  try {
    deviceStatus.off('steadyStandingDetect');
  } catch (err) {
    console.info('off failed, err = ' + err);
  }
  ```

Example 2: Unsubscribe from a specific callback of steady standing state change events.

  ```ts
  import { Callback } from '@ohos.base';
  // Define the callback variable.
  let callback : Callback<deviceStatus.SteadyStandingStatus> = (data : deviceStatus.SteadyStandingStatus) => {
    console.info('now status = ' + data);
  };
  // Subscribe to a specific callback of steady standing state change events.
  try {
    deviceStatus.on('steadyStandingDetect', callback);
  } catch (err) {
    console.info('on failed, err = ' + err);
  }
  // Unsubscribe from the specific callback of steady standing state change events.
  try {
    deviceStatus.off('steadyStandingDetect', callback);
  } catch (err) {
    console.info('off failed, err = ' + err);
  }
  ```
