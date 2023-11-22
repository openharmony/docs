# @ohos.bluetooth    
蓝牙模块提供了基础的传统蓝牙能力以及BLE的扫描、广播等功能。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import bluetooth from '@ohos.bluetooth'    
```  
    
## getState<sup>(deprecated)</sup>    
获取蓝牙开关状态。  
 **调用形式：**     
- getState(): BluetoothState  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.getState。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| BluetoothState | 表示蓝牙开关状态。 |  
    
 **示例代码：**   
```js    
let state : bluetooth.BluetoothState = bluetooth.getState();    
```    
  
    
## getBtConnectionState<sup>(deprecated)</sup>    
获取蓝牙本端的Profile连接状态，例如：任意一个支持的Profile连接状态为已连接，则此接口返回状态为已连接。  
 **调用形式：**     
- getBtConnectionState(): ProfileConnectionState  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.getBtConnectionState。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ProfileConnectionState | 表示蓝牙设备的Profile连接状态。 |  
    
 **示例代码：**   
```js    
let connectionState : bluetooth.ProfileConnectionState = bluetooth.getBtConnectionState();    
```    
  
    
## pairDevice<sup>(deprecated)</sup>    
发起蓝牙配对。  
 **调用形式：**     
- pairDevice(deviceId: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.pairDevice。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 发起蓝牙配对，成功返回true，否则返回false。 |  
    
 **示例代码：**   
```js    
let result : boolean = bluetooth.pairDevice("XX:XX:XX:XX:XX:XX");    
```    
  
    
## getRemoteDeviceName<sup>(deprecated)</sup>    
<span style="letter-spacing: 0px;">获取对端蓝牙设备的名称。</span>。  
 **调用形式：**     
- getRemoteDeviceName(deviceId: string): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.getRemoteDeviceName。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 表示远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 以字符串格式返回设备名称。 |  
    
 **示例代码：**   
```js    
let remoteDeviceName : string = bluetooth.getRemoteDeviceName("XX:XX:XX:XX:XX:XX");    
```    
  
    
## getRemoteDeviceClass<sup>(deprecated)</sup>    
获取对端蓝牙设备的类别。  
 **调用形式：**     
- getRemoteDeviceClass(deviceId: string): DeviceClass  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.getRemoteDeviceClass。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 表示远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DeviceClass | 远程设备的类别。 |  
    
 **示例代码：**   
```js    
let remoteDeviceClass : bluetooth.DeviceClass = bluetooth.getRemoteDeviceClass("XX:XX:XX:XX:XX:XX");    
```    
  
    
## enableBluetooth<sup>(deprecated)</sup>    
开启蓝牙。  
 **调用形式：**     
- enableBluetooth(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.enableBluetooth。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 打开蓝牙，成功返回true，否则返回false。 |  
    
 **示例代码：**   
```js    
let enable : boolean = bluetooth.enableBluetooth();    
```    
  
    
## disableBluetooth<sup>(deprecated)</sup>    
关闭蓝牙。  
 **调用形式：**     
- disableBluetooth(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.disableBluetooth。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 关闭蓝牙，成功返回true，否则返回false。 |  
    
 **示例代码：**   
```js    
let disable : boolean = bluetooth.disableBluetooth();    
```    
  
    
## getLocalName<sup>(deprecated)</sup>    
获取蓝牙本地设备名称。  
 **调用形式：**     
- getLocalName(): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.getLocalName。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 蓝牙本地设备名称。 |  
    
 **示例代码：**   
```js    
let localName : string = bluetooth.getLocalName();    
```    
  
    
## getPairedDevices<sup>(deprecated)</sup>    
获取蓝牙配对列表。  
 **调用形式：**     
- getPairedDevices(): Array\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.getPairedDevices。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 已配对蓝牙设备的地址列表。 |  
    
 **示例代码：**   
```js    
let devices : Array<string> = bluetooth.getPairedDevices();    
```    
  
    
## getProfileConnState<sup>(deprecated)</sup>    
依据ProfileId获取指定profile的连接状态。  
 **调用形式：**     
- getProfileConnState(profileId: ProfileId): ProfileConnectionState  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.getProfileConnectionState。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| profileId<sup>(deprecated)</sup> | ProfileId | true | 表示profile的枚举值，例如：PROFILE_A2DP_SOURCE。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ProfileConnectionState | profile的连接状态。 |  
    
 **示例代码：**   
```js    
let result : bluetooth.ProfileConnectionState = bluetooth.getProfileConnState(bluetooth.ProfileId.PROFILE_A2DP_SOURCE);    
```    
  
    
## setDevicePairingConfirmation<sup>(deprecated)</sup>    
设置设备配对请求确认。  
 **调用形式：**     
- setDevicePairingConfirmation(device: string, accept: boolean): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.setDevicePairingConfirmation。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.MANAGE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 表示远端设备地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
| accept<sup>(deprecated)</sup> | boolean | true | 接受配对请求设置为true，否则设置为false。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 设置设备配对确认，成功返回true，否则返回false。 |  
    
 **示例代码：**   
```js    
function onReceivePinRequiredEvent(data : bluetooth.PinRequiredParam) { // data为配对请求的入参，配对请求参数    console.info('pin required  = '+ JSON.stringify(data));    bluetooth.setDevicePairingConfirmation(data.deviceId, true);}bluetooth.on("pinRequired", onReceivePinRequiredEvent);    
```    
  
    
## setLocalName<sup>(deprecated)</sup>    
设置蓝牙本地设备名称。  
 **调用形式：**     
- setLocalName(name: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.setLocalName。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 要设置的蓝牙名称，最大长度为248字节数。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 设置蓝牙本地设备名称，成功返回true，否则返回false。 |  
    
 **示例代码：**   
```js    
let ret : boolean = bluetooth.setLocalName('device_name');    
```    
  
    
## setBluetoothScanMode<sup>(deprecated)</sup>    
设置蓝牙扫描模式，可以被远端设备发现。  
 **调用形式：**     
- setBluetoothScanMode(mode: ScanMode, duration: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.setBluetoothScanMode。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode<sup>(deprecated)</sup> | ScanMode | true | 蓝牙扫描模式。<br/> |  
| duration<sup>(deprecated)</sup> | number | true | 设备可被发现的持续时间，单位为毫秒；设置为0则持续可发现。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 设置蓝牙扫描，成功返回true，否则返回false。 |  
    
 **示例代码：**   
```js    
let result : boolean = bluetooth.setBluetoothScanMode(bluetooth.ScanMode    .SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE, 100);    
```    
  
    
## getBluetoothScanMode<sup>(deprecated)</sup>    
获取蓝牙扫描模式。  
 **调用形式：**     
- getBluetoothScanMode(): ScanMode  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.getBluetoothScanMode。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ScanMode | 蓝牙扫描模式。 |  
    
 **示例代码：**   
```js    
let scanMode : bluetooth.ScanMode = bluetooth.getBluetoothScanMode();    
```    
  
    
## startBluetoothDiscovery<sup>(deprecated)</sup>    
开启蓝牙扫描，可以发现远端设备。  
 **调用形式：**     
- startBluetoothDiscovery(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.startBluetoothDiscovery。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH and ohos.permission.LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 开启蓝牙扫描，成功返回true，否则返回false。 |  
    
 **示例代码：**   
```js    
let deviceId : Array<string>;function onReceiveEvent(data : Array<string>) {    deviceId = data;}bluetooth.on('bluetoothDeviceFind', onReceiveEvent);let result : boolean = bluetooth.startBluetoothDiscovery();    
```    
  
    
## stopBluetoothDiscovery<sup>(deprecated)</sup>    
关闭蓝牙扫描。  
 **调用形式：**     
- stopBluetoothDiscovery(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.stopBluetoothDiscovery。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 关闭蓝牙扫描，成功返回true，否则返回false。 |  
    
 **示例代码：**   
```js    
let result : boolean = bluetooth.stopBluetoothDiscovery();    
```    
  
    
## on('bluetoothDeviceFind')<sup>(deprecated)</sup>    
订阅蓝牙设备发现上报事件。  
 **调用形式：**     
- on(type: 'bluetoothDeviceFind', callback: Callback\<Array\<string>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.on#event:bluetoothDeviceFind。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"bluetoothDeviceFind"字符串，表示蓝牙设备发现事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<Array<string>> | true | 表示回调函数的入参，发现的设备集合。回调函数由用户创建通过该接口注册。<br/> |  
    
 **示例代码：**   
```js    
function onReceiveEvent(data : Array<string>) { // data为蓝牙设备地址集合    console.info('bluetooth device find = '+ JSON.stringify(data));}bluetooth.on('bluetoothDeviceFind', onReceiveEvent);    
```    
  
    
## off('bluetoothDeviceFind')<sup>(deprecated)</sup>    
取消订阅蓝牙设备发现上报事件。  
 **调用形式：**     
- off(type: 'bluetoothDeviceFind', callback?: Callback\<Array\<string>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.off#event:bluetoothDeviceFind。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"bluetoothDeviceFind"字符串，表示蓝牙设备发现事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<Array<string>> | false | 表示取消订阅蓝牙设备发现事件上报。不填该参数则取消订阅该type对应的所有回调。 |  
    
 **示例代码：**   
```js    
function onReceiveEvent(data : Array<string>) {    console.info('bluetooth device find = '+ JSON.stringify(data));}bluetooth.on('bluetoothDeviceFind', onReceiveEvent);bluetooth.off('bluetoothDeviceFind', onReceiveEvent);    
```    
  
    
## on('bondStateChange')<sup>(deprecated)</sup>    
订阅蓝牙配对状态改变事件。  
 **调用形式：**     
- on(type: 'bondStateChange', callback: Callback\<BondStateParam>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.on#event:bondStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"bondStateChange"字符串，表示蓝牙配对状态改变事件。 |  
| callback<sup>(deprecated)</sup> | Callback<BondStateParam> | true | 表示回调函数的入参，配对的状态。回调函数由用户创建通过该接口注册。 |  
    
 **示例代码：**   
```js    
function onReceiveEvent(data : bluetooth.BondStateParam) { // data为回调函数入参，表示配对的状态    console.info('pair state = '+ JSON.stringify(data));}bluetooth.on('bondStateChange', onReceiveEvent);    
```    
  
    
## off('bondStateChange')<sup>(deprecated)</sup>    
取消订阅蓝牙配对状态改变事件。  
 **调用形式：**     
- off(type: 'bondStateChange', callback?: Callback\<BondStateParam>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.off#event:bondStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"bondStateChange"字符串，表示蓝牙配对状态改变事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<BondStateParam> | false | 表示取消订阅蓝牙配对状态改变事件上报。不填该参数则取消订阅该type对应的所有回调。<br/> |  
    
 **示例代码：**   
```js    
function onReceiveEvent(data : bluetooth.BondStateParam) {    console.info('bond state = '+ JSON.stringify(data));}bluetooth.on('bondStateChange', onReceiveEvent);bluetooth.off('bondStateChange', onReceiveEvent);    
```    
  
    
## on('pinRequired')<sup>(deprecated)</sup>    
订阅远端蓝牙设备的配对请求事件。  
 **调用形式：**     
- on(type: 'pinRequired', callback: Callback\<PinRequiredParam>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.on#event:pinRequired。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"pinRequired"字符串，表示配对请求事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<PinRequiredParam> | true | 表示回调函数的入参，配对请求。回调函数由用户创建通过该接口注册。<br/> |  
    
 **示例代码：**   
```js    
function onReceiveEvent(data : bluetooth.PinRequiredParam) { // data为配对请求参数    console.info('pin required = '+ JSON.stringify(data));}bluetooth.on('pinRequired', onReceiveEvent);    
```    
  
    
## off('pinRequired')<sup>(deprecated)</sup>    
取消订阅远端蓝牙设备的配对请求事件。  
 **调用形式：**     
- off(type: 'pinRequired', callback?: Callback\<PinRequiredParam>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.off#event:pinRequired。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"pinRequired"字符串，表示配对请求事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<PinRequiredParam> | false | 表示取消订阅蓝牙配对请求事件上报，入参为配对请求参数。不填该参数则取消订阅该type对应的所有回调。<br/> |  
    
 **示例代码：**   
```js    
function onReceiveEvent(data : bluetooth.PinRequiredParam) {    console.info('pin required = '+ JSON.stringify(data));}bluetooth.on('pinRequired', onReceiveEvent);bluetooth.off('pinRequired', onReceiveEvent);    
```    
  
    
## on('stateChange')<sup>(deprecated)</sup>    
订阅蓝牙连接状态改变事件。  
 **调用形式：**     
- on(type: 'stateChange', callback: Callback\<BluetoothState>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.on#event:stateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"stateChange"字符串，表示蓝牙状态改变事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<BluetoothState> | true | 表示回调函数的入参，蓝牙状态。回调函数由用户创建通过该接口注册。<br/> |  
    
 **示例代码：**   
```js    
function onReceiveEvent(data : bluetooth.BluetoothState) {    console.info('bluetooth state = '+ JSON.stringify(data));}bluetooth.on('stateChange', onReceiveEvent);    
```    
  
    
## off('stateChange')<sup>(deprecated)</sup>    
取消订阅蓝牙连接状态改变事件。  
 **调用形式：**     
- off(type: 'stateChange', callback?: Callback\<BluetoothState>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.off#event:stateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"stateChange"字符串，表示蓝牙状态改变事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<BluetoothState> | false | 表示取消订阅蓝牙状态改变事件上报。不填该参数则取消订阅该type对应的所有回调。 |  
    
 **示例代码：**   
```js    
function onReceiveEvent(data : bluetooth.BluetoothState) {    console.info('bluetooth state = '+ JSON.stringify(data));}bluetooth.on('stateChange', onReceiveEvent);bluetooth.off('stateChange', onReceiveEvent);    
```    
  
    
## sppListen<sup>(deprecated)</sup>    
创建一个服务端监听Socket。  
 **调用形式：**     
- sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.sppListen。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 服务的名称。<br/> |  
| option<sup>(deprecated)</sup> | SppOption | true | spp监听配置参数。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 表示回调函数的入参，服务端Socket的id。 |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
## sppAccept<sup>(deprecated)</sup>    
服务端监听socket等待客户端连接。  
 **调用形式：**     
- sppAccept(serverSocket: number, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.sppAccept。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| serverSocket<sup>(deprecated)</sup> | number | true | 服务端socket的id。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 表示回调函数的入参，客户端socket的id。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
## sppConnect<sup>(deprecated)</sup>    
客户端向远端设备发起spp连接。  
 **调用形式：**     
- sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.sppConnect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 对端设备地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
| option<sup>(deprecated)</sup> | SppOption | true | spp客户端连接配置参数。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 表示回调函数的入参，客户端socket的id。 |  
    
 **示例代码：**   
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
  
    
## sppCloseServerSocket<sup>(deprecated)</sup>    
关闭服务端监听Socket，入参socket由sppListen接口返回。  
 **调用形式：**     
- sppCloseServerSocket(socket: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.sppCloseServerSocket。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| socket<sup>(deprecated)</sup> | number | true | 服务端监听socket的id。<br/> |  
    
 **示例代码：**   
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
  
    
## sppCloseClientSocket<sup>(deprecated)</sup>    
关闭客户端socket，入参socket由sppAccept或sppConnect接口获取。  
 **调用形式：**     
- sppCloseClientSocket(socket: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.sppCloseClientSocket。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| socket<sup>(deprecated)</sup> | number | true | 客户端socket的id。<br/> |  
    
 **示例代码：**   
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
  
    
## sppWrite<sup>(deprecated)</sup>    
通过socket向远端发送数据，入参clientSocket由sppAccept或sppConnect接口获取 。  
 **调用形式：**     
- sppWrite(clientSocket: number, data: ArrayBuffer): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.sppWrite。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| clientSocket<sup>(deprecated)</sup> | number | true | 客户端socket的id。<br/> |  
| data<sup>(deprecated)</sup> | ArrayBuffer | true | 写入的数据。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 写数据操作，成功返回true，否则返回false。 |  
    
 **示例代码：**   
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
  
    
## on('sppRead')<sup>(deprecated)</sup>    
订阅spp读请求事件，入参clientSocket由sppAccept或sppConnect接口获取。  
 **调用形式：**     
- on(type: 'sppRead', clientSocket: number, callback: Callback\<ArrayBuffer>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.on#event:sppRead。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"sppRead"字符串，表示spp读请求事件。<br/> |  
| clientSocket<sup>(deprecated)</sup> | number | true | 客户端socket的id。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<ArrayBuffer> | true | 表示回调函数的入参，读取到的数据。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
## off('sppRead')<sup>(deprecated)</sup>    
取消订阅spp读请求事件，入参clientSocket由sppAccept或sppConnect接口获取。  
 **调用形式：**     
- off(type: 'sppRead', clientSocket: number, callback?: Callback\<ArrayBuffer>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.off#event:sppRead。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"sppRead"字符串，表示spp读请求事件。<br/> |  
| clientSocket<sup>(deprecated)</sup> | number | true | 客户端Socket的id。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<ArrayBuffer> | false | 表示取消订阅spp读请求事件上报。不填该参数则取消订阅该type对应的所有回调。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
## getProfile<sup>(deprecated)</sup>    
通过ProfileId，获取profile的对象实例。  
 **调用形式：**     
- getProfile(profileId: ProfileId): A2dpSourceProfile | HandsFreeAudioGatewayProfile  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.getProfileInstance。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| profileId<sup>(deprecated)</sup> | ProfileId | true | 表示profile的枚举值，例如：PROFILE_A2DP_SOURCE。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| A2dpSourceProfile | HandsFreeAudioGatewayProfile | 对应的profile的对象实例，当前支持A2dpSourceProfile， HandsFreeAudioGatewayProfile。 |  
    
 **示例代码：**   
```js    
let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;    
```    
  
    
## BaseProfile<sup>(deprecated)</sup>    
profile基类。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.BaseProfile替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### getConnectionDevices<sup>(deprecated)</sup>    
返回已连接设备的地址列表。  
 **调用形式：**     
- getConnectionDevices(): Array\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.BaseProfile#getConnectionDevices。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 返回已连接设备的地址列表。 |  
    
 **示例代码：**   
```js    
let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;let retArray : Array<string> = a2dpSrc.getConnectionDevices();    
```    
  
    
### getDeviceState<sup>(deprecated)</sup>    
获取设备profile的连接状态。  
 **调用形式：**     
- getDeviceState(device: string): ProfileConnectionState  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.BaseProfile#getDeviceState。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 远端设备地址。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ProfileConnectionState | 返回profile的连接状态。 |  
    
 **示例代码：**   
```js    
let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;let ret : bluetooth.ProfileConnectionState = a2dpSrc.getDeviceState('XX:XX:XX:XX:XX:XX');    
```    
  
    
## A2dpSourceProfile<sup>(deprecated)</sup>    
使用A2dpSourceProfile方法之前需要创建该类的实例进行操作，通过getProfile()方法构造此实例。  
    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### connect<sup>(deprecated)</sup>    
发起设备的A2dp服务连接请求。  
 **调用形式：**     
- connect(device: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile#connect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 远端设备地址。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 成功返回true，失败返回false。 |  
    
 **示例代码：**   
```js    
let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;let ret : boolean = a2dpSrc.connect('XX:XX:XX:XX:XX:XX');    
```    
  
    
### disconnect<sup>(deprecated)</sup>    
断开设备的a2dp服务连接。  
 **调用形式：**     
- disconnect(device: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile#disconnect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 远端设备地址。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 成功返回true，失败返回false。 |  
    
 **示例代码：**   
```js    
let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;let ret : boolean = a2dpSrc.disconnect('XX:XX:XX:XX:XX:XX');    
```    
  
    
### on('connectionStateChange')<sup>(deprecated)</sup>    
订阅a2dp连接状态变化事件。  
 **调用形式：**     
- on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile.on#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"connectionStateChange"字符串，表示连接状态变化事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | true | 表示回调函数的入参。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
function onReceiveEvent(data : bluetooth.StateChangeParam) {    console.info('a2dp state = '+ JSON.stringify(data));}let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;a2dpSrc.on('connectionStateChange', onReceiveEvent);    
```    
  
    
### off('connectionStateChange')<sup>(deprecated)</sup>    
取消订阅a2dp连接状态变化事件。  
 **调用形式：**     
- off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile.off#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"connectionStateChange"字符串，表示连接状态变化事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | false | 表示回调函数的入参。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
function onReceiveEvent(data : bluetooth.StateChangeParam) {    console.info('a2dp state = '+ JSON.stringify(data));}let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;a2dpSrc.on('connectionStateChange', onReceiveEvent);a2dpSrc.off('connectionStateChange', onReceiveEvent);    
```    
  
    
### getPlayingState<sup>(deprecated)</sup>    
获取设备的播放状态。  
 **调用形式：**     
- getPlayingState(device: string): PlayingState  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.A2dpSourceProfile#getPlayingState。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 远端设备地址。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PlayingState | 远端设备的播放状态。 |  
    
## HandsFreeAudioGatewayProfile<sup>(deprecated)</sup>    
使用HandsFreeAudioGatewayProfile方法之前需要创建该类的实例进行操作，通过getProfile()方法构造此实例。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### connect<sup>(deprecated)</sup>    
连接设备的HFP服务。  
 **调用形式：**     
- connect(device: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile#connect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 远端设备地址。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 成功返回true，失败返回false。 |  
    
### disconnect<sup>(deprecated)</sup>    
断开连接设备的HFP服务。  
 **调用形式：**     
- disconnect(device: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile#disconnect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 远端设备地址。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 成功返回true，失败返回false。 |  
    
 **示例代码：**   
```js    
let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;let ret : boolean = a2dpSrc.disconnect('XX:XX:XX:XX:XX:XX');    
```    
  
    
### on('connectionStateChange')<sup>(deprecated)</sup>    
订阅HFP连接状态变化事件。  
 **调用形式：**     
- on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile.on#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"connectionStateChange"字符串，表示连接状态变化事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | true | <br/>表示回调函数的入参。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
function onReceiveEvent(data : bluetooth.StateChangeParam) {    console.info('a2dp state = '+ JSON.stringify(data));}let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;a2dpSrc.on('connectionStateChange', onReceiveEvent);    
```    
  
    
### off('connectionStateChange')<sup>(deprecated)</sup>    
取消订阅HFP连接状态变化事件。  
 **调用形式：**     
- off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.HandsFreeAudioGatewayProfile.off#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"connectionStateChange"字符串，表示连接状态变化事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | false | 表示回调函数的入参。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
function onReceiveEvent(data : bluetooth.StateChangeParam) {    console.info('a2dp state = '+ JSON.stringify(data));}let a2dpSrc : bluetooth.A2dpSourceProfile = bluetooth.getProfile(bluetooth.ProfileId.PROFILE_A2DP_SOURCE) as bluetooth.A2dpSourceProfile;a2dpSrc.on('connectionStateChange', onReceiveEvent);a2dpSrc.off('connectionStateChange', onReceiveEvent);    
```    
  
    
## createGattServer<sup>(deprecated)</sup>    
创建一个可使用的GattServer实例。  
 **调用形式：**     
- createGattServer(): GattServer  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.BLE.createGattServer。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| GattServer | server端类，使用server端方法之前需要创建该类的实例进行操作。 |  
    
 **示例代码：**   
```js    
et gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();    
```    
  
    
## createGattClientDevice<sup>(deprecated)</sup>    
创建一个可使用的GattClientDevice实例。  
 **调用形式：**     
- createGattClientDevice(deviceId: string): GattClientDevice  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.BLE.createGattClientDevice。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 对端设备地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| GattClientDevice | client端类，使用client端方法之前需要创建该类的实例进行操作。 |  
    
 **示例代码：**   
```js    
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');    
```    
  
    
## getConnectedBLEDevices<sup>(deprecated)</sup>    
获取和当前设备连接的BLE设备。  
 **调用形式：**     
- getConnectedBLEDevices(): Array\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.BLE.getConnectedBLEDevices。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 返回当前设备作为Server端时连接BLE设备地址集合。 |  
    
 **示例代码：**   
```js    
let result : Array<string> = bluetooth.BLE.getConnectedBLEDevices();    
```    
  
    
## startBLEScan<sup>(deprecated)</sup>    
发起BLE扫描流程。  
 **调用形式：**     
- startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.BLE.startBLEScan。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH and ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filters<sup>(deprecated)</sup> | Array<ScanFilter> | true | 表示扫描结果过滤策略集合，如果不使用过滤的方式，该参数设置为null。<br/> |  
| options<sup>(deprecated)</sup> | ScanOptions | false | 表示扫描的参数配置，可选参数。<br/> |  
    
 **示例代码：**   
```js    
function onReceiveEvent(data : Array<bluetooth.ScanResult>) {    console.info('BLE scan device find result = '+ JSON.stringify(data));}bluetooth.BLE.on("BLEDeviceFind", onReceiveEvent);let scanOptions : bluetooth.ScanOptions = {    interval: 500,    dutyMode: bluetooth.ScanDuty.SCAN_MODE_LOW_POWER,    matchMode: bluetooth.MatchMode.MATCH_MODE_AGGRESSIVE,}  
let scanFilter : bluetooth.ScanFilter = {    deviceId:"XX:XX:XX:XX:XX:XX",    name:"test",    serviceUuid:"00001888-0000-1000-8000-00805f9b34fb"}bluetooth.BLE.startBLEScan(    [scanFilter], scanOptions);    
```    
  
    
## stopBLEScan<sup>(deprecated)</sup>    
停止BLE扫描流程。  
 **调用形式：**     
- stopBLEScan(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.BLE.stopBLEScan。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **示例代码：**   
```js    
bluetooth.BLE.stopBLEScan();    
```    
  
    
## on('BLEDeviceFind')<sup>(deprecated)</sup>    
订阅BLE设备发现上报事件。  
 **调用形式：**     
- on(type: 'BLEDeviceFind', callback: Callback\<Array\<ScanResult>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.BLE.on#event:BLEDeviceFind。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"BLEDeviceFind"字符串，表示BLE设备发现事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<Array<ScanResult>> | true | 表示回调函数的入参，发现的设备集合。回调函数由用户创建通过该接口注册。<br/> |  
    
 **示例代码：**   
```js    
function onReceiveEvent(data : Array<bluetooth.ScanResult>) {    console.info('bluetooth device find = '+ JSON.stringify(data));}bluetooth.BLE.on('BLEDeviceFind', onReceiveEvent);    
```    
  
    
## off('BLEDeviceFind')<sup>(deprecated)</sup>    
取消订阅BLE设备发现上报事件。  
 **调用形式：**     
- off(type: 'BLEDeviceFind', callback?: Callback\<Array\<ScanResult>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.BLE.off#event:BLEDeviceFind。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"BLEDeviceFind"字符串，表示BLE设备发现事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<Array<ScanResult>> | false | 表示取消订阅BLE设备发现事件上报。不填该参数则取消订阅该type对应的所有回调。 |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
function onReceiveEvent(data : Array<bluetooth.ScanResult>) {    console.info('bluetooth device find = '+ JSON.stringify(data));}bluetooth.BLE.on('BLEDeviceFind', onReceiveEvent);bluetooth.BLE.off('BLEDeviceFind', onReceiveEvent);    
```    
  
    
## GattServer<sup>(deprecated)</sup>    
server端类，使用server端方法之前需要创建该类的实例进行操作，通过createGattServer()方法构造此实例。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.GattServer替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### startAdvertising<sup>(deprecated)</sup>    
开始发送BLE广播。  
 **调用形式：**     
- startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattServer#startAdvertising。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| setting<sup>(deprecated)</sup> | AdvertiseSetting | true | BLE广播的相关参数。<br/> |  
| advData<sup>(deprecated)</sup> | AdvertiseData | true | BLE广播包内容。<br/> |  
| advResponse<sup>(deprecated)</sup> | AdvertiseData | false | BLE回复扫描请求回复响应。 |  
    
 **示例代码：**   
```js    
let manufactureValueBuffer = new Uint8Array(4);manufactureValueBuffer[0] = 1;manufactureValueBuffer[1] = 2;manufactureValueBuffer[2] = 3;manufactureValueBuffer[3] = 4;  
let serviceValueBuffer = new Uint8Array(4);serviceValueBuffer[0] = 4;serviceValueBuffer[1] = 6;serviceValueBuffer[2] = 7;serviceValueBuffer[3] = 8;console.info('manufactureValueBuffer = '+ JSON.stringify(manufactureValueBuffer));console.info('serviceValueBuffer = '+ JSON.stringify(serviceValueBuffer));let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();let setting : bluetooth.AdvertiseSetting = {    interval:150,    txPower:60,    connectable:true,}  
let manufactureData : bluetooth.ManufactureData = {    manufactureId:4567,    manufactureValue:manufactureValueBuffer.buffer}  
let serviceData : bluetooth.ServiceData = {    serviceUuid:"00001888-0000-1000-8000-00805f9b34fb",    serviceValue:serviceValueBuffer.buffer}  
let advData : bluetooth.AdvertiseData = {    serviceUuids:["00001889-0000-1000-8000-00805f9b34fb"],    manufactureData:[manufactureData],    serviceData:[serviceData],}  
let advResponse : bluetooth.AdvertiseData = {    serviceUuids:["00001889-0000-1000-8000-00805f9b34fb"],    manufactureData:[manufactureData],    serviceData:[serviceData],}gattServer.startAdvertising(setting, advData, advResponse);    
```    
  
    
### stopAdvertising<sup>(deprecated)</sup>    
停止发送BLE广播。  
 **调用形式：**     
- stopAdvertising(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattServer#stopAdvertising。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
### addService<sup>(deprecated)</sup>    
server端添加服务。  
 **调用形式：**     
- addService(service: GattService): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattServer#addService。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| service<sup>(deprecated)</sup> | GattService | true | 服务端的service数据。BLE广播的相关参数<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 添加服务操作，成功返回true，否则返回false。 |  
    
 **示例代码：**   
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
删除已添加的服务。  
 **调用形式：**     
- removeService(serviceUuid: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattServer#removeService。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| serviceUuid<sup>(deprecated)</sup> | string | true | service的UUID，例如“00001810-0000-1000-8000-00805F9B34FB”。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 删除服务操作，成功返回true，否则返回false。 |  
    
 **示例代码：**   
```js    
let server : bluetooth.GattServer = bluetooth.BLE.createGattServer();server.removeService('00001810-0000-1000-8000-00805F9B34FB');    
```    
  
    
### close<sup>(deprecated)</sup>    
关闭服务端功能，去注册server在协议栈的注册，调用该接口后<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-bluetooth.md#gattserver">GattServer</a>实例将不能再使用。  
 **调用形式：**     
- close(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattServer#close。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
### notifyCharacteristicChanged<sup>(deprecated)</sup>    
server端特征值发生变化时，主动通知已连接的client设备。  
 **调用形式：**     
- notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattServer#notifyCharacteristicChanged。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 接收通知的client端设备地址，例如“XX:XX:XX:XX:XX:XX”。<br/> |  
| notifyCharacteristic<sup>(deprecated)</sup> | NotifyCharacteristic | true | <br/>通知的特征值数据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 通知操作，成功返回true，否则返回false。 |  
    
 **示例代码：**   
```js    
// 创建descriptorslet descriptors : Array<bluetooth.BLEDescriptor> = [];let arrayBuffer = new ArrayBuffer(8);let descV = new Uint8Array(arrayBuffer);descV[0] = 11;let descriptor : bluetooth.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};descriptors[0] = descriptor;let arrayBufferC = new ArrayBuffer(8);let characteristic : bluetooth.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};let notifyCharacteristic : bluetooth.NotifyCharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',  characteristicUuid: '00001821-0000-1000-8000-00805F9B34FB', characteristicValue: characteristic.characteristicValue, confirm: false};let server : bluetooth.GattServer = bluetooth.BLE.createGattServer();server.notifyCharacteristicChanged('XX:XX:XX:XX:XX:XX', notifyCharacteristic);    
```    
  
    
### sendResponse<sup>(deprecated)</sup>    
server端回复client端的读写请求。  
 **调用形式：**     
- sendResponse(serverResponse: ServerResponse): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattServer#sendResponse。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| serverResponse<sup>(deprecated)</sup> | ServerResponse | true | server端回复的响应数据。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 回复响应操作，成功返回true，否则返回false。 |  
    
 **示例代码：**   
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
server端订阅特征值读请求事件。  
 **调用形式：**     
- on(type: 'characteristicRead', callback: Callback\<CharacteristicReadReq>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattServer.on#event:characteristicRead。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"characteristicRead"字符串，表示特征值读请求事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<CharacteristicReadReq> | true | 表示回调函数的入参，client端发送的读请求数据。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
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
server端取消订阅特征值读请求事件。  
 **调用形式：**     
- off(type: 'characteristicRead', callback?: Callback\<CharacteristicReadReq>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattServer.off#event:characteristicRead。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"characteristicRead"字符串，表示特征值读请求事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<CharacteristicReadReq> | false | 表示取消订阅特征值读请求事件上报。不填该参数则取消订阅该type对应的所有回调。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();gattServer.off("characteristicRead");    
```    
  
    
### on('characteristicWrite')<sup>(deprecated)</sup>    
server端订阅特征值写请求事件。  
 **调用形式：**     
- on(type: 'characteristicWrite', callback: Callback\<CharacteristicWriteReq>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattServer.on#event:characteristicWrite。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"characteristicWrite"字符串，表示特征值写请求事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<CharacteristicWriteReq> | true | 表示回调函数的入参，client端发送的写请求数据。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
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
server端取消订阅特征值写请求事件。  
 **调用形式：**     
- off(type: 'characteristicWrite', callback?: Callback\<CharacteristicWriteReq>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattServer.off#event:characteristicWrite。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"characteristicWrite"字符串，表示特征值写请求事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<CharacteristicWriteReq> | false | 表示取消订阅特征值写请求事件上报。不填该参数则取消订阅该type对应的所有回调。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();gattServer.off("characteristicWrite");    
```    
  
    
### on('descriptorRead')<sup>(deprecated)</sup>    
server端订阅描述符读请求事件。  
 **调用形式：**     
- on(type: 'descriptorRead', callback: Callback\<DescriptorReadReq>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattServer.on#event:descriptorRead。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"descriptorRead"字符串，表示描述符读请求事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<DescriptorReadReq> | true | 表示回调函数的入参，client端发送的读请求数据。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
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
server端取消订阅描述符读请求事件。  
 **调用形式：**     
- off(type: 'descriptorRead', callback?: Callback\<DescriptorReadReq>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattServer.off#event:descriptorRead。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"descriptorRead"字符串，表示描述符读请求事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<DescriptorReadReq> | false | 表示取消订阅描述符读请求事件上报。不填该参数则取消订阅该type对应的所有回调。 |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();gattServer.off("descriptorRead");    
```    
  
    
### on('descriptorWrite')<sup>(deprecated)</sup>    
server端订阅描述符写请求事件。  
 **调用形式：**     
- on(type: 'descriptorWrite', callback: Callback\<DescriptorWriteReq>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattServer.on#event:descriptorWrite。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"descriptorWrite"字符串，表示描述符写请求事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<DescriptorWriteReq> | true | 表示回调函数的入参，client端发送的写请求数据。 |  
    
 **示例代码：**   
示例（callback）：  
  
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
server端取消订阅描述符写请求事件。  
 **调用形式：**     
- off(type: 'descriptorWrite', callback?: Callback\<DescriptorWriteReq>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattServer.off#event:descriptorWrite。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"descriptorWrite"字符串，表示描述符写请求事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<DescriptorWriteReq> | false | 表示取消订阅描述符写请求事件上报。不填该参数则取消订阅该type对应的所有回调。 |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();gattServer.off("descriptorWrite");    
```    
  
    
### on('connectStateChange')<sup>(deprecated)</sup>    
server端订阅BLE连接状态变化事件。  
 **调用形式：**     
- on(type: 'connectStateChange', callback: Callback\<BLEConnectChangedState>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattServer.on#event:connectStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"connectStateChange"字符串，表示BLE连接状态变化事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<BLEConnectChangedState> | true | 表示回调函数的入参，连接状态。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
function Connected(BLEConnectChangedState : bluetooth.BLEConnectChangedState) {  let deviceId : string = BLEConnectChangedState.deviceId;  let status : bluetooth.ProfileConnectionState = BLEConnectChangedState.state;}  
let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();gattServer.on("connectStateChange", Connected);    
```    
  
    
### off('connectStateChange')<sup>(deprecated)</sup>    
server端取消订阅BLE连接状态变化事件。  
 **调用形式：**     
- off(type: 'connectStateChange', callback?: Callback\<BLEConnectChangedState>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattServer.off#event:connectStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"connectStateChange"字符串，表示BLE连接状态变化事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<BLEConnectChangedState> | false | 表示取消订阅BLE连接状态变化事件。不填该参数则取消订阅该type对应的所有回调。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
let gattServer : bluetooth.GattServer = bluetooth.BLE.createGattServer();gattServer.off("connectStateChange");    
```    
  
    
## GattClientDevice<sup>(deprecated)</sup>    
client端类，使用client端方法之前需要创建该类的实例进行操作，通过createGattClientDevice(deviceId: string)方法构造此实例。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.GattClientDevice替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### connect<sup>(deprecated)</sup>    
client端发起连接远端蓝牙低功耗设备。  
 **调用形式：**     
- connect(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice#connect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 连接操作成功返回true，操作失败返回false。 |  
    
 **示例代码：**   
```js    
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');let ret : boolean = device.connect();    
```    
  
    
### disconnect<sup>(deprecated)</sup>    
client端断开与远端蓝牙低功耗设备的连接。  
 **调用形式：**     
- disconnect(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice#disconnect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 断开连接操作，成功返回true，操作失败返回false。 |  
    
 **示例代码：**   
```js    
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');let ret : boolean = device.disconnect();    
```    
  
    
### close<sup>(deprecated)</sup>    
关闭客户端功能，注销client在协议栈的注册，调用该接口后<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-bluetooth.md#gattclientdevice">GattClientDevice</a>实例将不能再使用。  
 **调用形式：**     
- close(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice#close。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 关闭操作，成功返回true，操作失败返回false。 |  
    
 **示例代码：**   
```js    
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');let ret : boolean = device.close();    
```    
  
    
### getDeviceName<sup>(deprecated)</sup>    
client获取远端蓝牙低功耗设备名。  
 **调用形式：**     
- getDeviceName(callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice#getDeviceName。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | client获取对端server设备名，通过注册回调函数获取。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
// callkback 模式  
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
  
    
### getDeviceName<sup>(deprecated)</sup>    
client获取远端蓝牙低功耗设备名。  
 **调用形式：**     
- getDeviceName(): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice#getDeviceName。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | client获取对端server设备名，通过promise形式获取。 |  
    
 **示例代码：**   
示例（promise）：  
  
```js    
// Promise 模式let device : bluetooth.GattClientDevice= bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');device.connect();device.getServices().then((result : Array<bluetooth.GattService>) => {    console.info("getServices successfully:" + JSON.stringify(result));});    
```    
  
    
### getServices<sup>(deprecated)</sup>    
client端获取蓝牙低功耗设备的所有服务，即服务发现 。  
 **调用形式：**     
- getServices(callback: AsyncCallback\<Array\<GattService>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice#getServices。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<GattService>> | true | client进行服务发现，通过注册回调函数获取。 |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
// callkback 模式  
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
client端获取蓝牙低功耗设备的所有服务，即服务发现。  
 **调用形式：**     
- getServices(): Promise\<Array\<GattService>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice#getServices。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<GattService>> | client进行服务发现，通过promise形式获取。 |  
    
 **示例代码：**   
示例（promise）：  
  
```js    
// Promise 模式let device : bluetooth.GattClientDevice= bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');device.connect();device.getServices().then((result : Array<bluetooth.GattService>) => {    console.info("getServices successfully:" + JSON.stringify(result));});    
```    
  
    
### readCharacteristicValue<sup>(deprecated)</sup>    
client端读取蓝牙低功耗设备特定服务的特征值。  
 **调用形式：**     
- readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice#readCharacteristicValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| characteristic<sup>(deprecated)</sup> | BLECharacteristic | true | 待读取的特征值。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<BLECharacteristic> | true | client读取特征值，通过注册回调函数获取。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
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
client端读取蓝牙低功耗设备特定服务的特征值。  
 **调用形式：**     
- readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice#readCharacteristicValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| characteristic<sup>(deprecated)</sup> | BLECharacteristic | true | 待读取的特征值。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<BLECharacteristic> | client读取特征值，通过promise形式获取。 |  
    
 **示例代码：**   
示例（promise）：  
  
```js    
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');let descriptors : Array<bluetooth.BLEDescriptor> = [];let bufferDesc = new ArrayBuffer(8);let descV = new Uint8Array(bufferDesc);descV[0] = 11;let descriptor : bluetooth.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};descriptors[0] = descriptor;  
let bufferCCC = new ArrayBuffer(8);let cccV = new Uint8Array(bufferCCC);cccV[0] = 1;let characteristic : bluetooth.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',characteristicValue: bufferCCC, descriptors:descriptors};device.readCharacteristicValue(characteristic);    
```    
  
    
### readDescriptorValue<sup>(deprecated)</sup>    
client端读取蓝牙低功耗设备特定的特征包含的描述符。  
 **调用形式：**     
- readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice#readDescriptorValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| descriptor<sup>(deprecated)</sup> | BLEDescriptor | true | 待读取的描述符。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<BLEDescriptor> | true | client读取描述符，通过注册回调函数获取。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
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
client端读取蓝牙低功耗设备特定的特征包含的描述符。  
 **调用形式：**     
- readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice#readDescriptorValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| descriptor<sup>(deprecated)</sup> | BLEDescriptor | true | 待读取的描述符。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<BLEDescriptor> | client读取描述符，通过promise形式获取。 |  
    
 **示例代码：**   
示例（promise）：  
  
```js    
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');let bufferDesc = new ArrayBuffer(8);let descV = new Uint8Array(bufferDesc);descV[0] = 11;let descriptor : bluetooth.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',  descriptorUuid: '00002903-0000-1000-8000-00805F9B34FB', descriptorValue: bufferDesc};device.readDescriptorValue(descriptor);    
```    
  
    
### writeCharacteristicValue<sup>(deprecated)</sup>    
client端向低功耗蓝牙设备写入特定的特征值。  
 **调用形式：**     
- writeCharacteristicValue(characteristic: BLECharacteristic): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice#writeCharacteristicValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| characteristic<sup>(deprecated)</sup> | BLECharacteristic | true | 蓝牙设备特征对应的二进制值及其它参数。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 写特征值操作成功返回true，操作失败返回false。 |  
    
 **示例代码：**   
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
client端向低功耗蓝牙设备特定的描述符写入二进制数据。  
 **调用形式：**     
- writeDescriptorValue(descriptor: BLEDescriptor): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice#writeDescriptorValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| descriptor<sup>(deprecated)</sup> | BLEDescriptor | true | 蓝牙设备描述符的二进制值及其它参数。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 写描述符操作成功返回true，操作失败返回false。 |  
    
 **示例代码：**   
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
  
    
### getRssiValue<sup>(deprecated)</sup>    
client获取远端蓝牙低功耗设备的信号强度 (Received Signal Strength Indication, RSSI)，调用<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-bluetooth.md#connect">connect</a>接口连接成功后才能使用。  
 **调用形式：**     
- getRssiValue(callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice#getRssiValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 返回信号强度，单位dBm，通过注册回调函数获取。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
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
client获取远端蓝牙低功耗设备的信号强度 (Received Signal Strength Indication, RSSI)，调用<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-bluetooth.md#connect">connect</a>接口连接成功后才能使用。  
 **调用形式：**     
- getRssiValue(): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice#getRssiValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 返回信号强度，单位 dBm，通过promise形式获取。 |  
    
 **示例代码：**   
示例（promise）：  
  
```js    
// promiselet gattClient : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice("XX:XX:XX:XX:XX:XX");gattClient.getRssiValue().then((data : number) => {    console.info('rssi' + JSON.stringify(data));})    
```    
  
    
### setBLEMtuSize<sup>(deprecated)</sup>    
client协商远端蓝牙低功耗设备的最大传输单元（Maximum Transmission Unit, MTU），调用<a href="https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-bluetooth.md#connect">connect</a>接口连接成功后才能使用。  
 **调用形式：**     
- setBLEMtuSize(mtu: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice#setBLEMtuSize。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mtu<sup>(deprecated)</sup> | number | true | 设置范围为22~512字节。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | MTU协商操作成功返回true，操作失败返回false。 |  
    
 **示例代码：**   
```js    
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');device.setBLEMtuSize(128);    
```    
  
    
### setNotifyCharacteristicChanged<sup>(deprecated)</sup>    
向服务端发送设置通知此特征值请求。  
 **调用形式：**     
- setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice#setNotifyCharacteristicChanged。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| characteristic<sup>(deprecated)</sup> | BLECharacteristic | true | 蓝牙低功耗特征。<br/> |  
| enable<sup>(deprecated)</sup> | boolean | true | 启用接收notify设置为true，否则设置为false。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 设置操作成功返回true，操作失败返回false。 |  
    
 **示例代码：**   
```js    
// 创建descriptorslet descriptors : Array<bluetooth.BLEDescriptor> = [];let arrayBuffer = new ArrayBuffer(8);let descV = new Uint8Array(arrayBuffer);descV[0] = 11;let descriptor : bluetooth.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',  descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};descriptors[0] = descriptor;let arrayBufferC = new ArrayBuffer(8);let characteristic : bluetooth.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',  characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');device.setNotifyCharacteristicChanged(characteristic, false);    
```    
  
    
### on('BLECharacteristicChange')<sup>(deprecated)</sup>    
订阅蓝牙低功耗设备的特征值变化事件。需要先调用setNotifyCharacteristicChanged接口才能接收server端的通知。  
 **调用形式：**     
- on(type: 'BLECharacteristicChange', callback: Callback\<BLECharacteristic>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice.on#event:BLECharacteristicChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"BLECharacteristicChange"字符串，表示特征值变化事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<BLECharacteristic> | true | 表示蓝牙低功耗设备的特征值变化事件的回调函数。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
<span style="letter-spacing: 0px;">function CharacteristicChange(CharacteristicChangeReq : bluetooth.BLECharacteristic) {</span>  
  let serviceUuid : string = CharacteristicChangeReq.serviceUuid;  let characteristicUuid : string = CharacteristicChangeReq.characteristicUuid;  let value = new Uint8Array(CharacteristicChangeReq.characteristicValue);}let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');device.on('BLECharacteristicChange', CharacteristicChange);    
```    
  
    
### off('BLECharacteristicChange')<sup>(deprecated)</sup>    
取消订阅蓝牙低功耗设备的特征值变化事件。  
 **调用形式：**     
- off(type: 'BLECharacteristicChange', callback?: Callback\<BLECharacteristic>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice.off#event:BLECharacteristicChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"BLECharacteristicChange"字符串，表示特征值变化事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<BLECharacteristic> | false | 表示取消订阅蓝牙低功耗设备的特征值变化事件。不填该参数则取消订阅该type对应的所有回调。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');device.off('BLECharacteristicChange');    
```    
  
    
### on('BLEConnectionStateChange')<sup>(deprecated)</sup>    
client端订阅蓝牙低功耗设备的连接状态变化事件。  
 **调用形式：**     
- on(type: 'BLEConnectionStateChange', callback: Callback\<BLEConnectChangedState>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice.on#event:BLEConnectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"BLEConnectionStateChange"字符串，表示连接状态变化事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<BLEConnectChangedState> | true | 表示连接状态，已连接或断开。<br/> |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
function ConnectStateChanged(state : bluetooth.BLEConnectChangedState) {  console.log('bluetooth connect state changed');  let connectState : bluetooth.ProfileConnectionState = state.state;}let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');device.on('BLEConnectionStateChange', ConnectStateChanged);    
```    
  
    
### off('BLEConnectionStateChange')<sup>(deprecated)</sup>    
取消订阅蓝牙低功耗设备的连接状态变化事件。  
 **调用形式：**     
- off(type: 'BLEConnectionStateChange', callback?: Callback\<BLEConnectChangedState>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.bluetoothManager/bluetoothManager.GattClientDevice.off#event:BLEConnectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"BLEConnectionStateChange"字符串，表示连接状态变化事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<BLEConnectChangedState> | false | 表示取消订阅蓝牙低功耗设备的连接状态变化事件。不填该参数则取消订阅该type对应的所有回调。 |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
let device : bluetooth.GattClientDevice = bluetooth.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');device.off('BLEConnectionStateChange');    
```    
  
    
## GattService<sup>(deprecated)</sup>    
描述service的接口参数定义。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.GattService替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。<br/> |  
| isPrimary<sup>(deprecated)</sup> | boolean | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>如果是主服务设置为true，否则设置为false。<br/> |  
| characteristics<sup>(deprecated)</sup> | Array<BLECharacteristic> | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>当前服务包含的特征列表。<br/> |  
| includeServices<sup>(deprecated)</sup> | Array<GattService> | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>当前服务依赖的其它服务。 |  
    
## BLECharacteristic<sup>(deprecated)</sup>    
描述characteristic的接口参数定义 。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.BLECharacteristic替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。<br/> |  
| characteristicUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。<br/> |  
| characteristicValue<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特征对应的二进制值。<br/> |  
| descriptors<sup>(deprecated)</sup> | Array<BLEDescriptor> | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特定特征的描述符列表。<br/> |  
    
## BLEDescriptor<sup>(deprecated)</sup>    
描述descriptor的接口参数定义 。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.BLEDescriptor替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。<br/> |  
| characteristicUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。<br/> |  
| descriptorUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>描述符（descriptor）的UUID，例如：00002902-0000-1000-8000-00805f9b34fb。<br/> |  
| descriptorValue<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>描述符对应的二进制值。 |  
    
## NotifyCharacteristic<sup>(deprecated)</sup>    
描述server端特征值变化时发送的特征通知参数定义。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.NotifyCharacteristic替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。<br/> |  
| characteristicUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。<br/> |  
| characteristicValue<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特征对应的二进制值。<br/> |  
| confirm<sup>(deprecated)</sup> | boolean | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>如果是notification则对端回复确认设置为true，如果是indication则对端不需要回复确认设置为false。<br/> |  
    
## CharacteristicReadReq<sup>(deprecated)</sup>    
描述server端订阅后收到的特征值读请求事件参数结构。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.CharacteristicReadRequest替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示发送特征值读请求的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
| transId<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示读请求的传输ID，server端回复响应时需填写相同的传输ID。<br/> |  
| offset<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示读特征值数据的起始位置。例如：k表示从第k个字节开始读，server端回复响应时需填写相同的offset。<br/> |  
| characteristicUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。<br/> |  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |  
    
## CharacteristicWriteReq<sup>(deprecated)</sup>    
描述server端订阅后收到的特征值写请求事件参数结构。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.CharacteristicWriteRequest替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示发送特征值写请求的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
| transId<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示写请求的传输ID，server端回复响应时需填写相同的传输ID。<br/> |  
| offset<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示写特征值数据的起始位置。例如：k表示从第k个字节开始写，server端回复响应时需填写相同的offset。<br/> |  
| isPrep<sup>(deprecated)</sup> | boolean | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示写请求是否立即执行。<br/> |  
| needRsp<sup>(deprecated)</sup> | boolean | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示是否要给client端回复响应。<br/> |  
| value<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示写入的描述符二进制数据。<br/> |  
| characteristicUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。<br/> |  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |  
    
## DescriptorReadReq<sup>(deprecated)</sup>    
描述server端订阅后收到的描述符读请求事件参数结构。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.DescriptorReadRequest替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示发送描述符读请求的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
| transId<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示读请求的传输ID，server端回复响应时需填写相同的传输ID。<br/> |  
| offset<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示读描述符数据的起始位置。例如：k表示从第k个字节开始读，server端回复响应时需填写相同的offset。<br/> |  
| descriptorUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示描述符（descriptor）的UUID，例如：00002902-0000-1000-8000-00805f9b34fb。<br/> |  
| characteristicUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。<br/> |  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。<br/> |  
    
## DescriptorWriteReq<sup>(deprecated)</sup>    
描述server端订阅后收到的描述符写请求事件参数结构。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.DescriptorWriteRequest替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示发送描述符写请求的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
| transId<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示写请求的传输ID，server端回复响应时需填写相同的传输ID。<br/> |  
| offset<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示写描述符数据的起始位置。例如：k表示从第k个字节开始写，server端回复响应时需填写相同的offset。<br/> |  
| isPrep<sup>(deprecated)</sup> | boolean | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示写请求是否立即执行。<br/> |  
| needRsp<sup>(deprecated)</sup> | boolean | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示是否要给client端回复响应。<br/> |  
| value<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示写入的描述符二进制数据。<br/> |  
| descriptorUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示描述符（descriptor）的UUID，例如：00002902-0000-1000-8000-00805f9b34fb。<br/> |  
| characteristicUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。<br/> |  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |  
    
## ServerResponse<sup>(deprecated)</sup>    
描述server端回复client端读/写请求的响应参数结构。  
    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.ServerResponse替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示远端设备地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
| transId<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示请求的传输ID，与订阅的读/写请求事件携带的ID保持一致。<br/> |  
| status<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示响应的状态，设置为0即可，表示正常。<br/> |  
| offset<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示请求的读/写起始位置，与订阅的读/写请求事件携带的offset保持一致。<br/> |  
| value<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示回复响应的二进制数据。<br/> |  
    
## BLEConnectChangedState<sup>(deprecated)</sup>    
描述Gatt profile连接状态 。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.BLEConnectChangedState替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示远端设备地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
| state<sup>(deprecated)</sup> | ProfileConnectionState | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示BLE连接状态的枚举。<br/> |  
    
## ScanResult<sup>(deprecated)</sup>    
扫描结果上报数据。  
    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.ScanResult替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示扫描到的设备地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
| rssi<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示扫描到的设备的rssi值。<br/> |  
| data<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示扫描到的设备发送的广播包。<br/> |  
    
## AdvertiseSetting<sup>(deprecated)</sup>    
描述蓝牙低功耗设备发送广播的参数。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.AdvertiseSetting替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| interval<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示广播间隔，最小值设置32个slot表示20ms，最大值设置16384个slot，默认值设置为1600个slot表示1s。<br/> |  
| txPower<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示发送功率，最小值设置-127，最大值设置1，默认值设置-7，单位dbm。<br/> |  
| connectable<sup>(deprecated)</sup> | boolean | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示是否是可连接广播，默认值设置为true。<br/> |  
    
## AdvertiseData<sup>(deprecated)</sup>    
描述BLE广播数据包的内容。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.AdvertiseData替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| serviceUuids<sup>(deprecated)</sup> | Array<string> | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示要广播的服务UUID列表。<br/> |  
| manufactureData<sup>(deprecated)</sup> | Array<ManufactureData> | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示要广播的广播的制造商信息列表。<br/> |  
| serviceData<sup>(deprecated)</sup> | Array<ServiceData> | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示要广播的服务数据列表。<br/> |  
    
## ManufactureData<sup>(deprecated)</sup>    
描述BLE广播数据包的内容。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.ManufactureData替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| manufactureId<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示制造商的ID，由蓝牙SIG分配。<br/> |  
| manufactureValue<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示制造商发送的制造商数据。<br/> |  
    
## ServiceData<sup>(deprecated)</sup>    
描述广播包中服务数据内容。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.ServiceData替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示服务的UUID。<br/> |  
| serviceValue<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示服务数据。 |  
    
## ScanFilter<sup>(deprecated)</sup>    
扫描过滤参数。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.ScanFilter替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示过滤的BLE设备地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
| name<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示过滤的BLE设备名。<br/> |  
| serviceUuid<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示过滤包含该UUID服务的设备，例如：00001888-0000-1000-8000-00805f9b34fb。<br/> |  
    
## ScanOptions<sup>(deprecated)</sup>    
扫描的配置参数。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.ScanOptions替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| interval<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示扫描结果上报延迟时间，默认值为0。<br/> |  
| dutyMode<sup>(deprecated)</sup> | ScanDuty | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示扫描模式，默认值为SCAN_MODE_LOW_POWER。<br/> |  
| matchMode<sup>(deprecated)</sup> | MatchMode | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示硬件的过滤匹配模式，默认值为MATCH_MODE_AGGRESSIVE。 |  
    
## SppOption<sup>(deprecated)</sup>    
描述spp的配置参数。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.SppOption替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uuid<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>spp单据的uuid。<br/> |  
| secure<sup>(deprecated)</sup> | boolean | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>是否是安全通道。<br/> |  
| type<sup>(deprecated)</sup> | SppType | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>Spp链路类型。<br/> |  
    
## PinRequiredParam<sup>(deprecated)</sup>    
描述配对请求参数。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.PinRequiredParam替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示要配对的设备ID。<br/> |  
| pinCode<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示要配对的密钥。 |  
    
## DeviceClass<sup>(deprecated)</sup>    
描述蓝牙设备的类别。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.DeviceClass替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| majorClass<sup>(deprecated)</sup> | MajorClass | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示蓝牙设备主要类别的枚举。<br/> |  
| majorMinorClass<sup>(deprecated)</sup> | MajorMinorClass | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示主要次要蓝牙设备类别的枚举。<br/> |  
| classOfDevice<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示设备类别。<br/> |  
    
## BondStateParam<sup>(deprecated)</sup>    
描述配对状态参数。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.BondStateParam替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示要配对的设备ID。<br/> |  
| state<sup>(deprecated)</sup> | BondState | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示配对设备的状态。 |  
    
## ScanDuty<sup>(deprecated)</sup>    
枚举，扫描模式。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.ScanDuty替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SCAN_MODE_LOW_POWER<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示低功耗模式，默认值。<br/> |  
| SCAN_MODE_BALANCED<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示均衡模式。<br/> |  
| SCAN_MODE_LOW_LATENCY<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示低延迟模式。 |  
    
## MatchMode<sup>(deprecated)</sup>    
枚举，硬件过滤匹配模式。  
    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.MatchMode替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MATCH_MODE_AGGRESSIVE<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示硬件上报扫描结果门限较低，比如扫描到的功率较低或者一段时间扫描到的次数较少也触发上报，默认值。<br/> |  
| MATCH_MODE_STICKY<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示硬件上报扫描结果门限较高，更高的功率门限以及扫描到多次才会上报。<br/> |  
    
## ProfileConnectionState<sup>(deprecated)</sup>    
枚举，蓝牙设备的profile连接状态。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.ProfileConnectionState替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STATE_DISCONNECTED<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示profile已断连。<br/> |  
| STATE_CONNECTING<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示profile正在连接。<br/> |  
| STATE_CONNECTED<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示profile已连接。<br/> |  
| STATE_DISCONNECTING<sup>(deprecated)</sup> | 3 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示profile正在断连。<br/> |  
    
## BluetoothState<sup>(deprecated)</sup>    
枚举，蓝牙开关状态。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.BluetoothState替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STATE_OFF<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示蓝牙已关闭。<br/> |  
| STATE_TURNING_ON<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示蓝牙正在打开。<br/> |  
| STATE_ON<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示蓝牙已打开。<br/> |  
| STATE_TURNING_OFF<sup>(deprecated)</sup> | 3 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示蓝牙正在关闭。<br/> |  
| STATE_BLE_TURNING_ON<sup>(deprecated)</sup> | 4 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示蓝牙正在打开LE-only模式。<br/> |  
| STATE_BLE_ON<sup>(deprecated)</sup> | 5 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示蓝牙正处于LE-only模式。<br/> |  
| STATE_BLE_TURNING_OFF<sup>(deprecated)</sup> | 6 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示蓝牙正在关闭LE-only模式。 |  
    
## SppType<sup>(deprecated)</sup>    
枚举，Spp链路类型。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.SppType替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SPP_RFCOMM<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示rfcomm链路类型。<br/> |  
    
## ScanMode<sup>(deprecated)</sup>    
枚举，扫描模式。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.ScanMode替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SCAN_MODE_NONE<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。<br>没有扫描模式。<br/> |  
| SCAN_MODE_CONNECTABLE<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。<br>可连接扫描模式。<br/> |  
| SCAN_MODE_GENERAL_DISCOVERABLE<sup>(deprecated)</sup> | 2 | 从API version 8 开始支持，从API version 9 开始废弃。<br>general发现模式。<br/> |  
| SCAN_MODE_LIMITED_DISCOVERABLE<sup>(deprecated)</sup> | 3 | 从API version 8 开始支持，从API version 9 开始废弃。<br>limited发现模式。<br/> |  
| SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE<sup>(deprecated)</sup> | 4 | 从API version 8 开始支持，从API version 9 开始废弃。<br>可连接general发现模式。<br/> |  
| SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE<sup>(deprecated)</sup> | 5 | 从API version 8 开始支持，从API version 9 开始废弃。<br>可连接limited发现模式。 |  
    
## BondState<sup>(deprecated)</sup>    
枚举，配对状态。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.BondState替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| BOND_STATE_INVALID<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。<br>无效的配对。<br/> |  
| BOND_STATE_BONDING<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。<br>正在配对。<br/> |  
| BOND_STATE_BONDED<sup>(deprecated)</sup> | 2 | 从API version 8 开始支持，从API version 9 开始废弃。<br>已配对。<br/> |  
    
## MajorClass<sup>(deprecated)</sup>    
枚举，蓝牙设备主要类别。  
    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.MajorClass替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MAJOR_MISC<sup>(deprecated)</sup> | 0x0000 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示杂项设备。<br/> |  
| MAJOR_COMPUTER<sup>(deprecated)</sup> | 0x0100 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示计算机设备。<br/> |  
| MAJOR_PHONE<sup>(deprecated)</sup> | 0x0200 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示手机设备。<br/> |  
| MAJOR_NETWORKING<sup>(deprecated)</sup> | 0x0300 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示网络设备。<br/> |  
| MAJOR_AUDIO_VIDEO<sup>(deprecated)</sup> | 0x0400 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示音频和视频设备。<br/> |  
| MAJOR_PERIPHERAL<sup>(deprecated)</sup> | 0x0500 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示外围设备。<br/> |  
| MAJOR_IMAGING<sup>(deprecated)</sup> | 0x0600 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示成像设备。<br/> |  
| MAJOR_WEARABLE<sup>(deprecated)</sup> | 0x0700 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示可穿戴设备。<br/> |  
| MAJOR_TOY<sup>(deprecated)</sup> | 0x0800 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示玩具设备。<br/> |  
| MAJOR_HEALTH<sup>(deprecated)</sup> | 0x0900 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示健康设备。<br/> |  
| MAJOR_UNCATEGORIZED<sup>(deprecated)</sup> | 0x1F00 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示未分类设备。 |  
    
## MajorMinorClass<sup>(deprecated)</sup>    
枚举，主要次要蓝牙设备类别。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.MajorMinorClass替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| COMPUTER_UNCATEGORIZED<sup>(deprecated)</sup> | 0x0100 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示未分类计算机设备。<br/> |  
| COMPUTER_DESKTOP<sup>(deprecated)</sup> | 0x0104 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示台式计算机设备。<br/> |  
| COMPUTER_SERVER<sup>(deprecated)</sup> | 0x0108 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示服务器设备。<br/> |  
| COMPUTER_LAPTOP<sup>(deprecated)</sup> | 0x010C | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示便携式计算机设备。<br/> |  
| COMPUTER_HANDHELD_PC_PDA<sup>(deprecated)</sup> | 0x0110 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示手持式计算机设备。<br/> |  
| COMPUTER_PALM_SIZE_PC_PDA<sup>(deprecated)</sup> | 0x0114 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示掌上电脑设备。<br/> |  
| COMPUTER_WEARABLE<sup>(deprecated)</sup> | 0x0118 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示可穿戴计算机设备。<br/> |  
| COMPUTER_TABLET<sup>(deprecated)</sup> | 0x011C | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示平板电脑设备。<br/> |  
| PHONE_UNCATEGORIZED<sup>(deprecated)</sup> | 0x0200 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示未分类手机设备。<br/> |  
| PHONE_CELLULAR<sup>(deprecated)</sup> | 0x0204 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示便携式手机设备。<br/> |  
| PHONE_CORDLESS<sup>(deprecated)</sup> | 0x0208 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示无线电话设备。<br/> |  
| PHONE_SMART<sup>(deprecated)</sup> | 0x020C | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示智能手机设备。<br/> |  
| PHONE_MODEM_OR_GATEWAY<sup>(deprecated)</sup> | 0x0210 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示调制解调器或网关手机设备。<br/> |  
| PHONE_ISDN<sup>(deprecated)</sup> | 0x0214 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示ISDN手机设备。<br/> |  
| NETWORK_FULLY_AVAILABLE<sup>(deprecated)</sup> | 0x0300 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示网络完全可用设备。<br/> |  
| NETWORK_1_TO_17_UTILIZED<sup>(deprecated)</sup> | 0x0320 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示使用网络1到17设备。<br/> |  
| NETWORK_17_TO_33_UTILIZED<sup>(deprecated)</sup> | 0x0340 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示使用网络17到33设备。<br/> |  
| NETWORK_33_TO_50_UTILIZED<sup>(deprecated)</sup> | 0x0360 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示使用网络33到50设备。<br/> |  
| NETWORK_60_TO_67_UTILIZED<sup>(deprecated)</sup> | 0x0380 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示使用网络60到67设备。<br/> |  
| NETWORK_67_TO_83_UTILIZED<sup>(deprecated)</sup> | 0x03A0 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示使用网络67到83设备。<br/> |  
| NETWORK_83_TO_99_UTILIZED<sup>(deprecated)</sup> | 0x03C0 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示使用网络83到99设备。<br/> |  
| NETWORK_NO_SERVICE<sup>(deprecated)</sup> | 0x03E0 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示网络无服务设备。<br/> |  
| AUDIO_VIDEO_UNCATEGORIZED<sup>(deprecated)</sup> | 0x0400 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示未分类音频视频设备。<br/> |  
| AUDIO_VIDEO_WEARABLE_HEADSET<sup>(deprecated)</sup> | 0x0404 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示可穿戴式音频视频设备。<br/> |  
| AUDIO_VIDEO_HANDSFREE<sup>(deprecated)</sup> | 0x0408 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示免提音频视频设备。<br/> |  
| AUDIO_VIDEO_MICROPHONE<sup>(deprecated)</sup> | 0x0410 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示麦克风音频视频设备。<br/> |  
| AUDIO_VIDEO_LOUDSPEAKER<sup>(deprecated)</sup> | 0x0414 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示扬声器音频视频设备。<br/> |  
| AUDIO_VIDEO_HEADPHONES<sup>(deprecated)</sup> | 0x0418 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示头戴式音频视频设备。<br/> |  
| AUDIO_VIDEO_PORTABLE_AUDIO<sup>(deprecated)</sup> | 0x041C | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示便携式音频视频设备。<br/> |  
| AUDIO_VIDEO_CAR_AUDIO<sup>(deprecated)</sup> | 0x0420 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示汽车音频视频设备。<br/> |  
| AUDIO_VIDEO_SET_TOP_BOX<sup>(deprecated)</sup> | 0x0424 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示机顶盒音频视频设备。<br/> |  
| AUDIO_VIDEO_HIFI_AUDIO<sup>(deprecated)</sup> | 0x0428 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示高保真音响设备。<br/> |  
| AUDIO_VIDEO_VCR<sup>(deprecated)</sup> | 0x042C | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示录像机音频视频设备。<br/> |  
| AUDIO_VIDEO_VIDEO_CAMERA<sup>(deprecated)</sup> | 0x0430 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示照相机音频视频设备。<br/> |  
| AUDIO_VIDEO_CAMCORDER<sup>(deprecated)</sup> | 0x0434 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示摄像机音频视频设备。<br/> |  
| AUDIO_VIDEO_VIDEO_MONITOR<sup>(deprecated)</sup> | 0x0438 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示监视器音频视频设备。<br/> |  
| AUDIO_VIDEO_VIDEO_DISPLAY_AND_LOUDSPEAKER<sup>(deprecated)</sup> | 0x043C | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示视频显示器和扬声器设备。<br/> |  
| AUDIO_VIDEO_VIDEO_CONFERENCING<sup>(deprecated)</sup> | 0x0440 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示音频视频会议设备。<br/> |  
| AUDIO_VIDEO_VIDEO_GAMING_TOY<sup>(deprecated)</sup> | 0x0448 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示游戏玩具音频视频设备。 |  
| PERIPHERAL_NON_KEYBOARD_NON_POINTING<sup>(deprecated)</sup> | 0x0500 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示非键盘非指向外围设备。<br/> |  
| PERIPHERAL_KEYBOARD<sup>(deprecated)</sup> | 0x0540 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示外设键盘设备。<br/> |  
| PERIPHERAL_POINTING_DEVICE<sup>(deprecated)</sup> | 0x0580 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示定点装置外围设备。<br/> |  
| PERIPHERAL_KEYBOARD_POINTING<sup>(deprecated)</sup> | 0x05C0 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示键盘指向外围设备。<br/> |  
| PERIPHERAL_UNCATEGORIZED<sup>(deprecated)</sup> | 0x0500 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示未分类外围设备。<br/> |  
| PERIPHERAL_JOYSTICK<sup>(deprecated)</sup> | 0x0504 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示周边操纵杆设备。<br/> |  
| PERIPHERAL_GAMEPAD<sup>(deprecated)</sup> | 0x0508 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示周边游戏板设备。<br/> |  
| PERIPHERAL_REMOTE_CONTROL<sup>(deprecated)</sup> | 0x05C0 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示远程控制外围设备。<br/> |  
| PERIPHERAL_SENSING_DEVICE<sup>(deprecated)</sup> | 0x0510 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示外围传感设备设备。<br/> |  
| PERIPHERAL_DIGITIZER_TABLET<sup>(deprecated)</sup> | 0x0514 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示外围数字化仪平板电脑设备。<br/> |  
| PERIPHERAL_CARD_READER<sup>(deprecated)</sup> | 0x0518 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示外围读卡器设备。<br/> |  
| PERIPHERAL_DIGITAL_PEN<sup>(deprecated)</sup> | 0x051C | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示外设数码笔设备。<br/> |  
| PERIPHERAL_SCANNER_RFID<sup>(deprecated)</sup> | 0x0520 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示射频识别扫描仪外围设备。<br/> |  
| PERIPHERAL_GESTURAL_INPUT<sup>(deprecated)</sup> | 0x0522 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示手势输入外围设备。<br/> |  
| IMAGING_UNCATEGORIZED<sup>(deprecated)</sup> | 0x0600 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示未分类的图像设备。 |  
| IMAGING_DISPLAY<sup>(deprecated)</sup> | 0x0610 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示图像显示设备。 |  
| IMAGING_CAMERA<sup>(deprecated)</sup> | 0x0620 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示成像照相机设备。<br/> |  
| IMAGING_SCANNER<sup>(deprecated)</sup> | 0x0640 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示成像扫描仪设备。<br/> |  
| IMAGING_PRINTER<sup>(deprecated)</sup> | 0x0680 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示成像打印机设备。<br/> |  
| WEARABLE_UNCATEGORIZED<sup>(deprecated)</sup> | 0x0700 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示未分类的可穿戴设备。<br/> |  
| WEARABLE_WRIST_WATCH<sup>(deprecated)</sup> | 0x0704 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示可穿戴腕表设备。<br/> |  
| WEARABLE_PAGER<sup>(deprecated)</sup> | 0x0708 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示可穿戴寻呼机设备。<br/> |  
| WEARABLE_JACKET<sup>(deprecated)</sup> | 0x070C | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示夹克可穿戴设备。<br/> |  
| WEARABLE_HELMET<sup>(deprecated)</sup> | 0x0710 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示可穿戴头盔设备。<br/> |  
| WEARABLE_GLASSES<sup>(deprecated)</sup> | 0x0714 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示可穿戴眼镜设备。<br/> |  
| TOY_UNCATEGORIZED<sup>(deprecated)</sup> | 0x0800 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示未分类的玩具设备。<br/> |  
| TOY_ROBOT<sup>(deprecated)</sup> | 0x0804 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示玩具机器人设备。<br/> |  
| TOY_VEHICLE<sup>(deprecated)</sup> | 0x0808 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示玩具车设备。<br/> |  
| TOY_DOLL_ACTION_FIGURE<sup>(deprecated)</sup> | 0x080C | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示人形娃娃玩具设备。<br/> |  
| TOY_CONTROLLER<sup>(deprecated)</sup> | 0x0810 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示玩具控制器设备。<br/> |  
| TOY_GAME<sup>(deprecated)</sup> | 0x0814 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示玩具游戏设备。<br/> |  
| HEALTH_UNCATEGORIZED<sup>(deprecated)</sup> | 0x0900 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示未分类健康设备。<br/> |  
| HEALTH_BLOOD_PRESSURE<sup>(deprecated)</sup> | 0x0904 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示血压健康设备。<br/> |  
| HEALTH_THERMOMETER<sup>(deprecated)</sup> | 0x0908 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示温度计健康设备。<br/> |  
| HEALTH_WEIGHING<sup>(deprecated)</sup> | 0x090C | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示体重健康设备。<br/> |  
| HEALTH_GLUCOSE<sup>(deprecated)</sup> | 0x0910 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示葡萄糖健康设备。<br/> |  
| HEALTH_PULSE_OXIMETER<sup>(deprecated)</sup> | 0x0914 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示脉搏血氧仪健康设备。<br/> |  
| HEALTH_PULSE_RATE<sup>(deprecated)</sup> | 0x0918 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示脉搏率健康设备。<br/> |  
| HEALTH_DATA_DISPLAY<sup>(deprecated)</sup> | 0x091C | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示数据显示健康设备。<br/> |  
| HEALTH_STEP_COUNTER<sup>(deprecated)</sup> | 0x0920 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示阶梯计数器健康设备。<br/> |  
| HEALTH_BODY_COMPOSITION_ANALYZER<sup>(deprecated)</sup> | 0x0924 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示身体成分分析仪健康设备。<br/> |  
| HEALTH_PEAK_FLOW_MOITOR<sup>(deprecated)</sup> | 0x0928 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示湿度计健康设备。<br/> |  
| HEALTH_MEDICATION_MONITOR<sup>(deprecated)</sup> | 0x092C | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示药物监视仪健康设备。<br/> |  
| HEALTH_KNEE_PROSTHESIS<sup>(deprecated)</sup> | 0x0930 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示膝盖假肢健康设备。<br/> |  
| HEALTH_ANKLE_PROSTHESIS<sup>(deprecated)</sup> | 0x0934 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示脚踝假肢健康设备。<br/> |  
| HEALTH_GENERIC_HEALTH_MANAGER<sup>(deprecated)</sup> | 0x0938 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示通用健康管理设备。<br/> |  
| HEALTH_PERSONAL_MOBILITY_DEVICE<sup>(deprecated)</sup> | 0x093C | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示个人移动健康设备。 |  
    
## StateChangeParam<sup>(deprecated)</sup>    
描述profile状态改变参数。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.StateChangeParam替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示蓝牙设备地址。<br/> |  
| state<sup>(deprecated)</sup> | ProfileConnectionState | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示蓝牙设备的profile连接状态。<br/> |  
    
## PlayingState<sup>(deprecated)</sup>    
枚举，蓝牙A2DP 播放状态。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.PlayingState替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STATE_NOT_PLAYING<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示未播放。<br/> |  
| STATE_PLAYING<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示正在播放。<br/> |  
    
## ProfileId<sup>(deprecated)</sup>    
蓝牙profile枚举，API9新增PROFILE_HID_HOST，PROFILE_PAN_NETWORK。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.bluetoothManager/bluetoothManager.ProfileId替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PROFILE_A2DP_SOURCE<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示A2DP profile。<br/> |  
| PROFILE_HANDS_FREE_AUDIO_GATEWAY<sup>(deprecated)</sup> | 4 | 从API version 8 开始支持，从API version 9 开始废弃。<br>表示HFP profile。 |  
