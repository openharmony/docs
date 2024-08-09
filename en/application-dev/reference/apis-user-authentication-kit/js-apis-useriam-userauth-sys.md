# @ohos.userIAM.userAuth (User Authentication) (System API)

The **userIAM.userAuth** module provides user authentication capabilities in identity authentication scenarios, such as device unlocking, payment, and app login.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.userIAM.userAuth (User Authentication)](js-apis-useriam-userauth.md).

## Modules to Import

```ts
import { userAuth } from '@kit.UserAuthenticationKit';
```

## WindowModeType<sup>10+</sup>

Enumerates the window types of the authentication widget.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**System API**: This is a system API.

| Name      | Value  | Description      |
| ---------- | ---- | ---------- |
| DIALOG_BOX | 1    | Dialog box. |
| FULLSCREEN | 2    | Full screen. |

## WidgetParam<sup>10+</sup>

Represents the information presented on the user authentication page.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

| Name                | Type                               | Mandatory | Description                                                        |
| -------------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| windowMode           | [WindowModeType](#windowmodetype10) | No  | Display format of the user authentication page. The default value is **WindowModeType.DIALOG_BOX**.<br>**System API**: This is a system API. |

## NoticeType<sup>10+</sup>

Defines the type of the user authentication notification.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**System API**: This is a system API.

| Name         | Value  | Description                |
| ------------- | ---- | -------------------- |
| WIDGET_NOTICE | 1    | Notification from the user authentication widget. |

## userAuth.sendNotice<sup>10+</sup>

sendNotice(noticeType: NoticeType, eventData: string): void

Sends a notification from the user authentication widget.

**Required permissions**: ohos.permission.SUPPORT_USER_AUTH

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type                       | Mandatory | Description      |
| ---------- | --------------------------- | ---- | ---------- |
| noticeType | [NoticeType](#noticetype10) | Yes  | Notification type. |
| eventData  | string                      | Yes  | Event data. |

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID | Error Message                               |
| -------- | --------------------------------------- |
| 201      | Permission verification failed.         |
| 202      | The caller is not a system application. |
| 401      | Incorrect parameters. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed.    |
| 12500002 | General operation error.                |

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

interface  EventData {
  widgetContextId: number;
  event: string;
  version: string;
  payload: PayLoad;
}
interface PayLoad {
  type: Object[];
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
  console.log('sendNotice success');
} catch (error) {
  console.error('sendNotice catch error: ' + JSON.stringify(error));
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

| Name  | Type                                         | Mandatory | Description                                                        |
| -------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'command'                                     | Yes  | Event type. The vlaue is **command**, which indicates the command sent from the user authentication framework to the user authentication widget. |
| callback | [IAuthWidgetCallback](#iauthwidgetcallback10) | Yes  | Callback invoked to return the command from the user authentication framework to the user authentication widget. |

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID | Error Message                |
| -------- | ------------------------ |
| 401      | Incorrect parameters. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 12500002 | General operation error. |

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

const userAuthWidgetMgrVersion = 1;
try {
  let userAuthWidgetMgr = userAuth.getUserAuthWidgetMgr(userAuthWidgetMgrVersion);
  console.log('get userAuthWidgetMgr instance success');
  userAuthWidgetMgr.on('command', {
    sendCommand(cmdData) {
      console.log('The cmdData is ' + cmdData);
    }
  })
  console.log('subscribe authentication event success');
} catch (error) {
  console.error('userAuth widgetMgr catch error: ' + JSON.stringify(error));
}
```

### off<sup>10+</sup>

off(type: 'command', callback?: IAuthWidgetCallback): void

Unsubscribes from commands sent from the user authentication framework.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**System API**: This is a system API.

**Parameters**

| Name  | Type                                         | Mandatory | Description                                                        |
| -------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'command'                                     | Yes  | Event type. The value is **command**, which indicates the command sent from the user authentication framework to the user authentication widget. |
| callback | [IAuthWidgetCallback](#iauthwidgetcallback10) | No  | Callback for the command sent from the user authentication framework to the user authentication widget. |

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID | Error Message                |
| -------- | ------------------------ |
| 401      | Incorrect parameters. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. |
| 12500002 | General operation error. |

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

const userAuthWidgetMgrVersion = 1;
try {
  let userAuthWidgetMgr = userAuth.getUserAuthWidgetMgr(userAuthWidgetMgrVersion);
  console.log('get userAuthWidgetMgr instance success');
  userAuthWidgetMgr.off('command', {
    sendCommand(cmdData) {
      console.log('The cmdData is ' + cmdData);
    }
  })
  console.log('cancel subscribe authentication event success');
} catch (error) {
  console.error('userAuth widgetMgr catch error: ' + JSON.stringify(error));
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

| Name | Type  | Mandatory | Description                |
| ------- | ------ | ---- | -------------------- |
| version | number | Yes  | Version of the user authentication widget. |

**Return value**

| Type                                     | Description        |
| ----------------------------------------- | ------------ |
| [UserAuthWidgetMgr](#userauthwidgetmgr10) | **UserAuthWidgetMgr** instance obtained. |

**Error codes**

For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

| ID | Error Message                               |
| -------- | --------------------------------------- |
| 201      | Permission verification failed.         |
| 202      | The caller is not a system application. |
| 401      | Incorrect parameters. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types.                                     |
| 12500002 | General operation error.                |

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

let userAuthWidgetMgrVersion = 1;
try {
  let userAuthWidgetMgr = userAuth.getUserAuthWidgetMgr(userAuthWidgetMgrVersion);
  console.log('get userAuthWidgetMgr instance success');
} catch (error) {
  console.error('userAuth widgetMgr catch error: ' + JSON.stringify(error));
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

| Name | Type  | Mandatory | Description                              |
| ------- | ------ | ---- | ---------------------------------- |
| cmdData | string | Yes  | Command sent from the user authentication framework to the user authentication widget.|

**Example**

```ts
import { userAuth } from '@kit.UserAuthenticationKit';

const userAuthWidgetMgrVersion = 1;
try {
  let userAuthWidgetMgr = userAuth.getUserAuthWidgetMgr(userAuthWidgetMgrVersion);
  console.log('get userAuthWidgetMgr instance success');
  userAuthWidgetMgr.on('command', {
    sendCommand(cmdData) {
      console.log('The cmdData is ' + cmdData);
    }
  })
  console.log('subscribe authentication event success');
} catch (error) {
  console.error('userAuth widgetMgr catch error: ' + JSON.stringify(error));
}
```
