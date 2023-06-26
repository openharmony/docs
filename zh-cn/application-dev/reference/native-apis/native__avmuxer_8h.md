# native_avmuxer.h


## 概述

声明用于音视频封装的Native API。

**起始版本：**

10

**相关模块:**

[AVMuxer](_a_v_muxer.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_AVMuxer_Create](_a_v_muxer.md#oh_avmuxer_create) (int32_t fd, OH_AVOutputFormat format) | 通过文件描述符fd和封装格式创建OH_AVMuxer实例。 | 
| [OH_AVMuxer_SetRotation](_a_v_muxer.md#oh_avmuxer_setrotation) (OH_AVMuxer \*muxer, int32_t rotation) | 设置视频的旋转角度（顺时针）。 | 
| [OH_AVMuxer_AddTrack](_a_v_muxer.md#oh_avmuxer_addtrack) (OH_AVMuxer \*muxer, int32_t \*trackIndex, OH_AVFormat \*trackFormat) | 向封装器添加媒体轨。 | 
| [OH_AVMuxer_Start](_a_v_muxer.md#oh_avmuxer_start) (OH_AVMuxer \*muxer) | 开始封装。 | 
| [OH_AVMuxer_WriteSample](_a_v_muxer.md#oh_avmuxer_writesample) (OH_AVMuxer \*muxer, uint32_t trackIndex, OH_AVMemory \*sample, OH_AVCodecBufferAttr info) | 将数据写入封装器。 | 
| [OH_AVMuxer_Stop](_a_v_muxer.md#oh_avmuxer_stop) (OH_AVMuxer \*muxer) | 停止封装。 | 
| [OH_AVMuxer_Destroy](_a_v_muxer.md#oh_avmuxer_destroy) (OH_AVMuxer \*muxer) | 清理内部资源，销毁OH_AVMuxer实例。 | 