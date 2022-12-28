# Agent-Powered Scheduled Reminder Development

## When to Use

You can set your application to call the **ReminderRequest** class to create scheduled reminders for countdown timers, calendar events, and alarm clocks. When the created reminders are published, the timing and pop-up notification functions of your application will be taken over by the reminder agent in the background, even when your application is frozen or exits.


## Available APIs

**reminderAgentManager** encapsulates the APIs for publishing and canceling reminders.

For details about the APIs, see [reminderAgentManager](../reference/apis/js-apis-reminderAgentManager.md).

**Table 1** Major APIs in reminderAgentManager

| Name| Description|
| -------- | -------- |
| publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback&lt;number&gt;): void<br>publishReminder(reminderReq: ReminderRequest): Promise&lt;number&gt; | Publishes a scheduled reminder.<br>The maximum number of valid notifications (excluding expired ones that will not pop up again) is 30 for one application and 2000 for the entire system. |
| cancelReminder(reminderId: number, callback: AsyncCallback&lt;void&gt;): void<br>cancelReminder(reminderId: number): Promise&lt;void&gt; | Cancels a specified reminder. (The value of **reminderId** is obtained from the return value of **publishReminder**.)|
| getValidReminders(callback: AsyncCallback&lt;Array&lt;ReminderRequest&gt;&gt;): void<br>getValidReminders(): Promise&lt;Array&lt;ReminderRequest&gt;&gt; | Obtains all valid reminders set by the current application.|
| cancelAllReminders(callback: AsyncCallback&lt;void&gt;): void<br>cancelAllReminders(): Promise&lt;void&gt; | Cancels all reminders set by the current application.|
| addNotificationSlot(slot: NotificationSlot, callback: AsyncCallback&lt;void&gt;): void<br>addNotificationSlot(slot: NotificationSlot): Promise&lt;void&gt; | Registers a **NotificationSlot** instance to be used by the reminder.|
| removeNotificationSlot(slotType: notification.SlotType, callback: AsyncCallback&lt;void&gt;): void<br>removeNotificationSlot(slotType: notification.SlotType): Promise&lt;void&gt; | Removes a **NotificationSlot** instance of a specified type.|

## How to Develop

> **NOTE**
>
> 1. To publish a reminder through the reminder agent, your application must apply for the **ohos.permission.PUBLISH_AGENT_REMINDER** permission.
>2. Your application must have notification enabled. For details, see [Notification.requestEnableNotification](../reference/apis/js-apis-notification.md#notificationrequestenablenotification8).
> 3. The reminder agent can be used only after being authorized by the user.

1. Define a reminder agent.

2. Publish the reminder agent.

```ts
import reminderAgentManager from '@ohos.reminderAgentManager';
import notification from '@ohos.notification';

// Sample code for defining a reminder agent for a countdown timer:
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

// Sample code for defining a reminder agent for a calendar event:
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

// Sample code for defining a reminder agent for an alarm:
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

        Button() { Text('Countdown reminder agent').fontSize(25).fontWeight(FontWeight.Bold) }.type(ButtonType.Capsule)
          .margin({ top: 10 }).backgroundColor('#0D9FFB').width(250).height(40)
          .onClick(() => {
          // Sample code for publishing the reminder agent.
          this.publishReminder();
        })

      }
      .width('100%')
    }
    .height('100%')
  }
}
```
