# NotificationSlot

The **NotificationSlot** module describes the notification slot.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**System capability**: SystemCapability.Notification.Notification

| Name                | Type                 | Readable| Writable| Description                                      |
| -------------------- | --------------------- | ---- | --- | ------------------------------------------ |
| type                 | [SlotType](js-apis-notificationManager.md#slottype) | Yes | Yes | Notification slot type.                                  |
| level                | number                | Yes | Yes | Notification level. If this parameter is not set, the default value that corresponds to the notification slot type is used.|
| desc                 | string                | Yes | Yes | Notification slot description.                          |
| badgeFlag            | boolean               | Yes | Yes | Whether to display the badge.                              |
| bypassDnd            | boolean               | Yes | Yes | Whether to bypass DND mode in the system.              |
| lockscreenVisibility | number                | Yes | Yes | Mode for displaying the notification on the lock screen.                |
| vibrationEnabled     | boolean               | Yes | Yes | Whether to enable vibration for the notification.                                |
| sound                | string                | Yes | Yes | Notification alert tone.                                |
| lightEnabled         | boolean               | Yes | Yes | Whether the indicator blinks for the notification.                                  |
| lightColor           | number                | Yes | Yes | Indicator color of the notification.                                |
| vibrationValues      | Array\<number\>       | Yes | Yes | Vibration mode of the notification.                              |
| enabled<sup>9+</sup> | boolean               | Yes | No | Whether the notification slot is enabled.                     |
