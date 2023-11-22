# @ohos.enterprise.browser    
本模块提供浏览器管理能力，包括设置/取消浏览器策略、获取浏览器策略等。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import browser from '@ohos.enterprise.browser'    
```  
    
## setPolicies    
指定设备管理应用为指定的浏览器设置浏览策略  
 **调用形式：**     
    
- setPolicies(admin: Want, appId: string, policies: string, callback: AsyncCallback\<void>): void    
起始版本： 10    
- setPolicies(admin: Want, appId: string, policies: string): Promise\<void>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager  
 **需要权限：** ohos.permission.ENTERPRISE_SET_BROWSER_POLICY    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。                   |  
| appId | string | true | 应用ID，用于指定浏览器。                   |  
| policies | string | true | 浏览器策略，当参数policies为空字符串时，表示取消指定浏览器的策略。                   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当接口调用成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。当指定设备管理应用设置浏览器策略失败时，会抛出错误对象。 |  
    
    
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
let appId: string = 'com.example.myapplication';  
let policies: string = '{"InsecurePrivateNetworkRequestsAllowed":{"level":"mandatory","scope":"machine","source":"platform","value":true},"LegacySameSiteCookieBehaviorEnabledForDomainList":{"level":"mandatory","scope":"machine","source":"platform","value":["[*.]"]}}'  
browser.setPolicies(wantTemp, appId, policies, (err) => {  
  if (err) {  
    console.error(`Failed to set browser policies. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info('Succeeded in setting browser policies');  
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
let appId: string = 'com.example.myapplication';  
let policies: string = '{"InsecurePrivateNetworkRequestsAllowed":{"level":"mandatory","scope":"machine","source":"platform","value":true},"LegacySameSiteCookieBehaviorEnabledForDomainList":{"level":"mandatory","scope":"machine","source":"platform","value":["[*.]"]}}'  
browser.setPolicies(wantTemp, appId, policies).then(() => {  
  console.info('Succeeded in setting browser policies');  
}).catch((err: BusinessError) => {  
  console.error(`Failed to set browser policies. Code is ${err.code}, message is ${err.message}`);  
});  
    
```    
  
    
## getPolicies    
指定管理员应用获取指定浏览器的策略  
 **调用形式：**     
    
- getPolicies(admin: Want, appId: string, callback: AsyncCallback\<string>): void    
起始版本： 10    
- getPolicies(admin: Want, appId: string): Promise\<string>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Customization.EnterpriseDeviceManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| admin | Want | true | 设备管理应用。 。 |  
| appId | string | true | 应用ID，用于指定浏览器。              |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，当接口调用成功，err为null，否则为错误对象。 |  
| Promise<string> | Promise对象，返回浏览器策略。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 9200001 | the application is not an administrator of the device. |  
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
let appId: string = 'com.example.myapplication';  
browser.getPolicies(wantTemp, appId, (err, result) => {  
  if (err) {  
    console.error(`Failed to get browser policies. Code is ${err.code}, message is ${err.message}`);  
    return;  
  }  
  console.info(`Succeeded in getting  browser policies, result : ${JSON.stringify(result)}`);  
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
let appId: string = 'com.example.myapplication';  
browser.getPolicies(wantTemp, appId).then((result) => {  
  console.info(`Succeeded in getting browser policies, result : ${JSON.stringify(result)}`);  
}).catch((err: BusinessError) => {  
  console.error(`Failed to get browser policies. Code is ${err.code}, message is ${err.message}`);  
});  
    
```    
  
