# MediaAssetManager


## Overview

Provides APIs for requesting media library assets.

**Since**: 12


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [media_access_helper_capi.h](media__access__helper__capi_8h.md) | Defines the APIs for album management.|
| [media_asset_base_capi.h](media__asset__base__capi_8h.md) | Defines the structs and enums of the media asset manager.|
| [media_asset_capi.h](media__asset__capi_8h.md) | Defines the APIs related to media assets. |
| [media_asset_change_request_capi.h](media__asset__change__request__capi_8h.md) | Defines the APIs related to media asset change requests. |
| [media_asset_manager_capi.h](media__asset__manager__capi_8h.md) | Defines the functions of the media asset manager.|


### Structs

| Name| Description|
| -------- | -------- |
| struct  [MediaLibrary_RequestId](_media_library___request_id.md) | Defines a request ID.|
| struct  [MediaLibrary_RequestOptions](_media_library___request_options.md) | Defines the options related to the media asset quality and delivery mode to set.|


### Types

| Name| Description|
| -------- | -------- |
| typedef struct [OH_MediaAssetManager](#oh_mediaassetmanager) [OH_MediaAssetManager](#oh_mediaassetmanager) | Defines a struct for the media asset manager.|
| typedef struct [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) | Defines a struct for a media asset change request.|
| typedef struct [OH_MediaAsset](#oh_mediaasset) [OH_MediaAsset](#oh_mediaasset) | Defines a struct for a media asset.|
| typedef struct [MediaLibrary_RequestId](_media_library___request_id.md) [MediaLibrary_RequestId](#medialibrary_requestid) | Defines a struct for a request ID. |
| typedef enum [MediaLibrary_ErrorCode](#medialibrary_errorcode-1) [MediaLibrary_ErrorCode](#medialibrary_errorcode) | Defines an enum for error codes.|
| typedef enum [MediaLibrary_DeliveryMode](#medialibrary_deliverymode-1) [MediaLibrary_DeliveryMode](#medialibrary_deliverymode) | Defines an enum for delivery modes of the requested media asset.|
| typedef struct [MediaLibrary_RequestOptions](_media_library___request_options.md) [MediaLibrary_RequestOptions](#medialibrary_requestoptions) | Defines an enum for options related to the media asset quality and delivery mode to set.|
| typedef enum [MediaLibrary_MediaType](#medialibrary_mediatype-1) [MediaLibrary_MediaType](#medialibrary_mediatype) | Defines an enum for media types.|
| typedef enum [MediaLibrary_MediaSubType](#medialibrary_mediasubtype-1) [MediaLibrary_MediaSubType](#medialibrary_mediasubtype) | Defines an enum for media subtypes.|
| typedef enum [MediaLibrary_ResourceType](#medialibrary_resourcetype-1) [MediaLibrary_ResourceType](#medialibrary_resourcetype) | Defines an enum for media library resource types.|
| typedef enum [MediaLibrary_ImageFileType](#medialibrary_imagefiletype-1) [MediaLibrary_ImageFileType](#medialibrary_imagefiletype) | Defines an enum for image file types.|
| typedef enum [MediaLibrary_MediaQuality](#medialibrary_mediaquality-1) [MediaLibrary_MediaQuality](#medialibrary_mediaquality) | Defines an enum for media resource quality.|
| typedef enum [MediaLibrary_MediaContentType](#medialibrary_mediacontenttype-1) [MediaLibrary_MediaContentType](#medialibrary_mediacontenttype) | Defines an enum for media content types.|
| typedef void(\* [OH_MediaLibrary_OnDataPrepared](#oh_medialibrary_ondataprepared)) (int32_t result, [MediaLibrary_RequestId](_media_library___request_id.md) requestId) | Defines a function pointer to the callback to be invoked when the requested media asset is ready. |
| typedef void(\* [OH_MediaLibrary_OnImageDataPrepared](#oh_medialibrary_onimagedataprepared)) ([MediaLibrary_ErrorCode](#medialibrary_errorcode) result, [MediaLibrary_RequestId](_media_library___request_id.md) requestId, [MediaLibrary_MediaQuality](#medialibrary_mediaquality) mediaQuality, [MediaLibrary_MediaContentType](#medialibrary_mediacontenttype) type, OH_ImageSourceNative \*imageSourceNative) | Defines a function pointer to the callback to be invoked when the requested image is ready.|


### Enums

| Name| Description|
| -------- | -------- |
| [MediaLibrary_ErrorCode](#medialibrary_errorcode-1) {<br>MEDIA_LIBRARY_OK = 0,<br>MEDIA_LIBRARY_PERMISSION_DENIED = 201,<br>MEDIA_LIBRARY_PARAMETER_ERROR = 401,<br>MEDIA_LIBRARY_NO_SUCH_FILE = 23800101,<br>MEDIA_LIBRARY_INVALID_DISPLAY_NAME = 23800102,<br>MEDIA_LIBRARY_INVALID_ASSET_URI = 23800103,<br>MEDIA_LIBRARY_INVALID_PHOTO_KEY = 23800104,<br>MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED = 23800201,<br>MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR = 23800301<br>} | Enumerates the error codes.|
| [MediaLibrary_DeliveryMode](#medialibrary_deliverymode-1) {<br>MEDIA_LIBRARY_FAST_MODE = 0,<br>MEDIA_LIBRARY_HIGH_QUALITY_MODE = 1,<br>MEDIA_LIBRARY_BALANCED_MODE = 2 } | Enumerates the delivery modes of the requested media asset.|
| [MediaLibrary_MediaType](#medialibrary_mediatype-1) {<br>MEDIA_LIBRARY_IMAGE = 1,<br>MEDIA_LIBRARY_VIDEO = 2 } | Enumerates the media types.|
| [MediaLibrary_MediaSubType](#medialibrary_mediasubtype-1) {<br>MEDIA_LIBRARY_DEFAULT = 0,<br>MEDIA_LIBRARY_MOVING_PHOTO = 3,<br>MEDIA_LIBRARY_BURST = 4 } | Enumerates the media subtypes.|
| [MediaLibrary_ResourceType](#medialibrary_resourcetype-1) {<br>MEDIA_LIBRARY_IMAGE_RESOURCE = 1,<br>MEDIA_LIBRARY_VIDEO_RESOURCE = 2 } | Enumerates the media library resource types.|
| [MediaLibrary_ImageFileType](#medialibrary_imagefiletype-1) {<br>MEDIA_LIBRARY_IMAGE_JPEG = 1 } | Enumerates the image file types.|
| [MediaLibrary_MediaQuality](#medialibrary_mediaquality-1) {<br>MEDIA_LIBRARY_QUALITY_FAST = 1,<br>MEDIA_LIBRARY_QUALITY_FULL = 2 } | Enumerates the media resource quality.|
| [MediaLibrary_MediaContentType](#medialibrary_mediacontenttype-1) {<br>MEDIA_LIBRARY_COMPRESSED = 1,<br>MEDIA_LIBRARY_PICTURE_OBJECT = 2 } | Enumerates the media content types.|


### Functions

| Name| Description|
| -------- | -------- |
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAccessHelper_ApplyChanges](#oh_mediaaccesshelper_applychanges) ([OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) \*changeRequest) | Applies changes to an asset or album.|
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetUri](#oh_mediaasset_geturi) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, const char \*\*uri) | Obtains the URI of a media asset.|
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetDisplayName](#oh_mediaasset_getdisplayname) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, const char \*\*displayName) | Obtains the displayed name of a media asset.|
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetSize](#oh_mediaasset_getsize) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, uint32_t \*size) | Obtains the size of a media asset file.|
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetDateModifiedMs](#oh_mediaasset_getdatemodifiedms) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, uint32_t \*dateModifiedMs) | Obtains the media asset modification time, in ms.|
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetWidth](#oh_mediaasset_getwidth) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, uint32_t \*width) | Obtains the image width (in pixels) of a media asset.|
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetHeight](#oh_mediaasset_getheight) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, uint32_t \*height) | Obtains the image height (in pixels) of a media asset.|
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetOrientation](#oh_mediaasset_getorientation) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, uint32_t \*orientation) | Obtains the orientation of a media asset, in degrees.|
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_Release](#oh_mediaasset_release) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset) | Releases a media asset.|
| [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) \* [OH_MediaAssetChangeRequest_Create](#oh_mediaassetchangerequest_create) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset) | Creates an [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) instance.|
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAssetChangeRequest_AddResourceWithBuffer](#oh_mediaassetchangerequest_addresourcewithbuffer) ([OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) \*changeRequest, [MediaLibrary_ResourceType](#medialibrary_resourcetype) resourceType, uint8_t \*buffer, uint32_t length) | Adds a resource using **ArrayBuffer** data.|
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAssetChangeRequest_SaveCameraPhoto](#oh_mediaassetchangerequest_savecameraphoto) ([OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) \*changeRequest, [MediaLibrary_ImageFileType](#medialibrary_imagefiletype) imageFileType) | Saves the photo taken by the camera.|
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAssetChangeRequest_DiscardCameraPhoto](#oh_mediaassetchangerequest_discardcameraphoto) ([OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) \*changeRequest) | Discards the photo taken by the camera.|
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAssetChangeRequest_Release](#oh_mediaassetchangerequest_release) ([OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) \*changeRequest) | Releases an [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) instance.|
| [OH_MediaAssetManager](#oh_mediaassetmanager) \* [OH_MediaAssetManager_Create](#oh_mediaassetmanager_create) (void) | Creates a **MediaAssetManager** instance.|
| [MediaLibrary_RequestId](_media_library___request_id.md) [OH_MediaAssetManager_RequestImageForPath](#oh_mediaassetmanager_requestimageforpath) ([OH_MediaAssetManager](#oh_mediaassetmanager) \*manager, const char \*uri, [MediaLibrary_RequestOptions](_media_library___request_options.md) requestOptions, const char \*destPath, [OH_MediaLibrary_OnDataPrepared](#oh_medialibrary_ondataprepared) callback) | Requests an image in the specified directory.|
| [MediaLibrary_RequestId](_media_library___request_id.md) [OH_MediaAssetManager_RequestVideoForPath](#oh_mediaassetmanager_requestvideoforpath) ([OH_MediaAssetManager](#oh_mediaassetmanager) \*manager, const char \*uri, [MediaLibrary_RequestOptions](_media_library___request_options.md) requestOptions, const char \*destPath, [OH_MediaLibrary_OnDataPrepared](#oh_medialibrary_ondataprepared) callback) | Requests a video in the specified directory.|
| bool [OH_MediaAssetManager_CancelRequest](#oh_mediaassetmanager_cancelrequest) ([OH_MediaAssetManager](#oh_mediaassetmanager) \*manager, const [MediaLibrary_RequestId](_media_library___request_id.md) requestId) | Cancels a request based on the request ID.|
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAssetManager_RequestImage](#oh_mediaassetmanager_requestimage) ([OH_MediaAssetManager](#oh_mediaassetmanager) \*manager, [OH_MediaAsset](#oh_mediaasset) \*mediaAsset, [MediaLibrary_RequestOptions](_media_library___request_options.md) requestOptions, [MediaLibrary_RequestId](_media_library___request_id.md) \*requestId, [OH_MediaLibrary_OnImageDataPrepared](#oh_medialibrary_onimagedataprepared) callback) | Requests an image.|


## Type Description


### MediaLibrary_DeliveryMode

```
typedef enum MediaLibrary_DeliveryMode MediaLibrary_DeliveryMode
```

**Description**

Defines an enum for delivery modes of the requested media asset.

The delivery modes include the following:

- **MEDIA_LIBRARY_FAST_MODE**: deliver the media asset available without considering its quality.

- **MEDIA_LIBRARY_HIGH_QUALITY_MODE**: deliver a media asset with high quality. If there is no high-quality asset available, trigger the process for creating a high-quality asset. Then, return the high-quality asset that is successfully created.

- **MEDIA_LIBRARY_BALANCED_MODE**: return the high-quality asset if there is any. Otherwise, return a low-quality asset first and trigger the process for creating a high-quality asset. Then, return the high-quality asset that is successfully created.

**Since**: 12


### MediaLibrary_ErrorCode

```
typedef enum MediaLibrary_ErrorCode MediaLibrary_ErrorCode
```

**Description**

Defines an enum for error codes.

**Since**: 12


### MediaLibrary_ImageFileType

```
typedef enum MediaLibrary_ImageFileType MediaLibrary_ImageFileType
```

**Description**

Defines an enum for image file types.

**Since**: 12


### MediaLibrary_MediaContentType

```
typedef enum MediaLibrary_MediaContentType MediaLibrary_MediaContentType
```

**Description**

Defines an enum for media content types.

**Since**: 12


### MediaLibrary_MediaQuality

```
typedef enum MediaLibrary_MediaQuality MediaLibrary_MediaQuality
```

**Description**

Defines an enum for media resource quality, which

varies with the specified delivery mode for the requested media asset.

- **MEDIA_LIBRARY_FAST_MODE**: deliver the media asset available without considering its quality.

- **MEDIA_LIBRARY_HIGH_QUALITY_MODE**: deliver a media asset with high quality. If there is no high-quality asset available, trigger the process for creating a high-quality asset. Then, return the high-quality asset that is successfully created.

- **MEDIA_LIBRARY_BALANCED_MODE**: return the high-quality asset if there is any. Otherwise, return a low-quality asset first and trigger the process for creating a high-quality asset. Then, return the high-quality asset that is successfully created.

**Since**: 12


### MediaLibrary_MediaSubType

```
typedef enum MediaLibrary_MediaSubType MediaLibrary_MediaSubType
```

**Description**

Define an enum for media subtypes.

**Since**: 12


### MediaLibrary_MediaType

```
typedef enum MediaLibrary_MediaType MediaLibrary_MediaType
```

**Description**

Define an enum for media types.

**Since**: 12


### MediaLibrary_RequestId

```
typedef struct MediaLibrary_RequestId MediaLibrary_RequestId
```

**Description**

Defines a request ID.

A value of this type is returned when a media asset is requested. The request ID can be used to cancel a request. If a request fails, an all-zero value, for example, **00000000-0000-0000-0000-000000000000** is returned.

**Since**: 12


### MediaLibrary_RequestOptions

```
typedef struct MediaLibrary_RequestOptions MediaLibrary_RequestOptions
```

**Description**

Defines how media assets are requested and processed.

You can use this struct to set options related to the media asset quality, delivery mode, and more.

**Since**: 12


### MediaLibrary_ResourceType

```
typedef enum MediaLibrary_ResourceType MediaLibrary_ResourceType
```

**Description**

Define an enum for media library resource types.

**Since**: 12


### OH_MediaAsset

```
typedef struct OH_MediaAsset OH_MediaAsset
```

**Description**

Defines a struct for a media asset.

This struct provides the capability of encapsulating media file attributes.

**Since**: 12


### OH_MediaAssetChangeRequest

```
typedef struct OH_MediaAssetChangeRequest OH_MediaAssetChangeRequest
```

**Description**

Defines a struct for a media asset change request.

This struct provides the capability of handling media asset change requests.

**Since**: 12


### OH_MediaAssetManager

```
typedef struct OH_MediaAssetManager OH_MediaAssetManager
```

**Description**

Defines a struct for the media asset manager.

You can use this struct to create a media asset manager instance. If the creation fails, a null pointer is returned.

**Since**: 12


### OH_MediaLibrary_OnDataPrepared

```
typedef void (*OH_MediaLibrary_OnDataPrepared)(int32_t result, MediaLibrary_RequestId requestId)
```

**Description**

Defines a function pointer to the callback to be invoked when the requested media asset is ready.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| result | Processing result of the requested asset.|
| requestId | Request ID.|


### OH_MediaLibrary_OnImageDataPrepared

```
typedef void (*OH_MediaLibrary_OnImageDataPrepared)(MediaLibrary_ErrorCode result, MediaLibrary_RequestId requestId, MediaLibrary_MediaQuality mediaQuality, MediaLibrary_MediaContentType type, OH_ImageSourceNative* imageSourceNative)
```

**Description**

Defines a function pointer to the callback to be invoked when the requested image is ready.

This callback is called when the requested image source is ready.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| result | [MediaLibrary_ErrorCode](#medialibrary_errorcode-1).|
| requestId | [MediaLibrary_RequestId](_media_library___request_id.md).|
| mediaQuality | [MediaLibrary_MediaQuality](#medialibrary_mediaquality-1).|
| type | [MediaLibrary_MediaContentType](#medialibrary_mediacontenttype-1).|
| imageSourceNative | [OH_ImageSourceNative](../apis-image-kit/_image___native_module.md#oh_imagesourcenative) obtained when the requested image source is ready.|


## Enum Description


### MediaLibrary_DeliveryMode

```
enum MediaLibrary_DeliveryMode
```

**Description**

Enumerates the delivery modes of the requested media asset.

The delivery modes include the following:

- **MEDIA_LIBRARY_FAST_MODE**: deliver the media asset available without considering its quality.

- **MEDIA_LIBRARY_HIGH_QUALITY_MODE**: deliver a media asset with high quality. If there is no high-quality asset available, trigger the process for creating a high-quality asset. Then, return the high-quality asset that is successfully created.

- **MEDIA_LIBRARY_BALANCED_MODE**: return the high-quality asset if there is any. Otherwise, return a low-quality asset first and trigger the process for creating a high-quality asset. Then, return the high-quality asset that is successfully created.

**Since**: 12

| Value| Description|
| -------- | -------- |
| MEDIA_LIBRARY_FAST_MODE | Fast mode.|
| MEDIA_LIBRARY_HIGH_QUALITY_MODE | High-quality mode.|
| MEDIA_LIBRARY_BALANCED_MODE | Balance mode.|


### MediaLibrary_ErrorCode

```
enum MediaLibrary_ErrorCode
```

**Description**

Enumerates the error codes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| MEDIA_LIBRARY_OK | The operation is successful. |
| MEDIA_LIBRARY_PERMISSION_DENIED | The permission is denied. |
| MEDIA_LIBRARY_PARAMETER_ERROR | Mandatory parameter is not specified, the parameter type is incorrect, or parameter verification failed. |
| MEDIA_LIBRARY_NO_SUCH_FILE | The file does not exist.|
| MEDIA_LIBRARY_INVALID_DISPLAY_NAME | The name displayed is incorrect. |
| MEDIA_LIBRARY_INVALID_ASSET_URI | The asset URI is invalid. |
| MEDIA_LIBRARY_INVALID_PHOTO_KEY | **PhotoKey** is invalid. |
| MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED | The operation is not supported. |
| MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR | An internal system error is detected. Possible causes include the following:<br>1. Database corrupted.<br>2. File system error.<br>3. IPC request timed out. |


### MediaLibrary_ImageFileType

```
enum MediaLibrary_ImageFileType
```

**Description**

Enumerates the image file types.

**Since**: 12

| Value| Description|
| -------- | -------- |
| MEDIA_LIBRARY_IMAGE_JPEG | JPEG.|


### MediaLibrary_MediaContentType

```
enum MediaLibrary_MediaContentType
```

**Description**

Enumerates the media content types.

**Since**: 12

| Value| Description|
| -------- | -------- |
| MEDIA_LIBRARY_COMPRESSED | Compressed media content.|
| MEDIA_LIBRARY_PICTURE_OBJECT | Image object.|


### MediaLibrary_MediaQuality

```
enum MediaLibrary_MediaQuality
```

**Description**

Enumerates the media resource quality, which varies with the specified delivery mode for the requested media asset.

- **MEDIA_LIBRARY_FAST_MODE**: deliver the media asset available without considering its quality.

- **MEDIA_LIBRARY_HIGH_QUALITY_MODE**: deliver a media asset with high quality. If there is no high-quality asset available, trigger the process for creating a high-quality asset. Then, return the high-quality asset that is successfully created.

- **MEDIA_LIBRARY_BALANCED_MODE**: return the high-quality asset if there is any. Otherwise, return a low-quality asset first and trigger the process for creating a high-quality asset. Then, return the high-quality asset that is successfully created.

**Since**: 12

| Value| Description|
| -------- | -------- |
| MEDIA_LIBRARY_QUALITY_FAST | Media asset available without considering its quality.|
| MEDIA_LIBRARY_QUALITY_FULL | High-quality media asset.|


### MediaLibrary_MediaSubType

```
enum MediaLibrary_MediaSubType
```

**Description**

Enumerates the media subtypes.

**Since**: 12

| Value| Description|
| -------- | -------- |
| MEDIA_LIBRARY_DEFAULT | Photo (default type).|
| MEDIA_LIBRARY_MOVING_PHOTO | Moving photo.|
| MEDIA_LIBRARY_BURST | Burst photo.|


### MediaLibrary_MediaType

```
enum MediaLibrary_MediaType
```

**Description**

Enumerates the media types.

**Since**: 12

| Value| Description|
| -------- | -------- |
| MEDIA_LIBRARY_IMAGE | Image.|
| MEDIA_LIBRARY_VIDEO | Video.|


### MediaLibrary_ResourceType

```
enum MediaLibrary_ResourceType
```

**Description**

Enumerates the media library resource types.

**Since**: 12

| Value| Description|
| -------- | -------- |
| MEDIA_LIBRARY_IMAGE_RESOURCE | Image resource.|
| MEDIA_LIBRARY_VIDEO_RESOURCE | Video resource.|


## Function Description


### OH_MediaAccessHelper_ApplyChanges()

```
MediaLibrary_ErrorCode OH_MediaAccessHelper_ApplyChanges(OH_MediaAssetChangeRequest* changeRequest)
```

**Description**

Applies changes to an asset or album.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| changeRequest | Pointer to the [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) instance. |

**Required permissions**

ohos.permission.WRITE_IMAGEVIDEO

**Returns**

[MediaLibrary_ErrorCode](#medialibrary_errorcode-1):

- **MEDIA_LIBRARY_OK**: The operation is successful.

- **MEDIA_LIBRARY_PARAMETER_ERROR**: Incorrect parameters.
  Possible causes:
  1. There is mandatory parameter that is not specified.
  
  2. The parameter type is incorrect.
  
  3. The parameter verification failed.

- **MEDIA_LIBRARY_PERMISSION_DENIED**: The permission is denied.

- **MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: An internal system error occurred.


### OH_MediaAsset_GetDateModifiedMs()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetDateModifiedMs(OH_MediaAsset* mediaAsset, uint32_t* dateModifiedMs)
```

**Description**

Obtains the media asset modification time, in ms.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| mediaAsset | Pointer to the [OH_MediaAsset](#oh_mediaasset) instance.|
| dateModifiedMs | Pointer to the asset modification time obtained, in ms. |

**Returns**

[MediaLibrary_ErrorCode](#medialibrary_errorcode-1):

- **MEDIA_LIBRARY_OK**: The operation is successful.

- **MEDIA_LIBRARY_PARAMETER_ERROR**: Incorrect parameters.
  Possible causes:
  1. There is mandatory parameter that is not specified.
  
  2. The parameter type is incorrect.
  
  3. The parameter verification failed.

- **MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: An internal system error occurred.


### OH_MediaAsset_GetDisplayName()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetDisplayName(OH_MediaAsset* mediaAsset, const char** displayName)
```

**Description**

Obtains the displayed name of a media asset.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| mediaAsset | Pointer to the [OH_MediaAsset](#oh_mediaasset) instance.|
| displayName | Pointer to the displayed name obtained.|

**Returns**

[MediaLibrary_ErrorCode](#medialibrary_errorcode-1):
- **MEDIA_LIBRARY_OK**: The operation is successful.

- **MEDIA_LIBRARY_PARAMETER_ERROR**: Incorrect parameters.
  Possible causes:

  1. There is mandatory parameter that is not specified.
  2. The parameter type is incorrect.
  3. The parameter verification failed.

- **MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: An internal system error occurred.


### OH_MediaAsset_GetHeight()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetHeight(OH_MediaAsset* mediaAsset, uint32_t* height)
```

**Description**

Obtains the image height (in pixels) of a media asset.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| mediaAsset | Pointer to the [OH_MediaAsset](#oh_mediaasset) instance.|
| height | Pointer to the image height of the media resource, in pixels.|

**Returns**

[MediaLibrary_ErrorCode](#medialibrary_errorcode-1):
- **MEDIA_LIBRARY_OK**: The operation is successful.

- **MEDIA_LIBRARY_PARAMETER_ERROR**: Incorrect parameters.
  Possible causes:

  1. There is mandatory parameter that is not specified.
  2. The parameter type is incorrect.
  3. The parameter verification failed.

- **MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: An internal system error occurred.


### OH_MediaAsset_GetOrientation()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetOrientation(OH_MediaAsset* mediaAsset, uint32_t* orientation)
```

**Description**

Obtains the orientation of a media asset, in degrees.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| mediaAsset | Pointer to the [OH_MediaAsset](#oh_mediaasset) instance.|
| orientation | Pointer to the orientation of the image obtained, in degrees.|

**Returns**

[MediaLibrary_ErrorCode](#medialibrary_errorcode-1):
- **MEDIA_LIBRARY_OK**: The operation is successful.

- **MEDIA_LIBRARY_PARAMETER_ERROR**: Incorrect parameters.
  Possible causes:

  1. There is mandatory parameter that is not specified.
  2. The parameter type is incorrect.
  3. The parameter verification failed.

- **MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: An internal system error occurred.


### OH_MediaAsset_GetSize()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetSize(OH_MediaAsset* mediaAsset, uint32_t* size)
```

**Description**

Obtains the size of a media asset file.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| mediaAsset | Pointer to the [OH_MediaAsset](#oh_mediaasset) instance.|
| size | Pointer to the file size obtained, in bytes.|

**Returns**

[MediaLibrary_ErrorCode](#medialibrary_errorcode-1):

- **MEDIA_LIBRARY_OK**: The operation is successful.

- **MEDIA_LIBRARY_PARAMETER_ERROR**: Incorrect parameters.
  Possible causes:

  1. There is mandatory parameter that is not specified.
  2. The parameter type is incorrect.
  3. The parameter verification failed.

- **MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: An internal system error occurred.


### OH_MediaAsset_GetUri()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetUri(OH_MediaAsset* mediaAsset, const char** uri)
```

**Description**

Obtains the URI of a media asset.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| mediaAsset | Pointer to the [OH_MediaAsset](#oh_mediaasset) instance.|
| uri | Pointer to the URI obtained.|

**Returns**

[MediaLibrary_ErrorCode](#medialibrary_errorcode-1):

- **MEDIA_LIBRARY_OK**: The operation is successful.

- **MEDIA_LIBRARY_PARAMETER_ERROR**: Incorrect parameters.
  Possible causes:

  1. There is mandatory parameter that is not specified.
  2. The parameter type is incorrect.
  3. The parameter verification failed.

- **MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: An internal system error occurred.


### OH_MediaAsset_GetWidth()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetWidth(OH_MediaAsset* mediaAsset, uint32_t* width)
```

**Description**

Obtains the image width (in pixels) of a media asset.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| mediaAsset | Pointer to the [OH_MediaAsset](#oh_mediaasset) instance.|
| width | Pointer to the image width obtained, in pixels.|

**Returns**

[MediaLibrary_ErrorCode](#medialibrary_errorcode-1):

- **MEDIA_LIBRARY_OK**: The operation is successful.

- **MEDIA_LIBRARY_PARAMETER_ERROR**: Incorrect parameters.
  Possible causes:

  1. There is mandatory parameter that is not specified.
  2. The parameter type is incorrect.
  3. The parameter verification failed.

- **MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: An internal system error occurred.


### OH_MediaAsset_Release()

```
MediaLibrary_ErrorCode OH_MediaAsset_Release(OH_MediaAsset* mediaAsset)
```

**Description**

Releases a media asset.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| mediaAsset | Pointer to the [OH_MediaAsset](#oh_mediaasset) instance to release. |

**Returns**

[MediaLibrary_ErrorCode](#medialibrary_errorcode-1):

- **MEDIA_LIBRARY_OK**: The operation is successful.

- **MEDIA_LIBRARY_PARAMETER_ERROR**: Incorrect parameters.
  Possible causes:

  1. There is mandatory parameter that is not specified.
  2. The parameter type is incorrect.
  3. The parameter verification failed.


### OH_MediaAssetChangeRequest_AddResourceWithBuffer()

```
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_AddResourceWithBuffer(OH_MediaAssetChangeRequest* changeRequest, MediaLibrary_ResourceType resourceType, uint8_t* buffer, uint32_t length)
```

**Description**

Adds a resource using **ArrayBuffer** data.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| changeRequest | Pointer to the [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) instance.|
| resourceType | [MediaLibrary_ResourceType](#medialibrary_resourcetype) of the resource to add.|
| buffer | Pointe to the data buffer.|
| length | Length of the data buffer.|

**Returns**

[MediaLibrary_ErrorCode](#medialibrary_errorcode-1):

- **MEDIA_LIBRARY_OK**: The operation is successful.

- **MEDIA_LIBRARY_PARAMETER_ERROR**: Incorrect parameters.
  Possible causes:

  1. There is mandatory parameter that is not specified.
  2. The parameter type is incorrect.
  3. The parameter verification failed.

- **MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: An internal system error occurred.

- **MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED**: This operation is not supported.


### OH_MediaAssetChangeRequest_Create()

```
OH_MediaAssetChangeRequest* OH_MediaAssetChangeRequest_Create(OH_MediaAsset* mediaAsset)
```

**Description**

Creates an [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| mediaAsset | Pointer to the [OH_MediaAsset](#oh_mediaasset) instance.|

**Returns**

[MediaLibrary_ErrorCode](#medialibrary_errorcode-1):

- **MEDIA_LIBRARY_OK**: The operation is successful.

- **MEDIA_LIBRARY_PARAMETER_ERROR**: Incorrect parameters.
  Possible causes:

  1. There is mandatory parameter that is not specified.
  2. The parameter type is incorrect.
  3. The parameter verification failed.

- **MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: An internal system error occurred.


### OH_MediaAssetChangeRequest_DiscardCameraPhoto()

```
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_DiscardCameraPhoto(OH_MediaAssetChangeRequest* changeRequest)
```

**Description**

Discards the photo taken by the camera.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| changeRequest | Pointer to the [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) instance.|

**Returns**

[MediaLibrary_ErrorCode](#medialibrary_errorcode-1):

- **MEDIA_LIBRARY_OK**: The operation is successful.

- **MEDIA_LIBRARY_PARAMETER_ERROR**: Incorrect parameters.
  Possible causes:

  1. There is mandatory parameter that is not specified.
  2. The parameter type is incorrect.
  3. The parameter verification failed.

- **MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: An internal system error occurred.

- **MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED**: This operation is not supported.


### OH_MediaAssetChangeRequest_Release()

```
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_Release(OH_MediaAssetChangeRequest* changeRequest)
```

**Description**

Releases an [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) instance.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| changeRequest | Pointer to the [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) instance to release.|

**Returns**

[MediaLibrary_ErrorCode](#medialibrary_errorcode-1):

- **MEDIA_LIBRARY_OK**: The operation is successful.

- **MEDIA_LIBRARY_PARAMETER_ERROR**: Incorrect parameters.
  Possible causes:

  1. There is mandatory parameter that is not specified.
  2. The parameter type is incorrect.
  3. The parameter verification failed.


### OH_MediaAssetChangeRequest_SaveCameraPhoto()

```
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_SaveCameraPhoto(OH_MediaAssetChangeRequest* changeRequest, MediaLibrary_ImageFileType imageFileType)
```

**Description**

Saves the photo taken by the camera.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| changeRequest | Pointer to the [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) instance.|
| imageFileType | [MediaLibrary_ImageFileType](#medialibrary_imagefiletype) of the photo to save.|

**Returns**

[MediaLibrary_ErrorCode](#medialibrary_errorcode-1):

- **MEDIA_LIBRARY_OK**: The operation is successful.

- **MEDIA_LIBRARY_PARAMETER_ERROR**: Incorrect parameters.
  Possible causes:

  1. There is mandatory parameter that is not specified.
  2. The parameter type is incorrect.
  3. The parameter verification failed.

- **MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: An internal system error occurred.

- **MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED**: This operation is not supported.


### OH_MediaAssetManager_CancelRequest()

```
bool OH_MediaAssetManager_CancelRequest (OH_MediaAssetManager *manager, const MediaLibrary_RequestId requestId)
```

**Description**

Cancels a request based on the request ID.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| manager | Pointer to the **OH_MediaAssetManager** instance.|
| requestId | ID of the request to cancel.|

**Required permissions**

ohos.permission.READ_IMAGEVIDEO

**Returns**

Returns **true** if the request is successfully canceled; returns **false** otherwise.


### OH_MediaAssetManager_Create()

```
OH_MediaAssetManager* OH_MediaAssetManager_Create (void )
```

**Description**

Creates a **MediaAssetManager** instance.

**Since**: 12

**Returns**

Returns the pointer to the **MediaAssetManager** instance created.


### OH_MediaAssetManager_RequestImage()

```
MediaLibrary_ErrorCode OH_MediaAssetManager_RequestImage(OH_MediaAssetManager* manager, OH_MediaAsset* mediaAsset, MediaLibrary_RequestOptions requestOptions, MediaLibrary_RequestId* requestId,  OH_MediaLibrary_OnImageDataPrepared callback)
```

**Description**

Requests an image.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| manager | Pointer to the [OH_MediaAssetManager](#oh_mediaassetmanager) instance.|
| mediaAsset | Pointer to the [OH_MediaAsset](#oh_mediaasset) instance to be requested.|
| requestOptions | [MediaLibrary_RequestOptions](_media_library___request_options.md).|
| requestId | Pointe to the [MediaLibrary_RequestId](_media_library___request_id.md) obtained.|
| callback | Callback [OH_MediaLibrary_OnImageDataPrepared](#oh_medialibrary_onimagedataprepared) to be invoked when the requested image source is ready.|

**Required permissions**

ohos.permission.READ_IMAGEVIDEO

**Returns**

[MediaLibrary_ErrorCode](#medialibrary_errorcode-1):

- **MEDIA_LIBRARY_OK**: The operation is successful.

- **MEDIA_LIBRARY_PARAMETER_ERROR**: Incorrect parameters.
  Possible causes:

  1. There is mandatory parameter that is not specified.
  2. The parameter type is incorrect.
  3. The parameter verification failed.

- **MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED**: This operation is not supported.

- **MEDIA_LIBRARY_PERMISSION_DENIED**: The permission is denied.

- **MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: An internal system error occurred.


### OH_MediaAssetManager_RequestImageForPath()

```
MediaLibrary_RequestId OH_MediaAssetManager_RequestImageForPath (OH_MediaAssetManager *manager, const char *uri, MediaLibrary_RequestOptions requestOptions, const char *destPath, OH_MediaLibrary_OnDataPrepared callback)
```

**Description**

Requests an image in the specified directory.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| manager | Pointer to the **OH_MediaAssetManager** instance.|
| uri | Pointer to the URI of the requested image asset.|
| requestOptions | Options related to the image asset quality and delivery mode.|
| destPath | Pointer to the destination directory of the requested image asset.|
| callback | Callback to be invoked when the requested image asset is ready.|

**Required permissions**

ohos.permission.READ_IMAGEVIDEO

**Returns**

Request ID.


### OH_MediaAssetManager_RequestVideoForPath()

```
MediaLibrary_RequestId OH_MediaAssetManager_RequestVideoForPath (OH_MediaAssetManager *manager, const char *uri, MediaLibrary_RequestOptions requestOptions, const char *destPath, OH_MediaLibrary_OnDataPrepared callback)
```

**Description**

Requests a video asset in the specified directory.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| manager | Pointer to the **OH_MediaAssetManager** instance.|
| uri | Pointer to the URI of the requested video asset.|
| requestOptions | Options related to the video asset quality and delivery mode.|
| destPath | Pointer to the destination directory of the requested video asset.|
| callback | Callback to be invoked when the requested video asset is ready.|

**Required permissions**

ohos.permission.READ_IMAGEVIDEO

**Returns**

Request ID.
