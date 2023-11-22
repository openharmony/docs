# @ohos.enterprise.deviceControl    
本模块提供设备控制能力。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import deviceControl from '@ohos.enterprise.deviceControl'    
```  
    
## resetFactory    
指定设备管理应用使设备恢复出厂设置。  
 **调用形式：**     
    
- resetFactory(admin: Want, callback: AsyncCallback\<void>): void    
起始版本： 10    
- resetFactory(admin: Want): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_RESET_DEVICE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当恢复出厂设置失败时抛出错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
| 9200002 | the administrator application does not have permission to manage the device. |  
| 201 |  |  
| 202 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import deviceControl from '@ohos.enterprise.deviceControl';  
import Want from '@ohos.app.ability.Want';  
  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
deviceControl.resetFactory(wantTemp, (err) => {  
  if (err) {  
    console.error(`Failed to reset factory. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.log('Succeeded in resetting factory');  
})    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import deviceControl from '@ohos.enterprise.deviceControl';  
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
deviceControl.resetFactory(wantTemp).then(() => {  
}).catch((err: BusinessError) => {  
  console.error(`Failed to reset factory. Code is ${err.code}, message is ${err.message}`);  
})  
    
```    
  
