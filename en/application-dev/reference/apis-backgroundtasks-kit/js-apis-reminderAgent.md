# @ohos.reminderAgent (reminderAgent)

The **reminderAgent** module provides APIs for publishing scheduled reminders through the reminder agent.

You can use the APIs to create scheduled reminders for countdown timers, calendar events, and alarm clocks. When the created reminders are published, the timing and pop-up notification functions of your application will be taken over by the reminder agent in the background when your application is frozen or exits.

> **NOTE**
>
> This module is deprecated since API version 9. You are advised to use [@ohos.reminderAgentManager](js-apis-reminderAgentManager.md) instead.
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import reminderAgent from'@ohos.reminderAgent';
```


## reminderAgent.publishReminder<sup>(deprecated)</sup>

publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback\<number>): void

Publishes a reminder through the reminder agent. This API uses an asynchronous callback to return the result. It can be called only when notification is enabled for the application through [Notification.requestEnableNotification](../apis-notification-kit/js-apis-notification.md#notificationrequestenablenotification8).

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.publishReminder](js-apis-reminderAgentManager.md#reminderagentmanagerpublishreminder).

**Required permissions**: ohos.permission.PUBLISH_AGENT_REMINDER

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | reminderReq | [ReminderRequest](#reminderrequestdeprecated) | Yes| Reminder to be published.|
  | callback | AsyncCallback\<number> | Yes| Callback used to return the published reminder's ID.|

**Example**
```ts
import { BusinessError } from '@ohos.base';

let timer:reminderAgent.ReminderRequestTimer = {
  reminderType: reminderAgent.ReminderType.REMINDER_TYPE_TIMER,
  triggerTimeInSeconds: 10
}

reminderAgent.publishReminder(timer, (err: BusinessError, reminderId: number) => {
  console.log("callback, reminderId = " + reminderId);
});
```


## reminderAgent.publishReminder<sup>(deprecated)</sup>

publishReminder(reminderReq: ReminderRequest): Promise\<number>

Publishes a reminder through the reminder agent. This API uses a promise to return the result. It can be called only when notification is enabled for the application through [Notification.requestEnableNotification](../apis-notification-kit/js-apis-notification.md#notificationrequestenablenotification8).

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.publishReminder](js-apis-reminderAgentManager.md#reminderagentmanagerpublishreminder-1).

**Required permissions**: ohos.permission.PUBLISH_AGENT_REMINDER

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | reminderReq | [ReminderRequest](#reminderrequestdeprecated) | Yes| Reminder to be published.|

**Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise\<number> | Promise used to return the published reminder's ID.|

**Example**
```ts
let timer:reminderAgent.ReminderRequestTimer = {
  reminderType: reminderAgent.ReminderType.REMINDER_TYPE_TIMER,
  triggerTimeInSeconds: 10
}

reminderAgent.publishReminder(timer).then((reminderId: number) => {
  console.log("promise, reminderId = " + reminderId);
});
```


## reminderAgent.cancelReminder<sup>(deprecated)</sup>

cancelReminder(reminderId: number, callback: AsyncCallback\<void>): void

Cancels the reminder with the specified ID. This API uses an asynchronous callback to return the cancellation result.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.cancelReminder](js-apis-reminderAgentManager.md#reminderagentmanagercancelreminder).

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| reminderId | number | Yes| ID of the reminder.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

reminderAgent.cancelReminder(1, (err: BusinessError, data: void) => {
  console.log("cancelReminder callback");
});
```


## reminderAgent.cancelReminder<sup>(deprecated)</sup>

cancelReminder(reminderId: number): Promise\<void>

Cancels the reminder with the specified ID. This API uses a promise to return the cancellation result.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.cancelReminder](js-apis-reminderAgentManager.md#reminderagentmanagercancelreminder-1).

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| reminderId | number | Yes| ID of the reminder.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
reminderAgent.cancelReminder(1).then(() => {
    console.log("cancelReminder promise");
});
```

## reminderAgent.getValidReminders<sup>(deprecated)</sup>

getValidReminders(callback: AsyncCallback\<Array\<ReminderRequest>>): void

Obtains all valid (not yet expired) reminders set by the current application. This API uses an asynchronous callback to return the reminders.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.getValidReminders](js-apis-reminderAgentManager.md#reminderagentmanagergetvalidreminders).

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<Array\<[ReminderRequest](#reminderrequestdeprecated)>> | Yes| Callback used to return an array of all valid reminders set by the current application.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

reminderAgent.getValidReminders((err: BusinessError, reminders: Array<reminderAgent.ReminderRequest>) => {
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
})
```


## reminderAgent.getValidReminders<sup>(deprecated)</sup>

getValidReminders(): Promise\<Array\<ReminderRequest>>

Obtains all valid (not yet expired) reminders set by the current application. This API uses a promise to return the reminders.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.getValidReminders](js-apis-reminderAgentManager.md#reminderagentmanagergetvalidreminders-1).

**System capability**: SystemCapability.Notification.ReminderAgent

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<Array\<[ReminderRequest](#reminderrequestdeprecated)>> | Promise used to return an array of all valid reminders set by the current application.|

**Example**

```ts
reminderAgent.getValidReminders().then((reminders: Array<reminderAgent.ReminderRequest>) => {
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
})

```


## reminderAgent.cancelAllReminders<sup>(deprecated)</sup>

cancelAllReminders(callback: AsyncCallback\<void>): void

Cancels all reminders set by the current application. This API uses an asynchronous callback to return the cancellation result.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.cancelAllReminders](js-apis-reminderAgentManager.md#reminderagentmanagercancelallreminders).

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

reminderAgent.cancelAllReminders((err: BusinessError, data: void) =>{
  console.log("cancelAllReminders callback")
})
```


## reminderAgent.cancelAllReminders<sup>(deprecated)</sup>

cancelAllReminders(): Promise\<void>

Cancels all reminders set by the current application. This API uses a promise to return the cancellation result.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.cancelAllReminders](js-apis-reminderAgentManager.md#reminderagentmanagercancelallreminders-1).

**System capability**: SystemCapability.Notification.ReminderAgent

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
reminderAgent.cancelAllReminders().then(() => {
    console.log("cancelAllReminders promise")
})
```

## reminderAgent.addNotificationSlot<sup>(deprecated)</sup>

addNotificationSlot(slot: NotificationSlot, callback: AsyncCallback\<void>): void

Adds a notification slot. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.addNotificationSlot](js-apis-reminderAgentManager.md#reminderagentmanageraddnotificationslot).

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| slot | [NotificationSlot](../apis-notification-kit/js-apis-notification.md#notificationslot) | Yes| Notification slot, whose type can be set.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

```ts
import notification from '@ohos.notificationManager'
import { BusinessError } from '@ohos.base';

let mySlot:notification.NotificationSlot = {
  type: notification.SlotType.SOCIAL_COMMUNICATION
}
reminderAgent.addNotificationSlot(mySlot, (err: BusinessError, data: void) => {
  console.log("addNotificationSlot callback");
});
```


## reminderAgent.addNotificationSlot<sup>(deprecated)</sup>

addNotificationSlot(slot: NotificationSlot): Promise\<void>

Adds a notification slot. This API uses a promise to return the result.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.addNotificationSlot](js-apis-reminderAgentManager.md#reminderagentmanageraddnotificationslot-1).

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| slot | [NotificationSlot](../apis-notification-kit/js-apis-notification.md#notificationslot) | Yes| Notification slot, whose type can be set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import notification from '@ohos.notificationManager'

let mySlot:notification.NotificationSlot = {
  type: notification.SlotType.SOCIAL_COMMUNICATION
}
reminderAgent.addNotificationSlot(mySlot).then(() => {
  console.log("addNotificationSlot promise");
});
```


## reminderAgent.removeNotificationSlot<sup>(deprecated)</sup>

removeNotificationSlot(slotType: notification.SlotType, callback: AsyncCallback\<void>): void

Removes a notification slot of a specified type. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.removeNotificationSlot](js-apis-reminderAgentManager.md#reminderagentmanagerremovenotificationslot).

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| slotType | [notification.SlotType](../apis-notification-kit/js-apis-notification.md#slottype) | Yes| Type of the reminder notification slot to remove.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

```ts
import notification from '@ohos.notification'
import { BusinessError } from '@ohos.base';

reminderAgent.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION, (err: BusinessError, data: void) => {
  console.log("removeNotificationSlot callback");
});
```


## reminderAgent.removeNotificationSlot<sup>(deprecated)</sup>

removeNotificationSlot(slotType: notification.SlotType): Promise\<void>

Removes a notification slot of a specified type. This API uses a promise to return the result.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.removeNotificationSlot](js-apis-reminderAgentManager.md#reminderagentmanagerremovenotificationslot-1).

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| slotType | [notification.SlotType](../apis-notification-kit/js-apis-notification.md#slottype) | Yes| Type of the reminder notification slot to remove.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import notification from '@ohos.notification'

reminderAgent.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION).then(() => {
    console.log("removeNotificationSlot promise");
});
```


## ActionButtonType<sup>(deprecated)</sup>

Enumerates the button types.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.ActionButtonType](js-apis-reminderAgentManager.md#actionbuttontype) instead.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Value| Description|
| -------- | -------- | -------- |
| ACTION_BUTTON_TYPE_CLOSE | 0 | Button for closing the reminder.|
| ACTION_BUTTON_TYPE_SNOOZE | 1 | Button for snoozing the reminder.|


## ReminderType<sup>(deprecated)</sup>

Enumerates reminder types.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.ReminderType](js-apis-reminderAgentManager.md#remindertype) instead.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Value| Description|
| -------- | -------- | -------- |
| REMINDER_TYPE_TIMER | 0 | Countdown reminder.|
| REMINDER_TYPE_CALENDAR | 1 | Calendar reminder.|
| REMINDER_TYPE_ALARM | 2 | Alarm reminder.|


## ActionButton<sup>(deprecated)</sup>

Defines a button displayed in the reminder notification.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.ActionButton](js-apis-reminderAgentManager.md#actionbutton) instead.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| title | string | Yes| Text on the button.|
| type | [ActionButtonType](#actionbuttontypedeprecated) | Yes| Button type.|


## WantAgent<sup>(deprecated)</sup>

Sets the package and ability that are redirected to when the reminder notification is clicked.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.WantAgent](js-apis-reminderAgentManager.md#wantagent) instead.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pkgName | string | Yes| Name of the HAP that is redirected to when the reminder notification is clicked.|
| abilityName | string | Yes| Name of the ability that is redirected to when the reminder notification is clicked.|


## MaxScreenWantAgent<sup>(deprecated)</sup>

Provides the information about the target package and ability to start automatically when the reminder is displayed in full-screen mode. This API is reserved.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.MaxScreenWantAgent](js-apis-reminderAgentManager.md#maxscreenwantagent).

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pkgName | string | Yes| Name of the HAP that is automatically started when the reminder arrives and the device is not in use.|
| abilityName | string | Yes| Name of the ability that is automatically started when the reminder arrives and the device is not in use.|


## ReminderRequest<sup>(deprecated)</sup>

Defines the reminder to publish.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.ReminderRequest](js-apis-reminderAgentManager.md#reminderrequest) instead.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| reminderType | [ReminderType](#remindertypedeprecated) | Yes| Type of the reminder.|
| actionButton | [[ActionButton?, ActionButton?]](#actionbuttondeprecated) | No| Button displayed in the reminder notification. (The parameter is optional. Up to two buttons are supported.)|
| wantAgent | WantAgent | No| Information about the ability that is redirected to when the notification is clicked.|
| maxScreenWantAgent | [MaxScreenWantAgent](#maxscreenwantagentdeprecated) | No| Information about the ability that is automatically started when the reminder arrives. If the device is in use, a notification will be displayed.|
| ringDuration | number | No| Ringing duration, in seconds. The default value is **1**.|
| snoozeTimes | number | No| Number of reminder snooze times. The default value is **0**.|
| timeInterval | number | No| Reminder snooze interval, in seconds. The default value is **0**.|
| title | string | No| Reminder title.|
| content | string | No| Reminder content.|
| expiredContent | string | No| Content to be displayed after the reminder expires.|
| snoozeContent | string | No| Content to be displayed when the reminder is snoozing.|
| notificationId | number | No| Notification ID used by the reminder. If there are reminders with the same notification ID, the later one will overwrite the earlier one.|
| slotType | [notification.SlotType](../apis-notification-kit/js-apis-notification.md#slottype) | No| Type of the slot used by the reminder.|


## ReminderRequestCalendar<sup>(deprecated)</sup>


Defines a reminder for a calendar event.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.ReminderRequestCalendar](js-apis-reminderAgentManager.md#reminderrequestcalendar) instead.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| dateTime | [LocalDateTime](#localdatetimedeprecated) | Yes| Reminder time.|
| repeatMonths | Array\<number> | No| Month in which the reminder repeats.|
| repeatDays | Array\<number> | No| Date on which the reminder repeats.|


## ReminderRequestAlarm<sup>(deprecated)</sup>


Defines a reminder for an alarm.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.ReminderRequestAlarm](js-apis-reminderAgentManager.md#reminderrequestalarm) instead.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| hour | number | Yes| Hour portion of the reminder time.|
| minute | number | Yes| Minute portion of the reminder time.|
| daysOfWeek | Array\<number> | No| Days of a week when the reminder repeats. The value ranges from 1 to 7, corresponding to the data from Monday to Sunday.|


## ReminderRequestTimer<sup>(deprecated)</sup>

Defines a reminder for a scheduled timer.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.ReminderRequestTimer](js-apis-reminderAgentManager.md#reminderrequesttimer) instead.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| triggerTimeInSeconds | number | Yes| Number of seconds in the countdown timer.|


## LocalDateTime<sup>(deprecated)</sup>

Sets the time information for a calendar reminder.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [reminderAgentManager.LocalDateTime](js-apis-reminderAgentManager.md#localdatetime) instead.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| year | number | Yes| Year.|
| month | number | Yes| Month.|
| day | number | Yes| Date.|
| hour | number | Yes| Hour.|
| minute | number | Yes| Minute.|
| second | number | No| Second.|
