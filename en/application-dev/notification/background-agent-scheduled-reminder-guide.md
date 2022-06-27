# Agent-Powered Scheduled Reminder Development

## When to Use

You can set your application to call the **ReminderRequest** class to create scheduled reminders for countdown timers, calendar events, and alarm clocks. When the created reminders are published, the timing and pop-up notification functions of your application will be taken over by the reminder agent in the background, even when your application is frozen or exits.

## Available APIs

**reminderAgent** encapsulates the methods for publishing and canceling reminders.

**Table 1** Major APIs in reminderAgent
| API                                                          | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| function publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback\<number>): void;<br>function publishReminder(reminderReq: ReminderRequest): Promise\<number>; | Publishes a scheduled reminder.<br>The maximum number of valid notifications (excluding expired ones that will not pop up again) is 30 for one application and 2000 for the entire system. |
| function cancelReminder(reminderId: number, callback: AsyncCallback\<void>): void;<br/>function cancelReminder(reminderId: number): Promise\<void>; | Cancels a specified reminder. (The value of **reminderId** is obtained from the return value of **publishReminder**.) |
| function getValidReminders(callback: AsyncCallback<Array\<ReminderRequest>>): void;<br/>function getValidReminders(): Promise<Array\<ReminderRequest>>; | Obtains all valid reminders set by the current application.  |
| function cancelAllReminders(callback: AsyncCallback\<void>): void;<br/>function cancelAllReminders(): Promise\<void>; | Cancels all reminders set by the current application.        |
| function addNotificationSlot(slot: NotificationSlot, callback: AsyncCallback\<void>): void;<br/>function addNotificationSlot(slot: NotificationSlot): Promise\<void>; | Registers a NotificationSlot instance to be used by the reminder. |
| function removeNotificationSlot(slotType: notification.SlotType, callback: AsyncCallback\<void>): void;function removeNotificationSlot(slotType: notification.SlotType): Promise\<void>; | Removes a NotificationSlot instance of a specified type.     |

**ActionButtonType** enumerates types of buttons displayed in a reminder notification.

**Table 2** ActionButtonType enumeration



| Name                     | Description                                                  |
| ------------------------ | ------------------------------------------------------------ |
| ACTION_BUTTON_TYPE_CLOSE | Close button, which can be tapped to stop the reminder alert tone, close the reminder notification, and cancel the reminder snoozing. |

**ReminderType** enumerates the reminder types.

**Table 3** ReminderType enumeration



| Name                   | Description         |
| ---------------------- | ------------------- |
| REMINDER_TYPE_TIMER    | Countdown reminder. |
| REMINDER_TYPE_CALENDAR | Calendar reminder.  |
| REMINDER_TYPE_ALARM    | Alarm reminder.     |

**ActionButton** defines a button displayed in the reminder notification.

**Table 4** ActionButton instance



| Name  | Type             | Mandatory | Description         |
| ----- | ---------------- | --------- | ------------------- |
| title | string           | Yes       | Text on the button. |
| type  | ActionButtonType | Yes       | Button type.        |

**WantAgent** sets the package and ability that are redirected to when the reminder notification is clicked.

**Table 5** WantAgent instance



| Name        | Type   | Mandatory | Description                                                  |
| ----------- | ------ | --------- | ------------------------------------------------------------ |
| pkgName     | string | Yes       | Name of the package redirected to when the reminder notification is clicked. |
| abilityName | string | Yes       | Name of the ability redirected to when the reminder notification is clicked. |

**MaxScreenWantAgent** sets the name of the target package and ability to start automatically when the reminder arrives and the device is not in use. If the device is in use, a notification will be displayed.

**Table 6** MaxScreenWantAgent instance



| Name        | Type   | Mandatory | Description                                                  |
| ----------- | ------ | --------- | ------------------------------------------------------------ |
| pkgName     | string | Yes       | Name of the package that is automatically started when the reminder arrives and the device is not in use. |
| abilityName | string | Yes       | Name of the ability that is automatically started when the reminder arrives and the device is not in use. |

**ReminderRequest** defines the reminder to publish.

**Table 7** ReminderRequest instance



| Name               | Type                           | Mandatory | Description                                                  |
| ------------------ | ------------------------------ | --------- | ------------------------------------------------------------ |
| reminderType       | ReminderType                   | Yes       | Type of the reminder.                                        |
| actionButton       | [ActionButton?, ActionButton?] | No        | Action button displayed in the reminder notification.        |
| wantAgent          | WantAgent                      | No        | Information about the ability that is redirected to when the notification is clicked. |
| maxScreenWantAgent | MaxScreenWantAgent             | No        | Information about the ability that is automatically started when the reminder arrives. If the device is in use, a notification will be displayed. |
| ringDuration       | number                         | No        | Ring duration.                                               |
| snoozeTimes        | number                         | No        | Number of reminder snooze times.                             |
| timeInterval       | number                         | No        | Reminder snooze interval.                                    |
| title              | string                         | No        | Reminder title.                                              |
| content            | string                         | No        | Reminder content.                                            |
| expiredContent     | string                         | No        | Extended content to be displayed when the reminder expires.  |
| snoozeContent      | string                         | No        | Extended content to be displayed when the reminder is snoozing. |
| notificationId     | number                         | No        | Notification ID used by the reminder. For details, see the API reference of the **NotificationRequest.setNotificationId(int id)** method. |
| slotType           | SlotType                       | No        | Type of the slot used by the reminder.                       |

**ReminderRequestCalendar** extends **ReminderRequest** and defines a reminder for a calendar event.

For the application to run properly, if both **repeatMonths** and **repeatDays** are not specified, the earliest reminder time must be later than the current time.

**Table 8** ReminderRequestCalendar instance



| Name         | Type           | Mandatory | Description                                                  |
| ------------ | -------------- | --------- | ------------------------------------------------------------ |
| dateTime     | LocalDateTime  | Yes       | Reminder time, accurate to the minute.                       |
| repeatMonths | Array\<number> | No        | Months in which the reminder repeats. The value range is 1 to 12. |
| repeatDays   | Array\<number> | No        | Date on which the reminder repeats. The value range is 1 to 31. |

**ReminderRequestAlarm** extends **ReminderRequest** and defines a reminder for the alarm clock.

**Table 9** ReminderRequestAlarm instance



| Name       | Type           | Mandatory | Description                                                  |
| ---------- | -------------- | --------- | ------------------------------------------------------------ |
| hour       | number         | Yes       | Hour portion of the reminder time. The value range is 0 to 23. |
| minute     | number         | Yes       | Minute portion of the reminder time. The value range is 0 to 59. |
| daysOfWeek | Array\<number> | No        | Days of a week when the reminder repeats. The value range is 1 to 7. |

**ReminderRequestTimer** extends **ReminderRequest** and defines a reminder for a scheduled timer.

**Table 10** ReminderRequestTimer instance



| Name                 | Type   | Mandatory | Description                               |
| -------------------- | ------ | --------- | ----------------------------------------- |
| triggerTimeInSeconds | number | Yes       | Number of seconds in the countdown timer. |

**LocalDateTime** defines a **LocalDateTime** instance.

**Table 11** LocalDateTime instance



| Name   | Type   | Mandatory | Description |
| ------ | ------ | --------- | ----------- |
| year   | number | Yes       | Year.       |
| month  | number | Yes       | Month.      |
| day    | number | Yes       | Date.       |
| hour   | number | Yes       | Hour.       |
| minute | number | Yes       | Minute.     |
| second | number | No        | Second.     |

## How to Develop

> **NOTE**
> To publish a reminder, your application needs to apply for the **ohos.permission.PUBLISH_AGENT_REMINDER** permission.

Publish a 10-second countdown reminder.

1. Define a countdown timer instance.

   ```
   import reminderAgent from '@ohos.reminderAgent';
   import notification from '@ohos.notification';
   export default {
       // In JS Project:
       // timer: {
       // In eTS Project:
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

2. Publish the reminder.

   ```
   startTimer() {
       reminderAgent.publishReminder(this.timer, (err, reminderId) =>{
           this.printInfo(JSON.stringify(err));
           this.printInfo("reminderId:" + reminderId);
       });
   }
   ```

   HML page code:

   ```
   <div class="container">
       <button type="text" value="publishReminder" onclick="startTimer"></button>
   </div>
   ```

Sample code for defining a calendar reminder instance:

```
// In JS Project:
// calendar: {
// In eTS Project:
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

Sample code for defining an alarm reminder instance:

```
// In JS Project:
// alarm: {
// In eTS Project:
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