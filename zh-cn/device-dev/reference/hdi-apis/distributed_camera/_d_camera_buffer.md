# DCameraBuffer


## 概述

分布式相机进程间传递数据的共享内存结构体。

**起始版本：** 3.2

**相关模块：**[Camera](_distributed.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [index_](#index_) | 缓冲区索引。 | 
| unsigned int [size_](#size_) | 缓冲区大小。 | 
| NativeBuffer [bufferHandle_](#bufferhandle_) | Native缓冲区。 | 


## 类成员变量说明


### bufferHandle_

```
NativeBuffer DCameraBuffer::bufferHandle_
```

**描述**


Native缓冲区。


### index_

```
int DCameraBuffer::index_
```

**描述**


缓冲区索引。


### size_

```
unsigned int DCameraBuffer::size_
```

**描述**


缓冲区大小。
