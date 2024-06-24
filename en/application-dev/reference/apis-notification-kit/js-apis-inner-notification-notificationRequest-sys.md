# NotificationRequest (System API)

The **NotificationRequest** module provides APIs for defining the notification request.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [NotificationRequest](./js-apis-inner-notification-notificationRequest.md).

## NotificationRequest

**System capability**: SystemCapability.Notification.Notification

| Name                           | Type                                                   |  Read-only| Mandatory| Description                                                                   |
|-------------------------------| -------------------------------------------------------- | ----- | --- |-----------------------------------------------------------------------|
| overlayIcon<sup>11+<sup>      | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)             |   No | No | Notification overlay icon. This field is optional. The total number of bytes of image pixels cannot exceed 100 KB.<br>**System API**: This is a system API.                                                |
| classification                | string                                                   |   No | No | Notification category.<br>**System API**: This is a system API.                              |
| isRemoveAllowed<sup>8+<sup>   | boolean                                                  |   No | No | Whether the notification can be removed. If a notification is not removable, it will not be deleted when the user touches the delete button below the notification, but it can still be deleted by swiping left on the notification and touching the delete button.<br>**System API**: This is a system API.<br>**Required permissions**: ohos.permission.SET_UNREMOVABLE_NOTIFICATION|
| source<sup>8+<sup>            | number                                                   |   Yes | No | Notification source.<br>**System API**: This is a system API.                               |
| deviceId<sup>8+<sup>          | string                                                   |   Yes | No | Device ID of the notification source.<br>**System API**: This is a system API.                      |

## DistributedOptions

Describes distributed notification options.

**System capability**: SystemCapability.Notification.Notification

| Name                  | Type           | Mandatory| Description                              |
| ---------------------- | -------------- | ---- | ---------------------------------- |
| remindType<sup>8+<sup>             | number         | No  | Notification reminder type.<br>**System API**: This is a system API. |


## NotificationFilter<sup>11+</sup>

Describes the filter criteria for querying the live view.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API. 

| Name           | Type                                  | Mandatory| Description                              |
| ----------------| ------------------------------------- | ---- | ---------------------------------- |
| bundle          | [BundleOption](js-apis-inner-notification-notificationCommonDef.md#bundleoption) | Yes  | Bundle information of the live view.|
| notificationKey | [NotificationKey](js-apis-notificationSubscribe-sys.md#notificationkey) | Yes  | Notification information, including the notification ID and label.  |
| extraInfoKeys   | Array\<string>                        | No  | List of extra keys. If this parameter is left empty, all extra information is included.|


## NotificationCheckRequest<sup>11+</sup>

Describes the notification authentication information.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API. 

| Name         | Type                                                      | Mandatory| Description             |
| --------------| --------------------------------------------------------- | ---- | ----------------- |
| contentType   | [ContentType](js-apis-notificationManager.md#contenttype) | Yes  | Notification type.        |
| slotType      | [SlotType](js-apis-notificationManager.md#slottype)       | Yes  | Notification slot type.        |
| extraInfoKeys | Array\<string>                                            | Yes  | Extra information about the live view.|
