# @ohos.file.RecentPhotoComponent (最近图片组件)

应用可以在布局中嵌入最近图片组件，通过此组件，应用无需申请权限，即可指定配置访问公共目录中最近的一个图片或视频文件。授予的权限仅包含只读权限。

> **说明：**
>
> 该组件从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

```ts
import {
  RecentPhotoComponent, RecentPhotoOptions, RecentPhotoCheckResultCallback,
  RecentPhotoClickCallback, PhotoSource, RecentPhotoInfo, RecentPhotoCheckInfoCallback,
} from '@ohos.file.RecentPhotoComponent';
```

## 属性

支持[通用属性](../apis-arkui/arkui-ts/ts-component-general-attributes.md)。

## RecentPhotoComponent

RecentPhotoComponent({
  recentPhotoOptions?: RecentPhotoOptions,
  onRecentPhotoCheckResult?: RecentPhotoCheckResultCallback,
  onRecentPhotoClick: RecentPhotoClickCallback,
  onRecentPhotoCheckInfo?: RecentPhotoCheckInfoCallback,
})

RecentPhotoComponent，是最近图片组件，可用于访问公共目录下的图片/视频文件。通过此组件，应用无需申请媒体访问权限，即可根据配置项，访问公共目录下最新的一个图片或视频文件。

**装饰器类型**：@Component

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 名称                       | 类型                                                                | 必填 | 说明                       |
|--------------------------|-------------------------------------------------------------------|------|----------------------------|
| recentPhotoOptions       | [RecentPhotoOptions](#recentphotooptions)                         | 否  | 最近图片配置参数信息。<br> **原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                |
| onRecentPhotoCheckResult | [RecentPhotoCheckResultCallback](#recentphotocheckresultcallback) | 否  | 最近图片查询结果回调函数。<br> **原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。              |
| onRecentPhotoClick       | [RecentPhotoClickCallback](#recentphotoclickcallback)             | 是  | 选择最近图片回调函数。<br> **原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                |
| onRecentPhotoCheckInfo<sup>13+</sup>   | [RecentPhotoCheckInfoCallback](#recentphotocheckinfocallback13)   | 否  | 最近图片查询结果回调函数，并且返回该照片的相关信息。<br> **原子化服务API**：从API version 13开始，该接口支持在原子化服务中使用。 |

## RecentPhotoOptions

最近图片配置选项。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                                                                                      | 必填  | 说明   |
|-------------------------|-----------------------------------------------------------------------------------------|-------|--------|
| period                  | number                                                                                  | 否    | 配置显示多久时间段内的最近图片，单位为秒。最长可配置时长为1天(86400)。<br/>当值小于等于0、大于86400或者未配置时，默认按最长时间段1天显示最近图片。当配置时间段内无符合的图片或视频时，组件不显示。|
| MIMEType                | [photoAccessHelper.PhotoViewMIMETypes](arkts-apis-photoAccessHelper-e.md#photoviewmimetypes) | 否    | 最近图片控件显示的文件类型，默认为PhotoViewMIMETypes.IMAGE_VIDEO_TYPE。                         |
| photoSource             | [PhotoSource](#photosource)                                                             | 否    | 配置最近图片视频显示内容的来源，比如拍照、截屏等。默认不限制来源。                               |

## RecentPhotoInfo<sup>13+</sup>

最近图片相关信息。

**原子化服务API**：从API version 13开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称         | 类型     | 必填  | 说明                                                        |
|------------|--------|-------|-----------------------------------------------------------|
| dateTaken  | number | 否    | 最近图片/视频的拍摄时间，单位为毫秒。（距1970年一月一日的毫秒数值）。                     |
| identifier | string | 否    | 最近图片/视频的名称hash值，用于辅助应用区分最新图片组件将要显示的图片/视频与之前曾显示过的图片/视频是否为同一个。 |

## RecentPhotoCheckResultCallback

type RecentPhotoCheckResultCallback = (recentPhotoExists: boolean) => void

最近图片查询结果回调事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| recentPhotoExists | boolean | 是 | 查询最近图片是否存在，true为存在，false为不存在，默认为true。 |

## RecentPhotoClickCallback

type RecentPhotoClickCallback = (recentPhotoInfo: BaseItemInfo) => boolean

选择最近图片触发的回调事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| recentPhotoInfo | [BaseItemInfo](ohos-file-PhotoPickerComponent.md#baseiteminfo) | 是 | 最近图片信息。 |

**返回值：** 

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 应用回调中处理最近图片的结果返回。true表示处理完成。 |

## RecentPhotoCheckInfoCallback<sup>13+</sup>

type RecentPhotoCheckInfoCallback = (recentPhotoExists: boolean, info: RecentPhotoInfo) => void

最近图片是否存在查询结果以及最近图片相关信息的回调事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名               | 类型                                    | 必填 | 说明          |
|-------------------|---------------------------------------| -------- |-------------|
| recentPhotoExists | boolean                               | 是 | 查询最近图片是否存在，true为存在，false为不存在，默认为true。 |
| info              | [RecentPhotoInfo](#recentphotoinfo13) | 是 | 最近图片相关信息。   |

## PhotoSource

枚举，图片或者视频数据的来源类型。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                | 值   | 说明                                                                                                                 |
|-------------------|-----|--------------------------------------------------------------------------------------------------------------------|
| ALL | 0   | 所有来源的图片、视频。 |
| CAMERA | 1   | 仅相机拍摄的图片、视频。 |
| SCREENSHOT | 2   | 截屏图片或者录屏视频。 |

## 示例

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
    // 存在符合条件的照片或视频。
    if (recentPhotoExists) {
      console.info('The photo is exist.');
    }
  }

  private onRecentPhotoClick(recentPhotoInfo: BaseItemInfo): boolean {
    // 照片或视频返回。
    if (recentPhotoInfo) {
      console.info('The photo uri is ' + recentPhotoInfo.uri);
      return true;
    }
    return true;
  }

  private onRecentPhotoCheckInfo(recentPhotoExists: boolean, info: RecentPhotoInfo): void {
    // 是否存在符合条件的照片或视频，若存在则可以拿到该照片或视频的相关信息。
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
