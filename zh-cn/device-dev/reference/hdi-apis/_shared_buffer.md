# SharedBuffer


## 概述

共享内存数据的结构体。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[NNRt](_n_n_rt.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [fd](#fd) | FileDescriptor<br/>共享内存的文件描述符&nbsp; | 
| [bufferSize](#buffersize) | unsigned&nbsp;int<br/>共享内存的空间大小，单位字节&nbsp; | 
| [offset](#offset) | unsigned&nbsp;int<br/>有效数据起始地址在共享内存中的偏移&nbsp; | 
| [dataSize](#datasize) | unsigned&nbsp;int<br/>有效数据的占用空间大小，单位字节&nbsp; | 


## 类成员变量说明


### bufferSize

  
```
unsigned int SharedBuffer::bufferSize
```
**描述:**
共享内存的空间大小，单位字节


### dataSize

  
```
unsigned int SharedBuffer::dataSize
```
**描述:**
有效数据的占用空间大小，单位字节


### fd

  
```
FileDescriptor SharedBuffer::fd
```
**描述:**
共享内存的文件描述符


### offset

  
```
unsigned int SharedBuffer::offset
```
**描述:**
有效数据起始地址在共享内存中的偏移
