# reminderAgentManager Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 1700001 Notification Disabled

**Error Message**

Notification is not enabled.

**Description**

The application is not allowed to send notifications when **publishReminder()** is called.

**Possible Causes**

1. The application has not requested notification to be enabled.
2. The reminder function is disabled.

**Solution**

1. Call [Notification.requestEnableNotification](../apis-notification-kit/js-apis-notification.md#notificationrequestenablenotification8) to request notification to be enabled for the application.
2. Check whether the notification function is disabled.

## 1700002 Too Many Reminders

**Error Message**

The number of reminders exceeds the limit.

**Description**

The number of reminders exceeds the limit when **publishReminder()** is called.

**Possible Causes**

1. The number of reminders generated for the entire system exceeds 2000 in API version 9 or 12000 in API version 10 or later.
2. The number of reminders generated for the application exceeds 30 in API version 9 or 30 (for a common application) or 10000 (for a system application) in API version 10 or later.
<!--RP1-->
**Solution**

Delete unnecessary reminders.
<!--RP1End-->
## 1700003 Nonexistent Reminder

**Error Message**

The reminder does not exist.

**Description**

The reminder passed in **cancelReminder()** does not exist.

**Possible Causes**

1. The reminder has expired.
2. The reminder has been deleted.

**Solution**

1. Check whether the reminder is valid.
2. Check whether the reminder has been deleted.

## 1700004 Nonexistent Bundle Name

**Error Message**

The bundle name does not exist.

**Description**

The bundle name passed is not found.

**Possible Causes**

1. The bundle name is incorrect.
2. The application is not installed.

**Solution**

Check whether the bundle name exists.
