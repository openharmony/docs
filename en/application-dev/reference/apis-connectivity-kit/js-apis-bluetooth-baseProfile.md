# @ohos.bluetooth.baseProfile (Bluetooth baseProfile Module)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

The **baseProfile** module provides the basic common methods for different Bluetooth technology protocols.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { baseProfile } from '@kit.ConnectivityKit';
```
## BaseProfile

**BaseProfile** class, which provides public capabilities such as obtaining the connection status and listening for connection status changes. For example, [profiles](../../connectivity/terminology.md#profile) such as [A2dpSourceProfile](js-apis-bluetooth-a2dp.md#a2dpsourceprofile) and [HandsFreeAudioGatewayProfile](js-apis-bluetooth-hfp.md#handsfreeaudiogatewayprofile) are inherited from this class.

## ProfileConnectionState

type ProfileConnectionState = constant.ProfileConnectionState

Represents the profile connection status between the local and peer Bluetooth devices.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Type                 | Description                 |
| ------------------- | ------------------- |
| [constant.ProfileConnectionState](js-apis-bluetooth-constant.md#profileconnectionstate) | Profile connection status between the local and peer Bluetooth devices.|

## StateChangeParam

Defines the parameters for the profile connection status change between the local and peer Bluetooth devices.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name    | Type                          | Read-Only| Optional| Description                           |
| -------- | ----------------------------- | ---- | ---- | ------------------------------- |
| deviceId | string                        | No  | No  | Address of the peer device, for example, XX:XX:XX:XX:XX:XX.  |
| state    | [ProfileConnectionState](js-apis-bluetooth-constant.md#profileconnectionstate)        | No  | No  | Profile connection status.|
| cause<sup>12+</sup>| [DisconnectCause](#disconnectcause12) | No| No| Reason of profile disconnection.|

## DisconnectCause<sup>12+</sup>

Enumerates the reasons of profile disconnection.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Value | Description    |
| ------------------ | ---- | ------ |
| USER_DISCONNECT            | 0    | The user proactively disconnects the connection.|
| CONNECT_FROM_KEYBOARD      | 1    | The connection request needs to be initiated from the keyboard.|
| CONNECT_FROM_MOUSE         | 2    | The connection request needs to be initiated from the mouse.|
| CONNECT_FROM_CAR           | 3    | The connection request needs to be initiated from the head unit.|
| TOO_MANY_CONNECTED_DEVICES | 4    | The number of connections exceeds the limit.|
| CONNECT_FAIL_INTERNAL      | 5    | Internal error.|

## BaseProfile.getConnectedDevices

getConnectedDevices(): Array&lt;string&gt;

Obtains the list of peer devices that have connected to the profile of the local device.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                 | Description                 |
| ------------------- | ------------------- |
| Array&lt;string&gt; | List of peer devices that have connected to the profile of the local device.<br>For security purposes, the device addresses obtained are virtual MAC addresses.<br>- The virtual addresses of paired Bluetooth devices will not change.<br>- If Bluetooth is disabled and then enabled again, the virtual address will change immediately.<br>- If the pairing is canceled, the Bluetooth subsystem will determine when to change the address based on the actual usage of the address. If the address is being used by another app, the address will not change immediately.<br>- To persistently save the address, call [access.addPersistentDeviceId](js-apis-bluetooth-access.md#accessaddpersistentdeviceid16).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { a2dp } from '@kit.ConnectivityKit';

try {
    let a2dpSrc = a2dp.createA2dpSrcProfile(); // A2DP is used as an example.
    let retArray = a2dpSrc.getConnectedDevices();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```

## BaseProfile.getConnectionState

getConnectionState(deviceId: string): ProfileConnectionState

Obtains the profile connection status between the local and peer devices.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the peer device, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type                                             | Description                   |
| ------------------------------------------------- | ----------------------- |
| [ProfileConnectionState](js-apis-bluetooth-constant.md#profileconnectionstate) | Profile connection status.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { a2dp } from '@kit.ConnectivityKit';

try {
    let a2dpSrc = a2dp.createA2dpSrcProfile(); // A2DP is used as an example.
    let ret = a2dpSrc.getConnectionState('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## BaseProfile.on('connectionStateChange')

on(type: 'connectionStateChange', callback: Callback&lt;StateChangeParam&gt;): void

Enables listening for profile connection status change events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectionStateChange** indicates a profile connection status change event.<br>This event is triggered when the profile connection status changes.|
| callback | Callback&lt;[StateChangeParam](#statechangeparam)&gt; | Yes   | Callback used to return the profile connection status.                       |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { a2dp } from '@kit.ConnectivityKit';

function onReceiveEvent(data: baseProfile.StateChangeParam) {
    console.info('a2dp state = '+ JSON.stringify(data));
}
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile(); // A2DP is used as an example.
    a2dpSrc.on('connectionStateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## BaseProfile.off('connectionStateChange')

off(type: 'connectionStateChange', callback?: Callback&lt;[StateChangeParam](#statechangeparam)&gt;): void

Disables listening for profile connection status change events.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectionStateChange** indicates a profile connection status change event.|
| callback | Callback&lt;[StateChangeParam](#statechangeparam)&gt; | No   | Callback to unregister.<br>If this parameter is specified, it must be the same as the callback in [BaseProfile.on('connectionStateChange')](#baseprofileonconnectionstatechange). If this parameter is not specified, all callbacks corresponding to the event type are unregistered.                              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { a2dp } from '@kit.ConnectivityKit';

function onReceiveEvent(data: baseProfile.StateChangeParam) {
    console.info('a2dp state = '+ JSON.stringify(data));
}
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile(); // A2DP is used as an example.
    a2dpSrc.on('connectionStateChange', onReceiveEvent);
    a2dpSrc.off('connectionStateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```
