# @ohos.commonEventManager (Common Event)

The **CommonEventManager** module provides common event capabilities, including the capabilities to publish, subscribe to, and unsubscribe from common events.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import CommonEventManager from '@ohos.commonEventManager';
```

## Support

A system common event is an event that is published by a system service or system application and requires specific permissions to subscribe to. To publish or subscribe to this type of event, you must follow the event-specific definitions.

For details about the definitions of all system common events, see [System Common Events](./commonEventManager-definitions.md).

## CommonEventManager.publish

publish(event: string, callback: AsyncCallback\<void>): void

Publishes a common event and executes an asynchronous callback after the event is published.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name    | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| event    | string               | Yes  | Name of the common event to publish.|
| callback | AsyncCallback\<void> | Yes  | Callback to execute after the event is published.|

**Error codes**

 For details about the error codes, see [Event Error Codes](../errorcodes/errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**Example**

```ts
import Base from '@ohos.base';

// Callback for common event publication
function publishCB(err:Base.BusinessError) {
    if (err) {
        console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publish");
    }
}

// Publish a common event.
try {
    CommonEventManager.publish("event", publishCB);
} catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
}
```

## CommonEventManager.publish

publish(event: string, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

Publishes a common event with given attributes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name    | Type                  | Mandatory| Description                  |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | Yes  | Name of the common event to publish. |
| options  | [CommonEventPublishData](./js-apis-inner-commonEvent-commonEventPublishData.md) | Yes  | Attributes of the common event to publish.|
| callback | syncCallback\<void>   | Yes  | Callback used to return the result. |

**Error codes**

 For details about the error codes, see [Event Error Codes](../errorcodes/errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**Example**

```ts
import Base from '@ohos.base';

// Attributes of a common event.
let options:CommonEventManager.CommonEventPublishData = {
	code: 0,			 // Result code of the common event.
	data: "initial data",// Result data of the common event.
	isOrdered: true	 // The common event is an ordered one.
}

// Callback for common event publication
function publishCB(err:Base.BusinessError) {
	if (err) {
        console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publish");
    }
}

// Publish a common event.
try {
    CommonEventManager.publish("event", options, publishCB);
} catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
}
```

## CommonEventManager.publishAsUser<sup>

publishAsUser(event: string, userId: number, callback: AsyncCallback\<void>): void

Publishes a common event to a specific user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| event    | string               | Yes  | Name of the common event to publish.            |
| userId   | number               | Yes  | User ID.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.            |

**Error codes**

 For details about the error codes, see [Event Error Codes](../errorcodes/errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**Example**

```ts
import Base from '@ohos.base';

// Callback for common event publication
function publishCB(err:Base.BusinessError) {
	if (err) {
        console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publishAsUser");
    }
}

// Specify the user to whom the common event will be published.
let userId = 100;

// Publish a common event.
try {
    CommonEventManager.publishAsUser("event", userId, publishCB);
} catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);
}
```

## CommonEventManager.publishAsUser

publishAsUser(event: string, userId: number, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

Publishes a common event with given attributes to a specific user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                  | Mandatory| Description                  |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | Yes  | Name of the common event to publish. |
| userId   | number | Yes| User ID.|
| options  | [CommonEventPublishData](./js-apis-inner-commonEvent-commonEventPublishData.md) | Yes  | Attributes of the common event to publish.|
| callback | AsyncCallback\<void>   | Yes  | Callback used to return the result. |

**Error codes**

 For details about the error codes, see [Event Error Codes](../errorcodes/errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1500004  | not System services or System app.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**Example**


```ts
import Base from '@ohos.base';

// Attributes of a common event.
let options:CommonEventManager.CommonEventPublishData = {
	code: 0,			 // Result code of the common event.
	data: "initial data",// Result data of the common event.
}

// Callback for common event publication.
function publishCB(err:Base.BusinessError) {
	if (err) {
        console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publishAsUser");
    }
}

// Specify the user to whom the common event will be published.
let userId = 100;

// Publish a common event.
try {
    CommonEventManager.publishAsUser("event", userId, options, publishCB);
} catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`publishAsUser failed, code is ${err.code}, message is ${err.message}`);
}
```

## CommonEventManager.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback\<CommonEventSubscriber>): void

Creates a subscriber. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name         | Type                                                        | Mandatory| Description                      |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------- |
| subscribeInfo | [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md)        | Yes  | Subscriber information.            |
| callback      | AsyncCallback\<[CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let subscriber:CommonEventManager.CommonEventSubscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {
    events: ["event"]
};

// Callback for subscriber creation.
function createCB(err:Base.BusinessError, commonEventSubscriber:CommonEventManager.CommonEventSubscriber) {
    if(!err) {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
    } else {
        console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
    }
}

// Create a subscriber.
try {
    CommonEventManager.createSubscriber(subscribeInfo, createCB);
} catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
}
```

## CommonEventManager.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise\<CommonEventSubscriber>

Creates a subscriber. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name         | Type                                                 | Mandatory| Description          |
| ------------- | ----------------------------------------------------- | ---- | -------------- |
| subscribeInfo | [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md) | Yes  | Subscriber information.|

**Return value**
| Type                                                     | Description            |
| --------------------------------------------------------- | ---------------- |
| Promise\<[CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)> | Promise used to return the subscriber object.|

**Example**

```ts
import Base from '@ohos.base';

let subscriber:CommonEventManager.CommonEventSubscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {
	events: ["event"]
};

// Create a subscriber.
CommonEventManager.createSubscriber(subscribeInfo).then((commonEventSubscriber:CommonEventManager.CommonEventSubscriber) => {
    console.info("createSubscriber");
    subscriber = commonEventSubscriber;
}).catch((err:Base.BusinessError) => {
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
});

```

## CommonEventManager.createSubscriberSync<sup>10+</sup>

createSubscriberSync(subscribeInfo: CommonEventSubscribeInfo): CommonEventSubscriber

Creates a subscriber. The API returns the result synchronously.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name         | Type                                                 | Mandatory| Description          |
| ------------- | ----------------------------------------------------- | ---- | -------------- |
| subscribeInfo | [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md) | Yes  | Subscriber information.|

**Return value**
| Type                                                     | Description            |
| --------------------------------------------------------- | ---------------- |
| [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md) | Promise used to return the subscriber object.|

**Example**

```ts
import Base from '@ohos.base';

let subscriber: CommonEventManager.CommonEventSubscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
let subscribeInfo: CommonEventManager.CommonEventSubscribeInfo = {
  events: ["event"]
};

// Create a subscriber.
try {
    subscriber = CommonEventManager.createSubscriberSync(subscribeInfo);
} catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`createSubscriberSync failed, code is ${err.code}, message is ${err.message}`);
}

```

## CommonEventManager.subscribe

subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback\<CommonEventData>): void

Subscribes to common events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name      | Type                                               | Mandatory| Description                            |
| ---------- | ---------------------------------------------------- | ---- | -------------------------------- |
| subscriber | [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)     | Yes  | Subscriber object.                |
| callback   | AsyncCallback\<[CommonEventData](./js-apis-inner-commonEvent-commonEventData.md)> | Yes  | Callback used to return the result.|

**Error codes**

 For details about the error codes, see [Event Error Codes](../errorcodes/errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 801  | capability not supported.               |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |

**Example**

```ts
import Base from '@ohos.base';

let subscriber:CommonEventManager.CommonEventSubscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {
    events: ["event"]
};

// Callback for common event subscription.
function SubscribeCB(err:Base.BusinessError, data:CommonEventManager.CommonEventData) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribe ");
    }
}

// Callback for subscriber creation.
function createCB(err:Base.BusinessError, commonEventSubscriber:CommonEventManager.CommonEventSubscriber) {
    if(!err) {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        // Subscribe to a common event.
        try {
            CommonEventManager.subscribe(subscriber, SubscribeCB);
        } catch (error) {
            let err:Base.BusinessError = error as Base.BusinessError;
            console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
        }
    } else {
        console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
    }
}

// Create a subscriber.
try {
    CommonEventManager.createSubscriber(subscribeInfo, createCB);
} catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
}
```

## CommonEventManager.unsubscribe

unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback\<void>): void

Unsubscribes from common events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name      | Type                                            | Mandatory| Description                    |
| ---------- | ----------------------------------------------- | ---- | ------------------------ |
| subscriber | [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md) | Yes  | Subscriber object.        |
| callback   | AsyncCallback\<void>                            | No  | Callback used to return the result.|

**Error codes**

 For details about the error codes, see [Event Error Codes](../errorcodes/errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 801  | capability not supported.               |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |

**Example**

```ts
import Base from '@ohos.base';

let subscriber:CommonEventManager.CommonEventSubscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.
// Subscriber information.
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {
    events: ["event"]
};
// Callback for common event subscription.
function subscribeCB(err:Base.BusinessError, data:CommonEventManager.CommonEventData) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribe");
    }
}
// Callback for subscriber creation.
function createCB(err:Base.BusinessError, commonEventSubscriber:CommonEventManager.CommonEventSubscriber) {
    if (err) {
        console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        // Subscribe to a common event.
        try {
            CommonEventManager.subscribe(subscriber, subscribeCB);
        } catch (error) {
            let err:Base.BusinessError = error as Base.BusinessError;
            console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
        }
    }
}
// Callback for common event unsubscription.
function unsubscribeCB(err:Base.BusinessError) {
    if (err) {
        console.error(`unsubscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("unsubscribe");
    }
}
// Create a subscriber.
try {
    CommonEventManager.createSubscriber(subscribeInfo, createCB);
} catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`createSubscriber failed, code is ${err.code}, message is ${err.message}`);
}

// Unsubscribe from the common event.
// Wait until execution of the asynchronous API subscribe is completed. Add setTimeout when necessary.
setTimeout(() => {
  try {
    CommonEventManager.unsubscribe(subscriber, unsubscribeCB);
  } catch (error) {
    let err:Base.BusinessError = error as Base.BusinessError;
    console.error(`unsubscribe failed, code is ${err.code}, message is ${err.message}`);
  }
}, 500);
```

## CommonEventManager.removeStickyCommonEvent<sup>10+</sup>

removeStickyCommonEvent(event: string, callback: AsyncCallback\<void>): void

Removes a sticky common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Required permissions**: ohos.permission.COMMONEVENT_STICKY

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                | Mandatory| Description                            |
| -------- | -------------------- | ---- | -------------------------------- |
| event    | string               | Yes  | Sticky common event to remove.      |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

 For details about the error codes, see [Event Error Codes](../errorcodes/errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1500004  | not system service.                 |
| 1500007  | error sending message to Common Event Service.             |
| 1500008  | Common Event Service does not complete initialization.     |

**Example**


```ts
import Base from '@ohos.base';

CommonEventManager.removeStickyCommonEvent("sticky_event", (err:Base.BusinessError) => {
    if (err) {
        console.info(`Remove sticky event AsyncCallback failed, errCode: ${err.code}, errMes: ${err.message}`);
        return;
    }
    console.info(`Remove sticky event AsyncCallback success`);
});
```

## CommonEventManager.removeStickyCommonEvent<sup>10+</sup>

removeStickyCommonEvent(event: string): Promise\<void>

Removes a sticky common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Required permissions**: ohos.permission.COMMONEVENT_STICKY

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| event  | string | Yes  | Sticky common event to remove.|

**Return value**

| Type          | Description                        |
| -------------- | ---------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

 For details about the error codes, see [Event Error Codes](../errorcodes/errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1500004  | not system service.                 |
| 1500007  | error sending message to Common Event Service.             |
| 1500008  | Common Event Service does not complete initialization.     |

**Example**


```ts
import Base from '@ohos.base';

CommonEventManager.removeStickyCommonEvent("sticky_event").then(() => {
    console.info(`Remove sticky event AsyncCallback success`);
}).catch ((err:Base.BusinessError) => {
    console.info(`Remove sticky event AsyncCallback failed, errCode: ${err.code}, errMes: ${err.message}`);
});
```

## CommonEventManager.setStaticSubscriberState<sup>10+</sup>

setStaticSubscriberState(enable: boolean, callback: AsyncCallback\<void>): void;

Enables or disables static subscription for the current application. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Notification.CommonEvent

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| enable  | boolean | Yes  | Whether static subscription is enabled.<br> **true**: enabled.<br>**false**: disabled.|
| callback  | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

 For details about the error codes, see [Event Error Codes](../errorcodes/errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1500007  | error sending message to Common Event Service.             |
| 1500008  | Common Event Service does not complete initialization.     |

**Example**


```ts
import Base from '@ohos.base';

CommonEventManager.setStaticSubscriberState(true, (err:Base.BusinessError) => {
    if (!err) {
        console.info(`Set static subscriber state callback failed, err is null.`);
        return;
    }
    if (err.code !== undefined && err.code != null) {
        console.info(`Set static subscriber state callback failed, errCode: ${err.code}, errMes: ${err.message}`);
        return;
    }
    console.info(`Set static subscriber state callback success`);
});
```

## CommonEventManager.setStaticSubscriberState<sup>10+</sup>

setStaticSubscriberState(enable: boolean): Promise\<void>;

Enables or disables static subscription for the current application. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Notification.CommonEvent

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| enable  | boolean | Yes  | Whether static subscription is enabled.<br> **true**: enabled.<br>**false**: disabled.|

**Return value**

| Type          | Description                        |
| -------------- | ---------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

 For details about the error codes, see [Event Error Codes](../errorcodes/errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1500007  | error sending message to Common Event Service.             |
| 1500008  | Common Event Service does not complete initialization.     |

**Example**


```ts
import Base from '@ohos.base';

CommonEventManager.setStaticSubscriberState(false).then(() => {
    console.info(`Set static subscriber state promise success`);
}).catch ((err:Base.BusinessError) => {
    console.info(`Set static subscriber state promise failed, errCode: ${err.code}, errMes: ${err.message}`);
});
```
