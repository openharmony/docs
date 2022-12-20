# native_avcodec_audioencoder.h


## 概述

声明用于音频编码的Native API。

**Since:**
9
**Version:**
1.0
**相关模块:**

[AudioEncoder](_audio_encoder.md)


## 汇总


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioEncoder_CreateByMime](_audio_encoder.md#oh_audioencoder_createbymime) (const char \*mime) | OH_AVCodec \*<br/>通过mime类型创建一个音频编码器实例，大多数情况下推荐使用该接口。  | 
| [OH_AudioEncoder_CreateByName](_audio_encoder.md#oh_audioencoder_createbyname) (const char \*name) | OH_AVCodec \*<br/>通过音频编码器名称创建一个音频编码器实例，使用这个接口的前提是必须清楚编码器准确的名称。  | 
| [OH_AudioEncoder_Destroy](_audio_encoder.md#oh_audioencoder_destroy) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>清空编码器内部资源，并销毁编码器实例。  | 
| [OH_AudioEncoder_SetCallback](_audio_encoder.md#oh_audioencoder_setcallback) (OH_AVCodec \*codec, [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) callback, void \*userData) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>设置异步回调函数，使得你的应用能够响应音频编码器产生的事件，该接口被调用必须是在Prepare被调用前。  | 
| [OH_AudioEncoder_Configure](_audio_encoder.md#oh_audioencoder_configure) (OH_AVCodec \*codec, OH_AVFormat \*format) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>配置音频编码器，典型地，需要配置被编码音频轨道的描述信息，该接口被调用必须是在Prepare被调用前。  | 
| [OH_AudioEncoder_Prepare](_audio_encoder.md#oh_audioencoder_prepare) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>准备编码器内部资源，调用该接口前必须先调用Configure接口。  | 
| [OH_AudioEncoder_Start](_audio_encoder.md#oh_audioencoder_start) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>启动编码器，该接口必须在已经Prepare成功后调用。 在启动成功后，编码器将开始报告[OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata)事件。  | 
| [OH_AudioEncoder_Stop](_audio_encoder.md#oh_audioencoder_stop) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>停止编码器。在停止后可通过Start重新进入Started状态。  | 
| [OH_AudioEncoder_Flush](_audio_encoder.md#oh_audioencoder_flush) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>清空编码器内部缓存的输入输出数据。在该接口被调用后，所有先前通过异步回调报告的Buffer的索引都将 失效，确保不要再访问这些索引对应的Buffers。  | 
| [OH_AudioEncoder_Reset](_audio_encoder.md#oh_audioencoder_reset) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>重置编码器。如需继续编码工作，需要重新调用Configure接口以配置该编码器实例。  | 
| [OH_AudioEncoder_GetOutputDescription](_audio_encoder.md#oh_audioencoder_getoutputdescription) (OH_AVCodec \*codec) | OH_AVFormat \*<br/>获取该编码器输出数据的描述信息，需要注意的是，返回值所指向的OH_AVFormat实例需调用者手动释放。  | 
| [OH_AudioEncoder_SetParameter](_audio_encoder.md#oh_audioencoder_setparameter) (OH_AVCodec \*codec, OH_AVFormat \*format) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>向编码器设置动态参数，注意：该接口仅能在编码器被启动后调用，同时错误的参数设置，可能会导致编码失败。  | 
| [OH_AudioEncoder_PushInputData](_audio_encoder.md#oh_audioencoder_pushinputdata) (OH_AVCodec \*codec, uint32_t index, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) attr) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>将填充好数据的输入Buffer提交给音频编码器。[OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata)回调会报告可用的输入 Buffer及对应的索引值。一旦指定索引的Buffer被提交给编码器，直到再一次收到[OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata) 回调报告相同索引的Buffer可用前，该Buffer都不可以再次被访问。  | 
| [OH_AudioEncoder_FreeOutputData](_audio_encoder.md#oh_audioencoder_freeoutputdata) (OH_AVCodec \*codec, uint32_t index) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>将处理结束的输出Buffer交还给编码器。  | 
