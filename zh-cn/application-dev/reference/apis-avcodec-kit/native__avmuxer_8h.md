# native_avmuxer.h


## 概述

声明用于音视频封装的Native API。

**库：** libnative_media_avmuxer.so

**引用文件：** <multimedia/player_framework/native_avmuxer.h>

**起始版本：** 10

**相关模块：**[AVMuxer](_a_v_muxer.md)


## 汇总

 
### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) [OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) | 定义封装接口native层对象类型。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \* [OH_AVMuxer_Create](_a_v_muxer.md#oh_avmuxer_create) (int32_t fd, [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat) format) | 通过文件描述符fd和封装格式创建OH_AVMuxer实例。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_SetRotation](_a_v_muxer.md#oh_avmuxer_setrotation) ([OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \*muxer, int32_t rotation) | 设置视频的旋转角度（顺时针，且旋转角度必须为0、90、180或270）。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_SetFormat](_a_v_muxer.md#oh_avmuxer_setformat) ([OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \*muxer, [OH_AVFormat](_core.md#oh_avformat) \*format) | 设置format数据到封装器。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_AddTrack](_a_v_muxer.md#oh_avmuxer_addtrack) ([OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \*muxer, int32_t \*trackIndex, [OH_AVFormat](_core.md#oh_avformat) \*trackFormat) | 向封装器添加音视频轨。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_Start](_a_v_muxer.md#oh_avmuxer_start) ([OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \*muxer) | 开始封装。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_WriteSample](_a_v_muxer.md#oh_avmuxer_writesample) ([OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \*muxer, uint32_t trackIndex, [OH_AVMemory](_core.md#oh_avmemory) \*sample, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) info) | 将sample写入封装器。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_WriteSampleBuffer](_a_v_muxer.md#oh_avmuxer_writesamplebuffer) ([OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \*muxer, uint32_t trackIndex, const [OH_AVBuffer](_core.md#oh_avbuffer) \*sample) | 将sample写入封装器。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_Stop](_a_v_muxer.md#oh_avmuxer_stop) ([OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \*muxer) | 停止封装。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_Destroy](_a_v_muxer.md#oh_avmuxer_destroy) ([OH_AVMuxer](_a_v_muxer.md#oh_avmuxer) \*muxer) | 清理内部资源，销毁OH_AVMuxer实例。 | 
