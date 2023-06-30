# FullConnection


## 概述

对输入数据做全连接。

该算子对应的[NodeType](_n_n_rt.md#nodetype)为NODE_TYPE_FULL_CONNECTION。

参数限制：useAxis为true的时候axis必须设置，useAxis为false的时候axis为0。

输入：

- x，n维tensor

- weight，全连接的权重张量。

- bias，全连接的偏置，在量化场景下不需要量化参数，其量化版本要求输入 int32 类型数据，实际量化参数由 x 和 weight 共同决定。

输出：

- output，输出运算后的张量。

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
| [hasBias](#hasbias) | boolean<br/>是否使用bias。 | 
| [useAxis](#useaxis) | boolean<br/>是否使用轴。 | 
| [axis](#axis) | long<br/>指定输入张量做全连接的轴，从指定轴axis开始，将axis和axis之后的轴展开成1维张量之后再做全连接。 | 
| [activationType](#activationtype) | enum&nbsp;[ActivationType](_n_n_rt.md#activationtype)<br/>激活函数类型，详情请参考：[ActivationType](_n_n_rt.md#activationtype)。 | 


## 类成员变量说明


### activationType

  
```
enum ActivationType FullConnection::activationType
```

**描述:**

激活函数类型，详情请参考：[ActivationType](_n_n_rt.md#activationtype)。


### axis

  
```
long FullConnection::axis
```

**描述:**

指定输入张量做全连接的轴，从指定轴axis开始，将axis和axis之后的轴展开成1维张量之后再做全连接。


### hasBias

  
```
boolean FullConnection::hasBias
```

**描述:**

是否使用bias。


### useAxis

  
```
boolean FullConnection::useAxis
```

**描述:**

是否使用轴。
