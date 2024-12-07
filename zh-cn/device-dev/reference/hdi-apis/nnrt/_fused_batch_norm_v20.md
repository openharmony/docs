# FusedBatchNorm


## 概述

对一个tensor进行批标准化的运算。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_FUSED_BATCH_NORM。

输入：

- x，n维tensor，要求形状为[N，...，C]，即第n维是通道数（channel）。

- scale，缩放因子的1D张量，用于缩放归一化的第一个张量。

- offset，用于偏移的1D张量，以移动到归一化的第一个张量。

- mean，总体均值的一维张量，仅用于推理；对于训练，必须为空。

- variance，用于总体方差的一维张量。仅用于推理；对于训练，必须为空。

输出：

- output，输出运算后的张量。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| float [epsilon](#epsilon) | 趋于零的极小值，用于保证除数不为0。  | 


## 类成员变量说明


### epsilon

```
float FusedBatchNorm::epsilon
```
**描述**

趋于零的极小值，用于保证除数不为0。
