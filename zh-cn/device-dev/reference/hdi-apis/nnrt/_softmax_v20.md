# Softmax

## 概述

给定一个tensor，计算其softmax结果。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_SOFTMAX。

输入：

- x，n维tensor。

输出：

- output，softmax的计算结果，一个n维tensor，类型和shape和x一致。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)

## 汇总

### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long[] [axis](#axis) | 指定计算softmax的维度。整数取值范围为[-n，n)。  | 

## 类成员变量说明

### axis

```
long [] Softmax::axis
```
**描述**

指定计算softmax的维度。整数取值范围为[-n，n)。
