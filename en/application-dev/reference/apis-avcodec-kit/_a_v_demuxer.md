# AVDemuxer


## Overview

The AVDemuxer module provides the APIs for extracting [samples](../../media/avcodec/audio-video-demuxer.md) from media streams.

For details about the development guide and sample, see [Media Data Demultiplexing](../../media/avcodec/audio-video-demuxer.md).

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_avdemuxer.h](native__avdemuxer_8h.md) | Declares the APIs for parsing audio and video media data.|

### Types

| Name| Description| 
| -------- | -------- |
| typedef void(* [DRM_MediaKeySystemInfoCallback](#drm_mediakeysysteminfocallback)) (DRM_MediaKeySystemInfo *mediaKeySystemInfo) | Defines a pointer to the callback function for [DRM_MediaKeySystemInfo](../apis-drm-kit/_d_r_m___media_key_system_info.md). No demuxer instance is returned. This callback function applies to the scenario where a single demuxer instance is used. You need to call [OH_AVDemuxer_SetMediaKeySystemInfoCallback](#oh_avdemuxer_setmediakeysysteminfocallback) to set the callback function as a callback. (This type is deprecated from API version 14.) |
| typedef void(* [Demuxer_MediaKeySystemInfoCallback](#demuxer_mediakeysysteminfocallback)) (OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfo *mediaKeySystemInfo)| Defines a pointer to the callback function for [DRM_MediaKeySystemInfo](../apis-drm-kit/_d_r_m___media_key_system_info.md). A demuxer instance is returned. This callback function applies to the scenario where multiple demuxer instances are used. You need to call [OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback](#oh_avdemuxer_setdemuxermediakeysysteminfocallback) to set the callback function as a callback. This callback function is recommended. |


### Functions

| Name| Description| 
| -------- | -------- |
| OH_AVDemuxer \* [OH_AVDemuxer_CreateWithSource](#oh_avdemuxer_createwithsource) ([OH_AVSource](_a_v_source.md#oh_avsource) \*source) | Creates an **OH_AVDemuxer** instance based on a source instance.|
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_Destroy](#oh_avdemuxer_destroy) (OH_AVDemuxer \*demuxer) | Destroys an **OH_AVDemuxer** instance and clears internal resources.| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_SelectTrackByID](#oh_avdemuxer_selecttrackbyid) (OH_AVDemuxer \*demuxer, uint32_t trackIndex) | Selects a track from which the demuxer reads sample data.|
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_UnselectTrackByID](#oh_avdemuxer_unselecttrackbyid) (OH_AVDemuxer \*demuxer, uint32_t trackIndex) | Deselects a track. The demuxer no longer reads sample data from a track after it is deselected.|
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_ReadSample](#oh_avdemuxer_readsample) (OH_AVDemuxer \*demuxer, uint32_t trackIndex, [OH_AVMemory](_core.md#oh_avmemory) \*sample, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*info) | Reads the sample and related information from the specified track. (This function is deprecated from API version 11.) |
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_ReadSampleBuffer](#oh_avdemuxer_readsamplebuffer) (OH_AVDemuxer \*demuxer, uint32_t trackIndex, [OH_AVBuffer](_core.md#oh_avbuffer) \*sample) | Reads the sample of the specified track.|
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_SeekToTime](#oh_avdemuxer_seektotime) (OH_AVDemuxer \*demuxer, int64_t millisecond, [OH_AVSeekMode](_codec_base.md#oh_avseekmode) mode) | Seeks to the specified time for all the selected tracks based on a [seek mode](_codec_base.md#oh_avseekmode-1). |
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_SetMediaKeySystemInfoCallback](#oh_avdemuxer_setmediakeysysteminfocallback) (OH_AVDemuxer \*demuxer, DRM_MediaKeySystemInfoCallback callback) | Sets an asynchronous callback for obtaining the media key system information. (This function is deprecated from API version 14.) | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback](#oh_avdemuxer_setdemuxermediakeysysteminfocallback) (OH_AVDemuxer \*demuxer, Demuxer_MediaKeySystemInfoCallback callback) | Sets an asynchronous callback for obtaining the media key system information. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_GetMediaKeySystemInfo](#oh_avdemuxer_getmediakeysysteminfo) (OH_AVDemuxer \*demuxer, DRM_MediaKeySystemInfo \*mediaKeySystemInfo) | Obtains the media key system information. | 


## Type Description

### Demuxer_MediaKeySystemInfoCallback

```
typedef void(* Demuxer_MediaKeySystemInfoCallback) (OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```

**Description**

Defines a pointer to the callback function for the media key system information.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 12


### DRM_MediaKeySystemInfoCallback

```
typedef void(* DRM_MediaKeySystemInfoCallback) (DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```

**Description**

Defines a pointer to the callback function for the media key system information.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 11

**Deprecated from**: 14

**Substitute**: [Demuxer_MediaKeySystemInfoCallback](#demuxer_mediakeysysteminfocallback)


## Function Description


### OH_AVDemuxer_CreateWithSource()

```
OH_AVDemuxer* OH_AVDemuxer_CreateWithSource (OH_AVSource *source)
```

**Description**

Creates an **OH_AVDemuxer** instance based on a source instance.

For details about how to create, destroy, and use a source instance, see [OH_AVSource](_a_v_source.md).

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| source | Pointer to an **OH_AVSource** instance. | 

**Returns**

Returns the pointer to an **OH_AVDemuxer** instance if the operation is successful; returns NULL otherwise.
 
The possible causes of an operation failure are as follows:
1. The value of **source** is invalid, that is, a null pointer.
2. The value of **source** does not point to an **OH_AVSource** instance.


### OH_AVDemuxer_Destroy()

```
OH_AVErrCode OH_AVDemuxer_Destroy (OH_AVDemuxer *demuxer)
```

**Description**

Destroys an **OH_AVDemuxer** instance and clears internal resources. An instance can be destroyed only once.

The destroyed instance cannot be used until it is re-created. You are advised to set the pointer to **NULL** after the instance is destroyed.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| demuxer | Pointer to an **OH_AVDemuxer** instance. | 

**Returns**

Returns one of the following result codes:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The value of **demuxer** is a null pointer or does not point to a demuxer instance.


### OH_AVDemuxer_GetMediaKeySystemInfo()

```
OH_AVErrCode OH_AVDemuxer_GetMediaKeySystemInfo (OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```
**Description**

Obtains the media key system information.

The media key system information can be obtained only after [Demuxer_MediaKeySystemInfoCallback](#demuxer_mediakeysysteminfocallback) or [DRM_MediaKeySystemInfoCallback](#drm_mediakeysysteminfocallback) is successfully invoked.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| demuxer | Pointer to an **OH_AVDemuxer** instance. | 
| mediaKeySystemInfo | Pointer to the media key system information. For details, see [DRM_MediaKeySystemInfo](../apis-drm-kit/_d_r_m___media_key_system_info.md). | 

**Returns**

Returns one of the following result codes:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**:

    1. The value of **demuxer** is a null pointer or does not point to a demuxer instance.
    2. The value of **mediaKeySystemInfo** is a null pointer.


### OH_AVDemuxer_ReadSample()

```
OH_AVErrCode OH_AVDemuxer_ReadSample (OH_AVDemuxer *demuxer, uint32_t trackIndex, OH_AVMemory *sample, OH_AVCodecBufferAttr *info)
```

**Description**

Reads the sample and related information from the specified track.

You must select a track before reading the sample. After this API is called, the demuxer automatically proceeds to the next frame.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Deprecated from**: 11

**Substitute API**: [OH_AVDemuxer_ReadSampleBuffer](#oh_avdemuxer_readsamplebuffer)

**Parameters**

| Name| Description| 
| -------- | -------- |
| demuxer | Pointer to an **OH_AVDemuxer** instance. | 
| trackIndex | Index of the track from which the compressed frame is to be read. | 
| sample | Pointer to the **OH_AVMemory** instance for storing the compressed frame data. | 
| info | Pointer to the **OH_AVCodecBufferAttr** instance for storing the compressed frame information. | 

**Returns**

Returns one of the following result codes:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**:

    1. The value of **demuxer** is a null pointer or does not point to a demuxer instance.
    2. The track index is out of range.
    3. Track reading is not supported.
    4. The value of **sample** is null.
    5. The value of **info** is null.

**AV_ERR_OPERATE_NOT_PERMIT**:

    1. The track with the specified index is not selected.
    2. The demuxer is not correctly initialized.

**AV_ERR_NO_MEMORY**: The sample capacity is insufficient to store all frame data.

**AV_ERR_UNKNOWN**: Failed to read or parse the frame from the file.


### OH_AVDemuxer_ReadSampleBuffer()

```
OH_AVErrCode OH_AVDemuxer_ReadSampleBuffer (OH_AVDemuxer *demuxer, uint32_t trackIndex, OH_AVBuffer *sample)
```

**Description**

Reads the sample and related information from the specified track.

You can use [OH_AVDemuxer_SelectTrackByID](#oh_avdemuxer_selecttrackbyid) to select a track before reading the sample. After this API is called, the demuxer automatically proceeds to the next frame.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| demuxer | Pointer to an **OH_AVDemuxer** instance. | 
| trackIndex | Index of the track from which the compressed frame is to be read. | 
| sample | Pointer to the **OH_AVBuffer** instance for storing the compressed frame data and related information. | 

**Returns**

Returns one of the following result codes:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**:

    1. The value of **demuxer** is a null pointer or does not point to a demuxer instance.
    2. The value of **sample** is a null pointer.
    3. The track index is out of range.
    4. The value of **sample** is null.

**AV_ERR_OPERATE_NOT_PERMIT**:

    1. The track with the specified index is not selected.
    2. The demuxer is not correctly initialized.

**AV_ERR_NO_MEMORY**: The sample capacity is insufficient to store all frame data.

**AV_ERR_UNKNOWN**: Failed to read or parse the frame from the file.


### OH_AVDemuxer_SeekToTime()

```
OH_AVErrCode OH_AVDemuxer_SeekToTime (OH_AVDemuxer *demuxer, int64_t millisecond, OH_AVSeekMode mode)
```

**Description**

Seeks to the specified time for all the selected tracks based on a [seek mode](_codec_base.md#oh_avseekmode-1).

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| demuxer | Pointer to an **OH_AVDemuxer** instance. | 
| millisecond | Time to seek to, in milliseconds. The timestamp is relative to the start position of the file. | 
| mode | Seek mode. For details, see [OH_AVSeekMode](_codec_base.md#oh_avseekmode). | 

**Returns**

Returns one of the following result codes:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**:

    1. The value of **demuxer** is a null pointer or does not point to a demuxer instance.
    2. The value of **millisecond** is out of range.

**AV_ERR_OPERATE_NOT_PERMIT**:

    1. The track with the specified index is not selected.
    2. The demuxer is not correctly initialized.
    3. The seek operation cannot be performed on the resource.

**AV_ERR_UNKNOWN**:

    1. The seek operation fails.
    2. **OH_AVSeekMode** is set to **SEEK_MODE_NEXT_SYNC** and there is no I-frame following the specified position.


### OH_AVDemuxer_SelectTrackByID()

```
OH_AVErrCode OH_AVDemuxer_SelectTrackByID (OH_AVDemuxer *demuxer, uint32_t trackIndex)
```

**Description**

Selects a track from which the demuxer reads sample data.

You can select multiple tracks by calling this API multiple times, with a different track index passed in each time.

When **OH_AVDemuxer_ReadSample** is called, only the data in the selected track is read. If the same track is selected multiple times, **AV_ERR_OK** is returned and the API call takes effect only once.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| demuxer | Pointer to an **OH_AVDemuxer** instance. | 
| trackIndex | Index of the track. | 

**Returns**

Returns one of the following result codes:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_OPERATE_NOT_PERMIT**: The demuxer is not correctly initialized.

**AV_ERR_INVALID_VAL**:
    
    1. The value of **demuxer** is a null pointer or does not point to a demuxer instance.
    2. The track index is out of range.
    3. Track reading is not supported.


### OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback()

```
OH_AVErrCode OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback (OH_AVDemuxer *demuxer, Demuxer_MediaKeySystemInfoCallback callback)
```

**Description**

Sets a callback for obtaining the media key system information.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| demuxer | Pointer to an **OH_AVDemuxer** instance. | 
| callback | Callback function. For details, see [Demuxer_MediaKeySystemInfoCallback](#demuxer_mediakeysysteminfocallback). | 

**Returns**

Returns one of the following result codes:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_OPERATE_NOT_PERMIT**: The demuxer is not correctly initialized.

**AV_ERR_INVALID_VAL**: The value of **demuxer** is a null pointer or does not point to a demuxer instance.


### OH_AVDemuxer_SetMediaKeySystemInfoCallback()

```
OH_AVErrCode OH_AVDemuxer_SetMediaKeySystemInfoCallback (OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfoCallback callback)
```
**Description**

Sets a callback for obtaining the media key system information.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 11

**Deprecated from**: 14

**Substitute**: [OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback](#oh_avdemuxer_setdemuxermediakeysysteminfocallback)

**Parameters**

| Name| Description| 
| -------- | -------- |
| demuxer | Pointer to an **OH_AVDemuxer** instance. | 
| callback | Callback function. For details, see [DRM_MediaKeySystemInfoCallback](#drm_mediakeysysteminfocallback). | 

**Returns**

Returns one of the following result codes:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_OPERATE_NOT_PERMIT**: The demuxer is not correctly initialized.

**AV_ERR_INVALID_VAL**: The value of **demuxer** is a null pointer or does not point to a demuxer instance.


### OH_AVDemuxer_UnselectTrackByID()

```
OH_AVErrCode OH_AVDemuxer_UnselectTrackByID (OH_AVDemuxer *demuxer, uint32_t trackIndex)
```

**Description**

Deselects a track. The demuxer no longer reads sample data from a track after it is deselected.

You can deselect multiple tracks by calling this API multiple times, with a different track index passed in each time.

If the same track is deselected multiple times, **AV_ERR_OK** is returned and the API call takes effect only once.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| demuxer | Pointer to an **OH_AVDemuxer** instance. | 
| trackIndex | Index of the track. | 

**Returns**

Returns one of the following result codes:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_OPERATE_NOT_PERMIT**: The demuxer is not correctly initialized.

**AV_ERR_INVALID_VAL**: The value of **demuxer** is a null pointer or does not point to a demuxer instance.
