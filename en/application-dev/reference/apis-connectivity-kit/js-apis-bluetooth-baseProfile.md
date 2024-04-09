# @ohos.bluetooth.baseProfile (Bluetooth baseProfile Module)

The **baseProfile** module provides APIs for using basic Bluetooth profiles.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.



## Modules to Import

```js
import baseProfile from '@ohos.bluetooth.baseProfile';
```


## StateChangeParam

Represents the profile state change parameters.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name    | Type                          | Readable| Writable| Description                           |
| -------- | ----------------------------- | ---- | ---- | ------------------------------- |
| deviceId | string                        | Yes  | No  | Address of the Bluetooth device.  |
| state    | ProfileConnectionState        | Yes  | No  | Profile connection state of the device.|


## baseProfile.getConnectedDevices

getConnectedDevices(): Array&lt;string&gt;

Obtains the connected devices.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                 | Description                 |
| ------------------- | ------------------- |
| Array&lt;string&gt; | Addresses of the connected devices. For security purposes, the device addresses obtained are random MAC addresses.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
import a2dp from '@ohos.bluetooth.a2dp';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    let retArray = a2dpSrc.getConnectedDevices();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## baseProfile.getConnectionState

getConnectionState(deviceId: string): ProfileConnectionState

Obtains the profile connection state of a device.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the remote device.|

**Return value**

| Type                                             | Description                   |
| ------------------------------------------------- | ----------------------- |
| [ProfileConnectionState](js-apis-bluetooth-constant.md#profileconnectionstate) | Profile connection state obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
import a2dp from '@ohos.bluetooth.a2dp';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    let ret = a2dpSrc.getConnectionState('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## baseProfile.on('connectionStateChange')

on(type: 'connectionStateChange', callback: Callback&lt;StateChangeParam&gt;): void

Subscribes to profile connection state changes.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **connectionStateChange**, which indicates a profile connection state change event.|
| callback | Callback&lt;[StateChangeParam](#statechangeparam)&gt; | Yes   | Callback invoked to return the profile connection state change.                              |

**Example**

```js
import { BusinessError } from '@ohos.base';
import a2dp from '@ohos.bluetooth.a2dp';
function onReceiveEvent(data: baseProfile.StateChangeParam) {
    console.info('a2dp state = '+ JSON.stringify(data));
}
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.on('connectionStateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## baseProfile.off('connectionStateChange')

off(type: 'connectionStateChange', callback?: Callback&lt;[StateChangeParam](#statechangeparam)&gt;): void

Unsubscribes from profile connection state changes.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **connectionStateChange**, which indicates a profile connection state change event.|
| callback | Callback&lt;[StateChangeParam](#statechangeparam)&gt; | No   | Callback to unregister.                |

**Example**

```js
import { BusinessError } from '@ohos.base';
import a2dp from '@ohos.bluetooth.a2dp';
function onReceiveEvent(data: baseProfile.StateChangeParam) {
    console.info('a2dp state = '+ JSON.stringify(data));
}
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.on('connectionStateChange', onReceiveEvent);
    a2dpSrc.off('connectionStateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```
