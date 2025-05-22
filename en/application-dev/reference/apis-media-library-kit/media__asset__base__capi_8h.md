# media_asset_base_capi.h


## Overview

Defines the following structs and enums of the media asset manager:

- [OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager): provides the capability of requesting assets from the media library.

- [MediaLibrary_RequestId](_media_library___request_id.md): defines a request ID returned when a media asset is requested. The request ID can be used to cancel a request.

- [MediaLibrary_DeliveryMode](_media_asset_manager.md#medialibrary_deliverymode-1): enumerates the deliver modes of the requested media asset.

- [OH_MediaLibrary_OnDataPrepared](_media_asset_manager.md#oh_medialibrary_ondataprepared): defines a function pointer to the callback to be invoked when the requested media asset is ready.

- [MediaLibrary_RequestOptions](_media_library___request_options.md): defines the options related to the media asset quality and delivery mode to set.


**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Library**: libmedia_asset_manager.so

**File to include**: &lt;multimedia/media_library/media_asset_base_capi.h&gt;

**Since**: 12

**Related module**: [MediaAssetManager](_media_asset_manager.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [MediaLibrary_RequestId](_media_library___request_id.md) | Defines a request ID. | 
| struct  [MediaLibrary_RequestOptions](_media_library___request_options.md) | Defines how media assets are requested and processed. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) [OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) | Defines a struct for the media asset manager. | 
| typedef struct [OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) [OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) | Defines a struct for a media asset change request. | 
| typedef struct [OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto) [OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto) | Defines a struct for a moving photo. | 
| typedef struct [OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) [OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) | Defines a struct for a media asset. | 
| typedef struct [MediaLibrary_RequestId](_media_library___request_id.md) [MediaLibrary_RequestId](_media_asset_manager.md#medialibrary_requestid) | Defines a struct for a request ID. | 
| typedef enum [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode-1) [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) | Defines an enum for error codes. | 
| typedef enum [MediaLibrary_DeliveryMode](_media_asset_manager.md#medialibrary_deliverymode-1) [MediaLibrary_DeliveryMode](_media_asset_manager.md#medialibrary_deliverymode) | Defines an enum for delivery modes of the requested media asset. | 
| typedef struct [MediaLibrary_RequestOptions](_media_library___request_options.md) [MediaLibrary_RequestOptions](_media_asset_manager.md#medialibrary_requestoptions) | Defines a struct for the options related to the media asset quality and delivery mode to set. | 
| typedef enum [MediaLibrary_MediaType](_media_asset_manager.md#medialibrary_mediatype-1) [MediaLibrary_MediaType](_media_asset_manager.md#medialibrary_mediatype) | Defines an enum for media types. | 
| typedef enum [MediaLibrary_MediaSubType](_media_asset_manager.md#medialibrary_mediasubtype-1) [MediaLibrary_MediaSubType](_media_asset_manager.md#medialibrary_mediasubtype) | Defines an enum for media subtypes. | 
| typedef enum [MediaLibrary_ResourceType](_media_asset_manager.md#medialibrary_resourcetype-1) [MediaLibrary_ResourceType](_media_asset_manager.md#medialibrary_resourcetype) | Defines an enum for media library resource types. | 
| typedef enum [MediaLibrary_ImageFileType](_media_asset_manager.md#medialibrary_imagefiletype-1) [MediaLibrary_ImageFileType](_media_asset_manager.md#medialibrary_imagefiletype) | Defines an enum for image file types. | 
| typedef enum [MediaLibrary_MediaQuality](_media_asset_manager.md#medialibrary_mediaquality-1) [MediaLibrary_MediaQuality](_media_asset_manager.md#medialibrary_mediaquality) | Defines an enum for media resource quality. | 
| typedef enum [MediaLibrary_MediaContentType](_media_asset_manager.md#medialibrary_mediacontenttype-1) [MediaLibrary_MediaContentType](_media_asset_manager.md#medialibrary_mediacontenttype) | Defines an enum for media content types. | 
| typedef void(\* [OH_MediaLibrary_OnDataPrepared](_media_asset_manager.md#oh_medialibrary_ondataprepared)) (int32_t result, [MediaLibrary_RequestId](_media_library___request_id.md) requestId) | Defines a function pointer to the callback to be invoked when the requested media asset is ready. | 
| typedef void(\* [OH_MediaLibrary_OnImageDataPrepared](_media_asset_manager.md#oh_medialibrary_onimagedataprepared)) ([MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) result, [MediaLibrary_RequestId](_media_library___request_id.md) requestId, [MediaLibrary_MediaQuality](_media_asset_manager.md#medialibrary_mediaquality) mediaQuality, [MediaLibrary_MediaContentType](_media_asset_manager.md#medialibrary_mediacontenttype) type, [OH_ImageSourceNative](_media_asset_manager.md#oh_imagesourcenative) *imageSourceNative) | Defines a function pointer to the callback to be invoked when the requested image source is ready. | 
| typedef void(\* [OH_MediaLibrary_OnMovingPhotoDataPrepared](_media_asset_manager.md#oh_medialibrary_onmovingphotodataprepared)) ([MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) result, [MediaLibrary_RequestId](_media_library___request_id.md) requestId, [MediaLibrary_MediaQuality](_media_asset_manager.md#medialibrary_mediaquality) mediaQuality, [MediaLibrary_MediaContentType](_media_asset_manager.md#medialibrary_mediacontenttype) type, [OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto) \*movingPhoto) | Called when the requested moving photo is ready. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) {<br>MEDIA_LIBRARY_OK = 0,<br>MEDIA_LIBRARY_PERMISSION_DENIED = 201,<br>MEDIA_LIBRARY_PARAMETER_ERROR = 401,<br>MEDIA_LIBRARY_NO_SUCH_FILE = 23800101,<br>MEDIA_LIBRARY_INVALID_DISPLAY_NAME = 23800102,<br>MEDIA_LIBRARY_INVALID_ASSET_URI = 23800103,<br>MEDIA_LIBRARY_INVALID_PHOTO_KEY = 23800104,<br>MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED = 23800201,<br>MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR = 23800301<br>} | Enumerates the error codes.| 
| [MediaLibrary_DeliveryMode](_media_asset_manager.md#medialibrary_deliverymode) {<br>MEDIA_LIBRARY_FAST_MODE = 0,<br>MEDIA_LIBRARY_HIGH_QUALITY_MODE = 1,<br>MEDIA_LIBRARY_BALANCED_MODE = 2 } | Enumerates the delivery modes of the requested media asset.| 
| [MediaLibrary_MediaType](_media_asset_manager.md#medialibrary_mediatype) {<br>MEDIA_LIBRARY_IMAGE = 1,<br>MEDIA_LIBRARY_VIDEO = 2 } | Enumerates the media types.| 
| [MediaLibrary_MediaSubType](_media_asset_manager.md#medialibrary_mediasubtype) {<br>MEDIA_LIBRARY_DEFAULT = 0,<br>MEDIA_LIBRARY_MOVING_PHOTO = 3,<br>MEDIA_LIBRARY_BURST = 4 } | Enumerates the media subtypes.| 
| [MediaLibrary_ResourceType](_media_asset_manager.md#medialibrary_resourcetype) {<br>MEDIA_LIBRARY_IMAGE_RESOURCE = 1,<br>MEDIA_LIBRARY_VIDEO_RESOURCE = 2 } | Enumerates the media library resource types.| 
| [MediaLibrary_ImageFileType](_media_asset_manager.md#medialibrary_imagefiletype) {<br>MEDIA_LIBRARY_IMAGE_JPEG = 1 } | Enumerates the image file types.| 
| [MediaLibrary_MediaQuality](_media_asset_manager.md#medialibrary_mediaquality) {<br>MEDIA_LIBRARY_QUALITY_FAST = 1,<br>MEDIA_LIBRARY_QUALITY_FULL = 2 } | Enumerates the media resource quality.| 
| [MediaLibrary_MediaContentType](_media_asset_manager.md#medialibrary_mediacontenttype) {<br>MEDIA_LIBRARY_COMPRESSED = 1,<br>MEDIA_LIBRARY_PICTURE_OBJECT = 2 } | Enumerates the media content types.| 
