# LayerInfo


## 概述

Defines 定义图层信息结构体。

在创建图层时，需要将LayerInfo传递给创建图层接口，创建图层接口根据图层信息创建相应图层。

**起始版本：** 3.2

**相关模块：**[Display](_display_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [width](#width) | 图层宽度  | 
| int [height](#height) | 图层高度  | 
| enum [LayerType](_display_v10.md#layertype)[type](#type) | 图层类型，包括图形层、视频层和媒体播放模式。  | 
| int [bpp](#bpp) | 每像素所占Bit数  | 
| enum [PixelFormat](_display_v10.md#pixelformat)[pixFormat](#pixformat) | 图层像素格式  | 


## 类成员变量说明


### bpp

```
int LayerInfo::bpp
```
**描述**

每像素所占Bit数


### height

```
int LayerInfo::height
```
**描述**

图层高度


### pixFormat

```
enum PixelFormat LayerInfo::pixFormat
```
**描述**

图层像素格式


### type

```
enum LayerType LayerInfo::type
```
**描述**

图层类型，包括图形层、视频层和媒体播放模式。


### width

```
int LayerInfo::width
```
**描述**

图层宽度
