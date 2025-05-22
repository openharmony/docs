# Model


## 概述

模型结构体。

该结构体中存储了模型推理时所有的信息，每一个Model的第0个子图都是主子图，一般情况下一个Model仅有一个subGraph（其他情况目前暂不支持）。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| String [name](#name) | 模型名称。  | 
| unsigned int[] [inputIndex](#inputindex) | 模型的输入张量在allTensors数组中的下标。  | 
| unsigned int[] [outputIndex](#outputindex) | 模型的输出张量在allTensors数组中的下标。  | 
| struct [Node](_node_v10.md)[] [nodes](#nodes) | 模型中所有的算子节点组成的数组，详情请参考：[Node](_node_v10.md)。  | 
| struct [Tensor](_tensor_v10.md)[] [allTensors](#alltensors) | 模型中所有的张量组成的数组，该数组中包括输入张量，输出张量和常量张量，详情请参考：[Tensor](_tensor_v10.md)。  | 
| struct [SubGraph](_sub_graph_v10.md)[] [subGraph](#subgraph) | 模型中所有的子图组成的数组，详情请参考：[SubGraph](_sub_graph_v10.md)。  | 


## 类成员变量说明


### allTensors

```
struct Tensor [] Model::allTensors
```
**描述**

模型中所有的张量组成的数组，该数组中包括输入张量，输出张量和常量张量，详情请参考：[Tensor](_tensor_v10.md)。


### inputIndex

```
unsigned int [] Model::inputIndex
```
**描述**

模型的输入张量在allTensors数组中的下标。


### name

```
String Model::name
```
**描述**

模型名称。


### nodes

```
struct Node [] Model::nodes
```
**描述**

模型中所有的算子节点组成的数组，详情请参考：[Node](_node_v10.md)。


### outputIndex

```
unsigned int [] Model::outputIndex
```
**描述**

模型的输出张量在allTensors数组中的下标。


### subGraph

```
struct SubGraph [] Model::subGraph
```
**描述**

模型中所有的子图组成的数组，详情请参考：[SubGraph](_sub_graph_v10.md)。
