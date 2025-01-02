# AvgPoolFusion


## 概述

在输入tensor上应用 2D 平均池化。支持int8量化输入。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_AVGPOOL_FUSION。

参数限制：当padMode==PAD_MODE_PAD时，padList的数值必须大于等于0。其他情况下padding的数值必须为0。

输入：

- x，n维张量。

输出：

- output， 输出平均池化后的张量。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long[] [kernelSize](#kernelsize) | 用来取平均值的kernel大小，是一个长度为2的int数组[kernel_height，kernel_weight]， 第一个数表示kernel高度，第二个数表示kernel宽度。  | 
| long[] [strides](#strides) | kernel移动的距离，是一个长度为2的int数组[stride_height，stride_weight]， 第一个数表示高度上的移动步幅，第二个数表示宽度上的移动步幅。  | 
| long[] [pad](#pad) | x周围的填充，是一个长度为4的int数组[top，bottom，left，right]，并且以最近邻的值填充。  | 
| enum [PadMode](_n_n_rt_v20.md#padmode)[padMode](#padmode) | 填充模式  | 
| enum [RoundMode](_n_n_rt_v20.md#roundmode)[roundMode](#roundmode) | 取整数的算法  | 
| enum [Format](_n_n_rt_v20.md#format)[format](#format) | 运算时的数据排列排列，详情请参考：[Format](_n_n_rt_v20.md#format) | 
| boolean [global](#global) | 是否是全局池化  | 
| enum [ActivationType](_n_n_rt_v20.md#activationtype)[activationType](#activationtype) | 激活函数，详情请参考：[ActivationType](_n_n_rt_v20.md#activationtype) | 


## 类成员变量说明


### activationType

```
enum ActivationType AvgPoolFusion::activationType
```
**描述**

激活函数，详情请参考：[ActivationType](_n_n_rt_v20.md#activationtype)


### format

```
enum Format AvgPoolFusion::format
```
**描述**

运算时的数据排列排列，详情请参考：[Format](_n_n_rt_v20.md#format)


### global

```
boolean AvgPoolFusion::global
```
**描述**

是否是全局池化


### kernelSize

```
long [] AvgPoolFusion::kernelSize
```
**描述**

用来取平均值的kernel大小，是一个长度为2的int数组[kernel_height，kernel_weight]， 第一个数表示kernel高度，第二个数表示kernel宽度。


### pad

```
long [] AvgPoolFusion::pad
```
**描述**

x周围的填充，是一个长度为4的int数组[top，bottom，left，right]，并且以最近邻的值填充。


### padMode

```
enum PadMode AvgPoolFusion::padMode
```
**描述**

填充模式


### roundMode

```
enum RoundMode AvgPoolFusion::roundMode
```
**描述**

取整数的算法


### strides

```
long [] AvgPoolFusion::strides
```
**描述**

kernel移动的距离，是一个长度为2的int数组[stride_height，stride_weight]， 第一个数表示高度上的移动步幅，第二个数表示宽度上的移动步幅。
