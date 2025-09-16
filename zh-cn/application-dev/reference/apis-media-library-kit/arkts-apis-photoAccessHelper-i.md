# Interfaces (其他)
<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## MediaChangeRequest<sup>11+</sup>

媒体变更请求，资产变更请求和相册变更请求的父类型。

> **注意**：
>
> 媒体变更请求必须在调用[applyChanges](arkts-apis-photoAccessHelper-PhotoAccessHelper.md#applychanges11)后才会生效。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

## CreateOptions

图片或视频的创建选项。

title参数的规格如下：

- 不应包含扩展名。
- 文件名字符串长度为1~255。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                   | 类型                | 必填 | 说明                                              |
| ---------------------- | ------------------- | ---- | ------------------------------------------------ |
| title                  | string                          | 否  | 图片或者视频的标题。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。  |
| subtype<sup>12+</sup>  | [PhotoSubtype](arkts-apis-photoAccessHelper-e.md#photosubtype12) | 否  | 图片或者视频的文件子类型。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。  |

## FetchOptions

检索条件。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                   | 类型                | 只读 | 可选 | 说明                                              |
| ---------------------- | ------------------- | ---- |---- | ------------------------------------------------ |
| fetchColumns           | Array&lt;string&gt; | 否   | 否   | 检索条件，指定列名查询。<br>对于照片，如果该参数为空，默认查询'uri'、'media_type'、'subtype'和'display_name'，使用[get](arkts-apis-photoAccessHelper-PhotoAsset.md#get)接口获取当前对象的其他属性时将会报错。示例：fetchColumns: ['uri', 'title']。<br>对于相册，如果该参数为空，默认查询'uri'和'album_name'。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| predicates           | [dataSharePredicates.DataSharePredicates](../apis-arkdata/js-apis-data-dataSharePredicates.md#datasharepredicates) | 否   | 否   | 谓词查询，显示过滤条件。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## RequestOptions<sup>11+</sup>

请求策略。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                   | 类型                        | 只读 | 可选 | 说明                                         |
| ---------------------- |----------------------------| ---- | ---- | ------------------------------------------- |
| deliveryMode           | [DeliveryMode](arkts-apis-photoAccessHelper-e.md#deliverymode11) | 否   | 否   | 请求资源分发模式，可以指定对于该资源的请求策略，可被配置为快速模式，高质量模式，均衡模式三种策略。 |
| compatibleMode<sup>15+</sup>      | [CompatibleMode](arkts-apis-photoAccessHelper-e.md#compatiblemode15) | 否   | 是   | 配置HDR视频资源转码模式，可指定配置为转码和不转码两种策略。默认为原视频资源内容模式即不转码。 |
| mediaAssetProgressHandler<sup>15+</sup> | [MediaAssetProgressHandler](arkts-apis-photoAccessHelper-MediaAssetProgressHandler.md) | 否   | 是   | 配置HDR视频转码为SDR视频时的进度级回调。 |

## ChangeData

监听器回调函数的返回值。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称    | 类型                        | 只读 | 可选 | 说明                                                         |
| ------- | --------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type    | [NotifyType](arkts-apis-photoAccessHelper-e.md#notifytype) | 否   | 否   | ChangeData的通知类型。                                       |
| uris    | Array&lt;string&gt;         | 否   | 否   | 相同[NotifyType](arkts-apis-photoAccessHelper-e.md#notifytype)的所有uri，可以是PhotoAsset或Album。 |
| extraUris | Array&lt;string&gt;         | 否   | 否   | 相册中变动文件的uri数组。可能为undefined，使用前需要检查是否为undefined。                           |

## TextContextInfo<sup>12+</sup>

文本信息，用于推荐图片的文本信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                    | 类型                | 必填 | 说明                          |
| ----------------------- | ------------------- | ---- | -------------------------------- |
| text | string   | 否   | 如果需要根据文本(支持250字以内的简体中文)推荐相应的图片，则配置此参数。text默认是空字符串。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let textInfo: photoAccessHelper.TextContextInfo = {
      text: '上海野生动物园的大熊猫'
    }
    let recommendOptions: photoAccessHelper.RecommendationOptions = {
      textContextInfo: textInfo
    }
    let options: photoAccessHelper.PhotoSelectOptions = {
      MIMEType: photoAccessHelper.PhotoViewMIMETypes.IMAGE_TYPE,
      maxSelectNumber: 1,
      recommendationOptions: recommendOptions
    }
    let photoPicker = new photoAccessHelper.PhotoViewPicker();
    photoPicker.select(options).then((PhotoSelectResult: photoAccessHelper.PhotoSelectResult) => {
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));
    }).catch((err: BusinessError) => {
      console.error(`PhotoViewPicker.select failed with err: ${err.code}, ${err.message}`);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error(`PhotoViewPicker failed with err: ${err.code}, ${err.message}`);
  }
}
```

## PhotoCreationConfig<sup>12+</sup>

保存图片/视频到媒体库的配置，包括保存的文件名等。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                   | 类型                | 必填 | 说明                                              |
| ---------------------- | ------------------- | ---- | ------------------------------------------------ |
| title | string | 否  | 图片或者视频的标题，不传入时由系统生成。参数规格为：<br>- 不应包含扩展名。<br>- 文件名字符串长度为1~255（资产文件名为标题+扩展名）。<br>- 不允许出现的非法英文字符，包括：. \ / : * ? " ' ` < > \| { } [ ]|
| fileNameExtension | string | 是  | 文件扩展名，例如'jpg'。|
| photoType | [PhotoType](arkts-apis-photoAccessHelper-e.md#phototype) | 是  | 创建的文件类型[PhotoType](arkts-apis-photoAccessHelper-e.md#phototype)，IMAGE或者VIDEO。|
| subtype | [PhotoSubtype](arkts-apis-photoAccessHelper-e.md#photosubtype12) | 否  | 图片或者视频的文件子类型[PhotoSubtype](arkts-apis-photoAccessHelper-e.md#photosubtype12)，当前仅支持DEFAULT。|

## PhotoAssetChangeInfo<sup>20+</sup>

媒体资产（图片/视频）信息。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称 |   类型   | 只读 |  可选 | 说明      |
| ---- | ------- | ---- |  ---- | ----- |
| uri       | string  | 否 | 否 | 媒体文件资源uri。 |
| mediaType | [PhotoType](arkts-apis-photoAccessHelper-e.md#phototype) | 否 | 否  | 媒体资产的类型（图片/视频）。 |
| albumUri  | string  | 否 | 否 | 媒体资产（图片/视频）所属相册的uri。  |

## PhotoAssetChangeData<sup>20+</sup>

媒体资产（图片/视频）的具体变更数据。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称     | 类型                | 只读 | 可选 | 说明  |
| ---- | ------- | ---- |  ---- | ----- |
| assetBeforeChange | [PhotoAssetChangeInfo](#photoassetchangeinfo20) \| null | 否 | 否 | 变更前的媒体资产（图片/视频）数据。如果是新增资产，assetBeforeChange为null。 |
| assetAfterChange  | [PhotoAssetChangeInfo](#photoassetchangeinfo20) \| null | 否 | 否  | 变更后的媒体资产（图片/视频）数据。如果是删除资产，assetAfterChange为null。 |
| isContentChanged  |boolean  | 否 | 否 | 媒体资产（图片/视频）内容是否变化。true表示文件内容发生变化，false表示文件内容未发生变化。  |
| isDeleted         |boolean  | 否 | 否 | 媒体资产（图片/视频）是否被删除。true表示资产被彻底删除，false表示资产未被彻底删除。  |

## PhotoAssetChangeInfos<sup>20+</sup>

媒体资产（图片/视频）的变更通知信息。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                   | 类型                | 只读 | 可选 | 说明    |
| ---- | ------- | ---- |  ---- | ----- |
| type       | [NotifyChangeType](arkts-apis-photoAccessHelper-e.md#notifychangetype20)  | 否 | 否 | 媒体资产（图片/视频）变更的通知类型。 |
| assetChangeDatas | [PhotoAssetChangeData](#photoassetchangedata20)[] \| null | 否 |  否 | 变更的媒体资产（图片/视频）数组。如果需要重新查询所有媒体资产，assetChangeDatas为null。  |
| isForRecheck    | boolean  | 否 | 否 | 应用是否应该重新查询所有媒体资产（图片/视频）信息。true表示需要重新查询所有资产，false表示无需查询所有资产。<br>**注意：** 在特殊情况或者异常通知的场景下，应用收到的isForRecheck为true，表示重新查询所有资产信息。  |

## AlbumChangeInfo<sup>20+</sup>

相册信息。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称  | 类型                | 只读 | 可选 | 说明                                              |
| ---- | ------- | ---- |  ---- | ----- |
| albumType | [AlbumType](arkts-apis-photoAccessHelper-e.md#albumtype)  | 否 | 否 | 相册类型。 |
| albumSubtype  | [AlbumSubtype](arkts-apis-photoAccessHelper-e.md#albumsubtype) | 否 | 否  | 相册子类型。 |
| albumName  | string  |否 |否 | 相册名。  |
| albumUri  | string  |否 |否 | 相册uri。  |
| imageCount  | number  |否 |否 | 相册中的图片数量。  |
| videoCount  | number  |否 |否 | 相册中的视频数量。  |
| count       | number  |否 |否 | 相册中的资产总数，包括图片和视频。  |
| coverUri  | string  |否 |否 | 相册封面资产的uri。  |

## AlbumChangeData<sup>20+</sup>

相册的具体变更数据。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                   | 类型                | 只读 | 可选 | 说明                |
| ---- | ------- | ---- |  ---- | ----- |
| albumBeforeChange | [AlbumChangeInfo](#albumchangeinfo20) \| null | 否 | 否 | 变更前的相册数据。如果是新增相册，albumBeforeChange为null。 |
| albumAfterChange  | [AlbumChangeInfo](#albumchangeinfo20) \| null | 否 | 否  | 变更后的相册数据。如果是删除相册，albumAfterChange为null。 |

## AlbumChangeInfos<sup>20+</sup>

相册的变更通知信息。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                   | 类型                | 只读 | 可选 | 说明           |
| ---- | ------- | ---- |  ---- | ----- |
| type       | [NotifyChangeType](arkts-apis-photoAccessHelper-e.md#notifychangetype20)  | 否 | 否 | 相册变更的通知类型。 |
| albumChangeDatas   | [AlbumChangeData](#albumchangedata20)[] \| null | 否 | 否 | 变更的相册数组。如果需要重新查询所有相册，albumChangeDatas为null。  |
| isForRecheck          | boolean  | 否 | 否 | 应用是否应该重新查询所有相册信息。true表示需要重新查询所有相册，false表示无需查询所有相册。<br>**注意：** 在特殊情况或者异常通知的场景下，应用收到的isForRecheck为true，表示重新查询所有相册信息。  |
