# SharedBuffer


## 概述

共享内存数据的结构体。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| FileDescriptor [fd](#fd) | 共享内存的文件描述符  | 
| unsigned int [bufferSize](#buffersize) | 共享内存的空间大小，单位字节  | 
| unsigned int [offset](#offset) | 有效数据起始地址在共享内存中的偏移  | 
| unsigned int [dataSize](#datasize) | 有效数据的占用空间大小，单位字节  | 


## 类成员变量说明


### bufferSize

```
unsigned int SharedBuffer::bufferSize
```
**描述**

共享内存的空间大小，单位字节


### dataSize

```
unsigned int SharedBuffer::dataSize
```
**描述**

有效数据的占用空间大小，单位字节


### fd

```
FileDescriptor SharedBuffer::fd
```
**描述**

共享内存的文件描述符


### offset

```
unsigned int SharedBuffer::offset
```
**描述**

有效数据起始地址在共享内存中的偏移
