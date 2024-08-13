# Notification Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 1600001 Internal Error

**Error Message**

Internal error.

**Description**

This error code is reported when an error occurs during internal processing, such as multi-thread processing or internal pointer checks.

**Cause**

Common kernel errors such as multi-thread processing and internal processing errors occur.

**Solution**

Make sure the system resources are sufficient.

## 1600002 Marshalling or Unmarshalling Error

**Error Message**

Marshalling or unmarshalling error.

**Description**

This error code is reported when a marshalling or unmarshalling error occurs before data transmission.

**Cause**

A parameter mismatch is detected between the application and the notification service.

**Solution**

Make sure the application SDK version matches the system version.

## 1600003 Failed to Connect to the Notification Service

**Error Message**

Failed to connect service.

**Description**

This error code is reported when the application fails to connect to the notification service.

**Cause**

The notification service is busy or abnormal.

**Solution**

Restart the system.

## 1600004 Notification Disabled

**Error Message**

Notification is not enabled.

**Description**

This error code is reported when notification is disabled.

**Cause**

The notification feature is not enabled for the application.

**Solution**

Enable notification for the application in the notification settings.

## 1600005 Notification Slot Disabled

**Error Message**

Notification slot is not enabled.

**Description**

This error code is reported when the notification slot is not available.

**Cause**

The notification slot is disabled or has not been added.

**Solution**

1. Access the notification settings and check whether the application has the notification slot. If no, add it.

2. Make sure the notification slot is enabled.

## 1600006 Notification Deletion Failed

**Error Message**

Notification deletion disabled.

**Description**

This error code is reported when notification deletion is disabled.

**Cause**

The notification attribute **isUnremovable** is set to true.

**Solution**

See [NotificationRequest](./js-apis-notificationManager.md#notificationrequest) to check the notification attribute **isUnremovable**.

## 1600007 Notification Not Found

**Error Message**

The notification does not exist.

**Description**

This error code is reported when the notification service could not find the notification.

**Cause**

The notification has been canceled or deleted.

**Solution**

Not supported

## 1600008 User Not Found

**Error Message**

The user does not exist.

**Description**

This error code is reported when the specified user is not found in the information system.

**Cause**

The user information passed is incorrect.

**Solution**

Verify the user information.

## 1600009 Notification Sending Limit Reached

**Error Message**

The notification sending frequency reaches the upper limit.

**Description**

This error code is reported when the notification sending frequency reaches the upper limit.

**Cause**

More than 10 notifications are sent per second, or more than 20 notifications are updated per second.

**Solution**

Reduce the notification sending frequency to no more than 10 per second.

## 1600010 Distributed Operation Failed

**Error Message**

Distributed operation failed.

**Description**

This error code is reported when an error occurs with the distributed database operation or distributed API invoking.

**Cause**

The distributed database could not be operated or the distributed API could not be invoked.

**Solution**

Verify the distributed connection.

## 1600011 Failed to Read the Template Configuration

**Error Message**

Failed to read the template configuration.

**Description**

This error code is reported when the attempt to read the template configuration file fails.

**Cause**

The template configuration file is lost in the system.

**Solution**

Check for the template configuration file: /system/etc/notification_template/external.json.

## 1600012 Insufficient Memory Space

**Error Message**

No memory space.

**Description**

This error code is reported when a memory allocation error occurs.

**Cause**

A memory allocation error occurs.

**Solution**

Ensure sufficient system memory.

## 1600013 Notification Pop-up Window Displayed

**Error Message**

A notification dialog box is already displayed.

**Description**

This error code is reported when the notification pop-up window is displayed.

**Cause**

The notification pop-up window is displayed.

**Solution**

Check whether the notification pop-up window is displayed.

## 17700001 Bundle Name Not Found

**Error Message**

The specified bundle name was not found.

**Description**

This error code is reported when the bundle name is incorrect or the application is not installed.

**Cause**

1. The bundle name is incorrect.
2. The application is not installed.

**Solution**

Verify the bundle name and make sure the application is installed.