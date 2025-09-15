# media_asset_base_capi.h

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the structs and enums for the media asset manager.

**Library**: libmedia_asset_manager.so

**File to include**: <multimedia/media_library/media_asset_base_capi.h>

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Since**: 12

**Related module**: [MediaAssetManager](capi-mediaassetmanager.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md) | MediaLibrary_RequestId | Describes a request ID.<br>A value of this type is returned when a media asset is requested.<br>The request ID can be used to cancel a request.|
| [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md) | OH_MediaAssetManager | Describes the media asset manager.<br>You can use this struct to create a media asset manager instance.<br>If the creation fails, nullptr is returned.|
| [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md) | OH_MediaAssetChangeRequest | Describes a media asset change request.<br>This struct provides the capability of handling media asset change requests.|
| [OH_MovingPhoto](capi-mediaassetmanager-oh-movingphoto.md) | OH_MovingPhoto | Describes a moving photo.<br>This struct provides the capability of obtaining information about a moving photo.|
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) | OH_MediaAsset | Describes a media asset.<br>This struct provides the capability of encapsulating media file attributes.|
| [MediaLibrary_RequestOptions](capi-mediaassetmanager-medialibrary-requestoptions.md) | MediaLibrary_RequestOptions | Defines how media assets are requested and processed.<br>You can use this struct to set options related to the media asset quality, delivery mode, and more.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) | MediaLibrary_ErrorCode | Enumerates the error codes of the media library.|
| [MediaLibrary_DeliveryMode](#medialibrary_deliverymode) | MediaLibrary_DeliveryMode | Enumerates the delivery modes of the requested media asset.|
| [MediaLibrary_MediaType](#medialibrary_mediatype) | MediaLibrary_MediaType | Enumerates the media asset types.|
| [MediaLibrary_MediaSubType](#medialibrary_mediasubtype) | MediaLibrary_MediaSubType | Enumerates the media asset subtypes.|
| [MediaLibrary_ResourceType](#medialibrary_resourcetype) | MediaLibrary_ResourceType | Enumerates the media library resource types.|
| [MediaLibrary_ImageFileType](#medialibrary_imagefiletype) | MediaLibrary_ImageFileType | Enumerates the image file types.|
| [MediaLibrary_MediaQuality](#medialibrary_mediaquality) | MediaLibrary_MediaQuality | Enumerates the media resource quality, which varies with the specified delivery mode for the requested media asset.|
| [MediaLibrary_MediaContentType](#medialibrary_mediacontenttype) | MediaLibrary_MediaContentType | Enumerates the media content types.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_MediaLibrary_OnDataPrepared)(int32_t result, MediaLibrary_RequestId requestId)](#oh_medialibrary_ondataprepared) | OH_MediaLibrary_OnDataPrepared | Called when the requested media asset is ready.|
| [typedef void (\*OH_MediaLibrary_OnImageDataPrepared)(MediaLibrary_ErrorCode result, MediaLibrary_RequestId requestId, MediaLibrary_MediaQuality mediaQuality, MediaLibrary_MediaContentType type,OH_ImageSourceNative* imageSourceNative)](#oh_medialibrary_onimagedataprepared) | OH_MediaLibrary_OnImageDataPrepared | Called when the requested image is ready.|
| [typedef void (\*OH_MediaLibrary_OnMovingPhotoDataPrepared)(MediaLibrary_ErrorCode result, MediaLibrary_RequestId requestId, MediaLibrary_MediaQuality mediaQuality, MediaLibrary_MediaContentType type, OH_MovingPhoto* movingPhoto)](#oh_medialibrary_onmovingphotodataprepared) | OH_MediaLibrary_OnMovingPhotoDataPrepared | Called when the requested moving photo is ready.|

### Variables

| Name| Description|
| -- | -- |
| static const int32_t UUID_STR_MAX_LENGTH = 37 | Maximum length of a request ID.  <br>**Since**: 12|

## Enum Description

### MediaLibrary_ErrorCode

```
enum MediaLibrary_ErrorCode
```

**Description**

Enumerates the error codes of the media library.

**Since**: 12

| Enum| Description|
| -- | -- |
| MEDIA_LIBRARY_OK = 0 | Operation success.|
| MEDIA_LIBRARY_PERMISSION_DENIED = 201 | No access permission.|
| MEDIA_LIBRARY_PARAMETER_ERROR = 401 | A mandatory parameter is not specified, the parameter type is incorrect, or parameter verification failed.|
| MEDIA_LIBRARY_NO_SUCH_FILE = 23800101 | The file does not exist.|
| MEDIA_LIBRARY_INVALID_DISPLAY_NAME = 23800102 | Invalid display name.|
| MEDIA_LIBRARY_INVALID_ASSET_URI = 23800103 | Invalid asset URI.|
| MEDIA_LIBRARY_INVALID_PHOTO_KEY = 23800104 | Invalid PhotoKey.|
| MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED = 23800201 | Unsupported operation.|
| MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR = 23800301 | Internal system error. Retry the operation and check logs. Possible causes:<br>1. The database is corrupted.<br>2. The file system is abnormal.<br>3. The IPC request timed out.|

### MediaLibrary_DeliveryMode

```
enum MediaLibrary_DeliveryMode
```

**Description**

Enumerates the delivery modes of the requested media asset.

**MEDIA_LIBRARY_FAST_MODE**: Deliver the media asset available without considering its quality.

**MEDIA_LIBRARY_HIGH_QUALITY_MODE**: Deliver a media asset with high quality. If there is no high-quality asset available, trigger the process for creating a high-quality asset. Then, return the high-quality asset that is successfully created.

**MEDIA_LIBRARY_BALANCED_MODE**: Return the high-quality asset if there is any. Otherwise, return a low-quality asset first and trigger the process for creating a high-quality asset. Then, return the high-quality asset that is successfully created.

**Since**: 12

| Enum| Description|
| -- | -- |
| MEDIA_LIBRARY_FAST_MODE = 0 | Fast mode.|
| MEDIA_LIBRARY_HIGH_QUALITY_MODE = 1 | High-quality mode.|
| MEDIA_LIBRARY_BALANCED_MODE = 2 | Balance mode.|

### MediaLibrary_MediaType

```
enum MediaLibrary_MediaType
```

**Description**

Enumerates the media asset types.

**Since**: 12

| Enum| Description|
| -- | -- |
| MEDIA_LIBRARY_IMAGE = 1 | Image.|
| MEDIA_LIBRARY_VIDEO = 2 | Video.|

### MediaLibrary_MediaSubType

```
enum MediaLibrary_MediaSubType
```

**Description**

Enumerates the media asset subtypes.

**Since**: 12

| Enum| Description|
| -- | -- |
| MEDIA_LIBRARY_DEFAULT = 0 | Photo, which is the default type.|
| MEDIA_LIBRARY_MOVING_PHOTO = 3 | Moving photo.|
| MEDIA_LIBRARY_BURST = 4 | Burst photo.|

### MediaLibrary_ResourceType

```
enum MediaLibrary_ResourceType
```

**Description**

Enumerates the media library resource types.

**Since**: 12

| Enum| Description|
| -- | -- |
| MEDIA_LIBRARY_IMAGE_RESOURCE = 1 | Image resource.|
| MEDIA_LIBRARY_VIDEO_RESOURCE = 2 | Video resource.|

### MediaLibrary_ImageFileType

```
enum MediaLibrary_ImageFileType
```

**Description**

Enumerates the image file types.

**Since**: 12

| Enum| Description|
| -- | -- |
| MEDIA_LIBRARY_IMAGE_JPEG = 1 | JPEG.|
| MEDIA_LIBRARY_FILE_VIDEO = 3 | MPEG type.<br>**Since**: 19|

### MediaLibrary_MediaQuality

```
enum MediaLibrary_MediaQuality
```

**Description**

Enumerates the media resource quality,

which varies with the specified delivery mode for the requested media asset.

**MEDIA_LIBRARY_FAST_MODE**: Deliver the media asset available without considering its quality.

**MEDIA_LIBRARY_HIGH_QUALITY_MODE**: Deliver a media asset with high quality. If there is no high-quality asset available, trigger the process for creating a high-quality asset. Then, return the high-quality asset that is successfully created.

**MEDIA_LIBRARY_BALANCED_MODE**: Return the high-quality asset if there is any. Otherwise, return a low-quality asset first and trigger the process for creating a high-quality asset. Then, return the high-quality asset that is successfully created.

**Since**: 12

| Enum| Description|
| -- | -- |
| MEDIA_LIBRARY_QUALITY_FAST = 1 | Media asset available without considering its quality.|
| MEDIA_LIBRARY_QUALITY_FULL = 2 | High-quality media asset.|

### MediaLibrary_MediaContentType

```
enum MediaLibrary_MediaContentType
```

**Description**

Enumerates the media content types.

**Since**: 12

| Enum| Description|
| -- | -- |
| MEDIA_LIBRARY_COMPRESSED = 1 | Compressed media content.|
| MEDIA_LIBRARY_PICTURE_OBJECT = 2 | Image object.|


## Function Description

### OH_MediaLibrary_OnDataPrepared()

```
typedef void (*OH_MediaLibrary_OnDataPrepared)(int32_t result, MediaLibrary_RequestId requestId)
```

**Description**

Called when the requested media asset is ready.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t result | Request processing result.|
|  MediaLibrary_RequestId requestId | Request ID.|

### OH_MediaLibrary_OnImageDataPrepared()

```
typedef void (*OH_MediaLibrary_OnImageDataPrepared)(MediaLibrary_ErrorCode result,MediaLibrary_RequestId requestId, MediaLibrary_MediaQuality mediaQuality, MediaLibrary_MediaContentType type,OH_ImageSourceNative* imageSourceNative)
```

**Description**

Called when the requested image is ready.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) result | Request processing result, which is specified by [MediaLibrary_ErrorCode](#medialibrary_errorcode).|
| [MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md) requestId | Request ID, which is specified by [MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md).|
|  [MediaLibrary_MediaQuality](#medialibrary_mediaquality) mediaQuality | Quality of the requested source, which is specified by [MediaLibrary_MediaQuality](#medialibrary_mediaquality).|
|  [MediaLibrary_MediaContentType](capi-media-asset-base-capi-h.md#medialibrary_mediacontenttype) type | Media content type of the requested source, which is specified by [MediaLibrary_MediaContentType](capi-media-asset-base-capi-h.md#medialibrary_mediacontenttype).|
| [OH_ImageSourceNative](../apis-image-kit/capi-image-nativemodule-oh-imagesourcenative.md)* imageSourceNative | Pointer to the [OH_ImageSourceNative](../apis-image-kit/capi-image-nativemodule-oh-imagesourcenative.md) instance obtained when the requested image is ready.|

### OH_MediaLibrary_OnMovingPhotoDataPrepared()

```
typedef void (*OH_MediaLibrary_OnMovingPhotoDataPrepared)(MediaLibrary_ErrorCode result,MediaLibrary_RequestId requestId, MediaLibrary_MediaQuality mediaQuality, MediaLibrary_MediaContentType type,OH_MovingPhoto* movingPhoto)
```

**Description**

Called when the requested moving photo is ready.

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) result | Request processing result, which is specified by [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode).|
| [MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md) requestId | Request ID, which is specified by [MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md).|
|  [MediaLibrary_MediaQuality](#medialibrary_mediaquality) mediaQuality | Quality of the requested resource, which is specified by [MediaLibrary_MediaQuality](#medialibrary_mediaquality).|
|  [MediaLibrary_MediaContentType](capi-media-asset-base-capi-h.md#medialibrary_mediacontenttype) type | Media content type of the requested resource, which is specified by [MediaLibrary_MediaContentType](capi-media-asset-base-capi-h.md#medialibrary_mediacontenttype).|
| [OH_MovingPhoto](capi-mediaassetmanager-oh-movingphoto.md)* movingPhoto | Pointer to the [OH_MovingPhoto](capi-mediaassetmanager-oh-movingphoto.md) instance obtained when the requested moving photo is ready.|
