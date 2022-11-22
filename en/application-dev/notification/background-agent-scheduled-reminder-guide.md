# Agent-Powered Scheduled Reminder Development

## When to Use

You can set your application to call the **ReminderRequest** class to create scheduled reminders for countdown timers, calendar events, and alarm clocks. When the created reminders are published, the timing and pop-up notification functions of your application will be taken over by the reminder agent in the background, even when your application is frozen or exits.


## Available APIs

**reminderAgent** encapsulates the APIs for publishing and canceling reminders.

For details about the APIs, see [reminderAgent](../reference/apis/js-apis-reminderAgent.md).

**Table 1** Major APIs in reminderAgent

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
> 1. To publish a reminder through the reminder agent, your application needs to apply for the **ohos.permission.PUBLISH_AGENT_REMINDER** permission.
>
> 2. Your application must have notification enabled. For details, see [Notification.requestEnableNotification](../reference/apis/js-apis-notification.md#notificationrequestenablenotification8).

1. Define a reminder agent.

   Sample code for defining a reminder agent for a countdown timer:
   ```js
   import reminderAgent from '@ohos.reminderAgent';
   import notification from '@ohos.notification';
   export default {
       // eTS project:
       let timer : reminderAgent.ReminderRequestTimer = {
           reminderType: reminderAgent.ReminderType.REMINDER_TYPE_TIMER,
           triggerTimeInSeconds: 10,
           actionButton: [
               {
                   title: "close",
                   type: reminderAgent.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE
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
   }
   ```

   Sample code for defining a reminder agent for a calendar event:

    ```js
    // eTS project:
    let calendar : reminderAgent.ReminderRequestCalendar = {
        reminderType: reminderAgent.ReminderType.REMINDER_TYPE_CALENDAR,
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
                type: reminderAgent.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE
            },
            {
                title: "snooze",
                type: reminderAgent.ActionButtonType.ACTION_BUTTON_TYPE_SNOOZE
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
    ```

    Sample code for defining a reminder agent for an alarm:

    ```js
    // eTS project:
    let alarm : reminderAgent.ReminderRequestAlarm = {
        reminderType: reminderAgent.ReminderType.REMINDER_TYPE_ALARM,
        hour: 11,
        minute: 14,
        daysOfWeek: [0],
        actionButton: [
            {
                title: "close",
                type: reminderAgent.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE
            },
            {
                title: "snooze",
                type: reminderAgent.ActionButtonType.ACTION_BUTTON_TYPE_SNOOZE
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
    ```

2. Publish a countdown reminder.
   ```js
   startTimer() {
       reminderAgent.publishReminder(this.timer, (err, reminderId) =>{
           this.printInfo(JSON.stringify(err));
           this.printInfo("reminderId:" + reminderId);
       });
   }
   ```

   HML page code:
   ```html
   <div class="container">
       <button type="text" value="publishReminder" onclick="startTimer"></button>
   </div>
   ```
