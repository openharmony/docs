# neural_network_runtime.h


## 概述

Neural Network Runtime部件接口定义，AI推理框架通过Neural Network Runtime提供的Native接口，完成模型构造与编译，并在加速硬件上执行推理计算。

**起始版本：**

9

**相关模块：**

[NeuralNeworkRuntime](_neural_nework_runtime.md)


## 汇总


### 函数

| 函数名称 | 描述 | 
| -------- | -------- |
| [OH_NNModel_Construct](_neural_nework_runtime.md#oh_nnmodel_construct) (void) | 创建[OH_NNModel](_neural_nework_runtime.md#oh_nnmodel)类型的模型实例，搭配OH_NNModel模块提供的其他接口，完成模型实例的构造。 | 
| [OH_NNModel_AddTensor](_neural_nework_runtime.md#oh_nnmodel_addtensor) (OH_NNModel \*model, const OH_NN_Tensor \*tensor) | 向模型实例中添加张量。 | 
| [OH_NNModel_SetTensorData](_neural_nework_runtime.md#oh_nnmodel_settensordata) (OH_NNModel \*model, uint32_t index, const void \*dataBuffer, size_t length) | 设置张量的数值。 | 
| [OH_NNModel_AddOperation](_neural_nework_runtime.md#oh_nnmodel_addoperation) (OH_NNModel \*model, OH_NN_OperationType op, const OH_NN_UInt32Array \*paramIndices, const OH_NN_UInt32Array \*inputIndices, const OH_NN_UInt32Array \*outputIndices) | 向模型实例中添加算子。 | 
| [OH_NNModel_SpecifyInputsAndOutputs](_neural_nework_runtime.md#oh_nnmodel_specifyinputsandoutputs) (OH_NNModel \*model, const OH_NN_UInt32Array \*inputIndices, const OH_NN_UInt32Array \*outputIndices) | 指定模型的输入输出。 | 
| [OH_NNModel_Finish](_neural_nework_runtime.md#oh_nnmodel_finish) (OH_NNModel \*model) | 完成模型构图。 | 
| [OH_NNModel_Destroy](_neural_nework_runtime.md#oh_nnmodel_destroy) (OH_NNModel \*\*model) | 释放模型实例。 | 
| [OH_NNModel_GetAvailableOperations](_neural_nework_runtime.md#oh_nnmodel_getavailableoperations) (OH_NNModel \*model, size_t deviceID, const bool \*\*isSupported, uint32_t \*opCount) | 查询硬件对模型内所有算子的支持情况，通过布尔值序列指示支持情况。 | 
| [OH_NNCompilation_Construct](_neural_nework_runtime.md#oh_nncompilation_construct) (const OH_NNModel \*model) | 创建[OH_NNCompilation](_neural_nework_runtime.md#oh_nncompilation)类型的编译实例。 | 
| [OH_NNCompilation_SetDevice](_neural_nework_runtime.md#oh_nncompilation_setdevice) (OH_NNCompilation \*compilation, size_t deviceID) | 指定模型编译和计算的硬件。 | 
| [OH_NNCompilation_SetCache](_neural_nework_runtime.md#oh_nncompilation_setcache) (OH_NNCompilation \*compilation, const char \*cachePath, uint32_t version) | 设置编译后的模型缓存路径和缓存版本。 | 
| [OH_NNCompilation_SetPerformanceMode](_neural_nework_runtime.md#oh_nncompilation_setperformancemode) (OH_NNCompilation \*compilation, OH_NN_PerformanceMode performanceMode) | 设置模型计算的性能模式。 | 
| [OH_NNCompilation_SetPriority](_neural_nework_runtime.md#oh_nncompilation_setpriority) (OH_NNCompilation \*compilation, OH_NN_Priority priority) | 设置模型计算的优先级。 | 
| [OH_NNCompilation_EnableFloat16](_neural_nework_runtime.md#oh_nncompilation_enablefloat16) (OH_NNCompilation \*compilation, bool enableFloat16) | 是否以float16的浮点数精度计算。 | 
| [OH_NNCompilation_Build](_neural_nework_runtime.md#oh_nncompilation_build) (OH_NNCompilation \*compilation) | 进行模型编译。 | 
| [OH_NNCompilation_Destroy](_neural_nework_runtime.md#oh_nncompilation_destroy) (OH_NNCompilation \*\*compilation) | 释放Compilation对象。 | 
| [OH_NNExecutor_Construct](_neural_nework_runtime.md#oh_nnexecutor_construct) (OH_NNCompilation \*compilation) | 创建[OH_NNExecutor](_neural_nework_runtime.md#oh_nnexecutor)类型的执行器实例。 | 
| [OH_NNExecutor_SetInput](_neural_nework_runtime.md#oh_nnexecutor_setinput) (OH_NNExecutor \*executor, uint32_t inputIndex, const OH_NN_Tensor \*tensor, const void \*dataBuffer, size_t length) | 设置模型单个输入的数据。 | 
| [OH_NNExecutor_SetOutput](_neural_nework_runtime.md#oh_nnexecutor_setoutput) (OH_NNExecutor \*executor, uint32_t outputIndex, void \*dataBuffer, size_t length) | 设置模型单个输出的缓冲区。 | 
| [OH_NNExecutor_GetOutputShape](_neural_nework_runtime.md#oh_nnexecutor_getoutputshape) (OH_NNExecutor \*executor, uint32_t outputIndex, int32_t \*\*shape, uint32_t \*shapeLength) | 获取输出张量的维度信息。 | 
| [OH_NNExecutor_Run](_neural_nework_runtime.md#oh_nnexecutor_run) (OH_NNExecutor \*executor) | 执行推理。 | 
| [OH_NNExecutor_AllocateInputMemory](_neural_nework_runtime.md#oh_nnexecutor_allocateinputmemory) (OH_NNExecutor \*executor, uint32_t inputIndex, size_t length) | 在硬件上为单个输入申请共享内存。 | 
| [OH_NNExecutor_AllocateOutputMemory](_neural_nework_runtime.md#oh_nnexecutor_allocateoutputmemory) (OH_NNExecutor \*executor, uint32_t outputIndex, size_t length) | 在硬件上为单个输出申请共享内存。 | 
| [OH_NNExecutor_DestroyInputMemory](_neural_nework_runtime.md#oh_nnexecutor_destroyinputmemory) (OH_NNExecutor \*executor, uint32_t inputIndex, OH_NN_Memory \*\*memory) | 释放[OH_NN_Memory](_o_h___n_n___memory.md)实例指向的输入内存。 | 
| [OH_NNExecutor_DestroyOutputMemory](_neural_nework_runtime.md#oh_nnexecutor_destroyoutputmemory) (OH_NNExecutor \*executor, uint32_t outputIndex, OH_NN_Memory \*\*memory) | 释放[OH_NN_Memory](_o_h___n_n___memory.md)实例指向的输出内存。 | 
| [OH_NNExecutor_SetInputWithMemory](_neural_nework_runtime.md#oh_nnexecutor_setinputwithmemory) (OH_NNExecutor \*executor, uint32_t inputIndex, const OH_NN_Tensor \*tensor, const OH_NN_Memory \*memory) | 将[OH_NN_Memory](_o_h___n_n___memory.md)实例指向的硬件共享内存，指定为单个输入使用的共享内存。 | 
| [OH_NNExecutor_SetOutputWithMemory](_neural_nework_runtime.md#oh_nnexecutor_setoutputwithmemory) (OH_NNExecutor \*executor, uint32_t outputIndex, const OH_NN_Memory \*memory) | 将[OH_NN_Memory](_o_h___n_n___memory.md)实例指向的硬件共享内存，指定为单个输出使用的共享内存。 | 
| [OH_NNExecutor_Destroy](_neural_nework_runtime.md#oh_nnexecutor_destroy) (OH_NNExecutor \*\*executor) | 销毁执行器实例，释放执行器占用的内存。 | 
| [OH_NNDevice_GetAllDevicesID](_neural_nework_runtime.md#oh_nndevice_getalldevicesid) (const size_t \*\*allDevicesID, uint32_t \*deviceCount) | 获取对接到 Neural Network Runtime 的硬件ID。 | 
| [OH_NNDevice_GetName](_neural_nework_runtime.md#oh_nndevice_getname) (size_t deviceID, const char \*\*name) | 获取指定硬件的类型信息。 | 
| [OH_NNDevice_GetType](_neural_nework_runtime.md#oh_nndevice_gettype) (size_t deviceID, [OH_NN_DeviceType](_neural_nework_runtime.md#oh_nn_devicetype) \*deviceType) | 获取指定硬件的类别信息。 | 
