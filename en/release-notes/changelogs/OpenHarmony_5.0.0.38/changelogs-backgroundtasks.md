# Resource Scheduler Subsystem Changelog

## cl.backgroundtasks.1 Permission Control Added for reminderAgentManager.publishReminder

**Access Level**

Public API

**Reason for Change**

Applications may abuse reminderAgentManager to send deferred advertisements and marketing activities, affecting user experience. A control mechanism is introduced, preventing applications that are not under control from using reminderAgentManager.

**Change Impact**

This change is a non-compatible change.

Before change: An application uses reminderAgentManager to create a deferred reminder. The API is successfully called, and a reminder ID is returned.

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let timer: reminderAgentManager.ReminderRequestTimer = {
  reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER,
  triggerTimeInSeconds: 10
}

reminderAgentManager.publishReminder(timer, (err: BusinessError, reminderId: number) => {
  // Before the change, the API returns a success response, indicating that the reminder is successfully published. The value of reminderId is greater than 0.
});
```

After change: The application attempts to uses reminderAgentManager to create a deferred reminder. The API fails to be called and error code 1700002 is returned.

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let timer: reminderAgentManager.ReminderRequestTimer = {
  reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER,
  triggerTimeInSeconds: 10
}

reminderAgentManager.publishReminder(timer, (err: BusinessError, reminderId: number) => {
  // After the change, the API returns a failure message, with error code 1700002, indicating that the reminder fails to be published.
  if (err.code == 1700002) {
      // The application is not under control and cannot use reminderAgentManager.
  }
});
```

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.38

**Key API/Component Changes**

**Adaptation Guide**

Solution 1:

You can use the Calendar API to create a deferred reminder. For details, see [Calendar Kit Development](../../../application-dev/calendarmanager/calendarmanager-event-developer.md).

Solution 2:

If you want to use reminderAgentManager to send a deferred reminder, provide the following information for a request. For details, see [Agent-Powered Reminders](../../../application-dev/task-management/agent-powered-reminder.md).

Permission name: Agent-powered Reminder.

Application name: value of the **label** field in the **module.json5** file.

Bundle name: value of **bundleName** in the **app.json** file.

Usage scenario: Provide the reason, purpose, and necessity of using agent-powered reminders. Attach pictures (if any).

 <!--no_check--> 