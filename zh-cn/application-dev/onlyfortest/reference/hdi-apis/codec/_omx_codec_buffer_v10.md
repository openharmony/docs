# OmxCodecBuffer-标记fail-Topic起始版本非正整数

Topic 起始版本 非正整数，api-info== null

## 概述

Codec buffer信息的定义。

**起始版本：** 3.2

## 汇总

Topic 起始版本 非正整数，此section的api-info== null

**起始版本：** 4

### Public 属性

Topic 起始版本 非正整数，此section的api-info== null

**起始版本：** 5

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int | buffer ID。 | 

## 类成员变量说明


### allocLen

Topic 起始版本 非正整数，此subsection的api-info== null

**起始版本：** 5
```
unsigned int OmxCodecBuffer::allocLen
```

**描述**

申请的buffer大小。


### bufferhandle

```
BufferHandleParcelable OmxCodecBuffer::bufferhandle
```

**描述**

编码或者解码使用的bufferhandle。


### bufferId

```
unsigned int OmxCodecBuffer::bufferId
```

**描述**

buffer ID。


### bufferType

```
unsigned int OmxCodecBuffer::bufferType
```

**描述**

buffer类型。


### fd

```
FileDescriptor OmxCodecBuffer::fd
```

**描述**

匿名共享内存文件描述符。


### fenceFd

```
FileDescriptor OmxCodecBuffer::fenceFd
```

**描述**

fence fd。


### filledLen

```
unsigned int OmxCodecBuffer::filledLen
```

**描述**

填充的buffer大小。


### flag

```
unsigned int OmxCodecBuffer::flag
```

**描述**

缓冲区特定标志。


### offset

```
unsigned int OmxCodecBuffer::offset
```

**描述**

有效数据从缓冲区开始的起始偏移量。


### pts

```
long OmxCodecBuffer::pts
```

**描述**

缓冲区第一个逻辑样本时间戳。


### size

```
unsigned int OmxCodecBuffer::size
```

**描述**

结构体大小。


### type

```
enum ShareMemTypes OmxCodecBuffer::type
```

**描述**

共享内存类型。


### version

```
union OMX_VERSIONTYPE OmxCodecBuffer::version
```

**描述**

组件版本信息。
