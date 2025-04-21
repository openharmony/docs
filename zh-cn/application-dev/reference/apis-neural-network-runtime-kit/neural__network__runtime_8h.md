# neural_network_runtime.h


## 概述

Neural Network Runtime模块接口定义，AI推理框架使用Neural Network Runtime提供的Native接口，完成模型构建。

注意：Neural Network Runtime的接口目前均不支持多线程并发调用。

**引用文件：**&lt;neural_network_runtime/neural_network_runtime.h&gt;

**库：** libneural_network_runtime.so

**系统能力：** SystemCapability.Ai.NeuralNetworkRuntime

**起始版本：** 9

**相关模块：**[NeuralNetworkRuntime](_neural_network_runtime.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [NN_QuantParam](_neural_network_runtime.md#nn_quantparam) \* [OH_NNQuantParam_Create](_neural_network_runtime.md#oh_nnquantparam_create) () | 创建一个[NN_QuantParam](_neural_network_runtime.md#nn_quantparam)量化参数实例。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNQuantParam_SetScales](_neural_network_runtime.md#oh_nnquantparam_setscales) ([NN_QuantParam](_neural_network_runtime.md#nn_quantparam) \*quantParams, const double \*scales, size_t quantCount) | 设置[NN_QuantParam](_neural_network_runtime.md#nn_quantparam)的缩放系数。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNQuantParam_SetZeroPoints](_neural_network_runtime.md#oh_nnquantparam_setzeropoints) ([NN_QuantParam](_neural_network_runtime.md#nn_quantparam) \*quantParams, const int32_t \*zeroPoints, size_t quantCount) | 设置[NN_QuantParam](_neural_network_runtime.md#nn_quantparam)的零点。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNQuantParam_SetNumBits](_neural_network_runtime.md#oh_nnquantparam_setnumbits) ([NN_QuantParam](_neural_network_runtime.md#nn_quantparam) \*quantParams, const uint32_t \*numBits, size_t quantCount) | 设置[NN_QuantParam](_neural_network_runtime.md#nn_quantparam)的量化位数。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNQuantParam_Destroy](_neural_network_runtime.md#oh_nnquantparam_destroy) ([NN_QuantParam](_neural_network_runtime.md#nn_quantparam) \*\*quantParams) | 销毁[NN_QuantParam](_neural_network_runtime.md#nn_quantparam)实例。 | 
| [OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \* [OH_NNModel_Construct](_neural_network_runtime.md#oh_nnmodel_construct) (void) | 创建[OH_NNModel](_neural_network_runtime.md#oh_nnmodel)类型的模型实例，搭配OH_NNModel模块提供的其他接口，完成模型实例的构造。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_AddTensorToModel](_neural_network_runtime.md#oh_nnmodel_addtensortomodel) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model, const [NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \*tensorDesc) | 向模型实例中添加张量。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_SetTensorData](_neural_network_runtime.md#oh_nnmodel_settensordata) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model, uint32_t index, const void \*dataBuffer, size_t length) | 设置张量的数值。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_SetTensorQuantParams](_neural_network_runtime.md#oh_nnmodel_settensorquantparams) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model, uint32_t index, [NN_QuantParam](_neural_network_runtime.md#nn_quantparam) \*quantParam) | 设置张量的量化参数，参考[NN_QuantParam](_neural_network_runtime.md#nn_quantparam)。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_SetTensorType](_neural_network_runtime.md#oh_nnmodel_settensortype) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model, uint32_t index, [OH_NN_TensorType](_neural_network_runtime.md#oh_nn_tensortype) tensorType) | 设置张量的类型，参考[OH_NN_TensorType](_neural_network_runtime.md#oh_nn_tensortype)。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_AddOperation](_neural_network_runtime.md#oh_nnmodel_addoperation) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model, [OH_NN_OperationType](_neural_network_runtime.md#oh_nn_operationtype) op, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*paramIndices, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*inputIndices, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*outputIndices) | 向模型实例中添加算子。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_SpecifyInputsAndOutputs](_neural_network_runtime.md#oh_nnmodel_specifyinputsandoutputs) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*inputIndices, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*outputIndices) | 指定模型的输入和输出张量的索引值。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_Finish](_neural_network_runtime.md#oh_nnmodel_finish) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model) | 完成模型构图。 | 
| void [OH_NNModel_Destroy](_neural_network_runtime.md#oh_nnmodel_destroy) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*\*model) | 销毁模型实例。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_GetAvailableOperations](_neural_network_runtime.md#oh_nnmodel_getavailableoperations) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model, size_t deviceID, const bool \*\*isSupported, uint32_t \*opCount) | 查询硬件对模型内所有算子的支持情况，通过布尔值序列指示支持情况。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNModel_AddTensor](_neural_network_runtime.md#oh_nnmodel_addtensor) ([OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model, const [OH_NN_Tensor](_o_h___n_n___tensor.md) \*tensor) | 向模型实例中添加张量。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNExecutor_SetInput](_neural_network_runtime.md#oh_nnexecutor_setinput) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, uint32_t inputIndex, const [OH_NN_Tensor](_o_h___n_n___tensor.md) \*tensor, const void \*dataBuffer, size_t length) | 设置模型单个输入的数据。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNExecutor_SetOutput](_neural_network_runtime.md#oh_nnexecutor_setoutput) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, uint32_t outputIndex, void \*dataBuffer, size_t length) | 设置模型单个输出的内存。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNExecutor_Run](_neural_network_runtime.md#oh_nnexecutor_run) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor) | 执行推理。 | 
| [OH_NN_Memory](_o_h___n_n___memory.md) \* [OH_NNExecutor_AllocateInputMemory](_neural_network_runtime.md#oh_nnexecutor_allocateinputmemory) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, uint32_t inputIndex, size_t length) | 在硬件上为单个输入申请共享内存。 | 
| [OH_NN_Memory](_o_h___n_n___memory.md) \* [OH_NNExecutor_AllocateOutputMemory](_neural_network_runtime.md#oh_nnexecutor_allocateoutputmemory) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, uint32_t outputIndex, size_t length) | 在硬件上为单个输出申请共享内存。 | 
| void [OH_NNExecutor_DestroyInputMemory](_neural_network_runtime.md#oh_nnexecutor_destroyinputmemory) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, uint32_t inputIndex, [OH_NN_Memory](_o_h___n_n___memory.md) \*\*memory) | 释放[OH_NN_Memory](_o_h___n_n___memory.md)实例指向的输入内存。 | 
| void [OH_NNExecutor_DestroyOutputMemory](_neural_network_runtime.md#oh_nnexecutor_destroyoutputmemory) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, uint32_t outputIndex, [OH_NN_Memory](_o_h___n_n___memory.md) \*\*memory) | 释放[OH_NN_Memory](_o_h___n_n___memory.md)实例指向的输出内存。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNExecutor_SetInputWithMemory](_neural_network_runtime.md#oh_nnexecutor_setinputwithmemory) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, uint32_t inputIndex, const [OH_NN_Tensor](_o_h___n_n___tensor.md) \*tensor, const [OH_NN_Memory](_o_h___n_n___memory.md) \*memory) | 将[OH_NN_Memory](_o_h___n_n___memory.md)实例指向的硬件共享内存，并指定为单个输入使用的内存。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode)[OH_NNExecutor_SetOutputWithMemory](_neural_network_runtime.md#oh_nnexecutor_setoutputwithmemory) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, uint32_t outputIndex, const [OH_NN_Memory](_o_h___n_n___memory.md) \*memory) | 将[OH_NN_Memory](_o_h___n_n___memory.md)实例指向的硬件共享内存，并指定为单个输出使用的内存。 | 
