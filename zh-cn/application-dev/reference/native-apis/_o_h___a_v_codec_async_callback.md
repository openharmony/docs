# OH_AVCodecAsyncCallback


## 概述

AVCodec所有的异步回调函数指针集合。注册一个该结构体实例给OH_AVCodec实例，并处理通过该回调报告的信息，以确保AVCodec正常运转。

@syscap SystemCapability.Multimedia.Media.CodecBase
参数
**起始版本：**
9

**相关模块:**

[CodecBase](_codec_base.md)


## 汇总


### 成员变量

  | 名称 | 描述 | 
| -------- | -------- |
| **onError** | 监听AVCodec运行错误，参考[OH_AVCodecOnError](_codec_base.md#oh_avcodeconerror) | 
| **onStreamChanged** | 监听编解码流信息，参考[OH_AVCodecOnStreamChanged](_codec_base.md#oh_avcodeconstreamchanged) | 
| **onNeedInputData** | 监听编解码需要输入数据，参考[OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata) | 
| **onNeedOutputData** | 监听编解码产生输出数据，参考[OH_AVCodecOnNewOutputData](_codec_base.md#oh_avcodeconnewoutputdata) | 
