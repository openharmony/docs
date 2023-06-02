# BiasAdd


## 概述

对给出的输入张量上的各个维度方向上的数据进行偏置。

该算子对应的[NodeType](_n_n_rt.md#nodetype)为NODE_TYPE_BIAS_ADD。

输入：

- x，n维tensor。

- bias，偏置值tensor。

输出：

- 输出张量，根据输入中每个维度方向偏置之后的结果。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[NNRt](_n_n_rt.md)
