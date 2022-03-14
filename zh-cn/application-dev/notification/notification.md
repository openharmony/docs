

# Notification开发指导

#### 简介

OpenHarmony通过ANS（Advanced Notification Service，通知系统服务）对通知类型的消息进行管理，支持多种通知类型，包括文本，长文本，多文本，图片，社交，媒体等。所有系统服务以及应用都可以通过通知接口发送通知消息，用户可以通过SystemUI查看所有通知消息。

通知常见的使用场景：

- 显示接收到短消息、即时消息等。
- 显示应用的推送消息，如广告、版本更新等。
- 显示当前正在进行的事件，如导航、下载等。



#### 接口列表

| API                                                          | 手机 | 平板 | 智慧屏 | 智能穿戴 |
| ------------------------------------------------------------ | ---- | ---- | ------ | -------- |
| Notification.publish(request: NotificationRequest, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.publish(request: NotificationRequest)           | 支持 | 支持 | 支持   | 支持     |
| Notification.cancel(id: number, label: string, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.cancel(id：number, label？：string）            | 支持 | 支持 | 支持   | 支持     |
| Notification.cancel(id: number, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.cancelAll(callback: AsyncCallback<void>)        | 支持 | 支持 | 支持   | 支持     |
| Notification.cancelAll()                                     | 支持 | 支持 | 支持   | 支持     |
| Notification.addSlot(type: SlotType, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.addSlot(type: SlotType)                         | 支持 | 支持 | 支持   | 支持     |
| Notification.getSlot(slotType: SlotType, callback: AsyncCallback<NotificationSlot>) | 支持 | 支持 | 支持   | 支持     |
| Notification.getSlot(slotType: SlotType)                     | 支持 | 支持 | 支持   | 支持     |
| Notification.getSlots(callback: AsyncCallback<Array<NotificationSlot>>) | 支持 | 支持 | 支持   | 支持     |
| Notification.getSlots()                                      | 支持 | 支持 | 支持   | 支持     |
| Notification.removeSlot(slotType: SlotType, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| Notification.removeSlot(slotType: SlotType)                  | 支持 | 支持 | 支持   | 支持     |
| Notification.removeAllSlots(callback: AsyncCallback<void>): void | 支持 | 支持 | 支持   | 支持     |
| Notification.removeAllSlots(): Promise<void>                 | 支持 | 支持 | 支持   | 支持     |
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
| WantAgent.cancel(agent: WantAgent, callback: AsyncCallback<void>) | 支持 | 支持 | 支持   | 支持     |
| WantAgent.cancel(agent: WantAgent): Promise<void>            | 支持 | 支持 | 支持   | 支持     |
| WantAgent.trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback<CompleteData>) | 支持 | 支持 | 支持   | 支持     |
| WantAgent.equal(agent: WantAgent, otherAgent: WantAgent, callback: AsyncCallback<boolean>) | 支持 | 支持 | 支持   | 支持     |
| WantAgent.equal(agent: WantAgent, otherAgent: WantAgent): Promise<boolean> | 支持 | 支持 | 支持   | 支持     |



#### Notification接口

##### 导入模块

```js
import Notification from '@ohos.notification';
```



##### NotificationSlot类型说明

NotificationSlot可以对提示音、振动等进行设置。一个应用可以创建一个或多个NotificationSlot，在发布通知时，通过绑定不同的NotificationSlot，实现不同用途。

| 名称                 | 读写属性 | 类型          | 必填 | 描述                         |
| -------------------- | -------- | ------------- | ---- | ---------------------------- |
| type                 | 读、写   | SlotType      | 是   | 通道类型                     |
| level                | 读、写   | SlotLevel     | 否   | 通知级别                     |
| desc                 | 读、写   | string        | 否   | 通知渠道描述信息             |
| badgeFlag            | 读、写   | boolean       | 否   | 是否显示角标                 |
| bypassDnd            | 读、写   | boolean       | 否   | 置是否在系统中绕过免打扰模式 |
| lockscreenVisibility | 读、写   | boolean       | 否   | 在锁定屏幕上显示通知的模式   |
| vibrationEnabled     | 读、写   | boolean       | 否   | 是否可振动                   |
| sound                | 读、写   | string        | 否   | 通知提示音                   |
| lightEnabled         | 读、写   | boolean       | 否   | 是否闪灯                     |
| lightColor           | 读、写   | number        | 否   | 通知灯颜色                   |
| vibrationValues      | 读、写   | Array<number> | 否   | 通知振动样式                 |

- SlotType类型说明

| 名称                 | 读写属性 | 类型 | 描述     |
| -------------------- | -------- | ---- | -------- |
| SOCIAL_COMMUNICATION | 只读     | enum | 社交类型 |
| SERVICE_INFORMATION  | 只读     | enum | 服务类型 |
| CONTENT_INFORMATION  | 只读     | enum | 内容类型 |
| OTHER_TYPES          | 只读     | enum | 其他类型 |

- SlotLevel类型说明

| 名称          | 读写属性 | 类型 | 描述                                                         |
| ------------- | -------- | ---- | ------------------------------------------------------------ |
| LEVEL_NONE    | 只读     | enum | 表示通知不发布                                               |
| LEVEL_MIN     | 只读     | enum | 表示通知可以发布，但不在状态栏显示，不自动弹出，无提示音；该级别不适用于前台服务的场景 |
| LEVEL_LOW     | 只读     | enum | 表示通知发布后在状态栏显示，不自动弹出，无提示音             |
| LEVEL_DEFAULT | 只读     | enum | 表示通知发布后在状态栏显示，不自动弹出，触发提示音           |
| LEVEL_HIGH    | 只读     | enum | 表示通知发布后在状态栏显示，自动弹出，触发提示音             |



##### NotificationRequest类型说明

NotificationRequest用于设置具体的通知对象，包括设置通知的属性，如：通知的分发时间、小图标、大图标、自动删除等参数，以及设置具体的通知类型，如普通文本、长文本等。

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

- NotificationContent类型说明


| 名称        | 读写属性 | 类型                         | 必填 | 描述                 |
| ----------- | -------- | ---------------------------- | ---- | -------------------- |
| contentType | 读、写   | ContentType                  | 是   | 通知内容类型         |
| normal      | 读、写   | NotificationBasicContent     | 否   | 普通类型通知内容     |
| longText    | 读、写   | NotificationLongTextContent  | 否   | 长文本类型通知内容   |
| multiLine   | 读、写   | NotificationMultiLineContent | 否   | 多行文本类型通知内容 |
| picture     | 读、写   | NotificationPictureContent   | 否   | 图片类型通知内容     |

- ContentType类型说明

| 名称                              | 读写属性 | 类型 | 描述             |
| --------------------------------- | -------- | ---- | ---------------- |
| NOTIFICATION_CONTENT_BASIC_TEXT   | 只读     | enum | 普通类型通知     |
| NOTIFICATION_CONTENT_LONG_TEXT    | 只读     | enum | 长文本类型通知   |
| NOTIFICATION_CONTENT_PICTURE      | 只读     | enum | 图片类型通知     |
| NOTIFICATION_CONTENT_CONVERSATION | 只读     | enum | 社交类型通知     |
| NOTIFICATION_CONTENT_MULTILINE    | 只读     | enum | 多行文本类型通知 |

- NotificationBasicContent类型说明

| 名称           | 读写属性 | 类型   | 必填 | 描述                             |
| -------------- | -------- | ------ | ---- | -------------------------------- |
| title          | 读、写   | string | 是   | 通知标题                         |
| text           | 读、写   | string | 是   | 通知内容                         |
| additionalText | 读、写   | string | 是   | 通知次要内容，是对通知内容的补充 |

- NotificationLongTextContent类型说明

| 名称          | 读写属性 | 类型   | 必填 | 描述                   |
| ------------- | -------- | ------ | ---- | ---------------------- |
| title          | 读、写   | string | 是   | 通知标题                         |
| text           | 读、写   | string | 是   | 通知内容                         |
| additionalText | 读、写   | string | 是   | 通知次要内容，是对通知内容的补充 |
| longText      | 读、写   | string | 是   | 通知的长文本 |
| briefText     | 读、写   | string | 是   | 通知概要内容，是对通知内容的总结 |
| expandedTitle | 读、写   | string | 是   | 通知展开时的标题 |

- NotificationMultiLineContent类型说明

| 名称      | 读写属性 | 类型          | 必填 | 描述                   |
| --------- | -------- | ------------- | ---- | ---------------------- |
| title          | 读、写   | string | 是   | 通知标题                         |
| text           | 读、写   | string | 是   | 通知内容                         |
| additionalText | 读、写   | string | 是   | 通知次要内容，是对通知内容的补充 |
| briefText | 读、写   | string        | 是   | 通知概要内容，是对通知内容的总结 |
| longTitle | 读、写   | string        | 是   | 通知展开时的标题 |
| lines     | 读、写   | Array<String> | 是   | 通知的多行文本 |

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



##### 创建通知通道

- 创建通知通道（callback形式)

  Notification.addSlot(type: SlotType, callback: AsyncCallback<void>)

  - 参数描述

  | 名称     | 读写属性 | 类型                | 必填 | 描述                   |
  | -------- | -------- | ------------------- | ---- | ---------------------- |
  | type     | 只读     | SlotType            | 是   | 要创建的通知通道的类型 |
  | callback | 只读     | AsyncCallback<void> | 是   | 表示被指定的回调方法   |

  - 返回值

    void

  - 示例代码

  ```js
  //addslot回调
  function addSlotCallBack(err) {
  	console.info("==========================>addSlotCallBack=======================>");
  }
  Notification.addSlot(SOCIAL_COMMUNICATION, addSlotCallBack)
  ```



- 创建通知通道（Promise形式)

  Notification.addSlot(type: SlotType)

  - 参数描述

  | 名称 | 读写属性 | 类型     | 必填 | 描述                   |
  | ---- | -------- | -------- | ---- | ---------------------- |
  | type | 只读     | SlotType | 是   | 要创建的通知通道的类型 |

  - 返回值

    Promise<**void**>

  - 示例代码

  ```js
  Notification.addSlot(SOCIAL_COMMUNICATION).then((void) => {
  	console.info("==========================>addSlotCallback=======================>");
  });
  ```



##### 获取通知通道

- 获取一个通知通道（callback形式)

  Notification.getSlot(slotType: SlotType, callback: AsyncCallback<NotificationSlot>)

  - 参数描述

  | 名称     | 读写属性 | 类型                            | 必填 | 描述                                                        |
  | -------- | -------- | ------------------------------- | ---- | ----------------------------------------------------------- |
  | slotType | 只读     | slotType                        | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型 |
  | callback | 只读     | AsyncCallback<NotificationSlot> | 是   | 表示被指定的回调方法                                        |

  - 返回值

    void

  - 示例代码

  ```js
  //getSlot回调
  function getSlotCallback(err,data) {
  	console.info("==========================>getSlotCallback=======================>");
  }
  var slotType = SOCIAL_COMMUNICATION;
  Notification.getSlot(slotType, getSlotCallback)
  ```



- 获取一个通知通道（Promise形式)

  Notification.getSlot(slotType)

  - 参数描述

  | 名称     | 读写属性 | 类型     | 必填 | 描述                                                        |
  | -------- | -------- | -------- | ---- | ----------------------------------------------------------- |
  | slotType | 只读     | slotType | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型 |

  - 返回值

    Promise<NotificationSlot>

  - 示例代码

  ```js
  var slotType = SOCIAL_COMMUNICATION;
  Notification.getSlot(slotType).then((data) => {
  	console.info("==========================>getSlotCallback=======================>");
  });
  ```



- 获取本应用程序的所有通知通道（callback形式)

  Notification.getSlots(callback: AsyncCallback<Array<NotificationSlot>>)

  - 参数描述

  | 名称     | 读写属性 | 类型                            | 必填 | 描述                 |
  | -------- | -------- | ------------------------------- | ---- | -------------------- |
  | callback | 只读     | AsyncCallback<NotificationSlot> | 是   | 表示被指定的回调方法 |

  - 返回值

    void

  - 示例代码

  ```js
  //getSlots回调
  function getSlotsCallback(err,data) {
  	console.info("==========================>getSlotsCallback=======================>");
  }
  Notification.getSlots(getSlotsCallback)
  ```



- 获取此应用程序的所有通知通道（Promise形式)

  Notification.getSlots()

  - 参数描述

    无参数

  - 返回值

    Promise<Array<NotificationSlot>>

  - 示例代码

  ```js
  Notification.getSlots().then((data) => {
  	console.info("==========================>getSlotsCallback=======================>");
  });
  ```



##### 删除通知通道

- 根据通知通道类型删除通知通道（callback形式)

  Notification.removeSlot(slotType: SlotType, callback: AsyncCallback<void>)

  - 参数描述

  | 名称     | 读写属性 | 类型                | 必填 | 描述                                                        |
  | -------- | -------- | ------------------- | ---- | ----------------------------------------------------------- |
  | SlotType | 只读     | SlotType            | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型 |
  | callback | 只读     | AsyncCallback<void> | 是   | 表示被指定的回调方法                                        |

  - 返回值

    void

  - 示例代码

  ```js
  //removeSlot回调
  function removeSlotCallback(err) {
  	console.info("==========================>removeSlotCallback=======================>");
  }
  var slotType = SOCIAL_COMMUNICATION;
  Notification.removeSlot(slotType, removeSlotCallback)
  ```



- 根据通知通道类型删除通知通道（Promise形式)

  Notification.removeSlot(slotType: SlotType)

  - 参数描述

  | 名称     | 读写属性 | 类型     | 必填 | 描述                                                        |
  | -------- | -------- | -------- | ---- | ----------------------------------------------------------- |
  | SlotType | 只读     | SlotType | 是   | 通知渠道类型,目前分为社交通信、服务提醒、内容咨询和其他类型 |

  - 返回值

    Promise<**void**>

  - 示例代码

  ```js
  var slotType = SOCIAL_COMMUNICATION;
  Notification.removeSlot(slotType).then((void) => {
  	console.info("==========================>removeSlotCallback=======================>");
  });
  ```



- 删除所有通知通道（callback形式)

  Notification.removeAllSlots(callback: AsyncCallback<void>)

  - 参数描述

  | 名称     | 读写属性 | 类型                | 必填 | 描述                 |
  | -------- | -------- | ------------------- | ---- | -------------------- |
  | callback | 只读     | AsyncCallback<void> | 是   | 表示被指定的回调方法 |

  - 返回值

    void

  - 示例代码

  ```js
  function removeAllSlotsCallBack(err) {
  	console.info("================>removeAllSlotsCallBack=======================>");
  }
  Notification.removeAllSlots(removeAllCallBack)
  ```



- 删除所有通知通道（Promise形式)

  Notification.removeAllSlots()

  - 参数描述

    无参数

  - 返回值

    Promise<**void**>

  - 示例代码

  ```js
  Notification.removeAllSlots().then((void) => {
  	console.info("==========================>removeAllSlotsCallBack=======================>");
  });
  ```



##### 发布通知

- 发布通知（callback形式）

  Notification.publish(request: NotificationRequest, callback: AsyncCallback<void>)

  - 参数描述

  | 名称     | 读写属性 | 类型                | 必填 | 描述                                        |
  | -------- | -------- | ------------------- | ---- | ------------------------------------------- |
  | request  | 只读     | NotificationRequest | 是   | 设置要发布通知内容的NotificationRequest对象 |
  | callback | 只读     | AsyncCallback<void> | 是   | 被指定的回调方法                            |

  - 返回值

    void

  - 示例代码

  ```js
  //publish回调
  function publishCallback(err) {
  		console.info("==========================>publishCallback=======================>");
  }
  //通知Request对象
  var request = {
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
  Notification.publish(request, publishCallback);
  ```




- 发布通知（Promise形式）

  Notification.publish(request: NotificationRequest)

  - 参数描述

  | 名称    | 读写属性 | 类型                | 必填 | 描述                                        |
  | ------- | -------- | ------------------- | ---- | ------------------------------------------- |
  | request | 只读     | NotificationRequest | 是   | 设置要发布通知内容的NotificationRequest对象 |

  - 返回值

    Promise<**void**>

  - 示例代码

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
  ```

	console.info("==========================>publishCallback=======================>");
  });
  
  ```
  
  ```



##### 取消通知

- 取消指定通知（callback形式）

  Notification.cancel(id: number, label: string, callback: AsyncCallback<void>)

  - 参数描述

  | 名称     | 读写属性 | 类型                | 必填 | 描述                 |
  | -------- | -------- | ------------------- | ---- | -------------------- |
  | id       | 只读     | number              | 是   | 通知ID               |
  | lable    | 只读     | string              | 是   | 通知标签             |
  | callback | 只读     | AsyncCallback<void> | 是   | 表示被指定的回调方法 |

  - 返回值

    void

  - 示例代码

  ```js
  //cancel回调
  function cancelCallback(err) {
  	console.info("==========================>cancelCallback=======================>");
  }
  Notification.cancel(0, "label", cancelCallback)
  ```



- 取消指定通知（Promise形式)

  Notification.cancel(id：number, label？：string）

  - 参数描述

  | 名称  | 读写属性 | 类型   | 必填 | 描述     |
  | ----- | -------- | ------ | ---- | -------- |
  | id    | 只读     | number | 是   | 通知ID   |
  | lable | 只读     | string | 是   | 通知标签 |

  - 返回值

    Promise<**void**>

  - 示例代码

  ```js
  Notification.cancel(0).then((void) => {
  	console.info("==========================>cancelCallback=======================>");
  });
  ```



- 取消指定id通知（callback形式)

  Notification.cancel(id: number, callback: AsyncCallback<void>)

  - 参数描述

  | 名称     | 读写属性 | 类型                | 必填 | 描述                 |
  | -------- | -------- | ------------------- | ---- | -------------------- |
  | id       | 只读     | number              | 是   | 通知ID               |
  | callback | 只读     | AsyncCallback<void> | 是   | 表示被指定的回调方法 |

  - 返回值

    void

  - 示例代码

  ```js
  //cancel回调
  function cancelCallback(err) {
  	console.info("==========================>cancelCallback=======================>");
  }
  Notification.cancel(0, cancelCallback)
  ```



- 取消所有已发布的通知（callback形式)

  Notification.cancelAll(callback: AsyncCallback<void>)

  - 参数描述

  | 名称     | 读写属性 | 类型                | 必填 | 描述                 |
  | -------- | -------- | ------------------- | ---- | -------------------- |
  | callback | 只读     | AsyncCallback<void> | 是   | 表示被指定的回调方法 |

  - 返回值

    void

  - 示例代码

  ```js
  //cancel回调
  function cancelAllback(err) {
  	console.info("==========================>cancelAllback=======================>");
  }
  Notification.cancelAll(cancelCallback)
  ```



- 取消所有已发布的通知（Promise形式)

  Notification.cancelAll()

  - 参数描述

    无参数

  - 返回值

    Promise<void>

  - 示例代码

  ```js
  Notification.cancelAll().then((void) => {
  ```

		console.info("==========================>cancelAllback=======================>");
  });
  
  ```
  
  ```



##### 获取当前应用活动通知

- 获取当前应用的活动通知数（Callback形式)

  Notification.getActiveNotificationCount(callback: AsyncCallback<**number**>)

  - 参数描述

  | 名称     | 读写属性 | 类型                      | 必填 | 描述                   |
  | -------- | -------- | ------------------------- | ---- | ---------------------- |
  | callback | 只读     | AsyncCallback<**number**> | 是   | 获取活动通知数回调函数 |

  - 返回值

    void

  - 示例代码

  ```js
  function getActiveNotificationCountCallback(err, data) {
  	console.info("==========================>getActiveNotificationCountCallback=======================>");
  }
  Notification.getActiveNotificationCount(getActiveNotificationCountCallback);
  ```



- 获取当前应用的活动通知数（Promise形式)

  Notification.getActiveNotificationCount()

  - 参数描述

    无

  - 返回值

    Promise<**number**>

  - 示例代码

  ```js
  Notification.getActiveNotificationCount().then((data) => {
  	console.info("==========================>getActiveNotificationCountCallback=======================>");
  });
  ```



- 获取当前应用的活动通知（Callback形式)

  Notification.getActiveNotifications(callback: AsyncCallback<Array<NotificationRequest>>)

  - 参数描述

  | 名称     | 读写属性 | 类型                                      | 必填 | 描述                           |
  | -------- | -------- | ----------------------------------------- | ---- | ------------------------------ |
  | callback | 只读     | AsyncCallback<Array<NotificationRequest>> | 是   | 获取当前应用的活动通知回调函数 |

  - 返回值

    void

  - 示例代码

  ```js
  function getActiveNotificationsCallback(err, data) {
  	console.info("==========================>getActiveNotificationsCallback=======================>");
  }
  Notification.getActiveNotifications(getActiveNotificationsCallback);
  ```



- 获取当前应用的活动通知（Promise形式)

  Notification.getActiveNotifications()

  - 参数描述

    无

  - 返回值

    Promise<Array<NotificationRequest>>

  - 示例代码

  ```js
  Notification.getActiveNotifications().then((data) => {
  	console.info("==========================>getActiveNotificationsCallback=======================>");
  });
  ```



#### WantAgent接口

##### 导入模块

```js
import WantAgent from '@ohos.wantAgent';
```



##### WantAgentInfo类型说明

WantAgentInfo类封装了获取一个WantAgent实例所需的数据。

| 名称           | 读写属性 | 类型                            | 必填 | 描述                   |
| -------------- | -------- | ------------------------------- | ---- | ---------------------- |
| wants          | 读、写   | Array<Want>                     | 是   | 将被执行的动作列表     |
| operationType  | 读、写   | wantAgent.OperationType         | 是   | 动作类型               |
| requestCode    | 读、写   | number                          | 是   | 使用者定义的一个私有值 |
| wantAgentFlags | 读、写   | Array<wantAgent.WantAgentFlags> | 否   | 动作执行属性           |
| extraInfo      | 读、写   | {[key: string]: any}            | 否   | 额外数据               |

- OperationType类型说明

| 名称              | 读写属性 | 类型 | 描述                    |
| ----------------- | -------- | ---- | ----------------------- |
| UNKNOWN_TYPE      | 只读     | enum | 不识别的类型            |
| START_ABILITY     | 只读     | enum | 开启一个有页面的Ability |
| START_ABILITIES   | 只读     | enum | 开启多个有页面的Ability |
| START_SERVICE     | 只读     | enum | 开启一个无页面的ability |
| SEND_COMMON_EVENT | 只读     | enum | 发送一个公共事件        |

- WantAgentFlags类型说明


| 名称                | 读写属性 | 类型 | 描述                                                         |
| ------------------- | -------- | ---- | ------------------------------------------------------------ |
| ONE_TIME_FLAG       | 只读     | enum | WantAgent仅能使用一次                                        |
| NO_BUILD_FLAG       | 只读     | enum | 如果描述WantAgent对象不存在，则不创建它，直接返回null        |
| CANCEL_PRESENT_FLAG | 只读     | enum | 在生成一个新的WantAgent对象前取消已存在的一个WantAgent对象   |
| UPDATE_PRESENT_FLAG | 只读     | enum | 使用新的WantAgent的额外数据替换已存在的WantAgent中的额外数据 |
| CONSTANT_FLAG       | 只读     | enum | WantAgent是不可变的                                          |
| REPLACE_ELEMENT     | 只读     | enum | 当前Want中的element属性可被WantAgent.trigger()中Want的element属性取代 |
| REPLACE_ACTION      | 只读     | enum | 当前Want中的action属性可被WantAgent.trigger()中Want的action属性取代 |
| REPLACE_URI         | 只读     | enum | 当前Want中的uri属性可被WantAgent.trigger()中Want的uri属性取代 |
| REPLACE_ENTITIES    | 只读     | enum | 当前Want中的entities属性可被WantAgent.trigger()中Want的entities属性取代 |
| REPLACE_BUNDLE      | 只读     | enum | 当前Want中的bundleName属性可被WantAgent.trigger()中Want的bundleName属性取代 |



##### TriggerInfo类型说明

TriggerInfo类封装了主动激发一个WantAgent实例所需的数据。

| 名称       | 读写属性 | 类型                 | 必填 | 描述        |
| ---------- | -------- | -------------------- | ---- | ----------- |
| code       | 读、写   | number               | 是   | result code |
| want       | 读、写   | Want                 | 否   | Want        |
| permission | 读、写   | string               | 否   | 权限定义    |
| extraInfo  | 读、写   | {[key: string]: any} | 否   | 额外数据    |



##### 创建WantAgent

- 创建WantAgent（callback形式）

  WantAgent.getWantAgent(info: WantAgentInfo, callback: AsyncCallback<WantAgent>)

  - 参数描述

  | 名称     | 读写属性 | 类型                     | 必填 | 描述                    |
  | -------- | -------- | ------------------------ | ---- | ----------------------- |
  | info     | 只读     | WantAgentInfo            | 是   | WantAgent信息           |
  | callback | 只读     | AsyncCallback<WantAgent> | 是   | 创建WantAgent的回调方法 |
  - 返回值
  
    void
  
  - 示例代码

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



- 创建WantAgent（Promise形式）

  WantAgent.getWantAgent(info: WantAgentInfo): Promise<WantAgent>

  - 参数描述

  | 名称 | 读写属性 | 类型          | 必填 | 描述          |
  | ---- | -------- | ------------- | ---- | ------------- |
  | info | 只读     | WantAgentInfo | 是   | WantAgent信息 |
  - 返回值

    Promise<WantAgent>

  - 示例代码

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
  ```

		console.info("==========================>getWantAgentCallback=======================>");
  });
  
  ```
  
  ```



##### 获取WantAgent实例的包名

- 获取WantAgent实例的包名（callback形式）

  WantAgent.getBundleName(agent: WantAgent, callback: AsyncCallback<string>)

  - 参数描述

  | 名称     | 读写属性 | 类型                  | 必填 | 描述                                     |
  | -------- | -------- | --------------------- | ---- | ---------------------------------------- |
  | agent    | 只读     | WantAgent             | 是   | WantAgent对象                            |
  | callback | 只读     | AsyncCallback<string> | 是   | 获取WantAgent指定的bundle name的回调方法 |

  - 返回值

    void

  - 示例代码

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



- 获取WantAgent实例的包名（Promise形式）

  WantAgent.getBundleName(agent: WantAgent): Promise<string>

  - 参数描述

  | 名称  | 读写属性 | 类型      | 必填 | 描述          |
  | ----- | -------- | --------- | ---- | ------------- |
  | agent | 只读     | WantAgent | 是   | WantAgent对象 |
  - 返回值

    Promise<string>

  - 示例代码

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




##### 获取WantAgent实例的用户ID

- 获取WantAgent实例的用户ID（callback形式）

  WantAgent.getUid(agent: WantAgent, callback: AsyncCallback<number>)

  - 参数描述

  | 名称     | 读写属性 | 类型                  | 必填 | 描述                                |
  | -------- | -------- | --------------------- | ---- | ----------------------------------- |
  | agent    | 只读     | WantAgent             | 是   | WantAgent对象                       |
  | callback | 只读     | AsyncCallback<number> | 是   | 获取WantAgent实例的用户ID的回调方法 |
  - 返回值

    void

  - 示例代码

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



- 获取WantAgent实例的用户ID（Promise形式）

  WantAgent.getUid(agent: WantAgent): Promise<number>

  - 参数描述

  | 名称  | 读写属性 | 类型      | 必填 | 描述          |
  | ----- | -------- | --------- | ---- | ------------- |
  | agent | 只读     | WantAgent | 是   | WantAgent对象 |
  - 返回值

    Promise<number>

  - 示例代码

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



##### 取消WantAgent实例

- 取消WantAgent实例（callback形式）

  WantAgent.cancel(agent: WantAgent, callback: AsyncCallback<void>)

  - 参数描述

  | 名称     | 读写属性 | 类型                | 必填 | 描述                        |
  | -------- | -------- | ------------------- | ---- | --------------------------- |
  | agent    | 只读     | WantAgent           | 是   | WantAgent对象               |
  | callback | 只读     | AsyncCallback<void> | 是   | 取消WantAgent实例的回调方法 |
  - 返回值

    void

  - 示例代码

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



- 取消WantAgent实例（Promise形式）

  WantAgent.cancel(agent: WantAgent): Promise<void>

  - 参数描述

  | 名称  | 读写属性 | 类型      | 必填 | 描述          |
  | ----- | -------- | --------- | ---- | ------------- |
  | agent | 只读     | WantAgent | 是   | WantAgent对象 |
  - 返回值

    Promise<void>

  - 示例代码

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




##### 主动激发WantAgent实例

- 主动激发WantAgent实例（callback形式）

  WantAgent.trigger(agent: WantAgent, triggerInfo: TriggerInfo, callback?: Callback<CompleteData>)

  - 参数描述

  | 名称        | 读写属性 | 类型                        | 必填 | 描述                            |
  | ----------- | -------- | --------------------------- | ---- | ------------------------------- |
  | agent       | 只读     | WantAgent                   | 是   | WantAgent对象                   |
  | triggerInfo | 只读     | TriggerInfo                 | 是   | TriggerInfo对象                 |
  | callback    | 只读     | AsyncCallback<CompleteData> | 是   | 主动激发WantAgent实例的回调方法 |
  - 返回值

    void

  - 示例代码

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




##### 判断两个WantAgent实例是否相等

- 判断两个WantAgent实例是否相等（callback形式）

  WantAgent.equal(agent: WantAgent, otherAgent: WantAgent, callback: AsyncCallback<boolean>)

  - 参数描述

  | 名称       | 读写属性 | 类型                   | 必填 | 描述                                    |
  | ---------- | -------- | ---------------------- | ---- | --------------------------------------- |
  | agent      | 只读     | WantAgent              | 是   | WantAgent对象                           |
  | otherAgent | 只读     | WantAgent              | 是   | WantAgent对象                           |
  | callback   | 只读     | AsyncCallback<boolean> | 是   | 判断两个WantAgent实例是否相等的回调方法 |
  - 返回值

    void

  - 示例代码

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



- 判断两个WantAgent实例是否相等（Promise形式）

  WantAgent.equal(agent: WantAgent, otherAgent: WantAgent): Promise<boolean>

  - 参数描述

  | 名称       | 读写属性 | 类型      | 必填 | 描述          |
  | ---------- | -------- | --------- | ---- | ------------- |
  | agent      | 只读     | WantAgent | 是   | WantAgent对象 |
  | otherAgent | 只读     | WantAgent | 是   | WantAgent对象 |
  - 返回值

    Promise<boolean>

  - 示例代码

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


























