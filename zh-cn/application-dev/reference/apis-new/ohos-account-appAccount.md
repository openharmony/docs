# @ohos.account.appAccount    
本模块提供应用帐号信息的添加、删除、修改和查询基础能力，并支持应用间鉴权和分布式数据同步功能。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import appAccount from '@ohos.account.appAccount'    
```  
    
## createAppAccountManager    
  
  
创建应用帐号管理器对象。  
 **调用形式：**     
- createAppAccountManager(): AppAccountManager  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AppAccountManager | 应用帐号管理器对象。 |  
    
 **示例代码：**   
```ts    
let appAccountManager = account_appAccount.createAppAccountManager();    
```    
  
    
## AppAccountManager    
应用帐号管理器类。  
 **系统能力:**  SystemCapability.Account.AppAccount    
### addAccount<sup>(deprecated)</sup>    
根据帐号名添加应用帐号。使用callback异步回调。  
 **调用形式：**     
- addAccount(name: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#createAccount。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当创建成功时，err为null，否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.addAccount('WangWu', (err: BusinessError) => {   
    console.log('addAccount err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### addAccount<sup>(deprecated)</sup>    
根据帐号名添加应用帐号。使用callback异步回调。  
 **调用形式：**     
- addAccount(name: string, extraInfo: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#createAccount。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。  |  
| extraInfo<sup>(deprecated)</sup> | string | true | 额外信息(能转换string类型的其它信息)，额外信息不能是应用帐号的敏感信息（如应用帐号密码、token等）。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当创建成功时，err为null，否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.addAccount('LiSi', 'token101', (err: BusinessError) => {   
  console.log('addAccount err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### addAccount<sup>(deprecated)</sup>    
根据帐号名添加应用帐号。使用callback异步回调。  
 **调用形式：**     
- addAccount(name: string, extraInfo?: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#createAccount。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。  |  
| extraInfo<sup>(deprecated)</sup> | string | false | 额外信息(能转换string类型的其它信息)，额外信息不能是应用帐号的敏感信息（如应用帐号密码、token等）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.addAccount('LiSi', 'token101').then(()=> {   
  console.log('addAccount Success');  
}).catch((err: BusinessError) => {  
  console.log('addAccount err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### createAccount<sup>(9+)</sup>    
根据帐号名创建应用帐号。使用callback异步回调。  
 **调用形式：**     
    
- createAccount(name: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- createAccount(name: string, options: CreateAccountOptions, callback: AsyncCallback\<void>): void    
起始版本： 9    
- createAccount(name: string, options?: CreateAccountOptions): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。  |  
| options | CreateAccountOptions | true | 创建应用帐号的选项，可提供自定义数据，但不建议包含敏感数据（如密码、Token等）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当创建成功时，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name or options. |  
| 12300004 | Account already exists. |  
| 12300007 | The number of accounts reaches the upper limit. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.createAccount('WangWu', (err: BusinessError) => {   
      console.log('createAccount err: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('createAccount err: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let options: account_appAccount.CreateAccountOptions = {  
  customData: {  
    age: '10'  
  }  
}  
try {  
  appAccountManager.createAccount('LiSi', options).then(() => {  
    console.log('createAccount successfully');  
  }).catch((err: BusinessError) => {  
    console.log('createAccount failed, error: ' + JSON.stringify(err));  
  });  
} catch(err) {  
  console.log('createAccount exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### addAccountImplicitly<sup>(deprecated)</sup>  
 **调用形式：**     
- addAccountImplicitly(       owner: string,       authType: string,       options: { [key: string]: any },       callback: AuthenticatorCallback     ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#createAccountImplicitly。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| owner<sup>(deprecated)</sup> | string | true |  |  
| authType<sup>(deprecated)</sup> | string | true |  |  
| options<sup>(deprecated)</sup> | { [key: string]: any } | true |  |  
| callback<sup>(deprecated)</sup> | AuthenticatorCallback | true |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import Want from '@ohos.app.ability.Want';  
import common from '@ohos.app.ability.common';  
  
let context = getContext(this) as common.UIAbilityContext; // UIAbilityContext  
  
function onResultCallback(code: number, result: Record<string, Object>): void {  
  console.log('resultCode: ' + code);  
  console.log('result: ' + JSON.stringify(result));  
}  
  
function onRequestRedirectedCallback(request: Want): void {  
  let wantInfo: Want = {  
    deviceId: '',  
    bundleName: 'com.example.accountjsdemo',  
    action: 'ohos.want.action.viewData',  
    entities: ['entity.system.default'],  
  }  
  context.startAbility(wantInfo).then(() => {  
    console.log('startAbility successfully');  
  }).catch((err: BusinessError) => {  
    console.log('startAbility err: ' + JSON.stringify(err));  
  })  
}  
  
appAccountManager.addAccountImplicitly('com.example.accountjsdemo', 'getSocialData', {}, {  
  onResult: onResultCallback,  
  onRequestRedirected: onRequestRedirectedCallback  
});  
    
```    
  
    
### createAccountImplicitly<sup>(9+)</sup>    
根据指定的帐号所有者和可选项隐式地创建应用帐号。使用callback异步回调。  
 **调用形式：**     
    
- createAccountImplicitly(owner: string, callback: AuthCallback): void    
起始版本： 9    
- createAccountImplicitly(owner: string, options: CreateAccountImplicitlyOptions, callback: AuthCallback): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| owner | string | true | 应用帐号所有者的包名。   |  
| options | CreateAccountImplicitlyOptions | true | 隐式创建帐号的选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 认证器回调对象，返回创建结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid owner or options. |  
| 12300007 | The number of accounts reaches the upper limit. |  
| 12300010 | Account service busy. |  
| 12300113 | Authenticator service not found. |  
| 12300114 | Authenticator service exception. |  
    
### deleteAccount<sup>(deprecated)</sup>    
删除应用帐号。使用callback异步回调。  
 **调用形式：**     
- deleteAccount(name: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#removeAccount。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true |  应用帐号的名称。  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当删除成功时，err为null，否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.deleteAccount('ZhaoLiu', (err: BusinessError) => {   
    console.log('deleteAccount err: ' + JSON.stringify(err));  
 });  
    
```    
  
    
### deleteAccount<sup>(deprecated)</sup>    
删除应用帐号。使用callback异步回调。  
 **调用形式：**     
- deleteAccount(name: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#removeAccount。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true |  应用帐号的名称。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.deleteAccount('ZhaoLiu').then(() => {   
      console.log('deleteAccount Success');  
 }).catch((err: BusinessError) => {  
    console.log('deleteAccount err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### removeAccount<sup>(9+)</sup>    
删除应用帐号。使用callback异步回调。  
 **调用形式：**     
    
- removeAccount(name: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- removeAccount(name: string): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。    |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当删除成功时，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name. |  
| 12300003 | Account not found. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.removeAccount('ZhaoLiu', (err: BusinessError) => {  
    if (err) {  
      console.log('removeAccount failed, error: ' + JSON.stringify(err));  
    } else {  
      console.log('removeAccount successfully');  
    }  
 });  
} catch(err) {  
  console.log('removeAccount exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### disableAppAccess<sup>(deprecated)</sup>    
禁止指定第三方应用帐号名称对指定的第三方应用进行访问。使用callback异步回调。  
 **调用形式：**     
- disableAppAccess(name: string, bundleName: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#setAppAccess。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。 |  
| bundleName<sup>(deprecated)</sup> | string | true | 第三方应用的包名。   |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当禁止指定第三方应用帐号名称对指定包名称的第三方应用进行访问设置成功时，err为null，否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.disableAppAccess('ZhangSan', 'com.example.accountjsdemo', (err: BusinessError) => {   
    console.log('disableAppAccess err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### disableAppAccess<sup>(deprecated)</sup>    
禁止指定第三方应用帐号名称对指定的第三方应用进行访问。使用callback异步回调。  
 **调用形式：**     
- disableAppAccess(name: string, bundleName: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#setAppAccess。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。 |  
| bundleName<sup>(deprecated)</sup> | string | true | 第三方应用的包名。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.disableAppAccess('ZhangSan', 'com.example.accountjsdemo').then(() => {   
    console.log('disableAppAccess Success');  
}).catch((err: BusinessError) => {  
    console.log('disableAppAccess err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### enableAppAccess<sup>(deprecated)</sup>    
允许指定第三方应用帐号名称对指定包名称的第三方应用进行访问。使用callback异步回调。  
 **调用形式：**     
- enableAppAccess(name: string, bundleName: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#setAppAccess。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。  |  
| bundleName<sup>(deprecated)</sup> | string | true | 第三方应用的包名。   |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当允许指定第三方应用帐号名称对指定包名称的第三方应用进行访问设置成功时，err为null，否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.enableAppAccess('ZhangSan', 'com.example.accountjsdemo', (err: BusinessError) => {   
    console.log('enableAppAccess: ' + JSON.stringify(err));  
 });  
    
```    
  
    
### enableAppAccess<sup>(deprecated)</sup>    
允许指定第三方应用帐号名称对指定包名称的第三方应用进行访问。使用callback异步回调。  
 **调用形式：**     
- enableAppAccess(name: string, bundleName: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#setAppAccess。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。  |  
| bundleName<sup>(deprecated)</sup> | string | true | 第三方应用的包名。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.enableAppAccess('ZhangSan', 'com.example.accountjsdemo').then(() => {   
     console.log('enableAppAccess Success');  
}).catch((err: BusinessError) => {  
    console.log('enableAppAccess err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setAppAccess<sup>(9+)</sup>    
设置指定应用对特定帐号的访问权限。使用callback异步回调。  
 **调用形式：**     
    
- setAppAccess(name: string, bundleName: string, isAccessible: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setAppAccess(name: string, bundleName: string, isAccessible: boolean): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。 |  
| bundleName | string | true | 第三方应用的包名。  |  
| isAccessible | boolean | true | 是否可访问。true表示允许访问，false表示禁止访问。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，如果设置成功，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name or bundleName. |  
| 12300003 | Account not found. |  
| 12400001 | Application not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.setAppAccess('ZhangSan', 'com.example.accountjsdemo', true, (err: BusinessError) => {  
    if (err) {  
      console.log('setAppAccess failed: ' + JSON.stringify(err));  
    } else {  
      console.log('setAppAccess successfully');  
    }  
  });  
} catch (err) {  
  console.log('setAppAccess exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.setAppAccess('ZhangSan', 'com.example.accountjsdemo', true).then(() => {  
    console.log('setAppAccess successfully');  
  }).catch((err: BusinessError) => {  
    console.log('setAppAccess failed: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('setAppAccess exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### checkAppAccess<sup>(9+)</sup>    
检查指定应用对特定帐号的数据是否可访问。使用callback异步回调。  
 **调用形式：**     
    
- checkAppAccess(name: string, bundleName: string, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- checkAppAccess(name: string, bundleName: string): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。 |  
| bundleName | string | true | 第三方应用的包名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示指定应用可访问特定帐号的数据；返回false表示不可访问。 |  
| Promise<boolean> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name or bundleName. |  
| 12300003 | Account not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.checkAppAccess('ZhangSan', 'com.example.accountjsdemo',  
    (err: BusinessError, isAccessible: boolean) => {  
      if (err) {  
        console.log('checkAppAccess failed, error: ' + JSON.stringify(err));  
      } else {  
        console.log('checkAppAccess successfully');  
      }  
    });  
} catch (err) {  
  console.log('checkAppAccess exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.checkAppAccess('ZhangSan', 'com.example.accountjsdemo').then((isAccessible: boolean) => {  
    console.log('checkAppAccess successfully, isAccessible: ' + isAccessible);  
  }).catch((err: BusinessError) => {  
    console.log('checkAppAccess failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('checkAppAccess exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### checkAppAccountSyncEnable<sup>(deprecated)</sup>    
检查指定应用帐号是否开启数据同步功能。使用callback异步回调。  
 **调用形式：**     
- checkAppAccountSyncEnable(name: string, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#checkDataSyncEnabled。  
 **系统能力:**  SystemCapability.Account.AppAccount  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true |  回调函数。返回true表示指定应用帐号已开启数据同步功能；返回false表示未开启。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.checkAppAccountSyncEnable('ZhangSan', (err: BusinessError, result: boolean) => {   
    console.log('checkAppAccountSyncEnable err: ' + JSON.stringify(err));  
    console.log('checkAppAccountSyncEnable result: ' + result);  
});  
    
```    
  
    
### checkAppAccountSyncEnable<sup>(deprecated)</sup>    
检查指定应用帐号是否开启数据同步功能。使用callback异步回调。  
 **调用形式：**     
- checkAppAccountSyncEnable(name: string): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#checkDataSyncEnabled。  
 **系统能力:**  SystemCapability.Account.AppAccount  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。返回true表示指定应用帐号已开启数据同步功能；返回false表示未开启。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.checkAppAccountSyncEnable('ZhangSan').then((data: boolean) => {   
    console.log('checkAppAccountSyncEnable, result: ' + data);  
}).catch((err: BusinessError) => {  
    console.log('checkAppAccountSyncEnable err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### checkDataSyncEnabled<sup>(9+)</sup>    
检查指定应用帐号是否开启数据同步功能。使用callback异步回调。  
 **调用形式：**     
    
- checkDataSyncEnabled(name: string, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- checkDataSyncEnabled(name: string): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示指定应用帐号已开启数据同步功能；返回false表示未开启。 |  
| Promise<boolean> | Promise对象。返回true表示指定应用帐号已开启数据同步功能；返回false表示未开启。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name. |  
| 12300003 | Account not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.checkDataSyncEnabled('ZhangSan', (err: BusinessError, isEnabled: boolean) => {  
    if (err) {  
      console.log('checkDataSyncEnabled failed, err: ' + JSON.stringify(err));  
    } else {  
      console.log('checkDataSyncEnabled successfully, isEnabled: ' + isEnabled);  
    }  
  });  
} catch (err) {  
  console.log('checkDataSyncEnabled err: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.checkDataSyncEnabled('ZhangSan').then((isEnabled: boolean) => {  
      console.log('checkDataSyncEnabled successfully, isEnabled: ' + isEnabled);  
  }).catch((err: BusinessError) => {  
    console.log('checkDataSyncEnabled failed, err: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('checkDataSyncEnabled err: ' + JSON.stringify(err));  
}  
    
```    
  
    
### setAccountCredential<sup>(deprecated)</sup>    
设置指定应用帐号的凭据。使用callback异步回调。  
 **调用形式：**     
- setAccountCredential(name: string, credentialType: string, credential: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#setCredential。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。  |  
| credentialType<sup>(deprecated)</sup> | string | true | 凭据类型。 |  
| credential<sup>(deprecated)</sup> | string | true | 凭据取值。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当设置此应用程序帐号的凭据成功时，err为null，否则为错误对象。 |  
    
 **示例代码：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.setAccountCredential('ZhangSan', 'credentialType001', 'credential001', (err: BusinessError) => {   
    console.log('setAccountCredential err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setAccountCredential<sup>(deprecated)</sup>    
设置指定应用帐号的凭据。使用callback异步回调。  
 **调用形式：**     
- setAccountCredential(name: string, credentialType: string, credential: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#setCredential。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。  |  
| credentialType<sup>(deprecated)</sup> | string | true | 凭据类型。 |  
| credential<sup>(deprecated)</sup> | string | true | 凭据取值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.setAccountCredential('ZhangSan', 'credentialType001', 'credential001').then(() => {   
    console.log('setAccountCredential Success');  
}).catch((err: BusinessError) => {  
    console.log('setAccountCredential err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setCredential<sup>(9+)</sup>    
设置指定应用帐号的凭据。使用callback异步回调  
 **调用形式：**     
    
- setCredential(name: string, credentialType: string, credential: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setCredential(name: string, credentialType: string, credential: string): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。 |  
| credentialType | string | true | 凭据类型。 |  
| credential | string | true | 凭据取值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当凭据设置成功时，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name, credentialType or credential |  
| 12300003 | Account not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.setCredential('ZhangSan', 'PIN_SIX', 'xxxxxx', (err: BusinessError) => {  
    if (err) {  
      console.log('setCredential failed, error: ' + JSON.stringify(err));  
    } else {  
      console.log('setCredential successfully');  
    }  
  });  
} catch (err) {  
  console.log('setCredential exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.setCredential('ZhangSan', 'PIN_SIX', 'xxxxxx').then(() => {  
    console.log('setCredential successfully');  
  }).catch((err: BusinessError) => {  
    console.log('setCredential failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('setCredential exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### setAccountExtraInfo<sup>(deprecated)</sup>    
设置指定应用帐号的额外信息。使用callback异步回调。  
 **调用形式：**     
- setAccountExtraInfo(name: string, extraInfo: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#setCustomData。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。 |  
| extraInfo<sup>(deprecated)</sup> | string | true | 额外信息(能转换string类型的其它信息)，额外信息不能是应用帐号的敏感信息（如应用帐号密码、token等）。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当设置成功时，err为null，否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.setAccountExtraInfo('ZhangSan', 'Tk002', (err: BusinessError) => {   
    console.log('setAccountExtraInfo err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setAccountExtraInfo<sup>(deprecated)</sup>    
设置指定应用帐号的额外信息。使用callback异步回调。  
 **调用形式：**     
- setAccountExtraInfo(name: string, extraInfo: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#setCustomData。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。 |  
| extraInfo<sup>(deprecated)</sup> | string | true | 额外信息(能转换string类型的其它信息)，额外信息不能是应用帐号的敏感信息（如应用帐号密码、token等）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.setAccountExtraInfo('ZhangSan', 'Tk002').then(() => {   
    console.log('setAccountExtraInfo Success');  
}).catch((err: BusinessError) => {  
    console.log('setAccountExtraInfo err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setAppAccountSyncEnable<sup>(deprecated)</sup>    
开启或禁止指定应用帐号的数据同步功能。使用callback异步回调。  
 **调用形式：**     
- setAppAccountSyncEnable(name: string, isEnable: boolean, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#setDataSyncEnabled。  
 **系统能力:**  SystemCapability.Account.AppAccount  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。 |  
| isEnable<sup>(deprecated)</sup> | boolean | true | 是否开启数据同步。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当开启或禁止成功时，err为null，否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.setAppAccountSyncEnable('ZhangSan', true, (err: BusinessError) => {   
    console.log('setAppAccountSyncEnable err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setAppAccountSyncEnable<sup>(deprecated)</sup>    
开启或禁止指定应用帐号的数据同步功能。使用callback异步回调。  
 **调用形式：**     
- setAppAccountSyncEnable(name: string, isEnable: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#setDataSyncEnabled。  
 **系统能力:**  SystemCapability.Account.AppAccount  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。 |  
| isEnable<sup>(deprecated)</sup> | boolean | true | 是否开启数据同步。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager .setAppAccountSyncEnable('ZhangSan', true).then(() => {   
    console.log('setAppAccountSyncEnable Success');  
}).catch((err: BusinessError) => {  
    console.log('setAppAccountSyncEnable err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setDataSyncEnabled<sup>(9+)</sup>    
开启或禁止指定应用帐号的数据同步功能。使用callback异步回调。  
 **调用形式：**     
    
- setDataSyncEnabled(name: string, isEnabled: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setDataSyncEnabled(name: string, isEnabled: boolean): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。 |  
| isEnabled | boolean | true | 是否开启数据同步。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当开启或禁止成功时，err为null，否则为错误对象 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name. |  
| 12300003 | Account not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    appAccountManager.setDataSyncEnabled('ZhangSan', true, (err: BusinessError) => {   
        console.log('setDataSyncEnabled err: ' + JSON.stringify(err));  
    });  
} catch (err) {  
    console.log('setDataSyncEnabled err: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    appAccountManager .setDataSyncEnabled('ZhangSan', true).then(() => {   
        console.log('setDataSyncEnabled Success');  
    }).catch((err: BusinessError) => {  
        console.log('setDataSyncEnabled err: ' + JSON.stringify(err));  
    });  
} catch (err) {  
    console.log('setDataSyncEnabled err: ' + JSON.stringify(err));  
}  
    
```    
  
    
### setAssociatedData<sup>(deprecated)</sup>    
设置指定应用帐号的关联数据。使用callback异步回调。  
 **调用形式：**     
- setAssociatedData(name: string, key: string, value: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#setCustomData。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。 |  
| key<sup>(deprecated)</sup> | string | true | 关联数据的键名 |  
| value<sup>(deprecated)</sup> | string | true | 关联数据的取值。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当设置与此应用帐号关联的数据成功时，err为null，否则为错误对象 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.setAssociatedData('ZhangSan', 'k001', 'v001', (err: BusinessError) => {   
    console.log('setAssociatedData err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setAssociatedData<sup>(deprecated)</sup>    
设置指定应用帐号的关联数据。使用callback异步回调。  
 **调用形式：**     
- setAssociatedData(name: string, key: string, value: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#setCustomData。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。 |  
| key<sup>(deprecated)</sup> | string | true | 关联数据的键名 |  
| value<sup>(deprecated)</sup> | string | true | 关联数据的取值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.setAssociatedData('ZhangSan', 'k001', 'v001').then(() => {   
    console.log('setAssociatedData Success');  
}).catch((err: BusinessError) => {  
    console.log('setAssociatedData err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### setCustomData<sup>(9+)</sup>    
设置指定应用帐号的自定义数据。使用callback异步回调。  
 **调用形式：**     
    
- setCustomData(name: string, key: string, value: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setCustomData(name: string, key: string, value: string): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。 |  
| key | string | true | 自定义数据的键名 |  
| value | string | true | 自定义数据的取值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当设置自定义数据成功时，err为null，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name, key or value. |  
| 12300003 | Account not found. |  
| 12400003 | The number of custom data reaches the upper limit. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.setCustomData('ZhangSan', 'age', '12', (err: BusinessError) => {  
    if (err) {  
      console.log('setCustomData failed, error: ' + JSON.stringify(err));  
    } else {  
      console.log('setCustomData successfully');  
    }  
  });  
} catch (err) {  
  console.log('setCustomData exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.setCustomData('ZhangSan', 'age', '12').then(() => {  
    console.log('setCustomData successfully');  
  }).catch((err: BusinessError) => {  
    console.log('setCustomData failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('setCustomData exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### getAllAccessibleAccounts<sup>(deprecated)</sup>    
获取所有可访问的应用帐号信息。使用callback异步回调。  
 **调用形式：**     
- getAllAccessibleAccounts(callback: AsyncCallback\<Array\<AppAccountInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getAllAccounts。  
 **系统能力:**  SystemCapability.Account.AppAccount  
 **需要权限：** ohos.permission.GET_ALL_APP_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<AppAccountInfo>> | true | 回调函数。当查询成功时，err为null，data为获取到的应用帐号信息列表；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getAllAccessibleAccounts((err: BusinessError, data: account_appAccount.AppAccountInfo[])=>{  
	console.debug('getAllAccessibleAccounts err: ' + JSON.stringify(err));  
	console.debug('getAllAccessibleAccounts data: ' + JSON.stringify(data));  
});  
    
```    
  
    
### getAllAccessibleAccounts<sup>(deprecated)</sup>    
获取所有可访问的应用帐号信息。使用callback异步回调。  
 **调用形式：**     
- getAllAccessibleAccounts(): Promise\<Array\<AppAccountInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getAllAccounts。  
 **系统能力:**  SystemCapability.Account.AppAccount  
 **需要权限：** ohos.permission.GET_ALL_APP_ACCOUNTS    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<AppAccountInfo>> | Promise对象，返回全部应用已授权帐号信息对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getAllAccessibleAccounts().then((data: account_appAccount.AppAccountInfo[]) => {   
     console.log('getAllAccessibleAccounts: ' + data);  
}).catch((err: BusinessError) => {  
    console.log('getAllAccessibleAccounts err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getAllAccounts<sup>(9+)</sup>    
根据应用帐号所有者获取调用方可访问的应用帐号列表。使用callback异步回调。  
 **调用形式：**     
    
- getAllAccounts(callback: AsyncCallback\<Array\<AppAccountInfo>>): void    
起始版本： 9    
- getAllAccounts(): Promise\<Array\<AppAccountInfo>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Array<AppAccountInfo>> | Promise对象，返回指定应用全部帐号信息对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 |  |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
const selfBundle = 'com.example.actsgetallaaccounts';  
appAccountManager.getAllAccounts(selfBundle, (err: BusinessError, data: account_appAccount.AppAccountInfo[])=>{  
	console.debug('getAllAccounts err: ' + JSON.stringify(err));  
	console.debug('getAllAccounts data:' + JSON.stringify(data));  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
const selfBundle = 'com.example.actsgetallaaccounts';  
appAccountManager.getAllAccounts(selfBundle).then((data: account_appAccount.AppAccountInfo[]) => {   
     console.log('getAllAccounts: ' + data);  
}).catch((err: BusinessError) => {  
    console.log('getAllAccounts err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getAllAccounts<sup>(deprecated)</sup>    
根据应用帐号所有者获取调用方可访问的应用帐号列表。使用callback异步回调。  
 **调用形式：**     
- getAllAccounts(owner: string, callback: AsyncCallback\<Array\<AppAccountInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getAccountsByOwner。  
 **系统能力:**  SystemCapability.Account.AppAccount  
 **需要权限：** ohos.permission.GET_ALL_APP_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| owner<sup>(deprecated)</sup> | string | true | 应用帐号信息列表。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<AppAccountInfo>> | true | 应用帐号信息列表。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
const selfBundle = 'com.example.actsgetallaaccounts';  
appAccountManager.getAllAccounts(selfBundle, (err: BusinessError, data: account_appAccount.AppAccountInfo[])=>{  
	console.debug('getAllAccounts err: ' + JSON.stringify(err));  
	console.debug('getAllAccounts data:' + JSON.stringify(data));  
});  
    
```    
  
    
### getAllAccounts<sup>(deprecated)</sup>    
根据应用帐号所有者获取调用方可访问的应用帐号列表。使用callback异步回调。  
 **调用形式：**     
- getAllAccounts(owner: string): Promise\<Array\<AppAccountInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getAccountsByOwner。  
 **系统能力:**  SystemCapability.Account.AppAccount  
 **需要权限：** ohos.permission.GET_ALL_APP_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| owner<sup>(deprecated)</sup> | string | true | 应用帐号信息列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<AppAccountInfo>> | Promise对象，返回指定应用全部帐号信息对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
const selfBundle = 'com.example.actsgetallaaccounts';  
appAccountManager.getAllAccounts(selfBundle).then((data: account_appAccount.AppAccountInfo[]) => {   
     console.log('getAllAccounts: ' + data);  
}).catch((err: BusinessError) => {  
    console.log('getAllAccounts err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getAccountsByOwner<sup>(9+)</sup>    
根据应用帐号所有者获取调用方可访问的应用帐号列表。使用callback异步回调。  
 **调用形式：**     
    
- getAccountsByOwner(owner: string, callback: AsyncCallback\<Array\<AppAccountInfo>>): void    
起始版本： 9    
- getAccountsByOwner(owner: string): Promise\<Array\<AppAccountInfo>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| owner | string | true | 应用帐号所有者的包名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果获取成功，err为null，data为获取到的应用帐号列表；否则为错误对象。 |  
| Promise<Array<AppAccountInfo>> | Promise对象，返回获取到的应用帐号列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid owner. |  
| 12400001 | Application not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.getAccountsByOwner('com.example.accountjsdemo2',  
    (err: BusinessError, data: account_appAccount.AppAccountInfo[]) => {  
      if (err) {  
        console.debug('getAccountsByOwner failed, error:' + JSON.stringify(err));  
      } else {  
        console.debug('getAccountsByOwner successfully, data:' + JSON.stringify(data));  
      }  
    });  
} catch (err) {  
  console.debug('getAccountsByOwner exception:' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.getAccountsByOwner('com.example.accountjsdemo2').then((  
    data: account_appAccount.AppAccountInfo[]) => {  
    console.debug('getAccountsByOwner successfully, data: ' + JSON.stringify(data));  
  }).catch((err: BusinessError) => {  
    console.debug('getAccountsByOwner failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.debug('getAccountsByOwner exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### getAccountCredential<sup>(deprecated)</sup>    
获取指定应用帐号的凭据。使用callback异步回调。  
 **调用形式：**     
- getAccountCredential(name: string, credentialType: string, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getCredential。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。  |  
| credentialType<sup>(deprecated)</sup> | string | true | 凭据类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 回调函数。当获取凭据成功时，err为null，data为指定应用帐号的凭据；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getAccountCredential('ZhangSan', 'credentialType001', (err: BusinessError, result: string) => {   
    console.log('getAccountCredential err: ' + JSON.stringify(err));  
    console.log('getAccountCredential result: ' + result);  
});  
    
```    
  
    
### getAccountCredential<sup>(deprecated)</sup>    
获取指定应用帐号的凭据。使用callback异步回调。  
 **调用形式：**     
- getAccountCredential(name: string, credentialType: string): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getCredential。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。  |  
| credentialType<sup>(deprecated)</sup> | string | true | 凭据类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise对象，返回指定应用帐号的凭据。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getAccountCredential('ZhangSan', 'credentialType001').then((data: string) => {   
    console.log('getAccountCredential, result: ' + data);  
}).catch((err: BusinessError) => {  
    console.log('getAccountCredential err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getCredential<sup>(9+)</sup>    
获取指定应用帐号的凭据。使用callback异步回调。  
 **调用形式：**     
    
- getCredential(name: string, credentialType: string, callback: AsyncCallback\<string>): void    
起始版本： 9    
- getCredential(name: string, credentialType: string): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。  |  
| credentialType | string | true | 凭据类型。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当获取凭据成功时，err为null，data为指定应用帐号的凭据；否则为错误对象。 |  
| Promise<string> | Promise对象，返回指定应用帐号的凭据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name or credentialType. |  
| 12300003 | Account not found. |  
| 12300102 | Credential not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
    appAccountManager.getCredential('ZhangSan', 'PIN_SIX', (err: BusinessError, result: string) => {   
      if (err) {  
        console.log('getCredential failed, error: ' + JSON.stringify(err));  
      } else {  
        console.log('getCredential successfully, result: ' + result);  
      }  
    });  
} catch (err) {  
    console.log('getCredential err: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.getCredential('ZhangSan', 'PIN_SIX').then((credential: string) => {  
      console.log('getCredential successfully, credential: ' + credential);  
  }).catch((err: BusinessError) => {  
      console.log('getCredential failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('getCredential exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### getAccountExtraInfo<sup>(deprecated)</sup>    
获取指定应用帐号的额外信息（能转换成string类型的其它信息）。使用callback异步回调。  
 **调用形式：**     
- getAccountExtraInfo(name: string, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getCustomData。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 回调函数。当获取此应用帐号的额外信息成功时，err为null，data返回此应用帐号的额外信息对象；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getAccountExtraInfo('ZhangSan', (err: BusinessError, result: string) => {   
    console.log('getAccountExtraInfo err: ' + JSON.stringify(err));  
    console.log('getAccountExtraInfo result: ' + result);  
});  
    
```    
  
    
### getAccountExtraInfo<sup>(deprecated)</sup>    
获取指定应用帐号的额外信息（能转换成string类型的其它信息）。使用callback异步回调。  
 **调用形式：**     
- getAccountExtraInfo(name: string): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getCustomData。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise对象，返回此应用程序帐号的额外信息对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getAccountExtraInfo('ZhangSan').then((data: string) => {   
    console.log('getAccountExtraInfo, result: ' + data);  
}).catch((err: BusinessError) => {  
    console.log('getAccountExtraInfo err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getAssociatedData<sup>(deprecated)</sup>    
根据指定键名获取特定应用帐号的关联数据。使用callback异步回调。  
 **调用形式：**     
- getAssociatedData(name: string, key: string, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getCustomData。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。  |  
| key<sup>(deprecated)</sup> | string | true | 关联数据的键名。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 回调函数。当获取成功时，err为null，data为关联数据的取值；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getAssociatedData('ZhangSan', 'k001', (err: BusinessError, result: string) => {   
    console.log('getAssociatedData err: ' + JSON.stringify(err));  
    console.log('getAssociatedData result: ' + result);  
});  
    
```    
  
    
### getAssociatedData<sup>(deprecated)</sup>    
根据指定键名获取特定应用帐号的关联数据。使用callback异步回调。  
 **调用形式：**     
- getAssociatedData(name: string, key: string): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getCustomData。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。  |  
| key<sup>(deprecated)</sup> | string | true | 关联数据的键名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise对象，返回关联数据的取值。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getAssociatedData('ZhangSan', 'k001').then((data: string) => {   
     console.log('getAssociatedData: ' + data);  
}).catch((err: BusinessError) => {  
    console.log('getAssociatedData err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getCustomData<sup>(9+)</sup>    
根据指定键名获取特定应用帐号的自定义数据。使用callback异步回调。  
 **调用形式：**     
    
- getCustomData(name: string, key: string, callback: AsyncCallback\<string>): void    
起始版本： 9    
- getCustomData(name: string, key: string): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。  |  
| key | string | true | 自定义数据的键名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当获取成功时，err为null，data为自定义数据的取值；否则为错误对象 |  
| Promise<string> | Promise对象，返回自定义数据的取值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name or key. |  
| 12300003 | Account not found. |  
| 12400002 | Custom data not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.getCustomData('ZhangSan', 'age', (err: BusinessError, data: string) => {  
    if (err) {  
      console.log('getCustomData failed, error: ' + err);  
    } else {  
      console.log('getCustomData successfully, data: ' + data);  
    }  
  });  
} catch (err) {  
  console.log('getCustomData exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.getCustomData('ZhangSan', 'age').then((data: string) => {  
    console.log('getCustomData successfully, data: ' + data);  
  }).catch((err: BusinessError) => {  
    console.log('getCustomData failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('getCustomData exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### getCustomDataSync<sup>(9+)</sup>    
根据指定键名获取特定应用帐号的自定义数据。使用同步方式返回结果。  
 **调用形式：**     
- getCustomDataSync(name: string, key: string): string  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。 |  
| key | string | true | 自定义数据的键名 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 自定义数据的取值 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception |  
| 12300002 | Invalid name or key |  
| 12300003 | Account not found |  
| 12400002 | Custom data not found. |  
    
 **示例代码：**   
```ts    
try {  
    let value = appAccountManager.getCustomDataSync('ZhangSan', 'age');  
    console.info('getCustomDataSync successfully, vaue: ' + value);  
} catch (err) {  
  console.error('getCustomDataSync failed, error: ' + JSON.stringify(err));  
}  
    
```    
  
    
### on('change')<sup>(deprecated)</sup>    
订阅指定应用的帐号信息变更事件。  
 **调用形式：**     
- on(type: 'change', owners: Array\<string>, callback: Callback\<Array\<AppAccountInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#on。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 事件回调类型，支持的事件为'change'，当帐号所有者更新帐号信息时，触发该事件。 |  
| owners<sup>(deprecated)</sup> | Array<string> | true | 应用帐号所有者的包名列表。 |  
| callback<sup>(deprecated)</sup> | Callback<Array<AppAccountInfo>> | true | 需要注册的回调函数，返回信息发生变更的应用帐号列表 |  
    
 **示例代码：**   
```ts    
function changeOnCallback(data: account_appAccount.AppAccountInfo[]): void {  
	console.debug('receive change data:' + JSON.stringify(data));  
}  
try{  
	appAccountManager.on('change', ['com.example.actsaccounttest'], changeOnCallback);  
}  
catch(err){  
	console.error('on accountOnOffDemo err:' + JSON.stringify(err));  
}  
    
```    
  
    
### on('accountChange')<sup>(9+)</sup>    
订阅指定应用的帐号信息变更事件。  
 **调用形式：**     
    
- on(type: 'accountChange', owners: Array\<string>, callback: Callback\<Array\<AppAccountInfo>>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持的事件为'accountChange'，当目标应用更新帐号信息时，触发该事件。 |  
| owners | Array<string> | true | 应用帐号所有者的包名列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 需要注册的回调函数，返回信息为发生变更的应用帐号列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid type or owners. |  
| 12400001 | Application not found. |  
    
 **示例代码：**   
```ts    
function changeOnCallback(data: account_appAccount.AppAccountInfo[]): void {  
	console.log('receive change data:' + JSON.stringify(data));  
}  
try{  
	appAccountManager.on('accountChange', ['com.example.actsaccounttest'], changeOnCallback);  
} catch(err) {  
	console.error('on accountChange failed, error:' + JSON.stringify(err));  
}  
    
```    
  
    
### off('change')<sup>(deprecated)</sup>    
取消订阅帐号信息变更事件。  
 **调用形式：**     
- off(type: 'change', callback?: Callback\<Array\<AppAccountInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#off。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 事件回调类型，支持的事件为'change'，当帐号所有者更新帐号信息时，触发该事件。 |  
| callback<sup>(deprecated)</sup> | Callback<Array<AppAccountInfo>> | false | 需要注销的回调函数，默认为空，表示取消该类型事件的所有回调。 |  
    
 **示例代码：**   
```ts    
function changeOnCallback(data: account_appAccount.AppAccountInfo[]): void {  
	console.debug('receive change data: ' + JSON.stringify(data));  
	appAccountManager.off('change', () => {  
		console.debug('off finish');  
	})  
}  
try{  
	appAccountManager.on('change', ['com.example.actsaccounttest'], changeOnCallback);  
}  
catch(err){  
	console.error('on accountOnOffDemo err: ' + JSON.stringify(err));  
}  
    
```    
  
    
### off('accountChange')<sup>(9+)</sup>    
取消订阅帐号信息变更事件。  
 **调用形式：**     
    
- off(type: 'accountChange', callback?: Callback\<Array\<AppAccountInfo>>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 事件回调类型，支持的事件为'accountChange'，当帐号所有者更新帐号信息时，触发该事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 需要注销的回调函数，默认为空，表示取消该类型事件所有的回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid type. |  
    
 **示例代码：**   
```ts    
function changeOnCallback(data: account_appAccount.AppAccountInfo[]): void {  
	console.log('receive change data:' + JSON.stringify(data));  
}  
try{  
	appAccountManager.on('accountChange', ['com.example.actsaccounttest'], changeOnCallback);  
} catch(err) {  
	console.error('on accountChange failed, error:' + JSON.stringify(err));  
}  
try{  
	appAccountManager.off('accountChange', changeOnCallback);  
}  
catch(err){  
	console.error('off accountChange failed, error:' + JSON.stringify(err));  
}  
    
```    
  
    
### authenticate<sup>(deprecated)</sup>  
 **调用形式：**     
- authenticate(       name: string,       owner: string,       authType: string,       options: { [key: string]: any },       callback: AuthenticatorCallback     ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#auth。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true |  |  
| owner<sup>(deprecated)</sup> | string | true |  |  
| authType<sup>(deprecated)</sup> | string | true |  |  
| options<sup>(deprecated)</sup> | { [key: string]: any } | true |  |  
| callback<sup>(deprecated)</sup> | AuthenticatorCallback | true |  |  
    
### auth<sup>(9+)</sup>    
对应用帐号进行鉴权以获取授权令牌。使用callback异步回调。  
 **调用形式：**     
    
- auth(name: string, owner: string, authType: string, callback: AuthCallback): void    
起始版本： 9    
- auth(       name: string,       owner: string,       authType: string,       options: { [key: string]: Object },       callback: AuthCallback     ): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。  |  
| owner | string | true | 应用帐号所有者的包名。 |  
| authType | string | true | 鉴权类型。  |  
| options | { [key: string]: Object } | true | 鉴权所需的可选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调对象，返回鉴权结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name, owner, authType or options. |  
| 12300003 | Account not found. |  
| 12300010 | Account service busy. |  
| 12300113 | Authenticator service not found. |  
| 12300114 | Authenticator service exception. |  
    
### getOAuthToken<sup>(deprecated)</sup>    
获取指定应用帐号的特定鉴权类型的授权令牌。使用callback异步回调。  
 **调用形式：**     
- getOAuthToken(name: string, owner: string, authType: string, callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getAuthToken。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。 |  
| owner<sup>(deprecated)</sup> | string | true | 应用帐号所有者的包名。 |  
| authType<sup>(deprecated)</sup> | string | true | 鉴权类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 回调函数。当获取成功时，err为null，data为授权令牌值；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
    
  appAccountManager.getOAuthToken('LiSi', 'com.example.accountjsdemo', 'getSocialData',  
    (err: BusinessError, data: string) => {  
      console.log('getOAuthToken err: ' + JSON.stringify(err));  
      console.log('getOAuthToken token: ' + data);  
    });  
    
```    
  
    
### getOAuthToken<sup>(deprecated)</sup>    
获取指定应用帐号的特定鉴权类型的授权令牌。使用callback异步回调。  
 **调用形式：**     
- getOAuthToken(name: string, owner: string, authType: string): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getAuthToken。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。 |  
| owner<sup>(deprecated)</sup> | string | true | 应用帐号所有者的包名。 |  
| authType<sup>(deprecated)</sup> | string | true | 鉴权类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise对象，返回授权令牌。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
    
  appAccountManager.getOAuthToken('LiSi', 'com.example.accountjsdemo', 'getSocialData').then((data: string) => {  
       console.log('getOAuthToken token: ' + data);  
  }).catch((err: BusinessError) => {  
      console.log('getOAuthToken err: ' + JSON.stringify(err));  
  });  
    
```    
  
    
### getAuthToken<sup>(9+)</sup>    
获取指定应用帐号的特定鉴权类型的授权令牌。使用callback异步回调。  
 **调用形式：**     
    
- getAuthToken(name: string, owner: string, authType: string, callback: AsyncCallback\<string>): void    
起始版本： 9    
- getAuthToken(name: string, owner: string, authType: string): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。 |  
| owner | string | true | 应用帐号所有者的包名。 |  
| authType | string | true | 鉴权类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<string> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name, owner, authType or options. |  
| 12300003 | Account not found. |  
| 12300107 | AuthType not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
    
  try {  
    appAccountManager.getAuthToken('LiSi', 'com.example.accountjsdemo', 'getSocialData',  
      (err: BusinessError, token: string) => {  
        if (err) {  
          console.log('getAuthToken failed, error: ' + JSON.stringify(err));  
        } else {  
          console.log('getAuthToken successfully, token: ' + token);  
        }  
      });  
  } catch (err) {  
      console.log('getAuthToken exception: ' + JSON.stringify(err));  
  }  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
  
```ts    
import { BusinessError } from '@ohos.base';  
    
  try {  
    appAccountManager.getAuthToken('LiSi', 'com.example.accountjsdemo', 'getSocialData').then((token: string) => {  
      console.log('getAuthToken successfully, token: ' + token);  
    }).catch((err: BusinessError) => {  
      console.log('getAuthToken failed, error: ' + JSON.stringify(err));  
    });  
  } catch (err) {  
      console.log('getAuthToken exception: ' + JSON.stringify(err));  
  }  
    
```    
  
    
### setOAuthToken<sup>(deprecated)</sup>    
为指定应用帐号设置特定鉴权类型的授权令牌。使用callback异步回调。  
 **调用形式：**     
- setOAuthToken(name: string, authType: string, token: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#setAuthToken。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。 |  
| authType<sup>(deprecated)</sup> | string | true |  鉴权类型。 |  
| token<sup>(deprecated)</sup> | string | true | 授权令牌。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当设置成功时，err为null；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
    
  appAccountManager.setOAuthToken('LiSi', 'getSocialData', 'xxxx', (err: BusinessError) => {  
      console.log('setOAuthToken err: ' + JSON.stringify(err));  
  });  
    
```    
  
    
### setOAuthToken<sup>(deprecated)</sup>    
为指定应用帐号设置特定鉴权类型的授权令牌。使用callback异步回调。  
 **调用形式：**     
- setOAuthToken(name: string, authType: string, token: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#setAuthToken。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。 |  
| authType<sup>(deprecated)</sup> | string | true |  鉴权类型。 |  
| token<sup>(deprecated)</sup> | string | true | 授权令牌。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
    
  appAccountManager.setOAuthToken('LiSi', 'getSocialData', 'xxxx').then(() => {  
      console.log('setOAuthToken successfully');  
  }).catch((err: BusinessError) => {  
      console.log('setOAuthToken err: ' + JSON.stringify(err));  
  });  
    
```    
  
    
### setAuthToken<sup>(9+)</sup>    
为指定应用帐号设置特定鉴权类型的授权令牌。使用callback异步回调。  
 **调用形式：**     
    
- setAuthToken(name: string, authType: string, token: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setAuthToken(name: string, authType: string, token: string): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。 |  
| authType | string | true |  鉴权类型。 |  
| token | string | true | 授权令牌。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当设置成功时，err为null；否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name, authType or token. |  
| 12300003 | Account not found. |  
| 12400004 | The number of tokens reaches the upper limit. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
    
  appAccountManager.setOAuthTokenVisibility('LiSi', 'getSocialData', 'com.example.accountjsdemo', true,  
    (err: BusinessError) => {  
      console.log('setOAuthTokenVisibility err: ' + JSON.stringify(err));  
    });  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
    
  appAccountManager.setOAuthTokenVisibility('LiSi', 'getSocialData', 'com.example.accountjsdemo', true).then(() => {  
      console.log('setOAuthTokenVisibility successfully');  
  }).catch((err: BusinessError) => {  
      console.log('setOAuthTokenVisibility err: ' + JSON.stringify(err));  
  });  
    
```    
  
    
### deleteOAuthToken<sup>(deprecated)</sup>    
删除指定应用帐号的特定鉴权类型的授权令牌。使用callback异步回调。  
 **调用形式：**     
- deleteOAuthToken(name: string, owner: string, authType: string, token: string, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#deleteAuthToken。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true |  |  
| owner<sup>(deprecated)</sup> | string | true | 应用帐号所有者的包名。 |  
| authType<sup>(deprecated)</sup> | string | true | 鉴权类型。  |  
| token<sup>(deprecated)</sup> | string | true | 授权令牌。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当删除成功时，err为null；否则为错误对象。  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
    
  appAccountManager.deleteOAuthToken('LiSi', 'com.example.accountjsdemo', 'getSocialData', 'xxxxx',  
    (err: BusinessError) => {  
      console.log('deleteOAuthToken err: ' + JSON.stringify(err));  
    });  
    
```    
  
    
### deleteOAuthToken<sup>(deprecated)</sup>    
删除指定应用帐号的特定鉴权类型的授权令牌。使用callback异步回调。  
 **调用形式：**     
- deleteOAuthToken(name: string, owner: string, authType: string, token: string): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#deleteAuthToken。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。 |  
| owner<sup>(deprecated)</sup> | string | true | 应用帐号所有者的包名。 |  
| authType<sup>(deprecated)</sup> | string | true | 鉴权类型。  |  
| token<sup>(deprecated)</sup> | string | true | 授权令牌。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 回调函数。当删除成功时，err为null；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
    
  appAccountManager.deleteOAuthToken('LiSi', 'com.example.accountjsdemo', 'getSocialData', 'xxxxx').then(() => {  
       console.log('deleteOAuthToken successfully');  
  }).catch((err: BusinessError) => {  
      console.log('deleteOAuthToken err: ' + JSON.stringify(err));  
  });  
    
```    
  
    
### deleteAuthToken<sup>(9+)</sup>    
删除指定应用帐号的特定鉴权类型的授权令牌。使用callback异步回调。  
 **调用形式：**     
    
- deleteAuthToken(name: string, owner: string, authType: string, token: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- deleteAuthToken(name: string, owner: string, authType: string, token: string): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。  |  
| owner | string | true | 应用帐号所有者的包名。 |  
| authType | string | true |  鉴权类型。  |  
| token | string | true | 授权令牌。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当删除成功时，err为null；否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name, owner, authType or token. |  
| 12300003 | Account not found. |  
| 12300107 | AuthType not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
    
  try {  
    appAccountManager.deleteAuthToken('LiSi', 'com.example.accountjsdemo', 'getSocialData', 'xxxxx',  
      (err: BusinessError) => {  
        if (err) {  
          console.log('deleteAuthToken failed, error: ' + JSON.stringify(err));  
        } else {  
          console.log('deleteAuthToken successfully');  
        }  
      });  
  } catch (err) {  
    console.log('deleteAuthToken exception: ' + JSON.stringify(err));  
  }  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
    
  try {  
    appAccountManager.deleteAuthToken('LiSi', 'com.example.accountjsdemo', 'getSocialData', 'xxxxx').then(() => {  
      console.log('deleteAuthToken successfully');  
    }).catch((err: BusinessError) => {  
      console.log('deleteAuthToken failed, error: ' + JSON.stringify(err));  
    });  
  } catch (err) {  
    console.log('deleteAuthToken exception: ' + JSON.stringify(err));  
  }  
    
```    
  
    
### setOAuthTokenVisibility<sup>(deprecated)</sup>  
 **调用形式：**     
- setOAuthTokenVisibility(       name: string,       authType: string,       bundleName: string,       isVisible: boolean,       callback: AsyncCallback\<void>     ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#setAuthTokenVisibility。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true |  |  
| authType<sup>(deprecated)</sup> | string | true |  |  
| bundleName<sup>(deprecated)</sup> | string | true |  |  
| isVisible<sup>(deprecated)</sup> | boolean | true |  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.setOAuthTokenVisibility('LiSi', 'getSocialData', 'com.example.accountjsdemo', true,  
  (err: BusinessError) => {  
    console.log('setOAuthTokenVisibility err: ' + JSON.stringify(err));  
  });  
    
```    
  
    
### setOAuthTokenVisibility<sup>(deprecated)</sup>    
设置指定帐号的特定鉴权类型的授权令牌对指定应用的可见性。使用callback异步回调。  
 **调用形式：**     
- setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#setAuthTokenVisibility。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。  |  
| authType<sup>(deprecated)</sup> | string | true |  鉴权类型。  |  
| bundleName<sup>(deprecated)</sup> | string | true | 被设置可见性的应用包名。  |  
| isVisible<sup>(deprecated)</sup> | boolean | true | 是否可见。true表示可见，false表示不可见。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
    
  appAccountManager.setOAuthTokenVisibility('LiSi', 'getSocialData', 'com.example.accountjsdemo', true).then(() => {  
      console.log('setOAuthTokenVisibility successfully');  
  }).catch((err: BusinessError) => {  
      console.log('setOAuthTokenVisibility err: ' + JSON.stringify(err));  
  });  
    
```    
  
    
### setAuthTokenVisibility<sup>(9+)</sup>    
设置指定帐号的特定鉴权类型的授权令牌对指定应用的可见性。使用callback异步回调。  
 **调用形式：**     
    
- setAuthTokenVisibility(       name: string,       authType: string,       bundleName: string,       isVisible: boolean,       callback: AsyncCallback\<void>     ): void    
起始版本： 9    
- setAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。 |  
| authType | string | true | 鉴权类型。 |  
| bundleName | string | true | 被设置可见性的应用包名。 |  
| isVisible | boolean | true | 是否可见。true表示可见，false表示不可见。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当设置成功时，err为null；否则为错误对象 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name, authType or bundleName. |  
| 12300003 | Account not found. |  
| 12300107 | AuthType not found. |  
| 12400001 | Application not found. |  
| 12400005 | The size of authorization list reaches the upper limit. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
    
  try {  
    appAccountManager.setAuthTokenVisibility('LiSi', 'getSocialData', 'com.example.accountjsdemo', true,  
      (err: BusinessError) => {  
        if (err) {  
          console.log('setAuthTokenVisibility failed, error: ' + JSON.stringify(err));  
        } else {  
          console.log('setAuthTokenVisibility successfully');  
        }  
      });  
  } catch (err) {  
      console.log('setAuthTokenVisibility exception: ' + JSON.stringify(err));  
  }  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.setAuthTokenVisibility('LiSi', 'getSocialData', 'com.example.accountjsdemo', true).then(() => {  
    console.log('setAuthTokenVisibility successfully');  
  }).catch((err: BusinessError) => {  
    console.log('setAuthTokenVisibility failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('setAuthTokenVisibility exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### checkOAuthTokenVisibility<sup>(deprecated)</sup>  
 **调用形式：**     
- checkOAuthTokenVisibility(       name: string,       authType: string,       bundleName: string,       callback: AsyncCallback\<boolean>     ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#checkAuthTokenVisibility。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true |  |  
| authType<sup>(deprecated)</sup> | string | true |  |  
| bundleName<sup>(deprecated)</sup> | string | true |  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true |  |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.checkOAuthTokenVisibility('LiSi', 'getSocialData', 'com.example.accountjsdemo',  
  (err: BusinessError, data: boolean) => {  
    console.log('checkOAuthTokenVisibility err: ' + JSON.stringify(err));  
    console.log('checkOAuthTokenVisibility isVisible: ' + data);  
  });  
    
```    
  
    
### checkOAuthTokenVisibility<sup>(deprecated)</sup>    
检查指定应用帐号的特定鉴权类型的授权令牌对指定应用的可见性。使用callback异步回调。  
 **调用形式：**     
- checkOAuthTokenVisibility(name: string, authType: string, bundleName: string): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#checkAuthTokenVisibility。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。 |  
| authType<sup>(deprecated)</sup> | string | true | 鉴权类型。 |  
| bundleName<sup>(deprecated)</sup> | string | true | 检查可见性的应用包名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。返回true表示指定鉴权类型的OAuth令牌对特定应用的可见，返回false表示不可见。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.checkOAuthTokenVisibility('LiSi', 'getSocialData', 'com.example.accountjsdemo').then((  
  data: boolean) => {  
  console.log('checkOAuthTokenVisibility isVisible: ' + data);  
}).catch((err: BusinessError) => {  
  console.log('checkOAuthTokenVisibility err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### checkAuthTokenVisibility<sup>(9+)</sup>    
检查指定应用帐号的特定鉴权类型的授权令牌对指定应用的可见性。使用callback异步回调。  
 **调用形式：**     
    
- checkAuthTokenVisibility(       name: string,       authType: string,       bundleName: string,       callback: AsyncCallback\<boolean>     ): void    
起始版本： 9    
- checkAuthTokenVisibility(name: string, authType: string, bundleName: string): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。 |  
| authType | string | true | 鉴权类型。 |  
| bundleName | string | true | 检查可见性的应用包名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<boolean> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name. |  
| 12300003 | Account not found. |  
| 12300107 | AuthType not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.checkOAuthTokenVisibility('LiSi', 'getSocialData', 'com.example.accountjsdemo',  
  (err: BusinessError, data: boolean) => {  
    console.log('checkOAuthTokenVisibility err: ' + JSON.stringify(err));  
    console.log('checkOAuthTokenVisibility isVisible: ' + data);  
  });  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.checkOAuthTokenVisibility('LiSi', 'getSocialData', 'com.example.accountjsdemo').then((  
  data: boolean) => {  
  console.log('checkOAuthTokenVisibility isVisible: ' + data);  
}).catch((err: BusinessError) => {  
  console.log('checkOAuthTokenVisibility err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getAllOAuthTokens<sup>(deprecated)</sup>    
获取指定帐号对调用方可见的所有授权令牌。使用callback异步回调。  
 **调用形式：**     
- getAllOAuthTokens(name: string, owner: string, callback: AsyncCallback\<Array\<OAuthTokenInfo>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getAllAuthTokens。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。   |  
| owner<sup>(deprecated)</sup> | string | true | 应用帐号所有者的包名。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<OAuthTokenInfo>> | true | 回调函数。当获取成功时，err为null，data为授权令牌数组；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getAllOAuthTokens('LiSi', 'com.example.accountjsdemo',  
  (err: BusinessError, data: account_appAccount.OAuthTokenInfo[]) => {  
    console.log('getAllOAuthTokens err: ' + JSON.stringify(err));  
    console.log('getAllOAuthTokens data: ' + JSON.stringify(data));  
  });  
    
```    
  
    
### getAllOAuthTokens<sup>(deprecated)</sup>    
获取指定帐号对调用方可见的所有授权令牌。使用callback异步回调。  
 **调用形式：**     
- getAllOAuthTokens(name: string, owner: string): Promise\<Array\<OAuthTokenInfo>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getAllAuthTokens。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。   |  
| owner<sup>(deprecated)</sup> | string | true | 应用帐号所有者的包名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<OAuthTokenInfo>> | Promise对象，返回授权令牌数组。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getAllOAuthTokens('LiSi', 'com.example.accountjsdemo').then((  
  data: account_appAccount.OAuthTokenInfo[]) => {  
  console.log('getAllOAuthTokens data: ' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.log('getAllOAuthTokens err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getAllAuthTokens<sup>(9+)</sup>    
获取指定帐号对调用方可见的所有授权令牌。使用callback异步回调。  
 **调用形式：**     
    
- getAllAuthTokens(name: string, owner: string, callback: AsyncCallback\<Array\<AuthTokenInfo>>): void    
起始版本： 9    
- getAllAuthTokens(name: string, owner: string): Promise\<Array\<AuthTokenInfo>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。   |  
| owner | string | true | 应用帐号所有者的包名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Array<AuthTokenInfo>> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid owner or options. |  
| 12300003 | Account not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getAllOAuthTokens('LiSi', 'com.example.accountjsdemo',  
  (err: BusinessError, data: account_appAccount.OAuthTokenInfo[]) => {  
    console.log('getAllOAuthTokens err: ' + JSON.stringify(err));  
    console.log('getAllOAuthTokens data: ' + JSON.stringify(data));  
  });  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getAllOAuthTokens('LiSi', 'com.example.accountjsdemo').then((  
  data: account_appAccount.OAuthTokenInfo[]) => {  
  console.log('getAllOAuthTokens data: ' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.log('getAllOAuthTokens err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getOAuthList<sup>(deprecated)</sup>    
获取指定应用帐号的特定鉴权类型的授权列表，即被授权的包名数组（令牌的授权列表通过setOAuthTokenVisibility(#setoauthtokenvisibilitydeprecated)来设置）。使用callback异步回调。  
 **调用形式：**     
- getOAuthList(name: string, authType: string, callback: AsyncCallback\<Array\<string>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getAuthList。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。 |  
| authType<sup>(deprecated)</sup> | string | true | 鉴权类型。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<string>> | true | 回调函数。当获取成功时，err为null，data为被授权的包名数组；否则为错误对象。   |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getOAuthList('LiSi', 'getSocialData', (err: BusinessError, data: string[]) => {  
  console.log('getOAuthList err: ' + JSON.stringify(err));  
  console.log('getOAuthList data: ' + JSON.stringify(data));  
});  
    
```    
  
    
### getOAuthList<sup>(deprecated)</sup>    
获取指定应用帐号的特定鉴权类型的授权列表，即被授权的包名数组（令牌的授权列表通过setOAuthTokenVisibility(#setoauthtokenvisibilitydeprecated)来设置）。使用callback异步回调。  
 **调用形式：**     
- getOAuthList(name: string, authType: string): Promise\<Array\<string>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getAuthList。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 应用帐号的名称。 |  
| authType<sup>(deprecated)</sup> | string | true | 鉴权类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<string>> | Promise对象，返回被授权的包名数组。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getOAuthList('LiSi', 'getSocialData').then((data: string[]) => {  
     console.log('getOAuthList data: ' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
    console.log('getOAuthList err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getAuthList<sup>(9+)</sup>    
获取指定应用帐号的特定鉴权类型的授权列表，即被授权的包名数组（令牌的授权列表通过setOAuthTokenVisibility(#setoauthtokenvisibilitydeprecated)来设置）。使用callback异步回调。  
 **调用形式：**     
    
- getAuthList(name: string, authType: string, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 9    
- getAuthList(name: string, authType: string): Promise\<Array\<string>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。 |  
| authType | string | true | 鉴权类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<Array<string>> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid owner or options. |  
| 12300003 | Account not found. |  
| 12300107 | AuthType not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.getAuthList('LiSi', 'getSocialData', (err: BusinessError, authList: string[]) => {  
    if (err) {  
      console.log('getAuthList failed, error: ' + JSON.stringify(err));  
    } else {  
      console.log('getAuthList successfully, authList: ' + authList);  
    }  
  });  
} catch (err) {  
  console.log('getAuthList exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.getAuthList('LiSi', 'getSocialData').then((authList: string[]) => {  
      console.log('getAuthList successfully, authList: ' + authList);  
  }).catch((err: BusinessError) => {  
      console.log('getAuthList failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('getAuthList exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### getAuthenticatorCallback<sup>(deprecated)</sup>    
获取鉴权会话的认证器回调。使用callback异步回调。  
 **调用形式：**     
- getAuthenticatorCallback(sessionId: string, callback: AsyncCallback\<AuthenticatorCallback>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getAuthCallback。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sessionId<sup>(deprecated)</sup> | string | true | 鉴权会话的标识。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<AuthenticatorCallback> | true | 回调函数。当获取鉴权会话的认证器回调函数成功时，err为null，data为认证器回调函数；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import Want from '@ohos.app.ability.Want';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
  
export default class EntryAbility extends UIAbility {  
  onCreate(want: Want, param: AbilityConstant.LaunchParam) { // ability 生命周期函数  
    let sessionId: string = want.parameters![account_appAccount.Constants.KEY_SESSION_ID] as string;  
    appAccountManager.getAuthenticatorCallback(sessionId,  
        (err: BusinessError, callback: account_appAccount.AuthenticatorCallback) => {  
        if (err.code != account_appAccount.ResultCode.SUCCESS) {  
            console.log('getAuthenticatorCallback err: ' + JSON.stringify(err));  
            return;  
        }  
        callback.onResult(account_appAccount.ResultCode.SUCCESS, {  
          name: 'LiSi',  
          owner: 'com.example.accountjsdemo',  
          authType: 'getSocialData',  
          token: 'xxxxxx'}  
        );  
      });  
  }  
}  
    
```    
  
    
### getAuthenticatorCallback<sup>(deprecated)</sup>    
获取鉴权会话的认证器回调。使用callback异步回调。  
 **调用形式：**     
- getAuthenticatorCallback(sessionId: string): Promise\<AuthenticatorCallback>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#getAuthCallback。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sessionId<sup>(deprecated)</sup> | string | true | 鉴权会话的标识。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<AuthenticatorCallback> | Promise对象，返回鉴权会话的认证器回调对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import Want from '@ohos.app.ability.Want';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
  
export default class EntryAbility extends UIAbility {  
  onCreate(want: Want, param: AbilityConstant.LaunchParam) { // ability 生命周期函数  
    let sessionId: string = want.parameters![account_appAccount.Constants.KEY_SESSION_ID] as string;  
    appAccountManager.getAuthenticatorCallback(sessionId).then((  
      callback: account_appAccount.AuthenticatorCallback) => {  
      callback.onResult(account_appAccount.ResultCode.SUCCESS, {  
        name: 'LiSi',  
        owner: 'com.example.accountjsdemo',  
        authType: 'getSocialData',  
        token: 'xxxxxx'}  
      );  
    }).catch((err: BusinessError) => {  
      console.log('getAuthenticatorCallback err: ' + JSON.stringify(err));  
    });  
  }  
}  
    
```    
  
    
### getAuthCallback<sup>(9+)</sup>    
获取鉴权会话的认证器回调对象。使用Promise异步回调。  
 **调用形式：**     
    
- getAuthCallback(sessionId: string, callback: AsyncCallback\<AuthCallback>): void    
起始版本： 9    
- getAuthCallback(sessionId: string): Promise\<AuthCallback>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sessionId | string | true | 鉴权会话的标识。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<AuthCallback> | Promise对象，返回鉴权会话的认证器回调对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid sessionId. |  
| 12300108 | Session not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import Want from '@ohos.app.ability.Want';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
  
export default class EntryAbility extends UIAbility {  
  onCreate(want: Want, param: AbilityConstant.LaunchParam) { // ability 生命周期函数  
    let sessionId: string = want.parameters![account_appAccount.Constants.KEY_SESSION_ID] as string;  
    appAccountManager.getAuthenticatorCallback(sessionId,  
        (err: BusinessError, callback: account_appAccount.AuthenticatorCallback) => {  
        if (err.code != account_appAccount.ResultCode.SUCCESS) {  
            console.log('getAuthenticatorCallback err: ' + JSON.stringify(err));  
            return;  
        }  
        callback.onResult(account_appAccount.ResultCode.SUCCESS, {  
          name: 'LiSi',  
          owner: 'com.example.accountjsdemo',  
          authType: 'getSocialData',  
          token: 'xxxxxx'}  
        );  
      });  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
import UIAbility from '@ohos.app.ability.UIAbility';  
import Want from '@ohos.app.ability.Want';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
  
export default class EntryAbility extends UIAbility {  
  onCreate(want: Want, param: AbilityConstant.LaunchParam) { // ability 生命周期函数  
    let sessionId: string = want.parameters![account_appAccount.Constants.KEY_SESSION_ID] as string;  
    appAccountManager.getAuthenticatorCallback(sessionId).then((  
      callback: account_appAccount.AuthenticatorCallback) => {  
      callback.onResult(account_appAccount.ResultCode.SUCCESS, {  
        name: 'LiSi',  
        owner: 'com.example.accountjsdemo',  
        authType: 'getSocialData',  
        token: 'xxxxxx'}  
      );  
    }).catch((err: BusinessError) => {  
      console.log('getAuthenticatorCallback err: ' + JSON.stringify(err));  
    });  
  }  
}  
    
```    
  
    
### getAuthenticatorInfo<sup>(deprecated)</sup>    
获取指定应用的认证器信息。使用callback异步回调。  
 **调用形式：**     
- getAuthenticatorInfo(owner: string, callback: AsyncCallback\<AuthenticatorInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#queryAuthenticatorInfo。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| owner<sup>(deprecated)</sup> | string | true | 应用帐号所有者的包名。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<AuthenticatorInfo> | true | 回调函数。当获取成功时，err为null，data为认证器信息对象；否则为错误对象 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getAuthenticatorInfo('com.example.accountjsdemo',  
  (err: BusinessError, data: account_appAccount.AuthenticatorInfo) => {  
    console.log('getAuthenticatorInfo err: ' + JSON.stringify(err));  
    console.log('getAuthenticatorInfo data: ' + JSON.stringify(data));  
  });  
    
```    
  
    
### getAuthenticatorInfo<sup>(deprecated)</sup>    
获取指定应用的认证器信息。使用callback异步回调。  
 **调用形式：**     
- getAuthenticatorInfo(owner: string): Promise\<AuthenticatorInfo>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.AppAccountManager#queryAuthenticatorInfo。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| owner<sup>(deprecated)</sup> | string | true | 应用帐号所有者的包名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<AuthenticatorInfo> | Promise对象，返回指定应用的认证器信息对象 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getAuthenticatorInfo('com.example.accountjsdemo').then((  
  data: account_appAccount.AuthenticatorInfo) => {   
  console.log('getAuthenticatorInfo: ' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.log('getAuthenticatorInfo err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### queryAuthenticatorInfo<sup>(9+)</sup>    
获取指定应用的认证器信息。使用callback异步回调。  
 **调用形式：**     
    
- queryAuthenticatorInfo(owner: string, callback: AsyncCallback\<AuthenticatorInfo>): void    
起始版本： 9    
- queryAuthenticatorInfo(owner: string): Promise\<AuthenticatorInfo>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| owner | string | true | 应用包名。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当获取成功时，err为null，data为认证器信息对象；否则为错误对象。 |  
| Promise<AuthenticatorInfo> | Promise对象，返回指定应用的认证器信息对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid owner. |  
| 12300113 | Authenticator service not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getAuthenticatorInfo('com.example.accountjsdemo',  
  (err: BusinessError, data: account_appAccount.AuthenticatorInfo) => {  
    console.log('getAuthenticatorInfo err: ' + JSON.stringify(err));  
    console.log('getAuthenticatorInfo data: ' + JSON.stringify(data));  
  });  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
appAccountManager.getAuthenticatorInfo('com.example.accountjsdemo').then((  
  data: account_appAccount.AuthenticatorInfo) => {   
  console.log('getAuthenticatorInfo: ' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.log('getAuthenticatorInfo err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### checkAccountLabels<sup>(9+)</sup>    
检查指定应用帐号是否满足特定的标签集合。使用callback异步回调。该方法依赖目标应用的认证器提供标签检查的能力。  
 **调用形式：**     
    
- checkAccountLabels(name: string, owner: string, labels: Array\<string>, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- checkAccountLabels(name: string, owner: string, labels: Array\<string>): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。  |  
| owner | string | true | 应用帐号的所有者。 |  
| labels | Array<string> | true | 标签数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当检查成功时，err为null，data为true表示满足特定的标签集合，data为false表示不满足；否则为错误对象。 |  
| Promise<boolean> | Promise对象。返回true表示指定帐号满足特定的标签集合，返回false表示不满足。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name, owner or labels. |  
| 12300003 | Account not found. |  
| 12300010 | Account service busy. |  
| 12300113 | Authenticator service not found. |  
| 12300114 | Authenticator service exception. |  
    
 **示例代码：**   
示例（callback）  
```ts    
import rpc from '@ohos.rpc';  
  
class MyAuthenticator extends account_appAccount.Authenticator {  
  addAccountImplicitly(authType: string, callerBundleName: string,  
    options: Record<string, Object>, callback: account_appAccount.AuthenticatorCallback) {  
      let want: Want = {  
        bundleName: 'com.example.accountjsdemo',  
        abilityName: 'com.example.accountjsdemo.LoginAbility',  
      };  
      callback.onRequestRedirected(want);  
  }  
  
  authenticate(name: string, authType: string, callerBundleName: string,  
    options: Record<string, Object>, callback: account_appAccount.AuthenticatorCallback) {  
      callback.onResult(account_appAccount.ResultCode.SUCCESS, {  
        name: name,  
        authType: authType,  
        token: 'xxxxxx'}  
      );  
  }  
  
  verifyCredential(name: string,  
    options: account_appAccount.VerifyCredentialOptions, callback: account_appAccount.AuthCallback) {  
      let want: Want = {  
        bundleName: 'com.example.accountjsdemo',  
        abilityName: 'com.example.accountjsdemo.VerifyAbility',  
        parameters: {  
          name: name  
        }  
      };  
      callback.onRequestRedirected(want);  
  }  
  
  setProperties(options: account_appAccount.SetPropertiesOptions, callback: account_appAccount.AuthCallback) {  
    let want: Want = {  
        bundleName: 'com.example.accountjsdemo',  
        abilityName: 'com.example.accountjsdemo.SetPropertiesAbility',  
        parameters: {  
          options: options  
        }  
      };  
      callback.onRequestRedirected(want);  
  }  
  
  checkAccountLabels(name: string, labels: string[], callback: account_appAccount.AuthCallback) {  
    callback.onResult(account_appAccount.ResultCode.SUCCESS);  
  }  
  
  checkAccountRemovable(name: string, callback: account_appAccount.AuthCallback) {  
    callback.onResult(account_appAccount.ResultCode.SUCCESS);  
  }  
}  
  
export default {  
  onConnect(want: Want): rpc.RemoteObject { // serviceAbility 生命周期函数  
    let authenticator = new MyAuthenticator();  
    return authenticator.getRemoteObject();  
  }  
}  
    
```    
  
    
### deleteCredential<sup>(9+)</sup>    
删除指定应用帐号的特定类型的凭据信息。使用callback异步回调。  
 **调用形式：**     
    
- deleteCredential(name: string, credentialType: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- deleteCredential(name: string, credentialType: string): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true |  应用帐号的名称。 |  
| credentialType | string | true |  凭据类型。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当删除成功时，err为null；否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name or credentialType. |  
| 12300003 | Invalid name or credentialType. |  
| 12300102 | Credential not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.deleteCredential('zhangsan', 'PIN_SIX', (err: BusinessError) => {  
    if (err) {  
      console.log('deleteCredential failed, error: ' + JSON.stringify(err));  
    } else {  
      console.log('deleteCredential successfully');  
    }  
  });  
} catch (err) {  
  console.log('deleteCredential exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  appAccountManager.deleteCredential('zhangsan', 'PIN_SIX').then(() => {  
    console.log('deleteCredential successfully');  
  }).catch((err: BusinessError) => {  
    console.log('deleteCredential failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('deleteCredential exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### selectAccountsByOptions<sup>(9+)</sup>    
根据选项选择调用方可访问的帐号列表。使用callback异步回调。如果选项中包含标签约束，则该方法依赖目标应用的认证器提供标签检查的能力。  
 **调用形式：**     
    
- selectAccountsByOptions(options: SelectAccountsOptions, callback: AsyncCallback\<Array\<AppAccountInfo>>): void    
起始版本： 9    
- selectAccountsByOptions(options: SelectAccountsOptions): Promise\<Array\<AppAccountInfo>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | SelectAccountsOptions | true | 选择帐号的选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当根据选项选择请求方可访问的帐号列表时，err为null，data为可访问的帐号信息对象；否则为错误对象。 |  
| Promise<Array<AppAccountInfo>> | Promise对象，返回调用方可访问的帐号列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid options. |  
| 12300010 | Account service busy. |  
| 12300114 | Authenticator service exception. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let options: account_appAccount.SelectAccountsOptions = {  
  allowedOwners: [ 'com.example.accountjsdemo' ],  
  requiredLabels: [ 'student' ]  
};  
try {  
  appAccountManager.selectAccountsByOptions(options,  
    (err: BusinessError, accountArr: account_appAccount.AppAccountInfo[]) => {  
      if (err) {  
        console.log('selectAccountsByOptions failed, error: ' + JSON.stringify(err));  
      } else {  
        console.log('selectAccountsByOptions successfully, accountArr: ' + JSON.stringify(accountArr));  
      }  
    });  
} catch (err) {  
  console.log('selectAccountsByOptions exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let options: account_appAccount.SelectAccountsOptions = {  
  allowedOwners: ['com.example.accountjsdemo']  
};  
try {  
  appAccountManager.selectAccountsByOptions(options).then((accountArr: account_appAccount.AppAccountInfo[]) => {  
    console.log('selectAccountsByOptions successfully, accountArr: ' + JSON.stringify(accountArr));  
  }).catch((err: BusinessError) => {  
    console.log('selectAccountsByOptions failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('selectAccountsByOptions exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### verifyCredential<sup>(9+)</sup>    
验证指定帐号的凭据。使用callback异步回调。  
 **调用形式：**     
    
- verifyCredential(name: string, owner: string, callback: AuthCallback): void    
起始版本： 9    
- verifyCredential(name: string, owner: string, options: VerifyCredentialOptions, callback: AuthCallback): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。 |  
| owner | string | true | 应用帐号所有者的包名。  |  
| options | VerifyCredentialOptions | true | 选择帐号的选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name or owner. |  
| 12300003 | Account not found. |  
| 12300010 | Account service busy |  
| 12300113 | Authenticator service not found. |  
| 12300114 | Authenticator service exception. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import Want from '@ohos.app.ability.Want';  
  
try {  
    appAccountManager.verifyCredential('zhangsan', 'com.example.accountjsdemo', {  
        onResult: (resultCode: number, result?: account_appAccount.AuthResult) => {  
            console.log('verifyCredential onResult, resultCode: ' + JSON.stringify(resultCode));  
            console.log('verifyCredential onResult, result: ' + JSON.stringify(result));  
        },  
        onRequestRedirected: (request: Want) => {  
            console.log('verifyCredential onRequestRedirected, request: ' + JSON.stringify(request));  
        }  
    });  
} catch (err) {  
    console.log('verifyCredential err: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import Want from '@ohos.app.ability.Want';  
  
let options: account_appAccount.VerifyCredentialOptions = {  
  credentialType: 'pin',  
  credential: '123456'  
};  
try {  
  appAccountManager.verifyCredential('zhangsan', 'com.example.accountjsdemo', options, {  
    onResult: (resultCode: number, result?: account_appAccount.AuthResult) => {  
      console.log('verifyCredential onResult, resultCode: ' + JSON.stringify(resultCode));  
      console.log('verifyCredential onResult, result: ' + JSON.stringify(result));  
    },  
    onRequestRedirected: (request: Want) => {  
      console.log('verifyCredential onRequestRedirected, request: ' + JSON.stringify(request));  
    }  
  });  
} catch (err) {  
  console.log('verifyCredential err: ' + JSON.stringify(err));  
}  
    
```    
  
    
### setAuthenticatorProperties<sup>(9+)</sup>    
设置指定应用的认证器属性。使用callback异步回调。  
 **调用形式：**     
    
- setAuthenticatorProperties(owner: string, callback: AuthCallback): void    
起始版本： 9    
- setAuthenticatorProperties(owner: string, options: SetPropertiesOptions, callback: AuthCallback): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| owner | string | true | 认证器的所有者。 |  
| options | SetPropertiesOptions | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回设置属性的结果 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid owner. |  
| 12300010 | Account service busy. |  
| 12300113 | Authenticator service not found. |  
| 12300114 | Authenticator service exception. |  
    
 **示例代码：**   
示例（callback）  
```ts    
import Want from '@ohos.app.ability.Want';  
  
try {  
  appAccountManager.setAuthenticatorProperties('com.example.accountjsdemo', {  
    onResult: (resultCode: number, result?: account_appAccount.AuthResult) => {  
      console.log('setAuthenticatorProperties onResult, resultCode: ' + JSON.stringify(resultCode));  
      console.log('setAuthenticatorProperties onResult, result: ' + JSON.stringify(result));  
    },  
    onRequestRedirected: (request: Want) => {  
      console.log('setAuthenticatorProperties onRequestRedirected, request: ' + JSON.stringify(request));  
    }  
  });  
} catch (err) {  
  console.log('setAuthenticatorProperties err: ' + JSON.stringify(err));  
}  
    
```    
  
    
## AppAccountInfo    
表示应用帐号信息。  
 **系统能力:**  SystemCapability.Account.AppAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.AppAccount    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| owner | string | false | true | 应用帐号所有者的包名。 |  
| name | string | false | true | 应用帐号的名称。 |  
    
## OAuthTokenInfo<sup>(deprecated)</sup>    
表示OAuth令牌信息。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用appAccount.AuthTokenInfo替代。  
 **系统能力:**  SystemCapability.Account.AppAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.AppAccount    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| authType<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>令牌的鉴权类型。 |  
| token<sup>(deprecated)</sup> | string | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>令牌的取值。 |  
    
## AuthTokenInfo<sup>(9+)</sup>    
表示Auth令牌信息。  
 **系统能力:**  SystemCapability.Account.AppAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.AppAccount    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| authType<sup>(9+)</sup> | string | false | true | 令牌的鉴权类型。  |  
| token<sup>(9+)</sup> | string | false | true | 令牌的取值。 |  
| account<sup>(9+)</sup> | AppAccountInfo | false | false | 令牌所属的帐号信息，默认为空。 |  
    
## AuthenticatorInfo<sup>(8+)</sup>    
表示OAuth认证器信息。  
 **系统能力:**  SystemCapability.Account.AppAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.AppAccount    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| owner<sup>(8+)</sup> | string | false | true | 认证器的所有者包名 |  
| iconId<sup>(8+)</sup> | number | false | true | 认证器的图标标识。 |  
| labelId<sup>(8+)</sup> | number | false | true | 认证器的标签标识。 |  
    
## AuthResult<sup>(9+)</sup>    
表示认证结果信息。  
 **系统能力:**  SystemCapability.Account.AppAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.AppAccount    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| account<sup>(9+)</sup> | AppAccountInfo | false | false | 令牌所属的帐号信息，默认为空。 |  
| tokenInfo<sup>(9+)</sup> | AuthTokenInfo | false | false | 令牌信息，默认为空。 |  
    
## CreateAccountOptions<sup>(9+)</sup>  
 **系统能力:**  SystemCapability.Account.AppAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.AppAccount    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| customData<sup>(9+)</sup> | object | false | false |  |  
    
## CreateAccountImplicitlyOptions<sup>(9+)</sup>    
表示隐式创建帐号的选项。  
 **系统能力:**  SystemCapability.Account.AppAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.AppAccount    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| requiredLabels<sup>(9+)</sup> | Array<string> | false | false | 所需的标签，默认为空。 |  
| authType<sup>(9+)</sup> | string | false | false | 鉴权类型，默认为空。 |  
| parameters<sup>(9+)</sup> | object | false | false | 自定义参数对象，默认为空。 |  
    
## SelectAccountsOptions<sup>(9+)</sup>    
允许的帐号数组，默认为空。  
 **系统能力:**  SystemCapability.Account.AppAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.AppAccount    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| allowedAccounts<sup>(9+)</sup> | Array<AppAccountInfo> | false | false | 允许的帐号数组，默认为空。 |  
| allowedOwners<sup>(9+)</sup> | Array<string> | false | false | 允许的帐号所有者数组，默认为空。 |  
| requiredLabels<sup>(9+)</sup> | Array<string> | false | false | 认证器的标签标识，默认为空。  |  
    
## VerifyCredentialOptions<sup>(9+)</sup>    
表示用于验证凭据的选项。  
 **系统能力:**  SystemCapability.Account.AppAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.AppAccount    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| credentialType<sup>(9+)</sup> | string | false | false | 凭据类型，默认为空。 |  
| credential<sup>(9+)</sup> | string | false | false | 凭据取值，默认为空。    |  
| parameters<sup>(9+)</sup> | object | false | false | 自定义参数对象，默认为空。 |  
    
## SetPropertiesOptions<sup>(9+)</sup>    
表示用于设置属性的选项。  
 **系统能力:**  SystemCapability.Account.AppAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.AppAccount    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| properties<sup>(9+)</sup> | object | false | false | 属性对象，默认为空。 |  
| parameters<sup>(9+)</sup> | object | false | false | 自定义参数对象，默认为空。 |  
    
## Constants<sup>(8+)</sup>    
表示常量的枚举。    
    
 **系统能力:**  SystemCapability.Account.AppAccount    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ACTION_ADD_ACCOUNT_IMPLICITLY<sup>(deprecated)</sup> | addAccountImplicitly | 从API version 8 开始支持，从API version 9 开始废弃。建议使用appAccount.Constants#ACTION_CREATE_ACCOUNT_IMPLICITLY替代。<br>表示操作，隐式添加帐号。 |  
| ACTION_AUTHENTICATE<sup>(deprecated)</sup> | authenticate | 从API version 8 开始支持，从API version 9 开始废弃。建议使用appAccount.Constants#ACTION_AUTH替代。<br>表示操作，鉴权。  |  
| ACTION_CREATE_ACCOUNT_IMPLICITLY<sup>(9+)</sup> | createAccountImplicitly | 表示操作，隐式创建帐号。 |  
| ACTION_AUTH<sup>(9+)</sup> | auth | 表示操作，鉴权。 |  
| ACTION_VERIFY_CREDENTIAL<sup>(9+)</sup> | verifyCredential | 表示操作，验证凭据。 |  
| ACTION_SET_AUTHENTICATOR_PROPERTIES<sup>(9+)</sup> | setAuthenticatorProperties | 表示操作，设置认证器属性。 |  
| KEY_NAME | name | 表示键名，应用帐号的名称。 |  
| KEY_OWNER | owner | 表示键名，应用帐号所有者 |  
| KEY_TOKEN | token | 表示键名，令牌。 |  
| KEY_ACTION | action | 表示键名，操作。  |  
| KEY_AUTH_TYPE | authType | 表示键名，鉴权类型。 |  
| KEY_SESSION_ID | sessionId | 表示键名，会话标识。    |  
| KEY_CALLER_PID | callerPid | 表示键名，调用方PID。 |  
| KEY_CALLER_UID | callerUid | 表示键名，调用方UID。  |  
| KEY_CALLER_BUNDLE_NAME | callerBundleName | 表示键名，调用方包名。   |  
| KEY_REQUIRED_LABELS<sup>(9+)</sup> | requiredLabels | 表示键名，必需的标签。 |  
| KEY_BOOLEAN_RESULT<sup>(9+)</sup> | booleanResult | 表示键名，布尔返回值 |  
    
## ResultCode<sup>(deprecated)</sup>    
表示返回码的枚举。    
从API version 8 开始支持，从API version 9 开始废弃。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SUCCESS | 0 | 表示操作成功。  |  
| ERROR_ACCOUNT_NOT_EXIST | 10001 | 表示应用帐号不存在。 |  
| ERROR_APP_ACCOUNT_SERVICE_EXCEPTION | 10002 | 表示应用帐号服务异常。 |  
| ERROR_INVALID_PASSWORD | 10003 | 表示密码无效。  |  
| ERROR_INVALID_REQUEST | 10004 | 表示请求无效。  |  
| ERROR_INVALID_RESPONSE | 10005 | 表示响应无效。   |  
| ERROR_NETWORK_EXCEPTION | 10006 |  表示网络异常。 |  
| ERROR_OAUTH_AUTHENTICATOR_NOT_EXIST | 10007 | 表示认证器不存在。 |  
| ERROR_OAUTH_CANCELED | 10008 | 表示鉴权取消。    |  
| ERROR_OAUTH_LIST_TOO_LARGE | 10009 | 表示开放授权列表过大。 |  
| ERROR_OAUTH_SERVICE_BUSY | 10010 | 表示开放授权服务忙碌。 |  
| ERROR_OAUTH_SERVICE_EXCEPTION | 10011 | 表示开放授权服务异常。 |  
| ERROR_OAUTH_SESSION_NOT_EXIST | 10012 | 表示鉴权会话不存在。 |  
| ERROR_OAUTH_TIMEOUT | 10013 | 表示鉴权超时。 |  
| ERROR_OAUTH_TOKEN_NOT_EXIST | 10014 | 表示开放授权令牌不存在。 |  
| ERROR_OAUTH_TOKEN_TOO_MANY | 10015 | 表示开放授权令牌过多。  |  
| ERROR_OAUTH_UNSUPPORT_ACTION | 10016 | 表示不支持的鉴权操作。  |  
| ERROR_OAUTH_UNSUPPORT_AUTH_TYPE | 10017 | 表示不支持的鉴权类型。 |  
| ERROR_PERMISSION_DENIED | 10018 | 表示权限不足。 |  
    
## AuthenticatorCallback<sup>(deprecated)</sup>    
OAuth认证器回调接口。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用AppAccount.AuthCallback替代。  
 **系统能力:**  SystemCapability.Account.AppAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.AppAccount    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| onResult<sup>(deprecated)</sup> | (code: number, result: { [key: string]: any }) => void | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br><br/>  
通知请求结果。 |  
| onRequestRedirected<sup>(deprecated)</sup> | (request: Want) => void | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>通知请求被跳转。 |  
    
## AuthCallback<sup>(9+)</sup>    
认证器回调类。  
 **系统能力:**  SystemCapability.Account.AppAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.AppAccount    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| onResult<sup>(9+)</sup> | (code: number, result?: AuthResult) => void | false | true |  |  
| onRequestRedirected<sup>(9+)</sup> | (request: Want) => void | false | true |  |  
| onRequestContinued<sup>(9+)</sup> | () => void | false | false |  |  
    
## Authenticator<sup>(8+)</sup>  
 **系统能力:**  SystemCapability.Account.AppAccount    
### addAccountImplicitly<sup>(deprecated)</sup>  
 **调用形式：**     
- addAccountImplicitly(       authType: string,       callerBundleName: string,       options: { [key: string]: any },       callback: AuthenticatorCallback     ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.Authenticator#createAccountImplicitly。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| authType<sup>(deprecated)</sup> | string | true |  |  
| callerBundleName<sup>(deprecated)</sup> | string | true |  |  
| options<sup>(deprecated)</sup> | { [key: string]: any } | true |  |  
| callback<sup>(deprecated)</sup> | AuthenticatorCallback | true |  |  
    
### createAccountImplicitly<sup>(9+)</sup>    
根据指定的帐号所有者隐式地创建应用帐号，并使用callback异步回调返回结果。  
 **调用形式：**     
    
- createAccountImplicitly(options: CreateAccountImplicitlyOptions, callback: AuthCallback): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | CreateAccountImplicitlyOptions | true | 隐式创建帐号的选项。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 认证器回调对象，用于返回创建结果。 |  
    
### authenticate<sup>(deprecated)</sup>  
 **调用形式：**     
- authenticate(       name: string,       authType: string,       callerBundleName: string,       options: { [key: string]: any },       callback: AuthenticatorCallback     ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: appAccount.Authenticator#auth。  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true |  |  
| authType<sup>(deprecated)</sup> | string | true |  |  
| callerBundleName<sup>(deprecated)</sup> | string | true |  |  
| options<sup>(deprecated)</sup> | { [key: string]: any } | true |  |  
| callback<sup>(deprecated)</sup> | AuthenticatorCallback | true |  |  
    
### auth<sup>(9+)</sup>    
对应用帐号进行鉴权以获取授权令牌。使用callback异步回调。  
 **调用形式：**     
    
- auth(name: string, authType: string, options: { [key: string]: Object }, callback: AuthCallback): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。    |  
| authType | string | true | 鉴权类型。  |  
| options | { [key: string]: Object } | true | 鉴权所需要的可选项。     |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
### verifyCredential<sup>(9+)</sup>    
验证用户凭据。使用callback异步回调。  
 **调用形式：**     
    
- verifyCredential(name: string, options: VerifyCredentialOptions, callback: AuthCallback): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true |  应用帐号的名称。    |  
| options | VerifyCredentialOptions | true | 验证凭据的选项。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回验证结果。 |  
    
### setProperties<sup>(9+)</sup>    
设置认证器属性，并使用callback异步回调返回结果。  
 **调用形式：**     
    
- setProperties(options: SetPropertiesOptions, callback: AuthCallback): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | SetPropertiesOptions | true | 设置属性的可选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 认证器回调，用于返回设置结果。 |  
    
### checkAccountLabels<sup>(9+)</sup>    
检查帐号标签，并使用callback异步回调返回结果。  
 **调用形式：**     
    
- checkAccountLabels(name: string, labels: Array\<string>, callback: AuthCallback): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。  |  
| labels | Array<string> | true | 标签数组。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 认证器回调，用于返回检查结果。 |  
    
### checkAccountRemovable<sup>(9+)</sup>    
判断帐号是否可以删除，并使用callback异步回调返回结果  
 **调用形式：**     
    
- checkAccountRemovable(name: string, callback: AuthCallback): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 应用帐号的名称。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 认证器回调，用于返回判断结果。 |  
    
### getRemoteObject<sup>(9+)</sup>    
获取认证器的远程对象，不可以重载实现。  
 **调用形式：**     
- getRemoteObject(): rpc.RemoteObject  
  
 **系统能力:**  SystemCapability.Account.AppAccount    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| rpc.RemoteObject |  |  
    
 **示例代码：**   
```ts    
import account_appAccount from '@ohos.account.appAccount';    
```    
  
