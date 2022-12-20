# VideoEncoder


## 概述

VideoEncoder模块提供用于视频编码功能的函数和枚举。

@syscap SystemCapability.Multimedia.Media.VideoEncoder

**Since:**
9
**Version:**
1.0

## 汇总


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [native_avcodec_videoencoder.h](native__avcodec__videoencoder_8h.md) | 声明用于视频编码的Native&nbsp;API。&nbsp; | 


### 类型定义

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_VideoEncodeBitrateMode](#ohvideoencodebitratemode) | typedef&nbsp;enum&nbsp;[OH_VideoEncodeBitrateMode](#ohvideoencodebitratemode)<br/>视频编码的比特率模式。&nbsp; | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_VideoEncodeBitrateMode](#ohvideoencodebitratemode)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001473332525.xml#xref742950777182348,link:zh-cn_topic_0000001473332525.xml#ggae5aed6bb1e318f7fc489a7cb859578e1adb1ecf549b5c6f145b2aff320909c70e](#ggae5aed6bb1e318f7fc489a7cb859578e1adb1ecf549b5c6f145b2aff320909c70e)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001473332525.xml#xref925239518182348,link:zh-cn_topic_0000001473332525.xml#ggae5aed6bb1e318f7fc489a7cb859578e1a5cd8a75942875437b0216e7e61693596](#ggae5aed6bb1e318f7fc489a7cb859578e1a5cd8a75942875437b0216e7e61693596)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001473332525.xml#xref1027861602182348,link:zh-cn_topic_0000001473332525.xml#ggae5aed6bb1e318f7fc489a7cb859578e1a3714c38a79124f71d2ec3fa8f9c03bc4](#ggae5aed6bb1e318f7fc489a7cb859578e1a3714c38a79124f71d2ec3fa8f9c03bc4)&nbsp;=&nbsp;2&nbsp;} | 视频编码的比特率模式。&nbsp; | 


### 函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_VideoEncoder_CreateByMime](#ohvideoencodercreatebymime)&nbsp;(const&nbsp;char&nbsp;\*mime) | OH_AVCodec&nbsp;\*<br/>通过mime类型创建一个视频编码器实例，大多数情况下推荐使用该接口。&nbsp; | 
| [OH_VideoEncoder_CreateByName](#ohvideoencodercreatebyname)&nbsp;(const&nbsp;char&nbsp;\*name) | OH_AVCodec&nbsp;\*<br/>通过视频编码器名称创建一个视频编码器实例，使用这个接口的前提是必须清楚编码器准确的名称。&nbsp; | 
| [OH_VideoEncoder_Destroy](#ohvideoencoderdestroy)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>清空编码器内部资源，并销毁编码器实例。&nbsp; | 
| [OH_VideoEncoder_SetCallback](#ohvideoencodersetcallback)&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;[OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md)&nbsp;callback,&nbsp;void&nbsp;\*userData) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>设置异步回调函数，使得你的应用能够响应视频编码器产生的事件，该接口被调用必须是在Prepare被调用前。&nbsp; | 
| [OH_VideoEncoder_Configure](#ohvideoencoderconfigure)&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;OH_AVFormat&nbsp;\*format) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>配置视频编码器，典型地，需要配置被编码视频轨道的描述信息，该接口被调用必须是在Prepare被调用前。&nbsp; | 
| [OH_VideoEncoder_Prepare](#ohvideoencoderprepare)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>准备编码器内部资源，调用该接口前必须先调用Configure接口。&nbsp; | 
| [OH_VideoEncoder_Start](#ohvideoencoderstart)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>启动编码器，该接口必须在已经Prepare成功后调用。&nbsp;在启动成功后，编码器将开始报告[OH_AVCodecOnNeedInputData](_codec_base.md#ohavcodeconneedinputdata)事件。&nbsp; | 
| [OH_VideoEncoder_Stop](#ohvideoencoderstop)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>停止编码器。在停止后可通过Start重新进入Started状态。&nbsp; | 
| [OH_VideoEncoder_Flush](#ohvideoencoderflush)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>清空编码器内部缓存的输入输出数据。在该接口被调用后，所有先前通过异步回调报告的Buffer的索引都将&nbsp;失效，确保不要再访问这些索引对应的Buffers。&nbsp; | 
| [OH_VideoEncoder_Reset](#ohvideoencoderreset)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>重置编码器。如需继续编码工作，需要重新调用Configure接口以配置该编码器实例。&nbsp; | 
| [OH_VideoEncoder_GetOutputDescription](#ohvideoencodergetoutputdescription)&nbsp;(OH_AVCodec&nbsp;\*codec) | OH_AVFormat&nbsp;\*<br/>获取该编码器输出数据的描述信息，需要注意的是，返回值所指向的OH_AVFormat实例的生命周期&nbsp;将会再下一次调用该接口时或者该OH_AVCodec实例被销毁时失效。&nbsp; | 
| [OH_VideoEncoder_SetParameter](#ohvideoencodersetparameter)&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;OH_AVFormat&nbsp;\*format) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>向编码器设置动态参数，注意：该接口仅能在编码器被启动后调用，同时错误的参数设置，可能会导致编码失败。&nbsp; | 
| [OH_VideoEncoder_GetSurface](#ohvideoencodergetsurface)&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;OHNativeWindow&nbsp;\*\*window) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>从视频编码器获取输入Surface，&nbsp;该接口被调用必须是在Prepare被调用前。&nbsp; | 
| [OH_VideoEncoder_FreeOutputData](#ohvideoencoderfreeoutputdata)&nbsp;(OH_AVCodec&nbsp;\*codec,&nbsp;uint32_t&nbsp;index) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>将处理结束的输出Buffer交还给编码器。&nbsp; | 
| [OH_VideoEncoder_NotifyEndOfStream](#ohvideoencodernotifyendofstream)&nbsp;(OH_AVCodec&nbsp;\*codec) | [OH_AVErrCode](_core.md#ohaverrcode)<br/>通知视频编码器输入码流已结束。surface模式推荐使用该接口通知编码器码流结束。&nbsp; | 


## 类型定义说明


### OH_VideoEncodeBitrateMode

  
```
typedef enum OH_VideoEncodeBitrateModeOH_VideoEncodeBitrateMode
```
**描述:**
视频编码的比特率模式。

@syscap SystemCapability.Multimedia.Media.VideoEncoder


## 枚举类型说明


### OH_VideoEncodeBitrateMode

  
```
enum OH_VideoEncodeBitrateMode
```
**描述:**
视频编码的比特率模式。

@syscap SystemCapability.Multimedia.Media.VideoEncoder

  | 枚举值 | 描述 | 
| -------- | -------- |
| CBR&nbsp; | 恒定比特率模式 | 
| VBR&nbsp; | 可变比特率模式 | 
| CQ&nbsp; | 恒定质量模式 | 


## 函数说明


### OH_VideoEncoder_Configure()

  
```
OH_AVErrCode OH_VideoEncoder_Configure (OH_AVCodec * codec, OH_AVFormat * format )
```
**描述:**
配置视频编码器，典型地，需要配置被编码视频轨道的描述信息，该接口被调用必须是在Prepare被调用前。

@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针&nbsp; | 
| format | 指向OH_AVFormat的指针，用以给出待编码视频轨道的描述信息&nbsp; | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_VideoEncoder_CreateByMime()

  
```
OH_AVCodec* OH_VideoEncoder_CreateByMime (const char * mime)
```
**描述:**
通过mime类型创建一个视频编码器实例，大多数情况下推荐使用该接口。

@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mime | mime类型描述字符串，参考[OH_AVCODEC_MIMETYPE_VIDEO_AVC](_codec_base.md#ohavcodecmimetypevideoavc) | 

**返回:**

返回一个指向OH_AVCodec实例的指针


### OH_VideoEncoder_CreateByName()

  
```
OH_AVCodec* OH_VideoEncoder_CreateByName (const char * name)
```
**描述:**
通过视频编码器名称创建一个视频编码器实例，使用这个接口的前提是必须清楚编码器准确的名称。

@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| name | 视频编码器名称&nbsp; | 

**返回:**

返回一个指向OH_AVCodec实例的指针


### OH_VideoEncoder_Destroy()

  
```
OH_AVErrCode OH_VideoEncoder_Destroy (OH_AVCodec * codec)
```
**描述:**
清空编码器内部资源，并销毁编码器实例。

@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针&nbsp; | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_VideoEncoder_Flush()

  
```
OH_AVErrCode OH_VideoEncoder_Flush (OH_AVCodec * codec)
```
**描述:**
清空编码器内部缓存的输入输出数据。在该接口被调用后，所有先前通过异步回调报告的Buffer的索引都将 失效，确保不要再访问这些索引对应的Buffers。

@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针&nbsp; | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_VideoEncoder_FreeOutputData()

  
```
OH_AVErrCode OH_VideoEncoder_FreeOutputData (OH_AVCodec * codec, uint32_t index )
```
**描述:**
将处理结束的输出Buffer交还给编码器。

@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针&nbsp; | 
| index | 输出Buffer对应的索引值&nbsp; | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_VideoEncoder_GetOutputDescription()

  
```
OH_AVFormat* OH_VideoEncoder_GetOutputDescription (OH_AVCodec * codec)
```
**描述:**
获取该编码器输出数据的描述信息，需要注意的是，返回值所指向的OH_AVFormat实例的生命周期 将会再下一次调用该接口时或者该OH_AVCodec实例被销毁时失效。

@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针&nbsp; | 

**返回:**

返回AVFormat实例的指针


### OH_VideoEncoder_GetSurface()

  
```
OH_AVErrCode OH_VideoEncoder_GetSurface (OH_AVCodec * codec, OHNativeWindow ** window )
```
**描述:**
从视频编码器获取输入Surface， 该接口被调用必须是在Prepare被调用前。

@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针&nbsp; | 
| window | 指向一个OHNativeWindow实例的指针&nbsp; | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_VideoEncoder_NotifyEndOfStream()

  
```
OH_AVErrCode OH_VideoEncoder_NotifyEndOfStream (OH_AVCodec * codec)
```
**描述:**
通知视频编码器输入码流已结束。surface模式推荐使用该接口通知编码器码流结束。

@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针&nbsp; | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_VideoEncoder_Prepare()

  
```
OH_AVErrCode OH_VideoEncoder_Prepare (OH_AVCodec * codec)
```
**描述:**
准备编码器内部资源，调用该接口前必须先调用Configure接口。

@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针&nbsp; | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_VideoEncoder_Reset()

  
```
OH_AVErrCode OH_VideoEncoder_Reset (OH_AVCodec * codec)
```
**描述:**
重置编码器。如需继续编码工作，需要重新调用Configure接口以配置该编码器实例。

@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针&nbsp; | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_VideoEncoder_SetCallback()

  
```
OH_AVErrCode OH_VideoEncoder_SetCallback (OH_AVCodec * codec, OH_AVCodecAsyncCallback callback, void * userData )
```
**描述:**
设置异步回调函数，使得你的应用能够响应视频编码器产生的事件，该接口被调用必须是在Prepare被调用前。

@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针&nbsp; | 
| callback | 一个包含所有回调函数的集合体，参考[OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md) | 
| userData | 用户特定数据&nbsp; | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_VideoEncoder_SetParameter()

  
```
OH_AVErrCode OH_VideoEncoder_SetParameter (OH_AVCodec * codec, OH_AVFormat * format )
```
**描述:**
向编码器设置动态参数，注意：该接口仅能在编码器被启动后调用，同时错误的参数设置，可能会导致编码失败。

@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针&nbsp; | 
| format | OH_AVFormat句柄指针&nbsp; | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_VideoEncoder_Start()

  
```
OH_AVErrCode OH_VideoEncoder_Start (OH_AVCodec * codec)
```
**描述:**
启动编码器，该接口必须在已经Prepare成功后调用。 在启动成功后，编码器将开始报告[OH_AVCodecOnNeedInputData](_codec_base.md#ohavcodeconneedinputdata)事件。

@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针&nbsp; | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)


### OH_VideoEncoder_Stop()

  
```
OH_AVErrCode OH_VideoEncoder_Stop (OH_AVCodec * codec)
```
**描述:**
停止编码器。在停止后可通过Start重新进入Started状态。

@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针&nbsp; | 

**返回:**

执行成功返回AV_ERR_OK

执行失败返回具体错误码，参考[OH_AVErrCode](_core.md#ohaverrcode)
