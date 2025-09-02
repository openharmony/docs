# NotificationSubscribeInfo (System API)
<!--Kit: Notification Kit-->
<!--Subsystem: Notification-->
<!--Owner: @michael_woo888-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @huipeizi-->

The **NotificationSubscribeInfo** module provides APIs for defining the information about the publisher for notification subscription.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## NotificationSubscribeInfo

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

| Name                | Type                 | Read-Only| Optional| Description                                      |
| -------------------- | --------------------- | ---- | --- | ------------------------------------------ |
| bundleNames          | Array<string\>         | No| Yes| Bundle names of the applications whose notifications are to be subscribed to.                             |
| userId               | number                | No| Yes | User ID.                                     |
| deviceType<sup>12+</sup>           | string                | No| Yes| Device type. The value is obtained based on [device information](../apis-basic-services-kit/js-apis-device-info.md).                                   |
| slotTypes<sup>18+</sup>   | Array<[notificationManager.SlotType](js-apis-notificationManager.md#slottype)\>| No| Yes| Types of the notification slot.|
| filterLimit<sup>18+</sup>   | number| No| Yes| Notification filtering range. The options are as follows:<br>- **0**: All notifications are subscribed.<br>- **1**: Filter out notifications whose slot type is [SOCIAL_COMMUNICATION](js-apis-notificationManager.md#slottype) and [userInput](js-apis-inner-notification-notificationActionButton.md#notificationactionbutton) is empty.<br>- **2**: Filter out notifications whose slot type is [SOCIAL_COMMUNICATION](js-apis-notificationManager.md#slottype) and [userInput](js-apis-inner-notification-notificationActionButton.md#notificationactionbutton) is not empty.|
