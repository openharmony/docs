# DrmBuffer


## 概述

定义DrmBuffer，该信息由[IMediaDecryptModule::DecryptMediaData](interface_i_media_decrypt_module.md#decryptmediadata)使用。

**起始版本：** 4.1

**相关模块：**[HdiDrm](_hdi_drm.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [bufferType](#buffertype) | buffer类型，由实现平台定义。  | 
| FileDescriptor [fd](#fd) | buffer描述符。  | 
| unsigned int [bufferLen](#bufferlen) | buffer长度。  | 
| unsigned int [allocLen](#alloclen) | 分配buffer的长度。  | 
| unsigned int [filledLen](#filledlen) | 实际填充数据的长度。  | 
| unsigned int [offset](#offset) | 数据基于buffer首地址的偏移。  | 
| unsigned int [sharedMemType](#sharedmemtype) | 共享内存类型。  | 


## 类成员变量说明


### allocLen

```
unsigned int DrmBuffer::allocLen
```
**描述**

分配buffer的长度。


### bufferLen

```
unsigned int DrmBuffer::bufferLen
```
**描述**

buffer长度。


### bufferType

```
unsigned int DrmBuffer::bufferType
```
**描述**

buffer类型，由实现平台定义。


### fd

```
FileDescriptor DrmBuffer::fd
```
**描述**

buffer描述符。


### filledLen

```
unsigned int DrmBuffer::filledLen
```
**描述**

实际填充数据的长度。


### offset

```
unsigned int DrmBuffer::offset
```
**描述**

数据基于buffer首地址的偏移。


### sharedMemType

```
unsigned int DrmBuffer::sharedMemType
```
**描述**

共享内存类型。
