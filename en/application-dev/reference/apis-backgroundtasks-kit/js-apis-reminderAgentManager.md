# @ohos.reminderAgentManager (Agent-Powered Reminders)

The reminderAgentManager module provides APIs related to agent-powered reminders. When your application is frozen or exits, the timing and notification functions of your application will be taken over by a system service running in the background. You can use the APIs to create scheduled reminders for countdown timers, calendar events, and alarm clocks.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { reminderAgentManager } from '@kit.BackgroundTasksKit';
```

## reminderAgentManager.publishReminder

publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback\<number>): void

Publishes a reminder. This API uses an asynchronous callback to return the result.

If the value of [ReminderRequest.ringDuration](#reminderrequest) is greater than 0, the custom ringtone is played on the alarm channel by default. If the value is less than or equal to 0, no ringtone is played.

> **NOTE**
>
> This API can be called only after the [NotificationManager.requestEnableNotification](../apis-notification-kit/js-apis-notificationManager.md#notificationmanagerrequestenablenotification10) permission is obtained.
>
> <!--RP1--><!--RP1End-->

**Required permissions**: ohos.permission.PUBLISH_AGENT_REMINDER

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | reminderReq | [ReminderRequest](#reminderrequest) | Yes| Request used for publishing the reminder.|
  | callback | AsyncCallback\<number> | Yes| Callback used to return the published reminder's ID.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](errorcode-reminderAgentManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message|
| --------- | ------- |
| 401 | If the input parameter is not valid parameter. |
| 1700001    | Notification is not enabled. |
| 1700002    | The number of reminders exceeds the limit. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let timer: reminderAgentManager.ReminderRequestTimer = {
  reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER,
  triggerTimeInSeconds: 10
}

reminderAgentManager.publishReminder(timer, (err: BusinessError, reminderId: number) => {
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.log("callback, reminderId = " + reminderId);
  }
});
```

## reminderAgentManager.publishReminder

publishReminder(reminderReq: ReminderRequest): Promise\<number>

Publishes a reminder. This API uses a promise to return the result.

If the value of [ReminderRequest.ringDuration](#reminderrequest) is greater than 0, the custom ringtone is played on the alarm channel by default. If the value is less than or equal to 0, no ringtone is played.

> **NOTE**
>
> This API can be called only after the [NotificationManager.requestEnableNotification](../apis-notification-kit/js-apis-notificationManager.md#notificationmanagerrequestenablenotification10) permission is obtained.
>
> <!--RP1--><!--RP1End-->

**Required permissions**: ohos.permission.PUBLISH_AGENT_REMINDER

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | reminderReq | [ReminderRequest](#reminderrequest) | Yes| Request used for publishing the reminder.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<number> | Promise used to return the published reminder ID.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](errorcode-reminderAgentManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message|
| --------- | ------- |
| 401 | If the input parameter is not valid parameter. |
| 1700001    | Notification is not enabled. |
| 1700002    | The number of reminders exceeds the limit. |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let timer: reminderAgentManager.ReminderRequestTimer = {
  reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER,
  triggerTimeInSeconds: 10
}

reminderAgentManager.publishReminder(timer).then((reminderId: number) => {
  console.log("promise, reminderId = " + reminderId);
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```


## reminderAgentManager.cancelReminder

cancelReminder(reminderId: number, callback: AsyncCallback\<void>): void

Cancels a reminder published. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| reminderId | number | Yes| ID of the reminder to cancel.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the reminder is canceled, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](errorcode-reminderAgentManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message|
| --------- | ------- |
| 401 | If the input parameter is not valid parameter. |
| 1700003    | The reminder does not exist. |
| 1700004    | The bundle name does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let reminderId: number = 1;
reminderAgentManager.cancelReminder(reminderId, (err: BusinessError) => {
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.log("cancelReminder callback");
  }
});
```

## reminderAgentManager.cancelReminder

cancelReminder(reminderId: number): Promise\<void>

Cancels a reminder published. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| reminderId | number | Yes| ID of the reminder to cancel.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](errorcode-reminderAgentManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message|
| --------- | ------- |
| 401 | If the input parameter is not valid parameter. |
| 1700003    | The reminder does not exist. |
| 1700004    | The bundle name does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let reminderId: number = 1;
reminderAgentManager.cancelReminder(reminderId).then(() => {
  console.log("cancelReminder promise");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```

## reminderAgentManager.getValidReminders

getValidReminders(callback: AsyncCallback<Array\<ReminderRequest>>): void

Obtains all [valid (not yet expired) reminders](../../task-management/agent-powered-reminder.md#constraints) set by the current application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<[ReminderRequest](#reminderrequest)>> | Yes| Callback used to return all the valid reminders.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](errorcode-reminderAgentManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message|
| --------- | ------- |
| 401 | If the input parameter is not valid parameter. |
| 1700004    | The bundle name does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

reminderAgentManager.getValidReminders((err: BusinessError, reminders: Array<reminderAgentManager.ReminderRequest>) => {
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.log("callback, getValidReminders length = " + reminders.length);
    for (let i = 0; i < reminders.length; i++) {
      console.log("getValidReminders = " + reminders[i]);
      console.log("getValidReminders, reminderType = " + reminders[i].reminderType);
      const actionButton = reminders[i].actionButton || [];
      for (let j = 0; j < actionButton.length; j++) {
        console.log("getValidReminders, actionButton.title = " + actionButton[j]?.title);
        console.log("getValidReminders, actionButton.type = " + actionButton[j]?.type);
      }
      console.log("getValidReminders, wantAgent.pkgName = " + reminders[i].wantAgent?.pkgName);
      console.log("getValidReminders, wantAgent.abilityName = " + reminders[i].wantAgent?.abilityName);
      console.log("getValidReminders, ringDuration = " + reminders[i].ringDuration);
      console.log("getValidReminders, snoozeTimes = " + reminders[i].snoozeTimes);
      console.log("getValidReminders, timeInterval = " + reminders[i].timeInterval);
      console.log("getValidReminders, title = " + reminders[i].title);
      console.log("getValidReminders, content = " + reminders[i].content);
      console.log("getValidReminders, expiredContent = " + reminders[i].expiredContent);
      console.log("getValidReminders, snoozeContent = " + reminders[i].snoozeContent);
      console.log("getValidReminders, notificationId = " + reminders[i].notificationId);
      console.log("getValidReminders, slotType = " + reminders[i].slotType);
    }
  }
});
```

## reminderAgentManager.getValidReminders

getValidReminders(): Promise\<Array\<ReminderRequest>>

Obtains all [valid (not yet expired) reminders](../../task-management/agent-powered-reminder.md#constraints) set by the current application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<Array\<[ReminderRequest](#reminderrequest)>> | Promise used to return all the valid reminders.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](errorcode-reminderAgentManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message|
| --------- | ------- |
| 401 | If the input parameter is not valid parameter. |
| 1700004    | The bundle name does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

reminderAgentManager.getValidReminders().then((reminders: Array<reminderAgentManager.ReminderRequest>) => {
  console.log("promise, getValidReminders length = " + reminders.length);
  for (let i = 0; i < reminders.length; i++) {
    console.log("getValidReminders = " + reminders[i]);
    console.log("getValidReminders, reminderType = " + reminders[i].reminderType);
    const actionButton = reminders[i].actionButton || [];
    for (let j = 0; j < actionButton.length; j++) {
      console.log("getValidReminders, actionButton.title = " + actionButton[j]?.title);
      console.log("getValidReminders, actionButton.type = " + actionButton[j]?.type);
    }
    console.log("getValidReminders, wantAgent.pkgName = " + reminders[i].wantAgent?.pkgName);
    console.log("getValidReminders, wantAgent.abilityName = " + reminders[i].wantAgent?.abilityName);
    console.log("getValidReminders, ringDuration = " + reminders[i].ringDuration);
    console.log("getValidReminders, snoozeTimes = " + reminders[i].snoozeTimes);
    console.log("getValidReminders, timeInterval = " + reminders[i].timeInterval);
    console.log("getValidReminders, title = " + reminders[i].title);
    console.log("getValidReminders, content = " + reminders[i].content);
    console.log("getValidReminders, expiredContent = " + reminders[i].expiredContent);
    console.log("getValidReminders, snoozeContent = " + reminders[i].snoozeContent);
    console.log("getValidReminders, notificationId = " + reminders[i].notificationId);
    console.log("getValidReminders, slotType = " + reminders[i].slotType);
  }
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
}); 
```

## reminderAgentManager.cancelAllReminders

cancelAllReminders(callback: AsyncCallback\<void>): void

Cancels all reminders set by the current application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If all the reminders are canceled, **err** is **undefined**. Otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](errorcode-reminderAgentManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message|
| --------- | ------- |
| 401 | If the input parameter is not valid parameter. |
| 1700004    | The bundle name does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

reminderAgentManager.cancelAllReminders((err: BusinessError) =>{
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.log("cancelAllReminders callback")
  }
});
```

## reminderAgentManager.cancelAllReminders

cancelAllReminders(): Promise\<void>

Cancels all reminders set by the current application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](errorcode-reminderAgentManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message|
| --------- | ------- |
| 401 | If the input parameter is not valid parameter. |
| 1700004    | The bundle name does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

reminderAgentManager.cancelAllReminders().then(() => {
  console.log("cancelAllReminders promise")
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```


## reminderAgentManager.addNotificationSlot

addNotificationSlot(slot: NotificationSlot, callback: AsyncCallback\<void>): void

Adds a notification slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| slot | [NotificationSlot](../apis-notification-kit/js-apis-inner-notification-notificationSlot.md#notificationslot-1) | Yes| notificationManager\.slot instance. Only **notificationType** can be set.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the notification slot is added, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 401      | If the input parameter is not valid parameter. |

**Example**

```ts
import { notificationManager } from '@kit.NotificationKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mySlot: notificationManager.NotificationSlot = {
  notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
}

reminderAgentManager.addNotificationSlot(mySlot, (err: BusinessError) => {
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.log("addNotificationSlot callback");
  }
});
```


## reminderAgentManager.addNotificationSlot

addNotificationSlot(slot: NotificationSlot): Promise\<void>

Adds a notification slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| slot | [NotificationSlot](../apis-notification-kit/js-apis-inner-notification-notificationSlot.md#notificationslot-1) | Yes| notificationManager\.slot instance. Only **notificationType** can be set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 401      | If the input parameter is not valid parameter. |

**Example**

```ts
import { notificationManager } from '@kit.NotificationKit';
import { BusinessError } from '@kit.BasicServicesKit';

let mySlot: notificationManager.NotificationSlot = {
  notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
}
reminderAgentManager.addNotificationSlot(mySlot).then(() => {
  console.log("addNotificationSlot promise");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```


## reminderAgentManager.removeNotificationSlot

removeNotificationSlot(slotType: notification.SlotType, callback: AsyncCallback\<void>): void

Removes a notification slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| slotType | [notification.SlotType](../apis-notification-kit/js-apis-notification.md#slottype) | Yes| Type of the notification slot.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the notification slot is removed, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 401      | If the input parameter is not valid parameter. |

**Example**

```ts
import { notificationManager } from '@kit.NotificationKit';
import { BusinessError } from '@kit.BasicServicesKit';

reminderAgentManager.removeNotificationSlot(notificationManager.SlotType.CONTENT_INFORMATION,
  (err: BusinessError) => {
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.log("removeNotificationSlot callback");
  }
});
```


## reminderAgentManager.removeNotificationSlot

removeNotificationSlot(slotType: notification.SlotType): Promise\<void>

Removes a notification slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| slotType | [notification.SlotType](../apis-notification-kit/js-apis-notification.md#slottype) | Yes| Type of the notification slot.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 401      | If the input parameter is not valid parameter. |

**Example**

```ts
import { notificationManager } from '@kit.NotificationKit';
import { BusinessError } from '@kit.BasicServicesKit';

reminderAgentManager.removeNotificationSlot(notificationManager.SlotType.CONTENT_INFORMATION).then(() => {
  console.log("removeNotificationSlot promise");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```

## reminderAgentManager.getAllValidReminders<sup>12+</sup>

getAllValidReminders(): Promise\<Array\<ReminderInfo>>

Obtains all [valid (not yet expired) reminders](../../task-management/agent-powered-reminder.md#constraints) set by the current application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Return value**

| Type                                             | Description                                                        |
| ------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[ReminderInfo](#reminderinfo12)>> | Promise used to return all the valid reminders.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message          |
| -------- | ------------------ |
| 201      | Permission denied. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

reminderAgentManager.getAllValidReminders().then((reminders: Array<reminderAgentManager.ReminderInfo>) => {
  console.log("promise, getAllValidReminders length = " + reminders.length);
  for (let i = 0; i < reminders.length; i++) {
    console.log("getAllValidReminders, reminderId = " + reminders[i].reminderId);
    console.log("getAllValidReminders, reminderType = " + reminders[i].reminderReq.reminderType);
    const actionButton = reminders[i].reminderReq.actionButton || [];
    for (let j = 0; j < actionButton.length; j++) {
      console.log("getAllValidReminders, actionButton.title = " + actionButton[j]?.title);
      console.log("getAllValidReminders, actionButton.type = " + actionButton[j]?.type);
    }
    console.log("getAllValidReminders, wantAgent.pkgName = " + reminders[i].reminderReq.wantAgent?.pkgName);
    console.log("getAllValidReminders, wantAgent.abilityName = " + reminders[i].reminderReq.wantAgent?.abilityName);
    console.log("getAllValidReminders, ringDuration = " + reminders[i].reminderReq.ringDuration);
    console.log("getAllValidReminders, snoozeTimes = " + reminders[i].reminderReq.snoozeTimes);
    console.log("getAllValidReminders, timeInterval = " + reminders[i].reminderReq.timeInterval);
    console.log("getAllValidReminders, title = " + reminders[i].reminderReq.title);
    console.log("getAllValidReminders, content = " + reminders[i].reminderReq.content);
    console.log("getAllValidReminders, expiredContent = " + reminders[i].reminderReq.expiredContent);
    console.log("getAllValidReminders, snoozeContent = " + reminders[i].reminderReq.snoozeContent);
    console.log("getAllValidReminders, notificationId = " + reminders[i].reminderReq.notificationId);
    console.log("getAllValidReminders, slotType = " + reminders[i].reminderReq.slotType);
  }
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
}); 
```

## reminderAgentManager.addExcludeDate<sup>12+</sup>

addExcludeDate(reminderId: number, date: Date): Promise\<void>

Adds a non-reminder date for a recurring calendar reminder with a specific ID. For example, configure a daily reminder to skip notifications on Tuesdays. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | ---------------------------------- |
| reminderId | number | Yes  | ID of the recurring calendar reminder.|
| date       | Date   | Yes  | Non-reminder date.                    |

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](errorcode-reminderAgentManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 201      | Permission denied.                             |
| 401      | If the input parameter is not valid parameter. |
| 1700003  | The reminder does not exist.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let reminderId: number = 1;
let date = new Date();
reminderAgentManager.addExcludeDate(reminderId, date).then(() => {
  console.log("addExcludeDate promise");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```

## reminderAgentManager.deleteExcludeDates<sup>12+</sup>

deleteExcludeDates(reminderId: number): Promise\<void>

Deletes all non-reminder dates for a recurring calendar reminder with a specific ID. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | ---------------------------------- |
| reminderId | number | Yes  | ID of the recurring calendar reminder.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](errorcode-reminderAgentManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                    |
| -------- | ---------------------------- |
| 201      | Permission denied.           |
| 1700003  | The reminder does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let reminderId: number = 1;
reminderAgentManager.deleteExcludeDates(reminderId).then(() => {
  console.log("deleteExcludeDates promise");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```

## reminderAgentManager.getExcludeDates<sup>12+</sup>

getExcludeDates(reminderId: number): Promise\<Array\<Date>>

Obtains all non-reminder dates for a recurring calendar reminder with a specific ID. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | ---------------------------------- |
| reminderId | number | Yes  | ID of the recurring calendar reminder.|

**Return value**

| Type                  | Description                             |
| ---------------------- | --------------------------------- |
| Promise\<Array\<Date>> | Promise used to return all the non-reminder dates.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](errorcode-reminderAgentManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                    |
| -------- | ---------------------------- |
| 201      | Permission denied.           |
| 1700003  | The reminder does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let reminderId: number = 1;
reminderAgentManager.getExcludeDates(reminderId).then((dates) => {
  console.log("getExcludeDates promise length: " + dates.length);
  for (let i = 0; i < dates.length; i++) {
	console.log("getExcludeDates promise date is: " + dates[i].toString());
  }
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```

## reminderAgentManager.updateReminder<sup>20+</sup>

updateReminder(reminderId: number, reminderReq: ReminderRequest): Promise\<void>

Updates the agent-powered reminder with the specified ID. This API uses a promise to return the result. Only [valid (not yet expired) reminders](../../task-management/agent-powered-reminder.md#constraints) that are not displayed in the notification panel can be updated.

**Required permissions**: ohos.permission.PUBLISH_AGENT_REMINDER

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | ---------------------------------- |
| reminderId | number | Yes  | ID of the reminder to be updated, which is the return value of [publishReminder](#reminderagentmanagerpublishreminder).|
| reminderReq | [ReminderRequest](#reminderrequest) | Yes  | Request instance used to set detailed information such as the reminder type and ringing duration.|

**Return value**

| Type                  | Description                             |
| ---------------------- | --------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](errorcode-reminderAgentManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                    |
| -------- | ---------------------------- |
| 201      | Permission denied.           |
| 1700003  | The reminder does not exist. |
| 1700007  | If the input parameter is not valid parameter. |

**Example**

```ts
import { reminderAgentManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';

let timer: reminderAgentManager.ReminderRequestTimer = {
  reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER,
  triggerTimeInSeconds: 10
}

let reminderId: number = 1;
reminderAgentManager.updateReminder(reminderId, timer).then(() => {
  console.info("update reminder succeed");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```

## ActionButtonType

Enumerates the types of buttons displayed for a reminder.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Value| Description|
| -------- | -------- | -------- |
| ACTION_BUTTON_TYPE_CLOSE | 0 | Button for closing the reminder.|
| ACTION_BUTTON_TYPE_SNOOZE | 1 | Button for snoozing the reminder, with the frequency and timing configured via **snoozeTimes** and **timeInterval** in the **ReminderRequest** struct.|

## ReminderType

Enumerates the reminder types.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Value| Description|
| -------- | -------- | -------- |
| REMINDER_TYPE_TIMER | 0 | Countdown reminder.|
| REMINDER_TYPE_CALENDAR | 1 | Calendar reminder.|
| REMINDER_TYPE_ALARM | 2 | Alarm reminder.|

## RingChannel<sup>20+</sup>

Enumerates the audio playback channels for the custom prompt tone.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Value| Description|
| -------- | -------- | -------- |
| RING_CHANNEL_ALARM | 0 | Alarm channel.|
| RING_CHANNEL_MEDIA | 1 | Media channel.|


## ActionButton

Describes the button displayed for a reminder.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| title | string | Yes| Text on the button.|
| titleResource<sup>11+</sup> | string | No| Resource ID of the title. This parameter is used to read the title information after the system language is switched.|
| type | [ActionButtonType](#actionbuttontype) | Yes| Button type.|


## WantAgent

Defines the information about the redirected-to ability.

**System capability**: SystemCapability.Notification.ReminderAgent


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pkgName | string | Yes| Name of the target package.|
| abilityName | string | Yes| Name of the target ability.|
| parameters<sup>12+</sup> | Record\<string, Object> | No| Parameters to be transferred to the target.|
| uri<sup>12+</sup> | string | No| URI of the target ability.|


## MaxScreenWantAgent

Describes the information about the ability that is started automatically and displayed in full-screen mode when a reminder is displayed in the notification center. This API is reserved.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pkgName | string | Yes| Name of the target package. (If the device is in use, only a notification banner is displayed.)|
| abilityName | string | Yes| Name of the target ability. (If the device is in use, only a notification banner is displayed.)|


## ReminderRequest

Defines the request for publishing a reminder.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| reminderType | [ReminderType](#remindertype) | Yes| Type of the reminder.|
| actionButton | [[ActionButton?, ActionButton?, ActionButton?]](#actionbutton) | No| Buttons displayed for the reminder notification.<br>- For common applications, a maximum of two buttons are supported.<br>- For system applications, a maximum of two buttons are supported in API version 9, and a maximum of three buttons are supported in API version 10 and later versions.|
| wantAgent | [WantAgent](#wantagent) | No| Information about the ability that is redirected to when the reminder is clicked.|
| maxScreenWantAgent | [MaxScreenWantAgent](#maxscreenwantagent) | No| Information about the ability that is started automatically and displayed in full-screen mode when the reminder arrives. If the device is in use, only a notification banner is displayed.<br> This API is reserved.|
| ringDuration | number | No| Ringing duration, in seconds. The default value is **1**.|
| snoozeTimes | number | No| Number of reminder snooze times. The default value is **0**. (It is not applicable to countdown reminders.)|
| timeInterval | number | No| Reminder snooze interval, in seconds. The minimum value is 5 minutes. (It is not applicable to countdown reminders.)|
| title | string | No| Reminder title.|
| titleResourceId<sup>18+</sup> | number | No| Resource ID of the reminder title.|
| content | string | No| Reminder content.|
| contentResourceId<sup>18+</sup> | number | No| Resource ID of the reminder content.|
| expiredContent | string | No| Content to be displayed after the reminder expires.|
| expiredContentResourceId<sup>18+</sup> | number | No| Resource ID of the content to be displayed after the reminder expires.|
| snoozeContent | string | No| Content to be displayed when the reminder is snoozing. (It is not applicable to countdown reminders.)|
| snoozeContentResourceId<sup>18+</sup> | number | No| Resource ID of the content to be displayed when the reminder is snoozing.|
| notificationId | number | No| Notification ID used by the reminder. You must pass in a notification ID. If there are reminders with the same notification ID, the later one will overwrite the earlier one.|
| groupId<sup>11+</sup> | string | No| Group ID used for the reminder. If "Don't ask again" or similar information is selected for the reminder, other reminders with the same group ID are also canceled.|
| slotType | [notification.SlotType](../apis-notification-kit/js-apis-notificationManager.md#slottype) | No| Type of the slot used by the reminder.|
| tapDismissed<sup>10+</sup> | boolean | No| Whether the reminder is automatically cleared. For details, see [NotificationRequest.tapDismissed](../apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest-1).<br> - **true** (default): The reminder is automatically cleared after the notification or button is tapped.<br> - **false**: The reminder is retained after the notification or button is tapped.|
| autoDeletedTime<sup>10+</sup> | number | No| Time when the reminder is automatically cleared. For details, see [NotificationRequest.autoDeletedTime](../apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest-1).|
| snoozeSlotType<sup>11+</sup> | [notification.SlotType](../apis-notification-kit/js-apis-notificationManager.md#slottype) | No| Type of the slot used by the snoozed reminder. (It is not applicable to countdown reminders.)|
| customRingUri<sup>11+</sup> | string | No| URI of the custom prompt tone. The prompt tone file must be stored in the **resources/rawfile** directory and supports formats such as M4A, AAC, MP3, OGG, WAV, FLAC, and AMR.|
| ringChannel<sup>20+</sup> | [RingChannel](#ringchannel20) | No| Audio channel of the custom prompt tone. The default channel is the alarm channel.|

## ReminderRequestCalendar

ReminderRequestCalendar extends ReminderRequest

Defines a reminder for a calendar event.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| dateTime | [LocalDateTime](#localdatetime) | Yes| Reminder time.|
| repeatMonths | Array\<number> | No| Month in which the reminder repeats.|
| repeatDays | Array\<number> | No| Date on which the reminder repeats.|
| daysOfWeek<sup>11+</sup> | Array\<number> | No| Days of a week when the reminder repeats. The value ranges from 1 to 7, corresponding to the data from Monday to Sunday.|
| endDateTime<sup>12+</sup> | [LocalDateTime](#localdatetime) | No| End time of the reminder.|


## ReminderRequestAlarm

ReminderRequestAlarm extends ReminderRequest

Defines a reminder for an alarm.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| hour | number | Yes| Hour portion of the reminder time.|
| minute | number | Yes| Minute portion of the reminder time.|
| daysOfWeek | Array\<number> | No| Days of a week when the reminder repeats. The value ranges from 1 to 7, corresponding to the data from Monday to Sunday.|


## ReminderRequestTimer

ReminderRequestTimer extends ReminderRequest

Defines a reminder for a scheduled timer.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| triggerTimeInSeconds | number | Yes| Number of seconds in the countdown timer.|


## LocalDateTime

Defines the time information for a calendar reminder.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| year | number | Yes| Year.|
| month | number | Yes| Month. The value ranges from 1 to 12.|
| day | number | Yes| Day. The value ranges from 1 to 31.|
| hour | number | Yes| Hour. The value ranges from 0 to 23.|
| minute | number | Yes| Minute. The value ranges from 0 to 59.|
| second | number | No| Second. The value ranges from 0 to 59.|

## ReminderInfo<sup>12+</sup>

Defines the reminder information.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name       | Type                               | Read Only| Optional| Description                |
| ----------- | ----------------------------------- | ---- | ---- | -------------------- |
| reminderId  | number                              | No  | No  | ID of the reminder.|
| reminderReq | [ReminderRequest](#reminderrequest) | No  | No  | Request used for publishing the reminder.      |
