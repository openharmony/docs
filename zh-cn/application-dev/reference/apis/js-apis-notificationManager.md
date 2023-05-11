# @ohos.notificationManager (NotificationManager模块)

本模块提供通知管理的能力，包括发布、取消发布通知，创建、获取、移除通知通道，获取通知的使能状态、角标使能状态，获取通知的相关信息等。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import notificationManager from '@ohos.notificationManager';
```

## notificationManager.publish

publish(request: NotificationRequest, callback: AsyncCallback\<void\>): void

发布通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |
| callback | AsyncCallback\<void\>                       | 是   | 发布通知的回调方法。                        |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600009  | Over max number notifications per second. |
| 1600012  | No memory space.                          |

**示例：**

```ts
//publish回调
function publishCallback(err) {
    if (err) {
        console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publish success");
    }
}
//通知Request对象
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

发布通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600009  | Over max number notifications per second. |
| 1600012  | No memory space.                          |

**示例：**

```ts
// 通知Request对象
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

发布通知给指定的用户（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |
| userId   | number                                      | 是   | 用户ID。                           |
| callback | AsyncCallback\<void\>                       | 是   | 被指定的回调方法。                           |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 202      | Not system application to call the interface.   |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600008  | The user is not exist.                    |
| 1600009  | Over max number notifications per second. |
| 1600012  | No memory space.                          |

**示例：**

```ts
// publish回调
function publishCallback(err) {
    if (err) {
        console.error(`publish failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publish success");
    }
}
// 用户ID
let userId = 1;
// 通知Request对象
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

发布通知给指定的用户（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     |  类型                                        | 必填 | 说明                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |
| userId   | number                                      | 是   | 用户ID。                           |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 201      | Permission denied.                        |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600008  | The user is not exist.                    |
| 1600009  | Over max number notifications per second. |
| 1600012  | No memory space.                          |

**示例：**

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

通过通知ID和通知标签取消已发布的通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| id       | number                | 是   | 通知ID。               |
| label    | string                | 是   | 通知标签。             |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**示例：**

```ts
// cancel回调
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

取消与指定通知ID相匹配的已发布通知，label可以指定也可以不指定（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名  | 类型   | 必填 | 说明     |
| ----- | ------ | ---- | -------- |
| id    | number | 是   | 通知ID。   |
| label | string | 否   | 通知标签。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**示例：**

```ts
notificationManager.cancel(0).then(() => {
	console.info("cancel success");
});
```

## notificationManager.cancel

cancel(id: number, callback: AsyncCallback\<void\>): void

取消与指定通知ID相匹配的已发布通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| id       | number                | 是   | 通知ID。               |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**示例：**

```ts
// cancel回调
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

取消所有已发布的通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**示例：**

```ts
// cancel回调
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

取消所有已发布的通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
notificationManager.cancelAll().then(() => {
	console.info("cancelAll success");
});
```

## notificationManager.addSlot

addSlot(slot: NotificationSlot, callback: AsyncCallback\<void\>): void

创建通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| slot     | [NotificationSlot](js-apis-inner-notification-notificationSlot.md)       | 是   | 要创建的通知通道对象。 |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**示例：**

```ts
// addslot回调
function addSlotCallBack(err) {
    if (err) {
        console.error(`addSlot failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("addSlot success");
    }
}
// 通知slot对象
let notificationSlot = {
    type: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
notificationManager.addSlot(notificationSlot, addSlotCallBack);
```

## notificationManager.addSlot

addSlot(slot: NotificationSlot): Promise\<void\>

创建通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型             | 必填 | 说明                 |
| ---- | ---------------- | ---- | -------------------- |
| slot | [NotificationSlot](js-apis-inner-notification-notificationSlot.md) | 是   | 要创建的通知通道对象。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**示例：**

```ts
// 通知slot对象
let notificationSlot = {
    type: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
notificationManager.addSlot(notificationSlot).then(() => {
	console.info("addSlot success");
});
```

## notificationManager.addSlot

addSlot(type: SlotType, callback: AsyncCallback\<void\>): void

创建指定类型的通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| type     | [SlotType](#slottype)              | 是   | 要创建的通知通道的类型。 |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。   |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |

**示例：**

```ts
// addslot回调
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

创建指定类型的通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名 | 类型     | 必填 | 说明                   |
| ---- | -------- | ---- | ---------------------- |
| type | [SlotType](#slottype) | 是   | 要创建的通知通道的类型。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                    |

**示例：**

```ts
notificationManager.addSlot(notificationManager.SlotType.SOCIAL_COMMUNICATION).then(() => {
	console.info("addSlot success");
});
```

## notificationManager.addSlots

addSlots(slots: Array\<NotificationSlot\>, callback: AsyncCallback\<void\>): void

创建多个通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                      | 必填 | 说明                     |
| -------- | ------------------------- | ---- | ------------------------ |
| slots    | Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\> | 是   | 要创建的通知通道对象数组。 |
| callback | AsyncCallback\<void\>     | 是   | 表示被指定的回调方法。     |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**示例：**

```ts
// addSlots回调
function addSlotsCallBack(err) {
    if (err) {
        console.error(`addSlots failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("addSlots success");
    }
}
// 通知slot对象
let notificationSlot = {
    type: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
// 通知slot array 对象
let notificationSlotArray = new Array();
notificationSlotArray[0] = notificationSlot;

notificationManager.addSlots(notificationSlotArray, addSlotsCallBack);
```

## notificationManager.addSlots

addSlots(slots: Array\<NotificationSlot\>): Promise\<void\>

创建多个通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名  | 类型                      | 必填 | 说明                     |
| ----- | ------------------------- | ---- | ------------------------ |
| slots | Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\> | 是   | 要创建的通知通道对象数组。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**示例：**

```ts
// 通知slot对象
let notificationSlot = {
    type: notificationManager.SlotType.SOCIAL_COMMUNICATION
};
// 通知slot array 对象
let notificationSlotArray = new Array();
notificationSlotArray[0] = notificationSlot;

notificationManager.addSlots(notificationSlotArray).then(() => {
	console.info("addSlots success");
});
```

## notificationManager.getSlot

getSlot(slotType: SlotType, callback: AsyncCallback\<NotificationSlot\>): void

获取一个指定类型的通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                                        |
| -------- | --------------------------------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype)                          | 是   | 通知渠道类型，目前分为社交通信、服务提醒、内容咨询和其他类型。 |
| callback | AsyncCallback\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\> | 是   | 表示被指定的回调方法。                                        |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
// getSlot回调
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

获取一个指定类型的通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型     | 必填 | 说明                                                        |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype) | 是   | 通知渠道类型，目前分为社交通信、服务提醒、内容咨询和其他类型。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<NotificationSlot\> | 以Promise形式返回获取一个通知通道。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
let slotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
notificationManager.getSlot(slotType).then((data) => {
	console.info("getSlot success, data: " + JSON.stringify(data));
});
```

## notificationManager.getSlots

getSlots(callback: AsyncCallback<Array\<NotificationSlot\>>): void

获取此应用程序的所有通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 参数名     | 类型                              | 必填 | 说明                 |
| -------- | --------------------------------- | ---- | -------------------- |
| callback | AsyncCallback\<Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\>\> | 是   | 以callback形式返回获取此应用程序的所有通知通道的结果。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
// getSlots回调
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

获取此应用程序的所有通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\>\> | 以Promise形式返回获取此应用程序的所有通知通道的结果。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
notificationManager.getSlots().then((data) => {
	console.info("getSlots success, data: " + JSON.stringify(data));
});
```

## notificationManager.removeSlot

removeSlot(slotType: SlotType, callback: AsyncCallback\<void\>): void

删除指定类型的通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                  | 必填 | 说明                                                        |
| -------- | --------------------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype)              | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。                                        |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
// removeSlot回调
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

删除指定类型的通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型     | 必填 | 说明                                                        |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype) | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
let slotType = notificationManager.SlotType.SOCIAL_COMMUNICATION;
notificationManager.removeSlot(slotType).then(() => {
	console.info("removeSlot success");
});
```

## notificationManager.removeAllSlots

removeAllSlots(callback: AsyncCallback\<void\>): void

删除所有通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

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

删除所有通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
notificationManager.removeAllSlots().then(() => {
	console.info("removeAllSlots success");
});
```

## notificationManager.setNotificationEnable

setNotificationEnable(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

设定指定应用的通知使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)   | 是   | 指定应用的包信息。        |
| enable   | boolean               | 是   | 使能状态。             |
| callback | AsyncCallback\<void\> | 是   | 设定通知使能回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

设定指定应用的通知使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| enable | boolean      | 是   | 使能状态。   |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

获取指定应用的通知使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名     | 类型                  | 必填 | 说明                     |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。            |
| callback | AsyncCallback\<void\> | 是   | 获取通知使能状态回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

获取指定应用的通知使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型               | 说明                                                |
| ------------------ | --------------------------------------------------- |
| Promise\<boolean\> | 以Promise形式返回获取指定应用的通知使能状态的结果。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

获取通知使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                     |
| -------- | --------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void\> | 是   | 获取通知使能状态回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

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

获取通知使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取通知使能状态的结果。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
notificationManager.isNotificationEnabled().then((data) => {
	console.info("isNotificationEnabled success, data: " + JSON.stringify(data));
});
```

## notificationManager.displayBadge

displayBadge(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

设定指定应用的角标使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。           |
| enable   | boolean               | 是   | 使能状态。             |
| callback | AsyncCallback\<void\> | 是   | 设定角标使能回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

设定指定应用的角标使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| enable | boolean      | 是   | 使能状态。   |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

获取指定应用的角标使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                     |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。               |
| callback | AsyncCallback\<void\> | 是   | 获取角标使能状态回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

获取指定应用的角标使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取指定应用的角标使能状态。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

设定角标个数，在应用的桌面图标上呈现（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名      | 类型   | 必填 | 说明       |
| ----------- | ------ | ---- | ---------- |
| badgeNumber | number | 是   | 角标个数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**示例：**

```ts
let badgeNumber = 10
notificationManager.setBadgeNumber(badgeNumber).then(() => {
	console.info("displayBadge success");
});
```

## notificationManager.setBadgeNumber<sup>10+</sup>

setBadgeNumber(badgeNumber: number, callback: AsyncCallback\<void\>): void

设定角标个数，在应用的桌面图标上呈现（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名      | 类型                  | 必填 | 说明               |
| ----------- | --------------------- | ---- | ------------------ |
| badgeNumber | number                | 是   | 角标个数。         |
| callback    | AsyncCallback\<void\> | 是   | 设定角标回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**示例：**

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

设定指定应用的通知通道（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 指定应用的包信息。           |
| slot     | [NotificationSlot](js-apis-inner-notification-notificationSlot.md)      | 是   | 通知通道。             |
| callback | AsyncCallback\<void\> | 是   | 设定通知通道回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

设定指定应用的通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |
| slot   | [NotificationSlot](js-apis-inner-notification-notificationSlot.md) | 是   | 通知通道。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

获取指定应用的所有通知通道（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                                     | 必填 | 说明                 |
| -------- | ---------------------------------------- | ---- | -------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)                             | 是   | 指定应用的包信息。           |
| callback | AsyncCallback<Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\>> | 是   | 获取通知通道回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

获取指定应用的所有通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise<Array\<[NotificationSlot](js-apis-inner-notification-notificationSlot.md)\>> | 以Promise形式返回获取指定应用的通知通道。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

获取指定应用的通知通道数量（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                      | 必填 | 说明                   |
| -------- | ------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)              | 是   | 指定应用的包信息。             |
| callback | AsyncCallback\<number\> | 是   | 获取通知通道数量回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

获取指定应用的通知通道数量（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 指定应用的包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | 以Promise形式返回获取指定应用的通知通道数量。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

获取当前未删除的所有通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| -------- | ------------------------------------------------------------ | ---- | -------------------- |
| callback | AsyncCallback<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)\>> | 是   | 获取活动通知回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

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

getAllActiveNotifications(): Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)\>\>

获取当前未删除的所有通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)\>\> | 以Promise形式返回获取活动通知。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
notificationManager.getAllActiveNotifications().then((data) => {
	console.info("getAllActiveNotifications success, data: " + JSON.stringify(data));
});
```

## notificationManager.getActiveNotificationCount

getActiveNotificationCount(callback: AsyncCallback\<number\>): void

获取当前应用未删除的通知数（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                   | 必填 | 说明                   |
| -------- | ---------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<number\> | 是   | 获取未删除通知数回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

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

获取当前应用未删除的通知数（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型              | 说明                                        |
| ----------------- | ------------------------------------------- |
| Promise\<number\> | 以Promise形式返回获取当前应用未删除通知数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
notificationManager.getActiveNotificationCount().then((data) => {
	console.info("getActiveNotificationCount success, data: " + JSON.stringify(data));
});
```

## notificationManager.getActiveNotifications

getActiveNotifications(callback: AsyncCallback<Array\<NotificationRequest\>>): void

获取当前应用未删除的通知列表（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)\>> | 是   | 获取当前应用通知列表回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

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

getActiveNotifications(): Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)\>\>

获取当前应用未删除的通知列表（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型                                                         | 说明                                    |
| ------------------------------------------------------------ | --------------------------------------- |
| Promise\<Array\<[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)\>\> | 以Promise形式返回获取当前应用通知列表。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
notificationManager.getActiveNotifications().then((data) => {
	console.info("removeGroupByBundle success, data: " + JSON.stringify(data));
});
```

## notificationManager.cancelGroup

cancelGroup(groupName: string, callback: AsyncCallback\<void\>): void

取消本应用指定组下的通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名      | 类型                  | 必填 | 说明                         |
| --------- | --------------------- | ---- | ---------------------------- |
| groupName | string                | 是   | 通知组名称，此名称需要在发布通知时通过[NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest)对象指定。 |
| callback  | AsyncCallback\<void\> | 是   | 取消本应用指定组下通知的回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

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

取消本应用指定组下的通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名      | 类型   | 必填 | 说明           |
| --------- | ------ | ---- | -------------- |
| groupName | string | 是   | 通知组名称。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
let groupName = "GroupName";
notificationManager.cancelGroup(groupName).then(() => {
	console.info("cancelGroup success");
});
```

## notificationManager.removeGroupByBundle

removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void\>): void

删除指定应用的指定组下的通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名      | 类型                  | 必填 | 说明                         |
| --------- | --------------------- | ---- | ---------------------------- |
| bundle    | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)          | 是   | 应用的包信息。                   |
| groupName | string                | 是   | 通知组名称。               |
| callback  | AsyncCallback\<void\> | 是   | 删除指定应用指定组下通知的回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

删除指定应用的指定组下的通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名      | 类型         | 必填 | 说明           |
| --------- | ------------ | ---- | -------------- |
| bundle    | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。     |
| groupName | string       | 是   | 通知组名称。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
let bundleOption = {bundle: "Bundle"};
let groupName = "GroupName";
notificationManager.removeGroupByBundle(bundleOption, groupName).then(() => {
	console.info("removeGroupByBundle success");
});
```

## notificationManager.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, callback: AsyncCallback\<void\>): void

设置免打扰时间（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate)      | 是   | 免打扰时间选项。         |
| callback | AsyncCallback\<void\> | 是   | 设置免打扰时间回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**示例：**

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

设置免打扰时间（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型             | 必填 | 说明           |
| ---- | ---------------- | ---- | -------------- |
| date | [DoNotDisturbDate](#donotdisturbdate) | 是   | 免打扰时间选项。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**示例：**

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

指定用户设置免打扰时间（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate)      | 是   | 免打扰时间选项。         |
| userId   | number                | 是   | 设置免打扰时间的用户ID。 |
| callback | AsyncCallback\<void\> | 是   | 设置免打扰时间回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |
| 1600012  | No memory space.                          |

**示例：**

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

指定用户设置免打扰时间（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型             | 必填 | 说明           |
| ------ | ---------------- | ---- | -------------- |
| date   | [DoNotDisturbDate](#donotdisturbdate) | 是   | 免打扰时间选项。 |
| userId | number           | 是   | 设置免打扰时间的用户ID。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |
| 1600012  | No memory space.                          |

**示例：**

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

查询免打扰时间（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                              | 必填 | 说明                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate)\> | 是   | 查询免打扰时间回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**示例：**

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

查询免打扰时间（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型                                             | 说明                                      |
| ------------------------------------------------ | ----------------------------------------- |
| Promise\<[DoNotDisturbDate](#donotdisturbdate)\> | 以Promise形式返回获取查询到的免打扰时间。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600012  | No memory space.                          |

**示例：**

```ts
notificationManager.getDoNotDisturbDate().then((data) => {
	console.info("getDoNotDisturbDate success, data: " + JSON.stringify(data));
});
```


## notificationManager.getDoNotDisturbDate

getDoNotDisturbDate(userId: number, callback: AsyncCallback\<DoNotDisturbDate\>): void

查询指定用户的免打扰时间（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                              | 必填 | 说明                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate)\> | 是   | 查询免打扰时间回调函数。 |
| userId   | number                            | 是   | 用户ID。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |
| 1600012  | No memory space.                          |

**示例：**

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

查询指定用户的免打扰时间（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                              | 必填 | 说明                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| userId   | number                            | 是   | 用户ID。 |

**返回值：**

| 类型                                             | 说明                                      |
| ------------------------------------------------ | ----------------------------------------- |
| Promise\<[DoNotDisturbDate](#donotdisturbdate)\> | 以Promise形式返回获取查询到的免打扰时间。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |
| 1600012  | No memory space.                          |

**示例：**

```ts
let userId = 1;

notificationManager.getDoNotDisturbDate(userId).then((data) => {
	console.info("getDoNotDisturbDate success, data: " + JSON.stringify(data));
});
```


## notificationManager.isSupportDoNotDisturbMode

 isSupportDoNotDisturbMode(callback: AsyncCallback\<boolean\>): void

查询是否支持免打扰功能（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                     | 必填 | 说明                             |
| -------- | ------------------------ | ---- | -------------------------------- |
| callback | AsyncCallback\<boolean\> | 是   | 查询是否支持免打扰功能回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

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

查询是否支持勿扰模式功能（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取是否支持免打扰功能的结果。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```ts
notificationManager.isSupportDoNotDisturbMode().then((data) => {
	console.info("supportDoNotDisturbMode success, data: " + JSON.stringify(data));
});
```

## notificationManager.isSupportTemplate

isSupportTemplate(templateName: string, callback: AsyncCallback\<boolean\>): void

查询模板是否存在（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名       | 类型                     | 必填 | 说明                       |
| ------------ | ------------------------ | ---- | -------------------------- |
| templateName | string                   | 是   | 模板名称。                   |
| callback     | AsyncCallback\<boolean\> | 是   | 查询模板是否存在的回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600011  | Read template config failed.        |

**示例：**

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

查询模板是否存在（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名       | 类型   | 必填 | 说明     |
| ------------ | ------ | ---- | -------- |
| templateName | string | 是   | 模板名称。 |

**返回值：**

| 类型               | 说明            |
| ------------------ | --------------- |
| Promise\<boolean\> | Promise方式返回模板是否存在的结果。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600011  | Read template config failed.        |

**示例：**

```javascript
let templateName = 'process';

notificationManager.isSupportTemplate(templateName).then((data) => {
    console.info("isSupportTemplate success, data: " + JSON.stringify(data));
});
```

## notificationManager.requestEnableNotification

requestEnableNotification(callback: AsyncCallback\<void\>): void

应用请求通知使能（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<void\> | 是   | 应用请求通知使能的回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

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

应用请求通知使能（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```javascript
notificationManager.requestEnableNotification().then(() => {
    console.info("requestEnableNotification success");
});
```



## notificationManager.setDistributedEnable

setDistributedEnable(enable: boolean, callback: AsyncCallback\<void\>): void

设置设备是否支持分布式通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | 是   | 是否支持。 |
| callback | AsyncCallback\<void\> | 是   | 设置设备是否支持分布式通知的回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600010  | Distributed operation failed.       |

**示例：**

```javascript
function setDistributedEnableCallback(err) {
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

设置设备是否支持分布式通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | 是   | 是否支持。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600010  | Distributed operation failed.       |

**示例：**

```javascript
let enable = true;

notificationManager.setDistributedEnable(enable).then(() => {
        console.info("setDistributedEnable success");
    });
```


## notificationManager.isDistributedEnabled

isDistributedEnabled(callback: AsyncCallback\<boolean>): void

查询设备是否支持分布式通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<boolean\> | 是   | 设备是否支持分布式通知的回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600010  | Distributed operation failed.       |

**示例：**

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

查询设备是否支持分布式通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型               | 说明                                          |
| ------------------ | --------------------------------------------- |
| Promise\<boolean\> | Promise方式返回设备是否支持分布式通知的结果。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 401      | The parameter check failed.         |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600010  | Distributed operation failed.       |

**示例：**

```javascript
notificationManager.isDistributedEnabled()
    .then((data) => {
        console.info("isDistributedEnabled success, data: " + JSON.stringify(data));
    });
```


## notificationManager.setDistributedEnableByBundle

setDistributedEnableByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void

设置指定应用是否支持分布式通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包信息。                   |
| enable   | boolean                  | 是   | 是否支持。                       |
| callback | AsyncCallback\<void\> | 是   | 应用程序是否支持分布式通知的回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

设置指定应用是否支持分布式通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包。                |
| enable   | boolean                  | 是   | 是否支持。                  |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

根据应用的包获取应用程序是否支持分布式通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包。                     |
| callback | AsyncCallback\<boolean\> | 是   | 查询指定应用是否支持分布式通知的回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**示例：**

```javascript
function isDistributedEnabledByBundleCallback(err, data) {
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

查询指定应用是否支持分布式通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption)             | 是   | 应用的包。                |

**返回值：**

| 类型               | 说明                                              |
| ------------------ | ------------------------------------------------- |
| Promise\<boolean\> | Promise方式返回指定应用是否支持分布式通知的结果。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

获取通知的提醒方式（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                               | 必填 | 说明                       |
| -------- | --------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<[DeviceRemindType](#deviceremindtype)\> | 是   | 获取通知提醒方式的回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

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

获取通知的提醒方式（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型               | 说明            |
| ------------------ | --------------- |
| Promise\<[DeviceRemindType](#deviceremindtype)\> | Promise方式返回获取通知提醒方式的结果。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```javascript
notificationManager.getDeviceRemindType().then((data) => {
    console.info("getDeviceRemindType success, data: " + JSON.stringify(data));
});
```


## notificationManager.publishAsBundle

publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number, callback: AsyncCallback\<void\>): void

发布代理通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名               | 类型                                        | 必填 | 说明                                     |
| -------------------- | ------------------------------------------- | ---- | ---------------------------------------- |
| request              | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |
| representativeBundle | string                                      | 是   | 被代理应用的包名。                       |
| userId               | number                                      | 是   | 用户ID。                                 |
| callback             | AsyncCallback                               | 是   | 发布代理通知的回调方法。                 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600008  | The user is not exist.                    |
| 1600009  | Over max number notifications per second. |
| 1600012  | No memory space.                          |

**示例：**

```ts
//publishAsBundle回调
function callback(err) {
    if (err) {
        console.error(`publishAsBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("publishAsBundle success");
    }
}
// 被代理应用的包名
let representativeBundle = "com.example.demo";
// 用户ID
let userId = 100;
// NotificationRequest对象
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

发布代理通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**


| 参数名               | 类型                                        | 必填 | 说明                                          |
| -------------------- | ------------------------------------------- | ---- | --------------------------------------------- |
| request              | [NotificationRequest](js-apis-inner-notification-notificationRequest.md#notificationrequest) | 是   | 用于设置要发布通知的内容和相关配置信息。 |
| representativeBundle | string                                      | 是   | 被代理应用的包名。                            |
| userId               | number                                      | 是   | 用户ID。                            |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600008  | The user is not exist.                    |
| 1600009  | Over max number notifications per second. |
| 1600012  | No memory space.                          |

**示例：**

```ts
// 被代理应用的包名
let representativeBundle = "com.example.demo";
// 用户ID
let userId = 100;
// NotificationRequest对象
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

取消代理通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名               | 类型          | 必填 | 说明                     |
| -------------------- | ------------- | ---- | ------------------------ |
| id                   | number        | 是   | 通知ID。                 |
| representativeBundle | string        | 是   | 被代理应用的包名。       |
| userId               | number        | 是   | 用户ID。       |
| callback             | AsyncCallback | 是   | 取消代理通知的回调方法。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |
| 1600008  | The user is not exist.              |

**示例：**

```ts
// cancelAsBundle
function cancelAsBundleCallback(err) {
    if (err) {
        console.error(`cancelAsBundle failed, code is ${err.code}, message is ${err.message}`);
    } else {
        console.info("cancelAsBundle success");
    }
}
// 被代理应用的包名
let representativeBundle = "com.example.demo";
// 用户ID
let userId = 100;

notificationManager.cancelAsBundle(0, representativeBundle, userId, cancelAsBundleCallback);
```

## notificationManager.cancelAsBundle

cancelAsBundle(id: number, representativeBundle: string, userId: number): Promise\<void\>

取消代理通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名               | 类型   | 必填 | 说明               |
| -------------------- | ------ | ---- | ------------------ |
| id                   | number | 是   | 通知ID。           |
| representativeBundle | string | 是   | 被代理应用的包名。 |
| userId               | number | 是   | 用户ID。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |
| 1600008  | The user is not exist.              |

**示例：**

```ts
// 被代理应用的包名
let representativeBundle = "com.example.demo";
// 用户ID
let userId = 100;

notificationManager.cancelAsBundle(0, representativeBundle, userId).then(() => {
	console.info("cancelAsBundle success");
});
```

## notificationManager.setNotificationEnableSlot 

setNotificationEnableSlot(bundle: BundleOption, type: SlotType, enable: boolean, callback: AsyncCallback\<void>): void

设置指定应用的指定渠道类型的使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名   | 类型                          | 必填 | 说明                   |
| -------- | ----------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。           |
| type     | [SlotType](#slottype)         | 是   | 指定渠道类型。         |
| enable   | boolean                       | 是   | 使能状态。             |
| callback | AsyncCallback\<void\>         | 是   | 设置渠道使能回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

设置指定应用的指定渠道类型的使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。   |
| type   | [SlotType](#slottype)         | 是   | 渠道类型。 |
| enable | boolean                       | 是   | 使能状态。     |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

获取指定应用的指定渠道类型的使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名   | 类型                          | 必填 | 说明                   |
| -------- | ----------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。           |
| type     | [SlotType](#slottype)         | 是   | 渠道类型。         |
| callback | AsyncCallback\<boolean\>         | 是   | 获取渠道使能状态回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

获取指定应用的指定渠道类型的使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| bundle | [BundleOption](./js-apis-inner-notification-notificationCommonDef.md#bundleoption) | 是   | 应用的包信息。   |
| type   | [SlotType](#slottype)         | 是   | 渠道类型。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回指定类型的渠道使能状态。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```ts
// isNotificationSlotEnabled
notificationManager.isNotificationSlotEnabled({ bundle: "ohos.samples.notification", },
    notificationManager.SlotType.SOCIAL_COMMUNICATION).then((data) => {
    console.info("isNotificationSlotEnabled success, data: " + JSON.stringify(data));
});
```


## notificationManager.setSyncNotificationEnabledWithoutApp

setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean, callback: AsyncCallback\<void\>): void

设置是否将通知同步到未安装应用程序的设备(callback形式)。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：** 

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | 是   | 用户ID。   |
| enable | boolean | 是   | 是否启用。   |
| callback | AsyncCallback\<void\>    | 是   | 设置是否将通知同步到未安装应用程序的设备的回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**示例：**

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

设置是否将通知同步到未安装应用程序的设备(Promise形式)。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | 是   | 用户ID。   |
| enable | boolean | 是   | 是否启用。   |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<void\> | 以Promise形式返回设置是否将通知同步到未安装应用程序的设备的结果。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**示例：**

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

获取同步通知到未安装应用程序设备的开关是否开启(callback形式)。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | 是   | 用户ID。   |
| callback | AsyncCallback\<boolean\>         | 是   | 获取同步通知到未安装应用程序设备的开关是否开启的回调函数。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**示例：**

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

获取同步通知到未安装应用程序设备的开关是否开启(Promise形式)。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | 是   | 用户ID。   |

**返回值：**

| 类型               | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取同步通知到未安装应用程序设备的开关是否开启的结果。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 201      | Permission denied.                        |
| 202      | Not system application to call the interface. |
| 401      | The parameter check failed.               |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**示例：**

```ts
let userId = 100;
notificationManager.getSyncNotificationEnabledWithoutApp(userId).then((data) => {
    console.info('getSyncNotificationEnabledWithoutApp, data:' + data);
}).catch((err) => {
    console.info('getSyncNotificationEnabledWithoutApp, err:' + err);
});
```

## notificationManager.on<sup>10+</sup>

on(type: 'checkNotification', callback: (checkInfo: NotificationCheckInfo) => NotificationCheckResult): void;

注册通知监听回调。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER and ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| type | string | 是   | 回调函数类型名，固定为'checkNotification'。 |
| callback | (checkInfo: [NotificationCheckInfo](#notificationcheckinfo)) =>  [NotificationCheckResult](#notificationcheckresult)    | 是   | 消息验证函数指针。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息        |
| -------- | --------------- |
| 1600001  | Internal error. |

**示例：**

```ts
try{
    notificationManager.on("checkNotification", OnCheckNotification);
} catch (error){
    console.info(`notificationManager.on error: ${JSON.stringify(error)}`);
}
function OnCheckNotification(info : notificationManager.NotificationCheckInfo) {
    console.info(`====>OnCheckNotification info: ${JSON.stringify(info)}`);
    if(info.notificationId == 1){
        return { code: 1, message: "testMsg1"}
    } else {
        return { code: 0, message: "testMsg0"}
    }
}
```

## notificationManager.off<sup>10+</sup>

off(type: 'checkNotification', callback?: (checkInfo: NotificationCheckInfo) => NotificationCheckResult): void;

取消通知监听回调。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER and ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| type | string                                                       | 是   | 回调函数类型名，固定为'checkNotification'。 |
| callback | (checkInfo: [NotificationCheckInfo](#notificationcheckinfo)) =>  [NotificationCheckResult](#notificationcheckresult)  | 否   | 消息验证函数指针。 |

**错误码：**

错误码详细介绍请参考[errcode-notification](../errorcodes/errorcode-notification.md)。

| 错误码ID | 错误信息        |
| -------- | --------------- |
| 1600001  | Internal error. |

**示例：**

```ts
try{
    notificationManager.off("checkNotification");
} catch (error){
    console.info(`notificationManager.off error: ${JSON.stringify(error)}`);
}
```

## DoNotDisturbDate

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称  | 类型                                  | 可读 | 可写 | 说明                   |
| ----- | ------------------------------------- | ---- | ---- | ---------------------- |
| type  | [DoNotDisturbType](#donotdisturbtype) | 是   | 是   | 免打扰设置的时间类型。 |
| begin | Date                                  | 是   | 是   | 免打扰设置的起点时间。 |
| end   | Date                                  | 是   | 是   | 免打扰设置的终点时间。 |

## DoNotDisturbType

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称         | 值               | 说明                                       |
| ------------ | ---------------- | ------------------------------------------ |
| TYPE_NONE    | 0 | 非通知勿扰类型。                           |
| TYPE_ONCE    | 1 | 以设置时间段(只看小时和分钟)一次执行勿扰。 |
| TYPE_DAILY   | 2 | 以设置时间段(只看小时和分钟)每天执行勿扰。 |
| TYPE_CLEARLY | 3 | 以设置时间段(明确年月日时分)执行勿扰。     |


## ContentType

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                              | 值          | 说明               |
| --------------------------------- | ----------- | ------------------ |
| NOTIFICATION_CONTENT_BASIC_TEXT   | NOTIFICATION_CONTENT_BASIC_TEXT | 普通类型通知。     |
| NOTIFICATION_CONTENT_LONG_TEXT    | NOTIFICATION_CONTENT_LONG_TEXT | 长文本类型通知。   |
| NOTIFICATION_CONTENT_PICTURE      | NOTIFICATION_CONTENT_PICTURE | 图片类型通知。     |
| NOTIFICATION_CONTENT_CONVERSATION | NOTIFICATION_CONTENT_CONVERSATION | 社交类型通知。     |
| NOTIFICATION_CONTENT_MULTILINE    | NOTIFICATION_CONTENT_MULTILINE | 多行文本类型通知。 |

## SlotLevel

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                              | 值          | 说明               |
| --------------------------------- | ----------- | ------------------ |
| LEVEL_NONE                        | 0           | 表示关闭通知功能。     |
| LEVEL_MIN                         | 1           | 表示通知功能已启用，但状态栏中不显示通知图标，且没有横幅或提示音。 |
| LEVEL_LOW                         | 2           | 表示通知功能已启用，且状态栏中显示通知图标，但没有横幅或提示音。 |
| LEVEL_DEFAULT                     | 3           | 表示通知功能已启用，状态栏中显示通知图标，没有横幅但有提示音。 |
| LEVEL_HIGH                        | 4           | 表示通知功能已启用，状态栏中显示通知图标，有横幅和提示音。 |


## SlotType

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                 | 值       | 说明       |
| -------------------- | -------- | ---------- |
| UNKNOWN_TYPE         | 0 | 未知类型。 |
| SOCIAL_COMMUNICATION | 1 | 社交类型。 |
| SERVICE_INFORMATION  | 2 | 服务类型。 |
| CONTENT_INFORMATION  | 3 | 内容类型。 |
| OTHER_TYPES          | 0xFFFF | 其他类型。 |




## DeviceRemindType

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称                 | 值  | 说明                               |
| -------------------- | --- | --------------------------------- |
| IDLE_DONOT_REMIND    | 0   | 设备未被使用，无需提醒。            |
| IDLE_REMIND          | 1   | 提醒设备未被使用。                 |
| ACTIVE_DONOT_REMIND  | 2   | 设备正在使用，无需提醒。            |
| ACTIVE_REMIND        | 3   | 提醒设备正在使用。                 |


## SourceType

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称                 | 值  | 说明                  |
| -------------------- | --- | -------------------- |
| TYPE_NORMAL          | 0   | 一般通知。            |
| TYPE_CONTINUOUS      | 1   | 连续通知。            |
| TYPE_TIMER           | 2   | 计划通知。            |

## NotificationCheckInfo

用于校验通知的参数。


| 名称                 | 类型       | 可读   | 可写   | 说明     |
| -------------------- | -------- | ---------- | ---------- | ---------- |
| bundleName         | string | 是 | 否 | bundle名称。 |
| notificationId | number | 是 | 否 | 通知Id。 |
| contentType  | [ContentType](#contenttype) | 是 | 否 | 通知类型。 |

## NotificationCheckResult

通知校验结果。

| 名称                 | 类型       | 可读     | 可写     | 说明       |
| -------------------- | -------- | ---------- | ---------- | ---------- |
| code         | number | 是 | 否 | 0-display, 1-no display。 |
| message | string | 是 | 否 | 结果信息。 |
