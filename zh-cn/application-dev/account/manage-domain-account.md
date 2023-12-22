# 管理域帐号（仅对系统应用开放）

用户可以在系统中添加域帐号，后续可以域帐号身份登录、使用系统。

## 开发准备

1. 申请权限，申请流程请参考：[访问控制授权申请指导](../security/accesstoken-guidelines.md)。
   - ohos.permission.MANAGE_LOCAL_ACCOUNTS
   - ohos.permission.GET_DOMAIN_ACCOUNTS

2. 导入系统帐号模块。

   ```ts
   import account_osAccount from '@ohos.account.osAccount';
   import { AsyncCallback, BusinessError } from '@ohos.base';
   ```

3. 获取获取系统帐号管理对象。

   ```ts
   let osAccountMgr = account_osAccount.getAccountManager();
   ```

## 判断指定域帐号是否存在

在添加域帐号之前，应该先判断域帐号是否存在。开发者可以使用[hasAccount](../reference/apis/js-apis-osAccount.md#hasaccount10)接口进行判断。

具体开发实例如下：

1. 定义待判断的域帐号信息。

   ```ts
   let domainAccountInfo: account_osAccount.DomainAccountInfo = {
     accountName: 'testAccountName',
     domain: 'testDomain'
   }
   ```

2. 调用[hasAccount](../reference/apis/js-apis-osAccount.md#hasaccount10)接口。

   ```ts
   let isAccountExisted: boolean = await account_osAccount.DomainAccountManager.hasAccount(domainAccountInfo);
   ```

## 添加域帐号

用户在设置中添加其他域帐号，允许其他域帐号用户使用同一设备。开发者可以使用[createOsAccountForDomain](../reference/apis/js-apis-osAccount.md#createosaccountfordomain)完成此操作。

具体开发实例如下：

1. 定义域帐号信息，指定域名、帐号名、帐号标识（可选）。

   ```ts
   let domainInfo: account_osAccount.DomainAccountInfo = {
     domain: 'testDomain',
     accountName: 'testAccountName'
   };
   ```

2. 指定类型和域帐号信息，调用[createOsAccount]()接口在设备上创建一个域帐号。

   ```ts
   try {
     accountMgr.createOsAccountForDomain(account_osAccount.OsAccountType.NORMAL, domainInfo,
     (err: BusinessError, osAccountInfo: account_osAccount.OsAccountInfo)=>{
       console.log('createOsAccountForDomain err:' + JSON.stringify(err));
       console.log('createOsAccountForDomain osAccountInfo:' + JSON.stringify(osAccountInfo));
   });
   } catch (e) {
   console.log('createOsAccountForDomain exception: ' + JSON.stringify(e));
   }
   ```

## 删除域帐号

用户可以删除不再使用的域帐号。由于域帐号和系统帐号是一一绑定关系，开发者可以使用[removeOsAccount](../reference/apis/js-apis-osAccount.md#removeosaccount)接口删除与目标域帐号绑定的系统帐号，进而实现删除域帐号。

具体开发实例如下：

1. 调用[getOsAccountLocalIdForDomain](../reference/apis/js-apis-osAccount.md#getosaccountlocalidfordomain)方法，根据域帐号信息获取系统帐号ID。

   ```ts
   let domainInfo: account_osAccount.DomainAccountInfo = {
       domain: 'testDomain',
       accountName: 'testAccountName'
   };

   try {
     let localId: number = accountMgr.getOsAccountLocalIdForDomain(domainInfo);
   } catch (err) {
     console.log('getOsAccountLocalIdForDomain exception: ' + JSON.stringify(err));
   }
   ```

2. 调用[removeOsAccount](../reference/apis/js-apis-osAccount.md#removeosaccount)方法删除域帐号。

   ```ts
   try {
     accountMgr.removeOsAccount(osAccountInfo.localId, (err: BusinessError)=>{
       if (err) {
           console.log('removeOsAccount failed, error: ' + JSON.stringify(err));
       } else {
           console.log('removeOsAccount successfully');
       }
     });
   } catch (err) {
     console.log('removeOsAccount exception: ' + JSON.stringify(err));
   }
   ```

## 查询域帐号信息

用户通过身份认证后，可以查询自己或他人的域帐号信息。开发者可以使用[getAccountInfo](../reference/apis/js-apis-osAccount.md#getaccountinfo10)接口完成此操作。

具体开发实例如下：

1. 定义查询选项，可以指定需要查询的域名和帐号名。选项的类型为[GetDomainAccountInfoOptions](../reference/apis/js-apis-osAccount.md#getdomainaccountinfooptions10)。

   ```ts
   let options: account_osAccount.GetDomainAccountInfoOptions = {
       domain: 'testDomain',
       accountName: 'testAccountName'
   }
   ```

2. 调用[getAccountInfo](../reference/apis/js-apis-osAccount.md#getaccountinfo10)接口查询域帐号信息。

   ```ts
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
