# native_avcodec_videoencoder.h


## 概述

声明用于视频编码的Native API。

**Since:**
9
**Version:**
1.0
**相关模块:**

[VideoEncoder](_video_encoder.md)


## 汇总


### 类型定义

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_VideoEncodeBitrateMode](_video_encoder.md#ohvideoencodebitratemode) | typedef enum [OH_VideoEncodeBitrateMode](_video_encoder.md#ohvideoencodebitratemode)<br/>视频编码的比特率模式。  | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_VideoEncodeBitrateMode](_video_encoder.md#ohvideoencodebitratemode) { **CBR** = 0, **VBR** = 1, **CQ** = 2 } | 视频编码的比特率模式。  | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_VideoEncoder_CreateByMime](_video_encoder.md#ohvideoencodercreatebymime) (const char \*mime) | OH_AVCodec \*<br/>通过mime类型创建一个视频编码器实例，大多数情况下推荐使用该接口。  | 
| [OH_VideoEncoder_CreateByName](_video_encoder.md#ohvideoencodercreatebyname) (const char \*name) | OH_AVCodec \*<br/>通过视频编码器名称创建一个视频编码器实例，使用这个接口的前提是必须清楚编码器准确的名称。  | 
| [OH_VideoEncoder_Destroy](_video_encoder.md#ohvideoencoderdestroy) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>清空编码器内部资源，并销毁编码器实例。  | 
| [OH_VideoEncoder_SetCallback](_video_encoder.md#ohvideoencodersetcallback) (OH_AVCodec \*codec, [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) callback, void \*userData) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>设置异步回调函数，使得你的应用能够响应视频编码器产生的事件，该接口被调用必须是在Prepare被调用前。  | 
| [OH_VideoEncoder_Configure](_video_encoder.md#ohvideoencoderconfigure) (OH_AVCodec \*codec, OH_AVFormat \*format) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>配置视频编码器，典型地，需要配置被编码视频轨道的描述信息，该接口被调用必须是在Prepare被调用前。  | 
| [OH_VideoEncoder_Prepare](_video_encoder.md#ohvideoencoderprepare) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>准备编码器内部资源，调用该接口前必须先调用Configure接口。  | 
| [OH_VideoEncoder_Start](_video_encoder.md#ohvideoencoderstart) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>启动编码器，该接口必须在已经Prepare成功后调用。 在启动成功后，编码器将开始报告[OH_AVCodecOnNeedInputData](_codec_base.md#oh_avcodeconneedinputdata)事件。  | 
| [OH_VideoEncoder_Stop](_video_encoder.md#ohvideoencoderstop) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>停止编码器。在停止后可通过Start重新进入Started状态。  | 
| [OH_VideoEncoder_Flush](_video_encoder.md#ohvideoencoderflush) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>清空编码器内部缓存的输入输出数据。在该接口被调用后，所有先前通过异步回调报告的Buffer的索引都将 失效，确保不要再访问这些索引对应的Buffers。  | 
| [OH_VideoEncoder_Reset](_video_encoder.md#ohvideoencoderreset) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>重置编码器。如需继续编码工作，需要重新调用Configure接口以配置该编码器实例。  | 
| [OH_VideoEncoder_GetOutputDescription](_video_encoder.md#ohvideoencodergetoutputdescription) (OH_AVCodec \*codec) | OH_AVFormat \*<br/>获取该编码器输出数据的描述信息，需要注意的是，返回值所指向的OH_AVFormat实例的生命周期 将会再下一次调用该接口时或者该OH_AVCodec实例被销毁时失效。  | 
| [OH_VideoEncoder_SetParameter](_video_encoder.md#ohvideoencodersetparameter) (OH_AVCodec \*codec, OH_AVFormat \*format) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>向编码器设置动态参数，注意：该接口仅能在编码器被启动后调用，同时错误的参数设置，可能会导致编码失败。  | 
| [OH_VideoEncoder_GetSurface](_video_encoder.md#ohvideoencodergetsurface) (OH_AVCodec \*codec, OHNativeWindow \*\*window) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>从视频编码器获取输入Surface， 该接口被调用必须是在Prepare被调用前。  | 
| [OH_VideoEncoder_FreeOutputData](_video_encoder.md#oh_videoencoder_freeoutputdata) (OH_AVCodec \*codec, uint32_t index) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>将处理结束的输出Buffer交还给编码器。  | 
| [OH_VideoEncoder_NotifyEndOfStream](_video_encoder.md#ohvideoencodernotifyendofstream) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>通知视频编码器输入码流已结束。surface模式推荐使用该接口通知编码器码流结束。  | 
