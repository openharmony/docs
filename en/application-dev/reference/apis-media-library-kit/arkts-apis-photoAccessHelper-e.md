# Enums
<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--SE: @liweilu1-->
<!--TSE: @xchaosioda-->

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xuchangda;@yixiaoff-->
<!--SE: @guxinggang;@liweilu1-->
<!--TSE: @wangbeibei;@xchaosioda-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## PhotoType

Enumerates the media file types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| IMAGE |  1 |  Image.|
| VIDEO |  2 |  Video.|

## PhotoSubtype<sup>12+</sup>

Enumerates the [PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md) types.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| DEFAULT |  0 |  Photo, which is the default type.|
| MOVING_PHOTO |  3 |  Moving photo.|
| BURST |  4 |  Burst photo.|

## DynamicRangeType<sup>12+</sup>

Enumerates the dynamic range types of media assets.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| SDR |  0 |  Standard dynamic range (SDR).|
| HDR |  1 |  High dynamic range (HDR). |

## AlbumType

Enumerates the album types.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name| Value   | Description     |
| --------| ---- | ------------|
| USER                | 0    | User album.  |
| SYSTEM              | 1024 | System album.|

## AlbumSubtype

Enumerate the album subtypes.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name    | Value         | Description  |
| ----- | ---------- | --- |
| USER\_GENERIC   | 1          | User album.|
| FAVORITE        | 1025       | Favorites.|
| VIDEO  | 1026       | Video album.|
| IMAGE<sup>12+</sup>               | 1031       | Photo album.|
| ANY    | 2147483647 | Any album.|

## PositionType<sup>16+</sup>

Enumerates the file locations.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| LOCAL |  1  |  Stored only on a local device.|
| CLOUD |  2  |  Stored only on the cloud.|
| LOCAL_AND_CLOUD |  3  |  Stored both on a local device and cloud.|

## PhotoKeys

Enumerates the keys available for image or video files.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name         | Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | 'uri'                 | URI of the file.<br>**NOTE**: Only the [DataSharePredicates.equalTo](../apis-arkdata/js-apis-data-dataSharePredicates.md#equalto10) predicate can be used for this field during photo query.<br>**Atomic service API**: This API can be used in atomic services since API version 20.           |
| PHOTO_TYPE    | 'media_type'           | Type of the file.<br>**Atomic service API**: This API can be used in atomic services since API version 20. |
| DISPLAY_NAME  | 'display_name'        | File name displayed. The specifications are as follows:<br>- The file name consists of a valid file name and an image or video file name extension.<br>- The file name cannot exceed 255 characters.<br>- The file name cannot contain any of the following characters:<br>- The title does not contain any of the following characters:.. \ / : * ? " ' ` < > \| { } [ ]<br>**Atomic service API**: This API can be used in atomic services since API version 20.     |
| SIZE          | 'size'                | File size, in bytes. The size of a moving photo includes the total size of the image and video.<br>**Atomic service API**: This API can be used in atomic services since API version 20.   |
| DATE_ADDED    | 'date_added'          | Unix timestamp when the file was created, in seconds.<br>**Atomic service API**: This API can be used in atomic services since API version 20.        |
| DATE_MODIFIED | 'date_modified'       | Unix timestamp when the file content (not the file name) was last modified, in seconds. This value is updated when the file content is modified, but not when the file name is modified.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| DURATION      | 'duration'            | Duration, in ms.<br>**Atomic service API**: This API can be used in atomic services since API version 20.           |
| WIDTH         | 'width'               | Image width, in pixels.<br>**Atomic service API**: This API can be used in atomic services since API version 20.                                   |
| HEIGHT        | 'height'              | Image height, in pixels.<br>**Atomic service API**: This API can be used in atomic services since API version 20.              |
| DATE_TAKEN    | 'date_taken'          | Unix timestamp when the photo was taken, in seconds.<br>**Atomic service API**: This API can be used in atomic services since API version 20.          |
| ORIENTATION   | 'orientation'         | Orientation of the file, in degrees.<br>**Atomic service API**: This API can be used in atomic services since API version 20. |
| FAVORITE      | 'is_favorite'            | Whether the file is marked as favorites.<br>**Atomic service API**: This API can be used in atomic services since API version 20.                |
| TITLE         | 'title'               | Title of the file.<br>**Atomic service API**: This API can be used in atomic services since API version 20.                |
| DATE_ADDED_MS<sup>12+</sup>  | 'date_added_ms'          | Unix timestamp when the file was created, in milliseconds.<br>**NOTE**: The photos queried cannot be sorted based on this field.<br>**Atomic service API**: This API can be used in atomic services since API version 20.     |
| DATE_MODIFIED_MS<sup>12+</sup>  | 'date_modified_ms'    | Unix timestamp when the file was modified, in milliseconds. This value is updated when the file content is modified, but not when the file name is modified.<br>**NOTE**: The photos queried cannot be sorted based on this field.<br>**Atomic service API**: This API can be used in atomic services since API version 20.          |
| PHOTO_SUBTYPE<sup>12+</sup>   | 'subtype'               | Subtype of the media file.<br>**Atomic service API**: This API can be used in atomic services since API version 20.    |
| DYNAMIC_RANGE_TYPE<sup>12+</sup>   | 'dynamic_range_type'               | Dynamic range type of the media asset.<br>**Atomic service API**: This API can be used in atomic services since API version 20.          |
| COVER_POSITION<sup>12+</sup>   | 'cover_position'               | Position of the moving photo cover, which is the video timestamp (in μs) corresponding to the cover frame.<br>**Atomic service API**: This API can be used in atomic services since API version 20.       |
| BURST_KEY<sup>12+</sup>   | 'burst_key'               | Unique ID of a group of burst photos.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| LCD_SIZE<sup>12+</sup>  | 'lcd_size'  | Width and height of an LCD image, in the format of a **width:height** string.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| THM_SIZE<sup>12+</sup>  | 'thm_size'  | Width and height of a thumbnail image, in the format of a **width:height** string.<br>**Atomic service API**: This API can be used in atomic services since API version 20.      |
| DETAIL_TIME<sup>13+</sup>  | 'detail_time'  | Detailed time. The value is a string of time when the image or video was taken in the time zone and does not change with the time zone.<br>**Atomic service API**: This API can be used in atomic services since API version 20.      |
| DATE_TAKEN_MS<sup>13+</sup>  | 'date_taken_ms'  | Unix timestamp when the image was captured, in milliseconds.<br>**Atomic service API**: This API can be used in atomic services since API version 20.  |
| POSITION<sup>16+</sup>  | 'position'            | File location type.<br>**Atomic service API**: This API can be used in atomic services since API version 20.       |
| MEDIA_SUFFIX<sup>18+</sup>  | 'media_suffix'            | File name extension.                              |

## AlbumKeys

Enumerates the album keys.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name         | Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | 'uri'                 | URI of the album.                                                  |
| ALBUM_NAME    | 'album_name'          | Name of the album.                                                  |

## ResourceType<sup>11+</sup>

Enumerates the types of the resources to write.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| IMAGE_RESOURCE |  1 |  Image resource.|
| VIDEO_RESOURCE |  2 |  Video resource.|

## ImageFileType<sup>13+</sup>

Enumerates the types of image files to save.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| JPEG  |  1 |  JPEG.|
| HEIF  |  2 |  HEIF.|

## NotifyType

Enumerates the notification event types.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                     | Value  | Description                            |
| ------------------------- | ---- | -------------------------------- |
| NOTIFY_ADD                | 0    | A file asset or album is added.    |
| NOTIFY_UPDATE             | 1    | A file asset or album is updated.    |
| NOTIFY_REMOVE             | 2    | A file asset or album is removed.    |
| NOTIFY_ALBUM_ADD_ASSET    | 3    | A file asset is added to the album.|
| NOTIFY_ALBUM_REMOVE_ASSET | 4    | A file asset is removed from the album.|

## DefaultChangeUri

Enumerates the **DefaultChangeUri** subtypes.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name             | Value                     | Description                                                        |
| ----------------- | ----------------------- | ------------------------------------------------------------ |
| DEFAULT_PHOTO_URI | 'file://media/Photo'      | Default **PhotoAsset** URI, which must be used with **forChildUris{true}** to subscribe to change notifications of all photo assets.|
| DEFAULT_ALBUM_URI | 'file://media/PhotoAlbum' | Default album URI, which must be used with **forChildUris{true}** to subscribe to change notifications of all albums.|

## PhotoViewMIMETypes

Enumerates the media file types.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                                   |  Value| Description      |
|---------------------------------------|  ---- |----------|
| IMAGE_TYPE                            |  'image/*' | Image.<br>**Atomic service API**: This API can be used in atomic services since API version 11.   |
| VIDEO_TYPE                            |  'video/*' | Video.<br>**Atomic service API**: This API can be used in atomic services since API version 11.   |
| IMAGE_VIDEO_TYPE                      |  '\*/*' | Image and video.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| MOVING_PHOTO_IMAGE_TYPE<sup>12+</sup> |  'image/movingPhoto' | Moving photo.<br>**Atomic service API**: This API can be used in atomic services since API version 12. |

## RecommendationType<sup>11+</sup>

Enumerates the types of recommended images.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- | ---- |
| QR_OR_BAR_CODE  |  1 | QR code or barcode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| QR_CODE |  2 | QR code.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| BAR_CODE |  3 | Barcode.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| ID_CARD |  4 | ID card.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| PROFILE_PICTURE |  5 | Profile.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| PASSPORT<sup>12+</sup> |  6 | Passport.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| BANK_CARD<sup>12+</sup> |  7 | Bank card.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| DRIVER_LICENSE<sup>12+</sup> |  8 | Driver license.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| DRIVING_LICENSE<sup>12+</sup> |  9 | Vehicle license.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| FEATURED_SINGLE_PORTRAIT<sup>12+</sup> |  10 | Recommended portrait.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

**Example**

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

Enumerates the single selection mode types.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                                   |  Value| Description      |
|---------------------------------------|  ---- |----------|
| BROWSER_MODE                          |  0 | Mode for previewing large images.   |
| SELECT_MODE                           |  1 | Mode for direct selection.   |
| BROWSER_AND_SELECT_MODE               |  2 | Compatibility mode. Tapping the bottom-right area enables direct selection, whereas tapping elsewhere switches to large image preview mode.|

## FilterOperator<sup>19+</sup>

Enumerates the operators that can be used for filtering.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| EQUAL_TO |  0 |  Equal to.|
| NOT_EQUAL_TO |  1 |  Not equal to.|
| MORE_THAN |  2 |  Greater than.|
| LESS_THAN |  3 |  Less than.|
| MORE_THAN_OR_EQUAL_TO |  4 |  Greater than or equal to.|
| LESS_THAN_OR_EQUAL_TO |  5 |  Less than or equal to.|
| BETWEEN |  6 |  Within the specified range.|

## DeliveryMode<sup>11+</sup>

Enumerates the asset delivery modes.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| FAST_MODE |  0 |  Fast mode.|
| HIGH_QUALITY_MODE |  1 |  High-quality mode.|
| BALANCE_MODE |  2 |  Balance mode.|

## CompatibleMode<sup>15+</sup>

Enumerates the compatible modes.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- | ---- | ---- |
| ORIGINAL_FORMAT_MODE |  0 |  Maintains the original video format. |
| COMPATIBLE_FORMAT_MODE    |  1 |  Converts the HDR content to SDR format.   |

## CompleteButtonText<sup>14+</sup>

Enumerates the text displayed on the complete button.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- | ---- | ---- |
| TEXT_DONE<sup>14+</sup> |  0 |  The text "Done" is displayed.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| TEXT_SEND<sup>14+</sup>    |  1 |  The text "Send" is displayed.<br>**Atomic service API**: This API can be used in atomic services since API version 14.|
| TEXT_ADD<sup>14+</sup> |  2 |  The text "Add" is displayed.<br>**Atomic service API**: This API can be used in atomic services since API version 14. |

## NotifyChangeType<sup>20+</sup>

Enumerates the types of changes that trigger the media asset or album change events.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                     | Value  | Description                            |
| ------------------------- | ---- | -------------------------------- |
| NOTIFY_CHANGE_ADD         | 0    | A media asset or an album is created.    |
| NOTIFY_CHANGE_UPDATE      | 1    | A media asset or an album is modified.    |
| NOTIFY_CHANGE_REMOVE      | 2    | A media asset or an album is deleted.    |

## PhotoSource<sup>20+</sup>

Enumerates the sources of the image or video data.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name               | Value  | Description                                                                                                                |
|-------------------|-----|--------------------------------------------------------------------------------------------------------------------|
| ALL | 0   | Images and videos from all sources.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| CAMERA | 1   | Photo or video taken by the camera.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
| SCREENSHOT | 2   | Screenshot or screen capture video.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|
