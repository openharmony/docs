# @ohos.commonEventManager (Common Event)

The **CommonEventManager** module provides common event capabilities, including the capabilities to publish, subscribe to, and unsubscribe from common events.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { commonEventManager } from '@kit.BasicServicesKit';
```

## Support

System common events refer to events released by system services or system applications. Subscribing to these common events requires specific permissions and values. For details, see [System Common Events](./common_event/commonEventManager-definitions.md).

## commonEventManager.publish

publish(event: string, callback: AsyncCallback\<void>): void

Publishes a common event. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name    | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| event    | string               | Yes  | Name of the common event to publish. For details, see [System Common Events](./common_event/commonEventManager-definitions.md).|
| callback | AsyncCallback\<void> | Yes  | Callback to execute after the event is published.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Event Error Codes](./errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- | 
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Callback for common event publication.
function publishCB(err: BusinessError) {
  if (err) {
    console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("publish success");
  }
}
// Publish a common event.
try {
  commonEventManager.publish("event", publishCB);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
}
```

## commonEventManager.publish

publish(event: string, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

Publishes a common event. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name    | Type                  | Mandatory| Description                  |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | Yes  | Name of the common event to publish. For details, see [System Common Events](./common_event/commonEventManager-definitions.md). |
| options  | [CommonEventPublishData](./js-apis-inner-commonEvent-commonEventPublishData.md) | Yes  | Attributes of the common event to publish.|
| callback | syncCallback\<void>   | Yes  | Callback used to return the result. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Event Error Codes](./errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Attributes of a common event.
let options:commonEventManager.CommonEventPublishData = {
  code: 0,			 // Result code of the common event.
  data: "initial data",// Result data of the common event.
  isOrdered: true	 // The common event is an ordered one.
}
// Callback for common event publication.
function publishCB(err: BusinessError) {
  if (err) {
    console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("publish success");
  }
}
// Publish a common event.
try {
  commonEventManager.publish("event", options, publishCB);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
}
```

## commonEventManager.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback\<CommonEventSubscriber>): void

Creates a subscriber. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name         | Type                                                        | Mandatory| Description                      |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------- |
| subscribeInfo | [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md)        | Yes  | Subscriber information.            |
| callback      | AsyncCallback\<[CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Define a subscriber to save the created subscriber object for subsequent subscription and unsubscription.
let subscriber:commonEventManager.CommonEventSubscriber;
// Attributes of a subscriber.
let subscribeInfo:commonEventManager.CommonEventSubscribeInfo = {
  events: ["event"]
};
// Callback for subscriber creation.
function createCB(err: BusinessError, commonEventSubscriber:commonEventManager.CommonEventSubscriber) {
  if(!err) {
    console.info("createSubscriber success");
    subscriber = commonEventSubscriber;
  } else {
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
  }
}
// Create a subscriber.
try {
  commonEventManager.createSubscriber(subscribeInfo, createCB);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
}
```

## commonEventManager.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise\<CommonEventSubscriber>

Creates a subscriber. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name         | Type                                                 | Mandatory| Description          |
| ------------- | ----------------------------------------------------- | ---- | -------------- |
| subscribeInfo | [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md) | Yes  | Subscriber information.|

**Return value**
| Type                                                     | Description            |
| --------------------------------------------------------- | ---------------- |
| Promise\<[CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Define a subscriber to save the created subscriber object for subsequent subscription and unsubscription.
let subscriber:commonEventManager.CommonEventSubscriber;
// Attributes of a subscriber.
let subscribeInfo:commonEventManager.CommonEventSubscribeInfo = {
  events: ["event"]
};
// Create a subscriber.
commonEventManager.createSubscriber(subscribeInfo).then((commonEventSubscriber:commonEventManager.CommonEventSubscriber) => {
  console.info("createSubscriber success");
  subscriber = commonEventSubscriber;
}).catch((err: BusinessError) => {
  console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
});
```

## commonEventManager.createSubscriberSync<sup>10+</sup>

createSubscriberSync(subscribeInfo: CommonEventSubscribeInfo): CommonEventSubscriber

Creates a subscriber. The API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name         | Type                                                 | Mandatory| Description          |
| ------------- | ----------------------------------------------------- | ---- | -------------- |
| subscribeInfo | [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md) | Yes  | Subscriber information.|

**Return value**
| Type                                                     | Description            |
| --------------------------------------------------------- | ---------------- |
| [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md) | Promise used to return the subscriber object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Define a subscriber to save the created subscriber object for subsequent subscription and unsubscription.
let subscriber: commonEventManager.CommonEventSubscriber;
// Attributes of a subscriber.
let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
  events: ["event"]
};
// Create a subscriber.
try {
  subscriber = commonEventManager.createSubscriberSync(subscribeInfo);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`createSubscriberSync failed, code is ${err.code}, message is ${err.message}`);
}
```

## commonEventManager.subscribe

subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback\<CommonEventData>): void

Subscribes to a common event. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name      | Type                                               | Mandatory| Description                            |
| ---------- | ---------------------------------------------------- | ---- | -------------------------------- |
| subscriber | [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)     | Yes  | Subscriber object.                |
| callback   | AsyncCallback\<[CommonEventData](./js-apis-inner-commonEvent-commonEventData.md)> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Event Error Codes](./errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 801  | capability not supported.               |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Define a subscriber to save the created subscriber object for subsequent subscription and unsubscription.
let subscriber:commonEventManager.CommonEventSubscriber;
// Attributes of a subscriber.
let subscribeInfo:commonEventManager.CommonEventSubscribeInfo = {
  events: ["event"]
};
// Callback for common event subscription.
function SubscribeCB(err: BusinessError, data:commonEventManager.CommonEventData) {
  if (err) {
    console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("subscribe success, Consume callback " + JSON.stringify(data));
  }
}
// Callback for subscriber creation.
function createCB(err: BusinessError, commonEventSubscriber:commonEventManager.CommonEventSubscriber) {
  if(!err) {
    console.info("createSubscriber success");
    subscriber = commonEventSubscriber;
    // Subscribe to a common event.
    try {
      commonEventManager.subscribe(subscriber, SubscribeCB);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    }
  } else {
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
  }
}
// Create a subscriber.
try {
  commonEventManager.createSubscriber(subscribeInfo, createCB);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
}
```

## commonEventManager.unsubscribe

unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback\<void>): void

Unsubscribes from a common event. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name      | Type                                            | Mandatory| Description                    |
| ---------- | ----------------------------------------------- | ---- | ------------------------ |
| subscriber | [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md) | Yes  | Subscriber object.        |
| callback   | AsyncCallback\<void>                            | No  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Event Error Codes](./errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 801  | capability not supported.               |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Define a subscriber to save the created subscriber object for subsequent subscription and unsubscription.
let subscriber:commonEventManager.CommonEventSubscriber; 
// Attributes of a subscriber.
let subscribeInfo:commonEventManager.CommonEventSubscribeInfo = {
  events: ["event"]
};
// Callback for common event subscription.
function subscribeCB(err: BusinessError, data:commonEventManager.CommonEventData) {
  if (err) {
    console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("subscribe success, Consume callback " + JSON.stringify(data));
  }
}
// Callback for subscriber creation.
function createCB(err: BusinessError, commonEventSubscriber:commonEventManager.CommonEventSubscriber) {
  if (err) {
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("createSubscriber success");
    subscriber = commonEventSubscriber;
    // Subscribe to a common event.
    try {
      commonEventManager.subscribe(subscriber, subscribeCB);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    }
  }
}
// Callback for common event unsubscription.
function unsubscribeCB(err: BusinessError) {
  if (err) {
    console.error(`unsubscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("unsubscribe success");
  }
}
// Create a subscriber.
try {
  commonEventManager.createSubscriber(subscribeInfo, createCB);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
}

// Unsubscribe from the common event.
// Wait until execution of the asynchronous API subscribe is completed. Add setTimeout when necessary.
setTimeout(() => {
  try {
    commonEventManager.unsubscribe(subscriber, unsubscribeCB);
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`unsubscribe failed, code is ${err.code}, message is ${err.message}`);
  }
}, 500);
```
