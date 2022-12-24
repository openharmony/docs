# 用户认证

提供用户认证能力，可应用于设备解锁、支付、应用登录等身份认证场景。

> **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';
```

## AuthResultInfo<sup>9+</sup>

表示认证结果信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.UserIAM.UserAuth.Core。

| 名称         | 类型   | 必填 | 说明                 |
| ------------ | ---------- | ---- | -------------------- |
| result        | number | 是   | 认证结果。       |
| token        | Uint8Array | 否   | 用户身份认证通过的凭证。 |
| remainAttempts  | number     | 否   | 剩余的认证操作次数。 |
| lockoutDuration | number     | 否   | 认证操作的冻结时间。 |

## TipInfo<sup>9+</sup>

表示认证过程中的提示信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.UserIAM.UserAuth.Core。

| 名称         | 类型   | 必填 | 说明                 |
| ------------ | ---------- | ---- | -------------------- |
| module        | number | 是   | 发送提示信息的模块标识。       |
| tip        | number | 是   | 认证过程提示信息。       |

## EventInfo<sup>9+</sup>

表示认证过程中事件信息的类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.UserIAM.UserAuth.Core。

| 取值类型    | 说明                       |
| --------- | ----------------------- |
| [AuthResultInfo](#authresultinfo9)    | 获取到的认证结果信息。  |
| [TipInfo](#tipinfo9)    | 认证过程中的提示信息。      |

## AuthEventKey<sup>9+</sup>

表示认证事件类型的关键字，作为[on](#on9)接口的的参数。

| 取值类型       | 说明                    |
| ---------- | ----------------------- |
| "result" | [on](#on9)接口第一个参数为"result"时，[callback](#callback9)回调返回认证的结果信息。 |
| "tip"    | [on](#on9)接口第一个参数为"tip"时，[callback](#callback9)回调返回认证操作中的提示信息。 |

## AuthEvent<sup>9+</sup>

认证接口的异步回调对象。

### callback<sup>9+</sup>

callback(result : EventInfo) : void

通过该回调获取认证结果信息或认证过程中的提示信息。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名    | 类型                       | 必填 | 说明                           |
| --------- | -------------------------- | ---- | ------------------------------ |
| result    | [EventInfo](#eventinfo9)     | 是   | 返回的认证结果信息或提示信息。  |

**示例：**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userIAM_userAuth.UserAuthType.FACE;
let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;
// 通过callback获取认证结果
try {
    let auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
    auth.on("result", {
        callback: (result: userIAM_userAuth.AuthResultInfo) => {
            console.log("authV9 result " + result.result);
            console.log("authV9 token " + result.token);
            console.log("authV9 remainAttempts " + result.remainAttempts);
            console.log("authV9 lockoutDuration " + result.lockoutDuration);
        }
    });
    auth.start();
    console.log("authV9 start success");
} catch (error) {
    console.log("authV9 error = " + error);
    // do error
}
// 通过callback获取认证过程中的提示信息
try {
    let auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
    auth.on("tip", {
        callback : (result : userIAM_userAuth.TipInfo) => {
            switch (result.tip) {
                case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_BRIGHT:
                // do something;
                case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_DARK:
                // do something;
                default:
                // do others
            }
        }
    });
    auth.start();
    console.log("authV9 start success");
} catch (error) {
    console.log("authV9 error = " + error);
    // do error
}
```

## AuthInstance<sup>9+</sup>

执行用户认证的对象。

### on<sup>9+</sup>

on : (name : AuthEventKey, callback : AuthEvent) => void

订阅指定类型的用户认证事件。

> **说明：**
> 使用获取到的[AuthInstance](#authinstance9)对象调用该接口进行订阅。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名    | 类型                        | 必填 | 说明                       |
| --------- | -------------------------- | ---- | ------------------------- |
| name  | [AuthEventKey](#autheventkey9) | 是   | 表示认证事件类型，取值为"result"时，回调函数返回认证结果；取值为"tip"时，回调函数返回认证过程中的提示信息。 |
| callback  | [AuthEvent](#authevent9)   | 是   | 认证接口的回调函数，用于返回认证结果或认证过程中的提示信息。 |

以下错误码的详细介绍请参见[用户认证错误码](../errorcodes/errorcode-useriam.md)

**错误码：**

| 错误码ID | 错误信息 |
| -------- | ------- |
| 401 | Incorrect parameters. |
| 12500002 | General operation error. |

**示例：**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userIAM_userAuth.UserAuthType.FACE;
let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;
try {
    let auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
    // 订阅认证结果
    auth.on("result", {
        callback: (result: userIAM_userAuth.AuthResultInfo) => {
            console.log("authV9 result " + result.result);
            console.log("authV9 token " + result.token);
            console.log("authV9 remainAttempts " + result.remainAttempts);
            console.log("authV9 lockoutDuration " + result.lockoutDuration);
        }
    });
    // 订阅认证过程中的提示信息
    auth.on("tip", {
        callback : (result : userIAM_userAuth.TipInfo) => {
            switch (result.tip) {
                case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_BRIGHT:
                // do something;
                case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_DARK:
                // do something;
                default:
                // do others
            }
        }
    });
    auth.start();
    console.log("authV9 start success");
} catch (error) {
    console.log("authV9 error = " + error);
    // do error
}
```

### off<sup>9+</sup>

off : (name : AuthEventKey) => void

取消订阅特定类型的认证事件。

> **说明：**
> 需要使用已经成功订阅事件的[AuthInstance](#authinstance9)对象调用该接口进行取消订阅。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称    | 类型                        | 必填 | 说明                       |
| --------- | -------------------------- | ---- | ------------------------- |
| name    | [AuthEventKey](#autheventkey9)      | 是   | 表示认证事件类型，取值为"result"时，取消订阅认证结果；取值为"tip"时，取消订阅认证过程中的提示信息。 |

以下错误码的详细介绍请参见[用户认证错误码](../errorcodes/errorcode-useriam.md)

**错误码：**

| 错误码ID | 错误信息 |
| -------- | ------- |
| 401 | Incorrect parameters. |
| 12500002 | General operation error. |

**示例：**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userIAM_userAuth.UserAuthType.FACE;
let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;
let auth;
try {
    auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
    console.log("get auth instance success");
} catch (error) {
    console.log("get auth instance failed" + error);
}

try {
    // 订阅认证结果
    auth.on("result", {
        callback: (result: userIAM_userAuth.AuthResultInfo) => {
            console.log("authV9 result " + result.result);
            console.log("authV9 token " + result.token);
            console.log("authV9 remainAttempts " + result.remainAttempts);
            console.log("authV9 lockoutDuration " + result.lockoutDuration);
        }
    });
    console.log("subscribe authentication event success");
} catch (error) {
    console.log("subscribe authentication event failed " + error);
}
// 取消订阅认证结果
try {
    auth.off("result");
    console.info("cancel subscribe authentication event success");
} catch (error) {
    console.info("cancel subscribe authentication event failed, error = " + error);
}
```

### start<sup>9+</sup>

start : () => void

开始认证。

> **说明：**
> 使用获取到的[AuthInstance](#authinstance9)对象调用该接口进行认证。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

以下错误码的详细介绍请参见[用户认证错误码](../errorcodes/errorcode-useriam.md)

**错误码：**

| 错误码ID | 错误信息 |
| -------- | ------- |
| 201 | Permission verification failed. |
| 401 | Incorrect parameters. |
| 12500001 | Execution failed. |
| 12500002 | General operation error. |
| 12500003 | The operation is canceled. |
| 12500004 | The operation is time-out. |
| 12500005 | The authentication type is not supported. |
| 12500006 | The authentication trust level is not supported. |
| 12500007 | The authentication task is busy. |
| 12500009 | The authenticator is locked. |
| 12500010 | The type of credential has not been enrolled. |

**示例：**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userIAM_userAuth.UserAuthType.FACE;
let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;

try {
    let auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
    auth.start();
    console.info("authV9 start auth success");
} catch (error) {
    console.info("authV9 start auth failed, error = " + error);
}
```

### cancel<sup>9+</sup>

cancel : () => void

取消认证。

> **说明：**
> 使用获取到的[AuthInstance](#authinstance9)对象调用该接口进行取消认证，此[AuthInstance](#authinstance9)需要是正在进行认证的对象。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

以下错误码的详细介绍请参见[用户认证错误码](../errorcodes/errorcode-useriam.md)

**错误码：**

| 错误码ID | 错误信息 |
| -------- | ------- |
| 201 | Permission verification failed. |
| 401 | Incorrect parameters. |
| 12500002 | General operation error. |

**示例：**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userIAM_userAuth.UserAuthType.FACE;
let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;

try {
    let auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
    auth.cancel();
    console.info("cancel auth success");
} catch (error) {
    console.info("cancel auth failed, error = " + error);
}
```

## userIAM_userAuth.getAuthInstance<sup>9+</sup>

getAuthInstance(challenge : Uint8Array, authType : UserAuthType, authTrustLevel : AuthTrustLevel): AuthInstance

获取AuthInstance对象，用于执行用户身份认证。

> **说明：**
> 每个AuthInstance只能进行一次认证，若需要再次进行认证则需重新获取AuthInstance。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名         | 类型                                     | 必填 | 说明                     |
| -------------- | ---------------------------------------- | ---- | ------------------------ |
| challenge      | Uint8Array                               | 是   | 挑战值，最大长度为32字节，可以填null。     |
| authType       | [UserAuthType](#userauthtype8)           | 是   | 认证类型，当前支持FACE。 |
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8)       | 是   | 认证信任等级。               |

**返回值：**

| 类型                                      | 说明         |
| ----------------------------------------- | ------------ |
| [AuthInstance](#authinstance9) | 认证器对象。 |

以下错误码的详细介绍请参见[用户认证错误码](../errorcodes/errorcode-useriam.md)

**错误码：**

| 错误码ID | 错误信息 |
| -------- | ------- |
| 401 | Incorrect parameters. |
| 12500002 | General operation error. |
| 12500005 | The authentication type is not supported. |
| 12500006 | The authentication trust level is not supported. |

**示例：**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userIAM_userAuth.UserAuthType.FACE;
let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;

try {
    let auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
    console.info("get auth instance success");
} catch (error) {
    console.info("get auth instance success failed, error = " + error);
}
```

## userIAM_userAuth.getVersion<sup>9+</sup>

getVersion(): number

获取认证器的版本信息。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**返回值：**

| 类型   | 说明                   |
| ------ | ---------------------- |
| number | 认证器版本信息。 |

以下错误码的详细介绍请参见[用户认证错误码](../errorcodes/errorcode-useriam.md)

**错误码：**

| 错误码ID | 错误信息 |
| -------- | ------- |
| 201 | Permission verification failed. |
| 12500002 | General operation error. |

**示例：**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

try {
    let version = userIAM_userAuth.getVersion();
    console.info("auth version = " + version);
} catch (error) {
    console.info("get version failed, error = " + error);
}
```

## userIAM_userAuth.getAvailableStatus<sup>9+</sup>

getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel): void

查询指定类型和等级的认证能力是否支持。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名         | 类型                               | 必填 | 说明                       |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| authType       | [UserAuthType](#userauthtype8)     | 是   | 认证类型，当前只支持FACE。 |
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8) | 是   | 认证信任等级。       |

以下错误码的详细介绍请参见[用户认证错误码](../errorcodes/errorcode-useriam.md)

**错误码：**

| 错误码ID | 错误信息 |
| -------- | ------- |
| 201 | Permission verification failed. |
| 401 | Incorrect parameters. |
| 12500002 | General operation error. |
| 12500005 | The authentication type is not supported. |
| 12500006 | The authentication trust level is not supported. |
| 12500010 | The type of credential has not been enrolled. |

**示例：**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

try {
    userIAM_userAuth.getAvailableStatus(userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1);
    console.info("current auth trust level is supported");
} catch (error) {
    console.info("current auth trust level is not supported, error = " + error);
}
```

## ResultCodeV9<sup>9+</sup>

表示返回码的枚举。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称                    |   值   | 说明                 |
| ----------------------- | ------ | -------------------- |
| SUCCESS                 | 12500000      | 执行成功。           |
| FAIL                    | 12500001      | 执行失败。           |
| GENERAL_ERROR           | 12500002      | 操作通用错误。       |
| CANCELED                | 12500003      | 操作取消。           |
| TIMEOUT                 | 12500004      | 操作超时。           |
| TYPE_NOT_SUPPORT        | 12500005      | 不支持的认证类型。   |
| TRUST_LEVEL_NOT_SUPPORT | 12500006      | 不支持的认证等级。   |
| BUSY                    | 12500007      | 忙碌状态。           |
| LOCKED                  | 12500009      | 认证器已锁定。       |
| NOT_ENROLLED            | 12500010      | 用户未录入认证信息。 |

## UserAuth<sup>8+</sup>

认证器对象。

### constructor<sup>(deprecated)</sup>

constructor()

创建认证器对象。

> **说明：**
> 从 API version 9 开始废弃，请使用[getAuthInstance](#useriam_userauthgetauthinstance9)替代。
<br/>从 API version 8 开始支持。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**返回值：**

| 类型                   | 说明                 |
| ---------------------- | -------------------- |
| [UserAuth](#userauth8) | 认证器对象。 |

**示例：**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let auth = new userIAM_userAuth.UserAuth();
```

### getVersion<sup>(deprecated)</sup>

getVersion() : number

获取认证器的版本信息。

> **说明：**
> 从 API version 9 开始废弃，请使用[getVersion](#useriam_userauthgetversion9)替代。
<br/>从 API version 8 开始支持。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**返回值：**

| 类型   | 说明                   |
| ------ | ---------------------- |
| number | 认证器版本信息。 |

**示例：**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let auth = new userIAM_userAuth.UserAuth();
let version = auth.getVersion();
console.info("auth version = " + version);
```

### getAvailableStatus<sup>(deprecated)</sup>

getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel) : number

查询指定类型和等级的认证能力是否支持。

> **说明：**
> 从 API version 9 开始废弃，请使用[getAvailableStatus](#useriam_userauthgetavailablestatus9)替代。
<br/>从 API version 8 开始支持。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名         | 类型                               | 必填 | 说明                       |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| authType       | [UserAuthType](#userauthtype8)     | 是   | 认证类型，当前只支持FACE。 |
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8) | 是   | 认证信任等级。       |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 查询结果，结果为SUCCESS时表示支持，其他返回值参见[ResultCode](#resultcodedeprecated)。 |

**示例：**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let auth = new userIAM_userAuth.UserAuth();
let checkCode = auth.getAvailableStatus(userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1);
if (checkCode == userIAM_userAuth.ResultCode.SUCCESS) {
    console.info("check auth support success");
} else {
    console.error("check auth support fail, code = " + checkCode);
}
```

### auth<sup>(deprecated)</sup>

auth(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array

执行用户认证，使用回调函数返回结果。

> **说明：**
> 从 API version 9 开始废弃，建议使用[start](#start9)代替。
<br/>从 API version 8 开始支持。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名         | 类型                                     | 必填 | 说明                     |
| -------------- | ---------------------------------------- | ---- | ------------------------ |
| challenge      | Uint8Array                               | 是   | 挑战值，可以填null。     |
| authType       | [UserAuthType](#userauthtype8)           | 是   | 认证类型，当前支持FACE。 |
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8)       | 是   | 认证信任等级。             |
| callback       | [IUserAuthCallback](#iuserauthcallbackdeprecated) | 是   | 回调函数。        |

**返回值：**

| 类型       | 说明                                                         |
| ---------- | ------------------------------------------------------------ |
| Uint8Array | ContextId，作为取消认证[cancelAuth](#cancelauthdeprecated)接口的入参。 |

**示例：**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let auth = new userIAM_userAuth.UserAuth();
auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
    onResult: (result, extraInfo) => {
        try {
            console.info("auth onResult result = " + result);
            console.info("auth onResult extraInfo = " + JSON.stringify(extraInfo));
            if (result == userIAM_userAuth.ResultCode.SUCCESS) {
                // 此处添加认证成功逻辑
            } else {
                // 此处添加认证失败逻辑
            }
        } catch (e) {
            console.info("auth onResult error = " + e);
        }
    }
});
```

### cancelAuth<sup>(deprecated)</sup>

cancelAuth(contextID : Uint8Array) : number

表示通过contextID取消本次认证操作。

> **说明：**
> 从 API version 9 开始废弃，建议使用[cancel](#cancel9)代替。
<br/>从 API version 8 开始支持。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名    | 类型       | 必填 | 说明                                       |
| --------- | ---------- | ---- | ------------------------------------------ |
| contextID | Uint8Array | 是   | 上下文的标识，通过[auth](#authdeprecated)接口获取。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| number | 取消认证的结果，结果为SUCCESS时表示取消成功，其他返回值参见[ResultCode](#resultcodedeprecated)。 |

**示例：**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

// contextId可通过auth接口获取，此处直接定义
let contextId = new Uint8Array([0, 1, 2, 3, 4, 5, 6, 7]);
let auth = new userIAM_userAuth.UserAuth();
let cancelCode = auth.cancelAuth(contextId);
if (cancelCode == userIAM_userAuth.ResultCode.SUCCESS) {
    console.info("cancel auth success");
} else {
    console.error("cancel auth fail");
}
```

## IUserAuthCallback<sup>(deprecated)</sup>

返回认证结果的回调对象。

> **说明：**
> 从 API version 9 开始废弃，建议使用[AuthEvent](#authevent9)代替。
<br/>从 API version 8 开始支持。

### onResult<sup>(deprecated)</sup>

onResult: (result : number, extraInfo : AuthResult) => void

回调函数，返回认证结果。

> **说明：**
> 从 API version 9 开始废弃，建议使用[callback](#callback9)代替。
<br/>从 API version 8 开始支持。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名    | 类型                       | 必填 | 说明        |
| --------- | -------------------------- | ---- | ------------------------------------------------ |
| result    | number           | 是   | 认证结果，参见[ResultCode](#resultcodedeprecated)。 |
| extraInfo | [AuthResult](#authresultdeprecated) | 是   | 扩展信息，不同情况下的具体信息，<br/>如果身份验证通过，则在extraInfo中返回用户认证令牌，<br/>如果身份验证失败，则在extraInfo中返回剩余的用户认证次数，<br/>如果身份验证执行器被锁定，则在extraInfo中返回冻结时间。 |

**示例：**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let auth = new userIAM_userAuth.UserAuth();
auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
    onResult: (result, extraInfo) => {
        try {
            console.info("auth onResult result = " + result);
            console.info("auth onResult extraInfo = " + JSON.stringify(extraInfo));
            if (result == userIAM_userAuth.ResultCode.SUCCESS) {
                // 此处添加认证成功逻辑
            }  else {
                // 此处添加认证失败逻辑
            }
        } catch (e) {
            console.info("auth onResult error = " + e);
        }
    }
});
```

### onAcquireInfo<sup>(deprecated)</sup>

onAcquireInfo ?: (module : number, acquire : number, extraInfo : any) => void

回调函数，返回认证过程中的提示信息，非必须实现。

> **说明：**
> 从 API version 9 开始废弃，建议使用[callback](#callback9)代替。
<br/>从 API version 8 开始支持。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明                           |
| --------- | ------ | ---- | ------------------------------ |
| module    | number | 是   | 发送提示信息的模块标识。             |
| acquire   | number | 是   | 认证执过程中的提示信息。 |
| extraInfo | any    | 是   | 预留字段。                     |

**示例：**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let auth = new userIAM_userAuth.UserAuth();
auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
    onAcquireInfo: (module, acquire, extraInfo) => {
        try {
            console.info("auth onAcquireInfo module = " + module);
            console.info("auth onAcquireInfo acquire = " + acquire);
            console.info("auth onAcquireInfo extraInfo = " + JSON.stringify(extraInfo));
        } catch (e) {
            console.info("auth onAcquireInfo error = " + e);
        }
    }
});
```

## AuthResult<sup>(deprecated)</sup>

表示认证结果的对象。

> **说明：**
> 从 API version 9 开始废弃，建议使用[AuthResultInfo](#authresultinfo9)代替。
<br/>从 API version 8 开始支持。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称         | 类型   | 必填 | 说明                 |
| ------------ | ---------- | ---- | -------------------|
| token        | Uint8Array | 否   | 认证通过的令牌信息。 |
| remainTimes  | number     | 否   | 剩余的认证操作次数。 |
| freezingTime | number     | 否   | 认证操作的冻结时间。 |

## ResultCode<sup>(deprecated)</sup>

表示返回码的枚举。

> **说明：**
> 从 API version 9 开始废弃，建议使用[ResultCodeV9](#resultcodev99)代替。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称                    | 值 | 说明                 |
| ----------------------- | ------ | -------------------- |
| SUCCESS                 | 0      | 执行成功。           |
| FAIL                    | 1      | 执行失败。           |
| GENERAL_ERROR           | 2      | 操作通用错误。       |
| CANCELED                | 3      | 操作取消。           |
| TIMEOUT                 | 4      | 操作超时。           |
| TYPE_NOT_SUPPORT        | 5      | 不支持的认证类型。   |
| TRUST_LEVEL_NOT_SUPPORT | 6      | 不支持的认证等级。   |
| BUSY                    | 7      | 忙碌状态。           |
| INVALID_PARAMETERS      | 8      | 无效参数。           |
| LOCKED                  | 9      | 认证器已锁定。       |
| NOT_ENROLLED            | 10     | 用户未录入认证信息。 |

## FaceTips<sup>8+</sup>

表示人脸认证过程中提示码的枚举。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称                          |   值   |    说明                             |
| ----------------------------- | ------ | ------------------------------------ |
| FACE_AUTH_TIP_TOO_BRIGHT      | 1      | 光线太强，获取的图像太亮。           |
| FACE_AUTH_TIP_TOO_DARK        | 2      | 光线太暗，获取的图像太暗。           |
| FACE_AUTH_TIP_TOO_CLOSE       | 3      | 人脸距离设备过近。                   |
| FACE_AUTH_TIP_TOO_FAR         | 4      | 人脸距离设备过远。                   |
| FACE_AUTH_TIP_TOO_HIGH        | 5      | 设备太高，仅获取到人脸上部。         |
| FACE_AUTH_TIP_TOO_LOW         | 6      | 设备太低，仅获取到人脸下部。         |
| FACE_AUTH_TIP_TOO_RIGHT       | 7      | 设备太靠右，仅获取到人脸右部。       |
| FACE_AUTH_TIP_TOO_LEFT        | 8      | 设备太靠左，仅获取到人脸左部。       |
| FACE_AUTH_TIP_TOO_MUCH_MOTION | 9      | 在图像采集过程中，用户人脸移动太快。 |
| FACE_AUTH_TIP_POOR_GAZE       | 10     | 没有正视摄像头。                     |
| FACE_AUTH_TIP_NOT_DETECTED    | 11     | 没有检测到人脸信息。                 |


## FingerprintTips<sup>8+</sup>

表示指纹认证过程中提示码的枚举。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称                              |   值   | 说明                                               |
| --------------------------------- | ------ | -------------------------------------------------- |
| FINGERPRINT_AUTH_TIP_GOOD         | 0      | 获取的指纹图像良好。                               |
| FINGERPRINT_AUTH_TIP_DIRTY        | 1      | 由于传感器上可疑或检测到的污垢，指纹图像噪音过大。 |
| FINGERPRINT_AUTH_TIP_INSUFFICIENT | 2      | 由于检测到的情况，指纹图像噪声太大，无法处理。     |
| FINGERPRINT_AUTH_TIP_PARTIAL      | 3      | 仅检测到部分指纹图像。                             |
| FINGERPRINT_AUTH_TIP_TOO_FAST     | 4      | 快速移动，指纹图像不完整。                         |
| FINGERPRINT_AUTH_TIP_TOO_SLOW     | 5      | 缺少运动，指纹图像无法读取。                       |


## UserAuthType<sup>8+</sup>

表示身份认证的凭据类型枚举。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称        |   值   | 说明       |
| ----------- | ------ | ---------- |
| FACE        | 2      | 人脸认证。 |
| FINGERPRINT | 4      | 指纹认证。 |

## AuthTrustLevel<sup>8+</sup>

表示认证结果的信任等级枚举。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称 |   值   | 说明                      |
| ---- | ------ | ------------------------- |
| ATL1 | 10000  | 认证结果的信任等级级别1。 |
| ATL2 | 20000  | 认证结果的信任等级级别2。 |
| ATL3 | 30000  | 认证结果的信任等级级别3。 |
| ATL4 | 40000  | 认证结果的信任等级级别4。 |

## userIAM_userAuth.getAuthenticator<sup>(deprecated)</sup>

getAuthenticator(): Authenticator

获取Authenticator对象，用于执行用户身份认证。

> **说明：**
> 从 API version 8 开始废弃，建议使用[constructor](#constructordeprecated)替代。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**返回值：**

| 类型                                      | 说明         |
| ----------------------------------------- | ------------ |
| [Authenticator](#authenticatordeprecated) | 认证器对象。 |

**示例：**
  ```js
  let authenticator = userIAM_userAuth.getAuthenticator();
  ```

## Authenticator<sup>(deprecated)</sup>

认证器对象。

> **说明：**
> 从 API version 8 开始废弃，建议使用[UserAuth](#userauth8)替代。

### execute<sup>(deprecated)</sup>

execute(type: AuthType, level: SecureLevel, callback: AsyncCallback&lt;number&gt;): void

执行用户认证，使用callback方式作为异步方法。

> **说明：**
> 从 API version 8 开始废弃，建议使用[auth](#authdeprecated)替代。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名   | 类型                        | 必填 | 说明                      |
| -------- | --------------------------- | ---- | -------------------------- |
| type     | AuthType                      | 是   | 认证类型，当前只支持"FACE_ONLY"。<br/>ALL为预留参数，当前版本暂不支持ALL类型的认证。 |
| level    | SecureLevel  | 是   | 安全级别，对应认证的安全级别，有效值为"S1"（最低）、"S2"、"S3"、"S4"（最高）。<br/>具备3D人脸识别能力的设备支持"S3"及以下安全级别的认证。<br/>具备2D人脸识别能力的设备支持"S2"及以下安全级别的认证。 |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。    |

callback返回值：

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 表示认证结果，参见[AuthenticationResult](#authenticationresultdeprecated)。 |

**示例：**

```js
let authenticator = userIAM_userAuth.getAuthenticator();
authenticator.execute("FACE_ONLY", "S2", (error, code)=>{
    if (code === userIAM_userAuth.ResultCode.SUCCESS) {
        console.info("auth success");
        return;
    }
    console.error("auth fail, code = " + code);
});
```


### execute<sup>(deprecated)</sup>

execute(type : AuthType, level : SecureLevel): Promise&lt;number&gt;

执行用户认证，使用promise方式作为异步方法。

> **说明：**
> 从 API version 8 开始废弃，建议使用[auth](#authdeprecated)替代。

**需要权限**：ohos.permission.ACCESS_BIOMETRIC

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | AuthType | 是   | 认证类型，当前只支持"FACE_ONLY"。<br/>ALL为预留参数，当前版本暂不支持ALL类型的认证。 |
| level  | SecureLevel | 是   | 安全级别，对应认证的安全级别，有效值为"S1"（最低）、"S2"、"S3"、"S4"（最高）。<br/>具备3D人脸识别能力的设备支持"S3"及以下安全级别的认证。<br/>具备2D人脸识别能力的设备支持"S2"及以下安全级别的认证。 |

**返回值：**

| 类型                  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | 返回携带一个number的Promise。number&nbsp;为认证结果，参见[AuthenticationResult](#authenticationresultdeprecated)。 |

**示例：**

```js
let authenticator = userIAM_userAuth.getAuthenticator();
authenticator.execute("FACE_ONLY", "S2").then((code)=>{
    console.info("auth success");
}).catch((error)=>{
    console.error("auth fail, code = " + error);
});
```

## AuthenticationResult<sup>(deprecated)</sup>

表示认证结果的枚举。

> **说明：**
> 从 API version 8 开始废弃，建议使用[ResultCode](#resultcodedeprecated)替代。

**系统能力**：SystemCapability.UserIAM.UserAuth.Core

| 名称               |   值   | 说明                       |
| ------------------ | ------ | -------------------------- |
| NO_SUPPORT         | -1     | 设备不支持当前的认证方式。 |
| SUCCESS            | 0      | 认证成功。                 |
| COMPARE_FAILURE    | 1      | 比对失败。                 |
| CANCELED           | 2      | 用户取消认证。             |
| TIMEOUT            | 3      | 认证超时。                 |
| CAMERA_FAIL        | 4      | 开启相机失败。             |
| BUSY               | 5      | 认证服务忙，请稍后重试。   |
| INVALID_PARAMETERS | 6      | 认证参数无效。             |
| LOCKED             | 7      | 认证失败次数过多，已锁定。 |
| NOT_ENROLLED       | 8      | 未录入认证凭据。           |
| GENERAL_ERROR      | 100    | 其他错误。                 |
