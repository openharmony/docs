# avmetadata_extractor.h

## 概述

定义AVMetadataExtractor接口。使用其C API从媒体资源中获取元数据。

**库：** libavmetadata_extractor.so

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18

**相关模块：** [AVMetadataExtractor](capi-avmetadataextractor.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AVMetadataExtractor](capi-avmetadaextractor-oh-avmetadataextractor.md) | OH_AVMetadataExtractor | 定义OH_AVMetadataExtractor类型。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_AVMetadataExtractor* OH_AVMetadataExtractor_Create(void)](#oh_avmetadataextractor_create) | 创建OH_AVMetadataExtractor实例。 |
| [OH_AVErrCode OH_AVMetadataExtractor_SetFDSource(OH_AVMetadataExtractor* extractor,int32_t fd, int64_t offset, int64_t size)](#oh_avmetadataextractor_setfdsource) | 通过媒体文件描述设置数据源。 |
| [OH_AVErrCode OH_AVMetadataExtractor_FetchMetadata(OH_AVMetadataExtractor* extractor, OH_AVFormat* avMetadata)](#oh_avmetadataextractor_fetchmetadata) | 从媒体资源中获取元数据。此函数必须在[OH_AVMetadataExtractor_SetFDSource](#oh_avmetadataextractor_setfdsource)之后调用。 |
| [OH_AVErrCode OH_AVMetadataExtractor_FetchAlbumCover(OH_AVMetadataExtractor* extractor, OH_PixelmapNative** pixelMap)](#oh_avmetadataextractor_fetchalbumcover) | 获取音频专辑封面。此函数必须在[OH_AVMetadataExtractor_SetFDSource](#oh_avmetadataextractor_setfdsource)之后调用。 |
| [OH_AVErrCode OH_AVMetadataExtractor_Release(OH_AVMetadataExtractor* extractor)](#oh_avmetadataextractor_release) | 释放用于OH_AVMetadataExtractor的资源并销毁OH_AVMetadataExtractor实例。 |

## 函数说明

### OH_AVMetadataExtractor_Create()

```
OH_AVMetadataExtractor* OH_AVMetadataExtractor_Create(void)
```

**描述**

创建OH_AVMetadataExtractor实例。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVMetadataExtractor](capi-avmetadaextractor-oh-avmetadataextractor.md)* | 创建成功时返回指向OH_AVMetadataExtractor实例的指针，否则返回空指针。<br>         可能的失败原因：HstEngineFactory::CreateAVMetadataHelperEngine执行失败。 |

### OH_AVMetadataExtractor_SetFDSource()

```
OH_AVErrCode OH_AVMetadataExtractor_SetFDSource(OH_AVMetadataExtractor* extractor,int32_t fd, int64_t offset, int64_t size)
```

**描述**

通过媒体文件描述设置数据源。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataExtractor](capi-avmetadaextractor-oh-avmetadataextractor.md)* extractor | 指向OH_AVMetadataExtractor实例的指针。 |
| int32_t fd | 媒体源的文件描述符。 |
| int64_t offset | 媒体源在文件描述符中的偏移量。 |
| int64_t size | 媒体源的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL： 输入的extractor为空指针或参数无效。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作被禁止。<br>         AV_ERR_NO_MEMORY：内部内存分配失败。 |

### OH_AVMetadataExtractor_FetchMetadata()

```
OH_AVErrCode OH_AVMetadataExtractor_FetchMetadata(OH_AVMetadataExtractor* extractor, OH_AVFormat* avMetadata)
```

**描述**

从媒体资源中获取元数据。

此函数必须在[OH_AVMetadataExtractor_SetFDSource](#oh_avmetadataextractor_setfdsource)之后调用。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataExtractor](capi-avmetadaextractor-oh-avmetadataextractor.md)* extractor | 指向OH_AVMetadataExtractor实例的指针。 |
| [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat)* avMetadata | 指向OH_AVFormat实例的指针，其内容包含获取的元数据信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL： 输入的extractor为空指针或参数无效。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作被禁止。<br>         AV_ERR_UNSUPPORTED_FORMAT：格式不支持。<br>         AV_ERR_NO_MEMORY：内部内存分配失败。 |

### OH_AVMetadataExtractor_FetchAlbumCover()

```
OH_AVErrCode OH_AVMetadataExtractor_FetchAlbumCover(OH_AVMetadataExtractor* extractor, OH_PixelmapNative** pixelMap)
```

**描述**

获取音频专辑封面。

此函数必须在[OH_AVMetadataExtractor_SetFDSource](#oh_avmetadataextractor_setfdsource)之后调用。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataExtractor](capi-avmetadaextractor-oh-avmetadataextractor.md)* extractor | 指向OH_AVMetadataExtractor实例的指针。 |
| [OH_PixelmapNative](../apis-image-kit/capi-image-nativemodule-oh-pixelmapnative.md** pixelMap | 从音频源获取的专辑封面。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL： 输入的extractor为空指针或参数无效。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作被禁止。<br>         AV_ERR_UNSUPPORTED_FORMAT：格式不支持。<br>         AV_ERR_NO_MEMORY：内部内存分配失败。 |

### OH_AVMetadataExtractor_Release()

```
OH_AVErrCode OH_AVMetadataExtractor_Release(OH_AVMetadataExtractor* extractor)
```

**描述**

释放用于OH_AVMetadataExtractor的资源并销毁OH_AVMetadataExtractor实例。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataExtractor](capi-avmetadaextractor-oh-avmetadataextractor.md)* extractor | 指向OH_AVMetadataExtractor实例指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL： 输入的extractor为空指针或参数无效。 |


