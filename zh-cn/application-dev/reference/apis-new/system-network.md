# @system.network    
> **说明**   
>本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import network from '@system.network';  
    
```  
    
## NetworkResponse  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | string | false | true | 是否按照流量计费。 |  
| metered | boolean | false | true | 网络类型，可能的值有2g，3g，4g，5g，wifi，none等。 |  
    
## Network  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
### getType  
 **调用形式：**     
- static getType(options?: {     /**      * Called when the network type is obtained.      * @syscap SystemCapability.Communication.NetManager.Core      * @since 3      */     success?: (data: NetworkResponse) => void;     /**      * Called when the network type fails to be obtained.      * @syscap SystemCapability.Communication.NetManager.Core      * @since 3      */     fail?: (data: any, code: number) => void;     /**      * Called when the execution is completed.      * @syscap SystemCapability.Communication.NetManager.Core      * @since 3      */     complete?: () => void;   }): void  
  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | {     /**      * Called when the network type is obtained.      * @syscap SystemCapability.Communication.NetManager.Core      * @since 3      */     success?: (data: NetworkResponse) => void;     /**      * Called when the network type fails to be obtained.      * @syscap SystemCapability.Communication.NetManager.Core      * @since 3      */     fail?: (data: any, code: number) => void;     /**      * Called when the execution is completed.      * @syscap SystemCapability.Communication.NetManager.Core      * @since 3      */     complete?: () => void;   } | false |  |  
    
### subscribe  
 **调用形式：**     
- static subscribe(options?: {     /**      * Called when the network connection state changes.      * @syscap SystemCapability.Communication.NetManager.Core      * @since 3      */     success?: (data: NetworkResponse) => void;     /**      * Called when the listening fails.      * @syscap SystemCapability.Communication.NetManager.Core      * @since 3      */     fail?: (data: any, code: number) => void;   }): void  
  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | {     /**      * Called when the network connection state changes.      * @syscap SystemCapability.Communication.NetManager.Core      * @since 3      */     success?: (data: NetworkResponse) => void;     /**      * Called when the listening fails.      * @syscap SystemCapability.Communication.NetManager.Core      * @since 3      */     fail?: (data: any, code: number) => void;   } | false |  |  
    
### unsubscribe  
 **调用形式：**     
- static unsubscribe(): void  
  
 **系统能力:**  SystemCapability.Communication.NetManager.Core    
 **示例代码：**   
```js    
export default {      
  unsubscribe() {          
    network.unsubscribe();      
  },  
}  
    
```    
  
