# @ohos.commonEvent (Common Event)

The **CommonEvent** module provides common event capabilities, including the capabilities to publish, subscribe to, and unsubscribe from common events, as well obtaining and setting the common event result code and result data.

> **NOTE**
>
> - The APIs provided by this module are no longer maintained since API version 9. You are advised to use [@ohos.commonEventManager](js-apis-commonEventManager.md).
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import CommonEvent from '@ohos.commonEvent';
```

## Support

A system common event is an event that is published by a system service or system application and requires specific permissions to subscribe to. To publish or subscribe to this type of event, you must follow the event-specific definitions.

For details about the definitions of all system common events, see [System Common Events](./commonEvent-definitions.md).

## CommonEvent.publish

```ts
publish(event: string, callback: AsyncCallback<void>): void
```

Publishes a common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name    | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| event    | string               | Yes  | Name of the common event to publish.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
// Callback for common event publication
function publishCB(err) {
	if (err.code) {
        console.error("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish");
    }
}

// Publish a common event.
CommonEvent.publish("event", publishCB);
```

## CommonEvent.publish

```ts
publish(event: string, options: CommonEventPublishData, callback: AsyncCallback<void>): void
```

Publishes a common event with given attributes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name    | Type                  | Mandatory| Description                  |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | Yes  | Name of the common event to publish. |
| options  | [CommonEventPublishData](#commoneventpublishdata) | Yes  | Attributes of the common event to publish.|
| callback | syncCallback\<void>   | Yes  | Callback used to return the result. |

**Example**


```ts
// Attributes of a common event.
let options = {
	code: 0,			 // Initial code of the common event.
	data: "initial data";// Initial data of the common event.
	isOrdered: true	 // The common event is an ordered one.
}

// Callback for common event publication
function publishCB(err) {
	if (err.code) {
        console.error("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish");
    }
}

// Publish a common event.
CommonEvent.publish("event", options, publishCB);
```

## CommonEvent.publishAsUser<sup>8+</sup>

```ts
publishAsUser(event: string, userId: number, callback: AsyncCallback<void>): void
```

Publishes a common event to a specific user. This API uses an asynchronous callback to return the result.

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
// Callback for common event publication
function publishCB(err) {
	if (err.code) {
        console.error("publishAsUser failed " + JSON.stringify(err));
    } else {
        console.info("publishAsUser");
    }
}

// Specify the user to whom the common event will be published.
let userId = 100;

// Publish a common event.
CommonEvent.publishAsUser("event", userId, publishCB);
```

## CommonEvent.publishAsUser<sup>8+</sup>

```ts
publishAsUser(event: string, userId: number, options: CommonEventPublishData, callback: AsyncCallback<void>): void
```

Publishes a common event with given attributes to a specific user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                  | Mandatory| Description                  |
| -------- | ---------------------- | ---- | ---------------------- |
| event    | string                 | Yes  | Name of the common event to publish. |
| userId   | number | Yes| User ID.|
| options  | [CommonEventPublishData](#commoneventpublishdata) | Yes  | Attributes of the common event to publish.|
| callback | AsyncCallback\<void>   | Yes  | Callback used to return the result. |

**Example**


```ts
// Attributes of a common event.
let options = {
	code: 0,			 // Initial code of the common event.
	data: "initial data";// Initial data of the common event.
}

// Callback for common event publication
function publishCB(err) {
	if (err.code) {
        console.error("publishAsUser failed " + JSON.stringify(err));
    } else {
        console.info("publishAsUser");
    }
}

// Specify the user to whom the common event will be published.
let userId = 100;

// Publish a common event.
CommonEvent.publishAsUser("event", userId, options, publishCB);
```

## CommonEvent.createSubscriber

```ts
createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback<CommonEventSubscriber>): void
```

Creates a subscriber. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name         | Type                                                        | Mandatory| Description                      |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------- |
| subscribeInfo | [CommonEventSubscribeInfo](#commoneventsubscribeinfo)        | Yes  | Subscriber information.            |
| callback      | AsyncCallback\<[CommonEventSubscriber](#commoneventsubscriber)> | Yes  | Callback used to return the result.|

**Example**


```ts
let subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
let subscribeInfo = {
	events: ["event"]
};

// Callback for subscriber creation.
function createCB(err, commonEventSubscriber) {
    if (err.code) {
        console.error("createSubscriber failed " + JSON.stringify(err));
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
    }
}

// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo, createCB);
```

## CommonEvent.createSubscriber

```ts
createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise<CommonEventSubscriber>
```

Creates a subscriber. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name         | Type                                                 | Mandatory| Description          |
| ------------- | ----------------------------------------------------- | ---- | -------------- |
| subscribeInfo | [CommonEventSubscribeInfo](#commoneventsubscribeinfo) | Yes  | Subscriber information.|

**Return value**
| Type                                                     | Description            |
| --------------------------------------------------------- | ---------------- |
| Promise\<[CommonEventSubscriber](#commoneventsubscriber)> | Promise used to return the subscriber object.|

**Example**

```ts
let subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
let subscribeInfo = {
	events: ["event"]
};

// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo).then((commonEventSubscriber) => {
    console.info("createSubscriber");
    subscriber = commonEventSubscriber;
}).catch((err) => {
    console.error("createSubscriber failed " + JSON.stringify(err));
});
```

## CommonEvent.subscribe

```ts
subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback<CommonEventData>): void
```

Subscribes to common events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name      | Type                                               | Mandatory| Description                            |
| ---------- | ---------------------------------------------------- | ---- | -------------------------------- |
| subscriber | [CommonEventSubscriber](#commoneventsubscriber)     | Yes  | Subscriber object.                |
| callback   | AsyncCallback\<[CommonEventData](#commoneventdata)> | Yes  | Callback used to return the result.|

**Example**

```ts
let subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
let subscribeInfo = {
    events: ["event"]
};

// Callback for common event subscription.
function subscribeCB(err, data) {
    if (err.code) {
        console.error("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe " + JSON.stringify(data));
    }
}

// Callback for subscriber creation.
function createCB(err, subscriber) {
    if (err.code) {
        console.error("createSubscriber failed " + JSON.stringify(err));
    } else {
        console.info("createSubscriber");
        // Subscribe to a common event.
        CommonEvent.subscribe(subscriber, subscribeCB);
    }
}

// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo, createCB);
```

## CommonEvent.unsubscribe

```ts
unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback<void>): void
```

Unsubscribes from common events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name      | Type                                            | Mandatory| Description                    |
| ---------- | ----------------------------------------------- | ---- | ------------------------ |
| subscriber | [CommonEventSubscriber](#commoneventsubscriber) | Yes  | Subscriber object.        |
| callback   | AsyncCallback\<void>                            | No  | Callback used to return the result.|

**Example**

```ts
let subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
let subscribeInfo = {
	events: ["event"]
};

// Callback for common event subscription.
function subscribeCB(err, data) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe " + JSON.stringify(data));
    }
}

// Callback for subscriber creation.
function createCB(err, commonEventSubscriber) {
    if (err.code) {
        console.info("createSubscriber failed " + JSON.stringify(err));
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        // Subscribe to a common event.
        CommonEvent.subscribe(subscriber, subscribeCB);
    }
}

// Callback for common event unsubscription.
function unsubscribeCB(err) {
	if (err.code) {
        console.info("unsubscribe failed " + JSON.stringify(err));
    } else {
        console.info("unsubscribe");
    }
}

// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo, createCB);

// Unsubscribe from the common event.
CommonEvent.unsubscribe(subscriber, unsubscribeCB);
```

## CommonEventSubscriber

### getCode

```ts
getCode(callback: AsyncCallback<number>): void
```

Obtains the code of this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                  | Mandatory| Description              |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<number> | Yes  | Common event code.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

// Callback for result code obtaining of an ordered common event.
function getCodeCB(err, Code) {
    if (err.code) {
        console.error("getCode failed " + JSON.stringify(err));
    } else {
        console.info("getCode " + JSON.stringify(Code));
    }
}
subscriber.getCode(getCodeCB);
```

### getCode

```ts
getCode(): Promise<number>
```

Obtains the code of this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<number> | Common event code.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.getCode().then((code) => {
    console.info("getCode " + JSON.stringify(code));
}).catch((err) => {
    console.error("getCode failed " + JSON.stringify(err));
});
```

### setCode

```ts
setCode(code: number, callback: AsyncCallback<void>): void
```

Sets the code for this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | Yes  | Common event code.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

// Callback for result code setting of an ordered common event.
function setCodeCB(err) {
    if (err.code) {
        console.error("setCode failed " + JSON.stringify(err));
    } else {
        console.info("setCode");
    }
}
subscriber.setCode(1, setCodeCB);
```

### setCode

```ts
setCode(code: number): Promise<void>
```

Sets the code for this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| code   | number | Yes  | Common event code.|

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.setCode(1).then(() => {
    console.info("setCode");
}).catch((err) => {
    console.error("setCode failed " + JSON.stringify(err));
});
```

### getData

```ts
getData(callback: AsyncCallback<string>): void
```

Obtains the data of this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                  | Mandatory| Description                |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | Yes  | Common event data.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

// Callback for result data obtaining of an ordered common event.
function getDataCB(err, data) {
    if (err.code) {
        console.error("getData failed " + JSON.stringify(err));
    } else {
        console.info("getData " + JSON.stringify(data));
    }
}

subscriber.getData(getDataCB);
```

### getData

```ts
getData(): Promise<string>
```

Obtains the data of this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description              |
| ---------------- | ------------------ |
| Promise\<string> | Common event data.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.getData().then((data) => {
    console.info("getData " + JSON.stringify(data));
}).catch((err) => {
    console.error("getData failed " + JSON.stringify(err));
});
```

### setData

```ts
setData(data: string, callback: AsyncCallback<void>): void
```

Sets the data for this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| data     | string               | Yes  | Common event data.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

// Callback for result data setting of an ordered common event
function setDataCB(err) {
    if (err.code) {
        console.error("setData failed " + JSON.stringify(err));
    } else {
        console.info("setData");
    }
}
subscriber.setData("publish_data_changed", setDataCB);
```

### setData

```ts
setData(data: string): Promise<void>
```

Sets the data for this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| data   | string | Yes  | Common event data.|

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.setData("publish_data_changed").then(() => {
    console.info("setData");
}).catch((err) => {
    console.error("setData failed " + JSON.stringify(err));
});
```

### setCodeAndData

```ts
setCodeAndData(code: number, data: string, callback:AsyncCallback<void>): void
```

Sets the code and data for this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | Yes  | Common event code.  |
| data     | string               | Yes  | Common event data.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

// Callback for result code and result data setting of an ordered common event.
function setCodeDataCB(err) {
    if (err.code) {
        console.error("setCodeAndData failed " + JSON.stringify(err));
    } else {
        console.info("setCodeDataCallback");
    }
}

subscriber.setCodeAndData(1, "publish_data_changed", setCodeDataCB);
```

### setCodeAndData

```ts
setCodeAndData(code: number, data: string): Promise<void>
```

Sets the code and data for this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| code   | number | Yes  | Common event code.|
| data   | string | Yes  | Common event data.|

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.setCodeAndData(1, "publish_data_changed").then(() => {
    console.info("setCodeAndData");
}).catch((err) => {
    console.info("setCodeAndData failed " + JSON.stringify(err));
});
```

### isOrderedCommonEvent

```ts
isOrderedCommonEvent(callback: AsyncCallback<boolean>): void
```

Checks whether this common event is an ordered one. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Returns **true** if the common event is an ordered one; returns **false** otherwise.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

// Callback for checking whether the current common event is an ordered one.
function isOrderedCB(err, isOrdered) {
    if (err.code) {
        console.error("isOrderedCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("isOrdered " + JSON.stringify(isOrdered));
    }
}
subscriber.isOrderedCommonEvent(isOrderedCB);
```

### isOrderedCommonEvent

```ts
isOrderedCommonEvent(): Promise<boolean>
```

Checks whether this common event is an ordered one. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                            |
| ----------------- | -------------------------------- |
| Promise\<boolean> | Returns **true** if the common event is an ordered one; returns **false** otherwise.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.isOrderedCommonEvent().then((isOrdered) => {
    console.info("isOrdered " + JSON.stringify(isOrdered));
}).catch((err) => {
    console.error("isOrdered failed " + JSON.stringify(err));
});
```

### isStickyCommonEvent

```ts
isStickyCommonEvent(callback: AsyncCallback<boolean>): void
```

Checks whether this common event is a sticky one. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Returns **true** if the common event is a sticky one; returns **false** otherwise.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

// Callback for checking whether the current common event is a sticky one.
function isStickyCB(err, isSticky) {
    if (err.code) {
        console.error("isStickyCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("isSticky " + JSON.stringify(isSticky));
    }
}
subscriber.isStickyCommonEvent(isStickyCB);
```

### isStickyCommonEvent

```ts
isStickyCommonEvent(): Promise<boolean>
```

Checks whether this common event is a sticky one. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                            |
| ----------------- | -------------------------------- |
| Promise\<boolean> | Returns **true** if the common event is a sticky one; returns **false** otherwise.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.isStickyCommonEvent().then((isSticky) => {
    console.info("isSticky " + JSON.stringify(isSticky));
}).catch((err) => {
    console.error("isSticky failed " + JSON.stringify(err));
});
```

### abortCommonEvent

```ts
abortCommonEvent(callback: AsyncCallback<void>): void
```

Aborts this common event. After the abort, the common event is not sent to the next subscriber. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

// Callback for common event aborting.
function abortCB(err) {
    if (err.code) {
        console.error("abortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("abortCommonEvent");
    }
}

subscriber.abortCommonEvent(abortCB);
```

### abortCommonEvent

```ts
abortCommonEvent(): Promise<void>
```

Aborts this common event. After the abort, the common event is not sent to the next subscriber. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.abortCommonEvent().then(() => {
    console.info("abortCommonEvent");
}).catch((err) => {
    console.error("abortCommonEvent failed " + JSON.stringify(err));
});
```

### clearAbortCommonEvent

```ts
clearAbortCommonEvent(callback: AsyncCallback<void>): void
```

Clears the aborted state of this common event. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

// Callback for clearing the aborted state of the current common event.
function clearAbortCB(err) {
    if (err.code) {
        console.error("clearAbortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("clearAbortCommonEvent");
    }
}

subscriber.clearAbortCommonEvent(clearAbortCB);
```

### clearAbortCommonEvent

```ts
clearAbortCommonEvent(): Promise<void>
```

Clears the aborted state of this common event. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.clearAbortCommonEvent().then(() => {
    console.info("clearAbortCommonEvent");
}).catch((err) => {
    console.error("clearAbortCommonEvent failed " + JSON.stringify(err));
});
```

### getAbortCommonEvent

```ts
getAbortCommonEvent(callback: AsyncCallback<boolean>): void
```

Checks whether this common event is in the aborted state. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Returns **true** if the ordered common event is in the aborted state; returns **false** otherwise.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

// Callback for checking whether the current common event is in the aborted state.
function getAbortCB(err, abortEvent) {
    if (err.code) {
        console.error("getAbortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("abortEvent " + abortEvent)
    }
}

subscriber.getAbortCommonEvent(getAbortCB);
```

### getAbortCommonEvent

```ts
getAbortCommonEvent(): Promise<boolean>
```

Checks whether this common event is in the aborted state. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                              |
| ----------------- | ---------------------------------- |
| Promise\<boolean> | Returns **true** if the ordered common event is in the aborted state; returns **false** otherwise.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.getAbortCommonEvent().then((abortCommonEvent) => {
    console.info("abortCommonEvent " + JSON.stringify(abortCommonEvent));
}).catch((err) => {
    console.error("getAbortCommonEvent failed " + JSON.stringify(err));
});
```

### getSubscribeInfo

```ts
getSubscribeInfo(callback: AsyncCallback<CommonEventSubscribeInfo>): void
```

Obtains the subscriber information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                                                        | Mandatory| Description                  |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| callback | AsyncCallback\<[CommonEventSubscribeInfo](#commoneventsubscribeinfo)> | Yes  | Promise used to return the subscriber information.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

// Callback for subscriber information obtaining.
function getCB(err, subscribeInfo) {
    if (err.code) {
        console.error("getSubscribeInfo failed " + JSON.stringify(err));
    } else {
        console.info("SubscribeInfo " + JSON.stringify(subscribeInfo));
    }
}

subscriber.getSubscribeInfo(getCB);
```

### getSubscribeInfo

```ts
getSubscribeInfo(): Promise<CommonEventSubscribeInfo>
```

Obtains the subscriber information. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| Promise\<[CommonEventSubscribeInfo](#commoneventsubscribeinfo)> | Promise used to return the subscriber information.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.getSubscribeInfo().then((subscribeInfo) => {
    console.info("subscribeInfo " + JSON.stringify(subscribeInfo));
}).catch((err) => {
    console.error("getSubscribeInfo failed " + JSON.stringify(err));
});
```

### finishCommonEvent<sup>9+</sup>

```ts
finishCommonEvent(callback: AsyncCallback<void>): void
```

Finishes this common event. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                 | Mandatory| Description                             |
| -------- | -------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback returned after the ordered common event is finished.|

**Example**

```ts
let subscriber; // Subscriber object successfully created.

// Callback for ordered common event finishing.
function finishCB(err) {
    if (err.code) {
        console.error("finishCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("FinishCommonEvent");
    }
}

subscriber.finishCommonEvent(finishCB);
```

### finishCommonEvent<sup>9+</sup>

```ts
finishCommonEvent(): Promise<void>
```

Finishes this common event. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
let subscriber;	// Subscriber object successfully created.

subscriber.finishCommonEvent().then(() => {
    console.info("FinishCommonEvent");
}).catch((err) => {
    console.error("finishCommonEvent failed " + JSON.stringify(err));
});
```

## CommonEventData

Describes the common event data body.

**System capability**: SystemCapability.Notification.CommonEvent

| Name      | Type                | Readable| Writable| Description                                                   |
| ---------- |-------------------- | ---- | ---- |  ------------------------------------------------------- |
| event      | string               | Yes | No | Name of the common event that is being received.                             |
| bundleName | string               | Yes | No | Bundle name.                                     |
| code       | number               | Yes | No | Result code of the common event, which is used to transfer data of the int type.          |
| data       | string               | Yes | No | Custom result data of the common event, which is used to transfer data of the string type.|
| parameters | {[key: string]: any} | Yes | No | Additional information about the common event.                                 |


## CommonEventPublishData

Describes the data body published by a common event, including the common event content and attributes.

**System capability**: SystemCapability.Notification.CommonEvent

| Name                 | Type                | Readable| Writable| Description                        |
| --------------------- | -------------------- | ---- | ---- | ---------------------------- |
| bundleName            | string               | Yes | No | Bundle name.          |
| code                  | number               | Yes | No | Result code of the common event.      |
| data                  | string               | Yes | No | Custom result data of the common event.|
| subscriberPermissions | Array\<string\>       | Yes | No | Permissions required for subscribers to receive the common event.            |
| isOrdered             | boolean              | Yes | No | Whether the common event is an ordered one.          |
| isSticky              | boolean              | Yes | No | Whether the common event is a sticky one. Only system applications and system services are allowed to send sticky events.|
| parameters            | {[key: string]: any} | Yes | No | Additional information about the common event.      |

## CommonEventSubscribeInfo

Provides the subscriber information.

**System capability**: SystemCapability.Notification.CommonEvent

| Name               | Type          | Readable| Writable| Description                                                        |
| ------------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| events              | Array\<string\> | Yes | No | Name of the common event to publish.                                        |
| publisherPermission | string         | Yes | No | Permissions required for publishers to publish the common event.                                            |
| publisherDeviceId   | string         | Yes | No | Device ID. The value must be the ID of an existing device on the same network.            |
| userId              | number         | Yes | No | User ID. The default value is the ID of the current user. If this parameter is specified, the value must be an existing user ID in the system.|
| priority            | number         | Yes | No | Subscriber priority. The value ranges from -100 to +1000.                    |
