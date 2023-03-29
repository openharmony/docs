# DistributedNotificationService Error Codes

## 1600001 Internal Error

**Error Message**

Internal Error.

**Description**

This error code is reported when an internal processing error occurs, such as a memory allocation or multi-thread processing error.

**Possible Causes**

1. Common kernel errors such as memory allocation and multi-thread processing errors occur.

**Solution**

1. Ensure sufficient system memory.
2. Restart the system.

## 1600002 Data Processing or Interaction Error Between the Application and Notification Subsystem

**Error Message**

IPC Error.

**Description**

This error code is reported when a serialization or deserialization error occurs and the interaction with the notification subsystem fails.

**Possible Causes**

1. A serialization and deserialization error occurs.
2. The interaction with the notification subsystem fails.

**Solution**

1. Make sure the input parameter value is within the valid range.
2. Make sure the notification subsystem is not being started.

## 1600003 Failed to Connect to the Service

**Error Message**

Failed to connect to service.

**Description**

This error code is reported when the notification subsystem is abnormal due to a service connection failure.

**Possible Causes**

The service is busy or the notification subsystem is not working correctly.

**Solution**

1. Try again later.
2. Make sure the notification subsystem is started.

## 1600004 Notification Is Disabled

**Error Message**

Notification is not enabled.

**Description**

This error code is reported when the notification function is disabled.

**Possible Causes**

The notification function is set to its default state (default) or manually disabled.

**Solution**

Enable the notification function.

## 1600005 Notification Slot Is Disabled

**Error Message**

Notification slot is not enabled.

**Description**

This error code is reported when the notification slot is disabled.

**Possible Causes**

The notification slot is disabled.

**Solution**

Make sure the application notification slot is enabled.

## 1600006 Unable to Remove the Notification

**Error Message**

Notification is not allowed to remove.

**Description**

This error code is reported when **isUnremoveable** is set to **true** and an attempt is made to remove all notifications or when **isRemoveAllowed** is set to **false** and an attempt is made to remove a specific notification.

**Possible Causes**

1. When **isUnremoveable** is set to **true**, notifications can only be removed on a one-by-one basis.
2. When **isRemoveAllowed** is set to **false**, no notification can be deleted.

**Solution**

1. Check whether **unremovable** is set to **true**.
2. Check whether **isRemoveAllowed** is set to **false**.

## 1600007 Notification Not Found

**Error Message**

The notification is not exist.

**Description**

This error code is reported when the target notification is not found.

**Possible Causes**

1. The notification has been deleted.
2. The notification has been canceled.

**Solution**

Make sure the notification exists.

## 1600008 User Not Found

**Error Message**

The user is not exist.

**Description**

This error code is reported when the target user is not found.

**Possible Causes**

1. The user ID is incorrect.
2. No user account has not been activated.

**Solution**

Make sure the user account with the specified ID has been activated.

## 1600009 Maximum Number of Notifications per Second Reached

**Error Message**

Over max number notifications per second.

**Description**

This error code is reported when the number of notifications sent per second has reached the maximum.

**Possible Causes**

More than 10 notifications are sent per second.

**Solution**

Reduce the number of notifications sent per second to 10 or less.

## 1600010 Distributed Processing Error

**Error Message**

Distributed operation failed.

**Description**

This error code is reported when a database processing error occurs or the database operations are too frequent.

**Possible Causes**

1. A database processing error occurs.
2. The database operations are too frequent.

**Solution**

1. Make sure the distributed data is running properly.
2. Reduce the database operation frequency.

## 1600011 Failed to read the Template Configuration File

**Error Message**

Read template config failed.

**Description**

This error code is reported when the template configuration file fails to be read.

**Possible Causes**

1. The template configuration file is lost.
2. The current template version is not supported.

**Solution**

1. Check for the **/system/etc/notification_template/external.json** file.
2. Update the version to 3.2 or later.

## 17700001 Bundle Name Not Found

**Error Message**

The specified bundle name was not found.

**Description**

This error code is reported when the specified bund name is not found.

**Possible Causes**

1. The bundle name is incorrect.
2. The application is not installed.

**Solution**

1. Verify the bundle name.
2. Make sure the application has been installed.
