# net_websocket.h


## Overview

The **native_avmetadata.h** file declares the definitions of playback control metadata.

**Library**: libohavsession.so

**File to include**: &lt;multimedia/av_session/native_avmetadata.h&gt;

**System capability**: SystemCapability.Multimedia.AVSession.Core

**Since**: 13

**Related module**: [OHAVSession](capi-_o_h_a_v_session.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct OH_AVMetadataBuilderStruct [OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) | Defines a struct for the session metadata builder. The builder is used to construct session metadata.| 
| typedef struct OH_AVMetadataStruct [OH_AVMetadata](capi-_o_h_a_v_session.md#oh_avmetadata) | Defines a struct for the session metadata. It is an AVMetadata instance set for a media asset.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) {<br>AVMETADATA_SUCCESS = 0,<br>AVMETADATA_ERROR_INVALID_PARAM = 1,<br>AVMETADATA_ERROR_NO_MEMORY = 2 } | Enumerates the error codes related to metadata operations.| 
| [AVMetadata_SkipIntervals](capi-_o_h_a_v_session.md#avmetadata_skipintervals) {<br>SECONDS_10 = 10,<br>SECONDS_15 = 15,<br>SECONDS_30 = 30 } | Enumerates the fast-forward or rewind intervals supported by the media session.| 
| [AVMetadata_DisplayTag](capi-_o_h_a_v_session.md#avmetadata_displaytag) { AVSESSION_DISPLAYTAG_AUDIO_VIVID = 1 } | Enumerates the display tags of the media asset. The display tag is a special type identifier of the media audio source.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_Create](capi-_o_h_a_v_session.md#oh_avmetadatabuilder_create) ([OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) \*\*builder) | Creates a metadata builder.| 
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_Destroy](capi-_o_h_a_v_session.md#oh_avmetadatabuilder_destroy) ([OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder) | Destroys a metadata builder.| 
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetAssetId](capi-_o_h_a_v_session.md#oh_avmetadatabuilder_setassetid) ([OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*assetId) | Sets the ID of the media asset.| 
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetTitle](capi-_o_h_a_v_session.md#oh_avmetadatabuilder_settitle) ([OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*title) | Sets a title for the media asset.| 
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetArtist](capi-_o_h_a_v_session.md#oh_avmetadatabuilder_setartist) ([OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*artist) | Sets an artist for the media asset.| 
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetAuthor](capi-_o_h_a_v_session.md#oh_avmetadatabuilder_setauthor) ([OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*author) | Sets an author for the media asset.| 
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetAlbum](capi-_o_h_a_v_session.md#oh_avmetadatabuilder_setalbum) ([OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*album) | Sets an album name for the media asset.| 
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetWriter](capi-_o_h_a_v_session.md#oh_avmetadatabuilder_setwriter) ([OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*writer) | Sets a writer for the media asset.| 
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetComposer](capi-_o_h_a_v_session.md#oh_avmetadatabuilder_setcomposer) ([OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*composer) | Sets a composer for the media asset.| 
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetDuration](capi-_o_h_a_v_session.md#oh_avmetadatabuilder_setduration) ([OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, int64_t duration) | Sets the playback duration for the media asset.| 
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetMediaImageUri](capi-_o_h_a_v_session.md#oh_avmetadatabuilder_setmediaimageuri) ([OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*mediaImageUri) | Sets an image for the media asset.| 
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetSubtitle](capi-_o_h_a_v_session.md#oh_avmetadatabuilder_setsubtitle) ([OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*subtitle) | Sets a subtitle for the media asset.| 
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetDescription](capi-_o_h_a_v_session.md#oh_avmetadatabuilder_setdescription) ([OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*description) | Sets a description for the media asset.| 
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetLyric](capi-_o_h_a_v_session.md#oh_avmetadatabuilder_setlyric) ([OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, const char \*lyric) | Sets lyrics for the media asset.| 
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetSkipIntervals](capi-_o_h_a_v_session.md#oh_avmetadatabuilder_setskipintervals) ([OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, [AVMetadata_SkipIntervals](capi-_o_h_a_v_session.md#avmetadata_skipintervals) intervals) | Sets the skip intervals for the media asset.| 
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_SetDisplayTags](capi-_o_h_a_v_session.md#oh_avmetadatabuilder_setdisplaytags) ([OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, int32_t tags) | Sets display tags for the media asset.| 
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadataBuilder_GenerateAVMetadata](capi-_o_h_a_v_session.md#oh_avmetadatabuilder_generateavmetadata) ([OH_AVMetadataBuilder](capi-_o_h_a_v_session.md#oh_avmetadatabuilder) \*builder, [OH_AVMetadata](capi-_o_h_a_v_session.md#oh_avmetadata) \*\*avMetadata) | Generates an **OH_AVMetadata** object.| 
| [AVMetadata_Result](capi-_o_h_a_v_session.md#avmetadata_result) [OH_AVMetadata_Destroy](capi-_o_h_a_v_session.md#oh_avmetadata_destroy) ([OH_AVMetadata](capi-_o_h_a_v_session.md#oh_avmetadata) \*avMetadata) | Releases an **OH_AVMetadata** object.| 
