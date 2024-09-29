# Concat


## 概述

在指定轴上连接张量，将输入张量按给定的轴连接起来。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_CONCAT。

输入：

- 多个维度相同的tensor。

输出：

- output，多个张量按axis轴连接的结果。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long [axis](#axis) | 拼接的轴，axis必须小于输入张量的维度数量。  | 


## 类成员变量说明


### axis

```
long Concat::axis
```
**描述**

拼接的轴，axis必须小于输入张量的维度数量。
