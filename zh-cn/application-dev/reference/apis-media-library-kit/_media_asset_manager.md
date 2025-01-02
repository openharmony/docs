# MediaAssetManager


## 概述

提供媒体库资源请求能力的API。

对应的开发指南及样例可参考[使用MediaAssetManager请求图片资源](../../media/medialibrary/using-ndk-mediaassetmanager-for-request-resource.md)。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [media_access_helper_capi.h](media__access__helper__capi_8h.md) | 定义与相册管理模块相关的API。  | 
| [media_asset_base_capi.h](media__asset__base__capi_8h.md) | 定义了媒体资产管理器的结构和枚举。  | 
| [media_asset_capi.h](media__asset__capi_8h.md) | 定义与媒体资源相关的API。  | 
| [media_asset_change_request_capi.h](media__asset__change__request__capi_8h.md) | 定义与媒体资产更改请求相关的API。  | 
| [media_asset_manager_capi.h](media__asset__manager__capi_8h.md) | 定义媒体资产管理器的接口。  | 
| [moving_photo_capi.h](moving__photo__capi_8h.md) | 定义与动态照片相关的API。  | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [MediaLibrary_RequestId](_media_library___request_id.md) | 定义请求Id。  | 
| struct  [MediaLibrary_RequestOptions](_media_library___request_options.md) | 请求策略模式配置项。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_MediaAssetManager](#oh_mediaassetmanager) [OH_MediaAssetManager](#oh_mediaassetmanager) | 定义媒体资产管理器。  | 
| typedef struct [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) | 定义媒体资产更改请求。  | 
| typedef struct [OH_MovingPhoto](#oh_movingphoto) [OH_MovingPhoto](#oh_movingphoto) | 定义动态照片。  | 
| typedef struct [OH_MediaAsset](#oh_mediaasset) [OH_MediaAsset](#oh_mediaasset) | 定义媒体资产。  | 
| typedef struct [MediaLibrary_RequestId](_media_library___request_id.md) [MediaLibrary_RequestId](#medialibrary_requestid) | 定义请求Id。  | 
| typedef enum [MediaLibrary_ErrorCode](#medialibrary_errorcode-1) [MediaLibrary_ErrorCode](#medialibrary_errorcode) | 媒体库错误代码的枚举。  | 
| typedef enum [MediaLibrary_DeliveryMode](#medialibrary_deliverymode-1) [MediaLibrary_DeliveryMode](#medialibrary_deliverymode) | 请求资源分发模式。  | 
| typedef struct [MediaLibrary_RequestOptions](_media_library___request_options.md) [MediaLibrary_RequestOptions](#medialibrary_requestoptions) | 请求策略模式配置项。  | 
| typedef enum [MediaLibrary_MediaType](#medialibrary_mediatype-1) [MediaLibrary_MediaType](#medialibrary_mediatype) | 媒体类型的枚举。  | 
| typedef enum [MediaLibrary_MediaSubType](#medialibrary_mediasubtype-1) [MediaLibrary_MediaSubType](#medialibrary_mediasubtype) | 媒体资源子类型的枚举。  | 
| typedef enum [MediaLibrary_ResourceType](#medialibrary_resourcetype-1) [MediaLibrary_ResourceType](#medialibrary_resourcetype) | 资源类型的枚举。  | 
| typedef enum [MediaLibrary_ImageFileType](#medialibrary_imagefiletype-1) [MediaLibrary_ImageFileType](#medialibrary_imagefiletype) | 图像文件类型的枚举。  | 
| typedef enum [MediaLibrary_MediaQuality](#medialibrary_mediaquality-1) [MediaLibrary_MediaQuality](#medialibrary_mediaquality) | 媒体资源质量枚举。  | 
| typedef enum [MediaLibrary_MediaContentType](#medialibrary_mediacontenttype-1) [MediaLibrary_MediaContentType](#medialibrary_mediacontenttype) | 媒体内容类型的枚举。  | 
| typedef void(\* [OH_MediaLibrary_OnDataPrepared](#oh_medialibrary_ondataprepared)) (int32_t result, [MediaLibrary_RequestId](_media_library___request_id.md) requestId) | 当所请求的媒体资源准备完成时会触发回调。  | 
| typedef void(\* [OH_MediaLibrary_OnImageDataPrepared](#oh_medialibrary_onimagedataprepared)) ([MediaLibrary_ErrorCode](#medialibrary_errorcode) result, [MediaLibrary_RequestId](_media_library___request_id.md) requestId, [MediaLibrary_MediaQuality](#medialibrary_mediaquality) mediaQuality, [MediaLibrary_MediaContentType](#medialibrary_mediacontenttype) type, OH_ImageSourceNative \*imageSourceNative) | 当请求的图像源准备就绪时调用。  | 
| typedef void(\* [OH_MediaLibrary_OnMovingPhotoDataPrepared](#oh_medialibrary_onmovingphotodataprepared)) ([MediaLibrary_ErrorCode](#medialibrary_errorcode) result, [MediaLibrary_RequestId](_media_library___request_id.md) requestId, [MediaLibrary_MediaQuality](#medialibrary_mediaquality) mediaQuality, [MediaLibrary_MediaContentType](#medialibrary_mediacontenttype) type, [OH_MovingPhoto](#oh_movingphoto) \*movingPhoto) | 当请求的动态照片准备就绪时调用。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [MediaLibrary_ErrorCode](#medialibrary_errorcode-1) {<br/>MEDIA_LIBRARY_OK = 0,<br/>MEDIA_LIBRARY_PERMISSION_DENIED = 201,<br/>MEDIA_LIBRARY_PARAMETER_ERROR = 401,<br/>MEDIA_LIBRARY_NO_SUCH_FILE = 23800101,<br/>MEDIA_LIBRARY_INVALID_DISPLAY_NAME = 23800102,<br/>MEDIA_LIBRARY_INVALID_ASSET_URI = 23800103,<br/>MEDIA_LIBRARY_INVALID_PHOTO_KEY = 23800104,<br/>MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED = 23800201,<br/>MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR = 23800301<br/>} | 媒体库错误代码的枚举。 | 
| [MediaLibrary_DeliveryMode](#medialibrary_deliverymode-1) {<br/>MEDIA_LIBRARY_FAST_MODE = 0,<br/>MEDIA_LIBRARY_HIGH_QUALITY_MODE = 1,<br/>MEDIA_LIBRARY_BALANCED_MODE = 2 } | 请求资源分发模式。 | 
| [MediaLibrary_MediaType](#medialibrary_mediatype-1) {<br/>MEDIA_LIBRARY_IMAGE = 1,<br/>MEDIA_LIBRARY_VIDEO = 2 } | 媒体类型的枚举。 | 
| [MediaLibrary_MediaSubType](#medialibrary_mediasubtype-1) {<br/>MEDIA_LIBRARY_DEFAULT = 0,<br/>MEDIA_LIBRARY_MOVING_PHOTO = 3,<br/>MEDIA_LIBRARY_BURST = 4 } | 媒体资源子类型的枚举。 | 
| [MediaLibrary_ResourceType](#medialibrary_resourcetype-1) {<br/>MEDIA_LIBRARY_IMAGE_RESOURCE = 1,<br/>MEDIA_LIBRARY_VIDEO_RESOURCE = 2 } | 资源类型的枚举。 | 
| [MediaLibrary_ImageFileType](#medialibrary_imagefiletype-1) {<br/>MEDIA_LIBRARY_IMAGE_JPEG = 1 } | 图像文件类型的枚举。 | 
| [MediaLibrary_MediaQuality](#medialibrary_mediaquality-1) {<br/>MEDIA_LIBRARY_QUALITY_FAST = 1,<br/>MEDIA_LIBRARY_QUALITY_FULL = 2 } | 媒体资源质量枚举。 | 
| [MediaLibrary_MediaContentType](#medialibrary_mediacontenttype-1) {<br/>MEDIA_LIBRARY_COMPRESSED = 1,<br/>MEDIA_LIBRARY_PICTURE_OBJECT = 2 } | 媒体内容类型的枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAccessHelper_ApplyChanges](#oh_mediaaccesshelper_applychanges) ([OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) \*changeRequest) | 发起应用资产或相册的更改请求。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetUri](#oh_mediaasset_geturi) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, const char \*\*uri) | 获取媒体资产的uri。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetMediaType](#oh_mediaasset_getmediatype) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, [MediaLibrary_MediaType](#medialibrary_mediatype) \*mediaType) | 获取媒体资源类型。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetMediaSubType](#oh_mediaasset_getmediasubtype) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, [MediaLibrary_MediaSubType](#medialibrary_mediasubtype) \*mediaSubType) | 获取媒体资源子类型。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetDisplayName](#oh_mediaasset_getdisplayname) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, const char \*\*displayName) | 获取媒体资源的显示名称。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetSize](#oh_mediaasset_getsize) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, uint32_t \*size) | 获取媒体资产的文件大小。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetDateAdded](#oh_mediaasset_getdateadded) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, uint32_t \*dateAdded) | 获取资产添加日期。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetDateModified](#oh_mediaasset_getdatemodified) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, uint32_t \*dateModified) | 获取资产的修改日期。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetDateTaken](#oh_mediaasset_getdatetaken) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, uint32_t \*dateTaken) | 获取资产的拍摄日期。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetDateAddedMs](#oh_mediaasset_getdateaddedms) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, uint32_t \*dateAddedMs) | 获取资产的添加时间（毫秒）。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetDateModifiedMs](#oh_mediaasset_getdatemodifiedms) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, uint32_t \*dateModifiedMs) | 获取资产的修改时间（毫秒）。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetDuration](#oh_mediaasset_getduration) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, uint32_t \*duration) | 获取媒体资源的持续时间（毫秒）。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetWidth](#oh_mediaasset_getwidth) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, uint32_t \*width) | 获取媒体资源的图像宽度（像素）。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetHeight](#oh_mediaasset_getheight) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, uint32_t \*height) | 获取媒体资源的图像高度（像素）。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetOrientation](#oh_mediaasset_getorientation) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, uint32_t \*orientation) | 获取图像的旋转角度，单位为度。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_IsFavorite](#oh_mediaasset_isfavorite) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, uint32_t \*favorite) | 获取资产的收藏状态。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_GetTitle](#oh_mediaasset_gettitle) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset, const char \*\*title) | 获取媒体资产的标题。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAsset_Release](#oh_mediaasset_release) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset) | 释放媒体资产  | 
| [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) \* [OH_MediaAssetChangeRequest_Create](#oh_mediaassetchangerequest_create) ([OH_MediaAsset](#oh_mediaasset) \*mediaAsset) | 创建[OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest)实例。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAssetChangeRequest_AddResourceWithUri](#oh_mediaassetchangerequest_addresourcewithuri) ([OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) \*changeRequest, [MediaLibrary_ResourceType](#medialibrary_resourcetype) resourceType, char \*fileUri) | 通过文件uri添加资源。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAssetChangeRequest_AddResourceWithBuffer](#oh_mediaassetchangerequest_addresourcewithbuffer) ([OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) \*changeRequest, [MediaLibrary_ResourceType](#medialibrary_resourcetype) resourceType, uint8_t \*buffer, uint32_t length) | 通过ArrayBuffer数据添加资源。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAssetChangeRequest_GetWriteCacheHandler](#oh_mediaassetchangerequest_getwritecachehandler) ([OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) \*changeRequest, int32_t \*fd) | 获取临时文件写句柄。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAssetChangeRequest_SaveCameraPhoto](#oh_mediaassetchangerequest_savecameraphoto) ([OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) \*changeRequest, [MediaLibrary_ImageFileType](#medialibrary_imagefiletype) imageFileType) | 保存相机拍摄的照片资源。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAssetChangeRequest_DiscardCameraPhoto](#oh_mediaassetchangerequest_discardcameraphoto) ([OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) \*changeRequest) | 丢弃相机拍摄的照片资源。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAssetChangeRequest_Release](#oh_mediaassetchangerequest_release) ([OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest) \*changeRequest) | 释放[OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest)实例。  | 
| [OH_MediaAssetManager](#oh_mediaassetmanager) \* [OH_MediaAssetManager_Create](#oh_mediaassetmanager_create) (void) | 创建一个媒体资产管理器。  | 
| [MediaLibrary_RequestId](_media_library___request_id.md) [OH_MediaAssetManager_RequestImageForPath](#oh_mediaassetmanager_requestimageforpath) ([OH_MediaAssetManager](#oh_mediaassetmanager) \*manager, const char \*uri, [MediaLibrary_RequestOptions](_media_library___request_options.md) requestOptions, const char \*destPath, [OH_MediaLibrary_OnDataPrepared](#oh_medialibrary_ondataprepared) callback) | 请求具有目标路径的图像资源。  | 
| [MediaLibrary_RequestId](_media_library___request_id.md) [OH_MediaAssetManager_RequestVideoForPath](#oh_mediaassetmanager_requestvideoforpath) ([OH_MediaAssetManager](#oh_mediaassetmanager) \*manager, const char \*uri, [MediaLibrary_RequestOptions](_media_library___request_options.md) requestOptions, const char \*destPath, [OH_MediaLibrary_OnDataPrepared](#oh_medialibrary_ondataprepared) callback) | 请求具有目标路径的视频资源。  | 
| bool [OH_MediaAssetManager_CancelRequest](#oh_mediaassetmanager_cancelrequest) ([OH_MediaAssetManager](#oh_mediaassetmanager) \*manager, const [MediaLibrary_RequestId](_media_library___request_id.md) requestId) | 通过请求Id取消请求。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAssetManager_RequestMovingPhoto](#oh_mediaassetmanager_requestmovingphoto) ([OH_MediaAssetManager](#oh_mediaassetmanager) \*manager, [OH_MediaAsset](#oh_mediaasset) \*mediaAsset, [MediaLibrary_RequestOptions](_media_library___request_options.md) requestOptions, [MediaLibrary_RequestId](_media_library___request_id.md) \*requestId, [OH_MediaLibrary_OnMovingPhotoDataPrepared](#oh_medialibrary_onmovingphotodataprepared) callback) | 根据不同的策略模式请求动态照片资源。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAssetManager_RequestImage](#oh_mediaassetmanager_requestimage) ([OH_MediaAssetManager](#oh_mediaassetmanager) \*manager, [OH_MediaAsset](#oh_mediaasset) \*mediaAsset, [MediaLibrary_RequestOptions](_media_library___request_options.md) requestOptions, [MediaLibrary_RequestId](_media_library___request_id.md) \*requestId, [OH_MediaLibrary_OnImageDataPrepared](#oh_medialibrary_onimagedataprepared) callback) | 根据不同的策略模式请求图像资源。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MediaAssetManager_Release](#oh_mediaassetmanager_release) ([OH_MediaAssetManager](#oh_mediaassetmanager) \*manager) | 释放[OH_MediaAssetManager](#oh_mediaassetmanager)实例。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MovingPhoto_GetUri](#oh_movingphoto_geturi) ([OH_MovingPhoto](#oh_movingphoto) \*movingPhoto, const char \*\*uri) | 获取动态照片的uri。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MovingPhoto_RequestContentWithUris](#oh_movingphoto_requestcontentwithuris) ([OH_MovingPhoto](#oh_movingphoto) \*movingPhoto, char \*imageUri, char \*videoUri) | 同时请求动态照片的图片内容和视频内容，并写入参数指定的对应的uri中。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MovingPhoto_RequestContentWithUri](#oh_movingphoto_requestcontentwithuri) ([OH_MovingPhoto](#oh_movingphoto) \*movingPhoto, [MediaLibrary_ResourceType](#medialibrary_resourcetype) resourceType, char \*uri) | 请求指定资源类型的动态照片内容，并写入参数指定的uri中。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MovingPhoto_RequestContentWithBuffer](#oh_movingphoto_requestcontentwithbuffer) ([OH_MovingPhoto](#oh_movingphoto) \*movingPhoto, [MediaLibrary_ResourceType](#medialibrary_resourcetype) resourceType, const uint8_t \*\*buffer, uint32_t \*size) | 请求指定资源类型的动态照片内容，以ArrayBuffer的形式返回。  | 
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) [OH_MovingPhoto_Release](#oh_movingphoto_release) ([OH_MovingPhoto](#oh_movingphoto) \*movingPhoto) | Release [OH_MovingPhoto](#oh_movingphoto)实例。  | 


## 类型定义说明


### MediaLibrary_DeliveryMode

```
typedef enum MediaLibrary_DeliveryMode MediaLibrary_DeliveryMode
```
**描述**
请求资源分发模式。

此枚举定义了请求资源的分发模式。 

- 快速分发：不考虑资源质量，直接基于现有资源返回。

- 高质量分发：返回高质量资源，若没有，则触发生成高质量资源，成功后才返回。

- 均衡分发：若存在高质量资源，则直接返回高质量资源。 否则，先返回低质量资源，并触发生成高质量资源，成功后再返回一次高质量资源。

**起始版本：** 12


### MediaLibrary_ErrorCode

```
typedef enum MediaLibrary_ErrorCode MediaLibrary_ErrorCode
```
**描述**
媒体库错误代码的枚举。

**起始版本：** 12


### MediaLibrary_ImageFileType

```
typedef enum MediaLibrary_ImageFileType MediaLibrary_ImageFileType
```
**描述**
图像文件类型的枚举。

**起始版本：** 12


### MediaLibrary_MediaContentType

```
typedef enum MediaLibrary_MediaContentType MediaLibrary_MediaContentType
```
**描述**
媒体内容类型的枚举。

**起始版本：** 12


### MediaLibrary_MediaQuality

```
typedef enum MediaLibrary_MediaQuality MediaLibrary_MediaQuality
```
**描述**
媒体资源质量枚举。

此枚举与请求媒体资源时定义的分发模式有关。

- 快速分发：不考虑资源质量，直接基于现有资源返回。

- 高质量分发：返回高质量资源，若没有，则触发生成高质量资源，成功后才返回。

- 均衡分发：若存在高质量资源，则直接返回高质量资源。 否则，先返回低质量资源，并触发生成高质量资源，成功后再返回一次高质量资源。

**起始版本：** 12


### MediaLibrary_MediaSubType

```
typedef enum MediaLibrary_MediaSubType MediaLibrary_MediaSubType
```
**描述**
媒体资源子类型的枚举。

**起始版本：** 12


### MediaLibrary_MediaType

```
typedef enum MediaLibrary_MediaType MediaLibrary_MediaType
```
**描述**
媒体类型的枚举。

**起始版本：** 12


### MediaLibrary_RequestId

```
typedef struct MediaLibrary_RequestId MediaLibrary_RequestId
```
**描述**
定义请求Id。

当请求媒体库资源时，会返回此类型。 请求Id用于取消请求。 如果请求失败，值将全为零，如 "00000000-0000-0000-0000-000000000000"。

**起始版本：** 12


### MediaLibrary_RequestOptions

```
typedef struct MediaLibrary_RequestOptions MediaLibrary_RequestOptions
```
**描述**
请求策略模式配置项。

此结构体为媒体资源请求策略模式配置项。

**起始版本：** 12


### MediaLibrary_ResourceType

```
typedef enum MediaLibrary_ResourceType MediaLibrary_ResourceType
```
**描述**
资源类型的枚举。

**起始版本：** 12


### OH_MediaAsset

```
typedef struct OH_MediaAsset OH_MediaAsset
```
**描述**
定义媒体资产。

此结构体提供了封装文件资源属性的能力。

**起始版本：** 12


### OH_MediaAssetChangeRequest

```
typedef struct OH_MediaAssetChangeRequest OH_MediaAssetChangeRequest
```
**描述**
定义媒体资产更改请求。

此结构体提供了处理媒体资产更改请求的能力。

**起始版本：** 12


### OH_MediaAssetManager

```
typedef struct OH_MediaAssetManager OH_MediaAssetManager
```
**描述**
定义媒体资产管理器。

此结构提供了请求媒体库资源的能力。 如果创建失败，则返回空指针。

**起始版本：** 12


### OH_MediaLibrary_OnDataPrepared

```
typedef void (*OH_MediaLibrary_OnDataPrepared)(int32_t result, MediaLibrary_RequestId requestId)
```
**描述**
当所请求的媒体资源准备完成时会触发回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| result | 请求资源处理的结果。  | 
| requestId | 请求Id。  | 


### OH_MediaLibrary_OnImageDataPrepared

```
typedef void (*OH_MediaLibrary_OnImageDataPrepared)(MediaLibrary_ErrorCode result, MediaLibrary_RequestId requestId, MediaLibrary_MediaQuality mediaQuality, MediaLibrary_MediaContentType type, OH_ImageSourceNative* imageSourceNative)
```
**描述**
当请求的图像源准备就绪时调用。

当所请求的图像源准备就绪时，会调用此函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| result | 处理所请求资源的结果[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)。 | 
| requestId | 请求的[MediaLibrary_RequestId](_media_library___request_id.md)。 | 
| mediaQuality | 请求源的[MediaLibrary_MediaQuality](#medialibrary_mediaquality-1)。 | 
| type | 请求源的[MediaLibrary_MediaContentType](#medialibrary_mediacontenttype-1)。 | 
| imageSourceNative | 当请求的图像源准备就绪时获取[OH_ImageSourceNative](../apis-image-kit/_image___native_module.md#oh_imagesourcenative)。 | 


### OH_MediaLibrary_OnMovingPhotoDataPrepared

```
typedef void (*OH_MediaLibrary_OnMovingPhotoDataPrepared)(MediaLibrary_ErrorCode result, MediaLibrary_RequestId requestId, MediaLibrary_MediaQuality mediaQuality, MediaLibrary_MediaContentType type, OH_MovingPhoto* movingPhoto)
```
**描述**
当请求的动态照片准备就绪时调用。

当所请求的动态照片准备就绪时，会调用此函数。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| result | 处理所请求资源的结果[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)。  | 
| requestId | 请求的[MediaLibrary_RequestId](_media_library___request_id.md)。  | 
| mediaQuality | 请求资源的[MediaLibrary_MediaQuality](#medialibrary_mediaquality-1)。  | 
| type | 请求资源的[MediaLibrary_MediaContentType](#medialibrary_mediacontenttype-1)。  | 
| movingPhoto | 当请求的动态图片准备就绪时获取[OH_MovingPhoto](#oh_movingphoto)。  | 


### OH_MovingPhoto

```
typedef struct OH_MovingPhoto OH_MovingPhoto
```
**描述**
定义动态照片。

此结构体提供了获取关于动态照片的信息的能力。

**起始版本：** 13


## 枚举类型说明


### MediaLibrary_DeliveryMode

```
enum MediaLibrary_DeliveryMode
```
**描述**
请求资源分发模式。

此枚举定义了请求资源的分发模式。

- 快速分发：不考虑资源质量，直接基于现有资源返回。

- 高质量分发：返回高质量资源，若没有，则触发生成高质量资源，成功后才返回。

- 均衡分发：若存在高质量资源，则直接返回高质量资源。 否则，先返回低质量资源，并触发生成高质量资源，成功后再返回一次高质量资源。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_LIBRARY_FAST_MODE  | 快速分发。   | 
| MEDIA_LIBRARY_HIGH_QUALITY_MODE  | 高质量分发。   | 
| MEDIA_LIBRARY_BALANCED_MODE  | 均衡分发。   | 


### MediaLibrary_ErrorCode

```
enum MediaLibrary_ErrorCode
```
**描述**
媒体库错误代码的枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_LIBRARY_OK | 媒体库结果正常。 | 
| MEDIA_LIBRARY_PERMISSION_DENIED | 权限被拒绝。 | 
| MEDIA_LIBRARY_PARAMETER_ERROR | 强制参数未指定，参数类型不正确或参数验证失败。 | 
| MEDIA_LIBRARY_NO_SUCH_FILE | 文件不存在。 | 
| MEDIA_LIBRARY_INVALID_DISPLAY_NAME | 显示名称无效。 | 
| MEDIA_LIBRARY_INVALID_ASSET_URI | 资产uri无效。 | 
| MEDIA_LIBRARY_INVALID_PHOTO_KEY | PhotoKey无效。 | 
| MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED | 不支持该操作。 | 
| MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR | 内部系统错误。 建议重试并检查日志。 可能的原因：<br/>1. 数据库已损坏。<br/>2. 文件系统异常。<br/>3. IPC请求超时。 | 


### MediaLibrary_ImageFileType

```
enum MediaLibrary_ImageFileType
```
**描述**
图像文件类型的枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_LIBRARY_IMAGE_JPEG  | JPEG类型。   | 


### MediaLibrary_MediaContentType

```
enum MediaLibrary_MediaContentType
```
**描述**
媒体内容类型的枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_LIBRARY_COMPRESSED  | 压缩媒体内容类型。   | 
| MEDIA_LIBRARY_PICTURE_OBJECT  | 图片对象媒体内容类型。   | 


### MediaLibrary_MediaQuality

```
enum MediaLibrary_MediaQuality
```
**描述**
媒体资源质量枚举。

此枚举与请求媒体资源时定义的分发模式有关。

- 快速分发：不考虑资源质量，直接基于现有资源返回。

- 高质量分发：返回高质量资源，若没有，则触发生成高质量资源，成功后才返回。

- 均衡分发：若存在高质量资源，则直接返回高质量资源。 否则，先返回低质量资源，并触发生成高质量资源，成功后再返回一次高质量资源。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_LIBRARY_QUALITY_FAST  | 不考虑资源质量，直接返回的现有资源。   | 
| MEDIA_LIBRARY_QUALITY_FULL  | 高质量资源。   | 


### MediaLibrary_MediaSubType

```
enum MediaLibrary_MediaSubType
```
**描述**
媒体资源子类型的枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_LIBRARY_DEFAULT  | 默认照片类型。   | 
| MEDIA_LIBRARY_MOVING_PHOTO  | 动态照片类型。   | 
| MEDIA_LIBRARY_BURST  | 连拍照片类型。   | 


### MediaLibrary_MediaType

```
enum MediaLibrary_MediaType
```
**描述**
媒体类型的枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_LIBRARY_IMAGE  | 图像资产。   | 
| MEDIA_LIBRARY_VIDEO  | 视频资产。   | 


### MediaLibrary_ResourceType

```
enum MediaLibrary_ResourceType
```
**描述**
资源类型的枚举。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| MEDIA_LIBRARY_IMAGE_RESOURCE  | 图像资源。   | 
| MEDIA_LIBRARY_VIDEO_RESOURCE  | 视频资源。   | 


## 函数说明


### OH_MediaAccessHelper_ApplyChanges()

```
MediaLibrary_ErrorCode OH_MediaAccessHelper_ApplyChanges(OH_MediaAssetChangeRequest* changeRequest)
```
**描述**
发起应用资产或相册的更改请求。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| changeRequest | 变更请求实例[OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest)。  | 

**需要权限：**

ohos.permission.WRITE_IMAGEVIDEO

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_PERMISSION_DENIED：没有权限。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。


### OH_MediaAsset_GetDateAdded()

```
ediaLibrary_ErrorCode OH_MediaAsset_GetDateAdded(OH_MediaAsset* mediaAsset, uint32_t* dateAdded)
```
**描述**
获取资产添加日期。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 
| dateAdded | 资产添加日期。该值是添加文件时间距1970年1月1日的秒数值。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。
 
- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 


### OH_MediaAsset_GetDateAddedMs()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetDateAddedMs(OH_MediaAsset* mediaAsset, uint32_t* dateAddedMs)
```
**描述**
获取资产的添加时间（毫秒）。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 
| dateAddedMs | 资产的添加时间（毫秒）。 该值是添加文件时间距1970年1月1日的毫秒数值。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。


### OH_MediaAsset_GetDateModified()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetDateModified(OH_MediaAsset* mediaAsset, uint32_t* dateModified)
```
**描述**
获取资产的修改日期。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 
| dateModified | 资产的修改日期。该值是修改文件时间距1970年1月1日的秒数值，修改文件名不会改变此值，当文件内容发生修改时才会更新。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。


### OH_MediaAsset_GetDateModifiedMs()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetDateModifiedMs(OH_MediaAsset* mediaAsset, uint32_t* dateModifiedMs)
```
**描述**
获取资产的修改时间（毫秒）。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 
| dateModifiedMs | 资产的修改时间（毫秒）。该值是修改文件时间距1970年1月1日的毫秒数值，修改文件名不会改变此值，当文件内容发生修改时才会更新。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 


### OH_MediaAsset_GetDateTaken()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetDateTaken(OH_MediaAsset* mediaAsset, uint32_t* dateTaken)
```
**描述**
获取资产的拍摄日期。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 
| dateTaken | 资产的拍摄日期。该值是文件拍照时间距1970年1月1日的秒数值。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 


### OH_MediaAsset_GetDisplayName()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetDisplayName(OH_MediaAsset* mediaAsset, const char** displayName)
```
**描述**
获取媒体资源的显示名称。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 
| displayName | 媒体资源的显示名称。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 


### OH_MediaAsset_GetDuration()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetDuration(OH_MediaAsset* mediaAsset, uint32_t* duration)
```
**描述**
获取媒体资源的持续时间（毫秒）。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 
| duration | 媒体资源的持续时间（毫秒）。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 


### OH_MediaAsset_GetHeight()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetHeight(OH_MediaAsset* mediaAsset, uint32_t* height)
```
**描述**
获取媒体资源的图像高度（像素）。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 
| height | 媒体资源的图像高度（像素）。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。  

### OH_MediaAsset_GetMediaSubType()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetMediaSubType(OH_MediaAsset* mediaAsset, MediaLibrary_MediaSubType* mediaSubType)
```
**描述**
获取媒体资源子类型。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 
| mediaSubType | 媒体资源子类型。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。  

### OH_MediaAsset_GetMediaType()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetMediaType(OH_MediaAsset* mediaAsset, MediaLibrary_MediaType* mediaType)
```
**描述**
获取媒体资源类型。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 
| mediaType | 媒体资源类型。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 


### OH_MediaAsset_GetOrientation()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetOrientation(OH_MediaAsset* mediaAsset, uint32_t* orientation)
```
**描述**
获取图像的旋转角度，单位为度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 
| orientation | 图像的旋转角度，单位为度。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 


### OH_MediaAsset_GetSize()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetSize(OH_MediaAsset* mediaAsset, uint32_t* size)
```
**描述**
获取媒体资产的文件大小。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 
| size | 媒体资源的文件大小（以字节为单位）。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 


### OH_MediaAsset_GetTitle()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetTitle(OH_MediaAsset* mediaAsset, const char** title)
```
**描述**
获取媒体资产的标题。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 
| title | 媒体资产的标题。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。


### OH_MediaAsset_GetUri()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetUri(OH_MediaAsset* mediaAsset, const char** uri)
```
**描述**
获取媒体资产的uri。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 
| uri | 媒体资产的uri。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 


### OH_MediaAsset_GetWidth()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetWidth(OH_MediaAsset* mediaAsset, uint32_t* width)
```
**描述**
获取媒体资源的图像宽度（像素）。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 
| width | 媒体资源的图像宽度（像素）。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 


### OH_MediaAsset_IsFavorite()

```
MediaLibrary_ErrorCode OH_MediaAsset_IsFavorite(OH_MediaAsset* mediaAsset, uint32_t* favorite)
```
**描述**
获取资产的收藏状态。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 
| favorite | 资产的收藏状态。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 


### OH_MediaAsset_Release()

```
MediaLibrary_ErrorCode OH_MediaAsset_Release(OH_MediaAsset* mediaAsset)
```
**描述**
释放媒体资产

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。


### OH_MediaAssetChangeRequest_AddResourceWithBuffer()

```
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_AddResourceWithBuffer(OH_MediaAssetChangeRequest* changeRequest, MediaLibrary_ResourceType resourceType, uint8_t* buffer, uint32_t length)
```
**描述**
通过ArrayBuffer数据添加资源。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| changeRequest | [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest)实例。  | 
| resourceType | 要添加的资源的[MediaLibrary_ResourceType](#medialibrary_resourcetype)。  | 
| buffer | 要添加的数据缓冲区。  | 
| length | 数据缓冲区的长度。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。


### OH_MediaAssetChangeRequest_AddResourceWithUri()

```
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_AddResourceWithUri(OH_MediaAssetChangeRequest* changeRequest, MediaLibrary_ResourceType resourceType, char* fileUri)
```
**描述**
通过文件uri添加资源。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| changeRequest | [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest)实例。  | 
| resourceType | 要添加的资源的[MediaLibrary_ResourceType](#medialibrary_resourcetype)。  | 
| fileUri | 文件uri。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_NO_SUCH_FILE：文件不存在。
  
- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。

- MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED：不支持该操作。 


### OH_MediaAssetChangeRequest_Create()

```
OH_MediaAssetChangeRequest* OH_MediaAssetChangeRequest_Create(OH_MediaAsset* mediaAsset)
```
**描述**
创建[OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest)实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mediaAsset | [OH_MediaAsset](#oh_mediaasset)实例。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。
  
- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 


### OH_MediaAssetChangeRequest_DiscardCameraPhoto()

```
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_DiscardCameraPhoto(OH_MediaAssetChangeRequest* changeRequest)
```
**描述**
丢弃相机拍摄的照片资源。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| changeRequest | [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest)实例。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。
 
- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。

- MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED：不支持该操作。 


### OH_MediaAssetChangeRequest_GetWriteCacheHandler()

```
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_GetWriteCacheHandler(OH_MediaAssetChangeRequest* changeRequest, int32_t* fd)
```
**描述**
获取临时文件写句柄。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| changeRequest | [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest)实例。  | 
| fd | 临时文件写句柄。  | 

**需要权限：**

ohos.permission.WRITE_IMAGEVIDEO

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。
 
- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。

- MEDIA_LIBRARY_PERMISSION_DENIED：没有权限。

- MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED：不支持该操作。 


### OH_MediaAssetChangeRequest_Release()

```
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_Release(OH_MediaAssetChangeRequest* changeRequest)
```
**描述**
释放[OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest)实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| changeRequest | [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest)实例。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。


### OH_MediaAssetChangeRequest_SaveCameraPhoto()

```
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_SaveCameraPhoto(OH_MediaAssetChangeRequest* changeRequest, MediaLibrary_ImageFileType imageFileType)
```
**描述**
保存相机拍摄的照片资源。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| changeRequest | [OH_MediaAssetChangeRequest](#oh_mediaassetchangerequest)实例。  | 
| imageFileType | 要保存的照片的[MediaLibrary_ImageFileType](#medialibrary_imagefiletype)。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。
 
- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。

- MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED：不支持该操作。 


### OH_MediaAssetManager_CancelRequest()

```
bool OH_MediaAssetManager_CancelRequest(OH_MediaAssetManager* manager, const MediaLibrary_RequestId requestId)
```
**描述**
通过请求Id取消请求。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| manager | 指向OH_MediaAssetManager实例的指针。  | 
| requestId | 待取消的请求Id。  | 

**需要权限：**

ohos.permission.READ_IMAGEVIDEO

**返回：**

如果请求成功取消，则返回true；否则返回false。


### OH_MediaAssetManager_Create()

```
OH_MediaAssetManager* OH_MediaAssetManager_Create(void)
```
**描述**
创建一个媒体资产管理器。

**起始版本：** 12

**返回：**

返回一个指向OH_MediaAssetManager实例的指针。


### OH_MediaAssetManager_Release()

```
MediaLibrary_ErrorCode OH_MediaAssetManager_Release(OH_MediaAssetManager* manager)
```
**描述**
释放[OH_MediaAssetManager](#oh_mediaassetmanager)实例。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| manager | 要释放的[OH_MediaAssetManager](#oh_mediaassetmanager)实例。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。


### OH_MediaAssetManager_RequestImage()

```
MediaLibrary_ErrorCode OH_MediaAssetManager_RequestImage(OH_MediaAssetManager* manager, OH_MediaAsset* mediaAsset, MediaLibrary_RequestOptions requestOptions, MediaLibrary_RequestId* requestId, OH_MediaLibrary_OnImageDataPrepared callback)
```
**描述**
根据不同的策略模式请求图像资源。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| manager | [OH_MediaAssetManager](#oh_mediaassetmanager)实例指针。  | 
| mediaAsset | 要请求的媒体文件对象的[OH_MediaAsset](#oh_mediaasset)实例。  | 
| requestOptions | 用于图像请求策略模式的[MediaLibrary_RequestOptions](_media_library___request_options.md)。  | 
| requestId | 请求的[MediaLibrary_RequestId](_media_library___request_id.md)，出参。  | 
| callback | 当请求的图像源准备就绪时调用[OH_MediaLibrary_OnImageDataPrepared](#oh_medialibrary_onimagedataprepared)。  | 

**需要权限：**

ohos.permission.READ_IMAGEVIDEO

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。
- MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED：不支持该操作。

- MEDIA_LIBRARY_PERMISSION_DENIED：没有权限。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 


### OH_MediaAssetManager_RequestImageForPath()

```
MediaLibrary_RequestId OH_MediaAssetManager_RequestImageForPath(OH_MediaAssetManager* manager, const char* uri, MediaLibrary_RequestOptions requestOptions, const char* destPath, OH_MediaLibrary_OnDataPrepared callback)
```
**描述**
请求具有目标路径的图像资源。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| manager | 指向OH_MediaAssetManager实例的指针。  | 
| uri | 请求的图像资源的uri。  | 
| requestOptions | 请求策略模式配置项。  | 
| destPath | 请求资源的目标地址。  | 
| callback | 媒体资源处理器，当所请求的媒体资源准备完成时会触发回调。  | 

**需要权限：**

ohos.permission.READ_IMAGEVIDEO

**返回：**

返回请求Id。


### OH_MediaAssetManager_RequestMovingPhoto()

```
MediaLibrary_ErrorCode OH_MediaAssetManager_RequestMovingPhoto(OH_MediaAssetManager* manager, OH_MediaAsset* mediaAsset, MediaLibrary_RequestOptions requestOptions, MediaLibrary_RequestId* requestId, OH_MediaLibrary_OnMovingPhotoDataPrepared callback)
```
**描述**
根据不同的策略模式请求动态照片资源。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| manager | [OH_MediaAssetManager](#oh_mediaassetmanager)实例指针。  | 
| mediaAsset | 要请求的媒体文件对象的[OH_MediaAsset](#oh_mediaasset)实例。  | 
| requestOptions | 用于图像请求策略模式的[MediaLibrary_RequestOptions](_media_library___request_options.md)。  | 
| requestId | 请求的[MediaLibrary_RequestId](_media_library___request_id.md)，出参。  | 
| callback | 当请求的动态照片准备就绪时调用[OH_MediaLibrary_OnMovingPhotoDataPrepared](#oh_medialibrary_onmovingphotodataprepared)。  | 

**需要权限：**

ohos.permission.READ_IMAGEVIDEO

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。
- MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED：不支持该操作。

- MEDIA_LIBRARY_PERMISSION_DENIED：没有权限。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 


### OH_MediaAssetManager_RequestVideoForPath()

```
MediaLibrary_RequestId OH_MediaAssetManager_RequestVideoForPath(OH_MediaAssetManager* manager, const char* uri, MediaLibrary_RequestOptions requestOptions, const char* destPath, OH_MediaLibrary_OnDataPrepared callback)
```
**描述**
请求具有目标路径的视频资源。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| manager | 指向OH_MediaAssetManager实例的指针。  | 
| uri | 请求的视频资源的uri。  | 
| requestOptions | 请求策略模式配置项。  | 
| destPath | 请求资源的目标地址。  | 
| callback | 媒体资源处理器，当所请求的媒体资源准备完成时会触发回调。  | 

**需要权限：**

ohos.permission.READ_IMAGEVIDEO

**返回：**

返回请求Id。


### OH_MovingPhoto_GetUri()

```
MediaLibrary_ErrorCode OH_MovingPhoto_GetUri(OH_MovingPhoto* movingPhoto, const char** uri)
```
**描述**
获取动态照片的uri。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| movingPhoto | [OH_MovingPhoto](#oh_movingphoto)实例。  | 
| uri | 动态照片的uri。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 


### OH_MovingPhoto_Release()

```
MediaLibrary_ErrorCode OH_MovingPhoto_Release(OH_MovingPhoto* movingPhoto)
```
**描述**
Release [OH_MovingPhoto](#oh_movingphoto)实例。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| movingPhoto | 要释放的[OH_MovingPhoto](#oh_movingphoto)实例。  | 

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。


### OH_MovingPhoto_RequestContentWithBuffer()

```
MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithBuffer(OH_MovingPhoto* movingPhoto, MediaLibrary_ResourceType resourceType, const uint8_t** buffer, uint32_t* size)
```
**描述**
请求指定资源类型的动态照片内容，以ArrayBuffer的形式返回。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| movingPhoto | [OH_MovingPhoto](#oh_movingphoto)实例。  | 
| resourceType | 指定的资源类型[MediaLibrary_ResourceType](#medialibrary_resourcetype)。  | 
| buffer | 保存目标文件数据的缓冲区。  | 
| size | 缓冲区的大小。  | 

**需要权限：**

ohos.permission.READ_IMAGEVIDEO

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_PERMISSION_DENIED：没有权限。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。


### OH_MovingPhoto_RequestContentWithUri()

```
MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithUri(OH_MovingPhoto* movingPhoto, MediaLibrary_ResourceType resourceType, char* uri)
```
**描述**
请求指定资源类型的动态照片内容，并写入参数指定的uri中。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| movingPhoto | [OH_MovingPhoto](#oh_movingphoto)实例。  | 
| resourceType | 指定的资源类型[MediaLibrary_ResourceType](#medialibrary_resourcetype)。  | 
| uri | 保存数据的目标文件uri。  | 

**需要权限：**

ohos.permission.READ_IMAGEVIDEO

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_PERMISSION_DENIED：没有权限。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。


### OH_MovingPhoto_RequestContentWithUris()

```
MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithUris(OH_MovingPhoto* movingPhoto, char* imageUri, char* videoUri)
```
**描述**
同时请求动态照片的图片内容和视频内容，并写入参数指定的对应的uri中。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| movingPhoto | [OH_MovingPhoto](#oh_movingphoto)实例。  | 
| imageUri | 用于保存图像数据的目标文件uri。  | 
| videoUri | 用于保存视频数据的目标文件uri。  | 

**需要权限：**

ohos.permission.READ_IMAGEVIDEO

**返回：**

错误码[MediaLibrary_ErrorCode](#medialibrary_errorcode-1)：

- MEDIA_LIBRARY_OK：方法调用成功。

- MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。
  可能的原因：
  1. 未指定强制参数。
  2. 参数类型不正确。
  3. 参数验证失败。

- MEDIA_LIBRARY_PERMISSION_DENIED：没有权限。

- MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。
