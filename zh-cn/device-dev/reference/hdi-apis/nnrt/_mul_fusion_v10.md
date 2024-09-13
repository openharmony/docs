# MulFusion


## 概述

对输入x1和x2，将x1和x2相同的位置的元素相乘得到output。

如果x1和x2类型shape不同，要求x1和x2可以通过broadcast扩充成相同的shape进行相乘。 该算子对应的[NodeType](_n_n_rt_v10.md#nodetype)为NODE_TYPE_MUL_FUSION。

输入：

- x1，int或float类型的张量。

- x2，int或float类型的张量。

输出：

- x1和x2每个元素的乘积。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [ActivationType](_n_n_rt_v10.md#activationtype)[activationType](#activationtype) | 激活函数，详情请参考：[ActivationType](_n_n_rt_v10.md#activationtype)。  | 


## 类成员变量说明


### activationType

```
enum ActivationType MulFusion::activationType
```
**描述**

激活函数，详情请参考：[ActivationType](_n_n_rt_v10.md#activationtype)。
