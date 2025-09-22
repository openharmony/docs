# Enums
<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## PhotoType

枚举，媒体文件类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称  |  值 |  说明 |
| ----- |  ---- |  ---- |
| IMAGE |  1 |  图片。 |
| VIDEO |  2 |  视频。 |

## PhotoSubtype<sup>12+</sup>

PhotoSubtype是不同[PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)类型的枚举。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称  |  值 |  说明 |
| ----- |  ---- |  ---- |
| DEFAULT |  0 |  默认照片类型。 |
| MOVING_PHOTO |  3 |  动态照片文件类型。 |
| BURST |  4 |  连拍照片文件类型。 |

## DynamicRangeType<sup>12+</sup>

枚举，媒体文件的动态范围类型。

**系统能力**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称  |  值 |  说明 |
| ----- |  ---- |  ---- |
| SDR |  0 |  标准动态范围类型。|
| HDR |  1 |  高动态范围类型。  |

## AlbumType

枚举，相册类型，表示是用户相册还是系统预置相册。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称 | 值    | 说明      |
| --------| ---- | ------------|
| USER                | 0    | 用户相册。   |
| SYSTEM              | 1024 | 系统预置相册。 |

## AlbumSubtype

枚举，相册子类型，表示具体的相册类型。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称     | 值          | 说明   |
| ----- | ---------- | --- |
| USER\_GENERIC   | 1          | 用户相册。|
| FAVORITE        | 1025       | 收藏夹。 |
| VIDEO  | 1026       | 视频相册。|
| IMAGE<sup>12+</sup>               | 1031       | 图片相册。|
| ANY    | 2147483647 | 任意相册。|

## PositionType<sup>16+</sup>

枚举，文件位置，表示文件在本地或云端。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称  |  值 |  说明 |
| ----- |  ---- |  ---- |
| LOCAL |  1  |  文件只存在于本端设备。 |
| CLOUD |  2  |  文件只存在于云端。 |
| LOCAL_AND_CLOUD |  3  |  文件存在于本端设备和云端。 |

## PhotoKeys

枚举，图片和视频文件关键信息。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称          | 值              | 说明                                                       |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | 'uri'                 | 文件uri。<br>**注意：** 查询照片时，该字段仅支持使用[DataSharePredicates.equalTo](../apis-arkdata/js-apis-data-dataSharePredicates.md#equalto10)谓词。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。            |
| PHOTO_TYPE    | 'media_type'           | 媒体文件类型。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。  |
| DISPLAY_NAME  | 'display_name'        | 显示名字。规格为：<br>- 应包含有效文件主名和图片或视频扩展名。<br>- 文件名字符串长度为1~255。<br>- 文件主名中不允许出现的非法英文字符，包括：. .. \ / : * ? " ' ` < > \| { } [ ]。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。      |
| SIZE          | 'size'                | 文件大小（单位：字节）。动态照片的size包括图片和视频的总大小。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。    |
| DATE_ADDED    | 'date_added'          | 文件创建时的Unix时间戳（单位：秒）。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。         |
| DATE_MODIFIED | 'date_modified'       | 文件修改时的Unix时间戳（单位：秒）。修改文件名不会改变此值，当文件内容发生修改时才会更新。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| DURATION      | 'duration'            | 持续时间（单位：毫秒）。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。            |
| WIDTH         | 'width'               | 图片宽度（单位：像素）。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。                                    |
| HEIGHT        | 'height'              | 图片高度（单位：像素）。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。               |
| DATE_TAKEN    | 'date_taken'          | 拍摄时的Unix时间戳（单位：秒）。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。           |
| ORIENTATION   | 'orientation'         | 文件的旋转角度，单位为度。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。  |
| FAVORITE      | 'is_favorite'            | 收藏。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。                 |
| TITLE         | 'title'               | 文件标题。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。                 |
| DATE_ADDED_MS<sup>12+</sup>  | 'date_added_ms'          | 文件创建时的Unix时间戳（单位：毫秒）。<br>**注意：**查询照片时，不支持基于该字段排序。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。      |
| DATE_MODIFIED_MS<sup>12+</sup>  | 'date_modified_ms'    | 文件修改时的Unix时间戳（单位：毫秒）。修改文件名不会改变此值，当文件内容发生修改时才会更新。<br>**注意：**查询照片时，不支持基于该字段排序。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。           |
| PHOTO_SUBTYPE<sup>12+</sup>   | 'subtype'               | 媒体文件的子类型。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。     |
| DYNAMIC_RANGE_TYPE<sup>12+</sup>   | 'dynamic_range_type'               | 媒体文件的动态范围类型。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。           |
| COVER_POSITION<sup>12+</sup>   | 'cover_position'               | 动态照片的封面位置，具体表示封面帧所对应的视频时间戳（单位：微秒）。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。        |
| BURST_KEY<sup>12+</sup>   | 'burst_key'               | 一组连拍照片的唯一标识：uuid。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| LCD_SIZE<sup>12+</sup>  | 'lcd_size'  | LCD图片的宽高，值为width:height拼接而成的字符串。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。|
| THM_SIZE<sup>12+</sup>  | 'thm_size'  | THUMB图片的宽高，值为width:height拼接而成的字符串。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。       |
| DETAIL_TIME<sup>13+</sup>  | 'detail_time'  | 大图浏览时间，值为拍摄时对应时区的时间的字符串，不会跟随时区变化。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。       |
| DATE_TAKEN_MS<sup>13+</sup>  | 'date_taken_ms'  | 拍摄时的Unix时间戳（单位：毫秒）。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。   |
| POSITION<sup>16+</sup>  | 'position'            | 文件位置类型。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。        |
| MEDIA_SUFFIX<sup>18+</sup>  | 'media_suffix'            | 文件的后缀名。                               |

## AlbumKeys

枚举，相册关键信息。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称          | 值              | 说明                                                       |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | 'uri'                 | 相册uri。                                                   |
| ALBUM_NAME    | 'album_name'          | 相册名字。                                                   |

## ResourceType<sup>11+</sup>

枚举，写入资源的类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称  |  值 |  说明 |
| ----- |  ---- |  ---- |
| IMAGE_RESOURCE |  1 |  表示图片资源。 |
| VIDEO_RESOURCE |  2 |  表示视频资源。 |

## ImageFileType<sup>13+</sup>

枚举，图片保存类型。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称  |  值 |  说明 |
| ----- |  ---- |  ---- |
| JPEG  |  1 |  表示jpeg图片类型。 |
| HEIF  |  2 |  表示heif图片类型。 |

## NotifyType

枚举，通知事件的类型。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                      | 值   | 说明                             |
| ------------------------- | ---- | -------------------------------- |
| NOTIFY_ADD                | 0    | 添加文件集或相册通知的类型。     |
| NOTIFY_UPDATE             | 1    | 文件集或相册的更新通知类型。     |
| NOTIFY_REMOVE             | 2    | 删除文件集或相册的通知类型。     |
| NOTIFY_ALBUM_ADD_ASSET    | 3    | 在相册中添加的文件集的通知类型。 |
| NOTIFY_ALBUM_REMOVE_ASSET | 4    | 在相册中删除的文件集的通知类型。 |

## DefaultChangeUri

枚举，DefaultChangeUri子类型。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称              | 值                      | 说明                                                         |
| ----------------- | ----------------------- | ------------------------------------------------------------ |
| DEFAULT_PHOTO_URI | 'file://media/Photo'      | 默认PhotoAsset的uri，与forSubUri{true}一起使用，将接收所有PhotoAsset的更改通知。 |
| DEFAULT_ALBUM_URI | 'file://media/PhotoAlbum' | 默认相册的uri，与forSubUri{true}一起使用，将接收所有相册的更改通知。 |

## PhotoViewMIMETypes

枚举，可选择的媒体文件类型。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                                    |  值 | 说明       |
|---------------------------------------|  ---- |----------|
| IMAGE_TYPE                            |  'image/*' | 图片类型。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。    |
| VIDEO_TYPE                            |  'video/*' | 视频类型。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。    |
| IMAGE_VIDEO_TYPE                      |  '\*/*' | 图片和视频类型。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| MOVING_PHOTO_IMAGE_TYPE<sup>12+</sup> |  'image/movingPhoto' | 动态照片类型。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。  |

## RecommendationType<sup>11+</sup>

枚举，推荐的图片类型。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称  |  值 |  说明 |
| ----- |  ---- | ---- |
| QR_OR_BAR_CODE  |  1 | 二维码或条码。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| QR_CODE |  2 | 二维码。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| BAR_CODE |  3 | 条码。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| ID_CARD |  4 | 身份证。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| PROFILE_PICTURE |  5 | 头像。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| PASSPORT<sup>12+</sup> |  6 | 护照。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| BANK_CARD<sup>12+</sup> |  7 | 银行卡。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| DRIVER_LICENSE<sup>12+</sup> |  8 | 驾驶证。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| DRIVING_LICENSE<sup>12+</sup> |  9 | 行驶证。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| FEATURED_SINGLE_PORTRAIT<sup>12+</sup> |  10 | 推荐人像。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let recommendOptions: photoAccessHelper.RecommendationOptions = {
      recommendationType: photoAccessHelper.RecommendationType.ID_CARD
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

## SingleSelectionMode<sup>18+</sup>

枚举，单选模式类型。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                                    |  值 | 说明       |
|---------------------------------------|  ---- |----------|
| BROWSER_MODE                          |  0 | 大图预览模式。    |
| SELECT_MODE                           |  1 | 直接选中模式。    |
| BROWSER_AND_SELECT_MODE               |  2 | 兼容模式，点击右下角区域为直接选中模式，点击其他区域进入大图预览模式。 |

## FilterOperator<sup>19+</sup>

枚举，支持进行过滤的操作符。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称  |  值 |  说明 |
| ----- |  ---- |  ---- |
| EQUAL_TO |  0 |  等于。 |
| NOT_EQUAL_TO |  1 |  不等于。 |
| MORE_THAN |  2 |  大于。 |
| LESS_THAN |  3 |  小于。 |
| MORE_THAN_OR_EQUAL_TO |  4 |  大于等于。 |
| LESS_THAN_OR_EQUAL_TO |  5 |  小于等于。 |
| BETWEEN |  6 |  在指定范围内。 |

## DeliveryMode<sup>11+</sup>

枚举，资源分发模式。

该模式适用于分段式拍照或分段式视频。如果当前设备不具备分段式能力，则以下三种分发模式无区别，直接返回请求的图片或视频资源。请求的结果通过[onDataPrepared](./arkts-apis-photoAccessHelper-MediaAssetDataHandler.md#ondataprepared11)回调返回。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称  |  值 |  说明 |
| ----- |  ---- |  ---- |
| FAST_MODE |  0 |  快速模式。<br>针对分段式拍照或视频场景，若当前存在高质量图或视频，则立即返回高质量图或视频的请求结果回调；若当前存在低质量图或视频，则立即返回低质量图或视频的请求结果回调。 |
| HIGH_QUALITY_MODE |  1 |  高质量模式。<br>针对分段式拍照或视频场景，若当前存在高质量图或视频，则立即返回高质量图或视频的请求结果回调；若当前存在低质量图或视频，则申请高质量图或视频的生成任务，待高质量图或视频生成后，返回高质量图或视频的请求结果回调。 |
| BALANCE_MODE |  2 |  均衡模式。<br>- 针对分段式拍照场景，若当前存在高质量图，则立即返回高质量图的请求结果回调；若当前存在低质量图，则立即返回低质量图的请求结果回调，并申请高质量图生成任务，待高质量图生成后，再次返回高质量图的请求结果回调。<br>- 针对分段式视频场景，若当前存在高质量视频，则立即返回高质量视频的请求结果回调；若当前存在低质量视频，则立即返回低质量视频的请求结果回调。 |

## CompatibleMode<sup>15+</sup>

配置转码模式。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称  |  值 |  说明 |
| ----- | ---- | ---- |
| ORIGINAL_FORMAT_MODE |  0 |  原视频资源内容模式。  |
| COMPATIBLE_FORMAT_MODE    |  1 |  兼容模式，从HDR视频资源转换为SDR视频资源。    |

## CompleteButtonText<sup>14+</sup>

配置完成按钮显示内容。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称  |  值 |  说明 |
| ----- | ---- | ---- |
| TEXT_DONE<sup>14+</sup> |  0 |  显示“完成”。 <br>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。 |
| TEXT_SEND<sup>14+</sup>    |  1 |  显示“发送”。 <br>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。 |
| TEXT_ADD<sup>14+</sup> |  2 |  显示“添加”。<br>**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。  |

## NotifyChangeType<sup>20+</sup>

枚举，媒体资产（图片/视频）或相册变更事件的通知类型。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                      | 值   | 说明                             |
| ------------------------- | ---- | -------------------------------- |
| NOTIFY_CHANGE_ADD         | 0    | 媒体资产（图片/视频）或相册已经创建。     |
| NOTIFY_CHANGE_UPDATE      | 1    | 媒体资产（图片/视频）或相册已经修改。     |
| NOTIFY_CHANGE_REMOVE      | 2    | 媒体资产（图片/视频）或相册已经删除。     |

## PhotoSource<sup>20+</sup>

枚举，图片或者视频数据的来源类型。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称                | 值   | 说明                                                                                                                 |
|-------------------|-----|--------------------------------------------------------------------------------------------------------------------|
| ALL | 0   | 所有来源的图片、视频。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| CAMERA | 1   | 仅相机拍摄的图片、视频。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |
| SCREENSHOT | 2   | 截屏图片或者录屏视频。<br>**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。 |

## HdrMode<sup>21+</sup>

枚举，图片的HDR类型。

| 名称  |  值 |  说明 |
| ----- |  ---- |  ---- |
| DEFAULT |  0 |  默认类型。|
| HDR_ISO_SINGLE |  1 |  单层HDR技术。  |
| HDR_ISO_DUAL |  2 |  单层HDR技术。  |
| HDR_CUVA |  3 |  中国超高清视频产业联盟HDR标准。  |
| HDR_VIVID_SINGLE |  4 |  单层HDR VIVID技术。  |
| HDR_VIVID_DUAL |  5 |  单层HDR VIVID技术。  |
