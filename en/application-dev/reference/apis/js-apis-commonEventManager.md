# @ohos.commonEventManager (Common Event)

The **CommonEventManager** module provides common event capabilities, including the capabilities to publish, subscribe to, and unsubscribe from common events, as well obtaining and setting the common event result code and result data.

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

Publishes a common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name    | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| event    | string               | Yes  | Name of the common event to publish.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**
For details about the error codes, see [Event Error Codes](../errorcodes/errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401  | The parameter check failed.             |
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**Example**

```ts
// Callback for common event publication
function publishCallBack(err) {
	if (err) {
        console.error("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish");
    }
}

// Publish a common event.
try {
    CommonEventManager.publish("event", publishCallBack);
} catch(err) {
    console.error('publish failed, catch error' + JSON.stringify(err));
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
| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401  | The parameter check failed.             |
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**Example**

```ts
// Attributes of a common event.
var options = {
	code: 0,			 // Result code of the common event.
	data: "initial data",// Result data of the common event.
	isOrdered: true	 // The common event is an ordered one.
}

// Callback for common event publication
function publishCallBack(err) {
	if (err) {
        console.error("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish");
    }
}

// Publish a common event.
try {
    CommonEventManager.publish("event", options, publishCallBack);
} catch (err) {
    console.error('publish failed, catch error' + JSON.stringify(err));
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
| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202  | not system app.                         |
| 401  | The parameter check failed.             |
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**Example**

```ts
// Callback for common event publication
function publishAsUserCallBack(err) {
	if (err) {
        console.error("publishAsUser failed " + JSON.stringify(err));
    } else {
        console.info("publishAsUser");
    }
}

// Specify the user to whom the common event will be published.
var userId = 100;

// Publish a common event.
try {
    CommonEventManager.publishAsUser("event", userId, publishAsUserCallBack);
} catch (err) {
    console.error('publishAsUser failed, catch error' + JSON.stringify(err));
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
| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202  | not system app.                         |
| 401  | The parameter check failed.             |
| 1500004  | not System services.                |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |
| 1500009  | error obtaining system parameters.  |

**Example**

```ts
// Attributes of a common event.
var options = {
	code: 0,			 // Result code of the common event.
	data: "initial data",// Result data of the common event.
}

// Callback for common event publication
function publishAsUserCallBack(err) {
	if (err) {
        console.error("publishAsUser failed " + JSON.stringify(err));
    } else {
        console.info("publishAsUser");
    }
}

// Specify the user to whom the common event will be published.
var userId = 100;

// Publish a common event.
try {
    CommonEventManager.publishAsUser("event", userId, options, publishAsUserCallBack);
} catch (err) {
    console.error('publishAsUser failed, catch error' + JSON.stringify(err));
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

**Error codes**

 For details about the error codes, see [Event Error Codes](../errorcodes/errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401  | The parameter check failed.             |

**Example**


```ts
var subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
var subscribeInfo = {
    events: ["event"]
};

// Callback for subscriber creation.
function createSubscriberCallBack(err, commonEventSubscriber) {
    if(!err) {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
    } else {
        console.error("createSubscriber failed " + JSON.stringify(err));
    }
}

// Create a subscriber.
try {
    CommonEventManager.createSubscriber(subscribeInfo, createSubscriberCallBack);
} catch (err) {
    console.error('createSubscriber failed, catch error' + JSON.stringify(err));
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

**Error codes**

 For details about the error codes, see [Event Error Codes](../errorcodes/errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401  | The parameter check failed.             |

**Example**

```ts
var subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
var subscribeInfo = {
	events: ["event"]
};

// Create a subscriber.
try {
    CommonEventManager.createSubscriber(subscribeInfo).then((commonEventSubscriber) => {
    console.info("createSubscriber");
    subscriber = commonEventSubscriber;
}).catch((err) => {
    console.error("createSubscriber failed " + JSON.stringify(err));
});
} catch(err) {
    console.error('createSubscriber failed, catch error' + JSON.stringify(err));
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
| 401  | The parameter check failed.             |
| 801  | capability not supported.               |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |

**Example**

```ts
// Subscriber information.
var subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information.
var subscribeInfo = {
    events: ["event"]
};

// Callback for common event subscription.
function SubscribeCallBack(err, data) {
    if (err) {
        console.error("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe ");
    }
}

// Callback for subscriber creation.
function createSubscriberCallBack(err, commonEventSubscriber) {
    if(!err) {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        // Subscribe to a common event.
        try {
            CommonEventManager.subscribe(subscriber, SubscribeCallBack);
        } catch (err) {
            console.error("createSubscriber failed " + JSON.stringify(err));
        }
    } else {
        console.error("createSubscriber failed " + JSON.stringify(err));
    }
}

// Create a subscriber.
try {
    CommonEventManager.createSubscriber(subscribeInfo, createSubscriberCallBack);
} catch (err) {
    console.error('createSubscriber failed, catch error' + JSON.stringify(err));
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
| 401  | The parameter check failed.             |
| 801  | capability not supported.               |
| 1500007  | error sending message to Common Event Service. |
| 1500008  | Common Event Service does not complete initialization. |

**Example**

```ts
var subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.
// Subscriber information.
var subscribeInfo = {
    events: ["event"]
};
// Callback for common event subscription.
function subscribeCallBack(err, data) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe");
    }
}
// Callback for subscriber creation.
function createSubscriberCallBack(err, commonEventSubscriber) {
    if (err) {
        console.info("createSubscriber failed " + JSON.stringify(err));
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        // Subscribe to a common event.
        try {
            CommonEventManager.subscribe(subscriber, subscribeCallBack);
        } catch(err) {
            console.info("subscribe failed " + JSON.stringify(err));
        }
    }
}
// Callback for common event unsubscription.
function unsubscribeCallBack(err) {
    if (err) {
        console.info("unsubscribe failed " + JSON.stringify(err));
    } else {
        console.info("unsubscribe");
    }
}
// Create a subscriber.
try {
    CommonEventManager.createSubscriber(subscribeInfo, createSubscriberCallBack);
} catch (err) {
    console.info("createSubscriber failed " + JSON.stringify(err));
}

// Unsubscribe from the common event.
try {
    CommonEventManager.unsubscribe(subscriber, unsubscribeCallBack);
} catch (err) {
    console.info("unsubscribe failed " + JSON.stringify(err));
}
```

## CommonEventSubscriber

### getCode

getCode(callback: AsyncCallback\<number>): void

Obtains the result code of this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                  | Mandatory| Description              |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result.|

**Error codes**

 For details about the error codes, see [Event Error Codes](../errorcodes/errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201  | The application dose not have permission to call the interface. |
| 202  | not system app.                         |
| 401  | The parameter check failed.             |
| 1500004  | not system service.                 |
| 1500007  | The message send error.             |
| 1500008  | The CEMS error.                     |

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for result code obtaining of an ordered common event.
function getCodeCallback(err, Code) {
    if (err) {
        console.error("getCode failed " + JSON.stringify(err));
    } else {
        console.info("getCode " + JSON.stringify(Code));
    }
}
subscriber.getCode(getCodeCallback);
```

### getCode

getCode(): Promise\<number>

Obtains the result code of this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<number> | Promise used to return the result.|

**Error codes**

 For details about the error codes, see [Event Error Codes](../errorcodes/errorcode-CommonEventService.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201  | The application dose not have permission to call the interface. |
| 202  | not system app.                         |
| 401  | The parameter check failed.             |
| 1500004  | not system service.                 |
| 1500007  | The message send error.             |
| 1500008  | The CEMS error.                     |

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.getCode().then((Code) => {
    console.info("getCode " + JSON.stringify(Code));
}).catch((err) => {
    console.error("getCode failed " + JSON.stringify(err));
});
```

### setCode

setCode(code: number, callback: AsyncCallback\<void>): void

Sets the result code for this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | Yes  | Result code of the common event.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for result code setting of an ordered common event.
function setCodeCallback(err) {
    if (err) {
        console.error("setCode failed " + JSON.stringify(err));
    } else {
        console.info("setCode");
    }
}
subscriber.setCode(1, setCodeCallback);
```

### setCode

setCode(code: number): Promise\<void>

Sets the result code for this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| code   | number | Yes  | Result code of the common event.|

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.setCode(1).then(() => {
    console.info("setCode");
}).catch((err) => {
    console.error("setCode failed " + JSON.stringify(err));
});
```

### getData

getData(callback: AsyncCallback\<string>): void

Obtains the result data of this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                  | Mandatory| Description                |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the result data.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for result data obtaining of an ordered common event.
function getDataCallback(err, Data) {
    if (err) {
        console.error("getData failed " + JSON.stringify(err));
    } else {
        console.info("getData " + JSON.stringify(Data));
    }
}
subscriber.getData(getDataCallback);
```

### getData

getData(): Promise\<string>

Obtains the result data of this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description              |
| ---------------- | ------------------ |
| Promise\<string> | Promise used to return the result data.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.getData().then((Data) => {
    console.info("getData " + JSON.stringify(Data));
}).catch((err) => {
    console.error("getData failed " + JSON.stringify(err));
});
```

### setData

setData(data: string, callback: AsyncCallback\<void>): void

Sets the result data for this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| data     | string               | Yes  | Result data of the common event.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for result data setting of an ordered common event
function setDataCallback(err) {
    if (err) {
        console.error("setData failed " + JSON.stringify(err));
    } else {
        console.info("setData");
    }
}
subscriber.setData("publish_data_changed", setDataCallback);
```

### setData

setData(data: string): Promise\<void>

Sets the result data for this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| data   | string | Yes  | Result data of the common event.|

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.setData("publish_data_changed").then(() => {
    console.info("setData");
}).catch((err) => {
    console.error("setData failed " + JSON.stringify(err));
});
```

### setCodeAndData

setCodeAndData(code: number, data: string, callback:AsyncCallback\<void>): void

Sets the result code and result data for this common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | Yes  | Result code of the common event.  |
| data     | string               | Yes  | Result data of the common event.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for result code and result data setting of an ordered common event.
function setCodeDataCallback(err) {
    if (err) {
        console.error("setCodeAndData failed " + JSON.stringify(err));
    } else {
        console.info("setCodeDataCallback");
    }
}
subscriber.setCodeAndData(1, "publish_data_changed", setCodeDataCallback);
```

### setCodeAndData

setCodeAndData(code: number, data: string): Promise\<void>

Sets the result code and result data for this common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| code   | number | Yes  | Result code of the common event.|
| data   | string | Yes  | Result data of the common event.|

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.setCodeAndData(1, "publish_data_changed").then(() => {
    console.info("setCodeAndData");
}).catch((err) => {
    console.info("setCodeAndData failed " + JSON.stringify(err));
});
```

### isOrderedCommonEvent

isOrderedCommonEvent(callback: AsyncCallback\<boolean>): void

Checks whether this common event is an ordered one. This API uses an asynchronous callback to return the result.

 

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The value **true** means that the common event is an ordered one; and **false** means the opposite.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for checking whether the current common event is an ordered one.
function isOrderedCallback(err, isOrdered) {
    if (err) {
        console.error("isOrderedCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("isOrdered " + JSON.stringify(isOrdered));
    }
}
subscriber.isOrderedCommonEvent(isOrderedCallback);
```

### isOrderedCommonEvent

isOrderedCommonEvent(): Promise\<boolean>

Checks whether this common event is an ordered one. This API uses a promise to return the result.

 

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                            |
| ----------------- | -------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the common event is an ordered one; and **false** means the opposite.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.isOrderedCommonEvent().then((isOrdered) => {
    console.info("isOrdered " + JSON.stringify(isOrdered));
}).catch((err) => {
    console.error("isOrdered failed " + JSON.stringify(err));
});
```

### isStickyCommonEvent

isStickyCommonEvent(callback: AsyncCallback\<boolean>): void

Checks whether this common event is a sticky one. This API uses an asynchronous callback to return the result.

 

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The value **true** means that the common event is a sticky one; and **false** means the opposite.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for checking whether the current common event is a sticky one.
function isStickyCallback(err, isSticky) {
    if (err) {
        console.error("isStickyCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("isSticky " + JSON.stringify(isSticky));
    }
}
subscriber.isStickyCommonEvent(isStickyCallback);
```

### isStickyCommonEvent

isStickyCommonEvent(): Promise\<boolean>

Checks whether this common event is a sticky one. This API uses a promise to return the result.

 

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                            |
| ----------------- | -------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the common event is a sticky one; and **false** means the opposite.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.isStickyCommonEvent().then((isSticky) => {
    console.info("isSticky " + JSON.stringify(isSticky));
}).catch((err) => {
    console.error("isSticky failed " + JSON.stringify(err));
});
```

### abortCommonEvent

abortCommonEvent(callback: AsyncCallback\<void>): void

Aborts this common event. After the abort, the common event is not sent to the next subscriber. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for common event aborting.
function abortCallback(err) {
    if (err) {
        console.error("abortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("abortCommonEvent");
    }
}
subscriber.abortCommonEvent(abortCallback);
```

### abortCommonEvent

abortCommonEvent(): Promise\<void>

Aborts this common event. After the abort, the common event is not sent to the next subscriber. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.abortCommonEvent().then(() => {
    console.info("abortCommonEvent");
}).catch((err) => {
    console.error("abortCommonEvent failed " + JSON.stringify(err));
});
```

### clearAbortCommonEvent

clearAbortCommonEvent(callback: AsyncCallback\<void>): void

Clears the aborted state of this common event. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for clearing the aborted state of the current common event.
function clearAbortCallback(err) {
    if (err) {
        console.error("clearAbortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("clearAbortCommonEvent");
    }
}
subscriber.clearAbortCommonEvent(clearAbortCallback);
```

### clearAbortCommonEvent

clearAbortCommonEvent(): Promise\<void>

Clears the aborted state of this common event. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.clearAbortCommonEvent().then(() => {
    console.info("clearAbortCommonEvent");
}).catch((err) => {
    console.error("clearAbortCommonEvent failed " + JSON.stringify(err));
});
```

### getAbortCommonEvent

getAbortCommonEvent(callback: AsyncCallback\<boolean>): void

Checks whether this common event is in the aborted state. This API takes effect only for ordered common events. It uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The value **true** means that the ordered common event is in the aborted state; and **false** means the opposite.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for checking whether the current common event is in the aborted state.
function getAbortCallback(err, AbortCommonEvent) {
    if (err) {
        console.error("getAbortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("AbortCommonEvent " + AbortCommonEvent)
    }
}
subscriber.getAbortCommonEvent(getAbortCallback);
```

### getAbortCommonEvent

getAbortCommonEvent(): Promise\<boolean>

Checks whether this common event is in the aborted state. This API takes effect only for ordered common events. It uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                              |
| ----------------- | ---------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the ordered common event is in the aborted state; and **false** means the opposite.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.getAbortCommonEvent().then((AbortCommonEvent) => {
    console.info("AbortCommonEvent " + JSON.stringify(AbortCommonEvent));
}).catch((err) => {
    console.error("getAbortCommonEvent failed " + JSON.stringify(err));
});
```

### getSubscribeInfo

getSubscribeInfo(callback: AsyncCallback\<CommonEventSubscribeInfo>): void

Obtains the subscriber information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                                                        | Mandatory| Description                  |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| callback | AsyncCallback\<[CommonEventSubscribeInfo](#commoneventsubscribeinfo)> | Yes  | Callback used to return the subscriber information.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

// Callback for subscriber information obtaining.
function getSubscribeInfoCallback(err, SubscribeInfo) {
    if (err) {
        console.error("getSubscribeInfo failed " + JSON.stringify(err));
    } else {
        console.info("SubscribeInfo " + JSON.stringify(SubscribeInfo));
    }
}
subscriber.getSubscribeInfo(getSubscribeInfoCallback);
```

### getSubscribeInfo

getSubscribeInfo(): Promise\<CommonEventSubscribeInfo>

Obtains the subscriber information. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| Promise\<[CommonEventSubscribeInfo](#commoneventsubscribeinfo)> | Promise used to return the subscriber information.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.getSubscribeInfo().then((SubscribeInfo) => {
    console.info("SubscribeInfo " + JSON.stringify(SubscribeInfo));
}).catch((err) => {
    console.error("getSubscribeInfo failed " + JSON.stringify(err));
});
```

### finishCommonEvent<sup>9+</sup>

finishCommonEvent(callback: AsyncCallback\<void\>): void

Finishes this ordered common event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                 | Mandatory| Description                             |
| -------- | -------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback returned after the ordered common event is finished.|

**Example**

```ts
var subscriber; // Subscriber object successfully created.

// Callback for ordered common event finishing.
function finishCommonEventCallback(err) {
  if (err) {
    console.error("finishCommonEvent failed " + JSON.stringify(err));
} else {
    console.info("FinishCommonEvent");
}
}
subscriber.finishCommonEvent(finishCommonEventCallback);
```

### finishCommonEvent<sup>9+</sup>

finishCommonEvent(): Promise\<void\>

Finishes this ordered common event. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<void>   | Promise used to return the result.|

**Example**

```ts
var subscriber;	// Subscriber object successfully created.

subscriber.finishCommonEvent().then(() => {
    console.info("FinishCommonEvent");
}).catch((err) => {
    console.error("finishCommonEvent failed " + JSON.stringify(err));
});
```

## CommonEventData

**System capability**: SystemCapability.Notification.CommonEvent

| Name      | Type                | Readable| Writable| Description                                                   |
| ---------- |-------------------- | ---- | ---- |  ------------------------------------------------------- |
| event      | string               | Yes | No | Name of the common event that is being received.                             |
| bundleName | string               | Yes | No | Bundle name.                                             |
| code       | number               | Yes | No | Result code of the common event, which is used to transfer data of the int type.          |
| data       | string               | Yes | No | Custom result data of the common event, which is used to transfer data of the string type.|
| parameters | {[key: string]: any} | Yes | No | Additional information about the common event.                                 |


## CommonEventPublishData

**System capability**: SystemCapability.Notification.CommonEvent

| Name                 | Type                | Readable| Writable| Description                        |
| --------------------- | -------------------- | ---- | ---- | ---------------------------- |
| bundleName            | string               | Yes | No | Bundle name.                  |
| code                  | number               | Yes | No | Result code of the common event.      |
| data                  | string               | Yes | No | Custom result data of the common event.|
| subscriberPermissions | Array\<string>       | Yes | No | Permissions required for subscribers to receive the common event.            |
| isOrdered             | boolean              | Yes | No | Whether the common event is an ordered one.          |
| isSticky              | boolean              | Yes | No | Whether the common event is a sticky one. Only system applications and system services are allowed to send sticky events.|
| parameters            | {[key: string]: any} | Yes | No | Additional information about the common event.      |

## CommonEventSubscribeInfo

**System capability**: SystemCapability.Notification.CommonEvent

| Name               | Type          | Readable| Writable| Description                                                        |
| ------------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| events              | Array\<string> | Yes | No | Name of the common event to publish.                                        |
| publisherPermission | string         | Yes | No | Permissions required for publishers to publish the common event.                                            |
| publisherDeviceId   | string         | Yes | No | Device ID. The value must be the ID of an existing device on the same network.            |
| userId              | number         | Yes | No | User ID. The default value is the ID of the current user. If this parameter is specified, the value must be an existing user ID in the system.|
| priority            | number         | Yes | No | Subscriber priority. The value ranges from -100 to +1000.                    |
