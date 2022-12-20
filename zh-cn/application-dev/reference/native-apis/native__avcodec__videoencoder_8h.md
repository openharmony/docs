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
| [OH_VideoEncodeBitrateMode](_video_encoder.md#ohvideoencodebitratemode) | typedef&nbsp;enum&nbsp;[OH_VideoEncodeBitrateMode](_video_encoder.md#ohvideoencodebitratemode)<br/>视频编码的比特率模式。&nbsp; | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_VideoEncodeBitrateMode](_video_encoder.md#ohvideoencodebitratemode)&nbsp;{&nbsp;[CBR](_video_encoder.md#ggae5aed6bb1e318f7fc489a7cb859578e1adb1ecf549b5c6f145b2aff320909c70e)&nbsp;=&nbsp;0,&nbsp;[VBR](_video_encoder.md#ggae5aed6bb1e318f7fc489a7cb859578e1a5cd8a75942875437b0216e7e61693596)&nbsp;=&nbsp;1,&nbsp;[CQ](_video_encoder.md#ggae5aed6bb1e318f7fc489a7cb859578e1a3714c38a79124f71d2ec3fa8f9c03bc4)&nbsp;=&nbsp;2&nbsp;} | 视频编码的比特率模式。&nbsp; | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_VideoEncoder_CreateByMime](_video_encoder.md#ohvideoencodercreatebymime)&nbsp;(const&nbsp;char&nbsp;\*mime) | OH_AVCodec&nbsp;\*<br/>通过mime类型创建一个视频编码器实例，大多数情况下推荐使用该接口。&nbsp; | 
| [OH_VideoEncoder_CreateByName](_video_encoder.md#ohvideoencodercreatebyname)&nbsp;(const&nbsp;char&nbsp;\*name) | OH_AVCodec&nbsp;\*<br/>通过视频编码器名称创建一个视频编码器实例，使用这个接口的前提是必须清楚编码器准确的名称。&nbsp; | 
| [OH_VideoEncoder_Destroy](_video_encoder.md#ohvideoencoderdestroy)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>清空编码器内部资源，并销毁编码器实例。&nbsp; | 
| [OH_VideoEncoder_SetCallback](_video_encoder.md#ohvideoencodersetcallback)&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;[OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md)&nbsp;callback,&nbsp;void&nbsp;\*userData) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>设置异步回调函数，使得你的应用能够响应视频编码器产生的事件，该接口被调用必须是在Prepare被调用前。&nbsp; | 
| [OH_VideoEncoder_Configure](_video_encoder.md#ohvideoencoderconfigure)&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;OH_AVFormat&nbsp;\*format) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>配置视频编码器，典型地，需要配置被编码视频轨道的描述信息，该接口被调用必须是在Prepare被调用前。&nbsp; | 
| [OH_VideoEncoder_Prepare](_video_encoder.md#ohvideoencoderprepare)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>准备编码器内部资源，调用该接口前必须先调用Configure接口。&nbsp; | 
| [OH_VideoEncoder_Start](_video_encoder.md#ohvideoencoderstart)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>启动编码器，该接口必须在已经Prepare成功后调用。&nbsp;在启动成功后，编码器将开始报告[OH_AVCodecOnNeedInputData](_codec_base.md#ohavcodeconneedinputdata)事件。&nbsp; | 
| [OH_VideoEncoder_Stop](_video_encoder.md#ohvideoencoderstop)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>停止编码器。在停止后可通过Start重新进入Started状态。&nbsp; | 
| [OH_VideoEncoder_Flush](_video_encoder.md#ohvideoencoderflush)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>清空编码器内部缓存的输入输出数据。在该接口被调用后，所有先前通过异步回调报告的Buffer的索引都将&nbsp;失效，确保不要再访问这些索引对应的Buffers。&nbsp; | 
| [OH_VideoEncoder_Reset](_video_encoder.md#ohvideoencoderreset)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>重置编码器。如需继续编码工作，需要重新调用Configure接口以配置该编码器实例。&nbsp; | 
| [OH_VideoEncoder_GetOutputDescription](_video_encoder.md#ohvideoencodergetoutputdescription)&nbsp;(OH_AVCodec&nbsp;\*codec) | OH_AVFormat&nbsp;\*<br/>获取该编码器输出数据的描述信息，需要注意的是，返回值所指向的OH_AVFormat实例的生命周期&nbsp;将会再下一次调用该接口时或者该OH_AVCodec实例被销毁时失效。&nbsp; | 
| [OH_VideoEncoder_SetParameter](_video_encoder.md#ohvideoencodersetparameter)&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;OH_AVFormat&nbsp;\*format) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>向编码器设置动态参数，注意：该接口仅能在编码器被启动后调用，同时错误的参数设置，可能会导致编码失败。&nbsp; | 
| [OH_VideoEncoder_GetSurface](_video_encoder.md#ohvideoencodergetsurface)&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;OHNativeWindow&nbsp;\*\*window) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>从视频编码器获取输入Surface，&nbsp;该接口被调用必须是在Prepare被调用前。&nbsp; | 
| [OH_VideoEncoder_FreeOutputData](_video_encoder.md#ohvideoencoderfreeoutputdata)&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;uint32_t&nbsp;index) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>将处理结束的输出Buffer交还给编码器。&nbsp; | 
| [OH_VideoEncoder_NotifyEndOfStream](_video_encoder.md#ohvideoencodernotifyendofstream)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>通知视频编码器输入码流已结束。surface模式推荐使用该接口通知编码器码流结束。&nbsp; | 
