# @ohos.account.appAccount.AuthorizationExtensionAbility (App AuthorizationExtensionAbility)

The **AuthorizationExtensionAbility** module provides APIs for implementing authorization to app accounts based on the ExtensionAbility framework.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import AuthorizationExtensionAbility, { AuthorizationRequest, AuthorizationCallback } from '@ohos.account.appAccount.AuthorizationExtensionAbility';
```

## AuthorizationRequest

Defines the app account authorization request.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.AppAccount

| Name     | Type                            | Readable| Writable| Description  |
| --------- | ------------------------------- | ---- | ---- | ------------------------------------ |
| callerUid | number | Yes  | No  | UID of the caller.|
| parameters | [appAccount.AccountCapabilityRequest](js-apis-appAccount.md#accountcapabilityrequest10) | Yes  | No |   Service parameters.|

## AuthorizationCallback

Provides callbacks to be invoked during the app account authorization.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.AppAccount

| Name     | Type                            | Readable| Writable| Description  |
| --------- | ------------------------------- | ---- | ---- | ------------------------------------ |
| onResult | AsyncCallback<[appAccount.AccountCapabilityResponse](js-apis-appAccount.md#accountcapabilityresponse10), { [key: string]: object }> | Yes  | No  | Callback invoked to return the authorization result.|

## AuthorizationExtensionAbility.onStartAuthorization

onStartAuthorization(request: AuthorizationRequest, callback: AuthorizationCallback): void

Called when an authorization request is received.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description                     |
| -------- | ---------------------------------------- | ---- | ----------------------- |
| request | [AuthorizationRequest](#authorizationrequest) | Yes   | Authorization request information.|
| callback | [AuthorizationCallback](#authorizationcallback) | Yes   | Authorization callback object.|

**Example**

```ts
class MyAuthorizationExtensionAbility extends AuthorizationExtensionAbility {
  onStartAuthorization(request: AuthorizationRequest, callback: AuthorizationCallback) {
    console.log('onStartAuthorization, callerUid: ' + request.callerUid + ', parameters: ' + request.parameters);
    let response = {
        name: 'xxxx',
        scopes: ['xxx', 'xxx']
    };
    callback.onResult(null, response);
  }
};
```
