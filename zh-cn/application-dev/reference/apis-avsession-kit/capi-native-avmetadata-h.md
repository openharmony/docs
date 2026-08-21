# native_avmetadata.h
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->

## 概述

提供播控元数据的定义。

**引用文件：** <multimedia/av_session/native_avmetadata.h>

**库：** libohavsession.so

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**起始版本：** 13

**相关模块：** [OHAVSession](capi-ohavsession.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AVMetadataBuilderStruct](capi-ohavsession-oh-avmetadatabuilderstruct.md) | OH_AVMetadataBuilder | 会话元数据构造器。用于构造会话元数据。 |
| [OH_AVMetadataStruct](capi-ohavsession-oh-avmetadatastruct.md) | OH_AVMetadata | 会话元数据。用于存储媒体资源元数据的结构体定义。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [AVMetadata_Result OH_AVMetadataBuilder_Create(OH_AVMetadataBuilder** builder)](#oh_avmetadatabuilder_create) | 创建一个元数据构造器。 |
| [AVMetadata_Result OH_AVMetadataBuilder_Destroy(OH_AVMetadataBuilder* builder)](#oh_avmetadatabuilder_destroy) | 销毁元数据构造器。 |
| [AVMetadata_Result OH_AVMetadataBuilder_SetAssetId(OH_AVMetadataBuilder* builder, const char* assetId)](#oh_avmetadatabuilder_setassetid) | 设置当前媒体资源ID。 |
| [AVMetadata_Result OH_AVMetadataBuilder_SetTitle(OH_AVMetadataBuilder* builder, const char* title)](#oh_avmetadatabuilder_settitle) | 设置资源标题。 |
| [AVMetadata_Result OH_AVMetadataBuilder_SetArtist(OH_AVMetadataBuilder* builder, const char* artist)](#oh_avmetadatabuilder_setartist) | 设置资源所属的艺术家信息。 |
| [AVMetadata_Result OH_AVMetadataBuilder_SetAuthor(OH_AVMetadataBuilder* builder, const char* author)](#oh_avmetadatabuilder_setauthor) | 设置资源的作者。 |
| [AVMetadata_Result OH_AVMetadataBuilder_SetAlbum(OH_AVMetadataBuilder* builder, const char* album)](#oh_avmetadatabuilder_setalbum) | 设置资源专辑名称。 |
| [AVMetadata_Result OH_AVMetadataBuilder_SetWriter(OH_AVMetadataBuilder* builder, const char* writer)](#oh_avmetadatabuilder_setwriter) | 设置资源词作者。 |
| [AVMetadata_Result OH_AVMetadataBuilder_SetComposer(OH_AVMetadataBuilder* builder, const char* composer)](#oh_avmetadatabuilder_setcomposer) | 设置资源作曲者。 |
| [AVMetadata_Result OH_AVMetadataBuilder_SetDuration(OH_AVMetadataBuilder* builder, int64_t duration)](#oh_avmetadatabuilder_setduration) | 设置资源播放时长。 |
| [AVMetadata_Result OH_AVMetadataBuilder_SetMediaImageUri(OH_AVMetadataBuilder* builder, const char* mediaImageUri)](#oh_avmetadatabuilder_setmediaimageuri) | 设置媒体图片的URI地址。 |
| [AVMetadata_Result OH_AVMetadataBuilder_SetSubtitle(OH_AVMetadataBuilder* builder, const char* subtitle)](#oh_avmetadatabuilder_setsubtitle) | 设置副标题。 |
| [AVMetadata_Result OH_AVMetadataBuilder_SetDescription(OH_AVMetadataBuilder* builder, const char* description)](#oh_avmetadatabuilder_setdescription) | 设置媒体描述信息。 |
| [AVMetadata_Result OH_AVMetadataBuilder_SetLyric(OH_AVMetadataBuilder* builder, const char* lyric)](#oh_avmetadatabuilder_setlyric) | 设置歌词。 |
| [AVMetadata_Result OH_AVMetadataBuilder_SetSkipIntervals(OH_AVMetadataBuilder* builder, AVMetadata_SkipIntervals intervals)](#oh_avmetadatabuilder_setskipintervals) | 设置资源的跳转间隔时间。 |
| [AVMetadata_Result OH_AVMetadataBuilder_SetDisplayTags(OH_AVMetadataBuilder* builder, int32_t tags)](#oh_avmetadatabuilder_setdisplaytags) | 设置媒体资源的金标类型。 |
| [AVMetadata_Result OH_AVMetadataBuilder_SetFilter(OH_AVMetadataBuilder* builder, uint32_t filter)](#oh_avmetadatabuilder_setfilter) | 设置支持的协议。 |
| [AVMetadata_Result OH_AVMetadataBuilder_GenerateAVMetadata(OH_AVMetadataBuilder* builder, OH_AVMetadata** avMetadata)](#oh_avmetadatabuilder_generateavmetadata) | 生成媒体元数据对象。 |
| [AVMetadata_Result OH_AVMetadata_Destroy(OH_AVMetadata* avMetadata)](#oh_avmetadata_destroy) | 释放媒体元数据对象。 |

## 函数说明

### OH_AVMetadataBuilder_Create()

```c
AVMetadata_Result OH_AVMetadataBuilder_Create(OH_AVMetadataBuilder** builder)
```

**描述**

创建一个元数据构造器。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)** builder |  指向创建的构造器实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_INVALID_PARAM：参数builder为nullptr。<br>         AVMETADATA_ERROR_NO_MEMORY：内存不足。 |

### OH_AVMetadataBuilder_Destroy()

```c
AVMetadata_Result OH_AVMetadataBuilder_Destroy(OH_AVMetadataBuilder* builder)
```

**描述**

销毁元数据构造器。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | 指向元数据构造器的实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br> AVMETADATA_ERROR_INVALID_PARAM：参数builder为nullptr。 |

### OH_AVMetadataBuilder_SetAssetId()

```c
AVMetadata_Result OH_AVMetadataBuilder_SetAssetId(OH_AVMetadataBuilder* builder, const char* assetId)
```

**描述**

设置当前媒体资源ID。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | 指向元数据构造器的实例。 |
| const char* assetId | 资源ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_INVALID_PARAM：<br>                                       1. 参数builder为nullptr。<br>                                       2. 参数assetId为nullptr。 |

### OH_AVMetadataBuilder_SetTitle()

```c
AVMetadata_Result OH_AVMetadataBuilder_SetTitle(OH_AVMetadataBuilder* builder, const char* title)
```

**描述**

设置资源标题。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | 指向元数据构造器的实例。 |
| const char* title | 标题。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_INVALID_PARAM：<br>                                       1. 参数builder为nullptr。<br>                                       2. 参数title为nullptr。 |

### OH_AVMetadataBuilder_SetArtist()

```c
AVMetadata_Result OH_AVMetadataBuilder_SetArtist(OH_AVMetadataBuilder* builder, const char* artist)
```

**描述**

设置资源所属的艺术家信息。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | 指向元数据构造器的实例。 |
| const char* artist | 媒体资源的艺术家。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_INVALID_PARAM：<br>                                       1. 参数builder为nullptr。<br>                                       2. 参数artist为nullptr。 |

### OH_AVMetadataBuilder_SetAuthor()

```c
AVMetadata_Result OH_AVMetadataBuilder_SetAuthor(OH_AVMetadataBuilder* builder, const char* author)
```

**描述**

设置资源的作者。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | 指向元数据构造器的实例。 |
| const char* author | 作者。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_INVALID_PARAM：<br>                                       1. 参数builder为nullptr。<br>                                       2. 参数author为nullptr。 |

### OH_AVMetadataBuilder_SetAlbum()

```c
AVMetadata_Result OH_AVMetadataBuilder_SetAlbum(OH_AVMetadataBuilder* builder, const char* album)
```

**描述**

设置资源专辑名称。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | 指向元数据构造器的实例。 |
| const char* album | 专辑名。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_INVALID_PARAM：<br>                                       1. 参数builder为nullptr。<br>                                       2. 参数album为nullptr。 |

### OH_AVMetadataBuilder_SetWriter()

```c
AVMetadata_Result OH_AVMetadataBuilder_SetWriter(OH_AVMetadataBuilder* builder, const char* writer)
```

**描述**

设置资源词作者。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | 指向元数据构造器的实例。 |
| const char* writer | 词作者。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_INVALID_PARAM：<br>                                       1. 参数builder为nullptr。<br>                                       2. 参数writer为nullptr。 |

### OH_AVMetadataBuilder_SetComposer()

```c
AVMetadata_Result OH_AVMetadataBuilder_SetComposer(OH_AVMetadataBuilder* builder, const char* composer)
```

**描述**

设置资源作曲者。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | 指向元数据构造器的实例。 |
| const char* composer | 作曲者。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_INVALID_PARAM：<br>                                       1. 参数builder为nullptr。<br>                                       2. 参数composer为nullptr。 |

### OH_AVMetadataBuilder_SetDuration()

```c
AVMetadata_Result OH_AVMetadataBuilder_SetDuration(OH_AVMetadataBuilder* builder, int64_t duration)
```

**描述**

设置资源播放时长。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | 指向元数据构造器的实例。 |
| int64_t duration | 资源播放时长，以ms为单位。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_INVALID_PARAM：参数builder为nullptr。 |

### OH_AVMetadataBuilder_SetMediaImageUri()

```c
AVMetadata_Result OH_AVMetadataBuilder_SetMediaImageUri(OH_AVMetadataBuilder* builder, const char* mediaImageUri)
```

**描述**

设置媒体图片的URI地址。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | 指向元数据构造器的实例。 |
| const char* mediaImageUri | 媒体图片的URI地址。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_INVALID_PARAM：<br>                                       1. 参数builder为nullptr。<br>                                       2. 参数mediaImageUri为nullptr。 |

### OH_AVMetadataBuilder_SetSubtitle()

```c
AVMetadata_Result OH_AVMetadataBuilder_SetSubtitle(OH_AVMetadataBuilder* builder, const char* subtitle)
```

**描述**

设置副标题。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | 指向元数据构造器的实例。 |
| const char* subtitle | 副标题名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_INVALID_PARAM：<br>                                       1. 参数builder为nullptr。<br>                                       2. 参数subtitle为nullptr。 |

### OH_AVMetadataBuilder_SetDescription()

```c
AVMetadata_Result OH_AVMetadataBuilder_SetDescription(OH_AVMetadataBuilder* builder, const char* description)
```

**描述**

设置媒体描述信息。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | 指向元数据构造器的实例。 |
| const char* description | 媒体描述信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_INVALID_PARAM：<br>                                       1. 参数builder为nullptr。<br>                                       2. 参数description为nullptr。 |

### OH_AVMetadataBuilder_SetLyric()

```c
AVMetadata_Result OH_AVMetadataBuilder_SetLyric(OH_AVMetadataBuilder* builder, const char* lyric)
```

**描述**

设置歌词。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | 指向元数据构造器的实例。 |
| const char* lyric | LRC格式的歌词内容。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_INVALID_PARAM：<br>                                       1. 参数builder为nullptr。<br>                                       2. 参数lyric为nullptr。 |

### OH_AVMetadataBuilder_SetSkipIntervals()

```c
AVMetadata_Result OH_AVMetadataBuilder_SetSkipIntervals(OH_AVMetadataBuilder* builder, AVMetadata_SkipIntervals intervals)
```

**描述**

设置资源的跳转间隔时间。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | 指向元数据构造器的实例。 |
| [AVMetadata_SkipIntervals](capi-native-avsession-base-h.md#avmetadata_skipintervals) intervals | 跳转的时间间隔。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_INVALID_PARAM：<br>                                       1. 参数builder为nullptr。<br>                                       2. 参数intervals为nullptr。 |

### OH_AVMetadataBuilder_SetDisplayTags()

```c
AVMetadata_Result OH_AVMetadataBuilder_SetDisplayTags(OH_AVMetadataBuilder* builder, int32_t tags)
```

**描述**

设置媒体资源的金标类型。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | 指向元数据构造器的实例。 |
| int32_t tags | 用于在播控中心显示的媒体资源金标类型，取值参考[AVMetadata_DisplayTag](capi-native-avsession-base-h.md#avmetadata_displaytag)相关定义。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_INVALID_PARAM：参数builder为nullptr。 |

### OH_AVMetadataBuilder_SetFilter()

```c
AVMetadata_Result OH_AVMetadataBuilder_SetFilter(OH_AVMetadataBuilder* builder, uint32_t filter)
```

**描述**

设置支持的协议。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | 指向元数据构造器的实例。 |
| uint32_t filter | 此会话支持的协议。如果没有设置，默认为[AVSession_ProtocolType](capi-native-avsession-base-h.md#avsession_protocoltype).TYPE_CAST_PLUS_STREAM。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_INVALID_PARAM：<br>                                       1. 参数builder为nullptr。<br>                                       2. 参数filter是无效的。 |

### OH_AVMetadataBuilder_GenerateAVMetadata()

```c
AVMetadata_Result OH_AVMetadataBuilder_GenerateAVMetadata(OH_AVMetadataBuilder* builder, OH_AVMetadata** avMetadata)
```

**描述**

生成媒体元数据对象。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | 指向元数据构造器的实例。 |
| [OH_AVMetadata](capi-ohavsession-oh-avmetadatastruct.md)** avMetadata | 指向OH_AVMetadata的指针对象，用于接收生成的元数据对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_NO_MEMORY：内存不足。<br>         AVMETADATA_ERROR_INVALID_PARAM：<br>                                       1. 参数builder为nullptr。<br>                                       2. 参数avMetadata为nullptr。 |

### OH_AVMetadata_Destroy()

```c
AVMetadata_Result OH_AVMetadata_Destroy(OH_AVMetadata* avMetadata)
```

**描述**

释放媒体元数据对象。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMetadata](capi-ohavsession-oh-avmetadatastruct.md)* avMetadata | 指向元数据实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [AVMetadata_Result](capi-native-avsession-errors-h.md#avmetadata_result) | AVMETADATA_SUCCESS：函数执行成功。<br>         AVMETADATA_ERROR_INVALID_PARAM：参数avMetadata为nullptr。 |


