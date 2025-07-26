# @ohos.bluetooth (蓝牙)

蓝牙模块提供了基础的传统蓝牙能力以及BLE的扫描、广播等功能。

> **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 从API Version 9 开始，该接口不再维护，推荐使用[`@ohos.bluetooth.ble`](js-apis-bluetooth-ble.md)等相关profile接口。



## 导入模块

```js
import bluetooth from '@ohos.bluetooth';
```


## bluetooth.enableBluetooth<sup>8+</sup><sup>(deprecated)</sup>

enableBluetooth(): boolean

开启蓝牙。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.enableBluetooth](js-apis-bluetoothManager.md#bluetoothmanagerenablebluetoothdeprecated)替代。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型      | 说明                       |
| ------- | ------------------------ |
| boolean | 打开蓝牙，成功返回true，否则返回false。 |

**示例：**

```js
let enable : boolean = bluetooth.enableBluetooth();
```


## bluetooth.disableBluetooth<sup>8+</sup><sup>(deprecated)</sup>

disableBluetooth(): boolean

关闭蓝牙。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.disableBluetooth](js-apis-bluetoothManager.md#bluetoothmanagerdisablebluetoothdeprecated)替代。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型      | 说明                       |
| ------- | ------------------------ |
| boolean | 关闭蓝牙，成功返回true，否则返回false。 |

**示例：**

```js
let disable : boolean = bluetooth.disableBluetooth();
```


## bluetooth.getLocalName<sup>8+</sup><sup>(deprecated)</sup>

getLocalName(): string

获取蓝牙本地设备名称。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.getLocalName](js-apis-bluetoothManager.md#bluetoothmanagergetlocalnamedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型     | 说明        |
| ------ | --------- |
| string | 蓝牙本地设备名称。 |

**示例：**

```js
let localName : string = bluetooth.getLocalName();
```


## bluetooth.getState<sup>(deprecated)</sup>

getState(): BluetoothState

获取蓝牙开关状态。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.getState](js-apis-bluetoothManager.md#bluetoothmanagergetstatedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型                                | 说明        |
| --------------------------------- | --------- |
| [BluetoothState](#bluetoothstatedeprecated) | 表示蓝牙开关状态。 |

**示例：**

```js
let state : bluetooth.BluetoothState = bluetooth.getState();
```


## bluetooth.getBtConnectionState<sup>(deprecated)</sup>

getBtConnectionState(): ProfileConnectionState

获取蓝牙本端的Profile连接状态，例如：任意一个支持的Profile连接状态为已连接，则此接口返回状态为已连接。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.getBtConnectionState](js-apis-bluetoothManager.md#bluetoothmanagergetbtconnectionstatedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型                                       | 说明                  |
| ---------------------------------------- | ------------------- |
| [ProfileConnectionState](#profileconnectionstatedeprecated) | 表示蓝牙设备的Profile连接状态。 |

**示例：**

```js
let connectionState : bluetooth.ProfileConnectionState = bluetooth.getBtConnectionState();
```


## bluetooth.setLocalName<sup>8+</sup><sup>(deprecated)</sup>

setLocalName(name: string): boolean

设置蓝牙本地设备名称。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.setLocalName](js-apis-bluetoothManager.md#bluetoothmanagersetlocalnamedeprecated)替代。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名  | 类型     | 必填   | 说明                    |
| ---- | ------ | ---- | --------------------- |
| name | string | 是    | 要设置的蓝牙名称，最大长度为248字节数。 |

**返回值：**

| 类型      | 说明                             |
| ------- | ------------------------------ |
| boolean | 设置蓝牙本地设备名称，成功返回true，否则返回false。 |

**示例：**

```js
let ret : boolean = bluetooth.setLocalName('device_name');
```


## bluetooth.pairDevice<sup>(deprecated)</sup>

pairDevice(deviceId: string): boolean

发起蓝牙配对。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.pairDevice](js-apis-bluetoothManager.md#bluetoothmanagerpairdevicedeprecated)替代。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型     | 必填   | 说明                                  |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | 是    | 表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型      | 说明                         |
| ------- | -------------------------- |
| boolean | 发起蓝牙配对，成功返回true，否则返回false。 |

**示例：**

```js
// 实际的地址可由扫描流程获取
let result : boolean = bluetooth.pairDevice("XX:XX:XX:XX:XX:XX");
```


## bluetooth.getProfileConnState<sup>8+</sup><sup>(deprecated)</sup>

getProfileConnState(profileId: ProfileId): ProfileConnectionState

依据ProfileId获取指定profile的连接状态。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.getProfileConnectionState](js-apis-bluetoothManager.md#bluetoothmanagergetprofileconnectionstatedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名       | 类型        | 必填   | 说明                                    |
| --------- | --------- | ---- | ------------------------------------- |
| profileId | ProfileId | 是    | 表示profile的枚举值，例如：PROFILE_A2DP_SOURCE。 |

**返回值：**

| 类型                                              | 说明                |
| ------------------------------------------------- | ------------------- |
| [ProfileConnectionState](#profileconnectionstatedeprecated) | profile的连接状态。 |

**示例：**

```js
let result : bluetooth.ProfileConnectionState = bluetooth.getProfileConnState(bluetooth.ProfileId.PROFILE_A2DP_SOURCE);
```


## bluetooth.getRemoteDeviceName<sup>8+</sup><sup>(deprecated)</sup>

getRemoteDeviceName(deviceId: string): string

获取对端蓝牙设备的名称。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.getRemoteDeviceName](js-apis-bluetoothManager.md#bluetoothmanagergetremotedevicenamedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型     | 必填   | 说明                                |
| -------- | ------ | ---- | --------------------------------- |
| deviceId | string | 是    | 表示远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型     | 说明            |
| ------ | ------------- |
| string | 以字符串格式返回设备名称。 |

**示例：**

```js
let remoteDeviceName : string = bluetooth.getRemoteDeviceName("XX:XX:XX:XX:XX:XX");
```


## bluetooth.getRemoteDeviceClass<sup>8+</sup><sup>(deprecated)</sup>

getRemoteDeviceClass(deviceId: string): DeviceClass

获取对端蓝牙设备的类别。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.getRemoteDeviceClass](js-apis-bluetoothManager.md#bluetoothmanagergetremotedeviceclassdeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型     | 必填   | 说明                                |
| -------- | ------ | ---- | --------------------------------- |
| deviceId | string | 是    | 表示远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                          | 说明       |
| --------------------------- | -------- |
| [DeviceClass](#deviceclassdeprecated) | 远程设备的类别。 |

**示例：**

```js
let remoteDeviceClass : bluetooth.DeviceClass = bluetooth.getRemoteDeviceClass("XX:XX:XX:XX:XX:XX");
```


## bluetooth.getPairedDevices<sup>8+</sup><sup>(deprecated)</sup>

getPairedDevices(): Array&lt;string&gt;

获取蓝牙配对列表。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.getPairedDevices](js-apis-bluetoothManager.md#bluetoothmanagergetpaireddevicesdeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
| Array&lt;string&gt; | 已配对蓝牙设备的地址列表。 |

**示例：**

```js
let devices : Array<string> = bluetooth.getPairedDevices();
```


## bluetooth.setBluetoothScanMode<sup>(deprecated)</sup>

setBluetoothScanMode(mode: ScanMode, duration: number): boolean

设置蓝牙扫描模式，可以被远端设备发现。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.setBluetoothScanMode](js-apis-bluetoothManager.md#bluetoothmanagersetbluetoothscanmodedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                    | 必填   | 说明                           |
| -------- | --------------------- | ---- | ---------------------------- |
| mode     | [ScanMode](#scanmodedeprecated) | 是    | 蓝牙扫描模式。                      |
| duration | number                | 是    | 设备可被发现的持续时间，单位为毫秒；设置为0则持续可发现。 |

**返回值：**

| 类型      | 说明                         |
| ------- | -------------------------- |
| boolean | 设置蓝牙扫描，成功返回true，否则返回false。 |

**示例：**

```js
// 设置为可连接可发现才可被远端设备扫描到，可以连接。
let result : boolean = bluetooth.setBluetoothScanMode(bluetooth.ScanMode
    .SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE, 100);
```


## bluetooth.getBluetoothScanMode<sup>8+</sup><sup>(deprecated)</sup>

getBluetoothScanMode(): ScanMode

获取蓝牙扫描模式。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.getBluetoothScanMode](js-apis-bluetoothManager.md#bluetoothmanagergetbluetoothscanmodedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型                    | 说明      |
| --------------------- | ------- |
| [ScanMode](#scanmodedeprecated) | 蓝牙扫描模式。 |

**示例：**

```js
let scanMode : bluetooth.ScanMode = bluetooth.getBluetoothScanMode();
```


## bluetooth.startBluetoothDiscovery<sup>8+</sup><sup>(deprecated)</sup>

startBluetoothDiscovery(): boolean

开启蓝牙扫描，可以发现远端设备。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.startBluetoothDiscovery](js-apis-bluetoothManager.md#bluetoothmanagerstartbluetoothdiscoverydeprecated)替代。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH 和 ohos.permission.LOCATION

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型      | 说明                         |
| ------- | -------------------------- |
| boolean | 开启蓝牙扫描，成功返回true，否则返回false。 |

**示例：**

```js
let deviceId : Array<string>;
function onReceiveEvent(data : Array<string>) {
    deviceId = data;
}
bluetooth.on('bluetoothDeviceFind', onReceiveEvent);
let result : boolean = bluetooth.startBluetoothDiscovery();
```


## bluetooth.stopBluetoothDiscovery<sup>8+</sup><sup>(deprecated)</sup>

stopBluetoothDiscovery(): boolean

关闭蓝牙扫描。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.stopBluetoothDiscovery](js-apis-bluetoothManager.md#bluetoothmanagerstopbluetoothdiscoverydeprecated)替代。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型      | 说明                         |
| ------- | -------------------------- |
| boolean | 关闭蓝牙扫描，成功返回true，否则返回false。 |

**示例：**

```js
let result : boolean = bluetooth.stopBluetoothDiscovery();
```


## bluetooth.setDevicePairingConfirmation<sup>8+</sup><sup>(deprecated)</sup>

setDevicePairingConfirmation(device: string, accept: boolean): boolean

设置设备配对请求确认。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.setDevicePairingConfirmation](js-apis-bluetoothManager.md#bluetoothmanagersetdevicepairingconfirmationdeprecated)替代。

**需要权限**：ohos.permission.MANAGE_BLUETOOTH（该权限仅系统应用可申请）

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型      | 必填   | 说明                               |
| ------ | ------- | ---- | -------------------------------- |
| device | string  | 是    | 表示远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| accept | boolean | 是    | 接受配对请求设置为true，否则设置为false。        |

**返回值：**

| 类型      | 说明                           |
| ------- | ---------------------------- |
| boolean | 设置设备配对确认，成功返回true，否则返回false。 |

**示例：**

```js
// 订阅“pinRequired”配对请求事件，收到远端配对请求后设置配对确认
function onReceivePinRequiredEvent(data : bluetooth.PinRequiredParam) { // data为配对请求的入参，配对请求参数
    console.info('pin required  = '+ JSON.stringify(data));
    bluetooth.setDevicePairingConfirmation(data.deviceId, true);
}
bluetooth.on("pinRequired", onReceivePinRequiredEvent);
```


## bluetooth.on('bluetoothDeviceFind')<sup>8+</sup><sup>(deprecated)</sup>

on(type: 'bluetoothDeviceFind', callback: Callback&lt;Array&lt;string&gt;&gt;): void

订阅蓝牙设备发现上报事件。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.on('bluetoothDeviceFind')](js-apis-bluetoothManager.md#bluetoothmanageronbluetoothdevicefinddeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                  | 必填   | 说明                                     |
| -------- | ----------------------------------- | ---- | -------------------------------------- |
| type     | string                              | 是    | 填写"bluetoothDeviceFind"字符串，表示蓝牙设备发现事件。 |
| callback | Callback&lt;Array&lt;string&gt;&gt; | 是    | 表示回调函数的入参，发现的设备集合。回调函数由用户创建通过该接口注册。    |

**返回值：**

无

**示例：**

```js
function onReceiveEvent(data : Array<string>) { // data为蓝牙设备地址集合
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
bluetooth.on('bluetoothDeviceFind', onReceiveEvent);
```


## bluetooth.off('bluetoothDeviceFind')<sup>8+</sup><sup>(deprecated)</sup>

off(type: 'bluetoothDeviceFind', callback?: Callback&lt;Array&lt;string&gt;&gt;): void

取消订阅蓝牙设备发现上报事件。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.off('bluetoothDeviceFind')](js-apis-bluetoothManager.md#bluetoothmanageroffbluetoothdevicefinddeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                  | 必填   | 说明                                       |
| -------- | ----------------------------------- | ---- | ---------------------------------------- |
| type     | string                              | 是    | 填写"bluetoothDeviceFind"字符串，表示蓝牙设备发现事件。   |
| callback | Callback&lt;Array&lt;string&gt;&gt; | 否    | 表示取消订阅蓝牙设备发现事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```js
function onReceiveEvent(data : Array<string>) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
bluetooth.on('bluetoothDeviceFind', onReceiveEvent);
bluetooth.off('bluetoothDeviceFind', onReceiveEvent);
```


## bluetooth.on('pinRequired')<sup>8+</sup><sup>(deprecated)</sup>

on(type: 'pinRequired', callback: Callback&lt;PinRequiredParam&gt;): void

订阅远端蓝牙设备的配对请求事件。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.on('pinRequired')](js-apis-bluetoothManager.md#bluetoothmanageronpinrequireddeprecated)替代。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                               |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| type     | string                                   | 是    | 填写"pinRequired"字符串，表示配对请求事件。     |
| callback | Callback&lt;[PinRequiredParam](#pinrequiredparamdeprecated)&gt; | 是    | 表示回调函数的入参，配对请求。回调函数由用户创建通过该接口注册。 |

**返回值：**

无

**示例：**

```js
function onReceiveEvent(data : bluetooth.PinRequiredParam) { // data为配对请求参数
    console.info('pin required = '+ JSON.stringify(data));
}
bluetooth.on('pinRequired', onReceiveEvent);
```


## bluetooth.off('pinRequired')<sup>8+</sup><sup>(deprecated)</sup>

off(type: 'pinRequired', callback?: Callback&lt;PinRequiredParam&gt;): void

取消订阅远端蓝牙设备的配对请求事件。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.off('pinRequired')](js-apis-bluetoothManager.md#bluetoothmanageroffpinrequireddeprecated)替代。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"pinRequired"字符串，表示配对请求事件。             |
| callback | Callback&lt;[PinRequiredParam](#pinrequiredparamdeprecated)&gt; | 否    | 表示取消订阅蓝牙配对请求事件上报，入参为配对请求参数。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```js
function onReceiveEvent(data : bluetooth.PinRequiredParam) {
    console.info('pin required = '+ JSON.stringify(data));
}
bluetooth.on('pinRequired', onReceiveEvent);
bluetooth.off('pinRequired', onReceiveEvent);
```


## bluetooth.on('bondStateChange')<sup>(deprecated)</sup>

on(type: 'bondStateChange', callback: Callback&lt;BondStateParam&gt;): void

订阅蓝牙配对状态改变事件。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.on('bondStateChange')](js-apis-bluetoothManager.md#bluetoothmanageronbondstatechangedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                   |
| -------- | ---------------------------------------- | ---- | ------------------------------------ |
| type     | string                                   | 是    | 填写"bondStateChange"字符串，表示蓝牙配对状态改变事件。 |
| callback | Callback&lt;[BondStateParam](#bondstateparamdeprecated)&gt; | 是    | 表示回调函数的入参，配对的状态。回调函数由用户创建通过该接口注册。    |

**返回值：**

无

**示例：**

```js
function onReceiveEvent(data : bluetooth.BondStateParam) { // data为回调函数入参，表示配对的状态
    console.info('pair state = '+ JSON.stringify(data));
}
bluetooth.on('bondStateChange', onReceiveEvent);
```


## bluetooth.off('bondStateChange')<sup>8+</sup><sup>(deprecated)</sup>

off(type: 'bondStateChange', callback?: Callback&lt;BondStateParam&gt;): void

取消订阅蓝牙配对状态改变事件。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.off('bondStateChange')](js-apis-bluetoothManager.md#bluetoothmanageroffbondstatechangedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"bondStateChange"字符串，表示蓝牙配对状态改变事件。     |
| callback | Callback&lt;[BondStateParam](#bondstateparamdeprecated)&gt; | 否    | 表示取消订阅蓝牙配对状态改变事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```js
function onReceiveEvent(data : bluetooth.BondStateParam) {
    console.info('bond state = '+ JSON.stringify(data));
}
bluetooth.on('bondStateChange', onReceiveEvent);
bluetooth.off('bondStateChange', onReceiveEvent);
```


## bluetooth.on('stateChange')<sup>8+</sup><sup>(deprecated)</sup>

on(type: 'stateChange', callback: Callback&lt;BluetoothState&gt;): void

订阅蓝牙连接状态改变事件。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.on('stateChange')](js-apis-bluetoothManager.md#bluetoothmanageronstatechangedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                               |
| -------- | ---------------------------------------- | ---- | -------------------------------- |
| type     | string                                   | 是    | 填写"stateChange"字符串，表示蓝牙状态改变事件。   |
| callback | Callback&lt;[BluetoothState](#bluetoothstatedeprecated)&gt; | 是    | 表示回调函数的入参，蓝牙状态。回调函数由用户创建通过该接口注册。 |

**返回值：**

无

**示例：**

```js
function onReceiveEvent(data : bluetooth.BluetoothState) {
    console.info('bluetooth state = '+ JSON.stringify(data));
}
bluetooth.on('stateChange', onReceiveEvent);
```


## bluetooth.off('stateChange')<sup>8+</sup><sup>(deprecated)</sup>

off(type: 'stateChange', callback?: Callback&lt;BluetoothState&gt;): void

取消订阅蓝牙连接状态改变事件。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.off('stateChange')](js-apis-bluetoothManager.md#bluetoothmanageroffstatechangedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"stateChange"字符串，表示蓝牙状态改变事件。           |
| callback | Callback&lt;[BluetoothState](#bluetoothstatedeprecated)&gt; | 否    | 表示取消订阅蓝牙状态改变事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```js
function onReceiveEvent(data : bluetooth.BluetoothState) {
    console.info('bluetooth state = '+ JSON.stringify(data));
}
bluetooth.on('stateChange', onReceiveEvent);
bluetooth.off('stateChange', onReceiveEvent);
```


## bluetooth.sppListen<sup>8+</sup><sup>(deprecated)</sup>

sppListen(name: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void

创建一个服务端监听Socket。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.sppListen](js-apis-bluetoothManager.md#bluetoothmanagerspplistendeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                          | 必填   | 说明                      |
| -------- | --------------------------- | ---- | ----------------------- |
| name     | string                      | 是    | 服务的名称。                  |
| option   | [SppOption](#sppoptiondeprecated)     | 是    | spp监听配置参数。              |
| callback | AsyncCallback&lt;number&gt; | 是    | 表示回调函数的入参，服务端Socket的id。 |

**示例：**

```js
import { BusinessError } from '@ohos.base';
let serverNumber = -1;
function serverSocket(code : BusinessError, number : number) {
  console.log('bluetooth error code: ' + code.code);
  if (code.code == 0) {
    console.log('bluetooth serverSocket Number: ' + number);
    serverNumber = number;
  }
}

let sppOption : bluetooth.SppOption = {uuid: '00001810-0000-1000-8000-00805F9B34FB', secure: false, type: 0};
bluetooth.sppListen('server1', sppOption, serverSocket);
```


## bluetooth.sppAccept<sup>8+</sup><sup>(deprecated)</sup>

sppAccept(serverSocket: number, callback: AsyncCallback&lt;number&gt;): void

服务端监听socket等待客户端连接。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.sppAccept](js-apis-bluetoothManager.md#bluetoothmanagersppacceptdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名          | 类型                          | 必填   | 说明                      |
| ------------ | --------------------------- | ---- | ----------------------- |
| serverSocket | number                      | 是    | 服务端socket的id。           |
| callback     | AsyncCallback&lt;number&gt; | 是    | 表示回调函数的入参，客户端socket的id。 |

**示例：**

```js
import { BusinessError } from '@ohos.base';
let serverNumber = -1;
function serverSocket(code : BusinessError, number : number) {
  console.log('bluetooth error code: ' + code.code);
  if (code.code == 0) {
    console.log('bluetooth serverSocket Number: ' + number);
    serverNumber = number;
  }
}
let clientNumber = -1;
function acceptClientSocket(code : BusinessError, number : number) {
  console.log('bluetooth error code: ' + code.code);
  if (code.code == 0) {
    console.log('bluetooth clientSocket Number: ' + number);
    // 获取的clientNumber用作服务端后续读/写操作socket的id。
    clientNumber = number;
  }
}
bluetooth.sppAccept(serverNumber, acceptClientSocket);
```


## bluetooth.sppConnect<sup>(deprecated)</sup>

sppConnect(device: string, option: SppOption, callback: AsyncCallback&lt;number&gt;): void

客户端向远端设备发起spp连接。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.sppConnect](js-apis-bluetoothManager.md#bluetoothmanagersppconnectdeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                          | 必填   | 说明                             |
| -------- | --------------------------- | ---- | ------------------------------ |
| device   | string                      | 是    | 对端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| option   | [SppOption](#sppoptiondeprecated)     | 是    | spp客户端连接配置参数。                  |
| callback | AsyncCallback&lt;number&gt; | 是    | 表示回调函数的入参，客户端socket的id。        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
let clientNumber = -1;
function clientSocket(code : BusinessError, number : number) {
  if (code.code != 0 || code == null) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // 获取的clientNumber用作客户端后续读/写操作socket的id。
  clientNumber = number;
}
let sppOption : bluetooth.SppOption = {uuid: '00001810-0000-1000-8000-00805F9B34FB', secure: false, type: 0};
bluetooth.sppConnect('XX:XX:XX:XX:XX:XX', sppOption, clientSocket);
```


## bluetooth.sppCloseServerSocket<sup>8+</sup><sup>(deprecated)</sup>

sppCloseServerSocket(socket: number): void

关闭服务端监听Socket，入参socket由sppListen接口返回。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.sppCloseServerSocket](js-apis-bluetoothManager.md#bluetoothmanagersppcloseserversocketdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明              |
| ------ | ------ | ---- | --------------- |
| socket | number | 是    | 服务端监听socket的id。 |

**示例：**

```js
import { BusinessError } from '@ohos.base';
let serverNumber = -1;
function serverSocket(code : BusinessError, number : number) {
  console.log('bluetooth error code: ' + code.code);
  if (code.code == 0) {
    console.log('bluetooth serverSocket Number: ' + number);
    serverNumber = number;
  }
}
bluetooth.sppCloseServerSocket(serverNumber);
```


## bluetooth.sppCloseClientSocket<sup>8+</sup><sup>(deprecated)</sup>

sppCloseClientSocket(socket: number): void

关闭客户端socket，入参socket由sppAccept或sppConnect接口获取。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.sppCloseClientSocket](js-apis-bluetoothManager.md#bluetoothmanagersppcloseclientsocketdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------------- |
| socket | number | 是    | 客户端socket的id。 |

**示例：**

```js
import { BusinessError } from '@ohos.base';
let clientNumber = -1;
function clientSocket(code : BusinessError, number : number) {
  if (code.code != 0 || code == null) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // 获取的clientNumber用作客户端后续读/写操作socket的id。
  clientNumber = number;
}
bluetooth.sppCloseClientSocket(clientNumber);
```


## bluetooth.sppWrite<sup>8+</sup><sup>(deprecated)</sup>

sppWrite(clientSocket: number, data: ArrayBuffer): boolean

通过socket向远端发送数据，入参clientSocket由sppAccept或sppConnect接口获取 。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.sppWrite](js-apis-bluetoothManager.md#bluetoothmanagersppwritedeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名          | 类型          | 必填   | 说明            |
| ------------ | ----------- | ---- | ------------- |
| clientSocket | number      | 是    | 客户端socket的id。 |
| data         | ArrayBuffer | 是    | 写入的数据。        |

**返回值：**

| 类型      | 说明                        |
| ------- | ------------------------- |
| boolean | 写数据操作，成功返回true，否则返回false。 |

**示例：**

```js
import { BusinessError } from '@ohos.base';
let clientNumber = -1;
function clientSocket(code : BusinessError, number : number) {
  if (code.code != 0 || code == null) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // 获取的clientNumber用作客户端后续读/写操作socket的id。
  clientNumber = number;
}
let arrayBuffer = new ArrayBuffer(8);
let data = new Uint8Array(arrayBuffer);
data[0] = 123;
let ret : boolean = bluetooth.sppWrite(clientNumber, arrayBuffer);
if (ret) {
  console.log('spp write successfully');
} else {
  console.log('spp write failed');
}
```


## bluetooth.on('sppRead')<sup>8+</sup><sup>(deprecated)</sup>

on(type: 'sppRead', clientSocket: number, callback: Callback&lt;ArrayBuffer&gt;): void

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.on('sppRead')](js-apis-bluetoothManager.md#bluetoothmanageronsppreaddeprecated)替代。

订阅spp读请求事件，入参clientSocket由sppAccept或sppConnect接口获取。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名          | 类型                          | 必填   | 说明                         |
| ------------ | --------------------------- | ---- | -------------------------- |
| type         | string                      | 是    | 填写"sppRead"字符串，表示spp读请求事件。 |
| clientSocket | number                      | 是    | 客户端socket的id。              |
| callback     | Callback&lt;ArrayBuffer&gt; | 是    | 表示回调函数的入参，读取到的数据。          |

**返回值：**

无

**示例：**

```js
import { BusinessError } from '@ohos.base';
let clientNumber = -1;
function clientSocket(code : BusinessError, number : number) {
  if (code.code != 0 || code == null) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // 获取的clientNumber用作客户端后续读/写操作socket的id。
  clientNumber = number;
}
function dataRead(dataBuffer : ArrayBuffer) {
  let data = new Uint8Array(dataBuffer);
  console.log('bluetooth data is: ' + data[0]);
}
bluetooth.on('sppRead', clientNumber, dataRead);
```


## bluetooth.off('sppRead')<sup>8+</sup><sup>(deprecated)</sup>

off(type: 'sppRead', clientSocket: number, callback?: Callback&lt;ArrayBuffer&gt;): void

取消订阅spp读请求事件，入参clientSocket由sppAccept或sppConnect接口获取。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.off('sppRead')](js-apis-bluetoothManager.md#bluetoothmanageroffsppreaddeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名          | 类型                          | 必填   | 说明                                       |
| ------------ | --------------------------- | ---- | ---------------------------------------- |
| type         | string                      | 是    | 填写"sppRead"字符串，表示spp读请求事件。               |
| clientSocket | number                      | 是    | 客户端Socket的id。                            |
| callback     | Callback&lt;ArrayBuffer&gt; | 否    | 表示取消订阅spp读请求事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```js
import { BusinessError } from '@ohos.base';
let clientNumber = -1;
function clientSocket(code : BusinessError, number : number) {
  if (code.code != 0 || code == null) {
    return;
  }
  console.log('bluetooth serverSocket Number: ' + number);
  // 获取的clientNumber用作客户端后续读/写操作socket的id。
  clientNumber = number;
}
bluetooth.off('sppRead', clientNumber);
```


## bluetooth.getProfile<sup>8+</sup><sup>(deprecated)</sup>

getProfile(profileId: ProfileId): A2dpSourceProfile | HandsFreeAudioGatewayProfile

通过ProfileId，获取profile的对象实例。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.getProfileInstance](js-apis-bluetoothManager.md#bluetoothmanagergetprofileinstancedeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名       | 类型        | 必填   | 说明                                    |
| --------- | --------- | ---- | ------------------------------------- |
| profileId | [ProfileId](#profileiddeprecated) | 是    | 表示profile的枚举值，例如：PROFILE_A2DP_SOURCE。 |

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [A2dpSourceProfile](#a2dpsourceprofile)或[HandsFreeAudioGatewayProfile](#handsfreeaudiogatewayprofile) | 对应的profile的对象实例，当前支持A2dpSourceProfile， HandsFreeAudioGatewayProfile。 |

**示例：**

```js
let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;
```


## BLE

### createGattServer<sup>(deprecated)</sup>

createGattServer(): GattServer

创建一个可使用的GattServer实例。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.BLE.createGattServer](js-apis-bluetoothManager.md#creategattserverdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型                        | 说明                                   |
| ------------------------- | ------------------------------------ |
| [GattServer](#gattserver) | server端类，使用server端方法之前需要创建该类的实例进行操作。 |

**示例：**

```js
let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();
```


### createGattClientDevice<sup>(deprecated)</sup>

createGattClientDevice(deviceId: string): GattClientDevice

创建一个可使用的GattClientDevice实例。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.BLE.createGattClientDevice](js-apis-bluetoothManager.md#creategattclientdevicedeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型     | 必填   | 说明                                   |
| -------- | ------ | ---- | ------------------------------------ |
| deviceId | string | 是    | 对端设备地址，&nbsp;例如："XX:XX:XX:XX:XX:XX"。 |

**返回值：**

| 类型                                    | 说明                                   |
| ------------------------------------- | ------------------------------------ |
| [GattClientDevice](#gattclientdevice) | client端类，使用client端方法之前需要创建该类的实例进行操作。 |

**示例：**

```js
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
```


### getConnectedBLEDevices<sup>(deprecated)</sup>

getConnectedBLEDevices(): Array&lt;string&gt;

获取和当前设备连接的BLE设备。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.BLE.getConnectedBLEDevices](js-apis-bluetoothManager.md#getconnectedbledevicesdeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型                  | 说明                  |
| ------------------- | ------------------- |
| Array&lt;string&gt; | 返回当前设备作为Server端时连接BLE设备地址集合。 |

**示例：**

```js
let result : Array<string> = bluetooth.BLE.getConnectedBLEDevices();
```


### startBLEScan<sup>(deprecated)</sup>

startBLEScan(filters: Array&lt;ScanFilter&gt;, options?: ScanOptions): void

发起BLE扫描流程。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.BLE.startBLEScan](js-apis-bluetoothManager.md#startblescandeprecated)替代。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH（该权限仅系统应用可申请） 和 ohos.permission.LOCATION

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名     | 类型                                     | 必填   | 说明                                  |
| ------- | -------------------------------------- | ---- | ----------------------------------- |
| filters | Array&lt;[ScanFilter](#scanfilterdeprecated)&gt; | 是    | 表示扫描结果过滤策略集合，如果不使用过滤的方式，该参数设置为null。 |
| options | [ScanOptions](#scanoptionsdeprecated)            | 否    | 表示扫描的参数配置，可选参数。                     |

**返回值：**

无

**示例：**

```js
function onReceiveEvent(data : Array<bluetooth.ScanResult>) {
    console.info('BLE scan device find result = '+ JSON.stringify(data));
}
bluetooth.BLE.on("BLEDeviceFind", onReceiveEvent);
let scanOptions : bluetooth.ScanOptions = {
    interval: 500,
    dutyMode: bluetooth.ScanDuty.SCAN_MODE_LOW_POWER,
    matchMode: bluetooth.MatchMode.MATCH_MODE_AGGRESSIVE,
}

let scanFilter : bluetooth.ScanFilter = {
    deviceId:"XX:XX:XX:XX:XX:XX",
    name:"test",
    serviceUuid:"00001888-0000-1000-8000-00805f9b34fb"
}
bluetooth.BLE.startBLEScan(
    [scanFilter], scanOptions
);
```


### stopBLEScan<sup>(deprecated)</sup>

stopBLEScan(): void

停止BLE扫描流程。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.BLE.stopBLEScan](js-apis-bluetoothManager.md#stopblescandeprecated)替代。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

无

**示例：**

```js
bluetooth.BLE.stopBLEScan();
```


### on('BLEDeviceFind')<sup>(deprecated)</sup>

on(type: 'BLEDeviceFind', callback: Callback&lt;Array&lt;ScanResult&gt;&gt;): void

订阅BLE设备发现上报事件。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.BLE.on('BLEDeviceFind')](js-apis-bluetoothManager.md#onbledevicefinddeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                  |
| -------- | ---------------------------------------- | ---- | ----------------------------------- |
| type     | string                                   | 是    | 填写"BLEDeviceFind"字符串，表示BLE设备发现事件。   |
| callback | Callback&lt;Array&lt;[ScanResult](#scanresultdeprecated)&gt;&gt; | 是    | 表示回调函数的入参，发现的设备集合。回调函数由用户创建通过该接口注册。 |

**返回值：**

无

**示例：**

```js
function onReceiveEvent(data : Array<bluetooth.ScanResult>) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
bluetooth.BLE.on('BLEDeviceFind', onReceiveEvent);
```


### off('BLEDeviceFind')<sup>(deprecated)</sup>

off(type: 'BLEDeviceFind', callback?: Callback&lt;Array&lt;ScanResult&gt;&gt;): void

取消订阅BLE设备发现上报事件。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.BLE.off('BLEDeviceFind')](js-apis-bluetoothManager.md#offbledevicefinddeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"BLEDeviceFind"字符串，表示BLE设备发现事件。        |
| callback | Callback&lt;Array&lt;[ScanResult](#scanresultdeprecated)&gt;&gt; | 否    | 表示取消订阅BLE设备发现事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```js
function onReceiveEvent(data : Array<bluetooth.ScanResult>) {
    console.info('bluetooth device find = '+ JSON.stringify(data));
}
bluetooth.BLE.on('BLEDeviceFind', onReceiveEvent);
bluetooth.BLE.off('BLEDeviceFind', onReceiveEvent);
```


## BaseProfile

profile基类。


### getConnectionDevices<sup>8+</sup><sup>(deprecated)</sup>

getConnectionDevices(): Array&lt;string&gt;

获取已连接设备列表。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.BaseProfile.getConnectionDevices](js-apis-bluetoothManager.md#getconnectiondevicesdeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型                  | 说明            |
| ------------------- | ------------- |
| Array&lt;string&gt; | 返回已连接设备的地址列表。 |

**示例：**

```js
let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;
let retArray : Array<string> = a2dpSrc.getConnectionDevices();
```

### getDeviceState<sup>8+</sup><sup>(deprecated)</sup>

getDeviceState(device: string): ProfileConnectionState

获取设备profile的连接状态。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.BaseProfile.getDeviceState](js-apis-bluetoothManager.md#getdevicestatedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| device | string | 是    | 远端设备地址。 |

**返回值：**

| 类型                                              | 说明                    |
| ------------------------------------------------- | ----------------------- |
| [ProfileConnectionState](#profileconnectionstatedeprecated) | 返回profile的连接状态。 |

**示例：**

```js
let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;
let ret : bluetooth.ProfileConnectionState = a2dpSrc.getDeviceState('XX:XX:XX:XX:XX:XX');
```

## A2dpSourceProfile

使用A2dpSourceProfile方法之前需要创建该类的实例进行操作，通过getProfile()方法构造此实例。


### connect<sup>8+</sup><sup>(deprecated)</sup>

connect(device: string): boolean

发起设备的A2dp服务连接请求。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.A2dpSourceProfile.connect](js-apis-bluetoothManager.md#connectdeprecated)替代。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| device | string | 是    | 远端设备地址。 |

**返回值：**

| 类型      | 说明                  |
| ------- | ------------------- |
| boolean | 成功返回true，失败返回false。 |

**示例：**

```js
let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;
let ret : boolean = a2dpSrc.connect('XX:XX:XX:XX:XX:XX');
```


### disconnect<sup>8+</sup><sup>(deprecated)</sup>

disconnect(device: string): boolean

断开设备的a2dp服务连接。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.A2dpSourceProfile.disconnect](js-apis-bluetoothManager.md#disconnectdeprecated)替代。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| device | string | 是    | 远端设备地址。 |

**返回值：**

| 类型      | 说明                  |
| ------- | ------------------- |
| boolean | 成功返回true，失败返回false。 |

**示例：**

```js
let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;
let ret : boolean = a2dpSrc.disconnect('XX:XX:XX:XX:XX:XX');
```


### on('connectionStateChange')<sup>8+</sup><sup>(deprecated)</sup>

on(type: 'connectionStateChange', callback: Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt;): void

订阅a2dp连接状态变化事件。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.A2dpSourceProfile.on('connectionStateChange')](js-apis-bluetoothManager.md#onconnectionstatechangedeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"connectionStateChange"字符串，表示连接状态变化事件。 |
| callback | Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt; | 是    | 表示回调函数的入参。                               |

**返回值：**

无

**示例：**

```js
function onReceiveEvent(data : bluetooth.StateChangeParam) {
    console.info('a2dp state = '+ JSON.stringify(data));
}
let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;
a2dpSrc.on('connectionStateChange', onReceiveEvent);
```


### off('connectionStateChange')<sup>8+</sup><sup>(deprecated)</sup>

off(type: 'connectionStateChange', callback?: Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt;): void

取消订阅a2dp连接状态变化事件。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.A2dpSourceProfile.off('connectionStateChange')](js-apis-bluetoothManager.md#offconnectionstatechangedeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"connectionStateChange"字符串，表示连接状态变化事件。 |
| callback | Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt; | 否    | 表示回调函数的入参。                               |

**返回值：**

无

**示例：**

```js
function onReceiveEvent(data : bluetooth.StateChangeParam) {
    console.info('a2dp state = '+ JSON.stringify(data));
}
let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;
a2dpSrc.on('connectionStateChange', onReceiveEvent);
a2dpSrc.off('connectionStateChange', onReceiveEvent);
```


### getPlayingState<sup>8+</sup><sup>(deprecated)</sup>

getPlayingState(device: string): PlayingState

获取设备的播放状态。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.A2dpSourceProfile.getPlayingState](js-apis-bluetoothManager.md#getplayingstatedeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| device | string | 是    | 远端设备地址。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| [PlayingState](#playingstatedeprecated) | 远端设备的播放状态。 |

**示例：**

```js
let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;
let state : bluetooth.PlayingState = a2dpSrc.getPlayingState('XX:XX:XX:XX:XX:XX');
```


## HandsFreeAudioGatewayProfile

使用HandsFreeAudioGatewayProfile方法之前需要创建该类的实例进行操作，通过getProfile()方法构造此实例。


### connect<sup>8+</sup><sup>(deprecated)</sup>

connect(device: string): boolean

连接设备的HFP服务。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.HandsFreeAudioGatewayProfile.connect](js-apis-bluetoothManager.md#connect)替代。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| device | string | 是    | 远端设备地址。 |

**返回值：**

| 类型      | 说明                  |
| ------- | ------------------- |
| boolean | 成功返回true，失败返回false。 |

**示例：**

```js
let hfpAg : bluetooth.HandsFreeAudioGatewayProfile= bluetooth.getProfile(bluetooth.ProfileId
    .PROFILE_HANDS_FREE_AUDIO_GATEWAY);
let ret : boolean = hfpAg.connect('XX:XX:XX:XX:XX:XX');
```


### disconnect<sup>8+</sup><sup>(deprecated)</sup>

disconnect(device: string): boolean

断开连接设备的HFP服务。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.HandsFreeAudioGatewayProfile.disconnect](js-apis-bluetoothManager.md#disconnectdeprecated-1)替代。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| device | string | 是    | 远端设备地址。 |

**返回值：**

| 类型      | 说明                  |
| ------- | ------------------- |
| boolean | 成功返回true，失败返回false。 |

**示例：**

```js
let hfpAg : bluetooth.HandsFreeAudioGatewayProfile = bluetooth.getProfile(bluetooth.ProfileId
    .PROFILE_HANDS_FREE_AUDIO_GATEWAY);
let ret : boolean = hfpAg.disconnect('XX:XX:XX:XX:XX:XX');
```


### on('connectionStateChange')<sup>8+</sup><sup>(deprecated)</sup>

on(type: 'connectionStateChange', callback: Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt;): void

订阅HFP连接状态变化事件。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.HandsFreeAudioGatewayProfile.on('connectionStateChange')](js-apis-bluetoothManager.md#onconnectionstatechangedeprecated-1)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"connectionStateChange"字符串，表示连接状态变化事件。 |
| callback | Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt; | 是    | 表示回调函数的入参。                               |

**返回值：**

无

**示例：**

```js
function onReceiveEvent(data : bluetooth.StateChangeParam) {
    console.info('hfp state = '+ JSON.stringify(data));
}
let hfpAg : bluetooth.HandsFreeAudioGatewayProfile= bluetooth.getProfile(bluetooth.ProfileId
    .PROFILE_HANDS_FREE_AUDIO_GATEWAY);
hfpAg.on('connectionStateChange', onReceiveEvent);
```


### off('connectionStateChange')<sup>8+</sup><sup>(deprecated)</sup>

off(type: 'connectionStateChange', callback?: Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt;): void

取消订阅HFP连接状态变化事件。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.HandsFreeAudioGatewayProfile.off('connectionStateChange')](js-apis-bluetoothManager.md#offconnectionstatechangedeprecated-1)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"connectionStateChange"字符串，表示连接状态变化事件。 |
| callback | Callback&lt;[StateChangeParam](#statechangeparamdeprecated)&gt; | 否    | 表示回调函数的入参。                               |

**返回值：**

无

**示例：**

```js
function onReceiveEvent(data : bluetooth.StateChangeParam) {
    console.info('hfp state = '+ JSON.stringify(data));
}
let hfpAg : bluetooth.HandsFreeAudioGatewayProfile= bluetooth.getProfile(bluetooth.ProfileId
    .PROFILE_HANDS_FREE_AUDIO_GATEWAY);
hfpAg.on('connectionStateChange', onReceiveEvent);
hfpAg.off('connectionStateChange', onReceiveEvent);
```


## GattServer

server端类，使用server端方法之前需要创建该类的实例进行操作，通过createGattServer()方法构造此实例。


### startAdvertising<sup>(deprecated)</sup>

startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void

开始发送BLE广播。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattServer.startAdvertising](js-apis-bluetoothManager.md#startadvertisingdeprecated)替代。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名         | 类型                                    | 必填   | 说明             |
| ----------- | ------------------------------------- | ---- | -------------- |
| setting     | [AdvertiseSetting](#advertisesettingdeprecated) | 是    | BLE广播的相关参数。    |
| advData     | [AdvertiseData](#advertisedatadeprecated)       | 是    | BLE广播包内容。      |
| advResponse | [AdvertiseData](#advertisedatadeprecated)       | 否    | BLE回复扫描请求回复响应。 |

**返回值：**

无

**示例：**

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
let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();
let setting : bluetooth.AdvertiseSetting = {
    interval:150,
    txPower:60,
    connectable:true,
}

let manufactureData : bluetooth.ManufactureData = {
    manufactureId:4567,
    manufactureValue:manufactureValueBuffer.buffer
}

let serviceData : bluetooth.ServiceData = {
    serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",
    serviceValue:serviceValueBuffer.buffer
}

let advData : bluetooth.AdvertiseData = {
    serviceUuids:["00001889-0000-1000-8000-00805f9b34fb"],
    manufactureData:[manufactureData],
    serviceData:[serviceData],
}

let advResponse : bluetooth.AdvertiseData = {
    serviceUuids:["00001889-0000-1000-8000-00805f9b34fb"],
    manufactureData:[manufactureData],
    serviceData:[serviceData],
}
gattServer.startAdvertising(setting, advData, advResponse);
```


### stopAdvertising<sup>(deprecated)</sup>

stopAdvertising(): void

停止发送BLE广播。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattServer.stopAdvertising](js-apis-bluetoothManager.md#stopadvertisingdeprecated)替代。

**需要权限**：ohos.permission.DISCOVER_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

无

**示例：**

```js
let server : bluetooth.GattServer = bluetooth.BLE.createGattServer();
server.stopAdvertising();
```


### addService<sup>(deprecated)</sup>

addService(service: GattService): boolean

server端添加服务。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattServer.addService](js-apis-bluetoothManager.md#addservicedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名     | 类型                          | 必填   | 说明                       |
| ------- | --------------------------- | ---- | ------------------------ |
| service | [GattService](#gattservicedeprecated) | 是    | 服务端的service数据。BLE广播的相关参数 |

**返回值：**

| 类型      | 说明                         |
| ------- | -------------------------- |
| boolean | 添加服务操作，成功返回true，否则返回false。 |

**示例：**

```js
// 创建descriptors
let descriptors : Array<bluetooth.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(8);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
let descriptor : bluetooth.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;

// 创建characteristics
let characteristics : Array<bluetooth.BLECharacteristic> = [];
let arrayBufferC = new ArrayBuffer(8);
let cccV = new Uint8Array(arrayBufferC);
cccV[0] = 1;
let characteristic : bluetooth.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
let characteristicN : bluetooth.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001821-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
characteristics[0] = characteristic;

// 创建gattService
let gattService : bluetooth.GattService = {serviceUuid:'00001810-0000-1000-8000-00805F9B34FB', isPrimary: true, characteristics:characteristics, includeServices:[]};

let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();
let ret : boolean = gattServer.addService(gattService);
if (ret) {
   console.log("add service successfully");
} else {
   console.log("add service failed");
}
```


### removeService<sup>(deprecated)</sup>

removeService(serviceUuid: string): boolean

删除已添加的服务。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattServer.removeService](js-apis-bluetoothManager.md#removeservicedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名         | 类型     | 必填   | 说明                                       |
| ----------- | ------ | ---- | ---------------------------------------- |
| serviceUuid | string | 是    | service的UUID，例如“00001810-0000-1000-8000-00805F9B34FB”。 |

**返回值：**

| 类型      | 说明                         |
| ------- | -------------------------- |
| boolean | 删除服务操作，成功返回true，否则返回false。 |

**示例：**

```js
let server : bluetooth.GattServer = bluetooth.BLE.createGattServer();
server.removeService('00001810-0000-1000-8000-00805F9B34FB');
```


### close<sup>(deprecated)</sup>

close(): void

关闭服务端功能，去注册server在协议栈的注册，调用该接口后[GattServer](#gattserver)实例将不能再使用。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattServer.close](js-apis-bluetoothManager.md#closedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**示例：**

```js
let server : bluetooth.GattServer = bluetooth.BLE.createGattServer();
server.close();
```


### notifyCharacteristicChanged<sup>(deprecated)</sup>

notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): boolean

server端特征值发生变化时，主动通知已连接的client设备。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattServer.notifyCharacteristicChanged](js-apis-bluetoothManager.md#notifycharacteristicchangeddeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名                  | 类型                                       | 必填   | 说明                                      |
| -------------------- | ---------------------------------------- | ---- | --------------------------------------- |
| deviceId             | string                                   | 是    | 接收通知的client端设备地址，例如“XX:XX:XX:XX:XX:XX”。 |
| notifyCharacteristic | [NotifyCharacteristic](#notifycharacteristicdeprecated) | 是    | 通知的特征值数据。                               |

**返回值：**

| 类型      | 说明                       |
| ------- | ------------------------ |
| boolean | 通知操作，成功返回true，否则返回false。 |

**示例：**

```js
// 创建descriptors
let descriptors : Array<bluetooth.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(8);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
let descriptor : bluetooth.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;
let arrayBufferC = new ArrayBuffer(8);
let characteristic : bluetooth.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
let notifyCharacteristic : bluetooth.NotifyCharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001821-0000-1000-8000-00805F9B34FB', characteristicValue: characteristic.characteristicValue, confirm: false};
let server : bluetooth.GattServer = bluetooth.BLE.createGattServer();
server.notifyCharacteristicChanged('XX:XX:XX:XX:XX:XX', notifyCharacteristic);
```


### sendResponse<sup>(deprecated)</sup>

sendResponse(serverResponse: ServerResponse): boolean

server端回复client端的读写请求。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattServer.sendResponse](js-apis-bluetoothManager.md#sendresponsedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名            | 类型                                | 必填   | 说明              |
| -------------- | --------------------------------- | ---- | --------------- |
| serverResponse | [ServerResponse](#serverresponsedeprecated) | 是    | server端回复的响应数据。 |

**返回值：**

| 类型      | 说明                         |
| ------- | -------------------------- |
| boolean | 回复响应操作，成功返回true，否则返回false。 |

**示例：**

```js
/* send response */
let arrayBufferCCC = new ArrayBuffer(8);
let cccValue = new Uint8Array(arrayBufferCCC);
cccValue[0] = 1123;
let serverResponse : bluetooth.ServerResponse = {
    "deviceId": "XX:XX:XX:XX:XX:XX",
    "transId": 0,
    "status": 0,
    "offset": 0,
    "value": arrayBufferCCC,
};

let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();
let ret : boolean = gattServer.sendResponse(serverResponse);
if (ret) {
  console.log('bluetooth sendResponse successfully');
} else {
  console.log('bluetooth sendResponse failed');
}
```


### on('characteristicRead')<sup>(deprecated)</sup>

on(type: 'characteristicRead', callback: Callback&lt;CharacteristicReadReq&gt;): void

server端订阅特征值读请求事件。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattServer.on('characteristicRead')](js-apis-bluetoothManager.md#oncharacteristicreaddeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                    |
| -------- | ---------------------------------------- | ---- | ------------------------------------- |
| type     | string                                   | 是    | 填写"characteristicRead"字符串，表示特征值读请求事件。 |
| callback | Callback&lt;[CharacteristicReadReq](#characteristicreadreqdeprecated)&gt; | 是    | 表示回调函数的入参，client端发送的读请求数据。            |

**返回值：**

无

**示例：**

```js
let arrayBufferCCC = new ArrayBuffer(8);
let cccValue = new Uint8Array(arrayBufferCCC);
cccValue[0] = 1123;
function ReadCharacteristicReq(CharacteristicReadReq : bluetooth.CharacteristicReadReq) {
  let deviceId : string = CharacteristicReadReq.deviceId;
  let transId : number = CharacteristicReadReq.transId;
  let offset : number = CharacteristicReadReq.offset;
  let characteristicUuid : string = CharacteristicReadReq.characteristicUuid;

  let serverResponse : bluetooth.ServerResponse = {deviceId: deviceId, transId: transId, status: 0, 
  offset: offset, value:arrayBufferCCC};

  let ret : boolean = gattServer.sendResponse(serverResponse);
  if (ret) {
    console.log('bluetooth sendResponse successfully');
  } else {
    console.log('bluetooth sendResponse failed');
  }
}

let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();
gattServer.on("characteristicRead", ReadCharacteristicReq);
```


### off('characteristicRead')<sup>(deprecated)</sup>

off(type: 'characteristicRead', callback?: Callback&lt;CharacteristicReadReq&gt;): void

server端取消订阅特征值读请求事件。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattServer.off('characteristicRead')](js-apis-bluetoothManager.md#offcharacteristicreaddeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"characteristicRead"字符串，表示特征值读请求事件。    |
| callback | Callback&lt;[CharacteristicReadReq](#characteristicreadreqdeprecated)&gt; | 否    | 表示取消订阅特征值读请求事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```js
let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();
gattServer.off("characteristicRead");
```


### on('characteristicWrite')<sup>(deprecated)</sup>

on(type: 'characteristicWrite', callback: Callback&lt;CharacteristicWriteReq&gt;): void

server端订阅特征值写请求事件。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattServer.on('characteristicWrite')](js-apis-bluetoothManager.md#oncharacteristicwritedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                     |
| -------- | ---------------------------------------- | ---- | -------------------------------------- |
| type     | string                                   | 是    | 填写"characteristicWrite"字符串，表示特征值写请求事件。 |
| callback | Callback&lt;[CharacteristicWriteReq](#characteristicwritereqdeprecated)&gt; | 是    | 表示回调函数的入参，client端发送的写请求数据。             |

**返回值：**

无

**示例：**

```js
let arrayBufferCCC = new ArrayBuffer(8);
let cccValue = new Uint8Array(arrayBufferCCC);
function WriteCharacteristicReq(CharacteristicWriteReq : bluetooth.CharacteristicWriteReq) {
  let deviceId : string = CharacteristicWriteReq.deviceId;
  let transId : number = CharacteristicWriteReq.transId;
  let offset : number = CharacteristicWriteReq.offset;
  let isPrep : boolean = CharacteristicWriteReq.isPrep;
  let needRsp : boolean = CharacteristicWriteReq.needRsp;
  let value =  new Uint8Array(arrayBufferCCC);
  let characteristicUuid : string = CharacteristicWriteReq.characteristicUuid;

  cccValue.set(new Uint8Array(value));
  let serverResponse : bluetooth.ServerResponse = {deviceId: deviceId, transId: transId, status: 0, 
  offset: offset, value:arrayBufferCCC};

  let ret : boolean = gattServer.sendResponse(serverResponse);
  if (ret) {
    console.log('bluetooth sendResponse successfully');
  } else {
    console.log('bluetooth sendResponse failed');
  }
}

let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();
gattServer.on("characteristicWrite", WriteCharacteristicReq);
```


### off('characteristicWrite')<sup>(deprecated)</sup>

off(type: 'characteristicWrite', callback?: Callback&lt;CharacteristicWriteReq&gt;): void

server端取消订阅特征值写请求事件。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattServer.off('characteristicWrite')](js-apis-bluetoothManager.md#offcharacteristicwritedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"characteristicWrite"字符串，表示特征值写请求事件。   |
| callback | Callback&lt;[CharacteristicWriteReq](#characteristicwritereqdeprecated)&gt; | 否    | 表示取消订阅特征值写请求事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```js
let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();
gattServer.off("characteristicWrite");
```


### on('descriptorRead')<sup>(deprecated)</sup>

on(type: 'descriptorRead', callback: Callback&lt;DescriptorReadReq&gt;): void

server端订阅描述符读请求事件。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattServer.on('descriptorRead')](js-apis-bluetoothManager.md#ondescriptorreaddeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                |
| -------- | ---------------------------------------- | ---- | --------------------------------- |
| type     | string                                   | 是    | 填写"descriptorRead"字符串，表示描述符读请求事件。 |
| callback | Callback&lt;[DescriptorReadReq](#descriptorreadreqdeprecated)&gt; | 是    | 表示回调函数的入参，client端发送的读请求数据。        |

**返回值：**

无

**示例：**

```js
let arrayBufferDesc = new ArrayBuffer(8);
let descValue = new Uint8Array(arrayBufferDesc);
descValue[0] = 1101;
function ReadDescriptorReq(DescriptorReadReq : bluetooth.DescriptorReadReq) {
  let deviceId : string = DescriptorReadReq.deviceId;
  let transId : number = DescriptorReadReq.transId;
  let offset : number = DescriptorReadReq.offset;
  let descriptorUuid : string = DescriptorReadReq.descriptorUuid;

  let serverResponse : bluetooth.ServerResponse = {deviceId: deviceId, transId: transId, status: 0, 
  offset: offset, value:arrayBufferDesc};

  let ret : boolean = gattServer.sendResponse(serverResponse);
  if (ret) {
    console.log('bluetooth sendResponse successfully');
  } else {
    console.log('bluetooth sendResponse failed');
  }
}

let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();
gattServer.on("descriptorRead", ReadDescriptorReq);
```


### off('descriptorRead')<sup>(deprecated)</sup>

off(type: 'descriptorRead', callback?: Callback&lt;DescriptorReadReq&gt;): void

server端取消订阅描述符读请求事件。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattServer.off('descriptorRead')](js-apis-bluetoothManager.md#offdescriptorreaddeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"descriptorRead"字符串，表示描述符读请求事件。        |
| callback | Callback&lt;[DescriptorReadReq](#descriptorreadreqdeprecated)&gt; | 否    | 表示取消订阅描述符读请求事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```js
let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();
gattServer.off("descriptorRead");
```


### on('descriptorWrite')<sup>(deprecated)</sup>

on(type: 'descriptorWrite', callback: Callback&lt;DescriptorWriteReq&gt;): void

server端订阅描述符写请求事件。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattServer.on('descriptorWrite')](js-apis-bluetoothManager.md#ondescriptorwritedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                 |
| -------- | ---------------------------------------- | ---- | ---------------------------------- |
| type     | string                                   | 是    | 填写"descriptorWrite"字符串，表示描述符写请求事件。 |
| callback | Callback&lt;[DescriptorWriteReq](#descriptorwritereqdeprecated)&gt; | 是    | 表示回调函数的入参，client端发送的写请求数据。         |

**返回值：**

无

**示例：**

```js
let arrayBufferDesc = new ArrayBuffer(8);
let descValue = new Uint8Array(arrayBufferDesc);
function WriteDescriptorReq(DescriptorWriteReq : bluetooth.DescriptorWriteReq) {
  let deviceId : string = DescriptorWriteReq.deviceId;
  let transId : number = DescriptorWriteReq.transId;
  let offset : number = DescriptorWriteReq.offset;
  let isPrep : boolean = DescriptorWriteReq.isPrep;
  let needRsp : boolean = DescriptorWriteReq.needRsp;
  let value = new Uint8Array(arrayBufferDesc);
  let descriptorUuid : string = DescriptorWriteReq.descriptorUuid;

  descValue.set(new Uint8Array(value));
  let serverResponse : bluetooth.ServerResponse = {deviceId: deviceId, transId: transId, status: 0, offset: offset, value:arrayBufferDesc};

  let ret : boolean = gattServer.sendResponse(serverResponse);
  if (ret) {
    console.log('bluetooth sendResponse successfully');
  } else {
    console.log('bluetooth sendResponse failed');
  }
}

let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();
gattServer.on("descriptorWrite", WriteDescriptorReq);
```


### off('descriptorWrite')<sup>(deprecated)</sup>

off(type: 'descriptorWrite', callback?: Callback&lt;DescriptorWriteReq&gt;): void

server端取消订阅描述符写请求事件。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattServer.off('descriptorWrite')](js-apis-bluetoothManager.md#offdescriptorwritedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"descriptorWrite"字符串，表示描述符写请求事件。       |
| callback | Callback&lt;[DescriptorWriteReq](#descriptorwritereqdeprecated)&gt; | 否    | 表示取消订阅描述符写请求事件上报。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```js
let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();
gattServer.off("descriptorWrite");
```


### on('connectStateChange')<sup>(deprecated)</sup>

on(type: 'connectStateChange', callback: Callback&lt;BLEConnectChangedState&gt;): void

server端订阅BLE连接状态变化事件。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattServer.on('connectStateChange')](js-apis-bluetoothManager.md#onconnectstatechangedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"connectStateChange"字符串，表示BLE连接状态变化事件。 |
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstatedeprecated)&gt; | 是    | 表示回调函数的入参，连接状态。                          |

**返回值：**

无

**示例：**

```js
function Connected(BLEConnectChangedState : bluetooth.BLEConnectChangedState) {
  let deviceId : string = BLEConnectChangedState.deviceId;
  let status : bluetooth.ProfileConnectionState = BLEConnectChangedState.state;
}

let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();
gattServer.on("connectStateChange", Connected);
```


### off('connectStateChange')<sup>(deprecated)</sup>

off(type: 'connectStateChange', callback?: Callback&lt;BLEConnectChangedState&gt;): void

server端取消订阅BLE连接状态变化事件。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattServer.off('connectStateChange')](js-apis-bluetoothManager.md#offconnectstatechangedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"connectStateChange"字符串，表示BLE连接状态变化事件。 |
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstatedeprecated)&gt; | 否    | 表示取消订阅BLE连接状态变化事件。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```js
let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();
gattServer.off("connectStateChange");
```


## GattClientDevice

client端类，使用client端方法之前需要创建该类的实例进行操作，通过createGattClientDevice(deviceId: string)方法构造此实例。


### connect<sup>(deprecated)</sup>

connect(): boolean

client端发起连接远端蓝牙低功耗设备。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.connect](js-apis-bluetoothManager.md#connectdeprecated-1)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型      | 说明                        |
| ------- | ------------------------- |
| boolean | 连接操作成功返回true，操作失败返回false。 |

**示例：**

```js
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let ret : boolean = device.connect();
```


### disconnect<sup>(deprecated)</sup>

disconnect(): boolean

client端断开与远端蓝牙低功耗设备的连接。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.disconnect](js-apis-bluetoothManager.md#disconnectdeprecated-2)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型      | 说明                           |
| ------- | ---------------------------- |
| boolean | 断开连接操作，成功返回true，操作失败返回false。 |

**示例：**

```js
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let ret : boolean = device.disconnect();
```


### close<sup>(deprecated)</sup>

close(): boolean

关闭客户端功能，注销client在协议栈的注册，调用该接口后[GattClientDevice](#gattclientdevice)实例将不能再使用。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.close](js-apis-bluetoothManager.md#closedeprecated-1)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型      | 说明                         |
| ------- | -------------------------- |
| boolean | 关闭操作，成功返回true，操作失败返回false。 |

**示例：**

```js
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let ret : boolean = device.close();
```




### getServices<sup>(deprecated)</sup>

getServices(callback: AsyncCallback&lt;Array&lt;GattService&gt;&gt;): void

client端获取蓝牙低功耗设备的所有服务，即服务发现 。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.getServices](js-apis-bluetoothManager.md#getservicesdeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;Array&lt;[GattService](#gattservicedeprecated)&gt;&gt; | 是    | client进行服务发现，通过注册回调函数获取。 |

**返回值：**

无

**示例：**

```js
import { BusinessError } from '@ohos.base';
// callback 模式
function getServices(code : BusinessError, gattServices : Array<bluetooth.GattService>) {
  if (code.code == 0) {
      let services : Array<bluetooth.GattService> = gattServices;
      console.log('bluetooth code is ' + code.code);
      console.log("bluetooth services size is ", services.length);

      for (let i = 0; i < services.length; i++) {
        console.log('bluetooth serviceUuid is ' + services[i].serviceUuid);
      }
  }
}

let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
device.connect();
device.getServices(getServices);
```


### getServices<sup>(deprecated)</sup>

getServices(): Promise&lt;Array&lt;GattService&gt;&gt;

client端获取蓝牙低功耗设备的所有服务，即服务发现。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.getServices](js-apis-bluetoothManager.md#getservicesdeprecated-1)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型                                       | 说明                          |
| ---------------------------------------- | --------------------------- |
| Promise&lt;Array&lt;[GattService](#gattservicedeprecated)&gt;&gt; | client进行服务发现，通过promise形式获取。 |

**示例：**

```js
// Promise 模式
let device : bluetooth.GattClientDevice= bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
device.connect();
device.getServices().then((result : Array<bluetooth.GattService>) => {
    console.info("getServices successfully:" + JSON.stringify(result));
});
```


### readCharacteristicValue<sup>(deprecated)</sup>

readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback&lt;BLECharacteristic&gt;): void

client端读取蓝牙低功耗设备特定服务的特征值。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.readCharacteristicValue](js-apis-bluetoothManager.md#readcharacteristicvaluedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名            | 类型                                       | 必填   | 说明                      |
| -------------- | ---------------------------------------- | ---- | ----------------------- |
| characteristic | [BLECharacteristic](#blecharacteristicdeprecated)  | 是    | 待读取的特征值。                |
| callback       | AsyncCallback&lt;[BLECharacteristic](#blecharacteristicdeprecated)&gt; | 是    | client读取特征值，通过注册回调函数获取。 |

**返回值：**

无

**示例：**

```js
import { BusinessError } from '@ohos.base';
function readCcc(code : BusinessError, BLECharacteristic : bluetooth.BLECharacteristic) {
  if (code.code != 0) {
      return;
  }
  console.log('bluetooth characteristic uuid: ' + BLECharacteristic.characteristicUuid);
  let value = new Uint8Array(BLECharacteristic.characteristicValue);
  console.log('bluetooth characteristic value: ' + value[0] +','+ value[1]+','+ value[2]+','+ value[3]);
}

let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let descriptors : Array<bluetooth.BLEDescriptor> = [];
let bufferDesc : ArrayBuffer = new ArrayBuffer(8);
let descV : Uint8Array = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor : bluetooth.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic : bluetooth.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
characteristicValue: bufferCCC, descriptors:descriptors};

device.readCharacteristicValue(characteristic, readCcc);
```


### readCharacteristicValue<sup>(deprecated)</sup>

readCharacteristicValue(characteristic: BLECharacteristic): Promise&lt;BLECharacteristic&gt;

client端读取蓝牙低功耗设备特定服务的特征值。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.readCharacteristicValue](js-apis-bluetoothManager.md#readcharacteristicvaluedeprecated-1)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名            | 类型                                      | 必填   | 说明       |
| -------------- | --------------------------------------- | ---- | -------- |
| characteristic | [BLECharacteristic](#blecharacteristicdeprecated) | 是    | 待读取的特征值。 |

**返回值：**

| 类型                                       | 说明                         |
| ---------------------------------------- | -------------------------- |
| Promise&lt;[BLECharacteristic](#blecharacteristicdeprecated)&gt; | client读取特征值，通过promise形式获取。 |

**示例：**

```js
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let descriptors : Array<bluetooth.BLEDescriptor> = [];
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor : bluetooth.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic : bluetooth.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
characteristicValue: bufferCCC, descriptors:descriptors};

device.readCharacteristicValue(characteristic);
```


### readDescriptorValue<sup>(deprecated)</sup>

readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback&lt;BLEDescriptor&gt;): void

client端读取蓝牙低功耗设备特定的特征包含的描述符。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.readDescriptorValue](js-apis-bluetoothManager.md#readdescriptorvaluedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名        | 类型                                       | 必填   | 说明                      |
| ---------- | ---------------------------------------- | ---- | ----------------------- |
| descriptor | [BLEDescriptor](#bledescriptordeprecated)          | 是    | 待读取的描述符。                |
| callback   | AsyncCallback&lt;[BLEDescriptor](#bledescriptordeprecated)&gt; | 是    | client读取描述符，通过注册回调函数获取。 |

**返回值：**

无

**示例：**

```js
import { BusinessError } from '@ohos.base';
function readDesc(code : BusinessError, BLEDescriptor : bluetooth.BLEDescriptor) {
  if (code.code != 0) {
      return;
  }
  console.log('bluetooth descriptor uuid: ' + BLEDescriptor.descriptorUuid);
  let value = new Uint8Array(BLEDescriptor.descriptorValue);
  console.log('bluetooth descriptor value: ' + value[0] +','+ value[1]+','+ value[2]+','+ value[3]);
}

let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor : bluetooth.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
device.readDescriptorValue(descriptor, readDesc);
```


### readDescriptorValue<sup>(deprecated)</sup>

readDescriptorValue(descriptor: BLEDescriptor): Promise&lt;BLEDescriptor&gt;

client端读取蓝牙低功耗设备特定的特征包含的描述符。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.readDescriptorValue](js-apis-bluetoothManager.md#readdescriptorvaluedeprecated-1)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名        | 类型                              | 必填   | 说明       |
| ---------- | ------------------------------- | ---- | -------- |
| descriptor | [BLEDescriptor](#bledescriptordeprecated) | 是    | 待读取的描述符。 |

**返回值：**

| 类型                                       | 说明                         |
| ---------------------------------------- | -------------------------- |
| Promise&lt;[BLEDescriptor](#bledescriptordeprecated)&gt; | client读取描述符，通过promise形式获取。 |

**示例：**

```js
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor : bluetooth.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
device.readDescriptorValue(descriptor);
```


### writeCharacteristicValue<sup>(deprecated)</sup>

writeCharacteristicValue(characteristic: BLECharacteristic): boolean

client端向低功耗蓝牙设备写入特定的特征值。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.writeCharacteristicValue](js-apis-bluetoothManager.md#writecharacteristicvaluedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名            | 类型                                      | 必填   | 说明                  |
| -------------- | --------------------------------------- | ---- | ------------------- |
| characteristic | [BLECharacteristic](#blecharacteristicdeprecated) | 是    | 蓝牙设备特征对应的二进制值及其它参数。 |

**返回值：**

| 类型      | 说明                          |
| ------- | --------------------------- |
| boolean | 写特征值操作成功返回true，操作失败返回false。 |

**示例：**

```js
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let descriptors : Array<bluetooth.BLEDescriptor> = [];
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 11;
let descriptor : bluetooth.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
descriptors[0] = descriptor;

let bufferCCC = new ArrayBuffer(8);
let cccV = new Uint8Array(bufferCCC);
cccV[0] = 1;
let characteristic : bluetooth.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  characteristicValue: bufferCCC, descriptors:descriptors};
let retWriteCcc : boolean = device.writeCharacteristicValue(characteristic);
if (retWriteCcc) {
  console.log('write characteristic successfully');
} else {
  console.log('write characteristic failed');
}
```


### writeDescriptorValue<sup>(deprecated)</sup>

writeDescriptorValue(descriptor: BLEDescriptor): boolean

client端向低功耗蓝牙设备特定的描述符写入二进制数据。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.writeDescriptorValue](js-apis-bluetoothManager.md#writedescriptorvaluedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名        | 类型                              | 必填   | 说明                 |
| ---------- | ------------------------------- | ---- | ------------------ |
| descriptor | [BLEDescriptor](#bledescriptordeprecated) | 是    | 蓝牙设备描述符的二进制值及其它参数。 |

**返回值：**

| 类型      | 说明                          |
| ------- | --------------------------- |
| boolean | 写描述符操作成功返回true，操作失败返回false。 |

**示例：**

```js
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
let bufferDesc = new ArrayBuffer(8);
let descV = new Uint8Array(bufferDesc);
descV[0] = 22;
let descriptor : bluetooth.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};
let retWriteDesc : boolean = device.writeDescriptorValue(descriptor);
if (retWriteDesc) {
  console.log('bluetooth write descriptor successfully');
} else {
  console.log('bluetooth write descriptor failed');
}
```


### setBLEMtuSize<sup>(deprecated)</sup>

setBLEMtuSize(mtu: number): boolean

client协商远端蓝牙低功耗设备的最大传输单元（Maximum Transmission Unit, MTU），调用[connect](#connectdeprecated)接口连接成功后才能使用。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.setBLEMtuSize](js-apis-bluetoothManager.md#setblemtusizedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名  | 类型     | 必填   | 说明             |
| ---- | ------ | ---- | -------------- |
| mtu  | number | 是    | 设置范围为22~512字节。 |

**返回值：**

| 类型      | 说明                           |
| ------- | ---------------------------- |
| boolean | MTU协商操作成功返回true，操作失败返回false。 |

**示例：**

```js
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
device.setBLEMtuSize(128);
```


### setNotifyCharacteristicChanged<sup>(deprecated)</sup>

setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): boolean

向服务端发送设置通知此特征值请求。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.setNotifyCharacteristicChanged](js-apis-bluetoothManager.md#setnotifycharacteristicchangeddeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名            | 类型                                      | 必填   | 说明                            |
| -------------- | --------------------------------------- | ---- | ----------------------------- |
| characteristic | [BLECharacteristic](#blecharacteristicdeprecated) | 是    | 蓝牙低功耗特征。                      |
| enable         | boolean                                 | 是    | 启用接收notify设置为true，否则设置为false。 |

**返回值：**

| 类型      | 说明                        |
| ------- | ------------------------- |
| boolean | 设置操作成功返回true，操作失败返回false。 |

**示例：**

```js
// 创建descriptors
let descriptors : Array<bluetooth.BLEDescriptor> = [];
let arrayBuffer = new ArrayBuffer(8);
let descV = new Uint8Array(arrayBuffer);
descV[0] = 11;
let descriptor : bluetooth.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',
  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};
descriptors[0] = descriptor;
let arrayBufferC = new ArrayBuffer(8);
let characteristic : bluetooth.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',
  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
device.setNotifyCharacteristicChanged(characteristic, false);
```


### on('BLECharacteristicChange')<sup>(deprecated)</sup>

on(type: 'BLECharacteristicChange', callback: Callback&lt;BLECharacteristic&gt;): void

订阅蓝牙低功耗设备的特征值变化事件。需要先调用setNotifyCharacteristicChanged接口才能接收server端的通知。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.on('BLECharacteristicChange')](js-apis-bluetoothManager.md#onblecharacteristicchangedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"BLECharacteristicChange"字符串，表示特征值变化事件。 |
| callback | Callback&lt;[BLECharacteristic](#blecharacteristicdeprecated)&gt; | 是    | 表示蓝牙低功耗设备的特征值变化事件的回调函数。                  |

**返回值：**

无

**示例：**

```js
function CharacteristicChange(CharacteristicChangeReq : bluetooth.BLECharacteristic) {
  let serviceUuid : string = CharacteristicChangeReq.serviceUuid;
  let characteristicUuid : string = CharacteristicChangeReq.characteristicUuid;
  let value = new Uint8Array(CharacteristicChangeReq.characteristicValue);
}
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
device.on('BLECharacteristicChange', CharacteristicChange);
```


### off('BLECharacteristicChange')<sup>(deprecated)</sup>

off(type: 'BLECharacteristicChange', callback?: Callback&lt;BLECharacteristic&gt;): void

取消订阅蓝牙低功耗设备的特征值变化事件。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.off('BLECharacteristicChange')](js-apis-bluetoothManager.md#offblecharacteristicchangedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"BLECharacteristicChange"字符串，表示特征值变化事件。 |
| callback | Callback&lt;[BLECharacteristic](#blecharacteristicdeprecated)&gt; | 否    | 表示取消订阅蓝牙低功耗设备的特征值变化事件。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```js
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
device.off('BLECharacteristicChange');
```


### on('BLEConnectionStateChange')<sup>(deprecated)</sup>

on(type: 'BLEConnectionStateChange', callback: Callback&lt;BLEConnectChangedState&gt;): void

client端订阅蓝牙低功耗设备的连接状态变化事件。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.on('BLEConnectionStateChange')](js-apis-bluetoothManager.md#onbleconnectionstatechangedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"BLEConnectionStateChange"字符串，表示连接状态变化事件。 |
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstatedeprecated)&gt; | 是    | 表示连接状态，已连接或断开。                           |

**返回值：**

无

**示例：**

```js
function ConnectStateChanged(state : bluetooth.BLEConnectChangedState) {
  console.log('bluetooth connect state changed');
  let connectState : bluetooth.ProfileConnectionState = state.state;
}
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
device.on('BLEConnectionStateChange', ConnectStateChanged);
```


### off('BLEConnectionStateChange')<sup>(deprecated)</sup>

off(type: 'BLEConnectionStateChange', callback?: Callback&lt;BLEConnectChangedState&gt;): void

取消订阅蓝牙低功耗设备的连接状态变化事件。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.off('BLEConnectionStateChange')](js-apis-bluetoothManager.md#offbleconnectionstatechangedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                                       |
| -------- | ---------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                   | 是    | 填写"BLEConnectionStateChange"字符串，表示连接状态变化事件。 |
| callback | Callback&lt;[BLEConnectChangedState](#bleconnectchangedstatedeprecated)&gt; | 否    | 表示取消订阅蓝牙低功耗设备的连接状态变化事件。不填该参数则取消订阅该type对应的所有回调。 |

**返回值：**

无

**示例：**

```js
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');
device.off('BLEConnectionStateChange');
```


### getDeviceName<sup>(deprecated)</sup>

getDeviceName(callback: AsyncCallback&lt;string&gt;): void

client获取远端蓝牙低功耗设备名。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.getDeviceName](js-apis-bluetoothManager.md#getdevicenamedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                          | 必填   | 说明                              |
| -------- | --------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback&lt;string&gt; | 是    | client获取对端server设备名，通过注册回调函数获取。 |

**返回值：**

无

**示例：**

```js
import { BusinessError } from '@ohos.base';
// callback
let gattClient : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice("XX:XX:XX:XX:XX:XX");
let deviceName : void = gattClient.getDeviceName((err : BusinessError, data : string)=> {
    console.info('device name err ' + JSON.stringify(err));
    console.info('device name' + JSON.stringify(data));
})
```


### getDeviceName<sup>(deprecated)</sup>

getDeviceName(): Promise&lt;string&gt;

client获取远端蓝牙低功耗设备名。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.getDeviceName](js-apis-bluetoothManager.md#getdevicenamedeprecated-1)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型                    | 说明                                 |
| --------------------- | ---------------------------------- |
| Promise&lt;string&gt; | client获取对端server设备名，通过promise形式获取。 |

**示例：**

```js
// promise
let gattClient : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice("XX:XX:XX:XX:XX:XX");
gattClient.getDeviceName().then((data) => {
    console.info('device name' + JSON.stringify(data));
})
```


### getRssiValue<sup>(deprecated)</sup>

getRssiValue(callback: AsyncCallback&lt;number&gt;): void

client获取远端蓝牙低功耗设备的信号强度 (Received Signal Strength Indication, RSSI)，调用[connect](#connectdeprecated)接口连接成功后才能使用。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.getRssiValue](js-apis-bluetoothManager.md#getrssivaluedeprecated)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名      | 类型                          | 必填   | 说明                             |
| -------- | --------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback&lt;number&gt; | 是    | 返回信号强度，单位&nbsp;dBm，通过注册回调函数获取。 |

**返回值：**

无

**示例：**

```js
import { BusinessError } from '@ohos.base';
// callback
let gattClient : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice("XX:XX:XX:XX:XX:XX");
let ret : boolean = gattClient.connect();
gattClient.getRssiValue((err : BusinessError, data : number)=> {
    console.info('rssi err ' + JSON.stringify(err));
    console.info('rssi value' + JSON.stringify(data));
})
```


### getRssiValue<sup>(deprecated)</sup>

getRssiValue(): Promise&lt;number&gt;

client获取远端蓝牙低功耗设备的信号强度 (Received Signal Strength Indication, RSSI)，调用[connect](#connectdeprecated)接口连接成功后才能使用。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattClientDevice.getRssiValue](js-apis-bluetoothManager.md#getrssivaluedeprecated-1)替代。

**需要权限**：ohos.permission.USE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型                    | 说明                                |
| --------------------- | --------------------------------- |
| Promise&lt;number&gt; | 返回信号强度，单位&nbsp;dBm，通过promise形式获取。 |

**示例：**

```js
// promise
let gattClient : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice("XX:XX:XX:XX:XX:XX");
gattClient.getRssiValue().then((data : number) => {
    console.info('rssi' + JSON.stringify(data));
})
```

## ScanMode<sup>(deprecated)</sup>

枚举，扫描模式。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.ScanMode](js-apis-bluetoothManager.md#scanmodedeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                                       | 值  | 说明              |
| ---------------------------------------- | ---- | --------------- |
| SCAN_MODE_NONE                           | 0    | 没有扫描模式。         |
| SCAN_MODE_CONNECTABLE                    | 1    | 可连接扫描模式。        |
| SCAN_MODE_GENERAL_DISCOVERABLE           | 2    | general发现模式。    |
| SCAN_MODE_LIMITED_DISCOVERABLE           | 3    | limited发现模式。    |
| SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE | 4    | 可连接general发现模式。 |
| SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE | 5    | 可连接limited发现模式。 |

## BondState<sup>(deprecated)</sup>

枚举，配对状态。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.BondState](js-apis-bluetoothManager.md#bondstatedeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                 | 值  | 说明     |
| ------------------ | ---- | ------ |
| BOND_STATE_INVALID | 0    | 无效的配对。 |
| BOND_STATE_BONDING | 1    | 正在配对。  |
| BOND_STATE_BONDED  | 2    | 已配对。   |


## SppOption<sup>(deprecated)</sup>

描述spp的配置参数。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.SppOption](js-apis-bluetoothManager.md#sppoptiondeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称     | 类型                | 可读   | 可写   | 说明          |
| ------ | ------------------- | ---- | ---- | ----------- |
| uuid   | string              | 是    | 是    | spp单据的uuid。 |
| secure | boolean             | 是    | 是    | 是否是安全通道。    |
| type   | [SppType](#spptypedeprecated) | 是    | 是    | Spp链路类型。    |


## SppType<sup>(deprecated)</sup>

枚举，Spp链路类型。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.SppType](js-apis-bluetoothManager.md#spptypedeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称         | 值  | 说明            |
| ---------- | ---- | ------------- |
| SPP_RFCOMM | 0    | 表示rfcomm链路类型。 |


## GattService<sup>(deprecated)</sup>

描述service的接口参数定义。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.GattService](js-apis-bluetoothManager.md#gattservicedeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称              | 类型                                     | 可读   | 可写   | 说明                                       |
| --------------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| serviceUuid     | string                                   | 是    | 是    | 特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |
| isPrimary       | boolean                                  | 是    | 是    | 如果是主服务设置为true，否则设置为false。                |
| characteristics | Array&lt;[BLECharacteristic](#blecharacteristicdeprecated)&gt; | 是    | 是    | 当前服务包含的特征列表。                             |
| includeServices | Array&lt;[GattService](#gattservicedeprecated)&gt; | 是    | 是    | 当前服务依赖的其它服务。                             |


## BLECharacteristic<sup>(deprecated)</sup>

描述characteristic的接口参数定义 。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.BLECharacteristic](js-apis-bluetoothManager.md#blecharacteristicdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                  | 类型                                     | 可读   | 可写   | 说明                                       |
| ------------------- | ---------------------------------------- | ---- | ---- | ---------------------------------------- |
| serviceUuid         | string                                   | 是    | 是    | 特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |
| characteristicUuid  | string                                   | 是    | 是    | 特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| characteristicValue | ArrayBuffer                              | 是    | 是    | 特征对应的二进制值。                               |
| descriptors         | Array&lt;[BLEDescriptor](#bledescriptordeprecated)&gt; | 是    | 是    | 特定特征的描述符列表。                              |


## BLEDescriptor<sup>(deprecated)</sup>

描述descriptor的接口参数定义 。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.BLEDescriptor](js-apis-bluetoothManager.md#bledescriptordeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                 | 类型        | 可读   | 可写   | 说明                                       |
| ------------------ | ----------- | ---- | ---- | ---------------------------------------- |
| serviceUuid        | string      | 是    | 是    | 特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |
| characteristicUuid | string      | 是    | 是    | 特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| descriptorUuid     | string      | 是    | 是    | 描述符（descriptor）的UUID，例如：00002902-0000-1000-8000-00805f9b34fb。 |
| descriptorValue    | ArrayBuffer | 是    | 是    | 描述符对应的二进制值。                              |


## NotifyCharacteristic<sup>(deprecated)</sup>

描述server端特征值变化时发送的特征通知参数定义。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.NotifyCharacteristic](js-apis-bluetoothManager.md#notifycharacteristicdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                  | 类型        | 可读   | 可写   | 说明                                       |
| ------------------- | ----------- | ---- | ---- | ---------------------------------------- |
| serviceUuid         | string      | 是    | 是    | 特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |
| characteristicUuid  | string      | 是    | 是    | 特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| characteristicValue | ArrayBuffer | 是    | 是    | 特征对应的二进制值。                               |
| confirm             | boolean     | 是    | 是    | 如果是notification则对端回复确认设置为true，如果是indication则对端不需要回复确认设置为false。 |


## CharacteristicReadReq<sup>(deprecated)</sup>

描述server端订阅后收到的特征值读请求事件参数结构。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.CharacteristicReadRequest](js-apis-bluetoothManager.md#characteristicreadrequestdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                 | 类型   | 可读   | 可写   | 说明                                       |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | 是    | 否    | 表示发送特征值读请求的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| transId            | number | 是    | 否    | 表示读请求的传输ID，server端回复响应时需填写相同的传输ID。       |
| offset             | number | 是    | 否    | 表示读特征值数据的起始位置。例如：k表示从第k个字节开始读，server端回复响应时需填写相同的offset。 |
| characteristicUuid | string | 是    | 否    | 特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| serviceUuid        | string | 是    | 否    | 特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |


## CharacteristicWriteReq<sup>(deprecated)</sup>

描述server端订阅后收到的特征值写请求事件参数结构。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.CharacteristicWriteRequest](js-apis-bluetoothManager.md#characteristicwriterequestdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                 | 类型   | 可读   | 可写   | 说明                                       |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | 是    | 否    | 表示发送特征值写请求的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| transId            | number | 是    | 否    | 表示写请求的传输ID，server端回复响应时需填写相同的传输ID。       |
| offset             | number | 是    | 否    | 表示写特征值数据的起始位置。例如：k表示从第k个字节开始写，server端回复响应时需填写相同的offset。 |
| isPrep             | boolean | 是    | 否    | 表示写请求是否立即执行。true表示立即执行。 |
| needRsp            | boolean | 是    | 否    | 表示是否要给client端回复响应。true表示需要回复。 |
| value              | ArrayBuffer | 是    | 否    | 表示写入的描述符二进制数据。 |
| characteristicUuid | string | 是    | 否    | 特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| serviceUuid        | string | 是    | 否    | 特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |


## DescriptorReadReq<sup>(deprecated)</sup>

描述server端订阅后收到的描述符读请求事件参数结构。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.DescriptorReadRequest](js-apis-bluetoothManager.md#descriptorreadrequestdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                 | 类型   | 可读   | 可写   | 说明                                       |
| ------------------ | ------ | ---- | ---- | ---------------------------------------- |
| deviceId           | string | 是    | 否    | 表示发送描述符读请求的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| transId            | number | 是    | 否    | 表示读请求的传输ID，server端回复响应时需填写相同的传输ID。       |
| offset             | number | 是    | 否    | 表示读描述符数据的起始位置。例如：k表示从第k个字节开始读，server端回复响应时需填写相同的offset。 |
| descriptorUuid     | string | 是    | 否    | 表示描述符（descriptor）的UUID，例如：00002902-0000-1000-8000-00805f9b34fb。 |
| characteristicUuid | string | 是    | 否    | 特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| serviceUuid        | string | 是    | 否    | 特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |


## DescriptorWriteReq<sup>(deprecated)</sup>

描述server端订阅后收到的描述符写请求事件参数结构。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.DescriptorWriteRequest](js-apis-bluetoothManager.md#descriptorwriterequestdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                 | 类型        | 可读   | 可写   | 说明                                       |
| ------------------ | ----------- | ---- | ---- | ---------------------------------------- |
| deviceId           | string      | 是    | 否    | 表示发送描述符写请求的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| transId            | number      | 是    | 否    | 表示写请求的传输ID，server端回复响应时需填写相同的传输ID。       |
| offset             | number      | 是    | 否    | 表示写描述符数据的起始位置。例如：k表示从第k个字节开始写，server端回复响应时需填写相同的offset。 |
| isPrep             | boolean     | 是    | 否    | 表示写请求是否立即执行。                             |
| needRsp            | boolean     | 是    | 否    | 表示是否要给client端回复响应。                       |
| value              | ArrayBuffer | 是    | 否    | 表示写入的描述符二进制数据。                           |
| descriptorUuid     | string      | 是    | 否    | 表示描述符（descriptor）的UUID，例如：00002902-0000-1000-8000-00805f9b34fb。 |
| characteristicUuid | string      | 是    | 否    | 特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |
| serviceUuid        | string      | 是    | 否    | 特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |


## ServerResponse<sup>(deprecated)</sup>

描述server端回复client端读/写请求的响应参数结构。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.ServerResponse](js-apis-bluetoothManager.md#serverresponsedeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称       | 类型        | 可读   | 可写   | 说明                                     |
| -------- | ----------- | ---- | ---- | -------------------------------------- |
| deviceId | string      | 是    | 否    | 表示远端设备地址，例如："XX:XX:XX:XX:XX:XX"。       |
| transId  | number      | 是    | 否    | 表示请求的传输ID，与订阅的读/写请求事件携带的ID保持一致。        |
| status   | number      | 是    | 否    | 表示响应的状态，设置为0即可，表示正常。                   |
| offset   | number      | 是    | 否    | 表示请求的读/写起始位置，与订阅的读/写请求事件携带的offset保持一致。 |
| value    | ArrayBuffer | 是    | 否    | 表示回复响应的二进制数据。                          |


## BLEConnectChangedState<sup>(deprecated)</sup>

描述Gatt profile连接状态 。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.BLEConnectChangedState](js-apis-bluetoothManager.md#bleconnectchangedstatedeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称     | 类型                                          | 可读 | 可写 | 说明                                          |
| -------- | ------------------------------------------------- | ---- | ---- | --------------------------------------------- |
| deviceId | string                                            | 是   | 否   | 表示远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| state    | [ProfileConnectionState](#profileconnectionstatedeprecated) | 是   | 是   | 表示BLE连接状态的枚举。                       |


## ProfileConnectionState<sup>(deprecated)</sup>

枚举，蓝牙设备的profile连接状态。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.ProfileConnectionState](js-apis-bluetoothManager.md#profileconnectionstatedeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                  | 值  | 说明             |
| ------------------- | ---- | -------------- |
| STATE_DISCONNECTED  | 0    | 表示profile已断连。  |
| STATE_CONNECTING    | 1    | 表示profile正在连接。 |
| STATE_CONNECTED     | 2    | 表示profile已连接。  |
| STATE_DISCONNECTING | 3    | 表示profile正在断连。 |


## ScanFilter<sup>(deprecated)</sup>

扫描过滤参数。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.ScanFilter](js-apis-bluetoothManager.md#scanfilterdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                                     | 类型    | 可读 | 可写 | 说明                                                         |
| ---------------------------------------- | ----------- | ---- | ---- | ------------------------------------------------------------ |
| deviceId                                 | string      | 是   | 是   | 表示过滤的BLE设备地址，例如："XX:XX:XX:XX:XX:XX"。           |
| name                                     | string      | 是   | 是   | 表示过滤的BLE设备名。                                        |
| serviceUuid                              | string      | 是   | 是   | 表示过滤包含该UUID服务的设备，例如：00001888-0000-1000-8000-00805f9b34fb。 |


## ScanOptions<sup>(deprecated)</sup>

扫描的配置参数。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.ScanOptions](js-apis-bluetoothManager.md#scanoptionsdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称        | 类型                    | 可读   | 可写   | 说明                                     |
| --------- | ----------------------- | ---- | ---- | -------------------------------------- |
| interval  | number                  | 是    | 是    | 表示扫描结果上报延迟时间，默认值为0。                    |
| dutyMode  | [ScanDuty](#scandutydeprecated)   | 是    | 是    | 表示扫描模式，默认值为SCAN_MODE_LOW_POWER。        |
| matchMode | [MatchMode](#matchmodedeprecated) | 是    | 是    | 表示硬件的过滤匹配模式，默认值为MATCH_MODE_AGGRESSIVE。 |


## ScanDuty<sup>(deprecated)</sup>

枚举，扫描模式。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.ScanDuty](js-apis-bluetoothManager.md#scandutydeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                    | 值  | 说明           |
| --------------------- | ---- | ------------ |
| SCAN_MODE_LOW_POWER   | 0    | 表示低功耗模式，默认值。 |
| SCAN_MODE_BALANCED    | 1    | 表示均衡模式。      |
| SCAN_MODE_LOW_LATENCY | 2    | 表示低延迟模式。     |


## MatchMode<sup>(deprecated)</sup>

枚举，硬件过滤匹配模式。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.MatchMode](js-apis-bluetoothManager.md#matchmodedeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                    | 值  | 说明                                       |
| --------------------- | ---- | ---------------------------------------- |
| MATCH_MODE_AGGRESSIVE | 1    | 表示硬件上报扫描结果门限较低，比如扫描到的功率较低或者一段时间扫描到的次数较少也触发上报，默认值。 |
| MATCH_MODE_STICKY     | 2    | 表示硬件上报扫描结果门限较高，更高的功率门限以及扫描到多次才会上报。       |


## ScanResult<sup>(deprecated)</sup>

扫描结果上报数据。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.ScanResult](js-apis-bluetoothManager.md#scanresultdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称       | 类型        | 可读   | 可写   | 说明                                 |
| -------- | ----------- | ---- | ---- | ---------------------------------- |
| deviceId | string      | 是    | 否    | 表示扫描到的设备地址，例如："XX:XX:XX:XX:XX:XX"。 |
| rssi     | number      | 是    | 否    | 表示扫描到的设备的rssi值。                    |
| data     | ArrayBuffer | 是    | 否    | 表示扫描到的设备发送的广播包。                    |


## BluetoothState<sup>(deprecated)</sup>

枚举，蓝牙开关状态。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.BluetoothState](js-apis-bluetoothManager.md#bluetoothstatedeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                    | 值  | 说明                 |
| --------------------- | ---- | ------------------ |
| STATE_OFF             | 0    | 表示蓝牙已关闭。           |
| STATE_TURNING_ON      | 1    | 表示蓝牙正在打开。          |
| STATE_ON              | 2    | 表示蓝牙已打开。           |
| STATE_TURNING_OFF     | 3    | 表示蓝牙正在关闭。          |
| STATE_BLE_TURNING_ON  | 4    | 表示蓝牙正在打开LE-only模式。 |
| STATE_BLE_ON          | 5    | 表示蓝牙正处于LE-only模式。  |
| STATE_BLE_TURNING_OFF | 6    | 表示蓝牙正在关闭LE-only模式。 |


## AdvertiseSetting<sup>(deprecated)</sup>

描述蓝牙低功耗设备发送广播的参数。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.AdvertiseSetting](js-apis-bluetoothManager.md#advertisesettingdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称          | 类型    | 可读   | 可写   | 说明                                       |
| ----------- | ------- | ---- | ---- | ---------------------------------------- |
| interval    | number  | 是    | 是    | 表示广播间隔，最小值设置32个slot表示20ms，最大值设置16384个slot，默认值设置为1600个slot表示1s。 |
| txPower     | number  | 是    | 是    | 表示发送功率，最小值设置-127，最大值设置1，默认值设置-7，单位dbm。   |
| connectable | boolean | 是    | 是    | 表示是否是可连接广播，默认值设置为true。                   |


## AdvertiseData<sup>(deprecated)</sup>

描述BLE广播数据包的内容。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.AdvertiseData](js-apis-bluetoothManager.md#advertisedatadeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称              | 类型                                     | 可读   | 可写   | 说明                          |
| --------------- | ---------------------------------------- | ---- | ---- | --------------------------- |
| serviceUuids    | Array&lt;string&gt;                      | 是    | 是    | 表示要广播的服务&nbsp;UUID&nbsp;列表。 |
| manufactureData | Array&lt;[ManufactureData](#manufacturedatadeprecated)&gt; | 是    | 是    | 表示要广播的广播的制造商信息列表。           |
| serviceData     | Array&lt;[ServiceData](#servicedatadeprecated)&gt; | 是    | 是    | 表示要广播的服务数据列表。               |


## ManufactureData<sup>(deprecated)</sup>

描述BLE广播数据包的内容。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.ManufactureData](js-apis-bluetoothManager.md#manufacturedatadeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称               | 类型                | 可读   | 可写   | 说明                 |
| ---------------- | ------------------- | ---- | ---- | ------------------ |
| manufactureId    | number  | 是    | 是    | 表示制造商的ID，由蓝牙SIG分配。 |
| manufactureValue | ArrayBuffer         | 是    | 是    | 表示制造商发送的制造商数据。     |


## ServiceData<sup>(deprecated)</sup>

描述广播包中服务数据内容。

> **说明：**<br/>
> 从API version 7开始支持，从API version 9开始废弃。建议使用[bluetoothManager.ServiceData](js-apis-bluetoothManager.md#servicedatadeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称           | 类型        | 可读   | 可写   | 说明         |
| ------------ | ----------- | ---- | ---- | ---------- |
| serviceUuid  | string      | 是    | 是    | 表示服务的UUID。 |
| serviceValue | ArrayBuffer | 是    | 是    | 表示服务数据。    |


## PinRequiredParam<sup>(deprecated)</sup>

描述配对请求参数。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.PinRequiredParam](js-apis-bluetoothManager.md#pinrequiredparamdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称       | 类型   | 可读   | 可写   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId | string | 是    | 否    | 表示要配对的设备ID。 |
| pinCode  | string | 是    | 否    | 表示要配对的密钥。   |


## BondStateParam<sup>(deprecated)</sup>

描述配对状态参数。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.BondStateParam](js-apis-bluetoothManager.md#bondstateparamdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称       | 类型   | 可读   | 可写   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| deviceId | string      | 是    | 否    | 表示要配对的设备ID。 |
| state    | BondState   | 是    | 否    | 表示配对设备的状态。 |


## StateChangeParam<sup>(deprecated)</sup>

描述profile状态改变参数。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.StateChangeParam](js-apis-bluetoothManager.md#statechangeparamdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称     | 类型                                          | 可读 | 可写 | 说明                            |
| -------- | ------------------------------------------------- | ---- | ---- | ------------------------------- |
| deviceId | string                                            | 是   | 否   | 表示蓝牙设备地址。              |
| state    | [ProfileConnectionState](#profileconnectionstatedeprecated) | 是   | 否   | 表示蓝牙设备的profile连接状态。 |


## DeviceClass<sup>(deprecated)</sup>

描述蓝牙设备的类别。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.DeviceClass](js-apis-bluetoothManager.md#deviceclassdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称              | 类型                                | 可读   | 可写   | 说明               |
| --------------- | ----------------------------------- | ---- | ---- | ---------------- |
| majorClass      | [MajorClass](#majorclassdeprecated)           | 是    | 否    | 表示蓝牙设备主要类别的枚举。   |
| majorMinorClass | [MajorMinorClass](#majorminorclassdeprecated) | 是    | 否    | 表示主要次要蓝牙设备类别的枚举。 |
| classOfDevice   | number                              | 是    | 否    | 表示设备类别。          |



## MajorClass<sup>(deprecated)</sup>

枚举，蓝牙设备主要类别。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.MajorClass](js-apis-bluetoothManager.md#majorclassdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                  | 值    | 说明         |
| ------------------- | ------ | ---------- |
| MAJOR_MISC          | 0x0000 | 表示杂项设备。    |
| MAJOR_COMPUTER      | 0x0100 | 表示计算机设备。   |
| MAJOR_PHONE         | 0x0200 | 表示手机设备。    |
| MAJOR_NETWORKING    | 0x0300 | 表示网络设备。    |
| MAJOR_AUDIO_VIDEO   | 0x0400 | 表示音频和视频设备。 |
| MAJOR_PERIPHERAL    | 0x0500 | 表示外围设备。    |
| MAJOR_IMAGING       | 0x0600 | 表示成像设备。    |
| MAJOR_WEARABLE      | 0x0700 | 表示可穿戴设备。   |
| MAJOR_TOY           | 0x0800 | 表示玩具设备。    |
| MAJOR_HEALTH        | 0x0900 | 表示健康设备。    |
| MAJOR_UNCATEGORIZED | 0x1F00 | 表示未分类设备。   |


## MajorMinorClass<sup>(deprecated)</sup>

枚举，主要次要蓝牙设备类别。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.MajorMinorClass](js-apis-bluetoothManager.md#majorminorclassdeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                                       | 值    | 说明              |
| ---------------------------------------- | ------ | --------------- |
| COMPUTER_UNCATEGORIZED                   | 0x0100 | 表示未分类计算机设备。     |
| COMPUTER_DESKTOP                         | 0x0104 | 表示台式计算机设备。      |
| COMPUTER_SERVER                          | 0x0108 | 表示服务器设备。        |
| COMPUTER_LAPTOP                          | 0x010C | 表示便携式计算机设备。     |
| COMPUTER_HANDHELD_PC_PDA                 | 0x0110 | 表示手持式计算机设备。     |
| COMPUTER_PALM_SIZE_PC_PDA                | 0x0114 | 表示掌上电脑设备。       |
| COMPUTER_WEARABLE                        | 0x0118 | 表示可穿戴计算机设备。     |
| COMPUTER_TABLET                          | 0x011C | 表示平板电脑设备。       |
| PHONE_UNCATEGORIZED                      | 0x0200 | 表示未分类手机设备。      |
| PHONE_CELLULAR                           | 0x0204 | 表示便携式手机设备。      |
| PHONE_CORDLESS                           | 0x0208 | 表示无线电话设备。       |
| PHONE_SMART                              | 0x020C | 表示智能手机设备。       |
| PHONE_MODEM_OR_GATEWAY                   | 0x0210 | 表示调制解调器或网关手机设备。 |
| PHONE_ISDN                               | 0x0214 | 表示ISDN手机设备。     |
| NETWORK_FULLY_AVAILABLE                  | 0x0300 | 表示网络完全可用设备。     |
| NETWORK_1_TO_17_UTILIZED                 | 0x0320 | 表示使用网络1到17设备。   |
| NETWORK_17_TO_33_UTILIZED                | 0x0340 | 表示使用网络17到33设备。  |
| NETWORK_33_TO_50_UTILIZED                | 0x0360 | 表示使用网络33到50设备。  |
| NETWORK_60_TO_67_UTILIZED                | 0x0380 | 表示使用网络60到67设备。  |
| NETWORK_67_TO_83_UTILIZED                | 0x03A0 | 表示使用网络67到83设备。  |
| NETWORK_83_TO_99_UTILIZED                | 0x03C0 | 表示使用网络83到99设备。  |
| NETWORK_NO_SERVICE                       | 0x03E0 | 表示网络无服务设备。      |
| AUDIO_VIDEO_UNCATEGORIZED                | 0x0400 | 表示未分类音频视频设备。    |
| AUDIO_VIDEO_WEARABLE_HEADSET             | 0x0404 | 表示可穿戴式音频视频设备。   |
| AUDIO_VIDEO_HANDSFREE                    | 0x0408 | 表示免提音频视频设备。     |
| AUDIO_VIDEO_MICROPHONE                   | 0x0410 | 表示麦克风音频视频设备。    |
| AUDIO_VIDEO_LOUDSPEAKER                  | 0x0414 | 表示扬声器音频视频设备。    |
| AUDIO_VIDEO_HEADPHONES                   | 0x0418 | 表示头戴式音频视频设备。    |
| AUDIO_VIDEO_PORTABLE_AUDIO               | 0x041C | 表示便携式音频视频设备。    |
| AUDIO_VIDEO_CAR_AUDIO                    | 0x0420 | 表示汽车音频视频设备。     |
| AUDIO_VIDEO_SET_TOP_BOX                  | 0x0424 | 表示机顶盒音频视频设备。    |
| AUDIO_VIDEO_HIFI_AUDIO                   | 0x0428 | 表示高保真音响设备。      |
| AUDIO_VIDEO_VCR                          | 0x042C | 表示录像机音频视频设备。    |
| AUDIO_VIDEO_VIDEO_CAMERA                 | 0x0430 | 表示照相机音频视频设备。    |
| AUDIO_VIDEO_CAMCORDER                    | 0x0434 | 表示摄像机音频视频设备。    |
| AUDIO_VIDEO_VIDEO_MONITOR                | 0x0438 | 表示监视器音频视频设备。    |
| AUDIO_VIDEO_VIDEO_DISPLAY_AND_LOUDSPEAKER | 0x043C | 表示视频显示器和扬声器设备。  |
| AUDIO_VIDEO_VIDEO_CONFERENCING           | 0x0440 | 表示音频视频会议设备。     |
| AUDIO_VIDEO_VIDEO_GAMING_TOY             | 0x0448 | 表示游戏玩具音频视频设备。   |
| PERIPHERAL_NON_KEYBOARD_NON_POINTING     | 0x0500 | 表示非键盘非指向外围设备。   |
| PERIPHERAL_KEYBOARD                      | 0x0540 | 表示外设键盘设备。       |
| PERIPHERAL_POINTING_DEVICE               | 0x0580 | 表示定点装置外围设备。     |
| PERIPHERAL_KEYBOARD_POINTING             | 0x05C0 | 表示键盘指向外围设备。     |
| PERIPHERAL_UNCATEGORIZED                 | 0x0500 | 表示未分类外围设备。      |
| PERIPHERAL_JOYSTICK                      | 0x0504 | 表示周边操纵杆设备。      |
| PERIPHERAL_GAMEPAD                       | 0x0508 | 表示周边游戏板设备。      |
| PERIPHERAL_REMOTE_CONTROL                | 0x05C0 | 表示远程控制外围设备。     |
| PERIPHERAL_SENSING_DEVICE                | 0x0510 | 表示外围传感设备设备。     |
| PERIPHERAL_DIGITIZER_TABLET              | 0x0514 | 表示外围数字化仪平板电脑设备。 |
| PERIPHERAL_CARD_READER                   | 0x0518 | 表示外围读卡器设备。      |
| PERIPHERAL_DIGITAL_PEN                   | 0x051C | 表示外设数码笔设备。      |
| PERIPHERAL_SCANNER_RFID                  | 0x0520 | 表示射频识别扫描仪外围设备。  |
| PERIPHERAL_GESTURAL_INPUT                | 0x0522 | 表示手势输入外围设备。     |
| IMAGING_UNCATEGORIZED                    | 0x0600 | 表示未分类的图像设备。     |
| IMAGING_DISPLAY                          | 0x0610 | 表示图像显示设备。       |
| IMAGING_CAMERA                           | 0x0620 | 表示成像照相机设备。      |
| IMAGING_SCANNER                          | 0x0640 | 表示成像扫描仪设备。      |
| IMAGING_PRINTER                          | 0x0680 | 表示成像打印机设备。      |
| WEARABLE_UNCATEGORIZED                   | 0x0700 | 表示未分类的可穿戴设备。    |
| WEARABLE_WRIST_WATCH                     | 0x0704 | 表示可穿戴腕表设备。      |
| WEARABLE_PAGER                           | 0x0708 | 表示可穿戴寻呼机设备。     |
| WEARABLE_JACKET                          | 0x070C | 表示夹克可穿戴设备。      |
| WEARABLE_HELMET                          | 0x0710 | 表示可穿戴头盔设备。      |
| WEARABLE_GLASSES                         | 0x0714 | 表示可穿戴眼镜设备。      |
| TOY_UNCATEGORIZED                        | 0x0800 | 表示未分类的玩具设备。     |
| TOY_ROBOT                                | 0x0804 | 表示玩具机器人设备。      |
| TOY_VEHICLE                              | 0x0808 | 表示玩具车设备。        |
| TOY_DOLL_ACTION_FIGURE                   | 0x080C | 表示人形娃娃玩具设备。     |
| TOY_CONTROLLER                           | 0x0810 | 表示玩具控制器设备。      |
| TOY_GAME                                 | 0x0814 | 表示玩具游戏设备。       |
| HEALTH_UNCATEGORIZED                     | 0x0900 | 表示未分类健康设备。      |
| HEALTH_BLOOD_PRESSURE                    | 0x0904 | 表示血压健康设备。       |
| HEALTH_THERMOMETER                       | 0x0908 | 表示温度计健康设备。      |
| HEALTH_WEIGHING                          | 0x090C | 表示体重健康设备。       |
| HEALTH_GLUCOSE                           | 0x0910 | 表示葡萄糖健康设备。      |
| HEALTH_PULSE_OXIMETER                    | 0x0914 | 表示脉搏血氧仪健康设备。    |
| HEALTH_PULSE_RATE                        | 0x0918 | 表示脉搏率健康设备。      |
| HEALTH_DATA_DISPLAY                      | 0x091C | 表示数据显示健康设备。     |
| HEALTH_STEP_COUNTER                      | 0x0920 | 表示阶梯计数器健康设备。    |
| HEALTH_BODY_COMPOSITION_ANALYZER         | 0x0924 | 表示身体成分分析仪健康设备。  |
| HEALTH_PEAK_FLOW_MOITOR                  | 0x0928 | 表示湿度计健康设备。      |
| HEALTH_MEDICATION_MONITOR                | 0x092C | 表示药物监视仪健康设备。    |
| HEALTH_KNEE_PROSTHESIS                   | 0x0930 | 表示膝盖假肢健康设备。     |
| HEALTH_ANKLE_PROSTHESIS                  | 0x0934 | 表示脚踝假肢健康设备。     |
| HEALTH_GENERIC_HEALTH_MANAGER            | 0x0938 | 表示通用健康管理设备。     |
| HEALTH_PERSONAL_MOBILITY_DEVICE          | 0x093C | 表示个人移动健康设备。     |


## PlayingState<sup>(deprecated)</sup>

枚举，蓝牙A2DP 播放状态。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.PlayingState](js-apis-bluetoothManager.md#playingstatedeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| STATE_NOT_PLAYING | 0x0000 | 表示未播放。  |
| STATE_PLAYING     | 0x0001 | 表示正在播放。 |


## ProfileId<sup>(deprecated)</sup>

蓝牙profile枚举，API9新增PROFILE_HID_HOST，PROFILE_PAN_NETWORK。

> **说明：**<br/>
> 从API version 8开始支持，从API version 9开始废弃。建议使用[bluetoothManager.ProfileId](js-apis-bluetoothManager.md#profileiddeprecated)替代。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                               | 值    | 说明              |
| -------------------------------- | ------ | --------------- |
| PROFILE_A2DP_SOURCE              | 1 | 表示A2DP profile。 |
| PROFILE_HANDS_FREE_AUDIO_GATEWAY | 4 | 表示HFP profile。  |
