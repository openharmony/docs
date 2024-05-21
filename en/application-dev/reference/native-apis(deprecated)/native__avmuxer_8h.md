# native_avmuxer.h


## Overview

The **native_avmuxer.h** file declares native APIs used for audio and video encapsulation.

**Since**

10

**Related Modules**

[AVMuxer](_a_v_muxer.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| \*[OH_AVMuxer_Create](_a_v_muxer.md#oh_avmuxer_create) (int32_t fd, OH_AVOutputFormat format) | Creates an **OH_AVMuxer** instance by using the file descriptor and encapsulation format.| 
| [OH_AVMuxer_SetRotation](_a_v_muxer.md#oh_avmuxer_setrotation) (OH_AVMuxer \*muxer, int32_t rotation) | Sets the rotation angle (clockwise) of an output video.| 
| [OH_AVMuxer_AddTrack](_a_v_muxer.md#oh_avmuxer_addtrack) (OH_AVMuxer \*muxer, int32_t \*trackIndex, OH_AVFormat \*trackFormat) | Adds a media track to the muxer.| 
| [OH_AVMuxer_Start](_a_v_muxer.md#oh_avmuxer_start) (OH_AVMuxer \*muxer) | Starts encapsulation.| 
| [OH_AVMuxer_WriteSample](_a_v_muxer.md#oh_avmuxer_writesample) (OH_AVMuxer \*muxer, uint32_t trackIndex, OH_AVMemory \*sample, OH_AVCodecBufferAttr info) | Writes data to the muxer.| 
| [OH_AVMuxer_Stop](_a_v_muxer.md#oh_avmuxer_stop) (OH_AVMuxer \*muxer) | Stops encapsulation.| 
| [OH_AVMuxer_Destroy](_a_v_muxer.md#oh_avmuxer_destroy) (OH_AVMuxer \*muxer) | Clears internal resources and destroys an **OH_AVMuxer** instance.| 
