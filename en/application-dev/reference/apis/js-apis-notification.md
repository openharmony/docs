# Notification

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
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

| Name    | Readable| Writable| Type                                       | Mandatory| Description                                       |
| -------- | ---- | ---- | ------------------------------------------- | ---- | ------------------------------------------- |
| request  | Yes  | No  |[NotificationRequest](#notificationrequest) | Yes  | Notification to publish.|
| callback | Yes  | No  |AsyncCallback\<void\>                       | Yes  | Callback used to return the result.                           |

**Example**

```js
// publish callback
function publishCallback(err) {
	console.info("==========================>publishCallback=======================>");
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
	console.info("==========================>publishCallback=======================>");
});

```

## Notification.publish<sup>8+</sup>

publish(request: NotificationRequest, userId: number, callback: AsyncCallback\<void\>): void

Publishes a notification. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                                       | Mandatory| Description                                       |
| -------- | ---- | ---- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | Yes  | No  |[NotificationRequest](#notificationrequest) | Yes  | Notification to publish.|
| userId   | Yes  | No  |number                                      | Yes  | ID of the user who receives the notification.                          |
| callback | Yes  | No  |AsyncCallback\<void\>                       | Yes  | Callback used to return the result.                          |

**Example**

```js
// publish callback
function publishCallback(err) {
	console.info("==========================>publishCallback=======================>");
}
// ID of the user who receives the notification.
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

**Parameters**

| Name    | Readable| Writable| Type                                       | Mandatory| Description                                       |
| -------- | ---- | ---- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | Yes  | No  |[NotificationRequest](#notificationrequest) | Yes  | Notification to publish.|
| userId   | Yes  | No  |number                                      | Yes  | ID of the user who receives the notification.                          |

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
	console.info("==========================>publishCallback=======================>");
});
```


## Notification.cancel

cancel(id: number, label: string, callback: AsyncCallback\<void\>): void

Cancels a notification with the specified ID and label. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                |
| -------- | --- | ---- | --------------------- | ---- | -------------------- |
| id       | Yes  | No  | number                | Yes  | Notification ID.              |
| label    | Yes  | No  | string                | Yes  | Notification label.            |
| callback | Yes  | No  | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
// cancel callback
function cancelCallback(err) {
	console.info("==========================>cancelCallback=======================>");
}
Notification.cancel(0, "label", cancelCallback)
```



## Notification.cancel

cancel(id: number, label?: string): Promise\<void\>

Cancels a notification with the specified ID and label. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name | Readable| Writable| Type  | Mandatory| Description    |
| ----- | --- | ---- | ------ | ---- | -------- |
| id    | Yes  | No  | number | Yes  | Notification ID.  |
| label | Yes  | No  | string | No  | Notification label.|

**Example**

```js
Notification.cancel(0).then(() => {
	console.info("==========================>cancelCallback=======================>");
});
```



## Notification.cancel

cancel(id: number, callback: AsyncCallback\<void\>): void

Cancels a notification with the specified ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| id       | Yes  | No | number                | Yes  | Notification ID.              |
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
// cancel callback
function cancelCallback(err) {
	console.info("==========================>cancelCallback=======================>");
}
Notification.cancel(0, cancelCallback)
```



## Notification.cancelAll

cancelAll(callback: AsyncCallback\<void\>): void

Cancels all notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
// cancel callback
function cancelAllCallback(err) {
	console.info("==========================>cancelAllCallback=======================>");
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
	console.info("==========================>cancelAllCallback=======================>");
});
```



## Notification.addSlot

addSlot(slot: NotificationSlot, callback: AsyncCallback\<void\>): void

Adds a notification slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| slot     | Yes  | No | [NotificationSlot](#notificationslot)       | Yes  | Notification slot to add.|
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
// addSlot callback
function addSlotCallBack(err) {
	console.info("==========================>addSlotCallBack=======================>");
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

**Parameters**

| Name| Readable| Writable| Type            | Mandatory| Description                |
| ---- | ---- | --- | ---------------- | ---- | -------------------- |
| slot | Yes  | No | [NotificationSlot](#notificationslot) | Yes  | Notification slot to add.|

**Example**

```js
// NotificationSlot object
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
Notification.addSlot(notificationSlot).then(() => {
	console.info("==========================>addSlotCallback=======================>");
});
```



## Notification.addSlot

addSlot(type: SlotType, callback: AsyncCallback\<void\>): void

Adds a notification slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                  |
| -------- | ---- | --- | --------------------- | ---- | ---------------------- |
| type     | Yes  | No | [SlotType](#slottype)              | Yes  | Type of the notification slot to add.|
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.  |

**Example**

```js
// addSlot callback
function addSlotCallBack(err) {
	console.info("==========================>addSlotCallBack=======================>");
}
Notification.addSlot(Notification.SlotType.SOCIAL_COMMUNICATION, addSlotCallBack)
```



## Notification.addSlot

addSlot(type: SlotType): Promise\<void\>

Adds a notification slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name| Readable| Writable| Type    | Mandatory| Description                  |
| ---- | ---- | --- | -------- | ---- | ---------------------- |
| type | Yes  | No | [SlotType](#slottype) | Yes  | Type of the notification slot to add.|

**Example**

```js
Notification.addSlot(Notification.SlotType.SOCIAL_COMMUNICATION).then(() => {
	console.info("==========================>addSlotCallback=======================>");
});
```



## Notification.addSlots

addSlots(slots: Array\<NotificationSlot\>, callback: AsyncCallback\<void\>): void

Adds multiple notification slots. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                     | Mandatory| Description                    |
| -------- | ---- | --- | ------------------------- | ---- | ------------------------ |
| slots    | Yes  | No | Array\<[NotificationSlot](#notificationslot)\> | Yes  | Notification slots to add.|
| callback | Yes  | No | AsyncCallback\<void\>     | Yes  | Callback used to return the result.    |

**Example**

```js
// addSlots callback
function addSlotsCallBack(err) {
	console.info("==========================>addSlotsCallBack=======================>");
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

**Parameters**

| Name | Readable| Writable| Type                     | Mandatory| Description                    |
| ----- | ---- | --- | ------------------------- | ---- | ------------------------ |
| slots | Yes  | No | Array\<[NotificationSlot](#notificationslot)\> | Yes  | Notification slots to add.|

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
	console.info("==========================>addSlotCallback=======================>");
});
```



## Notification.getSlot

getSlot(slotType: SlotType, callback: AsyncCallback\<NotificationSlot\>): void

Obtains a notification slot of the specified type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                             | Mandatory| Description                                                       |
| -------- | ---- | --- | --------------------------------- | ---- | ----------------------------------------------------------- |
| slotType | Yes  | No | [SlotType](#slottype)                          | Yes  | Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|
| callback | Yes  | No | AsyncCallback\<[NotificationSlot](#notificationslot)\> | Yes  | Callback used to return the result.                                       |

**Example**

```js
// getSlot callback
function getSlotCallback(err,data) {
	console.info("==========================>getSlotCallback=======================>");
}
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.getSlot(slotType, getSlotCallback)
```



## Notification.getSlot

getSlot(slotType: SlotType): Promise\<NotificationSlot\>

Obtains a notification slot of the specified type. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type    | Mandatory| Description                                                       |
| -------- | ---- | --- | -------- | ---- | ----------------------------------------------------------- |
| slotType | Yes  | No | [SlotType](#slottype) | Yes  | Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<NotificationSlot\> | Promise used to return the result.|

**Example**

```js
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.getSlot(slotType).then((data) => {
	console.info("==========================>getSlotCallback=======================>");
});
```



## Notification.getSlots

getSlots(callback: AsyncCallback\<Array\<NotificationSlot\>>): void

Obtains all notification slots. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                             | Mandatory| Description                |
| -------- | ---- | --- | --------------------------------- | ---- | -------------------- |
| callback | Yes  | No | AsyncCallback\<[NotificationSlot](#notificationslot)\> | Yes  | Callback used to return the result.|

**Example**

```js
// getSlots callback
function getSlotsCallback(err,data) {
	console.info("==========================>getSlotsCallback=======================>");
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
	console.info("==========================>getSlotsCallback=======================>");
});
```



## Notification.removeSlot

removeSlot(slotType: SlotType, callback: AsyncCallback\<void\>): void

Removes a notification slot of the specified type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                                                       |
| -------- | ---- | --- | --------------------- | ---- | ----------------------------------------------------------- |
| slotType | Yes  | No | [SlotType](#slottype)              | Yes  | Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.                                       |

**Example**

```js
// removeSlot callback
function removeSlotCallback(err) {
	console.info("==========================>removeSlotCallback=======================>");
}
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.removeSlot(slotType,removeSlotCallback)
```



## Notification.removeSlot

removeSlot(slotType: SlotType): Promise\<void\>

Removes a notification slot of the specified type. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type    | Mandatory| Description                                                       |
| -------- | ---- | --- | -------- | ---- | ----------------------------------------------------------- |
| slotType | Yes  | No | [SlotType](#slottype) | Yes  | Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|

**Example**

```js
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.removeSlot(slotType).then(() => {
	console.info("==========================>removeSlotCallback=======================>");
});
```



## Notification.removeAllSlots

removeAllSlots(callback: AsyncCallback\<void\>): void

Removes all notification slots. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function removeAllCallBack(err) {
	console.info("================>removeAllCallBack=======================>");
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
	console.info("==========================>removeAllCallBack=======================>");
});
```



## Notification.subscribe

subscribe(subscriber: NotificationSubscriber, info: NotificationSubscribeInfo, callback: AsyncCallback\<void\>): void

Subscribes to a notification with the subscription information specified. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name      | Readable| Writable| Type                     | Mandatory| Description            |
| ---------- | ---- | --- | ------------------------- | ---- | ---------------- |
| subscriber | Yes  | No | [NotificationSubscriber](#notificationsubscriber)    | Yes  | Notification subscriber.    |
| info       | Yes  | No | [NotificationSubscribeInfo](#notificationsubscribeinfo) | Yes  | Subscription information.        |
| callback   | Yes  | No | AsyncCallback\<void\>     | Yes  | Callback used to return the result.|

**Example**

```js
// subscribe callback
function subscribeCallback(err) {
	console.info("==========================>subscribeCallback=======================>");
}
function onConsumeCallback(err, data) {
	console.info("==========================>onConsumeCallback=======================>");
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

**Parameters**

| Name      | Readable| Writable| Type                  | Mandatory| Description            |
| ---------- | ---- | --- | ---------------------- | ---- | ---------------- |
| subscriber | Yes  | No | [NotificationSubscriber](#notificationsubscriber) | Yes  | Notification subscriber.    |
| callback   | Yes  | No | AsyncCallback\<void\>  | Yes  | Callback used to return the result.|

**Example**

```js
function subscribeCallback(err) {
	console.info("==========================>subscribeCallback=======================>");
}
function onConsumeCallback(err, data) {
	console.info("==========================>onConsumeCallback=======================>");
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

**Parameters**

| Name      | Readable| Writable| Type                     | Mandatory| Description        |
| ---------- | ---- | --- | ------------------------- | ---- | ------------ |
| subscriber | Yes  | No | [NotificationSubscriber](#notificationsubscriber)    | Yes  | Notification subscriber.|
| info       | Yes  | No | [NotificationSubscribeInfo](#notificationsubscribeinfo) | No  | Subscription information.    |

**Example**

```js
function onConsumeCallback(err, data) {
	console.info("==========================>onConsumeCallback=======================>");
}
var subscriber = {
    onConsume: onConsumeCallback
};
Notification.subscribe(subscriber).then(() => {
	console.info("==========================>subscribeCallback=======================>");
});
```



## Notification.unsubscribe

unsubscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>): void

Unsubscribes from a notification. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name      | Readable| Writable| Type                  | Mandatory| Description                |
| ---------- | ---- | --- | ---------------------- | ---- | -------------------- |
| subscriber | Yes  | No | [NotificationSubscriber](#notificationsubscriber) | Yes  | Notification subscriber.        |
| callback   | Yes  | No | AsyncCallback\<void\>  | Yes  | Callback used to return the result.|

**Example**

```js
function unsubscribeCallback(err) {
	console.info("==========================>unsubscribeCallback=======================>");
}
function onConsumeCallback(err, data) {
	console.info("==========================>onConsumeCallback=======================>");
}
var subscriber = {
    onConsume: onConsumeCallback
}
Notification.unsubscribe(subscriber, unsubscribeCallback);
```



## Notification.unsubscribe

unsubscribe(subscriber: NotificationSubscriber): Promise\<void\>

Unsubscribes from a notification. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name      | Readable| Writable| Type                  | Mandatory| Description        |
| ---------- | ---- | --- | ---------------------- | ---- | ------------ |
| subscriber | Yes  | No | [NotificationSubscriber](#notificationsubscriber) | Yes  | Notification subscriber.|

**Example**

```js
function onConsumeCallback(err, data) {
	console.info("==========================>onConsumeCallback=======================>");
}
var subscriber = {
    onConsume: onConsumeCallback
};
Notification.unsubscribe(subscriber).then(() => {
	console.info("==========================>unsubscribeCallback=======================>");
});
```



## Notification.enableNotification

enableNotification(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether to enable notification for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| bundle   | Yes  | No | [BundleOption](#bundleoption)          | Yes  | Bundle information.          |
| enable   | Yes  | No | boolean               | Yes  | Whether to enable notification.            |
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function enableNotificationCallback(err) {
	console.info("==========================>enableNotificationCallback=======================>");
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

**Parameters**

| Name  | Readable| Writable| Type        | Mandatory| Description      |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | Yes  | No | [BundleOption](#bundleoption) | Yes  | Bundle information.|
| enable | Yes  | No | boolean      | Yes  | Whether to enable notification.  |

**Example**

```js
var bundle = {
    bundle: "bundleName1",
}
Notification.enableNotification(bundle, false).then(() => {
	console.info("==========================>enableNotificationCallback=======================>");
});
```



## Notification.isNotificationEnabled

isNotificationEnabled(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

Checks whether notification is enabled for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                    |
| -------- | ---- | --- | --------------------- | ---- | ------------------------ |
| bundle   | Yes  | No | [BundleOption](#bundleoption)          | Yes  | Bundle information.              |
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function isNotificationEnabledCallback(err, data) {
	console.info("==========================>isNotificationEnabledCallback=======================>");
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

**Parameters**

| Name  | Readable| Writable| Type        | Mandatory| Description      |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | Yes  | No | [BundleOption](#bundleoption) | Yes  | Bundle information.|

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
	console.info("==========================>isNotificationEnabledCallback=======================>");
});
```



## Notification.isNotificationEnabled

isNotificationEnabled(callback: AsyncCallback\<boolean\>): void

Checks whether notification is enabled for this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                    |
| -------- | ---- | --- | --------------------- | ---- | ------------------------ |
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function isNotificationEnabledCallback(err, data) {
	console.info("==========================>isNotificationEnabledCallback=======================>");
}

Notification.isNotificationEnabled(isNotificationEnabledCallback);
```



## Notification.isNotificationEnabled

isNotificationEnabled(): Promise\<boolean\>

Checks whether notification is enabled for this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name  | Readable| Writable| Type        | Mandatory| Description      |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | Yes  | No | [BundleOption](#bundleoption) | Yes  | Bundle information.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

```js
Notification.isNotificationEnabled().then((data) => {
	console.info("==========================>isNotificationEnabledCallback=======================>");
});
```



## Notification.displayBadge

displayBadge(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether to enable the notification badge for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| bundle   | Yes  | No | [BundleOption](#bundleoption)          | Yes  | Bundle information.          |
| enable   | Yes  | No | boolean               | Yes  | Whether to enable notification.            |
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function displayBadgeCallback(err) {
	console.info("==========================>displayBadgeCallback=======================>");
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

**Parameters**

| Name  | Readable| Writable| Type        | Mandatory| Description      |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | Yes  | No | [BundleOption](#bundleoption) | Yes  | Bundle information.|
| enable | Yes  | No | boolean      | Yes  | Whether to enable notification.  |

**Example**

```js
var bundle = {
    bundle: "bundleName1",
}
Notification.displayBadge(bundle, false).then(() => {
	console.info("==========================>displayBadgeCallback=======================>");
});
```



## Notification.isBadgeDisplayed

isBadgeDisplayed(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

Checks whether the notification badge is enabled for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                    |
| -------- | ---- | --- | --------------------- | ---- | ------------------------ |
| bundle   | Yes  | No | [BundleOption](#bundleoption)          | Yes  | Bundle information.              |
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function isBadgeDisplayedCallback(err, data) {
	console.info("==========================>isBadgeDisplayedCallback=======================>");
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

**Parameters**

| Name  | Readable| Writable| Type        | Mandatory| Description      |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | Yes  | No | [BundleOption](#bundleoption) | Yes  | Bundle information.|

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
	console.info("==========================>isBadgeDisplayedCallback=======================>");
});
```



## Notification.setSlotByBundle

setSlotByBundle(bundle: BundleOption, slot: NotificationSlot, callback: AsyncCallback\<void\>): void

Sets the notification slot for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| bundle   | Yes  | No | [BundleOption](#bundleoption)          | Yes  | Bundle information.          |
| slot     | Yes  | No | [NotificationSlot](#notificationslot)      | Yes  | Notification slot.            |
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function setSlotByBundleCallback(err) {
	console.info("==========================>setSlotByBundleCallback=======================>");
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

**Parameters**

| Name  | Readable| Writable| Type        | Mandatory| Description      |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | Yes  | No | [BundleOption](#bundleoption) | Yes  | Bundle information.|
| slot   | Yes  | No | [NotificationSlot](#notificationslot) | Yes  | Whether to enable notification.  |

**Example**

```js
var bundle = {
    bundle: "bundleName1",
}
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
Notification.displayBadge(bundle, notificationSlot).then(() => {
	console.info("==========================>setSlotByBundleCallback=======================>");
});
```



## Notification.getSlotsByBundle

getSlotsByBundle(bundle: BundleOption, callback: AsyncCallback<Array\<NotificationSlot\>>): void

Obtains the notification slots of a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                                    | Mandatory| Description                |
| -------- | ---- | --- | ---------------------------------------- | ---- | -------------------- |
| bundle   | Yes  | No | [BundleOption](#bundleoption)                             | Yes  | Bundle information.          |
| callback | Yes  | No | AsyncCallback<Array\<[NotificationSlot](#notificationslot)\>> | Yes  | Callback used to return the result.|

**Example**

```js
function getSlotsByBundleCallback(err, data) {
	console.info("==========================>getSlotsByBundleCallback=======================>");
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

**Parameters**

| Name  | Readable| Writable| Type        | Mandatory| Description      |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | Yes  | No | [BundleOption](#bundleoption) | Yes  | Bundle information.|

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
	console.info("==========================>getSlotsByBundleCallback=======================>");
});
```



## Notification.getSlotNumByBundle

getSlotNumByBundle(bundle: BundleOption, callback: AsyncCallback\<number\>): void

Obtains the number of notification slots of a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                     | Mandatory| Description                  |
| -------- | ---- | --- | ------------------------- | ---- | ---------------------- |
| bundle   | Yes  | No | [BundleOption](#bundleoption)              | Yes  | Bundle information.            |
| callback | Yes  | No | AsyncCallback\<number\> | Yes  | Callback used to return the result.|

**Example**

```js
function getSlotNumByBundle(err, data) {
	console.info("==========================>getSlotNumByBundleCallback=======================>");
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

**Parameters**

| Name  | Readable| Writable| Type        | Mandatory| Description      |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | Yes  | No | [BundleOption](#bundleoption) | Yes  | Bundle information.|

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
	console.info("==========================>getSlotNumByBundleCallback=======================>");
});
```



## Notification.remove

remove(bundle: BundleOption, notificationKey: NotificationKey, callback: AsyncCallback\<void\>): void

Removes a notification for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name           | Readable| Writable| Type                               | Mandatory| Description                |
| --------------- | ---- | --- | ----------------------------------- | ---- | -------------------- |
| bundle          | Yes  | No | [BundleOption](#bundleoption)       | Yes  | Bundle information.          |
| notificationKey | Yes  | No | [NotificationKey](#notificationkey) | Yes  | Notification key.            |
| callback        | Yes  | No | AsyncCallback\<void\>               | Yes  | Callback used to return the result.|

**Example**

```js
function removeCallback(err) {
	console.info("==========================>removeCallback=======================>");
}
var bundle = {
    bundle: "bundleName1",
}
var notificationKey = {
    id: 0,
    label: "label",
}
Notification.remove(bundle, notificationKey, removeCallback);
```



## Notification.remove

remove(bundle: BundleOption, notificationKey: NotificationKey): Promise\<void\>

Removes a notification for a specified bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name           | Readable| Writable| Type           | Mandatory| Description      |
| --------------- | ---- | --- | --------------- | ---- | ---------- |
| bundle          | Yes  | No | [BundleOption](#bundleoption)    | Yes  | Bundle information.|
| notificationKey | Yes  | No | [NotificationKey](#notificationkey) | Yes  | Notification key.  |

**Example**

```js
var bundle = {
    bundle: "bundleName1",
}
var notificationKey = {
    id: 0,
    label: "label",
}
Notification.remove(bundle, notificationKey).then(() => {
	console.info("==========================>removeCallback=======================>");
});
```



## Notification.remove

remove(hashCode: string, callback: AsyncCallback\<void\>): void

Removes a notification for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| hashCode | Yes  | No | string                | Yes  | Unique notification ID.          |
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function removeCallback(err) {
	console.info("==========================>removeCallback=======================>");
}

Notification.remove(hashCode, removeCallback);
```



## Notification.remove

remove(hashCode: string): Promise\<void\>

Removes a notification for a specified bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type      | Mandatory| Description      |
| -------- | ---- | --- | ---------- | ---- | ---------- |
| hashCode | Yes  | No | string | Yes  | Unique notification ID.|

**Example**

```js
Notification.remove(hashCode).then(() => {
	console.info("==========================>removeCallback=======================>");
});
```



## Notification.removeAll

removeAll(bundle: BundleOption, callback: AsyncCallback\<void\>): void

Removes all notifications for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                        |
| -------- | ---- | --- | --------------------- | ---- | ---------------------------- |
| bundle   | Yes  | No | [BundleOption](#bundleoption)          | Yes  | Bundle information.                  |
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function removeAllCallback(err) {
	console.info("==========================>removeAllCallback=======================>");
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

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function removeAllCallback(err) {
	console.info("==========================>removeAllCallback=======================>");
}

Notification.removeAll(removeAllCallback);
```



## Notification.removeAll

removeAll(bundle?: BundleOption): Promise\<void\>

Removes all notifications for a specified user. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name  | Readable| Writable| Type        | Mandatory| Description      |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | Yes  | No | [BundleOption](#bundleoption) | No  | Bundle information.|

**Example**

```js
Notification.removeAll().then(() => {
	console.info("==========================>removeAllCallback=======================>");
});
```

## Notification.removeAll<sup>8+</sup>

removeAll(userId: number, callback: AsyncCallback\<void>): void

Removes all notifications for a specified user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name  | Readable| Writable| Type        | Mandatory| Description      |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| userId | Yes  | No | number | Yes  | ID of the user who receives the notification.|
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function removeAllCallback(err) {
	console.info("==========================>removeAllCallback=======================>");
}

var userId = 1

Notification.removeAll(userId, removeAllCallback);
```

## Notification.removeAll<sup>8+</sup>

removeAll(userId: number): Promise\<void>

Removes all notifications for a specified user. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name  | Readable| Writable| Type        | Mandatory| Description      |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| userId | Yes  | No | number | Yes  | ID of the user who receives the notification.|

**Example**

```js
function removeAllCallback(err) {
	console.info("==========================>removeAllCallback=======================>");
}

var userId = 1

Notification.removeAll(userId, removeAllCallback);
```


## Notification.getAllActiveNotifications

getAllActiveNotifications(callback: AsyncCallback<Array\<NotificationRequest\>>): void

Obtains all active notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                                                        | Mandatory| Description                |
| -------- | ---- | --- | ------------------------------------------------------------ | ---- | -------------------- |
| callback | Yes  | No | AsyncCallback<Array\<[NotificationRequest](#notificationrequest)\>> | Yes  | Callback used to return the result.|

**Example**

```js
function getAllActiveNotificationsCallback(err, data) {
	console.info("==========================>getAllActiveNotificationsCallback=======================>");
}

Notification.getAllActiveNotifications(getAllActiveNotificationsCallback);
```



## Notification.getAllActiveNotifications

getAllActiveNotifications(): Promise\<Array\<[NotificationRequest](#notificationrequest)\>\>

Obtains all active notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationRequest](#notificationrequest)\>\> | Promise used to return the result.|

**Example**

```js
Notification.getAllActiveNotifications().then((data) => {
	console.info("==========================>getAllActiveNotificationsCallback=======================>");
});
```



## Notification.getActiveNotificationCount

getActiveNotificationCount(callback: AsyncCallback\<number\>): void

Obtains the number of active notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                  | Mandatory| Description                  |
| -------- | ---- | --- | ---------------------- | ---- | ---------------------- |
| callback | Yes  | No | AsyncCallback\<number\> | Yes  | Callback used to return the result.|

**Example**

```js
function getActiveNotificationCountCallback(err, data) {
	console.info("==========================>getActiveNotificationCountCallback=======================>");
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
	console.info("==========================>getActiveNotificationCountCallback=======================>");
});
```



## Notification.getActiveNotifications

getActiveNotifications(callback: AsyncCallback<Array\<NotificationRequest\>>): void

Obtains active notifications of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                                                        | Mandatory| Description                          |
| -------- | ---- | --- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | Yes  | No | AsyncCallback<Array\<[NotificationRequest](#notificationrequest)\>> | Yes  | Callback used to return the result.|

**Example**

```js
function getActiveNotificationsCallback(err, data) {
	console.info("==========================>getActiveNotificationsCallback=======================>");
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
	console.info("==========================>getActiveNotificationsCallback=======================>");
});
```



## Notification.cancelGroup<sup>8+</sup>

cancelGroup(groupName: string, callback: AsyncCallback\<void\>): void

Cancels a notification group of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name     | Readable| Writable| Type                 | Mandatory| Description                        |
| --------- | ---- | --- | --------------------- | ---- | ---------------------------- |
| groupName | Yes  | No | string                | Yes  | Name of the notification group.              |
| callback  | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function cancelGroupCallback(err) {
   console.info("==========================>cancelGroupCallback=======================>");
}

var groupName = "GroupName";

Notification.cancelGroup(groupName, cancelGroupCallback);
```



## Notification.cancelGroup<sup>8+</sup>

cancelGroup(groupName: string): Promise\<void\>

Cancels a notification group of this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name     | Readable| Writable| Type  | Mandatory| Description          |
| --------- | ---- | --- | ------ | ---- | -------------- |
| groupName | Yes  | No | string | Yes  | Name of the notification group.|

**Example**

```js
var groupName = "GroupName";
Notification.cancelGroup(groupName).then(() => {
	console.info("==========================>cancelGroupPromise=======================>");
});
```



## Notification.removeGroupByBundle<sup>8+</sup>

removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void\>): void

Removes a notification group for a specified bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name     | Readable| Writable| Type                 | Mandatory| Description                        |
| --------- | ---- | --- | --------------------- | ---- | ---------------------------- |
| bundle    | Yes  | No | [BundleOption](#bundleoption)          | Yes  | Bundle information.                  |
| groupName | Yes  | No | string                | Yes  | Name of the notification group.              |
| callback  | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function removeGroupByBundleCallback(err) {
   console.info("==========================>removeGroupByBundleCallback=======================>");
}

var bundleOption = {bundle: "Bundle"};
var groupName = "GroupName";

Notification.removeGroupByBundle(bundleOption, groupName, removeGroupByBundleCallback);
```



## Notification.removeGroupByBundle<sup>8+</sup>

removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void\>

Removes a notification group for a specified bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name     | Readable| Writable| Type        | Mandatory| Description          |
| --------- | ---- | --- | ------------ | ---- | -------------- |
| bundle    | Yes  | No | [BundleOption](#bundleoption) | Yes  | Bundle information.    |
| groupName | Yes  | No | string       | Yes  | Name of the notification group.|

**Example**

```js
var bundleOption = {bundle: "Bundle"};
var groupName = "GroupName";
Notification.removeGroupByBundle(bundleOption, groupName).then(() => {
	console.info("==========================>removeGroupByBundlePromise=======================>");
});
```



## Notification.setDoNotDisturbDate<sup>8+</sup>

setDoNotDisturbDate(date: DoNotDisturbDate, callback: AsyncCallback\<void\>): void

Sets the DND time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                  |
| -------- | ---- | --- | --------------------- | ---- | ---------------------- |
| date     | Yes  | No | [DoNotDisturbDate](#donotdisturbdate8)      | Yes  | DND time to set.        |
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function setDoNotDisturbDateCallback(err) {
   console.info("==========================>setDoNotDisturbDateCallback=======================>");
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

**Parameters**

| Name| Readable| Writable| Type            | Mandatory| Description          |
| ---- | ---- | --- | ---------------- | ---- | -------------- |
| date | Yes  | No | [DoNotDisturbDate](#donotdisturbdate8) | Yes  | DND time to set.|

**Example**

```js
var doNotDisturbDate = {
    type: Notification.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
}
Notification.setDoNotDisturbDate(doNotDisturbDate).then(() => {
	console.info("==========================>setDoNotDisturbDatePromise=======================>");
});
```


## Notification.setDoNotDisturbDate<sup>8+</sup>

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number, callback: AsyncCallback\<void\>): void

Sets the DND time for a specified user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                 | Mandatory| Description                  |
| -------- | ---- | --- | --------------------- | ---- | ---------------------- |
| date     | Yes  | No | [DoNotDisturbDate](#donotdisturbdate8)      | Yes  | DND time to set.        |
| userId   | Yes  | No | number                | Yes  | User ID.|
| callback | Yes  | No | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
function setDoNotDisturbDateCallback(err) {
   console.info("==========================>setDoNotDisturbDateCallback=======================>");
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

**Parameters**

| Name  | Readable| Writable| Type            | Mandatory| Description          |
| ------ | ---- | --- | ---------------- | ---- | -------------- |
| date   | Yes  | No | [DoNotDisturbDate](#donotdisturbdate8) | Yes  | DND time to set.|
| userId | Yes  | No | number           | Yes  | User ID.|

**Example**

```js
var doNotDisturbDate = {
    type: Notification.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
}

var userId = 1

Notification.setDoNotDisturbDate(doNotDisturbDate, userId).then(() => {
	console.info("==========================>setDoNotDisturbDatePromise=======================>");
});
```


## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate\>): void

Obtains the DND time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                             | Mandatory| Description                  |
| -------- | ---- | --- | --------------------------------- | ---- | ---------------------- |
| callback | Yes  | No | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate8)\> | Yes  | Callback used to return the result.|

**Example**

```js
function getDoNotDisturbDateCallback(err,data) {
   console.info("==========================>getDoNotDisturbDateCallback=======================>");
}

Notification.getDoNotDisturbDate(getDoNotDisturbDateCallback);
```



## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(): Promise\<DoNotDisturbDate\>

Obtains the DND time. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[DoNotDisturbDate](#donotdisturbdate8)\> | Promise used to return the result.|

**Example**

```js
Notification.getDoNotDisturbDate().then((data) => {
	console.info("==========================>getDoNotDisturbDatePromise=======================>");
});
```


## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(userId: number, callback: AsyncCallback\<DoNotDisturbDate\>): void

Obtains the DND time of a specified user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                             | Mandatory| Description                  |
| -------- | ---- | --- | --------------------------------- | ---- | ---------------------- |
| callback | Yes  | No | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate8)\> | Yes  | Callback used to return the result.|
| userId   | Yes  | No | number                            | Yes  | User ID.|

**Example**

```js
function getDoNotDisturbDateCallback(err,data) {
   console.info("==========================>getDoNotDisturbDateCallback=======================>");
}

var userId = 1

Notification.getDoNotDisturbDate(userId, getDoNotDisturbDateCallback);
```



## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(userId: number): Promise\<DoNotDisturbDate\>

Obtains the DND time of a specified user. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                             | Mandatory| Description                  |
| -------- | ---- | --- | --------------------------------- | ---- | ---------------------- |
| userId   | Yes  | No | number                            | Yes  | User ID.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[DoNotDisturbDate](#donotdisturbdate8)\> | Promise used to return the result.|

**Example**

```js
var userId = 1

Notification.getDoNotDisturbDate(userId).then((data) => {
	console.info("==========================>getDoNotDisturbDatePromise=======================>");
});
```


## Notification.supportDoNotDisturbMode<sup>8+</sup>

supportDoNotDisturbMode(callback: AsyncCallback\<boolean\>): void

Checks whether the DND mode is supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Readable| Writable| Type                    | Mandatory| Description                            |
| -------- | ---- | --- | ------------------------ | ---- | -------------------------------- |
| callback | Yes  | No | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Example**

```js
function supportDoNotDisturbModeCallback(err,data) {
   console.info("==========================>supportDoNotDisturbModeCallback=======================>");
}

Notification.supportDoNotDisturbMode(supportDoNotDisturbModeCallback);
```



## Notification.supportDoNotDisturbMode<sup>8+</sup>

supportDoNotDisturbMode(): Promise\<boolean\>

Checks whether the DND mode is supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

```js
Notification.supportDoNotDisturbMode().then((data) => {
	console.info("==========================>supportDoNotDisturbModePromise=======================>");
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
    console.info("isSupportTemplateCallback");
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
    console.info("isSupportTemplateCallback");
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
function requestEnabledNotificationCallback() {
    console.log('------------- requestEnabledNotification --------------');
};

Notification.requestEnabledNotification(requestEnabledNotificationCallback);
```



## Notification.requestEnableNotification<sup>8+</sup>

requestEnableNotification(): Promise\<void\>

Requests notification to be enabled for this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Example**

```javascript
Notification.requestEnableNotification()
    .then(() => {
        console.info("requestEnableNotification ");
	});
```


## Notification.enableDistributed<sup>8+</sup>

enableDistributed(enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether this device supports distributed notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | Yes  | Whether the device supports distributed notifications.<br>**true**: The device supports distributed notifications.<br>**false**: The device does not support distributed notifications.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```javascript
function enabledNotificationCallback() {
    console.log('----------- enableDistributed ------------');
};

var enable = true

Notification.enableDistributed(enable, enabledNotificationCallback);
```



## Notification.enableDistributed<sup>8+</sup>

enableDistributed(enable: boolean): Promise\<void>

Sets whether this device supports distributed notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | Yes  | Whether the device supports distributed notifications.<br>**true**: The device supports distributed notifications.<br>**false**: The device does not support distributed notifications.|

**Example**

```javascript
var enable = true

Notification.enableDistributed(enable)
    .then(() => {
        console.log('-------- enableDistributed ----------');
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
    console.log('----------- isDistributedEnabled ------------');
};

Notification.enableDistributed(isDistributedEnabledCallback);
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
        console.log('-------- isDistributedEnabled ----------');
    });
```


## Notification.enableDistributedByBundle<sup>8+</sup>

enableDistributedByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void

Sets whether an application supports distributed notifications based on the bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](#bundleoption)             | Yes  | Application bundle.                    |
| enable   | boolean                  | Yes  | Whether the device supports distributed notifications.                      |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```javascript
function enableDistributedByBundleCallback() {
    console.log('----------- enableDistributedByBundle ------------');
};

var bundle = {
    bundle: "bundleName1",
}

var enable = true

Notification.enableDistributedByBundle(bundle, enable, enableDistributedByBundleCallback);
```



## Notification.enableDistributedByBundle<sup>8+</sup>

bundleenableDistributedByBundle(bundle: BundleOption, enable: boolean): Promise\<void>

Sets whether an application supports distributed notifications based on the bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

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
        console.log('-------- enableDistributedByBundle ----------');
    });
```

## Notification.isDistributedEnabledByBundle<sup>8+</sup>

isDistributedEnabledByBundle(bundle: BundleOption, callback: AsyncCallback\<boolean>): void

Obtains whether an application supports distributed notifications based on the bundle. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](#bundleoption)             | Yes  | Application bundle.                    |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Example**

```javascript
function isDistributedEnabledByBundleCallback(data) {
    console.log('----------- isDistributedEnabledByBundle ------------', data);
};

var bundle = {
    bundle: "bundleName1",
}

Notification.enableDistributedByBundle(bundle, isDistributedEnabledByBundleCallback);
```



## Notification.isDistributedEnabledByBundle<sup>8+</sup>

isDistributedEnabledByBundle(bundle: BundleOption): Promise\<boolean>

Obtains whether an application supports distributed notifications based on the bundle. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

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
        console.log('-------- isDistributedEnabledByBundle ----------', data);
    });
```


## Notification.getDeviceRemindType<sup>8+</sup>

getDeviceRemindType(callback: AsyncCallback\<DeviceRemindType\>): void

Obtains the notification reminder type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name  | Type                              | Mandatory| Description                      |
| -------- | --------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<[DeviceRemindType](#deviceremindtype8)\> | Yes  | Callback used to return the result.|

**Example**

```javascript
function getDeviceRemindTypeCallback(data) {
    console.log('----------- getDeviceRemindType ------------', data);
};

Notification.getDeviceRemindType(getDeviceRemindTypeCallback);
```



## Notification.getDeviceRemindType<sup>8+</sup>

getDeviceRemindType(): Promise\<DeviceRemindType\>

Obtains the notification reminder type. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Return value**

| Type              | Description           |
| ------------------ | --------------- |
| Promise\<[DeviceRemindType](#deviceremindtype8)\> | Promise used to return the result.|

**Example**

```javascript
Notification.getDeviceRemindType()
    .then((data) => {
        console.log('-------- getDeviceRemindType ----------', data);
    });
```

## NotificationSubscriber

### onConsume

onConsume?:(data: [SubscribeCallbackData](#subscribecallbackdata))

Callback for receiving notifications.

**System capability**: SystemCapability.Notification.Notification

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
            console.log('===> getWant success want:' + JSON.stringfy(data1));
        })
        .catch((err) => {
            console.error('===> getWant failed because' + JSON.stringfy(err));
        });
    console.info('===> onConsume callback req.wantAgent:' + JSON.stringfy(req.wantAgent));
};

var subscriber = {
    onConsume: onConsumeCallback
};

Notification.subscribe(subscriber, subscribeCallback);
```

### onCancel

onCancel?:(data: [SubscribeCallbackData](#subscribecallbackdata))

Callback for removing notifications.

**System capability**: SystemCapability.Notification.Notification

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

onUpdate?:(data: [NotificationSortingMap](#notificationsortingmap))

Callback for notification sorting updates.

**System capability**: SystemCapability.Notification.Notification

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

onConnect?:void

Callback for subscription.

**System capability**: SystemCapability.Notification.Notification

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

onDisconnect?:void

Callback for unsubscription.

**System capability**: SystemCapability.Notification.Notification

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

onDestroy?:void

Callback for service disconnection.

**System capability**: SystemCapability.Notification.Notification

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

onDoNotDisturbDateChange?:(mode: Notification.[DoNotDisturbDate](#donotdisturbdate8))

Callback for DND time setting updates.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| mode | Notification.[DoNotDisturbDate](#donotdisturbdate8) | Yes| DND time setting updates.|

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

onEnabledNotificationChanged?:(callbackData: [EnabledNotificationCallbackData](#enablednotificationcallbackdata8))

Listens for the notification enable status changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

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

function onEnabledNotificationChangedCallback(err, callbackData) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("bundle: ", callbackData.bundle);
        console.info("uid: ", callbackData.uid);
        console.info("enable: ", callbackData.enable);
    }
};

var subscriber = {
    onEnabledNotificationChanged: onEnabledNotificationChangedCallback
};

Notification.subscribe(subscriber, subscribeCallback);
```

## SubscribeCallbackData

**System capability**: SystemCapability.Notification.Notification

| Name           | Readable| Writable| Type                                             | Mandatory| Description    |
| --------------- | ---- | --- | ------------------------------------------------- | ---- | -------- |
| request         | Yes | No | [NotificationRequest](#notificationrequest)       | Yes  | Notification content.|
| sortingMap      | Yes | No | [NotificationSortingMap](#notificationsortingmap) | No  | Notification sorting information.|
| reason          | Yes | No | number                                            | No  | Reason for deletion.|
| sound           | Yes | No | string                                            | No  | Sound used for notification.|
| vibrationValues | Yes | No | Array\<number\>                                   | No  | Vibration used for notification.|


## EnabledNotificationCallbackData<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

| Name  | Readable| Writable| Type   | Mandatory| Description            |
| ------ | ---- | --- | ------- | ---- | ---------------- |
| bundle | Yes | No | string  | Yes  | Bundle name of the application.      |
| uid    | Yes | No | number  | Yes  | UID of the application.       |
| enable | Yes | No | boolean | Yes  | Notification enable status of the application.|


## DoNotDisturbDate<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

| Name | Readable| Writable| Type                                 | Description                    |
| ----- | ---- | --- | ------------------------------------- | ------------------------ |
| type  | Yes | No | [DoNotDisturbType](#donotdisturbtype8) | DND time type.|
| begin | Yes | No | Date                                  | DND start time.|
| end   | Yes | No | Date                                  | DND end time.|



## DoNotDisturbType<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification


| Name        | Value              | Description                                      |
| ------------ | ---------------- | ------------------------------------------ |
| TYPE_NONE    | DoNotDisturbType | Non-DND.                          |
| TYPE_ONCE    | DoNotDisturbType | One-shot DND at the specified time segment (only considering the hour and minute).|
| TYPE_DAILY   | DoNotDisturbType | Daily DND at the specified time segment (only considering the hour and minute).|
| TYPE_CLEARLY | DoNotDisturbType | DND at the specified time segment (considering the year, month, day, hour, and minute).    |


## ContentType

**System capability**: SystemCapability.Notification.Notification

| Name                             | Value         | Description              |
| --------------------------------- | ----------- | ------------------ |
| NOTIFICATION_CONTENT_BASIC_TEXT   | ContentType | Normal text notification.    |
| NOTIFICATION_CONTENT_LONG_TEXT    | ContentType | Long text notification.  |
| NOTIFICATION_CONTENT_PICTURE      | ContentType | Picture-attached notification.    |
| NOTIFICATION_CONTENT_CONVERSATION | ContentType | Conversation notification.    |
| NOTIFICATION_CONTENT_MULTILINE    | ContentType | Multi-line text notification.|

## SlotLevel

**System capability**: SystemCapability.Notification.Notification

| Name                             | Value         | Description              |
| --------------------------------- | ----------- | ------------------ |
| LEVEL_NONE                        | 0           | The notification feature is disabled.    |
| LEVEL_MIN                         | 1           | The notification feature is enabled, but the notification icon is not displayed in the status bar, with no banner or alert tone.|
| LEVEL_LOW                         | 2           | The notification feature is enabled, and the notification icon is displayed in the status bar, with no banner or alert tone.|
| LEVEL_DEFAULT                     | 3           | The notification feature is enabled, and the notification icon is displayed in the status bar, with an alert tone but no banner.|
| LEVEL_HIGH                        | 4           | The notification feature is enabled, and the notification icon is displayed in the status bar, with an alert tone and banner.|


## BundleOption

**System capability**: SystemCapability.Notification.Notification

| Name  | Readable| Writable| Type  | Mandatory| Description  |
| ------ | ---- | --- | ------ | ---- | ------ |
| bundle | Yes | Yes | string | Yes  | Bundle name.  |
| uid    | Yes | Yes | number | No  | User ID.|



## NotificationKey

**System capability**: SystemCapability.Notification.Notification

| Name | Readable| Writable| Type  | Mandatory| Description    |
| ----- | ---- | --- | ------ | ---- | -------- |
| id    | Yes | Yes | number | Yes  | Notification ID.  |
| label | Yes | Yes | string | No  | Notification label.|


## SlotType

**System capability**: SystemCapability.Notification.Notification

| Name                | Value      | Description      |
| -------------------- | -------- | ---------- |
| UNKNOWN_TYPE         | SlotType | Unknown type.|
| SOCIAL_COMMUNICATION | SlotType | Notification slot for social communication.|
| SERVICE_INFORMATION  | SlotType | Notification slot for service information.|
| CONTENT_INFORMATION  | SlotType | Notification slot for content consultation.|
| OTHER_TYPES          | SlotType | Notification slot for other purposes.|


## NotificationActionButton

**System capability**: SystemCapability.Notification.Notification

| Name     | Readable| Writable| Type                                           | Mandatory| Description                     |
| --------- | --- | ---- | ----------------------------------------------- | ---- | ------------------------- |
| title     | Yes | Yes | string                                          | Yes  | Button title.                 |
| wantAgent | Yes | Yes | WantAgent                                       | Yes  | **WantAgent** of the button.|
| extras    | Yes | Yes | { [key: string]: any }                          | No  | Extra information of the button.             |


## NotificationBasicContent

**System capability**: SystemCapability.Notification.Notification

| Name          | Readable| Writable| Type  | Mandatory| Description                              |
| -------------- | ---- | ---- | ------ | ---- | ---------------------------------- |
| title          | Yes  | Yes  | string | Yes  | Notification title.                        |
| text           | Yes  | Yes  | string | Yes  | Notification content.                        |
| additionalText | Yes  | Yes  | string | No  | Additional information of the notification.|


## NotificationLongTextContent

**System capability**: SystemCapability.Notification.Notification

| Name          | Readable| Writable| Type  | Mandatory| Description                            |
| -------------- | ---- | --- | ------ | ---- | -------------------------------- |
| title          | Yes | Yes | string | Yes  | Notification title.                        |
| text           | Yes | Yes | string | Yes  | Notification content.                        |
| additionalText | Yes | Yes | string | No  | Additional information of the notification.|
| longText       | Yes | Yes | string | Yes  | Long text of the notification.                    |
| briefText      | Yes | Yes | string | Yes  | Brief text of the notification.|
| expandedTitle  | Yes | Yes | string | Yes  | Title of the notification in the expanded state.                |


## NotificationMultiLineContent

**System capability**: SystemCapability.Notification.Notification

| Name          | Readable| Writable| Type           | Mandatory| Description                            |
| -------------- | --- | --- | --------------- | ---- | -------------------------------- |
| title          | Yes | Yes | string          | Yes  | Notification title.                        |
| text           | Yes | Yes | string          | Yes  | Notification content.                        |
| additionalText | Yes | Yes | string          | No  | Additional information of the notification.|
| briefText      | Yes | Yes | string          | Yes  | Brief text of the notification.|
| longTitle      | Yes | Yes | string          | Yes  | Title of the notification in the expanded state.                |
| lines          | Yes | Yes | Array\<string\> | Yes  | Multi-line text of the notification.                  |


## NotificationPictureContent

**System capability**: SystemCapability.Notification.Notification

| Name          | Readable| Writable| Type          | Mandatory| Description                            |
| -------------- | ---- | --- | -------------- | ---- | -------------------------------- |
| title          | Yes | Yes | string         | Yes  | Notification title.                        |
| text           | Yes | Yes | string         | Yes  | Notification content.                        |
| additionalText | Yes | Yes | string         | No  | Additional information of the notification.|
| briefText      | Yes | Yes | string         | Yes  | Brief text of the notification.|
| expandedTitle  | Yes | Yes | string         | Yes  | Title of the notification in the expanded state.                |
| picture        | Yes | Yes | image.PixelMap | Yes  | Picture attached to the notification.                  |


## NotificationContent

**System capability**: SystemCapability.Notification.Notification

| Name       | Readable| Writable| Type                                                        | Mandatory| Description              |
| ----------- | ---- | --- | ------------------------------------------------------------ | ---- | ------------------ |
| contentType | Yes | Yes | [ContentType](#contenttype)                                  | Yes  | Notification content type.      |
| normal      | Yes | Yes | [NotificationBasicContent](#notificationbasiccontent)        | No  | Normal text.  |
| longText    | Yes | Yes | [NotificationLongTextContent](#notificationlongtextcontent)  | No  | Long text.|
| multiLine   | Yes | Yes | [NotificationMultiLineContent](#notificationmultilinecontent) | No  | Multi-line text.  |
| picture     | Yes | Yes | [NotificationPictureContent](#notificationpicturecontent)    | No  | Picture-attached.  |


## NotificationFlagStatus<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

| Name          | Value | Description                              |
| -------------- | --- | --------------------------------- |
| TYPE_NONE      | 0   | The default flag is used.                        |
| TYPE_OPEN      | 1   | The notification flag is enabled.                    |
| TYPE_CLOSE     | 2   | The notification flag is disabled.                    |


## NotificationFlags<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

| Name            | Readable| Writable| Type                   | Mandatory| Description                              |
| ---------------- | ---- | ---- | ---------------------- | ---- | --------------------------------- |
| soundEnabled     | Yes  | No  | NotificationFlagStatus | No  | Whether to enable the sound alert for the notification.                 |
| vibrationEnabled | Yes  | No  | NotificationFlagStatus | No  | Whether to enable vibration for the notification.              |


## NotificationRequest

**System capability**: SystemCapability.Notification.Notification

| Name                 | Readable| Writable| Type                                         | Mandatory| Description                      |
| --------------------- | ---- | --- | --------------------------------------------- | ---- | -------------------------- |
| content               | Yes | Yes | [NotificationContent](#notificationcontent)   | Yes  | Notification content.                  |
| id                    | Yes | Yes | number                                        | No  | Notification ID.                    |
| slotType              | Yes | Yes | [SlotType](#slottype)                                      | No  | Slot type.                  |
| isOngoing             | Yes | Yes | boolean                                       | No  | Whether the notification is an ongoing notification.            |
| isUnremovable         | Yes | Yes | boolean                                       | No  | Whether the notification can be removed.                |
| deliveryTime          | Yes | Yes | number                                        | No  | Time when the notification is sent.              |
| tapDismissed          | Yes | Yes | boolean                                       | No  | Whether the notification is automatically cleared.          |
| autoDeletedTime       | Yes | Yes | number                                        | No  | Time when the notification is automatically cleared.            |
| wantAgent             | Yes | Yes | WantAgent                                     | No  | **WantAgent** instance to which the notification will be redirected after being clicked.       |
| extraInfo             | Yes | Yes | {[key: string]: any}                          | No  | Extended parameters.                  |
| color                 | Yes | Yes | number                                        | No  | Background color of the notification.              |
| colorEnabled          | Yes | Yes | boolean                                       | No  | Whether the notification background color is enabled.      |
| isAlertOnce           | Yes | Yes | boolean                                       | No  | Whether the notification triggers an alert only once.|
| isStopwatch           | Yes | Yes | boolean                                       | No  | Whether to display the stopwatch.          |
| isCountDown           | Yes | Yes | boolean                                       | No  | Whether to display the countdown time.        |
| isFloatingIcon        | Yes | Yes | boolean                                       | No  | Whether the notification is displayed as a floating icon.        |
| label                 | Yes | Yes | string                                        | No  | Notification label.                  |
| badgeIconStyle        | Yes | Yes | number                                        | No  | Notification badge type.              |
| showDeliveryTime      | Yes | Yes | boolean                                       | No  | Whether to display the time when the notification is delivered.          |
| actionButtons         | Yes | Yes | Array\<[NotificationActionButton](#notificationactionbutton)\>             | No  | Buttons in the notification. Up to two buttons are allowed.    |
| smallIcon             | Yes | Yes | PixelMap                                      | No  | Small notification icon.                |
| largeIcon             | Yes | Yes | PixelMap                                      | No  | Large notification icon.                |
| creatorBundleName     | Yes | No | string                                        | No  | Name of the bundle that creates the notification.            |
| creatorUid            | Yes | No | number                                        | No  | UID used for creating the notification.             |
| creatorPid            | Yes | No | number                                        | No  | PID used for creating the notification.             |
| creatorUserId<sup>8+</sup>| Yes | No | number                                    | No  | ID of the user who creates a notification.          |
| hashCode              | Yes | No | string                                        | No  | Unique ID of the notification.              |
| classification        | Yes | Yes | string                                        | No  | Notification category.                  |
| groupName<sup>8+</sup>| Yes | Yes | string                                        | No  | Group notification name.                |
| template<sup>8+</sup> | Yes | Yes | [NotificationTemplate](#notificationtemplate8) | No  | Notification template.                  |
| isRemoveAllowed<sup>8+</sup> | Yes | No | boolean                                | No  | Whether the notification can be removed.                  |
| source<sup>8+</sup>   | Yes | No | number                                        | No  | Notification source.                  |
| distributedOption<sup>8+</sup>   | Yes | Yes | [DistributedOptions](#distributedoptions8)                 | No  | Option of distributed notification.         |
| deviceId<sup>8+</sup> | Yes | No | string                                        | No  | Device ID of the notification source.         |
| notificationFlags<sup>8+</sup> | Yes | No | [NotificationFlags](#notificationflags8)                    | No  | Notification flags.         |


## DistributedOptions<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

| Name                  | Readable| Writable| Type           | Mandatory| Description                              |
| ---------------------- | ---- | ---- | -------------- | ---- | ---------------------------------- |
| isDistributed          | Yes  | Yes  | boolean        | No  | Whether the notification is a distributed notification.                 |
| supportDisplayDevices  | Yes  | Yes  | Array\<string> | Yes  | Types of the devices to which the notification can be synchronized.          |
| supportOperateDevices  | Yes  | Yes  | Array\<string> | No  | Devices on which notification can be enabled.               |
| remindType             | Yes  | No  | number         | No  | Notification reminder type.                   |


## NotificationSlot

**System capability**: SystemCapability.Notification.Notification

| Name                | Readable| Writable| Type                 | Mandatory| Description                                      |
| -------------------- | ---- | --- | --------------------- | ---- | ------------------------------------------ |
| type                 | Yes | Yes | [SlotType](#slottype) | Yes  | Slot type.                                  |
| level                | Yes | Yes | number                | No  | Notification level. If this parameter is not set, the default value is used based on the notification slot type.|
| desc                 | Yes | Yes | string                | No  | Notification slot description.                          |
| badgeFlag            | Yes | Yes | boolean               | No  | Whether to display the badge.                              |
| bypassDnd            | Yes | Yes | boolean               | No  | Whether to bypass the DND mode in the system.              |
| lockscreenVisibility | Yes | Yes | boolean               | No  | Mode for displaying the notification on the lock screen.                |
| vibrationEnabled     | Yes | Yes | boolean               | No  | Whether vibration is supported for the notification.                                |
| sound                | Yes | Yes | string                | No  | Notification alert tone.                                |
| lightEnabled         | Yes | Yes | boolean               | No  | Whether the indicator blinks for the notification.                                  |
| lightColor           | Yes | Yes | number                | No  | Indicator color of the notification.                                |
| vibrationValues      | Yes | Yes | Array\<number\>       | No  | Vibration mode of the notification.                              |


## NotificationSorting

**System capability**: SystemCapability.Notification.Notification

| Name    | Readable| Writable| Type                                 | Mandatory| Description        |
| -------- | ---- | --- | ------------------------------------- | ---- | ------------ |
| slot     | Yes | No | [NotificationSlot](#notificationslot) | Yes  | Notification slot content.|
| hashCode | Yes | No | string                                | Yes  | Unique ID of the notification.|
| ranking  | Yes | No | number                                | Yes  | Notification sequence number.|


## NotificationSortingMap

**System capability**: SystemCapability.Notification.Notification

| Name          | Readable| Writable| Type                                                        | Mandatory| Description            |
| -------------- | ---- | --- | ------------------------------------------------------------ | ---- | ---------------- |
| sortings       | Yes | No | {[key: string]: [NotificationSorting](#notificationsorting)} | Yes  | Array of notification sorting information.|
| sortedHashCode | Yes | No | Array\<string\>                                              | Yes  | Array of unique notification IDs.|


## NotificationSubscribeInfo

**System capability**: SystemCapability.Notification.Notification

| Name       | Readable| Writable| Type           | Mandatory| Description                           |
| ----------- | --- | ---- | --------------- | ---- | ------------------------------- |
| bundleNames | Yes | Yes | Array\<string\> | No  | Bundle names of the applications whose notifications are to be subscribed to.|
| userId      | Yes | Yes | number          | No  | User whose notifications are to be subscribed to.   |


## NotificationTemplate<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

| Name| Type              | Readable| Writable| Description      |
| ---- | ---------------------- | ---- | ---- | ---------- |
| name | string                 | Yes  | Yes  | Template name.|
| data | {[key:string]: Object} | Yes  | Yes  | Template data.|


## NotificationUserInput<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

| Name    | Readable| Writable| Type  | Mandatory| Description                         |
| -------- | --- | ---- | ------ | ---- | ----------------------------- |
| inputKey | Yes | Yes | string | Yes  | Key to identify the user input.|


## DeviceRemindType<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

| Name                | Value | Description                              |
| -------------------- | --- | --------------------------------- |
| IDLE_DONOT_REMIND    | 0   | The device is not in use. No notification is required.           |
| IDLE_REMIND          | 1   | The device is not in use.                |
| ACTIVE_DONOT_REMIND  | 2   | The device is in use. No notification is required.           |
| ACTIVE_REMIND        | 3   | The device is in use.                |
