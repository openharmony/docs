# neural_network_runtime.h


## Overview

Defines the Neural Network Runtime APIs. The AI inference framework uses the Native APIs provided by Neural Network Runtime to construct and compile models and perform inference and computing on acceleration hardware. Note: Currently, the APIs of Neural Network Runtime do not support multi-thread calling.

**Since:**
9

**Related Modules:**

[NeuralNeworkRuntime](_neural_nework_runtime.md)


## Summary


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_NNModel_Construct](_neural_nework_runtime.md#oh_nnmodel_construct) (void) | Creates a model instance of the [OH_NNModel](_neural_nework_runtime.md#oh_nnmodel) type and uses other APIs provided by OH_NNModel to construct the model instance.  | 
| [OH_NNModel_AddTensor](_neural_nework_runtime.md#oh_nnmodel_addtensor) ([OH_NNModel](_neural_nework_runtime.md#oh_nnmodel) \*model, const [OH_NN_Tensor](_o_h___n_n___tensor.md) \*tensor) | Adds a tensor to a model instance.  | 
| [OH_NNModel_SetTensorData](_neural_nework_runtime.md#oh_nnmodel_settensordata) ([OH_NNModel](_neural_nework_runtime.md#oh_nnmodel) \*model, uint32_t index, const void \*dataBuffer, size_t length) | Sets the tensor value.  | 
| [OH_NNModel_AddOperation](_neural_nework_runtime.md#oh_nnmodel_addoperation) ([OH_NNModel](_neural_nework_runtime.md#oh_nnmodel) \*model, [OH_NN_OperationType](_neural_nework_runtime.md#oh_nn_operationtype) op, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*paramIndices, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*inputIndices, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*outputIndices) | Adds an operator to a model instance.  | 
| [OH_NNModel_SpecifyInputsAndOutputs](_neural_nework_runtime.md#oh_nnmodel_specifyinputsandoutputs) ([OH_NNModel](_neural_nework_runtime.md#oh_nnmodel) \*model, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*inputIndices, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*outputIndices) | Specifies the inputs and outputs of a model.  | 
| [OH_NNModel_Finish](_neural_nework_runtime.md#oh_nnmodel_finish) ([OH_NNModel](_neural_nework_runtime.md#oh_nnmodel) \*model) | Completes model composition.  | 
| [OH_NNModel_Destroy](_neural_nework_runtime.md#oh_nnmodel_destroy) ([OH_NNModel](_neural_nework_runtime.md#oh_nnmodel) \*\*model) | Releases a model instance.  | 
| [OH_NNModel_GetAvailableOperations](_neural_nework_runtime.md#oh_nnmodel_getavailableoperations) ([OH_NNModel](_neural_nework_runtime.md#oh_nnmodel) \*model, size_t deviceID, const bool \*\*isSupported, uint32_t \*opCount) | Queries whether the device supports operators in the model. The support status is indicated by the Boolean value.  | 
| [OH_NNCompilation_Construct](_neural_nework_runtime.md#oh_nncompilation_construct) (const [OH_NNModel](_neural_nework_runtime.md#oh_nnmodel) \*model) | Creates a compilation instance of the [OH_NNCompilation](_neural_nework_runtime.md#oh_nncompilation) type.  | 
| [OH_NNCompilation_SetDevice](_neural_nework_runtime.md#oh_nncompilation_setdevice) ([OH_NNCompilation](_neural_nework_runtime.md#oh_nncompilation) \*compilation, size_t deviceID) | Specifies the device for model compilation and computing.  | 
| [OH_NNCompilation_SetCache](_neural_nework_runtime.md#oh_nncompilation_setcache) ([OH_NNCompilation](_neural_nework_runtime.md#oh_nncompilation) \*compilation, const char \*cachePath, uint32_t version) | Set the cache directory and version of the compiled model.  | 
| [OH_NNCompilation_SetPerformanceMode](_neural_nework_runtime.md#oh_nncompilation_setperformancemode) ([OH_NNCompilation](_neural_nework_runtime.md#oh_nncompilation) \*compilation, [OH_NN_PerformanceMode](_neural_nework_runtime.md#oh_nn_performancemode) performanceMode) | Sets the performance mode for model computing.  | 
| [OH_NNCompilation_SetPriority](_neural_nework_runtime.md#oh_nncompilation_setpriority) ([OH_NNCompilation](_neural_nework_runtime.md#oh_nncompilation) \*compilation, [OH_NN_Priority](_neural_nework_runtime.md#oh_nn_priority) priority) | Sets the model computing priority.  | 
| [OH_NNCompilation_EnableFloat16](_neural_nework_runtime.md#oh_nncompilation_enablefloat16) ([OH_NNCompilation](_neural_nework_runtime.md#oh_nncompilation) \*compilation, bool enableFloat16) | Enables float16 for computing.  | 
| [OH_NNCompilation_Build](_neural_nework_runtime.md#oh_nncompilation_build) ([OH_NNCompilation](_neural_nework_runtime.md#oh_nncompilation) \*compilation) | Compiles a model.  | 
| [OH_NNCompilation_Destroy](_neural_nework_runtime.md#oh_nncompilation_destroy) ([OH_NNCompilation](_neural_nework_runtime.md#oh_nncompilation) \*\*compilation) | Releases the **Compilation** object.  | 
| [OH_NNExecutor_Construct](_neural_nework_runtime.md#oh_nnexecutor_construct) ([OH_NNCompilation](_neural_nework_runtime.md#oh_nncompilation) \*compilation) | [OH_NNExecutor](_neural_nework_runtime.md#oh_nnexecutor) \*<br/>Creates an executor instance of the [OH_NNExecutor](_neural_nework_runtime.md#oh_nnexecutor) type.  | 
| [OH_NNExecutor_SetInput](_neural_nework_runtime.md#oh_nnexecutor_setinput) ([OH_NNExecutor](_neural_nework_runtime.md#oh_nnexecutor) \*executor, uint32_t inputIndex, const [OH_NN_Tensor](_o_h___n_n___tensor.md) \*tensor, const void \*dataBuffer, size_t length) | Sets the single input data for a model.  | 
| [OH_NNExecutor_SetOutput](_neural_nework_runtime.md#oh_nnexecutor_setoutput) ([OH_NNExecutor](_neural_nework_runtime.md#oh_nnexecutor) \*executor, uint32_t outputIndex, void \*dataBuffer, size_t length) | Sets the buffer for a single output of a model.  | 
| [OH_NNExecutor_GetOutputShape](_neural_nework_runtime.md#oh_nnexecutor_getoutputshape) ([OH_NNExecutor](_neural_nework_runtime.md#oh_nnexecutor) \*executor, uint32_t outputIndex, int32_t \*\*shape, uint32_t \*shapeLength) | Obtains the dimension information about the output tensor.  | 
| [OH_NNExecutor_Run](_neural_nework_runtime.md#oh_nnexecutor_run) ([OH_NNExecutor](_neural_nework_runtime.md#oh_nnexecutor) \*executor) | Performs inference.  | 
| [OH_NNExecutor_AllocateInputMemory](_neural_nework_runtime.md#oh_nnexecutor_allocateinputmemory) ([OH_NNExecutor](_neural_nework_runtime.md#oh_nnexecutor) \*executor, uint32_t inputIndex, size_t length) | Allocates shared memory to a single input on a device.  | 
| [OH_NNExecutor_AllocateOutputMemory](_neural_nework_runtime.md#oh_nnexecutor_allocateoutputmemory) ([OH_NNExecutor](_neural_nework_runtime.md#oh_nnexecutor) \*executor, uint32_t outputIndex, size_t length) | Allocates shared memory to a single output on a device.  | 
| [OH_NNExecutor_DestroyInputMemory](_neural_nework_runtime.md#oh_nnexecutor_destroyinputmemory) ([OH_NNExecutor](_neural_nework_runtime.md#oh_nnexecutor) \*executor, uint32_t inputIndex, [OH_NN_Memory](_o_h___n_n___memory.md) \*\*memory) | Releases the input memory to which the [OH_NN_Memory](_o_h___n_n___memory.md) instance points.  | 
| [OH_NNExecutor_DestroyOutputMemory](_neural_nework_runtime.md#oh_nnexecutor_destroyoutputmemory) ([OH_NNExecutor](_neural_nework_runtime.md#oh_nnexecutor) \*executor, uint32_t outputIndex, [OH_NN_Memory](_o_h___n_n___memory.md) \*\*memory) | Releases the output memory to which the [OH_NN_Memory](_o_h___n_n___memory.md) instance points.  | 
| [OH_NNExecutor_SetInputWithMemory](_neural_nework_runtime.md#oh_nnexecutor_setinputwithmemory) ([OH_NNExecutor](_neural_nework_runtime.md#oh_nnexecutor) \*executor, uint32_t inputIndex, const [OH_NN_Tensor](_o_h___n_n___tensor.md) \*tensor, const [OH_NN_Memory](_o_h___n_n___memory.md) \*memory) | Specifies the hardware shared memory pointed to by the [OH_NN_Memory](_o_h___n_n___memory.md) instance as the shared memory used by a single input.  | 
| [OH_NNExecutor_SetOutputWithMemory](_neural_nework_runtime.md#oh_nnexecutor_setoutputwithmemory) ([OH_NNExecutor](_neural_nework_runtime.md#oh_nnexecutor) \*executor, uint32_t outputIndex, const [OH_NN_Memory](_o_h___n_n___memory.md) \*memory) | Specifies the hardware shared memory pointed to by the [OH_NN_Memory](_o_h___n_n___memory.md) instance as the shared memory used by a single output.  | 
| [OH_NNExecutor_Destroy](_neural_nework_runtime.md#oh_nnexecutor_destroy) ([OH_NNExecutor](_neural_nework_runtime.md#oh_nnexecutor) \*\*executor) | Destroys an executor instance to release the memory occupied by the executor.  | 
| [OH_NNDevice_GetAllDevicesID](_neural_nework_runtime.md#oh_nndevice_getalldevicesid) (const size_t \*\*allDevicesID, uint32_t \*deviceCount) | Obtains the ID of the device connected to Neural Network Runtime.  | 
| [OH_NNDevice_GetName](_neural_nework_runtime.md#oh_nndevice_getname) (size_t deviceID, const char \*\*name) | Obtains the name of the specified device.  | 
| [OH_NNDevice_GetType](_neural_nework_runtime.md#oh_nndevice_gettype) (size_t deviceID, [OH_NN_DeviceType](_neural_nework_runtime.md#oh_nn_devicetype) \*deviceType) | Obtains the type information of the specified device.  | 
