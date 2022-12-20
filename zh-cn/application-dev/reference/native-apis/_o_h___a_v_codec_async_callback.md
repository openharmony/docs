# OH_AVCodecAsyncCallback


## 概述

AVCodec所有的异步回调函数指针集合。注册一个该结构体实例给OH_AVCodec实例，并处理通过该回调报告 的信息，以确保AVCodec正常运转。

@syscap SystemCapability.Multimedia.Media.CodecBase
参数
**Since:**
9
**Version:**
1.0
**相关模块:**

[CodecBase](_codec_base.md)


## 汇总


### 成员变量

  | 名称 | 描述 | 
| -------- | -------- |
| **onError** | [OH_AVCodecOnError](_codec_base.md#oh_avcodeconerror) | 
| **onStreamChanged** | [OH_AVCodecOnStreamChanged](_codec_base.md#oh_avcodeconstreamchanged) | 
| **onNeedInputData** | [OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata) | 
| **onNeedOutputData** | [OH_AVCodecOnNewOutputData](_codec_base.md#oh_avcodeconnewoutputdata) | 
