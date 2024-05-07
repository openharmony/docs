# media_asset_base_capi.h


## 概述

定义了媒体资产管理器的结构和枚举。

[OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager)结构体：该结构体提供了从媒体库请求资源的能力。

[MediaLibrary_RequestId](_media_library___request_id.md)结构体：在请求媒体库资源时返回的类型。请求Id用于取消请求。

[MediaLibrary_DeliveryMode](_media_asset_manager.md#medialibrary_deliverymode-1)枚举：此枚举定义了请求资源的分发模式。

[OH_MediaLibrary_OnDataPrepared](_media_asset_manager.md#oh_medialibrary_ondataprepared)函数指针：当所请求的媒体资源准备完成时会触发回调。

[MediaLibrary_RequestOptions](_media_library___request_options.md)结构体：此结构体为媒体资源请求策略模式配置项。

**系统能力：**SystemCapability.FileManagement.PhotoAccessHelper.Core

**库：** libmedia_asset_manager.so

**起始版本：** 12

**相关模块：**[MediaAssetManager](_media_asset_manager.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [MediaLibrary_RequestId](_media_library___request_id.md) | 定义请求Id。 | 
| struct  [MediaLibrary_RequestOptions](_media_library___request_options.md) | 请求策略模式配置项。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) [OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) | 定义媒体资产管理器。 | 
| typedef struct [MediaLibrary_RequestId](_media_library___request_id.md) [MediaLibrary_RequestId](_media_asset_manager.md#medialibrary_requestid) | 定义请求Id。 | 
| typedef enum [MediaLibrary_DeliveryMode](_media_asset_manager.md#medialibrary_deliverymode-1) [MediaLibrary_DeliveryMode](_media_asset_manager.md#medialibrary_deliverymode) | 请求资源分发模式。 | 
| typedef void(\* [OH_MediaLibrary_OnDataPrepared](_media_asset_manager.md#oh_medialibrary_ondataprepared)) (int32_t result, [MediaLibrary_RequestId](_media_library___request_id.md) requestId) | 当所请求的媒体资源准备完成时会触发回调。 | 
| typedef struct [MediaLibrary_RequestOptions](_media_library___request_options.md) [MediaLibrary_RequestOptions](_media_asset_manager.md#medialibrary_requestoptions) | 请求策略模式配置项。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [MediaLibrary_DeliveryMode](_media_asset_manager.md#medialibrary_deliverymode-1) {<br/>MEDIA_LIBRARY_FAST_MODE = 0,<br/>MEDIA_LIBRARY_HIGH_QUALITY_MODE = 1,<br/>MEDIA_LIBRARY_BALANCED_MODE = 2<br/>} | 请求资源分发模式。 | 
