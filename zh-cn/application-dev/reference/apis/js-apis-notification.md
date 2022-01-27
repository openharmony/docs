# Notification模块

## 导入模块

```js
import Notification from '@ohos.notification';
```

## Notification.publish(request: NotificationRequest, callback: AsyncCallback\<void\>)

- 接口说明

  发布通知（callback形式）

- publish参数描述


| 名称     | 读写属性 | 类型                  | 必填 | 描述                                        |
| -------- | -------- | --------------------- | ---- | ------------------------------------------- |
| request  | 只读     | NotificationRequest   | 是   | 设置要发布通知内容的NotificationRequest对象 |
| callback | 只读     | AsyncCallback\<void\> | 是   | 被指定的回调方法                            |

- NotificationRequest类型说明

| 名称                  | 读写属性 | 类型                                          | 必填 | 描述                       |
| --------------------- | -------- | --------------------------------------------- | ---- | -------------------------- |
| content               | 读、写   | NotificationContent                           | 是   | 通知内容                   |
| id                    | 读、写   | number                                        | 否   | 通知ID                     |
| slotType              | 读、写   | SlotType                                      | 否   | 通道类型                   |
| isOngoing             | 读、写   | boolean                                       | 否   | 是否进行时通知             |
| isUnremovable         | 读、写   | boolean                                       | 否   | 是否可移除                 |
| deliveryTime          | 读、写   | number                                        | 否   | 通知发送时间               |
| tapDismissed          | 读、写   | boolean                                       | 否   | 通知是否自动清除           |
| autoDeletedTime       | 读、写   | number                                        | 否   | 自动清除的时间             |
| wantAgent             | 读、写   | WantAgent                                     | 否   | 点击跳转的WantAgent        |
| extraInfo             | 读、写   | {[key: string]: any}                          | 否   | 扩展参数                   |
| color                 | 读、写   | number                                        | 否   | 通知背景颜色               |
| colorEnabled          | 读、写   | boolean                                       | 否   | 通知背景颜色是否使能       |
| isAlertOnce           | 读、写   | boolean                                       | 否   | 设置是否仅有一次此通知警报 |
| isStopwatch           | 读、写   | boolean                                       | 否   | 是否显示已用时间           |
| isCountDown           | 读、写   | boolean                                       | 否   | 是否显示倒计时时间         |
| isFloatingIcon        | 读、写   | boolean                                       | 否   | 是否显示状态栏图标         |
| label                 | 读、写   | string                                        | 否   | 通知标签                   |
| badgeIconStyle        | 读、写   | number                                        | 否   | 通知角标类型               |
| showDeliveryTime      | 读、写   | boolean                                       | 否   | 是否显示分发时间           |
| actionButtons         | 读、写   | Array\<NotificationActionButton\>             | 否   | 通知按钮，最多两个按钮     |
| smallIcon             | 读、写   | PixelMap                                      | 否   | 通知小图标                 |
| largeIcon             | 读、写   | PixelMap                                      | 否   | 通知大图标                 |
| creatorBundleName     | 只读     | string                                        | 否   | 创建通知的包名             |
| creatorUid            | 只读     | number                                        | 否   | 创建通知的UID              |
| creatorPid            | 只读     | number                                        | 否   | 创建通知的PID              |
| hashCode              | 只读     | string                                        | 否   | 通知唯一标识               |
| classification        | 读、写   | string                                        | 否   | 通知分类                   |
| groupName             | 读、写   | string                                        | 否   | 组通知名称                 |
| template<sup>8+</sup> | 读、写   | [NotificationTemplate](#notificationtemplate) | 否   | 通知模板                   |

NotificationContent类型说明

| 名称        | 读写属性 | 类型                         | 必填 | 描述               |
| ----------- | -------- | ---------------------------- | ---- | ------------------ |
| contentType | 读、写   | ContentType                  | 是   | 通知内容类型       |
| normal      | 读、写   | NotificationBasicContent     | 否   | 基本类型通知内容   |
| longText    | 读、写   | NotificationLongTextContent  | 否   | 长文本类型通知内容 |
| multiLine   | 读、写   | NotificationMultiLineContent | 否   | 多行类型通知内容   |
| picture     | 读、写   | NotificationPictureContent   | 否   | 图片类型通知内容   |

- ContentType类型说明

| 名称                              | 读写属性 | 类型        | 描述             |
| --------------------------------- | -------- | ----------- | ---------------- |
| NOTIFICATION_CONTENT_BASIC_TEXT   | 只读     | ContentType | 普通类型通知     |
| NOTIFICATION_CONTENT_LONG_TEXT    | 只读     | ContentType | 长文本类型通知   |
| NOTIFICATION_CONTENT_PICTURE      | 只读     | ContentType | 图片类型通知     |
| NOTIFICATION_CONTENT_CONVERSATION | 只读     | ContentType | 社交类型通知     |
| NOTIFICATION_CONTENT_MULTILINE    | 只读     | ContentType | 多行文本类型通知 |

- NotificationBasicContent类型说明

| 名称           | 读写属性 | 类型   | 必填 | 描述                             |
| -------------- | -------- | ------ | ---- | -------------------------------- |
| title          | 读、写   | string | 是   | 通知标题                         |
| text           | 读、写   | string | 是   | 通知内容                         |
| additionalText | 读、写   | string | 是   | 通知次要内容，是对通知内容的补充 |

- NotificationLongTextContent类型说明

| 名称           | 读写属性 | 类型   | 必填 | 描述                             |
| -------------- | -------- | ------ | ---- | -------------------------------- |
| title          | 读、写   | string | 是   | 通知标题                         |
| text           | 读、写   | string | 是   | 通知内容                         |
| additionalText | 读、写   | string | 是   | 通知次要内容，是对通知内容的补充 |
| longText       | 读、写   | string | 是   | 通知的长文本                     |
| briefText      | 读、写   | string | 是   | 通知概要内容，是对通知内容的总结 |
| expandedTitle  | 读、写   | string | 是   | 通知展开时的标题                 |

- NotificationMultiLineContent类型说明

| 名称           | 读写属性 | 类型            | 必填 | 描述                             |
| -------------- | -------- | --------------- | ---- | -------------------------------- |
| title          | 读、写   | string          | 是   | 通知标题                         |
| text           | 读、写   | string          | 是   | 通知内容                         |
| additionalText | 读、写   | string          | 是   | 通知次要内容，是对通知内容的补充 |
| briefText      | 读、写   | string          | 是   | 通知概要内容，是对通知内容的总结 |
| longTitle      | 读、写   | string          | 是   | 通知展开时的标题                 |
| lines          | 读、写   | Array\<String\> | 是   | 通知的多行文本                   |

- NotificationPictureContent类型说明

| 名称           | 读写属性 | 类型           | 必填 | 描述                             |
| -------------- | -------- | -------------- | ---- | -------------------------------- |
| title          | 读、写   | string         | 是   | 通知标题                         |
| text           | 读、写   | string         | 是   | 通知内容                         |
| additionalText | 读、写   | string         | 是   | 通知次要内容，是对通知内容的补充 |
| briefText      | 读、写   | string         | 是   | 通知概要内容，是对通知内容的总结 |
| expandedTitle  | 读、写   | string         | 是   | 通知展开时的标题                 |
| picture        | 读、写   | image.PixelMap | 是   | 通知的图片内容                   |

- SlotType类型说明

| 名称                 | 读写属性 | 类型     | 必填 | 描述     |
| -------------------- | -------- | -------- | ---- | -------- |
| SOCIAL_COMMUNICATION | 只读     | SlotType | 否   | 社交类型 |
| SERVICE_INFORMATION  | 只读     | SlotType | 否   | 服务类型 |
| CONTENT_INFORMATION  | 只读     | SlotType | 否   | 内容类型 |
| OTHER_TYPES          | 只读     | SlotType | 否   | 其他类型 |

- NotificationActionButton类型说明

| 名称      | 读写属性 | 类型                  | 必填 | 描述                      |
| --------- | -------- | --------------------- | ---- | ------------------------- |
| title     | 读、写   | string                | 是   | 按钮标题                  |
| wantAgent | 读、写   | wantAgent             | 是   | 点击按钮时触发的WantAgent |
| extras    | 读、写   | Array\<String\>       | 否   | 按钮扩展信息              |
| icon      | 读、写   | image.PixelMap        | 否   | 按钮图标                  |
| userInput | 读、写   | NotificationUserInput | 否   | 用户输入对象实例          |

- NotificationUserInput类型说明

| 名称     | 读写属性 | 类型   | 必填 | 描述                          |
| -------- | -------- | ------ | ---- | ----------------------------- |
| inputKey | 读、写   | string | 是   | 用户输入时用于标识此输入的key |


- 返回值

  void

- 示例

```js
//publish回调
function publishCallback(err) {
	console.info("==========================>publishCallback=======================>");
}
//通知Request对象
var notificationRequest = {
    id: 1,
    content: {
        contentType: notify.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
}
Notification.publish(notificationRequest, publishCallback)
```



## Notification.publish(request: NotificationRequest)

- 接口说明

  发布通知（Promise形式）

- 返回值

  Promise\<void\>

- 示例

```js
//通知Request对象
var notificationRequest = {
    notificationId: 1,
    content: {
        contentType: notify.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
        normal: {
            title: "test_title",
            text: "test_text",
            additionalText: "test_additionalText"
        }
    }
}
Notification.publish(notificationRequest).then((void) => {
	console.info("==========================>publishCallback=======================>");
});

```



## Notification.cancel(id: number, label: string, callback: AsyncCallback\<void\>)

- 接口说明

  取消与指定id和label相匹配的已发布通知（callback形式）

- cancel参数描述

| 名称     | 读写属性 | 类型                  | 必填 | 描述                 |
| -------- | -------- | --------------------- | ---- | -------------------- |
| id       | 只读     | number                | 是   | 通知ID               |
| label    | 只读     | string                | 是   | 通知标签             |
| callback | 只读     | AsyncCallback\<void\> | 是   | 表示被指定的回调方法 |

- 返回值

  void

- 示例

```js
//cancel回调
function cancelCallback(err) {
	console.info("==========================>cancelCallback=======================>");
}
Notification.cancel(0, "label", cancelCallback)
```



## Notification.cancel(id：number, label？：string）

- 接口说明

  取消与指定id相匹配的已发布通知,label可以指定也可以不指定（Promise形式)

- cancel参数描述

| 名称  | 读写属性 | 类型   | 必填 | 描述     |
| ----- | -------- | ------ | ---- | -------- |
| id    | 只读     | number | 是   | 通知ID   |
| label | 只读     | string | 否   | 通知标签 |

- 返回值

  Promise\<void\>

- 示例

```js
Notification.cancel(0).then((void) => {
	console.info("==========================>cancelCallback=======================>");
});
```



## Notification.cancel(id: number, callback: AsyncCallback\<void\>)

- 接口说明

  取消与指定id相匹配的已发布通知（callback形式)

- cancel参数描述

| 名称     | 读写属性 | 类型                  | 必填 | 描述                 |
| -------- | -------- | --------------------- | ---- | -------------------- |
| id       | 只读     | number                | 是   | 通知ID               |
| callback | 只读     | AsyncCallback\<void\> | 是   | 表示被指定的回调方法 |

- 返回值

  void

- 示例

```js
//cancel回调
function cancelCallback(err) {
	console.info("==========================>cancelCallback=======================>");
}
Notification.cancel(0, cancelCallback)
```



## Notification.cancelAll(callback: AsyncCallback\<void\>)

- 接口说明

  取消所有已发布的通知（callback形式)

- cancelAll参数描述

| 名称     | 读写属性 | 类型                  | 必填 | 描述                 |
| -------- | -------- | --------------------- | ---- | -------------------- |
| callback | 只读     | AsyncCallback\<void\> | 是   | 表示被指定的回调方法 |

- 返回值

  void

- 示例

```js
//cancel回调
function cancelAllback(err) {
	console.info("==========================>cancelAllback=======================>");
}
Notification.cancelAll(cancelCallback)
```



## Notification.cancelAll()

- 接口说明

  取消所有已发布的通知（Promise形式)

- 参数描述

  无参数

- 返回值

  Promise\<void\>

- 示例

```js
Notification.cancelAll().then((void) => {
	console.info("==========================>cancelAllback=======================>");
});
```



## Notification.addSlot(slot: NotificationSlot, callback: AsyncCallback\<void\>)

- 接口说明

  创建通知通道（callback形式)

- addSlot参数描述

| 名称     | 读写属性 | 类型                  | 必填 | 描述                 |
| -------- | -------- | --------------------- | ---- | -------------------- |
| slot     | 只读     | NotificationSlot      | 是   | 要创建的通知通道对象 |
| callback | 只读     | AsyncCallback\<void\> | 是   | 表示被指定的回调方法 |

- NotificationSlot类型说明

| 名称                 | 读写属性 | 类型            | 必填 | 描述                                       |
| -------------------- | -------- | --------------- | ---- | ------------------------------------------ |
| type                 | 读、写   | SlotType        | 是   | 通道类型                                   |
| level                | 读、写   | number          | 否   | 通知级别，不设置则根据通知渠道类型有默认值 |
| desc                 | 读、写   | string          | 否   | 通知渠道描述信息                           |
| badgeFlag            | 读、写   | boolean         | 否   | 是否显示角标                               |
| bypassDnd            | 读、写   | boolean         | 否   | 置是否在系统中绕过免打扰模式               |
| lockscreenVisibility | 读、写   | boolean         | 否   | 在锁定屏幕上显示通知的模式                 |
| vibrationEnabled     | 读、写   | boolean         | 否   | 是否可振动                                 |
| sound                | 读、写   | string          | 否   | 通知提示音                                 |
| lightEnabled         | 读、写   | boolean         | 否   | 是否闪灯                                   |
| lightColor           | 读、写   | number          | 否   | 通知灯颜色                                 |
| vibrationValues      | 读、写   | Array\<number\> | 否   | 通知振动样式                               |

* 返回值

  void

* 示例

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



## Notification.addSlot(slot: NotificationSlot)

- 接口说明

  创建通知通道（Promise形式)

- addSlot参数描述

| 名称 | 读写属性 | 类型             | 必填 | 描述                 |
| ---- | -------- | ---------------- | ---- | -------------------- |
| slot | 只读     | NotificationSlot | 是   | 要创建的通知通道对象 |

- 返回值

  Promise\<void\>

- 示例

```js
//通知slot对象
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
Notification.addSlot(notificationSlot).then((void) => {
	console.info("==========================>addSlotCallback=======================>");
});
```



## Notification.addSlot(type: SlotType, callback: AsyncCallback\<void\>)

- 接口说明

  创建通知通道（callback形式)

- addSlot参数描述

| 名称     | 读写属性 | 类型                  | 必填 | 描述                   |
| -------- | -------- | --------------------- | ---- | ---------------------- |
| type     | 只读     | SlotType              | 是   | 要创建的通知通道的类型 |
| callback | 只读     | AsyncCallback\<void\> | 是   | 表示被指定的回调方法   |

- 返回值

  void

- 示例

```js
//addslot回调
function addSlotCallBack(err) {
	console.info("==========================>addSlotCallBack=======================>");
}
Notification.addSlot(Notification.SlotType.SOCIAL_COMMUNICATION, addSlotCallBack)
```



## Notification.addSlot(type: SlotType)

- 接口说明

  创建通知通道（Promise形式)

- addSlot参数描述

| 名称 | 读写属性 | 类型     | 必填 | 描述                   |
| ---- | -------- | -------- | ---- | ---------------------- |
| type | 只读     | SlotType | 是   | 要创建的通知通道的类型 |

- 返回值

  Promise\<void\>

- 示例

```js
Notification.addSlot(Notification.SlotType.SOCIAL_COMMUNICATION).then((void) => {
	console.info("==========================>addSlotCallback=======================>");
});
```



## Notification.addSlots(slots: Array\<NotificationSlot\>, callback: AsyncCallback\<void\>)

- 接口说明

  创建多个通知通道（callback形式)

- addSlots数描述

| 名称     | 读写属性 | 类型                      | 必填 | 描述                     |
| -------- | -------- | ------------------------- | ---- | ------------------------ |
| slots    | 只读     | Array\<NotificationSlot\> | 是   | 要创建的通知通道对象数组 |
| callback | 只读     | AsyncCallback\<void\>     | 是   | 表示被指定的回调方法     |

- 返回值

  void

- 示例

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



## Notification.addSlots(slots: Array\<NotificationSlot\>)

- 接口说明

  创建多个通知通道（Promise形式)

- addSlots数描述

| 名称  | 读写属性 | 类型                      | 必填 | 描述                     |
| ----- | -------- | ------------------------- | ---- | ------------------------ |
| slots | 只读     | Array\<NotificationSlot\> | 是   | 要创建的通知通道对象数组 |

- 返回值

  Promise\<void\>

- 示例

```js
//通知slot对象
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
//通知slot array 对象
var notificationSlotArray = new Array(); 
notificationSlotArray[0] = notificationSlot; 

Notification.addSlots(notificationSlotArray).then((void) => {
	console.info("==========================>addSlotCallback=======================>");
});
```



## Notification.getSlot(slotType: SlotType, callback: AsyncCallback\<NotificationSlot\>)

- 接口说明

  获取一个通知通道（callback形式)

- getSlot参数描述

| 名称     | 读写属性 | 类型                              | 必填 | 描述                                                        |
| -------- | -------- | --------------------------------- | ---- | ----------------------------------------------------------- |
| slotType | 只读     | slotType                          | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型 |
| callback | 只读     | AsyncCallback\<NotificationSlot\> | 是   | 表示被指定的回调方法                                        |

- 返回值

  void

- 示例

```js
//getSlot回调
function getSlotCallback(err,data) {
	console.info("==========================>getSlotCallback=======================>");
}
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.getSlot(slotType, getSlotCallback)
```



## Notification.getSlot(slotType)

- 接口说明

  获取一个通知通道（Promise形式)

- getSlot参数描述

| 名称     | 读写属性 | 类型     | 必填 | 描述                                                        |
| -------- | -------- | -------- | ---- | ----------------------------------------------------------- |
| slotType | 只读     | slotType | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型 |

- 返回值

  Promise\<NotificationSlot\>

- 示例

```js
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.getSlot(slotType).then((data) => {
	console.info("==========================>getSlotCallback=======================>");
});
```



## Notification.getSlots(callback: AsyncCallback<Array\<NotificationSlot\>>)

- 接口说明

  获取此应用程序的所有通知通道（callback形式)

- getSlots参数描述

| 名称     | 读写属性 | 类型                              | 必填 | 描述                 |
| -------- | -------- | --------------------------------- | ---- | -------------------- |
| callback | 只读     | AsyncCallback\<NotificationSlot\> | 是   | 表示被指定的回调方法 |

- 返回值

  void

- 示例

```js
//getSlots回调
function getSlotsCallback(err,data) {
	console.info("==========================>getSlotsCallback=======================>");
}
Notification.getSlots(getSlotsCallback)
```



## Notification.getSlots()

- 接口说明

  获取此应用程序的所有通知通道（Promise形式)

- getSlots参数描述

  无参数

- 返回值

  Promise\<Array\<NotificationSlot\>\>

- 示例

```js
Notification.getSlots().then((data) => {
	console.info("==========================>getSlotsCallback=======================>");
});
```



## Notification.removeSlot(slotType: SlotType, callback: AsyncCallback\<void\>)

- 接口说明

  根据通知通道类型删除创建的通知通道（callback形式)

- removeSlot参数描述

| 名称     | 读写属性 | 类型                  | 必填 | 描述                                                        |
| -------- | -------- | --------------------- | ---- | ----------------------------------------------------------- |
| SlotType | 只读     | SlotType              | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型 |
| callback | 只读     | AsyncCallback\<void\> | 是   | 表示被指定的回调方法                                        |

- 返回值

  void

- 示例

```js
//removeSlot回调
function removeSlotCallback(err) {
	console.info("==========================>removeSlotCallback=======================>");
}
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.removeSlot(slotType,removeSlotCallback)
```



## Notification.removeSlot(slotType: SlotType)

- 接口说明

  根据通知通道类型删除创建的通知通道（Promise形式)

- removeSlot参数描述

| 名称     | 读写属性 | 类型     | 必填 | 描述                                                        |
| -------- | -------- | -------- | ---- | ----------------------------------------------------------- |
| SlotType | 只读     | SlotType | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型 |

- 返回值

  Promise\<void\>

- 示例

```js
var slotType = Notification.SlotType.SOCIAL_COMMUNICATION;
Notification.removeSlot(slotType).then((void) => {
	console.info("==========================>removeSlotCallback=======================>");
});
```



## Notification.removeAllSlots(callback: AsyncCallback\<void\>)

- 接口说明

  删除所有通知通道（callback形式)

- removeAllSlots参数描述

| 名称     | 读写属性 | 类型                  | 必填 | 描述                 |
| -------- | -------- | --------------------- | ---- | -------------------- |
| callback | 只读     | AsyncCallback\<void\> | 是   | 表示被指定的回调方法 |

- 返回值

  void

- 示例

```js
function removeAllCallBack(err) {
	console.info("================>removeAllCallBack=======================>");
}
Notification.removeAllSlots(removeAllCallBack)
```



## Notification.removeAllSlots()

- 接口说明

  删除所有通知通道（Promise形式)

- removeAllSlots参数描述

  参数无

- 返回值

  Promise\<void\>

- 示例

```js
Notification.removeAllSlots().then((void) => {
	console.info("==========================>removeAllCallBack=======================>");
});
```



## Notification.subscribe(subscriber: NotificationSubscriber, info: NotificationSubscribeInfo, callback: AsyncCallback\<void\>)

- 接口说明

  订阅通知并指定订阅信息（callback形式)

- subscribe参数描述

| 名称       | 读写属性 | 类型                      | 必填 | 描述             |
| ---------- | -------- | ------------------------- | ---- | ---------------- |
| subscriber | 只读     | NotificationSubscriber    | 是   | 通知订阅对象     |
| info       | 只读     | NotificationSubscribeInfo | 是   | 订阅信息         |
| callback   | 只读     | AsyncCallback\<void\>     | 是   | 订阅动作回调函数 |

- NotificationSubscriber类型说明

| 名称                                                         | 读写属性 | 类型     | 必填 | 描述                       |
| ------------------------------------------------------------ | -------- | -------- | ---- | -------------------------- |
| onConsume?:(data: SubscribeCallbackData)                     | 读、写   | function | 否   | 接收通知回调函数           |
| onCancel?:(data: SubscribeCallbackData)                      | 读、写   | function | 否   | 删除通知回调函数           |
| onUpdate?:(data: NotificationSortingMap)                     | 读、写   | function | 否   | 更新通知排序回调函数       |
| onConnect?:()                                                | 读、写   | function | 否   | 注册订阅回调函数           |
| onDisconnect?:()                                             | 读、写   | function | 否   | 取消订阅回调函数           |
| onDestroy?:()                                                | 读、写   | function | 否   | 服务失联回调函数           |
| onDoNotDisturbDateChange?:(mode: notification.DoNotDisturbDate) | 读、写   | function | 否   | 免打扰时间选项变更回调函数 |

- SubscribeCallbackData 类型说明

| 名称            | 读写属性 | 类型                   | 必填 | 描述     |
| --------------- | -------- | ---------------------- | ---- | -------- |
| request         | 只读     | NotificationRequest    | 是   | 通知内容 |
| sortingMap      | 只读     | NotificationSortingMap | 否   | 排序信息 |
| reason          | 只读     | number                 | 否   | 删除原因 |
| sound           | 只读     | string                 | 否   | 通知声音 |
| vibrationValues | 只读     | Array\<number\>        | 否   | 通知震动 |

- NotificationSortingMap类型说明

| 名称           | 读写属性 | 类型                                 | 必填 | 描述             |
| -------------- | -------- | ------------------------------------ | ---- | ---------------- |
| sortings       | 只读     | {[key: string]: NotificationSorting} | 是   | 通知排序信息数组 |
| sortedHashCode | 只读     | Array\<string\>                      | 是   | 通知唯一标识数组 |

- NotificationSorting 类型说明

| 名称     | 读写属性 | 类型             | 必填 | 描述         |
| -------- | -------- | ---------------- | ---- | ------------ |
| slot     | 只读     | NotificationSlot | 是   | 通知通道内容 |
| hashCode | 只读     | string           | 是   | 通知唯一标识 |
| ranking  | 只读     | number           | 是   | 通知排序序号 |

- DoNotDisturbType类型说明


| 名称         | 读写属性 | 类型                  | 描述                                     |
| ------------ | -------- | --------------------- | ---------------------------------------- |
| TYPE_NONE    | 只读     | enum DoNotDisturbType | 非通知勿扰类型                           |
| TYPE_ONCE    | 只读     | enum DoNotDisturbType | 以设置时间段(只看小时和分钟)一次执行勿扰 |
| TYPE_DAILY   | 只读     | enum DoNotDisturbType | 以设置时间段(只看小时和分钟)每天执行勿扰 |
| TYPE_CLEARLY | 只读     | enum DoNotDisturbType | 以设置时间段(明确年月日时分)执行勿扰     |

- DoNotDisturbDate类型说明

| 名称  | 读写属性 | 类型             | 描述                     |
| ----- | -------- | ---------------- | ------------------------ |
| type  | 读写     | DoNotDisturbType | 指定免打扰设置的时间类型 |
| begin | 读写     | Date             | 指定免打扰设置的起点时间 |
| end   | 读写     | Date             | 指定免打扰设置的终点时间 |

- NotificationSubscribeInfo类型说明

| 名称        | 读写属性 | 类型            | 必填 | 描述                            |
| ----------- | -------- | --------------- | ---- | ------------------------------- |
| bundleNames | 读、写   | Array\<string\> | 否   | 指定订阅哪些包名的APP发来的通知 |
| userId      | 读、写   | number          | 否   | 指定订阅哪个用户下发来的通知    |

- 返回值

  void

- 示例

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



## Notification.subscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>)

- 接口说明

  订阅通知并指定订阅信息（callback形式)

- subscribe参数描述

| 名称       | 读写属性 | 类型                   | 必填 | 描述             |
| ---------- | -------- | ---------------------- | ---- | ---------------- |
| subscriber | 只读     | NotificationSubscriber | 是   | 通知订阅对象     |
| callback   | 只读     | AsyncCallback\<void\>  | 是   | 订阅动作回调函数 |

- 返回值

  void

- 示例

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



## Notification.subscribe(subscriber: NotificationSubscriber, info?: NotificationSubscribeInfo)

- 接口说明

  订阅通知并指定订阅信息（Promise形式)

- subscribe参数描述

| 名称       | 读写属性 | 类型                      | 必填 | 描述         |
| ---------- | -------- | ------------------------- | ---- | ------------ |
| subscriber | 只读     | NotificationSubscriber    | 是   | 通知订阅对象 |
| info       | 只读     | NotificationSubscribeInfo | 否   | 订阅信息     |

- 返回值

  Promise\<void\>

- 示例

```js
function onConsumeCallback(err, data) {
	console.info("==========================>onConsumeCallback=======================>");
}
var subscriber = {
    onConsume: onConsumeCallback
};
Notification.subscribe(subscriber).then((void) => {
	console.info("==========================>subscribeCallback=======================>");
});
```



## Notification.unsubscribe(subscriber: NotificationSubscriber, callback: AsyncCallback\<void\>)

- 接口说明

  取消订阅（callbcak形式)

- unsubscribe参数描述

| 名称       | 读写属性 | 类型                   | 必填 | 描述                 |
| ---------- | -------- | ---------------------- | ---- | -------------------- |
| subscriber | 只读     | NotificationSubscriber | 是   | 通知订阅对象         |
| callback   | 只读     | AsyncCallback\<void\>  | 是   | 取消订阅动作回调函数 |

- 返回值

  void

- 示例

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



## Notification.unsubscribe(subscriber: NotificationSubscriber)

- 接口说明

  取消订阅（Promise形式)

- unsubscribe参数描述

| 名称       | 读写属性 | 类型                   | 必填 | 描述         |
| ---------- | -------- | ---------------------- | ---- | ------------ |
| subscriber | 只读     | NotificationSubscriber | 是   | 通知订阅对象 |

- 返回值

  Promise\<void\>

- 示例

```js
function onConsumeCallback(err, data) {
	console.info("==========================>onConsumeCallback=======================>");
}
var subscriber = {
    onConsume: onConsumeCallback
};
Notification.unsubscribe(subscriber).then((void) => {
	console.info("==========================>unsubscribeCallback=======================>");
});
```



## Notification.enableNotification(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>)

- 接口说明

  设定指定包的通知使能状态（Callback形式)

- enableNotification参数描述

| 名称     | 读写属性 | 类型                  | 必填 | 描述                 |
| -------- | -------- | --------------------- | ---- | -------------------- |
| bundle   | 只读     | BundleOption          | 是   | 指定包信息           |
| enable   | 只读     | boolean               | 是   | 使能状态             |
| callback | 只读     | AsyncCallback\<void\> | 是   | 设定通知使能回调函数 |

- BundleOption类型说明

| 名称   | 读写属性 | 类型   | 必填 | 描述   |
| ------ | -------- | ------ | ---- | ------ |
| bundle | 读/写    | string | 是   | 包名   |
| uid    | 读/写    | number | 否   | 用户id |
- 返回值

  void

- 示例

```js
function enableNotificationCallback(err) {
	console.info("==========================>enableNotificationCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
Notification.enableNotification(bundle, false, enableNotificationCallback);
```



## Notification.enableNotification(bundle: BundleOption, enable: boolean)

- 接口说明

  设定指定包的通知使能状态（Promise形式)

- enableNotification参数描述

| 名称   | 读写属性 | 类型         | 必填 | 描述       |
| ------ | -------- | ------------ | ---- | ---------- |
| bundle | 只读     | BundleOption | 是   | 指定包信息 |
| enable | 只读     | boolean      | 是   | 使能状态   |

- 返回值

  Promise\<void\>

- 示例

```js
var bundle = {
    bundle: "bundleName1";
}
Notification.enableNotification(bundle, false).then((void) => {
	console.info("==========================>enableNotificationCallback=======================>");
});
```



## Notification.isNotificationEnabled(bundle: BundleOption, callback: AsyncCallback\<boolean\>)

- 接口说明

  获取指定包的通知使能状态（Callback形式)

- isNotificationEnabled参数描述

| 名称     | 读写属性 | 类型                  | 必填 | 描述                     |
| -------- | -------- | --------------------- | ---- | ------------------------ |
| bundle   | 只读     | BundleOption          | 是   | 指定包信息               |
| callback | 只读     | AsyncCallback\<void\> | 是   | 获取通知使能状态回调函数 |

- 返回值

  void

- 示例

```js
function isNotificationEnabledCallback(err, data) {
	console.info("==========================>isNotificationEnabledCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
Notification.isNotificationEnabled(bundle, isNotificationEnabledCallback);
```



## Notification.isNotificationEnabled(bundle: BundleOption)

- 接口说明

  获取指定包的通知使能状态（Promise形式)

- isNotificationEnabled参数描述

| 名称   | 读写属性 | 类型         | 必填 | 描述       |
| ------ | -------- | ------------ | ---- | ---------- |
| bundle | 只读     | BundleOption | 是   | 指定包信息 |

- 返回值

  Promise\<boolean\>

- 示例

```js
var bundle = {
    bundle: "bundleName1";
}
Notification.isNotificationEnabled(bundle).then((data) => {
	console.info("==========================>isNotificationEnabledCallback=======================>");
});
```



## Notification.isNotificationEnabled(callback: AsyncCallback\<boolean\>)

- 接口说明

  获取通知使能状态（Callback形式)

- isNotificationEnabled参数描述

| 名称     | 读写属性 | 类型                  | 必填 | 描述                     |
| -------- | -------- | --------------------- | ---- | ------------------------ |
| callback | 只读     | AsyncCallback\<void\> | 是   | 获取通知使能状态回调函数 |

- 返回值

  void

- 示例

```js
function isNotificationEnabledCallback(err, data) {
	console.info("==========================>isNotificationEnabledCallback=======================>");
}

Notification.isNotificationEnabled(isNotificationEnabledCallback);
```



## Notification.isNotificationEnabled()

- 接口说明

  获取通知使能状态（Promise形式)

- isNotificationEnabled参数描述

| 名称   | 读写属性 | 类型         | 必填 | 描述       |
| ------ | -------- | ------------ | ---- | ---------- |
| bundle | 只读     | BundleOption | 是   | 指定包信息 |

- 返回值

  Promise\<boolean\>

- 示例

```js
Notification.isNotificationEnabled().then((data) => {
	console.info("==========================>isNotificationEnabledCallback=======================>");
});
```



## Notification.displayBadge(bundle: BundleOption, enable: boolean, callback: AsyncCallback\<void\>)

- 接口说明

  设定指定包的角标使能状态（Callback形式)

- displayBadge参数描述

| 名称     | 读写属性 | 类型                  | 必填 | 描述                 |
| -------- | -------- | --------------------- | ---- | -------------------- |
| bundle   | 只读     | BundleOption          | 是   | 指定包信息           |
| enable   | 只读     | boolean               | 是   | 使能状态             |
| callback | 只读     | AsyncCallback\<void\> | 是   | 设定角标使能回调函数 |

- 返回值

  void

- 示例

```js
function displayBadgeCallback(err) {
	console.info("==========================>displayBadgeCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
Notification.displayBadge(bundle, false, displayBadgeCallback);
```



## Notification.displayBadge(bundle: BundleOption, enable: boolean)

- 接口说明

  设定指定包的角标使能状态（Promise形式)

- displayBadge参数描述

| 名称   | 读写属性 | 类型         | 必填 | 描述       |
| ------ | -------- | ------------ | ---- | ---------- |
| bundle | 只读     | BundleOption | 是   | 指定包信息 |
| enable | 只读     | boolean      | 是   | 使能状态   |

- 返回值

  Promise\<void\>

- 示例

```js
var bundle = {
    bundle: "bundleName1";
}
Notification.displayBadge(bundle, false).then((void) => {
	console.info("==========================>displayBadgeCallback=======================>");
});
```



## Notification.isBadgeDisplayed(bundle: BundleOption, callback: AsyncCallback\<boolean\>)

- 接口说明

  获取指定包的角标使能状态（Callback形式)

- isBadgeDisplayed参数描述

| 名称     | 读写属性 | 类型                  | 必填 | 描述                     |
| -------- | -------- | --------------------- | ---- | ------------------------ |
| bundle   | 只读     | BundleOption          | 是   | 指定包信息               |
| callback | 只读     | AsyncCallback\<void\> | 是   | 获取角标使能状态回调函数 |

- 返回值

  void

- 示例

```js
function isBadgeDisplayedCallback(err, data) {
	console.info("==========================>isBadgeDisplayedCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
Notification.isBadgeDisplayed(bundle, isBadgeDisplayedCallback);
```



## Notification.isBadgeDisplayed(bundle: BundleOption)

- 接口说明

  获取指定包的角标使能状态（Promise形式)

- isBadgeDisplayed参数描述

| 名称   | 读写属性 | 类型         | 必填 | 描述       |
| ------ | -------- | ------------ | ---- | ---------- |
| bundle | 只读     | BundleOption | 是   | 指定包信息 |

- 返回值

  Promise\<boolean\>

- 示例

```js
var bundle = {
    bundle: "bundleName1";
}
Notification.isBadgeDisplayed(bundle).then((data) => {
	console.info("==========================>isBadgeDisplayedCallback=======================>");
});
```



## Notification.setSlotByBundle(bundle: BundleOption, slot: NotificationSlot, callback: AsyncCallback\<void\>)

- 接口说明

  设定指定包的通知通道状态（Callback形式)

- setSlotByBundle参数描述

| 名称     | 读写属性 | 类型                  | 必填 | 描述                 |
| -------- | -------- | --------------------- | ---- | -------------------- |
| bundle   | 只读     | BundleOption          | 是   | 指定包信息           |
| slot     | 只读     | NotificationSlot      | 是   | 通知通道             |
| callback | 只读     | AsyncCallback\<void\> | 是   | 设定通知通道回调函数 |

- 返回值

  void

- 示例

```js
function setSlotByBundleCallback(err) {
	console.info("==========================>setSlotByBundleCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
Notification.setSlotByBundle(bundle, notificationSlot, setSlotByBundleCallback);
```



## Notification.setSlotByBundle(bundle: BundleOption, slot: NotificationSlot)

- 接口说明

  设定指定包的角标使能状态（Promise形式)

- setSlotByBundle参数描述

| 名称   | 读写属性 | 类型         | 必填 | 描述       |
| ------ | -------- | ------------ | ---- | ---------- |
| bundle | 只读     | BundleOption | 是   | 指定包信息 |
| enable | 只读     | boolean      | 是   | 使能状态   |

- 返回值

  Promise\<void\>

- 示例

```js
var bundle = {
    bundle: "bundleName1";
}
var notificationSlot = {
    type: Notification.SlotType.SOCIAL_COMMUNICATION
}
Notification.displayBadge(bundle, notificationSlot).then((void) => {
	console.info("==========================>setSlotByBundleCallback=======================>");
});
```



## Notification.getSlotsByBundle(bundle: BundleOption, callback: AsyncCallback<Array\<NotificationSlot\>>)

- 接口说明

  获取指定包的通知通道（Callback形式)

- getSlotsByBundle参数描述

| 名称     | 读写属性 | 类型                                     | 必填 | 描述                 |
| -------- | -------- | ---------------------------------------- | ---- | -------------------- |
| bundle   | 只读     | BundleOption                             | 是   | 指定包信息           |
| callback | 只读     | AsyncCallback<Array\<NotificationSlot\>> | 是   | 获取通知通道回调函数 |

- 返回值

  void

- 示例

```js
function getSlotsByBundleCallback(err, data) {
	console.info("==========================>getSlotsByBundleCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
Notification.getSlotsByBundle(bundle, getSlotsByBundleCallback);
```



## Notification.getSlotsByBundle(bundle: BundleOption)

- 接口说明

  获取指定包的通知通道（Promise形式)

- getSlotsByBundle参数描述

| 名称   | 读写属性 | 类型         | 必填 | 描述       |
| ------ | -------- | ------------ | ---- | ---------- |
| bundle | 只读     | BundleOption | 是   | 指定包信息 |

- 返回值

  Promise<Array\<NotificationSlot\>>

- 示例

```js
var bundle = {
    bundle: "bundleName1";
}
Notification.getSlotsByBundle(bundle).then((data) => {
	console.info("==========================>getSlotsByBundleCallback=======================>");
});
```



## Notification.getSlotNumByBundle(bundle: BundleOption, callback: AsyncCallback\<number\>)

- 接口说明

  获取指定包的通知通道数（Callback形式)

- getSlotNumByBundle参数描述

| 名称     | 读写属性 | 类型                      | 必填 | 描述                   |
| -------- | -------- | ------------------------- | ---- | ---------------------- |
| bundle   | 只读     | BundleOption              | 是   | 指定包信息             |
| callback | 只读     | AsyncCallback\<number\> | 是   | 获取通知通道数回调函数 |

- 返回值

  void

- 示例

```js
function getSlotNumByBundle(err, data) {
	console.info("==========================>getSlotNumByBundleCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
Notification.getSlotNumByBundle(bundle, getSlotNumByBundleCallback);
```



## Notification.getSlotNumByBundle(bundle: BundleOption)

- 接口说明

  获取指定包的通知通道数（Promise形式)

- getSlotNumByBundle参数描述

| 名称   | 读写属性 | 类型         | 必填 | 描述       |
| ------ | -------- | ------------ | ---- | ---------- |
| bundle | 只读     | BundleOption | 是   | 指定包信息 |

- 返回值

  Promise\<number\>

- 示例

```js
var bundle = {
    bundle: "bundleName1";
}
Notification.getSlotNumByBundle(bundle).then((data) => {
	console.info("==========================>getSlotNumByBundleCallback=======================>");
});
```



## Notification.remove(bundle: BundleOption, notificationKey: NotificationKey, callback: AsyncCallback\<void\>)

- 接口说明

  删除指定通知（Callback形式)

- remove参数描述

| 名称            | 读写属性 | 类型                  | 必填 | 描述                 |
| --------------- | -------- | --------------------- | ---- | -------------------- |
| bundle          | 只读     | BundleOption          | 是   | 指定包信息           |
| notificationKey | 只读     | NotificationKey       | 是   | 通知键值             |
| callback        | 只读     | AsyncCallback\<void\> | 是   | 删除指定通知回调函数 |

- NotificationKey类型说明

| 名称  | 读写属性 | 类型   | 必填 | 描述     |
| ----- | -------- | ------ | ---- | -------- |
| id    | 读、写   | number | 是   | 通知ID   |
| label | 读、写   | string | 否   | 通知标签 |

- 返回值

  void

- 示例

```js
function removeCallback(err) {
	console.info("==========================>removeCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
var notificationKey = {
    id: 0;
    label: "label";
}
Notification.remove(bundle, notificationKey, removeCallback);
```



## Notification.remove(bundle: BundleOption, notificationKey: NotificationKey)

- 接口说明

  删除指定通知（Promise形式)

- remove参数描述

| 名称            | 读写属性 | 类型            | 必填 | 描述       |
| --------------- | -------- | --------------- | ---- | ---------- |
| bundle          | 只读     | BundleOption    | 是   | 指定包信息 |
| notificationKey | 只读     | NotificationKey | 是   | 通知键值   |

- 返回值

  Promise\<void\>

- 示例

```js
var bundle = {
    bundle: "bundleName1";
}
var notificationKey = {
    id: 0;
    label: "label";
}
Notification.remove(bundle, notificationKey).then((void) => {
	console.info("==========================>removeCallback=======================>");
});
```



## Notification.remove(hashCode: string, callback: AsyncCallback\<void\>)

- 接口说明

  删除指定通知（Callback形式)

- remove参数描述

| 名称     | 读写属性 | 类型                  | 必填 | 描述                 |
| -------- | -------- | --------------------- | ---- | -------------------- |
| hashCode | 只读     | string                | 是   | 通知唯一ID           |
| callback | 只读     | AsyncCallback\<void\> | 是   | 删除指定通知回调函数 |

- 返回值

  void

- 示例

```js
function removeCallback(err) {
	console.info("==========================>removeCallback=======================>");
}

Notification.remove(hashCode, removeCallback);
```



## Notification.remove(hashCode: string)

- 接口说明

  删除指定通知（Promise形式)

- remove参数描述

| 名称     | 读写属性 | 类型       | 必填 | 描述       |
| -------- | -------- | ---------- | ---- | ---------- |
| hashCode | 只读     | string | 是   | 通知唯一ID |

- 返回值

  Promise\<void\>

- 示例

```js
Notification.remove(hashCode).then((void) => {
	console.info("==========================>removeCallback=======================>");
});
```



## Notification.removeAll(bundle: BundleOption, callback: AsyncCallback\<void\>)

- 接口说明

  删除指定包的所有通知（Callback形式)

- removeAll参数描述

| 名称     | 读写属性 | 类型                  | 必填 | 描述                         |
| -------- | -------- | --------------------- | ---- | ---------------------------- |
| bundle   | 只读     | BundleOption          | 是   | 指定包信息                   |
| callback | 只读     | AsyncCallback\<void\> | 是   | 删除指定包的所有通知回调函数 |

- 返回值

  void

- 示例

```js
function removeAllCallback(err) {
	console.info("==========================>removeAllCallback=======================>");
}
var bundle = {
    bundle: "bundleName1";
}
Notification.removeAll(bundle, removeAllCallback);
```



## Notification.removeAll(callback: AsyncCallback\<void\>)

- 接口说明

  删除所有通知（Callback形式)

- removeAll参数描述

| 名称     | 读写属性 | 类型                  | 必填 | 描述                 |
| -------- | -------- | --------------------- | ---- | -------------------- |
| callback | 只读     | AsyncCallback\<void\> | 是   | 删除所有通知回调函数 |

- 返回值

  void

- 示例

```js
function removeAllCallback(err) {
	console.info("==========================>removeAllCallback=======================>");
}

Notification.removeAll(removeAllCallback);
```



## Notification.removeAll(bundle?: BundleOption)

- 接口说明

  删除所有通知（Promise形式)

- removeAll参数描述

| 名称   | 读写属性 | 类型         | 必填 | 描述       |
| ------ | -------- | ------------ | ---- | ---------- |
| bundle | 只读     | BundleOption | 否   | 指定包信息 |

- 返回值

  Promise\<void\>

- 示例

```js
Notification.removeAll().then((void) => {
	console.info("==========================>removeAllCallback=======================>");
});
```



## Notification.getAllActiveNotifications(callback: AsyncCallback<Array\<NotificationRequest\>>)

- 接口说明

  获取活动通知（Callback形式)

- getAllActiveNotifications参数描述

| 名称     | 读写属性 | 类型                                        | 必填 | 描述                 |
| -------- | -------- | ------------------------------------------- | ---- | -------------------- |
| callback | 只读     | AsyncCallback<Array\<NotificationRequest\>> | 是   | 获取活动通知回调函数 |

- 返回值

  void

- 示例

```js
function getAllActiveNotificationsCallback(err, data) {
	console.info("==========================>getAllActiveNotificationsCallback=======================>");
}

Notification.getAllActiveNotifications(getAllActiveNotificationsCallback);
```



## Notification.getAllActiveNotifications()

- 接口说明

  获取活动通知（Promise形式)

- getAllActiveNotifications参数描述

  无

- 返回值

  Promise\<Array\<NotificationRequest\>\>

- 示例

```js
Notification.getAllActiveNotifications().then((data) => {
	console.info("==========================>getAllActiveNotificationsCallback=======================>");
});
```



## Notification.getActiveNotificationCount(callback: AsyncCallback\<number\>)

- 接口说明

  获取当前应用的活动通知数（Callback形式)

- getActiveNotificationCount参数描述

| 名称     | 读写属性 | 类型                   | 必填 | 描述                   |
| -------- | -------- | ---------------------- | ---- | ---------------------- |
| callback | 只读     | AsyncCallback\<number\> | 是   | 获取活动通知数回调函数 |

- 返回值

  void

- 示例

```js
function getActiveNotificationCountCallback(err, data) {
	console.info("==========================>getActiveNotificationCountCallback=======================>");
}

Notification.getActiveNotificationCount(getActiveNotificationCountCallback);
```



## Notification.getActiveNotificationCount()

- 接口说明

  获取当前应用的活动通知数（Promise形式)

- getActiveNotificationCount参数描述

  无

- 返回值

  返回值为Promise\<number\>

- 示例

```js
Notification.getActiveNotificationCount().then((data) => {
	console.info("==========================>getActiveNotificationCountCallback=======================>");
});
```



## Notification.getActiveNotifications(callback: AsyncCallback<Array\<NotificationRequest\>>)

- 接口说明

  获取当前应用的活动通知（Callback形式)

- getActiveNotifications参数描述

| 名称     | 读写属性 | 类型                                        | 必填 | 描述                           |
| -------- | -------- | ------------------------------------------- | ---- | ------------------------------ |
| callback | 只读     | AsyncCallback<Array\<NotificationRequest\>> | 是   | 获取当前应用的活动通知回调函数 |

- 返回值

  void

- 示例

```js
function getActiveNotificationsCallback(err, data) {
	console.info("==========================>getActiveNotificationsCallback=======================>");
}

Notification.getActiveNotifications(getActiveNotificationsCallback);
```



## Notification.getActiveNotifications()

- 接口说明

  获取当前应用的活动通知（Promise形式)

- getActiveNotifications参数描述

  无

- 返回值

  Promise\<Array\<NotificationRequest\>\>

- 示例

```js
Notification.getActiveNotifications().then((data) => {
	console.info("==========================>getActiveNotificationsCallback=======================>");
});
```



## Notification.cancelGroup(groupName: string, callback: AsyncCallback\<void\>)

- 接口说明

  取消本应用指定组通知（Callback形式)

- cancelGroup参数描述

| 名称      | 读写属性 | 类型                  | 必填 | 描述                         |
| --------- | -------- | --------------------- | ---- | ---------------------------- |
| groupName | 只读     | string                | 是   | 指定通知组名称               |
| callback  | 只读     | AsyncCallback\<void\> | 是   | 取消本应用指定组通知回调函数 |

- 返回值

  void

- 示例

```js
function cancelGroupCallback(err) {
   console.info("==========================>cancelGroupCallback=======================>");
}

var groupName = "GroupName";

Notification.cancelGroup(groupName, cancelGroupCallback);
```



## Notification.cancelGroup(groupName: string)

- 接口说明

  取消本应用指定组通知（Promise形式)

- cancelGroup参数描述

| 名称      | 读写属性 | 类型   | 必填 | 描述           |
| --------- | -------- | ------ | ---- | -------------- |
| groupName | 只读     | string | 是   | 指定通知组名称 |

- 返回值

  Promise\<void\>

- 示例

```js
var groupName = "GroupName";
Notification.cancelGroup(groupName).then(() => {
	console.info("==========================>cancelGroupPromise=======================>");
});
```



## Notification.removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void\>)

- 接口说明

  删除指定应用指定组通知（Callback形式)

- removeGroupByBundle参数描述

| 名称      | 读写属性 | 类型                  | 必填 | 描述                         |
| --------- | -------- | --------------------- | ---- | ---------------------------- |
| bundle    | 只读     | BundleOption          | 是   | 指定包信息                   |
| groupName | 只读     | string                | 是   | 指定通知组名称               |
| callback  | 只读     | AsyncCallback\<void\> | 是   | 删除本应用指定组通知回调函数 |

- 返回值

  void

- 示例

```js
function removeGroupByBundleCallback(err) {
   console.info("==========================>removeGroupByBundleCallback=======================>");
}

var bundleOption = {bundle: "Bundle"};
var groupName = "GroupName";

Notification.removeGroupByBundle(bundleOption, groupName, removeGroupByBundleCallback);
```



## Notification.removeGroupByBundle(bundle: BundleOption, groupName: string)

- 接口说明

  删除指定应用指定组通知（Promise形式)

- removeGroupByBundle参数描述

| 名称      | 读写属性 | 类型         | 必填 | 描述           |
| --------- | -------- | ------------ | ---- | -------------- |
| bundle    | 只读     | BundleOption | 是   | 指定包信息     |
| groupName | 只读     | string       | 是   | 指定通知组名称 |

- 返回值

  Promise\<void\>

- 示例

```js
var bundleOption = {bundle: "Bundle"};
var groupName = "GroupName";
Notification.removeGroupByBundle(bundleOption, groupName).then(() => {
	console.info("==========================>removeGroupByBundlePromise=======================>");
});
```



## Notification.setDoNotDisturbDate(date: DoNotDisturbDate, callback: AsyncCallback\<void\>)

- 接口说明

  设置免打扰时间（Callback形式)

- setDoNotDisturbDate参数描述

| 名称     | 读写属性 | 类型                  | 必填 | 描述                   |
| -------- | -------- | --------------------- | ---- | ---------------------- |
| date     | 只读     | DoNotDisturbDate      | 是   | 免打扰时间选项         |
| callback | 只读     | AsyncCallback\<void\> | 是   | 设置免打扰时间回调函数 |

- 返回值

  void

- 示例

```js
function setDoNotDisturbDateCallback(err) {
   console.info("==========================>setDoNotDisturbDateCallback=======================>");
}

var doNotDisturbDate = {
    type: notification.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
}

Notification.setDoNotDisturbDate(doNotDisturbDate, setDoNotDisturbDateCallback);
```



## Notification.setDoNotDisturbDate(date: DoNotDisturbDate)

- 接口说明

  设置免打扰时间接口（Promise形式)

- setDoNotDisturbDate参数描述

| 名称 | 读写属性 | 类型             | 必填 | 描述           |
| ---- | -------- | ---------------- | ---- | -------------- |
| date | 只读     | DoNotDisturbDate | 是   | 免打扰时间选项 |

- 返回值

  Promise\<void\>

- 示例

```js
var doNotDisturbDate = {
    type: notification.DoNotDisturbType.TYPE_ONCE,
    begin: new Date(),
    end: new Date(2021, 11, 15, 18, 0)
}
Notification.setDoNotDisturbDate(doNotDisturbDate).then(() => {
	console.info("==========================>setDoNotDisturbDatePromise=======================>");
});
```



## Notification.getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate\>)

- 接口说明

  查询免打扰时间接口（Callback形式)

- getDoNotDisturbDate参数描述

| 名称     | 读写属性 | 类型                              | 必填 | 描述                   |
| -------- | -------- | --------------------------------- | ---- | ---------------------- |
| callback | 只读     | AsyncCallback\<DoNotDisturbDate\> | 是   | 查询免打扰时间回调函数 |

- 返回值

  void

- 示例

```js
function getDoNotDisturbDateCallback(err,data) {
   console.info("==========================>getDoNotDisturbDateCallback=======================>");
}

Notification.getDoNotDisturbDate(getDoNotDisturbDateCallback);
```



## Notification.getDoNotDisturbDate()

- 接口说明

  查询免打扰时间接口（Promise形式)

- getDoNotDisturbDate参数描述

  无

- 返回值

  Promise\<DoNotDisturbDate\>

- 示例

```js
Notification.getDoNotDisturbDate().then((data) => {
	console.info("==========================>getDoNotDisturbDatePromise=======================>");
});
```



## Notification.supportDoNotDisturbMode(callback: AsyncCallback\<boolean\>)

- 接口说明

  查询是否支持勿扰模式功能（Callback形式)

- supportDoNotDisturbMode参数描述

| 名称     | 读写属性 | 类型                     | 必填 | 描述                             |
| -------- | -------- | ------------------------ | ---- | -------------------------------- |
| callback | 只读     | AsyncCallback\<boolean\> | 是   | 查询是否支持勿扰模式功能回调函数 |

- 返回值

  void

- 示例

```js
function supportDoNotDisturbModeCallback(err,data) {
   console.info("==========================>supportDoNotDisturbModeCallback=======================>");
}

Notification.supportDoNotDisturbMode(supportDoNotDisturbModeCallback);
```



## Notification.supportDoNotDisturbMode()

- 接口说明

  查询是否支持勿扰模式功能（Promise形式)

- supportDoNotDisturbMode参数描述

  无

- 返回值

  Promise\<boolean\>

- 示例

```js
Notification.supportDoNotDisturbMode().then((data) => {
	console.info("==========================>supportDoNotDisturbModePromise=======================>");
});
```



## Notification.isSupportTemplate

isSupportTemplate(templateName: string, callback: AsyncCallback\<boolean\>): void

查询模板是否存在。

- 参数

| 参数名       | 类型                     | 必填 | 说明                       |
| ------------ | ------------------------ | ---- | -------------------------- |
| templateName | string                   | 是   | 模板名称                   |
| callback     | AsyncCallback\<boolean\> | 是   | 查询模板是否存在的回调函数 |

- 示例

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

- 参数

| 参数名       | 类型   | 必填 | 说明     |
| ------------ | ------ | ---- | -------- |
| templateName | string | 是   | 模板名称 |

- 返回值

| 类型               | 说明            |
| ------------------ | --------------- |
| Promise\<boolean\> | Promise方式返回 |

- 示例

```javascript
var templateName = 'process';

Notification.isSupportTemplate(templateName).then((data) => {
    console.info("isSupportTemplateCallback");
});
```



## NotificationTemplate

模板信息

| 名称 | 参数类型               | 可读 | 可写 | 说明     |
| ---- | ---------------------- | ---- | ---- | -------- |
| name | string                 | 是   | 是   | 模板名称 |
| data | {[key:string]: Object} | 是   | 是   | 模板数据 |



## WantAgent接口

## 导入模块

```js
import WantAgent from '@ohos.wantAgent';
```

## WantAgent.getWantAgent(info: WantAgentInfo, callback: AsyncCallback\<WantAgent\>)

- 接口说明

  创建WantAgent（callback形式）

- getWantAgent参数描述


| 名称     | 读写属性 | 类型                       | 必填 | 描述                    |
| -------- | -------- | -------------------------- | ---- | ----------------------- |
| info     | 只读     | WantAgentInfo              | 是   | WantAgent信息           |
| callback | 只读     | AsyncCallback\<WantAgent\> | 是   | 创建WantAgent的回调方法 |

- WantAgentInfo类型说明

| 名称           | 读写属性 | 类型                            | 必填 | 描述                   |
| -------------- | -------- | ------------------------------- | ---- | ---------------------- |
| wants          | 读、写   | Array\<Want\>                   | 是   | 将被执行的动作列表     |
| operationType  | 读、写   | wantAgent.OperationType         | 是   | 动作类型               |
| requestCode    | 读、写   | number                          | 是   | 使用者定义的一个私有值 |
| wantAgentFlags | 读、写   | Array<wantAgent.WantAgentFlags> | 否   | 动作执行属性           |
| extraInfo      | 读、写   | {[key: string]: any}            | 否   | 额外数据               |

- 
  WantAgentFlags类型说明


| 名称                | 读写属性 | 类型 | 必填 | 描述                                                         |
| ------------------- | -------- | ---- | ---- | ------------------------------------------------------------ |
| ONE_TIME_FLAG       | 只读     | enum | 否   | WantAgent仅能使用一次                                        |
| NO_BUILD_FLAG       | 只读     | enum | 否   | 如果描述WantAgent对象不存在，则不创建它，直接返回null        |
| CANCEL_PRESENT_FLAG | 只读     | enum | 否   | 在生成一个新的WantAgent对象前取消已存在的一个WantAgent对象   |
| UPDATE_PRESENT_FLAG | 只读     | enum | 否   | 使用新的WantAgent的额外数据替换已存在的WantAgent中的额外数据 |
| CONSTANT_FLAG       | 只读     | enum | 否   | WantAgent是不可变的                                          |

- OperationType类型说明

| 名称              | 读写属性 | 类型 | 必填 | 描述                    |
| ----------------- | -------- | ---- | ---- | ----------------------- |
| UNKNOWN_TYPE      | 只读     | enum | 否   | 不识别的类型            |
| START_ABILITY     | 只读     | enum | 否   | 开启一个有页面的Ability |
| START_ABILITIES   | 只读     | enum | 否   | 开启多个有页面的Ability |
| START_SERVICE     | 只读     | enum | 否   | 开启一个无页面的ability |
| SEND_COMMON_EVENT | 只读     | enum | 否   | 发送一个公共事件        |

- 返回值

  void

- 示例

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



## WantAgent.getWantAgent(info: WantAgentInfo): Promise\<WantAgent\>

- 接口说明

  创建WantAgent（Promise形式）

- getWantAgent参数描述


| 名称 | 读写属性 | 类型          | 必填 | 描述          |
| ---- | -------- | ------------- | ---- | ------------- |
| info | 只读     | WantAgentInfo | 是   | WantAgent信息 |

- 返回值

  Promise\<WantAgent\>

- 示例

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



## WantAgent.getBundleName(agent: WantAgent, callback: AsyncCallback\<string\>)

- 接口说明

  获取WantAgent实例的包名（callback形式）

- getBundleName参数描述


| 名称     | 读写属性 | 类型                    | 必填 | 描述                              |
| -------- | -------- | ----------------------- | ---- | --------------------------------- |
| agent    | 只读     | WantAgent               | 是   | WantAgent对象                     |
| callback | 只读     | AsyncCallback\<string\> | 是   | 获取WantAgent实例的包名的回调方法 |

- 返回值

  void

- 示例

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



## WantAgent.getBundleName(agent: WantAgent): Promise\<string\>

- 接口说明

  获取WantAgent实例的包名（Promise形式）

- getBundleName参数描述


| 名称  | 读写属性 | 类型      | 必填 | 描述          |
| ----- | -------- | --------- | ---- | ------------- |
| agent | 只读     | WantAgent | 是   | WantAgent对象 |

- 返回值

  Promise\<string\>

- 示例

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



## WantAgent.getUid(agent: WantAgent, callback: AsyncCallback\<number\>)

- 接口说明

  获取WantAgent实例的用户ID（callback形式）

- getUid参数描述


| 名称     | 读写属性 | 类型                    | 必填 | 描述                                |
| -------- | -------- | ----------------------- | ---- | ----------------------------------- |
| agent    | 只读     | WantAgent               | 是   | WantAgent对象                       |
| callback | 只读     | AsyncCallback\<number\> | 是   | 获取WantAgent实例的用户ID的回调方法 |

- 返回值

  void

- 示例

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



## WantAgent.getUid(agent: WantAgent): Promise\<number\>

- 接口说明

  获取WantAgent实例的用户ID（Promise形式）

- getUid参数描述


| 名称  | 读写属性 | 类型      | 必填 | 描述          |
| ----- | -------- | --------- | ---- | ------------- |
| agent | 只读     | WantAgent | 是   | WantAgent对象 |

- 返回值

  Promise\<number\>

- 示例

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



## WantAgent.getWant(agent: WantAgent, callback: AsyncCallback\<Want\>)

- 接口说明

  获取WantAgent对象的want（callback形式）

- getWant参数描述


| 名称     | 读写属性 | 类型                  | 必填 | 描述                            |
| -------- | -------- | --------------------- | ---- | ------------------------------- |
| agent    | 只读     | WantAgent             | 是   | WantAgent对象                   |
| callback | 只读     | AsyncCallback\<Want\> | 是   | 获取WantAgent对象want的回调方法 |

- 返回值

  void

- 示例

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
    wantAgentFlags:[WantAgentWantAgentFlags.UPDATE_PRESENT_FLAG]
}

WantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

//getWant回调
function getWantCallback(err, data) {
	console.info("==========================>getWantCallback=======================>");
}
WantAgent.getWant(wantAgent, getWantCallback)
```



## WantAgent.getWant(agent: WantAgent): Promise\<Want\>

- 接口说明

  获取WantAgent对象的want（Promise形式）

- getWant参数描述


| 名称  | 读写属性 | 类型      | 必填 | 描述          |
| ----- | -------- | --------- | ---- | ------------- |
| agent | 只读     | WantAgent | 是   | WantAgent对象 |

- 返回值

  Promise\<Want\>

- 示例

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



## WantAgent.cancel(agent: WantAgent, callback: AsyncCallback\<void\>)

- 接口说明

  取消WantAgent实例（callback形式）

- cancel参数描述


| 名称     | 读写属性 | 类型                  | 必填 | 描述                        |
| -------- | -------- | --------------------- | ---- | --------------------------- |
| agent    | 只读     | WantAgent             | 是   | WantAgent对象               |
| callback | 只读     | AsyncCallback\<void\> | 是   | 取消WantAgent实例的回调方法 |

- 返回值

  void

- 示例

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



## WantAgent.cancel(agent: WantAgent): Promise\<void\>

- 接口说明

  取消WantAgent实例（Promise形式）

- cancel参数描述


| 名称  | 读写属性 | 类型      | 必填 | 描述          |
| ----- | -------- | --------- | ---- | ------------- |
| agent | 只读     | WantAgent | 是   | WantAgent对象 |

- 返回值

  Promise\<void\>

- 示例

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



## WantAgent.trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback\<CompleteData\>)

- 接口说明

  主动激发WantAgent实例（callback形式）

- trigger参数描述


| 名称        | 读写属性 | 类型                          | 必填 | 描述                            |
| ----------- | -------- | ----------------------------- | ---- | ------------------------------- |
| agent       | 只读     | WantAgent                     | 是   | WantAgent对象                   |
| triggerInfo | 只读     | TriggerInfo                   | 是   | TriggerInfo对象                 |
| callback    | 只读     | AsyncCallback\<CompleteData\> | 是   | 主动激发WantAgent实例的回调方法 |

- TriggerInfo类型说明

| 名称       | 读写属性 | 类型                 | 必填 | 描述        |
| ---------- | -------- | -------------------- | ---- | ----------- |
| code       | 读、写   | number               | 是   | result code |
| want       | 读、写   | Want                 | 否   | Want        |
| permission | 读、写   | string               | 否   | 权限定义    |
| extraInfo  | 读、写   | {[key: string]: any} | 否   | 额外数据    |

- 返回值

  void

- 示例

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



## WantAgent.equal(agent: WantAgent, otherAgent: WantAgent, callback: AsyncCallback\<boolean\>)

- 接口说明

  判断两个WantAgent实例是否相等（callback形式）

- equal参数描述


| 名称       | 读写属性 | 类型                     | 必填 | 描述                                    |
| ---------- | -------- | ------------------------ | ---- | --------------------------------------- |
| agent      | 只读     | WantAgent                | 是   | WantAgent对象                           |
| otherAgent | 只读     | WantAgent                | 是   | WantAgent对象                           |
| callback   | 只读     | AsyncCallback\<boolean\> | 是   | 判断两个WantAgent实例是否相等的回调方法 |

- 返回值

  void

- 示例

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



## WantAgent.equal(agent: WantAgent, otherAgent: WantAgent): Promise\<boolean\>

- 接口说明

  判断两个WantAgent实例是否相等（Promise形式）

- equal参数描述


| 名称       | 读写属性 | 类型      | 必填 | 描述          |
| ---------- | -------- | --------- | ---- | ------------- |
| agent      | 只读     | WantAgent | 是   | WantAgent对象 |
| otherAgent | 只读     | WantAgent | 是   | WantAgent对象 |

- 返回值

  Promise\<boolean\>

- 示例

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



#### 



