# @ohos.notification (Notification模块)

本模块提供通知管理的能力，包括发布、取消发布通知，创建、获取、移除通知通道，订阅、取消订阅通知，获取通知的使能状态、角标使能状态，获取通知的相关信息等。

一般情况下，只有系统应用具有通知订阅和取消订阅的权限。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import Notification from '@ohos.notification';
```

## Notification.publish

publish(request: NotificationRequest, callback: AsyncCallback\<void\>): void

发布通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](#notificationrequest) | 是   | 设置要发布通知内容的NotificationRequest对象。 |
| callback | AsyncCallback\<void\>                       | 是   | 被指定的回调方法。                            |

**示例：**

```js
//publish回调
function publishCallback(err) {
    if (err.code) {
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

| 参数名     | 类型                                        | 必填 | 说明                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](#notificationrequest) | 是   | 设置要发布通知内容的NotificationRequest对象。 |

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

## Notification.publish<sup>8+</sup>

publish(request: NotificationRequest, userId: number, callback: AsyncCallback\<void\>): void

发布通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](#notificationrequest) | 是   | 设置要发布通知内容的NotificationRequest对象。 |
| userId   | number                                      | 是   | 接收通知用户的Id。                           |
| callback | AsyncCallback\<void\>                       | 是   | 被指定的回调方法。                           |

**示例：**

```js
//publish回调
function publishCallback(err) {
    if (err.code) {
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

## Notification.publish<sup>8+</sup>

publish(request: NotificationRequest, userId: number): Promise\<void\>

发布通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     |  类型                                        | 必填 | 说明                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | [NotificationRequest](#notificationrequest) | 是   | 设置要发布通知内容的NotificationRequest对象。 |
| userId   | number                                      | 是   | 接收通知用户的Id。                           |

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

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| id       | number                | 是   | 通知ID。               |
| label    | string                | 是   | 通知标签。             |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
//cancel回调
function cancelCallback(err) {
    if (err.code) {
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

| 参数名  | 类型   | 必填 | 说明     |
| ----- | ------ | ---- | -------- |
| id    | number | 是   | 通知ID。   |
| label | string | 否   | 通知标签。 |

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

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| id       | number                | 是   | 通知ID。               |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
//cancel回调
function cancelCallback(err) {
    if (err.code) {
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

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
//cancel回调
function cancelAllCallback(err) {
    if (err.code) {
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

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| slot     | [NotificationSlot](#notificationslot)       | 是   | 要创建的通知通道对象。 |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
//addslot回调
function addSlotCallBack(err) {
    if (err.code) {
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

| 参数名 | 类型             | 必填 | 说明                 |
| ---- | ---------------- | ---- | -------------------- |
| slot | [NotificationSlot](#notificationslot) | 是   | 要创建的通知通道对象。 |

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

| 参数名     | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| type     | [SlotType](#slottype)              | 是   | 要创建的通知通道的类型。 |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。   |

**示例：**

```js
//addslot回调
function addSlotCallBack(err) {
    if (err.code) {
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

| 参数名 | 类型     | 必填 | 说明                   |
| ---- | -------- | ---- | ---------------------- |
| type | [SlotType](#slottype) | 是   | 要创建的通知通道的类型。 |

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

| 参数名     | 类型                      | 必填 | 说明                     |
| -------- | ------------------------- | ---- | ------------------------ |
| slots    | Array\<[NotificationSlot](#notificationslot)\> | 是   | 要创建的通知通道对象数组。 |
| callback | AsyncCallback\<void\>     | 是   | 表示被指定的回调方法。     |

**示例：**

```js
//addSlots回调
function addSlotsCallBack(err) {
    if (err.code) {
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

| 参数名  | 类型                      | 必填 | 说明                     |
| ----- | ------------------------- | ---- | ------------------------ |
| slots | Array\<[NotificationSlot](#notificationslot)\> | 是   | 要创建的通知通道对象数组。 |

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

| 参数名     | 类型                              | 必填 | 说明                                                        |
| -------- | --------------------------------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype)                          | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |
| callback | AsyncCallback\<[NotificationSlot](#notificationslot)\> | 是   | 表示被指定的回调方法。                                        |

**示例：**

```js
//getSlot回调
function getSlotCallback(err,data) {
    if (err.code) {
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

| 参数名     | 类型     | 必填 | 说明                                                        |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype) | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<NotificationSlot\> | 以Promise形式返回获取一个通知通道。 |

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

| 参数名     | 类型                              | 必填 | 说明                 |
| -------- | --------------------------------- | ---- | -------------------- |
| callback | AsyncCallback\<Array\<[NotificationSlot](#notificationslot)\>\> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
//getSlots回调
function getSlotsCallback(err,data) {
    if (err.code) {
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

| 参数名     | 类型                  | 必填 | 说明                                                        |
| -------- | --------------------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype)              | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。                                        |

**示例：**

```js
//removeSlot回调
function removeSlotCallback(err) {
    if (err.code) {
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

| 参数名     | 类型     | 必填 | 说明                                                        |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| slotType | [SlotType](#slottype) | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |

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

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
function removeAllCallBack(err) {
    if (err.code) {
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

**示例：**

```js
Notification.removeAllSlots().then(() => {
	console.info("removeAllSlots sucess");
});
```



## Notification.subscribe

subscribe(subscriber: NotificationSubscriber, info: NotificationSubscribeInfo, callback: AsyncCallback\<void\>): void

订阅通知并指定订阅信息（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型                      | 必填 | 说明             |
| ---------- | ------------------------- | ---- | ---------------- |
| subscriber | [NotificationSubscriber](#notificationsubscriber)    | 是   | 通知订阅对象。     |
| info       | [NotificationSubscribeInfo](#notificationsubscribeinfo) | 是   | 订阅信息。         |
| callback   | AsyncCallback\<void\>     | 是   | 订阅动作回调函数。 |

**示例：**

```js
//subscribe回调
function subscribeCallback(err) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe success");
    }
}
function onConsumeCallback(data) {
	console.info("Consume callback: " + JSON.stringify(data));
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

订阅通知并指定订阅信息（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型                   | 必填 | 说明             |
| ---------- | ---------------------- | ---- | ---------------- |
| subscriber | [NotificationSubscriber](#notificationsubscriber) | 是   | 通知订阅对象。     |
| callback   | AsyncCallback\<void\>  | 是   | 订阅动作回调函数。 |

**示例：**

```js
function subscribeCallback(err) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe success");
    }
}
function onConsumeCallback(data) {
	console.info("Consume callback: " + JSON.stringify(data));
}
var subscriber = {
    onConsume: onConsumeCallback
}
Notification.subscribe(subscriber, subscribeCallback);
```



## Notification.subscribe

subscribe(subscriber: NotificationSubscriber, info?: NotificationSubscribeInfo): Promise\<void\>

订阅通知并指定订阅信息（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型                      | 必填 | 说明         |
| ---------- | ------------------------- | ---- | ------------ |
| subscriber | [NotificationSubscriber](#notificationsubscriber)    | 是   | 通知订阅对象。 |
| info       | [NotificationSubscribeInfo](#notificationsubscribeinfo) | 否   | 订阅信息。     |

**示例：**

```js
function onConsumeCallback(data) {
    console.info("Consume callback: " + JSON.stringify(data));
}
var subscriber = {
    onConsume: onConsumeCallback
};
Notification.subscribe(subscriber).then(() => {
	console.info("subscribe sucess");
});
```



## Notification.unsubscribe

unsubscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>): void

取消订阅（callbcak形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型                   | 必填 | 说明                 |
| ---------- | ---------------------- | ---- | -------------------- |
| subscriber | [NotificationSubscriber](#notificationsubscriber) | 是   | 通知订阅对象。         |
| callback   | AsyncCallback\<void\>  | 是   | 取消订阅动作回调函数。 |

**示例：**

```js
function unsubscribeCallback(err) {
    if (err.code) {
        console.info("unsubscribe failed " + JSON.stringify(err));
    } else {
        console.info("unsubscribe success");
    }
}
function onCancelCallback(data) {
	console.info("Cancel callback: " + JSON.stringify(data));
}
var subscriber = {
    onCancel: onCancelCallback
}
Notification.unsubscribe(subscriber, unsubscribeCallback);
```



## Notification.unsubscribe

unsubscribe(subscriber: NotificationSubscriber): Promise\<void\>

取消订阅（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名       | 类型                   | 必填 | 说明         |
| ---------- | ---------------------- | ---- | ------------ |
| subscriber | [NotificationSubscriber](#notificationsubscriber) | 是   | 通知订阅对象。 |

**示例：**

```js
function onCancelCallback(data) {
	console.info("Cancel callback: " + JSON.stringify(data));
}
var subscriber = {
    onCancel: onCancelCallback
};
Notification.unsubscribe(subscriber).then(() => {
	console.info("unsubscribe sucess");
});
```



## Notification.enableNotification

enableNotification(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

设定指定包的通知使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](#bundleoption)          | 是   | 指定包信息。           |
| enable   | boolean               | 是   | 使能状态。             |
| callback | AsyncCallback\<void\> | 是   | 设定通知使能回调函数。 |

**示例：**

```js
function enableNotificationCallback(err) {
    if (err.code) {
        console.info("enableNotification failed " + JSON.stringify(err));
    } else {
        console.info("enableNotification success");
    }
}
var bundle = {
    bundle: "bundleName1",
}
Notification.enableNotification(bundle, false, enableNotificationCallback);
```



## Notification.enableNotification

enableNotification(bundle: BundleOption, enable: boolean): Promise\<void\>

设定指定包的通知使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。 |
| enable | boolean      | 是   | 使能状态。   |

**示例：**

```js
var bundle = {
    bundle: "bundleName1",
}
Notification.enableNotification(bundle, false).then(() => {
	console.info("enableNotification sucess");
});
```



## Notification.isNotificationEnabled

isNotificationEnabled(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

获取指定包的通知使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名     | 类型                  | 必填 | 说明                     |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](#bundleoption)          | 是   | 指定包信息。               |
| callback | AsyncCallback\<void\> | 是   | 获取通知使能状态回调函数。 |

**示例：**

```js
function isNotificationEnabledCallback(err, data) {
    if (err.code) {
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

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取指定包的通知使能状态的结果。 |

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

| 参数名     | 类型                  | 必填 | 说明                     |
| -------- | --------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void\> | 是   | 获取通知使能状态回调函数。 |

**示例：**

```js
function isNotificationEnabledCallback(err, data) {
    if (err.code) {
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

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取通知使能状态的结果。 |

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

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](#bundleoption)          | 是   | 指定包信息。           |
| enable   | boolean               | 是   | 使能状态。             |
| callback | AsyncCallback\<void\> | 是   | 设定角标使能回调函数。 |

**示例：**

```js
function displayBadgeCallback(err) {
    if (err.code) {
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

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。 |
| enable | boolean      | 是   | 使能状态。   |

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

| 参数名     | 类型                  | 必填 | 说明                     |
| -------- | --------------------- | ---- | ------------------------ |
| bundle   | [BundleOption](#bundleoption)          | 是   | 指定包信息。               |
| callback | AsyncCallback\<void\> | 是   | 获取角标使能状态回调函数。 |

**示例：**

```js
function isBadgeDisplayedCallback(err, data) {
    if (err.code) {
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

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取指定包的角标使能状态。 |

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

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| bundle   | [BundleOption](#bundleoption)          | 是   | 指定包信息。           |
| slot     | [NotificationSlot](#notificationslot)      | 是   | 通知通道。             |
| callback | AsyncCallback\<void\> | 是   | 设定通知通道回调函数。 |

**示例：**

```js
function setSlotByBundleCallback(err) {
    if (err.code) {
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

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。 |
| slot   | [NotificationSlot](#notificationslot) | 是   | 使能状态。   |

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

| 参数名     | 类型                                     | 必填 | 说明                 |
| -------- | ---------------------------------------- | ---- | -------------------- |
| bundle   | [BundleOption](#bundleoption)                             | 是   | 指定包信息。           |
| callback | AsyncCallback<Array\<[NotificationSlot](#notificationslot)\>> | 是   | 获取通知通道回调函数。 |

**示例：**

```js
function getSlotsByBundleCallback(err, data) {
    if (err.code) {
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

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise<Array\<[NotificationSlot](#notificationslot)\>> | 以Promise形式返回获取指定包的通知通道。 |

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

| 参数名     | 类型                      | 必填 | 说明                   |
| -------- | ------------------------- | ---- | ---------------------- |
| bundle   | [BundleOption](#bundleoption)              | 是   | 指定包信息。             |
| callback | AsyncCallback\<number\> | 是   | 获取通知通道数回调函数。 |

**示例：**

```js
function getSlotNumByBundleCallback(err, data) {
    if (err.code) {
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

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 是   | 指定包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | 以Promise形式返回获取指定包的通知通道数。 |

**示例：**

```js
var bundle = {
    bundle: "bundleName1",
}
Notification.getSlotNumByBundle(bundle).then((data) => {
	console.info("getSlotNumByBundle sucess, data: " + JSON.stringify(data));
});
```



## Notification.remove

remove(bundle: BundleOption, notificationKey: NotificationKey, reason: RemoveReason, callback: AsyncCallback\<void\>): void

删除指定通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名            | 类型                                | 必填 | 说明                 |
| --------------- |   ----------------------------------| ---- | -------------------- |
| bundle          | [BundleOption](#bundleoption)       | 是   | 指定包信息。           |
| notificationKey | [NotificationKey](#notificationkey) | 是   | 通知键值。             |
| reason          | [RemoveReason](#removereason9)      | 是   | 通知删除原因。         |
| callback        | AsyncCallback\<void\>               | 是   | 删除指定通知回调函数。 |

**示例：**

```js
function removeCallback(err) {
    if (err.code) {
        console.info("remove failed " + JSON.stringify(err));
    } else {
        console.info("remove success");
    }
}
var bundle = {
    bundle: "bundleName1",
}
var notificationKey = {
    id: 0,
    label: "label",
}
var reason = Notification.RemoveReason.CLICK_REASON_REMOVE;
Notification.remove(bundle, notificationKey, reason, removeCallback);
```



## Notification.remove

remove(bundle: BundleOption, notificationKey: NotificationKey, reason: RemoveReason): Promise\<void\>

删除指定通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名            | 类型            | 必填 | 说明       |
| --------------- | --------------- | ---- | ---------- |
| bundle          | [BundleOption](#bundleoption)    | 是   | 指定包信息。 |
| notificationKey | [NotificationKey](#notificationkey) | 是   | 通知键值。   |
| reason          | [RemoveReason](#removereason9) | 是   | 通知删除原因。         |

**示例：**

```js
var bundle = {
    bundle: "bundleName1",
}
var notificationKey = {
    id: 0,
    label: "label",
}
var reason = Notification.RemoveReason.CLICK_REASON_REMOVE;
Notification.remove(bundle, notificationKey, reason).then(() => {
	console.info("remove sucess");
});
```



## Notification.remove

remove(hashCode: string, reason: RemoveReason, callback: AsyncCallback\<void\>): void

删除指定通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| hashCode | string                | 是   | 通知唯一ID。           |
| reason   | [RemoveReason](#removereason9) | 是   | 通知删除原因。         |
| callback | AsyncCallback\<void\> | 是   | 删除指定通知回调函数。 |

**示例：**

```js
var hashCode = 'hashCode'

function removeCallback(err) {
    if (err.code) {
        console.info("remove failed " + JSON.stringify(err));
    } else {
        console.info("remove success");
    }
}
var reason = Notification.RemoveReason.CANCEL_REASON_REMOVE;
Notification.remove(hashCode, reason, removeCallback);
```



## Notification.remove

remove(hashCode: string, reason: RemoveReason): Promise\<void\>

删除指定通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型       | 必填 | 说明       |
| -------- | ---------- | ---- | ---------- |
| hashCode | string | 是   | 通知唯一ID。 |
| reason   | [RemoveReason](#removereason9) | 是   | 通知删除原因。         |

**示例：**

```js
var hashCode = 'hashCode'
var reason = Notification.RemoveReason.CLICK_REASON_REMOVE;
Notification.remove(hashCode, reason).then(() => {
	console.info("remove sucess");
});
```



## Notification.removeAll

removeAll(bundle: BundleOption, callback: AsyncCallback\<void\>): void

删除指定包的所有通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**参数：**

| 参数名     | 类型                  | 必填 | 说明                         |
| -------- | --------------------- | ---- | ---------------------------- |
| bundle   | [BundleOption](#bundleoption)          | 是   | 指定包信息。                   |
| callback | AsyncCallback\<void\> | 是   | 删除指定包的所有通知回调函数。 |

**示例：**

```js
function removeAllCallback(err) {
    if (err.code) {
        console.info("removeAll failed " + JSON.stringify(err));
    } else {
        console.info("removeAll success");
    }
}
var bundle = {
    bundle: "bundleName1",
}
Notification.removeAll(bundle, removeAllCallback);
```



## Notification.removeAll

removeAll(callback: AsyncCallback\<void\>): void

删除所有通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                 |
| -------- | --------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 删除所有通知回调函数。 |

**示例：**

```js
function removeAllCallback(err) {
    if (err.code) {
        console.info("removeAll failed " + JSON.stringify(err));
    } else {
        console.info("removeAll success");
    }
}

Notification.removeAll(removeAllCallback);
```



## Notification.removeAll

removeAll(bundle?: BundleOption): Promise\<void\>

删除所有通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| bundle | [BundleOption](#bundleoption) | 否   | 指定包信息。 |

**示例：**

```js
Notification.removeAll().then(() => {
	console.info("removeAll sucess");
});
```

## Notification.removeAll<sup>8+</sup>

removeAll(userId: number, callback: AsyncCallback\<void>): void

删除所有通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| userId | number | 是   | 接收通知用户的Id。 |
| callback | AsyncCallback\<void\> | 是   | 删除所有通知回调函数。 |

**示例：**

```js
function removeAllCallback(err) {
    if (err.code) {
        console.info("removeAll failed " + JSON.stringify(err));
    } else {
        console.info("removeAll success");
    }
}

var userId = 1

Notification.removeAll(userId, removeAllCallback);
```

## Notification.removeAll<sup>8+</sup>

removeAll(userId: number): Promise\<void>

删除所有通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型         | 必填 | 说明       |
| ------ | ------------ | ---- | ---------- |
| userId | number | 是   | 接收通知用户的Id。 |

**示例：**

```js
function removeAllCallback(err) {
    if (err.code) {
        console.info("removeAll failed " + JSON.stringify(err));
    } else {
        console.info("removeAll success");
    }
}

var userId = 1

Notification.removeAll(userId, removeAllCallback);
```


## Notification.getAllActiveNotifications

getAllActiveNotifications(callback: AsyncCallback<Array\<NotificationRequest\>>): void

获取活动通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| -------- | ------------------------------------------------------------ | ---- | -------------------- |
| callback | AsyncCallback<Array\<[NotificationRequest](#notificationrequest)\>> | 是   | 获取活动通知回调函数。 |

**示例：**

```js
function getAllActiveNotificationsCallback(err, data) {
    if (err.code) {
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

| 参数名     | 类型                   | 必填 | 说明                   |
| -------- | ---------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<number\> | 是   | 获取活动通知数回调函数。 |

**示例：**

```js
function getActiveNotificationCountCallback(err, data) {
    if (err.code) {
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

| 参数名     | 类型                                                         | 必填 | 说明                           |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback<Array\<[NotificationRequest](#notificationrequest)\>> | 是   | 获取当前应用的活动通知回调函数。 |

**示例：**

```js
function getActiveNotificationsCallback(err, data) {
    if (err.code) {
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

**示例：**

```js
Notification.getActiveNotifications().then((data) => {
	console.info("removeGroupByBundle sucess, data: " + JSON.stringify(data));
});
```



## Notification.cancelGroup<sup>8+</sup>

cancelGroup(groupName: string, callback: AsyncCallback\<void\>): void

取消本应用指定组通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名      | 类型                  | 必填 | 说明                         |
| --------- | --------------------- | ---- | ---------------------------- |
| groupName | string                | 是   | 指定通知组名称。               |
| callback  | AsyncCallback\<void\> | 是   | 取消本应用指定组通知回调函数。 |

**示例：**

```js
function cancelGroupCallback(err) {
    if (err.code) {
        console.info("cancelGroup failed " + JSON.stringify(err));
    } else {
        console.info("cancelGroup success");
    }
}

var groupName = "GroupName";

Notification.cancelGroup(groupName, cancelGroupCallback);
```



## Notification.cancelGroup<sup>8+</sup>

cancelGroup(groupName: string): Promise\<void\>

取消本应用指定组通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名      | 类型   | 必填 | 说明           |
| --------- | ------ | ---- | -------------- |
| groupName | string | 是   | 指定通知组名称。 |

**示例：**

```js
var groupName = "GroupName";
Notification.cancelGroup(groupName).then(() => {
	console.info("cancelGroup sucess");
});
```



## Notification.removeGroupByBundle<sup>8+</sup>

removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void\>): void

删除指定应用指定组通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名      | 类型                  | 必填 | 说明                         |
| --------- | --------------------- | ---- | ---------------------------- |
| bundle    | [BundleOption](#bundleoption)          | 是   | 指定包信息。                   |
| groupName | string                | 是   | 指定通知组名称。               |
| callback  | AsyncCallback\<void\> | 是   | 删除本应用指定组通知回调函数。 |

**示例：**

```js
function removeGroupByBundleCallback(err) {
    if (err.code) {
        console.info("removeGroupByBundle failed " + JSON.stringify(err));
    } else {
        console.info("removeGroupByBundle success");
    }
}

var bundleOption = {bundle: "Bundle"};
var groupName = "GroupName";

Notification.removeGroupByBundle(bundleOption, groupName, removeGroupByBundleCallback);
```



## Notification.removeGroupByBundle<sup>8+</sup>

removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void\>

删除指定应用指定组通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名      | 类型         | 必填 | 说明           |
| --------- | ------------ | ---- | -------------- |
| bundle    | [BundleOption](#bundleoption) | 是   | 指定包信息。     |
| groupName | string       | 是   | 指定通知组名称。 |

**示例：**

```js
var bundleOption = {bundle: "Bundle"};
var groupName = "GroupName";
Notification.removeGroupByBundle(bundleOption, groupName).then(() => {
	console.info("removeGroupByBundle sucess");
});
```



## Notification.setDoNotDisturbDate<sup>8+</sup>

setDoNotDisturbDate(date: DoNotDisturbDate, callback: AsyncCallback\<void\>): void

设置免打扰时间（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate8)      | 是   | 免打扰时间选项。         |
| callback | AsyncCallback\<void\> | 是   | 设置免打扰时间回调函数。 |

**示例：**

```js
function setDoNotDisturbDateCallback(err) {
    if (err.code) {
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



## Notification.setDoNotDisturbDate<sup>8+</sup>

setDoNotDisturbDate(date: DoNotDisturbDate): Promise\<void\>

设置免打扰时间接口（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型             | 必填 | 说明           |
| ---- | ---------------- | ---- | -------------- |
| date | [DoNotDisturbDate](#donotdisturbdate8) | 是   | 免打扰时间选项。 |

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


## Notification.setDoNotDisturbDate<sup>8+</sup>

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number, callback: AsyncCallback\<void\>): void

指定用户设置免打扰时间（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                  | 必填 | 说明                   |
| -------- | --------------------- | ---- | ---------------------- |
| date     | [DoNotDisturbDate](#donotdisturbdate8)      | 是   | 免打扰时间选项。         |
| userId   | number                | 是   | 设置免打扰事件的用户ID。 |
| callback | AsyncCallback\<void\> | 是   | 设置免打扰时间回调函数。 |

**示例：**

```js
function setDoNotDisturbDateCallback(err) {
    if (err.code) {
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



## Notification.setDoNotDisturbDate<sup>8+</sup>

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number): Promise\<void\>

指定用户设置免打扰时间接口（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型             | 必填 | 说明           |
| ------ | ---------------- | ---- | -------------- |
| date   | [DoNotDisturbDate](#donotdisturbdate8) | 是   | 免打扰时间选项。 |
| userId | number           | 是   | 设置免打扰事件的用户ID。 |

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


## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate\>): void

查询免打扰时间接口（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                              | 必填 | 说明                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate8)\> | 是   | 查询免打扰时间回调函数。 |

**示例：**

```js
function getDoNotDisturbDateCallback(err,data) {
    if (err.code) {
        console.info("getDoNotDisturbDate failed " + JSON.stringify(err));
    } else {
        console.info("getDoNotDisturbDate success");
    }
}

Notification.getDoNotDisturbDate(getDoNotDisturbDateCallback);
```



## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(): Promise\<DoNotDisturbDate\>

查询免打扰时间接口（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[DoNotDisturbDate](#donotdisturbdate8)\> | 以Promise形式返回获取查询免打扰时间接口。 |

**示例：**

```js
Notification.getDoNotDisturbDate().then((data) => {
	console.info("getDoNotDisturbDate sucess, data: " + JSON.stringify(data));
});
```


## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(userId: number, callback: AsyncCallback\<DoNotDisturbDate\>): void

指定用户查询免打扰时间接口（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                              | 必填 | 说明                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback\<[DoNotDisturbDate](#donotdisturbdate8)\> | 是   | 查询免打扰时间回调函数。 |
| userId   | number                            | 是   | 设置免打扰事件的用户ID。 |

**示例：**

```js
function getDoNotDisturbDateCallback(err,data) {
    if (err.code) {
        console.info("getDoNotDisturbDate failed " + JSON.stringify(err));
    } else {
        console.info("getDoNotDisturbDate success");
    }
}

var userId = 1

Notification.getDoNotDisturbDate(userId, getDoNotDisturbDateCallback);
```



## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(userId: number): Promise\<DoNotDisturbDate\>

指定用户查询免打扰时间接口（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                              | 必填 | 说明                   |
| -------- | --------------------------------- | ---- | ---------------------- |
| userId   | number                            | 是   | 设置免打扰事件的用户ID。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[DoNotDisturbDate](#donotdisturbdate8)\> | 以Promise形式返回获取查询免打扰时间接口。 |

**示例：**

```js
var userId = 1

Notification.getDoNotDisturbDate(userId).then((data) => {
	console.info("getDoNotDisturbDate sucess, data: " + JSON.stringify(data));
});
```


## Notification.supportDoNotDisturbMode<sup>8+</sup>

supportDoNotDisturbMode(callback: AsyncCallback\<boolean\>): void

查询是否支持勿扰模式功能（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名     | 类型                     | 必填 | 说明                             |
| -------- | ------------------------ | ---- | -------------------------------- |
| callback | AsyncCallback\<boolean\> | 是   | 查询是否支持勿扰模式功能回调函数。 |

**示例：**

```js
function supportDoNotDisturbModeCallback(err,data) {
    if (err.code) {
        console.info("supportDoNotDisturbMode failed " + JSON.stringify(err));
    } else {
        console.info("supportDoNotDisturbMode success");
    }
}

Notification.supportDoNotDisturbMode(supportDoNotDisturbModeCallback);
```



## Notification.supportDoNotDisturbMode<sup>8+</sup>

supportDoNotDisturbMode(): Promise\<boolean\>

查询是否支持勿扰模式功能（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取是否支持勿扰模式功能的结果。 |

**示例：**

```js
Notification.supportDoNotDisturbMode().then((data) => {
	console.info("supportDoNotDisturbMode sucess, data: " + JSON.stringify(data));
});
```



## Notification.isSupportTemplate<sup>8+</sup>

isSupportTemplate(templateName: string, callback: AsyncCallback\<boolean\>): void

查询模板是否存在（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名       | 类型                     | 必填 | 说明                       |
| ------------ | ------------------------ | ---- | -------------------------- |
| templateName | string                   | 是   | 模板名称。                   |
| callback     | AsyncCallback\<boolean\> | 是   | 查询模板是否存在的回调函数。 |

**示例：**

```javascript
var templateName = 'process';
function isSupportTemplateCallback(err, data) {
    if (err.code) {
        console.info("isSupportTemplate failed " + JSON.stringify(err));
    } else {
        console.info("isSupportTemplate success");
    }
}

Notification.isSupportTemplate(templateName, isSupportTemplateCallback);
```



## Notification.isSupportTemplate<sup>8+</sup>

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

**示例：**

```javascript
var templateName = 'process';

Notification.isSupportTemplate(templateName).then((data) => {
    console.info("isSupportTemplate success, data: " + JSON.stringify(data));
});
```



## Notification.requestEnableNotification<sup>8+</sup>

requestEnableNotification(callback: AsyncCallback\<void\>): void

应用请求通知使能（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<void\> | 是   | 应用请求通知使能的回调函数。 |

**示例：**

```javascript
function requestEnableNotificationCallback(err) {
    if (err.code) {
        console.info("requestEnableNotification failed " + JSON.stringify(err));
    } else {
        
    }
};

Notification.requestEnableNotification(requestEnableNotificationCallback);
```



## Notification.requestEnableNotification<sup>8+</sup>

requestEnableNotification(): Promise\<void\>

应用请求通知使能（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**示例：**

```javascript
Notification.requestEnableNotification()
    .then(() => {
        console.info("requestEnableNotification sucess");
	});
```


## Notification.enableDistributed<sup>8+</sup>

enableDistributed(enable: boolean, callback: AsyncCallback\<void\>): void

设置设备是否支持分布式通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | 是   | 是否支持。<br/>true 支持。<br/>false 不支持。|
| callback | AsyncCallback\<void\> | 是   | 设置设备是否支持分布式通知的回调函数。 |

**示例：**

```javascript
function enabledNotificationCallback(err) {
    if (err.code) {
        console.info("enableDistributed failed " + JSON.stringify(err));
    } else {
        console.info("enableDistributed success");
    }
};

var enable = true

Notification.enableDistributed(enable, enabledNotificationCallback);
```



## Notification.enableDistributed<sup>8+</sup>

enableDistributed(enable: boolean): Promise\<void>

设置设备是否支持分布式通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | 是   | 是否支持。<br/>true 支持。<br/>false 不支持。|

**示例：**

```javascript
var enable = true

Notification.enableDistributed(enable)
    .then(() => {
        console.info("enableDistributed sucess");
    });
```


## Notification.isDistributedEnabled<sup>8+</sup>

isDistributedEnabled(callback: AsyncCallback\<boolean>): void

获取设备是否支持分布式通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<boolean\> | 是   | 设备是否支持分布式通知的回调函数。 |

**示例：**

```javascript
function isDistributedEnabledCallback(err, data) {
    if (err.code) {
        console.info("isDistributedEnabled failed " + JSON.stringify(err));
    } else {
        console.info("isDistributedEnabled success " + JSON.stringify(data));
    }
};

Notification.isDistributedEnabled(isDistributedEnabledCallback);
```



## Notification.isDistributedEnabled<sup>8+</sup>

isDistributedEnabled(): Promise\<boolean>

获取设备是否支持分布式通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型               | 说明            |
| ------------------ | --------------- |
| Promise\<boolean\> | Promise方式返回设备是否支持分布式通知的结果。<br/>true 支持。<br/>false 不支持。 |

**示例：**

```javascript
Notification.isDistributedEnabled()
    .then((data) => {
        console.info("isDistributedEnabled sucess, data: " + JSON.stringify(data));
    });
```


## Notification.enableDistributedByBundle<sup>8+</sup>

enableDistributedByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void

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

**示例：**

```javascript
function enableDistributedByBundleCallback(err) {
    if (err.code) {
        console.info("enableDistributedByBundle failed " + JSON.stringify(err));
    } else {
        console.info("enableDistributedByBundle success");
    }
};

var bundle = {
    bundle: "bundleName1",
}

var enable = true

Notification.enableDistributedByBundle(bundle, enable, enableDistributedByBundleCallback);
```



## Notification.enableDistributedByBundle<sup>8+</sup>

enableDistributedByBundle(bundle: BundleOption, enable: boolean): Promise\<void>

根据应用的包设置应用程序是否支持分布式通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | [BundleOption](#bundleoption)             | 是   | 应用的包。                |
| enable   | boolean                  | 是   | 是否支持。                  |

**示例：**

```javascript
var bundle = {
    bundle: "bundleName1",
}

var enable = true

Notification.enableDistributedByBundle(bundle, enable)
    .then(() => {
        console.info("enableDistributedByBundle sucess");
    });
```

## Notification.isDistributedEnabledByBundle<sup>8+</sup>

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

**示例：**

```javascript
function isDistributedEnabledByBundleCallback(err, data) {
    if (err.code) {
        console.info("isDistributedEnabledByBundle failed " + JSON.stringify(err));
    } else {
        console.info("isDistributedEnabledByBundle success" + JSON.stringify(data));
    }
};

var bundle = {
    bundle: "bundleName1",
}

Notification.isDistributedEnabledByBundle(bundle, isDistributedEnabledByBundleCallback);
```



## Notification.isDistributedEnabledByBundle<sup>8+</sup>

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


## Notification.getDeviceRemindType<sup>8+</sup>

getDeviceRemindType(callback: AsyncCallback\<DeviceRemindType\>): void

获取通知的提醒方式（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名   | 类型                               | 必填 | 说明                       |
| -------- | --------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<[DeviceRemindType](#deviceremindtype8)\> | 是   | 获取通知的提醒方式的回调函数。 |

**示例：**

```javascript
function getDeviceRemindTypeCallback(err,data) {
    if (err.code) {
        console.info("getDeviceRemindType failed " + JSON.stringify(err));
    } else {
        console.info("getDeviceRemindType success");
    }
};

Notification.getDeviceRemindType(getDeviceRemindTypeCallback);
```



## Notification.getDeviceRemindType<sup>8+</sup>

getDeviceRemindType(): Promise\<DeviceRemindType\>

获取通知的提醒方式（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**需要权限**: ohos.permission.NOTIFICATION_CONTROLLER

**系统API**: 此接口为系统接口，三方应用不支持调用。

**返回值：**

| 类型               | 说明            |
| ------------------ | --------------- |
| Promise\<[DeviceRemindType](#deviceremindtype8)\> | Promise方式返回通知的提醒方式的结果。 |

**示例：**

```javascript
Notification.getDeviceRemindType()
    .then((data) => {
        console.info("getDeviceRemindType sucess, data: " + JSON.stringify(data));
    });
```


## Notification.publishAsBundle<sup>9+</sup>

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

**示例：**

```js
//publishAsBundle回调
function publishAsBundleCallback(err) {
    if (err.code) {
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

## Notification.publishAsBundle<sup>9+</sup>

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

## Notification.cancelAsBundle<sup>9+</sup>

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

**示例：**

```js
//cancelAsBundle
function cancelAsBundleCallback(err) {
    if (err.code) {
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

## Notification.cancelAsBundle<sup>9+</sup>

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

## Notification.enableNotificationSlot <sup>9+</sup>

enableNotificationSlot(bundle: BundleOption, type: SlotType, enable: boolean, callback: AsyncCallback\<void>): void

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

**示例：**

```js
//enableNotificationSlot
function enableSlotCallback(err) {
    if (err.code) {
        console.info("enableNotificationSlot failed " + JSON.stringify(err));
    } else {
        console.info("enableNotificationSlot success");
    }
};

Notification.enableNotificationSlot(
    { bundle: "ohos.samples.notification", },
    Notification.SlotType.SOCIAL_COMMUNICATION,
    true,
    enableSlotCallback);
```

## Notification.enableNotificationSlot <sup>9+</sup>

enableNotificationSlot(bundle: BundleOption, type: SlotType, enable: boolean): Promise\<void> 

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

**示例：**

```js
//enableNotificationSlot
Notification.enableNotificationSlot(
    { bundle: "ohos.samples.notification", },
    Notification.SlotType.SOCIAL_COMMUNICATION,
    true).then(() => {
        console.info("enableNotificationSlot sucess");
    });
```

## Notification.isNotificationSlotEnabled <sup>9+</sup>

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

**示例：**

```js
//isNotificationSlotEnabled
function getEnableSlotCallback(err, data) {
    if (err.code) {
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

## Notification.isNotificationSlotEnabled <sup>9+</sup>

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


## Notification.setSyncNotificationEnabledWithoutApp<sup>9+</sup>

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

**示例：**

```js
let userId = 100;
let enable = true;

function setSyncNotificationEnabledWithoutAppCallback(err) {
    if (err.code) {
        console.info("setSyncNotificationEnabledWithoutApp failed " + JSON.stringify(err));
    } else {
        console.info("setSyncNotificationEnabledWithoutApp success");
    }
}

Notification.setSyncNotificationEnabledWithoutApp(userId, enable, setSyncNotificationEnabledWithoutAppCallback);
```


## Notification.setSyncNotificationEnabledWithoutApp<sup>9+</sup>

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


## Notification.getSyncNotificationEnabledWithoutApp<sup>9+</sup>

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

**示例：**

```js
let userId = 100;

function getSyncNotificationEnabledWithoutAppCallback(data, err) {
    if (err) {
        console.info('getSyncNotificationEnabledWithoutAppCallback, err' + err);
    } else {
        console.info('getSyncNotificationEnabledWithoutAppCallback, data' + data);
    }
}

Notification.getSyncNotificationEnabledWithoutApp(userId, getSyncNotificationEnabledWithoutAppCallback);
```


## Notification.getSyncNotificationEnabledWithoutApp<sup>9+</sup>

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



## NotificationSubscriber

提供订阅者接收到新通知或取消通知时的回调方法。

**系统API**：此接口为系统接口，三方应用不支持调用。

### onConsume

onConsume?: (data: [SubscribeCallbackData](#subscribecallbackdata)) => void

接收通知回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统接口**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [SubscribeCallbackData](#subscribecallbackdata) | 是 | 回调返回接收到的通知信息。 |

**示例：**

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
};

var subscriber = {
    onConsume: onConsumeCallback
};

Notification.subscribe(subscriber, subscribeCallback);
```

### onCancel

onCancel?:(data: [SubscribeCallbackData](#subscribecallbackdata)) => void

删除通知回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [SubscribeCallbackData](#subscribecallbackdata) | 是 | 回调返回接收到的通知信息。 |

**示例：**

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

onUpdate?:(data: [NotificationSortingMap](#notificationsortingmap)) => void

更新通知排序回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| data | [NotificationSortingMap](#notificationsortingmap) | 是 | 回调返回接收到的通知信息。 |

**示例：**

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

onConnect?:() => void

注册订阅回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**示例：**

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

onDisconnect?:() => void

取消订阅回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**示例：**

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

onDestroy?:() => void

服务失联回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**示例：**

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

onDoNotDisturbDateChange?:(mode: notification.[DoNotDisturbDate](#donotdisturbdate8)) => void

免打扰时间选项变更回调函数。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| mode | notification.[DoNotDisturbDate](#donotdisturbdate8) | 是 | 回调返回免打扰时间选项变更。 |

**示例：**
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

onEnabledNotificationChanged?:(callbackData: [EnabledNotificationCallbackData](#enablednotificationcallbackdata8)) => void

监听应用通知使能变化。

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<[EnabledNotificationCallbackData](#enablednotificationcallbackdata8)\> | 是 | 回调返回监听到的应用信息。 |

**示例：**

```javascript
function subscribeCallback(err) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onEnabledNotificationChangedCallback(callbackData) {
    console.info("bundle: ", callbackData.bundle);
    console.info("uid: ", callbackData.uid);
    console.info("enable: ", callbackData.enable);
};

var subscriber = {
    onEnabledNotificationChanged: onEnabledNotificationChangedCallback
};

Notification.subscribe(subscriber, subscribeCallback);
```

## SubscribeCallbackData

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称            | 类型                                              | 可读 | 可写 | 说明     |
| --------------- | ------------------------------------------------- | ---- | --- | -------- |
| request         | [NotificationRequest](#notificationrequest)       | 是  | 否  | 通知内容。 |
| sortingMap      | [NotificationSortingMap](#notificationsortingmap) | 是  | 否  | 排序信息。 |
| reason          | number                                            | 是  | 否  | 删除原因。 |
| sound           | string                                            | 是  | 否  | 通知声音。 |
| vibrationValues | Array\<number\>                                   | 是  | 否  | 通知震动。 |


## EnabledNotificationCallbackData<sup>8+</sup>

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称   | 类型    | 可读 | 可写 | 说明             |
| ------ | ------- | ---- | --- | ---------------- |
| bundle | string  | 是  | 否  | 应用的包名。       |
| uid    | number  | 是  | 否  | 应用的uid。        |
| enable | boolean | 是  | 否  | 应用通知使能状态。 |


## DoNotDisturbDate<sup>8+</sup>

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称  | 类型                                  | 可读 | 可写 | 说明                     |
| -----  ------------------------------------- || ---- | --- | ------------------------ |
| type  | [DoNotDisturbType](#donotdisturbtype8) | 是  | 否  | 指定免打扰设置的时间类型。 |
| begin | Date                                  | 是  | 否  | 指定免打扰设置的起点时间。 |
| end   | Date                                  | 是  | 否  | 指定免打扰设置的终点时间。 |



## DoNotDisturbType<sup>8+</sup>

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

| 名称   | 类型   | 可读 | 可写 | 说明   |
| ------ | ------ |---- | --- |  ------ |
| bundle | string | 是  | 是  | 包名。   |
| uid    | number | 是  | 是  | 用户id。 |



## NotificationKey

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称  | 类型   | 可读 | 可写 | 说明     |
| ----- | ------ | ---- | --- | -------- |
| id    | number | 是  | 是  | 通知ID。   |
| label | string | 是  | 是  | 通知标签。 |


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

| 名称      | 类型                                            | 可读 | 可写 | 说明                      |
| --------- | ----------------------------------------------- | --- | ---- | ------------------------- |
| title     | string                                          | 是  | 是  | 按钮标题。                  |
| wantAgent | WantAgent                                       | 是  | 是  | 点击按钮时触发的WantAgent。 |
| extras    | { [key: string]: any }                          | 是  | 是  | 按钮扩展信息。              |
| userInput<sup>8+</sup> | [NotificationUserInput](#notificationuserinput8) | 是  | 是  | 用户输入对象实例。          |


## NotificationBasicContent

描述普通文本通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型   | 可读 | 可写 | 说明                               |
| -------------- | ------ | ---- | ---- | ---------------------------------- |
| title          | string | 是   | 是   | 通知标题。                         |
| text           | string | 是   | 是   | 通知内容。                         |
| additionalText | string | 是   | 是   | 通知次要内容，是对通知内容的补充。 |


## NotificationLongTextContent

描述长文本通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型   | 可读 | 可写 | 说明                             |
| -------------- | ------ | ---- | --- | -------------------------------- |
| title          | string | 是  | 是  | 通知标题。                         |
| text           | string | 是  | 是  | 通知内容。                         |
| additionalText | string | 是  | 是  | 通知次要内容，是对通知内容的补充。 |
| longText       | string | 是  | 是  | 通知的长文本。                     |
| briefText      | string | 是  | 是  | 通知概要内容，是对通知内容的总结。 |
| expandedTitle  | string | 是  | 是  | 通知展开时的标题。                 |


## NotificationMultiLineContent

描述多行文本通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型            | 可读 | 可写 | 说明                             |
| -------------- | --------------- | --- | --- | -------------------------------- |
| title          | string          | 是  | 是  | 通知标题。                         |
| text           | string          | 是  | 是  | 通知内容。                         |
| additionalText | string          | 是  | 是  | 通知次要内容，是对通知内容的补充。 |
| briefText      | string          | 是  | 是  | 通知概要内容，是对通知内容的总结。 |
| longTitle      | string          | 是  | 是  | 通知展开时的标题。                 |
| lines          | Array\<string\> | 是  | 是  | 通知的多行文本。                   |


## NotificationPictureContent

描述附有图片的通知。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称           | 类型           | 可读 | 可写 | 说明                             |
| -------------- | -------------- | ---- | --- | -------------------------------- |
| title          | string         | 是  | 是  | 通知标题。                         |
| text           | string         | 是  | 是  | 通知内容。                         |
| additionalText | string         | 是  | 是  | 通知次要内容，是对通知内容的补充。 |
| briefText      | string         | 是  | 是  | 通知概要内容，是对通知内容的总结。 |
| expandedTitle  | string         | 是  | 是  | 通知展开时的标题。                 |
| picture        | image.PixelMap | 是  | 是  | 通知的图片内容。                   |


## NotificationContent

描述通知类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称        | 类型                                                         | 可读 | 可写 | 说明               |
| ----------- | ------------------------------------------------------------ | ---- | --- | ------------------ |
| contentType | [ContentType](#contenttype)                                  | 是  | 是  | 通知内容类型。       |
| normal      | [NotificationBasicContent](#notificationbasiccontent)        | 是  | 是  | 基本类型通知内容。   |
| longText    | [NotificationLongTextContent](#notificationlongtextcontent)  | 是  | 是  | 长文本类型通知内容。 |
| multiLine   | [NotificationMultiLineContent](#notificationmultilinecontent) | 是  | 是  | 多行类型通知内容。   |
| picture     | [NotificationPictureContent](#notificationpicturecontent)    | 是  | 是  | 图片类型通知内容。   |


## NotificationFlagStatus<sup>8+</sup>

描述通知标志状态。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统接口**：此接口为系统接口，三方应用不支持调用。

| 名称           | 值  | 说明                               |
| -------------- | --- | --------------------------------- |
| TYPE_NONE      | 0   | 默认标志。                         |
| TYPE_OPEN      | 1   | 通知标志打开。                     |
| TYPE_CLOSE     | 2   | 通知标志关闭。                     |


## NotificationFlags<sup>8+</sup>

描述通知标志的实例。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称             | 类型                    | 可读 | 可写 | 说明                               |
| ---------------- | ---------------------- | ---- | ---- | --------------------------------- |
| soundEnabled     | NotificationFlagStatus | 是   | 否   | 是否启用声音提示。                  |
| vibrationEnabled | NotificationFlagStatus | 是   | 否   | 是否启用振动提醒功能。               |


## NotificationRequest

描述通知的请求。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                  | 类型                                          | 可读 | 可写 | 说明                       |
| --------------------- | --------------------------------------------- | ---- | --- | -------------------------- |
| content               | [NotificationContent](#notificationcontent)   | 是  | 是  | 通知内容。                   |
| id                    | number                                        | 是  | 是  | 通知ID。                     |
| slotType              | [SlotType](#slottype)                         | 是  | 是  | 通道类型。                   |
| isOngoing             | boolean                                       | 是  | 是  | 是否进行时通知。             |
| isUnremovable         | boolean                                       | 是  | 是  | 是否可移除。                 |
| deliveryTime          | number                                        | 是  | 是  | 通知发送时间。               |
| tapDismissed          | boolean                                       | 是  | 是  | 通知是否自动清除。           |
| autoDeletedTime       | number                                        | 是  | 是  | 自动清除的时间。             |
| wantAgent             | WantAgent                                     | 是  | 是  | WantAgent封装了应用的行为意图，点击通知时触发该行为。 |
| extraInfo             | {[key: string]: any}                          | 是  | 是  | 扩展参数。                   |
| color                 | number                                        | 是  | 是  | 通知背景颜色。暂不支持。       |
| colorEnabled          | boolean                                       | 是  | 是  | 通知背景颜色是否使能。暂不支持。  |
| isAlertOnce           | boolean                                       | 是  | 是  | 设置是否仅有一次此通知警报。 |
| isStopwatch           | boolean                                       | 是  | 是  | 是否显示已用时间。           |
| isCountDown           | boolean                                       | 是  | 是  | 是否显示倒计时时间。         |
| isFloatingIcon        | boolean                                       | 是  | 是  | 是否显示状态栏图标。         |
| label                 | string                                        | 是  | 是  | 通知标签。                   |
| badgeIconStyle        | number                                        | 是  | 是  | 通知角标类型。               |
| showDeliveryTime      | boolean                                       | 是  | 是  | 是否显示分发时间。           |
| actionButtons         | Array\<[NotificationActionButton](#notificationactionbutton)\>             | 是  | 是  | 通知按钮，最多两个按钮。     |
| smallIcon             | PixelMap                                      | 是  | 是  | 通知小图标。（可选字段，大小不超过30KB） |
| largeIcon             | PixelMap                                      | 是  | 是  | 通知大图标。（可选字段，大小不超过30KB） |
| creatorBundleName     | string                                        | 是  | 否  | 创建通知的包名。             |
| creatorUid            | number                                        | 是  | 否  | 创建通知的UID。              |
| creatorPid            | number                                        | 是  | 否  | 创建通知的PID。              |
| creatorUserId<sup>8+</sup>| number                                    | 是  | 否  | 创建通知的UserId。           |
| hashCode              | string                                        | 是  | 否  | 通知唯一标识。               |
| classification        | string                                        | 是  | 是  | 通知分类。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。                   |
| groupName<sup>8+</sup>| string                                        | 是  | 是  | 组通知名称。                 |
| template<sup>8+</sup> | [NotificationTemplate](#notificationtemplate8) | 是  | 是  | 通知模板。                   |
| isRemoveAllowed<sup>8+</sup> | boolean                                | 是  | 否  | 通知是否能被移除。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。                   |
| source<sup>8+</sup>   | number                                        | 是  | 否  | 通知源。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。                   |
| distributedOption<sup>8+</sup>   | [DistributedOptions](#distributedoptions8)                 | 是  | 是  | 分布式通知的选项。          |
| deviceId<sup>8+</sup> | string                                        | 是  | 否  | 通知源的deviceId。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。          |
| notificationFlags<sup>8+</sup> | [NotificationFlags](#notificationflags8)                    | 是  | 否  | 获取NotificationFlags。          |
| removalWantAgent<sup>9+</sup> | WantAgent                    | 是  | 是  | 当移除通知时，通知将被重定向到的WantAgent实例。          |
| badgeNumber<sup>9+</sup> | number                    | 是  | 是  | 应用程序图标上显示的通知数。          |

## DistributedOptions<sup>8+</sup>

描述分布式选项。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                   | 类型            | 可读 | 可写 | 说明                               |
| ---------------------- | -------------- | ---- | ---- | ---------------------------------- |
| isDistributed          | boolean        | 是   | 是   | 是否为分布式通知。                  |
| supportDisplayDevices  | Array\<string> | 是   | 是   | 可以同步通知到的设备类型。           |
| supportOperateDevices  | Array\<string> | 是   | 是   | 可以打开通知的设备。                |
| remindType             | number         | 是   | 否   | 通知的提醒方式。<br>**系统API**: 此接口为系统接口，三方应用不支持调用。                    |


## NotificationSlot

描述通知槽

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                 | 类型                  | 可读 | 可写 | 说明                                       |
| -------------------- | --------------------- | ---- | --- | ------------------------------------------ |
| type                 | [SlotType](#slottype) | 是  | 是  | 通道类型。                                   |
| level                | number                | 是  | 是  | 通知级别，不设置则根据通知渠道类型有默认值。 |
| desc                 | string                | 是  | 是  | 通知渠道描述信息。                           |
| badgeFlag            | boolean               | 是  | 是  | 是否显示角标。                               |
| bypassDnd            | boolean               | 是  | 是  | 置是否在系统中绕过免打扰模式。               |
| lockscreenVisibility | number                | 是  | 是  | 在锁定屏幕上显示通知的模式。                 |
| vibrationEnabled     | boolean               | 是  | 是  | 是否可振动。                                 |
| sound                | string                | 是  | 是  | 通知提示音。                                 |
| lightEnabled         | boolean               | 是  | 是  | 是否闪灯。                                   |
| lightColor           | number                | 是  | 是  | 通知灯颜色。                                 |
| vibrationValues      | Array\<number\>       | 是  | 是  | 通知振动样式。                               |
| enabled<sup>9+</sup> | boolean               | 是  | 否  | 此通知插槽中的启停状态。                      |


## NotificationSorting

提供有关活动通知的排序信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称     | 类型                                  | 可读 | 可写 | 说明         |
| -------- | ------------------------------------- | ---- | --- | ------------ |
| slot     | [NotificationSlot](#notificationslot) | 是  | 否  | 通知通道内容。 |
| hashCode | string                                | 是  | 否  | 通知唯一标识。 |
| ranking  | number                                | 是  | 否  | 通知排序序号。 |


## NotificationSortingMap

提供关于已订阅的所有通知中活动通知的排序信息

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称           | 类型                                                         | 可读 | 可写 | 说明             |
| -------------- | ------------------------------------------------------------ | ---- | --- | ---------------- |
| sortings       | {[key: string]: [NotificationSorting](#notificationsorting)} | 是  | 否  | 通知排序信息数组。 |
| sortedHashCode | Array\<string\>                                              | 是  | 否  | 通知唯一标识数组。 |


## NotificationSubscribeInfo

设置订阅所需通知的发布者的信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称        | 类型            | 可读 | 可写 | 说明                            |
| ----------- | --------------- | --- | ---- | ------------------------------- |
| bundleNames | Array\<string\> | 是  | 是  | 指定订阅哪些包名的APP发来的通知。 |
| userId      | number          | 是  | 是  | 指定订阅哪个用户下发来的通知。    |


## NotificationTemplate<sup>8+</sup>

通知模板。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称 | 类型                    | 可读 | 可写 | 说明       |
| ---- | ---------------------- | ---- | ---- | ---------- |
| name | string                 | 是   | 是   | 模板名称。 |
| data | {[key:string]: Object} | 是   | 是   | 模板数据。 |


## NotificationUserInput<sup>8+</sup>

保存用户输入的通知消息。

**系统能力**：SystemCapability.Notification.Notification

| 名称     | 类型   | 可读 | 可写 | 说明                          |
| -------- | ------ | --- | ---- | ----------------------------- |
| inputKey | string | 是  | 是  | 用户输入时用于标识此输入的key。 |


## DeviceRemindType<sup>8+</sup>

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称                 | 值  | 说明                               |
| -------------------- | --- | --------------------------------- |
| IDLE_DONOT_REMIND    | 0   | 设备未被使用，无需提醒。            |
| IDLE_REMIND          | 1   | 提醒设备未被使用。                 |
| ACTIVE_DONOT_REMIND  | 2   | 设备正在使用，无需提醒。            |
| ACTIVE_REMIND        | 3   | 提醒设备正在使用。                 |


## SourceType<sup>8+</sup>

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称                 | 值  | 说明                  |
| -------------------- | --- | -------------------- |
| TYPE_NORMAL          | 0   | 一般通知。            |
| TYPE_CONTINUOUS      | 1   | 连续通知。            |
| TYPE_TIMER           | 2   | 计划通知。            |

## RemoveReason<sup>9+</sup>

**系统能力**：SystemCapability.Notification.Notification

**系统API**: 此接口为系统接口，三方应用不支持调用。

| 名称                 | 值  | 说明                  |
| -------------------- | --- | -------------------- |
| CLICK_REASON_REMOVE  | 1   | 点击通知后删除通知。    |
| CANCEL_REASON_REMOVE | 2   | 用户删除通知。         |