# OH_AVCodecBufferAttr


## 概述

定义OH_AVCodec的缓冲区描述信息。

\@syscap SystemCapability.Multimedia.Media.CodecBase

**起始版本：**

9

**相关模块：**

[CodecBase](_codec_base.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [pts](#pts) | 此缓冲区的显示时间戳（以微秒为单位） | 
| [size](#size) | 缓冲区中包含的数据的大小（以字节为单位） | 
| [offset](#offset) | 此缓冲区中有效数据的起始偏移量 | 
| [flags](#flags) | 此缓冲区具有的标志，也是多个[OH_AVCodecBufferFlags](_codec_base.md#oh_avcodecbufferflags)的组合。 | 


## 结构体成员变量说明


### pts

  
```
int64_t pts
```

**描述：**

此缓冲区的显示时间戳（以微秒为单位）

**起始版本：**

9


### size

  
```
int32_t size
```

**描述：**

缓冲区中包含的数据的大小（以字节为单位）

**起始版本：**

9


### offset

  
```
int32_t offset
```

**描述：**

此缓冲区中有效数据的起始偏移量

**起始版本：**

9


### flags

  
```
uint32_t flags
```

**描述：**

此缓冲区具有的标志，也是多个[OH_AVCodecBufferFlags](_codec_base.md#oh_avcodecbufferflags)的组合。

**起始版本：**

9
