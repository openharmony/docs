# 后台代理提醒开发指导

## 场景介绍

后台代理提醒主要提供后台提醒发布接口，开发者在应用开发时，可以调用这些接口去创建定时提醒，包括倒计时、日历、闹钟三种提醒类型。使用后台代理提醒能力后，应用可以被冻结或退出，计时和弹出提醒的功能将被后台系统服务代理。


## 接口说明

reminderAgentManager：封装了发布、取消提醒类通知的方法。

具体后台提醒相关功能接口请见[后台代理提醒](../reference/apis/js-apis-reminderAgentManager.md)。

**表1** reminderAgentManager主要接口

| 接口名 | 描述 |
| -------- | -------- |
| publishReminder(reminderReq:&nbsp;ReminderRequest,&nbsp;callback:&nbsp;AsyncCallback&lt;number&gt;):&nbsp;void<br/>publishReminder(reminderReq:&nbsp;ReminderRequest):&nbsp;Promise&lt;number&gt; | 发布一个定时提醒类通知。<br/>单个应用有效的提醒个数最多支持30个（不包括已经超时，即后续不会再提醒的提醒实例）<br/>整个系统有效的提醒个数最多支持2000个（不包括已经超时，即后续不会再提醒的提醒实例） |
| cancelReminder(reminderId:&nbsp;number,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void<br/>cancelReminder(reminderId:&nbsp;number):&nbsp;Promise&lt;void&gt; | 取消一个指定的提醒类通知。(reminderId从publishReminder的返回值获取) |
| getValidReminders(callback:&nbsp;AsyncCallback&lt;Array&lt;ReminderRequest&gt;&gt;):&nbsp;void<br/>getValidReminders():&nbsp;Promise&lt;Array&lt;ReminderRequest&gt;&gt; | 获取当前应用设置的所有有效的提醒。 |
| cancelAllReminders(callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void<br/>cancelAllReminders():&nbsp;Promise&lt;void&gt; | 取消当前应用设置的所有提醒 |
| addNotificationSlot(slot:&nbsp;NotificationSlot,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void<br/>addNotificationSlot(slot:&nbsp;NotificationSlot):&nbsp;Promise&lt;void&gt; | 注册一个提醒类需要使用的NotificationSlot |
| removeNotificationSlot(slotType:&nbsp;notification.SlotType,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void<br/>removeNotificationSlot(slotType:&nbsp;notification.SlotType):&nbsp;Promise&lt;void&gt; | 删除指定类型的NotificationSlot |

## 开发步骤

> **说明：**
>
> 1. 应用需要配置权限：ohos.permission.PUBLISH_AGENT_REMINDER。
>
> 2. 应用需要申请通知弹窗：[Notification.requestEnableNotification](../reference/apis/js-apis-notification.md#notificationrequestenablenotification8)。
>    只有用户授权后，提醒代理的功能才能使用。

1、定义目标提醒代理。

2、发布相应的提醒代理。

```ts
import reminderAgentManager from '@ohos.reminderAgentManager';
import notification from '@ohos.notification';

// 倒计时实例定义：
let timer : reminderAgentManager.ReminderRequestTimer = {
    reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER,
    triggerTimeInSeconds: 10,
    actionButton: [
        {
            title: "close",
            type: reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE
        }
    ],
    wantAgent: {
        pkgName: "com.example.device",
        abilityName: "com.example.device.MainAbility"
    },
    maxScreenWantAgent: {
        pkgName: "com.example.device",
        abilityName: "com.example.device.MainAbility"
    },
    title: "this is title",
    content: "this is content",
    expiredContent: "this reminder has expired",
    notificationId: 100,
    slotType: notification.SlotType.SOCIAL_COMMUNICATION
}

// 日历实例定义：
let calendar : reminderAgentManager.ReminderRequestCalendar = {
    reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_CALENDAR,
    dateTime: {
        year: 2050,
        month: 7,
        day: 30,
        hour: 11,
        minute: 14,
        second: 30
    },
    repeatMonths: [1],
    repeatDays: [1],
    actionButton: [
        {
            title: "close",
            type: reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE
        },
        {
            title: "snooze",
            type: reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_SNOOZE
        },
    ],
    wantAgent: {
        pkgName: "com.example.device",
        abilityName: "com.example.device.MainAbility"
    },
    maxScreenWantAgent: {
        pkgName: "com.example.device",
        abilityName: "com.example.device.MainAbility"
    },
    ringDuration: 5,
    snoozeTimes: 2,
    timeInterval: 5,
    title: "this is title",
    content: "this is content",
    expiredContent: "this reminder has expired",
    snoozeContent: "remind later",
    notificationId: 100,
    slotType: notification.SlotType.SOCIAL_COMMUNICATION
}

// 闹钟实例定义：
let alarm : reminderAgentManager.ReminderRequestAlarm = {
    reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_ALARM,
    hour: 11,
    minute: 14,
    daysOfWeek: [0],
    actionButton: [
        {
            title: "close",
            type: reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE
        },
        {
            title: "snooze",
            type: reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_SNOOZE
        },
    ],
    wantAgent: {
        pkgName: "com.example.device",
        abilityName: "com.example.device.MainAbility"
    },
    maxScreenWantAgent: {
        pkgName: "com.example.device",
        abilityName: "com.example.device.MainAbility"
    },
    ringDuration: 5,
    snoozeTimes: 2,
    timeInterval: 5,
    title: "this is title",
    content: "this is content",
    expiredContent: "this reminder has expired",
    snoozeContent: "remind later",
    notificationId: 100,
    slotType: notification.SlotType.SOCIAL_COMMUNICATION
}

@Entry
@Component
struct Index {
  @State message: string = 'test'

  publishReminder() {
    try {
        reminderAgentManager.publishReminder(timer).then(res => {
            console.log("publishReminder promise reminderId:" + res);
        }).catch(err => {
            console.log("publishReminder err code:" + err.code + " message:" + err.message);
        })
    } catch (error) {
        console.log("publishReminder code:" + error.code + " message:" + error.message);
    };
  }

  build() {
    Row() {
      Column() {
        Text("Index")
          .fontSize(50)
          .fontWeight(FontWeight.Bold)

        Button() { Text('倒计时提醒代理').fontSize(25).fontWeight(FontWeight.Bold) }.type(ButtonType.Capsule)
          .margin({ top: 10 }).backgroundColor('#0D9FFB').width(250).height(40)
          .onClick(() => {
          // 示例通过按钮控制提醒代理的发布
          this.publishReminder();
        })

      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 相关实例

基于后台代理提醒开发，有以下相关实例可供参考：

- [`AlarmClock`：后台代理提醒（ArkTS）（API8）](https://gitee.com/openharmony/app_samples/tree/master/Notification/AlarmClock)

- [`FlipClock`：翻页时钟（ArkTS）（API8）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/CompleteApps/FlipClock)

- [闹钟应用（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/CommonEventAndNotification/AlarmClock)