# native_avdemuxer.h


## Overview

The **native_avdemuxer.h** file declares the native APIs used for audio and video decapsulation.

**Since**

10

**Related Modules**

[AVDemuxer](_a_v_demuxer.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| \*[OH_AVDemuxer_CreateWithSource](_a_v_demuxer.md#oh_avdemuxer_createwithsource) (OH_AVSource \*source) | Creates an **OH_AVDemuxer** instance based on an **OH_AVSource** instance.| 
| [OH_AVDemuxer_Destroy](_a_v_demuxer.md#oh_avdemuxer_destroy) (OH_AVDemuxer \*demuxer) | Destroys an **OH_AVDemuxer** instance and clears internal resources.| 
| [OH_AVDemuxer_SelectTrackByID](_a_v_demuxer.md#oh_avdemuxer_selecttrackbyid) (OH_AVDemuxer \*demuxer, uint32_t trackIndex) | Selects a track, from which the demuxer reads data.| 
| [OH_AVDemuxer_UnselectTrackByID](_a_v_demuxer.md#oh_avdemuxer_unselecttrackbyid) (OH_AVDemuxer \*demuxer, uint32_t trackIndex) | Deselects a track. The demuxer no longer reads data from a track after it is deselected.| 
| [OH_AVDemuxer_ReadSample](_a_v_demuxer.md#oh_avdemuxer_readsample) (OH_AVDemuxer \*demuxer, uint32_t trackIndex, OH_AVMemory \*sample, OH_AVCodecBufferAttr \*info) | Obtains the compressed frame and related information at the current position from the selected track.| 
| [OH_AVDemuxer_SeekToTime](_a_v_demuxer.md#oh_avdemuxer_seektotime) (OH_AVDemuxer \*demuxer, int64_t millisecond, OH_AVSeekMode mode) | Seeks to the specified time for all the selected tracks based on a seek mode.| 
