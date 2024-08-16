# media_asset_base_capi.h


## Overview

Defines the following structs and enums of the media asset manager:

- [OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager): provides the capability of requesting assets from the media library.
- [MediaLibrary_RequestId](_media_library___request_id.md): defines a type returned when a media asset is requested. The request ID can be used to cancel a request.
- [MediaLibrary_DeliveryMode](_media_asset_manager.md#medialibrary_deliverymode-1): enumerates the deliver modes of the requested media asset.

- [OH_MediaLibrary_OnDataPrepared](_media_asset_manager.md#oh_medialibrary_ondataprepared): defines a function pointer to the callback to be invoked when the requested media asset is ready.

- [MediaLibrary_RequestOptions](_media_library___request_options.md): defines the options related to the media asset quality and delivery mode to set.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Library**: libmedia_asset_manager.so

**Since**: 12

**Related module**: [MediaAssetManager](_media_asset_manager.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| struct  [MediaLibrary_RequestId](_media_library___request_id.md) | Defines a request ID.|
| struct  [MediaLibrary_RequestOptions](_media_library___request_options.md) | Defines how media assets are requested and processed.|


### Types

| Name| Description|
| -------- | -------- |
| typedef struct [OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) [OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) | Defines a struct for the media asset manager.|
| typedef struct [MediaLibrary_RequestId](_media_library___request_id.md) [MediaLibrary_RequestId](_media_asset_manager.md#medialibrary_requestid) | Defines a struct for the request ID.|
| typedef enum [MediaLibrary_DeliveryMode](_media_asset_manager.md#medialibrary_deliverymode-1) [MediaLibrary_DeliveryMode](_media_asset_manager.md#medialibrary_deliverymode) | Defines an enum for the delivery mode of the requested media asset.|
| typedef void(\* [OH_MediaLibrary_OnDataPrepared](_media_asset_manager.md#oh_medialibrary_ondataprepared)) (int32_t result, [MediaLibrary_RequestId](_media_library___request_id.md) requestId) | Defines a function pointer to the callback to be triggered when the requested media asset is ready.|
| typedef struct [MediaLibrary_RequestOptions](_media_library___request_options.md) [MediaLibrary_RequestOptions](_media_asset_manager.md#medialibrary_requestoptions) | Defines a struct for the options related to the media asset quality and delivery mode to set.|


### Enums

| Name| Description|
| -------- | -------- |
| [MediaLibrary_DeliveryMode](_media_asset_manager.md#medialibrary_deliverymode-1) {<br>MEDIA_LIBRARY_FAST_MODE = 0,<br>MEDIA_LIBRARY_HIGH_QUALITY_MODE = 1,<br>MEDIA_LIBRARY_BALANCED_MODE = 2<br>} | Enumerates the delivery modes of the requested media asset.|
