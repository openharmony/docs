# avmetadata_extractor.h


## Overview

The **avmetadata_extractor.h** file declares the AVMetadataExtractor APIs. With these native APIs, you can obtain metadata from media assets.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Library**: libavmetadata_extractor.so

**Since**: 18

**Related module**: [AVMetadataExtractor](_a_v_metadata_extractor.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_AVMetadataExtractor](_a_v_metadata_extractor.md#oh_avmetadataextractor) [OH_AVMetadataExtractor](_a_v_metadata_extractor.md#oh_avmetadataextractor) | Defines a struct for the OH_AVMetadataExtractor. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AVMetadataExtractor](_a_v_metadata_extractor.md#oh_avmetadataextractor) \* [OH_AVMetadataExtractor_Create](_a_v_metadata_extractor.md#oh_avmetadataextractor_create) (void) | Creates an **OH_AVMetadataExtractor** instance. | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVMetadataExtractor_SetFDSource](_a_v_metadata_extractor.md#oh_avmetadataextractor_setfdsource) ([OH_AVMetadataExtractor](_a_v_metadata_extractor.md#oh_avmetadataextractor) \*extractor, int32_t fd, int64_t offset, int64_t size) | Sets a data source based on the media file descriptor. | 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVMetadataExtractor_FetchMetadata](_a_v_metadata_extractor.md#oh_avmetadataextractor_fetchmetadata) ([OH_AVMetadataExtractor](_a_v_metadata_extractor.md#oh_avmetadataextractor) \*extractor, OH_AVFormat \*avMetadata) | Obtains metadata from a media asset. This function must be called after [SetFDSource](_a_v_metadata_extractor.md#oh_avmetadataextractor_setfdsource).| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVMetadataExtractor_FetchAlbumCover](_a_v_metadata_extractor.md#oh_avmetadataextractor_fetchalbumcover) ([OH_AVMetadataExtractor](_a_v_metadata_extractor.md#oh_avmetadataextractor) \*extractor, OH_PixelmapNative \*\*pixelMap) | Obtains the cover of an audio album. This function must be called after [SetFDSource](_a_v_metadata_extractor.md#oh_avmetadataextractor_setfdsource).| 
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVMetadataExtractor_Release](_a_v_metadata_extractor.md#oh_avmetadataextractor_release) ([OH_AVMetadataExtractor](_a_v_metadata_extractor.md#oh_avmetadataextractor) \*extractor) | Releases the resources used by the **OH_AVMetadataExtractor** instance and destroys the instance. | 
