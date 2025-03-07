# OneHot


## 概述

根据indices指定的位置，生成一个由one-hot向量构成的tensor。

每个onehot向量中的有效值由on_value决定，其他位置由off_value决定。

该算子对应的[NodeType](_n_n_rt_v10.md#nodetype)为NODE_TYPE_ONE_HOT。

输入：

- indices，n维tensor。indices中每个元素决定每个one-hot向量，on_value的位置。

- depth，一个整型标量，决定one-hot向量的深度。要求depth&gt;0。

- on_value，一个标量，指定one-hot向量中的有效值。

- off_value，一个标量，指定one-hot向量中除有效位以外，其他位置的值。

输出：

- output，如果indices时n维tensor，则output是(n+1)维tensor。output的形状由indices和axis共同决定。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long [axis](#axis) | 一个整型标量，指定插入one-hot的维度。 indices的形状是[N，C]，depth的值是D，当axis=0时，output形状为[D，N，C]， indices的形状是[N，C]，depth的值是D，当axis=-1时，output形状为[N，C，D]， indices的形状是[N，C]，depth的值是D，当axis=1时，output形状为[N，D，C]。  | 


## 类成员变量说明


### axis

```
long OneHot::axis
```
**描述**

一个整型标量，指定插入one-hot的维度。 indices的形状是[N，C]，depth的值是D，当axis=0时，output形状为[D，N，C]， indices的形状是[N，C]，depth的值是D，当axis=-1时，output形状为[N，C，D]， indices的形状是[N，C]，depth的值是D，当axis=1时，output形状为[N，D，C]。
