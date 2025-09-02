# NotificationSortingMap (System API)

The **NotificationSortingMap** module provides APIs for defining the sorting information of active notifications in all subscribed notifications.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Properties

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

| Name       | Type    | Read Only| Optional| Description                                      |
| ----------- | ------- | --- | ----- |------------------------------------------ |
| sortings    | Record<string, [NotificationSorting](js-apis-inner-notification-notificationSorting-sys.md)\> | Yes| No | Array of notification sorting information.                                  |
| sortedHashCode | Array<string\> | Yes| No | Hash codes for notification sorting.|
