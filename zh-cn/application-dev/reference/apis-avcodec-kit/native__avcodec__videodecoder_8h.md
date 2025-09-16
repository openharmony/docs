# native_avcodec_videodecoder.h

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhanghongran-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @zengyawen-->

## 概述

声明用于视频解码的Native API。

**库：** libnative_media_vdec.so

**引用文件：** <multimedia/player_framework/native_avcodec_videodecoder.h>

**起始版本：** 9

**相关模块：**[VideoDecoder](_video_decoder.md)

**相关示例：**[AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)

## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodec](_codec_base.md#oh_avcodec) \* [OH_VideoDecoder_CreateByMime](_video_decoder.md#oh_videodecoder_createbymime) (const char \*mime) | 从MIME类型创建视频解码器实例。 | 
| [OH_AVCodec](_codec_base.md#oh_avcodec) \* [OH_VideoDecoder_CreateByName](_video_decoder.md#oh_videodecoder_createbyname) (const char \*name) | 通过视频解码器名称创建视频解码器实例。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_Destroy](_video_decoder.md#oh_videodecoder_destroy) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec) | 清理解码器内部资源，销毁解码器实例。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_SetCallback](_video_decoder.md#oh_videodecoder_setcallback) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) callback, void \*userData) | 设置异步回调函数，让应用可以响应视频解码器生成的事件。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_RegisterCallback](_video_decoder.md#oh_videodecoder_registercallback) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, [OH_AVCodecCallback](_o_h___a_v_codec_callback.md) callback, void \*userData) | 注册异步回调函数，让应用可以响应视频解码器生成的事件。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_SetSurface](_video_decoder.md#oh_videodecoder_setsurface) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, [OHNativeWindow](_codec_base.md#ohnativewindow) \*window) | 指定输出surface以提供视频解码输出。  |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_Configure](_video_decoder.md#oh_videodecoder_configure) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, [OH_AVFormat](capi-core-oh-avformat.md) \*format) | 配置视频解码器，通常需要配置解码视频轨迹的描述信息，这些信息可以从OH_AVSource中提取。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_Prepare](_video_decoder.md#oh_videodecoder_prepare) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec) | 要准备解码器的内部资源。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_Start](_video_decoder.md#oh_videodecoder_start) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec) | 启动解码器，准备成功后必须调用此接口。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_Stop](_video_decoder.md#oh_videodecoder_stop) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec) | 停止解码器。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_Flush](_video_decoder.md#oh_videodecoder_flush) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec) | 清除解码器中缓存的输入和输出数据。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_Reset](_video_decoder.md#oh_videodecoder_reset) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec) | 重置解码器。如果要继续解码，需要再次调用Configure接口配置解码器实例。  | 
| [OH_AVFormat](capi-core-oh-avformat.md) \* [OH_VideoDecoder_GetOutputDescription](_video_decoder.md#oh_videodecoder_getoutputdescription) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec) | 获取解码器输出数据的描述信息。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_SetParameter](_video_decoder.md#oh_videodecoder_setparameter) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, [OH_AVFormat](capi-core-oh-avformat.md) \*format) | 设置解码器的动态参数。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_PushInputData](_video_decoder.md#oh_videodecoder_pushinputdata) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t index, [OH_AVCodecBufferAttr](capi-core-oh-avcodecbufferattr.md) attr) | 将填充数据的输入缓冲区提交给视频解码器。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_RenderOutputData](_video_decoder.md#oh_videodecoder_renderoutputdata) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t index) | 将处理后的输出Buffer返回给解码器，并通知解码器完成在输出surface上渲染buffer中包含的解码数据。 |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_FreeOutputData](_video_decoder.md#oh_videodecoder_freeoutputdata) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t index) | 将处理后的输出缓冲区返回到解码器。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_PushInputBuffer](_video_decoder.md#oh_videodecoder_pushinputbuffer) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t index) | 将填充数据的输入缓冲区提交给视频解码器。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_RenderOutputBuffer](_video_decoder.md#oh_videodecoder_renderoutputbuffer) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t index) | 将处理后的输出缓冲返回给解码器，并通知解码器完成在输出surface上渲染，输出缓冲包含解码数据。 |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_RenderOutputBufferAtTime](_video_decoder.md#oh_videodecoder_renderoutputbufferattime) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t index, int64_t renderTimestampNs) | 将处理后的带渲染时间戳的输出缓冲返回给解码器，并通知解码器完成在输出surface上渲染，输出缓冲包含解码数据。  |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_FreeOutputBuffer](_video_decoder.md#oh_videodecoder_freeoutputbuffer) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t index) | 将处理后的输出缓冲区返回到解码器。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_IsValid](_video_decoder.md#oh_videodecoder_isvalid) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, bool \*isValid) | 检查当前解码实例是否有效。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_SetDecryptionConfig](_video_decoder.md#oh_videodecoder_setdecryptionconfig) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, MediaKeySession \*mediaKeySession, bool secureVideoPath) | 设置解密配置。 |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_QueryInputBuffer](_video_decoder.md#oh_videodecoder_queryinputbuffer) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t *index, int64_t timeoutUs) | 查询下一个可用输入缓冲区的索引。 | 
| [OH_AVBuffer](capi-core-oh-avbuffer.md) [OH_VideoDecoder_GetInputBuffer](_video_decoder.md#oh_videodecoder_getinputbuffer) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t index) | 获取可用输入缓冲区的实例。 |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoDecoder_QueryOutputBuffer](_video_decoder.md#oh_videodecoder_queryoutputbuffer) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t *index, int64_t timeoutUs) | 查询下一个可用输出缓冲区的索引。 | 
| [OH_AVBuffer](capi-core-oh-avbuffer.md) [OH_VideoDecoder_GetOutputBuffer](_video_decoder.md#oh_videodecoder_getoutputbuffer) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t index) | 获取可用输出缓冲区的实例。 |
