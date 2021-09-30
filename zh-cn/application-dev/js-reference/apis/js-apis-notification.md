

### Notification模块(JS端SDK接口)

#### 支持设备

| API                                                          | 手机 | 平板 | 智慧屏 | 智能穿戴 |
| ------------------------------------------------------------ | ---- | ---- | ------ | -------- |
| Notification.publish(request: NotificationRequest, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.publish(request: NotificationRequest)           | 支持 | 支持 | 支持   | 支持     |
| Notification.cancel(id: number, label: string, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.cancel(id：number, label？：string）            | 支持 | 支持 | 支持   | 支持     |
| Notification.cancel(id: number, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.cancelAll(callback: AsyncCallback<void>)        | 支持 | 支持 | 支持   | 支持     |
| Notification.cancelAll()                                     | 支持 | 支持 | 支持   | 支持     |
| Notification.addSlot(slot: NotificationSlot, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.addSlot(slot: NotificationSlot)                 | 支持 | 支持 | 支持   | 支持     |
| Notification.addSlot(type: SlotType, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.addSlot(type: SlotType)                         | 支持 | 支持 | 支持   | 支持     |
| Notification.addSlots(slots: Array<NotificationSlot>, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.addSlots(slots: Array<NotificationSlot>)        | 支持 | 支持 | 支持   | 支持     |
| Notification.getSlot(slotType: SlotType, callback: AsyncCallback<NotificationSlot>) | 支持 | 支持 | 支持   | 支持     |
| Notification.getSlot(slotType: SlotType)                     | 支持 | 支持 | 支持   | 支持     |
| Notification.getSlots(callback: AsyncCallback<Array<NotificationSlot>>) | 支持 | 支持 | 支持   | 支持     |
| Notification.getSlots()                                      | 支持 | 支持 | 支持   | 支持     |
| Notification.removeSlot(slotType: SlotType, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.removeSlot(slotType: SlotType)                  | 支持 | 支持 | 支持   | 支持     |
| Notification.removeAllSlots(callback: AsyncCallback<void>): void | 支持 | 支持 | 支持   | 支持     |
| Notification.removeAllSlots(): Promise<void>                 | 支持 | 支持 | 支持   | 支持     |
| Notification.subscribe(subscriber: NotificationSubscriber, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.subscribe(subscriber: NotificationSubscriber, info: NotificationSubscribeInfo, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.subscribe(subscriber: NotificationSubscriber, info?: NotificationSubscribeInfo) | 支持 | 支持 | 支持   | 支持     |
| Notification.unsubscribe(subscriber: NotificationSubscriber, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.unsubscribe(subscriber: NotificationSubscriber) | 支持 | 支持 | 支持   | 支持     |
| Notification.enableNotification(bundle: BundleOption, enable: boolean, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.enableNotification(bundle: BundleOption, enable: boolean) | 支持 | 支持 | 支持   | 支持     |
| Notification.isNotificationEnabled(bundle: BundleOption, callback: AsyncCallback<boolean>) | 支持 | 支持 | 支持   | 支持     |
| Notification.isNotificationEnabled(bundle: BundleOption)     | 支持 | 支持 | 支持   | 支持     |
| Notification.isNotificationEnabled(callback: AsyncCallback<boolean>) | 支持 | 支持 | 支持   | 支持     |
| Notification.isNotificationEnabled()                         | 支持 | 支持 | 支持   | 支持     |
| Notification.displayBadge(bundle: BundleOption, enable: boolean, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.displayBadge(bundle: BundleOption, enable: boolean) | 支持 | 支持 | 支持   | 支持     |
| Notification.isBadgeDisplayed(bundle: BundleOption, callback: AsyncCallback<boolean>) | 支持 | 支持 | 支持   | 支持     |
| Notification.isBadgeDisplayed(bundle: BundleOption)          | 支持 | 支持 | 支持   | 支持     |
| Notification.setSlotByBundle(bundle: BundleOption, slot: NotificationSlot, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.setSlotByBundle(bundle: BundleOption, slot: NotificationSlot) | 支持 | 支持 | 支持   | 支持     |
| Notification.getSlotsByBundle(bundle: BundleOption, callback: AsyncCallback<Array<NotificationSlot>>) | 支持 | 支持 | 支持   | 支持     |
| Notification.getSlotsByBundle(bundle: BundleOption)          | 支持 | 支持 | 支持   | 支持     |
| Notification.getSlotNumByBundle(bundle: BundleOption, callback: AsyncCallback<number>) | 支持 | 支持 | 支持   | 支持     |
| Notification.getSlotNumByBundle(bundle: BundleOption)        | 支持 | 支持 | 支持   | 支持     |
| Notification.remove(bundle: BundleOption, notificationKey: NotificationKey, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.remove(bundle: BundleOption, notificationKey: NotificationKey) | 支持 | 支持 | 支持   | 支持     |
| Notification.remove(hashCode: string, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.remove(hashCode: string)                        | 支持 | 支持 | 支持   | 支持     |
| Notification.removeAll(bundle: BundleOption, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.removeAll(callback: AsyncCallback<void>)        | 支持 | 支持 | 支持   | 支持     |
| Notification.removeAll(bundle?: BundleOption)                | 支持 | 支持 | 支持   | 支持     |
| Notification.getAllActiveNotifications(callback: AsyncCallback<Array<NotificationRequest>>) | 支持 | 支持 | 支持   | 支持     |
| Notification.getAllActiveNotifications()                     | 支持 | 支持 | 支持   | 支持     |
| Notification.getActiveNotificationCount(callback: AsyncCallback<number>) | 支持 | 支持 | 支持   | 支持     |
| Notification.getActiveNotificationCount()                    | 支持 | 支持 | 支持   | 支持     |
| Notification.getActiveNotifications(callback: AsyncCallback<Array<NotificationRequest>>) | 支持 | 支持 | 支持   | 支持     |
| Notification.getActiveNotifications()                        | 支持 | 支持 | 支持   | 支持     |
| WantAgent.getWantAgent(info: WantAgentInfo, callback: AsyncCallback<WantAgent>) | 支持 | 支持 | 支持   | 支持     |
| WantAgent.getWantAgent(info: WantAgentInfo): Promise<WantAgent> | 支持 | 支持 | 支持   | 支持     |
| WantAgent.getBundleName(agent: WantAgent, callback: AsyncCallback<string>) | 支持 | 支持 | 支持   | 支持     |
| WantAgent.getBundleName(agent: WantAgent): Promise<string>   | 支持 | 支持 | 支持   | 支持     |
| WantAgent.getUid(agent: WantAgent, callback: AsyncCallback<number>) | 支持 | 支持 | 支持   | 支持     |
| WantAgent.getUid(agent: WantAgent): Promise<number>          | 支持 | 支持 | 支持   | 支持     |
| WantAgent.getWant(agent: WantAgent, callback: AsyncCallback<Want>) | 支持 | 支持 | 支持   | 支持     |
| WantAgent.getWant(agent: WantAgent): Promise<Want>           | 支持 | 支持 | 支持   | 支持     |
| WantAgent.cancel(agent: WantAgent, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| WantAgent.cancel(agent: WantAgent): Promise<void>            | 支持 | 支持 | 支持   | 支持     |
| WantAgent.trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback<CompleteData>) | 支持 | 支持 | 支持   | 支持     |
| WantAgent.equal(agent: WantAgent, otherAgent: WantAgent, callback: AsyncCallback<boolean>) | 支持 | 支持 | 支持   | 支持     |
| WantAgent.equal(agent: WantAgent, otherAgent: WantAgent): Promise<boolean> | 支持 | 支持 | 支持   | 支持     |

#### 权限列表

无

#### 通知接口

#### 导入模块

```js
import notify from '@ohos.notification';
```

#### Notification.publish(request: NotificationRequest, callback: AsyncCallback<void>)

- 接口说明

  发布通知（callback形式）

- publish参数描述


| 名称     | 读写属性 | 类型                | 必填 | 描述                                        |
| -------- | -------- | ------------------- | ---- | ------------------------------------------- |
| request  | 只读     | NotificationRequest | 是   | 设置要发布通知内容的NotificationRequest对象 |
| callback | 只读     | AsyncCallback<void> | 是   | 被指定的回调方法                            |

- NotificationRequest类型说明

| 名称              | 读写属性 | 类型                            | 必填 | 描述                       |
| ----------------- | -------- | ------------------------------- | ---- | -------------------------- |
| content           | 读、写   | NotificationContent             | 是   | 通知内容                   |
| id                | 读、写   | number                          | 否   | 通知ID                     |
| slotType          | 读、写   | SlotType                        | 否   | 通道类型                   |
| isOngoing         | 读、写   | boolean                         | 否   | 是否进行时通知             |
| isUnremovable     | 读、写   | boolean                         | 否   | 是否可移除                 |
| deliveryTime      | 读、写   | number                          | 否   | 通知发送时间               |
| tapDismissed      | 读、写   | boolean                         | 否   | 通知是否自动清除           |
| autoDeletedTime   | 读、写   | number                          | 否   | 自动清除的时间             |
| wantAgent         | 读、写   | WantAgent                       | 否   | 点击跳转的WantAgent        |
| extraInfo         | 读、写   | {[key: string]: any}            | 否   | 扩展参数                   |
| color             | 读、写   | number                          | 否   | 通知背景颜色               |
| colorEnabled      | 读、写   | boolean                         | 否   | 通知背景颜色是否使能       |
| isAlertOnce       | 读、写   | boolean                         | 否   | 设置是否仅有一次此通知警报 |
| isStopwatch       | 读、写   | boolean                         | 否   | 是否显示已用时间           |
| isCountDown       | 读、写   | boolean                         | 否   | 是否显示倒计时时间         |
| isFloatingIcon    | 读、写   | boolean                         | 否   | 是否显示状态栏图标         |
| isFloatingIcon    | 读、写   | boolean                         | 否   | 是否显示状态栏图标         |
| label             | 读、写   | string                          | 否   | 通知标签                   |
| badgeIconStyle    | 读、写   | number                          | 否   | 通知角标类型               |
| showDeliveryTime  | 读、写   | boolean                         | 否   | 是否显示分发时间           |
| actionButtons     | 读、写   | Array<NotificationActionButton> | 否   | 通知按钮，最多两个按钮     |
| smallIcon         | 读、写   | PixelMap                        | 否   | 通知小图标                 |
| largeIcon         | 读、写   | PixelMap                        | 否   | 通知大图标                 |
| creatorBundleName | 只读     | string                          | 否   | 创建通知的包名             |
| creatorUid        | 只读     | number                          | 否   | 创建通知的UID              |
| creatorPid        | 只读     | number                          | 否   | 创建通知的PID              |
| hashCode          | 只读     | string                          | 否   | 通知唯一标识               |
| classification    | 读、写   | string                          | 否   | 通知分类                   |

NotificationContent类型说明

| 名称        | 读写属性 | 类型                         | 必填 | 描述           |
| ----------- | -------- | ---------------------------- | ---- | -------------- |
| contentType | 读、写   | ContentType                  | 是   | 通知内容类型   |
| normal      | 读、写   | NotificationBasicContent     | 否   | 通知基本内容   |
| longText    | 读、写   | NotificationLongTextContent  | 否   | 通知长文本内容 |
| multiLine   | 读、写   | NotificationMultiLineContent | 否   | 通知多行内容   |

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

| 名称           | 读写属性 | 类型          | 必填 | 描述                             |
| -------------- | -------- | ------------- | ---- | -------------------------------- |
| title          | 读、写   | string        | 是   | 通知标题                         |
| text           | 读、写   | string        | 是   | 通知内容                         |
| additionalText | 读、写   | string        | 是   | 通知次要内容，是对通知内容的补充 |
| briefText      | 读、写   | string        | 是   | 通知概要内容，是对通知内容的总结 |
| longTitle      | 读、写   | string        | 是   | 通知展开时的标题                 |
| lines          | 读、写   | Array<String> | 是   | 通知的多行文本                   |

- NotificationPictureContent类型说明

| 名称           | 读写属性 | 类型           | 必填 | 描述                             |
| -------------- | -------- | -------------- | ---- | -------------------------------- |
| title          | 读、写   | string         | 是   | 通知标题                         |
| text           | 读、写   | string         | 是   | 通知内容                         |
| additionalText | 读、写   | string         | 是   | 通知次要内容，是对通知内容的补充 |
| briefText      | 读、写   | string         | 是   | 通知概要内容，是对通知内容的总结 |
| expandedTitle  | 读、写   | string         | 是   | 通知展开时的标题                 |
| picture        | 读、写   | image.PixelMap | 是   | 通知的图片内容                   |

- NotificationActionButton类型说明

| 名称      | 读写属性 | 类型           | 必填 | 描述                      |
| --------- | -------- | -------------- | ---- | ------------------------- |
| title     | 读、写   | string         | 是   | 按钮标题                  |
| wantAgent | 读、写   | wantAgent      | 是   | 点击按钮时触发的WantAgent |
| extras    | 读、写   | Array<String>  | 否   | 按钮扩展信息              |
| icon      | 读、写   | image.PixelMap | 否   | 按钮图标                  |

- 

  返回值为void

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



#### Notification.publish(request: NotificationRequest)

- 接口说明

  发布通知（Promise形式）

- 

  返回值为Promise<**void**>

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



#### Notification.cancel(id: number, label: string, callback: AsyncCallback<void>)

- 接口说明

  取消与指定id和label相匹配的已发布通知（callback形式）

- cancel参数描述

  | 名称     | 读写属性 | 类型                | 必填 | 描述                 |
  | -------- | -------- | ------------------- | ---- | -------------------- |
  | id       | 只读     | number              | 是   | 通知ID               |
  | lable    | 只读     | string              | 是   | 通知标签             |
  | callback | 只读     | AsyncCallback<void> | 是   | 表示被指定的回调方法 |

- 

  返回值为void

- 示例

```js
//cancel回调
function cancelCallback(err) {
	console.info("==========================>cancelCallback=======================>");
}
Notification.cancel(0, "label", cancelCallback)
```



#### Notification.cancel(id：number, label？：string）

- 接口说明

  取消与指定id相匹配的已发布通知,label可以指定也可以不指定（Promise形式)

- cancel参数描述

  | 名称  | 读写属性 | 类型   | 必填 | 描述     |
  | ----- | -------- | ------ | ---- | -------- |
  | id    | 只读     | number | 是   | 通知ID   |
  | lable | 只读     | string | 是   | 通知标签 |

- 

  返回值为Promise<**void**>

- 示例

```js
Notification.cancel(0).then((void) => {
	console.info("==========================>cancelCallback=======================>");
});
```



#### Notification.cancel(id: number, callback: AsyncCallback<void>)

- 接口说明

  取消与指定id相匹配的已发布通知（callback形式)

- cancel参数描述

  | 名称     | 读写属性 | 类型                | 必填 | 描述                 |
  | -------- | -------- | ------------------- | ---- | -------------------- |
  | id       | 只读     | number              | 是   | 通知ID               |
  | callback | 只读     | AsyncCallback<void> | 是   | 表示被指定的回调方法 |

- 

  返回值为void

- 示例

```js
//cancel回调
function cancelCallback(err) {
	console.info("==========================>cancelCallback=======================>");
}
Notification.cancel(0, cancelCallback)
```



#### Notification.cancelAll(callback: AsyncCallback<void>)

- 接口说明

  取消所有已发布的通知（callback形式)

- cancelAll参数描述

  | 名称     | 读写属性 | 类型                | 必填 | 描述                 |
  | -------- | -------- | ------------------- | ---- | -------------------- |
  | callback | 只读     | AsyncCallback<void> | 是   | 表示被指定的回调方法 |

- 

  返回值为void

- 示例

```js
//cancel回调
function cancelAllback(err) {
	console.info("==========================>cancelAllback=======================>");
}
Notification.cancelAll(cancelCallback)
```



#### Notification.cancelAll()

- 接口说明

  取消所有已发布的通知（callback形式)

- 参数描述

  无参数

- 

  返回值为void

- 示例

```js
Notification.cancelAll().then((void) => {
	console.info("==========================>cancelAllback=======================>");
});
```

#### Notification.addSlot(type: SlotType, callback: AsyncCallback<void>)

- 接口说明

  创建通知通道（callback形式)

- addSlot参数描述

  | 名称     | 读写属性 | 类型                | 必填 | 描述                   |
  | -------- | -------- | ------------------- | ---- | ---------------------- |
  | type     | 只读     | SlotType            | 是   | 要创建的通知通道的类型 |
  | callback | 只读     | AsyncCallback<void> | 是   | 表示被指定的回调方法   |

- SlotType类型说明

| 名称                 | 读写属性 | 类型     | 必填 | 描述     |
| -------------------- | -------- | -------- | ---- | -------- |
| SOCIAL_COMMUNICATION | 只读     | SlotType | 否   | 社交类型 |
| SERVICE_INFORMATION  | 只读     | SlotType | 否   | 服务类型 |
| CONTENT_INFORMATION  | 只读     | SlotType | 否   | 内容类型 |
| OTHER_TYPES          | 只读     | SlotType | 否   | 其他类型 |

* 

  返回值为void

* 示例

```js
//addslot回调
function addSlotCallBack(err) {
	console.info("==========================>addSlotCallBack=======================>");
}
Notification.addSlot(SOCIAL_COMMUNICATION, addSlotCallBack)
```



#### Notification.addSlot(type: SlotType)

- 接口说明

  创建通知通道（Promise形式)

- addSlot参数描述

  | 名称 | 读写属性 | 类型     | 必填 | 描述                   |
  | ---- | -------- | -------- | ---- | ---------------------- |
  | type | 只读     | SlotType | 是   | 要创建的通知通道的类型 |

- 

  返回值为Promise<**void**>

- 示例

```js
Notification.addSlot(SOCIAL_COMMUNICATION).then((void) => {
	console.info("==========================>addSlotCallback=======================>");
});
```

#### Notification.getSlot(slotType: SlotType, callback: AsyncCallback<NotificationSlot>)

- 接口说明

  获取一个通知通道（callback形式)

- getSlot参数描述

  | 名称     | 读写属性 | 类型                            | 必填 | 描述                                                        |
  | -------- | -------- | ------------------------------- | ---- | ----------------------------------------------------------- |
  | slotType | 只读     | slotType                        | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型 |
  | callback | 只读     | AsyncCallback<NotificationSlot> | 是   | 表示被指定的回调方法                                        |

- 

  返回值为void

- 示例

```js
//getSlot回调
function getSlotCallback(err,data) {
	console.info("==========================>getSlotCallback=======================>");
}
var slotType = SOCIAL_COMMUNICATION;
Notification.getSlot(slotType, getSlotCallback)
```



#### Notification.getSlot(slotType)

- 接口说明

  获取一个通知通道（Promise形式)

* getSlot参数描述

  | 名称     | 读写属性 | 类型     | 必填 | 描述                                                        |
  | -------- | -------- | -------- | ---- | ----------------------------------------------------------- |
  | slotType | 只读     | slotType | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型 |

* 

  返回值为Promise<NotificationSlot>

* 示例

```js
var slotType = SOCIAL_COMMUNICATION;
Notification.getSlot(slotType).then((data) => {
	console.info("==========================>getSlotCallback=======================>");
```



#### Notification.getSlots(callback: AsyncCallback<Array<NotificationSlot>>)

- 接口说明

  获取此应用程序的所有通知通道（callback形式)

- getSlots参数描述

  | 名称     | 读写属性 | 类型                            | 必填 | 描述                 |
  | -------- | -------- | ------------------------------- | ---- | -------------------- |
  | callback | 只读     | AsyncCallback<NotificationSlot> | 是   | 表示被指定的回调方法 |

- 

  返回值为void

- 示例

```js
//getSlots回调
function getSlotsCallback(err,data) {
	console.info("==========================>getSlotsCallback=======================>");
}
Notification.getSlots(getSlotsCallback)
```



#### Notification.getSlots()

- 接口说明

  获取此应用程序的所有通知通道（Promise形式)

- getSlots参数描述

  无参数

- 

  返回值为Promise<Array<NotificationSlot>>

- 示例

```js
Notification.getSlots().then((data) => {
	console.info("==========================>getSlotsCallback=======================>");
```



#### Notification.removeSlot(slotType: SlotType, callback: AsyncCallback<void>)

- 接口说明

  根据通知通道类型删除创建的通知通道（callback形式)

- removeSlot参数描述

  | 名称     | 读写属性 | 类型                | 必填 | 描述                                                        |
  | -------- | -------- | ------------------- | ---- | ----------------------------------------------------------- |
  | SlotType | 只读     | SlotType            | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型 |
  | callback | 只读     | AsyncCallback<void> | 是   | 表示被指定的回调方法                                        |

- 

  返回值为void

- 示例

```js
//removeSlot回调
function removeSlotCallback(err) {
	console.info("==========================>removeSlotCallback=======================>");
}
var slotType = SOCIAL_COMMUNICATION;
Notification.removeSlot(slotType,removeSlotCallback)
```



#### Notification.removeSlot(slotType: SlotType)

- 接口说明

  根据通知通道类型删除创建的通知通道（Promise形式)

- removeSlot参数描述

  | 名称     | 读写属性 | 类型     | 必填 | 描述                                                        |
  | -------- | -------- | -------- | ---- | ----------------------------------------------------------- |
  | SlotType | 只读     | SlotType | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型 |

- 

  返回值为Promise<**void**>

- 示例

```js
var slotType = SOCIAL_COMMUNICATION;
Notification.removeSlot(slotType).then((void) => {
	console.info("==========================>removeSlotCallback=======================>");
```



#### Notification.removeAllSlots(callback: AsyncCallback<void>)

- 接口说明

  删除所有通知通道（callback形式)

- removeAllSlots参数描述

  | 名称     | 读写属性 | 类型                | 必填 | 描述                 |
  | -------- | -------- | ------------------- | ---- | -------------------- |
  | callback | 只读     | AsyncCallback<void> | 是   | 表示被指定的回调方法 |

- 

  返回值为void

- 示例

```js
function removeAllCallBack(err) {
	console.info("================>removeAllCallBack=======================>");
}
Notification.removeAllSlots(removeAllCallBack)
```



#### Notification.removeAllSlots()

- 接口说明

  删除所有通知通道（Promise形式)

- removeAllSlots参数描述

  参数无

- 

  返回值为Promise<**void**>

- 示例

```js

Notification.removeAllSlots().then((void) => {
	console.info("==========================>removeAllCallBack=======================>");
});
```

#### Notification.getAllActiveNotifications(callback: AsyncCallback<Array<NotificationRequest>>)

- 接口说明

  获取活动通知（Callback形式)

- getAllActiveNotifications参数描述

  | 名称     | 读写属性 | 类型                                      | 必填 | 描述                 |
  | -------- | -------- | ----------------------------------------- | ---- | -------------------- |
  | callback | 只读     | AsyncCallback<Array<NotificationRequest>> | 是   | 获取活动通知回调函数 |

- 

  返回值为void

- 示例

```js
function getAllActiveNotificationsCallback(err, data) {
	console.info("==========================>getAllActiveNotificationsCallback=======================>");
}

Notification.getAllActiveNotifications(getAllActiveNotificationsCallback);
```



#### Notification.getAllActiveNotifications()

- 接口说明

  获取活动通知（Promise形式)

- getAllActiveNotifications参数描述

  无

- 

  返回值为Promise<Array<NotificationRequest>>

- 示例

```js
Notification.getAllActiveNotifications().then((data) => {
	console.info("==========================>getAllActiveNotificationsCallback=======================>");
});
```



#### Notification.getActiveNotificationCount(callback: AsyncCallback<**number**>)

- 接口说明

  获取当前应用的活动通知数（Callback形式)

- getActiveNotificationCount参数描述

  | 名称     | 读写属性 | 类型                      | 必填 | 描述                   |
  | -------- | -------- | ------------------------- | ---- | ---------------------- |
  | callback | 只读     | AsyncCallback<**number**> | 是   | 获取活动通知数回调函数 |

- 

  返回值为void

- 示例

```js
function getActiveNotificationCountCallback(err, data) {
	console.info("==========================>getActiveNotificationCountCallback=======================>");
}

Notification.getActiveNotificationCount(getActiveNotificationCountCallback);
```



#### Notification.getActiveNotificationCount()

- 接口说明

  获取当前应用的活动通知数（Promise形式)

- getActiveNotificationCount参数描述

  无

- 

  返回值为Promise<**number**>

- 示例

```js
Notification.getActiveNotificationCount().then((data) => {
	console.info("==========================>getActiveNotificationCountCallback=======================>");
});
```



#### Notification.getActiveNotifications(callback: AsyncCallback<Array<NotificationRequest>>)

- 接口说明

  获取当前应用的活动通知（Callback形式)

- getActiveNotifications参数描述

  | 名称     | 读写属性 | 类型                                      | 必填 | 描述                           |
  | -------- | -------- | ----------------------------------------- | ---- | ------------------------------ |
  | callback | 只读     | AsyncCallback<Array<NotificationRequest>> | 是   | 获取当前应用的活动通知回调函数 |

- 

  返回值为void

- 示例

```js
function getActiveNotificationsCallback(err, data) {
	console.info("==========================>getActiveNotificationsCallback=======================>");
}

Notification.getActiveNotifications(getActiveNotificationsCallback);
```



#### Notification.getActiveNotifications()

- 接口说明

  获取当前应用的活动通知（Promise形式)

- getActiveNotifications参数描述

  无

- 

  返回值为Promise<Array<NotificationRequest>>

- 示例

```js
Notification.getActiveNotifications().then((data) => {
	console.info("==========================>getActiveNotificationsCallback=======================>");
});
```



#### WantAgent接口

#### 导入模块

```js
import WantAgent from '@ohos.wantAgent';
```

#### WantAgent.getWantAgent(info: WantAgentInfo, callback: AsyncCallback<WantAgent>)

- 接口说明

  创建WantAgent（callback形式）

- getWantAgent参数描述


| 名称     | 读写属性 | 类型                     | 必填 | 描述                    |
| -------- | -------- | ------------------------ | ---- | ----------------------- |
| info     | 只读     | WantAgentInfo            | 是   | WantAgent信息           |
| callback | 只读     | AsyncCallback<WantAgent> | 是   | 创建WantAgent的回调方法 |

- WantAgentInfo类型说明

| 名称           | 读写属性 | 类型                            | 必填 | 描述                   |
| -------------- | -------- | ------------------------------- | ---- | ---------------------- |
| wants          | 读、写   | Array<Want>                     | 是   | 将被执行的动作列表     |
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
| REPLACE_ELEMENT     | 只读     | enum | 否   | 当前Want中的element属性可被WantAgent.trigger()中Want的element属性取代 |
| REPLACE_ACTION      | 只读     | enum | 否   | 当前Want中的action属性可被WantAgent.trigger()中Want的action属性取代 |
| REPLACE_URI         | 只读     | enum | 否   | 当前Want中的uri属性可被WantAgent.trigger()中Want的uri属性取代 |
| REPLACE_ENTITIES    | 只读     | enum | 否   | 当前Want中的entities属性可被WantAgent.trigger()中Want的entities属性取代 |
| REPLACE_BUNDLE      | 只读     | enum | 否   | 当前Want中的bundleName属性可被WantAgent.trigger()中Want的bundleName属性取代 |

- OperationType类型说明

| 名称              | 读写属性 | 类型 | 必填 | 描述                    |
| ----------------- | -------- | ---- | ---- | ----------------------- |
| UNKNOWN_TYPE      | 只读     | enum | 否   | 不识别的类型            |
| START_ABILITY     | 只读     | enum | 否   | 开启一个有页面的Ability |
| START_ABILITIES   | 只读     | enum | 否   | 开启多个有页面的Ability |
| START_SERVICE     | 只读     | enum | 否   | 开启一个无页面的ability |
| SEND_COMMON_EVENT | 只读     | enum | 否   | 发送一个公共事件        |

- 

  返回值为void

- 示例

```js
import wantAgent from '@ohos.wantAgent';
import { OperationType, Flags } from '@ohos.wantagent';

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
    wantAgentFlags:[Flags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)
```



#### WantAgent.getWantAgent(info: WantAgentInfo): Promise<WantAgent>

- 接口说明

  创建WantAgent（Promise形式）

- getWantAgent参数描述


| 名称 | 读写属性 | 类型          | 必填 | 描述          |
| ---- | -------- | ------------- | ---- | ------------- |
| info | 只读     | WantAgentInfo | 是   | WantAgent信息 |

- 

  返回值为Promise<WantAgent>

- 示例

```js
import wantAgent from '@ohos.wantAgent';
import { OperationType, Flags } from '@ohos.wantagent';

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
    wantAgentFlags:[Flags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
});
```



#### WantAgent.getBundleName(agent: WantAgent, callback: AsyncCallback<string>)

- 接口说明

  获取WantAgent实例的包名（callback形式）

- getBundleName参数描述


| 名称     | 读写属性 | 类型                  | 必填 | 描述                              |
| -------- | -------- | --------------------- | ---- | --------------------------------- |
| agent    | 只读     | WantAgent             | 是   | WantAgent对象                     |
| callback | 只读     | AsyncCallback<string> | 是   | 获取WantAgent实例的包名的回调方法 |

- 返回值为void

- 示例

```js
import wantAgent from '@ohos.wantAgent';
import { OperationType, Flags } from '@ohos.wantagent';

//wantAgent对象
var WantAgent;

//getWantAgent回调
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	WantAgent = data;
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
    wantAgentFlags:[Flags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

//getBundleName回调
function getBundleNameCallback(err, data) {
	console.info("==========================>getBundleNameCallback=======================>");
}
wantAgent.getBundleName(WantAgent, getBundleNameCallback)
```



#### WantAgent.getBundleName(agent: WantAgent): Promise<string>

- 接口说明

  获取WantAgent实例的包名（Promise形式）

- getBundleName参数描述


| 名称  | 读写属性 | 类型      | 必填 | 描述          |
| ----- | -------- | --------- | ---- | ------------- |
| agent | 只读     | WantAgent | 是   | WantAgent对象 |

- 

  返回值为Promise<string>

- 示例

```js
import wantAgent from '@ohos.wantAgent';
import { OperationType, Flags } from '@ohos.wantagent';

//wantAgent对象
var WantAgent;

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
    wantAgentFlags:[Flags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    WantAgent = data;
});

wantAgent.getBundleName(WantAgent).then((data) => {
	console.info("==========================>getBundleNameCallback=======================>");
});
```



#### WantAgent.getUid(agent: WantAgent, callback: AsyncCallback<number>)

- 接口说明

  获取WantAgent实例的用户ID（callback形式）

- getUid参数描述


| 名称     | 读写属性 | 类型                  | 必填 | 描述                                |
| -------- | -------- | --------------------- | ---- | ----------------------------------- |
| agent    | 只读     | WantAgent             | 是   | WantAgent对象                       |
| callback | 只读     | AsyncCallback<number> | 是   | 获取WantAgent实例的用户ID的回调方法 |

- 返回值为void

- 示例

```js
import wantAgent from '@ohos.wantAgent';
import { OperationType, Flags } from '@ohos.wantagent';

//wantAgent对象
var WantAgent;

//getWantAgent回调
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	WantAgent = data;
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
    wantAgentFlags:[Flags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

//getUid回调
function getUidCallback(err, data) {
	console.info("==========================>getUidCallback=======================>");
}
wantAgent.getUid(WantAgent, getUidCallback)
```



#### WantAgent.getUid(agent: WantAgent): Promise<number>

- 接口说明

  获取WantAgent实例的用户ID（Promise形式）

- getUid参数描述


| 名称  | 读写属性 | 类型      | 必填 | 描述          |
| ----- | -------- | --------- | ---- | ------------- |
| agent | 只读     | WantAgent | 是   | WantAgent对象 |

- 

  返回值为Promise<number>

- 示例

```js
import wantAgent from '@ohos.wantAgent';
import { OperationType, Flags } from '@ohos.wantagent';

//wantAgent对象
var WantAgent;

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
    wantAgentFlags:[Flags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    WantAgent = data;
});

wantAgent.getUid(WantAgent).then((data) => {
	console.info("==========================>getUidCallback=======================>");
});
```



#### WantAgent.cancel(agent: WantAgent, callback: AsyncCallback<void>)

- 接口说明

  取消WantAgent实例（callback形式）

- cancel参数描述


| 名称     | 读写属性 | 类型                | 必填 | 描述                        |
| -------- | -------- | ------------------- | ---- | --------------------------- |
| agent    | 只读     | WantAgent           | 是   | WantAgent对象               |
| callback | 只读     | AsyncCallback<void> | 是   | 取消WantAgent实例的回调方法 |

- 返回值为void

- 示例

```js
import wantAgent from '@ohos.wantAgent';
import { OperationType, Flags } from '@ohos.wantagent';

//wantAgent对象
var WantAgent;

//getWantAgent回调
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	WantAgent = data;
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
    wantAgentFlags:[Flags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

//cancel回调
function cancelCallback(err, data) {
	console.info("==========================>cancelCallback=======================>");
}
wantAgent.cancel(WantAgent, cancelCallback)
```



#### WantAgent.cancel(agent: WantAgent): Promise<void>

- 接口说明

  取消WantAgent实例（Promise形式）

- cancel参数描述


| 名称  | 读写属性 | 类型      | 必填 | 描述          |
| ----- | -------- | --------- | ---- | ------------- |
| agent | 只读     | WantAgent | 是   | WantAgent对象 |

- 

  返回值为Promise<void>

- 示例

```js
import wantAgent from '@ohos.wantAgent';
import { OperationType, Flags } from '@ohos.wantagent';

//wantAgent对象
var WantAgent;

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
    wantAgentFlags:[Flags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    WantAgent = data;
});

wantAgent.cancel(WantAgent).then((data) => {
	console.info("==========================>cancelCallback=======================>");
});
```



#### WantAgent.trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback<CompleteData>)

- 接口说明

  主动激发WantAgent实例（callback形式）

- trigger参数描述


| 名称        | 读写属性 | 类型                        | 必填 | 描述                            |
| ----------- | -------- | --------------------------- | ---- | ------------------------------- |
| agent       | 只读     | WantAgent                   | 是   | WantAgent对象                   |
| triggerInfo | 只读     | TriggerInfo                 | 是   | TriggerInfo对象                 |
| callback    | 只读     | AsyncCallback<CompleteData> | 是   | 主动激发WantAgent实例的回调方法 |

- TriggerInfo类型说明

| 名称       | 读写属性 | 类型                 | 必填 | 描述        |
| ---------- | -------- | -------------------- | ---- | ----------- |
| code       | 读、写   | number               | 是   | result code |
| want       | 读、写   | Want                 | 否   | Want        |
| permission | 读、写   | string               | 否   | 权限定义    |
| extraInfo  | 读、写   | {[key: string]: any} | 否   | 额外数据    |

- 返回值为void
- 示例

```js
import wantAgent from '@ohos.wantAgent';
import { OperationType, Flags } from '@ohos.wantagent';

//wantAgent对象
var WantAgent;

//getWantAgent回调
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	WantAgent = data;
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
    wantAgentFlags:[Flags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

//cancel回调
function triggerCallback(err, data) {
	console.info("==========================>triggerCallback=======================>");
}
wantAgent.trigger(WantAgent, triggerCallback)
```



#### WantAgent.equal(agent: WantAgent, otherAgent: WantAgent, callback: AsyncCallback<boolean>)

- 接口说明

  判断两个WantAgent实例是否相等（callback形式）

- equal参数描述


| 名称       | 读写属性 | 类型                   | 必填 | 描述                                    |
| ---------- | -------- | ---------------------- | ---- | --------------------------------------- |
| agent      | 只读     | WantAgent              | 是   | WantAgent对象                           |
| otherAgent | 只读     | WantAgent              | 是   | WantAgent对象                           |
| callback   | 只读     | AsyncCallback<boolean> | 是   | 判断两个WantAgent实例是否相等的回调方法 |

- 返回值为void

- 示例

```js
import wantAgent from '@ohos.wantAgent';
import { OperationType, Flags } from '@ohos.wantagent';

//wantAgent对象
var WantAgent1;
var WantAgent2;

//getWantAgent回调
function getWantAgentCallback(err, data) {
	console.info("==========================>getWantAgentCallback=======================>");
    if (err.code == 0) {
    	WantAgent1 = data;
        WantAgent2 = data;
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
    wantAgentFlags:[Flags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo, getWantAgentCallback)

//cancel回调
function equalCallback(err, data) {
	console.info("==========================>equalCallback=======================>");
}
wantAgent.equal(WantAgent1, WantAgent1, equalCallback)
```



#### WantAgent.equal(agent: WantAgent, otherAgent: WantAgent): Promise<boolean>

- 接口说明

  判断两个WantAgent实例是否相等（Promise形式）

- equal参数描述


| 名称       | 读写属性 | 类型      | 必填 | 描述          |
| ---------- | -------- | --------- | ---- | ------------- |
| agent      | 只读     | WantAgent | 是   | WantAgent对象 |
| otherAgent | 只读     | WantAgent | 是   | WantAgent对象 |

- 

  返回值为Promise<boolean>

- 示例

```js
import wantAgent from '@ohos.wantAgent';
import { OperationType, Flags } from '@ohos.wantagent';

//wantAgent对象
var WantAgent1;
var WantAgent2;

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
    wantAgentFlags:[Flags.UPDATE_PRESENT_FLAG]
}

wantAgent.getWantAgent(wantAgentInfo).then((data) => {
	console.info("==========================>getWantAgentCallback=======================>");
    WantAgent = data;
});

wantAgent.equal(WantAgent1, WantAgent2).then((data) => {
	console.info("==========================>equalCallback=======================>");
});
```



#### 



































