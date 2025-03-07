# GfxOpt


## 概述

图像硬件加速相关的操作选项结构体定义，用于图像硬件加速时的操作选项。

**起始版本：** 3.2

**相关模块：**[Display](_display_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| boolean [enGlobalAlpha](#englobalalpha) | 全局Alpha使能位  | 
| unsigned int [globalAlpha](#globalalpha) | 全局Alpha的值  | 
| boolean [enPixelAlpha](#enpixelalpha) | 像素Alpha使能位  | 
| enum [BlendType](_display_v10.md#blendtype)[blendType](#blendtype) | 混合方式  | 
| enum [ColorKey](_display_v10.md#colorkey)[colorKeyFrom](#colorkeyfrom) | 色键模式  | 
| boolean [enableRop](#enablerop) | Rop功能使能位  | 
| enum [RopType](_display_v10.md#roptype)[colorRopType](#colorroptype) | 颜色的Rop类型  | 
| enum [RopType](_display_v10.md#roptype)[alphaRopType](#alpharoptype) | Alpha的Rop类型  | 
| boolean [enableScale](#enablescale) | 缩放功能使能位  | 
| enum [TransformType](_display_v10.md#transformtype)[rotateType](#rotatetype) | 旋转类型  | 
| enum [MirrorType](_display_v10.md#mirrortype)[mirrorType](#mirrortype) | 镜像类型  | 


## 类成员变量说明


### alphaRopType

```
enum RopType GfxOpt::alphaRopType
```
**描述**

Alpha的Rop类型


### blendType

```
enum BlendType GfxOpt::blendType
```
**描述**

混合方式


### colorKeyFrom

```
enum ColorKey GfxOpt::colorKeyFrom
```
**描述**

色键模式


### colorRopType

```
enum RopType GfxOpt::colorRopType
```
**描述**

颜色的Rop类型


### enableRop

```
boolean GfxOpt::enableRop
```
**描述**

Rop功能使能位


### enableScale

```
boolean GfxOpt::enableScale
```
**描述**

缩放功能使能位


### enGlobalAlpha

```
boolean GfxOpt::enGlobalAlpha
```
**描述**

全局Alpha使能位


### enPixelAlpha

```
boolean GfxOpt::enPixelAlpha
```
**描述**

像素Alpha使能位


### globalAlpha

```
unsigned int GfxOpt::globalAlpha
```
**描述**

全局Alpha的值


### mirrorType

```
enum MirrorType GfxOpt::mirrorType
```
**描述**

镜像类型


### rotateType

```
enum TransformType GfxOpt::rotateType
```
**描述**

旋转类型
