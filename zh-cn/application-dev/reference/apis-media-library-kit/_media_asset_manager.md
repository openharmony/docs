# MediaAssetManager


## 概述

提供媒体库资源请求能力的API。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [media_asset_base_capi.h](media__asset__base__capi_8h.md) | 定义了媒体资产管理器的结构和枚举。 | 
| [media_asset_manager_capi.h](media__asset__manager__capi_8h.md) | 定义媒体资产管理器的接口。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [MediaLibrary_RequestId](_media_library___request_id.md) | 定义请求Id。 | 
| struct  [MediaLibrary_RequestOptions](_media_library___request_options.md) | 请求策略模式配置项。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_MediaAssetManager](#oh_mediaassetmanager) [OH_MediaAssetManager](#oh_mediaassetmanager) | 定义媒体资产管理器。 | 
| typedef struct [MediaLibrary_RequestId](_media_library___request_id.md) [MediaLibrary_RequestId](#medialibrary_requestid) | 定义请求Id。 | 
| typedef enum [MediaLibrary_DeliveryMode](#medialibrary_deliverymode-1) [MediaLibrary_DeliveryMode](#medialibrary_deliverymode) | 请求资源分发模式。 | 
| typedef void(\* [OH_MediaLibrary_OnDataPrepared](#oh_medialibrary_ondataprepared)) (int32_t result, [MediaLibrary_RequestId](_media_library___request_id.md) requestId) | 当所请求的媒体资源准备完成时会触发回调。 | 
| typedef struct [MediaLibrary_RequestOptions](_media_library___request_options.md) [MediaLibrary_RequestOptions](#medialibrary_requestoptions) | 请求策略模式配置项。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [MediaLibrary_DeliveryMode](#medialibrary_deliverymode-1) {<br/>MEDIA_LIBRARY_FAST_MODE = 0,<br/>MEDIA_LIBRARY_HIGH_QUALITY_MODE = 1,<br/>MEDIA_LIBRARY_BALANCED_MODE = 2<br/>} | 请求资源分发模式。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_MediaAssetManager](#oh_mediaassetmanager) \* [OH_MediaAssetManager_Create](#oh_mediaassetmanager_create) (void) | 创建一个媒体资产管理器。 | 
| [MediaLibrary_RequestId](_media_library___request_id.md) [OH_MediaAssetManager_RequestImageForPath](#oh_mediaassetmanager_requestimageforpath) ([OH_MediaAssetManager](#oh_mediaassetmanager) \*manager, const char \*uri, [MediaLibrary_RequestOptions](_media_library___request_options.md) requestOptions, const char \*destPath, [OH_MediaLibrary_OnDataPrepared](#oh_medialibrary_ondataprepared) callback) | 请求具有目标路径的图像资源。 | 
| [MediaLibrary_RequestId](_media_library___request_id.md) [OH_MediaAssetManager_RequestVideoForPath](#oh_mediaassetmanager_requestvideoforpath) ([OH_MediaAssetManager](#oh_mediaassetmanager) \*manager, const char \*uri, [MediaLibrary_RequestOptions](_media_library___request_options.md) requestOptions, const char \*destPath, [OH_MediaLibrary_OnDataPrepared](#oh_medialibrary_ondataprepared) callback) | 请求具有目标路径的视频资源。 | 
| bool [OH_MediaAssetManager_CancelRequest](#oh_mediaassetmanager_cancelrequest) ([OH_MediaAssetManager](#oh_mediaassetmanager) \*manager, const [MediaLibrary_RequestId](_media_library___request_id.md) requestId) | 通过请求Id取消请求。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| char [MediaLibrary_RequestId::requestId](#requestid) [UUID_STR_MAX_LENGTH] | 请求Id。 | 
| [MediaLibrary_DeliveryMode](#medialibrary_deliverymode-1) [MediaLibrary_RequestOptions::deliveryMode](#deliverymode) | 分发模式。 | 


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
typedef void(* OH_MediaLibrary_OnDataPrepared) (int32_t result, MediaLibrary_RequestId requestId)
```

**描述**

当所请求的媒体资源准备完成时会触发回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| result | 请求资源处理的结果。 | 
| requestId | 请求Id。 | 


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
| MEDIA_LIBRARY_FAST_MODE | 快速分发。 | 
| MEDIA_LIBRARY_HIGH_QUALITY_MODE | 高质量分发。 | 
| MEDIA_LIBRARY_BALANCED_MODE | 均衡分发。 | 


## 函数说明


### OH_MediaAssetManager_CancelRequest()

```
bool OH_MediaAssetManager_CancelRequest (OH_MediaAssetManager *manager, const MediaLibrary_RequestId requestId)
```

**描述**

通过请求Id取消请求。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| manager | 指向OH_MediaAssetManager实例的指针。 | 
| requestId | 待取消的请求Id。 | 

**返回：**

如果请求成功取消，则返回true；否则返回false。


### OH_MediaAssetManager_Create()

```
OH_MediaAssetManager* OH_MediaAssetManager_Create (void )
```

**描述**

创建一个媒体资产管理器。

**起始版本：** 12

**返回：**

返回一个指向OH_MediaAssetManager实例的指针。


### OH_MediaAssetManager_RequestImageForPath()

```
MediaLibrary_RequestId OH_MediaAssetManager_RequestImageForPath (OH_MediaAssetManager *manager, const char *uri, MediaLibrary_RequestOptions requestOptions, const char *destPath, OH_MediaLibrary_OnDataPrepared callback)
```

**描述**

请求具有目标路径的图像资源。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| manager | 指向OH_MediaAssetManager实例的指针。 | 
| uri | 请求的图像资源的uri。 | 
| requestOptions | 请求策略模式配置项。 | 
| destPath | 请求资源的目标地址。 | 
| callback | 媒体资源处理器，当所请求的媒体资源准备完成时会触发回调。 | 

**返回：**

返回请求Id。


### OH_MediaAssetManager_RequestVideoForPath()

```
MediaLibrary_RequestId OH_MediaAssetManager_RequestVideoForPath (OH_MediaAssetManager *manager, const char *uri, MediaLibrary_RequestOptions requestOptions, const char *destPath, OH_MediaLibrary_OnDataPrepared callback)
```

**描述**

请求具有目标路径的视频资源。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| manager | 指向OH_MediaAssetManager实例的指针。 | 
| uri | 请求的视频资源的uri。 | 
| requestOptions | 请求策略模式配置项。 | 
| destPath | 请求资源的目标地址。 | 
| callback | 媒体资源处理器，当所请求的媒体资源准备完成时会触发回调。 | 

**返回：**

返回请求Id。


## 变量说明


### deliveryMode

```
MediaLibrary_DeliveryMode MediaLibrary_RequestOptions::deliveryMode
```

**描述**

分发模式。


### requestId

```
char MediaLibrary_RequestId::requestId[UUID_STR_MAX_LENGTH]
```

**描述**

请求Id。
