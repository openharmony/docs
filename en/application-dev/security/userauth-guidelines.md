# User Authentication Development

> **NOTE**
>
> This guide applies to the SDK for API version 10.

## When to Use

OpenHarmony supports PIN authentication, facial authentication, and fingerprint authentication, which can be used in identity authentication scenarios such as device unlocking, app login, and payment.

## Available APIs

The **userIAM_userAuth** module provides APIs for user authentication, including querying authentication capabilities, and initiating or canceling authentication. Users can use biometric feature information, such as facial and fingerprints, to perform authentications. For more details about the APIs, see [User Authentication](../reference/apis/js-apis-useriam-userauth.md).

Before authentication, you must specify the [authentication type](../reference/apis/js-apis-useriam-userauth.md#userauthtype8) and [authentication trust level](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8) to check whether the device supports the authentication capabilities.

**Table 1** APIs of user authentication

| API   | Description               |
| ---------- | ----------------------- |
| getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel): void | Checks whether the device supports the specified authentication type and level.|
| getUserAuthInstance(authParam: AuthParam, widgetParam: WidgetParam): UserAuthInstance | Obtains a **UserAuthInstance** instance for user authentication. The user authentication widget is supported.|
| on(type: 'result', callback: IAuthCallback): void | Subscribes to the user authentication result.|
| off(type: 'result', callback?: IAuthCallback): void | Unsubscribes from the user authentication result.|
| start(): void | Starts user authentication.       |
| cancel(): void | Cancels this user authentication.  |

**Table 2** Authentication trust levels

| Authentication Trust Level| Metrics                     | Description and Example                                                   | Typical Service Scenario                                |
| -------------------------- | --------------------------------- | ------------------------------------------------------------ | ---------------------------------------------------- |
| ATL4                       | When FRR = 10%, FAR ≤ 0.003%, SAR ≤ 3%   | The authentication can accurately identify individual users and provides powerful liveness detection capabilities. For example, PIN authentication with a secure keyboard and fingerprint and 3D facial authentication with special security enhancement. | Small-amount payment                                            |
| ATL3                       | When FRR = 10%, FAR ≤ 0.002%, SAR ≤ 7%    | The authentication can accurately identify individual users and provides strong liveness detection capabilities. For example, 2D facial authentication with special security enhancement. | Device unlocking                                            |
| ATL2                       | When FRR = 10%, FAR ≤ 0.002%, 7% < SAR ≤ 20%| The authentication can accurately identify individual users and provides regular liveness detection capabilities. For example, using a watch based on common ranging as a trusted holder to unlock a device. | Logins to apps and keeping a device unlocked    |
| ATL1                       | When FRR = 10%, FAR ≤ 1%, 7% < SAR ≤ 20%    | The authentication can identify individual users and provides limited liveness detection capabilities. For example, voiceprint authentication.          | Service risk control, query of general personal data, targeted recommendations, and personalized services|

> **NOTE**
>
> - FRR: False Reject Rate
> - FAR: False Acceptance Rate
> - SAR: Spoof Acceptance Rate

## Checking Authentication Capabilities Supported by a Device

### How to Develop

1. Apply for the permission.<br>Configure the **ohos.permission.ACCESS_BIOMETRIC** permission in **requestPermissions** in the **module.json5** file. For more information, see [module.json5](../quick-start/module-configuration-file.md).

2. Specify the [authentication type](../reference/apis/js-apis-useriam-userauth.md#userauthtype8) and [authentication trust level](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8), and call [getAvailableStatus](../reference/apis/js-apis-useriam-userauth.md#useriam_userauthgetavailablestatus9) to check whether the current device supports the authentication capabilities.

    ```ts
    import userIAM_userAuth from '@ohos.userIAM.userAuth';
    
    // Check whether the authentication capabilities are supported.
    try {
        userIAM_userAuth.getAvailableStatus(userIAM_userAuth.UserAuthType.FACE, userIAM_userAuth.AuthTrustLevel.ATL1);
        console.info('current auth trust level is supported');
    } catch (error) {
        console.info('current auth trust level is not supported, error = ' + error);
    }
    ```

## Performing Authentication and Subscribing to the Authentication Result

### How to Develop

1. Apply for the permission.<br>Configure the **ohos.permission.ACCESS_BIOMETRIC** permission in **requestPermissions** in the **module.json5** file. For more information, see [module.json5](../quick-start/module-configuration-file.md).

2. Specify the challenge, [authentication type](../reference/apis/js-apis-useriam-userauth.md#userauthtype8), and [authentication trust level](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8) to obtain an authentication object.

3. Call [on](../reference/apis/js-apis-useriam-userauth.md#on10) to subscribe to the authentication result.

4. Call [start](../reference/apis/js-apis-useriam-userauth.md#start10) to start authentication and return the authentication result through the [callback](../reference/apis/js-apis-useriam-userauth.md#callback10).

    ```ts
    import userIAM_userAuth from '@ohos.userIAM.userAuth';
    
    const authParam : userIAM_userAuth.AuthParam = {
      challenge: new Uint8Array([49, 49, 49, 49, 49, 49]),
      authType: [userIAM_userAuth.UserAuthType.PIN],
      authTrustLevel: userIAM_userAuth.AuthTrustLevel.ATL1,
    };
    const widgetParam : userIAM_userAuth.WidgetParam = {
      title:'Enter password',
    };
    try {
      // Obtain an authentication object.
      let userAuthInstance = userIAM_userAuth.getUserAuthInstance(authParam, widgetParam);
      console.log('get userAuth instance success');
      // Subscribe to the authentication result.
      userAuthInstance.on('result', {
        onResult (result) {
          console.log('userAuthInstance callback result = ' + JSON.stringify(result));
        }
      });
      console.log('auth on success');
      userAuthInstance.start();
      console.log('auth start success');
    } catch (error) {
      console.log('auth catch error: ' + JSON.stringify(error));
    }
    ```

5. Call [off](../reference/apis/js-apis-useriam-userauth.md#off10) for the [UserAuthInstance](../reference/apis/js-apis-useriam-userauth.md#userauthinstance10) object to unsubscribe from the authentication result.

   ```ts
   import userIAM_userAuth from '@ohos.userIAM.userAuth';
   
   const authParam : userIAM_userAuth.AuthParam = {
     challenge: new Uint8Array([49, 49, 49, 49, 49, 49]),
     authType: [userIAM_userAuth.UserAuthType.PIN],
     authTrustLevel: userIAM_userAuth.AuthTrustLevel.ATL1,
   };
   const widgetParam : userIAM_userAuth.WidgetParam = {
     title:'Enter password',
   };
   try {
     // Obtain an authentication object.
     let userAuthInstance = userIAM_userAuth.getUserAuthInstance(authParam, widgetParam);
     console.log('get userAuth instance success');
     // Unsubscribe from the authentication result.
     userAuthInstance.off('result', {
       onResult (result) {
         console.log('auth off result: ' + JSON.stringify(result));
       }
     });
     console.log('auth off success');
   } catch (error) {
     console.log('auth catch error: ' + JSON.stringify(error));
   }
   ```

## Canceling User Authentication

### How to Develop

1. Apply for the permission.<br>Configure the **ohos.permission.ACCESS_BIOMETRIC** permission in **requestPermissions** in the **module.json5** file. For more information, see [module.json5](../quick-start/module-configuration-file.md).

2. Specify the challenge, [authentication type](../reference/apis/js-apis-useriam-userauth.md#userauthtype8), and [authentication trust level](../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8) to obtain an authentication object.

3. Call [start](../reference/apis/js-apis-useriam-userauth.md#start10) to start authentication.

4. Call [cancel](../reference/apis/js-apis-useriam-userauth.md#cancel10) for the [UserAuthInstance](../reference/apis/js-apis-useriam-userauth.md#userauthinstance10) object to cancel this authentication.

    ```ts
    import userIAM_userAuth from '@ohos.userIAM.userAuth';
    
    const authParam : userIAM_userAuth.AuthParam = {
      challenge: new Uint8Array([49, 49, 49, 49, 49, 49]),
      authType: [userIAM_userAuth.UserAuthType.PIN],
      authTrustLevel: userIAM_userAuth.AuthTrustLevel.ATL1,
    };
    const widgetParam : userIAM_userAuth.WidgetParam = {
      title:'Enter password',
    };
    try {
      // Obtain an authentication object.
      let userAuthInstance = userIAM_userAuth.getUserAuthInstance(authParam, widgetParam);
      console.log('get userAuth instance success');
      // Start user authentication.
      userAuthInstance.start();
      console.log('auth start success');
      // Cancel the authentication.
      userAuthInstance.cancel();
      console.log('auth cancel success');
    } catch (error) {
      console.log('auth catch error: ' + JSON.stringify(error));
    }
    ```
