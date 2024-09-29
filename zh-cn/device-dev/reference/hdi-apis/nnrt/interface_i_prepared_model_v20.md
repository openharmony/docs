# IPreparedModel


## 概述

NNRt模块的包路径。

定义模型编译后的对象，包含编译后模型导出、模型推理接口。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [ExportModelCache](#exportmodelcache) ([out] struct [SharedBuffer](_shared_buffer_v20.md)[] modelCache) | 导出模型缓存。 | 
| [GetInputDimRanges](#getinputdimranges) ([out] unsigned int[][] minInputDims, [out] unsigned int[][] maxInputDims) | 获取模型输入支持的维度范围。如果模型输入为固定维度，则维度最大值与最小值相同。 | 
| [Run](#run) ([in] struct [IOTensor](_i_o_tensor_v20.md)[] inputs, [in] struct [IOTensor](_i_o_tensor_v20.md)[] outputs, [out] int[][] outputsDims) | 推理模型 | 


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
| modelCache | 模型缓存数组，元素顺序与导出时元素顺序一致，SharedBuffer定义请查看[SharedBuffer](_shared_buffer_v20.md)。 | 

**返回：**

返回0表示成功

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）


### GetInputDimRanges()

```
IPreparedModel::GetInputDimRanges ([out] unsigned int minInputDims[][], [out] unsigned int maxInputDims[][] )
```

**描述**


获取模型输入支持的维度范围。如果模型输入为固定维度，则维度最大值与最小值相同。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| minInputDims | 二维数组存放模型输入数据的最小维度值，数组第1维表示模型输入tensor的数量，第2维表示输入tensor的维度数量。 | 
| maxInputDims | 二维数组存放模型输入数据的最大维度值，数组第1维表示模型输入tensor的数量，第2维表示输入tensor的维度数量。 | 

**返回：**

返回0表示成功

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）


### Run()

```
IPreparedModel::Run ([in] struct IOTensor[] inputs, [in] struct IOTensor[] outputs, [out] int outputsDims[][] )
```

**描述**


推理模型

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| inputs | 模型推理的输入数据，输入的顺序与模型中定义的输入顺序一致，输入数据类型参考IOTensor定义[IOTensor](_i_o_tensor_v20.md)。 | 
| outputs | 模型推理的输出数据，推理完后需要往outputs的sharedBuffer中写入输出数据，IOTensor定义请查看[IOTensor](_i_o_tensor_v20.md)。 | 
| outputsDims | 模型推理输出数据的形状，输出顺序与outputs顺序一一对应。 | 
| isOutputBufferEnough | 模型推理输出数据的SharedBuffer空间是否足够，足够的话返回true，不足则返回false，输出顺序与outputs顺序一一对应。 | 

**返回：**

返回0表示成功

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）
