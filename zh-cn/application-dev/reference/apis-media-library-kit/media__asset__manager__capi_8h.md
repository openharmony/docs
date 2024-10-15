# media_asset_manager_capi.h


## 概述

定义媒体资产管理器的接口。

使用由媒体资产管理器提供的C API来请求媒体库资源。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**库：** libmedia_asset_manager.so

**引用文件：** &lt;multimedia/media_library/media_asset_manager_capi.h&gt;

**起始版本：** 12

**相关模块：**[MediaAssetManager](_media_asset_manager.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) \* [OH_MediaAssetManager_Create](_media_asset_manager.md#oh_mediaassetmanager_create) (void) | 创建一个媒体资产管理器。  | 
| [MediaLibrary_RequestId](_media_library___request_id.md) [OH_MediaAssetManager_RequestImageForPath](_media_asset_manager.md#oh_mediaassetmanager_requestimageforpath) ([OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) \*manager, const char \*uri, [MediaLibrary_RequestOptions](_media_library___request_options.md) requestOptions, const char \*destPath, [OH_MediaLibrary_OnDataPrepared](_media_asset_manager.md#oh_medialibrary_ondataprepared) callback) | 请求具有目标路径的图像资源。  | 
| [MediaLibrary_RequestId](_media_library___request_id.md) [OH_MediaAssetManager_RequestVideoForPath](_media_asset_manager.md#oh_mediaassetmanager_requestvideoforpath) ([OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) \*manager, const char \*uri, [MediaLibrary_RequestOptions](_media_library___request_options.md) requestOptions, const char \*destPath, [OH_MediaLibrary_OnDataPrepared](_media_asset_manager.md#oh_medialibrary_ondataprepared) callback) | 请求具有目标路径的视频资源。  | 
| bool [OH_MediaAssetManager_CancelRequest](_media_asset_manager.md#oh_mediaassetmanager_cancelrequest) ([OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) \*manager, const [MediaLibrary_RequestId](_media_library___request_id.md) requestId) | 通过请求Id取消请求。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAssetManager_RequestMovingPhoto](_media_asset_manager.md#oh_mediaassetmanager_requestmovingphoto) ([OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) \*manager, [OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, [MediaLibrary_RequestOptions](_media_library___request_options.md) requestOptions, [MediaLibrary_RequestId](_media_library___request_id.md) \*requestId, [OH_MediaLibrary_OnMovingPhotoDataPrepared](_media_asset_manager.md#oh_medialibrary_onmovingphotodataprepared) callback) | 根据不同的策略模式请求动态照片资源。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAssetManager_RequestImage](_media_asset_manager.md#oh_mediaassetmanager_requestimage) ([OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) \*manager, [OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) \*mediaAsset, [MediaLibrary_RequestOptions](_media_library___request_options.md) requestOptions, [MediaLibrary_RequestId](_media_library___request_id.md) \*requestId, [OH_MediaLibrary_OnImageDataPrepared](_media_asset_manager.md#oh_medialibrary_onimagedataprepared) callback) | 根据不同的策略模式请求图像资源。  | 
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) [OH_MediaAssetManager_Release](_media_asset_manager.md#oh_mediaassetmanager_release) ([OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) \*manager) | 释放[OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager)实例。  | 
