# @ohos.commonEvent (Common Event)

The **CommonEvent** module provides common event capabilities, including the capabilities to publish, subscribe to, and unsubscribe from common events, as well obtaining and setting the common event result code and result data.

> **NOTE**
> - The APIs provided by this module are no longer maintained since API version 9. You are advised to use [@ohos.commonEventManager](js-apis-commonEventManager.md).
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import CommonEvent from '@ohos.commonEvent';
```

## Support

A system common event is an event that is published by a system service or system application and requires specific permissions to subscribe to. To publish or subscribe to this type of event, you must follow the event-specific definitions.

For details about the definitions of all system common events, see [System Common Events](./common_event/commonEvent-definitions.md).

## CommonEvent.publish<sup>(deprecated)</sup>

publish(event: string, callback: AsyncCallback\<void>): void

Publishes a common event. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [commonEventManager.publish](js-apis-commonEventManager.md#commoneventmanagerpublish) instead.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name    | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| event    | string               | Yes  | Name of the common event to publish.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

// Callback for common event publication
function publishCB(err:Base.BusinessError) {
	if (err.code) {
        console.error(`publish failed, code is ${err.code}`);
    } else {
        console.info("publish");
    }
}

// Publish a common event.
CommonEvent.publish("event", publishCB);
```

## CommonEvent.publish<sup>(deprecated)</sup>

publish(event: string, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

Publishes a common event with given attributes. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [commonEventManager.publish](js-apis-commonEventManager.md#commoneventmanagerpublish-1) instead.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name    | Type                  | Mandatory| Description                  |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | Yes  | Name of the common event to publish. |
| options  | [CommonEventPublishData](./js-apis-inner-commonEvent-commonEventPublishData.md) | Yes  | Attributes of the common event to publish.|
| callback | AsyncCallback\<void>   | Yes  | Callback used to return the result. |

**Example**


```ts
import Base from '@ohos.base';
import CommonEventManager from '@ohos.commonEventManager';

// Attributes of a common event.
let options:CommonEventManager.CommonEventPublishData = {
	code: 0,			 // Result code of the common event.
	data: "initial data";// Result data of the common event.
	isOrdered: true	 // The common event is an ordered one.
}

// Callback for common event publication
function publishCB(err:Base.BusinessError) {
	if (err.code) {
        console.error(`publish failed, code is ${err.code}`);
    } else {
        console.info("publish");
    }
}

// Publish a common event.
CommonEvent.publish("event", options, publishCB);
```

## CommonEvent.createSubscriber<sup>(deprecated)</sup>

createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback\<CommonEventSubscriber>): void

Creates a subscriber. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
>This API is supported since API version 7 and deprecated since API version 9. You are advised to use [commonEventManager.createSubscriber](js-apis-commonEventManager.md#commoneventmanagercreatesubscriber) instead.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name         | Type                                                        | Mandatory| Description                      |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------- |
| subscribeInfo | [CommonEventSubscribeInfo](./js-apis-inner-commonEvent-commonEventSubscribeInfo.md)        | Yes  | Subscriber information.            |
| callback      | AsyncCallback\<[CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)> | Yes  | Callback used to return the result.|

**Example**


```ts
import Base from '@ohos.base';
import CommonEventManager from '@ohos.commonEventManager';

let subscriber:CommonEventManager.CommonEventSubscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {
    events: ["event"]
};

// Callback for subscriber creation.
function createCB(err:Base.BusinessError, commonEventSubscriber:CommonEventManager.CommonEventSubscriber) {
    if (err.code) {
        console.error(`createSubscriber failed, code is ${err.code}`);
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
    }
}

// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo, createCB);
```

## CommonEvent.createSubscriber<sup>(deprecated)</sup>

createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise\<CommonEventSubscriber>

Creates a subscriber. This API uses a promise to return the result.

> **NOTE**<br>
>This API is supported since API version 7 and deprecated since API version 9. You are advised to use [commonEventManager.createSubscriber](js-apis-commonEventManager.md#commoneventmanagercreatesubscriber-1) instead.

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
import CommonEventManager from '@ohos.commonEventManager';

let subscriber:CommonEventManager.CommonEventSubscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {
    events: ["event"]
};

// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo).then((commonEventSubscriber:CommonEventManager.CommonEventSubscriber) => {
    console.info("createSubscriber");
    subscriber = commonEventSubscriber;
}).catch((err:Base.BusinessError) => {
    console.error(`createSubscriber failed, code is ${err.code}`);
});
```

## CommonEvent.subscribe<sup>(deprecated)</sup>

subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback\<CommonEventData>): void

Subscribes to common events. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
>This API is supported since API version 7 and deprecated since API version 9. You are advised to use [commonEventManager.subscribe](js-apis-commonEventManager.md#commoneventmanagersubscribe) instead.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name      | Type                                               | Mandatory| Description                            |
| ---------- | ---------------------------------------------------- | ---- | -------------------------------- |
| subscriber | [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md)     | Yes  | Subscriber object.                |
| callback   | AsyncCallback\<[CommonEventData](./js-apis-inner-commonEvent-commonEventData.md)> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';
import CommonEventManager from '@ohos.commonEventManager';

let subscriber:CommonEventManager.CommonEventSubscriber;// Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {
    events: ["event"]
};

// Callback for common event subscription.
function subscribeCB(err:Base.BusinessError, data:CommonEventManager.CommonEventData) {
    if (err.code) {
        console.error(`subscribe failed, code is ${err.code}`);
    } else {
        console.info("subscribe " + JSON.stringify(data));
    }
}

// Callback for subscriber creation.
function createCB(err:Base.BusinessError, commonEventSubscriber:CommonEventManager.CommonEventSubscriber) {
    if (err.code) {
        console.error(`createSubscriber failed, code is ${err.code}`);
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        // Subscribe to a common event.
        CommonEvent.subscribe(subscriber, subscribeCB);
    }
}

// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo, createCB);
```

## CommonEvent.unsubscribe<sup>(deprecated)</sup>

unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback\<void>): void

Unsubscribes from common events. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
>This API is supported since API version 7 and deprecated since API version 9. You are advised to use [commonEventManager.subscribe](js-apis-commonEventManager.md#commoneventmanagerunsubscribe) instead.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name      | Type                                            | Mandatory| Description                    |
| ---------- | ----------------------------------------------- | ---- | ------------------------ |
| subscriber | [CommonEventSubscriber](./js-apis-inner-commonEvent-commonEventSubscriber.md) | Yes  | Subscriber object.        |
| callback   | AsyncCallback\<void>                            | No  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';
import CommonEventManager from '@ohos.commonEventManager';

let subscriber:CommonEventManager.CommonEventSubscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
let subscribeInfo:CommonEventManager.CommonEventSubscribeInfo = {
    events: ["event"]
};

// Callback for common event subscription.
function subscribeCB(err:Base.BusinessError, data:CommonEventManager.CommonEventData) {
    if (err.code) {
        console.error(`subscribe failed, code is ${err.code}`);
    } else {
        console.info("subscribe " + JSON.stringify(data));
    }
}

// Callback for subscriber creation.
function createCB(err:Base.BusinessError, commonEventSubscriber:CommonEventManager.CommonEventSubscriber) {
    if (err.code) {
        console.error(`createSubscriber failed, code is ${err.code}`);
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        // Subscribe to a common event.
        CommonEvent.subscribe(subscriber, subscribeCB);
    }
}

// Callback for common event unsubscription.
function unsubscribeCB(err:Base.BusinessError) {
    if (err.code) {
        console.error(`unsubscribe failed, code is ${err.code}`);
    } else {
        console.info("unsubscribe");
    }
}

// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo, createCB);

// Unsubscribe from the common event.
CommonEvent.unsubscribe(subscriber, unsubscribeCB);
```
