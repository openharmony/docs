# AVPlayerCallback


## 概述

包含了OH_AVPlayerOnInfo和OH_AVPlayerOnInfo回调函数指针的集合。应用需注册此实例结构体到OH_AVPlayer实例中，并对回调上报的信息进行处理，保证AVPlayer的正常运行。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**废弃版本：** 12

**替代接口：**[OH_AVPlayerOnInfoCallback](_a_v_player.md#oh_avplayeroninfocallback) [OH_AVPlayerOnErrorCallback](_a_v_player.md#oh_avplayeronerrorcallback)

**相关模块：**[AVPlayer](_a_v_player.md)

**所在头文件：**[avplayer_base.h](avplayer__base_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [onInfo](_a_v_player.md#oninfo) | 监控AVPlayer过程信息，参考[OH_AVPlayerOnInfo](_a_v_player.md#oh_avplayeroninfo)。 | 
| [onError](_a_v_player.md#onerror) | 监听AVPlayer操作错误，参考[OH_AVPlayerOnError](_a_v_player.md#oh_avplayeronerror)。 | 
