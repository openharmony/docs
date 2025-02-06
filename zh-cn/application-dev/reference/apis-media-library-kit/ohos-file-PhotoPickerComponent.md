# @ohos.file.PhotoPickerComponent (PhotoPicker组件)

应用可以在布局中嵌入PhotoPicker组件，通过此组件，应用无需申请权限，即可访问公共目录中的图片或视频文件。仅包含读权限。
应用嵌入组件后，用户可直接在PhotoPicker组件中选择图片或视频文件。

> **说明：**
>
> 该组件从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

```ts
import {
  PhotoPickerComponent, PickerController, PickerOptions,
  DataType, BaseItemInfo, ItemInfo, PhotoBrowserInfo, AnimatorParams,
  MaxSelected, ItemType, ClickType, PickerOrientation,
  SelectMode, PickerColorMode, ReminderMode, MaxCountType, PhotoBrowserRange
} from '@ohos.file.PhotoPickerComponent';
```

## 属性

支持[通用属性](../apis-arkui/arkui-ts/ts-universal-attributes-size.md)。

## PhotoPickerComponent

PhotoPickerComponent({
  pickerOptions?: PickerOptions,
  onSelect?: (uri: string) => void,
  onDeselect?: (uri: string) => void,
  onItemClicked?: (itemInfo: ItemInfo, clickType: ClickType) => boolean,
  onEnterPhotoBrowser?: (photoBrowserInfo: PhotoBrowserInfo) => boolean,
  onExitPhotoBrowser?: (photoBrowserInfo: PhotoBrowserInfo) => boolean,
  onPickerControllerReady?: () => void,
  onPhotoBrowserChanged?: (browserItemInfo: BaseItemInfo) => boolean,
  pickerController: PickerController
})

应用可以在布局中嵌入PhotoPickerComponent组件，通过此组件，应用无需申请权限，即可访问公共目录中的图片或视频文件。

> **说明：**
> 如果当前PhotoPickerComponent组件嵌套在Tabs组件中使用，Tabs组件的左右滑动会与图片选择大图界面的左右滑动切换手势发生冲突。
>
> 可在进退大图的回调中设置Tabs组件是否支持滑动来规避，该问题将在后续版本修复。

**装饰器类型**：@Component

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 名称          | 类型            | 必填  | 装饰器说明      | 参数描述       |
|---------------|----------------|-----|------------|--------------------------|
| pickerOptions  | [PickerOptions](#pickeroptions)       | 否   | - | picker参数信息。  |
| onSelect       | (uri: string) => void                 | 否   | - | 用户在Picker组件中勾选图片时产生的回调事件，将图片uri报给应用。             |
| onDeselect     | (uri: string) => void                 | 否   | - | 用户在Picker组件中取消勾选图片时产生的回调事件，同时也会将图片uri报给应用。  |
| onItemClicked  | (itemInfo: [ItemInfo](#iteminfo), clickType: [ClickType](#clicktype)) => boolean  | 否   | - | 用户在picker组件中点击item产生的回调事件。<br>点击图片（缩略图item）时，返回值为true则勾选此图片，否则不响应勾选，uri不授权；点击相机item，返回值为true则拉起系统相机，否则不拉起相机，由应用自行处理。 |
| onEnterPhotoBrowser | (photoBrowserInfo: [PhotoBrowserInfo](#photobrowserinfo)) => boolean   | 否   | - | 点击进入大图时产生的回调事件，将大图相关信息报给应用。   |
| onExitPhotoBrowser | (photoBrowserInfo: [PhotoBrowserInfo](#photobrowserinfo)) => boolean   | 否   | - | 退出大图时产生的回调事件，将大图相关信息报给应用。           |
| onPickerControllerReady | () => void   | 否   | - | 当pickerController可用时产生的回调事件。<br>调用PickerController相关接口需在该回调后才能生效。          |
| onPhotoBrowserChanged | (browserItemInfo: [BaseItemInfo](#baseiteminfo)) => boolean   | 否   | - | 大图左右滑动时产生的回调事件，将大图相关信息报给应用。           |
| pickerController         | [PickerController](#pickercontroller) | 否   | @ObjectLink | 应用可通过PickerController向Picker组件发送数据。               |

## PickerOptions

继承自[BaseSelectOptions](js-apis-photoAccessHelper.md#baseselectoptions12)。

Picker配置选项。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                     | 类型                                      | 必填  | 说明   |
|-------------------------|-----------------------------------------|-----|--------|
| checkBoxColor                 | string                                  | 否   | 勾选框的背景色。格式为8位十六进制颜色代码。                               |
| backgroundColor               | string                                  | 否   | picker宫格页面背景色。格式为8位十六进制颜色代码。                         |
| isRepeatSelectSupported       | boolean                                 | 否   | 是否支持单张图片重复选择。true表示支持。                               |
| checkboxTextColor             | string                                  | 否   | 勾选框内文本颜色。格式为8位十六进制颜色代码。 （该能力暂不支持）                             |
| photoBrowserBackgroundColorMode | [PickerColorMode](#pickercolormode)     | 否   | 大图背景颜色。包括跟随系统、浅色模式以及深色模式，默认为跟随系统。                |
| maxSelectedReminderMode | [ReminderMode](#remindermode)           | 否   | 选择数量达到最大时的提示方式。包括弹toast提示、不提示以及蒙层提示，默认为弹toast提示。 |
| orientation                   | [PickerOrientation](#pickerorientation) | 否   | 宫格页面滑动预览方向，包括水平和竖直两个方向，默认为竖直方向。（该能力暂不支持）                  |
| selectMode                    | [SelectMode](#selectmode)               | 否   | 选择模式。包括多选和单选，默认为多选。                              |
| maxPhotoSelectNumber          | number                                  | 否   | 图片最大的选择数量。最大值为500，受到最大选择总数的限制。                   |
| maxVideoSelectNumber          | number                                  | 否   | 视频最大的选择数量。最大值为500，受到最大选择总数的限制。                   |

## PickerController

应用可通过PickerController向picker组件发送数据。

**装饰器类型**：@Observed

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

### setData

setData(dataType: DataType, data: Object): void

应用可通过该接口向picker组件发送数据，并通过DataType来区分具体发送什么类型的数据。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

|  参数名        | 类型                                    | 必填  | 说明  |
| ------------------------- | ------------------ | ----- | --------------- |
| dataType | [DataType](#datatype) | 是 | 发送数据的数据类型。|
| data | Object | 是 | 发送的数据。 | 

### setMaxSelected

setMaxSelected(maxSelected: MaxSelected): void

应用可通过该接口，实时地设置图片的最大选择数量、视频的最大选择数量以及总的最大选择数量。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

|  参数名        | 类型                                    | 必填  | 说明     |
| ------------------------- | ------------------ | ----- | --------------- |
| maxSelected | [MaxSelected](#maxselected) | 是 | 最大选择数量。|

### setPhotoBrowserItem

setPhotoBrowserItem(uri: string, photoBrowserRange?: PhotoBrowserRange): void

应用可通过该接口,切换picker组件至大图浏览模式浏览图片；当已处于大图浏览模式时，切换浏览的图片。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

|  参数名        | 类型                                    | 必填  | 说明  |
| ------------------------- | ------------------ | ----- | --------------- |
| uri | string | 是 | 指定大图浏览的图片uri。仅支持指定用户已选择的图片，未选择的图片不生效。|
| photoBrowserRange | [PhotoBrowserRange](#photobrowserrange) | 否 | 打开大图浏览模式后，左右滑动切换浏览图片的范围，可配置仅浏览用户选择的或浏览全部图片，视频。默认：PhotoBrowserRange.ALL。浏览全部图片，视频。 | 

## BaseItemInfo

图片、视频相关信息。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称     | 类型    | 必填  | 说明                                                |
|----------|--------|-----|---------------------------------------------------|
| uri      | string                | 否   | 图片、视频的uri（itemType为ThUMBNAIL时支持，否则为空）。            |
| mimeType | string                | 否   | 图片、视频的mimeType（itemType为ThUMBNAIL时支持，否则为空）。       |
| width    | number                | 否   | 图片、视频的宽（单位：像素）（itemType为ThUMBNAIL时支持，否则为空）。       |
| height   | number                | 否   | 图片、视频的高（单位：像素）（itemType为ThUMBNAIL时支持，否则为空）。       |
| size     | number                | 否   | 图片、视频的大小（单位：千字节）（itemType为ThUMBNAIL时支持，否则为空）。     |
| duration   | number                | 否   | 视频的时长（单位：毫秒），图片时返回-1（itemType为ThUMBNAIL时支持，否则为空）。 |

## ItemInfo

继承自[BaseItemInfo]，仅含私有参数itemType

图片、视频相关信息。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称     | 类型    | 必填  | 说明                                                |
|----------|--------|-----|---------------------------------------------------|
| itemType | [ItemType](#itemtype) | 否   | 被点击的item类型。包括缩略图item和相机item。                      |

## PhotoBrowserInfo

大图相关信息。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称     | 类型    | 必填  | 说明     |
|----------|--------|-----|---------|
| animatorParams | [AnimatorParams](#animatorparams) | 否   | 进入、退出大图界面时的动效参数。 |

## AnimatorParams

进退大图动效参数。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称     | 类型    | 必填  | 说明           |
|----------|--------|-----|--------------|
| duration | number  | 否            | 动效时长（单位：毫秒）。 |
| curve      | [Curve](../apis-arkui/js-apis-curve.md#curve) &verbar; [ICurve](../apis-arkui/js-apis-curve.md#icurve9) &verbar; string | 否   | 动效曲线。        |

## MaxSelected

最大选择数量。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称     | 类型    | 必填  | 说明     |
|----------|--------|-----|---------|
| data | Map&lt;[MaxCountType](#maxcounttype), number&gt; | 否             | 最大选择数量（包含图片的最大选择数量、视频的最大选择数量以及总的最大选择数量） |

## DataType

枚举，PickerController向picker组件发送数据的数据类型。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                | 值   | 说明                                                                                                                 |
|-------------------|-----|--------------------------------------------------------------------------------------------------------------------|
| SET_SELECTED_URIS | 1   | 发送已选择的数据列表，通知picker组件勾选状态刷新，需要传入string数组类型。<br>例如：应用在自己的页面中删除某张图片后，需要把剩下的已选择的数据列表通过setData接口通知到picker组件，从而触发picker组件勾选框状态刷新正确。 |
| SET_ALBUM_URI | 2   | 应用按需设置图片的最大选择数量、视频的最大选择数量以及总的最大选择数量。 |

## ItemType

被点击item的类型。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                | 值   | 说明         |
|-------------------|-----|------------|
| THUMBNAIL | 0   | 图片、视频item（缩略图item）。 |
| CAMERA | 1   | 相机item。    |

## ClickType

点击操作的类型。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                | 值   | 说明                     |
|-------------------|-----|------------------------|
| SELECTED | 0   | 选择操作（勾选图片或者点击相机item）。 |
| DESELECTED | 1   | 取消选择操作（取消勾选图片）。       |

## PickerOrientation

Picker宫格页面滑动预览的方向。（该能力暂不支持）

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                | 值   | 说明    |
|-------------------|-----|-------|
| VERTICAL | 0   | 竖直方向。 |
| HORIZONTAL | 1   | 水平方向。 |

## SelectMode

选择模式。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                | 值   | 说明    |
|-------------------|-----|-------|
| SINGLE_SELECT | 0   | 单选模式。 |
| MULTI_SELECT | 1   | 多选模式。 |

## PickerColorMode

Picker的颜色模式。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core。

| 名称                | 值   | 说明    |
|-------------------|-----|-------|
| AUTO | 0   | 跟随系统。 |
| LIGHT | 1   | 浅色模式。 |
| DARK | 2   | 深色模式。 |

## ReminderMode

最大选择数量提示方式。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                | 值   | 说明        |
|-------------------|-----|-----------|
| NONE | 0   | 不提示。      |
| TOAST | 1   | 弹toast提示。 |
| MASK | 2   | 蒙灰提示。     |

## MaxCountType

最大选择数量的类型。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                | 值   | 说明                        |
|-------------------|-----|---------------------------|
| TOTAL_MAX_COUNT | 0   | 总的最大选择数量。                 |
| PHOTO_MAX_COUNT | 1   | 图片的最大选择数量（不能大于总的最大选择数量）。 |
| VIDEO_MAX_COUNT | 2   | 视频的最大选择数量（不能大于总的最大选择数量）。 |

## PhotoBrowserRange

打开大图浏览模式后，左右滑动切换浏览图片的范围。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                | 值   | 说明                        |
|-------------------|-----|---------------------------|
| ALL | 0   | 全部图片，视频。                 |
| SELECTED_ONLY | 1   | 仅用户已选择的图片，视频。 |

## 示例

```ts
// xxx.ets
import {
  PhotoPickerComponent, PickerController, PickerOptions,
  DataType, BaseItemInfo, ItemInfo, PhotoBrowserInfo, AnimatorParams,
  MaxSelected, ItemType, ClickType, PickerOrientation,
  SelectMode, PickerColorMode, ReminderMode, MaxCountType, PhotoBrowserRange
} from '@ohos.file.PhotoPickerComponent';
import photoAccessHelper from '@ohos.file.photoAccessHelper';

@Entry
@Component
struct PickerDemo {
  pickerOptions: PickerOptions = new PickerOptions();
  @State pickerController: PickerController = new PickerController();
  @State selectUris: Array<string> = new Array<string>();
  @State currentUri: string = '';
  @State isBrowserShow: boolean = false;

  aboutToAppear() {
    this.pickerOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE;
    this.pickerOptions.maxSelectNumber = 5;
    this.pickerOptions.isSearchSupported = false;
    this.pickerOptions.isPhotoTakingSupported = false;
    // 其他属性.....
  }
  
  private onSelect(uri: string): void {
    // 添加
    if (uri) {
      this.selectUris.push(uri);
    }
  }

  private onDeselect(uri: string): void {
    // 移除
    if (uri) {
      this.selectUris = this.selectUris.filter((item: string) => {
        return item != uri;
      })
    }
  }
  
  private onItemClicked(itemInfo: ItemInfo, clickType: ClickType): boolean {
    if (!itemInfo) {
       return false;
    }
    let type: ItemType | undefined = itemInfo.itemType;
    let uri: string | undefined = itemInfo.uri;
    if (type === ItemType.CAMERA) {
      // 点击相机item
      return true; // 返回true则拉起系统相机，若应用需要自行处理则返回false。
    } else {
      if (clickType === ClickType.SELECTED) {
        // 应用做自己的业务处理
        if (uri) {
          this.selectUris.push(uri);
          this.pickerOptions.preselectedUris = [...this.selectUris];
        }
        return true; // 返回true则勾选，否则则不响应勾选。
      } else {
        if (uri) {
          this.selectUris = this.selectUris.filter((item: string) => {
          return item != uri;
          });
          this.pickerOptions.preselectedUris = [...this.selectUris];
        }
      }
      return true;
    }
  }
  
  private onEnterPhotoBrowser(photoBrowserInfo: PhotoBrowserInfo): boolean {
    // 进入大图的回调
    this.isBrowserShow = true;
    return true;
  }
  
  private onExitPhotoBrowser(photoBrowserInfo: PhotoBrowserInfo): boolean {
    // 退出大图的回调
    this.isBrowserShow = false;
    return true;
  }
  
  private onPickerControllerReady(): void {
    // 接收到该回调后，便可通过pickerController相关接口向picker发送数据，在此之前不生效。
  }

  private onPhotoBrowserChanged(browserItemInfo: BaseItemInfo): boolean {
    // 大图左右滑动的回调
    this.currentUri = browserItemInfo.uri ?? '';
    return true;
  }

  build() {
    Flex({
      direction: FlexDirection.Column,
      justifyContent: FlexAlign.Center,
      alignItems: ItemAlign.Center
    }) {
      PhotoPickerComponent({
        pickerOptions: this.pickerOptions,
        // onSelect: (uri: string): void => this.onSelect(uri),
        // onDeselect: (uri: string): void => this.onDeselect(uri), 
        onItemClicked: (itemInfo: ItemInfo, clickType: ClickType): boolean => this.onItemClicked(itemInfo, clickType), // 该接口可替代上面两个接口
        onEnterPhotoBrowser: (photoBrowserInfo: PhotoBrowserInfo): boolean => this.onEnterPhotoBrowser(photoBrowserInfo),
        onExitPhotoBrowser: (photoBrowserInfo: PhotoBrowserInfo): boolean => this.onExitPhotoBrowser(photoBrowserInfo),
        onPickerControllerReady: (): void => this.onPickerControllerReady(),
        onPhotoBrowserChanged: (browserItemInfo: BaseItemInfo): boolean => this.onPhotoBrowserChanged(browserItemInfo),
        pickerController: this.pickerController,
      }).height('60%').width('100%')


      // 这里模拟应用侧底部的选择栏
      if (this.isBrowserShow) {
        Row() {
          ForEach(this.selectUris, (uri: string) => {
            if (uri === this.currentUri) {
              Image(uri).height('10%').width('10%').onClick(() => {
              }).borderWidth(1).borderColor('red')
            } else {
              Image(uri).height('10%').width('10%').onClick(() => {
                this.pickerController.setData(DataType.SET_SELECTED_URIS, this.selectUris);
                this.pickerController.setPhotoBrowserItem(uri, PhotoBrowserRange.ALL);
              })
            }
          }, (uri: string) => JSON.stringify(uri))
        }
      } else {
        Button('预览').width('33%').height('5%').onClick(() => {
          if (this.selectUris.length > 0) {
            this.pickerController.setPhotoBrowserItem(this.selectUris[0], PhotoBrowserRange.SELECTED_ONLY);
          }
        })
      }
    }
  }
}
```
