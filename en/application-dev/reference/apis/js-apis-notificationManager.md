# @ohos.notificationManager (NotificationManager)

The **notificationManager** module provides notification management capabilities, covering notifications, notification slots, notification enabled status, and notification badge status.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import notificationManager from '@ohos.notificationManager';
```

## notificationManager.publish

publish(request: NotificationRequest, callback: AsyncCallback\<void\>): void

Publishes a notification. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                                       | Mandatory| Description                                       |
| -------- | ------------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](#notificationrequest) | Yes  | Content and related configuration of the notification to publish.|
| callback | AsyncCallback\<void\>                       | Yes  | Callback used to return the result.                       |

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600009  | Over max number notifications per second. |

**Example**

```ts
// publish callback
function publishCallback(err) {
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
        contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
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

Publishes a notification. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                                       | Mandatory| Description                                       |
| -------- | ------------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](#notificationrequest) | Yes  | Content and related configuration of the notification to publish.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600009  | Over max number notifications per second. |

**Example**

```ts
// NotificationRequest object
let notificationRequest: notificationManager.NotificationRequest = {
    notificationId: 1,
    content: {
        contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
};
notificationManager.publish(notificationRequest).then(() => {
	console.info("publish success");
});

```

## notificationManager.publish

publish(request: NotificationRequest, userId: number, callback: AsyncCallback\<void\>): void

Publishes a notification to a specified user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                                       | Mandatory| Description                                       |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](#notificationrequest) | Yes  | Content and related configuration of the notification to publish.|
| userId   | number                                      | Yes  | User ID.                          |
| callback | AsyncCallback\<void\>                       | Yes  | Callback used to return the result.                          |

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600008  | The user is not exist.                    |
| 1600009  | Over max number notifications per second. |

**Example**

```ts
// publish callback
function publishCallback(err) {
    if (err) {
        console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publish success");
    }
}
// User ID
let userId = 1;
// NotificationRequest object
let notificationRequest: notificationManager.NotificationRequest = {
    id: 1,
    content: {
        contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
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

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    |  Type                                       | Mandatory| Description                                       |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](#notificationrequest) | Yes  | Content and related configuration of the notification to publish.|
| userId   | number                                      | Yes  | User ID.                          |

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600008  | The user is not exist.                    |
| 1600009  | Over max number notifications per second. |

**Example**

```ts
let notificationRequest: notificationManager.NotificationRequest = {
    notificationId: 1,
    content: {
        contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
};

let userId = 1;

notificationManager.publish(notificationRequest, userId).then(() => {
	console.info("publish success");
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

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**Example**

```ts
// cancel callback
function cancelCallback(err) {
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

Cancels a notification with the specified ID and optional label. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name | Type  | Mandatory| Description    |
| ----- | ------ | ---- | -------- |
| id    | number | Yes  | Notification ID.  |
| label | string | No  | Notification label.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**Example**

```ts
notificationManager.cancel(0).then(() => {
	console.info("cancel success");
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

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**Example**

```ts
// cancel callback
function cancelCallback(err) {
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

Cancels all notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

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
// cancel callback
function cancelAllCallback(err) {
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

Cancels all notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
notificationManager.cancelAll().then(() => {
	console.info("cancelAll success");
});
```

## notificationManager.addSlot

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

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
// addSlot callback
function addSlotCallBack(err) {
    if (err) {
        console.error(`addSlot failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("addSlot success");
    }
}
// NotificationSlot object
let notificationSlot = {
    type: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
notificationManager.addSlot(notificationSlot, addSlotCallBack);
```

## notificationManager.addSlot

addSlot(slot: NotificationSlot): Promise\<void\>

Adds a notification slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type            | Mandatory| Description                |
| ---- | ---------------- | ---- | -------------------- |
| slot | [NotificationSlot](#notificationslot) | Yes  | Notification slot to add.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
// NotificationSlot object
let notificationSlot = {
    type: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
notificationManager.addSlot(notificationSlot).then(() => {
	console.info("addSlot success");
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

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
// addSlot callback
function addSlotCallBack(err) {
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

Adds a notification slot of a specified type. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name| Type    | Mandatory| Description                  |
| ---- | -------- | ---- | ---------------------- |
| type | [SlotType](#slottype) | Yes  | Type of the notification slot to add.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
notificationManager.addSlot(notificationManager.SlotType.SOCIAL_COMMUNICATION).then(() => {
	console.info("addSlot success");
});
```

## notificationManager.addSlots

addSlots(slots: Array\<NotificationSlot\>, callback: AsyncCallback\<void\>): void

Adds an array of notification slots. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                     | Mandatory| Description                    |
| -------- | ------------------------- | ---- | ------------------------ |
| slots    | Array\<[NotificationSlot](#notificationslot)\> | Yes  | Notification slots to add.|
| callback | AsyncCallback\<void\>     | Yes  | Callback used to return the result.    |

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
// addSlots callback
function addSlotsCallBack(err) {
    if (err) {
        console.error(`addSlots failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("addSlots success");
    }
}
// NotificationSlot object
let notificationSlot = {
    type: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
// NotificationSlotArray object
let notificationSlotArray = new Array();
notificationSlotArray[0] = notificationSlot;

notificationManager.addSlots(notificationSlotArray, addSlotsCallBack);
```

## notificationManager.addSlots

addSlots(slots: Array\<NotificationSlot\>): Promise\<void\>

Adds an array of notification slots. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name | Type                     | Mandatory| Description                    |
| ----- | ------------------------- | ---- | ------------------------ |
| slots | Array\<[NotificationSlot](#notificationslot)\> | Yes  | Notification slots to add.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
// NotificationSlot object
let notificationSlot = {
    type: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
// NotificationSlotArray object
let notificationSlotArray = new Array();
notificationSlotArray[0] = notificationSlot;

notificationManager.addSlots(notificationSlotArray).then(() => {
	console.info("addSlots success");
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
| callback | AsyncCallback\<[NotificationSlot](#notificationslot)\> | Yes  | Callback used to return the result.                                       |

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
// getSlot callback
function getSlotCallback(err,data) {
    if (err) {
        console.error(`getSlot failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getSlot success");
    }
}
let slotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
notificationManager.getSlot(slotType, getSlotCallback);
```

## notificationManager.getSlot

getSlot(slotType: SlotType): Promise\<NotificationSlot\>

Obtains a notification slot of a specified type. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type    | Mandatory| Description                                                       |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype) | Yes  | Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<NotificationSlot\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
let slotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
notificationManager.getSlot(slotType).then((data) => {
	console.info("getSlot success, data: " + JSON.stringify(data));
});
```

## notificationManager.getSlots

getSlots(callback: AsyncCallback<Array\<NotificationSlot\>>): void

Obtains all notification slots of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| Name    | Type                             | Mandatory| Description                |
| -------- | --------------------------------- | ---- | -------------------- |
| callback | AsyncCallback\<Array\<[NotificationSlot](#notificationslot)\>\> | Yes  | Callback used to return all notification slots of the current application.|

**Error codes**

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
// getSlots callback
function getSlotsCallback(err,data) {
    if (err) {
        console.error(`getSlots failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getSlots success");
    }
}
notificationManager.getSlots(getSlotsCallback);
```

## notificationManager.getSlots

getSlots(): Promise\<Array\<NotificationSlot\>>

Obtains all notification slots of this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationSlot](#notificationslot)\>\> | Promise used to return all notification slots of the current application.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
notificationManager.getSlots().then((data) => {
	console.info("getSlots success, data: " + JSON.stringify(data));
});
```

## notificationManager.removeSlot

removeSlot(slotType: SlotType, callback: AsyncCallback\<void\>): void

Removes a notification slot of a specified type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                 | Mandatory| Description                                                       |
| -------- | --------------------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype)              | Yes  | Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.                                       |

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
// removeSlot callback
function removeSlotCallback(err) {
    if (err) {
        console.error(`removeSlot failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeSlot success");
    }
}
let slotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
notificationManager.removeSlot(slotType,removeSlotCallback);
```

## notificationManager.removeSlot

removeSlot(slotType: SlotType): Promise\<void\>

Removes a notification slot of a specified type. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type    | Mandatory| Description                                                       |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype) | Yes  | Type of the notification slot, which can be used for social communication, service information, content consultation, and other purposes.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
let slotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
notificationManager.removeSlot(slotType).then(() => {
	console.info("removeSlot success");
});
```

## notificationManager.removeAllSlots

removeAllSlots(callback: AsyncCallback\<void\>): void

Removes all notification slots. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
function removeAllCallBack(err) {
    if (err) {
        console.error(`removeAllSlots failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeAllSlots success");
    }
}
notificationManager.removeAllSlots(removeAllCallBack);
```

## notificationManager.removeAllSlots

removeAllSlots(): Promise\<void\>

Removes all notification slots. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
notificationManager.removeAllSlots().then(() => {
	console.info("removeAllSlots success");
});
```

## notificationManager.setNotificationEnable

setNotificationEnable(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether to enable notification for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](#bundleoption)          | Yes  | Bundle of the application.       |
| enable   | boolean               | Yes  | Whether to enable notification.            |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
function setNotificationEnablenCallback(err) {
    if (err) {
        console.error(`setNotificationEnablenCallback failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setNotificationEnablenCallback success");
    }
}
let bundle = {
    bundle: "bundleName1",
};
notificationManager.setNotificationEnable(bundle, false, setNotificationEnablenCallback);
```

## notificationManager.setNotificationEnable

setNotificationEnable(bundle: BundleOption, enable: boolean): Promise\<void\>

Sets whether to enable notification for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle of the application.|
| enable | boolean      | Yes  | Whether to enable notification.  |

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
let bundle = {
    bundle: "bundleName1",
};
notificationManager.setNotificationEnable(bundle, false).then(() => {
	console.info("setNotificationEnable success");
});
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

Checks whether notification is enabled for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name    | Type                 | Mandatory| Description                    |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](#bundleoption)          | Yes  | Bundle of the application.           |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
function isNotificationEnabledCallback(err, data) {
    if (err) {
        console.error(`isNotificationEnabled failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isNotificationEnabled success");
    }
}
let bundle = {
    bundle: "bundleName1",
};
notificationManager.isNotificationEnabled(bundle, isNotificationEnabledCallback);
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(bundle: BundleOption): Promise\<boolean\>

Checks whether notification is enabled for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle of the application.|

**Return value**

| Type              | Description                                               |
| ------------------ | --------------------------------------------------- |
| Promise\<boolean\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
let bundle = {
    bundle: "bundleName1",
};
notificationManager.isNotificationEnabled(bundle).then((data) => {
	console.info("isNotificationEnabled success, data: " + JSON.stringify(data));
});
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(callback: AsyncCallback\<boolean\>): void

Checks whether notification is enabled for this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                    |
| -------- | --------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
function isNotificationEnabledCallback(err, data) {
    if (err) {
        console.error(`isNotificationEnabled failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isNotificationEnabled success");
    }
}

notificationManager.isNotificationEnabled(isNotificationEnabledCallback);
```

## notificationManager.isNotificationEnabled

isNotificationEnabled(): Promise\<boolean\>

Checks whether notification is enabled for the current application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle of the application.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
notificationManager.isNotificationEnabled().then((data) => {
	console.info("isNotificationEnabled success, data: " + JSON.stringify(data));
});
```

## notificationManager.displayBadge

displayBadge(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether to enable the notification badge for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](#bundleoption)          | Yes  | Bundle of the application.          |
| enable   | boolean               | Yes  | Whether to enable notification.            |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
function displayBadgeCallback(err) {
    if (err) {
        console.error(`displayBadge failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("displayBadge success");
    }
}
let bundle = {
    bundle: "bundleName1",
};
notificationManager.displayBadge(bundle, false, displayBadgeCallback);
```

## notificationManager.displayBadge

displayBadge(bundle: BundleOption, enable: boolean): Promise\<void\>

Sets whether to enable the notification badge for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle of the application.|
| enable | boolean      | Yes  | Whether to enable notification.  |

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
let bundle = {
    bundle: "bundleName1",
};
notificationManager.displayBadge(bundle, false).then(() => {
	console.info("displayBadge success");
});
```

## notificationManager.isBadgeDisplayed

isBadgeDisplayed(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

Checks whether the notification badge is enabled for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                    |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](#bundleoption)          | Yes  | Bundle of the application.              |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
function isBadgeDisplayedCallback(err, data) {
    if (err) {
        console.error(`isBadgeDisplayed failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isBadgeDisplayed success");
    }
}
let bundle = {
    bundle: "bundleName1",
};
notificationManager.isBadgeDisplayed(bundle, isBadgeDisplayedCallback);
```

## notificationManager.isBadgeDisplayed

isBadgeDisplayed(bundle: BundleOption): Promise\<boolean\>

Checks whether the notification badge is enabled for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle of the application.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
let bundle = {
    bundle: "bundleName1",
};
notificationManager.isBadgeDisplayed(bundle).then((data) => {
	console.info("isBadgeDisplayed success, data: " + JSON.stringify(data));
});
```

## notificationManager.setBadgeNumber<sup>10+</sup>

setBadgeNumber(badgeNumber: number): Promise\<void\>

Sets the notification badge number. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name     | Type  | Mandatory| Description      |
| ----------- | ------ | ---- | ---------- |
| badgeNumber | number | Yes  | Notification badge number to set.|

**Error codes**

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |

**Example**

```ts
let badgeNumber = 10
notificationManager.setBadgeNumber(badgeNumber).then(() => {
	console.info("displayBadge success");
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

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |

**Example**

```ts
function setBadgeNumberCallback(err) {
    if (err) {
        console.info(`displayBadge failed code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("displayBadge success");
    }
}

let badgeNumber = 10
notificationManager.setBadgeNumber(badgeNumber, setBadgeNumberCallback);
```

## notificationManager.setSlotByBundle

setSlotByBundle(bundle: BundleOption, slot: NotificationSlot, callback: AsyncCallback\<void\>): void

Sets the notification slot for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](#bundleoption)          | Yes  | Bundle of the application.          |
| slot     | [NotificationSlot](#notificationslot)      | Yes  | Notification slot.            |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
function setSlotByBundleCallback(err) {
    if (err) {
        console.error(`setSlotByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setSlotByBundle success");
    }
}
let bundle = {
    bundle: "bundleName1",
};
let notificationSlot = {
    type: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
notificationManager.setSlotByBundle(bundle, notificationSlot, setSlotByBundleCallback);
```

## notificationManager.setSlotByBundle

setSlotByBundle(bundle: BundleOption, slot: NotificationSlot): Promise\<void\>

Sets the notification slot for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle of the application.|
| slot   | [NotificationSlot](#notificationslot) | Yes  | Notification slot.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
let bundle = {
    bundle: "bundleName1",
};
let notificationSlot = {
    type: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
notificationManager.setSlotByBundle(bundle, notificationSlot).then(() => {
	console.info("setSlotByBundle success");
});
```

## notificationManager.getSlotsByBundle

getSlotsByBundle(bundle: BundleOption, callback: AsyncCallback<Array\<NotificationSlot\>>): void

Obtains the notification slots of a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                                    | Mandatory| Description                |
| -------- | ---------------------------------------- | ---- | -------------------- |
| bundle   | [BundleOption](#bundleoption)                             | Yes  | Bundle of the application.          |
| callback | AsyncCallback<Array\<[NotificationSlot](#notificationslot)\>> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
function getSlotsByBundleCallback(err, data) {
    if (err) {
        console.error(`getSlotByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getSlotsByBundle success");
    }
}
let bundle = {
    bundle: "bundleName1",
};
notificationManager.getSlotsByBundle(bundle, getSlotsByBundleCallback);
```

## notificationManager.getSlotsByBundle

getSlotsByBundle(bundle: BundleOption): Promise<Array\<NotificationSlot\>>

Obtains the notification slots of a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle of the application.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise<Array\<[NotificationSlot](#notificationslot)\>> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
let bundle = {
    bundle: "bundleName1",
};
notificationManager.getSlotsByBundle(bundle).then((data) => {
	console.info("getSlotsByBundle success, data: " + JSON.stringify(data));
});
```

## notificationManager.getSlotNumByBundle

getSlotNumByBundle(bundle: BundleOption, callback: AsyncCallback\<number\>): void

Obtains the number of notification slots of a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                     | Mandatory| Description                  |
| -------- | ------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](#bundleoption)              | Yes  | Bundle of the application.            |
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
function getSlotNumByBundleCallback(err, data) {
    if (err) {
        console.error(`getSlotByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getSlotNumByBundle success");
    }
}
let bundle = {
    bundle: "bundleName1",
};
notificationManager.getSlotNumByBundle(bundle, getSlotNumByBundleCallback);
```

## notificationManager.getSlotNumByBundle

getSlotNumByBundle(bundle: BundleOption): Promise\<number\>

Obtains the number of notification slots of a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type        | Mandatory| Description      |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle of the application.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
let bundle = {
    bundle: "bundleName1",
};
notificationManager.getSlotNumByBundle(bundle).then((data) => {
	console.info("getSlotNumByBundle success, data: " + JSON.stringify(data));
});
```


## notificationManager.getAllActiveNotifications

getAllActiveNotifications(callback: AsyncCallback<Array\<NotificationRequest\>>): void

Obtains all active notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                                                        | Mandatory| Description                |
| -------- | ------------------------------------------------------------ | ---- | -------------------- |
| callback | AsyncCallback<Array\<[NotificationRequest](#notificationrequest)\>> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
function getAllActiveNotificationsCallback(err, data) {
    if (err) {
        console.error(`getAllActiveNotifications failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getAllActiveNotifications success");
    }
}

notificationManager.getAllActiveNotifications(getAllActiveNotificationsCallback);
```

## notificationManager.getAllActiveNotifications

getAllActiveNotifications(): Promise\<Array\<[NotificationRequest](#notificationrequest)\>\>

Obtains all active notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationRequest](#notificationrequest)\>\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
notificationManager.getAllActiveNotifications().then((data) => {
	console.info("getAllActiveNotifications success, data: " + JSON.stringify(data));
});
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

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
function getActiveNotificationCountCallback(err, data) {
    if (err) {
        console.error(`getActiveNotificationCount failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getActiveNotificationCount success");
    }
}

notificationManager.getActiveNotificationCount(getActiveNotificationCountCallback);
```

## notificationManager.getActiveNotificationCount

getActiveNotificationCount(): Promise\<number\>

Obtains the number of active notifications of this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Return value**

| Type             | Description                                       |
| ----------------- | ------------------------------------------- |
| Promise\<number\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
notificationManager.getActiveNotificationCount().then((data) => {
	console.info("getActiveNotificationCount success, data: " + JSON.stringify(data));
});
```

## notificationManager.getActiveNotifications

getActiveNotifications(callback: AsyncCallback<Array\<NotificationRequest\>>): void

Obtains active notifications of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name    | Type                                                        | Mandatory| Description                          |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback<Array\<[NotificationRequest](#notificationrequest)\>> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
function getActiveNotificationsCallback(err, data) {
    if (err) {
        console.error(`getActiveNotifications failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getActiveNotifications success");
    }
}

notificationManager.getActiveNotifications(getActiveNotificationsCallback);
```

## notificationManager.getActiveNotifications

getActiveNotifications(): Promise\<Array\<[NotificationRequest](#notificationrequest)\>\>

Obtains active notifications of this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Return value**

| Type                                                        | Description                                   |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise\<Array\<[NotificationRequest](#notificationrequest)\>\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
notificationManager.getActiveNotifications().then((data) => {
	console.info("removeGroupByBundle success, data: " + JSON.stringify(data));
});
```

## notificationManager.cancelGroup

cancelGroup(groupName: string, callback: AsyncCallback\<void\>): void

Cancels notifications under a notification group of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name     | Type                 | Mandatory| Description                        |
| --------- | --------------------- | ---- | ---------------------------- |
| groupName | string                | Yes  | Name of the notification group, which is specified through [NotificationRequest](#notificationrequest) when the notification is published.|
| callback  | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
function cancelGroupCallback(err) {
    if (err) {
        console.error(`cancelGroup failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("cancelGroup success");
    }
}

let groupName = "GroupName";

notificationManager.cancelGroup(groupName, cancelGroupCallback);
```

## notificationManager.cancelGroup

cancelGroup(groupName: string): Promise\<void\>

Cancels notifications under a notification group of this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name     | Type  | Mandatory| Description          |
| --------- | ------ | ---- | -------------- |
| groupName | string | Yes  | Name of the notification group.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
let groupName = "GroupName";
notificationManager.cancelGroup(groupName).then(() => {
	console.info("cancelGroup success");
});
```

## notificationManager.removeGroupByBundle

removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void\>): void

Removes notifications under a notification group of a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type                 | Mandatory| Description                        |
| --------- | --------------------- | ---- | ---------------------------- |
| bundle    | [BundleOption](#bundleoption)          | Yes  | Bundle information of the application.                  |
| groupName | string                | Yes  | Name of the notification group.              |
| callback  | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
function removeGroupByBundleCallback(err) {
    if (err) {
        console.error(`removeGroupByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("removeGroupByBundle success");
    }
}

let bundleOption = {bundle: "Bundle"};
let groupName = "GroupName";

notificationManager.removeGroupByBundle(bundleOption, groupName, removeGroupByBundleCallback);
```

## notificationManager.removeGroupByBundle

removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void\>

Removes notifications under a notification group of a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name     | Type        | Mandatory| Description          |
| --------- | ------------ | ---- | -------------- |
| bundle    | [BundleOption](#bundleoption) | Yes  | Bundle information of the application.    |
| groupName | string       | Yes  | Name of the notification group.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
let bundleOption = {bundle: "Bundle"};
let groupName = "GroupName";
notificationManager.removeGroupByBundle(bundleOption, groupName).then(() => {
	console.info("removeGroupByBundle success");
});
```

## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, callback: AsyncCallback\<void\>): void

Sets the DND time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                  |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate)      | Yes  | DND time to set.        |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
function setDoNotDisturbDateCallback(err) {
    if (err) {
        console.error(`setDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setDoNotDisturbDate success");
    }
}

let doNotDisturbDate = {
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

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type            | Mandatory| Description          |
| ---- | ---------------- | ---- | -------------- |
| date | [DoNotDisturbDate](#donotdisturbdate) | Yes  | DND time to set.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
let doNotDisturbDate = {
    type: notificationManager.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
};
notificationManager.setDoNotDisturbDate(doNotDisturbDate).then(() => {
	console.info("setDoNotDisturbDate success");
});
```


## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number, callback: AsyncCallback\<void\>): void

Sets the DND time for a specified user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                 | Mandatory| Description                  |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate)      | Yes  | DND time to set.        |
| userId   | number                | Yes  | ID of the user for whom you want to set the DND time.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**Example**

```ts
function setDoNotDisturbDateCallback(err) {
    if (err) {
        console.error(`setDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setDoNotDisturbDate success");
    }
}

let doNotDisturbDate = {
    type: notificationManager.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
};

let userId = 1;

notificationManager.setDoNotDisturbDate(doNotDisturbDate, userId, setDoNotDisturbDateCallback);
```

## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number): Promise\<void\>

Sets the DND time for a specified user. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type            | Mandatory| Description          |
| ------ | ---------------- | ---- | -------------- |
| date   | [DoNotDisturbDate](#donotdisturbdate) | Yes  | DND time to set.|
| userId | number           | Yes  | ID of the user for whom you want to set the DND time.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**Example**

```ts
let doNotDisturbDate = {
    type: notificationManager.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
};

let userId = 1;

notificationManager.setDoNotDisturbDate(doNotDisturbDate, userId).then(() => {
	console.info("setDoNotDisturbDate success");
});
```


## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate\>): void

Obtains the DND time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                             | Mandatory| Description                  |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate)\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
function getDoNotDisturbDateCallback(err,data) {
    if (err) {
        console.error(`getDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getDoNotDisturbDate success");
    }
}

notificationManager.getDoNotDisturbDate(getDoNotDisturbDateCallback);
```

## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(): Promise\<DoNotDisturbDate\>

Obtains the DND time. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

| Type                                            | Description                                     |
| ------------------------------------------------ | ----------------------------------------- |
| Promise\<[DoNotDisturbDate](#donotdisturbdate)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
notificationManager.getDoNotDisturbDate().then((data) => {
	console.info("getDoNotDisturbDate success, data: " + JSON.stringify(data));
});
```


## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(userId: number, callback: AsyncCallback\<DoNotDisturbDate\>): void

Obtains the DND time of a specified user. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                             | Mandatory| Description                  |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate)\> | Yes  | Callback used to return the result.|
| userId   | number                            | Yes  | User ID.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**Example**

```ts
function getDoNotDisturbDateCallback(err,data) {
    if (err) {
        console.error(`getDoNotDisturbDate failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getDoNotDisturbDate success");
    }
}

let userId = 1;

notificationManager.getDoNotDisturbDate(userId, getDoNotDisturbDateCallback);
```

## notificationManager.getDoNotDisturbDate

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

| Type                                            | Description                                     |
| ------------------------------------------------ | ----------------------------------------- |
| Promise\<[DoNotDisturbDate](#donotdisturbdate)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**Example**

```ts
let userId = 1;

notificationManager.getDoNotDisturbDate(userId).then((data) => {
	console.info("getDoNotDisturbDate success, data: " + JSON.stringify(data));
});
```


## notificationManager.isSupportDoNotDisturbMode

 isSupportDoNotDisturbMode(callback: AsyncCallback\<boolean\>): void

Checks whether DND mode is supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name    | Type                    | Mandatory| Description                            |
| -------- | ------------------------ | ---- | -------------------------------- |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Error codes**

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
function isSupportDoNotDisturbModeCallback(err,data) {
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

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```ts
notificationManager.isSupportDoNotDisturbMode().then((data) => {
	console.info("supportDoNotDisturbMode success, data: " + JSON.stringify(data));
});
```

## notificationManager.isSupportTemplate

isSupportTemplate(templateName: string, callback: AsyncCallback\<boolean\>): void

Checks whether a specified template is supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name      | Type                    | Mandatory| Description                      |
| ------------ | ------------------------ | ---- | -------------------------- |
| templateName | string                   | Yes  | Template name.                  |
| callback     | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600011  | Read template config failed.        |

**Example**

```javascript
let templateName = 'process';
function isSupportTemplateCallback(err, data) {
    if (err) {
        console.error(`isSupportTemplate failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isSupportTemplate success");
    }
}

notificationManager.isSupportTemplate(templateName, isSupportTemplateCallback);
```

## notificationManager.isSupportTemplate

isSupportTemplate(templateName: string): Promise\<boolean\>

Checks whether a specified template is supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name      | Type  | Mandatory| Description    |
| ------------ | ------ | ---- | -------- |
| templateName | string | Yes  | Template name.|

**Return value**

| Type              | Description           |
| ------------------ | --------------- |
| Promise\<boolean\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600011  | Read template config failed.        |

**Example**

```javascript
let templateName = 'process';

notificationManager.isSupportTemplate(templateName).then((data) => {
    console.info("isSupportTemplate success, data: " + JSON.stringify(data));
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

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```javascript
function requestEnableNotificationCallback(err) {
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

Requests notification to be enabled for this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```javascript
notificationManager.requestEnableNotification().then(() => {
    console.info("requestEnableNotification success");
});
```



## notificationManager.setDistributedEnable

setDistributedEnable(enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether this device supports distributed notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | Yes  | Whether the device supports distributed notifications.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600010  | Distributed operation failed.       |

**Example**

```javascript
function setDistributedEnableCallback() {
    if (err) {
        console.error(`setDistributedEnable failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("setDistributedEnable success");
    }
};

let enable = true;

notificationManager.setDistributedEnable(enable, setDistributedEnableCallback);
```

## notificationManager.setDistributedEnable

setDistributedEnable(enable: boolean): Promise\<void>

Sets whether this device supports distributed notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | Yes  | Whether the device supports distributed notifications.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600010  | Distributed operation failed.       |

**Example**

```javascript
let enable = true;

notificationManager.setDistributedEnable(enable).then(() => {
        console.info("setDistributedEnable success");
    });
```


## notificationManager.isDistributedEnabled

isDistributedEnabled(callback: AsyncCallback\<boolean>): void

Checks whether this device supports distributed notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600010  | Distributed operation failed.       |

**Example**

```javascript
function isDistributedEnabledCallback(err, data) {
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

Checks whether this device supports distributed notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Return value**

| Type              | Description                                         |
| ------------------ | --------------------------------------------- |
| Promise\<boolean\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600010  | Distributed operation failed.       |

**Example**

```javascript
notificationManager.isDistributedEnabled()
    .then((data) => {
        console.info("isDistributedEnabled success, data: " + JSON.stringify(data));
    });
```


## notificationManager.setDistributedEnableByBundle

setDistributedEnableByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void

Sets whether a specified application supports distributed notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](#bundleoption)             | Yes  | Bundle information of the application.                  |
| enable   | boolean                  | Yes  | Whether the device supports distributed notifications.                      |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**Example**

```javascript
function setDistributedEnableByBundleCallback(err) {
    if (err) {
        console.error(`setDistributedEnableByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("enableDistributedByBundle success");
    }
};

let bundle = {
    bundle: "bundleName1",
};

let enable = true

notificationManager.setDistributedEnableByBundle(bundle, enable, setDistributedEnableByBundleCallback);
```



## notificationManager.setDistributedEnableByBundle

setDistributedEnableByBundle(bundle: BundleOption, enable: boolean): Promise\<void>

Sets whether a specified application supports distributed notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](#bundleoption)             | Yes  | Bundle information of the application.               |
| enable   | boolean                  | Yes  | Whether the device supports distributed notifications.                 |

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**Example**

```javascript
let bundle = {
    bundle: "bundleName1",
};

let enable = true

notificationManager.setDistributedEnableByBundle(bundle, enable).then(() => {
    console.info("setDistributedEnableByBundle success");
});
```

## notificationManager.isDistributedEnabledByBundle

isDistributedEnabledByBundle(bundle: BundleOption, callback: AsyncCallback\<boolean>): void

Checks whether a specified application supports distributed notifications. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](#bundleoption)             | Yes  | Bundle information of the application.                    |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**Example**

```javascript
function isDistributedEnabledByBundleCallback(data) {
    if (err) {
        console.error(`isDistributedEnabledByBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isDistributedEnabledByBundle success" + JSON.stringify(data));
    }
};

let bundle = {
    bundle: "bundleName1",
};

notificationManager.isDistributedEnabledByBundle(bundle, isDistributedEnabledByBundleCallback);
```

## notificationManager.isDistributedEnabledByBundle

isDistributedEnabledByBundle(bundle: BundleOption): Promise\<boolean>

Checks whether a specified application supports distributed notifications. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                    | Mandatory| Description                      |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](#bundleoption)             | Yes  | Bundle information of the application.               |

**Return value**

| Type              | Description                                             |
| ------------------ | ------------------------------------------------- |
| Promise\<boolean\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**Example**

```javascript
let bundle = {
    bundle: "bundleName1",
};

notificationManager.isDistributedEnabledByBundle(bundle).then((data) => {
    console.info("isDistributedEnabledByBundle success, data: " + JSON.stringify(data));
});
```


## notificationManager.getDeviceRemindType

getDeviceRemindType(callback: AsyncCallback\<DeviceRemindType\>): void

Obtains the notification reminder type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name  | Type                              | Mandatory| Description                      |
| -------- | --------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<[DeviceRemindType](#deviceremindtype)\> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```javascript
function getDeviceRemindTypeCallback(err, data) {
    if (err) {
        console.error(`getDeviceRemindType failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("getDeviceRemindType success");
    }
};

notificationManager.getDeviceRemindType(getDeviceRemindTypeCallback);
```

## notificationManager.getDeviceRemindType

getDeviceRemindType(): Promise\<DeviceRemindType\>

Obtains the notification reminder type. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Return value**

| Type              | Description           |
| ------------------ | --------------- |
| Promise\<[DeviceRemindType](#deviceremindtype)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**Example**

```javascript
notificationManager.getDeviceRemindType().then((data) => {
    console.info("getDeviceRemindType success, data: " + JSON.stringify(data));
});
```


## notificationManager.publishAsBundle

publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number, callback: AsyncCallback\<void\>): void

Publishes a notification through the reminder agent. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER, ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name              | Type                                       | Mandatory| Description                                    |
| -------------------- | ------------------------------------------- | ---- | ---------------------------------------- |
| request              | [NotificationRequest](#notificationrequest) | Yes  | Content and related configuration of the notification to publish.|
| representativeBundle | string                                      | Yes  | Bundle name of the application whose notification function is taken over by the reminder agent.                      |
| userId               | number                                      | Yes  | User ID.                                |
| callback             | AsyncCallback                               | Yes  | Callback used to return the result.                |

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600008  | The user is not exist.                    |
| 1600009  | Over max number notifications per second. |

**Example**

```ts
// publishAsBundle callback
function callback(err) {
    if (err) {
        console.error(`publishAsBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publishAsBundle success");
    }
}
// Bundle name of the application whose notification function is taken over by the reminder agent
let representativeBundle = "com.example.demo";
// User ID
let userId = 100;
// NotificationRequest object
let request = {
    id: 1,
    content: {
        contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
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

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**


| Name              | Type                                       | Mandatory| Description                                         |
| -------------------- | ------------------------------------------- | ---- | --------------------------------------------- |
| request              | [NotificationRequest](#notificationrequest) | Yes  | Content and related configuration of the notification to publish.|
| representativeBundle | string                                      | Yes  | Bundle name of the application whose notification function is taken over by the reminder agent.                           |
| userId               | number                                      | Yes  | User ID.                           |

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                 |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600008  | The user is not exist.                    |
| 1600009  | Over max number notifications per second. |

**Example**

```ts
// Bundle name of the application whose notification function is taken over by the reminder agent
let representativeBundle = "com.example.demo";
// User ID
let userId = 100;
// NotificationRequest object
let request = {
    id: 1,
    content: {
        contentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
};

notificationManager.publishAsBundle(request, representativeBundle, userId).then(() => {
	console.info("publishAsBundle success");
});
```

## notificationManager.cancelAsBundle

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
| userId               | number        | Yes  | User ID.      |
| callback             | AsyncCallback | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |
| 1600008  | The user is not exist.              |

**Example**

```ts
// cancelAsBundle
function cancelAsBundleCallback(err) {
    if (err) {
        console.error(`cancelAsBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("cancelAsBundle success");
    }
}
// Bundle name of the application whose notification function is taken over by the reminder agent
let representativeBundle = "com.example.demo";
// User ID
let userId = 100;

notificationManager.cancelAsBundle(0, representativeBundle, userId, cancelAsBundleCallback);
```

## notificationManager.cancelAsBundle

cancelAsBundle(id: number, representativeBundle: string, userId: number): Promise\<void\>

Cancels a notification published by the reminder agent. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER, ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name              | Type  | Mandatory| Description              |
| -------------------- | ------ | ---- | ------------------ |
| id                   | number | Yes  | Notification ID.          |
| representativeBundle | string | Yes  | Bundle name of the application whose notification function is taken over by the reminder agent.|
| userId               | number | Yes  | User ID.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |
| 1600008  | The user is not exist.              |

**Example**

```ts
// Bundle name of the application whose notification function is taken over by the reminder agent
let representativeBundle = "com.example.demo";
// User ID
let userId = 100;

notificationManager.cancelAsBundle(0, representativeBundle, userId).then(() => {
	console.info("cancelAsBundle success");
});
```

## notificationManager.setNotificationEnableSlot 

setNotificationEnableSlot(bundle: BundleOption, type: SlotType, enable: boolean, callback: AsyncCallback\<void>): void

Sets whether to enable a specified notification slot type for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name  | Type                         | Mandatory| Description                  |
| -------- | ----------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](#bundleoption) | Yes  | Bundle information of the application.          |
| type     | [SlotType](#slottype)         | Yes  | Notification slot type.        |
| enable   | boolean                       | Yes  | Whether to enable notification.            |
| callback | AsyncCallback\<void\>         | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
// setNotificationEnableSlot
function setNotificationEnableSlotCallback(err) {
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

## notificationManager.setNotificationEnableSlot

setNotificationEnableSlot(bundle: BundleOption, type: SlotType, enable: boolean): Promise\<void> 

Sets whether to enable a specified notification slot type for a specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle information of the application.  |
| type   | [SlotType](#slottype)         | Yes  | Notification slot type.|
| enable | boolean                       | Yes  | Whether to enable notification.    |

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
// setNotificationEnableSlot
notificationManager.setNotificationEnableSlot(
    { bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION,
    true).then(() => {
        console.info("setNotificationEnableSlot success");
    });
```

## notificationManager.isNotificationSlotEnabled

isNotificationSlotEnabled(bundle: BundleOption, type: SlotType, callback: AsyncCallback\<boolean\>): void

Checks whether a specified notification slot type is enabled for a specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name  | Type                         | Mandatory| Description                  |
| -------- | ----------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](#bundleoption) | Yes  | Bundle information of the application.          |
| type     | [SlotType](#slottype)         | Yes  | Notification slot type.        |
| callback | AsyncCallback\<boolean\>         | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
// isNotificationSlotEnabled
function getEnableSlotCallback(err, data) {
    if (err) {
        console.error(`isNotificationSlotEnabled failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("isNotificationSlotEnabled success");
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

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| bundle | [BundleOption](#bundleoption) | Yes  | Bundle information of the application.  |
| type   | [SlotType](#slottype)         | Yes  | Notification slot type.|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                                |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**Example**

```ts
// isNotificationSlotEnabled
notificationManager.isNotificationSlotEnabled({ bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION).then((data) => {
    console.info("isNotificationSlotEnabled success, data: " + JSON.stringify(data));
});
```


## notificationManager.setSyncNotificationEnabledWithoutApp

setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean, callback: AsyncCallback\<void\>): void

Sets whether to enable the notification sync feature for devices where the application is not installed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | Yes  | User ID.  |
| enable | boolean | Yes  | Whether the feature is enabled.  |
| callback | AsyncCallback\<void\>    | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**Example**

```ts
let userId = 100;
let enable = true;

function callback(err) {
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

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | Yes  | User ID.  |
| enable | boolean | Yes  | Whether the feature is enabled.  |

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**Example**

```ts
let userId = 100;
let enable = true;

notificationManager.setSyncNotificationEnabledWithoutApp(userId, enable).then(() => {
    console.info('setSyncNotificationEnabledWithoutApp success');
}).catch((err) => {
    console.error(`setSyncNotificationEnabledWithoutApp failed, code is ${err.code}, message is ${err.message}`);
});
```


## notificationManager.getSyncNotificationEnabledWithoutApp

getSyncNotificationEnabledWithoutApp(userId: number, callback: AsyncCallback\<boolean>): void

Obtains whether the notification sync feature is enabled for devices where the application is not installed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | Yes  | User ID.  |
| callback | AsyncCallback\<boolean\>         | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**Example**

```ts
let userId = 100;

function getSyncNotificationEnabledWithoutAppCallback(err, data) {
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

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.NOTIFICATION_CONTROLLER

**Parameters**

| Name| Type                         | Mandatory| Description          |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | Yes  | User ID.  |

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Notification Error Codes](../errorcodes/errorcode-notification.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**Example**

```ts
let userId = 100;
notificationManager.getSyncNotificationEnabledWithoutApp(userId).then((data) => {
    console.info('getSyncNotificationEnabledWithoutApp, data:' + data);
}).catch((err) => {
    console.info('getSyncNotificationEnabledWithoutApp, err:' + err);
});
```


## DoNotDisturbDate

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name | Type                                 | Readable| Writable| Description                  |
| ----- | ------------------------------------- | ---- | ---- | ---------------------- |
| type  | [DoNotDisturbType](#donotdisturbtype) | Yes  | Yes  | DND time type.|
| begin | Date                                  | Yes  | Yes  | DND start time.|
| end   | Date                                  | Yes  | Yes  | DND end time.|

## DoNotDisturbType

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
| LEVEL_NONE                        | 0           | Notification is disabled.    |
| LEVEL_MIN                         | 1           | Notification is enabled, but the notification icon is not displayed in the status bar, with no banner or alert tone.|
| LEVEL_LOW                         | 2           | Notification is enabled, and the notification icon is displayed in the status bar, with no banner or alert tone.|
| LEVEL_DEFAULT                     | 3           | Notification is enabled, and the notification icon is displayed in the status bar, with an alert tone but no banner.|
| LEVEL_HIGH                        | 4           | Notification is enabled, and the notification icon is displayed in the status bar, with an alert tone and banner.|


## BundleOption

**System capability**: SystemCapability.Notification.Notification

| Name  | Type  | Readable| Writable| Description  |
| ------ | ------ |---- | --- |  ------ |
| bundle | string | Yes | Yes | Bundle information of the application.|
| uid    | number | Yes | Yes | User ID.|


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

Describes the button displayed in the notification.

**System capability**: SystemCapability.Notification.Notification

| Name     | Type                                           | Readable| Writable| Description                     |
| --------- | ----------------------------------------------- | --- | ---- | ------------------------- |
| title     | string                                          | Yes | Yes | Button title.                 |
| wantAgent | [WantAgent](js-apis-app-ability-wantAgent.md)   | Yes | Yes | **WantAgent** of the button.|
| extras    | { [key: string]: any }                          | Yes | Yes | Extra information of the button.             |
| userInput | [NotificationUserInput](#notificationuserinput) | Yes | Yes | User input object.         |


## NotificationBasicContent

Describes the normal text notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type  | Readable| Writable| Description                              |
| -------------- | ------ | ---- | ---- | ---------------------------------- |
| title          | string | Yes  | Yes  | Notification title.                        |
| text           | string | Yes  | Yes  | Notification content.                        |
| additionalText | string | Yes  | Yes  | Additional information of the notification.|


## NotificationLongTextContent

Describes the long text notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type  | Readable| Writable| Description                            |
| -------------- | ------ | ---- | --- | -------------------------------- |
| title          | string | Yes | Yes | Notification title.                        |
| text           | string | Yes | Yes | Notification content.                        |
| additionalText | string | Yes | Yes | Additional information of the notification.|
| longText       | string | Yes | Yes | Long text of the notification.                    |
| briefText      | string | Yes | Yes | Brief text of the notification.|
| expandedTitle  | string | Yes | Yes | Title of the notification in the expanded state.                |


## NotificationMultiLineContent

Describes the multi-line text notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type           | Readable| Writable| Description                            |
| -------------- | --------------- | --- | --- | -------------------------------- |
| title          | string          | Yes | Yes | Notification title.                        |
| text           | string          | Yes | Yes | Notification content.                        |
| additionalText | string          | Yes | Yes | Additional information of the notification.|
| briefText      | string          | Yes | Yes | Brief text of the notification.|
| longTitle      | string          | Yes | Yes | Title of the notification in the expanded state.                |
| lines          | Array\<string\> | Yes | Yes | Multi-line text of the notification.                  |


## NotificationPictureContent

Describe the picture-attached notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type          | Readable| Writable| Description                            |
| -------------- | -------------- | ---- | --- | -------------------------------- |
| title          | string         | Yes | Yes | Notification title.                        |
| text           | string         | Yes | Yes | Notification content.                        |
| additionalText | string         | Yes | Yes | Additional information of the notification.|
| briefText      | string         | Yes | Yes | Brief text of the notification.|
| expandedTitle  | string         | Yes | Yes | Title of the notification in the expanded state.                |
| picture        | [image.PixelMap](js-apis-image.md#pixelmap7) | Yes | Yes | Picture attached to the notification.                  |


## NotificationContent

Describes the notification content.

**System capability**: SystemCapability.Notification.Notification

| Name       | Type                                                        | Readable| Writable| Description              |
| ----------- | ------------------------------------------------------------ | ---- | --- | ------------------ |
| contentType | [ContentType](#contenttype)                                  | Yes | Yes | Notification content type.      |
| normal      | [NotificationBasicContent](#notificationbasiccontent)        | Yes | Yes | Normal text.  |
| longText    | [NotificationLongTextContent](#notificationlongtextcontent)  | Yes | Yes | Long text.|
| multiLine   | [NotificationMultiLineContent](#notificationmultilinecontent) | Yes | Yes | Multi-line text.  |
| picture     | [NotificationPictureContent](#notificationpicturecontent)    | Yes | Yes | Picture-attached.  |


## NotificationFlagStatus

Describes the notification flag status.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name          | Value | Description                              |
| -------------- | --- | --------------------------------- |
| TYPE_NONE      | 0   | The default flag is used.                        |
| TYPE_OPEN      | 1   | The notification flag is enabled.                    |
| TYPE_CLOSE     | 2   | The notification flag is disabled.                    |


## NotificationFlags

Enumerates notification flags.

**System capability**: SystemCapability.Notification.Notification

| Name            | Type                   | Readable| Writable| Description                              |
| ---------------- | ---------------------- | ---- | ---- | --------------------------------- |
| soundEnabled     | [NotificationFlagStatus](#notificationflagstatus) | Yes  | No  | Whether to enable the sound alert for the notification.                 |
| vibrationEnabled | [NotificationFlagStatus](#notificationflagstatus) | Yes  | No  |   Whether to enable vibration for the notification.              |


## NotificationRequest

Describes the notification request.

**System capability**: SystemCapability.Notification.Notification

| Name                 | Type                                         | Readable| Writable| Description                      |
| --------------------- | --------------------------------------------- | ---- | --- | -------------------------- |
| content               | [NotificationContent](#notificationcontent)   | Yes | Yes | Notification content.                  |
| id                    | number                                        | Yes | Yes | Notification ID.                    |
| slotType              | [SlotType](#slottype)                         | Yes | Yes | Notification slot type.                  |
| isOngoing             | boolean                                       | Yes | Yes | Whether the notification is an ongoing notification.            |
| isUnremovable         | boolean                                       | Yes | Yes | Whether the notification can be removed.                |
| deliveryTime          | number                                        | Yes | Yes | Time when the notification is sent.              |
| tapDismissed          | boolean                                       | Yes | Yes | Whether the notification is automatically cleared.          |
| autoDeletedTime       | number                                        | Yes | Yes | Time when the notification is automatically cleared.            |
| wantAgent             | [WantAgent](js-apis-app-ability-wantAgent.md) | Yes | Yes | **WantAgent** instance to which the notification will be redirected after being clicked.|
| extraInfo             | {[key: string]: any}                          | Yes | Yes | Extended parameters.                  |
| color                 | number                                        | Yes | Yes | Background color of the notification. Not supported currently.|
| colorEnabled          | boolean                                       | Yes | Yes | Whether the notification background color can be enabled. Not supported currently.|
| isAlertOnce           | boolean                                       | Yes | Yes | Whether the notification triggers an alert only once.|
| isStopwatch           | boolean                                       | Yes | Yes | Whether to display the stopwatch.          |
| isCountDown           | boolean                                       | Yes | Yes | Whether to display the countdown time.        |
| isFloatingIcon        | boolean                                       | Yes | Yes | Whether the notification is displayed as a floating icon in the status bar.        |
| label                 | string                                        | Yes | Yes | Notification label.                  |
| badgeIconStyle        | number                                        | Yes | Yes | Notification badge type.              |
| showDeliveryTime      | boolean                                       | Yes | Yes | Whether to display the time when the notification is delivered.          |
| actionButtons         | Array\<[NotificationActionButton](#notificationactionbutton)\>             | Yes | Yes | Buttons in the notification. Up to three buttons are allowed. |
| smallIcon             | [image.PixelMap](js-apis-image.md#pixelmap7) | Yes | Yes | Small notification icon. This field is optional, and the icon size cannot exceed 30 KB.|
| largeIcon             | [image.PixelMap](js-apis-image.md#pixelmap7) | Yes | Yes | Large notification icon. This field is optional, and the icon size cannot exceed 30 KB.|
| creatorBundleName     | string                                        | Yes | No | Name of the bundle that creates the notification.            |
| creatorUid            | number                                        | Yes | No | UID used for creating the notification.             |
| creatorPid            | number                                        | Yes | No | PID used for creating the notification.             |
| creatorUserId| number                                    | Yes | No | ID of the user who creates the notification.          |
| hashCode              | string                                        | Yes | No | Unique ID of the notification.              |
| classification        | string                                        | Yes | Yes | Notification category.<br>**System API**: This is a system API and cannot be called by third-party applications.                  |
| groupName| string                                        | Yes | Yes | Notification group name.                |
| template | [NotificationTemplate](#notificationtemplate) | Yes | Yes | Notification template.                  |
| isRemoveAllowed | boolean                                | Yes | No | Whether the notification can be removed.<br>**System API**: This is a system API and cannot be called by third-party applications.                  |
| source   | number                                        | Yes | No | Notification source.<br>**System API**: This is a system API and cannot be called by third-party applications.                  |
| distributedOption   | [DistributedOptions](#distributedoptions)                 | Yes | Yes | Distributed notification options.         |
| deviceId | string                                        | Yes | No | Device ID of the notification source.<br>**System API**: This is a system API and cannot be called by third-party applications.         |
| notificationFlags | [NotificationFlags](#notificationflags)                    | Yes | No | Notification flags.         |
| removalWantAgent | [WantAgent](js-apis-app-ability-wantAgent.md) | Yes | Yes | **WantAgent** instance to which the notification will be redirected when it is removed.         |
| badgeNumber | number                    | Yes | Yes | Number of notifications displayed on the application icon.         |


## DistributedOptions

Describes distributed options.

**System capability**: SystemCapability.Notification.Notification

| Name                  | Type           | Readable| Writable| Description                              |
| ---------------------- | -------------- | ---- | ---- | ---------------------------------- |
| isDistributed          | boolean        | Yes  | Yes  | Whether the notification is a distributed notification.                 |
| supportDisplayDevices  | Array\<string> | Yes  | Yes  | List of the devices to which the notification can be synchronized.        |
| supportOperateDevices  | Array\<string> | Yes  | Yes  | List of the devices on which the notification can be opened.             |
| remindType             | number         | Yes  | No  | Notification reminder type.<br>**System API**: This is a system API and cannot be called by third-party applications.                   |


## NotificationSlot

Describes the notification slot.

**System capability**: SystemCapability.Notification.Notification

| Name                | Type                 | Readable| Writable| Description                                      |
| -------------------- | --------------------- | ---- | --- | ------------------------------------------ |
| type                 | [SlotType](#slottype) | Yes | Yes | Notification slot type.                                  |
| level                | number                | Yes | Yes | Notification level. If this parameter is not set, the default value is used based on the notification slot type.|
| desc                 | string                | Yes | Yes | Notification slot description.                          |
| badgeFlag            | boolean               | Yes | Yes | Whether to display the badge.                              |
| bypassDnd            | boolean               | Yes | Yes | Whether to bypass DND mode in the system.              |
| lockscreenVisibility | number                | Yes | Yes | Mode for displaying the notification on the lock screen.                |
| vibrationEnabled     | boolean               | Yes | Yes | Whether vibration is enabled for the notification.                                |
| sound                | string                | Yes | Yes | Notification alert tone.                                |
| lightEnabled         | boolean               | Yes | Yes | Whether the indicator blinks for the notification.                                  |
| lightColor           | number                | Yes | Yes | Indicator color of the notification.                                |
| vibrationValues      | Array\<number\>       | Yes | Yes | Vibration mode of the notification.                              |
| enabled<sup>9+</sup> | boolean               | Yes | No | Whether the notification slot is enabled.                     |


## NotificationTemplate

Describes the notification template.

**System capability**: SystemCapability.Notification.Notification

| Name| Type                   | Readable| Writable| Description      |
| ---- | ---------------------- | ---- | ---- | ---------- |
| name | string                 | Yes  | Yes  | Template name.|
| data | {[key:string]: Object} | Yes  | Yes  | Template data.|


## NotificationUserInput

Provides the notification user input.

**System capability**: SystemCapability.Notification.Notification

| Name    | Type  | Readable| Writable| Description                         |
| -------- | ------ | --- | ---- | ----------------------------- |
| inputKey | string | Yes | Yes | Key to identify the user input.|


## DeviceRemindType

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name                | Value | Description                              |
| -------------------- | --- | --------------------------------- |
| IDLE_DONOT_REMIND    | 0   | The device is not in use. No notification is required.           |
| IDLE_REMIND          | 1   | The device is not in use.                |
| ACTIVE_DONOT_REMIND  | 2   | The device is in use. No notification is required.           |
| ACTIVE_REMIND        | 3   | The device is in use.                |


## SourceType

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name                | Value | Description                 |
| -------------------- | --- | -------------------- |
| TYPE_NORMAL          | 0   | Normal notification.           |
| TYPE_CONTINUOUS      | 1   | Continuous notification.           |
| TYPE_TIMER           | 2   | Timed notification.           |
