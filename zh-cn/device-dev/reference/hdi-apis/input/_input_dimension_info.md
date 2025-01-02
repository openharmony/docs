# InputDimensionInfo


## 概述

Input设备的维度信息。

**起始版本：** 1.0

**相关模块：**[Input](_input.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [axis](#axis) | 坐标轴  | 
| int32_t [min](#min) | 记录各个坐标的最小值  | 
| int32_t [max](#max) | 记录各个坐标的最大值  | 
| int32_t [fuzz](#fuzz) | 记录各个坐标的分辨率  | 
| int32_t [flat](#flat) | 记录各个坐标的基准值  | 
| int32_t [range](#range) | 范围  | 


## 类成员变量说明


### axis

```
int32_t InputDimensionInfo::axis
```
**描述**

坐标轴


### flat

```
int32_t InputDimensionInfo::flat
```
**描述**

记录各个坐标的基准值


### fuzz

```
int32_t InputDimensionInfo::fuzz
```
**描述**

记录各个坐标的分辨率


### max

```
int32_t InputDimensionInfo::max
```
**描述**

记录各个坐标的最大值


### min

```
int32_t InputDimensionInfo::min
```
**描述**

记录各个坐标的最小值


### range

```
int32_t InputDimensionInfo::range
```
**描述**

范围
