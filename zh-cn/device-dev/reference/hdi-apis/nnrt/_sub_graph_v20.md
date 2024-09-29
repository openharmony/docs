# SubGraph


## 概述

子图结构体。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| String [name](#name) | 子图的名称。  | 
| unsigned int[] [inputIndices](#inputindices) | 子图的输入子图在[Model](_model_v20.md)的subGraph数组中的下标。  | 
| unsigned int[] [outputIndices](#outputindices) | 子图的输出子图在[Model](_model_v20.md)的subGraph数组中的下标。  | 
| unsigned int[] [nodeIndices](#nodeindices) | 子图包含的算子节点在[Model](_model_v20.md)的nodes数组中的下标。  | 


## 类成员变量说明


### inputIndices

```
unsigned int [] SubGraph::inputIndices
```
**描述**

子图的输入子图在[Model](_model_v20.md)的subGraph数组中的下标。


### name

```
String SubGraph::name
```
**描述**

子图的名称。


### nodeIndices

```
unsigned int [] SubGraph::nodeIndices
```
**描述**

子图包含的算子节点在[Model](_model_v20.md)的nodes数组中的下标。


### outputIndices

```
unsigned int [] SubGraph::outputIndices
```
**描述**

子图的输出子图在[Model](_model_v20.md)的subGraph数组中的下标。
