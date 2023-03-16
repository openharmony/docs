# NotificationContent

The **NotificationContent** module describes the notification content.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**System capability**: SystemCapability.Notification.Notification

| Name       | Type                                                        | Readable| Writable| Description              |
| ----------- | ------------------------------------------------------------ | ---- | --- | ------------------ |
| contentType | [ContentType](./js-apis-notificationManager.md#contenttype)                                  | Yes | Yes | Notification content type.      |
| normal      | [NotificationBasicContent](#notificationbasiccontent)        | Yes | Yes | Normal text.  |
| longText    | [NotificationLongTextContent](#notificationlongtextcontent)  | Yes | Yes | Long text.|
| multiLine   | [NotificationMultiLineContent](#notificationmultilinecontent) | Yes | Yes | Multi-line text.  |
| picture     | [NotificationPictureContent](#notificationpicturecontent)    | Yes | Yes | Picture-attached.  |

## NotificationBasicContent

Describes the normal text notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type  | Readable| Writable| Description                              |
| -------------- | ------ | ---- | ---- | ---------------------------------- |
| title          | string | Yes  | Yes  | Notification title.                        |
| text           | string | Yes  | Yes  | Notification content.                        |
| additionalText | string | Yes  | Yes  | Additional information of the notification.|


## NotificationLongTextContent

Describes the long text notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type  | Readable| Writable| Description                            |
| -------------- | ------ | ---- | --- | -------------------------------- |
| title          | string | Yes | Yes | Notification title.                        |
| text           | string | Yes | Yes | Notification content.                        |
| additionalText | string | Yes | Yes | Additional information of the notification.|
| longText       | string | Yes | Yes | Long text of the notification.                    |
| briefText      | string | Yes | Yes | Brief text of the notification.|
| expandedTitle  | string | Yes | Yes | Title of the notification in the expanded state.                |


## NotificationMultiLineContent

Describes the multi-line text notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type           | Readable| Writable| Description                            |
| -------------- | --------------- | --- | --- | -------------------------------- |
| title          | string          | Yes | Yes | Notification title.                        |
| text           | string          | Yes | Yes | Notification content.                        |
| additionalText | string          | Yes | Yes | Additional information of the notification.|
| briefText      | string          | Yes | Yes | Brief text of the notification.|
| longTitle      | string          | Yes | Yes | Title of the notification in the expanded state.                |
| lines          | Array\<string\> | Yes | Yes | Multi-line text of the notification.                  |


## NotificationPictureContent

Describes the picture-attached notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type          | Readable| Writable| Description                            |
| -------------- | -------------- | ---- | --- | -------------------------------- |
| title          | string         | Yes | Yes | Notification title.                        |
| text           | string         | Yes | Yes | Notification content.                        |
| additionalText | string         | Yes | Yes | Additional information of the notification.|
| briefText      | string         | Yes | Yes | Brief text of the notification.|
| expandedTitle  | string         | Yes | Yes | Title of the notification in the expanded state.                |
| picture        | [image.PixelMap](js-apis-image.md#pixelmap7) | Yes | Yes | Picture attached to the notification.                  |
