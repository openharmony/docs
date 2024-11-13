# AddFusion


## 概述

输入Tensor逐元素相加， 输出x和y的和，数据形状与输入broadcast之后一样，数据类型与较高精度的输入精度一致。

该算子对应的[NodeType](_n_n_rt_v10.md#nodetype)为NODE_TYPE_ADD_FUSION。

输入：

- x，第一个输入张量。

- y，第二个输入张量，数据类型和第一个张量保持一致。

输出：

- output，x和y逐元素相加， 输出x和y的和，数据形状与输入broadcast之后一样，数据类型与较高精度的输入精度一致。 如果配置了activationType则会在输出之前调用指定的激活函数。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| enum [ActivationType](_n_n_rt_v10.md#activationtype)[activationType](#activationtype) | 激活函数类型。详情请参考：[ActivationType](_n_n_rt_v10.md#activationtype) | 


## 类成员变量说明


### activationType

```
enum ActivationType AddFusion::activationType
```

**描述**


激活函数类型。详情请参考：[ActivationType](_n_n_rt_v10.md#activationtype)
