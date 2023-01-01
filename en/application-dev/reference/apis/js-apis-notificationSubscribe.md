# @ohos.notificationSubscribe

The **NotificationSubscribe** module provides APIs for notification subscription, notification unsubscription, subscription removal, and more. In general cases, only system applications can call these APIs.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import NotificationSubscribe from '@ohos.notificationSubscribe';
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
| subscriber | [NotificationSubscriber](#notificationsubscriber)    | Yes  | Notification subscriber.    |
| info       | [NotificationSubscribeInfo](#notificationsubscribeinfo) | Yes  | Notification subscription information.|
| callback   | AsyncCallback\<void\>     | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```js
// subscribe callback
function subscribeCallback(err) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe success");
    }
}
function onConsumeCallback(data) {
	console.info("Consume callback: " + JSON.stringify(data));
}
var subscriber = {
    onConsume: onConsumeCallback
}
var info = {
    bundleNames: ["bundleName1","bundleName2"]
}
NotificationSubscribe.subscribe(subscriber, info, subscribeCallback);
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
| subscriber | [NotificationSubscriber](#notificationsubscriber) | Yes  | Notification subscriber.    |
| callback   | AsyncCallback\<void\>  | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```js
function subscribeCallback(err) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe success");
    }
}
function onConsumeCallback(data) {
	console.info("Consume callback: " + JSON.stringify(data));
}
var subscriber = {
    onConsume: onConsumeCallback
}
NotificationSubscribe.subscribe(subscriber, subscribeCallback);
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
| subscriber | [NotificationSubscriber](#notificationsubscriber)    | Yes  | Notification subscriber.|
| info       | [NotificationSubscribeInfo](#notificationsubscribeinfo) | No  | Notification subscription information.  |

**Error codes**

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```js
function onConsumeCallback(data) {
    console.info("Consume callback: " + JSON.stringify(data));
}
var subscriber = {
    onConsume: onConsumeCallback
};
NotificationSubscribe.subscribe(subscriber).then(() => {
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
| subscriber | [NotificationSubscriber](#notificationsubscriber) | Yes  | Notification subscriber.        |
| callback   | AsyncCallback\<void\>  | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```js
function unsubscribeCallback(err) {
    if (err) {
        console.info("unsubscribe failed " + JSON.stringify(err));
    } else {
        console.info("unsubscribe success");
    }
}
function onDisconnectCallback(data) {
	console.info("Cancel callback: " + JSON.stringify(data));
}
var subscriber = {
    onDisconnect: onDisconnectCallback
}
NotificationSubscribe.unsubscribe(subscriber, unsubscribeCallback);
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
| subscriber | [NotificationSubscriber](#notificationsubscriber) | Yes  | Notification subscriber.|

**Error codes**

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```js
function onDisconnectCallback(data) {
	console.info("Cancel callback: " + JSON.stringify(data));
}
var subscriber = {
    onDisconnect: onDisconnectCallback
};
NotificationSubscribe.unsubscribe(subscriber).then(() => {
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
| bundle          | [BundleOption](#bundleoption)       | Yes  | Bundle information of the application.          |
| notificationKey | [NotificationKey](#notificationkey) | Yes  | Notification key.            |
| reason          | [RemoveReason](#removereason)      | Yes  | Reason for removing the notification.        |
| callback        | AsyncCallback\<void\>               | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600007  | The notification is not exist.           |
| 17700001 | The specified bundle name was not found. |

**Example**

```js
function removeCallback(err) {
    if (err) {
        console.info("remove failed " + JSON.stringify(err));
    } else {
        console.info("remove success");
    }
}
var bundle = {
    bundle: "bundleName1",
}
var notificationKey = {
    id: 0,
    label: "label",
}
var reason = NotificationSubscribe.RemoveReason.CLICK_REASON_REMOVE;
NotificationSubscribe.remove(bundle, notificationKey, reason, removeCallback);
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
| bundle          | [BundleOption](#bundleoption)    | Yes  | Bundle information of the application.|
| notificationKey | [NotificationKey](#notificationkey) | Yes  | Notification key.  |
| reason          | [RemoveReason](#removereason) | Yes  | Reason for removing the notification.        |

**Error codes**

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600007  | The notification is not exist.           |
| 17700001 | The specified bundle name was not found. |

**Example**

```js
var bundle = {
    bundle: "bundleName1",
}
var notificationKey = {
    id: 0,
    label: "label",
}
var reason = NotificationSubscribe.RemoveReason.CLICK_REASON_REMOVE;
NotificationSubscribe.remove(bundle, notificationKey, reason).then(() => {
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
| hashCode | string                | Yes  | Unique notification ID. It is the **hashCode** in the [NotificationRequest](#notificationrequest) object of [SubscribeCallbackData](#subscribecallbackdata) of the [onConsume](#onconsume) callback.|
| reason   | [RemoveReason](#removereason) | Yes  | Reason for removing the notification.        |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**Example**

```js
var hashCode = 'hashCode'

function removeCallback(err) {
    if (err) {
        console.info("remove failed " + JSON.stringify(err));
    } else {
        console.info("remove success");
    }
}
var reason = NotificationSubscribe.RemoveReason.CANCEL_REASON_REMOVE;
NotificationSubscribe.remove(hashCode, reason, removeCallback);
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

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**Example**

```js
var hashCode = 'hashCode'
var reason = NotificationSubscribe.RemoveReason.CLICK_REASON_REMOVE;
NotificationSubscribe.remove(hashCode, reason).then(() => {
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
| bundle   | [BundleOption](#bundleoption)          | Yes  | Bundle information of the application.                  |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```js
function removeAllCallback(err) {
    if (err) {
        console.info("removeAll failed " + JSON.stringify(err));
    } else {
        console.info("removeAll success");
    }
}
var bundle = {
    bundle: "bundleName1",
}
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

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```js
function removeAllCallback(err) {
    if (err) {
        console.info("removeAll failed " + JSON.stringify(err));
    } else {
        console.info("removeAll success");
    }
}

NotificationSubscribe.removeAll(removeAllCallback);
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
| bundle | [BundleOption](#bundleoption) | No  | Bundle information of the application.|

**Error codes**

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```js
// If no application is specified, notifications of all applications are deleted.
NotificationSubscribe.removeAll().then(() => {
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

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**Example**

```js
function removeAllCallback(err) {
    if (err) {
        console.info("removeAll failed " + JSON.stringify(err));
    } else {
        console.info("removeAll success");
    }
}

var userId = 1

NotificationSubscribe.removeAll(userId, removeAllCallback);
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

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**Example**

```js
function removeAllCallback(err) {
    if (err) {
        console.info("removeAll failed " + JSON.stringify(err));
    } else {
        console.info("removeAll success");
    }
}

var userId = 1

NotificationSubscribe.removeAll(userId, removeAllCallback);
```



## NotificationSubscriber

Provides callbacks for receiving or removing notifications and serves as the input parameter of [subscribe](#notificationsubscribe).

**System API**: This is a system API and cannot be called by third-party applications.

### onConsume

onConsume?: (data: [SubscribeCallbackData](#subscribecallbackdata)) => void

Callback for receiving notifications.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [SubscribeCallbackData](#subscribecallbackdata) | Yes| Information about the notification received.|

**Example**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onConsumeCallback(data) {
    console.info('===> onConsume in test');
    let req = data.request;
    console.info('===> onConsume callback req.id:' + req.id);
};

var subscriber = {
    onConsume: onConsumeCallback
};

NotificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onCancel

onCancel?:(data: [SubscribeCallbackData](#subscribecallbackdata)) => void

Callback for canceling notifications.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [SubscribeCallbackData](#subscribecallbackdata) | Yes| Information about the notification to cancel.|

**Example**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onCancelCallback(data) {
    console.info('===> onCancel in test');
    let req = data.request;
    console.info('===> onCancel callback req.id:' + req.id);
}

var subscriber = {
    onCancel: onCancelCallback
};

NotificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onUpdate

onUpdate?:(data: [NotificationSortingMap](#notificationsortingmap)) => void

Callback for notification sorting updates.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [NotificationSortingMap](#notificationsortingmap) | Yes| Latest notification sorting list.|

**Example**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onUpdateCallback(map) {
    console.info('===> onUpdateCallback map:' + JSON.stringify(map));
}

var subscriber = {
    onUpdate: onUpdateCallback
};

NotificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onConnect

onConnect?:() => void

Callback for subscription.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Example**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onConnectCallback() {
    console.info('===> onConnect in test');
}

var subscriber = {
    onConnect: onConnectCallback
};

NotificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onDisconnect

onDisconnect?:() => void

Callback for unsubscription.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Example**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};
function unsubscribeCallback(err) {
    if (err.code) {
        console.info("unsubscribe failed " + JSON.stringify(err));
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

var subscriber = {
    onConnect: onConnectCallback,
    onDisconnect: onDisconnectCallback
};

// The onConnect callback is invoked when subscription to the notification is complete.
NotificationSubscribe.subscribe(subscriber, subscribeCallback);
// The onDisconnect callback is invoked when unsubscription to the notification is complete.
NotificationSubscribe.unsubscribe(subscriber, unsubscribeCallback);
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
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onDestroyCallback() {
    console.info('===> onDestroy in test');
}

var subscriber = {
    onDestroy: onDestroyCallback
};

NotificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onDoNotDisturbDateChange

onDoNotDisturbDateChange?:(mode: notification.[DoNotDisturbDate](js-apis-notificationManager.md#donotdisturbdate)) => void

Callback for DND time setting updates.

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
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onDoNotDisturbDateChangeCallback(mode) {
    console.info('===> onDoNotDisturbDateChange:' + mode);
}

var subscriber = {
    onDoNotDisturbDateChange: onDoNotDisturbDateChangeCallback
};

NotificationSubscribe.subscribe(subscriber, subscribeCallback);
```


### onEnabledNotificationChanged

onEnabledNotificationChanged?:(callbackData: [EnabledNotificationCallbackData](#enablednotificationcallbackdata)) => void

Listens for the notification enabled status changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<[EnabledNotificationCallbackData](#enablednotificationcallbackdata)\> | Yes| Callback used to return the result.|

**Example**

```javascript
function subscribeCallback(err) {
    if (err) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onEnabledNotificationChangedCallback(callbackData) {
    console.info("bundle: ", callbackData.bundle);
    console.info("uid: ", callbackData.uid);
    console.info("enable: ", callbackData.enable);
};

var subscriber = {
    onEnabledNotificationChanged: onEnabledNotificationChangedCallback
};

NotificationSubscribe.subscribe(subscriber, subscribeCallback);
```

## BundleOption

**System capability**: SystemCapability.Notification.Notification

| Name  | Type  | Readable| Writable| Description  |
| ------ | ------ |---- | --- |  ------ |
| bundle | string | Yes | Yes | Bundle information of the application.|
| uid    | number | Yes | Yes | User ID.|

## NotificationKey

**System capability**: SystemCapability.Notification.Notification

| Name | Type  | Readable| Writable| Description    |
| ----- | ------ | ---- | --- | -------- |
| id    | number | Yes | Yes | Notification ID.  |
| label | string | Yes | Yes | Notification label.|

## SubscribeCallbackData

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name           | Type                                             | Readable                                           | Writable                                           | Description    |
| --------------- | ------------------------------------------------- | -------- | -------- | -------- |
| request         | [NotificationRequest](js-apis-notificationManager.md#notificationrequest) | Yes| No| Notification content.|
| sortingMap      | [NotificationSortingMap](#notificationsortingmap) | Yes| No| Notification sorting information.|
| reason          | number                                            | Yes                                          | No                                          | Reason for deletion.|
| sound           | string                                            | Yes                                          | No                                          | Sound used for notification.|
| vibrationValues | Array\<number\>                                   | Yes                                 | No                                 | Vibration used for notification.|


## EnabledNotificationCallbackData

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name  | Type   | Readable | Writable | Description            |
| ------ | ------- | ---------------- | ---------------- | ---------------- |
| bundle | string  | Yes| No| Bundle name of the application.      |
| uid    | number  | Yes| No| UID of the application.       |
| enable | boolean | Yes| No| Notification enabled status of the application.|


## NotificationSorting

Provides sorting information of activity notifications.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name    | Type                                 | Readable| Writable| Description        |
| -------- | ------------------------------------- | ---- | --- | ------------ |
| slot     | [NotificationSlot](js-apis-notificationManager.md#notificationslot) | Yes | No | Notification slot.|
| hashCode | string                                | Yes | No | Unique ID of the notification.|
| ranking  | number                                | Yes | No | Notification sequence number.|


## NotificationSortingMap

Provides sorting information of active notifications in all subscribed notifications.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name          | Type                                                        | Readable| Writable| Description            |
| -------------- | ------------------------------------------------------------ | ---- | --- | ---------------- |
| sortings       | {[key: string]: [NotificationSorting](#notificationsorting)} | Yes | No | Array of notification sorting information.|
| sortedHashCode | Array\<string\>                                              | Yes | No | Array of unique notification IDs.|


## NotificationSubscribeInfo

Provides the information about the publisher for notification subscription.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name       | Type           | Readable| Writable| Description                           |
| ----------- | --------------- | --- | ---- | ------------------------------- |
| bundleNames | Array\<string\> | Yes | Yes | Bundle names of the applications whose notifications are to be subscribed to.|
| userId      | number          | Yes | Yes | User whose notifications are to be subscribed to.   |


## NotificationUserInput

Provides the notification user input.

**System capability**: SystemCapability.Notification.Notification

| Name    | Type  | Readable| Writable| Description                         |
| -------- | ------ | --- | ---- | ----------------------------- |
| inputKey | string | Yes | Yes | Key to identify the user input.|

## RemoveReason

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name                | Value | Description                 |
| -------------------- | --- | -------------------- |
| CLICK_REASON_REMOVE  | 1   | The notification is removed after a click on it.   |
| CANCEL_REASON_REMOVE | 2   | The notification is removed by the user.        |
