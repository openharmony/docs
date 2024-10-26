# NotificationFlags

The **NotificationFlags** module implements a **NotificationFlags** instance.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**System capability**: SystemCapability.Notification.Notification

## Attributes

| Name            | Type                   | Read Only | Optional | Description                                        |
| ---------------- | ---------------------- | ---- | -----|-------------------------------------------- |
| soundEnabled     | [NotificationFlagStatus](#notificationflagstatus) | Yes | Yes | Settings of the sound alert for the notification.   |
| vibrationEnabled | [NotificationFlagStatus](#notificationflagstatus) | Yes | Yes | Settings of the vibration for the notification. |


## NotificationFlagStatus

Enumerates the notification flag statuses.

**System capability**: SystemCapability.Notification.Notification

| Name          | Value | Description                              |
| -------------- | --- | --------------------------------- |
| TYPE_NONE      | 0   | The default flag is used. The effect is the same as that of **TYPE_OPEN**.         |
| TYPE_OPEN      | 1   | The notification flag is enabled.                    |
| TYPE_CLOSE     | 2   | The notification flag is disabled.                    |
