# User IAM Subsystem Changelog

## cl.useriam.1 Deprecation of AuthEvent

**Access Level**

Public

**Reason for Change**

The user authentication widget is used to implement user identity authentication to ensure consistent user experience. The APIs of the original user identity authentication are deprecated.

**Change Impact**

This change is a compatible change. The use of deprecated APIs is not affected.

**API Level**

8

**Change Since**

OpenHarmony SDK 4.1.6.2

**Deprecated APIs/Components**

| API| Description| Substitute API|
|---------|----------|--------|
| interface AuthEvent | This API is deprecated. Use **IAuthCallback** instead.| interface IAuthCallback |
| callback(result: EventInfo): void | This API is deprecated. Use **onResult** in **IAuthCallback** instead.| method onResult |
| field AuthEventKey | This API is deprecated.| N/A|
| type EventInfo | This API is deprecated. Use **UserAuthResult** in **IAuthCallback** instead.| interface UserAuthResult |
| interface AuthResultInfo | This API is deprecated.| N/A|
| field result | This API is deprecated. Use **result** in **UserAuthResult** instead.| field result |
| field token | This API is deprecated. Use **token** in **UserAuthResult** instead.| field token |
| field remainAttempts | This API is deprecated.| N/A|
| field lockoutDuration | This API is deprecated.| N/A|
| interface TipInfo | This API is deprecated.| N/A|
| field module | This API is deprecated.| N/A|
| field tip | This API is deprecated.| N/A|
| enum_class FingerprintTips | This API is deprecated.| N/A|
| enum_instance FINGERPRINT_AUTH_TIP_TOO_SLOW | This API is deprecated.| N/A|
| enum_instance FINGERPRINT_AUTH_TIP_TOO_FAST | This API is deprecated.| N/A|
| enum_instance FINGERPRINT_AUTH_TIP_PARTIAL | This API is deprecated.| N/A|
| enum_instance FINGERPRINT_AUTH_TIP_INSUFFICIENT | This API is deprecated.| N/A|
| enum_instance FINGERPRINT_AUTH_TIP_DIRTY | This API is deprecated.| N/A|
| enum_instance FINGERPRINT_AUTH_TIP_GOOD | This API is deprecated.| N/A|
| enum_class FaceTips | This API is deprecated.| N/A|
| enum_instance FACE_AUTH_TIP_TOO_BRIGHT | This API is deprecated.| N/A|
| enum_instance FACE_AUTH_TIP_TOO_DARK | This API is deprecated.| N/A|
| enum_instance FACE_AUTH_TIP_TOO_CLOSE | This API is deprecated.| N/A|
| enum_instance FACE_AUTH_TIP_TOO_FAR | This API is deprecated.| N/A|
| enum_instance FACE_AUTH_TIP_TOO_HIGH | This API is deprecated.| N/A|
| enum_instance FACE_AUTH_TIP_TOO_LOW | This API is deprecated.| N/A|
| enum_instance FACE_AUTH_TIP_TOO_RIGHT | This API is deprecated.| N/A|
| enum_instance FACE_AUTH_TIP_TOO_LEFT | This API is deprecated.| N/A|
| enum_instance FACE_AUTH_TIP_TOO_MUCH_MOTION | This API is deprecated.| N/A|
| enum_instance FACE_AUTH_TIP_POOR_GAZE | This API is deprecated.| N/A|
| enum_instance FACE_AUTH_TIP_NOT_DETECTED | This API is deprecated.| N/A|

**Adaptation Guide**

For example, replace the callback in **AuthEvent** with **onResult** of **IAuthCallback**. The sample code is as follows:

```js
import userIAM_userAuth from '@ohos.userIAM.userAuth';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userIAM_userAuth.UserAuthType.FACE;
let authTrustLevel = userIAM_userAuth.AuthTrustLevel.ATL1;
try {
  let auth = userIAM_userAuth.getAuthInstance(challenge, authType, authTrustLevel);
  auth.on('result', {
    // In API version 9, the callback in AuthEvent returns the authentication result.
    callback: (result: userIAM_userAuth.AuthResultInfo) => {
      console.log('authV9 result ' + result.result);
      console.log('authV9 token ' + result.token);
      console.log('authV9 remainAttempts ' + result.remainAttempts);
      console.log('authV9 lockoutDuration ' + result.lockoutDuration);
    }
  } as userIAM_userAuth.AuthEvent);
  auth.start();
  console.log('authV9 start success');
} catch (error) {
  console.error('authV9 error = ' + error);
  // do error
}
```

```js
import userAuth from '@ohos.userIAM.userAuth';

const authParam : userAuth.AuthParam = {
  challenge: new Uint8Array([49, 49, 49, 49, 49, 49]),
  authType: [userAuth.UserAuthType.PIN],
  authTrustLevel: userAuth.AuthTrustLevel.ATL1,
};
const widgetParam :userAuth.WidgetParam = {
  title: 'Enter password',
};
try {
  let userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.log('get userAuth instance success');
  // The authentication result is returned by onResult only after the authentication is started by start() of UserAuthInstance.
  userAuthInstance.on('result', {
    // Since API version 10, the onResult callback of IAuthCallback returns the authentication result.
    onResult (result) {
      console.log('userAuthInstance callback result = ' + JSON.stringify(result));
    }
  });
  console.log('auth on success');
} catch (error) {
  console.error('auth catch error: ' + JSON.stringify(error));
}
```

For more information, see [User Authentication](../../../application-dev/reference/apis-user-authentication-kit/js-apis-useriam-userauth.md) and [Facial Authentication](../../../application-dev/reference/apis-user-authentication-kit/js-apis-useriam-faceauth-sys.md).
