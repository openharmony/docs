# NotificationContent (System API)

The **NotificationContent** module provides APIs for defining the notification content.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [NotificationContent](./js-apis-inner-notification-notificationContent.md).

## NotificationContent

**System capability**: SystemCapability.Notification.Notification

| Name          | Type                                                                       | Read Only | Optional | Description              |
| -----------   | --------------------------------------------------------------------------- | ---- | --- | ------------------ |
| liveView<sup>11+</sup>       | [NotificationLiveViewContent](#notificationliveviewcontent11)              | No | Yes | Common live view.<br>**System API**: This is a system API.|

## NotificationLiveViewContent<sup>11+</sup>

Describes the common live view.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

| Name          | Type                                                               | Read Only| Optional | Description                                                 |
| -------------- | ------------------------------------------------------------------ | --- | --- | ------------------------------------------------------|
| status         | [LiveViewStatus](#liveviewstatus11)                                | No | No | Notification status.                 |
| version        | number                                                             | No | Yes | If the version number stored in the database is not **0xffffffff**, the version number needs to be verified when the live view is updated or ended to ensure that the current version number is greater than the version number stored in the database. The default value is **0xffffffff**.|
| extraInfo      | [key: string] object                                               | No | Yes | Extra information of the live view.          |
| pictureInfo    | [key: string] Array\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)> | No | Yes | Extra image information of the live view.|
| isLocalUpdateOnly<sup>12+</sup> | boolean                                           | No | Yes | Whether the live view is updated only locally.    |

## NotificationCapsule<sup>11+</sup>

Describe the notification capsule.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

| Name                 |  Type                        | Read Only | Optional | Description                             |
| --------------------- | ---------------------------- | ---- | ---- | -------------------------------- |
| content<sup>12+</sup> | string                       |  No |  Yes | Extended text of the capsule.                  |

## LiveViewStatus<sup>11+</sup>

Enumerates the statuses of the common live view.

**System capability**: SystemCapability.Security.AccessToken

**System API**: This is a system API.

| Name                        | Value |   Description  |
| ---------------------------- |----|----------|
| LIVE_VIEW_CREATE             | 0  | The live view is created.    |
| LIVE_VIEW_INCREMENTAL_UPDATE | 1  | The live view is updated in incremental mode. |
| LIVE_VIEW_END                | 2  | The live view is ended.    |
| LIVE_VIEW_FULL_UPDATE        | 3  | The live view is updated in full mode. |
