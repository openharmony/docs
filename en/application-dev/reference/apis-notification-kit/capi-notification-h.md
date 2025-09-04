# notification.h

## Overview

Defines APIs for notification services.

**File to include**: <NotificationKit/notification.h>

**Library**: libohnotification.so

**System capability**: SystemCapability.Notification.Notification

**Since**: 13

**Related module**: [NOTIFICATION](capi-notification.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [bool OH_Notification_IsNotificationEnabled(void)](#oh_notification_isnotificationenabled) | Checks whether the notification of the specified application is enabled.|

## Function Description

### OH_Notification_IsNotificationEnabled()

```
bool OH_Notification_IsNotificationEnabled(void)
```

**Description**

Checks whether the notification of the specified application is enabled.

**Since**: 13

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** - Notification is enabled for the specified application.<br>**false** - Notification is not enabled for the specified application. |
