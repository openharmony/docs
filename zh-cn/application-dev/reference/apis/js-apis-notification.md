# Notification模块

>**说明：**
>
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import Notification from '@ohos.notification';
```

## Notification.publish

publish(request: NotificationRequest, callback: AsyncCallback\<void\>): void

发布通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                                        | 必填 | 描述                                        |
| -------- | ---- | ---- | ------------------------------------------- | ---- | ------------------------------------------- |
| request  | 是   | 否   |[NotificationRequest](#notificationrequest) | 是   | 设置要发布通知内容的NotificationRequest对象。 |
| callback | 是   | 否   |AsyncCallback\<void\>                       | 是   | 被指定的回调方法。                            |

**示例：**

```js
//publish回调
function publishCallback(err) {
	console.info("==========================>publishCallback=======================>");
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
	console.info("==========================>publishCallback=======================>");
});

```

## Notification.publish<sup>8+</sup>

publish(request: NotificationRequest, userId: number, callback: AsyncCallback\<void\>): void

发布通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                                        | 必填 | 描述                                        |
| -------- | ---- | ---- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | 是   | 否   |[NotificationRequest](#notificationrequest) | 是   | 设置要发布通知内容的NotificationRequest对象。 |
| userId   | 是   | 否   |number                                      | 是   | 接收通知用户的Id。                           |
| callback | 是   | 否   |AsyncCallback\<void\>                       | 是   | 被指定的回调方法。                           |

**示例：**

```js
//publish回调
function publishCallback(err) {
	console.info("==========================>publishCallback=======================>");
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

**参数：**

| 名称     | 可读 | 可写 | 类型                                        | 必填 | 描述                                        |
| -------- | ---- | ---- | ----------------------------------------- | ---- | ------------------------------------------- |
| request  | 是   | 否   |[NotificationRequest](#notificationrequest) | 是   | 设置要发布通知内容的NotificationRequest对象。 |
| userId   | 是   | 否   |number                                      | 是   | 接收通知用户的Id。                           |

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
	console.info("==========================>publishCallback=======================>");
});
```


## Notification.cancel

cancel(id: number, label: string, callback: AsyncCallback\<void\>): void

取消与指定id和label相匹配的已发布通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                 |
| -------- | --- | ---- | --------------------- | ---- | -------------------- |
| id       | 是   | 否   | number                | 是   | 通知ID。               |
| label    | 是   | 否   | string                | 是   | 通知标签。             |
| callback | 是   | 否   | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
//cancel回调
function cancelCallback(err) {
	console.info("==========================>cancelCallback=======================>");
}
Notification.cancel(0, "label", cancelCallback)
```



## Notification.cancel

cancel(id：number, label?: string): Promise\<void\>

取消与指定id相匹配的已发布通知,label可以指定也可以不指定（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称  | 可读 | 可写 | 类型   | 必填 | 描述     |
| ----- | --- | ---- | ------ | ---- | -------- |
| id    | 是   | 否   | number | 是   | 通知ID。   |
| label | 是   | 否   | string | 否   | 通知标签。 |

**示例：**

```js
Notification.cancel(0).then(() => {
	console.info("==========================>cancelCallback=======================>");
});
```



## Notification.cancel

cancel(id: number, callback: AsyncCallback\<void\>): void

取消与指定id相匹配的已发布通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                 |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| id       | 是   | 否  | number                | 是   | 通知ID。               |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
//cancel回调
function cancelCallback(err) {
	console.info("==========================>cancelCallback=======================>");
}
Notification.cancel(0, cancelCallback)
```



## Notification.cancelAll

cancelAll(callback: AsyncCallback\<void\>): void

取消所有已发布的通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                 |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
//cancel回调
function cancelAllCallback(err) {
	console.info("==========================>cancelAllCallback=======================>");
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
	console.info("==========================>cancelAllCallback=======================>");
});
```



## Notification.addSlot

addSlot(slot: NotificationSlot, callback: AsyncCallback\<void\>): void

创建通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                 |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| slot     | 是   | 否  | NotificationSlot      | 是   | 要创建的通知通道对象。 |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
//addslot回调
function addSlotCallBack(err) {
	console.info("==========================>addSlotCallBack=======================>");
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

**参数：**

| 名称 | 可读 | 可写 | 类型             | 必填 | 描述                 |
| ---- | ---- | --- | ---------------- | ---- | -------------------- |
| slot | 是   | 否  | NotificationSlot | 是   | 要创建的通知通道对象。 |

**示例：**

```js
//通知slot对象
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
Notification.addSlot(notificationSlot).then(() => {
	console.info("==========================>addSlotCallback=======================>");
});
```



## Notification.addSlot

addSlot(type: SlotType, callback: AsyncCallback\<void\>): void

创建通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                   |
| -------- | ---- | --- | --------------------- | ---- | ---------------------- |
| type     | 是   | 否  | [SlotType](#slottype)              | 是   | 要创建的通知通道的类型。 |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。   |

**示例：**

```js
//addslot回调
function addSlotCallBack(err) {
	console.info("==========================>addSlotCallBack=======================>");
}
Notification.addSlot(Notification.SlotType.SOCIAL_COMMUNICATION, addSlotCallBack)
```



## Notification.addSlot

addSlot(type: SlotType): Promise\<void\>

创建通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称 | 可读 | 可写 | 类型     | 必填 | 描述                   |
| ---- | ---- | --- | -------- | ---- | ---------------------- |
| type | 是   | 否  | [SlotType](#slottype) | 是   | 要创建的通知通道的类型。 |

**示例：**

```js
Notification.addSlot(Notification.SlotType.SOCIAL_COMMUNICATION).then(() => {
	console.info("==========================>addSlotCallback=======================>");
});
```



## Notification.addSlots

addSlots(slots: Array\<NotificationSlot\>, callback: AsyncCallback\<void\>): void

创建多个通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                      | 必填 | 描述                     |
| -------- | ---- | --- | ------------------------- | ---- | ------------------------ |
| slots    | 是   | 否  | Array\<NotificationSlot\> | 是   | 要创建的通知通道对象数组。 |
| callback | 是   | 否  | AsyncCallback\<void\>     | 是   | 表示被指定的回调方法。     |

**示例：**

```js
//addSlots回调
function addSlotsCallBack(err) {
	console.info("==========================>addSlotsCallBack=======================>");
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

**参数：**

| 名称  | 可读 | 可写 | 类型                      | 必填 | 描述                     |
| ----- | ---- | --- | ------------------------- | ---- | ------------------------ |
| slots | 是   | 否  | Array\<NotificationSlot\> | 是   | 要创建的通知通道对象数组。 |

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
	console.info("==========================>addSlotCallback=======================>");
});
```



## Notification.getSlot

getSlot(slotType: SlotType, callback: AsyncCallback\<NotificationSlot\>): void

获取一个通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                              | 必填 | 描述                                                        |
| -------- | ---- | --- | --------------------------------- | ---- | ----------------------------------------------------------- |
| slotType | 是   | 否  | [SlotType](#slottype)                          | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |
| callback | 是   | 否  | AsyncCallback\<NotificationSlot\> | 是   | 表示被指定的回调方法。                                        |

**示例：**

```js
//getSlot回调
function getSlotCallback(err,data) {
	console.info("==========================>getSlotCallback=======================>");
}
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.getSlot(slotType, getSlotCallback)
```



## Notification.getSlot

getSlot(slotType: SlotType): Promise\<NotificationSlot\>

获取一个通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型     | 必填 | 描述                                                        |
| -------- | ---- | --- | -------- | ---- | ----------------------------------------------------------- |
| slotType | 是   | 否  | [SlotType](#slottype) | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<NotificationSlot\> | 以Promise形式返回获取一个通知通道。 |

**示例：**

```js
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.getSlot(slotType).then((data) => {
	console.info("==========================>getSlotCallback=======================>");
});
```



## Notification.getSlots

getSlots(callback: AsyncCallback<Array\<NotificationSlot\>>): void

获取此应用程序的所有通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                              | 必填 | 描述                 |
| -------- | ---- | --- | --------------------------------- | ---- | -------------------- |
| callback | 是   | 否  | AsyncCallback\<NotificationSlot\> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
//getSlots回调
function getSlotsCallback(err,data) {
	console.info("==========================>getSlotsCallback=======================>");
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
| Promise\<Array\<NotificationSlot\>\> | 以Promise形式返回获取此应用程序的所有通知通道的结果。 |

**示例：**

```js
Notification.getSlots().then((data) => {
	console.info("==========================>getSlotsCallback=======================>");
});
```



## Notification.removeSlot

removeSlot(slotType: SlotType, callback: AsyncCallback\<void\>): void

根据通知通道类型删除创建的通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                                                        |
| -------- | ---- | --- | --------------------- | ---- | ----------------------------------------------------------- |
| slotType | 是   | 否  | [SlotType](#slottype)              | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。                                        |

**示例：**

```js
//removeSlot回调
function removeSlotCallback(err) {
	console.info("==========================>removeSlotCallback=======================>");
}
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.removeSlot(slotType,removeSlotCallback)
```



## Notification.removeSlot

removeSlot(slotType: SlotType): Promise\<void\>

根据通知通道类型删除创建的通知通道（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型     | 必填 | 描述                                                        |
| -------- | ---- | --- | -------- | ---- | ----------------------------------------------------------- |
| slotType | 是   | 否  | [SlotType](#slottype) | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型。 |

**示例：**

```js
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.removeSlot(slotType).then(() => {
	console.info("==========================>removeSlotCallback=======================>");
});
```



## Notification.removeAllSlots

removeAllSlots(callback: AsyncCallback\<void\>): void

删除所有通知通道（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                 |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
function removeAllCallBack(err) {
	console.info("================>removeAllCallBack=======================>");
}
Notification.removeAllSlots(removeAllCallBack)
```



## Notification.removeAllSlots

removeAllSlots(): Promise\<void\>

删除所有通知通道(Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**示例：**

```js
Notification.removeAllSlots().then(() => {
	console.info("==========================>removeAllCallBack=======================>");
});
```



## Notification.subscribe

subscribe(subscriber: NotificationSubscriber, info: NotificationSubscribeInfo, callback: AsyncCallback\<void\>): void

订阅通知并指定订阅信息（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称       | 可读 | 可写 | 类型                      | 必填 | 描述             |
| ---------- | ---- | --- | ------------------------- | ---- | ---------------- |
| subscriber | 是   | 否  | [NotificationSubscriber](#notificationsubscriber)    | 是   | 通知订阅对象。     |
| info       | 是   | 否  | [NotificationSubscribeInfo](#notificationsubscribeinfo) | 是   | 订阅信息。         |
| callback   | 是   | 否  | AsyncCallback\<void\>     | 是   | 订阅动作回调函数。 |

**示例：**

```js
//subscribe回调
function subscribeCallback(err) {
	console.info("==========================>subscribeCallback=======================>");
}
function onConsumeCallback(err, data) {
	console.info("==========================>onConsumeCallback=======================>");
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

**参数：**

| 名称       | 可读 | 可写 | 类型                   | 必填 | 描述             |
| ---------- | ---- | --- | ---------------------- | ---- | ---------------- |
| subscriber | 是   | 否  | [NotificationSubscriber](#notificationsubscriber) | 是   | 通知订阅对象。     |
| callback   | 是   | 否  | AsyncCallback\<void\>  | 是   | 订阅动作回调函数。 |

**示例：**

```js
function subscribeCallback(err) {
	console.info("==========================>subscribeCallback=======================>");
}
function onConsumeCallback(err, data) {
	console.info("==========================>onConsumeCallback=======================>");
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

**参数：**

| 名称       | 可读 | 可写 | 类型                      | 必填 | 描述         |
| ---------- | ---- | --- | ------------------------- | ---- | ------------ |
| subscriber | 是   | 否  | [NotificationSubscriber](#notificationsubscriber)    | 是   | 通知订阅对象。 |
| info       | 是   | 否  | [NotificationSubscribeInfo](#notificationsubscribeinfo) | 否   | 订阅信息。     |

**示例：**

```js
function onConsumeCallback(err, data) {
	console.info("==========================>onConsumeCallback=======================>");
}
var subscriber = {
    onConsume: onConsumeCallback
};
Notification.subscribe(subscriber).then(() => {
	console.info("==========================>subscribeCallback=======================>");
});
```



## Notification.unsubscribe

unsubscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>): void

取消订阅（callbcak形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称       | 可读 | 可写 | 类型                   | 必填 | 描述                 |
| ---------- | ---- | --- | ---------------------- | ---- | -------------------- |
| subscriber | 是   | 否  | [NotificationSubscriber](#notificationsubscriber) | 是   | 通知订阅对象。         |
| callback   | 是   | 否  | AsyncCallback\<void\>  | 是   | 取消订阅动作回调函数。 |

**示例：**

```js
function unsubscribeCallback(err) {
	console.info("==========================>unsubscribeCallback=======================>");
}
function onConsumeCallback(err, data) {
	console.info("==========================>onConsumeCallback=======================>");
}
var subscriber = {
    onConsume: onConsumeCallback
}
Notification.unsubscribe(subscriber, unsubscribeCallback);
```



## Notification.unsubscribe

unsubscribe(subscriber: NotificationSubscriber): Promise\<void\>

取消订阅（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称       | 可读 | 可写 | 类型                   | 必填 | 描述         |
| ---------- | ---- | --- | ---------------------- | ---- | ------------ |
| subscriber | 是   | 否  | [NotificationSubscriber](#notificationsubscriber) | 是   | 通知订阅对象。 |

**示例：**

```js
function onConsumeCallback(err, data) {
	console.info("==========================>onConsumeCallback=======================>");
}
var subscriber = {
    onConsume: onConsumeCallback
};
Notification.unsubscribe(subscriber).then(() => {
	console.info("==========================>unsubscribeCallback=======================>");
});
```



## Notification.enableNotification

enableNotification(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

设定指定包的通知使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                 |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| bundle   | 是   | 否  | [BundleOption](#bundleoption)          | 是   | 指定包信息。           |
| enable   | 是   | 否  | boolean               | 是   | 使能状态。             |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 设定通知使能回调函数。 |

**示例：**

```js
function enableNotificationCallback(err) {
	console.info("==========================>enableNotificationCallback=======================>");
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

**参数：**

| 名称   | 可读 | 可写 | 类型         | 必填 | 描述       |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | 是   | 否  | [BundleOption](#bundleoption) | 是   | 指定包信息。 |
| enable | 是   | 否  | boolean      | 是   | 使能状态。   |

**示例：**

```js
var bundle = {
    bundle: "bundleName1",
}
Notification.enableNotification(bundle, false).then(() => {
	console.info("==========================>enableNotificationCallback=======================>");
});
```



## Notification.isNotificationEnabled

isNotificationEnabled(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

获取指定包的通知使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                     |
| -------- | ---- | --- | --------------------- | ---- | ------------------------ |
| bundle   | 是   | 否  | [BundleOption](#bundleoption)          | 是   | 指定包信息。               |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 获取通知使能状态回调函数。 |

**示例：**

```js
function isNotificationEnabledCallback(err, data) {
	console.info("==========================>isNotificationEnabledCallback=======================>");
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

**参数：**

| 名称   | 可读 | 可写 | 类型         | 必填 | 描述       |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | 是   | 否  | [BundleOption](#bundleoption) | 是   | 指定包信息。 |

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
	console.info("==========================>isNotificationEnabledCallback=======================>");
});
```



## Notification.isNotificationEnabled

isNotificationEnabled(callback: AsyncCallback\<boolean\>): void

获取通知使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                     |
| -------- | ---- | --- | --------------------- | ---- | ------------------------ |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 获取通知使能状态回调函数。 |

**示例：**

```js
function isNotificationEnabledCallback(err, data) {
	console.info("==========================>isNotificationEnabledCallback=======================>");
}

Notification.isNotificationEnabled(isNotificationEnabledCallback);
```



## Notification.isNotificationEnabled

isNotificationEnabled(): Promise\<boolean\>

获取通知使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称   | 可读 | 可写 | 类型         | 必填 | 描述       |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | 是   | 否  | [BundleOption](#bundleoption) | 是   | 指定包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取通知使能状态的结果。 |

**示例：**

```js
Notification.isNotificationEnabled().then((data) => {
	console.info("==========================>isNotificationEnabledCallback=======================>");
});
```



## Notification.displayBadge

displayBadge(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>): void

设定指定包的角标使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                 |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| bundle   | 是   | 否  | [BundleOption](#bundleoption)          | 是   | 指定包信息。           |
| enable   | 是   | 否  | boolean               | 是   | 使能状态。             |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 设定角标使能回调函数。 |

**示例：**

```js
function displayBadgeCallback(err) {
	console.info("==========================>displayBadgeCallback=======================>");
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

**参数：**

| 名称   | 可读 | 可写 | 类型         | 必填 | 描述       |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | 是   | 否  | [BundleOption](#bundleoption) | 是   | 指定包信息。 |
| enable | 是   | 否  | boolean      | 是   | 使能状态。   |

**示例：**

```js
var bundle = {
    bundle: "bundleName1",
}
Notification.displayBadge(bundle, false).then(() => {
	console.info("==========================>displayBadgeCallback=======================>");
});
```



## Notification.isBadgeDisplayed

isBadgeDisplayed(bundle: BundleOption, callback: AsyncCallback\<boolean\>): void

获取指定包的角标使能状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                     |
| -------- | ---- | --- | --------------------- | ---- | ------------------------ |
| bundle   | 是   | 否  | [BundleOption](#bundleoption)          | 是   | 指定包信息。               |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 获取角标使能状态回调函数。 |

**示例：**

```js
function isBadgeDisplayedCallback(err, data) {
	console.info("==========================>isBadgeDisplayedCallback=======================>");
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

**参数：**

| 名称   | 可读 | 可写 | 类型         | 必填 | 描述       |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | 是   | 否  | [BundleOption](#bundleoption) | 是   | 指定包信息。 |

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
	console.info("==========================>isBadgeDisplayedCallback=======================>");
});
```



## Notification.setSlotByBundle

setSlotByBundle(bundle: BundleOption, slot: NotificationSlot, callback: AsyncCallback\<void\>): void

设定指定包的通知通道状态（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                 |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| bundle   | 是   | 否  | [BundleOption](#bundleoption)          | 是   | 指定包信息。           |
| slot     | 是   | 否  | NotificationSlot      | 是   | 通知通道。             |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 设定通知通道回调函数。 |

**示例：**

```js
function setSlotByBundleCallback(err) {
	console.info("==========================>setSlotByBundleCallback=======================>");
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

设定指定包的角标使能状态（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称   | 可读 | 可写 | 类型         | 必填 | 描述       |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | 是   | 否  | [BundleOption](#bundleoption) | 是   | 指定包信息。 |
| enable | 是   | 否  | boolean      | 是   | 使能状态。   |

**示例：**

```js
var bundle = {
    bundle: "bundleName1",
}
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
Notification.displayBadge(bundle, notificationSlot).then(() => {
	console.info("==========================>setSlotByBundleCallback=======================>");
});
```



## Notification.getSlotsByBundle

getSlotsByBundle(bundle: BundleOption, callback: AsyncCallback<Array\<NotificationSlot\>>): void

获取指定包的通知通道（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                                     | 必填 | 描述                 |
| -------- | ---- | --- | ---------------------------------------- | ---- | -------------------- |
| bundle   | 是   | 否  | [BundleOption](#bundleoption)                             | 是   | 指定包信息。           |
| callback | 是   | 否  | AsyncCallback<Array\<NotificationSlot\>> | 是   | 获取通知通道回调函数。 |

**示例：**

```js
function getSlotsByBundleCallback(err, data) {
	console.info("==========================>getSlotsByBundleCallback=======================>");
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

**参数：**

| 名称   | 可读 | 可写 | 类型         | 必填 | 描述       |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | 是   | 否  | [BundleOption](#bundleoption) | 是   | 指定包信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise<Array\<NotificationSlot\>> | 以Promise形式返回获取指定包的通知通道。 |

**示例：**

```js
var bundle = {
    bundle: "bundleName1",
}
Notification.getSlotsByBundle(bundle).then((data) => {
	console.info("==========================>getSlotsByBundleCallback=======================>");
});
```



## Notification.getSlotNumByBundle

getSlotNumByBundle(bundle: BundleOption, callback: AsyncCallback\<number\>): void

获取指定包的通知通道数（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                      | 必填 | 描述                   |
| -------- | ---- | --- | ------------------------- | ---- | ---------------------- |
| bundle   | 是   | 否  | [BundleOption](#bundleoption)              | 是   | 指定包信息。             |
| callback | 是   | 否  | AsyncCallback\<number\> | 是   | 获取通知通道数回调函数。 |

**示例：**

```js
function getSlotNumByBundle(err, data) {
	console.info("==========================>getSlotNumByBundleCallback=======================>");
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

**参数：**

| 名称   | 可读 | 可写 | 类型         | 必填 | 描述       |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | 是   | 否  | [BundleOption](#bundleoption) | 是   | 指定包信息。 |

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
	console.info("==========================>getSlotNumByBundleCallback=======================>");
});
```



## Notification.remove

remove(bundle: BundleOption, notificationKey: NotificationKey, callback: AsyncCallback\<void\>): void

删除指定通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称            | 可读 | 可写 | 类型                                | 必填 | 描述                 |
| --------------- | ---- | --- | ----------------------------------- | ---- | -------------------- |
| bundle          | 是   | 否  | [BundleOption](#bundleoption)       | 是   | 指定包信息。           |
| notificationKey | 是   | 否  | [NotificationKey](#notificationkey) | 是   | 通知键值。             |
| callback        | 是   | 否  | AsyncCallback\<void\>               | 是   | 删除指定通知回调函数。 |

**示例：**

```js
function removeCallback(err) {
	console.info("==========================>removeCallback=======================>");
}
var bundle = {
    bundle: "bundleName1",
}
var notificationKey = {
    id: 0,
    label: "label",
}
Notification.remove(bundle, notificationKey, removeCallback);
```



## Notification.remove

remove(bundle: BundleOption, notificationKey: NotificationKey): Promise\<void\>

删除指定通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称            | 可读 | 可写 | 类型            | 必填 | 描述       |
| --------------- | ---- | --- | --------------- | ---- | ---------- |
| bundle          | 是   | 否  | [BundleOption](#bundleoption)    | 是   | 指定包信息。 |
| notificationKey | 是   | 否  | [NotificationKey](#notificationkey) | 是   | 通知键值。   |

**示例：**

```js
var bundle = {
    bundle: "bundleName1",
}
var notificationKey = {
    id: 0,
    label: "label",
}
Notification.remove(bundle, notificationKey).then(() => {
	console.info("==========================>removeCallback=======================>");
});
```



## Notification.remove

remove(hashCode: string, callback: AsyncCallback\<void\>): void

删除指定通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                 |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| hashCode | 是   | 否  | string                | 是   | 通知唯一ID。           |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 删除指定通知回调函数。 |

**示例：**

```js
function removeCallback(err) {
	console.info("==========================>removeCallback=======================>");
}

Notification.remove(hashCode, removeCallback);
```



## Notification.remove

remove(hashCode: string): Promise\<void\>

删除指定通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型       | 必填 | 描述       |
| -------- | ---- | --- | ---------- | ---- | ---------- |
| hashCode | 是   | 否  | string | 是   | 通知唯一ID。 |

**示例：**

```js
Notification.remove(hashCode).then(() => {
	console.info("==========================>removeCallback=======================>");
});
```



## Notification.removeAll

removeAll(bundle: BundleOption, callback: AsyncCallback\<void\>): void

删除指定包的所有通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                         |
| -------- | ---- | --- | --------------------- | ---- | ---------------------------- |
| bundle   | 是   | 否  | [BundleOption](#bundleoption)          | 是   | 指定包信息。                   |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 删除指定包的所有通知回调函数。 |

**示例：**

```js
function removeAllCallback(err) {
	console.info("==========================>removeAllCallback=======================>");
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

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                 |
| -------- | ---- | --- | --------------------- | ---- | -------------------- |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 删除所有通知回调函数。 |

**示例：**

```js
function removeAllCallback(err) {
	console.info("==========================>removeAllCallback=======================>");
}

Notification.removeAll(removeAllCallback);
```



## Notification.removeAll

removeAll(bundle?: BundleOption): Promise\<void\>

删除所有通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称   | 可读 | 可写 | 类型         | 必填 | 描述       |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| bundle | 是   | 否  | [BundleOption](#bundleoption) | 否   | 指定包信息。 |

**示例：**

```js
Notification.removeAll().then(() => {
	console.info("==========================>removeAllCallback=======================>");
});
```

## Notification.removeAll<sup>8+</sup>

removeAll(userId: number, callback: AsyncCallback\<void>): void

删除所有通知（callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称   | 可读 | 可写 | 类型         | 必填 | 描述       |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| userId | 是   | 否  | number | 是   | 接收通知用户的Id。 |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 删除所有通知回调函数。 |

**示例：**

```js
function removeAllCallback(err) {
	console.info("==========================>removeAllCallback=======================>");
}

var userId = 1

Notification.removeAll(userId, removeAllCallback);
```

## Notification.removeAll<sup>8+</sup>

removeAll(userId: number): Promise\<void>

删除所有通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称   | 可读 | 可写 | 类型         | 必填 | 描述       |
| ------ | ---- | --- | ------------ | ---- | ---------- |
| userId | 是   | 否  | number | 是   | 接收通知用户的Id。 |

**示例：**

```js
function removeAllCallback(err) {
	console.info("==========================>removeAllCallback=======================>");
}

var userId = 1

Notification.removeAll(userId, removeAllCallback);
```


## Notification.getAllActiveNotifications

getAllActiveNotifications(callback: AsyncCallback<Array\<NotificationRequest\>>): void

获取活动通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                                                         | 必填 | 描述                 |
| -------- | ---- | --- | ------------------------------------------------------------ | ---- | -------------------- |
| callback | 是   | 否  | AsyncCallback<Array\<[NotificationRequest](#notificationrequest)\>> | 是   | 获取活动通知回调函数。 |

**示例：**

```js
function getAllActiveNotificationsCallback(err, data) {
	console.info("==========================>getAllActiveNotificationsCallback=======================>");
}

Notification.getAllActiveNotifications(getAllActiveNotificationsCallback);
```



## Notification.getAllActiveNotifications

getAllActiveNotifications(): Promise\<Array\<[NotificationRequest](#notificationrequest)\>\>

获取活动通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[NotificationRequest](#notificationrequest)\>\> | 以Promise形式返回获取活动通知。 |

**示例：**

```js
Notification.getAllActiveNotifications().then((data) => {
	console.info("==========================>getAllActiveNotificationsCallback=======================>");
});
```



## Notification.getActiveNotificationCount

getActiveNotificationCount(callback: AsyncCallback\<number\>): void

获取当前应用的活动通知数（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                   | 必填 | 描述                   |
| -------- | ---- | --- | ---------------------- | ---- | ---------------------- |
| callback | 是   | 否  | AsyncCallback\<number\> | 是   | 获取活动通知数回调函数。 |

**示例：**

```js
function getActiveNotificationCountCallback(err, data) {
	console.info("==========================>getActiveNotificationCountCallback=======================>");
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
	console.info("==========================>getActiveNotificationCountCallback=======================>");
});
```



## Notification.getActiveNotifications

getActiveNotifications(callback: AsyncCallback<Array\<NotificationRequest\>>): void

获取当前应用的活动通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                                                         | 必填 | 描述                           |
| -------- | ---- | --- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | 是   | 否  | AsyncCallback<Array\<[NotificationRequest](#notificationrequest)\>> | 是   | 获取当前应用的活动通知回调函数。 |

**示例：**

```js
function getActiveNotificationsCallback(err, data) {
	console.info("==========================>getActiveNotificationsCallback=======================>");
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
	console.info("==========================>getActiveNotificationsCallback=======================>");
});
```



## Notification.cancelGroup<sup>8+</sup>

cancelGroup(groupName: string, callback: AsyncCallback\<void\>): void

取消本应用指定组通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称      | 可读 | 可写 | 类型                  | 必填 | 描述                         |
| --------- | ---- | --- | --------------------- | ---- | ---------------------------- |
| groupName | 是   | 否  | string                | 是   | 指定通知组名称。               |
| callback  | 是   | 否  | AsyncCallback\<void\> | 是   | 取消本应用指定组通知回调函数。 |

**示例：**

```js
function cancelGroupCallback(err) {
   console.info("==========================>cancelGroupCallback=======================>");
}

var groupName = "GroupName";

Notification.cancelGroup(groupName, cancelGroupCallback);
```



## Notification.cancelGroup<sup>8+</sup>

cancelGroup(groupName: string): Promise\<void\>

取消本应用指定组通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称      | 可读 | 可写 | 类型   | 必填 | 描述           |
| --------- | ---- | --- | ------ | ---- | -------------- |
| groupName | 是   | 否  | string | 是   | 指定通知组名称。 |

**示例：**

```js
var groupName = "GroupName";
Notification.cancelGroup(groupName).then(() => {
	console.info("==========================>cancelGroupPromise=======================>");
});
```



## Notification.removeGroupByBundle<sup>8+</sup>

removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void\>): void

删除指定应用指定组通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称      | 可读 | 可写 | 类型                  | 必填 | 描述                         |
| --------- | ---- | --- | --------------------- | ---- | ---------------------------- |
| bundle    | 是   | 否  | [BundleOption](#bundleoption)          | 是   | 指定包信息。                   |
| groupName | 是   | 否  | string                | 是   | 指定通知组名称。               |
| callback  | 是   | 否  | AsyncCallback\<void\> | 是   | 删除本应用指定组通知回调函数。 |

**示例：**

```js
function removeGroupByBundleCallback(err) {
   console.info("==========================>removeGroupByBundleCallback=======================>");
}

var bundleOption = {bundle: "Bundle"};
var groupName = "GroupName";

Notification.removeGroupByBundle(bundleOption, groupName, removeGroupByBundleCallback);
```



## Notification.removeGroupByBundle<sup>8+</sup>

removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void\>

删除指定应用指定组通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称      | 可读 | 可写 | 类型         | 必填 | 描述           |
| --------- | ---- | --- | ------------ | ---- | -------------- |
| bundle    | 是   | 否  | [BundleOption](#bundleoption) | 是   | 指定包信息。     |
| groupName | 是   | 否  | string       | 是   | 指定通知组名称。 |

**示例：**

```js
var bundleOption = {bundle: "Bundle"};
var groupName = "GroupName";
Notification.removeGroupByBundle(bundleOption, groupName).then(() => {
	console.info("==========================>removeGroupByBundlePromise=======================>");
});
```



## Notification.setDoNotDisturbDate<sup>8+</sup>

setDoNotDisturbDate(date: DoNotDisturbDate, callback: AsyncCallback\<void\>): void

设置免打扰时间（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                   |
| -------- | ---- | --- | --------------------- | ---- | ---------------------- |
| date     | 是   | 否  | DoNotDisturbDate      | 是   | 免打扰时间选项。         |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 设置免打扰时间回调函数。 |

**示例：**

```js
function setDoNotDisturbDateCallback(err) {
   console.info("==========================>setDoNotDisturbDateCallback=======================>");
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

**参数：**

| 名称 | 可读 | 可写 | 类型             | 必填 | 描述           |
| ---- | ---- | --- | ---------------- | ---- | -------------- |
| date | 是   | 否  | DoNotDisturbDate | 是   | 免打扰时间选项。 |

**示例：**

```js
var doNotDisturbDate = {
    type: Notification.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
}
Notification.setDoNotDisturbDate(doNotDisturbDate).then(() => {
	console.info("==========================>setDoNotDisturbDatePromise=======================>");
});
```


## Notification.setDoNotDisturbDate<sup>8+</sup>

setDoNotDisturbDate(date: DoNotDisturbDate, userId: number, callback: AsyncCallback\<void\>): void

指定用户设置免打扰时间（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                   |
| -------- | ---- | --- | --------------------- | ---- | ---------------------- |
| date     | 是   | 否  | DoNotDisturbDate      | 是   | 免打扰时间选项。         |
| userId   | 是   | 否  | number                | 是   | 设置免打扰事件的用户ID。 |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 设置免打扰时间回调函数。 |

**示例：**

```js
function setDoNotDisturbDateCallback(err) {
   console.info("==========================>setDoNotDisturbDateCallback=======================>");
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

**参数：**

| 名称   | 可读 | 可写 | 类型             | 必填 | 描述           |
| ------ | ---- | --- | ---------------- | ---- | -------------- |
| date   | 是   | 否  | DoNotDisturbDate | 是   | 免打扰时间选项。 |
| userId | 是   | 否  | number           | 是   | 设置免打扰事件的用户ID。 |

**示例：**

```js
var doNotDisturbDate = {
    type: Notification.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
}

var userId = 1

Notification.setDoNotDisturbDate(doNotDisturbDate, userId).then(() => {
	console.info("==========================>setDoNotDisturbDatePromise=======================>");
});
```


## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate\>): void

查询免打扰时间接口（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                              | 必填 | 描述                   |
| -------- | ---- | --- | --------------------------------- | ---- | ---------------------- |
| callback | 是   | 否  | AsyncCallback\<DoNotDisturbDate\> | 是   | 查询免打扰时间回调函数。 |

**示例：**

```js
function getDoNotDisturbDateCallback(err,data) {
   console.info("==========================>getDoNotDisturbDateCallback=======================>");
}

Notification.getDoNotDisturbDate(getDoNotDisturbDateCallback);
```



## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(): Promise\<DoNotDisturbDate\>

查询免打扰时间接口（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<DoNotDisturbDate\> | 以Promise形式返回获取查询免打扰时间接口。 |

**示例：**

```js
Notification.getDoNotDisturbDate().then((data) => {
	console.info("==========================>getDoNotDisturbDatePromise=======================>");
});
```


## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(userId: number, callback: AsyncCallback\<DoNotDisturbDate\>): void

指定用户查询免打扰时间接口（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                              | 必填 | 描述                   |
| -------- | ---- | --- | --------------------------------- | ---- | ---------------------- |
| callback | 是   | 否  | AsyncCallback\<DoNotDisturbDate\> | 是   | 查询免打扰时间回调函数。 |
| userId   | 是   | 否  | number                            | 是   | 设置免打扰事件的用户ID。 |

**示例：**

```js
function getDoNotDisturbDateCallback(err,data) {
   console.info("==========================>getDoNotDisturbDateCallback=======================>");
}

var userId = 1

Notification.getDoNotDisturbDate(userId, getDoNotDisturbDateCallback);
```



## Notification.getDoNotDisturbDate<sup>8+</sup>

getDoNotDisturbDate(userId: number): Promise\<DoNotDisturbDate\>

指定用户查询免打扰时间接口（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                              | 必填 | 描述                   |
| -------- | ---- | --- | --------------------------------- | ---- | ---------------------- |
| userId   | 是   | 否  | number                            | 是   | 设置免打扰事件的用户ID。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<DoNotDisturbDate\> | 以Promise形式返回获取查询免打扰时间接口。 |

**示例：**

```js
var userId = 1

Notification.getDoNotDisturbDate(userId).then((data) => {
	console.info("==========================>getDoNotDisturbDatePromise=======================>");
});
```


## Notification.supportDoNotDisturbMode<sup>8+</sup>

supportDoNotDisturbMode(callback: AsyncCallback\<boolean\>): void

查询是否支持勿扰模式功能（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 名称     | 可读 | 可写 | 类型                     | 必填 | 描述                             |
| -------- | ---- | --- | ------------------------ | ---- | -------------------------------- |
| callback | 是   | 否  | AsyncCallback\<boolean\> | 是   | 查询是否支持勿扰模式功能回调函数。 |

**示例：**

```js
function supportDoNotDisturbModeCallback(err,data) {
   console.info("==========================>supportDoNotDisturbModeCallback=======================>");
}

Notification.supportDoNotDisturbMode(supportDoNotDisturbModeCallback);
```



## Notification.supportDoNotDisturbMode<sup>8+</sup>

supportDoNotDisturbMode(): Promise\<boolean\>

查询是否支持勿扰模式功能（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取是否支持勿扰模式功能的结果。 |

**示例：**

```js
Notification.supportDoNotDisturbMode().then((data) => {
	console.info("==========================>supportDoNotDisturbModePromise=======================>");
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
    console.info("isSupportTemplateCallback");
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
    console.info("isSupportTemplateCallback");
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
function requestEnabledNotificationCallback() {
    console.log('------------- requestEnabledNotification --------------');
};

Notification.requestEnabledNotification(requestEnabledNotificationCallback);
```



## Notification.requestEnableNotification<sup>8+</sup>

requestEnableNotification(): Promise\<void\>

应用请求通知使能（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**示例：**

```javascript
Notification.requestEnableNotification()
    .then(() => {
        console.info("requestEnableNotification ");
	});
```


## Notification.enableDistributed<sup>8+</sup>

enableDistributed(enable: boolean, callback: AsyncCallback\<void\>): void

设置设备是否支持分布式通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | 是   | 是否支持。<br/>true 支持。<br/>false 不支持。|
| callback | AsyncCallback\<void\> | 是   | 设置设备是否支持分布式通知的回调函数。 |

**示例：**

```javascript
function enabledNotificationCallback() {
    console.log('----------- enableDistributed ------------');
};

var enable = true

Notification.enableDistributed(enable, enabledNotificationCallback);
```



## Notification.enableDistributed<sup>8+</sup>

enableDistributed(enable: boolean): Promise\<void>

设置设备是否支持分布式通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| enable   | boolean                  | 是   | 是否支持。<br/>true 支持。<br/>false 不支持。|

**示例：**

```javascript
var enable = true

Notification.enableDistributed(enable)
    .then(() => {
        console.log('-------- enableDistributed ----------');
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
function isDistributedEnabledCallback() {
    console.log('----------- isDistributedEnabled ------------');
};

Notification.enableDistributed(isDistributedEnabledCallback);
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
        console.log('-------- isDistributedEnabled ----------');
    });
```


## Notification.enableDistributedByBundle<sup>8+</sup>

enableDistributedByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void>): void

根据应用的包设置应用程序是否支持分布式通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | BundleOption             | 是   | 应用的包。                     |
| enable   | boolean                  | 是   | 是否支持。                       |
| callback | AsyncCallback\<void\> | 是   | 应用程序是否支持分布式通知的回调函数。 |

**示例：**

```javascript
function enableDistributedByBundleCallback() {
    console.log('----------- enableDistributedByBundle ------------');
};

var bundle = {
    bundle: "bundleName1",
}

var enable = true

Notification.enableDistributedByBundle(bundle, enable, enableDistributedByBundleCallback);
```



## Notification.enableDistributedByBundle<sup>8+</sup>

根据bundleenableDistributedByBundle(bundle: BundleOption, enable: boolean): Promise<void>

根据应用的包设置应用程序是否支持分布式通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | BundleOption             | 是   | 应用的包。                |
| enable   | boolean                  | 是   | 是否支持。                  |

**示例：**

```javascript
var bundle = {
    bundle: "bundleName1",
}

var enable = true

Notification.enableDistributedByBundle(bundle, enable)
    .then(() => {
        console.log('-------- enableDistributedByBundle ----------');
    });
```

## Notification.isDistributedEnabledByBundle<sup>8+</sup>

isDistributedEnabledByBundle(bundle: BundleOption, callback: AsyncCallback\<boolean>): void

根据应用的包获取应用程序是否支持分布式通知（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | BundleOption             | 是   | 应用的包。                     |
| callback | AsyncCallback\<boolean\> | 是   | 应用程序是否支持分布式通知的回调函数。 |

**示例：**

```javascript
function isDistributedEnabledByBundleCallback(data) {
    console.log('----------- isDistributedEnabledByBundle ------------', data);
};

var bundle = {
    bundle: "bundleName1",
}

Notification.enableDistributedByBundle(bundle, isDistributedEnabledByBundleCallback);
```



## Notification.isDistributedEnabledByBundle<sup>8+</sup>

isDistributedEnabledByBundle(bundle: BundleOption): Promise\<boolean>

根据应用的包获取应用程序是否支持分布式通知（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| bundle   | BundleOption             | 是   | 应用的包。                |

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
        console.log('-------- isDistributedEnabledByBundle ----------', data);
    });
```


## Notification.getDeviceRemindType<sup>8+</sup>

getDeviceRemindType(callback: AsyncCallback\<DeviceRemindType\>): void

获取通知的提醒方式（Callback形式）。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                               | 必填 | 说明                       |
| -------- | --------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback\<DeviceRemindType\> | 是   | 获取通知的提醒方式的回调函数。 |

**示例：**

```javascript
function getDeviceRemindTypeCallback(data) {
    console.log('----------- getDeviceRemindType ------------', data);
};

Notification.getDeviceRemindType(getDeviceRemindTypeCallback);
```



## Notification.getDeviceRemindType<sup>8+</sup>

getDeviceRemindType(): Promise\<DeviceRemindType\>

获取通知的提醒方式（Promise形式）。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型               | 说明            |
| ------------------ | --------------- |
| Promise\<DeviceRemindType\> | Promise方式返回通知的提醒方式的结果。 |

**示例：**

```javascript
Notification.getDeviceRemindType()
    .then((data) => {
        console.log('-------- getDeviceRemindType ----------', data);
    });
```


## DoNotDisturbDate<sup>8+</sup>

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称  | 可读 | 可写 | 类型                                  | 描述                     |
| ----- | ---- | --- | ------------------------------------- | ------------------------ |
| type  | 是  | 否  | [DoNotDisturbType](#donotdisturbtype) | 指定免打扰设置的时间类型。 |
| begin | 是  | 否  | Date                                  | 指定免打扰设置的起点时间。 |
| end   | 是  | 否  | Date                                  | 指定免打扰设置的终点时间。 |



## DoNotDisturbType<sup>8+</sup>

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification


| 名称         | 值               | 说明                                       |
| ------------ | ---------------- | ------------------------------------------ |
| TYPE_NONE    | DoNotDisturbType | 非通知勿扰类型。                           |
| TYPE_ONCE    | DoNotDisturbType | 以设置时间段(只看小时和分钟)一次执行勿扰。 |
| TYPE_DAILY   | DoNotDisturbType | 以设置时间段(只看小时和分钟)每天执行勿扰。 |
| TYPE_CLEARLY | DoNotDisturbType | 以设置时间段(明确年月日时分)执行勿扰。     |


## ContentType

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                              | 值          | 说明               |
| --------------------------------- | ----------- | ------------------ |
| NOTIFICATION_CONTENT_BASIC_TEXT   | ContentType | 普通类型通知。     |
| NOTIFICATION_CONTENT_LONG_TEXT    | ContentType | 长文本类型通知。   |
| NOTIFICATION_CONTENT_PICTURE      | ContentType | 图片类型通知。     |
| NOTIFICATION_CONTENT_CONVERSATION | ContentType | 社交类型通知。     |
| NOTIFICATION_CONTENT_MULTILINE    | ContentType | 多行文本类型通知。 |

## SlotLevel

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                              | 值          | 说明               |
| --------------------------------- | ----------- | ------------------ |
| LEVEL_NONE                        | 0           | 表示关闭通知功能。     |
| LEVEL_MIN                         | 1           | 启用通知功能，但通知不启用。   |
| LEVEL_LOW                         | 2           | 通知和通知功能都启用。 |
| LEVEL_DEFAULT                     | 3           | 通知和通知功能都启用。   |
| LEVEL_HIGH                        | 4           | 通知和通知功能都启用。   |


## BundleOption

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称   | 可读 | 可写 | 类型   | 必填 | 描述   |
| ------ | ---- | --- | ------ | ---- | ------ |
| bundle | 是  | 是  | string | 是   | 包名。   |
| uid    | 是  | 是  | number | 否   | 用户id。 |



## NotificationKey

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称  | 可读 | 可写 | 类型   | 必填 | 描述     |
| ----- | ---- | --- | ------ | ---- | -------- |
| id    | 是  | 是  | number | 是   | 通知ID。   |
| label | 是  | 是  | string | 否   | 通知标签。 |


## SlotType

**系统能力**：以下各项对应的系统能力均为SystemCapability.Notification.Notification

| 名称                 | 值       | 说明       |
| -------------------- | -------- | ---------- |
| UNKNOWN_TYPE         | SlotType | 未知类型。 |
| SOCIAL_COMMUNICATION | SlotType | 社交类型。 |
| SERVICE_INFORMATION  | SlotType | 服务类型。 |
| CONTENT_INFORMATION  | SlotType | 内容类型。 |
| OTHER_TYPES          | SlotType | 其他类型。 |