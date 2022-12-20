# native_avcodec_videodecoder.h


## 概述

声明用于视频解码的Native API。

**Since:**
9
**Version:**
1.0
**相关模块:**

[VideoDecoder](_video_decoder.md)


## 汇总


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_VideoDecoder_CreateByMime](_video_decoder.md#ohvideodecodercreatebymime)&nbsp;(const&nbsp;char&nbsp;\*mime) | OH_AVCodec&nbsp;\*<br/>通过mime类型创建一个视频解码器实例，大多数情况下推荐使用该接口。&nbsp; | 
| [OH_VideoDecoder_CreateByName](_video_decoder.md#ohvideodecodercreatebyname)&nbsp;(const&nbsp;char&nbsp;\*name) | OH_AVCodec&nbsp;\*<br/>通过视频解码器名称创建一个视频解码器实例，使用这个接口的前提是必须清楚解码器准确的名称。&nbsp; | 
| [OH_VideoDecoder_Destroy](_video_decoder.md#ohvideodecoderdestroy)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>清空解码器内部资源，并销毁解码器实例。&nbsp; | 
| [OH_VideoDecoder_SetCallback](_video_decoder.md#ohvideodecodersetcallback)&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;[OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md)&nbsp;callback,&nbsp;void&nbsp;\*userData) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>设置异步回调函数，使得你的应用能够响应视频解码器产生的事件，该接口被调用必须是在Prepare被调用前。&nbsp; | 
| [OH_VideoDecoder_SetSurface](_video_decoder.md#ohvideodecodersetsurface)&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;OHNativeWindow&nbsp;\*window) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>指定输出Surface，以提供视频解码输出，该接口被调用必须是在Prepare被调用前。&nbsp; | 
| [OH_VideoDecoder_Configure](_video_decoder.md#ohvideodecoderconfigure)&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;OH_AVFormat&nbsp;\*format) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>配置视频解码器，典型地，需要配置被解码视频轨道的描述信息，这些信息能够从容器中提取出来，&nbsp;该接口被调用必须是在Prepare被调用前。&nbsp; | 
| [OH_VideoDecoder_Prepare](_video_decoder.md#ohvideodecoderprepare)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>准备解码器内部资源，调用该接口前必须先调用Configure接口。&nbsp; | 
| [OH_VideoDecoder_Start](_video_decoder.md#ohvideodecoderstart)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>启动解码器，该接口必须在已经Prepare成功后调用。&nbsp;在启动成功后，解码器将开始报告[OH_AVCodecOnNeedInputData](_codec_base.md#ohavcodeconneedinputdata)事件。&nbsp; | 
| [OH_VideoDecoder_Stop](_video_decoder.md#ohvideodecoderstop)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>停止解码器。在停止后可通过Start重新进入Started状态，但需要注意的是，若先前给解码器输入过&nbsp;Codec-Specific-Data，则需要重新输入。&nbsp; | 
| [OH_VideoDecoder_Flush](_video_decoder.md#ohvideodecoderflush)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>清空解码器内部缓存的输入输出数据。在该接口被调用后，所有先前通过异步回调报告的Buffer的索引都将&nbsp;失效，确保不要再访问这些索引对应的Buffers。&nbsp; | 
| [OH_VideoDecoder_Reset](_video_decoder.md#ohvideodecoderreset)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>重置解码器。如需继续解码工作，需要重新调用Configure接口以配置该解码器实例。&nbsp; | 
| [OH_VideoDecoder_GetOutputDescription](_video_decoder.md#ohvideodecodergetoutputdescription)&nbsp;(OH_AVCodec&nbsp;\*codec) | OH_AVFormat&nbsp;\*<br/>获取该解码器输出数据的描述信息，需要注意的是，返回值所指向的OH_AVFormat实例的生命周期&nbsp;将会再下一次调用该接口时或者该OH_AVCodec实例被销毁时失效。&nbsp; | 
| [OH_VideoDecoder_SetParameter](_video_decoder.md#ohvideodecodersetparameter)&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;OH_AVFormat&nbsp;\*format) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>向解码器设置动态参数，注意：该接口仅能在解码器被启动后调用，同时错误的参数设置，可能会导致解码失败。&nbsp; | 
| [OH_VideoDecoder_PushInputData](_video_decoder.md#ohvideodecoderpushinputdata)&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;uint32_t&nbsp;index,&nbsp;[OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md)&nbsp;attr) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>将填充好数据的输入Buffer提交给视频解码器。[OH_AVCodecOnNeedInputData](_codec_base.md#ohavcodeconneedinputdata)回调会报告可用的输入&nbsp;Buffer及对应的索引值。一旦指定索引的Buffer被提交给解码器，直到再一次收到[OH_AVCodecOnNeedInputData](_codec_base.md#ohavcodeconneedinputdata)&nbsp;回调报告相同索引的Buffer可用前，该Buffer都不可以再次被访问。另外，对于部分解码器，要求在最开始给解码器输入&nbsp;Codec-Specific-Data，用以初始化解码器的解码过程，例如H264格式的PPS/SPS数据。&nbsp; | 
| [OH_VideoDecoder_RenderOutputData](_video_decoder.md#ohvideodecoderrenderoutputdata)&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;uint32_t&nbsp;index) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>将处理结束的输出Buffer交还给解码器，并通知解码器完成将该Buffer内包含的解码后的数据在输出Surface上渲染。&nbsp;如果先前未配置输出Surface，调用该接口仅仅将指定索引对应的输出Buffer交还给解码器。&nbsp; | 
| [OH_VideoDecoder_FreeOutputData](_video_decoder.md#ohvideodecoderfreeoutputdata)&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;uint32_t&nbsp;index) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>将处理结束的输出Buffer交还给解码器。&nbsp; | 
