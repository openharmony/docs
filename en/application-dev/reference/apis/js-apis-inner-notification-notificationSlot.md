# NotificationSlot

The **NotificationSlot** module provides APIs for defining the notification slot.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## NotificationSlot

**System capability**: SystemCapability.Notification.Notification

| Name                | Type                 | Mandatory| Description                  |
| -------------------- | --------------------- | --- |----------------------|
| type<sup>(deprecated)</sup> | [SlotType](js-apis-notificationManager.md#slottype) | No | Notification slot type.<br>This API is deprecated since API version 9. You are advised to use **notificationType** instead.               |
| notificationType<sup>11+</sup>                 | [SlotType](js-apis-notificationManager.md#slottype) | No | Notification slot type.               |
| level                | number                | No | Notification level. If this parameter is not set, the default value that corresponds to the notification slot type is used.|
| desc                 | string                | No | Notification slot description.           |
| badgeFlag            | boolean               | No | Whether to display the badge.             |
| bypassDnd            | boolean               | No | Whether to bypass DND mode in the system.      |
| lockscreenVisibility | number                | No | Mode for displaying the notification on the lock screen.      |
| vibrationEnabled     | boolean               | No | Whether to enable vibration for the notification.              |
| sound                | string                | No | Notification alert tone.              |
| lightEnabled         | boolean               | No | Whether the indicator blinks for the notification.               |
| lightColor           | number                | No | Indicator color of the notification.              |
| vibrationValues      | Array\<number\>       | No | Vibration mode of the notification.             |
| enabled<sup>9+</sup> | boolean               | No | Whether the notification slot is enabled.        |
