# OmxCodecBuffer


## **概述**

Codec buffer信息的定义。

**相关模块:**

[Codec](codec.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [bufferId](#bufferid) | buffer的ID。 | 
| [size](#size) | 结构体大小。 | 
| [version](#version) | 组件版本信息。 | 
| [bufferType](#buffertype) | buffer类型。 | 
| [buffer](#buffer) | 编码或者解码使用的buffer。 | 
| [bufferLen](#bufferlen) | buffer大小。 | 
| [allocLen](#alloclen) | 申请的buffer大小。 | 
| [filledLen](#filledlen) | 填充的buffer大小。 | 
| [offset](#offset) | 有效数据从缓冲区开始的起始偏移量。 | 
| [fenceFd](#fencefd) | 该描述符来自buffer消费者，Codec等待成功后才可以使用输入或者输出buffer。 | 
| [type](#type) | 共享内存类型。 | 
| [pts](#pts) | 时间戳。 | 
| [flag](#flag) | 标志。 | 


## **类成员变量说明**


### allocLen

  
```
uint32_t OmxCodecBuffer::allocLen
```

**描述：**

申请的buffer大小。


### buffer

  
```
uint8_t* OmxCodecBuffer::buffer
```

**描述：**

编码或者解码使用的buffer。


### bufferId

  
```
uint32_t OmxCodecBuffer::bufferId
```

**描述：**

buffer ID。


### bufferLen

  
```
uint32_t OmxCodecBuffer::bufferLen
```

**描述：**

buffer大小。


### bufferType

  
```
enum CodecBufferType OmxCodecBuffer::bufferType
```

**描述：**

buffer类型。


### fenceFd

  
```
int32_t OmxCodecBuffer::fenceFd
```

**描述：**

该描述符来自buffer消费者，Codec等待成功后才可以使用输入或者输出buffer。


### filledLen

  
```
uint32_t OmxCodecBuffer::filledLen
```

**描述：**

填充的buffer大小。


### flag

  
```
uint32_t OmxCodecBuffer::flag
```

**描述：**

标志。


### offset

  
```
uint32_t OmxCodecBuffer::offset
```

**描述：**

有效数据从缓冲区开始的起始偏移量。


### pts

  
```
int64_t OmxCodecBuffer::pts
```

**描述：**

时间戳。


### size

  
```
uint32_t OmxCodecBuffer::size
```

**描述：**

结构体大小。


### type

  
```
enum ShareMemTypes OmxCodecBuffer::type
```

**描述：**

共享内存类型。


### version

  
```
union OMX_VERSIONTYPE OmxCodecBuffer::version
```

**描述：**

组件版本信息。
