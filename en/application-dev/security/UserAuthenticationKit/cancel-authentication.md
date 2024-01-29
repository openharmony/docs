# Canceling User Authentication


This topic walks you through the process of canceling an authentication in process.


## Available APIs

For details about the parameters, return value, and error codes, see [Cancel](../../reference/apis/js-apis-useriam-userauth.md#cancel10).

This topic describes only the API for canceling authentication. For details about the APIs for initiating authentication, see [Initiating Authentication](start-authentication.md) and [User Authentication](../../reference/apis/js-apis-useriam-userauth.md).

| API| Description|
| -------- | -------- |
| cancel(): void | Cancels this user authentication.|


## How to Develop

1. Check that the application has the ohos.permission.ACCESS_BIOMETRIC permission. For details about how to request permissions, see [Requesting Permissions](prerequisites.md#requesting-permissions).

2. Use [getUserAuthInstance](../../reference/apis/js-apis-useriam-userauth.md#getuserauthinstance10) to obtain a [UserAuthInstance](../../reference/apis/js-apis-useriam-userauth.md#userauthinstance10) object and use [UserAuthInstance.start](../../reference/apis/js-apis-useriam-userauth.md#start10) to initiate authentication.
   For details, see [Initiating Authentication](start-authentication.md).

3. Use [UserAuthInstance.cancel](../../reference/apis/js-apis-useriam-userauth.md#cancel10) with the **UserAuthInstance** object that has initiated the authentication to cancel the authentication.

Example: Initiate the facial and lock screen password authentication with the authentication trust level greater than or equal to ATL3 and cancel it.

```ts
import userIAM_userAuth from '@ohos.userIAM.userAuth'; 

const authParam: userIAM_userAuth.AuthParam = {
  challenge: new Uint8Array([49, 49, 49, 49, 49, 49]),
  authType: [userIAM_userAuth.UserAuthType.PIN, userIAM_userAuth.UserAuthType.FACE],
  authTrustLevel: userIAM_userAuth.AuthTrustLevel.ATL3,
};
const widgetParam: userIAM_userAuth.WidgetParam = {
  title: 'Verify identity',
};
try {
  // Obtain a UserAuthInstance object.
  let userAuthInstance = userIAM_userAuth.getUserAuthInstance(authParam, widgetParam);
  console.log('get userAuth instance success');
  // Start user authentication.
  userAuthInstance.start();
  console.log('auth start success');
  // Cancel the authentication.
  userAuthInstance.cancel();
  console.log('auth cancel success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.log('auth catch error. Code is ${err.code}, message is ${err.message}`);
}
```
