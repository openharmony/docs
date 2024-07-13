# Obtaining Enrolled Credential Information


The caller can obtain information about the credentials enrolled by the user to detect the change of the credentials (face, fingerprint, and password).


## Available APIs

For details about the parameters, return values, and error codes, see [getEnrolledState](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthgetenrolledstate12).

| API| Description| 
| -------- | -------- |
| getEnrolledState(authType : UserAuthType): EnrolledState | Obtains the status of the enrolled credentials based on the specified authentication type.| 


## How to Develop

1. Check that the application has the ohos.permission.ACCESS_BIOMETRIC permission. For details about how to request permissions, see [Requesting Permissions](prerequisites.md#requesting-permissions).

2. Use [getEnrolledState](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthgetenrolledstate12) with **UserAuthType** to obtain information about the credentials enrolled by the user.

Example: Obtain information about the credentials enrolled for facial authentication.

```ts
import { BusinessError } from  '@kit.BasicServicesKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  let enrolledState = userAuth.getEnrolledState(userAuth.UserAuthType.FACE);
  console.info(`get current enrolled state success, enrolledState: ${JSON.stringify(enrolledState)}`);
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`get current enrolled state failed, Code is ${err?.code}, message is ${err?.message}`);
}
```
