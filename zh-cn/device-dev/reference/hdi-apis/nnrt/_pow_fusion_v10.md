# PowFusion


## 概述

求x的y次幂，输入必须是两个tensor或一个tensor和一个标量。

当输入是两个tensor时，它们的数据类型不能同时为DATA_TYPE_BOOL，且要求两个tensor的shape相同。当输入是一个tensor和一个标量时，标量只能是一个常数。

该算子对应的[NodeType](_n_n_rt_v10.md#nodetype)为NODE_TYPE_POW_FUSION。

参数说明：x的每个元素会做如下运算：x' = scale\*x+shift，然后对于x'再求y次幂。

输入：

- x，实数、bool值或tensor，tensor的数据类型为实数或DATA_TYPE_BOOL。

- y，实数、bool值或tensor，tensor的数据类型为实数或DATA_TYPE_BOOL。

输出：

- output，形状由x和y broadcast后的形状决定。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| float [scale](#scale) | 对x的数值进行缩放。  | 
| float [shift](#shift) | 对x的数值缩放后的值进行增减。  | 


## 类成员变量说明


### scale

```
float PowFusion::scale
```
**描述**

对x的数值进行缩放。


### shift

```
float PowFusion::shift
```
**描述**

对x的数值缩放后的值进行增减。
