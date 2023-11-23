# @ohos.bluetooth.a2dp    
a2dp模块提供了访问蓝牙音频接口的方法。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import a2dp from '@ohos.bluetooth.a2dp'    
```  
    
## createA2dpSrcProfile    
创建a2dp profile实例。  
 **调用形式：**     
- createA2dpSrcProfile(): A2dpSourceProfile  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| A2dpSourceProfile | 返回该profile的实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
try {  
    let a2dpProfile = a2dp.createA2dpSrcProfile();  
    console.info('a2dp success');  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
## A2dpSourceProfile    
使用A2dpSourceProfile方法之前需要创建该类的实例进行操作，通过createA2dpSrcProfile()方法构造此实例。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### getPlayingState    
获取设备的播放状态。  
 **调用形式：**     
- getPlayingState(deviceId: string): PlayingState  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 远端设备地址。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PlayingState | 远端设备的播放状态。 |  
    
    
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
```ts    
import { BusinessError } from '@ohos.base';  
try {  
    let a2dpSrc = a2dp.createA2dpSrcProfile();  
    let state = a2dpSrc.getPlayingState('XX:XX:XX:XX:XX:XX');  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
## PlayingState    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| STATE_NOT_PLAYING | 0 | 表示未播放。 |  
| STATE_PLAYING | 1 | 表示正在播放。 |  
