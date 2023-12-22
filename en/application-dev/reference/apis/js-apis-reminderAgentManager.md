# @ohos.reminderAgentManager (Agent-Powered Reminders)

The **reminderAgentManager** module provides APIs related to agent-powered reminders. When your application is frozen or exits, the timing and notification functions of your application will be taken over by a system service running in the background. You can use the APIs to create scheduled reminders for countdown timers, calendar events, and alarm clocks.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import reminderAgentManager from '@ohos.reminderAgentManager';
```

## reminderAgentManager.publishReminder

publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback\<number>): void

Publishes a reminder. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API can be called only after the [Notification.requestEnableNotification](js-apis-notification.md#notificationrequestenablenotification8) permission is obtained.

**Required permissions**: ohos.permission.PUBLISH_AGENT_REMINDER

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | reminderReq | [ReminderRequest](#reminderrequest) | Yes| Request used for publishing the reminder.|
  | callback | AsyncCallback\<number> | Yes| Callback used to return the published reminder's ID.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](../errorcodes/errorcode-reminderAgentManager.md).

| ID  | Error Message|
| --------- | ------- |
| 1700001    | Notification is not enabled. |
| 1700002    | The number of reminders exceeds the limit. |

**Example**
```ts
import { BusinessError } from '@ohos.base';

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

> **NOTE**
>
> This API can be called only after the [Notification.requestEnableNotification](js-apis-notification.md#notificationrequestenablenotification8) permission is obtained.

**Required permissions**: ohos.permission.PUBLISH_AGENT_REMINDER

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | reminderReq | [ReminderRequest](#reminderrequest) | Yes| Request used for publishing the reminder.|

**Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise\<number> | Promise used to return the published reminder's ID.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](../errorcodes/errorcode-reminderAgentManager.md).

| ID  | Error Message|
| --------- | ------- |
| 1700001    | Notification is not enabled. |
| 1700002    | The number of reminders exceeds the limit. |

**Example**
```ts
import { BusinessError } from '@ohos.base';

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

For details about the error codes, see [reminderAgentManager Error Codes](../errorcodes/errorcode-reminderAgentManager.md).

| ID  | Error Message|
| --------- | ------- |
| 1700003    | The reminder does not exist. |
| 1700004    | The bundle name does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

For details about the error codes, see [reminderAgentManager Error Codes](../errorcodes/errorcode-reminderAgentManager.md).

| ID  | Error Message|
| --------- | ------- |
| 1700003    | The reminder does not exist. |
| 1700004    | The bundle name does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

let reminderId: number = 1;
reminderAgentManager.cancelReminder(reminderId).then(() => {
  console.log("cancelReminder promise");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```

## reminderAgentManager.getValidReminders

getValidReminders(callback: AsyncCallback<Array\<ReminderRequest>>): void

Obtains all valid (not yet expired) reminders set by the current application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<[ReminderRequest](#reminderrequest)>> | Yes| Callback used to return all the valid reminders.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](../errorcodes/errorcode-reminderAgentManager.md).

| ID  | Error Message|
| --------- | ------- |
| 1700004    | The bundle name does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
      console.log("getValidReminders, maxScreenWantAgent.pkgName = " + reminders[i].maxScreenWantAgent?.pkgName);
      console.log("getValidReminders, maxScreenWantAgent.abilityName = " + reminders[i].maxScreenWantAgent?.abilityName);
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

Obtains all valid (not yet expired) reminders set by the current application. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<Array\<[ReminderRequest](#reminderrequest)>> | Promise used to return all the valid reminders.|

**Error codes**

For details about the error codes, see [reminderAgentManager Error Codes](../errorcodes/errorcode-reminderAgentManager.md).

| ID  | Error Message|
| --------- | ------- |
| 1700004    | The bundle name does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
    console.log("getValidReminders, maxScreenWantAgent.pkgName = " + reminders[i].maxScreenWantAgent?.pkgName);
    console.log("getValidReminders, maxScreenWantAgent.abilityName = " + reminders[i].maxScreenWantAgent?.abilityName);
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

For details about the error codes, see [reminderAgentManager Error Codes](../errorcodes/errorcode-reminderAgentManager.md).

| ID  | Error Message|
| --------- | ------- |
| 1700004    | The bundle name does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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

For details about the error codes, see [reminderAgentManager Error Codes](../errorcodes/errorcode-reminderAgentManager.md).

| ID  | Error Message|
| --------- | ------- |
| 1700004    | The bundle name does not exist. |

**Example**

```ts
import { BusinessError } from '@ohos.base';

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
| slot | [NotificationSlot](js-apis-notification.md#notificationslot) | Yes| Notification slot. Only the type can be set.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the notification slot is added, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```ts
import notification from '@ohos.notificationManager'
import { BusinessError } from '@ohos.base';

let mySlot: notification.NotificationSlot = {
  type: notification.SlotType.SOCIAL_COMMUNICATION
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
| slot | [NotificationSlot](js-apis-notification.md#notificationslot) | Yes| Notification slot. Only the type can be set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import notification from '@ohos.notificationManager'
import { BusinessError } from '@ohos.base';

let mySlot: notification.NotificationSlot = {
  type: notification.SlotType.SOCIAL_COMMUNICATION
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
| slotType | [notification.SlotType](js-apis-notification.md#slottype) | Yes| Type of the notification slot to remove.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the notification slot is removed, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```ts
import notification from '@ohos.notificationManager'
import { BusinessError } from '@ohos.base';

reminderAgentManager.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION,
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
| slotType | [notification.SlotType](js-apis-notification.md#slottype) | Yes| Type of the notification slot to remove.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import notification from '@ohos.notificationManager'
import { BusinessError } from '@ohos.base';

reminderAgentManager.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION).then(() => {
  console.log("removeNotificationSlot promise");
}).catch((err: BusinessError) => {
  console.error("promise err code:" + err.code + " message:" + err.message);
});
```

## ActionButtonType

Enumerates the button types.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Value| Description|
| -------- | -------- | -------- |
| ACTION_BUTTON_TYPE_CLOSE | 0 | Button for closing the reminder.|
| ACTION_BUTTON_TYPE_SNOOZE | 1 | Button for snoozing the reminder.|
| ACTION_BUTTON_TYPE_CUSTOM<sup>10+</sup>  | 2 | Custom button.<br>**System API**: This is a system API and cannot be called by third-party applications.|


## ReminderType

Enumerates the reminder types.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Value| Description|
| -------- | -------- | -------- |
| REMINDER_TYPE_TIMER | 0 | Countdown reminder.|
| REMINDER_TYPE_CALENDAR | 1 | Calendar reminder.|
| REMINDER_TYPE_ALARM | 2 | Alarm reminder.|


## ActionButton

Defines the button on the reminder displayed.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| title | string | Yes| Text on the button.|
| titleResource<sup>11+</sup> | string | No| Resource ID of the title. This parameter is used to read the title information after the system language is switched.|
| type | [ActionButtonType](#actionbuttontype) | Yes| Button type.|
| wantAgent<sup>10+</sup> | [WantAgent](#wantagent) | No| Information about the ability that is displayed after the button is clicked.<br>**System API**: This is a system API and cannot be called by third-party applications.|
| dataShareUpdate<sup>11+</sup> | [DataShareUpdate](#datashareupdate11) | No| The application database will be updated after a click on the button.<br>**System API**: This is a system API and cannot be called by third-party applications.|


## WantAgent

Defines the information about the redirected-to ability.

**System capability**: SystemCapability.Notification.ReminderAgent


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pkgName | string | Yes| Name of the target package.|
| abilityName | string | Yes| Name of the target ability.|
| uri<sup>10+</sup> | string | No| URI of the target ability.<br>**System API**: This is a system API and cannot be called by third-party applications.|

## DataShareUpdate<sup>11+</sup>

Defines the parameter information used to update the database.

The data provider needs to set the ID, read/write permissions, and basic information of the table to be shared under **proxyDatas** in the **module.json5** file. For details about the configuration method, see [Data Proxy](../../database/share-data-by-silent-access.md).

**System capability**: SystemCapability.Notification.ReminderAgent


| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI of the data, which is the unique identifier for cross-application data access.<br>**System API**: This is a system API and cannot be called by third-party applications.|
| equalTo | Record<string, number \| string \| boolean> | Yes| Filter criteria. Currently, only equal to is supported.<br>**System API**: This is a system API and cannot be called by third-party applications.|
| value | [ValueBucket](js-apis-data-valuesBucket.md#valuesbucket) | Yes| New data.<br>**System API**: This is a system API and cannot be called by third-party applications.|


## MaxScreenWantAgent

Provides the information about the ability that is started automatically and displayed in full-screen mode when the reminder arrives. This API is reserved.

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
| actionButton | [[ActionButton?, ActionButton?, ActionButton?]](#actionbutton) | No| Buttons displayed for the reminder in the notification panel.<br>- For common applications, a maximum of two buttons are supported.<br>- For system applications, a maximum of two buttons are supported in API version 9, and a maximum of three buttons are supported in API version 10 and later versions.|
| wantAgent | [WantAgent](#wantagent) | No| Information about the ability that is redirected to when the reminder is clicked.|
| maxScreenWantAgent | [MaxScreenWantAgent](#maxscreenwantagent) | No| Information about the ability that is started automatically and displayed in full-screen mode when the reminder arrives. If the device is in use, only a notification banner is displayed.<br> This API is reserved.|
| ringDuration | number | No| Ringing duration, in seconds. The default value is **1**.|
| snoozeTimes | number | No| Number of reminder snooze times. The default value is **0**. (It is not applicable to countdown reminders.)|
| timeInterval | number | No| Reminder snooze interval, in seconds. The minimum value is 5 minutes. (It is not applicable to countdown reminders.)|
| title | string | No| Reminder title.|
| content | string | No| Reminder content.|
| expiredContent | string | No| Content to be displayed after the reminder expires.|
| snoozeContent | string | No| Content to be displayed when the reminder is snoozing. (It is not applicable to countdown reminders.)|
| notificationId | number | No| Notification ID used by the reminder. If there are reminders with the same notification ID, the later one will overwrite the earlier one.|
| groupId<sup>11+</sup> | string | No| Group ID used for the reminder. If "Don't ask again" or similar information is selected for the reminder, other reminders with the same group ID are also canceled.|
| slotType | [notification.SlotType](js-apis-notificationManager.md#slottype) | No| Type of the slot used by the reminder.|
| tapDismissed<sup>10+</sup> | boolean | No| Whether the reminder is automatically cleared. For details, see [NotificationRequest.tapDismissed](js-apis-inner-notification-notificationRequest.md#notificationrequest). |
| autoDeletedTime<sup>10+</sup> | number | No| Time when the reminder is automatically cleared. For details, see [NotificationRequest.autoDeletedTime](js-apis-inner-notification-notificationRequest.md#notificationrequest).|
| snoozeSlotType<sup>11+</sup> | [notification.SlotType](js-apis-notificationManager.md#slottype) | No| Type of the slot used by the reminder. (It is not applicable to countdown reminders.)|
| customRingUri<sup>11+</sup> | string | No| URI of the custom prompt tone.|

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

Sets the time information for a calendar reminder.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| year | number | Yes| Year.|
| month | number | Yes| Month. The value ranges from 1 to 12.|
| day | number | Yes| Day. The value ranges from 1 to 31.|
| hour | number | Yes| Hour. The value ranges from 0 to 23.|
| minute | number | Yes| Minute. The value ranges from 0 to 59.|
| second | number | No| Second. The value ranges from 0 to 59.|
