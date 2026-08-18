# Obtaining the Locking Status of a Specified Authentication Type

<!--Kit: User Authentication Kit-->
<!--Subsystem: UserIAM-->
<!--Owner: @WALL_EYE-->
<!--Designer: @lichangting518-->
<!--Tester: @jane_lz-->
<!--Adviser: @zengyawen-->

From API version 22, you can obtain the locking status of a specified authentication type, the number of remaining authentication attempts, or the remaining authentication locking time based on the following development guide.

## Available APIs

For details about the parameters, return values, and error codes, see [userAuth.getAuthLockState](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthgetauthlockstate22).

| API| Description|
| -------- | -------- |
| getAuthLockState(authType: UserAuthType): Promise\<AuthLockState> | Obtains the locking status of a specified authentication type to determine whether authentication can be initiated.| 

## How to Develop

1. Check that the application has the ohos.permission.ACCESS_BIOMETRIC permission. For details about how to request permissions, see [Requesting Permissions](prerequisites.md#requesting-permissions).

2. Specify an authentication type ([UserAuthType](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthtype8)) and call the [getAuthLockState](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthgetauthlockstate22) API to query the authentication locking status.

Example: Obtain the authentication locking status of the PIN authentication type.

<!-- @[obtain_auth_lock_state_capabilities](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/UserAuthentication/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
async obtainingAuthLockState() : Promise<string> {
  try {
    Logger.info(`get auth lock state start`);
    const authLockState : userAuth.AuthLockState = await userAuth.getAuthLockState(userAuth.UserAuthType.PIN);
    if (authLockState.lockoutDuration === userAuth.PERMANENT_LOCKOUT_DURATION) {
      Logger.info('the authentication of given authType is permanent locked.');
    }
    const authLockStateContent : string = JSON.stringify(authLockState);
    Logger.info('get auth lock state successfully.');
    return authLockStateContent;
  } catch (error) {
    const errorMessage : string = `get auth lock state failed, err code is : ${error?.code}, err message is : ${error?.message}`;
    Logger.error(errorMessage);
    return errorMessage;
  }
}
```

## Sample Code

  - [Querying the Authentication Locking Status of a Specified Authentication Type](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/UserAuthentication)
