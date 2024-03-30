# Maximum


## 概述

对输入x1和x2，计算x1和x2对应元素最大值，x1和x2的输入遵守隐式类型转换规则，使数据类型一致。

输入必须是两个张量或一个张量和一个标量。当输入是两个张量时，它们的数据类型不能同时为DATA_TYPE_BOOL。它们的形状支持 broadcast成相同的大小。当输入是一个张量和一个标量时，标量只能是一个常数。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_MAXIMUM。

输入：

- x1，n维输入tensor，实数或DATA_TYPE_BOOL类型。

- x2，n维输入tensor，实数或DATA_TYPE_BOOL类型。

输出：

- output，x1和x2两个tensor对应元素的最大值。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)
