# neural_network_core.h


## 概述

Neural Network Core模块接口定义，AI推理框架使用Neural Network Core提供的Native接口，完成模型编译，并在加速硬件上执行推理和计算。

部分接口定义从neural_network_runtime.h移动至此头文件统一呈现，对于此类接口，API version 11 版本之前即支持使用，各版本均可正常使用。

Neural Network Core的接口目前均不支持多线程并发调用。

**引用文件：**&lt;neural_network_runtime/neural_network_core.h&gt;

**库：** libneural_network_core.so

**系统能力：** SystemCapability.Ai.NeuralNetworkRuntime

**起始版本：** 11

**相关模块：**[NeuralNetworkRuntime](_neural_network_runtime.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NNCompilation](_neural_network_runtime.md#oh_nncompilation) \* [OH_NNCompilation_Construct](_neural_network_runtime.md#oh_nncompilation_construct) (const [OH_NNModel](_neural_network_runtime.md#oh_nnmodel) \*model) | 创建[OH_NNCompilation](_neural_network_runtime.md#oh_nncompilation)类型的编译实例。 | 
| [OH_NNCompilation](_neural_network_runtime.md#oh_nncompilation) \* [OH_NNCompilation_ConstructWithOfflineModelFile](_neural_network_runtime.md#oh_nncompilation_constructwithofflinemodelfile) (const char \*modelPath) | 基于离线模型文件创建编译实例。 | 
| [OH_NNCompilation](_neural_network_runtime.md#oh_nncompilation) \* [OH_NNCompilation_ConstructWithOfflineModelBuffer](_neural_network_runtime.md#oh_nncompilation_constructwithofflinemodelbuffer) (const void \*modelBuffer, size_t modelSize) | 基于离线模型文件内存创建编译实例。 | 
| [OH_NNCompilation](_neural_network_runtime.md#oh_nncompilation) \* [OH_NNCompilation_ConstructForCache](_neural_network_runtime.md#oh_nncompilation_constructforcache) () | 创建一个空的编译实例，以便稍后从模型缓存中恢复。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNCompilation_ExportCacheToBuffer](_neural_network_runtime.md#oh_nncompilation_exportcachetobuffer) ([OH_NNCompilation](_neural_network_runtime.md#oh_nncompilation) \*compilation, const void \*buffer, size_t length, size_t \*modelSize) | 将模型缓存写入到指定内存区域。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNCompilation_ImportCacheFromBuffer](_neural_network_runtime.md#oh_nncompilation_importcachefrombuffer) ([OH_NNCompilation](_neural_network_runtime.md#oh_nncompilation) \*compilation, const void \*buffer, size_t modelSize) | 从指定内存区域读取模型缓存。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNCompilation_AddExtensionConfig](_neural_network_runtime.md#oh_nncompilation_addextensionconfig) ([OH_NNCompilation](_neural_network_runtime.md#oh_nncompilation) \*compilation, const char \*configName, const void \*configValue, const size_t configValueSize) | 为自定义硬件属性添加扩展配置。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNCompilation_SetDevice](_neural_network_runtime.md#oh_nncompilation_setdevice) ([OH_NNCompilation](_neural_network_runtime.md#oh_nncompilation) \*compilation, size_t deviceID) | 指定模型编译和计算的硬件。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNCompilation_SetCache](_neural_network_runtime.md#oh_nncompilation_setcache) ([OH_NNCompilation](_neural_network_runtime.md#oh_nncompilation) \*compilation, const char \*cachePath, uint32_t version) | 设置编译模型的缓存目录和版本。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNCompilation_SetPerformanceMode](_neural_network_runtime.md#oh_nncompilation_setperformancemode) ([OH_NNCompilation](_neural_network_runtime.md#oh_nncompilation) \*compilation, [OH_NN_PerformanceMode](_neural_network_runtime.md#oh_nn_performancemode) performanceMode) | 设置模型计算的性能模式。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNCompilation_SetPriority](_neural_network_runtime.md#oh_nncompilation_setpriority) ([OH_NNCompilation](_neural_network_runtime.md#oh_nncompilation) \*compilation, [OH_NN_Priority](_neural_network_runtime.md#oh_nn_priority) priority) | 设置模型计算的优先级。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNCompilation_EnableFloat16](_neural_network_runtime.md#oh_nncompilation_enablefloat16) ([OH_NNCompilation](_neural_network_runtime.md#oh_nncompilation) \*compilation, bool enableFloat16) | 是否以float16的浮点数精度计算。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNCompilation_Build](_neural_network_runtime.md#oh_nncompilation_build) ([OH_NNCompilation](_neural_network_runtime.md#oh_nncompilation) \*compilation) | 执行模型编译。 | 
| void [OH_NNCompilation_Destroy](_neural_network_runtime.md#oh_nncompilation_destroy) ([OH_NNCompilation](_neural_network_runtime.md#oh_nncompilation) \*\*compilation) | 销毁Compilation实例。 | 
| [NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \* [OH_NNTensorDesc_Create](_neural_network_runtime.md#oh_nntensordesc_create) () | 创建一个[NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc)实例。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNTensorDesc_Destroy](_neural_network_runtime.md#oh_nntensordesc_destroy) ([NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \*\*tensorDesc) | 释放一个[NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc)实例。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNTensorDesc_SetName](_neural_network_runtime.md#oh_nntensordesc_setname) ([NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \*tensorDesc, const char \*name) | 设置[NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc)的名称。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNTensorDesc_GetName](_neural_network_runtime.md#oh_nntensordesc_getname) (const [NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \*tensorDesc, const char \*\*name) | 获取[NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc)的名称。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNTensorDesc_SetDataType](_neural_network_runtime.md#oh_nntensordesc_setdatatype) ([NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \*tensorDesc, [OH_NN_DataType](_neural_network_runtime.md#oh_nn_datatype) dataType) | 设置[NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc)的数据类型。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNTensorDesc_GetDataType](_neural_network_runtime.md#oh_nntensordesc_getdatatype) (const [NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \*tensorDesc, [OH_NN_DataType](_neural_network_runtime.md#oh_nn_datatype) \*dataType) | 获取[NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc)的数据类型。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNTensorDesc_SetShape](_neural_network_runtime.md#oh_nntensordesc_setshape) ([NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \*tensorDesc, const int32_t \*shape, size_t shapeLength) | 设置[NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc)的数据形状。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNTensorDesc_GetShape](_neural_network_runtime.md#oh_nntensordesc_getshape) (const [NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \*tensorDesc, int32_t \*\*shape, size_t \*shapeLength) | 获取[NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc)的形状。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNTensorDesc_SetFormat](_neural_network_runtime.md#oh_nntensordesc_setformat) ([NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \*tensorDesc, [OH_NN_Format](_neural_network_runtime.md#oh_nn_format) format) | 设置[NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc)的数据布局。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNTensorDesc_GetFormat](_neural_network_runtime.md#oh_nntensordesc_getformat) (const [NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \*tensorDesc, [OH_NN_Format](_neural_network_runtime.md#oh_nn_format) \*format) | 获取[NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc)的数据布局。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNTensorDesc_GetElementCount](_neural_network_runtime.md#oh_nntensordesc_getelementcount) (const [NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \*tensorDesc, size_t \*elementCount) | 获取[NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc)的元素个数。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNTensorDesc_GetByteSize](_neural_network_runtime.md#oh_nntensordesc_getbytesize) (const [NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \*tensorDesc, size_t \*byteSize) | 获取基于[NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc)的形状和数据类型计算的数据占用字节数。 | 
| [NN_Tensor](_neural_network_runtime.md#nn_tensor) \* [OH_NNTensor_Create](_neural_network_runtime.md#oh_nntensor_create) (size_t deviceID, [NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \*tensorDesc) | 从[NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc)创建一个[NN_Tensor](_neural_network_runtime.md#nn_tensor)实例。 | 
| [NN_Tensor](_neural_network_runtime.md#nn_tensor) \* [OH_NNTensor_CreateWithSize](_neural_network_runtime.md#oh_nntensor_createwithsize) (size_t deviceID, [NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \*tensorDesc, size_t size) | 按照指定内存大小和[NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc)创建[NN_Tensor](_neural_network_runtime.md#nn_tensor)实例。 | 
| [NN_Tensor](_neural_network_runtime.md#nn_tensor) \* [OH_NNTensor_CreateWithFd](_neural_network_runtime.md#oh_nntensor_createwithfd) (size_t deviceID, [NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \*tensorDesc, int fd, size_t size, size_t offset) | 按照指定共享内存的文件描述符和[NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc)创建{\@Link NN_Tensor}实例。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNTensor_Destroy](_neural_network_runtime.md#oh_nntensor_destroy) ([NN_Tensor](_neural_network_runtime.md#nn_tensor) \*\*tensor) | 销毁一个[NN_Tensor](_neural_network_runtime.md#nn_tensor)实例。 | 
| [NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \* [OH_NNTensor_GetTensorDesc](_neural_network_runtime.md#oh_nntensor_gettensordesc) (const [NN_Tensor](_neural_network_runtime.md#nn_tensor) \*tensor) | 获取[NN_Tensor](_neural_network_runtime.md#nn_tensor)的[NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc)实例。 | 
| void \* [OH_NNTensor_GetDataBuffer](_neural_network_runtime.md#oh_nntensor_getdatabuffer) (const [NN_Tensor](_neural_network_runtime.md#nn_tensor) \*tensor) | 获取[NN_Tensor](_neural_network_runtime.md#nn_tensor)数据的内存地址。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNTensor_GetFd](_neural_network_runtime.md#oh_nntensor_getfd) (const [NN_Tensor](_neural_network_runtime.md#nn_tensor) \*tensor, int \*fd) | 获取[NN_Tensor](_neural_network_runtime.md#nn_tensor)数据所在共享内存的文件描述符。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNTensor_GetSize](_neural_network_runtime.md#oh_nntensor_getsize) (const [NN_Tensor](_neural_network_runtime.md#nn_tensor) \*tensor, size_t \*size) | 获取[NN_Tensor](_neural_network_runtime.md#nn_tensor)数据所在共享内存的大小。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNTensor_GetOffset](_neural_network_runtime.md#oh_nntensor_getoffset) (const [NN_Tensor](_neural_network_runtime.md#nn_tensor) \*tensor, size_t \*offset) | 获取[NN_Tensor](_neural_network_runtime.md#nn_tensor)数据所在共享内存上的偏移量。 | 
| [OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \* [OH_NNExecutor_Construct](_neural_network_runtime.md#oh_nnexecutor_construct) ([OH_NNCompilation](_neural_network_runtime.md#oh_nncompilation) \*compilation) | 创建[OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor)执行器实例。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNExecutor_GetOutputShape](_neural_network_runtime.md#oh_nnexecutor_getoutputshape) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, uint32_t outputIndex, int32_t \*\*shape, uint32_t \*shapeLength) | 获取输出张量的维度信息。 | 
| void [OH_NNExecutor_Destroy](_neural_network_runtime.md#oh_nnexecutor_destroy) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*\*executor) | 销毁执行器实例，释放执行器占用的内存。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNExecutor_GetInputCount](_neural_network_runtime.md#oh_nnexecutor_getinputcount) (const [OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, size_t \*inputCount) | 获取输入张量的数量。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNExecutor_GetOutputCount](_neural_network_runtime.md#oh_nnexecutor_getoutputcount) (const [OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, size_t \*outputCount) | 获取输出张量的数量。 | 
| [NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \* [OH_NNExecutor_CreateInputTensorDesc](_neural_network_runtime.md#oh_nnexecutor_createinputtensordesc) (const [OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, size_t index) | 由指定索引值创建一个输入张量的描述。 | 
| [NN_TensorDesc](_neural_network_runtime.md#nn_tensordesc) \* [OH_NNExecutor_CreateOutputTensorDesc](_neural_network_runtime.md#oh_nnexecutor_createoutputtensordesc) (const [OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, size_t index) | 由指定索引值创建一个输出张量的描述。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNExecutor_GetInputDimRange](_neural_network_runtime.md#oh_nnexecutor_getinputdimrange) (const [OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, size_t index, size_t \*\*minInputDims, size_t \*\*maxInputDims, size_t \*shapeLength) | 获取所有输入张量的维度范围。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNExecutor_SetOnRunDone](_neural_network_runtime.md#oh_nnexecutor_setonrundone) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, [NN_OnRunDone](_neural_network_runtime.md#nn_onrundone) onRunDone) | 设置异步推理结束后的回调处理函数。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNExecutor_SetOnServiceDied](_neural_network_runtime.md#oh_nnexecutor_setonservicedied) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, [NN_OnServiceDied](_neural_network_runtime.md#nn_onservicedied) onServiceDied) | 设置异步推理执行期间设备驱动服务突然死亡时的回调处理函数。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNExecutor_RunSync](_neural_network_runtime.md#oh_nnexecutor_runsync) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, [NN_Tensor](_neural_network_runtime.md#nn_tensor) \*inputTensor[], size_t inputCount, [NN_Tensor](_neural_network_runtime.md#nn_tensor) \*outputTensor[], size_t outputCount) | 执行同步推理。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNExecutor_RunAsync](_neural_network_runtime.md#oh_nnexecutor_runasync) ([OH_NNExecutor](_neural_network_runtime.md#oh_nnexecutor) \*executor, [NN_Tensor](_neural_network_runtime.md#nn_tensor) \*inputTensor[], size_t inputCount, [NN_Tensor](_neural_network_runtime.md#nn_tensor) \*outputTensor[], size_t outputCount, int32_t timeout, void \*userData) | 执行异步推理。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNDevice_GetAllDevicesID](_neural_network_runtime.md#oh_nndevice_getalldevicesid) (const size_t \*\*allDevicesID, uint32_t \*deviceCount) | 获取对接到 Neural Network Runtime 的硬件ID。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNDevice_GetName](_neural_network_runtime.md#oh_nndevice_getname) (size_t deviceID, const char \*\*name) | 获取指定硬件的名称。 | 
| [OH_NN_ReturnCode](_neural_network_runtime.md#oh_nn_returncode) [OH_NNDevice_GetType](_neural_network_runtime.md#oh_nndevice_gettype) (size_t deviceID, [OH_NN_DeviceType](_neural_network_runtime.md#oh_nn_devicetype) \*deviceType) | 获取指定硬件的类别信息。 | 
