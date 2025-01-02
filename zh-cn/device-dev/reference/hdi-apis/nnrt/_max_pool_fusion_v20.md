# MaxPoolFusion


## 概述

对输入x，计算 2D 最大值池化。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_MAX_POOL_FUSION。

参数限制：当padMode==PAD_MODE_PAD时，padList的数值必须大于等于0。其他情况下padding的数值必须为0。

输入：

- x，n维tensor

输出：

- output，x1和x2两个tensor对应元素的最大值。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long[] [kernelSize](#kernelsize) | 取最大值的kernel大小，是一个长度为2的int数组[kernel_height，kernel_weight]。  | 
| long[] [strides](#strides) | 池化核步长，kernel移动的距离，是一个长度为2的int数组。  | 
| long[] [pad](#pad) | 填充数组。  | 
| enum [PadMode](_n_n_rt_v20.md#padmode)[padMode](#padmode) | 填充类型，详情请参考：[PadMode](_n_n_rt_v20.md#padmode)。  | 
| enum [Format](_n_n_rt_v20.md#format)[format](#format) | 运算时数据的排列，详情请参考：[Format](_n_n_rt_v20.md#format)。  | 
| boolean [global](#global) | 是否是全局池化。  | 
| enum [ActivationType](_n_n_rt_v20.md#activationtype)[activationType](#activationtype) | 激活函数，详情请参考：[ActivationType](_n_n_rt_v20.md#activationtype)。  | 


## 类成员变量说明


### activationType

```
enum ActivationType MaxPoolFusion::activationType
```
**描述**

激活函数，详情请参考：[ActivationType](_n_n_rt_v20.md#activationtype)。


### format

```
enum Format MaxPoolFusion::format
```
**描述**

运算时数据的排列，详情请参考：[Format](_n_n_rt_v20.md#format)。


### global

```
boolean MaxPoolFusion::global
```
**描述**

是否是全局池化。


### kernelSize

```
long [] MaxPoolFusion::kernelSize
```
**描述**

取最大值的kernel大小，是一个长度为2的int数组[kernel_height，kernel_weight]。


### pad

```
long [] MaxPoolFusion::pad
```
**描述**

填充数组。


### padMode

```
enum PadMode MaxPoolFusion::padMode
```
**描述**

填充类型，详情请参考：[PadMode](_n_n_rt_v20.md#padmode)。


### strides

```
long [] MaxPoolFusion::strides
```
**描述**

池化核步长，kernel移动的距离，是一个长度为2的int数组。
