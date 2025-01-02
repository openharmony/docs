# MatMulFusion


## 概述

对输入x1和x2，计算x1和x2的内积。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_MATMUL_FUSION。

输入：

- x1，n维输入tensor，实数或DATA_TYPE_BOOL类型的tensor。

- x2，n维输入tensor，实数或DATA_TYPE_BOOL类型的tensor。

输出：

- output，计算得到内积，当type!=DATA_TYPE_UNKNOWN时，output数据类型由type决定；当type==DATA_TYPE_UNKNOWN时， output的数据类型取决于x1和x2进行计算时转化的数据类型。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| boolean [transposeA](#transposea) | 是否对x1矩阵进行转置。  | 
| boolean [transposeB](#transposeb) | 是否对x2矩阵进行转置。  | 
| enum [ActivationType](_n_n_rt_v20.md#activationtype)[activationType](#activationtype) | 激活函数，详情请参考：[ActivationType](_n_n_rt_v20.md#activationtype)。  | 


## 类成员变量说明


### activationType

```
enum ActivationType MatMulFusion::activationType
```
**描述**

激活函数，详情请参考：[ActivationType](_n_n_rt_v20.md#activationtype)。


### transposeA

```
boolean MatMulFusion::transposeA
```
**描述**

是否对x1矩阵进行转置。


### transposeB

```
boolean MatMulFusion::transposeB
```
**描述**

是否对x2矩阵进行转置。
