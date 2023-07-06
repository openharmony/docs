# native_avcodec_audioencoder.h

## 概述

声明用于音频编码的Native API。

**起始版本：**

9

**相关模块：**

[AudioEncoder](_audio_encoder.md)

## 汇总

### 函数

| 名称                                                                                                                                                           | 描述                                                                           |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------ |
| \*[OHOS::Media::OH_AudioEncoder_CreateByMime](_audio_encoder.md#oh_audioencoder_createbymime) (const char \*mime)                                                 | 根据MIME类型创建音频编码器实例，大多数场景下建议使用此方式。                   |
| \*[OHOS::Media::OH_AudioEncoder_CreateByName](_audio_encoder.md#oh_audioencoder_createbyname) (const char \*name)                                                 | 通过音频编码器名称创建音频编码器实例，使用此接口的前提是知道编码器的确切名称。 |
| [OHOS::Media::OH_AudioEncoder_Destroy](_audio_encoder.md#oh_audioencoder_destroy) (OH_AVCodec \*codec)                                                            | 清理编码器内部资源，销毁编码器实例。                                           |
| [OHOS::Media::OH_AudioEncoder_SetCallback](_audio_encoder.md#oh_audioencoder_setcallback) (OH_AVCodec \*codec, OH_AVCodecAsyncCallback callback, void \*userData) | 设置异步回调函数，使您的应用程序可以响应音频编码器生成的事件。                 |
| [OHOS::Media::OH_AudioEncoder_Configure](_audio_encoder.md#oh_audioencoder_configure) (OH_AVCodec \*codec, OH_AVFormat \*format)                                  | 要配置音频编码器，通常需要配置编码后的音轨的描述信息。                         |
| [OHOS::Media::OH_AudioEncoder_Prepare](_audio_encoder.md#oh_audioencoder_prepare) (OH_AVCodec \*codec)                                                            | 准备编码器的内部资源，在调用此接口之前必须调用Configure接口。                  |
| [OHOS::Media::OH_AudioEncoder_Start](_audio_encoder.md#oh_audioencoder_start) (OH_AVCodec \*codec)                                                                | Prepare成功后调用此接口启动编码器。                                            |
| [OHOS::Media::OH_AudioEncoder_Stop](_audio_encoder.md#oh_audioencoder_stop) (OH_AVCodec \*codec)                                                                  | 停止编码器。                                                                   |
| [OHOS::Media::OH_AudioEncoder_Flush](_audio_encoder.md#oh_audioencoder_flush) (OH_AVCodec \*codec)                                                                | 清除编码器中缓存的输入和输出数据。                                             |
| [OHOS::Media::OH_AudioEncoder_Reset](_audio_encoder.md#oh_audioencoder_reset) (OH_AVCodec \*codec)                                                                | 重置编码器。                                                                   |
| \*[OHOS::Media::OH_AudioEncoder_GetOutputDescription](_audio_encoder.md#oh_audioencoder_getoutputdescription) (OH_AVCodec \*codec)                                | 获取编码器输出数据的描述信息，详细信息请参见**OH_AVFormat**。            |
| [OHOS::Media::OH_AudioEncoder_SetParameter](_audio_encoder.md#oh_audioencoder_setparameter) (OH_AVCodec \*codec, OH_AVFormat \*format)                            | 配置编码器的动态参数。                                                         |
| [OHOS::Media::OH_AudioEncoder_PushInputData](_audio_encoder.md#oh_audioencoder_pushinputdata) (OH_AVCodec \*codec, uint32_t index, OH_AVCodecBufferAttr attr)     | 将填充有数据的输入缓冲区提交给音频编码器。                                     |
| [OHOS::Media::OH_AudioEncoder_FreeOutputData](_audio_encoder.md#oh_audioencoder_freeoutputdata) (OH_AVCodec \*codec, uint32_t index)                              | 将处理后的输出缓冲区返回给编码器。                                             |
| [OHOS::Media::OH_AudioEncoder_IsValid](_audio_encoder.md#oh_audioencoder_isvalid) (OH_AVCodec \*codec, bool \*isValid)                                            | 检查当前编码器实例是否有效。                                                   |
