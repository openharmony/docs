# Softmax


## 概述

给定一个tensor，计算其softmax结果。

该算子对应的[NodeType](_n_n_rt.md#nodetype)为NODE_TYPE_SOFTMAX。

输入：

- x，n维tensor

输出：

- output，softmax的计算结果，一个n维tensor，类型和shape和x一致。

**Since:**

3.2

**Version:**

1.0

**相关模块:**

[NNRt](_n_n_rt.md)


## 汇总


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [axis](#axis) | long[]<br/>指定计算softmax的维度。整数取值范围为[-n，n)。&nbsp; | 


## 类成员变量说明


### axis

  
```
long [] Softmax::axis
```
**描述:**

指定计算softmax的维度。整数取值范围为[-n，n)。
