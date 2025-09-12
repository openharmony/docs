# Interfaces (Others)
<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## MediaChangeRequest<sup>11+</sup>

Media change request, which is the parent class of the asset change request and album change request.

> **NOTE**
>
> **MediaChangeRequest** takes effect only after [applyChanges](arkts-apis-photoAccessHelper-PhotoAccessHelper.md#applychanges11) is called.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

## CreateOptions

Options for creating an image or video asset.

The title must meet the following requirements:

- It must not contain a file name extension.
- The total length of the file name must be between 1 and 255 characters.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Mandatory| Description                                             |
| ---------------------- | ------------------- | ---- | ------------------------------------------------ |
| title                  | string                          | No | Title of the image or video.<br>**Atomic service API**: This API can be used in atomic services since API version 11. |
| subtype<sup>12+</sup>  | [PhotoSubtype](arkts-apis-photoAccessHelper-e.md#photosubtype12) | No | Subtype of the image or video file.<br>**Atomic service API**: This API can be used in atomic services since API version 12. |

## FetchOptions

Defines the retrieval options.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Read-Only| Optional| Description                                             |
| ---------------------- | ------------------- | ---- |---- | ------------------------------------------------ |
| fetchColumns           | Array&lt;string&gt; | No  | No  | Names of the columns specified for query.<br>If this parameter is left blank for photos, photos are fetched by **'uri'**, **'media_type'**, **'subtype'**, and **'display_name'** by default. An error will be thrown if [get](arkts-apis-photoAccessHelper-PhotoAsset.md#get) is used to obtain other attributes of this object. <br>Example: **fetchColumns: ['uri', 'title']**.<br>If this parameter is left blank for albums, albums are fetched by **'uri'** and **'album_name'** by default.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| predicates           | [dataSharePredicates.DataSharePredicates](../apis-arkdata/js-apis-data-dataSharePredicates.md#datasharepredicates) | No  | No  | Predicates that specify the fetch criteria.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

## RequestOptions<sup>11+</sup>

Represents request options.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type                       | Read-Only| Optional| Description                                        |
| ---------------------- |----------------------------| ---- | ---- | ------------------------------------------- |
| deliveryMode           | [DeliveryMode](arkts-apis-photoAccessHelper-e.md#deliverymode11) | No  | No  | Delivery mode of the requested asset. The value can be **FAST_MODE**, **HIGH_QUALITY_MODE**, or **BALANCE_MODE**.|
| compatibleMode<sup>15+</sup>      | [CompatibleMode](arkts-apis-photoAccessHelper-e.md#compatiblemode15) | No  | Yes  | HDR video transcoding policy, which can be **FAST_ORIGINAL_FORMAT_MODE** (maintaining the original HDR format) or **COMPATIBLE_FORMAT_MODE** (converting HDR content to SDR format). The default value is **FAST_ORIGINAL_FORMAT_MODE**.|
| mediaAssetProgressHandler<sup>15+</sup> | [MediaAssetProgressHandler](arkts-apis-photoAccessHelper-MediaAssetProgressHandler.md) | No  | Yes  | Callback used to return the HDR-to-SDR conversion progress.|

## ChangeData

Defines the return value of the listener callback.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name   | Type                       | Read-Only| Optional| Description                                                        |
| ------- | --------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type    | [NotifyType](arkts-apis-photoAccessHelper-e.md#notifytype) | No  | No  | Notification type.                                      |
| uris    | Array&lt;string&gt;         | No  | No  | All URIs with the same [NotifyType](arkts-apis-photoAccessHelper-e.md#notifytype), which can be **PhotoAsset** or **Album**.|
| extraUris | Array&lt;string&gt;         | No  | No  | URIs of the changed files in the album. The value may be undefined. Check whether the value is undefined before using it.                          |

## TextContextInfo<sup>12+</sup>

Represents the text information about the recommended images.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                   | Type               | Mandatory| Description                         |
| ----------------------- | ------------------- | ---- | -------------------------------- |
| text | string   | No  | Text based on which images are recommended. The text cannot exceed 250 characters. The default value is an empty string.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let textInfo: photoAccessHelper.TextContextInfo = {
      text: 'Pandas at Shanghai Wild Zoo'
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

Represents the configuration for saving a media asset (image or video) to the media library, including the file name.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Mandatory| Description                                             |
| ---------------------- | ------------------- | ---- | ------------------------------------------------ |
| title | string | No | Title of the image or video. If this parameter is not passed, the system generates a title. The title must meet the following requirements:<br>- It must not contain a file name extension.<br>- The total length of the file name, which is in the format of title+file name extension, must be between 1 and 255 characters.<br>- It must not contain any invalid characters, which are:\ / : * ? " ' ` < > \| { } [ ]|
| fileNameExtension | string | Yes | File name extension, for example, **'jpg'**.|
| photoType | [PhotoType](arkts-apis-photoAccessHelper-e.md#phototype) | Yes | Type of the file to create, which can be **IMAGE** or **VIDEO**. See [PhotoType](arkts-apis-photoAccessHelper-e.md#phototype).|
| subtype | [PhotoSubtype](arkts-apis-photoAccessHelper-e.md#photosubtype12) | No | Image or video file subtype. Currently, only **DEFAULT** is supported. See [PhotoSubtype](arkts-apis-photoAccessHelper-e.md#photosubtype12).|

## PhotoAssetChangeInfo<sup>20+</sup>

Describes the information about a media asset.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name|   Type  | Read-Only|  Optional| Description     |
| ---- | ------- | ---- |  ---- | ----- |
| uri       | string  | No| No| URI of the media asset.|
| mediaType | [PhotoType](arkts-apis-photoAccessHelper-e.md#phototype) | No| No | Type of the media asset (image or video).|
| albumUri  | string  | No| No| URI of the album that the media asset belongs to. |

## PhotoAssetChangeData<sup>20+</sup>

Describes the detailed change data of a media asset.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name    | Type               | Read-Only| Optional| Description |
| ---- | ------- | ---- |  ---- | ----- |
| assetBeforeChange | [PhotoAssetChangeInfo](#photoassetchangeinfo20) \| null | No| No| Data of the media asset before change. In the case of asset addition, **assetBeforeChange** is null.|
| assetAfterChange  | [PhotoAssetChangeInfo](#photoassetchangeinfo20) \| null | No| No | Data of the media asset after change. In the case of asset deletion, **assetAfterChange** is null.|
| isContentChanged  |boolean  | No| No| Whether the content of the media asset is changed. **true** if changed, **false** otherwise. |
| isDeleted         |boolean  | No| No| Whether the media asset is deleted. **true** if deleted, **false** otherwise. |

## PhotoAssetChangeInfos<sup>20+</sup>

Describes the notification information about the change of a media asset.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Read-Only| Optional| Description   |
| ---- | ------- | ---- |  ---- | ----- |
| type       | [NotifyChangeType](arkts-apis-photoAccessHelper-e.md#notifychangetype20)  | No| No| Type of the media asset change.|
| assetChangeDatas | [PhotoAssetChangeData](#photoassetchangedata20)[] \| null | No|  No| Array of changed media assets. If all media assets need to be queried again, **assetChangeDatas** is null. |
| isForRecheck    | boolean  | No| No| Whether the application should query all media assets again. **true** if the application should query all assets again, **false** otherwise.<br>**NOTE**: In special cases or abnormal notification scenarios, **isForRecheck** will be **true**. In this case, the application should query all assets again. |

## AlbumChangeInfo<sup>20+</sup>

Describes the album information.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name | Type               | Read-Only| Optional| Description                                             |
| ---- | ------- | ---- |  ---- | ----- |
| albumType | [AlbumType](arkts-apis-photoAccessHelper-e.md#albumtype)  | No| No| Type of the album.|
| albumSubtype  | [AlbumSubtype](arkts-apis-photoAccessHelper-e.md#albumsubtype) | No| No | Subtype of the album.|
| albumName  | string  |No|No| Album name. |
| albumUri  | string  |No|No| URI of the album. |
| imageCount  | number  |No|No| Number of images in the album. |
| videoCount  | number  |No|No| Number of videos in the album. |
| count       | number  |No|No| Total number of assets in the album, including images and videos. |
| coverUri  | string  |No|No| URI of the album cover asset. |

## AlbumChangeData<sup>20+</sup>

Describes the detailed change data of an album.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Read-Only| Optional| Description               |
| ---- | ------- | ---- |  ---- | ----- |
| albumBeforeChange | [AlbumChangeInfo](#albumchangeinfo20) \| null | No| No| Data of the album before change. If an album is added, **albumBeforeChange** is null.|
| albumAfterChange  | [AlbumChangeInfo](#albumchangeinfo20) \| null | No| No | Data of the album after change. In the case of album deletion, **albumAfterChange** is null.|

## AlbumChangeInfos<sup>20+</sup>

Describes the notification information about the change of an album.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Read-Only| Optional| Description          |
| ---- | ------- | ---- |  ---- | ----- |
| type       | [NotifyChangeType](arkts-apis-photoAccessHelper-e.md#notifychangetype20)  | No| No| Type of the album change.|
| albumChangeDatas   | [AlbumChangeData](#albumchangedata20)[] \| null | No| No| Array of changed albums. If all albums need to be queried again, **albumChangeDatas** is null. |
| isForRecheck          | boolean  | No| No| Whether the application should query all albums again. **true** if the application should query all albums again, **false** otherwise.<br>**NOTE**: In special cases or abnormal notification scenarios, **isForRecheck** will be **true**. In this case, the application should query all albums again. |
