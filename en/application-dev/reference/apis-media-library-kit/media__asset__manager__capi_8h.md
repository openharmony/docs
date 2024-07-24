# media_asset_manager_capi.h


## Overview

Defines the functions of the media asset manager.

You can use the functions to request media assets in the media library.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Library**: libmedia_asset_manager.so

**Since**: 12

**Related module**: [MediaAssetManager](_media_asset_manager.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) \* [OH_MediaAssetManager_Create](_media_asset_manager.md#oh_mediaassetmanager_create) (void) | Creates a **MediaAssetManager** instance.|
| [MediaLibrary_RequestId](_media_library___request_id.md) [OH_MediaAssetManager_RequestImageForPath](_media_asset_manager.md#oh_mediaassetmanager_requestimageforpath) ([OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) \*manager, const char \*uri, [MediaLibrary_RequestOptions](_media_library___request_options.md) requestOptions, const char \*destPath, [OH_MediaLibrary_OnDataPrepared](_media_asset_manager.md#oh_medialibrary_ondataprepared) callback) | Requests an image in the specified directory.|
| [MediaLibrary_RequestId](_media_library___request_id.md) [OH_MediaAssetManager_RequestVideoForPath](_media_asset_manager.md#oh_mediaassetmanager_requestvideoforpath) ([OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) \*manager, const char \*uri, [MediaLibrary_RequestOptions](_media_library___request_options.md) requestOptions, const char \*destPath, [OH_MediaLibrary_OnDataPrepared](_media_asset_manager.md#oh_medialibrary_ondataprepared) callback) | Requests a video in the specified directory.|
| bool [OH_MediaAssetManager_CancelRequest](_media_asset_manager.md#oh_mediaassetmanager_cancelrequest) ([OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) \*manager, const [MediaLibrary_RequestId](_media_library___request_id.md) requestId) | Cancels a request based on the request ID.|
