# @ohos.userIAM.userAccessCtrl (User Access Control) (System API)

The **userAccessCtrl** module provides APIs for setting and obtaining user identity authentication policies and verifying user identity authentication results.

> **NOTE**
>
> The initial APIs of this module are supported since API version 16. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { userAccessCtrl } from '@kit.UserAuthenticationKit';
```

## AuthTokenType

Enumerates the authentication token types.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**System API**: This is a system API.

| Name                     | Value  | Description      |
| ------------------------ | ---- | ---------- |
| TOKEN_TYPE_LOCAL_AUTH    | 0    | Authentication token issued based on the local authentication result.|
| TOKEN_TYPE_LOCAL_RESIGN  | 1    | Authentication token issued based on the reused identity authentication result.|
| TOKEN_TYPE_COAUTH        | 2    | Authentication token issued based on a collaborative authentication result of multiple devices.|

## AuthToken

Represents the AuthToken data returned after a successful verification.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**System API**: This is a system API.

| Name          | Type                              | Read Only| Optional| Description                                      |
| -------------- | ---------------------------------- | ----- | ----- |------------------------------------------------------------ |
| challenge | Uint8Array | No| No|Random challenge for the authentication.|
| authTrustLevel | [userAuth.AuthTrustLevel](js-apis-useriam-userauth.md#authtrustlevel8) | No| No|Authentication trust level.|
| authType | [userAuth.UserAuthType](js-apis-useriam-userauth.md#userauthtype8) | No| No |Credential type for the identity authentication.|
| tokenType | [AuthTokenType](#authtokentype) | No| No|Authentication token type.|
| userId | number | No| No |User ID.|
| timeInterval | bigint | No | No |Time elapsed since the issuance of the authentication token, in milliseconds.|
| secureUid | bigint    | No | Yes |Secure user ID.|
| enrolledId | bigint   | No | Yes |Credential enrollment ID.|
| credentialId | bigint | No | Yes |Credential ID.|


## userAccessCtrl.verifyAuthToken

verifyAuthToken(authToken: Uint8Array, allowableDuration: number): Promise\<AuthToken>

Verifies an authentication token.

**Required permissions**: ohos.permission.USE_USER_ACCESS_MANAGER

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                       | Mandatory| Description      |
| ---------- | --------------------------- | ---- | ---------- |
| authToken | Uint8Array | Yes  | Authentication token to verify, which cannot exceed 1024.|
| allowableDuration  | number  | Yes  | Time allowed for the authentication token to be used after being issued, in milliseconds. The value must be greater than 0 and less than or equal to 86,400,000.|

**Return value**

| Type                                     | Description        |
| ----------------------------------------- | ------------ |
| Promise\<[AuthToken](#authtoken)> | Promise used to return the parsed authentication token.|

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 201      | Permission verification failed.         |
| 202      | The caller is not a system application. |
| 401      | Incorrect parameters. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.    |
| 12500002 | General operation error.                |
| 12500015 | AuthToken integrity check failed.     |
| 12500016 | AuthToken has expired.                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAccessCtrl } from '@kit.UserAuthenticationKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const allowableDuration: number = 5000;
  const len: number = 16;
  const randData: Uint8Array = rand?.generateRandomSync(len)?.data;
  const authParam: userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
  };
  const widgetParam: userAuth.WidgetParam = {
    title: 'Enter password',
  };

  const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
  // The authentication result is returned by onResult() only after the authentication is started by start() of UserAuthInstance.
  userAuthInstance.on('result', {
    onResult (result) {
        if (!result.token) {
            console.error('userAuthInstance callback result.token is null');
            return;
        }
        // Initiate a request for verifying the authentication token.
        userAccessCtrl.verifyAuthToken(result.token, allowableDuration)
            .then((retAuthToken: userAccessCtrl.AuthToken) => {
                Object.keys(retAuthToken).forEach((key) => {
                    console.info(`retAuthToken key:${key}, value:${retAuthToken[key]}`);
                })
            }).catch ((error: BusinessError) => {
                console.error(`verify authToken error. Code is ${error?.code}, message is ${error?.message}`);
            })
    }
  });
  console.info('auth on success');
  // Start authentication.
  userAuthInstance.start();
  console.info('auth start success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```
