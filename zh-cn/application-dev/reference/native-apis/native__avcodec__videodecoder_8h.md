# native_avcodec_videodecoder.h


## 概述

声明用于视频解码的Native API。

**起始版本：**

9

**相关模块：**

[VideoDecoder](_video_decoder.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_VideoDecoder_CreateByMime](_video_decoder.md#oh_videodecoder_createbymime) (const char \*mime) | 从MIME类型创建视频解码器实例，大多数情况下建议使用。 | 
| \*[OH_VideoDecoder_CreateByName](_video_decoder.md#oh_videodecoder_createbyname) (const char \*name) | 通过视频解码器名称创建视频解码器实例。 使用此接口的前提是知道解码器的确切名称。 | 
| [OH_VideoDecoder_Destroy](_video_decoder.md#oh_videodecoder_destroy) (OH_AVCodec \*codec) | 清理解码器内部资源，销毁解码器实例。 | 
| [OH_VideoDecoder_SetCallback](_video_decoder.md#oh_videodecoder_setcallback) (OH_AVCodec \*codec, OH_AVCodecAsyncCallback callback, void \*userData) | 设置异步回调函数，以便您的应用程序可以响应视频解码器生成的事件。 | 
| [OH_VideoDecoder_SetSurface](_video_decoder.md#oh_videodecoder_setsurface) (OH_AVCodec \*codec, OHNativeWindow \*window) | 指定输出表面以提供视频解码输出，必须在调用Prepare之前调用此接口。 | 
| [OH_VideoDecoder_Configure](_video_decoder.md#oh_videodecoder_configure) (OH_AVCodec \*codec, OH_AVFormat \*format) | 配置视频解码器，通常需要配置解码视频轨迹的描述信息，这些信息可以从容器中提取。 | 
| [OH_VideoDecoder_Prepare](_video_decoder.md#oh_videodecoder_prepare) (OH_AVCodec \*codec) | 要准备解码器的内部资源，在调用该接口之前，必须调用Configure接口。 | 
| [OH_VideoDecoder_Start](_video_decoder.md#oh_videodecoder_start) (OH_AVCodec \*codec) | 启动解码器，准备成功后必须调用此接口。 | 
| [OH_VideoDecoder_Stop](_video_decoder.md#oh_videodecoder_stop) (OH_AVCodec \*codec) | 停止解码器。 | 
| [OH_VideoDecoder_Flush](_video_decoder.md#oh_videodecoder_flush) (OH_AVCodec \*codec) | 清除解码器中缓存的输入和输出数据。 | 
| [OH_VideoDecoder_Reset](_video_decoder.md#oh_videodecoder_reset) (OH_AVCodec \*codec) | 重置解码器。 | 
| \*[OH_VideoDecoder_GetOutputDescription](_video_decoder.md#oh_videodecoder_getoutputdescription) (OH_AVCodec \*codec) | 获取解码器输出数据的描述信息。 | 
| [OH_VideoDecoder_SetParameter](_video_decoder.md#oh_videodecoder_setparameter) (OH_AVCodec \*codec, OH_AVFormat \*format) | 设置解码器的动态参数。 | 
| [OH_VideoDecoder_PushInputData](_video_decoder.md#oh_videodecoder_pushinputdata) (OH_AVCodec \*codec, uint32_t index, OH_AVCodecBufferAttr attr) | 将填充数据的输入缓冲区提交给视频解码器。 | 
| [OH_VideoDecoder_RenderOutputData](_video_decoder.md#oh_videodecoder_renderoutputdata) (OH_AVCodec \*codec, uint32_t index) | 将处理后的输出Buffer返回给解码器，并通知解码器完成在输出表面上渲染Buffer中包含的解码数据。 | 
| [OH_VideoDecoder_FreeOutputData](_video_decoder.md#oh_videodecoder_freeoutputdata) (OH_AVCodec \*codec, uint32_t index) | 将处理后的输出缓冲区返回到解码器。 | 
| [OH_VideoDecoder_IsValid](_video_decoder.md#oh_videodecoder_isvalid) (OH_AVCodec \*codec, bool \*isValid) | 检查当前编解码实例是否有效。 | 
