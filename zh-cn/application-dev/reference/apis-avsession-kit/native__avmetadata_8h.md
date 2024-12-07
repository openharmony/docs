# native_avmetadata.h


## 概述

提供播控元数据的定义。

**库：** libohavsession.so

**引用文件：** &lt;multimedia/av_session/native_avmetadata.h&gt;

**系统能力：** SystemCapability.Multimedia.AVSession.Core

**起始版本：** 13

**相关模块：**[OHAVSession](_o_h_a_v_session.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct OH_AVMetadataBuilderStruct [OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) | 会话元数据构造器。 构造器用于构造会话元数据。 | 
| typedef struct OH_AVMetadataStruct [OH_AVMetadata](_o_h_a_v_session.md#oh_avmetadata) | 会话元数据。 资源设置的avmetadata的实例。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) {<br/>AVMETADATA_SUCCESS = 0,<br/>AVMETADATA_ERROR_INVALID_PARAM = 1,<br/>AVMETADATA_ERROR_NO_MEMORY = 2 } | 元数据操作的错误码。 | 
| [AVMetadata_SkipIntervals](_o_h_a_v_session.md#avmetadata_skipintervals) {<br/>SECONDS_10 = 10,<br/>SECONDS_15 = 15,<br/>SECONDS_30 = 30 } | 表示session支持的快进快退时间间隔。 | 
| [AVMetadata_DisplayTag](_o_h_a_v_session.md#avmetadata_displaytag) { AVSESSION_DISPLAYTAG_AUDIO_VIVID = 1 } | 应用媒体音源的特殊类型标识。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_Create](_o_h_a_v_session.md#oh_avmetadatabuilder_create) ([OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) \*\*builder) | 创建一个元数据构造器。 | 
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_Destroy](_o_h_a_v_session.md#oh_avmetadatabuilder_destroy) ([OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder) | 销毁元数据构造器。 | 
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetAssetId](_o_h_a_v_session.md#oh_avmetadatabuilder_setassetid) ([OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*assetId) | 设置当前媒体资源id。 | 
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetTitle](_o_h_a_v_session.md#oh_avmetadatabuilder_settitle) ([OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*title) | 设置资源标题。 | 
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetArtist](_o_h_a_v_session.md#oh_avmetadatabuilder_setartist) ([OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*artist) | 设置资源所属的艺术家。 | 
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetAuthor](_o_h_a_v_session.md#oh_avmetadatabuilder_setauthor) ([OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*author) | 设置资源的作者。 | 
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetAlbum](_o_h_a_v_session.md#oh_avmetadatabuilder_setalbum) ([OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*album) | 设置资源专辑名称。 | 
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetWriter](_o_h_a_v_session.md#oh_avmetadatabuilder_setwriter) ([OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*writer) | 设置资源词作者。 | 
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetComposer](_o_h_a_v_session.md#oh_avmetadatabuilder_setcomposer) ([OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*composer) | 设置资源作曲者。 | 
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetDuration](_o_h_a_v_session.md#oh_avmetadatabuilder_setduration) ([OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, int64_t duration) | 设置资源播放时长。 | 
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetMediaImageUri](_o_h_a_v_session.md#oh_avmetadatabuilder_setmediaimageuri) ([OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*mediaImageUri) | 设置媒体图片数据。 | 
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetSubtitle](_o_h_a_v_session.md#oh_avmetadatabuilder_setsubtitle) ([OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*subtitle) | 设置副标题。 | 
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetDescription](_o_h_a_v_session.md#oh_avmetadatabuilder_setdescription) ([OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*description) | 设置媒体描述信息。 | 
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetLyric](_o_h_a_v_session.md#oh_avmetadatabuilder_setlyric) ([OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*lyric) | 设置歌词。 | 
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetSkipIntervals](_o_h_a_v_session.md#oh_avmetadatabuilder_setskipintervals) ([OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, [AVMetadata_SkipIntervals](_o_h_a_v_session.md#avmetadata_skipintervals) intervals) | 设置资源的跳转的间隔时间。 | 
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetDisplayTags](_o_h_a_v_session.md#oh_avmetadatabuilder_setdisplaytags) ([OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, int32_t tags) | 设置媒体资源的金标类型。 | 
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_GenerateAVMetadata](_o_h_a_v_session.md#oh_avmetadatabuilder_generateavmetadata) ([OH_AVMetadataBuilder](_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, [OH_AVMetadata](_o_h_a_v_session.md#oh_avmetadata) \*\*avMetadata) | 生成媒体元数据对象。 | 
| [AVMetadata_Result](_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadata_Destroy](_o_h_a_v_session.md#oh_avmetadata_destroy) ([OH_AVMetadata](_o_h_a_v_session.md#oh_avmetadata) \*avMetadata) | 释放媒体元数据对象。 | 
