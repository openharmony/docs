# User Authentication

The **userIAM.userAuth** module provides user authentication capabilities in identity authentication scenarios, such as device unlocking, payment, and app login.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';
```

## Sample Code

```js
// API version 9
import userIAM_userAuth from '@ohos.userIAM.userAuth';

export default {
    getVersion() {
        try {
            let version = userIAM_userAuth.getVersion();
            console.info("auth version = " + version);
        } catch (error) {
            console.info("get version failed, error = " + error);
        }
    },

    start() {
        console.info("start auth");
        let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
        let authType = userIAM_userAuth.UserAuthType.FACE;
        let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;
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
            // If tips are needed
            auth.on("tip", {
            callback : (result : userIAM_userAuth.TipInfo) => {
                switch (result.tip) {
                    case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_BRIGHT:
                    // Do something;
                    case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_DARK:
                    // Do something;
                    // ...
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
    },

    getAvailableStatus() {
        console.info("start check auth support");
        try {
            userIAM_userAuth.getAvailableStatus(userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1);
            console.info("current auth trust level is supported");
        } catch (error) {
            console.info("current auth trust level is not supported, error = " + error);
        }
    },

    cancel() {
        console.info("start cancel auth");
        let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
        let authType = userIAM_userAuth.UserAuthType.FACE;
        let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;

        try {
            let auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
            auth.start();
            auth.cancel();
            console.info("cancel auth success");
        } catch (error) {
            console.info("cancel auth failed, error = " + error);
        }
    }
}
```

```js
// API version 8
import userIAM_userAuth from '@ohos.userIAM.userAuth';
let auth = new userIAM_userAuth.UserAuth();

export default {
    getVersion() {
        console.info("start get version");
        let version = auth.getVersion();
        console.info("auth version = " + version);
    },

    startAuth() {
        console.info("start auth");
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
            },

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
    },

    checkAuthSupport() {
        console.info("start check auth support");
        let checkCode = this.auth.getAvailableStatus(userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1);
        if (checkCode == userIAM_userAuth.ResultCode.SUCCESS) {
            console.info("check auth support success");
            // Add the logic to be executed if the specified authentication type is supported.
        } else {
            console.error("check auth support fail, code = " + checkCode);
            // Add the logic to be executed if the specified authentication type is not supported.
        }
    },

    cancelAuth() {
        console.info("start cancel auth");
        // Obtain contextId using auth().
        let contextId = auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
            onResult: (result, extraInfo) => {
                console.info("auth onResult result = " + result);
            },

            onAcquireInfo: (module, acquire, extraInfo) => {
                console.info("auth onAcquireInfo module = " + module);
            }
        });
        let cancelCode = this.auth.cancel(contextId);
        if (cancelCode == userIAM_userAuth.ResultCode.SUCCESS) {
            console.info("cancel auth success");
        } else {
            console.error("cancel auth fail");
        }
    }
}
```

```js
// API version 6
import userIAM_userAuth from '@ohos.userIAM.userAuth';

export default {
    startAuth() {
        console.info("start auth");
        let auth = userIAM_userAuth.getAuthenticator();
        auth.execute("FACE_ONLY", "S2").then((code)=>{
            console.info("auth success");
            // Add the logic to be executed when the authentication is successful.
        }).catch((code)=>{
            console.error("auth fail, code = " + code);
            // Add the logic to be executed when the authentication fails.
        });
    }
}
```

## EventInfo<sup>9+</sup>

Defines the event information used in authentication.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Type   | Description                      |
| --------- | ----------------------- |
| [AuthResultInfo](#authresultinfo9)    | Authentication result information. |
| [TipInfo](#tipinfo9)    | Authentication tip information.     |

## AuthEvent<sup>9+</sup>

Provides callbacks to return authentication events.

### callback<sup>9+</sup>

callback: (result : EventInfo) => void

Called to return the authentication result or authentication tips.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type                      | Mandatory| Description                                                        |
| --------- | -------------------------- | ---- | -------------------------------------------------------- |
| result    | [EventInfo](#eventinfo9)                     | Yes  | Authentication result or tip information.                  |

**Example**

  ```js
    import userIAM_userAuth from '@ohos.userIAM.userAuth';

    let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
    let authType = userIAM_userAuth.UserAuthType.FACE;
    let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;
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
  ```

## AuthResultInfo<sup>9+</sup>

Defines the authentication result information.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name        | Type  | Mandatory| Description                |
| ------------ | ---------- | ---- | -------------------- |
| result        | number | Yes  | Authentication result.      |
| token        | Uint8Array | No  | Token that has passed the user identity authentication.|
| remainAttempts  | number     | No  | Number of remaining authentication times allowed.|
| lockoutDuration | number     | No  | Time for which the authentication operation is frozen.|

## TipInfo<sup>9+</sup>

Defines the authentication tip information.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name        | Type  | Mandatory| Description                |
| ------------ | ---------- | ---- | -------------------- |
| module        | number | No  | Authentication module.      |
| tip        | number | No  | Tip to be given during the authentication process.      |

## AuthEventKey<sup>9+</sup>

Defines the keyword of an authentication event.

| Value      | Description                   |
| ---------- | ----------------------- |
| "result" | Indicates authentication result.|
| "tip"    | If **AuthEventKey** is **result**, the callback returns the authentication tip information.|

## AuthInstance<sup>9+</sup>

Implements user authentication.

### on<sup>9+</sup>

on(name : AuthEventKey, callback : AuthEvent) : void

Enables authentication event listening.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type                       | Mandatory| Description                      |
| --------- | -------------------------- | ---- | ------------------------- |
| name    | AuthEventKey                 | Yes  | Keyword of the authentication event to listen for.         |
| callback    | AuthEvent                | Yes  | Callback invoked to return the authentication event.         |

**Example**

  ```js
    import userIAM_userAuth from '@ohos.userIAM.userAuth';

    let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
    let authType = userIAM_userAuth.UserAuthType.FACE;
    let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;
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
        // If tips are needed
        auth.on("tip", {
        callback : (result : userIAM_userAuth.TipInfo) => {
            switch (result.tip) {
                case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_BRIGHT:
                // Do something;
                case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_DARK:
                // Do something;
                // ...
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

off(name : AuthEventKey) : void

Disables authentication event listening.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name   | Type                       | Mandatory| Description                      |
| --------- | -------------------------- | ---- | ------------------------- |
| name    | AuthEventKey                 | Yes  | Keyword of the authentication event.         |

**Example**

  ```js
    import userIAM_userAuth from '@ohos.userIAM.userAuth';

    let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
    let authType = userIAM_userAuth.UserAuthType.FACE;
    let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;

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
        console.log("turn on authentication event listening success");
    } catch (error) {
        console.log("turn off authentication event listening failed " + error);
        // do error
    }

    try {
        let auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
        auth.off("result");
        console.info("turn off authentication event listening success");
    } catch (error) {
        console.info("turn off authentication event listening failed, error = " + error);
    }
  ```

### start<sup>9+</sup>

start() : void

Starts authentication.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

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

cancel(): void

Cancels the authentication.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Example**

  ```js
    import userIAM_userAuth from '@ohos.userIAM.userAuth';

    let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
    let authType = userIAM_userAuth.UserAuthType.FACE;
    let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;

    try {
        let auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
        auth.start();
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
> Each **AuthInstance** can be used to initiate an authentication only once.

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
| [AuthInstance](#authinstance9) | **Authenticator** object obtained.|

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

## userIAM_userAuth.getVersion<sup>9+</sup>

getVersion(): number

Obtains the version of this authenticator.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| number | Authenticator version obtained.|

**Example**

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

Checks whether the authentication capability of the specified trust level is available.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name        | Type                              | Mandatory| Description                      |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| authType       | [UserAuthType](#userauthtype8)     | Yes  | Authentication type. Only **FACE** is supported.|
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8) | Yes  | Trust level of the authentication result.      |

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

  ## ResultCodeV9<sup>9+</sup>

Enumerates the operation results.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name                   | Default Value| Description                |
| ----------------------- | ------ | -------------------- |
| SUCCESS                 | 12500000      | The operation is successful.          |
| FAIL                    | 12500001      | The operation failed.          |
| GENERAL_ERROR           | 12500002      | A common operation error occurred.      |
| CANCELED                | 12500003      | The operation is canceled.          |
| TIMEOUT                 | 12500004      | The operation timed out.          |
| TYPE_NOT_SUPPORT        | 12500005      | The authentication type is not supported.  |
| TRUST_LEVEL_NOT_SUPPORT | 12500006      | The authentication trust level is not supported.  |
| BUSY                    | 12500007      | Indicates the busy state.          |
| INVALID_PARAMETERS      | 12500008      | Invalid parameters are detected.          |
| LOCKED                  | 12500009      | The authentication executor is locked.      |
| NOT_ENROLLED            | 12500010      | The user has not entered the authentication information.|

## UserAuth<sup>8+</sup>

Provides methods to manage an **Authenticator** object.

### constructor<sup>(deprecated)</sup>

constructor()

> **NOTE**
>
>This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getAuthInstance](#useriam_userauthgetauthinstance9).

A constructor used to create an **authenticator** object.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Return value**

| Type                  | Description                |
| ---------------------- | -------------------- |
| [UserAuth](#userauth8) | **Authenticator** object obtained.|

**Example**

  ```js
  import userIAM_userAuth from '@ohos.userIAM.userAuth';

  let auth = new userIAM_userAuth.UserAuth();
  ```

### getVersion<sup>(deprecated)</sup>

getVersion() : number

> **NOTE**
> 
>This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getVersion](#useriam_userauthgetversion9).

Obtains the authentication executor version.

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

> **NOTE**
> 
>This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getAvailableStatus](#useriam_userauthgetavailablestatus9).

Obtains the available status of the specified authentication trust level.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name        | Type                              | Mandatory| Description                      |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| authType       | [UserAuthType](#userauthtype8)     | Yes  | Authentication type. Only **FACE** is supported.|
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8) | Yes  | Trust level of the authentication result.      |

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| number | Available status obtained. For details, see [ResultCode](#resultcodedeprecated).|

**Example**

  ```js
  import userIAM_userAuth from '@ohos.userIAM.userAuth';

  let auth = new userIAM_userAuth.UserAuth();
  let checkCode = auth.getAvailableStatus(userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1);
  if (checkCode == userIAM_userAuth.ResultCode.SUCCESS) {
      console.info("check auth support success");
      // Add the logic to be executed if the specified authentication type is supported.
  } else {
      console.error("check auth support fail, code = " + checkCode);
      // Add the logic to be executed if the specified authentication type is not supported.
  }
  ```

### auth<sup>(deprecated)</sup>

auth(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array

> **NOTE**
> 
>This API is supported since API version 8 and deprecated since API version 9. You are advised to use [start](#start9).

Performs user authentication. This API uses a callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name        | Type                                    | Mandatory| Description                    |
| -------------- | ---------------------------------------- | ---- | ------------------------ |
| challenge      | Uint8Array                               | Yes  | Challenge value, which can be null.    |
| authType       | [UserAuthType](#userauthtype8)           | Yes  | Authentication type. Only **FACE** is supported.|
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8)       | Yes  | Trust level.              |
| callback       | [IUserAuthCallback](#iuserauthcallbackdeprecated) | Yes  | Callback used to return the result.              |

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

> **NOTE**
> 
>This API is supported since API version 8 and deprecated since API version 9. You are advised to use [cancel](#cancel9).

Cancels an authentication.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type      | Mandatory| Description                                      |
| --------- | ---------- | ---- | ------------------------------------------ |
| contextID | Uint8Array | Yes  | Context ID, which is obtained by using [auth](#authdeprecated).|

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| number | Whether the authentication is canceled.|

**Example**

  ```js
  import userIAM_userAuth from '@ohos.userIAM.userAuth';

  // contextId can be obtained using auth(). In this example, it is defined here.
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

> **NOTE**
> 
>This object is supported since API version 8 and deprecated since API version 9. You are advised to use [AuthEvent](#authevent9).

Defines the object of the result returned by the callback during authentication.

### onResult<sup>(deprecated)</sup>

onResult: (result : number, extraInfo : AuthResult) => void

> **NOTE**
> 
>This API is supported since API version 8 and deprecated since API version 9. You are advised to use [callback](#callback9).

Obtains the authentication result.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type                      | Mandatory| Description                                                        |
| --------- | -------------------------- | ---- | ------------------------------------------------------------ |
| result    | number                     | Yes  | Authentication result. For details, see [ResultCode](#resultcodedeprecated).                  |
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
      },

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

### onAcquireInfo<sup>(deprecated)</sup>

onAcquireInfo ?: (module : number, acquire : number, extraInfo : any) => void

> **NOTE**
> 
>This API is supported since API version 8 and deprecated since API version 9. You are advised to use [callback](#callback9).

Obtains the tip code information during authentication. This function is optional.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type  | Mandatory| Description                          |
| --------- | ------ | ---- | ------------------------------ |
| module    | number | Yes  | Type of the authentication executor.            |
| acquire   | number | Yes  | Interaction information of the authentication executor during the authentication process.|
| extraInfo | any    | Yes  | Reserved field.                    |

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
      },

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

> **NOTE**
> 
>This object is supported since API version 8 and deprecated since API version 9. You are advised to use [AuthResultInfo](#authresultinfo9).

Represents the authentication result object.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name        | Type  | Mandatory| Description                |
| ------------ | ---------- | ---- | -------------------- |
| token        | Uint8Array | No  | Identity authentication token.      |
| remainTimes  | number     | No  | Number of remaining authentication operations.|
| freezingTime | number     | No  | Time for which the authentication operation is frozen.|

## ResultCode<sup>(deprecated)</sup>

> **NOTE**<br>
> This object is deprecated since API version 9. You are advised to use [ResultCodeV9](#resultcodev99).

Enumerates the operation results.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name                   | Default Value| Description                |
| ----------------------- | ------ | -------------------- |
| SUCCESS                 | 0      | The operation is successful.          |
| FAIL                    | 1      | The operation failed.          |
| GENERAL_ERROR           | 2      | A common operation error occurred.      |
| CANCELED                | 3      | The operation is canceled.          |
| TIMEOUT                 | 4      | The operation timed out.          |
| TYPE_NOT_SUPPORT        | 5      | The authentication type is not supported.  |
| TRUST_LEVEL_NOT_SUPPORT | 6      | The authentication trust level is not supported.  |
| BUSY                    | 7      | Indicates the busy state.          |
| LOCKED                  | 9      | The authentication executor is locked.      |
| NOT_ENROLLED            | 10     | The user has not entered the authentication information.|


## FaceTips<sup>8+</sup>

Enumerates the tip codes used during the facial authentication process.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name                         | Default Value| Description                                |
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

| Name                             | Default Value| Description                                              |
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

| Name       | Default Value| Description      |
| ----------- | ------ | ---------- |
| FACE        | 2      | Facial authentication.|
| FINGERPRINT | 4      | Fingerprint authentication.|

## AuthTrustLevel<sup>8+</sup>

Enumerates the trust levels of the authentication result.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name| Default Value| Description                     |
| ---- | ------ | ------------------------- |
| ATL1 | 10000  | Trust level 1.|
| ATL2 | 20000  | Trust level 2.|
| ATL3 | 30000  | Trust level 3.|
| ATL4 | 40000  | Trust level 4.|

## userIAM_userAuth.getAuthenticator<sup>(deprecated)</sup>

getAuthenticator(): Authenticator

> **NOTE**<br>
> This API is deprecated since API version 8. You are advised to use [constructor](#constructordeprecated).

Obtains an **Authenticator** object for user authentication.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Return value**

| Type                                     | Description        |
| ----------------------------------------- | ------------ |
| [Authenticator](#authenticatordeprecated) | **Authenticator** object obtained.|

**Example**
  ```js
  let authenticator = userIAM_userAuth.getAuthenticator();
  ```

## Authenticator<sup>(deprecated)</sup>

> **NOTE**<br>
> This object is deprecated since API version 8. You are advised to use [UserAuth](#userauth8).

Provides methods to manage an **Authenticator** object.


### execute<sup>(deprecated)</sup>

execute(type: AuthType, level: SecureLevel, callback: AsyncCallback&lt;number&gt;): void

> **NOTE**<br>
> This API is deprecated since API version 8. You are advised to use [auth](#authdeprecated).

Performs user authentication. This API uses asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| type     | AuthType                      | Yes  | Authentication type. Only **FACE_ONLY** is supported.<br>**ALL** is reserved and not supported by the current version.|
| level    | SecureLevel                      | Yes  | Security level of the authentication. It can be **S1** (lowest), **S2**, **S3**, or **S4** (highest).<br>Devices capable of 3D facial recognition support S3 and lower-level authentication.<br>Devices capable of 2D facial recognition support S2 and lower-level authentication.|
| callback | AsyncCallback&lt;number&gt; | No  | Callback used to return the result.                                                  |

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

execute(type:AuthType, level:SecureLevel): Promise&lt;number&gt;

> **NOTE**<br>
> This API is deprecated since API version 8. You are advised to use [auth](#authdeprecated).

Performs user authentication. This API uses a promise to return the result.

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

> **NOTE**<br>
> This object is discarded since API version 8. You are advised to use [ResultCode](#resultcodedeprecated).

Enumerates the authentication results.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name              | Default Value| Description                      |
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
