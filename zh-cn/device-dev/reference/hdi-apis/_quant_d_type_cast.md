# QuantDTypeCast


## 概述

数据类型转换。

该算子对应的[NodeType](_n_n_rt.md#nodetype)为NODE_TYPE_QUANT_DTYPE_CAST。

输入：

- x，n维tensor。

输出：

- output，类型转换之后的tensor。

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
| [srcT](#srct) | long<br/>定义输入的数据类型。&nbsp; | 
| [dstT](#dstt) | long<br/>定义输出的数据类型。&nbsp; | 


## 类成员变量说明


### dstT

  
```
long QuantDTypeCast::dstT
```
**描述:**

定义输出的数据类型。


### srcT

  
```
long QuantDTypeCast::srcT
```
**描述:**

定义输入的数据类型。
