# Authenticating a Domain Account (for System Applications Only)

<!--Kit: Basic Services Kit-->
<!--Subsystem: Account-->
<!--Owner: @steven-q-->
<!--Designer: @JiDong-CS1-->
<!--Tester: @zhaimengchao-->
<!--Adviser: @zengyawen-->

Authenticate a domain account before unlocking the screen or when the login session fails.

## Before You Start

Import the **osAccount** module.

```ts
import { osAccount } from '@kit.BasicServicesKit';
```

## Domain Account Authentication by Password

The domain account can be authenticated by password. You can use [auth](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#auth10) to implement this operation. To call this API, the application must have the ohos.permission.ACCESS_USER_AUTH_INTERNAL permission.

**Procedure**

1. Request the ohos.permission.ACCESS_USER_AUTH_INTERNAL permission. For details about how to request the permission, see [Requesting Permissions for system_basic Applications](../../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

2. Obtain user input information, including the domain account and its password.

   ```ts
     let domainAccountInfo: osAccount.DomainAccountInfo = {
       domain: 'CHINA',
       accountName: 'zhangsan'
     }
     let credential: Uint8Array = new Uint8Array([0]);
   ```

3. Define the callback used to return the authentication result.

   ```ts
   let callback: osAccount.IUserAuthCallback = {
     onResult: (resultCode: number, authResult: osAccount.AuthResult) => {
       console.log('auth resultCode = ' + resultCode);
       console.log('auth authResult = ' + JSON.stringify(authResult));
     }
   }
   ```

4. Use [auth](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#auth10) to authenticate the domain account by password.

   ```ts
   try {
     osAccount.DomainAccountManager.auth(domainAccountInfo, credential, callback);
   } catch (err) {
     console.error('auth exception = ' + JSON.stringify(err));
   }
   ```

## Domain Account Authentication by Dialog

If the domain account password is unavailable, display a dialog box to authentication the domain account. You can use [authWithPopup](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#authwithpopup10) to implement this operation.

**Procedure**

1. Define the callback used to return the authentication result.

   ```ts
   let callback: osAccount.IUserAuthCallback = {
     onResult: (resultCode: number, authResult: osAccount.AuthResult) => {
       console.log('authWithPopup resultCode = ' + resultCode);
       console.log('authWithPopup authResult = ' + JSON.stringify(authResult));
     }
   }
   ```

2. Use [authWithPopup](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#authwithpopup10) to authenticate the domain account in a dialog box displayed.

   ```ts
   try {
     osAccount.DomainAccountManager.authWithPopup(callback)
   } catch (err) {
     console.error('authWithPopup exception = ' + JSON.stringify(err));
   }
   ```
