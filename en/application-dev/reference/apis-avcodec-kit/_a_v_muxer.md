# AVMuxer

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @zengyawen-->

## Overview

The AVMuxer module provides the APIs for audio and video multiplexing.

For details about the development guide and sample, see [Media Data Multiplexing](../../media/avcodec/audio-video-muxer.md).

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [native_avmuxer.h](native__avmuxer_8h.md) | Declares the native APIs used for audio and video multiplexing. |


### Types

| Name| Description|
| -------- | -------- |
| typedef struct [OH_AVMuxer](#oh_avmuxer) [OH_AVMuxer](#oh_avmuxer) | Defines a struct for the native object for the muxer interface. |


### Functions

| Name| Description|
| -------- | -------- |
| [OH_AVMuxer](#oh_avmuxer) \* [OH_AVMuxer_Create](#oh_avmuxer_create) (int32_t fd, [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat) format) | Creates an OH_AVMuxer instance by using the file descriptor and container format. |
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_SetRotation](#oh_avmuxer_setrotation) ([OH_AVMuxer](#oh_avmuxer) \*muxer, int32_t rotation) | Sets the rotation angle (clockwise), which must be 0, 90, 180, or 270, of an output video. |
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_SetFormat](#oh_avmuxer_setformat) ([OH_AVMuxer](#oh_avmuxer) \*muxer, [OH_AVFormat](_core.md#oh_avformat) \*format) | Sets format data to the muxer.|
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_AddTrack](#oh_avmuxer_addtrack) ([OH_AVMuxer](#oh_avmuxer) \*muxer, int32_t \*trackIndex, [OH_AVFormat](_core.md#oh_avformat) \*trackFormat) | Adds an audio or video track to a muxer.|
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_Start](#oh_avmuxer_start) ([OH_AVMuxer](#oh_avmuxer) \*muxer) | Starts a muxer.|
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_WriteSample](#oh_avmuxer_writesample) ([OH_AVMuxer](#oh_avmuxer) \*muxer, uint32_t trackIndex, [OH_AVMemory](_core.md#oh_avmemory) \*sample, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) info) | Writes a sample to a muxer. (It is deprecated from API version 11.)|
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_WriteSampleBuffer](#oh_avmuxer_writesamplebuffer) ([OH_AVMuxer](#oh_avmuxer) \*muxer, uint32_t trackIndex, const [OH_AVBuffer](_core.md#oh_avbuffer) \*sample) | Writes a sample to a muxer. |
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_Stop](#oh_avmuxer_stop) ([OH_AVMuxer](#oh_avmuxer) \*muxer) | Stops a muxer. |
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_Destroy](#oh_avmuxer_destroy) ([OH_AVMuxer](#oh_avmuxer) \*muxer) | Clears internal resources and destroys an OH_AVMuxer instance. |


## Type Description


### OH_AVMuxer

```
typedef struct OH_AVMuxer OH_AVMuxer
```
**Description**

Defines a struct for the native object for the muxer interface.

**Since**: 10


## Function Description


### OH_AVMuxer_AddTrack()

```
OH_AVErrCode OH_AVMuxer_AddTrack (OH_AVMuxer *muxer, int32_t *trackIndex, OH_AVFormat *trackFormat)
```

**Description**

Adds an audio or video track to a muxer. 

Each time this function is called, an audio or video track is added to the muxer. This function must be called before **OH_AVMuxer_Start**.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| muxer | Pointer to an OH_AVMuxer instance. |
| trackIndex | Pointer to the index of the media track. The index will be used in the **OH_AVMuxer_WriteSample** function. If the audio or video track is added, the index value is greater than or equal to 0; otherwise, the value is less than 0. |
| trackFormat | Pointer to an OH_AVFormat instance. |

**Returns**

**AV_ERR_OK** if the operation is successful; one of the following error codes defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise:

- **AV_ERR_INVALID_VAL**: The muxer pointer is null, or the track index or track format is invalid. 

- **AV_ERR_OPERATE_NOT_PERMIT**: The function is called out of sequence. 

- **AV_ERR_UNSUPPORT**: The MIME type is not supported. 

- **AV_ERR_NO_MEMORY**: Memory allocation fails. 

- **AV_ERR_UNKNOWN**: Unknown error.


### OH_AVMuxer_Create()

```
OH_AVMuxer* OH_AVMuxer_Create (int32_t fd, OH_AVOutputFormat format)
```

**Description**

Creates an OH_AVMuxer instance by using the file descriptor and container format.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| fd | File descriptor (FD). You must open the file in read/write mode (O_RDWR) and close the file after using it. |
| format | Format of the multiplexed output file. For details, see [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat-1). |

**Returns**

Pointer to the OH_AVMuxer instance created. After the multiplexing process is complete, call **OH_AVMuxer_Destroy** to destroy the instance.


### OH_AVMuxer_Destroy()

```
OH_AVErrCode OH_AVMuxer_Destroy (OH_AVMuxer *muxer)
```

**Description**

Clears internal resources and destroys an OH_AVMuxer instance.

Do not repeatedly destroy the instance. Otherwise, the program may crash.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| muxer | Pointer to an OH_AVMuxer instance. |

**Returns**

**AV_ERR_OK** if the operation is successful, and you must set the muxer to null; one of the following error codes defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise:

- **AV_ERR_INVALID_VAL**: The muxer pointer is null.


### OH_AVMuxer_SetRotation()

```
OH_AVErrCode OH_AVMuxer_SetRotation (OH_AVMuxer *muxer, int32_t rotation)
```

**Description**

Sets the rotation angle (clockwise), which must be 0, 90, 180, or 270, of an output video.

This function must be called before **OH_AVMuxer_Start**.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| muxer | Pointer to an OH_AVMuxer instance. |
| rotation | Angle to set. The value must be 0, 90, 180, or 270. |

**Returns**

**AV_ERR_OK** if the operation is successful; one of the following error codes defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise:

- **AV_ERR_INVALID_VAL**: The muxer pointer is null or the value of **rotation** is invalid.

- **AV_ERR_OPERATE_NOT_PERMIT**: The function is called out of sequence.



### OH_AVMuxer_SetFormat()

```
OH_AVErrCode OH_AVMuxer_SetFormat(OH_AVMuxer *muxer, OH_AVFormat *format)
```
**Description**

Sets format data to the muxer.

Starting from API version 14, setting the creation time via **OH_MD_KEY_CREATION_TIME** is supported. If the setting fails, check whether the value of **OH_MD_KEY_CREATION_TIME** complies with the ISO 8601 standard and whether the UTC time is used.

Starting from API version 20, the following operations are supported:
- Setting the file description via **OH_MD_KEY_COMMENT** is supported. If the setting fails, check whether **OH_MD_KEY_COMMENT** is a string within the range [1, 256].
- Setting the position of the MP4 moov via **OH_MD_KEY_ENABLE_MOOV_FRONT**. If **OH_MD_KEY_ENABLE_MOOV_FRONT** is set to **0**, moov is placed at the end. If it is set to **1**, moov is placed at the front. By default, moov is placed at the end.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 14

**Parameters**

| Name| Description|
| -------- | -------- |
| muxer | Pointer to an OH_AVMuxer instance. |
| format | Pointer to an OH_AVFormat instance. It is a file-level metadata set. |

**Returns**

- **AV_ERR_OK**: The **format** parameter is correctly set.

- **AV_ERR_INVALID_VAL**: The muxer pointer is null or the value of **format** is invalid.

- **AV_ERR_OPERATE_NOT_PERMIT**: The function is called out of sequence.

### OH_AVMuxer_Start()

```
OH_AVErrCode OH_AVMuxer_Start (OH_AVMuxer *muxer)
```

**Description**

Starts a muxer. 

This function must be called after **OH_AVMuxer_AddTrack** and before **OH_AVMuxer_WriteSample**.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| muxer | Pointer to an OH_AVMuxer instance. |

**Returns**

**AV_ERR_OK** if the operation is successful; one of the following error codes defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise:

- **AV_ERR_INVALID_VAL**: The muxer pointer is null. 

- **AV_ERR_OPERATE_NOT_PERMIT**: The function is called out of sequence. 

- **AV_ERR_UNKNOWN**: Unknown error.

### OH_AVMuxer_Stop()

```
OH_AVErrCode OH_AVMuxer_Stop (OH_AVMuxer *muxer)
```

**Description**

Stops a muxer. 

Once the muxer is stopped, it cannot be restarted.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| muxer | Pointer to an OH_AVMuxer instance. |

**Returns**

**AV_ERR_OK** if the operation is successful; one of the following error codes defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise:

- **AV_ERR_INVALID_VAL**: The muxer pointer is null. 

- **AV_ERR_OPERATE_NOT_PERMIT**: The function is called out of sequence.


### OH_AVMuxer_WriteSample()

```
OH_AVErrCode OH_AVMuxer_WriteSample (OH_AVMuxer *muxer, uint32_t trackIndex, OH_AVMemory *sample, OH_AVCodecBufferAttr info)
```

**Description**

Writes a sample to a muxer. 

This function must be called after **OH_AVMuxer_Start** and before **OH_AVMuxer_Stop**. The caller must write the sample to the correct audio or video track based on the timing in **info**.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Deprecated from**: 11

**Substitute API**: [OH_AVMuxer_WriteSampleBuffer](#oh_avmuxer_writesamplebuffer)

**Parameters**

| Name| Description|
| -------- | -------- |
| muxer | Pointer to an OH_AVMuxer instance. |
| trackIndex | Index of the audio or video track corresponding to the data. |
| sample | Pointer to the data obtained after encoding or demultiplexing. |
| info | Sample description. For details, see [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md). |

**Returns**

**AV_ERR_OK** if the operation is successful; one of the following error codes defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise:

- **AV_ERR_INVALID_VAL**: The muxer pointer is null, or the track index, sample, or info is invalid. 

- **AV_ERR_OPERATE_NOT_PERMIT**: The function is called out of sequence.

- **AV_ERR_NO_MEMORY**: Memory allocation fails.

- **AV_ERR_UNKNOWN**: Unknown error.


### OH_AVMuxer_WriteSampleBuffer()

```
OH_AVErrCode OH_AVMuxer_WriteSampleBuffer (OH_AVMuxer *muxer, uint32_t trackIndex, const OH_AVBuffer *sample)
```

**Description**

Writes a sample to a muxer. 

This function must be called after **OH_AVMuxer_Start** and before **OH_AVMuxer_Stop**. The caller must write the sample to the correct audio or video track based on the timing in **sample**.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| muxer | Pointer to an OH_AVMuxer instance. |
| trackIndex | Index of the audio or video track corresponding to the data. |
| sample | Pointer to the data and properties obtained after encoding or demultiplexing. |

**Returns**

**AV_ERR_OK** if the operation is successful; one of the following error codes defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise:

- **AV_ERR_INVALID_VAL**: The muxer pointer is null, or the track index or sample is invalid.

- **AV_ERR_OPERATE_NOT_PERMIT**: The function is called out of sequence.

- **AV_ERR_NO_MEMORY**: Memory allocation fails.

- **AV_ERR_UNKNOWN**: Unknown error.
