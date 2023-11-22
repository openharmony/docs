# @ohos.bluetooth.access    
access模块提供了打开和关闭蓝牙、获取蓝牙状态的方法。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import access from '@ohos.bluetooth.access'    
```  
    
## enableBluetooth    
开启蓝牙。  
  
  
 **调用形式：**     
- enableBluetooth(): void  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
    
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
    access.enableBluetooth();  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
```  
    
```    
  
    
## disableBluetooth    
关闭蓝牙。  
 **调用形式：**     
- disableBluetooth(): void  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
    
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
    access.disableBluetooth();  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
## getState    
获取蓝牙开关状态。  
 **调用形式：**     
- getState(): BluetoothState  
  
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
| 2900001 | Service stopped. |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let state = access.getState();  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
## on('stateChange')    
订阅蓝牙设备开关状态事件。  
 **调用形式：**     
    
- on(type: 'stateChange', callback: Callback\<BluetoothState>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 | Operation failed. |  
    
 **示例代码：**   
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
  
    
## off('stateChange')    
取消订阅蓝牙设备开关状态事件。  
 **调用形式：**     
    
- off(type: 'stateChange', callback?: Callback\<BluetoothState>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 2900099 | Operation failed. |  
    
## BluetoothState    
枚举，蓝牙开关状态。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STATE_OFF | 0 | 表示蓝牙已关闭。<br/> |  
| STATE_TURNING_ON | 1 | 表示蓝牙正在打开。<br/> |  
| STATE_ON | 2 | 表示蓝牙已打开。<br/> |  
| STATE_TURNING_OFF | 3 | 表示蓝牙正在关闭。<br/> |  
| STATE_BLE_TURNING_ON | 4 | 表示蓝牙正在打开LE-only模式。<br/> |  
| STATE_BLE_ON | 5 | 表示蓝牙正处于LE-only模式。<br/> |  
| STATE_BLE_TURNING_OFF | 6 | 表示蓝牙正在关闭LE-only模式。 |  
