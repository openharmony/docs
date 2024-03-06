# NotificationFlags

The **NotificationFlags** module implements a **NotificationFlags** instance.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**System capability**: SystemCapability.Notification.Notification

## Attributes

| Name            | Type                   | Mandatory| Description                              |
| ---------------- | ---------------------- | ---- | --------------------------------- |
| soundEnabled     | [NotificationFlagStatus](#notificationflagstatus) | No  | Whether to enable the sound alert for the notification.                 |
| vibrationEnabled | [NotificationFlagStatus](#notificationflagstatus) | No  | Whether to enable vibration for the notification.              |
| reminderFlags<sup>11+</sup> | number| No  | Whether to enable the input information prompt features.<br>**System API**: This is a system API.<br>- Bit 0: sound alert. The value **0** means to enable the feature, and **1** means the opposite.<br>- Bit 1: locking the screen. The value **0** means to enable the feature, and **1** means the opposite.<br>- Bit 2: banner. The value **0** means to enable the feature, and **1** means the opposite.<br>- BIt 3: turning on the screen. The value **0** means to enable the feature, and **1** means the opposite.<br>- Bit 4: vibration. The value **0** means to enable the feature, and **1** means the opposite.|


## NotificationFlagStatus

Describes the notification flag status.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name          | Value | Description                              |
| -------------- | --- | --------------------------------- |
| TYPE_NONE      | 0   | The default flag is used.                        |
| TYPE_OPEN      | 1   | The notification flag is enabled.                    |
| TYPE_CLOSE     | 2   | The notification flag is disabled.                    |
