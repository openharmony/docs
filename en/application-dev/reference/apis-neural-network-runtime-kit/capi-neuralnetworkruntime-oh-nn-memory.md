# OH_NN_Memory
<!--Kit_Neural Network Runtime Kit--><!--System_AI-->

## Overview

Defines the memory structure.

**Since**: 9

**Deprecated from**: 11

**Substitute**: [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md)

**Related module**: [NeuralNetworkRuntime](capi-neuralnetworkruntime.md)

**Header file**: [neural_network_runtime_type.h](capi-neural-network-runtime-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| void * const data | Pointer to the shared memory. The shared memory is usually applied for by the underlying hardware driver.|
| const size_t length | Length of the shared memory, in bytes.|
