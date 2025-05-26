# Notification


## Overview

The **Notification** module provides the notification capabilities for applications.

**System capability**: SystemCapability.Notification.Notification

**Since**: 13


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [notification.h](notification_8h.md) | Defines the APIs for notification service.<br>**File to include**: <NotificationKit/notification.h><br>**Library**: libohnotification.so|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Notification_IsNotificationEnabled](#oh_notification_isnotificationenabled)| Queries the notification enabling state of the application.|

## Function Description

### OH_Notification_IsNotificationEnabled

```cpp
bool OH_Notification_IsNotificationEnabled(void)
```

**Description**

Queries the notification enabling state of the application.

**Since**: 13

**Returns**

Returns **true** if the notification is enabled; returns **false** otherwise.
