# @ohos.bluetoothManager    
蓝牙模块提供了基础的传统蓝牙能力以及BLE的扫描、广播等功能。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import bluetoothManager from '@ohos.bluetoothManager'    
```  
    
## getState<sup>(deprecated)</sup>    
获取蓝牙开关状态。  
 **调用形式：**     
- getState(): BluetoothState  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.access/access#getState。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| BluetoothState | 表示蓝牙开关状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900099 | Operation failed |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let state: bluetoothManager.BluetoothState = bluetoothManager.getState();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## getState<sup>(deprecated)</sup>  
 **调用形式：**     
- getState(): BluetoothState  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.access/access#getState。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| BluetoothState |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900099 |  |  
    
## getBtConnectionState<sup>(deprecated)</sup>    
  获取蓝牙本端的Profile连接状态，例如：任意一个支持的Profile连接状态为已连接，则此接口返回状态为已连接。  
 **调用形式：**     
- getBtConnectionState(): ProfileConnectionState  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#getProfileConnectionState。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ProfileConnectionState | 表示蓝牙设备的Profile连接状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let connectionState: bluetoothManager.ProfileConnectionState = bluetoothManager.getBtConnectionState();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## getBtConnectionState<sup>(deprecated)</sup>  
 **调用形式：**     
- getBtConnectionState(): ProfileConnectionState  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#getProfileConnectionState。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ProfileConnectionState |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
## pairDevice<sup>(deprecated)</sup>    
发起蓝牙配对。  
 **调用形式：**     
- pairDevice(deviceId: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#pairDevice。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    // 实际的地址可由扫描流程获取  
    bluetoothManager.pairDevice("XX:XX:XX:XX:XX:XX");  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## pairDevice<sup>(deprecated)</sup>  
 **调用形式：**     
- pairDevice(deviceId: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#pairDevice。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
## getRemoteDeviceName<sup>(deprecated)</sup>    
获取对端蓝牙设备的名称。  
 **调用形式：**     
- getRemoteDeviceName(deviceId: string): string  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#getRemoteDeviceName。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 表示要删除的远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 以字符串格式返回设备名称。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let remoteDeviceName: string = bluetoothManager.getRemoteDeviceName("XX:XX:XX:XX:XX:XX");  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## getRemoteDeviceName<sup>(deprecated)</sup>  
 **调用形式：**     
- getRemoteDeviceName(deviceId: string): string  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#getRemoteDeviceName。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
## getRemoteDeviceClass<sup>(deprecated)</sup>    
获取对端蓝牙设备的类别。  
 **调用形式：**     
- getRemoteDeviceClass(deviceId: string): DeviceClass  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#getRemoteDeviceClass。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 表示要删除的远程设备的地址，例如："XX:XX:XX:XX:XX:XX"。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DeviceClass | 远程设备的类别。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let remoteDeviceClass: bluetoothManager.DeviceClass  = bluetoothManager.getRemoteDeviceClass("XX:XX:XX:XX:XX:XX");  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## getRemoteDeviceClass<sup>(deprecated)</sup>  
 **调用形式：**     
- getRemoteDeviceClass(deviceId: string): DeviceClass  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#getRemoteDeviceClass。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DeviceClass |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
## enableBluetooth<sup>(deprecated)</sup>    
开启蓝牙。  
 **调用形式：**     
- enableBluetooth(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.access/access#enableBluetooth。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    bluetoothManager.enableBluetooth();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## enableBluetooth<sup>(deprecated)</sup>  
 **调用形式：**     
- enableBluetooth(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.access/access#enableBluetooth。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900099 |  |  
    
## disableBluetooth<sup>(deprecated)</sup>    
关闭蓝牙。  
 **调用形式：**     
- disableBluetooth(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.access/access#disableBluetooth。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    bluetoothManager.disableBluetooth();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ", errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## disableBluetooth<sup>(deprecated)</sup>  
 **调用形式：**     
- disableBluetooth(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.access/access#disableBluetooth。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900099 |  |  
    
## getLocalName<sup>(deprecated)</sup>    
获取蓝牙本地设备名称。  
 **调用形式：**     
- getLocalName(): string  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#getLocalName。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 蓝牙本地设备名称。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```null    
import { BusinessError } from '@ohos.base';  
try {  
    let localName: string = bluetoothManager.getLocalName();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## getLocalName<sup>(deprecated)</sup>  
 **调用形式：**     
- getLocalName(): string  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#getLocalName。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900099 |  |  
    
## getPairedDevices<sup>(deprecated)</sup>    
获取蓝牙配对列表。  
 **调用形式：**     
- getPairedDevices(): Array\<string>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#getPairedDevices。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 已配对蓝牙设备的地址列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let devices: Array<string> = bluetoothManager.getPairedDevices();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## getPairedDevices<sup>(deprecated)</sup>  
 **调用形式：**     
- getPairedDevices(): Array\<string>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#getPairedDevices。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
## getProfileConnectionState<sup>(deprecated)</sup>    
获取蓝牙本端的Profile连接状态，例如：任意一个支持的Profile连接状态为已连接，则此接口返回状态为已连接。  
 **调用形式：**     
- getProfileConnectionState(profileId: ProfileId): ProfileConnectionState  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#getProfileConnectionState。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| profileId<sup>(deprecated)</sup> | ProfileId | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ProfileConnectionState | 表示蓝牙设备的Profile连接状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Service stopped. |  
| 2900004 |  |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let connectionState: bluetoothManager.ProfileConnectionState = bluetoothManager.getBtConnectionState();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## getProfileConnectionState<sup>(deprecated)</sup>  
 **调用形式：**     
- getProfileConnectionState(profileId: ProfileId): ProfileConnectionState  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#getProfileConnectionState。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| profileId<sup>(deprecated)</sup> | ProfileId | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ProfileConnectionState |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900004 |  |  
| 2900099 |  |  
    
## setDevicePairingConfirmation<sup>(deprecated)</sup>    
设置设备配对请求确认。  
 **调用形式：**     
- setDevicePairingConfirmation(device: string, accept: boolean): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#setDevicePairingConfirmation。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.MANAGE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 表示远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |  
| accept<sup>(deprecated)</sup> | boolean | true | 接受配对请求设置为true，否则设置为false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
// 订阅“pinRequired”配对请求事件，收到远端配对请求后设置配对确认  
function onReceivePinRequiredEvent(data: bluetoothManager.PinRequiredParam) { // data为配对请求的入参，配对请求参数  
    console.info('pin required  = '+ JSON.stringify(data));  
    bluetoothManager.setDevicePairingConfirmation(data.deviceId, true);  
}  
try {  
    bluetoothManager.on("pinRequired", onReceivePinRequiredEvent);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## setDevicePairingConfirmation<sup>(deprecated)</sup>  
 **调用形式：**     
- setDevicePairingConfirmation(device: string, accept: boolean): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#setDevicePairingConfirmation。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true |  |  
| accept<sup>(deprecated)</sup> | boolean | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
## setLocalName<sup>(deprecated)</sup>    
设置蓝牙本地设备名称。  
 **调用形式：**     
- setLocalName(name: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#setLocalName。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 要设置的蓝牙名称，最大长度为248字节数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    bluetoothManager.setLocalName('device_name');  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## setLocalName<sup>(deprecated)</sup>  
 **调用形式：**     
- setLocalName(name: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#setLocalName。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
## setBluetoothScanMode<sup>(deprecated)</sup>    
设置蓝牙扫描模式，可以被远端设备发现。  
 **调用形式：**     
- setBluetoothScanMode(mode: ScanMode, duration: number): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#setBluetoothScanMode。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode<sup>(deprecated)</sup> | ScanMode | true | 蓝牙扫描模式。 |  
| duration<sup>(deprecated)</sup> | number | true | 设备可被发现的持续时间，单位为毫秒；设置为0则持续可发现。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    // 设置为可连接可发现才可被远端设备扫描到，可以连接。  
    bluetoothManager.setBluetoothScanMode(bluetoothManager.ScanMode.SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE, 100);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## setBluetoothScanMode<sup>(deprecated)</sup>  
 **调用形式：**     
- setBluetoothScanMode(mode: ScanMode, duration: number): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#setBluetoothScanMode。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode<sup>(deprecated)</sup> | ScanMode | true |  |  
| duration<sup>(deprecated)</sup> | number | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
## getBluetoothScanMode<sup>(deprecated)</sup>    
获取蓝牙扫描模式。  
 **调用形式：**     
- getBluetoothScanMode(): ScanMode  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#getBluetoothScanMode。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ScanMode | 蓝牙扫描模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```null    
import { BusinessError } from '@ohos.base';  
try {  
    let scanMode: bluetoothManager.ScanMode = bluetoothManager.getBluetoothScanMode();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## getBluetoothScanMode<sup>(deprecated)</sup>  
 **调用形式：**     
- getBluetoothScanMode(): ScanMode  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#getBluetoothScanMode。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ScanMode |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
## startBluetoothDiscovery<sup>(deprecated)</sup>    
开启蓝牙扫描，可以发现远端设备。  
 **调用形式：**     
- startBluetoothDiscovery(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#startBluetoothDiscovery。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```null    
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
  
    
## startBluetoothDiscovery<sup>(deprecated)</sup>  
 **调用形式：**     
- startBluetoothDiscovery(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#startBluetoothDiscovery。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
## stopBluetoothDiscovery<sup>(deprecated)</sup>    
关闭蓝牙扫描。  
 **调用形式：**     
- stopBluetoothDiscovery(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#stopBluetoothDiscovery。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    bluetoothManager.stopBluetoothDiscovery();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## stopBluetoothDiscovery<sup>(deprecated)</sup>  
 **调用形式：**     
- stopBluetoothDiscovery(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#stopBluetoothDiscovery。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
## on('bluetoothDeviceFind')<sup>(deprecated)</sup>    
订阅蓝牙设备发现上报事件。  
 **调用形式：**     
- on(type: 'bluetoothDeviceFind', callback: Callback\<Array\<string>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection.on#event:bluetoothDeviceFind。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"bluetoothDeviceFind"字符串，表示蓝牙设备发现事件。 |  
| callback<sup>(deprecated)</sup> | Callback<Array<string>> | true | 表示回调函数的入参，发现的设备集合。回调函数由用户创建通过该接口注册。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
function onReceiveEvent(data: Array<string>) { // data为蓝牙设备地址集合  
    console.info('bluetooth device find = '+ JSON.stringify(data));  
}  
try {  
    bluetoothManager.on('bluetoothDeviceFind', onReceiveEvent);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## on('bluetoothDeviceFind')<sup>(deprecated)</sup>  
 **调用形式：**     
- on(type: 'bluetoothDeviceFind', callback: Callback\<Array\<string>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection.on#event:bluetoothDeviceFind。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<Array<string>> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 |  |  
    
## off('bluetoothDeviceFind')<sup>(deprecated)</sup>    
取消订阅蓝牙设备发现上报事件。  
 **调用形式：**     
- off(type: 'bluetoothDeviceFind', callback?: Callback\<Array\<string>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection.off#event:bluetoothDeviceFind。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"bluetoothDeviceFind"字符串，表示蓝牙设备发现事件。 |  
| callback<sup>(deprecated)</sup> | Callback<Array<string>> | false | 表示取消订阅蓝牙设备发现事件上报。不填该参数则取消订阅该type对应的所有回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
## off('bluetoothDeviceFind')<sup>(deprecated)</sup>  
 **调用形式：**     
- off(type: 'bluetoothDeviceFind', callback?: Callback\<Array\<string>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection.off#event:bluetoothDeviceFind。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<Array<string>> | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900099 |  |  
    
## on('bondStateChange')<sup>(deprecated)</sup>    
订阅蓝牙配对状态改变事件。  
 **调用形式：**     
- on(type: 'bondStateChange', callback: Callback\<BondStateParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection.on#event:bondStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"bluetoothDeviceFind"字符串，表示蓝牙设备发现事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<BondStateParam> | true | 表示取消订阅蓝牙设备发现事件上报。不填该参数则取消订阅该type对应的所有回调。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
function onReceiveEvent(data: bluetoothManager.BondStateParam) { // data为回调函数入参，表示配对的状态  
    console.info('pair state = '+ JSON.stringify(data));  
}  
try {  
    bluetoothManager.on('bondStateChange', onReceiveEvent);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## on('bondStateChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- on(type: 'bondStateChange', callback: Callback\<BondStateParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection.on#event:bondStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<BondStateParam> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 |  |  
    
## off('bondStateChange')<sup>(deprecated)</sup>    
取消订阅蓝牙配对状态改变事件。  
 **调用形式：**     
- off(type: 'bondStateChange', callback?: Callback\<BondStateParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection.off#event:bondStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"bluetoothDeviceFind"字符串，表示蓝牙设备发现事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<BondStateParam> | false | 表示取消订阅蓝牙设备发现事件上报。不填该参数则取消订阅该type对应的所有回调。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
## off('bondStateChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- off(type: 'bondStateChange', callback?: Callback\<BondStateParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection.off#event:bondStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<BondStateParam> | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 |  |  
    
## on('pinRequired')<sup>(deprecated)</sup>    
订阅远端蓝牙设备的配对请求事件。  
 **调用形式：**     
- on(type: 'pinRequired', callback: Callback\<PinRequiredParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection.on#event:pinRequired。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"bluetoothDeviceFind"字符串，表示蓝牙设备发现事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<PinRequiredParam> | true | 表示取消订阅蓝牙设备发现事件上报。不填该参数则取消订阅该type对应的所有回调。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
function onReceiveEvent(data: bluetoothManager.PinRequiredParam) { // data为配对请求参数  
    console.info('pin required = '+ JSON.stringify(data));  
}  
try {  
    bluetoothManager.on('pinRequired', onReceiveEvent);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## on('pinRequired')<sup>(deprecated)</sup>  
 **调用形式：**     
- on(type: 'pinRequired', callback: Callback\<PinRequiredParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection.on#event:pinRequired。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<PinRequiredParam> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 |  |  
    
## off('pinRequired')<sup>(deprecated)</sup>    
示例（callback）：。  
 **调用形式：**     
- off(type: 'pinRequired', callback?: Callback\<PinRequiredParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection.off#event:pinRequired。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"bluetoothDeviceFind"字符串，表示蓝牙设备发现事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<PinRequiredParam> | false | 表示取消订阅蓝牙设备发现事件上报。不填该参数则取消订阅该type对应的所有回调。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 | Operation failed. |  
    
## off('pinRequired')<sup>(deprecated)</sup>  
 **调用形式：**     
- off(type: 'pinRequired', callback?: Callback\<PinRequiredParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection.off#event:pinRequired。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<PinRequiredParam> | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 |  |  
    
## on('stateChange')<sup>(deprecated)</sup>    
订阅蓝牙设备开关状态事件。  
 **调用形式：**     
- on(type: 'stateChange', callback: Callback\<BluetoothState>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.access/access.on#event:stateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"bluetoothDeviceFind"字符串，表示蓝牙设备发现事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<BluetoothState> | true | 表示取消订阅蓝牙设备发现事件上报。不填该参数则取消订阅该type对应的所有回调。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
## on('stateChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- on(type: 'stateChange', callback: Callback\<BluetoothState>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.access/access.on#event:stateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<BluetoothState> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 |  |  
    
## off('stateChange')<sup>(deprecated)</sup>    
取消订阅蓝牙设备开关状态事件。  
 **调用形式：**     
- off(type: 'stateChange', callback?: Callback\<BluetoothState>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.access/access.off#event:stateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"bluetoothDeviceFind"字符串，表示蓝牙设备发现事件。<br/> |  
| callback<sup>(deprecated)</sup> | Callback<BluetoothState> | false | 表示取消订阅蓝牙状态改变事件上报。不填该参数则取消订阅该type对应的所有回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
## off('stateChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- off(type: 'stateChange', callback?: Callback\<BluetoothState>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.access/access.off#event:stateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<BluetoothState> | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 |  |  
    
## sppListen<sup>(deprecated)</sup>    
创建一个服务端监听Socket。  
 **调用形式：**     
- sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.socket/socket#sppListen。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 服务的名称。 |  
| option<sup>(deprecated)</sup> | SppOption | true | spp监听配置参数。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 表示回调函数的入参，服务端Socket的id。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900004 |  |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
## sppListen<sup>(deprecated)</sup>  
 **调用形式：**     
- sppListen(name: string, option: SppOption, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.socket/socket#sppListen。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true |  |  
| option<sup>(deprecated)</sup> | SppOption | true |  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900004 |  |  
| 2900099 |  |  
    
## sppAccept<sup>(deprecated)</sup>    
服务端监听socket等待客户端连接。  
 **调用形式：**     
- sppAccept(serverSocket: number, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.socket/socket#sppAccept。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| serverSocket<sup>(deprecated)</sup> | number | true | 服务端socket的id。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 表示回调函数的入参，客户端socket的id。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900004 |  |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
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
    // 获取的clientNumber用作服务端后续读/写操作socket的id。  
    clientNumber = number;  
  }  
}  
try {  
    bluetoothManager.sppAccept(serverNumber, acceptClientSocket);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## sppConnect<sup>(deprecated)</sup>    
客户端向远端设备发起spp连接。  
 **调用形式：**     
- sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.socket/socket#sppConnect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 对端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |  
| option<sup>(deprecated)</sup> | SppOption | true | spp客户端连接配置参数。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 表示回调函数的入参，客户端socket的id。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 |  |  
| 2900004 | Profile is not supported. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
  
let clientNumber = -1;  
function clientSocket(code: BusinessError, number: number) {  
  if (code.code != 0 || code == null) {  
    return;  
  }  
  console.log('bluetooth serverSocket Number: ' + number);  
  // 获取的clientNumber用作客户端后续读/写操作socket的id。  
  clientNumber = number;  
}  
let sppOption: bluetoothManager.SppOption = {uuid: '00001810-0000-1000-8000-00805F9B34FB', secure: false, type: 0};  
try {  
    bluetoothManager.sppConnect('XX:XX:XX:XX:XX:XX', sppOption, clientSocket);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## sppConnect<sup>(deprecated)</sup>  
 **调用形式：**     
- sppConnect(device: string, option: SppOption, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.socket/socket#sppConnect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true |  |  
| option<sup>(deprecated)</sup> | SppOption | true |  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900004 | Profile is not supported. |  
| 2900099 | Operation failed. |  
    
## sppCloseServerSocket<sup>(deprecated)</sup>    
关闭服务端监听Socket，入参socket由sppListen接口返回。  
 **调用形式：**     
- sppCloseServerSocket(socket: number): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.socket/socket#sppCloseServerSocket。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| socket<sup>(deprecated)</sup> | number | true | 服务端监听socket的id。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
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
  
    
## sppCloseClientSocket<sup>(deprecated)</sup>  
 **调用形式：**     
- sppCloseClientSocket(socket: number): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.socket/socket#sppCloseClientSocket。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| socket<sup>(deprecated)</sup> | number | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900099 |  |  
    
## sppWrite<sup>(deprecated)</sup>    
通过socket向远端发送数据，入参clientSocket由sppAccept或sppConnect接口获取。  
 **调用形式：**     
- sppWrite(clientSocket: number, data: ArrayBuffer): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.socket/socket#sppWrite。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| clientSocket<sup>(deprecated)</sup> | number | true | 客户端socket的id。 |  
| data<sup>(deprecated)</sup> | ArrayBuffer | true | 写入的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 2901054 | IO error. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
let clientNumber = -1;  
function clientSocket(code: BusinessError, number: number) {  
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
try {  
    bluetoothManager.sppWrite(clientNumber, arrayBuffer);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## on('sppRead')<sup>(deprecated)</sup>    
订阅spp读请求事件，入参clientSocket由sppAccept或sppConnect接口获取。  
 **调用形式：**     
- on(type: 'sppRead', clientSocket: number, callback: Callback\<ArrayBuffer>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.socket/socket.on#event:sppRead。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"sppRead"字符串，表示spp读请求事件。 |  
| clientSocket<sup>(deprecated)</sup> | number | true | 客户端socket的id。 |  
| callback<sup>(deprecated)</sup> | Callback<ArrayBuffer> | true | 表示回调函数的入参，读取到的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 2901054 | IO error. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
let clientNumber = -1;  
function clientSocket(code: BusinessError, number: number) {  
  if (code.code != 0 || code == null) {  
    return;  
  }  
  console.log('bluetooth serverSocket Number: ' + number);  
  // 获取的clientNumber用作客户端后续读/写操作socket的id。  
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
  
    
## off('sppRead')<sup>(deprecated)</sup>    
取消订阅spp读请求事件，入参clientSocket由sppAccept或sppConnect接口获取。  
 **调用形式：**     
- off(type: 'sppRead', clientSocket: number, callback?: Callback\<ArrayBuffer>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.socket/socket.off#event:sppRead。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"sppRead"字符串，表示spp读请求事件。 |  
| clientSocket<sup>(deprecated)</sup> | number | true | 客户端Socket的id。 |  
| callback<sup>(deprecated)</sup> | Callback<ArrayBuffer> | false | 表示取消订阅spp读请求事件上报。不填该参数则取消订阅该type对应的所有回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
let clientNumber = -1;  
function clientSocket(code: BusinessError, number: number) {  
  if (code.code != 0 || code == null) {  
    return;  
  }  
  console.log('bluetooth serverSocket Number: ' + number);  
  // 获取的clientNumber用作客户端后续读/写操作socket的id。  
  clientNumber = number;  
}  
try {  
    bluetoothManager.off('sppRead', clientNumber);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## getProfileInstance<sup>(deprecated)</sup>    
通过ProfileId，获取profile的对象实例，API9新增了HidHostProfile，PanProfile。  
 **调用形式：**     
- getProfileInstance(    profileId: ProfileId  ): A2dpSourceProfile | HandsFreeAudioGatewayProfile | HidHostProfile | PanProfile  
  
 **废弃说明：** 从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| profileId<sup>(deprecated)</sup> | ProfileId | true | 表示profile的枚举值，例如：PROFILE_A2DP_SOURCE。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| A2dpSourceProfile | HandsFreeAudioGatewayProfile | HidHostProfile | PanProfile | 对应的profile的对象实例，当前支持A2dpSourceProfile/HandsFreeAudioGatewayProfile/HidHostProfile/PanProfile。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let hidHost: bluetoothManager.HidHostProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_HID_HOST);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## BaseProfile<sup>(deprecated)</sup>    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.baseProfile/baseProfile.BaseProfile替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### getConnectionDevices<sup>(deprecated)</sup>    
获取已连接设备列表。  
 **调用形式：**     
- getConnectionDevices(): Array\<string>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.baseProfile/baseProfile#getConnectedDevices。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 返回已连接设备的地址列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900004 | Profile is not supported. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let a2dpSrc: bluetoothManager.A2dpSourceProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_A2DP_SOURCE) as bluetoothManager.A2dpSourceProfile;  
    let retArray: Array<string> = a2dpSrc.getConnectionDevices();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### getConnectionDevices<sup>(deprecated)</sup>  
 **调用形式：**     
- getConnectionDevices(): Array\<string>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.baseProfile/baseProfile#getConnectedDevices。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900004 |  |  
| 2900099 |  |  
    
### getDeviceState<sup>(deprecated)</sup>    
获取设备profile的连接状态。  
 **调用形式：**     
- getDeviceState(device: string): ProfileConnectionState  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.baseProfile/baseProfile#getConnectionState。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 远端设备地址。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ProfileConnectionState | 返回profile的连接状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900004 | Profile is not supported. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
    try {  
        let a2dpSrc: bluetoothManager.A2dpSourceProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_A2DP_SOURCE) as bluetoothManager.A2dpSourceProfile;  
        let ret: bluetoothManager.ProfileConnectionState = a2dpSrc.getDeviceState('XX:XX:XX:XX:XX:XX');  
    } catch (err) {  
        console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
    }  
    
```    
  
    
### getDeviceState<sup>(deprecated)</sup>  
 **调用形式：**     
- getDeviceState(device: string): ProfileConnectionState  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.baseProfile/baseProfile#getConnectionState。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ProfileConnectionState |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900004 |  |  
| 2900099 |  |  
    
## A2dpSourceProfile<sup>(deprecated)</sup>    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.a2dp/a2dp.A2dpSourceProfile替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### connect<sup>(deprecated)</sup>    
发起设备的A2dp服务连接请求。  
 **调用形式：**     
- connect(device: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.a2dp/a2dp.A2dpSourceProfile#connect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 远端设备地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900004 | Profile is not supported. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let a2dpSrc: bluetoothManager.A2dpSourceProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_A2DP_SOURCE) as bluetoothManager.A2dpSourceProfile;  
    a2dpSrc.connect('XX:XX:XX:XX:XX:XX');  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### connect<sup>(deprecated)</sup>  
 **调用形式：**     
- connect(device: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.a2dp/a2dp.A2dpSourceProfile#connect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900004 |  |  
| 2900099 |  |  
    
### disconnect<sup>(deprecated)</sup>    
断开设备的a2dp服务连接。  
 **调用形式：**     
- disconnect(device: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.a2dp/a2dp.A2dpSourceProfile#disconnect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 远端设备地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900004 | Profile is not supported. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let a2dpSrc: bluetoothManager.A2dpSourceProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_A2DP_SOURCE) as bluetoothManager.A2dpSourceProfile;  
    a2dpSrc.disconnect('XX:XX:XX:XX:XX:XX');  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### disconnect<sup>(deprecated)</sup>  
 **调用形式：**     
- disconnect(device: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.a2dp/a2dp.A2dpSourceProfile#disconnect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900004 |  |  
| 2900099 |  |  
    
### on('connectionStateChange')<sup>(deprecated)</sup>    
订阅a2dp连接状态变化事件。  
 **调用形式：**     
- on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.a2dp/a2dp.A2dpSourceProfile.on#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"connectionStateChange"字符串，表示连接状态变化事件。 |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | true | 表示回调函数的入参。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
### on('connectionStateChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.a2dp/a2dp.A2dpSourceProfile.on#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
### off('connectionStateChange')<sup>(deprecated)</sup>    
取消订阅a2dp连接状态变化事件。  
 **调用形式：**     
- off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.a2dp/a2dp.A2dpSourceProfile.off#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"connectionStateChange"字符串，表示连接状态变化事件。 |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | false | 表示回调函数的入参。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
```null    
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
  
    
### off('connectionStateChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.a2dp/a2dp.A2dpSourceProfile.off#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
### getPlayingState<sup>(deprecated)</sup>    
获取设备的播放状态。  
 **调用形式：**     
- getPlayingState(device: string): PlayingState  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.a2dp/a2dp.A2dpSourceProfile#getPlayingState。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 远端设备地址。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PlayingState | 远端设备的播放状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900004 | Profile is not supported. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let a2dpSrc: bluetoothManager.A2dpSourceProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_A2DP_SOURCE) as bluetoothManager.A2dpSourceProfile;  
    let state: bluetoothManager.PlayingState  = a2dpSrc.getPlayingState('XX:XX:XX:XX:XX:XX');  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### getPlayingState<sup>(deprecated)</sup>  
 **调用形式：**     
- getPlayingState(device: string): PlayingState  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.a2dp/a2dp.A2dpSourceProfile#getPlayingState。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PlayingState |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900004 |  |  
| 2900099 |  |  
    
## HandsFreeAudioGatewayProfile<sup>(deprecated)</sup>    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.hfp/hfp.HandsFreeAudioGatewayProfile替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### connect<sup>(deprecated)</sup>    
连接设备的HFP服务。  
 **调用形式：**     
- connect(device: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.hfp/hfp.HandsFreeAudioGatewayProfile#connect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 远端设备地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900004 | Profile is not supported. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let hfpAg: bluetoothManager.HandsFreeAudioGatewayProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_HANDS_FREE_AUDIO_GATEWAY) as bluetoothManager.HandsFreeAudioGatewayProfile;  
    hfpAg.connect('XX:XX:XX:XX:XX:XX');  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### connect<sup>(deprecated)</sup>  
 **调用形式：**     
- connect(device: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.hfp/hfp.HandsFreeAudioGatewayProfile#connect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900004 |  |  
| 2900099 |  |  
    
### disconnect<sup>(deprecated)</sup>    
断开连接设备的HFP服务。  
 **调用形式：**     
- disconnect(device: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.hfp/hfp.HandsFreeAudioGatewayProfile#disconnect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 远端设备地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900004 | Profile is not supported. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let hfpAg: bluetoothManager.HandsFreeAudioGatewayProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_HANDS_FREE_AUDIO_GATEWAY) as bluetoothManager.HandsFreeAudioGatewayProfile;  
    hfpAg.disconnect('XX:XX:XX:XX:XX:XX');  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### disconnect<sup>(deprecated)</sup>  
 **调用形式：**     
- disconnect(device: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.hfp/hfp.HandsFreeAudioGatewayProfile#disconnect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900004 |  |  
| 2900099 |  |  
    
### on('connectionStateChange')<sup>(deprecated)</sup>    
订阅HFP连接状态变化事件。  
 **调用形式：**     
- on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.hfp/hfp.HandsFreeAudioGatewayProfile.on#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"connectionStateChange"字符串，表示连接状态变化事件。 |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | true | 表示回调函数的入参。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
### on('connectionStateChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.hfp/hfp.HandsFreeAudioGatewayProfile.on#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
### off('connectionStateChange')<sup>(deprecated)</sup>    
  取消订阅HFP连接状态变化事件。  
 **调用形式：**     
- off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.hfp/hfp.HandsFreeAudioGatewayProfile.off#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"connectionStateChange"字符串，表示连接状态变化事件。 |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | false | 表示回调函数的入参。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
### off('connectionStateChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.hfp/hfp.HandsFreeAudioGatewayProfile.off#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
## HidHostProfile<sup>(deprecated)</sup>    
使用HidHostProfile方法之前需要创建该类的实例进行操作，通过getProfile()方法构造此实例。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.hid/hid.HidHostProfile替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### on('connectionStateChange')<sup>(deprecated)</sup>    
订阅HidHost连接状态变化事件。  
 **调用形式：**     
- on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.hid/hid.HidHostProfile.on#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"connectionStateChange"字符串，表示连接状态变化事件。 |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | true | 表示回调函数的入参。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
### on('connectionStateChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.hid/hid.HidHostProfile.on#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
### off('connectionStateChange')<sup>(deprecated)</sup>    
取消订阅HidHost连接状态变化事件。  
 **调用形式：**     
- off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.hid/hid.HidHostProfile.off#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"connectionStateChange"字符串，表示连接状态变化事件。 |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | false | 表示回调函数的入参。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
### off('connectionStateChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.hid/hid.HidHostProfile.off#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
## PanProfile<sup>(deprecated)</sup>    
使用PanProfile方法之前需要创建该类的实例进行操作，通过getProfile()方法构造此实例。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.pan/pan.PanProfile替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### on('connectionStateChange')<sup>(deprecated)</sup>    
订阅Pan连接状态变化事件。  
 **调用形式：**     
- on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.pan/pan.PanProfile.on#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"connectionStateChange"字符串，表示连接状态变化事件。 |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | true | 表示回调函数的入参。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
### on('connectionStateChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.pan/pan.PanProfile.on#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
### off('connectionStateChange')<sup>(deprecated)</sup>    
取消订阅Pan连接状态变化事件。  
 **调用形式：**     
- off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.pan/pan.PanProfile.off#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"connectionStateChange"字符串，表示连接状态变化事件。 |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | false | 表示回调函数的入参。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
### off('connectionStateChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.pan/pan.PanProfile.off#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<StateChangeParam> | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
## createGattServer<sup>(deprecated)</sup>    
创建一个可使用的GattServer实例。  
 **调用形式：**     
- createGattServer(): GattServer  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble#createGattServer。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| GattServer | server端类，使用server端方法之前需要创建该类的实例进行操作。 |  
    
## createGattClientDevice<sup>(deprecated)</sup>    
创建一个可使用的GattClientDevice实例。  
 **调用形式：**     
- createGattClientDevice(deviceId: string): GattClientDevice  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble#createGattClientDevice。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 对端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| GattClientDevice | client端类，使用client端方法之前需要创建该类的实例进行操作。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let device: bluetoothManager.GattClientDevice = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## getConnectedBLEDevices<sup>(deprecated)</sup>    
获取和当前设备连接的BLE设备。  
 **调用形式：**     
- getConnectedBLEDevices(): Array\<string>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble#getConnectedBLEDevices。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 返回当前设备作为Server端时连接BLE设备地址集合。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Profile is not supported. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let result: Array<string>  = bluetoothManager.BLE.getConnectedBLEDevices();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## getConnectedBLEDevices<sup>(deprecated)</sup>  
 **调用形式：**     
- getConnectedBLEDevices(): Array\<string>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble#getConnectedBLEDevices。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
## startBLEScan<sup>(deprecated)</sup>    
发起BLE扫描流程。  
 **调用形式：**     
- startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble#startBLEScan。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH and ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filters<sup>(deprecated)</sup> | Array<ScanFilter> | true | 表示扫描结果过滤策略集合，如果不使用过滤的方式，该参数设置为null。 |  
| options<sup>(deprecated)</sup> | ScanOptions | false | 表示扫描的参数配置，可选参数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
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
  
    
## startBLEScan<sup>(deprecated)</sup>  
 **调用形式：**     
- startBLEScan(filters: Array\<ScanFilter>, options?: ScanOptions): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble#startBLEScan。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| filters<sup>(deprecated)</sup> | Array<ScanFilter> | true |  |  
| options<sup>(deprecated)</sup> | ScanOptions | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
## stopBLEScan<sup>(deprecated)</sup>    
停止BLE扫描流程。  
 **调用形式：**     
- stopBLEScan(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble#stopBLEScan。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Profile is not supported. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    bluetoothManager.BLE.stopBLEScan();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## stopBLEScan<sup>(deprecated)</sup>  
 **调用形式：**     
- stopBLEScan(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble#stopBLEScan。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
## on('BLEDeviceFind')<sup>(deprecated)</sup>    
订阅BLE设备发现上报事件。  
 **调用形式：**     
- on(type: 'BLEDeviceFind', callback: Callback\<Array\<ScanResult>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.on#event:BLEDeviceFind。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"BLEDeviceFind"字符串，表示BLE设备发现事件。 |  
| callback<sup>(deprecated)</sup> | Callback<Array<ScanResult>> | true | 表示回调函数的入参，发现的设备集合。回调函数由用户创建通过该接口注册。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
## on('BLEDeviceFind')<sup>(deprecated)</sup>  
 **调用形式：**     
- on(type: 'BLEDeviceFind', callback: Callback\<Array\<ScanResult>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.on#event:BLEDeviceFind。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<Array<ScanResult>> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 |  |  
    
## off('BLEDeviceFind')<sup>(deprecated)</sup>    
取消订阅BLE设备发现上报事件。  
 **调用形式：**     
- off(type: 'BLEDeviceFind', callback?: Callback\<Array\<ScanResult>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.off#event:BLEDeviceFind。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"BLEDeviceFind"字符串，表示BLE设备发现事件。  |  
| callback<sup>(deprecated)</sup> | Callback<Array<ScanResult>> | false | 表示取消订阅BLE设备发现事件上报。不填该参数则取消订阅该type对应的所有回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
## off('BLEDeviceFind')<sup>(deprecated)</sup>  
 **调用形式：**     
- off(type: 'BLEDeviceFind', callback?: Callback\<Array\<ScanResult>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.off#event:BLEDeviceFind。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<Array<ScanResult>> | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 |  |  
    
## GattServer<sup>(deprecated)</sup>    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.GattServer替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### startAdvertising<sup>(deprecated)</sup>    
开始发送BLE广播。  
 **调用形式：**     
- startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble#startAdvertising。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| setting<sup>(deprecated)</sup> | AdvertiseSetting | true | BLE广播的相关参数。 |  
| advData<sup>(deprecated)</sup> | AdvertiseData | true | BLE广播包内容。 |  
| advResponse<sup>(deprecated)</sup> | AdvertiseData | false | BLE回复扫描请求回复响应。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
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
  
    
### startAdvertising<sup>(deprecated)</sup>  
 **调用形式：**     
- startAdvertising(setting: AdvertiseSetting, advData: AdvertiseData, advResponse?: AdvertiseData): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble#startAdvertising。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| setting<sup>(deprecated)</sup> | AdvertiseSetting | true |  |  
| advData<sup>(deprecated)</sup> | AdvertiseData | true |  |  
| advResponse<sup>(deprecated)</sup> | AdvertiseData | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
### stopAdvertising<sup>(deprecated)</sup>    
停止发送BLE广播。  
 **调用形式：**     
- stopAdvertising(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble#stopAdvertising。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
let server = bluetoothManager.BLE.createGattServer();  
try {  
    server.stopAdvertising();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### stopAdvertising<sup>(deprecated)</sup>  
 **调用形式：**     
- stopAdvertising(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble#stopAdvertising。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
### addService<sup>(deprecated)</sup>    
server端添加服务。  
 **调用形式：**     
- addService(service: GattService): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer#addService。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| service<sup>(deprecated)</sup> | GattService | true | 服务端的service数据。BLE广播的相关参数 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
// 创建descriptors  
let descriptors: Array<bluetoothManager.BLEDescriptor> = [];  
let arrayBuffer = new ArrayBuffer(8);  
let descV = new Uint8Array(arrayBuffer);  
descV[0] = 11;  
let descriptor: bluetoothManager.BLEDescriptor = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',  
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB',  
    descriptorUuid: '00002902-0000-1000-8000-00805F9B34FB', descriptorValue: arrayBuffer};  
descriptors[0] = descriptor;  
  
// 创建characteristics  
let characteristics: Array<bluetoothManager.BLECharacteristic> = [];  
let arrayBufferC = new ArrayBuffer(8);  
let cccV = new Uint8Array(arrayBufferC);  
cccV[0] = 1;  
let characteristic: bluetoothManager.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',  
    characteristicUuid: '00001820-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};  
let characteristicN: bluetoothManager.BLECharacteristic = {serviceUuid: '00001810-0000-1000-8000-00805F9B34FB',  
    characteristicUuid: '00001821-0000-1000-8000-00805F9B34FB', characteristicValue: arrayBufferC, descriptors:descriptors};  
characteristics[0] = characteristic;  
  
// 创建gattService  
let gattService: bluetoothManager.GattService = {serviceUuid:'00001810-0000-1000-8000-00805F9B34FB', isPrimary: true, characteristics:characteristics, includeServices:[]};  
  
let gattServer  = bluetoothManager.BLE.createGattServer();  
try {  
    gattServer.addService(gattService);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### addService<sup>(deprecated)</sup>  
 **调用形式：**     
- addService(service: GattService): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer#addService。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| service<sup>(deprecated)</sup> | GattService | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
### removeService<sup>(deprecated)</sup>    
删除已添加的服务。  
 **调用形式：**     
- removeService(serviceUuid: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer#removeService。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| serviceUuid<sup>(deprecated)</sup> | string | true | service的UUID，例如“00001810-0000-1000-8000-00805F9B34FB”。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900004 | Profile is not supported. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
let server = bluetoothManager.BLE.createGattServer();  
try {  
    server.removeService('00001810-0000-1000-8000-00805F9B34FB');  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### removeService<sup>(deprecated)</sup>  
 **调用形式：**     
- removeService(serviceUuid: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer#removeService。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| serviceUuid<sup>(deprecated)</sup> | string | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900004 |  |  
| 2900099 |  |  
    
### close<sup>(deprecated)</sup>    
关闭服务端功能，去注册server在协议栈的注册，调用该接口后[GattServer](#gattserver)实例将不能再使用。  
 **调用形式：**     
- close(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer#close。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
let server = bluetoothManager.BLE.createGattServer();  
try {  
    server.close();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### close<sup>(deprecated)</sup>  
 **调用形式：**     
- close(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer#close。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
### notifyCharacteristicChanged<sup>(deprecated)</sup>    
server端特征值发生变化时，主动通知已连接的client设备。  
 **调用形式：**     
- notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer#notifyCharacteristicChanged。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true | 接收通知的client端设备地址，例如“XX:XX:XX:XX:XX:XX”。 |  
| notifyCharacteristic<sup>(deprecated)</sup> | NotifyCharacteristic | true | 通知的特征值数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
// 创建descriptors  
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
  
    
### notifyCharacteristicChanged<sup>(deprecated)</sup>  
 **调用形式：**     
- notifyCharacteristicChanged(deviceId: string, notifyCharacteristic: NotifyCharacteristic): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer#notifyCharacteristicChanged。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true |  |  
| notifyCharacteristic<sup>(deprecated)</sup> | NotifyCharacteristic | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
### sendResponse<sup>(deprecated)</sup>    
server端回复client端的读写请求。  
 **调用形式：**     
- sendResponse(serverResponse: ServerResponse): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer#sendResponse。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| serverResponse<sup>(deprecated)</sup> | ServerResponse | true | server端回复的响应数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Profile is not supported. |  
    
 **示例代码：**   
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
  
    
### sendResponse<sup>(deprecated)</sup>  
 **调用形式：**     
- sendResponse(serverResponse: ServerResponse): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer#sendResponse。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| serverResponse<sup>(deprecated)</sup> | ServerResponse | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
### on('characteristicRead')<sup>(deprecated)</sup>    
server端订阅特征值读请求事件。  
 **调用形式：**     
- on(type: 'characteristicRead', callback: Callback\<CharacteristicReadRequest>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.on#event:characteristicRead。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"characteristicRead"字符串，表示特征值读请求事件。 |  
| callback<sup>(deprecated)</sup> | Callback<CharacteristicReadRequest> | true | 表示回调函数的入参，client端发送的读请求数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
### on('characteristicRead')<sup>(deprecated)</sup>  
 **调用形式：**     
- on(type: 'characteristicRead', callback: Callback\<CharacteristicReadRequest>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.on#event:characteristicRead。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<CharacteristicReadRequest> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
### off('characteristicRead')<sup>(deprecated)</sup>    
server端取消订阅特征值读请求事件。  
 **调用形式：**     
- off(type: 'characteristicRead', callback?: Callback\<CharacteristicReadRequest>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.off#event:characteristicRead。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"characteristicRead"字符串，表示特征值读请求事件。 |  
| callback<sup>(deprecated)</sup> | Callback<CharacteristicReadRequest> | false | 表示取消订阅特征值读请求事件上报。不填该参数则取消订阅该type对应的所有回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
try {  
let gattServer = bluetoothManager.BLE.createGattServer();  
gattServer.off("characteristicRead");  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### off('characteristicRead')<sup>(deprecated)</sup>  
 **调用形式：**     
- off(type: 'characteristicRead', callback?: Callback\<CharacteristicReadRequest>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.off#event:characteristicRead。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<CharacteristicReadRequest> | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
### on('characteristicWrite')<sup>(deprecated)</sup>    
server端订阅特征值写请求事件。  
 **调用形式：**     
- on(type: 'characteristicWrite', callback: Callback\<CharacteristicWriteRequest>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.on#event:characteristicWrite。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"characteristicWrite"字符串，表示特征值写请求事件。 |  
| callback<sup>(deprecated)</sup> | Callback<CharacteristicWriteRequest> | true | 表示回调函数的入参，client端发送的写请求数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
```null    
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
  
    
### on('characteristicWrite')<sup>(deprecated)</sup>  
 **调用形式：**     
- on(type: 'characteristicWrite', callback: Callback\<CharacteristicWriteRequest>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.on#event:characteristicWrite。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<CharacteristicWriteRequest> | true | 表示回调函数的入参，client端发送的读请求数据。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
### off('characteristicWrite')<sup>(deprecated)</sup>    
server端取消订阅特征值写请求事件。  
 **调用形式：**     
- off(type: 'characteristicWrite', callback?: Callback\<CharacteristicWriteRequest>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.off#event:characteristicWrite。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"characteristicWrite"字符串，表示特征值写请求事件。 |  
| callback<sup>(deprecated)</sup> | Callback<CharacteristicWriteRequest> | false | 表示回调函数的入参，client端发送的读请求数据。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
try {  
let gattServer = bluetoothManager.BLE.createGattServer();  
gattServer.off("characteristicWrite");  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### off('characteristicWrite')<sup>(deprecated)</sup>  
 **调用形式：**     
- off(type: 'characteristicWrite', callback?: Callback\<CharacteristicWriteRequest>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.off#event:characteristicWrite。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<CharacteristicWriteRequest> | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
### on('descriptorRead')<sup>(deprecated)</sup>    
server端订阅描述符读请求事件。  
 **调用形式：**     
- on(type: 'descriptorRead', callback: Callback\<DescriptorReadRequest>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.on#event:descriptorRead。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"characteristicWrite"字符串，表示特征值写请求事件。 |  
| callback<sup>(deprecated)</sup> | Callback<DescriptorReadRequest> | true | 表示回调函数的入参，client端发送的读请求数据。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
### on('descriptorRead')<sup>(deprecated)</sup>  
 **调用形式：**     
- on(type: 'descriptorRead', callback: Callback\<DescriptorReadRequest>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.on#event:descriptorRead。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<DescriptorReadRequest> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
### off('descriptorRead')<sup>(deprecated)</sup>    
server端取消订阅描述符读请求事件。  
 **调用形式：**     
- off(type: 'descriptorRead', callback?: Callback\<DescriptorReadRequest>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.off#event:descriptorRead。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"characteristicWrite"字符串，表示特征值写请求事件。 |  
| callback<sup>(deprecated)</sup> | Callback<DescriptorReadRequest> | false | 表示回调函数的入参，client端发送的读请求数据。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
try {  
let gattServer = bluetoothManager.BLE.createGattServer();  
gattServer.off("descriptorRead");  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### off('descriptorRead')<sup>(deprecated)</sup>  
 **调用形式：**     
- off(type: 'descriptorRead', callback?: Callback\<DescriptorReadRequest>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.off#event:descriptorRead。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<DescriptorReadRequest> | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
### on('descriptorWrite')<sup>(deprecated)</sup>    
server端订阅描述符写请求事件。  
 **调用形式：**     
- on(type: 'descriptorWrite', callback: Callback\<DescriptorWriteRequest>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.on#event:descriptorWrite。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"characteristicWrite"字符串，表示特征值写请求事件。 |  
| callback<sup>(deprecated)</sup> | Callback<DescriptorWriteRequest> | true | 表示回调函数的入参，client端发送的读请求数据。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
### on('descriptorWrite')<sup>(deprecated)</sup>  
 **调用形式：**     
- on(type: 'descriptorWrite', callback: Callback\<DescriptorWriteRequest>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.on#event:descriptorWrite。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<DescriptorWriteRequest> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
### off('descriptorWrite')<sup>(deprecated)</sup>    
server端取消订阅描述符写请求事件。  
 **调用形式：**     
- off(type: 'descriptorWrite', callback?: Callback\<DescriptorWriteRequest>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.off#event:descriptorWrite。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"characteristicWrite"字符串，表示特征值写请求事件。 |  
| callback<sup>(deprecated)</sup> | Callback<DescriptorWriteRequest> | false | 表示回调函数的入参，client端发送的读请求数据。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
try {  
let gattServer = bluetoothManager.BLE.createGattServer();  
gattServer.off("descriptorWrite");  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### off('descriptorWrite')<sup>(deprecated)</sup>  
 **调用形式：**     
- off(type: 'descriptorWrite', callback?: Callback\<DescriptorWriteRequest>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.off#event:descriptorWrite。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<DescriptorWriteRequest> | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
### on('connectStateChange')<sup>(deprecated)</sup>    
server端订阅BLE连接状态变化事件。  
 **调用形式：**     
- on(type: 'connectStateChange', callback: Callback\<BLEConnectChangedState>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.on#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"characteristicWrite"字符串，表示特征值写请求事件。 |  
| callback<sup>(deprecated)</sup> | Callback<BLEConnectChangedState> | true | 表示回调函数的入参，client端发送的读请求数据。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
### on('connectStateChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- on(type: 'connectStateChange', callback: Callback\<BLEConnectChangedState>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.on#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<BLEConnectChangedState> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
### off('connectStateChange')<sup>(deprecated)</sup>    
server端取消订阅BLE连接状态变化事件。  
 **调用形式：**     
- off(type: 'connectStateChange', callback?: Callback\<BLEConnectChangedState>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.off#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"characteristicWrite"字符串，表示特征值写请求事件。 |  
| callback<sup>(deprecated)</sup> | Callback<BLEConnectChangedState> | false | 表示回调函数的入参，client端发送的读请求数据。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
try {  
let gattServer = bluetoothManager.BLE.createGattServer();  
gattServer.off("connectStateChange");  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### off('connectStateChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- off(type: 'connectStateChange', callback?: Callback\<BLEConnectChangedState>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattServer.off#event:connectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<BLEConnectChangedState> | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
## GattClientDevice<sup>(deprecated)</sup>    
client端类，使用client端方法之前需要创建该类的实例进行操作，通过createGattClientDevice(deviceId: string)方法构造此实例。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.GattClientDevice替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### connect<sup>(deprecated)</sup>    
client端发起连接远端蓝牙低功耗设备。  
 **调用形式：**     
- connect(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#connect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');  
    device.connect();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### connect<sup>(deprecated)</sup>  
 **调用形式：**     
- connect(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#connect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
### disconnect<sup>(deprecated)</sup>  
 **调用形式：**     
- disconnect(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#disconnect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
client端断开与远端蓝牙低功耗设备的连接。  
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');  
    device.disconnect();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### disconnect<sup>(deprecated)</sup>  
 **调用形式：**     
- disconnect(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#disconnect。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
### close<sup>(deprecated)</sup>    
关闭客户端功能，注销client在协议栈的注册，调用该接口后[GattClientDevice](#gattclientdevice)实例将不能再使用。  
 **调用形式：**     
- close(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#close。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');  
    device.close();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### close<sup>(deprecated)</sup>  
 **调用形式：**     
- close(): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#close。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
### getDeviceName<sup>(deprecated)</sup>    
client获取远端蓝牙低功耗设备名。  
 **调用形式：**     
- getDeviceName(callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#getDeviceName。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | client获取对端server设备名，通过注册回调函数获取。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
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
 **调用形式：**     
- getDeviceName(callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#getDeviceName。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900099 |  |  
    
### getDeviceName<sup>(deprecated)</sup>    
client获取远端蓝牙低功耗设备名。  
 **调用形式：**     
- getDeviceName(): Promise\<string>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#getDeviceName。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | client获取对端server设备名，通过promise形式获取。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900099 | Profile is not supported. |  
    
 **示例代码：**   
示例（promise）：  
  
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
  
    
### getDeviceName<sup>(deprecated)</sup>  
 **调用形式：**     
- getDeviceName(): Promise\<string>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#getDeviceName。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900099 |  |  
    
### getServices<sup>(deprecated)</sup>    
client端获取蓝牙低功耗设备的所有服务，即服务发现。  
 **调用形式：**     
- getServices(callback: AsyncCallback\<Array\<GattService>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#getServices。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<GattService>> | true | client获取对端server设备名，通过注册回调函数获取。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
// callkback 模式  
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
 **调用形式：**     
- getServices(callback: AsyncCallback\<Array\<GattService>>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#getServices。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<GattService>> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900099 |  |  
    
### getServices<sup>(deprecated)</sup>    
client端获取蓝牙低功耗设备的所有服务，即服务发现。  
 **调用形式：**     
- getServices(): Promise\<Array\<GattService>>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#getServices。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<GattService>> | client获取对端server设备名，通过promise形式获取。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（promise）：  
  
```js    
import { BusinessError } from '@ohos.base';  
// Promise 模式  
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
  
    
### getServices<sup>(deprecated)</sup>  
 **调用形式：**     
- getServices(): Promise\<Array\<GattService>>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#getServices。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<GattService>> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900099 |  |  
    
### readCharacteristicValue<sup>(deprecated)</sup>    
client端读取蓝牙低功耗设备特定服务的特征值。  
 **调用形式：**     
- readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#readCharacteristicValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| characteristic<sup>(deprecated)</sup> | BLECharacteristic | true | 待读取的特征值。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<BLECharacteristic> | true | client获取对端server设备名，通过注册回调函数获取。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Operation failed. |  
| 2901000 | Read forbidden. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
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
 **调用形式：**     
- readCharacteristicValue(characteristic: BLECharacteristic, callback: AsyncCallback\<BLECharacteristic>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#readCharacteristicValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| characteristic<sup>(deprecated)</sup> | BLECharacteristic | true |  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<BLECharacteristic> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2901000 |  |  
| 2900099 |  |  
    
### readCharacteristicValue<sup>(deprecated)</sup>    
client端读取蓝牙低功耗设备特定服务的特征值。  
 **调用形式：**     
- readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#readCharacteristicValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| characteristic<sup>(deprecated)</sup> | BLECharacteristic | true | 待读取的特征值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<BLECharacteristic> | client获取对端server设备名，通过promise形式获取。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Operation failed. |  
| 2901000 | Read forbidden. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（promise）：  
  
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
  
    
### readCharacteristicValue<sup>(deprecated)</sup>  
 **调用形式：**     
- readCharacteristicValue(characteristic: BLECharacteristic): Promise\<BLECharacteristic>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#readCharacteristicValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| characteristic<sup>(deprecated)</sup> | BLECharacteristic | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<BLECharacteristic> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2901000 |  |  
| 2900099 |  |  
    
### readDescriptorValue<sup>(deprecated)</sup>    
client端读取蓝牙低功耗设备特定的特征包含的描述符。  
 **调用形式：**     
- readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#readDescriptorValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| descriptor<sup>(deprecated)</sup> | BLEDescriptor | true | 待读取的描述符。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<BLEDescriptor> | true | client获取对端server设备名，通过注册回调函数获取。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2901000 | Read forbidden. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
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
 **调用形式：**     
- readDescriptorValue(descriptor: BLEDescriptor, callback: AsyncCallback\<BLEDescriptor>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#readDescriptorValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| descriptor<sup>(deprecated)</sup> | BLEDescriptor | true |  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<BLEDescriptor> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2901000 |  |  
| 2900099 |  |  
    
### readDescriptorValue<sup>(deprecated)</sup>    
client端读取蓝牙低功耗设备特定的特征包含的描述符。  
 **调用形式：**     
- readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#readDescriptorValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| descriptor<sup>(deprecated)</sup> | BLEDescriptor | true | 待读取的描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<BLEDescriptor> | client获取对端server设备名，通过promise形式获取。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2901000 | Read forbidden. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（promise）：  
  
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
  
    
### readDescriptorValue<sup>(deprecated)</sup>  
 **调用形式：**     
- readDescriptorValue(descriptor: BLEDescriptor): Promise\<BLEDescriptor>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#readDescriptorValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| descriptor<sup>(deprecated)</sup> | BLEDescriptor | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<BLEDescriptor> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2901000 |  |  
| 2900099 |  |  
    
### writeCharacteristicValue<sup>(deprecated)</sup>    
client端向低功耗蓝牙设备写入特定的特征值。  
 **调用形式：**     
- writeCharacteristicValue(characteristic: BLECharacteristic): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#writeCharacteristicValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| characteristic<sup>(deprecated)</sup> | BLECharacteristic | true | 蓝牙设备特征对应的二进制值及其它参数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2901001 | Write forbidden. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
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
  
    
### writeCharacteristicValue<sup>(deprecated)</sup>  
 **调用形式：**     
- writeCharacteristicValue(characteristic: BLECharacteristic): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#writeCharacteristicValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| characteristic<sup>(deprecated)</sup> | BLECharacteristic | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2901001 |  |  
| 2900099 |  |  
    
### writeDescriptorValue<sup>(deprecated)</sup>    
client端向低功耗蓝牙设备特定的描述符写入二进制数据。  
 **调用形式：**     
- writeDescriptorValue(descriptor: BLEDescriptor): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#writeDescriptorValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| descriptor<sup>(deprecated)</sup> | BLEDescriptor | true | 蓝牙设备描述符的二进制值及其它参数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2901001 | Write forbidden. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
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
  
    
### writeDescriptorValue<sup>(deprecated)</sup>  
 **调用形式：**     
- writeDescriptorValue(descriptor: BLEDescriptor): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#writeDescriptorValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| descriptor<sup>(deprecated)</sup> | BLEDescriptor | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2901001 |  |  
| 2900099 |  |  
    
### getRssiValue<sup>(deprecated)</sup>    
client获取远端蓝牙低功耗设备的信号强度 (Received Signal Strength Indication, RSSI)，调用[connect](#connect)接口连接成功后才能使用。  
 **调用形式：**     
- getRssiValue(callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#getRssiValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | client获取对端server设备名，通过注册回调函数获取。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（callback）：  
  
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
 **调用形式：**     
- getRssiValue(callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#getRssiValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 |  |  
    
### getRssiValue<sup>(deprecated)</sup>    
client获取远端蓝牙低功耗设备的信号强度 (Received Signal Strength Indication, RSSI)，调用[connect](#connect)接口连接成功后才能使用。  
 **调用形式：**     
- getRssiValue(): Promise\<number>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#getRssiValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | client获取对端server设备名，通过promise形式获取。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
示例（promise）：  
  
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
  
    
### getRssiValue<sup>(deprecated)</sup>  
 **调用形式：**     
- getRssiValue(): Promise\<number>  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#getRssiValue。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 |  |  
    
### setBLEMtuSize<sup>(deprecated)</sup>    
client协商远端蓝牙低功耗设备的最大传输单元（Maximum Transmission Unit, MTU），调用[connect](#connect)接口连接成功后才能使用。  
 **调用形式：**     
- setBLEMtuSize(mtu: number): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#setBLEMtuSize。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mtu<sup>(deprecated)</sup> | number | true | 设置范围为22~512字节。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');  
    device.setBLEMtuSize(128);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### setBLEMtuSize<sup>(deprecated)</sup>  
 **调用形式：**     
- setBLEMtuSize(mtu: number): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#setBLEMtuSize。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mtu<sup>(deprecated)</sup> | number | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900099 |  |  
    
### setNotifyCharacteristicChanged<sup>(deprecated)</sup>    
向服务端发送设置通知此特征值请求。  
 **调用形式：**     
- setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#setCharacteristicChangeNotification。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| characteristic<sup>(deprecated)</sup> | BLECharacteristic | true | 蓝牙低功耗特征。 |  
| enable<sup>(deprecated)</sup> | boolean | true | 启用接收notify设置为true，否则设置为false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
// 创建descriptors  
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
  
    
### setNotifyCharacteristicChanged<sup>(deprecated)</sup>  
 **调用形式：**     
- setNotifyCharacteristicChanged(characteristic: BLECharacteristic, enable: boolean): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice#setCharacteristicChangeNotification。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| characteristic<sup>(deprecated)</sup> | BLECharacteristic | true |  |  
| enable<sup>(deprecated)</sup> | boolean | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900099 |  |  
    
### on('BLECharacteristicChange')<sup>(deprecated)</sup>    
订阅蓝牙低功耗设备的特征值变化事件。需要先调用setNotifyCharacteristicChanged接口才能接收server端的通知。  
 **调用形式：**     
- on(type: 'BLECharacteristicChange', callback: Callback\<BLECharacteristic>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice.on#event:BLECharacteristicChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"BLECharacteristicChange"字符串，表示特征值变化事件。 |  
| callback<sup>(deprecated)</sup> | Callback<BLECharacteristic> | true | client获取对端server设备名，通过注册回调函数获取。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
### on('BLECharacteristicChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- on(type: 'BLECharacteristicChange', callback: Callback\<BLECharacteristic>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice.on#event:BLECharacteristicChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<BLECharacteristic> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
    
### off('BLECharacteristicChange')<sup>(deprecated)</sup>    
取消订阅蓝牙低功耗设备的特征值变化事件。  
 **调用形式：**     
- off(type: 'BLECharacteristicChange', callback?: Callback\<BLECharacteristic>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice.off#event:BLECharacteristicChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"BLECharacteristicChange"字符串，表示特征值变化事件。 |  
| callback<sup>(deprecated)</sup> | Callback<BLECharacteristic> | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');  
    device.off('BLECharacteristicChange');  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### off('BLECharacteristicChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- off(type: 'BLECharacteristicChange', callback?: Callback\<BLECharacteristic>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice.off#event:BLECharacteristicChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<BLECharacteristic> | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
    
### on('BLEConnectionStateChange')<sup>(deprecated)</sup>    
client端订阅蓝牙低功耗设备的连接状态变化事件。  
 **调用形式：**     
- on(type: 'BLEConnectionStateChange', callback: Callback\<BLEConnectChangedState>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice.on#event:BLEConnectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 填写"BLECharacteristicChange"字符串，表示特征值变化事件。 |  
| callback<sup>(deprecated)</sup> | Callback<BLEConnectChangedState> | true | client获取对端server设备名，通过注册回调函数获取。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
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
  
    
### on('BLEConnectionStateChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- on(type: 'BLEConnectionStateChange', callback: Callback\<BLEConnectChangedState>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice.on#event:BLEConnectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<BLEConnectChangedState> | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
    
### off('BLEConnectionStateChange')<sup>(deprecated)</sup>    
取消订阅蓝牙低功耗设备的连接状态变化事件。  
 **调用形式：**     
- off(type: 'BLEConnectionStateChange', callback?: Callback\<BLEConnectChangedState>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice.off#event:BLEConnectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<BLEConnectChangedState> | false | client获取对端server设备名，通过注册回调函数获取。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let device = bluetoothManager.BLE.createGattClientDevice('XX:XX:XX:XX:XX:XX');  
    device.off('BLEConnectionStateChange');  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### off('BLEConnectionStateChange')<sup>(deprecated)</sup>  
 **调用形式：**     
- off(type: 'BLEConnectionStateChange', callback?: Callback\<BLEConnectChangedState>): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.ble/ble.GattClientDevice.off#event:BLEConnectionStateChange。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | Callback<BLEConnectChangedState> | false |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
    
## GattService<sup>(deprecated)</sup>    
描述service的接口参数定义。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.GattService替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.GattService#serviceUuid替代。<br>特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |  
| isPrimary<sup>(deprecated)</sup> | boolean | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.GattService#isPrimary替代。<br>如果是主服务设置为true，否则设置为false。 |  
| characteristics<sup>(deprecated)</sup> | Array<BLECharacteristic> | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.GattService#characteristics替代。<br>当前服务包含的特征列表。 |  
| includeServices<sup>(deprecated)</sup> | Array<GattService> | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.GattService#includeServices替代。<br>当前服务依赖的其它服务。 |  
    
## BLECharacteristic<sup>(deprecated)</sup>    
描述characteristic的接口参数定义。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.BLECharacteristic替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.BLECharacteristic#serviceUuid替代。<br>特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |  
| characteristicUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.BLECharacteristic#characteristicUuid替代。<br>特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |  
| characteristicValue<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.BLECharacteristic#characteristicValue替代。<br>特征对应的二进制值。 |  
| descriptors<sup>(deprecated)</sup> | Array<BLEDescriptor> | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.BLECharacteristic#descriptors替代。<br>特定特征的描述符列表。 |  
    
## BLEDescriptor<sup>(deprecated)</sup>    
描述descriptor的接口参数定义。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.BLEDescriptor替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.BLEDescriptor#serviceUuid替代。<br>特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |  
| characteristicUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.BLEDescriptor#characteristicUuid替代。<br>特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |  
| descriptorUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.BLEDescriptor#descriptorUuid替代。<br>描述符（descriptor）的UUID，例如：00002902-0000-1000-8000-00805f9b34fb。 |  
| descriptorValue<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.BLEDescriptor#descriptorValue替代。<br>描述符（descriptor）的UUID，例如：00002902-0000-1000-8000-00805f9b34fb。 |  
    
## NotifyCharacteristic<sup>(deprecated)</sup>    
描述server端特征值变化时发送的特征通知参数定义。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.NotifyCharacteristic替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.NotifyCharacteristic#serviceUuid替代。<br>特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |  
| characteristicUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.NotifyCharacteristic#characteristicUuid替代。<br>特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |  
| characteristicValue<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.NotifyCharacteristic#characteristicValue替代。<br>特征对应的二进制值。 |  
| confirm<sup>(deprecated)</sup> | boolean | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.NotifyCharacteristic#confirm替代。<br>如果是notification则对端回复确认设置为true，如果是indication则对端不需要回复确认设置为false。 |  
    
## CharacteristicReadRequest<sup>(deprecated)</sup>    
描述server端订阅后收到的特征值读请求事件参数结构。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.CharacteristicReadRequest替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.CharacteristicReadRequest#deviceId替代。<br>表示发送特征值读请求的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |  
| transId<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.CharacteristicReadRequest#transId替代。<br>表示读请求的传输ID，server端回复响应时需填写相同的传输ID。 |  
| offset<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.CharacteristicReadRequest#offset替代。<br>表示读特征值数据的起始位置。例如：k表示从第k个字节开始读，server端回复响应时需填写相同的offset。 |  
| characteristicUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.CharacteristicReadRequest#characteristicUuid替代。<br>特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.CharacteristicReadRequest#serviceUuid替代。<br>特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |  
    
## CharacteristicWriteRequest<sup>(deprecated)</sup>    
描述server端订阅后收到的特征值写请求事件参数结构。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.CharacteristicWriteRequest替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.CharacteristicWriteRequest#deviceId替代。<br>表示发送特征值写请求的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |  
| transId<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.CharacteristicWriteRequest#transId替代。<br>表示写请求的传输ID，server端回复响应时需填写相同的传输ID。 |  
| offset<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.CharacteristicWriteRequest#offset替代。<br>表示写特征值数据的起始位置。例如：k表示从第k个字节开始写，server端回复响应时需填写相同的offset。 |  
| isPrep<sup>(deprecated)</sup> | boolean | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.CharacteristicWriteRequest#isPrepared替代。<br>表示写请求是否立即执行。 |  
| needRsp<sup>(deprecated)</sup> | boolean | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.CharacteristicWriteRequest#needRsp替代。<br>表示是否要给client端回复响应。 |  
| value<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.CharacteristicWriteRequest#value替代。<br>表示写入的描述符二进制数据。 |  
| characteristicUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.CharacteristicWriteRequest#characteristicUuid替代。<br>特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.CharacteristicWriteRequest#serviceUuid替代。<br>特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |  
    
## DescriptorReadRequest<sup>(deprecated)</sup>    
描述server端订阅后收到的描述符读请求事件参数结构。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.DescriptorReadRequest替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.DescriptorReadRequest#deviceId替代。<br>表示发送特征值写请求的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。。 |  
| transId<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.DescriptorReadRequest#transId替代。<br>表示写请求的传输ID，server端回复响应时需填写相同的传输ID。 |  
| offset<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.DescriptorReadRequest#offset替代。<br>表示写特征值数据的起始位置。例如：k表示从第k个字节开始写，server端回复响应时需填写相同的offset。 |  
| descriptorUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.DescriptorReadRequest#descriptorUuid替代。<br>描述符（descriptor）的UUID，例如：00002902-0000-1000-8000-00805f9b34fb。 |  
| characteristicUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.DescriptorReadRequest#characteristicUuid替代。<br>特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.DescriptorReadRequest#serviceUuid替代。<br>特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |  
    
## DescriptorWriteRequest<sup>(deprecated)</sup>    
描述server端订阅后收到的描述符写请求事件参数结构。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.DescriptorWriteRequest替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.DescriptorWriteRequest#deviceId替代。<br>表示发送特征值写请求的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |  
| transId<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.DescriptorWriteRequest#transId替代。<br>表示写请求的传输ID，server端回复响应时需填写相同的传输ID。 |  
| offset<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.DescriptorWriteRequest#offset替代。<br>表示写特征值数据的起始位置。例如：k表示从第k个字节开始写，server端回复响应时需填写相同的offset。 |  
| isPrep<sup>(deprecated)</sup> | boolean | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.DescriptorWriteRequest#isPrepared替代。<br>表示写请求是否立即执行。 |  
| needRsp<sup>(deprecated)</sup> | boolean | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.DescriptorWriteRequest#needRsp替代。<br>表示是否要给client端回复响应。 |  
| value<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.DescriptorWriteRequest#value替代。<br>表示写入的描述符二进制数据。 |  
| descriptorUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.DescriptorWriteRequest#descriptorUuid替代。<br>描述符（descriptor）的UUID，例如：00002902-0000-1000-8000-00805f9b34fb。 |  
| characteristicUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.DescriptorWriteRequest#characteristicUuid替代。<br>特定特征（characteristic）的UUID，例如：00002a11-0000-1000-8000-00805f9b34fb。 |  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.DescriptorWriteRequest#serviceUuid替代。<br>特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |  
    
## ServerResponse<sup>(deprecated)</sup>    
描述server端回复client端读/写请求的响应参数结构。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ServerResponse替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ServerResponse#deviceId替代。<br>表示发送特征值写请求的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |  
| transId<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ServerResponse#transId替代。<br>表示写请求的传输ID，server端回复响应时需填写相同的传输ID。 |  
| status<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ServerResponse#status替代。<br>表示响应的状态，设置为0即可，表示正常。 |  
| offset<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ServerResponse#offset替代。<br>表示请求的读/写起始位置，与订阅的读/写请求事件携带的offset保持一致。 |  
| value<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ServerResponse#value替代。<br>表示回复响应的二进制数据。 |  
    
## BLEConnectChangedState<sup>(deprecated)</sup>    
描述Gatt profile连接状态。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.BLEConnectionChangeState替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.BLEConnectionChangeState#deviceId替代。<br>表示发送特征值写请求的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |  
| state<sup>(deprecated)</sup> | ProfileConnectionState | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.BLEConnectionChangeState#state替代。<br>描述Gatt profile连接状态。 |  
    
## ScanResult<sup>(deprecated)</sup>    
扫描结果上报数据。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanResult替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanResult#deviceId替代。<br>表示发送特征值写请求的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。 |  
| rssi<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanResult#rssi替代。<br>表示扫描到的设备的rssi值。 |  
| data<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanResult#data替代。<br>表示扫描到的设备发送的广播包。 |  
    
## AdvertiseSetting<sup>(deprecated)</sup>    
描述蓝牙低功耗设备发送广播的参数。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.AdvertiseSetting替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| interval<sup>(deprecated)</sup> | number | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.AdvertiseSetting#interval替代。<br>表示广播间隔，最小值设置32个slot表示20ms，最大值设置16384个slot，默认值设置为1600个slot表示1s。 |  
| txPower<sup>(deprecated)</sup> | number | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.AdvertiseSetting#txPower替代。<br>表示发送功率，最小值设置-127，最大值设置1，默认值设置-7，单位dbm。 |  
| connectable<sup>(deprecated)</sup> | boolean | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.AdvertiseSetting#connectable替代。<br>表示是否是可连接广播，默认值设置为true。 |  
    
## AdvertiseData<sup>(deprecated)</sup>    
描述BLE广播数据包的内容。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.AdvertiseData替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| serviceUuids<sup>(deprecated)</sup> | Array<string> | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.AdvertiseData#serviceUuids替代。<br>表示要广播的服务UUID列表。 |  
| manufactureData<sup>(deprecated)</sup> | Array<ManufactureData> | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.AdvertiseData#manufactureData替代。<br>表示要广播的广播的制造商信息列表。 |  
| serviceData<sup>(deprecated)</sup> | Array<ServiceData> | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.AdvertiseData#serviceData替代。<br>表示要广播的服务数据列表。 |  
    
## ManufactureData<sup>(deprecated)</sup>    
描述BLE广播数据包的内容。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ManufactureData替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| manufactureId<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ManufactureData#manufactureId替代。<br>表示制造商的ID，由蓝牙SIG分配。 |  
| manufactureValue<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ManufactureData#manufactureValue替代。<br>表示制造商发送的制造商数据。 |  
    
## ServiceData<sup>(deprecated)</sup>    
描述广播包中服务数据内容。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ServiceData替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| serviceUuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ServiceData#serviceUuid替代。<br>表示服务的UUID。 |  
| serviceValue<sup>(deprecated)</sup> | ArrayBuffer | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ServiceData#serviceValue替代。<br>表示服务数据。 |  
    
## ScanFilter<sup>(deprecated)</sup>    
扫描过滤参数。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanFilter替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanFilter#deviceId替代。<br>表示过滤的BLE设备地址，例如："XX:XX:XX:XX:XX:XX"。 |  
| name<sup>(deprecated)</sup> | string | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanFilter#name替代。<br>表示过滤的BLE设备名。 |  
| serviceUuid<sup>(deprecated)</sup> | string | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanFilter#serviceUuid替代。<br>特定服务（service）的UUID，例如：00001888-0000-1000-8000-00805f9b34fb。 |  
| serviceUuidMask<sup>(deprecated)</sup> | string | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanFilter#serviceUuidMask替代。<br>表示过滤包含该UUID服务掩码的设备，例如：FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF。 |  
| serviceSolicitationUuid<sup>(deprecated)</sup> | string | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanFilter#serviceSolicitationUuid替代。<br>表示过滤包含该UUID服务请求的设备，例如：00001888-0000-1000-8000-00805F9B34FB。 |  
| serviceSolicitationUuidMask<sup>(deprecated)</sup> | string | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanFilter#serviceSolicitationUuidMask替代。<br>表示过滤包含该UUID服务请求掩码的设备，例如：FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF。 |  
| serviceData<sup>(deprecated)</sup> | ArrayBuffer | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanFilter#serviceData替代。<br>表示过滤包含该服务相关数据的设备，例如：[0x90,0x00,0xF1,0xF2]。 |  
| serviceDataMask<sup>(deprecated)</sup> | ArrayBuffer | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanFilter#serviceDataMask替代。<br>表示过滤包含该服务相关数据掩码的设备，例如：[0xFF,0xFF,0xFF,0xFF]。 |  
| manufactureId<sup>(deprecated)</sup> | number | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanFilter#manufactureId替代。<br>表示过滤包含该制造商ID的设备，例如：0x0006。   |  
| manufactureData<sup>(deprecated)</sup> | ArrayBuffer | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanFilter#manufactureData替代。<br>表示过滤包含该制造商相关数据的设备，例如：[0x1F,0x2F,0x3F]。 |  
| manufactureDataMask<sup>(deprecated)</sup> | ArrayBuffer | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanFilter#manufactureDataMask替代。<br>表示过滤包含该制造商相关数据掩码的设备，例如：[0xFF,0xFF,0xFF]。 |  
    
## ScanOptions<sup>(deprecated)</sup>    
扫描的配置参数。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanOptions替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| interval<sup>(deprecated)</sup> | number | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanOptions#interval替代。<br>表示扫描结果上报延迟时间，默认值为0。 |  
| dutyMode<sup>(deprecated)</sup> | ScanDuty | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanOptions#dutyMode替代。<br>表示扫描模式，默认值为SCAN_MODE_LOW_POWER。 |  
| matchMode<sup>(deprecated)</sup> | MatchMode | false | false | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanOptions#matchMode替代。<br>表示硬件的过滤匹配模式，默认值为MATCH_MODE_AGGRESSIVE。 |  
    
## SppOption<sup>(deprecated)</sup>    
描述spp的配置参数。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.socket/socket.SppOptions替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uuid<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.socket/socket.SppOptions#uuid替代。<br>spp单据的uuid。 |  
| secure<sup>(deprecated)</sup> | boolean | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.socket/socket.SppOptions#secure替代。<br>是否是安全通道。 |  
| type<sup>(deprecated)</sup> | SppType | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.socket/socket.SppOptions#type替代。<br>Spp链路类型。 |  
    
## PinRequiredParam<sup>(deprecated)</sup>    
描述配对请求参数。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.PinRequiredParam替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.PinRequiredParam#deviceId替代。<br>表示要配对的设备ID。 |  
| pinCode<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.PinRequiredParam#pinCode替代。<br>表示要配对的密钥。 |  
    
## DeviceClass<sup>(deprecated)</sup>    
描述蓝牙设备的类别。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.DeviceClass替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| majorClass<sup>(deprecated)</sup> | MajorClass | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.DeviceClass#majorClass替代。<br>表示蓝牙设备主要类别的枚举。 |  
| majorMinorClass<sup>(deprecated)</sup> | MajorMinorClass | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.DeviceClass#majorMinorClass替代。<br>表示主要次要蓝牙设备类别的枚举。 |  
| classOfDevice<sup>(deprecated)</sup> | number | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.DeviceClass#classOfDevice替代。<br>表示设备类别。 |  
    
## BondStateParam<sup>(deprecated)</sup>    
描述配对状态参数。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.BondStateParam替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.BondStateParam#deviceId替代。<br>表示要配对的设备ID。 |  
| state<sup>(deprecated)</sup> | BondState | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.BondStateParam#state替代。<br>表示配对设备的状态。 |  
    
## StateChangeParam<sup>(deprecated)</sup>    
描述profile状态改变参数。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.baseProfile/baseProfile.StateChangeParam替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.baseProfile/baseProfile.StateChangeParam#deviceId替代。<br>表示要配对的设备ID。 |  
| state<sup>(deprecated)</sup> | ProfileConnectionState | false | true | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.baseProfile/baseProfile.StateChangeParam#state替代。<br>表示配对设备的状态。 |  
    
## ScanDuty<sup>(deprecated)</sup>    
枚举，扫描模式。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanDuty替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SCAN_MODE_LOW_POWER<sup>(deprecated)</sup> | 0 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanDuty#SCAN_MODE_LOW_POWER替代。<br>表示低功耗模式，默认值。 |  
| SCAN_MODE_BALANCED<sup>(deprecated)</sup> | 1 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanDuty#SCAN_MODE_BALANCED替代。<br>表示均衡模式。 |  
| SCAN_MODE_LOW_LATENCY<sup>(deprecated)</sup> | 2 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.ScanDuty#SCAN_MODE_LOW_LATENCY替代。<br>表示低延迟模式。 |  
    
## MatchMode<sup>(deprecated)</sup>    
枚举，硬件过滤匹配模式。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.MatchMode替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MATCH_MODE_AGGRESSIVE<sup>(deprecated)</sup> | 1 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.MatchMode#MATCH_MODE_AGGRESSIVE替代。<br>表示硬件上报扫描结果门限较低，比如扫描到的功率较低或者一段时间扫描到的次数较少也触发上报，默认值。 |  
| MATCH_MODE_STICKY<sup>(deprecated)</sup> | 2 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.ble/ble.MatchMode#MATCH_MODE_STICKY替代。<br>表示硬件上报扫描结果门限较高，更高的功率门限以及扫描到多次才会上报。 |  
    
## ProfileConnectionState<sup>(deprecated)</sup>    
枚举，蓝牙设备的profile连接状态。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.ProfileConnectionState替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STATE_DISCONNECTED<sup>(deprecated)</sup> | 0 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.ProfileConnectionState#STATE_DISCONNECTED替代。<br>表示profile已断连。 |  
| STATE_CONNECTING<sup>(deprecated)</sup> | 1 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.ProfileConnectionState#STATE_CONNECTING替代。<br>表示profile正在连接。 |  
| STATE_CONNECTED<sup>(deprecated)</sup> | 2 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.ProfileConnectionState#STATE_CONNECTED替代。<br>表示profile已连接。 |  
| STATE_DISCONNECTING<sup>(deprecated)</sup> | 3 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.ProfileConnectionState#STATE_DISCONNECTING替代。<br>表示profile正在断连。 |  
    
## BluetoothState<sup>(deprecated)</sup>    
枚举，蓝牙开关状态。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.access/access.BluetoothState替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STATE_OFF<sup>(deprecated)</sup> | 0 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.access/access.BluetoothState#STATE_OFF替代。<br>表示蓝牙已关闭。 |  
| STATE_TURNING_ON<sup>(deprecated)</sup> | 1 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.access/access.BluetoothState#STATE_TURNING_ON替代。<br>表示蓝牙正在打开。 |  
| STATE_ON<sup>(deprecated)</sup> | 2 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.access/access.BluetoothState#STATE_ON替代。<br>表示蓝牙已打开。 |  
| STATE_TURNING_OFF<sup>(deprecated)</sup> | 3 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.access/access.BluetoothState#STATE_TURNING_OFF替代。<br>表示蓝牙正在关闭。 |  
| STATE_BLE_TURNING_ON<sup>(deprecated)</sup> | 4 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.access/access.BluetoothState#STATE_BLE_TURNING_ON替代。<br>表示蓝牙正在打开LE-only模式。 |  
| STATE_BLE_ON<sup>(deprecated)</sup> | 5 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.access/access.BluetoothState#STATE_BLE_ON替代。<br>表示蓝牙正处于LE-only模式。 |  
| STATE_BLE_TURNING_OFF<sup>(deprecated)</sup> | 6 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.access/access.BluetoothState#STATE_BLE_TURNING_OFF替代。<br>表示蓝牙正在关闭LE-only模式。 |  
    
## SppType<sup>(deprecated)</sup>    
枚举，Spp链路类型。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.socket/socket.SppType替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SPP_RFCOMM<sup>(deprecated)</sup> | 0 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.socket/socket.SppType#SPP_RFCOMM替代。<br>表示rfcomm链路类型。 |  
    
## ScanMode<sup>(deprecated)</sup>    
枚举，扫描模式。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.ScanMode替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SCAN_MODE_NONE<sup>(deprecated)</sup> | 0 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.ScanMode#SCAN_MODE_NONE替代。<br>没有扫描模式。 |  
| SCAN_MODE_CONNECTABLE<sup>(deprecated)</sup> | 1 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.ScanMode#SCAN_MODE_CONNECTABLE替代。<br>可连接扫描模式。 |  
| SCAN_MODE_GENERAL_DISCOVERABLE<sup>(deprecated)</sup> | 2 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.ScanMode#SCAN_MODE_GENERAL_DISCOVERABLE替代。<br>general发现模式。 |  
| SCAN_MODE_LIMITED_DISCOVERABLE<sup>(deprecated)</sup> | 3 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.ScanMode#SCAN_MODE_LIMITED_DISCOVERABLE替代。<br>limited发现模式。 |  
| SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE<sup>(deprecated)</sup> | 4 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.ScanMode#SCAN_MODE_CONNECTABLE_GENERAL_DISCOVERABLE替代。<br>可连接general发现模式。 |  
| SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE<sup>(deprecated)</sup> | 5 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.ScanMode#SCAN_MODE_CONNECTABLE_LIMITED_DISCOVERABLE替代。<br>可连接limited发现模式。 |  
    
## BondState<sup>(deprecated)</sup>    
枚举，配对状态。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.BondState替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| BOND_STATE_INVALID<sup>(deprecated)</sup> | 0 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.BondState#BOND_STATE_INVALID替代。<br>无效的配对。 |  
| BOND_STATE_BONDING<sup>(deprecated)</sup> | 1 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.BondState#BOND_STATE_BONDING替代。<br>正在配对。 |  
| BOND_STATE_BONDED<sup>(deprecated)</sup> | 2 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.connection/connection.BondState#BOND_STATE_BONDED替代。<br>已配对。 |  
    
## MajorClass<sup>(deprecated)</sup>    
枚举，蓝牙设备主要类别。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorClass替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MAJOR_MISC<sup>(deprecated)</sup> | 0x0000 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorClass#MAJOR_MISC替代。<br>表示杂项设备。 |  
| MAJOR_COMPUTER<sup>(deprecated)</sup> | 0x0100 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorClass#MAJOR_COMPUTER替代。<br>表示计算机设备。 |  
| MAJOR_PHONE<sup>(deprecated)</sup> | 0x0200 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorClass#MAJOR_PHONE替代。<br>表示手机设备。 |  
| MAJOR_NETWORKING<sup>(deprecated)</sup> | 0x0300 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorClass#MAJOR_NETWORKING替代。<br>表示网络设备。 |  
| MAJOR_AUDIO_VIDEO<sup>(deprecated)</sup> | 0x0400 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorClass#MAJOR_AUDIO_VIDEO替代。<br>表示音频和视频设备。 |  
| MAJOR_PERIPHERAL<sup>(deprecated)</sup> | 0x0500 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorClass#MAJOR_PERIPHERAL替代。<br>表示外围设备。 |  
| MAJOR_IMAGING<sup>(deprecated)</sup> | 0x0600 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorClass#MAJOR_IMAGING替代。<br>表示成像设备。 |  
| MAJOR_WEARABLE<sup>(deprecated)</sup> | 0x0700 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorClass#MAJOR_WEARABLE替代。<br>表示可穿戴设备。 |  
| MAJOR_TOY<sup>(deprecated)</sup> | 0x0800 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorClass#MAJOR_TOY替代。<br>表示玩具设备。 |  
| MAJOR_HEALTH<sup>(deprecated)</sup> | 0x0900 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorClass#MAJOR_HEALTH替代。<br>表示健康设备。 |  
| MAJOR_UNCATEGORIZED<sup>(deprecated)</sup> | 0x1F00 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorClass#MAJOR_UNCATEGORIZED替代。<br>表示未分类设备。 |  
    
## MajorMinorClass<sup>(deprecated)</sup>    
枚举，主要次要蓝牙设备类别。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| COMPUTER_UNCATEGORIZED<sup>(deprecated)</sup> | 0x0100 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#COMPUTER_UNCATEGORIZED替代。<br>表示未分类计算机设备。 |  
| COMPUTER_DESKTOP<sup>(deprecated)</sup> | 0x0104 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#COMPUTER_DESKTOP替代。<br>表示台式计算机设备。 |  
| COMPUTER_SERVER<sup>(deprecated)</sup> | 0x0108 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#COMPUTER_SERVER替代。<br>表示服务器设备。 |  
| COMPUTER_LAPTOP<sup>(deprecated)</sup> | 0x010C | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#COMPUTER_LAPTOP替代。<br>表示便携式计算机设备。 |  
| COMPUTER_HANDHELD_PC_PDA<sup>(deprecated)</sup> | 0x0110 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#COMPUTER_HANDHELD_PC_PDA替代。<br>表示手持式计算机设备。 |  
| COMPUTER_PALM_SIZE_PC_PDA<sup>(deprecated)</sup> | 0x0114 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#COMPUTER_PALM_SIZE_PC_PDA替代。<br>表示掌上电脑设备。 |  
| COMPUTER_WEARABLE<sup>(deprecated)</sup> | 0x0118 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#COMPUTER_WEARABLE替代。<br>表示可穿戴计算机设备。 |  
| COMPUTER_TABLET<sup>(deprecated)</sup> | 0x011C | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#COMPUTER_TABLET替代。<br>表示平板电脑设备。 |  
| PHONE_UNCATEGORIZED<sup>(deprecated)</sup> | 0x0200 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PHONE_UNCATEGORIZED替代。<br>表示未分类手机设备。 |  
| PHONE_CELLULAR<sup>(deprecated)</sup> | 0x0204 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PHONE_CELLULAR替代。<br>表示便携式手机设备。 |  
| PHONE_CORDLESS<sup>(deprecated)</sup> | 0x0208 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PHONE_CORDLESS替代。<br>表示无线电话设备。 |  
| PHONE_SMART<sup>(deprecated)</sup> | 0x020C | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PHONE_SMART替代。<br>表示智能手机设备。 |  
| PHONE_MODEM_OR_GATEWAY<sup>(deprecated)</sup> | 0x0210 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PHONE_MODEM_OR_GATEWAY替代。<br>表示调制解调器或网关手机设备。 |  
| PHONE_ISDN<sup>(deprecated)</sup> | 0x0214 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PHONE_ISDN替代。<br>表示ISDN手机设备。 |  
| NETWORK_FULLY_AVAILABLE<sup>(deprecated)</sup> | 0x0300 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#NETWORK_FULLY_AVAILABLE替代。<br>表示网络完全可用设备。 |  
| NETWORK_1_TO_17_UTILIZED<sup>(deprecated)</sup> | 0x0320 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#NETWORK_1_TO_17_UTILIZED替代。<br>表示使用网络1到17设备。 |  
| NETWORK_17_TO_33_UTILIZED<sup>(deprecated)</sup> | 0x0340 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#NETWORK_17_TO_33_UTILIZED替代。<br>表示使用网络17到33设备。 |  
| NETWORK_33_TO_50_UTILIZED<sup>(deprecated)</sup> | 0x0360 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#NETWORK_33_TO_50_UTILIZED替代。<br>表示使用网络33到50设备。 |  
| NETWORK_60_TO_67_UTILIZED<sup>(deprecated)</sup> | 0x0380 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#NETWORK_60_TO_67_UTILIZED替代。<br>表示使用网络60到67设备。 |  
| NETWORK_67_TO_83_UTILIZED<sup>(deprecated)</sup> | 0x03A0 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#NETWORK_67_TO_83_UTILIZED替代。<br>表示使用网络67到83设备。 |  
| NETWORK_83_TO_99_UTILIZED<sup>(deprecated)</sup> | 0x03C0 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#NETWORK_83_TO_99_UTILIZED替代。<br>表示使用网络83到99设备。 |  
| NETWORK_NO_SERVICE<sup>(deprecated)</sup> | 0x03E0 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#NETWORK_NO_SERVICE替代。<br>表示网络无服务设备。 |  
| AUDIO_VIDEO_UNCATEGORIZED<sup>(deprecated)</sup> | 0x0400 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_UNCATEGORIZED替代。<br>表示未分类音频视频设备。 |  
| AUDIO_VIDEO_WEARABLE_HEADSET<sup>(deprecated)</sup> | 0x0404 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_WEARABLE_HEADSET替代。<br>表示可穿戴式音频视频设备。 |  
| AUDIO_VIDEO_HANDSFREE<sup>(deprecated)</sup> | 0x0408 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_HANDSFREE替代。<br>表示免提音频视频设备。 |  
| AUDIO_VIDEO_MICROPHONE<sup>(deprecated)</sup> | 0x0410 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_MICROPHONE替代。<br>表示麦克风音频视频设备。 |  
| AUDIO_VIDEO_LOUDSPEAKER<sup>(deprecated)</sup> | 0x0414 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_LOUDSPEAKER替代。<br>表示扬声器音频视频设备。 |  
| AUDIO_VIDEO_HEADPHONES<sup>(deprecated)</sup> | 0x0418 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_HEADPHONES替代。<br>表示头戴式音频视频设备。 |  
| AUDIO_VIDEO_PORTABLE_AUDIO<sup>(deprecated)</sup> | 0x041C | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_PORTABLE_AUDIO替代。<br>表示便携式音频视频设备。 |  
| AUDIO_VIDEO_CAR_AUDIO<sup>(deprecated)</sup> | 0x0420 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_CAR_AUDIO替代。<br>表示汽车音频视频设备。 |  
| AUDIO_VIDEO_SET_TOP_BOX<sup>(deprecated)</sup> | 0x0424 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_SET_TOP_BOX替代。<br>表示机顶盒音频视频设备。 |  
| AUDIO_VIDEO_HIFI_AUDIO<sup>(deprecated)</sup> | 0x0428 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_HIFI_AUDIO替代。<br>表示高保真音响设备。 |  
| AUDIO_VIDEO_VCR<sup>(deprecated)</sup> | 0x042C | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_VCR替代。<br>表示录像机音频视频设备。 |  
| AUDIO_VIDEO_VIDEO_CAMERA<sup>(deprecated)</sup> | 0x0430 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_VIDEO_CAMERA替代。<br>表示照相机音频视频设备。 |  
| AUDIO_VIDEO_CAMCORDER<sup>(deprecated)</sup> | 0x0434 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_CAMCORDER替代。<br>表示摄像机音频视频设备。 |  
| AUDIO_VIDEO_VIDEO_MONITOR<sup>(deprecated)</sup> | 0x0438 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_VIDEO_MONITOR替代。<br>表示监视器音频视频设备。 |  
| AUDIO_VIDEO_VIDEO_DISPLAY_AND_LOUDSPEAKER<sup>(deprecated)</sup> | 0x043C | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_VIDEO_DISPLAY_AND_LOUDSPEAKER替代。<br>表示视频显示器和扬声器设备。 |  
| AUDIO_VIDEO_VIDEO_CONFERENCING<sup>(deprecated)</sup> | 0x0440 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_VIDEO_CONFERENCING替代。<br>表示音频视频会议设备。 |  
| AUDIO_VIDEO_VIDEO_GAMING_TOY<sup>(deprecated)</sup> | 0x0448 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#AUDIO_VIDEO_VIDEO_GAMING_TOY替代。<br>表示游戏玩具音频视频设备。 |  
| PERIPHERAL_NON_KEYBOARD_NON_POINTING<sup>(deprecated)</sup> | 0x0500 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_NON_KEYBOARD_NON_POINTING替代。<br>表示非键盘非指向外围设备。 |  
| PERIPHERAL_KEYBOARD<sup>(deprecated)</sup> | 0x0540 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_KEYBOARD替代。<br>表示外设键盘设备。 |  
| PERIPHERAL_POINTING_DEVICE<sup>(deprecated)</sup> | 0x0580 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_POINTING_DEVICE替代。<br>表示定点装置外围设备。 |  
| PERIPHERAL_KEYBOARD_POINTING<sup>(deprecated)</sup> | 0x05C0 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_KEYBOARD_POINTING替代。<br>表示键盘指向外围设备。 |  
| PERIPHERAL_UNCATEGORIZED<sup>(deprecated)</sup> | 0x0500 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_UNCATEGORIZED替代。<br>表示未分类外围设备。 |  
| PERIPHERAL_JOYSTICK<sup>(deprecated)</sup> | 0x0504 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_JOYSTICK替代。<br>表示周边操纵杆设备。 |  
| PERIPHERAL_GAMEPAD<sup>(deprecated)</sup> | 0x0508 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_GAMEPAD替代。<br>表示周边游戏板设备。 |  
| PERIPHERAL_REMOTE_CONTROL<sup>(deprecated)</sup> | 0x05C0 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_REMOTE_CONTROL替代。<br>表示周边游戏板设备。 |  
| PERIPHERAL_SENSING_DEVICE<sup>(deprecated)</sup> | 0x0510 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_SENSING_DEVICE替代。<br>表示远程控制外围设备。 |  
| PERIPHERAL_DIGITIZER_TABLET<sup>(deprecated)</sup> | 0x0514 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_DIGITIZER_TABLET替代。<br>表示外围数字化仪平板电脑设备。 |  
| PERIPHERAL_CARD_READER<sup>(deprecated)</sup> | 0x0518 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_CARD_READER替代。<br>表示外围读卡器设备。 |  
| PERIPHERAL_DIGITAL_PEN<sup>(deprecated)</sup> | 0x051C | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_DIGITAL_PEN替代。<br>表示外设数码笔设备。 |  
| PERIPHERAL_SCANNER_RFID<sup>(deprecated)</sup> | 0x0520 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_SCANNER_RFID替代。<br>表示射频识别扫描仪外围设备。 |  
| PERIPHERAL_GESTURAL_INPUT<sup>(deprecated)</sup> | 0x0522 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#PERIPHERAL_GESTURAL_INPUT替代。<br>表示手势输入外围设备。 |  
| IMAGING_UNCATEGORIZED<sup>(deprecated)</sup> | 0x0600 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#IMAGING_UNCATEGORIZED替代。<br>表示未分类的图像设备。 |  
| IMAGING_DISPLAY<sup>(deprecated)</sup> | 0x0610 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#IMAGING_DISPLAY替代。<br>表示图像显示设备。 |  
| IMAGING_CAMERA<sup>(deprecated)</sup> | 0x0620 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#IMAGING_CAMERA替代。<br>表示成像照相机设备。 |  
| IMAGING_SCANNER<sup>(deprecated)</sup> | 0x0640 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#IMAGING_SCANNER替代。<br>表示成像扫描仪设备。 |  
| IMAGING_PRINTER<sup>(deprecated)</sup> | 0x0680 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#IMAGING_PRINTER替代。<br>表示成像打印机设备。 |  
| WEARABLE_UNCATEGORIZED<sup>(deprecated)</sup> | 0x0700 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#WEARABLE_UNCATEGORIZED替代。 |  
| WEARABLE_WRIST_WATCH<sup>(deprecated)</sup> | 0x0704 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#WEARABLE_WRIST_WATCH替代。<br>表示未分类的可穿戴设备。 |  
| WEARABLE_PAGER<sup>(deprecated)</sup> | 0x0708 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#WEARABLE_PAGER替代。<br>表示可穿戴寻呼机设备。 |  
| WEARABLE_JACKET<sup>(deprecated)</sup> | 0x070C | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#WEARABLE_JACKET替代。<br>表示夹克可穿戴设备。 |  
| WEARABLE_HELMET<sup>(deprecated)</sup> | 0x0710 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#WEARABLE_HELMET替代。<br>表示可穿戴头盔设备。 |  
| WEARABLE_GLASSES<sup>(deprecated)</sup> | 0x0714 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#WEARABLE_GLASSES替代。<br>表示可穿戴眼镜设备。 |  
| TOY_UNCATEGORIZED<sup>(deprecated)</sup> | 0x0800 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#TOY_UNCATEGORIZED替代。<br>表示未分类的玩具设备。 |  
| TOY_ROBOT<sup>(deprecated)</sup> | 0x0804 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#TOY_ROBOT替代。<br>表示玩具机器人设备。 |  
| TOY_VEHICLE<sup>(deprecated)</sup> | 0x0808 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#TOY_VEHICLE替代。<br>表示玩具车设备。 |  
| TOY_DOLL_ACTION_FIGURE<sup>(deprecated)</sup> | 0x080C | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#TOY_DOLL_ACTION_FIGURE替代。<br>表示人形娃娃玩具设备。 |  
| TOY_CONTROLLER<sup>(deprecated)</sup> | 0x0810 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#TOY_CONTROLLER替代。<br>表示玩具控制器设备。 |  
| TOY_GAME<sup>(deprecated)</sup> | 0x0814 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#TOY_GAME替代。<br>表示玩具游戏设备。 |  
| HEALTH_UNCATEGORIZED<sup>(deprecated)</sup> | 0x0900 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_UNCATEGORIZED替代。<br>表示未分类健康设备。 |  
| HEALTH_BLOOD_PRESSURE<sup>(deprecated)</sup> | 0x0904 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_BLOOD_PRESSURE替代。<br>表示血压健康设备。 |  
| HEALTH_THERMOMETER<sup>(deprecated)</sup> | 0x0908 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_THERMOMETER替代。<br>表示温度计健康设备。 |  
| HEALTH_WEIGHING<sup>(deprecated)</sup> | 0x090C | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_WEIGHING替代。<br>表示体重健康设备。 |  
| HEALTH_GLUCOSE<sup>(deprecated)</sup> | 0x0910 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_GLUCOSE替代。<br>表示葡萄糖健康设备。 |  
| HEALTH_PULSE_OXIMETER<sup>(deprecated)</sup> | 0x0914 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_PULSE_OXIMETER替代。<br>表示脉搏血氧仪健康设备。 |  
| HEALTH_PULSE_RATE<sup>(deprecated)</sup> | 0x0918 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_PULSE_RATE替代。<br>表示脉搏率健康设备。 |  
| HEALTH_DATA_DISPLAY<sup>(deprecated)</sup> | 0x091C | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_DATA_DISPLAY替代。<br>表示数据显示健康设备。 |  
| HEALTH_STEP_COUNTER<sup>(deprecated)</sup> | 0x0920 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_STEP_COUNTER替代。<br>表示阶梯计数器健康设备。 |  
| HEALTH_BODY_COMPOSITION_ANALYZER<sup>(deprecated)</sup> | 0x0924 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_BODY_COMPOSITION_ANALYZER替代。<br>表示身体成分分析仪健康设备。 |  
| HEALTH_PEAK_FLOW_MONITOR<sup>(deprecated)</sup> | 0x0928 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_PEAK_FLOW_MONITOR替代。<br>表示湿度计健康设备。 |  
| HEALTH_MEDICATION_MONITOR<sup>(deprecated)</sup> | 0x092C | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_MEDICATION_MONITOR替代。<br>表示药物监视仪健康设备。 |  
| HEALTH_KNEE_PROSTHESIS<sup>(deprecated)</sup> | 0x0930 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_KNEE_PROSTHESIS替代。<br>表示膝盖假肢健康设备。 |  
| HEALTH_ANKLE_PROSTHESIS<sup>(deprecated)</sup> | 0x0934 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_ANKLE_PROSTHESIS替代。<br>表示脚踝假肢健康设备。 |  
| HEALTH_GENERIC_HEALTH_MANAGER<sup>(deprecated)</sup> | 0x0938 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_GENERIC_HEALTH_MANAGER替代。<br>表示通用健康管理设备。 |  
| HEALTH_PERSONAL_MOBILITY_DEVICE<sup>(deprecated)</sup> | 0x093C | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.MajorMinorClass#HEALTH_PERSONAL_MOBILITY_DEVICE替代。<br>表示个人移动健康设备。 |  
    
## PlayingState<sup>(deprecated)</sup>    
枚举，蓝牙A2DP 播放状态。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.a2dp/a2dp.PlayingState替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STATE_NOT_PLAYING<sup>(deprecated)</sup> | 0 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.a2dp/a2dp.PlayingState#STATE_NOT_PLAYING替代。<br>表示未播放。 |  
| STATE_PLAYING<sup>(deprecated)</sup> | 1 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.a2dp/a2dp.PlayingState#STATE_PLAYING替代。<br>表示正在播放。 |  
    
## ProfileId<sup>(deprecated)</sup>    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.ProfileId替代。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PROFILE_A2DP_SOURCE<sup>(deprecated)</sup> | 1 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.ProfileId#PROFILE_A2DP_SOURCE替代。<br>表示A2DP profile。 |  
| PROFILE_HANDS_FREE_AUDIO_GATEWAY<sup>(deprecated)</sup> | 4 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.ProfileId#PROFILE_HANDSFREE_AUDIO_GATEWAY替代。<br>表示HFP profile。 |  
| PROFILE_HID_HOST<sup>(deprecated)</sup> | 6 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.ProfileId#PROFILE_HID_HOST替代。<br>表示HID profile。 |  
| PROFILE_PAN_NETWORK<sup>(deprecated)</sup> | 7 | 从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.constant/constant.ProfileId#PROFILE_PAN_NETWORK替代。<br>表示PAN profile。 |  
