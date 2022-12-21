# @ohos.notificationManager (NotificationManager模块)

本模块提供通知管理的能力，包括发布、取消发布通知，创建、获取、移除通知通道，获取通知的使能状态、角标使能状态，获取通知的相关信息等。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import Notification from '@ohos.notificationManager';
```

## Notification.publish

publish(request: NotificationRequest, callback: AsyncCallback\<void\>): void

发布通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 类型                                        | 必填 | 描述                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](#notificationrequest) | 是   | 设置要发布通知内容的NotificationRequest对象。 |
| callback | AsyncCallback\<void\>                       | 是   | 被指定的回调方法。                            |

**错误码：**

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600009  | Over max number notifications per second. |

**示例：**

```js
//publish回调
function publishCallback(err) {
    if (err) {
        console.info("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish success");
    }
}
//通知Request对象
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

发布通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 类型                                        | 必填 | 描述                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](#notificationrequest) | 是   | 设置要发布通知内容的NotificationRequest对象。 |

**错误码：**

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600009  | Over max number notifications per second. |

**示例：**

```js
//通知Request对象
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

## Notification.publish

publish(request: NotificationRequest, userId: number, callback: AsyncCallback\<void\>): void

发布通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                                        | 必填 | 描述                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](#notificationrequest) | 是   | 设置要发布通知内容的NotificationRequest对象。 |
| userId   | number                                      | 是   | 接收通知用户的Id。                           |
| callback | AsyncCallback\<void\>                       | 是   | 被指定的回调方法。                           |

**错误码：**

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600008  | The user is not exist.                    |
| 1600009  | Over max number notifications per second. |

**示例：**

```js
//publish回调
function publishCallback(err) {
    if (err) {
        console.info("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish success");
    }
}
// 接收通知的用户ID
var userId = 1
//通知Request对象
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

## Notification.publish

publish(request: NotificationRequest, userId: number): Promise\<void\>

发布通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     |  类型                                        | 必填 | 描述                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](#notificationrequest) | 是   | 设置要发布通知内容的NotificationRequest对象。 |
| userId   | number                                      | 是   | 接收通知用户的Id。                           |

**错误码：**

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600008  | The user is not exist.                    |
| 1600009  | Over max number notifications per second. |

**示例：**

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

取消与指定id和label相匹配的已发布通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 类型                  | 必填 | 描述                 |
| -------- | --------------------- | ---- | -------------------- |
| id       | number                | 是   | 通知ID。               |
| label    | string                | 是   | 通知标签。             |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**示例：**

```js
//cancel回调
function cancelCallback(err) {
    if (err) {
        console.info("cancel failed " + JSON.stringify(err));
    } else {
        console.info("cancel success");
    }
}
Notification.cancel(0, "label", cancelCallback)
```



## Notification.cancel

cancel(id: number, label?: string): Promise\<void\>

取消与指定id相匹配的已发布通知，label可以指定也可以不指定（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称  | 类型   | 必填 | 描述     |
| ----- | ------ | ---- | -------- |
| id    | number | 是   | 通知ID。   |
| label | string | 否   | 通知标签。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**示例：**

```js
Notification.cancel(0).then(() => {
	console.info("cancel sucess");
});
```



## Notification.cancel

cancel(id: number, callback: AsyncCallback\<void\>): void

取消与指定id相匹配的已发布通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 类型                  | 必填 | 描述                 |
| -------- | --------------------- | ---- | -------------------- |
| id       | number                | 是   | 通知ID。               |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |

**示例：**

```js
//cancel回调
function cancelCallback(err) {
    if (err) {
        console.info("cancel failed " + JSON.stringify(err));
    } else {
        console.info("cancel success");
    }
}
Notification.cancel(0, cancelCallback)
```



## Notification.cancelAll

cancelAll(callback: AsyncCallback\<void\>): void

取消所有已发布的通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**参数：**

| 名称     | 类型                  | 必填 | 描述                 |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
//cancel回调
function cancelAllCallback(err) {
    if (err) {
        console.info("cancelAll failed " + JSON.stringify(err));
    } else {
        console.info("cancelAll success");
    }
}
Notification.cancelAll(cancelAllCallback)
```



## Notification.cancelAll

cancelAll(): Promise\<void\>

取消所有已发布的通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
Notification.cancelAll().then(() => {
	console.info("cancelAll sucess");
});
```



## Notification.addSlot

addSlot(slot: NotificationSlot, callback: AsyncCallback\<void\>): void

创建通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                  | 必填 | 描述                 |
| -------- | --------------------- | ---- | -------------------- |
| slot     | [NotificationSlot](#notificationslot)       | 是   | 要创建的通知通道对象。 |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
//addslot回调
function addSlotCallBack(err) {
    if (err) {
        console.info("addSlot failed " + JSON.stringify(err));
    } else {
        console.info("addSlot success");
    }
}
//通知slot对象
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
Notification.addSlot(notificationSlot, addSlotCallBack)
```



## Notification.addSlot

addSlot(slot: NotificationSlot): Promise\<void\>

创建通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称 | 类型             | 必填 | 描述                 |
| ---- | ---------------- | ---- | -------------------- |
| slot | [NotificationSlot](#notificationslot) | 是   | 要创建的通知通道对象。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
//通知slot对象
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
Notification.addSlot(notificationSlot).then(() => {
	console.info("addSlot sucess");
});
```



## Notification.addSlot

addSlot(type: SlotType, callback: AsyncCallback\<void\>): void

创建通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 类型                  | 必填 | 描述                   |
| -------- | --------------------- | ---- | ---------------------- |
| type     | [SlotType](#slottype)              | 是   | 要创建的通知通道的类型。 |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。   |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
//addslot回调
function addSlotCallBack(err) {
    if (err) {
        console.info("addSlot failed " + JSON.stringify(err));
    } else {
        console.info("addSlot success");
    }
}
Notification.addSlot(Notification.SlotType.SOCIAL_COMMUNICATION, addSlotCallBack)
```



## Notification.addSlot

addSlot(type: SlotType): Promise\<void\>

创建通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称 | 类型     | 必填 | 描述                   |
| ---- | -------- | ---- | ---------------------- |
| type | [SlotType](#slottype) | 是   | 要创建的通知通道的类型。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
Notification.addSlot(Notification.SlotType.SOCIAL_COMMUNICATION).then(() => {
	console.info("addSlot sucess");
});
```



## Notification.addSlots

addSlots(slots: Array\<NotificationSlot\>, callback: AsyncCallback\<void\>): void

创建多个通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                      | 必填 | 描述                     |
| -------- | ------------------------- | ---- | ------------------------ |
| slots    | Array\<[NotificationSlot](#notificationslot)\> | 是   | 要创建的通知通道对象数组。 |
| callback | AsyncCallback\<void\>     | 是   | 表示被指定的回调方法。     |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
//addSlots回调
function addSlotsCallBack(err) {
    if (err) {
        console.info("addSlots failed " + JSON.stringify(err));
    } else {
        console.info("addSlots success");
    }
}
//通知slot对象
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
//通知slot array 对象
var notificationSlotArray = new Array();
notificationSlotArray[0] = notificationSlot;

Notification.addSlots(notificationSlotArray, addSlotsCallBack)
```



## Notification.addSlots

addSlots(slots: Array\<NotificationSlot\>): Promise\<void\>

创建多个通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称  | 类型                      | 必填 | 描述                     |
| ----- | ------------------------- | ---- | ------------------------ |
| slots | Array\<[NotificationSlot](#notificationslot)\> | 是   | 要创建的通知通道对象数组。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
//通知slot对象
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
//通知slot array 对象
var notificationSlotArray = new Array();
notificationSlotArray[0] = notificationSlot;

Notification.addSlots(notificationSlotArray).then(() => {
	console.info("addSlots sucess");
});
```



## Notification.getSlot

getSlot(slotType: SlotType, callback: AsyncCallback\<NotificationSlot\>): void

获取一个通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 类型                              | 必填 | 描述                                                        |
| -------- | --------------------------------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype)                          | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |
| callback | AsyncCallback\<[NotificationSlot](#notificationslot)\> | 是   | 表示被指定的回调方法。                                        |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
//getSlot回调
function getSlotCallback(err,data) {
    if (err) {
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

获取一个通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 类型     | 必填 | 描述                                                        |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype) | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<NotificationSlot\> | 以Promise形式返回获取一个通知通道。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.getSlot(slotType).then((data) => {
	console.info("getSlot sucess, data: " + JSON.stringify(data));
});
```



## Notification.getSlots

getSlots(callback: AsyncCallback<Array\<NotificationSlot\>>): void

获取此应用程序的所有通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 类型                              | 必填 | 描述                 |
| -------- | --------------------------------- | ---- | -------------------- |
| callback | AsyncCallback\<Array\<[NotificationSlot](#notificationslot)\>\> | 是   | 表示被指定的回调方法。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
//getSlots回调
function getSlotsCallback(err,data) {
    if (err) {
        console.info("getSlots failed " + JSON.stringify(err));
    } else {
        console.info("getSlots success");
    }
}
Notification.getSlots(getSlotsCallback)
```



## Notification.getSlots

getSlots(): Promise\<Array\<NotificationSlot\>>

获取此应用程序的所有通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationSlot](#notificationslot)\>\> | 以Promise形式返回获取此应用程序的所有通知通道的结果。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
Notification.getSlots().then((data) => {
	console.info("getSlots sucess, data: " + JSON.stringify(data));
});
```



## Notification.removeSlot

removeSlot(slotType: SlotType, callback: AsyncCallback\<void\>): void

根据通知通道类型删除创建的通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 类型                  | 必填 | 描述                                                        |
| -------- | --------------------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype)              | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。                                        |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
//removeSlot回调
function removeSlotCallback(err) {
    if (err) {
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

根据通知通道类型删除创建的通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 类型     | 必填 | 描述                                                        |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype) | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.removeSlot(slotType).then(() => {
	console.info("removeSlot sucess");
});
```



## Notification.removeAllSlots

removeAllSlots(callback: AsyncCallback\<void\>): void

删除所有通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 类型                  | 必填 | 描述                 |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function removeAllCallBack(err) {
    if (err) {
        console.info("removeAllSlots failed " + JSON.stringify(err));
    } else {
        console.info("removeAllSlots success");
    }
}
Notification.removeAllSlots(removeAllCallBack)
```



## Notification.removeAllSlots

removeAllSlots(): Promise\<void\>

删除所有通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
Notification.removeAllSlots().then(() => {
	console.info("removeAllSlots sucess");
});
```



## Notification.setNotificationEnable

setNotificationEnable(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

设定指定包的通知使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                  | 必填 | 描述                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](#bundleoption)          | 是   | 指定包信息。           |
| enable   | boolean               | 是   | 使能状态。             |
| callback | AsyncCallback\<void\> | 是   | 设定通知使能回调函数。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
function setNotificationEnablenCallback(err) {
    if (err) {
        console.info("setNotificationEnablenCallback failed " + JSON.stringify(err));
    } else {
        console.info("setNotificationEnablenCallback success");
    }
}
var bundle = {
    bundle: "bundleName1",
}
Notification.setNotificationEnable(bundle, false, setNotificationEnablenCallback);
```



## Notification.setNotificationEnable

setNotificationEnable(bundle: BundleOption, enable: boolean): Promise\<void\>

设定指定包的通知使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称   | 类型         | 必填 | 描述       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。 |
| enable | boolean      | 是   | 使能状态。   |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
var bundle = {
    bundle: "bundleName1",
}
Notification.setNotificationEnable(bundle, false).then(() => {
	console.info("setNotificationEnable sucess");
});
```



## Notification.isNotificationEnabled

isNotificationEnabled(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

获取指定包的通知使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 名称     | 类型                  | 必填 | 描述                     |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](#bundleoption)          | 是   | 指定包信息。               |
| callback | AsyncCallback\<void\> | 是   | 获取通知使能状态回调函数。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
function isNotificationEnabledCallback(err, data) {
    if (err) {
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

获取指定包的通知使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称   | 类型         | 必填 | 描述       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取指定包的通知使能状态的结果。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

获取通知使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                  | 必填 | 描述                     |
| -------- | --------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void\> | 是   | 获取通知使能状态回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function isNotificationEnabledCallback(err, data) {
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

获取通知使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称   | 类型         | 必填 | 描述       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取通知使能状态的结果。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
Notification.isNotificationEnabled().then((data) => {
	console.info("isNotificationEnabled sucess, data: " + JSON.stringify(data));
});
```



## Notification.displayBadge

displayBadge(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

设定指定包的角标使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                  | 必填 | 描述                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](#bundleoption)          | 是   | 指定包信息。           |
| enable   | boolean               | 是   | 使能状态。             |
| callback | AsyncCallback\<void\> | 是   | 设定角标使能回调函数。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
function displayBadgeCallback(err) {
    if (err) {
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

设定指定包的角标使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称   | 类型         | 必填 | 描述       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。 |
| enable | boolean      | 是   | 使能状态。   |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

获取指定包的角标使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                  | 必填 | 描述                     |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](#bundleoption)          | 是   | 指定包信息。               |
| callback | AsyncCallback\<void\> | 是   | 获取角标使能状态回调函数。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
function isBadgeDisplayedCallback(err, data) {
    if (err) {
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

获取指定包的角标使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称   | 类型         | 必填 | 描述       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取指定包的角标使能状态。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

设定指定包的通知通道状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                  | 必填 | 描述                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](#bundleoption)          | 是   | 指定包信息。           |
| slot     | [NotificationSlot](#notificationslot)      | 是   | 通知通道。             |
| callback | AsyncCallback\<void\> | 是   | 设定通知通道回调函数。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |



**示例：**

```js
function setSlotByBundleCallback(err) {
    if (err) {
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

设定指定包的通知通道状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称   | 类型         | 必填 | 描述       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。 |
| slot   | [NotificationSlot](#notificationslot) | 是   | 使能状态。   |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

获取指定包的通知通道（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                                     | 必填 | 描述                 |
| -------- | ---------------------------------------- | ---- | -------------------- |
| bundle   | [BundleOption](#bundleoption)                             | 是   | 指定包信息。           |
| callback | AsyncCallback<Array\<[NotificationSlot](#notificationslot)\>> | 是   | 获取通知通道回调函数。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
function getSlotsByBundleCallback(err, data) {
    if (err) {
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

获取指定包的通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称   | 类型         | 必填 | 描述       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise<Array\<[NotificationSlot](#notificationslot)\>> | 以Promise形式返回获取指定包的通知通道。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

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

获取指定包的通知通道数（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                      | 必填 | 描述                   |
| -------- | ------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](#bundleoption)              | 是   | 指定包信息。             |
| callback | AsyncCallback\<number\> | 是   | 获取通知通道数回调函数。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
function getSlotNumByBundleCallback(err, data) {
    if (err) {
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

获取指定包的通知通道数（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称   | 类型         | 必填 | 描述       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | 以Promise形式返回获取指定包的通知通道数。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
var bundle = {
    bundle: "bundleName1",
}
Notification.getSlotNumByBundle(bundle).then((data) => {
	console.info("getSlotNumByBundle sucess, data: " + JSON.stringify(data));
});
```




## Notification.getAllActiveNotifications

getAllActiveNotifications(callback: AsyncCallback<Array\<NotificationRequest\>>): void

获取活动通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                                                         | 必填 | 描述                 |
| -------- | ------------------------------------------------------------ | ---- | -------------------- |
| callback | AsyncCallback<Array\<[NotificationRequest](#notificationrequest)\>> | 是   | 获取活动通知回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function getAllActiveNotificationsCallback(err, data) {
    if (err) {
        console.info("getAllActiveNotifications failed " + JSON.stringify(err));
    } else {
        console.info("getAllActiveNotifications success");
    }
}

Notification.getAllActiveNotifications(getAllActiveNotificationsCallback);
```



## Notification.getAllActiveNotifications

getAllActiveNotifications(): Promise\<Array\<[NotificationRequest](#notificationrequest)\>\>

获取活动通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationRequest](#notificationrequest)\>\> | 以Promise形式返回获取活动通知。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
Notification.getAllActiveNotifications().then((data) => {
	console.info("getAllActiveNotifications sucess, data: " + JSON.stringify(data));
});
```



## Notification.getActiveNotificationCount

getActiveNotificationCount(callback: AsyncCallback\<number\>): void

获取当前应用的活动通知数（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 类型                   | 必填 | 描述                   |
| -------- | ---------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<number\> | 是   | 获取活动通知数回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function getActiveNotificationCountCallback(err, data) {
    if (err) {
        console.info("getActiveNotificationCount failed " + JSON.stringify(err));
    } else {
        console.info("getActiveNotificationCount success");
    }
}

Notification.getActiveNotificationCount(getActiveNotificationCountCallback);
```



## Notification.getActiveNotificationCount

getActiveNotificationCount(): Promise\<number\>

获取当前应用的活动通知数（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | 以Promise形式返回获取当前应用的活动通知数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
Notification.getActiveNotificationCount().then((data) => {
	console.info("getActiveNotificationCount sucess, data: " + JSON.stringify(data));
});
```



## Notification.getActiveNotifications

getActiveNotifications(callback: AsyncCallback<Array\<NotificationRequest\>>): void

获取当前应用的活动通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 类型                                                         | 必填 | 描述                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback<Array\<[NotificationRequest](#notificationrequest)\>> | 是   | 获取当前应用的活动通知回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function getActiveNotificationsCallback(err, data) {
    if (err) {
        console.info("getActiveNotifications failed " + JSON.stringify(err));
    } else {
        console.info("getActiveNotifications success");
    }
}

Notification.getActiveNotifications(getActiveNotificationsCallback);
```



## Notification.getActiveNotifications

getActiveNotifications(): Promise\<Array\<[NotificationRequest](#notificationrequest)\>\>

获取当前应用的活动通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationRequest](#notificationrequest)\>\> | 以Promise形式返回获取当前应用的活动通知。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
Notification.getActiveNotifications().then((data) => {
	console.info("removeGroupByBundle sucess, data: " + JSON.stringify(data));
});
```



## Notification.cancelGroup

cancelGroup(groupName: string, callback: AsyncCallback\<void\>): void

取消本应用指定组通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称      | 类型                  | 必填 | 描述                         |
| --------- | --------------------- | ---- | ---------------------------- |
| groupName | string                | 是   | 指定通知组名称。               |
| callback  | AsyncCallback\<void\> | 是   | 取消本应用指定组通知回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function cancelGroupCallback(err) {
    if (err) {
        console.info("cancelGroup failed " + JSON.stringify(err));
    } else {
        console.info("cancelGroup success");
    }
}

var groupName = "GroupName";

Notification.cancelGroup(groupName, cancelGroupCallback);
```



## Notification.cancelGroup

cancelGroup(groupName: string): Promise\<void\>

取消本应用指定组通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称      | 类型   | 必填 | 描述           |
| --------- | ------ | ---- | -------------- |
| groupName | string | 是   | 指定通知组名称。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
var groupName = "GroupName";
Notification.cancelGroup(groupName).then(() => {
	console.info("cancelGroup sucess");
});
```



## Notification.removeGroupByBundle

removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void\>): void

删除指定应用指定组通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称      | 类型                  | 必填 | 描述                         |
| --------- | --------------------- | ---- | ---------------------------- |
| bundle    | [BundleOption](#bundleoption)          | 是   | 指定包信息。                   |
| groupName | string                | 是   | 指定通知组名称。               |
| callback  | AsyncCallback\<void\> | 是   | 删除本应用指定组通知回调函数。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
function removeGroupByBundleCallback(err) {
    if (err) {
        console.info("removeGroupByBundle failed " + JSON.stringify(err));
    } else {
        console.info("removeGroupByBundle success");
    }
}

var bundleOption = {bundle: "Bundle"};
var groupName = "GroupName";

Notification.removeGroupByBundle(bundleOption, groupName, removeGroupByBundleCallback);
```



## Notification.removeGroupByBundle

removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void\>

删除指定应用指定组通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称      | 类型         | 必填 | 描述           |
| --------- | ------------ | ---- | -------------- |
| bundle    | [BundleOption](#bundleoption) | 是   | 指定包信息。     |
| groupName | string       | 是   | 指定通知组名称。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
var bundleOption = {bundle: "Bundle"};
var groupName = "GroupName";
Notification.removeGroupByBundle(bundleOption, groupName).then(() => {
	console.info("removeGroupByBundle sucess");
});
```



## Notification.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, callback: AsyncCallback\<void\>): void

设置免打扰时间（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                  | 必填 | 描述                   |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate)      | 是   | 免打扰时间选项。         |
| callback | AsyncCallback\<void\> | 是   | 设置免打扰时间回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function setDoNotDisturbDateCallback(err) {
    if (err) {
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



## Notification.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate): Promise\<void\>

设置免打扰时间接口（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称 | 类型             | 必填 | 说明           |
| ---- | ---------------- | ---- | -------------- |
| date | [DoNotDisturbDate](#donotdisturbdate) | 是   | 免打扰时间选项。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

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


## Notification.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number, callback: AsyncCallback\<void\>): void

指定用户设置免打扰时间（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate)      | 是   | 免打扰时间选项。         |
| userId   | number                | 是   | 设置免打扰事件的用户ID。 |
| callback | AsyncCallback\<void\> | 是   | 设置免打扰时间回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**示例：**

```js
function setDoNotDisturbDateCallback(err) {
    if (err) {
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



## Notification.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number): Promise\<void\>

指定用户设置免打扰时间接口（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称   | 类型             | 必填 | 说明           |
| ------ | ---------------- | ---- | -------------- |
| date   | [DoNotDisturbDate](#donotdisturbdate) | 是   | 免打扰时间选项。 |
| userId | number           | 是   | 设置免打扰事件的用户ID。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**示例：**

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


## Notification.getDoNotDisturbDate

getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate\>): void

查询免打扰时间接口（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                              | 必填 | 说明                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate)\> | 是   | 查询免打扰时间回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function getDoNotDisturbDateCallback(err,data) {
    if (err) {
        console.info("getDoNotDisturbDate failed " + JSON.stringify(err));
    } else {
        console.info("getDoNotDisturbDate success");
    }
}

Notification.getDoNotDisturbDate(getDoNotDisturbDateCallback);
```



## Notification.getDoNotDisturbDate

getDoNotDisturbDate(): Promise\<DoNotDisturbDate\>

查询免打扰时间接口（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型                                             | 说明                                      |
| ------------------------------------------------ | ----------------------------------------- |
| Promise\<[DoNotDisturbDate](#donotdisturbdate)\> | 以Promise形式返回获取查询免打扰时间接口。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
Notification.getDoNotDisturbDate().then((data) => {
	console.info("getDoNotDisturbDate sucess, data: " + JSON.stringify(data));
});
```


## Notification.getDoNotDisturbDate

getDoNotDisturbDate(userId: number, callback: AsyncCallback\<DoNotDisturbDate\>): void

指定用户查询免打扰时间接口（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                              | 必填 | 说明                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate)\> | 是   | 查询免打扰时间回调函数。 |
| userId   | number                            | 是   | 设置免打扰事件的用户ID。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**示例：**

```js
function getDoNotDisturbDateCallback(err,data) {
    if (err) {
        console.info("getDoNotDisturbDate failed " + JSON.stringify(err));
    } else {
        console.info("getDoNotDisturbDate success");
    }
}

var userId = 1

Notification.getDoNotDisturbDate(userId, getDoNotDisturbDateCallback);
```



## Notification.getDoNotDisturbDate

getDoNotDisturbDate(userId: number): Promise\<DoNotDisturbDate\>

指定用户查询免打扰时间接口（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                              | 必填 | 描述                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| userId   | number                            | 是   | 设置免打扰事件的用户ID。 |

**返回值：**

| 类型                                             | 说明                                      |
| ------------------------------------------------ | ----------------------------------------- |
| Promise\<[DoNotDisturbDate](#donotdisturbdate)\> | 以Promise形式返回获取查询免打扰时间接口。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**示例：**

```js
var userId = 1

Notification.getDoNotDisturbDate(userId).then((data) => {
	console.info("getDoNotDisturbDate sucess, data: " + JSON.stringify(data));
});
```


## Notification.supportDoNotDisturbMode

supportDoNotDisturbMode(callback: AsyncCallback\<boolean\>): void

查询是否支持勿扰模式功能（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 类型                     | 必填 | 描述                             |
| -------- | ------------------------ | ---- | -------------------------------- |
| callback | AsyncCallback\<boolean\> | 是   | 查询是否支持勿扰模式功能回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
function supportDoNotDisturbModeCallback(err,data) {
    if (err) {
        console.info("supportDoNotDisturbMode failed " + JSON.stringify(err));
    } else {
        console.info("supportDoNotDisturbMode success");
    }
}

Notification.supportDoNotDisturbMode(supportDoNotDisturbModeCallback);
```



## Notification.supportDoNotDisturbMode

supportDoNotDisturbMode(): Promise\<boolean\>

查询是否支持勿扰模式功能（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取是否支持勿扰模式功能的结果。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```js
Notification.supportDoNotDisturbMode().then((data) => {
	console.info("supportDoNotDisturbMode sucess, data: " + JSON.stringify(data));
});
```



## Notification.isSupportTemplate

isSupportTemplate(templateName: string, callback: AsyncCallback\<boolean\>): void

查询模板是否存在（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名       | 类型                     | 必填 | 说明                       |
| ------------ | ------------------------ | ---- | -------------------------- |
| templateName | string                   | 是   | 模板名称。                   |
| callback     | AsyncCallback\<boolean\> | 是   | 查询模板是否存在的回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600011  | Read template config failed.        |

**示例：**

```javascript
var templateName = 'process';
function isSupportTemplateCallback(err, data) {
    if (err) {
        console.info("isSupportTemplate failed " + JSON.stringify(err));
    } else {
        console.info("isSupportTemplate success");
    }
}

Notification.isSupportTemplate(templateName, isSupportTemplateCallback);
```



## Notification.isSupportTemplate

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

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600011  | Read template config failed.        |

**示例：**

```javascript
var templateName = 'process';

Notification.isSupportTemplate(templateName).then((data) => {
    console.info("isSupportTemplate success, data: " + JSON.stringify(data));
});
```



## Notification.requestEnableNotification

requestEnableNotification(callback: AsyncCallback\<void\>): void

应用请求通知使能（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<void\> | 是   | 应用请求通知使能的回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```javascript
function requestEnableNotificationCallback(err) {
    if (err) {
        console.info("requestEnableNotification failed " + JSON.stringify(err));
    } else {
        console.info("requestEnableNotification success");
    }
};

Notification.requestEnableNotification(requestEnableNotificationCallback);
```



## Notification.requestEnableNotification

requestEnableNotification(): Promise\<void\>

应用请求通知使能（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```javascript
Notification.requestEnableNotification()
    .then(() => {
        console.info("requestEnableNotification sucess");
	});
```



## Notification.setDistributedEnable

setDistributedEnable(enable: boolean, callback: AsyncCallback\<void\>): void

设置设备是否支持分布式通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | 是   | 是否支持。<br/>true 支持。<br/>false 不支持。|
| callback | AsyncCallback\<void\> | 是   | 设置设备是否支持分布式通知的回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600010  | Distributed operation failed.       |

**示例：**

```javascript
function setDistributedEnableCallback() {
    if (err) {
        console.info("setDistributedEnable failed " + JSON.stringify(err));
    } else {
        console.info("setDistributedEnable success");
    }
};

var enable = true

Notification.setDistributedEnable(enable, setDistributedEnableCallback);
```



## Notification.setDistributedEnable

setDistributedEnable(enable: boolean): Promise\<void>

设置设备是否支持分布式通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | 是   | 是否支持。<br/>true 支持。<br/>false 不支持。|

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600010  | Distributed operation failed.       |

**示例：**

```javascript
var enable = true

Notification.setDistributedEnable(enable)
    .then(() => {
        console.info("setDistributedEnable sucess");
    });
```


## Notification.isDistributedEnabled

isDistributedEnabled(callback: AsyncCallback\<boolean>): void

获取设备是否支持分布式通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<boolean\> | 是   | 设备是否支持分布式通知的回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600010  | Distributed operation failed.       |

**示例：**

```javascript
function isDistributedEnabledCallback(err) {
    if (err) {
        console.info("isDistributedEnabled failed " + JSON.stringify(err));
    } else {
        console.info("isDistributedEnabled success");
    }
};

Notification.isDistributedEnabled(isDistributedEnabledCallback);
```



## Notification.isDistributedEnabled

isDistributedEnabled(): Promise\<boolean>

获取设备是否支持分布式通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型               | 说明            |
| ------------------ | --------------- |
| Promise\<boolean\> | Promise方式返回设备是否支持分布式通知的结果。<br/>true 支持。<br/>false 不支持。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600010  | Distributed operation failed.       |

**示例：**

```javascript
Notification.isDistributedEnabled()
    .then((data) => {
        console.info("isDistributedEnabled sucess, data: " + JSON.stringify(data));
    });
```


## Notification.setDistributedEnableByBundle

setDistributedEnableByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void

根据应用的包设置应用程序是否支持分布式通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](#bundleoption)             | 是   | 应用的包。                     |
| enable   | boolean                  | 是   | 是否支持。                       |
| callback | AsyncCallback\<void\> | 是   | 应用程序是否支持分布式通知的回调函数。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**示例：**

```javascript
function setDistributedEnableByBundleCallback(err) {
    if (err) {
        console.info("enableDistributedByBundle failed " + JSON.stringify(err));
    } else {
        console.info("enableDistributedByBundle success");
    }
};

var bundle = {
    bundle: "bundleName1",
}

var enable = true

Notification.setDistributedEnableByBundle(bundle, enable, setDistributedEnableByBundleCallback);
```



## Notification.setDistributedEnableByBundle

setDistributedEnableByBundle(bundle: BundleOption, enable: boolean): Promise\<void>

根据应用的包设置应用程序是否支持分布式通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](#bundleoption)             | 是   | 应用的包。                |
| enable   | boolean                  | 是   | 是否支持。                  |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**示例：**

```javascript
var bundle = {
    bundle: "bundleName1",
}

var enable = true

Notification.setDistributedEnableByBundle(bundle, enable)
    .then(() => {
        console.info("setDistributedEnableByBundle sucess");
    });
```

## Notification.isDistributedEnabledByBundle

isDistributedEnabledByBundle(bundle: BundleOption, callback: AsyncCallback\<boolean>): void

根据应用的包获取应用程序是否支持分布式通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](#bundleoption)             | 是   | 应用的包。                     |
| callback | AsyncCallback\<boolean\> | 是   | 应用程序是否支持分布式通知的回调函数。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**示例：**

```javascript
function isDistributedEnabledByBundleCallback(data) {
    if (err) {
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



## Notification.isDistributedEnabledByBundle

isDistributedEnabledByBundle(bundle: BundleOption): Promise\<boolean>

根据应用的包获取应用程序是否支持分布式通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](#bundleoption)             | 是   | 应用的包。                |

**返回值：**

| 类型               | 说明            |
| ------------------ | --------------- |
| Promise\<boolean\> | Promise方式返回应用程序是否支持分布式通知的结果。<br/>true 支持。<br/>false 不支持。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 1600010  | Distributed operation failed.            |
| 17700001 | The specified bundle name was not found. |

**示例：**

```javascript
var bundle = {
    bundle: "bundleName1",
}

Notification.isDistributedEnabledByBundle(bundle)
    .then((data) => {
        console.info("isDistributedEnabledByBundle sucess, data: " + JSON.stringify(data));
    });
```


## Notification.getDeviceRemindType

getDeviceRemindType(callback: AsyncCallback\<DeviceRemindType\>): void

获取通知的提醒方式（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                               | 必填 | 说明                       |
| -------- | --------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<[DeviceRemindType](#deviceremindtype)\> | 是   | 获取通知的提醒方式的回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```javascript
function getDeviceRemindTypeCallback(err, data) {
    if (err) {
        console.info("getDeviceRemindType failed " + JSON.stringify(err));
    } else {
        console.info("getDeviceRemindType success");
    }
};

Notification.getDeviceRemindType(getDeviceRemindTypeCallback);
```



## Notification.getDeviceRemindType

getDeviceRemindType(): Promise\<DeviceRemindType\>

获取通知的提醒方式（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型               | 说明            |
| ------------------ | --------------- |
| Promise\<[DeviceRemindType](#deviceremindtype)\> | Promise方式返回通知的提醒方式的结果。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |

**示例：**

```javascript
Notification.getDeviceRemindType()
    .then((data) => {
        console.info("getDeviceRemindType sucess, data: " + JSON.stringify(data));
    });
```


## Notification.publishAsBundle

publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number, callback: AsyncCallback\<void\>): void

发布代理通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名               | 类型                                        | 必填 | 说明                                          |
| -------------------- | ------------------------------------------- | ---- | --------------------------------------------- |
| request              | [NotificationRequest](#notificationrequest) | 是   | 设置要发布通知内容的NotificationRequest对象。 |
| representativeBundle | string                                      | 是   | 被代理应用的包名。                            |
| userId               | number                                      | 是   | 接收通知用户的Id。                            |
| callback             | AsyncCallback                               | 是   | 发布代理通知的回调方法。                      |

**错误码：**

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600008  | The user is not exist.                    |
| 1600009  | Over max number notifications per second. |

**示例：**

```js
//publishAsBundle回调
function publishAsBundleCallback(err) {
    if (err) {
        console.info("publishAsBundle failed " + JSON.stringify(err));
    } else {
        console.info("publishAsBundle success");
    }
}
// 被代理应用的包名
let representativeBundle = "com.example.demo"
// 接收通知的用户ID
let userId = 100
//通知Request对象
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

## Notification.publishAsBundle

publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number): Promise\<void\>

发布代理通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**


| 参数名               | 类型                                        | 必填 | 说明                                          |
| -------------------- | ------------------------------------------- | ---- | --------------------------------------------- |
| request              | [NotificationRequest](#notificationrequest) | 是   | 设置要发布通知内容的NotificationRequest对象。 |
| representativeBundle | string                                      | 是   | 被代理应用的包名。                            |
| userId               | number                                      | 是   | 接收通知用户的Id。                            |

**错误码：**

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 1600001  | Internal error.                           |
| 1600002  | Marshalling or unmarshalling error.       |
| 1600003  | Failed to connect service.                |
| 1600004  | Notification is not enabled.              |
| 1600005  | Notification slot is not enabled.         |
| 1600008  | The user is not exist.                    |
| 1600009  | Over max number notifications per second. |

**示例：**

```js
// 被代理应用的包名
let representativeBundle = "com.example.demo"
// 接收通知的用户ID
let userId = 100
//通知Request对象
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

## Notification.cancelAsBundle

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
| userId               | number        | 是   | 接收通知用户的Id。       |
| callback             | AsyncCallback | 是   | 取消代理通知的回调方法。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |
| 1600008  | The user is not exist.              |

**示例：**

```js
//cancelAsBundle
function cancelAsBundleCallback(err) {
    if (err) {
        console.info("cancelAsBundle failed " + JSON.stringify(err));
    } else {
        console.info("cancelAsBundle success");
    }
}
// 被代理应用的包名
let representativeBundle = "com.example.demo"
// 接收通知的用户ID
let userId = 100

Notification.cancelAsBundle(0, representativeBundle, userId, cancelAsBundleCallback);
```

## Notification.cancelAsBundle

cancelAsBundle(id: number, representativeBundle: string, userId: number): Promise\<void\>

发布代理通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER，ohos.permission.NOTIFICATION_AGENT_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名               | 类型   | 必填 | 说明               |
| -------------------- | ------ | ---- | ------------------ |
| id                   | number | 是   | 通知ID。           |
| representativeBundle | string | 是   | 被代理应用的包名。 |
| userId               | number | 是   | 接收通知用户的Id。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600007  | The notification is not exist.      |
| 1600008  | The user is not exist.              |

**示例：**

```js
// 被代理应用的包名
let representativeBundle = "com.example.demo"
// 接收通知的用户ID
let userId = 100

Notification.cancelAsBundle(0, representativeBundle, userId).then(() => {
	console.info("cancelAsBundle success");
});
```

## Notification.setNotificationEnableSlot 

setNotificationEnableSlot(bundle: BundleOption, type: SlotType, enable: boolean, callback: AsyncCallback\<void>): void

设定指定类型的渠道使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名   | 类型                          | 必填 | 说明                   |
| -------- | ----------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](#bundleoption) | 是   | 指定包信息。           |
| type     | [SlotType](#slottype)         | 是   | 指定渠道类型。         |
| enable   | boolean                       | 是   | 使能状态。             |
| callback | AsyncCallback\<void\>         | 是   | 设定渠道使能回调函数。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
//setNotificationEnableSlot
function setNotificationEnableSlotCallback(err) {
    if (err) {
        console.info("setNotificationEnableSlot failed " + JSON.stringify(err));
    } else {
        console.info("setNotificationEnableSlot success");
    }
};

Notification.setNotificationEnableSlot(
    { bundle: "ohos.samples.notification", },
    Notification.SlotType.SOCIAL_COMMUNICATION,
    true,
    setNotificationEnableSlotCallback);
```

## Notification.setNotificationEnableSlot

setNotificationEnableSlot(bundle: BundleOption, type: SlotType, enable: boolean): Promise\<void> 

设定指定类型的渠道使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。   |
| type   | [SlotType](#slottype)         | 是   | 指定渠道类型。 |
| enable | boolean                       | 是   | 使能状态。     |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
//setNotificationEnableSlot
Notification.setNotificationEnableSlot(
    { bundle: "ohos.samples.notification", },
    Notification.SlotType.SOCIAL_COMMUNICATION,
    true).then(() => {
        console.info("setNotificationEnableSlot sucess");
    });
```

## Notification.isNotificationSlotEnabled

isNotificationSlotEnabled(bundle: BundleOption, type: SlotType, callback: AsyncCallback\<boolean\>): void

获取指定类型的渠道使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名   | 类型                          | 必填 | 说明                   |
| -------- | ----------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](#bundleoption) | 是   | 指定包信息。           |
| type     | [SlotType](#slottype)         | 是   | 指定渠道类型。         |
| callback | AsyncCallback\<boolean\>         | 是   | 设定渠道使能回调函数。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
//isNotificationSlotEnabled
function getEnableSlotCallback(err, data) {
    if (err) {
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

## Notification.isNotificationSlotEnabled

isNotificationSlotEnabled(bundle: BundleOption, type: SlotType): Promise\<boolean\>  

获取指定类型的渠道使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。   |
| type   | [SlotType](#slottype)         | 是   | 指定渠道类型。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回指定类型的渠道使能状态。 |

**错误码：**

| 错误码ID | 错误信息                                 |
| -------- | ---------------------------------------- |
| 1600001  | Internal error.                          |
| 1600002  | Marshalling or unmarshalling error.      |
| 1600003  | Failed to connect service.               |
| 17700001 | The specified bundle name was not found. |

**示例：**

```js
//isNotificationSlotEnabled
Notification.isNotificationSlotEnabled(
    { bundle: "ohos.samples.notification", },
    Notification.SlotType.SOCIAL_COMMUNICATION
    ).then((data) => {
      console.info("isNotificationSlotEnabled success, data: " + JSON.stringify(data));
    });
```


## Notification.setSyncNotificationEnabledWithoutApp

setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean, callback: AsyncCallback\<void\>): void

设置是否将通知同步到未安装应用程序的设备(callback形式)。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：** 

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | 是   | 用户Id。   |
| enable | boolean | 是   | 是否启用。<br>true：启用。<br>false：禁用。   |
| callback | AsyncCallback\<void\>    | 是   | 设置是否将通知同步到未安装应用程序的设备的回调函数。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**示例：**

```js
let userId = 100;
let enable = true;

function setSyncNotificationEnabledWithoutAppCallback(err) {
    if (err) {
        console.info("setSyncNotificationEnabledWithoutApp failed " + JSON.stringify(err));
    } else {
        console.info("setSyncNotificationEnabledWithoutApp success");
    }
}

Notification.setSyncNotificationEnabledWithoutApp(userId, enable, setSyncNotificationEnabledWithoutAppCallback);
```


## Notification.setSyncNotificationEnabledWithoutApp

setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean): Promise\<void>

设置是否将通知同步到未安装应用程序的设备(Promise形式)。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | 是   | 用户Id。   |
| enable | boolean | 是   | 是否启用。<br>true：启用。<br>false：禁用。   |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<void\> | 以Promise形式返回设置是否将通知同步到未安装应用程序的设备的结果。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**示例：**

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


## Notification.getSyncNotificationEnabledWithoutApp

getSyncNotificationEnabledWithoutApp(userId: number, callback: AsyncCallback\<boolean>): void

获取是否同步通知到未安装应用程序的设备(callback形式)。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | 是   | 用户Id。   |
| callback | AsyncCallback\<boolean\>         | 是   | 设置是否将通知同步到未安装应用程序的设备的回调函数。<br>true: 是。<br>false: 否。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**示例：**

```js
let userId = 100;

function getSyncNotificationEnabledWithoutAppCallback(err, data) {
    if (err) {
        console.info('getSyncNotificationEnabledWithoutAppCallback, err' + err);
    } else {
        console.info('getSyncNotificationEnabledWithoutAppCallback, data' + data);
    }
}

Notification.getSyncNotificationEnabledWithoutApp(userId, getSyncNotificationEnabledWithoutAppCallback);
```


## Notification.getSyncNotificationEnabledWithoutApp

getSyncNotificationEnabledWithoutApp(userId: number): Promise\<boolean>

获取是否同步通知到未安装应用程序的设备(Promise形式)。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名 | 类型                          | 必填 | 说明           |
| ------ | ----------------------------- | ---- | -------------- |
| userId | number | 是   | 用户Id。   |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取是否同步通知到未安装应用程序的设备的结果。<br>true: 是。<br>false: 否。 |

**错误码：**

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 1600001  | Internal error.                     |
| 1600002  | Marshalling or unmarshalling error. |
| 1600003  | Failed to connect service.          |
| 1600008  | The user is not exist.              |

**示例：**

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




## DoNotDisturbDate

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称  | 可读 | 可写 | 类型                                  | 说明                     |
| ----- | ---- | --- | ------------------------------------- | ------------------------ |
| type  | 是  | 否  | [DoNotDisturbType](#donotdisturbtype) | 指定免打扰设置的时间类型。 |
| begin | 是  | 否  | Date                                  | 指定免打扰设置的起点时间。 |
| end   | 是  | 否  | Date                                  | 指定免打扰设置的终点时间。 |



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


## BundleOption

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称   | 可读 | 可写 | 类型   | 描述   |
| ------ | ---- | --- | ------ | ------ |
| bundle | 是  | 是  | string | 包名。   |
| uid    | 是  | 是  | number | 用户id。 |


## SlotType

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                 | 值       | 说明       |
| -------------------- | -------- | ---------- |
| UNKNOWN_TYPE         | 0 | 未知类型。 |
| SOCIAL_COMMUNICATION | 1 | 社交类型。 |
| SERVICE_INFORMATION  | 2 | 服务类型。 |
| CONTENT_INFORMATION  | 3 | 内容类型。 |
| OTHER_TYPES          | 0xFFFF | 其他类型。 |


## NotificationActionButton

描述通知中显示的操作按钮。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称      | 可读 | 可写 | 类型                                            | 说明                      |
| --------- | --- | ---- | ----------------------------------------------- | ------------------------- |
| title     | 是  | 是  | string                                          | 按钮标题。                  |
| wantAgent | 是  | 是  | WantAgent                                       | 点击按钮时触发的WantAgent。 |
| extras    | 是  | 是  | { [key: string]: any }                          | 按钮扩展信息。              |
| userInput | 是  | 是  | [NotificationUserInput](#notificationuserinput) | 用户输入对象实例。          |


## NotificationBasicContent

描述普通文本通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 可读 | 可写 | 类型   | 描述                               |
| -------------- | ---- | ---- | ------ | ---------------------------------- |
| title          | 是   | 是   | string | 通知标题。                         |
| text           | 是   | 是   | string | 通知内容。                         |
| additionalText | 是   | 是   | string | 通知次要内容，是对通知内容的补充。 |


## NotificationLongTextContent

描述长文本通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 可读 | 可写 | 类型   | 描述                             |
| -------------- | ---- | --- | ------ | -------------------------------- |
| title          | 是  | 是  | string | 通知标题。                         |
| text           | 是  | 是  | string | 通知内容。                         |
| additionalText | 是  | 是  | string | 通知次要内容，是对通知内容的补充。 |
| longText       | 是  | 是  | string | 通知的长文本。                     |
| briefText      | 是  | 是  | string | 通知概要内容，是对通知内容的总结。 |
| expandedTitle  | 是  | 是  | string | 通知展开时的标题。                 |


## NotificationMultiLineContent

描述多行文本通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 可读 | 可写 | 类型            | 描述                             |
| -------------- | --- | --- | --------------- | -------------------------------- |
| title          | 是  | 是  | string          | 通知标题。                         |
| text           | 是  | 是  | string          | 通知内容。                         |
| additionalText | 是  | 是  | string          | 通知次要内容，是对通知内容的补充。 |
| briefText      | 是  | 是  | string          | 通知概要内容，是对通知内容的总结。 |
| longTitle      | 是  | 是  | string          | 通知展开时的标题。                 |
| lines          | 是  | 是  | Array\<string\> | 通知的多行文本。                   |


## NotificationPictureContent

描述附有图片的通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 可读 | 可写 | 类型           | 描述                             |
| -------------- | ---- | --- | -------------- | -------------------------------- |
| title          | 是  | 是  | string         | 通知标题。                         |
| text           | 是  | 是  | string         | 通知内容。                         |
| additionalText | 是  | 是  | string         | 通知次要内容，是对通知内容的补充。 |
| briefText      | 是  | 是  | string         | 通知概要内容，是对通知内容的总结。 |
| expandedTitle  | 是  | 是  | string         | 通知展开时的标题。                 |
| picture        | 是  | 是  | image.PixelMap | 通知的图片内容。                   |


## NotificationContent

描述通知类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称        | 可读 | 可写 | 类型                                                         | 描述               |
| ----------- | ---- | --- | ------------------------------------------------------------ | ------------------ |
| contentType | 是  | 是  | [ContentType](#contenttype)                                  | 通知内容类型。       |
| normal      | 是  | 是  | [NotificationBasicContent](#notificationbasiccontent)        | 基本类型通知内容。   |
| longText    | 是  | 是  | [NotificationLongTextContent](#notificationlongtextcontent)  | 长文本类型通知内容。 |
| multiLine   | 是  | 是  | [NotificationMultiLineContent](#notificationmultilinecontent) | 多行类型通知内容。   |
| picture     | 是  | 是  | [NotificationPictureContent](#notificationpicturecontent)    | 图片类型通知内容。   |


## NotificationFlagStatus

描述通知标志状态。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口，三方应用不支持调用。

| 名称           | 值  | 描述                               |
| -------------- | --- | --------------------------------- |
| TYPE_NONE      | 0   | 默认标志。                         |
| TYPE_OPEN      | 1   | 通知标志打开。                     |
| TYPE_CLOSE     | 2   | 通知标志关闭。                     |


## NotificationFlags

描述通知标志的实例。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称             | 可读 | 可写 | 类型                    | 描述                               |
| ---------------- | ---- | ---- | ---------------------- | --------------------------------- |
| soundEnabled     | 是   | 否   | NotificationFlagStatus | 是否启用声音提示。                  |
| vibrationEnabled | 是   | 否   | NotificationFlagStatus | 是否启用振动提醒功能。               |


## NotificationRequest

描述通知的请求。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                  | 可读 | 可写 | 类型                                          | 说明                       |
| --------------------- | ---- | --- | --------------------------------------------- | -------------------------- |
| content               | 是  | 是  | [NotificationContent](#notificationcontent)   | 通知内容。                   |
| id                    | 是  | 是  | number                                        | 通知ID。                     |
| slotType              | 是  | 是  | [SlotType](#slottype)                         | 通道类型。                   |
| isOngoing             | 是  | 是  | boolean                                       | 是否进行时通知。             |
| isUnremovable         | 是  | 是  | boolean                                       | 是否可移除。                 |
| deliveryTime          | 是  | 是  | number                                        | 通知发送时间。               |
| tapDismissed          | 是  | 是  | boolean                                       | 通知是否自动清除。           |
| autoDeletedTime       | 是  | 是  | number                                        | 自动清除的时间。             |
| wantAgent             | 是  | 是  | WantAgent                                     | WantAgent封装了应用的行为意图，点击通知时触发该行为。 |
| extraInfo             | 是  | 是  | {[key: string]: any}                          | 扩展参数。                   |
| color                 | 是  | 是  | number                                        | 通知背景颜色。暂不支持。       |
| colorEnabled          | 是  | 是  | boolean                                       | 通知背景颜色是否使能。暂不支持。  |
| isAlertOnce           | 是  | 是  | boolean                                       | 设置是否仅有一次此通知警报。 |
| isStopwatch           | 是  | 是  | boolean                                       | 是否显示已用时间。           |
| isCountDown           | 是  | 是  | boolean                                       | 是否显示倒计时时间。         |
| isFloatingIcon        | 是  | 是  | boolean                                       | 是否显示状态栏图标。         |
| label                 | 是  | 是  | string                                        | 通知标签。                   |
| badgeIconStyle        | 是  | 是  | number                                        | 通知角标类型。               |
| showDeliveryTime      | 是  | 是  | boolean                                       | 是否显示分发时间。           |
| actionButtons         | 是  | 是  | Array\<[NotificationActionButton](#notificationactionbutton)\>             | 通知按钮，最多两个按钮。     |
| smallIcon             | 是  | 是  | PixelMap                                      | 通知小图标。（可选字段，大小不超过30KB） |
| largeIcon             | 是  | 是  | PixelMap                                      | 通知大图标。（可选字段，大小不超过30KB） |
| creatorBundleName     | 是  | 否  | string                                        | 创建通知的包名。             |
| creatorUid            | 是  | 否  | number                                        | 创建通知的UID。              |
| creatorPid            | 是  | 否  | number                                        | 创建通知的PID。              |
| creatorUserId | 是  | 否  | number                                    | 创建通知的UserId。           |
| hashCode              | 是  | 否  | string                                        | 通知唯一标识。               |
| classification        | 是  | 是  | string                                        | 通知分类。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。                   |
| groupName | 是  | 是  | string                                        | 组通知名称。                 |
| template | 是  | 是  | [NotificationTemplate](#notificationtemplate) | 通知模板。                   |
| isRemoveAllowed | 是  | 否  | boolean                                | 通知是否能被移除。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。                   |
| source   | 是  | 否  | number                                        | 通知源。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。                   |
| distributedOption   | 是  | 是  | [DistributedOptions](#distributedoptions)                 | 分布式通知的选项。          |
| deviceId | 是  | 否  | string                                        | 通知源的deviceId。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。          |
| notificationFlags | 是  | 否  | [NotificationFlags](#notificationflags)                    | 获取NotificationFlags。          |
| removalWantAgent | 是  | 是  | WantAgent                    | 当移除通知时，通知将被重定向到的WantAgent实例。          |
| badgeNumber | 是  | 是  | number                    | 应用程序图标上显示的通知数。          |


## DistributedOptions

描述分布式选项。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                   | 可读 | 可写 | 类型            | 描述                               |
| ---------------------- | ---- | ---- | -------------- | ---------------------------------- |
| isDistributed          | 是   | 是   | boolean        | 是否为分布式通知。                  |
| supportDisplayDevices  | 是   | 是   | Array\<string> | 可以同步通知到的设备类型。           |
| supportOperateDevices  | 是   | 是   | Array\<string> | 可以打开通知的设备。                |
| remindType             | 是   | 否   | number         | 通知的提醒方式。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。                    |


## NotificationSlot

描述通知槽

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                 | 可读 | 可写 | 类型                  | 描述                                       |
| -------------------- | ---- | --- | --------------------- | ------------------------------------------ |
| type                 | 是  | 是  | [SlotType](#slottype) | 通道类型。                                   |
| level                | 是  | 是  | number                | 通知级别，不设置则根据通知渠道类型有默认值。 |
| desc                 | 是  | 是  | string                | 通知渠道描述信息。                           |
| badgeFlag            | 是  | 是  | boolean               | 是否显示角标。                               |
| bypassDnd            | 是  | 是  | boolean               | 置是否在系统中绕过免打扰模式。               |
| lockscreenVisibility | 是  | 是  | number                | 在锁定屏幕上显示通知的模式。                 |
| vibrationEnabled     | 是  | 是  | boolean               | 是否可振动。                                 |
| sound                | 是  | 是  | string                | 通知提示音。                                 |
| lightEnabled         | 是  | 是  | boolean               | 是否闪灯。                                   |
| lightColor           | 是  | 是  | number                | 通知灯颜色。                                 |
| vibrationValues      | 是  | 是  | Array\<number\>       | 通知振动样式。                               |
| enabled<sup>9+</sup> | 是  | 否  | boolean               | 此通知插槽中的启停状态。                      |


## NotificationTemplate

通知模板。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称 | 参数类型               | 可读 | 可写 | 说明       |
| ---- | ---------------------- | ---- | ---- | ---------- |
| name | string                 | 是   | 是   | 模板名称。 |
| data | {[key:string]: Object} | 是   | 是   | 模板数据。 |


## NotificationUserInput

保存用户输入的通知消息。

**系统能力**：SystemCapability.Notification.Notification

| 名称     | 可读 | 可写 | 类型   | 描述                          |
| -------- | --- | ---- | ------ | ----------------------------- |
| inputKey | 是  | 是  | string | 用户输入时用于标识此输入的key。 |


## DeviceRemindType

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称                 | 值  | 描述                               |
| -------------------- | --- | --------------------------------- |
| IDLE_DONOT_REMIND    | 0   | 设备未被使用，无需提醒。            |
| IDLE_REMIND          | 1   | 提醒设备未被使用。                 |
| ACTIVE_DONOT_REMIND  | 2   | 设备正在使用，无需提醒。            |
| ACTIVE_REMIND        | 3   | 提醒设备正在使用。                 |


## SourceType

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称                 | 值  | 描述                  |
| -------------------- | --- | -------------------- |
| TYPE_NORMAL          | 0   | 一般通知。            |
| TYPE_CONTINUOUS      | 1   | 连续通知。            |
| TYPE_TIMER           | 2   | 计划通知。            |
