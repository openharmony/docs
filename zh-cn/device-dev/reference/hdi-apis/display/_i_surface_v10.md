# ISurface


## 概述

用于存放窗口相关信息的结构体定义，提供给硬件加速使用，例如图像合成，位图搬移等操作。

**起始版本：** 3.2

**相关模块：**[Display](_display_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned long [phyAddr](#phyaddr) | 图像首地址。  | 
| int [height](#height) | 图像高度。  | 
| int [width](#width) | 图像宽度。  | 
| int [stride](#stride) | 图像跨度。  | 
| enum [PixelFormat](_display_v10.md#pixelformat)。[enColorFmt](#encolorfmt) | 图像格式。  | 
| boolean [bYCbCrClut](#bycbcrclut) | CLUT表是否位于 YCbCr 空间。  | 
| boolean [bAlphaMax255](#balphamax255) | 图像Alpha最大值为255还是128。  | 
| boolean [bAlphaExt1555](#balphaext1555) | 是否使能1555的Alpha扩展。  | 
| unsigned char [alpha0](#alpha0) | Alpha0值，取值范围：[0,255]。  | 
| unsigned char [alpha1](#alpha1) | Alpha1值，取值范围：[0,255]。  | 
| unsigned long [cbcrPhyAddr](#cbcrphyaddr) | CbCr分量地址。  | 
| int [cbcrStride](#cbcrstride) | CbCr分量跨度。  | 
| unsigned long [clutPhyAddr](#clutphyaddr) | Clut表首地址，用作颜色扩展或颜色校正。  | 


## 类成员变量说明


### alpha0

```
unsigned char ISurface::alpha0
```
**描述**

Alpha0值，取值范围：[0,255]。


### alpha1

```
unsigned char ISurface::alpha1
```
**描述**

Alpha1值，取值范围：[0,255]。


### bAlphaExt1555

```
boolean ISurface::bAlphaExt1555
```
**描述**

是否使能1555的Alpha扩展。


### bAlphaMax255

```
boolean ISurface::bAlphaMax255
```
**描述**

图像Alpha最大值为255还是128。


### bYCbCrClut

```
boolean ISurface::bYCbCrClut
```
**描述**

CLUT表是否位于 YCbCr 空间。


### cbcrPhyAddr

```
unsigned long ISurface::cbcrPhyAddr
```
**描述**

CbCr分量地址。


### cbcrStride

```
int ISurface::cbcrStride
```
**描述**

CbCr分量跨度。


### clutPhyAddr

```
unsigned long ISurface::clutPhyAddr
```
**描述**

Clut表首地址，用作颜色扩展或颜色校正。


### enColorFmt

```
enum PixelFormat ISurface::enColorFmt
```
**描述**

图像格式。


### height

```
int ISurface::height
```
**描述**

图像高度。


### phyAddr

```
unsigned long ISurface::phyAddr
```
**描述**

图像首地址。


### stride

```
int ISurface::stride
```
**描述**

图像跨度。


### width

```
int ISurface::width
```
**描述**

图像宽度。
