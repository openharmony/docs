# @ohos.userIAM.userAuth (User Authentication) (System API)

<!--Kit: User Authentication Kit-->
<!--Subsystem: UserIAM-->
<!--Owner: @WALL_EYE-->
<!--SE: @lichangting518-->
<!--TSE: @jane_lz-->

The **userIAM.userAuth** module provides user authentication capabilities in identity authentication scenarios, such as device unlocking, payment, and app login.

> **NOTE**<br>
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.userIAM.userAuth (User Authentication)](js-apis-useriam-userauth.md).

## Modules to Import

```ts
import { userAuth } from '@kit.UserAuthenticationKit';
```

## AuthParam<sup>10+</sup>

Represents the user authentication parameters.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name          | Type                              | Mandatory| Description                                                        |
| -------------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| userId<sup>18+</sup> | number | No  |ID of the user to be authenticated. The value is a positive integer greater than or equal to 0. The default value is the ID of the current user.|

## WindowModeType<sup>10+</sup>

Enumerates the window types of the authentication widget.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**System API**: This is a system API.

| Name      | Value  | Description      |
| ---------- | ---- | ---------- |
| DIALOG_BOX | 1    | Dialog box.|
| FULLSCREEN | 2    | Full screen.|

## WidgetParam<sup>10+</sup>

Represents the information presented on the user authentication page.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name                | Type                               | Mandatory| Description                                                        |
| -------------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| windowMode           | [WindowModeType](#windowmodetype10) | No  | Display format of the user authentication page. The default value is **WindowModeType.DIALOG_BOX**.<br>**System API**: This is a system API.|

## NoticeType<sup>10+</sup>

Defines the type of the user authentication notification.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**System API**: This is a system API.

| Name         | Value  | Description                |
| ------------- | ---- | -------------------- |
| WIDGET_NOTICE | 1    | Notification from the user authentication widget.|

## userAuth.sendNotice<sup>10+</sup>

sendNotice(noticeType: NoticeType, eventData: string): void

Sends a notification from the user authentication widget.

**Required permissions**: ohos.permission.SUPPORT_USER_AUTH

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                       | Mandatory| Description      |
| ---------- | --------------------------- | ---- | ---------- |
| noticeType | [NoticeType](#noticetype10) | Yes  | Notification type.|
| eventData  | string                | Yes  | Event data. The data length range is 0 to 65536.   |

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 201      | Permission denied.       |
| 202      | Permission denied. Called by non-system application. |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.    |
| 12500002 | General operation error.                |

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';
import { BusinessError } from '@kit.BasicServicesKit';

interface  EventData {
  widgetContextId: number;
  event: string;
  version: string;
  payload: PayLoad;
}
interface PayLoad {
  type: string[];
}
try {
  const eventData : EventData = {
    widgetContextId: 123456,
    event: 'EVENT_AUTH_TYPE_READY',
    version: '1',
    payload: {
      type: ['pin']
    } as PayLoad,
  };
  const jsonEventData = JSON.stringify(eventData);
  let noticeType = userAuth.NoticeType.WIDGET_NOTICE;
  userAuth.sendNotice(noticeType, jsonEventData);
  console.info('sendNotice success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`sendNotice catch error: Code is ${err?.code}, message is ${err?.message}`);
}
```

## UserAuthWidgetMgr<sup>10+</sup>

Provides APIs for managing the user authentication widget. You can use the APIs to register the user authentication widget with UserAuthWidgetMgr for management and scheduling.

### on<sup>10+</sup>

on(type: 'command', callback: IAuthWidgetCallback): void

Subscribes to commands from the user authentication framework for the user authentication widget.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**System API**: This is a system API.

**Parameters**

| Name  | Type                                         | Mandatory| Description                                                        |
| -------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'command'                                     | Yes  | Event type. **command** indicates the command sent from the user authentication framework to the user authentication widget.|
| callback | [IAuthWidgetCallback](#iauthwidgetcallback10) | Yes  | Callback used to return the command from the user authentication framework to the user authentication widget.|

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID| Error Message                |
| -------- | ------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 12500002 | General operation error. |

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';
import { BusinessError } from '@kit.BasicServicesKit';

const userAuthWidgetMgrVersion = 1;
try {
  let userAuthWidgetMgr = userAuth.getUserAuthWidgetMgr(userAuthWidgetMgrVersion);
  console.info('get userAuthWidgetMgr instance success');
  userAuthWidgetMgr.on('command', {
    sendCommand(cmdData) {
      console.info(`The cmdData is ${cmdData}`);
    }
  })
  console.info('subscribe authentication event success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`userAuth widgetMgr catch error: Code is ${err?.code}, message is ${err?.message}`);
}
```

### off<sup>10+</sup>

off(type: 'command', callback?: IAuthWidgetCallback): void

Unsubscribes from commands sent from the user authentication framework.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**System API**: This is a system API.

**Parameters**

| Name  | Type                                         | Mandatory| Description                                                        |
| -------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'command'                                     | Yes  | Event type. **command** indicates the command sent from the user authentication framework to the user authentication widget.|
| callback | [IAuthWidgetCallback](#iauthwidgetcallback10) | No  | Callback used to return the command from the user authentication framework to the user authentication widget.|

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID| Error Message                |
| -------- | ------------------------ |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 12500002 | General operation error. |

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';
import { BusinessError } from '@kit.BasicServicesKit';

const userAuthWidgetMgrVersion = 1;
try {
  let userAuthWidgetMgr = userAuth.getUserAuthWidgetMgr(userAuthWidgetMgrVersion);
  console.info('get userAuthWidgetMgr instance success');
  userAuthWidgetMgr.off('command', {
    sendCommand(cmdData) {
      console.info(`The cmdData is ${cmdData}`);
    }
  })
  console.info('cancel subscribe authentication event success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`userAuth widgetMgr catch error: Code is ${err?.code}, message is ${err?.message}`);
}
```

## userAuth.getUserAuthWidgetMgr<sup>10+</sup>

getUserAuthWidgetMgr(version: number): UserAuthWidgetMgr

Obtains a **UserAuthWidgetMgr** instance for user authentication.

> **NOTE**<br>
> A **UserAuthInstance** instance can be used for an authentication only once.

**Required permissions**: ohos.permission.SUPPORT_USER_AUTH

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**System API**: This is a system API.

**Parameters**

| Name | Type  | Mandatory| Description                |
| ------- | ------ | ---- | -------------------- |
| version | number | Yes  | Version of the user authentication widget.|

**Return value**

| Type                                     | Description        |
| ----------------------------------------- | ------------ |
| [UserAuthWidgetMgr](#userauthwidgetmgr10) | **UserAuthWidgetMgr** instance obtained.|

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 201      | Permission denied.       |
| 202      | Permission denied. Called by non-system application. |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.                                     |
| 12500002 | General operation error.                |

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';
import { BusinessError } from '@kit.BasicServicesKit';

let userAuthWidgetMgrVersion = 1;
try {
  let userAuthWidgetMgr = userAuth.getUserAuthWidgetMgr(userAuthWidgetMgrVersion);
  console.info('get userAuthWidgetMgr instance success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`userAuth widgetMgr catch error: Code is ${err?.code}, message is ${err?.message}`);
}
```

## IAuthWidgetCallback<sup>10+</sup>

Provides the callback for returning the commands sent from the user authentication framework to the user authentication widget.

### sendCommand<sup>10+</sup>

sendCommand(cmdData: string): void

Called to return the command sent from the user authentication framework to the user authentication widget.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**System API**: This is a system API.

**Parameters**

| Name | Type  | Mandatory| Description                              |
| ------- | ------ | ---- | ---------------------------------- |
| cmdData | string | Yes  | Command from the user authentication framework to the user authentication widget.|

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';
import { BusinessError } from '@kit.BasicServicesKit';

const userAuthWidgetMgrVersion = 1;
try {
  let userAuthWidgetMgr = userAuth.getUserAuthWidgetMgr(userAuthWidgetMgrVersion);
  console.info('get userAuthWidgetMgr instance success');
  userAuthWidgetMgr.on('command', {
    sendCommand(cmdData) {
      console.info(`The cmdData is ${cmdData}`);
    }
  })
  console.info('subscribe authentication event success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`userAuth widgetMgr catch error: Code is ${err?.code}, message is ${err?.message}`);
}
```

## UserAuthType<sup>8+</sup>

Enumerates the types of credentials for identity authentication.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name       | Value  | Description      |
| ----------- | ---- | ---------- |
| PRIVATE_PIN<sup>14+</sup>  | 16   | Privacy password.|

**Example**

Initiate privacy PIN authentication with the authentication trust level greater than or equal to ATL3.

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
    authType: [userAuth.UserAuthType.PRIVATE_PIN],
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
      console.info(`userAuthInstance callback result = ${JSON.stringify(result)}`);
    }
  });
  console.info('auth on success');
  userAuthInstance.start();
  console.info('auth start success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`auth catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

## userAuth.queryReusableAuthResult<sup>20+</sup>

queryReusableAuthResult(authParam: AuthParam): Uint8Array

Queries whether there is any reusable identity authentication result.

**Required permissions**: ohos.permission.ACCESS_USER_AUTH_INTERNAL

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**System API**: This is a system API.

**Parameters**

| Name | Type  | Mandatory| Description                |
| ------- | ------ | ---- | -------------------- |
| authParam | [userAuth.AuthParam](js-apis-useriam-userauth.md#authparam10) | Yes| Represents the user authentication parameters.|

**Return value**

| Type       | Description                                |
| ---------- | ------------------------------------ |
| Uint8Array | Reusable AuthToken, up to 1024 bytes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Authentication Error Codes](errorcode-useriam.md).

| ID| Error Message                               |
| -------- | --------------------------------------- |
| 201      | Permission denied.       |
| 202      | Permission denied. Called by non-system application. |
| 12500002 | General operation error.                |
| 12500008 | The parameter is out of range.          |
| 12500017 | Failed to reuse authentication result.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth } from '@kit.UserAuthenticationKit';

try {
  const rand = cryptoFramework.createRandom();
  const len: number = 16;
  const randData: Uint8Array = rand?.generateRandomSync(len)?.data;
  const reuseUnlockResult: userAuth.ReuseUnlockResult = {
    reuseMode: userAuth.ReuseMode.AUTH_TYPE_RELEVANT,
    reuseDuration: userAuth.MAX_ALLOWABLE_REUSE_DURATION,
  }
  const authParam: userAuth.AuthParam = {
    challenge: randData,
    authType: [userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
    reuseUnlockResult: reuseUnlockResult,
  };
  let authToken = userAuth.queryReusableAuthResult(authParam);
  console.info('query reuse auth result success');
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`query reuse auth result catch error. Code is ${err?.code}, message is ${err?.message}`);
}
```

## UserAuthResultCode<sup>18+</sup>

Enumerates the authentication result codes.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**System API**: This is a system API.

| Name                   |   Value  | Description                |
| ----------------------- | ------ | -------------------- |
| AUTH_TOKEN_CHECK_FAILED | 12500015      | The AuthToken is invalid.|
| AUTH_TOKEN_EXPIRED      | 12500016      | The interval between the AuthToken issuance time and the AuthToken verification time exceeds the maximum validity period.|
| REUSE_AUTH_RESULT_FAILED<sup>20+</sup>| 12500017      | Failed to reuse the authentication result.|
