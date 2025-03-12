# SpaceToBatchND

## 概述

将4维张量在空间维度上进行切分成多个小块，然后在batch维度上拼接这些小块。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_SPACE_TO_BATCH_ND。

输入：

- x，n维tensor。

输出：

- output，一个4维tensor，数据类型和input一致。shape由input，blockShape和paddings共同决定，假设input shape为[n,c,h,w]，则有：

  \( output.shape[0] = n \* blockShape[0] \* blockShape[1]\)

  \( output.shape[1] = c \)

  \( output.shape[2] = (h + paddings[0][0] + paddings[0][1]) / blockShape[0] \)

  \( output.shape[3] = (w + paddings[1][0] + paddings[1][1]) / blockShape[1] \)

  要求 \( (h + paddings[0][0] + paddings[0][1])能被\) blockShape[0] \(整除，(w + paddings[1][0] + paddings[1][1]) \)能被 \( blockShape[1] \)整除。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)

## 汇总

### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long[] [blockShape](#blockshape) | 描述空间维度为分割的个数，取值需大于1。 | 
| long[][] [paddings](#paddings) | 空间维度的填充大小。 | 

## 类成员变量说明

### blockShape

```
long [] SpaceToBatchND::blockShape
```

**描述**

描述空间维度为分割的个数，取值需大于1。

### paddings

```
long [][] SpaceToBatchND::paddings
```

**描述**

空间维度的填充大小。
