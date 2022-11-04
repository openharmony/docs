# Notification

The **Notification** module provides notification management capabilities, covering notifications, notification slots, notification subscription, notification enabled status, and notification badge status.

Generally, only system applications have the permission to subscribe to and unsubscribe from notifications.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import Notification from '@ohos.notification';
```

## Notification.publish

publish(request: NotificationRequest, callback: AsyncCallback\<void\>): void

Publishes a notification. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                                       | Mandatory| Description                                       |
| -------- | ------------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](#notificationrequest) | Yes  | **NotificationRequest** object.|
| callback | AsyncCallback\<void\>                       | Yes  | Callback used to return the result.                           |

**Example**

```js
// publish callback
function publishCallback(err) {
    if (err.code) {
        console.info("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish success");
    }
}
// NotificationRequest object
var notificationRequest = {
    id: 1,
    content: {
        contentType: Notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
}
Notification.publish(notificationRequest, publishCallback)
```



## Notification.publish

publish(request: NotificationRequest): Promise\<void\>

Publishes a notification. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                                       | Mandatory| Description                                       |
| -------- | ------------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](#notificationrequest) | Yes  | **NotificationRequest** object.|

**Example**

```js
// NotificationRequest object
var notificationRequest = {
    notificationId: 1,
    content: {
        contentType: Notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
}
Notification.publish(notificationRequest).then(() => {
	console.info("publish sucess");
});

```

## Notification.publish<sup>8+</sup>

publish(request: NotificationRequest, userId: number, callback: AsyncCallback\<void\>): void

Publishes a notification. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                                       | Mandatory| Description                                       |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](#notificationrequest) | Yes  | **NotificationRequest** object.|
| userId   | number                                      | Yes  | ID of the user who receives the notification.                          |
| callback | AsyncCallback\<void\>                       | Yes  | Callback used to return the result.                          |

**Example**

```js
// publish callback
function publishCallback(err) {
    if (err.code) {
        console.info("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish success");
    }
}
// ID of the user who receives the notification
var userId = 1
// NotificationRequest object
var notificationRequest = {
    id: 1,
    content: {
        contentType: Notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
}
Notification.publish(notificationRequest, userId, publishCallback);
```

## Notification.publish<sup>8+</sup>

publish(request: NotificationRequest, userId: number): Promise\<void\>

Publishes a notification. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    |  Type                                       | Mandatory| Description                                       |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](#notificationrequest) | Yes  | **NotificationRequest** object.|
| userId   | number                                      | Yes  | ID of the user who receives the notification.                          |

**Example**

```js
var notificationRequest = {
    notificationId: 1,
    content: {
        contentType: Notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
}

var userId = 1

Notification.publish(notificationRequest, userId).then(() => {
	console.info("publish sucess");
});
```


## Notification.cancel

cancel(id: number, label: string, callback: AsyncCallback\<void\>): void

Cancels a notification with the specified ID and label. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| id       | number                | Yes  | Notification ID.              |
| label    | string                | Yes  | Notification label.            |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
// cancel callback
function cancelCallback(err) {
    if (err.code) {
        console.info("cancel failed " + JSON.stringify(err));
    } else {
        console.info("cancel success");
    }
}
Notification.cancel(0, "label", cancelCallback)
```



## Notification.cancel

cancel(id: number, label?: string): Promise\<void\>

Cancels a notification with the specified ID and label. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name | Type  | Mandatory| Description    |
| ----- | ------ | ---- | -------- |
| id    | number | Yes  | Notification ID.  |
| label | string | No  | Notification label.|

**Example**

```js
Notification.cancel(0).then(() => {
	console.info("cancel sucess");
});
```



## Notification.cancel

cancel(id: number, callback: AsyncCallback\<void\>): void

Cancels a notification with the specified ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| id       | number                | Yes  | Notification ID.              |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
// cancel callback
function cancelCallback(err) {
    if (err.code) {
        console.info("cancel failed " + JSON.stringify(err));
    } else {
        console.info("cancel success");
    }
}
Notification.cancel(0, cancelCallback)
```



## Notification.cancelAll

cancelAll(callback: AsyncCallback\<void\>): void

Cancels all notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
// cancel callback
function cancelAllCallback(err) {
    if (err.code) {
        console.info("cancelAll failed " + JSON.stringify(err));
    } else {
        console.info("cancelAll success");
    }
}
Notification.cancelAll(cancelAllCallback)
```



## Notification.cancelAll

cancelAll(): Promise\<void\>

Cancels all notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Example**

```js
Notification.cancelAll().then(() => {
	console.info("cancelAll sucess");
});
```



## Notification.addSlot

addSlot(slot: NotificationSlot, callback: AsyncCallback\<void\>): void

Adds a notification slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| slot     | [NotificationSlot](#notificationslot)       | Yes  | Notification slot to add.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
// addSlot callback
function addSlotCallBack(err) {
    if (err.code) {
        console.info("addSlot failed " + JSON.stringify(err));
    } else {
        console.info("addSlot success");
    }
}
// NotificationSlot object
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
Notification.addSlot(notificationSlot, addSlotCallBack)
```



## Notification.addSlot

addSlot(slot: NotificationSlot): Promise\<void\>

Adds a notification slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type            | Mandatory| Description                |
| ---- | ---------------- | ---- | -------------------- |
| slot | [NotificationSlot](#notificationslot) | Yes  | Notification slot to add.|

**Example**

```js
// NotificationSlot object
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
Notification.addSlot(notificationSlot).then(() => {
	console.info("addSlot sucess");
});
```



## Notification.addSlot

addSlot(type: SlotType, callback: AsyncCallback\<void\>): void

Adds a notification slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                 | Mandatory| Description                  |
| -------- | --------------------- | ---- | ---------------------- |
| type     | [SlotType](#slottype)              | Yes  | Type of the notification slot to add.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.  |

**Example**

```js
// addSlot callback
function addSlotCallBack(err) {
    if (err.code) {
        console.info("addSlot failed " + JSON.stringify(err));
    } else {
        console.info("addSlot success");
    }
}
Notification.addSlot(Notification.SlotType.SOCIAL_COMMUNICATION, addSlotCallBack)
```



## Notification.addSlot

addSlot(type: SlotType): Promise\<void\>

Adds a notification slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name| Type    | Mandatory| Description                  |
| ---- | -------- | ---- | ---------------------- |
| type | [SlotType](#slottype) | Yes  | Type of the notification slot to add.|

**Example**

```js
Notification.addSlot(Notification.SlotType.SOCIAL_COMMUNICATION).then(() => {
	console.info("addSlot sucess");
});
```



## Notification.addSlots

addSlots(slots: Array\<NotificationSlot\>, callback: AsyncCallback\<void\>): void

Adds multiple notification slots. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                     | Mandatory| Description                    |
| -------- | ------------------------- | ---- | ------------------------ |
| slots    | Array\<[NotificationSlot](#notificationslot)\> | Yes  | Notification slots to add.|
| callback | AsyncCallback\<void\>     | Yes  | Callback used to return the result.    |

**Example**

```js
// addSlots callback
function addSlotsCallBack(err) {
    if (err.code) {
        console.info("addSlots failed " + JSON.stringify(err));
    } else {
        console.info("addSlots success");
    }
}
// NotificationSlot object
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
// NotificationSlotArray object
var notificationSlotArray = new Array();
notificationSlotArray[0] = notificationSlot;

Notification.addSlots(notificationSlotArray, addSlotsCallBack)
```



## Notification.addSlots

addSlots(slots: Array\<NotificationSlot\>): Promise\<void\>

Adds multiple notification slots. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name | Type                     | Mandatory| Description                    |
| ----- | ------------------------- | ---- | ------------------------ |
| slots | Array\<[NotificationSlot](#notificationslot)\> | Yes  | Notification slots to add.|

**Example**

```js
// NotificationSlot object
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
// NotificationSlotArray object
var notificationSlotArray = new Array();
notificationSlotArray[0] = notificationSlot;

Notification.addSlots(notificationSlotArray).then(() => {
	console.info("addSlots sucess");
});
```



## Notification.getSlot

getSlot(slotType: SlotType, callback: AsyncCallback\<NotificationSlot\>): void

Obtains a notification slot of the specified type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                             | Mandatory| Description                                                       |
| -------- | --------------------------------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype)                          | Yes  | Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|
| callback | AsyncCallback\<[NotificationSlot](#notificationslot)\> | Yes  | Callback used to return the result.                                       |

**Example**

```js
// getSlot callback
function getSlotCallback(err,data) {
    if (err.code) {
        console.info("getSlot failed " + JSON.stringify(err));
    } else {
        console.info("getSlot success");
    }
}
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.getSlot(slotType, getSlotCallback)
```



## Notification.getSlot

getSlot(slotType: SlotType): Promise\<NotificationSlot\>

Obtains a notification slot of the specified type. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type    | Mandatory| Description                                                       |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype) | Yes  | Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<NotificationSlot\> | Promise used to return the result.|

**Example**

```js
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.getSlot(slotType).then((data) => {
	console.info("getSlot sucess, data: " + JSON.stringify(data));
});
```



## Notification.getSlots

getSlots(callback: AsyncCallback<Array\<NotificationSlot\>>): void

Obtains all notification slots. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                             | Mandatory| Description                |
| -------- | --------------------------------- | ---- | -------------------- |
| callback | AsyncCallback\<Array\<[NotificationSlot](#notificationslot)\>\> | Yes  | Callback used to return the result.|

**Example**

```js
// getSlots callback
function getSlotsCallback(err,data) {
    if (err.code) {
        console.info("getSlots failed " + JSON.stringify(err));
    } else {
        console.info("getSlots success");
    }
}
Notification.getSlots(getSlotsCallback)
```



## Notification.getSlots

getSlots(): Promise\<Array\<NotificationSlot\>>

Obtains all notification slots of this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationSlot](#notificationslot)\>\> | Promise used to return the result.|

**Example**

```js
Notification.getSlots().then((data) => {
	console.info("getSlots sucess, data: " + JSON.stringify(data));
});
```



## Notification.removeSlot

removeSlot(slotType: SlotType, callback: AsyncCallback\<void\>): void

Removes a notification slot of the specified type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                 | Mandatory| Description                                                       |
| -------- | --------------------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype)              | Yes  | Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.                                       |

**Example**

```js
// removeSlot callback
function removeSlotCallback(err) {
    if (err.code) {
        console.info("removeSlot failed " + JSON.stringify(err));
    } else {
        console.info("removeSlot success");
    }
}
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.removeSlot(slotType,removeSlotCallback)
```



## Notification.removeSlot

removeSlot(slotType: SlotType): Promise\<void\>

Removes a notification slot of the specified type. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type    | Mandatory| Description                                                       |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype) | Yes  | Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|

**Example**

```js
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.removeSlot(slotType).then(() => {
	console.info("removeSlot sucess");
});
```



## Notification.removeAllSlots

removeAllSlots(callback: AsyncCallback\<void\>): void

Removes all notification slots. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function removeAllCallBack(err) {
    if (err.code) {
        console.info("removeAllSlots failed " + JSON.stringify(err));
    } else {
        console.info("removeAllSlots success");
    }
}
Notification.removeAllSlots(removeAllCallBack)
```



## Notification.removeAllSlots

removeAllSlots(): Promise\<void\>

Removes all notification slots. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Example**

```js
Notification.removeAllSlots().then(() => {
	console.info("removeAllSlots sucess");
});
```



## Notification.subscribe

subscribe(subscriber: NotificationSubscriber, info: NotificationSubscribeInfo, callback: AsyncCallback\<void\>): void

Subscribes to a notification with the subscription information specified. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type                     | Mandatory| Description            |
| ---------- | ------------------------- | ---- | ---------------- |
| subscriber | [NotificationSubscriber](#notificationsubscriber)    | Yes  | Notification subscriber.    |
| info       | [NotificationSubscribeInfo](#notificationsubscribeinfo) | Yes  | Subscription information.        |
| callback   | AsyncCallback\<void\>     | Yes  | Callback used to return the result.|

**Example**

```js
// subscribe callback
function subscribeCallback(err) {
    if (err.code) {
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
Notification.subscribe(subscriber, info, subscribeCallback);
```



## Notification.subscribe

subscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>): void

Subscribes to a notification with the subscription information specified. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type                  | Mandatory| Description            |
| ---------- | ---------------------- | ---- | ---------------- |
| subscriber | [NotificationSubscriber](#notificationsubscriber) | Yes  | Notification subscriber.    |
| callback   | AsyncCallback\<void\>  | Yes  | Callback used to return the result.|

**Example**

```js
function subscribeCallback(err) {
    if (err.code) {
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
Notification.subscribe(subscriber, subscribeCallback);
```



## Notification.subscribe

subscribe(subscriber: NotificationSubscriber, info?: NotificationSubscribeInfo): Promise\<void\>

Subscribes to a notification with the subscription information specified. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type                     | Mandatory| Description        |
| ---------- | ------------------------- | ---- | ------------ |
| subscriber | [NotificationSubscriber](#notificationsubscriber)    | Yes  | Notification subscriber.|
| info       | [NotificationSubscribeInfo](#notificationsubscribeinfo) | No  | Subscription information.    |

**Example**

```js
function onConsumeCallback(data) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe success");
    }
}
var subscriber = {
    onConsume: onConsumeCallback
};
Notification.subscribe(subscriber).then(() => {
	console.info("subscribe sucess");
});
```



## Notification.unsubscribe

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

**Example**

```js
function unsubscribeCallback(err) {
    if (err.code) {
        console.info("unsubscribe failed " + JSON.stringify(err));
    } else {
        console.info("unsubscribe success");
    }
}
function onCancelCallback(data) {
	console.info("Cancel callback: " + JSON.stringify(data));
}
var subscriber = {
    onCancel: onCancelCallback
}
Notification.unsubscribe(subscriber, unsubscribeCallback);
```



## Notification.unsubscribe

unsubscribe(subscriber: NotificationSubscriber): Promise\<void\>

Unsubscribes from a notification. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type                  | Mandatory| Description        |
| ---------- | ---------------------- | ---- | ------------ |
| subscriber | [NotificationSubscriber](#notificationsubscriber) | Yes  | Notification subscriber.|

**Example**

```js
function onCancelCallback(data) {
	console.info("Cancel callback: " + JSON.stringify(data));
}
var subscriber = {
    onCancel: onCancelCallback
};
Notification.unsubscribe(subscriber).then(() => {
	console.info("unsubscribe sucess");
});
```



## Notification.enableNotification

enableNotification(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether to enable notification for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](#bundleoption)          | Yes  | Bundle information.          |
| enable   | boolean               | Yes  | Whether to enable notification.            |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function enableNotificationCallback(err) {
    if (err.code) {
        console.info("enableNotification failed " + JSON.stringify(err));
    } else {
        console.info("enableNotification success");
    }
}
var bundle = {
    bundle: "bundleName1",
}
Notification.enableNotification(bundle, false, enableNotificationCallback);
```



## Notification.enableNotification

enableNotification(bundle: BundleOption, enable: boolean): Promise\<void\>

Sets whether to enable notification for a specified bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle information.|
| enable | boolean      | Yes  | Whether to enable notification.  |

**Example**

```js
var bundle = {
    bundle: "bundleName1",
}
Notification.enableNotification(bundle, false).then(() => {
	console.info("enableNotification sucess");
});
```



## Notification.isNotificationEnabled

isNotificationEnabled(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

Checks whether notification is enabled for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name    | Type                 | Mandatory| Description                    |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](#bundleoption)          | Yes  | Bundle information.              |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function isNotificationEnabledCallback(err, data) {
    if (err.code) {
        console.info("isNotificationEnabled failed " + JSON.stringify(err));
    } else {
        console.info("isNotificationEnabled success");
    }
}
var bundle = {
    bundle: "bundleName1",
}
Notification.isNotificationEnabled(bundle, isNotificationEnabledCallback);
```



## Notification.isNotificationEnabled

isNotificationEnabled(bundle: BundleOption): Promise\<boolean\>

Checks whether notification is enabled for a specified bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle information.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

```js
var bundle = {
    bundle: "bundleName1",
}
Notification.isNotificationEnabled(bundle).then((data) => {
	console.info("isNotificationEnabled sucess, data: " + JSON.stringify(data));
});
```



## Notification.isNotificationEnabled

isNotificationEnabled(callback: AsyncCallback\<boolean\>): void

Checks whether notification is enabled for this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                    |
| -------- | --------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function isNotificationEnabledCallback(err, data) {
    if (err.code) {
        console.info("isNotificationEnabled failed " + JSON.stringify(err));
    } else {
        console.info("isNotificationEnabled success");
    }
}

Notification.isNotificationEnabled(isNotificationEnabledCallback);
```



## Notification.isNotificationEnabled

isNotificationEnabled(): Promise\<boolean\>

Checks whether notification is enabled for this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle information.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

```js
Notification.isNotificationEnabled().then((data) => {
	console.info("isNotificationEnabled sucess, data: " + JSON.stringify(data));
});
```



## Notification.displayBadge

displayBadge(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether to enable the notification badge for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](#bundleoption)          | Yes  | Bundle information.          |
| enable   | boolean               | Yes  | Whether to enable notification.            |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function displayBadgeCallback(err) {
    if (err.code) {
        console.info("displayBadge failed " + JSON.stringify(err));
    } else {
        console.info("displayBadge success");
    }
}
var bundle = {
    bundle: "bundleName1",
}
Notification.displayBadge(bundle, false, displayBadgeCallback);
```



## Notification.displayBadge

displayBadge(bundle: BundleOption, enable: boolean): Promise\<void\>

Sets the notification slot for a specified bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle information.|
| enable | boolean      | Yes  | Whether to enable notification.  |

**Example**

```js
var bundle = {
    bundle: "bundleName1",
}
Notification.displayBadge(bundle, false).then(() => {
	console.info("displayBadge sucess");
});
```



## Notification.isBadgeDisplayed

isBadgeDisplayed(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

Checks whether the notification badge is enabled for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                    |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](#bundleoption)          | Yes  | Bundle information.              |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function isBadgeDisplayedCallback(err, data) {
    if (err.code) {
        console.info("isBadgeDisplayed failed " + JSON.stringify(err));
    } else {
        console.info("isBadgeDisplayed success");
    }
}
var bundle = {
    bundle: "bundleName1",
}
Notification.isBadgeDisplayed(bundle, isBadgeDisplayedCallback);
```



## Notification.isBadgeDisplayed

isBadgeDisplayed(bundle: BundleOption): Promise\<boolean\>

Checks whether the notification badge is enabled for a specified bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle information.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

```js
var bundle = {
    bundle: "bundleName1",
}
Notification.isBadgeDisplayed(bundle).then((data) => {
	console.info("isBadgeDisplayed sucess, data: " + JSON.stringify(data));
});
```



## Notification.setSlotByBundle

setSlotByBundle(bundle: BundleOption, slot: NotificationSlot, callback: AsyncCallback\<void\>): void

Sets the notification slot for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](#bundleoption)          | Yes  | Bundle information.          |
| slot     | [NotificationSlot](#notificationslot)      | Yes  | Notification slot.            |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function setSlotByBundleCallback(err) {
    if (err.code) {
        console.info("setSlotByBundle failed " + JSON.stringify(err));
    } else {
        console.info("setSlotByBundle success");
    }
}
var bundle = {
    bundle: "bundleName1",
}
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
Notification.setSlotByBundle(bundle, notificationSlot, setSlotByBundleCallback);
```



## Notification.setSlotByBundle

setSlotByBundle(bundle: BundleOption, slot: NotificationSlot): Promise\<void\>

Sets the notification slot for a specified bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle information.|
| slot   | [NotificationSlot](#notificationslot) | Yes  | Whether to enable notification.  |

**Example**

```js
var bundle = {
    bundle: "bundleName1",
}
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
Notification.setSlotByBundle(bundle, notificationSlot).then(() => {
	console.info("setSlotByBundle sucess");
});
```



## Notification.getSlotsByBundle

getSlotsByBundle(bundle: BundleOption, callback: AsyncCallback<Array\<NotificationSlot\>>): void

Obtains the notification slots of a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                                    | Mandatory| Description                |
| -------- | ---------------------------------------- | ---- | -------------------- |
| bundle   | [BundleOption](#bundleoption)                             | Yes  | Bundle information.          |
| callback | AsyncCallback<Array\<[NotificationSlot](#notificationslot)\>> | Yes  | Callback used to return the result.|

**Example**

```js
function getSlotsByBundleCallback(err, data) {
    if (err.code) {
        console.info("getSlotsByBundle failed " + JSON.stringify(err));
    } else {
        console.info("getSlotsByBundle success");
    }
}
var bundle = {
    bundle: "bundleName1",
}
Notification.getSlotsByBundle(bundle, getSlotsByBundleCallback);
```



## Notification.getSlotsByBundle

getSlotsByBundle(bundle: BundleOption): Promise<Array\<NotificationSlot\>>

Obtains the notification slots of a specified bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle information.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise<Array\<[NotificationSlot](#notificationslot)\>> | Promise used to return the result.|

**Example**

```js
var bundle = {
    bundle: "bundleName1",
}
Notification.getSlotsByBundle(bundle).then((data) => {
	console.info("getSlotsByBundle sucess, data: " + JSON.stringify(data));
});
```



## Notification.getSlotNumByBundle

getSlotNumByBundle(bundle: BundleOption, callback: AsyncCallback\<number\>): void

Obtains the number of notification slots of a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                     | Mandatory| Description                  |
| -------- | ------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](#bundleoption)              | Yes  | Bundle information.            |
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the result.|

**Example**

```js
function getSlotNumByBundleCallback(err, data) {
    if (err.code) {
        console.info("getSlotNumByBundle failed " + JSON.stringify(err));
    } else {
        console.info("getSlotNumByBundle success");
    }
}
var bundle = {
    bundle: "bundleName1",
}
Notification.getSlotNumByBundle(bundle, getSlotNumByBundleCallback);
```



## Notification.getSlotNumByBundle

getSlotNumByBundle(bundle: BundleOption): Promise\<number\>

Obtains the number of notification slots of a specified bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle information.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | Promise used to return the result.|

**Example**

```js
var bundle = {
    bundle: "bundleName1",
}
Notification.getSlotNumByBundle(bundle).then((data) => {
	console.info("getSlotNumByBundle sucess, data: " + JSON.stringify(data));
});
```



## Notification.remove

remove(bundle: BundleOption, notificationKey: NotificationKey, reason: RemoveReason, callback: AsyncCallback\<void\>): void

Removes a notification for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name           | Type                               | Mandatory| Description                |
| --------------- |   ----------------------------------| ---- | -------------------- |
| bundle          | [BundleOption](#bundleoption)       | Yes  | Bundle information.          |
| notificationKey | [NotificationKey](#notificationkey) | Yes  | Notification key.            |
| reason          | [RemoveReason](#removereason9)      | Yes  | Indicates the reason for deleting a notification.        |
| callback        | AsyncCallback\<void\>               | Yes  | Callback used to return the result.|

**Example**

```js
function removeCallback(err) {
    if (err.code) {
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
var reason = Notification.RemoveReason.CLICK_REASON_REMOVE;
Notification.remove(bundle, notificationKey, reason, removeCallback);
```



## Notification.remove

remove(bundle: BundleOption, notificationKey: NotificationKey, reason: RemoveReason): Promise\<void\>

Removes a notification for a specified bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name           | Type           | Mandatory| Description      |
| --------------- | --------------- | ---- | ---------- |
| bundle          | [BundleOption](#bundleoption)    | Yes  | Bundle information.|
| notificationKey | [NotificationKey](#notificationkey) | Yes  | Notification key.  |
| reason          | [RemoveReason](#removereason9) | Yes  | Reason for deleting the notification.        |

**Example**

```js
var bundle = {
    bundle: "bundleName1",
}
var notificationKey = {
    id: 0,
    label: "label",
}
var reason = Notification.RemoveReason.CLICK_REASON_REMOVE;
Notification.remove(bundle, notificationKey, reason).then(() => {
	console.info("remove sucess");
});
```



## Notification.remove

remove(hashCode: string, reason: RemoveReason, callback: AsyncCallback\<void\>): void

Removes a notification for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| hashCode | string                | Yes  | Unique notification ID.          |
| reason   | [RemoveReason](#removereason9) | Yes  | Reason for removing the notification.        |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
var hashCode = 'hashCode'

function removeCallback(err) {
    if (err.code) {
        console.info("remove failed " + JSON.stringify(err));
    } else {
        console.info("remove success");
    }
}
var reason = Notification.RemoveReason.CANCEL_REASON_REMOVE;
Notification.remove(hashCode, reason, removeCallback);
```



## Notification.remove

remove(hashCode: string, reason: RemoveReason): Promise\<void\>

Removes a notification for a specified bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type      | Mandatory| Description      |
| -------- | ---------- | ---- | ---------- |
| hashCode | string | Yes  | Unique notification ID.|
| reason   | [RemoveReason](#removereason9) | Yes  | Reason for removing the notification.        |

**Example**

```js
var hashCode = 'hashCode'
var reason = Notification.RemoveReason.CLICK_REASON_REMOVE;
Notification.remove(hashCode, reason).then(() => {
	console.info("remove sucess");
});
```



## Notification.removeAll

removeAll(bundle: BundleOption, callback: AsyncCallback\<void\>): void

Removes all notifications for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name    | Type                 | Mandatory| Description                        |
| -------- | --------------------- | ---- | ---------------------------- |
| bundle   | [BundleOption](#bundleoption)          | Yes  | Bundle information.                  |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function removeAllCallback(err) {
    if (err.code) {
        console.info("removeAll failed " + JSON.stringify(err));
    } else {
        console.info("removeAll success");
    }
}
var bundle = {
    bundle: "bundleName1",
}
Notification.removeAll(bundle, removeAllCallback);
```



## Notification.removeAll

removeAll(callback: AsyncCallback\<void\>): void

Removes all notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function removeAllCallback(err) {
    if (err.code) {
        console.info("removeAll failed " + JSON.stringify(err));
    } else {
        console.info("removeAll success");
    }
}

Notification.removeAll(removeAllCallback);
```



## Notification.removeAll

removeAll(bundle?: BundleOption): Promise\<void\>

Removes all notifications for a specified user. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | No  | Bundle information.|

**Example**

```js
Notification.removeAll().then(() => {
	console.info("removeAll sucess");
});
```

## Notification.removeAll<sup>8+</sup>

removeAll(userId: number, callback: AsyncCallback\<void>): void

Removes all notifications for a specified user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| userId | number | Yes  | ID of the user who receives the notification.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function removeAllCallback(err) {
    if (err.code) {
        console.info("removeAll failed " + JSON.stringify(err));
    } else {
        console.info("removeAll success");
    }
}

var userId = 1

Notification.removeAll(userId, removeAllCallback);
```

## Notification.removeAll<sup>8+</sup>

removeAll(userId: number): Promise\<void>

Removes all notifications for a specified user. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| userId | number | Yes  | ID of the user who receives the notification.|

**Example**

```js
function removeAllCallback(err) {
    if (err.code) {
        console.info("removeAll failed " + JSON.stringify(err));
    } else {
        console.info("removeAll success");
    }
}

var userId = 1

Notification.removeAll(userId, removeAllCallback);
```


## Notification.getAllActiveNotifications

getAllActiveNotifications(callback: AsyncCallback<Array\<NotificationRequest\>>): void

Obtains all active notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                                                        | Mandatory| Description                |
| -------- | ------------------------------------------------------------ | ---- | -------------------- |
| callback | AsyncCallback<Array\<[NotificationRequest](#notificationrequest)\>> | Yes  | Callback used to return the result.|

**Example**

```js
function getAllActiveNotificationsCallback(err, data) {
    if (err.code) {
        console.info("getAllActiveNotifications failed " + JSON.stringify(err));
    } else {
        console.info("getAllActiveNotifications success");
    }
}

Notification.getAllActiveNotifications(getAllActiveNotificationsCallback);
```



## Notification.getAllActiveNotifications

getAllActiveNotifications(): Promise\<Array\<[NotificationRequest](#notificationrequest)\>\>

Obtains all active notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationRequest](#notificationrequest)\>\> | Promise used to return the result.|

**Example**

```js
Notification.getAllActiveNotifications().then((data) => {
	console.info("getAllActiveNotifications sucess, data: " + JSON.stringify(data));
});
```



## Notification.getActiveNotificationCount

getActiveNotificationCount(callback: AsyncCallback\<number\>): void

Obtains the number of active notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                  | Mandatory| Description                  |
| -------- | ---------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the result.|

**Example**

```js
function getActiveNotificationCountCallback(err, data) {
    if (err.code) {
        console.info("getActiveNotificationCount failed " + JSON.stringify(err));
    } else {
        console.info("getActiveNotificationCount success");
    }
}

Notification.getActiveNotificationCount(getActiveNotificationCountCallback);
```



## Notification.getActiveNotificationCount

getActiveNotificationCount(): Promise\<number\>

Obtains the number of active notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | Promise used to return the result.|

**Example**

```js
Notification.getActiveNotificationCount().then((data) => {
	console.info("getActiveNotificationCount sucess, data: " + JSON.stringify(data));
});
```



## Notification.getActiveNotifications

getActiveNotifications(callback: AsyncCallback<Array\<NotificationRequest\>>): void

Obtains active notifications of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                                                        | Mandatory| Description                          |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback<Array\<[NotificationRequest](#notificationrequest)\>> | Yes  | Callback used to return the result.|

**Example**

```js
function getActiveNotificationsCallback(err, data) {
    if (err.code) {
        console.info("getActiveNotifications failed " + JSON.stringify(err));
    } else {
        console.info("getActiveNotifications success");
    }
}

Notification.getActiveNotifications(getActiveNotificationsCallback);
```



## Notification.getActiveNotifications

getActiveNotifications(): Promise\<Array\<[NotificationRequest](#notificationrequest)\>\>

Obtains active notifications of this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationRequest](#notificationrequest)\>\> | Promise used to return the result.|

**Example**

```js
Notification.getActiveNotifications().then((data) => {
	console.info("removeGroupByBundle sucess, data: " + JSON.stringify(data));
});
```



## Notification.cancelGroup<sup>8+</sup>

cancelGroup(groupName: string, callback: AsyncCallback\<void\>): void

Cancels a notification group of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name     | Type                 | Mandatory| Description                        |
| --------- | --------------------- | ---- | ---------------------------- |
| groupName | string                | Yes  | Name of the notification group.              |
| callback  | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function cancelGroupCallback(err) {
    if (err.code) {
        console.info("cancelGroup failed " + JSON.stringify(err));
    } else {
        console.info("cancelGroup success");
    }
}

var groupName = "GroupName";

Notification.cancelGroup(groupName, cancelGroupCallback);
```



## Notification.cancelGroup<sup>8+</sup>

cancelGroup(groupName: string): Promise\<void\>

Cancels a notification group of this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name     | Type  | Mandatory| Description          |
| --------- | ------ | ---- | -------------- |
| groupName | string | Yes  | Name of the notification group.|

**Example**

```js
var groupName = "GroupName";
Notification.cancelGroup(groupName).then(() => {
	console.info("cancelGroup sucess");
});
```



## Notification.removeGroupByBundle<sup>8+</sup>

removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void\>): void

Removes a notification group for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type                 | Mandatory| Description                        |
| --------- | --------------------- | ---- | ---------------------------- |
| bundle    | [BundleOption](#bundleoption)          | Yes  | Bundle information.                  |
| groupName | string                | Yes  | Name of the notification group.              |
| callback  | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function removeGroupByBundleCallback(err) {
    if (err.code) {
        console.info("removeGroupByBundle failed " + JSON.stringify(err));
    } else {
        console.info("removeGroupByBundle success");
    }
}

var bundleOption = {bundle: "Bundle"};
var groupName = "GroupName";

Notification.removeGroupByBundle(bundleOption, groupName, removeGroupByBundleCallback);
```



## Notification.removeGroupByBundle<sup>8+</sup>

removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void\>

Removes a notification group for a specified bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type        | Mandatory| Description          |
| --------- | ------------ | ---- | -------------- |
| bundle    | [BundleOption](#bundleoption) | Yes  | Bundle information.    |
| groupName | string       | Yes  | Name of the notification group.|

**Example**

```js
var bundleOption = {bundle: "Bundle"};
var groupName = "GroupName";
Notification.removeGroupByBundle(bundleOption, groupName).then(() => {
	console.info("removeGroupByBundle sucess");
});
```



## Notification.setDoNotDisturbDate<sup>8+</sup>

setDoNotDisturbDate(date: DoNotDisturbDate, callback: AsyncCallback\<void\>): void

Sets the DND time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                  |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate8)      | Yes  | DND time to set.        |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function setDoNotDisturbDateCallback(err) {
    if (err.code) {
        console.info("setDoNotDisturbDate failed " + JSON.stringify(err));
    } else {
        console.info("setDoNotDisturbDate success");
    }
}

var doNotDisturbDate = {
    type: Notification.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
}

Notification.setDoNotDisturbDate(doNotDisturbDate, setDoNotDisturbDateCallback);
```



## Notification.setDoNotDisturbDate<sup>8+</sup>

setDoNotDisturbDate(date: DoNotDisturbDate): Promise\<void\>

Sets the DND time. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type            | Mandatory| Description          |
| ---- | ---------------- | ---- | -------------- |
| date | [DoNotDisturbDate](#donotdisturbdate8) | Yes  | DND time to set.|

**Example**

```js
var doNotDisturbDate = {
    type: Notification.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
}
Notification.setDoNotDisturbDate(doNotDisturbDate).then(() => {
	console.info("setDoNotDisturbDate sucess");
});
```


## Notification.setDoNotDisturbDate<sup>8+</sup>

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number, callback: AsyncCallback\<void\>): void

Sets the DND time for a specified user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                  |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate8)      | Yes  | DND time to set.        |
| userId   | number                | Yes  | User ID.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function setDoNotDisturbDateCallback(err) {
    if (err.code) {
        console.info("setDoNotDisturbDate failed " + JSON.stringify(err));
    } else {
        console.info("setDoNotDisturbDate success");
    }
}

var doNotDisturbDate = {
    type: Notification.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
}

var userId = 1

Notification.setDoNotDisturbDate(doNotDisturbDate, userId, setDoNotDisturbDateCallback);
```



## Notification.setDoNotDisturbDate<sup>8+</sup>

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number): Promise\<void\>

Sets the DND time for a specified user. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type            | Mandatory| Description          |
| ------ | ---------------- | ---- | -------------- |
| date   | [DoNotDisturbDate](#donotdisturbdate8) | Yes  | DND time to set.|
| userId | number           | Yes  | User ID.|

**Example**

```js
var doNotDisturbDate = {
    type: Notification.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
}

var userId = 1

Notification.setDoNotDisturbDate(doNotDisturbDate, userId).then(() => {
	console.info("setDoNotDisturbDate sucess");
});
```


## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate\>): void

Obtains the DND time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                             | Mandatory| Description                  |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate8)\> | Yes  | Callback used to return the result.|

**Example**

```js
function getDoNotDisturbDateCallback(err,data) {
    if (err.code) {
        console.info("getDoNotDisturbDate failed " + JSON.stringify(err));
    } else {
        console.info("getDoNotDisturbDate success");
    }
}

Notification.getDoNotDisturbDate(getDoNotDisturbDateCallback);
```



## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(): Promise\<DoNotDisturbDate\>

Obtains the DND time. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[DoNotDisturbDate](#donotdisturbdate8)\> | Promise used to return the result.|

**Example**

```js
Notification.getDoNotDisturbDate().then((data) => {
	console.info("getDoNotDisturbDate sucess, data: " + JSON.stringify(data));
});
```


## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(userId: number, callback: AsyncCallback\<DoNotDisturbDate\>): void

Obtains the DND time of a specified user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                             | Mandatory| Description                  |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate8)\> | Yes  | Callback used to return the result.|
| userId   | number                            | Yes  | User ID.|

**Example**

```js
function getDoNotDisturbDateCallback(err,data) {
    if (err.code) {
        console.info("getDoNotDisturbDate failed " + JSON.stringify(err));
    } else {
        console.info("getDoNotDisturbDate success");
    }
}

var userId = 1

Notification.getDoNotDisturbDate(userId, getDoNotDisturbDateCallback);
```



## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(userId: number): Promise\<DoNotDisturbDate\>

Obtains the DND time of a specified user. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                             | Mandatory| Description                  |
| -------- | --------------------------------- | ---- | ---------------------- |
| userId   | number                            | Yes  | User ID.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[DoNotDisturbDate](#donotdisturbdate8)\> | Promise used to return the result.|

**Example**

```js
var userId = 1

Notification.getDoNotDisturbDate(userId).then((data) => {
	console.info("getDoNotDisturbDate sucess, data: " + JSON.stringify(data));
});
```


## Notification.supportDoNotDisturbMode<sup>8+</sup>

supportDoNotDisturbMode(callback: AsyncCallback\<boolean\>): void

Checks whether the DND mode is supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                    | Mandatory| Description                            |
| -------- | ------------------------ | ---- | -------------------------------- |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Example**

```js
function supportDoNotDisturbModeCallback(err,data) {
    if (err.code) {
        console.info("supportDoNotDisturbMode failed " + JSON.stringify(err));
    } else {
        console.info("supportDoNotDisturbMode success");
    }
}

Notification.supportDoNotDisturbMode(supportDoNotDisturbModeCallback);
```



## Notification.supportDoNotDisturbMode<sup>8+</sup>

supportDoNotDisturbMode(): Promise\<boolean\>

Checks whether the DND mode is supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

```js
Notification.supportDoNotDisturbMode().then((data) => {
	console.info("supportDoNotDisturbMode sucess, data: " + JSON.stringify(data));
});
```



## Notification.isSupportTemplate<sup>8+</sup>

isSupportTemplate(templateName: string, callback: AsyncCallback\<boolean\>): void

Checks whether a specified template exists. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name      | Type                    | Mandatory| Description                      |
| ------------ | ------------------------ | ---- | -------------------------- |
| templateName | string                   | Yes  | Template name.                  |
| callback     | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Example**

```javascript
var templateName = 'process';
function isSupportTemplateCallback(err, data) {
    if (err.code) {
        console.info("isSupportTemplate failed " + JSON.stringify(err));
    } else {
        console.info("isSupportTemplate success");
    }
}

Notification.isSupportTemplate(templateName, isSupportTemplateCallback);
```



## Notification.isSupportTemplate<sup>8+</sup>

isSupportTemplate(templateName: string): Promise\<boolean\>

Checks whether a specified template exists. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name      | Type  | Mandatory| Description    |
| ------------ | ------ | ---- | -------- |
| templateName | string | Yes  | Template name.|

**Return value**

| Type              | Description           |
| ------------------ | --------------- |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

```javascript
var templateName = 'process';

Notification.isSupportTemplate(templateName).then((data) => {
    console.info("isSupportTemplate success, data: " + JSON.stringify(data));
});
```



## Notification.requestEnableNotification<sup>8+</sup>

requestEnableNotification(callback: AsyncCallback\<void\>): void

Requests notification to be enabled for this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```javascript
function requestEnableNotificationCallback() {
    if (err.code) {
        console.info("requestEnableNotification failed " + JSON.stringify(err));
    } else {
        console.info("requestEnableNotification success");
    }
};

Notification.requestEnableNotification(requestEnableNotificationCallback);
```



## Notification.requestEnableNotification<sup>8+</sup>

requestEnableNotification(): Promise\<void\>

Requests notification to be enabled for this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Example**

```javascript
Notification.requestEnableNotification()
    .then(() => {
        console.info("requestEnableNotification sucess");
	});
```


## Notification.enableDistributed<sup>8+</sup>

enableDistributed(enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether this device supports distributed notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | Yes  | Whether the device supports distributed notifications.<br>**true**: The device supports distributed notifications.<br>**false**: The device does not support distributed notifications.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```javascript
function enabledNotificationCallback() {
    if (err.code) {
        console.info("enableDistributed failed " + JSON.stringify(err));
    } else {
        console.info("enableDistributed success");
    }
};

var enable = true

Notification.enableDistributed(enable, enabledNotificationCallback);
```



## Notification.enableDistributed<sup>8+</sup>

enableDistributed(enable: boolean): Promise\<void>

Sets whether this device supports distributed notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | Yes  | Whether the device supports distributed notifications.<br>**true**: The device supports distributed notifications.<br>**false**: The device does not support distributed notifications.|

**Example**

```javascript
var enable = true

Notification.enableDistributed(enable)
    .then(() => {
        console.info("enableDistributed sucess");
    });
```


## Notification.isDistributedEnabled<sup>8+</sup>

isDistributedEnabled(callback: AsyncCallback\<boolean>): void

Obtains whether this device supports distributed notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Example**

```javascript
function isDistributedEnabledCallback() {
    if (err.code) {
        console.info("isDistributedEnabled failed " + JSON.stringify(err));
    } else {
        console.info("isDistributedEnabled success");
    }
};

Notification.isDistributedEnabled(isDistributedEnabledCallback);
```



## Notification.isDistributedEnabled<sup>8+</sup>

isDistributedEnabled(): Promise\<boolean>

Obtains whether this device supports distributed notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Return value**

| Type              | Description           |
| ------------------ | --------------- |
| Promise\<boolean\> | Promise used to return the result.<br>**true**: The device supports distributed notifications.<br>**false**: The device does not support distributed notifications.|

**Example**

```javascript
Notification.isDistributedEnabled()
    .then((data) => {
        console.info("isDistributedEnabled sucess, data: " + JSON.stringify(data));
    });
```


## Notification.enableDistributedByBundle<sup>8+</sup>

enableDistributedByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void

Sets whether an application supports distributed notifications based on the bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](#bundleoption)             | Yes  | Application bundle.                    |
| enable   | boolean                  | Yes  | Whether the device supports distributed notifications.                      |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```javascript
function enableDistributedByBundleCallback() {
    if (err.code) {
        console.info("enableDistributedByBundle failed " + JSON.stringify(err));
    } else {
        console.info("enableDistributedByBundle success");
    }
};

var bundle = {
    bundle: "bundleName1",
}

var enable = true

Notification.enableDistributedByBundle(bundle, enable, enableDistributedByBundleCallback);
```



## Notification.enableDistributedByBundle<sup>8+</sup>

enableDistributedByBundle(bundle: BundleOption, enable: boolean): Promise\<void>

Sets whether an application supports distributed notifications based on the bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](#bundleoption)             | Yes  | Application bundle.               |
| enable   | boolean                  | Yes  | Whether the device supports distributed notifications.                 |

**Example**

```javascript
var bundle = {
    bundle: "bundleName1",
}

var enable = true

Notification.enableDistributedByBundle(bundle, enable)
    .then(() => {
        console.info("enableDistributedByBundle sucess");
    });
```

## Notification.isDistributedEnabledByBundle<sup>8+</sup>

isDistributedEnabledByBundle(bundle: BundleOption, callback: AsyncCallback\<boolean>): void

Obtains whether an application supports distributed notifications based on the bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](#bundleoption)             | Yes  | Application bundle.                    |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Example**

```javascript
function isDistributedEnabledByBundleCallback(data) {
    if (err.code) {
        console.info("isDistributedEnabledByBundle failed " + JSON.stringify(err));
    } else {
        console.info("isDistributedEnabledByBundle success");
    }
};

var bundle = {
    bundle: "bundleName1",
}

Notification.isDistributedEnabledByBundle(bundle, isDistributedEnabledByBundleCallback);
```



## Notification.isDistributedEnabledByBundle<sup>8+</sup>

isDistributedEnabledByBundle(bundle: BundleOption): Promise\<boolean>

Obtains whether an application supports distributed notifications based on the bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](#bundleoption)             | Yes  | Application bundle.               |

**Return value**

| Type              | Description           |
| ------------------ | --------------- |
| Promise\<boolean\> | Promise used to return the result.<br>**true**: The device supports distributed notifications.<br>**false**: The device does not support distributed notifications.|

**Example**

```javascript
var bundle = {
    bundle: "bundleName1",
}

Notification.isDistributedEnabledByBundle(bundle)
    .then((data) => {
        console.info("isDistributedEnabledByBundle sucess, data: " + JSON.stringify(data));
    });
```


## Notification.getDeviceRemindType<sup>8+</sup>

getDeviceRemindType(callback: AsyncCallback\<DeviceRemindType\>): void

Obtains the notification reminder type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                              | Mandatory| Description                      |
| -------- | --------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<[DeviceRemindType](#deviceremindtype8)\> | Yes  | Callback used to return the result.|

**Example**

```javascript
function getDeviceRemindTypeCallback(data) {
    if (err.code) {
        console.info("getDeviceRemindType failed " + JSON.stringify(err));
    } else {
        console.info("getDeviceRemindType success");
    }
};

Notification.getDeviceRemindType(getDeviceRemindTypeCallback);
```



## Notification.getDeviceRemindType<sup>8+</sup>

getDeviceRemindType(): Promise\<DeviceRemindType\>

Obtains the notification reminder type. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

| Type              | Description           |
| ------------------ | --------------- |
| Promise\<[DeviceRemindType](#deviceremindtype8)\> | Promise used to return the result.|

**Example**

```javascript
Notification.getDeviceRemindType()
    .then((data) => {
        console.info("getDeviceRemindType sucess, data: " + JSON.stringify(data));
    });
```


## Notification.publishAsBundle<sup>9+</sup>

publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number, callback: AsyncCallback\<void\>): void

Publishes an agent-powered notification. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER, ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name              | Type                                       | Mandatory| Description                                         |
| -------------------- | ------------------------------------------- | ---- | --------------------------------------------- |
| request              | [NotificationRequest](#notificationrequest) | Yes  | **NotificationRequest** object.|
| representativeBundle | string                                      | Yes  | Bundle name of the application whose notification function is taken over by the reminder agent.                           |
| userId               | number                                      | Yes  | ID of the user who receives the notification.                           |
| callback             | AsyncCallback                               | Yes  | Callback used to return the result.                     |

**Example**

```js
// Callback for publishAsBundle
function publishAsBundleCallback(err) {
    if (err.code) {
        console.info("publishAsBundle failed " + JSON.stringify(err));
    } else {
        console.info("publishAsBundle success");
    }
}
// Bundle name of the application whose notification function is taken over by the reminder agent
let representativeBundle = "com.example.demo"
// ID of the user who receives the notification
let userId = 100
// NotificationRequest object
let notificationRequest = {
    id: 1,
    content: {
        contentType: Notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
}

Notification.publishAsBundle(notificationRequest, representativeBundle, userId, publishAsBundleCallback);
```

## Notification.publishAsBundle<sup>9+</sup>

publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number): Promise\<void\>

Publishes a notification through the reminder agent. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER, ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**


| Name              | Type                                       | Mandatory| Description                                         |
| -------------------- | ------------------------------------------- | ---- | --------------------------------------------- |
| request              | [NotificationRequest](#notificationrequest) | Yes  | **NotificationRequest** object.|
| representativeBundle | string                                      | Yes  | Bundle name of the application whose notification function is taken over by the reminder agent.                           |
| userId               | number                                      | Yes  | ID of the user who receives the notification.                           |

**Example**

```js
// Bundle name of the application whose notification function is taken over by the reminder agent
let representativeBundle = "com.example.demo"
// ID of the user who receives the notification
let userId = 100
// NotificationRequest object
var notificationRequest = {
    id: 1,
    content: {
        contentType: Notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
}

Notification.publishAsBundle(notificationRequest, representativeBundle, userId).then(() => {
	console.info("publishAsBundle sucess");
});
```

## Notification.cancelAsBundle<sup>9+</sup>

cancelAsBundle(id: number, representativeBundle: string, userId: number, callback: AsyncCallback\<void\>): void

Cancels a notification published by the reminder agent. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER, ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name              | Type         | Mandatory| Description                    |
| -------------------- | ------------- | ---- | ------------------------ |
| id                   | number        | Yes  | Notification ID.                |
| representativeBundle | string        | Yes  | Bundle name of the application whose notification function is taken over by the reminder agent.      |
| userId               | number        | Yes  | ID of the user who receives the notification.      |
| callback             | AsyncCallback | Yes  | Callback used to return the result.|

**Example**

```js
//cancelAsBundle
function cancelAsBundleCallback(err) {
    if (err.code) {
        console.info("cancelAsBundle failed " + JSON.stringify(err));
    } else {
        console.info("cancelAsBundle success");
    }
}
// Bundle name of the application whose notification function is taken over by the reminder agent
let representativeBundle = "com.example.demo"
// ID of the user who receives the notification
let userId = 100

Notification.cancelAsBundle(0, representativeBundle, userId, cancelAsBundleCallback);
```

## Notification.cancelAsBundle<sup>9+</sup>

cancelAsBundle(id: number, representativeBundle: string, userId: number): Promise\<void\>

Publishes a notification through the reminder agent. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER, ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name              | Type  | Mandatory| Description              |
| -------------------- | ------ | ---- | ------------------ |
| id                   | number | Yes  | Notification ID.          |
| representativeBundle | string | Yes  | Bundle name of the application whose notification function is taken over by the reminder agent.|
| userId               | number | Yes  | ID of the user who receives the notification.|

**Example**

```js
// Bundle name of the application whose notification function is taken over by the reminder agent
let representativeBundle = "com.example.demo"
// ID of the user who receives the notification
let userId = 100

Notification.cancelAsBundle(0, representativeBundle, userId).then(() => {
	console.info("cancelAsBundle success");
});
```

## Notification.enableNotificationSlot <sup>9+</sup>

enableNotificationSlot(bundle: BundleOption, type: SlotType, enable: boolean, callback: AsyncCallback\<void>): void

Sets the enabled status for a notification slot of a specified type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name  | Type                         | Mandatory| Description                  |
| -------- | ----------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](#bundleoption) | Yes  | Bundle information.          |
| type     | [SlotType](#slottype)         | Yes  | Notification slot type.        |
| enable   | boolean                       | Yes  | Whether to enable notification.            |
| callback | AsyncCallback\<void\>         | Yes  | Callback used to return the result.|

**Example**

```js
//enableNotificationSlot
function enableSlotCallback(err) {
    if (err.code) {
        console.info("enableNotificationSlot failed " + JSON.stringify(err));
    } else {
        console.info("enableNotificationSlot success");
    }
};

Notification.enableNotificationSlot(
    { bundle: "ohos.samples.notification", },
    Notification.SlotType.SOCIAL_COMMUNICATION,
    true,
    enableSlotCallback);
```

## Notification.enableNotificationSlot <sup>9+</sup>

enableNotificationSlot(bundle: BundleOption, type: SlotType, enable: boolean): Promise\<void> 

Sets the enabled status for a notification slot of a specified type. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle information.  |
| type   | [SlotType](#slottype)         | Yes  | Notification slot type.|
| enable | boolean                       | Yes  | Whether to enable notification.    |

**Example**

```js
//enableNotificationSlot
Notification.enableNotificationSlot(
    { bundle: "ohos.samples.notification", },
    Notification.SlotType.SOCIAL_COMMUNICATION,
    true).then(() => {
        console.info("enableNotificationSlot sucess");
    });
```

## Notification.isNotificationSlotEnabled <sup>9+</sup>

isNotificationSlotEnabled(bundle: BundleOption, type: SlotType, callback: AsyncCallback\<boolean\>): void

Obtains the enabled status of the notification slot of a specified type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name  | Type                         | Mandatory| Description                  |
| -------- | ----------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](#bundleoption) | Yes  | Bundle information.          |
| type     | [SlotType](#slottype)         | Yes  | Notification slot type.        |
| callback | AsyncCallback\<boolean\>         | Yes  | Callback used to return the result.|

**Example**

```js
//isNotificationSlotEnabled
function getEnableSlotCallback(err, data) {
    if (err.code) {
        console.info("isNotificationSlotEnabled failed " + JSON.stringify(err));
    } else {
        console.info("isNotificationSlotEnabled success");
    }
};

Notification.isNotificationSlotEnabled(
    { bundle: "ohos.samples.notification", },
    Notification.SlotType.SOCIAL_COMMUNICATION,
    getEnableSlotCallback);
```

## Notification.isNotificationSlotEnabled <sup>9+</sup>

isNotificationSlotEnabled(bundle: BundleOption, type: SlotType): Promise\<boolean\>  

Obtains the enabled status of the notification slot of a specified type. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle information.  |
| type   | [SlotType](#slottype)         | Yes  | Notification slot type.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the enabled status of the notification slot of the specified type.|

**Example**

```js
//isNotificationSlotEnabled
Notification.isNotificationSlotEnabled(
    { bundle: "ohos.samples.notification", },
    Notification.SlotType.SOCIAL_COMMUNICATION
    ).then((data) => {
      console.info("isNotificationSlotEnabled success, data: " + JSON.stringify(data));
    });
```


## Notification.setSyncNotificationEnabledWithoutApp<sup>9+</sup>

setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether to sync notifications to devices where the application is not installed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | Yes  | User ID.  |
| enable | boolean | Yes  | Whether the feature is enabled.<br>**true**: enabled<br>**false**: disabled  |
| callback | AsyncCallback\<void\>    | Yes  | Callback used to return the result.|

**Example**

```js
let userId = 100;
let enable = true;

function setSyncNotificationEnabledWithoutAppCallback(err) {
    if (err.code) {
        console.info("setSyncNotificationEnabledWithoutApp failed " + JSON.stringify(err));
    } else {
        console.info("setSyncNotificationEnabledWithoutApp success");
    }
}

Notification.setSyncNotificationEnabledWithoutApp(userId, enable, setSyncNotificationEnabledWithoutAppCallback);
```


## Notification.setSyncNotificationEnabledWithoutApp<sup>9+</sup>

setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean): Promise\<void>

Sets whether to sync notifications to devices where the application is not installed. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | Yes  | User ID.  |
| enable | boolean | Yes  | Whether the feature is enabled.<br>**true**: enabled<br>**false**: disabled  |

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<void\> | Promise used to return the result.|

**Example**

```js
let userId = 100;
let enable = true;

Notification.setSyncNotificationEnabledWithoutApp(userId, enable)
    .then(() => {
        console.info('setSyncNotificationEnabledWithoutApp');
    })
    .catch((err) => {
        console.info('setSyncNotificationEnabledWithoutApp, err:', err);
    });
```


## Notification.getSyncNotificationEnabledWithoutApp<sup>9+</sup>

getSyncNotificationEnabledWithoutApp(userId: number, callback: AsyncCallback\<boolean>): void

Obtains whether notifications are synced to devices where the application is not installed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | Yes  | User ID.  |
| callback | AsyncCallback\<boolean\>         | Yes  | Callback used to return the result.<br>**true**: Notifications are synced to devices where the application is not installed.<br>**false**: Notifications are not synced to devices where the application is not installed.|

**Example**

```js
let userId = 100;

function getSyncNotificationEnabledWithoutAppCallback(data, err) {
    if (err) {
        console.info('getSyncNotificationEnabledWithoutAppCallback, err' + err);
    } else {
        console.info('getSyncNotificationEnabledWithoutAppCallback, data' + data);
    }
}

Notification.getSyncNotificationEnabledWithoutApp(userId, getSyncNotificationEnabledWithoutAppCallback);
```


## Notification.getSyncNotificationEnabledWithoutApp<sup>9+</sup>

getSyncNotificationEnabledWithoutApp(userId: number): Promise\<boolean>

Obtains whether notifications are synced to devices where the application is not installed. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | Yes  | User ID.  |

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.<br>**true**: Notifications are synced to devices where the application is not installed.<br>**false**: Notifications are not synced to devices where the application is not installed.|

**Example**

```js
let userId = 100;

Notification.getSyncNotificationEnabledWithoutApp(userId)
    .then((data) => {
        console.info('getSyncNotificationEnabledWithoutApp, data:', data);
    })
    .catch((err) => {
        console.info('getSyncNotificationEnabledWithoutApp, err:', err);
    });
```



## NotificationSubscriber

**System API**: This is a system API and cannot be called by third-party applications.

### onConsume

onConsume?: (data: [SubscribeCallbackData](#subscribecallbackdata)) => void

Callback for receiving notifications.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| data | AsyncCallback\<[SubscribeCallbackData](#subscribecallbackdata)\> | Yes| Notification information returned.|

**Example**

```javascript
function subscribeCallback(err) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onConsumeCallback(data) {
    console.info('===> onConsume in test');
    let req = data.request;
    console.info('===> onConsume callback req.id:' + req.id);
    let wantAgent = data.wantAgent;
    wantAgent .getWant(wantAgent)
        .then((data1) => {
            console.info('===> getWant success want:' + JSON.stringify(data1));
        })
        .catch((err) => {
            console.error('===> getWant failed because' + JSON.stringify(err));
        });
    console.info('===> onConsume callback req.wantAgent:' + JSON.stringify(req.wantAgent));
};

var subscriber = {
    onConsume: onConsumeCallback
};

Notification.subscribe(subscriber, subscribeCallback);
```

### onCancel

onCancel?:(data: [SubscribeCallbackData](#subscribecallbackdata)) => void

Callback for removing notifications.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| data | AsyncCallback\<[SubscribeCallbackData](#subscribecallbackdata)\> | Yes| Notification information returned.|

**Example**

```javascript
function subscribeCallback(err) {
    if (err.code) {
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

Notification.subscribe(subscriber, subscribeCallback);
```

### onUpdate

onUpdate?:(data: [NotificationSortingMap](#notificationsortingmap)) => void

Callback for notification sorting updates.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [NotificationSortingMap](#notificationsortingmap) | Yes| Notification information returned.|

**Example**

```javascript
function subscribeCallback(err) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onUpdateCallback() {
    console.info('===> onUpdate in test');
}

var subscriber = {
    onUpdate: onUpdateCallback
};

Notification.subscribe(subscriber, subscribeCallback);
```

### onConnect

onConnect?:() => void

Callback for subscription.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Example**

```javascript
function subscribeCallback(err) {
    if (err.code) {
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

Notification.subscribe(subscriber, subscribeCallback);
```

### onDisconnect

onDisconnect?:() => void

Callback for unsubscription.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Example**

```javascript
function subscribeCallback(err) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onDisconnectCallback() {
    console.info('===> onDisconnect in test');
}

var subscriber = {
    onDisconnect: onDisconnectCallback
};

Notification.subscribe(subscriber, subscribeCallback);
```

### onDestroy

onDestroy?:() => void

Callback for service disconnection.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Example**

```javascript
function subscribeCallback(err) {
    if (err.code) {
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

Notification.subscribe(subscriber, subscribeCallback);
```

### onDoNotDisturbDateChange<sup>8+</sup>

onDoNotDisturbDateChange?:(mode: notification.[DoNotDisturbDate](#donotdisturbdate8)) => void

Callback for DND time setting updates.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| mode | notification.[DoNotDisturbDate](#donotdisturbdate8) | Yes| DND time setting updates.|

**Example**
```javascript
function subscribeCallback(err) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onDoNotDisturbDateChangeCallback() {
    console.info('===> onDoNotDisturbDateChange in test');
}

var subscriber = {
    onDoNotDisturbDateChange: onDoNotDisturbDateChangeCallback
};

Notification.subscribe(subscriber, subscribeCallback);
```


### onEnabledNotificationChanged<sup>8+</sup>

onEnabledNotificationChanged?:(callbackData: [EnabledNotificationCallbackData](#enablednotificationcallbackdata8)) => void

Listens for the notification enable status changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<[EnabledNotificationCallbackData](#enablednotificationcallbackdata8)\> | Yes| Callback used to return the result.|

**Example**

```javascript
function subscribeCallback(err) {
    if (err.code) {
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

Notification.subscribe(subscriber, subscribeCallback);
```

## SubscribeCallbackData

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name           | Readable| Writable| Type                                             | Description    |
| --------------- | ---- | --- | ------------------------------------------------- | -------- |
| request         | Yes | No | [NotificationRequest](#notificationrequest)       | Notification content.|
| sortingMap      | Yes | No | [NotificationSortingMap](#notificationsortingmap) | Notification sorting information.|
| reason          | Yes | No | number                                            | Reason for deletion.|
| sound           | Yes | No | string                                            | Sound used for notification.|
| vibrationValues | Yes | No | Array\<number\>                                   | Vibration used for notification.|


## EnabledNotificationCallbackData<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name  | Readable| Writable| Type   | Description            |
| ------ | ---- | --- | ------- | ---------------- |
| bundle | Yes | No | string  | Bundle name of the application.      |
| uid    | Yes | No | number  | UID of the application.       |
| enable | Yes | No | boolean | Notification enabled status of the application.|


## DoNotDisturbDate<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name | Readable| Writable| Type                                 | Description                    |
| ----- | ---- | --- | ------------------------------------- | ------------------------ |
| type  | Yes | No | [DoNotDisturbType](#donotdisturbtype8) | DND time type.|
| begin | Yes | No | Date                                  | DND start time.|
| end   | Yes | No | Date                                  | DND end time.|



## DoNotDisturbType<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name        | Value              | Description                                      |
| ------------ | ---------------- | ------------------------------------------ |
| TYPE_NONE    | 0 | Non-DND.                          |
| TYPE_ONCE    | 1 | One-shot DND at the specified time segment (only considering the hour and minute).|
| TYPE_DAILY   | 2 | Daily DND at the specified time segment (only considering the hour and minute).|
| TYPE_CLEARLY | 3 | DND at the specified time segment (considering the year, month, day, hour, and minute).    |


## ContentType

**System capability**: SystemCapability.Notification.Notification

| Name                             | Value         | Description              |
| --------------------------------- | ----------- | ------------------ |
| NOTIFICATION_CONTENT_BASIC_TEXT   | NOTIFICATION_CONTENT_BASIC_TEXT | Normal text notification.    |
| NOTIFICATION_CONTENT_LONG_TEXT    | NOTIFICATION_CONTENT_LONG_TEXT | Long text notification.  |
| NOTIFICATION_CONTENT_PICTURE      | NOTIFICATION_CONTENT_PICTURE | Picture-attached notification.    |
| NOTIFICATION_CONTENT_CONVERSATION | NOTIFICATION_CONTENT_CONVERSATION | Conversation notification.    |
| NOTIFICATION_CONTENT_MULTILINE    | NOTIFICATION_CONTENT_MULTILINE | Multi-line text notification.|

## SlotLevel

**System capability**: SystemCapability.Notification.Notification

| Name                             | Value         | Description              |
| --------------------------------- | ----------- | ------------------ |
| LEVEL_NONE                        | 0           | The notification function is disabled.    |
| LEVEL_MIN                         | 1           | The notification function is enabled, but the notification icon is not displayed in the status bar, with no banner or alert tone.|
| LEVEL_LOW                         | 2           | The notification function is enabled, and the notification icon is displayed in the status bar, with no banner or alert tone.|
| LEVEL_DEFAULT                     | 3           | The notification feature is enabled, and the notification icon is displayed in the status bar, with an alert tone but no banner.|
| LEVEL_HIGH                        | 4           | The notification feature is enabled, and the notification icon is displayed in the status bar, with an alert tone and banner.|


## BundleOption

**System capability**: SystemCapability.Notification.Notification

| Name  | Readable| Writable| Type  | Description  |
| ------ | ---- | --- | ------ | ------ |
| bundle | Yes | Yes | string | Bundle name.  |
| uid    | Yes | Yes | number | User ID.|



## NotificationKey

**System capability**: SystemCapability.Notification.Notification

| Name | Readable| Writable| Type  | Description    |
| ----- | ---- | --- | ------ | -------- |
| id    | Yes | Yes | number | Notification ID.  |
| label | Yes | Yes | string | Notification label.|


## SlotType

**System capability**: SystemCapability.Notification.Notification

| Name                | Value      | Description      |
| -------------------- | -------- | ---------- |
| UNKNOWN_TYPE         | 0 | Unknown type.|
| SOCIAL_COMMUNICATION | 1 | Notification slot for social communication.|
| SERVICE_INFORMATION  | 2 | Notification slot for service information.|
| CONTENT_INFORMATION  | 3 | Notification slot for content consultation.|
| OTHER_TYPES          | 0xFFFF | Notification slot for other purposes.|


## NotificationActionButton

**System capability**: SystemCapability.Notification.Notification

| Name     | Readable| Writable| Type                                           | Description                     |
| --------- | --- | ---- | ----------------------------------------------- | ------------------------- |
| title     | Yes | Yes | string                                          | Button title.                 |
| wantAgent | Yes | Yes | WantAgent                                       | **WantAgent** of the button.|
| extras    | Yes | Yes | { [key: string]: any }                          | Extra information of the button.             |
| userInput<sup>8+</sup> | Yes | Yes | [NotificationUserInput](#notificationuserinput8) | User input object.         |


## NotificationBasicContent

**System capability**: SystemCapability.Notification.Notification

| Name          | Readable| Writable| Type  | Description                              |
| -------------- | ---- | ---- | ------ | ---------------------------------- |
| title          | Yes  | Yes  | string | Notification title.                        |
| text           | Yes  | Yes  | string | Notification content.                        |
| additionalText | Yes  | Yes  | string | Additional information of the notification.|


## NotificationLongTextContent

**System capability**: SystemCapability.Notification.Notification

| Name          | Readable| Writable| Type  | Description                            |
| -------------- | ---- | --- | ------ | -------------------------------- |
| title          | Yes | Yes | string | Notification title.                        |
| text           | Yes | Yes | string | Notification content.                        |
| additionalText | Yes | Yes | string | Additional information of the notification.|
| longText       | Yes | Yes | string | Long text of the notification.                    |
| briefText      | Yes | Yes | string | Brief text of the notification.|
| expandedTitle  | Yes | Yes | string | Title of the notification in the expanded state.                |


## NotificationMultiLineContent

**System capability**: SystemCapability.Notification.Notification

| Name          | Readable| Writable| Type           | Description                            |
| -------------- | --- | --- | --------------- | -------------------------------- |
| title          | Yes | Yes | string          | Notification title.                        |
| text           | Yes | Yes | string          | Notification content.                        |
| additionalText | Yes | Yes | string          | Additional information of the notification.|
| briefText      | Yes | Yes | string          | Brief text of the notification.|
| longTitle      | Yes | Yes | string          | Title of the notification in the expanded state.                |
| lines          | Yes | Yes | Array\<string\> | Multi-line text of the notification.                  |


## NotificationPictureContent

**System capability**: SystemCapability.Notification.Notification

| Name          | Readable| Writable| Type          | Description                            |
| -------------- | ---- | --- | -------------- | -------------------------------- |
| title          | Yes | Yes | string         | Notification title.                        |
| text           | Yes | Yes | string         | Notification content.                        |
| additionalText | Yes | Yes | string         | Additional information of the notification.|
| briefText      | Yes | Yes | string         | Brief text of the notification.|
| expandedTitle  | Yes | Yes | string         | Title of the notification in the expanded state.                |
| picture        | Yes | Yes | image.PixelMap | Picture attached to the notification.                  |


## NotificationContent

**System capability**: SystemCapability.Notification.Notification

| Name       | Readable| Writable| Type                                                        | Description              |
| ----------- | ---- | --- | ------------------------------------------------------------ | ------------------ |
| contentType | Yes | Yes | [ContentType](#contenttype)                                  | Notification content type.      |
| normal      | Yes | Yes | [NotificationBasicContent](#notificationbasiccontent)        | Normal text.  |
| longText    | Yes | Yes | [NotificationLongTextContent](#notificationlongtextcontent)  | Long text.|
| multiLine   | Yes | Yes | [NotificationMultiLineContent](#notificationmultilinecontent) | Multi-line text.  |
| picture     | Yes | Yes | [NotificationPictureContent](#notificationpicturecontent)    | Picture-attached.  |


## NotificationFlagStatus<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name          | Value | Description                              |
| -------------- | --- | --------------------------------- |
| TYPE_NONE      | 0   | The default flag is used.                        |
| TYPE_OPEN      | 1   | The notification flag is enabled.                    |
| TYPE_CLOSE     | 2   | The notification flag is disabled.                    |


## NotificationFlags<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

| Name            | Readable| Writable| Type                   | Description                              |
| ---------------- | ---- | ---- | ---------------------- | --------------------------------- |
| soundEnabled     | Yes  | No  | NotificationFlagStatus | Whether to enable the sound alert for the notification.                 |
| vibrationEnabled | Yes  | No  | NotificationFlagStatus | Whether to enable vibration for the notification.              |


## NotificationRequest

**System capability**: SystemCapability.Notification.Notification

| Name                 | Readable| Writable| Type                                         | Description                      |
| --------------------- | ---- | --- | --------------------------------------------- | -------------------------- |
| content               | Yes | Yes | [NotificationContent](#notificationcontent)   | Notification content.                  |
| id                    | Yes | Yes | number                                        | Notification ID.                    |
| slotType              | Yes | Yes | [SlotType](#slottype)                         | Slot type.                  |
| isOngoing             | Yes | Yes | boolean                                       | Whether the notification is an ongoing notification.            |
| isUnremovable         | Yes | Yes | boolean                                       | Whether the notification can be removed.                |
| deliveryTime          | Yes | Yes | number                                        | Time when the notification is sent.              |
| tapDismissed          | Yes | Yes | boolean                                       | Whether the notification is automatically cleared.          |
| autoDeletedTime       | Yes | Yes | number                                        | Time when the notification is automatically cleared.            |
| wantAgent             | Yes | Yes | WantAgent                                     | **WantAgent** instance to which the notification will be redirected after being clicked.       |
| extraInfo             | Yes | Yes | {[key: string]: any}                          | Extended parameters.                  |
| color                 | Yes | Yes | number                                        | Background color of the notification.              |
| colorEnabled          | Yes | Yes | boolean                                       | Whether the notification background color is enabled.      |
| isAlertOnce           | Yes | Yes | boolean                                       | Whether the notification triggers an alert only once.|
| isStopwatch           | Yes | Yes | boolean                                       | Whether to display the stopwatch.          |
| isCountDown           | Yes | Yes | boolean                                       | Whether to display the countdown time.        |
| isFloatingIcon        | Yes | Yes | boolean                                       | Whether the notification is displayed as a floating icon.        |
| label                 | Yes | Yes | string                                        | Notification label.                  |
| badgeIconStyle        | Yes | Yes | number                                        | Notification badge type.              |
| showDeliveryTime      | Yes | Yes | boolean                                       | Whether to display the time when the notification is delivered.          |
| actionButtons         | Yes | Yes | Array\<[NotificationActionButton](#notificationactionbutton)\>             | Buttons in the notification. Up to two buttons are allowed.    |
| smallIcon             | Yes | Yes | PixelMap                                      | Small notification icon.                |
| largeIcon             | Yes | Yes | PixelMap                                      | Large notification icon.                |
| creatorBundleName     | Yes | No | string                                        | Name of the bundle that creates the notification.            |
| creatorUid            | Yes | No | number                                        | UID used for creating the notification.             |
| creatorPid            | Yes | No | number                                        | PID used for creating the notification.             |
| creatorUserId<sup>8+</sup>| Yes | No | number                                    | ID of the user who creates the notification.          |
| hashCode              | Yes | No | string                                        | Unique ID of the notification.              |
| classification        | Yes | Yes | string                                        | Notification category.<br>**System API**: This is a system API and cannot be called by third-party applications.                  |
| groupName<sup>8+</sup>| Yes | Yes | string                                        | Group notification name.                |
| template<sup>8+</sup> | Yes | Yes | [NotificationTemplate](#notificationtemplate8) | Notification template.                  |
| isRemoveAllowed<sup>8+</sup> | Yes | No | boolean                                | Whether the notification can be removed.<br>**System API**: This is a system API and cannot be called by third-party applications.                  |
| source<sup>8+</sup>   | Yes | No | number                                        | Notification source.<br>**System API**: This is a system API and cannot be called by third-party applications.                  |
| distributedOption<sup>8+</sup>   | Yes | Yes | [DistributedOptions](#distributedoptions8)                 | Option of distributed notification.         |
| deviceId<sup>8+</sup> | Yes | No | string                                        | Device ID of the notification source.<br>**System API**: This is a system API and cannot be called by third-party applications.         |
| notificationFlags<sup>8+</sup> | Yes | No | [NotificationFlags](#notificationflags8)                    | Notification flags.         |
| removalWantAgent<sup>9+</sup> | Yes | Yes | WantAgent                    | **WantAgent** instance to which the notification will be redirected when it is removed.         |
| badgeNumber<sup>9+</sup> | Yes | Yes | number                    | Number of notifications displayed on the application icon.         |


## DistributedOptions<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

| Name                  | Readable| Writable| Type           | Description                              |
| ---------------------- | ---- | ---- | -------------- | ---------------------------------- |
| isDistributed          | Yes  | Yes  | boolean        | Whether the notification is a distributed notification.                 |
| supportDisplayDevices  | Yes  | Yes  | Array\<string> | Types of the devices to which the notification can be synchronized.          |
| supportOperateDevices  | Yes  | Yes  | Array\<string> | Devices on which notification can be enabled.               |
| remindType             | Yes  | No  | number         | Notification reminder type.<br>**System API**: This is a system API and cannot be called by third-party applications.                   |


## NotificationSlot

**System capability**: SystemCapability.Notification.Notification

| Name                | Readable| Writable| Type                 | Description                                      |
| -------------------- | ---- | --- | --------------------- | ------------------------------------------ |
| type                 | Yes | Yes | [SlotType](#slottype) | Slot type.                                  |
| level                | Yes | Yes | number                | Notification level. If this parameter is not set, the default value is used based on the notification slot type.|
| desc                 | Yes | Yes | string                | Notification slot description.                          |
| badgeFlag            | Yes | Yes | boolean               | Whether to display the badge.                              |
| bypassDnd            | Yes | Yes | boolean               | Whether to bypass the DND mode in the system.              |
| lockscreenVisibility | Yes | Yes | number                | Mode for displaying the notification on the lock screen.                |
| vibrationEnabled     | Yes | Yes | boolean               | Whether vibration is supported for the notification.                                |
| sound                | Yes | Yes | string                | Notification alert tone.                                |
| lightEnabled         | Yes | Yes | boolean               | Whether the indicator blinks for the notification.                                  |
| lightColor           | Yes | Yes | number                | Indicator color of the notification.                                |
| vibrationValues      | Yes | Yes | Array\<number\>       | Vibration mode of the notification.                              |
| enabled<sup>9+</sup> | Yes | No | boolean               | Enabled status of the notification slot.                     |


## NotificationSorting

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name    | Readable| Writable| Type                                 | Description        |
| -------- | ---- | --- | ------------------------------------- | ------------ |
| slot     | Yes | No | [NotificationSlot](#notificationslot) | Notification slot content.|
| hashCode | Yes | No | string                                | Unique ID of the notification.|
| ranking  | Yes | No | number                                | Notification sequence number.|


## NotificationSortingMap

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name          | Readable| Writable| Type                                                        | Description            |
| -------------- | ---- | --- | ------------------------------------------------------------ | ---------------- |
| sortings       | Yes | No | {[key: string]: [NotificationSorting](#notificationsorting)} | Array of notification sorting information.|
| sortedHashCode | Yes | No | Array\<string\>                                              | Array of unique notification IDs.|


## NotificationSubscribeInfo

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name       | Readable| Writable| Type           | Description                           |
| ----------- | --- | ---- | --------------- | ------------------------------- |
| bundleNames | Yes | Yes | Array\<string\> | Bundle names of the applications whose notifications are to be subscribed to.|
| userId      | Yes | Yes | number          | User whose notifications are to be subscribed to.   |


## NotificationTemplate<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

| Name| Type              | Readable| Writable| Description      |
| ---- | ---------------------- | ---- | ---- | ---------- |
| name | string                 | Yes  | Yes  | Template name.|
| data | {[key:string]: Object} | Yes  | Yes  | Template data.|


## NotificationUserInput<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

| Name    | Readable| Writable| Type  | Description                         |
| -------- | --- | ---- | ------ | ----------------------------- |
| inputKey | Yes | Yes | string | Key to identify the user input.|


## DeviceRemindType<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name                | Value | Description                              |
| -------------------- | --- | --------------------------------- |
| IDLE_DONOT_REMIND    | 0   | The device is not in use. No notification is required.           |
| IDLE_REMIND          | 1   | The device is not in use.                |
| ACTIVE_DONOT_REMIND  | 2   | The device is in use. No notification is required.           |
| ACTIVE_REMIND        | 3   | The device is in use.                |


## SourceType<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name                | Value | Description                 |
| -------------------- | --- | -------------------- |
| TYPE_NORMAL          | 0   | Normal notification.           |
| TYPE_CONTINUOUS      | 1   | Continuous notification.           |
| TYPE_TIMER           | 2   | Timed notification.           |

## RemoveReason<sup>9+</sup>

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name                | Value | Description                 |
| -------------------- | --- | -------------------- |
| CLICK_REASON_REMOVE  | 1   | The notification is removed due to a click on it.   |
| CANCEL_REASON_REMOVE | 2   | The notification is removed by the user.        |
