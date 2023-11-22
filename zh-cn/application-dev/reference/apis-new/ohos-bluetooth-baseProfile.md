# @ohos.bluetooth.baseProfile    
baseProfile模块提供了基础的profile方法。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import baseProfile from '@ohos.bluetooth.baseProfile'    
```  
    
## StateChangeParam    
描述profile状态改变参数。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| deviceId | string | false | true |  |  
| state | ProfileConnectionState | false | true |  |  
    
## BaseProfile    
  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### getConnectedDevices    
获取已连接设备列表。  
 **调用形式：**     
- getConnectedDevices(): Array\<string>  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 返回当前已连接设备的地址。 |  
    
    
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
import a2dp from '@ohos.bluetooth.a2dp';  
try {  
    let a2dpSrc = a2dp.createA2dpSrcProfile();  
    let retArray = a2dpSrc.getConnectedDevices();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError).code + ",errMessage:" + (err as BusinessError).message);  
}  
    
```    
  
    
### getConnectionState    
获取设备profile的连接状态。  
 **调用形式：**     
- getConnectionState(deviceId: string): ProfileConnectionState  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 远端设备地址。<br/> |  
    
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
import a2dp from '@ohos.bluetooth.a2dp';  
try {  
    let a2dpSrc = a2dp.createA2dpSrcProfile();  
    let ret = a2dpSrc.getConnectionState('XX:XX:XX:XX:XX:XX');  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
### on('connectionStateChange')    
订阅连接状态变化事件。  
 **调用形式：**     
    
- on(type: 'connectionStateChange', callback: Callback\<StateChangeParam>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 填写"connectionStateChange"字符串，表示连接状态变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示回调函数的入参。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
import a2dp from '@ohos.bluetooth.a2dp';  
function onReceiveEvent(data: baseProfile.StateChangeParam) {  
    console.info('a2dp state = '+ JSON.stringify(data));  
}  
try {  
    let a2dpSrc = a2dp.createA2dpSrcProfile();  
    a2dpSrc.on('connectionStateChange', onReceiveEvent);  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
### off('connectionStateChange')    
取消订阅连接状态变化事件。  
 **调用形式：**     
    
- off(type: 'connectionStateChange', callback?: Callback\<StateChangeParam>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 填写"connectionStateChange"字符串，表示连接状态变化事件。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 表示回调函数的入参。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
import a2dp from '@ohos.bluetooth.a2dp';  
function onReceiveEvent(data: baseProfile.StateChangeParam) {  
    console.info('a2dp state = '+ JSON.stringify(data));  
}  
try {  
    let a2dpSrc = a2dp.createA2dpSrcProfile();  
    a2dpSrc.on('connectionStateChange', onReceiveEvent);  
    a2dpSrc.off('connectionStateChange', onReceiveEvent);  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
