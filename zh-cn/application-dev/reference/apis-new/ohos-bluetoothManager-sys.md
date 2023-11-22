# @ohos.bluetoothManager    
蓝牙模块提供了基础的传统蓝牙能力以及BLE的扫描、广播等功能。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import bluetoothManager from '@ohos.bluetoothManager'    
```  
    
## cancelPairedDevice<sup>(deprecated)</sup>    
删除配对的远程设备。  
 **调用形式：**     
- cancelPairedDevice(deviceId: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#cancelPairedDevice。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId<sup>(deprecated)</sup> | string | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 | Service stopped. |  
| 2900003 | Bluetooth switch is off. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    bluetoothManager.cancelPairedDevice("XX:XX:XX:XX:XX:XX");  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
## cancelPairedDevice<sup>(deprecated)</sup>  
 **调用形式：**     
- cancelPairedDevice(deviceId: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.connection/connection#cancelPairedDevice。  
 **系统API:**  此接口为系统接口。  
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
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900099 |  |  
    
## HidHostProfile<sup>(deprecated)</sup>    
使用HidHostProfile方法之前需要创建该类的实例进行操作，通过getProfile()方法构造此实例。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.hid/hid.HidHostProfile替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### connect<sup>(deprecated)</sup>    
连接设备的HidHost服务。  
 **调用形式：**     
- connect(device: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.hid/hid.HidHostProfile#connect。  
 **系统API:**  此接口为系统接口。  
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
| 202 |  |  
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
    let hidHostProfile: bluetoothManager.HidHostProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_HID_HOST) as bluetoothManager.HidHostProfile;  
    hidHostProfile.connect('XX:XX:XX:XX:XX:XX');  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### connect<sup>(deprecated)</sup>  
 **调用形式：**     
- connect(device: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.hid/hid.HidHostProfile#connect。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900004 |  |  
| 2900099 |  |  
    
### disconnect<sup>(deprecated)</sup>    
断开连接设备的HidHost服务。  
 **调用形式：**     
- disconnect(device: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.hid/hid.HidHostProfile#disconnect。  
 **系统API:**  此接口为系统接口。  
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
| 202 |  |  
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
    let hidHostProfile: bluetoothManager.HidHostProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_HID_HOST) as bluetoothManager.HidHostProfile;  
    hidHostProfile.disconnect('XX:XX:XX:XX:XX:XX');  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### disconnect<sup>(deprecated)</sup>  
 **调用形式：**     
- disconnect(device: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.hid/hid.HidHostProfile#disconnect。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900004 |  |  
| 2900099 |  |  
    
## PanProfile<sup>(deprecated)</sup>    
使用PanProfile方法之前需要创建该类的实例进行操作，通过getProfile()方法构造此实例。    
从API version 9 开始支持，从API version 10 开始废弃。建议使用ohos.bluetooth.pan/pan.PanProfile替代。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### disconnect<sup>(deprecated)</sup>    
断开连接设备的Pan服务。  
 **调用形式：**     
- disconnect(device: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.pan/pan.PanProfile#disconnect。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.USE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| device<sup>(deprecated)</sup> | string | true | 远端设备地址。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
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
    let panProfile: bluetoothManager.PanProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_PAN_NETWORK) as bluetoothManager.PanProfile;  
    panProfile.disconnect('XX:XX:XX:XX:XX:XX');  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### disconnect<sup>(deprecated)</sup>  
 **调用形式：**     
- disconnect(device: string): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.pan/pan.PanProfile#disconnect。  
 **系统API:**  此接口为系统接口。  
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
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900004 |  |  
| 2900099 |  |  
    
### setTethering<sup>(deprecated)</sup>    
设置网络共享状态。  
 **调用形式：**     
- setTethering(enable: boolean): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.pan/pan.PanProfile#setTethering。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.DISCOVER_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enable<sup>(deprecated)</sup> | boolean | true | 是否设置蓝牙共享。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
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
    let panProfile: bluetoothManager.PanProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_PAN_NETWORK) as bluetoothManager.PanProfile;  
    panProfile.setTethering(true);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### setTethering<sup>(deprecated)</sup>  
 **调用形式：**     
- setTethering(enable: boolean): void  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.pan/pan.PanProfile#setTethering。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enable<sup>(deprecated)</sup> | boolean | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 2900001 |  |  
| 2900003 |  |  
| 2900004 |  |  
| 2900099 |  |  
    
### isTetheringOn<sup>(deprecated)</sup>    
获取网络共享状态。  
 **调用形式：**     
- isTetheringOn(): boolean  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.pan/pan.PanProfile#isTetheringOn。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 网络共享开启返回true，网络共享关闭返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 801 |  |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let panProfile: bluetoothManager.PanProfile = bluetoothManager.getProfileInstance(bluetoothManager.ProfileId.PROFILE_PAN_NETWORK) as bluetoothManager.PanProfile;  
    panProfile.isTetheringOn();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### isTetheringOn<sup>(deprecated)</sup>  
 **调用形式：**     
- isTetheringOn(): boolean  
  
 **废弃说明：** 从API version 10 开始废弃。替代接口: ohos.bluetooth.pan/pan.PanProfile#isTetheringOn。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 801 |  |  
