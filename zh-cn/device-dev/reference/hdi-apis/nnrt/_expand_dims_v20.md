# ExpandDims

## 概述

在给定轴上为tensor添加一个额外的维度。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_EXPAND_DIMS。

输入：

- x，n维tensor。

- axis，需要添加的维度的index，int32_t类型，值必须在[-dim-1，dim]，且只允许常量值。

输出：

- output，给定轴上添加了额外额度的算子。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)
