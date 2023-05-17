# @ohos.notificationSubscribe (NotificationSubscribe)

The **notificationSubscribe** module provides APIs for notification subscription, notification unsubscription, subscription removal, and more. In general cases, only system applications can call these APIs.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import notificationSubscribe from '@ohos.notificationSubscribe';
```



## NotificationSubscribe.subscribe

subscribe(subscriber: NotificationSubscriber, info: NotificationSubscribeInfo, callback: AsyncCallback\<void\>): void

Subscribes to a notification with the subscription information specified. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type                     | Mandatory| Description            |
| ---------- | ------------------------- | ---- | ---------------- |
| subscriber | [NotificationSubscriber](js-apis-notification.md#notificationsubscriber)    | Yes  | Notification subscriber.    |
| info       | [NotificationSubscribeInfo](js-apis-notification.md#notificationsubscribeinfo) | Yes  | Notification subscription information.|
| callback   | AsyncCallback\<void\>     | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201  | Permission denied.                      |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.             |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |

**Example**

```js
// subscribe callback
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribe success");
    }
}
function onConsumeCallback(data) {
	console.info("Consume callback: " + JSON.stringify(data));
}
let subscriber = {
    onConsume: onConsumeCallback
};
let info = {
    bundleNames: ["bundleName1","bundleName2"]
};
notificationSubscribe.subscribe(subscriber, info, subscribeCallback);
```

## NotificationSubscribe.subscribe

subscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>): void

Subscribes to notifications of all applications under this user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type                  | Mandatory| Description            |
| ---------- | ---------------------- | ---- | ---------------- |
| subscriber | [NotificationSubscriber](js-apis-notification.md#notificationsubscriber) | Yes  | Notification subscriber.    |
| callback   | AsyncCallback\<void\>  | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201  | Permission denied.                      |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.             |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |

**Example**

```js
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribe success");
    }
}
function onConsumeCallback(data) {
	console.info("Consume callback: " + JSON.stringify(data));
}
let subscriber = {
    onConsume: onConsumeCallback
};
notificationSubscribe.subscribe(subscriber, subscribeCallback);
```



## NotificationSubscribe.subscribe

subscribe(subscriber: NotificationSubscriber, info?: NotificationSubscribeInfo): Promise\<void\>

Subscribes to a notification with the subscription information specified. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type                     | Mandatory| Description        |
| ---------- | ------------------------- | ---- | ------------ |
| subscriber | [NotificationSubscriber](js-apis-notification.md#notificationsubscriber)    | Yes  | Notification subscriber.|
| info       | [NotificationSubscribeInfo](js-apis-notification.md#notificationsubscribeinfo) | No  | Notification subscription information.  |

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201  | Permission denied.                      |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.             |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |

**Example**

```js
function onConsumeCallback(data) {
    console.info("Consume callback: " + JSON.stringify(data));
}
let subscriber = {
    onConsume: onConsumeCallback
};
notificationSubscribe.subscribe(subscriber).then(() => {
	console.info("subscribe success");
});
```



## NotificationSubscribe.unsubscribe

unsubscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>): void

Unsubscribes from a notification. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type                  | Mandatory| Description                |
| ---------- | ---------------------- | ---- | -------------------- |
| subscriber | [NotificationSubscriber](js-apis-notification.md#notificationsubscriber) | Yes  | Notification subscriber.        |
| callback   | AsyncCallback\<void\>  | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201  | Permission denied.                      |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.             |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```js
function unsubscribeCallback(err) {
    if (err) {
        console.error(`unsubscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("unsubscribe success");
    }
}
function onDisconnectCallback() {
	console.info("subscribe disconnect");
}
let subscriber = {
    onDisconnect: onDisconnectCallback
};
notificationSubscribe.unsubscribe(subscriber, unsubscribeCallback);
```

## NotificationSubscribe.unsubscribe

unsubscribe(subscriber: NotificationSubscriber): Promise\<void\>

Unsubscribes from a notification. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type                  | Mandatory| Description        |
| ---------- | ---------------------- | ---- | ------------ |
| subscriber | [NotificationSubscriber](js-apis-notification.md#notificationsubscriber) | Yes  | Notification subscriber.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201  | Permission denied.                      |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.             |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```js
function onDisconnectCallback() {
	console.info("subscribe disconnect");
}
let subscriber = {
    onDisconnect: onDisconnectCallback
};
notificationSubscribe.unsubscribe(subscriber).then(() => {
	console.info("unsubscribe success");
});
```

## NotificationSubscribe.remove

remove(bundle: BundleOption, notificationKey: NotificationKey, reason: RemoveReason, callback: AsyncCallback\<void\>): void

Removes a notification for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name           | Type                               | Mandatory| Description                |
| --------------- |   ----------------------------------| ---- | -------------------- |
| bundle          | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption)       | Yes  | Bundle information of the application.          |
| notificationKey | [NotificationKey](js-apis-notification.md#notificationkey) | Yes  | Notification key.            |
| reason          | [RemoveReason](#removereason)      | Yes  | Reason for removing the notification.        |
| callback        | AsyncCallback\<void\>               | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600007  | The notification is not exist.           |
| 17700001 | The specified bundle name was not found. |

**Example**

```js
function removeCallback(err) {
    if (err) {
        console.error(`remove failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("remove success");
    }
}
let bundle = {
    bundle: "bundleName1",
};
let notificationKey = {
    id: 0,
    label: "label",
};
let reason = notificationSubscribe.RemoveReason.CLICK_REASON_REMOVE;
notificationSubscribe.remove(bundle, notificationKey, reason, removeCallback);
```



## NotificationSubscribe.remove

remove(bundle: BundleOption, notificationKey: NotificationKey, reason: RemoveReason): Promise\<void\>

Removes a notification for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name           | Type           | Mandatory| Description      |
| --------------- | --------------- | ---- | ---------- |
| bundle          | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption)    | Yes  | Bundle information of the application.|
| notificationKey | [NotificationKey]((js-apis-notification.md#notificationkey)) | Yes  | Notification key.  |
| reason          | [RemoveReason](#removereason) | Yes  | Reason for removing the notification.        |

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600007  | The notification is not exist.           |
| 17700001 | The specified bundle name was not found. |

**Example**

```js
let bundle = {
    bundle: "bundleName1",
};
let notificationKey = {
    id: 0,
    label: "label",
};
let reason = NotificationSubscribe.RemoveReason.CLICK_REASON_REMOVE;
notificationSubscribe.remove(bundle, notificationKey, reason).then(() => {
	console.info("remove success");
});
```

## NotificationSubscribe.remove

remove(hashCode: string, reason: RemoveReason, callback: AsyncCallback\<void\>): void

Removes a specified notification. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| hashCode | string                | Yes  | Unique notification ID. It is the value of **hashCode** in the [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) object of [SubscribeCallbackData](js-apis-notification.md#subscribecallbackdata) in the [onConsume](#onconsume) callback.|
| reason   | [RemoveReason](#removereason) | Yes  | Reason for removing the notification.        |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**Example**

```js
let hashCode = 'hashCode';

function removeCallback(err) {
    if (err) {
        console.error(`remove failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("remove success");
    }
}
let reason = NotificationSubscribe.RemoveReason.CANCEL_REASON_REMOVE;
notificationSubscribe.remove(hashCode, reason, removeCallback);
```

## NotificationSubscribe.remove

remove(hashCode: string, reason: RemoveReason): Promise\<void\>

Removes a specified notification. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type      | Mandatory| Description      |
| -------- | ---------- | ---- | ---------- |
| hashCode | string | Yes  | Unique notification ID.|
| reason   | [RemoveReason](#removereason) | Yes  | Reason for removing the notification.        |

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**Example**

```js
let hashCode = 'hashCode';
let reason = notificationSubscribe.RemoveReason.CLICK_REASON_REMOVE;
notificationSubscribe.remove(hashCode, reason).then(() => {
	console.info("remove success");
});
```

## NotificationSubscribe.removeAll

removeAll(bundle: BundleOption, callback: AsyncCallback\<void\>): void

Removes all notifications for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name    | Type                 | Mandatory| Description                        |
| -------- | --------------------- | ---- | ---------------------------- |
| bundle   | [BundleOption]((js-apis-inner-notification-notificationCommonDef.md#bundleoption))          | Yes  | Bundle information of the application.                  |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```js
function removeAllCallback(err) {
    if (err) {
        console.error(`removeAll failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeAll success");
    }
}
let bundle = {
    bundle: "bundleName1",
};
NotificationSubscribe.removeAll(bundle, removeAllCallback);
```

## NotificationSubscribe.removeAll

removeAll(callback: AsyncCallback\<void\>): void

Removes all notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```js
function removeAllCallback(err) {
    if (err) {
        console.error(`removeAll failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeAll success");
    }
}

notificationSubscribe.removeAll(removeAllCallback);
```

## NotificationSubscribe.removeAll

removeAll(bundle?: BundleOption): Promise\<void\>

Removes all notifications for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption]((js-apis-inner-notification-notificationCommonDef.md#bundleoption)) | No  | Bundle information of the application.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```js
// If no application is specified, notifications of all applications are deleted.
notificationSubscribe.removeAll().then(() => {
	console.info("removeAll success");
});
```

## NotificationSubscribe.removeAll

removeAll(userId: number, callback: AsyncCallback\<void>): void

Removes all notifications for a specified user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| userId | number | Yes  | User ID.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**Example**

```js
function removeAllCallback(err) {
    if (err) {
        console.error(`removeAll failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeAll success");
    }
}

let userId = 1;

notificationSubscribe.removeAll(userId, removeAllCallback);
```

## Notification.removeAll

removeAll(userId: number): Promise\<void>

Removes all notifications for a specified user. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| userId | number | Yes  | User ID.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201  | Permission denied.                           |
| 202  | Not system application to call the interface. |
| 401  | The parameter check failed.                  |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**Example**

```js
function removeAllCallback(err) {
    if (err) {
        console.error(`removeAll failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeAll success");
    }
}

let userId = 1;

notificationSubscribe.removeAll(userId, removeAllCallback);
```

## NotificationSubscriber

Provides callbacks for receiving or removing notifications and serves as the input parameter of [subscribe](#notificationsubscribesubscribe).

**System API**: This is a system API and cannot be called by third-party applications.

### onConsume

onConsume?: (data: [SubscribeCallbackData](js-apis-notification.md#subscribecallbackdata)) => void

Called when a notification is received.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [SubscribeCallbackData](js-apis-notification.md#subscribecallbackdata) | Yes| Information about the notification received.|

**Example**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};

function onConsumeCallback(data) {
    console.info('===> onConsume in test');
    let req = data.request;
    console.info('===> onConsume callback req.id:' + req.id);
};

let subscriber = {
    onConsume: onConsumeCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onCancel

onCancel?:(data: [SubscribeCallbackData](js-apis-notification.md#subscribecallbackdata)) => void

Called when a notification is canceled.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [SubscribeCallbackData](js-apis-notification.md#subscribecallbackdata) | Yes| Information about the notification to cancel.|

**Example**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};

function onCancelCallback(data) {
    console.info('===> onCancel in test');
    let req = data.request;
    console.info('===> onCancel callback req.id:' + req.id);
}

let subscriber = {
    onCancel: onCancelCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onUpdate

onUpdate?:(data: [NotificationSortingMap](js-apis-notification.md#notificationsortingmap)) => void

Called when the notification sorting list is updated.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [NotificationSortingMap](js-apis-notification.md#notificationsortingmap)) | Yes| Latest notification sorting list.|

**Example**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};

function onUpdateCallback(map) {
    console.info('===> onUpdateCallback map:' + JSON.stringify(map));
}

let subscriber = {
    onUpdate: onUpdateCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onConnect

onConnect?:() => void

Called when subscription is complete.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Example**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};

function onConnectCallback() {
    console.info('===> onConnect in test');
}

let subscriber = {
    onConnect: onConnectCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onDisconnect

onDisconnect?:() => void

Called when unsubscription is complete.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Example**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};
function unsubscribeCallback(err) {
    if (err.code) {
        console.error(`unsubscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("unsubscribeCallback");
    }
};

function onConnectCallback() {
    console.info('===> onConnect in test');
}
function onDisconnectCallback() {
    console.info('===> onDisconnect in test');
}

let subscriber = {
    onConnect: onConnectCallback,
    onDisconnect: onDisconnectCallback
};

// The onConnect callback is invoked when subscription to the notification is complete.
notificationSubscribe.subscribe(subscriber, subscribeCallback);
// The onDisconnect callback is invoked when unsubscription to the notification is complete.
notificationSubscribe.unsubscribe(subscriber, unsubscribeCallback);
```

### onDestroy

onDestroy?:() => void

Callback for service disconnection.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Example**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};

function onDestroyCallback() {
    console.info('===> onDestroy in test');
}

let subscriber = {
    onDestroy: onDestroyCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onDoNotDisturbDateChange

onDoNotDisturbDateChange?:(mode: notification.[DoNotDisturbDate](js-apis-notificationManager.md#donotdisturbdate)) => void

Called when the DND time setting is updated.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| mode | notification.[DoNotDisturbDate](js-apis-notificationManager.md#DoNotDisturbDate) | Yes| DND time setting updates.|

**Example**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};

function onDoNotDisturbDateChangeCallback(mode) {
    console.info('===> onDoNotDisturbDateChange:' + mode);
}

let subscriber = {
    onDoNotDisturbDateChange: onDoNotDisturbDateChangeCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```


### onEnabledNotificationChanged

onEnabledNotificationChanged?:(callbackData: [EnabledNotificationCallbackData](js-apis-notification.md#enablednotificationcallbackdata8)) => void

Listens for the notification enabled status changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<[EnabledNotificationCallbackData](js-apis-notification.md#enablednotificationcallbackdata8)\> | Yes| Callback used to return the result.|

**Example**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};

function onEnabledNotificationChangedCallback(callbackData) {
    console.info("bundle: ", callbackData.bundle);
    console.info("uid: ", callbackData.uid);
    console.info("enable: ", callbackData.enable);
};

let subscriber = {
    onEnabledNotificationChanged: onEnabledNotificationChangedCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onBadgeChanged<sup>10+</sup>

 onBadgeChanged?:(data: [BadgeNumberCallbackData](#badgenumbercallbackdata10)) => void

Listens for the change of the notification badge number.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                      |
| -------- | ------------------------------------------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<[BadgeNumberCallbackData](#badgenumbercallbackdata10)\> | Yes  | Callback used to return the result.|

**Example**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("subscribeCallback");
    }
};

function onBadgeChangedCallback(data) {
    console.info("bundle: ", data.bundle);
    console.info("uid: ", data.uid);
    console.info("badgeNumber: ", data.badgeNumber);
};

let subscriber = {
    onBadgeChanged: onBadgeChangedCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```


## RemoveReason

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name                | Value | Description                 |
| -------------------- | --- | -------------------- |
| CLICK_REASON_REMOVE  | 1   | The notification is removed after a click on it.   |
| CANCEL_REASON_REMOVE | 2   | The notification is removed by the user.        |

## BadgeNumberCallbackData<sup>10+</sup>

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name       | Type  | Readable| Writable| Description        |
| ----------- | ------ | ---- | ---- | ------------ |
| bundle      | string | Yes  | No  | Bundle name of the application.|
| uid         | number | Yes  | No  | UID of the application. |
| badgeNumber | number | Yes  | No  | Notification badge number.  |
