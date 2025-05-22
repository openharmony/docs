# @ohos.notification (Notification) (System API)

The **Notification** module provides notification management capabilities, covering notifications, notification slots, notification subscription, notification enabled status, and notification badge status.

> **NOTE**<br>
>
> The APIs provided by this module are no longer maintained since API version 9. You are advised to use [@ohos.notificationManager](js-apis-notificationManager.md).
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [Notification](./js-apis-notification.md).


## Modules to Import

```ts
import Notification from '@ohos.notification';
```

## Notification.publish<sup>8+</sup>

publish(request: NotificationRequest, userId: number, callback: AsyncCallback\<void\>): void

Publishes a notification to a specified user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                                       | Mandatory| Description                                       |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | Yes  | Content and related configuration of the notification to publish.|
| userId   | number                                      | Yes  | User ID.                          |
| callback | AsyncCallback\<void\>                       | Yes  | Callback used to return the result.                          |

**Example**

```ts
import NotificationManager from '@ohos.notificationManager';
import Base from '@ohos.base';

// publish callback
let publishCallback = (err: Base.BusinessError) => {
  if (err) {
    console.error(`publish failed, code is ${err.code}`);
  } else {
    console.info("publish success");
  }
}
// User ID
let userId: number = 1;
// NotificationRequest object
let notificationRequest: NotificationManager.NotificationRequest = {
  id: 1,
  content: {
    contentType: Notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
    normal: {
      title: "test_title",
      text: "test_text",
      additionalText: "test_additionalText"
    }
  }
};
Notification.publish(notificationRequest, userId, publishCallback);
```

## Notification.publish<sup>8+</sup>

publish(request: NotificationRequest, userId: number): Promise\<void\>

Publishes a notification to a specified user. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    |  Type                                       | Mandatory| Description                                       |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | Yes  | Content and related configuration of the notification to publish.|
| userId   | number                                      | Yes  | User ID.                          |

**Return value**

| Type    | Description        | 
| ------- |------------|
| Promise\<void\> | Promise that returns no value.|  

**Example**

```ts
import NotificationManager from '@ohos.notificationManager';
import Base from '@ohos.base';

let notificationRequest: NotificationManager.NotificationRequest = {
  id: 1,
  content: {
    contentType: Notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
    normal: {
      title: "test_title",
      text: "test_text",
      additionalText: "test_additionalText"
    }
  }
};

let userId: number = 1;

Notification.publish(notificationRequest, userId).then(() => {
  console.info("publish success");
}).catch((err: Base.BusinessError) => {
  console.error(`publish failed, code is ${err}`);
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
| slot     | [NotificationSlot](./js-apis-notification.md#notificationslot)       | Yes  | Notification slot to add.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import NotificationManager from '@ohos.notificationManager';
import Base from '@ohos.base';

// addSlot callback
let addSlotCallBack = (err: Base.BusinessError) => {
  if (err) {
    console.info("addSlot failed " + JSON.stringify(err));
  } else {
    console.info("addSlot success");
  }
}
// NotificationSlot object
let notificationSlot: NotificationManager.NotificationSlot = {
  type: Notification.SlotType.SOCIAL_COMMUNICATION
};
Notification.addSlot(notificationSlot, addSlotCallBack);
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
| slot | [NotificationSlot](./js-apis-notification.md#notificationslot) | Yes  | Notification slot to add.|

**Return value**

| Type    | Description        | 
| ------- |------------|
| Promise\<void\> | Promise that returns no value.|  

**Example**

```ts
import NotificationManager from '@ohos.notificationManager';
import Base from '@ohos.base';

// NotificationSlot object
let notificationSlot: NotificationManager.NotificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
};
Notification.addSlot(notificationSlot).then(() => {
	console.info("addSlot success");
}).catch((err: Base.BusinessError) => {
  console.error(`addSlot failed, code is ${err}`);
});
```

## Notification.addSlots

addSlots(slots: Array\<NotificationSlot\>, callback: AsyncCallback\<void\>): void

Adds an array of notification slots. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                     | Mandatory| Description                    |
| -------- | ------------------------- | ---- | ------------------------ |
| slots    | Array\<[NotificationSlot](./js-apis-notification.md#notificationslot)\> | Yes  | Notification slots to add.|
| callback | AsyncCallback\<void\>     | Yes  | Callback used to return the result.    |

**Example**

```ts
import NotificationManager from '@ohos.notificationManager';
import Base from '@ohos.base';

// addSlots callback
let addSlotsCallBack = (err: Base.BusinessError) => {
  if (err) {
    console.info("addSlots failed " + JSON.stringify(err));
  } else {
    console.info("addSlots success");
  }
}
// NotificationSlot object
let notificationSlot: NotificationManager.NotificationSlot = {
  type: Notification.SlotType.SOCIAL_COMMUNICATION
};
// NotificationSlotArray object
let notificationSlotArray: NotificationManager.NotificationSlot[] = new Array();
notificationSlotArray[0] = notificationSlot;

Notification.addSlots(notificationSlotArray, addSlotsCallBack);
```

## Notification.addSlots

addSlots(slots: Array\<NotificationSlot\>): Promise\<void\>

Adds an array of notification slots. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name | Type                     | Mandatory| Description                    |
| ----- | ------------------------- | ---- | ------------------------ |
| slots | Array\<[NotificationSlot](./js-apis-notification.md#notificationslot)\> | Yes  | Notification slots to add.|

**Return value**

| Type    | Description        | 
| ------- |------------|
| Promise\<void\> | Promise that returns no value.|  

**Example**

```ts
import NotificationManager from '@ohos.notificationManager';
import Base from '@ohos.base';

// NotificationSlot object
let notificationSlot: NotificationManager.NotificationSlot = {
  type: Notification.SlotType.SOCIAL_COMMUNICATION
};
// NotificationSlotArray object
let notificationSlotArray: NotificationManager.NotificationSlot[] = new Array();
notificationSlotArray[0] = notificationSlot;

Notification.addSlots(notificationSlotArray).then(() => {
  console.info("addSlots success");
}).catch((err: Base.BusinessError) => {
  console.error(`addSlot failed, code is ${err}`);
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
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md#notificationsubscriber)    | Yes  | Notification subscriber.    |
| info       | [NotificationSubscribeInfo](js-apis-inner-notification-notificationSubscribeInfo-sys.md#notificationsubscribeinfo) | Yes  | Notification subscription information.|
| callback   | AsyncCallback\<void\>     | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';
import NotificationSubscribe from '@ohos.notificationSubscribe';

// subscribe callback
let subscribeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("subscribe failed " + JSON.stringify(err));
  } else {
    console.info("subscribe success");
  }
}
let onConsumeCallback = (data: NotificationSubscribe.SubscribeCallbackData) => {
  console.info("Consume callback: " + JSON.stringify(data));
}
let subscriber: NotificationSubscribe.NotificationSubscriber = {
  onConsume: onConsumeCallback
};
let info: NotificationSubscribe.NotificationSubscribeInfo = {
  bundleNames: ["bundleName1", "bundleName2"]
};
Notification.subscribe(subscriber, info, subscribeCallback);
```

## Notification.subscribe

subscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>): void

Subscribes to notifications of all applications under this user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name      | Type                  | Mandatory| Description            |
| ---------- | ---------------------- | ---- | ---------------- |
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md#notificationsubscriber) | Yes  | Notification subscriber.    |
| callback   | AsyncCallback\<void\>  | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';
import NotificationSubscribe from '@ohos.notificationSubscribe';

let subscribeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("subscribe failed " + JSON.stringify(err));
  } else {
    console.info("subscribe success");
  }
}
function onConsumeCallback(data: NotificationSubscribe.SubscribeCallbackData) {
  console.info("Consume callback: " + JSON.stringify(data));
}
let subscriber: NotificationSubscribe.NotificationSubscriber = {
  onConsume: onConsumeCallback
};
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
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md#notificationsubscriber)    | Yes  | Notification subscriber.|
| info       | [NotificationSubscribeInfo](js-apis-inner-notification-notificationSubscribeInfo-sys.md#notificationsubscribeinfo) | No  | Notification subscription information. This parameter is left empty by default.  |

**Return value**

| Type    | Description        | 
| ------- |------------|
| Promise\<void\> | Promise that returns no value.|  

**Example**

```ts
import Base from '@ohos.base';
import NotificationSubscribe from '@ohos.notificationSubscribe';

function onConsumeCallback(data: NotificationSubscribe.SubscribeCallbackData) {
  console.info("Consume callback: " + JSON.stringify(data));
}
let subscriber: NotificationSubscribe.NotificationSubscriber = {
  onConsume: onConsumeCallback
};
Notification.subscribe(subscriber).then(() => {
  console.info("subscribe success");
}).catch((err: Base.BusinessError) => {
  console.error(`subscribe failed, code is ${err}`);
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
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md#notificationsubscriber) | Yes  | Notification subscriber.        |
| callback   | AsyncCallback\<void\>  | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';
import NotificationSubscribe from '@ohos.notificationSubscribe';

let unsubscribeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("unsubscribe failed " + JSON.stringify(err));
  } else {
    console.info("unsubscribe success");
  }
}
let onDisconnectCallback = () => {
  console.info("subscribe disconnect");
}
let subscriber: NotificationSubscribe.NotificationSubscriber = {
  onDisconnect: onDisconnectCallback
};
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
| subscriber | [NotificationSubscriber](js-apis-inner-notification-notificationSubscriber-sys.md#notificationsubscriber) | Yes  | Notification subscriber.|

**Return value**

| Type    | Description        | 
| ------- |------------|
| Promise\<void\> | Promise that returns no value.|  

**Example**

```ts
import Base from '@ohos.base';
import NotificationSubscribe from '@ohos.notificationSubscribe';

function onDisconnectCallback() {
  console.info("subscribe disconnect");
}
let subscriber: NotificationSubscribe.NotificationSubscriber = {
  onDisconnect: onDisconnectCallback
};
Notification.unsubscribe(subscriber).then(() => {
  console.info("unsubscribe success");
}).catch((err: Base.BusinessError) => {
  console.error(`unsubscribe failed, code is ${err}`);
});
```

## Notification.enableNotification

enableNotification(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether to enable notification for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | Yes  | Bundle information of the application.       |
| enable   | boolean               | Yes  | Whether to enable notification.            |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let enableNotificationCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("enableNotification failed " + JSON.stringify(err));
  } else {
    console.info("enableNotification success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.enableNotification(bundle, false, enableNotificationCallback);
```

## Notification.enableNotification

enableNotification(bundle: BundleOption, enable: boolean): Promise\<void\>

Sets whether to enable notification for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|
| enable | boolean      | Yes  | Whether to enable notification.  |

**Return value**

| Type    | Description        | 
| ------- |------------|
| Promise\<void\> | Promise that returns no value.|  

**Example**

```ts
import Base from '@ohos.base';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.enableNotification(bundle, false).then(() => {
  console.info("enableNotification success");
}).catch((err: Base.BusinessError) => {
  console.error(`enableNotification failed, code is ${err}`);
});

```

## Notification.isNotificationEnabled

isNotificationEnabled(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

Checks whether notification is enabled for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name    | Type                 | Mandatory| Description                    |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | Yes  | Bundle information of the application.           |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let isNotificationEnabledCallback = (err: Base.BusinessError, data: boolean) => {
  if (err) {
    console.info("isNotificationEnabled failed " + JSON.stringify(err));
  } else {
    console.info("isNotificationEnabled success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.isNotificationEnabled(bundle, isNotificationEnabledCallback);
```

## Notification.isNotificationEnabled

isNotificationEnabled(bundle: BundleOption): Promise\<boolean\>

Checks whether notification is enabled for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|

**Return value**

| Type              | Description                                               |
| ------------------ | --------------------------------------------------- |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.isNotificationEnabled(bundle).then((data) => {
  console.info("isNotificationEnabled success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`isNotificationEnabled failed, code is ${err}`);
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

```ts
import Base from '@ohos.base';

let isNotificationEnabledCallback = (err: Base.BusinessError, data: boolean) => {
  if (err) {
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
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

Notification.isNotificationEnabled().then((data: boolean) => {
  console.info("isNotificationEnabled success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`isNotificationEnabled failed, code is ${err}`);
});
```

## Notification.displayBadge

displayBadge(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether to enable the notification badge for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | Yes  | Bundle information of the application.          |
| enable   | boolean               | Yes  | Whether to enable notification.            |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let displayBadgeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("displayBadge failed " + JSON.stringify(err));
  } else {
    console.info("displayBadge success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.displayBadge(bundle, false, displayBadgeCallback);
```

## Notification.displayBadge

displayBadge(bundle: BundleOption, enable: boolean): Promise\<void\>

Sets whether to enable the notification badge for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|
| enable | boolean      | Yes  | Whether to enable notification.  |

**Return value**

| Type    | Description        | 
| ------- |------------|
| Promise\<void\> | Promise that returns no value.|  

**Example**

```ts
import Base from '@ohos.base';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.displayBadge(bundle, false).then(() => {
  console.info("displayBadge success");
}).catch((err: Base.BusinessError) => {
  console.error(`displayBadge failed, code is ${err}`);
});
```

## Notification.isBadgeDisplayed

isBadgeDisplayed(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

Checks whether the notification badge is enabled for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                    |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | Yes  | Bundle information of the application.              |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let isBadgeDisplayedCallback = (err: Base.BusinessError, data: boolean) => {
  if (err) {
    console.info("isBadgeDisplayed failed " + JSON.stringify(err));
  } else {
    console.info("isBadgeDisplayed success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.isBadgeDisplayed(bundle, isBadgeDisplayedCallback);
```

## Notification.isBadgeDisplayed

isBadgeDisplayed(bundle: BundleOption): Promise\<boolean\>

Checks whether the notification badge is enabled for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.isBadgeDisplayed(bundle).then((data) => {
  console.info("isBadgeDisplayed success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`isBadgeDisplayed failed, code is ${err}`);
});
```

## Notification.setSlotByBundle

setSlotByBundle(bundle: BundleOption, slot: NotificationSlot, callback: AsyncCallback\<void\>): void

Sets the notification slot for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | Yes  | Bundle information of the application.          |
| slot     | [NotificationSlot](./js-apis-notification.md#notificationslot)      | Yes  | Notification slot.            |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

let setSlotByBundleCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("setSlotByBundle failed " + JSON.stringify(err));
  } else {
    console.info("setSlotByBundle success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
let notificationSlot: NotificationManager.NotificationSlot = {
  type: Notification.SlotType.SOCIAL_COMMUNICATION
};
Notification.setSlotByBundle(bundle, notificationSlot, setSlotByBundleCallback);
```

## Notification.setSlotByBundle

setSlotByBundle(bundle: BundleOption, slot: NotificationSlot): Promise\<void\>

Sets the notification slot for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|
| slot   | [NotificationSlot](./js-apis-notification.md#notificationslot) | Yes  | Notification slot.|

**Return value**

| Type    | Description        | 
| ------- |------------|
| Promise\<void\> | Promise that returns no value.|  

**Example**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
let notificationSlot: NotificationManager.NotificationSlot = {
  type: Notification.SlotType.SOCIAL_COMMUNICATION
};
Notification.setSlotByBundle(bundle, notificationSlot).then(() => {
  console.info("setSlotByBundle success");
}).catch((err: Base.BusinessError) => {
  console.error(`setSlotByBundle failed, code is ${err}`);
});
```

## Notification.getSlotsByBundle

getSlotsByBundle(bundle: BundleOption, callback: AsyncCallback\<Array\<NotificationSlot>>): void

Obtains the notification slots of a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                                    | Mandatory| Description                |
| -------- | ---------------------------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)                             | Yes  | Bundle information of the application.          |
| callback | AsyncCallback\<Array\<[NotificationSlot](./js-apis-notification.md#notificationslot)>> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

let getSlotsByBundleCallback = (err: Base.BusinessError, data: NotificationManager.NotificationSlot[]) => {
  if (err) {
    console.info("getSlotsByBundle failed " + JSON.stringify(err));
  } else {
    console.info("getSlotsByBundle success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.getSlotsByBundle(bundle, getSlotsByBundleCallback);
```

## Notification.getSlotsByBundle

getSlotsByBundle(bundle: BundleOption): Promise\<Array\<NotificationSlot>>

Obtains the notification slots of a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationSlot](./js-apis-notification.md#notificationslot)>> | Promise used to return the result.|

**Example**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.getSlotsByBundle(bundle).then((data: NotificationManager.NotificationSlot[]) => {
  console.info("getSlotsByBundle success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`getSlotsByBundle failed, code is ${err}`);
});
```

## Notification.getSlotNumByBundle

getSlotNumByBundle(bundle: BundleOption, callback: AsyncCallback\<number\>): void

Obtains the number of notification slots of a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                     | Mandatory| Description                  |
| -------- | ------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)              | Yes  | Bundle information of the application.            |
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

let getSlotNumByBundleCallback = (err: Base.BusinessError, data: number) => {
  if (err) {
    console.info("getSlotNumByBundle failed " + JSON.stringify(err));
  } else {
    console.info("getSlotNumByBundle success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.getSlotNumByBundle(bundle, getSlotNumByBundleCallback);
```

## Notification.getSlotNumByBundle

getSlotNumByBundle(bundle: BundleOption): Promise\<number\>

Obtains the number of notification slots of a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | Promise used to return the result.|

**Example**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
Notification.getSlotNumByBundle(bundle).then((data: number) => {
  console.info("getSlotNumByBundle success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`getSlotNumByBundle failed, code is ${err}`);
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
| bundle          | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)       | Yes  | Bundle information of the application.          |
| notificationKey | [NotificationKey](./js-apis-notification.md#notificationkeydeprecated) | Yes  | Notification key.            |
| reason          | [RemoveReason](#removereason-deprecated)      | Yes  | Reason for deleting a notification.        |
| callback        | AsyncCallback\<void\>               | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let removeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("remove failed " + JSON.stringify(err));
  } else {
    console.info("remove success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
let notificationKey: Notification.NotificationKey = {
  id: 0,
  label: "label",
};
let reason: Notification.RemoveReason = Notification.RemoveReason.CLICK_REASON_REMOVE;
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
| bundle          | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)    | Yes  | Bundle information of the application.|
| notificationKey | [NotificationKey](./js-apis-notification.md#notificationkeydeprecated) | Yes  | Notification key.  |
| reason          | [RemoveReason](#removereason-deprecated) | Yes  | Reason for deleting a notification.        |

**Return value**

| Type    | Description        | 
| ------- |------------|
| Promise\<void\> | Promise that returns no value.|  

**Example**

```ts
import Base from '@ohos.base';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
let notificationKey: Notification.NotificationKey = {
  id: 0,
  label: "label",
};
let reason: Notification.RemoveReason = Notification.RemoveReason.CLICK_REASON_REMOVE;
Notification.remove(bundle, notificationKey, reason).then(() => {
  console.info("remove success");
}).catch((err: Base.BusinessError) => {
  console.error(`remove failed, code is ${err}`);
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
| hashCode | string                | Yes  | Unique notification ID. It is the value of **hashCode** in the [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) object of [SubscribeCallbackData](#subscribecallbackdata) of the [onConsume](js-apis-inner-notification-notificationSubscriber-sys.md#onconsume) callback.|
| reason   | [RemoveReason](#removereason-deprecated) | Yes  | Reason for deleting a notification.        |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let hashCode: string = 'hashCode';

let removeCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("remove failed " + JSON.stringify(err));
  } else {
    console.info("remove success");
  }
}
let reason: Notification.RemoveReason = Notification.RemoveReason.CANCEL_REASON_REMOVE;
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
| reason   | [RemoveReason](#removereason-deprecated) | Yes  | Reason for deleting a notification.        |

**Return value**

| Type    | Description        | 
| ------- |------------|
| Promise\<void\> | Promise that returns no value.|  

**Example**

```ts
import Base from '@ohos.base';

let hashCode: string = 'hashCode';
let reason: Notification.RemoveReason = Notification.RemoveReason.CLICK_REASON_REMOVE;
Notification.remove(hashCode, reason).then(() => {
  console.info("remove success");
}).catch((err: Base.BusinessError) => {
  console.error(`remove failed, code is ${err}`);
});
```

## Notification.removeAll

removeAll(bundle: BundleOption, callback: AsyncCallback\<void\>): void

Removes all notifications for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name    | Type                 | Mandatory| Description                        |
| -------- | --------------------- | ---- | ---------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | Yes  | Bundle information of the application.                  |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let removeAllCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("removeAll failed " + JSON.stringify(err));
  } else {
    console.info("removeAll success");
  }
}
let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};
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

```ts
import Base from '@ohos.base';

let removeAllCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("removeAll failed " + JSON.stringify(err));
  } else {
    console.info("removeAll success");
  }
}

Notification.removeAll(removeAllCallback);
```

## Notification.removeAll

removeAll(bundle?: BundleOption): Promise\<void\>

Removes all notifications for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | No  | Bundle information of the application. By default, this parameter is left empty, indicating that all notifications will be removed.|

**Return value**

| Type    | Description        | 
| ------- |------------|
| Promise\<void\> | Promise that returns no value.|  

**Example**

```ts
import Base from '@ohos.base';

// If no application is specified, notifications of all applications are deleted.
Notification.removeAll().then(() => {
  console.info("removeAll success");
}).catch((err: Base.BusinessError) => {
  console.error(`removeAll failed, code is ${err}`);
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
| userId | number | Yes  | User ID.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

function removeAllCallback(err: Base.BusinessError) {
  if (err) {
    console.info("removeAll failed " + JSON.stringify(err));
  } else {
    console.info("removeAll success");
  }
}

let userId: number = 1;
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
| userId | number | Yes  | User ID.|

**Example**

```ts
import Base from '@ohos.base';

let userId: number = 1;
Notification.removeAll(userId).then(() => {
  console.info("removeAll success");
}).catch((err: Base.BusinessError) => {
  console.error(`removeAll failed, code is ${err}`);
});
```


## Notification.getAllActiveNotifications

getAllActiveNotifications(callback: AsyncCallback\<Array\<NotificationRequest>>): void

Obtains all active notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                                                        | Mandatory| Description                |
| -------- | ------------------------------------------------------------ | ---- | -------------------- |
| callback | AsyncCallback\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)>> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

function getAllActiveNotificationsCallback(err: Base.BusinessError, data: NotificationManager.NotificationRequest[]) {
  if (err) {
    console.info("getAllActiveNotifications failed " + JSON.stringify(err));
  } else {
    console.info("getAllActiveNotifications success");
  }
}

Notification.getAllActiveNotifications(getAllActiveNotificationsCallback);
```

## Notification.getAllActiveNotifications

getAllActiveNotifications(): Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)>>

Obtains all active notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)>> | Promise used to return the result.|

**Example**

```ts
import Base from '@ohos.base';
import NotificationManager from '@ohos.notificationManager';

Notification.getAllActiveNotifications().then((data: NotificationManager.NotificationRequest[]) => {
  console.info("getAllActiveNotifications success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`getAllActiveNotifications failed, code is ${err}`);
});
```

## Notification.removeGroupByBundle<sup>8+</sup>

removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void\>): void

Removes notifications under a notification group of a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type                 | Mandatory| Description                        |
| --------- | --------------------- | ---- | ---------------------------- |
| bundle    | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | Yes  | Bundle information of the application.                  |
| groupName | string                | Yes  | Name of the notification group.              |
| callback  | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let removeGroupByBundleCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("removeGroupByBundle failed " + JSON.stringify(err));
  } else {
    console.info("removeGroupByBundle success");
  }
}

let bundleOption: Notification.BundleOption = {bundle: "Bundle"};
let groupName: string = "GroupName";

Notification.removeGroupByBundle(bundleOption, groupName, removeGroupByBundleCallback);
```

## Notification.removeGroupByBundle<sup>8+</sup>

removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void\>

Removes notifications under a notification group of a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type        | Mandatory| Description          |
| --------- | ------------ | ---- | -------------- |
| bundle    | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.    |
| groupName | string       | Yes  | Name of the notification group.|

**Return value**

| Type    | Description        | 
| ------- |------------|
| Promise\<void\> | Promise that returns no value.|  

**Example**

```ts
import Base from '@ohos.base';

let bundleOption: Notification.BundleOption = {bundle: "Bundle"};
let groupName: string = "GroupName";
Notification.removeGroupByBundle(bundleOption, groupName).then(() => {
  console.info("removeGroupByBundle success");
}).catch((err: Base.BusinessError) => {
  console.error(`removeGroupByBundle failed, code is ${err}`);
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
| date     | [DoNotDisturbDate](#donotdisturbdate8-deprecated)      | Yes  | DND time to set.        |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let setDoNotDisturbDateCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("setDoNotDisturbDate failed " + JSON.stringify(err));
  } else {
    console.info("setDoNotDisturbDate success");
  }
}

let doNotDisturbDate: Notification.DoNotDisturbDate = {
  type: Notification.DoNotDisturbType.TYPE_ONCE,
  begin: new Date(),
  end: new Date(2021, 11, 15, 18, 0)
};

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
| date | [DoNotDisturbDate](#donotdisturbdate8-deprecated) | Yes  | DND time to set.|

**Return value**

| Type    | Description        | 
| ------- |------------|
| Promise\<void\> | Promise that returns no value.|  

**Example**

```ts
import Base from '@ohos.base';

let doNotDisturbDate: Notification.DoNotDisturbDate = {
    type: Notification.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
};
Notification.setDoNotDisturbDate(doNotDisturbDate).then(() => {
	console.info("setDoNotDisturbDate success");
}).catch((err: Base.BusinessError) => {
  console.error(`setDoNotDisturbDate failed, code is ${err}`);
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
| date     | [DoNotDisturbDate](#donotdisturbdate8-deprecated)      | Yes  | DND time to set.        |
| userId   | number                | Yes  | ID of the user for whom you want to set the DND time.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let setDoNotDisturbDateCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("setDoNotDisturbDate failed " + JSON.stringify(err));
  } else {
    console.info("setDoNotDisturbDate success");
  }
}

let doNotDisturbDate: Notification.DoNotDisturbDate = {
  type: Notification.DoNotDisturbType.TYPE_ONCE,
  begin: new Date(),
  end: new Date(2021, 11, 15, 18, 0)
};

let userId: number = 1;
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
| date   | [DoNotDisturbDate](#donotdisturbdate8-deprecated) | Yes  | DND time to set.|
| userId | number           | Yes  | ID of the user for whom you want to set the DND time.|

**Return value**

| Type    | Description        | 
| ------- |------------|
| Promise\<void\> | Promise that returns no value.|  

**Example**

```ts
import Base from '@ohos.base';

let doNotDisturbDate: Notification.DoNotDisturbDate = {
  type: Notification.DoNotDisturbType.TYPE_ONCE,
  begin: new Date(),
  end: new Date(2021, 11, 15, 18, 0)
};

let userId: number = 1;

Notification.setDoNotDisturbDate(doNotDisturbDate, userId).then(() => {
  console.info("setDoNotDisturbDate success");
}).catch((err: Base.BusinessError) => {
  console.error(`setDoNotDisturbDate failed, code is ${err}`);
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
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate8-deprecated)\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let getDoNotDisturbDateCallback = (err: Base.BusinessError, data: Notification.DoNotDisturbDate) => {
  if (err) {
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

| Type                                             | Description                                     |
| ------------------------------------------------- | ----------------------------------------- |
| Promise\<[DoNotDisturbDate](#donotdisturbdate8-deprecated)\> | Promise used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

Notification.getDoNotDisturbDate().then((data: Notification.DoNotDisturbDate) => {
  console.info("getDoNotDisturbDate success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`getDoNotDisturbDate failed, code is ${err}`);
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
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate8-deprecated)\> | Yes  | Callback used to return the result.|
| userId   | number                            | Yes  | User ID.|

**Example**

```ts
import Base from '@ohos.base';

let getDoNotDisturbDateCallback = (err: Base.BusinessError, data: Notification.DoNotDisturbDate) => {
  if (err) {
    console.info("getDoNotDisturbDate failed " + JSON.stringify(err));
  } else {
    console.info("getDoNotDisturbDate success");
  }
}

let userId: number = 1;

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

| Type                                             | Description                                     |
| ------------------------------------------------- | ----------------------------------------- |
| Promise\<[DoNotDisturbDate](#donotdisturbdate8-deprecated)\> | Promise used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let userId: number = 1;

Notification.getDoNotDisturbDate(userId).then((data: Notification.DoNotDisturbDate) => {
  console.info("getDoNotDisturbDate success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`getDoNotDisturbDate failed, code is ${err}`);
});
```


## Notification.supportDoNotDisturbMode<sup>8+</sup>

supportDoNotDisturbMode(callback: AsyncCallback\<boolean\>): void

Checks whether DND mode is supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                    | Mandatory| Description                            |
| -------- | ------------------------ | ---- | -------------------------------- |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let supportDoNotDisturbModeCallback = (err: Base.BusinessError, data: boolean) => {
  if (err) {
    console.info("supportDoNotDisturbMode failed " + JSON.stringify(err));
  } else {
    console.info("supportDoNotDisturbMode success");
  }
}

Notification.supportDoNotDisturbMode(supportDoNotDisturbModeCallback);
```

## Notification.supportDoNotDisturbMode<sup>8+</sup>

supportDoNotDisturbMode(): Promise\<boolean\>

Checks whether DND mode is supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

Notification.supportDoNotDisturbMode().then((data: boolean) => {
  console.info("supportDoNotDisturbMode success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`supportDoNotDisturbMode failed, code is ${err}`);
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
| enable   | boolean                  | Yes  | Whether the device supports distributed notifications.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let enabledNotificationCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("enableDistributed failed " + JSON.stringify(err));
  } else {
    console.info("enableDistributed success");
  }
};

let enable: boolean = true;

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
| enable   | boolean                  | Yes  | Whether the device supports distributed notifications.|

**Example**

```ts
import Base from '@ohos.base';

let enable: boolean = true;
Notification.enableDistributed(enable).then(() => {
  console.info("enableDistributed success");
}).catch((err: Base.BusinessError) => {
  console.error(`enableDistributed failed, code is ${err}`);
});
```

## Notification.enableDistributedByBundle<sup>8+</sup>

enableDistributedByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void

Sets whether a specified application supports distributed notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | Yes  | Bundle information of the application.                  |
| enable   | boolean                  | Yes  | Whether the device supports distributed notifications.                      |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let enableDistributedByBundleCallback = (err: Base.BusinessError) => {
  if (err) {
    console.info("enableDistributedByBundle failed " + JSON.stringify(err));
  } else {
    console.info("enableDistributedByBundle success");
  }
};

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};

let enable: boolean = true;

Notification.enableDistributedByBundle(bundle, enable, enableDistributedByBundleCallback);
```

## Notification.enableDistributedByBundle<sup>8+</sup>

enableDistributedByBundle(bundle: BundleOption, enable: boolean): Promise\<void>

Sets whether a specified application supports distributed notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | Yes  | Application bundle.               |
| enable   | boolean                  | Yes  | Whether the device supports distributed notifications.                 |

**Example**

```ts
import Base from '@ohos.base';

let enable: boolean = true;

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};

Notification.enableDistributedByBundle(bundle, enable).then(() => {
  console.info("enableDistributedByBundle success");
}).catch((err: Base.BusinessError) => {
  console.error(`enableDistributedByBundle failed, code is ${err}`);
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
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | Yes  | Application bundle.                    |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let isDistributedEnabledByBundleCallback = (err: Base.BusinessError, data: boolean) => {
  if (err) {
    console.info("isDistributedEnabledByBundle failed " + JSON.stringify(err));
  } else {
    console.info("isDistributedEnabledByBundle success" + JSON.stringify(data));
  }
};

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};

Notification.isDistributedEnabledByBundle(bundle, isDistributedEnabledByBundleCallback);
```

## Notification.isDistributedEnabledByBundle<sup>8+</sup>

isDistributedEnabledByBundle(bundle: BundleOption): Promise\<boolean>

Checks whether a specified application supports distributed notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | Yes  | Application bundle.               |

**Return value**

| Type              | Description                                             |
| ------------------ | ------------------------------------------------- |
| Promise\<boolean\> | Promise used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let bundle: Notification.BundleOption = {
  bundle: "bundleName1",
};

Notification.isDistributedEnabledByBundle(bundle).then((data: boolean) => {
  console.info("isDistributedEnabledByBundle success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`isDistributedEnabledByBundle failed, code is ${err}`);
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
| callback | AsyncCallback\<[DeviceRemindType](#deviceremindtype8-deprecated)\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

let getDeviceRemindTypeCallback = (err: Base.BusinessError, data: Notification.DeviceRemindType) => {
  if (err) {
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
| Promise\<[DeviceRemindType](#deviceremindtype8-deprecated)\> | Promise used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

Notification.getDeviceRemindType().then((data: Notification.DeviceRemindType) => {
  console.info("getDeviceRemindType success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
  console.error(`getDeviceRemindType failed, code is ${err}`);
});
```

## DoNotDisturbDate<sup>8+</sup> <sup>deprecated</sup>

**System capability**: SystemCapability.Notification.Notification

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [notificationManager.DoNotDisturbDate](js-apis-notificationManager-sys.md#donotdisturbdate) instead.

**System API**: This is a system API and cannot be called by third-party applications.

| Name | Type                                  | Readable| Writable| Description                  |
| ----- | -------------------------------------- | ---- | ---- | ---------------------- |
| type  | [DoNotDisturbType](./js-apis-notificationManager-sys.md#donotdisturbtype) | Yes  | Yes  | DND time type.|
| begin | Date                                   | Yes  | Yes  | DND start time.|
| end   | Date                                   | Yes  | Yes  | DND end time.|

## DoNotDisturbType<sup>8+</sup> <sup>deprecated</sup>

**System capability**: SystemCapability.Notification.Notification

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [notificationManager.DoNotDisturbType](js-apis-notificationManager-sys.md#donotdisturbtype) instead.

**System API**: This is a system API and cannot be called by third-party applications.

| Name        | Value              | Description                                      |
| ------------ | ---------------- | ------------------------------------------ |
| TYPE_NONE    | 0 | Non-DND.                          |
| TYPE_ONCE    | 1 | One-shot DND at the specified time segment (only considering the hour and minute).|
| TYPE_DAILY   | 2 | Daily DND at the specified time segment (only considering the hour and minute).|
| TYPE_CLEARLY | 3 | DND at the specified time segment (considering the year, month, day, hour, and minute).    |

## DeviceRemindType<sup>8+</sup> <sup>deprecated</sup>

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [notificationManager.DeviceRemindType](js-apis-notificationManager-sys.md#deviceremindtype) instead.

| Name                | Value | Description                              |
| -------------------- | --- | --------------------------------- |
| IDLE_DONOT_REMIND    | 0   | The device is not in use. No notification is required.           |
| IDLE_REMIND          | 1   | The device is not in use.                |
| ACTIVE_DONOT_REMIND  | 2   | The device is in use. No notification is required.           |
| ACTIVE_REMIND        | 3   | The device is in use.                |


## SourceType<sup>8+</sup> <sup>deprecated</sup>

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

> **NOTE**<br>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [notificationManager.SourceType](js-apis-notificationManager-sys.md#sourcetype) instead.

| Name                | Value | Description                 |
| -------------------- | --- | -------------------- |
| TYPE_NORMAL          | 0   | Normal notification.           |
| TYPE_CONTINUOUS      | 1   | Continuous notification.           |
| TYPE_TIMER           | 2   | Timed notification.           |

## RemoveReason <sup>deprecated</sup>

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

> **NOTE**<br>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [notificationManager.RemoveReason](js-apis-notificationSubscribe-sys.md#removereason) instead.

| Name                | Value | Description                 |
| -------------------- | --- | -------------------- |
| CLICK_REASON_REMOVE  | 1   | The notification is removed after a click on it.   |
| CANCEL_REASON_REMOVE | 2   | The notification is removed by the user.        |
