# SquaredDifference


## 概述

计算两个输入的差值并返回差值的平方。SquaredDifference算子支持tensor和tensor相减。

该算子对应的[NodeType](_n_n_rt_v10.md#nodetype)为NODE_TYPE_SQUEEZE。

输入：

- x，被减数，是一个tensor，tensor的类型可以是实数或DATA_TYPE_BOOL。

- y，减数，是一个tensor，tensor的类型可以是实数或DATA_TYPE_BOOL。

输出：

- output，output的shape由x1和y共同决定，x1和y的shape相同时， output的shape和x1、y相同；shape不同时，需要将x1或y做broadcast操作后，相减得到output。 output的精度由两个输入中更高精度的决定。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)
