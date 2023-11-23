# @ohos.account.distributedAccount    
本模块提供管理分布式帐号的一些基础功能，主要包括查询和更新帐号登录状态。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import distributedAccount from '@ohos.account.distributedAccount'    
```  
    
## DistributedAccountAbility    
提供查询和更新分布式帐号登录状态方法(需要先获取分布式帐号的单实例对象)。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### getOsAccountDistributedInfoByLocalId<sup>(10+)</sup>    
获取指定系统帐号的分布式信息。使用callback异步回调。  
 **调用形式：**     
    
- getOsAccountDistributedInfoByLocalId(localId: number, callback: AsyncCallback\<DistributedInfo>): void    
起始版本： 10    
- getOsAccountDistributedInfoByLocalId(localId: number): Promise\<DistributedInfo>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId | number | true | 系统帐号ID。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调参数。当获取分布式帐号信息成功，err为undefined，data为获取到的分布式帐号信息对象；否则为错误对象。 |  
| Promise<DistributedInfo> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300003 | Account not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
const accountAbility = account_distributedAccount.getDistributedAccountAbility();  
try {  
  accountAbility.getOsAccountDistributedInfoByLocalId(100,  
    (err: BusinessError, data: account_distributedAccount.DistributedInfo) => {  
      if (err) {  
        console.log('getOsAccountDistributedInfoByLocalId exception: ' + JSON.stringify(err));  
      } else {  
        console.log('distributed information: ' + JSON.stringify(data));  
      }  
    });  
} catch (err) {  
  console.log('getOsAccountDistributedInfoByLocalId exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
const accountAbility = account_distributedAccount.getDistributedAccountAbility();  
try {  
  accountAbility.getOsAccountDistributedInfoByLocalId(100).then((  
    data: account_distributedAccount.DistributedInfo) => {  
    console.log('distributed information: ' + JSON.stringify(data));  
  }).catch((err: BusinessError) => {  
    console.log('getOsAccountDistributedInfoByLocalId exception: '  + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('getOsAccountDistributedInfoByLocalId exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### setOsAccountDistributedInfoByLocalId<sup>(10+)</sup>    
设置指定系统帐号的分布式信息。使用callback异步回调。  
 **调用形式：**     
    
- setOsAccountDistributedInfoByLocalId(       localId: number,       distributedInfo: DistributedInfo,       callback: AsyncCallback\<void>     ): void    
起始版本： 10    
- setOsAccountDistributedInfoByLocalId(localId: number, distributedInfo: DistributedInfo): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId | number | true | 系统帐号ID。  |  
| distributedInfo | DistributedInfo | true |  分布式帐号信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid distributedInfo. |  
| 12300003 | Account identified by localId or by distributedInfo not found. |  
| 12300008 | Restricted OS account. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
const accountAbility = account_distributedAccount.getDistributedAccountAbility();  
let accountInfo: account_distributedAccount.DistributedInfo =  
  {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};  
try {  
  accountAbility.setOsAccountDistributedInfoByLocalId(100, accountInfo, (err: BusinessError) => {  
    if (err) {  
      console.log('setOsAccountDistributedInfoByLocalId exception: ' + JSON.stringify(err));  
    } else {  
      console.log('setOsAccountDistributedInfoByLocalId successfully');  
    }  
  });  
} catch (err) {  
    console.log('setOsAccountDistributedInfoByLocalId exception: ' + JSON.stringify(err));  
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
  accountAbility.setOsAccountDistributedInfoByLocalId(100, accountInfo).then(() => {  
      console.log('setOsAccountDistributedInfoByLocalId successfully');  
  }).catch((err: BusinessError) => {  
      console.log('setOsAccountDistributedInfoByLocalId exception: '  + JSON.stringify(err));  
  });  
} catch (err) {  
    console.log('setOsAccountDistributedInfoByLocalId exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码：**   
```ts    
import account_distributedAccount from '@ohos.account.distributedAccount';    
```    
  
