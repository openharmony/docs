# Unsqueeze


## 概述

根据输入axis的值。增加一个维度。

该算子对应的[NodeType](_n_n_rt.md#nodetype)为NODE_TYPE_UNSQUEEZE。

输入：

- x，n维tensor。

输出：

- output，输出tensor。

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
| [axis](#axis) | long[]<br/>axis，指定增加的维度。axis可以是一个整数或一组整数，整数的取值范围为[-n，n)。&nbsp; | 


## 类成员变量说明


### axis

  
```
long [] Unsqueeze::axis
```
**描述:**

axis，指定增加的维度。axis可以是一个整数或一组整数，整数的取值范围为[-n，n)。
