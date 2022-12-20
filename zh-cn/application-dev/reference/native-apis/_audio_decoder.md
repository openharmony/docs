# AudioDecoder


## 概述

AudioDecoder模块提供用于音频解码功能的函数。

@syscap SystemCapability.Multimedia.Media.AudioDecoder

**Since:**
9
**Version:**
1.0

## 汇总


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [native_avcodec_audiodecoder.h](native__avcodec__audiodecoder_8h.md) | 声明用于音频解码的Native API。  | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioDecoder_CreateByMime](#ohaudiodecodercreatebymime) (const char \*mime) | OH_AVCodec \*<br/>通过mime类型创建一个音频解码器实例，大多数情况下推荐使用该接口。  | 
| [OH_AudioDecoder_CreateByName](#ohaudiodecodercreatebyname) (const char \*name) | OH_AVCodec \*<br/>通过音频解码器名称创建一个音频解码器实例，使用这个接口的前提是必须清楚解码器准确的名称。  | 
| [OH_AudioDecoder_Destroy](#ohaudiodecoderdestroy) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>清空解码器内部资源，并销毁解码器实例  | 
| [OH_AudioDecoder_SetCallback](#ohaudiodecodersetcallback) (OH_AVCodec \*codec, [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) callback, void \*userData) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>设置异步回调函数，使得你的应用能够响应音频解码器产生的事件，该接口被调用必须是在Prepare被调用前。  | 
| [OH_AudioDecoder_Configure](#ohaudiodecoderconfigure) (OH_AVCodec \*codec, OH_AVFormat \*format) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>配置音频解码器，典型地，需要配置被解码音频轨道的描述信息，这些信息能够从容器中提取出来， 该接口被调用必须是在Prepare被调用前。  | 
| [OH_AudioDecoder_Prepare](#ohaudiodecoderprepare) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>准备解码器内部资源，调用该接口前必须先调用Configure接口。  | 
| [OH_AudioDecoder_Start](#ohaudiodecoderstart) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>启动解码器，该接口必须在已经Prepare成功后调用。 在启动成功后，解码器将开始报告[OH_AVCodecOnNeedInputData](_codec_base.md#ohavcodeconneedinputdata)事件。  | 
| [OH_AudioDecoder_Stop](#ohaudiodecoderstop) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>停止解码器。在停止后可通过Start重新进入Started状态，但需要注意的是，若先前给解码器输入过 Codec-Specific-Data，则需要重新输入。  | 
| [OH_AudioDecoder_Flush](#ohaudiodecoderflush) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>清空解码器内部缓存的输入输出数据。在该接口被调用后，所有先前通过异步回调报告的Buffer的索引都将 失效，确保不要再访问这些索引对应的Buffers。  | 
| [OH_AudioDecoder_Reset](#ohaudiodecoderreset) (OH_AVCodec \*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>重置解码器。如需继续解码工作，需要重新调用Configure接口以配置该解码器实例。  | 
| [OH_AudioDecoder_GetOutputDescription](#ohaudiodecodergetoutputdescription) (OH_AVCodec \*codec) | OH_AVFormat \*<br/>获取该解码器输出数据的描述信息，需要注意的是，返回值所指向的OH_AVFormat实例需调用者手动释放。  | 
| [OH_AudioDecoder_SetParameter](#ohaudiodecodersetparameter) (OH_AVCodec \*codec, OH_AVFormat \*format) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>向解码器设置动态参数，注意：该接口仅能在解码器被启动后调用，同时错误的参数设置，可能会导致解码失败。  | 
| [OH_AudioDecoder_PushInputData](#ohaudiodecoderpushinputdata) (OH_AVCodec \*codec, uint32_t index, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) attr) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>将填充好数据的输入Buffer提交给音频解码器。[OH_AVCodecOnNeedInputData](_codec_base.md#ohavcodeconneedinputdata)回调会报告可用的输入 Buffer及对应的索引值。一旦指定索引的Buffer被提交给解码器，直到再一次收到[OH_AVCodecOnNeedInputData](_codec_base.md#ohavcodeconneedinputdata) 回调报告相同索引的Buffer可用前，该Buffer都不可以再次被访问。另外，对于部分解码器，要求在最开始给解码器输入 Codec-Specific-Data，用以初始化解码器的解码过程。  | 
| [OH_AudioDecoder_FreeOutputData](#ohaudiodecoderfreeoutputdata) (OH_AVCodec \*codec, uint32_t index) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>将处理结束的输出Buffer交还给解码器。  | 


## 函数说明


### OH_AudioDecoder_Configure()

  
```
OH_AVErrCode OH_AudioDecoder_Configure (OH_AVCodec * codec, OH_AVFormat * format )
```
**描述:**
配置音频解码器，典型地，需要配置被解码音频轨道的描述信息，这些信息能够从容器中提取出来， 该接口被调用必须是在Prepare被调用前。

@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针  | 
| format | 指向OH_AVFormat的指针，用以给出待解码音频轨道的描述信息  | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_AudioDecoder_CreateByMime()

  
```
OH_AVCodec* OH_AudioDecoder_CreateByMime (const char * mime)
```
**描述:**
通过mime类型创建一个音频解码器实例，大多数情况下推荐使用该接口。

@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mime | mime类型描述字符串，参考[OH_AVCODEC_MIMETYPE_AUDIO_AAC](_codec_base.md#ohavcodecmimetypeaudioaac) | 

**返回:**

返回一个指向OH_AVCodec实例的指针


### OH_AudioDecoder_CreateByName()

  
```
OH_AVCodec* OH_AudioDecoder_CreateByName (const char * name)
```
**描述:**
通过音频解码器名称创建一个音频解码器实例，使用这个接口的前提是必须清楚解码器准确的名称。

@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| name | 音频解码器名称  | 

**返回:**

返回一个指向OH_AVCodec实例的指针


### OH_AudioDecoder_Destroy()

  
```
OH_AVErrCode OH_AudioDecoder_Destroy (OH_AVCodec * codec)
```
**描述:**
清空解码器内部资源，并销毁解码器实例

@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针  | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_AudioDecoder_Flush()

  
```
OH_AVErrCode OH_AudioDecoder_Flush (OH_AVCodec * codec)
```
**描述:**
清空解码器内部缓存的输入输出数据。在该接口被调用后，所有先前通过异步回调报告的Buffer的索引都将 失效，确保不要再访问这些索引对应的Buffers。

@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针  | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_AudioDecoder_FreeOutputData()

  
```
OH_AVErrCode OH_AudioDecoder_FreeOutputData (OH_AVCodec * codec, uint32_t index )
```
**描述:**
将处理结束的输出Buffer交还给解码器。

@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针  | 
| index | 输出Buffer对应的索引值  | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_AudioDecoder_GetOutputDescription()

  
```
OH_AVFormat* OH_AudioDecoder_GetOutputDescription (OH_AVCodec * codec)
```
**描述:**
获取该解码器输出数据的描述信息，需要注意的是，返回值所指向的OH_AVFormat实例需调用者手动释放。

@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针  | 

**返回:**

返回OH_AVFormat句柄指针，需调用者手动释放;


### OH_AudioDecoder_Prepare()

  
```
OH_AVErrCode OH_AudioDecoder_Prepare (OH_AVCodec * codec)
```
**描述:**
准备解码器内部资源，调用该接口前必须先调用Configure接口。

@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针  | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_AudioDecoder_PushInputData()

  
```
OH_AVErrCode OH_AudioDecoder_PushInputData (OH_AVCodec * codec, uint32_t index, OH_AVCodecBufferAttr attr )
```
**描述:**
将填充好数据的输入Buffer提交给音频解码器。[OH_AVCodecOnNeedInputData](_codec_base.md#ohavcodeconneedinputdata)回调会报告可用的输入 Buffer及对应的索引值。一旦指定索引的Buffer被提交给解码器，直到再一次收到[OH_AVCodecOnNeedInputData](_codec_base.md#ohavcodeconneedinputdata) 回调报告相同索引的Buffer可用前，该Buffer都不可以再次被访问。另外，对于部分解码器，要求在最开始给解码器输入 Codec-Specific-Data，用以初始化解码器的解码过程。

@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针  | 
| index | 输入Buffer对应的索引值  | 
| attr | 描述该Buffer内所包含数据的信息  | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_AudioDecoder_Reset()

  
```
OH_AVErrCode OH_AudioDecoder_Reset (OH_AVCodec * codec)
```
**描述:**
重置解码器。如需继续解码工作，需要重新调用Configure接口以配置该解码器实例。

@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针  | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_AudioDecoder_SetCallback()

  
```
OH_AVErrCode OH_AudioDecoder_SetCallback (OH_AVCodec * codec, OH_AVCodecAsyncCallback callback, void * userData )
```
**描述:**
设置异步回调函数，使得你的应用能够响应音频解码器产生的事件，该接口被调用必须是在Prepare被调用前。

@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针  | 
| callback | 一个包含所有回调函数的集合体，参考[OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) | 
| userData | 用户特定数据  | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_AudioDecoder_SetParameter()

  
```
OH_AVErrCode OH_AudioDecoder_SetParameter (OH_AVCodec * codec, OH_AVFormat * format )
```
**描述:**
向解码器设置动态参数，注意：该接口仅能在解码器被启动后调用，同时错误的参数设置，可能会导致解码失败。

@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针  | 
| format | OH_AVFormat句柄指针  | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_AudioDecoder_Start()

  
```
OH_AVErrCode OH_AudioDecoder_Start (OH_AVCodec * codec)
```
**描述:**
启动解码器，该接口必须在已经Prepare成功后调用。 在启动成功后，解码器将开始报告[OH_AVCodecOnNeedInputData](_codec_base.md#ohavcodeconneedinputdata)事件。

@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针  | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_AudioDecoder_Stop()

  
```
OH_AVErrCode OH_AudioDecoder_Stop (OH_AVCodec * codec)
```
**描述:**
停止解码器。在停止后可通过Start重新进入Started状态，但需要注意的是，若先前给解码器输入过 Codec-Specific-Data，则需要重新输入。

@syscap SystemCapability.Multimedia.Media.AudioDecoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针  | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)
