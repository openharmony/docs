# avmetadata_extractor_base.h


## Overview

The **avmetadata_extractor_base.h** file declares the constants used by the AVMetadataExtractor.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Library**: libavmetadata_extractor.so

**Since**: 18

**Related module**: [AVMetadataExtractor](_a_v_metadata_extractor.md)


### Variables

| Name| Description| 
| -------- | -------- |
| static const char\* [OH_AVMETADATA_EXTRACTOR_ALBUM](_a_v_metadata_extractor.md#oh_avmetadata_extractor_album) = "album" | Pointer to the key for obtaining the title of the album. The value type is const char\*. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_ALBUM_ARTIST](_a_v_metadata_extractor.md#oh_avmetadata_extractor_album_artist) = "albumArtist" | Pointer to the key for obtaining the artist of the album. The value type is const char\*. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_ARTIST](_a_v_metadata_extractor.md#oh_avmetadata_extractor_artist) = "artist" | Pointer to the key for obtaining the artist of the media asset. The value type is const char\*. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_AUTHOR](_a_v_metadata_extractor.md#oh_avmetadata_extractor_author) = "author" | Pointer to the key for obtaining the author of the media asset. The value type is const char\*. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_DATE_TIME](_a_v_metadata_extractor.md#oh_avmetadata_extractor_date_time) = "dateTime" | Pointer to the key for obtaining the creation time of the media asset. The value type is const char\*. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_DATE_TIME_FORMAT](_a_v_metadata_extractor.md#oh_avmetadata_extractor_date_time_format) = "dateTimeFormat" | Pointer to the key for obtaining the creation time of the media asset. The value type is const char\* and the output format is YYYY-MM-DD HH:mm:ss. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_COMPOSER](_a_v_metadata_extractor.md#oh_avmetadata_extractor_composer) = "composer" | Pointer to the key for obtaining the composer of the media asset. The value type is const char\*. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_DURATION](_a_v_metadata_extractor.md#oh_avmetadata_extractor_duration) = "duration" | Pointer to the key for obtaining the duration of the media asset, in ms. The value type is int64_t. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_GENRE](_a_v_metadata_extractor.md#oh_avmetadata_extractor_genre) = "genre" | Pointer to the key for obtaining the type or genre of the media asset. The value type is const char\*. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_HAS_AUDIO](_a_v_metadata_extractor.md#oh_avmetadata_extractor_has_audio) = "hasAudio" | Pointer to the key for obtaining the flag indicating whether the media asset contains audio. The value type is int32_t. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_HAS_VIDEO](_a_v_metadata_extractor.md#oh_avmetadata_extractor_has_video) = "hasVideo" | Pointer to the key for obtaining the flag indicating whether the media asset contains video. The value type is int32_t. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_MIME_TYPE](_a_v_metadata_extractor.md#oh_avmetadata_extractor_mime_type) = "mimeType" | Pointer to the key for obtaining the MIME type of the media asset. The value type is const char\*, for example, video/mp4, audio/mp4, and audio/amr wb. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_TRACK_COUNT](_a_v_metadata_extractor.md#oh_avmetadata_extractor_track_count) = "trackCount" | Pointer to the key for obtaining the number of tracks of the media asset. The value type is int32_t. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_SAMPLE_RATE](_a_v_metadata_extractor.md#oh_avmetadata_extractor_sample_rate) = "sampleRate" | Pointer to the key for obtaining the audio sampling rate, in Hz. The value type is int32_t. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_TITLE](_a_v_metadata_extractor.md#oh_avmetadata_extractor_title) = "title" | Pointer to the key for obtaining the title of the media asset. The value type is const char\*. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_VIDEO_HEIGHT](_a_v_metadata_extractor.md#oh_avmetadata_extractor_video_height) = "videoHeight" | Pointer to the key for obtaining the video height, in px. The value type is int32_t. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_VIDEO_WIDTH](_a_v_metadata_extractor.md#oh_avmetadata_extractor_video_width) = "videoWidth" | Pointer to the key for obtaining the video weight, in px. The value type is int32_t. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_VIDEO_ORIENTATION](_a_v_metadata_extractor.md#oh_avmetadata_extractor_video_orientation) = "videoOrientation" | Pointer to the key for obtaining the video rotation direction, in degrees (°). The value type is int32_t. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_VIDEO_IS_HDR_VIVID](_a_v_metadata_extractor.md#oh_avmetadata_extractor_video_is_hdr_vivid) = "hdrType" | Pointer to the key for obtaining the flag indicating whether the video is an HDR Vivid video. The value type is int32_t. For details, see the definition of [OH_Core_HdrType](../apis-avcodec-kit/_core.md#oh_core_hdrtype) in [media_types.h](../apis-avcodec-kit/media__types_8h.md). | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_LOCATION_LATITUDE](_a_v_metadata_extractor.md#oh_avmetadata_extractor_location_latitude) = "latitude" | Pointer to the key for obtaining the latitude in the geographical location. The value type is float. | 
| static const char\* [OH_AVMETADATA_EXTRACTOR_LOCATION_LONGITUDE](_a_v_metadata_extractor.md#oh_avmetadata_extractor_location_longitude) = "longitude" | Pointer to the key for obtaining the longitude in the geographical location. The value type is float. | 
