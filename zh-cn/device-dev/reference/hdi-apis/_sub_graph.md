# SubGraph


## 概述

子图结构体。

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
| [name](#name) | String<br/>子图的名称。&nbsp; | 
| [inputIndices](#inputindices) | unsigned&nbsp;int[]<br/>子图的输入子图在[Model](_model.md)的subGraph数组中的下标。&nbsp; | 
| [outputIndices](#outputindices) | unsigned&nbsp;int[]<br/>子图的输出子图在[Model](_model.md)的subGraph数组中的下标。&nbsp; | 
| [nodeIndices](#nodeindices) | unsigned&nbsp;int[]<br/>子图包含的算子节点在[Model](_model.md)的nodes数组中的下标。&nbsp; | 


## 类成员变量说明


### inputIndices

  
```
unsigned int [] SubGraph::inputIndices
```
**描述:**
子图的输入子图在[Model](_model.md)的subGraph数组中的下标。


### name

  
```
String SubGraph::name
```
**描述:**
子图的名称。


### nodeIndices

  
```
unsigned int [] SubGraph::nodeIndices
```
**描述:**
子图包含的算子节点在[Model](_model.md)的nodes数组中的下标。


### outputIndices

  
```
unsigned int [] SubGraph::outputIndices
```
**描述:**
子图的输出子图在[Model](_model.md)的subGraph数组中的下标。
