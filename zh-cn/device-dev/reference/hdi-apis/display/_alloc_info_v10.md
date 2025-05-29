# AllocInfo


## 概述

定义待分配内存的信息。

**起始版本：** 3.2

**相关模块：**[Display](_display_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [width](#width) | 申请内存宽度  | 
| unsigned int [height](#height) | 申请内存高度  | 
| unsigned long [usage](#usage) | 申请内存的使用场景  | 
| unsigned int [format](#format) | 申请内存格式  | 
| unsigned int [expectedSize](#expectedsize) | 申请内存大小  | 


## 类成员变量说明


### expectedSize

```
unsigned int AllocInfo::expectedSize
```
**描述**

申请内存大小


### format

```
unsigned int AllocInfo::format
```
**描述**

申请内存格式


### height

```
unsigned int AllocInfo::height
```
**描述**

申请内存高度


### usage

```
unsigned long AllocInfo::usage
```
**描述**

申请内存的使用场景


### width

```
unsigned int AllocInfo::width
```
**描述**

申请内存宽度
