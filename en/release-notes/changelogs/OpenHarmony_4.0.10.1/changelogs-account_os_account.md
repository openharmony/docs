# Account Subsystem Changelog

## cl.account_os_account.1 Deletion of App Account Authorization Interfaces

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


After change:

All the involved interfaces are deleted.

**Adaptation Guide**

The deleted interfaces cannot be used any longer.
