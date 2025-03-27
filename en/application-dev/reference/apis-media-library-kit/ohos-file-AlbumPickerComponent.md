# @ohos.file.AlbumPickerComponent (AlbumPickerComponent)

The AlbumPickerComponent embedded in the UI of an application allows the application to access the albums in the user directory without any permission.

This component must be used together with [PhotoPickerComponent](ohos-file-PhotoPickerComponent.md). When a user selects an album by using **AlbumPickerComponent**, **PhotoPickerComponent** is instructed to update the photos and videos in the album.

> **NOTE**
>
> This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { AlbumPickerComponent, AlbumPickerOptions, AlbumInfo, photoAccessHelper, EmptyAreaClickCallback } from '@kit.MediaLibraryKit';
```

## Properties

The [universal properties](../apis-arkui/arkui-ts/ts-component-general-attributes.md) are supported.

## AlbumPickerComponent

AlbumPickerComponent({
  albumPickerOptions?: AlbumPickerOptions,
  onAlbumClick?: (albumInfo: AlbumInfo) => boolean,
  onEmptyAreaClick?: EmptyAreaClickCallback
})

Allows the application to access the albums in the user directory without any permission.

**Decorator**: @Component

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name                | Type                                                 | Mandatory | Description                             |
|--------------------|-----------------------------------------------------|-----|---------------------------------|
| albumPickerOptions | [AlbumPickerOptions](#albumpickeroptions)           | No  | **AlbumPicker** configuration.<br>**Atomic service API**: This API can be used in atomic services since API version 12.             |
| onAlbumClick       | (albumInfo: [AlbumInfo](#albuminfo)) => boolean     | No  | Callback used to return the album URI when an album is selected by a user.<br>**Atomic service API**: This API can be used in atomic services since API version 12.   |
| onEmptyAreaClick<sup>13+</sup>   | [EmptyAreaClickCallback](#emptyareaclickcallback13) | No  | Callback to be invoked when the blank area of **AlbumPickerComponent** is tapped, which is used to notify the application of the tap.<br>**Atomic service API**: This API can be used in atomic services since API version 13.|

## AlbumPickerOptions

Represents the **AlbumPicker** configuration.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name            | Type | Mandatory | Description                                                         |
|----------------|-------|-----|-------------------------------------------------------------|
| themeColorMode | [PickerColorMode](ohos-file-PhotoPickerComponent.md#pickercolormode) | No  | Theme color of the album page. The options are **AUTO**, **Light**, and **Dark**. The default value is **AUTO**.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                        |
| filterType<sup>13+</sup>     | [photoAccessHelper.PhotoViewMIMETypes](js-apis-photoAccessHelper.md#photoviewmimetypes) | No  | Type of the filter. You can use it to display images, videos, or both. If this parameter is not specified, images and videos are displayed in a specific album.<br>**Atomic service API**: This API can be used in atomic services since API version 13.|

## EmptyAreaClickCallback<sup>13+</sup>

type EmptyAreaClickCallback = () => void

Called when the blank area of the **AlbumPickerComponent** component is tapped.

**Atomic service API**: This API can be used in atomic services since API version 13.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

## AlbumInfo

Represents album information.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name | Type | Mandatory | Description   |
|------|------|-----|---------|
| uri  | string | No  | Album URI.|
| albumName  | string | No  | Album name.|

## Example

```ts
// xxx.ets
import { AlbumPickerComponent, AlbumPickerOptions, AlbumInfo, PickerColorMode, photoAccessHelper, EmptyAreaClickCallback } from '@kit.MediaLibraryKit';

@Entry
@Component
struct PickerDemo {
  albumPickerOptions: AlbumPickerOptions = new AlbumPickerOptions();
  private emptyAreaClickCallback: EmptyAreaClickCallback = (): void => this.onEmptyAreaClick();

  aboutToAppear() {
    this.albumPickerOptions.themeColorMode = PickerColorMode.AUTO;
    this.albumPickerOptions.filterType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE;
  }
  
  private onAlbumClick(albumInfo: AlbumInfo): boolean {
    if (albumInfo?.uri) {
      // pickerController instructs PhotoPickerComponent to refresh data.
    }
    if (albumInfo?.albumName) {
      // Perform subsequent processing based on the obtained albumName.
    }
    return true;
  }
  
  private onEmptyAreaClick(): void {
    // Callback when the blank area of the component is tapped.
  }

  build() {
    Stack() {
      AlbumPickerComponent({
        albumPickerOptions: this.albumPickerOptions,
        onAlbumClick:(albumInfo: AlbumInfo): boolean => this.onAlbumClick(albumInfo),
        onEmptyAreaClick(): this.emptyAreaClickCallback,
      }).height('100%').width('100%')
    }
  }
}
