# moving_photo_capi.h

## 概述

定义与动态照片相关的API。提供获取动态照片信息的功能。

**库：** libmedia_asset_manager.so

**引用文件：** <multimedia/media_library/moving_photo_capi.h>

**系统能力：** SystemCapability.FileManagement.PhotoAccessHelper.Core

**起始版本：** 13

**相关模块：** [MediaAssetManager](capi-mediaassetmanager.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [MediaLibrary_ErrorCode OH_MovingPhoto_GetUri(OH_MovingPhoto* movingPhoto, const char** uri)](#oh_movingphoto_geturi) | 获取动态照片的uri。 |
| [MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithUris(OH_MovingPhoto* movingPhoto, char* imageUri,char* videoUri)](#oh_movingphoto_requestcontentwithuris) | 同时请求动态照片的图片内容和视频内容，并写入参数指定的对应的uri中。 |
| [MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithUri(OH_MovingPhoto* movingPhoto,MediaLibrary_ResourceType resourceType, char* uri)](#oh_movingphoto_requestcontentwithuri) | 请求指定资源类型的动态照片内容，并写入参数指定的uri中。 |
| [MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithBuffer(OH_MovingPhoto* movingPhoto,MediaLibrary_ResourceType resourceType, const uint8_t** buffer, uint32_t* size)](#oh_movingphoto_requestcontentwithbuffer) | 请求指定资源类型的动态照片内容，以ArrayBuffer的形式返回。 |
| [MediaLibrary_ErrorCode OH_MovingPhoto_Release(OH_MovingPhoto* movingPhoto)](#oh_movingphoto_release) | Release [OH_MovingPhoto](capi-oh-movingphoto.md)实例。 |

## 函数说明

### OH_MovingPhoto_GetUri()

```
MediaLibrary_ErrorCode OH_MovingPhoto_GetUri(OH_MovingPhoto* movingPhoto, const char** uri)
```

**描述**

获取动态照片的uri。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_MovingPhoto](capi-oh-movingphoto.md)* movingPhoto | [OH_MovingPhoto](capi-oh-movingphoto.md)实例。 |
| const char** uri | 动态照片的uri。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | MEDIA_LIBRARY_OK：方法调用成功。<br>      MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。可能的原因：<br>                                      1. 未指定强制参数。<br>                                      2. 参数类型不正确。<br>                                      3. 参数验证失败。<br>      MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 |

### OH_MovingPhoto_RequestContentWithUris()

```
MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithUris(OH_MovingPhoto* movingPhoto, char* imageUri,char* videoUri)
```

**描述**

同时请求动态照片的图片内容和视频内容，并写入参数指定的对应的uri中。

**需要权限：** ohos.permission.READ_IMAGEVIDEO

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_MovingPhoto](capi-oh-movingphoto.md)* movingPhoto | [OH_MovingPhoto](capi-oh-movingphoto.md)实例。 |
| char* imageUri | 用于保存图像数据的目标文件uri。 |
| char* videoUri | 用于保存视频数据的目标文件uri。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | MEDIA_LIBRARY_OK：方法调用成功。<br>      MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。可能的原因：<br>                                      1. 未指定强制参数。<br>                                      2. 参数类型不正确。<br>                                      3. 参数验证失败。<br>      MEDIA_LIBRARY_PERMISSION_DENIED：没有权限。<br>      MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 |

### OH_MovingPhoto_RequestContentWithUri()

```
MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithUri(OH_MovingPhoto* movingPhoto,MediaLibrary_ResourceType resourceType, char* uri)
```

**描述**

请求指定资源类型的动态照片内容，并写入参数指定的uri中。

**需要权限：** ohos.permission.READ_IMAGEVIDEO

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_MovingPhoto](capi-oh-movingphoto.md)* movingPhoto | [OH_MovingPhoto](capi-oh-movingphoto.md)实例。 |
| [MediaLibrary_ResourceType](capi-media-asset-base-capi-h.md#medialibrary_resourcetype) resourceType | 指定的资源类型[MediaLibrary_ResourceType](capi-media-asset-base-capi-h.md#medialibrary_resourcetype)。 |
| char* uri | 保存数据的目标文件uri。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | MEDIA_LIBRARY_OK：方法调用成功。<br>      MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。可能的原因：<br>                                      1. 未指定强制参数。<br>                                      2. 参数类型不正确。<br>                                      3. 参数验证失败。<br>      MEDIA_LIBRARY_PERMISSION_DENIED：没有权限。<br>      MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 |

### OH_MovingPhoto_RequestContentWithBuffer()

```
MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithBuffer(OH_MovingPhoto* movingPhoto,MediaLibrary_ResourceType resourceType, const uint8_t** buffer, uint32_t* size)
```

**描述**

请求指定资源类型的动态照片内容，以ArrayBuffer的形式返回。

**需要权限：** ohos.permission.READ_IMAGEVIDEO

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_MovingPhoto](capi-oh-movingphoto.md)* movingPhoto | [OH_MovingPhoto](capi-oh-movingphoto.md)实例。 |
| [MediaLibrary_ResourceType](capi-media-asset-base-capi-h.md#medialibrary_resourcetype) resourceType | 指定的资源类型[MediaLibrary_ResourceType](capi-media-asset-base-capi-h.md#medialibrary_resourcetype)。 |
| const uint8_t** buffer | 保存目标文件数据的缓冲区。 |
| uint32_t* size | 缓冲区的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | MEDIA_LIBRARY_OK：方法调用成功。<br>      MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。可能的原因：<br>                                      1. 未指定强制参数。<br>                                      2. 参数类型不正确。<br>                                      3. 参数验证失败。<br>      MEDIA_LIBRARY_PERMISSION_DENIED：没有权限。<br>      MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR：内部系统错误。 |

### OH_MovingPhoto_Release()

```
MediaLibrary_ErrorCode OH_MovingPhoto_Release(OH_MovingPhoto* movingPhoto)
```

**描述**

Release [OH_MovingPhoto](capi-oh-movingphoto.md)实例。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_MovingPhoto](capi-oh-movingphoto.md)* movingPhoto | 要释放的[OH_MovingPhoto](capi-oh-movingphoto.md)实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | MEDIA_LIBRARY_OK：方法调用成功。<br>      MEDIA_LIBRARY_PARAMETER_ERROR：参数错误。可能的原因：<br>                                      1. 未指定强制参数。<br>                                      2. 参数类型不正确。<br>                                      3. 参数验证失败。 |


