# native_avmuxer.h

## Overview

The file declares the native APIs used for audio and video multiplexing.

**File to include**: <multimedia/player_framework/native_avmuxer.h>

**Library**: libnative_media_avmuxer.so

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Related module**: [AVMuxer](capi-avmuxer.md)

**Sample**: [AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) | OH_AVMuxer | Describes a native object for the muxer interface.|

### Functions

| Name| Description|
| -- | -- |
| [OH_AVMuxer *OH_AVMuxer_Create(int32_t fd, OH_AVOutputFormat format)](#oh_avmuxer_create) | Creates an OH_AVMuxer instance by using the file descriptor and container format.|
| [OH_AVErrCode OH_AVMuxer_SetRotation(OH_AVMuxer *muxer, int32_t rotation)](#oh_avmuxer_setrotation) | Sets the rotation angle (clockwise) of an output video. Note: This function must be called before [OH_AVMuxer_Start](#oh_avmuxer_start).|
| [OH_AVErrCode OH_AVMuxer_SetFormat(OH_AVMuxer *muxer, OH_AVFormat *format)](#oh_avmuxer_setformat) | Sets format data to the muxer. Note: Currently, only **OH_MD_KEY_CREATION_TIME** can be set. If the setting fails, check whether the value of **OH_MD_KEY_CREATION_TIME** complies with the ISO 8601 standard and whether the UTC time is used.|
| [OH_AVErrCode OH_AVMuxer_AddTrack(OH_AVMuxer *muxer, int32_t *trackIndex, OH_AVFormat *trackFormat)](#oh_avmuxer_addtrack) | Adds an audio or video track to a muxer. Note: This function must be called before [OH_AVMuxer_Start](#oh_avmuxer_start).|
| [OH_AVErrCode OH_AVMuxer_Start(OH_AVMuxer *muxer)](#oh_avmuxer_start) | Starts a muxer. Note: This function must be called after **OH_AVMuxer_AddTrack** and before **OH_AVMuxer_WriteSample**.|
| [OH_AVErrCode OH_AVMuxer_WriteSample(OH_AVMuxer *muxer, uint32_t trackIndex, OH_AVMemory *sample, OH_AVCodecBufferAttr info)](#oh_avmuxer_writesample) | Writes a sample to a muxer. Note: This function must be called after **OH_AVMuxer_Start** and before **OH_AVMuxer_Stop**. You must ensure that the data is written to the correct media track in ascending order by time.|
| [OH_AVErrCode OH_AVMuxer_WriteSampleBuffer(OH_AVMuxer *muxer, uint32_t trackIndex, const OH_AVBuffer *sample)](#oh_avmuxer_writesamplebuffer) | Writes a sample to a muxer. Note: This function must be called after **OH_AVMuxer_Start** and before **OH_AVMuxer_Stop**. You must ensure that the data is written to the correct media track in ascending order by time.|
| [OH_AVErrCode OH_AVMuxer_Stop(OH_AVMuxer *muxer)](#oh_avmuxer_stop) | Stops a muxer. Note: Once the muxer is stopped, it cannot be restarted.|
| [OH_AVErrCode OH_AVMuxer_Destroy(OH_AVMuxer *muxer)](#oh_avmuxer_destroy) | Clears internal resources and destroys an OH_AVMuxer instance.|

## Function Description

### OH_AVMuxer_Create()

```
OH_AVMuxer *OH_AVMuxer_Create(int32_t fd, OH_AVOutputFormat format)
```

**Description**

Creates an OH_AVMuxer instance by using the file descriptor and container format.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| int32_t fd | File descriptor (FD). You must open the file in read/write mode (O_RDWR) and close the file after using it.|
| [OH_AVOutputFormat](capi-native-avcodec-base-h.md#oh_avoutputformat) format | Format of the multiplexed output file.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) * | Pointer to the **OH_AVMuxer** instance created. You must call **OH_AVMuxer_Destroy** to destroy the instance when it is no longer needed.|

### OH_AVMuxer_SetRotation()

```
OH_AVErrCode OH_AVMuxer_SetRotation(OH_AVMuxer *muxer, int32_t rotation)
```

**Description**

Sets the rotation angle (clockwise), which must be 0, 90, 180, or 270, of an output video. This function must be called before [OH_AVMuxer_Start](#oh_avmuxer_start).

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | Pointer to an OH_AVMuxer instance.|
| int32_t rotation | Angle to set. The value must be 0, 90, 180, or 270.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The muxer pointer is null or the value of **rotation** is invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The function is called out of sequence.|

### OH_AVMuxer_SetFormat()

```
OH_AVErrCode OH_AVMuxer_SetFormat(OH_AVMuxer *muxer, OH_AVFormat *format)
```

**Description**

Sets format data to the muxer.

Starting from API version 14, setting the creation time via **OH_MD_KEY_CREATION_TIME** is supported. If the setting fails, check whether the value of **OH_MD_KEY_CREATION_TIME** complies with the ISO 8601 standard and whether the UTC time is used.

Starting from API version 20, the following operations are supported:

- Setting the file description via **OH_MD_KEY_COMMENT** is supported. If the setting fails, check whether **OH_MD_KEY_COMMENT** is a string within the range [1, 256].
- Setting the position of the MP4 moov via **OH_MD_KEYENABLE_MOOV_FRONT**. If **OH_MD_KEYENABLE_MOOV_FRONT** is set to **0**, moov is placed at the end. If it is set to **1**, moov is placed at the front. By default, moov is placed at the end.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | Pointer to an OH_AVMuxer instance.|
| [OH_AVFormat](_core.md#oh_avformat) *format | Pointer to an OH_AVFormat instance. It is a file-level metadata set.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK**: The **format** parameter is correctly set.<br>**AV_ERR_INVALID_VAL**: The muxer pointer is null or the value of **format** is invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The function is called out of sequence.|

### OH_AVMuxer_AddTrack()

```
OH_AVErrCode OH_AVMuxer_AddTrack(OH_AVMuxer *muxer, int32_t *trackIndex, OH_AVFormat *trackFormat)
```

**Description**

Adds an audio or video track to a muxer. Each time this function is called, an audio or video track is added to the muxer. This function must be called before [OH_AVMuxer_Start](#oh_avmuxer_start).

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | Pointer to an OH_AVMuxer instance.|
| int32_t *trackIndex | Pointer to the index of the media track. The index will be used in the [OH_AVMuxer_WriteSample](#oh_avmuxer_writesample) function. If the media track is added, the index value is greater than or equal to 0; otherwise, the value is less than 0.|
| [OH_AVFormat](_core.md#oh_avformat) *trackFormat | Pointer to an OH_AVFormat instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The muxer pointer is null, or the track index or track format is invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The function is called out of sequence.<br>**AV_ERR_UNSUPPORT**: The MIME type is not supported.<br>**AV_ERR_NO_MEMORY**: Memory allocation fails.<br>**AV_ERR_UNKNOWN**: An unknown error occurs.|

### OH_AVMuxer_Start()

```
OH_AVErrCode OH_AVMuxer_Start(OH_AVMuxer *muxer)
```

**Description**

Starts a muxer. This function must be called after [OH_AVMuxer_AddTrack](#oh_avmuxer_addtrack) and before [OH_AVMuxer_WriteSample](#oh_avmuxer_writesample).

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | Pointer to an OH_AVMuxer instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The muxer pointer is null.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The function is called out of sequence.<br>**AV_ERR_UNKNOWN**: An unknown error occurs.|

### OH_AVMuxer_WriteSample()

```
OH_AVErrCode OH_AVMuxer_WriteSample(OH_AVMuxer *muxer, uint32_t trackIndex, OH_AVMemory *sample, OH_AVCodecBufferAttr info)
```

**Description**

Writes a sample to a muxer. This function must be called after [OH_AVMuxer_Start](#oh_avmuxer_start) and before [OH_AVMuxer_Stop](#oh_avmuxer_stop). The caller must write the sample to the correct audio or video track based on the timing in **info**.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Deprecated from**: 11

**Substitute**: [OH_AVMuxer_WriteSampleBuffer](capi-native-avmuxer-h.md#oh_avmuxer_writesamplebuffer)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | Pointer to an OH_AVMuxer instance.|
| uint32_t trackIndex | Index of the audio or video track corresponding to the data.|
| [OH_AVMemory](_core.md#oh_avmemory) *sample | Pointer to the data obtained after encoding or demultiplexing.|
| [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) info | Sample description.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The muxer pointer is null, or the track index, sample, or info is invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The function is called out of sequence.<br>**AV_ERR_NO_MEMORY**: Memory allocation fails.<br>**AV_ERR_UNKNOWN**: An unknown error occurs.|

### OH_AVMuxer_WriteSampleBuffer()

```
OH_AVErrCode OH_AVMuxer_WriteSampleBuffer(OH_AVMuxer *muxer, uint32_t trackIndex, const OH_AVBuffer *sample)
```

**Description**

Writes a sample to a muxer. This function must be called after [OH_AVMuxer_Start](#oh_avmuxer_start) and before [OH_AVMuxer_Stop](#oh_avmuxer_stop). The caller must write the sample to the correct audio or video track based on the timing in **sample**.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | Pointer to an OH_AVMuxer instance.|
| uint32_t trackIndex | Index of the audio or video track corresponding to the data.|
| const [OH_AVBuffer](_core.md#oh_avbuffer) *sample | Pointer to the data and properties obtained after encoding or demultiplexing.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The muxer pointer is null, or the track index or sample is invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The function is called out of sequence.<br>**AV_ERR_NO_MEMORY**: Memory allocation fails.<br>**AV_ERR_UNKNOWN**: An unknown error occurs.|

### OH_AVMuxer_Stop()

```
OH_AVErrCode OH_AVMuxer_Stop(OH_AVMuxer *muxer)
```

**Description**

Stops a muxer. Once the muxer is stopped, it cannot be restarted.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | Pointer to an OH_AVMuxer instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The muxer pointer is null.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The function is called out of sequence.|

### OH_AVMuxer_Destroy()

```
OH_AVErrCode OH_AVMuxer_Destroy(OH_AVMuxer *muxer)
```

**Description**

Clears internal resources and destroys an OH_AVMuxer instance.

Do not repeatedly destroy the instance. Otherwise, the program may crash.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | Pointer to an OH_AVMuxer instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK** if the operation is successful, and you must set the muxer to null; one of the following error codes otherwise:<br>**AV_ERR_INVALID_VAL**: The muxer pointer is null.|
