# MaxPoolFusion


## 概述

对输入x，计算 2D 最大值池化。

该算子对应的[NodeType](_n_n_rt.md#nodetype)为NODE_TYPE_MAX_POOL_FUSION。

参数限制：当padMode==PAD_MODE_PAD时，padList的数值必须大于等于0。其他情况下padding的数值必须为0。

输入：

- x，n维tensor

输出：

- output，x1和x2两个tensor对应元素的最大值。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[NNRt](_n_n_rt.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [kernelSize](#kernelsize) | long[]<br/>取最大值的kernel大小，是一个长度为2的int数组[kernel_height，kernel_weight]。&nbsp; | 
| [strides](#strides) | long[]<br/>池化核步长，kernel移动的距离，是一个长度为2的int数组。&nbsp; | 
| [pad](#pad) | long[]<br/>填充数组。&nbsp; | 
| [padMode](#padmode) | enum&nbsp;[PadMode](_n_n_rt.md#padmode)<br/>填充类型，详情请参考：[PadMode](_n_n_rt.md#padmode)。&nbsp; | 
| [format](#format) | enum&nbsp;[Format](_n_n_rt.md#format)<br/>运算时数据的排列，详情请参考：[Format](_n_n_rt.md#format)。&nbsp; | 
| [global](#global) | boolean<br/>是否是全局池化。&nbsp; | 
| [activationType](#activationtype) | enum&nbsp;[ActivationType](_n_n_rt.md#activationtype)<br/>激活函数，详情请参考：[ActivationType](_n_n_rt.md#activationtype)。&nbsp; | 


## 类成员变量说明


### activationType

  
```
enum ActivationType MaxPoolFusion::activationType
```
**描述:**
激活函数，详情请参考：[ActivationType](_n_n_rt.md#activationtype)。


### format

  
```
enum Format MaxPoolFusion::format
```
**描述:**
运算时数据的排列，详情请参考：[Format](_n_n_rt.md#format)。


### global

  
```
boolean MaxPoolFusion::global
```
**描述:**
是否是全局池化。


### kernelSize

  
```
long [] MaxPoolFusion::kernelSize
```
**描述:**
取最大值的kernel大小，是一个长度为2的int数组[kernel_height，kernel_weight]。


### pad

  
```
long [] MaxPoolFusion::pad
```
**描述:**
填充数组。


### padMode

  
```
enum PadMode MaxPoolFusion::padMode
```
**描述:**
填充类型，详情请参考：[PadMode](_n_n_rt.md#padmode)。


### strides

  
```
long [] MaxPoolFusion::strides
```
**描述:**
池化核步长，kernel移动的距离，是一个长度为2的int数组。
