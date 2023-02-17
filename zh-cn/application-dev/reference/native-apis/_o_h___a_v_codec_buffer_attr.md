# OH_AVCodecBufferAttr


## 概述

定义OH_AVCodec的Buffer描述信息。

@syscap SystemCapability.Multimedia.Media.CodecBase

**起始版本：**
9

**相关模块:**

[CodecBase](_codec_base.md)


## 汇总


### 成员变量

  | 名称 | 描述 | 
| -------- | -------- |
| [pts](_codec_base.md#pts) | 以微秒为单位表示的该Buffer的Presentation时间戳 | 
| [size](_codec_base.md#size) | 以字节为单位表示的该Buffer内所包含数据的大小 | 
| [offset](_codec_base.md#offset) | 有效数据在该Buffer内的起始偏移量 | 
| [flags](_codec_base.md#flags) | 该Buffer具有的标记，也是多个[OH_AVCodecBufferFlags](_codec_base.md#oh_avcodecbufferflags)的组合 | 
