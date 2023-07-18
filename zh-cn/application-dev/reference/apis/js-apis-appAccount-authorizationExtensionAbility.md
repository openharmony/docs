# @ohos.account.appAccount.AuthorizationExtensionAbility (应用帐号授权扩展能力)

**AuthorizationExtensionAbility**基于ExtensionAbility框架，提供应用帐号授权的能力。

> **说明：**
>
> 本模块首批接口从API version 10开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import AuthorizationExtensionAbility, { AuthorizationRequest, AuthorizationCallback } from '@ohos.account.appAccount.AuthorizationExtensionAbility';
```

## AuthorizationRequest

帐号授权请求信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.AppAccount

| 名称      | 类型                             | 可读 | 可写 | 说明   |
| --------- | ------------------------------- | ---- | ---- | ------------------------------------ |
| callerUid | number | 是   | 否   | 调用方UID。 |
| parameters | [appAccount.AccountCapabilityRequest](js-apis-appAccount.md#accountcapabilityrequest10) | 是   | 否  |   业务参数。 |

## AuthorizationCallback

帐号授权回调方法类。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.AppAccount

| 名称      | 类型                             | 可读 | 可写 | 说明   |
| --------- | ------------------------------- | ---- | ---- | ------------------------------------ |
| onResult | AsyncCallback<[appAccount.AccountCapabilityResponse](js-apis-appAccount.md#accountcapabilityresponse10), { [key: string]: object }> | 是   | 否   | 表示授权结果的回调方法。 |

## AuthorizationExtensionAbility.onStartAuthorization

onStartAuthorization(request: AuthorizationRequest, callback: AuthorizationCallback): void

开始处理授权请求的回调方法。当有新的帐号授权请求到达时，框架会回调此接口。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Account.AppAccount

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                      |
| -------- | ---------------------------------------- | ---- | ----------------------- |
| request | [AuthorizationRequest](#authorizationrequest) | 是    | 授权请求信息。 |
| callback | [AuthorizationCallback](#authorizationcallback) | 是    | 授权回调对象。 |

**示例：**

```ts
import appAccount from '@ohos.account.appAccount';

class MyResponse extends appAccount.AccountCapabilityResponse {
  name: string;
  scopes: string[];

  constructor(request: appAccount.AccountCapabilityRequest) {
    super(request);
  }
};

class MyAuthorizationExtensionAbility extends AuthorizationExtensionAbility {
  onStartAuthorization(request: AuthorizationRequest, callback: AuthorizationCallback) {
    console.log('onStartAuthorization, callerUid: ' + request.callerUid + ', parameters: ' + request.parameters);
    let response = new MyResponse(null);
    response.name = 'xxx';
    response.scopes = ['xxx', 'xxx'];
    callback.onResult(null, response);
  }
};
```
