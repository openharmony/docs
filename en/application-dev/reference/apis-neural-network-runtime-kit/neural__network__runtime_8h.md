# neural_network_runtime.h


## Overview

Defines APIs for Neural Network Runtime. The AI inference framework uses the native APIs provided by the Neural Network Runtime to construct and build models.

**NOTE**<br>Currently, the APIs of Neural Network Runtime do not support multi-thread calling.

**File to include**: &lt;neural_network_runtime/neural_network_runtime.h&gt;

**Library**: libneural_network_runtime.so

**System capability**: \@Syscap SystemCapability.Ai.NeuralNetworkRuntime

**Since**: 9

**Related module**: [NeuralNetworkRuntime](_neural_network_runtime.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [NN_QuantParam](_neural_network_runtime.md#nn_quantparam) \* [OH_NNQuantParam_Create](_neural_network_runtime.md#oh_nnquantparam_create) () | Creates an [NN_QuantParam](_neural_network_runtime.md#nn_quantparam) instance.| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNQuantParam_SetScales](_neural_network_runtime.md#oh_nnquantparam_setscales) ([NN_QuantParam](_neural_network_runtime.md#nn_quantparam) \*quantParams, const double \*scales, size_t quantCount) | Sets the scaling coefficient for an [NN_QuantParam](_neural_network_runtime.md#nn_quantparam) instance.| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNQuantParam_SetZeroPoints](_neural_network_runtime.md#oh_nnquantparam_setzeropoints) ([NN_QuantParam](_neural_network_runtime.md#nn_quantparam) \*quantParams, const int32_t \*zeroPoints, size_t quantCount) | Sets the zero point for an [NN_QuantParam](_neural_network_runtime.md#nn_quantparam) instance.| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNQuantParam_SetNumBits](_neural_network_runtime.md#oh_nnquantparam_setnumbits) ([NN_QuantParam](_neural_network_runtime.md#nn_quantparam) \*quantParams, const uint32_t \*numBits, size_t quantCount) | Sets the number of quantization bits for an [NN_QuantParam](_neural_network_runtime.md#nn_quantparam) instance.| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNQuantParam_Destroy](_neural_network_runtime.md#oh_nnquantparam_destroy) ([NN_QuantParam](_neural_network_runtime.md#nn_quantparam) \*\*quantParams) | Destroys an [NN_QuantParam](_neural_network_runtime.md#nn_quantparam) instance.| 
| [OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \* [OH_NNModel_Construct](_neural_network_runtime.md#oh_nnmodel_construct) (void) | Creates a model instance of the [OH_NNModel](_neural_network_runtime.md#oh_nnmodel) type and constructs a model instance by using the APIs provided by **OH_NNModel**.| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_AddTensorToModel](_neural_network_runtime.md#oh_nnmodel_addtensortomodel) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model, const [NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \*tensorDesc) | Adds a tensor to a model instance.| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_SetTensorData](_neural_network_runtime.md#oh_nnmodel_settensordata) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model, uint32_t index, const void \*dataBuffer, size_t length) | Sets the tensor value.| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_SetTensorQuantParams](_neural_network_runtime.md#oh_nnmodel_settensorquantparams) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model, uint32_t index, [NN_QuantParam](_neural_network_runtime.md#nn_quantparam) \*quantParam) | Sets the quantization parameters of a tensor. For details, see [NN_QuantParam](_neural_network_runtime.md#nn_quantparam).| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_SetTensorType](_neural_network_runtime.md#oh_nnmodel_settensortype) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model, uint32_t index, [OH_NN_TensorType](_neural_network_runtime.md#oh_nn_tensortype) tensorType) | Sets the tensor type. For details, see [OH_NN_TensorType](_neural_network_runtime.md#oh_nn_tensortype).| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_AddOperation](_neural_network_runtime.md#oh_nnmodel_addoperation) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model, [OH_NN_OperationType](_neural_network_runtime.md#oh_nn_operationtype) op, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*paramIndices, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*inputIndices, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*outputIndices) | Adds an operator to a model instance.| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_SpecifyInputsAndOutputs](_neural_network_runtime.md#oh_nnmodel_specifyinputsandoutputs) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*inputIndices, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*outputIndices) | Sets an index value for the input and output tensors of a model.| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_Finish](_neural_network_runtime.md#oh_nnmodel_finish) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model) | Completes model composition.| 
| void [OH_NNModel_Destroy](_neural_network_runtime.md#oh_nnmodel_destroy) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*\*model) | Destroys a model instance.| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_GetAvailableOperations](_neural_network_runtime.md#oh_nnmodel_getavailableoperations) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model, size_t deviceID, const bool \*\*isSupported, uint32_t \*opCount) | Checks whether all operators in a model are supported by the device. The result is indicated by a Boolean value.| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_AddTensor](_neural_network_runtime.md#oh_nnmodel_addtensor) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model, const [OH_NN_Tensor](_o_h___n_n___tensor.md) \*tensor) | Adds a tensor to a model instance.| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNExecutor_SetInput](_neural_network_runtime.md#oh_nnexecutor_setinput) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, uint32_t inputIndex, const [OH_NN_Tensor](_o_h___n_n___tensor.md) \*tensor, const void \*dataBuffer, size_t length) | Sets the data for a single model input.| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNExecutor_SetOutput](_neural_network_runtime.md#oh_nnexecutor_setoutput) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, uint32_t outputIndex, void \*dataBuffer, size_t length) | Sets the memory for a single model output.| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNExecutor_Run](_neural_network_runtime.md#oh_nnexecutor_run) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor) | Executes model inference.| 
| [OH_NN_Memory](_o_h___n_n___memory.md) \* [OH_NNExecutor_AllocateInputMemory](_neural_network_runtime.md#oh_nnexecutor_allocateinputmemory) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, uint32_t inputIndex, size_t length) | Applies for shared memory for a single model input on the device.| 
| [OH_NN_Memory](_o_h___n_n___memory.md) \* [OH_NNExecutor_AllocateOutputMemory](_neural_network_runtime.md#oh_nnexecutor_allocateoutputmemory) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, uint32_t outputIndex, size_t length) | Applies for shared memory for a single model output on the device.| 
| void [OH_NNExecutor_DestroyInputMemory](_neural_network_runtime.md#oh_nnexecutor_destroyinputmemory) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, uint32_t inputIndex, [OH_NN_Memory](_o_h___n_n___memory.md) \*\*memory) | Releases the input memory pointed by the [OH_NN_Memory](_o_h___n_n___memory.md) instance.| 
| void [OH_NNExecutor_DestroyOutputMemory](_neural_network_runtime.md#oh_nnexecutor_destroyoutputmemory) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, uint32_t outputIndex, [OH_NN_Memory](_o_h___n_n___memory.md) \*\*memory) | Releases the output memory pointed by the [OH_NN_Memory](_o_h___n_n___memory.md) instance.| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNExecutor_SetInputWithMemory](_neural_network_runtime.md#oh_nnexecutor_setinputwithmemory) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, uint32_t inputIndex, const [OH_NN_Tensor](_o_h___n_n___tensor.md) \*tensor, const [OH_NN_Memory](_o_h___n_n___memory.md) \*memory) | Specifies the shared memory pointed by the [OH_NN_Memory](_o_h___n_n___memory.md) instance for a single model input.| 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNExecutor_SetOutputWithMemory](_neural_network_runtime.md#oh_nnexecutor_setoutputwithmemory) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, uint32_t outputIndex, const [OH_NN_Memory](_o_h___n_n___memory.md) \*memory) | Specifies the shared memory pointed by the [OH_NN_Memory](_o_h___n_n___memory.md) instance for a single model output.| 
