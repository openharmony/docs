# @ohos.bluetooth.baseProfile    
baseProfile模块提供了基础的profile方法。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import baseProfile from '@ohos.bluetooth.baseProfile'    
```  
    
## ConnectionStrategy    
枚举，表示Profile的连接策略。    
    
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CONNECTION_STRATEGY_UNSUPPORTED | 0 | 当设备未配对时的默认连接策略。<br/> |  
| CONNECTION_STRATEGY_ALLOWED | 1 | 设备允许接受或发起配对时的连接策略。<br/> |  
| CONNECTION_STRATEGY_FORBIDDEN | 2 | 设备不允许接受或发起配对时的连接策略。<br/> |  
    
## BaseProfile    
  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
### setConnectionStrategy    
设置该设备Profile的连接策略。  
 **调用形式：**     
    
- setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy): Promise\<void>    
起始版本： 10    
- setConnectionStrategy(deviceId: string, strategy: ConnectionStrategy, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
| strategy | ConnectionStrategy | true | Profile的连接策略。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当设置成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 返回promise对象。 |  
    
    
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
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
import a2dp from '@ohos.bluetooth.a2dp';  
try {  
    let a2dpSrc = a2dp.createA2dpSrcProfile();  
    a2dpSrc.setConnectionStrategy('XX:XX:XX:XX:XX:XX', 0, (err: BusinessError) => {  
        console.info('setConnectionStrategy, err: ' + JSON.stringify(err));  
    });  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
### getConnectionStrategy    
设置该设备Profile的连接策略。  
 **调用形式：**     
    
- getConnectionStrategy(deviceId: string, callback: AsyncCallback\<ConnectionStrategy>): void    
起始版本： 10    
- getConnectionStrategy(deviceId: string): Promise\<ConnectionStrategy>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
 **需要权限：** ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deviceId | string | true | 表示配对的远端设备地址，例如："XX:XX:XX:XX:XX:XX"。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | Profile的连接策略。 |  
| Promise<ConnectionStrategy> | 返回promise对象。 |  
    
    
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
import a2dp from '@ohos.bluetooth.a2dp';  
try {  
    let a2dpSrc = a2dp.createA2dpSrcProfile();  
    a2dpSrc.getConnectionStrategy('XX:XX:XX:XX:XX:XX', 0, (err: BusinessError, data: baseProfile.ConnectionStrategy) => {  
        console.info('getConnectionStrategy, err: ' + JSON.stringify(err) + ', data: ' + JSON.stringify(data));  
    });  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
