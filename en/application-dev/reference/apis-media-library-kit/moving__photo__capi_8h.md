# moving_photo_capi.h


## Overview

Provides the APIs related to moving photos.

You can use the APIs to obtain moving photo information.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Library**: libmedia_asset_manager.so

**File to include**: &lt;multimedia/media_library/moving_photo_capi.h&gt;

**Since**: 13

**Related module**: [MediaAssetManager](_media_asset_manager.md)


## Summary


### Functions

| Function| Description| 
| -------- | -------- |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MovingPhoto_GetUri](_media_asset_manager.md#oh_movingphoto_geturi) ([OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto) \*movingPhoto, const char \*\*uri) | Obtains the URI of a moving photo. | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MovingPhoto_RequestContentWithUris](_media_asset_manager.md#oh_movingphoto_requestcontentwithuris) ([OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto) \*movingPhoto, char \*imageUri, char \*videoUri) | Requests the image data and video data of a moving photo and writes them to the specified URIs, respectively. | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MovingPhoto_RequestContentWithUri](_media_asset_manager.md#oh_movingphoto_requestcontentwithuri) ([OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto) \*movingPhoto, [MediaLibrary_ResourceType](_media_asset_manager.md#medialibrary_resourcetype) resourceType, char \*uri) | Requests the moving photo content of the specified resource type and writes it to the specified URI. | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MovingPhoto_RequestContentWithBuffer](_media_asset_manager.md#oh_movingphoto_requestcontentwithbuffer) ([OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto) \*movingPhoto, [MediaLibrary_ResourceType](_media_asset_manager.md#medialibrary_resourcetype) resourceType, const uint8_t \*\*buffer, uint32_t \*size) | Requests the moving photo content of the specified resource type and returns it in ArrayBuffer format. | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MovingPhoto_Release](_media_asset_manager.md#oh_movingphoto_release) ([OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto) \*movingPhoto) | Releases an [OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto) instance. | 
