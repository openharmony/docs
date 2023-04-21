# OH_NN_Tensor


## Overview

Defines the tensor structure.

It is usually used to construct data nodes and operator parameters in a model graph. When constructing a tensor, you need to specify the data type, number of dimensions, dimension information, and quantization information.

**Since:**
9

**Related Modules:**

[NeuralNeworkRuntime](_neural_nework_runtime.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| [dataType](#datatype) | Data type of the specified tensor. The value must be an enumerated value of [OH_NN_DataType](_neural_nework_runtime.md#oh_nn_datatype).  | 
| [dimensionCount](#dimensioncount) | Number of dimensions of the specified tensor  | 
| [dimensions](#dimensions) | Dimension information (shape) of the specified tensor  | 
| [quantParam](#quantparam) | Quantization information of the specified tensor. The data type must be [OH_NN_QuantParam](_o_h___n_n___quant_param.md).  | 
| [type](#type) | Specifies the tensor type. The value of **type** is related to the tensor usage. When the tensor is used as the input or output of the model, set **type** to [OH_NN_TENSOR](_neural_nework_runtime.md). When a tensor is used as an operator parameter, select any enumerated value except [OH_NN_TENSOR](_neural_nework_runtime.md) from [OH_NN_TensorType](_neural_nework_runtime.md#oh_nn_tensortype).  | 


## Member Variable Description 


### dataType

  
```
OH_NN_DataType OH_NN_Tensor::dataType
```
**Description**<br>
Data type of the specified tensor. The value must be an enumerated value of [OH_NN_DataType](_neural_nework_runtime.md#oh_nn_datatype).


### dimensionCount

  
```
uint32_t OH_NN_Tensor::dimensionCount
```
**Description**<br>
Number of dimensions of the specified tensor


### dimensions

  
```
const int32_t* OH_NN_Tensor::dimensions
```
**Description**<br>
Dimension information (shape) of the specified tensor


### quantParam

  
```
const OH_NN_QuantParam* OH_NN_Tensor::quantParam
```
**Description**<br>
Quantization information of the specified tensor. The data type must be [OH_NN_QuantParam](_o_h___n_n___quant_param.md).


### type

  
```
OH_NN_TensorType OH_NN_Tensor::type
```
**Description**<br>
Specifies the tensor type. The value of **type** is related to the tensor usage. When the tensor is used as the input or output of the model, set **type** to [OH_NN_TENSOR](_neural_nework_runtime.md). When a tensor is used as an operator parameter, select any enumerated value except [OH_NN_TENSOR](_neural_nework_runtime.md) from [OH_NN_TensorType](_neural_nework_runtime.md#oh_nn_tensortype).
