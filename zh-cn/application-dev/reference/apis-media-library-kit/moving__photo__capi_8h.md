# moving_photo_capi.h


## 概述

定义与动态照片相关的API。

提供获取动态照片信息的功能。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**库：** libmedia_asset_manager.so

**引用文件：** &lt;multimedia/media_library/moving_photo_capi.h&gt;

**起始版本：** 13

**相关模块：**[MediaAssetManager](_media_asset_manager.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MovingPhoto_GetUri](_media_asset_manager.md#oh_movingphoto_geturi) ([OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto) \*movingPhoto, const char \*\*uri) | 获取动态照片的uri。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MovingPhoto_RequestContentWithUris](_media_asset_manager.md#oh_movingphoto_requestcontentwithuris) ([OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto) \*movingPhoto, char \*imageUri, char \*videoUri) | 同时请求动态照片的图片内容和视频内容，并写入参数指定的对应的uri中。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MovingPhoto_RequestContentWithUri](_media_asset_manager.md#oh_movingphoto_requestcontentwithuri) ([OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto) \*movingPhoto, [MediaLibrary_ResourceType](_media_asset_manager.md#medialibrary_resourcetype) resourceType, char \*uri) | 请求指定资源类型的动态照片内容，并写入参数指定的uri中。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MovingPhoto_RequestContentWithBuffer](_media_asset_manager.md#oh_movingphoto_requestcontentwithbuffer) ([OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto) \*movingPhoto, [MediaLibrary_ResourceType](_media_asset_manager.md#medialibrary_resourcetype) resourceType, const uint8_t \*\*buffer, uint32_t \*size) | 请求指定资源类型的动态照片内容，以ArrayBuffer的形式返回。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MovingPhoto_Release](_media_asset_manager.md#oh_movingphoto_release) ([OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto) \*movingPhoto) | Release [OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto)实例。  | 
