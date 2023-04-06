# @ohos.userIAM.userAuth (User Authentication)

The **userIAM.userAuth** module provides user authentication capabilities in identity authentication scenarios, such as device unlocking, payment, and app login.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';
```

## AuthResultInfo<sup>9+</sup>

Defines the authentication result.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name        | Type  | Mandatory| Description                |
| ------------ | ---------- | ---- | -------------------- |
| result        | number | Yes  | Authentication result.      |
| token        | Uint8Array | No  | Token that has passed the user identity authentication.|
| remainAttempts  | number     | No  | Number of remaining authentication attempts.|
| lockoutDuration | number     | No  | Lock duration of the authentication operation, in milliseconds.|

## TipInfo<sup>9+</sup>

Defines the authentication tip information.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name        | Type  | Mandatory| Description                |
| ------------ | ---------- | ---- | -------------------- |
| module        | number | Yes  | ID of the module that sends the tip information.      |
| tip        | number | Yes  | Tip to be given during the authentication process.      |

## EventInfo<sup>9+</sup>

Enumerates the authentication event information types.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Value   | Description                      |
| --------- | ----------------------- |
| [AuthResultInfo](#authresultinfo9)    | Authentication result. |
| [TipInfo](#tipinfo9)    | Authentication tip information.     |

## AuthEventKey<sup>9+</sup>

Defines the keyword of the authentication event type. It is used as a parameter of [on](#on9).

| Value      | Description                   |
| ---------- | ----------------------- |
| "result" | If the first parameter of [on](#on9) is **result**, the [callback](#callback9) returns the authentication result.|
| "tip"    | If the first parameter of [on](#on9) is **tip**, the [callback](#callback9) returns the authentication tip information.|

## AuthEvent<sup>9+</sup>

Provides an asynchronous callback to return the authentication event information.

### callback<sup>9+</sup>

callback(result : EventInfo) : void

Called to return the authentication result or authentication tip information.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type                      | Mandatory| Description                          |
| --------- | -------------------------- | ---- | ------------------------------ |
| result    | [EventInfo](#eventinfo9)     | Yes  | Authentication result or tip information. |

**Example**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userIAM_userAuth.UserAuthType.FACE;
let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;
// Obtain the authentication result through a callback.
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
// Obtain the authentication tip information through a callback.
try {
    let auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
    auth.on("tip", {
        callback : (result : userIAM_userAuth.TipInfo) => {
            switch (result.tip) {
                case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_BRIGHT:
                // Do something;
                case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_DARK:
                // Do something.
                default:
                // Do others.
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

Implements user authentication.

### on<sup>9+</sup>

on : (name : AuthEventKey, callback : AuthEvent) => void

Subscribes to the user authentication events of the specified type.

> **NOTE**<br>
> Use the [AuthInstance](#authinstance9) instance obtained to invoke this API to subscribe to events.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type                       | Mandatory| Description                      |
| --------- | -------------------------- | ---- | ------------------------- |
| name  | [AuthEventKey](#autheventkey9) | Yes  | Authentication event type. If the value is **result**, the callback returns the authentication result. If the value is **tip**, the callback returns the authentication tip information.|
| callback  | [AuthEvent](#authevent9)   | Yes  | Callback invoked to return the authentication result or tip information.|

For details about the error codes, see [User Authentication Error Codes](../errorcodes/errorcode-useriam.md).

**Error codes**

| ID| Error Message|
| -------- | ------- |
| 401 | Incorrect parameters. |
| 12500002 | General operation error. |

**Example**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userIAM_userAuth.UserAuthType.FACE;
let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;
try {
    let auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
    // Subscribe to the authentication result.
    auth.on("result", {
        callback: (result: userIAM_userAuth.AuthResultInfo) => {
            console.log("authV9 result " + result.result);
            console.log("authV9 token " + result.token);
            console.log("authV9 remainAttempts " + result.remainAttempts);
            console.log("authV9 lockoutDuration " + result.lockoutDuration);
        }
    });
    // Subscribe to authentication tip information.
    auth.on("tip", {
        callback : (result : userIAM_userAuth.TipInfo) => {
            switch (result.tip) {
                case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_BRIGHT:
                // Do something;
                case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_DARK:
                // Do something.
                default:
                // Do others.
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

Unsubscribes from the user authentication events of the specific type.

> **NOTE**<br>
> Use the [AuthInstance](#authinstance9) instance obtained to invoke this API to unsubscribe from events.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name   | Type                       | Mandatory| Description                      |
| --------- | -------------------------- | ---- | ------------------------- |
| name    | [AuthEventKey](#autheventkey9)      | Yes  | Type of the authentication event to unsubscribe from. If the value is **result**, the authentication result is unsubscribed from. If the value is **tip**, the authentication tip information is unsubscribed from.|

For details about the error codes, see [User Authentication Error Codes](../errorcodes/errorcode-useriam.md).

**Error codes**

| ID| Error Message|
| -------- | ------- |
| 401 | Incorrect parameters. |
| 12500002 | General operation error. |

**Example**

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
    // Subscribe to the authentication result.
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
// Unsubscribe from the authentication result.
try {
    auth.off("result");
    console.info("cancel subscribe authentication event success");
} catch (error) {
    console.info("cancel subscribe authentication event failed, error = " + error);
}
```

### start<sup>9+</sup>

start : () => void

Starts authentication.

> **NOTE**<br>
> Use the [AuthInstance](#authinstance9) instance obtained to invoke this API.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

For details about the error codes, see [User Authentication Error Codes](../errorcodes/errorcode-useriam.md).

**Error codes**

| ID| Error Message|
| -------- | ------- |
| 201 | Permission verification failed. |
| 401 | Incorrect parameters. |
| 12500001 | Authentication failed. |
| 12500002 | General operation error. |
| 12500003 | The operation is canceled. |
| 12500004 | The operation is time-out. |
| 12500005 | The authentication type is not supported. |
| 12500006 | The authentication trust level is not supported. |
| 12500007 | The authentication task is busy. |
| 12500009 | The authenticator is locked. |
| 12500010 | The type of credential has not been enrolled. |

**Example**

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

Cancels this authentication.

> **NOTE**<br>
> Use the [AuthInstance](#authinstance9) instance obtained to invoke this API. The [AuthInstance](#authinstance9) instance must be the one being authenticated.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

For details about the error codes, see [User Authentication Error Codes](../errorcodes/errorcode-useriam.md).

**Error codes**

| ID| Error Message|
| -------- | ------- |
| 201 | Permission verification failed. |
| 401 | Incorrect parameters. |
| 12500002 | General operation error. |

**Example**

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

Obtains an **AuthInstance** instance for user authentication.

> **NOTE**<br>
> An **AuthInstance** instance can be used for an authentication only once.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name        | Type                                    | Mandatory| Description                    |
| -------------- | ---------------------------------------- | ---- | ------------------------ |
| challenge      | Uint8Array                               | Yes  | Challenge value. The maximum length is 32 bytes. The value can be **null**.    |
| authType       | [UserAuthType](#userauthtype8)           | Yes  | Authentication type. Only **FACE** is supported.|
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8)       | Yes  | Authentication trust level.              |

**Return value**

| Type                                     | Description        |
| ----------------------------------------- | ------------ |
| [AuthInstance](#authinstance9) | **Authenticator** instance obtained.|

For details about the error codes, see [User Authentication Error Codes](../errorcodes/errorcode-useriam.md).

**Error codes**

| ID| Error Message|
| -------- | ------- |
| 401 | Incorrect parameters. |
| 12500002 | General operation error. |
| 12500005 | The authentication type is not supported. |
| 12500006 | The authentication trust level is not supported. |

**Example**

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

## userIAM_userAuth.getAvailableStatus<sup>9+</sup>

getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel): void

Checks whether the specified authentication capability is supported.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name        | Type                              | Mandatory| Description                      |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| authType       | [UserAuthType](#userauthtype8)     | Yes  | Authentication type. Only **FACE** is supported.|
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8) | Yes  | Authentication trust level.      |

For details about the error codes, see [User Authentication Error Codes](../errorcodes/errorcode-useriam.md).

**Error codes**

| ID| Error Message|
| -------- | ------- |
| 201 | Permission verification failed. |
| 401 | Incorrect parameters. |
| 12500002 | General operation error. |
| 12500005 | The authentication type is not supported. |
| 12500006 | The authentication trust level is not supported. |
| 12500010 | The type of credential has not been enrolled. |

**Example**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

try {
    userIAM_userAuth.getAvailableStatus(userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1);
    console.info("current auth trust level is supported");
} catch (error) {
    console.info("current auth trust level is not supported, error = " + error);
}
```

## UserAuthResultCode<sup>9+</sup>

Enumerates the authentication result codes.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name                   |   Value  | Description                |
| ----------------------- | ------ | -------------------- |
| SUCCESS                 | 12500000      | The authentication is successful.          |
| FAIL                    | 12500001      | The authentication failed.          |
| GENERAL_ERROR           | 12500002      | A general operation error occurred.      |
| CANCELED                | 12500003      | The authentication is canceled.          |
| TIMEOUT                 | 12500004      | The authentication timed out.          |
| TYPE_NOT_SUPPORT        | 12500005      | The authentication type is not supported.  |
| TRUST_LEVEL_NOT_SUPPORT | 12500006      | The authentication trust level is not supported.  |
| BUSY                    | 12500007      | Indicates the busy state.          |
| LOCKED                  | 12500009      | The authentication executor is locked.      |
| NOT_ENROLLED            | 12500010      | The user has not entered the authentication information.|

## UserAuth<sup>8+</sup>

Provides APIs to manage an **Authenticator** object.

### constructor<sup>(deprecated)</sup>

constructor()

A constructor used to create an authenticator instance.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getAuthInstance](#useriam_userauthgetauthinstance9).

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Return value**

| Type                  | Description                |
| ---------------------- | -------------------- |
| [UserAuth](#userauth8) | **Authenticator** instance obtained.|

**Example**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let auth = new userIAM_userAuth.UserAuth();
```

### getVersion<sup>(deprecated)</sup>

getVersion() : number

Obtains the version of this authenticator.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| number | Authenticator version obtained.|

**Example**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let auth = new userIAM_userAuth.UserAuth();
let version = auth.getVersion();
console.info("auth version = " + version);
```

### getAvailableStatus<sup>(deprecated)</sup>

getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel) : number

Checks whether the specified authentication capability is supported.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getAvailableStatus](#useriam_userauthgetavailablestatus9).

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name        | Type                              | Mandatory| Description                      |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| authType       | [UserAuthType](#userauthtype8)     | Yes  | Authentication type. Only **FACE** is supported.|
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8) | Yes  | Authentication trust level.      |

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| number | Query result. If the authentication capability is supported, **SUCCESS** is returned. Otherwise, a [ResultCode](#resultcodedeprecated) is returned.|

**Example**

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

Performs user authentication. This API uses a callback to return the result.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [start](#start9).

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name        | Type                                    | Mandatory| Description                    |
| -------------- | ---------------------------------------- | ---- | ------------------------ |
| challenge      | Uint8Array                               | Yes  | Challenge value, which can be null.    |
| authType       | [UserAuthType](#userauthtype8)           | Yes  | Authentication type. Only **FACE** is supported.|
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8)       | Yes  | Authentication trust level.            |
| callback       | [IUserAuthCallback](#iuserauthcallbackdeprecated) | Yes  | Callback used to return the result.       |

**Return value**

| Type      | Description                                                        |
| ---------- | ------------------------------------------------------------ |
| Uint8Array | Context ID, which is used as the input parameter of [cancelAuth](#cancelauthdeprecated).|

**Example**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let auth = new userIAM_userAuth.UserAuth();
auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
    onResult: (result, extraInfo) => {
        try {
            console.info("auth onResult result = " + result);
            console.info("auth onResult extraInfo = " + JSON.stringify(extraInfo));
            if (result == userIAM_userAuth.ResultCode.SUCCESS) {
                // Add the logic to be executed when the authentication is successful.
            } else {
                // Add the logic to be executed when the authentication fails.
            }
        } catch (e) {
            console.info("auth onResult error = " + e);
        }
    }
});
```

### cancelAuth<sup>(deprecated)</sup>

cancelAuth(contextID : Uint8Array) : number

Cancels an authentication based on the context ID.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [cancel](#cancel9).

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type      | Mandatory| Description                                      |
| --------- | ---------- | ---- | ------------------------------------------ |
| contextID | Uint8Array | Yes  | Context ID, which is obtained by [auth](#authdeprecated).|

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| number | Returns **SUCCESS** if the cancellation is successful. Returns a [ResultCode](#resultcodedeprecated) otherwise.|

**Example**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

// contextId can be obtained by auth(). In this example, it is defined here.
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

Provides callbacks to return the authentication result.

> **NOTE**<br>
> This object is supported since API version 8 and deprecated since API version 9. You are advised to use [AuthEvent](#authevent9).

### onResult<sup>(deprecated)</sup>

onResult: (result : number, extraInfo : AuthResult) => void

Called to return the authentication result.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [callback](#callback9).

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type                      | Mandatory| Description       |
| --------- | -------------------------- | ---- | ------------------------------------------------ |
| result    | number           | Yes  | Authentication result. For details, see [ResultCode](#resultcodedeprecated).|
| extraInfo | [AuthResult](#authresultdeprecated) | Yes  | Extended information, which varies depending on the authentication result.<br>If the authentication is successful, the user authentication token will be returned in **extraInfo**.<br>If the authentication fails, the remaining number of authentication times will be returned in **extraInfo**.<br>If the authentication executor is locked, the freeze time will be returned in **extraInfo**.|

**Example**

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let auth = new userIAM_userAuth.UserAuth();
auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
    onResult: (result, extraInfo) => {
        try {
            console.info("auth onResult result = " + result);
            console.info("auth onResult extraInfo = " + JSON.stringify(extraInfo));
            if (result == userIAM_userAuth.ResultCode.SUCCESS) {
                // Add the logic to be executed when the authentication is successful.
            }  else {
                // Add the logic to be executed when the authentication fails.
            }
        } catch (e) {
            console.info("auth onResult error = " + e);
        }
    }
});
```

### onAcquireInfo<sup>(deprecated)</sup>

onAcquireInfo ?: (module : number, acquire : number, extraInfo : any) => void

Called to acquire authentication tip information. This API is optional.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [callback](#callback9).

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type  | Mandatory| Description                          |
| --------- | ------ | ---- | ------------------------------ |
| module    | number | Yes  | ID of the module that sends the tip information.            |
| acquire   | number | Yes  | Authentication tip information.|
| extraInfo | any    | Yes  | Reserved field.                    |

**Example**

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

Represents the authentication result object.

> **NOTE**<br>
> This object is supported since API version 8 and deprecated since API version 9. You are advised to use [AuthResultInfo](#authresultinfo9).

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name        | Type  | Mandatory| Description                |
| ------------ | ---------- | ---- | -------------------|
| token        | Uint8Array | No  | Authentication token information.|
| remainTimes  | number     | No  | Number of remaining authentication operations.|
| freezingTime | number     | No  | Time for which the authentication operation is frozen.|

## ResultCode<sup>(deprecated)</sup>

Enumerates the authentication result codes.

> **NOTE**<br>
> This object is deprecated since API version 9. You are advised to use [UserAuthResultCode](#userauthresultcode9).

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name                   | Value| Description                |
| ----------------------- | ------ | -------------------- |
| SUCCESS                 | 0      | The operation is successful.          |
| FAIL                    | 1      | The authentication failed.          |
| GENERAL_ERROR           | 2      | A general operation error occurred.      |
| CANCELED                | 3      | The authentication is canceled.          |
| TIMEOUT                 | 4      | The authentication timed out.          |
| TYPE_NOT_SUPPORT        | 5      | The authentication type is not supported.  |
| TRUST_LEVEL_NOT_SUPPORT | 6      | The authentication trust level is not supported.  |
| BUSY                    | 7      | Indicates the busy state.          |
| INVALID_PARAMETERS      | 8      | Invalid parameters are detected.          |
| LOCKED                  | 9      | The authentication executor is locked.      |
| NOT_ENROLLED            | 10     | The user has not entered the authentication information.|

## FaceTips<sup>8+</sup>

Enumerates the tip codes used during the facial authentication process.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name                         |   Value  |    Description                            |
| ----------------------------- | ------ | ------------------------------------ |
| FACE_AUTH_TIP_TOO_BRIGHT      | 1      | The obtained facial image is too bright due to high illumination.          |
| FACE_AUTH_TIP_TOO_DARK        | 2      | The obtained facial image is too dark due to low illumination.          |
| FACE_AUTH_TIP_TOO_CLOSE       | 3      | The face is too close to the device.                  |
| FACE_AUTH_TIP_TOO_FAR         | 4      | The face is too far away from the device.                  |
| FACE_AUTH_TIP_TOO_HIGH        | 5      | Only the upper part of the face is captured because the device is angled too high.        |
| FACE_AUTH_TIP_TOO_LOW         | 6      | Only the lower part of the face is captured because the device is angled too low.        |
| FACE_AUTH_TIP_TOO_RIGHT       | 7      | Only the right part of the face is captured because the device is deviated to the right.      |
| FACE_AUTH_TIP_TOO_LEFT        | 8      | Only the left part of the face is captured because the device is deviated to the left.      |
| FACE_AUTH_TIP_TOO_MUCH_MOTION | 9      | The face moves too fast during facial information collection.|
| FACE_AUTH_TIP_POOR_GAZE       | 10     | The face is not facing the camera.                    |
| FACE_AUTH_TIP_NOT_DETECTED    | 11     | No face is detected.                |


## FingerprintTips<sup>8+</sup>

Enumerates the tip codes used during the fingerprint authentication process.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name                             |   Value  | Description                                              |
| --------------------------------- | ------ | -------------------------------------------------- |
| FINGERPRINT_AUTH_TIP_GOOD         | 0      | The obtained fingerprint image is in good condition.                              |
| FINGERPRINT_AUTH_TIP_DIRTY        | 1      | Large fingerprint image noise is detected due to suspicious or detected dirt on the sensor.|
| FINGERPRINT_AUTH_TIP_INSUFFICIENT | 2      | The noise of the fingerprint image is too large to be processed.    |
| FINGERPRINT_AUTH_TIP_PARTIAL      | 3      | Incomplete fingerprint image is detected.                            |
| FINGERPRINT_AUTH_TIP_TOO_FAST     | 4      | The fingerprint image is incomplete due to fast movement.                        |
| FINGERPRINT_AUTH_TIP_TOO_SLOW     | 5      | Failed to obtain the fingerprint image because the finger seldom moves.                      |


## UserAuthType<sup>8+</sup>

Enumerates the identity authentication types.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name       |   Value  | Description      |
| ----------- | ------ | ---------- |
| FACE        | 2      | Facial authentication.|
| FINGERPRINT | 4      | Fingerprint authentication.|

## AuthTrustLevel<sup>8+</sup>

Enumerates the trust levels of the authentication result.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name|   Value  | Description                     |
| ---- | ------ | ------------------------- |
| ATL1 | 10000  | Trust level 1.|
| ATL2 | 20000  | Trust level 2.|
| ATL3 | 30000  | Trust level 3.|
| ATL4 | 40000  | Trust level 4.|

## userIAM_userAuth.getAuthenticator<sup>(deprecated)</sup>

getAuthenticator(): Authenticator

Obtains an **Authenticator** instance for user authentication.

> **NOTE**<br>
> This API is deprecated since API version 8. You are advised to use [constructor](#constructordeprecated).

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Return value**

| Type                                     | Description        |
| ----------------------------------------- | ------------ |
| [Authenticator](#authenticatordeprecated) | **Authenticator** instance obtained.|

**Example**
  ```js
  let authenticator = userIAM_userAuth.getAuthenticator();
  ```

## Authenticator<sup>(deprecated)</sup>

Defines the **Authenticator** object.

> **NOTE**<br>
> This object is deprecated since API version 8. You are advised to use [UserAuth](#userauth8).

### execute<sup>(deprecated)</sup>

execute(type: AuthType, level: SecureLevel, callback: AsyncCallback&lt;number&gt;): void

Performs user authentication. This API uses asynchronous callback to return the result.

> **NOTE**<br>
> This API is deprecated since API version 8. You are advised to use [auth](#authdeprecated).

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                     |
| -------- | --------------------------- | ---- | -------------------------- |
| type     | AuthType                      | Yes  | Authentication type. Only **FACE_ONLY** is supported.<br>**ALL** is reserved and not supported by the current version.|
| level    | SecureLevel  | Yes  | Security level of the authentication. It can be **S1** (lowest), **S2**, **S3**, or **S4** (highest).<br>Devices capable of 3D facial recognition support S3 and lower-level authentication.<br>Devices capable of 2D facial recognition support S2 and lower-level authentication.|
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result.   |

Parameters returned in callback

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| number | Authentication result. For details, see [AuthenticationResult](#authenticationresultdeprecated).|

**Example**

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

Performs user authentication. This API uses a promise to return the result.

> **NOTE**<br>
> This API is deprecated since API version 8. You are advised to use [auth](#authdeprecated).

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | AuthType | Yes  | Authentication type. Only **FACE_ONLY** is supported.<br>**ALL** is reserved and not supported by the current version.|
| level  | SecureLevel | Yes  | Security level of the authentication. It can be **S1** (lowest), **S2**, **S3**, or **S4** (highest).<br>Devices capable of 3D facial recognition support S3 and lower-level authentication.<br>Devices capable of 2D facial recognition support S2 and lower-level authentication.|

**Return value**

| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the authentication result, which is a number. For details, see [AuthenticationResult](#authenticationresultdeprecated).|

**Example**

```js
let authenticator = userIAM_userAuth.getAuthenticator();
authenticator.execute("FACE_ONLY", "S2").then((code)=>{
    console.info("auth success");
}).catch((error)=>{
    console.error("auth fail, code = " + error);
});
```

## AuthenticationResult<sup>(deprecated)</sup>

Enumerates the authentication results.

> **NOTE**<br>
> This object is discarded since API version 8. You are advised to use [ResultCode](#resultcodedeprecated).

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name              |   Value  | Description                      |
| ------------------ | ------ | -------------------------- |
| NO_SUPPORT         | -1     | The device does not support the current authentication mode.|
| SUCCESS            | 0      | The authentication is successful.                |
| COMPARE_FAILURE    | 1      | The feature comparison failed.                |
| CANCELED           | 2      | The authentication was canceled by the user.            |
| TIMEOUT            | 3      | The authentication has timed out.                |
| CAMERA_FAIL        | 4      | The camera failed to start.            |
| BUSY               | 5      | The authentication service is not available. Try again later.  |
| INVALID_PARAMETERS | 6      | The authentication parameters are invalid.            |
| LOCKED             | 7      | The user account is locked because the number of authentication failures has reached the threshold.|
| NOT_ENROLLED       | 8      | No authentication credential is registered.          |
| GENERAL_ERROR      | 100    | Other errors.                |
