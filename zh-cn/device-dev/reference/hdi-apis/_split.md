# Split


## 概述

算子沿 axis 维度将x拆分成多个张量，张量数量由outputNum指定。

该算子对应的[NodeType](_n_n_rt.md#nodetype)为NODE_TYPE_SPLIT。

输入：

- x，n维tensor

输出：

- outputs，一组n维张量，每一个张量类型和维度相同，每个张量的类型和x一致。

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
| [outputNum](#outputnum) | long<br/>指定分割数量。 | 
| [sizeSplits](#sizesplits) | long[]<br/>指定输入的张量沿axis轴拆分后，每个张量的大小。 | 
| [axis](#axis) | long<br/>指定分割的维度。 | 


## 类成员变量说明


### axis

  
```
long Split::axis
```

**描述:**

指定分割的维度。


### outputNum

  
```
long Split::outputNum
```

**描述:**

指定分割数量。


### sizeSplits

  
```
long [] Split::sizeSplits
```

**描述:**

指定输入的张量沿 axis 轴拆分后，每个张量的大小。

如果 sizeSplits 的数据为空，则 sizeSplits 被拆分成大小均等的 张量，此时要求 x.shape[axis] 可以被 outputNum 整除；如果 sizeSplits 不为空，则要求 sizeSplits 所有元素之和等于 x.shape[axis]。
