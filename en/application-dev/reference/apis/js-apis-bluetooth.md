> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The Bluetooth module provides Classic Bluetooth capabilities and Bluetooth Low Energy (BLE) scan and advertising.


## Modules to Import

```
import bluetooth from '@ohos.bluetooth';
```


## Required Permissions

ohos.permission.USE_BLUETOOTH

ohos.permission.MANAGE_BLUETOOTH

ohos.permission.DISCOVER_BLUETOOTH

ohos.permission.LOCATION


## bluetooth.enableBluetooth

enableBluetooth(): boolean

Enables Bluetooth.

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;Bluetooth&nbsp;is&nbsp;enabled;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
let enable = bluetooth.enableBluetooth();
```


## bluetooth.disableBluetooth

disableBluetooth(): boolean

Disables Bluetooth.

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;Bluetooth&nbsp;is&nbsp;disabled;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
let disable = bluetooth.disableBluetooth();
```


## bluetooth.getLocalName

getLocalName(): string

Obtains the name of the local Bluetooth device.

**Return values:**

| Type | Description |
| -------- | -------- |
| string | Name&nbsp;of&nbsp;the&nbsp;local&nbsp;Bluetooth&nbsp;device. |

**Example:**

```
let localName = bluetooth.getLocalName();
```


## bluetooth.getState

getState(): BluetoothState

Obtains the Bluetooth state.

**Return values:**

| Type | Description |
| -------- | -------- |
| [BluetoothState](#bluetoothstate) | Bluetooth&nbsp;state&nbsp;obtained. |

**Example:**

```
let state = bluetooth.getState();
```


## bluetooth.getBtConnectionState

getBtConnectionState(): ProfileConnectionState

Obtains the profile connection state of this Bluetooth device.

**Return values:**

| Type | Description |
| -------- | -------- |
| [ProfileConnectionState](#profileconnectionstate) | Profile&nbsp;connection&nbsp;state&nbsp;obtained. |

**Example:**

```
let connectionState = bluetooth.getBtConnectionState();
```


## bluetooth.setLocalName

setLocalName(name: string): boolean

Sets the name of the local Bluetooth device.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| name | string | Yes | Bluetooth&nbsp;device&nbsp;name&nbsp;to&nbsp;be&nbsp;set.&nbsp;It&nbsp;cannot&nbsp;exceed&nbsp;128&nbsp;characters. |

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
let ret = bluetooth.setLocalName('device_name');
```


## bluetooth.pairDevice

pairDevice(deviceId: string): boolean

Initiates Bluetooth pairing.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| deviceId | string | Yes | Address&nbsp;of&nbsp;the&nbsp;peer&nbsp;device&nbsp;to&nbsp;pair,&nbsp;for&nbsp;example,&nbsp;**8F:8F:8E:8E:6D:6D**. |

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
// The actual address can be scanned.
let result = bluetooth.pairDevice("8F:8F:8E:8E:6D:6D");
```


## bluetooth.getPairedDevices

getPairedDevices(): Array&lt;string&gt;

Obtains the Bluetooth pairing list.

**Return values:**

| Type | Description |
| -------- | -------- |
| Array&lt;string&gt; | List&nbsp;of&nbsp;the&nbsp;addresses&nbsp;of&nbsp;the&nbsp;paired&nbsp;Bluetooth&nbsp;devices. |

**Example:**

```
let devices = bluetooth.getPairedDevices();
```


## bluetooth.setBluetoothScanMode

setBluetoothScanMode(mode: ScanMode, duration: number): boolean

Sets the Bluetooth scan mode so that the device can be discovered by a peer device.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| mode | [ScanMode](#scanmode) | Yes | Bluetooth&nbsp;scan&nbsp;mode. |
| duration | number | Yes | Duration&nbsp;(in&nbsp;seconds)&nbsp;in&nbsp;which&nbsp;the&nbsp;device&nbsp;can&nbsp;be&nbsp;discovered.&nbsp;The&nbsp;value&nbsp;**0**&nbsp;indicates&nbsp;unlimited&nbsp;time. |

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
// The device can be discovered and connected only when the discoverable and connectable mode is used.
let result = bluetooth.setBluetoothScanMode(ScanMode.SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE, 100);
```


## bluetooth.getBluetoothScanMode

getBluetoothScanMode(): ScanMode

Obtains the Bluetooth scan mode.

**Return values:**

| Type | Description |
| -------- | -------- |
| [ScanMode](#scanmode) | Bluetooth&nbsp;scan&nbsp;mode&nbsp;obtained. |

**Example:**

```
let scanMode = bluetooth.getBluetoothScanMode();
```


## bluetooth.startBluetoothDiscovery

startBluetoothDiscovery(): boolean

Starts Bluetooth scan to discover peer devices.

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
let deviceId;
function onReceiveEvent(data) {
    deviceId = data;
}
bluetooth.on('bluetoothDeviceFind', onReceiveEvent);
let result = bluetooth.startBluetoothDiscovery();
```


## bluetooth.stopBluetoothDiscovery

stopBluetoothDiscovery(): boolean

Stops Bluetooth scan.

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
let result = bluetooth.stopBluetoothDiscovery();
```


## bluetooth.setDevicePairingConfirmation

setDevicePairingConfirmation(device: string, accept: boolean): boolean

Sets the device pairing confirmation.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| device | string | Yes | Address&nbsp;of&nbsp;the&nbsp;peer&nbsp;device,&nbsp;for&nbsp;example,&nbsp;**8F:8F:8E:8E:6D:6D**. |
| accept | boolean | Yes | Whether&nbsp;to&nbsp;accept&nbsp;the&nbsp;pairing&nbsp;request.&nbsp;The&nbsp;value&nbsp;**true**&nbsp;means&nbsp;to&nbsp;accept&nbsp;the&nbsp;pairing&nbsp;request,&nbsp;and&nbsp;the&nbsp;value&nbsp;**false**&nbsp;means&nbsp;the&nbsp;opposite. |

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
// Subscribe to the pinRequired event and configure the pairing confirmation after receiving a pairing request from the peer device.
function onReceivePinRequiredEvent(data) { // data is the input parameter for the pairing request.
    console.info('pin required  = '+ JSON.stringify(data));
    bluetooth.setDevicePairingConfirmation(data.deviceId, true);
}
bluetooth.on("pinRequired", onReceivePinRequiredEvent);
```


## bluetooth.on('bluetoothDeviceFind')

on(type: "bluetoothDeviceFind", callback: Callback&lt;Array&lt;string&gt;&gt;): void

Subscribes to the Bluetooth device discovery events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**bluetoothDeviceFind**&nbsp;indicates&nbsp;an&nbsp;event&nbsp;reported&nbsp;when&nbsp;a&nbsp;Bluetooth&nbsp;device&nbsp;is&nbsp;discovered. |
| callback | Callback&lt;Array&lt;string&gt;&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;the&nbsp;discovered&nbsp;devices.&nbsp;You&nbsp;need&nbsp;to&nbsp;implement&nbsp;this&nbsp;callback. |

**Return values:**

None.

**Example:**

```
function onReceiveEvent(data) { // data is a set of Bluetooth device addresses.
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
bluetooth.on('bluetoothDeviceFind', onReceiveEvent);
```


## bluetooth.off('bluetoothDeviceFind')

off(type: "bluetoothDeviceFind", callback?: Callback&lt;Array&lt;string&gt;&gt;): void

Unsubscribes from the Bluetooth device discovery events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**bluetoothDeviceFind**&nbsp;indicates&nbsp;an&nbsp;event&nbsp;reported&nbsp;when&nbsp;a&nbsp;Bluetooth&nbsp;device&nbsp;is&nbsp;discovered. |
| callback | Callback&lt;Array&lt;string&gt;&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;report&nbsp;the&nbsp;discovered&nbsp;devices.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;this&nbsp;method&nbsp;unsubscribes&nbsp;from&nbsp;all&nbsp;callbacks&nbsp;corresponding&nbsp;to&nbsp;**type**. |

**Return values:**

None.

**Example:**

```
function onReceiveEvent(data) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
bluetooth.on('bluetoothDeviceFind', onReceiveEvent);
bluetooth.off('bluetoothDeviceFind', onReceiveEvent);
```


## bluetooth.on('pinRequired')

on(type: "pinRequired", callback: Callback&lt;PinRequiredParam&gt;): void

Subscribes to the pairing request events of the peer Bluetooth device.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**pinRequired**&nbsp;indicates&nbsp;a&nbsp;pairing&nbsp;request&nbsp;event. |
| callback | Callback&lt;[PinRequiredParam](#pinrequiredparam)&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;the&nbsp;pairing&nbsp;request.&nbsp;You&nbsp;need&nbsp;to&nbsp;implement&nbsp;this&nbsp;callback. |

**Return values:**

None.

**Example:**

```
function onReceiveEvent(data) { // data is the pairing request parameter.
    console.info('pin required = '+ JSON.stringify(data));
}
bluetooth.on('pinRequired', onReceiveEvent);
```


## bluetooth.off('pinRequired')

off(type: "pinRequired", callback?: Callback&lt;PinRequiredParam&gt;): void

Unsubscribes from the pairing request events of the peer Bluetooth device.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**pinRequired**&nbsp;indicates&nbsp;a&nbsp;pairing&nbsp;request&nbsp;event. |
| callback | Callback&lt;[PinRequiredParam](#pinrequiredparam)&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;report&nbsp;the&nbsp;Bluetooth&nbsp;pairing&nbsp;request.&nbsp;The&nbsp;input&nbsp;parameter&nbsp;is&nbsp;the&nbsp;pairing&nbsp;request&nbsp;parameter.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;this&nbsp;method&nbsp;unsubscribes&nbsp;from&nbsp;all&nbsp;callbacks&nbsp;corresponding&nbsp;to&nbsp;**type**. |

**Return values:**

None.

**Example:**

```
function onReceiveEvent(data) {
    console.info('pin required = '+ JSON.stringify(data));
}
bluetooth.on('pinRequired', onReceiveEvent);
bluetooth.off('pinRequired', onReceiveEvent);
```


## bluetooth.on('bondStateChange')

on(type: "bondStateChange", callback: Callback&lt;BondState&gt;): void

Subscribes to the Bluetooth pairing state change events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**bondStateChange**&nbsp;indicates&nbsp;a&nbsp;Bluetooth&nbsp;pairing&nbsp;state&nbsp;change&nbsp;event. |
| callback | Callback&lt;[BondState](#bondstate)&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;the&nbsp;pairing&nbsp;state.&nbsp;You&nbsp;need&nbsp;to&nbsp;implement&nbsp;this&nbsp;callback. |

**Return values:**

None.

**Example:**

```
function onReceiveEvent(data) { // data, as the input parameter of the callback, indicates the pairing state.
    console.info('pair state = '+ JSON.stringify(data));
}
bluetooth.on('bondStateChange', onReceiveEvent);
```


## bluetooth.off('bondStateChange')

off(type: "bondStateChange", callback?: Callback&lt;BondState&gt;): void

Unsubscribes from the Bluetooth pairing state change events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**bondStateChange**&nbsp;indicates&nbsp;a&nbsp;Bluetooth&nbsp;pairing&nbsp;state&nbsp;change&nbsp;event. |
| callback | Callback&lt;[BondState](#bondstate)&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;report&nbsp;the&nbsp;change&nbsp;of&nbsp;the&nbsp;Bluetooth&nbsp;pairing&nbsp;state.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;this&nbsp;method&nbsp;unsubscribes&nbsp;from&nbsp;all&nbsp;callbacks&nbsp;corresponding&nbsp;to&nbsp;**type**. |

**Return values:**

None.

**Example:**

```
function onReceiveEvent(data) {
    console.info('bond state = '+ JSON.stringify(data));
}
bluetooth.on('bondStateChange', onReceiveEvent);
bluetooth.off('bondStateChange', onReceiveEvent);
```


## bluetooth.on('stateChange')

on(type: "stateChange", callback: Callback&lt;BluetoothState&gt;): void

Subscribes to the Bluetooth connection state change events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**stateChange**&nbsp;indicates&nbsp;a&nbsp;Bluetooth&nbsp;connection&nbsp;state&nbsp;change&nbsp;event. |
| callback | Callback&lt;[BluetoothState](#bluetoothstate)&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;the&nbsp;Bluetooth&nbsp;connection&nbsp;state.&nbsp;You&nbsp;need&nbsp;to&nbsp;implement&nbsp;this&nbsp;callback. |

**Return values:**

None.

**Example:**

```
function onReceiveEvent(data) {
    console.info('bluetooth state = '+ JSON.stringify(data));
}
bluetooth.on('stateChange', onReceiveEvent);
```


## bluetooth.off('stateChange')

off(type: "stateChange", callback?: Callback&lt;BluetoothState&gt;): void

Unsubscribes from the Bluetooth connection state change events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**stateChange**&nbsp;indicates&nbsp;a&nbsp;Bluetooth&nbsp;connection&nbsp;state&nbsp;change&nbsp;event. |
| callback | Callback&lt;[BluetoothState](#bluetoothstate)&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;report&nbsp;the&nbsp;Bluetooth&nbsp;connection&nbsp;state.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;this&nbsp;method&nbsp;unsubscribes&nbsp;from&nbsp;all&nbsp;callbacks&nbsp;corresponding&nbsp;to&nbsp;**type**. |

**Return values:**

None.

**Example:**

```
function onReceiveEvent(data) {
    console.info('bluetooth state = '+ JSON.stringify(data));
}
bluetooth.on('stateChange', onReceiveEvent);
bluetooth.off('stateChange', onReceiveEvent);
```


## bluetooth.sppListen

sppListen(name: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void

Creates a server listening socket.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| name | string | Yes | Service&nbsp;name. |
| option | [SppOption](#sppoption) | Yes | Serial&nbsp;port&nbsp;profile&nbsp;(SPP)&nbsp;listening&nbsp;configuration. |
| callback | AsyncCallback&lt;number&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;the&nbsp;server&nbsp;socket&nbsp;ID. |

**Example:**

```
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


## bluetooth.sppAccept

sppAccept(serverSocket: number, callback: AsyncCallback&lt;number&gt;): void

Listens for a connection to be made to this socket from the client and accepts it.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| serverSocket | number | Yes | Server&nbsp;socket&nbsp;ID. |
| callback | AsyncCallback&lt;number&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;the&nbsp;client&nbsp;socket&nbsp;ID. |

**Example:**

```
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


## bluetooth.sppConnect

sppConnect(device: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void

Initiates an SPP connection to a peer device from the client.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| device | string | Yes | Address&nbsp;of&nbsp;the&nbsp;peer&nbsp;device,&nbsp;for&nbsp;example,&nbsp;**8F:8F:8E:8E:6D:6D**. |
| option | [SppOption](#sppoption) | Yes | Configuration&nbsp;for&nbsp;connecting&nbsp;to&nbsp;the&nbsp;SPP&nbsp;client. |
| callback | AsyncCallback&lt;number&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;the&nbsp;client&nbsp;socket&nbsp;ID. |

**Example:**

```
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
bluetooth.sppConnect('8F:8F:8E:8E:6D:6D', sppOption, clientSocket);
```


## bluetooth.sppCloseServerSocket

sppCloseServerSocket(socket: number): void

Closes the listening socket of the server.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| socket | number | Yes | ID&nbsp;of&nbsp;the&nbsp;listening&nbsp;socket&nbsp;on&nbsp;the&nbsp;server.&nbsp;The&nbsp;ID&nbsp;is&nbsp;obtained&nbsp;by&nbsp;**sppListen**. |

**Example:**

```
bluetooth.sppCloseServerSocket(serverNumber);
```


## bluetooth.sppCloseClientSocket

sppCloseClientSocket(socket: number): void

Closes the client socket.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| socket | number | Yes | Client&nbsp;socket&nbsp;ID,&nbsp;which&nbsp;is&nbsp;obtained&nbsp;by&nbsp;**sppAccept**&nbsp;or&nbsp;**sppConnect**. |

**Example:**

```
bluetooth.sppCloseClientSocket(clientNumber);
```


## bluetooth.sppWrite

sppWrite(clientSocket: number, data: ArrayBuffer): boolean

Writes data to the peer device through the socket.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| clientSocket | number | Yes | Client&nbsp;socket&nbsp;ID,&nbsp;which&nbsp;is&nbsp;obtained&nbsp;by&nbsp;**sppAccept**&nbsp;or&nbsp;**sppConnect**. |
| data | ArrayBuffer | Yes | Data&nbsp;to&nbsp;write. |

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
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


## bluetooth.on('sppRead')

on(type: "sppRead", clientSocket: number, callback: Callback&lt;ArrayBuffer&gt;): void

Subscribes to the SPP read request events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**sppRead**&nbsp;indicates&nbsp;an&nbsp;SPP&nbsp;read&nbsp;request&nbsp;event. |
| clientSocket | number | Yes | Client&nbsp;socket&nbsp;ID,&nbsp;which&nbsp;is&nbsp;obtained&nbsp;by&nbsp;**sppAccept**&nbsp;or&nbsp;**sppConnect**. |
| callback | Callback&lt;ArrayBuffer&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;the&nbsp;data&nbsp;read. |

**Return values:**

None.

**Example:**

```
function dataRead(dataBuffer) {
  let data = new Uint8Array(dataBuffer);
  console.log('bluetooth data is: ' + data[0]);
}
bluetooth.on('sppRead', clientNumber, dataRead);
```


## bluetooth.off('sppRead')

off(type: "sppRead", clientSocket: number, callback?: Callback&lt;ArrayBuffer&gt;): void

Unsubscribes from the SPP read request events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**sppRead**&nbsp;indicates&nbsp;an&nbsp;SPP&nbsp;read&nbsp;request&nbsp;event. |
| clientSocket | number | Yes | Client&nbsp;socket&nbsp;ID,&nbsp;which&nbsp;is&nbsp;obtained&nbsp;by&nbsp;**sppAccept**&nbsp;or&nbsp;**sppConnect**. |
| callback | Callback&lt;ArrayBuffer&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;report&nbsp;an&nbsp;SPP&nbsp;read&nbsp;request&nbsp;event.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;this&nbsp;method&nbsp;unsubscribes&nbsp;from&nbsp;all&nbsp;callbacks&nbsp;corresponding&nbsp;to&nbsp;**type**. |

**Return values:**

None.

**Example:**

```
bluetooth.off('sppRead', clientNumber);
```


## bluetooth.BLE

### bluetooth.BLE.createGattServer

createGattServer(): GattServer

Creates a **GattServer** instance.

**Return values:**

| Type | Description |
| -------- | -------- |
| [GattServer](#gattserver) | **GattServer**&nbsp;instance&nbsp;created.&nbsp;Before&nbsp;using&nbsp;a&nbsp;method&nbsp;of&nbsp;the&nbsp;server,&nbsp;you&nbsp;must&nbsp;create&nbsp;a&nbsp;**GattSever**&nbsp;instance. |

**Example:**

```
let gattServer = bluetooth.BLE.createGattServer();
```


### bluetooth.BLE.createGattClientDevice

createGattClientDevice(deviceId: string): GattClientDevice

Creates a **GattClientDevice** instance.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| deviceId | string | Yes | Address&nbsp;of&nbsp;the&nbsp;peer&nbsp;device,&nbsp;for&nbsp;example,&nbsp;**8F:8F:8E:8E:6D:6D**. |

**Return values:**

| Type | Description |
| -------- | -------- |
| [GattClientDevice](#gattclientdevice) | **GattClientDevice**&nbsp;instance&nbsp;created.&nbsp;Before&nbsp;using&nbsp;a&nbsp;method&nbsp;of&nbsp;the&nbsp;client,&nbsp;you&nbsp;must&nbsp;create&nbsp;a&nbsp;**GattClientDevice**&nbsp;instance. |

**Example:**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
```


### bluetooth.BLE.getConnectedBLEDevices

getConnectedBLEDevices(): Array&lt;string&gt;

Obtains the BLE devices connected to this device.

**Return values:**

| Type | Description |
| -------- | -------- |
| Array&lt;string&gt; | Addresses&nbsp;of&nbsp;the&nbsp;BLE&nbsp;devices&nbsp;connected&nbsp;to&nbsp;this&nbsp;device. |

**Example:**

```
let result = bluetooth.BLE.getConnectedBLEDevices();
```


### bluetooth.BLE.startBLEScan

startBLEScan(filters: Array&lt;ScanFilter&gt;, options?: ScanOptions): void

Starts a BLE scan.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| filters | Array&lt;[ScanFilter](#scanfilter)&gt; | Yes | Criteria&nbsp;for&nbsp;filtering&nbsp;the&nbsp;scan&nbsp;result.&nbsp;Set&nbsp;this&nbsp;parameter&nbsp;to&nbsp;**null**&nbsp;if&nbsp;you&nbsp;do&nbsp;not&nbsp;want&nbsp;to&nbsp;filter&nbsp;the&nbsp;scan&nbsp;result. |
| options | [ScanOptions](#scanoptions) | No | Scan&nbsp;options. |

**Return values:**

None.

**Example:**

```
function onReceiveEvent(data) {
    console.info('BLE scan device find result = '+ JSON.stringify(data));
}
bluetooth.BLE.on("BLEDeviceFind", onReceiveEvent);
bluetooth.BLE.startBLEScan(
    [{
        deviceId:"8F:8F:8E:8E:6D:6D",
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


### bluetooth.BLE.stopBLEScan

stopBLEScan(): void

Stops the BLE scan.

**Return values:**

None.

**Example:**

```
bluetooth.BLE.stopBLEScan();
```


### bluetooth.BLE.on('BLEDeviceFind')

on(type: "BLEDeviceFind", callback: Callback&lt;Array&lt;ScanResult&gt;&gt;): void

Subscribe to the BLE device discovery events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**BLEDeviceFind**&nbsp;indicates&nbsp;an&nbsp;event&nbsp;reported&nbsp;when&nbsp;a&nbsp;BLE&nbsp;device&nbsp;is&nbsp;discovered. |
| callback | Callback&lt;Array&lt;[ScanResult](#scanresult)&gt;&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;the&nbsp;discovered&nbsp;devices.&nbsp;You&nbsp;need&nbsp;to&nbsp;implement&nbsp;this&nbsp;callback. |

**Return values:**

None.

**Example:**

```
function onReceiveEvent(data) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
bluetooth.BLE.on('BLEDeviceFind', onReceiveEvent);
```


### bluetooth.BLE.off('BLEDeviceFind')

off(type: "BLEDeviceFind", callback?: Callback&lt;Array&lt;ScanResult&gt;&gt;): void

Unsubscribes from the BLE device discovery events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**BLEDeviceFind**&nbsp;indicates&nbsp;an&nbsp;event&nbsp;reported&nbsp;when&nbsp;a&nbsp;BLE&nbsp;device&nbsp;is&nbsp;discovered. |
| callback | Callback&lt;Array&lt;[ScanResult](#scanresult)&gt;&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;report&nbsp;the&nbsp;discovered&nbsp;devices.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;this&nbsp;method&nbsp;unsubscribes&nbsp;from&nbsp;all&nbsp;callbacks&nbsp;corresponding&nbsp;to&nbsp;**type**. |

**Return values:**

None.

**Example:**

```
function onReceiveEvent(data) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
bluetooth.BLE.on('BLEDeviceFind', onReceiveEvent);
bluetooth.BLE.off('BLEDeviceFind', onReceiveEvent);
```


## GattServer

Implements the Generic Attribute Profile (GATT) server. Before using a method of this class, you need to create a **GattServer** instance using the **createGattServer()** method.


### startAdvertising

startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void

Starts BLE advertising.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| setting | [AdvertiseSetting](#advertisesetting) | Yes | Settings&nbsp;related&nbsp;to&nbsp;BLE&nbsp;advertising. |
| advData | [AdvertiseData](#advertisedata) | Yes | Content&nbsp;of&nbsp;the&nbsp;BLE&nbsp;advertisement&nbsp;packet. |
| advResponse | [AdvertiseData](#advertisedata) | No | Response&nbsp;to&nbsp;the&nbsp;BLE&nbsp;scan&nbsp;request. |

**Return values:**

None.

**Example:**

```
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


### stopAdvertising

stopAdvertising(): void

Stops BLE advertising.

**Return values:**

None.

**Example:**

```
let server = bluetooth.BLE.createGattServer();
server.stopAdvertising();
```


### addService

addService(service: GattService): boolean

Adds a service to this GATT server.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| service | [GattService](#gattservice) | Yes | Service&nbsp;to&nbsp;add. |

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
// Create descriptors.
let descriptors = [];
let arrayBuffer = new ArrayBuffer(8);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
let descriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00001830-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;

// Create characteristics.
let characteristics = [];
let arrayBufferC = new ArrayBuffer(8);
let cccV = new Uint8Array(arrayBufferC);
cccV[0] = 1;
let characteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
let characteristicN = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001821-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptorsN};
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


### removeService

removeService(serviceUuid: string): boolean

Removes a service from this GATT server.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| serviceUuid | string | Yes | Universally&nbsp;unique&nbsp;identifier&nbsp;(UUID)&nbsp;of&nbsp;the&nbsp;service&nbsp;to&nbsp;remove,&nbsp;for&nbsp;example,&nbsp;**00001810-0000-1000-8000-00805F9B34FB**. |

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
let server = bluetooth.BLE.createGattServer();
server.removeService('00001810-0000-1000-8000-00805F9B34FB');
```


### close

close(): void


Closes this GATT server to unregister it from the protocol stack. After this method is called, this [GattServer](#gattserver) instance cannot be used.

**Example:**

```
let server = bluetooth.BLE.createGattServer();
server.close();
```


### notifyCharacteristicChanged

notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): boolean

Notifies the connected client device when a characteristic value changes.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| deviceId | string | Yes | Address&nbsp;of&nbsp;the&nbsp;client&nbsp;device&nbsp;to&nbsp;notify,&nbsp;for&nbsp;example,&nbsp;**8F:8F:8E:8E:6D:6D**. |
| notifyCharacteristic | [NotifyCharacteristic](#notifycharacteristic) | Yes | New&nbsp;characteristic&nbsp;value. |

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
let notifyCharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001821-0000-1000-8000-00805F9B34FB', characteristicValue:  notifyCcc.characteristicValue, confirm: false};
let server = bluetooth.BLE.createGattServer();
server.notifyCharacteristicChanged('8F:8F:8E:8E:6D:6D', notifyCharacteristic);
```


### sendResponse

sendResponse(serverResponse: ServerResponse): boolean

Sends a response to a read or write request from the GATT client.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| serverResponse | [ServerResponse](#serverresponse) | Yes | Response&nbsp;returned&nbsp;by&nbsp;the&nbsp;GATT&nbsp;server. |

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
/* Send a response. */
let arrayBufferCCC = new ArrayBuffer(8);
let cccValue = new Uint8Array(arrayBufferCCC);
cccValue[0] = 1123;
let serverResponse = {
    "deviceId": "8F:8F:8E:8E:6D:6D",
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


### on('characteristicRead')

on(type: "characteristicRead", callback: Callback&lt;CharacteristicReadReq&gt;): void

Subscribes to the characteristic read request events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**characteristicRead**&nbsp;indicates&nbsp;a&nbsp;characteristic&nbsp;read&nbsp;request&nbsp;event. |
| callback | Callback&lt;[CharacteristicReadReq](#characteristicreadreq)&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;a&nbsp;characteristic&nbsp;read&nbsp;request&nbsp;from&nbsp;the&nbsp;GATT&nbsp;client. |

**Return values:**

None.

**Example:**

```
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


### off('characteristicRead')

off(type: "characteristicRead", callback?: Callback&lt;CharacteristicReadReq&gt;): void

Unsubscribes from the characteristic read request events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**characteristicRead**&nbsp;indicates&nbsp;a&nbsp;characteristic&nbsp;read&nbsp;request&nbsp;event. |
| callback | Callback&lt;[CharacteristicReadReq](#characteristicreadreq)&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;report&nbsp;a&nbsp;characteristic&nbsp;read&nbsp;request&nbsp;event.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;this&nbsp;method&nbsp;unsubscribes&nbsp;from&nbsp;all&nbsp;callbacks&nbsp;corresponding&nbsp;to&nbsp;**type**. |

**Return values:**

None.

**Example:**

```
let gattServer = bluetooth.BLE.createGattServer();
gattServer.off("characteristicRead");
```


### on('characteristicWrite')

on(type: "characteristicWrite", callback: Callback&lt;CharacteristicWriteReq&gt;): void

Subscribes to the characteristic write request events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**characteristicWrite**&nbsp;indicates&nbsp;a&nbsp;characteristic&nbsp;write&nbsp;request&nbsp;event. |
| callback | Callback&lt;[DescriptorWriteReq](#descriptorwritereq)&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;a&nbsp;characteristic&nbsp;write&nbsp;request&nbsp;from&nbsp;the&nbsp;GATT&nbsp;client. |

**Return values:**

None.

**Example:**

```
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


### off('characteristicWrite')

off(type: "characteristicWrite", callback?: Callback&lt;CharacteristicWriteReq&gt;): void

Unsubscribes from the characteristic write request events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**characteristicWrite**&nbsp;indicates&nbsp;a&nbsp;characteristic&nbsp;write&nbsp;request&nbsp;event. |
| callback | Callback&lt;[CharacteristicWriteReq](#characteristicwritereq)&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;report&nbsp;a&nbsp;characteristic&nbsp;write&nbsp;request&nbsp;event.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;this&nbsp;method&nbsp;unsubscribes&nbsp;from&nbsp;all&nbsp;callbacks&nbsp;corresponding&nbsp;to&nbsp;**type**. |

**Return values:**

None.

**Example:**

```
let gattServer = bluetooth.BLE.createGattServer();
gattServer.off("characteristicWrite");
```


### on('descriptorRead')

on(type: "descriptorRead", callback: Callback&lt;DescriptorReadReq&gt;): void

Subscribes to the descriptor read request events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**descriptorRead**&nbsp;indicates&nbsp;a&nbsp;descriptor&nbsp;read&nbsp;request&nbsp;event. |
| callback | Callback&lt;[DescriptorReadReq](#descriptorreadreq)&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;a&nbsp;descriptor&nbsp;read&nbsp;request&nbsp;from&nbsp;the&nbsp;GATT&nbsp;client. |

**Return values:**

None.

**Example:**

```
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


### off('descriptorRead')

off(type: "descriptorRead", callback?: Callback&lt;DescriptorReadReq&gt;): void

Unsubscribes from the descriptor read request events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**descriptorRead**&nbsp;indicates&nbsp;a&nbsp;descriptor&nbsp;read&nbsp;request&nbsp;event. |
| callback | Callback&lt;[DescriptorReadReq](#descriptorreadreq)&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;report&nbsp;a&nbsp;descriptor&nbsp;read&nbsp;request&nbsp;event.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;this&nbsp;method&nbsp;unsubscribes&nbsp;from&nbsp;all&nbsp;callbacks&nbsp;corresponding&nbsp;to&nbsp;**type**. |

**Return values:**

None.

**Example:**

```
let gattServer = bluetooth.BLE.createGattServer();
gattServer.off("descriptorRead");
```


### on('descriptorWrite')

on(type: "descriptorWrite", callback: Callback&lt;DescriptorWriteReq&gt;): void

Subscribes to the descriptor write request events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**descriptorWrite**&nbsp;indicates&nbsp;a&nbsp;descriptor&nbsp;write&nbsp;request&nbsp;event. |
| callback | Callback&lt;[DescriptorWriteReq](#descriptorwritereq)&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;a&nbsp;descriptor&nbsp;write&nbsp;request&nbsp;from&nbsp;the&nbsp;GATT&nbsp;client. |

**Return values:**

None.

**Example:**

```
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


### off('descriptorWrite')

off(type: "descriptorWrite", callback?: Callback&lt;DescriptorWriteReq&gt;): void

Unsubscribes from the descriptor write request events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**descriptorWrite**&nbsp;indicates&nbsp;a&nbsp;descriptor&nbsp;write&nbsp;request&nbsp;event. |
| callback | Callback&lt;[DescriptorWriteReq](#descriptorwritereq)&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;report&nbsp;a&nbsp;descriptor&nbsp;read&nbsp;request&nbsp;event.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;this&nbsp;method&nbsp;unsubscribes&nbsp;from&nbsp;all&nbsp;callbacks&nbsp;corresponding&nbsp;to&nbsp;**type**. |

**Return values:**

None.

**Example:**

```
let gattServer = bluetooth.BLE.createGattServer();
gattServer.off("descriptorWrite");
```


### on('connectStateChange')

on(type: "connectStateChange", callback: Callback&lt;BLEConnectChangedState&gt;): void

Subscribes to the BLE connection state change events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**connectStateChange**&nbsp;indicates&nbsp;a&nbsp;BLE&nbsp;connection&nbsp;state&nbsp;change&nbsp;event. |
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstate)&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;the&nbsp;BLE&nbsp;connection&nbsp;state. |

**Return values:**

None.

**Example:**

```
function Connected(BLEConnectChangedState) {
  let deviceId = BLEConnectChangedState.deviceId;
  let status = BLEConnectChangedState.state;
}

let gattServer = bluetooth.BLE.createGattServer();
gattServer.on("connectStateChange", Connected);
```


### off('connectStateChange')

off(type: "connectStateChange", callback?: Callback&lt;BLEConnectChangedState&gt;): void

Unsubscribes from the BLE connection state change events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**connectStateChange**&nbsp;indicates&nbsp;a&nbsp;BLE&nbsp;connection&nbsp;state&nbsp;change&nbsp;event. |
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstate)&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;report&nbsp;the&nbsp;BLE&nbsp;connection&nbsp;state.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;this&nbsp;method&nbsp;unsubscribes&nbsp;from&nbsp;all&nbsp;callbacks&nbsp;corresponding&nbsp;to&nbsp;**type**. |

**Return values:**

None.

**Example:**

```
let gattServer = bluetooth.BLE.createGattServer();
gattServer.off("connectStateChange");
```


## GattClientDevice

Implements the GATT client. Before using a method of this class, you must create a **GattClientDevice** instance using the **createGattClientDevice(deviceId: string)** method.


### connect

connect(): boolean

Initiates a connection to the peer BLE device.

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;connection&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
let ret = device.connect();
```


### disconnect

disconnect(): boolean

Disconnects from the peer BLE device.

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;connection&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
let ret = device.disconnect();
```


### close

close(): boolean

Closes this GATT client to unregister it from the protocol stack. After this method is called, this [GattClientDevice](#gattclientdevice) instance cannot be used.

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
let ret = device.close();
```




### getServices

getServices(callback: AsyncCallback&lt;Array&lt;GattService&gt;&gt;): void

Obtains all services of the peer BLE device. This method uses an asynchronous callback to return the result.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[GattService](#gattservice)&gt;&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;the&nbsp;services&nbsp;obtained. |

**Return values:**

None.

**Example:**

```
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

let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
device.connect();
device.getServices(getServices);
```


### getServices

getServices(): Promise&lt;Array&lt;GattService&gt;&gt;

Obtains all services of the peer BLE device. This method uses a promise to return the result.

**Parameters:**

**Return values:**

| Type | Description |
| -------- | -------- |
| Promise&lt;Array&lt;[GattService](#gattservice)&gt;&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;services&nbsp;obtained. |

**Example:**

```
// Promise
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
device.connect();
let services = device.getServices();
console.log("bluetooth services size is ", services.length);

for (let i = 0; i < services.length; i++) {
    console.log('bluetooth serviceUuid is ' + services[i].serviceUuid);
}
```


### readCharacteristicValue

readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback&lt;BLECharacteristic&gt;): void

Reads the characteristic value of the specific service of the peer BLE device. This method uses an asynchronous callback to return the result.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes | Characteristic&nbsp;value&nbsp;to&nbsp;read. |
| callback | AsyncCallback&lt;[BLECharacteristic](#blecharacteristic)&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;the&nbsp;characteristic&nbsp;value&nbsp;read. |

**Return values:**

None.

**Example:**

```
function readCcc(code, BLECharacteristic) {
  if (code.code != 0) {
      return;
  }
  console.log('bluetooth characteristic uuid: ' + BLECharacteristic.characteristicUuid);
  let value = new Uint8Array(BLECharacteristic.characteristicValue);
  console.log('bluetooth characteristic value: ' + value[0] +','+ value[1]+','+ value[2]+','+ value[3]);
}

let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
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


### readCharacteristicValue

readCharacteristicValue(characteristic: BLECharacteristic): Promise&lt;BLECharacteristic&gt;

Reads the characteristic value of the specific service of the peer BLE device. This method uses a promise to return the result.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes | Characteristic&nbsp;value&nbsp;to&nbsp;read. |

**Return values:**

| Type | Description |
| -------- | -------- |
| Promise&lt;[BLECharacteristic](#blecharacteristic)&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;characteristic&nbsp;value&nbsp;read. |

**Example:**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
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


### readDescriptorValue

readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback&lt;BLEDescriptor&gt;): void

Reads the descriptor contained in the specific characteristic of the peer BLE device. This method uses an asynchronous callback to return the result.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| descriptor | [BLEDescriptor](#bledescriptor) | Yes | Descriptor&nbsp;to&nbsp;read. |
| callback | AsyncCallback&lt;[BLECharacteristic](#blecharacteristic)&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;the&nbsp;descriptor&nbsp;read. |

**Return values:**

None.

**Example:**

```
function readDesc(code, BLEDescriptor) {
  if (code.code != 0) {
      return;
  }
  console.log('bluetooth descriptor uuid: ' + BLEDescriptor.descriptorUuid);
  let value = new Uint8Array(BLEDescriptor.descriptorValue);
  console.log('bluetooth descriptor value: ' + value[0] +','+ value[1]+','+ value[2]+','+ value[3]);
}

let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
device.readDescriptorValue(descriptor, readDesc);
```


### readDescriptorValue

readDescriptorValue(descriptor: BLEDescriptor): Promise&lt;BLEDescriptor&gt;

Reads the descriptor contained in the specific characteristic of the peer BLE device. This method uses a promise to return the result.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| descriptor | [BLEDescriptor](#bledescriptor) | Yes | Descriptor&nbsp;to&nbsp;read. |

**Return values:**

| Type | Description |
| -------- | -------- |
| Promise&lt;[BLEDescriptor](#bledescriptor)&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;descriptor&nbsp;read. |

**Example:**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
device.readDescriptorValue(descriptor);
```


### writeCharacteristicValue

writeCharacteristicValue(characteristic: BLECharacteristic): boolean

Writes a characteristic value to the peer BLE device.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes | Binary&nbsp;value&nbsp;and&nbsp;other&nbsp;parameters&nbsp;of&nbsp;the&nbsp;BLE&nbsp;device&nbsp;characteristic. |

**Return values:**

| Name | Type | Mandatory | Description |
| -------- | -------- |
| Name | Type | Mandatory | Description |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
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


### writeDescriptorValue

writeDescriptorValue(descriptor: BLEDescriptor): boolean

Writes binary data to the specific descriptor of the peer BLE device.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| descriptor | [BLEDescriptor](#bledescriptor) | Yes | Binary&nbsp;value&nbsp;and&nbsp;other&nbsp;parameters&nbsp;of&nbsp;the&nbsp;BLE&nbsp;device&nbsp;descriptor. |

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
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


### setBLEMtuSize

setBLEMtuSize(mtu: number): boolean

Sets the maximum transmission unit (MTU) that can be transmitted between the GATT client and its peer BLE device. This method can be used only after a connection is set up by calling **connect**.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| mtu | number | Yes | MTU&nbsp;to&nbsp;set,&nbsp;which&nbsp;ranges&nbsp;from&nbsp;22&nbsp;to&nbsp;512&nbsp;bytes. |

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
device.setBLEMtuSize(128);
```


### setNotifyCharacteristicChanged

setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): boolean

Sets the function of notifying the GATT client when the characteristic value of the peer BLE device changes.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | Yes | BLE&nbsp;characteristic&nbsp;to&nbsp;listen&nbsp;for. |
| enable | boolean | Yes | Whether&nbsp;to&nbsp;enable&nbsp;the&nbsp;notify&nbsp;function.&nbsp;The&nbsp;value&nbsp;**true**&nbsp;means&nbsp;to&nbsp;enable&nbsp;the&nbsp;notify&nbsp;function,&nbsp;and&nbsp;the&nbsp;value&nbsp;**false**&nbsp;means&nbsp;the&nbsp;opposite. |

**Return values:**

| Type | Description |
| -------- | -------- |
| boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. |

**Example:**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
device.setNotifyCharacteristicChanged(notifyCcc, false);
```


### on('BLECharacteristicChange')

on(type: "BLECharacteristicChange", callback: Callback&lt;BLECharacteristic&gt;): void

Subscribes to the BLE characteristic change events. The client can receive a notification from the server only after the **setNotifyCharacteristicChanged** method is called.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**BLECharacteristicChange**&nbsp;indicates&nbsp;a&nbsp;characteristic&nbsp;value&nbsp;change&nbsp;event. |
| callback | Callback&lt;[BLECharacteristic](#blecharacteristic)&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;the&nbsp;characteristic&nbsp;value&nbsp;changes. |

**Return values:**

None.

**Example:**

```
function CharacteristicChange(CharacteristicChangeReq) {
  let serviceUuid = CharacteristicChangeReq.serviceUuid;
  let characteristicUuid = CharacteristicChangeReq.characteristicUuid;
  let value = new Uint8Array(CharacteristicChangeReq.characteristicValue);
}
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
device.on('BLECharacteristicChange', CharacteristicChange);
```


### off('BLECharacteristicChange')

off(type: "BLECharacteristicChange", callback?: Callback&lt;BLECharacteristic&gt;): void

Unsubscribes from the BLE characteristic change events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**BLECharacteristicChange**&nbsp;indicates&nbsp;a&nbsp;characteristic&nbsp;value&nbsp;change&nbsp;event. |
| callback | Callback&lt;[BLECharacteristic](#blecharacteristic)&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;report&nbsp;the&nbsp;characteristic&nbsp;value.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;this&nbsp;method&nbsp;unsubscribes&nbsp;from&nbsp;all&nbsp;callbacks&nbsp;corresponding&nbsp;to&nbsp;**type**. |

**Return values:**

None.

**Example:**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
device.off('BLECharacteristicChange');
```


### on('BLEConnectionStateChange')

on(type: "BLEConnectionStateChange", callback: Callback&lt;BLEConnectChangedState&gt;): void

Subscribes to the BLE connection state change events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**BLEConnectionStateChange**&nbsp;indicates&nbsp;a&nbsp;BLE&nbsp;connection&nbsp;state&nbsp;change&nbsp;event. |
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstate)&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;the&nbsp;BLE&nbsp;connection&nbsp;state. |

**Return values:**

None.

**Example:**

```
function ConnectStateChanged(state) {
  console.log('bluetooth connect state changed');
  let connectState = state.state;
}
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
device.on('BLEConnectionStateChange', ConnectStateChanged);
```


### off('BLEConnectionStateChange')

off(type: "BLEConnectionStateChange", callback?: Callback&lt;BLEConnectChangedState&gt;): void

Unsubscribes from the BLE connection state change events.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| type | string | Yes | Event&nbsp;type.&nbsp;The&nbsp;value&nbsp;**BLEConnectionStateChange**&nbsp;indicates&nbsp;a&nbsp;BLE&nbsp;connection&nbsp;state&nbsp;change&nbsp;event. |
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstate)&gt; | No | Callback&nbsp;used&nbsp;to&nbsp;report&nbsp;the&nbsp;BLE&nbsp;connection&nbsp;state.&nbsp;If&nbsp;this&nbsp;parameter&nbsp;is&nbsp;not&nbsp;set,&nbsp;this&nbsp;method&nbsp;unsubscribes&nbsp;from&nbsp;all&nbsp;callbacks&nbsp;corresponding&nbsp;to&nbsp;**type**. |

**Return values:**

None.

**Example:**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
device.off('BLEConnectionStateChange');
```


### getDeviceName

getDeviceName(callback: AsyncCallback&lt;string&gt;): void

Obtains the name of the peer BLE device. This method uses an asynchronous callback to return the result.

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;string&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;the&nbsp;peer&nbsp;BLE&nbsp;device&nbsp;name. |

**Return values:**

None.

**Example:**

```
// Callback
let gattClient = bluetooth.BLE.createGattClientDevice("8F:8F:8E:8E:6D:6D");
let deviceName = gattClient.getDeviceName((err, data)=> {
    console.info('device name err ' + JSON.stringify(err));
    console.info('device name' + JSON.stringify(data));
})
```


### getDeviceName

getDeviceName(): Promise&lt;string&gt;

Obtains the name of the peer BLE device. This method uses a promise to return the result.

**Return values:**

| Type | Description |
| -------- | -------- |
| Promise&lt;string&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;peer&nbsp;BLE&nbsp;device&nbsp;name. |

**Example:**

```
// Promise
let gattClient = bluetooth.BLE.createGattClientDevice("8F:8F:8E:8E:6D:6D");
let ret = device.connect();
let deviceName = gattClient.getDeviceName().then((data) => {
    console.info('device name' + JSON.stringify(data));
})
```


### getRssiValue

getRssiValue(callback: AsyncCallback&lt;number&gt;): void

Obtains the received signal strength indication (RSSI) of the peer BLE device. This method uses an asynchronous callback to return the result. It can be used only after a connection is set up by calling [connect](#connect-boolean).

**Parameters:**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;number&gt; | Yes | Callback&nbsp;invoked&nbsp;to&nbsp;return&nbsp;the&nbsp;RSSI,&nbsp;in&nbsp;dBm. |

**Return values:**

None.

**Example:**

```
// Callback
let gattClient = bluetooth.BLE.createGattClientDevice("8F:8F:8E:8E:6D:6D");
let ret = device.connect();
let rssi = gattClient.getRssiValue((err, data)=> {
    console.info('rssi err ' + JSON.stringify(err));
    console.info('rssi value' + JSON.stringify(data));
})
```


### getRssiValue

getRssiValue(): Promise&lt;number&gt;

Obtains the RSSI of the peer BLE device. This method uses a promise to return the result. It can be used only after a connection is set up by calling [connect](#connect-boolean).

**Return values:**

| Type | Description |
| -------- | -------- |
| Promise&lt;number&gt; | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;RSSI,&nbsp;in&nbsp;dBm. |

**Example:**

```
// Promise
let gattClient = bluetooth.BLE.createGattClientDevice("8F:8F:8E:8E:6D:6D");
let rssi = gattClient.getRssiValue().then((data) => {
    console.info('rssi' + JSON.stringify(data));
})
```


## ScanMode

Enumerates the scan modes.

| Mode | Default&nbsp;Value | Description |
| -------- | -------- | -------- |
| SCAN_MODE_NONE | 0 | No&nbsp;scan&nbsp;mode&nbsp;is&nbsp;specified. |
| SCAN_MODE_CONNECTABLE | 1 | Discoverable&nbsp;mode. |
| SCAN_MODE_GENERAL_DISCOVERABLE | 2 | General&nbsp;discoverable&nbsp;mode. |
| SCAN_MODE_LIMITED_DISCOVERABLE | 3 | Limited&nbsp;discoverable&nbsp;mode. |
| SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE | 4 | General&nbsp;connectable&nbsp;and&nbsp;discoverable&nbsp;mode. |
| SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE | 5 | Limited&nbsp;connectable&nbsp;and&nbsp;discoverable&nbsp;mode. |


## BondState

Enumerates the pairing states.

| State | Default&nbsp;Value | Description |
| -------- | -------- | -------- |
| BOND_STATE_INVALID | 0 | Invalid&nbsp;pairing. |
| BOND_STATE_BONDING | 1 | Pairing. |
| BOND_STATE_BONDED | 2 | Paired. |


## SppOption

Defines the SPP configuration parameters.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| uuid | string | Yes | Yes | UUID&nbsp;of&nbsp;the&nbsp;SPP. |
| isPrimary | boolean | Yes | Yes | Whether&nbsp;it&nbsp;is&nbsp;a&nbsp;secure&nbsp;channel. |
| type | [SppType](#SppType) | Yes | Yes | Type&nbsp;of&nbsp;the&nbsp;SPP&nbsp;link. |


## SppType

Enumerates the SPP link types.

| Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- |
| SPP_RFCOMM | 0 | Radio&nbsp;frequency&nbsp;communication&nbsp;(RFCOMM)&nbsp;link&nbsp;type. |


## GattService

Defines the GATT service API parameters.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | Yes | Yes | UUID&nbsp;of&nbsp;the&nbsp;service,&nbsp;for&nbsp;example,&nbsp;**00001888-0000-1000-8000-00805f9b34fb**. |
| isPrimary | boolean | Yes | Yes | Whether&nbsp;the&nbsp;service&nbsp;is&nbsp;a&nbsp;primary&nbsp;service.&nbsp;The&nbsp;value&nbsp;**true**&nbsp;means&nbsp;a&nbsp;primary&nbsp;service. |
| characteristics | Array&lt;[BLECharacteristic](#BLECharacteristic)&gt; | Yes | Yes | List&nbsp;of&nbsp;characteristics&nbsp;of&nbsp;the&nbsp;service. |
| includeServices | Array&lt;[GattService](#GattService)&gt; | Yes | Yes | Services&nbsp;on&nbsp;which&nbsp;the&nbsp;service&nbsp;depends. |


## BLECharacteristic

Defines the characteristic API parameters.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | Yes | Yes | UUID&nbsp;of&nbsp;the&nbsp;service,&nbsp;for&nbsp;example,&nbsp;**00001888-0000-1000-8000-00805f9b34fb**. |
| characteristicUuid | string | Yes | Yes | UUID&nbsp;of&nbsp;the&nbsp;characteristic,&nbsp;for&nbsp;example,&nbsp;**00002a11-0000-1000-8000-00805f9b34fb**. |
| characteristicValue | ArrayBuffer | Yes | Yes | Binary&nbsp;value&nbsp;of&nbsp;the&nbsp;characteristic. |
| descriptors | Array&lt;[BLEDescriptor](#BLEDescriptor)&gt; | Yes | Yes | List&nbsp;of&nbsp;descriptors&nbsp;of&nbsp;the&nbsp;characteristic. |


## BLEDescriptor

Defines the descriptor API parameters.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | Yes | Yes | UUID&nbsp;of&nbsp;the&nbsp;service,&nbsp;for&nbsp;example,&nbsp;**00001888-0000-1000-8000-00805f9b34fb**. |
| characteristicUuid | string | Yes | Yes | UUID&nbsp;of&nbsp;the&nbsp;characteristic,&nbsp;for&nbsp;example,&nbsp;**00002a11-0000-1000-8000-00805f9b34fb**. |
| descriptorUuid | string | Yes | Yes | UUID&nbsp;of&nbsp;the&nbsp;descriptor,&nbsp;for&nbsp;example,&nbsp;**00002902-0000-1000-8000-00805f9b34fb**. |
| descriptorValue | ArrayBuffer | Yes | Yes | Binary&nbsp;value&nbsp;of&nbsp;the&nbsp;descriptor. |


## NotifyCharacteristic

Defines the parameters in the notifications sent when the server characteristic value changes.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | Yes | Yes | UUID&nbsp;of&nbsp;the&nbsp;service,&nbsp;for&nbsp;example,&nbsp;**00001888-0000-1000-8000-00805f9b34fb**. |
| characteristicUuid | string | Yes | Yes | UUID&nbsp;of&nbsp;the&nbsp;characteristic,&nbsp;for&nbsp;example,&nbsp;**00002a11-0000-1000-8000-00805f9b34fb**. |
| characteristicValue | ArrayBuffer | Yes | Yes | Binary&nbsp;value&nbsp;of&nbsp;the&nbsp;characteristic. |
| confirm | boolean | Yes | Yes | Whether&nbsp;the&nbsp;notification&nbsp;needs&nbsp;to&nbsp;be&nbsp;confirmed&nbsp;by&nbsp;the&nbsp;peer&nbsp;end.&nbsp;For&nbsp;a&nbsp;notification,&nbsp;set&nbsp;it&nbsp;to&nbsp;**true**.&nbsp;In&nbsp;this&nbsp;case,&nbsp;the&nbsp;peer&nbsp;end&nbsp;must&nbsp;confirm&nbsp;the&nbsp;receipt&nbsp;of&nbsp;the&nbsp;notification.&nbsp;For&nbsp;an&nbsp;indication,&nbsp;set&nbsp;it&nbsp;to&nbsp;**false**.&nbsp;In&nbsp;this&nbsp;case,&nbsp;the&nbsp;peer&nbsp;end&nbsp;does&nbsp;not&nbsp;need&nbsp;to&nbsp;confirm&nbsp;the&nbsp;receipt&nbsp;of&nbsp;the&nbsp;notification. |


## CharacteristicReadReq

Defines the parameters of the **CharacteristicReadReq** event received by the server.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | Yes | No | Address&nbsp;of&nbsp;the&nbsp;client&nbsp;that&nbsp;sends&nbsp;the&nbsp;request,&nbsp;for&nbsp;example,&nbsp;**8F:8F:8E:8E:6D:6D**. |
| transId | number | Yes | No | Transmission&nbsp;ID&nbsp;of&nbsp;the&nbsp;read&nbsp;request.&nbsp;The&nbsp;response&nbsp;returned&nbsp;by&nbsp;the&nbsp;server&nbsp;must&nbsp;use&nbsp;the&nbsp;same&nbsp;transmission&nbsp;ID. |
| offset | number | Yes | No | Position&nbsp;from&nbsp;which&nbsp;the&nbsp;characteristic&nbsp;value&nbsp;is&nbsp;read.&nbsp;For&nbsp;example,&nbsp;**k**&nbsp;means&nbsp;to&nbsp;read&nbsp;from&nbsp;the&nbsp;_k_th&nbsp;byte.&nbsp;The&nbsp;response&nbsp;returned&nbsp;by&nbsp;the&nbsp;server&nbsp;must&nbsp;use&nbsp;the&nbsp;same&nbsp;offset. |
| characteristicUuid | string | Yes | No | UUID&nbsp;of&nbsp;the&nbsp;characteristic,&nbsp;for&nbsp;example,&nbsp;**00002a11-0000-1000-8000-00805f9b34fb**. |
| serviceUuid | string | Yes | No | UUID&nbsp;of&nbsp;the&nbsp;service,&nbsp;for&nbsp;example,&nbsp;**00001888-0000-1000-8000-00805f9b34fb**. |


## CharacteristicWriteReq

Defines the parameters of the **CharacteristicWriteReq** event received by the server.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | Yes | No | Address&nbsp;of&nbsp;the&nbsp;client&nbsp;that&nbsp;sends&nbsp;the&nbsp;request,&nbsp;for&nbsp;example,&nbsp;**8F:8F:8E:8E:6D:6D**. |
| transId | number | Yes | No | Transmission&nbsp;ID&nbsp;of&nbsp;the&nbsp;write&nbsp;request.&nbsp;The&nbsp;response&nbsp;returned&nbsp;by&nbsp;the&nbsp;server&nbsp;must&nbsp;use&nbsp;the&nbsp;same&nbsp;transmission&nbsp;ID. |
| offset | number | Yes | No | Start&nbsp;position&nbsp;for&nbsp;writing&nbsp;the&nbsp;characteristic&nbsp;value.&nbsp;For&nbsp;example,&nbsp;**k**&nbsp;means&nbsp;to&nbsp;write&nbsp;from&nbsp;the&nbsp;_k_th&nbsp;byte.&nbsp;The&nbsp;response&nbsp;returned&nbsp;by&nbsp;the&nbsp;server&nbsp;must&nbsp;use&nbsp;the&nbsp;same&nbsp;offset. |
| descriptorUuid | string | Yes | No | UUID&nbsp;of&nbsp;the&nbsp;descriptor,&nbsp;for&nbsp;example,&nbsp;**00002902-0000-1000-8000-00805f9b34fb**. |
| characteristicUuid | string | Yes | No | UUID&nbsp;of&nbsp;the&nbsp;characteristic,&nbsp;for&nbsp;example,&nbsp;**00002a11-0000-1000-8000-00805f9b34fb**. |
| serviceUuid | string | Yes | No | UUID&nbsp;of&nbsp;the&nbsp;service,&nbsp;for&nbsp;example,&nbsp;**00001888-0000-1000-8000-00805f9b34fb**. |


## DescriptorReadReq

Defines the parameters of the **DescriptorReadReq** event received by the server.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | Yes | No | Address&nbsp;of&nbsp;the&nbsp;client&nbsp;that&nbsp;sends&nbsp;the&nbsp;request,&nbsp;for&nbsp;example,&nbsp;**8F:8F:8E:8E:6D:6D**. |
| transId | number | Yes | No | Transmission&nbsp;ID&nbsp;of&nbsp;the&nbsp;read&nbsp;request.&nbsp;The&nbsp;response&nbsp;returned&nbsp;by&nbsp;the&nbsp;server&nbsp;must&nbsp;use&nbsp;the&nbsp;same&nbsp;transmission&nbsp;ID. |
| offset | number | Yes | No | Position&nbsp;from&nbsp;which&nbsp;the&nbsp;descriptor&nbsp;is&nbsp;read.&nbsp;For&nbsp;example,&nbsp;**k**&nbsp;means&nbsp;to&nbsp;read&nbsp;from&nbsp;the&nbsp;_k_th&nbsp;byte.&nbsp;The&nbsp;response&nbsp;returned&nbsp;by&nbsp;the&nbsp;server&nbsp;must&nbsp;use&nbsp;the&nbsp;same&nbsp;offset. |
| descriptorUuid | string | Yes | No | UUID&nbsp;of&nbsp;the&nbsp;descriptor,&nbsp;for&nbsp;example,&nbsp;**00002902-0000-1000-8000-00805f9b34fb**. |
| characteristicUuid | string | Yes | No | UUID&nbsp;of&nbsp;the&nbsp;characteristic,&nbsp;for&nbsp;example,&nbsp;**00002a11-0000-1000-8000-00805f9b34fb**. |
| serviceUuid | string | Yes | No | UUID&nbsp;of&nbsp;the&nbsp;service,&nbsp;for&nbsp;example,&nbsp;**00001888-0000-1000-8000-00805f9b34fb**. |


## DescriptorWriteReq

Defines the parameters of the **DescriptorWriteReq** event received by the server.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | Yes | No | Address&nbsp;of&nbsp;the&nbsp;client&nbsp;that&nbsp;sends&nbsp;the&nbsp;request,&nbsp;for&nbsp;example,&nbsp;**8F:8F:8E:8E:6D:6D**. |
| transId | number | Yes | No | Transmission&nbsp;ID&nbsp;of&nbsp;the&nbsp;write&nbsp;request.&nbsp;The&nbsp;response&nbsp;returned&nbsp;by&nbsp;the&nbsp;server&nbsp;must&nbsp;use&nbsp;the&nbsp;same&nbsp;transmission&nbsp;ID. |
| offset | number | Yes | No | Start&nbsp;position&nbsp;for&nbsp;writing&nbsp;the&nbsp;descriptor.&nbsp;For&nbsp;example,&nbsp;**k**&nbsp;means&nbsp;to&nbsp;write&nbsp;from&nbsp;the&nbsp;_k_th&nbsp;byte.&nbsp;The&nbsp;response&nbsp;returned&nbsp;by&nbsp;the&nbsp;server&nbsp;must&nbsp;use&nbsp;the&nbsp;same&nbsp;offset. |
| isPrep | boolean | Yes | No | Whether&nbsp;the&nbsp;write&nbsp;request&nbsp;is&nbsp;executed&nbsp;immediately. |
| needRsp | boolean | Yes | No | Whether&nbsp;to&nbsp;send&nbsp;a&nbsp;response&nbsp;to&nbsp;the&nbsp;GATT&nbsp;client. |
| value | ArrayBuffer | Yes | No | Binary&nbsp;value&nbsp;of&nbsp;the&nbsp;descriptor&nbsp;to&nbsp;write. |
| descriptorUuid | string | Yes | No | UUID&nbsp;of&nbsp;the&nbsp;descriptor,&nbsp;for&nbsp;example,&nbsp;**00002902-0000-1000-8000-00805f9b34fb**. |
| characteristicUuid | string | Yes | No | UUID&nbsp;of&nbsp;the&nbsp;characteristic,&nbsp;for&nbsp;example,&nbsp;**00002a11-0000-1000-8000-00805f9b34fb**. |
| serviceUuid | string | Yes | No | UUID&nbsp;of&nbsp;the&nbsp;service,&nbsp;for&nbsp;example,&nbsp;**00001888-0000-1000-8000-00805f9b34fb**. |


## ServerResponse

Defines the parameters of the server's response to the GATT client's read/write request.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | Yes | No | Address&nbsp;of&nbsp;the&nbsp;client,&nbsp;for&nbsp;example,&nbsp;**8F:8F:8E:8E:6D:6D**. |
| transId | number | Yes | No | Transmission&nbsp;ID&nbsp;of&nbsp;the&nbsp;request.&nbsp;The&nbsp;value&nbsp;must&nbsp;be&nbsp;the&nbsp;same&nbsp;as&nbsp;the&nbsp;ID&nbsp;carried&nbsp;in&nbsp;the&nbsp;read/write&nbsp;request&nbsp;received. |
| status | number | Yes | No | Response&nbsp;state.&nbsp;Set&nbsp;this&nbsp;parameter&nbsp;to&nbsp;**0**,&nbsp;which&nbsp;indicates&nbsp;a&nbsp;normal&nbsp;response. |
| offset | number | Yes | No | Start&nbsp;read/write&nbsp;position.&nbsp;The&nbsp;value&nbsp;must&nbsp;be&nbsp;the&nbsp;same&nbsp;as&nbsp;the&nbsp;**offset**&nbsp;carried&nbsp;in&nbsp;the&nbsp;read/write&nbsp;request. |
| value | ArrayBuffer | Yes | No | Binary&nbsp;data&nbsp;in&nbsp;the&nbsp;response. |


## BLEConnectChangedState

Defines the parameters of **BLEConnectChangedState**.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | Yes | No | Address&nbsp;of&nbsp;the&nbsp;peer&nbsp;device,&nbsp;for&nbsp;example,&nbsp;**8F:8F:8E:8E:6D:6D**. |
| state | [ProfileConnectionState](#ProfileConnectionState) | Yes | Yes | BLE&nbsp;connection&nbsp;state. |


## ProfileConnectionState

Enumerates the profile connection states.

| Name | Default&nbsp;Value | Description |
| -------- | -------- | -------- |
| STATE_DISCONNECTED | 0 | Disconnected. |
| STATE_CONNECTING | 1 | Connecting. |
| STATE_CONNECTED | 2 | Connected. |
| STATE_DISCONNECTING | 3 | Disconnecting. |


## ScanFilter

Defines the scan filter parameters.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | Yes | Yes | Address&nbsp;of&nbsp;the&nbsp;BLE&nbsp;device&nbsp;to&nbsp;filter,&nbsp;for&nbsp;example,&nbsp;**8F:8F:8E:8E:6D:6D**. |
| name | string | Yes | Yes | Name&nbsp;of&nbsp;the&nbsp;BLE&nbsp;device&nbsp;to&nbsp;filter. |
| serviceUuid | string | Yes | Yes | UUID&nbsp;of&nbsp;the&nbsp;service,&nbsp;for&nbsp;example,&nbsp;**00001888-0000-1000-8000-00805f9b34fb**. |


## ScanOptions

Defines the scan configuration parameters.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| interval | number | Yes | Yes | Delay&nbsp;in&nbsp;reporting&nbsp;the&nbsp;scan&nbsp;result.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**0**. |
| dutyMode | [ScanDuty](#ScanDuty) | Yes | Yes | Scan&nbsp;duty.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**SCAN_MODE_LOW_POWER**. |
| matchMode | [MatchMode](#MatchMode) | Yes | Yes | Hardware&nbsp;match&nbsp;mode&nbsp;for&nbsp;BLE&nbsp;scan&nbsp;filters.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**MATCH_MODE_AGGRESSIVE**. |


## ScanDuty

Enumerates the scan duty options.

| Name | Default&nbsp;Value | Description |
| -------- | -------- | -------- |
| SCAN_MODE_LOW_POWER | 0 | Low-power&nbsp;mode,&nbsp;which&nbsp;is&nbsp;the&nbsp;default&nbsp;value. |
| SCAN_MODE_BALANCED | 1 | Balanced&nbsp;mode. |
| SCAN_MODE_LOW_LATENCY | 2 | Low-latency&nbsp;mode. |


## MatchMode

Enumerates the hardware match modes of BLE scan filters.

| Name | Default&nbsp;Value | Description |
| -------- | -------- | -------- |
| MATCH_MODE_AGGRESSIVE | 1 | Hardware&nbsp;reports&nbsp;the&nbsp;scan&nbsp;result&nbsp;with&nbsp;a&nbsp;lower&nbsp;threshold&nbsp;of&nbsp;signal&nbsp;strength&nbsp;and&nbsp;few&nbsp;number&nbsp;of&nbsp;matches&nbsp;in&nbsp;a&nbsp;duration.&nbsp;This&nbsp;is&nbsp;the&nbsp;default&nbsp;value. |
| SCAN_MODE_LOW_LATENCY | 2 | Hardware&nbsp;reports&nbsp;the&nbsp;scan&nbsp;result&nbsp;with&nbsp;a&nbsp;higher&nbsp;threshold&nbsp;of&nbsp;signal&nbsp;strength&nbsp;and&nbsp;sightings. |


## ScanResult

Defines the scan result.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | Yes | No | Address&nbsp;of&nbsp;the&nbsp;device&nbsp;discovered,&nbsp;for&nbsp;example,&nbsp;**8F:8F:8E:8E:6D:6D**. |
| rssi | number | Yes | No | RSSI&nbsp;of&nbsp;the&nbsp;device. |
| data | ArrayBuffer | Yes | No | Advertisement&nbsp;packets&nbsp;sent&nbsp;by&nbsp;the&nbsp;device. |


## BluetoothState

Enumerates the Bluetooth states.

| Name | Default&nbsp;Value | Description |
| -------- | -------- | -------- |
| STATE_OFF | 0 | Bluetooth&nbsp;is&nbsp;turned&nbsp;off. |
| STATE_TURNING_ON | 1 | Bluetooth&nbsp;is&nbsp;being&nbsp;turned&nbsp;on. |
| STATE_ON | 2 | Bluetooth&nbsp;is&nbsp;turned&nbsp;on. |
| STATE_TURNING_OFF | 3 | Bluetooth&nbsp;is&nbsp;being&nbsp;turned&nbsp;off. |
| STATE_BLE_TURNING_ON | 4 | The&nbsp;LE-only&nbsp;mode&nbsp;is&nbsp;being&nbsp;turned&nbsp;on&nbsp;for&nbsp;Bluetooth. |
| STATE_BLE_ON | 5 | Bluetooth&nbsp;is&nbsp;in&nbsp;LE-only&nbsp;mode. |
| STATE_BLE_TURNING_OFF | 6 | The&nbsp;LE-only&nbsp;mode&nbsp;is&nbsp;being&nbsp;turned&nbsp;off&nbsp;for&nbsp;Bluetooth. |


## AdvertiseSetting

Defines the BLE advertising parameters.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| interval | number | Yes | Yes | Interval&nbsp;for&nbsp;BLE&nbsp;advertising.&nbsp;The&nbsp;minimum&nbsp;value&nbsp;is&nbsp;**32**&nbsp;slots&nbsp;(20&nbsp;ms).&nbsp;The&nbsp;maximum&nbsp;value&nbsp;is&nbsp;**16777215**&nbsp;slots.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**1600**&nbsp;slots&nbsp;(1s). |
| txPower | number | Yes | Yes | Transmit&nbsp;power,&nbsp;in&nbsp;dBm.&nbsp;The&nbsp;value&nbsp;range&nbsp;is&nbsp;–127&nbsp;to&nbsp;1.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**–7**. |
| connectable | boolean | Yes | Yes | Whether&nbsp;the&nbsp;advertisement&nbsp;is&nbsp;connectable.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**true**. |


## AdvertiseData

Defines the content of a BLE advertisement packet.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuids | Array&lt;string&gt; | Yes | Yes | List&nbsp;of&nbsp;service&nbsp;UUIDs&nbsp;to&nbsp;be&nbsp;broadcasted. |
| manufactureData | Array&lt;[ManufactureData](#ManufactureData)&gt; | Yes | Yes | List&nbsp;of&nbsp;manufacturers&nbsp;to&nbsp;be&nbsp;broadcasted. |
| serviceData | Array&lt;[ServiceData](#ServiceData)&gt; | Yes | Yes | List&nbsp;of&nbsp;service&nbsp;data&nbsp;to&nbsp;be&nbsp;broadcasted. |


## ManufactureData

Defines the content of a BLE advertisement packet.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| manufactureId | Array&lt;string&gt; | Yes | Yes | Manufacturer&nbsp;ID&nbsp;allocated&nbsp;by&nbsp;the&nbsp;Bluetooth&nbsp;SIG. |
| manufactureValue | ArrayBuffer | Yes | Yes | Manufacturer&nbsp;data. |


## ServiceData

Defines the service data contained in an advertisement packet.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | Yes | Yes | Service&nbsp;UUID. |
| serviceValue | ArrayBuffer | Yes | Yes | Service&nbsp;data. |


## PinRequiredParam

Defines the pairing request parameters.

| Name | Type | Readable | Writable | Description |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | Yes | No | ID&nbsp;of&nbsp;the&nbsp;device&nbsp;to&nbsp;pair. |
| pinCode | string | Yes | No | Key&nbsp;for&nbsp;the&nbsp;device&nbsp;pairing. |
