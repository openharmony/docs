# OH_AVCodecAsyncCallback


## 概述

OH_AVCodec中所有异步回调函数指针的集合。将该结构体的实例注册到OH_AVCodec实例中，并处理回调上报的信息，以保证OH_AVCodec的正常运行。

**系统能力：** SystemCapability.Multimedia.Media.CodecBase

**相关模块：**[CodecBase](_codec_base.md)

**所在头文件：**[native_avcodec_base.h](native__avcodec__base_8h.md)

**起始版本：** 9

**废弃版本：** 11

**替代接口：**[OH_AVCodecCallback](_o_h___a_v_codec_callback.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodecOnError](_codec_base.md#oh_avcodeconerror) [onError](#onerror) | 监控编解码器操作错误。 | 
| [OH_AVCodecOnStreamChanged](_codec_base.md#oh_avcodeconstreamchanged) [onStreamChanged](#onstreamchanged) | 监控编解码器流变化。 | 
| [OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata) [onNeedInputData](#onneedinputdata) | 监控编解码器需要输入数据。 | 
| [OH_AVCodecOnNewOutputData](_codec_base.md#oh_avcodeconnewoutputdata) [onNewOutputData](#onnewoutputdata) | 监控编解码器已生成输出数据。 | 


## 结构体成员变量说明


### onError

**描述**

监控编解码器操作错误。

**起始版本：** 9


### onNeedInputData

**描述**

监控编解码器需要输入数据。

**起始版本：** 9


### onNewOutputData

**描述**

监控编解码器已生成输出数据。

**起始版本：** 9


### onStreamChanged

**描述**

监控编解码器流变化。

**起始版本：** 9
