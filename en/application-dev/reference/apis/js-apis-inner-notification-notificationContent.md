# NotificationContent

The **NotificationContent** module describes the notification content.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**System capability**: SystemCapability.Notification.Notification

| Name       | Type                                                        | Read-only| Mandatory| Description              |
| ----------- | ------------------------------------------------------------ | ---- | --- | ------------------ |
| contentType | [ContentType](./js-apis-notificationManager.md#contenttype)  | No | Yes | Notification content type.      |
| normal      | [NotificationBasicContent](#notificationbasiccontent)        | No | No | Normal text.  |
| longText    | [NotificationLongTextContent](#notificationlongtextcontent)  | No | No | Long text.|
| multiLine   | [NotificationMultiLineContent](#notificationmultilinecontent) | No | No | Multi-line text.  |
| picture     | [NotificationPictureContent](#notificationpicturecontent)    | No | No | Picture-attached.  |

## NotificationBasicContent

Describes the normal text notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type  | Read-only| Mandatory| Description                              |
| -------------- | ------ | ---- | ---- | ---------------------------------- |
| title          | string | No  | Yes  | Notification title.                        |
| text           | string | No  | Yes  | Notification content.                        |
| additionalText | string | No  | No  | Additional information of the notification.|


## NotificationLongTextContent

Describes the long text notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type  | Read-only| Mandatory| Description                            |
| -------------- | ------ | ---- | --- | -------------------------------- |
| title          | string | No | Yes | Notification title.                        |
| text           | string | No | Yes | Notification content.                        |
| additionalText | string | No | No | Additional information of the notification.|
| longText       | string | No | Yes | Long text of the notification.                    |
| briefText      | string | No | Yes | Brief text of the notification.  |
| expandedTitle  | string | No | Yes | Title of the notification in the expanded state.                |


## NotificationMultiLineContent

Describes the multi-line text notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type           | Readable| Writable| Description                            |
| -------------- | --------------- | --- | --- | -------------------------------- |
| title          | string          | No | Yes | Notification title.                        |
| text           | string          | No | Yes | Notification content.                        |
| additionalText | string          | No | No | Additional information of the notification.|
| briefText      | string          | No | Yes | Brief text of the notification.|
| longTitle      | string          | No | Yes | Title of the notification in the expanded state.                |
| lines          | Array\<string\> | No | Yes | Multi-line text of the notification.                  |


## NotificationPictureContent

Describes the picture-attached notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type          | Readable| Writable| Description                            |
| -------------- | -------------- | ---- | --- | -------------------------------- |
| title          | string         | No | Yes | Notification title.                        |
| text           | string         | No | Yes | Notification content.                        |
| additionalText | string         | No | No | Additional information of the notification.|
| briefText      | string         | No | Yes | Brief text of the notification.|
| expandedTitle  | string         | No | Yes | Title of the notification in the expanded state.                |
| picture        | [image.PixelMap](js-apis-image.md#pixelmap7) | No | Yes | Picture attached to the notification.                  |
