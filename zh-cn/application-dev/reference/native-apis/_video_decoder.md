# VideoDecoder


## 概述

VideoDecoder模块提供用于视频解码的函数。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**起始版本：**

9


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_avcodec_videodecoder.h](native__avcodec__videodecoder_8h.md) | 声明用于视频解码的Native API。<br>**引用文件**：<multimedia/player_framework/native_avcodec_videodecoder.h><br>**库**：libnative_media_vdec.so  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_VideoDecoder_CreateByMime](#oh_videodecoder_createbymime) (const char \*mime) | 从MIME类型创建视频解码器实例，大多数情况下建议使用。 | 
| \*[OH_VideoDecoder_CreateByName](#oh_videodecoder_createbyname) (const char \*name) | 通过视频解码器名称创建视频解码器实例。 使用此接口的前提是知道解码器的确切名称。 | 
| [OH_VideoDecoder_Destroy](#oh_videodecoder_destroy) (OH_AVCodec \*codec) | 清理解码器内部资源，销毁解码器实例。 | 
| [OH_VideoDecoder_SetCallback](#oh_videodecoder_setcallback) (OH_AVCodec \*codec, OH_AVCodecAsyncCallback callback, void \*userData) | 设置异步回调函数，以便您的应用程序可以响应视频解码器生成的事件。 | 
| [OH_VideoDecoder_SetSurface](#oh_videodecoder_setsurface) (OH_AVCodec \*codec, OHNativeWindow \*window) | 指定输出表面以提供视频解码输出，必须在调用Prepare之前调用此接口。 | 
| [OH_VideoDecoder_Configure](#oh_videodecoder_configure) (OH_AVCodec \*codec, OH_AVFormat \*format) | 配置视频解码器，通常需要配置解码视频轨迹的描述信息，这些信息可以从容器中提取。 | 
| [OH_VideoDecoder_Prepare](#oh_videodecoder_prepare) (OH_AVCodec \*codec) | 要准备解码器的内部资源，在调用该接口之前，必须调用Configure接口。 | 
| [OH_VideoDecoder_Start](#oh_videodecoder_start) (OH_AVCodec \*codec) | 启动解码器，准备成功后必须调用此接口。 | 
| [OH_VideoDecoder_Stop](#oh_videodecoder_stop) (OH_AVCodec \*codec) | 停止解码器。 | 
| [OH_VideoDecoder_Flush](#oh_videodecoder_flush) (OH_AVCodec \*codec) | 清除解码器中缓存的输入和输出数据。 | 
| [OH_VideoDecoder_Reset](#oh_videodecoder_reset) (OH_AVCodec \*codec) | 重置解码器。 | 
| \*[OH_VideoDecoder_GetOutputDescription](#oh_videodecoder_getoutputdescription) (OH_AVCodec \*codec) | 获取解码器输出数据的描述信息。 | 
| [OH_VideoDecoder_SetParameter](#oh_videodecoder_setparameter) (OH_AVCodec \*codec, OH_AVFormat \*format) | 设置解码器的动态参数。 | 
| [OH_VideoDecoder_PushInputData](#oh_videodecoder_pushinputdata) (OH_AVCodec \*codec, uint32_t index, OH_AVCodecBufferAttr attr) | 将填充数据的输入缓冲区提交给视频解码器。 | 
| [OH_VideoDecoder_RenderOutputData](#oh_videodecoder_renderoutputdata) (OH_AVCodec \*codec, uint32_t index) | 将处理后的输出Buffer返回给解码器，并通知解码器完成在输出表面上渲染Buffer中包含的解码数据。 | 
| [OH_VideoDecoder_FreeOutputData](#oh_videodecoder_freeoutputdata) (OH_AVCodec \*codec, uint32_t index) | 将处理后的输出缓冲区返回到解码器。 | 
| [OH_VideoDecoder_IsValid](#oh_videodecoder_isvalid) (OH_AVCodec \*codec, bool \*isValid) | 检查当前编解码实例是否有效。 | 


## 函数说明


### OH_VideoDecoder_Configure()

  
```
OH_AVErrCode OH_VideoDecoder_Configure (OH_AVCodec *codec, OH_AVFormat *format)
```

**描述：**

配置视频解码器，通常需要配置解码视频轨迹的描述信息，这些信息可以从容器中提取。

在调用准备之前，必须调用此接口。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针 | 
| format | 指向OH_AVFormat的指针，用于给出要解码的视频轨道的描述 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoDecoder_CreateByMime()

  
```
OH_AVCodec* OH_VideoDecoder_CreateByMime (const char *mime)
```

**描述：**

从MIME类型创建视频解码器实例，大多数情况下建议使用。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| mime | MIME类型描述字符串，请参阅 [AVCODEC_MIMETYPE](_codec_base.md#变量)。 | 

**返回：**

返回一个指向OH_AVCodec实例的指针。

**起始版本：**

9


### OH_VideoDecoder_CreateByName()

  
```
OH_AVCodec* OH_VideoDecoder_CreateByName (const char *name)
```

**描述：**

通过视频解码器名称创建视频解码器实例。 使用此接口的前提是知道解码器的确切名称。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| name | 视频编解码器名称。 | 

**返回：**

返回指向OH_AVCodec实例的指针。

**起始版本：**

9


### OH_VideoDecoder_Destroy()

  
```
OH_AVErrCode OH_VideoDecoder_Destroy (OH_AVCodec *codec)
```

**描述：**

清理解码器内部资源，销毁解码器实例。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoDecoder_Flush()

  
```
OH_AVErrCode OH_VideoDecoder_Flush (OH_AVCodec *codec)
```

**描述：**

清除解码器中缓存的输入和输出数据。

调用此接口后，以前通过异步回调上报的所有缓冲区索引都将失效， 请确保不要访问这些索引对应的缓冲区。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoDecoder_FreeOutputData()

  
```
OH_AVErrCode OH_VideoDecoder_FreeOutputData (OH_AVCodec *codec, uint32_t index)
```

**描述：**

将处理后的输出缓冲区返回到解码器。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 
| index | 输出Buffer对应的索引值。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoDecoder_GetOutputDescription()

  
```
OH_AVFormat* OH_VideoDecoder_GetOutputDescription (OH_AVCodec *codec)
```

**描述：**

获取解码器输出数据的描述信息，参见**OH_AVFormat**。

需要注意的是，返回值指向的OH_AVFormat实例的生命周期需要调用者手动释放。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 

**返回：**

返回指向OH_AVFormat实例的指针。

**起始版本：**

9


### OH_VideoDecoder_IsValid()

  
```
OH_AVErrCode OH_VideoDecoder_IsValid (OH_AVCodec *codec, bool *isValid)
```

**描述：**

检查当前编解码实例是否有效。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 
| isVaild | 输出参数。指向布尔实例的指针，如果编解码器实例有效，则为true，如果编解码器实例无效，则为false。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_VideoDecoder_Prepare()

  
```
OH_AVErrCode OH_VideoDecoder_Prepare (OH_AVCodec *codec)
```

**描述：**

要准备解码器的内部资源，在调用该接口之前，必须调用Configure接口。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoDecoder_PushInputData()

  
```
OH_AVErrCode OH_VideoDecoder_PushInputData (OH_AVCodec *codec, uint32_t index, OH_AVCodecBufferAttr attr)
```

**描述：**

将填充数据的输入缓冲区提交给视频解码器。

**OH_AVCodecOnNeedInputData**回调将报告可用的输入缓冲区和相应的索引值。

一旦具有指定索引的缓冲区提交到视频解码器，则无法再次访问缓冲区，直到再次收到**OH_AVCodecOnNeedInputData**回调，报告具有相同索引的缓冲区可用。

此外，对于某些解码器，需要在开始时向解码器输入编解码特定数据，以初始化解码器的解码过程，如H264格式的PPS/SPS数据。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 
| index | 输入Buffer对应的索引值。 | 
| attr | 描述缓冲区中包含的数据的信息。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoDecoder_RenderOutputData()

  
```
OH_AVErrCode OH_VideoDecoder_RenderOutputData (OH_AVCodec *codec, uint32_t index)
```

**描述：**

将处理后的输出Buffer返回给解码器，并通知解码器完成在输出表面上渲染Buffer中包含的解码数据。

如果之前没有配置输出表面，则调用此接口仅将指定索引对应的输出缓冲区返回给解码器。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 
| index | 输出Buffer对应的索引值。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoDecoder_Reset()

  
```
OH_AVErrCode OH_VideoDecoder_Reset (OH_AVCodec *codec)
```

**描述：**

重置解码器。如果要继续解码，需要再次调用Configure接口配置解码器实例。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoDecoder_SetCallback()

  
```
OH_AVErrCode OH_VideoDecoder_SetCallback (OH_AVCodec *codec, OH_AVCodecAsyncCallback callback, void *userData)
```

**描述：**

设置异步回调函数，以便您的应用程序可以响应视频解码器生成的事件。

在调用Prepare之前，必须调用此接口。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 
| callback | 所有回调函数的集合，请参见 [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md)。 | 
| userData | 用户特定数据。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoDecoder_SetParameter()

  
```
OH_AVErrCode OH_VideoDecoder_SetParameter (OH_AVCodec *codec, OH_AVFormat *format)
```

**描述：**

设置解码器的动态参数。

注意，该接口只能在解码器启动后调用。 同时，参数配置错误可能会导致解码失败。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 
| format | 指向OH_AVFormat实例的指针。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoDecoder_SetSurface()

  
```
OH_AVErrCode OH_VideoDecoder_SetSurface (OH_AVCodec *codec, OHNativeWindow *window)
```

**描述：**

指定输出表面以提供视频解码输出，必须在调用Prepare之前调用此接口。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 
| window | 指向OHNativeWindow实例的指针，请参见{\@链接OHNativeWindow}。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoDecoder_Start()

  
```
OH_AVErrCode OH_VideoDecoder_Start (OH_AVCodec *codec)
```

**描述：**

启动解码器，准备成功后必须调用此接口。

成功启动后，解码器将开始报告NeedInputData事件。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoDecoder_Stop()

  
```
OH_AVErrCode OH_VideoDecoder_Stop (OH_AVCodec *codec)
```

**描述：**

停止解码器。停止后，您可以通过Start重新进入Started状态。

但需要注意的是，如果编解码器特定数据以前已输入到解码器，则需要再次输入。

\@syscap SystemCapability.Multimedia.Media.VideoDecoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 

**返回：**

如果执行成功，则返回AV_ERR_OK， 否则返回特定错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9
