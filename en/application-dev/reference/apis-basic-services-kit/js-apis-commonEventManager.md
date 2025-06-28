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
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Event Error Codes](./errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- | 
| 1500003  | The common event sending frequency too high. |
| 1500007  | Failed to send the message to the common event service. |
| 1500008  | Failed to initialize the common event service. |
| 1500009  | Failed to obtain system parameters.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Publish a common event.
try {
  commonEventManager.publish('event', (err: BusinessError) => {
    if (err) {
      console.error(`Failed to publish common event. Code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info(`Succeeded in publishing common event.`);
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to publish common event. Code is ${err.code}, message is ${err.message}`);
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
| callback | AsyncCallback\<void>   | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Event Error Codes](./errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1500003  | The common event sending frequency too high. |
| 1500007  | Failed to send the message to the common event service. |
| 1500008  | Failed to initialize the common event service. |
| 1500009  | Failed to obtain system parameters.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Common event information. The following uses an ordered common event as an example.
let options: commonEventManager.CommonEventPublishData = {
  code: 0,
  data: 'initial data',
  isOrdered: true // The common event is an ordered one.
}

// Publish a common event.
try {
  commonEventManager.publish('event', options, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to publish common event. Code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info(`Succeeded in publishing common event.`);
  });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to publish common event. Code is ${err.code}, message is ${err.message}`);
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
| callback      | AsyncCallback\<[CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.    | 

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Define a subscriber to save the created subscriber object for subsequent subscription and unsubscription.
let subscriber: commonEventManager.CommonEventSubscriber;
// Attributes of a subscriber.
let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
  events: ['event']
};

// Create a subscriber.
try {
  commonEventManager.createSubscriber(subscribeInfo,
    (err: BusinessError, commonEventSubscriber: commonEventManager.CommonEventSubscriber) => {
      if(!err) {
        console.info(`Succeeded in creating subscriber.`);
        subscriber = commonEventSubscriber;
        return;
      }
      console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
    });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
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
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Define a subscriber to save the created subscriber object for subsequent subscription and unsubscription.
let subscriber: commonEventManager.CommonEventSubscriber;
// Attributes of a subscriber.
let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
  events: ['event']
};
// Create a subscriber.
commonEventManager.createSubscriber(subscribeInfo).then((commonEventSubscriber: commonEventManager.CommonEventSubscriber) => {
  console.info(`Succeeded in creating subscriber.`);
  subscriber = commonEventSubscriber;
}).catch((err: BusinessError) => {
  console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
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
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Define a subscriber to save the created subscriber object for subsequent subscription and unsubscription.
let subscriber: commonEventManager.CommonEventSubscriber;
// Attributes of a subscriber.
let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
  events: ['event']
};
// Create a subscriber.
try {
  subscriber = commonEventManager.createSubscriberSync(subscribeInfo);
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
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
| callback   | AsyncCallback\<[CommonEventData](./js-apis-inner-commonEvent-commonEventData.md)> | Yes  | Callback triggered if the operation is successful; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Event Error Codes](./errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 801  | capability not supported.               |
| 1500007  | Failed to send the message to the common event service. |
| 1500008  | Failed to initialize the common event service. |
| 1500010  | The count of subscriber exceed system specification. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Define a subscriber to save the created subscriber object for subsequent subscription and unsubscription.
let subscriber: commonEventManager.CommonEventSubscriber;
// Attributes of a subscriber.
let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
  events: ['event']
};

// Create a subscriber.
try {
  commonEventManager.createSubscriber(subscribeInfo,
    (err: BusinessError, commonEventSubscriber: commonEventManager.CommonEventSubscriber) => {
      if(!err) {
        console.info(`Succeeded in creating subscriber.`);
        subscriber = commonEventSubscriber;
        // Subscribe to a common event.
        try {
          commonEventManager.subscribe(subscriber, (err: BusinessError, data: commonEventManager.CommonEventData) => {
            if (err) {
              console.error(`Failed to subscribe. Code is ${err.code}, message is ${err.message}`);
              return;
            }
            console.info(`Succeeded in subscribing, data is ${JSON.stringify(data)}`);
          });
        } catch (error) {
          let err: BusinessError = error as BusinessError;
          console.error(`Failed to subscribe. Code is ${err.code}, message is ${err.message}`);
        }
        return;
      }
      console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
    });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
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
| callback   | AsyncCallback\<void>                            | No  | Callback to unregister. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Event Error Codes](./errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401     | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameter types.<br>3. Parameter verification failed.      | 
| 801  | capability not supported.               |
| 1500007  | Failed to send the message to the common event service. |
| 1500008  | Failed to initialize the common event service. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Define a subscriber to save the created subscriber object for subsequent subscription and unsubscription.
let subscriber: commonEventManager.CommonEventSubscriber | undefined; 
// Attributes of a subscriber.
let subscribeInfo: commonEventManager.CommonEventSubscribeInfo = {
  events: ['event']
};

// Create a subscriber.
try {
  commonEventManager.createSubscriber(subscribeInfo,
    (err: BusinessError, commonEventSubscriber: commonEventManager.CommonEventSubscriber) => {
      if(!err) {
        console.info(`Succeeded in creating subscriber.`);
        subscriber = commonEventSubscriber;
        // Subscribe to a common event.
        try {
          commonEventManager.subscribe(subscriber, (err: BusinessError, data: commonEventManager.CommonEventData) => {
            if (err) {
              console.error(`Failed to subscribe. Code is ${err.code}, message is ${err.message}`);
              return;
            }
            console.info(`Succeeded in subscribing, data is ${JSON.stringify(data)}`);
          });
        } catch (error) {
          let err: BusinessError = error as BusinessError;
          console.error(`Failed to subscribe. Code is ${err.code}, message is ${err.message}`);
        }
        return;
      }
      console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
    });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
}

// Unsubscribe from the common event.
// Wait until execution of the asynchronous API subscribe is completed. Add setTimeout when necessary.
setTimeout(() => {
  try {
    commonEventManager.unsubscribe(subscriber, (err: BusinessError) => {
      if (err) {
        console.error(`Failed to unsubscribe. Code is ${err.code}, message is ${err.message}`);
        return;
      }
      // If the subscriber is no longer used, set it to undefined to avoid memory leakage.
      subscriber = undefined;
      console.info(`Succeeded in unsubscribing.`);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`Failed to unsubscribe. Code is ${err.code}, message is ${err.message}`);
  }
}, 500);
```

## commonEventManager.subscribeToEvent<sup>20+</sup>

subscribeToEvent(subscriber: CommonEventSubscriber, callback: Callback\<CommonEventData>): Promise\<void>

Subscribes to common events. This API uses a promise to return the result, indicating subscription success or failure. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name      | Type                                               | Mandatory| Description                            |
| ---------- | ---------------------------------------------------- | ---- | -------------------------------- |
| subscriber | [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)     | Yes  | Subscriber object.                |
| callback   | Callback\<[CommonEventData](./js-apis-inner-commonEvent-commonEventData.md)> | Yes  | Callback to be invoked when a common event is subscribed to.|

**Return value**
| Type                                                     | Description            |
| --------------------------------------------------------- | ---------------- |
| Promise\<void>   | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Event Error Codes](./errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 801  | Capability not supported.               |
| 1500007  | Failed to send the message to the common event service. |
| 1500008  | Failed to initialize the common event service. |
| 1500010  | The count of subscriber exceed system specification. |

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
  commonEventManager.createSubscriber(subscribeInfo,
    (err: BusinessError, commonEventSubscriber: commonEventManager.CommonEventSubscriber) => {
      if (err) {
        console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
      } else {
        console.info(`Succeeded in creating subscriber.`);
        subscriber = commonEventSubscriber;
        // Subscribe to a common event.
        try {
          commonEventManager.subscribeToEvent(subscriber, (data: commonEventManager.CommonEventData) => {
            console.info(`Succeeded to receive common event, data is ` + JSON.stringify(data));
          }).then(() => {
            console.info(`Succeeded to subscribe.`);
          }).catch((err: BusinessError) => {
            console.error(`Failed to subscribe. Code is ${err.code}, message is ${err.message}`);
          });
        } catch (error) {
          let err: BusinessError = error as BusinessError;
          console.error(`Failed to subscribe. Code is ${err.code}, message is ${err.message}`);
        }
      }
    });
} catch (error) {
  let err: BusinessError = error as BusinessError;
  console.error(`Failed to create subscriber. Code is ${err.code}, message is ${err.message}`);
}
```

## CommonEventData<sup>10+</sup>

type CommonEventData = _CommonEventData

Describes the data of a common event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

| Type| Description|
| --- | --- |
| [_CommonEventData](js-apis-inner-commonEvent-commonEventData.md) | Data of a common event.|

## CommonEventSubscriber<sup>10+</sup>

type CommonEventSubscriber = _CommonEventSubscriber

Describes the subscriber of a common event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

| Type| Description|
| --- | --- |
| [_CommonEventSubscriber](js-apis-inner-commonEvent-commonEventSubscriber.md) | Subscriber of a common event.|

## CommonEventSubscribeInfo<sup>10+</sup>

type CommonEventSubscribeInfo = _CommonEventSubscribeInfo

Describes the information about a subscriber.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

| Type| Description|
| --- | --- |
| [_CommonEventSubscribeInfo](js-apis-inner-commonEvent-commonEventSubscribeInfo.md) | Information about a subscriber.|

## CommonEventPublishData<sup>10+</sup>

type CommonEventPublishData = _CommonEventPublishData

Describes the content and attributes of a common event.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Notification.CommonEvent

| Type| Description|
| --- | --- |
| [_CommonEventPublishData](js-apis-inner-commonEvent-commonEventPublishData.md) | Content and attributes of a common event.|
