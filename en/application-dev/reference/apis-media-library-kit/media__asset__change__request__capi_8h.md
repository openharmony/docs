# media_asset_change_request_capi.h


## Overview

Defines the APIs related to media asset change requests.

You can use the APIs to change media assets.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Library**: libmedia_asset_manager.so

**File to include**: &lt;multimedia/media_library/media_asset_change_request_capi.h&gt;

**Since**: 12

**Related module**: [MediaAssetManager](_media_asset_manager.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) \* [OH_MediaAssetChangeRequest_Create](_media_asset_manager.md#oh_mediaassetchangerequest_create) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset) | Creates an [OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) instance.| 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAssetChangeRequest_AddResourceWithBuffer](_media_asset_manager.md#oh_mediaassetchangerequest_addresourcewithbuffer) ([OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) \*changeRequest, [MediaLibrary_ResourceType](_media_asset_manager.md#medialibrary_resourcetype) resourceType, uint8_t \*buffer, uint32_t length) | Adds a resource using **ArrayBuffer** data.| 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAssetChangeRequest_SaveCameraPhoto](_media_asset_manager.md#oh_mediaassetchangerequest_savecameraphoto) ([OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) \*changeRequest, [MediaLibrary_ImageFileType](_media_asset_manager.md#medialibrary_imagefiletype) imageFileType) | Saves the photo taken by the camera.| 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAssetChangeRequest_DiscardCameraPhoto](_media_asset_manager.md#oh_mediaassetchangerequest_discardcameraphoto) ([OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) \*changeRequest) | Discards the photo taken by the camera.| 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAssetChangeRequest_Release](_media_asset_manager.md#oh_mediaassetchangerequest_release) ([OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) \*changeRequest) | Releases an [OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) instance.| 
