# AVMuxer


## Overview

The AVMuxer module provides the functions for audio and video muxing.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_avmuxer.h](native__avmuxer_8h.md) | Declares the native APIs used for audio and video muxing. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_AVMuxer](#oh_avmuxer) [OH_AVMuxer](#oh_avmuxer) | Defines a struct that describes a native object for the muxer interface. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AVMuxer](#oh_avmuxer) \* [OH_AVMuxer_Create](#oh_avmuxer_create) (int32_t fd, [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat) format) | Creates an **OH_AVMuxer** instance by using the file descriptor and container format. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_SetRotation](#oh_avmuxer_setrotation) ([OH_AVMuxer](#oh_avmuxer) \*muxer, int32_t rotation) | Sets the rotation angle (clockwise) of an output video. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_AddTrack](#oh_avmuxer_addtrack) ([OH_AVMuxer](#oh_avmuxer) \*muxer, int32_t \*trackIndex, [OH_AVFormat](_core.md#oh_avformat) \*trackFormat) | Adds a media track to the muxer.| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_Start](#oh_avmuxer_start) ([OH_AVMuxer](#oh_avmuxer) \*muxer) | Starts the muxer.| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_WriteSample](#oh_avmuxer_writesample) ([OH_AVMuxer](#oh_avmuxer) \*muxer, uint32_t trackIndex, [OH_AVMemory](_core.md#oh_avmemory) \*sample, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) info) | Writes data to the muxer.| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_WriteSampleBuffer](#oh_avmuxer_writesamplebuffer) ([OH_AVMuxer](#oh_avmuxer) \*muxer, uint32_t trackIndex, const [OH_AVBuffer](_core.md#oh_avbuffer) \*sample) | Writes data to the muxer. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_Stop](#oh_avmuxer_stop) ([OH_AVMuxer](#oh_avmuxer) \*muxer) | Stops the muxer. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_Destroy](#oh_avmuxer_destroy) ([OH_AVMuxer](#oh_avmuxer) \*muxer) | Clears internal resources and destroys an **OH_AVMuxer** instance. | 


## Type Description


### OH_AVMuxer

```
typedef struct OH_AVMuxer OH_AVMuxer
```
**Description**

Defines a struct that describes a native object for the muxer interface.

**Since**: 10


## Function Description


### OH_AVMuxer_AddTrack()

```
OH_AVErrCode OH_AVMuxer_AddTrack (OH_AVMuxer *muxer, int32_t *trackIndex, OH_AVFormat *trackFormat)
```

**Description**

Adds a media track to the muxer.

This function must be called before **OH_AVMuxer_Start**.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| muxer | Pointer to an **OH_AVMuxer** instance. | 
| trackIndex | Pointer to the index of the media track. The index will be used in the **OH_AVMuxer_WriteSample** function. If the media track is added, the index value is greater than or equal to 0; otherwise, the value is less than 0. | 
| trackFormat | Pointer to an **OH_AVFormat** instance. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the muxer pointer is null, or the track index or track format is invalid. **AV_ERR_OPERATE_NOT_PERMIT** is returned if the function is called in an invalid state. **AV_ERR_UNSUPPORT** is returned if the MIME type is not supported. **AV_ERR_NO_MEMORY** is returned if memory allocation fails. **AV_ERR_UNKNOWN** is returned in the case of an unknown error.


### OH_AVMuxer_Create()

```
OH_AVMuxer* OH_AVMuxer_Create (int32_t fd, OH_AVOutputFormat format)
```

**Description**

Creates an **OH_AVMuxer** instance by using the file descriptor and container format.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| fd | File descriptor (FD). You must open the file in read/write mode (O_RDWR) and close the file after using it. | 
| format | Format of the encapsulated output file. For details, see [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat). | 

**Returns**

Returns the pointer to the **OH_AVMuxer** instance created. You must call **OH_AVMuxer_Destroy** to destroy the instance when it is no longer needed.


### OH_AVMuxer_Destroy()

```
OH_AVErrCode OH_AVMuxer_Destroy (OH_AVMuxer *muxer)
```

**Description**

Clears internal resources and destroys an **OH_AVMuxer** instance.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| muxer | Pointer to an **OH_AVMuxer** instance. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise. You must set the muxer to null.

**AV_ERR_INVALID_VAL** is returned if the muxer pointer is null.


### OH_AVMuxer_SetRotation()

```
OH_AVErrCode OH_AVMuxer_SetRotation (OH_AVMuxer *muxer, int32_t rotation)
```

**Description**

Sets the rotation angle (clockwise) of an output video.

This function must be called before **OH_AVMuxer_Start**.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| muxer | Pointer to an **OH_AVMuxer** instance. | 
| rotation | Angle to set. The value must be 0, 90, 180, or 270. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** if the muxer pointer is null or the value of **rotation** is invalid. **AV_ERR_OPERATE_NOT_PERMIT** is returned if the function is called in an invalid state.


### OH_AVMuxer_Start()

```
OH_AVErrCode OH_AVMuxer_Start (OH_AVMuxer *muxer)
```

**Description**

Starts the muxer.

This function must be called after **OH_AVMuxer_AddTrack** and before **OH_AVMuxer_WriteSample**.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| muxer | Pointer to an **OH_AVMuxer** instance. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the muxer pointer is null. **AV_ERR_OPERATE_NOT_PERMIT** is returned if the function is called in an invalid state. **AV_ERR_UNKNOWN** is returned in the case of an unknown error.


### OH_AVMuxer_Stop()

```
OH_AVErrCode OH_AVMuxer_Stop (OH_AVMuxer *muxer)
```

**Description**

Stops the muxer.

Once the muxer is stopped, it cannot be restarted.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| muxer | Pointer to an **OH_AVMuxer** instance. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the muxer pointer is null. **AV_ERR_OPERATE_NOT_PERMIT** is returned if the function is called in an invalid state.


### OH_AVMuxer_WriteSample()

```
OH_AVErrCode OH_AVMuxer_WriteSample (OH_AVMuxer *muxer, uint32_t trackIndex, OH_AVMemory *sample, OH_AVCodecBufferAttr info)
```

**Description**

Writes data to the muxer.

This function must be called after **OH_AVMuxer_Start** and before **OH_AVMuxer_Stop**. You must ensure that the data is written to the correct media track in ascending order by time.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Deprecated from**: 11

**Substitute API**: [OH_AVMuxer_WriteSampleBuffer](#oh_avmuxer_writesamplebuffer)

**Parameters**

| Name| Description| 
| -------- | -------- |
| muxer | Pointer to an **OH_AVMuxer** instance. | 
| trackIndex | Index of the media track corresponding to the data. | 
| sample | Pointer to the buffer that stores the data written (data obtained after encoding or demuxing). | 
| info | Information about the data written. For details, see **OH_AVCodecBufferAttr**. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the muxer pointer is null, or the track index, sample, or info is invalid. **AV_ERR_OPERATE_NOT_PERMIT** is returned if the function is called in an invalid state. **AV_ERR_NO_MEMORY** is returned if memory allocation fails. **AV_ERR_UNKNOWN** is returned in the case of an unknown error.


### OH_AVMuxer_WriteSampleBuffer()

```
OH_AVErrCode OH_AVMuxer_WriteSampleBuffer (OH_AVMuxer *muxer, uint32_t trackIndex, const OH_AVBuffer *sample)
```

**Description**

Writes data to the muxer.

This function must be called after **OH_AVMuxer_Start** and before **OH_AVMuxer_Stop**. You must ensure that the data is written to the correct media track in ascending order by time.

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| muxer | Pointer to an **OH_AVMuxer** instance. | 
| trackIndex | Index of the media track corresponding to the data. | 
| sample | Pointer to the buffer that stores the data written (data obtained after encoding or demuxing). Data and data attributes are included. | 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**AV_ERR_INVALID_VAL** is returned if the muxer pointer is null, or the track index or sample is invalid. **AV_ERR_OPERATE_NOT_PERMIT** is returned if the function is called in an invalid state. **AV_ERR_NO_MEMORY** is returned if memory allocation fails. **AV_ERR_UNKNOWN** is returned in the case of an unknown error.
