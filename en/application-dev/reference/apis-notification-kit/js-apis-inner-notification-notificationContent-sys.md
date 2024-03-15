# NotificationContent (System API)

The **NotificationContent** module provides APIs for defining the notification content.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [NotificationContent](./js-apis-inner-notification-notificationContent.md).

## NotificationContent

**System capability**: SystemCapability.Notification.Notification

| Name          | Type                                                                       | Read-only| Mandatory| Description              |
| -----------   | --------------------------------------------------------------------------- | ---- | --- | ------------------ |
| liveView<sup>11+</sup>       | [NotificationLiveViewContent](#notificationliveviewcontent11)              | No | No | Common live view.<br>**System API**: This is a system API.|

## NotificationLiveViewContent<sup>11+</sup>

Describes the common live view.

**System capability**: SystemCapability.Notification.Notification

**System API**: This is a system API.

| Name          | Type                                                               | Read-only| Mandatory| Description                                                 |
| -------------- | ------------------------------------------------------------------ | --- | --- | ------------------------------------------------------|
| status         | [LiveViewStatus](#liveviewstatus11)                                | No | Yes | Notification status.                 |
| version        | number                                                             | No | No | Version number of the notification. If the version number stored in the database is 0xffffffff, the value of this parameter is not verified for the update and ended states. Otherwise, it needs to be verified and it must be greater than the version number stored in the database to pass the verification. If this parameter is left blank, the default value **0xffffffff** is used.|
| extraInfo      | [key: string] object                                               | No | No | Extra information of the live view.          |
| pictureInfo    | [key: string] Array\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)> | No | No | Extra image information of the live view.|

## LiveViewStatus<sup>11+</sup>

Describes the status of the common live view.

**System capability**: SystemCapability.Security.AccessToken

**System API**: This is a system API.

| Name                        | Value|   Description  |
| ---------------------------- |----|----------|
| LIVE_VIEW_CREATE             | 0  | The live view is created.    |
| LIVE_VIEW_INCREMENTAL_UPDATE | 1  | The live view is updated in incremental mode.|
| LIVE_VIEW_END                | 2  | The live view is ended.    |
| LIVE_VIEW_FULL_UPDATE        | 3  | The live view is updated in full mode.|
