# avmetadata_extractor_base.h

## Overview

The **avmetadata_extractor_base.h** file declares the constants used by the AVMetadataExtractor.

**Library**: libavmetadata_extractor.so

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18

**Related module**: [AVMetadataExtractor](capi-avmetadataextractor.md)

## Summary

### Variables

| Name| Description|
| -- | -- |
| static const char* OH_AVMETADATA_EXTRACTOR_ALBUM = "album" | Pointer to the key for obtaining the title of the album. The value type is const char*.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_ALBUM_ARTIST = "albumArtist" | Pointer to the key for obtaining the artist of the album. The value type is const char*.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_ARTIST = "artist" | Pointer to the key for obtaining the artist of the media asset. The value type is const char*.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_AUTHOR = "author" | Pointer to the key for obtaining the author of the media asset. The value type is const char*.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_DATE_TIME = "dateTime" | Pointer to the key for obtaining the creation time of the media asset. The value type is const char*.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_DATE_TIME_FORMAT = "dateTimeFormat" | Pointer to the key for obtaining the creation time of the media asset. The value type is const char* and the output format is YYYY-MM-DD HH:mm:ss.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_COMPOSER = "composer" | Pointer to the key for obtaining the composer of the media asset. The value type is const char*.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_DURATION = "duration" | Pointer to the key for obtaining the duration of the media asset, in ms. The value type is int64_t.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_GENRE = "genre" | Pointer to the key for obtaining the type or genre of the media asset. The value type is const char*.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_HAS_AUDIO = "hasAudio" | Pointer to the key for obtaining the flag indicating whether the media asset contains audio. The value type is int32_t.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_HAS_VIDEO = "hasVideo" | Pointer to the key for obtaining the flag indicating whether the media asset contains video. The value type is int32_t.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_MIME_TYPE = "mimeType" | Pointer to the key for obtaining the MIME type of the media asset. The value type is const char*, for example, video/mp4, audio/mp4, and audio/amr wb.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_TRACK_COUNT = "trackCount" | Pointer to the key for obtaining the number of tracks of the media asset. The value type is int32_t.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_SAMPLE_RATE = "sampleRate" | Pointer to the key for obtaining the audio sampling rate, in Hz. The value type is int32_t.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_TITLE = "title" | Pointer to the key for obtaining the title of the media asset. The value type is const char*.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_VIDEO_HEIGHT = "videoHeight" | Pointer to the key for obtaining the video height, in px. The value type is int32_t.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_VIDEO_WIDTH = "videoWidth" | Pointer to the key for obtaining the video weight, in px. The value type is int32_t.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_VIDEO_ORIENTATION = "videoOrientation" | Pointer to the key for obtaining the video rotation direction, in degrees (°). The value type is int32_t.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_VIDEO_IS_HDR_VIVID = "hdrType" | Pointer to the key for obtaining the flag indicating whether the video is an HDR Vivid video. The value type is int32_t.<br>For details, see [OH_Core_HdrType](../apis-avcodec-kit/_core.md#oh_core_hdrtype-1) in **media_types.h**.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_LOCATION_LATITUDE = "latitude" | Pointer to the key for obtaining the latitude in the geographical location. The value type is float.<br>**Since**: 18|
| static const char* OH_AVMETADATA_EXTRACTOR_LOCATION_LONGITUDE = "longitude" | Pointer to the key for obtaining the longitude in the geographical location. The value type is float.<br>**Since**: 18|
