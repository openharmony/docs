# NotificationSubscribeInfo (System API)

The **NotificationSubscribeInfo** module provides APIs for defining the information about the publisher for notification subscription.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## NotificationSubscribeInfo

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API and cannot be called by third-party applications.

| Name                | Type                 |  Mandatory| Description                                      |
| -------------------- | --------------------- | --- | ------------------------------------------ |
| bundleNames          | Array<string\>         | No | Bundle names of the applications whose notifications are to be subscribed to.                             |
| userId               | number                | No | User ID.                                     |
| deviceType<sup>12+</sup>           | string                | No | Device type. The value is obtained based on [device information](../apis-basic-services-kit/js-apis-device-info.md).                                   |
| slotTypes<sup>16+</sup>   | Array<[notificationManager.SlotType](js-apis-notificationManager.md#slottype)\>| No | Types of the notification slot.|
