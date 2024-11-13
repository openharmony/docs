# @ohos.file.RecentPhotoComponent (RecentPhotoComponent)

The **RecentPhotoComponent** component embedded in the UI of an application allows the application to access the latest image or video in the user directory without the required permission. This component grants the application only the read permission.

> **NOTE**
>
> This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import {
  RecentPhotoComponent, RecentPhotoOptions, RecentPhotoCheckResultCallback,
  RecentPhotoClickCallback, PhotoSource
} from '@ohos.file.RecentPhotoComponent';
```

## Properties

The [universal properties](../apis-arkui/arkui-ts/ts-universal-attributes-size.md) are supported.

## RecentPhotoComponent

RecentPhotoComponent({
  recentPhotoOptions?: RecentPhotoOptions,
  onRecentPhotoCheckResult?: RecentPhotoCheckResultCallback,
  onRecentPhotoClick: RecentPhotoClickCallback
})

Allows the application  to access the latest image or video in the user directory without the media access permission.

**Decorator**: @Component

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name         | Type           | Mandatory | Decorator Description     | Description                |
|---------------|-----------------|-------|-----------------|--------------------------|
| recentPhotoOptions         | [RecentPhotoOptions](#recentphotooptions)                             | No  | - | Configuration of the latest image or video. |
| onRecentPhotoCheckResult   | [RecentPhotoCheckResultCallback](#recentphotocheckresultcallback)     | No  | - | Callback used to return the query result of the latest image or video. |
| onRecentPhotoClick         | [RecentPhotoClickCallback](#recentphotoclickcallback)                 | Yes  | - | Callback to be called when the latest image or video is selected.     |

## RecentPhotoOptions

Represents the configuration of the latest image or video.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                   | Type                                   | Mandatory | Description  |
|-------------------------|-----------------------------------------|-------|--------|
| period                  | number                                  | No   | Time period for the latest image or video, in seconds. The maximum value is **86400** seconds (one day), which is also the default value. If there is no image or video in the specified period, the component is not displayed. |
| MIMEType                | [PhotoViewMIMETypes](js-apis-photoAccessHelper.md#photoviewmimetypes)   | No   | Types of the file displayed. The default value is **PhotoViewMIMETypes.IMAGE_VIDEO_TYPE**.                        |
| photoSource             | [PhotoSource](#photosource)                                 | No   | Source of the latest image or video, for example, photo or video taken by the camera or screenshot. By default, the source is not restricted.                              |

## RecentPhotoCheckResultCallback

type RecentPhotoCheckResultCallback = (recentPhotoExists: boolean) => void

Called to return the query result of the latest image or video.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| recentPhotoExists | boolean | Yes| Whether the latest image or video exists.|

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
| boolean | Processing result of the latest image or video.|

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
  RecentPhotoComponent, RecentPhotoOptions, PhotoSource, RecentPhotoCheckResultCallback, RecentPhotoClickCallback
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

  build() {
    Stack() {
      RecentPhotoComponent({
        recentPhotoOptions: this.recentPhotoOptions,
        onRecentPhotoCheckResult: this.recentPhotoCheckResultCallback,
        onRecentPhotoClick: this.recentPhotoClickCallback,
      }).height('100%').width('100%')
    }
  }
}
```
