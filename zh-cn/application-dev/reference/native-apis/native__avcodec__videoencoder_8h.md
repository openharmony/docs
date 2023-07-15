# native_avcodec_videoencoder.h


## 概述

声明用于视频编码的Native API。

**起始版本：**

9

**相关模块：**

[VideoEncoder](_video_encoder.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode) | 视频编码器的比特率模式。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_VideoEncodeBitrateMode](_video_encoder.md#oh_videoencodebitratemode) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;**CBR** = 0,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**VBR** = 1,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**CQ** = 2<br/>} | 视频编码器的比特率模式。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_VideoEncoder_CreateByMime](_video_encoder.md#oh_videoencoder_createbymime) (const char \*mime) | 多数情况下，推荐从MIME类型创建视频编码器实例。 | 
| \*[OH_VideoEncoder_CreateByName](_video_encoder.md#oh_videoencoder_createbyname) (const char \*name) | 通过视频编码器名称创建一个视频编码器实例。使用此接口的前提是知道编码器的确切名称。 | 
| [OH_VideoEncoder_Destroy](_video_encoder.md#oh_videoencoder_destroy) (OH_AVCodec \*codec) | 清除编码器的内部资源并销毁编码器实例。 | 
| [OH_VideoEncoder_SetCallback](_video_encoder.md#oh_videoencoder_setcallback) (OH_AVCodec \*codec, OH_AVCodecAsyncCallback callback, void \*userData) | 设置异步回调函数，以便您的应用程序能够响应视频编码器事件。 | 
| [OH_VideoEncoder_Configure](_video_encoder.md#oh_videoencoder_configure) (OH_AVCodec \*codec, OH_AVFormat \*format) | 配置视频编码器，通常需要配置要编码的视频轨的描述信息。 | 
| [OH_VideoEncoder_Prepare](_video_encoder.md#oh_videoencoder_prepare) (OH_AVCodec \*codec) | 若要准备编码器的内部资源，必须先调用Configure接口，再调用此接口。 | 
| [OH_VideoEncoder_Start](_video_encoder.md#oh_videoencoder_start) (OH_AVCodec \*codec) | 启动编码器, 这个接口必须要在Prepare接口执行成功后调用。 | 
| [OH_VideoEncoder_Stop](_video_encoder.md#oh_videoencoder_stop) (OH_AVCodec \*codec) | 停止编码器。 | 
| [OH_VideoEncoder_Flush](_video_encoder.md#oh_videoencoder_flush) (OH_AVCodec \*codec) | 清除编码器中缓冲的输入和输出数据。 | 
| [OH_VideoEncoder_Reset](_video_encoder.md#oh_videoencoder_reset) (OH_AVCodec \*codec) | 重置编码器。 | 
| \*[OH_VideoEncoder_GetOutputDescription](_video_encoder.md#oh_videoencoder_getoutputdescription) (OH_AVCodec \*codec) | 获取编码器输出数据的描述信息，详细信息请参阅**OH_AVFormat**。 | 
| [OH_VideoEncoder_SetParameter](_video_encoder.md#oh_videoencoder_setparameter) (OH_AVCodec \*codec, OH_AVFormat \*format) | 为编码器设置动态参数。 | 
| [OH_VideoEncoder_GetSurface](_video_encoder.md#oh_videoencoder_getsurface) (OH_AVCodec \*codec, OHNativeWindow \*\*window) | 从视频编码器获取输入Surface，必须在调用Prepare之前调用此接口。 | 
| [OH_VideoEncoder_FreeOutputData](_video_encoder.md#oh_videoencoder_freeoutputdata) (OH_AVCodec \*codec, uint32_t index) | 将处理后的输出缓冲区返回给编码器。 | 
| [OH_VideoEncoder_NotifyEndOfStream](_video_encoder.md#oh_videoencoder_notifyendofstream) (OH_AVCodec \*codec) | 通知视频编码器输入流已结束。建议使用此接口进行通知。 | 
| [OH_VideoEncoder_PushInputData](_video_encoder.md#oh_videoencoder_pushinputdata) (OH_AVCodec \*codec, uint32_t index, OH_AVCodecBufferAttr attr) | 将填入数据的输入缓冲区提交给视频编码器。 | 
| \*[OH_VideoEncoder_GetInputDescription](_video_encoder.md#oh_videoencoder_getinputdescription) (OH_AVCodec \*codec) | 获取视频编码器接收的描述信息，调用Configure后调用此接口，请参阅 **OH_AVFormat** 获取详细信息。 | 
| [OH_VideoEncoder_IsValid](_video_encoder.md#oh_videoencoder_isvalid) (OH_AVCodec \*codec, bool \*isValid) | 检查当前编解码器实例是否有效。 | 
