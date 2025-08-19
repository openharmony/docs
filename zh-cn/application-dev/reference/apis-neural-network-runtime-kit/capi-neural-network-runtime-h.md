# neural_network_runtime.h
<!--Kit: Neural Network Runtime Kit-->
<!--Subsystem: AI-->
<!--Owner: @GbuzhidaoR-->
<!--Designer: @GbuzhidaoR-->
<!--Tester: @GbuzhidaoR-->
<!--Adviser: @ge-yafang-->

## 概述

Neural Network Runtime模块接口定义，AI推理框架使用Neural Network Runtime提供的Native接口，完成模型构建。

Neural Network Runtime的接口目前均不支持多线程并发调用。

**引用文件：** <neural_network_runtime/neural_network_runtime.h>

**库：** libneural_network_runtime.so

**系统能力：** SystemCapability.Ai.NeuralNetworkRuntime

**起始版本：** 9

**相关模块：** [NeuralNetworkRuntime](capi-neuralnetworkruntime.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [NN_QuantParam *OH_NNQuantParam_Create()](#oh_nnquantparam_create) | 创建一个[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)量化参数实例。 |
| [OH_NN_ReturnCode OH_NNQuantParam_SetScales(NN_QuantParam *quantParams, const double *scales, size_t quantCount)](#oh_nnquantparam_setscales) | 设置[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)的缩放系数。<br>参数<b>quantCount</b>是张量中量化参数的数量，例如对于per-channel量化，<b>quantCount</b>就是通道数量。 |
| [OH_NN_ReturnCode OH_NNQuantParam_SetZeroPoints(NN_QuantParam *quantParams, const int32_t *zeroPoints, size_t quantCount)](#oh_nnquantparam_setzeropoints) | 设置[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)的零点。<br>参数<b>quantCount</b>是张量中量化参数的数量，例如对于per-channel量化，<b>quantCount</b>就是通道数量。 |
| [OH_NN_ReturnCode OH_NNQuantParam_SetNumBits(NN_QuantParam *quantParams, const uint32_t *numBits, size_t quantCount)](#oh_nnquantparam_setnumbits) | 设置[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)的量化位数。<br>参数<b>quantCount</b>是张量中量化参数的数量，例如对于per-channel量化，<b>quantCount</b>就是通道数量。 |
| [OH_NN_ReturnCode OH_NNQuantParam_Destroy(NN_QuantParam **quantParams)](#oh_nnquantparam_destroy) | 销毁[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)实例。 <br>当设置[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)实例到一个[NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md)中后，如果不再使用该实例，需要销毁它以避免内存泄漏。 <br>如果<b>quantParams</b>或<b>*quantParams</b>是空指针，那么该接口仅打印警告日志，不会执行销毁操作。 |
| [OH_NNModel *OH_NNModel_Construct(void)](#oh_nnmodel_construct) | 创建[OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md)类型的模型实例，搭配OH_NNModel模块提供的其他接口，完成模型实例的构造。 |
| [OH_NN_ReturnCode OH_NNModel_AddTensorToModel(OH_NNModel *model, const NN_TensorDesc *tensorDesc)](#oh_nnmodel_addtensortomodel) | 向模型实例中添加张量。<br>Neural Network Runtime模型中的数据节点和算子参数均由模型的张量构成。 |
| [OH_NN_ReturnCode OH_NNModel_SetTensorData(OH_NNModel *model, uint32_t index, const void *dataBuffer, size_t length)](#oh_nnmodel_settensordata) | 设置张量的数值。 对于具有常量值的张量（如模型的权重），需要在构图阶段使用该接口设置数值。张量的索引值根据张量添加进模型的顺序决定，张量的添加参考[OH_NNModel_AddTensorToModel](capi-neural-network-runtime-h.md#oh_nnmodel_addtensortomodel)。 |
| [OH_NN_ReturnCode OH_NNModel_SetTensorQuantParams(OH_NNModel *model, uint32_t index, NN_QuantParam *quantParam)](#oh_nnmodel_settensorquantparams) | 设置张量的量化参数，参考[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)。 |
| [OH_NN_ReturnCode OH_NNModel_SetTensorType(OH_NNModel *model, uint32_t index, OH_NN_TensorType tensorType)](#oh_nnmodel_settensortype) | 设置张量的类型，参考[OH_NN_TensorType](capi-neural-network-runtime-type-h.md#oh_nn_tensortype)。 |
| [OH_NN_ReturnCode OH_NNModel_AddOperation(OH_NNModel *model,OH_NN_OperationType op,const OH_NN_UInt32Array *paramIndices,const OH_NN_UInt32Array *inputIndices,const OH_NN_UInt32Array *outputIndices)](#oh_nnmodel_addoperation) | 向模型实例中添加算子。 |
| [OH_NN_ReturnCode OH_NNModel_SpecifyInputsAndOutputs(OH_NNModel *model,const OH_NN_UInt32Array *inputIndices,const OH_NN_UInt32Array *outputIndices)](#oh_nnmodel_specifyinputsandoutputs) | 指定模型的输入和输出张量的索引值。模型实例需要指定张量作为端到端的输入和输出张量。 |
| [OH_NN_ReturnCode OH_NNModel_Finish(OH_NNModel *model)](#oh_nnmodel_finish) | 完成模型构图。完成模型拓扑结构的搭建后，调用该接口指示构图已完成。 |
| [void OH_NNModel_Destroy(OH_NNModel **model)](#oh_nnmodel_destroy) | 销毁模型实例。调用[OH_NNModel_Construct](capi-neural-network-runtime-h.md#oh_nnmodel_construct)创建的模型实例需要调用该接口主动销毁，否则将造成内存泄漏。 如果model为空指针或者*model为空指针，该接口仅打印警告日志，不执行销毁操作。 |
| [OH_NN_ReturnCode OH_NNModel_GetAvailableOperations(OH_NNModel *model,size_t deviceID,const bool **isSupported,uint32_t *opCount)](#oh_nnmodel_getavailableoperations) | 查询硬件对模型内所有算子的支持情况，通过布尔值序列指示支持情况。 |
| [OH_NN_ReturnCode OH_NNModel_AddTensor(OH_NNModel *model, const OH_NN_Tensor *tensor)](#oh_nnmodel_addtensor) | 向模型实例中添加张量。<br>Neural Network Runtime模型中的数据节点和算子参数均由模型的张量构成，该接口根据tensor，向model实例中添加张量。 |
| [OH_NN_ReturnCode OH_NNExecutor_SetInput(OH_NNExecutor *executor,uint32_t inputIndex,const OH_NN_Tensor *tensor,const void *dataBuffer,size_t length)](#oh_nnexecutor_setinput) | 设置模型单个输入的数据。该接口将dataBuffer中，长度为length个字节的数据，拷贝到底层硬件的共享内存。 |
| [OH_NN_ReturnCode OH_NNExecutor_SetOutput(OH_NNExecutor *executor,uint32_t outputIndex,void *dataBuffer,size_t length)](#oh_nnexecutor_setoutput) | 设置模型单个输出的内存。<br>该接口将dataBuffer指向的内存与outputIndex指定的输出绑定，内存的长度由length指定。 |
| [OH_NN_ReturnCode OH_NNExecutor_Run(OH_NNExecutor *executor)](#oh_nnexecutor_run) | 执行推理。 在执行器关联的硬件上，执行模型的端到端推理计算。 |
| [OH_NN_Memory *OH_NNExecutor_AllocateInputMemory(OH_NNExecutor *executor, uint32_t inputIndex, size_t length)](#oh_nnexecutor_allocateinputmemory) | 在硬件上为单个输入申请共享内存。 |
| [OH_NN_Memory *OH_NNExecutor_AllocateOutputMemory(OH_NNExecutor *executor, uint32_t outputIndex, size_t length)](#oh_nnexecutor_allocateoutputmemory) | 在硬件上为单个输出申请共享内存。 |
| [void OH_NNExecutor_DestroyInputMemory(OH_NNExecutor *executor, uint32_t inputIndex, OH_NN_Memory **memory)](#oh_nnexecutor_destroyinputmemory) | 释放[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)实例指向的输入内存。 调用[OH_NNExecutor_AllocateInputMemory](capi-neural-network-runtime-h.md#oh_nnexecutor_allocateinputmemory)创建的内存实例，需要主动调用该接口进行释放，否则将造成内存泄漏。 |
| [void OH_NNExecutor_DestroyOutputMemory(OH_NNExecutor *executor, uint32_t outputIndex, OH_NN_Memory **memory)](#oh_nnexecutor_destroyoutputmemory) | 释放[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)实例指向的输出内存。 调用[OH_NNExecutor_AllocateOutputMemory](capi-neural-network-runtime-h.md#oh_nnexecutor_allocateoutputmemory)创建的内存实例，需要主动调用该接口进行释放，否则将造成内存泄漏。outputIndex和memory的对应关系需要和创建内存实例时保持一致。 如果memory或*memory为空指针，该接口仅打印警告日志，不执行释放操作。 |
| [OH_NN_ReturnCode OH_NNExecutor_SetInputWithMemory(OH_NNExecutor *executor,uint32_t inputIndex,const OH_NN_Tensor *tensor,const OH_NN_Memory *memory)](#oh_nnexecutor_setinputwithmemory) | 将[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)实例指向的硬件共享内存，并指定为单个输入使用的内存。 |
| [OH_NN_ReturnCode OH_NNExecutor_SetOutputWithMemory(OH_NNExecutor *executor,uint32_t outputIndex,const OH_NN_Memory *memory)](#oh_nnexecutor_setoutputwithmemory) | 将[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)实例指向的硬件共享内存，并指定为单个输出使用的内存。 |

## 函数说明

### OH_NNQuantParam_Create()

```
NN_QuantParam *OH_NNQuantParam_Create()
```

**描述**

创建一个[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)量化参数实例。

创建[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)量化参数实例后，调用[OH_NNQuantParam_SetScales](capi-neural-network-runtime-h.md#oh_nnquantparam_setscales)、[OH_NNQuantParam_SetZeroPoints](capi-neural-network-runtime-h.md#oh_nnquantparam_setzeropoints)或[OH_NNQuantParam_SetNumBits](capi-neural-network-runtime-h.md#oh_nnquantparam_setnumbits)设置它的属性值，并调用[OH_NNModel_SetTensorQuantParams](capi-neural-network-runtime-h.md#oh_nnmodel_settensorquantparams)将它设置到[NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md)中。最后再调用[OH_NNQuantParam_Destroy](capi-neural-network-runtime-h.md#oh_nnquantparam_destroy)销毁它，以避免内存泄露。

**起始版本：** 11

**返回：**

| 类型 | 说明 |
| -- | -- |
| [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) * | 指向[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)实例的指针，如果创建失败就返回NULL。 |

### OH_NNQuantParam_SetScales()

```
OH_NN_ReturnCode OH_NNQuantParam_SetScales(NN_QuantParam *quantParams, const double *scales, size_t quantCount)
```

**描述**

设置[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)的缩放系数。

参数<b>quantCount</b>是张量中量化参数的数量，例如对于per-channel量化，<b>quantCount</b>就是通道数量。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) *quantParams | 指向[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)实例的指针。 |
| const double *scales | 张量中所有量化参数的缩放系数构成的数组。 |
| size_t quantCount | 张量中量化参数的数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |

### OH_NNQuantParam_SetZeroPoints()

```
OH_NN_ReturnCode OH_NNQuantParam_SetZeroPoints(NN_QuantParam *quantParams, const int32_t *zeroPoints, size_t quantCount)
```

**描述**

设置[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)的零点。

参数<b>quantCount</b>是张量中量化参数的数量，例如对于per-channel量化，<b>quantCount</b>就是通道数量。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) *quantParams | 指向[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)实例的指针。 |
| const int32_t *zeroPoints | 张量中所有量化参数的零点构成的数组。 |
| size_t quantCount | 张量中量化参数的数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |

### OH_NNQuantParam_SetNumBits()

```
OH_NN_ReturnCode OH_NNQuantParam_SetNumBits(NN_QuantParam *quantParams, const uint32_t *numBits, size_t quantCount)
```

**描述**

设置[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)的量化位数。

参数<b>quantCount</b>是张量中量化参数的数量，例如对于per-channel量化，<b>quantCount</b>就是通道数量。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) *quantParams | 指向[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)实例的指针。 |
| const uint32_t *numBits | 张量中所有量化参数的量化位数构成的数组。 |
| size_t quantCount | 张量中量化参数的数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |

### OH_NNQuantParam_Destroy()

```
OH_NN_ReturnCode OH_NNQuantParam_Destroy(NN_QuantParam **quantParams)
```

**描述**

销毁[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)实例。

当设置[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)实例到一个[NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md)中后，如果不再使用该实例，需要销毁它以避免内存泄漏。 <br>如果<b>quantParams</b>或<b>*quantParams</b>是空指针，那么该接口仅打印警告日志，不会执行销毁操作。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) **quantParams | 指向[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)实例的二级指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |

### OH_NNModel_Construct()

```
OH_NNModel *OH_NNModel_Construct(void)
```

**描述**

创建[OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md)类型的模型实例，搭配OH_NNModel模块提供的其他接口，完成模型实例的构造。

在开始构图前，先调用[OH_NNModel_Construct](capi-neural-network-runtime-h.md#oh_nnmodel_construct)创建模型实例，根据模型的拓扑结构，调用[OH_NNModel_AddTensorToModel](capi-neural-network-runtime-h.md#oh_nnmodel_addtensortomodel)、[OH_NNModel_AddOperation](capi-neural-network-runtime-h.md#oh_nnmodel_addoperation)和[OH_NNModel_SetTensorData](capi-neural-network-runtime-h.md#oh_nnmodel_settensordata)方法，填充模型的数据节点和算子节点；然后调用[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)指定模型的输入和输出；当构造完模型的拓扑结构，调用[OH_NNModel_Finish](capi-neural-network-runtime-h.md#oh_nnmodel_finish)完成模型的构建。

模型实例使用完毕后，需要调用[OH_NNModel_Destroy](capi-neural-network-runtime-h.md#oh_nnmodel_destroy)销毁模型实例，避免内存泄漏。

**起始版本：** 9

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) * | 返回一个指向[OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md)实例的指针，如果创建失败就返回NULL。 |

### OH_NNModel_AddTensorToModel()

```
OH_NN_ReturnCode OH_NNModel_AddTensorToModel(OH_NNModel *model, const NN_TensorDesc *tensorDesc)
```

**描述**

向模型实例中添加张量。

Neural Network Runtime模型中的数据节点和算子参数均由模型的张量构成。

该接口根据[NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md)向model实例中添加张量，张量添加的顺序是模型中记录张量的索引值。[OH_NNModel_SetTensorData](capi-neural-network-runtime-h.md#oh_nnmodel_settensordata)、[OH_NNModel_AddOperation](capi-neural-network-runtime-h.md#oh_nnmodel_addoperation)和[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)接口根据该索引值，指定不同的张量。

Neural Network Runtime支持动态形状的输入和输出张量。在添加动态形状的数据节点时，需要将tensor.dimensions中支持动态变化的维度设置为-1。例如可将一个四维tensor的dimensions设置为[1, -1, 2, 2]，表示其第二个维度支持动态变化。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | 指向[OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md)实例的指针。 |
| [const NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) *tensorDesc | [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md)张量的指针，[NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md)指定了添加到模型实例中张量的属性。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |

### OH_NNModel_SetTensorData()

```
OH_NN_ReturnCode OH_NNModel_SetTensorData(OH_NNModel *model, uint32_t index, const void *dataBuffer, size_t length)
```

**描述**

设置张量的数值。 对于具有常量值的张量（如模型的权重），需要在构图阶段使用该接口设置数值。

张量的索引值根据张量添加进模型的顺序决定，张量的添加参考[OH_NNModel_AddTensorToModel](capi-neural-network-runtime-h.md#oh_nnmodel_addtensortomodel)。

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | 指向[OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md)实例的指针。 |
| uint32_t index | 张量的索引值。 |
| const void *dataBuffer | 指向真实数据内存的指针。 |
| size_t length | 数据内存的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |

### OH_NNModel_SetTensorQuantParams()

```
OH_NN_ReturnCode OH_NNModel_SetTensorQuantParams(OH_NNModel *model, uint32_t index, NN_QuantParam *quantParam)
```

**描述**

设置张量的量化参数，参考[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | 指向[OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md)实例的指针。 |
| uint32_t index | 张量的索引值。 |
| [NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md) *quantParam | 指向[NN_QuantParam](capi-neuralnetworkruntime-nn-quantparam.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |

### OH_NNModel_SetTensorType()

```
OH_NN_ReturnCode OH_NNModel_SetTensorType(OH_NNModel *model, uint32_t index, OH_NN_TensorType tensorType)
```

**描述**

设置张量的类型，参考[OH_NN_TensorType](capi-neural-network-runtime-type-h.md#oh_nn_tensortype)。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | 指向[OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md)实例的指针。 |
| uint32_t index | 张量的索引值。 |
| [OH_NN_TensorType](capi-neural-network-runtime-type-h.md#oh_nn_tensortype) tensorType | 张量类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) |

### OH_NNModel_AddOperation()

```
OH_NN_ReturnCode OH_NNModel_AddOperation(OH_NNModel *model,OH_NN_OperationType op,const OH_NN_UInt32Array *paramIndices,const OH_NN_UInt32Array *inputIndices,const OH_NN_UInt32Array *outputIndices)
```

**描述**

向模型实例中添加算子。

该接口向模型实例中添加算子，算子类型由op指定，算子的参数、输入和输出由paramIndices、inputIndices和outputIndices指定。

该接口将对算子参数的属性和输入、输出张量的数量进行校验，这些属性需要在调用[OH_NNModel_AddTensorToModel](capi-neural-network-runtime-h.md#oh_nnmodel_addtensortomodel)添加张量时正确设置。

每个算子期望的参数、输入和输出属性请参考[OH_NN_OperationType](capi-neural-network-runtime-type-h.md#oh_nn_operationtype)。 

paramIndices、inputIndices和outputIndices中存储的是张量的索引值，每个索引值根据张量添加进模型的顺序决定，正确设置并添加算子要求准确设置每个张量的索引值。

张量的添加参考[OH_NNModel_AddTensorToModel](capi-neural-network-runtime-h.md#oh_nnmodel_addtensortomodel)。

如果添加算子时，添加了额外的参数（非算子需要的参数），该接口返回[OH_NN_INVALID_PARAMETER](capi-neural-network-runtime-type-h.md#oh_nn_returncode)；如果没有设置算子参数，则算子按默认值设置缺省的参数，默认值请参考[OH_NN_OperationType](capi-neural-network-runtime-type-h.md#oh_nn_operationtype)。

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | 指向[OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md)实例的指针。 |
| [OH_NN_OperationType](capi-neural-network-runtime-type-h.md#oh_nn_operationtype) op | 指定添加的算子类型，取值请参考[OH_NN_OperationType](capi-neural-network-runtime-type-h.md#oh_nn_operationtype)的枚举值。 |
| [const OH_NN_UInt32Array](capi-neuralnetworkruntime-oh-nn-uint32array.md) *paramIndices | OH_NN_UInt32Array实例的指针，设置算子的参数张量索引。 |
| [const OH_NN_UInt32Array](capi-neuralnetworkruntime-oh-nn-uint32array.md) *inputIndices | OH_NN_UInt32Array实例的指针，指定算子的输入张量索引。 |
| [const OH_NN_UInt32Array](capi-neuralnetworkruntime-oh-nn-uint32array.md) *outputIndices | OH_NN_UInt32Array实例的指针，设置算子的输出张量索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |

### OH_NNModel_SpecifyInputsAndOutputs()

```
OH_NN_ReturnCode OH_NNModel_SpecifyInputsAndOutputs(OH_NNModel *model,const OH_NN_UInt32Array *inputIndices,const OH_NN_UInt32Array *outputIndices)
```

**描述**

指定模型的输入和输出张量的索引值。

模型实例需要指定张量作为端到端的输入和输出张量。设置一个张量为输入或输出张量后，就不能再通过调用[OH_NNModel_SetTensorData](capi-neural-network-runtime-h.md#oh_nnmodel_settensordata)设置张量数据，而需要在执行阶段调用OH_NNExecutor的方法设置输入或输出张量数据。

张量的索引值根据张量添加进模型的顺序决定，张量的添加参考[OH_NNModel_AddTensorToModel](capi-neural-network-runtime-h.md#oh_nnmodel_addtensortomodel)。 暂时不支持异步设置模型输入和输出张量。

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | 指向[OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md)实例的指针。 |
| [const OH_NN_UInt32Array](capi-neuralnetworkruntime-oh-nn-uint32array.md) *inputIndices | OH_NN_UInt32Array实例的指针，指定算子的输入张量。 |
| [const OH_NN_UInt32Array](capi-neuralnetworkruntime-oh-nn-uint32array.md) *outputIndices | OH_NN_UInt32Array实例的指针，指定算子的输出张量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |

### OH_NNModel_Finish()

```
OH_NN_ReturnCode OH_NNModel_Finish(OH_NNModel *model)
```

**描述**

完成模型构图。

完成模型拓扑结构的搭建后，调用该接口指示构图已完成。

在调用该接口后，无法进行额外的构图操作，调用[OH_NNModel_AddTensorToModel](capi-neural-network-runtime-h.md#oh_nnmodel_addtensortomodel)、[OH_NNModel_AddOperation](capi-neural-network-runtime-h.md#oh_nnmodel_addoperation)、[OH_NNModel_SetTensorData](capi-neural-network-runtime-h.md#oh_nnmodel_settensordata)和[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)将返回[OH_NN_OPERATION_FORBIDDEN](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。

在调用[OH_NNModel_GetAvailableOperations](capi-neural-network-runtime-h.md#oh_nnmodel_getavailableoperations)和[OH_NNCompilation_Construct](capi-neural-network-core-h.md#oh_nncompilation_construct)之前，必须先调用该接口完成构图。

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | 指向[OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |

### OH_NNModel_Destroy()

```
void OH_NNModel_Destroy(OH_NNModel **model)
```

**描述**

销毁模型实例。

调用[OH_NNModel_Construct](capi-neural-network-runtime-h.md#oh_nnmodel_construct)创建的模型实例需要调用该接口主动销毁，否则将造成内存泄漏。

如果model为空指针或者*model为空指针，该接口仅打印警告日志，不执行销毁操作。

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) **model | 指向[OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md)实例的二级指针。模型实例销毁后，该接口会将*model主动设置为空指针。 |

### OH_NNModel_GetAvailableOperations()

```
OH_NN_ReturnCode OH_NNModel_GetAvailableOperations(OH_NNModel *model,size_t deviceID,const bool **isSupported,uint32_t *opCount)
```

**描述**

查询硬件对模型内所有算子的支持情况，通过布尔值序列指示支持情况。

查询底层硬件对模型实例内每个算子的支持情况，硬件由deviceID指定，结果将通过isSupported指向的数组表示。

如果支持第i个算子，则(\*isSupported)[i] == true，否则为false。 该接口成功执行后，(\*isSupported)将指向记录算子支持情况的bool数组，数组长度和模型实例的算子数量相等。

该数组对应的内存由Neural Network Runtime管理，在模型实例销毁或再次调用该接口后自动销毁。

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | 指向[OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md)实例的指针。 |
| size_t deviceID | 指定查询的硬件ID，通过[OH_NNDevice_GetAllDevicesID](capi-neural-network-core-h.md#oh_nndevice_getalldevicesid)获取。 |
| const bool **isSupported | 指向bool数组的指针。调用该接口时，要求(*isSupported)为空指针，否则返回[OH_NN_INVALID_PARAMETER](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |
| uint32_t *opCount | 模型实例中算子的数量，对应(*isSupported)数组的长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |

### OH_NNModel_AddTensor()

```
OH_NN_ReturnCode OH_NNModel_AddTensor(OH_NNModel *model, const OH_NN_Tensor *tensor)
```

**描述**

向模型实例中添加张量。

Neural Network Runtime模型中的数据节点和算子参数均由模型的张量构成，该接口根据tensor，向model实例中添加张量。

张量添加的顺序由模型中记录张量的索引值来确定，[OH_NNModel_SetTensorData](capi-neural-network-runtime-h.md#oh_nnmodel_settensordata)、[OH_NNModel_AddOperation](capi-neural-network-runtime-h.md#oh_nnmodel_addoperation)和[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)接口根据该索引值，指定不同的张量。

Neural Network Runtime支持动态形状输入和输出。

在添加动态形状的数据节点时，需要将tensor.dimensions中支持动态变化的维度设置为-1。例如可将一个四维tensor的dimensions设置为[1, -1, 2, 2]，表示其第二个维度支持动态变化。

**起始版本：** 9

**废弃版本：** 11

**替代接口：** [OH_NNModel_AddTensorToModel](capi-neural-network-runtime-h.md#oh_nnmodel_addtensortomodel)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | 指向[OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md)实例的指针。 |
| [const OH_NN_Tensor](capi-neuralnetworkruntime-oh-nn-tensor.md) *tensor | [OH_NN_Tensor](capi-neuralnetworkruntime-oh-nn-tensor.md)张量的指针，tensor指定了添加到模型实例中张量的属性。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |

### OH_NNExecutor_SetInput()

```
OH_NN_ReturnCode OH_NNExecutor_SetInput(OH_NNExecutor *executor,uint32_t inputIndex,const OH_NN_Tensor *tensor,const void *dataBuffer,size_t length)
```

**描述**

设置模型单个输入的数据。

该接口将dataBuffer中，长度为length个字节的数据，拷贝到底层硬件的共享内存。

inputIndex指定设置的输入，tensor用于设置输入张量的形状、数据类型、量化参数等信息。 

由于Neural Network Runtime支持动态输入形状的模型，在固定形状输入和动态形状输入的场景下，该接口采取不同的处理策略：

- 固定形状输入的场景：tensor各属性必须和构图阶段调用[OH_NNModel_AddTensor](capi-neural-network-runtime-h.md#oh_nnmodel_addtensor)添加的张量保持一致；
- 动态形状输入的场景：在构图阶段，由于动态输入的形状不确定，调用该接口时，要求tensor.dimensions中的每个值必须大于0，以确定执行计算阶段输入的形状。设置形状时，只允许调整数值为-1的维度。<br>假设在构图阶段，输入A的维度为[-1, 224, 224, 3]，调用该接口时，只能调整第一个维度的尺寸，如：[3, 224, 224, 3]。调整其他维度将返回[OH_NN_INVALID_PARAMETER](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。

**起始版本：** 9

**废弃版本：** 11

**替代接口：** [OH_NNExecutor_RunSync](capi-neural-network-core-h.md#oh_nnexecutor_runsync)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | 指向[OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md)实例的指针。 |
| uint32_t inputIndex | 输入的索引值，与调用[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)时输入数据的顺序一致。<br>假设调用[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)时，inputIndices为{1, 5, 9}，则在设置输入的阶段，三个输入的索引值分别为{0, 1, 2}。 |
| [const OH_NN_Tensor](capi-neuralnetworkruntime-oh-nn-tensor.md) *tensor | 设置输入数据对应的张量。 |
| const void *dataBuffer | 指向输入数据的指针。 |
| size_t length | 数据内存的字节长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |

### OH_NNExecutor_SetOutput()

```
OH_NN_ReturnCode OH_NNExecutor_SetOutput(OH_NNExecutor *executor,uint32_t outputIndex,void *dataBuffer,size_t length)
```

**描述**

设置模型单个输出的内存。

该接口将dataBuffer指向的内存与outputIndex指定的输出绑定，内存的长度由length指定。

调用[OH_NNExecutor_Run](capi-neural-network-runtime-h.md#oh_nnexecutor_run)完成单次模型推理后，Neural Network Runtime将比对dataBuffer指向的内存与输出数据的长度，根据不同情况，返回不同结果：

- 如果内存大小大于或等于数据长度：则推理后的结果将拷贝至内存，并返回[OH_NN_SUCCESS](capi-neural-network-runtime-type-h.md#oh_nn_returncode)，可以通过访问dataBuffer读取推理结果。
- 如果内存大小小于数据长度：则[OH_NNExecutor_Run](capi-neural-network-runtime-h.md#oh_nnexecutor_run)将返回[OH_NN_INVALID_PARAMETER](capi-neural-network-runtime-type-h.md#oh_nn_returncode)，并输出日志告知内存太小的信息。

**起始版本：** 9

**废弃版本：** 11

**替代接口：** [OH_NNExecutor_RunSync](capi-neural-network-core-h.md#oh_nnexecutor_runsync)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | 指向[OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md)实例的指针。 |
| uint32_t outputIndex | 输出的索引值，与调用[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)时输出数据的顺序一致。<br>假设调用[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)时，outputIndices为{4, 6, 8}，则在设置输出内存时，三个输出的索引值分别为{0, 1, 2}。 |
| void *dataBuffer | 指向输出数据的指针。 |
| size_t length | 数据内存的字节长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |

### OH_NNExecutor_Run()

```
OH_NN_ReturnCode OH_NNExecutor_Run(OH_NNExecutor *executor)
```

**描述**

执行推理。 在执行器关联的硬件上，执行模型的端到端推理计算。

**起始版本：** 9

**废弃版本：** 11

**替代接口：** [OH_NNExecutor_RunSync](capi-neural-network-core-h.md#oh_nnexecutor_runsync)

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | 指向[OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md)实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |

### OH_NNExecutor_AllocateInputMemory()

```
OH_NN_Memory *OH_NNExecutor_AllocateInputMemory(OH_NNExecutor *executor, uint32_t inputIndex, size_t length)
```

**描述**

在硬件上为单个输入申请共享内存。

Neural Network Runtime 提供主动申请硬件共享内存的方法。

通过指定执行器和输入索引值，该接口在单个输入关联的硬件上，申请大小为length的共享内存，通过[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)实例返回。

**起始版本：** 9

**废弃版本：** 11

**替代接口：** [OH_NNTensor_CreateWithSize](capi-neural-network-core-h.md#oh_nntensor_createwithsize)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | 指向[OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md)实例的指针。 |
| uint32_t inputIndex | 输入的索引值，与调用[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)时输入数据的顺序一致。<br>假设调用[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)时，inputIndices为{1, 5, 9}，则在申请输入内存时，三个输入的索引值分别为{0, 1, 2}。 |
| size_t length | 申请的内存字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) * | 指向[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)实例的指针，如果创建失败就返回NULL。 |

### OH_NNExecutor_AllocateOutputMemory()

```
OH_NN_Memory *OH_NNExecutor_AllocateOutputMemory(OH_NNExecutor *executor, uint32_t outputIndex, size_t length)
```

**描述**

在硬件上为单个输出申请共享内存。

Neural Network Runtime 提供主动申请硬件共享内存的方法。

通过指定执行器和输出索引值，该接口在单个输出关联的硬件上，申请大小为length的共享内存，通过[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)实例返回。

**起始版本：** 9

**废弃版本：** 11

**替代接口：** [OH_NNTensor_CreateWithSize](capi-neural-network-core-h.md#oh_nntensor_createwithsize)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | 指向[OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md)实例的指针。 |
| uint32_t outputIndex | 输出的索引值，与调用[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)时输出数据的顺序一致。<br>假设调用[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)时，outputIndices为{4, 6, 8}，则在申请输出内存时，三个输出的索引值分别为{0, 1, 2}。 |
| size_t length | 申请的内存字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) * | 指向[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)实例的指针，如果创建失败就返回NULL。 |

### OH_NNExecutor_DestroyInputMemory()

```
void OH_NNExecutor_DestroyInputMemory(OH_NNExecutor *executor, uint32_t inputIndex, OH_NN_Memory **memory)
```

**描述**

释放[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)实例指向的输入内存。

调用[OH_NNExecutor_AllocateInputMemory](capi-neural-network-runtime-h.md#oh_nnexecutor_allocateinputmemory)创建的内存实例，需要主动调用该接口进行释放，否则将造成内存泄漏。

inputIndex和memory的对应关系需要和创建内存实例时保持一致。 如果memory或*memory为空指针，该接口仅打印警告日志，不执行释放操作。

**起始版本：** 9

**废弃版本：** 11

**替代接口：** [OH_NNTensor_Destroy](capi-neural-network-core-h.md#oh_nntensor_destroy)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | 指向[OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md)实例的指针。 |
| uint32_t inputIndex | 输入的索引值，与调用[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)时输入数据的顺序一致。<br>假设调用[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)时，inputIndices为{1, 5, 9}，则在释放输入内存时，三个输入的索引值分别为{0, 1, 2}。 |
| [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) **memory | 指向[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)实例的二级指针。共享内存释放后，该接口将*memory主动设置为空指针。 |

### OH_NNExecutor_DestroyOutputMemory()

```
void OH_NNExecutor_DestroyOutputMemory(OH_NNExecutor *executor, uint32_t outputIndex, OH_NN_Memory **memory)
```

**描述**

释放[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)实例指向的输出内存。

调用[OH_NNExecutor_AllocateOutputMemory](capi-neural-network-runtime-h.md#oh_nnexecutor_allocateoutputmemory)创建的内存实例，需要主动调用该接口进行释放，否则将造成内存泄漏。

outputIndex和memory的对应关系需要和创建内存实例时保持一致。 

如果memory或*memory为空指针，该接口仅打印警告日志，不执行释放操作。

**起始版本：** 9

**废弃版本：** 11

**替代接口：** [OH_NNTensor_Destroy](capi-neural-network-core-h.md#oh_nntensor_destroy)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | 指向[OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md)实例的指针。 |
| uint32_t outputIndex | 输出的索引值，与调用[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)时输出数据的顺序一致。<br>假设调用[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)时，outputIndices为{4, 6, 8}，则在释放输出内存时，三个输出的索引值分别为{0, 1, 2}。 |
| [OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) **memory | 指向[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)实例的二级指针。共享内存释放后，该接口将*memory主动设置为空指针。 |

### OH_NNExecutor_SetInputWithMemory()

```
OH_NN_ReturnCode OH_NNExecutor_SetInputWithMemory(OH_NNExecutor *executor,uint32_t inputIndex,const OH_NN_Tensor *tensor,const OH_NN_Memory *memory)
```

**描述**

将[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)实例指向的硬件共享内存，并指定为单个输入使用的内存。

在需要自行管理内存的场景下，该接口将执行输入和[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)内存实例绑定。

执行计算时，底层硬件从内存实例指向的共享内存中读取输入数据。

通过该接口，可以实现设置输入、执行计算、读取输出的并发执行，提升数据流的推理效率。

**起始版本：** 9

**废弃版本：** 11

**替代接口：** [OH_NNExecutor_RunSync](capi-neural-network-core-h.md#oh_nnexecutor_runsync)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | 指向[OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md)实例的指针。 |
| uint32_t inputIndex | 输入的索引值，与调用[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)时输入数据的顺序一致。<br>假设调用[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)时，inputIndices为{1, 5, 9}，则在指定输入的共享内存时，三个输入的索引值分别为{0, 1, 2}。 |
| [const OH_NN_Tensor](capi-neuralnetworkruntime-oh-nn-tensor.md) *tensor | 指向[OH_NN_Tensor](capi-neuralnetworkruntime-oh-nn-tensor.md)的指针，设置单个输入所对应的张量。 |
| [const OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) *memory | 指向[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |

### OH_NNExecutor_SetOutputWithMemory()

```
OH_NN_ReturnCode OH_NNExecutor_SetOutputWithMemory(OH_NNExecutor *executor,uint32_t outputIndex,const OH_NN_Memory *memory)
```

**描述**

将[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)实例指向的硬件共享内存，并指定为单个输出使用的内存。

在需要自行管理内存的场景下，该接口将执行输出和[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)内存实例绑定。

执行计算时，底层硬件将计算结果直接写入内存实例指向的共享内存。

通过该接口，可以实现设置输入、执行计算、读取输出的并发执行，提升数据流的推理效率。

**起始版本：** 9

**废弃版本：** 11

**替代接口：** [OH_NNExecutor_RunSync](capi-neural-network-core-h.md#oh_nnexecutor_runsync)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | 执行器。 |
| uint32_t outputIndex | 输出的索引值，与调用[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)时输出数据的顺序一致。<br>假设调用[OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs)时，outputIndices为{4, 6, 8}，则在指定输出的共享内存时，三个输出的索引值分别为{0, 1, 2}。 |
| [const OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md) *memory | 指向[OH_NN_Memory](capi-neuralnetworkruntime-oh-nn-memory.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | 函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode)。 |


