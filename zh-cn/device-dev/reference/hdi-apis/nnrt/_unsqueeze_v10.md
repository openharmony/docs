# Unsqueeze


## 概述

根据输入axis的值。增加一个维度。

该算子对应的[NodeType](_n_n_rt_v10.md#nodetype)为NODE_TYPE_UNSQUEEZE。

输入：

- x，n维tensor。

输出：

- output，输出tensor。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long[] [axis](#axis) | axis，指定增加的维度。axis可以是一个整数或一组整数，整数的取值范围为[-n，n)。  | 


## 类成员变量说明


### axis

```
long [] Unsqueeze::axis
```
**描述**

axis，指定增加的维度。axis可以是一个整数或一组整数，整数的取值范围为[-n，n)。
