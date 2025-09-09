# 管理域账号插件（仅对系统应用开放）

<!--Kit: Basic Services Kit-->
<!--Subsystem: Account-->
<!--Owner: @steven-q-->
<!--Designer: @JiDong-CS1-->
<!--Tester: @zhaimengchao-->
<!--Adviser: @zengyawen-->

OEM厂商可以采用插件方式定制化域账号管理能力，系统提供了域账号插件注册和注销能力。

## 开发准备

1. 申请权限，申请流程请参考：[申请应用权限](../../security/AccessToken/determine-application-mode.md#system_basic等级应用申请权限的方式)。
   - ohos.permission.MANAGE_LOCAL_ACCOUNTS
   - ohos.permission.GET_DOMAIN_ACCOUNTS

2. 导入系统账号模块。

   ```ts
   import { osAccount, AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
   ```

3. 获取系统账号管理对象。

   ```ts
   let accountMgr = osAccount.getAccountManager()
   ```

## 注册插件

域插件原型为[DomainPlugin](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#domainplugin9)，域插件开发者需要继承并实现插件原型中定义的接口。开发者可以使用[registerPlugin](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#registerplugin9)接口完成插件注册操作。

具体开发实例如下：

1. 定义插件。

   ```ts
   let plugin: osAccount.DomainPlugin = {
     auth: (domainAccountInfo: osAccount.DomainAccountInfo, credential: Uint8Array,
            callback: osAccount.IUserAuthCallback) => {
       console.info("plugin auth domain" + domainAccountInfo.domain)
       console.info("plugin auth accountName" + domainAccountInfo.accountName)
       console.info("plugin auth accountId" + domainAccountInfo.accountId)

       let result: osAccount.AuthResult = {
         token: new Uint8Array([0]),
         remainTimes: 5,
         freezingTime: 0
       };
       callback.onResult(0, result);
     },
     authWithPopup: (domainAccountInfo: osAccount.DomainAccountInfo,
                     callback: osAccount.IUserAuthCallback) => {
       console.info("plugin authWithPopup domain" + domainAccountInfo.domain)
       console.info("plugin authWithPopup accountName" + domainAccountInfo.accountName)
       console.info("plugin authWithPopup accountId" + domainAccountInfo.accountId)

       let result: osAccount.AuthResult = {
         token: new Uint8Array([0]),
         remainTimes: 5,
         freezingTime: 0
       };
       callback.onResult(0, result);
     },
     authWithToken: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array, callback: osAccount.IUserAuthCallback) => {
       console.info("plugin authWithToken domain" + domainAccountInfo.domain)
       console.info("plugin authWithToken accountName" + domainAccountInfo.accountName)
       console.info("plugin authWithToken accountId" + domainAccountInfo.accountId)
       let result: osAccount.AuthResult = {
         token: new Uint8Array([0]),
         remainTimes: 5,
         freezingTime: 0
       };
       callback.onResult(0, result);
     },
     getAccountInfo: (options: osAccount.GetDomainAccountInfoPluginOptions,
                      callback: AsyncCallback<osAccount.DomainAccountInfo>) => {
       console.info("plugin getAccountInfo domain")
       let domainAccountId = Date.now().toString()
       let code: BusinessError = {
         code: 0,
         name: "mock_name",
         message: "mock_message"
       };
       let domainStr: string = '';
       if (options.domain != undefined) {
        domainStr = options.domain
       }
       let accountInfo: osAccount.DomainAccountInfo = {
         domain: domainStr,
         accountName: options.accountName,
         accountId: domainAccountId,
         isAuthenticated: false
       };
       callback(code, accountInfo);
     },
     getAuthStatusInfo: (domainAccountInfo: osAccount.DomainAccountInfo,
                         callback: AsyncCallback<osAccount.AuthStatusInfo>) => {

       console.info("plugin getAuthStatusInfo domain" + domainAccountInfo.domain)
       console.info("plugin getAuthStatusInfo accountName" + domainAccountInfo.accountName)
       console.info("plugin getAuthStatusInfo accountId" + domainAccountInfo.accountId)

       let code: BusinessError = {
         code: 0,
         name: "mock_name",
         message: "mock_message"
       };
       let statusInfo: osAccount.AuthStatusInfo = {
         remainTimes: 5,
         freezingTime: 0
       };
       callback(code, statusInfo);
     },
     bindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, localId: number,
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
     unbindAccount: (domainAccountInfo: osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {
       console.info("plugin unbindAccount domain" + domainAccountInfo.domain)
       console.info("plugin unbindAccount accountName" + domainAccountInfo.accountName)
       console.info("plugin unbindAccount accountId" + domainAccountInfo.accountId)
     },
     isAccountTokenValid: (domainAccountInfo: osAccount.DomainAccountInfo, token: Uint8Array,
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
     getAccessToken: (options: osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {
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

2. 调用[registerPlugin](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#registerplugin9)注册插件。

   ```ts
   try {
       osAccount.DomainAccountManager.registerPlugin(plugin)
       console.info("registerPlugin success")
   } catch (err) {
       console.error(`registerPlugin err: code is ${err.code}, message is ${err.message}`);
   }
   ```

## 注销插件

当插件不再使用时，开发者可以使用[unregisterPlugin](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#unregisterplugin9)接口注销插件。

具体开发实例如下：

```ts
try {
  osAccount.DomainAccountManager.unregisterPlugin();
  console.info('unregisterPlugin success.');
} catch(err) {
  console.error(`unregisterPlugin failed, code is ${err.code}, message is ${err.message}`);
}
```
