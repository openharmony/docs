# TopKFusion


## 概述

查找沿axis轴的前K个最大值和对应索引。

该算子对应的[NodeType](_n_n_rt_v10.md#nodetype)为NODE_TYPE_TOPK_FUSION。

输入：

- x，n维tensor。

输出：

- output0，axis维度的前K个最大值。

- output1，axis维度的前K个最大值的索引。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| boolean [sorted](#sorted) | 如果为True，按照大到小排序，如果为False，按照小到大排序。  | 
| long [axis](#axis) | 作用的轴。  | 


## 类成员变量说明


### axis

```
long TopKFusion::axis
```
**描述**

作用的轴。


### sorted

```
boolean TopKFusion::sorted
```
**描述**

如果为True，按照大到小排序，如果为False，按照小到大排序。
