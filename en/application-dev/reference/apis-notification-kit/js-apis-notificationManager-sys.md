# @ohos.notificationManager (NotificationManager) (System API)

The **NotificationManager** module provides notification management capabilities, covering notifications, notification slots, notification enabled status, and notification badge status.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [[NotificationManager](./js-apis-notificationManager.md).

## Modules to Import

```ts
import notificationManager from '@ohos.notificationManager';
```

## notificationManager.publish

publish(request: NotificationRequest, userId: number, callback: AsyncCallback\<void\>): void

Publishes a notification to a specified user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                                       | Mandatory| Description                                       |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest) | Yes  | Content and related configuration of the notification to publish.|
| userId   | number                                      | Yes  | User ID.                          |
| callback | AsyncCallback\<void\>                       | Yes  | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                             |
| -------- | ---------------------------------------------------- |
| 1600001  | Internal error.                                      |
| 1600002  | Marshalling or unmarshalling error.                  |
| 1600003  | Failed to connect service.                           |
| 1600004  | Notification is not enabled.                         |
| 1600005  | Notification slot is not enabled.                    |
| 1600007  | The notification is not exist.                       |
| 1600008  | The user does not exist.                               |
| 1600009  | Over max number notifications per second.            |
| 1600012  | No memory space.                                     |
| 1600014  | No relevant right.                                   |
| 1600015  | The current notification status does not support duplicate configurations. |
| 1600016  | The notification version for this update is too low. |
| 2300007  | Network is unreachable.                              |

**Example**

```ts
import Base from '@ohos.base';

// publish callback
let publishCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publish success");
    }
}
// User ID
let userId: number = 1;
// NotificationRequest object
let notificationRequest: notificationManager.NotificationRequest = {
    id: 1,
    content: {
        notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
};
notificationManager.publish(notificationRequest, userId, publishCallback);
```

## notificationManager.publish

publish(request: NotificationRequest, userId: number): Promise\<void\>

Publishes a notification to a specified user. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    |  Type                                       | Mandatory| Description                                       |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest) | Yes  | Content and related configuration of the notification to publish.|
| userId   | number                                      | Yes  | User ID.                          |

**Return value**

| Type    | Description       | 
| ------- |-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                             |
| -------- | ---------------------------------------------------- |
| 1600001  | Internal error.                                      |
| 1600002  | Marshalling or unmarshalling error.                  |
| 1600003  | Failed to connect service.                           |
| 1600004  | Notification is not enabled.                         |
| 1600005  | Notification slot is not enabled.                    |
| 1600007  | The notification is not exist.                       |
| 1600008  | The user does not exist.                               |
| 1600009  | Over max number notifications per second.            |
| 1600012  | No memory space.                                     |
| 1600014  | No relevant right.                                   |
| 1600015  | The current notification status does not support duplicate configurations. |
| 1600016  | The notification version for this update is too low. |
| 2300007  | Network is unreachable.                              |

**Example**

```ts
import Base from '@ohos.base';

let notificationRequest: notificationManager.NotificationRequest = {
    id: 1,
    content: {
        notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
};

let userId: number = 1;

notificationManager.publish(notificationRequest, userId).then(() => {
	console.info("publish success");
}).catch((err: Base.BusinessError) => {
    console.error(`publish fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.addSlot

addSlot(slot: NotificationSlot, callback: AsyncCallback\<void\>): void

Adds a notification slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| slot     | [NotificationSlot](js-apis-inner-notification-notificationSlot.md)       | Yes  | Notification slot to add.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**Example**

```ts
import Base from '@ohos.base';

// addSlot callback
let addSlotCallBack = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`addSlot failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("addSlot success");
    }
}
// NotificationSlot object
let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
notificationManager.addSlot(notificationSlot, addSlotCallBack);
```

## notificationManager.addSlot

addSlot(slot: NotificationSlot): Promise\<void\>

Adds a notification slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name| Type            | Mandatory| Description                |
| ---- | ---------------- | ---- | -------------------- |
| slot | [NotificationSlot](js-apis-inner-notification-notificationSlot.md) | Yes  | Notification slot to add.|

**Return value**

| Type    | Description       | 
| ------- |-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**Example**

```ts
import Base from '@ohos.base';

// NotificationSlot object
let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
notificationManager.addSlot(notificationSlot).then(() => {
	console.info("addSlot success");
}).catch((err: Base.BusinessError) => {
    console.error(`addSlot fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.addSlots

addSlots(slots: Array\<NotificationSlot\>, callback: AsyncCallback\<void\>): void

Adds an array of notification slots. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                     | Mandatory| Description                    |
| -------- | ------------------------- | ---- | ------------------------ |
| slots    | Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\> | Yes  | Notification slots to add.|
| callback | AsyncCallback\<void\>     | Yes  | Callback used to return the result.    |

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**Example**

```ts
import Base from '@ohos.base';

// addSlots callback
let addSlotsCallBack = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`addSlots failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("addSlots success");
    }
}
// NotificationSlot object
let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
// NotificationSlotArray object
let notificationSlotArray: notificationManager.NotificationSlot[] = new Array();
notificationSlotArray[0] = notificationSlot;

notificationManager.addSlots(notificationSlotArray, addSlotsCallBack);
```

## notificationManager.addSlots

addSlots(slots: Array\<NotificationSlot\>): Promise\<void\>

Adds an array of notification slots. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name | Type                     | Mandatory| Description                    |
| ----- | ------------------------- | ---- | ------------------------ |
| slots | Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\> | Yes  | Notification slots to add.|

**Return value**

| Type     | Description       | 
|---------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**Example**

```ts
import Base from '@ohos.base';

// NotificationSlot object
let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
// NotificationSlotArray object
let notificationSlotArray: notificationManager.NotificationSlot[] = new Array();
notificationSlotArray[0] = notificationSlot;

notificationManager.addSlots(notificationSlotArray).then(() => {
	console.info("addSlots success");
}).catch((err: Base.BusinessError) => {
    console.error(`addSlot fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.setNotificationEnable

setNotificationEnable(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether to enable notification for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)   | Yes  | Bundle of the application.       |
| enable   | boolean               | Yes  | Whether to enable notification.            |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let setNotificationEnableCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setNotificationEnableCallback failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setNotificationEnableCallback success");
    }
}
let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.setNotificationEnable(bundle, false, setNotificationEnableCallback);
```

## notificationManager.setNotificationEnable

setNotificationEnable(bundle: BundleOption, enable: boolean): Promise\<void\>

Sets whether to enable notification for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle of the application.|
| enable | boolean      | Yes  | Whether to enable notification.  |

**Return value**

| Type     | Description       | 
|---------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.setNotificationEnable(bundle, false).then(() => {
	console.info("setNotificationEnable success");
}).catch((err: Base.BusinessError) => {
    console.error(`setNotificationEnable fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

Checks whether notification is enabled for the specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                    |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | Yes  | Bundle of the application.           |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let isNotificationEnabledCallback = (err: Base.BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isNotificationEnabled failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`isNotificationEnabled success, data is ${JSON.stringify(data)}`);
    }
}

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};

notificationManager.isNotificationEnabled(bundle, isNotificationEnabledCallback);
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(bundle: BundleOption): Promise\<boolean\>

Checks whether notification is enabled for the specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle of the application.|

**Return value**

| Type              | Description                                               |
| ------------------ | --------------------------------------------------- |
| Promise\<boolean\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.isNotificationEnabled(bundle).then((data: boolean) => {
	console.info("isNotificationEnabled success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`isNotificationEnabled fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(userId: number, callback: AsyncCallback\<boolean\>): void

Checks whether notification is enabled for a specified user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                    |
| -------- | --------------------- | ---- | ------------------------ |
| userId   | number                | Yes  | User ID.|
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |

**Example**

```ts
import Base from '@ohos.base';

let isNotificationEnabledCallback = (err: Base.BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isNotificationEnabled failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`isNotificationEnabled success, data is ${JSON.stringify(data)}`);
    }
}

let userId: number = 1;

notificationManager.isNotificationEnabled(userId, isNotificationEnabledCallback);
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(userId: number): Promise\<boolean\>

Checks whether notification is enabled for a specified user. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| userId | number       | Yes  | User ID.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600008  | The user does not exist..                  |

**Example**

```ts
import Base from '@ohos.base';

let userId: number = 1;

notificationManager.isNotificationEnabled(userId).then((data: boolean) => {
	console.info("isNotificationEnabled success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`isNotificationEnabled fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.displayBadge

displayBadge(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether to enable the notification badge for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | Yes  | Bundle of the application.          |
| enable   | boolean               | Yes  | Whether to enable notification.            |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let displayBadgeCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`displayBadge failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("displayBadge success");
    }
}
let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.displayBadge(bundle, false, displayBadgeCallback);
```

## notificationManager.displayBadge

displayBadge(bundle: BundleOption, enable: boolean): Promise\<void\>

Sets whether to enable the notification badge for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle of the application.|
| enable | boolean      | Yes  | Whether to enable notification.  |

**Return value**

| Type     | Description       | 
|---------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.displayBadge(bundle, false).then(() => {
	console.info("displayBadge success");
}).catch((err: Base.BusinessError) => {
    console.error(`displayBadge fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.isBadgeDisplayed

isBadgeDisplayed(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

Checks whether the notification badge is enabled for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                    |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | Yes  | Bundle of the application.              |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let isBadgeDisplayedCallback = (err: Base.BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isBadgeDisplayed failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`isBadgeDisplayed success, data is ${JSON.stringify(data)}`);
    }
}
let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.isBadgeDisplayed(bundle, isBadgeDisplayedCallback);
```

## notificationManager.isBadgeDisplayed

isBadgeDisplayed(bundle: BundleOption): Promise\<boolean\>

Checks whether the notification badge is enabled for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle of the application.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
  bundle: "bundleName1",
};

notificationManager.isBadgeDisplayed(bundle).then((data: boolean) => {
	console.info("isBadgeDisplayed success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`isBadgeDisplayed fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setSlotFlagsByBundle<sup>11+</sup>

setSlotFlagsByBundle(bundle: BundleOption, slotFlags: number): Promise\<void\>

Sets the notification slot for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle of the application.|
| slotFlags   | number | Yes  | Notification slot flags.|

**Return value**

| Type     | Description       | 
|---------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};

let slotFlags: number = 1;

notificationManager.setSlotFlagsByBundle(bundle, slotFlags).then(() => {
	console.info("setSlotFlagsByBundle success");
}).catch((err: Base.BusinessError) => {
    console.error(`setSlotFlagsByBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setSlotByBundle

setSlotByBundle(bundle: BundleOption, slot: NotificationSlot, callback: AsyncCallback\<void\>): void

Sets the notification slot for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | Yes  | Bundle of the application.          |
| slot     | [NotificationSlot](js-apis-inner-notification-notificationSlot.md)      | Yes  | Notification slot.            |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let setSlotByBundleCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setSlotByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setSlotByBundle success");
    }
}
let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
notificationManager.setSlotByBundle(bundle, notificationSlot, setSlotByBundleCallback);
```

## notificationManager.setSlotByBundle

setSlotByBundle(bundle: BundleOption, slot: NotificationSlot): Promise\<void\>

Sets the notification slot for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle of the application.|
| slot   | [NotificationSlot](js-apis-inner-notification-notificationSlot.md) | Yes  | Notification slot.|

**Return value**

| Type     | Description       | 
|---------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};

let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};

notificationManager.setSlotByBundle(bundle, notificationSlot).then(() => {
	console.info("setSlotByBundle success");
}).catch((err: Base.BusinessError) => {
    console.error(`setSlotByBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.getSlotFlagsByBundle<sup>11+</sup>

getSlotFlagsByBundle(bundle: BundleOption): Promise\<number\>

Obtains the notification slot flag of a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle of the application.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
|  Promise\<number\>| Promise used to return the notification slot flag.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.getSlotFlagsByBundle(bundle).then((data : number) => {
	console.info("getSlotFlagsByBundle success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getSlotFlagsByBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.getSlotsByBundle

getSlotsByBundle(bundle: BundleOption, callback: AsyncCallback\<Array\<NotificationSlot>>): void

Obtains the notification slots of a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                                    | Mandatory| Description                |
| -------- | ---------------------------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)                             | Yes  | Bundle of the application.          |
| callback | AsyncCallback\<Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)>> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let getSlotsByBundleCallback = (err: Base.BusinessError, data: Array<notificationManager.NotificationSlot>): void => {
    if (err) {
        console.error(`getSlotsByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getSlotsByBundle success, data is ${JSON.stringify(data)}`);
    }
}
let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.getSlotsByBundle(bundle, getSlotsByBundleCallback);
```

## notificationManager.getSlotsByBundle

getSlotsByBundle(bundle: BundleOption): Promise\<Array\<NotificationSlot>>

Obtains the notification slots of a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle of the application.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)>> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};

notificationManager.getSlotsByBundle(bundle).then((data: Array<notificationManager.NotificationSlot>) => {
	console.info("getSlotsByBundle success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getSlotsByBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.getSlotNumByBundle

getSlotNumByBundle(bundle: BundleOption, callback: AsyncCallback\<number\>): void

Obtains the number of notification slots of a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                     | Mandatory| Description                  |
| -------- | ------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)              | Yes  | Bundle of the application.            |
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let getSlotNumByBundleCallback = (err: Base.BusinessError, data: number): void => {
    if (err) {
        console.error(`getSlotNumByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getSlotNumByBundle success data is ${JSON.stringify(data)}`);
    }
}

let bundle: notificationManager.BundleOption = {
  bundle: "bundleName1",
};

notificationManager.getSlotNumByBundle(bundle, getSlotNumByBundleCallback);
```

## notificationManager.getSlotNumByBundle

getSlotNumByBundle(bundle: BundleOption): Promise\<number\>

Obtains the number of notification slots of a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle of the application.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
  bundle: "bundleName1",
};

notificationManager.getSlotNumByBundle(bundle).then((data: number) => {
	console.info("getSlotNumByBundle success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getSlotNumByBundle fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.getAllActiveNotifications

getAllActiveNotifications(callback: AsyncCallback\<Array\<NotificationRequest>>): void

Obtains all active notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                                                        | Mandatory| Description                |
| -------- | ------------------------------------------------------------ | ---- | -------------------- |
| callback | AsyncCallback\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest)>> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
import Base from '@ohos.base';

let getAllActiveNotificationsCallback = (err: Base.BusinessError, data: Array<notificationManager.NotificationRequest>): void => {
    if (err) {
        console.error(`getAllActiveNotifications failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getAllActiveNotifications success, data is ${JSON.stringify(data)}`);
    }
}

notificationManager.getAllActiveNotifications(getAllActiveNotificationsCallback);
```

## notificationManager.getAllActiveNotifications

getAllActiveNotifications(): Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest)\>\>

Obtains all active notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest)\>\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
import Base from '@ohos.base';

notificationManager.getAllActiveNotifications().then((data: Array<notificationManager.NotificationRequest>) => {
	console.info("getAllActiveNotifications success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getAllActiveNotifications fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.getActiveNotificationByFilter<sup>11+<sup>

getActiveNotificationByFilter(filter: NotificationFilter, callback: AsyncCallback\<NotificationRequest\>): void

Obtains information about the common live view that matches the specified filter criteria. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.


**Parameters**

| Name    | Type                                                        | Mandatory| Description                          |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| filter   | [NotificationFilter](js-apis-inner-notification-notificationRequest-sys.md#notificationfilter11) | Yes  | Filter criteria for querying the common live view.|
| callback | AsyncCallback\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest)>> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                 |
| -------- | ---------------------------------------- |
| 1600007  | The notification is not exist.           |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';
import notificationSubscribe from '@ohos.notificationSubscribe';

let bundleOption: notificationManager.BundleOption = {
  bundle: "bundleName1",
};
let notificationKey: notificationSubscribe.NotificationKey = {
    id: 11,
    label: ""
};
let filter: notificationManager.NotificationFilter = {
    bundle: bundleOption,
    notificationKey: notificationKey,
    extraInfoKeys: ['event']
}
let getActiveNotificationByFilterCallback = (err: Base.BusinessError, data: notificationManager.NotificationRequest): void => {
    if (err) {
        console.error(`getActiveNotificationByFilter failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getActiveNotificationByFilter success");
    }
}
notificationManager.getActiveNotificationByFilter(filter, getActiveNotificationByFilterCallback);
```

## notificationManager.getActiveNotificationByFilter<sup>11+<sup>

getActiveNotificationByFilter(filter: NotificationFilter): Promise\<NotificationRequest\>

Obtains information about the common live view that matches the specified filter criteria. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.


**Parameters**

| Name    | Type                                                        | Mandatory| Description                          |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| filter   | [NotificationFilter](js-apis-inner-notification-notificationRequest-sys.md#notificationfilter11) | Yes  | Filter criteria for querying the common live view.|

**Return value**

| Type                                                        | Description                                   |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise\<[NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                 |
| -------- | ---------------------------------------- |
| 1600007  | The notification is not exist.           |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';
import notificationSubscribe from '@ohos.notificationSubscribe';

let bundleOption: notificationManager.BundleOption = {
  bundle: "bundleName1",
};
let notificationKey: notificationSubscribe.NotificationKey = {
    id: 11,
    label: ""
};
let filter: notificationManager.NotificationFilter = {
    bundle: bundleOption,
    notificationKey: notificationKey,
    extraInfoKeys: ['event']
}
notificationManager.getActiveNotificationByFilter(filter).then((data: notificationManager.NotificationRequest) => {
	console.info("getActiveNotificationByFilter success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getActiveNotificationByFilter fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.removeGroupByBundle

removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void\>): void

Removes notifications under a notification group of the specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name     | Type                 | Mandatory| Description                        |
| --------- | --------------------- | ---- | ---------------------------- |
| bundle    | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | Yes  | Bundle information of the application.                  |
| groupName | string                | Yes  | Name of the notification group.              |
| callback  | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let removeGroupByBundleCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`removeGroupByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeGroupByBundle success");
    }
}

let bundleOption: notificationManager.BundleOption = { bundle: "Bundle" };
let groupName: string = "GroupName";

notificationManager.removeGroupByBundle(bundleOption, groupName, removeGroupByBundleCallback);
```

## notificationManager.removeGroupByBundle

removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void\>

Removes notifications under a notification group of the specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name     | Type        | Mandatory| Description          |
| --------- | ------------ | ---- | -------------- |
| bundle    | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.    |
| groupName | string       | Yes  | Name of the notification group.|

**Return value**

| Type     | Description       | 
|---------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let bundleOption: notificationManager.BundleOption = { bundle: "Bundle" };
let groupName: string = "GroupName";

notificationManager.removeGroupByBundle(bundleOption, groupName).then(() => {
	console.info("removeGroupByBundle success");
}).catch((err: Base.BusinessError) => {
    console.error(`removeGroupByBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, callback: AsyncCallback\<void\>): void

Sets the DND time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                  |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate)      | Yes  | DND time to set.        |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**Example**

```ts
import Base from '@ohos.base';

let setDoNotDisturbDateCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setDoNotDisturbDate success");
    }
}

let doNotDisturbDate: notificationManager.DoNotDisturbDate = {
    type: notificationManager.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
};

notificationManager.setDoNotDisturbDate(doNotDisturbDate, setDoNotDisturbDateCallback);
```

## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate): Promise\<void\>

Sets the DND time. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name| Type            | Mandatory| Description          |
| ---- | ---------------- | ---- | -------------- |
| date | [DoNotDisturbDate](#donotdisturbdate) | Yes  | DND time to set.|


**Return value**

| Type     | Description       | 
|---------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**Example**

```ts
import Base from '@ohos.base';

let doNotDisturbDate: notificationManager.DoNotDisturbDate = {
    type: notificationManager.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
};
notificationManager.setDoNotDisturbDate(doNotDisturbDate).then(() => {
	console.info("setDoNotDisturbDate success");
}).catch((err: Base.BusinessError) => {
    console.error(`setDoNotDisturbDate fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number, callback: AsyncCallback\<void\>): void

Sets the DND time for a specified user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                  |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate)      | Yes  | DND time to set.        |
| userId   | number                | Yes  | ID of the user for whom you want to set the DND time.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |
| 1600012  | No memory space.                          |

**Example**

```ts
import Base from '@ohos.base';

let setDoNotDisturbDateCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setDoNotDisturbDate success");
    }
}

let doNotDisturbDate: notificationManager.DoNotDisturbDate = {
    type: notificationManager.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
};

let userId: number = 1;

notificationManager.setDoNotDisturbDate(doNotDisturbDate, userId, setDoNotDisturbDateCallback);
```

## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number): Promise\<void\>

Sets the DND time for a specified user. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type            | Mandatory| Description          |
| ------ | ---------------- | ---- | -------------- |
| date   | [DoNotDisturbDate](#donotdisturbdate) | Yes  | DND time to set.|
| userId | number           | Yes  | ID of the user for whom you want to set the DND time.|

**Return value**

| Type     | Description       | 
|---------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |
| 1600012  | No memory space.                          |

**Example**

```ts
import Base from '@ohos.base';

let doNotDisturbDate: notificationManager.DoNotDisturbDate = {
    type: notificationManager.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
};

let userId: number = 1;

notificationManager.setDoNotDisturbDate(doNotDisturbDate, userId).then(() => {
	console.info("setDoNotDisturbDate success");
}).catch((err: Base.BusinessError) => {
    console.error(`setDoNotDisturbDate fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate\>): void

Obtains the DND time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                             | Mandatory| Description                  |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate)\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**Example**

```ts
import Base from '@ohos.base';

let getDoNotDisturbDateCallback = (err: Base.BusinessError, data: notificationManager.DoNotDisturbDate): void => {
    if (err) {
        console.error(`getDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getDoNotDisturbDate success, data is ${JSON.stringify(data)}`);
    }
}

notificationManager.getDoNotDisturbDate(getDoNotDisturbDateCallback);
```

## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(): Promise\<DoNotDisturbDate\>

Obtains the DND time. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Return value**

| Type                                            | Description                                     |
| ------------------------------------------------ | ----------------------------------------- |
| Promise\<[DoNotDisturbDate](#donotdisturbdate)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**Example**

```ts
import Base from '@ohos.base';

notificationManager.getDoNotDisturbDate().then((data: notificationManager.DoNotDisturbDate) => {
  console.info("getDoNotDisturbDate success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getDoNotDisturbDate fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(userId: number, callback: AsyncCallback\<DoNotDisturbDate\>): void

Obtains the DND time of a specified user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                             | Mandatory| Description                  |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate)\> | Yes  | Callback used to return the result.|
| userId   | number                            | Yes  | User ID.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |
| 1600012  | No memory space.                          |

**Example**

```ts
import Base from '@ohos.base';

let getDoNotDisturbDateCallback = (err: Base.BusinessError, data: notificationManager.DoNotDisturbDate): void => {
    if (err) {
        console.error(`getDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getDoNotDisturbDate success, data is ${JSON.stringify(data)}`);
    }
}

let userId: number = 1;

notificationManager.getDoNotDisturbDate(userId, getDoNotDisturbDateCallback);
```

## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(userId: number): Promise\<DoNotDisturbDate\>

Obtains the DND time of a specified user. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                             | Mandatory| Description                  |
| -------- | --------------------------------- | ---- | ---------------------- |
| userId   | number                            | Yes  | User ID.|

**Return value**

| Type                                            | Description                                     |
| ------------------------------------------------ | ----------------------------------------- |
| Promise\<[DoNotDisturbDate](#donotdisturbdate)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |
| 1600012  | No memory space.                          |

**Example**

```ts
import Base from '@ohos.base';

let userId: number = 1;

notificationManager.getDoNotDisturbDate(userId).then((data: notificationManager.DoNotDisturbDate) => {
	console.info("getDoNotDisturbDate success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getDoNotDisturbDate fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.isSupportDoNotDisturbMode

 isSupportDoNotDisturbMode(callback: AsyncCallback\<boolean\>): void

Checks whether DND mode is supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                    | Mandatory| Description                            |
| -------- | ------------------------ | ---- | -------------------------------- |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result. The value **true** means that DND mode is supported, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
import Base from '@ohos.base';

let isSupportDoNotDisturbModeCallback = (err: Base.BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isSupportDoNotDisturbMode failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isSupportDoNotDisturbMode success");
    }
}

notificationManager.isSupportDoNotDisturbMode(isSupportDoNotDisturbModeCallback);
```

## notificationManager.isSupportDoNotDisturbMode

isSupportDoNotDisturbMode(): Promise\<boolean\>

Checks whether DND mode is supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result. The value **true** means that DND mode is supported, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
import Base from '@ohos.base';

notificationManager.isSupportDoNotDisturbMode().then((data: boolean) => {
	console.info("supportDoNotDisturbMode success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`supportDoNotDisturbMode fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setDistributedEnable

setDistributedEnable(enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether to enable distributed notification on this device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | Yes  | Whether to enable distributed notification. The value **true** means to enable distributed notification, and **false** means the opposite.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600010  | Distributed operation failed.       |

**Example**

```ts
import Base from '@ohos.base';

let setDistributedEnableCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setDistributedEnable failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setDistributedEnable success");
    }
};
let enable: boolean = true;
notificationManager.setDistributedEnable(enable, setDistributedEnableCallback);
```

## notificationManager.setDistributedEnable

setDistributedEnable(enable: boolean): Promise\<void>

Sets whether to enable distributed notification on this device. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | Yes  | Whether to enable distributed notification. The value **true** means to enable distributed notification, and **false** means the opposite.|

**Return value**

| Type             | Description       | 
|-----------------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600010  | Distributed operation failed.       |

**Example**

```ts
import Base from '@ohos.base';

let enable: boolean = true;
notificationManager.setDistributedEnable(enable).then(() => {
    console.info("setDistributedEnable success");
}).catch((err: Base.BusinessError) => {
    console.error(`setDistributedEnable fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setDistributedEnableByBundle

setDistributedEnableByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void

Sets whether to enable distributed notification for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | Yes  | Bundle information of the application.                  |
| enable   | boolean                  | Yes  | Whether to enable distributed notification. The value **true** means to enable distributed notification, and **false** means the opposite.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let setDistributedEnableByBundleCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setDistributedEnableByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("enableDistributedByBundle success");
    }
};
let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
let enable: boolean = true;
notificationManager.setDistributedEnableByBundle(bundle, enable, setDistributedEnableByBundleCallback);
```



## notificationManager.setDistributedEnableByBundle

setDistributedEnableByBundle(bundle: BundleOption, enable: boolean): Promise\<void>

Sets whether to enable distributed notification for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | Yes  | Bundle information of the application.               |
| enable   | boolean                  | Yes  | Whether to enable distributed notification. The value **true** means to enable distributed notification, and **false** means the opposite.                 |

**Return value**

| Type             | Description       | 
|-----------------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
let enable: boolean = true;
notificationManager.setDistributedEnableByBundle(bundle, enable).then(() => {
    console.info("setDistributedEnableByBundle success");
}).catch((err: Base.BusinessError) => {
    console.error(`setDistributedEnableByBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.isDistributedEnabledByBundle

isDistributedEnabledByBundle(bundle: BundleOption, callback: AsyncCallback\<boolean>): void

Checks whether distributed notification is enabled for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | Yes  | Bundle information of the application.                    |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result. The value **true** means that distributed notification is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let isDistributedEnabledByBundleCallback = (err: Base.BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isDistributedEnabledByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isDistributedEnabledByBundle success" + JSON.stringify(data));
    }
};
let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.isDistributedEnabledByBundle(bundle, isDistributedEnabledByBundleCallback);
```

## notificationManager.isDistributedEnabledByBundle

isDistributedEnabledByBundle(bundle: BundleOption): Promise\<boolean>

Checks whether distributed notification is enabled for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | Yes  | Bundle information of the application.               |

**Return value**

| Type              | Description                                             |
| ------------------ | ------------------------------------------------- |
| Promise\<boolean\> | Promise used to return the result. The value **true** means that distributed notification is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.isDistributedEnabledByBundle(bundle).then((data: boolean) => {
    console.info("isDistributedEnabledByBundle success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`isDistributedEnabledByBundle fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.getDeviceRemindType

getDeviceRemindType(callback: AsyncCallback\<DeviceRemindType\>): void

Obtains the notification reminder type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                              | Mandatory| Description                      |
| -------- | --------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<[DeviceRemindType](#deviceremindtype)\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
import Base from '@ohos.base';

let getDeviceRemindTypeCallback = (err: Base.BusinessError, data: notificationManager.DeviceRemindType): void => {
    if (err) {
        console.error(`getDeviceRemindType failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getDeviceRemindType success, data is ${JSON.stringify(data)}`);
    }
};
notificationManager.getDeviceRemindType(getDeviceRemindTypeCallback);
```

## notificationManager.getDeviceRemindType

getDeviceRemindType(): Promise\<DeviceRemindType\>

Obtains the notification reminder type. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Return value**

| Type              | Description           |
| ------------------ | --------------- |
| Promise\<[DeviceRemindType](#deviceremindtype)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
import Base from '@ohos.base';

notificationManager.getDeviceRemindType().then((data: notificationManager.DeviceRemindType) => {
    console.info("getDeviceRemindType success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getDeviceRemindType fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.publishAsBundle

publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number, callback: AsyncCallback\<void\>): void

Publishes a notification through the reminder agent. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER, ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name              | Type                                       | Mandatory| Description                                    |
| -------------------- | ------------------------------------------- | ---- | ---------------------------------------- |
| request              | [NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest) | Yes  | Content and related configuration of the notification to publish.|
| representativeBundle | string                                      | Yes  | Bundle name of the application whose notification function is taken over by the reminder agent.                      |
| userId               | number                                      | Yes  | User ID.                                |
| callback             | AsyncCallback\<void\>                        | Yes  | Callback used to return the result.                |

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600008  | The user does not exist.                    |
| 1600009  | Over max number notifications per second. |
| 1600012  | No memory space.                          |

**Example**

```ts
import Base from '@ohos.base';

// publishAsBundle callback
let callback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`publishAsBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publishAsBundle success");
    }
}
// Bundle name of the application whose notification function is taken over by the reminder agent
let representativeBundle: string = "com.example.demo";
// User ID
let userId: number = 100;
// NotificationRequest object
let request: notificationManager.NotificationRequest = {
    id: 1,
    content: {
        notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
};
notificationManager.publishAsBundle(request, representativeBundle, userId, callback);
```

## notificationManager.publishAsBundle

publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number): Promise\<void\>

Publishes a notification through the reminder agent. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER, ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API.

**Parameters**


| Name              | Type                                       | Mandatory| Description                                         |
| -------------------- | ------------------------------------------- | ---- | --------------------------------------------- |
| request              | [NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest) | Yes  | Content and related configuration of the notification to publish.|
| representativeBundle | string                                      | Yes  | Bundle name of the application whose notification function is taken over by the reminder agent.                           |
| userId               | number                                      | Yes  | User ID.                           |

**Return value**

| Type             | Description       | 
|-----------------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600008  | The user does not exist.                    |
| 1600009  | Over max number notifications per second. |
| 1600012  | No memory space.                          |

**Example**

```ts
import Base from '@ohos.base';

// Bundle name of the application whose notification function is taken over by the reminder agent
let representativeBundle: string = "com.example.demo";
// User ID
let userId: number = 100;
// NotificationRequest object
let request: notificationManager.NotificationRequest = {
    id: 1,
    content: {
        notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
};
notificationManager.publishAsBundle(request, representativeBundle, userId).then(() => {
	console.info("publishAsBundle success");
}).catch((err: Base.BusinessError) => {
    console.error(`publishAsBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.cancelAsBundle

cancelAsBundle(id: number, representativeBundle: string, userId: number, callback: AsyncCallback\<void\>): void

Cancels a notification published through the reminder agent. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER, ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name              | Type         | Mandatory| Description                    |
| -------------------- | ------------- | ---- | ------------------------ |
| id                   | number        | Yes  | Notification ID.                |
| representativeBundle | string        | Yes  | Bundle name of the application whose notification function is taken over by the reminder agent.      |
| userId               | number        | Yes  | User ID.      |
| callback             | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |
| 1600008  | The user does not exist.              |

**Example**

```ts
import Base from '@ohos.base';

// cancelAsBundle
let cancelAsBundleCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`cancelAsBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("cancelAsBundle success");
    }
}
// Bundle name of the application whose notification function is taken over by the reminder agent
let representativeBundle: string = "com.example.demo";
// User ID
let userId: number = 100;
notificationManager.cancelAsBundle(0, representativeBundle, userId, cancelAsBundleCallback);
```

## notificationManager.cancelAsBundle

cancelAsBundle(id: number, representativeBundle: string, userId: number): Promise\<void\>

Cancels a notification published through the reminder agent. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER, ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name              | Type  | Mandatory| Description              |
| -------------------- | ------ | ---- | ------------------ |
| id                   | number | Yes  | Notification ID.          |
| representativeBundle | string | Yes  | Bundle name of the application whose notification function is taken over by the reminder agent.|
| userId               | number | Yes  | User ID.|

**Return value**

| Type             | Description       | 
|-----------------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |
| 1600008  | The user does not exist.              |

**Example**

```ts
import Base from '@ohos.base';

// Bundle name of the application whose notification function is taken over by the reminder agent
let representativeBundle: string = "com.example.demo";
// User ID
let userId: number = 100;
notificationManager.cancelAsBundle(0, representativeBundle, userId).then(() => {
	console.info("cancelAsBundle success");
}).catch((err: Base.BusinessError) => {
    console.error(`cancelAsBundle fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setNotificationEnableSlot 

setNotificationEnableSlot(bundle: BundleOption, type: SlotType, enable: boolean, callback: AsyncCallback\<void>): void

Sets the enabled status of a slot type for the specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                         | Mandatory| Description                  |
| -------- | ----------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.          |
| type     | [SlotType](./js-apis-notificationManager.md#slottype)         | Yes  | Notification slot type.        |
| enable   | boolean                       | Yes  | Whether to enable the notification slot type. The value **true** means to enable the notification slot type, and **false** means the opposite.            |
| callback | AsyncCallback\<void\>         | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600012  | No memory space.                         |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

// setNotificationEnableSlot
let setNotificationEnableSlotCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setNotificationEnableSlot failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setNotificationEnableSlot success");
    }
};
notificationManager.setNotificationEnableSlot(
    { bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION,
    true,
    setNotificationEnableSlotCallback);
```

## notificationManager.setNotificationEnableSlot<sup>11+</sup>

setNotificationEnableSlot(bundle: BundleOption, type: SlotType, enable: boolean, isForceControl: boolean, callback: AsyncCallback\<void>): void

Sets the enabled status of a slot type for the specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                         | Mandatory| Description                    |
| -------- | ----------------------------- | ---- | ----------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|
| type     | [SlotType](./js-apis-notificationManager.md#slottype)         | Yes  | Notification slot type.          |
| enable   | boolean                       | Yes  | Whether to enable the notification slot type.              |
| isForceControl<sup>11+</sup> | boolean                 | Yes  | Whether the enabled status of the notification slot is subject to the enabled status of notification. The value **false** means that the enabled status of the notification slot is subject to the enabled status of notification, and **true** means the opposite.|
| callback | AsyncCallback\<void\>         | Yes  | Callback used to return the result.   |

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600012  | No memory space.                         |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

let setNotificationEnableSlotCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setNotificationEnableSlot failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setNotificationEnableSlot success");
    }
};

notificationManager.setNotificationEnableSlot(
    { bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION,
    true,
    false,
    setNotificationEnableSlotCallback);
```

## notificationManager.setNotificationEnableSlot

setNotificationEnableSlot(bundle: BundleOption, type: SlotType, enable: boolean, isForceControl?: boolean): Promise\<void>

Sets the enabled status of a slot type for the specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.  |
| type   | [SlotType](./js-apis-notificationManager.md#slottype)         | Yes  | Notification slot type.|
| enable | boolean                       | Yes  | Whether to enable the notification slot type. The value **true** means to enable the notification slot type, and **false** means the opposite.    |
| isForceControl<sup>11+</sup> | boolean               | No  | Whether the enabled status of the notification slot is subject to the enabled status of notification. The value **false** means that the enabled status of the notification slot is subject to the enabled status of notification, and **true** means the opposite.<br> Default value: **false**    |

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600012  | No memory space.                         |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

// setNotificationEnableSlot
notificationManager.setNotificationEnableSlot(
    { bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION,
    true).then(() => {
        console.info("setNotificationEnableSlot success");
    }).catch((err: Base.BusinessError) => {
        console.error(`setNotificationEnableSlot fail: ${JSON.stringify(err)}`);
    });
```

## notificationManager.isNotificationSlotEnabled

isNotificationSlotEnabled(bundle: BundleOption, type: SlotType, callback: AsyncCallback\<boolean\>): void

Checks whether a specified notification slot type is enabled for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name  | Type                         | Mandatory| Description                  |
| -------- | ----------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.          |
| type     | [SlotType](./js-apis-notificationManager.md#slottype)         | Yes  | Notification slot type.        |
| callback | AsyncCallback\<boolean\>         | Yes  | Callback used to return the result. The value **true** means that the notification slot type is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

// isNotificationSlotEnabled
let getEnableSlotCallback = (err: Base.BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isNotificationSlotEnabled failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`isNotificationSlotEnabled success, data is ${JSON.stringify(data)}`);
    }
};

notificationManager.isNotificationSlotEnabled(
    { bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION,
    getEnableSlotCallback);
```

## notificationManager.isNotificationSlotEnabled

isNotificationSlotEnabled(bundle: BundleOption, type: SlotType): Promise\<boolean\>  

Checks whether a specified notification slot type is enabled for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.  |
| type   | [SlotType](./js-apis-notificationManager.md#slottype)         | Yes  | Notification slot type.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result. The value **true** means that the notification slot type is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

// isNotificationSlotEnabled
notificationManager.isNotificationSlotEnabled({ bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION).then((data: boolean) => {
    console.info("isNotificationSlotEnabled success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`isNotificationSlotEnabled fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.setSyncNotificationEnabledWithoutApp

setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether to enable the notification sync feature for devices where the application is not installed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | Yes  | User ID.  |
| enable | boolean | Yes  | Whether to enable the notification sync feature. The value **true** means to enable the feature, and **false** means the opposite.  |
| callback | AsyncCallback\<void\>    | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |

**Example**

```ts
import Base from '@ohos.base';

let userId: number = 100;
let enable: boolean = true;
let callback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`setSyncNotificationEnabledWithoutApp failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setSyncNotificationEnabledWithoutApp success");
    }
}
notificationManager.setSyncNotificationEnabledWithoutApp(userId, enable, callback);
```


## notificationManager.setSyncNotificationEnabledWithoutApp

setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean): Promise\<void>

Sets whether to enable the notification sync feature for devices where the application is not installed. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | Yes  | User ID.  |
| enable | boolean | Yes  | Whether to enable the notification sync feature. The value **true** means to enable the feature, and **false** means the opposite.  |

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |

**Example**

```ts
import Base from '@ohos.base';

let userId: number = 100;
let enable: boolean = true;
notificationManager.setSyncNotificationEnabledWithoutApp(userId, enable).then(() => {
    console.info('setSyncNotificationEnabledWithoutApp success');
}).catch((err: Base.BusinessError) => {
    console.error(`setSyncNotificationEnabledWithoutApp fail: ${JSON.stringify(err)}`);
});
```


## notificationManager.getSyncNotificationEnabledWithoutApp

getSyncNotificationEnabledWithoutApp(userId: number, callback: AsyncCallback\<boolean>): void

Obtains whether the notification sync feature is enabled for devices where the application is not installed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | Yes  | User ID.  |
| callback | AsyncCallback\<boolean\>         | Yes  | Callback used to return the result. The value **true** means that the notification sync feature is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |

**Example**

```ts
import Base from '@ohos.base';

let userId: number = 100;
let getSyncNotificationEnabledWithoutAppCallback = (err: Base.BusinessError, data: boolean): void => {
    if (err) {
        console.info('getSyncNotificationEnabledWithoutAppCallback, err:' + err);
    } else {
        console.info('getSyncNotificationEnabledWithoutAppCallback, data:' + data);
    }
}
notificationManager.getSyncNotificationEnabledWithoutApp(userId, getSyncNotificationEnabledWithoutAppCallback);
```


## notificationManager.getSyncNotificationEnabledWithoutApp

getSyncNotificationEnabledWithoutApp(userId: number): Promise\<boolean>

Obtains whether the notification sync feature is enabled for devices where the application is not installed. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | Yes  | User ID.  |

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result. The value **true** means that the notification sync feature is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user does not exist.              |

**Example**

```ts
import Base from '@ohos.base';

let userId: number = 100;
notificationManager.getSyncNotificationEnabledWithoutApp(userId).then((data: boolean) => {
  console.info('getSyncNotificationEnabledWithoutApp, data:' + data);
}).catch((err: Base.BusinessError) => {
    console.error(`getSyncNotificationEnabledWithoutApp fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.on<sup>10+</sup>

on(type: 'checkNotification', callback: (checkInfo: NotificationCheckInfo) => NotificationCheckResult): void;

Subscribes to notification events. The notification service sends the notification information in the callback to the verification program. The verification program returns the verification result to determine whether to publish the notification, for example, controlling the publish frequency of marketing notifications.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER, ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name| Type                                                                                                                     | Mandatory| Description          |
| ------ |-------------------------------------------------------------------------------------------------------------------------| ---- | -------------- |
| type | string                                                                                                                  | Yes  | Event type. The value is fixed to **'checkNotification'**.|
| callback | (checkInfo: [NotificationCheckInfo](#notificationcheckinfo10)) =>  [NotificationCheckResult](#notificationcheckresult10) | Yes  | Pointer to the notification verification function.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |

**Example**

```ts
import Base from '@ohos.base';

let onCheckNotification = (info : notificationManager.NotificationCheckInfo): notificationManager.NotificationCheckResult => {
    console.info(`====>OnCheckNotification info: ${JSON.stringify(info)}`);
    if(info.notificationId == 1){
        let result: notificationManager.NotificationCheckResult =  { code: 1, message: "testMsg1"};
        return result;
    } else {
        let result: notificationManager.NotificationCheckResult =   { code: 0, message: "testMsg0"};
        return result;
    }
}
try{
    notificationManager.on("checkNotification", onCheckNotification);
} catch (error){
    console.error(`notificationManager.on error: ${JSON.stringify(error as Base.BusinessError)}`);
}
```

## notificationManager.on<sup>11+</sup>

on(type: 'checkNotification', checkRequest: NotificationCheckRequest, callback: (checkInfo: NotificationCheckInfo) => Promise\<NotificationCheckResult\>): void

Subscribes to notification events. The notification service sends the notification information in the callback to the verification program. The verification program returns the verification result to determine whether to publish the notification, for example, controlling the publish frequency of marketing notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER, ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name| Type                                                                                                            | Mandatory| Description          |
| ------ |-----------------------------------------------------------------------------------------------------------------| ---- | -------------- |
| type | string                                                                                                            | Yes  | Event type. The value is fixed to **'checkNotification'**.|
| checkRequest | [NotificationCheckRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationcheckrequest11)    | Yes  | Notification verification content.|
| callback | (checkInfo: [NotificationCheckInfo](#notificationcheckinfo10)) =>  Promise\<[NotificationCheckResult](#notificationcheckresult10)\> | Yes  | Pointer to the notification verification function.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |

**Example**

```ts
import Base from '@ohos.base';

try{
  notificationManager.on('checkNotification',{
    contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_LIVE_VIEW,
    slotType: notificationManager.SlotType.LIVE_VIEW ,
    extraInfoKeys: ["event"],
  },
    async (checkInfo)=>{
      return { code: 1, message: "INVALID_PARAMETERS"};
  },);
} catch (error) {
  console.error(`notificationManager.on error: ${JSON.stringify(error as Base.BusinessError)}`);
}
```

## notificationManager.off<sup>10+</sup>

off(type: 'checkNotification', callback?: (checkInfo: NotificationCheckInfo) => NotificationCheckResult): void;

Unsubscribes from notification events.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER, ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name| Type                                                                                                                     | Mandatory| Description          |
| ------ |-------------------------------------------------------------------------------------------------------------------------| ---- | -------------- |
| type | string                                                                                                                  | Yes  | Event type. The value is fixed to **'checkNotification'**.|
| callback | (checkInfo: [NotificationCheckInfo](#notificationcheckinfo10)) =>  [NotificationCheckResult](#notificationcheckresult10) | No  | Pointer to the notification verification function.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |

**Example**

```ts
import Base from '@ohos.base';

try{
    notificationManager.off("checkNotification");
} catch (error){
    console.error(`notificationManager.off error: ${JSON.stringify(error as Base.BusinessError)}`);
}
```

## notificationManager.triggerSystemLiveView<sup>11+</sup>

triggerSystemLiveView(bundle: BundleOption, notificationId: number, buttonOptions: ButtonOptions): Promise\<void>;

Triggers a system live view notification. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name| Type                  | Mandatory| Description          |
| -------------- | ------------- | ---- | -------------- |
| bundle         | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)  | Yes  |Bundle of the application.|
| notificationId | number        | Yes  | Notification ID.|
| buttonOptions  | [ButtonOptions](#buttonoptions11) | Yes  | Button information.|

**Return value**

| Type| Description|
| ---- | ----|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

// Bundle of the application
let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
// Notification ID
let notificationId = 1;
// Button information
let buttonOptions: notificationManager.ButtonOptions = {
    buttonName: "buttonName1",
}
notificationManager.triggerSystemLiveView(bundle, notificationId, buttonOptions).then(() => {
  console.info("triggerSystemLiveView success");
}).catch((error: Base.BusinessError) => {
  console.error(`triggerSystemLiveView fail: ${JSON.stringify(error)}`);
});
```


## notificationManager.subscribeSystemLiveView<sup>11+</sup>

subscribeSystemLiveView(subscriber: SystemLiveViewSubscriber): Promise\<void>;

Subscribes to the system live view notification. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

**Parameters**

| Name| Type                  | Mandatory| Description          |
| -------------- | ------------- | ---- | -------------- |
| subscriber | [SystemLiveViewSubscriber](#systemliveviewsubscriber11)  | Yes  | Subscriber of the system live view notification.|

**Return value**

| Type| Description|
| ---- | ----|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |

**Example**

```ts
import Base from '@ohos.base';

let onResponseCallback = (id:number, option:notificationManager.ButtonOptions) => {
    console.info("response callback: " + JSON.stringify(option) + "notificationId" + id);
}
let subscriber: notificationManager.SystemLiveViewSubscriber  = {
    onResponse: onResponseCallback,
};
notificationManager.subscribeSystemLiveView(subscriber).then(() => {
	console.info("subscribeSystemLiveView success");
}).catch((error: Base.BusinessError) => {
    console.error(`subscribeSystemLiveView fail: ${JSON.stringify(error)}`);
});
```

## DoNotDisturbDate

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

| Name | Type                                 | Mandatory| Description                  |
| ----- | ------------------------------------- | ---- | ---------------------- |
| type  | [DoNotDisturbType](#donotdisturbtype) | Yes  | DND time type.|
| begin | Date                                  | Yes  | DND start time.|
| end   | Date                                  | Yes  | DND end time.|

## DoNotDisturbType

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

| Name        | Value              | Description                                      |
| ------------ | ---------------- | ------------------------------------------ |
| TYPE_NONE    | 0 | Non-DND.                          |
| TYPE_ONCE    | 1 | One-shot DND at the specified time segment (only considering the hour and minute).|
| TYPE_DAILY   | 2 | Daily DND at the specified time segment (only considering the hour and minute).|
| TYPE_CLEARLY | 3 | DND at the specified time segment (with the hour, day, and month specified).    |


## DeviceRemindType

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

| Name                | Value | Description                              |
| -------------------- | --- | --------------------------------- |
| IDLE_DONOT_REMIND    | 0   | The device is not in use. No notification is required.           |
| IDLE_REMIND          | 1   | The device is not in use.                |
| ACTIVE_DONOT_REMIND  | 2   | The device is in use. No notification is required.           |
| ACTIVE_REMIND        | 3   | The device is in use.                |


## SourceType

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

| Name                | Value | Description                 |
| -------------------- | --- | -------------------- |
| TYPE_NORMAL          | 0   | Normal notification.           |
| TYPE_CONTINUOUS      | 1   | Continuous notification.           |
| TYPE_TIMER           | 2   | Timed notification.           |

## NotificationCheckInfo<sup>10+</sup>

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER, ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API.

| Name                        | Type                        | Mandatory| Description           |
| ---------------------------- | ---------------------------- | --- | --------------- |
| bundleName                   | string                       | Yes  | Bundle name.   |
| notificationId               | number                       | Yes  | Notification ID.       |
| label<sup>11+</sup>          | string                       | No  | Notification label.     |
| contentType                  | [ContentType](./js-apis-notificationManager.md#contenttype)  | Yes  | Notification type.     |
| creatorUserId<sup>11+</sup>  | number                       | Yes  | User ID of the notification.|
| slotType<sup>11+</sup>       | [SlotType](./js-apis-notificationManager.md#slottype)        | Yes  | Notification slot type.     |
| extraInfos<sup>11+</sup>     | [key: string]: object        | No  | Extra information of the notification.|

## NotificationCheckResult<sup>10+</sup>

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER, ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API.

| Name   | Type                                 | Mandatory| Description                  |
| ------- | ------------------------------------ | ---- | ---------------------- |
| code    | number                               | Yes  | Result code.<br>**0**: display.<br>**1**: no display.|
| message | string                               | Yes  | Result.   |


## ButtonOptions<sup>11+</sup>

Provides the button information of the notification.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER, ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API.

| Name   | Type                                 | Mandatory| Description                  |
| ------- | ------------------------------------ | ---- | ---------------------- |
| buttonName    | string                         | Yes  | Button name.|


## SystemLiveViewSubscriber<sup>11+</sup>

Subscriber of the system live view notification.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.


| Name   | Type                                 | Mandatory| Description                  |
| ------- | ------------------------------------ | ---- | ---------------------- |
| onResponse    | (notificationId: number, buttonOptions: ButtonOptions) => void;                         | No  | Callback when the button is touched.|
