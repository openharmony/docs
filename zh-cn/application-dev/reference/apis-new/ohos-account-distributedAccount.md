# @ohos.account.distributedAccount    
本模块提供管理分布式帐号的一些基础功能，主要包括查询和更新帐号登录状态。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import distributedAccount from '@ohos.account.distributedAccount'    
```  
    
## getDistributedAccountAbility    
  
  
获取分布式帐号单实例对象。  
 **调用形式：**     
- getDistributedAccountAbility(): DistributedAccountAbility  
  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DistributedAccountAbility | 返回一个实例，实例提供查询和更新分布式帐号登录状态方法。 |  
    
 **示例代码：**   
```ts    
const accountAbility = account_distributedAccount.getDistributedAccountAbility();    
```    
  
    
## DistributedAccountAbility    
提供查询和更新分布式帐号登录状态方法(需要先获取分布式帐号的单实例对象)。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### queryOsAccountDistributedInfo<sup>(deprecated)</sup>    
获取分布式帐号信息。使用callback异步回调。  
 **调用形式：**     
- queryOsAccountDistributedInfo(callback: AsyncCallback\<DistributedInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: distributedAccount.DistributedAccountAbility#getOsAccountDistributedInfo。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.DISTRIBUTED_DATASYNC    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<DistributedInfo> | true | 回调函数。当获取分布式帐号信息成功，err为undefined，data为获取到的分布式帐号信息对象；否则为错误对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
const accountAbility = account_distributedAccount.getDistributedAccountAbility();  
accountAbility.queryOsAccountDistributedInfo(  
  (err: BusinessError, data: account_distributedAccount.DistributedInfo) => {  
    if (err) {  
      console.log('queryOsAccountDistributedInfo exception: ' + JSON.stringify(err));  
    } else {  
      console.log('distributed information: ' + JSON.stringify(data));  
    }  
  });  
    
```    
  
    
### queryOsAccountDistributedInfo<sup>(deprecated)</sup>    
获取分布式帐号信息。使用callback异步回调。  
 **调用形式：**     
- queryOsAccountDistributedInfo(): Promise\<DistributedInfo>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: distributedAccount.DistributedAccountAbility#getOsAccountDistributedInfo。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.DISTRIBUTED_DATASYNC    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<DistributedInfo> | Promise对象，返回分布式帐号信息对象。 |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
  
const accountAbility = account_distributedAccount.getDistributedAccountAbility();  
accountAbility.queryOsAccountDistributedInfo().then((data: account_distributedAccount.DistributedInfo) => {  
    console.log('distributed information: ' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
    console.log('queryOsAccountDistributedInfo exception: '  + JSON.stringify(err));  
});  
    
```    
  
    
### getOsAccountDistributedInfo<sup>(9+)</sup>    
获取分布式帐号信息，使用callback异步回调。  
 **调用形式：**     
    
- getOsAccountDistributedInfo(callback: AsyncCallback\<DistributedInfo>): void    
起始版本： 9    
- getOsAccountDistributedInfo(): Promise\<DistributedInfo>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS or ohos.permission.GET_DISTRIBUTED_ACCOUNTS or ohos.permission.DISTRIBUTED_DATASYNC    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调参数。当获取分布式帐号信息成功，err为undefined，data为获取到的分布式帐号信息对象；否则为错误对象。 |  
| Promise<DistributedInfo> |  |  
    
    
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
  
const accountAbility = account_distributedAccount.getDistributedAccountAbility();  
try {  
  accountAbility.getOsAccountDistributedInfo(  
    (err: BusinessError, data: account_distributedAccount.DistributedInfo) => {  
      if (err) {  
        console.log('getOsAccountDistributedInfo exception: ' + JSON.stringify(err));  
      } else {  
        console.log('distributed information: ' + JSON.stringify(data));  
      }  
    });  
} catch (err) {  
  console.log('getOsAccountDistributedInfo exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
const accountAbility = account_distributedAccount.getDistributedAccountAbility();  
try {  
  accountAbility.getOsAccountDistributedInfo().then((data: account_distributedAccount.DistributedInfo) => {  
      console.log('distributed information: ' + JSON.stringify(data));  
  }).catch((err: BusinessError) => {  
      console.log('getOsAccountDistributedInfo exception: '  + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('getOsAccountDistributedInfo exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### updateOsAccountDistributedInfo<sup>(deprecated)</sup>    
更新分布式帐号信息。使用callback异步回调。  
 **调用形式：**     
- updateOsAccountDistributedInfo(accountInfo: DistributedInfo, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: distributedAccount.DistributedAccountAbility#setOsAccountDistributedInfo。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| accountInfo<sup>(deprecated)</sup> | DistributedInfo | true | 分布式帐号信息。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当更新分布式帐号信息成功时，err为undefined，否则为错误对象。 |  
    
 **示例代码：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
const accountAbility = account_distributedAccount.getDistributedAccountAbility();  
let accountInfo: account_distributedAccount.DistributedInfo =  
  {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};  
accountAbility.updateOsAccountDistributedInfo(accountInfo, (err: BusinessError) => {  
  if (err) {  
    console.log('queryOsAccountDistributedInfo exception: ' + JSON.stringify(err));  
  } else {  
    console.log('queryOsAccountDistributedInfo successfully');  
  }  
});  
    
```    
  
    
### updateOsAccountDistributedInfo<sup>(deprecated)</sup>    
更新分布式帐号信息。使用callback异步回调。  
 **调用形式：**     
- updateOsAccountDistributedInfo(accountInfo: DistributedInfo): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: distributedAccount.DistributedAccountAbility#setOsAccountDistributedInfo。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| accountInfo<sup>(deprecated)</sup> | DistributedInfo | true | 分布式帐号信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | Promise对象，无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
const accountAbility = account_distributedAccount.getDistributedAccountAbility();  
let accountInfo: account_distributedAccount.DistributedInfo =  
  {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};  
accountAbility.updateOsAccountDistributedInfo(accountInfo).then(() => {  
    console.log('updateOsAccountDistributedInfo successfully');  
 }).catch((err: BusinessError) => {  
    console.log('updateOsAccountDistributedInfo exception: '  + JSON.stringify(err));  
});  
    
```    
  
    
### setOsAccountDistributedInfo<sup>(9+)</sup>    
更新分布式帐号信息。使用callback异步回调。  
 **调用形式：**     
    
- setOsAccountDistributedInfo(accountInfo: DistributedInfo, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setOsAccountDistributedInfo(accountInfo: DistributedInfo): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| accountInfo | DistributedInfo | true | 分布式帐号信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当更新分布式帐号信息成功时，err为undefined，否则为错误对象。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid accountInfo. |  
| 12300003 | Account not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
const accountAbility = account_distributedAccount.getDistributedAccountAbility();  
let accountInfo: account_distributedAccount.DistributedInfo =  
  {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};  
try {  
  accountAbility.setOsAccountDistributedInfo(accountInfo, (err: BusinessError) => {  
    if (err) {  
      console.log('setOsAccountDistributedInfo exception: ' + JSON.stringify(err));  
    } else {  
      console.log('setOsAccountDistributedInfo successfully');  
    }  
  });  
} catch (err) {  
    console.log('setOsAccountDistributedInfo exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
const accountAbility = account_distributedAccount.getDistributedAccountAbility();  
let accountInfo: account_distributedAccount.DistributedInfo =  
  {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};  
try {  
  accountAbility.setOsAccountDistributedInfo(accountInfo).then(() => {  
      console.log('setOsAccountDistributedInfo successfully');  
  }).catch((err: BusinessError) => {  
      console.log('setOsAccountDistributedInfo exception: '  + JSON.stringify(err));  
  });  
} catch (err) {  
    console.log('setOsAccountDistributedInfo exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
## DistributedAccountStatus<sup>(10+)</sup>    
表示分布式帐号状态枚举。    
    
 **系统能力:**  SystemCapability.Account.OsAccount    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NOT_LOGGED_IN | 0 | 未登录状态。 |  
| LOGGED_IN | 1 | 已登录状态。 |  
    
## DistributedInfo    
提供操作系统帐号的分布式信息。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | false | true | 分布式帐号名称，非空字符串。 |  
| id | string | false | true | 分布式帐号UID，非空字符串。 |  
| event | string | false | true | 分布式帐号登录状态，包括登录、登出、Token失效和注销，分别对应以下字符串：<br/>-Ohos.account.event.LOGIN<br/>-Ohos.account.event.LOGOUT<br/>-Ohos.account.event.TOKEN_INVALID<br/>-Ohos.account.event.LOGOFF |  
| nickname<sup>(9+)</sup> | string | false | false | 分布式帐号的昵称，默认为空。 |  
| avatar<sup>(9+)</sup> | string | false | false | 分布式帐号的头像，默认为空。  |  
| status<sup>(10+)</sup> | DistributedAccountStatus | true | false | 分布式帐号的状态，枚举类型，默认为未登录状态。  |  
| scalableData<sup>(8+)</sup> | object | false | false | 分布式帐号扩展信息，根据业务所需，以k-v形式传递定制化信息，默认为空。 |  
    
 **示例代码：**   
```ts    
import account_distributedAccount from '@ohos.account.distributedAccount';    
```    
  
