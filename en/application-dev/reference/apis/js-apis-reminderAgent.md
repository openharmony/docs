# reminderAgent

The **reminderAgent** module provides APIs for publishing scheduled reminders through the reminder agent.

You can set your application to use the reminder agent APIs to create scheduled reminders for countdown timers, calendar events, and alarm clocks. When the created reminders are published, the timing and pop-up notification functions of your application will be taken over by the reminder agent in the background when your application is frozen or exits.

> **NOTE**
>
> This module is deprecated since API version 9. You are advised to use [@ohos.reminderAgentManager](js-apis-reminderAgentManager.md) instead.
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import reminderAgent from'@ohos.reminderAgent';
```


## reminderAgent.publishReminder

publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback&lt;number&gt;): void

Publishes a reminder through the reminder agent. This API uses an asynchronous callback to return the result. It can be called only when notification is enabled for the application through [Notification.requestEnableNotification](js-apis-notification.md#notificationrequestenablenotification8).

**Required permissions**: ohos.permission.PUBLISH_AGENT_REMINDER

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | reminderReq | [ReminderRequest](#reminderrequest) | Yes| Reminder to be published.|
  | callback | AsyncCallback&lt;number&gt; | Yes| Asynchronous callback used to return the published reminder's ID.|

**Example**
```js
  let timer = {
      reminderType: reminderAgent.ReminderType.REMINDER_TYPE_TIMER,
      triggerTimeInSeconds: 10
  }
  reminderAgent.publishReminder(timer, (err, reminderId) => {
      console.log("callback, reminderId = " + reminderId);
  });
```


## reminderAgent.publishReminder

publishReminder(reminderReq: ReminderRequest): Promise&lt;number&gt;

Publishes a reminder through the reminder agent. This API uses a promise to return the result. It can be called only when notification is enabled for the application through [Notification.requestEnableNotification](js-apis-notification.md#notificationrequestenablenotification8).

**Required permissions**: ohos.permission.PUBLISH_AGENT_REMINDER

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**
  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | reminderReq | [ReminderRequest](#reminderrequest) | Yes| Reminder to be published.|

**Return value**
  | Type| Description|
  | -------- | -------- |
  | Promise&lt;number&gt; | Promise used to return the published reminder's ID.|

**Example**
```js
  let timer = {
      reminderType: reminderAgent.ReminderType.REMINDER_TYPE_TIMER,
      triggerTimeInSeconds: 10
  }
  reminderAgent.publishReminder(timer).then((reminderId) => {
      console.log("promise, reminderId = " + reminderId);
  });
```


## reminderAgent.cancelReminder

cancelReminder(reminderId: number, callback: AsyncCallback&lt;void&gt;): void

Cancels the reminder with the specified ID. This API uses an asynchronous callback to return the cancellation result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| reminderId | number | Yes| ID of the reminder to cancel. The value is obtained by calling [publishReminder](#reminderagentpublishreminder).|
| callback | AsyncCallback&lt;void&gt; | Yes| Asynchronous callback used to return the result.|

**Example**

```js
reminderAgent.cancelReminder(1, (err, data) => {
    console.log("cancelReminder callback");
});
```


## reminderAgent.cancelReminder

cancelReminder(reminderId: number): Promise&lt;void&gt;

Cancels the reminder with the specified ID. This API uses a promise to return the cancellation result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| reminderId | number | Yes| ID of the reminder to cancel. The value is obtained by calling [publishReminder](#reminderagentpublishreminder).|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
reminderAgent.cancelReminder(1).then(() => {
    console.log("cancelReminder promise");
});
```


## reminderAgent.getValidReminders

getValidReminders(callback: AsyncCallback&lt;Array&lt;ReminderRequest&gt;&gt;): void

Obtains all valid (not yet expired) reminders set by the current application. This API uses an asynchronous callback to return the reminders.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;Array&lt;[ReminderRequest](#reminderrequest)&gt;&gt; | Yes| Asynchronous callback used to return an array of all valid reminders set by the current application.|

**Example**

```js
reminderAgent.getValidReminders((err, reminders) => {
    console.log("callback, getValidReminders length = " + reminders.length);
    for (let i = 0; i < reminders.length; i++) {
        console.log("getValidReminders = " + reminders[i]);
        console.log("getValidReminders, reminderType = " + reminders[i].reminderType);
        for (let j = 0; j < reminders[i].actionButton.length; j++) {
            console.log("getValidReminders, actionButton.title = " + reminders[i].actionButton[j].title);
            console.log("getValidReminders, actionButton.type = " + reminders[i].actionButton[j].type);
        }
        console.log("getValidReminders, wantAgent.pkgName = " + reminders[i].wantAgent.pkgName);
        console.log("getValidReminders, wantAgent.abilityName = " + reminders[i].wantAgent.abilityName);
        console.log("getValidReminders, maxScreenWantAgent.pkgName = " + reminders[i].maxScreenWantAgent.pkgName);
        console.log("getValidReminders, maxScreenWantAgent.abilityName = " + reminders[i].maxScreenWantAgent.abilityName);
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


## reminderAgent.getValidReminders

getValidReminders(): Promise&lt;Array&lt;ReminderRequest&gt;&gt;

Obtains all valid (not yet expired) reminders set by the current application. This API uses a promise to return the reminders.

**System capability**: SystemCapability.Notification.ReminderAgent

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;[ReminderRequest](#reminderrequest)&gt;&gt; | Promise used to return an array of all valid reminders set by the current application.|

**Example**

```js
reminderAgent.getValidReminders().then((reminders) => {
    console.log("promise, getValidReminders length = " + reminders.length);
    for (let i = 0; i < reminders.length; i++) {
        console.log("getValidReminders = " + reminders[i]);
        console.log("getValidReminders, reminderType = " + reminders[i].reminderType);
        for (let j = 0; j < reminders[i].actionButton.length; j++) {
            console.log("getValidReminders, actionButton.title = " + reminders[i].actionButton[j].title);
            console.log("getValidReminders, actionButton.type = " + reminders[i].actionButton[j].type);
        }
        console.log("getValidReminders, wantAgent.pkgName = " + reminders[i].wantAgent.pkgName);
        console.log("getValidReminders, wantAgent.abilityName = " + reminders[i].wantAgent.abilityName);
        console.log("getValidReminders, maxScreenWantAgent.pkgName = " + reminders[i].maxScreenWantAgent.pkgName);
        console.log("getValidReminders, maxScreenWantAgent.abilityName = " + reminders[i].maxScreenWantAgent.abilityName);
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


## reminderAgent.cancelAllReminders

cancelAllReminders(callback: AsyncCallback&lt;void&gt;): void

Cancels all reminders set by the current application. This API uses an asynchronous callback to return the cancellation result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Asynchronous callback used to return the result.|

**Example**

```js
reminderAgent.cancelAllReminders((err, data) =>{
    console.log("cancelAllReminders callback")
})
```


## reminderAgent.cancelAllReminders

cancelAllReminders(): Promise&lt;void&gt;

Cancels all reminders set by the current application. This API uses a promise to return the cancellation result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
reminderAgent.cancelAllReminders().then(() => {
    console.log("cancelAllReminders promise")
})
```


## reminderAgent.addNotificationSlot

addNotificationSlot(slot: NotificationSlot, callback: AsyncCallback&lt;void&gt;): void

Adds a notification slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| slot | [NotificationSlot](js-apis-notification.md#notificationslot) | Yes| Notification slot, whose type can be set.|
| callback | AsyncCallback&lt;void&gt; | Yes| Asynchronous callback used to return the result.|

**Example**

```js
import notification from '@ohos.notification'

let mySlot = {
    type: notification.SlotType.SOCIAL_COMMUNICATION
}
reminderAgent.addNotificationSlot(mySlot, (err, data) => {
    console.log("addNotificationSlot callback");
});
```


## reminderAgent.addNotificationSlot

addNotificationSlot(slot: NotificationSlot): Promise&lt;void&gt;

Adds a notification slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| slot | [NotificationSlot](js-apis-notification.md#notificationslot) | Yes| Notification slot, whose type can be set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
import notification from '@ohos.notification'

let mySlot = {
    type: notification.SlotType.SOCIAL_COMMUNICATION
}
reminderAgent.addNotificationSlot(mySlot).then(() => {
   console.log("addNotificationSlot promise");
});
```


## reminderAgent.removeNotificationSlot

removeNotificationSlot(slotType: notification.SlotType, callback: AsyncCallback&lt;void&gt;): void

Removes a notification slot of a specified type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| slotType | [notification.SlotType](js-apis-notification.md#slottype) | Yes| Type of the notification slot to remove.|
| callback | AsyncCallback&lt;void&gt; | Yes| Asynchronous callback used to return the result.|

**Example**

```js
import notification from '@ohos.notification'

reminderAgent.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION, (err, data) => {
    console.log("removeNotificationSlot callback");
});
```


## reminderAgent.removeNotificationSlot

removeNotificationSlot(slotType: notification.SlotType): Promise&lt;void&gt;

Removes a notification slot of a specified type. This API uses a promise to return the result.

**System capability**: SystemCapability.Notification.ReminderAgent

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| slotType | [notification.SlotType](js-apis-notification.md#slottype) | Yes| Type of the notification slot to remove.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```js
import notification from '@ohos.notification'

reminderAgent.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION).then(() => {
    console.log("removeNotificationSlot promise");
});
```


## ActionButtonType

Enumerates button types.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Default Value| Description|
| -------- | -------- | -------- |
| ACTION_BUTTON_TYPE_CLOSE | 0 | Button for closing the reminder.|
| ACTION_BUTTON_TYPE_SNOOZE | 1 | Button for snoozing the reminder.|


## ReminderType

Enumerates reminder types.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Default Value| Description|
| -------- | -------- | -------- |
| REMINDER_TYPE_TIMER | 0 | Countdown reminder.|
| REMINDER_TYPE_CALENDAR | 1 | Calendar reminder.|
| REMINDER_TYPE_ALARM | 2 | Alarm reminder.|


## ActionButton

Defines a button displayed in the reminder notification.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| title | string | Yes| Text on the button.|
| type | [ActionButtonType](#actionbuttontype) | Yes| Button type.|


## WantAgent

Sets the package and ability that are redirected to when the reminder notification is clicked.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pkgName | string | Yes| Name of the package that is redirected to when the reminder notification is clicked.|
| abilityName | string | Yes| Name of the ability that is redirected to when the reminder notification is clicked.|


## MaxScreenWantAgent

Provides the information about the target package and ability to start automatically when the reminder is displayed in full-screen mode. This API is reserved.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pkgName | string | Yes| Name of the package that is automatically started when the reminder arrives and the device is not in use.|
| abilityName | string | Yes| Name of the ability that is automatically started when the reminder arrives and the device is not in use.|


## ReminderRequest

Defines the reminder to publish.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| reminderType | [ReminderType](#remindertype) | Yes| Type of the reminder.|
| actionButton | [ActionButton](#actionbutton) | No| Button displayed in the reminder notification. (The parameter is optional. Up to two buttons are supported.)|
| wantAgent | [WantAgent](#wantagent) | No| Information about the ability that is redirected to when the notification is clicked.|
| maxScreenWantAgent | [MaxScreenWantAgent](#maxscreenwantagent) | No| Information about the ability that is automatically started when the reminder arrives. If the device is in use, a notification will be displayed.|
| ringDuration | number | No| Ringing duration.|
| snoozeTimes | number | No| Number of reminder snooze times.|
| timeInterval | number | No| Reminder snooze interval.|
| title | string | No| Reminder title.|
| content | string | No| Reminder content.|
| expiredContent | string | No| Content to be displayed after the reminder expires.|
| snoozeContent | string | No| Content to be displayed when the reminder is snoozing.|
| notificationId | number | No| Notification ID used by the reminder. If there are reminders with the same notification ID, the later one will overwrite the earlier one.|
| slotType | [notification.SlotType](js-apis-notification.md#slottype) | No| Type of the slot used by the reminder.|


## ReminderRequestCalendar

ReminderRequestCalendar extends ReminderRequest

Defines a reminder for a calendar event.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| dateTime | [LocalDateTime](#localdatetime) | Yes| Reminder time.|
| repeatMonths | Array&lt;number&gt; | No| Month in which the reminder repeats.|
| repeatDays | Array&lt;number&gt; | No| Date on which the reminder repeats.|


## ReminderRequestAlarm

ReminderRequestAlarm extends ReminderRequest

Defines a reminder for an alarm.

**System capability**: SystemCapability.Notification.ReminderAgent

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| hour | number | Yes| Hour portion of the reminder time.|
| minute | number | Yes| Minute portion of the reminder time.|
| daysOfWeek | Array&lt;number&gt; | No| Days of a week when the reminder repeats.|


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
| month | number | Yes| Month.|
| day | number | Yes| Date.|
| hour | number | Yes| Hour.|
| minute | number | Yes| Minute.|
| second | number | No| Second.|
