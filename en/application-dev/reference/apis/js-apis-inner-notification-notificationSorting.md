# NotificationSorting

Provides sorting information of active notifications.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name                | Type                 | Read-only| Mandatory| Description                                      |
| -------------------- | --------------------- | ---- | --- | ------------------------------------------ |
| slot                 | [NotificationSlot](js-apis-inner-notification-notificationSlot.md) | Yes | Yes | Notification slot type.                                  |
| level                | number                | Yes | Yes | Notification level. If this parameter is not set, the default value is used based on the notification slot type.|
| desc                 | string                | Yes | Yes | Description of the notification slot.                          |
