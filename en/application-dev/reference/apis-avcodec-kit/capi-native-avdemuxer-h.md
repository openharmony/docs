# native_avdemuxer.h

## Overview

The file declares the APIs for parsing audio and video media data.

**File to include**: <multimedia/player_framework/native_avdemuxer.h>

**Library**: libnative_media_avdemuxer.so

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Related module**: [AVDemuxer](capi-avdemuxer.md)

**Sample**: [AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) | OH_AVDemuxer | Describes a native object for the OH_AVDemuxer interface.|
| [DRM_MediaKeySystemInfo](capi-avdemuxer-drm-mediakeysysteminfo.md) | DRM_MediaKeySystemInfo | Describes a native object for the DRM_MediaKeySystemInf interface.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*DRM_MediaKeySystemInfoCallback)(DRM_MediaKeySystemInfo* mediaKeySystemInfo)](#drm_mediakeysysteminfocallback) | DRM_MediaKeySystemInfoCallback | Defines a pointer to the callback function for **DRM_MediaKeySystemInfo**. No demuxer instance is returned. This callback function applies to the scenario where a single demuxer instance is used. You need to call **OH_AVDemuxer_SetMediaKeySystemInfoCallback** to set the callback function as a callback.|
| [typedef void (\*Demuxer_MediaKeySystemInfoCallback)(OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfo *mediaKeySystemInfo)](#demuxer_mediakeysysteminfocallback) | Demuxer_MediaKeySystemInfoCallback | Defines a pointer to the callback function for **DRM_MediaKeySystemInfo**. A demuxer instance is returned. This callback function applies to the scenario where multiple demuxer instances are used. You need to call **OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback** to set the callback function as a callback. This callback function is recommended.|
| [OH_AVDemuxer *OH_AVDemuxer_CreateWithSource(OH_AVSource *source)](#oh_avdemuxer_createwithsource) | - | Creates an OH_AVDemuxer instance based on a source instance. For details about how to create, destroy, and use a source instance, see [OH_AVSource](_a_v_source.md).|
| [OH_AVErrCode OH_AVDemuxer_Destroy(OH_AVDemuxer *demuxer)](#oh_avdemuxer_destroy) | - | Destroys an OH_AVDemuxer instance and clears internal resources. An instance can be destroyed only once. The destroyed instance cannot be used until it is re-created. You are advised to set the pointer to NULL after the instance is destroyed.|
| [OH_AVErrCode OH_AVDemuxer_SelectTrackByID(OH_AVDemuxer *demuxer, uint32_t trackIndex)](#oh_avdemuxer_selecttrackbyid) | - | Selects a track from which the demuxer reads sample data. You can select multiple tracks by calling this API multiple times, with a different track index passed in each time. When **OH_AVDemuxer_ReadSample** is called, only the data in the selected track is read. If the same track is selected multiple times, **AV_ERR_OK** is returned and the API call takes effect only once.|
| [OH_AVErrCode OH_AVDemuxer_UnselectTrackByID(OH_AVDemuxer *demuxer, uint32_t trackIndex)](#oh_avdemuxer_unselecttrackbyid) | - | Deselects a track. The demuxer no longer reads sample data from a track after it is deselected. You can deselect multiple tracks by calling this API multiple times, with a different track index passed in each time. If the same track is deselected multiple times, **AV_ERR_OK** is returned and the API call takes effect only once.|
| [OH_AVErrCode OH_AVDemuxer_ReadSample(OH_AVDemuxer *demuxer, uint32_t trackIndex,OH_AVMemory *sample, OH_AVCodecBufferAttr *info)](#oh_avdemuxer_readsample) | - | Reads the sample and related information from the specified track. You must select a track before reading the sample. After this API is called, the demuxer automatically proceeds to the next frame.|
| [OH_AVErrCode OH_AVDemuxer_ReadSampleBuffer(OH_AVDemuxer *demuxer, uint32_t trackIndex,OH_AVBuffer *sample)](#oh_avdemuxer_readsamplebuffer) | - | Reads the sample and related information from the specified track. You must select a track before reading the sample. After this API is called, the demuxer automatically proceeds to the next frame.|
| [OH_AVErrCode OH_AVDemuxer_SeekToTime(OH_AVDemuxer *demuxer, int64_t millisecond, OH_AVSeekMode mode)](#oh_avdemuxer_seektotime) | - | Seeks to the specified time for all the selected tracks based on a seek mode.|
| [OH_AVErrCode OH_AVDemuxer_SetMediaKeySystemInfoCallback(OH_AVDemuxer *demuxer,DRM_MediaKeySystemInfoCallback callback)](#oh_avdemuxer_setmediakeysysteminfocallback) | - | Sets a callback for obtaining the media key system information.|
| [OH_AVErrCode OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback(OH_AVDemuxer *demuxer,Demuxer_MediaKeySystemInfoCallback callback)](#oh_avdemuxer_setdemuxermediakeysysteminfocallback) | - | Sets an asynchronous callback for obtaining the media key system information.|
| [OH_AVErrCode OH_AVDemuxer_GetMediaKeySystemInfo(OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfo *mediaKeySystemInfo)](#oh_avdemuxer_getmediakeysysteminfo) | - | Obtains the media key system information. The media key system information can be obtained only after **Demuxer_MediaKeySystemInfoCallback** or **DRM_MediaKeySystemInfoCallback** is successfully invoked.|

## Function Description

### DRM_MediaKeySystemInfoCallback()

```
typedef void (*DRM_MediaKeySystemInfoCallback)(DRM_MediaKeySystemInfo* mediaKeySystemInfo)
```

**Description**

Defines a pointer to the callback function for DRM_MediaKeySystemInfo. No demuxer instance is returned. This callback function applies to the scenario where a single demuxer instance is used.

You need to call [OH_AVDemuxer_SetMediaKeySystemInfoCallback](#oh_avdemuxer_setdemuxermediakeysysteminfocallback) to set the callback function as a callback.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 11

**Deprecated from**: 14

**Substitute**: [Demuxer_MediaKeySystemInfoCallback](#demuxer_mediakeysysteminfocallback)

### Demuxer_MediaKeySystemInfoCallback()

```
typedef void (*Demuxer_MediaKeySystemInfoCallback)(OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```

**Description**

Defines a pointer to the callback function for **DRM_MediaKeySystemInfo**. A demuxer instance is returned. This callback function applies to the scenario where multiple demuxer instances are used.

You need to call [OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback](#oh_avdemuxer_setdemuxermediakeysysteminfocallback) to set the callback function as a callback. This callback function is recommended.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 12

### OH_AVDemuxer_CreateWithSource()

```
OH_AVDemuxer *OH_AVDemuxer_CreateWithSource(OH_AVSource *source)
```

**Description**

Creates an OH_AVDemuxer instance based on a source instance.

For details about how to create, destroy, and use a source instance, see [OH_AVSource](_a_v_source.md).

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSource](_a_v_source.md#oh_avsource) *source | Pointer to an OH_AVSource instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) * | Pointer to an OH_AVDemuxer instance.<br>If the operation fails, NULL is returned.<br>The possible causes of an operation failure are as follows:<br>1. The value of **source** is invalid, that is, nullptr.<br>2. The value of **source** does not point to an OH_AVSource instance. |

### OH_AVDemuxer_Destroy()

```
OH_AVErrCode OH_AVDemuxer_Destroy(OH_AVDemuxer *demuxer)
```

**Description**

Destroys an OH_AVDemuxer instance and clears internal resources. An instance can be destroyed only once.

The destroyed instance cannot be used until it is re-created. You are advised to set the pointer to NULL after the instance is destroyed.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | Pointer to an OH_AVDemuxer instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The value of **demuxer** is nullptr or does not point to a demuxer instance.|

### OH_AVDemuxer_SelectTrackByID()

```
OH_AVErrCode OH_AVDemuxer_SelectTrackByID(OH_AVDemuxer *demuxer, uint32_t trackIndex)
```

**Description**

Selects a track from which the demuxer reads sample data.

You can select multiple tracks by calling this API multiple times, with a different track index passed in each time.

When [OH_AVDemuxer_ReadSample](#oh_avdemuxer_readsample) is called, only the data in the selected track is read. If the same track is selected multiple times, **AV_ERR_OK** is returned and the API call takes effect only once.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | Pointer to an OH_AVDemuxer instance.|
| uint32_t trackIndex | Index of the track.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**:<br>1. The value of **demuxer** is nullptr or does not point to a demuxer instance.<br>2. The track index is out of range.<br>3. Track reading is not supported.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The demuxer is not correctly initialized.|

### OH_AVDemuxer_UnselectTrackByID()

```
OH_AVErrCode OH_AVDemuxer_UnselectTrackByID(OH_AVDemuxer *demuxer, uint32_t trackIndex)
```

**Description**

Deselects a track. The demuxer no longer reads sample data from a track after it is deselected.

You can deselect multiple tracks by calling this API multiple times, with a different track index passed in each time.

If the same track is deselected multiple times, **AV_ERR_OK** is returned and the API call takes effect only once.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | Pointer to an OH_AVDemuxer instance.|
| uint32_t trackIndex | Index of the track.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The value of **demuxer** is nullptr or does not point to a demuxer instance.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The demuxer is not correctly initialized.|

### OH_AVDemuxer_ReadSample()

```
OH_AVErrCode OH_AVDemuxer_ReadSample(OH_AVDemuxer *demuxer, uint32_t trackIndex,OH_AVMemory *sample, OH_AVCodecBufferAttr *info)
```

**Description**

Reads the sample and related information from the specified track.

You must select a track before reading the sample. After this API is called, the demuxer automatically proceeds to the next frame.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Deprecated from**: 11

**Substitute**: [OH_AVDemuxer_ReadSampleBuffer](#oh_avdemuxer_readsamplebuffer)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | Pointer to an OH_AVDemuxer instance.|
| uint32_t trackIndex | Index of the track from which the compressed frame is to be read.|
| [OH_AVMemory](_core.md#oh_avmemory) *sample | Pointer to the OH_AVMemory instance for storing the compressed frame data.|
| [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) *info | Pointer to the OH_AVCodecBufferAttr instance for storing the compressed frame information.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**:<br>1. The value of **demuxer** is nullptr or does not point to a demuxer instance.<br>2. The track index is out of range.<br>3. Track reading is not supported.<br>4. The value of **sample** is null.<br>5. The value of **info** is null.<br>**AV_ERR_OPERATE_NOT_PERMIT**:<br>1. The track with the specified index is not selected.<br>2. The demuxer is not correctly initialized.<br>**AV_ERR_NO_MEMORY**: The sample capacity is insufficient to store all frame data.<br>**AV_ERR_UNKNOWN**: Failed to read or parse the frame from the file.|

### OH_AVDemuxer_ReadSampleBuffer()

```
OH_AVErrCode OH_AVDemuxer_ReadSampleBuffer(OH_AVDemuxer *demuxer, uint32_t trackIndex,OH_AVBuffer *sample)
```

**Description**

Reads the sample and related information from the specified track.

You can use [OH_AVDemuxer_SelectTrackByID](#oh_avdemuxer_selecttrackbyid) to select a track before reading the sample. After this API is called, the demuxer automatically proceeds to the next frame.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | Pointer to an OH_AVDemuxer instance.|
| uint32_t trackIndex | Index of the track from which the compressed frame is to be read.. |
| [OH_AVBuffer](_core.md#oh_avbuffer) *sample | Pointer to the OH_AVBuffer instance for storing the compressed frame data and related information.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**:<br>1. The value of **demuxer** is nullptr or does not point to a demuxer instance.<br>2. The value of **sample** is nullptr.<br>3. The track index is out of range.<br>4. The value of **sample** is null.<br>**AV_ERR_OPERATE_NOT_PERMIT**:<br>1. The track with the specified index is not selected.<br>2. The demuxer is not correctly initialized.<br>**AV_ERR_NO_MEMORY**: The sample capacity is insufficient to store all frame data.<br>**AV_ERR_UNKNOWN**: Failed to read or parse the frame from the file.|

### OH_AVDemuxer_SeekToTime()

```
OH_AVErrCode OH_AVDemuxer_SeekToTime(OH_AVDemuxer *demuxer, int64_t millisecond, OH_AVSeekMode mode)
```

**Description**

Seeks to the specified time for all the selected tracks based on a [seek mode](capi-native-avcodec-base-h.md#oh_avseekmode).

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | Pointer to an OH_AVDemuxer instance.|
| int64_t millisecond | Time to seek to, in milliseconds. The timestamp is relative to the start position of the file.|
| [OH_AVSeekMode](capi-native-avcodec-base-h.md#oh_avseekmode) mode | Seek mode.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**:<br>1. The value of **demuxer** is nullptr or does not point to a demuxer instance.<br>2. The value of **millisecond** is out of range.<br>**AV_ERR_OPERATE_NOT_PERMIT**:<br>1. The track with the specified index is not selected.<br>2. The demuxer is not correctly initialized.<br>3. The seek operation cannot be performed on the resource.<br>**AV_ERR_UNKNOWN**:<br>1. The seek operation fails.<br>2. **OH_AVSeekMode** is set to **SEEK_MODE_NEXT_SYNC** and there is no I-frame following the specified position.|

### OH_AVDemuxer_SetMediaKeySystemInfoCallback()

```
OH_AVErrCode OH_AVDemuxer_SetMediaKeySystemInfoCallback(OH_AVDemuxer *demuxer,DRM_MediaKeySystemInfoCallback callback)
```

**Description**

Sets a callback for obtaining the media key system information.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 11

**Deprecated from**: 14

**Substitute**: [OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback](#oh_avdemuxer_setdemuxermediakeysysteminfocallback)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | Pointer to an OH_AVDemuxer instance.|
| [DRM_MediaKeySystemInfoCallback](#drm_mediakeysysteminfocallback) callback | Callback function.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The demuxer is not correctly initialized.<br>**AV_ERR_INVALID_VAL**: The value of **demuxer** is nullptr or does not point to a demuxer instance.|

### OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback()

```
OH_AVErrCode OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback(OH_AVDemuxer *demuxer,Demuxer_MediaKeySystemInfoCallback callback)
```

**Description**

Sets a callback for obtaining the media key system information.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | Pointer to an OH_AVDemuxer instance.|
| [Demuxer_MediaKeySystemInfoCallback](#demuxer_mediakeysysteminfocallback) callback | Callback function.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The demuxer is not correctly initialized.<br>**AV_ERR_INVALID_VAL**: The value of **demuxer** is nullptr or does not point to a demuxer instance.|

### OH_AVDemuxer_GetMediaKeySystemInfo()

```
OH_AVErrCode OH_AVDemuxer_GetMediaKeySystemInfo(OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```

**Description**

Obtains the media key system information. The media key system information can be obtained only after [Demuxer_MediaKeySystemInfoCallback](#demuxer_mediakeysysteminfocallback) or [DRM_MediaKeySystemInfoCallback](#drm_mediakeysysteminfocallback) is successfully invoked.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | Pointer to an OH_AVDemuxer instance.|
| [DRM_MediaKeySystemInfo](capi-avdemuxer-drm-mediakeysysteminfo.md) *mediaKeySystemInfo | Pointer to the media key system information.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**:<br>1. The value of **demuxer** is nullptr or does not point to a demuxer instance.<br> 2. The value of **mediaKeySystemInfo** is nullptr.|
