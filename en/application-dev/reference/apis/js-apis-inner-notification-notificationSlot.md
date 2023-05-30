# NotificationSlot

The **NotificationSlot** module describes the notification slot.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**System capability**: SystemCapability.Notification.Notification

| Name                | Type                 | Read-only| Mandatory| Description                                      |
| -------------------- | --------------------- | ---- | --- | ------------------------------------------ |
| type                 | [SlotType](js-apis-notificationManager.md#slottype) | No | Yes | Notification slot type.                                  |
| level                | number                | No | No | Notification level. If this parameter is not set, the default value that corresponds to the notification slot type is used.|
| desc                 | string                | No | No | Notification slot description.                          |
| badgeFlag            | boolean               | No | No | Whether to display the badge.                              |
| bypassDnd            | boolean               | No | No | Whether to bypass DND mode in the system.              |
| lockscreenVisibility | number                | No | No | Mode for displaying the notification on the lock screen.                |
| vibrationEnabled     | boolean               | No | No | Whether to enable vibration for the notification.                                |
| sound                | string                | No | No | Notification alert tone.                                |
| lightEnabled         | boolean               | No | No | Whether the indicator blinks for the notification.                                  |
| lightColor           | number                | No | No | Indicator color of the notification.                                |
| vibrationValues      | Array\<number\>       | No | No | Vibration mode of the notification.                              |
| enabled<sup>9+</sup> | boolean               | Yes | No | Whether the notification slot is enabled.                     |
