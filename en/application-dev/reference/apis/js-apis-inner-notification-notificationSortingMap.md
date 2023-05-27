# NotificationSortingMap

Provides sorting information of active notifications in all subscribed notifications.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name                | Type                 | Read-only| Mandatory| Description                                      |
| -------------------- | --------------------- | ---- | --- | ------------------------------------------ |
| sortings              | { [key: string]: [NotificationSorting](js-apis-inner-notification-notificationSorting.md) } | Yes | Yes | Array of notification sorting information.|
| sortedHashCode                | Array\<string>              | Yes | Yes | Hash codes for notification sorting.|

