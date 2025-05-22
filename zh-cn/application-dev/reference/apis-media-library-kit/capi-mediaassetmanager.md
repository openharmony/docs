# MediaAssetManager

## 概述

提供媒体库资源请求能力的API。

**起始版本：** 12
## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [media_access_helper_capi.h](capi-media-access-helper-capi-h.md) | 定义与相册管理模块相关的API。提供创建相册的功能，以及访问和修改相册中的媒体数据信息的功能。 |
| [media_asset_base_capi.h](capi-media-asset-base-capi-h.md) | 定义了媒体资产管理器的结构和枚举。OH_MediaAssetManager结构体：该结构体提供了从媒体库请求资源的能力。 <br>MediaLibrary_RequestId结构体：在请求媒体库资源时返回的类型。请求Id用于取消请求。 <br>MediaLibrary_DeliveryMode枚举：此枚举定义了请求资源的分发模式。 <br>OH_MediaLibrary_OnDataPrepared函数指针：当所请求的媒体资源准备完成时会触发回调。 <br>MediaLibrary_RequestOptions结构体：此结构体为媒体资源请求策略模式配置项。 <br> |
| [media_asset_capi.h](capi-media-asset-capi-h.md) | 定义与媒体资源相关的API。提供获取图像或视频信息的能力。 |
| [media_asset_change_request_capi.h](capi-media-asset-change-request-capi-h.md) | 定义与媒体资产更改请求相关的API。提供更改资产的能力。 |
| [media_asset_manager_capi.h](capi-media-asset-manager-capi-h.md) | 定义媒体资产管理器的接口。使用由媒体资产管理器提供的C API来请求媒体库资源。 |
| [moving_photo_capi.h](capi-moving-photo-capi-h.md) | 定义与动态照片相关的API。提供获取动态照片信息的功能。 |
