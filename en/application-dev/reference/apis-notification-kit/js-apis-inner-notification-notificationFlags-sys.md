# NotificationFlags (System API)

The **NotificationFlags** module implements a **NotificationFlags** instance.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [NotificationFlags](./js-apis-inner-notification-notificationFlags.md).

**System capability**: SystemCapability.Notification.Notification

## Attributes

| Name            | Type                   | Read Only | Optional | Description                              |
| ---------------- | ---------------------- | ---- | ---- | --------------------------- |
| reminderFlags<sup>11+</sup> | number| Yes | Yes | Settings of the input information reminder features.<br>**System API**: This is a system API.<br>- Bit 0: sound alert. The value **0** means to enable the feature, and **1** means the opposite.<br>- Bit 1: locking the screen. The value **0** means to enable the feature, and **1** means the opposite.<br>- Bit 2: banner. The value **0** means to enable the feature, and **1** means the opposite.<br>- BIt 3: turning on the screen. The value **0** means to enable the feature, and **1** means the opposite.<br>- Bit 4: vibration. The value **0** means to enable the feature, and **1** means the opposite.<br>- Bit 5: notification icon in the status bar. The value **0** means to enable the feature, and **1** means the opposite.|
