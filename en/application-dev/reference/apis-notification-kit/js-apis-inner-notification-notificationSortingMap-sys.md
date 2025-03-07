# NotificationSortingMap (System API)

The **NotificationSortingMap** module provides APIs for defining the sorting information of active notifications in all subscribed notifications.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Attributes

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name       | Type    | Read Only| Mandatory| Description                                      |
| ----------- | ------- | --- | ----- |------------------------------------------ |
| sortings    | Record<string, [NotificationSorting](js-apis-inner-notification-notificationSorting-sys.md)\> | Yes| Yes | Array of notification sorting information.                                  |
| sortedHashCode | Array<string\> | Yes| Yes | Hash codes for notification sorting.|
