# Canceling User Authentication

<!--Kit: User Authentication Kit-->
<!--Subsystem: UserIAM-->
<!--Owner: @WALL_EYE-->
<!--Designer: @lichangting518-->
<!--Tester: @jane_lz-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=7bb26c61ea8a340708fd981ae4e6341180afc9e5 translatedAt=2026-08-14T06:44:34.416Z pushedAt=2026-08-14T07:59:38.451Z -->

The unified user authentication framework provides **cancel()** for terminating the authentication process.

## Available APIs

For details about the parameters, return values, and error codes, see [cancel](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#cancel10).

This topic describes only the API for canceling authentication. For details about the APIs for initiating authentication, see [Initiating Authentication](start-authentication.md) and related API reference.

| API| Description| 
| -------- | -------- |
| cancel(): void | Cancels this user authentication.| 

## How to Develop

1. Check that the application has the ohos.permission.ACCESS_BIOMETRIC permission. For details about how to request permissions, see [Requesting Permissions](prerequisites.md#requesting-permissions).

2. Set [AuthParam](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authparam10) (including the challenge value, [UserAuthType](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthtype8), and [AuthTrustLevel](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authtrustlevel8)), obtain a [UserAuthInstance](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthinstance10) instance, and call [UserAuthInstance.start](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#start10) to start authentication. For details, see [Initiating Authentication](start-authentication.md).

3. Call [UserAuthInstance.cancel](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#cancel10) with the **UserAuthInstance** instance that has initiated the authentication to terminate the authentication process.

Example: Initiate facial and lock screen password authentication at ATL3 or higher and then cancel it.

<!-- @[cancel_authentication](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/UserAuthentication/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
handleAuthResultAndCanceling(userAuthInstance: userAuth.UserAuthInstance, exampleNumber: number) {
  // ...
    // Start authentication.
    userAuthInstance.start();
    Logger.info('auth start successfully.');
    // ...
      // Cancel the authentication.
      userAuthInstance.cancel();
      Logger.info('auth cancel successfully.');
      // ...
}

/*
 * cancel-authentication.md
 * Initiate facial and lock screen password authentication at ATL3 or higher and then cancel it.
 * */
cancelingUserAuthentication() {
  try {
    const randData = getRandData();
    if (!randData) {
      return;
    }
    // Set authentication parameters.
    const authParam: userAuth.AuthParam = {
      challenge: randData,
      authType: [userAuth.UserAuthType.PIN, userAuth.UserAuthType.FACE, userAuth.UserAuthType.FINGERPRINT],
      authTrustLevel: userAuth.AuthTrustLevel.ATL3,
    };
    // Set the authentication page.
    const widgetParam: userAuth.WidgetParam = {
      title: resourceToString($r('app.string.title')),
    };
    // Obtain an authentication object.
    const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
    Logger.info('get userAuth instance successfully.');
    this.handleAuthResultAndCanceling(userAuthInstance, ResultIndex.CANCEL);
  } catch (error) {
    const err: BusinessError = error as BusinessError;
    Logger.error(`auth failed, code is ${err?.code as number}, message is ${err?.message}`);
  }
}
```

## Sample Code

  - [Canceling authentication during the authentication process](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/UserAuthentication)