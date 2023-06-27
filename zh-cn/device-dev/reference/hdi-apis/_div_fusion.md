# DivFusion


## 概述

将两个tensor执行除法运算。

该算子对应的[NodeType](_n_n_rt.md#nodetype)为NODE_TYPE_DIV_FUSION。

输入：

- x1，int或float类型的张量。

- x2，int或float类型的张量。

输出：

- output， 输出两输入相除后的结果。

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
| [activationType](#activationtype) | enum&nbsp;[ActivationType](_n_n_rt.md#activationtype)<br/>激活函数类型，详情请参考：[Activation](_activation.md)。&nbsp; | 


## 类成员变量说明


### activationType

  
```
enum ActivationType DivFusion::activationType
```
**描述:**

激活函数类型，详情请参考：[Activation](_activation.md)。
