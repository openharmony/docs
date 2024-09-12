# Gather


## 概述

根据指定的索引和轴返回输入tensor的切片。

该算子对应的[NodeType](_n_n_rt_v10.md#nodetype)为NODE_TYPE_GATHER。

输入：

- x，n维tensor。

- inputIndices，指定输入x在axis上的索引，是一个int类型的数组，值必须在[0,x.shape[axis])范围内。

- axis，指定x被切片的轴，int32_t类型的数组，数组长度为1。

输出：

- output，输出切片后的tensor。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)
