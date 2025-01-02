# ReduceFusion


## 概述

减小x张量的维度。

该算子对应的[NodeType](_n_n_rt_v10.md#nodetype)为NODE_TYPE_REDUCE_FUSION。

参数说明：mode若为REDUCE_ALL,REDUCE_PROD和REDUCE_MEAN，则reduce_to_end为true时，Reduce之后的输出乘以coeff为最终输出。

输入：

- x，n维tensor，n&lt;8。

- axis，1维tensor，指定reduce的维度，axis中每个元素的取值范围为[-n，n)。

输出：

- output，执行Reduce之后的m维的tensor，其数据类型和x相同。当keepDims为false时，m&lt;n；当keepDims为true时，m==n。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| boolean [keepDims](#keepdims) | 维度是否保持不变。  | 
| enum [ReduceMode](_n_n_rt_v10.md#reducemode)[mode](#mode) | 减小张量维度的算法，详情请参考：[ReduceMode](_n_n_rt_v10.md#reducemode)。  | 
| boolean [reduceToEnd](#reducetoend) | 如果为true，则从axis取第一个元素并设置为i， 然后axis会被修改为[i,i+1,...,n-1,n]， 例如reduceToEnd=True，axis=[2,4]，x的维度为7，则axis会被修改为[2,3,4,5,6]  | 
| float [coeff](#coeff) | 系数  | 


## 类成员变量说明


### coeff

```
float ReduceFusion::coeff
```
**描述**

系数


### keepDims

```
boolean ReduceFusion::keepDims
```
**描述**

维度是否保持不变。


### mode

```
enum ReduceMode ReduceFusion::mode
```
**描述**

减小张量维度的算法，详情请参考：[ReduceMode](_n_n_rt_v10.md#reducemode)。


### reduceToEnd

```
boolean ReduceFusion::reduceToEnd
```
**描述**

如果为true，则从axis取第一个元素并设置为i， 然后axis会被修改为[i,i+1,...,n-1,n]， 例如reduceToEnd=True，axis=[2,4]，x的维度为7，则axis会被修改为[2,3,4,5,6]
