# @ohos.account.osAccount    
本模块提供管理系统帐号的基础能力，包括系统帐号的添加、删除、查询、设置、订阅、启动等功能。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import osAccount from '@ohos.account.osAccount'    
```  
    
## getAccountManager    
获取系统帐号管理对象。  
 **调用形式：**     
- getAccountManager(): AccountManager  
  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| AccountManager | 系统帐号管理对象。 |  
    
 **示例代码：**   
```ts    
let accountManager = account_osAccount.getAccountManager();    
```    
  
    
## AccountManager    
系统帐号管理类。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### isMultiOsAccountEnable<sup>(deprecated)</sup>    
判断是否支持多系统帐号。使用callback异步回调。  
 **调用形式：**     
- isMultiOsAccountEnable(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#checkMultiOsAccountEnabled。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。返回true表示支持多系统帐号；返回false表示不支持。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
accountManager.isMultiOsAccountEnable((err: BusinessError, isEnabled: boolean) => {  
  if (err) {  
    console.log('isMultiOsAccountEnable failed, error: ' + JSON.stringify(err));  
  } else {  
  console.log('isMultiOsAccountEnable successfully, isEnabled: ' + isEnabled);  
  }  
});  
    
```    
  
    
### isMultiOsAccountEnable<sup>(deprecated)</sup>    
判断是否支持多系统帐号。使用callback异步回调。  
 **调用形式：**     
- isMultiOsAccountEnable(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#checkMultiOsAccountEnabled。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。返回true表示支持多系统帐号；返回false表示不支持。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
accountManager.isMultiOsAccountEnable().then((isEnabled: boolean) => {  
  console.log('isMultiOsAccountEnable successfully, isEnabled: ' + isEnabled);  
}).catch((err: BusinessError) => {  
  console.log('isMultiOsAccountEnable failed, error: ' + JSON.stringify(err));  
});  
    
```    
  
    
### checkMultiOsAccountEnabled<sup>(9+)</sup>    
判断是否支持多系统帐号。使用callback异步回调。  
 **调用形式：**     
    
- checkMultiOsAccountEnabled(callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- checkMultiOsAccountEnabled(): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示支持多系统帐号；返回false表示不支持。 |  
| Promise<boolean> | Promise对象。返回true表示支持多系统帐号；返回false表示不支持。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.checkMultiOsAccountEnabled((err: BusinessError, isEnabled: boolean) => {  
    if (err) {  
      console.error(`checkMultiOsAccountEnabled failed, code is ${err.code}, message is ${err.message}`);  
    } else {  
    console.log('checkMultiOsAccountEnabled successfully, isEnabled: ' + isEnabled);  
    }  
  });  
} catch (err) {  
  console.log('checkMultiOsAccountEnabled failed, error:' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
try {  
  let accountManager = account_osAccount.getAccountManager();  
  accountManager.checkMultiOsAccountEnabled().then((isEnabled: boolean) => {  
    console.log('checkMultiOsAccountEnabled successfully, isEnabled: ' + isEnabled);  
  }).catch((err: BusinessError) => {  
    console.error(`checkMultiOsAccountEnabled failed, code is ${err.code}, message is ${err.message}`);  
  });  
} catch (err) {  
  console.log('checkMultiOsAccountEnabled failed, error:' + JSON.stringify(err));  
}  
    
```    
  
    
### isOsAccountActived<sup>(deprecated)</sup>    
判断指定系统帐号是否处于激活状态。使用callback异步回调。  
 **调用形式：**     
- isOsAccountActived(localId: number, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#checkOsAccountActivated。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId<sup>(deprecated)</sup> | number | true | 系统帐号ID。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。返回true表示帐号已激活；返回false表示帐号未激活。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
accountManager.isOsAccountActived(localId, (err: BusinessError, isActived: boolean) => {  
  if (err) {  
    console.log('isOsAccountActived failed, err:' + JSON.stringify(err));  
  } else {  
    console.log('isOsAccountActived successfully, isActived:' + isActived);  
  }  
});  
    
```    
  
    
### isOsAccountActived<sup>(deprecated)</sup>    
判断指定系统帐号是否处于激活状态。使用callback异步回调。  
 **调用形式：**     
- isOsAccountActived(localId: number): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#checkOsAccountActivated。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId<sup>(deprecated)</sup> | number | true | 系统帐号ID。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。返回true表示帐号已激活；返回false表示帐号未激活。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
accountManager.isOsAccountActived(localId).then((isActived: boolean) => {  
  console.log('isOsAccountActived successfully, isActived: ' + isActived);  
}).catch((err: BusinessError) => {  
  console.log('isOsAccountActived failed, error: ' + JSON.stringify(err));  
});  
    
```    
  
    
### checkOsAccountActivated<sup>(9+)</sup>    
判断指定系统帐号是否处于激活状态。使用callback异步回调。  
 **调用形式：**     
    
- checkOsAccountActivated(localId: number, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- checkOsAccountActivated(localId: number): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId | number | true | 系统帐号ID。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示帐号已激活；返回false表示帐号未激活。 |  
| Promise<boolean> | Promise对象。返回true表示帐号已激活；返回false表示帐号未激活。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid localId. |  
| 12300003 | Account not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
try {  
  accountManager.checkOsAccountActivated(localId, (err: BusinessError, isActivated: boolean) => {  
    if (err) {  
      console.log('checkOsAccountActivated failed, error:' + JSON.stringify(err));  
    } else {  
      console.log('checkOsAccountActivated successfully, isActivated:' + isActivated);  
    }  
  });  
} catch (err) {  
  console.log('checkOsAccountActivated exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
try {  
  accountManager.checkOsAccountActivated(localId).then((isActivated: boolean) => {  
    console.log('checkOsAccountActivated successfully, isActivated: ' + isActivated);  
  }).catch((err: BusinessError) => {  
    console.log('checkOsAccountActivated failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('checkOsAccountActivated exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### isOsAccountConstraintEnable<sup>(deprecated)</sup>    
判断指定系统帐号是否具有指定约束。使用callback异步回调。  
 **调用形式：**     
- isOsAccountConstraintEnable(localId: number, constraint: string, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#checkConstraintEnabled。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId<sup>(deprecated)</sup> | number | true |  |  
| constraint<sup>(deprecated)</sup> | string | true | 指定的[约束](#系统帐号约束列表)名称。<br/> |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。返回true表示已使能指定的约束；返回false表示未使能指定的约束。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
let constraint: string = 'constraint.wifi';  
accountManager.isOsAccountConstraintEnable(localId, constraint, (err: BusinessError, isEnabled: boolean) => {  
  if (err) {  
    console.log('isOsAccountConstraintEnable failed, error: ' + JSON.stringify(err));  
  } else {  
    console.log('isOsAccountConstraintEnable successfully, isEnabled: ' + isEnabled);  
  }  
});  
    
```    
  
    
### isOsAccountConstraintEnable<sup>(deprecated)</sup>    
判断指定系统帐号是否具有指定约束。使用callback异步回调。  
 **调用形式：**     
- isOsAccountConstraintEnable(localId: number, constraint: string): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#checkConstraintEnabled。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId<sup>(deprecated)</sup> | number | true | 系统帐号ID。<br/> |  
| constraint<sup>(deprecated)</sup> | string | true | 指定的[约束](#系统帐号约束列表)名称。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。返回true表示已使能指定的约束；返回false表示未使能指定的约束。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
let constraint: string = 'constraint.wifi';  
accountManager.isOsAccountConstraintEnable(localId, constraint).then((isEnabled: boolean) => {  
  console.log('isOsAccountConstraintEnable successfully, isEnabled: ' + isEnabled);  
}).catch((err: BusinessError) => {  
  console.log('isOsAccountConstraintEnable err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### checkOsAccountConstraintEnabled<sup>(9+)</sup>    
判断指定系统帐号是否具有指定约束。使用callback异步回调。  
 **调用形式：**     
    
- checkOsAccountConstraintEnabled(localId: number, constraint: string, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- checkOsAccountConstraintEnabled(localId: number, constraint: string): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId | number | true | 系统帐号ID。 |  
| constraint | string | true | 指定的[约束](#系统帐号约束列表)名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示已使能指定的约束；返回false表示未使能指定的约束。 |  
| Promise<boolean> | Promise对象。返回true表示当前帐号为测试帐号；返回false表示当前帐号非测试帐号。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid localId or constraint. |  
| 12300003 | Account not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
let constraint: string = 'constraint.wifi';  
try {  
  accountManager.checkOsAccountConstraintEnabled(localId, constraint, (err: BusinessError, isEnabled: boolean)=>{  
    if (err) {  
      console.log('checkOsAccountConstraintEnabled failed, error: ' + JSON.stringify(err));  
    } else {  
      console.log('checkOsAccountConstraintEnabled successfully, isEnabled: ' + isEnabled);  
    }  
  });  
} catch (err) {  
  console.log('checkOsAccountConstraintEnabled exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
let constraint: string = 'constraint.wifi';  
try {  
  accountManager.checkOsAccountConstraintEnabled(localId, constraint).then((isEnabled: boolean) => {  
    console.log('checkOsAccountConstraintEnabled successfully, isEnabled: ' + isEnabled);  
  }).catch((err: BusinessError) => {  
    console.log('checkOsAccountConstraintEnabled failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('checkOsAccountConstraintEnabled exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### isTestOsAccount<sup>(deprecated)</sup>    
检查当前系统帐号是否为测试帐号。使用callback异步回调。  
 **调用形式：**     
- isTestOsAccount(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#checkOsAccountTestable。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。返回true表示当前帐号为测试帐号；返回false表示当前帐号非测试帐号。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
accountManager.isTestOsAccount((err: BusinessError, isTestable: boolean) => {  
  if (err) {  
    console.log('isTestOsAccount failed, error: ' + JSON.stringify(err));  
  } else {  
    console.log('isTestOsAccount successfully, isTestable: ' + isTestable);  
  }  
});  
    
```    
  
    
### isTestOsAccount<sup>(deprecated)</sup>    
检查当前系统帐号是否为测试帐号。使用callback异步回调。  
 **调用形式：**     
- isTestOsAccount(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#checkOsAccountTestable。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。返回true表示当前帐号为测试帐号；返回false表示当前帐号非测试帐号。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
  accountManager.isTestOsAccount().then((isTestable: boolean) => {  
    console.log('isTestOsAccount successfully, isTestable: ' + isTestable);  
  }).catch((err: BusinessError) => {  
    console.log('isTestOsAccount failed, error: ' + JSON.stringify(err));  
});  
    
```    
  
    
### checkOsAccountTestable<sup>(9+)</sup>    
检查当前系统帐号是否为测试帐号。使用callback异步回调。  
 **调用形式：**     
    
- checkOsAccountTestable(callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- checkOsAccountTestable(): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示当前帐号为测试帐号；返回false表示当前帐号非测试帐号。 |  
| Promise<boolean> | Promise对象。返回true表示当前帐号为测试帐号；返回false表示当前帐号非测试帐号。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.checkOsAccountTestable((err: BusinessError, isTestable: boolean) => {  
    if (err) {  
      console.log('checkOsAccountTestable failed, error: ' + JSON.stringify(err));  
    } else {  
      console.log('checkOsAccountTestable successfully, isTestable: ' + isTestable);  
    }  
  });  
} catch (err) {  
  console.log('checkOsAccountTestable error: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.checkOsAccountTestable().then((isTestable: boolean) => {  
    console.log('checkOsAccountTestable successfully, isTestable: ' + isTestable);  
  }).catch((err: BusinessError) => {  
    console.log('checkOsAccountTestable failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('checkOsAccountTestable exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### isOsAccountVerified<sup>(deprecated)</sup>    
检查当前系统帐号是否已验证。使用callback异步回调。  
 **调用形式：**     
- isOsAccountVerified(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#checkOsAccountVerified。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。返回true表示指定帐号已验证；返回false表示指定帐号未验证。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
accountManager.isOsAccountVerified((err: BusinessError, isVerified: boolean) => {  
  if (err) {  
    console.log('isOsAccountVerified failed, error: ' + JSON.stringify(err));  
  } else {  
    console.log('isOsAccountVerified successfully, isVerified: ' + isVerified);  
  }  
});  
    
```    
  
    
### isOsAccountVerified<sup>(deprecated)</sup>    
检查当前系统帐号是否已验证。使用callback异步回调。  
 **调用形式：**     
- isOsAccountVerified(localId: number, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#checkOsAccountVerified。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId<sup>(deprecated)</sup> | number | true | 系统帐号ID。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。返回true表示指定帐号已验证；返回false表示指定帐号未验证。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
accountManager.isOsAccountVerified(localId, (err: BusinessError, isVerified: boolean) => {  
  if (err) {  
    console.log('isOsAccountVerified failed, error: ' + JSON.stringify(err));  
  } else {  
    console.log('isOsAccountVerified successfully, isVerified: ' + isVerified);  
  }  
});  
    
```    
  
    
### isOsAccountVerified<sup>(deprecated)</sup>    
检查当前系统帐号是否已验证。使用callback异步回调。  
 **调用形式：**     
- isOsAccountVerified(localId?: number): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#checkOsAccountVerified。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId<sup>(deprecated)</sup> | number | false | 系统帐号ID。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。返回true表示指定帐号已验证；返回false表示指定帐号未验证。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
accountManager.isOsAccountVerified(localId).then((isVerified: boolean) => {  
  console.log('isOsAccountVerified successfully, isVerified: ' + isVerified);  
}).catch((err: BusinessError) => {  
  console.log('isOsAccountVerified failed, error: ' + JSON.stringify(err));  
});  
    
```    
  
    
### checkOsAccountVerified<sup>(9+)</sup>    
检查当前系统帐号是否已认证解锁。使用callback异步回调。  
 **调用形式：**     
    
- checkOsAccountVerified(callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- checkOsAccountVerified(): Promise\<boolean>    
起始版本： 9    
- checkOsAccountVerified(localId: number, callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- checkOsAccountVerified(localId: number): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId | number | true | 系统帐号ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示当前帐号已认证解锁；返回false表示当前帐号未认证解锁。 |  
| Promise<boolean> | Promise对象。返回true表示当前帐号已认证解锁；返回false表示当前帐号未认证解锁。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 12300001 | System service exception. |  
| 201 |  |  
| 401 |  |  
| 12300002 | Invalid localId. |  
| 12300003 | Account not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.checkOsAccountVerified((err: BusinessError, isVerified: boolean) => {  
    if (err) {  
      console.log('checkOsAccountVerified failed, error: ' + JSON.stringify(err));  
    } else {  
      console.log('checkOsAccountVerified successfully, isVerified: ' + isVerified);  
    }  
  });  
} catch (err) {  
  console.log('checkOsAccountVerified exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.checkOsAccountVerified().then((isVerified: boolean) => {  
    console.log('checkOsAccountVerified successfully, isVerified: ' + isVerified);  
  }).catch((err: BusinessError) => {  
    console.log('checkOsAccountVerified failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('checkOsAccountVerified exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### getCreatedOsAccountsCount<sup>(deprecated)</sup>    
获取已创建的系统帐号数量。使用callback异步回调。  
 **调用形式：**     
- getCreatedOsAccountsCount(callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getOsAccountCount。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数。当获取成功时，err为null，data为已创建的系统帐号的数量；否则为错误对象。 |  
    
 **示例代码：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
accountManager.getCreatedOsAccountsCount((err: BusinessError, count: number)=>{  
  if (err) {  
    console.log('getCreatedOsAccountsCount failed, error: ' + JSON.stringify(err));  
  } else {  
    console.log('getCreatedOsAccountsCount successfully, count: ' + count);  
  }  
});  
    
```    
  
    
### getCreatedOsAccountsCount<sup>(deprecated)</sup>    
获取已创建的系统帐号数量。使用callback异步回调。  
 **调用形式：**     
- getCreatedOsAccountsCount(): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getOsAccountCount。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象，返回已创建的系统帐号的数量。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
accountManager.getCreatedOsAccountsCount().then((count: number) => {  
  console.log('getCreatedOsAccountsCount successfully, count: ' + count);  
}).catch((err: BusinessError) => {  
  console.log('getCreatedOsAccountsCount failed, error: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getOsAccountCount<sup>(9+)</sup>    
获取已创建的系统帐号数量。使用callback异步回调。  
 **调用形式：**     
    
- getOsAccountCount(callback: AsyncCallback\<number>): void    
起始版本： 9    
- getOsAccountCount(): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当获取成功时，err为null，data为已创建的系统帐号的数量；否则为错误对象。 |  
| Promise<number> | Promise对象，返回已创建的系统帐号的数量。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.getOsAccountCount((err: BusinessError, count: number) => {  
    if (err) {  
      console.log('getOsAccountCount failed, error: ' + JSON.stringify(err));  
    } else {  
      console.log('getOsAccountCount successfully, count: ' + count);  
    }  
  });  
} catch (err) {  
  console.log('getOsAccountCount exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.getOsAccountCount().then((count: number) => {  
    console.log('getOsAccountCount successfully, count: ' + count);  
  }).catch((err: BusinessError) => {  
    console.log('getOsAccountCount failed, error: ' + JSON.stringify(err));  
  });  
} catch(err) {  
  console.log('getOsAccountCount exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### getOsAccountLocalIdFromProcess<sup>(deprecated)</sup>    
获取当前进程所属的系统帐号ID，使用callback异步回调。  
 **调用形式：**     
- getOsAccountLocalIdFromProcess(callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getOsAccountLocalId。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数。当获取成功时，err为null，data为当前进程所属的系统帐号ID；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
accountManager.getOsAccountLocalIdFromProcess((err: BusinessError, localId: number) => {  
  if (err) {  
    console.log('getOsAccountLocalIdFromProcess failed, error: ' + JSON.stringify(err));  
  } else {  
    console.log('getOsAccountLocalIdFromProcess failed, error: ' + localId);  
  }  
});  
    
```    
  
    
### getOsAccountLocalIdFromProcess<sup>(deprecated)</sup>    
获取当前进程所属的系统帐号ID，使用callback异步回调。  
 **调用形式：**     
- getOsAccountLocalIdFromProcess(): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getOsAccountLocalId。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象，返回当前进程所属的系统帐号ID。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
accountManager.getOsAccountLocalIdFromProcess().then((localId: number) => {  
  console.log('getOsAccountLocalIdFromProcess successfully, localId: ' + localId);  
}).catch((err: BusinessError) => {  
  console.log('getOsAccountLocalIdFromProcess failed, error: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getOsAccountLocalId<sup>(9+)</sup>    
获取当前进程所属的系统帐号ID，使用callback异步回调。  
 **调用形式：**     
    
- getOsAccountLocalId(callback: AsyncCallback\<number>): void    
起始版本： 9    
- getOsAccountLocalId(): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当获取成功时，err为null，data为当前进程所属的系统帐号ID；否则为错误对象。 |  
| Promise<number> | Promise对象，返回当前进程所属的系统帐号ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.getOsAccountLocalId((err: BusinessError, localId: number) => {  
    if (err) {  
      console.log('getOsAccountLocalId failed, error: ' + JSON.stringify(err));  
    } else {  
      console.log('getOsAccountLocalId successfully, localId: ' + localId);  
    }  
  });  
} catch (err) {  
  console.log('getOsAccountLocalId exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.getOsAccountLocalId().then((localId: number) => {  
    console.log('getOsAccountLocalId successfully, localId: ' + localId);  
  }).catch((err: BusinessError) => {  
    console.log('getOsAccountLocalId failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('getOsAccountLocalId exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### getOsAccountLocalIdFromUid<sup>(deprecated)</sup>    
根据uid查询对应的系统帐号ID。使用callback异步回调。  
 **调用形式：**     
- getOsAccountLocalIdFromUid(uid: number, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getOsAccountLocalIdForUid。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid<sup>(deprecated)</sup> | number | true | 进程uid。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数。如果查询成功，err为null，data为对应的系统帐号ID；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let uid: number = 12345678;  
accountManager.getOsAccountLocalIdFromUid(uid, (err: BusinessError, localId: number) => {  
  if (err) {  
    console.log('getOsAccountLocalIdFromUid failed, error: ' + JSON.stringify(err));  
  } else {  
    console.log('getOsAccountLocalIdFromUid successfully, localId: ' + localId);  
  }  
});  
    
```    
  
    
### getOsAccountLocalIdFromUid<sup>(deprecated)</sup>    
根据uid查询对应的系统帐号ID。使用callback异步回调。  
 **调用形式：**     
- getOsAccountLocalIdFromUid(uid: number): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getOsAccountLocalIdForUid。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid<sup>(deprecated)</sup> | number | true | 进程uid。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象，返回uid对应的系统帐号ID。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let uid: number = 12345678;  
accountManager.getOsAccountLocalIdFromUid(uid).then((localId: number) => {  
  console.log('getOsAccountLocalIdFromUid successfully, localId: ' + localId);  
}).catch((err: BusinessError) => {  
  console.log('getOsAccountLocalIdFromUid failed, error: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getOsAccountLocalIdForUid<sup>(9+)</sup>    
根据uid查询对应的系统帐号ID。使用callback异步回调。  
 **调用形式：**     
    
- getOsAccountLocalIdForUid(uid: number, callback: AsyncCallback\<number>): void    
起始版本： 9    
- getOsAccountLocalIdForUid(uid: number): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid | number | true | 进程uid。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果查询成功，err为null，data为对应的系统帐号ID；否则为错误对象。 |  
| Promise<number> | 回调函数。如果查询成功，err为null，data为对应的系统帐号ID；否则为错误对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid authType or authTrustLevel. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let uid: number = 12345678;  
try {  
  accountManager.getOsAccountLocalIdForUid(uid, (err: BusinessError, localId: number) => {  
    if (err) {  
      console.log('getOsAccountLocalIdForUid failed, error: ' + JSON.stringify(err));  
    }  
    console.log('getOsAccountLocalIdForUid successfully, localId: ' + localId);  
  });  
} catch (err) {  
  console.log('getOsAccountLocalIdForUid exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let uid: number = 12345678;  
try {  
  accountManager.getOsAccountLocalIdForUid(uid).then((localId: number) => {  
    console.log('getOsAccountLocalIdForUid successfully, localId: ' + localId);  
  }).catch((err: BusinessError) => {  
    console.log('getOsAccountLocalIdForUid failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('getOsAccountLocalIdForUid exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### getOsAccountLocalIdForUidSync<sup>(10+)</sup>    
根据uid查询对应的系统帐号ID。使用同步方式返回结果。  
 **调用形式：**     
- getOsAccountLocalIdForUidSync(uid: number): number  
  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid | number | true | 进程uid。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回指定uid对应的系统帐号ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300002 | Invalid uid. |  
    
 **示例代码：**   
```ts    
let accountManager = account_osAccount.getAccountManager();  
let uid: number = 12345678;  
try {  
  let localId : number = accountManager.getOsAccountLocalIdForUidSync(uid);  
  console.log('getOsAccountLocalIdForUidSync successfully, localId: ' + localId);  
} catch (err) {  
  console.log('getOsAccountLocalIdForUidSync exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### getOsAccountLocalIdFromDomain<sup>(deprecated)</sup>    
根据域帐号信息，获取与其关联的系统帐号的帐号ID。使用callback异步回调。  
 **调用形式：**     
- getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getOsAccountLocalIdForDomain。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| domainInfo<sup>(deprecated)</sup> | DomainAccountInfo | true | 域帐号信息。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数，如果获取成功，err为null，data为域帐号关联的系统帐号ID；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let domainInfo: account_osAccount.DomainAccountInfo = {domain: 'testDomain', accountName: 'testAccountName'};  
let accountManager = account_osAccount.getAccountManager();  
accountManager.getOsAccountLocalIdFromDomain(domainInfo, (err: BusinessError, localId: number) => {  
  if (err) {  
    console.log('getOsAccountLocalIdFromDomain failed, error: ' + JSON.stringify(err));  
  } else {  
    console.log('getOsAccountLocalIdFromDomain successfully, localId: ' + localId);  
  }  
});  
    
```    
  
    
### getOsAccountLocalIdFromDomain<sup>(deprecated)</sup>    
根据域帐号信息，获取与其关联的系统帐号的帐号ID。使用callback异步回调。  
 **调用形式：**     
- getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getOsAccountLocalIdForDomain。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| domainInfo<sup>(deprecated)</sup> | DomainAccountInfo | true | 域帐号信息。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象，返回域帐号关联的系统帐号ID。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let domainInfo: account_osAccount.DomainAccountInfo = {domain: 'testDomain', accountName: 'testAccountName'};  
accountManager.getOsAccountLocalIdFromDomain(domainInfo).then((localId: number) => {  
  console.log('getOsAccountLocalIdFromDomain successfully, localId: ' + localId);  
}).catch((err: BusinessError) => {  
  console.log('getOsAccountLocalIdFromDomain failed, error: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getOsAccountLocalIdForDomain<sup>(9+)</sup>    
根据域帐号信息，获取与其关联的系统帐号的帐号ID。使用callback异步回调。  
 **调用形式：**     
    
- getOsAccountLocalIdForDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback\<number>): void    
起始版本： 9    
- getOsAccountLocalIdForDomain(domainInfo: DomainAccountInfo): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| domainInfo | DomainAccountInfo | true | 域帐号信息。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，如果获取成功，err为null，data为域帐号关联的系统帐号ID；否则为错误对象。 |  
| Promise<number> | Promise对象，返回域帐号关联的系统帐号ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid authType or authTrustLevel. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let domainInfo: account_osAccount.DomainAccountInfo = {domain: 'testDomain', accountName: 'testAccountName'};  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.getOsAccountLocalIdForDomain(domainInfo, (err: BusinessError, localId: number) => {  
    if (err) {  
      console.log('getOsAccountLocalIdForDomain failed, error: ' + JSON.stringify(err));  
    } else {  
      console.log('getOsAccountLocalIdForDomain successfully, localId: ' + localId);  
    }  
  });  
} catch (err) {  
  console.log('getOsAccountLocalIdForDomain exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let domainInfo: account_osAccount.DomainAccountInfo = {domain: 'testDomain', accountName: 'testAccountName'};  
try {  
  accountManager.getOsAccountLocalIdForDomain(domainInfo).then((localId: number) => {  
    console.log('getOsAccountLocalIdForDomain successfully, localId: ' + localId);  
  }).catch((err: BusinessError) => {  
    console.log('getOsAccountLocalIdForDomain failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('getOsAccountLocalIdForDomain exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### getOsAccountAllConstraints<sup>(deprecated)</sup>    
获取指定系统帐号的全部约束。使用callback异步回调。  
 **调用形式：**     
- getOsAccountAllConstraints(localId: number, callback: AsyncCallback\<Array\<string>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getOsAccountConstraints。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId<sup>(deprecated)</sup> | number | true | 系统帐号ID。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<string>> | true | 回调函数。如果获取成功，err为null，data为指定系统帐号的全部[约束](#系统帐号约束列表)；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
accountManager.getOsAccountAllConstraints(localId, (err: BusinessError, constraints: string[])=>{  
  console.log('getOsAccountAllConstraints err:' + JSON.stringify(err));  
  console.log('getOsAccountAllConstraints:' + JSON.stringify(constraints));  
});  
    
```    
  
    
### getOsAccountAllConstraints<sup>(deprecated)</sup>    
获取指定系统帐号的全部约束。使用callback异步回调。  
 **调用形式：**     
- getOsAccountAllConstraints(localId: number): Promise\<Array\<string>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getOsAccountConstraints。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId<sup>(deprecated)</sup> | number | true | 系统帐号ID。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<string>> | Promise对象，返回指定系统帐号的全部[约束](#系统帐号约束列表)。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
accountManager.getOsAccountAllConstraints(localId).then((constraints: string[]) => {  
  console.log('getOsAccountAllConstraints, constraints: ' + constraints);  
}).catch((err: BusinessError) => {  
  console.log('getOsAccountAllConstraints err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getOsAccountConstraints<sup>(9+)</sup>    
获取指定系统帐号的全部约束。使用callback异步回调。  
 **调用形式：**     
    
- getOsAccountConstraints(localId: number, callback: AsyncCallback\<Array\<string>>): void    
起始版本： 9    
- getOsAccountConstraints(localId: number): Promise\<Array\<string>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId | number | true | 系统帐号ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，如果获取成功，err为null，data为该系统帐号的全部[约束](#系统帐号约束列表)；否则为错误对象。 |  
| Promise<Array<string>> | Promise对象，返回指定系统帐号的全部[约束](#系统帐号约束列表)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid localId. |  
| 12300003 | Account not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
try {  
  accountManager.getOsAccountConstraints(localId, (err: BusinessError, constraints: string[]) => {  
    if (err) {  
      console.log('getOsAccountConstraints failed, err: ' + JSON.stringify(err));  
    } else {  
      console.log('getOsAccountConstraints successfully, constraints: ' + JSON.stringify(constraints));  
    }  
  });  
} catch (err) {  
  console.log('getOsAccountConstraints exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
try {  
  accountManager.getOsAccountConstraints(localId).then((constraints: string[]) => {  
    console.log('getOsAccountConstraints, constraints: ' + constraints);  
  }).catch((err: BusinessError) => {  
    console.log('getOsAccountConstraints err: ' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('getOsAccountConstraints exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### queryActivatedOsAccountIds<sup>(deprecated)</sup>    
查询当前处于激活状态的系统帐号的ID列表。使用callback异步回调。  
 **调用形式：**     
- queryActivatedOsAccountIds(callback: AsyncCallback\<Array\<number>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getActivatedOsAccountLocalIds。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<number>> | true | 回调函数。如果查询成功，err为null，data为当前处于激活状态的系统帐号的ID列表；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
accountManager.queryActivatedOsAccountIds((err: BusinessError, idArray: number[])=>{  
  console.log('queryActivatedOsAccountIds err:' + JSON.stringify(err));  
  console.log('queryActivatedOsAccountIds idArray length:' + idArray.length);  
  for(let i=0;i<idArray.length;i++) {  
    console.info('activated os account id: ' + idArray[i]);  
  }  
});  
    
```    
  
    
### queryActivatedOsAccountIds<sup>(deprecated)</sup>    
查询当前处于激活状态的系统帐号的ID列表。使用callback异步回调。  
 **调用形式：**     
- queryActivatedOsAccountIds(): Promise\<Array\<number>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getActivatedOsAccountLocalIds。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<number>> | Promise对象，返回当前处于激活状态的系统帐号的ID列表。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
accountManager.queryActivatedOsAccountIds((err: BusinessError, idArray: number[])=>{  
  console.log('queryActivatedOsAccountIds err:' + JSON.stringify(err));  
  console.log('queryActivatedOsAccountIds idArray length:' + idArray.length);  
  for(let i=0;i<idArray.length;i++) {  
    console.info('activated os account id: ' + idArray[i]);  
  }  
});  
    
```    
  
    
### getActivatedOsAccountLocalIds<sup>(9+)</sup>    
查询当前处于激活状态的系统帐号的ID列表。使用callback异步回调。  
 **调用形式：**     
    
- getActivatedOsAccountLocalIds(callback: AsyncCallback\<Array\<number>>): void    
起始版本： 9    
- getActivatedOsAccountLocalIds(): Promise\<Array\<number>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果查询成功，err为null，data为当前处于激活状态的系统帐号的ID列表；否则为错误对象。 |  
| Promise<Array<number>> | Promise对象，返回当前处于激活状态的系统帐号的ID列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.getActivatedOsAccountLocalIds((err: BusinessError, idArray: number[])=>{  
    console.log('getActivatedOsAccountLocalIds err:' + JSON.stringify(err));  
    console.log('getActivatedOsAccountLocalIds idArray length:' + idArray.length);  
    for(let i=0;i<idArray.length;i++) {  
      console.info('activated os account id: ' + idArray[i]);  
    }  
  });  
} catch (e) {  
  console.log('getActivatedOsAccountLocalIds exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.getActivatedOsAccountLocalIds((err: BusinessError, idArray: number[])=>{  
    console.log('getActivatedOsAccountLocalIds err:' + JSON.stringify(err));  
    console.log('getActivatedOsAccountLocalIds idArray length:' + idArray.length);  
    for(let i=0;i<idArray.length;i++) {  
      console.info('activated os account id: ' + idArray[i]);  
    }  
  });  
} catch (e) {  
  console.log('getActivatedOsAccountLocalIds exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### queryCurrentOsAccount<sup>(deprecated)</sup>    
查询当前进程所属的系统帐号的信息。使用callback异步回调。  
 **调用形式：**     
- queryCurrentOsAccount(callback: AsyncCallback\<OsAccountInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getCurrentOsAccount。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<OsAccountInfo> | true | 回调函数。如果查询成功，err为null，data为当前进程所属的系统帐号信息；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
accountManager.queryCurrentOsAccount((err: BusinessError, curAccountInfo: account_osAccount.OsAccountInfo)=>{  
  console.log('queryCurrentOsAccount err:' + JSON.stringify(err));  
  console.log('queryCurrentOsAccount curAccountInfo:' + JSON.stringify(curAccountInfo));  
});  
    
```    
  
    
### queryCurrentOsAccount<sup>(deprecated)</sup>    
查询当前进程所属的系统帐号的信息。使用callback异步回调。  
 **调用形式：**     
- queryCurrentOsAccount(): Promise\<OsAccountInfo>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getCurrentOsAccount。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<OsAccountInfo> | Promise对象，返回当前进程所属的系统帐号信息。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
accountManager.queryCurrentOsAccount().then((accountInfo: account_osAccount.OsAccountInfo) => {  
  console.log('queryCurrentOsAccount, accountInfo: ' + JSON.stringify(accountInfo));  
}).catch((err: BusinessError) => {  
  console.log('queryCurrentOsAccount err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getCurrentOsAccount<sup>(9+)</sup>    
查询当前进程所属的系统帐号的信息。使用callback异步回调。  
 **调用形式：**     
    
- getCurrentOsAccount(callback: AsyncCallback\<OsAccountInfo>): void    
起始版本： 9    
- getCurrentOsAccount(callback: AsyncCallback\<OsAccountInfo>): void    
起始版本： 10    
- getCurrentOsAccount(): Promise\<OsAccountInfo>    
起始版本： 9    
- getCurrentOsAccount(): Promise\<OsAccountInfo>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果查询成功，err为null，data为当前进程所属的系统帐号信息；否则为错误对象。 |  
| Promise<OsAccountInfo> | Promise对象，返回当前进程所属的系统帐号信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.getCurrentOsAccount((err: BusinessError, curAccountInfo: account_osAccount.OsAccountInfo)=>{  
    console.log('getCurrentOsAccount err:' + JSON.stringify(err));  
    console.log('getCurrentOsAccount curAccountInfo:' + JSON.stringify(curAccountInfo));  
  });  
} catch (e) {  
  console.log('getCurrentOsAccount exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.getCurrentOsAccount().then((accountInfo: account_osAccount.OsAccountInfo) => {  
    console.log('getCurrentOsAccount, accountInfo: ' + JSON.stringify(accountInfo));  
  }).catch((err: BusinessError) => {  
    console.log('getCurrentOsAccount err: ' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('getCurrentOsAccount exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### getOsAccountTypeFromProcess<sup>(deprecated)</sup>    
查询当前进程所属的系统帐号的帐号类型。使用callback异步回调。  
 **调用形式：**     
- getOsAccountTypeFromProcess(callback: AsyncCallback\<OsAccountType>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getOsAccountType。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<OsAccountType> | true | 回调函数。如果查询成功，err为null，data为当前进程所属的系统帐号的帐号类型；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
accountManager.getOsAccountTypeFromProcess((err: BusinessError, accountType: account_osAccount.OsAccountType) => {  
  console.log('getOsAccountTypeFromProcess err: ' + JSON.stringify(err));  
  console.log('getOsAccountTypeFromProcess accountType: ' + accountType);  
});  
    
```    
  
    
### getOsAccountTypeFromProcess<sup>(deprecated)</sup>    
查询当前进程所属的系统帐号的帐号类型。使用callback异步回调。  
 **调用形式：**     
- getOsAccountTypeFromProcess(): Promise\<OsAccountType>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getOsAccountType。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<OsAccountType> | Promise对象，返回当前进程所属的系统帐号的帐号类型。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
accountManager.getOsAccountTypeFromProcess().then((accountType: account_osAccount.OsAccountType) => {  
  console.log('getOsAccountTypeFromProcess, accountType: ' + accountType);  
}).catch((err: BusinessError) => {  
  console.log('getOsAccountTypeFromProcess err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getOsAccountType<sup>(9+)</sup>    
查询当前进程所属的系统帐号的帐号类型。使用callback异步回调。  
 **调用形式：**     
    
- getOsAccountType(callback: AsyncCallback\<OsAccountType>): void    
起始版本： 9    
- getOsAccountType(): Promise\<OsAccountType>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果查询成功，err为null，data为当前进程所属的系统帐号的帐号类型；否则为错误对象。 |  
| Promise<OsAccountType> | Promise对象，返回当前进程所属的系统帐号的帐号类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.getOsAccountType((err: BusinessError, accountType: account_osAccount.OsAccountType) => {  
    console.log('getOsAccountType err: ' + JSON.stringify(err));  
    console.log('getOsAccountType accountType: ' + accountType);  
  });  
} catch (e) {  
  console.log('getOsAccountType exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.getOsAccountType().then((accountType: account_osAccount.OsAccountType) => {  
    console.log('getOsAccountType, accountType: ' + accountType);  
  }).catch((err: BusinessError) => {  
    console.log('getOsAccountType err: ' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('getOsAccountType exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### getDistributedVirtualDeviceId<sup>(deprecated)</sup>    
获取分布式虚拟设备ID。使用callback异步回调。  
 **调用形式：**     
- getDistributedVirtualDeviceId(callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#queryDistributedVirtualDeviceId。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC or ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 回调函数。如果获取成功，err为null，data为分布式虚拟设备ID；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
accountManager.getDistributedVirtualDeviceId((err: BusinessError, virtualID: string) => {  
  console.log('getDistributedVirtualDeviceId err: ' + JSON.stringify(err));  
  console.log('getDistributedVirtualDeviceId virtualID: ' + virtualID);  
});  
    
```    
  
    
### getDistributedVirtualDeviceId<sup>(deprecated)</sup>    
获取分布式虚拟设备ID。使用callback异步回调。  
 **调用形式：**     
- getDistributedVirtualDeviceId(): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#queryDistributedVirtualDeviceId。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC or ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise对象，返回分布式虚拟设备ID。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
accountManager.getDistributedVirtualDeviceId().then((virtualID: string) => {  
  console.log('getDistributedVirtualDeviceId, virtualID: ' + virtualID);  
}).catch((err: BusinessError) => {  
  console.log('getDistributedVirtualDeviceId err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### queryDistributedVirtualDeviceId<sup>(9+)</sup>    
获取分布式虚拟设备ID。使用callback异步回调。  
 **调用形式：**     
    
- queryDistributedVirtualDeviceId(callback: AsyncCallback\<string>): void    
起始版本： 9    
- queryDistributedVirtualDeviceId(): Promise\<string>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.DISTRIBUTED_DATASYNC or ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果获取成功，err为null，data为分布式虚拟设备ID；否则为错误对象。 |  
| Promise<string> | Promise对象，返回分布式虚拟设备ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.queryDistributedVirtualDeviceId((err: BusinessError, virtualID: string) => {  
    console.log('queryDistributedVirtualDeviceId err: ' + JSON.stringify(err));  
    console.log('queryDistributedVirtualDeviceId virtualID: ' + virtualID);  
  });  
} catch (e) {  
  console.log('queryDistributedVirtualDeviceId exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.queryDistributedVirtualDeviceId().then((virtualID: string) => {  
    console.log('queryDistributedVirtualDeviceId, virtualID: ' + virtualID);  
  }).catch((err: BusinessError) => {  
    console.log('queryDistributedVirtualDeviceId err: ' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('queryDistributedVirtualDeviceId exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### getOsAccountLocalIdBySerialNumber<sup>(deprecated)</sup>    
通过SN码查询与其关联的系统帐号的帐号ID。使用callback异步回调。  
 **调用形式：**     
- getOsAccountLocalIdBySerialNumber(serialNumber: number, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getOsAccountLocalIdForSerialNumber。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| serialNumber<sup>(deprecated)</sup> | number | true | 帐号SN码。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数。如果查询成功，err为null，data为与SN码关联的系统帐号的帐号ID；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let serialNumber: number = 12345;  
accountManager.getOsAccountLocalIdBySerialNumber(serialNumber, (err: BusinessError, localId: number)=>{  
  console.log('ger localId err:' + JSON.stringify(err));  
  console.log('get localId:' + localId + ' by serialNumber: ' + serialNumber);  
});  
    
```    
  
    
### getOsAccountLocalIdBySerialNumber<sup>(deprecated)</sup>    
通过SN码查询与其关联的系统帐号的帐号ID。使用callback异步回调。  
 **调用形式：**     
- getOsAccountLocalIdBySerialNumber(serialNumber: number): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getOsAccountLocalIdForSerialNumber。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| serialNumber<sup>(deprecated)</sup> | number | true | 帐号SN码。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象，返回与SN码关联的系统帐号的帐号ID。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let serialNumber: number = 12345;  
accountManager.getOsAccountLocalIdBySerialNumber(serialNumber).then((localId: number) => {  
  console.log('getOsAccountLocalIdBySerialNumber localId: ' + localId);  
}).catch((err: BusinessError) => {  
  console.log('getOsAccountLocalIdBySerialNumber err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getOsAccountLocalIdForSerialNumber<sup>(9+)</sup>    
通过SN码查询与其关联的系统帐号的帐号ID。使用callback异步回调。  
 **调用形式：**     
    
- getOsAccountLocalIdForSerialNumber(serialNumber: number, callback: AsyncCallback\<number>): void    
起始版本： 9    
- getOsAccountLocalIdForSerialNumber(serialNumber: number): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| serialNumber | number | true | 帐号SN码。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果成功，err为null，data为与SN码关联的系统帐号的帐号ID；否则为错误对象。 |  
| Promise<number> | Promise对象，返回与SN码关联的系统帐号的帐号ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid serialNumber. |  
| 12300003 | The account indicated by serialNumber dose not exist. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let serialNumber: number = 12345;  
try {  
  accountManager.getOsAccountLocalIdForSerialNumber(serialNumber, (err: BusinessError, localId: number)=>{  
    console.log('ger localId err:' + JSON.stringify(err));  
    console.log('get localId:' + localId + ' by serialNumber: ' + serialNumber);  
  });  
} catch (e) {  
  console.log('ger localId exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let serialNumber: number = 12345;  
try {  
  accountManager.getOsAccountLocalIdForSerialNumber(serialNumber).then((localId: number) => {  
    console.log('getOsAccountLocalIdForSerialNumber localId: ' + localId);  
  }).catch((err: BusinessError) => {  
    console.log('getOsAccountLocalIdForSerialNumber err: ' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('getOsAccountLocalIdForSerialNumber exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### getSerialNumberByOsAccountLocalId<sup>(deprecated)</sup>    
通过系统帐号ID获取与该系统帐号关联的SN码。使用callback异步回调。  
 **调用形式：**     
- getSerialNumberByOsAccountLocalId(localId: number, callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getSerialNumberForOsAccountLocalId。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId<sup>(deprecated)</sup> | number | true | 系统帐号ID。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 回调函数。如果获取成功，err为null，data为与该系统帐号关联的SN码；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
accountManager.getSerialNumberByOsAccountLocalId(localId, (err: BusinessError, serialNumber: number)=>{  
  console.log('ger serialNumber err:' + JSON.stringify(err));  
  console.log('get serialNumber:' + serialNumber + ' by localId: ' + localId);  
});  
    
```    
  
    
### getSerialNumberByOsAccountLocalId<sup>(deprecated)</sup>    
通过系统帐号ID获取与该系统帐号关联的SN码。使用callback异步回调。  
 **调用形式：**     
- getSerialNumberByOsAccountLocalId(localId: number): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: osAccount.AccountManager#getSerialNumberForOsAccountLocalId。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId<sup>(deprecated)</sup> | number | true | 系统帐号ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | Promise对象，返回与该系统帐号关联的SN码。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
accountManager.getSerialNumberByOsAccountLocalId(localId).then((serialNumber: number) => {  
  console.log('getSerialNumberByOsAccountLocalId serialNumber: ' + serialNumber);  
}).catch((err: BusinessError) => {  
  console.log('getSerialNumberByOsAccountLocalId err: ' + JSON.stringify(err));  
});  
    
```    
  
    
### getSerialNumberForOsAccountLocalId<sup>(9+)</sup>    
通过系统帐号ID获取与该系统帐号关联的SN码。使用callback异步回调。  
 **调用形式：**     
    
- getSerialNumberForOsAccountLocalId(localId: number, callback: AsyncCallback\<number>): void    
起始版本： 9    
- getSerialNumberForOsAccountLocalId(localId: number): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId | number | true | 系统帐号ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果获取成功，err为null，data为与该系统帐号关联的SN码；否则为错误对象。 |  
| Promise<number> | Promise对象，返回与该系统帐号关联的SN码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid localId. |  
| 12300003 | Account not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
try {  
  accountManager.getSerialNumberForOsAccountLocalId(localId, (err: BusinessError, serialNumber: number)=>{  
    console.log('ger serialNumber err:' + JSON.stringify(err));  
    console.log('get serialNumber:' + serialNumber + ' by localId: ' + localId);  
  });  
} catch (e) {  
  console.log('ger serialNumber exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
try {  
  accountManager.getSerialNumberForOsAccountLocalId(localId).then((serialNumber: number) => {  
    console.log('getSerialNumberForOsAccountLocalId serialNumber: ' + serialNumber);  
  }).catch((err: BusinessError) => {  
    console.log('getSerialNumberForOsAccountLocalId err: ' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('getSerialNumberForOsAccountLocalId exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
## OsAccountInfo    
表示系统帐号信息。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| localId | number | false | true | 系统帐号ID。 |  
| localName | string | false | true | 系统帐号名称。 |  
| type | OsAccountType | false | true | 系统帐号类型。 |  
| constraints | Array<string> | false | true | 系统帐号[约束](#系统帐号约束列表)，默认为空。 |  
| isVerified<sup>(8+)</sup> | boolean | false | true | 帐号是否验证。 |  
| photo<sup>(8+)</sup> | string | false | true | 系统帐号头像，默认为空。 |  
| createTime<sup>(8+)</sup> | number | false | true | 系统帐号创建时间。 |  
| lastLoginTime<sup>(8+)</sup> | number | false | true | 系统帐号最后一次登录时间，默认为空。 |  
| serialNumber<sup>(8+)</sup> | number | false | true | 系统帐号SN码。 |  
| isActived<sup>(8+)</sup> | boolean | false | true | 系统帐号激活状态。 |  
| isCreateCompleted<sup>(8+)</sup> | boolean | false | true | 系统帐号创建是否完整。 |  
| distributedInfo | distributedAccount.DistributedInfo | false | true | 分布式帐号信息，默认为空。 |  
| domainInfo<sup>(8+)</sup> | DomainAccountInfo | false | true | 域帐号信息，默认为空。 |  
    
## DomainAccountInfo<sup>(8+)</sup>    
表示域帐号信息。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| domain<sup>(8+)</sup> | string | false | true | 域名。 |  
| accountName<sup>(8+)</sup> | string | false | true | 域帐号名。 |  
    
## OsAccountType    
表示系统帐号类型的枚举。    
    
 **系统能力:**  SystemCapability.Account.OsAccount    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ADMIN | 0 | 管理员帐号。 |  
| NORMAL | 1 | 普通帐号。 |  
| GUEST | 2 | 访客帐号。 |  
