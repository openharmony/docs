# SliceFusion


## 概述

在x各维度，在axes维度中，以begin为起点，截取size长度的切片。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_SLICE_FUSION。

输入：

- x，n维输入tensor。

- begin，一组不小于0的整数，指定axes维度上的起始切分点。

- size，一组不小于1的整数，指定axes维度上切片的长度。假设某一维度i，1&lt;=size[i]&lt;=input.shape[i]-begin[i]。

输出：

- output，切片得到的n维tensor。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long[] [axes](#axes) | 作用的维度。  | 


## 类成员变量说明


### axes

```
long [] SliceFusion::axes
```
**描述**

作用的维度。
