# @ohos.file.AlbumPickerComponent (AlbumPickerComponent)

The **AlbumPickerComponent** component embedded in the UI of an application allows the application to access the albums in the user directory without any permission.

This component must be used together with [PhotoPickerComponent](ohos-file-PhotoPickerComponent.md). When a user selects an album by using **AlbumPickerComponent**, **PhotoPickerComponent** is instructed to update the photos and videos in the album.

> **NOTE**
>
> This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { AlbumPickerComponent, AlbumPickerOptions, AlbumInfo } from '@kit.MediaLibraryKit';
```

## Properties

The [universal properties](../apis-arkui/arkui-ts/ts-universal-attributes-size.md) are supported.

## AlbumPickerComponent

AlbumPickerComponent({
  albumPickerOptions?: AlbumPickerOptions,
  onAlbumClick?: (albumInfo: AlbumInfo) => boolean
})

Allows the application to access the albums in the user directory without any permission.

**Decorator**: @Component

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type | Mandatory | Description   |
|-------|-------|-----|------------|
| albumPickerOptions    | [AlbumPickerOptions](#albumpickeroptions) | No  |  **AlbumPicker** configuration.                         |
| onAlbumClick  | (albumInfo: [AlbumInfo](#albuminfo)) => boolean   | No  |  Callback used to return the album URI when an album is selected by a user.  |

## AlbumPickerOptions

Represents the **AlbumPicker** configuration.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name | Type | Mandatory | Description   |
|------|-------|-----|----------|
| themeColorMode  | [PickerColorMode](ohos-file-PhotoPickerComponent.md#pickercolormode) | No  | Theme color of the album page. The options are **AUTO**, **Light**, and **Dark**. The default value is **AUTO**.|

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
import { AlbumPickerComponent, AlbumPickerOptions, AlbumInfo, PickerColorMode } from '@kit.MediaLibraryKit';

@Entry
@Component
struct PickerDemo {
  albumPickerOptions: AlbumPickerOptions = new AlbumPickerOptions();

  aboutToAppear() {
    this.albumPickerOptions.themeColorMode = PickerColorMode.AUTO;
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

  build() {
    Stack() {
      AlbumPickerComponent({
        albumPickerOptions: this.albumPickerOptions,
        onAlbumClick:(albumInfo: AlbumInfo): boolean => this.onAlbumClick(albumInfo),
      }).height('100%').width('100%')
    }
  }
}

```