# media_asset_change_request_capi.h


## 概述

定义与媒体资产更改请求相关的API。

提供更改资产的能力。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**库：** libmedia_asset_manager.so

**引用文件：** &lt;multimedia/media_library/media_asset_change_request_capi.h&gt;

**起始版本：** 12

**相关模块：**[MediaAssetManager](_media_asset_manager.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) \* [OH_MediaAssetChangeRequest_Create](_media_asset_manager.md#oh_mediaassetchangerequest_create) ([OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset) | 创建[OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest)实例。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAssetChangeRequest_AddResourceWithUri](_media_asset_manager.md#oh_mediaassetchangerequest_addresourcewithuri) ([OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) \*changeRequest, [MediaLibrary_ResourceType](_media_asset_manager.md#medialibrary_resourcetype) resourceType, char \*fileUri) | 通过文件uri添加资源。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAssetChangeRequest_AddResourceWithBuffer](_media_asset_manager.md#oh_mediaassetchangerequest_addresourcewithbuffer) ([OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) \*changeRequest, [MediaLibrary_ResourceType](_media_asset_manager.md#medialibrary_resourcetype) resourceType, uint8_t \*buffer, uint32_t length) | 通过ArrayBuffer数据添加资源。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAssetChangeRequest_GetWriteCacheHandler](_media_asset_manager.md#oh_mediaassetchangerequest_getwritecachehandler) ([OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) \*changeRequest, int32_t \*fd) | 获取临时文件写句柄。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAssetChangeRequest_SaveCameraPhoto](_media_asset_manager.md#oh_mediaassetchangerequest_savecameraphoto) ([OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) \*changeRequest, [MediaLibrary_ImageFileType](_media_asset_manager.md#medialibrary_imagefiletype) imageFileType) | 保存相机拍摄的照片资源。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAssetChangeRequest_DiscardCameraPhoto](_media_asset_manager.md#oh_mediaassetchangerequest_discardcameraphoto) ([OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) \*changeRequest) | 丢弃相机拍摄的照片资源。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAssetChangeRequest_Release](_media_asset_manager.md#oh_mediaassetchangerequest_release) ([OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) \*changeRequest) | 释放[OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest)实例。  | 
