# native_avcodec_audiocodec.h

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @zengyawen-->

## 概述

音频编解码Native API的声明。

**库：** libnative_media_acodec.so

**引用文件：** <multimedia/player_framework/native_avcodec_audiocodec.h>

**起始版本：** 11

**相关模块：**[AudioCodec](_audio_codec.md)

**相关示例：**[AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)

## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodec](_codec_base.md#oh_avcodec) \* [OH_AudioCodec_CreateByMime](_audio_codec.md#oh_audiocodec_createbymime) (const char \*mime, bool isEncoder) | 根据MIME类型创建音频编解码器实例。  | 
| [OH_AVCodec](_codec_base.md#oh_avcodec) \* [OH_AudioCodec_CreateByName](_audio_codec.md#oh_audiocodec_createbyname) (const char \*name) | 通过音频编解码器名称创建音频编解码器实例。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioCodec_Destroy](_audio_codec.md#oh_audiocodec_destroy) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec) | 清理编解码器内部资源，销毁编解码器实例。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioCodec_RegisterCallback](_audio_codec.md#oh_audiocodec_registercallback) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, [OH_AVCodecCallback](_o_h___a_v_codec_callback.md) callback, void \*userData) | 设置异步回调函数，让应用可以响应音频编解码器生成的事件。在调用Prepare之前，必须调用此接口。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioCodec_Configure](_audio_codec.md#oh_audiocodec_configure) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, const [OH_AVFormat](_core.md#oh_avformat) \*format) | 配置音频描述信息。音频编解码器通常会根据音频描述信息进行配置。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioCodec_Prepare](_audio_codec.md#oh_audiocodec_prepare) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec) | 准备编解码器的内部资源。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioCodec_Start](_audio_codec.md#oh_audiocodec_start) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec) | 调用此接口启动编解码器，在Prepare成功后执行。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioCodec_Stop](_audio_codec.md#oh_audiocodec_stop) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec) | 停止编解码器。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioCodec_Flush](_audio_codec.md#oh_audiocodec_flush) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec) | 清除编解码器中缓存的输入和输出数据。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioCodec_Reset](_audio_codec.md#oh_audiocodec_reset) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec) | 重置编解码器。此时会清空已配置的参数和输入输出数据。<br>如果要继续编解码，需要再次调用Configure接口配置编解码器实例。  | 
| [OH_AVFormat](_core.md#oh_avformat) \* [OH_AudioCodec_GetOutputDescription](_audio_codec.md#oh_audiocodec_getoutputdescription) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec) | 获取编解码器输出数据的描述信息。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioCodec_SetParameter](_audio_codec.md#oh_audiocodec_setparameter) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, const [OH_AVFormat](_core.md#oh_avformat) \*format) | 配置编解码器的动态参数。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioCodec_PushInputBuffer](_audio_codec.md#oh_audiocodec_pushinputbuffer) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t index) | 通知音频编解码器已完成对index所对应缓冲区进行输入数据的填充。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioCodec_FreeOutputBuffer](_audio_codec.md#oh_audiocodec_freeoutputbuffer) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t index) | 将处理后的输出缓冲区返回给编解码器。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioCodec_IsValid](_audio_codec.md#oh_audiocodec_isvalid) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, bool \*isValid) | 检查当前编解码器实例是否有效。<br>可用于后台故障恢复或应用程序从后台恢复时检测编解码器有效状态。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioCodec_SetDecryptionConfig](_audio_codec.md#oh_audiocodec_setdecryptionconfig) ([OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, MediaKeySession \*mediaKeySession, bool secureAudio) | 设置解密信息。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioCodec_QueryInputBuffer](_audio_codec.md#oh_audiocodec_queryinputbuffer) (struct [OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t *index, int64_t timeoutUs) | 在设置的超时时间内，尝试查询对应音频编解码器可用的输入缓冲区的索引值。  | 
| [OH_AVBuffer](_core.md#oh_avbuffer) \*[OH_AudioCodec_GetInputBuffer](_audio_codec.md#oh_audiocodec_getinputbuffer)(struct [OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t index) | 输入索引值，获取对应音频编解码器中该索引值对应的输入缓冲区。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AudioCodec_QueryOutputBuffer](_audio_codec.md#oh_audiocodec_queryoutputbuffer)(struct [OH_AVCodec](_codec_base.md#oh_avcodec) \*codec, uint32_t \*index, int64_t timeoutUs) | 在设置的超时时间内，尝试查询对应音频编解码器可用的输出缓冲区的索引值。  | 
| [OH_AVBuffer](_core.md#oh_avbuffer) \*[OH_AudioCodec_GetOutputBuffer](_audio_codec.md#oh_audiocodec_getoutputbuffer)(struct [OH_AVCodec](_codec_base.md#oh_avcodec) *codec, uint32_t index) | 输入索引值，获取对应音频编解码器中该索引值对应的输出缓冲区。  | 
