# Managing System Account Credentials (for System Application Only)

Credentials can be used to authenticate users. This topic walks you through on how to add, update, obtain, and delete credentials for a system account and authenticate the system account using the enrolled credentials.

## Credential Type

The following types of credentials are supported for system accounts:

| Name | Value| Description            |
| ----- | ----- | ---------------- |
| PIN   | 1     | PIN.|
| FACE  | 2     | Face.|
| FINGERPRINT<sup>10+</sup>   | 4     | Fingerprint.|

## Credential Subtype

Credential types are further classified into the following subtypes:

| Name      | Value| Description              |
| ---------- | ----- | ------------------ |
| PIN_SIX    | 10000 | Six-digit PIN.      |
| PIN_NUMBER | 10001 | Custom PIN.|
| PIN_MIXED  | 10002 | Custom mixed PIN.|
| FACE_2D    | 20000 | 2D face credential.  |
| FACE_3D    | 20001 | 3D face credential.  |
| FINGERPRINT_CAPACITIVE<sup>10+</sup>    | 30000 | Capacitive fingerprint.  |
| FINGERPRINT_OPTICAL<sup>10+</sup>    | 30001 | Optical fingerprint.  |
| FINGERPRINT_ULTRASONIC<sup>10+</sup>    | 30002 | Ultrasonic fingerprint.  |

**NOTE**<br>The credential types supported by the device depend on the hardware capability.

## Before You Start

1. Request the following permissions. For details, see [Requesting Permissions for system_basic Applications](../../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).
   - ohos.permission.MANAGE_USER_IDM
   - ohos.permission.ACCESS_PIN_AUTH

2. Import the **osAccount** module.

   ```ts
   import { osAccount } from '@kit.BasicServicesKit';
   ```

3. Create a **UserIDM** instance.

   ```ts
   let userIDM: osAccount.UserIdentityManager = new osAccount.UserIdentityManager();
   ```

## Registering a PIN Inputer

Register a PIN inputer to transmit PIN data.

**Procedure**

1. Define a PIN inputer and obtain the PIN.

   ```ts
   let pinData: Uint8Array = new Uint8Array([31, 32, 33, 34, 35, 36]); // you can obtain a PIN throught other ways.
   let inputer: osAccount.IInputer = {
     onGetData: (authSubType: osAccount.AuthSubType, callback: osAccount.IInputData) => {
       callback.onSetData(authSubType, pinData);
     }
   }
   ```

2. Use [registerInputer](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#registerinputer8) to register the PIN inputer.

   ```ts
   let pinAuth: osAccount.PINAuth = new osAccount.PINAuth();
   pinAuth.registerInputer(inputer);
   ```

## Opening a Session

Use [openSession](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#opensession8) to open a session for credential management.

**Procedure**

1. Use [openSession](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#opensession8) to open a session for credential management.

   ```ts
   let challenge: Uint8Array = await userIDM.openSession();
   ```

## Enrolling a PIN

Use [addCredential](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#addcredential8) to enroll a PIN.

**Procedure**

1. Defines the PIN authentication credential.

   ```ts
   let credentialInfo: osAccount.CredentialInfo = {
     credType: osAccount.AuthType.PIN,
     credSubType: osAccount.AuthSubType.PIN_SIX;
     token: new Uint8Array([0])
   };
   ```

2. Use [addCredential](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#addcredential8) to add credential information. The credential is returned by a callback or promise.

   ```ts
   userIDM.addCredential(credentialInfo, {
     onResult: (code: number, result: osAccount.RequestResult) => {
       console.log('addCredential code = ' + code);
       console.log('addCredential result = ' + result);
     }
   });
   ```

## Authenticating a PIN

Use [auth](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#auth8) to perform PIN authentication.

**Procedure**

1. Set authentication parameters, including the challenge value, authentication type, and authentication trust level.

   ```ts
   let challenge: Uint8Array = new Uint8Array([1, 2, 3, 4, 5]);
   let authType: osAccount.AuthType = osAccount.AuthType.PIN;
   let authTrustLevel: osAccount.AuthTrustLevel = osAccount.AuthTrustLevel.ATL1;
   ```

2. Use [auth](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#auth8) to perform PIN authentication.

   ```ts
   let userAuth: osAccount.UserAuth = new osAccount.UserAuth();
   userAuth.auth(challenge, authType, authTrustLevel, {
     onResult: (result: number, extraInfo: osAccount.AuthResult) => {
       console.log('pin auth result = ' + result);
       console.log('pin auth extraInfo = ' + JSON.stringify(extraInfo));
       let authToken = extraInfo.token;
     }
   });
   ```

## Enrolling Biometric Credentials

Biometric credentials such as face and fingerprint can be enrolled after the PIN authentication is successful. The enrollment process is similar to the PIN enrollment process.

**Procedure**

1. Perform PIN authentication to obtain the authorization token (**authToken**).

2. Set face credential information. The following uses 2D face credential as an example.

   ```ts
   let faceCredInfo: osAccount.CredentialInfo = {
     credType: osAccount.AuthType.FACE,
     credSubType: osAccount.AuthSubType.FACE_2D,
     token: new Uint8Array([1, 2, 3, 4, 5])
   }
   ```

3. Use [addCredential](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#addcredential8) to enroll face credentials.

   ```ts
   userIDM.addCredential(faceCredInfo, {
     onResult: (code: number, result: osAccount.RequestResult) => {
       console.log('add face credential, resultCode: ' + code);
       console.log('add face credential, request result: ' + result);
     }
   });
   ```

4. Set fingerprint credential information.

   ```ts
   let fingerprintCredInfo: osAccount.CredentialInfo = {
     credType: osAccount.AuthType.FINGERPRINT,
     credSubType: osAccount.AuthSubType.FINGERPRINT_CAPACITIVE,
     token: new Uint8Array([1, 2, 3, 4, 5])
   }
   ```

5. Use [addCredential](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#addcredential8) to enroll the fingerprint.

   ```ts
   userIDM.addCredential(fingerprintCredInfo, {
     onResult: (code: number, result: osAccount.RequestResult) => {
       console.log('add fingerprint credential, resultCode: ' + code);
       console.log('add fingerprint credential, request result: ' + result);
     }
   });
   ```

## Authenticating Biometric Credentials

Biometric authentication can be performed after the biometric credentials are enrolled. You can use [auth](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#auth8) to perform biometric authentication.

**Procedure**

1. Set authentication parameters, including the challenge value, authentication type, and authentication trust level. The following uses facial authentication as an example.

   ```ts
   let challenge: Uint8Array = new Uint8Array([1, 2, 3, 4, 5]);
   let authType: osAccount.AuthType = osAccount.AuthType.FACE;
   let authTrustLevel: osAccount.AuthTrustLevel = osAccount.AuthTrustLevel.ATL1;
   ```

2. Use **auth()** to perform authentication.

   ```ts
   let userAuth: osAccount.UserAuth = new osAccount.UserAuth();
   userAuth.auth(challenge, authType, authTrustLevel, {
     onResult: (result: number, extraInfo: osAccount.AuthResult) => {
       console.log('face auth result = ' + result);
       console.log('face auth extraInfo = ' + JSON.stringify(extraInfo));
     }
   });
   ```

## Updating a Credential

The user can update credentials as required. You can use [updateCredential](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#updatecredential8) to update credential information.

**Procedure**

1. Perform PIN authentication to obtain the authorization token (**authToken**).

2. Specify the credential information to be updated.

   ```ts
   let credentialInfo: osAccount.CredentialInfo = {
     credType: osAccount.AuthType.PIN,
     credSubType: osAccount.AuthSubType.PIN_SIX,
     token: new Uint8Array([1, 2, 3, 4, 5])
   };
   ```

3. Use [updateCredential](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#updatecredential8) to update the credential.  

   ```ts
   userIDM.updateCredential(credentialInfo, {
     onResult: (result: number, extraInfo: osAccount.RequestResult) => {
       console.log('updateCredential result = ' + result);
       console.log('updateCredential extraInfo = ' + extraInfo);
     }
   });
   ```

## Obtaining Credential Information

The enrolled credentials need to be displayed on the credential management page, and the available credential types need to be displayed on the lock screen page. You can use [getAuthInfo](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#getauthinfo8) to obtain the credential information to be displayed.

**Procedure**

1. Obtain information about all the credentials enrolled.

   ```ts
   let enrolledCredInfoList: osAccount.EnrolledCredInfo[] = await userIDM.getAuthInfo();
   ```

2. Use [getAuthInfo](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#getauthinfo8) to obtain the credential of the specified type. In the following example, the fingerprint enrolled is obtained.

   ```ts
   let enrolledFingerCredInfoList: osAccount.EnrolledCredInfo[] = await userIDM.getAuthInfo(osAccount.AuthType.FINGERPRINT);
   ```

## Deleting a Credential

Before a credential is deleted, [PIN Authentication](#authenticating-a-pin) is required and the ID of the credential to be deleted needs to be [obtained](#obtaining-credential-information).

For example, delete a fingerprint, do as follows:

1. Obtain the fingerprint information.

   ```ts
   let credentialId: Uint8Array = new Uint8Array([1, 2, 3, 4, 5]);
   let token: Uint8Array = new Uint8Array([1, 2, 3, 4, 5])
   let credInfoList: osAccount.EnrolledCredInfo[] = await userIDM.getAuthInfo(osAccount.AuthType.FINGERPRINT);
   if (credInfoList.length != 0) {
     credentialId = credInfoList[0].credentialId;
   }
   ```

2. [Perform PIN authentication](#authenticating-a-pin) to obtain the authentication token.

3. Use [delCred](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#delcred8) to delete the fingerprint credential.

   ```ts
   userIDM.delCred(credentialId, token, {
     onResult: (result: number, extraInfo: osAccount.RequestResult) => {
       console.log('delCred result = ' + result);
       console.log('delCred extraInfo = ' + JSON.stringify(extraInfo));
     }
   });
   ```

## Unregistering a PIN Inputer

Use [unregisterInputer](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#unregisterinputer8) to unregister the PIN inputer that is no longer required.

**Procedure**

```ts
pinAuth.unregisterInputer();
```

## Closing a Session

Use [closeSession](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#closesession8) to close a session to terminate credential management.

**Procedure**

```ts
userIDM.closeSession();
```
