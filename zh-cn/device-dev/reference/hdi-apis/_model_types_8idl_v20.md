# ModelTypes.idl


## 概述

该文件定义AI模型相关的结构体。

在**PrepareModel**阶段，需要解析Model并将其转换为用于推理的模型结构，在**Run**阶段则会执行模型推理。大致流程如下：

1. 编写[NodeAttrTypes.idl](_node_attr_types_8idl_v20.md)文件中每一个算子的函数，并将函数与[NodeType](_n_n_rt_v20.md#nodetype)进行关联；

2. 遍历[Model](_model_v20.md)的subGraph参数，然后从子图的nodeIndecies中获得该子图包含的算子节点以及算子的输入输出张量和整个[Model](_model_v20.md)的输入输出张量。

3. 通过[Node](_node_v20.md)的nodeType参数找到算子函数，并构建用于运行时的模型结构。

4. 执行模型推理时，通过用户输入张量传递给模型并执行模型推理，最终输出模型推理的结果。

模块包路径：ohos.hdi.nnrt.v2_0

引用：ohos.hdi.nnrt.v2_0.NnrtTypes

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[Tensor](_tensor_v20.md) | 张量结构体。  | 
| struct&nbsp;&nbsp;[Node](_node_v20.md) | 算子节点结构体。  | 
| struct&nbsp;&nbsp;[SubGraph](_sub_graph_v20.md) | 子图结构体。  | 
| struct&nbsp;&nbsp;[Model](_model_v20.md) | 模型结构体。  | 
