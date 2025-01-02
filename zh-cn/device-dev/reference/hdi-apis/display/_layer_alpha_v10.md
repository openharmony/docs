# LayerAlpha


## 概述

定义图层Alpha信息的结构体。

**起始版本：** 3.2

**相关模块：**[Display](_display_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| boolean [enGlobalAlpha](#englobalalpha) | 全局Alpha使能标志  | 
| boolean [enPixelAlpha](#enpixelalpha) | 像素Alpha使能标志  | 
| unsigned char [alpha0](#alpha0) | Alpha0值，取值范围：[0, 255]。  | 
| unsigned char [alpha1](#alpha1) | Alpha1值，取值范围：[0, 255]。  | 
| unsigned char [gAlpha](#galpha) | 全局Alpha值，取值范围：[0, 255]。  | 


## 类成员变量说明


### alpha0

```
unsigned char LayerAlpha::alpha0
```
**描述**

Alpha0值，取值范围：[0, 255]。


### alpha1

```
unsigned char LayerAlpha::alpha1
```
**描述**

Alpha1值，取值范围：[0, 255]。


### enGlobalAlpha

```
boolean LayerAlpha::enGlobalAlpha
```
**描述**

全局Alpha使能标志


### enPixelAlpha

```
boolean LayerAlpha::enPixelAlpha
```
**描述**

像素Alpha使能标志


### gAlpha

```
unsigned char LayerAlpha::gAlpha
```
**描述**

全局Alpha值，取值范围：[0, 255]。
