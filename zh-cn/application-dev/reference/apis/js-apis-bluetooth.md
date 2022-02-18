# Bluetooth

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

蓝牙模块提供了基础的传统蓝牙能力以及BLE的扫描、广播等功能。

## 导入模块

```
import bluetooth from '@ohos.bluetooth';
```


## 权限

ohos.permission.USE_BLUETOOTH

ohos.permission.MANAGE_BLUETOOTH

ohos.permission.DISCOVER_BLUETOOTH

ohos.permission.LOCATION


## bluetooth.enableBluetooth

enableBluetooth(): boolean

开启蓝牙。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 打开蓝牙，成功返回true，否则返回false。 |

**示例：**

```
let enable = bluetooth.enableBluetooth();
```


## bluetooth.disableBluetooth

disableBluetooth(): boolean

关闭蓝牙。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 关闭蓝牙，成功返回true，否则返回false。 |

**示例：**

```
let disable = bluetooth.disableBluetooth();
```


## bluetooth.getLocalName

getLocalName(): string

获取蓝牙本地设备名称。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 蓝牙本地设备名称。 |

**示例：**

```
let localName = bluetooth.getLocalName();
```


## bluetooth.getState

getState(): BluetoothState

获取蓝牙开关状态。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [BluetoothState](#bluetoothstate) | 表示蓝牙开关状态。 |

**示例：**

```
let state = bluetooth.getState();
```


## bluetooth.getBtConnectionState

getBtConnectionState(): ProfileConnectionState

获取蓝牙设备的Profile连接状态。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [ProfileConnectionState](#profileconnectionstate) | 表示蓝牙设备的Profile连接状态。 |

**示例：**

```
let connectionState = bluetooth.getBtConnectionState();
```


## bluetooth.setLocalName

setLocalName(name: string): boolean

设置蓝牙本地设备名称。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 要设置的蓝牙名称，最大长度为128。 |

**返回值：**

| | |
| -------- | -------- |
| 类型 | 说明 |
| boolean | 设置蓝牙本地设备名称，成功返回true，否则返回false。 |

**示例：**

```
let ret = bluetooth.setLocalName('device_name');
```


## bluetooth.pairDevice

pairDevice(deviceId: string): boolean

发起蓝牙配对。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceId | string | 是 | 表示配对的远端设备地址，例如："8F:8F:8E:8E:6D:6D"。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 发起蓝牙配对，成功返回true，否则返回false。 |

**示例：**

```
// 实际的地址可由扫描流程获取
let result = bluetooth.pairDevice("8F:8F:8E:8E:6D:6D");
```


## bluetooth.getPairedDevices

getPairedDevices(): Array&lt;string&gt;

获取蓝牙配对列表。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array&lt;string&gt; | 已配对蓝牙设备的地址列表。 |

**示例：**

```
let devices = bluetooth.getPairedDevices();
```


## bluetooth.setBluetoothScanMode

setBluetoothScanMode(mode: ScanMode, duration: number): boolean

设置蓝牙扫描模式，可以被远端设备发现。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mode | [ScanMode](#scanmode) | 是 | 蓝牙扫描模式。 |
| duration | number | 是 | 设备可被发现的持续时间，单位为秒；设置为0则持续可发现。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 设置蓝牙扫描，成功返回true，否则返回false。 |

**示例：**

```
// 设置为可连接可发现才可被远端设备扫描到，可以连接。
let result = bluetooth.setBluetoothScanMode(ScanMode.SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE, 100);
```


## bluetooth.getBluetoothScanMode

getBluetoothScanMode(): ScanMode

获取蓝牙扫描模式。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [ScanMode](#scanmode) | 蓝牙扫描模式。 |

**示例：**

```
let scanMode = bluetooth.getBluetoothScanMode();
```


## bluetooth.startBluetoothDiscovery

startBluetoothDiscovery(): boolean

开启蓝牙扫描，可以发现远端设备。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 开启蓝牙扫描，成功返回true，否则返回false。 |

**示例：**

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

关闭蓝牙扫描。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 关闭蓝牙扫描，成功返回true，否则返回false。 |

**示例：**

```
let result = bluetooth.stopBluetoothDiscovery();
```


## bluetooth.setDevicePairingConfirmation

setDevicePairingConfirmation(device: string, accept: boolean): boolean

设置设备配对请求确认。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| device | string | 是 | 表示远端设备地址，例如："8F:8F:8E:8E:6D:6D"。 |
| accept | boolean | 是 | 接受配对请求设置为true，否则设置为false。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 设置设备配对确认，成功返回true，否则返回false。 |

**示例：**

```
// 订阅“pinRequired”配对请求事件，收到远端配对请求后设置配对确认
function onReceivePinRequiredEvent(data) { // data为配对请求的入参，配对请求参数
    console.info('pin required  = '+ JSON.stringify(data));
    bluetooth.setDevicePairingConfirmation(data.deviceId, true);
}
bluetooth.on("pinRequired", onReceivePinRequiredEvent);
```


## bluetooth.on('bluetoothDeviceFind')

on(type: "bluetoothDeviceFind", callback: Callback&lt;Array&lt;string&gt;&gt;): void

订阅蓝牙设备发现上报事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"bluetoothDeviceFind"字符串，表示蓝牙设备发现事件。 |
| callback | Callback&lt;Array&lt;string&gt;&gt; | 是 | 表示回调函数的入参，发现的设备集合。回调函数由用户创建通过该接口注册。 |

**返回值：**

无

**示例：**

```
function onReceiveEvent(data) { // data为蓝牙设备地址集合
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
bluetooth.on('bluetoothDeviceFind', onReceiveEvent);
```


## bluetooth.off('bluetoothDeviceFind')

off(type: "bluetoothDeviceFind", callback?: Callback&lt;Array&lt;string&gt;&gt;): void

取消订阅蓝牙设备发现上报事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"bluetoothDeviceFind"字符串，表示蓝牙设备发现事件。 |
| callback | Callback&lt;Array&lt;string&gt;&gt; | 否 | 表示取消订阅蓝牙设备发现事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```
function onReceiveEvent(data) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
bluetooth.on('bluetoothDeviceFind', onReceiveEvent);
bluetooth.off('bluetoothDeviceFind', onReceiveEvent);
```


## bluetooth.on('pinRequired')

on(type: "pinRequired", callback: Callback&lt;PinRequiredParam&gt;): void

订阅远端蓝牙设备的配对请求事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"pinRequired"字符串，表示配对请求事件。 |
| callback | Callback&lt;[PinRequiredParam](#pinrequiredparam)&gt; | 是 | 表示回调函数的入参，配对请求。回调函数由用户创建通过该接口注册。 |

**返回值：**

无

**示例：**

```
function onReceiveEvent(data) { // data为配对请求参数
    console.info('pin required = '+ JSON.stringify(data));
}
bluetooth.on('pinRequired', onReceiveEvent);
```


## bluetooth.off('pinRequired')

off(type: "pinRequired", callback?: Callback&lt;PinRequiredParam&gt;): void

取消订阅远端蓝牙设备的配对请求事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"pinRequired"字符串，表示配对请求事件。 |
| callback | Callback&lt;[PinRequiredParam](#pinrequiredparam)&gt; | 否 | 表示取消订阅蓝牙配对请求事件上报，入参为配对请求参数。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```
function onReceiveEvent(data) {
    console.info('pin required = '+ JSON.stringify(data));
}
bluetooth.on('pinRequired', onReceiveEvent);
bluetooth.off('pinRequired', onReceiveEvent);
```


## bluetooth.on('bondStateChange')

on(type: "bondStateChange", callback: Callback&lt;BondState&gt;): void

订阅蓝牙配对状态改变事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"bondStateChange"字符串，表示蓝牙配对状态改变事件。 |
| callback | Callback&lt;[BondState](#bondstate)&gt; | 是 | 表示回调函数的入参，配对的状态。回调函数由用户创建通过该接口注册。 |

**返回值：**

无

**示例：**

```
function onReceiveEvent(data) { // data为回调函数入参，表示配对的状态
    console.info('pair state = '+ JSON.stringify(data));
}
bluetooth.on('bondStateChange', onReceiveEvent);
```


## bluetooth.off('bondStateChange')

off(type: "bondStateChange", callback?: Callback&lt;BondState&gt;): void

取消订阅蓝牙配对状态改变事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"bondStateChange"字符串，表示蓝牙配对状态改变事件。 |
| callback | Callback&lt;[BondState](#bondstate)&gt; | 否 | 表示取消订阅蓝牙配对状态改变事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```
function onReceiveEvent(data) {
    console.info('bond state = '+ JSON.stringify(data));
}
bluetooth.on('bondStateChange', onReceiveEvent);
bluetooth.off('bondStateChange', onReceiveEvent);
```


## bluetooth.on('stateChange')

on(type: "stateChange", callback: Callback&lt;BluetoothState&gt;): void

订阅蓝牙连接状态改变事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"stateChange"字符串，表示蓝牙状态改变事件。 |
| callback | Callback&lt;[BluetoothState](#bluetoothstate)&gt; | 是 | 表示回调函数的入参，蓝牙状态。回调函数由用户创建通过该接口注册。 |

**返回值：**

无

**示例：**

```
function onReceiveEvent(data) {
    console.info('bluetooth state = '+ JSON.stringify(data));
}
bluetooth.on('stateChange', onReceiveEvent);
```


## bluetooth.off('stateChange')

off(type: "stateChange", callback?: Callback&lt;BluetoothState&gt;): void

取消订阅蓝牙连接状态改变事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"stateChange"字符串，表示蓝牙状态改变事件。 |
| callback | Callback&lt;[BluetoothState](#bluetoothstate)&gt; | 否 | 表示取消订阅蓝牙状态改变事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```
function onReceiveEvent(data) {
    console.info('bluetooth state = '+ JSON.stringify(data));
}
bluetooth.on('stateChange', onReceiveEvent);
bluetooth.off('stateChange', onReceiveEvent);
```


## bluetooth.sppListen

sppListen(name: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void

创建一个服务端监听Socket。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 服务的名称。 |
| option | [SppOption](#sppoption) | 是 | spp监听配置参数。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 表示回调函数的入参，服务端Socket的id。 |

**示例：**

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

服务端监听socket等待客户端连接。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| serverSocket | number | 是 | 服务端socket的id。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 表示回调函数的入参，客户端socket的id。 |

**示例：**

```
let clientNumber = -1;
function acceptClientSocket(code, number) {
  console.log('bluetooth error code: ' + code.code);
  if (code.code == 0) {
    console.log('bluetooth clientSocket Number: ' + number);
    // 获取的clientNumber用作服务端后续读/写操作socket的id。
    clientNumber = number;
  }
}
bluetooth.sppAccept(serverNumber, acceptClientSocket);
```


## bluetooth.sppConnect

sppConnect(device: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void

客户端向远端设备发起spp连接。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| device | string | 是 | 对端设备地址，例如："8F:8F:8E:8E:6D:6D"。 |
| option | [SppOption](#sppoption) | 是 | spp客户端连接配置参数。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 表示回调函数的入参，客户端socket的id。 |

**示例：**

```
let clientNumber = -1;
function clientSocket(code, number) {
  if (code.code != 0) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // 获取的clientNumber用作客户端后续读/写操作socket的id。
  clientNumber = number;
}
let sppOption = {uuid: '00001810-0000-1000-8000-00805F9B34FB', secure: false, type: 0};
bluetooth.sppConnect('8F:8F:8E:8E:6D:6D', sppOption, clientSocket);
```


## bluetooth.sppCloseServerSocket

sppCloseServerSocket(socket: number): void

关闭服务端监听Socket，入参socket由sppListen接口返回。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| socket | number | 是 | 服务端监听socket的id。 |

**示例：**

```
bluetooth.sppCloseServerSocket(serverNumber);
```


## bluetooth.sppCloseClientSocket

sppCloseClientSocket(socket: number): void

关闭客户端socket，入参socket由sppAccept或sppConnect接口获取。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| 参数名 | 类型 | 必填 | 说明 |
| socket | number | 是 | 客户端socket的id。 |

**示例：**

```
bluetooth.sppCloseClientSocket(clientNumber);
```


## bluetooth.sppWrite

sppWrite(clientSocket: number, data: ArrayBuffer): boolean

通过socket向远端发送数据，入参clientSocket由sppAccept或sppConnect接口获取 。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| clientSocket | number | 是 | 客户端socket的id。 |
| data | ArrayBuffer | 是 | 写入的数据。 |

**返回值：**

| | |
| -------- | -------- |
| 类型 | 说明 |
| boolean | 写数据操作，成功返回true，否则返回false。 |

**示例：**

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

订阅spp读请求事件，入参clientSocket由sppAccept或sppConnect接口获取。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"sppRead"字符串，表示spp读请求事件。 |
| clientSocket | number | 是 | 客户端socket的id。 |
| callback | Callback&lt;ArrayBuffer&gt; | 是 | 表示回调函数的入参，读取到的数据。 |

**返回值：**

无

**示例：**

```
function dataRead(dataBuffer) {
  let data = new Uint8Array(dataBuffer);
  console.log('bluetooth data is: ' + data[0]);
}
bluetooth.on('sppRead', clientNumber, dataRead);
```


## bluetooth.off('sppRead')

off(type: "sppRead", clientSocket: number, callback?: Callback&lt;ArrayBuffer&gt;): void

取消订阅spp读请求事件，入参clientSocket由sppAccept或sppConnect接口获取。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"sppRead"字符串，表示spp读请求事件。 |
| clientSocket | number | 是 | 客户端Socket的id。 |
| callback | Callback&lt;ArrayBuffer&gt; | 否 | 表示取消订阅spp读请求事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```
bluetooth.off('sppRead', clientNumber);
```


## bluetooth.BLE

### bluetooth.BLE.createGattServer

createGattServer(): GattServer

创建一个可使用的GattServer实例。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [GattServer](#gattserver) | server端类，使用server端方法之前需要创建该类的实例进行操作。 |

**示例：**

```
let gattServer = bluetooth.BLE.createGattServer();
```


### bluetooth.BLE.createGattClientDevice

createGattClientDevice(deviceId: string): GattClientDevice

创建一个可使用的GattClientDevice实例。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceId | string | 是 | 对端设备地址，&nbsp;例如："8F:8F:8E:8E:6D:6D"。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [GattClientDevice](#gattclientdevice) | client端类，使用client端方法之前需要创建该类的实例进行操作。 |

**示例：**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
```


### bluetooth.BLE.getConnectedBLEDevices

getConnectedBLEDevices(): Array&lt;string&gt;

获取和当前设备连接的BLE设备。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array&lt;string&gt; | 返回和当前设备连接BLE设备地址集合。 |

**示例：**

```
let result = bluetooth.BLE.getConnectedBLEDevices();
```


### bluetooth.BLE.startBLEScan

startBLEScan(filters: Array&lt;ScanFilter&gt;, options?: ScanOptions): void

发起BLE扫描流程。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| filters | Array&lt;[ScanFilter](#scanfilter)&gt; | 是 | 表示扫描结果过滤策略集合，如果不使用过滤的方式，该参数设置为null。 |
| options | [ScanOptions](#scanoptions) | 否 | 表示扫描的参数配置，可选参数。 |

**返回值：**

无

**示例：**

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

停止BLE扫描流程。

**返回值：**

无

**示例：**

```
bluetooth.BLE.stopBLEScan();
```


### bluetooth.BLE.on('BLEDeviceFind')

on(type: "BLEDeviceFind", callback: Callback&lt;Array&lt;ScanResult&gt;&gt;): void

订阅BLE设备发现上报事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"BLEDeviceFind"字符串，表示BLE设备发现事件。 |
| callback | Callback&lt;Array&lt;[ScanResult](#scanresult)&gt;&gt; | 是 | 表示回调函数的入参，发现的设备集合。回调函数由用户创建通过该接口注册。 |

**返回值：**

无

**示例：**

```
function onReceiveEvent(data) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
bluetooth.BLE.on('BLEDeviceFind', onReceiveEvent);
```


### bluetooth.BLE.off('BLEDeviceFind')

off(type: "BLEDeviceFind", callback?: Callback&lt;Array&lt;ScanResult&gt;&gt;): void

取消订阅BLE设备发现上报事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"BLEDeviceFind"字符串，表示BLE设备发现事件。 |
| callback | Callback&lt;Array&lt;[ScanResult](#scanresult)&gt;&gt; | 否 | 表示取消订阅BLE设备发现事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```
function onReceiveEvent(data) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
bluetooth.BLE.on('BLEDeviceFind', onReceiveEvent);
bluetooth.BLE.off('BLEDeviceFind', onReceiveEvent);
```


## GattServer

server端类，使用server端方法之前需要创建该类的实例进行操作，通过createGattServer()方法构造此实例。


### startAdvertising

startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void

开始发送BLE广播。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| setting | [AdvertiseSetting](#advertisesetting) | 是 | BLE广播的相关参数。 |
| advData | [AdvertiseData](#advertisedata) | 是 | BLE广播包内容。 |
| advResponse | [AdvertiseData](#advertisedata) | 否 | BLE回复扫描请求回复响应。 |

**返回值：**

无

**示例：**

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

停止发送BLE广播。

**返回值：**

无

**示例：**

```
let server = bluetooth.BLE.createGattServer();
server.stopAdvertising();
```


### addService

addService(service: GattService): boolean

server端添加服务。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| service | [GattService](#gattservice) | 是 | 服务端的service数据。BLE广播的相关参数 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 添加服务操作，成功返回true，否则返回false。 |

**示例：**

```
// 创建descriptors
let descriptors = [];
let arrayBuffer = new ArrayBuffer(8);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
let descriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00001830-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;

// 创建characteristics
let characteristics = [];
let arrayBufferC = new ArrayBuffer(8);
let cccV = new Uint8Array(arrayBufferC);
cccV[0] = 1;
let characteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
let characteristicN = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001821-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptorsN};
characteristics[0] = characteristic;

// 创建gattService
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

删除已添加的服务。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| serviceUuid | string | 是 | service的UUID，例如“00001810-0000-1000-8000-00805F9B34FB”。 |

**返回值：**

| | |
| -------- | -------- |
| 类型 | 说明 |
| boolean | 删除服务操作，成功返回true，否则返回false。 |

**示例：**

```
let server = bluetooth.BLE.createGattServer();
server.removeService('00001810-0000-1000-8000-00805F9B34FB');
```


### close

close(): void

关闭服务端功能，去注册server在协议栈的注册，调用该接口后[GattServer](#gattserver)实例将不能再使用。

**示例：**

```
let server = bluetooth.BLE.createGattServer();
server.close();
```


### notifyCharacteristicChanged

notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): boolean

server端特征值发生变化时，主动通知已连接的client设备。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceId | string | 是 | 接收通知的client端设备地址，例如“8F:8F:8E:8E:6D:6D”。 |
| notifyCharacteristic | [NotifyCharacteristic](#notifycharacteristic) | 是 | 通知的特征值数据。 |

**返回值：**

| | |
| -------- | -------- |
| 类型 | 说明 |
| boolean | 通知操作，成功返回true，否则返回false。 |

**示例：**

```
let notifyCharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001821-0000-1000-8000-00805F9B34FB', characteristicValue:  notifyCcc.characteristicValue, confirm: false};
let server = bluetooth.BLE.createGattServer();
server.notifyCharacteristicChanged('8F:8F:8E:8E:6D:6D', notifyCharacteristic);
```


### sendResponse

sendResponse(serverResponse: ServerResponse): boolean

server端回复client端的读写请求。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| serverResponse | [ServerResponse](#serverresponse) | 是 | server端回复的响应数据。 |

**返回值：**

| | |
| -------- | -------- |
| 类型 | 说明 |
| boolean | 回复响应操作，成功返回true，否则返回false。 |

**示例：**

```
/* send response */
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

server端订阅特征值读请求事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"characteristicRead"字符串，表示特征值读请求事件。 |
| callback | Callback&lt;[CharacteristicReadReq](#characteristicreadreq)&gt; | 是 | 表示回调函数的入参，client端发送的读请求数据。 |

**返回值：**

无

**示例：**

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

server端取消订阅特征值读请求事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"characteristicRead"字符串，表示特征值读请求事件。 |
| callback | Callback&lt;[CharacteristicReadReq](#characteristicreadreq)&gt; | 否 | 表示取消订阅特征值读请求事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```
let gattServer = bluetooth.BLE.createGattServer();
gattServer.off("characteristicRead");
```


### on('characteristicWrite')

on(type: "characteristicWrite", callback: Callback&lt;CharacteristicWriteReq&gt;): void

server端订阅特征值写请求事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"characteristicWrite"字符串，表示特征值写请求事件。 |
| callback | Callback&lt;[DescriptorWriteReq](#descriptorwritereq)&gt; | 是 | 表示回调函数的入参，client端发送的写请求数据。 |

**返回值：**

无

**示例：**

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

server端取消订阅特征值写请求事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"characteristicWrite"字符串，表示特征值写请求事件。 |
| callback | Callback&lt;[CharacteristicWriteReq](#characteristicwritereq)&gt; | 否 | 表示取消订阅特征值写请求事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```
let gattServer = bluetooth.BLE.createGattServer();
gattServer.off("characteristicWrite");
```


### on('descriptorRead')

on(type: "descriptorRead", callback: Callback&lt;DescriptorReadReq&gt;): void

server端订阅描述符读请求事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"descriptorRead"字符串，表示描述符读请求事件。 |
| callback | Callback&lt;[DescriptorReadReq](#descriptorreadreq)&gt; | 是 | 表示回调函数的入参，client端发送的读请求数据。 |

**返回值：**

无

**示例：**

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

server端取消订阅描述符读请求事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"descriptorRead"字符串，表示描述符读请求事件。 |
| callback | Callback&lt;[DescriptorReadReq](#descriptorreadreq)&gt; | 否 | 表示取消订阅描述符读请求事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```
let gattServer = bluetooth.BLE.createGattServer();
gattServer.off("descriptorRead");
```


### on('descriptorWrite')

on(type: "descriptorWrite", callback: Callback&lt;DescriptorWriteReq&gt;): void

server端订阅描述符写请求事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"descriptorWrite"字符串，表示描述符写请求事件。 |
| callback | Callback&lt;[DescriptorWriteReq](#descriptorwritereq)&gt; | 是 | 表示回调函数的入参，client端发送的写请求数据。 |

**返回值：**

无

**示例：**

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

server端取消订阅描述符写请求事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"descriptorWrite"字符串，表示描述符写请求事件。 |
| callback | Callback&lt;[DescriptorWriteReq](#descriptorwritereq)&gt; | 否 | 表示取消订阅描述符读请求事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```
let gattServer = bluetooth.BLE.createGattServer();
gattServer.off("descriptorWrite");
```


### on('connectStateChange')

on(type: "connectStateChange", callback: Callback&lt;BLEConnectChangedState&gt;): void

server端订阅BLE连接状态变化事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"connectStateChange"字符串，表示BLE连接状态变化事件。 |
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstate)&gt; | 是 | 表示回调函数的入参，连接状态。 |

**返回值：**

无

**示例：**

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

server端取消订阅BLE连接状态变化事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"connectStateChange"字符串，表示BLE连接状态变化事件。 |
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstate)&gt; | 否 | 表示取消订阅BLE连接状态变化事件。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```
let gattServer = bluetooth.BLE.createGattServer();
gattServer.off("connectStateChange");
```


## GattClientDevice

client端类，使用client端方法之前需要创建该类的实例进行操作，通过createGattClientDevice(deviceId: string)方法构造此实例。


### connect

connect(): boolean

client端发起连接远端蓝牙低功耗设备。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 连接操作成功返回true，操作失败返回false。 |

**示例：**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
let ret = device.connect();
```


### disconnect

disconnect(): boolean

client端断开与远端蓝牙低功耗设备的连接。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 连接操作，成功返回true，操作失败返回false。 |

**示例：**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
let ret = device.disconnect();
```


### close

close(): boolean

关闭客户端功能，注销client在协议栈的注册，调用该接口后[GattClientDevice](#gattclientdevice)实例将不能再使用。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 关闭操作，成功返回true，操作失败返回false。 |

**示例：**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
let ret = device.close();
```




### getServices

getServices(callback: AsyncCallback&lt;Array&lt;GattService&gt;&gt;): void

client端获取蓝牙低功耗设备的所有服务，即服务发现 。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[GattService](#gattservice)&gt;&gt; | 是 | client进行服务发现，通过注册回调函数获取。 |

**返回值：**

无

**示例：**

```
// callkback 模式
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

client端获取蓝牙低功耗设备的所有服务，即服务发现。

**参数：**

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[GattService](#gattservice)&gt;&gt; | client进行服务发现，通过promise形式获取。 |

**示例：**

```
// Promise 模式
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

client端读取蓝牙低功耗设备特定服务的特征值。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | 是 | 待读取的特征值。 |
| callback | AsyncCallback&lt;[BLECharacteristic](#blecharacteristic)&gt; | 是 | client读取特征值，通过注册回调函数获取。 |

**返回值：**

无

**示例：**

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

client端读取蓝牙低功耗设备特定服务的特征值。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | 是 | 待读取的特征值。 |

**返回值：**

| | |
| -------- | -------- |
| 类型 | 说明 |
| Promise&lt;[BLECharacteristic](#blecharacteristic)&gt; | client读取特征值，通过promise形式获取。 |

**示例：**

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

client端读取蓝牙低功耗设备特定的特征包含的描述符。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| descriptor | [BLEDescriptor](#bledescriptor) | 是 | 待读取的描述符。 |
| callback | AsyncCallback&lt;[BLECharacteristic](#blecharacteristic)&gt; | 是 | client读取描述符，通过注册回调函数获取。 |

**返回值：**

无

**示例：**

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

client端读取蓝牙低功耗设备特定的特征包含的描述符。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| descriptor | [BLEDescriptor](#bledescriptor) | 是 | 待读取的描述符。 |

**返回值：**

| | |
| -------- | -------- |
| 类型 | 说明 |
| Promise&lt;[BLEDescriptor](#bledescriptor)&gt; | client读取描述符，通过promise形式获取。 |

**示例：**

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

client端向低功耗蓝牙设备写入特定的特征值。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | 是 | 蓝牙设备特征对应的二进制值及其它参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 写特征值操作成功返回true，操作失败返回false。 |

**示例：**

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

client端向低功耗蓝牙设备特定的描述符写入二进制数据。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| descriptor | [BLEDescriptor](#bledescriptor) | 是 | 蓝牙设备描述符的二进制值及其它参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 写描述符操作成功返回true，操作失败返回false。 |

**示例：**

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

client协商远端蓝牙低功耗设备的最大传输单元（Maximum Transmission Unit, MTU），调用connect接口连接成功后才能使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mtu | number | 是 | 设置范围为22~512字节。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | MTU协商操作成功返回true，操作失败返回false。 |

**示例：**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
device.setBLEMtuSize(128);
```


### setNotifyCharacteristicChanged

setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): boolean

向服务端发送设置通知此特征值请求。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| characteristic | [BLECharacteristic](#blecharacteristic) | 是 | 蓝牙低功耗特征。 |
| enable | boolean | 是 | 启用接收notify设置为true，否则设置为false。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 设置操作成功返回true，操作失败返回false。 |

**示例：**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
device.setNotifyCharacteristicChanged(notifyCcc, false);
```


### on('BLECharacteristicChange')

on(type: "BLECharacteristicChange", callback: Callback&lt;BLECharacteristic&gt;): void

订阅蓝牙低功耗设备的特征值变化事件。需要先调用setNotifyCharacteristicChanged接口才能接收server端的通知。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"BLECharacteristicChange"字符串，表示特征值变化事件。 |
| callback | Callback&lt;[BLECharacteristic](#blecharacteristic)&gt; | 是 | 表示蓝牙低功耗设备的特征值变化事件的回调函数。 |

**返回值：**

无

**示例：**

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

取消订阅蓝牙低功耗设备的特征值变化事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"BLECharacteristicChange"字符串，表示特征值变化事件。 |
| callback | Callback&lt;[BLECharacteristic](#blecharacteristic)&gt; | 否 | 表示取消订阅蓝牙低功耗设备的特征值变化事件。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
device.off('BLECharacteristicChange');
```


### on('BLEConnectionStateChange')

on(type: "BLEConnectionStateChange", callback: Callback&lt;BLEConnectChangedState&gt;): void

client端订阅蓝牙低功耗设备的连接状态变化事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"BLEConnectionStateChange"字符串，表示连接状态变化事件。 |
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstate)&gt; | 是 | 表示连接状态，已连接或断开。 |

**返回值：**

无

**示例：**

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

取消订阅蓝牙低功耗设备的连接状态变化事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 填写"BLEConnectionStateChange"字符串，表示连接状态变化事件。 |
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstate)&gt; | 否 | 表示取消订阅蓝牙低功耗设备的连接状态变化事件。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```
let device = bluetooth.BLE.createGattClientDevice('8F:8F:8E:8E:6D:6D');
device.off('BLEConnectionStateChange');
```


### getDeviceName

getDeviceName(callback: AsyncCallback&lt;string&gt;): void

client获取远端蓝牙低功耗设备名。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;string&gt; | 是 | client获取对端server设备名，通过注册回调函数获取。 |

**返回值：**

无

**示例：**

```
// callback
let gattClient = bluetooth.BLE.createGattClientDevice("8F:8F:8E:8E:6D:6D");
let deviceName = gattClient.getDeviceName((err, data)=> {
    console.info('device name err ' + JSON.stringify(err));
    console.info('device name' + JSON.stringify(data));
})
```


### getDeviceName

getDeviceName(): Promise&lt;string&gt;

client获取远端蓝牙低功耗设备名。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | client获取对端server设备名，通过promise形式获取。 |

**示例：**

```
// promise
let gattClient = bluetooth.BLE.createGattClientDevice("8F:8F:8E:8E:6D:6D");
let ret = device.connect();
let deviceName = gattClient.getDeviceName().then((data) => {
    console.info('device name' + JSON.stringify(data));
})
```


### getRssiValue

getRssiValue(callback: AsyncCallback&lt;number&gt;): void

client获取远端蓝牙低功耗设备的信号强度 (Received Signal Strength Indication, RSSI)，调用[connect](#connect-boolean)接口连接成功后才能使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;number&gt; | 是 | 返回信号强度，单位&nbsp;dBm，通过注册回调函数获取。 |

**返回值：**

无

**示例：**

```
// callback
let gattClient = bluetooth.BLE.createGattClientDevice("8F:8F:8E:8E:6D:6D");
let ret = device.connect();
let rssi = gattClient.getRssiValue((err, data)=> {
    console.info('rssi err ' + JSON.stringify(err));
    console.info('rssi value' + JSON.stringify(data));
})
```


### getRssiValue

getRssiValue(): Promise&lt;number&gt;

client获取远端蓝牙低功耗设备的信号强度 (Received Signal Strength Indication, RSSI)，调用[connect](#connect-boolean)接口连接成功后才能使用。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | 返回信号强度，单位&nbsp;dBm，通过promise形式获取。 |

**示例：**

```
// promise
let gattClient = bluetooth.BLE.createGattClientDevice("8F:8F:8E:8E:6D:6D");
let rssi = gattClient.getRssiValue().then((data) => {
    console.info('rssi' + JSON.stringify(data));
})
```


## ScanMode

枚举，扫描模式。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| SCAN_MODE_NONE | 0 | 没有扫描模式。 |
| SCAN_MODE_CONNECTABLE | 1 | 可连接扫描模式。 |
| SCAN_MODE_GENERAL_DISCOVERABLE | 2 | general发现模式。 |
| SCAN_MODE_LIMITED_DISCOVERABLE | 3 | limited发现模式。 |
| SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE | 4 | 可连接general发现模式。 |
| SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE | 5 | 可连接limited发现模式。 |


## BondState

枚举，配对状态。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| BOND_STATE_INVALID | 0 | 无效的配对。 |
| BOND_STATE_BONDING | 1 | 正在配对。 |
| BOND_STATE_BONDED | 2 | 已配对。 |


## SppOption

描述spp的配置参数。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| uuid | string | 是 | 是 | spp单据的uuid。 |
| isPrimary | boolean | 是 | 是 | 是否是安全通道。 |
| type | [ERROR:Invalid&nbsp;link:zh-cn_topic_0000001193344974.xml#xref2575mcpsimp,link:#SppType](#SppType) | 是 | 是 | Spp链路类型。 |


## SppType

枚举，Spp链路类型。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| SPP_RFCOMM | 0 | 表示rfcomm链路类型。 |


## GattService

描述service的接口参数定义。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | 是 | 是 | 特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |
| isPrimary | boolean | 是 | 是 | 如果是主服务设置为true，否则设置为false。 |
| characteristics | Array&lt;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001193344974.xml#xref2628mcpsimp,link:#BLECharacteristic](#BLECharacteristic)&gt; | 是 | 是 | 当前服务包含的特征列表。 |
| includeServices | Array&lt;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001193344974.xml#xref2635mcpsimp,link:#GattService](#GattService)&gt; | 是 | 是 | 当前服务依赖的其它服务。 |


## BLECharacteristic

描述characteristic的接口参数定义 。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | 是 | 是 | 特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |
| characteristicUuid | string | 是 | 是 | 特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| characteristicValue | ArrayBuffer | 是 | 是 | 特征对应的二进制值。 |
| descriptors | Array&lt;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001193344974.xml#xref2677mcpsimp,link:#BLEDescriptor](#BLEDescriptor)&gt; | 是 | 是 | 特定特征的描述符列表。 |


## BLEDescriptor

描述descriptor的接口参数定义 。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | 是 | 是 | 特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |
| characteristicUuid | string | 是 | 是 | 特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| descriptorUuid | string | 是 | 是 | 描述符（descriptor）的UUID，例如：00002902-0000-1000-8000-00805f9b34fb。 |
| descriptorValue | ArrayBuffer | 是 | 是 | 描述符对应的二进制值。 |


## NotifyCharacteristic

描述server端特征值变化时发送的特征通知参数定义。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | 是 | 是 | 特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |
| characteristicUuid | string | 是 | 是 | 特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| characteristicValue | ArrayBuffer | 是 | 是 | 特征对应的二进制值。 |
| confirm | boolean | 是 | 是 | 如果是notification则对端回复确认设置为true，如果是indication则对端不需要回复确认设置为false。 |


## CharacteristicReadReq

描述server端订阅后收到的特征值读请求事件参数结构。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | 是 | 否 | 表示发送特征值读请求的远端设备地址，例如："8F:8F:8E:8E:6D:6D"。 |
| transId | number | 是 | 否 | 表示读请求的传输ID，server端回复响应时需填写相同的传输ID。 |
| offset | number | 是 | 否 | 表示读特征值数据的起始位置。例如：k表示从第k个字节开始读，server端回复响应时需填写相同的offset。 |
| characteristicUuid | string | 是 | 否 | 特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| serviceUuid | string | 是 | 否 | 特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |


## CharacteristicWriteReq

描述server端订阅后收到的特征值写请求事件参数结构。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | 是 | 否 | 表示发送特征值写请求的远端设备地址，例如："8F:8F:8E:8E:6D:6D"。 |
| transId | number | 是 | 否 | 表示写请求的传输ID，server端回复响应时需填写相同的传输ID。 |
| offset | number | 是 | 否 | 表示写特征值数据的起始位置。例如：k表示从第k个字节开始写，server端回复响应时需填写相同的offset。 |
| descriptorUuid | string | 是 | 否 | 表示描述符（descriptor）的UUID，例如：00002902-0000-1000-8000-00805f9b34fb。 |
| characteristicUuid | string | 是 | 否 | 特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| serviceUuid | string | 是 | 否 | 特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |


## DescriptorReadReq

描述server端订阅后收到的描述符读请求事件参数结构。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | 是 | 否 | 表示发送描述符读请求的远端设备地址，例如："8F:8F:8E:8E:6D:6D"。 |
| transId | number | 是 | 否 | 表示读请求的传输ID，server端回复响应时需填写相同的传输ID。 |
| offset | number | 是 | 否 | 表示读描述符数据的起始位置。例如：k表示从第k个字节开始读，server端回复响应时需填写相同的offset。 |
| descriptorUuid | string | 是 | 否 | 表示描述符（descriptor）的UUID，例如：00002902-0000-1000-8000-00805f9b34fb。 |
| characteristicUuid | string | 是 | 否 | 特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| serviceUuid | string | 是 | 否 | 特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |


## DescriptorWriteReq

描述server端订阅后收到的描述符写请求事件参数结构。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | 是 | 否 | 表示发送描述符写请求的远端设备地址，例如："8F:8F:8E:8E:6D:6D"。 |
| transId | number | 是 | 否 | 表示写请求的传输ID，server端回复响应时需填写相同的传输ID。 |
| offset | number | 是 | 否 | 表示写描述符数据的起始位置。例如：k表示从第k个字节开始写，server端回复响应时需填写相同的offset。 |
| isPrep | boolean | 是 | 否 | 表示写请求是否立即执行。 |
| needRsp | boolean | 是 | 否 | 表示是否要给client端回复响应。 |
| value | ArrayBuffer | 是 | 否 | 表示写入的描述符二进制数据。 |
| descriptorUuid | string | 是 | 否 | 表示描述符（descriptor）的UUID，例如：00002902-0000-1000-8000-00805f9b34fb。 |
| characteristicUuid | string | 是 | 否 | 特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| serviceUuid | string | 是 | 否 | 特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |


## ServerResponse

描述server端回复client端读/写请求的响应参数结构。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | 是 | 否 | 表示远端设备地址，例如："8F:8F:8E:8E:6D:6D"。 |
| transId | number | 是 | 否 | 表示请求的传输ID，与订阅的读/写请求事件携带的ID保持一致。 |
| status | number | 是 | 否 | 表示响应的状态，设置为0即可，表示正常。 |
| offset | number | 是 | 否 | 表示请求的读/写起始位置，与订阅的读/写请求事件携带的offset保持一致。 |
| value | ArrayBuffer | 是 | 否 | 表示回复响应的二进制数据。 |


## BLEConnectChangedState

描述Gatt profile连接状态 。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | 是 | 否 | 表示远端设备地址，例如："8F:8F:8E:8E:6D:6D"。 |
| state | [ERROR:Invalid&nbsp;link:zh-cn_topic_0000001193344974.xml#xref3060mcpsimp,link:#ProfileConnectionState](#ProfileConnectionState) | 是 | 是 | 表示BLE连接状态的枚举。 |


## ProfileConnectionState

枚举，蓝牙设备的profile连接状态。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| STATE_DISCONNECTED | 0 | 表示profile已断连。 |
| STATE_CONNECTING | 1 | 表示profile正在连接。 |
| STATE_CONNECTED | 2 | 表示profile已连接。 |
| STATE_DISCONNECTING | 3 | 表示profile正在断连。 |


## ScanFilter

扫描过滤参数。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | 是 | 是 | 表示过滤的BLE设备地址，例如："8F:8F:8E:8E:6D:6D"。 |
| name | string | 是 | 是 | 表示过滤的BLE设备名。 |
| serviceUuid | string | 是 | 是 | 表示过滤包含该UUID服务的设备，例如：00001888-0000-1000-8000-00805f9b34fb。 |


## ScanOptions

扫描的配置参数。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| interval | number | 是 | 是 | 表示扫描结果上报延迟时间，默认值为0。 |
| dutyMode | [ERROR:Invalid&nbsp;link:zh-cn_topic_0000001193344974.xml#xref3154mcpsimp,link:#ScanDuty](#ScanDuty) | 是 | 是 | 表示扫描模式，默认值为SCAN_MODE_LOW_POWER。 |
| matchMode | [ERROR:Invalid&nbsp;link:zh-cn_topic_0000001193344974.xml#xref3161mcpsimp,link:#MatchMode](#MatchMode) | 是 | 是 | 表示硬件的过滤匹配模式，默认值为MATCH_MODE_AGGRESSIVE。 |


## ScanDuty

枚举，扫描模式。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| SCAN_MODE_LOW_POWER | 0 | 表示低功耗模式，默认值。 |
| SCAN_MODE_BALANCED | 1 | 表示均衡模式。 |
| SCAN_MODE_LOW_LATENCY | 2 | 表示低延迟模式。 |


## MatchMode

枚举，硬件过滤匹配模式。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| MATCH_MODE_AGGRESSIVE | 1 | 表示硬件上报扫描结果门限较低，比如扫描到的功率较低或者一段时间扫描到的次数较少也触发上报，默认值。 |
| SCAN_MODE_LOW_LATENCY | 2 | 表示硬件上报扫描结果门限较高，更高的功率门限以及扫描到多次才会上报。 |


## ScanResult

扫描结果上报数据。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | 是 | 否 | 表示扫描到的设备地址，例如："8F:8F:8E:8E:6D:6D"。 |
| rssi | number | 是 | 否 | 表示扫描到的设备的rssi值。 |
| data | ArrayBuffer | 是 | 否 | 表示扫描到的设备发送的广播包。 |


## BluetoothState

枚举，蓝牙开关状态。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| STATE_OFF | 0 | 表示蓝牙已关闭。 |
| STATE_TURNING_ON | 1 | 表示蓝牙正在打开。 |
| STATE_ON | 2 | 表示蓝牙已打开。 |
| STATE_TURNING_OFF | 3 | 表示蓝牙正在关闭。 |
| STATE_BLE_TURNING_ON | 4 | 表示蓝牙正在打开LE-only模式。 |
| STATE_BLE_ON | 5 | 表示蓝牙正处于LE-only模式。 |
| STATE_BLE_TURNING_OFF | 6 | 表示蓝牙正在关闭LE-only模式。 |


## AdvertiseSetting

描述蓝牙低功耗设备发送广播的参数。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| interval | number | 是 | 是 | 表示广播间隔，最小值设置32个slot表示20ms，最大值设置16777215个slot，默认值设置为1600个slot表示1s。 |
| txPower | number | 是 | 是 | 表示发送功率，最小值设置-127，最大值设置1，默认值设置-7，单位dbm。 |
| connectable | boolean | 是 | 是 | 表示是否是可连接广播，默认值设置为true。 |


## AdvertiseData

描述BLE广播数据包的内容。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuids | Array&lt;string&gt; | 是 | 是 | 表示要广播的服务&nbsp;UUID&nbsp;列表。 |
| manufactureData | Array&lt;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001193344974.xml#xref3348mcpsimp,link:#ManufactureData](#ManufactureData)&gt; | 是 | 是 | 表示要广播的广播的制造商信息列表。 |
| serviceData | Array&lt;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001193344974.xml#xref3355mcpsimp,link:#ServiceData](#ServiceData)&gt; | 是 | 是 | 表示要广播的服务数据列表。 |


## ManufactureData

描述BLE广播数据包的内容。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| manufactureId | Array&lt;string&gt; | 是 | 是 | 表示制造商的ID，由蓝牙SIG分配。 |
| manufactureValue | ArrayBuffer | 是 | 是 | 表示制造商发送的制造商数据。 |


## ServiceData

描述广播包中服务数据内容。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| serviceUuid | string | 是 | 是 | 表示服务的UUID。 |
| serviceValue | ArrayBuffer | 是 | 是 | 表示服务数据。 |


## PinRequiredParam

描述配对请求参数。

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceId | string | 是 | 否 | 表示要配对的设备ID。 |
| pinCode | string | 是 | 否 | 表示要配对的密钥。 |
