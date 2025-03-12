# ArgMaxFusion

## 概述

返回跨轴的tensor前K个索引或者是数值。

该算子对应的[NodeType](_n_n_rt_v20.md#nodetype)为NODE_TYPE_ARGMAX_FUSION。

输入：

- x，n维tensor，输入张量（N,\*），其中\*意味着数量任意的附加维度。

输出：

- output，轴上输入张量最大值的前K个索引或者是数值。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)

## 汇总

### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long [axis](#axis) | 指定求最大值索引的维度。  | 
| long [topK](#topk) | 轴上前K个最大值。  | 
| boolean [keepDims](#keepdims) | 是否保持输出维度和输入的维度是否相同。  | 
| boolean [outMaxValue](#outmaxvalue) | 若为false则输出索引，为true则输出数值，默认为false。  | 

## 类成员变量说明

### axis

```
long ArgMaxFusion::axis
```
**描述**

指定求最大值索引的维度。

### keepDims

```
boolean ArgMaxFusion::keepDims
```
**描述**

是否保持输出维度和输入的维度是否相同。

### outMaxValue

```
boolean ArgMaxFusion::outMaxValue
```
**描述**

若为false则输出索引，为true则输出数值，默认为false。

### topK

```
long ArgMaxFusion::topK
```
**描述**

轴上前K个最大值。
