# OH_AVCodecCallback

## 概述

OH_AVCodec中所有异步回调函数指针的集合。将该结构体的实例注册到OH_AVCodec实例中，并处理回调上报的信息，以保证OH_AVCodec的正常运行。

使用指导请参见[视频编码](../../media/avcodec/video-encoding.md)中的“Surface模式步骤-4或Buffer模式步骤-3”。

**起始版本：** 11

**相关模块：** [CodecBase](capi-codecbase.md)

**所在头文件：** [native_avcodec_base.h](capi-native-avcodec-base-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [OH_AVCodecOnError](capi-native-avcodec-base-h.md#oh_avcodeconerror) onError | 监控编解码器操作错误。 |
| [OH_AVCodecOnStreamChanged](capi-native-avcodec-base-h.md#oh_avcodeconstreamchanged) onStreamChanged | 监控编解码器流变化。 |
| [OH_AVCodecOnNeedInputBuffer](capi-native-avcodec-base-h.md#oh_avcodeconneedinputbuffer) onNeedInputBuffer| 监控编解码器需要输入数据。 |
| [OH_AVCodecOnNewOutputBuffer](capi-native-avcodec-base-h.md#oh_avcodeconnewoutputbuffer) onNewOutputBuffer | 监控编解码器已生成输出数据。 |

