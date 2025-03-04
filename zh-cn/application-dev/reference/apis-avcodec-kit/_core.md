# Core


## 概述

Core模块提供用于媒体框架的基础骨干能力，包含内存、错误码、媒体数据结构等相关函数。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_audio_channel_layout.h](native__audio__channel__layout_8h.md) | 在录制和播放时的扬声器布局。 | 
| [native_avbuffer.h](native__avbuffer_8h.md) | 声明了媒体数据结构AVBuffer的函数接口。 | 
| [native_avbuffer_info.h](native__avbuffer__info_8h.md) | 声明了媒体数据结构AVBuffer属性的定义。 | 
| [native_averrors.h](native__averrors_8h.md) | 媒体框架错误码。 | 
| [native_avformat.h](native__avformat_8h.md) | 声明了OH_AVFormat相关的函数和枚举。 | 
| [native_avmemory.h](native__avmemory_8h.md) | 声明了媒体数据结构AVMemory的定义。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) | 定义OH_AVCodec的缓冲区描述信息。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [OH_AudioChannelSet](#oh_audiochannelset-1) [OH_AudioChannelSet](#oh_audiochannelset) | 音频声道集合。 | 
| typedef enum [OH_AmbAttributeSet](#oh_ambattributeset-1) [OH_AmbAttributeSet](#oh_ambattributeset) | 高保真立体声混响设置。 | 
| typedef enum [OH_AudioChannelLayout](#oh_audiochannellayout-1) [OH_AudioChannelLayout](#oh_audiochannellayout) | 音频声道布局。 | 
| typedef struct [OH_AVBuffer](#oh_avbuffer) [OH_AVBuffer](#oh_avbuffer) | 为媒体内存接口定义native层对象。 | 
| typedef struct [OH_NativeBuffer](#oh_nativebuffer) [OH_NativeBuffer](#oh_nativebuffer) | 为图形内存接口定义native层对象。 | 
| typedef enum [OH_AVCodecBufferFlags](#oh_avcodecbufferflags-1) [OH_AVCodecBufferFlags](#oh_avcodecbufferflags) | 枚举OH_AVCodec缓冲区标记的类别。 | 
| typedef struct [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) [OH_AVCodecBufferAttr](#oh_avcodecbufferattr) | 定义OH_AVCodec的缓冲区描述信息。 | 
| typedef enum [OH_AVErrCode](#oh_averrcode-1) [OH_AVErrCode](#oh_averrcode) | 媒体框架错误码。 | 
| typedef struct [OH_AVFormat](#oh_avformat) [OH_AVFormat](#oh_avformat) | 为OH_AVFormat接口定义native层对象。 | 
| typedef enum [OH_AVPixelFormat](#oh_avpixelformat-1) [OH_AVPixelFormat](#oh_avpixelformat) | 视频像素格式的枚举类。 | 
| typedef struct [OH_AVMemory](#oh_avmemory) [OH_AVMemory](#oh_avmemory) | 为音视频内存接口定义native层对象。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioChannelSet](#oh_audiochannelset-1) {<br/>CH_SET_FRONT_LEFT = 1ULL &lt;&lt; 0U,<br/>CH_SET_FRONT_RIGHT = 1ULL &lt;&lt; 1U,<br/>CH_SET_FRONT_CENTER = 1ULL &lt;&lt; 2U,<br/>CH_SET_LOW_FREQUENCY = 1ULL &lt;&lt; 3U,<br/>CH_SET_BACK_LEFT = 1ULL &lt;&lt; 4U,<br/>CH_SET_BACK_RIGHT = 1ULL &lt;&lt; 5U,<br/>CH_SET_FRONT_LEFT_OF_CENTER = 1ULL &lt;&lt; 6U,<br/>CH_SET_FRONT_RIGHT_OF_CENTER = 1ULL &lt;&lt; 7U,<br/>CH_SET_BACK_CENTER = 1ULL &lt;&lt; 8U,<br/>CH_SET_SIDE_LEFT = 1ULL &lt;&lt; 9U,<br/>CH_SET_SIDE_RIGHT = 1ULL &lt;&lt; 10U,<br/>CH_SET_TOP_CENTER = 1ULL &lt;&lt; 11U,<br/>CH_SET_TOP_FRONT_LEFT = 1ULL &lt;&lt; 12U,<br/>CH_SET_TOP_FRONT_CENTER = 1ULL &lt;&lt; 13U,<br/>CH_SET_TOP_FRONT_RIGHT = 1ULL &lt;&lt; 14U,<br/>CH_SET_TOP_BACK_LEFT = 1ULL &lt;&lt; 15U,<br/>CH_SET_TOP_BACK_CENTER = 1ULL &lt;&lt; 16U,<br/>CH_SET_TOP_BACK_RIGHT = 1ULL &lt;&lt; 17U,<br/>CH_SET_STEREO_LEFT = 1ULL &lt;&lt; 29U,<br/>CH_SET_STEREO_RIGHT = 1ULL &lt;&lt; 30U,<br/>CH_SET_WIDE_LEFT = 1ULL &lt;&lt; 31U,<br/>CH_SET_WIDE_RIGHT = 1ULL &lt;&lt; 32U,<br/>CH_SET_SURROUND_DIRECT_LEFT = 1ULL &lt;&lt; 33U,<br/>CH_SET_SURROUND_DIRECT_RIGHT = 1ULL &lt;&lt; 34U,<br/>CH_SET_LOW_FREQUENCY_2 = 1ULL &lt;&lt; 35U,<br/>CH_SET_TOP_SIDE_LEFT = 1ULL &lt;&lt; 36U,<br/>CH_SET_TOP_SIDE_RIGHT = 1ULL &lt;&lt; 37U,<br/>CH_SET_BOTTOM_FRONT_CENTER = 1ULL &lt;&lt; 38U,<br/>CH_SET_BOTTOM_FRONT_LEFT = 1ULL &lt;&lt; 39U,<br/>CH_SET_BOTTOM_FRONT_RIGHT = 1ULL &lt;&lt; 40U<br/>} | 音频声道集合。 | 
| [OH_AmbAttributeSet](#oh_ambattributeset-1) {<br/>AMB_ORD_1 = 1ULL &lt;&lt; 0U,<br/>AMB_ORD_2 = 2ULL &lt;&lt; 0U,<br/>AMB_ORD_3 = 3ULL &lt;&lt; 0U,<br/>AMB_COM_ACN = 0ULL &lt;&lt; 8U,<br/>AMB_COM_FUMA = 1ULL &lt;&lt; 8U,<br/>AMB_NOR_N3D = 0ULL &lt;&lt; 12U,<br/>AMB_NOR_SN3D = 1ULL &lt;&lt; 12U,<br/>AMB_MODE = 1ULL &lt;&lt; 44U<br/>} | 高保真立体声混响设置。 | 
| [OH_AudioChannelLayout](#oh_audiochannellayout-1) {<br/>CH_LAYOUT_UNKNOWN = 0ULL,<br/>CH_LAYOUT_MONO = CH_SET_FRONT_CENTER,<br/>CH_LAYOUT_STEREO = CH_SET_FRONT_LEFT \| CH_SET_FRONT_RIGHT,<br/>CH_LAYOUT_STEREO_DOWNMIX = CH_SET_STEREO_LEFT \| CH_SET_STEREO_RIGHT,<br/>CH_LAYOUT_2POINT1 = CH_LAYOUT_STEREO \| CH_SET_LOW_FREQUENCY,<br/>CH_LAYOUT_3POINT0 = CH_LAYOUT_STEREO \| CH_SET_BACK_CENTER,<br/>CH_LAYOUT_SURROUND = CH_LAYOUT_STEREO \| CH_SET_FRONT_CENTER,<br/>CH_LAYOUT_3POINT1 = CH_LAYOUT_SURROUND \| CH_SET_LOW_FREQUENCY,<br/>CH_LAYOUT_4POINT0 = CH_LAYOUT_SURROUND \| CH_SET_BACK_CENTER,<br/>CH_LAYOUT_QUAD_SIDE = CH_LAYOUT_STEREO \| CH_SET_SIDE_LEFT \| CH_SET_SIDE_RIGHT,<br/>CH_LAYOUT_QUAD = CH_LAYOUT_STEREO \| CH_SET_BACK_LEFT \| CH_SET_BACK_RIGHT,<br/>CH_LAYOUT_2POINT0POINT2 = CH_LAYOUT_STEREO \| CH_SET_TOP_SIDE_LEFT \| CH_SET_TOP_SIDE_RIGHT,<br/>CH_LAYOUT_AMB_ORDER1_ACN_N3D = AMB_MODE \| AMB_ORD_1 \| AMB_COM_ACN \| AMB_NOR_N3D, CH_LAYOUT_AMB_ORDER1_ACN_SN3D = AMB_MODE \| AMB_ORD_1 \| AMB_COM_ACN \| AMB_NOR_SN3D,<br/>CH_LAYOUT_AMB_ORDER1_FUMA = AMB_MODE \| AMB_ORD_1 \| AMB_COM_FUMA,<br/>CH_LAYOUT_4POINT1 = CH_LAYOUT_4POINT0 \| CH_SET_LOW_FREQUENCY,<br/>CH_LAYOUT_5POINT0 = CH_LAYOUT_SURROUND \| CH_SET_SIDE_LEFT \| CH_SET_SIDE_RIGHT,<br/>CH_LAYOUT_5POINT0_BACK = CH_LAYOUT_SURROUND \| CH_SET_BACK_LEFT \| CH_SET_BACK_RIGHT,<br/>CH_LAYOUT_2POINT1POINT2 = CH_LAYOUT_2POINT0POINT2 \| CH_SET_LOW_FREQUENCY,<br/>CH_LAYOUT_3POINT0POINT2 = CH_LAYOUT_2POINT0POINT2 \| CH_SET_FRONT_CENTER,<br/>CH_LAYOUT_5POINT1 = CH_LAYOUT_5POINT0 \| CH_SET_LOW_FREQUENCY,<br/>CH_LAYOUT_5POINT1_BACK = CH_LAYOUT_5POINT0_BACK \| CH_SET_LOW_FREQUENCY,<br/>CH_LAYOUT_6POINT0 = CH_LAYOUT_5POINT0 \| CH_SET_BACK_CENTER,<br/>CH_LAYOUT_3POINT1POINT2 = CH_LAYOUT_3POINT1 \| CH_SET_TOP_FRONT_LEFT \| CH_SET_TOP_FRONT_RIGHT,<br/>CH_LAYOUT_6POINT0_FRONT = CH_LAYOUT_QUAD_SIDE \| CH_SET_FRONT_LEFT_OF_CENTER \| CH_SET_FRONT_RIGHT_OF_CENTER,<br/>CH_LAYOUT_HEXAGONAL = CH_LAYOUT_5POINT0_BACK \| CH_SET_BACK_CENTER,<br/>CH_LAYOUT_6POINT1 = CH_LAYOUT_5POINT1 \| CH_SET_BACK_CENTER,<br/>CH_LAYOUT_6POINT1_BACK = CH_LAYOUT_5POINT1_BACK \| CH_SET_BACK_CENTER,<br/>CH_LAYOUT_6POINT1_FRONT = CH_LAYOUT_6POINT0_FRONT \| CH_SET_LOW_FREQUENCY,<br/>CH_LAYOUT_7POINT0 = CH_LAYOUT_5POINT0 \| CH_SET_BACK_LEFT \| CH_SET_BACK_RIGHT,<br/>CH_LAYOUT_7POINT0_FRONT = CH_LAYOUT_5POINT0 \| CH_SET_FRONT_LEFT_OF_CENTER \| CH_SET_FRONT_RIGHT_OF_CENTER,<br/>CH_LAYOUT_7POINT1 = CH_LAYOUT_5POINT1 \| CH_SET_BACK_LEFT \| CH_SET_BACK_RIGHT,<br/>CH_LAYOUT_OCTAGONAL = CH_LAYOUT_5POINT0 \| CH_SET_BACK_LEFT \| CH_SET_BACK_CENTER \| CH_SET_BACK_RIGHT,<br/>CH_LAYOUT_5POINT1POINT2 = CH_LAYOUT_5POINT1 \| CH_SET_TOP_SIDE_LEFT \| CH_SET_TOP_SIDE_RIGHT,<br/>CH_LAYOUT_7POINT1_WIDE = CH_LAYOUT_5POINT1 \| CH_SET_FRONT_LEFT_OF_CENTER \| CH_SET_FRONT_RIGHT_OF_CENTER,<br/>CH_LAYOUT_7POINT1_WIDE_BACK = CH_LAYOUT_5POINT1_BACK \| CH_SET_FRONT_LEFT_OF_CENTER \| CH_SET_FRONT_RIGHT_OF_CENTER,<br/>CH_LAYOUT_AMB_ORDER2_ACN_N3D = AMB_MODE \| AMB_ORD_2 \| AMB_COM_ACN \| AMB_NOR_N3D,<br/>CH_LAYOUT_AMB_ORDER2_ACN_SN3D = AMB_MODE \| AMB_ORD_2 \| AMB_COM_ACN \| AMB_NOR_SN3D,<br/>CH_LAYOUT_AMB_ORDER2_FUMA = AMB_MODE \| AMB_ORD_2 \| AMB_COM_FUMA,<br/>CH_LAYOUT_5POINT1POINT4,<br/>CH_LAYOUT_7POINT1POINT2 = CH_LAYOUT_7POINT1 \| CH_SET_TOP_SIDE_LEFT \| CH_SET_TOP_SIDE_RIGHT,<br/>CH_LAYOUT_7POINT1POINT4,<br/>CH_LAYOUT_10POINT2,<br/>CH_LAYOUT_9POINT1POINT4 = CH_LAYOUT_7POINT1POINT4 \| CH_SET_WIDE_LEFT \| CH_SET_WIDE_RIGHT,<br/>CH_LAYOUT_9POINT1POINT6 = CH_LAYOUT_9POINT1POINT4 \| CH_SET_TOP_SIDE_LEFT \| CH_SET_TOP_SIDE_RIGHT,<br/>CH_LAYOUT_HEXADECAGONAL,<br/>CH_LAYOUT_AMB_ORDER3_ACN_N3D = AMB_MODE \| AMB_ORD_3 \| AMB_COM_ACN \| AMB_NOR_N3D,<br/>CH_LAYOUT_AMB_ORDER3_ACN_SN3D = AMB_MODE \| AMB_ORD_3 \| AMB_COM_ACN \| AMB_NOR_SN3D,<br/>CH_LAYOUT_AMB_ORDER3_FUMA = AMB_MODE \| AMB_ORD_3 \| AMB_COM_FUMA,<br/>CH_LAYOUT_22POINT2<br/>} | 音频声道布局。 | 
| [OH_AVCodecBufferFlags](#oh_avcodecbufferflags-1) {<br/>AVCODEC_BUFFER_FLAGS_NONE = 0,<br/>AVCODEC_BUFFER_FLAGS_EOS = 1 &lt;&lt; 0, AVCODEC_BUFFER_FLAGS_SYNC_FRAME = 1 &lt;&lt; 1, AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME = 1 &lt;&lt; 2,<br/>AVCODEC_BUFFER_FLAGS_CODEC_DATA = 1 &lt;&lt; 3, <br/>AVCODEC_BUFFER_FLAGS_DISCARD = 1 &lt;&lt; 4, <br/>AVCODEC_BUFFER_FLAGS_DISPOSABLE = 1 &lt;&lt; 5<br/>} | 枚举OH_AVCodec缓冲区标记的类别。  | 
| [OH_AVErrCode](#oh_averrcode-1)  {<br/>AV_ERR_OK = 0,<br/>AV_ERR_NO_MEMORY = 1,<br/>AV_ERR_OPERATE_NOT_PERMIT = 2,<br/>AV_ERR_INVALID_VAL = 3,<br/>AV_ERR_IO = 4,<br/>AV_ERR_TIMEOUT = 5,<br/>AV_ERR_UNKNOWN = 6,<br/>AV_ERR_SERVICE_DIED = 7,<br/>AV_ERR_INVALID_STATE = 8,<br/>AV_ERR_UNSUPPORT = 9,<br/>AV_ERR_EXTEND_START = 100,<br/>AV_ERR_DRM_BASE = 200,<br/>AV_ERR_DRM_DECRYPT_FAILED = 201,<br/>AV_ERR_VIDEO_BASE = 300,<br/>AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION = 301<br/>} | 媒体框架错误码。  |
| [OH_AVPixelFormat](#oh_avpixelformat-1) {<br/>AV_PIXEL_FORMAT_YUVI420 = 1,<br/>AV_PIXEL_FORMAT_NV12 = 2,<br/>AV_PIXEL_FORMAT_NV21 = 3,<br/>AV_PIXEL_FORMAT_SURFACE_FORMAT = 4,<br/>AV_PIXEL_FORMAT_RGBA = 5<br/>} | 视频像素格式的枚举类。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVBuffer](#oh_avbuffer) \* [OH_AVBuffer_Create](#oh_avbuffer_create) (int32_t capacity) | 创建OH_AVBuffer实例。 需要注意的是，返回值指向的创建OH_AVBuffer的实例需要开发者主动调用接口释放，请参阅[OH_AVBuffer_Destroy](#oh_avbuffer_destroy)。 | 
| [OH_AVErrCode](#oh_averrcode) [OH_AVBuffer_Destroy](#oh_avbuffer_destroy) ([OH_AVBuffer](#oh_avbuffer) \*buffer) | 释放OH_AVBuffer实例指针的资源。 | 
| [OH_AVErrCode](#oh_averrcode) [OH_AVBuffer_GetBufferAttr](#oh_avbuffer_getbufferattr) ([OH_AVBuffer](#oh_avbuffer) \*buffer, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr) | 获取数据缓冲区的pts、size、offset、flags高频属性参数。 | 
| [OH_AVErrCode](#oh_averrcode) [OH_AVBuffer_SetBufferAttr](#oh_avbuffer_setbufferattr) ([OH_AVBuffer](#oh_avbuffer) \*buffer, const [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr) | 设置数据缓冲区的pts、size、offset、flags高频属性参数。 | 
| [OH_AVFormat](#oh_avformat) \* [OH_AVBuffer_GetParameter](#oh_avbuffer_getparameter) ([OH_AVBuffer](#oh_avbuffer) \*buffer) | 获取除基础属性外的其他参数，信息在OH_AVFormat中承载。 | 
| [OH_AVErrCode](#oh_averrcode) [OH_AVBuffer_SetParameter](#oh_avbuffer_setparameter) ([OH_AVBuffer](#oh_avbuffer) \*buffer, const [OH_AVFormat](#oh_avformat) \*format) | 设置除基础属性外的其他参数，信息在OH_AVFormat中承载。 | 
| uint8_t \* [OH_AVBuffer_GetAddr](#oh_avbuffer_getaddr) ([OH_AVBuffer](#oh_avbuffer) \*buffer) | 获取数据缓冲区的虚拟地址。 | 
| int32_t [OH_AVBuffer_GetCapacity](#oh_avbuffer_getcapacity) ([OH_AVBuffer](#oh_avbuffer) \*buffer) | 获取数据缓冲区的容量（字节数）。 | 
| [OH_NativeBuffer](#oh_nativebuffer) \* [OH_AVBuffer_GetNativeBuffer](#oh_avbuffer_getnativebuffer) ([OH_AVBuffer](#oh_avbuffer) \*buffer) | 获取OH_NativeBuffer实例的指针。 | 
| struct [OH_AVFormat](#oh_avformat) \* [OH_AVFormat_Create](#oh_avformat_create) (void) | 创建OH_AVFormat实例，用于读写数据。 | 
| struct [OH_AVFormat](#oh_avformat) \* [OH_AVFormat_CreateAudioFormat](#oh_avformat_createaudioformat) (const char \*mimeType, int32_t sampleRate, int32_t channelCount) | 创建音频OH_AVFormat实例指针并预设置指定参数，用于读写数据。 | 
| struct [OH_AVFormat](#oh_avformat) \* [OH_AVFormat_CreateVideoFormat](#oh_avformat_createvideoformat) (const char \*mimeType, int32_t width, int32_t height) | 创建视频OH_AVFormat实例指针并预设置指定参数，用于读写数据。 | 
| void [OH_AVFormat_Destroy](#oh_avformat_destroy) (struct [OH_AVFormat](#oh_avformat) \*format) | 销毁OH_AVFormat实例。 | 
| bool [OH_AVFormat_Copy](#oh_avformat_copy) (struct [OH_AVFormat](#oh_avformat) \*to, struct [OH_AVFormat](#oh_avformat) \*from) | 复制OH_AVFormat实例。 | 
| bool [OH_AVFormat_SetIntValue](#oh_avformat_setintvalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, int32_t value) | 对OH_AVFormat的key赋int类型的值。 |
| bool [OH_AVFormat_SetLongValue](#oh_avformat_setlongvalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, int64_t value) | 对OH_AVFormat的key赋long类型的值。 |
| bool [OH_AVFormat_SetFloatValue](#oh_avformat_setfloatvalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, float value) | 对OH_AVFormat的key赋float类型的值。 |
| bool [OH_AVFormat_SetDoubleValue](#oh_avformat_setdoublevalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, double value) | 对OH_AVFormat的key赋double类型的值 |
| bool [OH_AVFormat_SetStringValue](#oh_avformat_setstringvalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, const char \*value) | 对OH_AVFormat的key赋string类型的值。 |
| bool [OH_AVFormat_SetBuffer](#oh_avformat_setbuffer) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, const uint8_t \*addr, size_t size) | 将指定长度的数据块写入OH_AVFormat。 | 
| bool [OH_AVFormat_GetIntValue](#oh_avformat_getintvalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, int32_t \*out) | 从OH_AVFormat的key获取int类型的值 | 
| bool [OH_AVFormat_GetLongValue](#oh_avformat_getlongvalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, int64_t \*out) | 从OH_AVFormat的key获取long类型的值。 | 
| bool [OH_AVFormat_GetFloatValue](#oh_avformat_getfloatvalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, float \*out) | 从OH_AVFormat的key获取float类型的值。 | 
| bool [OH_AVFormat_GetDoubleValue](#oh_avformat_getdoublevalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, double \*out) | 从OH_AVFormat的key获取double类型的值。 | 
| bool [OH_AVFormat_GetStringValue](#oh_avformat_getstringvalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, const char \*\*out) | 从OH_AVFormat的key获取string类型的值。 | 
| bool [OH_AVFormat_GetBuffer](#oh_avformat_getbuffer) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, uint8_t \*\*addr, size_t \*size) | 从OH_AVFormat中读取指定长度的数据块。 | 
| const char \* [OH_AVFormat_DumpInfo](#oh_avformat_dumpinfo) (struct [OH_AVFormat](#oh_avformat) \*format) | 返回OH_AVFormat中包含的key-value组成的字符串。 | 
| [OH_AVMemory](#oh_avmemory) \* [OH_AVMemory_Create](#oh_avmemory_create) (int32_t size) | 创建OH_AVMemory实例的指针。（API11废弃） | 
| uint8_t \* [OH_AVMemory_GetAddr](#oh_avmemory_getaddr) (struct [OH_AVMemory](#oh_avmemory) \*mem) | 获取内存虚拟地址。 （API11废弃）| 
| int32_t [OH_AVMemory_GetSize](#oh_avmemory_getsize) (struct [OH_AVMemory](#oh_avmemory) \*mem) | 获取内存长度。（API11废弃） | 
| [OH_AVErrCode](#oh_averrcode) [OH_AVMemory_Destroy](#oh_avmemory_destroy) (struct [OH_AVMemory](#oh_avmemory) \*mem) | 释放OH_AVMemory实例指针的资源。（API11废弃） | 


## 类型定义说明


### OH_AmbAttributeSet

```
typedef enum OH_AmbAttributeSet OH_AmbAttributeSet
```

**描述**

高保真立体声混响设置。

用int64_t整数来表示高保真立体声混响属性。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11


### OH_AudioChannelLayout

```
typedef enum OH_AudioChannelLayout OH_AudioChannelLayout
```

**描述**

音频声道布局。

用int64_t整数来表示在录制或播放时扬声器的外观和顺序。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11


### OH_AudioChannelSet

```
typedef enum OH_AudioChannelSet OH_AudioChannelSet
```

**描述**

音频声道集合。

将每一个声道映射为int64_t的变量。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11


### OH_AVBuffer

```
typedef struct OH_AVBuffer OH_AVBuffer
```
**描述**

为媒体内存接口定义native层对象。

**起始版本：** 11


### OH_AVCodecBufferAttr

```
typedef struct OH_AVCodecBufferAttr OH_AVCodecBufferAttr
```

**描述**

定义OH_AVCodec的缓冲区描述信息。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9


### OH_AVCodecBufferFlags

```
typedef enum OH_AVCodecBufferFlags OH_AVCodecBufferFlags
```

**描述**

枚举OH_AVCodec缓冲区标记的类别。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9


### OH_AVErrCode

```
typedef enum OH_AVErrCode OH_AVErrCode
```

**描述**

媒体框架错误码。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9


### OH_AVFormat

```
typedef struct OH_AVFormat OH_AVFormat
```
**描述**

为OH_AVFormat接口定义native层对象。

**起始版本：** 9


### OH_AVMemory

```
typedef struct OH_AVMemory OH_AVMemory
```
**描述**

为音视频内存接口定义native层对象。

**起始版本：** 9


### OH_AVPixelFormat

```
typedef enum OH_AVPixelFormat OH_AVPixelFormat
```

**描述**

视频像素格式的枚举类。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9


### OH_NativeBuffer

```
typedef struct OH_NativeBuffer OH_NativeBuffer
```
**描述**

为图形内存接口定义native层对象。

**起始版本：** 11


## 枚举类型说明


### OH_AmbAttributeSet

```
enum OH_AmbAttributeSet
```

**描述**

高保真立体声混响设置。

用int64_t整数来表示高保真立体声混响属性。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| AMB_ORD_1 | 一阶高保真立体声混响 | 
| AMB_ORD_2 | 二阶高保真立体声混响 | 
| AMB_ORD_3 | 三阶高保真立体声混响 | 
| AMB_COM_ACN | ACN通道排序的高保真立体声混响 | 
| AMB_COM_FUMA | FUMA通道排序的高保真立体声混响 | 
| AMB_NOR_N3D | N3D归一化的高保真立体声混响 | 
| AMB_NOR_SN3D | SN3D归一化的高保真立体声混响 | 
| AMB_MODE | 高保真立体声混响的声道布局 | 


### OH_AudioChannelLayout

```
enum OH_AudioChannelLayout
```

**描述**

音频声道布局。

用int64_t整数来表示在录制或播放时扬声器的外观和顺序。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| CH_LAYOUT_UNKNOWN | 未知声道布局 | 
| CH_LAYOUT_MONO | 单声道布局， 共1个声道 | 
| CH_LAYOUT_STEREO | 立体声布局，共2个声道 | 
| CH_LAYOUT_STEREO_DOWNMIX | 立体声下混布局，共2个声道 | 
| CH_LAYOUT_2POINT1 | 2.1布局，共3个声道 | 
| CH_LAYOUT_3POINT0 | 3.0布局，共3个声道 | 
| CH_LAYOUT_SURROUND | 环绕布局，共3个声道 | 
| CH_LAYOUT_3POINT1 | 3.1布局，共4个声道 | 
| CH_LAYOUT_4POINT0 | 4.0布局，共4个声道 | 
| CH_LAYOUT_QUAD_SIDE | QUAD_SIDE布局，共4个声道 | 
| CH_LAYOUT_QUAD | QUAD布局，共4个声道 | 
| CH_LAYOUT_2POINT0POINT2 | 2.0.2布局，共4个声道 | 
| CH_LAYOUT_AMB_ORDER1_ACN_N3D | ACN_N3D（根据ITU标准）的一阶FOA布局，共4个声道 | 
| CH_LAYOUT_AMB_ORDER1_ACN_SN3D | ACN_SN3D（根据ITU标准）的一阶FOA布局，共4个声道 | 
| CH_LAYOUT_AMB_ORDER1_FUMA | FUMA（根据ITU标准）的一阶FOA布局，共4个声道 | 
| CH_LAYOUT_4POINT1 | 4.1布局，共5个声道 | 
| CH_LAYOUT_5POINT0 | 5.0布局，共5个声道 | 
| CH_LAYOUT_5POINT0_BACK | 5.0-后置布局，共5个声道 | 
| CH_LAYOUT_2POINT1POINT2 | 2.1.2布局，共5个声道 | 
| CH_LAYOUT_3POINT0POINT2 | 3.0.2布局，共5个声道 | 
| CH_LAYOUT_5POINT1 | 5.1布局，共6个声道 | 
| CH_LAYOUT_5POINT1_BACK | 5.1-后置布局，共6个声道 | 
| CH_LAYOUT_6POINT0 | 6.0布局，共6个声道 | 
| CH_LAYOUT_3POINT1POINT2 | 3.1.2布局，共6个声道 | 
| CH_LAYOUT_6POINT0_FRONT | 6.0-Front布局，共6个声道 | 
| CH_LAYOUT_HEXAGONAL | HEXAGONAL布局，共6个声道 | 
| CH_LAYOUT_6POINT1 | 6.1布局，共7个声道 | 
| CH_LAYOUT_6POINT1_BACK | 6.1-后置布局，共7个声道 | 
| CH_LAYOUT_6POINT1_FRONT | 6.1-前置布局，共7个声道 | 
| CH_LAYOUT_7POINT0 | 7.0布局，共7个声道 | 
| CH_LAYOUT_7POINT0_FRONT | 7.0-前置布局，共7个声道 | 
| CH_LAYOUT_7POINT1 | 7.1布局，共8个声道 | 
| CH_LAYOUT_OCTAGONAL | OCTAGONAL布局，共8个声道 | 
| CH_LAYOUT_5POINT1POINT2 | 5.1.2布局，共8个声道 | 
| CH_LAYOUT_7POINT1_WIDE | 7.1-宽布局，共8个声道 | 
| CH_LAYOUT_7POINT1_WIDE_BACK | 7.1-后置宽布局，共8个声道 | 
| CH_LAYOUT_AMB_ORDER2_ACN_N3D | ACN_N3D（根据ITU标准）的二阶HOA布局，共9个声道 | 
| CH_LAYOUT_AMB_ORDER2_ACN_SN3D | ACN_SN3D（根据ITU标准）的二阶HOA布局，共9个声道 | 
| CH_LAYOUT_AMB_ORDER2_FUMA | FUMA（根据ITU标准）的二阶HOA布局，共9个声道 | 
| CH_LAYOUT_5POINT1POINT4 | 5.1.4布局，共10个声道 | 
| CH_LAYOUT_7POINT1POINT2 | 7.1.2布局，共10个声道 | 
| CH_LAYOUT_7POINT1POINT4 | 7.1.4布局，共12个声道 | 
| CH_LAYOUT_10POINT2 | 10.2布局，共12个声道 | 
| CH_LAYOUT_9POINT1POINT4 | 9.1.4布局，共14个声道 | 
| CH_LAYOUT_9POINT1POINT6 | 9.1.6布局，共16个声道 | 
| CH_LAYOUT_HEXADECAGONAL | HEXADECAGONAL布局，共16个声道 | 
| CH_LAYOUT_AMB_ORDER3_ACN_N3D | ACN_N3D（根据ITU标准）的三阶HOA布局，共16个声道 | 
| CH_LAYOUT_AMB_ORDER3_ACN_SN3D | ACN_SN3D（根据ITU标准）的三阶HOA布局，共16个声道 | 
| CH_LAYOUT_AMB_ORDER3_FUMA | FUMA（根据ITU标准）的三阶HOA布局，共16个声道 | 
| CH_LAYOUT_22POINT2 | 22.2布局，共24个声道 | 


### OH_AudioChannelSet

```
enum OH_AudioChannelSet
```

**描述**

音频声道集合。

将每一个声道映射为int64_t的变量。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11

| 枚举值 | 描述 | 
| -------- | -------- |
| CH_SET_FRONT_LEFT | 左前声道 | 
| CH_SET_FRONT_RIGHT | 右前声道 | 
| CH_SET_FRONT_CENTER | 中前声道 | 
| CH_SET_LOW_FREQUENCY | 低频声道 | 
| CH_SET_BACK_LEFT | 左后声道 | 
| CH_SET_BACK_RIGHT | 右后声道 | 
| CH_SET_FRONT_LEFT_OF_CENTER | 左前中置声道 | 
| CH_SET_FRONT_RIGHT_OF_CENTER | 右前中置声道 | 
| CH_SET_BACK_CENTER | 后方中置声道 | 
| CH_SET_SIDE_LEFT | 左侧声道 | 
| CH_SET_SIDE_RIGHT | 右侧声道 | 
| CH_SET_TOP_CENTER | 上方中置声道 | 
| CH_SET_TOP_FRONT_LEFT | 上方左前声道 | 
| CH_SET_TOP_FRONT_CENTER | 上方中前声道 | 
| CH_SET_TOP_FRONT_RIGHT | 上方右前声道 | 
| CH_SET_TOP_BACK_LEFT | 上方左后声道 | 
| CH_SET_TOP_BACK_CENTER | 上方中后声道 | 
| CH_SET_TOP_BACK_RIGHT | 上方右后声道 | 
| CH_SET_STEREO_LEFT | 立体声左声道 | 
| CH_SET_STEREO_RIGHT | 立体声右声道 | 
| CH_SET_WIDE_LEFT | 宽左声道 | 
| CH_SET_WIDE_RIGHT | 宽右声道 | 
| CH_SET_SURROUND_DIRECT_LEFT | 左环绕声道 | 
| CH_SET_SURROUND_DIRECT_RIGHT | 右环绕声道 | 
| CH_SET_LOW_FREQUENCY_2 | 低频声道2 | 
| CH_SET_TOP_SIDE_LEFT | 上方左侧声道 | 
| CH_SET_TOP_SIDE_RIGHT | 上方右侧声道 | 
| CH_SET_BOTTOM_FRONT_CENTER | 下方中前声道 | 
| CH_SET_BOTTOM_FRONT_LEFT | 下方左前声道 | 
| CH_SET_BOTTOM_FRONT_RIGHT | 下方右前声道 | 


### OH_AVCodecBufferFlags

```
enum OH_AVCodecBufferFlags
```

**描述**

枚举OH_AVCodec缓冲区标记的类别。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

| 枚举值 | 描述 | 
| -------- | -------- |
| AVCODEC_BUFFER_FLAGS_NONE | 表示为普通帧。 | 
| AVCODEC_BUFFER_FLAGS_EOS | 表示缓冲区是流结束帧。 | 
| AVCODEC_BUFFER_FLAGS_SYNC_FRAME | 表示缓冲区包含关键帧。 | 
| AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME | 表示缓冲区中的数据只是帧的一部分。 | 
| AVCODEC_BUFFER_FLAGS_CODEC_DATA | 表示缓冲区包含编解码特定数据。 | 
| AVCODEC_BUFFER_FLAGS_DISCARD  | 表示缓冲区被解码依赖，解码之后的数据可丢弃。<br/>**起始版本：** 12 | 
| AVCODEC_BUFFER_FLAGS_DISPOSABLE  | 表示缓冲区不被参考可直接丢弃。<br/>**起始版本：** 12 | 


### OH_AVErrCode

```
enum OH_AVErrCode
```

**描述**

媒体框架错误码。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

| 枚举值 | 描述 | 
| -------- | -------- |
| AV_ERR_OK  | 操作成功。   | 
| AV_ERR_NO_MEMORY  | 无内存。   | 
| AV_ERR_OPERATE_NOT_PERMIT  | 操作不允许。   | 
| AV_ERR_INVALID_VAL  | 无效值。   | 
| AV_ERR_IO  | IO错误。   | 
| AV_ERR_TIMEOUT  | 超时错误。   | 
| AV_ERR_UNKNOWN  | 未知错误。   | 
| AV_ERR_SERVICE_DIED  | 服务死亡。   | 
| AV_ERR_INVALID_STATE  | 当前状态不支持此操作。   | 
| AV_ERR_UNSUPPORT  | 未支持的功能。   | 
| AV_ERR_EXTEND_START  | 扩展错误码初始值。   | 
| AV_ERR_DRM_BASE  | DRM起始错误码。<br/>**起始版本：** 12 | 
| AV_ERR_DRM_DECRYPT_FAILED  | DRM解密失败。<br/>**起始版本：** 12 | 
| AV_ERR_VIDEO_BASE   | 视频起始错误码。<br/>**起始版本：** 12 |
| AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION   | 视频不支持色彩空间转换。<br/>**起始版本：** 12 |

### OH_AVPixelFormat

```
enum OH_AVPixelFormat
```

**描述**

视频像素格式的枚举类。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

| 枚举值 | 描述 | 
| -------- | -------- |
| AV_PIXEL_FORMAT_YUVI420 | yuv 420 planar。 | 
| AV_PIXEL_FORMAT_NV12 | NV12. yuv 420 semiplanar。 | 
| AV_PIXEL_FORMAT_NV21 | NV21. yvu 420 semiplanar。 | 
| AV_PIXEL_FORMAT_SURFACE_FORMAT | 像素格式从surface获取。 | 
| AV_PIXEL_FORMAT_RGBA | RGBA8888。 | 


## 函数说明


### OH_AVBuffer_Create()

```
OH_AVBuffer* OH_AVBuffer_Create (int32_t capacity)
```

**描述**

创建OH_AVBuffer实例。 需要注意的是，返回值指向的创建OH_AVBuffer的实例需要开发者主动调用接口释放，请参阅[OH_AVBuffer_Destroy](#oh_avbuffer_destroy)。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| capacity | 创建内存的大小，单位字节。 | 

**返回：**

如果创建成功，则返回OH_AVBuffer实例的指针，如果失败，则返回NULL。

可能失败的原因：

1. capacity <=0；
2. 出现内部错误，系统没有资源等。


### OH_AVBuffer_Destroy()

```
OH_AVErrCode OH_AVBuffer_Destroy (OH_AVBuffer *buffer)
```

**描述**

释放OH_AVBuffer实例指针的资源，同一个buffer不允许重复销毁。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 指向OH_AVBuffer实例的指针。 | 

**返回：**

返回函数结果：

AV_ERR_OK：操作成功。

AV_ERR_INVALID_VAL：输入的buffer为空指针或者buffer结构校验失败。

AV_ERR_OPERATE_NOT_PERMIT：输入的buffer不是用户创建的。


### OH_AVBuffer_GetAddr()

```
uint8_t* OH_AVBuffer_GetAddr (OH_AVBuffer *buffer)
```

**描述**

获取数据缓冲区的虚拟地址。

不同场景下，对是否可以获取虚拟地址的支持情况不同，请见表格：

**编码：**
| 模式 | 填充数据的方式 |  是否可以获取虚拟地址 |
| --------------- | -------- | -------- |
| Surface模式 | OnNeedInputBuffer输入  | × |
| Surface模式 | OnNewOutputBuffer输出  | √ |
| Buffer模式  | OnNeedInputBuffer输入  | √ |
| Buffer模式  | OnNewOutputBuffer输出  | √ |

**解码：**
| 模式 | 填充数据的方式 |  是否可以获取虚拟地址 |
| --------------- | -------- | -------- |
| Surface模式 | OnNeedInputBuffer输入  | √ |
| Surface模式 | OnNewOutputBuffer输出  | × |
| Buffer模式  | OnNeedInputBuffer输入  | √ |
| Buffer模式  | OnNewOutputBuffer输出  | √ |

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 指向OH_AVBuffer实例的指针。 | 

**返回：**

如果成功，则返回数据缓冲区的虚拟地址，如果失败，则返回NULL。

可能失败的原因：

1. 输入的buffer为空指针；
2. OH_AVBuffer结构校验失败；
3. 出现内部错误。


### OH_AVBuffer_GetBufferAttr()

```
OH_AVErrCode OH_AVBuffer_GetBufferAttr (OH_AVBuffer *buffer, OH_AVCodecBufferAttr *attr)
```

**描述**

获取数据缓冲区的pts、size、offset、flags高频属性参数。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 指向OH_AVBuffer实例的指针。 | 
| attr | 指向[OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md)实例的指针。 | 

**返回：**

返回函数结果：

AV_ERR_OK：操作成功。

AV_ERR_INVALID_VAL：

    可能的原因：
    1. 输入的buffer或attr为空指针；
    2. buffer结构校验失败。


### OH_AVBuffer_GetCapacity()

```
int32_t OH_AVBuffer_GetCapacity (OH_AVBuffer *buffer)
```

**描述**

获取数据缓冲区的容量（字节数）。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 指向OH_AVBuffer实例的指针。 | 

**返回：**

如果成功，则返回数据缓冲区的容量，如果失败，则返回-1。

可能失败的原因：

1. 输入的buffer为空指针；
2. OH_AVBuffer结构校验失败；
3. 出现内部错误。


### OH_AVBuffer_GetNativeBuffer()

```
OH_NativeBuffer* OH_AVBuffer_GetNativeBuffer (OH_AVBuffer *buffer)
```

**描述**

获取OH_NativeBuffer实例的指针。 需要注意的是，返回值指向的创建OH_NativeBuffer的实例需要开发者主动调用接口释放，请参阅[OH_NativeBuffer_Unreference](../apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_unreference)。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 指向OH_AVBuffer实例的指针。 | 

**返回：**

如果成功，则返回OH_NativeBuffer实例的指针，如果失败，则返回NULL。

可能失败的原因：

1. 输入的buffer为空指针；
2. OH_AVBuffer结构校验失败；
3. 出现内部错误。


### OH_AVBuffer_GetParameter()

```
OH_AVFormat* OH_AVBuffer_GetParameter (OH_AVBuffer *buffer)
```

**描述**

获取除基础属性外的其他参数，信息在OH_AVFormat中承载。 需要注意的是，返回值指向的创建OH_AVFormat的实例需要开发者主动释放，请参阅[OH_AVFormat_Destroy](#oh_avformat_destroy)。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 指向OH_AVBuffer实例的指针。 | 

**返回：**

返回函数结果：

AV_ERR_OK：操作成功。

AV_ERR_INVALID_VAL：

    可能的原因：
    1. 输入的buffer为空指针；
    2. 输入buffer的meta为空指针；
    3. buffer结构校验失败。


### OH_AVBuffer_SetBufferAttr()

```
OH_AVErrCode OH_AVBuffer_SetBufferAttr (OH_AVBuffer *buffer, const OH_AVCodecBufferAttr *attr)
```

**描述**

设置数据缓冲区的pts、size、offset、flags高频属性参数。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 指向OH_AVBuffer实例的指针。 | 
| attr | 指向[OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md)实例的指针。 | 

**返回：**

返回函数结果：

AV_ERR_OK：操作成功。

AV_ERR_INVALID_VAL：

    可能的原因：
    1. 输入的buffer或attr为空指针；
    2. buffer结构校验失败；
    3. 输入buffer中内存的size或offset是无效值。


### OH_AVBuffer_SetParameter()

```
OH_AVErrCode OH_AVBuffer_SetParameter (OH_AVBuffer *buffer, const OH_AVFormat *format)
```

**描述**

设置除基础属性外的其他参数，信息在OH_AVFormat中承载。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 指向OH_AVBuffer实例的指针。 | 
| format | 指向OH_AVFormat实例的指针。 | 

**返回：**

返回函数结果：

AV_ERR_OK：操作成功。

AV_ERR_INVALID_VAL：

    可能的原因：
    1. 输入的buffer或format为空指针；
    2. 输入buffer的meta为空指针；
    3. buffer结构校验失败。


### OH_AVFormat_Copy()

```
bool OH_AVFormat_Copy (struct OH_AVFormat *to, struct OH_AVFormat *from)
```

**描述**

复制OH_AVFormat实例。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| to | OH_AVFormat实例，用于接收数据。 | 
| from | 指向复制数据的OH_AVFormat实例的指针。 | 

**返回：**

返回值为TRUE表示成功，返回值为FALSE表示失败。

可能的失败原因：

1. 输入参数为空指针；
2. 输入的OH_AVFormat参数结构校验失败。


### OH_AVFormat_Create()

```
struct OH_AVFormat* OH_AVFormat_Create (void)
```

**描述**

创建OH_AVFormat实例，用于读写数据。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**返回：**

返回指向OH_AVFormat实例的指针。系统资源不足时返回NULL。


### OH_AVFormat_CreateAudioFormat()

```
struct OH_AVFormat* OH_AVFormat_CreateAudioFormat (const char *mimeType, int32_t sampleRate, int32_t channelCount)
```

**描述**

创建音频OH_AVFormat实例指针并预设置指定参数，用于读写数据。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mimeType | MIME类型描述字符串，请参阅[AVCODEC_MIMETYPE](_codec_base.md#变量)。 | 
| sampleRate | 采样率，单位Hz。 | 
| channelCount | 声道个数，如1为单声道，2为双声道。 | 

**返回：**

返回指向OH_AVFormat实例的指针。传入的mimeType为NULL或系统资源不足时返回NULL。


### OH_AVFormat_CreateVideoFormat()

```
struct OH_AVFormat* OH_AVFormat_CreateVideoFormat (const char *mimeType, int32_t width, int32_t height)
```

**描述**

创建视频OH_AVFormat实例指针并预设置指定参数，用于读写数据。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mimeType | MIME类型描述字符串，请参阅[AVCODEC_MIMETYPE](_codec_base.md#变量)。 | 
| width | 亮度的宽度，单位为pixel。 | 
| height | 亮度的高度，单位为pixel。 | 

**返回：**

返回指向OH_AVFormat实例的指针。传入的mimeType为NULL或系统资源不足时返回NULL。


### OH_AVFormat_Destroy()

```
void OH_AVFormat_Destroy (struct OH_AVFormat *format)
```

**描述**

销毁OH_AVFormat实例，不允许重复销毁。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针。 | 

**返回：**

无返回值。

### OH_AVFormat_DumpInfo()

```
const char* OH_AVFormat_DumpInfo (struct OH_AVFormat *format)
```

**描述**

返回OH_AVFormat中包含的key-value组成的字符串。最大可返回1024字节的字符串，销毁format时释放字符串指针。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针。 | 

**返回：**

返回一个由key-value组成的字符串。传入的format为NULL或系统资源不足时返回NULL。


### OH_AVFormat_GetBuffer()

```
bool OH_AVFormat_GetBuffer (struct OH_AVFormat *format, const char *key, uint8_t ** addr, size_t *size)
```

**描述**

从OH_AVFormat中读取指定长度的数据块。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针。 | 
| key | 要读取数据的键。 | 
| addr | 生命周期与format相同，与format一同销毁。 如果开发者需要长时间保持它，必须进行内存拷贝。 | 
| size | 读到数据的长度。 | 

**返回：**

返回值为TRUE表示成功，返回值为FALSE表示失败。

可能的失败原因：

1. 输入format为空指针；
2. 输入format参数结构校验失败；
3. 输入key为空指针；
4. 输入addr为空指针；
5. size为空指针；
6. 获取的key不存在或者未设置。


### OH_AVFormat_GetDoubleValue()

```
bool OH_AVFormat_GetDoubleValue (struct OH_AVFormat *format, const char *key, double *out)
```

**描述**

从OH_AVFormat的[key](_codec_base.md#媒体数据键值对)获取double类型的值。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针。 | 
| key | 读取数据的键。 | 
| out | 读取数据的值。 | 

**返回：**

返回值为TRUE表示成功，返回值为FALSE表示失败。

可能的失败原因：

1. 输入format为空指针；
2. 输入format参数结构校验失败；
3. 输入key为空指针；
4. 输入out为空指针；
5. 获取的key不存在或者未设置。


### OH_AVFormat_GetFloatValue()

```
bool OH_AVFormat_GetFloatValue (struct OH_AVFormat *format, const char *key, float *out)
```

**描述**

从OH_AVFormat的[key](_codec_base.md#媒体数据键值对)获取float类型的值。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针。 | 
| key | 读取数据的键。 | 
| out | 读取数据的值。 | 

**返回：**

返回值为TRUE表示成功，返回值为FALSE表示失败。

可能的失败原因：

1. 输入format为空指针；
2. 输入format参数结构校验失败；
3. 输入key为空指针；
4. 输入out为空指针；
5. 获取的key不存在或者未设置。


### OH_AVFormat_GetIntValue()

```
bool OH_AVFormat_GetIntValue (struct OH_AVFormat *format, const char *key, int32_t *out)
```

**描述**

从OH_AVFormat的[key](_codec_base.md#媒体数据键值对)获取int类型的值。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针。 | 
| key | 读取数据的键。 | 
| out | 读取数据的值。 | 

**返回：**

返回值为TRUE表示成功，返回值为FALSE表示失败。

可能的失败原因：

1. 输入format为空指针；
2. 输入format参数结构校验失败；
3. 输入key为空指针；
4. 输入out为空指针；
5. 获取的key不存在或者未设置。


### OH_AVFormat_GetLongValue()

```
bool OH_AVFormat_GetLongValue (struct OH_AVFormat *format, const char *key, int64_t *out)
```

**描述**

从OH_AVFormat的[key](_codec_base.md#媒体数据键值对)获取long类型的值。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针。 | 
| key | 读取数据的键。 | 
| out | 读取数据的值。 | 

**返回：**

返回值为TRUE表示成功，返回值为FALSE表示失败。

可能的失败原因：

1. 输入format为空指针；
2. 输入format参数结构校验失败；
3. 输入key为空指针；
4. 输入out为空指针；
5. 获取的key不存在或者未设置。


### OH_AVFormat_GetStringValue()

```
bool OH_AVFormat_GetStringValue (struct OH_AVFormat *format, const char *key, const char ** out)
```

**描述**

从OH_AVFormat的[key](_codec_base.md#媒体数据键值对)获取string类型的值。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针。 | 
| key | 读取数据的键。 | 
| out | 读取string指针，out数据的生命周期与format内string对应，如果开发者需要长时间保持它，必须进行拷贝内存。out最大输出字符串长度为256字节，如果长度超过256字节，会报false。 | 

**返回：**

返回值为TRUE表示成功，返回值为FALSE表示失败。

可能的失败原因：

1. 输入format为空指针；
2. 输入format参数结构校验失败；
3. 输入key为空指针；
4. 输入out为空指针；
5. malloc出的out字符串资源不足；
6. 获取的key不存在或者未设置；
7. 输出out的长度超过256字节。


### OH_AVFormat_SetBuffer()

```
bool OH_AVFormat_SetBuffer (struct OH_AVFormat *format, const char *key, const uint8_t *addr, size_t size)
```

**描述**

将指定长度的数据块写入OH_AVFormat。该接口仅能设置buffer类型的参数，参数类型定义详见[CodecBase](_codec_base.md)。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针。 | 
| key | 写入数据的键。 | 
| addr | 写入数据的地址，生命周期由开发者管理。 | 
| size | 写入数据的长度，范围为(0, 1]MB。 | 

**返回：**

返回值为TRUE表示成功，返回值为FALSE表示失败。

可能的失败原因：

1. 输入format为空指针；
2. 输入format参数结构校验失败；
3. 输入key为空指针；
4. 输入addr为空指针；
5. size为0或超过上限，上限为1MB；
6. 设置的key对应的value类型错误。


### OH_AVFormat_SetDoubleValue()

```
bool OH_AVFormat_SetDoubleValue (struct OH_AVFormat *format, const char *key, double value)
```

**描述**

对OH_AVFormat的[key](_codec_base.md#媒体数据键值对)赋double类型的值。该接口仅能设置double类型的参数，参数类型定义详见[CodecBase](_codec_base.md)。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针。 | 
| key | 写入数据的键。 | 
| value | 写入数据的值。 | 

**返回：**

返回值为TRUE表示成功，返回值为FALSE表示失败。

可能的失败原因：

1. 输入format为空指针；
2. 输入format参数结构校验失败；
3. 输入key为空指针；
4. 设置的key对应的value类型错误。


### OH_AVFormat_SetFloatValue()

```
bool OH_AVFormat_SetFloatValue (struct OH_AVFormat *format, const char *key, float value)
```

**描述**

对OH_AVFormat的[key](_codec_base.md#媒体数据键值对)赋float类型的值。该接口仅能设置float类型的参数，参数类型定义详见[CodecBase](_codec_base.md)。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针。 | 
| key | 写入数据的键。 | 
| value | 写入数据的值。 | 

**返回：**

返回值为TRUE表示成功，返回值为FALSE表示失败。

可能的失败原因：

1. 输入format为空指针；
2. 输入format参数结构校验失败；
3. 输入key为空指针；
4. 设置的key对应的value类型错误。

### OH_AVFormat_SetIntValue()

```
bool OH_AVFormat_SetIntValue (struct OH_AVFormat *format, const char *key, int32_t value)
```

**描述**

对OH_AVFormat的[key](_codec_base.md#媒体数据键值对)赋int类型的值。该接口仅能设置int类型的参数，参数类型定义详见[CodecBase](_codec_base.md)。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针。 | 
| key | 写入数据的键。 | 
| value | 写入数据的值。 | 

**返回：**

返回值为TRUE表示成功，返回值为FALSE表示失败。

可能的失败原因：

1. 输入format为空指针；
2. 输入format参数结构校验失败；
3. 输入key为空指针；
4. 设置的key对应的value类型错误。


### OH_AVFormat_SetLongValue()

```
bool OH_AVFormat_SetLongValue (struct OH_AVFormat *format, const char *key, int64_t value)
```

**描述**

对OH_AVFormat的[key](_codec_base.md#媒体数据键值对)赋long类型的值。该接口仅能设置long类型的参数，参数类型定义详见[CodecBase](_codec_base.md)。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针。 | 
| key | 写入数据的键。 | 
| value | 写入数据的值。 | 

**返回：**

返回值为TRUE表示成功，返回值为FALSE表示失败。

可能的失败原因：

1. 输入format为空指针；
2. 输入format参数结构校验失败；
3. 输入key为空指针；
4. 设置的key对应的value类型错误。


### OH_AVFormat_SetStringValue()

```
bool OH_AVFormat_SetStringValue (struct OH_AVFormat *format, const char *key, const char *value)
```

**描述**

对OH_AVFormat的[key](_codec_base.md#媒体数据键值对)赋string类型的值。该接口仅能设置string类型的参数，参数类型定义详见[CodecBase](_codec_base.md)。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| format | 指向OH_AVFormat实例的指针。 | 
| key | 写入数据的键。 | 
| value | 写入字符串数据（使用建议：设置字符长度不超过256字节）。 | 

**返回：**

返回值为TRUE表示成功，返回值为FALSE表示失败。

可能的失败原因：

1. 输入format为空指针；
2. 输入format参数结构校验失败；
3. 输入key为空指针；
4. 输入value为空指针；
5. 设置的key对应的value类型错误。


### OH_AVMemory_Create()

```
OH_AVMemory* OH_AVMemory_Create (int32_t size)
```

**描述**

创建OH_AVMemory实例的指针。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 10

**废弃版本：** 11

**替代接口：**[OH_AVBuffer_Create](#oh_avbuffer_create)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| size | 创建内存的大小，单位字节。 | 

**返回：**

如果创建成功，返回OH_AVMemory实例的指针，如果失败，返回NULL。 使用结束后需要通过OH_AVMemory_Destroy释放内存。


### OH_AVMemory_Destroy()

```
OH_AVErrCode OH_AVMemory_Destroy (struct OH_AVMemory *mem)
```

**描述**

释放OH_AVMemory实例指针的资源。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 10

**废弃版本：** 11

**替代接口：**[OH_AVBuffer_Destroy](#oh_avbuffer_destroy)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mem | 指向OH_AVMemory实例的指针。 | 

**返回：**

如果释放成功返回AV_ERR_OK，如果失败返回具体错误码, 参考[OH_AVErrCode](#oh_averrcode-1)。


### OH_AVMemory_GetAddr()

```
uint8_t* OH_AVMemory_GetAddr (struct OH_AVMemory *mem)
```

**描述**

获取内存虚拟地址。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**废弃版本：** 11

**替代接口：**[OH_AVBuffer_GetAddr](#oh_avbuffer_getaddr)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mem | 指向OH_AVMemory实例的指针。 | 

**返回：**

如果内存有效，返回内存的虚拟地址；如果内存无效，返回NULL。

可能的失败原因：

1. 输入mem为空指针；
2. 输入mem参数结构校验失败；
3. 输入mem中内存为空指针。


### OH_AVMemory_GetSize()

```
int32_t OH_AVMemory_GetSize (struct OH_AVMemory *mem)
```

**描述**

获取内存长度。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**废弃版本：** 11

**替代接口：**[OH_AVBuffer_GetCapacity](#oh_avbuffer_getcapacity)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mem | 指向OH_AVMemory实例的指针。 | 

**返回：**

如果内存有效，返回内存长度；如果内存无效，返回-1。

可能的失败原因：

1. 输入mem为空指针；
2. 输入mem参数结构校验失败；
3. 输入mem中内存为空指针。
