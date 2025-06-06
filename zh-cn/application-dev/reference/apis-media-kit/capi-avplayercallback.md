# AVPlayerCallback

## 概述

包含了OH_AVPlayerOnInfo和OH_AVPlayerOnInfo回调函数指针的集合。应用需注册此实例结构体到OH_AVPlayer实例中，并对回调上报的信息进行处理，保证AVPlayer的正常运行。

**起始版本：** 11

**废弃版本：** 12

**替代接口：** [OH_AVPlayerOnInfoCallback](capi-avplayer-base-h.md#oh_avplayeroninfocallback) [OH_AVPlayerOnErrorCallback](capi-avplayer-base-h.md#oh_avplayeronerrorcallback)

**相关模块：** [AVPlayer](capi-avplayer.md)

**所在头文件：** [avplayer_base.h](capi-avplayer-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| OH_AVPlayerOnInfo onInfo | 监控AVPlayer过程信息，参考[OH_AVPlayerOnInfo](capi-avplayer-base-h.md#oh_avplayeroninfo)。<br>**起始版本：** 11<br>**废弃版本：** 12<br>**替代接口：** [OH_AVPlayerOnInfoCallback](capi-avplayer-base-h.md#oh_avplayeroninfocallback) |
| OH_AVPlayerOnError onError | 监控AVPlayer操作错误，参考[OH_AVPlayerOnError](capi-avplayer-base-h.md#oh_avplayeronerror)。<br>**起始版本：** 11<br>**废弃版本：** 12<br>**替代接口：** [OH_AVPlayerOnErrorCallback](capi-avplayer-base-h.md#oh_avplayeronerrorcallback) |


