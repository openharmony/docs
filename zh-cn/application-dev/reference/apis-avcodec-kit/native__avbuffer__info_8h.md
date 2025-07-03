# native_avbuffer_info.h


## 概述

声明了媒体数据结构AVBuffer属性的定义。

**库：** libnative_media_core.so

**引用文件：** <multimedia/player_framework/native_avbuffer_info.h>

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**相关模块：**[Core](_core.md)

**相关示例：**[AVCodec](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) | 定义OH_AVCodec的缓冲区描述信息。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_AVCodecBufferFlags](_core.md#oh_avcodecbufferflags) [OH_AVCodecBufferFlags](_core.md#oh_avcodecbufferflags) | 枚举OH_AVCodec缓冲区标记的类别。 | 
| typedef struct [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) [OH_AVCodecBufferAttr](_core.md#oh_avcodecbufferattr) | 定义OH_AVCodec的缓冲区描述信息。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVCodecBufferFlags](_core.md#oh_avcodecbufferflags-1) {<br/>AVCODEC_BUFFER_FLAGS_NONE = 0,<br/>AVCODEC_BUFFER_FLAGS_EOS = 1 &lt;&lt; 0, AVCODEC_BUFFER_FLAGS_SYNC_FRAME = 1 &lt;&lt; 1, AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME = 1 &lt;&lt; 2,<br/>AVCODEC_BUFFER_FLAGS_CODEC_DATA = 1 &lt;&lt; 3, <br/>AVCODEC_BUFFER_FLAGS_DISCARD = 1 &lt;&lt; 4, <br/>AVCODEC_BUFFER_FLAGS_DISPOSABLE = 1 &lt;&lt; 5<br/>} | 枚举OH_AVCodec缓冲区标记的类别。  | 
