# avmetadata_extractor_base.h


## 概述

定义AVMetadataExtractor的常量。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**库：** libavmetadata_extractor.so

**起始版本：** 18

**相关模块：**[AVMetadataExtractor](_a_v_metadata_extractor.md)


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| static const char\* [OH_AVMETADATA_EXTRACTOR_ALBUM](_a_v_metadata_extractor.md#oh_avmetadata_extractor_album) = "album" | 获取专辑的标题的关键字，对应值类型是const char\*。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_ALBUM_ARTIST](_a_v_metadata_extractor.md#oh_avmetadata_extractor_album_artist) = "albumArtist" | 获取专辑的艺术家的关键字，对应值类型是const char\*。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_ARTIST](_a_v_metadata_extractor.md#oh_avmetadata_extractor_artist) = "artist" | 获取媒体资源的艺术家的关键字，对应值类型是const char\*。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_AUTHOR](_a_v_metadata_extractor.md#oh_avmetadata_extractor_author) = "author" | 获取媒体资源的作者的关键字，对应值类型是const char\*。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_DATE_TIME](_a_v_metadata_extractor.md#oh_avmetadata_extractor_date_time) = "dateTime" | 取媒体资源的创建时间的关键字，对应值类型是const char\*。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_DATE_TIME_FORMAT](_a_v_metadata_extractor.md#oh_avmetadata_extractor_date_time_format) = "dateTimeFormat" | 获取媒体资源的创建时间的关键字，对应值类型是const char\*，按YYYY-MM-DD HH:mm:ss格式输出。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_COMPOSER](_a_v_metadata_extractor.md#oh_avmetadata_extractor_composer) = "composer" | 获取媒体资源的作曲家的关键字，对应值类型是const char\*。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_DURATION](_a_v_metadata_extractor.md#oh_avmetadata_extractor_duration) = "duration" | 获取媒体资源的时长的关键字，对应值类型是int64_t，单位为毫秒（ms）。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_GENRE](_a_v_metadata_extractor.md#oh_avmetadata_extractor_genre) = "genre" | 获取媒体资源的类型或体裁的关键字，对应值类型是const char\*。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_HAS_AUDIO](_a_v_metadata_extractor.md#oh_avmetadata_extractor_has_audio) = "hasAudio" | 获取媒体资源是否包含音频的关键字，对应值类型是int32_t。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_HAS_VIDEO](_a_v_metadata_extractor.md#oh_avmetadata_extractor_has_video) = "hasVideo" | 获取媒体资源是否包含视频的关键字，对应值类型是int32_t。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_MIME_TYPE](_a_v_metadata_extractor.md#oh_avmetadata_extractor_mime_type) = "mimeType" | 获取媒体资源的mime类型的关键字，对应值类型是const char\*，例如：“video/mp4”、“audio/mp4”和“audio/amr wb”。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_TRACK_COUNT](_a_v_metadata_extractor.md#oh_avmetadata_extractor_track_count) = "trackCount" | 获取媒体资源的轨道数量的关键字，对应值类型是int32_t。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_SAMPLE_RATE](_a_v_metadata_extractor.md#oh_avmetadata_extractor_sample_rate) = "sampleRate" | 获取音频的采样率的关键字，对应值类型是int32_t，单位为赫兹（Hz）。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_TITLE](_a_v_metadata_extractor.md#oh_avmetadata_extractor_title) = "title" | 获取媒体资源的标题的关键字，对应值类型是const char\*。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_VIDEO_HEIGHT](_a_v_metadata_extractor.md#oh_avmetadata_extractor_video_height) = "videoHeight" | 获取视频的高度的关键字，对应值类型int32_t，单位为像素。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_VIDEO_WIDTH](_a_v_metadata_extractor.md#oh_avmetadata_extractor_video_width) = "videoWidth" | 获取视频的宽度的关键字，对应值类型int32_t，单位为像素。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_VIDEO_ORIENTATION](_a_v_metadata_extractor.md#oh_avmetadata_extractor_video_orientation) = "videoOrientation" | 获取视频的旋转方向的关键字，对应值类型int32_t，单位为度（°）。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_VIDEO_IS_HDR_VIVID](_a_v_metadata_extractor.md#oh_avmetadata_extractor_video_is_hdr_vivid) = "hdrType" | 获取是否是HDR Vivid视频的关键字，对应值类型int32_t。 详情请参阅 [OH_Core_HdrType](../apis-avcodec-kit/_core.md#oh_core_hdrtype) 定义在 [media_types.h](../apis-avcodec-kit/media__types_8h.md) 。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_LOCATION_LATITUDE](_a_v_metadata_extractor.md#oh_avmetadata_extractor_location_latitude) = "latitude" | 获取地理位置中的纬度值的关键字，对应值类型float。  | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_LOCATION_LONGITUDE](_a_v_metadata_extractor.md#oh_avmetadata_extractor_location_longitude) = "longitude" | 获取地理位置中的经度值的关键字，对应值类型float。  | 
