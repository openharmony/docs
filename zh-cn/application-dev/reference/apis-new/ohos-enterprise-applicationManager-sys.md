# @ohos.enterprise.applicationManager    
本模块提供应用管理能力，包括添加应用运行黑名单、获取应用运行黑名单、移除应用运行黑名单等。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import applicationManager from '@ohos.enterprise.applicationManager'    
```  
    
## addDisallowedRunningBundles    
指定设备管理应用添加应用至应用运行黑名单，添加至黑名单的应用不允许在指定用户（通过userId指定）下运行，否则允许运行。  
 **调用形式：**     
    
- addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。                  |  
| appIds | Array<string> | true | 应用ID数组，指定具体应用。                  | |  
| userId | number | true | 用户ID，指定具体用户。取值范围：大于等于0。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当指定设备管理应用添加应用运行黑名单失败时，会抛出错误对象。 |  
    
    
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
let appIds: Array<string> = ['com.example.myapplication'];  
  
applicationManager.addDisallowedRunningBundles(wantTemp, appIds, 100, (err) => {  
  if (err) {  
    console.error(`Failed to add disallowed running bundles. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('Succeeded in adding disallowed running bundles');  
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
let appIds: Array<string> = ['com.example.myapplication'];  
  
applicationManager.addDisallowedRunningBundles(wantTemp, appIds, 100).then(() => {  
  console.info('Succeeded in adding disallowed running bundles');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to add disallowed running bundles. Code is ${err.code}, message is ${err.message}`);  
});  
    
```    
  
    
## removeDisallowedRunningBundles    
指定当前/指定用户下的设备管理应用在应用运行黑名单中移除应用  
 **调用形式：**     
    
- removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback\<void>): void    
起始版本： 10    
- removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。                   |  
| appIds | Array<string> | true | 应用ID数组，指定具体应用。                   |  
| userId | number | true | 用户ID，取值范围：大于等于0。<br> - 调用接口时，若传入userId，表示指定用户。<br> - 调用接口时，若未传入userId，表示当前用户。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | the administrator application does not have permission to manage the device. |  
    
    
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
let appIds: Array<string> = ['com.example.myapplication'];  
  
applicationManager.removeDisallowedRunningBundles(wantTemp, appIds, 100, (err) => {  
  if (err) {  
    console.error(`Failed to remove disallowed running bundles. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('Succeeded in removing disallowed running bundles');  
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
let appIds: Array<string> = ['com.example.myapplication'];  
  
applicationManager.removeDisallowedRunningBundles(wantTemp, appIds, 100).then(() => {  
  console.info('Succeeded in removing disallowed running bundles');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to remove disallowed running bundles. Code is ${err.code}, message is ${err.message}`);  
});  
    
```    
  
    
## getDisallowedRunningBundles    
指定设备管理应用获取当前/指定用户下的应用运行黑名单  
 **调用形式：**     
    
- getDisallowedRunningBundles(admin: Want, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 10    
- getDisallowedRunningBundles(admin: Want, userId: number, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 10    
- getDisallowedRunningBundles(admin: Want, userId?: number): Promise\<Array\<string>>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。  |  
| userId | number | true | 用户ID，取值范围：大于等于0。<br> - 调用接口时，若传入userId，表示指定用户。<br> - 调用接口时，若未传入userId，表示当前用户。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当接口调用成功，err为null，否则为错误对象。 |  
| Promise<Array<string>> | Promise对象，返回当前用户下的应用运行黑名单。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device.                        | |  
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
  
applicationManager.getDisallowedRunningBundles(wantTemp, 100, (err, result) => {  
  if (err) {  
    console.error(`Failed to get disallowed running bundles. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in getting disallowed running bundles, result : ${JSON.stringify(result)}`);  
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
  
applicationManager.getDisallowedRunningBundles(wantTemp, 100).then((result) => {  
  console.info(`Succeeded in getting disallowed running bundles, result : ${JSON.stringify(result)}`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to get disallowed running bundles. Code is ${err.code}, message is ${err.message}`);  
});  
    
```    
  
