# media_asset_manager_capi.h

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## 概述

定义媒体资产管理器的接口。使用由媒体资产管理器提供的C API来请求媒体库资源。

**库：** libmedia_asset_manager.so

**引用文件：** <multimedia/media_library/media_asset_manager_capi.h>

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**起始版本：** 12

**相关模块：** [MediaAssetManager](capi-mediaassetmanager.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_MediaAssetManager* OH_MediaAssetManager_Create(void)](#oh_mediaassetmanager_create) | 创建一个媒体资产管理器。 |
| [MediaLibrary_RequestId OH_MediaAssetManager_RequestImageForPath(OH_MediaAssetManager* manager, const char* uri, MediaLibrary_RequestOptions requestOptions, const char* destPath, OH_MediaLibrary_OnDataPrepared callback)](#oh_mediaassetmanager_requestimageforpath) | 请求具有目标路径的图像资源。 |
| [MediaLibrary_RequestId OH_MediaAssetManager_RequestVideoForPath(OH_MediaAssetManager* manager, const char* uri, MediaLibrary_RequestOptions requestOptions, const char* destPath, OH_MediaLibrary_OnDataPrepared callback)](#oh_mediaassetmanager_requestvideoforpath) | 请求具有目标路径的视频资源。 |
| [bool OH_MediaAssetManager_CancelRequest(OH_MediaAssetManager* manager, const MediaLibrary_RequestId requestId)](#oh_mediaassetmanager_cancelrequest) | 通过请求Id取消请求。 |
| [MediaLibrary_ErrorCode OH_MediaAssetManager_RequestMovingPhoto(OH_MediaAssetManager* manager, OH_MediaAsset* mediaAsset, MediaLibrary_RequestOptions requestOptions, MediaLibrary_RequestId* requestId, OH_MediaLibrary_OnMovingPhotoDataPrepared callback)](#oh_mediaassetmanager_requestmovingphoto) | 根据不同的策略模式请求动态照片资源。 |
| [MediaLibrary_ErrorCode OH_MediaAssetManager_RequestImage(OH_MediaAssetManager* manager, OH_MediaAsset* mediaAsset, MediaLibrary_RequestOptions requestOptions, MediaLibrary_RequestId* requestId, OH_MediaLibrary_OnImageDataPrepared callback)](#oh_mediaassetmanager_requestimage) | 根据不同的策略模式请求图像资源。 |
| [MediaLibrary_ErrorCode OH_MediaAssetManager_Release(OH_MediaAssetManager* manager)](#oh_mediaassetmanager_release) | 释放[OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)实例。 |

## 函数说明

### OH_MediaAssetManager_Create()

```
OH_MediaAssetManager* OH_MediaAssetManager_Create(void)
```

**描述**

创建一个媒体资产管理器。

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)* | 返回一个指向OH_MediaAssetManager实例的指针。 |

### OH_MediaAssetManager_RequestImageForPath()

```
MediaLibrary_RequestId OH_MediaAssetManager_RequestImageForPath(OH_MediaAssetManager* manager, const char* uri,MediaLibrary_RequestOptions requestOptions, const char* destPath, OH_MediaLibrary_OnDataPrepared callback)
```

**描述**

请求具有目标路径的图像资源。

**需要权限：** ohos.permission.READ_IMAGEVIDEO

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)* manager | 指向OH_MediaAssetManager实例的指针。 |
| const char* uri | 请求的图像资源的uri。 |
| [MediaLibrary_RequestOptions](capi-mediaassetmanager-medialibrary-requestoptions.md) requestOptions | 请求策略模式配置项。 |
| const char* destPath | 请求资源的目标地址。 |
| [OH_MediaLibrary_OnDataPrepared](capi-media-asset-base-capi-h.md#oh_medialibrary_ondataprepared) callback | 媒体资源处理器，当所请求的媒体资源准备完成时会触发回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md) | 返回请求Id。 |

### OH_MediaAssetManager_RequestVideoForPath()

```
MediaLibrary_RequestId OH_MediaAssetManager_RequestVideoForPath(OH_MediaAssetManager* manager, const char* uri,MediaLibrary_RequestOptions requestOptions, const char* destPath, OH_MediaLibrary_OnDataPrepared callback)
```

**描述**

请求具有目标路径的视频资源。

**需要权限：** ohos.permission.READ_IMAGEVIDEO

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)* manager | 指向OH_MediaAssetManager实例的指针。 |
| const char* uri | 请求的视频资源的uri。 |
| [MediaLibrary_RequestOptions](capi-mediaassetmanager-medialibrary-requestoptions.md) requestOptions | 请求策略模式配置项。 |
| const char* destPath | 请求资源的目标地址。 |
| [OH_MediaLibrary_OnDataPrepared](capi-media-asset-base-capi-h.md#oh_medialibrary_ondataprepared) callback | 媒体资源处理器，当所请求的媒体资源准备完成时会触发回调。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md) | 返回请求Id。 |

### OH_MediaAssetManager_CancelRequest()

```
bool OH_MediaAssetManager_CancelRequest(OH_MediaAssetManager* manager, const MediaLibrary_RequestId requestId)
```

**描述**

通过请求Id取消请求。

**需要权限：** ohos.permission.READ_IMAGEVIDEO

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)* manager | 指向OH_MediaAssetManager实例的指针。 |
| const [MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md) requestId | 待取消的请求Id。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果请求成功取消，则返回true；否则返回false。 |

### OH_MediaAssetManager_RequestMovingPhoto()

```
MediaLibrary_ErrorCode OH_MediaAssetManager_RequestMovingPhoto(OH_MediaAssetManager* manager,OH_MediaAsset* mediaAsset, MediaLibrary_RequestOptions requestOptions, MediaLibrary_RequestId* requestId,OH_MediaLibrary_OnMovingPhotoDataPrepared callback)
```

**描述**

根据不同的策略模式请求动态照片资源。

**需要权限：** ohos.permission.READ_IMAGEVIDEO

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)* manager | [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)实例指针。 |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | 要请求的媒体文件对象的[OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)实例。 |
| [MediaLibrary_RequestOptions](capi-mediaassetmanager-medialibrary-requestoptions.md) requestOptions | 用于图像请求策略模式的[MediaLibrary_RequestOptions](capi-mediaassetmanager-medialibrary-requestoptions.md)。 |
| [MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md)* requestId | 请求的[MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md)，出参。 |
| [OH_MediaLibrary_OnMovingPhotoDataPrepared](capi-media-asset-base-capi-h.md#oh_medialibrary_onmovingphotodataprepared) callback | 当请求的动态照片准备就绪时调用[OH_MediaLibrary_OnMovingPhotoDataPrepared](capi-media-asset-base-capi-h.md#oh_medialibrary_onmovingphotodataprepared)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | MEDIA_LIBRARY_OK：方法调用成功。<br>      MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。可能的原因：<br>                                      1. 未指定强制参数。<br>                                      2. 参数类型不正确。<br>                                      3. 参数验证失败。<br>      MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED：不支持该操作。<br>      MEDIA_LIBRARY_PERMISSION_DENIED：没有权限。<br>      MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 |

### OH_MediaAssetManager_RequestImage()

```
MediaLibrary_ErrorCode OH_MediaAssetManager_RequestImage(OH_MediaAssetManager* manager, OH_MediaAsset* mediaAsset,MediaLibrary_RequestOptions requestOptions, MediaLibrary_RequestId* requestId,OH_MediaLibrary_OnImageDataPrepared callback)
```

**描述**

根据不同的策略模式请求图像资源。

**需要权限：** ohos.permission.READ_IMAGEVIDEO

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)* manager | [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)实例指针。 |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | 要请求的媒体文件对象的[OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)实例。 |
| [MediaLibrary_RequestOptions](capi-mediaassetmanager-medialibrary-requestoptions.md) requestOptions | 用于图像请求策略模式的[MediaLibrary_RequestOptions](capi-mediaassetmanager-medialibrary-requestoptions.md)。 |
| [MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md)* requestId | 请求的[MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md)，出参。 |
| [OH_MediaLibrary_OnImageDataPrepared](capi-media-asset-base-capi-h.md#oh_medialibrary_onimagedataprepared) callback | 当请求的图像源准备就绪时调用[OH_MediaLibrary_OnImageDataPrepared](capi-media-asset-base-capi-h.md#oh_medialibrary_onimagedataprepared)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | MEDIA_LIBRARY_OK：方法调用成功。<br>      MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。可能的原因：<br>                                      1. 未指定强制参数。<br>                                      2. 参数类型不正确。<br>                                      3. 参数验证失败。<br>      MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED：不支持该操作。<br>      MEDIA_LIBRARY_PERMISSION_DENIED：没有权限。<br>      MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 |

### OH_MediaAssetManager_Release()

```
MediaLibrary_ErrorCode OH_MediaAssetManager_Release(OH_MediaAssetManager* manager)
```

**描述**

释放[OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)实例。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)* manager | 要释放的[OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | MEDIA_LIBRARY_OK：方法调用成功。<br>      MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。可能的原因：<br>                                      1. 未指定强制参数。<br>                                      2. 参数类型不正确。<br>                                      3. 参数验证失败。 |


