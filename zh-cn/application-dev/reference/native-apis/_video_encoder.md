# VideoEncoder


## 概述

VideoEncoder模块提供用于视频编码功能的函数。

\@syscap SystemCapability.Multimedia.Avcodec.VideoEncoder

**起始版本：**

9


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_avcodec_videoencoder.h](native__avcodec__videoencoder_8h.md) | 声明用于视频编码的Native API。<br>**引用文件**：<multimedia/player_framework/native_avcodec_videoencoder.h><br> **库**：libnative_media_venc.so | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [OH_VideoEncodeBitrateMode](#oh_videoencodebitratemode) | 视频编码器的比特率模式。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_VideoEncodeBitrateMode](#oh_videoencodebitratemode) {<br/>&nbsp;&nbsp;&nbsp;&nbsp;**CBR** = 0,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**VBR** = 1,<br/>&nbsp;&nbsp;&nbsp;&nbsp;**CQ** = 2<br/>} | 视频编码器的比特率模式。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_VideoEncoder_CreateByMime](#oh_videoencoder_createbymime) (const char \*mime) | 多数情况下，推荐从MIME类型创建视频编码器实例。 | 
| \*[OH_VideoEncoder_CreateByName](#oh_videoencoder_createbyname) (const char \*name) | 通过视频编码器名称创建一个视频编码器实例。使用此接口的前提是知道编码器的确切名称。 | 
| [OH_VideoEncoder_Destroy](#oh_videoencoder_destroy) (OH_AVCodec \*codec) | 清除编码器的内部资源并销毁编码器实例。 | 
| [OH_VideoEncoder_SetCallback](#oh_videoencoder_setcallback) (OH_AVCodec \*codec, OH_AVCodecAsyncCallback callback, void \*userData) | 设置异步回调函数，以便您的应用程序能够响应视频编码器事件。 | 
| [OH_VideoEncoder_Configure](#oh_videoencoder_configure) (OH_AVCodec \*codec, OH_AVFormat \*format) | 配置视频编码器。 | 
| [OH_VideoEncoder_Prepare](#oh_videoencoder_prepare) (OH_AVCodec \*codec) | 若要准备编码器的内部资源，必须先调用Configure接口，再调用此接口。 | 
| [OH_VideoEncoder_Start](#oh_videoencoder_start) (OH_AVCodec \*codec) | 启动编码器, 这个接口必须要在Prepare接口执行成功后调用。 | 
| [OH_VideoEncoder_Stop](#oh_videoencoder_stop) (OH_AVCodec \*codec) | 停止编码器。 | 
| [OH_VideoEncoder_Flush](#oh_videoencoder_flush) (OH_AVCodec \*codec) | 清除编码器中缓冲的输入和输出数据。 | 
| [OH_VideoEncoder_Reset](#oh_videoencoder_reset) (OH_AVCodec \*codec) | 重置编码器。 | 
| \*[OH_VideoEncoder_GetOutputDescription](#oh_videoencoder_getoutputdescription) (OH_AVCodec \*codec) | 获取编码器输出数据的描述信息，详细信息请参阅 [OH_AVFormat](_core.md) 。 | 
| [OH_VideoEncoder_SetParameter](#oh_videoencoder_setparameter) (OH_AVCodec \*codec, OH_AVFormat \*format) | 为编码器设置动态参数。 | 
| [OH_VideoEncoder_GetSurface](#oh_videoencoder_getsurface) (OH_AVCodec \*codec, OHNativeWindow \*\*window) | 从视频编码器获取输入Surface，必须在调用Prepare之前调用此接口。 | 
| [OH_VideoEncoder_FreeOutputData](#oh_videoencoder_freeoutputdata) (OH_AVCodec \*codec, uint32_t index) | 将处理后的输出缓冲区返回给编码器。 | 
| [OH_VideoEncoder_NotifyEndOfStream](#oh_videoencoder_notifyendofstream) (OH_AVCodec \*codec) | 通知视频编码器输入流已结束。建议使用此接口进行通知。 | 
| [OH_VideoEncoder_PushInputData](#oh_videoencoder_pushinputdata) (OH_AVCodec \*codec, uint32_t index, OH_AVCodecBufferAttr attr) | 将填入数据的输入缓冲区提交给视频编码器。 | 
| \*[OH_VideoEncoder_GetInputDescription](#oh_videoencoder_getinputdescription) (OH_AVCodec \*codec) | 获取视频编码器接收的描述信息，调用Configure后调用此接口，请参阅 [OH_AVFormat](_core.md) 获取详细信息。 | 
| [OH_VideoEncoder_IsValid](#oh_videoencoder_isvalid) (OH_AVCodec \*codec, bool \*isValid) | 检查当前编解码器实例是否有效。 | 


## 类型定义说明


### OH_VideoEncodeBitrateMode

  
```
typedef enum OH_VideoEncodeBitrateMode OH_VideoEncodeBitrateMode
```

**描述：**

视频编码器的比特率模式。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：**

9


## 枚举类型说明


### OH_VideoEncodeBitrateMode

  
```
enum OH_VideoEncodeBitrateMode
```

**描述：**

视频编码器的比特率模式。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：**

9

| 枚举值 | 描述 |
| -------- | -------- |
| CBR | 恒定比特率模式。 | 
| VBR | 可变比特率模式。 | 
| CQ | 恒定质量模式。 | 


## 函数说明


### OH_VideoEncoder_Configure()

  
```
OH_AVErrCode OH_VideoEncoder_Configure (OH_AVCodec *codec, OH_AVFormat *format)
```

**描述：**

配置视频编码器。用于配置要编码的视频轨的描述信息。

必须在调用Prepare之前，调用此接口。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 
| format | 指向OH_AVFormat的指针，用于给出要编码的视频轨的描述。 | 

**返回：**

如果执行成功，返回AV_ERR_OK 否则，返回特定的错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoEncoder_CreateByMime()

  
```
OH_AVCodec* OH_VideoEncoder_CreateByMime (const char *mime)
```

**描述：**

多数情况下，推荐从MIME类型创建视频编码器实例。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| mime | MIME类型描述字符串，请参阅[AVCODEC_MIMETYPE](_codec_base.md#变量)。 | 

**返回：**

返回一个指向OH_AVCodec实例的指针, 需要调用OH_VideoEncoder_Destroy销毁。

**起始版本：**

9


### OH_VideoEncoder_CreateByName()

  
```
OH_AVCodec* OH_VideoEncoder_CreateByName (const char *name)
```

**描述：**

通过视频编码器名称创建一个视频编码器实例。使用此接口的前提是知道编码器的确切名称。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| name | 视频编码器名称。 | 

**返回：**

返回指向OH_AVCodec实例的指针。

**起始版本：**

9


### OH_VideoEncoder_Destroy()

  
```
OH_AVErrCode OH_VideoEncoder_Destroy (OH_AVCodec *codec)
```

**描述：**

清除编码器的内部资源并销毁编码器实例。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 

**返回：**

如果执行成功，返回AV_ERR_OK 否则，返回特定的错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoEncoder_Flush()

  
```
OH_AVErrCode OH_VideoEncoder_Flush (OH_AVCodec *codec)
```

**描述：**

清除编码器中缓冲的输入和输出数据。

调用此接口后，之前通过异步回调函数报告的索引将无效，请确保不要访问与这些索引相对应的缓冲区。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 

**返回：**

如果执行成功，返回AV_ERR_OK 否则，返回特定的错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoEncoder_FreeOutputData()

  
```
OH_AVErrCode OH_VideoEncoder_FreeOutputData (OH_AVCodec *codec, uint32_t index)
```

**描述：**

将处理后的输出缓冲区返回给编码器。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 
| index | 输出缓冲区对应的索引值。 | 

**返回：**

如果执行成功，返回AV_ERR_OK 否则，返回特定的错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoEncoder_GetInputDescription()

  
```
OH_AVFormat* OH_VideoEncoder_GetInputDescription (OH_AVCodec *codec)
```

**描述：**

获取视频编码器接收的描述信息，调用Configure后调用此接口，请参阅 **OH_AVFormat** 获取详细信息。

应该注意的是，返回指针所指向的OH_AVFormat实例的生命周期需要由调用者手动释放。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 

**返回：**

返回指向OH_AVFormat实例的指针。

**起始版本：**

10


### OH_VideoEncoder_GetOutputDescription()

  
```
OH_AVFormat* OH_VideoEncoder_GetOutputDescription (OH_AVCodec *codec)
```

**描述：**

获取编码器输出数据的描述信息，详细信息请参阅 **OH_AVFormat**。

需要注意的是，返回值指针指向的OH_AVFormat实例的生命周期需要由调用者手动释放。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 

**返回：**

返回指向OH_AVFormat实例的指针。

**起始版本：**

9


### OH_VideoEncoder_GetSurface()

  
```
OH_AVErrCode OH_VideoEncoder_GetSurface (OH_AVCodec *codec, OHNativeWindow **window)
```

**描述：**

从视频编码器获取输入Surface，必须在调用Prepare之前调用此接口。
应用负责管理window的生命周期，结束时调用OH_NativeWindow_DestroyNativeWindow()释放。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 
| window | 指向OHNativeWindow实例的指针, 参考 **OHNativeWindow**。 | 

**返回：**

如果执行成功，返回AV_ERR_OK 否则，返回特定的错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoEncoder_IsValid()

  
```
OH_AVErrCode OH_VideoEncoder_IsValid (OH_AVCodec *codec, bool *isValid)
```

**描述：**

检查当前编解码器实例是否有效。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 
| isValid | 指向布尔实例的指针，true: 编码器实例有效，false: 编码器实例无效。 | 

**返回：**

如果执行成功，返回AV_ERR_OK 否则，返回特定的错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_VideoEncoder_NotifyEndOfStream()

  
```
OH_AVErrCode OH_VideoEncoder_NotifyEndOfStream (OH_AVCodec *codec)
```

**描述：**

通知视频编码器输入流已结束。建议使用此接口进行通知。

编码器surface模式下，输入流的结束通知。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 

**返回：**

如果执行成功，返回AV_ERR_OK 否则，返回特定的错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoEncoder_Prepare()

  
```
OH_AVErrCode OH_VideoEncoder_Prepare (OH_AVCodec *codec)
```

**描述：**

若要准备编码器的内部资源，必须先调用Configure接口，再调用此接口。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 

**返回：**

如果执行成功，返回AV_ERR_OK 否则，返回特定的错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoEncoder_PushInputData()

  
```
OH_AVErrCode OH_VideoEncoder_PushInputData (OH_AVCodec *codec, uint32_t index, OH_AVCodecBufferAttr attr)
```

**描述：**

将填入数据的输入缓冲区提交给视频编码器。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 
| index | 输入缓冲区对应的索引值。 | 
| attr | 缓冲区中包含数据的描述信息。 | 

**返回：**

如果执行成功，返回AV_ERR_OK 否则，返回特定的错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

10


### OH_VideoEncoder_Reset()

  
```
OH_AVErrCode OH_VideoEncoder_Reset (OH_AVCodec *codec)
```

**描述：**

重置编码器。要继续编码，您需要再次调用Configure接口配置编码器实例。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 

**返回：**

如果执行成功，返回AV_ERR_OK 否则，返回特定的错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoEncoder_SetCallback()

  
```
OH_AVErrCode OH_VideoEncoder_SetCallback (OH_AVCodec *codec, OH_AVCodecAsyncCallback callback, void *userData)
```

**描述：**

设置异步回调函数，以便您的应用程序能够响应视频编码器事件。

必须在调用Prepare之前，调用此接口。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 
| callback | 所有回调函数的集合，请参阅 [OH_AVCodecAsyncCallback](_o_h___a_v_codec_async_callback.md)。 | 
| userData | 用户的特定数据。 | 

**返回：**

如果执行成功，返回AV_ERR_OK 否则，返回特定的错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoEncoder_SetParameter()

  
```
OH_AVErrCode OH_VideoEncoder_SetParameter (OH_AVCodec *codec, OH_AVFormat *format)
```

**描述：**

为编码器设置动态参数。

注意，此接口只有在编码器启动后才能调用。 同时，不正确的参数设置可能会导致编码失败。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 
| format | OH_AVFormat句柄指针。 | 

**返回：**

如果执行成功，返回AV_ERR_OK 否则，返回特定的错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoEncoder_Start()

  
```
OH_AVErrCode OH_VideoEncoder_Start (OH_AVCodec *codec)
```

**描述：**

启动编码器, 这个接口必须要在Prepare接口执行成功后调用。

在成功启动编码器之后，编码器将开始报告NeedInputData事件。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 

**返回：**

如果执行成功，返回AV_ERR_OK 否则，返回特定的错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9


### OH_VideoEncoder_Stop()

  
```
OH_AVErrCode OH_VideoEncoder_Stop (OH_AVCodec *codec)
```

**描述：**

停止编码器。停止之后，你可以通过Start接口进入Started状态。

\@syscap SystemCapability.Multimedia.Media.VideoEncoder

**参数：**

| 名称 | 描述 | 
| -------- | -------- |
| codec | 指向OH_AVCodec实例的指针。 | 

**返回：**

如果执行成功，返回AV_ERR_OK 否则，返回特定的错误代码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

**起始版本：**

9
