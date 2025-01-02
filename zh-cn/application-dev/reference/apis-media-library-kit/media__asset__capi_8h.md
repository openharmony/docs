# media_asset_capi.h


## 概述

定义与媒体资源相关的API。

提供获取图像或视频信息的能力。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**库：** libmedia_asset_manager.so

**引用文件：** &lt;multimedia/media_library/media_asset_capi.h&gt;

**起始版本：** 12

**相关模块：**[MediaAssetManager](_media_asset_manager.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetUri](_media_asset_manager.md#oh_mediaasset_geturi) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, const char \*\*uri) | 获取媒体资产的uri。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetMediaType](_media_asset_manager.md#oh_mediaasset_getmediatype) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, [MediaLibrary_MediaType](_media_asset_manager.md#medialibrary_mediatype) \*mediaType) | 获取媒体资源类型。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetMediaSubType](_media_asset_manager.md#oh_mediaasset_getmediasubtype) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, [MediaLibrary_MediaSubType](_media_asset_manager.md#medialibrary_mediasubtype) \*mediaSubType) | 获取媒体资源子类型。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetDisplayName](_media_asset_manager.md#oh_mediaasset_getdisplayname) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, const char \*\*displayName) | 获取媒体资源的显示名称。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetSize](_media_asset_manager.md#oh_mediaasset_getsize) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*size) | 获取媒体资产的文件大小。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetDateAdded](_media_asset_manager.md#oh_mediaasset_getdateadded) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*dateAdded) | 获取资产添加日期。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetDateModified](_media_asset_manager.md#oh_mediaasset_getdatemodified) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*dateModified) | 获取资产的修改日期。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetDateTaken](_media_asset_manager.md#oh_mediaasset_getdatetaken) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*dateTaken) | 获取资产的拍摄日期。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetDateAddedMs](_media_asset_manager.md#oh_mediaasset_getdateaddedms) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*dateAddedMs) | 获取资产的添加时间（毫秒）。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetDateModifiedMs](_media_asset_manager.md#oh_mediaasset_getdatemodifiedms) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*dateModifiedMs) | 获取资产的修改时间（毫秒）。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetDuration](_media_asset_manager.md#oh_mediaasset_getduration) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*duration) | 获取媒体资源的持续时间（毫秒）。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetWidth](_media_asset_manager.md#oh_mediaasset_getwidth) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*width) | 获取媒体资源的图像宽度（像素）。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetHeight](_media_asset_manager.md#oh_mediaasset_getheight) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*height) | 获取媒体资源的图像高度（像素）。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetOrientation](_media_asset_manager.md#oh_mediaasset_getorientation) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*orientation) | 获取图像的旋转角度，单位为度。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_IsFavorite](_media_asset_manager.md#oh_mediaasset_isfavorite) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, uint32_t \*favorite) | 获取资产的收藏状态。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_GetTitle](_media_asset_manager.md#oh_mediaasset_gettitle) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, const char \*\*title) | 获取媒体资产的标题。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAsset_Release](_media_asset_manager.md#oh_mediaasset_release) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset) | 释放媒体资产  | 
