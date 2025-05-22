# media_asset_base_capi.h

## 概述

定义了媒体资产管理器的结构和枚举。OH_MediaAssetManager结构体：该结构体提供了从媒体库请求资源的能力。 <br>MediaLibrary_RequestId结构体：在请求媒体库资源时返回的类型。请求Id用于取消请求。 <br>MediaLibrary_DeliveryMode枚举：此枚举定义了请求资源的分发模式。 <br>OH_MediaLibrary_OnDataPrepared函数指针：当所请求的媒体资源准备完成时会触发回调。 <br>MediaLibrary_RequestOptions结构体：此结构体为媒体资源请求策略模式配置项。 <br>

**库：** libmedia_asset_manager.so

**起始版本：** 12

**相关模块：** [MediaAssetManager](capi-mediaassetmanager.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [MediaLibrary_RequestId](capi-medialibrary-requestid.md) | MediaLibrary_RequestId | 定义请求Id。当请求媒体库资源时，会返回此类型。请求Id用于取消请求。如果请求失败，值将全为零，如 "00000000-0000-0000-0000-000000000000"。 |
| [OH_MediaAssetManager](capi-oh-mediaassetmanager.md) | OH_MediaAssetManager | 定义媒体资产管理器。此结构提供了请求媒体库资源的能力。如果创建失败，则返回空指针。 |
| [OH_MediaAssetChangeRequest](capi-oh-mediaassetchangerequest.md) | OH_MediaAssetChangeRequest | 定义媒体资产更改请求。此结构体提供了处理媒体资产更改请求的能力。 |
| [OH_MovingPhoto](capi-oh-movingphoto.md) | OH_MovingPhoto | 定义动态照片。此结构体提供了获取关于动态照片的信息的能力。 |
| [OH_MediaAsset](capi-oh-mediaasset.md) | OH_MediaAsset | 定义媒体资产。此结构体提供了封装文件资源属性的能力。 |
| [MediaLibrary_RequestOptions](capi-medialibrary-requestoptions.md) | MediaLibrary_RequestOptions | 请求策略模式配置项。此结构体为媒体资源请求策略模式配置项。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) | MediaLibrary_ErrorCode | 媒体库错误代码的枚举。 |
| [MediaLibrary_DeliveryMode](#medialibrary_deliverymode) | MediaLibrary_DeliveryMode | 请求资源分发模式。此枚举定义了请求资源的分发模式。快速分发：不考虑资源质量，直接基于现有资源返回。 <br>高质量分发：返回高质量资源，若没有，则触发生成高质量资源，成功后才返回。 <br>均衡分发：若存在高质量资源，则直接返回高质量资源。否则，先返回低质量资源，并触发生成高质量资源，成功后再返回一次高质量资源。 <br> |
| [MediaLibrary_MediaType](#medialibrary_mediatype) | MediaLibrary_MediaType | 媒体类型的枚举。 |
| [MediaLibrary_MediaSubType](#medialibrary_mediasubtype) | MediaLibrary_MediaSubType | 媒体资源子类型的枚举。 |
| [MediaLibrary_ResourceType](#medialibrary_resourcetype) | MediaLibrary_ResourceType | 资源类型的枚举。 |
| [MediaLibrary_ImageFileType](#medialibrary_imagefiletype) | MediaLibrary_ImageFileType | 图像文件类型的枚举。 |
| [MediaLibrary_MediaQuality](#medialibrary_mediaquality) | MediaLibrary_MediaQuality | 媒体资源质量枚举。此枚举与请求媒体资源时定义的分发模式有关。快速分发：不考虑资源质量，直接基于现有资源返回。高质量分发：返回高质量资源，若没有，则触发生成高质量资源，成功后才返回。均衡分发：若存在高质量资源，则直接返回高质量资源。否则，先返回低质量资源，并触发生成高质量资源，成功后再返回一次高质量资源。 |
| [MediaLibrary_MediaContentType](#medialibrary_mediacontenttype) | MediaLibrary_MediaContentType | 媒体内容类型的枚举。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_MediaLibrary_OnDataPrepared)(int32_t result, MediaLibrary_RequestId requestId)](#oh_medialibrary_ondataprepared) | OH_MediaLibrary_OnDataPrepared | 当所请求的媒体资源准备完成时会触发回调。 |
| [typedef void (\*OH_MediaLibrary_OnImageDataPrepared)(MediaLibrary_ErrorCode result,MediaLibrary_RequestId requestId, MediaLibrary_MediaQuality mediaQuality, MediaLibrary_MediaContentType type,OH_ImageSourceNative* imageSourceNative)](#oh_medialibrary_onimagedataprepared) | OH_MediaLibrary_OnImageDataPrepared | 当请求的图像源准备就绪时调用。当所请求的图像源准备就绪时，会调用此函数。 |
| [typedef void (\*OH_MediaLibrary_OnMovingPhotoDataPrepared)(MediaLibrary_ErrorCode result,MediaLibrary_RequestId requestId, MediaLibrary_MediaQuality mediaQuality, MediaLibrary_MediaContentType type,OH_MovingPhoto* movingPhoto)](#oh_medialibrary_onmovingphotodataprepared) | OH_MediaLibrary_OnMovingPhotoDataPrepared | 当请求的动态照片准备就绪时调用。当所请求的动态照片准备就绪时，会调用此函数。 |

### 变量

| 名称 | 描述 |
| -- | -- |
| static const int32_t UUID_STR_MAX_LENGTH = 37 | 定义UUID最大长度。这个常量定义了UUID字符串的最大长度。<br>**起始版本：** 12 |

## 枚举类型说明

### MediaLibrary_ErrorCode

```
enum MediaLibrary_ErrorCode
```

**描述**

媒体库错误代码的枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| MEDIA_LIBRARY_OK = 0 | 媒体库结果正常。 |
| MEDIA_LIBRARY_PERMISSION_DENIED = 201 | 权限被拒绝。 |
| MEDIA_LIBRARY_PARAMETER_ERROR = 401 | 强制参数未指定，参数类型不正确或参数验证失败。 |
| MEDIA_LIBRARY_NO_SUCH_FILE = 23800101 | 文件不存在。 |
| MEDIA_LIBRARY_INVALID_DISPLAY_NAME = 23800102 | 显示名称无效。 |
| MEDIA_LIBRARY_INVALID_ASSET_URI = 23800103 | 资产uri无效。 |
| MEDIA_LIBRARY_INVALID_PHOTO_KEY = 23800104 | PhotoKey无效。 |
| MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED = 23800201 | 不支持该操作。 |
| MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR = 23800301 | 内部系统错误。建议重试并检查日志。可能的原因：1. 数据库已损坏。2. 文件系统异常。3. IPC请求超时。 |

### MediaLibrary_DeliveryMode

```
enum MediaLibrary_DeliveryMode
```

**描述**

请求资源分发模式。此枚举定义了请求资源的分发模式。快速分发：不考虑资源质量，直接基于现有资源返回。 <br>高质量分发：返回高质量资源，若没有，则触发生成高质量资源，成功后才返回。 <br>均衡分发：若存在高质量资源，则直接返回高质量资源。否则，先返回低质量资源，并触发生成高质量资源，成功后再返回一次高质量资源。 <br>

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| MEDIA_LIBRARY_FAST_MODE = 0 | 快速分发。 |
| MEDIA_LIBRARY_HIGH_QUALITY_MODE = 1 | 高质量分发。 |
| MEDIA_LIBRARY_BALANCED_MODE = 2 | 均衡分发。 |

### MediaLibrary_MediaType

```
enum MediaLibrary_MediaType
```

**描述**

媒体类型的枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| MEDIA_LIBRARY_IMAGE = 1 | 图像资产。 |
| MEDIA_LIBRARY_VIDEO = 2 | 视频资产。 |

### MediaLibrary_MediaSubType

```
enum MediaLibrary_MediaSubType
```

**描述**

媒体资源子类型的枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| MEDIA_LIBRARY_DEFAULT = 0 | 默认照片类型。 |
| MEDIA_LIBRARY_MOVING_PHOTO = 3 | 动态照片类型。 |
| MEDIA_LIBRARY_BURST = 4 | 连拍照片类型。 |

### MediaLibrary_ResourceType

```
enum MediaLibrary_ResourceType
```

**描述**

资源类型的枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| MEDIA_LIBRARY_IMAGE_RESOURCE = 1 | 图像资源。 |
| MEDIA_LIBRARY_VIDEO_RESOURCE = 2 | 视频资源。 |

### MediaLibrary_ImageFileType

```
enum MediaLibrary_ImageFileType
```

**描述**

图像文件类型的枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| MEDIA_LIBRARY_IMAGE_JPEG = 1 | JPEG类型。 |

### MediaLibrary_MediaQuality

```
enum MediaLibrary_MediaQuality
```

**描述**

媒体资源质量枚举。此枚举与请求媒体资源时定义的分发模式有关。快速分发：不考虑资源质量，直接基于现有资源返回。高质量分发：返回高质量资源，若没有，则触发生成高质量资源，成功后才返回。均衡分发：若存在高质量资源，则直接返回高质量资源。否则，先返回低质量资源，并触发生成高质量资源，成功后再返回一次高质量资源。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| MEDIA_LIBRARY_QUALITY_FAST = 1 | 不考虑资源质量，直接返回的现有资源。 |
| MEDIA_LIBRARY_QUALITY_FULL = 2 | 高质量资源。 |

### MediaLibrary_MediaContentType

```
enum MediaLibrary_MediaContentType
```

**描述**

媒体内容类型的枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| MEDIA_LIBRARY_COMPRESSED = 1 | 压缩媒体内容类型。 |
| MEDIA_LIBRARY_PICTURE_OBJECT = 2 | 图片对象媒体内容类型。 |


## 函数说明

### OH_MediaLibrary_OnDataPrepared()

```
typedef void (*OH_MediaLibrary_OnDataPrepared)(int32_t result, MediaLibrary_RequestId requestId)
```

**描述**

当所请求的媒体资源准备完成时会触发回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t result | 请求资源处理的结果。 |
|  MediaLibrary_RequestId requestId | 请求Id。 |

### OH_MediaLibrary_OnImageDataPrepared()

```
typedef void (*OH_MediaLibrary_OnImageDataPrepared)(MediaLibrary_ErrorCode result,MediaLibrary_RequestId requestId, MediaLibrary_MediaQuality mediaQuality, MediaLibrary_MediaContentType type,OH_ImageSourceNative* imageSourceNative)
```

**描述**

当请求的图像源准备就绪时调用。当所请求的图像源准备就绪时，会调用此函数。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) result | 处理所请求资源的结果[MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode)。 |
| [MediaLibrary_RequestId](capi-medialibrary-requestid.md) requestId | 请求的[MediaLibrary_RequestId](capi-medialibrary-requestid.md)。 |
|  MediaLibrary_MediaQuality mediaQuality | 请求源的[MediaLibrary_MediaQuality](capi-media-asset-base-capi-h.md#medialibrary_mediaquality)。 |
|  MediaLibrary_MediaContentType type | 请求源的[MediaLibrary_MediaContentType](capi-media-asset-base-capi-h.md#medialibrary_mediacontenttype)。 |
| OH_ImageSourceNative* imageSourceNative | 当请求的图像源准备就绪时获取{@link OH_ImageSourceNative}。 |

### OH_MediaLibrary_OnMovingPhotoDataPrepared()

```
typedef void (*OH_MediaLibrary_OnMovingPhotoDataPrepared)(MediaLibrary_ErrorCode result,MediaLibrary_RequestId requestId, MediaLibrary_MediaQuality mediaQuality, MediaLibrary_MediaContentType type,OH_MovingPhoto* movingPhoto)
```

**描述**

当请求的动态照片准备就绪时调用。当所请求的动态照片准备就绪时，会调用此函数。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [MediaLibrary_ErrorCode](#medialibrary_errorcode) result | 处理所请求资源的结果[MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode)。 |
| [MediaLibrary_RequestId](capi-medialibrary-requestid.md) requestId | 请求的[MediaLibrary_RequestId](capi-medialibrary-requestid.md)。 |
|  MediaLibrary_MediaQuality mediaQuality | 请求资源的[MediaLibrary_MediaQuality](capi-media-asset-base-capi-h.md#medialibrary_mediaquality)。 |
|  MediaLibrary_MediaContentType type | 请求资源的[MediaLibrary_MediaContentType](capi-media-asset-base-capi-h.md#medialibrary_mediacontenttype)。 |
| [OH_MovingPhoto](capi-oh-movingphoto.md)* movingPhoto | 当请求的动态图片准备就绪时获取[OH_MovingPhoto](capi-oh-movingphoto.md)。 |


