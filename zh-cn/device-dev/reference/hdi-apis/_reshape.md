# Reshape


## 概述

根据inputShape调整input的形状。

该算子对应的[NodeType](_n_n_rt.md#nodetype)为NODE_TYPE_RESHAPE。

输入：

- x，一个n维输入tensor。

- InputShape，一个1维tensor，表示输出tensor的shape，需要是一个常量tensor。

输出：

- output，数据类型和input一致，shape由inputShape决定。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[NNRt](_n_n_rt.md)
