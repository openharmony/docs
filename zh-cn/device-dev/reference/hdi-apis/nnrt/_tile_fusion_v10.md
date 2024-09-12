# TileFusion


## 概述

以multiples指定的次数拷贝输入张量。

该算子对应的[NodeType](_n_n_rt_v10.md#nodetype)为NODE_TYPE_TILE_FUSION。

输入：

- x，n维tensor。

- multiples， 1维tensor，指定各个维度拷贝的次数。其长度m不小于x的维数n。

输出：

- Tensor，m维tensor，OperandType与input相同。如果input和multiples长度相同， 则output和input维数一致，都是n维tensor；如果multiples长度大于n，则用1填充input的维度， 再在各个维度上拷贝相应的次数，得到m维tensor。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long[] [dims](#dims) | 它和multiples功能相同，1维tensor，指定各个维度拷贝的次数。其长度m不小于x的维数n。  | 


## 类成员变量说明


### dims

```
long [] TileFusion::dims
```
**描述**

它和multiples功能相同，1维tensor，指定各个维度拷贝的次数。其长度m不小于x的维数n。
