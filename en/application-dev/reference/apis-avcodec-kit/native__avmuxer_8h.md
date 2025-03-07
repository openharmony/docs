# native_avmuxer.h


## Overview

The **native_avmuxer.h** file declares the native APIs used for audio and video muxing.

**Library**: libnative_media_avmuxer.so

**Since**: 10

**Related module**: [AVMuxer](_a_v_muxer.md)


## Summary

 
### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) [OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) | Defines a struct that describes a native object for the muxer interface. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \* [OH_AVMuxer_Create](_a_v_muxer.md#oh_avmuxer_create) (int32_t fd, [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat) format) | Creates an **OH_AVMuxer** instance by using the file descriptor and container format. | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_SetRotation](_a_v_muxer.md#oh_avmuxer_setrotation) ([OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \*muxer, int32_t rotation) | Sets the rotation angle (clockwise), which must be 0, 90, 180, or 270, of an output video.| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_SetFormat](_a_v_muxer.md#oh_avmuxer_setformat) ([OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \*muxer, [OH_AVFormat](_core.md#oh_avformat) \*format) | Sets format data to the muxer.| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_AddTrack](_a_v_muxer.md#oh_avmuxer_addtrack) ([OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \*muxer, int32_t \*trackIndex, [OH_AVFormat](_core.md#oh_avformat) \*trackFormat) | Adds an audio or video track to a muxer.| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_Start](_a_v_muxer.md#oh_avmuxer_start) ([OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \*muxer) | Starts a muxer.| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_WriteSample](_a_v_muxer.md#oh_avmuxer_writesample) ([OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \*muxer, uint32_t trackIndex, [OH_AVMemory](_core.md#oh_avmemory) \*sample, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) info) | Writes a sample to a muxer.| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_WriteSampleBuffer](_a_v_muxer.md#oh_avmuxer_writesamplebuffer) ([OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \*muxer, uint32_t trackIndex, const [OH_AVBuffer](_core.md#oh_avbuffer) \*sample) | Writes a sample to a muxer.| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_Stop](_a_v_muxer.md#oh_avmuxer_stop) ([OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \*muxer) | Stops a muxer.| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_Destroy](_a_v_muxer.md#oh_avmuxer_destroy) ([OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \*muxer) | Clears internal resources and destroys an **OH_AVMuxer** instance.| 
