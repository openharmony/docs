# @ohos.file.RecentPhotoComponent (RecentPhotoComponent)

The RecentPhotoComponent embedded in the UI of an application allows the application to access the latest image or video in the user directory without the required permission. This component grants the application only the read permission.

> **NOTE**
>
> This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import {
  RecentPhotoComponent, RecentPhotoOptions, RecentPhotoCheckResultCallback,
  RecentPhotoClickCallback, PhotoSource, RecentPhotoInfo, RecentPhotoCheckInfoCallback,
} from '@ohos.file.RecentPhotoComponent';
```

## Properties

The [universal properties](../apis-arkui/arkui-ts/ts-component-general-attributes.md) are supported.

## RecentPhotoComponent

RecentPhotoComponent({
  recentPhotoOptions?: RecentPhotoOptions,
  onRecentPhotoCheckResult?: RecentPhotoCheckResultCallback,
  onRecentPhotoClick: RecentPhotoClickCallback,
  onRecentPhotoCheckInfo?: RecentPhotoCheckInfoCallback,
})

Allows the application  to access the latest image or video in the user directory without the media access permission.

**Decorator**: @Component

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name                      | Type                                                               | Mandatory| Description                      |
|--------------------------|-------------------------------------------------------------------|------|----------------------------|
| recentPhotoOptions       | [RecentPhotoOptions](#recentphotooptions)                         | No | Configuration of the latest image or video.<br> **Atomic service API**: This API can be used in atomic services since API version 12.               |
| onRecentPhotoCheckResult | [RecentPhotoCheckResultCallback](#recentphotocheckresultcallback) | No | Callback used to return the query result of the latest image or video.<br> **Atomic service API**: This API can be used in atomic services since API version 12.             |
| onRecentPhotoClick       | [RecentPhotoClickCallback](#recentphotoclickcallback)             | Yes | Callback to be invoked when the latest image or video is selected.<br> **Atomic service API**: This API can be used in atomic services since API version 12.               |
| onRecentPhotoCheckInfo<sup>13+</sup>   | [RecentPhotoCheckInfoCallback](#recentphotocheckinfocallback13)   | No | Callback used to return information about the latest image or video obtained.<br> **Atomic service API**: This API can be used in atomic services since API version 13.|

## RecentPhotoOptions

Represents the configuration of the latest image or video.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                   | Type                                                                                     | Mandatory | Description  |
|-------------------------|-----------------------------------------------------------------------------------------|-------|--------|
| period                  | number                                                                                  | No   | Time period for the latest image or video, in seconds. The maximum value is **86400** seconds (one day), which is also the default value.<br>If the value is less than or equal to 0, greater than 86400, or not set, the most recent photos over the longest period of up to one day is displayed by default. If there is no image or video in the specified period, the component is not displayed.|
| MIMEType                | [photoAccessHelper.PhotoViewMIMETypes](js-apis-photoAccessHelper.md#photoviewmimetypes) | No   | Types of the file displayed. The default value is **PhotoViewMIMETypes.IMAGE_VIDEO_TYPE**.                        |
| photoSource             | [PhotoSource](#photosource)                                                             | No   | Source of the latest image or video, for example, photo or video taken by the camera or screenshot. By default, the source is not restricted.                              |

## RecentPhotoInfo<sup>13+</sup>

Represents information about the latest image or video.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name        | Type    | Mandatory | Description                                                       |
|------------|--------|-------|-----------------------------------------------------------|
| dateTaken  | number | No   | Time when the latest image or video is taken, in ms. The value is the number of milliseconds elapsed since the Unix epoch (00:00:00 UTC on January 1, 1970).                    |
| identifier | string | No   | Hash value of the name of the latest image or video, which is used to help the application determine whether the image or video to be displayed is the same as the one displayed before.|

## RecentPhotoCheckResultCallback

type RecentPhotoCheckResultCallback = (recentPhotoExists: boolean) => void

Called to return the query result of the latest image or video.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| recentPhotoExists | boolean | Yes| Whether the latest image or video exists. The value **true** means that the latest image or video exists, and **false** means the opposite. The default value is **true**.|

## RecentPhotoClickCallback

type RecentPhotoClickCallback = (recentPhotoInfo: BaseItemInfo) => boolean

Called when the latest image or video is selected.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| recentPhotoInfo | [BaseItemInfo](ohos-file-PhotoPickerComponent.md#baseiteminfo) | Yes| Information about the latest image or video.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Processing result of the latest image or video. The value **true** means that the processing is complete.|

## RecentPhotoCheckInfoCallback<sup>13+</sup>

type RecentPhotoCheckInfoCallback = (recentPhotoExists: boolean, info: RecentPhotoInfo) => void

Called to return whether the latest image or video exists and the information about it.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name              | Type                                   | Mandatory| Description         |
|-------------------|---------------------------------------| -------- |-------------|
| recentPhotoExists | boolean                               | Yes| Whether the latest image or video exists. The value **true** means that the latest image or video exists, and **false** means the opposite. The default value is **true**.|
| info              | [RecentPhotoInfo](#recentphotoinfo13) | Yes| Information about the latest image or video.  |

## PhotoSource

Enumerates the sources of the image or video data.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name               | Value  | Description                                                                                                                |
|-------------------|-----|--------------------------------------------------------------------------------------------------------------------|
| ALL | 0   | Images and videos from all sources.|
| CAMERA | 1   | Photo or video taken by the camera.|
| SCREENSHOT | 2   | Screenshot or screen capture video.|

## Example

```ts
// xxx.ets
import {
  photoAccessHelper
} from '@kit.MediaLibraryKit';
import {
  RecentPhotoComponent, RecentPhotoOptions, PhotoSource, RecentPhotoInfo, RecentPhotoCheckResultCallback, RecentPhotoClickCallback, RecentPhotoCheckInfoCallback
} from '@ohos.file.RecentPhotoComponent';
import {
  BaseItemInfo
} from '@ohos.file.PhotoPickerComponent';

@Entry
@Component
struct PickerDemo {
  private recentPhotoOptions: RecentPhotoOptions = new RecentPhotoOptions();
  private recentPhotoCheckResultCallback: RecentPhotoCheckResultCallback = (recentPhotoExists: boolean) => this.onRecentPhotoCheckResult(recentPhotoExists);
  private recentPhotoClickCallback: RecentPhotoClickCallback = (recentPhotoInfo: BaseItemInfo): boolean => this.onRecentPhotoClick(recentPhotoInfo);
  private recentPhotoCheckInfoCallback: RecentPhotoCheckInfoCallback = (recentPhotoExists: boolean, info: RecentPhotoInfo) => this.onRecentPhotoCheckInfo(recentPhotoExists, info);

  aboutToAppear() {
    this.recentPhotoOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE;
    this.recentPhotoOptions.period = 30;
    this.recentPhotoOptions.photoSource = PhotoSource.ALL;
  }

  private onRecentPhotoCheckResult(recentPhotoExists: boolean): void {
    // Photo or video that meets the search criteria exists.
    if (recentPhotoExists) {
      console.info('The photo is exist.');
    }
  }

  private onRecentPhotoClick(recentPhotoInfo: BaseItemInfo): boolean {
    // Return the photo or video.
    if (recentPhotoInfo) {
      console.info('The photo uri is ' + recentPhotoInfo.uri);
      return true;
    }
    return true;
  }

  private onRecentPhotoCheckInfo(recentPhotoExists: boolean, info: RecentPhotoInfo): void {
    // Check whether a photo or video that meets the conditions exists. If yes, obtain information about the photo or video.
  }

  build() {
    Stack() {
      RecentPhotoComponent({
        recentPhotoOptions: this.recentPhotoOptions,
        onRecentPhotoCheckResult: this.recentPhotoCheckResultCallback,
        onRecentPhotoClick: this.recentPhotoClickCallback,
        onRecentPhotoCheckInfo: this.recentPhotoCheckInfoCallback,
      }).height('100%').width('100%')
    }
  }
}
```
