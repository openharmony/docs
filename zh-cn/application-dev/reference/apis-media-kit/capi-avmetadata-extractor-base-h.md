# avmetadata_extractor_base.h
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @hanzhengshi-->
<!--Designer: @chris2981-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

## 概述

定义AVMetadataExtractor常量。

**引用文件：** <multimedia/player_framework/avmetadata_extractor_base.h>

**库：** libavmetadata_extractor.so

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18

**相关模块：** [AVMetadataExtractor](capi-avmetadataextractor.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AVMetadataExtractor_FrameInfo](capi-avmetadataextractor-oh-avmetadataextractor-frameinfo.md) | OH_AVMetadataExtractor_FrameInfo | 定义从视频中提取出的帧的信息。 |
| [OH_AVMetadataExtractor_OutputParam](capi-avmetadataextractor-oh-avmetadataextractor-outputparam.md) | OH_AVMetadataExtractor_OutputParam | 定义由AVMetadataExtractor提取的帧的输出参数。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AVMetadataExtractor_FetchState](#oh_avmetadataextractor_fetchstate) | OH_AVMetadataExtractor_FetchState | 枚举帧提取操作的结果状态。 |

### 变量

| 名称 | 描述 |
| -- | -- |
| static const char * OH_AVMETADATA_EXTRACTOR_ALBUM = "album" | 获取专辑标题的关键字，对应值类型为const char*。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_ALBUM_ARTIST = "albumArtist" | 获取专辑艺术家的关键字，对应值类型为const char*。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_ARTIST = "artist" | 获取媒体资源艺术家的关键字，对应值类型为const char*。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_AUTHOR = "author" | 获取媒体资源作者的关键字，对应值类型为const char*。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_DATE_TIME = "dateTime" | 获取媒体资源创建时间的关键字，对应值类型为const char*。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_DATE_TIME_FORMAT = "dateTimeFormat" | 获取媒体资源创建时间的关键字，对应值类型为const char*，按YYYY-MM-DD HH:mm:ss格式输出。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_COMPOSER = "composer" | 获取媒体资源作曲家的关键字，对应值类型为const char*。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_DURATION = "duration" | 获取媒体资源时长的关键字，对应值类型为int64_t，单位为毫秒（ms）。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_GENRE = "genre" | 获取媒体资源类型或体裁的关键字，对应值类型为const char*。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_HAS_AUDIO = "hasAudio" | 获取媒体资源是否包含音频的关键字，对应值类型为int32_t。<br>取值原则：0表示不包含音频，1表示包含音频。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_HAS_VIDEO = "hasVideo" | 获取媒体资源是否包含视频的关键字，对应值类型为int32_t。<br>取值原则：0表示不包含视频，1表示包含视频。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_MIME_TYPE = "mimeType" | 获取媒体资源mime类型的关键字，对应值类型为const char*，例如：“video/mp4”、“audio/mp4”和“audio/amr-wb”。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_TRACK_COUNT = "trackCount" | 获取媒体资源轨道数量的关键字，对应值类型为int32_t。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_SAMPLE_RATE = "sampleRate" | 获取音频采样率的关键字，对应值类型为int32_t，单位为赫兹（Hz）。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_TITLE = "title" | 获取媒体资源标题的关键字，对应值类型为const char*。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_VIDEO_HEIGHT = "videoHeight" | 获取视频高度的关键字，对应值类型为int32_t，单位为像素。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_VIDEO_WIDTH = "videoWidth" | 获取视频宽度的关键字，对应值类型为int32_t，单位为像素。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_VIDEO_ORIENTATION = "videoOrientation" | 获取视频旋转方向的关键字，对应值类型为int32_t，单位为度（°）。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_VIDEO_IS_HDR_VIVID = "hdrType" | 获取是否是HDR Vivid视频的关键字，对应值类型为int32_t。<br>        详情请参阅media_types.h中的[OH_Core_HdrType](../apis-avcodec-kit/capi-media-types-h.md#oh_core_hdrtype)。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_LOCATION_LATITUDE = "latitude" | 获取地理位置中的纬度值的关键字，对应值类型为float。<br>**起始版本：** 18 |
| static const char * OH_AVMETADATA_EXTRACTOR_LOCATION_LONGITUDE = "longitude" | 获取地理位置中的经度值的关键字，对应值类型为float。<br>**起始版本：** 18 |

## 枚举类型说明

### OH_AVMetadataExtractor_FetchState

```c
enum OH_AVMetadataExtractor_FetchState
```

**描述**

枚举帧提取操作的结果状态。

**起始版本：** 23

| 枚举项 | 描述 |
| -- | -- |
| OH_AVMETADATA_EXTRACTOR_FETCH_FAILED = 0 | 帧提取操作失败。 |
| OH_AVMETADATA_EXTRACTOR_FETCH_SUCCEEDED = 1 | 帧提取操作成功。 |
| OH_AVMETADATA_EXTRACTOR_FETCH_CANCELED = 2 | 帧提取操作被用户取消。 |


