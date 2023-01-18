# reminderAgentManager Error Codes

## 1700001 Notification Disabled

**Error Message**

Notification is not enabled.

**Description**

The application is not allowed to send notifications when **publishReminder()** is called.

**Possible Causes**

1. The application has not requested notification to be enabled.
2. The reminder function is disabled.

**Solution**

1. Call [Notification.requestEnableNotification](../apis/js-apis-notification.md#notificationrequestenablenotification8) to request notification to be enabled for the application.
2. Check whether the notification function is disabled.

## 1700002 Too Many Reminders

**Error Message**

The number of reminders exceeds the limit.

**Description**

The number of reminders exceeds the limit when **publishReminder()** is called.

**Possible Causes**

1. There are already 2000 reminders for the entire system.
2. There are already 30 reminders for the application.

**Solution**

Delete unnecessary reminders.

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
