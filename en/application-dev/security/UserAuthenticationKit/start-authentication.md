# Initiating Authentication


A user authentication must be initiated before an application accesses a critical functionality or sensitive data. This topic walks you through the process.


## Available APIs

For details about the parameters, return value, and error codes, see [User Authentication](../../reference/apis/js-apis-useriam-userauth.md#getuserauthinstance10).

| API| Description|
| -------- | -------- |
| getUserAuthInstance(authParam: AuthParam, widgetParam: WidgetParam): UserAuthInstance | Obtains a **UserAuthInstance** object for user authentication. The unified [user authentication widget](#user-authentication-widget) is also supported.|
| on(type: 'result', callback: IAuthCallback): void | Subscribes to the user authentication result.|
| off(type: 'result', callback?: IAuthCallback): void | Unsubscribes from the user authentication result.|
| start(): void | Starts user authentication.|


## User Authentication Widget

The system provides a unified user authentication widget for applications to call. The widget provides the following features:

- The user authentication widget identifies and authenticates user information and returns the authentication result to the application. The overall process is secure and controllable.

- The widget comes with a unified UI component style to elevate user experience.

The following figure shows the style of the user authentication widget, which can be set via the [WidgetParam](../../reference/apis/js-apis-useriam-userauth.md#widgetparam10) parameter.

![](figures/user-authentication-widget.png)

- ①: Title (**WidgetParam.title**) of the user authentication page, which cannot exceed 500 characters. You can set the title based on actual requirements.

- ②: Text on the navigation button (**WidgetParam.navigationButtonText**), which cannot exceed 60 characters. This parameter can be set only for a single fingerprint or facial authentication. By default, the biometric authentication is switched to the lock screen password authentication after the navigation button is tapped.

- The following shows the display modes (**WidgetParam.windowMode**) of the user authentication widget.
  The user authentication widget provides two display modes: dialog box (default mode, as shown in figure on the left) and full screen (as shown in the figure on the right).

  Currently, the full screen mode is available only for system applications.

  ![](figures/widget_display_modes.png)

The user authentication widget supports the following types of authentication:

- Lock screen password authentication

- Facial authentication

- Fingerprint authentication

- Facial + lock screen password authentication

- Fingerprint + lock screen password authentication

- Facial + fingerprint + lock screen password authentication

> **NOTE**
> Currently, the text on the navigation button (**WidgetParam.navigationButtonText**) can be set only for a single fingerprint or facial authentication.


## How to Develop

1. Check that the application has the ohos.permission.ACCESS_BIOMETRIC permission. For details about how to request permissions, see [Requesting Permissions](prerequisites.md#requesting-permissions).

2. Use [getUserAuthInstance](../../reference/apis/js-apis-useriam-userauth.md#getuserauthinstance10) to obtain a **UserAuthInstance** object. You can set user authentication parameters, including the challenge value, authentication type list ([UserAuthType](../../reference/apis/js-apis-useriam-userauth.md#userauthtype8)), and authentication trust level ([AuthTrustLevel](../../reference/apis/js-apis-useriam-userauth.md#authtrustlevel8)), in [AuthParam](../../reference/apis/js-apis-useriam-userauth.md#authparam10), and set the authentication page style in [WidgetParam](../../reference/apis/js-apis-useriam-userauth.md#widgetparam10). 

3. Use [UserAuthInstance.on](../../reference/apis/js-apis-useriam-userauth.md#on10) to subscribe to the authentication result.

4. Use [UserAuthInstance.start](../../reference/apis/js-apis-useriam-userauth.md#start10) to initiate authentication. The authentication result [UserAuthResult](../../reference/apis/js-apis-useriam-userauth.md#userauthresult10) is returned through [IAuthCallback](../../reference/apis/js-apis-useriam-userauth.md#iauthcallback10).
   If the authentication is successful, the authentication type ([UserAuthType](../../reference/apis/js-apis-useriam-userauth.md#userauthtype8)) and token information (**AuthToken**) are returned.

Example: Initiate facial and lock screen password authentication with the authentication trust level greater than or equal to ATL3.

```ts
import userIAM_userAuth from '@ohos.userIAM.userAuth'; 

// Set authentication parameters.
const authParam: userIAM_userAuth.AuthParam = {
  challenge: new Uint8Array([49, 49, 49, 49, 49, 49]),
  authType: [userIAM_userAuth.UserAuthType.PIN, userIAM_userAuth.UserAuthType.FACE],
  authTrustLevel: userIAM_userAuth.AuthTrustLevel.ATL3,
};
// Set the authentication page.
const widgetParam: userIAM_userAuth.WidgetParam = {
  title: 'Verify identity',
};
try {
  // Obtain a UserAuthInstance object.
  let userAuthInstance = userIAM_userAuth.getUserAuthInstance(authParam, widgetParam);
  console.log('get userAuth instance success');
  // Subscribe to the authentication result.
  userAuthInstance.on('result', {
    onResult(result) {
      console.log('userAuthInstance callback result = ' + JSON.stringify(result));
      // Unsubscribe from the authentication result if required.
      userAuthInstance.off('result');
    }
  });
  console.log('auth on success');
  userAuthInstance.start();
  console.log('auth start success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.log('auth catch error. Code is ${err.code}, message is ${err.message}`);
}
```
