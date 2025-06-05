# NotificationContent

The **NotificationContent** module provides APIs for defining the notification content.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## NotificationContent

Describes the notification contents.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type                                                                       | Read Only| Optional| Description              |
| -----------   | --------------------------------------------------------------------------- | ---- | --- | ------------------ |
| contentType<sup>(deprecated)</sup> | [notification.ContentType](./js-apis-notification.md#contenttype)  | No | Yes | Notification content type.<br>This API is deprecated since API version 11. You are advised to use **notificationContentType** instead.      |
| notificationContentType<sup>11+</sup>    | [notificationManager.ContentType](./js-apis-notificationManager.md#contenttype)                | No | Yes | Notification content type.      |
| normal         | [NotificationBasicContent](#notificationbasiccontent)                      | No | Yes | Normal text.  |
| longText       | [NotificationLongTextContent](#notificationlongtextcontent)                | No | Yes | Long text.|
| multiLine      | [NotificationMultiLineContent](#notificationmultilinecontent)              | No | Yes | Multi-line text.  |
| picture        | [NotificationPictureContent](#notificationpicturecontent)                  | No | Yes | Picture-attached.  |
| systemLiveView<sup>11+</sup> | [NotificationSystemLiveViewContent](#notificationsystemliveviewcontent)    | No | Yes | System live view. A third-party application cannot directly create a notification of this type. After the system proxy creates a system live view, the third-party application releases a notification with the same ID to update the specified content.|

## NotificationBasicContent

Describes the normal text notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type   | Read Only| Optional| Description                              |
| -------------- | ------ | ---- |-----| ---------------------------------- |
| title          | string |  No |  No | Notification title. It cannot be empty or exceed 1024 bytes. Excess content will be truncated.        |
| text           | string |  No |  No | Notification content. It cannot be empty or exceed 3072 bytes. Excess content will be truncated.        |
| additionalText | string |  No |  Yes | Additional information of the notification. It cannot exceed 3072 bytes. Excess content will be truncated.  |
| lockscreenPicture<sup>12+</sup> | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) |  No |  Yes | Picture of a notification displayed on the lock screen. Currently, only the live view notification is supported. The total number of the icon pixel bytes cannot exceed 192 KB (which is obtained through [getPixelBytesNumber](../apis-image-kit/js-apis-image.md#getpixelbytesnumber7). The recommended icon size is 128 × 128 pixels. The display effect depends on the device capability and notification center UI style.  |

## NotificationLongTextContent

Describes the long text notification. This API is inherited from [NotificationBasicContent](#notificationbasiccontent).

> **NOTE**
>
> The display effect depends on the device capability and notification center UI style.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type   | Read Only| Optional| Description                            |
| -------------- | ------ | ---- | --- | -------------------------------- |
| longText       | string |  No | No | Long text of the notification. It cannot be an empty string and exceed 3072 bytes. Excess content will be truncated.                    |
| briefText      | string |  No | No | Brief text of the notification. It cannot be empty or exceed 1024 bytes. Excess content will be truncated.  |
| expandedTitle  | string |  No | No | Title of the notification in the expanded state. It cannot be empty or exceed 1024 bytes. Excess content will be truncated.                |


## NotificationMultiLineContent

Describes the multi-line text notification. This API is inherited from [NotificationBasicContent](#notificationbasiccontent).

> **NOTE**
>
> - When the multi-line text notification and another notification form a group notification, the group notification is displayed as a [normal text notification](#notificationbasiccontent) by default. After the group notification is expanded, the value of **longTitle** is used as the title, and the value of **lines** is used as the multi-line text content.<br>When the multi-line text notification is displayed independently, the value of **longTitle** is used as the title, and the value of **lines** is used as the multi-line text content.
>
> - The display effect depends on the device capability and notification center UI style.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type           | Read Only| Optional| Description                            |
| -------------- | --------------- | --- | --- | -------------------------------- |
| briefText      | string          | No | No | Brief text of the notification. It cannot be empty or exceed 1024 bytes. Excess content will be truncated.|
| longTitle      | string          | No | No | Title of the notification in the expanded state. It cannot be empty or exceed 1024 bytes. Excess content will be truncated.|
| lines          | Array\<string\> | No | No | Multi-line text of a notification. A maximum of three lines are supported, and each line cannot exceed 1024 bytes. Excess content will be truncated.                 |


## NotificationPictureContent

Describes the picture-attached notification. This API is inherited from [NotificationBasicContent](#notificationbasiccontent).

> **NOTE**
>
> The display effect depends on the device capability and notification center UI style.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type                                         | Read Only| Optional| Description                              |
| -------------- | -------------------------------------------- | ---- | --- |------------------------------------|
| briefText      | string                                       |  No | No | Brief text of the notification. It cannot be empty or exceed 1024 bytes. Excess content will be truncated.|
| expandedTitle  | string                                       |  No | No | Title of the notification in the expanded state. It cannot be empty or exceed 1024 bytes. Excess content will be truncated.   |
| picture        | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) |  No | No | Picture content of the notification. The total number of bytes of image pixels cannot exceed 2 MB. |


## NotificationSystemLiveViewContent

Describes the system live view notification. A third-party application cannot directly create a notification of this type. After the system proxy creates a system live view, the third-party application releases a notification with the same ID to update the specified content. This API is inherited from [NotificationBasicContent](#notificationbasiccontent).

**System capability**: SystemCapability.Notification.Notification

| Name                        | Type                                            | Read Only| Optional| Description                              |
| ---------------------------- | ----------------------------------------------- | --- | --- | -----------------------------------|
| typeCode<sup>11+</sup>       | number                                          | No | No | Type code, which identifies the type of the service that invokes the API.      |
| capsule<sup>11+</sup>        | [NotificationCapsule](#notificationcapsule11)   | No | Yes | Capsule of the notification.                    |
| button<sup>11+</sup>         | [NotificationButton](#notificationbutton11)     | No | Yes | Button in the notification.                    |
| time<sup>11+</sup>           | [NotificationTime](#notificationtime11)         | No | Yes | Time of the notification.                    |
| progress<sup>11+</sup>       | [NotificationProgress](#notificationprogress11) | No | Yes | Progress of the notification.                    |


## NotificationCapsule<sup>11+</sup>

Describe the notification capsule.

**System capability**: SystemCapability.Notification.Notification

| Name           | Type                                         | Read Only| Optional| Description                           |
| --------------- | -------------------------------------------- | --- | --- | -------------------------------- |
| title           | string                                       | No | Yes | Title of the capsule.                       |
| icon            | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | No | Yes | Icon of the capsule.                       |
| backgroundColor | string                                       | No | Yes | Background color of the capsule.                       |


## NotificationButton<sup>11+</sup>

Describes the notification button.

**System capability**: SystemCapability.Notification.Notification

| Name | Type                                                  | Read Only| Optional| Description            |
| ----- | ----------------------------------------------------- | --- | --- | ----------------- |
| names | Array\<string\>                                       | No |  Yes| Button names. A maximum of three names are supported.  |
| icons | Array\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)\> | No |  Yes| Button icons. A maximum of three icons are supported.  |
| iconsResource<sup>12+</sup> | Array\<[Resource](../apis-arkui/arkui-ts/ts-types.md#resource)\> | No |  Yes| Button icon resources. A maximum of three icon resources are supported.  |

## NotificationTime<sup>11+</sup>

Describes the notification timing information.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type             | Read Only| Optional| Description                            |
| -------------- | ---------------- | --- | --- | -------------------------------- |
| initialTime    | number           | No | Yes | Start time, in milliseconds.               |
| isCountDown    | boolean          | No | Yes | Whether to count down. The default value is **false**.<br> - **true**: Yes.<br> - **false**: No.|
| isPaused       | boolean          | No | Yes | Whether to pause the progress. The default value is **false**.<br> - **true**: Yes.<br> - **false**: No.  |
| isInTitle      | boolean          | No | Yes | Whether the time is displayed in the title. The default value is **false**.<br> - **true**: Yes.<br> - **false**: No.|

**Example**:

```ts
// The notification counts down from three seconds and the time is displayed in the title.
time: {
    initialTime: 3000,
    isCountDown: true,
    isPaused: false,
    isInTitle: true,
}
```


## NotificationProgress<sup>11+</sup>

Describes the notification progress.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type           | Read Only| Optional| Description                            |
| -------------- | --------------- | --- | --- | -------------------------------- |
| maxValue        | number         | No | Yes | Maximum progress value.                      |
| currentValue    | number         | No | Yes | Current progress value.                      |
| isPercentage    | boolean        | No | Yes | Whether to show the progress in percentage. The default value is **false**.<br> - **true**: Yes.<br> - **false**: No.|
