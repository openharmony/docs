# native_avcodec_audioencoder.h


## 概述

声明用于音频编码的Native API。

**库：** libnative_media_aenc.so

**起始版本：** 9

**相关模块：**[AudioEncoder](_audio_encoder.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| OH_AVCodec \* [OH_AudioEncoder_CreateByMime](_audio_encoder.md#oh_audioencoder_createbymime) (const char \*mime) | 根据MIME类型创建音频编码器实例。 | 
| OH_AVCodec \* [OH_AudioEncoder_CreateByName](_audio_encoder.md#oh_audioencoder_createbyname) (const char \*name) | 通过音频编码器名称创建音频编码器实例。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioEncoder_Destroy](_audio_encoder.md#oh_audioencoder_destroy) (OH_AVCodec \*codec) | 清理编码器内部资源，销毁编码器实例。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioEncoder_SetCallback](_audio_encoder.md#oh_audioencoder_setcallback) (OH_AVCodec \*codec, [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) callback, void \*userData) | 设置异步回调函数，使应用可以响应音频编码器生成的事件。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioEncoder_Configure](_audio_encoder.md#oh_audioencoder_configure) (OH_AVCodec \*codec, OH_AVFormat \*format) | 要配置音频编码器，通常需要配置编码后的音轨的描述信息。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioEncoder_Prepare](_audio_encoder.md#oh_audioencoder_prepare) (OH_AVCodec \*codec) | 准备编码器的内部资源。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioEncoder_Start](_audio_encoder.md#oh_audioencoder_start) (OH_AVCodec \*codec) | 调用此接口启动编码器，在Prepare成功后执行。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioEncoder_Stop](_audio_encoder.md#oh_audioencoder_stop) (OH_AVCodec \*codec) | 停止编码器。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioEncoder_Flush](_audio_encoder.md#oh_audioencoder_flush) (OH_AVCodec \*codec) | 清除编码器中缓存的输入和输出数据。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioEncoder_Reset](_audio_encoder.md#oh_audioencoder_reset) (OH_AVCodec \*codec) | 重置编码器。 | 
| OH_AVFormat \* [OH_AudioEncoder_GetOutputDescription](_audio_encoder.md#oh_audioencoder_getoutputdescription) (OH_AVCodec \*codec) | 获取编码器输出数据的描述信息。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioEncoder_SetParameter](_audio_encoder.md#oh_audioencoder_setparameter) (OH_AVCodec \*codec, OH_AVFormat \*format) | 配置编码器的动态参数。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioEncoder_PushInputData](_audio_encoder.md#oh_audioencoder_pushinputdata) (OH_AVCodec \*codec, uint32_t index, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) attr) | 将填充有数据的输入缓冲区提交给音频编码器。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioEncoder_FreeOutputData](_audio_encoder.md#oh_audioencoder_freeoutputdata) (OH_AVCodec \*codec, uint32_t index) | 将处理后的输出缓冲区返回给编码器。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioEncoder_IsValid](_audio_encoder.md#oh_audioencoder_isvalid) (OH_AVCodec \*codec, bool \*isValid) | 检查当前编码器实例是否有效，可用于后台故障恢复或应用程序从后台恢复时检测编码器有效状态。 | 
