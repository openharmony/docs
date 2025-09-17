# native_avmetadata.h
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the definitions of playback control metadata.

**File to include**: <multimedia/av_session/native_avmetadata.h>

**Library**: libohavsession.so

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Since**: 13

**Related module**: [OHAVSession](capi-ohavsession.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVMetadataBuilderStruct](capi-ohavsession-oh-avmetadatabuilderstruct.md) | OH_AVMetadataBuilder | Defines a struct for the session metadata builder. The builder is used to construct session metadata.|
| [OH_AVMetadataStruct](capi-ohavsession-oh-avmetadatastruct.md) | OH_AVMetadata | Defines a struct for the session metadata. It is an AVMetadata instance set for a media asset.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [AVMetadata_Result](#avmetadata_result) | AVMetadata_Result | Enumerates the error codes related to metadata operations.|
| [AVMetadata_SkipIntervals](#avmetadata_skipintervals) | AVMetadata_SkipIntervals | Enumerates the fast-forward or rewind intervals supported by the media session.|
| [AVMetadata_DisplayTag](#avmetadata_displaytag) | AVMetadata_DisplayTag | Enumerates the display tags of the media asset. The display tag is a special type identifier of the media audio source.|

### Functions

| Name| Description|
| -- | -- |
| [AVMetadata_Result OH_AVMetadataBuilder_Create(OH_AVMetadataBuilder** builder)](#oh_avmetadatabuilder_create) | Creates a metadata builder.|
| [AVMetadata_Result OH_AVMetadataBuilder_Destroy(OH_AVMetadataBuilder* builder)](#oh_avmetadatabuilder_destroy) | Destroys a metadata builder.|
| [AVMetadata_Result OH_AVMetadataBuilder_SetAssetId(OH_AVMetadataBuilder* builder, const char* assetId)](#oh_avmetadatabuilder_setassetid) | Sets the ID of the media asset.|
| [AVMetadata_Result OH_AVMetadataBuilder_SetTitle(OH_AVMetadataBuilder* builder, const char* title)](#oh_avmetadatabuilder_settitle) | Sets a title for the media asset.|
| [AVMetadata_Result OH_AVMetadataBuilder_SetArtist(OH_AVMetadataBuilder* builder, const char* artist)](#oh_avmetadatabuilder_setartist) | Sets an artist for the media asset.|
| [AVMetadata_Result OH_AVMetadataBuilder_SetAuthor(OH_AVMetadataBuilder* builder, const char* author)](#oh_avmetadatabuilder_setauthor) | Sets an author for the media asset.|
| [AVMetadata_Result OH_AVMetadataBuilder_SetAlbum(OH_AVMetadataBuilder* builder, const char* album)](#oh_avmetadatabuilder_setalbum) | Sets an album name for the media asset.|
| [AVMetadata_Result OH_AVMetadataBuilder_SetWriter(OH_AVMetadataBuilder* builder, const char* writer)](#oh_avmetadatabuilder_setwriter) | Sets a writer for the media asset.|
| [AVMetadata_Result OH_AVMetadataBuilder_SetComposer(OH_AVMetadataBuilder* builder, const char* composer)](#oh_avmetadatabuilder_setcomposer) | Sets a composer for the media asset.|
| [AVMetadata_Result OH_AVMetadataBuilder_SetDuration(OH_AVMetadataBuilder* builder, int64_t duration)](#oh_avmetadatabuilder_setduration) | Sets the playback duration for the media asset.|
| [AVMetadata_Result OH_AVMetadataBuilder_SetMediaImageUri(OH_AVMetadataBuilder* builder, const char* mediaImageUri)](#oh_avmetadatabuilder_setmediaimageuri) | Sets an image for the media asset.|
| [AVMetadata_Result OH_AVMetadataBuilder_SetSubtitle(OH_AVMetadataBuilder* builder, const char* subtitle)](#oh_avmetadatabuilder_setsubtitle) | Sets a subtitle for the media asset.|
| [AVMetadata_Result OH_AVMetadataBuilder_SetDescription(OH_AVMetadataBuilder* builder, const char* description)](#oh_avmetadatabuilder_setdescription) | Sets a description for the media asset.|
| [AVMetadata_Result OH_AVMetadataBuilder_SetLyric(OH_AVMetadataBuilder* builder, const char* lyric)](#oh_avmetadatabuilder_setlyric) | Sets lyrics for the media asset.|
| [AVMetadata_Result OH_AVMetadataBuilder_SetSkipIntervals(OH_AVMetadataBuilder* builder, AVMetadata_SkipIntervals intervals)](#oh_avmetadatabuilder_setskipintervals) | Sets the skip intervals for the media asset.|
| [AVMetadata_Result OH_AVMetadataBuilder_SetDisplayTags(OH_AVMetadataBuilder* builder, int32_t tags)](#oh_avmetadatabuilder_setdisplaytags) | Sets display tags for the media asset.|
| [AVMetadata_Result OH_AVMetadataBuilder_GenerateAVMetadata(OH_AVMetadataBuilder* builder, OH_AVMetadata** avMetadata)](#oh_avmetadatabuilder_generateavmetadata) | Generates an OH_AVMetadata object.|
| [AVMetadata_Result OH_AVMetadata_Destroy(OH_AVMetadata* avMetadata)](#oh_avmetadata_destroy) | Releases an OH_AVMetadata object.|

## Enums

### AVMetadata_Result

```
enum AVMetadata_Result
```

**Description**

Enumerates the error codes related to metadata operations.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| AVMETADATA_SUCCESS = 0 | Operation successful.|
| AVMETADATA_ERROR_INVALID_PARAM = 1 | Incorrect parameter.|
| AVMETADATA_ERROR_NO_MEMORY = 2 | Insufficient memory.|

### AVMetadata_SkipIntervals

```
enum AVMetadata_SkipIntervals
```

**Description**

Enumerates the fast-forward or rewind intervals supported by the media session.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| SECONDS_10 = 10 | The time is 10 seconds.|
| SECONDS_15 = 15 | The time is 15 seconds.|
| SECONDS_30 = 30 | The time is 30 seconds.|

### AVMetadata_DisplayTag

```
enum AVMetadata_DisplayTag
```

**Description**

Enumerates the display tags of the media asset. The display tag is a special type identifier of the media audio source.

**Since**: 13

| Enum Item| Description|
| -- | -- |
| AVSESSION_DISPLAYTAG_AUDIO_VIVID = 1 | AUDIO VIVID.|


## Function Description

### OH_AVMetadataBuilder_Create()

```
AVMetadata_Result OH_AVMetadataBuilder_Create(OH_AVMetadataBuilder** builder)
```

**Description**

Creates a metadata builder.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)** builder |  Double pointer to the builder created.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_INVALID_PARAM**: **builder** is nullptr.<br> **AVMETADATA_ERROR_NO_MEMORY**: There is no sufficient memory.|

### OH_AVMetadataBuilder_Destroy()

```
AVMetadata_Result OH_AVMetadataBuilder_Destroy(OH_AVMetadataBuilder* builder)
```

**Description**

Destroys a metadata builder.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | Pointer to an OH_AVMetadataBuilder instance.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_INVALID_PARAM**: **builder** is nullptr.|

### OH_AVMetadataBuilder_SetAssetId()

```
AVMetadata_Result OH_AVMetadataBuilder_SetAssetId(OH_AVMetadataBuilder* builder, const char* assetId)
```

**Description**

Sets the ID of the media asset.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | Pointer to an OH_AVMetadataBuilder instance.|
| const char* assetId | Pointer to the asset ID.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_INVALID_PARAM**:<br>                               1. **builder** is nullptr.<br>                               2. **assetId** is nullptr.|

### OH_AVMetadataBuilder_SetTitle()

```
AVMetadata_Result OH_AVMetadataBuilder_SetTitle(OH_AVMetadataBuilder* builder, const char* title)
```

**Description**

Sets a title for the media asset.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | Pointer to an OH_AVMetadataBuilder instance.|
| const char* title | Pointer to the title.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_INVALID_PARAM**:<br>                                1. **builder** is nullptr.<br>                                2. **title** is nullptr.|

### OH_AVMetadataBuilder_SetArtist()

```
AVMetadata_Result OH_AVMetadataBuilder_SetArtist(OH_AVMetadataBuilder* builder, const char* artist)
```

**Description**

Sets an artist for the media asset.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | Pointer to an OH_AVMetadataBuilder instance.|
| const char* artist | Pointer to the artist.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_INVALID_PARAM**:<br>                                1. **builder** is nullptr.<br>                                2. **artist** is nullptr.|

### OH_AVMetadataBuilder_SetAuthor()

```
AVMetadata_Result OH_AVMetadataBuilder_SetAuthor(OH_AVMetadataBuilder* builder, const char* author)
```

**Description**

Sets an author for the media asset.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | Pointer to an OH_AVMetadataBuilder instance.|
| const char* author | Pointer to the author.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_INVALID_PARAM**:<br>                                1. **builder** is nullptr.<br>                                2. **author** is nullptr.|

### OH_AVMetadataBuilder_SetAlbum()

```
AVMetadata_Result OH_AVMetadataBuilder_SetAlbum(OH_AVMetadataBuilder* builder, const char* album)
```

**Description**

Sets an album name for the media asset.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | Pointer to an OH_AVMetadataBuilder instance.|
| const char* album | Pointer to the album name.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_INVALID_PARAM**:<br>                                1. **builder** is nullptr.<br>                                2. **album** is nullptr.|

### OH_AVMetadataBuilder_SetWriter()

```
AVMetadata_Result OH_AVMetadataBuilder_SetWriter(OH_AVMetadataBuilder* builder, const char* writer)
```

**Description**

Sets a writer for the media asset.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | Pointer to an OH_AVMetadataBuilder instance.|
| const char* writer | Pointer to the writer.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_INVALID_PARAM**:<br>                                1. **builder** is nullptr.<br>                                2. **writer** is nullptr.|

### OH_AVMetadataBuilder_SetComposer()

```
AVMetadata_Result OH_AVMetadataBuilder_SetComposer(OH_AVMetadataBuilder* builder, const char* composer)
```

**Description**

Sets a composer for the media asset.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | Pointer to an OH_AVMetadataBuilder instance.|
| const char* composer | Pointer to the composer.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_INVALID_PARAM**:<br>                                1. **builder** is nullptr.<br>                                2. **composer** is nullptr.|

### OH_AVMetadataBuilder_SetDuration()

```
AVMetadata_Result OH_AVMetadataBuilder_SetDuration(OH_AVMetadataBuilder* builder, int64_t duration)
```

**Description**

Sets the playback duration for the media asset.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | Pointer to an OH_AVMetadataBuilder instance.|
| int64_t duration | Playback duration, in ms.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_INVALID_PARAM**: **builder** is nullptr.|

### OH_AVMetadataBuilder_SetMediaImageUri()

```
AVMetadata_Result OH_AVMetadataBuilder_SetMediaImageUri(OH_AVMetadataBuilder* builder, const char* mediaImageUri)
```

**Description**

Sets an image for the media asset.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | Pointer to an OH_AVMetadataBuilder instance.|
| const char* mediaImageUri | Pointer to the URI of the image.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_INVALID_PARAM**:<br>                                1. **builder** is nullptr.<br>                                2. **mediaImageUri** is nullptr.|

### OH_AVMetadataBuilder_SetSubtitle()

```
AVMetadata_Result OH_AVMetadataBuilder_SetSubtitle(OH_AVMetadataBuilder* builder, const char* subtitle)
```

**Description**

Sets a subtitle for the media asset.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | Pointer to an OH_AVMetadataBuilder instance.|
| const char* subtitle | Pointer to the subtitle.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_INVALID_PARAM**:<br>                                1. **builder** is nullptr.<br>                                2. **subtitle** is nullptr.|

### OH_AVMetadataBuilder_SetDescription()

```
AVMetadata_Result OH_AVMetadataBuilder_SetDescription(OH_AVMetadataBuilder* builder, const char* description)
```

**Description**

Sets a description for the media asset.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | Pointer to an OH_AVMetadataBuilder instance.|
| const char* description | Pointer to the description.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_INVALID_PARAM**:<br>                                1. **builder** is nullptr.<br>                                2. **description** is nullptr.|

### OH_AVMetadataBuilder_SetLyric()

```
AVMetadata_Result OH_AVMetadataBuilder_SetLyric(OH_AVMetadataBuilder* builder, const char* lyric)
```

**Description**

Sets lyrics for the media asset.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | Pointer to an OH_AVMetadataBuilder instance.|
| const char* lyric | Pointer to the lyrics in the lrc format.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_INVALID_PARAM**:<br>                                1. **builder** is nullptr.<br>                                2. **lyric** is nullptr.|

### OH_AVMetadataBuilder_SetSkipIntervals()

```
AVMetadata_Result OH_AVMetadataBuilder_SetSkipIntervals(OH_AVMetadataBuilder* builder,AVMetadata_SkipIntervals intervals)
```

**Description**

Sets the skip intervals for the media asset.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | Pointer to an OH_AVMetadataBuilder instance.|
| [AVMetadata_SkipIntervals](capi-native-avmetadata-h.md#avmetadata_skipintervals) intervals | Skip intervals.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_INVALID_PARAM**:<br>                                1. **builder** is nullptr.<br>                                2. **intervals** is invalid.|

### OH_AVMetadataBuilder_SetDisplayTags()

```
AVMetadata_Result OH_AVMetadataBuilder_SetDisplayTags(OH_AVMetadataBuilder* builder, int32_t tags)
```

**Description**

Sets display tags for the media asset.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | Pointer to an OH_AVMetadataBuilder instance.|
| int32_t tags | Tags of the media asset displayed on the playback control page.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_INVALID_PARAM**: **builder** is nullptr.|

### OH_AVMetadataBuilder_GenerateAVMetadata()

```
AVMetadata_Result OH_AVMetadataBuilder_GenerateAVMetadata(OH_AVMetadataBuilder* builder,OH_AVMetadata** avMetadata)
```

**Description**

Generates an OH_AVMetadata object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadataBuilder](capi-ohavsession-oh-avmetadatabuilderstruct.md)* builder | Pointer to an OH_AVMetadataBuilder instance.|
| [OH_AVMetadata](capi-ohavsession-oh-avmetadatastruct.md)** avMetadata | Double pointer to the OH_AVMetadata object created.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_NO_MEMORY**: The memory is insufficient.<br> **AVMETADATA_ERROR_INVALID_PARAM**:<br>                                1. **builder** is nullptr.<br>                                2. **avMetadata** is nullptr.|

### OH_AVMetadata_Destroy()

```
AVMetadata_Result OH_AVMetadata_Destroy(OH_AVMetadata* avMetadata)
```

**Description**

Releases an OH_AVMetadata object.

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMetadata](capi-ohavsession-oh-avmetadatastruct.md)* avMetadata | Pointer to an OH_AVMetadata object.|

**Returns**

| Type| Description|
| -- | -- |
| [AVMetadata_Result](capi-native-avmetadata-h.md#avmetadata_result) | **AVMETADATA_SUCCESS**: The function is executed successfully.<br> **AVMETADATA_ERROR_INVALID_PARAM**: **avMetadata** is nullptr.|
