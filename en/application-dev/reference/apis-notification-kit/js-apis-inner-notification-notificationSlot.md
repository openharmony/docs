# NotificationSlot

The **NotificationSlot** module provides APIs for defining the notification slot.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## NotificationSlot

**System capability**: SystemCapability.Notification.Notification

| Name                | Type                | Read Only | Optional | Description                  |
| -------------------- | ---------------------|---- | --- |----------------------|
| type<sup>(deprecated)</sup> | [notification.SlotType](js-apis-notificationManager.md#slottype) | No | Yes | Notification slot type.<br>This API is deprecated since API version 11. You are advised to use **notificationType** instead.               |
| notificationType<sup>11+</sup>                 | [notificationManager.SlotType](js-apis-notificationManager.md#slottype) | No | Yes | Notification slot type.               |
| level                | [notification.SlotLevel](../apis-notification-kit/js-apis-notificationManager.md#slotlevel)                | No | Yes | Notification level. |
| desc                 | string                | No | Yes | Notification slot description.           |
| badgeFlag            | boolean               | No | Yes | Whether to display the badge.             |
| bypassDnd            | boolean               | No | Yes | Whether to bypass DND mode in the system.      |
| lockscreenVisibility | number                | No | Yes | Mode for displaying the notification on the lock screen.      |
| vibrationEnabled     | boolean               | No | Yes | Whether to enable vibration for the notification.              |
| sound                | string                | No | Yes | Notification alert tone.              |
| lightEnabled         | boolean               | No | Yes | Whether the indicator blinks for the notification.               |
| lightColor           | number                | No | Yes | Indicator color of the notification.              |
| vibrationValues      | Array\<number\>       | No | Yes | Vibration mode of the notification.             |
| enabled<sup>9+</sup> | boolean               | Yes | Yes | Whether the notification slot is enabled.        |
