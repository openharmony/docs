# Canceling User Authentication

Use **cancel()** to terminate the authentication process when needed.

## Available APIs

For details about the parameters, return value, and error codes, see [cancel](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#cancel10).

This topic describes only the API for canceling authentication. For details about the APIs for initiating authentication, see [Initiating Authentication](start-authentication.md) and [User Authentication](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md).

| API| Description|
| -------- | -------- |
| cancel(): void | Cancels this user authentication.|

## How to Develop

1. Check that the application has the ohos.permission.ACCESS_BIOMETRIC permission. For details about how to request permissions, see [Requesting Permissions](prerequisites.md#requesting-permissions).

2. Set [AuthParam](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authparam10) (including the challenge value, [UserAuthType](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthtype8), and [AuthTrustLevel](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authtrustlevel8)), obtain a [UserAuthInstance](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthinstance10) instance, and call [UserAuthInstance.start](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#start10) to start authentication. For details, see [Initiating Authentication](start-authentication.md).

3. Call [UserAuthInstance.cancel](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#cancel10) with the **UserAuthInstance** instance that has initiated the authentication to terminate the authentication process.

Example: Initiate facial and lock screen password authentication at ATL3 or higher and then cancel it.

```ts
import { BusinessError } from  '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  const randData: Uint8Array = rand?.generateRandomSync(len)?.data;
  // Set authentication parameters.
  const authParam: userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN, userAuth.UserAuthType.FACE],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
  };
  // Set the authentication page.
  const widgetParam: userAuth.WidgetParam = {
    title: 'Verify identity',
  };
  // Obtain a UserAuthInstance object.
  const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
  // Start user authentication.
  userAuthInstance.start();
  console.info('auth start success');
  // Cancel the authentication.
  userAuthInstance.cancel();
  console.info('auth cancel success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```
