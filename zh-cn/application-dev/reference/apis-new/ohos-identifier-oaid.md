# @ohos.identifier.oaid    
本模块提供开放匿名设备标识符（Open Anonymous Device Identifier, OAID，以下简称OAID）的获取和重置能力。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import identifier from '@ohos.identifier.oaid'    
```  
    
## getOAID    
获取开放匿名设备标识符（Open Anonymous Device Identifier, OAID）。  
 **调用形式：**     
    
- getOAID(callback: AsyncCallback\<string>): void    
起始版本： 10    
- getOAID(): Promise\<string>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Advertising.OAID  
 **需要权限：** ohos.permission.APP_TRACKING_CONSENT    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取开放匿名设备标识符（Open Anonymous Device Identifier, OAID）的回调函数。 |  
| Promise<string> | Promise对象。返回开放匿名设备标识符（Open Anonymous Device Identifier, OAID）。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17300001 | System internal error. |  
    
 **示例代码1：**   
示例：(callback)  
```js    
import identifier from '@ohos.identifier.oaid';  
import hilog from '@ohos.hilog';  
import { BusinessError } from '@ohos.base';  
  
try {  
identifier.getOAID((err: BusinessError, data) => {  
if (err.code) {  
hilog.info(0x0000, 'testTag', '%{public}s', `get oaid failed, message: ${err.message}`);  
} else {  
const oaid: string = data;  
hilog.info(0x0000, 'testTag', '%{public}s', `get oaid by callback success`);  
}  
});  
} catch (err) {  
hilog.error(0x0000, 'testTag', 'get oaid catch error: %{public}d %{public}s', err.code, err.message);  
}  
    
```    
  
    
 **示例代码2：**   
示例：(promise)  
```js    
import identifier from '@ohos.identifier.oaid';  
import hilog from '@ohos.hilog';   
import { BusinessError } from '@ohos.base';  
   
try {    
  identifier.getOAID().then((data) => {  
    const oaid: string = data;  
    hilog.info(0x0000, 'testTag', '%{public}s', `get oaid by promise success`);  
  }).catch((err: BusinessError) => {  
    hilog.info(0x0000, 'testTag', '%{public}s', `get oaid failed, message: ${err.message}`);  
  })  
} catch (err) {  
  hilog.error(0x0000, 'testTag', 'get oaid catch error: %{public}d %{public}s', err.code, err.message);  
}  
    
```    
  
