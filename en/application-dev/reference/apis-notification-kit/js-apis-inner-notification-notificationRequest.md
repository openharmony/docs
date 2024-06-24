# NotificationRequest

The **NotificationRequest** module provides APIs for defining the notification request.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## NotificationRequest

**System capability**: SystemCapability.Notification.Notification

| Name                           | Type                                                   |  Read-only| Mandatory| Description                                                                   |
|-------------------------------| -------------------------------------------------------- | ----- | --- |-----------------------------------------------------------------------|
| content                       | [NotificationContent](js-apis-inner-notification-notificationContent.md#notificationcontent)   |   No | Yes | Notification content.                                                                |
| id                            | number                                                   |   No | No | Notification ID.                                                                |
| slotType<sup>(deprecated)</sup> | [SlotType](js-apis-notificationManager.md#slottype)    |   No | No | Notification slot type.<br>This API is deprecated since API version 11. You are advised to use **notificationSlotType** instead.                       |
| notificationSlotType<sup>11+</sup> | [SlotType](js-apis-notificationManager.md#slottype) |   No | No | Notification slot type.                       |
| isOngoing                     | boolean                                                  |   No | No | Whether the notification is an ongoing notification.                                                             |
| isUnremovable                 | boolean                                                  |   No | No | Not supported currently. |
| deliveryTime                  | number                                                   |   No | No | Time when the notification is sent.                                                              |
| tapDismissed                  | boolean                                                  |   No | No | Whether the notification is automatically cleared.                                                            |
| autoDeletedTime               | number                                                   |   No | No | Time when the notification is automatically cleared.                                                             |
| wantAgent                     | [WantAgent](../apis-ability-kit/js-apis-wantAgent.md)            |   No | No | **WantAgent** instance to which the notification will be redirected after being clicked.                                      |
| extraInfo                     | {[key: string]: any}                                     |   No | No | Extended parameters.                                                                |
| color                         | number                                                   |   No | No | Background color of the notification. Not supported currently.                                                    |
| colorEnabled                  | boolean                                                  |   No | No | Whether the notification background color can be enabled. Not supported currently.                                                |
| isAlertOnce                   | boolean                                                  |   No | No | Whether the notification triggers an alert only once.                                                       |
| isStopwatch                   | boolean                                                  |   No | No | Whether to display the stopwatch.                                                            |
| isCountDown                   | boolean                                                  |   No | No | Whether to display the countdown time.                                                           |
| isFloatingIcon                | boolean                                                  |   No | No | Whether the notification is displayed as a floating icon in the status bar.                                                           |
| label                         | string                                                   |   No | No | Notification label.                                                                |
| badgeIconStyle                | number                                                   |   No | No | Notification badge type. Not supported currently.                                                    |
| showDeliveryTime              | boolean                                                  |   No | No | Whether to display the time when the notification is delivered.                                                            |
| actionButtons                 | Array\<[NotificationActionButton](js-apis-inner-notification-notificationActionButton.md)\>             |   No | No | Buttons in the notification. Up to three buttons are allowed.                                                         |
| smallIcon                     | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)             |   No | No | Small notification icon. This field is optional. The total number of bytes of image pixels cannot exceed 100 KB. The display effect depends on the device capability and notification center UI style.                                                |
| largeIcon                     | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)             |   No | No | Large notification icon. This field is optional. The total number of bytes of image pixels cannot exceed 100 KB. The display effect depends on the device capability and notification center UI style.                                                |
| creatorBundleName             | string                                                   |   Yes | No | Name of the bundle that creates the notification.                                                             |
| creatorUid                    | number                                                   |   Yes | No | UID used for creating the notification.                                                            |
| creatorPid                    | number                                                   |   Yes | No | PID used for creating the notification.                                                            |
| creatorUserId<sup>8+<sup>     | number                                                   |   Yes | No | ID of the user who creates the notification.                                                         |
| hashCode                      | string                                                   |   Yes | No | Unique ID of the notification.                                                              |
| groupName<sup>8+<sup>         | string                                                   |   No | No | Notification group name.                                                               |
| template<sup>8+<sup>          | [NotificationTemplate](./js-apis-inner-notification-notificationTemplate.md) |   No | No | Notification template.                                                                |
| distributedOption<sup>8+<sup> | [DistributedOptions](#distributedoptions)                |   No | No | Distributed notification options.                                                            |
| notificationFlags<sup>8+<sup> | [NotificationFlags](js-apis-inner-notification-notificationFlags.md#notificationflags)                   |   Yes | No | Notification flags.                                                 |
| removalWantAgent<sup>9+<sup>  | [WantAgent](../apis-ability-kit/js-apis-wantAgent.md)            |   No | No | **WantAgent** instance to which the notification will be redirected when it is removed. The target **WantAgent** instance must be a common event or a system service (for which the value of **OperationType** is 3 or larger).                                         |
| badgeNumber<sup>9+<sup>       | number                                                   |   No | No | Number of notifications displayed on the application icon.                                                       |


## DistributedOptions

Describes distributed notification options.

**System capability**: SystemCapability.Notification.Notification

| Name                  | Type           | Mandatory| Description                              |
| ---------------------- | -------------- | ---- | ---------------------------------- |
| isDistributed<sup>8+<sup>          | boolean        | No  | Whether the notification is a distributed notification.                  |
| supportDisplayDevices<sup>8+<sup>  | Array\<string> | No  | List of the devices to which the notification can be synchronized.           |
| supportOperateDevices<sup>8+<sup>  | Array\<string> | No  | List of the devices on which the notification can be opened.             |
