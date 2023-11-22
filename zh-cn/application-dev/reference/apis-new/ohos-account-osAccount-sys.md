# @ohos.account.osAccount    
本模块提供管理系统帐号的基础能力，包括系统帐号的添加、删除、查询、设置、订阅、启动等功能。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import osAccount from '@ohos.account.osAccount'    
```  
    
## AccountManager    
系统帐号管理类。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### activateOsAccount    
激活指定系统帐号。使用callback异步回调。  
 **调用形式：**     
    
- activateOsAccount(localId: number, callback: AsyncCallback\<void>): void    
起始版本： 7    
- activateOsAccount(localId: number): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId | number | true | 系统帐号ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当帐号激活成功时，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象，无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid localId. |  
| 12300003 | Account not found. |  
| 12300008 | Restricted Account. |  
| 12300009 | Account has been activated. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let localId: number = 100;  
try {  
  accountManager.activateOsAccount(localId, (err: BusinessError)=>{  
    if (err) {  
      console.error(`activateOsAccount failed, code is ${err.code}, message is ${err.message}`);  
    } else {  
      console.log('activateOsAccount successfully');  
    }  
  });  
} catch (err) {  
  console.log('activateOsAccount failed, error:' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
try {  
  accountManager.activateOsAccount(localId).then(() => {  
    console.log('activateOsAccount successfully');  
  }).catch((err: BusinessError) => {  
    console.log('activateOsAccount failed, err:' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('activateOsAccount exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### removeOsAccount  
 **调用形式：**     
    
- removeOsAccount(localId: number, callback: AsyncCallback\<void>): void    
起始版本： 7    
- removeOsAccount(localId: number): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId | number | true | 系统帐号ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果删除帐号成功，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象，无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid localId. |  
| 12300003 | Account not found. |  
| 12300008 | Restricted Account |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let accountName: string = 'testAccountName';  
try {  
  accountManager.createOsAccount(accountName, account_osAccount.OsAccountType.NORMAL,  
    (err: BusinessError, osAccountInfo: account_osAccount.OsAccountInfo) => {  
      accountManager.removeOsAccount(osAccountInfo.localId, (err: BusinessError)=>{  
        if (err) {  
          console.log('removeOsAccount failed, error: ' + JSON.stringify(err));  
        } else {  
          console.log('removeOsAccount successfully');  
        }  
    });  
  });  
} catch (err) {  
  console.log('removeOsAccount exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let accountName: string = 'testAccountName';  
try {  
  accountManager.createOsAccount(accountName, account_osAccount.OsAccountType.NORMAL,  
    (err: BusinessError, osAccountInfo: account_osAccount.OsAccountInfo)=>{  
      accountManager.removeOsAccount(osAccountInfo.localId).then(() => {  
        console.log('removeOsAccount successfully');  
      }).catch((err: BusinessError) => {  
          console.log('removeOsAccount failed, error: ' + JSON.stringify(err));  
      });  
  });  
} catch (err) {  
  console.log('removeOsAccount exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### setOsAccountConstraints    
为指定系统帐号设置/删除约束。使用callback异步回调。  
 **调用形式：**     
    
- setOsAccountConstraints(       localId: number,       constraints: Array\<string>,       enable: boolean,       callback: AsyncCallback\<void>     ): void    
起始版本： 7    
- setOsAccountConstraints(localId: number, constraints: Array\<string>, enable: boolean): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId | number | true | 系统帐号ID。 |  
| constraints | Array<string> | true | 待设置/删除的[约束](#系统帐号约束列表)列表。 |  
| enable | boolean | true | 设置(true)/删除(false) |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果设置成功，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象，无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid localId or constraints. |  
| 12300003 | Account not found. |  
| 12300008 | Restricted Account. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
let constraint: string = 'constraint.wifi';  
try {  
  accountManager.setOsAccountConstraints(localId, [constraint], true, (err: BusinessError) => {  
    if (err) {  
      console.log('setOsAccountConstraints failed, error: ' + JSON.stringify(err));  
    } else {  
      console.log('setOsAccountConstraints successfully');  
    }  
  });  
} catch (err) {  
  console.log('setOsAccountConstraints exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
try {  
  accountManager.setOsAccountConstraints(localId, ['constraint.location.set'], false).then(() => {  
    console.log('setOsAccountConstraints succsuccessfully');  
  }).catch((err: BusinessError) => {  
    console.log('setOsAccountConstraints failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('setOsAccountConstraints exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### setOsAccountName  
 **调用形式：**     
    
- setOsAccountName(localId: number, localName: string, callback: AsyncCallback\<void>): void    
起始版本： 7    
- setOsAccountName(localId: number, localName: string): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId | number | true | 系统帐号ID。 |  
| localName | string | true | 帐号名，最大长度为1024个字符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果设置成功，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象，无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid localId or localName. |  
| 12300003 | Account not found. |  
| 12300008 | Restricted Account. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
let name: string = 'demoName';  
try {  
  accountManager.setOsAccountName(localId, name, (err: BusinessError) => {  
    if (err) {  
      console.log('setOsAccountName failed, error: ' + JSON.stringify(err));  
    } else {  
      console.log('setOsAccountName successfully');  
    }  
  });  
} catch (err) {  
  console.log('setOsAccountName exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
let name: string = 'testName';  
try {  
  accountManager.setOsAccountName(localId, name).then(() => {  
    console.log('setOsAccountName successfully');  
  }).catch((err: BusinessError) => {  
    console.log('setOsAccountName failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('setOsAccountName exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### queryMaxOsAccountNumber    
查询允许创建的系统帐号的最大数量。使用callback异步回调。  
 **调用形式：**     
    
- queryMaxOsAccountNumber(callback: AsyncCallback\<number>): void    
起始版本： 7    
- queryMaxOsAccountNumber(): Promise\<number>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，如果查询成功，err为null，data为允许创建的系统帐号的最大数量；否则为错误对象。 |  
| Promise<number> | Promise对象，返回允许创建的系统帐号的最大数量。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.queryMaxOsAccountNumber((err: BusinessError, maxCnt: number) => {  
    if (err) {  
      console.log('queryMaxOsAccountNumber failed, error:' + JSON.stringify(err));  
    } else {  
      console.log('queryMaxOsAccountNumber successfully, maxCnt:' + maxCnt);  
    }  
  });  
} catch (err) {  
  console.log('queryMaxOsAccountNumber exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.queryMaxOsAccountNumber().then((maxCnt: number) => {  
    console.log('queryMaxOsAccountNumber successfully, maxCnt: ' + maxCnt);  
  }).catch((err: BusinessError) => {  
    console.log('queryMaxOsAccountNumber failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('queryMaxOsAccountNumber exception: ' + JSON.stringify(err));  
}  
    
```    
  
    
### queryAllCreatedOsAccounts    
查询已创建的所有系统帐号的信息列表。使用callback异步回调。  
 **调用形式：**     
    
- queryAllCreatedOsAccounts(callback: AsyncCallback\<Array\<OsAccountInfo>>): void    
起始版本： 7    
- queryAllCreatedOsAccounts(): Promise\<Array\<OsAccountInfo>>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果查询成功，err为null，data为已创建的所有系统帐号的信息列表；否则为错误对象。 |  
| Promise<Array<OsAccountInfo>> | Promise对象，返回已创建的所有系统帐号的信息列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.queryAllCreatedOsAccounts((err: BusinessError, accountArr: account_osAccount.OsAccountInfo[])=>{  
    console.log('queryAllCreatedOsAccounts err:' + JSON.stringify(err));  
    console.log('queryAllCreatedOsAccounts accountArr:' + JSON.stringify(accountArr));  
  });  
} catch (e) {  
  console.log('queryAllCreatedOsAccounts exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.queryAllCreatedOsAccounts().then((accountArr: account_osAccount.OsAccountInfo[]) => {  
    console.log('queryAllCreatedOsAccounts, accountArr: ' + JSON.stringify(accountArr));  
  }).catch((err: BusinessError) => {  
    console.log('queryAllCreatedOsAccounts err: ' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('queryAllCreatedOsAccounts exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### createOsAccount    
创建一个系统帐号。使用callback异步回调。  
 **调用形式：**     
    
- createOsAccount(localName: string, type: OsAccountType, callback: AsyncCallback\<OsAccountInfo>): void    
起始版本： 7    
- createOsAccount(localName: string, type: OsAccountType): Promise\<OsAccountInfo>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localName | string | true | 创建的系统帐号的名称。 |  
| type | OsAccountType | true | 创建的系统帐号的类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果创建成功，err为null，data为新创建的系统帐号的信息；否则为错误对象。 |  
| Promise<OsAccountInfo> | Promise对象，返回新创建的系统帐号的信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid localName or type. |  
| 12300005 | Multi-user not supported. |  
| 12300006 | Unsupported account type. |  
| 12300007 | The number of accounts reaches the upper limit. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.createOsAccount('testName', account_osAccount.OsAccountType.NORMAL,  
    (err: BusinessError, osAccountInfo: account_osAccount.OsAccountInfo)=>{  
    console.log('createOsAccount err:' + JSON.stringify(err));  
    console.log('createOsAccount osAccountInfo:' + JSON.stringify(osAccountInfo));  
  });  
} catch (e) {  
  console.log('createOsAccount exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.createOsAccount('testAccountName', account_osAccount.OsAccountType.NORMAL).then(  
    (accountInfo: account_osAccount.OsAccountInfo) => {  
    console.log('createOsAccount, accountInfo: ' + JSON.stringify(accountInfo));  
  }).catch((err: BusinessError) => {  
    console.log('createOsAccount err: ' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('createOsAccount exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### createOsAccountForDomain<sup>(8+)</sup>    
根据域帐号信息，创建一个系统帐号并将其与域帐号关联。使用callback异步回调。  
 **调用形式：**     
    
- createOsAccountForDomain(       type: OsAccountType,       domainInfo: DomainAccountInfo,       callback: AsyncCallback\<OsAccountInfo>     ): void    
起始版本： 8    
- createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo): Promise\<OsAccountInfo>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | OsAccountType | true | 创建的系统帐号的类型。 |  
| domainInfo | DomainAccountInfo | true | 域帐号信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果创建成功，err为null，data为新创建的系统帐号的信息；否则为错误对象。 |  
| Promise<OsAccountInfo> | Promise对象，返回新创建的系统帐号的信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid type or domainInfo. |  
| 12300005 | Multi-user not supported. |  
| 12300006 | Unsupported account type. |  
| 12300007 | The number of accounts reaches the upper limit. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let domainInfo: account_osAccount.DomainAccountInfo =  
  {domain: 'testDomain', accountName: 'testAccountName'};  
try {  
  accountManager.createOsAccountForDomain(account_osAccount.OsAccountType.NORMAL, domainInfo,  
    (err: BusinessError, osAccountInfo: account_osAccount.OsAccountInfo)=>{  
    console.log('createOsAccountForDomain err:' + JSON.stringify(err));  
    console.log('createOsAccountForDomain osAccountInfo:' + JSON.stringify(osAccountInfo));  
  });  
} catch (e) {  
  console.log('createOsAccountForDomain exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let domainInfo: account_osAccount.DomainAccountInfo =  
  {domain: 'testDomain', accountName: 'testAccountName'};  
try {  
  accountManager.createOsAccountForDomain(account_osAccount.OsAccountType.NORMAL, domainInfo).then(  
    (accountInfo: account_osAccount.OsAccountInfo) => {  
    console.log('createOsAccountForDomain, account info: ' + JSON.stringify(accountInfo));  
  }).catch((err: BusinessError) => {  
    console.log('createOsAccountForDomain err: ' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('createOsAccountForDomain exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### queryOsAccountById    
查询指定系统帐号的信息。使用callback异步回调。  
 **调用形式：**     
    
- queryOsAccountById(localId: number, callback: AsyncCallback\<OsAccountInfo>): void    
起始版本： 7    
- queryOsAccountById(localId: number): Promise\<OsAccountInfo>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId | number | true | 要查询的系统帐号的ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果查询成功，err为null，data为查到的系统帐号的信息；否则为错误对象。 |  
| Promise<OsAccountInfo> | Promise对象，返回查到的系统帐号的信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
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
  accountManager.queryOsAccountById(localId, (err: BusinessError, accountInfo: account_osAccount.OsAccountInfo)=>{  
    console.log('queryOsAccountById err:' + JSON.stringify(err));  
    console.log('queryOsAccountById accountInfo:' + JSON.stringify(accountInfo));  
  });  
} catch (e) {  
  console.log('queryOsAccountById exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
try {  
  accountManager.queryOsAccountById(localId).then((accountInfo: account_osAccount.OsAccountInfo) => {  
    console.log('queryOsAccountById, accountInfo: ' + JSON.stringify(accountInfo));  
  }).catch((err: BusinessError) => {  
    console.log('queryOsAccountById err: ' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('queryOsAccountById exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### getOsAccountProfilePhoto  
 **调用形式：**     
    
- getOsAccountProfilePhoto(localId: number, callback: AsyncCallback\<string>): void    
起始版本： 7    
- getOsAccountProfilePhoto(localId: number): Promise\<string>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId | number | true | 系统帐号ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果获取成功，err为null，data为指定系统帐号的头像信息；否则为错误对象。 |  
| Promise<string> | Promise对象，返回指定系统帐号的头像信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
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
  accountManager.getOsAccountProfilePhoto(localId, (err: BusinessError, photo: string)=>{  
    console.log('getOsAccountProfilePhoto err:' + JSON.stringify(err));  
    console.log('get photo:' + photo + ' by localId: ' + localId);  
  });  
} catch (e) {  
  console.log('getOsAccountProfilePhoto exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
try {  
  accountManager.getOsAccountProfilePhoto(localId).then((photo: string) => {  
    console.log('getOsAccountProfilePhoto: ' + photo);  
  }).catch((err: BusinessError) => {  
    console.log('getOsAccountProfilePhoto err: ' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('getOsAccountProfilePhoto exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### setOsAccountProfilePhoto    
为指定系统帐号设置头像信息。使用callback异步回调。  
 **调用形式：**     
    
- setOsAccountProfilePhoto(localId: number, photo: string, callback: AsyncCallback\<void>): void    
起始版本： 7    
- setOsAccountProfilePhoto(localId: number, photo: string): Promise\<void>    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId | number | true | 系统帐号ID。 |  
| photo | string | true | 头像信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果设置成功，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象，无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid localId or photo. |  
| 12300003 | Account not found. |  
| 12300008 | Restricted Account. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
let photo: string = 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAA0AAAAPCAYAAAA/I0V3AAAAAXNSR0IArs4c6QAAAARnQU1BAA'+  
'Cxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAACwSURBVDhPvZLBDYMwDEV/ugsXRjAT0EHCOuFIBwkbdIRewi6unbiAyoGgSn1SFH85+Y'+  
'q/4ljARW62X+LHS8uIzjm4dXUYF+utzBikB52Jo5e5iEPKqpACk7R9NM2RvWm5tIkD2czLCUFNKLD6IjdMHFHDzws285MgGrT0xCtp3WOKHo'+  
'+7q0mP0DZW9pNmoEFUzrQjp5cCnaen2kSJXLFD8ghbXyZCMQf/8e8Ns1XVAG/XAgqKzVnJFAAAAABJRU5ErkJggg=='  
try {  
  accountManager.setOsAccountProfilePhoto(localId, photo, (err: BusinessError)=>{  
    console.log('setOsAccountProfilePhoto err:' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('setOsAccountProfilePhoto exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let localId: number = 100;  
let photo: string = 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAA0AAAAPCAYAAAA/I0V3AAAAAXNSR0IArs4c6QAAAARnQU1BAA'+  
'Cxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAACwSURBVDhPvZLBDYMwDEV/ugsXRjAT0EHCOuFIBwkbdIRewi6unbiAyoGgSn1SFH85+Y'+  
'q/4ljARW62X+LHS8uIzjm4dXUYF+utzBikB52Jo5e5iEPKqpACk7R9NM2RvWm5tIkD2czLCUFNKLD6IjdMHFHDzws285MgGrT0xCtp3WOKHo'+  
'+7q0mP0DZW9pNmoEFUzrQjp5cCnaen2kSJXLFD8ghbXyZCMQf/8e8Ns1XVAG/XAgqKzVnJFAAAAABJRU5ErkJggg=='  
try {  
  accountManager.setOsAccountProfilePhoto(localId, photo).then(() => {  
    console.log('setOsAccountProfilePhoto success');  
  }).catch((err: BusinessError) => {  
    console.log('setOsAccountProfilePhoto err: ' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('setOsAccountProfilePhoto exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### on('activate' | 'activating')    
订阅系统帐号的激活完成与激活中的事件。使用callback异步回调。  
 **调用形式：**     
    
- on(type: 'activate' | 'activating', name: string, callback: Callback\<number>): void    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 订阅类型，activate表示订阅的是帐号已激活完成的事件，activating表示订阅的是帐号正在激活的事件。 |  
| name | string | true | 订阅名称，可自定义，要求非空且长度不超过1024字节。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 订阅系统帐号激活完成与激活中的事件回调，表示激活完成后或正在激活中的系统帐号ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid type or name. |  
    
 **示例代码：**   
示例（callback）  
```ts    
let accountManager = account_osAccount.getAccountManager();  
function onCallback(receiveLocalId: number){  
  console.log('receive localId:' + receiveLocalId);  
}  
try {  
  accountManager.on('activating', 'osAccountOnOffNameA', onCallback);  
} catch (e) {  
  console.log('receive localId exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### off('activate' | 'activating')    
取消订阅系统帐号的激活完成与激活中的事件。使用callback异步回调。  
 **调用形式：**     
    
- off(type: 'activate' | 'activating', name: string, callback?: Callback\<number>): void    
起始版本： 7  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取消订阅类型，activate表示取消订阅帐号已激活完成的事件，activating取消订阅帐号正在激活的事件。 |  
| name | string | true | 订阅名称，可自定义，要求非空且长度不超过1024字节，需要与订阅接口传入的值保持一致。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 取消订阅系统帐号激活完成与激活中的事件回调，默认为空，表示取消该类型事件的所有回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid type or name. |  
    
 **示例代码：**   
```ts    
let accountManager = account_osAccount.getAccountManager();  
function offCallback(){  
  console.log('off enter')  
}  
try {  
  accountManager.off('activating', 'osAccountOnOffNameA', offCallback);  
} catch (e) {  
  console.log('off exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### getBundleIdForUid<sup>(9+)</sup>    
通过uid查询对应的bundleId，使用callback异步回调。  
 **调用形式：**     
    
- getBundleIdForUid(uid: number, callback: AsyncCallback\<number>): void    
起始版本： 9    
- getBundleIdForUid(uid: number): Promise\<number>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid | number | true | 进程uid。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果查询成功，err为null，data为与uid对应的bundleId；否则为错误对象。 |  
| Promise<number> | Promise对象，返回与uid对应的bundleId。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid uid. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let testUid: number = 1000000;  
try {  
  accountManager.getBundleIdForUid(testUid, (err: BusinessError, bundleId: number) => {  
    console.info('getBundleIdForUid errInfo:' + JSON.stringify(err));  
    console.info('getBundleIdForUid bundleId:' + JSON.stringify(bundleId));  
  });  
} catch (e) {  
  console.info('getBundleIdForUid exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
let testUid: number = 1000000;  
try {  
  accountManager.getBundleIdForUid(testUid).then((result: number) => {  
    console.info('getBundleIdForUid bundleId:' + JSON.stringify(result));  
  }).catch((err: BusinessError) => {  
    console.info('getBundleIdForUid errInfo:' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.info('getBundleIdForUid exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### getBundleIdForUidSync<sup>(10+)</sup>    
通过uid查询对应的bundleId。使用同步方式返回结果。  
 **调用形式：**     
- getBundleIdForUidSync(uid: number): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid | number | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 表示与进程uid对应的bundleId。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 12300002 | Invalid uid. |  
    
 **示例代码：**   
```ts    
let accountManager = account_osAccount.getAccountManager();  
let testUid: number = 1000000;  
try {  
  let bundleId : number = accountManager.getBundleIdForUidSync(testUid);  
  console.info('getBundleIdForUidSync bundleId:' + bundleId);  
} catch (e) {  
  console.info('getBundleIdForUidSync exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### isMainOsAccount<sup>(9+)</sup>    
查询当前进程是否处于主用户，使用callback异步回调。  
 **调用形式：**     
    
- isMainOsAccount(callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isMainOsAccount(): Promise\<boolean>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回true表示当前帐号为主帐号，返回false表示当前帐号非主帐号。 |  
| Promise<boolean> | Promise对象，返回true表示当前帐号为主帐号，返回false表示当前帐号非主帐号。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.isMainOsAccount((err: BusinessError,result: boolean)=>{  
    console.info('isMainOsAccount errInfo:' + JSON.stringify(err));  
    console.info('isMainOsAccount result:' + JSON.stringify(result));  
  });  
} catch (e) {  
  console.info('isMainOsAccount exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.isMainOsAccount().then((result: boolean) => {  
    console.info('isMainOsAccount result:' + JSON.stringify(result));  
  }).catch((err: BusinessError) => {  
    console.info('isMainOsAccount errInfo:' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.info('isMainOsAccount exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
### getOsAccountConstraintSourceTypes<sup>(9+)</sup>    
查询指定系统帐号的指定约束来源信息，使用callback异步回调。  
 **调用形式：**     
    
- getOsAccountConstraintSourceTypes(       localId: number,       constraint: string,       callback: AsyncCallback\<Array\<ConstraintSourceTypeInfo>>     ): void    
起始版本： 9    
- getOsAccountConstraintSourceTypes(localId: number, constraint: string): Promise\<Array\<ConstraintSourceTypeInfo>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId | number | true | 要查询的系统帐号ID |  
| constraint | string | true | 要查询的[约束](#系统帐号约束列表)名称 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果成功，err为null，data为指定系统帐号的指定[约束](#系统帐号约束列表)来源信息；否则为错误对象。 |  
| Promise<Array<ConstraintSourceTypeInfo>> | Promise对象，返回指定系统帐号的指定[约束](#系统帐号约束列表)来源信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid name or constraint. |  
| 12300003 | Account not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.getOsAccountConstraintSourceTypes(100, 'constraint.wifi',  
    (err: BusinessError,sourceTypeInfos: account_osAccount.ConstraintSourceTypeInfo[])=>{  
    console.info('getOsAccountConstraintSourceTypes errInfo:' + JSON.stringify(err));  
    console.info('getOsAccountConstraintSourceTypes sourceTypeInfos:' + JSON.stringify(sourceTypeInfos));  
  });  
} catch (e) {  
  console.info('getOsAccountConstraintSourceTypes exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let accountManager = account_osAccount.getAccountManager();  
try {  
  accountManager.getOsAccountConstraintSourceTypes(100, 'constraint.wifi').then(  
    (result: account_osAccount.ConstraintSourceTypeInfo[]) => {  
    console.info('getOsAccountConstraintSourceTypes sourceTypeInfos:' + JSON.stringify(result));  
  }).catch((err: BusinessError) => {  
    console.info('getOsAccountConstraintSourceTypes errInfo:' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.info('getOsAccountConstraintSourceTypes exception: ' + JSON.stringify(e));  
}  
    
```    
  
    
## DomainAccountInfo<sup>(8+)</sup>    
表示域帐号信息。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| accountId<sup>(10+)</sup> | string | false | false | 域帐号标识。<br>**系统接口：** 此接口为系统接口，默认为空。 |  
    
## UserAuth<sup>(8+)</sup>    
用户认证类。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### getVersion<sup>(8+)</sup>    
返回版本信息。  
 **调用形式：**     
- getVersion(): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回版本信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
    
 **示例代码：**   
```ts    
let userAuth = new account_osAccount.UserAuth();  
let version: number = userAuth.getVersion();  
console.log('getVersion version = ' + version);    
```    
  
    
### getAvailableStatus<sup>(8+)</sup>    
获取指定认证类型和认证可信等级的认证能力的可用状态。  
 **调用形式：**     
- getAvailableStatus(authType: AuthType, authTrustLevel: AuthTrustLevel): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| authType | AuthType | true | 认证类型。 |  
| authTrustLevel | AuthTrustLevel | true | 认证的可信等级。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回认证能力的可用状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid authType or authTrustLevel. |  
    
 **示例代码：**   
```ts    
let userAuth = new account_osAccount.UserAuth();  
let authType: account_osAccount.AuthType = account_osAccount.AuthType.PIN;  
let authTrustLevel: account_osAccount.AuthTrustLevel = account_osAccount.AuthTrustLevel.ATL1;  
try {  
  let status: number = userAuth.getAvailableStatus(authType, authTrustLevel);  
  console.log('getAvailableStatus status = ' + status);  
} catch (e) {  
  console.log('getAvailableStatus exception = ' + JSON.stringify(e));  
}  
    
```    
  
    
### getProperty<sup>(8+)</sup>    
基于指定的请求信息获取属性。使用callback异步回调。  
 **调用形式：**     
    
- getProperty(request: GetPropertyRequest, callback: AsyncCallback\<ExecutorProperty>): void    
起始版本： 8    
- getProperty(request: GetPropertyRequest): Promise\<ExecutorProperty>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request | GetPropertyRequest | true | 请求信息，包括认证类型和属性类型列表。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果获取成功，err为null，data为执行器属性信息；否则为错误对象。 |  
| Promise<ExecutorProperty> | Promise对象，返回执行者属性信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid request. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let userAuth = new account_osAccount.UserAuth();  
let keys: Array<account_osAccount.GetPropertyType>  = [  
  account_osAccount.GetPropertyType.AUTH_SUB_TYPE,  
  account_osAccount.GetPropertyType.REMAIN_TIMES,  
  account_osAccount.GetPropertyType.FREEZING_TIME  
];  
let request: account_osAccount.GetPropertyRequest = {  
  authType: account_osAccount.AuthType.PIN,  
  keys: keys  
};  
try {  
  userAuth.getProperty(request, (err: BusinessError, result: account_osAccount.ExecutorProperty) => {  
    console.log('getProperty err = ' + JSON.stringify(err));  
    console.log('getProperty result = ' + JSON.stringify(result));  
  });  
} catch (e) {  
  console.log('getProperty exception = ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let userAuth = new account_osAccount.UserAuth();  
let keys: Array<account_osAccount.GetPropertyType> = [  
  account_osAccount.GetPropertyType.AUTH_SUB_TYPE,   
  account_osAccount.GetPropertyType.REMAIN_TIMES,  
  account_osAccount.GetPropertyType.FREEZING_TIME  
];  
let request: account_osAccount.GetPropertyRequest = {  
  authType: account_osAccount.AuthType.PIN,  
  keys: keys  
};  
try {  
  userAuth.getProperty(request).then((result: account_osAccount.ExecutorProperty) => {  
    console.log('getProperty result = ' + JSON.stringify(result));  
  }).catch((err: BusinessError) => {  
    console.log('getProperty error = ' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('getProperty exception = ' + JSON.stringify(e));  
}  
    
```    
  
    
### setProperty<sup>(8+)</sup>    
设置可用于初始化算法的属性。使用callback异步回调。  
 **调用形式：**     
    
- setProperty(request: SetPropertyRequest, callback: AsyncCallback\<void>): void    
起始版本： 8    
- setProperty(request: SetPropertyRequest): Promise\<void>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request | SetPropertyRequest | true | 请求信息，包括认证类型和要设置的密钥值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果设置成功，err为null，否则为错误对象。 |  
| Promise<void> | Promise对象，无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid request. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let userAuth = new account_osAccount.UserAuth();  
let request: account_osAccount.SetPropertyRequest = {  
  authType: account_osAccount.AuthType.PIN,  
  key: account_osAccount.SetPropertyType.INIT_ALGORITHM,  
  setInfo: new Uint8Array([0])  
};  
try {  
  userAuth.setProperty(request, (err: BusinessError) => {  
    if (err) {  
      console.log('setProperty failed, error = ' + JSON.stringify(err));  
    } else {  
      console.log('setProperty successfully');  
    }  
  });  
} catch (e) {  
  console.log('setProperty exception = ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let userAuth = new account_osAccount.UserAuth();  
let request: account_osAccount.SetPropertyRequest = {  
  authType: account_osAccount.AuthType.PIN,  
  key: account_osAccount.SetPropertyType.INIT_ALGORITHM,  
  setInfo: new Uint8Array([0])  
};  
try {  
  userAuth.setProperty(request).then(() => {  
    console.log('setProperty successfully');  
  }).catch((err: BusinessError) => {  
    console.log('setProperty failed, error = ' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('setProperty exception = ' + JSON.stringify(e));  
}  
    
```    
  
    
### auth<sup>(8+)</sup>    
认证当前用户。使用callback异步回调。  
 **调用形式：**     
    
- auth(       challenge: Uint8Array,       authType: AuthType,       authTrustLevel: AuthTrustLevel,       callback: IUserAuthCallback     ): Uint8Array    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| challenge | Uint8Array | true | 指示挑战值，挑战值为一个随机数，用于提升安全性。 |  
| authType | AuthType | true | 指示认证类型。 |  
| authTrustLevel | AuthTrustLevel | true | 指示认证结果的信任级别。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调对象，返回认证结果。 |  
| Uint8Array | 返回取消的上下文ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid challenge, authType or authTrustLevel. |  
| 12300101 | Credential is incorrect. |  
| 12300102 | Credential not enrolled. |  
| 12300105 | Unsupported authTrustLevel. |  
| 12300106 | Unsupported authType. |  
| 12300109 | Authentication is canceled. |  
| 12300110 | Authentication is locked. |  
| 12300111 | Authentication timeout. |  
| 12300112 | Authentication service is busy. |  
    
### authUser<sup>(8+)</sup>    
认证指定用户。使用callback异步回调。  
 **调用形式：**     
    
- authUser(       userId: number,       challenge: Uint8Array,       authType: AuthType,       authTrustLevel: AuthTrustLevel,       callback: IUserAuthCallback     ): Uint8Array    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| userId | number | true | 指示用户身份。 |  
| challenge | Uint8Array | true | 指示挑战值，挑战值为一个随机数，用于提升安全性。 |  
| authType | AuthType | true | 指示认证类型。 |  
| authTrustLevel | AuthTrustLevel | true | 指示认证结果的信任级别。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调对象，返回认证结果。 |  
| Uint8Array | 返回取消的上下文ID。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid userId, challenge, authType or authTrustLevel. |  
| 12300101 | Credential is incorrect. |  
| 12300102 | Credential not enrolled. |  
| 12300105 | Unsupported authTrustLevel. |  
| 12300106 | Unsupported authType. |  
| 12300109 | Authentication is canceled. |  
| 12300110 | Authentication is locked. |  
| 12300111 | Authentication timeout. |  
| 12300112 | Authentication service is busy. |  
    
 **示例代码：**   
```ts    
let userAuth = new account_osAccount.UserAuth();  
let userID: number = 100;  
let challenge: Uint8Array = new Uint8Array([0]);  
let authType: account_osAccount.AuthType = account_osAccount.AuthType.PIN;  
let authTrustLevel: account_osAccount.AuthTrustLevel = account_osAccount.AuthTrustLevel.ATL1;  
try {  
  userAuth.authUser(userID, challenge, authType, authTrustLevel, {  
    onResult: (result,extraInfo) => {  
      console.log('authUser result = ' + result);  
      console.log('authUser extraInfo = ' + JSON.stringify(extraInfo));  
    }  
  });  
} catch (e) {  
  console.log('authUser exception = ' + JSON.stringify(e));  
}  
    
```    
  
    
### cancelAuth<sup>(8+)</sup>    
取消指定的认证操作。  
 **调用形式：**     
- cancelAuth(contextID: Uint8Array): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| contextID | Uint8Array | true | 指示身份验证上下文ID，此ID动态生成没有具体值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid contextId. |  
    
 **示例代码：**   
```ts    
let userAuth = new account_osAccount.UserAuth();  
let pinAuth: account_osAccount.PINAuth = new account_osAccount.PINAuth();  
let challenge = new Uint8Array([0]);  
let contextId: Uint8Array = userAuth.auth(challenge, account_osAccount.AuthType.PIN, account_osAccount.AuthTrustLevel.ATL1, {  
  onResult: (result: number, extraInfo: account_osAccount.AuthResult) => {  
    console.log('auth result = ' + result);  
    console.log('auth extraInfo = ' + JSON.stringify(extraInfo));  
  }  
});  
try {  
  userAuth.cancelAuth(contextId);  
} catch (e) {  
  console.log('cancelAuth exception = ' + JSON.stringify(e));  
}  
    
```    
  
    
## PINAuth<sup>(8+)</sup>    
PIN码认证基类。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### registerInputer<sup>(8+)</sup>    
注册PIN码输入器。  
 **调用形式：**     
- registerInputer(inputer: IInputer): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.ACCESS_PIN_AUTH    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| inputer | IInputer | true | PIN码输入器，用于获取PIN码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid inputer. |  
| 12300103 | Inputer already registered. |  
    
 **示例代码：**   
```ts    
let pinAuth: account_osAccount.PINAuth = new account_osAccount.PINAuth();  
let password = new Uint8Array([0, 0, 0, 0, 0]);  
try {  
  let result = pinAuth.registerInputer({  
      onGetData: (authSubType: account_osAccount.AuthSubType, callback: account_osAccount.IInputData) => {  
        callback.onSetData(authSubType, password);  
      }  
  });  
  console.log('registerInputer result = ' + result);  
} catch (e) {  
  console.log('registerInputer exception = ' + JSON.stringify(e));  
}  
    
```    
  
    
### unregisterInputer<sup>(8+)</sup>    
解注册PIN码输入器。  
 **调用形式：**     
- unregisterInputer(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.ACCESS_PIN_AUTH    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
let pinAuth: account_osAccount.PINAuth = new account_osAccount.PINAuth();  
pinAuth.unregisterInputer();    
```    
  
    
## InputerManager<sup>(9+)</sup>    
凭据输入管理器。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### registerInputer<sup>(9+)</sup>    
注册凭据输入器。  
 **调用形式：**     
- static registerInputer(authType: AuthType, inputer: IInputer): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL or ohos.permission.MANAGE_USER_IDM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| authType | AuthType | true | 认证类型。 |  
| inputer | IInputer | true | 凭据输入器，用于获取凭据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid authType or inputer. |  
| 12300103 | The credential inputer has been registered. |  
| 12300106 | Unsupported authType. |  
    
 **示例代码：**   
```ts    
let authType: account_osAccount.AuthType = account_osAccount.AuthType.DOMAIN;  
let password: Uint8Array = new Uint8Array([0, 0, 0, 0, 0]);  
try {  
  account_osAccount.InputerManager.registerInputer(authType, {  
      onGetData: (authSubType: account_osAccount.AuthSubType, callback: account_osAccount.IInputData) => {  
        callback.onSetData(authSubType, password);  
      }  
  });  
  console.log('registerInputer success.');  
} catch (e) {  
  console.log('registerInputer exception = ' + JSON.stringify(e));  
}  
    
```    
  
    
### unregisterInputer<sup>(9+)</sup>    
解注册凭据输入器。  
 **调用形式：**     
- static unregisterInputer(authType: AuthType): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL or ohos.permission.MANAGE_USER_IDM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| authType | AuthType | true | 认证类型。<br/> |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300002 | Invalid authType. |  
    
 **示例代码：**   
```ts    
let authType: account_osAccount.AuthType = account_osAccount.AuthType.DOMAIN;  
try {  
  account_osAccount.InputerManager.unregisterInputer(authType);  
  console.log('unregisterInputer success.');  
} catch(err) {  
  console.log('unregisterInputer err:' + JSON.stringify(err));  
}  
    
```    
  
    
## AuthStatusInfo<sup>(10+)</sup>    
表示认证状态信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| remainTimes<sup>(10+)</sup> | number | false | true | 剩余次数 |  
| freezingTime<sup>(10+)</sup> | number | false | true | 冻结时间 |  
    
## GetDomainAccessTokenOptions<sup>(10+)</sup>    
表示获取域访问令牌的选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| domainAccountInfo<sup>(10+)</sup> | DomainAccountInfo | false | true | [DomainAccountInfo](#domainaccountinfo8) | 是   | 域帐号的信息 |  
| domainAccountToken<sup>(10+)</sup> | Uint8Array | false | true | 域帐号的令牌 |  
| businessParams<sup>(10+)</sup> | object | false | true | 业务参数，由业务方根据请求协议自定义 |  
| callerUid<sup>(10+)</sup> | number | false | true | 调用方唯一标识符 |  
    
## GetDomainAccountInfoOptions<sup>(10+)</sup>    
表示查询域帐号信息的选项。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| accountName<sup>(10+)</sup> | string | false | true | 域帐号名。 |  
| domain<sup>(10+)</sup> | string | false | false | 域名。 |  
    
## GetDomainAccountInfoPluginOptions<sup>(10+)</sup>    
表示插件查询域帐号信息的选项。GetDomainAccountInfoPluginOptions类继承[GetDomainAccountInfoOptions](#getdomainaccountinfooptions10)  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| callerUid<sup>(10+)</sup> | number | false | true | 调用方唯一标识符 |  
    
## DomainPlugin<sup>(9+)</sup>    
域插件，提供域帐号认证功能。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### auth<sup>(9+)</sup>    
认证指定的域帐号。  
 **调用形式：**     
    
- auth(domainAccountInfo: DomainAccountInfo, credential: Uint8Array, callback: IUserAuthCallback): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| domainAccountInfo | DomainAccountInfo | true | 指示域帐号信息。 |  
| credential | Uint8Array | true | 指示域帐号的凭据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示认证结果回调。 |  
    
 **示例代码：**   
```ts    
import { AsyncCallback } from '@ohos.base';  
let plugin: account_osAccount.DomainPlugin = {  
  auth: (domainAccountInfo: account_osAccount.DomainAccountInfo, credential: Uint8Array,  
        callback: account_osAccount.IUserAuthCallback) => {  
    // mock authentication  
    // notify authentication result  
    let result: account_osAccount.AuthResult = {  
      token: new Uint8Array([0]),  
      remainTimes: 5,  
      freezingTime: 0  
    };  
    callback.onResult(0, result);  
  },  
  authWithPopup: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                  callback: account_osAccount.IUserAuthCallback) => {},  
  authWithToken: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                  callback: account_osAccount.IUserAuthCallback) => {},  
  getAccountInfo: (options: account_osAccount.GetDomainAccountInfoPluginOptions,  
                  callback: AsyncCallback<account_osAccount.DomainAccountInfo>) => {},  
  getAuthStatusInfo: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                    callback: AsyncCallback<account_osAccount.AuthStatusInfo>) => {},  
  bindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, localId: number,  
                callback: AsyncCallback<void>) => {},  
  unbindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},  
  isAccountTokenValid: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                        callback: AsyncCallback<boolean>) => {},  
  getAccessToken: (options: account_osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}  
}  
account_osAccount.DomainAccountManager.registerPlugin(plugin);  
let userAuth = new account_osAccount.UserAuth();  
let challenge: Uint8Array = new Uint8Array([0]);  
let authType: account_osAccount.AuthType = account_osAccount.AuthType.DOMAIN;  
let authTrustLevel: account_osAccount.AuthTrustLevel = account_osAccount.AuthTrustLevel.ATL1;  
try {  
  userAuth.auth(challenge, authType, authTrustLevel, {  
    onResult: (resultCode: number, authResult: account_osAccount.AuthResult) => {  
        console.log('auth resultCode = ' + resultCode);  
        console.log('auth authResult = ' + JSON.stringify(authResult));  
    }  
  });  
} catch (err) {  
  console.log('auth exception = ' + JSON.stringify(err));  
}  
    
```    
  
    
### authWithPopup<sup>(10+)</sup>    
弹窗认证指定的域帐号。  
 **调用形式：**     
    
- authWithPopup(domainAccountInfo: DomainAccountInfo, callback: IUserAuthCallback): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| domainAccountInfo | DomainAccountInfo | true | 指示域帐号信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示认证结果回调。 |  
    
 **示例代码：**   
```ts    
import { AsyncCallback } from '@ohos.base';  
let plugin: account_osAccount.DomainPlugin = {  
  auth: (domainAccountInfo: account_osAccount.DomainAccountInfo, credential: Uint8Array,  
        callback: account_osAccount.IUserAuthCallback) => {},  
  authWithPopup: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                  callback: account_osAccount.IUserAuthCallback) => {  
    // mock authentication  
    // notify authentication result  
    let result: account_osAccount.AuthResult = {  
      token: new Uint8Array([0]),  
      remainTimes: 5,  
      freezingTime: 0  
    };  
    callback.onResult(0, result);  
  },  
  authWithToken: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                  callback: account_osAccount.IUserAuthCallback) => {},  
  getAccountInfo: (options: account_osAccount.GetDomainAccountInfoPluginOptions,  
                  callback: AsyncCallback<account_osAccount.DomainAccountInfo>) => {},  
  getAuthStatusInfo: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                      callback: AsyncCallback<account_osAccount.AuthStatusInfo>) => {},  
  bindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, localId: number,  
                callback: AsyncCallback<void>) => {},  
  unbindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},  
  isAccountTokenValid: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                        callback: AsyncCallback<boolean>) => {},  
  getAccessToken: (options: account_osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}  
}  
account_osAccount.DomainAccountManager.registerPlugin(plugin)  
    
```    
  
    
### authWithToken<sup>(10+)</sup>    
使用授权令牌认证指定的域帐号。  
 **调用形式：**     
    
- authWithToken(domainAccountInfo: DomainAccountInfo, token: Uint8Array, callback: IUserAuthCallback): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| domainAccountInfo | DomainAccountInfo | true | 指示域帐号信息。<br/> |  
| token | Uint8Array | true | 指示PIN码或生物识别认证成功时生成的授权令牌。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示认证结果回调。 |  
    
 **示例代码：**   
```ts    
import { AsyncCallback } from '@ohos.base';  
let plugin: account_osAccount.DomainPlugin = {  
  auth: (domainAccountInfo: account_osAccount.DomainAccountInfo, credential: Uint8Array,  
        callback: account_osAccount.IUserAuthCallback) => {},  
  authWithPopup: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                  callback: account_osAccount.IUserAuthCallback) => {},  
  authWithToken: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                  callback: account_osAccount.IUserAuthCallback) => {  
    // mock authentication  
    // notify authentication result  
    let result: account_osAccount.AuthResult = {  
      token: new Uint8Array([0]),  
      remainTimes: 5,  
      freezingTime: 0  
    };  
    callback.onResult(0, result);  
  },  
  getAccountInfo: (options: account_osAccount.GetDomainAccountInfoPluginOptions,  
                  callback: AsyncCallback<account_osAccount.DomainAccountInfo>) => {},  
  getAuthStatusInfo: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                      callback: AsyncCallback<account_osAccount.AuthStatusInfo>) => {},  
  bindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, localId: number,  
                callback: AsyncCallback<void>) => {},  
  unbindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},  
  isAccountTokenValid: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                        callback: AsyncCallback<boolean>) => {},  
  getAccessToken: (options: account_osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}  
}  
account_osAccount.DomainAccountManager.registerPlugin(plugin)  
    
```    
  
    
### getAccountInfo<sup>(10+)</sup>    
查询指定域帐号的信息。  
 **调用形式：**     
    
- getAccountInfo(options: GetDomainAccountInfoPluginOptions, callback: AsyncCallback\<DomainAccountInfo>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | GetDomainAccountInfoPluginOptions | true | 指示域帐号信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示查询结果回调。 |  
    
 **示例代码：**   
```ts    
import { AsyncCallback, BusinessError } from '@ohos.base';  
let plugin: account_osAccount.DomainPlugin = {  
  auth: (domainAccountInfo: account_osAccount.DomainAccountInfo, credential: Uint8Array,  
        callback: account_osAccount.IUserAuthCallback) => {},  
  authWithPopup: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                  callback: account_osAccount.IUserAuthCallback) => {},  
  authWithToken: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                  callback: account_osAccount.IUserAuthCallback) => {},  
  getAccountInfo: (options: account_osAccount.GetDomainAccountInfoPluginOptions,  
                  callback: AsyncCallback<account_osAccount.DomainAccountInfo>) => {  
    // mock getting account information  
    // notify result  
    let code: BusinessError = {  
      code: 0,  
      name: "",  
      message: ""  
    };  
    let accountInfo: account_osAccount.DomainAccountInfo = {  
      domain: options.domain,  
      accountName: options.accountName,  
      accountId: 'xxxx'  
    };  
    callback(code, accountInfo);  
  },  
  getAuthStatusInfo: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                      callback: AsyncCallback<account_osAccount.AuthStatusInfo>) => {},  
  bindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, localId: number,  
                callback: AsyncCallback<void>) => {},  
  unbindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},  
  isAccountTokenValid: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                        callback: AsyncCallback<boolean>) => {},  
  getAccessToken: (options: account_osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}  
}  
account_osAccount.DomainAccountManager.registerPlugin(plugin)  
    
```    
  
    
### getAuthStatusInfo<sup>(10+)</sup>    
查询指定域帐号的认证状态信息。  
 **调用形式：**     
    
- getAuthStatusInfo(domainAccountInfo: DomainAccountInfo, callback: AsyncCallback\<AuthStatusInfo>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| domainAccountInfo | DomainAccountInfo | true | 指示域帐号信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示查询结果回调。 |  
    
 **示例代码：**   
```ts    
import { AsyncCallback, BusinessError } from '@ohos.base';  
let plugin: account_osAccount.DomainPlugin = {  
  auth: (domainAccountInfo: account_osAccount.DomainAccountInfo, credential: Uint8Array,  
        callback: account_osAccount.IUserAuthCallback) => {},  
  authWithPopup: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                  callback: account_osAccount.IUserAuthCallback) => {},  
  authWithToken: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                  callback: account_osAccount.IUserAuthCallback) => {},  
  getAccountInfo: (options: account_osAccount.GetDomainAccountInfoPluginOptions,  
                  callback: AsyncCallback<account_osAccount.DomainAccountInfo>) => {},  
  getAuthStatusInfo: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                      callback: AsyncCallback<account_osAccount.AuthStatusInfo>) => {  
    let code: BusinessError = {  
      code: 0,  
      name: "",  
      message: ""  
    };  
    let statusInfo: account_osAccount.AuthStatusInfo = {  
      remainTimes: 5,  
      freezingTime: 0  
    };  
    callback(code, statusInfo);  
  },  
  bindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, localId: number,  
                callback: AsyncCallback<void>) => {},  
  unbindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},  
  isAccountTokenValid: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                        callback: AsyncCallback<boolean>) => {},  
  getAccessToken: (options: account_osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}  
}  
account_osAccount.DomainAccountManager.registerPlugin(plugin)  
    
```    
  
    
### bindAccount<sup>(10+)</sup>    
绑定指定的域帐号。  
 **调用形式：**     
    
- bindAccount(domainAccountInfo: DomainAccountInfo, localId: number, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| domainAccountInfo | DomainAccountInfo | true | 指示域帐号信息。<br/> |  
| localId | number | true | 系统帐号ID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
    
 **示例代码：**   
```ts    
import { AsyncCallback, BusinessError } from '@ohos.base';  
let plugin: account_osAccount.DomainPlugin = {  
  auth: (domainAccountInfo: account_osAccount.DomainAccountInfo, credential: Uint8Array,  
        callback: account_osAccount.IUserAuthCallback) => {},  
  authWithPopup: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                  callback: account_osAccount.IUserAuthCallback) => {},  
  authWithToken: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                  callback: account_osAccount.IUserAuthCallback) => {},  
  getAccountInfo: (options: account_osAccount.GetDomainAccountInfoPluginOptions,  
                  callback: AsyncCallback<account_osAccount.DomainAccountInfo>) => {},  
  getAuthStatusInfo: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                      callback: AsyncCallback<account_osAccount.AuthStatusInfo>) => {},  
  bindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, localId: number,  
                callback: AsyncCallback<void>) => {  
    // mock unbinding operation  
    // notify binding result  
    let code: BusinessError = {  
      code: 0,  
      name: "",  
      message: ""  
    };  
    callback(code);  
  },  
  unbindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},  
  isAccountTokenValid: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                        callback: AsyncCallback<boolean>) => {},  
  getAccessToken: (options: account_osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}  
}  
account_osAccount.DomainAccountManager.registerPlugin(plugin)  
    
```    
  
    
### unbindAccount<sup>(10+)</sup>    
解绑指定的域帐号。  
 **调用形式：**     
    
- unbindAccount(domainAccountInfo: DomainAccountInfo, callback: AsyncCallback\<void>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| domainAccountInfo | DomainAccountInfo | true | 指示域帐号信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示绑定结果回调。 |  
    
 **示例代码：**   
```ts    
import { AsyncCallback, BusinessError } from '@ohos.base';  
let plugin: account_osAccount.DomainPlugin = {  
  auth: (domainAccountInfo: account_osAccount.DomainAccountInfo, credential: Uint8Array,  
        callback: account_osAccount.IUserAuthCallback) => {},  
  authWithPopup: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                  callback: account_osAccount.IUserAuthCallback) => {},  
  authWithToken: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                  callback: account_osAccount.IUserAuthCallback) => {},  
  getAccountInfo: (options: account_osAccount.GetDomainAccountInfoPluginOptions,  
                  callback: AsyncCallback<account_osAccount.DomainAccountInfo>) => {},  
  getAuthStatusInfo: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                      callback: AsyncCallback<account_osAccount.AuthStatusInfo>) => {},  
  bindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, localId: number,  
                callback: AsyncCallback<void>) => {},  
  unbindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {  
    // mock unbinding operation  
    // notify unbinding result  
    let code: BusinessError = {  
      code: 0,  
      name: "",  
      message: ""  
    };  
    callback(code);  
  },  
  isAccountTokenValid: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                        callback: AsyncCallback<boolean>) => {},  
  getAccessToken: (options: account_osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}  
}  
account_osAccount.DomainAccountManager.registerPlugin(plugin)  
    
```    
  
    
### isAccountTokenValid<sup>(10+)</sup>    
检查指定的域帐号令牌是否有效。  
 **调用形式：**     
    
- isAccountTokenValid(       domainAccountInfo: DomainAccountInfo,       token: Uint8Array,       callback: AsyncCallback\<boolean>     ): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| domainAccountInfo | DomainAccountInfo | true | 指示域帐号信息。 |  
| token | Uint8Array | true | 指示域帐号令牌。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示检查结果回调。 |  
    
 **示例代码：**   
```ts    
import { AsyncCallback, BusinessError } from '@ohos.base';  
let plugin: account_osAccount.DomainPlugin = {  
  auth: (domainAccountInfo: account_osAccount.DomainAccountInfo, credential: Uint8Array,  
        callback: account_osAccount.IUserAuthCallback) => {},  
  authWithPopup: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                  callback: account_osAccount.IUserAuthCallback) => {},  
  authWithToken: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                  callback: account_osAccount.IUserAuthCallback) => {},  
  getAccountInfo: (options: account_osAccount.GetDomainAccountInfoPluginOptions,  
                  callback: AsyncCallback<account_osAccount.DomainAccountInfo>) => {},  
  getAuthStatusInfo: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                      callback: AsyncCallback<account_osAccount.AuthStatusInfo>) => {},  
  bindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, localId: number,  
                callback: AsyncCallback<void>) => {},  
  unbindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},  
  isAccountTokenValid: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                        callback: AsyncCallback<boolean>) => {  
    // mock checking operation  
    // notify checking result  
    let code: BusinessError = {  
      code: 0,  
      name: "",  
      message: ""  
    };  
    callback(code, true);  
  },  
  getAccessToken: (options: account_osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}  
}  
account_osAccount.DomainAccountManager.registerPlugin(plugin)  
    
```    
  
    
### getAccessToken<sup>(10+)</sup>    
根据指定的选项获取域访问令牌。  
 **调用形式：**     
    
- getAccessToken(options: GetDomainAccessTokenOptions, callback: AsyncCallback\<Uint8Array>): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | GetDomainAccessTokenOptions | true | 指示获取域访问令牌的选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示结果回调。 |  
    
 **示例代码：**   
```ts    
import { AsyncCallback, BusinessError } from '@ohos.base';  
let plugin: account_osAccount.DomainPlugin = {  
  auth: (domainAccountInfo: account_osAccount.DomainAccountInfo, credential: Uint8Array,  
        callback: account_osAccount.IUserAuthCallback) => {},  
  authWithPopup: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                  callback: account_osAccount.IUserAuthCallback) => {},  
  authWithToken: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                  callback: account_osAccount.IUserAuthCallback) => {},  
  getAccountInfo: (options: account_osAccount.GetDomainAccountInfoPluginOptions,  
                  callback: AsyncCallback<account_osAccount.DomainAccountInfo>) => {},  
  getAuthStatusInfo: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                      callback: AsyncCallback<account_osAccount.AuthStatusInfo>) => {},  
  bindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, localId: number,  
                callback: AsyncCallback<void>) => {},  
  unbindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},  
  isAccountTokenValid: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                        callback: AsyncCallback<boolean>) => {},  
  getAccessToken: (options: account_osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {  
    // mock getting operation  
    // notify result  
    let code: BusinessError = {  
      code: 0,  
      name: "",  
      message: ""  
    };  
    let token: Uint8Array = new Uint8Array([0]);  
    callback(code, token);  
  }  
}  
account_osAccount.DomainAccountManager.registerPlugin(plugin)  
    
```    
  
    
## DomainAccountManager<sup>(9+)</sup>    
域帐号管理器类。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### registerPlugin<sup>(9+)</sup>    
注册域插件。  
 **调用形式：**     
- static registerPlugin(plugin: DomainPlugin): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| plugin | DomainPlugin | true | 指示域插件。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300201 | The domain plugin has been registered. |  
    
 **示例代码：**   
```ts    
import { AsyncCallback } from '@ohos.base';  
let plugin: account_osAccount.DomainPlugin = {  
  auth: (domainAccountInfo: account_osAccount.DomainAccountInfo, credential: Uint8Array,  
       callback: account_osAccount.IUserAuthCallback) => {},  
  authWithPopup: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                callback: account_osAccount.IUserAuthCallback) => {},  
  authWithToken: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                callback: account_osAccount.IUserAuthCallback) => {},  
  getAccountInfo: (options: account_osAccount.GetDomainAccountInfoPluginOptions,  
                 callback: AsyncCallback<account_osAccount.DomainAccountInfo>) => {},  
  getAuthStatusInfo: (domainAccountInfo: account_osAccount.DomainAccountInfo,  
                      callback: AsyncCallback<account_osAccount.AuthStatusInfo>) => {},  
  bindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, localId: number,  
                callback: AsyncCallback<void>) => {},  
  unbindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},  
  isAccountTokenValid: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,  
                      callback: AsyncCallback<boolean>) => {},  
  getAccessToken: (options: account_osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}  
}  
try {  
  account_osAccount.DomainAccountManager.registerPlugin(plugin);  
  console.log('registerPlugin success.');  
} catch(err) {  
  console.log('registerPlugin err:' + JSON.stringify(err));  
}  
    
```    
  
    
### unregisterPlugin<sup>(9+)</sup>    
注销域插件。  
 **调用形式：**     
- static unregisterPlugin(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
try {  
  account_osAccount.DomainAccountManager.unregisterPlugin();  
  console.log('unregisterPlugin success.');  
} catch(err) {  
  console.log('unregisterPlugin err:' + JSON.stringify(err));  
}  
    
```    
  
    
### auth<sup>(10+)</sup>    
认证指定的域帐号。  
 **调用形式：**     
    
- static auth(domainAccountInfo: DomainAccountInfo, credential: Uint8Array, callback: IUserAuthCallback): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| domainAccountInfo | DomainAccountInfo | true | 指示域帐号信息。 |  
| credential | Uint8Array | true | 指示域帐号的凭据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示认证结果回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid domainAccountInfo or credential. |  
| 12300003 | Domain account does not exist. |  
| 12300013 | Network exception. |  
| 12300101 | Authentication failed. |  
| 12300109 | Authentication is canceled. |  
| 12300110 | Authentication is locked. |  
| 12300111 | Authentication timeout. |  
| 12300112 | Authentication service is busy. |  
| 12300113 | Authentication service does not exist. |  
| 12300114 | Authentication service exception. |  
    
 **示例代码：**   
```ts    
let domainAccountInfo: account_osAccount.DomainAccountInfo = {  
  domain: 'CHINA',  
  accountName: 'zhangsan'  
}  
let credential = new Uint8Array([0])  
try {  
  account_osAccount.DomainAccountManager.auth(domainAccountInfo, credential, {  
    onResult: (resultCode: number, authResult: account_osAccount.AuthResult) => {  
      console.log('auth resultCode = ' + resultCode);  
      console.log('auth authResult = ' + JSON.stringify(authResult));  
    }  
  });  
} catch (err) {  
  console.log('auth exception = ' + JSON.stringify(err));  
}  
    
```    
  
    
### authWithPopup<sup>(10+)</sup>    
弹框认证指定的域帐号。  
 **调用形式：**     
    
- static authWithPopup(callback: IUserAuthCallback): void    
起始版本： 10    
- static authWithPopup(localId: number, callback: IUserAuthCallback): void    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.ACCESS_USER_AUTH_INTERNAL    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localId | number | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示认证结果回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 12300001 | System service exception. |  
| 12300003 | No domain account is bound. |  
| 12300013 | Network exception. |  
| 12300101 | Authentication failed. |  
| 12300109 | Authentication is canceled. |  
| 12300110 | Authentication is locked. |  
| 12300111 | Authentication timeout. |  
| 12300112 | Authentication service is busy. |  
| 12300113 | Authentication service does not exist. |  
| 12300114 | Authentication service exception. |  
| 12300002 |  |  
    
 **示例代码：**   
```ts    
try {  
  account_osAccount.DomainAccountManager.authWithPopup({  
    onResult: (resultCode: number, authResult: account_osAccount.AuthResult) => {  
      console.log('auth resultCode = ' + resultCode);  
      console.log('auth authResult = ' + JSON.stringify(authResult));  
    }  
  })  
} catch (err) {  
  console.log('auth exception = ' + JSON.stringify(err));  
}  
    
```    
  
    
### hasAccount<sup>(10+)</sup>    
检查是否存在指定的域帐号。  
 **调用形式：**     
    
- static hasAccount(domainAccountInfo: DomainAccountInfo, callback: AsyncCallback\<boolean>): void    
起始版本： 10    
- static hasAccount(domainAccountInfo: DomainAccountInfo): Promise\<boolean>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| domainAccountInfo | DomainAccountInfo | true | 指示域帐号信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示检查结果回调。 |  
| Promise<boolean> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid domainAccountInfo. |  
| 12300013 | Network exception. |  
| 12300111 | Operation timeout. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let domainAccountInfo: account_osAccount.DomainAccountInfo = {  
  domain: 'CHINA',  
  accountName: 'zhangsan'  
}  
try {  
  account_osAccount.DomainAccountManager.hasAccount(domainAccountInfo, (err: BusinessError, result: boolean) => {  
    if (err) {  
      console.log('call hasAccount failed, error: ' + JSON.stringify(err));  
    } else {  
      console.log('hasAccount result: ' + result);  
    }  
  });  
} catch (err) {  
  console.log('hasAccount exception = ' + JSON.stringify(err));  
}  
    
```    
  
    
### updateAccountToken<sup>(10+)</sup>    
更新指定域帐号的令牌，空令牌表示目标域帐号的令牌失效。使用callback异步回调。  
 **调用形式：**     
    
- static updateAccountToken(       domainAccountInfo: DomainAccountInfo,       token: Uint8Array,       callback: AsyncCallback\<void>     ): void    
起始版本： 10    
- static updateAccountToken(domainAccountInfo: DomainAccountInfo, token: Uint8Array): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| domainAccountInfo | DomainAccountInfo | true | 指示域帐号信息。 |  
| token | Uint8Array | true | 指示域帐号的令牌。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果更新成功，err为null，否则为错误对象。 |  
| Promise<void> |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid token. |  
| 12300003 | Account not found. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let domainAccountInfo: account_osAccount.DomainAccountInfo = {  
  domain: 'CHINA',  
  accountName: 'zhangsan',  
  accountId: '123456'  
}  
let token = new Uint8Array([0])  
try {  
  account_osAccount.DomainAccountManager.updateAccountToken(domainAccountInfo, token, (err: BusinessError) => {  
    if (err != null) {  
      console.log('updateAccountToken failed, error: ' + JSON.stringify(err));  
    } else {  
      console.log('updateAccountToken successfully');  
    }  
  })  
} catch (err) {  
  console.log('updateAccountToken exception = ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let domainAccountInfo: account_osAccount.DomainAccountInfo = {  
  domain: 'CHINA',  
  accountName: 'zhangsan',  
  accountId: '123456'  
}  
let token = new Uint8Array([0])  
try {  
  account_osAccount.DomainAccountManager.updateAccountToken(domainAccountInfo, token).then(() => {  
    console.log('updateAccountToken successfully');  
  }).catch((err: BusinessError) => {  
      console.log('updateAccountToken failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('updateAccountToken exception = ' + JSON.stringify(err));  
}  
    
```    
  
    
### getAccountInfo<sup>(10+)</sup>    
查询指定的域帐号信息，callback方式。  
 **调用形式：**     
    
- static getAccountInfo(options: GetDomainAccountInfoOptions, callback: AsyncCallback\<DomainAccountInfo>): void    
起始版本： 10    
- static getAccountInfo(options: GetDomainAccountInfoOptions): Promise\<DomainAccountInfo>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.GET_DOMAIN_ACCOUNTS    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | GetDomainAccountInfoOptions | true | 指示域帐号信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指示查询结果回调。 |  
| Promise<DomainAccountInfo> | Promise对象，返回指定的域帐号信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 801 |  |  
| 12300001 | System service exception. |  
| 12300003 | Account not found. |  
| 12300013 | Network exception. |  
| 12300111 | Operation timeout. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let domainAccountInfo: account_osAccount.GetDomainAccountInfoOptions = {  
  domain: 'CHINA',  
  accountName: 'zhangsan'  
}  
try {  
  account_osAccount.DomainAccountManager.getAccountInfo(domainAccountInfo,  
    (err: BusinessError, result: account_osAccount.DomainAccountInfo) => {  
    if (err) {  
      console.log('call getAccountInfo failed, error: ' + JSON.stringify(err));  
    } else {  
      console.log('getAccountInfo result: ' + result);  
    }  
  });  
} catch (err) {  
  console.log('getAccountInfo exception = ' + JSON.stringify(err));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```null    
import { BusinessError } from '@ohos.base';  
let domainAccountInfo: account_osAccount.GetDomainAccountInfoOptions = {  
  domain: 'CHINA',  
  accountName: 'zhangsan'  
}  
try {  
  account_osAccount.DomainAccountManager.getAccountInfo(domainAccountInfo)  
    .then((result: account_osAccount.DomainAccountInfo) => {  
    console.log('getAccountInfo result: ' + result);  
  }).catch((err: BusinessError) => {  
    console.log('call getAccountInfo failed, error: ' + JSON.stringify(err));  
  });  
} catch (err) {  
  console.log('getAccountInfo exception = ' + JSON.stringify(err));  
}  
    
```    
  
    
## UserIdentityManager<sup>(8+)</sup>    
获取用户身份管理类。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### openSession<sup>(8+)</sup>    
打开会话，获取挑战值。使用callback异步回调。  
 **调用形式：**     
    
- openSession(callback: AsyncCallback\<Uint8Array>): void    
起始版本： 8    
- openSession(): Promise\<Uint8Array>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_USER_IDM    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。如果打开会话成功，err为null，data为挑战值；否则为错误对象。 |  
| Promise<Uint8Array> | Promise对象，返回挑战值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let userIDM = new account_osAccount.UserIdentityManager();  
try {  
  userIDM.openSession((err: BusinessError, challenge: Uint8Array) => {  
      console.log('openSession error = ' + JSON.stringify(err));  
      console.log('openSession challenge = ' + JSON.stringify(challenge));  
  });  
} catch (e) {  
  console.log('openSession exception = ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let userIDM = new account_osAccount.UserIdentityManager();  
try {  
  userIDM.openSession().then((challenge: Uint8Array) => {  
      console.info('openSession challenge = ' + JSON.stringify(challenge));  
  }).catch((err: BusinessError) => {  
      console.info('openSession error = ' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('openSession exception = ' + JSON.stringify(e));  
}  
    
```    
  
    
### addCredential<sup>(8+)</sup>    
添加凭据，添加用户凭据信息，传入凭据添加方法和凭据信息（凭据类型，子类，如果添加用户的非密码凭据，则传入密码身份验证令牌），并获取结果/获取信息。  
 **调用形式：**     
    
- addCredential(credentialInfo: CredentialInfo, callback: IIdmCallback): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_USER_IDM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| credentialInfo | CredentialInfo | true | 指示凭据信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调对象，返回添加凭据的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid credentialInfo, i.e. authType or authSubType. |  
| 12300101 | Token is invalid. |  
| 12300106 | Unsupported authType. |  
| 12300109 | Operation is canceled. |  
| 12300111 | Operation timeout. |  
| 12300115 | The number of credentials reaches the upper limit. |  
    
 **示例代码：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let password: Uint8Array = new Uint8Array([0, 0, 0, 0, 0, 0]);  
let pinAuth: account_osAccount.PINAuth = new account_osAccount.PINAuth();  
pinAuth.registerInputer({  
  onGetData: (authSubType: account_osAccount.AuthSubType, callback: account_osAccount.IInputData) => {  
    callback.onSetData(authSubType, password);  
  }  
});  
let credentialInfo: account_osAccount.CredentialInfo = {  
  credType: account_osAccount.AuthType.PIN,  
  credSubType: account_osAccount.AuthSubType.PIN_SIX,  
  token: new Uint8Array([]),  
};  
let userIDM = new account_osAccount.UserIdentityManager();  
userIDM.openSession((err: BusinessError, challenge: Uint8Array) => {  
  try {  
  userIDM.addCredential(credentialInfo, {  
    onResult: (result: number, extraInfo: account_osAccount.RequestResult) => {  
      console.log('addCredential result = ' + result);  
      console.log('addCredential extraInfo = ' + extraInfo);  
    }  
  });  
  } catch (e) {  
    console.log('addCredential exception = ' + JSON.stringify(e));  
  }  
});  
    
```    
  
    
### updateCredential<sup>(8+)</sup>    
更新凭据。使用callback异步回调。  
 **调用形式：**     
    
- updateCredential(credentialInfo: CredentialInfo, callback: IIdmCallback): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_USER_IDM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| credentialInfo | CredentialInfo | true | 指示凭据信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调对象，返回更新凭据的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid credentialInfo, i.e. authType or authSubType or token. |  
| 12300101 | Token is invalid. |  
| 12300102 | Credential not enrolled. |  
| 12300106 | Unsupported authType. |  
| 12300109 | Operation is canceled. |  
| 12300111 | Operation timeout. |  
    
 **示例代码：**   
```ts    
import { BusinessError } from '@ohos.base';  
let userIDM = new account_osAccount.UserIdentityManager();  
let userAuth: account_osAccount.UserAuth = new account_osAccount.UserAuth();  
let pinAuth: account_osAccount.PINAuth = new account_osAccount.PINAuth();  
let password: Uint8Array = new Uint8Array([0, 0, 0, 0, 0, 0]);  
let credentialInfo: account_osAccount.CredentialInfo = {  
  credType: account_osAccount.AuthType.PIN,  
  credSubType: account_osAccount.AuthSubType.PIN_SIX,  
  token: new Uint8Array([]),  
};  
pinAuth.registerInputer({  
  onGetData: (authSubType: account_osAccount.AuthSubType, callback: account_osAccount.IInputData) => {  
    callback.onSetData(authSubType, password);  
  }  
});  
userIDM.openSession((err: BusinessError, challenge: Uint8Array) => {  
  userAuth.auth(challenge, credentialInfo.credType, account_osAccount.AuthTrustLevel.ATL1, {  
    onResult: (result: number, extraInfo: account_osAccount.AuthResult) => {  
      if (result != account_osAccount.ResultCode.SUCCESS) {  
        return;  
      }  
      if (extraInfo.token != null) {  
        credentialInfo.token = extraInfo.token;  
      }  
      try {  
        userIDM.updateCredential(credentialInfo, {  
          onResult: (result: number, extraInfo: account_osAccount.RequestResult) => {  
              console.log('updateCredential result = ' + result);  
              console.log('updateCredential extraInfo = ' + extraInfo);  
          }  
        });  
      } catch (e) {  
        console.log('updateCredential exception = ' + JSON.stringify(e));  
      }  
    }  
  });  
});  
    
```    
  
    
### closeSession<sup>(8+)</sup>    
关闭会话，结束IDM操作。  
 **调用形式：**     
- closeSession(): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_USER_IDM    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
    
 **示例代码：**   
```ts    
let userIDM = new account_osAccount.UserIdentityManager();  
userIDM.closeSession();    
```    
  
    
### cancel<sup>(8+)</sup>    
根据挑战值取消条目。  
 **调用形式：**     
- cancel(challenge: Uint8Array): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_USER_IDM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| challenge | Uint8Array | true | 挑战值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid challenge. |  
    
 **示例代码：**   
```ts    
let userIDM = new account_osAccount.UserIdentityManager();  
let challenge: Uint8Array = new Uint8Array([0]);  
try {  
  userIDM.cancel(challenge);  
} catch(err) {  
  console.log('cancel err:' + JSON.stringify(err));  
}  
    
```    
  
    
### delUser<sup>(8+)</sup>    
删除具有身份验证令牌的用户，使用callback方式异步返回结果。  
 **调用形式：**     
    
- delUser(token: Uint8Array, callback: IIdmCallback): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_USER_IDM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| token | Uint8Array | true | 身份验证令牌。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调对象，返回删除用户的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300101 | Token is invalid. |  
    
 **示例代码：**   
```ts    
let userIDM = new account_osAccount.UserIdentityManager();  
let token: Uint8Array = new Uint8Array([0]);  
try {  
  userIDM.delUser(token, {  
    onResult: (result: number, extraInfo: account_osAccount.RequestResult) => {  
      console.log('delUser result = ' + result);  
      console.log('delUser extraInfo = ' + JSON.stringify(extraInfo));  
    }  
  });  
} catch (e) {  
  console.log('delUser exception = ' + JSON.stringify(e));  
}  
    
```    
  
    
### delCred<sup>(8+)</sup>    
删除用户凭据信息。  
 **调用形式：**     
    
- delCred(credentialId: Uint8Array, token: Uint8Array, callback: IIdmCallback): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.MANAGE_USER_IDM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| credentialId | Uint8Array | true | 凭证索引。 |  
| token | Uint8Array | true | 身份验证令牌。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调对象，返回删除凭据的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300002 | Invalid credentialId. |  
| 12300101 | Token is invalid. |  
| 12300102 | Credential not enrolled. |  
    
 **示例代码：**   
```ts    
let userIDM = new account_osAccount.UserIdentityManager();  
let credentialId: Uint8Array = new Uint8Array([0, 0, 0, 0, 0, 0, 0, 0]);  
let token: Uint8Array = new Uint8Array([0]);  
try {  
  userIDM.delCred(credentialId, token, {  
    onResult: (result: number, extraInfo: account_osAccount.RequestResult) => {  
        console.log('delCred result = ' + result);  
        console.log('delCred extraInfo = ' + JSON.stringify(extraInfo));  
    }  
  });  
} catch (e) {  
  console.log('delCred exception = ' + JSON.stringify(e));  
}  
    
```    
  
    
### getAuthInfo<sup>(8+)</sup>    
获取认证信息。使用callback异步回调。  
 **调用形式：**     
    
- getAuthInfo(callback: AsyncCallback\<Array\<EnrolledCredInfo>>): void    
起始版本： 8    
- getAuthInfo(authType: AuthType, callback: AsyncCallback\<Array\<EnrolledCredInfo>>): void    
起始版本： 8    
- getAuthInfo(authType?: AuthType): Promise\<Array\<EnrolledCredInfo>>    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount  
 **需要权限：** ohos.permission.USE_USER_IDM    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| authType | AuthType | true | 认证类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，如果获取成功，err为null，data为当前用户指定类型的所有已注册凭据信息；否则为错误对象。 |  
| Promise<Array<EnrolledCredInfo>> | Promise对象，返回当前用户指定类型的所有已注册凭据信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 12300001 | System service exception. |  
| 12300102 | Invalid authType. |  
| 12300002 | Credential not enrolled. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
let userIDM = new account_osAccount.UserIdentityManager();  
try {  
  userIDM.getAuthInfo((err: BusinessError, result: account_osAccount.EnrolledCredInfo[]) => {  
    console.log('getAuthInfo err = ' + JSON.stringify(err));  
    console.log('getAuthInfo result = ' + JSON.stringify(result));  
  });  
} catch (e) {  
  console.log('getAuthInfo exception = ' + JSON.stringify(e));  
}  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
let userIDM = new account_osAccount.UserIdentityManager();  
try {  
  userIDM.getAuthInfo(account_osAccount.AuthType.PIN).then((result: account_osAccount.EnrolledCredInfo[]) => {  
    console.log('getAuthInfo result = ' + JSON.stringify(result))  
  }).catch((err: BusinessError) => {  
    console.log('getAuthInfo error = ' + JSON.stringify(err));  
  });  
} catch (e) {  
  console.log('getAuthInfo exception = ' + JSON.stringify(e));  
}  
    
```    
  
    
## IInputData<sup>(8+)</sup>    
密码数据回调。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| onSetData<sup>(8+)</sup> | (authSubType: AuthSubType, data: Uint8Array) => void | false | true | 通知设置数据。 |  
    
## IInputer<sup>(8+)</sup>    
凭据输入器回调。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| onGetData<sup>(8+)</sup> | (authSubType: AuthSubType, callback: IInputData) => void | false | true | 通知获取数据。 |  
    
## IUserAuthCallback<sup>(8+)</sup>    
表示用户认证回调类。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| onResult<sup>(8+)</sup> | (result: number, extraInfo: AuthResult) => void | false | true | 身份认证结果回调函数，返回结果码和认证结果信息。 |  
| onAcquireInfo<sup>(8+)</sup> | (module: number, acquire: number, extraInfo: any) => void | false | false | 身份认证信息获取回调函数。 |  
    
## IIdmCallback<sup>(8+)</sup>    
表示身份管理回调类。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| onResult<sup>(8+)</sup> | (result: number, extraInfo: RequestResult) => void | false | true | 身份管理操作结果回调函数，返回结果码和请求结果信息。 |  
| onAcquireInfo<sup>(8+)</sup> | (module: number, acquire: number, extraInfo: any) => void | false | false | 身份管理信息获取回调函数。 |  
    
## GetPropertyRequest<sup>(8+)</sup>    
提供获取属性请求的信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| authType<sup>(8+)</sup> | AuthType | false | true | 身份验证凭据类型。 |  
| keys<sup>(8+)</sup> | Array<GetPropertyType> | false | true | 指示要获取的属性类型数组。 |  
    
## SetPropertyRequest<sup>(8+)</sup>    
提供设置属性请求的信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| authType<sup>(8+)</sup> | AuthType | false | true | 身份验证凭据类型。 |  
| key<sup>(8+)</sup> | SetPropertyType | false | true | 指示要设置的属性类型。 |  
| setInfo<sup>(8+)</sup> | Uint8Array | false | true | 指示要设置的信息。 |  
    
## ExecutorProperty<sup>(8+)</sup>    
提供执行器的属性。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| result<sup>(8+)</sup> | number | false | true | 指示结果。 |  
| authSubType<sup>(8+)</sup> | AuthSubType | false | true | 指示认证凭据子类型。 |  
| remainTimes<sup>(8+)</sup> | number | false | false | 指示剩余次数。 |  
| freezingTime<sup>(8+)</sup> | number | false | false | 指示冻结时间。 |  
| enrollmentProgress<sup>(10+)</sup> | string | false | false | 指示录入进度，默认为空。 |  
| sensorInfo<sup>(10+)</sup> | string | false | false | 指示传感器信息，默认为空。 |  
    
## AuthResult<sup>(8+)</sup>    
表示认证结果的信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| token<sup>(8+)</sup> | Uint8Array | false | false | 指示认证令牌，默认为空。 |  
| remainTimes<sup>(8+)</sup> | number | false | false | 指示剩余次数，默认为空。 |  
| freezingTime<sup>(8+)</sup> | number | false | false | 指示冻结时间，默认为空。 |  
    
## CredentialInfo<sup>(8+)</sup>    
表示凭证信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| credType<sup>(8+)</sup> | AuthType | false | true | 指示凭据类型。 |  
| credSubType<sup>(8+)</sup> | AuthSubType | false | true | 指示凭据子类型。 |  
| token<sup>(8+)</sup> | Uint8Array | false | true | 指示认证令牌。 |  
    
## RequestResult<sup>(8+)</sup>    
表示请求结果的信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| credentialId<sup>(8+)</sup> | Uint8Array | false | false | 指示凭据索引，默认为空。 |  
    
## EnrolledCredInfo<sup>(8+)</sup>    
表示已注册凭据的信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| credentialId<sup>(8+)</sup> | Uint8Array | false | true | 指示凭据索引。 |  
| authType<sup>(8+)</sup> | AuthType | false | true | 指示认证凭据类型。 |  
| authSubType<sup>(8+)</sup> | AuthSubType | false | true | 指示认证凭据子类型。 |  
| templateId<sup>(8+)</sup> | Uint8Array | false | true | 指示凭据模板ID。 |  
    
## GetPropertyType<sup>(8+)</sup>    
表示要获取的属性类型的枚举。    
    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| AUTH_SUB_TYPE | 1 | 认证子类型。 |  
| REMAIN_TIMES | 2 | 剩余时间。 |  
| FREEZING_TIME | 3 | 冻结时间。 |  
| ENROLLMENT_PROGRESS<sup>(10+)</sup> | 4 | 录入进度。 |  
| SENSOR_INFO<sup>(10+)</sup> | 5 | 传感器信息。 |  
    
## SetPropertyType<sup>(8+)</sup>    
表示要设置的属性类型的枚举。    
    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| INIT_ALGORITHM | 1 | 初始化算法。 |  
    
## AuthType<sup>(8+)</sup>    
表示身份验证的凭据类型的枚举。    
    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PIN | 1 | 表示PIN认证类型。 |  
| FACE | 2 | 表示脸部认证类型。 |  
| FINGERPRINT<sup>(10+)</sup> | 4 | 表示指纹认证类型。 |  
| DOMAIN<sup>(9+)</sup> | 1024 | 表示域认证类型。 |  
    
## AuthSubType<sup>(8+)</sup>    
表示用于认证的凭据子类型的枚举。    
    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| PIN_SIX | 10000 | 表示6位凭证。 |  
| PIN_NUMBER | 10001 | 表示自定义数字凭证。 |  
| PIN_MIXED | 10002 | 表示自定义混合凭据。 |  
| FACE_2D | 20000 | 表示2D 人脸凭证。 |  
| FACE_3D | 20001 | 表示3D 人脸凭证。 |  
| FINGERPRINT_CAPACITIVE<sup>(10+)</sup> | 30000 | 表示电容式指纹。 |  
| FINGERPRINT_OPTICAL<sup>(10+)</sup> | 30001 | 表示光学指纹。 |  
| FINGERPRINT_ULTRASONIC<sup>(10+)</sup> | 30002 | 表示超声波指纹。 |  
| DOMAIN_MIXED<sup>(9+)</sup> | 10240001 | 表示域认证混合凭证。 |  
    
## AuthTrustLevel<sup>(8+)</sup>    
表示认证结果的受信任级别的枚举。    
    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ATL1 | 10000 | 信任级别 1。 |  
| ATL2 | 20000 | 信任级别 2。 |  
| ATL3 | 30000 | 信任级别 3。 |  
| ATL4 | 40000 | 信任级别 4。 |  
    
## Module<sup>(8+)</sup>    
表示获取信息的模块的枚举。    
    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FACE_AUTH | 1 | 表示从人脸认证获取的信息。 |  
    
## ResultCode<sup>(8+)</sup>    
表示身份验证结果码。    
    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SUCCESS | 0 | 表示身份验证成功或支持此功能。 |  
| FAIL | 1 | 表示验证器无法识别用户。 |  
| GENERAL_ERROR | 2 | 表示其他错误。 |  
| CANCELED | 3 | 表示身份验证已取消。 |  
| TIMEOUT | 4 | 表示身份验证已超时。 |  
| TYPE_NOT_SUPPORT | 5 | 表示不支持此身份验证类型。 |  
| TRUST_LEVEL_NOT_SUPPORT | 6 | 表示不支持身份验证信任级别。 |  
| BUSY | 7 | 表示身份验证任务正忙。等待几秒钟，然后重试。 |  
| INVALID_PARAMETERS | 8 | 表示参数不正确。 |  
| LOCKED | 9 | 指示身份验证器已锁定。 |  
| NOT_ENROLLED | 10 | 表示用户尚未注册验证器。 |  
    
## FaceTipsCode<sup>(8+)</sup>    
表示人脸验证过程中提示的枚举。    
    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FACE_AUTH_TIP_TOO_BRIGHT | 1 | 表示由于高照明，获得的面部图像太亮。 |  
| FACE_AUTH_TIP_TOO_DARK | 2 | 表示由于照明度低，获得的面部图像太暗。 |  
| FACE_AUTH_TIP_TOO_CLOSE | 3 | 表示面部离设备太近。 |  
| FACE_AUTH_TIP_TOO_FAR | 4 | 表示面部离设备太远。 |  
| FACE_AUTH_TIP_TOO_HIGH | 5 | 表示设备太高，仅捕捉面部上部。 |  
| FACE_AUTH_TIP_TOO_LOW | 6 | 表示设备太低，仅捕捉面部下部。 |  
| FACE_AUTH_TIP_TOO_RIGHT | 7 | 指示设备向右偏移，并且仅捕捉面部的右侧部分。 |  
| FACE_AUTH_TIP_TOO_LEFT | 8 | 指示设备向左偏移，并且仅捕捉面部的左侧部分。 |  
| FACE_AUTH_TIP_TOO_MUCH_MOTION | 9 | 表示面部信息收集过程中面部移动过快。 |  
| FACE_AUTH_TIP_POOR_GAZE | 10 | 表示面未朝向设备。 |  
| FACE_AUTH_TIP_NOT_DETECTED | 11 | 表示未检测到人脸。 |  
    
## FingerprintTips<sup>(8+)</sup>    
表示指纹身份验证过程中提示的枚举。    
    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| FINGERPRINT_TIP_GOOD | 0 | 表示采集的图像良好。 |  
| FINGERPRINT_TIP_IMAGER_DIRTY | 1 | 表示由于传感器上可疑或检测到污垢，指纹图像噪声过大。 |  
| FINGERPRINT_TIP_INSUFFICIENT | 2 | 表示由于检测到的情况，指纹图像噪声太大，无法处理。 |  
| FINGERPRINT_TIP_PARTIAL | 3 | 表示仅检测到部分指纹图像。 |  
| FINGERPRINT_TIP_TOO_FAST | 4 | 表示指纹图像由于快速运动而不完整。 |  
| FINGERPRINT_TIP_TOO_SLOW | 5 | 表示由于缺少运动，指纹图像无法读取。 |  
| FINGERPRINT_TIP_FINGER_DOWN<sup>(10+)</sup> | 6 | | FINGERPRINT_TIP_FINGER_DOWN<sup>10+</sup>   | 6     | 表示手指落下。                  | |  
| FINGERPRINT_TIP_FINGER_UP<sup>(10+)</sup> | 7 | 表示手指抬起。 |  
    
## ConstraintSourceType<sup>(9+)</sup>    
表示约束来源类型的枚举。    
    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CONSTRAINT_NOT_EXIST | 0 | 约束不存在 |  
| CONSTRAINT_TYPE_BASE | 1 | 约束源自系统设置 |  
| CONSTRAINT_TYPE_DEVICE_OWNER | 2 | 约束源自设备所有者设置 |  
| CONSTRAINT_TYPE_PROFILE_OWNER | 3 | 约束源自资料所有者设置 |  
    
## ConstraintSourceTypeInfo<sup>(9+)</sup>    
表示约束来源类型信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.Account.OsAccount    
### 属性    
 **系统能力:**  SystemCapability.Account.OsAccount    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| localId<sup>(9+)</sup> | number | false | true | 系统帐号ID |  
| type<sup>(9+)</sup> | ConstraintSourceType | false | true | 约束来源类型。 |  
