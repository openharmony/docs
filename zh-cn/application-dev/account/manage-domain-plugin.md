# 管理域帐号插件

OEM厂商可以采用插件方式定制化域帐号管理能力，系统提供了域帐号插件注册和注销能能力。

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
   let accountMgr = account_osAccount.getAccountManager()
   ```

## 注册插件

域插件原型为[DomainPlugin](../reference/apis/js-apis-osAccount.md#domainplugin9)，域插件开发者需要继承并实现插件原型中定义的接口。开发者可以使用[registerPlugin](../reference/apis/js-apis-osAccount.md#registerplugin9)接口完成插件注册操作。

具体开发实例如下：

1. 定义插件。

   ```ts
   let plugin: account_osAccount.DomainPlugin = {
     auth: (domainAccountInfo: account_osAccount.DomainAccountInfo, credential: Uint8Array,
            callback: account_osAccount.IUserAuthCallback) => {
       console.info("plugin auth domain" + domainAccountInfo.domain)
       console.info("plugin auth accountName" + domainAccountInfo.accountName)
       console.info("plugin auth accountId" + domainAccountInfo.accountId)

       let result: account_osAccount.AuthResult = {
         token: new Uint8Array([0]),
         remainTimes: 5,
         freezingTime: 0
       };
       callback.onResult(0, result);
     },
     authWithPopup: (domainAccountInfo: account_osAccount.DomainAccountInfo,
                     callback: account_osAccount.IUserAuthCallback) => {
       console.info("plugin authWithPopup domain" + domainAccountInfo.domain)
       console.info("plugin authWithPopup accountName" + domainAccountInfo.accountName)
       console.info("plugin authWithPopup accountId" + domainAccountInfo.accountId)

       let result: account_osAccount.AuthResult = {
         token: new Uint8Array([0]),
         remainTimes: 5,
         freezingTime: 0
       };
       callback.onResult(0, result);
     },
     authWithToken: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array, callback: account_osAccount.IUserAuthCallback) => {
       console.info("plugin authWithToken domain" + domainAccountInfo.domain)
       console.info("plugin authWithToken accountName" + domainAccountInfo.accountName)
       console.info("plugin authWithToken accountId" + domainAccountInfo.accountId)
       let result: account_osAccount.AuthResult = {
         token: new Uint8Array([0]),
         remainTimes: 5,
         freezingTime: 0
       };
       callback.onResult(0, result);
     },
     getAccountInfo: (options: account_osAccount.GetDomainAccountInfoPluginOptions,
                      callback: AsyncCallback<account_osAccount.DomainAccountInfo>) => {
       console.info("plugin getAccountInfo domain")
       let domainAccountId = Date.now().toString()
       let code: BusinessError = {
         code: 0,
         name: "mock_name",
         message: "mock_message"
       };
       let accountInfo: account_osAccount.DomainAccountInfo = {
         domain: options.domain,
         accountName: options.accountName,
         accountId: domainAccountId,
         isAuthenticated: false
       };
       callback(code, accountInfo);
     },
     getAuthStatusInfo: (domainAccountInfo: account_osAccount.DomainAccountInfo,
                         callback: AsyncCallback<account_osAccount.AuthStatusInfo>) => {

       console.info("plugin getAuthStatusInfo domain" + domainAccountInfo.domain)
       console.info("plugin getAuthStatusInfo accountName" + domainAccountInfo.accountName)
       console.info("plugin getAuthStatusInfo accountId" + domainAccountInfo.accountId)

       let code: BusinessError = {
         code: 0,
         name: "mock_name",
         message: "mock_message"
       };
       let statusInfo: account_osAccount.AuthStatusInfo = {
         remainTimes: 5,
         freezingTime: 0
       };
       callback(code, statusInfo);
     },
     bindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, localId: number,
                   callback: AsyncCallback<void>) => {
       console.info("plugin bindAccount domain" + domainAccountInfo.domain)
       console.info("plugin bindAccount accountName" + domainAccountInfo.accountName)
       console.info("plugin bindAccount accountId" + domainAccountInfo.accountId)
       let code: BusinessError = {
         code: 0,
         name: "mock_name",
         message: "mock_message"
       };
       callback(code);
     },
     unbindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {
       console.info("plugin unbindAccount domain" + domainAccountInfo.domain)
       console.info("plugin unbindAccount accountName" + domainAccountInfo.accountName)
       console.info("plugin unbindAccount accountId" + domainAccountInfo.accountId)
     },
     isAccountTokenValid: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,
                           callback: AsyncCallback<boolean>) => {
       console.info("plugin isAccountTokenValid domain" + domainAccountInfo.domain)
       console.info("plugin isAccountTokenValid accountName" + domainAccountInfo.accountName)
       console.info("plugin isAccountTokenValid accountId" + domainAccountInfo.accountId)
       let code: BusinessError = {
         code: 0,
         name: "mock_name",
         message: "mock_message"
       };
       callback(code, true);
     },
     getAccessToken: (options: account_osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {
       console.info("plugin getAccessToken domain")
       let code: BusinessError = {
         code: 0,
         name: "mock_name",
         message: "mock_message"
       };
       let token: Uint8Array = new Uint8Array([0]);
       callback(code, token);
     }
   }
   ```

2. 调用[registerPlugin](../reference/apis/js-apis-osAccount.md#registerplugin9)注册插件。

   ```ts
   try {
       account_osAccount.DomainAccountManager.registerPlugin(plugin)
       console.info("registerPlugin success")
   } catch (err) {
       console.info("registerPlugin err: " + JSON.stringify(err));
   }
   ```

## 注销插件

当插件不再使用时，开发者可以使用[unregisterPlugin](../reference/apis/js-apis-osAccount.md#unregisterplugin9)接口注销插件。

具体开发实例如下：

```ts
try {
  account_osAccount.DomainAccountManager.unregisterPlugin();
  console.log('unregisterPlugin success.');
} catch(err) {
  console.log('unregisterPlugin err:' + JSON.stringify(err));
}
```
