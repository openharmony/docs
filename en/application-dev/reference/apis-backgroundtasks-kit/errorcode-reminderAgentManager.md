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
<!--RP1-->
1. In API version 10 or later, the number of reminders generated for the application exceeds 30 (for a common application) or 10,000 (for a system application). In API version 9 or earlier, the number of reminders generated for the application exceeds 30.
2. In API version 10 or later, the total number of reminders generated for all applications exceeds 12,000. In API version 9 or earlier, the total number of reminders generated for all applications exceeds 2,000.

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

## 1700007 Invalid Parameter

**Error Message**

If the input parameter is not valid parameter.

**Description**

The input parameter is invalid.

**Possible Causes**

The parameter does not comply with the rules.

**Solution**

Make sure all the mandatory parameters are passed in and the parameter types are valid. If parameter verification fails, read the parameter specifications and locate the fault based on the possible causes.
