# RawFileDescriptor


## 概述

提供rawfile文件描述符信息。

RawFileDescriptor是[OH_ResourceManager_GetRawFileDescriptor](rawfile.md#oh_resourcemanager_getrawfiledescriptor)的输出参数, 涵盖了rawfile文件的文件描述符以及在HAP包中的起始位置和长度。

**起始版本：** 8

**相关模块：**[Rawfile](rawfile.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int [fd](#fd) | rawfile文件描述符，单位为int。  | 
| long [start](#start) | rawfile在HAP包中的起始位置，单位为long。  | 
| long [length](#length) | rawfile在HAP包中的长度，单位为long。  | 


## 结构体成员变量说明


### fd

```
int RawFileDescriptor::fd
```
**描述** 

rawfile文件描述符，单位为int。


### length

```
long RawFileDescriptor::length
```
**描述**

rawfile在HAP包中的长度，单位为long。


### start

```
long RawFileDescriptor::start
```
**描述**

rawfile在HAP包中的起始位置，单位为long。
