# avmetadata_extractor.h


## 概述

定义AVMetadataExtractor接口。使用AVMetadataExtractor提供的Native API从媒体资源中获取元数据。

**系统能力：** SystemCapability.Multimedia.Media.AVMetadataExtractor

**库：** libavmetadata_extractor.so

**起始版本：** 18

**相关模块：**[AVMetadataExtractor](_a_v_metadata_extractor.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AVMetadataExtractor](_a_v_metadata_extractor.md#oh_avmetadataextractor) [OH_AVMetadataExtractor](_a_v_metadata_extractor.md#oh_avmetadataextractor) | 定义OH_AVMetadataExtractor类型。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVMetadataExtractor](_a_v_metadata_extractor.md#oh_avmetadataextractor) \* [OH_AVMetadataExtractor_Create](_a_v_metadata_extractor.md#oh_avmetadataextractor_create) (void) | 创建OH_AVMetadataExtractor实例。  | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVMetadataExtractor_SetFDSource](_a_v_metadata_extractor.md#oh_avmetadataextractor_setfdsource) ([OH_AVMetadataExtractor](_a_v_metadata_extractor.md#oh_avmetadataextractor) \*extractor, int32_t fd, int64_t offset, int64_t size) | 通过媒体文件描述设置数据源。  | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVMetadataExtractor_FetchMetadata](_a_v_metadata_extractor.md#oh_avmetadataextractor_fetchmetadata) ([OH_AVMetadataExtractor](_a_v_metadata_extractor.md#oh_avmetadataextractor) \*extractor, OH_AVFormat \*avMetadata) | 从媒体资源中获取元数据。 此函数必须在[SetFDSource](_a_v_metadata_extractor.md#oh_avmetadataextractor_setfdsource)之后调用。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVMetadataExtractor_FetchAlbumCover](_a_v_metadata_extractor.md#oh_avmetadataextractor_fetchalbumcover) ([OH_AVMetadataExtractor](_a_v_metadata_extractor.md#oh_avmetadataextractor) \*extractor, OH_PixelmapNative \*\*pixelMap) | 获取音频专辑封面。 此函数必须在[SetFDSource](_a_v_metadata_extractor.md#oh_avmetadataextractor_setfdsource)之后调用。 | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVMetadataExtractor_Release](_a_v_metadata_extractor.md#oh_avmetadataextractor_release) ([OH_AVMetadataExtractor](_a_v_metadata_extractor.md#oh_avmetadataextractor) \*extractor) | 释放用于OH_AVMetadataExtractor的资源以及销毁OH_AVMetadataExtractor对象。  | 
