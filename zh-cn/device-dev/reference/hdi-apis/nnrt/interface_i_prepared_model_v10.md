# IPreparedModel


## 概述

定义模型编译后的对象，包含编译后模型导出、模型推理接口。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [ExportModelCache](#exportmodelcache) ([out] struct [SharedBuffer](_shared_buffer_v10.md)[] modelCache) | 导出模型缓存。  | 
| [Run](#run) ([in] struct [IOTensor](_i_o_tensor_v10.md)[] inputs, [in] struct [IOTensor](_i_o_tensor_v10.md)[] outputs, [out] int[][] outputsDims, [out] boolean[] isOutputBufferEnough) | 推理模型  | 


## 成员函数说明


### ExportModelCache()

```
IPreparedModel::ExportModelCache ([out] struct SharedBuffer[] modelCache)
```
**描述**

导出模型缓存。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| modelCache | 模型缓存数组，元素顺序与导出时元素顺序一致，SharedBuffer定义请查看[SharedBuffer](_shared_buffer_v10.md)。 | 

**返回：**

返回0表示成功

返回负数表示失败


### Run()

```
IPreparedModel::Run ([in] struct IOTensor[] inputs, [in] struct IOTensor[] outputs, [out] int outputsDims[][], [out] boolean[] isOutputBufferEnough )
```
**描述**

推理模型

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| inputs | 模型推理的输入数据，输入的顺序与模型中定义的输入顺序一致，输入数据类型参考IOTensor定义[IOTensor](_i_o_tensor_v10.md)。  | 
| outputs | 模型推理的输出数据，推理完后需要往outputs的sharedBuffer中写入输出数据，IOTensor定义请查看[IOTensor](_i_o_tensor_v10.md)。  | 
| outputsDims | 模型推理输出数据的形状，输出顺序与outputs顺序一一对应。  | 
| isOutputBufferEnough | 模型推理输出数据的SharedBuffer空间是否足够，足够的话返回true，不足则返回false，输出顺序与outputs顺序一一对应。 | 

**返回：**

返回0表示成功

返回负数表示失败
