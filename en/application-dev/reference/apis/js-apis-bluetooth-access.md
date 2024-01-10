# @ohos.bluetooth.access (Bluetooth Access Module)

The **access** module provides APIs for enabling and disabling Bluetooth and obtaining the Bluetooth status.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import access from '@ohos.bluetooth.access';
```


## access.enableBluetooth<a name="enableBluetooth"></a>

enableBluetooth(): void

Enables Bluetooth.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message           |
| -------- | ------------------ |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    access.enableBluetooth();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## access.disableBluetooth<a name="disableBluetooth"></a>

disableBluetooth(): void

Disables Bluetooth.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

|ID  | Error Message          |
| -------- | ------------------ |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    access.disableBluetooth();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## access.getState<a name="getState"></a>

getState(): BluetoothState

Obtains the Bluetooth state.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                             | Description             |
| --------------------------------- | ---------------- |
| [BluetoothState](#bluetoothstate) | Bluetooth state obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

|ID  | Error Message          |
| -------- | ------------------ |
|2900001   | Service stopped.   |
|2900099   | Operation failed.  |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let state = access.getState();
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## access.on('stateChange')<a name="stateChange"></a>

on(type: "stateChange", callback: Callback&lt;BluetoothState&gt;): void

Subscribes to Bluetooth state changes.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name  | Type                                              | Mandatory | Description                                                      |
| -------- | ------------------------------------------------- | ----- | ---------------------------------------------------------- |
| type     | string                                            | Yes   | Event type. The value is **stateChange**, which indicates a Bluetooth state change event.              |
| callback | Callback&lt;[BluetoothState](#bluetoothstate)&gt; | Yes   | Callback invoked to return the Bluetooth state. You need to implement this callback.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

|ID  | Error Message          |
| -------- | ------------------ |
|2900099   | Operation failed.  |

**Example**

```js
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: access.BluetoothState) {
    console.info('bluetooth state = '+ JSON.stringify(data));
}
try {
    access.on('stateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## access.off('stateChange')<a name="stateChange"></a>

off(type: "stateChange", callback?: Callback&lt;BluetoothState&gt;): void

Unsubscribes from Bluetooth state changes.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value is **stateChange**, which indicates a Bluetooth state change event.          |
| callback | Callback&lt;[BluetoothState](#bluetoothstate)&gt; | No   | Callback for the Bluetooth state change event. If this parameter is not set, this API unsubscribes from all callbacks corresponding to **type**.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
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


## BluetoothState<a name="BluetoothState"></a>

Enumerates the Bluetooth states.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                   | Value | Description                |
| --------------------- | ---- | ------------------ |
| STATE_OFF             | 0    | Bluetooth is turned off.          |
| STATE_TURNING_ON      | 1    | Bluetooth is being turned on.         |
| STATE_ON              | 2    | Bluetooth is turned on.          |
| STATE_TURNING_OFF     | 3    | Bluetooth is being turned off.         |
| STATE_BLE_TURNING_ON  | 4    | The LE-only mode is being turned on for Bluetooth.|
| STATE_BLE_ON          | 5    | Bluetooth is in LE-only mode. |
| STATE_BLE_TURNING_OFF | 6    | The LE-only mode is being turned off for Bluetooth.|
