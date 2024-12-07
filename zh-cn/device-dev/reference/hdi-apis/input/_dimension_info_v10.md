# DimensionInfo


## 概述

Input设备的维度信息。

**起始版本：** 3.2

**相关模块：**[HdiInput](_hdi_input.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int [axis](#axis) | 坐标轴  | 
| int [min](#min) | 记录各个坐标的最小值  | 
| int [max](#max) | 记录各个坐标的最大值  | 
| int [fuzz](#fuzz) | 记录各个坐标的分辨率  | 
| int [flat](#flat) | 记录各个坐标的基准值  | 
| int [range](#range) | 范围  | 


## 类成员变量说明


### axis

```
int DimensionInfo::axis
```
**描述**

坐标轴


### flat

```
int DimensionInfo::flat
```
**描述**

记录各个坐标的基准值


### fuzz

```
int DimensionInfo::fuzz
```
**描述**

记录各个坐标的分辨率


### max

```
int DimensionInfo::max
```
**描述**

记录各个坐标的最大值


### min

```
int DimensionInfo::min
```
**描述**

记录各个坐标的最小值


### range

```
int DimensionInfo::range
```
**描述**

范围
