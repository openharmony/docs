# OH_NN_Tensor
<!--Kit: Neural Network Runtime Kit-->
<!--Subsystem: AI-->
<!--Owner: @GbuzhidaoR-->
<!--Designer: @GbuzhidaoR-->
<!--Tester: @GbuzhidaoR-->
<!--Adviser: @ge-yafang-->

## Overview

Defines the tensor structure.

It is usually used to construct data nodes and operator parameters in a model diagram. When constructing a tensor, you need to specify the data type, number of dimensions, dimension information, and quantization information.

**Since**: 9

**Deprecated from**: 11

**Substitute**: [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md)

**Related module**: [NeuralNetworkRuntime](capi-neuralnetworkruntime.md)

**Header file**: [neural_network_runtime_type.h](capi-neural-network-runtime-type-h.md)

## Summary

### Member Variables

| Name                                                                                 | Description|
|-------------------------------------------------------------------------------------| -- |
| [OH_NN_DataType](capi-neural-network-runtime-type-h.md#oh_nn_datatype) dataType     | Data type of the specified tensor. The value must be an enum of [OH_NN_DataType](capi-neural-network-runtime-type-h.md#oh_nn_datatype).|
| uint32_t dimensionCount                                                             | Number of dimensions of the specified tensor.|
| const int32_t *dimensions                                                           | Dimension information (shape) of the specified tensor.|
| const [OH_NN_QuantParam](capi-neuralnetworkruntime-oh-nn-quantparam.md) *quantParam | Quantization information of the specified tensor. The value must be an enum of [OH_NN_QuantParam](capi-neuralnetworkruntime-oh-nn-quantparam.md).|
| [OH_NN_TensorType](capi-neural-network-runtime-type-h.md#oh_nn_tensortype) type     | Type of the specified tensor. The value is related to the tensor usage. If the tensor is used as the input or output of the model, set type to [OH_NN_TENSOR](capi-neural-network-runtime-type-h.md#oh_nn_tensortype). If the tensor is used as an operator parameter, select an enum value other than [OH_NN_TENSOR](capi-neural-network-runtime-type-h.md#oh_nn_tensortype) from [OH_NN_TensorType](capi-neural-network-runtime-type-h.md#oh_nn_tensortype).|
