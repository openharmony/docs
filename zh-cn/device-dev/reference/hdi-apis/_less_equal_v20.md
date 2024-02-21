# LessEqual


## 概述

对输入x1和x2，计算每对元素的x1&lt;=x2的结果。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_LESS_EQUAL。

输入：

- x1，可以是实数、布尔值或数据类型是实数或者布尔类型的tensor。

- x2，如果x1是tensor，x2可以是实数、布尔值，否则只能是tensor，其数据类型是实数或DATA_TYPE_BOOL。

输出：

- output，数据类型为DATA_TYPE_BOOL的tensor；使用量化模型时，output的量化参数不可省略，但量化参数的数值不会对输入结果产生影响。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)
