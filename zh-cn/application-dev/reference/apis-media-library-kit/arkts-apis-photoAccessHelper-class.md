# Classes (其他)

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xuchangda; @yixiaoff-->
<!--Designer: @guxinggang; @liweilu1-->
<!--Tester: @wangbeibei; @xchaosioda-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## RecommendationOptions<sup>11+</sup>

图片推荐选项(基于图片数据分析结果，依赖设备适配)。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 必填 | 说明                          |
| ----------------------- | ------------------- | ---- | -------------------------------- |
| recommendationType | [RecommendationType](arkts-apis-photoAccessHelper-e.md#recommendationtype11)   | 否   | 如果需要根据枚举值推荐相应的图片，则配置此参数。 <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。|
| textContextInfo<sup>12+</sup> | [TextContextInfo](arkts-apis-photoAccessHelper-i.md#textcontextinfo12)   | 否   | 如果需要根据文本信息推荐相应的图片，则配置此参数(如果同时配置了recommendationType，则仅textContextInfo生效)。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## BaseSelectOptions<sup>12+</sup>

图库选择选项基类。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 必填 | 说明                          |
| ----------------------- | ------------------- | ---- | -------------------------------- |
| MIMEType    | [PhotoViewMIMETypes](arkts-apis-photoAccessHelper-e.md#photoviewmimetypes)   | 否   | 可选择的媒体文件类型，若无此参数，则默认为图片和视频类型。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| maxSelectNumber      | number | 否   | 选择媒体文件数量的最大值（最大可设置的值为500，若不设置则默认为50）。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。   |
| isPhotoTakingSupported<sup>11+</sup> | boolean  | 否   | 是否支持拍照，true表示支持，false表示不支持，默认为true。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| isSearchSupported<sup>11+</sup> | boolean  | 否   | 是否支持搜索，true表示支持，false表示不支持，默认为true。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| recommendationOptions<sup>11+</sup>       | [RecommendationOptions](#recommendationoptions11)   | 否   | 图片推荐相关配置参数。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| preselectedUris<sup>11+</sup> | Array&lt;string&gt;  | 否   | 预选择图片的uri数据。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| isPreviewForSingleSelectionSupported<sup>12+</sup> | boolean  | 否   | 单选模式下是否需要进大图预览，true表示需要，false表示不需要，默认为true。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| singleSelectionMode<sup>18+</sup> | [SingleSelectionMode](arkts-apis-photoAccessHelper-e.md#singleselectionmode18) | 否   | 单选模式类型。默认为大图预览模式（SingleSelectionMode.BROWSER_MODE）。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。 |
| mimeTypeFilter<sup>19+</sup> | [MimeTypeFilter](#mimetypefilter19)  | 否   | 文件类型的过滤配置，支持指定多个类型过滤。<br>当配置mimeTypeFilter参数时，MIMEType的配置自动失效。<br>配置该参数时，仅显示配置过滤类型对应的媒体文件，建议提示用户仅支持选择指定类型的图片/视频。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。 |
| fileSizeFilter<sup>19+</sup> | [FileSizeFilter](#filesizefilter19)  | 否   | 可选择媒体文件大小的过滤配置。<br>配置该参数时，仅显示配置文件大小范围的媒体文件，建议提示用户仅支持选择指定大小的图片/视频。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。 |
| videoDurationFilter<sup>19+</sup> | [VideoDurationFilter](#videodurationfilter19)  | 否   | 可选择媒体文件视频时长的过滤配置。<br>配置该参数时，仅显示配置视频时长范围的媒体文件，建议提示用户仅支持选择指定时长视频。<br>**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。 |
| combinedMediaTypeFilter<sup>20+</sup> | Array\<string\> | 否 | 将过滤条件配置为字符串数组，支持多种类型组合。<br>字符串格式如下：`photoType \| photoSubType1,photoSubType2, … \| mimeType1,mimeType2, …`。<br>- 第1段指定1个photoType，固定为image（图片）或video（视频）。<br>- 第2段指定1~N个photoSubType，多个photoSubType之间使用逗号隔开，之间为“或（OR）”的逻辑取并集；N目前支持最大为1；可选的PhotoSubType包括movingPhoto或“*”（忽略）。<br>- 第3段指定1~N个mimeType，多个mimeType之间使用逗号隔开，之间为“或（OR）”的逻辑取并集；N最大为10，格式类似于[MimeTypeFilter](#mimetypefilter19)。<br>三段过滤的组合取交集处理。<br>支持“非”的逻辑。对于需要排除的类型，进行加括号的方式进行标识；一个string最多可使用1个括号。<br>当应用配置的过滤条件string不满足上述规格时，过滤结果为空。<br>配置该参数时，仅取数组前三个参数进行处理，MIMEType、mimeTypeFilter参数自动失效。<br>**原子化服务API：** 从API version 20开始支持在原子化服务中使用。 |
| photoViewMimeTypeFileSizeFilters<sup>20+</sup> | Array\<[PhotoViewMimeTypeFileSizeFilter](#photoviewmimetypefilesizefilter20)\>  | 否   | 指定媒体文件类型和文件大小进行过滤。<br>配置该参数时，仅取数组前三个参数进行处理，MIMETypes和fileSizeFilter自动失效。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## PhotoSelectOptions

PhotoSelectOptions extends BaseSelectOptions

图库选择选项子类，继承自[BaseSelectOptions](#baseselectoptions12)。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 必填 | 说明                          |
| ----------------------- | ------------------- | ---- | -------------------------------- |
| isEditSupported<sup>11+</sup>       | boolean | 否   | 是否支持编辑照片，true表示支持，false表示不支持，默认为true。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。     |
| isOriginalSupported<sup>12+</sup>       | boolean | 否   | 是否显示选择原图按钮，true表示显示，false表示不显示，默认为true。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。     |
| subWindowName<sup>12+</sup>       | string | 否   | 子窗口名称。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。     |
| completeButtonText<sup>14+</sup>       | [CompleteButtonText](arkts-apis-photoAccessHelper-e.md#completebuttontext14) | 否   | 完成按钮显示的内容。<br>完成按钮指在界面右下方，用户点击表示图片选择已完成的按钮。 <br>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。     |

## PhotoSelectResult

返回图库选择后的结果集。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 可读 | 可写 | 说明                           |
| ----------------------- | ------------------- | ---- | ---- | ------------------------------ |
| photoUris        | Array&lt;string&gt;    | 是   | 是   | 返回图库选择后的媒体文件的uri数组，此uri数组只能通过临时授权的方式调用[photoAccessHelper.getAssets接口](arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets)去使用，具体使用方式参见用户文件uri介绍中的[媒体文件uri的使用方式](../../file-management/user-file-uri-intro.md#媒体文件uri的使用方式)。 |
| isOriginalPhoto        | boolean    | 是   | 是   | 返回图库选择后的媒体文件是否为原图。true为是原图，false为不是原图，默认值是false。 |

## MimeTypeFilter<sup>19+</sup>

文件类型的过滤配置。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 必填 | 说明                           |
| ----------------------- | ------------------- | ---- | ------------------------------ |
| mimeTypeArray        | Array&lt;string&gt;    | 是   | PhotoPicker可供用户选择媒体文件的过滤类型。最多支持指定十种媒体文件类型。<br>过滤类型参考MIME类型定义，例如：“image/jpeg”、“video/mp4”等。 |

## FileSizeFilter<sup>19+</sup>

可选择媒体文件大小的过滤配置。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 必填 | 说明                           |
| ----------------------- | ------------------- | ---- |------------------------------ |
| filterOperator        | [FilterOperator](arkts-apis-photoAccessHelper-e.md#filteroperator19)    | 是  | 过滤操作符。<br>例如：按照大于/小于某个fileSize的方式过滤文件。 |
| fileSize        | number    | 是 | 指定进行过滤的文件大小。<br>单位为字节（Byte）。 |
| extraFileSize   | number    | 否 | 针对FilterOperator.BETWEEN情况下，配置文件大小的上限值。默认值为-1。<br>单位为字节（Byte）。 |

## VideoDurationFilter<sup>19+</sup>

可选择媒体文件视频时长的过滤配置。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 必填 | 说明                           |
| ----------------------- | ------------------- | ---- |------------------------------ |
| filterOperator        | [FilterOperator](arkts-apis-photoAccessHelper-e.md#filteroperator19)    | 是  |过滤操作符。<br>例如：按照大于/小于某个videoDuration的方式过滤可选择的视频。 |
| videoDuration        | number    | 是 | 指定过滤视频的时长。<br>单位为毫秒（ms）。 |
| extraVideoDuration   | number    | 否 | 针对FilterOperator.BETWEEN情况下，配置视频时长的上限值。默认值为-1。<br>单位为毫秒（ms）。 |

## RecentPhotoOptions<sup>20+</sup>

最近图片配置选项。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                                                                                      | 必填  | 说明   |
|-------------------------|-----------------------------------------------------------------------------------------|-------|--------|
| period                  | number                                                                                  | 否    | 配置最近图片显示的时间范围，单位为秒（s）。配置后，系统将显示距离当前时间点指定时长内的图片。最长可配置时长为1天（86400s）。<br/>当值小于等于0、大于86400或者未配置时，默认按最长时间段（1天）显示最近图片。当配置时间段内无符合的图片或视频时，组件不显示。<br/>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。|
| MIMEType                | [photoAccessHelper.PhotoViewMIMETypes](arkts-apis-photoAccessHelper-e.md#photoviewmimetypes) | 否    | 最近图片控件显示的文件类型，默认为PhotoViewMIMETypes.IMAGE_VIDEO_TYPE。<br/>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。                         |
| photoSource             | [PhotoSource](arkts-apis-photoAccessHelper-e.md#photosource20)                                                             | 否    | 配置最近图片视频显示内容的来源，比如拍照、截屏等。默认不限制来源。<br/>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。                               |

## RecentPhotoInfo<sup>20+</sup>

最近图片相关信息。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称         | 类型     | 必填  | 说明                                                        |
|------------|--------|-------|-----------------------------------------------------------|
| dateTaken  | number | 否    | 最近图片/视频的拍摄时间（距1970年一月一日的毫秒数值），单位为毫秒（ms）。<br/>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。                     |
| identifier | string | 否    | 最近图片/视频的名称hash值，用于辅助应用区分最新图片组件将要显示的图片/视频与之前曾显示过的图片/视频是否为同一个。<br/>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。 |

## PhotoViewMimeTypeFileSizeFilter<sup>20+</sup>

媒体文件视频时长过滤配置。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 必填 | 说明                          |
| ----------------------- | ------------------- | ---- | -------------------------------- |
| photoViewMimeType    | [PhotoViewMIMETypes](arkts-apis-photoAccessHelper-e.md#photoviewmimetypes)   | 是   | 指定媒体文件类型，用于文件大小过滤。 |
| sizeFilter    | [FileSizeFilter](#filesizefilter19)   | 是   | 指定文件大小过滤规则。 |