# OH_NN_Tensor


## 概述

张量结构体。

通常用于构造模型图中的数据节点和算子参数，在构造张量时需要明确数据类型、维数、维度信息和量化信息。

**起始版本：** 9

**弃用：** 从API version 11开始，此接口废弃。

**替代：** 推荐使用[NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc)。

**相关模块：**[NeuralNeworkRuntime](_neural_network_runtime.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NN_DataType](_neural_network_runtime.md#oh_nn_datatype)[dataType](#datatype) | 指定张量的数据类型，要求从[OH_NN_DataType](_neural_network_runtime.md#oh_nn_datatype)枚举类型中取值。 | 
| uint32_t [dimensionCount](#dimensioncount) | 指定张量的维数。 | 
| const int32_t \* [dimensions](#dimensions) | 指定张量的维度信息（形状）。 | 
| const [OH_NN_QuantParam](_o_h___n_n___quant_param.md) \* [quantParam](#quantparam) | 指定张量的量化信息，数据类型要求为[OH_NN_QuantParam](_o_h___n_n___quant_param.md)。 | 
| [OH_NN_TensorType](_neural_network_runtime.md#oh_nn_tensortype)[type](#type) | 指定张量的类型。type的取值和张量的用途相关，当张量用作模型的输入或输出，则要求将type设置为[OH_NN_TENSOR](_neural_network_runtime.md)； 当张量用作算子参数，则要求从[OH_NN_TensorType](_neural_network_runtime.md#oh_nn_tensortype)中选择除[OH_NN_TENSOR](_neural_network_runtime.md)以外的枚举值。 | 


## 结构体成员变量说明


### dataType

```
OH_NN_DataType OH_NN_Tensor::dataType
```

**描述**

指定张量的数据类型，要求从[OH_NN_DataType](_neural_network_runtime.md#oh_nn_datatype)枚举类型中取值。


### dimensionCount

```
uint32_t OH_NN_Tensor::dimensionCount
```

**描述**

指定张量的维数。


### dimensions

```
const int32_t* OH_NN_Tensor::dimensions
```

**描述**

指定张量的维度信息（形状）。


### quantParam

```
const OH_NN_QuantParam* OH_NN_Tensor::quantParam
```

**描述**

指定张量的量化信息，数据类型要求为[OH_NN_QuantParam](_o_h___n_n___quant_param.md)。


### type

```
OH_NN_TensorType OH_NN_Tensor::type
```

**描述**

指定张量的类型。type的取值和张量的用途相关，当张量用作模型的输入或输出，则要求将type设置为[OH_NN_TENSOR](_neural_network_runtime.md)； 当张量用作算子参数，则要求从[OH_NN_TensorType](_neural_network_runtime.md#oh_nn_tensortype)中选择除[OH_NN_TENSOR](_neural_network_runtime.md)以外的枚举值。
