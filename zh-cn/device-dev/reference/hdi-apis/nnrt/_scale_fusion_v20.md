# ScaleFusion


## 概述

给定一个tensor，计算其缩放后的值。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_SCALE_FUSION。

输入：

- x，n维tensor。

- scale，缩放tensor。

- bias，偏置tensor。

输出：

- output， scale的计算结果，一个n维tensor，类型和x一致，shape由axis决定。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long [axis](#axis) | 指定缩放的维度。  | 
| enum [ActivationType](_n_n_rt_v20.md#activationtype)[activationType](#activationtype) | 激活函数，详情请参考：[ActivationType](_n_n_rt_v20.md#activationtype)。  | 


## 类成员变量说明


### activationType

```
enum ActivationType ScaleFusion::activationType
```
**描述**

激活函数，详情请参考：[ActivationType](_n_n_rt_v20.md#activationtype)。


### axis

```
long ScaleFusion::axis
```
**描述**

指定缩放的维度。
