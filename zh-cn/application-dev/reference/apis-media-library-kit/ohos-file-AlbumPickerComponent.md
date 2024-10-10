# @ohos.file.AlbumPickerComponent (Album Picker组件)

应用可以在布局中嵌入AlbumPickerComponent组件，通过此组件，应用无需申请权限，即可访问公共目录中的相册列表。

需配合[PhotoPickerComponent](ohos-file-PhotoPickerComponent.md)一起使用，用户通过AlbumPickerComponent组件选择对应相册并通知PhotoPickerComponent组件刷新成对应相册的图片和视频。

> **说明：**
>
> 该组件从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

```ts
import { AlbumPickerComponent, AlbumPickerOptions, AlbumInfo, photoAccessHelper } from '@kit.MediaLibraryKit';
import { EmptyAreaClickCallbck } from '@ohos.file.AlbumPickerComponent';
```

## 属性

支持[通用属性](../apis-arkui/arkui-ts/ts-universal-attributes-size.md)。

## AlbumPickerComponent

AlbumPickerComponent({
  albumPickerOptions?: AlbumPickerOptions,
  onAlbumClick?: (albumInfo: AlbumInfo) => boolean,
  onEmptyAreaClick?: EmptyAreaClickCallbck
})

应用可以在布局中嵌入AlbumPickerComponent组件，通过此组件，应用无需申请权限，即可访问公共目录中的的相册列表。

**装饰器类型**：@Component

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 名称                 | 类型                                                | 必填  | 说明                              |
|--------------------|---------------------------------------------------|-----|---------------------------------|
| albumPickerOptions | [AlbumPickerOptions](#albumpickeroptions)         | 否   | AlbumPicker的配置信息。               |
| onAlbumClick       | (albumInfo: [AlbumInfo](#albuminfo)) => boolean   | 否   | 用户选择某个相册时产生的回调事件，将相册uri给到应用。    |
| onEmptyAreaClick<sup>13+</sup>   | [EmptyAreaClickCallbck](#emptyareaclickcallbck13) | 否   | 点击相册组件空白区域时产生的回调事件，将该次点击通知给应用。 |

## AlbumPickerOptions

Album Picker配置选项。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称             | 类型  | 必填  | 说明                                                          |
|----------------|-------|-----|-------------------------------------------------------------|
| themeColorMode | [PickerColorMode](ohos-file-PhotoPickerComponent.md#pickercolormode) | 否   | 相册页主题颜色，包括跟随系统、浅色模式以及深色模式，默认为跟随系统。                          |
| filterType<sup>13+</sup>     | [photoAccessHelper.PhotoViewMIMETypes](js-apis-photoAccessHelper.md#photoviewmimetypes) | 否   | 相册组件过滤参数，可筛选只显示图片、视频或者图片和视频。若未配置此参数，则某个具体相册中显示图片和视频类型的所有资源。 |

## EmptyAreaClickCallbck<sup>13+</sup>

type EmptyAreaClickCallbck = () => void

点击相册组件空白区域时产生的回调事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

## AlbumInfo

相册相关信息。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称  | 类型  | 必填  | 说明    |
|------|------|-----|---------|
| uri  | string | 否   | 相册的uri。 |
| albumName  | string | 否   | 相册的名称。 |

## 示例

```ts
// xxx.ets
import { AlbumPickerComponent, AlbumPickerOptions, AlbumInfo, PickerColorMode, photoAccessHelper } from '@kit.MediaLibraryKit';
import { EmptyAreaClickCallbck } from '@ohos.file.AlbumPickerComponent';

@Entry
@Component
struct PickerDemo {
  albumPickerOptions: AlbumPickerOptions = new AlbumPickerOptions();
  private emptyAreaClickCallback: EmptyAreaClickCallbck = (): void => this.onEmptyAreaClick();

  aboutToAppear() {
    this.albumPickerOptions.themeColorMode = PickerColorMode.AUTO;
    this.albumPickerOptions.filterType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE;
  }
  
  private onAlbumClick(albumInfo: AlbumInfo): boolean {
    if (albumInfo?.uri) {
      // 通过pickerController向PhotoPickerComponent发送消息，通知其刷新
    }
    if (albumInfo?.albumName) {
      // 基于获取到的albumName后续逻辑处理
    }
    return true;
  }
  
  private onEmptyAreaClick(): void {
    // 点击组件空白区域回调
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
