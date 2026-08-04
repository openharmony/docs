# Classes (其他)

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xuchangda-->
<!--Designer: @guxinggang-->
<!--Tester: @wangbeibei-->
<!--Adviser: @w_Machine_cc-->

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## RecommendationOptions<sup>11+</sup>

图片推荐选项（基于图片数据分析结果，依赖设备适配）。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 只读 | 可选 | 说明                          |
| ----------------------- | ------------------- | ---- | ---- | -------------------------------- |
| recommendationType | [RecommendationType](arkts-apis-photoAccessHelper-e.md#recommendationtype11)   | 否   | 是 | 如果需要根据枚举值推荐相应的图片，则配置此参数。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| textContextInfo<sup>12+</sup> | [TextContextInfo](arkts-apis-photoAccessHelper-i.md#textcontextinfo12)   | 否   | 是 | 如果需要根据文本信息推荐相应的图片，则配置此参数（如果同时配置了recommendationType，则仅textContextInfo生效）。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## BaseSelectOptions

图库选择选项基类。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 只读 | 可选 | 说明                          |
| ----------------------- | ------------------- | ---- | ---- | -------------------------------- |
| MIMEType    | [PhotoViewMIMETypes](arkts-apis-photoAccessHelper-e.md#photoviewmimetypes)   | 否 | 是   | 可选择的媒体文件类型，若无此参数，则默认为图片和视频类型。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| maxSelectNumber      | number | 否   | 是 | 选择媒体文件数量的最大值（最大可设置的值为500，若不设置则默认为50）。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。   |
| isPhotoTakingSupported<sup>11+</sup> | boolean  | 否   | 是 | 是否支持拍照，true表示支持，false表示不支持，默认为true。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| isSearchSupported<sup>11+</sup> | boolean  | 否   | 是 | 是否支持搜索，true表示支持，false表示不支持，默认为true。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| recommendationOptions<sup>11+</sup>       | [RecommendationOptions](#recommendationoptions11)   | 否   | 是 | 图片推荐相关配置参数。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| preselectedUris<sup>11+</sup> | Array&lt;string&gt;  | 否   | 是 | 预选择图片的uri数据。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| isPreviewForSingleSelectionSupported<sup>12+</sup> | boolean  | 否   | 是 | 单选模式下是否需要进入大图预览，true表示需要，false表示不需要，默认为true。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| singleSelectionMode<sup>18+</sup> | [SingleSelectionMode](arkts-apis-photoAccessHelper-e.md#singleselectionmode18) | 否   | 是 | 单选模式类型。默认为大图预览模式（SingleSelectionMode.BROWSER_MODE）。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| mimeTypeFilter<sup>19+</sup> | [MimeTypeFilter](#mimetypefilter19)  | 否   | 是 | 文件类型的过滤配置，支持指定多个类型过滤。<br>当配置mimeTypeFilter参数时，MIMEType的配置自动失效。<br>配置该参数时，仅显示配置过滤类型对应的媒体文件，建议提示用户仅支持选择指定类型的图片/视频。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。 |
| fileSizeFilter<sup>19+</sup> | [FileSizeFilter](#filesizefilter19)  | 否   | 是 | 可选择媒体文件大小的过滤配置。<br>配置该参数时，仅显示配置文件大小范围的媒体文件，建议提示用户仅支持选择指定大小的图片/视频。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。 |
| videoDurationFilter<sup>19+</sup> | [VideoDurationFilter](#videodurationfilter19)  | 否   | 是 | 可选择媒体文件视频时长的过滤配置。<br>配置该参数时，仅显示配置视频时长范围的媒体文件，建议提示用户仅支持选择指定时长视频。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。 |
| combinedMediaTypeFilter<sup>20+</sup> | Array\<string\> | 否 | 是 | 将过滤条件配置为字符串数组，支持多种类型组合。<br>字符串格式如下：`photoType \| photoSubType1,photoSubType2, … \| mimeType1,mimeType2, …`。<br>- 第1段指定1个photoType，固定为image（图片）或video（视频）。<br>- 第2段指定1~N个photoSubType，多个photoSubType之间使用逗号隔开，之间为“或（OR）”的逻辑取并集；N目前支持最大为1；可选的PhotoSubType包括movingPhoto或“*”（忽略）。<br>- 第3段指定1~N个mimeType，多个mimeType之间使用逗号隔开，之间为“或（OR）”的逻辑取并集；N最大为10，格式类似于[MimeTypeFilter](#mimetypefilter19)。<br>三段过滤的组合取交集处理。<br>支持“非”的逻辑。对于需要排除的类型，进行加括号的方式进行标识；一个string最多可使用1个括号。<br>当应用配置的过滤条件string不满足上述规格时，过滤结果为空。<br>配置该参数时，仅取数组前三个参数进行处理，MIMEType、mimeTypeFilter参数自动失效。<br>**原子化服务API：** 从API version 20开始支持在原子化服务中使用。 |
| photoViewMimeTypeFileSizeFilters<sup>20+</sup> | Array\<[PhotoViewMimeTypeFileSizeFilter](#photoviewmimetypefilesizefilter20)\>  | 否   | 是 | 指定媒体文件类型和文件大小进行过滤。<br>配置该参数时，仅取数组前三个参数进行处理，MIMETypes和fileSizeFilter自动失效。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| isMovingPhotoBadgeShown<sup>22+</sup> | boolean  | 否   | 是 | 是否在大图浏览模式下展示动态照片图标，true表示展示，false表示不展示，默认为false。<br>若设置为true，[Photoselectresult](#photoselectresult)返回movingPhotoBadgeStates数组，动态照片默认返回状态为[MOVING_PHOTO_ENABLED](arkts-apis-photoAccessHelper-e.md#movingphotobadgestatetype22)。<br>**注意：** 必须同时使用isMovingPhotoBadgeShown和MovingPhotoBadgeStateType判断照片是否是动态照片。<br>**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。 |
| assetFilter<sup>22+</sup>       | Array\<[OperationItem](#operationitem22)\> | 否   | 是 | 媒体资产过滤器，长度限制为50个，超出取前50个。<br>**注意：**<br> 1. 当使用该过滤器时，其他过滤器会失效。<br>2. 当配置多个条件时，过滤条件前后需要配置英文括号，否则可能和内部过滤项冲突。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。|
| autoPlayScenes<sup>23+</sup>      | Array\<[AutoPlayScene](#autoplayscene23)\> | 否   | 是 | 设置动态照片播放模式。长度限制为2个，超出取前2个，多余的会自动忽略。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。|
| globalMovingPhotoState<sup>23+</sup>       | [MovingPhotoBadgeStateType](arkts-apis-photoAccessHelper-e.md#movingphotobadgestatetype22) | 否   | 是 | 设置全局动态照片的效果，当前仅支持MOVING_PHOTO_ENABLED和MOVING_PHOTO_DISABLED。默认为MOVING_PHOTO_ENABLED。 <br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。 |
| gridPinchMode<sup>23+</sup>       | [GridPinchMode](arkts-apis-photoAccessHelper-i.md#gridpinchmode23) | 否   | 是 | picker内宫格捏合模式。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。 |
| showDateOnScrollbar<sup>24+</sup>       | boolean | 否   | 是 | 是否在拖动滚动条时展示日期分组信息，true表示展示，false表示不展示，默认为false。 <br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。 |
| assetCompatibleCapability<sup>24+</sup>       | [AssetCompatibleCapability](arkts-apis-photoAccessHelper-i.md#assetcompatiblecapability24)  | 否   | 是 | 资产兼容性能力配置。 <br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。 |
| preferredCompatibleMode       | [PreferredCompatibleMode](arkts-apis-photoAccessHelper-e.md#preferredcompatiblemode)  | 否   | 是 | 资产兼容性模式配置。 <br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br>**起始版本：** 26.0.0  |

## PhotoSelectOptions

PhotoSelectOptions extends BaseSelectOptions

图库选择选项子类，继承自[BaseSelectOptions](#baseselectoptions)。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 只读 | 可选 | 说明                          |
| ----------------------- | ------------------- | ---- | ---- | -------------------------------- |
| isEditSupported<sup>11+</sup>       | boolean | 否   | 是 | 是否支持编辑照片，true表示支持，false表示不支持，默认为true。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。     |
| isOriginalSupported<sup>12+</sup>       | boolean | 否   | 是 | 是否显示选择原图按钮，true表示显示，false表示不显示，默认为false。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。     |
| subWindowName<sup>12+</sup>       | string | 否   | 是 | 子窗口名称。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。     |
| completeButtonText<sup>14+</sup>       | [CompleteButtonText](arkts-apis-photoAccessHelper-e.md#completebuttontext14) | 否   | 是 | 完成按钮显示的内容。<br>完成按钮指在界面右下方，用户点击表示图片选择已完成的按钮。 <br>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。     |
| contextRecoveryInfo<sup>21+</sup>       | [ContextRecoveryInfo](#contextrecoveryinfo21) | 否   | 是 | 用于恢复上次退出时PhotoPicker现场的信息。<br>上次完成选择时photoPicker将返回contextRecoveryInfo给应用，应用可使用返回的contextRecoveryInfo，在下次启动时恢复上次使用picker，最后浏览的宫格界面。 <br>**原子化服务API：** 从API version 21开始，该接口支持在原子化服务中使用。     |
| isDestroyedWithNavigation<sup>23+</sup>       | boolean | 否   | 是 | 是否支持跟随[Navigation](../apis-arkui/arkui-ts/ts-basic-components-navigation.md#navigation-1)销毁，true表示支持，false表示不支持，默认为false。<br>**模型约束**： 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。     |
| maxPhotoSelectNumber<sup>23+</sup> | number  | 否  | 是 |支持设置的图片最大的选择数量。单位：个。<br>受到最大选择总数的限制，最大值为500。默认为500。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。                                     |
| maxVideoSelectNumber<sup>23+</sup> | number  | 否  | 是 | 支持设置的视频最大的选择数量。单位：个。<br>受到系统中所有媒体文件最大选择总数的限制，最大值为500。默认为500。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。 |
| isReturnToPhotoBrowserEnabled<sup>23+</sup>       | boolean | 否   | 是 | 在单选模式下，拍完照是否能自动跳转到大图预览模式，true表示支持，false表示不支持，默认为false。<br>**注意：** 该参数配置为true时仅在[SingleSelectionMode](arkts-apis-photoAccessHelper-e.md#singleselectionmode18)为BROWSER_MODE（大图预览模式）或者BROWSER_AND_SELECT_MODE（兼容模式）并且[BaseSelectOptions.isPreviewForSingleSelectionSupported](arkts-apis-photoAccessHelper-class.md#baseselectoptions)参数为true时生效。<br>**模型约束**： 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。     |
| isSelectionNumberVisible       | boolean | 否   | 是 | 是否支持选择序号。true表示支持，false表示不支持，默认值为false。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br>**起始版本：** 26.0.0     |
| isSelectionOrderAdjustable      | boolean | 否   | 是 | 是否支持调整选择顺序。true表示支持，false表示不支持，默认值为false。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br>**起始版本：** 26.0.0     |

## PhotoSelectResult

返回图库选择后的结果集。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 只读 | 可选 | 说明                          |
| ----------------------- | ------------------- | ---- | ---- | -------------------------------- |
| photoUris       | Array&lt;string&gt; | 否   | 否 | 返回图库选择后的媒体文件的URI数组。<br>此URI数组只能通过临时授权的方式调用[photoAccessHelper.getAssets](arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets)接口去使用，具体使用方式请参考[媒体文件URI的使用方式](../../file-management/user-file-uri-intro.md#媒体文件uri的使用方式)。<br>**注意：**<br>当资源为连拍照片类型时，则返回该连拍组的所有资源，判断是否为连拍图的方式请参考[通过URI判断连拍图资源](../../media/medialibrary/medialibrary-faqs/medialibrary-asset-judgment-faq.md#通过uri判断连拍图资源)。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。     |
| isOriginalPhoto       | boolean | 否   | 否 | 返回图库选择后的媒体文件是否为原图。true表示是原图，false表示不是原图，默认值是false。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。     |
| contextRecoveryInfo<sup>21+</sup>         | [ContextRecoveryInfo](#contextrecoveryinfo21)    | 否   | 否 | 当用户完成选择时返回的photoSelectResult将包含退出picker的上下文信息contextRecoveryInfo，支持应用下次启动PhotoPicker时设置给PhotoSelectOptions用于上次退出时现场的恢复。<br>**原子化服务API：** 从API version 21开始，该接口支持在原子化服务中使用。 |
| movingPhotoBadgeStates<sup>22+</sup>         | Array\<[MovingPhotoBadgeStateType](arkts-apis-photoAccessHelper-e.md#movingphotobadgestatetype22)\>    | 否   | 否 | 返回图库选择的媒体文件动态照片状态数组。<br>当isMovingPhotoBadgeShown为true时，movingPhotoBadgeStates携带动态照片状态，反之为空。<br>**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。 |

## AutoPlayScene<sup>23+</sup>

动态照片在不同场景中的播放模式。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 只读 | 可选 | 说明                          |
| ----------------------- | ------------------- | ---- | ---- | -------------------------------- |
| sceneType      | [SceneType](arkts-apis-photoAccessHelper-e.md#scenetype23) | 否   | 否 | 动态照片播放的场景。<br>**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。     |
| playMode    | [PlayMode](arkts-apis-photoAccessHelper-e.md#playmode23) | 否   | 否 | 是否支持动态照片自动播放。<br>**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。     |

## MimeTypeFilter<sup>19+</sup>

文件类型的过滤配置。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 只读 | 可选 | 说明                           |
| ----------------------- | ------------------- | ---- | ---- | ------------------------------ |
| mimeTypeArray        | Array&lt;string&gt;    | 否   | 否 | PhotoPicker可供用户选择媒体文件的过滤类型。数组长度最大为10，因此支持最多十种指定类型。<br>过滤类型参考MIME类型定义，例如：“image/jpeg”、“video/mp4”等。 |

## FileSizeFilter<sup>19+</sup>

可选择媒体文件大小的过滤配置。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 只读 | 可选 | 说明                           |
| ----------------------- | ------------------- | ---- | ---- |------------------------------ |
| filterOperator        | [FilterOperator](arkts-apis-photoAccessHelper-e.md#filteroperator19)    | 否  | 否 | 过滤操作符。<br>例如：按照大于/小于某个fileSize的方式过滤文件。 |
| fileSize        | number    | 否 | 否 | 指定进行过滤的文件大小。<br>单位为字节（Byte）。 |
| extraFileSize   | number    | 否 | 是 | 针对FilterOperator.BETWEEN情况下，配置文件大小的上限值。默认值为-1。<br>单位为字节（Byte）。 |

## VideoDurationFilter<sup>19+</sup>

可选择媒体文件视频时长的过滤配置。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 只读 | 可选 | 说明                           |
| ----------------------- | ------------------- | ---- | ---- |------------------------------ |
| filterOperator        | [FilterOperator](arkts-apis-photoAccessHelper-e.md#filteroperator19)    | 否 | 否  |过滤操作符。<br>例如：按照大于/小于某个videoDuration的方式过滤可选择的视频。 |
| videoDuration        | number    | 否 | 否 | 指定过滤视频的时长。<br>单位为毫秒（ms）。 |
| extraVideoDuration   | number    | 否 | 是 | 针对FilterOperator.BETWEEN情况下，配置视频时长的上限值。默认值为-1。<br>单位为毫秒（ms）。 |

## RecentPhotoOptions<sup>20+</sup>

最近图片配置选项。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                                                                                     | 只读 | 可选  | 说明   |
|-------------------------|-----------------------------------------------------------------------------------------|-------|-------|--------|
| period                  | number                                                                                  | 否    | 是 | 配置最近图片显示的时间范围，单位为秒（s）。配置后，系统将显示距离当前时间点指定时长内的图片。最长可配置时长为1天（86400s）。<br/>当值小于等于0、大于86400或者未配置时，默认按最长时间段（1天）显示最近图片。当配置时间段内无符合的图片或视频时，组件不显示。<br/>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。|
| MIMEType                | [photoAccessHelper.PhotoViewMIMETypes](arkts-apis-photoAccessHelper-e.md#photoviewmimetypes) | 否    | 是 | 最近图片控件显示的文件类型，默认为PhotoViewMIMETypes.IMAGE_VIDEO_TYPE。<br/>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。                         |
| photoSource             | [PhotoSource](arkts-apis-photoAccessHelper-e.md#photosource20)                                                             | 否    | 是 | 配置最近图片视频显示内容的来源，比如拍照、截屏等。默认不限制来源。<br/>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。                               |

## RecentPhotoInfo<sup>20+</sup>

最近图片相关信息。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称         | 类型     | 只读 | 可选  | 说明                                                        |
|------------|--------|-------|-------|-----------------------------------------------------------|
| dateTaken  | number | 否    | 是 | 最近图片/视频的拍摄时间（距1970年1月1日的毫秒数值），单位为毫秒（ms）。<br/>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。                     |
| identifier | string | 否    | 是 | 最近图片/视频的名称hash值，用于辅助应用区分最新图片组件将要显示的图片/视频与之前曾显示过的图片/视频是否为同一个。<br/>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。 |

## PhotoViewMimeTypeFileSizeFilter<sup>20+</sup>

指定媒体文件类型和文件大小进行过滤。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 只读 | 可选 | 说明                          |
| ----------------------- | ------------------- | ---- | ---- | -------------------------------- |
| photoViewMimeType    | [PhotoViewMIMETypes](arkts-apis-photoAccessHelper-e.md#photoviewmimetypes)   | 否 | 否   | 指定媒体文件类型，用于文件大小过滤。 |
| sizeFilter    | [FileSizeFilter](#filesizefilter19)   | 否 | 否   | 指定文件大小过滤规则。 |

## ContextRecoveryInfo<sup>21+</sup>

PhotoPicker退出界面的上下文信息，可以用于下次使用PhotoPicker时恢复上次退出时的现场。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 只读 | 可选 | 说明                          |
| ----------------------- | ------------------- | ---- | ---- | -------------------------------- |
| albumUri    | string | 否   | 否 | 用户选择图片后，退出时的相册信息。<br/>albumUri对应媒体库中相册的uri。<br>- 当上次在所有图片中选择时，albumUri为固定的"allPhotos"字符串。<br/>- 当用户在搜索结果/文本推荐/头像推荐中完成选择退出时，不支持下次恢复现场，此时Picker返回的albumUri为空字符串。<br/>默认值为空字符串。<br>**原子化服务API：** 从API version 21开始，该接口支持在原子化服务中使用。 |
| time    | number   | 否   | 否 | 用户上次选择图片的宫格界面，左上角首张图片的时间。<br/>- 按拍摄时间排序的相册，返回拍摄时间。<br/>- 按保存时间排序的相册返回保存时间。默认为0。<br>**原子化服务API：** 从API version 21开始，该接口支持在原子化服务中使用。 |
| displayName    | string   | 否   | 否 | 用户上次选择图片的宫格界面，左上角首张图片的文件名。默认为空字符串。<br>**原子化服务API：** 从API version 21开始，该接口支持在原子化服务中使用。 |
| recommendationType    | number   | 否   | 否 | 用户上次选择时设置的推荐内容枚举值，参考[RecommendationType](arkts-apis-photoAccessHelper-e.md#recommendationtype11)值定义。<br/>上次选择时未设置推荐时，默认为0。<br>**原子化服务API：** 从API version 21开始，该接口支持在原子化服务中使用。|
| selectedRecommendationType    | number   | 否   | 否 | 用户上次选择时选中的推荐内容枚举值，参考[RecommendationType](arkts-apis-photoAccessHelper-e.md#recommendationtype11)值定义。<br/>当上次选择未选中推荐项，选中"全部"时，默认为0。<br>**原子化服务API：** 从API version 21开始，该接口支持在原子化服务中使用。|
| version    | number   | 否   | 否 | 现场数据版本号，用于校验现场信息数据与现场恢复能力的匹配度。<br>版本号必须大于等于1.0。<br>**原子化服务API：** 从API version 21开始，该接口支持在原子化服务中使用。|
| gridLevel<sup>23+</sup>    | [GridLevel](arkts-apis-photoAccessHelper-e.md#gridlevel23)   | 否   | 是 | 用户上次退出宫格时的档位。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。|
| sortRule<sup>24+</sup>    | string   | 否   | 是 | 用户上次选择图片的宫格界面的排序规则，默认为空字符串。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。 |
| fileSize<sup>24+</sup>    | number   | 否   | 是 | 用户上次选择图片的宫格界面中，左上角首张图片的文件大小，默认为0。<br>**模型约束：** 此接口仅可在Stage模型下使用。<br>**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。|

## OperationItem<sup>22+</sup>

选择媒体文件的过滤配置。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 只读 | 可选 | 说明                          |
| ----------------------- | ------------------- | ---- | ---- | -------------------------------- |
| operationType    | [OperationType](arkts-apis-photoAccessHelper-e.md#operationtype22)   | 否 | 否   | 各类谓词的枚举。 |
| field    | [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys)   | 否 | 是   | 数据表中的列名。<br>当前仅支持如下关键字段：URI、PHOTO_TYPE、DISPLAY_NAME、SIZE、DURATION、WIDTH、HEIGHT、ORIENTATION、FAVORITE、TITLE、POSITION、PHOTO_SUBTYPE、DYNAMIC_RANGE_TYPE、COVER_POSITION、BURST_KEY、LCD_SIZE、THM_SIZE、DETAIL_TIME、MEDIA_SUFFIX、OWNER_ALBUM_ID、ASPECT_RATIO、DATE_TAKEN_MS<sup>24+</sup><br>通过[select](arkts-apis-photoAccessHelper-PhotoViewPicker.md#select)接口配置此参数时，输入非法字段会抛出错误码401；通过[PhotoPickerComponent (PhotoPicker组件)](ohos-file-PhotoPickerComponent.md)配置此参数时，输入非法字段无onPickerControllerReady回调。<br>非条件谓词如and、or、beginWrap、endWrap等不涉及该字段。 |
| value    | Array<[OperationValueType](arkts-apis-photoAccessHelper-t.md#operationvaluetype22)>   | 否 | 是   |  不同谓词所需匹配的值。<br>非条件谓词如and、or、beginWrap、endWrap等不涉及该字段。<br>限制最大长度为10，超出则取前10个值。 |
 
## RequestReadPermissionResult<sup>23+</sup>

包含已授权的uri列表和无效的uri列表。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 只读 | 可选 | 说明                          |
| ----------------------- | ------------------- | ---- | ---- | -------------------------------- |
| authorizedUris    | Array\<string\>   | 否 | 是   | 返回已创建并授予保存权限的uri列表。 |
| invalidUris    | Array\<string\>  | 否 | 是   | 返回可能被删除、隐藏或重命名的无效uri列表。 |