# @ohos.commonEventManager (Common Event) (System API)

This module provides common event capabilities, including publishing, subscribing to, and unsubscribing from common events.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [CommonEventManager](./js-apis-commonEventManager.md).

## Modules to Import

```ts
import { commonEventManager } from '@kit.BasicServicesKit';
```

## Support

A system common event is an event that is published by a system service or system application and requires specific permissions to subscribe to. To publish or subscribe to this type of event, you must follow the event-specific definitions.

For details about the enumerations of all system common events, see [System Common Events](./common_event/commonEventManager-definitions.md).

## commonEventManager.publishAsUser<sup>

publishAsUser(event: string, userId: number, callback: AsyncCallback\<void>): void

Publishes a common event to a specific user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| event    | string               | Yes  | Name of the common event to publish. For details, see [System Common Events](./common_event/commonEventManager-definitions.md).            |
| userId   | number               | Yes  | User ID.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.            |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Event Error Codes](./errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202      | not system app.                     |
| 1500003  | The common event sending frequency too high. |
| 1500007  | Failed to send the message to the common event service. |
| 1500008  | Failed to initialize the common event service. |
| 1500009  | Failed to obtain system parameters.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Specify the user to whom the common event will be published.
let userId = 100;

// Publish a common event.
try {
    commonEventManager.publishAsUser('event', userId, (err: BusinessError) => {
      if (err) {
        console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);
        return;
      }
      console.info('publishAsUser');
    });
} catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);
}
```

## commonEventManager.publishAsUser

publishAsUser(event: string, userId: number, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

Publishes a common event with given attributes to a specific user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                  | Mandatory| Description                  |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | Yes  | Name of the common event to publish. For details, see [System Common Events](./common_event/commonEventManager-definitions.md). |
| userId   | number | Yes| User ID.|
| options  | [CommonEventPublishData](./js-apis-inner-commonEvent-commonEventPublishData.md) | Yes  | Attributes of the common event to publish.|
| callback | AsyncCallback\<void>   | Yes  | Callback used to return the result. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Event Error Codes](./errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202      | not system app.                     |
| 1500003  | The common event sending frequency too high. |
| 1500007  | Failed to send the message to the common event service. |
| 1500008  | Failed to initialize the common event service. |
| 1500009  | Failed to obtain system parameters.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Attributes of a common event.
let options:commonEventManager.CommonEventPublishData = {
  code: 0,			 // Result code of the common event.
  data: 'initial data', // Initial data of the common event.
}

// Specify the user to whom the common event will be published.
let userId = 100;
// Publish a common event.
try {
  commonEventManager.publishAsUser('event', userId, options, (err: BusinessError) => {
    if (err) {
      console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info('publishAsUser');
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);
}
```

## commonEventManager.removeStickyCommonEvent<sup>10+</sup>

removeStickyCommonEvent(event: string, callback: AsyncCallback\<void>): void

Removes a sticky common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Required permissions**: ohos.permission.COMMONEVENT_STICKY

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                | Mandatory| Description                            |
| -------- | -------------------- | ---- | -------------------------------- |
| event    | string               | Yes  | Sticky common event to remove. For details, see [System Common Events](./common_event/commonEventManager-definitions.md).      |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Event Error Codes](./errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | The application does not have permission to call the interface.    |
| 202      | not system app.                     |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      |
| 1500004  | A third-party application cannot send system common events.                |
| 1500007  | Failed to send the message to the common event service.             |
| 1500008  | Failed to initialize the common event service.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

commonEventManager.removeStickyCommonEvent('sticky_event', (err: BusinessError) => {
  if (err) {
    console.error(`removeStickyCommonEvent failed, errCode: ${err.code}, errMes: ${err.message}`);
    return;
  }
  console.info(`removeStickyCommonEvent success`);
});
```

## commonEventManager.removeStickyCommonEvent<sup>10+</sup>

removeStickyCommonEvent(event: string): Promise\<void>

Removes a sticky common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Required permissions**: ohos.permission.COMMONEVENT_STICKY

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| event  | string | Yes  | Sticky common event to remove. For details, see [System Common Events](./common_event/commonEventManager-definitions.md).|

**Return value**

| Type          | Description                        |
| -------------- | ---------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Event Error Codes](./errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | The application does not have permission to call the interface.    |
| 202      | not system app.                     |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      |
| 1500004  | A third-party application cannot send system common events.                |
| 1500007  | Failed to send the message to the common event service.             |
| 1500008  | Failed to initialize the common event service.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

commonEventManager.removeStickyCommonEvent('sticky_event').then(() => {
  console.info(`removeStickyCommonEvent success`);
}).catch ((err: BusinessError) => {
  console.error(`removeStickyCommonEvent failed, errCode: ${err.code}, errMes: ${err.message}`);
});
```

## commonEventManager.setStaticSubscriberState<sup>10+</sup>

setStaticSubscriberState(enable: boolean, callback: AsyncCallback\<void>): void

Enables or disables static subscription for the current application. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Notification.CommonEvent

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| enable  | boolean | Yes  | Whether static subscription is enabled.<br>**true**: enabled.<br>**false**: disabled. |
| callback  | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Event Error Codes](./errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202      | not system app.                     |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      |
| 1500007  | Failed to send the message to the common event service.             |
| 1500008  | Failed to initialize the common event service.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

commonEventManager.setStaticSubscriberState(true, (err: BusinessError) => {
  if (err.code != 0) {
    console.error(`setStaticSubscriberState failed, errCode: ${err.code}, errMes: ${err.message}`);
    return;
  }
  console.info(`setStaticSubscriberState success`);
});
```

## commonEventManager.setStaticSubscriberState<sup>10+</sup>

setStaticSubscriberState(enable: boolean): Promise\<void>

Enables or disables static subscription for the current application. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Notification.CommonEvent

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| enable  | boolean | Yes  | Whether static subscription is enabled.<br>**true**: enabled.<br>**false**: disabled. |

**Return value**

| Type          | Description                        |
| -------------- | ---------------------------- |
| Promise\<void> |  Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Event Error Codes](./errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202      | not system app.                     |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      |
| 1500007  | Failed to send the message to the common event service.             |
| 1500008  | Failed to initialize the common event service.     |

**Example**


```ts
import { BusinessError } from '@kit.BasicServicesKit';

commonEventManager.setStaticSubscriberState(false).then(() => {
  console.info(`setStaticSubscriberState success`);
}).catch ((err: BusinessError) => {
  console.error(`setStaticSubscriberState failed, errCode: ${err.code}, errMes: ${err.message}`);
});
```

## commonEventManager.setStaticSubscriberState<sup>12+</sup>

setStaticSubscriberState(enable: boolean, events?: Array\<string>): Promise\<void>

Enables or disables the static subscription event for the current application and records the event name. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Notification.CommonEvent

**System API**: This is a system API.

**Parameters**

| Name| Type         | Mandatory| Description                                                |
| ------ | ------------- | ---- | ---------------------------------------------------- |
| enable | boolean       | Yes  | Whether static subscription is enabled.<br>**true**: enabled.<br>**false**: disabled. |
| events | Array\<string> | No  | Name of a recorded event.                                  |

**Return value**

| Type          | Description                                |
| -------------- | ------------------------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Event Error Codes](./errorcode-CommonEventService.md).

| ID| Error Message                                              |
| -------- | ------------------------------------------------------ |
| 202      | not system app.                     |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      |
| 1500007  | Failed to send the message to the common event service.        |
| 1500008  | Failed to initialize the common event service. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let evenName: string[] = ['usual.event.SEND_DATA'];
commonEventManager.setStaticSubscriberState(true, evenName).then(() => {
  console.info(`setStaticSubscriberState success, state is ${true}`);
}).catch((err: BusinessError) => {
  console.error(`setStaticSubscriberState failed, errCode: ${err.code}, errMes: ${err.message}`);
});
```
