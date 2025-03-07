# NotificationSlot (System API)

The **NotificationSlot** module provides APIs for defining the notification slot.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [NotificationSlot](./js-apis-inner-notification-notificationSlot.md).

## NotificationSlot

**System capability**: SystemCapability.Notification.Notification

| Name                | Type                | Read Only | Optional | Description                  |
| -------------------- | ------------------- | ---- |-----|------------------------|
| reminderMode<sup>11+</sup> | number               | Yes | Yes | Reminder mode of the notification.<br>**System API**: This is a system API.<br>- Bit 0: sound alert. The value **0** means to enable the feature, and **1** means the opposite.<br>- Bit 1: locking the screen. The value **0** means to enable the feature, and **1** means the opposite.<br>- Bit 2: banner. The value **0** means to enable the feature, and **1** means the opposite.<br>- BIt 3: turning on the screen. The value **0** means to enable the feature, and **1** means the opposite.<br>- Bit 4: vibration. The value **0** means to enable the feature, and **1** means the opposite.<br>- Bit 5: notification icon in the status bar. The value **0** means to enable the feature, and **1** means the opposite.   |
| authorizedStatus<sup>12+</sup> | number               | Yes | Yes | Authorization status.<br>**System API**: This is a system API.<br>- **0**: means the feature is authorized.<br>- **1**: means the feature is to be authorized.   |
