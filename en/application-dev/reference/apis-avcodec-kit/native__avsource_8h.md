# native_avsource.h


## Overview

The file declares the native APIs used for audio and video demultiplexing.

**Library**: libnative_media_avsource.so

**File to include**: <multimedia/player_framework/native_avsource.h>

**Since**: 10

**Related module**: [AVSource](_a_v_source.md)

**Sample**: [AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_AVSource](_a_v_source.md#oh_avsource) [OH_AVSource](_a_v_source.md#oh_avsource) | Defines a struct that describes a native object for the media source interface. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AVSource](_a_v_source.md#oh_avsource) \* [OH_AVSource_CreateWithDataSource](_a_v_source.md#oh_avsource_createwithdatasource) ([OH_AVDataSource](_o_h___a_v_data_source.md) \*dataSource) | Creates an OH_AVSource instance with a user-defined data source. You can release the instance by calling **OH_AVSource_Destroy**. | 
| [OH_AVSource](_a_v_source.md#oh_avsource) \* [OH_AVSource_CreateWithURI](_a_v_source.md#oh_avsource_createwithuri) (char \*uri) | Creates an OH_AVSource instance based on a URI.| 
| [OH_AVSource](_a_v_source.md#oh_avsource) \* [OH_AVSource_CreateWithFD](_a_v_source.md#oh_avsource_createwithfd) (int32_t fd, int64_t offset, int64_t size) | Creates an OH_AVSource instance based on a file descriptor (FD).| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVSource_Destroy](_a_v_source.md#oh_avsource_destroy) ([OH_AVSource](_a_v_source.md#oh_avsource) \*source) | Destroys an OH_AVSource instance and clears internal resources.| 
| [OH_AVFormat](_core.md#oh_avformat) \* [OH_AVSource_GetSourceFormat](_a_v_source.md#oh_avsource_getsourceformat) ([OH_AVSource](_a_v_source.md#oh_avsource) \*source) | Obtains the basic information about a media resource file.| 
| [OH_AVFormat](_core.md#oh_avformat) \* [OH_AVSource_GetTrackFormat](_a_v_source.md#oh_avsource_gettrackformat) ([OH_AVSource](_a_v_source.md#oh_avsource) \*source, uint32_t trackIndex) | Obtains the basic information about a track.| 
| OH_AVFormat \* [OH_AVSource_GetCustomMetadataFormat](_a_v_source.md#oh_avsource_getcustommetadataformat) ([OH_AVSource](_a_v_source.md#oh_avsource) \*source) | Obtains the basic information about custom metadata.| 
