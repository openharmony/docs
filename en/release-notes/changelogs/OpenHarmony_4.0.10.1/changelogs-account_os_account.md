# Account Subsystem Changelog

## cl.account_os_account.1 Deletion of App Account Authorization Interfaces

**Change Impact**

Apps developed based on earlier versions cannot use the account authorization capability.

**Key API/Component Changes**

Involved interfaces:

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


## cl.account_os_account.2 Change of the Error Codes in addCredential()

**Change Impact**

For the applications developed based on earlier versions, you need to change the error code processing logic.

**Key API/Component Changes**

Involved API:

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


Before change:
The error code 12300002 is returned when a session times out.

After change:
The error code 12300001 is returned when a session times out.


**Adaptation Guide**

Modify the error code processing logic based on the new error codes.
