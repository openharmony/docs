# OH_NN_Tensor


## Overview

Defines the tensor structure.

It is usually used to construct data nodes and operator parameters in a model diagram. When constructing a tensor, you need to specify the data type, number of dimensions, dimension information, and quantization information.

**Since**: 9

**Deprecated**: This module is deprecated since API version 11.

**Substitute**: You are advised to use [NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc).

**Related module**: [NeuralNetworkRuntime](_neural_network_runtime.md)

**Header file**: [neural_network_runtime_type.h](neural__network__runtime__type_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [OH_NN_DataType](_neural_network_runtime.md#oh_nn_datatype) [dataType](#datatype) | Data type of the specified tensor. The value must be of the [OH_NN_DataType](_neural_network_runtime.md#oh_nn_datatype) type.| 
| uint32_t [dimensionCount](#dimensioncount) | Number of dimensions of the specified tensor.| 
| const int32_t \* [dimensions](#dimensions) | Dimension information (shape) of the specified tensor.| 
| const [OH_NN_QuantParam](_o_h___n_n___quant_param.md) \* [quantParam](#quantparam) | Quantization information of the specified tensor. The data type must be [OH_NN_QuantParam](_o_h___n_n___quant_param.md).| 
| [OH_NN_TensorType](_neural_network_runtime.md#oh_nn_tensortype) [type](#type) | Type of the specified tensor. The value is related to the tensor usage. If the tensor is used as the input or output of the model, set **type** to [OH_NN_TENSOR](_neural_network_runtime.md). If the tensor is used as an operator parameter, select an enum value other than [OH_NN_TENSOR](_neural_network_runtime.md) from [OH_NN_TensorType](_neural_network_runtime.md#oh_nn_tensortype).| 


## Member Variable Description


### dataType

```
OH_NN_DataType OH_NN_Tensor::dataType
```

**Description**

Data type of the specified tensor. The value must be of the [OH_NN_DataType](_neural_network_runtime.md#oh_nn_datatype) type.


### dimensionCount

```
uint32_t OH_NN_Tensor::dimensionCount
```

**Description**

Number of dimensions of the specified tensor.


### dimensions

```
const int32_t* OH_NN_Tensor::dimensions
```

**Description**

Dimension information (shape) of the specified tensor.


### quantParam

```
const OH_NN_QuantParam* OH_NN_Tensor::quantParam
```

**Description**

Quantization information of the specified tensor. The data type must be [OH_NN_QuantParam](_o_h___n_n___quant_param.md).


### type

```
OH_NN_TensorType OH_NN_Tensor::type
```

**Description**

Type of the specified tensor. The value is related to the tensor usage. If the tensor is used as the input or output of the model, set **type** to [OH_NN_TENSOR](_neural_network_runtime.md). If the tensor is used as an operator parameter, select an enum value other than [OH_NN_TENSOR](_neural_network_runtime.md) from [OH_NN_TensorType](_neural_network_runtime.md#oh_nn_tensortype).
