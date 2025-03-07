# @ohos.commonEvent (Common Event) (System API)

The **CommonEvent** module provides common event capabilities, including the capabilities to publish, subscribe to, and unsubscribe from common events, as well obtaining and setting the common event result code and result data.

> **NOTE**
> The APIs provided by this module are no longer maintained since API version 9. You are advised to use [@ohos.commonEventManager](js-apis-commonEventManager.md).
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [CommonEvent](./js-apis-commonEvent.md).

## Modules to Import

```ts
import commonEvent from '@ohos.commonEvent';
```

## Support

A system common event is an event that is published by a system service or system application and requires specific permissions to subscribe to. To publish or subscribe to this type of event, you must follow the event-specific definitions.

For details about the definitions of all system common events, see [System Common Events](./common_event/commonEvent-definitions.md).

## commonEvent.publishAsUser<sup>(deprecated)</sup>

publishAsUser(event: string, userId: number, callback: AsyncCallback\<void>): void

Publishes a common event to a specific user. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [commonEventManager.publishAsUser](js-apis-commonEventManager-sys.md#commoneventmanagerpublishasuser) instead.

**System capability**: SystemCapability.Notification.CommonEvent

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                | Mandatory| Description                              |
| -------- | -------------------- | ---- | ---------------------------------- |
| event    | string               | Yes  | Name of the common event to publish.            |
| userId   | number               | Yes  | User ID.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.            |

**Example**

```ts
import Base from '@ohos.base';

// Callback for common event publication
function publishCB(err:Base.BusinessError) {
	if (err.code) {
        console.error(`publishAsUser failed, code is ${err.code}`);
    } else {
        console.info("publishAsUser");
    }
}

// Specify the user to whom the common event will be published.
let userId = 100;

// Publish a common event.
commonEvent.publishAsUser("event", userId, publishCB);
```

## commonEvent.publishAsUser<sup>(deprecated)</sup>

publishAsUser(event: string, userId: number, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

Publishes a common event with given attributes to a specific user. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [commonEventManager.publishAsUser](js-apis-commonEventManager-sys.md#commoneventmanagerpublishasuser-1) instead.

**System capability**: SystemCapability.Notification.CommonEvent

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                  | Mandatory| Description                  |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | Yes  | Name of the common event to publish. |
| userId   | number | Yes| User ID.|
| options  | [CommonEventPublishData](./js-apis-inner-commonEvent-commonEventPublishData.md) | Yes  | Attributes of the common event to publish.|
| callback | AsyncCallback\<void>   | Yes  | Callback used to return the result. |

**Example**


```ts
import Base from '@ohos.base';
import CommonEventManager from '@ohos.commonEventManager';

// Attributes of a common event.
let options:CommonEventManager.CommonEventPublishData = {
	code: 0,			 // Result code of the common event.
	data: "initial data",// Result data of the common event.
}

// Callback for common event publication
function publishCB(err:Base.BusinessError) {
    if (err.code) {
        console.error(`publishAsUser failed, code is ${err.code}`);
    } else {
        console.info("publishAsUser");
    }
}

// Specify the user to whom the common event will be published.
let userId = 100;

// Publish a common event.
commonEvent.publishAsUser("event", userId, options, publishCB);
```


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
        commonEvent.subscribe(subscriber, subscribeCB);
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
commonEvent.createSubscriber(subscribeInfo, createCB);

// Unsubscribe from the common event.
commonEvent.unsubscribe(subscriber, unsubscribeCB);
```
