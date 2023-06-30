# LayerNormFusion


## 概述

对一个tensor从某一axis开始做层归一化。

该算子对应的[NodeType](_n_n_rt.md#nodetype)为NODE_TYPE_LAYER_NORM_FUSION。

输入：

- x，n维tensor。

- gamma，一个m维tensor，gamma维度应该与input做归一化部分的shape一致。

- beta，一个m维tensor，shape与gamma一样。

输出：

- output，n维输出tensor，数据类型和shape和input一致。

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
| [beginNormAxis](#beginnormaxis) | long<br/>指定x需进行层归一化的起始维度。&nbsp; | 
| [epsilon](#epsilon) | float<br/>为数值稳定性定义一个加到分母上的值。&nbsp; | 
| [elementwiseAffine](#elementwiseaffine) | boolean<br/>是否为元素级别的操作。&nbsp; | 
| [beginParamsAxis](#beginparamsaxis) | long<br/>指定输入参数gamma，beta需进行层归一化的开始维度，其值必须在[-n,&nbsp;n)范围内。&nbsp; | 


## 类成员变量说明


### beginNormAxis

  
```
long LayerNormFusion::beginNormAxis
```
**描述:**
指定x需进行层归一化的起始维度。


### beginParamsAxis

  
```
long LayerNormFusion::beginParamsAxis
```
**描述:**
指定输入参数gamma，beta需进行层归一化的开始维度，其值必须在[-n, n)范围内。


### elementwiseAffine

  
```
boolean LayerNormFusion::elementwiseAffine
```
**描述:**
是否为元素级别的操作。


### epsilon

  
```
float LayerNormFusion::epsilon
```
**描述:**
为数值稳定性定义一个加到分母上的值。
