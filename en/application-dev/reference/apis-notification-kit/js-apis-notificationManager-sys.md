# @ohos.notificationManager (NotificationManager) (System API)

The **NotificationManager** module provides notification management capabilities, covering notifications, notification slots, notification enabled status, and notification badge status.

> **NOTE**<br>
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [NotificationManager](./js-apis-notificationManager.md).

## Modules to Import

```ts
import { notificationManager } from '@kit.NotificationKit';
```

## notificationManager.publish

publish(request: NotificationRequest, userId: number, callback: AsyncCallback\<void\>): void

Publishes a notification to a specified user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER or ohos.permission.SEND_NOTIFICATION_CROSS_USER

**System API**: This is a system API.

**Parameters**

| Name    | Type                                       | Mandatory| Description                                       |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest) | Yes  | Content and related configuration of the notification to publish.|
| userId   | number                                      | Yes  | User ID.                          |
| callback | AsyncCallback\<void\>                       | Yes  | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                                      |
| 1600002  | Marshalling or unmarshalling error.                  |
| 1600003  | Failed to connect to the service.                    |
| 1600004  | Notification disabled.                               |
| 1600005  | Notification slot disabled.                    |
| 1600007  | The notification does not exist.                       |
| 1600008  | The user does not exist.                               |
| 1600009  | The notification sending frequency reaches the upper limit.            |
| 1600012  | No memory space.                                     |
| 1600014  | No permission.                                   |
| 1600015  | The current notification status does not support duplicate configurations. |
| 1600016  | The notification version for this update is too low. |
| 1600020  | The application is not allowed to send notifications due to permission settings. |
| 2300007  | Network unreachable.                              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// publish callback
let publishCallback = (err: BusinessError): void => {
    if (err) {
        console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publish success");
    }
}
// Use the actual user ID when calling the API.
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

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER or ohos.permission.SEND_NOTIFICATION_CROSS_USER

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                             |
| -------- | ---------------------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                                      |
| 1600002  | Marshalling or unmarshalling error.                  |
| 1600003  | Failed to connect to the service.                           |
| 1600004  | Notification disabled.                         |
| 1600005  | Notification slot disabled.                    |
| 1600007  | The notification does not exist.                       |
| 1600008  | The user does not exist.                               |
| 1600009  | The notification sending frequency reaches the upper limit.            |
| 1600012  | No memory space.                                     |
| 1600014  | No permission.                                   |
| 1600015  | The current notification status does not support duplicate configurations. |
| 1600016  | The notification version for this update is too low. |
| 1600020  | The application is not allowed to send notifications due to permission settings. |
| 2300007  | Network unreachable.                              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

// Use the actual user ID when calling the API.
let userId: number = 1;

notificationManager.publish(notificationRequest, userId).then(() => {
	console.info("publish success");
}).catch((err: BusinessError) => {
    console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
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
| slot     | [NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md)       | Yes  | Notification slot to add.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// addSlot callback
let addSlotCallBack = (err: BusinessError): void => {
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
| slot | [NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md) | Yes  | Notification slot to add.|

**Return value**

| Type    | Description       | 
| ------- |-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// NotificationSlot object
let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
notificationManager.addSlot(notificationSlot).then(() => {
	console.info("addSlot success");
}).catch((err: BusinessError) => {
    console.error(`addSlot failed, code is ${err.code}, message is ${err.message}`);
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
| slots    | Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md)\> | Yes  | Notification slots to add.|
| callback | AsyncCallback\<void\>     | Yes  | Callback used to return the result.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// addSlots callback
let addSlotsCallBack = (err: BusinessError): void => {
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
| slots | Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md)\> | Yes  | Notification slots to add.|

**Return value**

| Type     | Description       | 
|---------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// NotificationSlot object
let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
// NotificationSlotArray object
let notificationSlotArray: notificationManager.NotificationSlot[] = new Array();
notificationSlotArray[0] = notificationSlot;

notificationManager.addSlots(notificationSlotArray).then(() => {
	console.info("addSlots success");
}).catch((err: BusinessError) => {
    console.error(`addSlots failed, code is ${err.code}, message is ${err.message}`);
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
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)   | Yes  | Bundle information of the application.       |
| enable   | boolean               | Yes  | Whether to enable the notification slot type. The value **true** means to enable the notification slot type, and **false** means the opposite.            |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let setNotificationEnableCallback = (err: BusinessError): void => {
    if (err) {
        console.error(`setNotificationEnable failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setNotificationEnable success");
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
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|
| enable | boolean      | Yes  | Whether to enable the notification slot type. The value **true** means to enable the notification slot type, and **false** means the opposite.  |

**Return value**

| Type     | Description       | 
|---------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.setNotificationEnable(bundle, false).then(() => {
	console.info("setNotificationEnable success");
}).catch((err: BusinessError) => {
    console.error(`setNotificationEnable failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.getAllNotificationEnabledBundles<sup>12+</sup>

getAllNotificationEnabledBundles(): Promise<Array<BundleOption\>>

Obtains a list of applications that allow notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Return value**

| Type     | Description       | 
|---------|-----------|
| Promise<Array<[BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption)\>> | Returns a list of applications that allow notifications.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

notificationManager.getAllNotificationEnabledBundles().then((data: Array<notificationManager.BundleOption>) => {
    console.info(`Enable bundle data is ${JSON.stringify(data)}`);
    data.forEach(element => {
        console.info(`Enable uid is ${JSON.stringify(element.uid)}`);
        console.info(`Enable bundle is ${JSON.stringify(element.bundle)}`);
    });
}).catch((err: BusinessError) => {
    console.error(`getAllNotificationEnabledBundles failed, code is ${err.code}, message is ${err.message}`);
})
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
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | Yes  | Bundle information of the application.           |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result. The value **true** means that the notification is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isNotificationEnabledCallback = (err: BusinessError, data: boolean): void => {
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
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|

**Return value**

| Type              | Description                                               |
| ------------------ | --------------------------------------------------- |
| Promise\<boolean\> | Promise used to return the result. The value **true** means that the notification is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.isNotificationEnabled(bundle).then((data: boolean) => {
	console.info(`isNotificationEnabled success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isNotificationEnabled failed, code is ${err.code}, message is ${err.message}`);
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
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result. The value **true** means that the notification is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isNotificationEnabledCallback = (err: BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isNotificationEnabled failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`isNotificationEnabled success, data is ${JSON.stringify(data)}`);
    }
}

// Use the actual user ID when calling the API.
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
| Promise\<boolean\> | Promise used to return the result. The value **true** means that the notification is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600008  | The user does not exist.                  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Use the actual user ID when calling the API.
let userId: number = 1;

notificationManager.isNotificationEnabled(userId).then((data: boolean) => {
	console.info(`isNotificationEnabled success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isNotificationEnabled failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.displayBadge

displayBadge(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether to enable the notification badge for a specified application. This API uses an asynchronous callback to return the result.

This API is not supported on wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | Yes  | Bundle information of the application.          |
| enable   | boolean               | Yes  | Whether to enable the notification slot type. The value **true** means to enable the notification slot type, and **false** means the opposite.            |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 801 | Capability not supported. | 
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let displayBadgeCallback = (err: BusinessError): void => {
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

This API is not supported on wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|
| enable | boolean      | Yes  | Whether to enable the notification slot type. The value **true** means to enable the notification slot type, and **false** means the opposite.  |

**Return value**

| Type     | Description       | 
|---------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.displayBadge(bundle, false).then(() => {
	console.info("displayBadge success");
}).catch((err: BusinessError) => {
    console.error(`displayBadge failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.isBadgeDisplayed

isBadgeDisplayed(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

Checks whether the notification badge is enabled for a specified application. This API uses an asynchronous callback to return the result.

This API is not supported on wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                    |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | Yes  | Bundle information of the application.              |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result. The value **true** means that the badge is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      | 
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isBadgeDisplayedCallback = (err: BusinessError, data: boolean): void => {
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

This API is not supported on wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result. The value **true** means that the badge is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
  bundle: "bundleName1",
};

notificationManager.isBadgeDisplayed(bundle).then((data: boolean) => {
	console.info(`isBadgeDisplayed success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isBadgeDisplayed failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setSlotFlagsByBundle<sup>11+</sup>

setSlotFlagsByBundle(bundle: BundleOption, slotFlags: number): Promise\<void\>

Sets the notification slot for a specified application. This API uses a promise to return the result.

This API is not supported on wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|
| slotFlags   | number | Yes  | Notification slot flags.<br>- Bit 0: sound alert. The value **0** means to disable the feature, and **1** means the opposite.<br>- Bit 1: locking the screen. The value **0** means to disable the feature, and **1** means the opposite.<br>- Bit 2: banner. The value **0** means to disable the feature, and **1** means the opposite.<br>- BIt 3: turning on the screen. The value **0** means to disable the feature, and **1** means the opposite.<br>- Bit 4: vibration. The value **0** means to disable the feature, and **1** means the opposite.<br>- Bit 5: notification icon in the status bar. The value **0** means to disable the feature, and **1** means the opposite.|

**Return value**

| Type     | Description       | 
|---------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};

let slotFlags: number = 1;

notificationManager.setSlotFlagsByBundle(bundle, slotFlags).then(() => {
	console.info("setSlotFlagsByBundle success");
}).catch((err: BusinessError) => {
    console.error(`setSlotFlagsByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setSlotByBundle

setSlotByBundle(bundle: BundleOption, slot: NotificationSlot, callback: AsyncCallback\<void\>): void

Sets the notification slot for a specified application. This API uses an asynchronous callback to return the result.

Before setting a notification slot, create a slot through [addSlot](#notificationmanageraddslot).

This API is not supported on wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | Yes  | Bundle information of the application.          |
| slot     | [NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md)      | Yes  | Notification slot.            |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let setSlotByBundleCallback = (err: BusinessError): void => {
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

Before setting a notification slot, create a slot through [addSlot](#notificationmanageraddslot).

This API is not supported on wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|
| slot   | [NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md) | Yes  | Notification slot.|

**Return value**

| Type     | Description       | 
|---------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};

let notificationSlot: notificationManager.NotificationSlot = {
    notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
};

notificationManager.setSlotByBundle(bundle, notificationSlot).then(() => {
	console.info("setSlotByBundle success");
}).catch((err: BusinessError) => {
    console.error(`setSlotByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.getSlotFlagsByBundle<sup>11+</sup>

getSlotFlagsByBundle(bundle: BundleOption): Promise\<number\>

Obtains the notification slot flag of a specified application. This API uses a promise to return the result.

This API is not supported on wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
|  Promise\<number\>| Promise used to return the notification slot flag.<br>- Bit 0: sound alert. The value **0** means to disable the feature, and **1** means the opposite.<br>- Bit 1: locking the screen. The value **0** means to disable the feature, and **1** means the opposite.<br>- Bit 2: banner. The value **0** means to disable the feature, and **1** means the opposite.<br>- BIt 3: turning on the screen. The value **0** means to disable the feature, and **1** means the opposite.<br>- Bit 4: vibration. The value **0** means to disable the feature, and **1** means the opposite.<br>- Bit 5: notification icon in the status bar. The value **0** means to disable the feature, and **1** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.getSlotFlagsByBundle(bundle).then((data : number) => {
	console.info(`getSlotFlagsByBundle success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSlotFlagsByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.getSlotsByBundle

getSlotsByBundle(bundle: BundleOption, callback: AsyncCallback\<Array\<NotificationSlot>>): void

Obtains the notification slots of a specified application. This API uses an asynchronous callback to return the result.

This API is not supported on wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                                    | Mandatory| Description                |
| -------- | ---------------------------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)                             | Yes  | Bundle information of the application.          |
| callback | AsyncCallback\<Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md)>> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let getSlotsByBundleCallback = (err: BusinessError, data: Array<notificationManager.NotificationSlot>): void => {
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

This API is not supported on wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md)>> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};

notificationManager.getSlotsByBundle(bundle).then((data: Array<notificationManager.NotificationSlot>) => {
	console.info(`getSlotsByBundle success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSlotsByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.getSlotNumByBundle

getSlotNumByBundle(bundle: BundleOption, callback: AsyncCallback\<number\>): void

Obtains the number of notification slots of a specified application. This API uses an asynchronous callback to return the result.

This API is not supported on wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                     | Mandatory| Description                  |
| -------- | ------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)              | Yes  | Bundle information of the application.            |
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let getSlotNumByBundleCallback = (err: BusinessError, data: number): void => {
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

This API is not supported on wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
  bundle: "bundleName1",
};

notificationManager.getSlotNumByBundle(bundle).then((data: number) => {
	console.info(`getSlotNumByBundle success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSlotNumByBundle failed, code is ${err.code}, message is ${err.message}`);
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let getAllActiveNotificationsCallback = (err: BusinessError, data: Array<notificationManager.NotificationRequest>): void => {
    if (err) {
        console.error(`getAllActiveNotifications failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getAllActiveNotifications success, data is ${JSON.stringify(data)}`);
    }
}

notificationManager.getAllActiveNotifications(getAllActiveNotificationsCallback);
```

## notificationManager.getAllActiveNotifications

getAllActiveNotifications(): Promise\<Array\<NotificationRequest\>\>

Obtains all active notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest)\>\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

notificationManager.getAllActiveNotifications().then((data: Array<notificationManager.NotificationRequest>) => {
	console.info(`getAllActiveNotifications success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getAllActiveNotifications failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.getActiveNotificationByFilter<sup>11+</sup>

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                 |
| -------- | ---------------------------------------- | 
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600007  | The notification does not exist.           |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { notificationSubscribe } from '@kit.NotificationKit';

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
let getActiveNotificationByFilterCallback = (err: BusinessError, data: notificationManager.NotificationRequest): void => {
    if (err) {
        console.error(`getActiveNotificationByFilter failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getActiveNotificationByFilter success");
    }
}
notificationManager.getActiveNotificationByFilter(filter, getActiveNotificationByFilterCallback);
```

## notificationManager.getActiveNotificationByFilter<sup>11+</sup>

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                 |
| -------- | ---------------------------------------- | 
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600007  | The notification does not exist.         |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { notificationSubscribe } from '@kit.NotificationKit';

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
	console.info(`getActiveNotificationByFilter success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getActiveNotificationByFilter failed, code is ${err.code}, message is ${err.message}`);
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let removeGroupByBundleCallback = (err: BusinessError): void => {
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundleOption: notificationManager.BundleOption = { bundle: "Bundle" };
let groupName: string = "GroupName";

notificationManager.removeGroupByBundle(bundleOption, groupName).then(() => {
	console.info("removeGroupByBundle success");
}).catch((err: BusinessError) => {
    console.error(`removeGroupByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, callback: AsyncCallback\<void\>): void

Sets the DND time. This API uses an asynchronous callback to return the result.

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                 | Mandatory| Description                  |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate)      | Yes  | DND time to set.        |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let setDoNotDisturbDateCallback = (err: BusinessError): void => {
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

This API is not supported on TVs and wearables.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let doNotDisturbDate: notificationManager.DoNotDisturbDate = {
    type: notificationManager.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
};
notificationManager.setDoNotDisturbDate(doNotDisturbDate).then(() => {
	console.info("setDoNotDisturbDate success");
}).catch((err: BusinessError) => {
    console.error(`setDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number, callback: AsyncCallback\<void\>): void

Sets the DND time for a specified user. This API uses an asynchronous callback to return the result.

This API is not supported on TVs and wearables.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |
| 1600012  | No memory space.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let setDoNotDisturbDateCallback = (err: BusinessError): void => {
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

// Use the actual user ID when calling the API.
let userId: number = 1;

notificationManager.setDoNotDisturbDate(doNotDisturbDate, userId, setDoNotDisturbDateCallback);
```

## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number): Promise\<void\>

Sets the DND time for a specified user. This API uses a promise to return the result.

This API is not supported on TVs and wearables.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |
| 1600012  | No memory space.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let doNotDisturbDate: notificationManager.DoNotDisturbDate = {
    type: notificationManager.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
};

// Use the actual user ID when calling the API.
let userId: number = 1;

notificationManager.setDoNotDisturbDate(doNotDisturbDate, userId).then(() => {
	console.info("setDoNotDisturbDate success");
}).catch((err: BusinessError) => {
    console.error(`setDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate\>): void

Obtains the DND time. This API uses an asynchronous callback to return the result.

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                             | Mandatory| Description                  |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate)\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let getDoNotDisturbDateCallback = (err: BusinessError, data: notificationManager.DoNotDisturbDate): void => {
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

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Return value**

| Type                                            | Description                                     |
| ------------------------------------------------ | ----------------------------------------- |
| Promise\<[DoNotDisturbDate](#donotdisturbdate)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

notificationManager.getDoNotDisturbDate().then((data: notificationManager.DoNotDisturbDate) => {
  console.info(`getDoNotDisturbDate success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(userId: number, callback: AsyncCallback\<DoNotDisturbDate\>): void

Obtains the DND time of a specified user. This API uses an asynchronous callback to return the result.

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                             | Mandatory| Description                  |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate)\> | Yes  | Callback used to return the result.|
| userId   | number                            | Yes  | User ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |
| 1600012  | No memory space.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let getDoNotDisturbDateCallback = (err: BusinessError, data: notificationManager.DoNotDisturbDate): void => {
    if (err) {
        console.error(`getDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getDoNotDisturbDate success, data is ${JSON.stringify(data)}`);
    }
}

// Use the actual user ID when calling the API.
let userId: number = 1;

notificationManager.getDoNotDisturbDate(userId, getDoNotDisturbDateCallback);
```

## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(userId: number): Promise\<DoNotDisturbDate\>

Obtains the DND time of a specified user. This API uses a promise to return the result.

This API is not supported on TVs and wearables.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |
| 1600012  | No memory space.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Use the actual user ID when calling the API.
let userId: number = 1;

notificationManager.getDoNotDisturbDate(userId).then((data: notificationManager.DoNotDisturbDate) => {
	console.info(`getDoNotDisturbDate success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.isSupportDoNotDisturbMode

 isSupportDoNotDisturbMode(callback: AsyncCallback\<boolean\>): void

Checks whether DND mode is supported. This API uses an asynchronous callback to return the result.

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name    | Type                    | Mandatory| Description                            |
| -------- | ------------------------ | ---- | -------------------------------- |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result. The value **true** means that DND mode is supported, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isSupportDoNotDisturbModeCallback = (err: BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isSupportDoNotDisturbMode failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`isSupportDoNotDisturbMode success, data: ${JSON.stringify(data)}`);
    }
}

notificationManager.isSupportDoNotDisturbMode(isSupportDoNotDisturbModeCallback);
```

## notificationManager.isSupportDoNotDisturbMode

isSupportDoNotDisturbMode(): Promise\<boolean\>

Checks whether DND mode is supported. This API uses a promise to return the result.

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result. The value **true** means that DND mode is supported, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

notificationManager.isSupportDoNotDisturbMode().then((data: boolean) => {
	console.info(`isSupportDoNotDisturbMode success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isSupportDoNotDisturbMode failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setDistributedEnable

setDistributedEnable(enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether to enable distributed notification on this device. This API uses an asynchronous callback to return the result.

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | Yes  | Whether to enable distributed notification. The value **true** means to enable distributed notification, and **false** means the opposite.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600010  | Distributed operation failed.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let setDistributedEnableCallback = (err: BusinessError): void => {
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

This API is not supported on TVs and wearables.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600010  | Distributed operation failed.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let enable: boolean = true;
notificationManager.setDistributedEnable(enable).then(() => {
    console.info("setDistributedEnable success");
}).catch((err: BusinessError) => {
    console.error(`setDistributedEnable failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setDistributedEnableByBundle

setDistributedEnableByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void

Sets whether to enable distributed notification for a specified application. This API uses an asynchronous callback to return the result.

This API is not supported on TVs and wearables.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let setDistributedEnableByBundleCallback = (err: BusinessError): void => {
    if (err) {
        console.error(`setDistributedEnableByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setDistributedEnableByBundle success");
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

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | Yes  | Bundle of the application.               |
| enable   | boolean                  | Yes  | Whether to enable distributed notification. The value **true** means to enable distributed notification, and **false** means the opposite.                 |

**Return value**

| Type             | Description       | 
|-----------------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
let enable: boolean = true;
notificationManager.setDistributedEnableByBundle(bundle, enable).then(() => {
    console.info("setDistributedEnableByBundle success");
}).catch((err: BusinessError) => {
    console.error(`setDistributedEnableByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.isDistributedEnabledByBundle

isDistributedEnabledByBundle(bundle: BundleOption, callback: AsyncCallback\<boolean>): void

Checks whether distributed notification is enabled for a specified application. This API uses an asynchronous callback to return the result.

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | Yes  | Bundle of the application.                    |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result. The value **true** means that distributed notification is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isDistributedEnabledByBundleCallback = (err: BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isDistributedEnabledByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`isDistributedEnabledByBundle success, data: ${JSON.stringify(data)}`);
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

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | Yes  | Bundle of the application.               |

**Return value**

| Type              | Description                                             |
| ------------------ | ------------------------------------------------- |
| Promise\<boolean\> | Promise used to return the result. The value **true** means that distributed notification is enabled, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};
notificationManager.isDistributedEnabledByBundle(bundle).then((data: boolean) => {
    console.info(`isDistributedEnabledByBundle success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isDistributedEnabledByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.getDeviceRemindType

getDeviceRemindType(callback: AsyncCallback\<DeviceRemindType\>): void

Obtains the notification reminder type. This API uses an asynchronous callback to return the result.

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                              | Mandatory| Description                      |
| -------- | --------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<[DeviceRemindType](#deviceremindtype)\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let getDeviceRemindTypeCallback = (err: BusinessError, data: notificationManager.DeviceRemindType): void => {
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

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Return value**

| Type              | Description           |
| ------------------ | --------------- |
| Promise\<[DeviceRemindType](#deviceremindtype)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

notificationManager.getDeviceRemindType().then((data: notificationManager.DeviceRemindType) => {
    console.info(`getDeviceRemindType success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDeviceRemindType failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.publishAsBundle

publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number, callback: AsyncCallback\<void\>): void

Publishes a notification through the reminder agent. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER or ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name              | Type                                       | Mandatory| Description                                    |
| -------------------- | ------------------------------------------- | ---- | ---------------------------------------- |
| request              | [NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest) | Yes  | Content and related configuration of the notification to publish.|
| representativeBundle | string                                      | Yes  | Bundle name of the application whose notification function is taken over by the reminder agent.                      |
| userId               | number                                      | Yes  | User ID.                                |
| callback             | AsyncCallback\<void\>                        | Yes  | Callback used to return the result.                |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect to the service.                |
| 1600004  | Notification disabled.              |
| 1600005  | Notification slot disabled.         |
| 1600007  | The notification does not exist.      |
| 1600008  | The user does not exist.                    |
| 1600009  | The notification sending frequency reaches the upper limit. |
| 1600012  | No memory space.                          |
| 1600015  | The current notification status does not support duplicate configurations. |
| 1600016  | The notification version for this update is too low. |
| 1600020  | The application is not allowed to send notifications due to permission settings. |
| 2300007  | Network unreachable.                              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// publishAsBundle callback
let callback = (err: BusinessError): void => {
    if (err) {
        console.error(`publishAsBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publishAsBundle success");
    }
}
// Bundle name of the application whose notification function is taken over by the reminder agent
let representativeBundle: string = "com.example.demo";
// Use the actual user ID when calling the API.
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

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER or ohos.permission.NOTIFICATION_AGENT_CONTROLLER

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect to the service.                |
| 1600004  | Notification disabled.                    |
| 1600005  | Notification slot disabled.         |
| 1600007  | The notification does not exist.      |
| 1600008  | The user does not exist.                    |
| 1600009  | The notification sending frequency reaches the upper limit. |
| 1600012  | No memory space.                          |
| 1600015  | The current notification status does not support duplicate configurations. |
| 1600016  | The notification version for this update is too low. |
| 1600020  | The application is not allowed to send notifications due to permission settings. |
| 2300007  | Network unreachable.                              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Bundle name of the application whose notification function is taken over by the reminder agent
let representativeBundle: string = "com.example.demo";
// Use the actual user ID when calling the API.
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
}).catch((err: BusinessError) => {
    console.error(`publishAsBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.publishAsBundle<sup>12+</sup>

publishAsBundle(representativeBundle: BundleOption, request: NotificationRequest): Promise\<void\>

Publishes a notification through the reminder agent. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER or ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API.

**Parameters**


| Name              | Type                                       | Mandatory| Description                                         |
|----------------------|--------------------------------------------|------|-----------------------------------------------|
| representativeBundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)  | Yes  | Bundle information of the application whose notification function is taken over by the reminder agent.                           |
| request              | [NotificationRequest](js-apis-inner-notification-notificationRequest-sys.md#notificationrequest) | Yes  | Content and related configuration of the notification to publish.|

**Return value**

| Type             | Description       | 
|-----------------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect to the service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot disabled.         |
| 1600007  | The notification does not exist.      |
| 1600008  | The user does not exist.                    |
| 1600009  | The notification sending frequency reaches the upper limit. |
| 1600012  | No memory space.                          |
| 1600015  | The current notification status does not support duplicate configurations. |
| 1600016  | The notification version for this update is too low. |
| 1600020  | The application is not allowed to send notifications due to permission settings. |
| 2300007  | Network unreachable.                              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Bundle information of the application whose notification function is taken over by the reminder agent.
let representativeBundle: notificationManager.BundleOption = {
  bundle: "bundleName1",
};
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
notificationManager.publishAsBundle(representativeBundle, request).then(() => {
	console.info("publishAsBundle success");
}).catch((err: BusinessError) => {
    console.error(`publishAsBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.cancelAsBundle

cancelAsBundle(id: number, representativeBundle: string, userId: number, callback: AsyncCallback\<void\>): void

Cancels a notification published through the reminder agent. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER or ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name              | Type         | Mandatory| Description                    |
| -------------------- | ------------- | ---- | ------------------------ |
| id                   | number        | Yes  | Notification ID.                |
| representativeBundle | string        | Yes  | Bundle name of the application whose notification function is taken over by the reminder agent.      |
| userId               | number        | Yes  | User ID.      |
| callback             | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600007  | The notification does not exist.      |
| 1600008  | The user does not exist.              |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// cancelAsBundle
let cancelAsBundleCallback = (err: BusinessError): void => {
    if (err) {
        console.error(`cancelAsBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("cancelAsBundle success");
    }
}
// Bundle name of the application whose notification function is taken over by the reminder agent
let representativeBundle: string = "com.example.demo";
// Use the actual user ID when calling the API.
let userId: number = 100;
notificationManager.cancelAsBundle(0, representativeBundle, userId, cancelAsBundleCallback);
```

## notificationManager.cancelAsBundle

cancelAsBundle(id: number, representativeBundle: string, userId: number): Promise\<void\>

Cancels a notification published through the reminder agent. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER or ohos.permission.NOTIFICATION_AGENT_CONTROLLER

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600007  | The notification does not exist.      |
| 1600008  | The user does not exist.              |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Bundle name of the application whose notification function is taken over by the reminder agent
let representativeBundle: string = "com.example.demo";
// Use the actual user ID when calling the API.
let userId: number = 100;
notificationManager.cancelAsBundle(0, representativeBundle, userId).then(() => {
	console.info("cancelAsBundle success");
}).catch((err: BusinessError) => {
    console.error(`cancelAsBundle failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.cancelAsBundle<sup>12+</sup>

cancelAsBundle(representativeBundle: BundleOption, id: number): Promise\<void\>

Cancels a notification published through the reminder agent. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER or ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API.

**Parameters**


| Name              | Type                                       | Mandatory| Description                                         |
| -------------------- | ------------------------------------------- | ---- | --------------------------------------------- |
| representativeBundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)  |Yes  | Bundle information of the application whose notification function is taken over by the reminder agent.|
| id                   | number                                     | Yes  | Notification ID.          |

**Return value**

| Type             | Description       | 
|-----------------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect to the service.                |
| 1600007  | The notification does not exist.            |
| 1600008  | The user does not exist.                    |
| 1600012  | No memory space.                          |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let representativeBundle: notificationManager.BundleOption = {
  bundle: "bundleName1",
};
notificationManager.cancelAsBundle(representativeBundle, 1).then(() => {
	console.info("cancelAsBundle success");
}).catch((err: BusinessError) => {
    console.error(`cancelAsBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.cancel<sup>12+</sup>

cancel(representativeBundle: BundleOption, id: number): Promise\<void\>

Cancels the notification of other applications of the user. This API uses a promise to return the result.

The current application must have a proxy relationship with another application, or the **ohos.permission.NOTIFICATION_AGENT_CONTROLLER** permission is granted to the current application.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

**Parameters**

| Name              | Type  | Mandatory| Description              |
| -------------------- | ------ | ---- | ------------------ |
| representativeBundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.          |
|       id             | number | Yes  | Notification ID.|

**Return value**

| Type             | Description       | 
|-----------------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600007  | The notification does not exist.      |
| 1600012  | No memory space.                    |
| 1600017  | There is no corresponding agent relationship configuration.    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
  bundle: "bundleName"
};
let id: number = 1;
notificationManager.cancel(bundle, id).then(() => {
  console.info("cancel success");
}).catch((err: BusinessError) => {
  console.error(`cancel failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setNotificationEnableSlot 

setNotificationEnableSlot(bundle: BundleOption, type: SlotType, enable: boolean, callback: AsyncCallback\<void>): void

Sets the enabled status of a slot type for the specified application. This API uses an asynchronous callback to return the result.

This API is not supported on wearables.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600012  | No memory space.                         |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// setNotificationEnableSlot
let setNotificationEnableSlotCallback = (err: BusinessError): void => {
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

This API is not supported on wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                         | Mandatory| Description                    |
| -------- | ----------------------------- | ---- | ----------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|
| type     | [SlotType](./js-apis-notificationManager.md#slottype)         | Yes  | Notification slot type.          |
| enable   | boolean                       | Yes  | Whether to enable the notification slot type. The value **true** means to enable the notification slot type, and **false** means the opposite.              |
| isForceControl<sup>11+</sup> | boolean                 | Yes  | Whether the slot is affected by the notification authorization. The value **true** means the slot is affected, and **false** means the opposite.|
| callback | AsyncCallback\<void\>         | Yes  | Callback used to return the result.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600012  | No memory space.                         |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let setNotificationEnableSlotCallback = (err: BusinessError): void => {
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

This API is not supported on wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.  |
| type   | [SlotType](./js-apis-notificationManager.md#slottype)         | Yes  | Notification slot type.|
| enable | boolean                       | Yes  | Whether to enable the notification slot type. The value **true** means to enable the notification slot type, and **false** means the opposite.    |
| isForceControl<sup>11+</sup> | boolean               | No  | Whether the enabled status of the notification slot is subject to the enabled status of notification. The value **false** means that the enabled status of the notification slot is subject to the enabled status of notification, and **true** means the opposite. Default value: **false**    |

**Return value**

| Type    | Description        |
| ------- |------------|
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600012  | No memory space.                         |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// setNotificationEnableSlot
notificationManager.setNotificationEnableSlot(
    { bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION,
    true).then(() => {
        console.info("setNotificationEnableSlot success");
    }).catch((err: BusinessError) => {
        console.error(`setNotificationEnableSlot failed, code is ${err.code}, message is ${err.message}`);
    });
```

## notificationManager.isNotificationSlotEnabled

isNotificationSlotEnabled(bundle: BundleOption, type: SlotType, callback: AsyncCallback\<boolean\>): void

Checks whether a specified notification slot type is enabled for a specified application. This API uses an asynchronous callback to return the result.

This API is not supported on wearables.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// isNotificationSlotEnabledCallback
let isNotificationSlotEnabledCallback = (err: BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isNotificationSlotEnabled failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`isNotificationSlotEnabled success, data is ${JSON.stringify(data)}`);
    }
};

notificationManager.isNotificationSlotEnabled(
    { bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION,
    isNotificationSlotEnabledCallback);
```

## notificationManager.isNotificationSlotEnabled

isNotificationSlotEnabled(bundle: BundleOption, type: SlotType): Promise\<boolean\>  

Checks whether a specified notification slot type is enabled for a specified application. This API uses a promise to return the result.

This API is not supported on wearables.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// isNotificationSlotEnabled
notificationManager.isNotificationSlotEnabled({ bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION).then((data: boolean) => {
    console.info(`isNotificationSlotEnabled success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isNotificationSlotEnabled failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.setSyncNotificationEnabledWithoutApp

setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether to enable the notification sync feature for devices where the application is not installed. This API uses an asynchronous callback to return the result.

This API is not supported on TVs and wearables.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Use the actual user ID when calling the API.
let userId: number = 100;
let enable: boolean = true;
let setSyncNotificationEnabledWithoutAppCallback = (err: BusinessError): void => {
    if (err) {
        console.error(`setSyncNotificationEnabledWithoutApp failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setSyncNotificationEnabledWithoutApp success");
    }
}
notificationManager.setSyncNotificationEnabledWithoutApp(userId, enable, setSyncNotificationEnabledWithoutAppCallback);
```


## notificationManager.setSyncNotificationEnabledWithoutApp

setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean): Promise\<void>

Sets whether to enable the notification sync feature for devices where the application is not installed. This API uses a promise to return the result.

This API is not supported on TVs and wearables.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Use the actual user ID when calling the API.
let userId: number = 100;
let enable: boolean = true;
notificationManager.setSyncNotificationEnabledWithoutApp(userId, enable).then(() => {
    console.info('setSyncNotificationEnabledWithoutApp success');
}).catch((err: BusinessError) => {
    console.error(`setSyncNotificationEnabledWithoutApp failed, code is ${err.code}, message is ${err.message}`);
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Use the actual user ID when calling the API.
let userId: number = 100;
let getSyncNotificationEnabledWithoutAppCallback = (err: BusinessError, data: boolean): void => {
    if (err) {
        console.error(`getSyncNotificationEnabledWithoutAppCallback failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getSyncNotificationEnabledWithoutAppCallback success, data: ${JSON.stringify(data)}`);
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600008  | The user does not exist.              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Use the actual user ID when calling the API.
let userId: number = 100;
notificationManager.getSyncNotificationEnabledWithoutApp(userId).then((data: boolean) => {
  console.info(`getSyncNotificationEnabledWithoutApp, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSyncNotificationEnabledWithoutApp failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.on<sup>10+</sup>

on(type: 'checkNotification', callback: (checkInfo: NotificationCheckInfo) => NotificationCheckResult): void

Subscribes to notification events. The notification service sends the notification information in the callback to the verification program. The verification program returns the verification result to determine whether to publish the notification, for example, controlling the publish frequency of marketing notifications.

Each [SlotType](./js-apis-notificationManager.md#slottype) in the system can have only one registrant.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER, ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name| Type                                                                                                                     | Mandatory| Description          |
| ------ |-------------------------------------------------------------------------------------------------------------------------| ---- | -------------- |
| type | string                                                                                                                  | Yes  | Event type. The value is fixed to **'checkNotification'**.|
| callback | (checkInfo: [NotificationCheckInfo](#notificationcheckinfo10)) =>  [NotificationCheckResult](#notificationcheckresult10) | Yes  | Pointer to the notification verification function.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- | 
| 202      | Not system application.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
} catch (err: BusinessError){
    console.error(`notificationManager.on failed, code is ${err.code}, message is ${err.message}`);
}
```

## notificationManager.on<sup>11+</sup>

on(type: 'checkNotification', checkRequest: NotificationCheckRequest, callback: (checkInfo: NotificationCheckInfo) => Promise\<NotificationCheckResult\>): void

Subscribes to notification events. The notification service sends the notification information in the callback to the verification program. The verification program returns the verification result to determine whether to publish the notification, for example, controlling the publish frequency of marketing notifications. This API uses a promise to return the result.

Each [SlotType](./js-apis-notificationManager.md#slottype) in the system can have only one registrant.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try{
  notificationManager.on('checkNotification',{
    contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_LIVE_VIEW,
    slotType: notificationManager.SlotType.LIVE_VIEW ,
    extraInfoKeys: ["event"],
  },
    async (checkInfo)=>{
      return { code: 1, message: "INVALID_PARAMETERS"};
  },);
} catch (err) {
  console.error(`notificationManager.on failed, code is ${err.code}, message is ${err.message}`);
}
```

## notificationManager.off<sup>10+</sup>

off(type: 'checkNotification', callback?: (checkInfo: NotificationCheckInfo) => NotificationCheckResult): void

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | The application does not have permission to call the interface.    |
| 202      | Not system application.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 1600001  | Internal error.                     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try{
    notificationManager.off("checkNotification");
} catch (err: BusinessError){
    console.error(`notificationManager.off failed, code is ${err.code}, message is ${err.message}`);
}
```

## notificationManager.triggerSystemLiveView<sup>11+</sup>

triggerSystemLiveView(bundle: BundleOption, notificationId: number, buttonOptions: ButtonOptions): Promise\<void>

Triggers a system live view notification. This API uses a promise to return the result.

This API is not supported on wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name| Type                  | Mandatory| Description          |
| -------------- | ------------- | ---- | -------------- |
| bundle         | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)  | Yes  |Bundle information of the application.|
| notificationId | number        | Yes  | Notification ID.|
| buttonOptions  | [ButtonOptions](#buttonoptions11) | Yes  | Button information.|

**Return value**

| Type| Description|
| ---- | ----|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600007  | The notification does not exist.      |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Bundle information
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
}).catch((err: BusinessError) => {
  console.error(`triggerSystemLiveView failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.subscribeSystemLiveView<sup>11+</sup>

subscribeSystemLiveView(subscriber: SystemLiveViewSubscriber): Promise\<void>

Subscribes to the system live view notification. This API uses a promise to return the result.

This API is not supported on wearables.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let onResponseCallback = (id:number, option:notificationManager.ButtonOptions) => {
    console.info(`notificationId: ${id},onResponseCallback: ${JSON.stringify(option)}`);
}
let subscriber: notificationManager.SystemLiveViewSubscriber  = {
    onResponse: onResponseCallback,
};
notificationManager.subscribeSystemLiveView(subscriber).then(() => {
	console.info("subscribeSystemLiveView success");
}).catch((err: BusinessError) => {
    console.error(`subscribeSystemLiveView failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setDistributedEnabledByBundle<sup>12+</sup>

setDistributedEnabledByBundle(bundle: BundleOption, deviceType: string, enable: boolean): Promise<void\>

Sets whether a specified application supports cross-device collaboration. This API uses a promise to return the result.

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | Yes  | Bundle information of the application.                  |
| deviceType | string | Yes  | Device type.|
| enable   | boolean                  | Yes  | Whether to enable cross-device collaboration. The value **true** means to enable distributed notification, and **false** means the opposite.|

**Return value**

| Type| Description|
| ---- | ----|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600010  | Distributed operation failed.            |
| 1600012  | No memory space.                    |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
    uid: 1
};
let enable: boolean = true;
let deviceType: string = "phone";
notificationManager.setDistributedEnabledByBundle(bundle, deviceType, enable).then(() => {
    console.info("setDistributedEnabledByBundle success");
}).catch((err: BusinessError) => {
    console.error(`setDistributedEnabledByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.isDistributedEnabledByBundle<sup>12+</sup>

isDistributedEnabledByBundle(bundle: BundleOption, deviceType: string): Promise<boolean\>

Obtains whether a specified application supports cross-device collaboration. This API uses a promise to return the result.

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | Yes  | Bundle information of the application.                  |
| deviceType | string | Yes  | Device type.|

**Return value**

| Type| Description|
| ---- | ----|
| Promise\<boolean\> | Promise used to return the result (true: enabled; false: disabled).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600010  | Distributed operation failed.            |
| 1600012  | No memory space.                    |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
    uid: 1
};
let deviceType: string = "phone";
notificationManager.isDistributedEnabledByBundle(bundle, deviceType).then((data: boolean) => {
    console.info(`isDistributedEnabledByBundle success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isDistributedEnabledByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setSmartReminderEnabled<sup>12+</sup>

setSmartReminderEnabled(deviceType: string, enable: boolean): Promise<void\>

Sets a smart reminder for cross-device collaboration. This API uses a promise to return the result.

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| deviceType | string | Yes  | Device type.|
| enable   | boolean                  | Yes  | Indicates whether the specified application supports a smart reminder for cross-device collaboration (**true**: enabled; **false**: disabled).|

**Return value**

| Type| Description|
| ---- | ----|
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600010  | Distributed operation failed.            |
| 1600012  | No memory space.                    |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let deviceType: string = "phone";
let enable: boolean = true;
notificationManager.setSmartReminderEnabled(deviceType, enable).then(() => {
    console.info("setSmartReminderEnabled success");
}).catch((err: BusinessError) => {
    console.error(`setSmartReminderEnabled failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.isSmartReminderEnabled<sup>12+</sup>

isSmartReminderEnabled(deviceType: string): Promise<boolean\>

Obtains a smart reminder for cross-device collaboration. This API uses a promise to return the result.

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| deviceType | string | Yes  | Device type.|

**Return value**

| Type| Description|
| ---- | ----|
| Promise\<boolean\> | Promise used to return the result (**true**: enabled; **false**: disabled).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600010  | Distributed operation failed.            |
| 1600012  | No memory space.                    |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let deviceType: string = "phone";
notificationManager.isSmartReminderEnabled(deviceType).then((data: boolean) => {
    console.info(`isSmartReminderEnabled success, data:${data}`);
}).catch((err: BusinessError) => {
    console.error(`isSmartReminderEnabled failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setBadgeNumberByBundle<sup>12+</sup>

setBadgeNumberByBundle(bundle: BundleOption, badgeNumber: number): Promise\<void\>

Sets the badge count for other applications. This API uses a promise to return the result.

This API is not supported on wearables.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

**Parameters**

| Name     | Type  | Mandatory| Description      |
| ----------- | ------ | ---- | ---------- |
| bundle | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|
| badgeNumber | number | Yes  | Notification badge number to set.|

**Return value**

| Type           | Description                     |
| --------------- | ------------------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                    |
| 1600017  | There is no corresponding agent relationship configuration.     |
| 17700001 | The specified bundle name was not found.   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: 'com.example.bundleName',
};
let badgeNumber: number = 10;

notificationManager.setBadgeNumberByBundle(bundle, badgeNumber).then(() => {
    console.info('setBadgeNumberByBundle success');
}).catch((err: BusinessError) => {
    console.error(`setBadgeNumberByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.getSlotByBundle<sup>12+</sup>

getSlotByBundle(bundle: BundleOption, slotType: SlotType): Promise\<NotificationSlot>

Obtains a notification slot of a specified application. This API uses a promise to return the result.

This API is not supported on wearables.

Before obtaining the notification slot, create a slot through [addSlot](#notificationmanageraddslot).

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the application.|
| slotType | [SlotType](././js-apis-notificationManager.md#slottype) | Yes  | Notification slot type.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[NotificationSlot](js-apis-inner-notification-notificationSlot-sys.md)> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect to the service.               |
| 1600012  | No memory space.                         |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bundle: notificationManager.BundleOption = {
    bundle: "bundleName1",
};

let slotType = notificationManager.SlotType.LIVE_VIEW;

notificationManager.getSlotByBundle(bundle, slotType).then((data: notificationManager.NotificationSlot) => {
	console.info(`getSlotByBundle success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSlotByBundle failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.addDoNotDisturbProfile<sup>12+</sup>

addDoNotDisturbProfile(templates: Array\<DoNotDisturbProfile>): Promise\<void\>

Adds the Do Not Disturb profile configuration information. This API uses a promise to return the result.

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type            | Mandatory| Description          |
| ------ | ---------------- | ---- | -------------- |
| templates   | Array\<[DoNotDisturbProfile](#donotdisturbprofile12)> | Yes| Configuration information about the Do Not Disturb profile.|

**Return value**

| Type     | Description       |
|---------|-----------|
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let trustlist: Array<notificationManager.BundleOption> = [
  {
    bundle: 'com.example.bundleName',
    uid: 0
  },
  {
    bundle: 'com.example.bundleName1',
    uid: 1
  }
]
let templates: Array<notificationManager.DoNotDisturbProfile> = [
  {
    id: 3,
    name: 'working mode',
    trustlist: trustlist
  }
]

notificationManager.addDoNotDisturbProfile(templates).then(() => {
  console.info("addDoNotDisturbProfile success.");
}).catch((err: BusinessError) => {
  console.error(`addDoNotDisturbProfile failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.removeDoNotDisturbProfile<sup>12+</sup>

removeDoNotDisturbProfile(templates: Array\<DoNotDisturbProfile>): Promise\<void\>

Deletes the Do Not Disturb profile configuration. This API uses a promise to return the result.

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type            | Mandatory| Description          |
| ------ | ---------------- | ---- | -------------- |
| templates   | Array\<[DoNotDisturbProfile](#donotdisturbprofile12)> | Yes | Configuration information about the Do Not Disturb profile.|

**Return value**

| Type     | Description       |
|---------|-----------|
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600012  | No memory space.                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let templates: Array<notificationManager.DoNotDisturbProfile> = [
  {
    id: 3,
    name: 'working mode'
  }
]
notificationManager.removeDoNotDisturbProfile(templates).then(() => {
  console.info("removeDoNotDisturbProfile success.");
}).catch((err: BusinessError) => {
  console.error(`removeDoNotDisturbProfile failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setAdditionalConfig<sup>12+</sup>

setAdditionalConfig(key: string, value: string): Promise\<number\>

Sets the additional system configuration information of the notification. This API uses a promise to return the result.

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type            | Mandatory| Description          |
| ------ | ---------------- | ---- | -------------- |
| key   | string | Yes | Additional configuration key. Currently, only **RING_TRUSTLIST_PKG** is supported, indicating that the application supports [customized ring tone](./js-apis-inner-notification-notificationRequest.md#notificationrequest-1).|
| value   | string | Yes | Additional configuration value. Example: [bundleName1,bundleName2].|

**Return value**

| Type     | Description       |
|---------|-----------|
| Promise\<number\> | Promise used to return the result. **0** indicates successful; other values indicate failed.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |  
| 202      | Not system application to call the interface.                                      |  
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

notificationManager.setAdditionalConfig('RING_TRUSTLIST_PKG','[bundleName1,bundleName2]').then((data: number) => {
  console.info(`setAdditionalConfig success, data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`setAdditionalConfig failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.getDoNotDisturbProfile<sup>13+</sup>

getDoNotDisturbProfile(id: number): Promise\<DoNotDisturbProfile\>

Queries the configuration information about the Do Not Disturb profile. This API uses a promise to return the result.

This API is not supported on TVs and wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type            | Mandatory| Description          |
| ------ | ---------------- | ---- | -------------- |
| id   | number | Yes | ID of the Do Not Disturb profile.|

**Return value**

| Type     | Description       |
|---------|-----------|
| Promise\<[DoNotDisturbProfile](#donotdisturbprofile12)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 201      | Permission denied.     |
| 202      | Not system application to call the interface.                                      |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 801 | Capability not supported. |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect to the service.          |
| 1600019  | The do-not-disturb profile does not exist.                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

notificationManager.getDoNotDisturbProfile(1).then((data: notificationManager.DoNotDisturbProfile) => {
  console.info(`getDoNotDisturbProfile success: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`getDoNotDisturbProfile failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.disableNotificationFeature<sup>18+</sup>

disableNotificationFeature(disabled: boolean, bundleList: Array\<string\>): Promise\<void\>

Disables the application from publishing notifications by adding the application bundle name to the permission control list. This function can be disabled as required.

This API is not supported on wearables.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER or ohos.permission.MANAGE_EDM_POLICY

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                    |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| disabled | boolean | Yes  | Whether to enable the permission control list for publishing notifications (**true**: enabled; **false**: disabled).|
| bundleList | Array\<string\> | Yes  | Application list under the permission control list. The bundle name is used to represent the application.|

**Return value**

| Type           | Description                    | 
|-----------------|-------------------------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801 | Capability not supported. | 
| 1600001      | Internal error.                     |
| 1600002      | Marshalling or unmarshalling error. |

**Example**

```ts
import { notificationManager } from '@kit.NotificationKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let disabled: boolean = true;
let bundleList: Array<string> = ["com.example.myapplication"];
try {
  notificationManager.disableNotificationFeature(disabled, bundleList).then(() => {
    hilog.info(0x0000, 'testTag', '%{public}s', `disableNotificationFeature success.`);
  }).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', '%{public}s', `disableNotificationFeature failed, code is ${err.code}, message is ${err.message}`);
  });
} catch (err) {
  hilog.error(0x0000, 'testTag', '%{public}s', `testTag failed, code is ${err.code}, message is ${err.message}`);
}
```

## notificationManager.setTargetDeviceStatus<sup>18+</sup>

setTargetDeviceStatus(deviceType: string, status: number): Promise\<void\>

Sets the status of a device after it is successfully connected. Device status determines the notification mode of the current device when a notification is published.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                    |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| deviceType | string | Yes  | Device type. Currently, only **headset** (wearable audio device), **liteWearable** (lite wearables), **wearable** (smart wearables), and **current** (local device) are supported.|
| status | number | Yes  | Device status.<br>- Bit 0: whether the device is in use. The value **0** indicates that the device is available; **1** indicates that the device is in use.<br>- Bit 1: whether the device user is the owner. The value **0** indicates that the user is not the owner; **1** indicates the opposite.<br>- Bit 2: whether the device is in the Do Not Disturb mode. The value **0** indicates that the device is not in the Do Not Disturb mode; **1** indicates the opposite.|

**Return value**

| Type           | Description                    | 
|-----------------|-------------------------|
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

notificationManager.setTargetDeviceStatus("current", 1).then(() => {
  console.info(`Succeeded in setting target device status.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set target device status. Code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.setDistributedEnabledBySlot<sup>18+</sup>

setDistributedEnabledBySlot(slot: SlotType, deviceType: string, enabled: boolean): Promise\<void\>

Sets whether the notification of a specified slot can be sent to devices of a specified type through cross-device collaboration. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                    |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| slot | [SlotType](js-apis-notificationManager.md#slottype) | Yes  | Types of the notification slot.|
| deviceType | string | Yes  | Device type. The value can be **wearable**, **litewearable**, or **headset**.|
| enabled | boolean | Yes  | Whether to enable cross-device collaboration for notifications. The value **true** indicates that the function is enabled; **false** indicates the opposite.|

**Return value**

| Type           | Description                    | 
|-----------------|-------------------------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { notificationManager } from '@kit.NotificationKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let slot: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
let deviceType: string = 'wearable';
let enabled: boolean = true;

notificationManager.setDistributedEnabledBySlot(slot, deviceType, enabled).then(() => {
    hilog.info(0x0000, 'testTag', '%{public}s', `setDistributedEnabledBySlot success.`);
}).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', '%{public}s', `setDistributedEnabledBySlot failed, code is ${err.code}, message is ${err.message}`);
});
```

## notificationManager.isDistributedEnabledBySlot<sup>18+</sup>

isDistributedEnabledBySlot(slot: SlotType, deviceType: string): Promise\<boolean\>

Queries whether notifications of a specified slot can be sent to devices of a specified type through cross-device collaboration. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                        | Mandatory| Description                    |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| slot | [SlotType](js-apis-notificationManager.md#slottype) | Yes  | Types of the notification slot.|
| deviceType | string | Yes  | Device type. The value can be **wearable**, **litewearable**, or **headset**.|

**Return value**

| Type           | Description                    | 
|-----------------|-------------------------|
| Promise\<boolean\> | Promise used to return the result. The value **true** indicates that cross-device collaboration is supported; **false** indicates the opposite.| 

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { notificationManager } from '@kit.NotificationKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let slot: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
let deviceType: string = 'wearable';

notificationManager.isDistributedEnabledBySlot(slot, deviceType).then((data: boolean) => {
    hilog.info(0x0000, 'testTag', '%{public}s', `isDistributedEnabledBySlot success.`);
}).catch((err: BusinessError) => {
    hilog.error(0x0000, 'testTag', '%{public}s', `isDistributedEnabledBySlot failed, code is ${err.code}, message is ${err.message}`);
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
| extraInfos<sup>11+</sup>     | [key: string]: object        | No  | Extra information about the live view.|

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
| onResponse    | (notificationId: number, buttonOptions: [ButtonOptions](#buttonoptions11)) => void                         | No  | Callback when the button is touched.|


## SlotType

**System capability**: SystemCapability.Notification.Notification

| Name                               | Value    | Description                                                        |
| ----------------------------------- | ------ | ------------------------------------------------------------ |
| EMERGENCY_INFORMATION<sup>12+</sup> | 10     | Emergency event. **System API**: This is a system API.                              |


## NotificationControlFlagStatus<sup>12+</sup>
Each bit can control the notification mode. When the bitwise OR operation is performed on **notificationControlFlags** and the enumerated values in the following table, the notification mode is disabled.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

| Name                                | Value  | Description    |
| ------------------------------------ | ---- | -------- |
| NOTIFICATION_STATUS_CLOSE_SOUND      | 1<<0 | Disables the sound notification function.|
| NOTIFICATION_STATUS_CLOSE_LOCKSCREEN |  1<<1    |     Disables the screen lock notification function.    |
| NOTIFICATION_STATUS_CLOSE_BANNER     |    1<<2   |     Disables the banner notification function.    |
| NOTIFICATION_STATUS_CLOSE_LIGHT_SCREEN     |   1<<3   |     Disables the screen-on notification function.    |
| NOTIFICATION_STATUS_CLOSE_VIBRATION     |   1<<4   |     Disables the vibration notification function.    |
| NOTIFICATION_STATUS_CLOSE_STATUSBAR_ICON     |  1<<5    |     Disables the icon notification function in the status bar.    |

## DoNotDisturbProfile<sup>12+</sup>

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

| Name | Type                                 | Mandatory| Description                  |
| ----- | ------------------------------------- | ---- | ---------------------- |
| id | number | Yes| ID of the Do Not Disturb profile.|
| name | string  | Yes| Name of the Do Not Disturb profile.|
| trustlist | Array\<[BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)> | No| Trustlist in Do Not Disturb profile.|

## NotificationLiveViewContent<sup>11+</sup>

type NotificationLiveViewContent = _NotificationLiveViewContent

Describes the common live view.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

| Type| Description|
| --- | --- |
| [_NotificationLiveViewContent](js-apis-inner-notification-notificationContent-sys.md#notificationliveviewcontent11) | Common live view.|
