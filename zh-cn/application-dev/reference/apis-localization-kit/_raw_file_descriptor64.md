# RawFileDescriptor64


## 概述

提供较大rawfile文件描述符信息。

RawFileDescriptor64是[OH_ResourceManager_GetRawFileDescriptor64](rawfile.md#oh_resourcemanager_getrawfiledescriptor64)的输出参数, 涵盖了rawfile文件的文件描述符以及在HAP包中的起始位置和长度。

**起始版本：** 11

**相关模块：**[Rawfile](rawfile.md)

**所在头文件：**[raw_file.h](raw__file_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int [fd](#fd) | rawfile文件描述符，单位为int。  | 
| int64_t [start](#start) | rawfile在HAP包中的起始位置，单位为int64_t。  | 
| int64_t [length](#length) | rawfile在HAP包中的长度，单位为int64_t。  | 


## 结构体成员变量说明


### fd

```
int RawFileDescriptor64::fd
```
**描述**

rawfile文件描述符，单位为int。


### length

```
int64_t RawFileDescriptor64::length
```
**描述**

rawfile在HAP包中的长度，单位为int64_t。


### start

```
int64_t RawFileDescriptor64::start
```
**描述**

rawfile在HAP包中的起始位置，单位为int64_t。