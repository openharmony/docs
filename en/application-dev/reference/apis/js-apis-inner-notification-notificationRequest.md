# NotificationRequest

The **NotificationRequest** module provides APIs for defining the notification request.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## NotificationRequest

**System capability**: SystemCapability.Notification.Notification

| Name                           | Type                                         | Mandatory| Description                                                                   |
|-------------------------------| --------------------------------------------- | --- |-----------------------------------------------------------------------|
| content                       | [NotificationContent](js-apis-inner-notification-notificationContent.md#notificationcontent)   | Yes | Notification content.                                                                |
| id                            | number                                        | No | Notification ID.                                                                |
| slotType<sup>(deprecated)</sup> | [SlotType](js-apis-notificationManager.md#slottype) | No | Notification slot type.<br>This API is deprecated since API version 9. You are advised to use **notificationSlotType** instead.                       |
| notificationSlotType<sup>11+</sup> | [SlotType](js-apis-notificationManager.md#slottype) | No | Notification slot type.                       |
| isOngoing                     | boolean                                       | No | Whether the notification is an ongoing notification.                                                             |
| isUnremovable                 | boolean                                       | No | Whether the notification can be removed. This parameter applies to continuous notification tasks, such as navigation and music playback. If a notifiation is not removable, it will not be deleted when the user touches the delete button below the notification, but it can still be deleted by swiping left on the notification and touching the delete button.           |
| deliveryTime                  | number                                        | No | Time when the notification is sent.                                                              |
| tapDismissed                  | boolean                                       | No | Whether the notification is automatically cleared.                                                            |
| autoDeletedTime               | number                                        | No | Time when the notification is automatically cleared.                                                             |
| wantAgent                     | [WantAgent](js-apis-app-ability-wantAgent.md) | No | **WantAgent** instance to which the notification will be redirected after being clicked.                                      |
| extraInfo                     | {[key: string]: any}                          | No | Extended parameters.                                                                |
| color                         | number                                        | No | Background color of the notification. Not supported currently.                                                    |
| colorEnabled                  | boolean                                       | No | Whether the notification background color can be enabled. Not supported currently.                                                |
| isAlertOnce                   | boolean                                       | No | Whether the notification triggers an alert only once.                                                       |
| isStopwatch                   | boolean                                       | No | Whether to display the stopwatch.                                                            |
| isCountDown                   | boolean                                       | No | Whether to display the countdown time.                                                           |
| isFloatingIcon                | boolean                                       | No | Whether the notification is displayed as a floating icon in the status bar.                                                           |
| label                         | string                                        | No | Notification label.                                                                |
| badgeIconStyle                | number                                        | No | Notification badge type. Not supported currently.                                                    |
| showDeliveryTime              | boolean                                       | No | Whether to display the time when the notification is delivered.                                                            |
| actionButtons                 | Array\<[NotificationActionButton](js-apis-inner-notification-notificationActionButton.md)\>             | No | Buttons in the notification. Up to three buttons are allowed.                                                         |
| smallIcon                     | [image.PixelMap](js-apis-image.md#pixelmap7) | No | Small notification icon. This field is optional, and the icon size cannot exceed 30 KB.                                                |
| largeIcon                     | [image.PixelMap](js-apis-image.md#pixelmap7) | No | Large notification icon. This field is optional, and the icon size cannot exceed 30 KB.                                                |
| creatorBundleName             | string                                        | No | Name of the bundle that creates the notification.                                                             |
| creatorUid                    | number                                        | No | UID used for creating the notification.                                                            |
| creatorPid                    | number                                        | No | PID used for creating the notification.                                                            |
| creatorUserId<sup>8+<sup>     | number                                       | No | ID of the user who creates the notification.                                                         |
| hashCode                      | string                                        | No | Unique ID of the notification.                                                              |
| classification                | string                                        | No | Notification category.<br>**System API**: This is a system API and cannot be called by third-party applications.                              |
| groupName<sup>8+<sup>         | string                                        | No | Notification group name.                                                               |
| template<sup>8+<sup>          | [NotificationTemplate](./js-apis-inner-notification-notificationTemplate.md) | No | Notification template.                                                                |
| isRemoveAllowed<sup>8+<sup>   | boolean                                | No | Whether the notification can be removed. If a notifiation is not removable, it will not be deleted when the user touches the delete button below the notification, but it can still be deleted by swiping left on the notification and touching the delete button.<br>**System API**: This is a system API and cannot be called by third-party applications.|
| source<sup>8+<sup>            | number                                        | No | Notification source.<br>**System API**: This is a system API and cannot be called by third-party applications.                               |
| distributedOption<sup>8+<sup> | [DistributedOptions](#distributedoptions)                 | No | Distributed notification options.                                                            |
| deviceId<sup>8+<sup>          | string                                        | No | Device ID of the notification source.<br>**System API**: This is a system API and cannot be called by third-party applications.                      |
| notificationFlags<sup>8+<sup> | [NotificationFlags](js-apis-inner-notification-notificationFlags.md#notificationflags)                    | No | Notification flags.                                                 |
| removalWantAgent<sup>9+<sup>  | [WantAgent](js-apis-app-ability-wantAgent.md) | No | **WantAgent** instance to which the notification will be redirected when it is removed.                                         |
| badgeNumber<sup>9+<sup>       | number                    | No | Number of notifications displayed on the application icon.                                                       |


## DistributedOptions

Describes distributed notification options.

**System capability**: SystemCapability.Notification.Notification

| Name                  | Type           | Mandatory| Description                              |
| ---------------------- | -------------- | ---- | ---------------------------------- |
| isDistributed<sup>8+<sup>          | boolean        | No  | Whether the notification is a distributed notification.                  |
| supportDisplayDevices<sup>8+<sup>  | Array\<string> | No  | List of the devices to which the notification can be synchronized.           |
| supportOperateDevices<sup>8+<sup>  | Array\<string> | No  | List of the devices on which the notification can be opened.             |
| remindType<sup>8+<sup>             | number         | No  | Notification reminder type.<br>**System API**: This is a system API and cannot be called by third-party applications.                   |
