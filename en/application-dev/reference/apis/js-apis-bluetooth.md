# @ohos.bluetooth (Bluetooth)

The **Bluetooth** module provides classic Bluetooth capabilities and Bluetooth Low Energy (BLE) scan and advertising.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are no longer maintained since API version 9. You are advised to use [bluetoothManager](js-apis-bluetoothManager.md).



## Modules to Import

```js
import bluetooth from '@ohos.bluetooth';
```


## bluetooth.enableBluetooth<sup>8+</sup><sup>(deprecated)</sup><a name="enableBluetooth"></a>

enableBluetooth(): boolean

Enables Bluetooth.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.enableBluetooth](js-apis-bluetoothManager.md#bluetoothmanagerenablebluetooth).

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type     | Description                      |
| ------- | ------------------------ |
| boolean | Returns **true** if Bluetooth is enabled; returns **false** otherwise.|

**Example**

```js
let enable = bluetooth.enableBluetooth();
```


## bluetooth.disableBluetooth<sup>8+</sup><sup>(deprecated)</sup><a name="disableBluetooth"></a>

disableBluetooth(): boolean

Disables Bluetooth.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.disableBluetooth](js-apis-bluetoothManager.md#bluetoothmanagerdisablebluetooth).

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type     | Description                      |
| ------- | ------------------------ |
| boolean | Returns **true** if Bluetooth is disabled; returns **false** otherwise.|

**Example**

```js
let disable = bluetooth.disableBluetooth();
```


## bluetooth.getLocalName<sup>8+</sup><sup>(deprecated)</sup><a name="getLocalName"></a>

getLocalName(): string

Obtains the name of the local Bluetooth device.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.getLocalName](js-apis-bluetoothManager.md#bluetoothmanagergetlocalname).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type    | Description       |
| ------ | --------- |
| string | Name of the local Bluetooth device obtained.|

**Example**

```js
let localName = bluetooth.getLocalName();
```


## bluetooth.getState<sup>(deprecated)</sup><a name="getState"></a>

getState(): BluetoothState

Obtains the Bluetooth state.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.getState](js-apis-bluetoothManager.md#bluetoothmanagergetstate).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                               | Description       |
| --------------------------------- | --------- |
| [BluetoothState](#bluetoothstate) | Bluetooth state obtained.|

**Example**

```js
let state = bluetooth.getState();
```


## bluetooth.getBtConnectionState<sup>(deprecated)</sup><a name="getBtConnectionState"></a>

getBtConnectionState(): ProfileConnectionState

Obtains the local profile connection state.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.getBtConnectionState](js-apis-bluetoothManager.md#bluetoothmanagergetbtconnectionstate).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                                      | Description                 |
| ---------------------------------------- | ------------------- |
| [ProfileConnectionState](#profileconnectionstate) | Profile connection state obtained.|

**Example**

```js
let connectionState = bluetooth.getBtConnectionState();
```


## bluetooth.setLocalName<sup>8+</sup><sup>(deprecated)</sup><a name="setLocalName"></a>

setLocalName(name: string): boolean

Sets the name of the local Bluetooth device.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.setLocalName](js-apis-bluetoothManager.md#bluetoothmanagersetlocalname).

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name | Type    | Mandatory  | Description                   |
| ---- | ------ | ---- | --------------------- |
| name | string | Yes   | Bluetooth device name to set. It cannot exceed 248 bytes.|

**Return value**

| Type     | Description                            |
| ------- | ------------------------------ |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let ret = bluetooth.setLocalName('device_name');
```


## bluetooth.pairDevice<sup>(deprecated)</sup><a name="pairDevice"></a>

pairDevice(deviceId: string): boolean

Initiates Bluetooth pairing.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.pairDevice](js-apis-bluetoothManager.md#bluetoothmanagerpairdevice).

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the remote device to pair, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type     | Description                        |
| ------- | -------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
// The address can be scanned.
let result = bluetooth.pairDevice("XX:XX:XX:XX:XX:XX");
```


## bluetooth.getProfileConnState<sup>8+</sup><sup>(deprecated)</sup><a name="getProfileConnState"></a>

getProfileConnState(profileId: ProfileId): ProfileConnectionState

Obtains the connection status of a specified profile.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.getProfileConnectionState](js-apis-bluetoothManager.md#bluetoothmanagergetprofileconnectionstate).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name      | Type       | Mandatory  | Description                                   |
| --------- | --------- | ---- | ------------------------------------- |
| ProfileId | profileId | Yes   | ID of the profile to obtain, for example, **PROFILE_A2DP_SOURCE**.|

**Return value**

| Type                                             | Description               |
| ------------------------------------------------- | ------------------- |
| [ProfileConnectionState](#profileconnectionstate) | Profile connection state obtained.|

**Example**

```js
let result = bluetooth.getProfileConnState(bluetooth.ProfileId.PROFILE_A2DP_SOURCE);
```


## bluetooth.cancelPairedDevice<sup>8+</sup><sup>(deprecated)</sup><a name="cancelPairedDevice"></a>

cancelPairedDevice(deviceId: string): boolean

Cancels a paired remote device.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.cancelPairedDevice](js-apis-bluetoothManager.md#bluetoothmanagercancelpaireddevice).

**System API**: This is a system API.

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                   |
| -------- | ------ | ---- | ------------------------------------- |
| deviceId | string | Yes   | Address of the remote device to cancel, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type     | Description                        |
| ------- | -------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let result = bluetooth.cancelPairedDevice("XX:XX:XX:XX:XX:XX");
```


## bluetooth.getRemoteDeviceName<sup>8+</sup><sup>(deprecated)</sup><a name="getRemoteDeviceName"></a>

getRemoteDeviceName(deviceId: string): string

Obtains the name of the remote Bluetooth device.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.getRemoteDeviceName](js-apis-bluetoothManager.md#bluetoothmanagergetremotedevicename).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                               |
| -------- | ------ | ---- | --------------------------------- |
| deviceId | string | Yes   | Address of the target remote device, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Device name (a string) obtained.|

**Example**

```js
let remoteDeviceName = bluetooth.getRemoteDeviceName("XX:XX:XX:XX:XX:XX");
```


## bluetooth.getRemoteDeviceClass<sup>8+</sup><sup>(deprecated)</sup><a name="getRemoteDeviceClass"></a>

getRemoteDeviceClass(deviceId: string): DeviceClass

Obtains the class of the remote Bluetooth device.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.getRemoteDeviceClass](js-apis-bluetoothManager.md#bluetoothmanagergetremotedeviceclass).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                               |
| -------- | ------ | ---- | --------------------------------- |
| deviceId | string | Yes   | Address of the target remote device, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type                         | Description      |
| --------------------------- | -------- |
| [DeviceClass](#deviceclass) | Class of the remote device obtained.|

**Example**

```js
let remoteDeviceClass = bluetooth.getRemoteDeviceClass("XX:XX:XX:XX:XX:XX");
```


## bluetooth.getPairedDevices<sup>8+</sup><sup>(deprecated)</sup><a name="getPairedDevices"></a>

getPairedDevices(): Array&lt;string&gt;

Obtains the paired devices.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.getPairedDevices](js-apis-bluetoothManager.md#bluetoothmanagergetpaireddevices).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
| Array&lt;string&gt; | Addresses of the paired Bluetooth devices.|

**Example**

```js
let devices = bluetooth.getPairedDevices();
```


## bluetooth.setBluetoothScanMode<sup>8+</sup><sup>(deprecated)</sup><a name="setBluetoothScanMode"></a>

setBluetoothScanMode(mode: ScanMode, duration: number): boolean

Sets the Bluetooth scan mode so that the device can be discovered by a remote device.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.setBluetoothScanMode](js-apis-bluetoothManager.md#bluetoothmanagersetbluetoothscanmode).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                   | Mandatory  | Description                          |
| -------- | --------------------- | ---- | ---------------------------- |
| mode     | [ScanMode](#scanmode) | Yes   | Bluetooth scan mode to set.                     |
| duration | number                | Yes   | Duration (in ms) in which the device can be discovered. The value **0** indicates unlimited time.|

**Return value**

| Type     | Description                        |
| ------- | -------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
// The device can be discovered and connected only when the discoverable and connectable mode is used.
let result = bluetooth.setBluetoothScanMode(bluetooth.ScanMode.SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE, 100);
```


## bluetooth.getBluetoothScanMode<sup>8+</sup><sup>(deprecated)</sup><a name="getBluetoothScanMode"></a>

getBluetoothScanMode(): ScanMode

Obtains the Bluetooth scan mode.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.getBluetoothScanMode](js-apis-bluetoothManager.md#bluetoothmanagergetbluetoothscanmode).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                   | Description     |
| --------------------- | ------- |
| [ScanMode](#scanmode) | Bluetooth scan mode obtained.|

**Example**

```js
let scanMode = bluetooth.getBluetoothScanMode();
```


## bluetooth.startBluetoothDiscovery<sup>8+</sup><sup>(deprecated)</sup><a name="startBluetoothDiscovery"></a>

startBluetoothDiscovery(): boolean

Starts Bluetooth scan to discover remote devices.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.startBluetoothDiscovery](js-apis-bluetoothManager.md#bluetoothmanagerstartbluetoothdiscovery).

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type     | Description                        |
| ------- | -------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let deviceId;
function onReceiveEvent(data) {
    deviceId = data;
}
bluetooth.on('bluetoothDeviceFind', onReceiveEvent);
let result = bluetooth.startBluetoothDiscovery();
```


## bluetooth.stopBluetoothDiscovery<sup>8+</sup><sup>(deprecated)</sup><a name="stopBluetoothDiscovery"></a>

stopBluetoothDiscovery(): boolean

Stops Bluetooth scan.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.stopBluetoothDiscovery](js-apis-bluetoothManager.md#bluetoothmanagerstopbluetoothdiscovery).

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type     | Description                        |
| ------- | -------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let result = bluetooth.stopBluetoothDiscovery();
```


## bluetooth.setDevicePairingConfirmation<sup>8+</sup><sup>(deprecated)</sup><a name="setDevicePairingConfirmation"></a>

setDevicePairingConfirmation(device: string, accept: boolean): boolean

Sets the device pairing confirmation.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.setDevicePairingConfirmation](js-apis-bluetoothManager.md#bluetoothmanagersetdevicepairingconfirmation).

**Required permissions**: ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type     | Mandatory  | Description                              |
| ------ | ------- | ---- | -------------------------------- |
| device | string  | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|
| accept | boolean | Yes   | Whether to accept the pairing request. The value **true** means to accept the pairing request, and the value **false** means the opposite.       |

**Return value**

| Type     | Description                          |
| ------- | ---------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
// Subscribe to the pinRequired event and configure the pairing confirmation after receiving a pairing request from the remote device.
function onReceivePinRequiredEvent(data) { // data is the input parameter for the pairing request.
    console.info('pin required  = '+ JSON.stringify(data));
    bluetooth.setDevicePairingConfirmation(data.deviceId, true);
}
bluetooth.on("pinRequired", onReceivePinRequiredEvent);
```


## bluetooth.on('bluetoothDeviceFind')<sup>8+</sup><sup>(deprecated)</sup><a name="bluetoothDeviceFind"></a>

on(type: "bluetoothDeviceFind", callback: Callback&lt;Array&lt;string&gt;&gt;): void

Subscribes to the Bluetooth device discovery events.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.on('bluetoothDeviceFind')](js-apis-bluetoothManager.md#bluetoothmanageronbluetoothdevicefind).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                 | Mandatory  | Description                                    |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| type     | string                              | Yes   | Event type. The value **bluetoothDeviceFind** indicates an event reported when a Bluetooth device is discovered.|
| callback | Callback&lt;Array&lt;string&gt;&gt; | Yes   | Callback invoked to return the discovered devices. You need to implement this callback.   |

**Return value**

No value is returned.

**Example**

```js
function onReceiveEvent(data) { // data is a set of Bluetooth device addresses.
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
bluetooth.on('bluetoothDeviceFind', onReceiveEvent);
```


## bluetooth.off('bluetoothDeviceFind')<sup>8+</sup><sup>(deprecated)</sup>

off(type: "bluetoothDeviceFind", callback?: Callback&lt;Array&lt;string&gt;&gt;): void

Unsubscribes from the Bluetooth device discovery events.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.off('bluetoothDeviceFind')](js-apis-bluetoothManager.md#bluetoothmanageroffbluetoothdevicefind).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                 | Mandatory  | Description                                      |
| -------- | ----------------------------------- | ---- | ---------------------------------------- |
| type     | string                              | Yes   | Event type. The value **bluetoothDeviceFind** indicates an event reported when a Bluetooth device is discovered.  |
| callback | Callback&lt;Array&lt;string&gt;&gt; | No   | Callback for the **bluetoothDeviceFind** event. If this parameter is not set, this method unsubscribes from all callbacks corresponding to **type**.|

**Return value**

No value is returned.

**Example**

```js
function onReceiveEvent(data) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
bluetooth.on('bluetoothDeviceFind', onReceiveEvent);
bluetooth.off('bluetoothDeviceFind', onReceiveEvent);
```


## bluetooth.on('pinRequired')<sup>8+</sup><sup>(deprecated)</sup>

on(type: "pinRequired", callback: Callback&lt;PinRequiredParam&gt;): void

Subscribes to the pairing request events of the remote Bluetooth device.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.on('pinRequired')](js-apis-bluetoothManager.md#bluetoothmanageronpinrequired).

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                              |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| type     | string                                   | Yes   | Event type. The value **pinRequired** indicates a pairing request event.    |
| callback | Callback&lt;[PinRequiredParam](#pinrequiredparam)&gt; | Yes   | Callback invoked to return the pairing request. You need to implement this callback.|

**Return value**

No value is returned.

**Example**

```js
function onReceiveEvent(data) { // data is the pairing request parameter.
    console.info('pin required = '+ JSON.stringify(data));
}
bluetooth.on('pinRequired', onReceiveEvent);
```


## bluetooth.off('pinRequired')<sup>8+</sup><sup>(deprecated)</sup>

off(type: "pinRequired", callback?: Callback&lt;PinRequiredParam&gt;): void

Unsubscribes from the pairing request events of the remote Bluetooth device.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.off('pinRequired')](js-apis-bluetoothManager.md#bluetoothmanageroffpinrequired).

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **pinRequired** indicates a pairing request event.            |
| callback | Callback&lt;[PinRequiredParam](#pinrequiredparam)&gt; | No   | Callback for the Bluetooth pairing request event. The input parameter is the pairing request parameter. If this parameter is not set, this method unsubscribes from all callbacks corresponding to **type**.|

**Return value**

No value is returned.

**Example**

```js
function onReceiveEvent(data) {
    console.info('pin required = '+ JSON.stringify(data));
}
bluetooth.on('pinRequired', onReceiveEvent);
bluetooth.off('pinRequired', onReceiveEvent);
```


## bluetooth.on('bondStateChange')<sup>8+</sup><sup>(deprecated)</sup>

on(type: "bondStateChange", callback: Callback&lt;BondStateParam&gt;): void

Subscribes to the Bluetooth pairing state change events.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.on('bondStateChange')](js-apis-bluetoothManager.md#bluetoothmanageronbondstatechange).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                  |
| -------- | ---------------------------------------- | ---- | ------------------------------------ |
| type     | string                                   | Yes   | Event type. The value **bondStateChange** indicates a Bluetooth pairing state change event.|
| callback | Callback&lt;[BondStateParam](#BondStateParam)&gt; | Yes   | Callback invoked to return the pairing state. You need to implement this callback.   |

**Return value**

No value is returned.

**Example**

```js
function onReceiveEvent(data) { // data, as the input parameter of the callback, indicates the pairing state.
    console.info('pair state = '+ JSON.stringify(data));
}
bluetooth.on('bondStateChange', onReceiveEvent);
```


## bluetooth.off('bondStateChange')<sup>8+</sup><sup>(deprecated)</sup>

off(type: "bondStateChange", callback?: Callback&lt;BondStateParam&gt;): void

Unsubscribes from the Bluetooth pairing state change events.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.off('bondStateChange')](js-apis-bluetoothManager.md#bluetoothmanageroffbondstatechange).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **bondStateChange** indicates a Bluetooth pairing state change event.    |
| callback | Callback&lt;[BondStateParam](#BondStateParam)&gt; | No   | Callback for the change of the Bluetooth pairing state. If this parameter is not set, this method unsubscribes from all callbacks corresponding to **type**.|

**Return value**

No value is returned.

**Example**

```js
function onReceiveEvent(data) {
    console.info('bond state = '+ JSON.stringify(data));
}
bluetooth.on('bondStateChange', onReceiveEvent);
bluetooth.off('bondStateChange', onReceiveEvent);
```


## bluetooth.on('stateChange')<sup>8+</sup><sup>(deprecated)</sup>

on(type: "stateChange", callback: Callback&lt;BluetoothState&gt;): void

Subscribes to the Bluetooth connection state change events.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.on('stateChange')](js-apis-bluetoothManager.md#bluetoothmanageronstatechange).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                              |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| type     | string                                   | Yes   | Event type. The value **stateChange** indicates a Bluetooth connection state change event.  |
| callback | Callback&lt;[BluetoothState](#bluetoothstate)&gt; | Yes   | Callback invoked to return the Bluetooth connection state. You need to implement this callback.|

**Return value**

No value is returned.

**Example**

```js
function onReceiveEvent(data) {
    console.info('bluetooth state = '+ JSON.stringify(data));
}
bluetooth.on('stateChange', onReceiveEvent);
```


## bluetooth.off('stateChange')<sup>8+</sup><sup>(deprecated)</sup>

off(type: "stateChange", callback?: Callback&lt;BluetoothState&gt;): void

Unsubscribes from the Bluetooth connection state change events.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.off('stateChange')](js-apis-bluetoothManager.md#bluetoothmanageroffstatechange).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **stateChange** indicates a Bluetooth connection state change event.          |
| callback | Callback&lt;[BluetoothState](#bluetoothstate)&gt; | No   | Callback for the Bluetooth connection state change event. If this parameter is not set, this method unsubscribes from all callbacks corresponding to **type**.|

**Return value**

No value is returned.

**Example**

```js
function onReceiveEvent(data) {
    console.info('bluetooth state = '+ JSON.stringify(data));
}
bluetooth.on('stateChange', onReceiveEvent);
bluetooth.off('stateChange', onReceiveEvent);
```


## bluetooth.sppListen<sup>8+</sup><sup>(deprecated)</sup><a name="sppListen"></a>

sppListen(name: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void

Creates a server listening socket.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.sppListen](js-apis-bluetoothManager.md#bluetoothmanagerspplisten).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                     |
| -------- | --------------------------- | ---- | ----------------------- |
| name     | string                      | Yes   | Name of the service.                 |
| option   | [SppOption](#sppoption)     | Yes   | Serial port profile (SPP) listening configuration.             |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback invoked to return the server socket ID.|

**Example**

```js
let serverNumber = -1;
function serverSocket(code, number) {
  console.log('bluetooth error code: ' + code.code);
  if (code.code == 0) {
    console.log('bluetooth serverSocket Number: ' + number);
    serverNumber = number;
  }
}

let sppOption = {uuid: '00001810-0000-1000-8000-00805F9B34FB', secure: false, type: 0};
bluetooth.sppListen('server1', sppOption, serverSocket);
```


## bluetooth.sppAccept<sup>8+</sup><sup>(deprecated)</sup><a name="sppAccept"></a>

sppAccept(serverSocket: number, callback: AsyncCallback&lt;number&gt;): void

Listens for a connection to be made to this socket from the client and accepts it.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.sppAccept](js-apis-bluetoothManager.md#bluetoothmanagersppaccept).

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                     |
| ------------ | --------------------------- | ---- | ----------------------- |
| serverSocket | number                      | Yes   | Server socket ID.          |
| callback     | AsyncCallback&lt;number&gt; | Yes   | Callback invoked to return the client socket ID.|

**Example**

```js
let serverNumber = -1;
function serverSocket(code, number) {
  console.log('bluetooth error code: ' + code.code);
  if (code.code == 0) {
    console.log('bluetooth serverSocket Number: ' + number);
    serverNumber = number;
  }
}
let clientNumber = -1;
function acceptClientSocket(code, number) {
  console.log('bluetooth error code: ' + code.code);
  if (code.code == 0) {
    console.log('bluetooth clientSocket Number: ' + number);
    // The obtained clientNumber is used as the socket ID for subsequent read/write operations on the server.
    clientNumber = number;
  }
}
bluetooth.sppAccept(serverNumber, acceptClientSocket);
```


## bluetooth.sppConnect<sup>8+</sup><sup>(deprecated)</sup><a name="sppConnect"></a>

sppConnect(device: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void

Initiates an SPP connection to a remote device from the client.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.sppConnect](js-apis-bluetoothManager.md#bluetoothmanagersppconnect).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                            |
| -------- | --------------------------- | ---- | ------------------------------ |
| device   | string                      | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|
| option   | [SppOption](#sppoption)     | Yes   | Configuration for connecting to the SPP client.                 |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback invoked to return the client socket ID.       |

**Example**

```js

let clientNumber = -1;
function clientSocket(code, number) {
  if (code.code != 0) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // The obtained clientNumber is used as the socket ID for subsequent read/write operations on the client.
  clientNumber = number;
}
let sppOption = {uuid: '00001810-0000-1000-8000-00805F9B34FB', secure: false, type: 0};
bluetooth.sppConnect('XX:XX:XX:XX:XX:XX', sppOption, clientSocket);
```


## bluetooth.sppCloseServerSocket<sup>8+</sup><sup>(deprecated)</sup><a name="sppCloseServerSocket"></a>

sppCloseServerSocket(socket: number): void

Closes the listening socket of the server.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.sppCloseServerSocket](js-apis-bluetoothManager.md#bluetoothmanagersppcloseserversocket).

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description             |
| ------ | ------ | ---- | --------------- |
| socket | number | Yes   | ID of the listening socket on the server. The ID is obtained by **sppListen**.|

**Example**

```js
let serverNumber = -1;
function serverSocket(code, number) {
  console.log('bluetooth error code: ' + code.code);
  if (code.code == 0) {
    console.log('bluetooth serverSocket Number: ' + number);
    serverNumber = number;
  }
}
bluetooth.sppCloseServerSocket(serverNumber);
```


## bluetooth.sppCloseClientSocket<sup>8+</sup><sup>(deprecated)</sup><a name="sppCloseClientSocket"></a>

sppCloseClientSocket(socket: number): void

Closes the client socket.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.sppCloseClientSocket](js-apis-bluetoothManager.md#bluetoothmanagersppcloseclientsocket).

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description           |
| ------ | ------ | ---- | ------------- |
| Name   | Type    | Mandatory  | Description           |
| socket | number | Yes   | Client socket ID, which is obtained by **sppAccept** or **sppConnect**.|

**Example**

```js
let clientNumber = -1;
function clientSocket(code, number) {
  if (code.code != 0) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // The obtained clientNumber is used as the socket ID for subsequent read/write operations on the client.
  clientNumber = number;
}
bluetooth.sppCloseClientSocket(clientNumber);
```


## bluetooth.sppWrite<sup>8+</sup><sup>(deprecated)</sup><a name="sppWrite"></a>

sppWrite(clientSocket: number, data: ArrayBuffer): boolean

Writes data to the remote device through the socket.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.sppWrite](js-apis-bluetoothManager.md#bluetoothmanagersppwrite).

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type         | Mandatory  | Description           |
| ------------ | ----------- | ---- | ------------- |
| clientSocket | number      | Yes   | Client socket ID, which is obtained by **sppAccept** or **sppConnect**.|
| data         | ArrayBuffer | Yes   | Data to write.       |

**Return value**

| Type     | Description                       |
| ------- | ------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let clientNumber = -1;
function clientSocket(code, number) {
  if (code.code != 0) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // The obtained clientNumber is used as the socket ID for subsequent read/write operations on the client.
  clientNumber = number;
}
let arrayBuffer = new ArrayBuffer(8);
let data = new Uint8Array(arrayBuffer);
data[0] = 123;
let ret = bluetooth.sppWrite(clientNumber, arrayBuffer);
if (ret) {
  console.log('spp write successfully');
} else {
  console.log('spp write failed');
}
```


## bluetooth.on('sppRead')<sup>8+</sup><sup>(deprecated)</sup>

on(type: "sppRead", clientSocket: number, callback: Callback&lt;ArrayBuffer&gt;): void

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.on('sppRead')](js-apis-bluetoothManager.md#bluetoothmanageronsppread).

Subscribes to the SPP read request events.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                        |
| ------------ | --------------------------- | ---- | -------------------------- |
| type         | string                      | Yes   | Event type. The value **sppRead** indicates an SPP read request event.|
| clientSocket | number                      | Yes   | Client socket ID, which is obtained by **sppAccept** or **sppConnect**.             |
| callback     | Callback&lt;ArrayBuffer&gt; | Yes   | Callback invoked to return the data read.         |

**Return value**

No value is returned.

**Example**

```js
let clientNumber = -1;
function clientSocket(code, number) {
  if (code.code != 0) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // The obtained clientNumber is used as the socket ID for subsequent read/write operations on the client.
  clientNumber = number;
}
function dataRead(dataBuffer) {
  let data = new Uint8Array(dataBuffer);
  console.log('bluetooth data is: ' + data[0]);
}
bluetooth.on('sppRead', clientNumber, dataRead);
```


## bluetooth.off('sppRead')<sup>8+</sup><sup>(deprecated)</sup>

off(type: "sppRead", clientSocket: number, callback?: Callback&lt;ArrayBuffer&gt;): void

Unsubscribes from the SPP read request events.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.off('sppRead')](js-apis-bluetoothManager.md#bluetoothmanageroffsppread).

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name         | Type                         | Mandatory  | Description                                      |
| ------------ | --------------------------- | ---- | ---------------------------------------- |
| type         | string                      | Yes   | Event type. The value **sppRead** indicates an SPP read request event.              |
| clientSocket | number                      | Yes   | Client socket ID, which is obtained by **sppAccept** or **sppConnect**.                           |
| callback     | Callback&lt;ArrayBuffer&gt; | No   | Callback for the SPP read request event. If this parameter is not set, this method unsubscribes from all callbacks corresponding to **type**.|

**Return value**

No value is returned.

**Example**

```js
let clientNumber = -1;
function clientSocket(code, number) {
  if (code.code != 0) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // The obtained clientNumber is used as the socket ID for subsequent read/write operations on the client.
  clientNumber = number;
}
bluetooth.off('sppRead', clientNumber);
```


## bluetooth.getProfile<sup>8+</sup><sup>(deprecated)</sup><a name="bt-getProfile"></a>

getProfile(profileId: ProfileId): A2dpSourceProfile | HandsFreeAudioGatewayProfile

Obtains a profile object.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.getProfileInstance](js-apis-bluetoothManager.md#bluetoothmanagergetprofileinstance).

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name      | Type       | Mandatory  | Description                                   |
| --------- | --------- | ---- | ------------------------------------- |
| profileId | [ProfileId](#ProfileId) | Yes   | ID of the profile to obtain, for example, **PROFILE_A2DP_SOURCE**.|

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [A2dpSourceProfile](#a2dpsourceprofile) or [HandsFreeAudioGatewayProfile](#handsfreeaudiogatewayprofile)| Profile object obtained. Only **A2dpSourceProfile** and **HandsFreeAudioGatewayProfile** are supported.|

**Example**

```js
let a2dpSrc = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE);
```


## bluetooth.BLE

### bluetooth.BLE.createGattServer<sup>(deprecated)</sup>

createGattServer(): GattServer

Creates a **GattServer** instance.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.BLE.createGattServer](js-apis-bluetoothManager.md#bluetoothmanagerblecreategattserver).

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                       | Description                                  |
| ------------------------- | ------------------------------------ |
| [GattServer](#gattserver) | **GattServer** instance created. Before using a method of the server, you must create a **GattSever** instance.|

**Example**

```js
let gattServer = bluetooth.BLE.createGattServer();
```


### bluetooth.BLE.createGattClientDevice<sup>(deprecated)</sup>

createGattClientDevice(deviceId: string): GattClientDevice

Creates a **GattClientDevice** instance.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.BLE.createGattClientDevice](js-apis-bluetoothManager.md#bluetoothmanagerblecreategattclientdevice).

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                  |
| -------- | ------ | ---- | ------------------------------------ |
| deviceId | string | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type                                   | Description                                  |
| ------------------------------------- | ------------------------------------ |
| [GattClientDevice](#gattclientdevice) | **GattClientDevice** instance created. Before using a method of the client, you must create a **GattClientDevice** instance.|

**Example**

```js
let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
```


### bluetooth.BLE.getConnectedBLEDevices<sup>(deprecated)</sup>

getConnectedBLEDevices(): Array&lt;string&gt;

Obtains the BLE devices connected to this device.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.BLE.getConnectedBLEDevices](js-apis-bluetoothManager.md#bluetoothmanagerblegetconnectedbledevices).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                 | Description                 |
| ------------------- | ------------------- |
| Array&lt;string&gt; | Addresses of the BLE devices connected to this device.|

**Example**

```js
let result = bluetooth.BLE.getConnectedBLEDevices();
```


### bluetooth.BLE.startBLEScan<sup>(deprecated)</sup>

startBLEScan(filters: Array&lt;ScanFilter&gt;, options?: ScanOptions): void

Starts a BLE scan.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.BLE.startBLEScan](js-apis-bluetoothManager.md#bluetoothmanagerblestartblescan).

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH, ohos.permission.MANAGE_BLUETOOTH, and ohos.permission.LOCATION

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name    | Type                                    | Mandatory  | Description                                 |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| filters | Array&lt;[ScanFilter](#scanfilter)&gt; | Yes   | Criteria for filtering the scan result. Set this parameter to **null** if you do not want to filter the scan result.|
| options | [ScanOptions](#scanoptions)            | No   | Scan options.                    |

**Return value**

No value is returned.

**Example**

```js
function onReceiveEvent(data) {
    console.info('BLE scan device find result = '+ JSON.stringify(data));
}
bluetooth.BLE.on("BLEDeviceFind", onReceiveEvent);
bluetooth.BLE.startBLEScan(
    [{
        deviceId:"XX:XX:XX:XX:XX:XX",
        name:"test",
        serviceUuid:"00001888-0000-1000-8000-00805f9b34fb"
    }],
    {
        interval: 500,
        dutyMode: bluetooth.ScanDuty.SCAN_MODE_LOW_POWER,
        matchMode: bluetooth.MatchMode.MATCH_MODE_AGGRESSIVE,
    }
);
```


### bluetooth.BLE.stopBLEScan<sup>(deprecated)</sup>

stopBLEScan(): void

Stops the BLE scan.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.BLE.stopBLEScan](js-apis-bluetoothManager.md#bluetoothmanagerblestopblescan).

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

No value is returned.

**Example**

```js
bluetooth.BLE.stopBLEScan();
```


### bluetooth.BLE.on('BLEDeviceFind')<sup>(deprecated)</sup>

on(type: "BLEDeviceFind", callback: Callback&lt;Array&lt;ScanResult&gt;&gt;): void

Subscribe to the BLE device discovery events.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.BLE.on('BLEDeviceFind')](js-apis-bluetoothManager.md#bluetoothmanagerbleonbledevicefind).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                 |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEDeviceFind** indicates an event reported when a BLE device is discovered.  |
| callback | Callback&lt;Array&lt;[ScanResult](#scanresult)&gt;&gt; | Yes   | Callback invoked to return the discovered devices. You need to implement this callback.|

**Return value**

No value is returned.

**Example**

```js
function onReceiveEvent(data) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
bluetooth.BLE.on('BLEDeviceFind', onReceiveEvent);
```


### bluetooth.BLE.off('BLEDeviceFind')<sup>(deprecated)</sup>

off(type: "BLEDeviceFind", callback?: Callback&lt;Array&lt;ScanResult&gt;&gt;): void

Unsubscribes from the BLE device discovery events.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.BLE.off('BLEDeviceFind')](js-apis-bluetoothManager.md#bluetoothmanagerbleoffbledevicefind).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEDeviceFind** indicates an event reported when a BLE device is discovered.       |
| callback | Callback&lt;Array&lt;[ScanResult](#scanresult)&gt;&gt; | No   | Callback for the **BLEDeviceFind** event. If this parameter is not set, this method unsubscribes from all callbacks corresponding to **type**.|

**Return value**

No value is returned.

**Example**

```js
function onReceiveEvent(data) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
bluetooth.BLE.on('BLEDeviceFind', onReceiveEvent);
bluetooth.BLE.off('BLEDeviceFind', onReceiveEvent);
```


## BaseProfile

Provides the profile base class.


### getConnectionDevices<sup>8+</sup><sup>(deprecated)</sup><a name="getConnectionDevices"></a>

getConnectionDevices(): Array&lt;string&gt;

Obtains the connected devices.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.BaseProfile.getConnectionDevices](js-apis-bluetoothManager.md#getconnectiondevices).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                 | Description           |
| ------------------- | ------------- |
| Array&lt;string&gt; | Addresses of the connected devices.|

**Example**

```js
let a2dpSrc = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;
let retArray = a2dpSrc.getConnectionDevices();
```

### getDeviceState<sup>8+</sup><sup>(deprecated)</sup><a name="getDeviceState"></a>

getDeviceState(device: string): ProfileConnectionState

Obtains the connection state of the profile.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.BaseProfile.getDeviceState](js-apis-bluetoothManager.md#getdevicestate).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| device | string | Yes   | Address of the target device.|

**Return value**

| Type                                             | Description                   |
| ------------------------------------------------- | ----------------------- |
| [ProfileConnectionState](#profileconnectionstate) | Profile connection state obtained.|

**Example**

```js
let a2dpSrc = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;
let ret = a2dpSrc.getDeviceState('XX:XX:XX:XX:XX:XX');
```

## A2dpSourceProfile

Before using a method of **A2dpSourceProfile**, you need to create an instance of this class by using the **getProfile()** method.


### connect<sup>8+</sup><sup>(deprecated)</sup><a name="a2dp-connect"></a>

connect(device: string): boolean

Sets up an Advanced Audio Distribution Profile (A2DP) connection.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.A2dpSourceProfile.connect](js-apis-bluetoothManager.md#connect).

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| device | string | Yes   | Address of the target device.|

**Return value**

| Type     | Description                 |
| ------- | ------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let a2dpSrc = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;
let ret = a2dpSrc.connect('XX:XX:XX:XX:XX:XX');
```


### disconnect<sup>8+</sup><sup>(deprecated)</sup><a name="a2dp-disconnect"></a>

disconnect(device: string): boolean

Disconnects an A2DP connection.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.A2dpSourceProfile.disconnect](js-apis-bluetoothManager.md#disconnect).

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| device | string | Yes   | Address of the target device.|

**Return value**

| Type     | Description                 |
| ------- | ------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let a2dpSrc = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;
let ret = a2dpSrc.disconnect('XX:XX:XX:XX:XX:XX');
```


### on('connectionStateChange')<sup>8+</sup><sup>(deprecated)</sup>

on(type: "connectionStateChange", callback: Callback&lt;[StateChangeParam](#StateChangeParam)&gt;): void

Subscribes to the A2DP connection state change events.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.A2dpSourceProfile.on('connectionStateChange')](js-apis-bluetoothManager.md#onconnectionstatechange).

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectionStateChange** indicates an A2DP connection state change event.|
| callback | Callback&lt;[StateChangeParam](#StateChangeParam)&gt; | Yes   | Callback invoked to return the A2DP connection state change event.                              |

**Return value**

No value is returned.

**Example**

```js
function onReceiveEvent(data) {
    console.info('a2dp state = '+ JSON.stringify(data));
}
let a2dpSrc = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;
a2dpSrc.on('connectionStateChange', onReceiveEvent);
```


### off('connectionStateChange')<sup>8+</sup><sup>(deprecated)</sup>

off(type: "connectionStateChange", callback?: Callback&lt;[StateChangeParam](#StateChangeParam)&gt;): void

Unsubscribes from the A2DP connection state change events.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.A2dpSourceProfile.off('connectionStateChange')](js-apis-bluetoothManager.md#offconnectionstatechange).

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectionStateChange** indicates an A2DP connection state change event.|
| callback | Callback&lt;[StateChangeParam](#StateChangeParam)&gt; | No   | Callback for the A2DP connection state change event.                              |

**Return value**

No value is returned.

**Example**

```js
function onReceiveEvent(data) {
    console.info('a2dp state = '+ JSON.stringify(data));
}
let a2dpSrc = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;
a2dpSrc.on('connectionStateChange', onReceiveEvent);
a2dpSrc.off('connectionStateChange', onReceiveEvent);
```


### getPlayingState<sup>8+</sup><sup>(deprecated)</sup>

getPlayingState(device: string): PlayingState

Obtains the playing state of a device.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.A2dpSourceProfile.getPlayingState](js-apis-bluetoothManager.md#getplayingstate).

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| device | string | Yes   | Address of the target device.|

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| [PlayingState](#PlayingState) | Playing state of the remote device obtained.|

**Example**

```js
let a2dpSrc = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;
let state = a2dpSrc.getPlayingState('XX:XX:XX:XX:XX:XX');
```


## HandsFreeAudioGatewayProfile

Before using a method of **HandsFreeAudioGatewayProfile**, you need to create an instance of this class by using the **getProfile()** method.


### connect<sup>8+</sup><sup>(deprecated)</sup><a name="hfp-connect"></a>

connect(device: string): boolean

Sets up a Hands-free Profile (HFP) connection of a device.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.HandsFreeAudioGatewayProfile.connect](js-apis-bluetoothManager.md#connect-1).

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| device | string | Yes   | Address of the target device.|

**Return value**

| Type     | Description                 |
| ------- | ------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let hfpAg = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_HANDS_FREE_AUDIO_GATEWAY) as
  bluetooth.HandsFreeAudioGatewayProfile;
let ret = hfpAg.connect('XX:XX:XX:XX:XX:XX');
```


### disconnect<sup>8+</sup><sup>(deprecated)</sup><a name="hfp-disconnect"></a>

disconnect(device: string): boolean

Disconnects the HFP connection of a device.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.HandsFreeAudioGatewayProfile.disconnect](js-apis-bluetoothManager.md#disconnect-1).

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| device | string | Yes   | Address of the target device.|

**Return value**

| Type     | Description                 |
| ------- | ------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let hfpAg = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_HANDS_FREE_AUDIO_GATEWAY) as
  bluetooth.HandsFreeAudioGatewayProfile;
let ret = hfpAg.disconnect('XX:XX:XX:XX:XX:XX');
```


### on('connectionStateChange')<sup>8+</sup><sup>(deprecated)</sup>

on(type: "connectionStateChange", callback: Callback&lt;[StateChangeParam](#StateChangeParam)&gt;): void

Subscribes to the HFP connection state change events.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.HandsFreeAudioGatewayProfile.on('connectionStateChange')](js-apis-bluetoothManager.md#onconnectionstatechange-1).

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectionStateChange** indicates an HFP connection state change event.|
| callback | Callback&lt;[StateChangeParam](#StateChangeParam)&gt; | Yes   | Callback invoked to return the HFP connection state change event.                              |

**Return value**

No value is returned.

**Example**

```js
function onReceiveEvent(data) {
    console.info('hfp state = '+ JSON.stringify(data));
}
let hfpAg = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_HANDS_FREE_AUDIO_GATEWAY) as
  bluetooth.HandsFreeAudioGatewayProfile;
hfpAg.on('connectionStateChange', onReceiveEvent);
```


### off('connectionStateChange')<sup>8+</sup><sup>(deprecated)</sup>

off(type: "connectionStateChange", callback?: Callback&lt;[StateChangeParam](#StateChangeParam)&gt;): void

Unsubscribes from the HFP connection state change events.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.HandsFreeAudioGatewayProfile.off('connectionStateChange')](js-apis-bluetoothManager.md#offconnectionstatechange-1).

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectionStateChange** indicates an HFP connection state change event.|
| callback | Callback&lt;[StateChangeParam](#StateChangeParam)&gt; | No   | Callback for the HFP connection state change event.                              |

**Return value**

No value is returned.

**Example**

```js
function onReceiveEvent(data) {
    console.info('hfp state = '+ JSON.stringify(data));
}
let hfpAg = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_HANDS_FREE_AUDIO_GATEWAY) as
  bluetooth.HandsFreeAudioGatewayProfile;
hfpAg.on('connectionStateChange', onReceiveEvent);
hfpAg.off('connectionStateChange', onReceiveEvent);
```


## GattServer

Implements the Generic Attribute Profile (GATT) server. Before using a method of this class, you need to create a **GattServer** instance using the **createGattServer()** method.


### startAdvertising<sup>(deprecated)</sup>

startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void

Starts BLE advertising.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattServer.startAdvertising](js-apis-bluetoothManager.md#startadvertising).

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name        | Type                                   | Mandatory  | Description            |
| ----------- | ------------------------------------- | ---- | -------------- |
| setting     | [AdvertiseSetting](#advertisesetting) | Yes   | Settings related to BLE advertising.   |
| advData     | [AdvertiseData](#advertisedata)       | Yes   | Content of the BLE advertisement packet.     |
| advResponse | [AdvertiseData](#advertisedata)       | No   | Response to the BLE scan request.|

**Return value**

No value is returned.

**Example**

```js
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
let gattServer = bluetooth.BLE.createGattServer();
gattServer.startAdvertising({
            interval:150,
            txPower:60,
            connectable:true,
        },{
            serviceUuids:["00001888-0000-1000-8000-00805f9b34fb"],
            manufactureData:[{
                 manufactureId:4567,
                 manufactureValue:manufactureValueBuffer.buffer
            }],
            serviceData:[{
                 serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
                 serviceValue:serviceValueBuffer.buffer
            }],
        },{
            serviceUuids:["00001889-0000-1000-8000-00805f9b34fb"],
            manufactureData:[{
                 manufactureId:1789,
                 manufactureValue:manufactureValueBuffer.buffer
            }],
            serviceData:[{
                 serviceUuid:"00001889-0000-1000-8000-00805f9b34fb",
                 serviceValue:serviceValueBuffer.buffer
            }],
});
```


### stopAdvertising<sup>(deprecated)</sup>

stopAdvertising(): void

Stops BLE advertising.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattServer.stopAdvertising](js-apis-bluetoothManager.md#stopadvertising).

**Required permissions**: ohos.permission.DISCOVER_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

No value is returned.

**Example**

```js
let server = bluetooth.BLE.createGattServer();
server.stopAdvertising();
```


### addService<sup>(deprecated)</sup>

addService(service: GattService): boolean

Adds a service to this GATT server.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattServer.addService](js-apis-bluetoothManager.md#addservice).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name    | Type                         | Mandatory  | Description                      |
| ------- | --------------------------- | ---- | ------------------------ |
| service | [GattService](#gattservice) | Yes   | Service to add. Settings related to BLE advertising.|

**Return value**

| Type     | Description                        |
| ------- | -------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
// Create descriptors.
let descriptors = [];
let arrayBuffer = new ArrayBuffer(8);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
let descriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;

// Create characteristics.
let characteristics = [];
let arrayBufferC = new ArrayBuffer(8);
let cccV = new Uint8Array(arrayBufferC);
cccV[0] = 1;
let characteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
let characteristicN = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001821-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
characteristics[0] = characteristic;

// Create a gattService instance.
let gattService = {serviceUuid:'00001810-0000-1000-8000-00805F9B34FB', isPrimary: true, characteristics:characteristics, includeServices:[]};

let gattServer = bluetooth.BLE.createGattServer();
let ret = gattServer.addService(gattService);
if (ret) {
   console.log("add service successfully");
} else {
   console.log("add service failed");
}
```


### removeService<sup>(deprecated)</sup>

removeService(serviceUuid: string): boolean

Removes a service from this GATT server.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattServer.removeService](js-apis-bluetoothManager.md#removeservice).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name        | Type    | Mandatory  | Description                                      |
| ----------- | ------ | ---- | ---------------------------------------- |
| serviceUuid | string | Yes   | Universally unique identifier (UUID) of the service to remove, for example, **00001810-0000-1000-8000-00805F9B34FB**.|

**Return value**

| Type     | Description                        |
| ------- | -------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let server = bluetooth.BLE.createGattServer();
server.removeService('00001810-0000-1000-8000-00805F9B34FB');
```


### close<sup>(deprecated)</sup>

close(): void

Closes this GATT server to unregister it from the protocol stack. After this method is called, this [GattServer](#gattserver) cannot be used.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattServer.close](js-apis-bluetoothManager.md#close).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Example**

```js
let server = bluetooth.BLE.createGattServer();
server.close();
```


### notifyCharacteristicChanged<sup>(deprecated)</sup>

notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): boolean

Notifies the connected client device when a characteristic value changes.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattServer.notifyCharacteristicChanged](js-apis-bluetoothManager.md#notifycharacteristicchanged).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name                 | Type                                      | Mandatory  | Description                                     |
| -------------------- | ---------------------------------------- | ---- | --------------------------------------- |
| deviceId             | string                                   | Yes   | Address of the client that receives notifications, for example, XX:XX:XX:XX:XX:XX.|
| notifyCharacteristic | [NotifyCharacteristic](#notifycharacteristic) | Yes   | New characteristic value.                              |

**Return value**

| Type     | Description                      |
| ------- | ------------------------ |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
// Create descriptors.
let descriptors = [];
let arrayBuffer = new ArrayBuffer(8);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
let descriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;
let arrayBufferC = new ArrayBuffer(8);
let characteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
let notifyCharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001821-0000-1000-8000-00805F9B34FB', characteristicValue: characteristic.characteristicValue, confirm: false};
let server = bluetooth.BLE.createGattServer();
server.notifyCharacteristicChanged('XX:XX:XX:XX:XX:XX', notifyCharacteristic);
```


### sendResponse<sup>(deprecated)</sup>

sendResponse(serverResponse: ServerResponse): boolean

Sends a response to a read or write request from the GATT client.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattServer.sendResponse](js-apis-bluetoothManager.md#sendresponse).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                               | Mandatory  | Description             |
| -------------- | --------------------------------- | ---- | --------------- |
| serverResponse | [ServerResponse](#serverresponse) | Yes   | Response returned by the GATT server.|

**Return value**

| Type     | Description                        |
| ------- | -------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
/* send response */
let arrayBufferCCC = new ArrayBuffer(8);
let cccValue = new Uint8Array(arrayBufferCCC);
cccValue[0] = 1123;
let serverResponse = {
    "deviceId": "XX:XX:XX:XX:XX:XX",
    "transId": 0,
    "status": 0,
    "offset": 0,
    "value": arrayBufferCCC,
};

let gattServer = bluetooth.BLE.createGattServer();
let ret = gattServer.sendResponse(serverResponse);
if (ret) {
  console.log('bluetooth sendResponse successfully');
} else {
  console.log('bluetooth sendResponse failed');
}
```


### on('characteristicRead')<sup>(deprecated)</sup>

on(type: "characteristicRead", callback: Callback&lt;CharacteristicReadReq&gt;): void

Subscribes to the characteristic read request events.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattServer.on('characteristicRead')](js-apis-bluetoothManager.md#oncharacteristicread).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                   |
| -------- | ---------------------------------------- | ---- | ------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **characteristicRead** indicates a characteristic read request event.|
| callback | Callback&lt;[CharacteristicReadReq](#characteristicreadreq)&gt; | Yes   | Callback invoked to return a characteristic read request event from the GATT client.           |

**Return value**

No value is returned.

**Example**

```js
let arrayBufferCCC = new ArrayBuffer(8);
let cccValue = new Uint8Array(arrayBufferCCC);
cccValue[0] = 1123;
function ReadCharacteristicReq(CharacteristicReadReq) {
  let deviceId = CharacteristicReadReq.deviceId;
  let transId = CharacteristicReadReq.transId;
  let offset = CharacteristicReadReq.offset;
  let characteristicUuid = CharacteristicReadReq.characteristicUuid;

  let serverResponse = {deviceId: deviceId, transId: transId, status: 0, offset: offset, value:arrayBufferCCC};

  let ret = gattServer.sendResponse(serverResponse);
  if (ret) {
    console.log('bluetooth sendResponse successfully');
  } else {
    console.log('bluetooth sendResponse failed');
  }
}

let gattServer = bluetooth.BLE.createGattServer();
gattServer.on("characteristicRead", ReadCharacteristicReq);
```


### off('characteristicRead')<sup>(deprecated)</sup>

off(type: "characteristicRead", callback?: Callback&lt;CharacteristicReadReq&gt;): void

Unsubscribes from the characteristic read request events.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattServer.off('characteristicRead')](js-apis-bluetoothManager.md#offcharacteristicread).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **characteristicRead** indicates a characteristic read request event.   |
| callback | Callback&lt;[CharacteristicReadReq](#characteristicreadreq)&gt; | No   | Callback for the characteristic read request event. If this parameter is not set, this method unsubscribes from all callbacks corresponding to **type**.|

**Return value**

No value is returned.

**Example**

```js
let gattServer = bluetooth.BLE.createGattServer();
gattServer.off("characteristicRead");
```


### on('characteristicWrite')<sup>(deprecated)</sup>

on(type: "characteristicWrite", callback: Callback&lt;CharacteristicWriteReq&gt;): void

Subscribes to the characteristic write request events.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattServer.on('characteristicWrite')](js-apis-bluetoothManager.md#oncharacteristicwrite).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                    |
| -------- | ---------------------------------------- | ---- | -------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **characteristicWrite** indicates a characteristic write request event.|
| callback | Callback&lt;[CharacteristicWriteReq](#characteristicwritereq)&gt; | Yes   | Callback invoked to return a characteristic write request from the GATT client.            |

**Return value**

No value is returned.

**Example**

```js
let arrayBufferCCC = new ArrayBuffer(8);
let cccValue = new Uint8Array(arrayBufferCCC);
function WriteCharacteristicReq(CharacteristicWriteReq) {
  let deviceId = CharacteristicWriteReq.deviceId;
  let transId = CharacteristicWriteReq.transId;
  let offset = CharacteristicWriteReq.offset;
  let isPrep = CharacteristicWriteReq.isPrep;
  let needRsp = CharacteristicWriteReq.needRsp;
  let value =  new Uint8Array(CharacteristicWriteReq.value);
  let characteristicUuid = CharacteristicWriteReq.characteristicUuid;

  cccValue[0] = value[0];
  let serverResponse = {deviceId: deviceId, transId: transId, status: 0, offset: offset, value:arrayBufferCCC};

  let ret = gattServer.sendResponse(serverResponse);
  if (ret) {
    console.log('bluetooth sendResponse successfully');
  } else {
    console.log('bluetooth sendResponse failed');
  }
}

let gattServer = bluetooth.BLE.createGattServer();
gattServer.on("characteristicWrite", WriteCharacteristicReq);
```


### off('characteristicWrite')<sup>(deprecated)</sup>

off(type: "characteristicWrite", callback?: Callback&lt;CharacteristicWriteReq&gt;): void

Unsubscribes from the characteristic write request events.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattServer.off('characteristicWrite')](js-apis-bluetoothManager.md#offcharacteristicwrite).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **characteristicWrite** indicates a characteristic write request event.  |
| callback | Callback&lt;[CharacteristicWriteReq](#characteristicwritereq)&gt; | No   | Callback for the characteristic write request event. If this parameter is not set, this method unsubscribes from all callbacks corresponding to **type**.|

**Return value**

No value is returned.

**Example**

```js
let gattServer = bluetooth.BLE.createGattServer();
gattServer.off("characteristicWrite");
```


### on('descriptorRead')<sup>(deprecated)</sup>

on(type: "descriptorRead", callback: Callback&lt;DescriptorReadReq&gt;): void

Subscribes to the descriptor read request events.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattServer.on('descriptorRead')](js-apis-bluetoothManager.md#ondescriptorread).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                               |
| -------- | ---------------------------------------- | ---- | --------------------------------- |
| type     | string                                   | Yes   | Event type. The value **descriptorRead** indicates a descriptor read request event.|
| callback | Callback&lt;[DescriptorReadReq](#descriptorreadreq)&gt; | Yes   | Callback invoked to return a descriptor read request event from the GATT client.       |

**Return value**

No value is returned.

**Example**

```js
let arrayBufferDesc = new ArrayBuffer(8);
let descValue = new Uint8Array(arrayBufferDesc);
descValue[0] = 1101;
function ReadDescriptorReq(DescriptorReadReq) {
  let deviceId = DescriptorReadReq.deviceId;
  let transId = DescriptorReadReq.transId;
  let offset = DescriptorReadReq.offset;
  let descriptorUuid = DescriptorReadReq.descriptorUuid;

  let serverResponse = {deviceId: deviceId, transId: transId, status: 0, offset: offset, value:arrayBufferDesc};

  let ret = gattServer.sendResponse(serverResponse);
  if (ret) {
    console.log('bluetooth sendResponse successfully');
  } else {
    console.log('bluetooth sendResponse failed');
  }
}

let gattServer = bluetooth.BLE.createGattServer();
gattServer.on("descriptorRead", ReadDescriptorReq);
```


### off('descriptorRead')<sup>(deprecated)</sup>

off(type: "descriptorRead", callback?: Callback&lt;DescriptorReadReq&gt;): void

Unsubscribes from the descriptor read request events.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattServer.off('descriptorRead')](js-apis-bluetoothManager.md#offdescriptorread).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **descriptorRead** indicates a descriptor read request event.       |
| callback | Callback&lt;[DescriptorReadReq](#descriptorreadreq)&gt; | No   | Callback for the descriptor read request event. If this parameter is not set, this method unsubscribes from all callbacks corresponding to **type**.|

**Return value**

No value is returned.

**Example**

```js
let gattServer = bluetooth.BLE.createGattServer();
gattServer.off("descriptorRead");
```


### on('descriptorWrite')<sup>(deprecated)</sup>

on(type: "descriptorWrite", callback: Callback&lt;DescriptorWriteReq&gt;): void

Subscribes to the descriptor write request events.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattServer.on('descriptorWrite')](js-apis-bluetoothManager.md#ondescriptorwrite).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                |
| -------- | ---------------------------------------- | ---- | ---------------------------------- |
| type     | string                                   | Yes   | Event type. The value **descriptorWrite** indicates a descriptor write request event.|
| callback | Callback&lt;[DescriptorWriteReq](#descriptorwritereq)&gt; | Yes   | Callback invoked to return a descriptor write request from the GATT client.        |

**Return value**

No value is returned.

**Example**

```js
let arrayBufferDesc = new ArrayBuffer(8);
let descValue = new Uint8Array(arrayBufferDesc);
function WriteDescriptorReq(DescriptorWriteReq) {
  let deviceId = DescriptorWriteReq.deviceId;
  let transId = DescriptorWriteReq.transId;
  let offset = DescriptorWriteReq.offset;
  let isPrep = DescriptorWriteReq.isPrep;
  let needRsp = DescriptorWriteReq.needRsp;
  let value = new Uint8Array(DescriptorWriteReq.value);
  let descriptorUuid = DescriptorWriteReq.descriptorUuid;

  descValue[0] = value[0];
  let serverResponse = {deviceId: deviceId, transId: transId, status: 0, offset: offset, value:arrayBufferDesc};

  let ret = gattServer.sendResponse(serverResponse);
  if (ret) {
    console.log('bluetooth sendResponse successfully');
  } else {
    console.log('bluetooth sendResponse failed');
  }
}

let gattServer = bluetooth.BLE.createGattServer();
gattServer.on("descriptorRead", WriteDescriptorReq);
```


### off('descriptorWrite')<sup>(deprecated)</sup>

off(type: "descriptorWrite", callback?: Callback&lt;DescriptorWriteReq&gt;): void

Unsubscribes from the descriptor write request events.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattServer.off('descriptorWrite')](js-apis-bluetoothManager.md#offdescriptorwrite).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **descriptorWrite** indicates a descriptor write request event.      |
| callback | Callback&lt;[DescriptorWriteReq](#descriptorwritereq)&gt; | No   | Callback for the descriptor write request event. If this parameter is not set, this method unsubscribes from all callbacks corresponding to **type**.|

**Return value**

No value is returned.

**Example**

```js
let gattServer = bluetooth.BLE.createGattServer();
gattServer.off("descriptorWrite");
```


### on('connectStateChange')<sup>(deprecated)</sup>

on(type: "connectStateChange", callback: Callback&lt;BLEConnectChangedState&gt;): void

Subscribes to the BLE connection state change events.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattServer.on('connectStateChange')](js-apis-bluetoothManager.md#onconnectstatechange).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectStateChange** indicates a BLE connection state change event.|
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstate)&gt; | Yes   | Callback invoked to return the BLE connection state.                         |

**Return value**

No value is returned.

**Example**

```js
function Connected(BLEConnectChangedState) {
  let deviceId = BLEConnectChangedState.deviceId;
  let status = BLEConnectChangedState.state;
}

let gattServer = bluetooth.BLE.createGattServer();
gattServer.on("connectStateChange", Connected);
```


### off('connectStateChange')<sup>(deprecated)</sup>

off(type: "connectStateChange", callback?: Callback&lt;BLEConnectChangedState&gt;): void

Unsubscribes from the BLE connection state change events.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattServer.off('connectStateChange')](js-apis-bluetoothManager.md#offconnectstatechange).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **connectStateChange** indicates a BLE connection state change event.|
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstate)&gt; | No   | Callback for the BLE connection state change event. If this parameter is not set, this method unsubscribes from all callbacks corresponding to **type**.|

**Return value**

No value is returned.

**Example**

```js
let gattServer = bluetooth.BLE.createGattServer();
gattServer.off("connectStateChange");
```


## GattClientDevice

Implements the GATT client. Before using a method of this class, you must create a **GattClientDevice** instance using the **createGattClientDevice(deviceId: string)** method.


### connect<sup>(deprecated)</sup>

connect(): boolean

Initiates a connection to the remote BLE device.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.connect](js-apis-bluetoothManager.md#connect-3).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type     | Description                       |
| ------- | ------------------------- |
| boolean | Returns **true** if the connection is successful; returns **false** otherwise.|

**Example**

```js
let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let ret = device.connect();
```


### disconnect<sup>(deprecated)</sup>

disconnect(): boolean

Disconnects from the remote BLE device.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.disconnect](js-apis-bluetoothManager.md#disconnect-4).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type     | Description                          |
| ------- | ---------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let ret = device.disconnect();
```


### close<sup>(deprecated)</sup>

close(): boolean

Closes this GATT client to unregister it from the protocol stack. After this method is called, this [GattClientDevice](#gattclientdevice) instance cannot be used.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.close](js-apis-bluetoothManager.md#close-1).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type     | Description                        |
| ------- | -------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let ret = device.close();
```




### getServices<sup>(deprecated)</sup>

getServices(callback: AsyncCallback&lt;Array&lt;GattService&gt;&gt;): void

Obtains all services of the remote BLE device. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.getServices](js-apis-bluetoothManager.md#getservices).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;Array&lt;[GattService](#gattservice)&gt;&gt; | Yes   | Callback invoked to return the services obtained.|

**Return value**

No value is returned.

**Example**

```js
// Callback
function getServices(code, gattServices) {
  if (code.code == 0) {
      let services = gattServices;
      console.log('bluetooth code is ' + code.code);
      console.log("bluetooth services size is ", services.length);

      for (let i = 0; i < services.length; i++) {
        console.log('bluetooth serviceUuid is ' + services[i].serviceUuid);
      }
  }
}

let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
device.connect();
device.getServices(getServices);
```


### getServices<sup>(deprecated)</sup>

getServices(): Promise&lt;Array&lt;GattService&gt;&gt;

Obtains all services of the remote BLE device. This API uses a promise to return the result.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.getServices](js-apis-bluetoothManager.md#getservices-1).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                                      | Description                         |
| ---------------------------------------- | --------------------------- |
| Promise&lt;Array&lt;[GattService](#gattservice)&gt;&gt; | Promise used to return the services obtained.|

**Example**

```js
// Promise
let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
device.connect();
device.getServices().then(result => {
    console.info("getServices successfully:" + JSON.stringify(result));
});
```


### readCharacteristicValue<sup>(deprecated)</sup>

readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback&lt;BLECharacteristic&gt;): void

Reads the characteristic value of the specific service of the remote BLE device. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.readCharacteristicValue](js-apis-bluetoothManager.md#readcharacteristicvalue).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                      | Mandatory  | Description                     |
| -------------- | ---------------------------------------- | ---- | ----------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic)  | Yes   | Characteristic value to read.               |
| callback       | AsyncCallback&lt;[BLECharacteristic](#blecharacteristic)&gt; | Yes   | Callback invoked to return the characteristic value read.|

**Return value**

No value is returned.

**Example**

```js
function readCcc(code, BLECharacteristic) {
  if (code.code != 0) {
      return;
  }
  console.log('bluetooth characteristic uuid: ' + BLECharacteristic.characteristicUuid);
  let value = new Uint8Array(BLECharacteristic.characteristicValue);
  console.log('bluetooth characteristic value: ' + value[0] +','+ value[1]+','+ value[2]+','+ value[3]);
}

let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let descriptors = [];
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
characteristicValue: bufferCCC, descriptors:descriptors};

device.readCharacteristicValue(characteristic, readCcc);
```


### readCharacteristicValue<sup>(deprecated)</sup>

readCharacteristicValue(characteristic: BLECharacteristic): Promise&lt;BLECharacteristic&gt;

Reads the characteristic value of the specific service of the remote BLE device. This API uses a promise to return the result.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.readCharacteristicValue](js-apis-bluetoothManager.md#readcharacteristicvalue-1).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description      |
| -------------- | --------------------------------------- | ---- | -------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes   | Characteristic value to read.|

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| Promise&lt;[BLECharacteristic](#blecharacteristic)&gt; | Promise used to return the characteristic value read.|

**Example**

```js
let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let descriptors = [];
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
characteristicValue: bufferCCC, descriptors:descriptors};

device.readCharacteristicValue(characteristic);
```


### readDescriptorValue<sup>(deprecated)</sup>

readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback&lt;BLEDescriptor&gt;): void

Reads the descriptor contained in the specific characteristic of the remote BLE device. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.readDescriptorValue](js-apis-bluetoothManager.md#readdescriptorvalue).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name       | Type                                      | Mandatory  | Description                     |
| ---------- | ---------------------------------------- | ---- | ----------------------- |
| descriptor | [BLEDescriptor](#bledescriptor)          | Yes   | Descriptor to read.               |
| callback   | AsyncCallback&lt;[BLEDescriptor](#bledescriptor)&gt; | Yes   | Callback invoked to return the descriptor read.|

**Return value**

No value is returned.

**Example**

```js
function readDesc(code, BLEDescriptor) {
  if (code.code != 0) {
      return;
  }
  console.log('bluetooth descriptor uuid: ' + BLEDescriptor.descriptorUuid);
  let value = new Uint8Array(BLEDescriptor.descriptorValue);
  console.log('bluetooth descriptor value: ' + value[0] +','+ value[1]+','+ value[2]+','+ value[3]);
}

let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
device.readDescriptorValue(descriptor, readDesc);
```


### readDescriptorValue<sup>(deprecated)</sup>

readDescriptorValue(descriptor: BLEDescriptor): Promise&lt;BLEDescriptor&gt;

Reads the descriptor contained in the specific characteristic of the remote BLE device. This API uses a promise to return the result.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.readDescriptorValue](js-apis-bluetoothManager.md#readdescriptorvalue-1).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name       | Type                             | Mandatory  | Description      |
| ---------- | ------------------------------- | ---- | -------- |
| descriptor | [BLEDescriptor](#bledescriptor) | Yes   | Descriptor to read.|

**Return value**

| Type                                      | Description                        |
| ---------------------------------------- | -------------------------- |
| Promise&lt;[BLEDescriptor](#bledescriptor)&gt; | Promise used to return the descriptor read.|

**Example**

```js
let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
device.readDescriptorValue(descriptor);
```


### writeCharacteristicValue<sup>(deprecated)</sup>

writeCharacteristicValue(characteristic: BLECharacteristic): boolean

Writes a characteristic value to the remote BLE device.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.writeCharacteristicValue](js-apis-bluetoothManager.md#writecharacteristicvalue).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description                 |
| -------------- | --------------------------------------- | ---- | ------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes   | Binary value and other parameters of the BLE device characteristic.|

**Return value**

| Type     | Description                         |
| ------- | --------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let descriptors = [];
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  characteristicValue: bufferCCC, descriptors:descriptors};
let retWriteCcc = device.writeCharacteristicValue(characteristic);
if (retWriteCcc) {
  console.log('write characteristic successfully');
} else {
  console.log('write characteristic failed');
}
```


### writeDescriptorValue<sup>(deprecated)</sup>

writeDescriptorValue(descriptor: BLEDescriptor): boolean

Writes binary data to the specific descriptor of the remote BLE device.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.writeDescriptorValue](js-apis-bluetoothManager.md#writedescriptorvalue).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name       | Type                             | Mandatory  | Description                |
| ---------- | ------------------------------- | ---- | ------------------ |
| descriptor | [BLEDescriptor](#bledescriptor) | Yes   | Binary value and other parameters of the BLE device descriptor.|

**Return value**

| Type     | Description                         |
| ------- | --------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 22;
let descriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
let retWriteDesc = device.writeDescriptorValue(descriptor);
if (retWriteDesc) {
  console.log('bluetooth write descriptor successfully');
} else {
  console.log('bluetooth write descriptor failed');
}
```


### setBLEMtuSize<sup>(deprecated)</sup>

setBLEMtuSize(mtu: number): boolean

Sets the maximum transmission unit (MTU) that can be transmitted between the GATT client and its remote BLE device. This API can be used only after a connection is set up by calling [connect](#connect).

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.setBLEMtuSize](js-apis-bluetoothManager.md#setblemtusize).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name | Type    | Mandatory  | Description            |
| ---- | ------ | ---- | -------------- |
| mtu  | number | Yes   | MTU to set, which ranges from 22 to 512 bytes.|

**Return value**

| Type     | Description                          |
| ------- | ---------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
device.setBLEMtuSize(128);
```


### setNotifyCharacteristicChanged<sup>(deprecated)</sup>

setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): boolean

Sets the function of notifying the GATT client when the characteristic value of the remote BLE device changes.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.setNotifyCharacteristicChanged](js-apis-bluetoothManager.md#setnotifycharacteristicchanged).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name           | Type                                     | Mandatory  | Description                           |
| -------------- | --------------------------------------- | ---- | ----------------------------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes   | BLE characteristic to listen for.                     |
| enable         | boolean                                 | Yes   | Whether to enable the notify function. The value **true** means to enable the notify function, and the value **false** means the opposite.|

**Return value**

| Type     | Description                       |
| ------- | ------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
// Create descriptors.
let descriptors = [];
let arrayBuffer = new ArrayBuffer(8);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
let descriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;
let arrayBufferC = new ArrayBuffer(8);
let characteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
device.setNotifyCharacteristicChanged(characteristic, false);
```


### on('BLECharacteristicChange')<sup>(deprecated)</sup>

on(type: "BLECharacteristicChange", callback: Callback&lt;BLECharacteristic&gt;): void

Subscribes to the BLE characteristic change events. The client can receive a notification from the server only after the **setNotifyCharacteristicChanged** method is called.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.on('BLECharacteristicChange')](js-apis-bluetoothManager.md#onblecharacteristicchange).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLECharacteristicChange** indicates a characteristic value change event.|
| callback | Callback&lt;[BLECharacteristic](#blecharacteristic)&gt; | Yes   | Callback invoked to return the characteristic value changes.                 |

**Return value**

No value is returned.

**Example**

```js
function CharacteristicChange(CharacteristicChangeReq) {
  let serviceUuid = CharacteristicChangeReq.serviceUuid;
  let characteristicUuid = CharacteristicChangeReq.characteristicUuid;
  let value = new Uint8Array(CharacteristicChangeReq.characteristicValue);
}
let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
device.on('BLECharacteristicChange', CharacteristicChange);
```


### off('BLECharacteristicChange')<sup>(deprecated)</sup>

off(type: "BLECharacteristicChange", callback?: Callback&lt;BLECharacteristic&gt;): void

Unsubscribes from the BLE characteristic change events.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.off('BLECharacteristicChange')](js-apis-bluetoothManager.md#offblecharacteristicchange).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLECharacteristicChange** indicates a characteristic value change event.|
| callback | Callback&lt;[BLECharacteristic](#blecharacteristic)&gt; | No   | Callback for the characteristic value change event. If this parameter is not set, this method unsubscribes from all callbacks corresponding to **type**.|

**Return value**

No value is returned.

**Example**

```js
let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
device.off('BLECharacteristicChange');
```


### on('BLEConnectionStateChange')<sup>(deprecated)</sup>

on(type: "BLEConnectionStateChange", callback: Callback&lt;BLEConnectChangedState&gt;): void

Subscribes to the BLE connection state change events.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.on('BLEConnectionStateChange')](js-apis-bluetoothManager.md#onbleconnectionstatechange).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEConnectionStateChange** indicates a BLE connection state change event.|
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstate)&gt; | Yes   | Callback invoked to return the BLE connection state.                          |

**Return value**

No value is returned.

**Example**

```js
function ConnectStateChanged(state) {
  console.log('bluetooth connect state changed');
  let connectState = state.state;
}
let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
device.on('BLEConnectionStateChange', ConnectStateChanged);
```


### off('BLEConnectionStateChange')<sup>(deprecated)</sup>

off(type: "BLEConnectionStateChange", callback?: Callback&lt;BLEConnectChangedState&gt;): void

Unsubscribes from the BLE connection state change events.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.off('BLEConnectionStateChange')](js-apis-bluetoothManager.md#offbleconnectionstatechange).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                      |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | Yes   | Event type. The value **BLEConnectionStateChange** indicates a BLE connection state change event.|
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstate)&gt; | No   | Callback for the BLE connection state change event. If this parameter is not set, this method unsubscribes from all callbacks corresponding to **type**.|

**Return value**

No value is returned.

**Example**

```js
let device = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
device.off('BLEConnectionStateChange');
```


### getDeviceName<sup>(deprecated)</sup>

getDeviceName(callback: AsyncCallback&lt;string&gt;): void

Obtains the name of the remote BLE device. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.getDeviceName](js-apis-bluetoothManager.md#getdevicename).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                             |
| -------- | --------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback invoked to return the remote BLE device name obtained.|

**Return value**

No value is returned.

**Example**

```js
// callback
let gattClient = bluetooth.BLE.createGattClientDevice("XX:XX:XX:XX:XX:XX");
let deviceName = gattClient.getDeviceName((err, data)=> {
    console.info('device name err ' + JSON.stringify(err));
    console.info('device name' + JSON.stringify(data));
})
```


### getDeviceName<sup>(deprecated)</sup>

getDeviceName(): Promise&lt;string&gt;

Obtains the name of the remote BLE device. This API uses a promise to return the result.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.getDeviceName](js-apis-bluetoothManager.md#getdevicename-1).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                   | Description                                |
| --------------------- | ---------------------------------- |
| Promise&lt;string&gt; | Promise used to return the remote BLE device name.|

**Example**

```js
// promise
let gattClient = bluetooth.BLE.createGattClientDevice("XX:XX:XX:XX:XX:XX");
let ret = device.connect();
let deviceName = gattClient.getDeviceName().then((data) => {
    console.info('device name' + JSON.stringify(data));
})
```


### getRssiValue<sup>(deprecated)</sup>

getRssiValue(callback: AsyncCallback&lt;number&gt;): void

Obtains the received signal strength indication (RSSI) of the remote BLE device. This API uses an asynchronous callback to return the result. It can be used only after a connection is set up by calling [connect](#connect).

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.getRssiValue](js-apis-bluetoothManager.md#getrssivalue).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                            |
| -------- | --------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback invoked to return the RSSI, in dBm.|

**Return value**

No value is returned.

**Example**

```js
// callback
let gattClient = bluetooth.BLE.createGattClientDevice("XX:XX:XX:XX:XX:XX");
let ret = device.connect();
let rssi = gattClient.getRssiValue((err, data)=> {
    console.info('rssi err ' + JSON.stringify(err));
    console.info('rssi value' + JSON.stringify(data));
})
```


### getRssiValue<sup>(deprecated)</sup>

getRssiValue(): Promise&lt;number&gt;

Obtains the RSSI of the remote BLE device. This API uses a promise to return the result. It can be used only after a connection is set up by calling [connect](#connect).

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattClientDevice.getRssiValue](js-apis-bluetoothManager.md#getrssivalue-1).

**Required permissions**: ohos.permission.USE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                   | Description                               |
| --------------------- | --------------------------------- |
| Promise&lt;number&gt; | Promise used to return the RSSI, in dBm.|

**Example**

```js
// promise
let gattClient = bluetooth.BLE.createGattClientDevice("XX:XX:XX:XX:XX:XX");
let rssi = gattClient.getRssiValue().then((data) => {
    console.info('rssi' + JSON.stringify(data));
})
```

## ScanMode<sup>8+</sup><sup>(deprecated)</sup><a name="ScanMode"></a>

Enumerates the scan modes.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.ScanMode](js-apis-bluetoothManager.md#scanmode).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                                      | Value | Description             |
| ---------------------------------------- | ---- | --------------- |
| SCAN_MODE_NONE                           | 0    | No scan mode.        |
| SCAN_MODE_CONNECTABLE                    | 1    | Connectable mode.       |
| SCAN_MODE_GENERAL_DISCOVERABLE           | 2    | General discoverable mode.   |
| SCAN_MODE_LIMITED_DISCOVERABLE           | 3    | Limited discoverable mode.   |
| SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE | 4    | General connectable and discoverable mode.|
| SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE | 5    | Limited connectable and discoverable mode.|

## BondState<sup>8+</sup><sup>(deprecated)</sup><a name="BondState"></a>

Enumerates the pairing states.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.BondState](js-apis-bluetoothManager.md#bondstate).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Value | Description    |
| ------------------ | ---- | ------ |
| BOND_STATE_INVALID | 0    | Invalid pairing.|
| BOND_STATE_BONDING | 1    | Pairing. |
| BOND_STATE_BONDED  | 2    | Paired.  |


## SppOption<sup>8+</sup><sup>(deprecated)</sup><a name="SppOption"></a>

Defines the SPP configuration parameters.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.SppOption](js-apis-bluetoothManager.md#sppoption).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name    | Type               | Readable  | Writable  | Description         |
| ------ | ------------------- | ---- | ---- | ----------- |
| uuid   | string              | Yes   | Yes   | UUID of the SPP.|
| secure | boolean             | Yes   | Yes   | Whether it is a secure channel.   |
| type   | [SppType](#spptype) | Yes   | Yes   | Type of the SPP link.   |


## SppType<sup>8+</sup><sup>(deprecated)</sup><a name="SppType"></a>

Enumerates the SPP link types.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.SppType](js-apis-bluetoothManager.md#spptype).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name        | Value | Description           |
| ---------- | ---- | ------------- |
| SPP_RFCOMM | 0    | Radio frequency communication (RFCOMM) link type.|


## GattService<sup>(deprecated)</sup>

Defines the GATT service API parameters.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.GattService](js-apis-bluetoothManager.md#gattservice).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name             | Type                                    | Readable  | Writable  | Description                                      |
| --------------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| serviceUuid     | string                                   | Yes   | Yes   | UUID of the service, for example, **00001888-0000-1000-8000-00805f9b34fb**.|
| isPrimary       | boolean                                  | Yes   | Yes   | Whether the service is a primary service. The value **true** means a primary service.               |
| characteristics | Array&lt;[BLECharacteristic](#blecharacteristic)&gt; | Yes   | Yes   | List of characteristics of the service.                            |
| includeServices | Array&lt;[GattService](#gattservice)&gt; | Yes   | Yes   | Services on which the service depends.                            |


## BLECharacteristic<sup>(deprecated)</sup>

Defines the characteristic API parameters.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.BLECharacteristic](js-apis-bluetoothManager.md#blecharacteristic).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                 | Type                                    | Readable  | Writable  | Description                                      |
| ------------------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| serviceUuid         | string                                   | Yes   | Yes   | UUID of the service, for example, **00001888-0000-1000-8000-00805f9b34fb**.|
| characteristicUuid  | string                                   | Yes   | Yes   | UUID of the characteristic, for example, **00002a11-0000-1000-8000-00805f9b34fb**.|
| characteristicValue | ArrayBuffer                              | Yes   | Yes   | Binary value of the characteristic.                              |
| descriptors         | Array&lt;[BLEDescriptor](#bledescriptor)&gt; | Yes   | Yes   | List of descriptors of the characteristic.                             |


## BLEDescriptor<sup>(deprecated)</sup>

Defines the descriptor API parameters.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.BLEDescriptor](js-apis-bluetoothManager.md#bledescriptor).

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
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.NotifyCharacteristic](js-apis-bluetoothManager.md#notifycharacteristic).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                 | Type       | Readable  | Writable  | Description                                      |
| ------------------- | ----------- | ---- | ---- | ---------------------------------------- |
| serviceUuid         | string      | Yes   | Yes   | UUID of the service, for example, **00001888-0000-1000-8000-00805f9b34fb**.|
| characteristicUuid  | string      | Yes   | Yes   | UUID of the characteristic, for example, **00002a11-0000-1000-8000-00805f9b34fb**.|
| characteristicValue | ArrayBuffer | Yes   | Yes   | Binary value of the characteristic.                              |
| confirm             | boolean     | Yes   | Yes   | Whether the notification needs to be confirmed by the remote end. For a notification, set it to **true**. In this case, the remote end must confirm the receipt of the notification. For an indication, set it to **false**. In this case, the remote end does not need to confirm the receipt of the notification.|


## CharacteristicReadReq<sup>(deprecated)</sup>

Defines the parameters of the **CharacteristicReadReq** event received by the server.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.CharacteristicReadRequest](js-apis-bluetoothManager.md#characteristicreadrequest).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type  | Readable  | Writable  | Description                                      |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | Yes   | No   | Address of the remote device that sends the **CharacteristicReadReq** event, for example, XX:XX:XX:XX:XX:XX.|
| transId            | number | Yes   | No   | Transmission ID of the read request. The response returned by the server must use the same transmission ID.      |
| offset             | number | Yes   | No   | Position from which the characteristic value is read. For example, **k** means to read from the kth byte. The response returned by the server must use the same offset.|
| characteristicUuid | string | Yes   | No   | UUID of the characteristic, for example, **00002a11-0000-1000-8000-00805f9b34fb**.|
| serviceUuid        | string | Yes   | No   | UUID of the service, for example, **00001888-0000-1000-8000-00805f9b34fb**.|


## CharacteristicWriteReq<sup>(deprecated)</sup>

Defines the parameters of the **CharacteristicWriteReq** event received by the server.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.CharacteristicWriteRequest](js-apis-bluetoothManager.md#characteristicwriterequest).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type  | Readable  | Writable  | Description                                      |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | Yes   | No   | Address of the remote device that sends the **CharacteristicWriteReq** event, for example, XX:XX:XX:XX:XX:XX.|
| transId            | number | Yes   | No   | Transmission ID of the write request. The response returned by the server must use the same transmission ID.      |
| offset             | number | Yes   | No   | Start position for writing the characteristic value. For example, **k** means to write from the kth byte. The response returned by the server must use the same offset.|
| descriptorUuid     | string | Yes   | No   | UUID of the descriptor, for example, **00002902-0000-1000-8000-00805f9b34fb**.|
| characteristicUuid | string | Yes   | No   | UUID of the characteristic, for example, **00002a11-0000-1000-8000-00805f9b34fb**.|
| serviceUuid        | string | Yes   | No   | UUID of the service, for example, **00001888-0000-1000-8000-00805f9b34fb**.|


## DescriptorReadReq<sup>(deprecated)</sup>

Defines the parameters of the **DescriptorReadReq** event received by the server.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.DescriptorReadRequest](js-apis-bluetoothManager.md#descriptorreadrequest).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Type  | Readable  | Writable  | Description                                      |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | Yes   | No   | Address of the remote device that sends a **DescriptorReadReq** event, for example, XX:XX:XX:XX:XX:XX.|
| transId            | number | Yes   | No   | Transmission ID of the read request. The response returned by the server must use the same transmission ID.      |
| offset             | number | Yes   | No   | Position from which the descriptor is read. For example, **k** means to read from the kth byte. The response returned by the server must use the same offset.|
| descriptorUuid     | string | Yes   | No   | UUID of the descriptor, for example, **00002902-0000-1000-8000-00805f9b34fb**.|
| characteristicUuid | string | Yes   | No   | UUID of the characteristic, for example, **00002a11-0000-1000-8000-00805f9b34fb**.|
| serviceUuid        | string | Yes   | No   | UUID of the service, for example, **00001888-0000-1000-8000-00805f9b34fb**.|


## DescriptorWriteReq<sup>(deprecated)</sup>

Defines the parameters of the **DescriptorWriteReq** event received by the server.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.DescriptorWriteRequest](js-apis-bluetoothManager.md#descriptorwriterequest).

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
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.ServerResponse](js-apis-bluetoothManager.md#serverresponse).

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
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.BLEConnectChangedState](js-apis-bluetoothManager.md#bleconnectchangedstate).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name    | Type                                         | Readable| Writable| Description                                         |
| -------- | ------------------------------------------------- | ---- | ---- | --------------------------------------------- |
| deviceId | string                                            | Yes  | No  | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|
| state    | [ProfileConnectionState](#profileconnectionstate) | Yes  | Yes  | BLE connection state.                      |


## ProfileConnectionState<sup>(deprecated)</sup>

Enumerates the profile connection states.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.ProfileConnectionState](js-apis-bluetoothManager.md#profileconnectionstate).

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
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.ScanFilter](js-apis-bluetoothManager.md#scanfilter).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                                    | Type   | Readable| Writable| Description                                                        |
| ---------------------------------------- | ----------- | ---- | ---- | ------------------------------------------------------------ |
| deviceId                                 | string      | Yes  | Yes  | Address of the BLE device to filter, for example, XX:XX:XX:XX:XX:XX.          |
| name                                     | string      | Yes  | Yes  | Name of the BLE device to filter.                                       |
| serviceUuid                              | string      | Yes  | Yes  | Service UUID of the device to filter, for example, **00001888-0000-1000-8000-00805f9b34fb**.|


## ScanOptions<sup>(deprecated)</sup>

Defines the scan configuration parameters.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.ScanOptions](js-apis-bluetoothManager.md#scanoptions).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name       | Type                   | Readable  | Writable  | Description                                    |
| --------- | ----------------------- | ---- | ---- | -------------------------------------- |
| interval  | number                  | Yes   | Yes   | Delay in reporting the scan result. The default value is **0**.                   |
| dutyMode  | [ScanDuty](#scanduty)   | Yes   | Yes   | Scan duty. The default value is **SCAN_MODE_LOW_POWER**.       |
| matchMode | [MatchMode](#matchmode) | Yes   | Yes   | Hardware filtering match mode. The default value is **MATCH_MODE_AGGRESSIVE**.|


## ScanDuty<sup>(deprecated)</sup>

Enumerates the scan duty options.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.ScanDuty](js-apis-bluetoothManager.md#scanduty).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                   | Value | Description          |
| --------------------- | ---- | ------------ |
| SCAN_MODE_LOW_POWER   | 0    | Low-power mode, which is the default value.|
| SCAN_MODE_BALANCED    | 1    | Balanced mode.     |
| SCAN_MODE_LOW_LATENCY | 2    | Low-latency mode.    |


## MatchMode<sup>(deprecated)</sup>

Enumerates the hardware match modes of BLE scan filters.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.MatchMode](js-apis-bluetoothManager.md#matchmode).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                   | Value | Description                                      |
| --------------------- | ---- | ---------------------------------------- |
| MATCH_MODE_AGGRESSIVE | 1    | Hardware reports the scan result with a lower threshold of signal strength and few number of matches in a duration. This is the default value.|
| MATCH_MODE_STICKY     | 2    | Hardware reports the scan result with a higher threshold of signal strength and sightings.      |


## ScanResult<sup>(deprecated)</sup>

Defines the scan result.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.ScanResult](js-apis-bluetoothManager.md#scanresult).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type       | Readable  | Writable  | Description                                |
| -------- | ----------- | ---- | ---- | ---------------------------------- |
| deviceId | string      | Yes   | No   | Address of the scanned device, for example, XX:XX:XX:XX:XX:XX.|
| rssi     | number      | Yes   | No   | RSSI of the device.                   |
| data     | ArrayBuffer | Yes   | No   | Advertisement packets sent by the device.                   |


## BluetoothState<sup>(deprecated)</sup>

Enumerates the Bluetooth states.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.BluetoothState](js-apis-bluetoothManager.md#bluetoothstate).

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
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.AdvertiseSetting](js-apis-bluetoothManager.md#advertisesetting).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name         | Type   | Readable  | Writable  | Description                                      |
| ----------- | ------- | ---- | ---- | ---------------------------------------- |
| interval    | number  | Yes   | Yes   | Interval for BLE advertising. The minimum value is **32** slots (20 ms). The maximum value is **16384** slots. The default value is **1600** slots (1s).|
| txPower     | number  | Yes   | Yes   | Transmit power, in dBm. The value range is -127 to 1. The default value is **-7**.  |
| connectable | boolean | Yes   | Yes   | Whether the advertisement is connectable. The default value is **true**.                  |


## AdvertiseData<sup>(deprecated)</sup>

Defines the content of a BLE advertisement packet.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.AdvertiseData](js-apis-bluetoothManager.md#advertisedata).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name             | Type                                    | Readable  | Writable  | Description                         |
| --------------- | ---------------------------------------- | ---- | ---- | --------------------------- |
| serviceUuids    | Array&lt;string&gt;                      | Yes   | Yes   | List of service UUIDs to broadcast.|
| manufactureData | Array&lt;[ManufactureData](#manufacturedata)&gt; | Yes   | Yes   | List of manufacturers to broadcast.          |
| serviceData     | Array&lt;[ServiceData](#servicedata)&gt; | Yes   | Yes   | List of service data to broadcast.              |


## ManufactureData<sup>(deprecated)</sup>

Defines the content of a BLE advertisement packet.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.ManufactureData](js-apis-bluetoothManager.md#manufacturedata).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name              | Type               | Readable  | Writable  | Description                |
| ---------------- | ------------------- | ---- | ---- | ------------------ |
| manufactureId    | number  | Yes   | Yes   | Manufacturer ID allocated by the Bluetooth SIG.|
| manufactureValue | ArrayBuffer         | Yes   | Yes   | Manufacturer data.    |


## ServiceData<sup>(deprecated)</sup>

Defines the service data contained in an advertisement packet.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [bluetoothManager.ServiceData](js-apis-bluetoothManager.md#servicedata).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name          | Type       | Readable  | Writable  | Description        |
| ------------ | ----------- | ---- | ---- | ---------- |
| serviceUuid  | string      | Yes   | Yes   | Service UUID.|
| serviceValue | ArrayBuffer | Yes   | Yes   | Service data.   |


## PinRequiredParam<sup>8+</sup><sup>(deprecated)</sup><a name="PinRequiredParam"></a>

Defines the pairing request parameters.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.PinRequiredParam](js-apis-bluetoothManager.md#pinrequiredparam).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type  | Readable  | Writable  | Description         |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId | string | Yes   | No   | ID of the device to pair.|
| pinCode  | string | Yes   | No   | Key for the device pairing.  |


## BondStateParam<sup>8+</sup><sup>(deprecated)</sup><a name="BondStateParam"></a>

Defines the pairing state parameters.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.BondStateParam](js-apis-bluetoothManager.md#bondstateparam).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name      | Type  | Readable  | Writable  | Description         |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId | string      | Yes   | No   | ID of the device to pair.|
| state    | BondState   | Yes   | No   | State of the device.|


## StateChangeParam<sup>8+</sup><sup>(deprecated)</sup><a name="StateChangeParam"></a>

Defines the profile state change parameters.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.StateChangeParam](js-apis-bluetoothManager.md#statechangeparam).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name    | Type                                         | Readable| Writable| Description                           |
| -------- | ------------------------------------------------- | ---- | ---- | ------------------------------- |
| deviceId | string                                            | Yes  | No  | Address of a Bluetooth device.             |
| state    | [ProfileConnectionState](#profileconnectionstate) | Yes  | No  | Profile connection state of the device.|


## DeviceClass<sup>8+</sup><sup>(deprecated)</sup><a name="DeviceClass"></a>

Defines the class of a Bluetooth device.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.DeviceClass](js-apis-bluetoothManager.md#deviceclass).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name             | Type                               | Readable  | Writable  | Description              |
| --------------- | ----------------------------------- | ---- | ---- | ---------------- |
| majorClass      | [MajorClass](#majorclass)           | Yes   | No   | Major classes of Bluetooth devices.  |
| majorMinorClass | [MajorMinorClass](#majorminorclass) | Yes   | No   | Major and minor classes of Bluetooth devices.|
| classOfDevice   | number                              | Yes   | No   | Class of the device.         |



## MajorClass<sup>8+</sup><sup>(deprecated)</sup><a name="MajorClass"></a>

Enumerates the major classes of Bluetooth devices.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.MajorClass](js-apis-bluetoothManager.md#majorclass).

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


## MajorMinorClass<sup>8+</sup><sup>(deprecated)</sup><a name="MajorMinorClass"></a>

Enumerates the major and minor classes of Bluetooth devices.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.MajorMinorClass](js-apis-bluetoothManager.md#majorminorclass).

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
| HEALTH_PEAK_FLOW_MOITOR                  | 0x0928 | Hygrometer.     |
| HEALTH_MEDICATION_MONITOR                | 0x092C | Medication monitor.   |
| HEALTH_KNEE_PROSTHESIS                   | 0x0930 | Prosthetic knee.    |
| HEALTH_ANKLE_PROSTHESIS                  | 0x0934 | Prosthetic ankle.    |
| HEALTH_GENERIC_HEALTH_MANAGER            | 0x0938 | Generic health management device.    |
| HEALTH_PERSONAL_MOBILITY_DEVICE          | 0x093C | Personal mobility device.    |


## PlayingState<sup>8+</sup><sup>(deprecated)</sup><a name="PlayingState"></a>

Enumerates the A2DP playing states.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.PlayingState](js-apis-bluetoothManager.md#playingstate).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name               | Value   | Description     |
| ----------------- | ------ | ------- |
| STATE_NOT_PLAYING | 0x0000 | Not playing. |
| STATE_PLAYING     | 0x0001 | Playing.|


## ProfileId<sup>8+</sup><sup>(deprecated)</sup><a name="ProfileId"></a>

Enumerates the Bluetooth profiles. API version 9 is added with **PROFILE_HID_HOST** and **PROFILE_PAN_NETWORK**.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [bluetoothManager.ProfileId](js-apis-bluetoothManager.md#profileid).

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                              | Value   | Description             |
| -------------------------------- | ------ | --------------- |
| PROFILE_A2DP_SOURCE              | 1 | A2DP profile.|
| PROFILE_HANDS_FREE_AUDIO_GATEWAY | 4 | HFP profile. |
