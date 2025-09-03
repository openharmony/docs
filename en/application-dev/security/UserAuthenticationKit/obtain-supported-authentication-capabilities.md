# Obtaining Supported Authentication Capabilities

<!--Kit: User Authentication Kit-->
<!--Subsystem: UserIAM-->
<!--Owner: @WALL_EYE-->
<!--SE: @lichangting518-->
<!--TSE: @jane_lz-->

Different devices support different authentication capabilities (facial authentication, fingerprint authentication, and password authentication). Before you start coding, obtain the authentication capabilities supported by the target device.

## Available APIs

For details about the parameters, return value, and error codes, see [getAvailableStatus](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthgetavailablestatus9).

| API| Description| 
| -------- | -------- |
| getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel): void | Checks whether the specified authentication type and authentication trust level are supported by the device.| 

## How to Develop

1. [Request](prerequisites.md#requesting-permissions) the ohos.permission.ACCESS_BIOMETRIC permission.

2. Call [getAvailableStatus](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthgetavailablestatus9) to check whether the device supports the specified authentication type ([UserAuthType](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthtype8)) and authentication trust level ([AuthTrustLevel](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authtrustlevel8)).

   For details about the authentication trust levels, see [Principles for Classifying Biometric Authentication Trust Levels](../../security/UserAuthenticationKit/user-authentication-overview.md).

Example: Check whether the device supports facial authentication of ATL3 or higher.

```ts
import { BusinessError } from  '@kit.BasicServicesKit';
import { userAuth } from '@kit.UserAuthenticationKit';

// Check whether the specified authentication capabilities are supported.
try {
    userAuth.getAvailableStatus(userAuth.UserAuthType.FACE, userAuth.AuthTrustLevel.ATL3);
    console.info('current auth trust level is supported');
} catch (error) {
    const err: BusinessError = error as BusinessError;
    console.error(`current auth trust level is not supported. Code is ${err?.code}, message is ${err?.message}`);
}
```
