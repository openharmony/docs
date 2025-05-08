# AVMetadataExtractor


## Overview

The AVMetadataExtractor module provides the APIs for extracting metadata from media assets.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [avmetadata_extractor.h](avmetadata__extractor_8h.md) | Declares the AVMetadataExtractor APIs. With these native APIs, you can obtain metadata from media assets. |
| [avmetadata_extractor_base.h](avmetadata__extractor__base_8h.md) | Declares the constants used by the AVMetadataExtractor. |


### Types

| Name| Description|
| -------- | -------- |
| typedef struct [OH_AVMetadataExtractor](#oh_avmetadataextractor) [OH_AVMetadataExtractor](#oh_avmetadataextractor) | Defines a struct for the OH_AVMetadataExtractor. |


### Functions

| Name| Description|
| -------- | -------- |
| [OH_AVMetadataExtractor](#oh_avmetadataextractor) \* [OH_AVMetadataExtractor_Create](#oh_avmetadataextractor_create) (void) | Creates an **OH_AVMetadataExtractor** instance. |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVMetadataExtractor_SetFDSource](#oh_avmetadataextractor_setfdsource) ([OH_AVMetadataExtractor](#oh_avmetadataextractor) \*extractor, int32_t fd, int64_t offset, int64_t size) | Sets a data source based on the media file descriptor. |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVMetadataExtractor_FetchMetadata](#oh_avmetadataextractor_fetchmetadata) ([OH_AVMetadataExtractor](#oh_avmetadataextractor) \*extractor, OH_AVFormat \*avMetadata) | Obtains metadata from a media asset. This function must be called after [SetFDSource](#oh_avmetadataextractor_setfdsource).|
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVMetadataExtractor_FetchAlbumCover](#oh_avmetadataextractor_fetchalbumcover) ([OH_AVMetadataExtractor](#oh_avmetadataextractor) \*extractor, OH_PixelmapNative \*\*pixelMap) | Obtains the cover of an audio album. This function must be called after [SetFDSource](#oh_avmetadataextractor_setfdsource).|
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVMetadataExtractor_Release](#oh_avmetadataextractor_release) ([OH_AVMetadataExtractor](#oh_avmetadataextractor) \*extractor) | Releases the resources used by the **OH_AVMetadataExtractor** instance and destroys the instance. |


### Variables

| Name| Description|
| -------- | -------- |
| static const char\* [OH_AVMETADATA_EXTRACTOR_ALBUM](#oh_avmetadata_extractor_album) = "album" | Pointer to the key for obtaining the title of the album. The value type is const char\*. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_ALBUM_ARTIST](#oh_avmetadata_extractor_album_artist) = "albumArtist" | Pointer to the key for obtaining the artist of the album. The value type is const char\*. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_ARTIST](#oh_avmetadata_extractor_artist) = "artist" | Pointer to the key for obtaining the artist of the media asset. The value type is const char\*. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_AUTHOR](#oh_avmetadata_extractor_author) = "author" | Pointer to the key for obtaining the author of the media asset. The value type is const char\*. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_DATE_TIME](#oh_avmetadata_extractor_date_time) = "dateTime" | Pointer to the key for obtaining the creation time of the media asset. The value type is const char\*. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_DATE_TIME_FORMAT](#oh_avmetadata_extractor_date_time_format) = "dateTimeFormat" | Pointer to the key for obtaining the creation time of the media asset. The value type is const char\* and the output format is YYYY-MM-DD HH:mm:ss. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_COMPOSER](#oh_avmetadata_extractor_composer) = "composer" | Pointer to the key for obtaining the composer of the media asset. The value type is const char\*. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_DURATION](#oh_avmetadata_extractor_duration) = "duration" | Pointer to the key for obtaining the duration of the media asset, in ms. The value type is int64_t. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_GENRE](#oh_avmetadata_extractor_genre) = "genre" | Pointer to the key for obtaining the type or genre of the media asset. The value type is const char\*. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_HAS_AUDIO](#oh_avmetadata_extractor_has_audio) = "hasAudio" | Pointer to the key for obtaining the flag indicating whether the media asset contains audio. The value type is int32_t. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_HAS_VIDEO](#oh_avmetadata_extractor_has_video) = "hasVideo" | Pointer to the key for obtaining the flag indicating whether the media asset contains video. The value type is int32_t. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_MIME_TYPE](#oh_avmetadata_extractor_mime_type) = "mimeType" | Pointer to the key for obtaining the MIME type of the media asset. The value type is const char\*, for example, video/mp4, audio/mp4, and audio/amr wb. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_TRACK_COUNT](#oh_avmetadata_extractor_track_count) = "trackCount" | Pointer to the key for obtaining the number of tracks of the media asset. The value type is int32_t. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_SAMPLE_RATE](#oh_avmetadata_extractor_sample_rate) = "sampleRate" | Pointer to the key for obtaining the audio sampling rate, in Hz. The value type is int32_t. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_TITLE](#oh_avmetadata_extractor_title) = "title" | Pointer to the key for obtaining the title of the media asset. The value type is const char\*. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_VIDEO_HEIGHT](#oh_avmetadata_extractor_video_height) = "videoHeight" | Pointer to the key for obtaining the video height, in px. The value type is int32_t. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_VIDEO_WIDTH](#oh_avmetadata_extractor_video_width) = "videoWidth" | Pointer to the key for obtaining the video weight, in px. The value type is int32_t. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_VIDEO_ORIENTATION](#oh_avmetadata_extractor_video_orientation) = "videoOrientation" | Pointer to the key for obtaining the video rotation direction, in degrees (°). The value type is int32_t. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_VIDEO_IS_HDR_VIVID](#oh_avmetadata_extractor_video_is_hdr_vivid) = "hdrType" | Pointer to the key for obtaining the flag indicating whether the video is an HDR Vivid video. The value type is int32_t. For details, see the definition of [OH_Core_HdrType](../apis-avcodec-kit/_core.md#oh_core_hdrtype) in [media_types.h](../apis-avcodec-kit/media__types_8h.md). |
| static const char\* [OH_AVMETADATA_EXTRACTOR_LOCATION_LATITUDE](#oh_avmetadata_extractor_location_latitude) = "latitude" | Pointer to the key for obtaining the latitude in the geographical location. The value type is float. |
| static const char\* [OH_AVMETADATA_EXTRACTOR_LOCATION_LONGITUDE](#oh_avmetadata_extractor_location_longitude) = "longitude" | Pointer to the key for obtaining the longitude in the geographical location. The value type is float. |


## Type Description


### OH_AVMetadataExtractor

```
typedef struct OH_AVMetadataExtractor OH_AVMetadataExtractor
```
**Description**

Defines a struct for the OH_AVMetadataExtractor.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


## Function Description


### OH_AVMetadataExtractor_Create()

```
OH_AVMetadataExtractor* OH_AVMetadataExtractor_Create(void)
```
**Description**

Creates an **OH_AVMetadataExtractor** instance.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18

**Returns**

Returns the pointer to the **OH_AVMetadataExtractor** instance created if the operation is successful; returns a null pointer otherwise.

Possible cause of failures: **HstEngineFactory::CreateAVMetadataHelperEngine** fails to run.


### OH_AVMetadataExtractor_FetchAlbumCover()

```
OH_AVErrCode OH_AVMetadataExtractor_FetchAlbumCover(OH_AVMetadataExtractor* extractor, OH_PixelmapNative** pixelMap)
```
**Description**

Obtains the cover of an audio album. This function must be called after [SetFDSource](#oh_avmetadataextractor_setfdsource).

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| extractor | Pointer to an **OH_AVMetadataExtractor** instance. |
| pixelMap | Double pointer to the album cover obtained. For details, see **OH_PixelmapNative**. |

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **extractor** is a null pointer or an input parameter is invalid.

**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.

**AV_ERR_UNSUPPORTED_FORMAT**: The format is not supported.

**AV_ERR_NO_MEMORY**: Internal memory allocation failed.


### OH_AVMetadataExtractor_FetchMetadata()

```
OH_AVErrCode OH_AVMetadataExtractor_FetchMetadata(OH_AVMetadataExtractor* extractor, OH_AVFormat* avMetadata)
```
**Description**

Obtains metadata from a media asset. This function must be called after [SetFDSource](#oh_avmetadataextractor_setfdsource).

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| extractor | Pointer to an **OH_AVMetadataExtractor** instance. |
| avMetadata | Pointer to an **OH_AVFormat** instance, which contains the obtained metadata. |

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **extractor** is a null pointer or an input parameter is invalid.

**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.

**AV_ERR_UNSUPPORTED_FORMAT**: The format is not supported.

**AV_ERR_NO_MEMORY**: Internal memory allocation failed.


### OH_AVMetadataExtractor_Release()

```
OH_AVErrCode OH_AVMetadataExtractor_Release(OH_AVMetadataExtractor* extractor)
```
**Description**

Releases the resources used by the **OH_AVMetadataExtractor** instance and destroys the instance.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| extractor | Pointer to an **OH_AVMetadataExtractor** instance. |

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **extractor** is a null pointer or an input parameter is invalid.


### OH_AVMetadataExtractor_SetFDSource()

```
OH_AVErrCode OH_AVMetadataExtractor_SetFDSource(OH_AVMetadataExtractor* extractor, int32_t fd, int64_t offset, int64_t size)
```
**Description**

Sets a data source based on the media file descriptor.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| extractor | Pointer to an **OH_AVMetadataExtractor** instance. |
| fd | File descriptor of the media source. |
| offset | Offset of the media source in the file descriptor. |
| size | Size of the media source. |

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **extractor** is a null pointer or an input parameter is invalid.

**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.

**AV_ERR_NO_MEMORY**: Internal memory allocation failed.


## Variable Description


### OH_AVMETADATA_EXTRACTOR_ALBUM

```
static const char* OH_AVMETADATA_EXTRACTOR_ALBUM = "album"
```
**Description**

Pointer to the key for obtaining the title of the album. The value type is const char\*.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_ALBUM_ARTIST

```
static const char* OH_AVMETADATA_EXTRACTOR_ALBUM_ARTIST = "albumArtist"
```
**Description**

Pointer to the key for obtaining the artist of the album. The value type is const char\*.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_ARTIST

```
static const char* OH_AVMETADATA_EXTRACTOR_ARTIST = "artist"
```
**Description**

Pointer to the key for obtaining the artist of the media asset. The value type is const char\*.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_AUTHOR

```
static const char* OH_AVMETADATA_EXTRACTOR_AUTHOR = "author"
```
**Description**

Pointer to the key for obtaining the author of the media asset. The value type is const char\*.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_COMPOSER

```
static const char* OH_AVMETADATA_EXTRACTOR_COMPOSER = "composer"
```
**Description**

Pointer to the key for obtaining the composer of the media asset. The value type is const char\*.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_DATE_TIME

```
static const char* OH_AVMETADATA_EXTRACTOR_DATE_TIME = "dateTime"
```
**Description**

Pointer to the key for obtaining the creation time of the media asset. The value type is const char\*.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_DATE_TIME_FORMAT

```
static const char* OH_AVMETADATA_EXTRACTOR_DATE_TIME_FORMAT = "dateTimeFormat"
```
**Description**

Pointer to the key for obtaining the creation time of the media asset. The value type is const char\* and the output format is YYYY-MM-DD HH:mm:ss.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_DURATION

```
static const char* OH_AVMETADATA_EXTRACTOR_DURATION = "duration"
```
**Description**

Pointer to the key for obtaining the duration of the media asset, in ms. The value type is int64_t.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_GENRE

```
static const char* OH_AVMETADATA_EXTRACTOR_GENRE = "genre"
```
**Description**

Pointer to the key for obtaining the type or genre of the media asset. The value type is const char\*.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_HAS_AUDIO

```
static const char* OH_AVMETADATA_EXTRACTOR_HAS_AUDIO = "hasAudio"
```
**Description**

Pointer to the key for obtaining the flag indicating whether the media asset contains audio. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_HAS_VIDEO

```
static const char* OH_AVMETADATA_EXTRACTOR_HAS_VIDEO = "hasVideo"
```
**Description**

Pointer to the key for obtaining the flag indicating whether the media asset contains video. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_LOCATION_LATITUDE

```
static const char* OH_AVMETADATA_EXTRACTOR_LOCATION_LATITUDE = "latitude"
```
**Description**

Pointer to the key for obtaining the latitude in the geographical location. The value type is float.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_LOCATION_LONGITUDE

```
static const char* OH_AVMETADATA_EXTRACTOR_LOCATION_LONGITUDE = "longitude"
```
**Description**

Pointer to the key for obtaining the longitude in the geographical location. The value type is float.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_MIME_TYPE

```
static const char* OH_AVMETADATA_EXTRACTOR_MIME_TYPE = "mimeType"
```
**Description**

Pointer to the key for obtaining the MIME type of the media asset. The value type is const char\*, for example, video/mp4, audio/mp4, and audio/amr wb.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_SAMPLE_RATE

```
static const char* OH_AVMETADATA_EXTRACTOR_SAMPLE_RATE = "sampleRate"
```
**Description**

Pointer to the key for obtaining the audio sampling rate, in Hz. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_TITLE

```
static const char* OH_AVMETADATA_EXTRACTOR_TITLE = "title"
```
**Description**

Pointer to the key for obtaining the title of the media asset. The value type is const char\*.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_TRACK_COUNT

```
static const char* OH_AVMETADATA_EXTRACTOR_TRACK_COUNT = "trackCount"
```
**Description**

Pointer to the key for obtaining the number of tracks of the media asset. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_VIDEO_HEIGHT

```
static const char* OH_AVMETADATA_EXTRACTOR_VIDEO_HEIGHT = "videoHeight"
```
**Description**

Pointer to the key for obtaining the video height, in px. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_VIDEO_IS_HDR_VIVID

```
static const char* OH_AVMETADATA_EXTRACTOR_VIDEO_IS_HDR_VIVID = "hdrType"
```
**Description**

Pointer to the key for obtaining the flag indicating whether the video is an HDR Vivid video. The value type is int32_t. For details, see the definition of [OH_Core_HdrType](../apis-avcodec-kit/_core.md#oh_core_hdrtype) in [media_types.h](../apis-avcodec-kit/media__types_8h.md).

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_VIDEO_ORIENTATION

```
static const char* OH_AVMETADATA_EXTRACTOR_VIDEO_ORIENTATION = "videoOrientation"
```
**Description**

Pointer to the key for obtaining the video rotation direction, in degrees (°). The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


### OH_AVMETADATA_EXTRACTOR_VIDEO_WIDTH

```
static const char* OH_AVMETADATA_EXTRACTOR_VIDEO_WIDTH = "videoWidth"
```
**Description**

Pointer to the key for obtaining the video weight, in px. The value type is int32_t.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18
