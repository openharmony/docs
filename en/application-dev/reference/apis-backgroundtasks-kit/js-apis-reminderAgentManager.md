# @ohos.reminderAgentManager (Agent-powered Reminder)

<!--Kit: Background Tasks Kit-->
<!--Subsystem: Resourceschedule-->
<!--Owner: @xufu7-->
<!--Designer: @zhouben25-->
<!--Tester: @leetestnady-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=428e1286778a3a7ab9f84d96d96e298fc6f7e862 translatedAt=2026-08-11T01:55:50.514Z pushedAt=2026-08-11T03:04:36.334Z -->

The **reminderAgentManager** module provides APIs related to agent-powered reminders. When your application is frozen or exits, the application's scheduled notification capability will be taken over by a system service running in the background. You can use the APIs to create scheduled reminders for countdown timers, calendar events, and alarm clocks. For details, see [Agent-powered Reminder](../../task-management/agent-powered-reminder.md).

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

> **NOTE**
>
> This API can be called only after the [notificationManager.requestEnableNotification](../apis-notification-kit/js-apis-notificationManager.md#notificationmanagerrequestenablenotification10) permission is obtained.
>
> <!--RP1--><!--RP1End-->

**Required permissions**: ohos.permission.PUBLISH_AGENT_REMINDER

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | reminderReq | [ReminderRequest](#reminderrequest) | Yes| Request used for publishing the reminder.|
  | callback | AsyncCallback\<number> | Yes| Callback used to return the result. After the agent-powered reminder is published, **err** is **undefined**, and **data** is the ID of the published reminder. Otherwise, **err** is an error object.|

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
import { reminderAgentManager } from '@kit.BackgroundTasksKit';

let timer: reminderAgentManager.ReminderRequestTimer = {
  reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER,
  triggerTimeInSeconds: 10
}

reminderAgentManager.publishReminder(timer, (err: BusinessError, reminderId: number) => {
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.info("callback, reminderId = " + reminderId);
  }
});
```

## reminderAgentManager.publishReminder

publishReminder(reminderReq: ReminderRequest): Promise\<number>

Publishes a reminder. This API uses a promise to return the result.

> **NOTE**
>
> This API can be called only after the [notificationManager.requestEnableNotification](../apis-notification-kit/js-apis-notificationManager.md#notificationmanagerrequestenablenotification10) permission is obtained.
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
import { reminderAgentManager } from '@kit.BackgroundTasksKit';

let timer: reminderAgentManager.ReminderRequestTimer = {
  reminderType: reminderAgentManager.ReminderType.REMINDER_TYPE_TIMER,
  triggerTimeInSeconds: 10
}

reminderAgentManager.publishReminder(timer).then((reminderId: number) => {
  console.info("promise, reminderId = " + reminderId);
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
| reminderId | number | Yes| ID of the agent-powered reminder to be canceled. The reminder ID is returned when the [reminderAgentManager.publishReminder](#reminderagentmanagerpublishreminder) API is called.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If all the reminders are canceled, **err** is **undefined**. Otherwise, **err** is an error object.|

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
import { reminderAgentManager } from '@kit.BackgroundTasksKit';

let reminderId: number = 1;
reminderAgentManager.cancelReminder(reminderId, (err: BusinessError) => {
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.info("cancelReminder callback");
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
| reminderId | number | Yes| ID of the agent-powered reminder to be canceled. The reminder ID is returned when the [reminderAgentManager.publishReminder](#reminderagentmanagerpublishreminder) API is called.|

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
import { reminderAgentManager } from '@kit.BackgroundTasksKit';

let reminderId: number = 1;
reminderAgentManager.cancelReminder(reminderId).then(() => {
  console.info("cancelReminder promise");
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
| callback | AsyncCallback\<Array\<[ReminderRequest](#reminderrequest)>> | Yes| Callback used to return the result. If the agent-powered reminder is queried, **err** is **undefined**, and **data** contains all valid (not yet expired) reminders set by the current application. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](errorcode-reminderAgentManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message|
| --------- | ------- |
| 401 | If the input parameter is not valid parameter. |
| 1700004    | The bundle name does not exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { reminderAgentManager } from '@kit.BackgroundTasksKit';

reminderAgentManager.getValidReminders((err: BusinessError, reminders: Array<reminderAgentManager.ReminderRequest>) => {
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.info("callback, getValidReminders length = " + reminders.length);
    for (let i = 0; i < reminders.length; i++) {
      console.info("getValidReminders = " + reminders[i]);
      console.info("getValidReminders, reminderType = " + reminders[i].reminderType);
      const actionButton = reminders[i].actionButton || [];
      for (let j = 0; j < actionButton.length; j++) {
        console.info("getValidReminders, actionButton.title = " + actionButton[j]?.title);
        console.info("getValidReminders, actionButton.type = " + actionButton[j]?.type);
      }
      console.info("getValidReminders, wantAgent.pkgName = " + reminders[i].wantAgent?.pkgName);
      console.info("getValidReminders, wantAgent.abilityName = " + reminders[i].wantAgent?.abilityName);
      console.info("getValidReminders, ringDuration = " + reminders[i].ringDuration);
      console.info("getValidReminders, snoozeTimes = " + reminders[i].snoozeTimes);
      console.info("getValidReminders, timeInterval = " + reminders[i].timeInterval);
      console.info("getValidReminders, title = " + reminders[i].title);
      console.info("getValidReminders, content = " + reminders[i].content);
      console.info("getValidReminders, expiredContent = " + reminders[i].expiredContent);
      console.info("getValidReminders, snoozeContent = " + reminders[i].snoozeContent);
      console.info("getValidReminders, notificationId = " + reminders[i].notificationId);
      console.info("getValidReminders, slotType = " + reminders[i].slotType);
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
import { reminderAgentManager } from '@kit.BackgroundTasksKit';

reminderAgentManager.getValidReminders().then((reminders: Array<reminderAgentManager.ReminderRequest>) => {
  console.info("promise, getValidReminders length = " + reminders.length);
  for (let i = 0; i < reminders.length; i++) {
    console.info("getValidReminders = " + reminders[i]);
    console.info("getValidReminders, reminderType = " + reminders[i].reminderType);
    const actionButton = reminders[i].actionButton || [];
    for (let j = 0; j < actionButton.length; j++) {
      console.info("getValidReminders, actionButton.title = " + actionButton[j]?.title);
      console.info("getValidReminders, actionButton.type = " + actionButton[j]?.type);
    }
    console.info("getValidReminders, wantAgent.pkgName = " + reminders[i].wantAgent?.pkgName);
    console.info("getValidReminders, wantAgent.abilityName = " + reminders[i].wantAgent?.abilityName);
    console.info("getValidReminders, ringDuration = " + reminders[i].ringDuration);
    console.info("getValidReminders, snoozeTimes = " + reminders[i].snoozeTimes);
    console.info("getValidReminders, timeInterval = " + reminders[i].timeInterval);
    console.info("getValidReminders, title = " + reminders[i].title);
    console.info("getValidReminders, content = " + reminders[i].content);
    console.info("getValidReminders, expiredContent = " + reminders[i].expiredContent);
    console.info("getValidReminders, snoozeContent = " + reminders[i].snoozeContent);
    console.info("getValidReminders, notificationId = " + reminders[i].notificationId);
    console.info("getValidReminders, slotType = " + reminders[i].slotType);
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
import { reminderAgentManager } from '@kit.BackgroundTasksKit';

reminderAgentManager.cancelAllReminders((err: BusinessError) =>{
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.info("cancelAllReminders callback")
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
import { reminderAgentManager } from '@kit.BackgroundTasksKit';

reminderAgentManager.cancelAllReminders().then(() => {
  console.info("cancelAllReminders promise")
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
| slot | [NotificationSlot](../apis-notification-kit/js-apis-inner-notification-notificationSlot.md#notificationslot-1) | Yes| Notification slot instance. Only the **notificationType** property can be set.|
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
import { reminderAgentManager } from '@kit.BackgroundTasksKit';

let mySlot: notificationManager.NotificationSlot = {
  notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
}

reminderAgentManager.addNotificationSlot(mySlot, (err: BusinessError) => {
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.info("addNotificationSlot callback");
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
| slot | [NotificationSlot](../apis-notification-kit/js-apis-inner-notification-notificationSlot.md#notificationslot-1) | Yes| Notification slot instance. Only the **notificationType** property can be set.|

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
import { reminderAgentManager } from '@kit.BackgroundTasksKit';

let mySlot: notificationManager.NotificationSlot = {
  notificationType: notificationManager.SlotType.SOCIAL_COMMUNICATION
}
reminderAgentManager.addNotificationSlot(mySlot).then(() => {
  console.info("addNotificationSlot promise");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```

## reminderAgentManager.removeNotificationSlot

removeNotificationSlot(slotType: notification.SlotType, callback: AsyncCallback\<void>): void

Removes a specified notification slot. This API uses an asynchronous callback to return the result.

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
import { reminderAgentManager } from '@kit.BackgroundTasksKit';

reminderAgentManager.removeNotificationSlot(notificationManager.SlotType.CONTENT_INFORMATION,
  (err: BusinessError) => {
  if (err.code) {
    console.error("callback err code:" + err.code + " message:" + err.message);
  } else {
    console.info("removeNotificationSlot callback");
  }
});
```

## reminderAgentManager.removeNotificationSlot

removeNotificationSlot(slotType: notification.SlotType): Promise\<void>

Removes a specified notification slot. This API uses a promise to return the result.

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
import { reminderAgentManager } from '@kit.BackgroundTasksKit';

reminderAgentManager.removeNotificationSlot(notificationManager.SlotType.CONTENT_INFORMATION).then(() => {
  console.info("removeNotificationSlot promise");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```

## reminderAgentManager.getAllValidReminders<sup>12+</sup>

getAllValidReminders(): Promise\<Array\<ReminderInfo>>

Obtains all [valid (not yet expired) reminders](../../task-management/agent-powered-reminder.md#constraints) set by the current application. This API uses a promise to return the result. To call this API, you need to request the ohos.permission.PUBLISH_AGENT_REMINDER permission.

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
import { reminderAgentManager } from '@kit.BackgroundTasksKit';

reminderAgentManager.getAllValidReminders().then((reminders: Array<reminderAgentManager.ReminderInfo>) => {
  console.info("promise, getAllValidReminders length = " + reminders.length);
  for (let i = 0; i < reminders.length; i++) {
    console.info("getAllValidReminders, reminderId = " + reminders[i].reminderId);
    console.info("getAllValidReminders, reminderType = " + reminders[i].reminderReq.reminderType);
    const actionButton = reminders[i].reminderReq.actionButton || [];
    for (let j = 0; j < actionButton.length; j++) {
      console.info("getAllValidReminders, actionButton.title = " + actionButton[j]?.title);
      console.info("getAllValidReminders, actionButton.type = " + actionButton[j]?.type);
    }
    console.info("getAllValidReminders, wantAgent.pkgName = " + reminders[i].reminderReq.wantAgent?.pkgName);
    console.info("getAllValidReminders, wantAgent.abilityName = " + reminders[i].reminderReq.wantAgent?.abilityName);
    console.info("getAllValidReminders, ringDuration = " + reminders[i].reminderReq.ringDuration);
    console.info("getAllValidReminders, snoozeTimes = " + reminders[i].reminderReq.snoozeTimes);
    console.info("getAllValidReminders, timeInterval = " + reminders[i].reminderReq.timeInterval);
    console.info("getAllValidReminders, title = " + reminders[i].reminderReq.title);
    console.info("getAllValidReminders, content = " + reminders[i].reminderReq.content);
    console.info("getAllValidReminders, expiredContent = " + reminders[i].reminderReq.expiredContent);
    console.info("getAllValidReminders, snoozeContent = " + reminders[i].reminderReq.snoozeContent);
    console.info("getAllValidReminders, notificationId = " + reminders[i].reminderReq.notificationId);
    console.info("getAllValidReminders, slotType = " + reminders[i].reminderReq.slotType);
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
| reminderId | number | Yes  | ID of the agent-powered reminder to be added. The reminder ID is returned when the [reminderAgentManager.publishReminder](#reminderagentmanagerpublishreminder) API is called.|
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
import { reminderAgentManager } from '@kit.BackgroundTasksKit';

let reminderId: number = 1;
let date = new Date();
reminderAgentManager.addExcludeDate(reminderId, date).then(() => {
  console.info("addExcludeDate promise");
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
| reminderId | number | Yes  | ID of the agent-powered reminder to be deleted. The reminder ID is returned when the [reminderAgentManager.publishReminder](#reminderagentmanagerpublishreminder) API is called.|

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
import { reminderAgentManager } from '@kit.BackgroundTasksKit';

let reminderId: number = 1;
reminderAgentManager.deleteExcludeDates(reminderId).then(() => {
  console.info("deleteExcludeDates promise");
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
| reminderId | number | Yes  | ID of the agent-powered reminder to be queried. The reminder ID is returned when the [reminderAgentManager.publishReminder](#reminderagentmanagerpublishreminder) API is called.|

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
import { reminderAgentManager } from '@kit.BackgroundTasksKit';

let reminderId: number = 1;
reminderAgentManager.getExcludeDates(reminderId).then((dates) => {
  console.info("getExcludeDates promise length: " + dates.length);
  for (let i = 0; i < dates.length; i++) {
    console.info("getExcludeDates promise date is: " + dates[i].toString());
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
| reminderId | number | Yes  | ID of the agent-powered reminder to be updated. The reminder ID is returned when the [reminderAgentManager.publishReminder](#reminderagentmanagerpublishreminder) API is called.|
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

## reminderAgentManager.cancelReminderOnDisplay<sup>23+</sup>

cancelReminderOnDisplay(reminderId: number): Promise\<void>

Cancels the notification card displayed in the notification center with the agent reminder data retained. For example, for a daily repeating reminder, calling this API removes the card from the notification center, but the reminder will be triggered again the next day according to its schedule.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | ---------------------------------- |
| reminderId | number | Yes  | ID of the agent-powered reminder to be canceled. The reminder ID is returned when the [reminderAgentManager.publishReminder](#reminderagentmanagerpublishreminder) API is called.|

**Return value**

| Type                  | Description                             |
| ---------------------- | --------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](errorcode-reminderAgentManager.md).

| ID| Error Message                    |
| -------- | ---------------------------- |
| 1700003  | The reminder does not exist. |
| 1700007  | If the input parameter is not valid parameter. |

**Example**

```ts
import { reminderAgentManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';

let reminderId: number = 1;
reminderAgentManager.cancelReminderOnDisplay(reminderId).then(() => {
  console.info("cancel display reminder  succeed");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```

## reminderAgentManager.subscribeReminderState<sup>23+</sup>

subscribeReminderState(callback: Callback\<Array\<ReminderState>>): Promise\<void>

Subscribes to agent-powered reminder state changes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.PUBLISH_AGENT_REMINDER

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | ---------------------------------- |
| callback | Callback\<Array\<[ReminderState](#reminderstate23)>> | Yes  | Callback used to return the agent-powered reminder state.|

**Return value**

| Type                  | Description                             |
| ---------------------- | --------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [reminderAgentManager Error Codes](errorcode-reminderAgentManager.md).

| ID| Error Message                    |
| -------- | ---------------------------- |
| 201      | Permission denied.           |
| 1700007  | If the input parameter is not valid parameter. |

**Example**

``` ts
import { reminderAgentManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';

function reminderStateCallback(states: Array<reminderAgentManager.ReminderState>) {
  console.info('length is : ' + states.length);
}

reminderAgentManager.subscribeReminderState(reminderStateCallback).then(() => {
  console.info('subscribe succeed');
}).catch((err: BusinessError) => {
  console.error('promise err code:' + err.code + ' message:' + err.message);
});
```

## reminderAgentManager.unsubscribeReminderState<sup>23+</sup>

unsubscribeReminderState(callback?: Callback\<Array\<ReminderState>>): Promise\<void>

Unsubscribes from agent-powered reminder state changes. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | ---------------------------------- |
| callback | Callback\<Array\<[ReminderState](#reminderstate23)>> | No  | Callback used to return the result. If the **callback** parameter is not passed, all subscriptions are canceled.|

**Return value**

| Type                  | Description                             |
| ---------------------- | --------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](errorcode-reminderAgentManager.md).

| ID| Error Message                    |
| -------- | ---------------------------- |
| 1700007  | If the input parameter is not valid parameter. |

**Example**

``` ts
import { reminderAgentManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';

function reminderStateCallback(states: Array<reminderAgentManager.ReminderState>) {
  console.info('length is : ' + states.length);
}

reminderAgentManager.unsubscribeReminderState(reminderStateCallback).then(() => {
  console.info('unsubscribe succeed');
}).catch((err: BusinessError) => {
  console.error('promise err code:' + err.code + ' message:' + err.message);
});
```

## ActionButtonType

Enumerates the types of buttons displayed for a reminder.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Value| Description|
| -------- | -------- | -------- |
| ACTION_BUTTON_TYPE_CLOSE | 0 | Button for closing the reminder.|
| ACTION_BUTTON_TYPE_SNOOZE | 1 | Button for snoozing the reminder, with the frequency and timing configured via **snoozeTimes** and **timeInterval** in the [ReminderRequest](#reminderrequest) struct.|

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
| RING_CHANNEL_NOTIFICATION<sup>23+</sup> | 2 | Notification slot.|

## TimeZoneType

Enumerates the time zone types. When the time zone is changed, the reminder time is recalculated based on the new time zone.

**Since**: 26.0.0

**System capability**: SystemCapability.Notification.ReminderAgent

**Model restriction**: This API can be used only in the stage model.

| Name| Value| Description|
| -------- | -------- | -------- |
| DEFAULT | 0 | Default value. When the time zone is changed, the reminder time is calculated in the same way as that for the time zone type of **FIXED_TIME_ZONE**. When the time is changed, the reminder time is calculated in the same way as that for the time zone type of **SYSTEM_TIME_ZONE**. You are advised to set the time zone type to **FIXED_TIME_ZONE** or **SYSTEM_TIME_ZONE** based on the service scenario.|
| FIXED_TIME_ZONE | 1 | Fixed time zone, which is used in scenarios such as ticket booking and meetings. For example, if the reminder time is set to 08:00 (GMT+8), the reminder will be triggered at 08:00 (GMT+8) no matter whether the device time zone is changed. If the device time zone is changed to GMT+4, the reminder will be triggered at 04:00. The reminder time is not affected by the change of the system time.|
| SYSTEM_TIME_ZONE | 2 | System time zone, which is used in scenarios such as setting the alarm clock, fixed time for exercise, and sleep time. For example, if the reminder time is set to 08:00 (GMT+8), and the time zone is changed to GMT+4, the reminder will still be triggered at 08:00. The reminder time is not affected by the change of the system time.|

## ActionButton

Describes the button displayed for a reminder.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| title | string | No| No| Text on the button.|
| titleResource<sup>11+</sup> | string | No| Yes| Resource ID of the title. This parameter is used to read the title information after the system language is switched.|
| type | [ActionButtonType](#actionbuttontype) | No| No| Button type.|

## WantAgent

Defines the information about the redirected-to ability.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| pkgName | string | No| No| Name of the target package.|
| abilityName | string | No| No| Name of the target ability.|
| parameters<sup>12+</sup> | Record\<string, Object> | No| Yes| Parameters to be transferred to the target.|
| uri<sup>12+</sup> | string | No| Yes| URI of the target ability.|

## MaxScreenWantAgent

Describes the information about the ability that is started automatically and displayed in full-screen mode when a reminder is displayed in the notification center. This API is reserved.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| pkgName | string | No| No| Name of the target package. (If the device is in use, only a notification banner is displayed.)|
| abilityName | string | No| No| Name of the target ability. (If the device is in use, only a notification banner is displayed.)|

## NotificationRequestProxy

Sends a notification request message.

**Since**: 26.0.0

**System capability**: SystemCapability.Notification.ReminderAgent

**Model restriction**: This API can be used only in the stage model.

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| appMessageId | string | No| Yes| Unique ID carried in a notification sent by an application, which is used for notification deduplication. This parameter is left empty by default. For details, see [NotificationRequest.appMessageId](../apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest-1).|
| isAlertOnce | boolean | No| Yes| Whether to send a notification alert only once when a notification is published or updated. The default value is **false**. For details, see [NotificationRequest.isAlertOnce](../apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest-1).<br> - **true**: An alert is sent only when the notification is published for the first time. For subsequent update, the alert mode is changed to [LEVEL_LOW](../apis-notification-kit/js-apis-notificationManager.md#slotlevel).<br> - **false**: The alert is sent in the configured alert mode.|

## ReminderRequest

Defines the request for publishing a reminder.

**System capability**: SystemCapability.Notification.ReminderAgent

<!--Table: 20%; 20%; 8%; 8%; 44%-->

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| reminderType | [ReminderType](#remindertype) | No| No| Type of the reminder.|
| actionButton | [[ActionButton?, ActionButton?, ActionButton?]](#actionbutton) | No| Yes| Buttons displayed for the reminder notification.<br>For third-party applications, a maximum of two buttons are supported.<br>For system applications, a maximum of three buttons are supported in API version 10 and later versions, and a maximum of two buttons are supported in versions earlier than API version 10.|
| wantAgent | [WantAgent](#wantagent) | No| Yes| Information about the ability that is redirected to when the reminder is clicked.|
| maxScreenWantAgent | [MaxScreenWantAgent](#maxscreenwantagent) | No| Yes| Information about the ability that is started automatically and displayed in full-screen mode when the reminder arrives. If the device is in use, only a notification banner is displayed.<br> This API is reserved.|
| ringDuration | number | No| Yes| Ringing duration.<br> The value ranges from 0 to1800, in seconds. The default value is **1**.<br>If the value is **0**, the system notification tone is used.<br>If the value is greater than 0 and [ReminderRequest.customRingUri](#reminderrequest) is set, the reminder rings on the specified channel [ReminderRequest.ringChannel](#reminderrequest). Otherwise, the custom notification tone of the agent-powered reminder is used.<br>The device vibrates when the reminder rings. Since API version 26.0.0, long vibration is supported, and the vibration duration is the same as the ring duration. In versions earlier than API 26.0.0, the device vibrates once quickly when the reminder rings.|
| snoozeTimes | number | No| Yes| Number of reminder snooze times. The default value is **0**. (It is not applicable to countdown reminders.)|
| timeInterval | number | No| Yes| Reminder snooze interval,<br> in seconds. The minimum value is 30s. (It is not applicable to countdown reminders.)|
| title | string | No| Yes| Reminder title.|
| titleResourceId<sup>18+</sup> | number | No| Yes| Resource ID of the reminder title, which can be obtained through $r(*resource-name*).id.|
| content | string | No| Yes| Reminder content.|
| contentResourceId<sup>18+</sup> | number | No| Yes| Resource ID of the reminder content, which can be obtained through $r(*resource-name*).id.|
| expiredContent | string | No| Yes| Content to be displayed after the reminder expires.|
| expiredContentResourceId<sup>18+</sup> | number | No| Yes| Resource ID of the content to be displayed after the reminder expires, which can be obtained through $r(*resource-name*).id.|
| snoozeContent | string | No| Yes| Content to be displayed when the reminder is snoozing. (It is not applicable to countdown reminders.)|
| snoozeContentResourceId<sup>18+</sup> | number | No| Yes| Resource ID of the content to be displayed when the reminder is snoozing, which can be obtained through $r(*resource-name*).id.|
| notificationId | number | No| Yes| Notification ID used by the reminder. You must pass in a notification ID. If there are reminders with the same notification ID, the later one will overwrite the earlier one. The default value is **0**.|
| groupId<sup>11+</sup> | string | No | Yes | Group ID used for the reminder. If "Don't ask again" or similar information is selected for the reminder, other reminders with the same group ID are also canceled. |
| slotType | [notification.SlotType](../apis-notification-kit/js-apis-notificationManager.md#slottype) | No| Yes| Type of the slot used by the reminder.|
| tapDismissed<sup>10+</sup> | boolean | No| Yes| Whether the reminder is automatically cleared. The default value is **true**. For details, see [NotificationRequest.tapDismissed](../apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest-1).<br> - **true** (default): The reminder is automatically cleared after the notification or button is tapped.<br> - **false**: The reminder is retained after the notification or button is tapped.|
| autoDeletedTime<sup>10+</sup> | number | No| Yes| Time when the notification is automatically cleared.<br> The data format is timestamp, in milliseconds. For details, please refer to [NotificationRequest.autoDeletedTime](../apis-notification-kit/js-apis-inner-notification-notificationRequest.md#notificationrequest-1).|
| snoozeSlotType<sup>11+</sup> | [notification.SlotType](../apis-notification-kit/js-apis-notificationManager.md#slottype) | No| Yes| Type of the slot used by the snoozed reminder. (It is not applicable to countdown reminders.)|
| customRingUri<sup>11+</sup> | string | No| Yes| URI of the custom prompt tone. The prompt tone file must be stored in the **resources/rawfile** directory and supports formats such as M4A, AAC, MP3, OGG, WAV, FLAC, and AMR.|
| ringChannel<sup>20+</sup> | [RingChannel](#ringchannel20) | No| Yes| Audio channel of the custom prompt tone. The default channel is the alarm channel.|
| fixedTimeZone | [TimeZoneType](#timezonetype) | No| Yes| Time zone type. The default value is **TimeZoneType.DEFAULT**.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| notificationRequestProxy | [NotificationRequestProxy](#notificationrequestproxy) | No| Yes| Notification request message. This parameter is left empty by default.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|

## ReminderRequestCalendar

ReminderRequestCalendar extends ReminderRequest

Defines a reminder for a calendar event.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| dateTime | [LocalDateTime](#localdatetime) | No| No| Reminder time.|
| repeatMonths | Array\<number> | No| Yes| Month in which the reminder repeats. The value range is [1, 12]. This parameter is left empty by default. This parameter must be used together with **repeatDays**.|
| repeatDays | Array\<number> | No| Yes| Day in which the reminder repeats. The value range is [1, 31]. This parameter is left empty by default. This parameter must be used together with **repeatMonths**.|
| daysOfWeek<sup>11+</sup> | Array\<number> | No| Yes| Days of a week when the reminder repeats. The value ranges from 1 to 7, corresponding to the data from Monday to Sunday. This parameter is left empty by default.|
| endDateTime<sup>12+</sup> | [LocalDateTime](#localdatetime) | No| Yes| End time of the reminder.|

## ReminderRequestAlarm

ReminderRequestAlarm extends ReminderRequest

Defines a reminder for an alarm.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| hour | number | No| No| Hour portion of the reminder time. The value range is [0, 23].|
| minute | number | No| No| Minute portion of the reminder time. The value range is [0, 59].|
| daysOfWeek | Array\<number> | No| Yes| Days of a week when the reminder repeats. The value ranges from 1 to 7, corresponding to the data from Monday to Sunday. This parameter is left empty by default.|

## ReminderRequestTimer

ReminderRequestTimer extends ReminderRequest

Defines a reminder for a scheduled timer.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| triggerTimeInSeconds | number | No| No| Number of seconds in the countdown timer.<br> Unit: s|
| repeatInterval | number | No| Yes| Repeat interval. There is no default value. If no value is set, there is no repeat interval. This parameter must be used together with **repeatCount**.<br>The value range is [86400, +∞), in seconds. If the value is out of range, error code 401 is returned.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| repeatCount | number | No| Yes| Number of repetitions. The default value is **0**, indicating infinite repetitions. This parameter must be used together with **repeatInterval**.<br>The value range is [0, +∞). If the value is out of range, error code 401 is returned.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|

## LocalDateTime

Defines the time information for a calendar reminder.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| year | number | No| No| Year.|
| month | number | No| No| Month. The value ranges from 1 to 12.|
| day | number | No| No| Day. The value ranges from 1 to 31.|
| hour | number | No| No| Hour. The value ranges from 0 to 23.|
| minute | number | No| No| Minute. The value ranges from 0 to 59.|
| second | number | No| Yes| Second. The value ranges from 0 to 59.|

## ReminderInfo<sup>12+</sup>

Defines the reminder information.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name       | Type                               | Read Only| Optional| Description                |
| ----------- | ----------------------------------- | ---- | ---- | -------------------- |
| reminderId  | number                              | No  | No  | Reminder ID.|
| reminderReq | [ReminderRequest](#reminderrequest) | No  | No  | Request used for publishing the reminder.      |

## ReminderState<sup>23+</sup>

Defines the agent-powered reminder state information, for which notifications are triggered in the following scenarios:<br>

1. When a user taps a button on an agent-powered reminder notification, a notification specifying the tapped button type is sent to the application if it is running. If the application is not running, the notification will not be received.

2. Since the above scenario cannot guarantee that the application receives the notification, all callbacks associated with user-tapped button types under the application are returned to the application when it registers a new callback function. State information is retained for a maximum of 30 days. Cached state information is cleared when the application registers a new callback function or has not registered any callback function for more than 30 days. 

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name       | Type                                 | Read Only| Optional| Description                |
| ----------- | ------------------------------------- | ---- | ---- | -------------------- |
| reminderId  | number                                | No  | No  | Reminder ID.|
| buttonType  | [ActionButtonType](#actionbuttontype) | No  | No  | Button type.|
| isMessageResent | boolean | No  | No  | Whether a message is sent repeatedly.<br> - **false**: The message is sent for the first time. Applicable scenarios: The application is running when the user taps a button on the agent-powered reminder notification; the application is not running when the user taps the button, and the application registers a new callback function afterward.<br> - **true**: The message is sent repeatedly. Applicable scenario: The application is running and registers a new callback function after the user taps a button on the agent-powered reminder notification.|