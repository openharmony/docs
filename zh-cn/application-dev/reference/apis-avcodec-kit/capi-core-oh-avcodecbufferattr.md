# OH_AVCodecBufferAttr

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhanghongran-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @zengyawen-->

## 概述

定义OH_AVCodec的缓冲区描述信息。

**起始版本：** 9

**相关模块：** [Core](capi-core.md)

**所在头文件：** [native_avbuffer_info.h](capi-native-avbuffer-info-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int64_t pts | 此缓冲区的显示时间戳（以微秒为单位）。 |
| int32_t size | 缓冲区中包含的数据的大小（以字节为单位）。 |
| int32_t offset | 此缓冲区中有效数据的起始偏移量。 |
| uint32_t flags | 此缓冲区具有的标志，请参阅[OH_AVCodecBufferFlags](capi-native-avbuffer-info-h.md#oh_avcodecbufferflags)。 |


