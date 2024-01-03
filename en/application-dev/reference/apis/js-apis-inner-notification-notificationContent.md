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
| systemLiveView<sup>11+</sup> | [NotificationSystemLiveViewContent](#notificationsystemliveviewcontent)    | No | No | Live view (for system applications only).|

## NotificationBasicContent

Describes the normal text notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type   | Read-only| Mandatory| Description                              |
| -------------- | ------ | ---- |-----| ---------------------------------- |
| title          | string |  No |  Yes | Notification title. It cannot be an empty string.        |
| text           | string |  No |  Yes | Notification content. It cannot be an empty string.        |
| additionalText | string |  No |  No | Additional information of the notification.  |


## NotificationLongTextContent

Describes the long text notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type   | Read-only| Mandatory| Description                            |
| -------------- | ------ | ---- | --- | -------------------------------- |
| title          | string |  No | Yes | Notification title. It cannot be an empty string.                        |
| text           | string |  No | Yes | Notification content. It cannot be an empty string.                        |
| additionalText | string |  No | No | Additional information of the notification.  |
| longText       | string |  No | Yes | Long text of the notification. It cannot be an empty string.                    |
| briefText      | string |  No | Yes | Brief text of the notification. It cannot be an empty string.  |
| expandedTitle  | string |  No | Yes | Title of the notification in the expanded state. It cannot be an empty string.                |


## NotificationMultiLineContent

Describes the multi-line text notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type           | Read-only| Mandatory| Description                            |
| -------------- | --------------- | --- | --- | -------------------------------- |
| title          | string          | No | Yes | Notification title. It cannot be an empty string.      |
| text           | string          | No | Yes | Notification content. It cannot be an empty string.      |
| additionalText | string          | No | No | Additional information of the notification.|
| briefText      | string          | No | Yes | Brief text of the notification. It cannot be an empty string.|
| longTitle      | string          | No | Yes | Title of the notification in the expanded state. It cannot be an empty string.|
| lines          | Array\<string\> | No | Yes | Multi-line text of the notification.                 |


## NotificationPictureContent

Describes the picture-attached notification.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type                                         | Read-only| Mandatory| Description                              |
| -------------- | -------------------------------------------- | ---- | --- |------------------------------------|
| title          | string                                       |  No | Yes | Notification title. It cannot be an empty string.         |
| text           | string                                       |  No | Yes | Notification content. It cannot be an empty string.         |
| additionalText | string                                       |  No | No | Additional information of the notification.   |
| briefText      | string                                       |  No | Yes | Brief text of the notification. It cannot be an empty string.|
| expandedTitle  | string                                       |  No | Yes | Title of the notification in the expanded state. It cannot be an empty string.   |
| picture        | [image.PixelMap](js-apis-image.md#pixelmap7) |  No | Yes | Picture attached to the notification. The maximum size is 2 MB.|


## NotificationSystemLiveViewContent

Describes the live view notification. This API is available for system applications only.

**System capability**: SystemCapability.Notification.Notification

| Name                        | Type                                            | Read-only| Mandatory| Description                              |
| ---------------------------- | ----------------------------------------------- | --- | --- | -----------------------------------|
| title                        | string                                          | No | Yes | Notification title. It cannot be an empty string.         |
| text                         | string                                          | No | Yes | Notification content. It cannot be an empty string.         |
| additionalText               | string                                          | No | No | Additional information of the notification.    |
| typeCode<sup>11+</sup>       | number                                          | No | Yes | Type code, which identifies the type of the service that invokes the API.      |
| capsule<sup>11+</sup>        | [NotificationCapsule](#notificationcapsule11)   | No | No | Capsule of the notification.                    |
| button<sup>11+</sup>         | [NotificationButton](#notificationbutton11)     | No | No | Button in the notification.                    |
| time<sup>11+</sup>           | [NotificationTime](#notificationtime11)         | No | No | Time of the notification.                    |
| progress<sup>11+</sup>       | [NotificationProgress](#notificationprogress11) | No | No | Progress of the notification.                    |


## NotificationCapsule<sup>11+</sup>

Describe the notification capsule.

**System capability**: SystemCapability.Notification.Notification

| Name           | Type                                         | Read-only| Mandatory| Description                           |
| --------------- | -------------------------------------------- | --- | --- | -------------------------------- |
| title           | string                                       | No | No | Title of the capsule.                       |
| icon            | [image.PixelMap](js-apis-image.md#pixelmap7) | No | No | Icon of the capsule.                       |
| backgroundColor | string                                       | No | No | Background color of the capsule.                       |


## NotificationButton<sup>11+</sup>

Describes the notification button.

**System capability**: SystemCapability.Notification.Notification

| Name | Type                                                  | Read-only| Mandatory| Description            |
| ----- | ----------------------------------------------------- | --- | --- | ----------------- |
| names | Array\<string\>                                       | No |  No| Button names. A maximum of three names are supported.  |
| icons | Array\<[image.PixelMap](js-apis-image.md#pixelmap7)\> | No |  No| Button icons. A maximum of three icons are supported.  |


## NotificationTime<sup>11+</sup>

Describes the notification time.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type             | Read-only| Mandatory| Description                            |
| -------------- | ---------------- | --- | --- | -------------------------------- |
| initialTime    | number           | No | No | Start time.               |
| isCountDown    | boolean          | No | No | Whether to count down.                    |
| isPaused       | boolean          | No | No | Whether to pause the progress.                      |
| isInTitle      | boolean          | No | No | Whether the time is displayed in the title.          |


## NotificationProgress<sup>11+</sup>

Describes the notification progress.

**System capability**: SystemCapability.Notification.Notification

| Name          | Type           | Read-only| Mandatory| Description                            |
| -------------- | --------------- | --- | --- | -------------------------------- |
| maxValue        | number         | No | No | Maximum progress value.                      |
| currentValue    | number         | No | No | Current progress value.                      |
| isPercentage    | boolean        | No | No | Whether to show the progress in percentage.                  |
