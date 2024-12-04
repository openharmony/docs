# @ohos.bluetoothManager (Bluetooth)

The **Bluetooth** module provides classic Bluetooth capabilities and Bluetooth Low Energy (BLE) scan and advertising.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are no longer maintained since API version 10. You are advised to use profile APIs of [@ohos.bluetooth.ble](js-apis-bluetooth-ble.md).



## Modules to Import

```js
import bluetoothManager from '@ohos.bluetoothManager';
```


## bluetoothManager.enableBluetooth<sup>(deprecated)</sup>

enableBluetooth(): void

Enables Bluetooth.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [access.enableBluetooth](js-apis-bluetooth-access.md#accessenablebluetooth) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH


**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    bluetoothManager.enableBluetooth();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.disableBluetooth<sup>(deprecated)</sup>

disableBluetooth(): void

Disables Bluetooth.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [access.disableBluetooth](js-apis-bluetooth-access.md#accessdisablebluetooth) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    bluetoothManager.disableBluetooth();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ", errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.getLocalName<sup>(deprecated)</sup>

getLocalName(): string

Obtains the name of the local Bluetooth device.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.getLocalName](js-apis-bluetooth-connection.md#connectiongetlocalname) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type    | Description       |
| ------ | --------- |
| string | Name of the local Bluetooth device obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let localName: string = bluetoothManager.getLocalName();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.getState<sup>(deprecated)</sup>

getState(): BluetoothState

Obtains the Bluetooth state.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [access.getState](js-apis-bluetooth-access.md#accessgetstate) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                               | Description       |
| --------------------------------- | --------- |
| [BluetoothState](#bluetoothstatedeprecated) | Bluetooth state obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let state: bluetoothManager.BluetoothState = bluetoothManager.getState();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.getBtConnectionState<sup>(deprecated)</sup>

getBtConnectionState(): ProfileConnectionState

Obtains the local profile connection status.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.getProfileConnectionState](js-apis-bluetooth-connection.md#connectiongetprofileconnectionstate) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                                      | Description                 |
| ---------------------------------------- | ------------------- |
| [ProfileConnectionState](#profileconnectionstatedeprecated) | Profile connection state obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let connectionState: bluetoothManager.ProfileConnectionState = bluetoothManager.getBtConnectionState();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.setLocalName<sup>(deprecated)</sup>

setLocalName(name: string): void

Sets the name of the local Bluetooth device.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.setLocalName](js-apis-bluetooth-connection.md#connectionsetlocalname) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name | Type    | Mandatory  | Description                   |
| ---- | ------ | ---- | --------------------- |
| name | string | Yes   | Bluetooth device name to set. It cannot exceed 248 bytes.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.              |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    bluetoothManager.setLocalName('device_name');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.pairDevice<sup>(deprecated)</sup>

pairDevice(deviceId: string): void

Initiates Bluetooth pairing.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.pairDevice](js-apis-bluetooth-connection.md#connectionpairdevice) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the remote device to pair, for example, XX:XX:XX:XX:XX:XX.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    // The address can be scanned.
    bluetoothManager.pairDevice("XX:XX:XX:XX:XX:XX");
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.getProfileConnectionState<sup>(deprecated)</sup>

getProfileConnectionState(profileId: ProfileId): ProfileConnectionState

Obtains the connection status of the specified profile.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.getProfileConnectionState](js-apis-bluetooth-connection.md#connectiongetprofileconnectionstate) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name      | Type       | Mandatory  | Description                                   |
| --------- | --------- | ---- | ------------------------------------- |
| profileId | ProfileId | Yes   | ID of the profile to obtain, for example, **PROFILE_A2DP_SOURCE**.|

**Return value**

| Type                                             | Description               |
| ------------------------------------------------- | ------------------- |
| [ProfileConnectionState](#profileconnectionstatedeprecated) | Profile connection state obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.           |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let result: bluetoothManager.ProfileConnectionState = bluetoothManager.getProfileConnectionState(bluetoothManager.ProfileId.PROFILE_A2DP_SOURCE);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```



## bluetoothManager.getRemoteDeviceName<sup>(deprecated)</sup>

getRemoteDeviceName(deviceId: string): string

Obtains the name of the remote Bluetooth device.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.getRemoteDeviceName](js-apis-bluetooth-connection.md#connectiongetremotedevicename) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                               |
| -------- | ------ | ---- | --------------------------------- |
| deviceId | string | Yes   | Address of the target remote device, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Device name (a string) obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let remoteDeviceName: string = bluetoothManager.getRemoteDeviceName("XX:XX:XX:XX:XX:XX");
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.getRemoteDeviceClass<sup>(deprecated)</sup>

getRemoteDeviceClass(deviceId: string): DeviceClass

Obtains the class of the remote Bluetooth device.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.getRemoteDeviceClass](js-apis-bluetooth-connection.md#connectiongetremotedeviceclass) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                               |
| -------- | ------ | ---- | --------------------------------- |
| deviceId | string | Yes   | Address of the target remote device, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type                         | Description      |
| --------------------------- | -------- |
| [DeviceClass](#deviceclassdeprecated) | Class of the remote device obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let remoteDeviceClass: bluetoothManager.DeviceClass  = bluetoothManager.getRemoteDeviceClass("XX:XX:XX:XX:XX:XX");
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.getPairedDevices<sup>(deprecated)</sup>

getPairedDevices(): Array&lt;string&gt;

Obtains the paired devices.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.getPairedDevices](js-apis-bluetooth-connection.md#connectiongetpaireddevices) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
| Array&lt;string&gt; | Addresses of the paired Bluetooth devices.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let devices: Array<string> = bluetoothManager.getPairedDevices();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.setBluetoothScanMode<sup>(deprecated)</sup>

setBluetoothScanMode(mode: ScanMode, duration: number): void

Sets the Bluetooth scan mode so that the device can be discovered by a remote device.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.setBluetoothScanMode](js-apis-bluetooth-connection.md#connectionsetbluetoothscanmode) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                   | Mandatory  | Description                          |
| -------- | --------------------- | ---- | ---------------------------- |
| mode     | [ScanMode](#scanmodedeprecated) | Yes   | Bluetooth scan mode to set.                     |
| duration | number                | Yes   | Duration (in ms) in which the device can be discovered. The value **0** indicates unlimited time.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.             |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    // The device can be discovered and connected only when the discoverable and connectable mode is used.
    bluetoothManager.setBluetoothScanMode(bluetoothManager.ScanMode.SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE, 100);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.getBluetoothScanMode<sup>(deprecated)</sup>

getBluetoothScanMode(): ScanMode

Obtains the Bluetooth scan mode.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.getBluetoothScanMode](js-apis-bluetooth-connection.md#connectiongetbluetoothscanmode) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                   | Description     |
| --------------------- | ------- |
| [ScanMode](#scanmodedeprecated) | Bluetooth scan mode to set.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let scanMode: bluetoothManager.ScanMode = bluetoothManager.getBluetoothScanMode();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.startBluetoothDiscovery<sup>(deprecated)</sup>

startBluetoothDiscovery(): void

Starts Bluetooth scan to discover remote devices.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.startBluetoothDiscovery](js-apis-bluetooth-connection.md#connectionstartbluetoothdiscovery) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
let deviceId: Array<string>;
function onReceiveEvent(data: Array<string>) {
    deviceId = data;
}
try {
    bluetoothManager.on('bluetoothDeviceFind', onReceiveEvent);
    bluetoothManager.startBluetoothDiscovery();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.stopBluetoothDiscovery<sup>(deprecated)</sup>

stopBluetoothDiscovery(): void

Stops Bluetooth scan.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.stopBluetoothDiscovery](js-apis-bluetooth-connection.md#connectionstopbluetoothdiscovery) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    bluetoothManager.stopBluetoothDiscovery();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.setDevicePairingConfirmation<sup>(deprecated)</sup>

setDevicePairingConfirmation(device: string, accept: boolean): void

Sets the device pairing confirmation.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.setDevicePairingConfirmation](js-apis-bluetooth-connection.md#connectionsetdevicepairingconfirmation) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH (available only for system applications)

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type     | Mandatory  | Description                              |
| ------ | ------- | ---- | -------------------------------- |
| device | string  | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|
| accept | boolean | Yes   | Whether to accept the pairing request. The value **true** means to accept the pairing request, and the value **false** means the opposite.       |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
// Subscribe to the pinRequired event and configure the pairing confirmation after receiving a pairing request from the remote device.
function onReceivePinRequiredEvent(data: bluetoothManager.PinRequiredParam) { // data is the input parameter for the pairing request.
    console.info('pin required  = '+ JSON.stringify(data));
    bluetoothManager.setDevicePairingConfirmation(data.deviceId, true);
}
try {
    bluetoothManager.on("pinRequired", onReceivePinRequiredEvent);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.on('bluetoothDeviceFind')<sup>(deprecated)</sup>

on(type: 'bluetoothDeviceFind', callback: Callback&lt;Array&lt;string&gt;&gt;): void

Subscribes to the Bluetooth device discovery events.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.on('bluetoothDeviceFind')](js-apis-bluetooth-connection.md#connectiononbluetoothdevicefind) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                 | Mandatory  | Description                                    |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| type     | string                              | Yes   | Event type. The value **bluetoothDeviceFind** indicates an event reported when a Bluetooth device is discovered.|
| callback | Callback&lt;Array&lt;string&gt;&gt; | Yes   | Callback used to return the discovered devices. You need to implement this callback.   |

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
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: Array<string>) { // data is an array of Bluetooth device addresses.
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
try {
    bluetoothManager.on('bluetoothDeviceFind', onReceiveEvent);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.off('bluetoothDeviceFind')<sup>(deprecated)</sup>

off(type: 'bluetoothDeviceFind', callback?: Callback&lt;Array&lt;string&gt;&gt;): void

Unsubscribes from the Bluetooth device discovery events.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.off('bluetoothDeviceFind')](js-apis-bluetooth-connection.md#connectionoffbluetoothdevicefind) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                 | Mandatory  | Description                                      |
| -------- | ----------------------------------- | ---- | ---------------------------------------- |
| type     | string                              | Yes   | Event type. The value **bluetoothDeviceFind** indicates an event reported when a Bluetooth device is discovered.  |
| callback | Callback&lt;Array&lt;string&gt;&gt; | No   | Callback to unregister. If this parameter is not set, this API unregistersall callbacks for the specified **type**.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: Array<string>) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
try {
    bluetoothManager.on('bluetoothDeviceFind', onReceiveEvent);
    bluetoothManager.off('bluetoothDeviceFind', onReceiveEvent);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.on('pinRequired')<sup>(deprecated)</sup>

on(type: 'pinRequired', callback: Callback&lt;PinRequiredParam&gt;): void

Subscribes to the pairing request events of the remote Bluetooth device.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.on('pinRequired')](js-apis-bluetooth-connection.md#connectiononpinrequired) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                              |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| type     | string                                   | Yes   | Event type. The value **pinRequired** indicates a pairing request event.    |
| callback | Callback&lt;[PinRequiredParam](#pinrequiredparamdeprecated)&gt; | Yes   | Callback used to return the pairing request. You need to implement this callback.|

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
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: bluetoothManager.PinRequiredParam) { // data is the pairing request parameter.
    console.info('pin required = '+ JSON.stringify(data));
}
try {
    bluetoothManager.on('pinRequired', onReceiveEvent);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.off('pinRequired')<sup>(deprecated)</sup>

off(type: 'pinRequired', callback?: Callback&lt;PinRequiredParam&gt;): void

Unsubscribes from the pairing request events of the remote Bluetooth device.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.off('pinRequired')](js-apis-bluetooth-connection.md#connectionoffpinrequired) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **pinRequired** indicates a pairing request event.            |
| callback | Callback&lt;[PinRequiredParam](#pinrequiredparamdeprecated)&gt; | No   | Callback to unregister. The input parameter is the pairing request parameter. If this parameter is not set, this API unregistersall callbacks for the specified **type**.|

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
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: bluetoothManager.PinRequiredParam) {
    console.info('pin required = '+ JSON.stringify(data));
}
try {
    bluetoothManager.on('pinRequired', onReceiveEvent);
    bluetoothManager.off('pinRequired', onReceiveEvent);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.on('bondStateChange')<sup>(deprecated)</sup>

on(type: 'bondStateChange', callback: Callback&lt;BondStateParam&gt;): void

Subscribes to the Bluetooth pairing state changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.on('bondStateChange')](js-apis-bluetooth-connection.md#connectiononbondstatechange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                  |
| -------- | ---------------------------------------- | ---- | ------------------------------------ |
| type     | string                                   | Yes   | Event type. The value **bondStateChange** indicates a Bluetooth pairing state change event.|
| callback | Callback&lt;[BondStateParam](#bondstateparamdeprecated)&gt; | Yes   | Callback used to return the pairing state. You need to implement this callback.   |

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
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: bluetoothManager.BondStateParam) { // data, as the input parameter of the callback, indicates the pairing state.
    console.info('pair state = '+ JSON.stringify(data));
}
try {
    bluetoothManager.on('bondStateChange', onReceiveEvent);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.off('bondStateChange')<sup>(deprecated)</sup>

off(type: 'bondStateChange', callback?: Callback&lt;BondStateParam&gt;): void

Unsubscribes from the Bluetooth pairing state changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.off('bondStateChange')](js-apis-bluetooth-connection.md#connectionoffbondstatechange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **bondStateChange** indicates a Bluetooth pairing state change event.    |
| callback | Callback&lt;[BondStateParam](#bondstateparamdeprecated)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregistersall callbacks for the specified **type**.|

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
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: bluetoothManager.BondStateParam) {
    console.info('bond state = '+ JSON.stringify(data));
}
try {
    bluetoothManager.on('bondStateChange', onReceiveEvent);
    bluetoothManager.off('bondStateChange', onReceiveEvent);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.on('stateChange')<sup>(deprecated)</sup>

on(type: 'stateChange', callback: Callback&lt;BluetoothState&gt;): void

Subscribes to Bluetooth state events.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [access.on('stateChange')](js-apis-bluetooth-access.md#accessonstatechange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                              |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| type     | string                                   | Yes   | Event type. The value **stateChange** indicates a Bluetooth connection state change event.  |
| callback | Callback&lt;[BluetoothState](#bluetoothstatedeprecated)&gt; | Yes   | Callback used to return the Bluetooth connection state. You need to implement this callback.|

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
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: bluetoothManager.BluetoothState) {
    console.info('bluetooth state = '+ JSON.stringify(data));
}
try {
    bluetoothManager.on('stateChange', onReceiveEvent);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.off('stateChange')<sup>(deprecated)</sup>

off(type: 'stateChange', callback?: Callback&lt;BluetoothState&gt;): void

Unsubscribes from Bluetooth state events.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [access.off('stateChange')](js-apis-bluetooth-access.md#accessoffstatechange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **stateChange** indicates a Bluetooth connection state change event.          |
| callback | Callback&lt;[BluetoothState](#bluetoothstatedeprecated)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregistersall callbacks for the specified **type**.|

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
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: bluetoothManager.BluetoothState) {
    console.info('bluetooth state = '+ JSON.stringify(data));
}
try {
    bluetoothManager.on('stateChange', onReceiveEvent);
    bluetoothManager.off('stateChange', onReceiveEvent);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.sppListen<sup>(deprecated)</sup>

sppListen(name: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void

Creates a server listening socket.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [socket.sppListen](js-apis-bluetooth-socket.md#socketspplisten) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                     |
| -------- | --------------------------- | ---- | ----------------------- |
| name     | string                      | Yes   | Name of the service.                 |
| option   | [SppOption](#sppoptiondeprecated)     | Yes   | Serial port profile (SPP) listening configuration.             |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the server socket ID.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.              |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
let serverNumber = -1;
function serverSocket(code: BusinessError, number: number) {
  console.log('bluetooth error code: ' + code.code);
  if (code.code == 0) {
    console.log('bluetooth serverSocket Number: ' + number);
    serverNumber = number;
  }
}

let sppOption: bluetoothManager.SppOption = {uuid: '00001810-0000-1000-8000-00805F9B34FB', secure: false, type: 0};
try {
    bluetoothManager.sppListen('server1', sppOption, serverSocket);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.sppAccept<sup>(deprecated)</sup>

sppAccept(serverSocket: number, callback: AsyncCallback&lt;number&gt;): void

Listens for a connection to be made to this socket from the client and accepts it.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [socket.sppAccept](js-apis-bluetooth-socket.md#socketsppaccept) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                     |
| ------------ | --------------------------- | ---- | ----------------------- |
| serverSocket | number                      | Yes   | Server socket ID.          |
| callback     | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the client socket ID.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.             |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
let serverNumber = -1;
function serverSocket(code: BusinessError, number: number) {
  console.log('bluetooth error code: ' + code.code);
  if (code.code == 0) {
    console.log('bluetooth serverSocket Number: ' + number);
    serverNumber = number;
  }
}
let clientNumber = -1;
function acceptClientSocket(code: BusinessError, number: number) {
  console.log('bluetooth error code: ' + code.code);
  if (code.code == 0) {
    console.log('bluetooth clientSocket Number: ' + number);
    // The obtained clientNumber is used as the socket ID for subsequent read/write operations on the server.
    clientNumber = number;
  }
}
try {
    bluetoothManager.sppAccept(serverNumber, acceptClientSocket);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.sppConnect<sup>(deprecated)</sup>

sppConnect(device: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void

Initiates an SPP connection to a remote device from the client.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [socket.sppConnect](js-apis-bluetooth-socket.md#socketsppconnect) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                            |
| -------- | --------------------------- | ---- | ------------------------------ |
| device   | string                      | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|
| option   | [SppOption](#sppoptiondeprecated)     | Yes   | Configuration for connecting to the SPP client.                 |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the client socket ID.       |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.               |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';

let clientNumber = -1;
function clientSocket(code: BusinessError, number: number) {
  if (code.code != 0 || code == null) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // The obtained clientNumber is used as the socket ID for subsequent read/write operations on the client.
  clientNumber = number;
}
let sppOption: bluetoothManager.SppOption = {uuid: '00001810-0000-1000-8000-00805F9B34FB', secure: false, type: 0};
try {
    bluetoothManager.sppConnect('XX:XX:XX:XX:XX:XX', sppOption, clientSocket);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.sppCloseServerSocket<sup>(deprecated)</sup>

sppCloseServerSocket(socket: number): void

Closes the listening socket of the server.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [socket.sppCloseServerSocket](js-apis-bluetooth-socket.md#socketsppcloseserversocket) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description             |
| ------ | ------ | ---- | --------------- |
| socket | number | Yes   | ID of the listening socket on the server. The ID is obtained by **sppListen**.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.               |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
let serverNumber = -1;
function serverSocket(code: BusinessError, number: number) {
  console.log('bluetooth error code: ' + code.code);
  if (code.code == 0) {
    console.log('bluetooth serverSocket Number: ' + number);
    serverNumber = number;
  }
}
try {
    bluetoothManager.sppCloseServerSocket(serverNumber);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.sppCloseClientSocket<sup>(deprecated)</sup>

sppCloseClientSocket(socket: number): void

Closes the client socket.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [socket.sppCloseClientSocket](js-apis-bluetooth-socket.md#socketsppcloseclientsocket) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description           |
| ------ | ------ | ---- | ------------- |
| socket | number | Yes   | Client socket ID, which is obtained by **sppAccept** or **sppConnect**.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
let clientNumber = -1;
function clientSocket(code: BusinessError, number: number) {
  if (code.code != 0 || code == null) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // The obtained clientNumber is used as the socket ID for subsequent read/write operations on the client.
  clientNumber = number;
}
try {
    bluetoothManager.sppCloseClientSocket(clientNumber);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.sppWrite<sup>(deprecated)</sup>

sppWrite(clientSocket: number, data: ArrayBuffer): void

Writes data to the remote device through the socket.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [socket.sppWrite](js-apis-bluetooth-socket.md#socketsppwrite) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type         | Mandatory  | Description           |
| ------------ | ----------- | ---- | ------------- |
| clientSocket | number      | Yes   | Client socket ID, which is obtained by **sppAccept** or **sppConnect**.|
| data         | ArrayBuffer | Yes   | Data to write.       |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.               |
|801 | Capability not supported.          |
|2901054 | IO error.                                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
let clientNumber = -1;
function clientSocket(code: BusinessError, number: number) {
  if (code.code != 0 || code == null) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // The obtained clientNumber is used as the socket ID for subsequent read/write operations on the client.
  clientNumber = number;
}
let arrayBuffer = new ArrayBuffer(8);
let data = new Uint8Array(arrayBuffer);
data[0] = 123;
try {
    bluetoothManager.sppWrite(clientNumber, arrayBuffer);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.on('sppRead')<sup>(deprecated)</sup>

on(type: 'sppRead', clientSocket: number, callback: Callback&lt;ArrayBuffer&gt;): void

Subscribes to the SPP read request events.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [socket.on('sppRead')](js-apis-bluetooth-socket.md#socketonsppread) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                        |
| ------------ | --------------------------- | ---- | -------------------------- |
| type         | string                      | Yes   | Event type. The value **sppRead** indicates an SPP read request event.|
| clientSocket | number                      | Yes   | Client socket ID, which is obtained by **sppAccept** or **sppConnect**.             |
| callback     | Callback&lt;ArrayBuffer&gt; | Yes   | Callback used to return the data read.         |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                |
|801 | Capability not supported.          |
|2901054 | IO error.                                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
let clientNumber = -1;
function clientSocket(code: BusinessError, number: number) {
  if (code.code != 0 || code == null) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // The obtained clientNumber is used as the socket ID for subsequent read/write operations on the client.
  clientNumber = number;
}
function dataRead(dataBuffer: ArrayBuffer) {
  let data = new Uint8Array(dataBuffer);
  console.log('bluetooth data is: ' + data[0]);
}
try {
    bluetoothManager.on('sppRead', clientNumber, dataRead);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## bluetoothManager.off('sppRead')<sup>(deprecated)</sup>

off(type: 'sppRead', clientSocket: number, callback?: Callback&lt;ArrayBuffer&gt;): void

Unsubscribes from the SPP read request events.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [socket.off('sppRead')](js-apis-bluetooth-socket.md#socketoffsppread) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                                      |
| ------------ | --------------------------- | ---- | ---------------------------------------- |
| type         | string                      | Yes   | Event type. The value **sppRead** indicates an SPP read request event.              |
| clientSocket | number                      | Yes   | Client socket ID, which is obtained by **sppAccept** or **sppConnect**.                           |
| callback     | Callback&lt;ArrayBuffer&gt; | No   | Callback to unregister. If this parameter is not set, this API unregistersall callbacks for the specified **type**.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.              |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
let clientNumber = -1;
function clientSocket(code: BusinessError, number: number) {
  if (code.code != 0 || code == null) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // The obtained clientNumber is used as the socket ID for subsequent read/write operations on the client.
  clientNumber = number;
}
try {
    bluetoothManager.off('sppRead', clientNumber);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```

## bluetoothManager.getProfileInstance<sup>(deprecated)</sup>

getProfileInstance(profileId: ProfileId): A2dpSourceProfile | HandsFreeAudioGatewayProfile | HidHostProfile | PanProfile

Obtains a profile instance. API version 9 is added with **HidHostProfile** and **PanProfile**.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name      | Type       | Mandatory  | Description                                   |
| --------- | --------- | ---- | ------------------------------------- |
| profileId | [ProfileId](#profileiddeprecated) | Yes   | ID of the profile to obtain, for example, **PROFILE_A2DP_SOURCE**.|

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [A2dpSourceProfile](#a2dpsourceprofile), [HandsFreeAudioGatewayProfile](#handsfreeaudiogatewayprofiledeprecated), [HidHostProfile](#hidhostprofiledeprecated), or [PanProfile](#panprofile)| Profile instance obtained, which can be **A2dpSourceProfile**, **HandsFreeAudioGatewayProfile**, **HidHostProfile**, or **PanProfile**.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.           |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let hidHost: bluetoothManager.HidHostProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_HID_HOST);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## BLE

Provides APIs for operating and managing Bluetooth.

### createGattServer<sup>(deprecated)</sup>

createGattServer(): GattServer

Creates a **GattServer** instance.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.createGattServer](js-apis-bluetooth-ble.md#blecreategattserver) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                       | Description                                  |
| ------------------------- | ------------------------------------ |
| [GattServer](#gattserver) | **GattServer** instance created. Before using an API of this class, you must create a **GattSever** instance.|

**Example**

```js
let gattServer: bluetoothManager.GattServer  = bluetoothManager.BLE.createGattServer();
```


### createGattClientDevice<sup>(deprecated)</sup>

createGattClientDevice(deviceId: string): GattClientDevice

Creates a **GattClientDevice** instance.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.createGattClientDevice](js-apis-bluetooth-ble.md#blecreategattclientdevice) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                  |
| -------- | ------ | ---- | ------------------------------------ |
| deviceId | string | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type                                   | Description                                  |
| ------------------------------------- | ------------------------------------ |
| [GattClientDevice](#gattclientdevice) | **GattClientDevice** instance created. Before using an API of the client, you must create a **GattClientDevice** instance.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let device: bluetoothManager.GattClientDevice = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### getConnectedBLEDevices<sup>(deprecated)</sup>

getConnectedBLEDevices(): Array&lt;string&gt;

Obtains the BLE devices connected to this device.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.getConnectedBLEDevices](js-apis-bluetooth-ble.md#blegetconnectedbledevices) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                 | Description                 |
| ------------------- | ------------------- |
| Array&lt;string&gt; | Addresses of the BLE devices connected to this device.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let result: Array<string>  = bluetoothManager.BLE.getConnectedBLEDevices();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### startBLEScan<sup>(deprecated)</sup>

startBLEScan(filters: Array&lt;ScanFilter&gt;, options?: ScanOptions): void

Starts a BLE scan.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.startBLEScan](js-apis-bluetooth-ble.md#blestartblescan) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name    | Type                                    | Mandatory  | Description                                 |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| filters | Array&lt;[ScanFilter](#scanfilterdeprecated)&gt; | Yes   | Criteria for filtering the scan result. Set this parameter to **null** if you do not want to filter the scan result.|
| options | [ScanOptions](#scanoptionsdeprecated)            | No   | Scan options.                    |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: Array<bluetoothManager.ScanResult>) {
    console.info('BLE scan device find result = '+ JSON.stringify(data));
}
try {
    bluetoothManager.BLE.on("BLEDeviceFind", onReceiveEvent);
    let scanfilter: bluetoothManager.ScanFilter = {
        deviceId:"XX:XX:XX:XX:XX:XX",
        name:"test",
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb"
    };
    let scanoptions: bluetoothManager.ScanOptions = {
        interval: 500,
        dutyMode: bluetoothManager.ScanDuty.SCAN_MODE_LOW_POWER,
        matchMode: bluetoothManager.MatchMode.MATCH_MODE_AGGRESSIVE,
    }
    bluetoothManager.BLE.startBLEScan([scanfilter], scanoptions);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### stopBLEScan<sup>(deprecated)</sup>

stopBLEScan(): void

Stops the BLE scan.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.startBLEScan](js-apis-bluetooth-ble.md#blestopblescan) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    bluetoothManager.BLE.stopBLEScan();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('BLEDeviceFind')<sup>(deprecated)</sup>

on(type: 'BLEDeviceFind', callback: Callback&lt;Array&lt;ScanResult&gt;&gt;): void

Subscribe to the BLE device discovery events.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.on('BLEDeviceFind')](js-apis-bluetooth-ble.md#bleonbledevicefind) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                 |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEDeviceFind** indicates an event reported when a BLE device is discovered.  |
| callback | Callback&lt;Array&lt;[ScanResult](#scanresultdeprecated)&gt;&gt; | Yes   | Callback used to return the discovered devices. You need to implement this callback.|

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
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: Array<bluetoothManager.ScanResult>) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
try {
    bluetoothManager.BLE.on('BLEDeviceFind', onReceiveEvent);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### off('BLEDeviceFind')<sup>(deprecated)</sup>

off(type: 'BLEDeviceFind', callback?: Callback&lt;Array&lt;ScanResult&gt;&gt;): void

Unsubscribes from the BLE device discovery events.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.off('BLEDeviceFind')](js-apis-bluetooth-ble.md#bleoffbledevicefind) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEDeviceFind** indicates an event reported when a BLE device is discovered.       |
| callback | Callback&lt;Array&lt;[ScanResult](#scanresultdeprecated)&gt;&gt; | No   | Callback to unregister. If this parameter is not set, this API unregistersall callbacks for the specified **type**.|

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
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: Array<bluetoothManager.ScanResult>) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
try {
    bluetoothManager.BLE.on('BLEDeviceFind', onReceiveEvent);
    bluetoothManager.BLE.off('BLEDeviceFind', onReceiveEvent);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## BaseProfile

Provides the profile base class.


### getConnectionDevices<sup>(deprecated)</sup>

getConnectionDevices(): Array&lt;string&gt;

Obtains the connected devices.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [baseProfile.getConnectedDevices](js-apis-bluetooth-baseProfile.md#baseprofilegetconnecteddevices) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
| Array&lt;string&gt; | Addresses of the connected devices.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

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
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc: bluetoothManager.A2dpSourceProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_A2DP_SOURCE) as bluetoothManager.A2dpSourceProfile;
    let retArray: Array<string> = a2dpSrc.getConnectionDevices();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```

### getDeviceState<sup>(deprecated)</sup>

getDeviceState(device: string): ProfileConnectionState

Obtains the connection state of the profile.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [baseProfile.getConnectionState](js-apis-bluetooth-baseProfile.md#baseprofilegetconnectionstate) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| device | string | Yes   | Address of the target device.|

**Return value**

| Type                                             | Description                   |
| ------------------------------------------------- | ----------------------- |
| [ProfileConnectionState](#profileconnectionstatedeprecated) | Profile connection state obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

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
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc: bluetoothManager.A2dpSourceProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_A2DP_SOURCE) as bluetoothManager.A2dpSourceProfile;
    let ret: bluetoothManager.ProfileConnectionState = a2dpSrc.getDeviceState('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## A2dpSourceProfile

Before using an API of **A2dpSourceProfile**, you need to create an instance of this class by using **getProfile()**.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [a2dp.A2dpSourceProfile](js-apis-bluetooth-a2dp.md#a2dpsourceprofile) instead.


### connect<sup>(deprecated)</sup>

connect(device: string): void

Sets up an Advanced Audio Distribution Profile (A2DP) connection.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. The substitute API is available only for system applications.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| device | string | Yes   | Address of the target device.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

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
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc: bluetoothManager.A2dpSourceProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_A2DP_SOURCE) as bluetoothManager.A2dpSourceProfile;
    a2dpSrc.connect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### disconnect<sup>(deprecated)</sup>

disconnect(device: string): void

Disconnects an A2DP connection.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. The substitute API is available only for system applications.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| device | string | Yes   | Address of the target device.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

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
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc: bluetoothManager.A2dpSourceProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_A2DP_SOURCE) as bluetoothManager.A2dpSourceProfile;
    a2dpSrc.disconnect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('connectionStateChange')<sup>(deprecated)</sup>

on(type: 'connectionStateChange', callback: Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt;): void

Subscribes to the A2DP connection state changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [baseProfile.on('connectionStateChange')](js-apis-bluetooth-baseProfile.md#baseprofileonconnectionstatechange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectionStateChange** indicates A2DP connection state changes.|
| callback | Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt; | Yes   | Callback used to return the A2DP connection state change.                              |

**Return value**

No value is returned.

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: bluetoothManager.StateChangeParam) {
    console.info('a2dp state = '+ JSON.stringify(data));
}
try {
let a2dpSrc: bluetoothManager.A2dpSourceProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_A2DP_SOURCE) as bluetoothManager.A2dpSourceProfile;
a2dpSrc.on('connectionStateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### off('connectionStateChange')<sup>(deprecated)</sup>

off(type: 'connectionStateChange', callback?: Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt;): void

Unsubscribes from the A2DP connection state changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [baseProfile.off('connectionStateChange')](js-apis-bluetooth-baseProfile.md#baseprofileoffconnectionstatechange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectionStateChange** indicates A2DP connection state changes.|
| callback | Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt; | No   | Callback to unregister.                              |

**Return value**

No value is returned.

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: bluetoothManager.StateChangeParam) {
    console.info('a2dp state = '+ JSON.stringify(data));
}
try {
let a2dpSrc: bluetoothManager.A2dpSourceProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_A2DP_SOURCE) as bluetoothManager.A2dpSourceProfile;
a2dpSrc.on('connectionStateChange', onReceiveEvent);
a2dpSrc.off('connectionStateChange', onReceiveEvent);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getPlayingState<sup>(deprecated)</sup>

getPlayingState(device: string): PlayingState

Obtains the playing state of a device.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [a2dp.A2dpSourceProfile#getPlayingState](js-apis-bluetooth-a2dp.md#getPlayingState) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| device | string | Yes   | Address of the target device.|

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| [PlayingState](#playingstatedeprecated) | Playing state of the remote device obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900004 | Profile not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc: bluetoothManager.A2dpSourceProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_A2DP_SOURCE) as bluetoothManager.A2dpSourceProfile;
    let state: bluetoothManager.PlayingState  = a2dpSrc.getPlayingState('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## HandsFreeAudioGatewayProfile<sup>(deprecated)</sup>

Before using an API of **HandsFreeAudioGatewayProfile**, you need to create an instance of this class by using **getProfile()**.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [hfp.HandsFreeAudioGatewayProfile](js-apis-bluetooth-hfp.md#HandsFreeAudioGatewayProfile) instead.


### connect

connect(device: string): void

Sets up a Hands-free Profile (HFP) connection of a device.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. The substitute API is available only for system applications.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| device | string | Yes   | Address of the target device.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

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
import { BusinessError } from '@ohos.base';
try {
    let hfpAg: bluetoothManager.HandsFreeAudioGatewayProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_HANDS_FREE_AUDIO_GATEWAY) as bluetoothManager.HandsFreeAudioGatewayProfile;
    hfpAg.connect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### disconnect<sup>(deprecated)</sup>

disconnect(device: string): void

Disconnects the HFP connection of a device.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. The substitute API is available only for system applications.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| device | string | Yes   | Address of the target device.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

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
import { BusinessError } from '@ohos.base';
try {
    let hfpAg: bluetoothManager.HandsFreeAudioGatewayProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_HANDS_FREE_AUDIO_GATEWAY) as bluetoothManager.HandsFreeAudioGatewayProfile;
    hfpAg.disconnect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('connectionStateChange')<sup>(deprecated)</sup>

on(type: 'connectionStateChange', callback: Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt;): void

Subscribes to the HFP connection state changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [baseProfile.on('connectionStateChange')](js-apis-bluetooth-baseProfile.md#baseprofileonconnectionstatechange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectionStateChange** indicates HFP connection state changes.|
| callback | Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt; | Yes   | Callback used to return the HFP connection state change.                              |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: bluetoothManager.StateChangeParam) {
    console.info('hfp state = '+ JSON.stringify(data));
}
try {
let hfpAg: bluetoothManager.HandsFreeAudioGatewayProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_HANDS_FREE_AUDIO_GATEWAY) as
  bluetoothManager.HandsFreeAudioGatewayProfile;
hfpAg.on('connectionStateChange', onReceiveEvent);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### off('connectionStateChange')<sup>(deprecated)</sup>

off(type: 'connectionStateChange', callback?: Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt;): void

Unsubscribes from the HFP connection state changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [baseProfile.off('connectionStateChange')](js-apis-bluetooth-baseProfile.md#baseprofileoffconnectionstatechange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectionStateChange** indicates HFP connection state changes.|
| callback | Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt; | No   | Callback to unregister.                              |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
**Example**

```js
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: bluetoothManager.StateChangeParam) {
    console.info('hfp state = '+ JSON.stringify(data));
}
try {
let hfpAg: bluetoothManager.HandsFreeAudioGatewayProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_HANDS_FREE_AUDIO_GATEWAY) as
  bluetoothManager.HandsFreeAudioGatewayProfile;
hfpAg.on('connectionStateChange', onReceiveEvent);
hfpAg.off('connectionStateChange', onReceiveEvent);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## HidHostProfile<sup>(deprecated)</sup>

Before using an API of **HidHostProfile**, you need to create an instance of this class by using **getProfile()**.

### on('connectionStateChange')<sup>(deprecated)</sup>

on(type: 'connectionStateChange', callback: Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt;): void

Subscribes to the HidHost connection state changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [baseProfile.on('connectionStateChange')](js-apis-bluetooth-baseProfile.md#baseprofileonconnectionstatechange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectionStateChange** indicates HidHost connection state changes.|
| callback | Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt; | Yes   | Callback used to return the HidHost connection state change.                              |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: bluetoothManager.StateChangeParam) {
    console.info('hidHost state = '+ JSON.stringify(data));
}
try {
let hidHost: bluetoothManager.HidHostProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_HID_HOST) as bluetoothManager.HidHostProfile;
hidHost.on('connectionStateChange', onReceiveEvent);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### off('connectionStateChange')<sup>(deprecated)</sup>

off(type: 'connectionStateChange', callback?: Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt;): void

Unsubscribes from the HidHost connection state changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [baseProfile.off('connectionStateChange')](js-apis-bluetooth-baseProfile.md#baseprofileoffconnectionstatechange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                     |
| -------- | ----------------------------------------------------- | ---- | --------------------------------------------------------- |
| type     | string                                                | Yes  | Event type. The value **connectionStateChange** indicates HidHost connection state changes.|
| callback | Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt; | No  | Callback to unregister.                                     |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: bluetoothManager.StateChangeParam) {
    console.info('hidHost state = '+ JSON.stringify(data));
}
try {
let hidHost: bluetoothManager.HidHostProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_HID_HOST) as bluetoothManager.HidHostProfile;
hidHost.on('connectionStateChange', onReceiveEvent);
hidHost.off('connectionStateChange', onReceiveEvent);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## PanProfile

Before using an API of **PanProfile**, you need to create an instance of this class by using **getProfile()**.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [pan.PanProfile](js-apis-bluetooth-pan.md#panprofile) instead.




### on('connectionStateChange')<sup>(deprecated)</sup>

on(type: 'connectionStateChange', callback: Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt;): void

Subscribes to the PAN connection state changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [baseProfile.on('connectionStateChange')](js-apis-bluetooth-baseProfile.md#baseprofileonconnectionstatechange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectionStateChange** indicates PAN connection state changes.|
| callback | Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt; | Yes   | Callback used to return the PAN connection state change.                              |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: bluetoothManager.StateChangeParam) {
    console.info('pan state = '+ JSON.stringify(data));
}
try {
let panProfile: bluetoothManager.PanProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_PAN_NETWORK) as bluetoothManager.PanProfile;
panProfile.on('connectionStateChange', onReceiveEvent);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### off('connectionStateChange')<sup>(deprecated)</sup>

off(type: 'connectionStateChange', callback?: Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt;): void

Unsubscribes from the PAN connection state changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [baseProfile.off('connectionStateChange')](js-apis-bluetooth-baseProfile.md#baseprofileoffconnectionstatechange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                                     |
| -------- | ----------------------------------------------------- | ---- | --------------------------------------------------------- |
| type     | string                                                | Yes  | Event type. The value **connectionStateChange** indicates PAN connection state changes.|
| callback | Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt; | No  | Callback to unregister.                                     |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
function onReceiveEvent(data: bluetoothManager.StateChangeParam) {
    console.info('pan state = '+ JSON.stringify(data));
}
try {
let panProfile: bluetoothManager.PanProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_PAN_NETWORK) as bluetoothManager.PanProfile;
panProfile.on('connectionStateChange', onReceiveEvent);
panProfile.off('connectionStateChange', onReceiveEvent);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## GattServer

Implements the Generic Attribute Profile (GATT) server. Before using an API of this class, you need to create a **GattServer** instance using **createGattServer()**.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattServer](js-apis-bluetooth-ble.md#GattServer) instead. 


### startAdvertising<sup>(deprecated)</sup>

startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void

Starts BLE advertising.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.startAdvertising](js-apis-bluetooth-ble.md#blestartadvertising) instead. 

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name        | Type                                   | Mandatory  | Description            |
| ----------- | ------------------------------------- | ---- | -------------- |
| setting     | [AdvertiseSetting](#advertisesettingdeprecated) | Yes   | Settings related to BLE advertising.   |
| advData     | [AdvertiseData](#advertisedatadeprecated)       | Yes   | Content of the BLE advertisement packet.     |
| advResponse | [AdvertiseData](#advertisedatadeprecated)       | No   | Response to the BLE scan request.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
let manufactureValueBuffer = new Uint8Array(4);
manufactureValueBuffer[0] = 1;
manufactureValueBuffer[1] = 2;
manufactureValueBuffer[2] = 3;
manufactureValueBuffer[3] = 4;

let serviceValueBuffer = new Uint8Array(4);
serviceValueBuffer[0] = 4;
serviceValueBuffer[1] = 6;
serviceValueBuffer[2] = 7;
serviceValueBuffer[3] = 8;
console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));
console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));
let gattServer = bluetoothManager.BLE.createGattServer();
try {
    let setting: bluetoothManager.AdvertiseSetting = {
        interval:150,
        txPower:0,
        connectable:true,
    };
    let manufactureDataUnit: bluetoothManager.ManufactureData = {
        manufactureId:4567,
        manufactureValue:manufactureValueBuffer.buffer
    };
    let serviceDataUnit: bluetoothManager.ServiceData = {
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
        serviceValue:serviceValueBuffer.buffer
    };
    let advData: bluetoothManager.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit],
    };
    let advResponse: bluetoothManager.AdvertiseData = {
        serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
        manufactureData:[manufactureDataUnit],
        serviceData:[serviceDataUnit],
    };
    gattServer.startAdvertising(setting, advData ,advResponse);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### stopAdvertising<sup>(deprecated)</sup>

stopAdvertising(): void

Stops BLE advertising.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.stopAdvertising](js-apis-bluetooth-ble.md#blestopadvertising) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
let server = bluetoothManager.BLE.createGattServer();
try {
    server.stopAdvertising();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### addService<sup>(deprecated)</sup>

addService(service: GattService): void

Adds a service to this GATT server.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattServer#addService](js-apis-bluetooth-ble.md#addservice) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name    | Type                         | Mandatory  | Description                      |
| ------- | --------------------------- | ---- | ------------------------ |
| service | [GattService](#gattservicedeprecated) | Yes   | Service to add. Settings related to BLE advertising.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
// Create descriptors.
let descriptors: Array<bluetoothManager.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(8);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
let descriptor: bluetoothManager.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;

// Create characteristics.
let characteristics: Array<bluetoothManager.BLECharacteristic> = [];
let arrayBufferC = new ArrayBuffer(8);
let cccV = new Uint8Array(arrayBufferC);
cccV[0] = 1;
let characteristic: bluetoothManager.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
let characteristicN: bluetoothManager.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001821-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
characteristics[0] = characteristic;

// Create a gattService instance.
let gattService: bluetoothManager.GattService = {serviceUuid:'00001810-0000-1000-8000-00805F9B34FB', isPrimary: true, characteristics:characteristics, includeServices:[]};

let gattServer  = bluetoothManager.BLE.createGattServer();
try {
    gattServer.addService(gattService);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### removeService<sup>(deprecated)</sup>

removeService(serviceUuid: string): void

Removes a service from this GATT server.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattServer#removeService](js-apis-bluetooth-ble.md#removeservice) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name        | Type    | Mandatory  | Description                                      |
| ----------- | ------ | ---- | ---------------------------------------- |
| serviceUuid | string | Yes   | Universally unique identifier (UUID) of the service to remove, for example, **00001810-0000-1000-8000-00805F9B34FB**.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

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
import { BusinessError } from '@ohos.base';
let server = bluetoothManager.BLE.createGattServer();
try {
    server.removeService('00001810-0000-1000-8000-00805F9B34FB');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### close<sup>(deprecated)</sup>

close(): void

Closes this GATT server to unregister it from the protocol stack. After this method is called, this [GattServer](#gattserver) cannot be used.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattServer#close](js-apis-bluetooth-ble.md#close) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
let server = bluetoothManager.BLE.createGattServer();
try {
    server.close();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### notifyCharacteristicChanged<sup>(deprecated)</sup>

notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): void

Notifies the connected client device when a characteristic value changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattServer#notifyCharacteristicChanged](js-apis-bluetooth-ble.md#notifycharacteristicchanged) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name                 | Type                                      | Mandatory  | Description                                     |
| -------------------- | ---------------------------------------- | ---- | --------------------------------------- |
| deviceId             | string                                   | Yes   | Address of the client that receives notifications, for example, XX:XX:XX:XX:XX:XX.|
| notifyCharacteristic | [NotifyCharacteristic](#notifycharacteristicdeprecated) | Yes   | New characteristic value.                              |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
// Create descriptors.
let descriptors: Array<bluetoothManager.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(8);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
let descriptor: bluetoothManager.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;
let arrayBufferC = new ArrayBuffer(8);
let characteristic: bluetoothManager.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
let notifyCharacteristic: bluetoothManager.NotifyCharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001821-0000-1000-8000-00805F9B34FB', characteristicValue: characteristic.characteristicValue, confirm: false};
let server = bluetoothManager.BLE.createGattServer();
try {
    server.notifyCharacteristicChanged('XX:XX:XX:XX:XX:XX', notifyCharacteristic);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### sendResponse<sup>(deprecated)</sup>

sendResponse(serverResponse: ServerResponse): void

Sends a response to a read or write request from the GATT client.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattServer#sendResponse](js-apis-bluetooth-ble.md#sendresponse) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                               | Mandatory  | Description             |
| -------------- | --------------------------------- | ---- | --------------- |
| serverResponse | [ServerResponse](#serverresponsedeprecated) | Yes   | Response returned by the GATT server.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
/* send response */
let arrayBufferCCC = new ArrayBuffer(8);
let cccValue = new Uint8Array(arrayBufferCCC);
cccValue[0] = 1123;
let serverResponse: bluetoothManager.ServerResponse = {
    deviceId: 'XX:XX:XX:XX:XX:XX',
    transId: 0,
    status: 0,
    offset: 0,
    value: arrayBufferCCC,
};

let gattServer = bluetoothManager.BLE.createGattServer();
try {
    gattServer.sendResponse(serverResponse);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('characteristicRead')<sup>(deprecated)</sup>

on(type: 'characteristicRead', callback: Callback&lt;CharacteristicReadRequest&gt;): void

Subscribes to the characteristic read request events.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattServer#on('characteristicRead')](js-apis-bluetooth-ble.md#oncharacteristicread) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                   |
| -------- | ---------------------------------------- | ---- | ------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **characteristicRead** indicates a characteristic read request event.|
| callback | Callback&lt;[CharacteristicReadRequest](#characteristicreadrequestdeprecated)&gt; | Yes   | Callback used to return a characteristic read request event from the GATT client.           |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
let arrayBufferCCC = new ArrayBuffer(8);
let cccValue = new Uint8Array(arrayBufferCCC);
cccValue[0] = 1123;
function ReadCharacteristicReq(characteristicReadRequest: bluetoothManager.CharacteristicReadRequest) {
    let deviceId: string = characteristicReadRequest.deviceId;
    let transId: number = characteristicReadRequest.transId;
    let offset: number = characteristicReadRequest.offset;
    let characteristicUuid: string = characteristicReadRequest.characteristicUuid;

    let serverResponse: bluetoothManager.ServerResponse = {deviceId: deviceId, transId: transId, status: 0, offset: offset, value:arrayBufferCCC};

    try {
        gattServer.sendResponse(serverResponse);
    } catch (err) {
        console.error('errCode: ' + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
    }
}

let gattServer = bluetoothManager.BLE.createGattServer();
gattServer.on("characteristicRead", ReadCharacteristicReq);
```


### off('characteristicRead')<sup>(deprecated)</sup>

off(type: 'characteristicRead', callback?: Callback&lt;CharacteristicReadRequest&gt;): void

Unsubscribes from the characteristic read request events.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattServer#off('characteristicRead')](js-apis-bluetooth-ble.md#offcharacteristicread) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **characteristicRead** indicates a characteristic read request event.   |
| callback | Callback&lt;[CharacteristicReadRequest](#characteristicreadrequestdeprecated)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregistersall callbacks for the specified **type**.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
let gattServer = bluetoothManager.BLE.createGattServer();
gattServer.off("characteristicRead");
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('characteristicWrite')<sup>(deprecated)</sup>

on(type: 'characteristicWrite', callback: Callback&lt;CharacteristicWriteRequest&gt;): void

Subscribes to the characteristic write request events.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattServer#on('characteristicWrite')](js-apis-bluetooth-ble.md#oncharacteristicwrite) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                    |
| -------- | ---------------------------------------- | ---- | -------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **characteristicWrite** indicates a characteristic write request event.|
| callback | Callback&lt;[CharacteristicWriteRequest](#characteristicwriterequestdeprecated)&gt; | Yes   | Callback used to return a characteristic write request from the GATT client.            |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
let arrayBufferCCC = new ArrayBuffer(8);
let cccValue = new Uint8Array(arrayBufferCCC);
function WriteCharacteristicReq(characteristicWriteRequest: bluetoothManager.CharacteristicWriteRequest) {
    let deviceId: string = characteristicWriteRequest.deviceId;
    let transId: number = characteristicWriteRequest.transId;
    let offset: number = characteristicWriteRequest.offset;
    let isPrep: boolean = characteristicWriteRequest.isPrep;
    let needRsp: boolean = characteristicWriteRequest.needRsp;
    let value: Uint8Array =  new Uint8Array(characteristicWriteRequest.value);
    let characteristicUuid: string = characteristicWriteRequest.characteristicUuid;

    cccValue[0] = value[0];
    let serverResponse: bluetoothManager.ServerResponse = {deviceId: deviceId, transId: transId, status: 0, offset: offset, value:arrayBufferCCC};

    try {
        gattServer.sendResponse(serverResponse);
    } catch (err) {
        console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
}

let gattServer = bluetoothManager.BLE.createGattServer();
gattServer.on("characteristicWrite", WriteCharacteristicReq);
```


### off('characteristicWrite')<sup>(deprecated)</sup>

off(type: 'characteristicWrite', callback?: Callback&lt;CharacteristicWriteRequest&gt;): void

Unsubscribes from the characteristic write request events.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattServer#off('characteristicWrite')](js-apis-bluetooth-ble.md#offcharacteristicwrite) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **characteristicWrite** indicates a characteristic write request event.  |
| callback | Callback&lt;[CharacteristicWriteRequest](#characteristicwriterequestdeprecated)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregistersall callbacks for the specified **type**.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
let gattServer = bluetoothManager.BLE.createGattServer();
gattServer.off("characteristicWrite");
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('descriptorRead')<sup>(deprecated)</sup>

on(type: 'descriptorRead', callback: Callback&lt;DescriptorReadRequest&gt;): void

Subscribes to the descriptor read request events.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattServer#on('descriptorRead')](js-apis-bluetooth-ble.md#ondescriptorread) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                               |
| -------- | ---------------------------------------- | ---- | --------------------------------- |
| type     | string                                   | Yes   | Event type. The value **descriptorRead** indicates a descriptor read request event.|
| callback | Callback&lt;[DescriptorReadRequest](#descriptorreadrequestdeprecated)&gt; | Yes   | Callback used to return a descriptor read request event from the GATT client.       |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
let arrayBufferDesc = new ArrayBuffer(8);
let descValue = new Uint8Array(arrayBufferDesc);
descValue[0] = 1101;
function ReadDescriptorReq(descriptorReadRequest: bluetoothManager.DescriptorReadRequest) {
    let deviceId: string = descriptorReadRequest.deviceId;
    let transId: number = descriptorReadRequest.transId;
    let offset: number = descriptorReadRequest.offset;
    let descriptorUuid: string = descriptorReadRequest.descriptorUuid;

    let serverResponse: bluetoothManager.ServerResponse = {deviceId: deviceId, transId: transId, status: 0, offset: offset, value:arrayBufferDesc};

    try {
        gattServer.sendResponse(serverResponse);
    } catch (err) {
        console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
}

let gattServer = bluetoothManager.BLE.createGattServer();
gattServer.on("descriptorRead", ReadDescriptorReq);
```


### off('descriptorRead')<sup>(deprecated)</sup>

off(type: 'descriptorRead', callback?: Callback&lt;DescriptorReadRequest&gt;): void

Unsubscribes from the descriptor read request events.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattServer#off('descriptorRead')](js-apis-bluetooth-ble.md#offdescriptorread) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **descriptorRead** indicates a descriptor read request event.       |
| callback | Callback&lt;[DescriptorReadRequest](#descriptorreadrequestdeprecated)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregistersall callbacks for the specified **type**.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
let gattServer = bluetoothManager.BLE.createGattServer();
gattServer.off("descriptorRead");
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('descriptorWrite')<sup>(deprecated)</sup>

on(type: 'descriptorWrite', callback: Callback&lt;DescriptorWriteRequest&gt;): void

Subscribes to the descriptor write request events.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattServer#on('descriptorWrite')](js-apis-bluetooth-ble.md#ondescriptorwrite) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                |
| -------- | ---------------------------------------- | ---- | ---------------------------------- |
| type     | string                                   | Yes   | Event type. The value **descriptorWrite** indicates a descriptor write request event.|
| callback | Callback&lt;[DescriptorWriteRequest](#descriptorwriterequestdeprecated)&gt; | Yes   | Callback used to return a descriptor write request from the GATT client.        |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
let arrayBufferDesc = new ArrayBuffer(8);
let descValue = new Uint8Array(arrayBufferDesc);
function WriteDescriptorReq(descriptorWriteRequest: bluetoothManager.DescriptorWriteRequest) {
    let deviceId: string = descriptorWriteRequest.deviceId;
    let transId: number = descriptorWriteRequest.transId;
    let offset: number = descriptorWriteRequest.offset;
    let isPrep: boolean = descriptorWriteRequest.isPrep;
    let needRsp: boolean = descriptorWriteRequest.needRsp;
    let value: Uint8Array = new Uint8Array(descriptorWriteRequest.value);
    let descriptorUuid: string = descriptorWriteRequest.descriptorUuid;

    descValue[0] = value[0];
    let serverResponse: bluetoothManager.ServerResponse = {deviceId: deviceId, transId: transId, status: 0, offset: offset, value:arrayBufferDesc};

    try {
        gattServer.sendResponse(serverResponse);
    } catch (err) {
        console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
    }
}

let gattServer = bluetoothManager.BLE.createGattServer();
gattServer.on("descriptorWrite", WriteDescriptorReq);
```


### off('descriptorWrite')<sup>(deprecated)</sup>

off(type: 'descriptorWrite', callback?: Callback&lt;DescriptorWriteRequest&gt;): void

Unsubscribes from the descriptor write request events.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattServer#off('descriptorWrite')](js-apis-bluetooth-ble.md#offdescriptorwrite) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **descriptorWrite** indicates a descriptor write request event.      |
| callback | Callback&lt;[DescriptorWriteRequest](#descriptorwriterequestdeprecated)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregistersall callbacks for the specified **type**.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
let gattServer = bluetoothManager.BLE.createGattServer();
gattServer.off("descriptorWrite");
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('connectStateChange')<sup>(deprecated)</sup>

on(type: 'connectStateChange', callback: Callback&lt;BLEConnectChangedState&gt;): void

Subscribes to the BLE connection state changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattServer#on('connectionStateChange')](js-apis-bluetooth-ble.md#onconnectionstatechange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectStateChange** indicates a BLE connection state change event.|
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstatedeprecated)&gt; | Yes   | Callback used to return the BLE connection state.                         |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
function Connected(BLEConnectChangedState: bluetoothManager.BLEConnectChangedState) {
  let deviceId: string = BLEConnectChangedState.deviceId;
  let status: bluetoothManager.ProfileConnectionState  = BLEConnectChangedState.state;
}
try {
let gattServer = bluetoothManager.BLE.createGattServer();
gattServer.on("connectStateChange", Connected);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### off('connectStateChange')<sup>(deprecated)</sup>

off(type: 'connectStateChange', callback?: Callback&lt;BLEConnectChangedState&gt;): void

Unsubscribes from the BLE connection state changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattServer#off('connectionStateChange')](js-apis-bluetooth-ble.md#offconnectionstatechange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectStateChange** indicates a BLE connection state change event.|
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstatedeprecated)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregistersall callbacks for the specified **type**.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
let gattServer = bluetoothManager.BLE.createGattServer();
gattServer.off("connectStateChange");
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


## GattClientDevice

Implements the GATT client. Before using an API of this class, you must create a **GattClientDevice** instance using **createGattClientDevice(deviceId: string)**.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice](js-apis-bluetooth-ble.md#gattclientdevice) instead.


### connect<sup>(deprecated)</sup>

connect(): void

Initiates a connection to the remote BLE device.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#connect](js-apis-bluetooth-ble.md#connect) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.connect();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### disconnect<sup>(deprecated)</sup>

disconnect(): void

Disconnects from the remote BLE device.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#disconnect](js-apis-bluetooth-ble.md#disconnect) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.disconnect();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### close<sup>(deprecated)</sup>

close(): void

Closes this GATT client to unregister it from the protocol stack. After this method is called, this [GattClientDevice](#gattclientdevice) instance cannot be used.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#close](js-apis-bluetooth-ble.md#close) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth disabled.                 |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.close();
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```




### getServices<sup>(deprecated)</sup>

getServices(callback: AsyncCallback&lt;Array&lt;GattService&gt;&gt;): void

Obtains all services of the remote BLE device. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#getServices](js-apis-bluetooth-ble.md#getservices) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;Array&lt;[GattService](#gattservicedeprecated)&gt;&gt; | Yes   | Callback used to return the services obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.             |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
// Callback mode.
function getServices(code: BusinessError, gattServices: Array<bluetoothManager.GattService>) {
  if (code.code == 0) {
      let services: Array<bluetoothManager.GattService> = gattServices;
      console.log('bluetooth code is ' + code.code);
      console.log("bluetooth services size is ", services.length);

      for (let i = 0; i < services.length; i++) {
        console.log('bluetooth serviceUuid is ' + services[i].serviceUuid);
      }
  }
}

try {
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.connect();
    device.getServices(getServices);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### getServices<sup>(deprecated)</sup>

getServices(): Promise&lt;Array&lt;GattService&gt;&gt;

Obtains all services of the remote BLE device. This API uses a promise to return the result.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#getServices](js-apis-bluetooth-ble.md#getservices-1) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                                      | Description                         |
| ---------------------------------------- | --------------------------- |
| Promise&lt;Array&lt;[GattService](#gattservicedeprecated)&gt;&gt; | Promise used to return the services obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
// Promise
try {
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.connect();
    device.getServices().then(result => {
        console.info("getServices successfully:" + JSON.stringify(result));
    });
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### readCharacteristicValue<sup>(deprecated)</sup>

readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback&lt;BLECharacteristic&gt;): void

Reads the characteristic value of the specific service of the remote BLE device. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#readCharacteristicValue](js-apis-bluetooth-ble.md#readcharacteristicvalue) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                      | Mandatory  | Description                     |
| -------------- | ---------------------------------------- | ---- | ----------------------- |
| characteristic | [BLECharacteristic](#blecharacteristicdeprecated)  | Yes   | Characteristic value to read.               |
| callback       | AsyncCallback&lt;[BLECharacteristic](#blecharacteristicdeprecated)&gt; | Yes   | Callback used to return the characteristic value read.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2901000 | Read forbidden.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
function readCcc(code: BusinessError, BLECharacteristic: bluetoothManager.BLECharacteristic) {
    if (code.code != 0) {
        return;
    }
    console.log('bluetooth characteristic uuid: ' + BLECharacteristic.characteristicUuid);
    let value = new Uint8Array(BLECharacteristic.characteristicValue);
    console.log('bluetooth characteristic value: ' + value[0] +','+ value[1]+','+ value[2]+','+ value[3]);
}

let descriptors: Array<bluetoothManager.BLEDescriptor> = [];
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor: bluetoothManager.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic: bluetoothManager.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    characteristicValue: bufferCCC, descriptors:descriptors};

try {
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.readCharacteristicValue(characteristic, readCcc);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### readCharacteristicValue<sup>(deprecated)</sup>

readCharacteristicValue(characteristic: BLECharacteristic): Promise&lt;BLECharacteristic&gt;

Reads the characteristic value of the specific service of the remote BLE device. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#readCharacteristicValue](js-apis-bluetooth-ble.md#readcharacteristicvalue-1) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description      |
| -------------- | --------------------------------------- | ---- | -------- |
| characteristic | [BLECharacteristic](#blecharacteristicdeprecated) | Yes   | Characteristic value to read.|

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| Promise&lt;[BLECharacteristic](#blecharacteristicdeprecated)&gt; | Promise used to return the characteristic value read.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2901000 | Read forbidden.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
let descriptors: Array<bluetoothManager.BLEDescriptor> = [];
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor: bluetoothManager.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic: bluetoothManager.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    characteristicValue: bufferCCC, descriptors:descriptors};

try {
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.readCharacteristicValue(characteristic);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### readDescriptorValue<sup>(deprecated)</sup>

readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback&lt;BLEDescriptor&gt;): void

Reads the descriptor contained in the specific characteristic of the remote BLE device. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#readDescriptorValue](js-apis-bluetooth-ble.md#readdescriptorvalue) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description                     |
| ---------- | ---------------------------------------- | ---- | ----------------------- |
| descriptor | [BLEDescriptor](#bledescriptordeprecated)          | Yes   | Descriptor to read.               |
| callback   | AsyncCallback&lt;[BLEDescriptor](#bledescriptordeprecated)&gt; | Yes   | Callback used to return the descriptor read.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2901000 | Read forbidden.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
function readDesc(code: BusinessError, BLEDescriptor: bluetoothManager.BLEDescriptor) {
    if (code.code != 0) {
        return;
    }
    console.log('bluetooth descriptor uuid: ' + BLEDescriptor.descriptorUuid);
    let value = new Uint8Array(BLEDescriptor.descriptorValue);
    console.log('bluetooth descriptor value: ' + value[0] +','+ value[1]+','+ value[2]+','+ value[3]);
}

let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor: bluetoothManager.BLEDescriptor = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB',
    descriptorValue: bufferDesc
};
try {
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.readDescriptorValue(descriptor, readDesc);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### readDescriptorValue<sup>(deprecated)</sup>

readDescriptorValue(descriptor: BLEDescriptor): Promise&lt;BLEDescriptor&gt;

Reads the descriptor contained in the specific characteristic of the remote BLE device. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#readDescriptorValue](js-apis-bluetooth-ble.md#readdescriptorvalue-1) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name       | Type                             | Mandatory  | Description      |
| ---------- | ------------------------------- | ---- | -------- |
| descriptor | [BLEDescriptor](#bledescriptordeprecated) | Yes   | Descriptor to read.|

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| Promise&lt;[BLEDescriptor](#bledescriptordeprecated)&gt; | Promise used to return the descriptor read.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2901000 | Read forbidden.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor: bluetoothManager.BLEDescriptor = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB',
    descriptorValue: bufferDesc
};
try {
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.readDescriptorValue(descriptor);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### writeCharacteristicValue<sup>(deprecated)</sup>

writeCharacteristicValue(characteristic: BLECharacteristic): void

Writes a characteristic value to the remote BLE device.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#writeCharacteristicValue](js-apis-bluetooth-ble.md#writecharacteristicvalue) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description                 |
| -------------- | --------------------------------------- | ---- | ------------------- |
| characteristic | [BLECharacteristic](#blecharacteristicdeprecated) | Yes   | Binary value and other parameters of the BLE device characteristic.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2901001 | Write forbidden.                        |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
let descriptors: Array<bluetoothManager.BLEDescriptor> = [];
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor: bluetoothManager.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic: bluetoothManager.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    characteristicValue: bufferCCC, descriptors:descriptors};
try {
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.writeCharacteristicValue(characteristic);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### writeDescriptorValue<sup>(deprecated)</sup>

writeDescriptorValue(descriptor: BLEDescriptor): void

Writes binary data to the specific descriptor of the remote BLE device.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#writeCharacteristicValue](js-apis-bluetooth-ble.md#writecharacteristicvalue-1) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name       | Type                             | Mandatory  | Description                |
| ---------- | ------------------------------- | ---- | ------------------ |
| descriptor | [BLEDescriptor](#bledescriptordeprecated) | Yes   | Binary value and other parameters of the BLE device descriptor.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2901001 | Write forbidden.                        |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 22;
let descriptor: bluetoothManager.BLEDescriptor = {
    serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB',
    descriptorValue: bufferDesc
};
try {
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.writeDescriptorValue(descriptor);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### setBLEMtuSize<sup>(deprecated)</sup>

setBLEMtuSize(mtu: number): void

Sets the maximum transmission unit (MTU) that can be transmitted between the GATT client and its remote BLE device. This API can be used only after a connection is set up by calling [connect](#connect).

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#setBLEMtuSize](js-apis-bluetooth-ble.md#setBLEMtuSize) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name | Type    | Mandatory  | Description            |
| ---- | ------ | ---- | -------------- |
| mtu  | number | Yes   | MTU to set, which ranges from 22 to 512 bytes.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.setBLEMtuSize(128);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### setNotifyCharacteristicChanged<sup>(deprecated)</sup>

setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): void

Sets the function of notifying the GATT client when the characteristic value of the remote BLE device changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#setCharacteristicChangeNotification](js-apis-bluetooth-ble.md#setcharacteristicchangenotification) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description                           |
| -------------- | --------------------------------------- | ---- | ----------------------------- |
| characteristic | [BLECharacteristic](#blecharacteristicdeprecated) | Yes   | BLE characteristic to listen for.                     |
| enable         | boolean                                 | Yes   | Whether to enable the notify function. The value **true** means to enable the notify function, and the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
// Create descriptors.
let descriptors: Array<bluetoothManager.BLEDescriptor> = [];
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor: bluetoothManager.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic: bluetoothManager.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
    characteristicValue: bufferCCC, descriptors:descriptors};
try {
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.setNotifyCharacteristicChanged(characteristic, false);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}

```


### on('BLECharacteristicChange')<sup>(deprecated)</sup>

on(type: 'BLECharacteristicChange', callback: Callback&lt;BLECharacteristic&gt;): void

Subscribes to the BLE characteristic changes. The client can receive a notification from the server only after the **setNotifyCharacteristicChanged** method is called.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#on('BLECharacteristicChange')](js-apis-bluetooth-ble.md#onblecharacteristicchange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLECharacteristicChange** indicates a characteristic value change event.|
| callback | Callback&lt;[BLECharacteristic](#blecharacteristicdeprecated)&gt; | Yes   | Callback used to return the characteristic value changes.                 |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
function CharacteristicChange(characteristicChangeReq: ble.BLECharacteristic) {
    let serviceUuid: string = characteristicChangeReq.serviceUuid;
    let characteristicUuid: string = characteristicChangeReq.characteristicUuid;
    let value: Uint8Array = new Uint8Array(characteristicChangeReq.characteristicValue);
}
try {
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.on('BLECharacteristicChange', CharacteristicChange);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### off('BLECharacteristicChange')<sup>(deprecated)</sup>

off(type: 'BLECharacteristicChange', callback?: Callback&lt;BLECharacteristic&gt;): void

Unsubscribes from the BLE characteristic changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#off('BLECharacteristicChange')](js-apis-bluetooth-ble.md#offblecharacteristicchange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLECharacteristicChange** indicates a characteristic value change event.|
| callback | Callback&lt;[BLECharacteristic](#blecharacteristicdeprecated)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregistersall callbacks for the specified **type**.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.off('BLECharacteristicChange');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### on('BLEConnectionStateChange')<sup>(deprecated)</sup>

on(type: 'BLEConnectionStateChange', callback: Callback&lt;BLEConnectChangedState&gt;): void

Subscribes to the BLE connection state changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#on('BLEConnectionStateChange')](js-apis-bluetooth-ble.md#onbleconnectionstatechange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEConnectionStateChange** indicates a BLE connection state change event.|
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstatedeprecated)&gt; | Yes   | Callback used to return the BLE connection state.                          |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
function ConnectStateChanged(state: bluetoothManager.BLEConnectChangedState) {
    console.log('bluetooth connect state changed');
    let connectState: bluetoothManager.ProfileConnectionState = state.state;
}
try {
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.on('BLEConnectionStateChange', ConnectStateChanged);
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### off('BLEConnectionStateChange')<sup>(deprecated)</sup>

off(type: 'BLEConnectionStateChange', callback?: Callback&lt;BLEConnectChangedState&gt;): void

Unsubscribes from the BLE connection state changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#off('BLEConnectionStateChange')](js-apis-bluetooth-ble.md#offbleconnectionstatechange) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEConnectionStateChange** indicates a BLE connection state change event.|
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstatedeprecated)&gt; | No   | Callback to unregister. If this parameter is not set, this API unregistersall callbacks for the specified **type**.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
    device.off('BLEConnectionStateChange');
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### getDeviceName<sup>(deprecated)</sup>

getDeviceName(callback: AsyncCallback&lt;string&gt;): void

Obtains the name of the remote BLE device. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#getDeviceName](js-apis-bluetooth-ble.md#getdevicename) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                             |
| -------- | --------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the remote BLE device name obtained.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.              |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
// callback
try {
    let gattClient = bluetoothManager.BLE.createGattClientDevice("XX:XX:XX:XX:XX:XX");
    gattClient.connect();
    let deviceName = gattClient.getDeviceName((err, data)=> {
        console.info('device name err ' + JSON.stringify(err));
        console.info('device name' + JSON.stringify(data));
    })
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### getDeviceName<sup>(deprecated)</sup>

getDeviceName(): Promise&lt;string&gt;

Obtains the name of the remote BLE device. This API uses a promise to return the result.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#getDeviceName](js-apis-bluetooth-ble.md#getdevicename-1) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                   | Description                                |
| --------------------- | ---------------------------------- |
| Promise&lt;string&gt; | Promise used to return the remote BLE device name.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.              |
|801 | Capability not supported.          |
|2900001 | Service stopped.                         |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
// promise
try {
    let gattClient = bluetoothManager.BLE.createGattClientDevice("XX:XX:XX:XX:XX:XX");
    gattClient.connect();
    let deviceName = gattClient.getDeviceName().then((data) => {
        console.info('device name' + JSON.stringify(data));
    })
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### getRssiValue<sup>(deprecated)</sup>

getRssiValue(callback: AsyncCallback&lt;number&gt;): void

Obtains the RSSI of the remote BLE device. This API uses an asynchronous callback to return the result. It can be used only after a connection is set up by calling [connect](#connect).

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#getRssiValue](js-apis-bluetooth-ble.md#getrssivalue) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                            |
| -------- | --------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the RSSI, in dBm.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.              |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
// callback
try {
    let gattClient = bluetoothManager.BLE.createGattClientDevice("XX:XX:XX:XX:XX:XX");
    gattClient.connect();
    let rssi = gattClient.getRssiValue((err: BusinessError, data: number)=> {
        console.info('rssi err ' + JSON.stringify(err));
        console.info('rssi value' + JSON.stringify(data));
    })
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```


### getRssiValue<sup>(deprecated)</sup>

getRssiValue(): Promise&lt;number&gt;

Obtains the RSSI of the remote BLE device. This API uses a promise to return the result. It can be used only after a connection is set up by calling [connect](#connect).

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattClientDevice#getRssiValue](js-apis-bluetooth-ble.md#getrssivalue-1) instead.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                   | Description                               |
| --------------------- | --------------------------------- |
| Promise&lt;number&gt; | Promise used to return the RSSI, in dBm.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.               |
|801 | Capability not supported.          |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
// promise
try {
    let gattClient = bluetoothManager.BLE.createGattClientDevice("XX:XX:XX:XX:XX:XX");
    let rssi = gattClient.getRssiValue().then((data: number) => {
        console.info('rssi' + JSON.stringify(data));
    })
} catch (err) {
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);
}
```

## ScanMode<sup>(deprecated)</sup>

Enumerates the scan modes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.ScanMode](js-apis-bluetooth-connection.md#scanmode) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                                      | Value | Description             |
| ---------------------------------------- | ---- | --------------- |
| SCAN_MODE_NONE                           | 0    | No scan mode.        |
| SCAN_MODE_CONNECTABLE                    | 1    | Connectable mode.       |
| SCAN_MODE_GENERAL_DISCOVERABLE           | 2    | General discoverable mode.   |
| SCAN_MODE_LIMITED_DISCOVERABLE           | 3    | Limited discoverable mode.   |
| SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE | 4    | General connectable and discoverable mode.|
| SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE | 5    | Limited connectable and discoverable mode.|

## BondState<sup>(deprecated)</sup>

Enumerates the pairing states.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.BondState](js-apis-bluetooth-connection.md#bondstate) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Value | Description    |
| ------------------ | ---- | ------ |
| BOND_STATE_INVALID | 0    | Invalid pairing.|
| BOND_STATE_BONDING | 1    | Pairing. |
| BOND_STATE_BONDED  | 2    | Paired.  |


## SppOption<sup>(deprecated)</sup>

Defines the SPP configuration parameters.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [socket.SppOption](js-apis-bluetooth-socket.md#sppoptions) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name    | Type               | Readable  | Writable  | Description         |
| ------ | ------------------- | ---- | ---- | ----------- |
| uuid   | string              | Yes   | Yes   | UUID of the SPP.|
| secure | boolean             | Yes   | Yes   | Whether it is a secure channel.   |
| type   | [SppType](#spptypedeprecated) | Yes   | Yes   | Type of the SPP link.   |


## SppType<sup>(deprecated)</sup>

Enumerates the SPP link types.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [socket.SppType](js-apis-bluetooth-socket.md#spptype) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name        | Value | Description           |
| ---------- | ---- | ------------- |
| SPP_RFCOMM | 0    | Radio frequency communication (RFCOMM) link type.|


## GattService<sup>(deprecated)</sup>

Defines the GATT service API parameters.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.GattService](js-apis-bluetooth-ble.md#gattservice) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name             | Type                                    | Readable  | Writable  | Description                                      |
| --------------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| serviceUuid     | string                                   | Yes   | Yes   | UUID of the service, for example, **00001888-0000-1000-8000-00805f9b34fb**.|
| isPrimary       | boolean                                  | Yes   | Yes   | Whether the service is a primary service. The value **true** means a primary service.               |
| characteristics | Array&lt;[BLECharacteristic](#blecharacteristicdeprecated)&gt; | Yes   | Yes   | List of characteristics of the service.                            |
| includeServices | Array&lt;[GattService](#gattservicedeprecated)&gt; | Yes   | Yes   | Services on which the service depends.                            |


## BLECharacteristic<sup>(deprecated)</sup>

Defines the characteristic API parameters.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.BLECharacteristic](js-apis-bluetooth-ble.md#blecharacteristic) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                 | Type                                    | Readable  | Writable  | Description                                |
| ------------------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| serviceUuid         | string                                   | Yes   | Yes   | UUID of the service, for example, **00001888-0000-1000-8000-00805f9b34fb**.|
| characteristicUuid  | string                                   | Yes   | Yes   | UUID of the characteristic, for example, **00002a11-0000-1000-8000-00805f9b34fb**.|
| characteristicValue | ArrayBuffer                              | Yes   | Yes   | Binary value of the characteristic.                     |
| descriptors         | Array&lt;[BLEDescriptor](#bledescriptordeprecated)&gt; | Yes   | Yes   | List of descriptors of the characteristic.               |


## BLEDescriptor<sup>(deprecated)</sup>

Defines the descriptor API parameters.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.BLEDescriptor](js-apis-bluetooth-ble.md#bledescriptor) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type       | Readable  | Writable  | Description                                      |
| ------------------ | ----------- | ---- | ---- | ---------------------------------------- |
| serviceUuid        | string      | Yes   | Yes   | UUID of the service, for example, **00001888-0000-1000-8000-00805f9b34fb**.|
| characteristicUuid | string      | Yes   | Yes   | UUID of the characteristic, for example, **00002a11-0000-1000-8000-00805f9b34fb**.|
| descriptorUuid     | string      | Yes   | Yes   | UUID of the descriptor, for example, **00002902-0000-1000-8000-00805f9b34fb**.|
| descriptorValue    | ArrayBuffer | Yes   | Yes   | Binary value of the descriptor.                             |


## NotifyCharacteristic<sup>(deprecated)</sup>

Defines the parameters in the notifications sent when the server characteristic value changes.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.NotifyCharacteristic](js-apis-bluetooth-ble.md#notifycharacteristic) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                 | Type       | Readable  | Writable  | Description                                      |
| ------------------- | ----------- | ---- | ---- | ---------------------------------------- |
| serviceUuid         | string      | Yes   | Yes   | UUID of the service, for example, **00001888-0000-1000-8000-00805f9b34fb**.|
| characteristicUuid  | string      | Yes   | Yes   | UUID of the characteristic, for example, **00002a11-0000-1000-8000-00805f9b34fb**.|
| characteristicValue | ArrayBuffer | Yes   | Yes   | Binary value of the characteristic.                              |
| confirm             | boolean     | Yes   | Yes   | Whether the notification needs to be confirmed by the remote end. For a notification, set it to **true**. In this case, the remote end must confirm the receipt of the notification. For an indication, set it to **false**. In this case, the remote end does not need to confirm the receipt of the notification.|


## CharacteristicReadRequest<sup>(deprecated)</sup>

Defines the parameters of the **CharacteristicReadReq** event received by the server.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.CharacteristicReadRequest](js-apis-bluetooth-ble.md#characteristicreadrequest) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type  | Readable  | Writable  | Description                                      |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | Yes   | No   | Address of the remote device that sends the **CharacteristicReadReq** event, for example, XX:XX:XX:XX:XX:XX.|
| transId            | number | Yes   | No   | Transmission ID of the read request. The response returned by the server must use the same transmission ID.      |
| offset             | number | Yes   | No   | Position from which the characteristic value is read. For example, **k** means to read from the kth byte. The response returned by the server must use the same offset.|
| characteristicUuid | string | Yes   | No   | UUID of the characteristic, for example, **00002a11-0000-1000-8000-00805f9b34fb**.|
| serviceUuid        | string | Yes   | No   | UUID of the service, for example, **00001888-0000-1000-8000-00805f9b34fb**.|


## CharacteristicWriteRequest<sup>(deprecated)</sup>

Defines the parameters of the **CharacteristicWriteReq** event received by the server.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.CharacteristicWriteRequest](js-apis-bluetooth-ble.md#characteristicwriterequest) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type  | Readable  | Writable  | Description                                      |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | Yes   | No   | Address of the remote device that sends the **CharacteristicWriteReq** event, for example, XX:XX:XX:XX:XX:XX.|
| transId            | number | Yes   | No   | Transmission ID of the write request. The response returned by the server must use the same transmission ID.      |
| offset             | number | Yes   | No   | Start position for writing the characteristic value. For example, **k** means to write from the kth byte. The response returned by the server must use the same offset.|
| characteristicUuid | string | Yes   | No   | UUID of the characteristic, for example, **00002a11-0000-1000-8000-00805f9b34fb**.|
| serviceUuid        | string | Yes   | No   | UUID of the service, for example, **00001888-0000-1000-8000-00805f9b34fb**.|


## DescriptorReadRequest<sup>(deprecated)</sup>

Defines the parameters of the **DescriptorReadReq** event received by the server.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.DescriptorReadRequest](js-apis-bluetooth-ble.md#descriptorreadrequest) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type  | Readable  | Writable  | Description                                      |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | Yes   | No   | Address of the remote device that sends a **DescriptorReadReq** event, for example, XX:XX:XX:XX:XX:XX.|
| transId            | number | Yes   | No   | Transmission ID of the read request. The response returned by the server must use the same transmission ID.      |
| offset             | number | Yes   | No   | Position from which the descriptor is read. For example, **k** means to read from the kth byte. The response returned by the server must use the same offset.|
| descriptorUuid     | string | Yes   | No   | UUID of the descriptor, for example, **00002902-0000-1000-8000-00805f9b34fb**.|
| characteristicUuid | string | Yes   | No   | UUID of the characteristic, for example, **00002a11-0000-1000-8000-00805f9b34fb**.|
| serviceUuid        | string | Yes   | No   | UUID of the service, for example, **00001888-0000-1000-8000-00805f9b34fb**.|


## DescriptorWriteRequest<sup>(deprecated)</sup>

Defines the parameters of the **DescriptorWriteReq** event received by the server.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.DescriptorWriteRequest](js-apis-bluetooth-ble.md#descriptorwriterequest) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type       | Readable  | Writable  | Description                                      |
| ------------------ | ----------- | ---- | ---- | ---------------------------------------- |
| deviceId           | string      | Yes   | No   | Address of the remote device that sends a **DescriptorWriteReq** event, for example, XX:XX:XX:XX:XX:XX.|
| transId            | number      | Yes   | No   | Transmission ID of the write request. The response returned by the server must use the same transmission ID.      |
| offset             | number      | Yes   | No   | Start position for writing the descriptor. For example, **k** means to write from the kth byte. The response returned by the server must use the same offset.|
| isPrep             | boolean     | Yes   | No   | Whether the write request is executed immediately.                            |
| needRsp            | boolean     | Yes   | No   | Whether to send a response to the GATT client.                      |
| value              | ArrayBuffer | Yes   | No   | Binary value of the descriptor to write.                          |
| descriptorUuid     | string      | Yes   | No   | UUID of the descriptor, for example, **00002902-0000-1000-8000-00805f9b34fb**.|
| characteristicUuid | string      | Yes   | No   | UUID of the characteristic, for example, **00002a11-0000-1000-8000-00805f9b34fb**.|
| serviceUuid        | string      | Yes   | No   | UUID of the service, for example, **00001888-0000-1000-8000-00805f9b34fb**.|


## ServerResponse<sup>(deprecated)</sup>

Defines the parameters of the server's response to the GATT client's read/write request.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.ServerResponse](js-apis-bluetooth-ble.md#serverresponse) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type       | Readable  | Writable  | Description                                    |
| -------- | ----------- | ---- | ---- | -------------------------------------- |
| deviceId | string      | Yes   | No   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.      |
| transId  | number      | Yes   | No   | Transmission ID of the request. The value must be the same as the ID carried in the read/write request received.       |
| status   | number      | Yes   | No   | Response state. Set this parameter to **0**, which indicates a normal response.                  |
| offset   | number      | Yes   | No   | Start read/write position. The value must be the same as the offset carried in the read/write request.|
| value    | ArrayBuffer | Yes   | No   | Binary data in the response.                         |


## BLEConnectChangedState<sup>(deprecated)</sup>

Defines the parameters of **BLEConnectChangedState**.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [BLEConnectionChangeState](js-apis-bluetooth-ble.md#bleconnectionchangestate) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name    | Type                                         | Readable| Writable| Description                                         |
| -------- | ------------------------------------------------- | ---- | ---- | --------------------------------------------- |
| deviceId | string                                            | Yes  | No  | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|
| state    | [ProfileConnectionState](#profileconnectionstatedeprecated) | Yes  | Yes  | BLE connection state.                      |


## ProfileConnectionState<sup>(deprecated)</sup>

Enumerates the profile connection states.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [constant.ProfileConnectionState](js-apis-bluetooth-constant.md#profileconnectionstate) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                 | Value | Description            |
| ------------------- | ---- | -------------- |
| STATE_DISCONNECTED  | 0    | Disconnected. |
| STATE_CONNECTING    | 1    | Connecting.|
| STATE_CONNECTED     | 2    | Connected. |
| STATE_DISCONNECTING | 3    | Disconnecting.|


## ScanFilter<sup>(deprecated)</sup>

Defines the scan filter parameters.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.ScanFilter](js-apis-bluetooth-ble.md#scanfilter) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                                    | Type   | Readable| Writable| Description                                                        |
| ---------------------------------------- | ----------- | ---- | ---- | ------------------------------------------------------------ |
| deviceId                                 | string      | Yes  | Yes  | Address of the BLE device to filter, for example, XX:XX:XX:XX:XX:XX.          |
| name                                     | string      | Yes  | Yes  | Name of the BLE device to filter.                                       |
| serviceUuid                              | string      | Yes  | Yes  | Service UUID of the device to filter, for example, **00001888-0000-1000-8000-00805f9b34fb**.|
| serviceUuidMask             | string      | Yes  | Yes  | Service UUID mask of the device to filter, for example, **FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF**.|
| serviceSolicitationUuid     | string      | Yes  | Yes  | Service solicitation UUID of the device to filter, for example, **00001888-0000-1000-8000-00805F9B34FB**.|
| serviceSolicitationUuidMask | string      | Yes  | Yes  | Service solicitation UUID mask of the device to filter, for example, **FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF**.|
| serviceData                 | ArrayBuffer | Yes  | Yes  | Service data of the device to filter, for example, **[0x90, 0x00, 0xF1, 0xF2]**.|
| serviceDataMask             | ArrayBuffer | Yes  | Yes  | Service data mask of the device to filter, for example, **[0xFF,0xFF,0xFF,0xFF]**.|
| manufactureId               | number      | Yes  | Yes  | Manufacturer ID of the device to filter, for example, **0x0006**.                |
| manufactureData             | ArrayBuffer | Yes  | Yes  | Manufacturer data of the device to filter, for example, **[0x1F,0x2F,0x3F]**.|
| manufactureDataMask         | ArrayBuffer | Yes  | Yes  | Manufacturer data mask of the device to filter, for example, **[0xFF, 0xFF, 0xFF]**.|


## ScanOptions<sup>(deprecated)</sup>

Defines the scan configuration parameters.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.ScanOptions](js-apis-bluetooth-ble.md#scanoptions) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name       | Type                   | Readable  | Writable  | Description                                    |
| --------- | ----------------------- | ---- | ---- | -------------------------------------- |
| interval  | number                  | Yes   | Yes   | Delay in reporting the scan result. The default value is **0**.                   |
| dutyMode  | [ScanDuty](#scandutydeprecated)   | Yes   | Yes   | Scan duty. The default value is SCAN_MODE_LOW_POWER.       |
| matchMode | [MatchMode](#matchmodedeprecated) | Yes   | Yes   | Hardware filtering match mode. The default value is **MATCH_MODE_AGGRESSIVE**.|


## ScanDuty<sup>(deprecated)</sup>

Enumerates the scan duty options.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.ScanDuty](js-apis-bluetooth-ble.md#scanduty) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                   | Value | Description          |
| --------------------- | ---- | ------------ |
| SCAN_MODE_LOW_POWER   | 0    | Low-power mode, which is the default value.|
| SCAN_MODE_BALANCED    | 1    | Balanced mode.     |
| SCAN_MODE_LOW_LATENCY | 2    | Low-latency mode.    |


## MatchMode<sup>(deprecated)</sup>

Enumerates the hardware match modes of BLE scan filters.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.MatchMode](js-apis-bluetooth-ble.md#matchmode) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                   | Value | Description                                      |
| --------------------- | ---- | ---------------------------------------- |
| MATCH_MODE_AGGRESSIVE | 1    | Hardware reports the scan result with a lower threshold of signal strength and few number of matches in a duration. This is the default value.|
| MATCH_MODE_STICKY     | 2    | Hardware reports the scan result with a higher threshold of signal strength and sightings.      |


## ScanResult<sup>(deprecated)</sup>

Defines the scan result.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.ScanResult](js-apis-bluetooth-ble.md#scanresult) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type       | Readable  | Writable  | Description                                |
| -------- | ----------- | ---- | ---- | ---------------------------------- |
| deviceId | string      | Yes   | No   | Address of the scanned device, for example, XX:XX:XX:XX:XX:XX.|
| rssi     | number      | Yes   | No   | RSSI of the device.                   |
| data     | ArrayBuffer | Yes   | No   | Advertisement packets sent by the device.                   |


## BluetoothState<sup>(deprecated)</sup>

Enumerates the Bluetooth states.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [access.BluetoothState](js-apis-bluetooth-access.md#bluetoothstate) instead.

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


## AdvertiseSetting<sup>(deprecated)</sup>

Defines the BLE advertising parameters.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.AdvertiseSetting](js-apis-bluetooth-ble.md#advertisesetting) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name         | Type   | Readable  | Writable  | Description                                      |
| ----------- | ------- | ---- | ---- | ---------------------------------------- |
| interval    | number  | Yes   | Yes   | Interval for BLE advertising. The minimum value is **32** slots (20 ms). The maximum value is **16384** slots. The default value is **1600** slots (1s).|
| txPower     | number  | Yes   | Yes   | Transmit power, in dBm. The value range is -127 to 1. The default value is **-7**.  |
| connectable | boolean | Yes   | Yes   | Whether the advertisement is connectable. The default value is **true**.                  |


## AdvertiseData<sup>(deprecated)</sup>

Defines the content of a BLE advertisement packet.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.AdvertiseData](js-apis-bluetooth-ble.md#advertisedata) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name             | Type                                    | Readable  | Writable  | Description                         |
| --------------- | ---------------------------------------- | ---- | ---- | --------------------------- |
| serviceUuids    | Array&lt;string&gt;                      | Yes   | Yes   | List of service UUIDs to broadcast.|
| manufactureData | Array&lt;[ManufactureData](#manufacturedatadeprecated)&gt; | Yes   | Yes   | List of manufacturers to broadcast.          |
| serviceData     | Array&lt;[ServiceData](#servicedatadeprecated)&gt; | Yes   | Yes   | List of service data to broadcast.              |


## ManufactureData<sup>(deprecated)</sup>

Defines the content of a BLE advertisement packet.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.ManufactureData](js-apis-bluetooth-ble.md#manufacturedata) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name              | Type               | Readable  | Writable  | Description                |
| ---------------- | ------------------- | ---- | ---- | ------------------ |
| manufactureId    | number  | Yes   | Yes   | Manufacturer ID allocated by the Bluetooth SIG.|
| manufactureValue | ArrayBuffer         | Yes   | Yes   | Manufacturer data.    |


## ServiceData<sup>(deprecated)</sup>

Defines the service data contained in an advertisement packet.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [ble.ServiceData](js-apis-bluetooth-ble.md#servicedata) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name          | Type       | Readable  | Writable  | Description        |
| ------------ | ----------- | ---- | ---- | ---------- |
| serviceUuid  | string      | Yes   | Yes   | Service UUID.|
| serviceValue | ArrayBuffer | Yes   | Yes   | Service data.   |


## PinRequiredParam<sup>(deprecated)</sup>

Defines the pairing request parameters.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.PinRequiredParam](js-apis-bluetooth-connection.md#pinrequiredparam) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type  | Readable  | Writable  | Description         |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId | string | Yes   | No   | ID of the device to pair.|
| pinCode  | string | Yes   | No   | Key for the device pairing.  |


## BondStateParam<sup>(deprecated)</sup>

Defines the pairing state parameters.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.BondStateParam](js-apis-bluetooth-connection.md#bondstateparam) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type  | Readable  | Writable  | Description         |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId | string      | Yes   | No   | ID of the device to pair.|
| state    | BondState   | Yes   | No   | State of the device.|


## StateChangeParam<sup>(deprecated)</sup>

Defines the profile state change parameters.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [baseProfile.StateChangeParam](js-apis-bluetooth-baseProfile.md#statechangeparam) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name    | Type                                         | Readable| Writable| Description                           |
| -------- | ------------------------------------------------- | ---- | ---- | ------------------------------- |
| deviceId | string                                            | Yes  | No  | Address of a Bluetooth device.             |
| state    | [ProfileConnectionState](#profileconnectionstatedeprecated) | Yes  | No  | Profile connection state of the device.|


## DeviceClass<sup>(deprecated)</sup>

Defines the class of a Bluetooth device.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [connection.DeviceClass](js-apis-bluetooth-connection.md#deviceclass) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name             | Type                               | Readable  | Writable  | Description              |
| --------------- | ----------------------------------- | ---- | ---- | ---------------- |
| majorClass      | [MajorClass](#majorclassdeprecated)           | Yes   | No   | Major classes of Bluetooth devices.  |
| majorMinorClass | [MajorMinorClass](#majorminorclassdeprecated) | Yes   | No   | Major and minor classes of Bluetooth devices.|
| classOfDevice   | number                              | Yes   | No   | Class of the device.         |


## MajorClass<sup>(deprecated)</sup>

Enumerates the major classes of Bluetooth devices.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [constant.MajorClass](js-apis-bluetooth-constant.md#majorclass) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                 | Value   | Description        |
| ------------------- | ------ | ---------- |
| MAJOR_MISC          | 0x0000 | Miscellaneous device.   |
| MAJOR_COMPUTER      | 0x0100 | Computer.  |
| MAJOR_PHONE         | 0x0200 | Mobile phone.   |
| MAJOR_NETWORKING    | 0x0300 | Network device.   |
| MAJOR_AUDIO_VIDEO   | 0x0400 | Audio or video device.|
| MAJOR_PERIPHERAL    | 0x0500 | Peripheral device.   |
| MAJOR_IMAGING       | 0x0600 | Imaging device.   |
| MAJOR_WEARABLE      | 0x0700 | Wearable device.  |
| MAJOR_TOY           | 0x0800 | Toy.   |
| MAJOR_HEALTH        | 0x0900 | Health device.   |
| MAJOR_UNCATEGORIZED | 0x1F00 | Unclassified device.  |


## MajorMinorClass<sup>(deprecated)</sup>

Enumerates the major and minor classes of Bluetooth devices.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [constant.MajorMinorClass](js-apis-bluetooth-constant.md#majorminorclass) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                                      | Value   | Description             |
| ---------------------------------------- | ------ | --------------- |
| COMPUTER_UNCATEGORIZED                   | 0x0100 | Unclassified computer.    |
| COMPUTER_DESKTOP                         | 0x0104 | Desktop computer.     |
| COMPUTER_SERVER                          | 0x0108 | Server.       |
| COMPUTER_LAPTOP                          | 0x010C | Laptop.    |
| COMPUTER_HANDHELD_PC_PDA                 | 0x0110 | Hand-held computer.    |
| COMPUTER_PALM_SIZE_PC_PDA                | 0x0114 | Palmtop computer.      |
| COMPUTER_WEARABLE                        | 0x0118 | Wearable computer.    |
| COMPUTER_TABLET                          | 0x011C | Tablet.      |
| PHONE_UNCATEGORIZED                      | 0x0200 | Unclassified mobile phone.     |
| PHONE_CELLULAR                           | 0x0204 | Portable phone.     |
| PHONE_CORDLESS                           | 0x0208 | Cordless phone.      |
| PHONE_SMART                              | 0x020C | Smartphone.      |
| PHONE_MODEM_OR_GATEWAY                   | 0x0210 | Modem or gateway phone.|
| PHONE_ISDN                               | 0x0214 | ISDN phone.    |
| NETWORK_FULLY_AVAILABLE                  | 0x0300 | Device with network fully available.    |
| NETWORK_1_TO_17_UTILIZED                 | 0x0320 | Device used on network 1 to 17.  |
| NETWORK_17_TO_33_UTILIZED                | 0x0340 | Device used on network 17 to 33. |
| NETWORK_33_TO_50_UTILIZED                | 0x0360 | Device used on network 33 to 50. |
| NETWORK_60_TO_67_UTILIZED                | 0x0380 | Device used on network 60 to 67. |
| NETWORK_67_TO_83_UTILIZED                | 0x03A0 | Device used on network 67 to 83. |
| NETWORK_83_TO_99_UTILIZED                | 0x03C0 | Device used on network 83 to 99. |
| NETWORK_NO_SERVICE                       | 0x03E0 | Device without network service     |
| AUDIO_VIDEO_UNCATEGORIZED                | 0x0400 | Unclassified audio or video device.   |
| AUDIO_VIDEO_WEARABLE_HEADSET             | 0x0404 | Wearable audio or video headset.  |
| AUDIO_VIDEO_HANDSFREE                    | 0x0408 | Hands-free audio or video device.    |
| AUDIO_VIDEO_MICROPHONE                   | 0x0410 | Audio or video microphone.   |
| AUDIO_VIDEO_LOUDSPEAKER                  | 0x0414 | Audio or video loudspeaker.   |
| AUDIO_VIDEO_HEADPHONES                   | 0x0418 | Audio or video headphones.   |
| AUDIO_VIDEO_PORTABLE_AUDIO               | 0x041C | Portable audio or video device.   |
| AUDIO_VIDEO_CAR_AUDIO                    | 0x0420 | In-vehicle audio or video device.    |
| AUDIO_VIDEO_SET_TOP_BOX                  | 0x0424 | Audio or video STB device.   |
| AUDIO_VIDEO_HIFI_AUDIO                   | 0x0428 | High-fidelity speaker device.     |
| AUDIO_VIDEO_VCR                          | 0x042C | Video cassette recording (VCR) device.   |
| AUDIO_VIDEO_VIDEO_CAMERA                 | 0x0430 | Camera.   |
| AUDIO_VIDEO_CAMCORDER                    | 0x0434 | Camcorder   |
| AUDIO_VIDEO_VIDEO_MONITOR                | 0x0438 | Audio or video monitor.   |
| AUDIO_VIDEO_VIDEO_DISPLAY_AND_LOUDSPEAKER | 0x043C | Video display or loudspeaker. |
| AUDIO_VIDEO_VIDEO_CONFERENCING           | 0x0440 | Video conferencing device.    |
| AUDIO_VIDEO_VIDEO_GAMING_TOY             | 0x0448 | Audio or video gaming toy.  |
| PERIPHERAL_NON_KEYBOARD_NON_POINTING     | 0x0500 | Non-keyboard or non-pointing peripheral device.  |
| PERIPHERAL_KEYBOARD                      | 0x0540 | Keyboard device.      |
| PERIPHERAL_POINTING_DEVICE               | 0x0580 | Pointing peripheral device.    |
| PERIPHERAL_KEYBOARD_POINTING             | 0x05C0 | Keyboard pointing device.    |
| PERIPHERAL_UNCATEGORIZED                 | 0x0500 | Unclassified peripheral device.     |
| PERIPHERAL_JOYSTICK                      | 0x0504 | Peripheral joystick.     |
| PERIPHERAL_GAMEPAD                       | 0x0508 | Peripheral game pad     |
| PERIPHERAL_REMOTE_CONTROL                | 0x05C0 | Peripheral remote control device    |
| PERIPHERAL_SENSING_DEVICE                | 0x0510 | Peripheral sensing device.    |
| PERIPHERAL_DIGITIZER_TABLET              | 0x0514 | Peripheral digitizer tablet.|
| PERIPHERAL_CARD_READER                   | 0x0518 | Peripheral card reader.     |
| PERIPHERAL_DIGITAL_PEN                   | 0x051C | Peripheral digital pen.     |
| PERIPHERAL_SCANNER_RFID                  | 0x0520 | Peripheral RFID scanner. |
| PERIPHERAL_GESTURAL_INPUT                | 0x0522 | Gesture input device.    |
| IMAGING_UNCATEGORIZED                    | 0x0600 | Unclassified imaging device.    |
| IMAGING_DISPLAY                          | 0x0610 | Imaging display device.      |
| IMAGING_CAMERA                           | 0x0620 | Imaging camera device.     |
| IMAGING_SCANNER                          | 0x0640 | Imaging scanner.     |
| IMAGING_PRINTER                          | 0x0680 | Imaging printer.     |
| WEARABLE_UNCATEGORIZED                   | 0x0700 | Unclassified wearable device.   |
| WEARABLE_WRIST_WATCH                     | 0x0704 | Smart watch.     |
| WEARABLE_PAGER                           | 0x0708 | Wearable pager.    |
| WEARABLE_JACKET                          | 0x070C | Smart jacket.     |
| WEARABLE_HELMET                          | 0x0710 | Wearable helmet.     |
| WEARABLE_GLASSES                         | 0x0714 | Wearable glasses.     |
| TOY_UNCATEGORIZED                        | 0x0800 | Unclassified toy.    |
| TOY_ROBOT                                | 0x0804 | Toy robot.     |
| TOY_VEHICLE                              | 0x0808 | Toy vehicle.       |
| TOY_DOLL_ACTION_FIGURE                   | 0x080C | Humanoid toy doll.    |
| TOY_CONTROLLER                           | 0x0810 | Toy controller.     |
| TOY_GAME                                 | 0x0814 | Toy gaming device.      |
| HEALTH_UNCATEGORIZED                     | 0x0900 | Unclassified health devices.     |
| HEALTH_BLOOD_PRESSURE                    | 0x0904 | Blood pressure device.      |
| HEALTH_THERMOMETER                       | 0x0908 | Thermometer     |
| HEALTH_WEIGHING                          | 0x090C | Body scale.      |
| HEALTH_GLUCOSE                           | 0x0910 | Blood glucose monitor.     |
| HEALTH_PULSE_OXIMETER                    | 0x0914 | Pulse oximeter.   |
| HEALTH_PULSE_RATE                        | 0x0918 | Heart rate monitor.     |
| HEALTH_DATA_DISPLAY                      | 0x091C | Health data display.    |
| HEALTH_STEP_COUNTER                      | 0x0920 | Step counter.   |
| HEALTH_BODY_COMPOSITION_ANALYZER         | 0x0924 | Body composition analyzer. |
| HEALTH_PEAK_FLOW_MONITOR                  | 0x0928 | Hygrometer.     |
| HEALTH_MEDICATION_MONITOR                | 0x092C | Medication monitor.   |
| HEALTH_KNEE_PROSTHESIS                   | 0x0930 | Prosthetic knee.    |
| HEALTH_ANKLE_PROSTHESIS                  | 0x0934 | Prosthetic ankle.    |
| HEALTH_GENERIC_HEALTH_MANAGER            | 0x0938 | Generic health management device.    |
| HEALTH_PERSONAL_MOBILITY_DEVICE          | 0x093C | Personal mobility device.    |


## PlayingState<sup>(deprecated)</sup>

Enumerates the A2DP playing states.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [a2dp.PlayingState](js-apis-bluetooth-a2dp.md#playingstate) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Value   | Description     |
| ----------------- | ------ | ------- |
| STATE_NOT_PLAYING | 0x0000 | Not playing. |
| STATE_PLAYING     | 0x0001 | Playing.|


## ProfileId<sup>(deprecated)</sup>

Enumerates the Bluetooth profiles. API version 9 is added with **PROFILE_HID_HOST** and **PROFILE_PAN_NETWORK**.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [constant.ProfileId](js-apis-bluetooth-constant.md#profileid) instead.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                              | Value   | Description             |
| -------------------------------- | ------ | --------------- |
| PROFILE_A2DP_SOURCE              | 1 | A2DP profile.|
| PROFILE_HANDS_FREE_AUDIO_GATEWAY | 4 | HFP profile. |
| PROFILE_HID_HOST | 6 | Human Interface Device (HID) profile. |
| PROFILE_PAN_NETWORK | 7 | PAN profile. |
