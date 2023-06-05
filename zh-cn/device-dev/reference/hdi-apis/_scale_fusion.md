# ScaleFusion


## 概述

给定一个tensor，计算其缩放后的值。

该算子对应的[NodeType](_n_n_rt.md#nodetype)为NODE_TYPE_SCALE_FUSION。

输入：

- x，n维tensor。

- scale，缩放tensor。

- bias，偏置tensor。

输出：

- output， scale的计算结果，一个n维tensor，类型和x一致，shape由axis决定。

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
| [axis](#axis) | long<br/>指定缩放的维度。&nbsp; | 
| [activationType](#activationtype) | enum&nbsp;[ActivationType](_n_n_rt.md#activationtype)<br/>激活函数，详情请参考：[ActivationType](_n_n_rt.md#activationtype)。&nbsp; | 


## 类成员变量说明


### activationType

  
```
enum ActivationType ScaleFusion::activationType
```
**描述:**

激活函数，详情请参考：[ActivationType](_n_n_rt.md#activationtype)。


### axis

  
```
long ScaleFusion::axis
```
**描述:**

指定缩放的维度。
