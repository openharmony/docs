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

Failed to connect to the service.

**Description**

This error code is reported when the application fails to connect to the notification service.

**Cause**

The notification service is busy or abnormal.

**Solution**

Restart the system.

## 1600004 Notification Disabled

**Error Message**

Notification disabled.

**Description**

This error code is reported when notification is disabled.

**Cause**

The notification feature is not enabled for the application.

**Solution**

Enable notification for the application in the notification settings.

## 1600005 Notification Slot Disabled

**Error Message**

Notification slot disabled.

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

Enable notification deletion. For details, see [NotificationRequest](./js-apis-inner-notification-notificationRequest.md).

## 1600007 Notification Not Found

**Error Message**

The notification does not exist.

**Description**

This error code is reported when the notification service could not find the notification.

**Cause**

The notification has been canceled or deleted.

**Solution**

N/A

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

## 1600011 Failed to Read Template Configuration

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


## 1600014 No Related Permission

**Error Message**

No permission.

**Description**

This error code is reported when you do not have the related permission.

**Cause**

You do not have the related permission.

**Solution**

Check whether you have the related permission.

## 1600015 Duplicate Configurations not Allowed for the Current Notification Status

**Error Message**

The current notification status does not support duplicate configurations.

**Description**

This error code is reported when the current notification status does not support duplicate configurations.

**Cause**

The current notification status does not support duplicate configurations.

**Solution**

Check whether the notification status is duplicately configured.

## 1600016 Updated Notification Version Outdated

**Error Message**

The notification version for this update is too low.

**Description**

This error code is reported when the notification version for this update is outdated.

**Cause**

The notification version for this update is outdated.

**Solution**

Check the notification version.

## 1600017 No Configured Proxy Relationship

**Error Message**

There is no corresponding agent relationship configuration.

**Description**

This error code is reported when no proxy relationship is configured.

**Cause**

No corresponding proxy relationship is configured.

**Solution**

Check the proxy relationship configuration.

## 1600018 Notification Settings Page Already Displayed

**Error Message**

The notification settings window is already displayed.

**Description**

This error code is reported when the notification settings page has been displayed.

**Cause**

The notification settings page has been displayed.

**Solution**

Check whether the notification settings page is displayed.

## 1600019 No Configuration Information for a Do Not Disturb Profile

**Error Message**

The do-not-disturb profile does not exist.

**Description**

This error code is reported when the configuration information corresponding to the Do Not Disturb profile ID does not exist.

**Cause**

No configuration information corresponding to the Do Not Disturb profile ID exists.

**Solution**

Check whether the queried Do Not Disturb profile ID is correct.

## 2300007 Network Access Failure

**Error Message**

Network unreachable.

**Description**

This error code is reported when the network cannot be accessed.

**Cause**

The network cannot be accessed.

**Solution**

Check the network status.

## 17700001 Bundle Name Not Found

**Error Message**

The specified bundle name was not found.

**Description**

This error code is reported when the bundle name is incorrect or the application is not installed.

**Cause**

1. The bundle name is incorrect.
2. The application is not installed.

**Solution**

1. Verify the bundle name and make sure the application is installed.
