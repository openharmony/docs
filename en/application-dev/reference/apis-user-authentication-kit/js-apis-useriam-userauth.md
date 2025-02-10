# @ohos.userIAM.userAuth (User Authentication)

The **userIAM.userAuth** module provides user authentication capabilities in identity authentication scenarios, such as device unlocking, payment, and app login.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { userAuth } from '@kit.UserAuthenticationKit';
```

## Constant

Represents the maximum period for which the device unlocking result can be reused.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name       | Value  | Description      |
| ----------- | ---- | ---------- |
| MAX_ALLOWABLE_REUSE_DURATION<sup>12+</sup>    | 300000   | Maximum period for which the device unlocking result can be reused. The value is **300,000** ms.|

## EnrolledState<sup>12+</sup>

Represents information about the enrolled credentials.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name        | Type   | Readable| Writable| Description                |
| ------------ | ---------- | ---- | ---- | -------------------- |
| credentialDigest       | number | Yes  |  No| Credential digest, which is randomly generated when a credential is added.|
| credentialCount        | number | Yes  |  No| Number of enrolled credentials.      |

## ReuseMode<sup>12+</sup>

Represents the mode for reusing the device unlocking result.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name       | Value  | Description      |
| ----------- | ---- | ---------- |
| AUTH_TYPE_RELEVANT    | 1   | The device unlocking result can be reused within the validity period if the authentication type matches any of the authentication types specified for this authentication.<br> **Atomic service API**: This API can be used in atomic services since API version 12.|
| AUTH_TYPE_IRRELEVANT  | 2   | The device unlocking result can be reused within the validity period regardless of the authentication type.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| CALLER_IRRELEVANT_AUTH_TYPE_RELEVANT<sup>14+</sup>    | 3   | Any identity authentication (including device unlocking) result can be reused within the validity period if the authentication type matches any of the authentication types specified for this authentication.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| CALLER_IRRELEVANT_AUTH_TYPE_IRRELEVANT<sup>14+</sup>  | 4   | Any identity authentication (including device unlocking) result can be reused within the validity period regardless of the authentication type.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|

## ReuseUnlockResult<sup>12+</sup>

Represents the device unlocking result.
> **NOTE**
>
> If the credential changes within the validity period after the screen is unlocked, the screen lock authentication result can still be reused, and the actual **EnrolledState** is returned in the authentication result. If the credential is completely deleted when the lock screen authentication result is reused,
> both **credentialCount** and **credentialDigest** in **EnrolledState** are **0**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name        | Type  | Mandatory| Description                |
| ------------ | ---------- | ---- | -------------------- |
| reuseMode        | [ReuseMode](#reusemode12) | Yes  | Mode for reusing the device unlocking result.      |
| reuseDuration    | number | Yes  | Period for which the device unlocking result can be reused. <br>Value range: 0 to [MAX_ALLOWABLE_REUSE_DURATION](#constant)|

## userAuth.getEnrolledState<sup>12+</sup>

getEnrolledState(authType : UserAuthType): EnrolledState

Obtains information about the credentials enrolled. With this API, you can obtain the change of the credentials. 

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name        | Type                              | Mandatory| Description                      |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| authType       | [UserAuthType](#userauthtype8)     | Yes  | Authentication type.|

**Return value**

| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| [EnrolledState](#enrolledstate12) | Information about the enrolled credentials.|

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID| Error Message|
| -------- | ------- |
| 201 | Permission verification failed. |
| 401 | Incorrect parameters. Possible causes: 1.Mandatory parameters are left unspecified. |
| 12500002 | General operation error. |
| 12500005 | The authentication type is not supported. |
| 12500010 | The type of credential has not been enrolled. |

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  let enrolledState = userAuth.getEnrolledState(userAuth.UserAuthType.FACE);
  console.info(`get current enrolled state success, enrolledState = ${JSON.stringify(enrolledState)}`);
} catch (error) {
  console.error(`get current enrolled state failed, error = ${JSON.stringify(error)}`);
}
```

## AuthParam<sup>10+</sup>

Defines the user authentication parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name          | Type                              | Mandatory| Description                                                        |
| -------------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| challenge      | Uint8Array                         | Yes  | Random challenge value, which is used to prevent replay attacks. It cannot exceed 32 bytes and can be passed in **Uint8Array([])** format.|
| authType       | [UserAuthType](#userauthtype8)[]   | Yes  | Authentication type list, which specifies the types of authentication provided on the user authentication page.          |
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8) | Yes  | Authentication trust level.                                              |
| reuseUnlockResult<sup>12+</sup> | [ReuseUnlockResult](#reuseunlockresult12) | No  |Device unlocking result that can be reused.|

## WidgetParam<sup>10+</sup>

Represents the information presented on the user authentication page.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name                | Type                               | Mandatory| Description                                                        |
| -------------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| title                | string                              | Yes  | Title of the user authentication page. It cannot exceed 500 characters.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| navigationButtonText | string                              | No  | Text on the navigation button. It cannot exceed 60 characters. This parameter is valid only in fingerprint or facial authentication only.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| uiContext<sup>16+</sup>            | Context               | No  | Whether to display the authentication dialog box in modal application mode. This mode is applicable only to 2-in-1 devices. If this mode is not used or other types of devices are used, the authentication dialog box is displayed in modal system mode.<br>**Atomic service API**: This API can be used in atomic services since API version 16.|

## UserAuthResult<sup>10+</sup>

Represents the user authentication result. If the authentication is successful, the authentication type and token information are returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name    | Type                          | Mandatory| Description                                                        |
| -------- | ------------------------------ | ---- | ------------------------------------------------------------ |
| result   | number                         | Yes  | User authentication result. If the operation is successful, **SUCCESS** is returned. If the operation fails, an error code is returned. For details, see [UserAuthResultCode](#userauthresultcode9).|
| token    | Uint8Array                     | No  | Token that has passed the authentication.                |
| authType | [UserAuthType](#userauthtype8) | No  | Type of the authentication.                          |
| enrolledState<sup>12+</sup> | [EnrolledState](#enrolledstate12) | No  |  Enrolled credential information.        |

## IAuthCallback<sup>10+</sup>

Provides callbacks to return the authentication result.

### onResult<sup>10+</sup>

onResult(result: UserAuthResult): void

Called to return the authentication result. If the authentication is successful, the token information can be obtained from **UserAuthResult**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name| Type                               | Mandatory| Description      |
| ------ | ----------------------------------- | ---- | ---------- |
| result | [UserAuthResult](#userauthresult10) | Yes  | Authentication result.|

**Example 1**

Initiate facial authentication and lock screen password authentication with the authentication trust level greater than or equal to ATL3.

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  const randData: Uint8Array = rand?.generateRandomSync(len)?.data;
  const authParam: userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
  };
  const widgetParam: userAuth.WidgetParam = {
    title:'Enter password',
  };

  const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
  // The authentication result is returned by onResult only after the authentication is started by start() of UserAuthInstance.
  userAuthInstance.on('result', {
    onResult (result) {
      console.info(`userAuthInstance callback result = ${JSON.stringify(result)}`);
    }
  });
  console.info('auth on success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

**Example 2**

Initiate facial authentication with the authentication trust level greater than or equal to ATL3, and enable the device unlock result to be reused for the same type of authentication within the specified time.

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

let reuseUnlockResult: userAuth.ReuseUnlockResult = {
  reuseMode: userAuth.ReuseMode.AUTH_TYPE_RELEVANT,
  reuseDuration: userAuth.MAX_ALLOWABLE_REUSE_DURATION,
}
try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  const randData: Uint8Array = rand?.generateRandomSync(len)?.data;
  const authParam: userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
    reuseUnlockResult: reuseUnlockResult,
  };
  const widgetParam: userAuth.WidgetParam = {
    title:'Enter password',
  };
  const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
  // The authentication result is returned by onResult only after the authentication is started by start() of UserAuthInstance.
  userAuthInstance.on('result', {
    onResult (result) {
      console.info(`userAuthInstance callback result = ${JSON.stringify(result)}`);
    }
  });
  console.info('auth on success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

**Example 3**

Initiate facial authentication with the authentication trust level greater than or equal to ATL3, and enable the device unlock result to be reused for any type of authentication within the maximum authentication validity of any application.

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

let reuseUnlockResult: userAuth.ReuseUnlockResult = {
  reuseMode: userAuth.ReuseMode.CALLER_IRRELEVANT_AUTH_TYPE_RELEVANT,
  reuseDuration: userAuth.MAX_ALLOWABLE_REUSE_DURATION,
}
try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  const randData: Uint8Array = rand?.generateRandomSync(len)?.data;
  const authParam: userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
    reuseUnlockResult: reuseUnlockResult,
  };
  const widgetParam: userAuth.WidgetParam = {
    title:'Enter password',
  };
  const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
  // The authentication result is returned by onResult only after the authentication is started by start() of UserAuthInstance.
  userAuthInstance.on('result', {
    onResult (result) {
      console.info(`userAuthInstance callback result = ${JSON.stringify(result)}`);
    }
  });
  console.info('auth on success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

## UserAuthInstance<sup>10+</sup>

Provides APIs for user authentication. The user authentication widget is supported.
Before using the APIs, you need to obtain a **UserAuthInstance** instance by using [getUserAuthInstance](#userauthgetuserauthinstance10).

### on<sup>10+</sup>

on(type: 'result', callback: IAuthCallback): void

Subscribes to the user authentication result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name  | Type                             | Mandatory| Description                                      |
| -------- | --------------------------------- | ---- | ------------------------------------------ |
| type     | 'result'                          | Yes  | Event type. The value is **result**, which indicates the authentication result.|
| callback | [IAuthCallback](#iauthcallback10) | Yes  | Callback used to return the user authentication result.    |

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID| Error Message                |
| -------- | ------------------------ |
| 401      | Incorrect parameters. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 12500002 | General operation error. |

**Example 1**

Perform user identity authentication in modal system mode.

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  const randData: Uint8Array = rand?.generateRandomSync(len)?.data;
  const authParam: userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
  };
  const widgetParam: userAuth.WidgetParam = {
    title:'Enter password',
  };
  const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
  // The authentication result is returned by onResult only after the authentication is started by start() of UserAuthInstance.
  userAuthInstance.on('result', {
    onResult (result) {
      console.info(`userAuthInstance callback result = ${JSON.stringify(result)}`);
    }
  });
  console.info('auth on success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

**Example 2**

Perform user identity authentication in modal application mode.

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  const randData: Uint8Array = rand?.generateRandomSync(len)?.data;
  const authParam: userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
  };
  const widgetParam: userAuth.WidgetParam = {
    title:'Enter password',
    uiContext: this.getUIContext().getHostContext(),
  };
  const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
  // The authentication result is returned by onResult only after the authentication is started by start() of UserAuthInstance.
  userAuthInstance.on('result', {
    onResult (result) {
      console.info(`userAuthInstance callback result = ${JSON.stringify(result)}`);
    }
  });
  console.info('auth on success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

### off<sup>10+</sup>

off(type: 'result', callback?: IAuthCallback): void

Unsubscribes from the user authentication result.

> **NOTE**
> 
> The [UserAuthInstance](#userauthinstance10) instance used to invoke this API must be the one used to subscribe to the event.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name  | Type                             | Mandatory| Description                                      |
| -------- | --------------------------------- | ---- | ------------------------------------------ |
| type     | 'result'                          | Yes  | Event type. The value is **result**, which indicates the authentication result.|
| callback | [IAuthCallback](#iauthcallback10) | No  | Callback to unregister.    |

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID| Error Message                |
| -------- | ------------------------ |
| 401      | Incorrect parameters. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 12500002 | General operation error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  const randData: Uint8Array = rand?.generateRandomSync(len)?.data;
  const authParam: userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
  };
  const widgetParam: userAuth.WidgetParam = {
    title:'Enter password',
  };
  const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
  userAuthInstance.off('result', {
    onResult (result) {
      console.info(`auth off result = ${JSON.stringify(result)}`);
    }
  });
  console.info('auth off success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

### start<sup>10+</sup>

start(): void

Starts authentication.

> **NOTE**<br>
> A **UserAuthInstance** instance can be used for an authentication only once.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID| Error Message                                        |
| -------- | ------------------------------------------------ |
| 201      | Permission verification failed.                  |
| 401      | Incorrect parameters. Possible causes: 1.Incorrect parameter types. |
| 12500001 | Authentication failed.                           |
| 12500002 | General operation error.                         |
| 12500003 | Authentication canceled.                         |
| 12500004 | Authentication timeout.                          |
| 12500005 | The authentication type is not supported.        |
| 12500006 | The authentication trust level is not supported. |
| 12500007 | Authentication service is busy.                  |
| 12500009 | Authentication is locked out.                    |
| 12500010 | The type of credential has not been enrolled.    |
| 12500011 | Switched to the custom authentication process.   |
| 12500013 | Operation failed because of PIN expired. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  const randData: Uint8Array = rand?.generateRandomSync(len)?.data;
  const authParam: userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
  };
  const widgetParam: userAuth.WidgetParam = {
    title:'Enter password',
  };
  const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
  userAuthInstance.start();
  console.info('auth start success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

### cancel<sup>10+</sup>

cancel(): void

Cancels this authentication.

> **NOTE**
>
> **UserAuthInstance** must be the instance being authenticated.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Error codes**

| ID| Error Message                       |
| -------- | ------------------------------- |
| 201      | Permission verification failed. |
| 401      | Incorrect parameters. Possible causes: 1.Incorrect parameter types. |
| 12500002 | General operation error.        |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  const randData: Uint8Array = rand?.generateRandomSync(len)?.data;
  const authParam : userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
  };
  const widgetParam: userAuth.WidgetParam = {
    title:'Enter password',
  };
  const userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
  // The cancel() API can be called only after the authentication is started by start() of UserAuthInstance.
  userAuthInstance.cancel();
  console.info('auth cancel success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

## userAuth.getUserAuthInstance<sup>10+</sup>

getUserAuthInstance(authParam: AuthParam, widgetParam: WidgetParam): UserAuthInstance

Obtains a [UserAuthInstance](#userauthinstance10) instance for user authentication. The user authentication widget is also supported.

> **NOTE**<br>
> A **UserAuthInstance** instance can be used for an authentication only once.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name     | Type                         | Mandatory| Description                      |
| ----------- | ----------------------------- | ---- | -------------------------- |
| authParam   | [AuthParam](#authparam10)      | Yes  | User authentication parameters.        |
| widgetParam | [WidgetParam](#widgetparam10) | Yes  | Parameters on the user authentication page.|

**Return value**

| Type                                   | Description                      |
| --------------------------------------- | -------------------------- |
| [UserAuthInstance](#userauthinstance10) | **UserAuthInstance** instance that supports UI.|

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID| Error Message                                        |
| -------- | ------------------------------------------------ |
| 401      | Incorrect parameters. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.   |
| 12500002 | General operation error.                         |
| 12500005 | The authentication type is not supported.        |
| 12500006 | The authentication trust level is not supported. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  const randData: Uint8Array = rand?.generateRandomSync(len)?.data;
  const authParam: userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
  };
  const widgetParam: userAuth.WidgetParam = {
    title:'Enter password',
  };
  let userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
  console.info('get userAuth instance success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

## AuthResultInfo<sup>(deprecated)</sup>

Defines the authentication result.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 11.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name        | Type  | Mandatory| Description                |
| ------------ | ---------- | ---- | -------------------- |
| result        | number | Yes  | Authentication result.      |
| token        | Uint8Array | No  | Token that has passed the user identity authentication.|
| remainAttempts  | number     | No  | Number of remaining authentication attempts.|
| lockoutDuration | number     | No  | Lock duration of the authentication operation, in ms.|

## TipInfo<sup>(deprecated)</sup>

Defines the authentication tip information.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 11.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name        | Type  | Mandatory| Description                |
| ------------ | ---------- | ---- | -------------------- |
| module        | number | Yes  | ID of the module that sends the tip information.      |
| tip        | number | Yes  | Tip to be given during the authentication process.      |

## EventInfo<sup>(deprecated)</sup>

type EventInfo = AuthResultInfo | TipInfo

Enumerates the authentication event information types.

The event information type consists of the fields in **Type** in the following table.

> **NOTE**<br>
> This parameter is supported since API version 9 and deprecated since API version 11. Use [UserAuthResult](#userauthresult10) instead.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Type   | Description                      |
| --------- | ----------------------- |
| [AuthResultInfo](#authresultinfodeprecated)    | Authentication result. |
| [TipInfo](#tipinfodeprecated)    | Authentication tip information.     |

## AuthEventKey<sup>(deprecated)</sup>

type AuthEventKey = 'result' | 'tip'

Defines the keyword of the authentication event type. It is used as a parameter of [on](#ondeprecated).

It consists of the fields in **Type** in the following table.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 11.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Type      | Description                   |
| ---------- | ----------------------- |
| 'result' | If the first parameter of [on](#ondeprecated) is **result**, the [callback](#callbackdeprecated) returns the authentication result.|
| 'tip'    | If the first parameter of [on](#ondeprecated) is **tip**, the [callback](#callbackdeprecated) returns the authentication tip information.|

## AuthEvent<sup>(deprecated)</sup>

Provides an asynchronous callback to return the authentication event information.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 11. Use [IAuthCallback](#iauthcallback10) instead.

### callback<sup>(deprecated)</sup>

callback(result : EventInfo) : void

Called to return the authentication result or authentication tip information.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 11. Use [onResult](#onresult10) instead.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type                      | Mandatory| Description                          |
| --------- | -------------------------- | ---- | ------------------------------ |
| result    | [EventInfo](#eventinfodeprecated)     | Yes  | Authentication result or tip information. |

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userAuth.UserAuthType.FACE;
let authTrustLevel = userAuth.AuthTrustLevel.ATL1;
// Obtain the authentication result through a callback.
try {
  let auth = userAuth.getAuthInstance(challenge, authType, authTrustLevel);
  auth.on('result', {
    callback: (result: userAuth.AuthResultInfo) => {
      console.info(`authV9 result ${result.result}`);
      console.info(`authV9 token ${result.token}`);
      console.info(`authV9 remainAttempts ${result.remainAttempts}`);
      console.info(`authV9 lockoutDuration ${result.lockoutDuration}`);
    }
  } as userAuth.AuthEvent);
  auth.start();
  console.info('authV9 start success');
} catch (error) {
  console.error(`authV9 error = ${error}`);
  // do error
}
// Obtain the authentication tip information through a callback.
try {
  let auth = userAuth.getAuthInstance(challenge, authType, authTrustLevel);
  auth.on('tip', {
    callback : (result : userAuth.TipInfo) => {
      switch (result.tip) {
        case userAuth.FaceTips.FACE_AUTH_TIP_TOO_BRIGHT:
          // Do something.
        case userAuth.FaceTips.FACE_AUTH_TIP_TOO_DARK:
          // Do something.
        default:
          // Do others.
      }
    }
  } as userAuth.AuthEvent);
  auth.start();
  console.info('authV9 start success');
} catch (error) {
  console.error(`authV9 error = ${error}`);
  // do error
}
```

## AuthInstance<sup>(deprecated)</sup>

Implements user authentication.

> **NOTE**<br>
> This API is supported since API version 9 and deprecated since API version 10. Use [UserAuthInstance](#userauthinstance10) instead.

### on<sup>(deprecated)</sup>

on : (name : AuthEventKey, callback : AuthEvent) => void

Subscribes to the user authentication events of the specified type.

> **NOTE**<br>
> - This API is supported since API version 9 and deprecated since API version 10.
> - Use the [AuthInstance](#authinstancedeprecated) instance obtained to call this API.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type                       | Mandatory| Description                      |
| --------- | -------------------------- | ---- | ------------------------- |
| name  | [AuthEventKey](#autheventkeydeprecated) | Yes  | Authentication event type. If the value is **result**, the callback returns the authentication result. If the value is **tip**, the callback returns the authentication tip information.|
| callback  | [AuthEvent](#autheventdeprecated)   | Yes  | Callback used to return the authentication result or tip information.|

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID| Error Message|
| -------- | ------- |
| 401 | Incorrect parameters. |
| 12500002 | General operation error. |

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userAuth.UserAuthType.FACE;
let authTrustLevel = userAuth.AuthTrustLevel.ATL1;
try {
  let auth = userAuth.getAuthInstance(challenge, authType, authTrustLevel);
  // Subscribe to the authentication result.
  auth.on('result', {
    callback: (result: userAuth.AuthResultInfo) => {
      console.info(`authV9 result ${result.result}`);
      console.info(`authV9 token ${result.token}`);
      console.info(`authV9 remainAttempts ${result.remainAttempts}`);
      console.info(`authV9 lockoutDuration ${result.lockoutDuration}`);
    }
  });
  // Subscribe to authentication tip information.
  auth.on('tip', {
    callback : (result : userAuth.TipInfo) => {
      switch (result.tip) {
        case userAuth.FaceTips.FACE_AUTH_TIP_TOO_BRIGHT:
          // Do something.
        case userAuth.FaceTips.FACE_AUTH_TIP_TOO_DARK:
          // Do something.
        default:
          // Do others.
      }
    }
  } as userAuth.AuthEvent);
  auth.start();
  console.info('authV9 start success');
} catch (error) {
  console.error(`authV9 error = ${error}`);
  // do error
}
```

### off<sup>(deprecated)</sup>

off : (name : AuthEventKey) => void

Unsubscribes from the user authentication events of the specific type.

> **NOTE**<br>
> - This API is supported since API version 9 and deprecated since API version 10.
> - The [AuthInstance](#authinstancedeprecated) instance used to call this API must be the one used to subscribe to the events.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name   | Type                       | Mandatory| Description                      |
| --------- | -------------------------- | ---- | ------------------------- |
| name    | [AuthEventKey](#autheventkeydeprecated)      | Yes  | Authentication event type. If the value is **result**, the authentication result is unsubscribed from. If the value is **tip**, the authentication tip information is unsubscribed from.|

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID| Error Message|
| -------- | ------- |
| 401 | Incorrect parameters. |
| 12500002 | General operation error. |

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userAuth.UserAuthType.FACE;
let authTrustLevel = userAuth.AuthTrustLevel.ATL1;
try {
  let auth = userAuth.getAuthInstance(challenge, authType, authTrustLevel);
  // Subscribe to the authentication result.
  auth.on('result', {
    callback: (result: userAuth.AuthResultInfo) => {
      console.info(`authV9 result ${result.result}`);
      console.info(`authV9 token ${result.token}`);
      console.info(`authV9 remainAttempts ${result.remainAttempts}`);
      console.info(`authV9 lockoutDuration ${result.lockoutDuration}`);
    }
  });
  // Unsubscription result.
  auth.off('result');
  console.info('cancel subscribe authentication event success');
} catch (error) {
  console.error(`cancel subscribe authentication event failed, error = ${error}`);
  // do error
}
```

### start<sup>(deprecated)</sup>

start : () => void

Starts authentication.

> **NOTE**<br>
> - This API is supported since API version 9 and deprecated since API version 10.
> - Use the [AuthInstance](#authinstancedeprecated) instance obtained to call this API.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID| Error Message|
| -------- | ------- |
| 201 | Permission verification failed. |
| 401 | Incorrect parameters. |
| 12500001 | Authentication failed. |
| 12500002 | General operation error. |
| 12500003 | The operation is canceled. |
| 12500004 | The operation is time-out.  |
| 12500005 | The authentication type is not supported. |
| 12500006 | The authentication trust level is not supported. |
| 12500007 | The authentication task is busy. |
| 12500009 | The authenticator is locked. |
| 12500010 | The type of credential has not been enrolled. |

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userAuth.UserAuthType.FACE;
let authTrustLevel = userAuth.AuthTrustLevel.ATL1;

try {
  let auth = userAuth.getAuthInstance(challenge, authType, authTrustLevel);
  auth.start();
  console.info('authV9 start auth success');
} catch (error) {
  console.error(`authV9 start auth failed, error = ${error}`);
}
```

### cancel<sup>(deprecated)</sup>

cancel : () => void

Cancels this authentication.

> **NOTE**<br>
>
> - This API is supported since API version 9 and deprecated since API version 10.
> - Use the [AuthInstance](#authinstancedeprecated) instance obtained to invoke this API. The [AuthInstance](#authinstancedeprecated) instance must be the instance being authenticated.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID| Error Message|
| -------- | ------- |
| 201 | Permission verification failed. |
| 401 | Incorrect parameters. |
| 12500002 | General operation error. |

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userAuth.UserAuthType.FACE;
let authTrustLevel = userAuth.AuthTrustLevel.ATL1;

try {
  let auth = userAuth.getAuthInstance(challenge, authType, authTrustLevel);
  auth.cancel();
  console.info('cancel auth success');
} catch (error) {
  console.error(`cancel auth failed, error = ${error}`);
}
```

## userAuth.getAuthInstance<sup>(deprecated)</sup>

getAuthInstance(challenge : Uint8Array, authType : UserAuthType, authTrustLevel : AuthTrustLevel): AuthInstance

Obtains an **AuthInstance** instance for user authentication.

> **NOTE**<br>
>
> - This API is supported since API version 9 and deprecated since API version 10. Use [getUserAuthInstance](#userauthgetuserauthinstance10) instead.
> - An **AuthInstance** instance can be used for an authentication only once.


**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name        | Type                                    | Mandatory| Description                    |
| -------------- | ---------------------------------------- | ---- | ------------------------ |
| challenge      | Uint8Array                               | Yes  | Challenge value. It cannot exceed 32 bytes and can be passed in Uint8Array([]) format.|
| authType       | [UserAuthType](#userauthtype8)           | Yes  | Authentication type. Currently, **FACE** and **FINGERPRINT** are supported.|
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8)       | Yes  | Authentication trust level.              |

**Return value**

| Type                                   | Description        |
| --------------------------------------- | ------------ |
| [AuthInstance](#authinstancedeprecated) | **AuthInstance** instance obtained.|

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID| Error Message|
| -------- | ------- |
| 401 | Incorrect parameters. |
| 12500002 | General operation error. |
| 12500005 | The authentication type is not supported. |
| 12500006 | The authentication trust level is not supported. |

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let challenge = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8]);
let authType = userAuth.UserAuthType.FACE;
let authTrustLevel = userAuth.AuthTrustLevel.ATL1;

try {
  let auth = userAuth.getAuthInstance(challenge, authType, authTrustLevel);
  console.info('let auth instance success');
} catch (error) {
  console.error(`get auth instance success failed, error = ${error}`);
}
```

## userAuth.getAvailableStatus<sup>9+</sup>

getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel): void

Checks whether the specified authentication capability is supported.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name        | Type                              | Mandatory| Description                      |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| authType       | [UserAuthType](#userauthtype8)     | Yes  | Authentication type. PIN is supported since API version 11.|
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8) | Yes  | Authentication trust level.      |

> The mechanism for returning the error code is as follows:
>
> - The error code 12500005 is returned if the corresponding executor is not registered.
> - The error code 12500006 is returned if the corresponding executor is registered, the function is not disabled, but the authentication security level is lower than that specified for the service.
> - The error code 12500010 is returned if the corresponding executor is registered, the function is not disabled, but the user has not enrolled the credential.
> - The error code 12500013 is returned if the corresponding executor is registered, the function is not disabled, but the PIN has expired.

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID| Error Message|
| -------- | ------- |
| 201 | Permission verification failed. |
| 401 | Incorrect parameters. Possible causes: 1.Mandatory parameters are left unspecified. |
| 12500002 | General operation error. |
| 12500005 | The authentication type is not supported. |
| 12500006 | The authentication trust level is not supported. |
| 12500010 | The type of credential has not been enrolled. |
| 12500013 | Operation failed because of PIN expired. |

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  userAuth.getAvailableStatus(userAuth.UserAuthType.FACE, userAuth.AuthTrustLevel.ATL1);
  console.info('current auth trust level is supported');
} catch (error) {
  console.error(`current auth trust level is not supported, error = ${error}`);
}
```

## UserAuthResultCode<sup>9+</sup>

Enumerates the authentication result codes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name                   |   Value  | Description                |
| ----------------------- | ------ | -------------------- |
| SUCCESS                 | 12500000      | The authentication is successful.          |
| FAIL                    | 12500001      | The authentication failed.          |
| GENERAL_ERROR           | 12500002      | A general operation error occurred.      |
| CANCELED                | 12500003      | The authentication is canceled.          |
| TIMEOUT                 | 12500004      | The authentication timed out.          |
| TYPE_NOT_SUPPORT        | 12500005      | The authentication type is not supported.  |
| TRUST_LEVEL_NOT_SUPPORT | 12500006      | The authentication trust level is not supported.  |
| BUSY                    | 12500007      | Indicates the busy state.          |
| LOCKED                  | 12500009      | The authentication executor is locked.      |
| NOT_ENROLLED            | 12500010      | The user has not entered the authentication information.|
| CANCELED_FROM_WIDGET<sup>10+</sup> | 12500011 | The authentication is canceled by the user from the user authentication widget. If this error code is returned, the authentication is customized by the application.|
| PIN_EXPIRED<sup>12+</sup> | 12500013 | The authentication failed because the lock screen password has expired.|

## UserAuth<sup>(deprecated)</sup>

Provides APIs for user authentication.

### constructor<sup>(deprecated)</sup>

constructor()

A constructor used to create a **UserAuth** instance.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. Use [getAuthInstance](#userauthgetauthinstancedeprecated) instead.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let auth = new userAuth.UserAuth();
```

### getVersion<sup>(deprecated)</sup>

getVersion() : number

Obtains the version of this authenticator.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Return value**

| Type  | Description                  |
| ------ | ---------------------- |
| number | Authenticator version obtained.|

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let auth = new userAuth.UserAuth();
let version = auth.getVersion();
console.info(`auth version = ${version}`);
```

### getAvailableStatus<sup>(deprecated)</sup>

getAvailableStatus(authType : UserAuthType, authTrustLevel : AuthTrustLevel) : number

Checks whether the specified authentication capability is supported.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. Use [getAvailableStatus](#userauthgetavailablestatus9) instead.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name        | Type                              | Mandatory| Description                      |
| -------------- | ---------------------------------- | ---- | -------------------------- |
| authType       | [UserAuthType](#userauthtype8)     | Yes  | Authentication type. Currently, **FACE** and **FINGERPRINT** are supported.|
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8) | Yes  | Authentication trust level.      |

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| number | Query result. If the authentication capability is supported, **SUCCESS** is returned. Otherwise, a [ResultCode](#resultcodedeprecated) is returned.|

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let auth = new userAuth.UserAuth();
let checkCode = auth.getAvailableStatus(userAuth.UserAuthType.FACE, userAuth.AuthTrustLevel.ATL1);
if (checkCode == userAuth.ResultCode.SUCCESS) {
  console.info('check auth support success');
} else {
  console.error(`check auth support fail, code = ${checkCode}`);
}
```

### auth<sup>(deprecated)</sup>

auth(challenge: Uint8Array, authType: UserAuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array

Starts user authentication. This API uses a callback to return the result.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. Use [start](#startdeprecated) instead.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name        | Type                                    | Mandatory| Description                    |
| -------------- | ---------------------------------------- | ---- | ------------------------ |
| challenge      | Uint8Array                               | Yes  | Challenge value, which can be passed in Uint8Array([]) format.|
| authType       | [UserAuthType](#userauthtype8)           | Yes  | Authentication type. Currently, **FACE** and **FINGERPRINT** are supported.|
| authTrustLevel | [AuthTrustLevel](#authtrustlevel8)       | Yes  | Authentication trust level.            |
| callback       | [IUserAuthCallback](#iuserauthcallbackdeprecated) | Yes  | Callback used to return the result.       |

**Return value**

| Type      | Description                                                        |
| ---------- | ------------------------------------------------------------ |
| Uint8Array | Context ID, which is used as the input parameter of [cancelAuth](#cancelauthdeprecated).|

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let auth = new userAuth.UserAuth();
let challenge = new Uint8Array([]);
auth.auth(challenge, userAuth.UserAuthType.FACE, userAuth.AuthTrustLevel.ATL1, {
  onResult: (result, extraInfo) => {
    try {
      console.info(`auth onResult result = ${result}`);
      console.info(`auth onResult extraInfo = ${JSON.stringify(extraInfo)}`);
      if (result == userAuth.ResultCode.SUCCESS) {
        // Add the logic to be executed when the authentication is successful.
      } else {
        // Add the logic to be executed when the authentication fails.
      }
    } catch (error) {
      console.error(`auth onResult error = ${error}`);
    }
  }
});
```

### cancelAuth<sup>(deprecated)</sup>

cancelAuth(contextID : Uint8Array) : number

Cancels an authentication based on the context ID.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. Use [cancel](#canceldeprecated) instead.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type      | Mandatory| Description                                      |
| --------- | ---------- | ---- | ------------------------------------------ |
| contextID | Uint8Array | Yes  | Context ID, which is obtained by [auth](#authdeprecated).|

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| number | Returns **SUCCESS** if the cancellation is successful. Returns a [ResultCode](#resultcodedeprecated) otherwise.|

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

// contextId can be obtained by auth(). In this example, it is defined here.
let contextId = new Uint8Array([0, 1, 2, 3, 4, 5, 6, 7]);
let auth = new userAuth.UserAuth();
let cancelCode = auth.cancelAuth(contextId);
if (cancelCode == userAuth.ResultCode.SUCCESS) {
  console.info('cancel auth success');
} else {
  console.error('cancel auth fail');
}
```

## IUserAuthCallback<sup>(deprecated)</sup>

Provides callbacks to return the authentication result.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. Use [AuthEvent](#autheventdeprecated) instead.

### onResult<sup>(deprecated)</sup>

onResult: (result : number, extraInfo : AuthResult) => void

Called to return the authentication result.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. Use [callback](#callbackdeprecated) instead.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type                      | Mandatory| Description       |
| --------- | -------------------------- | ---- | ------------------------------------------------ |
| result    | number           | Yes  | Authentication result. For details, see [ResultCode](#resultcodedeprecated).|
| extraInfo | [AuthResult](#authresultdeprecated) | Yes  | Extended information, which varies depending on the authentication result.<br>If the authentication is successful, the user authentication token will be returned in **extraInfo**.<br>If the authentication fails, the remaining number of authentication times will be returned in **extraInfo**.<br>If the authentication executor is locked, the freeze time will be returned in **extraInfo**.|

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let auth = new userAuth.UserAuth();
let challenge = new Uint8Array([]);
auth.auth(challenge, userAuth.UserAuthType.FACE, userAuth.AuthTrustLevel.ATL1, {
  onResult: (result, extraInfo) => {
    try {
      console.info(`auth onResult result = ${result}`);
      console.info(`auth onResult extraInfo = ${JSON.stringify(extraInfo)}`);
      if (result == userAuth.ResultCode.SUCCESS) {
        // Add the logic to be executed when the authentication is successful.
      }  else {
        // Add the logic to be executed when the authentication fails.
      }
    } catch (error) {
      console.error(`auth onResult error = ${error}`);
    }
  }
});
```

### onAcquireInfo<sup>(deprecated)</sup>

onAcquireInfo ?: (module : number, acquire : number, extraInfo : any) => void

Called to acquire authentication tip information. This API is optional.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. Use [callback](#callbackdeprecated) instead.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name   | Type  | Mandatory| Description                          |
| --------- | ------ | ---- | ------------------------------ |
| module    | number | Yes  | ID of the module that sends the tip information.            |
| acquire   | number | Yes  | Authentication tip information.|
| extraInfo | any    | Yes  | Reserved field.                    |

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let auth = new userAuth.UserAuth();
let challenge = new Uint8Array([]);
auth.auth(challenge, userAuth.UserAuthType.FACE, userAuth.AuthTrustLevel.ATL1, {
  onResult: (result, extraInfo) => {
    try {
      console.info(`auth onResult result = ${result}`);
      console.info(`auth onResult extraInfo = ${JSON.stringify(extraInfo)}`);
      if (result == userAuth.ResultCode.SUCCESS) {
        // Add the logic to be executed when the authentication is successful.
      }  else {
        // Add the logic to be executed when the authentication fails.
      }
    } catch (error) {
      console.error(`auth onResult error = ${error}`);
    }
  },
  onAcquireInfo: (module, acquire, extraInfo : userAuth.AuthResult) => {
    try {
      console.info(`auth onAcquireInfo module = ${module}`);
      console.info(`auth onAcquireInfo acquire = ${acquire}`);
      console.info(`auth onAcquireInfo extraInfo = ${JSON.stringify(extraInfo)}`);
    } catch (error) {
      console.error(`auth onAcquireInfo error = ${error}`);
    }
  }
});
```

## AuthResult<sup>(deprecated)</sup>

Represents the authentication result object.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. Use [AuthResultInfo](#authresultinfodeprecated) instead.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name        | Type  | Mandatory| Description                |
| ------------ | ---------- | ---- | -------------------|
| token        | Uint8Array | No  | Authentication token information.|
| remainTimes  | number     | No  | Number of remaining authentication operations.|
| freezingTime | number     | No  | Time for which the authentication operation is frozen.|

## ResultCode<sup>(deprecated)</sup>

Enumerates the authentication result codes.

> **NOTE**<br>
> This object is deprecated since API version 9. Use [UserAuthResultCode](#userauthresultcode9) instead.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name                   | Value| Description                |
| ----------------------- | ------ | -------------------- |
| SUCCESS                 | 0      | The operation is successful.          |
| FAIL                    | 1      | The authentication failed.          |
| GENERAL_ERROR           | 2      | A general operation error occurred.      |
| CANCELED                | 3      | The authentication is canceled.          |
| TIMEOUT                 | 4      | The authentication timed out.          |
| TYPE_NOT_SUPPORT        | 5      | The authentication type is not supported.  |
| TRUST_LEVEL_NOT_SUPPORT | 6      | The authentication trust level is not supported.  |
| BUSY                    | 7      | Indicates the busy state.          |
| INVALID_PARAMETERS      | 8      | Invalid parameters are detected.          |
| LOCKED                  | 9      | The authentication executor is locked.      |
| NOT_ENROLLED            | 10     | The user has not entered the authentication information.|

## FaceTips<sup>(deprecated)</sup>

Enumerates the tip codes used during the facial authentication process.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 11.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name                         |   Value  |    Description                            |
| ----------------------------- | ------ | ------------------------------------ |
| FACE_AUTH_TIP_TOO_BRIGHT      | 1      | The obtained facial image is too bright due to high illumination.          |
| FACE_AUTH_TIP_TOO_DARK        | 2      | The obtained facial image is too dark due to low illumination.          |
| FACE_AUTH_TIP_TOO_CLOSE       | 3      | The face is too close to the device.                  |
| FACE_AUTH_TIP_TOO_FAR         | 4      | The face is too far away from the device.                  |
| FACE_AUTH_TIP_TOO_HIGH        | 5      | Only the upper part of the face is captured because the device is angled too high.        |
| FACE_AUTH_TIP_TOO_LOW         | 6      | Only the lower part of the face is captured because the device is angled too low.        |
| FACE_AUTH_TIP_TOO_RIGHT       | 7      | Only the right part of the face is captured because the device is deviated to the right.      |
| FACE_AUTH_TIP_TOO_LEFT        | 8      | Only the left part of the face is captured because the device is deviated to the left.      |
| FACE_AUTH_TIP_TOO_MUCH_MOTION | 9      | The face moves too fast during facial information collection.|
| FACE_AUTH_TIP_POOR_GAZE       | 10     | The face is not facing the camera.                    |
| FACE_AUTH_TIP_NOT_DETECTED    | 11     | No face is detected.                |


## FingerprintTips<sup>(deprecated)</sup>

Enumerates the tip codes used during the fingerprint authentication process.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 11.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name                             |   Value  | Description                                              |
| --------------------------------- | ------ | -------------------------------------------------- |
| FINGERPRINT_AUTH_TIP_GOOD         | 0      | The obtained fingerprint image is in good condition.                              |
| FINGERPRINT_AUTH_TIP_DIRTY        | 1      | Large fingerprint image noise is detected due to suspicious or detected dirt on the sensor.|
| FINGERPRINT_AUTH_TIP_INSUFFICIENT | 2      | The noise of the fingerprint image is too large to be processed.    |
| FINGERPRINT_AUTH_TIP_PARTIAL      | 3      | Incomplete fingerprint image is detected.                            |
| FINGERPRINT_AUTH_TIP_TOO_FAST     | 4      | The fingerprint image is incomplete due to fast movement.                        |
| FINGERPRINT_AUTH_TIP_TOO_SLOW     | 5      | Failed to obtain the fingerprint image because the finger seldom moves.                      |


## UserAuthType<sup>8+</sup>

Enumerates the identity authentication types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name       | Value  | Description      |
| ----------- | ---- | ---------- |
| PIN<sup>10+</sup>         | 1    | PIN authentication.|
| FACE        | 2    | Facial authentication.|
| FINGERPRINT | 4    | Fingerprint authentication.|

## AuthTrustLevel<sup>8+</sup>

Enumerates the trust levels of the authentication result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name| Value   | Description                                                        |
| ---- | ----- | ------------------------------------------------------------ |
| ATL1 | 10000 | Authentication trust level 1. The authentication of this level can identify individual users and provides limited liveness detection capabilities. It is usually used in service risk control and query of general personal data.|
| ATL2 | 20000 | Authentication trust level 2. The authentication of this level can accurately identify individual users and provides regular liveness detection capabilities. It is usually used in scenarios such as application logins and keeping the unlocking state of a device.|
| ATL3 | 30000 | Authentication trust level 3. The authentication of this level can accurately identify individual users and provides strong liveness detection capabilities. It is usually used in scenarios such as unlocking a device.|
| ATL4 | 40000 | Authentication trust level 4. The authentication of this level can accurately identify individual users and provides powerful liveness detection capabilities. It is usually used in scenarios such as small-amount payment.|

## SecureLevel<sup>(deprecated)</sup>

Enumerates the authentication security levels.

> **NOTE**<br>This API is supported since API version 6 and deprecated since API version 8.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name| Value   | Description                                                        |
| ---- | ----- | ------------------------------------------------------------ |
| S1 | 'S1' | Authentication trust level 1. The authentication of this level can identify individual users and provides limited liveness detection capabilities. It is usually used in service risk control and query of general personal data.|
| S2 | 'S2' | Authentication trust level 2. The authentication of this level can accurately identify individual users and provides regular liveness detection capabilities. It is usually used in scenarios such as application logins and keeping the unlocking state of a device.|
| S3 | 'S3' | Authentication trust level 3. The authentication of this level can accurately identify individual users and provides strong liveness detection capabilities. It is usually used in scenarios such as unlocking a device.|
| S4 | 'S4' | Authentication trust level 4. The authentication of this level can accurately identify individual users and provides powerful liveness detection capabilities. It is usually used in scenarios such as small-amount payment.|

## AuthType<sup>(deprecated)</sup>

Enumerates the authentication types.

> **NOTE**<br>This API is supported since API version 6 and deprecated since API version 8.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name| Value   | Description                                                        |
| ---- | ----- | ------------------------------------------------------------ |
| ALL  | 'ALL' | A reserved parameter not supported by the current version.|
| FACE_ONLY | 'FACE_ONLY' | Facial authentication.|

## userAuth.getAuthenticator<sup>(deprecated)</sup>

getAuthenticator(): Authenticator

Obtains an **Authenticator** instance for user authentication.

> **NOTE**<br>
> This API is deprecated since API version 8. Use [constructor](#constructordeprecated) instead.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Return value**

| Type                                     | Description        |
| ----------------------------------------- | ------------ |
| [Authenticator](#authenticatordeprecated) | **Authenticator** instance obtained.|

**Example**
  ```ts
  import { userAuth } from '@kit.UserAuthenticationKit';
  
  let authenticator = userAuth.getAuthenticator();
  ```

## Authenticator<sup>(deprecated)</sup>

Defines the **Authenticator** object.

> **NOTE**<br>
> This API is deprecated since API version 8. Use [UserAuth](#userauthdeprecated) instead.

### execute<sup>(deprecated)</sup>

execute(type: AuthType, level: SecureLevel, callback: AsyncCallback&lt;number&gt;): void

Starts user authentication. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
> This API is deprecated since API version 8. Use [auth](#authdeprecated) instead.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                                                                   |
| -------- | --------------------------- | ---- |-----------------------------------------------------------------------------------------------------------------------|
| type     | AuthType                      | Yes  | Authentication type. Currently, only **FACE_ONLY** is supported.<br>**ALL** is reserved and not supported by the current version.                                                                |
| level    | SecureLevel  | Yes  | Security level of the authentication. It can be **S1** (lowest), **S2**, **S3**, or **S4** (highest).<br>Devices capable of 3D facial recognition support S3 and lower-level authentication.<br>Devices capable of 2D facial recognition support S2 and lower-level authentication.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the result. **number** indicates the [AuthenticationResult](#authenticationresultdeprecated).|

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let authenticator = userAuth.getAuthenticator();
authenticator.execute('FACE_ONLY', 'S2', (error, code)=>{
  if (code === userAuth.ResultCode.SUCCESS) {
    console.info('auth success');
    return;
  }
  console.error(`auth fail, code = ${code}`);
});
```


### execute<sup>(deprecated)</sup>

execute(type : AuthType, level : SecureLevel): Promise&lt;number&gt;

Starts user authentication. This API uses a promise to return the result.

> **NOTE**<br>
> This API is deprecated since API version 8. Use [auth](#authdeprecated) instead.

**Required permissions**: ohos.permission.ACCESS_BIOMETRIC

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name| Type  | Mandatory| Description                                                                                                                   |
| ------ | ------ | ---- |-----------------------------------------------------------------------------------------------------------------------|
| type   | AuthType | Yes  | Authentication type. Currently, only **FACE_ONLY** is supported.<br>**ALL** is reserved and not supported by the current version.                                                                |
| level  | SecureLevel | Yes  | Security level of the authentication. It can be **S1** (lowest), **S2**, **S3**, or **S4** (highest).<br>Devices capable of 3D facial recognition support S3 and lower-level authentication.<br>Devices capable of 2D facial recognition support S2 and lower-level authentication.|

**Return value**

| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the authentication result, which is a number. For details, see [AuthenticationResult](#authenticationresultdeprecated).|

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  let authenticator = userAuth.getAuthenticator();
  authenticator.execute('FACE_ONLY', 'S2').then((code)=>{
    console.info('auth success');
  })
} catch (error) {
  console.error(`auth fail, code = ${error}`);
}
```

## AuthenticationResult<sup>(deprecated)</sup>

Enumerates the authentication results.

> **NOTE**<br>
> This object is deprecated since API version 8. Use [ResultCode](#resultcodedeprecated) instead.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name              |   Value  | Description                      |
| ------------------ | ------ | -------------------------- |
| NO_SUPPORT         | -1     | The device does not support the current authentication mode.|
| SUCCESS            | 0      | The authentication is successful.                |
| COMPARE_FAILURE    | 1      | The feature comparison failed.                |
| CANCELED           | 2      | The authentication was canceled by the user.            |
| TIMEOUT            | 3      | The authentication has timed out.                |
| CAMERA_FAIL        | 4      | The camera failed to start.            |
| BUSY               | 5      | The authentication service is not available. Try again later.  |
| INVALID_PARAMETERS | 6      | The authentication parameters are invalid.            |
| LOCKED             | 7      | The user account is locked because the number of authentication failures has reached the threshold.|
| NOT_ENROLLED       | 8      | No authentication credential is registered.          |
| GENERAL_ERROR      | 100    | Other errors.                |
