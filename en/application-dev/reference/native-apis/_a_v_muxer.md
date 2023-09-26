# AVMuxer


## Overview

The **AVMuxer** module provides functions for audio and video encapsulation.

\@syscap SystemCapability.Multimedia.Media.Muxer

**Since**

10


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_avmuxer.h](native__avmuxer_8h.md) | Declares native APIs used for audio and video encapsulation.<br>**File to include**: <multimedia/player_framework/native_avmuxer.h><br>**Library**: libnative_media_avmuxer.so| 


### Functions

| Name| Description| 
| -------- | -------- |
| \*[OH_AVMuxer_Create](#oh_avmuxer_create) (int32_t fd, OH_AVOutputFormat format) | Creates an **OH_AVMuxer** instance by using the file descriptor and encapsulation format.| 
| [OH_AVMuxer_SetRotation](#oh_avmuxer_setrotation) (OH_AVMuxer \*muxer, int32_t rotation) | Sets the rotation angle (clockwise) of an output video.| 
| [OH_AVMuxer_AddTrack](#oh_avmuxer_addtrack) (OH_AVMuxer \*muxer, int32_t \*trackIndex, OH_AVFormat \*trackFormat) | Adds a media track to the muxer.| 
| [OH_AVMuxer_Start](#oh_avmuxer_start) (OH_AVMuxer \*muxer) | Starts encapsulation.| 
| [OH_AVMuxer_WriteSample](#oh_avmuxer_writesample) (OH_AVMuxer \*muxer, uint32_t trackIndex, OH_AVMemory \*sample, OH_AVCodecBufferAttr info) | Writes data to the muxer.| 
| [OH_AVMuxer_Stop](#oh_avmuxer_stop) (OH_AVMuxer \*muxer) | Stops encapsulation.| 
| [OH_AVMuxer_Destroy](#oh_avmuxer_destroy) (OH_AVMuxer \*muxer) | Clears internal resources and destroys an **OH_AVMuxer** instance.| 


## Function Description


### OH_AVMuxer_AddTrack()

  
```
OH_AVErrCode OH_AVMuxer_AddTrack (OH_AVMuxer *muxer, int32_t *trackIndex, OH_AVFormat *trackFormat)
```

**Description**

Adds a media track to the muxer.

This function must be called before **OH_AVMuxer_Start**.

\@syscap SystemCapability.Multimedia.Media.Muxer

**Parameters**

  | Name| Description| 
| -------- | -------- |
| muxer | Pointer to an **OH_AVMuxer** instance.| 
| trackIndex | Pointer to the index of the media track. The index will be used in the **OH_AVMuxer_WriteSample** function. If the media track is added, the index value is greater than or equal to 0; otherwise, the value is less than 0.| 
| trackFormat | Pointer to an **OH_AVFormat** instance.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode-1) otherwise.

**Since**

10


### OH_AVMuxer_Create()

  
```
OH_AVMuxer* OH_AVMuxer_Create (int32_t fd, OH_AVOutputFormat format)
```

**Description**

Creates an **OH_AVMuxer** instance by using the file descriptor and encapsulation format.

\@syscap SystemCapability.Multimedia.Media.Muxer

**Parameters**

  | Name| Description| 
| -------- | -------- |
| fd | File descriptor (FD). You must open the file in read/write mode (O_RDWR) and close the file after using it.| 
| format | Format of the encapsulated output file. For details, see [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat).| 

**Returns**

Returns the pointer to the **OH_AVMuxer** instance created. You must call **OH_AVMuxer_Destroy** to destroy the instance when it is no longer needed.

**Since**

10


### OH_AVMuxer_Destroy()

  
```
OH_AVErrCode OH_AVMuxer_Destroy (OH_AVMuxer *muxer)
```

**Description**

Clears internal resources and destroys an **OH_AVMuxer** instance.

\@syscap SystemCapability.Multimedia.Media.Muxer

**Parameters**

  | Name| Description| 
| -------- | -------- |
| muxer | Pointer to an **OH_AVMuxer** instance.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode-1) otherwise. You must set the muxer to null.

**Since**

10


### OH_AVMuxer_SetRotation()

  
```
OH_AVErrCode OH_AVMuxer_SetRotation (OH_AVMuxer *muxer, int32_t rotation)
```

**Description**

Sets the rotation angle (clockwise) of an output video.

This function must be called before **OH_AVMuxer_Start**.

\@syscap SystemCapability.Multimedia.Media.Muxer

**Parameters**

  | Name| Description| 
| -------- | -------- |
| muxer | Pointer to an **OH_AVMuxer** instance.| 
| rotation | Angle to set. The value must be 0, 90, 180, or 270.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode-1) otherwise.

**Since**

10


### OH_AVMuxer_Start()

  
```
OH_AVErrCode OH_AVMuxer_Start (OH_AVMuxer *muxer)
```

**Description**

Starts encapsulation.

This function must be called after **OH_AVMuxer_AddTrack** and before **OH_AVMuxer_WriteSample**.

\@syscap SystemCapability.Multimedia.Media.Muxer

**Parameters**

  | Name| Description| 
| -------- | -------- |
| muxer | Pointer to an **OH_AVMuxer** instance.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode-1) otherwise.

**Since**

10


### OH_AVMuxer_Stop()

  
```
OH_AVErrCode OH_AVMuxer_Stop (OH_AVMuxer *muxer)
```

**Description**

Stops encapsulation.

Once encapsulation is stopped, it cannot be restarted.

\@syscap SystemCapability.Multimedia.Media.Muxer

**Parameters**

  | Name| Description| 
| -------- | -------- |
| muxer | Pointer to an **OH_AVMuxer** instance.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode-1) otherwise.

**Since**

10


### OH_AVMuxer_WriteSample()

  
```
OH_AVErrCode OH_AVMuxer_WriteSample (OH_AVMuxer *muxer, uint32_t trackIndex, OH_AVMemory *sample, OH_AVCodecBufferAttr info)
```

**Description**

Writes data to the muxer.

This function must be called after **OH_AVMuxer_Start** and before **OH_AVMuxer_Stop**. You must ensure that the data is written to the correct media track in ascending order by time.

\@syscap SystemCapability.Multimedia.Media.Muxer

**Parameters**

  | Name| Description| 
| -------- | -------- |
| muxer | Pointer to an **OH_AVMuxer** instance.| 
| trackIndex | Index of the media track corresponding to the data.| 
| sample | Pointer to the buffer that stores the data written (data obtained after encoding or decapsulation).| 
| info | Information about the data written. For details, see [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md).| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode-1) otherwise.

**Since**

10
