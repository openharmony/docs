# Transpose


## 概述

根据perm对x进行数据重排。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_TRANSPOSE。

输入：

- x，n维tensor，待重排的tensor。

- perm，1维tensor，其长度和x的维数一致。

输出：

- output，n维tensor，output的数据类型，量化等参数与x相同，shape由x的shape和perm共同决定。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)
