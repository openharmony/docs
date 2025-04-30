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
  SelectMode, PickerColorMode, ReminderMode, MaxCountType, PhotoBrowserRange, PhotoBrowserUIElement,
  ItemsDeletedCallback, ExceedMaxSelectedCallback, CurrentAlbumDeletedCallback
} from '@ohos.file.PhotoPickerComponent';
```

## 属性

支持[通用属性](../apis-arkui/arkui-ts/ts-component-general-attributes.md)。

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
  onSelectedItemsDeleted?: ItemsDeletedCallback,
  onExceedMaxSelected?: ExceedMaxSelectedCallback,
  onCurrentAlbumDeleted?: CurrentAlbumDeletedCallback,
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

| 名称                      | 类型                                                                               | 必填  | 装饰器说明      | 参数描述                                                                                                                                                                                                                                                                                                                                                            |
|-------------------------|----------------------------------------------------------------------------------|-----|------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| pickerOptions           | [PickerOptions](#pickeroptions)                                                  | 否   | - | picker参数信息。                                                                                                                                                                                                                                                                                                                                                     |
| onSelect                | (uri: string) => void                                                            | 否   | - | 用户在Picker组件中勾选图片时产生的回调事件，将图片uri报给应用。                                                                                                                                                                                                                                                                                                                            |
| onDeselect              | (uri: string) => void                                                            | 否   | - | 用户在Picker组件中取消勾选图片时产生的回调事件，同时也会将图片uri报给应用。                                                                                                                                                                                                                                                                                                                      |
| onItemClicked           | (itemInfo: [ItemInfo](#iteminfo), clickType: [ClickType](#clicktype)) => boolean | 否   | - | 用户在picker组件中点击item产生的回调事件。<br>点击图片（缩略图item）时，返回值为true则勾选此图片，否则不响应勾选，uri不授权；点击相机item，返回值为true则拉起系统相机，否则不拉起相机，由应用自行处理。                                                                                                                                                                                                                                            |
| onEnterPhotoBrowser     | (photoBrowserInfo: [PhotoBrowserInfo](#photobrowserinfo)) => boolean             | 否   | - | 点击进入大图时产生的回调事件，将大图相关信息报给应用。                                                                                                                                                                                                                                                                                                                                     |
| onExitPhotoBrowser      | (photoBrowserInfo: [PhotoBrowserInfo](#photobrowserinfo)) => boolean             | 否   | - | 退出大图时产生的回调事件，将大图相关信息报给应用。                                                                                                                                                                                                                                                                                                                                       |
| onPickerControllerReady | () => void                                                                       | 否   | - | 当pickerController可用时产生的回调事件。<br>调用PickerController相关接口需在该回调后才能生效。                                                                                                                                                                                                                                                                                               |
| onPhotoBrowserChanged   | (browserItemInfo: [BaseItemInfo](#baseiteminfo)) => boolean                      | 否   | - | 大图左右滑动时产生的回调事件，将大图相关信息报给应用。                                                                                                                                                                                                                                                                                                                                     |
| onSelectedItemsDeleted<sup>13+</sup>  | [ItemsDeletedCallback](#itemsdeletedcallback13)                                  | 否   | - | 已勾选的图片被删除时产生的回调，并将被删除图片的相关信息回调给应用。                                                                                                                                                                                                                                                                                                                              |
| onExceedMaxSelected<sup>13+</sup>     | [ExceedMaxSelectedCallback](#exceedmaxselectedcallback13)                          | 否   | - | 选择达到最大选择数量（最大图片选择数量或者是最大视频选择数量亦或是总的最大选择数量）之后再次点击勾选时产生的回调。<br>- 若选择的数量达到了最大图片选择数量且未达到总的最大选择数量则回调的参数exceedMaxCountType为[MaxCountType](#maxcounttype).PHOTO_MAX_COUNT。<br>- 若选择的数量达到了最大视频选择数量且未达到总的最大选择数量则回调的参数exceedMaxCountType为[MaxCountType](#maxcounttype).VIDEO_MAX_COUNT。<br>- 只要选择的数量达到了总的最大选择数量则回调的参数exceedMaxCountType为[MaxCountType](#maxcounttype).TOTAL_MAX_COUNT。 |
| onCurrentAlbumDeleted<sup>13+</sup>   | [CurrentAlbumDeletedCallback](#currentalbumdeletedcallback13)                    | 否   | - | 当前相册被删除时产生的回调。<br>当前相册是指通过pickerController.[setData](#setdata)([DataType](#datatype).SET_ALBUM_URI, currentAlbumUri)接口设置给宫格组件的相册，即“currentAlbumUri”。<br>当前相册被删除后若使用方刷新自己的相册标题栏，使用方可以设置自己的标题栏名称为默认的相册名例如“图片和视频”、“图片”或“视频”，然后通过pickerController.[setData](#setdata)([DataType](#datatype).SET_ALBUM_URI, '')接口传空串去刷新宫格页为默认相册。                                  |
| onVideoPlayStateChanged<sup>14+</sup>   | [videoPlayStateChangedCallback](#videoplaystatechangedcallback14)                    | 否   | - | 大图页视频播放状态改变时回调。                                  |
| pickerController        | [PickerController](#pickercontroller)                                            | 否   | @ObjectLink | 应用可通过PickerController向Picker组件发送数据。                                                                                                                                                                                                                                                                                                                             |

## PickerOptions

继承自[BaseSelectOptions](js-apis-photoAccessHelper.md#baseselectoptions12)。

Picker配置选项。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                              | 类型                                      | 必填  | 说明                                                                       |
|---------------------------------|-----------------------------------------|-----|--------------------------------------------------------------------------|
| checkBoxColor                   | string                                  | 否   | 勾选框的背景色。格式为8位十六进制颜色代码。                                                   |
| backgroundColor                 | string                                  | 否   | picker宫格页面背景色。格式为8位十六进制颜色代码。                                             |
| isRepeatSelectSupported         | boolean                                 | 否   | 是否支持单张图片重复选择。true表示支持。默认不支持。                                                   |
| checkboxTextColor               | string                                  | 否   | 勾选框内文本颜色。格式为8位十六进制颜色代码。 （该能力暂不支持）                                        |
| photoBrowserBackgroundColorMode | [PickerColorMode](#pickercolormode)     | 否   | 大图背景颜色。包括跟随系统、浅色模式以及深色模式，默认为跟随系统。                                        |
| maxSelectedReminderMode         | [ReminderMode](#remindermode)           | 否   | 选择数量达到最大时的提示方式。包括弹toast提示、不提示以及蒙层提示，默认为弹toast提示。                         |
| orientation                     | [PickerOrientation](#pickerorientation) | 否   | 宫格页面滑动预览方向，包括水平和竖直两个方向，默认为竖直方向。（该能力暂不支持）                                 |
| selectMode                      | [SelectMode](#selectmode)               | 否   | 选择模式。包括多选和单选，默认为多选。                                                      |
| maxPhotoSelectNumber            | number                                  | 否   | 图片最大的选择数量。最大值为500，受到最大选择总数的限制。默认为500。                                           |
| maxVideoSelectNumber            | number                                  | 否   | 视频最大的选择数量。最大值为500，受到最大选择总数的限制。默认为500。                                           |
| isSlidingSelectionSupported<sup>13+</sup>     | boolean                                 | 否   | 是否支持滑动多选，true表示支持。默认不支持。重复选择场景不支持滑动多选。                                            |
| photoBrowserCheckboxPosition<sup>13+</sup>    | [number, number]                        | 否   | 设置大图页checkbox的位置。第一个参数为X方向偏移量，第二个参数为Y方向偏移量。传参范围0-1，代表距离组件左上角0%-100%的偏移量。默认值为[0, 0]。 |
| gridMargin<sup>14+</sup>        | [Margin](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#margin)                        | 否   | 设置组件宫格页margin。 |
| photoBrowserMargin<sup>14+</sup>    | [Margin](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#margin)                        | 否   | 设置组件大图页margin |

## ItemsDeletedCallback<sup>13+</sup>

type ItemsDeletedCallback = (baseItemInfos: Array&lt;BaseItemInfo&gt;) => void

已勾选的图片被删除时产生的回调事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名 | 类型                                         | 必填 | 说明       |
| -------- |--------------------------------------------| -------- |----------|
| baseItemInfos | Array&lt;[BaseItemInfo](#baseiteminfo)&gt; | 是 | 照片的基本信息。 |

## ExceedMaxSelectedCallback<sup>13+</sup>

type ExceedMaxSelectedCallback = (exceedMaxCountType: MaxCountType) => void

选择达到最大选择数量之后再次点击勾选时的回调事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明                                           |
| -------- |-------------------------------| -------- |----------------------------------------------|
| exceedMaxCountType | [MaxCountType](#maxcounttype) | 是 | 达到最大选择数量的类型。类型包含图片最大选择数量、视频最大选择数量以及总的最大选择数量。 |

## CurrentAlbumDeletedCallback<sup>13+</sup>

type CurrentAlbumDeletedCallback = () => void

当前相册被删除时的回调事件。

**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

## videoPlayStateChangedCallback<sup>14+</sup>

type videoPlayStateChangedCallback = (state: VideoPlayerState) => void

大图页视频播放状态改变时回调。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

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

### exitPhotoBrowser<sup>13+</sup>

exitPhotoBrowser(): void

应用可通过该接口，向picker发送退出大图的通知。

**原子化服务API**：从API version 13开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

### setPhotoBrowserUIElementVisibility<sup>13+</sup>

setPhotoBrowserUIElementVisibility(elements: Array&lt;PhotoBrowserUIElement&gt;, isVisible: boolean): void

应用可通过该接口，设置大图页大图预览组件外其他UI元素是否可见。不设置则默认可见。

**原子化服务API**：从API version 13开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名         | 类型                                                             | 必填  | 说明                |
|-------------|----------------------------------------------------------------| ----- |-------------------|
| elements    | Array&lt;[PhotoBrowserUIElement](#photobrowseruielement13)&gt; | 是 | 大图页大图预览组件外其他UI元素。 |
| isVisible | boolean                                                        | 是 | 是否可见。true表示可见，默认为false。             |

### replacePhotoPickerPreview<sup>15+</sup>

replacePhotoPickerPreview(originalUri: string, newUri: string, callback: AsyncCallback&lt;void&gt;): void

应用可通过该接口，将photoPicker中用户勾选的图片替换为应用后期编辑修改后的图片。

**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名         | 类型                     |     必填     | 说明                |
|-------------|----------------------------| -------------- |-------------------|
| originalUri     | string  | 是 | 原uri，将会被替换掉的uri。 |
| newUri  | boolean   | 是 | 新uri，即替换后的uri。基于originalUri修改后期望在photoPicker上替换originalUri显示的，暂存在应用沙箱的图片/视频uri。      |
| callback   | AsyncCallback&lt;void&gt;   | 是 | 调用接口完成替换后的回调。      |

### saveTrustedPhotoAssets<sup>15+</sup>

saveTrustedPhotoAssets(trustedUris: Array&lt;string&gt;, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;, configs?: Array&lt;photoAccessHelper.PhotoCreationConfig&gt;, saveMode?: SaveMode): void

应用可通过该接口，保存对应uri列表的文件。使用时，一般结合[replacePhotoPickerPreview](#replacephotopickerpreview15)接口使用，将替换显示成功后的应用沙箱图片/视频newUris保存到图库。

**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名         | 类型                                                             | 必填  | 说明                |
|-------------|----------------------------------------------------------------| ----- |-------------------|
| trustedUris     | Array&lt;string&gt; | 是 | 需要保存到图库的应用沙箱图片/视频uri。trustedUris一般来自[replacePhotoPickerPreview](#replacephotopickerpreview15)替换显示成功的newUri。 |
| callback  | AsyncCallback&lt;Array&lt;string&gt;&gt;          | 是 | 返回保存后新生成的媒体库文件对应的uri。             |
| configs | Array&lt;[photoAccessHelper.PhotoCreationConfig](js-apis-photoAccessHelper.md#photocreationconfig12)&gt;          | 否 | 需要保存的文件对应的配置参数。             |
| saveMode | [SaveMode](#savemode15)           | 否 | 图片保存模式。             |

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
| SET_ALBUM_URI | 2   | 发送已选择相册，通知picker组件刷新相册，需要传入string类型。<br>例如：应用在自己的页面中选择相册后，需要把已选择的相册uri通过setData接口通知到picker组件，从而触发picker组件刷新新相册数据。 |

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

## PhotoBrowserUIElement<sup>13+</sup>

大图页大图预览组件外其他UI元素。

**原子化服务API**：从API version 13开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称          | 值   | 说明       |
|-------------|-----|----------|
| CHECKBOX    | 0   | 大图页勾选框。  |
| BACK_BUTTON | 1   | 大图页返回按钮。 |

## SaveMode<sup>15+</sup>

图片/视频保存模式。

**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称          | 值   | 说明       |
|-------------|-----|----------|
| SAVE_AS     | 0   | 另存为新的图片/视频。  |
| OVERWRITE  | 1   | 覆盖原有图片/视频，覆盖后支持在图库中将保存内容回退，还原成原始图片/视频。 |

## VideoPlayerState<sup>14+</sup>

视频播放状态。

**原子化服务API**：从API version 14开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                | 值   | 说明                        |
|-------------------|-----|---------------------------|
| PLAYING | 0   | 视频播放中。                 |
| PAUSED | 1   | 视频播放暂停。 |
| STOPPED | 2   | 视频播放停止。 |
| SEEK_START | 3   | 开始拖拽进度条。 |
| SEEK_FINSH | 4   | 结束拖拽进度条。 |

## 示例

```ts
// xxx.ets
import {
  PhotoPickerComponent,
  PickerController,
  PickerOptions,
  DataType,
  BaseItemInfo,
  ItemInfo,
  PhotoBrowserInfo,
  AnimatorParams,
  MaxSelected,
  ItemType,
  ClickType,
  PickerOrientation,
  SelectMode,
  PickerColorMode,
  ReminderMode,
  MaxCountType,
  PhotoBrowserRange,
  PhotoBrowserUIElement,
  ItemsDeletedCallback,
  ExceedMaxSelectedCallback,
  CurrentAlbumDeletedCallback,
  videoPlayStateChangedCallback,
  VideoPlayerState
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
  private selectedItemsDeletedCallback: ItemsDeletedCallback =
    (baseItemInfos: Array<BaseItemInfo>) => this.onSelectedItemsDeleted(baseItemInfos);
  private exceedMaxSelectedCallback: ExceedMaxSelectedCallback =
    (exceedMaxCountType: MaxCountType) => this.onExceedMaxSelected(exceedMaxCountType);
  private currentAlbumDeletedCallback: CurrentAlbumDeletedCallback = () => this.onCurrentAlbumDeleted();
  private videoPlayStateChangedCallback: videoPlayStateChangedCallback =
    (state: VideoPlayerState) => this.videoPlayStateChanged(state);

  aboutToAppear() {
    this.pickerOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE;
    this.pickerOptions.maxSelectNumber = 5;
    this.pickerOptions.isSearchSupported = false;
    this.pickerOptions.isPhotoTakingSupported = false;
    this.pickerOptions.photoBrowserCheckboxPosition = [0.5, 0.5];
    // 其他属性.....
  }

  private onSelect(uri: string): void {
    // 添加。
    if (uri) {
      this.selectUris.push(uri);
    }
  }

  private onDeselect(uri: string): void {
    // 移除。
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
      // 点击相机item。
      return true; // 返回true则拉起系统相机，若应用需要自行处理则返回false。
    } else {
      if (clickType === ClickType.SELECTED) {
        // 应用做自己的业务处理。
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
    // 进入大图的回调。
    this.isBrowserShow = true;
    return true;
  }

  private onExitPhotoBrowser(photoBrowserInfo: PhotoBrowserInfo): boolean {
    // 退出大图的回调。
    this.isBrowserShow = false;
    return true;
  }

  private onPickerControllerReady(): void {
    // 接收到该回调后，便可通过pickerController相关接口向picker发送数据，在此之前不生效。
    let elements: number[] = [PhotoBrowserUIElement.BACK_BUTTON];
    this.pickerController.setPhotoBrowserUIElementVisibility(elements, false); // 设置大图页不显示返回按钮。
  }

  private onPhotoBrowserChanged(browserItemInfo: BaseItemInfo): boolean {
    // 大图左右滑动的回调。
    this.currentUri = browserItemInfo.uri ?? '';
    return true;
  }

  private onSelectedItemsDeleted(baseItemInfos: Array<BaseItemInfo>): void {
    // 已勾选图片被删除时的回调。
  }

  private onExceedMaxSelected(exceedMaxCountType: MaxCountType): void {
    // 超过最大选择数量再次点击时的回调。
  }

  private onCurrentAlbumDeleted(): void {
    // 当前相册被删除时的回调。
  }

  private videoPlayStateChanged(state: VideoPlayerState): void {
    // 当视频播放状态变化时回调。
  }
  build() {
    Flex({
      direction: FlexDirection.Column,
      justifyContent: FlexAlign.Center,
      alignItems: ItemAlign.Center
    }) {
      Column() {
        if (this.isBrowserShow) {
          // 这里模拟应用自己的大图返回按钮。
          Row() {
            Button("退出大图").width('33%').height('8%').onClick(() => {
              this.pickerController.exitPhotoBrowser();
            })
          }.margin({ bottom: 20 })
        }

        PhotoPickerComponent({
          pickerOptions: this.pickerOptions,
          // onSelect: (uri: string): void => this.onSelect(uri),
          // onDeselect: (uri: string): void => this.onDeselect(uri),
          onItemClicked: (itemInfo: ItemInfo, clickType: ClickType): boolean => this.onItemClicked(itemInfo,
            clickType), // 该接口可替代上面两个接口。
          onEnterPhotoBrowser: (photoBrowserInfo: PhotoBrowserInfo): boolean => this.onEnterPhotoBrowser(photoBrowserInfo),
          onExitPhotoBrowser: (photoBrowserInfo: PhotoBrowserInfo): boolean => this.onExitPhotoBrowser(photoBrowserInfo),
          onPickerControllerReady: (): void => this.onPickerControllerReady(),
          onPhotoBrowserChanged: (browserItemInfo: BaseItemInfo): boolean => this.onPhotoBrowserChanged(browserItemInfo),
          onSelectedItemsDeleted: this.selectedItemsDeletedCallback,
          onExceedMaxSelected: this.exceedMaxSelectedCallback,
          onCurrentAlbumDeleted: this.currentAlbumDeletedCallback,
          onVideoPlayStateChanged: this.videoPlayStateChangedCallback,
          pickerController: this.pickerController,
        }).height('60%').width('100%')

        // 这里模拟应用侧底部的选择栏。
        if (this.isBrowserShow) {
          Row() {
            ForEach(this.selectUris, (uri: string) => {
              if (uri === this.currentUri) {
                Image(uri)
                  .height('10%')
                  .width('10%')
                  .onClick(() => {
                  })
                  .borderWidth(1)
                  .borderColor('red')
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
}
```
