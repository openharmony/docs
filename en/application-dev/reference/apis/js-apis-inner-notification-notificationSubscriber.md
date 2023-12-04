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

```ts
import Base from '@ohos.base';

let subscribeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("subscribeCallback");
  }
};

let onConsumeCallback = (data: notificationSubscribe.SubscribeCallbackData) => {
  console.info('===> onConsume in test');
  let req = data.request;
  console.info('===> onConsume callback req.id:' + req.id);
};

let subscriber: notificationSubscribe.NotificationSubscriber = {
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

```ts
import Base from '@ohos.base';

let subscribeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("subscribeCallback");
  }
};

function onCancelCallback(data: notificationSubscribe.SubscribeCallbackData) {
  console.info('===> onCancel in test');
  let req = data.request;
  console.info('===> onCancel callback req.id:' + req.id);
}

let subscriber: notificationSubscribe.NotificationSubscriber = {
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

```ts
import Base from '@ohos.base';

let subscribeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("subscribeCallback");
  }
};

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onUpdate: (map) => {
    console.info('===> onUpdateCallback map:' + JSON.stringify(map));
  }
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onConnect

onConnect?:() => void

Called when the subscription is complete.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Example**

```ts
import Base from '@ohos.base';

let subscribeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("subscribeCallback");
  }
};

let onConnectCallback = () => {
  console.info('===> onConnect in test');
}

let subscriber: notificationSubscribe.NotificationSubscriber = {
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

```ts
import Base from '@ohos.base';

let subscribeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("subscribeCallback");
  }
};
let unsubscribeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.error(`unsubscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("unsubscribeCallback");
  }
};

let onConnectCallback = () => {
  console.info('===> onConnect in test');
}
let onDisconnectCallback = () => {
  console.info('===> onDisconnect in test');
}

let subscriber: notificationSubscribe.NotificationSubscriber = {
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

```ts
import Base from '@ohos.base';

let subscribeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("subscribeCallback");
  }
};

let onDestroyCallback = () => {
  console.info('===> onDestroy in test');
}

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onDestroy: onDestroyCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onDoNotDisturbDateChange<sup>8+</sup>(deprecated)

onDoNotDisturbDateChange?:(mode: notification.[DoNotDisturbDate](js-apis-notificationManager.md#donotdisturbdate)) => void

Called when the DND time settings are changed.

> **NOTE**
>
> This API is supported since API version 8 and is deprecated since API version 11. You are advised to use [onDoNotDisturbChanged](js-apis-inner-notification-notificationSubscriber.md#ondonotdisturbchanged11) instead.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| mode | notification.[DoNotDisturbDate](js-apis-notificationManager.md#donotdisturbdate) | Yes| DND time setting updates.|

**Example**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

let subscribeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("subscribeCallback");
  }
};

let onDoNotDisturbDateChangeCallback = (mode: NotificationManager.DoNotDisturbDate) => {
  console.info('===> onDoNotDisturbDateChange:' + mode);
}

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onDoNotDisturbDateChange: onDoNotDisturbDateChangeCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onDoNotDisturbChanged<sup>11+</sup>

onDoNotDisturbChanged?:(mode: notification.[DoNotDisturbDate](js-apis-notificationManager.md#donotdisturbdate)) => void

Called when the DND time settings are changed.

**System API**: This is a system API.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name| Type| Mandatory| Description|
| ------------ | ------------------------ | ---- | -------------------------- |
| mode | notification.[DoNotDisturbDate](js-apis-notificationManager.md#donotdisturbdate) | Yes| DND time setting updates.|

**Example**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

let subscribeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("subscribeCallback");
  }
};

let onDoNotDisturbChangedCallback = (mode: NotificationManager.DoNotDisturbDate) => {
  console.info('===> onDoNotDisturbChanged:' + mode);
}

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onDoNotDisturbChanged: onDoNotDisturbChangedCallback
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

### onEnabledNotificationChanged<sup>8+</sup>

onEnabledNotificationChanged?:(callbackData: [EnabledNotificationCallbackData](js-apis-notification.md#enablednotificationcallbackdata8)) => void

Listens for the notification enabled status changes.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type                                                                                                          | Mandatory| Description|
| ------------ |--------------------------------------------------------------------------------------------------------------| ---- | -------------------------- |
| callback | AsyncCallback\<[EnabledNotificationCallbackData](js-apis-notification.md#enablednotificationcallbackdata8)\> | Yes| Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let subscribeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("subscribeCallback");
  }
};

let onEnabledNotificationChangedCallback = (callbackData: notificationSubscribe.EnabledNotificationCallbackData) => {
  console.info("bundle: ", callbackData.bundle);
  console.info("uid: ", callbackData.uid);
  console.info("enable: ", callbackData.enable);
};

let subscriber: notificationSubscribe.NotificationSubscriber = {
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

```ts
import Base from '@ohos.base';

let subscribeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.error(`subscribe failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("subscribeCallback");
  }
};

let subscriber: notificationSubscribe.NotificationSubscriber = {
  onBadgeChanged: (data) => {
    console.info("bundle: ", data.bundle);
    console.info("uid: ", data.uid);
    console.info("badgeNumber: ", data.badgeNumber);
  }
};

notificationSubscribe.subscribe(subscriber, subscribeCallback);
```

## SubscribeCallbackData

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name           | Type                                                                | Readable| Writable| Description    |
| --------------- |--------------------------------------------------------------------| ---- | --- | -------- |
| request         | [NotificationRequest](js-apis-notification.md#notificationrequest) | Yes | No | Notification content.|
| sortingMap      | [NotificationSortingMap](js-apis-inner-notification-notificationSortingMap.md) | Yes | No | Notification sorting information.|
| reason          | number                                                             | Yes | No | Reason for deletion.|
| sound           | string                                                             | Yes | No | Sound used for notification.|
| vibrationValues | Array\<number\>                                                    | Yes | No | Vibration used for notification.|


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
