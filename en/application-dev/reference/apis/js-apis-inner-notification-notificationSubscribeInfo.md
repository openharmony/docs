# NotificationSubscribeInfo

The **NotificationSubscribeInfo** module provides APIs for defining the information about the publisher for notification subscription.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## NotificationSubscribeInfo

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name                | Type                 |  Mandatory| Description                                      |
| -------------------- | --------------------- | --- | ------------------------------------------ |
| bundleNames          | Array<string>         | No | Bundle names of the applications whose notifications are to be subscribed to.                             |
| userId               | number                | No | User ID.                                     |
