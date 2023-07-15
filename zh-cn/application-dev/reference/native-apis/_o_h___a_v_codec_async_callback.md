# OH_AVCodecAsyncCallback


## 概述

OH_AVCodec中所有异步回调函数指针的集合。将该结构体的实例注册到OH_AVCodec实例中， 并处理回调上报的信息，以保证OH_AVCodec的正常运行。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**起始版本：**

9

**相关模块：**

[CodecBase](_codec_base.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [onError](#onerror) | 监控编解码器操作错误，请参见[OH_AVCodecOnError](_codec_base.md#oh_avcodeconerror) | 
| [onStreamChanged](#onstreamchanged) | 监控编解码器流变化，请参见[OH_AVCodecOnStreamChanged](_codec_base.md#oh_avcodeconstreamchanged) | 
| [onNeedInputData](#onneedinputdata) | 监控编解码器需要输入数据，请参见[OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata) | 
| [onNeedOutputData](#onneedoutputdata) | 监控编解码器已生成输出数据，请参见[OH_AVCodecOnNewOutputData](_codec_base.md#oh_avcodeconnewoutputdata) | 


## 结构体成员变量说明


### onError

  
```
OH_AVCodecOnError onError
```

**描述：**

监控编解码器操作错误，请参见[OH_AVCodecOnError](_codec_base.md#oh_avcodeconerror)

**起始版本：**

9


### onNeedInputData

  
```
OH_AVCodecOnNeedInputData onNeedInputData
```

**描述：**

监控编解码器需要输入数据，请参见[OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata)

**起始版本：**

9


### onNeedOutputData

  
```
OH_AVCodecOnNewOutputData onNeedOutputData
```

**描述：**

监控编解码器已生成输出数据，请参见[OH_AVCodecOnNewOutputData](_codec_base.md#oh_avcodeconnewoutputdata)

**起始版本：**

9


### onStreamChanged

  
```
OH_AVCodecOnStreamChanged onStreamChanged
```

**描述：**

监控编解码器流变化，请参见[OH_AVCodecOnStreamChanged](_codec_base.md#oh_avcodeconstreamchanged)

**起始版本：**

9
