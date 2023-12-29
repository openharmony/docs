# AVPlayerCallback


## 概述

OH_AVPlayer中所有回调函数指针的集合。注册此的实例结构体到OH_AVPlayer实例中，并对回调上报的信息进行处理，保证AVPlayer的正常运行。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**起始版本：** 11

**相关模块：**[AVPlayer](_a_v_player.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [onInfo](_a_v_player.md#oninfo) | 监控AVPlayer过程信息，参考[OH_AVPlayerOnInfo](_a_v_player.md#oh_avplayeroninfo)。 | 
| [onError](_a_v_player.md#onerror) | 监听AVPlayer操作错误，参考[OH_AVPlayerOnError](_a_v_player.md#oh_avplayeronerror)。 | 
