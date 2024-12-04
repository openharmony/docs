# native_avdemuxer.h


## Overview

Declares the APIs for parsing audio and video media data.

**Library**: libnative_media_avdemuxer.so

**Since**: 10

**Related module**: [AVDemuxer](_a_v_demuxer.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef void(* [DRM_MediaKeySystemInfoCallback](_a_v_demuxer.md#drm_mediakeysysteminfocallback)) (DRM_MediaKeySystemInfo *mediaKeySystemInfo) | Defines a pointer to the callback function for the media key system information. |
| typedef void(* [Demuxer_MediaKeySystemInfoCallback](_a_v_demuxer.md#demuxer_mediakeysysteminfocallback)) (OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfo *mediaKeySystemInfo)| Defines a pointer to the callback function for the media key system information. |


### Functions

| Name| Description| 
| -------- | -------- |
| OH_AVDemuxer \* [OH_AVDemuxer_CreateWithSource](_a_v_demuxer.md#oh_avdemuxer_createwithsource) ([OH_AVSource](_a_v_source.md#oh_avsource) \*source) | Creates an **OH_AVDemuxer** instance based on a source instance. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_Destroy](_a_v_demuxer.md#oh_avdemuxer_destroy) (OH_AVDemuxer \*demuxer) | Destroys an **OH_AVDemuxer** instance and clears internal resources. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_SelectTrackByID](_a_v_demuxer.md#oh_avdemuxer_selecttrackbyid) (OH_AVDemuxer \*demuxer, uint32_t trackIndex) | Selects a track from which the demuxer reads sample data. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_UnselectTrackByID](_a_v_demuxer.md#oh_avdemuxer_unselecttrackbyid) (OH_AVDemuxer \*demuxer, uint32_t trackIndex) | Deselects a track. The demuxer no longer reads data from a track after it is deselected. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_ReadSample](_a_v_demuxer.md#oh_avdemuxer_readsample) (OH_AVDemuxer \*demuxer, uint32_t trackIndex, [OH_AVMemory](_core.md#oh_avmemory) \*sample, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*info) | Reads the sample and related information from the specified track. (This function is deprecated in API version 11.) | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_ReadSampleBuffer](_a_v_demuxer.md#oh_avdemuxer_readsamplebuffer) (OH_AVDemuxer \*demuxer, uint32_t trackIndex, [OH_AVBuffer](_core.md#oh_avbuffer) \*sample) | Obtains the compressed frame and related information at the current position from the selected track. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_SeekToTime](_a_v_demuxer.md#oh_avdemuxer_seektotime) (OH_AVDemuxer \*demuxer, int64_t millisecond, [OH_AVSeekMode](_codec_base.md#oh_avseekmode) mode) | Seeks to the specified time for all the selected tracks based on a seek mode. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_SetMediaKeySystemInfoCallback](_a_v_demuxer.md#oh_avdemuxer_setmediakeysysteminfocallback) (OH_AVDemuxer \*demuxer, DRM_MediaKeySystemInfoCallback callback) | Sets an asynchronous callback for obtaining the media key system information. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback](_a_v_demuxer.md#oh_avdemuxer_setdemuxermediakeysysteminfocallback) (OH_AVDemuxer \*demuxer, Demuxer_MediaKeySystemInfoCallback callback) | Sets an asynchronous callback for obtaining the media key system information. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_GetMediaKeySystemInfo](_a_v_demuxer.md#oh_avdemuxer_getmediakeysysteminfo) (OH_AVDemuxer \*demuxer, DRM_MediaKeySystemInfo \*mediaKeySystemInfo) | Obtains the media key system information. | 
