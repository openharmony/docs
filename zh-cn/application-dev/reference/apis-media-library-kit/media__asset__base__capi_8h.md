# media_asset_base_capi.h


## 概述

定义了媒体资产管理器的结构和枚举。

[OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager)结构体：该结构体提供了从媒体库请求资源的能力。

[MediaLibrary_RequestId](_media_library___request_id.md)结构体：在请求媒体库资源时返回的类型。请求Id用于取消请求。

[MediaLibrary_DeliveryMode](_media_asset_manager.md#medialibrary_deliverymode-1)枚举：此枚举定义了请求资源的分发模式。

[OH_MediaLibrary_OnDataPrepared](_media_asset_manager.md#oh_medialibrary_ondataprepared)函数指针：当所请求的媒体资源准备完成时会触发回调。

[MediaLibrary_RequestOptions](_media_library___request_options.md)结构体：此结构体为媒体资源请求策略模式配置项。

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**库：** libmedia_asset_manager.so

**引用文件：** &lt;multimedia/media_library/media_asset_base_capi.h&gt;

**起始版本：** 12

**相关模块：**[MediaAssetManager](_media_asset_manager.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [MediaLibrary_RequestId](_media_library___request_id.md) | 定义请求Id。  | 
| struct  [MediaLibrary_RequestOptions](_media_library___request_options.md) | 请求策略模式配置项。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) [OH_MediaAssetManager](_media_asset_manager.md#oh_mediaassetmanager) | 定义媒体资产管理器。  | 
| typedef struct [OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) [OH_MediaAssetChangeRequest](_media_asset_manager.md#oh_mediaassetchangerequest) | 定义媒体资产更改请求。  | 
| typedef struct [OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto) [OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto) | 定义动态照片。  | 
| typedef struct [OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) [OH_MediaAsset](_media_asset_manager.md#oh_mediaasset) | 定义媒体资产。  | 
| typedef struct [MediaLibrary_RequestId](_media_library___request_id.md) [MediaLibrary_RequestId](_media_asset_manager.md#medialibrary_requestid) | 定义请求Id。  | 
| typedef enum [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode-1) [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) | 媒体库错误代码的枚举。  | 
| typedef enum [MediaLibrary_DeliveryMode](_media_asset_manager.md#medialibrary_deliverymode-1) [MediaLibrary_DeliveryMode](_media_asset_manager.md#medialibrary_deliverymode) | 请求资源分发模式。  | 
| typedef struct [MediaLibrary_RequestOptions](_media_library___request_options.md) [MediaLibrary_RequestOptions](_media_asset_manager.md#medialibrary_requestoptions) | 请求策略模式配置项。  | 
| typedef enum [MediaLibrary_MediaType](_media_asset_manager.md#medialibrary_mediatype-1) [MediaLibrary_MediaType](_media_asset_manager.md#medialibrary_mediatype) | 媒体类型的枚举。  | 
| typedef enum [MediaLibrary_MediaSubType](_media_asset_manager.md#medialibrary_mediasubtype-1) [MediaLibrary_MediaSubType](_media_asset_manager.md#medialibrary_mediasubtype) | 媒体资源子类型的枚举。  | 
| typedef enum [MediaLibrary_ResourceType](_media_asset_manager.md#medialibrary_resourcetype-1) [MediaLibrary_ResourceType](_media_asset_manager.md#medialibrary_resourcetype) | 资源类型的枚举。  | 
| typedef enum [MediaLibrary_ImageFileType](_media_asset_manager.md#medialibrary_imagefiletype-1) [MediaLibrary_ImageFileType](_media_asset_manager.md#medialibrary_imagefiletype) | 图像文件类型的枚举。  | 
| typedef enum [MediaLibrary_MediaQuality](_media_asset_manager.md#medialibrary_mediaquality-1) [MediaLibrary_MediaQuality](_media_asset_manager.md#medialibrary_mediaquality) | 媒体资源质量枚举。  | 
| typedef enum [MediaLibrary_MediaContentType](_media_asset_manager.md#medialibrary_mediacontenttype-1) [MediaLibrary_MediaContentType](_media_asset_manager.md#medialibrary_mediacontenttype) | 媒体内容类型的枚举。  | 
| typedef void(\* [OH_MediaLibrary_OnDataPrepared](_media_asset_manager.md#oh_medialibrary_ondataprepared)) (int32_t result, [MediaLibrary_RequestId](_media_library___request_id.md) requestId) | 当所请求的媒体资源准备完成时会触发回调。  | 
| typedef void(\* [OH_MediaLibrary_OnImageDataPrepared](_media_asset_manager.md#oh_medialibrary_onimagedataprepared)) ([MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) result, [MediaLibrary_RequestId](_media_library___request_id.md) requestId, [MediaLibrary_MediaQuality](_media_asset_manager.md#medialibrary_mediaquality) mediaQuality, [MediaLibrary_MediaContentType](_media_asset_manager.md#medialibrary_mediacontenttype) type, [OH_ImageSourceNative](_media_asset_manager.md#oh_imagesourcenative) *imageSourceNative) | 当请求的图像源准备就绪时调用。  | 
| typedef void(\* [OH_MediaLibrary_OnMovingPhotoDataPrepared](_media_asset_manager.md#oh_medialibrary_onmovingphotodataprepared)) ([MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) result, [MediaLibrary_RequestId](_media_library___request_id.md) requestId, [MediaLibrary_MediaQuality](_media_asset_manager.md#medialibrary_mediaquality) mediaQuality, [MediaLibrary_MediaContentType](_media_asset_manager.md#medialibrary_mediacontenttype) type, [OH_MovingPhoto](_media_asset_manager.md#oh_movingphoto) \*movingPhoto) | 当请求的动态照片准备就绪时调用。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [MediaLibrary_ErrorCode](_media_asset_manager.md#medialibrary_errorcode) {<br/>MEDIA_LIBRARY_OK = 0,<br/>MEDIA_LIBRARY_PERMISSION_DENIED = 201,<br/>MEDIA_LIBRARY_PARAMETER_ERROR = 401,<br/>MEDIA_LIBRARY_NO_SUCH_FILE = 23800101,<br/>MEDIA_LIBRARY_INVALID_DISPLAY_NAME = 23800102,<br/>MEDIA_LIBRARY_INVALID_ASSET_URI = 23800103,<br/>MEDIA_LIBRARY_INVALID_PHOTO_KEY = 23800104,<br/>MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED = 23800201,<br/>MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR = 23800301<br/>} | 媒体库错误代码的枚举。 | 
| [MediaLibrary_DeliveryMode](_media_asset_manager.md#medialibrary_deliverymode) {<br/>MEDIA_LIBRARY_FAST_MODE = 0,<br/>MEDIA_LIBRARY_HIGH_QUALITY_MODE = 1,<br/>MEDIA_LIBRARY_BALANCED_MODE = 2 } | 请求资源分发模式。 | 
| [MediaLibrary_MediaType](_media_asset_manager.md#medialibrary_mediatype) {<br/>MEDIA_LIBRARY_IMAGE = 1,<br/>MEDIA_LIBRARY_VIDEO = 2 } | 媒体类型的枚举。 | 
| [MediaLibrary_MediaSubType](_media_asset_manager.md#medialibrary_mediasubtype) {<br/>MEDIA_LIBRARY_DEFAULT = 0,<br/>MEDIA_LIBRARY_MOVING_PHOTO = 3,<br/>MEDIA_LIBRARY_BURST = 4 } | 媒体资源子类型的枚举。 | 
| [MediaLibrary_ResourceType](_media_asset_manager.md#medialibrary_resourcetype) {<br/>MEDIA_LIBRARY_IMAGE_RESOURCE = 1,<br/>MEDIA_LIBRARY_VIDEO_RESOURCE = 2 } | 资源类型的枚举。 | 
| [MediaLibrary_ImageFileType](_media_asset_manager.md#medialibrary_imagefiletype) {<br/>MEDIA_LIBRARY_IMAGE_JPEG = 1 } | 图像文件类型的枚举。 | 
| [MediaLibrary_MediaQuality](_media_asset_manager.md#medialibrary_mediaquality) {<br/>MEDIA_LIBRARY_QUALITY_FAST = 1,<br/>MEDIA_LIBRARY_QUALITY_FULL = 2 } | 媒体资源质量枚举。 | 
| [MediaLibrary_MediaContentType](_media_asset_manager.md#medialibrary_mediacontenttype) {<br/>MEDIA_LIBRARY_COMPRESSED = 1,<br/>MEDIA_LIBRARY_PICTURE_OBJECT = 2 } | 媒体内容类型的枚举。 | 
