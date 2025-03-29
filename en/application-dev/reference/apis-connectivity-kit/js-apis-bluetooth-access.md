# @ohos.bluetooth.access (Bluetooth Access Module)

The **access** module provides APIs for enabling and disabling Bluetooth and obtaining the Bluetooth status.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import { access } from '@kit.ConnectivityKit';
```


## access.enableBluetooth

enableBluetooth(): void

Enables Bluetooth.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message           |
| -------- | ------------------ |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    access.enableBluetooth();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## access.disableBluetooth

disableBluetooth(): void

Disables Bluetooth.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

|ID  | Error Message          |
| -------- | ------------------ |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    access.disableBluetooth();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## access.getState

getState(): BluetoothState

Obtains the Bluetooth state.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                             | Description             |
| --------------------------------- | ---------------- |
| [BluetoothState](#bluetoothstate) | Bluetooth state obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

|ID  | Error Message          |
| -------- | ------------------ |
|801 | Capability not supported.          |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
try {
    let state = access.getState();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## access.on('stateChange')<a name="stateChange"></a>

on(type: 'stateChange', callback: Callback&lt;BluetoothState&gt;): void

Subscribes to Bluetooth state changes. This API uses an asynchronous callback to return the result. Since API version 16, the **ohos.permission.ACCESS_BLUETOOTH** permission is no longer verified.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name  | Type                                              | Mandatory | Description                                                      |
| -------- | ------------------------------------------------- | ----- | ---------------------------------------------------------- |
| type     | string                                            | Yes   | Event type. The value is **stateChange**, which indicates Bluetooth state changes.              |
| callback | Callback&lt;[BluetoothState](#bluetoothstate)&gt; | Yes   | Callback used to return the Bluetooth state. You need to implement this callback.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

|ID  | Error Message          |
| -------- | ------------------ |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099   | Operation failed.  |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: access.BluetoothState) {
    console.info('bluetooth state = '+ JSON.stringify(data));
}
try {
    access.on('stateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## access.off('stateChange')

off(type: 'stateChange', callback?: Callback&lt;BluetoothState&gt;): void

Unsubscribes from Bluetooth state changes.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **stateChange**, which indicates Bluetooth state changes.          |
| callback | Callback&lt;[BluetoothState](#bluetoothstate)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregisters all callbacks for Bluetooth state changes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
function onReceiveEvent(data: access.BluetoothState) {
    console.info('bluetooth state = '+ JSON.stringify(data));
}
try {
    access.on('stateChange', onReceiveEvent);
    access.off('stateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## access.addPersistentDeviceId<sup>16+</sup>

addPersistentDeviceId(deviceId: string): Promise&lt;void&gt;

The device address obtained by the application through Bluetooth scanning is a random virtual address. If the application needs to use this random virtual address for an extended period, it needs to call this API to persistently store the address.

When using this API, ensure that the real address of the peer device corresponding to the virtual random address remains unchanged. If the real address of the peer device changes, the persistently stored virtual address will become invalid and unusable.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.PERSISTENT_BLUETOOTH_PEERS_MAC

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| deviceId     | string                                   | Yes   | Virtual address of the peer device, for example, XX:XX:XX:XX:XX:XX. The address is generally obtained from Bluetooth scanning. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900003 | Bluetooth disabled. |
|2900010 | The number of supported device addresses has reached the upper limit. |
|2900099 | Add persistent device address failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { access } from '@kit.ConnectivityKit';

let deviceId = '11:22:33:44:55:66' // The address can be obtained through BLE scanning.
try {
    access.addPersistentDeviceId(deviceId);
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## access.deletePersistentDeviceId<sup>16+</sup>

deletePersistentDeviceId(deviceId: string): Promise&lt;void&gt;

Deletes a persistently stored virtual address.


**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.PERSISTENT_BLUETOOTH_PEERS_MAC

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| deviceId     | string                                   | Yes   | Virtual address of the peer device, for example, XX:XX:XX:XX:XX:XX. The address is generally obtained from Bluetooth scanning.          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900003 | Bluetooth disabled. |
|2900099 | delete persistent device address failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { access } from '@kit.ConnectivityKit';

let deviceId = '11:22:33:44:55:66' // The address can be obtained through BLE scanning.
try {
    access.deletePersistentDeviceId(deviceId);
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## access.getPersistentDeviceIds<sup>16+</sup>

getPersistentDeviceIds(): string[];

Obtains persistently stored virtual addresses.


**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.PERSISTENT_BLUETOOTH_PEERS_MAC

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                             | Description             |
| --------------------------------- | ---------------- |
| string[] | List of persistently stored virtual addresses.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900003 | Bluetooth disabled. |
|2900099 | Get persistent device address failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { access } from '@kit.ConnectivityKit';

try {
    let deviceIds = access.getPersistentDeviceIds();
    console.info("deviceIds: " + deviceIds);
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## access.isValidRandomDeviceId<sup>16+</sup>

isValidRandomDeviceId(deviceId: string): boolean;

Checks whether the virtual address of the peer device is valid.


**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| deviceId     | string                                   | Yes   | Virtual address of the peer device, for example, XX:XX:XX:XX:XX:XX. The address is generally obtained from Bluetooth scanning.          |

**Return value**

| Type                             | Description             |
| --------------------------------- | ---------------- |
| boolean | Whether the virtual address is valid.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900003 | Bluetooth disabled. |
|2900099 | Check persistent device address failed.                        |

**Example**

```js
import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
import { access } from '@kit.ConnectivityKit';

try {
    let deviceId = '11:22:33:44:55:66' // The address can be obtained through BLE scanning.
    let isValid = access.isValidRandomDeviceId(deviceId);
    console.info("isValid: " + isValid);
} catch (err) {
    console.error('errCode: ' + err.code + ', errMessage: ' + err.message);
}
```

## BluetoothState

Enumerates the Bluetooth states.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                   | Value | Description                |
| --------------------- | ---- | ------------------ |
| STATE_OFF             | 0    | Bluetooth is turned off.         |
| STATE_TURNING_ON      | 1    | Bluetooth is being turned on.         |
| STATE_ON              | 2    | Bluetooth is turned on.          |
| STATE_TURNING_OFF     | 3    | Bluetooth is being turned off.         |
| STATE_BLE_TURNING_ON  | 4    | The LE-only mode is being turned on for Bluetooth.|
| STATE_BLE_ON          | 5    | Bluetooth is in LE-only mode. |
| STATE_BLE_TURNING_OFF | 6    | The LE-only mode is being turned off for Bluetooth.|
