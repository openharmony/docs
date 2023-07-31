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