# NotificationSubscriber

The **NotificationSubscriber** module provides callbacks for receiving or removing notifications and serves as the input parameter of [subscribe](js-apis-notificationSubscribe.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import notificationSubscribe from '@ohos.notificationSubscribe';
```

**System API**: This is a system API and cannot be called by third-party applications.

### onConsume

onConsume?: (data: [SubscribeCallbackData](js-apis-notification.md#subscribecallbackdata)) => void

Called when a new notification is received.

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

Called when notification sorting is updated.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [NotificationSortingMap](js-apis-notification.md#notificationsortingmap) | Yes| Latest notification sorting list.|

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

Called when the subscription is complete.

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

Called when the service is disconnected.

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

### onDoNotDisturbDateChange<sup>8+</sup>

onDoNotDisturbDateChange?:(mode: notification.[DoNotDisturbDate](js-apis-notificationManager.md#donotdisturbdate)) => void

Called when the DND time settings are changed.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| mode | notification.[DoNotDisturbDate](js-apis-notificationManager.md#donotdisturbdate) | Yes| DND time setting updates.|

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


### onEnabledNotificationChanged<sup>8+</sup>

onEnabledNotificationChanged?:(callbackData: [EnabledNotificationCallbackData](js-apis-notification.md#enablednotificationcallbackdata8)) => void

Listens for the notification enabled status changes.

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

## SubscribeCallbackData

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name           | Type                                             | Readable| Writable| Description    |
| --------------- | ------------------------------------------------- | ---- | --- | -------- |
| request         | [NotificationRequest](js-apis-notification.md#notificationrequest)       | Yes | No | Notification content.|
| sortingMap      | [NotificationSortingMap](js-apis-inner-notification-notificationSortingMap.md) | Yes | No | Notification sorting information.|
| reason          | number                                            | Yes | No | Reason for deletion.|
| sound           | string                                            | Yes | No | Sound used for notification.|
| vibrationValues | Array\<number\>                                   | Yes | No | Vibration used for notification.|


## EnabledNotificationCallbackData<sup>8+</sup>

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name  | Type   | Readable| Writable| Description            |
| ------ | ------- | ---- | --- | ---------------- |
| bundle | string  | Yes | No | Bundle name of the application.      |
| uid    | number  | Yes | No | UID of the application.       |
| enable | boolean | Yes | No | Notification enabled status of the application.|


## BadgeNumberCallbackData<sup>10+</sup>

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name       | Type  | Readable| Writable| Description        |
| ----------- | ------ | ---- | ---- | ------------ |
| bundle      | string | Yes  | No  | Bundle name of the application.|
| uid         | number | Yes  | No  | UID of the application. |
| badgeNumber | number | Yes  | No  | Number of notifications displayed on the application icon.  |
