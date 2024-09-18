# NotificationRequest

The **NotificationRequest** module provides APIs for defining the notification request.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## NotificationRequest

**System capability**: SystemCapability.Notification.Notification

| Name                           | Type                                                   |  Read Only | Optional | Description                                                                   |
|-------------------------------| -------------------------------------------------------- | ----- | --- |-----------------------------------------------------------------------|
| content                       | [NotificationContent](js-apis-inner-notification-notificationContent.md#notificationcontent)   |   No | No | Notification content.                                                                |
| id                            | number                                                   |   No | Yes | Notification ID. The default value is **0**.                                                                |
| slotType<sup>(deprecated)</sup> | [notification.SlotType](./js-apis-notification.md#slottype)    |   No | Yes | Notification slot type.<br>This API is deprecated since API version 11. You are advised to use **notificationSlotType** instead.                       |
| notificationSlotType<sup>11+</sup> | [notificationManager.SlotType](js-apis-notificationManager.md#slottype) |   No | No | Notification slot type.                       |
| isOngoing                     | boolean                                                  |   No | Yes | Not supported currently. |
| isUnremovable                 | boolean                                                  |   No | Yes | Not supported currently. |
| deliveryTime                  | number                                                   |   No | Yes | Time when the notification is sent.                                                              |
| tapDismissed                  | boolean                                                  |   No | Yes | Whether the notification is automatically cleared.                                                            |
| autoDeletedTime               | number                                                   |   No | Yes | Time when the notification is automatically cleared.                                                             |
| wantAgent                     | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md)            |   No | Yes | **WantAgent** instance to which the notification will be redirected after being clicked.                                      |
| extraInfo                     | {[key: string]: any}                                     |   No | Yes | Extended parameters.                                                                |
| color                         | number                                                   |   No | Yes | Background color of the notification. Not supported currently.                                                    |
| colorEnabled                  | boolean                                                  |   No | Yes | Whether the notification background color can be enabled. Not supported currently.                                                |
| isAlertOnce                   | boolean                                                  |   No | Yes | Whether the notification triggers an alert only once.                                                       |
| isStopwatch                   | boolean                                                  |   No | Yes | Whether to display the stopwatch.                                                            |
| isCountDown                   | boolean                                                  |   No | Yes | Whether to display the countdown time.                                                           |
| isFloatingIcon                | boolean                                                  |   No | Yes | Whether the notification is displayed as a floating icon in the status bar.                                                           |
| label                         | string                                                   |   No | Yes | Notification label.                                                                |
| badgeIconStyle                | number                                                   |   No | Yes | Notification badge type. Not supported currently.                                                    |
| showDeliveryTime              | boolean                                                  |   No | Yes | Whether to display the time when the notification is delivered.                                                            |
| actionButtons                 | Array\<[NotificationActionButton](js-apis-inner-notification-notificationActionButton.md)\>             |   No | Yes | Buttons in the notification. Up to three buttons are allowed.                                                         |
| smallIcon                     | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)             |   No | Yes | Small notification icon. This field is optional. The total number of bytes of image pixels cannot exceed 100 KB. The display effect depends on the device capability and notification center UI style.                                                |
| largeIcon                     | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)             |   No | Yes | Large notification icon. This field is optional. The total number of bytes of image pixels cannot exceed 100 KB. The display effect depends on the device capability and notification center UI style.                                                |
| creatorBundleName             | string                                                   |   Yes | Yes | Name of the bundle that creates the notification.                                                             |
| creatorUid                    | number                                                   |   Yes | Yes | UID used for creating the notification.                                                            |
| creatorPid                    | number                                                   |   Yes | Yes | PID used for creating the notification.                                                            |
| creatorUserId<sup>8+</sup>     | number                                                   |   Yes | Yes | ID of the user who creates the notification.                                                         |
| hashCode                      | string                                                   |   Yes | Yes | Unique ID of the notification.                                                              |
| groupName<sup>8+</sup>         | string                                                   |   No | Yes | Notification group name.                                                               |
| template<sup>8+</sup>          | [NotificationTemplate](./js-apis-inner-notification-notificationTemplate.md) |   No | Yes | Notification template.                                                                |
| distributedOption<sup>8+</sup> | [DistributedOptions](#distributedoptions)                |   No | Yes | Distributed notification options.                                                            |
| notificationFlags<sup>8+</sup> | [NotificationFlags](js-apis-inner-notification-notificationFlags.md#notificationflags)                   |   Yes | Yes | Notification flags.                                                 |
| removalWantAgent<sup>9+</sup>  | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md)            |   No | Yes | **WantAgent** instance to which the notification will be redirected when it is removed. The target **WantAgent** instance must be a common event or a system service (for which the value of **OperationType** is 3 or larger).                                         |
| badgeNumber<sup>9+</sup>       | number                                                   |   No | Yes | Number of notifications displayed on the application icon.                                                       |
| appMessageId<sup>12+</sup>       | string                                                   |   No | Yes | Unique ID carried in a notification sent by an app, which is used for notification deduplication. If an app publishes notifications with the same **appMessageId** locally or on the cloud, the device displays only one message. Repeated notifications received later will be silenced and deduplicated, and will not be displayed or notified. The deduplication flag is valid only within 24 hours after the notification is published. After 24 hours or the device is restarted, the deduplication flag becomes invalid. |
| sound<sup>12+</sup>            | string                                                   |   No | Yes | Customized ring tone for app notifications: <!--RP1-->This field takes effect only after a system app with the [ohos.permission.NOTIFICATION_AGENT_CONTROLLER](../../security/AccessToken/permissions-for-system-apps.md#ohospermissionnotification_agent_controller) permission calls the [notificationManager.setAdditionalConfig](./js-apis-notificationManager-sys.md#notificationmanagersetadditionalconfig12) API to configure this field.<!--RP1End-->                                                        |

## DistributedOptions

Describes distributed notification options.

**System capability**: SystemCapability.Notification.Notification

| Name                              | Type           | Read Only | Optional | Description                              |
| ---------------------------------- | -------------- | ---- | ---- | --------------------------------- |
| isDistributed<sup>8+</sup>          | boolean        | No  | Yes  | Whether the notification is a distributed notification.                 |
| supportDisplayDevices<sup>8+</sup>  | Array\<string> | No  | Yes  | List of the devices to which the notification can be synchronized.          |
| supportOperateDevices<sup>8+</sup>  | Array\<string> | No  | Yes  | List of the devices on which the notification can be opened.            |
