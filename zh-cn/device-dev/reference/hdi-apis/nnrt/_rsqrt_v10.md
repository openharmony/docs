# Rsqrt


## 概述

求x的平方根的倒数。

该算子对应的[NodeType](_n_n_rt_v10.md#nodetype)为NODE_TYPE_RSQRT。

输入：

- x，n维输入tensor，input中的每个元素不能小于0，n&lt;8。

输出：

- output，n维输出tensor，output的shape和数据类型和input相同。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)
