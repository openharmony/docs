# User Authentication

> **NOTE**<br>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';
```

## Example

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

```js
// API version 8
import userIAM_userAuth from '@ohos.userIAM.userAuth';
let auth = new userIAM_userAuth.UserAuth();

export default {
    getVersion() {
        console.info("start get version");
        let version = this.auth.getVersion();
        console.info("auth version = " + version);
    },

    startAuth() {
        console.info("start auth");
        this.auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
            onResult: (result, extraInfo) => {
                try {
                    console.info("auth onResult result = " + result);
                    console.info("auth onResult extraInfo = " + JSON.stringify(extraInfo));
                    if (result == 'SUCCESS') {
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
        if (cancelCode == userIAM_userAuth.Result.SUCCESS) {
            console.info("cancel auth success");
        } else {
            console.error("cancel auth fail");
        }
    }
}
```

## userIAM_userAuth.getAuthenticator<sup>(deprecated)</sup>

getAuthenticator(): Authenticator

> **NOTE**<br/>
> This API is not longer maintained since API version 8. You are advised to use [constructor](#constructor8).

Obtains an **Authenticator** object for user authentication.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Return value**
| Type                                     | Description        |
| ----------------------------------------- | ------------ |
| [Authenticator](#authenticatordeprecated) | **Authenticator** object obtained. |

**Example**
  ```js
  let authenticator = userIAM_userAuth.getAuthenticator();
  ```

## Authenticator<sup>(deprecated)</sup>

> **NOTE**<br/>
> This object is not longer maintained since API version 8. You are advised to use [UserAuth](#userauth8).

Provides methods to manage an **Authenticator** object.


### execute<sup>(deprecated)</sup>

execute(type: string, level: string, callback: AsyncCallback&lt;number&gt;): void

> **NOTE**<br/>
> This API is not longer maintained since API version 8. You are advised to use [auth](#auth8).

Performs user authentication. This API uses asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                      | Yes  | Authentication type. Only **FACE_ONLY** is supported.<br>**ALL** is reserved and not supported by the current version. |
| level    | string                      | Yes  | Security level of the authentication. It can be S1 (lowest), S2, S3, or S4 (highest).<br>Devices capable of 3D facial recognition support S3 and lower-level authentication.<br>Devices capable of 2D facial recognition support S2 and lower-level authentication. |
| callback | AsyncCallback&lt;number&gt; | No  | Callback used to return the result.                                                  |

 Parameters returned in callback

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| number | Authentication result. For details, see [AuthenticationResult](#authenticationresultdeprecated). |

**Example**
  ```js
  authenticator.execute("FACE_ONLY", "S2", (code)=>{
      if (code == userIAM_userAuth.AuthenticationResult.SUCCESS) {
          console.info("auth success");
          return;
      }
      console.error("auth fail, code = " + code);
  })
  ```


### execute<sup>(deprecated)</sup>

execute(type:string, level:string): Promise&lt;number&gt;

> **NOTE**<br/>
> This API is not longer maintained since API version 8. You are advised to use [auth](#auth8).

Performs user authentication. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**
| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Authentication type. Only **FACE_ONLY** is supported.<br>**ALL** is reserved and not supported by the current version. |
| level  | string | Yes  | Security level of the authentication. It can be S1 (lowest), S2, S3, or S4 (highest).<br>Devices capable of 3D facial recognition support S3 and lower-level authentication.<br>Devices capable of 2D facial recognition support S2 and lower-level authentication. |

**Return value**
| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the authentication result, which is a number. For details, see [AuthenticationResult](#authenticationresultdeprecated). |

**Example**

```js
let authenticator = userIAM_userAuth.getAuthenticator();
authenticator.execute("FACE_ONLY", "S2").then((code)=>{
    console.info("auth success");
}).catch((code)=>{
    console.error("auth fail, code = " + code);
});
```

## AuthenticationResult<sup>(deprecated)</sup>

> **NOTE**<br/>
> This parameter is not longer maintained since API version 8. You are advised to use [ResultCode](#resultcode8).

Enumerates the authentication results.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name              | Default Value| Description                      |
| ------------------ | ------ | -------------------------- |
| NO_SUPPORT         | -1     | The device does not support the current authentication mode. |
| SUCCESS            | 0      | The authentication is successful.                |
| COMPARE_FAILURE    | 1      | The feature comparison failed.                |
| CANCELED           | 2      | The authentication was canceled by the user.            |
| TIMEOUT            | 3      | The authentication has timed out.                |
| CAMERA_FAIL        | 4      | The camera failed to start.            |
| BUSY               | 5      | The authentication service is not available. Try again later.  |
| INVALID_PARAMETERS | 6      | The authentication parameters are invalid.            |
| LOCKED             | 7      | The user account is locked because the number of authentication failures has reached the threshold. |
| NOT_ENROLLED       | 8      | No authentication credential is registered.          |
| GENERAL_ERROR      | 100    | Other errors.                |

## UserAuth<sup>8+</sup>

Provides methods to manage an **Authenticator** object.

### constructor<sup>8+</sup>

constructor()

A constructor used to create an **authenticator** object.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Return value**

| Type                  | Description                |
| ---------------------- | -------------------- |
| [UserAuth](#userauth8) | **Authenticator** object obtained. |

**Example**

  ```js
  import userIAM_userAuth from '@ohos.userIAM.userAuth';

  let auth = new userIAM_userAuth.UserAuth();
  ```

### getVersion<sup>8+</sup>

getVersion() : number

Obtains the authentication executor version.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| number | Authentication executor version obtained. |

**Example**

  ```js
  import userIAM_userAuth from '@ohos.userIAM.userAuth';

  let auth = new userIAM_userAuth.UserAuth();
  let version = auth.getVersion();
  console.info("auth version = " + version);
  ```

### getAvailableStatus<sup>8+</sup>

getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel) : number

Checks whether the authentication capability of the specified trust level is available.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name        | Type                              | Mandatory| Description                      |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| authType       | [UserAuthType](#userauthtype8)     | Yes  | Authentication type. Only **FACE** is supported. |
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8) | Yes  | Trust level of the authentication result.      |

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| number | Whether the authentication capability of the specified trust level is available. For details, see [ResultCode](#resultcode8). |

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

### auth<sup>8+</sup>

auth(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array

Performs user authentication. This API uses a callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name        | Type                                    | Mandatory| Description                    |
| -------------- | ---------------------------------------- | ---- | ------------------------ |
| challenge      | Uint8Array                               | Yes  | Challenge value, which can be null.    |
| authType       | [UserAuthType](#userauthtype8)           | Yes  | Authentication type. Only **FACE** is supported. |
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8)       | Yes  | Trust level.              |
| callback       | [IUserAuthCallback](#iuserauthcallback8) | Yes  | Callback used to return the result.              |

**Return value**

| Type      | Description                                                        |
| ---------- | ------------------------------------------------------------ |
| Uint8Array | ContextId, which is used as the input parameter of [cancelAuth](#cancelauth8). |

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

### cancelAuth<sup>8+</sup>

cancelAuth(contextID : Uint8Array) : number

Cancels an authentication.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type      | Mandatory| Description                                      |
| --------- | ---------- | ---- | ------------------------------------------ |
| contextID | Uint8Array | Yes  | Context ID, which is obtained using [auth](#auth8). |

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| number | Whether the authentication is canceled. |

**Example**

  ```js
  import userIAM_userAuth from '@ohos.userIAM.userAuth';

  // contextId can be obtained using auth(). In this example, it is defined here.
  let contextId = new Uint8Array([0, 1, 2, 3, 4, 5, 6, 7]);
  let cancelCode = auth.cancel(contextId);
  if (cancelCode == userIAM_userAuth.ResultCode.SUCCESS) {
      console.info("cancel auth success");
  } else {
      console.error("cancel auth fail");
  }
  ```

## IUserAuthCallback<sup>8+</sup>

Defines the object of the result returned by the callback during authentication.

### onResult<sup>8+</sup>

onResult: (result : number, extraInfo : AuthResult) => void

Obtains the authentication result.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type                      | Mandatory| Description                                                        |
| --------- | -------------------------- | ---- | ------------------------------------------------------------ |
| result    | number                     | Yes  | Authentication result obtained. For details, see [ResultCode](#resultcode8).                  |
| extraInfo | [AuthResult](#authresult8) | Yes  | Extended information, which varies depending on the authentication result.<br>If the authentication is successful, the user authentication token will be returned in **extraInfo**.<br>If the authentication fails, the remaining number of authentication times will be returned in **extraInfo**.<br>If the authentication executor is locked, the freeze time will be returned in **extraInfo**. |


**Example**

  ```js
  import userIAM_userAuth from '@ohos.userIAM.userAuth';

  let auth = new userIAM_userAuth.UserAuth();
  auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
      onResult: (result, extraInfo) => {
          try {
              console.info("auth onResult result = " + result);
              console.info("auth onResult extraInfo = " + JSON.stringify(extraInfo));
              if (result == SUCCESS) {
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

### onAcquireInfo<sup>8+</sup>

onAcquireInfo ?: (module : number, acquire : number, extraInfo : any) => void

Obtains the tip code information during authentication. This function is optional.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type  | Mandatory| Description                          |
| --------- | ------ | ---- | ------------------------------ |
| module    | number | Yes  | Type of the authentication executor.            |
| acquire   | number | Yes  | Interaction information of the authentication executor during the authentication process. |
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
              if (result == SUCCESS) {
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

## AuthResult<sup>8+</sup>

Represents the authentication result object.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name        | Type  | Mandatory| Description                |
| ------------ | ---------- | ---- | -------------------- |
| token        | Uint8Array | No  | Identity authentication token.      |
| remainTimes  | number     | No  | Number of remaining authentication operations. |
| freezingTime | number     | No  | Time for which the authentication operation is frozen. |

## ResultCode<sup>8+</sup>

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
| INVALID_PARAMETERS      | 8      | Invalid parameters are detected.          |
| LOCKED                  | 9      | The authentication executor is locked.      |
| NOT_ENROLLED            | 10     | The user has not entered the authentication information. |


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
| FACE_AUTH_TIP_TOO_MUCH_MOTION | 9      | The face moves too fast during facial information collection. |
| FACE_AUTH_TIP_POOR_GAZE       | 10     | The face is not facing the camera.                    |
| FACE_AUTH_TIP_NOT_DETECTED    | 11     | No face is detected.                |


## FingerprintTips<sup>8+</sup>

Enumerates the tip codes used during the fingerprint authentication process.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name                             | Default Value| Description                                              |
| --------------------------------- | ------ | -------------------------------------------------- |
| FINGERPRINT_AUTH_TIP_GOOD         | 0      | The obtained fingerprint image is in good condition.                              |
| FINGERPRINT_AUTH_TIP_DIRTY        | 1      | Large fingerprint image noise is detected due to suspicious or detected dirt on the sensor. |
| FINGERPRINT_AUTH_TIP_INSUFFICIENT | 2      | The noise of the fingerprint image is too large to be processed.    |
| FINGERPRINT_AUTH_TIP_PARTIAL      | 3      | Incomplete fingerprint image is detected.                            |
| FINGERPRINT_AUTH_TIP_TOO_FAST     | 4      | The fingerprint image is incomplete due to fast movement.                        |
| FINGERPRINT_AUTH_TIP_TOO_SLOW     | 5      | Failed to obtain the fingerprint image because the finger seldom moves.                      |


## UserAuthType<sup>8+</sup>

Enumerates the identity authentication types.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name       | Default Value| Description      |
| ----------- | ------ | ---------- |
| FACE        | 2      | Facial authentication. |
| FINGERPRINT | 4      | Fingerprint authentication. |

## AuthTrustLevel<sup>8+</sup>

Enumerates the trust levels of the authentication result.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name| Default Value| Description                     |
| ---- | ------ | ------------------------- |
| ATL1 | 10000  | Trust level 1. |
| ATL2 | 20000  | Trust level 2. |
| ATL3 | 30000  | Trust level 3. |
| ATL4 | 40000  | Trust level 4. |
