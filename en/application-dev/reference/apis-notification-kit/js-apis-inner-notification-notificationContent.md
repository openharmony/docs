# NotificationContent

The **NotificationContent** module provides APIs for defining the notification content.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## NotificationContent

**System capability**: SystemCapability.Notification.Notification

| Name          | Type                                                                       | Read-only| Mandatory| Description              |
| -----------   | --------------------------------------------------------------------------- | ---- | --- | ------------------ |
| contentType<sup>(deprecated)</sup> | [ContentType](./js-apis-notificationManager.md#contenttype)  | No | No | Notification content type.<br>This API is deprecated since API version 11. You are advised to use **notificationContentType** instead.      |
| notificationContentType<sup>11+</sup>    | [ContentType](./js-apis-notificationManager.md#contenttype)                | No | No | Notification content type.      |
| normal         | [NotificationBasicContent](#notificationbasiccontent)                      | No | No | Normal text.  |
| longText       | [NotificationLongTextContent](#notificationlongtextcontent)                | No | No | Long text.|
| multiLine      | [NotificationMultiLineContent](#notificationmultilinecontent)              | No | No | Multi-line text.  |
| picture        | [NotificationPictureContent](#notificationpicturecontent)                  | No | No | Picture-attached.  |
| systemLiveView<sup>11+</sup> | [NotificationSystemLiveViewContent](#notificationsystemliveviewcontent)    | No | No | System live view. Not supported currently.|

## NotificationBasicContent

Describes the normal text notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type   | Read-only| Mandatory| Description                              |
| -------------- | ------ | ---- |-----| ---------------------------------- |
| title          | string |  No |  Yes | Notification title. (The value cannot be an empty string and cannot exceed 200 bytes.)        |
| text           | string |  No |  Yes | Notification content. (The value cannot be an empty string and cannot exceed 200 bytes.)        |
| additionalText | string |  No |  No | Additional text of a notification, which is a supplement to the notification content. (The value cannot exceed 200 bytes.)  |

## NotificationLongTextContent

Describes the long text notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type   | Read-only| Mandatory| Description                            |
| -------------- | ------ | ---- | --- | -------------------------------- |
| title          | string |  No | Yes | Notification title. (The value cannot be an empty string and cannot exceed 200 bytes.)                        |
| text           | string |  No | Yes | Notification content. (The value cannot be an empty string and cannot exceed 200 bytes.)                        |
| additionalText | string |  No | No | Additional text of a notification, which is a supplement to the notification content. (The value cannot exceed 200 bytes.)  |
| longText       | string |  No | Yes | Long text of the notification. (The value cannot be an empty string and cannot exceed 200 bytes.)                    |
| briefText      | string |  No | Yes | Notification summary. (The value cannot be an empty string and cannot exceed 200 bytes.)  |
| expandedTitle  | string |  No | Yes | Title of the expanded notification. (The value cannot be an empty string and cannot exceed 200 bytes.)                |


## NotificationMultiLineContent

Describes the multi-line text notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type           | Read-only| Mandatory| Description                            |
| -------------- | --------------- | --- | --- | -------------------------------- |
| title          | string          | No | Yes | Notification title. (The value cannot be an empty string and cannot exceed 200 bytes.)      |
| text           | string          | No | Yes | Notification content. (The value cannot be an empty string and cannot exceed 200 bytes.)      |
| additionalText | string          | No | No | Additional text of a notification, which is a supplement to the notification content. (The value cannot exceed 200 bytes.)|
| briefText      | string          | No | Yes | Notification summary. (The value cannot be an empty string and cannot exceed 200 bytes.)|
| longTitle      | string          | No | Yes | Title of the expanded notification. (The value cannot be an empty string and cannot exceed 200 bytes.)|
| lines          | Array\<string\> | No | Yes | Multi-line text of the notification. (The value cannot exceed 200 bytes.)                 |


## NotificationPictureContent

Describes the picture-attached notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type                                         | Read-only| Mandatory| Description                              |
| -------------- | -------------------------------------------- | ---- | --- |------------------------------------|
| title          | string                                       |  No | Yes | Notification title. (The value cannot be an empty string and cannot exceed 200 bytes.)         |
| text           | string                                       |  No | Yes | Notification content. (The value cannot be an empty string and cannot exceed 200 bytes.)         |
| additionalText | string                                       |  No | No | Additional text of a notification, which is a supplement to the notification content. (The value cannot exceed 200 bytes.)   |
| briefText      | string                                       |  No | Yes | Notification summary. (The value cannot be an empty string and cannot exceed 200 bytes.)|
| expandedTitle  | string                                       |  No | Yes | Title of the expanded notification. (The value cannot be an empty string and cannot exceed 200 bytes.)   |
| picture        | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) |  No | Yes | Picture content of the notification. (The total number of bytes of image pixels cannot exceed 2 MB.)|


## NotificationSystemLiveViewContent

Describes the system live view notification. Not supported currently.

**System capability**: SystemCapability.Notification.Notification

| Name                        | Type                                            | Read-only| Mandatory| Description                              |
| ---------------------------- | ----------------------------------------------- | --- | --- | -----------------------------------|
| title                        | string                                          | No | Yes | Notification title. (The value cannot be an empty string and cannot exceed 200 bytes.)         |
| text                         | string                                          | No | Yes | Notification content. (The value cannot be an empty string and cannot exceed 200 bytes.)         |
| additionalText               | string                                          | No | No | Additional text of a notification, which is a supplement to the notification content. (The value cannot exceed 200 bytes.)    |
| typeCode<sup>11+</sup>       | number                                          | No | Yes | Type code, which identifies the type of the service that invokes the API.      |
| capsule<sup>11+</sup>        | [NotificationCapsule](#notificationcapsule11)   | No | No | Capsule of the notification.                    |
| button<sup>11+</sup>         | [NotificationButton](#notificationbutton11)     | No | No | Button in the notification.                    |
| time<sup>11+</sup>           | [NotificationTime](#notificationtime11)         | No | No | Time of the notification.                    |
| progress<sup>11+</sup>       | [NotificationProgress](#notificationprogress11) | No | No | Progress of the notification.                    |


## NotificationCapsule<sup>11+</sup>

Describe the notification capsule. Not supported currently.

**System capability**: SystemCapability.Notification.Notification

| Name           | Type                                         | Read-only| Mandatory| Description                           |
| --------------- | -------------------------------------------- | --- | --- | -------------------------------- |
| title           | string                                       | No | No | Title of the capsule.                       |
| icon            | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | No | No | Icon of the capsule.                       |
| backgroundColor | string                                       | No | No | Background color of the capsule.                       |


## NotificationButton<sup>11+</sup>

Describes the notification button. Not supported currently.

**System capability**: SystemCapability.Notification.Notification

| Name | Type                                                  | Read-only| Mandatory| Description            |
| ----- | ----------------------------------------------------- | --- | --- | ----------------- |
| names | Array\<string\>                                       | No |  No| Button names. A maximum of three names are supported.  |
| icons | Array\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)\> | No |  No| Button icons. A maximum of three icons are supported.  |


## NotificationTime<sup>11+</sup>

Describes the notification time. Not supported currently.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type             | Read-only| Mandatory| Description                            |
| -------------- | ---------------- | --- | --- | -------------------------------- |
| initialTime    | number           | No | No | Start time.               |
| isCountDown    | boolean          | No | No | Whether to count down.                    |
| isPaused       | boolean          | No | No | Whether to pause the progress.                      |
| isInTitle      | boolean          | No | No | Whether the time is displayed in the title.          |


## NotificationProgress<sup>11+</sup>

Describes the notification progress. Not supported currently.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type           | Read-only| Mandatory| Description                            |
| -------------- | --------------- | --- | --- | -------------------------------- |
| maxValue        | number         | No | No | Maximum progress value.                      |
| currentValue    | number         | No | No | Current progress value.                      |
| isPercentage    | boolean        | No | No | Whether to show the progress in percentage.                  |
