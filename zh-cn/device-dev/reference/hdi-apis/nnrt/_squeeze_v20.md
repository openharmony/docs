# Squeeze

## 概述

去除axis中，长度为1的维度。支持int8量化输入。

假设输入的x的shape为[2，1，1，2，2]，axis为[0,1]，则输出的output的shape为[2，1，2，2]，意思是第0维到第1维之间，长度为1的维度被去除。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_SQUARED_DIFFERENCE。

输入：

- x，n维tensor。

输出：

- output，去除axis中长度为1的维度之后得到的tensor。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)

## 汇总

### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long[] [axis](#axis) | 指定删除的维度。axis可以是一个整数或数组，整数的取值范围为[-n，n)。  | 

## 类成员变量说明

### axis

```
long [] Squeeze::axis
```
**描述**

指定删除的维度。axis可以是一个整数或数组，整数的取值范围为[-n，n)。
