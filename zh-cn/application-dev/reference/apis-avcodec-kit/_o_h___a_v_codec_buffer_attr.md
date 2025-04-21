# OH_AVCodecBufferAttr


## 概述

定义OH_AVCodec的缓冲区描述信息。

**系统能力：** SystemCapability.Multimedia.Media.Core

**起始版本：** 9

**相关模块：**[Core](_core.md)

**所在头文件：**[native_avbuffer_info.h](native__avbuffer__info_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int64_t [pts](#pts) | 此缓冲区的显示时间戳（以微秒为单位）。 | 
| int32_t [size](#size) | 缓冲区中包含的数据的大小（以字节为单位）。 | 
| int32_t [offset](#offset) | 此缓冲区中有效数据的起始偏移量。 | 
| uint32_t [flags](#flags) | 此缓冲区具有的标志，请参阅[OH_AVCodecBufferFlags](_core.md#oh_avcodecbufferflags)。 | 


## 结构体成员变量说明


### flags

```
uint32_t OH_AVCodecBufferAttr::flags
```

**描述**

此缓冲区具有的标志，请参阅[OH_AVCodecBufferFlags](_core.md#oh_avcodecbufferflags)。


### offset

```
int32_t OH_AVCodecBufferAttr::offset
```

**描述**

此缓冲区中有效数据的起始偏移量。


### pts

```
int64_t OH_AVCodecBufferAttr::pts
```

**描述**

此缓冲区的显示时间戳（以微秒为单位）。


### size

```
int32_t OH_AVCodecBufferAttr::size
```

**描述**

缓冲区中包含的数据的大小（以字节为单位）。
