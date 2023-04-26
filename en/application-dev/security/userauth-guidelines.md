# User Authentication Development

> ![icon-note.gif](../public_sys-resources/icon-note.gif) **NOTE**<br>
> This guide applies to the SDK for API version 9.

## When to Use

User authentication supports facial recognition and fingerprint recognition and can be used in identity authentication scenarios such as device unlocking, application login, and payment.

## Available APIs

The **userIAM_userAuth** module provides APIs for user authentication, including querying authentication capabilities, and initiating or canceling authentication. Users can use biometric feature information, such as facial and fingerprints, to perform authentications. For more details about the APIs, see [User Authentication](../reference/apis/js-apis-useriam-userauth.md).

Before authentication, you must specify the [authentication type](../reference/apis/js-apis-useriam-userauth.md#userauthtype8) and [authentication trust level](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8) to check whether the device supports the authentication capabilities.

**Table 1** APIs of user authentication

| API   | Description               |
| ---------- | ----------------------- |
| getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel): void | Checks whether the device supports the specified authentication type and level.|
| getAuthInstance(challenge : Uint8Array, authType : UserAuthType, authTrustLevel : AuthTrustLevel): AuthInstance | Obtains an **AuthInstance** instance for user authentication.|
| on(name : AuthEventKey, callback : AuthEvent) : void | Subscribes to the user authentication events of the specified type.|
| off(name : AuthEventKey) : void | Unsubscribes from the user authentication events of the specific type.|
| start: void  | Starts user authentication.       |
| cancel: void | Cancel this user authentication.   |

## Checking Authentication Capabilities Supported by a Device

### How to Develop

1. Apply for the permission.<br> Configure the **ohos.permission.ACCESS_BIOMETRIC** permission in **requestPermissions** in the **module.json5** file. For more information, see [module.json5](../quick-start/module-configuration-file.md).

2. Specify the [authentication type](../reference/apis/js-apis-useriam-userauth.md#userauthtype8) and [authentication trust level](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8), and call [getAvailableStatus](../reference/apis/js-apis-useriam-userauth.md#useriam_userauthgetavailablestatus9) to check whether the current device supports the authentication capabilities.

    ```js
    import userIAM_userAuth from '@ohos.userIAM.userAuth';

    // Check whether the authentication capabilities are supported.
    try {
        userIAM_userAuth.getAvailableStatus(userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1);
        console.info("current auth trust level is supported");
    } catch (error) {
        console.info("current auth trust level is not supported, error = " + error);
    }
    ```

## Performing Authentication and Subscribing to the Authentication Result

### How to Develop

1. Apply for the permission.<br> Configure the **ohos.permission.ACCESS_BIOMETRIC** permission in **requestPermissions** in the **module.json5** file. For more information, see [module.json5](../quick-start/module-configuration-file.md).

2. Specify the challenge, [authentication type](../reference/apis/js-apis-useriam-userauth.md#userauthtype8), and [authentication trust level](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8) to obtain an authentication object.

3. Use [on](../reference/apis/js-apis-useriam-userauth.md#on9) to subscribe to the authentication result.

4. Use [start](../reference/apis/js-apis-useriam-userauth.md#start9) to initiate an authentication and return the authentication result through [callback](../reference/apis/js-apis-useriam-userauth.md#callback9).

5. Use [off](../reference/apis/js-apis-useriam-userauth.md#off9) to unsubscribe from the authentication result.

    ```js
    import userIAM_userAuth from '@ohos.userIAM.userAuth';

    let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
    let authType = userIAM_userAuth.UserAuthType.FACE;
    let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;

    // Obtain an authentication object.
    let auth;
    try {
        auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
        console.log("get auth instance success");
    } catch (error) {
        console.log("get auth instance failed" + error);
    }

    // Subscribe to the authentication result.
    try {
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

    // Start user authentication.
    try {
        auth.start();
        console.info("authV9 start auth success");
    } catch (error) {
        console.info("authV9 start auth failed, error = " + error);
    }

    // Unsubscribe from the authentication result.
    try {
        auth.off("result");
        console.info("cancel subscribe authentication event success");
    } catch (error) {
        console.info("cancel subscribe authentication event failed, error = " + error);
    }
    ```

## Performing Authentication and Subscribing to Authentication Tip Information

### How to Develop

1. Apply for the permission.<br> Configure the **ohos.permission.ACCESS_BIOMETRIC** permission in **requestPermissions** in the **module.json5** file. For more information, see [module.json5](../quick-start/module-configuration-file.md).

2. Specify the challenge, [authentication type](../reference/apis/js-apis-useriam-userauth.md#userauthtype8), and [authentication trust level](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8) to obtain an authentication object.

3. Use [on](../reference/apis/js-apis-useriam-userauth.md#on9) to subscribe to the authentication tip information.

4. Use [start](../reference/apis/js-apis-useriam-userauth.md#start9) to initiate an authentication and return the tip information through [callback](../reference/apis/js-apis-useriam-userauth.md#callback9).

5. Use [off](../reference/apis/js-apis-useriam-userauth.md#off9) to unsubscribe from the authentication tip information.

    ```js
    import userIAM_userAuth from '@ohos.userIAM.userAuth';

    let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
    let authType = userIAM_userAuth.UserAuthType.FACE;
    let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;

    // Obtain an authentication object.
    let auth;
    try {
        auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
        console.log("get auth instance success");
    } catch (error) {
        console.log("get auth instance failed" + error);
    }

    // Subscribe to authentication tip information.
    try {
        auth.on("tip", {
            callback : (result : userIAM_userAuth.TipInfo) => {
                switch (result.tip) {
                    case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_BRIGHT:
                    // Do something.
                    case userIAM_userAuth.FaceTips.FACE_AUTH_TIP_TOO_DARK:
                    // Do something.
                    default:
                    // Do others.
                }
            }
        });
        console.log("subscribe authentication event success");
    } catch (error) {
        console.log("subscribe authentication event failed " + error);
    }

    // Start user authentication.
    try {
        auth.start();
        console.info("authV9 start auth success");
    } catch (error) {
        console.info("authV9 start auth failed, error = " + error);
    }

    // Unsubscribe from authentication tip information.
    try {
        auth.off("tip");
        console.info("cancel subscribe tip information success");
    } catch (error) {
        console.info("cancel subscribe tip information failed, error = " + error);
    }
    ```

## Canceling User Authentication

### How to Develop

1. Apply for the permission.<br> Configure the **ohos.permission.ACCESS_BIOMETRIC** permission in **requestPermissions** in the **module.json5** file. For more information, see [module.json5](../quick-start/module-configuration-file.md).

2. Specify the challenge, [authentication type](../reference/apis/js-apis-useriam-userauth.md#userauthtype8), and [authentication trust level](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8) to obtain an authentication object.

3. Use [start](../reference/apis/js-apis-useriam-userauth.md#start9) to initiate an authentication.

4. Use [cancel](../reference/apis/js-apis-useriam-userauth.md#cancel9) to cancel this authentication.

    ```js
    import userIAM_userAuth from '@ohos.userIAM.userAuth';

    let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
    let authType = userIAM_userAuth.UserAuthType.FACE;
    let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;

    // Obtain an authentication object.
    let auth;
    try {
        auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
        console.log("get auth instance success");
    } catch (error) {
        console.log("get auth instance failed" + error);
    }

    // Start user authentication.
    try {
        auth.start();
        console.info("authV9 start auth success");
    } catch (error) {
        console.info("authV9 start auth failed, error = " + error);
    }

    // Cancel the authentication.
    try {
        auth.cancel();
        console.info("cancel auth success");
    } catch (error) {
        console.info("cancel auth failed, error = " + error);
    }
    ```
