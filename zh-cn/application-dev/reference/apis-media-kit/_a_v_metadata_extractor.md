# AVMetadataExtractor


## 概述

提供从媒体资源中获取元数据的API。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [avmetadata_extractor.h](avmetadata__extractor_8h.md) | 定义AVMetadataExtractor接口。使用AVMetadataExtractor提供的Native API从媒体资源中获取元数据。  | 
| [avmetadata_extractor_base.h](avmetadata__extractor__base_8h.md) | 定义AVMetadataExtractor的常量。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AVMetadataExtractor](#oh_avmetadataextractor) [OH_AVMetadataExtractor](#oh_avmetadataextractor) | 定义OH_AVMetadataExtractor类型。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVMetadataExtractor](#oh_avmetadataextractor) \* [OH_AVMetadataExtractor_Create](#oh_avmetadataextractor_create) (void) | 创建OH_AVMetadataExtractor实例。  | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVMetadataExtractor_SetFDSource](#oh_avmetadataextractor_setfdsource) ([OH_AVMetadataExtractor](#oh_avmetadataextractor) \*extractor, int32_t fd, int64_t offset, int64_t size) | 通过媒体文件描述设置数据源。  | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVMetadataExtractor_FetchMetadata](#oh_avmetadataextractor_fetchmetadata) ([OH_AVMetadataExtractor](#oh_avmetadataextractor) \*extractor, OH_AVFormat \*avMetadata) | 从媒体资源中获取元数据。 此函数必须在[SetFDSource](#oh_avmetadataextractor_setfdsource)之后调用。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVMetadataExtractor_FetchAlbumCover](#oh_avmetadataextractor_fetchalbumcover) ([OH_AVMetadataExtractor](#oh_avmetadataextractor) \*extractor, OH_PixelmapNative \*\*pixelMap) | 获取音频专辑封面。 此函数必须在[SetFDSource](#oh_avmetadataextractor_setfdsource)之后调用。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVMetadataExtractor_Release](#oh_avmetadataextractor_release) ([OH_AVMetadataExtractor](#oh_avmetadataextractor) \*extractor) | 释放用于OH_AVMetadataExtractor的资源以及销毁OH_AVMetadataExtractor对象。  | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| static const char\* [OH_AVMETADATA_EXTRACTOR_ALBUM](#oh_avmetadata_extractor_album) = "album" | 获取专辑的标题的关键字，对应值类型是const char\*。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_ALBUM_ARTIST](#oh_avmetadata_extractor_album_artist) = "albumArtist" | 获取专辑的艺术家的关键字，对应值类型是const char\*。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_ARTIST](#oh_avmetadata_extractor_artist) = "artist" | 获取媒体资源的艺术家的关键字，对应值类型是const char\*。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_AUTHOR](#oh_avmetadata_extractor_author) = "author" | 获取媒体资源的作者的关键字，对应值类型是const char\*。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_DATE_TIME](#oh_avmetadata_extractor_date_time) = "dateTime" | 取媒体资源的创建时间的关键字，对应值类型是const char\*。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_DATE_TIME_FORMAT](#oh_avmetadata_extractor_date_time_format) = "dateTimeFormat" | 获取媒体资源的创建时间的关键字，对应值类型是const char\*，按YYYY-MM-DD HH:mm:ss格式输出。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_COMPOSER](#oh_avmetadata_extractor_composer) = "composer" | 获取媒体资源的作曲家的关键字，对应值类型是const char\*。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_DURATION](#oh_avmetadata_extractor_duration) = "duration" | 获取媒体资源的时长的关键字，对应值类型是int64_t，单位为毫秒（ms）。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_GENRE](#oh_avmetadata_extractor_genre) = "genre" | 获取媒体资源的类型或体裁的关键字，对应值类型是const char\*。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_HAS_AUDIO](#oh_avmetadata_extractor_has_audio) = "hasAudio" | 获取媒体资源是否包含音频的关键字，对应值类型是int32_t。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_HAS_VIDEO](#oh_avmetadata_extractor_has_video) = "hasVideo" | 获取媒体资源是否包含视频的关键字，对应值类型是int32_t。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_MIME_TYPE](#oh_avmetadata_extractor_mime_type) = "mimeType" | 获取媒体资源的mime类型的关键字，对应值类型是const char\*，例如：“video/mp4”、“audio/mp4”和“audio/amr wb”。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_TRACK_COUNT](#oh_avmetadata_extractor_track_count) = "trackCount" | 获取媒体资源的轨道数量的关键字，对应值类型是int32_t。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_SAMPLE_RATE](#oh_avmetadata_extractor_sample_rate) = "sampleRate" | 获取音频的采样率的关键字，对应值类型是int32_t，单位为赫兹（Hz）。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_TITLE](#oh_avmetadata_extractor_title) = "title" | 获取媒体资源的标题的关键字，对应值类型是const char\*。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_VIDEO_HEIGHT](#oh_avmetadata_extractor_video_height) = "videoHeight" | 获取视频的高度的关键字，对应值类型int32_t，单位为像素。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_VIDEO_WIDTH](#oh_avmetadata_extractor_video_width) = "videoWidth" | 获取视频的宽度的关键字，对应值类型int32_t，单位为像素。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_VIDEO_ORIENTATION](#oh_avmetadata_extractor_video_orientation) = "videoOrientation" | 获取视频的旋转方向的关键字，对应值类型int32_t，单位为度（°）。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_VIDEO_IS_HDR_VIVID](#oh_avmetadata_extractor_video_is_hdr_vivid) = "hdrType" | 获取是否是HDR Vivid视频的关键字，对应值类型int32_t。 详情请参阅 [OH_Core_HdrType](../apis-avcodec-kit/_core.md#oh_core_hdrtype) 定义在 [media_types.h](../apis-avcodec-kit/media__types_8h.md) 。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_LOCATION_LATITUDE](#oh_avmetadata_extractor_location_latitude) = "latitude" | 获取地理位置中的纬度值的关键字，对应值类型float。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_LOCATION_LONGITUDE](#oh_avmetadata_extractor_location_longitude) = "longitude" | 获取地理位置中的经度值的关键字，对应值类型float。  | 


## 类型定义说明


### OH_AVMetadataExtractor

```
typedef struct OH_AVMetadataExtractor OH_AVMetadataExtractor
```
**描述**
定义OH_AVMetadataExtractor类型。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


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

如果创建成功返回指向OH_AVMetadataExtractor实例的指针，否则返回空指针。 

可能的失败原因：HstEngineFactory::CreateAVMetadataHelperEngine执行失败。


### OH_AVMetadataExtractor_FetchAlbumCover()

```
OH_AVErrCode OH_AVMetadataExtractor_FetchAlbumCover(OH_AVMetadataExtractor* extractor, OH_PixelmapNative** pixelMap)
```
**描述**
获取音频专辑封面。 此函数必须在[SetFDSource](#oh_avmetadataextractor_setfdsource)之后调用。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| extractor | 指向OH_AVMetadataExtractor实例的指针。  | 
| pixelMap | 从音频源获取的专辑封面。有关详细信息，请参阅 **OH_PixelmapNative** 。  | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL：输入extractor为空指针或者输入参数无效。

AV_ERR_OPERATE_NOT_PERMIT：操作不允许。

AV_ERR_UNSUPPORTED_FORMAT：格式不支持。

AV_ERR_NO_MEMORY：内部内存分配失败。


### OH_AVMetadataExtractor_FetchMetadata()

```
OH_AVErrCode OH_AVMetadataExtractor_FetchMetadata(OH_AVMetadataExtractor* extractor, OH_AVFormat* avMetadata)
```
**描述**
从媒体资源中获取元数据。 此函数必须在[SetFDSource](#oh_avmetadataextractor_setfdsource)之后调用。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| extractor | 指向OH_AVMetadataExtractor实例的指针。  | 
| avMetadata | 指向**OH_AVFormat**实例的指针，其内容包含获取的元数据信息。  | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL：输入extractor为空指针或者输入参数无效。

AV_ERR_OPERATE_NOT_PERMIT：操作不允许。

AV_ERR_UNSUPPORTED_FORMAT：格式不支持。

AV_ERR_NO_MEMORY：内部内存分配失败。


### OH_AVMetadataExtractor_Release()

```
OH_AVErrCode OH_AVMetadataExtractor_Release(OH_AVMetadataExtractor* extractor)
```
**描述**
释放用于OH_AVMetadataExtractor的资源以及销毁OH_AVMetadataExtractor对象。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| extractor | 指向OH_AVMetadataExtractor实例指针。  | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL：输入extractor为空指针或者输入参数无效。


### OH_AVMetadataExtractor_SetFDSource()

```
OH_AVErrCode OH_AVMetadataExtractor_SetFDSource(OH_AVMetadataExtractor* extractor, int32_t fd, int64_t offset, int64_t size)
```
**描述**
通过媒体文件描述设置数据源。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| extractor | 指向OH_AVMetadataExtractor实例的指针。  | 
| fd | 媒体源的文件描述符。  | 
| offset | 媒体源在文件描述符中的偏移量。  | 
| size | 媒体源的大小。  | 

**返回：**

函数结果代码[OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1)：

AV_ERR_OK：执行成功。

AV_ERR_INVALID_VAL：输入extractor为空指针或者输入参数无效。

AV_ERR_OPERATE_NOT_PERMIT：操作不允许。

AV_ERR_NO_MEMORY：内部内存分配失败。


## 变量说明


### OH_AVMETADATA_EXTRACTOR_ALBUM

```
static const char* OH_AVMETADATA_EXTRACTOR_ALBUM = "album"
```
**描述**
获取专辑的标题的关键字，对应值类型是const char\*。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_ALBUM_ARTIST

```
static const char* OH_AVMETADATA_EXTRACTOR_ALBUM_ARTIST = "albumArtist"
```
**描述**
获取专辑的艺术家的关键字，对应值类型是const char\*。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_ARTIST

```
static const char* OH_AVMETADATA_EXTRACTOR_ARTIST = "artist"
```
**描述**
获取媒体资源的艺术家的关键字，对应值类型是const char\*。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_AUTHOR

```
static const char* OH_AVMETADATA_EXTRACTOR_AUTHOR = "author"
```
**描述**
获取媒体资源的作者的关键字，对应值类型是const char\*。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_COMPOSER

```
static const char* OH_AVMETADATA_EXTRACTOR_COMPOSER = "composer"
```
**描述**
获取媒体资源的作曲家的关键字，对应值类型是const char\*。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_DATE_TIME

```
static const char* OH_AVMETADATA_EXTRACTOR_DATE_TIME = "dateTime"
```
**描述**
取媒体资源的创建时间的关键字，对应值类型是const char\*。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_DATE_TIME_FORMAT

```
static const char* OH_AVMETADATA_EXTRACTOR_DATE_TIME_FORMAT = "dateTimeFormat"
```
**描述**
获取媒体资源的创建时间的关键字，对应值类型是const char\*，按YYYY-MM-DD HH:mm:ss格式输出。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_DURATION

```
static const char* OH_AVMETADATA_EXTRACTOR_DURATION = "duration"
```
**描述**
获取媒体资源的时长的关键字，对应值类型是int64_t，单位为毫秒（ms）。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_GENRE

```
static const char* OH_AVMETADATA_EXTRACTOR_GENRE = "genre"
```
**描述**
获取媒体资源的类型或体裁的关键字，对应值类型是const char\*。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_HAS_AUDIO

```
static const char* OH_AVMETADATA_EXTRACTOR_HAS_AUDIO = "hasAudio"
```
**描述**
获取媒体资源是否包含音频的关键字，对应值类型是int32_t。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_HAS_VIDEO

```
static const char* OH_AVMETADATA_EXTRACTOR_HAS_VIDEO = "hasVideo"
```
**描述**
获取媒体资源是否包含视频的关键字，对应值类型是int32_t。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_LOCATION_LATITUDE

```
static const char* OH_AVMETADATA_EXTRACTOR_LOCATION_LATITUDE = "latitude"
```
**描述**
获取地理位置中的纬度值的关键字，对应值类型float。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_LOCATION_LONGITUDE

```
static const char* OH_AVMETADATA_EXTRACTOR_LOCATION_LONGITUDE = "longitude"
```
**描述**
获取地理位置中的经度值的关键字，对应值类型float。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_MIME_TYPE

```
static const char* OH_AVMETADATA_EXTRACTOR_MIME_TYPE = "mimeType"
```
**描述**
获取媒体资源的mime类型的关键字，对应值类型是const char\*，例如：“video/mp4”、“audio/mp4”和“audio/amr wb”。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_SAMPLE_RATE

```
static const char* OH_AVMETADATA_EXTRACTOR_SAMPLE_RATE = "sampleRate"
```
**描述**
获取音频的采样率的关键字，对应值类型是int32_t，单位为赫兹（Hz）。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_TITLE

```
static const char* OH_AVMETADATA_EXTRACTOR_TITLE = "title"
```
**描述**
获取媒体资源的标题的关键字，对应值类型是const char\*。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_TRACK_COUNT

```
static const char* OH_AVMETADATA_EXTRACTOR_TRACK_COUNT = "trackCount"
```
**描述**
获取媒体资源的轨道数量的关键字，对应值类型是int32_t。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_VIDEO_HEIGHT

```
static const char* OH_AVMETADATA_EXTRACTOR_VIDEO_HEIGHT = "videoHeight"
```
**描述**
获取视频的高度的关键字，对应值类型int32_t，单位为像素。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_VIDEO_IS_HDR_VIVID

```
static const char* OH_AVMETADATA_EXTRACTOR_VIDEO_IS_HDR_VIVID = "hdrType"
```
**描述**
获取是否是HDR Vivid视频的关键字，对应值类型int32_t。 详情请参阅 [OH_Core_HdrType](../apis-avcodec-kit/_core.md#oh_core_hdrtype) 定义在 [media_types.h](../apis-avcodec-kit/media__types_8h.md) 。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_VIDEO_ORIENTATION

```
static const char* OH_AVMETADATA_EXTRACTOR_VIDEO_ORIENTATION = "videoOrientation"
```
**描述**
获取视频的旋转方向的关键字，对应值类型int32_t，单位为度（°）。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18


### OH_AVMETADATA_EXTRACTOR_VIDEO_WIDTH

```
static const char* OH_AVMETADATA_EXTRACTOR_VIDEO_WIDTH = "videoWidth"
```
**描述**
获取视频的宽度的关键字，对应值类型int32_t，单位为像素。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**起始版本：** 18
