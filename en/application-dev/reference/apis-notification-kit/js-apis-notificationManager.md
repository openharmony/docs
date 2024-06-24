# @ohos.notificationManager (NotificationManager)

The **NotificationManager** module provides notification management capabilities, covering notifications, notification slots, notification enabled status, and notification badge status.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import notificationManager from '@ohos.notificationManager';
```

## notificationManager.publish

publish(request: NotificationRequest, callback: AsyncCallback\<void\>): void

Publish a notification. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                                       | Mandatory| Description                                       |
| -------- | ------------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | Yes  | Content and related configuration of the notification to publish.|
| callback | AsyncCallback\<void\>                       | Yes  | Callback used to return the result.                       |

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
notificationManager.publish(notificationRequest, publishCallback);
```

## notificationManager.publish

publish(request: NotificationRequest): Promise\<void\>

Publish a notification. This API uses a promise to return the URI of the file in the destination directory.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                                       | Mandatory| Description                                       |
| -------- | ------------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | Yes  | Content and related configuration of the notification to publish.|

**Return value**

| Type    | Description| 
| ------- |--|
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
| 1600009  | Over max number notifications per second.            |
| 1600012  | No memory space.                                     |
| 1600014  | No relevant right.                                   |
| 1600015  | The current notification status does not support duplicate configurations. |
| 1600016  | The notification version for this update is too low. |
| 2300007  | Network is unreachable.                              |

**Example**

```ts
import Base from '@ohos.base';

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
notificationManager.publish(notificationRequest).then(() => {
	console.info("publish success");
}).catch((err: Base.BusinessError) => {
    console.error(`publish fail: ${JSON.stringify(err)}`);
});

```

## notificationManager.cancel

cancel(id: number, label: string, callback: AsyncCallback\<void\>): void

Cancels a notification with the specified ID and label. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| id       | number                | Yes  | Notification ID.              |
| label    | string                | Yes  | Notification label.            |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**Example**

```ts
import Base from '@ohos.base';

// cancel callback
let cancelCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`cancel failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("cancel success");
    } 
}
notificationManager.cancel(0, "label", cancelCallback);
```

## notificationManager.cancel

cancel(id: number, label?: string): Promise\<void\>

Cancels a notification with the specified ID and optional label. This API uses a promise to return the URI of the file in the destination directory.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name | Type  | Mandatory| Description    |
| ----- | ------ | ---- | -------- |
| id    | number | Yes  | Notification ID.  |
| label | string | No  | Notification label. This parameter is left empty by default.|

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
| 1600007  | The notification is not exist.      |

**Example**

```ts
import Base from '@ohos.base';

notificationManager.cancel(0).then(() => {
	console.info("cancel success");
}).catch((err: Base.BusinessError) => {
    console.error(`cancel fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.cancel

cancel(id: number, callback: AsyncCallback\<void\>): void

Cancels a notification with the specified ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| id       | number                | Yes  | Notification ID.              |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**Example**

```ts
import Base from '@ohos.base';

// cancel callback
let cancelCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`cancel failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("cancel success");
    }
}
notificationManager.cancel(0, cancelCallback);
```

## notificationManager.cancelAll

cancelAll(callback: AsyncCallback\<void\>): void

Cancels all notifications of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```ts
import Base from '@ohos.base';

// cancel callback
let cancelAllCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`cancelAll failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("cancelAll success");
    }
}
notificationManager.cancelAll(cancelAllCallback);
```

## notificationManager.cancelAll

cancelAll(): Promise\<void\>

Cancels all notifications of this application. This API uses a promise to return the URI of the file in the destination directory.

**System capability**: SystemCapability.Notification.Notification

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

**Example**

```ts
import Base from '@ohos.base';

notificationManager.cancelAll().then(() => {
	console.info("cancelAll success");
}).catch((err: Base.BusinessError) => {
    console.error(`cancelAll fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.addSlot

addSlot(type: SlotType, callback: AsyncCallback\<void\>): void

Adds a notification slot of a specified type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                 | Mandatory| Description                  |
| -------- | --------------------- | ---- | ---------------------- |
| type     | [SlotType](#slottype)              | Yes  | Type of the notification slot to add.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.  |

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

// addSlot callback
let addSlotCallBack = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`addSlot failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("addSlot success");
    }
}
notificationManager.addSlot(notificationManager.SlotType.SOCIAL_COMMUNICATION, addSlotCallBack);
```

## notificationManager.addSlot

addSlot(type: SlotType): Promise\<void\>

Adds a notification slot of a specified type. This API uses a promise to return the URI of the file in the destination directory.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name| Type    | Mandatory| Description                  |
| ---- | -------- | ---- | ---------------------- |
| type | [SlotType](#slottype) | Yes  | Type of the notification slot to add.|

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
| 1600012  | No memory space.                    |

**Example**

```ts
import Base from '@ohos.base';

notificationManager.addSlot(notificationManager.SlotType.SOCIAL_COMMUNICATION).then(() => {
	console.info("addSlot success");
}).catch((err: Base.BusinessError) => {
    console.error(`addSlot fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.getSlot

getSlot(slotType: SlotType, callback: AsyncCallback\<NotificationSlot\>): void

Obtains a notification slot of a specified type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                             | Mandatory| Description                                                       |
| -------- | --------------------------------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype)                          | Yes  | Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|
| callback | AsyncCallback\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\> | Yes  | Callback used to return the result.                                       |

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

// getSlot callback
let getSlotCallback = (err: Base.BusinessError, data: notificationManager.NotificationSlot): void => {
    if (err) {
        console.error(`getSlot failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getSlot success, data is ${JSON.stringify(data)}`);
    }
}
let slotType: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
notificationManager.getSlot(slotType, getSlotCallback);
```

## notificationManager.getSlot

getSlot(slotType: SlotType): Promise\<NotificationSlot\>

Obtains a notification slot of a specified type. This API uses a promise to return the URI of the file in the destination directory.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type    | Mandatory| Description                                                       |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype) | Yes  | Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\> | Promise used to return the result.|

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

let slotType: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;

notificationManager.getSlot(slotType).then((data: notificationManager.NotificationSlot) => {
    console.info("getSlot success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getSlot fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.getSlots

getSlots(callback: AsyncCallback\<Array\<NotificationSlot>>): void

Obtains all notification slots of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                             | Mandatory| Description                |
| -------- | --------------------------------- | ---- | -------------------- |
| callback | AsyncCallback\<Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\>\> | Yes  | Callback used to return all notification slots of the current application.|

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

// getSlots callback
let getSlotsCallback = (err: Base.BusinessError, data: Array<notificationManager.NotificationSlot>): void => {
  if (err) {
    console.error(`getSlots failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info(`getSlots success, data is ${JSON.stringify(data)}`);
  }
}
notificationManager.getSlots(getSlotsCallback);
```

## notificationManager.getSlots

getSlots(): Promise\<Array\<NotificationSlot>>

Obtains all notification slots of this application. This API uses a promise to return the URI of the file in the destination directory.

**System capability**: SystemCapability.Notification.Notification

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\>\> | Promise used to return all notification slots of the current application.|

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

notificationManager.getSlots().then((data: Array<notificationManager.NotificationSlot>) => {
	console.info("getSlots success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getSlots fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.removeSlot

removeSlot(slotType: SlotType, callback: AsyncCallback\<void\>): void

Removes a notification slot of a specified type for this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                 | Mandatory| Description                                                       |
| -------- | --------------------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype)              | Yes  | Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.                                       |

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

// removeSlot callback
let removeSlotCallback = (err: Base.BusinessError): void => {
  if (err) {
    console.error(`removeSlot failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.info("removeSlot success");
  }
}
let slotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
notificationManager.removeSlot(slotType, removeSlotCallback);
```

## notificationManager.removeSlot

removeSlot(slotType: SlotType): Promise\<void\>

Removes a notification slot of a specified type for this application. This API uses a promise to return the URI of the file in the destination directory.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type    | Mandatory| Description                                                       |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype) | Yes  | Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|

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

**Example**

```ts
import Base from '@ohos.base';

let slotType: notificationManager.SlotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
notificationManager.removeSlot(slotType).then(() => {
	console.info("removeSlot success");
}).catch((err: Base.BusinessError) => {
    console.error(`removeSlot fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.removeAllSlots

removeAllSlots(callback: AsyncCallback\<void\>): void

Removes all notification slots for this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

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

let removeAllSlotsCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`removeAllSlots failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeAllSlots success");
    }
}
notificationManager.removeAllSlots(removeAllSlotsCallback);
```

## notificationManager.removeAllSlots

removeAllSlots(): Promise\<void\>

Removes all notification slots for this application. This API uses a promise to return the URI of the file in the destination directory.

**System capability**: SystemCapability.Notification.Notification

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

**Example**

```ts
import Base from '@ohos.base';

notificationManager.removeAllSlots().then(() => {
	console.info("removeAllSlots success");
}).catch((err: Base.BusinessError) => {
    console.error(`removeAllSlots fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(callback: AsyncCallback\<boolean\>): void

Checks whether notification is enabled for the specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                 | Mandatory| Description                    |
| -------- | --------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600008  | The user does not exist.                   |
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

notificationManager.isNotificationEnabled(isNotificationEnabledCallback);
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(): Promise\<boolean\>

Checks whether notification is enabled for the specified application. This API uses a promise to return the URI of the file in the destination directory.

**System capability**: SystemCapability.Notification.Notification

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
| 1600008  | The user does not exist.                   |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
import Base from '@ohos.base';

notificationManager.isNotificationEnabled().then((data: boolean) => {
	console.info("isNotificationEnabled success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`isNotificationEnabled fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setBadgeNumber<sup>10+</sup>

setBadgeNumber(badgeNumber: number): Promise\<void\>

Sets the notification badge number. This API uses a promise to return the URI of the file in the destination directory.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name     | Type  | Mandatory| Description      |
| ----------- | ------ | ---- | ---------- |
| badgeNumber | number | Yes  | Notification badge number to set.|

**Return value**

| Type     | Description       | 
|---------|-----------|
| Promise\<void\> | Promise that returns no value.| 

**Error codes**

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**Example**

```ts
import Base from '@ohos.base';

let badgeNumber: number = 10;

notificationManager.setBadgeNumber(badgeNumber).then(() => {
	console.info("setBadgeNumber success");
}).catch((err: Base.BusinessError) => {
    console.error(`setBadgeNumber fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.setBadgeNumber<sup>10+</sup>

setBadgeNumber(badgeNumber: number, callback: AsyncCallback\<void\>): void

Sets the notification badge number. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name     | Type                 | Mandatory| Description              |
| ----------- | --------------------- | ---- | ------------------ |
| badgeNumber | number                | Yes  | Notification badge number to set.        |
| callback    | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

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

let setBadgeNumberCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.info(`setBadgeNumber failed code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setBadgeNumber success");
    }
}
let badgeNumber: number = 10;
notificationManager.setBadgeNumber(badgeNumber, setBadgeNumberCallback);
```

## notificationManager.getActiveNotificationCount

getActiveNotificationCount(callback: AsyncCallback\<number\>): void

Obtains the number of active notifications of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                  | Mandatory| Description                  |
| -------- | ---------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the result.|

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

let getActiveNotificationCountCallback = (err: Base.BusinessError, data: number): void => {
    if (err) {
        console.error(`getActiveNotificationCount failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info(`getActiveNotificationCount success, data is ${JSON.stringify(data)}`);
    }
}

notificationManager.getActiveNotificationCount(getActiveNotificationCountCallback);
```

## notificationManager.getActiveNotificationCount

getActiveNotificationCount(): Promise\<number\>

Obtains the number of active notifications of this application. This API uses a promise to return the URI of the file in the destination directory.

**System capability**: SystemCapability.Notification.Notification

**Return value**

| Type             | Description                                       |
| ----------------- | ------------------------------------------- |
| Promise\<number\> | Promise used to return the result.|

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

notificationManager.getActiveNotificationCount().then((data: number) => {
	console.info("getActiveNotificationCount success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getActiveNotificationCount fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.getActiveNotifications

getActiveNotifications(callback: AsyncCallback\<Array\<NotificationRequest>>): void

Obtains the active notifications of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                                                        | Mandatory| Description                          |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)>> | Yes  | Callback used to return the result.|

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

let getActiveNotificationsCallback = (err: Base.BusinessError, data: Array<notificationManager.NotificationRequest>): void => {
    if (err) {
        console.error(`getActiveNotifications failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getActiveNotifications success" + JSON.stringify(data));
    }
}
notificationManager.getActiveNotifications(getActiveNotificationsCallback);
```

## notificationManager.getActiveNotifications

getActiveNotifications(): Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)\>\>

Obtains the active notifications of this application. This API uses a promise to return the URI of the file in the destination directory.

**System capability**: SystemCapability.Notification.Notification

**Return value**

| Type                                                        | Description                                   |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)\>\> | Promise used to return the result.|

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

notificationManager.getActiveNotifications().then((data: Array<notificationManager.NotificationRequest>) => {
	console.info("getActiveNotifications success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`getActiveNotifications fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.cancelGroup

cancelGroup(groupName: string, callback: AsyncCallback\<void\>): void

Cancels notifications under a notification group of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name     | Type                 | Mandatory| Description                        |
| --------- | --------------------- | ---- | ---------------------------- |
| groupName | string                | Yes  | Name of the notification group, which is specified through [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) when the notification is published.|
| callback  | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

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

let cancelGroupCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`cancelGroup failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("cancelGroup success");
    }
}

let groupName: string = "GroupName";

notificationManager.cancelGroup(groupName, cancelGroupCallback);
```

## notificationManager.cancelGroup

cancelGroup(groupName: string): Promise\<void\>

Cancels notifications under a notification group of this application. This API uses a promise to return the URI of the file in the destination directory.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name     | Type  | Mandatory| Description          |
| --------- | ------ | ---- | -------------- |
| groupName | string | Yes  | Name of the notification group.|

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

**Example**

```ts
import Base from '@ohos.base';

let groupName: string = "GroupName";
notificationManager.cancelGroup(groupName).then(() => {
	console.info("cancelGroup success");
}).catch((err: Base.BusinessError) => {
    console.error(`cancelGroup fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.isSupportTemplate

isSupportTemplate(templateName: string, callback: AsyncCallback\<boolean\>): void

Checks whether a specified template is supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name      | Type                    | Mandatory| Description                      |
| ------------ | ------------------------ | ---- | -------------------------- |
| templateName | string                   | Yes  | Template name. Currently, only **downloadTemplate** is supported.                  |
| callback     | AsyncCallback\<boolean\> | Yes  | Callback used to return the result. The value **true** means that the specified template is supported, and **false** means the opposite.|

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

let templateName: string = 'process';
let isSupportTemplateCallback = (err: Base.BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isSupportTemplate failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isSupportTemplate success, data: " + JSON.stringify(data));
    }
}
notificationManager.isSupportTemplate(templateName, isSupportTemplateCallback);
```

## notificationManager.isSupportTemplate

isSupportTemplate(templateName: string): Promise\<boolean\>

Checks whether a specified template is supported. This API uses a promise to return the URI of the file in the destination directory.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name      | Type  | Mandatory| Description    |
| ------------ | ------ | ---- | -------- |
| templateName | string | Yes  | Template name. Currently, only **downloadTemplate** is supported.|

**Return value**

| Type              | Description           |
| ------------------ | --------------- |
| Promise\<boolean\> | Promise used to return the result. The value **true** means that the specified template is supported, and **false** means the opposite.|

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

let templateName: string = 'process';
notificationManager.isSupportTemplate(templateName).then((data: boolean) => {
    console.info("isSupportTemplate success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`isSupportTemplate fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.requestEnableNotification

requestEnableNotification(callback: AsyncCallback\<void\>): void

Requests notification to be enabled for this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600004  | Notification is not enabled.          |
| 1600013  | Enable Notification Dialog has been popping already.          |

**Example**

```ts
import Base from '@ohos.base';

let requestEnableNotificationCallback = (err: Base.BusinessError): void => {
    if (err) {
        console.error(`requestEnableNotification failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("requestEnableNotification success");
    }
};
notificationManager.requestEnableNotification(requestEnableNotificationCallback);
```

## notificationManager.requestEnableNotification

requestEnableNotification(): Promise\<void\>

Requests notification to be enabled for this application. This API uses a promise to return the URI of the file in the destination directory.

**System capability**: SystemCapability.Notification.Notification

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
| 1600004  | Notification is not enabled.          |
| 1600013  | Enable Notification Dialog has been popping already.          |

**Example**

```ts
import Base from '@ohos.base';

notificationManager.requestEnableNotification().then(() => {
    console.info("requestEnableNotification success");
}).catch((err: Base.BusinessError) => {
    console.error(`requestEnableNotification fail: ${JSON.stringify(err)}`);
});
```

## notificationManager.requestEnableNotification<sup>10+<sup>

requestEnableNotification(context: UIAbilityContext, callback: AsyncCallback\<void\>): void

Requests notification to be enabled for this application in a modal. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name  | Type                    | Mandatory| Description                |
| -------- | ------------------------ | ---- |--------------------|
| context | UIAbilityContext | Yes  | Ability context bound to the notification dialog box.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.    |

**Error codes**

For details about the error codes, see [Notification Error Codes](./errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600004  | Notification is not enabled.          |
| 1600013  | Enable Notification Dialog has been popping already.          |

**Example**

```ts
import Base from '@ohos.base';
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.Window';

class MyAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let requestEnableNotificationCallback = (err: Base.BusinessError): void => {
      if (err) {
        console.error(`requestEnableNotification failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.info("requestEnableNotification success");
      }
    };
    notificationManager.requestEnableNotification(this.context, requestEnableNotificationCallback);
  }
}
```

## notificationManager.requestEnableNotification<sup>10+<sup>

requestEnableNotification(context: UIAbilityContext): Promise\<void\>

Requests notification to be enabled for this application in a modal. This API uses a promise to return the URI of the file in the destination directory.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name  | Type                    | Mandatory| Description                |
| -------- | ------------------------ | ---- |--------------------|
| context | UIAbilityContext | Yes  | Ability context bound to the notification dialog box.|

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
| 1600004  | Notification is not enabled.          |
| 1600013  | Enable Notification Dialog has been popping already.          |

**Example**

```ts
import Base from '@ohos.base';
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.Window';

class MyAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    notificationManager.requestEnableNotification(this.context).then(() => {
      console.info("requestEnableNotification success");
    }).catch((err: Base.BusinessError) => {
      console.error(`requestEnableNotification fail: ${JSON.stringify(err)}`);
    });
  }
}
```

## notificationManager.isDistributedEnabled

isDistributedEnabled(callback: AsyncCallback\<boolean>): void

Checks whether distributed notification is enabled on this device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result. The value **true** means that distributed notification is enabled, and **false** means the opposite.|

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

let isDistributedEnabledCallback = (err: Base.BusinessError, data: boolean): void => {
    if (err) {
        console.error(`isDistributedEnabled failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isDistributedEnabled success " + JSON.stringify(data));
    }
};
notificationManager.isDistributedEnabled(isDistributedEnabledCallback);
```

## notificationManager.isDistributedEnabled

isDistributedEnabled(): Promise\<boolean>

Checks whether distributed notification is enabled on this device. This API uses a promise to return the URI of the file in the destination directory.

**System capability**: SystemCapability.Notification.Notification

**Return value**

| Type              | Description                                         |
| ------------------ | --------------------------------------------- |
| Promise\<boolean\> | Promise used to return the result. The value **true** means that distributed notification is enabled, and **false** means the opposite.|

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

notificationManager.isDistributedEnabled()
.then((data: boolean) => {
    console.info("isDistributedEnabled success, data: " + JSON.stringify(data));
}).catch((err: Base.BusinessError) => {
    console.error(`isDistributedEnabled fail: ${JSON.stringify(err)}`);
});
```

## ContentType

**System capability**: SystemCapability.Notification.Notification

| Name                             | Value         | Description              |
| --------------------------------- | ----------- |------------------|
| NOTIFICATION_CONTENT_BASIC_TEXT   | 0          | Normal text notification.         |
| NOTIFICATION_CONTENT_LONG_TEXT    | 1          | Long text notification.        |
| NOTIFICATION_CONTENT_PICTURE      | 2          | Picture-attached notification. (Not supported currently)         |
| NOTIFICATION_CONTENT_CONVERSATION | 3          | Conversation notification. (Not supported currently)|
| NOTIFICATION_CONTENT_MULTILINE    | 4          | Multi-line text notification.       |
| NOTIFICATION_CONTENT_SYSTEM_LIVE_VIEW<sup>11+</sup>    | 5 | Live view notification. (Not supported currently)       |
| NOTIFICATION_CONTENT_LIVE_VIEW<sup>11+</sup>    | 6 | Common live view notification. (Not supported currently) |

## SlotLevel

**System capability**: SystemCapability.Notification.Notification

| Name                             | Value         | Description              |
| --------------------------------- | ----------- | ------------------ |
| LEVEL_NONE                        | 0           | Notification is disabled.    |
| LEVEL_MIN                         | 1           | Notification is enabled, but the notification icon is not displayed in the status bar, with no banner or alert tone.|
| LEVEL_LOW                         | 2           | Notification is enabled, and the notification icon is displayed in the status bar, with no banner or alert tone.|
| LEVEL_DEFAULT                     | 3           | Notification is enabled, and the notification icon is displayed in the status bar, with an alert tone but no banner.|
| LEVEL_HIGH                        | 4           | Notification is enabled, and the notification icon is displayed in the status bar, with an alert tone and banner.|


## SlotType

**System capability**: SystemCapability.Notification.Notification

| Name                | Value      | Description      |
| -------------------- | -------- | ---------- |
| UNKNOWN_TYPE         | 0 | Unknown type.|
| SOCIAL_COMMUNICATION | 1 | Social communication.|
| SERVICE_INFORMATION  | 2 | Service information.|
| CONTENT_INFORMATION  | 3 | Content information.|
| LIVE_VIEW<sup>11+</sup>            | 4 | Live view. (Not supported currently)|
| CUSTOMER_SERVICE<sup>11+</sup>     | 5 | Customer service message. This type is used for messages between users and customer service providers. The messages must be initiated by users. |
| OTHER_TYPES          | 0xFFFF | Other.|
