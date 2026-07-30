# native_avcodec_videobase.h
<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @w_Machine_cc-->

## 概述

声明用于基础视频编解码功能以及视频特定配置和参数的Native API。

**引用文件：** <multimedia/player_framework/native_avcodec_videobase.h>

**库：** libnative_media_codecbase.so

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**起始版本：** 26.0.0

**相关模块：** [CodecBase](capi-codecbase.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_VideoMetadataRoiSemanticLabel](#oh_videometadataroisemanticlabel) | OH_VideoMetadataRoiSemanticLabel | 视频编码中感兴趣区域（ROI）的语义标签。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_AVErrCode OH_VideoMetadata_AppendRoiString(char **roiStrInOut, OH_AVFormat *format)](#oh_videometadata_appendroistring) | 将OH_AVFormat句柄中的感兴趣区域（ROI）配置转化为字符串，并将其追加到目标字符串中。此函数从提供的格式句柄中提取ROI属性（如坐标、量化参数偏移量和语义标签），构建标准的ROI字符串表示，并将其追加到roiStrInOut指向的字符串末尾。如果*roiStrInOut为NULL，则会分配一个新字符串，如果不为NULL，则会重新分配现有字符串的内存以追加新配置。 |
| [OH_AVErrCode OH_VideoMetadata_GetRoiCount(const char *roiStr, uint32_t *outCount)](#oh_videometadata_getroicount) | 获取ROI字符串，以获取其中包含的有效ROI区域数量。此接口不受具体后端容量限制影响，并根据语法规则识别ROI字符串中满足规则要求的ROI区域数量。 |
| [OH_AVErrCode OH_VideoMetadata_ParseRoiString(const char *roiStr, OH_AVFormat **outOwnedFormats, uint32_t maxCapacity, uint32_t *outCount)](#oh_videometadata_parseroistring) | 解析ROI字符串并填充调用者提供的OH_AVFormat数组。 |

### 变量

| 名称 | 描述 |
| -- | -- |
| const char * OH_MD_KEY_VIDEO_METADATA_ROI_TOP | 用于描述单个ROI（感兴趣区域）矩形顶部坐标（y）的键，值类型为int32_t。坐标系的原点位于视频的左上角。取值范围为[0, OH_MD_KEY_VIDEO_METADATA_ROI_BOTTOM)。这是配置ROI参数时的必填键。<br>**起始版本：** 26.0.0<br>**系统能力：** SystemCapability.Multimedia.Media.CodecBase |
| const char * OH_MD_KEY_VIDEO_METADATA_ROI_LEFT | 用于描述单个ROI矩形左侧坐标 (x) 的键，值类型为 int32_t。坐标系的原点位于视频的左上角。取值范围为[0, OH_MD_KEY_VIDEO_METADATA_ROI_RIGHT)。这是配置ROI参数时的必填键。<br>**起始版本：** 26.0.0 |
| const char * OH_MD_KEY_VIDEO_METADATA_ROI_BOTTOM | 用于描述单个ROI矩形底部坐标（y）的键，值类型为int32_t。坐标系的原点位于视频的左上角。取值范围为(OH_MD_KEY_VIDEO_METADATA_ROI_TOP, OH_MD_KEY_VIDEO_HEIGHT]。这是配置ROI参数时的必填键。<br>**起始版本：** 26.0.0 |
| const char * OH_MD_KEY_VIDEO_METADATA_ROI_RIGHT | 用于描述单个ROI矩形右侧坐标（x）的键，值类型为int32_t。坐标系的原点位于视频的左上角。取值范围为(OH_MD_KEY_VIDEO_METADATA_ROI_LEFT, OH_MD_KEY_VIDEO_WIDTH]。这是配置ROI参数时的必填键。<br>**起始版本：** 26.0.0 |
| const char * OH_MD_KEY_VIDEO_METADATA_ROI_DELTA_QP | 用于描述单个ROI的量化参数（QP）相对偏移值的键，值类型为int32_t。该变量取值范围为[-51, 51]。这是配置ROI参数时的可选键。如果未设置此键，编码器将对此区域使用其默认的量化参数策略。<br>**起始版本：** 26.0.0 |
| const char * OH_MD_KEY_VIDEO_METADATA_ROI_SEM_LABEL | 用于描述单个ROI语义标签的键，值类型为int32_t。该变量值必须与[OH_VideoMetadataRoiSemanticLabel](capi-native-avcodec-videobase-h.md#oh_videometadataroisemanticlabel)对应。这是配置ROI参数时的可选键。如果未设置此键，该区域将采用默认的语义处理策略。<br>**起始版本：** 26.0.0 |

## 枚举类型说明

### OH_VideoMetadataRoiSemanticLabel

```c
enum OH_VideoMetadataRoiSemanticLabel
```

**描述**

视频编码中感兴趣区域（ROI）的语义标签。

**起始版本：** 26.0.0

| 枚举项 | 描述 |
| -- | -- |
| OH_VIDEO_METADATA_ROI_SEM_LABEL_OTHER = 0 | 表示未指定或未知的区域。<br>**起始版本：** 26.0.0 |
| OH_VIDEO_METADATA_ROI_SEM_LABEL_FACE = 1 | 表示该ROI包含人脸。<br>**起始版本：** 26.0.0 |


## 函数说明

### OH_VideoMetadata_AppendRoiString()

```c
OH_AVErrCode OH_VideoMetadata_AppendRoiString(char **roiStrInOut, OH_AVFormat *format)
```

**描述**

将OH_AVFormat句柄中的感兴趣区域（ROI）配置转化为字符串，并将其追加到目标字符串中。此函数从提供的格式句柄中提取ROI属性（如坐标、量化参数偏移量和语义标签），构建标准的ROI字符串表示，并将其追加到roiStrInOut指向的字符串中末尾。如果*roiStrInOut为NULL，则会分配一个新字符串，如果不为NULL，则会重新分配现有字符串的内存以追加新配置。

> **说明：** 
> 
> 调用者拥有为*roiStrInOut分配内存的所有权。
> 内存是通过标准C库分配器（malloc/realloc）分配的。
> 当不再需要该字符串时，调用者必须使用匹配的标准C库释放器（free）释放该字符串，并将指针设置为NULL以防止重复释放。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| char **roiStrInOut | 指向目标字符串的双重指针。指针本身不能为NULL。如果*roiStrInOut为NULL，则分配一个新字符串。 |
| OH_AVFormat *format | 包含要追加的ROI参数的OH_AVFormat句柄，不能为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | AV_ERR_OK：表示字符串成功转化并追加。<br> AV_ERR_INVALID_VAL：表示roiStrInOut指针或format句柄为NULL，或者格式缺少必需的ROI键。<br> AV_ERR_NO_MEMORY：表示内部内存分配或重新分配失败。 |

### OH_VideoMetadata_GetRoiCount()

```c
OH_AVErrCode OH_VideoMetadata_GetRoiCount(const char *roiStr, uint32_t *outCount)
```

**描述**

预解析ROI字符串，以获取其中包含的有效ROI区域数量。此接口不受具体后端容量限制影响，并根据语法规则识别ROI字符串中满足规则要求的ROI区域数量。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *roiStr | 输入的ROI配置字符串。 |
| uint32_t *outCount | 返回从字符串中解析出的有效ROI区域的数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | AV_ERR_OK：表示操作成功。<br> AV_ERR_INVALID_VAL：表示roiStr或outCount指针为NULL。 |

### OH_VideoMetadata_ParseRoiString()

```c
OH_AVErrCode OH_VideoMetadata_ParseRoiString(const char *roiStr, OH_AVFormat **outOwnedFormats, uint32_t maxCapacity, uint32_t *outCount)
```

**描述**

解析ROI字符串并填充调用者提供的OH_AVFormat数组。

>**说明：** 
>调用者拥有每个成功创建的OH_AVFormat句柄的所有权。返回时，有效的句柄存储在outOwnedFormats数组的前*outCount个元素中。- 完全或部分成功时（*outCount > 0），调用者必须使用[OH_AVFormat_Destroy](./capi-native-avformat-h.md#oh_avformat_destroy)逐个销毁有效句柄，以防止内存泄漏。- 完全失败时（*outCount == 0），不会创建任何句柄，也无需销毁。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *roiStr | 输入的ROI配置字符串。 |
| OH_AVFormat **outOwnedFormats | 由调用者分配的指针数组，用于接收解析后的OH_AVFormat句柄。调用者拥有此数组中每个非NULL句柄的所有权。 |
| uint32_t maxCapacity | 指示outOwnedFormats数组的最大物理容量，以防止越界写入。 |
| uint32_t *outCount | 返回成功解析并填充到数组中的实际ROI数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | AV_ERR_OK：表示操作成功。<br> AV_ERR_INVALID_VAL：表示roiStr、outOwnedFormats或outCount为NULL。 |


