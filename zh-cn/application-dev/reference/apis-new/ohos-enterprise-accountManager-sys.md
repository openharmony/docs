# @ohos.enterprise.accountManager    
本模块提供设备帐户管理能力，包括禁止创建本地用户等。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import accountManager from '@ohos.enterprise.accountManager'    
```  
    
## disallowAddLocalAccount    
指定设备管理应用禁止设备创建本地用户。  
 **调用形式：**     
    
- disallowAddLocalAccount(admin: Want, disallow: boolean, callback: AsyncCallback\<void>): void    
起始版本： 10    
- disallowAddLocalAccount(admin: Want, disallow: boolean): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。  |  
| disallow | boolean | true | 是否禁止创建本地用户，true表示禁止创建，false表示允许创建。                  。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当禁止创建本地用户失败时，抛出错误对象。 | |  
    
    
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
import Want from '@ohos.app.ability.Want';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
accountManager.disallowAddLocalAccount(wantTemp, true, (err) => {  
  if (err) {  
    console.error(`Failed to disallow add local account. Code: ${err.code}, message: ${err.message}`);  
    return;  
  }  
  console.info('Succeeded in disallowing add local account');  
});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import Want from '@ohos.app.ability.Want';  
import { BusinessError } from '@ohos.base';  
let wantTemp: Want = {  
  bundleName: 'com.example.myapplication',  
  abilityName: 'EntryAbility',  
};  
  
accountManager.disallowAddLocalAccount(wantTemp, true).then(() => {  
  console.info('Succeeded in disallowing add local account');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to disallow add local account. Code: ${err.code}, message: ${err.message}`);  
});  
    
```    
  
