# FullConnection

## 概述

对输入数据做全连接。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_FULL_CONNECTION。

参数限制：useAxis为true的时候axis必须设置，useAxis为false的时候axis为0。

输入：

- x，n维tensor。

- weight，全连接的权重张量。

- bias，全连接的偏置，在量化场景下不需要量化参数，其量化版本要求输入int32类型数据，实际量化参数由x和weight共同决定。

输出：

- output，输出运算后的张量。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)

## 汇总

### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| boolean [hasBias](#hasbias) | hasBias为true使用bias，反之不使用。 | 
| boolean [useAxis](#useaxis) | useAxis为true使用轴，反之不使用。 | 
| long [axis](#axis) | 指定输入张量做全连接的轴，从指定轴axis开始，将axis和axis之后的轴展开成1维张量之后再做全连接。 | 
| enum [ActivationType](_n_n_rt_v20.md#activationtype)[activationType](#activationtype) | 激活函数类型，详情请参考：[ActivationType](_n_n_rt_v20.md#activationtype)。 | 

## 类成员变量说明

### activationType

```
enum ActivationType FullConnection::activationType
```

**描述**

激活函数类型，详情请参考：[ActivationType](_n_n_rt_v20.md#activationtype)。

### axis

```
long FullConnection::axis
```

**描述**

指定输入张量做全连接的轴，从指定轴axis开始，将axis和axis之后的轴展开成1维张量之后再做全连接。

### hasBias

```
boolean FullConnection::hasBias
```

**描述**

是否使用bias。

### useAxis

```
boolean FullConnection::useAxis
```

**描述**

是否使用轴。
