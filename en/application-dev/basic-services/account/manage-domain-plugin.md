# Managing Domain Account Plugins (for System Applications Only)

<!--Kit: Basic Services Kit-->
<!--Subsystem: Account-->
<!--Owner: @steven-q-->
<!--Designer: @JiDong-CS1-->
<!--Tester: @zhaimengchao-->
<!--Adviser: @zengyawen-->

The system provides APIs for registering and unregistering a domain account plugin, which is used to customize domain account management.

## Before You Start

1. Request the following permissions. For details, see [Requesting Permissions for system_basic Applications](../../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).
   - ohos.permission.MANAGE_LOCAL_ACCOUNTS
   - ohos.permission.GET_DOMAIN_ACCOUNTS

2. Import the **osAccount** module.

   ```ts
   import { osAccount, AsyncCallback, BusinessError } from '@kit.BasicServicesKit';
   ```

3. Obtain an **AccountManager** instance.

   ```ts
   let accountMgr = osAccount.getAccountManager()
   ```

## Registering a Domain Account Plugin

The domain account plugin prototype is [DomainPlugin](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#domainplugin9). The domain account plugin must inherit and implement the **DomainPlugin** APIs. You can use [registerPlugin](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#registerplugin9) to register a plugin.

**Procedure**

1. Define the plugin.

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

2. Use [registerPlugin](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#registerplugin9) to register the plug-in.

   ```ts
   try {
       osAccount.DomainAccountManager.registerPlugin(plugin)
       console.info("registerPlugin success")
   } catch (err) {
       console.error("registerPlugin err: " + JSON.stringify(err));
   }
   ```

## Unregistering a Domain Account Plugin

Use [unregisterPlugin](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#unregisterplugin9) to unregister a domain account plugin that is not required.

**Procedure**

```ts
try {
  osAccount.DomainAccountManager.unregisterPlugin();
  console.log('unregisterPlugin success.');
} catch(err) {
  console.error('unregisterPlugin err:' + JSON.stringify(err));
}
```
