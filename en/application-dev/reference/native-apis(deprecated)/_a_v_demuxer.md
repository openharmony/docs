# AVDemuxer


## Overview

The AVDemuxer module provides functions for audio and video decapsulation.

\@syscap SystemCapability.Multimedia.Media.Spliter

**Since**

10


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [native_avdemuxer.h](native__avdemuxer_8h.md) | Declares the native APIs used for audio and video decapsulation.<br>**File to include**: <multimedia/player_framework/native_avdemuxer.h><br>**Library**: libnative_media_avdemuxer.so| 


### Functions

| Name| Description| 
| -------- | -------- |
| \*[OH_AVDemuxer_CreateWithSource](#oh_avdemuxer_createwithsource) (OH_AVSource \*source) | Creates an **OH_AVDemuxer** instance based on an **OH_AVSource** instance.| 
| [OH_AVDemuxer_Destroy](#oh_avdemuxer_destroy) (OH_AVDemuxer \*demuxer) | Destroys an **OH_AVDemuxer** instance and clears internal resources.| 
| [OH_AVDemuxer_SelectTrackByID](#oh_avdemuxer_selecttrackbyid) (OH_AVDemuxer \*demuxer, uint32_t trackIndex) | Selects a track, from which the demuxer reads data.| 
| [OH_AVDemuxer_UnselectTrackByID](#oh_avdemuxer_unselecttrackbyid) (OH_AVDemuxer \*demuxer, uint32_t trackIndex) | Deselects a track. The demuxer no longer reads data from a track after it is deselected.| 
| [OH_AVDemuxer_ReadSample](#oh_avdemuxer_readsample) (OH_AVDemuxer \*demuxer, uint32_t trackIndex, OH_AVMemory \*sample, OH_AVCodecBufferAttr \*info) | Obtains the compressed frame and related information at the current position from the selected track.| 
| [OH_AVDemuxer_SeekToTime](#oh_avdemuxer_seektotime) (OH_AVDemuxer \*demuxer, int64_t millisecond, OH_AVSeekMode mode) | Seeks to the specified time for all the selected tracks based on a seek mode.| 


## Function Description


### OH_AVDemuxer_CreateWithSource()

  
```
OH_AVDemuxer* OH_AVDemuxer_CreateWithSource (OH_AVSource *source)
```

**Description**

Creates an **OH_AVDemuxer** instance based on an **OH_AVSource** instance. You can release the instance by calling **OH_AVDemuxer_Destroy**.

\@syscap SystemCapability.Multimedia.Media.Spliter

**Parameters**

| Name| Description| 
| -------- | -------- |
| source | Pointer to an **OH_AVSource** instance.| 

**Returns**

Returns the pointer to an **OH_AVDemuxer** instance.

**Since**

10


### OH_AVDemuxer_Destroy()

  
```
OH_AVErrCode OH_AVDemuxer_Destroy (OH_AVDemuxer *demuxer)
```

**Description**

Destroys an **OH_AVDemuxer** instance and clears internal resources. An instance can be destroyed only once.

The destroyed instance cannot be used until it is re-created. You are advised to set the pointer to **NULL** after the instance is destroyed.

\@syscap SystemCapability.Multimedia.Media.Spliter

**Parameters**

| Name| Description| 
| -------- | -------- |
| demuxer | Pointer to an **OH_AVDemuxer** instance.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVDemuxer_ReadSample()

  
```
OH_AVErrCode OH_AVDemuxer_ReadSample (OH_AVDemuxer *demuxer, uint32_t trackIndex, OH_AVMemory *sample, OH_AVCodecBufferAttr *info)
```

**Description**

Obtains the compressed frame and related information at the current position from the selected track.

You must select a track before reading data. After this API is called, the demuxer automatically proceeds to the next frame.

\@syscap SystemCapability.Multimedia.Media.Spliter

**Parameters**

| Name| Description| 
| -------- | -------- |
| demuxer | Pointer to an **OH_AVDemuxer** instance.| 
| trackIndex | Index of the track from which the compressed frame is to be read.| 
| sample | Pointer to the **OH_AVMemory** instance for storing the compressed frame data.| 
| info | Pointer to the **OH_AVCodecBufferAttr** instance for storing the compressed frame information.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVDemuxer_SeekToTime()

  
```
OH_AVErrCode OH_AVDemuxer_SeekToTime (OH_AVDemuxer *demuxer, int64_t millisecond, OH_AVSeekMode mode)
```

**Description**

Seeks to the specified time for all the selected tracks based on a seek mode.

\@syscap SystemCapability.Multimedia.Media.Spliter

**Parameters**

| Name| Description| 
| -------- | -------- |
| demuxer | Pointer to an **OH_AVDemuxer** instance.| 
| millisecond | Time to seek to, in milliseconds. The timestamp is relative to the start position of the file.| 
| mode | Seek mode. For details, see **OH_AVSeekMode**.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVDemuxer_SelectTrackByID()

  
```
OH_AVErrCode OH_AVDemuxer_SelectTrackByID (OH_AVDemuxer *demuxer, uint32_t trackIndex)
```

**Description**

Selects a track, from which the demuxer reads data.

You can select multiple tracks by calling this API multiple times, with a different track index passed in each time.

When **OH_AVDemuxer_ReadSample** is called, only the data in the selected track is read. If the same track is selected multiple times, **AV_ERR_OK** is returned and the API call takes effect only once.

\@syscap SystemCapability.Multimedia.Media.Spliter

**Parameters**

| Name| Description| 
| -------- | -------- |
| demuxer | Pointer to an **OH_AVDemuxer** instance.| 
| trackIndex | Index of the track.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVDemuxer_UnselectTrackByID()

  
```
OH_AVErrCode OH_AVDemuxer_UnselectTrackByID (OH_AVDemuxer *demuxer, uint32_t trackIndex)
```

**Description**

Deselects a track. The demuxer no longer reads data from a track after it is deselected.

You can deselect multiple tracks by calling this API multiple times, with a different track index passed in each time.

If the same track is deselected multiple times, **AV_ERR_OK** is returned and the API call takes effect only once.

\@syscap SystemCapability.Multimedia.Media.Spliter

**Parameters**

| Name| Description| 
| -------- | -------- |
| demuxer | Pointer to an **OH_AVDemuxer** instance.| 
| trackIndex | Index of the track.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10
