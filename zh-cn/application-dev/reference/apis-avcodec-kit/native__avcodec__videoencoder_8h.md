# native_avcodec_videoencoder.h

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhanghongran-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @zengyawen-->

## 概述

声明用于视频编码的Native API。

**库：** libnative_media_venc.so

**引用文件：** <multimedia/player_framework/native_avcodec_videoencoder.h>

**起始版本：** 9

**相关模块：**[VideoEncoder](_video_encoder.md)

**相关示例：**[AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void(\* [OH_VideoEncoder_OnNeedInputParameter](_video_encoder.md#oh_videoencoder_onneedinputparameter)) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t index, OH_AVFormat \*parameter, void \*userData) | 当OH_AVCodec在运行过程中需要新的输入参数时，将调用此函数指针，并携带可用的缓冲区来填充新的输入参数。设置的参数随帧立即生效。  | 
| typedef enum [OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode) [OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode) | 视频编码器的比特率模式。（API14废弃） | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode) { CBR = 0, VBR = 1, CQ = 2 } | 视频编码器的比特率模式。（API14废弃） | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodec](_codec_base.md#oh_avcodec) \* [OH_VideoEncoder_CreateByMime](_video_encoder.md#oh_videoencoder_createbymime) (const char \*mime) | 从MIME类型创建视频编码器实例。 | 
| [OH_AVCodec](_codec_base.md#oh_avcodec) \* [OH_VideoEncoder_CreateByName](_video_encoder.md#oh_videoencoder_createbyname) (const char \*name) | 通过视频编码器名称创建视频编码器实例。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_Destroy](_video_encoder.md#oh_videoencoder_destroy) (OH_AVCodec \*codec) | 清理编码器内部资源，销毁编码器实例。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_SetCallback](_video_encoder.md#oh_videoencoder_setcallback) (OH_AVCodec \*codec, [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) callback, void \*userData) | 设置异步回调函数，让应用可以响应视频编码器生成的事件。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_RegisterCallback](_video_encoder.md#oh_videoencoder_registercallback) (OH_AVCodec \*codec, [OH_AVCodecCallback](_o_h___a_v_codec_callback.md) callback, void \*userData) | 注册异步回调函数，让应用可以响应视频编码器生成的事件。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_RegisterParameterCallback](_video_encoder.md#oh_videoencoder_registerparametercallback) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, [OH_VideoEncoder_OnNeedInputParameter](_video_encoder.md#oh_videoencoder_onneedinputparameter) onInputParameter, void \*userData) | 注册异步输入参数回调函数，让应用可以响应视频编码器生成的事件。  | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_Configure](_video_encoder.md#oh_videoencoder_configure) (OH_AVCodec \*codec, OH_AVFormat \*format) | 配置视频编码器，通常需要配置要编码的视频轨的描述信息。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_Prepare](_video_encoder.md#oh_videoencoder_prepare) (OH_AVCodec \*codec) | 准备编码器的内部资源。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_Start](_video_encoder.md#oh_videoencoder_start) (OH_AVCodec \*codec) | 启动编码器，准备成功后必须调用此接口。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_Stop](_video_encoder.md#oh_videoencoder_stop) (OH_AVCodec \*codec) | 停止编码器。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_Flush](_video_encoder.md#oh_videoencoder_flush) (OH_AVCodec \*codec) | 清除编码器中缓存的输入和输出数据。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_Reset](_video_encoder.md#oh_videoencoder_reset) (OH_AVCodec \*codec) | 重置编码器。 | 
| [OH_AVFormat](capi-core-oh-avformat.md) \* [OH_VideoEncoder_GetOutputDescription](_video_encoder.md#oh_videoencoder_getoutputdescription) (OH_AVCodec \*codec) | 获取编码器输出数据的描述信息。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_SetParameter](_video_encoder.md#oh_videoencoder_setparameter) (OH_AVCodec \*codec, OH_AVFormat \*format) | 为编码器设置动态参数。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_GetSurface](_video_encoder.md#oh_videoencoder_getsurface) (OH_AVCodec \*codec, OHNativeWindow \*\*window) | 从视频编码器获取输入Surface。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_FreeOutputData](_video_encoder.md#oh_videoencoder_freeoutputdata) (OH_AVCodec \*codec, uint32_t index) | 将处理后的输出缓冲区返回给编码器。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_NotifyEndOfStream](_video_encoder.md#oh_videoencoder_notifyendofstream) (OH_AVCodec \*codec) | 通知视频编码器输入流已结束。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_PushInputData](_video_encoder.md#oh_videoencoder_pushinputdata) (OH_AVCodec \*codec, uint32_t index, [OH_AVCodecBufferAttr](capi-core-oh-avcodecbufferattr.md) attr) | 将填入数据的输入缓冲区提交给视频编码器。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_PushInputBuffer](_video_encoder.md#oh_videoencoder_pushinputbuffer) (OH_AVCodec \*codec, uint32_t index) | 将填入数据的输入缓冲区提交给视频编码器。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_PushInputParameter](_video_encoder.md#oh_videoencoder_pushinputparameter) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t index) | 将填入数据的输入参数缓冲区提交给视频编码器。  | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_FreeOutputBuffer](_video_encoder.md#oh_videoencoder_freeoutputbuffer) (OH_AVCodec \*codec, uint32_t index) | 将处理后的输出缓冲区返回给编码器。 | 
| [OH_AVFormat](capi-core-oh-avformat.md) \* [OH_VideoEncoder_GetInputDescription](_video_encoder.md#oh_videoencoder_getinputdescription) (OH_AVCodec \*codec) | 获取视频编码器接收的描述信息。 | 
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_IsValid](_video_encoder.md#oh_videoencoder_isvalid) (OH_AVCodec \*codec, bool \*isValid) | 检查当前编码实例是否有效。 |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_QueryInputBuffer](_video_encoder.md#oh_videoencoder_queryinputbuffer) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t *index, int64_t timeoutUs) | 查询下一个可用输入缓冲区的索引。 | 
| [OH_AVBuffer](capi-core-oh-avbuffer.md) [OH_VideoEncoder_GetInputBuffer](_video_encoder.md#oh_videoencoder_getinputbuffer) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t index) | 获取可用输入缓冲区的实例。 |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) [OH_VideoEncoder_QueryOutputBuffer](_video_encoder.md#oh_videoencoder_queryoutputbuffer) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t *index, int64_t timeoutUs) | 查询下一个可用输出缓冲区的索引。 | 
| [OH_AVBuffer](capi-core-oh-avbuffer.md) [OH_VideoEncoder_GetOutputBuffer](_video_encoder.md#oh_videoencoder_getoutputbuffer) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t index) | 获取可用输出缓冲区的实例。 |
