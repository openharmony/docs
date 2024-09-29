# BatchToSpaceND


## 概述

将一个4维tensor的batch维度按block_shape切分成小块，并将这些小块拼接到空间维度。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_BATCH_TO_SPACE_ND。

输入：

- x，n维tensor。

输出：

- 输出张量，假设x的形状为(n,h,w,c)，output的形状为（n',h',w',c'）：

  - $ n' = n / (block_shape[0] \* block_shape[1]) $
  - $ h' = h \* block_shape[0] - crops[0][0] - crops[0][1] $
  - $ w' = w \* block_shape[1] - crops[1][0] - crops[1][1] $
  - $ c'= c $

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long[] [blockShape](#blockshape) | 一个长度为2的数组[height_block，weight_block]，指定切分到空间维度上的block大小。 | 
| long[][] [crops](#crops) | 一个shape为(2，2)的2维数组[[crop0_start，crop0_end]，[crop1_start，crop1_end]]， 表示在output的空间维度上截掉部分元素。 | 


## 类成员变量说明


### blockShape

```
long [] BatchToSpaceND::blockShape
```

**描述**


一个长度为2的数组[height_block，weight_block]，指定切分到空间维度上的block大小。


### crops

```
long [][] BatchToSpaceND::crops
```

**描述**


一个shape为(2，2)的2维数组[[crop0_start，crop0_end]，[crop1_start，crop1_end]]， 表示在output的空间维度上截掉部分元素。
