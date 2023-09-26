# native_avcodec_audiodecoder.h

## 概述

声明用于音频解码的Native API。

**起始版本：**

9

**相关模块：**

[AudioDecoder](_audio_decoder.md)

## 汇总

### 函数

| 名称                                                                                                                                                           | 描述                                                                                                 |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------- |
| \*[OHOS::Media::OH_AudioDecoder_CreateByMime](_audio_decoder.md#oh_audiodecoder_createbymime) (const char \*mime)                                                 | 根据MIME类型创建音频解码器实例，大多数场景下建议使用此方式。                                         |
| \*[OHOS::Media::OH_AudioDecoder_CreateByName](_audio_decoder.md#oh_audiodecoder_createbyname) (const char \*name)                                                 | 通过音频解码器名称创建音频解码器实例，使用此接口的前提是知道解码器的确切名称。                       |
| [OHOS::Media::OH_AudioDecoder_Destroy](_audio_decoder.md#oh_audiodecoder_destroy) (OH_AVCodec \*codec)                                                            | 清理解码器内部资源，销毁解码器实例。                                                                 |
| [OHOS::Media::OH_AudioDecoder_SetCallback](_audio_decoder.md#oh_audiodecoder_setcallback) (OH_AVCodec \*codec, OH_AVCodecAsyncCallback callback, void \*userData) | 设置异步回调函数，使您的应用程序可以响应音频解码器生成的事件。                                       |
| [OHOS::Media::OH_AudioDecoder_Configure](_audio_decoder.md#oh_audiodecoder_configure) (OH_AVCodec \*codec, OH_AVFormat \*format)                                  | 要配置音频解码器，通常需要配置从容器中提取的音频描述信息。                                           |
| [OHOS::Media::OH_AudioDecoder_Prepare](_audio_decoder.md#oh_audiodecoder_prepare) (OH_AVCodec \*codec)                                                            | 准备解码器的内部资源，在调用此接口之前必须调用Configure接口。                                        |
| [OHOS::Media::OH_AudioDecoder_Start](_audio_decoder.md#oh_audiodecoder_start) (OH_AVCodec \*codec)                                                                | Prepare成功后调用此接口启动解码器。                                                                  |
| [OHOS::Media::OH_AudioDecoder_Stop](_audio_decoder.md#oh_audiodecoder_stop) (OH_AVCodec \*codec)                                                                  | 停止解码器。                                                                                         |
| [OHOS::Media::OH_AudioDecoder_Flush](_audio_decoder.md#oh_audiodecoder_flush) (OH_AVCodec \*codec)                                                                | 清除解码器中缓存的输入和输出数据。                                                                   |
| [OHOS::Media::OH_AudioDecoder_Reset](_audio_decoder.md#oh_audiodecoder_reset) (OH_AVCodec \*codec)                                                                | 重置解码器。如果要继续解码，需要再次调用Configure接口配置解码器实例 。                               |
| \*[OHOS::Media::OH_AudioDecoder_GetOutputDescription](_audio_decoder.md#oh_audiodecoder_getoutputdescription) (OH_AVCodec \*codec)                                | 获取解码器输出数据的描述信息，详细信息请参见**OH_AVFormat**。                                  |
| [OHOS::Media::OH_AudioDecoder_SetParameter](_audio_decoder.md#oh_audiodecoder_setparameter) (OH_AVCodec \*codec, OH_AVFormat \*format)                            | 配置解码器的动态参数。注意：该接口必须在解码器启动后才能调用。另外，参数配置错误可能会导致解码失败。 |
| [OHOS::Media::OH_AudioDecoder_PushInputData](_audio_decoder.md#oh_audiodecoder_pushinputdata) (OH_AVCodec \*codec, uint32_t index, OH_AVCodecBufferAttr attr)     | 将填充有数据的输入缓冲区提交给音频解码器。                                                           |
| [OHOS::Media::OH_AudioDecoder_FreeOutputData](_audio_decoder.md#oh_audiodecoder_freeoutputdata) (OH_AVCodec \*codec, uint32_t index)                              | 将处理后的输出缓冲区返回给解码器。                                                                   |
| [OHOS::Media::OH_AudioDecoder_IsValid](_audio_decoder.md#oh_audiodecoder_isvalid) (OH_AVCodec \*codec, bool \*isValid)                                            | 检查当前解码器实例是否有效。                                                                         |
