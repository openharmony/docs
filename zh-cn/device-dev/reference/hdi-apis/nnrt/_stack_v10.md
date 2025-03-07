# Stack


## 概述

将一组tensor沿axis维度进行堆叠，堆叠前每个tensor的维数为n，则堆叠后output维数为n+1。

该算子对应的[NodeType](_n_n_rt_v10.md#nodetype)为NODE_TYPE_STACK。

输入：

- 多个输入n维tensor，每个tensor要求shape相同且类型相同。

输出：

- output，将输入的张量沿axis维度堆叠的输出，n+1维tensor，数据类型与精度和输入相同。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long [axis](#axis) | 一个整数，指定tensor堆叠的维度。axis可以是负数，axis取值范围为[-(n+1)，(n+1))。  | 


## 类成员变量说明


### axis

```
long Stack::axis
```
**描述**

一个整数，指定tensor堆叠的维度。axis可以是负数，axis取值范围为[-(n+1)，(n+1))。
