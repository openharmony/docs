# Notification模块

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

cancel(id：number, label？：string): Promise\<void\>

取消与指定id相匹配的已发布通知,label可以指定也可以不指定（Promise形式)。

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

取消与指定id相匹配的已发布通知（callback形式)。

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

取消所有已发布的通知（callback形式)。

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

取消所有已发布的通知（Promise形式)。

**系统能力**：SystemCapability.Notification.Notification

**示例：**

```js
Notification.cancelAll().then(() => {
	console.info("==========================>cancelAllCallback=======================>");
});
```



## Notification.addSlot

addSlot(slot: NotificationSlot, callback: AsyncCallback\<void\>): void

创建通知通道（callback形式)。

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

创建通知通道（Promise形式)。

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

创建通知通道（callback形式)。

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

创建通知通道（Promise形式)。

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

创建多个通知通道（callback形式)。

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

创建多个通知通道（Promise形式)。

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

获取一个通知通道（callback形式)。

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

getSlot(slotType): Promise\<NotificationSlot\>

获取一个通知通道（Promise形式)。

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

获取此应用程序的所有通知通道（callback形式)。

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

getSlots()

获取此应用程序的所有通知通道（Promise形式)。

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

根据通知通道类型删除创建的通知通道（callback形式)。

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

根据通知通道类型删除创建的通知通道（Promise形式)。

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

删除所有通知通道（callback形式)。

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

删除所有通知通道(Promise形式)。

**系统能力**：SystemCapability.Notification.Notification

**示例：**

```js
Notification.removeAllSlots().then(() => {
	console.info("==========================>removeAllCallBack=======================>");
});
```



## Notification.subscribe

subscribe(subscriber: NotificationSubscriber, info: NotificationSubscribeInfo, callback: AsyncCallback\<void\>): void

订阅通知并指定订阅信息（callback形式)。

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

subscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>); void

订阅通知并指定订阅信息（callback形式)。

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

订阅通知并指定订阅信息（Promise形式)。

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

取消订阅（callbcak形式)。

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

取消订阅（Promise形式)。

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

设定指定包的通知使能状态（Callback形式)。

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

设定指定包的通知使能状态（Promise形式)。

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

获取指定包的通知使能状态（Callback形式)。

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

获取指定包的通知使能状态（Promise形式)。

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

获取通知使能状态（Callback形式)。

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

获取通知使能状态（Promise形式)。

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

设定指定包的角标使能状态（Callback形式)。

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

设定指定包的角标使能状态（Promise形式)。

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

获取指定包的角标使能状态（Callback形式)。

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

获取指定包的角标使能状态（Promise形式)。

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

设定指定包的通知通道状态（Callback形式)。

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

设定指定包的角标使能状态（Promise形式)。

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

获取指定包的通知通道（Callback形式)。

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

获取指定包的通知通道（Promise形式)。

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

获取指定包的通知通道数（Callback形式)。

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

获取指定包的通知通道数（Promise形式)。

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

删除指定通知（Callback形式)。

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

删除指定通知（Promise形式)。

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

删除指定通知（Callback形式)。

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

删除指定通知（Promise形式)。

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

删除指定包的所有通知（Callback形式)。

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

删除所有通知（Callback形式)。

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

删除所有通知（Promise形式)。

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



## Notification.getAllActiveNotifications

getAllActiveNotifications(callback: AsyncCallback<Array\<NotificationRequest\>>): void

获取活动通知（Callback形式)。

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

获取活动通知（Promise形式)。

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

获取当前应用的活动通知数（Callback形式)。

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

获取当前应用的活动通知数（Promise形式)。

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

获取当前应用的活动通知（Callback形式)。

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

获取当前应用的活动通知（Promise形式)。

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



## Notification.cancelGroup

cancelGroup(groupName: string, callback: AsyncCallback\<void\>): void

取消本应用指定组通知（Callback形式)。

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



## Notification.cancelGroup

cancelGroup(groupName: string): Promise\<void\>

取消本应用指定组通知（Promise形式)。

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



## Notification.removeGroupByBundle

removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void\>): void

删除指定应用指定组通知（Callback形式)。

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



## Notification.removeGroupByBundle

removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void\>

删除指定应用指定组通知（Promise形式)。

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



## Notification.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate, callback: AsyncCallback\<void\>): void

设置免打扰时间（Callback形式)。

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



## Notification.setDoNotDisturbDate

setDoNotDisturbDate(date: DoNotDisturbDate): Promise\<void\>

设置免打扰时间接口（Promise形式)。

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



## Notification.getDoNotDisturbDate

getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate\>): void

查询免打扰时间接口（Callback形式)。

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



## Notification.getDoNotDisturbDate

getDoNotDisturbDate(): Promise\<DoNotDisturbDate\>

查询免打扰时间接口（Promise形式)。

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



## Notification.supportDoNotDisturbMode

supportDoNotDisturbMode(callback: AsyncCallback\<boolean\>): void

查询是否支持勿扰模式功能（Callback形式)。

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



## Notification.supportDoNotDisturbMode

supportDoNotDisturbMode(): Promise\<boolean\>

查询是否支持勿扰模式功能（Promise形式)。

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



## Notification.isSupportTemplate

isSupportTemplate(templateName: string, callback: AsyncCallback\<boolean\>): void

查询模板是否存在。

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



## Notification.isSupportTemplate

isSupportTemplate(templateName: string): Promise\<boolean\>

查询模板是否存在。

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



## Notification.requestEnabledNotification

requestEnabledNotification(callback: AsyncCallback\<boolean\>): void

应用请求通知使能。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<boolean\> | 是   | 查询模板是否存在的回调函数。 |

**示例：**

```javascript
function requestEnabledNotificationCallback(err) {
    if (err.code) {
        console.info("isNotificationEnabledSelf failed " + JSON.stringify(err));
    } else {
        console.info("isNotificationEnabledSelf");
    }
};

Notification.requestEnabledNotification(requestEnabledNotificationCallback);
```



## Notification.requestEnabledNotification

requestEnabledNotification(callback: AsyncCallback\<void\>): void

应用请求通知使能。

**系统能力**：SystemCapability.Notification.Notification

**返回值：**

| 类型               | 说明            |
| ------------------ | --------------- |
| Promise\<boolean\> | Promise方式返回应用请求通知使能。 |

**示例：**

```javascript
Notification.isNotificationEnabledSelf()
    .then(() => {
        console.info("requestEnabledNotification ");
	})
	.catch((err) => {
        console.info("requestEnabledNotification failed " + JSON.stringify(err));
	});
```


## Notification.show

show(options?: ShowNotificationOptions): void

展示通知事件。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名   | 类型                     | 必填 | 说明              |
| ------- | ------------------------ | ---- | ---------------- |
| options | ShowNotificationOptions  | 否   | 需要展示通知的参数 |

**示例：**

```javascript
var options = {
  contentTitle: 'contentTitle',
  contentText: 'contentText',
  clickAction: {
    bundleName: 'bundleName',
    abilityName: 'abilityName',
    uri: 'uri',
  }
};

Notification.show(options);
```



## NotificationSubscriber

| 名称                                                         | 可读 | 可写 | 类型     | 必填 | 描述                       |
| ------------------------------------------------------------ | ---- | --- | -------- | ---- | -------------------------- |
| onConsume?:(data: [SubscribeCallbackData](#subscribecallbackdata)) | 是 | 否 | function | 否   | 接收通知回调函数。<br/>**系统能力**：SystemCapability.Notification.Notification           |
| onCancel?:(data: [SubscribeCallbackData](#subscribecallbackdata)) | 是 | 否 | function | 否   | 删除通知回调函数。<br/>**系统能力**：SystemCapability.Notification.Notification           |
| onUpdate?:(data: [NotificationSortingMap](#notificationsortingmap)) | 是 | 否 | function | 否   | 更新通知排序回调函数。<br/>**系统能力**：SystemCapability.Notification.Notification       |
| onConnect?:()                                                | 是 | 否 | function | 否   | 注册订阅回调函数。<br/>**系统能力**：SystemCapability.Notification.Notification           |
| onDisconnect?:()                                             | 是 | 否 | function | 否   | 取消订阅回调函数。<br/>**系统能力**：SystemCapability.Notification.Notification           |
| onDestroy?:()                                                | 是 | 否 | function | 否   | 服务失联回调函数。<br/>**系统能力**：SystemCapability.Notification.Notification           |
| onDoNotDisturbDateChange?:(mode: Notification.[DoNotDisturbDate](#donotdisturbdate)) | 是 | 否 | function | 否   | 免打扰时间选项变更回调函数。<br/>**系统能力**：SystemCapability.Notification.Notification |

### onEnabledNotificationChanged

onEnabledNotificationChanged?:(callbackData: [EnabledNotificationCallbackData](#enablednotificationcallbackdata))

监听应用通知使能变化。

**系统能力**：SystemCapability.Notification.Notification

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------------ | ------------------------ | ---- | -------------------------- |
| callback | AsyncCallback\<[EnabledNotificationCallbackData](#enablednotificationcallbackdata)\> | 是 | 回调返回监听到的应用信息。 |

**示例：**

```javascript
function subscribeCallback(err) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribeCallback");
    }
};

function onEnabledNotificationChangedCallback(err, callbackData) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("bundle: ", callbackData.bundle);
        console.info("uid: ", callbackData.uid);
        console.info("enable: ", callbackData.enable);
    }
};

var subscriber = {
    onEnabledNotificationChanged: onEnabledNotificationChangedCallback
};

Notification.subscribe(subscriber, subscribeCallback);
```



## SubscribeCallbackData

| 名称            | 可读 | 可写 | 类型                                              | 必填 | 描述     |
| --------------- | ---- | --- | ------------------------------------------------- | ---- | -------- |
| request         | 是  | 否  | [NotificationRequest](#notificationrequest)       | 是   | 通知内容。<br/>**系统能力**：SystemCapability.Notification.Notification |
| sortingMap      | 是  | 否  | [NotificationSortingMap](#notificationsortingmap) | 否   | 排序信息。<br/>**系统能力**：SystemCapability.Notification.Notification |
| reason          | 是  | 否  | number                                            | 否   | 删除原因。<br/>**系统能力**：SystemCapability.Notification.Notification |
| sound           | 是  | 否  | string                                            | 否   | 通知声音。<br/>**系统能力**：SystemCapability.Notification.Notification |
| vibrationValues | 是  | 否  | Array\<number\>                                   | 否   | 通知震动。<br/>**系统能力**：SystemCapability.Notification.Notification |

。<br/>**系统能力**：SystemCapability.Notification.Notification

## NotificationSortingMap

| 名称           | 可读 | 可写 | 类型                                                         | 必填 | 描述             |
| -------------- | ---- | --- | ------------------------------------------------------------ | ---- | ---------------- |
| sortings       | 是  | 否  | {[key: string]: [NotificationSorting](#notificationsorting)} | 是   | 通知排序信息数组。<br/>**系统能力**：SystemCapability.Notification.Notification |
| sortedHashCode | 是  | 否  | Array\<string\>                                              | 是   | 通知唯一标识数组。<br/>**系统能力**：SystemCapability.Notification.Notification |



## NotificationSorting

| 名称     | 可读 | 可写 | 类型                                  | 必填 | 描述         |
| -------- | ---- | --- | ------------------------------------- | ---- | ------------ |
| slot     | 是  | 否  | [NotificationSlot](#notificationslot) | 是   | 通知通道内容。<br/>**系统能力**：SystemCapability.Notification.Notification |
| hashCode | 是  | 否  | string                                | 是   | 通知唯一标识。<br/>**系统能力**：SystemCapability.Notification.Notification |
| ranking  | 是  | 否  | number                                | 是   | 通知排序序号。<br/>**系统能力**：SystemCapability.Notification.Notification |



## DoNotDisturbDate

| 名称  | 可读 | 可写 | 类型                                  | 描述                     |
| ----- | ---- | --- | ------------------------------------- | ------------------------ |
| type  | 是  | 否  | [DoNotDisturbType](#donotdisturbtype) | 指定免打扰设置的时间类型。<br/>**系统能力**：SystemCapability.Notification.Notification |
| begin | 是  | 否  | Date                                  | 指定免打扰设置的起点时间。<br/>**系统能力**：SystemCapability.Notification.Notification |
| end   | 是  | 否  | Date                                  | 指定免打扰设置的终点时间。<br/>**系统能力**：SystemCapability.Notification.Notification |



## DoNotDisturbType


| 名称         | 值               | 说明                                     |
| ------------ | ---------------- | ---------------------------------------- |
| TYPE_NONE    | DoNotDisturbType | 非通知勿扰类型。<br/>**系统能力**：SystemCapability.Notification.Notification                           |
| TYPE_ONCE    | DoNotDisturbType | 以设置时间段(只看小时和分钟)一次执行勿扰。<br/>**系统能力**：SystemCapability.Notification.Notification |
| TYPE_DAILY   | DoNotDisturbType | 以设置时间段(只看小时和分钟)每天执行勿扰。<br/>**系统能力**：SystemCapability.Notification.Notification |
| TYPE_CLEARLY | DoNotDisturbType | 以设置时间段(明确年月日时分)执行勿扰。<br/>**系统能力**：SystemCapability.Notification.Notification     |



## EnabledNotificationCallbackData

| 名称   | 可读 | 可写 | 类型    | 必填 | 描述             |
| ------ | ---- | --- | ------- | ---- | ---------------- |
| bundle | 是  | 否  | string  | 否   | 应用的包名。<br/>**系统能力**：SystemCapability.Notification.Notification       |
| uid    | 是  | 否  | number  | 否   | 应用的uid。<br/>**系统能力**：SystemCapability.Notification.Notification        |
| enable | 是  | 否  | boolean | 否   | 应用通知使能状态。<br/>**系统能力**：SystemCapability.Notification.Notification |



## NotificationRequest

| 名称                  | 可读 | 可写 | 类型                                          | 必填 | 描述                       |
| --------------------- | ---- | --- | --------------------------------------------- | ---- | -------------------------- |
| content               | 是  | 是  | [NotificationContent](#notificationcontent)   | 是   | 通知内容。<br/>**系统能力**：SystemCapability.Notification.Notification                   |
| id                    | 是  | 是  | number                                        | 否   | 通知ID。<br/>**系统能力**：SystemCapability.Notification.Notification                     |
| slotType              | 是  | 是  | [SlotType](#slottype)                                      | 否   | 通道类型。<br/>**系统能力**：SystemCapability.Notification.Notification                   |
| isOngoing             | 是  | 是  | boolean                                       | 否   | 是否进行时通知。<br/>**系统能力**：SystemCapability.Notification.Notification             |
| isUnremovable         | 是  | 是  | boolean                                       | 否   | 是否可移除。<br/>**系统能力**：SystemCapability.Notification.Notification                 |
| deliveryTime          | 是  | 是  | number                                        | 否   | 通知发送时间。<br/>**系统能力**：SystemCapability.Notification.Notification               |
| tapDismissed          | 是  | 是  | boolean                                       | 否   | 通知是否自动清除。<br/>**系统能力**：SystemCapability.Notification.Notification           |
| autoDeletedTime       | 是  | 是  | number                                        | 否   | 自动清除的时间。<br/>**系统能力**：SystemCapability.Notification.Notification             |
| wantAgent             | 是  | 是  | WantAgent                                     | 否   | 点击跳转的WantAgent。<br/>**系统能力**：SystemCapability.Notification.Notification        |
| extraInfo             | 是  | 是  | {[key: string]: any}                          | 否   | 扩展参数。<br/>**系统能力**：SystemCapability.Notification.Notification                   |
| color                 | 是  | 是  | number                                        | 否   | 通知背景颜色。<br/>**系统能力**：SystemCapability.Notification.Notification               |
| colorEnabled          | 是  | 是  | boolean                                       | 否   | 通知背景颜色是否使能。<br/>**系统能力**：SystemCapability.Notification.Notification       |
| isAlertOnce           | 是  | 是  | boolean                                       | 否   | 设置是否仅有一次此通知警报。<br/>**系统能力**：SystemCapability.Notification.Notification |
| isStopwatch           | 是  | 是  | boolean                                       | 否   | 是否显示已用时间。<br/>**系统能力**：SystemCapability.Notification.Notification           |
| isCountDown           | 是  | 是  | boolean                                       | 否   | 是否显示倒计时时间。<br/>**系统能力**：SystemCapability.Notification.Notification         |
| isFloatingIcon        | 是  | 是  | boolean                                       | 否   | 是否显示状态栏图标。<br/>**系统能力**：SystemCapability.Notification.Notification         |
| label                 | 是  | 是  | string                                        | 否   | 通知标签。<br/>**系统能力**：SystemCapability.Notification.Notification                   |
| badgeIconStyle        | 是  | 是  | number                                        | 否   | 通知角标类型。<br/>**系统能力**：SystemCapability.Notification.Notification               |
| showDeliveryTime      | 是  | 是  | boolean                                       | 否   | 是否显示分发时间。<br/>**系统能力**：SystemCapability.Notification.Notification           |
| actionButtons         | 是  | 是  | Array\<[NotificationActionButton](#notificationactionbutton)\>             | 否   | 通知按钮，最多两个按钮。<br/>**系统能力**：SystemCapability.Notification.Notification     |
| smallIcon             | 是  | 是  | PixelMap                                      | 否   | 通知小图标。<br/>**系统能力**：SystemCapability.Notification.Notification                 |
| largeIcon             | 是  | 是  | PixelMap                                      | 否   | 通知大图标。<br/>**系统能力**：SystemCapability.Notification.Notification                 |
| creatorBundleName     | 是  | 否  | string                                        | 否   | 创建通知的包名。<br/>**系统能力**：SystemCapability.Notification.Notification             |
| creatorUid            | 是  | 否  | number                                        | 否   | 创建通知的UID。<br/>**系统能力**：SystemCapability.Notification.Notification              |
| creatorPid            | 是  | 否  | number                                        | 否   | 创建通知的PID。<br/>**系统能力**：SystemCapability.Notification.Notification              |
| hashCode              | 是  | 否  | string                                        | 否   | 通知唯一标识。<br/>**系统能力**：SystemCapability.Notification.Notification               |
| classification        | 是  | 是  | string                                        | 否   | 通知分类。<br/>**系统能力**：SystemCapability.Notification.Notification                   |
| groupName             | 是  | 是  | string                                        | 否   | 组通知名称。<br/>**系统能力**：SystemCapability.Notification.Notification                 |
| template<sup>8+</sup> | 是  | 是  | [NotificationTemplate](#notificationtemplate) | 否   | 通知模板。<br/>**系统能力**：SystemCapability.Notification.Notification                   |



## NotificationSlot

| 名称                 | 可读 | 可写 | 类型                  | 必填 | 描述                                       |
| -------------------- | ---- | --- | --------------------- | ---- | ------------------------------------------ |
| type                 | 是  | 是  | [SlotType](#slottype) | 是   | 通道类型。<br/>**系统能力**：SystemCapability.Notification.Notification                                   |
| level                | 是  | 是  | number                | 否   | 通知级别，不设置则根据通知渠道类型有默认值。<br/>**系统能力**：SystemCapability.Notification.Notification |
| desc                 | 是  | 是  | string                | 否   | 通知渠道描述信息。<br/>**系统能力**：SystemCapability.Notification.Notification                           |
| badgeFlag            | 是  | 是  | boolean               | 否   | 是否显示角标。<br/>**系统能力**：SystemCapability.Notification.Notification                               |
| bypassDnd            | 是  | 是  | boolean               | 否   | 置是否在系统中绕过免打扰模式。<br/>**系统能力**：SystemCapability.Notification.Notification               |
| lockscreenVisibility | 是  | 是  | boolean               | 否   | 在锁定屏幕上显示通知的模式。<br/>**系统能力**：SystemCapability.Notification.Notification                 |
| vibrationEnabled     | 是  | 是  | boolean               | 否   | 是否可振动。<br/>**系统能力**：SystemCapability.Notification.Notification                                 |
| sound                | 是  | 是  | string                | 否   | 通知提示音。<br/>**系统能力**：SystemCapability.Notification.Notification                                 |
| lightEnabled         | 是  | 是  | boolean               | 否   | 是否闪灯。<br/>**系统能力**：SystemCapability.Notification.Notification                                   |
| lightColor           | 是  | 是  | number                | 否   | 通知灯颜色。<br/>**系统能力**：SystemCapability.Notification.Notification                                 |
| vibrationValues      | 是  | 是  | Array\<number\>       | 否   | 通知振动样式。<br/>**系统能力**：SystemCapability.Notification.Notification                               |


## NotificationContent

| 名称        | 可读 | 可写 | 类型                                                         | 必填 | 描述               |
| ----------- | ---- | --- | ------------------------------------------------------------ | ---- | ------------------ |
| contentType | 是  | 是  | [ContentType](#contenttype)                                  | 是   | 通知内容类型。<br/>**系统能力**：SystemCapability.Notification.Notification       |
| normal      | 是  | 是  | [NotificationBasicContent](#notificationbasiccontent)        | 否   | 基本类型通知内容。<br/>**系统能力**：SystemCapability.Notification.Notification   |
| longText    | 是  | 是  | [NotificationLongTextContent](#notificationlongtextcontent)  | 否   | 长文本类型通知内容。<br/>**系统能力**：SystemCapability.Notification.Notification |
| multiLine   | 是  | 是  | [NotificationMultiLineContent](#notificationmultilinecontent) | 否   | 多行类型通知内容。<br/>**系统能力**：SystemCapability.Notification.Notification   |
| picture     | 是  | 是  | [NotificationPictureContent](#notificationpicturecontent)    | 否   | 图片类型通知内容。<br/>**系统能力**：SystemCapability.Notification.Notification   |



## ContentType

| 名称                              | 值          | 说明             |
| --------------------------------- | ----------- | ---------------- |
| NOTIFICATION_CONTENT_BASIC_TEXT   | ContentType | 普通类型通知。<br/>**系统能力**：SystemCapability.Notification.Notification     |
| NOTIFICATION_CONTENT_LONG_TEXT    | ContentType | 长文本类型通知。<br/>**系统能力**：SystemCapability.Notification.Notification   |
| NOTIFICATION_CONTENT_PICTURE      | ContentType | 图片类型通知。<br/>**系统能力**：SystemCapability.Notification.Notification     |
| NOTIFICATION_CONTENT_CONVERSATION | ContentType | 社交类型通知。<br/>**系统能力**：SystemCapability.Notification.Notification     |
| NOTIFICATION_CONTENT_MULTILINE    | ContentType | 多行文本类型通知。<br/>**系统能力**：SystemCapability.Notification.Notification |



## NotificationBasicContent

| 名称           | 可读 | 可写 | 类型   | 必填 | 描述                             |
| -------------- | ---- |--- | ------ | ---- | -------------------------------- |
| title          | 是  | 是  | string | 是   | 通知标题。<br/>**系统能力**：SystemCapability.Notification.Notification                         |
| text           | 是  | 是  | string | 是   | 通知内容。<br/>**系统能力**：SystemCapability.Notification.Notification                         |
| additionalText | 是  | 是  | string | 是   | 通知次要内容，是对通知内容的补充。<br/>**系统能力**：SystemCapability.Notification.Notification |



## NotificationLongTextContent

| 名称           | 可读 | 可写 | 类型   | 必填 | 描述                             |
| -------------- | ---- | --- | ------ | ---- | -------------------------------- |
| title          | 是  | 是  | string | 是   | 通知标题。<br/>**系统能力**：SystemCapability.Notification.Notification                         |
| text           | 是  | 是  | string | 是   | 通知内容。<br/>**系统能力**：SystemCapability.Notification.Notification                         |
| additionalText | 是  | 是  | string | 是   | 通知次要内容，是对通知内容的补充。<br/>**系统能力**：SystemCapability.Notification.Notification |
| longText       | 是  | 是  | string | 是   | 通知的长文本。<br/>**系统能力**：SystemCapability.Notification.Notification                     |
| briefText      | 是  | 是  | string | 是   | 通知概要内容，是对通知内容的总结。<br/>**系统能力**：SystemCapability.Notification.Notification |
| expandedTitle  | 是  | 是  | string | 是   | 通知展开时的标题。<br/>**系统能力**：SystemCapability.Notification.Notification                 |



## NotificationMultiLineContent

| 名称           | 可读 | 可写 | 类型            | 必填 | 描述                             |
| -------------- | --- | --- | --------------- | ---- | -------------------------------- |
| title          | 是  | 是  | string          | 是   | 通知标题。<br/>**系统能力**：SystemCapability.Notification.Notification                         |
| text           | 是  | 是  | string          | 是   | 通知内容。<br/>**系统能力**：SystemCapability.Notification.Notification                         |
| additionalText | 是  | 是  | string          | 是   | 通知次要内容，是对通知内容的补充。<br/>**系统能力**：SystemCapability.Notification.Notification |
| briefText      | 是  | 是  | string          | 是   | 通知概要内容，是对通知内容的总结。<br/>**系统能力**：SystemCapability.Notification.Notification |
| longTitle      | 是  | 是  | string          | 是   | 通知展开时的标题。<br/>**系统能力**：SystemCapability.Notification.Notification                 |
| lines          | 是  | 是  | Array\<String\> | 是   | 通知的多行文本。<br/>**系统能力**：SystemCapability.Notification.Notification                   |



## NotificationPictureContent

| 名称           | 可读 | 可写 | 类型           | 必填 | 描述                             |
| -------------- | ---- | --- | -------------- | ---- | -------------------------------- |
| title          | 是  | 是  | string         | 是   | 通知标题。<br/>**系统能力**：SystemCapability.Notification.Notification                         |
| text           | 是  | 是  | string         | 是   | 通知内容。<br/>**系统能力**：SystemCapability.Notification.Notification                         |
| additionalText | 是  | 是  | string         | 是   | 通知次要内容，是对通知内容的补充。<br/>**系统能力**：SystemCapability.Notification.Notification |
| briefText      | 是  | 是  | string         | 是   | 通知概要内容，是对通知内容的总结。<br/>**系统能力**：SystemCapability.Notification.Notification |
| expandedTitle  | 是  | 是  | string         | 是   | 通知展开时的标题。<br/>**系统能力**：SystemCapability.Notification.Notification                 |
| picture        | 是  | 是  | image.PixelMap | 是   | 通知的图片内容。<br/>**系统能力**：SystemCapability.Notification.Notification                   |



## BundleOption

| 名称   | 可读 | 可写 | 类型   | 必填 | 描述   |
| ------ | ---- | --- | ------ | ---- | ------ |
| bundle | 是  | 是  | string | 是   | 包名。<br/>**系统能力**：SystemCapability.Notification.Notification   |
| uid    | 是  | 是  | number | 否   | 用户id。<br/>**系统能力**：SystemCapability.Notification.Notification |



## NotificationKey

| 名称  | 可读 | 可写 | 类型   | 必填 | 描述     |
| ----- | ---- | --- | ------ | ---- | -------- |
| id    | 是  | 是  | number | 是   | 通知ID。<br/>**系统能力**：SystemCapability.Notification.Notification   |
| label | 是  | 是  | string | 否   | 通知标签。<br/>**系统能力**：SystemCapability.Notification.Notification |



## SlotType

| 名称                 | 值       | 说明     |
| -------------------- | -------- | -------- |
| SOCIAL_COMMUNICATION | SlotType | 社交类型。<br/>**系统能力**：SystemCapability.Notification.Notification |
| SERVICE_INFORMATION  | SlotType | 服务类型。<br/>**系统能力**：SystemCapability.Notification.Notification |
| CONTENT_INFORMATION  | SlotType | 内容类型。<br/>**系统能力**：SystemCapability.Notification.Notification |
| OTHER_TYPES          | SlotType | 其他类型。<br/>**系统能力**：SystemCapability.Notification.Notification |



## NotificationActionButton

| 名称      | 可读 | 可写 | 类型                                            | 必填 | 描述                      |
| --------- | --- | ---- | ----------------------------------------------- | ---- | ------------------------- |
| title     | 是  | 是  | string                                          | 是   | 按钮标题。<br/>**系统能力**：SystemCapability.Notification.Notification                  |
| wantAgent | 是  | 是  | WantAgent                                       | 是   | 点击按钮时触发的WantAgent。<br/>**系统能力**：SystemCapability.Notification.Notification |
| extras    | 是  | 是  | Array\<String\>                                 | 否   | 按钮扩展信息。<br/>**系统能力**：SystemCapability.Notification.Notification              |
| icon      | 是  | 是  | image.PixelMap                                  | 否   | 按钮图标。<br/>**系统能力**：SystemCapability.Notification.Notification                  |
| userInput | 是  | 是  | [NotificationUserInput](#notificationuserinput) | 否   | 用户输入对象实例。<br/>**系统能力**：SystemCapability.Notification.Notification          |



## NotificationUserInput

| 名称     | 可读 | 可写 | 类型   | 必填 | 描述                          |
| -------- | --- | ---- | ------ | ---- | ----------------------------- |
| inputKey | 是  | 是  | string | 是   | 用户输入时用于标识此输入的key。<br/>**系统能力**：SystemCapability.Notification.Notification |



## NotificationSubscribeInfo

| 名称        | 可读 | 可写 | 类型            | 必填 | 描述                            |
| ----------- | --- | ---- | --------------- | ---- | ------------------------------- |
| bundleNames | 是  | 是  | Array\<string\> | 否   | 指定订阅哪些包名的APP发来的通知。<br/>**系统能力**：SystemCapability.Notification.Notification |
| userId      | 是  | 是  | number          | 否   | 指定订阅哪个用户下发来的通知。<br/>**系统能力**：SystemCapability.Notification.Notification    |



## NotificationTemplate

模板信息

| 名称 | 参数类型               | 可读 | 可写 | 说明     |
| ---- | ---------------------- | ---- | ---- | -------- |
| name | string                 | 是   | 是   | 模板名称。<br/>**系统能力**：SystemCapability.Notification.Notification |
| data | {[key:string]: Object} | 是   | 是   | 模板数据。<br/>**系统能力**：SystemCapability.Notification.Notification |



## ActionResult

| 名称         | 参数类型    | 可读 | 可写  | 说明     |
| ------------ | ---------- | ---- | ---- | -------- |
| bundleName   | string     | 是   | 是   | 点击通知后重定向应用的包名。<br/>**系统能力**：SystemCapability.Notification.Notification |
| abilityName  | string     | 是   | 是   | 点击通知后重定向应用的的Ability名称。<br/>**系统能力**：SystemCapability.Notification.Notification |
| uri          | string     | 是   | 是   | 要重定向到的页面的Uri。<br/>**系统能力**：SystemCapability.Notification.Notification |



## ShowNotificationOptions

| 名称         | 参数类型       | 可读 | 可写  | 说明     |
| ------------ | ----------    | ---- | ---- | -------- |
| contentTitle | string        | 是   | 是   | 通知的标题。<br/>**系统能力**：SystemCapability.Notification.Notification |
| contentText  | string        | 是   | 是   | 通知的内容。<br/>**系统能力**：SystemCapability.Notification.Notification |
| clickAction  | ActionResult  | 是   | 是   | 点击通知后触发的动作。<br/>**系统能力**：SystemCapability.Notification.Notification |



## WantAgent接口

## 导入模块

```js
import WantAgent from '@ohos.wantAgent';
```



## WantAgent.getWantAgent

getWantAgent(info: WantAgentInfo, callback: AsyncCallback\<WantAgent\>): void

创建WantAgent（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 可读 | 可写  | 类型                       | 必填 | 描述                    |
| -------- | --- | ---- | -------------------------- | ---- | ----------------------- |
| info     | 是   | 否   | WantAgentInfo              | 是   | WantAgent信息。           |
| callback | 是   | 否   | AsyncCallback\<WantAgent\> | 是   | 创建WantAgent的回调方法。 |

**示例：**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

//getWantAgent回调
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
}
//WantAgentInfo对象
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)
```



## WantAgent.getWantAgent

getWantAgent(info: WantAgentInfo): Promise\<WantAgent\>

创建WantAgent（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称 | 可读 | 可写  | 类型          | 必填 | 描述          |
| ---- | --- | ---- | ------------- | ---- | ------------- |
| info | 是   | 否   | WantAgentInfo | 是   | WantAgent信息。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<WantAgent\> | 以Promise形式返回WantAgent。 |

**示例：**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

//WantAgentInfo对象
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
});
```



## WantAgent.getBundleName

getBundleName(agent: WantAgent, callback: AsyncCallback\<string\>): void

获取WantAgent实例的包名（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 可读 | 可写  | 类型                    | 必填 | 描述                              |
| -------- | --- | ---- | ----------------------- | ---- | --------------------------------- |
| agent    | 是   | 否   | WantAgent               | 是   | WantAgent对象。                     |
| callback | 是   | 否   | AsyncCallback\<string\> | 是   | 获取WantAgent实例的包名的回调方法。 |

**示例：**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

//wantAgent对象
var wantAgent;

//getWantAgent回调
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
}
//WantAgentInfo对象
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

//getBundleName回调
function getBundleNameCallback(err, data) {
	console.info("==========================>getBundleNameCallback=======================>");
}
WantAgent.getBundleName(wantAgent, getBundleNameCallback)
```



## WantAgent.getBundleName

getBundleName(agent: WantAgent): Promise\<string\>

获取WantAgent实例的包名（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称  | 可读 | 可写 | 类型      | 必填 | 描述          |
| ----- | --- | ---- | --------- | ---- | ------------- |
| agent | 是   | 否  | WantAgent | 是   | WantAgent对象。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<string\> | 以Promise形式返回获取WantAgent实例的包名。 |

**示例：**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

//wantAgent对象
var wantAgent;

//WantAgentInfo对象
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    wantAgent = data;
});

WantAgent.getBundleName(wantAgent).then((data) => {
	console.info("==========================>getBundleNameCallback=======================>");
});
```



## WantAgent.getUid

getUid(agent: WantAgent, callback: AsyncCallback\<number\>): void

获取WantAgent实例的用户ID（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 可读 | 可写 | 类型                    | 必填 | 描述                                |
| -------- | --- | ---- | ----------------------- | ---- | ----------------------------------- |
| agent    | 是   | 否  | WantAgent               | 是   | WantAgent对象。                       |
| callback | 是   | 否  | AsyncCallback\<number\> | 是   | 获取WantAgent实例的用户ID的回调方法。 |

**示例：**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

//wantAgent对象
var wantAgent;

//getWantAgent回调
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
}
//WantAgentInfo对象
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

//getUid回调
function getUidCallback(err, data) {
	console.info("==========================>getUidCallback=======================>");
}
WantAgent.getUid(wantAgent, getUidCallback)
```



## WantAgent.getUid

getUid(agent: WantAgent): Promise\<number\>

获取WantAgent实例的用户ID（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称  | 可读 | 可写 | 类型      | 必填 | 描述          |
| ----- | --- | ---- | --------- | ---- | ------------- |
| agent | 是   | 否  | WantAgent | 是   | WantAgent对象。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | 以Promise形式返回获取WantAgent实例的用户ID。 |

**示例：**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

//wantAgent对象
var wantAgent;

//WantAgentInfo对象
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    wantAgent = data;
});

WantAgent.getUid(wantAgent).then((data) => {
	console.info("==========================>getUidCallback=======================>");
});
```



## WantAgent.getWant

getWant(agent: WantAgent, callback: AsyncCallback\<Want\>): void

获取WantAgent对象的want（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                            |
| -------- | --- | ---- | --------------------- | ---- | ------------------------------- |
| agent    | 是   | 否  | WantAgent             | 是   | WantAgent对象。                   |
| callback | 是   | 否  | AsyncCallback\<Want\> | 是   | 获取WantAgent对象want的回调方法。 |

**示例：**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

//wantAgent对象
var wantAgent;

//getWantAgent回调
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
}
//WantAgentInfo对象
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

//getWant回调
function getWantCallback(err, data) {
	console.info("==========================>getWantCallback=======================>");
}
WantAgent.getWant(wantAgent, getWantCallback)
```



## WantAgent.getWant

getWant(agent: WantAgent): Promise\<Want\>

获取WantAgent对象的want（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称  | 可读 | 可写 | 类型      | 必填 | 描述          |
| ----- | --- | ---- | --------- | ---- | ------------- |
| agent | 是   | 否  | WantAgent | 是   | WantAgent对象。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Want\> | 以Promise形式返回获取WantAgent对象的want。 |

**示例：**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

//wantAgent对象
var wantAgent;

//WantAgentInfo对象
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    wantAgent = data;
});

WantAgent.getWant(wantAgent).then((data) => {
	console.info("==========================>getWantCallback=======================>");
});
```



## WantAgent.cancel

cancel(agent: WantAgent, callback: AsyncCallback\<void\>): void

取消WantAgent实例（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称     | 可读 | 可写 | 类型                  | 必填 | 描述                        |
| -------- | --- | ---- | --------------------- | ---- | --------------------------- |
| agent    | 是   | 否  | WantAgent             | 是   | WantAgent对象。               |
| callback | 是   | 否  | AsyncCallback\<void\> | 是   | 取消WantAgent实例的回调方法。 |

**示例：**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

//wantAgent对象
var wantAgent;

//getWantAgent回调
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
}
//WantAgentInfo对象
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

//cancel回调
function cancelCallback(err, data) {
	console.info("==========================>cancelCallback=======================>");
}
WantAgent.cancel(wantAgent, cancelCallback)
```



## WantAgent.cancel

cancel(agent: WantAgent): Promise\<void\>

取消WantAgent实例（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称  | 可读 | 可写 | 类型      | 必填 | 描述          |
| ----- | --- | ---- | --------- | ---- | ------------- |
| agent | 是   | 否  | WantAgent | 是   | WantAgent对象。 |

**示例：**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

//wantAgent对象
var wantAgent;

//WantAgentInfo对象
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    wantAgent = data;
});

WantAgent.cancel(wantAgent).then((data) => {
	console.info("==========================>cancelCallback=======================>");
});
```



## WantAgent.trigger

trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback\<CompleteData\>): void

主动激发WantAgent实例（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称        | 可读 | 可写 | 类型                          | 必填 | 描述                            |
| ----------- | --- | ---- | ----------------------------- | ---- | ------------------------------- |
| agent       | 是   | 否  | WantAgent                     | 是   | WantAgent对象。                   |
| triggerInfo | 是   | 否  | TriggerInfo                   | 是   | TriggerInfo对象。                 |
| callback    | 是   | 否  | AsyncCallback\<CompleteData\> | 是   | 主动激发WantAgent实例的回调方法。 |

**示例：**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

//wantAgent对象
var wantAgent;

//getWantAgent回调
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
}
//WantAgentInfo对象
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

//trigger回调
function triggerCallback(err, data) {
	console.info("==========================>triggerCallback=======================>");
}

var triggerInfo = {
    code:0
}
WantAgent.trigger(wantAgent, triggerInfo, triggerCallback)
```



## WantAgent.equal

equal(agent: WantAgent, otherAgent: WantAgent, callback: AsyncCallback\<boolean\>): void

判断两个WantAgent实例是否相等（callback形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称       | 可读 | 可写 | 类型                     | 必填 | 描述                                    |
| ---------- | --- | ---- | ------------------------ | ---- | --------------------------------------- |
| agent      | 是   | 否  | WantAgent                | 是   | WantAgent对象。                           |
| otherAgent | 是   | 否  | WantAgent                | 是   | WantAgent对象。                           |
| callback   | 是   | 否  | AsyncCallback\<boolean\> | 是   | 判断两个WantAgent实例是否相等的回调方法。 |

**示例：**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

//wantAgent对象
var wantAgent1;
var wantAgent2;

//getWantAgent回调
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	wantAgent1 = data;
        wantAgent2 = data;
    } else {
        console.info('----getWantAgent failed!----');
    }
}
//WantAgentInfo对象
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

//equal回调
function equalCallback(err, data) {
	console.info("==========================>equalCallback=======================>");
}
WantAgent.equal(wantAgent1, wantAgent2, equalCallback)
```



## WantAgent.equal

equal(agent: WantAgent, otherAgent: WantAgent): Promise\<boolean\>

判断两个WantAgent实例是否相等（Promise形式）。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称       | 可读 | 可写 | 类型      | 必填 | 描述          |
| ---------- | --- | ---- | --------- | ---- | ------------- |
| agent      | 是   | 否  | WantAgent | 是   | WantAgent对象。 |
| otherAgent | 是   | 否  | WantAgent | 是   | WantAgent对象。 |

**返回值：**

| 类型                                                        | 说明                                                         |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回获取判断两个WantAgent实例是否相等的结果。 |

**示例：**

```js
import WantAgent from '@ohos.wantAgent';
import { OperationType, WantAgentFlags } from '@ohos.wantagent';

//wantAgent对象
var wantAgent1;
var wantAgent2;

//WantAgentInfo对象
var wantAgentInfo = {
    wants: [
        {
            deviceId: "deviceId",
            bundleName: "com.neu.setResultOnAbilityResultTest1",
            abilityName: "com.example.test.MainAbility",
            action: "action1",
            entities: ["entity1"],
            type: "MIMETYPE",
            uri: "key={true,true,false}",
            parameters:
            {
                mykey0: 2222,
                mykey1: [1, 2, 3],
                mykey2: "[1, 2, 3]",
                mykey3: "ssssssssssssssssssssssssss",
                mykey4: [false, true, false],
                mykey5: ["qqqqq", "wwwwww", "aaaaaaaaaaaaaaaaa"],
                mykey6: true,
            }
        }
    ],
    operationType: OperationType.START_ABILITIES,
    requestCode: 0,
    wantAgentFlags:[WantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    wantAgent1 = data;
    wantAgent2 = data;
});

WantAgent.equal(wantAgent1, wantAgent2).then((data) => {
	console.info("==========================>equalCallback=======================>");
});
```



## WantAgentInfo

| 名称           | 可读 | 可写 | 类型                            | 必填 | 描述                   |
| -------------- | --- | ---- | ------------------------------- | ---- | ---------------------- |
| wants          | 是  | 是  | Array\<Want\>                   | 是   | 将被执行的动作列表。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core     |
| operationType  | 是  | 是  | wantAgent.OperationType         | 是   | 动作类型。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core               |
| requestCode    | 是  | 是  | number                          | 是   | 使用者定义的一个私有值。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| wantAgentFlags | 是  | 是  | Array<wantAgent.WantAgentFlags> | 否   | 动作执行属性。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core           |
| extraInfo      | 是  | 是  | {[key: string]: any}            | 否   | 额外数据。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core               |



## WantAgentFlags

| 名称                | 值             | 说明                                                         |
| ------------------- | -------------- | ------------------------------------------------------------ |
| ONE_TIME_FLAG       | WantAgentFlags | WantAgent仅能使用一次。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core                                        |
| NO_BUILD_FLAG       | WantAgentFlags | 如果描述WantAgent对象不存在，则不创建它，直接返回null。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core        |
| CANCEL_PRESENT_FLAG | WantAgentFlags | 在生成一个新的WantAgent对象前取消已存在的一个WantAgent对象。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core   |
| UPDATE_PRESENT_FLAG | WantAgentFlags | 使用新的WantAgent的额外数据替换已存在的WantAgent中的额外数据。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| CONSTANT_FLAG       | WantAgentFlags | WantAgent是不可变的。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core                                          |



## OperationType

| 名称              | 值            | 说明                    |
| ----------------- | ------------- | ----------------------- |
| UNKNOWN_TYPE      | OperationType | 不识别的类型。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core            |
| START_ABILITY     | OperationType | 开启一个有页面的Ability。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| START_ABILITIES   | OperationType | 开启多个有页面的Ability。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| START_SERVICE     | OperationType | 开启一个无页面的ability。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| SEND_COMMON_EVENT | OperationType | 发送一个公共事件。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core        |



## TriggerInfo

| 名称       | 可读 | 可写 | 类型                 | 必填 | 描述        |
| ---------- | --- | ---- | -------------------- | ---- | ----------- |
| code       | 是  | 是  | number               | 是   | result code。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| want       | 是  | 是  | Want                 | 否   | Want。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core        |
| permission | 是  | 是  | string               | 否   | 权限定义。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core    |
| extraInfo  | 是  | 是  | {[key: string]: any} | 否   | 额外数据。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core    |
