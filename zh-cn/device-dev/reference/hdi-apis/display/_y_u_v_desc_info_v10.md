# YUVDescInfo


## 概述

YUV描述信息结构体定义。

**起始版本：** 3.2

**相关模块：**[Display](_display_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned long [baseAddr](#baseaddr) | 内存的初始地址  | 
| unsigned int [yOffset](#yoffset) | Y的偏移量  | 
| unsigned int [uOffset](#uoffset) | U的偏移量  | 
| unsigned int [vOffset](#voffset) | V的偏移量  | 
| unsigned int [yStride](#ystride) | Y的Stride信息  | 
| unsigned int [uvStride](#uvstride) | UV的Stride信息  | 
| unsigned int [uvStep](#uvstep) | UV的Step信息  | 


## 类成员变量说明


### baseAddr

```
unsigned long YUVDescInfo::baseAddr
```
**描述**

内存的初始地址


### uOffset

```
unsigned int YUVDescInfo::uOffset
```
**描述**

U的偏移量


### uvStep

```
unsigned int YUVDescInfo::uvStep
```
**描述**

UV的Step信息


### uvStride

```
unsigned int YUVDescInfo::uvStride
```
**描述**

UV的Stride信息


### vOffset

```
unsigned int YUVDescInfo::vOffset
```
**描述**

V的偏移量


### yOffset

```
unsigned int YUVDescInfo::yOffset
```
**描述**

Y的偏移量


### yStride

```
unsigned int YUVDescInfo::yStride
```
**描述**

Y的Stride信息
