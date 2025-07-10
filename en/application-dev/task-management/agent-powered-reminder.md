# Agent-powered Reminder (ArkTS)

## Overview

### Introduction

After an application switches to the background or an application process is terminated, it may have scheduled tasks for reminding users, for example, flash sale reminders for shopping applications. To meet this requirement, the system provides agent-powered reminders (implemented by **reminderAgentManager**). When the application switches to the background or the process is terminated, the system sends reminders on behalf of the application. Currently, the following reminder types are supported: timer, calendar, and alarm.<!--RP1--><!--RP1End-->

- Timer: reminders based on countdown timers

- Calendar: reminders based on calendar events

- Alarm: reminders based on alarm clocks

### Constraints

<!--RP2-->
- **Maximum reminders**: 30 for regular applications, 10,000 for system applications, and 12,000 total for the system.
<!--RP2End-->

> **NOTE**
>
> When the reminder time arrives, the notification center displays the relevant reminder. The reminder remains active and unexpired unless the user touches the CLOSE button, at which point the reminder becomes expired.
>
> For a recurring reminder (for example, a daily reminder), the reminder is always valid regardless of whether the user touches the CLOSE button.

- **Redirection limit**: The application that is redirected to upon a click on the notification must be the application that requested the agent-powered reminder.

<!--RP3--><!--RP3End-->


## Available APIs

**Table 1** Main APIs for agent-powered reminders

The table below uses promise as an example to describe the APIs used for developing agent-powered reminders. For details about more APIs and their usage, see [reminderAgentManager](../reference/apis-backgroundtasks-kit/js-apis-reminderAgentManager.md).
| API| Description|
| -------- | -------- |
| publishReminder(reminderReq: ReminderRequest): Promise&lt;number&gt; | Publishes a scheduled reminder.|
| cancelReminder(reminderId: number): Promise&lt;void&gt; | Cancels a reminder.|
| getValidReminders(): Promise&lt;Array&lt;ReminderRequest&gt;&gt; | Obtains all valid reminders set by the current application.|
| cancelAllReminders(): Promise&lt;void&gt; | Cancels all reminders set by the current application.|
| addNotificationSlot(slot: NotificationSlot): Promise&lt;void&gt; | Adds a notification slot.|
| removeNotificationSlot(slotType: notification.SlotType): Promise&lt;void&gt; | Removes a notification slot.|


## How to Develop

1. Declare the **ohos.permission.PUBLISH_AGENT_REMINDER** permission. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

2. [Request notification authorization](../notification/notification-enable.md). Agent-powered reminders can be used only after being authorized by the user.

3. Import the modules.
   
   ```ts
   import { reminderAgentManager } from '@kit.BackgroundTasksKit';
   import { notificationManager } from '@kit.NotificationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

4. Define a reminder. You can define the following types of reminders based on project requirements.

   - Timer
     
      ```ts
      let targetReminderAgent: reminderAgentManager.ReminderRequestTimer = {
        reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER,   // The reminder type is timer.
        triggerTimeInSeconds: 10,
        actionButton: [ // Set the button type and title displayed for the reminder in the notification panel.
          {
            title: 'close',
            type: reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE
          }
        ],
        wantAgent: {     // Information about the target UIAbility that is displayed after the reminder notification is touched.
          pkgName: 'com.example.myapplication',
          abilityName: 'EntryAbility'
        },
        title: 'this is title', // Reminder title.
        content: 'this is content', // Reminder content.
        expiredContent: 'this reminder has expired', // Content to be displayed after the reminder expires.
        notificationId: 100, // Notification ID used by the reminder. If there are reminders with the same notification ID, the later one will overwrite the earlier one.
        slotType: notificationManager.SlotType.SOCIAL_COMMUNICATION // Type of the slot used by the reminder.
      }
      ```

   - Calendar
     
      ```ts
      let targetReminderAgent: reminderAgentManager.ReminderRequestCalendar = {
        reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_CALENDAR, // The reminder type is calendar.
        dateTime: {   // Reminder time.
          year: 2023,
          month: 1,
          day: 1,
          hour: 11,
          minute: 14,
          second: 30
        },
        repeatMonths: [1], // Month in which the reminder repeats.
        repeatDays: [1], // Date on which the reminder repeats.
        actionButton: [ // Set the button type and title displayed for the reminder in the notification panel.
          {
            title: 'close',
            type: reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE
          },
          {
            title: 'snooze',
            type: reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_SNOOZE
          },
        ],
        wantAgent: { // Information about the target UIAbility that is displayed after the reminder notification is touched.
          pkgName: 'com.example.myapplication',
          abilityName: 'EntryAbility'
        },
        ringDuration: 5, // Ringing duration, in seconds.
        snoozeTimes: 2, // Number of reminder snooze times.
        timeInterval: 5*60, // Reminder snooze interval, in seconds.
        title: 'this is title', // Reminder title.
        content: 'this is content', // Reminder content.
        expiredContent: 'this reminder has expired', // Content to be displayed after the reminder expires.
        snoozeContent: 'remind later', // Content to be displayed when the reminder is snoozed.
        notificationId: 100, // Notification ID used by the reminder. If there are reminders with the same notification ID, the later one will overwrite the earlier one.
        slotType: notificationManager.SlotType.SOCIAL_COMMUNICATION // Type of the slot used by the reminder.
      }
      ```

   - Alarm
   
      ```ts
      let targetReminderAgent: reminderAgentManager.ReminderRequestAlarm = {
        reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_ALARM, // The reminder type is alarm.
        hour: 23, // Hour portion of the reminder time.
        minute: 9, // Minute portion of the reminder time.
        daysOfWeek: [2], // Days of a week when the reminder repeats..
        actionButton: [ // Set the button type and title displayed for the reminder in the notification panel.
          {
            title: 'close',
            type: reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE
          },
          {
            title: 'snooze',
            type: reminderAgentManager.ActionButtonType.ACTION_BUTTON_TYPE_SNOOZE
          },
        ],
        wantAgent: { // Information about the target UIAbility that is displayed after the reminder notification is touched.
          pkgName: 'com.example.myapplication',
          abilityName: 'EntryAbility'
        },
        ringDuration: 5, // Ringing duration, in seconds.
        snoozeTimes: 2, // Number of reminder snooze times.
        timeInterval: 5*60, // Reminder snooze interval, in seconds.
        title: 'this is title', // Reminder title.
        content: 'this is content', // Reminder content.
        expiredContent: 'this reminder has expired', // Content to be displayed after the reminder expires.
        snoozeContent: 'remind later', // Content to be displayed when the reminder is snoozed.
        notificationId: 99, // Notification ID used by the reminder. If there are reminders with the same notification ID, the later one will overwrite the earlier one.
        slotType: notificationManager.SlotType.SOCIAL_COMMUNICATION // Type of the slot used by the reminder.
      }
      ```

5. Publish the reminder. After the reminder is published, your application can use the agent-powered reminder feature.
   
   ```ts
    reminderAgentManager.publishReminder(targetReminderAgent).then((res: number) => {
      console.info('Succeeded in publishing reminder. ');
      let reminderId: number = res; // ID of the published reminder.
    }).catch((err: BusinessError) => {
      console.error(`Failed to publish reminder. Code: ${err.code}, message: ${err.message}`);
    })
   ```

6. Delete the reminder as required.
   
   ```ts
    let reminderId: number = 1;
    // The reminder ID is obtained from the callback after the reminder is published.
    reminderAgentManager.cancelReminder(reminderId).then(() => {
      console.log('Succeeded in canceling reminder.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to cancel reminder. Code: ${err.code}, message: ${err.message}`);
    });
   ```

