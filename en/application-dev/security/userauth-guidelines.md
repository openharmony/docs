# User Authentication Development

> ![icon-note.gif](../public_sys-resources/icon-note.gif) **NOTE**<br>
> This development guide applies to the SDK of API Version 8 or later.

## When to Use

2D and 3D facial recognition used in identity authentication scenarios such as device unlocking, application login, and payment

## Available APIs

The userIAM_userAuth module provides methods for checking the support for user authentication, and performing and canceling authentication. You can perform authentication based on biometric features such as facial characteristics. For more details, see [API Reference](../reference/apis/js-apis-useriam-userauth.md).

Before performing authentication, check whether the device supports user authentication, including the authentication type and level. If user authentication is not supported, consider using another authentication type. The following table lists the APIs available for user authentication.

**Table 1** APIs of user authentication

| API                                                      | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| getVersion() : number                                        | Obtains the version information of an authentication object.                                    |
| getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel) : number | Checks whether the device supports the specified authentication type and level.|
| auth(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array | Performs user authentication. This method uses asynchronous callback to return the result.                |
| cancelAuth(contextID : Uint8Array) : number                  | Cancels an authentication.                             |

## How to Develop

Before starting the development, make the following preparations:

1. Add the ohos.permission.ACCESS_BIOMETRIC permission declaration to the application permission file.
2. Add **import userIAM_userAuth from '@ohos.userIAM.userAuth'** to the code file.

The development procedure is as follows:

1. Obtain an **Authenticator** singleton object. The sample code is as follows:

   ```js
   let auth = new userIAM_userAuth.UserAuth();
   ```

2. (Optional) Obtain the version information of the authenticated object.

   ```js
   let auth = new userIAM_userAuth.UserAuth();
   let version = auth.getVersion();
   console.info("auth version = " + version);
   ```

3. Check whether the device supports the authentication capabilities based on the specified authentication type and level. 

   ```js
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

4. Perform an authentication.

   ```js
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

5. Cancel the authentication.

   ```js
   let auth = new userIAM_userAuth.UserAuth();
   // Obtain contextId using auth().
   let contextId = auth.auth(null, userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1, {
       onResult: (result, extraInfo) => {
           console.info("auth onResult result = " + result);
       },
   
       onAcquireInfo: (module, acquire, extraInfo) => {
           console.info("auth onAcquireInfo module = " + module);
       }
   });
   let cancelCode = auth.cancel(contextId);
   if (cancelCode == userIAM_userAuth.ResultCode.SUCCESS) {
       console.info("cancel auth success");
   } else {
       console.error("cancel auth fail");
   }
   ```
