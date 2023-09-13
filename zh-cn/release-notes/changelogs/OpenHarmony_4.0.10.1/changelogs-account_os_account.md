# 帐号子系统ChangeLog

## cl.account_os_account.1 删除应用帐号授权接口

**变更影响**

基于此前版本开发的应用，无法继续使用帐号授权能力。

**关键接口/组件变更**

涉及接口：

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


变更后：

涉及接口全部删除。

**适配指导**

该接口删除后无法再使用，请同步删除相应功能。


## cl.account_os_account.2 系统帐号添加凭据接口错误码变更

**变更影响**

基于此前版本开发的应用，需要重新适配旧错误码场景的分支判断。

**关键接口/组件变更**

涉及接口：

```js
  class UserIdentityManager {
    ...
    addCredential(credentialInfo: CredentialInfo, callback: IIdmCallback): void;
    ...
  }
```

错误码列表：
| 错误码ID | 错误信息                     |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid credentialInfo, i.e. authType or authSubType. |
| 12300101 | Token is invalid. |
| 12300106 | Unsupported authType. |
| 12300109 | Operation is canceled. |
| 12300111 | Operation timeout. |
| 12300115 | The number of credentials reaches the upper limit. |


变更前：
会话超时异常场景对应的错误码返回为12300002

变更后：
会话超时异常场景对应的错误码返回为12300001


**适配指导**

根据错误码变更场景进行排查适配。
