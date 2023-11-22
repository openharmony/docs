# @ohos.bluetooth.hfp    
hfp模块提供了访问蓝牙呼叫接口的方法。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import hfp from '@ohos.bluetooth.hfp'    
```  
    
## HandsFreeAudioGatewayProfile    
使用HandsFreeAudioGatewayProfile方法之前需要创建该类的实例进行操作，通过createHfpAgProfile()方法构造此实例。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### connect    
连接设备的HFP服务。  
 **调用形式：**     
- connect(deviceId: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 远端设备地址。<br/> |  
    
    
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
    let hfpAg = hfp.createHfpAgProfile();  
    hfpAg.connect('XX:XX:XX:XX:XX:XX');  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
### disconnect    
断开连接设备的HFP服务。  
 **调用形式：**     
- disconnect(deviceId: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 远端设备地址。<br/> |  
    
    
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
    let hfpAg = hfp.createHfpAgProfile();  
    hfpAg.disconnect('XX:XX:XX:XX:XX:XX');  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
