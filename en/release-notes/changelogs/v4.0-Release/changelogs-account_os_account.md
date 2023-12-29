# Account Changelog

## cl.account_os_account.1 Deletion of the App Account Authorization Interfaces

**Change Impact**

Apps developed based on earlier versions cannot use the account authorization capability.

**Key API/Component Changes**

Involved APIs:

interface/sdk-js/api/@ohos.account.appAccount.d.ts:

```js
    enum AccountCapabilityType
```
```js
    class AccountCapabilityProvider
```
```js
    class AuthorizationProvider extends AccountCapabilityProvider
```
```js
    interface AuthorizationProviderInfo
```
```js
    class AccountCapabilityRequest
```
```js
    class AccountCapabilityResponse
```
```js
    class AccountCapabilityScheduler
```

interface/sdk-js/api/@ohos.account.appAccount.AuthorizationExtensionAbility.d.ts:

```js
    export default class AuthorizationExtensionAbility extends ExtensionAbility
```
```js
    declare interface AuthorizationRequest
```
```js
    declare interface AuthorizationCallback
```


After the change:

All the involved interfaces are deleted.

**Adaptation Guide**

The deleted interfaces cannot be used any longer.


## cl.account_os_account.2 Change of the Error Codes in addCredential()

**Change Impact**

For the applications developed based on earlier versions, you need to change the error code processing logic.

**Key API/Component Changes**

Involved APIs:

```js
  class UserIdentityManager {
    ...
    addCredential(credentialInfo: CredentialInfo, callback: IIdmCallback): void;
    ...
  }
```

Error code list:
| ID| Error Message                    |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid credentialInfo, i.e. authType or authSubType. |
| 12300101 | Token is invalid. |
| 12300106 | Unsupported authType. |
| 12300109 | Operation is canceled. |
| 12300111 | Operation timeout. |
| 12300115 | The number of credentials reaches the upper limit. |


Before the change:
The error code 12300002 is returned when a session times out.

After the change:
The error code 12300001 is returned when a session times out.


**Adaptation Guide**

Modify the error code processing logic based on the new error codes.


## cl.account_os_account.3 Change of getAccountInfo()

Changed the parameters in **getAccountInfo()** from specified type to extensible type (**GetDomainAccountInfoPluginOptions**) to improve the parameter scalability.

**Change Impact**

New parameters must be used. Otherwise, the compilation fails. For details about the adaptation, see the following sample code.

**Key API/Component Changes**

Before change:

```js
  interface DomainPlugin {
    ...
    getAccountInfo(domain: string, accountName: string, callback: AsyncCallback<DomainAccountInfo>): void;
    ...
  }
```

After change:
```js
  interface DomainPlugin {
    ...
    getAccountInfo(options: GetDomainAccountInfoPluginOptions, callback: AsyncCallback<DomainAccountInfo>): void;
    ...
  }
```

**Adaptation Guide**

Change **domain** and **accountName** to **GetDomainAccountInfoPluginOptions**. The sample code is as follows:

```js
  let plugin: account_osAccount.DomainPlugin = {
  auth: (domainAccountInfo: account_osAccount.DomainAccountInfo, credential: Uint8Array,
        callback: account_osAccount.IUserAuthCallback) => {},
  authWithPopup: (domainAccountInfo: account_osAccount.DomainAccountInfo,
                  callback: account_osAccount.IUserAuthCallback) => {},
  authWithToken: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,
                  callback: account_osAccount.IUserAuthCallback) => {},
  getAccountInfo: (options: account_osAccount.GetDomainAccountInfoPluginOptions, // Change the input parameters.
                  callback: AsyncCallback<account_osAccount.DomainAccountInfo>) => {
    // mock getting account information
    // notify result
    let code: BusinessError = {
      code: 0,
      name: "",
      message: ""
    };
    let accountInfo: account_osAccount.DomainAccountInfo = {
      domain: options.domain, // Obtain the input parameter.
      accountName: options.accountName, // Obtain the input parameter.
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
