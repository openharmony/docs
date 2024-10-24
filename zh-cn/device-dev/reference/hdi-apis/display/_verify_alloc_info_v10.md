# VerifyAllocInfo


## 概述

用于验证内存分配信息的结构体定义。

**起始版本：** 3.2

**相关模块：**[Display](_display_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [width](#width) | 分配内存的宽度  | 
| unsigned int [height](#height) | 分配内存的高度  | 
| unsigned long [usage](#usage) | 内存的用处  | 
| unsigned int [format](#format) | 分配内存的像素格式  | 


## 类成员变量说明


### format

```
unsigned int VerifyAllocInfo::format
```
**描述**

分配内存的像素格式


### height

```
unsigned int VerifyAllocInfo::height
```
**描述**

分配内存的高度


### usage

```
unsigned long VerifyAllocInfo::usage
```
**描述**

内存的用处


### width

```
unsigned int VerifyAllocInfo::width
```
**描述**

分配内存的宽度
