# native_avcodec_audiodecoder.h


## 概述

音频解码Native API的声明。

**库：** libnative_media_adec.so

**起始版本：** 9

**相关模块：**[AudioDecoder](_audio_decoder.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| OH_AVCodec \* [OH_AudioDecoder_CreateByMime](_audio_decoder.md#oh_audiodecoder_createbymime) (const char \*mime) | 根据MIME类型创建音频解码器实例。 | 
| OH_AVCodec \* [OH_AudioDecoder_CreateByName](_audio_decoder.md#oh_audiodecoder_createbyname) (const char \*name) | 通过音频解码器名称创建音频解码器实例。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioDecoder_Destroy](_audio_decoder.md#oh_audiodecoder_destroy) (OH_AVCodec \*codec) | 清理解码器内部资源，销毁解码器实例。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioDecoder_SetCallback](_audio_decoder.md#oh_audiodecoder_setcallback) (OH_AVCodec \*codec, [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) callback, void \*userData) | 设置异步回调函数，使应用可以响应音频解码器生成的事件。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioDecoder_Configure](_audio_decoder.md#oh_audiodecoder_configure) (OH_AVCodec \*codec, OH_AVFormat \*format) | 要配置音频解码器，通常需要配置从容器中提取的音频描述信息。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioDecoder_Prepare](_audio_decoder.md#oh_audiodecoder_prepare) (OH_AVCodec \*codec) | 准备解码器的内部资源。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioDecoder_Start](_audio_decoder.md#oh_audiodecoder_start) (OH_AVCodec \*codec) | 调用此接口启动解码器，在Prepare成功后执行。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioDecoder_Stop](_audio_decoder.md#oh_audiodecoder_stop) (OH_AVCodec \*codec) | 停止解码器。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioDecoder_Flush](_audio_decoder.md#oh_audiodecoder_flush) (OH_AVCodec \*codec) | 清除解码器中缓存的输入和输出数据。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioDecoder_Reset](_audio_decoder.md#oh_audiodecoder_reset) (OH_AVCodec \*codec) | 重置解码器。如果要继续解码，需要再次调用Configure接口配置解码器实例。 | 
| OH_AVFormat \* [OH_AudioDecoder_GetOutputDescription](_audio_decoder.md#oh_audiodecoder_getoutputdescription) (OH_AVCodec \*codec) | 获取解码器输出数据的描述信息。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioDecoder_SetParameter](_audio_decoder.md#oh_audiodecoder_setparameter) (OH_AVCodec \*codec, OH_AVFormat \*format) | 配置解码器的动态参数。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioDecoder_PushInputData](_audio_decoder.md#oh_audiodecoder_pushinputdata) (OH_AVCodec \*codec, uint32_t index, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) attr) | 通知音频解码器已完成对index所对应缓冲区进行输入数据的填充。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioDecoder_FreeOutputData](_audio_decoder.md#oh_audiodecoder_freeoutputdata) (OH_AVCodec \*codec, uint32_t index) | 将处理后的输出缓冲区返回给解码器。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioDecoder_IsValid](_audio_decoder.md#oh_audiodecoder_isvalid) (OH_AVCodec \*codec, bool \*isValid) | 检查当前解码器实例是否有效，可用于后台故障恢复或应用程序从后台恢复时检测解码器有效状态。 | 
