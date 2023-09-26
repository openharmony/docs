# native_avdemuxer.h


## 概述

声明用于音视频解封装的Native API。

**起始版本：**

10

**相关模块：**

[AVDemuxer](_a_v_demuxer.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_AVDemuxer_CreateWithSource](_a_v_demuxer.md#oh_avdemuxer_createwithsource) (OH_AVSource \*source) | 通过source实例对象创建OH_AVDemuxer实例对象。 | 
| [OH_AVDemuxer_Destroy](_a_v_demuxer.md#oh_avdemuxer_destroy) (OH_AVDemuxer \*demuxer) | 销毁OH_AVDemuxer实例并清理内部资源。 | 
| [OH_AVDemuxer_SelectTrackByID](_a_v_demuxer.md#oh_avdemuxer_selecttrackbyid) (OH_AVDemuxer \*demuxer, uint32_t trackIndex) | 选中指定轨道，解封装器将会从该轨道中读取数据。 | 
| [OH_AVDemuxer_UnselectTrackByID](_a_v_demuxer.md#oh_avdemuxer_unselecttrackbyid) (OH_AVDemuxer \*demuxer, uint32_t trackIndex) | 取消选择指定轨道，未选中的轨道的数据不会被解封装器读取。 | 
| [OH_AVDemuxer_ReadSample](_a_v_demuxer.md#oh_avdemuxer_readsample) (OH_AVDemuxer \*demuxer, uint32_t trackIndex, OH_AVMemory \*sample, OH_AVCodecBufferAttr \*info) | 从选中轨道中获取当前位置压缩帧及相关信息。 | 
| [OH_AVDemuxer_SeekToTime](_a_v_demuxer.md#oh_avdemuxer_seektotime) (OH_AVDemuxer \*demuxer, int64_t millisecond, OH_AVSeekMode mode) | 根据设定的跳转模式，将所有选中的轨道到指定时间附近。 | 
