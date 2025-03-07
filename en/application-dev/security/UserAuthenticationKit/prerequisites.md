# Before You Start


Before you get started, learn the development process.


- [Obtain supported authentication capabilities](obtain-supported-authentication-capabilities.md).

- [Initiate a request for user authentication and obtain the authentication result](start-authentication.md).

- Verify and use the authentication result. For details, see [Key Access Control via Secondary Authentication](../UniversalKeystoreKit/huks-identity-authentication-overview.md).

- (Optional) [Cancel authentication](cancel-authentication.md).

- (Optional) [Apply custom authentication](apply-custom-authentication.md).


## Requesting Permissions

The application capable of user authentication based on biometric features (such as facial and fingerprints) must have the ohos.permission.ACCESS_BIOMETRIC permission.

This permission is a system_grant (system authorization) permission. You can declare it in the **requestPermissions** tag in the **module.json5** file. For details, see [Declaring Permissions](../AccessToken/declare-permissions.md).
