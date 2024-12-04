# media_asset_capi.h


## Overview

Defines the APIs related to media assets.

You can use the APIs to obtain image or video information.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Library**: libmedia_asset_manager.so

**File to include**: &lt;multimedia/media_library/media_asset_capi.h&gt;

**Since**: 12

**Related module**: [MediaAssetManager](_media_asset_manager.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetUri](_media_asset_manager.md#oh_mediaasset_geturi) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, const char \*\*uri) | Obtains the URI of a media asset. |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetMediaType](_media_asset_manager.md#oh_mediaasset_getmediatype) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, [MediaLibrary_MediaType](_media_asset_manager.md#medialibrary_mediatype) \*mediaType) | Obtains the type of a media asset. |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetMediaSubType](_media_asset_manager.md#oh_mediaasset_getmediasubtype) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, [MediaLibrary_MediaSubType](_media_asset_manager.md#medialibrary_mediasubtype) \*mediaSubType) | Obtains the subtype of a media asset. |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetDisplayName](_media_asset_manager.md#oh_mediaasset_getdisplayname) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, const char \*\*displayName) | Obtains the displayed name of a media asset. |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetSize](_media_asset_manager.md#oh_mediaasset_getsize) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*size) | Obtains the size of a media asset file. |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetDateAdded](_media_asset_manager.md#oh_mediaasset_getdateadded) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*dateAdded) | Obtains the date when a media asset was added. |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetDateModified](_media_asset_manager.md#oh_mediaasset_getdatemodified) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*dateModified) | Obtains the date when a media asset was last modified. |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetDateTaken](_media_asset_manager.md#oh_mediaasset_getdatetaken) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*dateTaken) | Obtains the date when a media asset was taken. |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetDateAddedMs](_media_asset_manager.md#oh_mediaasset_getdateaddedms) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*dateAddedMs) | Obtains the date when a media asset was added, in ms. |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetDateModifiedMs](_media_asset_manager.md#oh_mediaasset_getdatemodifiedms) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*dateModifiedMs) | Obtains the date when a media asset was last modified, in ms. |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetDuration](_media_asset_manager.md#oh_mediaasset_getduration) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*duration) | Obtains the duration of a media asset, in ms. |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetWidth](_media_asset_manager.md#oh_mediaasset_getwidth) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*width) | Obtains the image width (in pixels) of a media asset. |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetHeight](_media_asset_manager.md#oh_mediaasset_getheight) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*height) | Obtains the image height (in pixels) of a media asset. |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetOrientation](_media_asset_manager.md#oh_mediaasset_getorientation) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*orientation) | Obtains the orientation of a media asset, in degrees. |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_IsFavorite](_media_asset_manager.md#oh_mediaasset_isfavorite) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*favorite) | Checks whether a media asset is favorited. |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetTitle](_media_asset_manager.md#oh_mediaasset_gettitle) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, const char \*\*title) | Obtains the title of a media asset. |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_Release](_media_asset_manager.md#oh_mediaasset_release) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset) | Releases a media asset. |
