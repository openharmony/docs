# @ohos.bluetooth.pan    
pan模块提供了访问蓝牙个人区域网相关功能的方法。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import pan from '@ohos.bluetooth.pan'    
```  
    
## createPanProfile    
创建pan profile实例。  
 **调用形式：**     
- createPanProfile(): PanProfile  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PanProfile | 返回该profile的实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
```js    
import { BusinessError } from '@ohos.base';  
try {  
    let panProfile : pan.PanProfile= pan.createPanProfile();  
    console.info('pan success');  
} catch (err) {  
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);  
}  
    
```    
  
    
## PanProfile    
使用PanProfile方法之前需要创建该类的实例进行操作，通过createPanProfile()方法构造此实例。  
  
 **系统能力:**  SystemCapability.Communication.Bluetooth.Core  
