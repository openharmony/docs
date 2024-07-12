# Obtaining Supported Authentication Capabilities


Different devices support different authentication capabilities (facial authentication, fingerprint authentication, and PIN authentication). Before you start coding, obtain the authentication capabilities supported by the target device.


## Available APIs

For details about the parameters, return value, and error codes, see [getAvailableStatus](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthgetavailablestatus9).

| API| Description| 
| -------- | -------- |
| getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel): void | Checks whether the specified authentication type and authentication trust level are supported by the device.| 


## How to Develop

1. [Request](prerequisites.md#requesting-permissions) the ohos.permission.ACCESS_BIOMETRIC permission.

2. Use [getAvailableStatus](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthgetavailablestatus9) to check whether the device supports the specified authentication type (**UserAuthType**) and authentication trust level (**AuthTrustLevel**).

Example: Check whether the device supports facial authentication of ATL1 or higher.

```ts
import { BusinessError } from  '@kit.BasicServicesKit';
import { userAuth } from '@kit.UserAuthenticationKit';

// Check whether the specified authentication capabilities are supported.
try {    
    userAuth.getAvailableStatus(userAuth.UserAuthType.FACE, userAuth.AuthTrustLevel.ATL1);    
    console.info('current auth trust level is supported');
} catch (error) {
    const err: BusinessError = error as BusinessError;
    console.error(`current auth trust level is not supported. Code is ${err?.code}, message is ${err?.message}`);
}
```
