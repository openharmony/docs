# AVMuxer


## 概述

AVMuxer模块提供用于音视频封装功能的函数。

\@syscap SystemCapability.Multimedia.Media.Muxer

**起始版本：**

10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_avmuxer.h](native__avmuxer_8h.md) | 声明用于音视频封装的Native API。<br/>引用文件：&lt;multimedia/native_avmuxer.h&gt; | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| \*[OH_AVMuxer_Create](#oh_avmuxer_create) (int32_t fd, OH_AVOutputFormat format) | 通过文件描述符fd和封装格式创建OH_AVMuxer实例。 | 
| [OH_AVMuxer_SetRotation](#oh_avmuxer_setrotation) (OH_AVMuxer \*muxer, int32_t rotation) | 设置视频的旋转角度（顺时针）。 | 
| [OH_AVMuxer_AddTrack](#oh_avmuxer_addtrack) (OH_AVMuxer \*muxer, int32_t \*trackIndex, OH_AVFormat \*trackFormat) | 向封装器添加媒体轨。 | 
| [OH_AVMuxer_Start](#oh_avmuxer_start) (OH_AVMuxer \*muxer) | 开始封装。 | 
| [OH_AVMuxer_WriteSample](#oh_avmuxer_writesample) (OH_AVMuxer \*muxer, uint32_t trackIndex, OH_AVMemory \*sample, OH_AVCodecBufferAttr info) | 将数据写入封装器。 | 
| [OH_AVMuxer_Stop](#oh_avmuxer_stop) (OH_AVMuxer \*muxer) | 停止封装。 | 
| [OH_AVMuxer_Destroy](#oh_avmuxer_destroy) (OH_AVMuxer \*muxer) | 清理内部资源，销毁OH_AVMuxer实例。 | 


## 函数说明


### OH_AVMuxer_AddTrack()

  
```
OH_AVErrCode OH_AVMuxer_AddTrack (OH_AVMuxer * muxer, int32_t * trackIndex, OH_AVFormat * trackFormat )
```

**描述:**

向封装器添加媒体轨。

该接口必须在OH_AVMuxer_Start前调用。

\@syscap SystemCapability.Multimedia.Media.Muxer

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| muxer | 指向OH_AVMuxer实例的指针。 | 
| trackIndex | 用于获取该轨的索引，该值在OH_AVMuxer_WriteSample接口中使用。 如果媒体轨添加成功，该值大于或等于0，否则小于0。 | 
| trackFormat | 指向OH_AVFormat实例的指针。 | 

**返回:**

执行成功返回AV_ERR_OK，否则返回具体错误码，参考[OH_AVErrCode](_core.md#oh_averrcode-1)。

**起始版本：**

10


### OH_AVMuxer_Create()

  
```
OH_AVMuxer* OH_AVMuxer_Create (int32_t fd, OH_AVOutputFormat format )
```

**描述:**

通过文件描述符fd和封装格式创建OH_AVMuxer实例。

\@syscap SystemCapability.Multimedia.Media.Muxer

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| fd | 用读写方式打开（O_RDWR），由调用者关闭该fd。 | 
| format | 封装输出的文件格式，参考[OH_AVOutputFormat](_codec_base.md#oh_avoutputformat)。 | 

**返回:**

返回一个指向OH_AVMuxer实例的指针, 需要调用OH_AVMuxer_Destroy销毁。

**起始版本：**

10


### OH_AVMuxer_Destroy()

  
```
OH_AVErrCode OH_AVMuxer_Destroy (OH_AVMuxer * muxer)
```

**描述:**

清理内部资源，销毁OH_AVMuxer实例。

\@syscap SystemCapability.Multimedia.Media.Muxer

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| muxer | 指向OH_AVMuxer实例的指针。 | 

**返回:**

执行成功返回AV_ERR_OK，需调用者置空muxer；否则返回具体错误码，参考[OH_AVErrCode](_core.md#oh_averrcode-1)。

**起始版本：**

10


### OH_AVMuxer_SetRotation()

  
```
OH_AVErrCode OH_AVMuxer_SetRotation (OH_AVMuxer * muxer, int32_t rotation )
```

**描述:**

设置视频的旋转角度（顺时针）。

这个接口必须在OH_AVMuxer_Start前调用。

\@syscap SystemCapability.Multimedia.Media.Muxer

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| muxer | 指向OH_AVMuxer实例的指针。 | 
| rotation | 角度，必须为0、90、180 或 270。 | 

**返回:**

执行成功返回AV_ERR_OK，否则返回具体错误码，参考[OH_AVErrCode](_core.md#oh_averrcode-1)。

**起始版本：**

10


### OH_AVMuxer_Start()

  
```
OH_AVErrCode OH_AVMuxer_Start (OH_AVMuxer * muxer)
```

**描述:**

开始封装。

该接口必须在OH_AVMuxer_AddTrack后，OH_AVMuxer_WriteSample前调用。

\@syscap SystemCapability.Multimedia.Media.Muxer

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| muxer | 指向OH_AVMuxer实例的指针。 | 

**返回:**

执行成功返回AV_ERR_OK，否则返回具体错误码，参考[OH_AVErrCode](_core.md#oh_averrcode-1)。

**起始版本：**

10


### OH_AVMuxer_Stop()

  
```
OH_AVErrCode OH_AVMuxer_Stop (OH_AVMuxer * muxer)
```

**描述:**

停止封装。

封装器一旦停止，不能重新开始。

\@syscap SystemCapability.Multimedia.Media.Muxer

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| muxer | 指向OH_AVMuxer实例的指针。 | 

**返回:**

执行成功返回AV_ERR_OK，否则返回具体错误码，参考[OH_AVErrCode](_core.md#oh_averrcode-1)。

**起始版本：**

10


### OH_AVMuxer_WriteSample()

  
```
OH_AVErrCode OH_AVMuxer_WriteSample (OH_AVMuxer * muxer, uint32_t trackIndex, OH_AVMemory * sample, OH_AVCodecBufferAttr info )
```

**描述:**

将数据写入封装器。

该接口必须在OH_AVMuxer_Start后，OH_AVMuxer_Stop前调用。 调用者需要保证数据写入正确的轨道，并按时间顺序排列。

\@syscap SystemCapability.Multimedia.Media.Muxer

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| muxer | 指向OH_AVMuxer实例的指针。 | 
| trackIndex | 数据对应的媒体轨的索引。 | 
| sample | 写入的数据，编码或解封装得到的数据。 | 
| info | 写入数据的信息，参考[OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md)。 | 

**返回:**

执行成功返回AV_ERR_OK，否则返回具体错误码，参考[OH_AVErrCode](_core.md#oh_averrcode-1)。

**起始版本：**

10
