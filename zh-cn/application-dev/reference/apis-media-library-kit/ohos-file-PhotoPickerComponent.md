# @ohos.file.PhotoPickerComponent (PhotoPicker组件)
<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xuchangda-->
<!--Designer: @guxinggang-->
<!--Tester: @wangbeibei-->
<!--Adviser: @w_Machine_cc-->

应用可以在布局中嵌入PhotoPicker组件，通过此组件，应用无需申请权限，即可实现媒体文件选择功能。在用户选择媒体文件后，应用即可访问用户选中的图片或视频文件。仅包含读权限。

需要注意的是PhotoPickerComponent不能嵌套使用，且不建议在PhotoPickerComponent上覆盖设置了overlay属性的组件，将导致PhotoPickerComponent无法接受手势事件。

请注意PhotoPickerComponent不支持嵌套，且不应在其上覆盖设置overlay属性或更高层级组件，以免导致手势事件失效。

应用嵌入组件后，用户可直接在PhotoPicker组件中选择图片或视频文件。

> **说明：**
>
> - 该组件从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
> - 该组件不支持[同层渲染](../../../application-dev/web/web-same-layer.md)。

## 导入模块

```ts
// 在API version 23之前的版本中，需要使用 'import { api1, api2, ... } from @ohos.file.PhotoPickerComponent'的导入方式。
import {
  PhotoPickerComponent, PickerController, PickerOptions,
  DataType, BaseItemInfo, ItemInfo, PhotoBrowserInfo, ItemType, ClickType,
  MaxCountType, PhotoBrowserRange, PhotoBrowserUIElement,
  ItemsDeletedCallback, ExceedMaxSelectedCallback, CurrentAlbumDeletedCallback, SingleLineConfig,
  BadgeConfig, PreselectedInfo, SaveMode, BadgeType, VideoPlayerState, ItemDisplayRatio
} from '@kit.MediaLibraryKit';
```

## 属性

支持[通用属性](../apis-arkui/arkui-ts/ts-component-general-attributes.md)。

## PhotoPickerComponent

PhotoPickerComponent({ pickerOptions?: PickerOptions, onSelect?: (uri: string) => void, onDeselect?: (uri: string) => void, onItemClicked?: (itemInfo: ItemInfo, clickType: ClickType) => boolean, onItemClickedNotify?: ItemClickedNotifyCallback, onEnterPhotoBrowser?: (photoBrowserInfo: PhotoBrowserInfo) => boolean, onExitPhotoBrowser?: (photoBrowserInfo: PhotoBrowserInfo) => boolean, onPickerControllerReady?: () => void, onPhotoBrowserChanged?: (browserItemInfo: BaseItemInfo) => boolean, onSelectedItemsDeleted?: ItemsDeletedCallback, onExceedMaxSelected?: ExceedMaxSelectedCallback, onCurrentAlbumDeleted?: CurrentAlbumDeletedCallback, onVideoPlayStateChanged?: videoPlayStateChangedCallback, pickerController: PickerController })

应用可以在布局中嵌入PhotoPickerComponent组件，通过此组件，应用无需申请权限，即可访问公共目录中的图片或视频文件。

> **说明：**
> 如果当前PhotoPickerComponent组件嵌套在Tabs组件中使用，Tabs组件的左右滑动会与图片选择大图界面的左右滑动切换手势发生冲突。
>
> 可在进退大图的回调中设置Tabs组件是否支持滑动来规避，该问题将在后续版本修复。

**装饰器类型**：@Component

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 名称                      | 类型                                                                               | 必填  | 装饰器类型      | 说明                                                                                                                                                                                                                                                                                                                                                            |
|-------------------------|----------------------------------------------------------------------------------|-----|------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| pickerOptions              | [PickerOptions](#pickeroptions)                                                  | 否   | - | picker配置参数信息。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                                     |
| onSelect                | (uri: string) => void                                                            | 否   | - | 用户在Picker组件中勾选图片时产生的回调事件，将图片uri报给应用。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                            |
| onDeselect              | (uri: string) => void                                                            | 否   | - | 用户在Picker组件中取消勾选图片时产生的回调事件，同时也会将图片uri报给应用。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                      |
| onItemClicked           | (itemInfo: [ItemInfo](#iteminfo), clickType: [ClickType](#clicktype)) => boolean | 否   | - | 用户在picker组件中点击宫格产生的回调事件。<br>点击图片（缩略图宫格）时，返回值为true则勾选此图片，否则不响应勾选，URI不授权；点击相机宫格，返回值为true则拉起系统相机，否则不拉起相机，由应用自行处理。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                    |
| onItemClickedNotify<sup>23+</sup> | [ItemClickedNotifyCallback](#itemclickednotifycallback23) | 否   | - | 用户在picker组件中点击宫格产生的回调事件。<br>应用可执行自身是否选中逻辑，需要配合addData方法一同使用，通过SET_ITEM_CLICK_RESULT进行选中或不选中。若未设置选中结果，在2秒或PhotoPicker被关闭时取消授权。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。|
| onPinchGridSwitched<sup>23+</sup>           |  [PinchGridSwitchedCallback](#pinchgridswitchedcallback23)  | 否   | - | 宫格捏合时产生的回调事件。仅在[GridPinchModeType](arkts-apis-photoAccessHelper-e.md#gridpinchmodetype23)配置为FULL_FUNCTION_GRID时被触发。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。   | 
| onEnterPhotoBrowser     | (photoBrowserInfo: [PhotoBrowserInfo](#photobrowserinfo)) => boolean             | 否   | - | 点击进入大图时产生的回调事件，将大图相关信息报给应用。不对返回值做特殊处理。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                     |
| onExitPhotoBrowser      | (photoBrowserInfo: [PhotoBrowserInfo](#photobrowserinfo)) => boolean             | 否   | - | 退出大图时产生的回调事件，将大图相关信息报给应用。不对返回值做特殊处理。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                       |
| onPickerControllerReady | () => void                                                                       | 否   | - | 当pickerController可用时产生的回调事件。<br>调用PickerController相关接口需在该回调后才能生效。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                               |
| onPhotoBrowserChanged   | (browserItemInfo: [BaseItemInfo](#baseiteminfo)) => boolean                      | 否   | - | 大图左右滑动时产生的回调事件，将大图相关信息报给应用。仅在多选模式下生效。不对返回值做特殊处理。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                                     |
| onSelectedItemsDeleted<sup>13+</sup>  | [ItemsDeletedCallback](#itemsdeletedcallback13)                                  | 否   | - | 已勾选的图片被删除时产生的回调，并将被删除图片的相关信息回调给应用。<br>**原子化服务API**：从API version 13开始，该接口支持在原子化服务中使用。                                                                                                                                                                                                                                                                                                                              |
| onExceedMaxSelected<sup>13+</sup>     | [ExceedMaxSelectedCallback](#exceedmaxselectedcallback13)                          | 否   | - | 选择达到最大选择数量（最大图片选择数量或者是最大视频选择数量亦或是总的最大选择数量）之后再次点击勾选时产生的回调。<br>- 若选择的数量达到了最大图片选择数量且未达到总的最大选择数量则回调的参数exceedMaxCountType为[MaxCountType](#maxcounttype).PHOTO_MAX_COUNT。<br>- 若选择的数量达到了最大视频选择数量且未达到总的最大选择数量则回调的参数exceedMaxCountType为[MaxCountType](#maxcounttype).VIDEO_MAX_COUNT。<br>- 只要选择的数量达到了总的最大选择数量则回调的参数exceedMaxCountType为[MaxCountType](#maxcounttype).TOTAL_MAX_COUNT。<br>**原子化服务API**：从API version 13开始，该接口支持在原子化服务中使用。 |
| onCurrentAlbumDeleted<sup>13+</sup>   | [CurrentAlbumDeletedCallback](#currentalbumdeletedcallback13)                    | 否   | - | 当前相册被删除时产生的回调。<br>当前相册是指通过pickerController.[setData](#setdata)([DataType](#datatype).SET_ALBUM_URI, currentAlbumUri)接口设置给宫格组件的相册，即“currentAlbumUri”。<br>当前相册被删除后若使用方刷新自己的相册标题栏，使用方可以设置自己的标题栏名称为默认的相册名例如“图片和视频”、“图片”或“视频”，然后通过pickerController.[setData](#setdata)([DataType](#datatype).SET_ALBUM_URI, '')接口传空串去刷新宫格页为默认相册。<br>**原子化服务API**：从API version 13开始，该接口支持在原子化服务中使用。                                  |
| onVideoPlayStateChanged<sup>14+</sup>   | [videoPlayStateChangedCallback](#videoplaystatechangedcallback14)                    | 否   | - | 大图页视频播放状态改变时回调。<br>**原子化服务API**：从API version 14开始，该接口支持在原子化服务中使用。                                  |
| pickerController        | [PickerController](#pickercontroller)                                            | 是   | @ObjectLink | 应用可通过PickerController向Picker组件发送数据。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。|
| onMovingPhotoBadgeStateChanged<sup>22+</sup> | [MovingPhotoBadgeStateChangedCallback](#movingphotobadgestatechangedcallback22) | 否 | - | 用户在Picker组件中打开/关闭动态效果时产生的回调。将图片uri和动态照片状态报给应用。<br>**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。 |
| onScrollStopAtStart<sup>23+</sup> | [ScrollStopAtStartCallback](#scrollstopatstartcallback23) | 否 | - | 用户在Picker组件滑动停止、处于宫格内容起始位置时的回调。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。 |
| onScrollStopAtEnd<sup>23+</sup> | [ScrollStopAtEndCallback](#scrollstopatendcallback23) | 否 | - | 用户在Picker组件滑动停止、处于宫格内容结束位置时的回调。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。 |
| onPhotoBrowserChangeStart<sup>23+</sup> | [PhotoBrowserChangeStartCallback](#photobrowserchangestartcallback23) | 否 | - | 宫格视图进入到大图视图、大图浏览切换时产生的回调。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。 |
| onError<sup>23+</sup> | [ErrorCallback](#errorcallback23) | 否 | - | 使用PhotoPickerComponent组件发生错误时产生的回调。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。 |
| onPhotoBrowserZoom| [PhotoBrowserZoomCallback](#photobrowserzoomcallback) | 否 | - | PhotoPickerComponent进入大图后，双指放大缩小时的回调。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br>**起始版本：** 26.0.0 |

## PickerOptions

Picker配置选项，继承自[photoAccessHelper.BaseSelectOptions](arkts-apis-photoAccessHelper-class.md#baseselectoptions)。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                              | 类型                                      | 只读 | 可选  | 说明                                                                       |
|---------------------------------|-----------------------------------------|-----|-----|--------------------------------------------------------------------------|
| checkBoxColor                   | string                                  | 否  | 是 | 勾选框的背景色。<br>格式为8位十六进制颜色代码。前2位表示透明度，后6位表示RGB颜色值。<br>示例：'#FFFFFFFF'表示白色不透明背景；'#80FF0000'表示半透明红色背景。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                   |
| backgroundColor                 | string                                  | 否  | 是 | picker宫格页面背景色。格式为8位十六进制颜色代码。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                             |
| isRepeatSelectSupported         | boolean                                 | 否  | 是 | 是否支持单张图片重复选择。true表示支持，false表示不支持。默认值为false。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                   |
| checkboxTextColor               | string                                  | 否  | 是 | 勾选框内文本颜色。格式为8位十六进制颜色代码（该能力从API version 19开始支持，API version 19之前系统默认为白色）。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                        |
| photoBrowserBackgroundColorMode | [PickerColorMode](#pickercolormode)     | 否  | 是 | 大图背景颜色。包括跟随系统、浅色模式以及深色模式，默认为跟随系统。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                        |
| maxSelectedReminderMode         | [ReminderMode](#remindermode)           | 否  | 是 | 选择数量达到最大时的提示方式。包括弹toast提示、不提示以及蒙层提示，默认为弹toast提示。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                         |
| orientation                     | [PickerOrientation](#pickerorientation) | 否  | 是 | 宫格页面滑动预览方向，包括水平和竖直两个方向，默认为竖直方向（该能力从API version 20开始支持，API version 20之前系统默认为竖直方向）。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                 |
| selectMode                      | [SelectMode](#selectmode)               | 否  | 是  | 选择模式。包括多选和单选，默认为多选。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                                      |
| maxPhotoSelectNumber            | number                                  | 否  | 是 | 图片最大的选择数量。最大值为500，受到最大选择总数的限制。默认为500。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                           |
| maxVideoSelectNumber            | number                                  | 否  | 是 | 视频最大的选择数量。最大值为500，受到系统中所有媒体文件最大选择总数的限制。默认为500。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                           |
| isSlidingSelectionSupported<sup>13+</sup>     | boolean                                 | 否  | 是 | 是否支持滑动多选，true表示支持，false表示不支持。默认值为false。重复选择场景不支持滑动多选。<br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。                                            |
| photoBrowserCheckboxPosition<sup>13+</sup>    | [number, number]                        | 否  | 是 | 设置大图页checkbox的位置。第一个参数为X方向偏移量，第二个参数为Y方向偏移量。传参范围[0, 1]，代表距离组件左上角0%-100%的偏移量。默认值为[0, 0]。<br>**原子化服务API：** 从API version 13开始，该接口支持在原子化服务中使用。 |
| gridMargin<sup>14+</sup>        | [Margin](../../reference/apis-arkui/arkui-ts/ts-types.md#margin)                         | 否  | 是 | 设置组件宫格页margin。<br>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。 |
| photoBrowserMargin<sup>14+</sup>    | [Margin](../../reference/apis-arkui/arkui-ts/ts-types.md#margin)                         | 否  | 是 | 设置组件大图页margin。<br>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。 |
| singleLineConfig<sup>20+</sup>             | [SingleLineConfig](#singlelineconfig20)                                                | 否  | 是 | 设置组件宫格页单行显示模式。单行模式下，组件不提供打开大图浏览相关功能。组件不支持大图相关回调，PickerController不支持大图相关的接口，接口调用将无效。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。      |  
| uiComponentColorMode<sup>20+</sup>             | [PickerColorMode](#pickercolormode)                                                | 否  | 是 | Picker的颜色模式。Picker宫格界面除背景色之外其他组件的深浅色风格，包括搜索框、相机入口、安全使用图库提示组件、推荐气泡等组件，一般与backgroundColor配合使用。默认为PickerColorMode.AUTO，跟随系统深浅色切换。<br>该属性一般设置PickerColorMode.LIGHT时不与深颜色的backgroundColor搭配；设置PickerColorMode.DARK时不与浅颜色的backgroundColor搭配，否则会出现组件背景或文字无法看清楚的问题。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。  |
| gridStartOffset<sup>20+</sup>    | number                              | 否  | 是  | 组件宫格缩略图第一行与组件顶部的预留空间。默认值0，单位vp。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| gridEndOffset<sup>20+</sup>    | number                              | 否  | 是 | 组件宫格缩略图最后一行与组件底部的预留空间。默认值0，单位vp。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| pickerIndex<sup>21+</sup>    | number                              | 否  | 是  | 通过设置唯一序号来区分不同的pickerComponent。默认值为-1，-1时不做区分。<br>**原子化服务API：** 从API version 21开始，该接口支持在原子化服务中使用。 |
| preselectedInfos<sup>21+</sup>    | Array&lt;[PreselectedInfo](#preselectedinfo21)&gt;                              | 否   | 是 | 支持在指定pickerIndex的PhotoPickerComponent中回显用户已选择的数据。<br>**原子化服务API：** 从API version 21开始，该接口支持在原子化服务中使用。 |
| badgeConfig<sup>21+</sup>    | [BadgeConfig](#badgeconfig21)                              | 否   | 是 | 支持配置特殊角标显示。Picker目前仅支持一种类型的角标，详见[BadgeType](#badgetype21)。<br>**原子化服务API：** 从API version 21开始，该接口支持在原子化服务中使用。 |
| isSlidingSupported<sup>23+</sup>         | boolean                         | 否   | 是 | 是否屏蔽PhotoPickerComponent的滚动。true表示不屏蔽滚动事件，响应用户滚动。false表示屏蔽滚动事件，不响应用户滚动。<br>默认为true。<br>**注意：**<br>当isSlidingSupported设为false时，宫格缩略图将不响应用户点击查看大图的操作。<br>**模型约束**：此接口仅可在Stage模型下使用。<br>**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。|
| edgeEffect<sup>23+</sup>         | [EdgeEffect](../apis-arkui/arkui-ts/ts-appendix-enums.md#edgeeffect)                         | 否   | 是 | Picker宫格页滑动到边缘处的滑动效果。<br>默认为[EdgeEffect.Spring](../apis-arkui/arkui-ts/ts-appendix-enums.md#edgeeffect)。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。|
| appAlbumFilters<sup>23+</sup>         | Array&lt;string&gt;                         | 否   | 是 | 仅显示与指定bundle name对应的相册内容。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。|
| backgroundOpacity<sup>24+</sup>         | number                        | 否   | 是 | 支持配置picker背景透明度。取值范围为[0, 1]，0表示完全透明，1表示完全不透明。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。|
| contextRecoveryInfo        | [photoAccessHelper.ContextRecoveryInfo](arkts-apis-photoAccessHelper-class.md#contextrecoveryinfo21)                        | 否   | 是 | 用于恢复上次退出时PhotoPicker现场的信息。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br>**起始版本：** 26.0.0 |

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

大图页视频播放状态改变时的回调事件。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明                                           |
| -------- |-------------------------------| -------- |----------------------------------------------|
| state | [VideoPlayerState](#videoplayerstate14) | 是 | 视频播放状态。 |

## MovingPhotoBadgeStateChangedCallback<sup>22+</sup>

type MovingPhotoBadgeStateChangedCallback = (uri: string, state: photoAccessHelper.MovingPhotoBadgeStateType) => void

用户在Picker组件中打开/关闭动态效果时的回调事件。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明 |
| ----- |-------------------------------| ----- |----------------------------------------------|
| uri    | string                         | 是    | 动态照片uri。 |
| state  | [photoAccessHelper.MovingPhotoBadgeStateType](arkts-apis-photoAccessHelper-e.md#movingphotobadgestatetype22) | 是 | 动态照片状态。 |

## ScrollStopAtStartCallback<sup>23+</sup>

type ScrollStopAtStartCallback = () => void

表示用户滑动picker宫格页，当滚动停止并处于宫格内容开始位置时的回调事件类型。

**模型约束**： 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

## ItemClickedNotifyCallback<sup>23+</sup>

type ItemClickedNotifyCallback = (itemInfo: ItemInfo, clickType: ClickType) => void

用户在picker组件中点击宫格产生的回调事件。

**模型约束**： 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明 |
| ----- |-------------------------------| ----- |----------------------------------------------|
| itemInfo    | [ItemInfo](#iteminfo) | 是    | 被点击的宫格类型。包括缩略图宫格和相机宫格。 |
| clickType  | [ClickType](#clicktype) | 是 | 点击操作的类型。 |

**示例：**

```ts
import {
  ClickType,
  DataType,
  ItemInfo,
  PhotoPickerComponent,
  PickerController,
  PickerOptions,
} from '@kit.MediaLibraryKit';
import { ClickResult, ItemClickedNotifyCallback } from '@ohos.file.PhotoPickerComponent';

const DOMAIN = 0x0000;
const TAG: string = 'clickedNotifyDemo';

interface Checks {
    isOnClicked: boolean;
    isOnClickedNotify: boolean;
}

export interface ClickResultEx {
    uri: string,
    isSelected: boolean,
}

@Entry
@Component
struct PickerPage {
@State pickerController: PickerController = new PickerController();
private pickerOptions: PickerOptions = new PickerOptions();
@State currentUri: string = '';
@State currentState: number = 0;
@State clickedUris: Map<string, ClickResultEx> = new Map();
private isOnClicked: boolean = false;
private isOnClickedNotify: boolean = false;

    onClicked: (itemInfo: ItemInfo, clickType: ClickType) => boolean = (itemInfo: ItemInfo, clickType: ClickType) => {
        return true;
    };
    // 当一个宫格被点击时，代码会验证该宫格对应URI是否有效，如无效，则忽略。
    // 然后，会检查 clickedUris 中否已存在该URI的记录。如没有，则创建一条记录并将 isSelected 属性设置为 true。
    // 如果记录存在，则将该记录的 isSelected 属性更新为 true。
    // 数据保存完成后点击“setClickResult”按钮，会调用addData(SET_ITEM_CLICK_RESULT)将对应宫格设置为选中状态。
    onClickedNotify: ItemClickedNotifyCallback = (itemInfo: ItemInfo, clickType: ClickType) => {
        if (!itemInfo.uri) {
            return;
        }

        let clickResult = this.clickedUris.get(itemInfo.uri);
        if (!clickResult) {
            clickResult = {
                uri: itemInfo.uri,
                isSelected: true,
            };
        } else {
            clickResult.isSelected = true;
        }
        this.clickedUris.set(itemInfo.uri, clickResult);
    };

    aboutToAppear(): void {
        let params = this.getUIContext().getRouter().getParams() as Checks;

        this.pickerOptions.isSlidingSelectionSupported = true;
        this.pickerOptions.isSearchSupported = false;
        this.isOnClicked = params.isOnClicked;
        // 从index.ets页面获取参数。
        this.isOnClickedNotify = params.isOnClickedNotify;
        this.pickerOptions.maxPhotoSelectNumber = 500;
    }

    // 从this.clickedUris获取这些URI，后续在调用pickerController.addData()设置宫格item选中时使用。
    getClickedUris(): ClickResult[] {
        let uris: ClickResultEx[] = [];
        this.clickedUris.forEach((uri, index) => {
            uris.push(uri)
        })
        return uris;
    }

    build() {
        Column() {
            Row() {
                // 照片选择器组件调用。
                PhotoPickerComponent({
                    pickerOptions: this.pickerOptions,
                    pickerController: this.pickerController,
                    onItemClicked: this.isOnClicked ? this.onClicked : undefined,
                    onItemClickedNotify: this.isOnClickedNotify ? this.onClickedNotify : undefined,
                    onSelect: (uri: string) => {},
                    onDeselect: (uri: string) => {}
                })
            }.height('50%')

            Row() {
                Column() {
                    Text('Selected assets')
                    ForEach(this.getClickedUris(), (uri: ClickResult) => {
                        Row() {
                            // 能够移除选择或添加选择。
                            Checkbox({ name: "OnClick" })
                                .select(uri.isSelected)
                                .onChange((checked: boolean) => {
                                    let clickResult = this.clickedUris.get(uri.uri);
                                    if (!clickResult) {
                                        clickResult = {
                                            uri: uri.uri,
                                            isSelected: checked
                                        };
                                    } else {
                                        clickResult.isSelected = checked;
                                    }
                                    if (uri.uri !== 'abnormal') {
                                        this.clickedUris.set(uri.uri, clickResult);
                                    }
                                }).margin({ right: 5 })
                            Text(uri.uri.slice(-30)).margin({right: 5}).width(150)
                            // 从 this.clickeduris 中移除选择项。
                            Button('Delete').onClick(() => {
                                this.clickedUris.delete(uri.uri);
                            })
                            // 此处代码为异常场景样例，当传入异常URI时，picker宫格选中不生效。
                            Button('Abnormal').onClick(() => {
                                let clickResult = this.clickedUris.get(uri.uri);
                                if (clickResult) {
                                    let oldClickUri = clickResult.uri;
                                    clickResult.uri = 'abnormal'
                                    this.clickedUris.set(oldClickUri, clickResult)
                                }
                            })
                        }.width('100%')
                    })
                }
            }.height('20%')

            Row() {
                // 发送URI(SET_ITEM_CLICK_RESULT)。
                Button('Set ClickResult')
                    .onClick(() => {
                        this.pickerController.addData(DataType.SET_ITEM_CLICK_RESULT, this.getClickedUris())
                    })
            }.height('10%')
        }
    .height('100%')
            .width('100%')
    }
}
```

## ScrollStopAtEndCallback<sup>23+</sup>

type ScrollStopAtEndCallback = () => void

表示用户滑动picker宫格页，当滚动停止并处于宫格内容结束位置时的回调事件类型。

**模型约束**： 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

## PhotoBrowserChangeStartCallback<sup>23+</sup>

type PhotoBrowserChangeStartCallback = (targetPhotoInfo: BaseItemInfo) => void

宫格视图进入到大图视图、大图浏览切换时产生的回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明 |
| ----- |-------------------------------| ----- |----------------------------------------------|
| targetPhotoInfo  | [BaseItemInfo](#baseiteminfo) | 是 | 照片的基本信息。 |

## PinchGridSwitchedCallback<sup>23+</sup>

type PinchGridSwitchedCallback = (gridLevel: photoAccessHelper.GridLevel) => void

用户在宫格组件内捏合时产生的回调事件。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明 |
| ----- |-------------------------------| ----- |----------------------------------------------|
| gridLevel  | [photoAccessHelper.GridLevel](arkts-apis-photoAccessHelper-e.md#gridlevel23) | 是 | 宫格列数的档位。 |

## ErrorCallback<sup>23+</sup>

type ErrorCallback = (pickerError: PickerError) => void

PhotoPickerComponent产生错误时的回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明 |
| ----- |-------------------------------| ----- |----------------------------------------------|
| pickerError  | [PickerError](#pickererror23) | 是 | 产生的错误的基本信息。 |

## PhotoBrowserZoomCallback 

export type PhotoBrowserZoomCallback = (scale: number) => void

PhotoPickerComponent进入大图后，大图放大缩小时的回调。

**起始版本：** 26.0.0

**原子化服务API：** 从API version 26.0.0开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明 |
| ----- |-------------------------------| ----- |----------------------------------------------|
| scale  | number | 是 | 图片相比原图放大缩小的比例。 |

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

### addData<sup>21+</sup>

addData(dataType: DataType, data: Object): void

应用可通过该接口向picker组件发送增加配置数据。通过[DataType](#datatype)来区分具体发送的数据类型。在API version 23之前，该方法仅支持SET_BADGE_CONFIGS类型。

**原子化服务API**：从API version 21开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

|  参数名        | 类型                                    | 必填  | 说明  |
| ------------------------- | ------------------ | ----- | --------------- |
| dataType | [DataType](#datatype) | 是 | 发送增加配置数据的数据类型。|
| data | Object | 是 | 发送的增加配置数据。 | 

### deleteData<sup>21+</sup>

deleteData(dataType: DataType, data: Object): void

应用可通过该接口向picker组件发送移除配置数据。通过[DataType](#datatype)来区分具体发送的数据类型，该方法仅支持SET_BADGE_CONFIGS类型。

**原子化服务API**：从API version 21开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

|  参数名        | 类型                                    | 必填  | 说明  |
| ------------------------- | ------------------ | ----- | --------------- |
| dataType | [DataType](#datatype) | 是 | 发送移除配置数据的数据类型。|
| data | Object | 是 | 发送的移除配置数据。 | 

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
| isVisible | boolean                                                        | 是 | 设置的elements元素是否可见。true表示可见，false表示不可见。默认值为false。             |

### replacePhotoPickerPreview<sup>15+</sup>

replacePhotoPickerPreview(originalUri: string, newUri: string, callback: AsyncCallback&lt;void&gt;): void

应用可通过该接口，将photoPicker中用户勾选的图片替换为应用后期编辑修改后的图片。

**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名         | 类型                     |     必填     | 说明                |
|-------------|----------------------------| -------------- |-------------------|
| originalUri     | string  | 是 | 原uri，将会被替换掉的uri。 |
| newUri  | string   | 是 | 新uri，即替换后的uri。基于originalUri修改后期望在photoPicker上替换originalUri显示的，暂存在应用沙箱的图片/视频uri。      |
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
| configs | Array&lt;[photoAccessHelper.PhotoCreationConfig](arkts-apis-photoAccessHelper-i.md#photocreationconfig12)&gt;          | 否 | 需要保存的文件对应的配置参数。<br>**注意：**<br>1. 传入subtype选项，配置项不生效，仅支持保存DEFAULT类型图片。<br>默认使用trustedUris对应mediaItem的title、fileNameExtension和photoType值，且subtype固定为DEFAULT。<br>2. 该参数在[SaveMode](#savemode15)为OVERWRITE下不生效。             |
| saveMode | [SaveMode](#savemode15)           | 否 | 图片保存模式。<br>默认使用SAVE_AS模式保存为新图片。             |

### updatePickerOptions<sup>22+</sup>

updatePickerOptions(updateConfig: UpdatablePickerConfigs): Promise\<void>

应用通过该接口，更新PhotoPickerComponent的属性。使用Promise异步回调。

**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名         | 类型                                                             | 必填  | 说明                |
|-------------|----------------------------------------------------------------| ----- |-------------------|
| updateConfig | [UpdatablePickerConfigs](#updatablepickerconfigs22) | 是 | 支持更新的PhotoPickerComponent属性，为[PickerOptions](#pickeroptions)的子集。 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

### saveTrustedPhotoAssetsEx<sup>23+</sup>

saveTrustedPhotoAssetsEx(trustedUris: Array\<string>,settings?: Array\<photoAccessHelper.CreationSetting>, saveMode?: SaveMode): Promise\<Array\<string>>

应用可通过该接口保存对应URI列表中的文件。使用Promise异步回调。

> **说明：**
>
> 此接口通常与[replacePhotoPickerPreview](#replacephotopickerpreview15)接口结合使用，以保存替换显示成功后的应用沙箱图片或视频newUris到图库。

**模型约束**：此接口仅可在Stage模型下使用。

**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数**：

| 参数名        | 类型                                                                                                   | 必填  | 说明                |
|-------------- |-------------------------------------------------------------------------------------------------------| ----- |-------------------|
| trustedUris   | Array&lt;string&gt;                                                                                   | 是 | 需要保存到图库的应用沙箱图片或视频URI。<br>trustedUris一般来自[replacePhotoPickerPreview](#replacephotopickerpreview15)替换显示成功后的应用沙箱图片或视频newUri。 |
| settings       | Array&lt;[photoAccessHelper.CreationSetting](arkts-apis-photoAccessHelper-i.md#creationsetting23)&gt;| 否 | 需要保存的文件对应的配置参数。<br>默认使用trustedUris对应mediaItem的title、fileNameExtension和photoType值。|
| saveMode      | [SaveMode](#savemode15)                                                                               | 否 | 图片或视频的保存模式。<br>默认使用SAVE_AS模式保存为新图片。               |

**返回值**：

| 类型   | 说明                     |
| ------ | ------------------------ |
| Promise\<Array\<string>> | Promise对象，返回保存后新生成的媒体库文件对应的URI。 |

### setMovingPhotoState<sup>23+</sup>

setMovingPhotoState(movingPhotoState: photoAccessHelper.MovingPhotoBadgeStateType): Promise\<void>

应用通过该接口，设置大图浏览下当前动态照片的效果。使用Promise异步回调。

仅在大图浏览下设置生效，不支持设置NOT_MOVING_PHOTO。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名         | 类型                                                             | 必填  | 说明                |
|-------------|----------------------------------------------------------------| ----- |-------------------|
|movingPhotoState|[photoAccessHelper.MovingPhotoBadgeStateType](arkts-apis-photoAccessHelper-e.md#movingphotobadgestatetype22) | 是 | 设置当前大图动态照片的状态。 |

**错误码：**

以下错误码的详细介绍请参见[媒体库错误码](errorcode-medialibrary.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 23800151 | Scene parameters validate failed, possible causes: 1. An invalid enumeration value was passed. Only MOVING_PHOTO_ENABLED and MOVING_PHOTO_DISABLED are supported for configuration | 
| 23800202 | Invalid call context. Possible causes: 1. The API is called outside the photo browsing scenario. 2. The API is called when isMovingPhotoBadgeShown is already set to true.     |   

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

### completed

completed(): Promise\<CompletedResult>

应用可通过该接口，在Picker界面完成选择操作后获取完整现场数据，下一次启动Picker时可以使用该数据恢复现场。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| Promise\<[CompletedResult](#completedresult)> | Promise对象，返回恢复现场的信息。 |

## BaseItemInfo

图片、视频相关信息。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称     | 类型    | 只读 | 可选  | 说明                                                |
|----------|--------|-----|-----|---------------------------------------------------|
| uri      | string                | 否 | 是   | 图片、视频的uri。<br>当[ItemType](#itemtype)为THUMBNAIL时支持，否则为空。<br>**注意：**<br>当资源为连拍照片类型时，仅返回该连拍组的封面资源。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。            |
| mimeType | string                | 否 | 是   | 图片、视频的mimeType。<br>当[ItemType](#itemtype)为THUMBNAIL时支持，否则为空。<br>开发者可以通过mimeType的字符串前缀判断媒体类型：以'image/'开头表示图片，以'video/'开头表示视频。具体判断方式请参考[使用mimeType字段来判断资源类型](../../media/medialibrary/medialibrary-faqs/medialibrary-asset-judgment-faq.md#使用mimetype字段来判断资源类型)。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。       |
| width    | number                | 否 | 是   | 图片、视频的宽（单位：像素）。<br>当[ItemType](#itemtype)为THUMBNAIL时支持，否则为空。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。       |
| height   | number                | 否 | 是   | 图片、视频的高（单位：像素）。<br>当[ItemType](#itemtype)为THUMBNAIL时支持，否则为空。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。       |
| size     | number                | 否 | 是   | 图片、视频的大小（单位：字节）。<br>当[ItemType](#itemtype)为THUMBNAIL时支持，否则为空。<br>**模型约束**：此接口仅可在Stage模型下使用。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。     |
| duration   | number                | 否 | 是   | 视频的持续时间（单位：毫秒）。在API version 23之前，动态照片的duration将返回0；在API version 23及之后，返回动态照片附带视频片段的时长，异常场景返回-1。<br>当[ItemType](#itemtype)为THUMBNAIL时支持，否则为空。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| photoSubType<sup>21+</sup>   | [photoAccessHelper.PhotoSubtype](arkts-apis-photoAccessHelper-e.md#photosubtype12)        | 否 | 是   | 图片类型，包括DEFAULT、MOVING_PHOTO和BURST。<br>非特殊类型图片默认为DEFAULT（0）。<br>**原子化服务API**：从API version 21开始，该接口支持在原子化服务中使用。 |
| dynamicRangeType<sup>21+</sup>   | [photoAccessHelper.DynamicRangeType](arkts-apis-photoAccessHelper-e.md#dynamicrangetype12)                 | 否 | 是   | 媒体文件动态范围模型，包括HDR和SDR。<br>对于movingPhoto专指封面图片的动态范围类型。<br>**原子化服务API**：从API version 21开始，该接口支持在原子化服务中使用。|
| orientation<sup>21+</sup>   | number             | 否 | 是   | 图片/视频方向信息。<br>1.“TOP-left”，图像未旋转。<br>2.“TOP-right”，镜像水平翻转。<br>3.“Bottom-right”，图像旋转180°。<br>4.“Bottom-left”，镜像垂直翻转。<br>5.“Left-top”，先镜像水平翻转，再顺时针旋转270°。<br>6.“Right-top”，顺时针旋转90°。<br>7.“Right-bottom”，先镜像水平翻转，再顺时针旋转90°。<br>8.“Left-bottom”，顺时针旋转270°。<br>携带镜像信息的图片无论旋转与否其宽高属性都与原图保持一致，无镜像信息的图片其宽高属性会更新为旋转后的结果。<br>**原子化服务API**：从API version 21开始，该接口支持在原子化服务中使用。|
| movingPhotoBadgeState<sup>22+</sup> | [photoAccessHelper.MovingPhotoBadgeStateType](arkts-apis-photoAccessHelper-e.md#movingphotobadgestatetype22) | 否 | 是   | 动态照片的状态。<br>当[ItemType](#itemtype)为THUMBNAIL时支持，否则为空。<br>**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。 |
| videoMode<sup>22+</sup> | [photoAccessHelper.VideoMode](arkts-apis-photoAccessHelper-e.md#videomode22) | 否 | 是   | 视频文件的log模式。 <br>**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。|
## ItemInfo

继承自[BaseItemInfo](#baseiteminfo)，增加私有参数itemType。

图片、视频相关信息。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称     | 类型    | 只读 | 可选  | 说明                                                |
|----------|--------|-----|-----|---------------------------------------------------|
| itemType | [ItemType](#itemtype) | 否 | 是   | 被点击的item类型。包括缩略图item和相机item。                      |

## PhotoBrowserInfo

大图相关信息。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称     | 类型    | 只读  | 可选 | 说明     |
|----------|--------|-----|-----|---------|
| animatorParams | [AnimatorParams](#animatorparams) | 否 |  是  | 进入、退出大图界面时的动效参数。 |

## AnimatorParams

进退大图动效参数。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称     | 类型    | 只读 | 可选  | 说明           |
|----------|--------|-----|-----|--------------|
| duration | number  | 否  | 是 | 动效时长（单位：毫秒）。 |
| curve      | [Curve](../apis-arkui/js-apis-curve.md#curve) &verbar; [ICurve](../apis-arkui/js-apis-curve.md#icurve9) &verbar; string | 否   | 是 | 动效曲线。        |

## MaxSelected

最大选择数量。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称     | 类型    | 只读  | 可选 | 说明     |
|----------|--------|-----|-----|---------|
| data | Map&lt;[MaxCountType](#maxcounttype), number&gt; | 否             | 是 | 最大选择数量（包含图片的最大选择数量、视频的最大选择数量以及总的最大选择数量）。 |

## SingleLineConfig<sup>20+</sup>

单行显示模式配置项。单行模式下，组件不提供打开大图浏览相关功能。组件不支持大图相关回调，PickerController不支持大图相关的接口，接口调用将无效。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称 | 类型                                             | 只读 | 可选 | 说明                                                                           |
| ---- | ------------------------------------------------ | ---- | ---- | ------------------------------------------------------------------------------ |
| itemDisplayRatio | [ItemDisplayRatio](#itemdisplayratio20) | 否   | 是 | 宫格显示宽高比，支持1:1，原图宽高比两种模式，默认为宽高比1:1显示。 |
| itemBorderRadius | [Length](../apis-arkui/arkui-ts/ts-types.md#length) &verbar; [BorderRadiuses](../apis-arkui/arkui-ts/ts-types.md#borderradiuses9) &verbar; [LocalizedBorderRadiuses](../apis-arkui/arkui-ts/ts-types.md#localizedborderradiuses12) | 否   | 是 |宫格圆角属性。 |
| itemGap | [Length](../apis-arkui/arkui-ts/ts-types.md#length) | 否   | 是 | 宫格间距。 |

## BadgeConfig<sup>21+</sup>

特殊角标配置项。

**原子化服务API**：从API version 21开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称 | 类型                                             | 只读 | 可选 | 说明                                                                           |
| ---- | ------------------------------------------------ | ---- | ---- | ------------------------------------------------------------------------------ |
| badgeType | [BadgeType](#badgetype21) | 否   | 是 | 特殊角标的类型。 |
| uris | Array&lt;string&gt;  | 否   | 是 | 显示角标的资产uri数据。 |

## ClickResult<sup>23+</sup>

设置指定URI的资产是否被选中。

**模型约束**：此接口仅可在Stage模型下使用。

**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称 | 类型                                             | 只读 | 可选 | 说明      |
| ---- | ------------------------------------------------ | ---- | ---- |---------|
| uri | string | 否   | 否 | 媒体文件资产的URI。 |
| isSelected | boolean  | 否   | 否 | 设置指定的媒体文件资产是否被选中，true表示选中，false表示不选中。  |

## PreselectedInfo<sup>21+</sup>

预选中的文件以及文件对应的PhotoPickerComponent序号。

**原子化服务API**：从API version 21开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称 | 类型                                             | 只读 | 可选 | 说明                                                                           |
| ---- | ------------------------------------------------ | ---- | ---- | ------------------------------------------------------------------------------ |
| uri | string | 否   | 否 |选中媒体文件的uri。 |
| preselectablePickerIndex | number | 否   | 是 | 限制仅在指定序号的PhotoPickerComponent中进行自动选中；默认为-1，即可支持在任意序号的PhotoPickerComponent中自动选中。 |

## UpdatablePickerConfigs<sup>22+</sup>

支持更新的PhotoPickerComponent属性，为[PickerOptions](#pickeroptions)的子集。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                            | 类型                                             | 只读 | 可选 | 说明  |
| ------------------------------- | ----------------------------------------------- | ---- | ---- | ---- |
| mimeType                        | [photoAccessHelper.PhotoViewMIMETypes](arkts-apis-photoAccessHelper-e.md#photoviewmimetypes)            | 否 | 是   | 可选择的媒体文件类型。<br>若无此参数，则默认为图片和视频类型。<br>**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。|
| mimeTypeFilter                  | [photoAccessHelper.MimeTypeFilter](arkts-apis-photoAccessHelper-class.md#mimetypefilter19)  | 否   | 是 | 文件类型的过滤配置，支持指定多个类型过滤。<br>- 当配置mimeTypeFilter参数时，mimeType的配置自动失效。<br>- 当配置该参数时，仅显示配置过滤类型对应的媒体文件，建议提示用户仅支持选择指定类型的图片/视频。<br>**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。 |
| maxSelectNumber                 | number                          | 否   | 是 | 选择媒体文件数量的最大值（单位：个）。<br>最大可设置为500，若不设置则默认为50。<br>**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。 |
| maxPhotoSelectNumber            | number                          | 否  | 是 | 图片最大的选择数量（单位：个）。<br>最大值为500，受到最大选择总数的限制。默认为500。<br>**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。                                     |
| maxVideoSelectNumber            | number                          | 否  | 是 | 视频最大的选择数量（单位：个）。<br>最大值为500，受到系统中所有媒体文件最大选择总数的限制。默认为500。<br>**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。                                      |
| selectMode                      | [SelectMode](#selectmode)       | 否  | 是  | Picker选择模式。<br>包括多选和单选，默认为多选。 <br>**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。                                                    |
| singleSelectionMode             | [photoAccessHelper.SingleSelectionMode](arkts-apis-photoAccessHelper-e.md#singleselectionmode18) | 否   | 是 | 单选模式类型。默认为大图预览模式（SingleSelectionMode.BROWSER_MODE）。<br>**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。 |
| isRepeatSelectSupported         | boolean                         | 否   | 是 | 是否支持单张图片重复选择。<br>true表示支持，false表示不支持。默认为false。<br>**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。 |
| preselectedUris | Array&lt;string&gt;                             | 否   | 是 | 已选择图片的uri数据。<br>**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。 |
| checkBoxColor                   | string                          | 否  | 是 | 勾选框的背景色。<br>格式为8位十六进制颜色代码。 <br>**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。                                                  |
| backgroundColor                 | string                          | 否  | 是 | Picker宫格页面背景色。<br>格式为8位十六进制颜色代码。 <br>**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。                                           |
| checkboxTextColor               | string                          | 否  | 是 | 勾选框内文本颜色。<br>格式为8位十六进制颜色代码。<br>**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。 |
| photoBrowserBackgroundColorMode | [PickerColorMode](#pickercolormode) | 否  | 是 | 大图背景颜色。<br>包括跟随系统、浅色模式以及深色模式，默认为跟随系统。<br>**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。                                      |
| uiComponentColorMode            | [PickerColorMode](#pickercolormode) | 否  | 是 | Picker UI组件的颜色模式。<br>Picker宫格界面除背景色之外其他组件的深浅色风格，包括搜索框、相机入口、安全使用图库提示组件、推荐气泡等组件，一般与backgroundColor配合使用。默认为PickerColorMode.AUTO，跟随系统深浅色切换。<br>该属性设置为PickerColorMode.LIGHT时，一般不与深颜色的backgroundColor搭配；设置为PickerColorMode.DARK时，不与浅颜色的backgroundColor搭配，避免出现组件背景或文字无法看清楚的问题。<br>**原子化服务API**：从API version 22开始，该接口支持在原子化服务中使用。  |
| isSlidingSupported<sup>23+</sup>         | boolean                         | 否   | 是 | 是否屏蔽PhotoPickerComponent的滚动。true表示不屏蔽滚动事件，响应用户滚动。false表示屏蔽滚动事件，不响应用户滚动。<br>默认为true。<br>**模型约束**：此接口仅可在Stage模型下使用。<br>**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。 |
| edgeEffect<sup>23+</sup>         | [EdgeEffect](../apis-arkui/arkui-ts/ts-appendix-enums.md#edgeeffect)                         | 否   | 是 | Picker宫格页滑动到边缘处的滑动效果。<br>默认为[EdgeEffect.Spring](../apis-arkui/arkui-ts/ts-appendix-enums.md#edgeeffect)。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。|
| appAlbumFilters<sup>23+</sup>         | Array&lt;string&gt;                         | 否   | 是 | 仅显示与指定bundle name对应的相册内容。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。|
| autoPlayScenes<sup>23+</sup>      | Array\<[photoAccessHelper.AutoPlayScene](./arkts-apis-photoAccessHelper-class.md#autoplayscene23)\> | 否   | 是 | 设置动态照片播放模式。长度限制为2个，超出取前2个，多余的会自动忽略。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。|
| backgroundOpacity<sup>24+</sup>         | number                        | 否   | 是 | 支持配置picker背景透明度。取值范围为[0, 1]，0表示完全透明，1表示完全不透明。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。|
| gridMargin        | [Margin](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#margin) | 否  | 是 | 设置组件宫格页边距。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。 |
| photoBrowserMargin  | [Margin](../../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#margin) | 否  | 是 | 设置组件大图页边距。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。 |

## PickerError<sup>23+</sup>

使用PhotoPickerComponent组件发生错误时返回的错误的接口名称、错误码和错误描述。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称 | 类型   | 只读 | 可选 | 说明   |
| ---- | ------------------------------------------------ | ---- | ---- | ------ |
| functionName | string | 否   | 否 |产生错误的接口名称。 |
| errorCode | number | 否   | 否 | 错误码。 |
| message | string | 否   | 否 | 接口返回的具体错误描述信息。 |

## CompletedResult

Picker上次退出时现场的信息。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称 | 类型                                             | 只读 | 可选 | 说明      |
| ---- | ------------------------------------------------ | ---- | ---- |---------|
| photoUris | Array&lt;string&gt; | 否   | 否 | 已选择的图片或视频URI。该URI数组仅支持通过临时授权方式调用photoAccessHelper.getAssets使用。 |
| contextRecoveryInfo |  [photoAccessHelper.ContextRecoveryInfo](arkts-apis-photoAccessHelper-class.md#contextrecoveryinfo21)   | 否   | 否 | PhotoPicker退出状态的上下文信息。  |
| movingPhotoBadgeStates | Array&lt;[photoAccessHelper.MovingPhotoBadgeStateType](arkts-apis-photoAccessHelper-e.md#movingphotobadgestatetype22)&gt;  | 否   | 否 | 已选择媒体文件的动态照片状态。当isMovingPhotoBadgeShown为true时，movingPhotoBadgeStates包含动态照片状态；否则为空。 |

## DataType

枚举，PickerController向picker组件发送数据的数据类型。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core
 
| 名称                | 值   | 说明                                                                                                                 |
|-------------------|-----|--------------------------------------------------------------------------------------------------------------------|
| SET_SELECTED_URIS | 1   | 发送已选择的数据列表，通知picker组件勾选状态刷新，需要传入string数组类型。<br>例如：应用在自己的页面中删除某张图片后，需要把剩下的已选择的数据列表通过setData接口通知到picker组件，从而触发picker组件勾选框状态刷新正确。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| SET_ALBUM_URI | 2   | 发送已选择相册，通知picker组件刷新相册，需要传入string类型。<br>例如：应用在自己的页面中选择相册后，需要把已选择的相册uri通过setData接口通知到picker组件，从而触发picker组件刷新相册数据。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| SET_SELECTED_INFO<sup>21+</sup> | 3   | 发送已选择的文件uri以及选中的picker序号。当picker序号与参数中的picker序号匹配时，已选择文件支持在当前picker里自动选中。<br>**原子化服务API**：从API version 21开始，该接口支持在原子化服务中使用。 |
| SET_BADGE_CONFIGS<sup>21+</sup> | 4   | 发送需要显示角标的配置，类型为[badgeConfig](#badgeconfig21)，包含角标的类型和对应文件uri的数据列表。配置后，对应文件会显示配置类型的角标。<br>**原子化服务API**：从API version 21开始，该接口支持在原子化服务中使用。 |
| SET_ITEM_CLICK_RESULT<sup>23+</sup> | 5   | 发送点击后的结果，类型为[ClickResult](#clickresult23)。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。 |

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

Picker宫格页面滑动预览的方向。

从API20开始，该能力支持配置；在API12-19，该能力设置不生效，默认为竖直方向。

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

## BadgeType<sup>21+</sup>

表示特殊角标类型的枚举。

**原子化服务API**：从API version 21开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称          | 值   | 说明       |
|-------------|-----|----------|
| BADGE_UPLOADED     | 0   | 已上传。  |

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
| SEEK_FINISH | 4   | 结束拖拽进度条。 |

## ItemDisplayRatio<sup>20+</sup>

单行布局宫格显示宽高比模式，包括1:1和原图宽高比两种模式。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                | 值  | 说明           |
| ------------------- | --- | -------------- |
| SQUARE_RATIO        | 0   | 1:1比例显示。    |
| ORIGINAL_SIZE_RATIO | 1   | 原图宽高比显示。 |

## 示例一（PhotoPickerComponent组件的使用）

```ts
// xxx.ets
// 从API version 23开始，推荐使用统一导入方式，从'@kit.MediaLibraryKit'导入所需模块。
// 在API version 23之前的版本中，需要使用分别导入方式。
// import { PhotoPickerComponent, PickerController, PickerOptions, DataType, BaseItemInfo, ItemInfo, PhotoBrowserInfo, ItemType, ClickType, MaxCountType, PhotoBrowserRange, PhotoBrowserUIElement, ItemsDeletedCallback, ExceedMaxSelectedCallback, CurrentAlbumDeletedCallback, videoPlayStateChangedCallback, VideoPlayerState } from '@ohos.file.PhotoPickerComponent';
// import { photoAccessHelper } from '@ohos.file.photoAccessHelper';
import {
  PhotoPickerComponent,
  PickerController,
  PickerOptions,
  DataType,
  BaseItemInfo,
  ItemInfo,
  PhotoBrowserInfo,
  ItemType,
  ClickType,
  MaxCountType,
  PhotoBrowserRange,
  PhotoBrowserUIElement,
  ItemsDeletedCallback,
  ExceedMaxSelectedCallback,
  CurrentAlbumDeletedCallback,
  videoPlayStateChangedCallback,
  VideoPlayerState,
  photoAccessHelper
} from '@kit.MediaLibraryKit';
import { dataSharePredicates } from '@kit.ArkData';
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct PickerDemo {
  pickerOptions: PickerOptions = new PickerOptions();
  @State pickerController: PickerController = new PickerController();
  @State selectUris: string[] = [];
  @State currentUri: string = '';
  @State isBrowserShow: boolean = false;
  private selectedItemsDeletedCallback: ItemsDeletedCallback =
    (baseItemInfos: Array<BaseItemInfo>) => this.onSelectedItemsDeleted(baseItemInfos);
  private exceedMaxSelectedCallback: ExceedMaxSelectedCallback =
    (exceedMaxCountType: MaxCountType) => this.onExceedMaxSelected(exceedMaxCountType);
  private currentAlbumDeletedCallback: CurrentAlbumDeletedCallback = () => this.onCurrentAlbumDeleted();
  private videoPlayStateChangedCallback: videoPlayStateChangedCallback =
    (state: VideoPlayerState) => this.videoPlayStateChanged(state);
  private thumbnail: PixelMap[] = [];
  private assets: photoAccessHelper.PhotoAsset[] = [];

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
        // 应用做自己的业务处理（注：非长耗时操作，例如openSync大文件）。
        if (uri) {
          this.selectUris.push(uri);
          this.pickerOptions.preselectedUris = [...this.selectUris];
        }
        return true; // 返回true则勾选，否则不响应勾选。
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
          onSelect: (uri: string): void => this.onSelect(uri),
          onDeselect: (uri: string): void => this.onDeselect(uri),
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
            ForEach(this.assets, async (asset: photoAccessHelper.PhotoAsset, index) => {
              if (asset.uri === this.currentUri) {
                Image(this.thumbnail[index])
                  .height('10%')
                  .width('10%')
                  .onClick(() => {
                  })
                  .borderWidth(1)
                  .borderColor('red')
              } else {
                Image(this.thumbnail[index]).height('10%').width('10%').onClick(() => {
                  this.pickerController.setData(DataType.SET_SELECTED_URIS, this.selectUris);
                  this.pickerController.setPhotoBrowserItem(asset.uri, PhotoBrowserRange.ALL);
                })
              }
            }, (uri: string) => JSON.stringify(uri))
          }
        } else {
          Button('预览').width('33%').height('5%').onClick(async () => {
            if (this.selectUris.length > 0) {
              this.thumbnail = [];
              this.assets = [];
              for (let selectUri of this.selectUris) {
                let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
                predicates.equalTo(photoAccessHelper.PhotoKeys.URI, selectUri);
                let fetchOptions: photoAccessHelper.FetchOptions = {
                  fetchColumns: [],
                  predicates: predicates
                };
                let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
                let photoHelper = photoAccessHelper.getPhotoAccessHelper(context);
                let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> =
                  await photoHelper.getAssets(fetchOptions);
                let asset = await fetchResult.getFirstObject()
                this.assets.push(asset);
                this.thumbnail.push(await asset.getThumbnail())
              }
              this.pickerController.setPhotoBrowserItem(this.selectUris[0], PhotoBrowserRange.SELECTED_ONLY);
            }
          })
        }
      }
    }
  }
}
```

## 示例二（使用PhotoPickerComponent实现抽屉组件效果）

从API version 23开始，可以通过[PickerOptions](#pickeroptions)的isSlidingSupported、[PhotoPickerComponent](#photopickercomponent)的onScrollStopAtStart和onScrollStopAtEnd回调来实现抽屉效果。

```ts
// xxx.ets
import { display } from '@kit.ArkUI';
import { PhotoPickerComponent, PickerController, PickerOptions } from '@kit.MediaLibraryKit';
const enum DrawerState {
  // 展开状态。
  Expanding,
  // 收缩状态。
  Collapsing,
  // 滑动状态。
  Sliding
}

@Entry
@Component
struct Drawer {
  @State pickerController: PickerController = new PickerController();
  private pickerOptions: PickerOptions = new PickerOptions();
  // 屏幕高度，单位为vp。
  @State screenHeight: number = 0;
  // 抽屉高度，单位为vp。
  @State drawerHeight: number = 0;
  // 抽屉的偏移量，单位为vp。
  @State offsetY: number = 0;
  // 抽屉是否展开。
  @State isExpanded: boolean = false;
  // 拖拽起始位置，单位为vp。
  private startY: number = 0;
  // 当前拖拽的偏移量，单位为vp。
  private currentOffset: number = 0;
  // 自定义抽屉高度在整个屏幕的占比。
  private drawerRatio: number = 0.8;
  // 自定义初始化时隐藏抽屉的占比。
  private hideRatio: number = 0.8;
  // 初始化为收缩状态。
  private drawerState: DrawerState = DrawerState.Collapsing;
  // 手势响应阈值，判断手势是否为向下。
  private pullingDownThreshold: number = -5;

  aboutToAppear(): void {
    // 获取屏幕高度。
    let displayInfo = display.getDefaultDisplaySync();
    this.screenHeight = displayInfo.height / displayInfo.densityPixels;
    // 获取抽屉高度，示例为屏幕高度的0.8倍，可自定义修改。
    this.drawerHeight = this.screenHeight * this.drawerRatio;
    // 初始时抽屉在底部（隐藏高度），示例为隐藏抽屉的0.8倍。
    this.offsetY = this.drawerHeight * this.hideRatio;
    // 初始化时Picker不支持滑动。
    this.pickerOptions.isSlidingSupported = false;
    // 无边缘回弹。
    this.pickerOptions.edgeEffect = EdgeEffect.None;
    // 不展示搜索框。
    this.pickerOptions.isSearchSupported = false;
  }

  private scrollStopAtStart() {
    // 状态变更为展开状态，同时设置宫格不能滑动。
    this.drawerState = DrawerState.Expanding;
    this.pickerController.updatePickerOptions({
    isSlidingSupported: false
  })
  }

  private toggleDrawer() {
    if (this.isExpanded) {
      this.hideDrawer();
    } else {
      this.showDrawer();
    }
  }

  private hideDrawer() {
    this.getUIContext()?.animateTo({
      duration: 300,
      curve: Curve.EaseOut,
      onFinish: () => {
        this.isExpanded = false;
      }
    }, () => {
      this.drawerState = DrawerState.Collapsing;
      this.offsetY = this.drawerHeight * 0.8;
    })
  }

  private showDrawer() {
    this.getUIContext()?.animateTo({
      duration: 300,
      curve: Curve.EaseOut,
      onFinish: () => {
        this.isExpanded = true;
      }
    }, () => {
      this.drawerState = DrawerState.Expanding;
      this.offsetY = 0;
    })
  }

  build() {
    RelativeContainer() {
      // 主内容区域。
      Column() {
        Text('主页面内容')
          .fontSize(24)
          .fontWeight(FontWeight.Bold)
          .margin({ bottom: 20 })

        Text('这是一个使用RelativeContainer实现的底部抽屉效果')
          .fontSize(16)
          .fontColor('#666')
          .margin({ bottom: 30 })
          .textAlign(TextAlign.Center)
          .width('80%')

        Button(this.isExpanded ? '收起抽屉' : '展开抽屉')
          .onClick(() => {
            this.toggleDrawer();
          })
      }
      .width('100%')
      .padding(20)
      .alignItems(HorizontalAlign.Center)
      .backgroundColor('#f5f5f5')
      .borderRadius(10)
      .alignRules({
        top: { anchor: '__container__', align: VerticalAlign.Top },
        left: { anchor: '__container__', align: HorizontalAlign.Start },
        right: { anchor: '__container__', align: HorizontalAlign.End },
      })
      .height('100%')

      if (this.isExpanded) {
        Column()
          .width('100%')
          .height('100%')
          .backgroundColor('#80000000')
          .alignRules({
            top: { anchor: '__container__', align: VerticalAlign.Top },
            left: { anchor: '__container__', align: HorizontalAlign.Start },
            right: { anchor: '__container__', align: HorizontalAlign.End },
            bottom: { anchor: '__container__', align: VerticalAlign.Bottom },
          })
          .onClick(() => {
            this.hideDrawer();
          })
      }

      Column() {
        Row()
          .width(50)
          .height(5)
          .backgroundColor('#CCC')
          .borderRadius(3)
          .margin({ top: 12, bottom: 8 })

        Text('抽屉菜单')
          .fontSize(18)
          .fontWeight(FontWeight.Medium)
          .margin({ bottom: 10 })

        Divider()
          .width('90%')
          .margin({ bottom: 10 })

        PhotoPickerComponent({
          pickerOptions: this.pickerOptions,
          pickerController: this.pickerController,
          onScrollStopAtStart: this.scrollStopAtStart
        })
          .layoutWeight(1)
          .width('100%')
      }
      .width('100%')
      .height(this.drawerHeight)
      .backgroundColor(Color.White)
      .borderRadius({ topLeft: 20, topRight: 20 })
      .shadow({ radius: 10, color: '#33000000' })
      .alignRules({
        left: { anchor: '__container__', align: HorizontalAlign.Start },
        right: { anchor: '__container__', align: HorizontalAlign.End },
        bottom: { anchor: '__container__', align: VerticalAlign.Bottom },
      })
      .translate({ y: this.offsetY })
      .gesture(
        PanGesture({ direction: PanDirection.Vertical })
          // 记录抽屉开始拖拽的位置。
          .onActionStart((event: GestureEvent) => {
            this.startY = event.fingerList[0].globalY || 0;
            this.currentOffset = this.offsetY;
          })
          .onActionUpdate((event: GestureEvent) => {
            // 如果是Picker滑动状态，不改变抽屉的高度，直接返回。
            if (this.drawerState === DrawerState.Sliding) {
              return;
            }
            // 如果抽屉的状态是展开或者收缩则需要通过手势来进一步改变抽屉状态。
            // 计算移动距离。
            const deltaY = event.fingerList[0].globalY - this.startY || 0;
            // 当抽屉处于展开状态且用户向下滑动时，开启宫格滑动功能并将抽屉状态切换为滑动状态。
            if (this.drawerState === DrawerState.Expanding && deltaY < this.pullingDownThreshold) {
              this.pickerController.updatePickerOptions({
                isSlidingSupported: true
              })
              this.drawerState = DrawerState.Sliding
            }
            let newOffset = this.currentOffset + deltaY;
            if (newOffset < 0) {
              newOffset = 0;
            }
            this.offsetY = newOffset;
          })
          .onActionEnd(()=>{
            // 手势结束，根据位置自动展开或收起。
            if (this.offsetY > this.drawerHeight / 2) {
              // 滑动超过抽屉高度一半，抽屉状态置为收缩状态。
              this.hideDrawer();
            } else {
              // 滑动不到抽屉高度一半，抽屉状态置为展开状态。
              this.showDrawer();
            }
          })
      )
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#E0E0E0')
  }
}
```