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

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

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

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

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

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

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

on(type: "stateChange", callback: Callback&lt;BluetoothState&gt;): void

Subscribes to Bluetooth state changes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name  | Type                                              | Mandatory | Description                                                      |
| -------- | ------------------------------------------------- | ----- | ---------------------------------------------------------- |
| type     | string                                            | Yes   | Event type. The value is **stateChange**, which indicates Bluetooth state changes.              |
| callback | Callback&lt;[BluetoothState](#bluetoothstate)&gt; | Yes   | Callback used to return the Bluetooth state. You need to implement this callback.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

|ID  | Error Message          |
| -------- | ------------------ |
|201 | Permission denied.                 |
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

off(type: "stateChange", callback?: Callback&lt;BluetoothState&gt;): void

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

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

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
