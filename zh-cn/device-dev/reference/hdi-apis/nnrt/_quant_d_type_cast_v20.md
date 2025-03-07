# QuantDTypeCast


## 概述

数据类型转换。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_QUANT_DTYPE_CAST。

输入：

- x，n维tensor。

输出：

- output，类型转换之后的tensor。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long [srcT](#srct) | 定义输入的数据类型。  | 
| long [dstT](#dstt) | 定义输出的数据类型。  | 


## 类成员变量说明


### dstT

```
long QuantDTypeCast::dstT
```
**描述**

定义输出的数据类型。


### srcT

```
long QuantDTypeCast::srcT
```
**描述**

定义输入的数据类型。
