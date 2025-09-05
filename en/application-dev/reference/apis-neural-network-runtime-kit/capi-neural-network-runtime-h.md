# neural_network_runtime.h
<!--Kit: Neural Network Runtime Kit-->
<!--Subsystem: AI-->
<!--Owner: @GbuzhidaoR-->
<!--Designer: @GbuzhidaoR-->
<!--Tester: @GbuzhidaoR-->
<!--Adviser: @ge-yafang-->

## Overview

Defines APIs for Neural Network Runtime. The AI inference framework uses the native APIs provided by the Neural Network Runtime to construct and build models.

Currently, the APIs of Neural Network Runtime do not support multi-thread calling.

**File to include**: <neural_network_runtime/neural_network_runtime.h>

**Library**: libneural_network_runtime.so

**System capability**: SystemCapability.Ai.NeuralNetworkRuntime

**Since**: 9

**Related module**: [NeuralNetworkRuntime](capi-neuralnetworkruntime.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [NN_QuantParam *OH_NNQuantParam_Create()](#oh_nnquantparam_create) | Creates an [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance.|
| [OH_NN_ReturnCode OH_NNQuantParam_SetScales(NN_QuantParam *quantParams, const double *scales, size_t quantCount)](#oh_nnquantparam_setscales) | Sets the scaling coefficient of the [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance.<br>**quantCount** is the number of quantization parameters in the tensor. For example, for per-channel quantization, **quantCount** is the number of channels.|
| [OH_NN_ReturnCode OH_NNQuantParam_SetZeroPoints(NN_QuantParam *quantParams, const int32_t *zeroPoints, size_t quantCount)](#oh_nnquantparam_setzeropoints) | Sets the zero point of the [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance.<br>**quantCount** is the number of quantization parameters in the tensor. For example, for per-channel quantization, **quantCount** is the number of channels.|
| [OH_NN_ReturnCode OH_NNQuantParam_SetNumBits(NN_QuantParam *quantParams, const uint32_t *numBits, size_t quantCount)](#oh_nnquantparam_setnumbits) | Sets the quantization bit width of the [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance.<br>**quantCount** is the number of quantization parameters in the tensor. For example, for per-channel quantization, **quantCount** is the number of channels.|
| [OH_NN_ReturnCode OH_NNQuantParam_Destroy(NN_QuantParam **quantParams)](#oh_nnquantparam_destroy) | Destroys an [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance.<br>After an [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance is no longer needed after being passed to [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md), you need to destroy it to avoid memory leak.<br>If **quantParams** or ***quantParams** is a null pointer, this API only prints warning logs but does not perform the destruction operation.|
| [OH_NNModel *OH_NNModel_Construct(void)](#oh_nnmodel_construct) | Creates an [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance.|
| [OH_NN_ReturnCode OH_NNModel_AddTensorToModel(OH_NNModel *model, const NN_TensorDesc *tensorDesc)](#oh_nnmodel_addtensortomodel) | Adds a tensor to a model instance.<br>The data node and operator parameters in the NNRt model are composed of tensors of the model.|
| [OH_NN_ReturnCode OH_NNModel_SetTensorData(OH_NNModel *model, uint32_t index, const void *dataBuffer, size_t length)](#oh_nnmodel_settensordata) | Sets the tensor value. For tensors with constant values (such as model weights), you need to use this API in the composition phase. The index value of a tensor is determined by the sequence in which the tensor is added to the model. For details about how to add a tensor, see [OH_NNModel_AddTensorToModel](capi-neural-network-runtime-h.md#oh_nnmodel_addtensortomodel).|
| [OH_NN_ReturnCode OH_NNModel_SetTensorQuantParams(OH_NNModel *model, uint32_t index, NN_QuantParam *quantParam)](#oh_nnmodel_settensorquantparams) | Sets the quantization parameters of a tensor. For details, see [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md).|
| [OH_NN_ReturnCode OH_NNModel_SetTensorType(OH_NNModel *model, uint32_t index, OH_NN_TensorType tensorType)](#oh_nnmodel_settensortype) | Sets the tensor type. For details, see [OH_NN_TensorType](capi-neural-network-runtime-type-h.md#oh_nn_tensortype).|
| [OH_NN_ReturnCode OH_NNModel_AddOperation(OH_NNModel *model,OH_NN_OperationType op,const OH_NN_UInt32Array *paramIndices,const OH_NN_UInt32Array *inputIndices,const OH_NN_UInt32Array *outputIndices)](#oh_nnmodel_addoperation) | Adds an operator to a model instance.|
| [OH_NN_ReturnCode OH_NNModel_SpecifyInputsAndOutputs(OH_NNModel *model,const OH_NN_UInt32Array *inputIndices,const OH_NN_UInt32Array *outputIndices)](#oh_nnmodel_specifyinputsandoutputs) | Sets an index value for the input and output tensors of a model. A tensor must be specified as the end-to-end input and output of a model instance. |
| [OH_NN_ReturnCode OH_NNModel_Finish(OH_NNModel *model)](#oh_nnmodel_finish) | Completes model composition. After the model topology is set up, call this API to indicate that the composition is complete.|
| [void OH_NNModel_Destroy(OH_NNModel **model)](#oh_nnmodel_destroy) | Destroys a model instance. This API needs to be called to destroy the model instance created by calling [OH_NNModel_Construct](capi-neural-network-runtime-h.md#oh_nnmodel_construct). Otherwise, memory leak will occur. If **model** or ***model** is a null pointer, this API only prints warning logs but does not perform the destruction operation.|
| [OH_NN_ReturnCode OH_NNModel_GetAvailableOperations(OH_NNModel *model,size_t deviceID,const bool **isSupported,uint32_t *opCount)](#oh_nnmodel_getavailableoperations) | Checks whether all operators in a model are supported by the device. The result is indicated by a Boolean value.|
| [OH_NN_ReturnCode OH_NNModel_AddTensor(OH_NNModel *model, const OH_NN_Tensor *tensor)](#oh_nnmodel_addtensor) | Adds a tensor to a model instance.<br>The data node and operator parameters in the NNRt model are composed of tensors of the model. You can use this API to add tensors to a model instance based on the **tensor** parameter.|
| [OH_NN_ReturnCode OH_NNExecutor_SetInput(OH_NNExecutor *executor,uint32_t inputIndex,const OH_NN_Tensor *tensor,const void *dataBuffer,size_t length)](#oh_nnexecutor_setinput) | Sets the data for a single model input. This API copies the data whose length is specified by **length** (in bytes) in **dataBuffer** to the shared memory of the underlying device.|
| [OH_NN_ReturnCode OH_NNExecutor_SetOutput(OH_NNExecutor *executor,uint32_t outputIndex,void *dataBuffer,size_t length)](#oh_nnexecutor_setoutput) | Sets the memory for a single model output.<br>This API binds the buffer pointed by **dataBuffer** to the output specified by **outputIndex**. The length of the buffer is specified by **length**.|
| [OH_NN_ReturnCode OH_NNExecutor_Run(OH_NNExecutor *executor)](#oh_nnexecutor_run) | Perform model inference through This API performs end-to-end model inference and computing on the device associated with the executor.|
| [OH_NN_Memory *OH_NNExecutor_AllocateInputMemory(OH_NNExecutor *executor, uint32_t inputIndex, size_t length)](#oh_nnexecutor_allocateinputmemory) | Applies for shared memory for a single model input on the device.|
| [OH_NN_Memory *OH_NNExecutor_AllocateOutputMemory(OH_NNExecutor *executor, uint32_t outputIndex, size_t length)](#oh_nnexecutor_allocateoutputmemory) | Applies for shared memory for a single model output on the device.|
| [void OH_NNExecutor_DestroyInputMemory(OH_NNExecutor *executor, uint32_t inputIndex, OH_NN_Memory **memory)](#oh_nnexecutor_destroyinputmemory) | Releases the input memory pointed by the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance. This API is used to release the memory instance created by calling [OH_NNExecutor_AllocateInputMemory](capi-neural-network-runtime-h.md#oh_nnexecutor_allocateinputmemory). If this API is not called, memory leakage occurs.|
| [void OH_NNExecutor_DestroyOutputMemory(OH_NNExecutor *executor, uint32_t outputIndex, OH_NN_Memory **memory)](#oh_nnexecutor_destroyoutputmemory) | Releases the output memory pointed by the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance. This API needs to be called to release the memory instance created by calling [OH_NNExecutor_AllocateOutputMemory](capi-neural-network-runtime-h.md#oh_nnexecutor_allocateoutputmemory). Otherwise, memory leak will occur. The mapping between **outputIndex** and **memory** must be the same as that in memory instance creation. If **memory** or ***memory** is a null pointer, this API only prints the warning log and does not execute the release logic.|
| [OH_NN_ReturnCode OH_NNExecutor_SetInputWithMemory(OH_NNExecutor *executor,uint32_t inputIndex,const OH_NN_Tensor *tensor,const OH_NN_Memory *memory)](#oh_nnexecutor_setinputwithmemory) | Specifies the hardware shared memory pointed by the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance as the shared memory used by a single model input.|
| [OH_NN_ReturnCode OH_NNExecutor_SetOutputWithMemory(OH_NNExecutor *executor,uint32_t outputIndex,const OH_NN_Memory *memory)](#oh_nnexecutor_setoutputwithmemory) | Specifies the hardware shared memory pointed by the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance as the shared memory used by a single model output.|

## Function Description

### OH_NNQuantParam_Create()

```
NN_QuantParam *OH_NNQuantParam_Create()
```

**Description**

Creates an [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance.

After creating an [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance, set its attribute values by calling [OH_NNQuantParam_SetScales](capi-neural-network-runtime-h.md#oh_nnquantparam_setscales), [OH_NNQuantParam_SetZeroPoints](capi-neural-network-runtime-h.md#oh_nnquantparam_setzeropoints), or [OH_NNQuantParam_SetNumBits](capi-neural-network-runtime-h.md#oh_nnquantparam_setnumbits), and pass it to [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) by calling [OH_NNModel_SetTensorQuantParams](capi-neural-network-runtime-h.md#oh_nnmodel_settensorquantparams). Finally, call [OH_NNQuantParam_Destroy](capi-neural-network-runtime-h.md#oh_nnquantparam_destroy) to destroy the instance to prevent a memory leak.

**Since**: 11

**Returns**

| Type| Description|
| -- | -- |
| [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) * | Pointer to the [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance. If the operation fails, **NULL** is returned.|

### OH_NNQuantParam_SetScales()

```
OH_NN_ReturnCode OH_NNQuantParam_SetScales(NN_QuantParam *quantParams, const double *scales, size_t quantCount)
```

**Description**

Sets the scaling coefficient of the [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance.

**quantCount** is the number of quantization parameters in the tensor. For example, for per-channel quantization, **quantCount** is the number of channels.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) *quantParams | Pointer to the [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance.|
| const double *scales | Array consisting of scaling coefficients of all quantization parameters in the tensor.|
| size_t quantCount | Number of quantization parameters in a tensor.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNQuantParam_SetZeroPoints()

```
OH_NN_ReturnCode OH_NNQuantParam_SetZeroPoints(NN_QuantParam *quantParams, const int32_t *zeroPoints, size_t quantCount)
```

**Description**

Sets the zero point of the [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance.

**quantCount** is the number of quantization parameters in the tensor. For example, for per-channel quantization, **quantCount** is the number of channels.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) *quantParams | Pointer to the [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance.|
| const int32_t *zeroPoints | Array consisting of zero points of all quantization parameters in a tensor.|
| size_t quantCount | Number of quantization parameters in a tensor.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNQuantParam_SetNumBits()

```
OH_NN_ReturnCode OH_NNQuantParam_SetNumBits(NN_QuantParam *quantParams, const uint32_t *numBits, size_t quantCount)
```

**Description**

Sets the quantization bit width of the [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance.

**quantCount** is the number of quantization parameters in the tensor. For example, for per-channel quantization, **quantCount** is the number of channels.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) *quantParams | Pointer to the [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance.|
| const uint32_t *numBits | Array consisting of quantization bits of all quantization parameters in a tensor.|
| size_t quantCount | Number of quantization parameters in a tensor.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNQuantParam_Destroy()

```
OH_NN_ReturnCode OH_NNQuantParam_Destroy(NN_QuantParam **quantParams)
```

**Description**

Destroys an [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance.

After an [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance is no longer needed after being passed to [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md), you need to destroy it to avoid memory leak.<br>If **quantParams** or ***quantParams** is a null pointer, this API only prints warning logs but does not perform the destruction operation.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) **quantParams | Level-2 pointer to the [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNModel_Construct()

```
OH_NNModel *OH_NNModel_Construct(void)
```

**Description**

Creates an [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance.

Before graph composition, call [OH_NNModel_Construct](capi-neural-network-runtime-h.md#oh_nnmodel_construct) to create a model instance. Based on the model topology, call [OH_NNModel_AddTensorToModel](capi-neural-network-runtime-h.md#oh_nnmodel_addtensortomodel), [OH_NNModel_AddOperation](capi-neural-network-runtime-h.md#oh_nnmodel_addoperation), and [OH_NNModel_SetTensorData](capi-neural-network-runtime-h.md#oh_nnmodel_settensordata) to fill in the data and operator nodes of the model, and then call [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) to specify the input and output of the model. After the model topology is constructed, call [OH_NNModel_Finish](capi-neural-network-runtime-h.md#oh_nnmodel_finish) to build the model.

If a model instance is no longer needed, destroy it by calling [OH_NNModel_Destroy](capi-neural-network-runtime-h.md#oh_nnmodel_destroy) to prevent a memory leak.

**Since**: 9

**Returns**

| Type| Description|
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) * | Pointer to the [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance. If the operation fails, **NULL** is returned.|

### OH_NNModel_AddTensorToModel()

```
OH_NN_ReturnCode OH_NNModel_AddTensorToModel(OH_NNModel *model, const NN_TensorDesc *tensorDesc)
```

**Description**

Adds a tensor to a model instance.

The data node and operator parameters in the NNRt model are composed of tensors of the model.

This API adds tensors to a model instance based on [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md). The sequence of adding tensors is specified by the index value recorded in the model. The [OH_NNModel_SetTensorData](capi-neural-network-runtime-h.md#oh_nnmodel_settensordata), [OH_NNModel_AddOperation](capi-neural-network-runtime-h.md#oh_nnmodel_addoperation), and [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) APIs specify tensors based on the index value.

NNRt supports input and output of dynamic shapes. When adding a data node with a dynamic shape, you need to set the dimensions that support dynamic changes in **tensor.dimensions** to **-1**. For example, if **tensor.dimensions** of a four-dimensional tensor is set to **[1, -1, 2, 2]**, the second dimension supports dynamic changes.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | Pointer to the [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance.|
| [const NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) *tensorDesc | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) tensor, where [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) specify the attributes of the tensor to be added to the model instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNModel_SetTensorData()

```
OH_NN_ReturnCode OH_NNModel_SetTensorData(OH_NNModel *model, uint32_t index, const void *dataBuffer, size_t length)
```

**Description**

Sets the tensor value. For tensors with constant values (such as model weights), you need to use this API in the composition phase.

The index value of a tensor is determined by the sequence in which the tensor is added to the model. For details about how to add a tensor, see [OH_NNModel_AddTensorToModel](capi-neural-network-runtime-h.md#oh_nnmodel_addtensortomodel).

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | Pointer to the [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance.|
| uint32_t index | Index value of a tensor.|
| const void *dataBuffer | Pointer to the real data memory.|
| size_t length | Length of the data memory.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNModel_SetTensorQuantParams()

```
OH_NN_ReturnCode OH_NNModel_SetTensorQuantParams(OH_NNModel *model, uint32_t index, NN_QuantParam *quantParam)
```

**Description**

Sets the quantization parameters of a tensor. For details, see [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md).

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | Pointer to the [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance.|
| uint32_t index | Index value of a tensor.|
| [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) *quantParam | Pointer to the [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNModel_SetTensorType()

```
OH_NN_ReturnCode OH_NNModel_SetTensorType(OH_NNModel *model, uint32_t index, OH_NN_TensorType tensorType)
```

**Description**

Sets the tensor type. For details, see [OH_NN_TensorType](capi-neural-network-runtime-type-h.md#oh_nn_tensortype).

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | Pointer to the [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance.|
| uint32_t index | Index value of a tensor.|
| [OH_NN_TensorType](capi-neural-network-runtime-type-h.md#oh_nn_tensortype) tensorType | Tensor type.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNModel_AddOperation()

```
OH_NN_ReturnCode OH_NNModel_AddOperation(OH_NNModel *model,OH_NN_OperationType op,const OH_NN_UInt32Array *paramIndices,const OH_NN_UInt32Array *inputIndices,const OH_NN_UInt32Array *outputIndices)
```

**Description**

Adds an operator to a model instance.

You can use this API to add an operator to a model instance. The operator type is specified by **op**, and the operator parameters, inputs, and outputs are specified by **paramIndices**, **inputIndices**, and **outputIndices** respectively.

This API verifies the attributes of operator parameters and the number of input and output parameters. These attributes must be correctly set when [OH_NNModel_AddTensorToModel](capi-neural-network-runtime-h.md#oh_nnmodel_addtensortomodel) is called to add tensors.

For details about the expected parameters, input attributes, and output attributes of each operator, see [OH_NN_OperationType](capi-neural-network-runtime-type-h.md#oh_nn_operationtype).

**paramIndices**, **inputIndices**, and **outputIndices** store index values of tensors. Index values are determined by the sequence in which tensors are added to the model.

For details about how to add a tensor, see [OH_NNModel_AddTensorToModel](capi-neural-network-runtime-h.md#oh_nnmodel_addtensortomodel).

If unnecessary parameters are added for adding an operator, this API returns the error code [OH_NN_INVALID_PARAMETER](capi-neural-network-runtime-type-h.md#oh_nn_returncode). If no operator parameter is set, the operator uses the default parameter value. For details about the default values, see OH_NN_OperationType](capi-neural-network-runtime-type-h.md#oh_nn_operationtype).

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | Pointer to the [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance.|
| [OH_NN_OperationType](capi-neural-network-runtime-type-h.md#oh_nn_operationtype) op | Type of the operator to be added. For details, see [OH_NN_OperationType](capi-neural-network-runtime-type-h.md#oh_nn_operationtype).|
| [const OH_NN_UInt32Array](capi-neuralnetworkruntime-oh-nn-uint32array.md) *paramIndices | Pointer to the **OH_NN_UInt32Array** instance, which is used to set the parameter tensor index of the operator.|
| [const OH_NN_UInt32Array](capi-neuralnetworkruntime-oh-nn-uint32array.md) *inputIndices | Pointer to the **OH_NN_UInt32Array** instance, specifying the input tensor index of the operator.|
| [const OH_NN_UInt32Array](capi-neuralnetworkruntime-oh-nn-uint32array.md) *outputIndices | Pointer to the **OH_NN_UInt32Array** instance, which is used to set the output tensor index of the operator.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNModel_SpecifyInputsAndOutputs()

```
OH_NN_ReturnCode OH_NNModel_SpecifyInputsAndOutputs(OH_NNModel *model,const OH_NN_UInt32Array *inputIndices,const OH_NN_UInt32Array *outputIndices)
```

**Description**

Sets an index value for the input and output tensors of a model.

A tensor must be specified as the end-to-end input and output of a model instance. After a tensor is set as the input or output tensor, you are not allowed to set the tensor data by calling [OH_NNModel_SetTensorData](capi-neural-network-runtime-h.md#oh_nnmodel_settensordata). Instead, call OH_NNExecutor in the execution phase to set the input or output tensor data.

The index value of a tensor is determined by the sequence in which the tensor is added to the model. For details about how to add a tensor, see [OH_NNModel_AddTensorToModel](capi-neural-network-runtime-h.md#oh_nnmodel_addtensortomodel). Currently, the model input and output cannot be set asynchronously.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | Pointer to the [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance.|
| [const OH_NN_UInt32Array](capi-neuralnetworkruntime-oh-nn-uint32array.md) *inputIndices | Pointer to the **OH_NN_UInt32Array** instance, which is used to set the input tensor of the operator.|
| [const OH_NN_UInt32Array](capi-neuralnetworkruntime-oh-nn-uint32array.md) *outputIndices | Pointer to the OH_NN_UInt32Array instance, which is used to set the output tensor of the operator.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNModel_Finish()

```
OH_NN_ReturnCode OH_NNModel_Finish(OH_NNModel *model)
```

**Description**

Completes model composition.

After the model topology is set up, call this API to indicate that the composition is complete.

After this API is called, additional graph composition cannot be performed. If [OH_NNModel_AddTensorToModel](capi-neural-network-runtime-h.md#oh_nnmodel_addtensortomodel), [OH_NNModel_AddOperation](capi-neural-network-runtime-h.md#oh_nnmodel_addoperation), [OH_NNModel_SetTensorData](capi-neural-network-runtime-h.md#oh_nnmodel_settensordata), or [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called, [OH_NN_OPERATION_FORBIDDEN](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned.

Before calling Before calling [OH_NNModel_GetAvailableOperations](capi-neural-network-runtime-h.md#oh_nnmodel_getavailableoperations) and [OH_NNCompilation_Construct](capi-neural-network-core-h.md#oh_nncompilation_construct), you must call this API to complete composition., you must call this API to complete composition.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | Pointer to the [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNModel_Destroy()

```
void OH_NNModel_Destroy(OH_NNModel **model)
```

**Description**

Destroys a model instance.

This API needs to be called to destroy the model instance created by calling [OH_NNModel_Construct](capi-neural-network-runtime-h.md#oh_nnmodel_construct). Otherwise, memory leak will occur.

If **model** or ***model** is a null pointer, this API only prints warning logs but does not perform the destruction operation.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) **model | Level-2 pointer to the [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance. After a model instance is destroyed, this API sets ***model** to a null pointer.|

### OH_NNModel_GetAvailableOperations()

```
OH_NN_ReturnCode OH_NNModel_GetAvailableOperations(OH_NNModel *model,size_t deviceID,const bool **isSupported,uint32_t *opCount)
```

**Description**

Checks whether all operators in a model are supported by the device. The result is indicated by a Boolean value.

Checks whether the underlying device supports operators in a model instance. The device is specified by **deviceID**, and the result is represented by the array pointed by **isSupported**.

If the *i*th operator is supported, the value of **(\*isSupported)**[*i*] is **true**. Otherwise, the value is **false**. After this API is successfully executed, **(*isSupported)** points to the bool array that records the operator support status. The operator quantity for the array length is the same as that for the model instance.

The memory corresponding to this array is managed by NNRt and is automatically destroyed after the model instance is destroyed or this API is called again.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | Pointer to the [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance.|
| size_t deviceID | Device ID to be queried, which can be obtained by using [OH_NNDevice_GetAllDevicesID](capi-neural-network-core-h.md#oh_nndevice_getalldevicesid).|
| const bool **isSupported | Pointer to the **bool** array. The input ***isSupported** must be a null pointer. Otherwise, [OH_NN_INVALID_PARAMETER](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned.|
| uint32_t *opCount | Number of operators in a model instance, corresponding to the length of the ***isSupported** array.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNModel_AddTensor()

```
OH_NN_ReturnCode OH_NNModel_AddTensor(OH_NNModel *model, const OH_NN_Tensor *tensor)
```

**Description**

Adds a tensor to a model instance.

The data node and operator parameters in the NNRt model are composed of tensors of the model. You can use this API to add tensors to a model instance based on the **tensor** parameter.

The sequence of adding tensors is specified by the index value recorded in the model. The [OH_NNModel_SetTensorData](capi-neural-network-runtime-h.md#oh_nnmodel_settensordata), [OH_NNModel_AddOperation](capi-neural-network-runtime-h.md#oh_nnmodel_addoperation), and [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) APIs specify tensors based on the index value.

NNRt supports input and output of dynamic shapes.

When adding a data node with a dynamic shape, you need to set the dimensions that support dynamic changes in **tensor.dimensions** to **-1**. For example, if **tensor.dimensions** of a four-dimensional tensor is set to **[1, -1, 2, 2]**, the second dimension supports dynamic changes.

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_NNModel_AddTensorToModel](capi-neural-network-runtime-h.md#oh_nnmodel_addtensortomodel)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | Pointer to the [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance.|
| [const OH_NN_Tensor](capi-neuralnetworkruntime-oh-nn-tensor.md) *tensor | Pointer to the [OH_NN_Tensor](capi-neuralnetworkruntime-oh-nn-tensor.md) tensor, where **tensor** specifies the attributes of the tensor to be added to the model instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNExecutor_SetInput()

```
OH_NN_ReturnCode OH_NNExecutor_SetInput(OH_NNExecutor *executor,uint32_t inputIndex,const OH_NN_Tensor *tensor,const void *dataBuffer,size_t length)
```

**Description**

Sets the data for a single model input.

This API copies the data whose length is specified by **length** (in bytes) in **dataBuffer** to the shared memory of the underlying device.

**inputIndex** specifies the input to be set and **tensor** sets tensor information such as the shape, type, and quantization parameters.

NNRt supports models with dynamical shape input. For fixed shape input and dynamic shape input scenarios, this API uses different processing policies.

- Fixed shape input: The attributes of tensor must be the same as those of the tensor added by calling [OH_NNModel_AddTensor](capi-neural-network-runtime-h.md#oh_nnmodel_addtensor) in the build phase.
- Dynamic shape input: In the composition phase, because the shape is not fixed, each value in **tensor.dimensions** must be greater than **0** in the API calls to determine the shape input in the computing phase. When setting the shape, you can modify only the dimension whose value is **-1**.<br>Assume that **[-1, 224, 224, 3]** is input as the the dimension of A in the composition phase. When this API is called, you can only change the size of the first dimension, for example, to [3, 224, 224, 3]. If other dimensions are adjusted, [OH_NN_INVALID_PARAMETER](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned.

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_NNExecutor_RunSync](capi-neural-network-core-h.md#oh_nnexecutor_runsync)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|
| uint32_t inputIndex | Input index value, which is the same as the sequence of the input data when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called.<br>Assume that **inputIndices** is {1, 5, 9} when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called. When you set the input data, set the value of this parameter to {0, 1, 2}.|
| [const OH_NN_Tensor](capi-neuralnetworkruntime-oh-nn-tensor.md) *tensor | Tensor corresponding to the input data.|
| const void *dataBuffer | Pointer to the input data.|
| size_t length | Length of the data memory, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNExecutor_SetOutput()

```
OH_NN_ReturnCode OH_NNExecutor_SetOutput(OH_NNExecutor *executor,uint32_t outputIndex,void *dataBuffer,size_t length)
```

**Description**

Sets the memory for a single model output.

This method binds the buffer pointed by **dataBuffer** to the output specified by **outputIndex**. The length of the buffer is specified by **length**.

After [OH_NNExecutor_Run](capi-neural-network-runtime-h.md#oh_nnexecutor_run) is called to complete a single model inference, NNRt compares the length of the buffer pointed by **dataBuffer** with the length of the output data and returns different results based on the actual situation. 

- If the memory size is greater than or equal to the data length, the API copies the inference result to the memory and returns [OH_NN_SUCCESS](capi-neural-network-runtime-type-h.md#oh_nn_returncode). You can read the inference result from **dataBuffer**.
- If the memory size is less than the data length, the [OH_NNExecutor_Run](capi-neural-network-runtime-h.md#oh_nnexecutor_run) API returns the error code [OH_NN_INVALID_PARAMETER](capi-neural-network-runtime-type-h.md#oh_nn_returncode) and generates a log indicating that the memory size is too small.

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_NNExecutor_RunSync](capi-neural-network-core-h.md#oh_nnexecutor_runsync)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|
| uint32_t outputIndex | Output index value, which is the same as the sequence of the output data when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called.<br>Assume that **outputIndices** is {4, 6, 8} when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called. When you set the output memory, set the value of this parameter to {0, 1, 2}.|
| void *dataBuffer | Pointer to the output data.|
| size_t length | Length of the data memory, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNExecutor_Run()

```
OH_NN_ReturnCode OH_NNExecutor_Run(OH_NNExecutor *executor)
```

**Description**

Perform model inference through This API performs end-to-end model inference and computing on the device associated with the executor.

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_NNExecutor_RunSync](capi-neural-network-core-h.md#oh_nnexecutor_runsync)

**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNExecutor_AllocateInputMemory()

```
OH_NN_Memory *OH_NNExecutor_AllocateInputMemory(OH_NNExecutor *executor, uint32_t inputIndex, size_t length)
```

**Description**

Applies for shared memory for a single model input on the device.

NNRt provides an API for proactively applying for shared memory on a device.

Based on the specified executor and input index value, this API applies for the shared memory whose size is **length** on the device associated with a single input. Then, it returns the shared memory through the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance.

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_NNTensor_CreateWithSize](capi-neural-network-core-h.md#oh_nntensor_createwithsize)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|
| uint32_t inputIndex | Input index value, which is the same as the sequence of the input data when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called.<br>Assume that **inputIndices** is {1, 5, 9} when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called. When you request the input memory, set the value of this parameter to {0, 1, 2}.|
| size_t length | Memory size to be applied for, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) * | Pointer to the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance. If the operation fails, **NULL** is returned.|

### OH_NNExecutor_AllocateOutputMemory()

```
OH_NN_Memory *OH_NNExecutor_AllocateOutputMemory(OH_NNExecutor *executor, uint32_t outputIndex, size_t length)
```

**Description**

Applies for shared memory for a single model output on the device.

NNRt provides an API for proactively applying for shared memory on a device.

Based on the specified executor and output index value, this API applies for the shared memory whose size is **length** on the device associated with a single output. Then, it returns the shared memory through the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance.

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_NNTensor_CreateWithSize](capi-neural-network-core-h.md#oh_nntensor_createwithsize)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|
| uint32_t outputIndex | Output index value, which is the same as the sequence of the output data when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called.<br>Assume that **outputIndices** is {4, 6, 8} when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called. When you request the output memory, set the value of this parameter to {0, 1, 2}.|
| size_t length | Memory size to be applied for, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) * | Pointer to the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance. If the operation fails, **NULL** is returned.|

### OH_NNExecutor_DestroyInputMemory()

```
void OH_NNExecutor_DestroyInputMemory(OH_NNExecutor *executor, uint32_t inputIndex, OH_NN_Memory **memory)
```

**Description**

Releases the input memory pointed by the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance.

This API is used to release the memory instance created by calling [OH_NNExecutor_AllocateInputMemory](capi-neural-network-runtime-h.md#oh_nnexecutor_allocateinputmemory). If this API is not called, memory leakage occurs.

The mapping between **inputIndex** and **memory** must be the same as that in memory instance creation. If **memory** or ***memory** is a null pointer, this API only prints the warning log and does not execute the release logic.

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_NNTensor_Destroy](capi-neural-network-core-h.md#oh_nntensor_destroy)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|
| uint32_t inputIndex | Input index value, which is the same as the sequence of the input data when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called.<br>Assume that **inputIndices** is {1, 5, 9} when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called. When you release the input memory, set the value of this parameter to {0, 1, 2}.|
| [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) **memory | Level-2 pointer to the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance. After the shared memory is released, this API sets ***memory** to a null pointer.|

### OH_NNExecutor_DestroyOutputMemory()

```
void OH_NNExecutor_DestroyOutputMemory(OH_NNExecutor *executor, uint32_t outputIndex, OH_NN_Memory **memory)
```

**Description**

Releases the output memory pointed by the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance.

This API needs to be called to release the memory instance created by calling [OH_NNExecutor_AllocateOutputMemory](capi-neural-network-runtime-h.md#oh_nnexecutor_allocateoutputmemory). Otherwise, memory leak will occur.

The mapping between **outputIndex** and **memory** must be the same as that in memory instance creation.

If **memory** or ***memory** is a null pointer, this API only prints the warning log and does not execute the release logic.

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_NNTensor_Destroy](capi-neural-network-core-h.md#oh_nntensor_destroy)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|
| uint32_t outputIndex | Output index value, which is the same as the sequence of the output data when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called.<br>Assume that **outputIndices** is {4, 6, 8} when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called. When you release the output memory, set the value of this parameter to {0, 1, 2}.|
| [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) **memory | Level-2 pointer to the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance. After the shared memory is released, this API sets ***memory** to a null pointer.|

### OH_NNExecutor_SetInputWithMemory()

```
OH_NN_ReturnCode OH_NNExecutor_SetInputWithMemory(OH_NNExecutor *executor,uint32_t inputIndex,const OH_NN_Tensor *tensor,const OH_NN_Memory *memory)
```

**Description**

Specifies the hardware shared memory pointed by the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance as the shared memory used by a single model input.

In the scenario where the memory needs to be managed by yourself, this API binds the input to the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance.

During computing, the underlying device reads the input data from the shared memory pointed to by the memory instance.

By using this API, you can implement concurrent execution of input setting, computing, and read to improve the data flow inference efficiency.

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_NNExecutor_RunSync](capi-neural-network-core-h.md#oh_nnexecutor_runsync)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|
| uint32_t inputIndex | Input index value, which is the same as the sequence of the input data when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called.<br>Assume that **inputIndices** is {1, 5, 9} when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called. When you specify the input shared memory, set the value of this parameter to {0, 1, 2}.|
| [const OH_NN_Tensor](capi-neuralnetworkruntime-oh-nn-tensor.md) *tensor | Pointer to the [OH_NN_Tensor](capi-neuralnetworkruntime-oh-nn-tensor.md) instance, which is used to set the tensor corresponding to a single input.|
| [const OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) *memory | Pointer to the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNExecutor_SetOutputWithMemory()

```
OH_NN_ReturnCode OH_NNExecutor_SetOutputWithMemory(OH_NNExecutor *executor,uint32_t outputIndex,const OH_NN_Memory *memory)
```

**Description**

Specifies the hardware shared memory pointed by the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance as the shared memory used by a single model output.

In the scenario where the memory needs to be managed by yourself, this API binds the output to the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance.

During computing, the underlying device writes the computing result to the shared memory pointed by the memory instance.

By using this API, you can implement concurrent execution of input setting, computing, and read to improve the data flow inference efficiency.

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_NNExecutor_RunSync](capi-neural-network-core-h.md#oh_nnexecutor_runsync)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the executor.|
| uint32_t outputIndex | Output index value, which is the same as the sequence of the output data when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called.<br>Assume that **outputIndices** is {4, 6, 8} when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called. When you specify the output shared memory, set the value of this parameter to {0, 1, 2}.|
| [const OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) *memory | Pointer to the [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|
