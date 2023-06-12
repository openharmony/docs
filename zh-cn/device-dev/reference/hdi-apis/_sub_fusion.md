# SubFusion


## 概述

计算两个输入的差值。

该算子对应的[NodeType](_n_n_rt.md#nodetype)为NODE_TYPE_SUB_FUSION。

输入：

- x，被减数，是int或float类型的张量。

- y，减数，是int或float类型的张量。

输出：

- output，两个input相减的差。output的shape由x和y共同决定，x和y的shape相同时，output的shape和x、y相同； shape不同时，需要将x或y做broadcast操作后，相减得到output。output的精度为x和y中精度更高的决定。

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
| [activationType](#activationtype) | enum&nbsp;[ActivationType](_n_n_rt.md#activationtype)<br/>激活函数类型，详情请参考：[ActivationType](_n_n_rt.md#activationtype)。&nbsp; | 


## 类成员变量说明


### activationType

  
```
enum ActivationType SubFusion::activationType
```
**描述:**

激活函数类型，详情请参考：[ActivationType](_n_n_rt.md#activationtype)。
