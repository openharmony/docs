# neural_network_core.h
<!--Kit_Neural Network Runtime Kit--><!--System_AI-->

## Overview

Defines APIs for the Neural Network Core module. The AI inference framework uses the native APIs provided by Neural Network Core to compile models and perform inference and computing on acceleration hardware.

Some API definitions have been moved from **neural_network_runtime.h** to this file for unified presentation. These APIs are supported since API version 11 and can be used in all later versions.

Currently, the APIs of Neural Network Core do not support multi-thread calling.

**File to include**: <neural_network_runtime/neural_network_core.h>

**Library**: libneural_network_core.so

**System capability**: SystemCapability.Ai.NeuralNetworkRuntime

**Since**: 11

**Related module**: [NeuralNetworkRuntime](capi-neuralnetworkruntime.md)

## Summary

### Functions

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_NNCompilation *OH_NNCompilation_Construct(const OH_NNModel *model)](#oh_nncompilation_construct) | Creates an [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance.<br>After an [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance is created, the OH_NNCompilation module passes the model instance to the underlying device for compilation.|
| [OH_NNCompilation *OH_NNCompilation_ConstructWithOfflineModelFile(const char *modelPath)](#oh_nncompilation_constructwithofflinemodelfile) | Creates a model compilation instance based on an offline model file.<br>This API conflicts with the one that utilizes an online model or offline model buffer. You can select only one of the three compilation APIs.<br>An offline model is one that is offline-compiled by the model converter provided by hardware vendors. As such, it can only be used on designated devices. However, the compilation time of an offline model is generally much shorter than that of the graph construction instance [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md).<br>During development, offline compilation needs to be performed and offline models need to be deployed in application packages.|
| [OH_NNCompilation *OH_NNCompilation_ConstructWithOfflineModelBuffer(const void *modelBuffer, size_t modelSize)](#oh_nncompilation_constructwithofflinemodelbuffer) | Creates a model compilation instance based on the offline model buffer.<br>This API conflicts with the one that utilizes an online model or offline model file. You can select only one of the three compilation APIs.<br>The returned [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance only saves the **modelBuffer** pointer, but does not copy its data. The **modelBuffer** instance should not be released before the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance is destroyed.|
| [OH_NNCompilation *OH_NNCompilation_ConstructForCache()](#oh_nncompilation_constructforcache) | Creates an empty model compilation instance for later recovery from the model cache.<br>For details about the model cache, see [OH_NNCompilation_SetCache](capi-neural-network-core-h.md#oh_nncompilation_setcache).<br>The time required for model recovery from the model cache is less than the time required for compilation using [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md).<br>Call [OH_NNCompilation_SetCache](capi-neural-network-core-h.md#oh_nncompilation_setcache) or [OH_NNCompilation_ImportCacheFromBuffer](capi-neural-network-core-h.md#oh_nncompilation_importcachefrombuffer) and then [OH_NNCompilation_Build](capi-neural-network-core-h.md#oh_nncompilation_build) to complete model recovery.|
| [OH_NN_ReturnCode OH_NNCompilation_ExportCacheToBuffer(OH_NNCompilation *compilation,const void *buffer,size_t length,size_t *modelSize)](#oh_nncompilation_exportcachetobuffer) | Writes the model cache to the specified buffer.<br>For details about the model cache, see [OH_NNCompilation_SetCache](capi-neural-network-core-h.md#oh_nncompilation_setcache).<br>The model cache stores the result of [OH_NNCompilation_Build](capi-neural-network-core-h.md#oh_nncompilation_build). Therefore, this API must be called after [OH_NNCompilation_Build](capi-neural-network-core-h.md#oh_nncompilation_build) is complete.|
| [OH_NN_ReturnCode OH_NNCompilation_ImportCacheFromBuffer(OH_NNCompilation *compilation,const void *buffer,size_t modelSize)](#oh_nncompilation_importcachefrombuffer) | Reads the model cache from the specified buffer.<br>For details about the model cache, see [OH_NNCompilation_SetCache](capi-neural-network-core-h.md#oh_nncompilation_setcache).<br>After calling [OH_NNCompilation_ImportCacheFromBuffer](capi-neural-network-core-h.md#oh_nncompilation_importcachefrombuffer), call [OH_NNCompilation_Build](capi-neural-network-core-h.md#oh_nncompilation_build) to complete model recovery.<br>The **compilation** instance only stores the **buffer** pointer, but does not copy its data. You cannot release the **buffer** before the **compilation** instance is destroyed.|
| [OH_NN_ReturnCode OH_NNCompilation_AddExtensionConfig(OH_NNCompilation *compilation,const char *configName,const void *configValue,const size_t configValueSize)](#oh_nncompilation_addextensionconfig) | Adds extended configurations for custom device attributes.<br>Some devices have their own attributes, which have not been enabled in NNRt. This API helps you to set custom attributes for these devices.<br>You need to obtain their names and values from the device vendor's documentation and add them to the model compilation instance. These attributes are passed directly to the device driver. If the device driver cannot parse the attributes, an error is returned.<br>After [OH_NNCompilation_Build](capi-neural-network-core-h.md#oh_nncompilation_build) is called, **configName** and **configValue** can be released.|
| [OH_NN_ReturnCode OH_NNCompilation_SetDevice(OH_NNCompilation *compilation, size_t deviceID)](#oh_nncompilation_setdevice) | Sets the device for model compilation and computing.<br>In the compilation phase, you need to specify the device for model compilation and computing. Call [OH_NNDevice_GetAllDevicesID](capi-neural-network-core-h.md#oh_nndevice_getalldevicesid) to obtain available device IDs. Then, call [OH_NNDevice_GetType](capi-neural-network-core-h.md#oh_nndevice_gettype) and [OH_NNDevice_GetType](capi-neural-network-core-h.md#oh_nndevice_gettype) to obtain device information and pass target device IDs to this API.|
| [OH_NN_ReturnCode OH_NNCompilation_SetCache(OH_NNCompilation *compilation, const char *cachePath, uint32_t version)](#oh_nncompilation_setcache) | Sets the cache directory and version for model compilation.                              |
| [OH_NN_ReturnCode OH_NNCompilation_SetPerformanceMode(OH_NNCompilation *compilation,OH_NN_PerformanceMode performanceMode)](#oh_nncompilation_setperformancemode) | Sets the performance mode for model computing.<br>NNRt allows you to set the performance mode for model computing to meet the requirements of low power consumption and ultimate performance. If this API is not called to set the performance mode in the compilation phase, the model compilation instance assigns the [OH_NN_PERFORMANCE_NONE](capi-neural-network-runtime-type-h.md#oh_nn_performancemode) mode for the model by default. In this case, the device performs computing in the default performance mode. If this API is called on a device that does not support setting of the performance mode, the error code [OH_NN_UNAVAILABLE_DEVICE](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned.|
| [OH_NN_ReturnCode OH_NNCompilation_SetPriority(OH_NNCompilation *compilation, OH_NN_Priority priority)](#oh_nncompilation_setpriority) | Sets the priority for model computing.<br>NNRt allows you to set computing priorities for models. The priorities apply only to models created by the process with the same UID. The settings will not affect models created by processes with different UIDs on different devices. If this API is called on a device that does not support priority setting, the error code [OH_NN_UNAVAILABLE_DEVICE](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned.|
| [OH_NN_ReturnCode OH_NNCompilation_EnableFloat16(OH_NNCompilation *compilation, bool enableFloat16)](#oh_nncompilation_enablefloat16) | Enables float16 for computing.<br>By default, the floating-point model uses float32 for computing. If this API is called on a device that supports float16, floating-point model that supports float32 will use float16 for computing, so to reduce memory usage and execution time. This option is invalid for fixed-point models, for example, fixed-point models of the int8 type.<br>If this API is called on a device that does not support float16, the error code [OH_NN_UNAVAILABLE_DEVICE](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned.|
| [OH_NN_ReturnCode OH_NNCompilation_Build(OH_NNCompilation *compilation)](#oh_nncompilation_build) | Performs model compilation.<br>After the compilation configuration is complete, call this API to start model compilation. The model compilation instance pushes the model and compilation options to the device for compilation.<br>After this API is called, additional compilation operations cannot be performed. If [OH_NNCompilation_SetDevice](capi-neural-network-core-h.md#oh_nncompilation_setdevice), [OH_NNCompilation_SetCache](capi-neural-network-core-h.md#oh_nncompilation_setcache), [OH_NNCompilation_SetPerformanceMode](capi-neural-network-core-h.md#oh_nncompilation_setperformancemode), [OH_NNCompilation_SetPriority](capi-neural-network-core-h.md#oh_nncompilation_setpriority), or [OH_NNCompilation_EnableFloat16](capi-neural-network-core-h.md#oh_nncompilation_enablefloat16) is called, [OH_NN_OPERATION_FORBIDDEN](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned.|
| [void OH_NNCompilation_Destroy(OH_NNCompilation **compilation)](#oh_nncompilation_destroy) | Destroys an [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance.<br>This API needs to be used to destroy the model compilation instances created by calling [OH_NNCompilation_Construct](capi-neural-network-core-h.md#oh_nncompilation_construct), [OH_NNCompilation_ConstructWithOfflineModelFile](capi-neural-network-core-h.md#oh_nncompilation_constructwithofflinemodelfile), [OH_NNCompilation_ConstructWithOfflineModelBuffer](capi-neural-network-core-h.md#oh_nncompilation_constructwithofflinemodelbuffer) or [OH_NNCompilation_ConstructForCache](capi-neural-network-core-h.md#oh_nncompilation_constructforcache). If **compilation** or **\*compilation** is a null pointer, this API only prints warning logs but does not perform the destruction operation.|
| [NN_TensorDesc *OH_NNTensorDesc_Create()](#oh_nntensordesc_create) | Creates an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>[NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) describes various tensor attributes, such as the name, data type, shape, and format.<br>You can create an [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance based on the input [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance by calling the following APIs:<br>[OH_NNTensor_Create](capi-neural-network-core-h.md#oh_nntensor_create) <br>[OH_NNTensor_CreateWithSize](capi-neural-network-core-h.md#oh_nntensor_createwithsize) <br>[OH_NNTensor_CreateWithFd](capi-neural-network-core-h.md#oh_nntensor_createwithfd) <br>This API copies the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance to [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md). This way, you can create multiple [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instances with the same [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance. If the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance is no longer needed, call [OH_NNTensorDesc_Destroy](capi-neural-network-core-h.md#oh_nntensordesc_destroy) to destroy it.|
| [OH_NN_ReturnCode OH_NNTensorDesc_Destroy(NN_TensorDesc **tensorDesc)](#oh_nntensordesc_destroy) | Destroys an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>If the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance is no longer needed, call this API to destroy it. Otherwise, a memory leak occurs.<br>If <b>tensorDesc</b> or <b>\*tensorDesc</b> is a null pointer, an error is returned but the object will not be destroyed.|
| [OH_NN_ReturnCode OH_NNTensorDesc_SetName(NN_TensorDesc *tensorDesc, const char *name)](#oh_nntensordesc_setname) | Sets the name of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>After an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance is created, call this API to set the tensor name. The value of \*name is a C-style string ending with \0.<br>If <b>tensorDesc</b> or <b>name</b> is a null pointer, an error is returned.|
| [OH_NN_ReturnCode OH_NNTensorDesc_GetName(const NN_TensorDesc *tensorDesc, const char **name)](#oh_nntensordesc_getname) | Obtains the name of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>You can use this API to obtain the name of the specified [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance. The value of **\*name** is a C-style string ending with **\0**.<br>If <b>tensorDesc</b> or <b>name</b> is a null pointer, an error is returned. As an output parameter, **\*name** must be a null pointer. Otherwise, an error is returned.<br>For example, you should define **char\* tensorName = NULL** and pass **&tensorName** as a parameter of **name**.<br>You do not need to release the memory of **name**. When **tensorDesc** is destroyed, it is automatically released.|
| [OH_NN_ReturnCode OH_NNTensorDesc_SetDataType(NN_TensorDesc *tensorDesc, OH_NN_DataType dataType)](#oh_nntensordesc_setdatatype) | Sets the data type of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>After an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance is created, call this API to set the tensor data type.<br>If **tensorDesc** is a null pointer, an error is returned.|
| [OH_NN_ReturnCode OH_NNTensorDesc_GetDataType(const NN_TensorDesc *tensorDesc, OH_NN_DataType *dataType)](#oh_nntensordesc_getdatatype) | Obtains the data type of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>You can use this API to obtain the data type of the specified [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>If <b>tensorDesc</b> or <b>dataType</b> is a null pointer, an error is returned.|
| [OH_NN_ReturnCode OH_NNTensorDesc_SetShape(NN_TensorDesc *tensorDesc, const int32_t *shape, size_t shapeLength)](#oh_nntensordesc_setshape) | Sets the data shape of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>After an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance is created, call this API to set the tensor shape.<br>If <b>tensorDesc</b> or <b>shape</b> is a null pointer, or <b>shapeLength</b> is 0, an error is returned.|
| [OH_NN_ReturnCode OH_NNTensorDesc_GetShape(const NN_TensorDesc *tensorDesc, int32_t **shape, size_t *shapeLength)](#oh_nntensordesc_getshape) | Obtains the shape of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>You can use this API to obtain the shape of the specified [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>If <b>tensorDesc</b>, <b>shape</b>, or <b>shapeLength</b> is a null pointer, an error is returned. As an output parameter, **\*shape** must be a null pointer. Otherwise, an error is returned.<br>For example, you should define **int32_t\* tensorShape = NULL** and pass **&tensorShape** as a parameter of **shape**.<br>You do not need to release the memory of **shape**. When **tensorDesc** is destroyed, it is automatically released.|
| [OH_NN_ReturnCode OH_NNTensorDesc_SetFormat(NN_TensorDesc *tensorDesc, OH_NN_Format format)](#oh_nntensordesc_setformat) | Sets the data format of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>After an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance is created, call this API to set [OH_NN_Format](capi-neural-network-runtime-type-h.md#oh_nn_format) of the tensor.<br>If <b>tensorDesc</b> is a null pointer, an error is returned.|
| [OH_NN_ReturnCode OH_NNTensorDesc_GetFormat(const NN_TensorDesc *tensorDesc, OH_NN_Format *format)](#oh_nntensordesc_getformat) | Obtains the data format of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>You can use this API to obtain [OH_NN_Format](capi-neural-network-runtime-type-h.md#oh_nn_format) of the specified [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>If <b>tensorDesc</b> or <b>format</b> is a null pointer, an error is returned.|
| [OH_NN_ReturnCode OH_NNTensorDesc_GetElementCount(const NN_TensorDesc *tensorDesc, size_t *elementCount)](#oh_nntensordesc_getelementcount) | Obtains the number of elements in an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>You can use this API to obtain the number of elements in the specified [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance. To obtain the size of tensor data, call [OH_NNTensorDesc_GetByteSize](capi-neural-network-core-h.md#oh_nntensordesc_getbytesize).<br>If the tensor shape is dynamically variable, this API returns an error code and **elementCount** is **0**.<br>If <b>tensorDesc</b> or <b>elementCount</b> is a null pointer, an error is returned.|
| [OH_NN_ReturnCode OH_NNTensorDesc_GetByteSize(const NN_TensorDesc *tensorDesc, size_t *byteSize)](#oh_nntensordesc_getbytesize) | Obtains the number of bytes occupied by the tensor data obtained through calculation based on the shape and data type of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>You can use this API to obtain the number of bytes occupied by the tensor data obtained through calculation based on the shape and data type of the specified [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>If the tensor shape is dynamically variable, this API returns an error code and **byteSize** is **0**.<br>To obtain the number of elements in the tensor data, call [OH_NNTensorDesc_GetElementCount](capi-neural-network-core-h.md#oh_nntensordesc_getelementcount).<br>If <b>tensorDesc</b> or <b>byteSize</b> is a null pointer, an error is returned.|
| [NN_Tensor *OH_NNTensor_Create(size_t deviceID, NN_TensorDesc *tensorDesc)](#oh_nntensor_create) | Creates an [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance from [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md).<br>This API uses [OH_NNTensorDesc_GetByteSize](capi-neural-network-core-h.md#oh_nntensordesc_getbytesize) to calculate the number of bytes of tensor data and allocate device memory for it. The device driver directly obtains tensor data in zero-copy mode.<br>This API copies **tensorDesc** to [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md). Therefore, if **tensorDesc** is no longer needed, destroy it by calling [OH_NNTensorDesc_Destroy](capi-neural-network-core-h.md#oh_nntensordesc_destroy).<br>If the tensor shape is dynamic, an error is returned.<br><b>deviceID</b> indicates the selected device. If the value is **0**, the first device in the current device list is used by default.<br>**tensorDesc is mandatory**. If it is a null pointer, an error is returned.<br>If the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance is no longer needed, destroy it by calling [OH_NNTensor_Destroy](capi-neural-network-core-h.md#oh_nntensor_destroy).|
| [NN_Tensor *OH_NNTensor_CreateWithSize(size_t deviceID, NN_TensorDesc *tensorDesc, size_t size)](#oh_nntensor_createwithsize) | Creates an [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance based on the specified memory size and [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>This API uses **size** as the number of bytes of tensor data and allocates device memory to it. The device driver directly obtains tensor data in zero-copy mode.<br>Note that this API copies **tensorDesc** to [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md). Therefore, if **tensorDesc** is no longer needed, destroy it by calling [OH_NNTensorDesc_Destroy](capi-neural-network-core-h.md#oh_nntensordesc_destroy).<br>**deviceID** indicates the ID of the selected device. If the value is **0**, the first device is used.<br>**tensorDesc** is mandatory. If it is a null pointer, an error is returned.<br>The value of **size** must be greater than or equal to the number of bytes occupied by **tensorDesc**, which can be obtained by calling [OH_NNTensorDesc_GetByteSize](capi-neural-network-core-h.md#oh_nntensordesc_getbytesize). Otherwise, an error is returned. If the tensor shape is dynamic, <b>size</b> is not checked.<br>If the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance is no longer needed, destroy it by calling [OH_NNTensor_Destroy](capi-neural-network-core-h.md#oh_nntensor_destroy).|
| [NN_Tensor *OH_NNTensor_CreateWithFd(size_t deviceID,NN_TensorDesc *tensorDesc,int fd,size_t size,size_t offset)](#oh_nntensor_createwithfd) | Creates an [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance based on the specified file descriptor of the shared memory and [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.<br>This API reuses the shared memory corresponding to **fd**, which may source from another [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance. When the tensor created by calling [OH_NNTensor_Destroy](capi-neural-network-core-h.md#oh_nntensor_destroy) is destroyed, the memory storing the tensor data is not released.<br>Note that this API copies **tensorDesc** to [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md). Therefore, if **tensorDesc** is no longer needed, destroy it by calling [OH_NNTensorDesc_Destroy](capi-neural-network-core-h.md#oh_nntensordesc_destroy).<br><b>deviceID</b> indicates the selected device. If the value is **0**, the first device in the current device list is used by default.<br>**tensorDesc** is mandatory. If the pointer is null, an error is returned.<br>If the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance is no longer needed, destroy it by calling [OH_NNTensor_Destroy](capi-neural-network-core-h.md#oh_nntensor_destroy).|
| [OH_NN_ReturnCode OH_NNTensor_Destroy(NN_Tensor **tensor)](#oh_nntensor_destroy) | Destroys an [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance.<br>If the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance is no longer needed, call this API to destroy it. Otherwise, a memory leak occurs.<br>If <b>tensor</b> or <b>*tensor</b> is a null pointer, an error is returned but the object will not be destroyed.|
| [NN_TensorDesc *OH_NNTensor_GetTensorDesc(const NN_Tensor *tensor)](#oh_nntensor_gettensordesc) | Obtains an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance of [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md).<br>You can use this API to obtain the pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance of the specified [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance.<br>You can obtain tensor attributes of various types from the returned [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance, such as the name, data format, data type, and shape.<br>You should not destroy the returned [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance because it points to an internal instance of [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md). Otherwise, once [OH_NNTensor_Destroy](capi-neural-network-core-h.md#oh_nntensor_destroy) is called, a crash may occur due to double memory release.<br>If <b>Tensor</b> is a null pointer, a null pointer is returned.|
| [void *OH_NNTensor_GetDataBuffer(const NN_Tensor *tensor)](#oh_nntensor_getdatabuffer) | Obtains the memory address of [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) data.<br>You can read/write data from/to tensor data memory. The data memory is mapped from the shared memory on the device. Therefore, the device driver can directly obtain tensor data in zero-copy mode.<br>Only tensor data in the [offset, size) segment in the corresponding shared memory can be used. **offset** indicates the offset in the shared memory and can be obtained by calling [OH_NNTensor_GetOffset](capi-neural-network-core-h.md#oh_nntensor_getoffset). **size** indicates the total size of the shared memory, which can be obtained by calling [OH_NNTensor_GetSize](capi-neural-network-core-h.md#oh_nntensor_getsize).<br>If <b>Tensor</b> is a null pointer, a null pointer is returned.|
| [OH_NN_ReturnCode OH_NNTensor_GetFd(const NN_Tensor *tensor, int *fd)](#oh_nntensor_getfd) | Obtains the file descriptor (**fd**) of the shared memory where [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) data is stored.<br>**fd** corresponds to a device shared memory and can be used by another [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) through [OH_NNTensor_CreateWithFd](capi-neural-network-core-h.md#oh_nntensor_createwithfd).<br>If <b>tensor</b> or <b>fd</b> is a null pointer, an error is returned.|
| [OH_NN_ReturnCode OH_NNTensor_GetSize(const NN_Tensor *tensor, size_t *size)](#oh_nntensor_getsize) | Obtains the size of the shared memory where the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) data is stored.<br>The value of **size** is the same as that of [OH_NNTensor_CreateWithSize](capi-neural-network-core-h.md#oh_nntensor_createwithsize) and [OH_NNTensor_CreateWithFd](capi-neural-network-core-h.md#oh_nntensor_createwithfd). However, for a tensor created by using [OH_NNTensor_Create](capi-neural-network-core-h.md#oh_nntensor_create), the value of **size** is equal to the number of bytes actually occupied by the tensor data, which can be obtained by calling [OH_NNTensorDesc_GetByteSize](capi-neural-network-core-h.md#oh_nntensordesc_getbytesize).<br> Only tensor data in the [offset, size) segment in the shared memory corresponding to the **fd** can be used. **offset** indicates the offset in the shared memory and can be obtained by calling [OH_NNTensor_GetOffset](capi-neural-network-core-h.md#oh_nntensor_getoffset). **size** indicates the total size of the shared memory, which can be obtained by calling [OH_NNTensor_GetSize](capi-neural-network-core-h.md#oh_nntensor_getsize).<br>If <b>tensor</b> or <b>size</b> is a null pointer, an error is returned.|
| [OH_NN_ReturnCode OH_NNTensor_GetOffset(const NN_Tensor *tensor, size_t *offset)](#oh_nntensor_getoffset) | Obtains the offset of [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) data in the shared memory.<br>**offset** indicates the offset of tensor data in the corresponding shared memory. It can be used by another [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) together with **fd** and **size** of the shared memory through [OH_NNTensor_CreateWithFd](capi-neural-network-core-h.md#oh_nntensor_createwithfd).<br> Only tensor data in the [offset, size) segment in the shared memory corresponding to the **fd** can be used. **offset** indicates the offset in the shared memory and can be obtained by calling [OH_NNTensor_GetOffset](capi-neural-network-core-h.md#oh_nntensor_getoffset). **size** indicates the total size of the shared memory, which can be obtained by calling [OH_NNTensor_GetSize](capi-neural-network-core-h.md#oh_nntensor_getsize).<br>If <b>tensor</b> or <b>offset</b> is a null pointer, an error is returned.|
| [OH_NNExecutor *OH_NNExecutor_Construct(OH_NNCompilation *compilation)](#oh_nnexecutor_construct) | Creates an [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) executor instance.<br>This API constructs a model inference executor for a device based on the specified [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance. Use [OH_NNExecutor_SetInput](capi-neural-network-runtime-h.md#oh_nnexecutor_setinput) to set the model input data. After the input data is set, call [OH_NNExecutor_Run](capi-neural-network-runtime-h.md#oh_nnexecutor_run) to perform inference and then call [OH_NNExecutor_SetOutput](capi-neural-network-runtime-h.md#oh_nnexecutor_setoutput) to obtain the computing result.  After an [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance is created through the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance, destroy the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance if it is no longer needed.|
| [OH_NN_ReturnCode OH_NNExecutor_GetOutputShape(OH_NNExecutor *executor,uint32_t outputIndex,int32_t **shape,uint32_t *shapeLength)](#oh_nnexecutor_getoutputshape) | Obtains the dimension information about the output tensor.                                    |
| [void OH_NNExecutor_Destroy(OH_NNExecutor **executor)](#oh_nnexecutor_destroy) | Destroys an executor instance to release the memory occupied by it.<br>This API needs to be called to release the executor instance created by calling [OH_NNExecutor_Construct](capi-neural-network-core-h.md#oh_nnexecutor_construct). Otherwise, a memory leak occurs.  If **executor** or **\*executor** is a null pointer, this API only prints the warning log and does not execute the release logic.|
| [OH_NN_ReturnCode OH_NNExecutor_GetInputCount(const OH_NNExecutor *executor, size_t *inputCount)](#oh_nnexecutor_getinputcount) | Obtains the number of input tensors.<br>You can obtain the number of input tensors from **executor**, and then use [OH_NNExecutor_CreateInputTensorDesc](capi-neural-network-core-h.md#oh_nnexecutor_createinputtensordesc) to create a tensor description based on the specified tensor index.|
| [OH_NN_ReturnCode OH_NNExecutor_GetOutputCount(const OH_NNExecutor *executor, size_t *outputCount)](#oh_nnexecutor_getoutputcount) | Obtains the number of output tensors.<br>You can obtain the number of output tensors from **executor**, and then use [OH_NNExecutor_CreateOutputTensorDesc](capi-neural-network-core-h.md#oh_nnexecutor_createoutputtensordesc) to create a tensor description based on the specified tensor index.|
| [NN_TensorDesc *OH_NNExecutor_CreateInputTensorDesc(const OH_NNExecutor *executor, size_t index)](#oh_nnexecutor_createinputtensordesc) | Creates the description of an input tensor based on the specified index value.<br>The description contains all types of attribute values of the tensor. If the value of **index** reaches or exceeds the number of input tensors, an error is returned. You can obtain the number of input tensors by calling [OH_NNExecutor_GetInputCount](capi-neural-network-core-h.md#oh_nnexecutor_getinputcount).|
| [NN_TensorDesc *OH_NNExecutor_CreateOutputTensorDesc(const OH_NNExecutor *executor, size_t index)](#oh_nnexecutor_createoutputtensordesc) | Creates the description of an output tensor based on the specified index value.<br>The description contains all types of attribute values of the tensor. If the value of **index** reaches or exceeds the number of output tensors, an error is returned. You can obtain the number of output tensors by calling [OH_NNExecutor_GetOutputCount](capi-neural-network-core-h.md#oh_nnexecutor_getoutputcount).|
| [OH_NN_ReturnCode OH_NNExecutor_GetInputDimRange(const OH_NNExecutor *executor,size_t index,size_t **minInputDims,size_t **maxInputDims,size_t *shapeLength)](#oh_nnexecutor_getinputdimrange) | Obtains the dimension range of all input tensors.<br>If the input tensor has a dynamic shape, the dimension range supported by the tensor may vary according to device. You can call this API to obtain the dimension range supported by the current device. **\*minInputDims** saves the minimum dimension of the specified input tensor (the number of dimensions matches the shape), while **\*maxInputDims** saves the maximum dimension.|
| [OH_NN_ReturnCode OH_NNExecutor_SetOnRunDone(OH_NNExecutor *executor, NN_OnRunDone onRunDone)](#oh_nnexecutor_setonrundone) | Sets the callback processing function invoked when the asynchronous inference ends.<br>For details about the callback function, see [NN_OnRunDone](capi-neural-network-runtime-type-h.md#nn_onrundone).|
| [OH_NN_ReturnCode OH_NNExecutor_SetOnServiceDied(OH_NNExecutor *executor, NN_OnServiceDied onServiceDied)](#oh_nnexecutor_setonservicedied) | Sets the callback processing function invoked when the device driver service terminates unexpectedly during asynchronous inference.<br>For details about the callback function, see [NN_OnServiceDied](capi-neural-network-runtime-type-h.md#nn_onservicedied).|
| [OH_NN_ReturnCode OH_NNExecutor_RunSync(OH_NNExecutor *executor,NN_Tensor *inputTensor[],size_t inputCount,NN_Tensor *outputTensor[],size_t outputCount)](#oh_nnexecutor_runsync) | Performs synchronous inference.<br>You need to create input and output tensors by calling [OH_NNTensor_Create](capi-neural-network-core-h.md#oh_nntensor_create), [OH_NNTensor_CreateWithSize](capi-neural-network-core-h.md#oh_nntensor_createwithsize), or [OH_NNTensor_CreateWithFd](capi-neural-network-core-h.md#oh_nntensor_createwithfd). Then, use [OH_NNTensor_GetDataBuffer](capi-neural-network-core-h.md#oh_nntensor_getdatabuffer) to obtain the pointer to tensor data and copy the input data to it. The executor performs model inference, generates the inference result, and writes the result to the output tensor.<br>If the output tensor has a dynamic shape, you can obtain the actual shape of the output tensor by calling [OH_NNExecutor_GetOutputShape](capi-neural-network-core-h.md#oh_nnexecutor_getoutputshape). Alternatively, obtain the tensor description from the input tensor by calling [OH_NNTensor_GetTensorDesc](capi-neural-network-core-h.md#oh_nntensor_gettensordesc), and then obtain the actual shape by calling [OH_NNTensorDesc_GetShape](capi-neural-network-core-h.md#oh_nntensordesc_getshape).|
| [OH_NN_ReturnCode OH_NNExecutor_RunAsync(OH_NNExecutor *executor,NN_Tensor *inputTensor[],size_t inputCount,NN_Tensor *outputTensor[],size_t outputCount,int32_t timeout,void *userData)](#oh_nnexecutor_runasync) | Performs asynchronous inference.<br>You need to create input and output tensors by calling [OH_NNTensor_Create](capi-neural-network-core-h.md#oh_nntensor_create), [OH_NNTensor_CreateWithSize](capi-neural-network-core-h.md#oh_nntensor_createwithsize), or [OH_NNTensor_CreateWithFd](capi-neural-network-core-h.md#oh_nntensor_createwithfd). Then, use [OH_NNTensor_GetDataBuffer](capi-neural-network-core-h.md#oh_nntensor_getdatabuffer) to obtain the pointer to tensor data and copy the input data to it. The executor performs model inference, generates the inference result, and writes the result to the output tensor.<br>If the output tensor has a dynamic shape, you can obtain the actual shape of the output tensor by calling [OH_NNExecutor_GetOutputShape](capi-neural-network-core-h.md#oh_nnexecutor_getoutputshape). Alternatively, obtain the tensor description from the input tensor by calling [OH_NNTensor_GetTensorDesc](capi-neural-network-core-h.md#oh_nntensor_gettensordesc), and then obtain the actual shape by calling [OH_NNTensorDesc_GetShape](capi-neural-network-core-h.md#oh_nntensordesc_getshape).<br>This API works in non-blocking mode and returns the result immediately after being called. You can obtain the inference result and execution return status through the [NN_OnRunDone](capi-neural-network-runtime-type-h.md#nn_onrundone) callback. If the device driver service stops abnormally during execution, you can use the [NN_OnServiceDied](capi-neural-network-runtime-type-h.md#nn_onservicedied) callback for exception processing.<br>You can set the NN_OnRunDone](capi-neural-network-runtime-type-h.md#nn_onrundone) and [NN_OnServiceDied](capi-neural-network-runtime-type-h.md#nn_onservicedied) callbacks by calling [OH_NNExecutor_SetOnRunDone](capi-neural-network-core-h.md#oh_nnexecutor_setonrundone) and [OH_NNExecutor_SetOnServiceDied](capi-neural-network-core-h.md#oh_nnexecutor_setonservicedied).<br>If the inference times out, it is terminated immediately and the error code [OH_NN_TIMEOUT](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned through the [NN_OnRunDone](capi-neural-network-runtime-type-h.md#nn_onrundone) callback.<br>**userData** is the identifier used to distinguish different asynchronous inferences and is returned as the first parameter in the callback. You can use any data that can distinguish different inferences as the identifier.|
| [OH_NN_ReturnCode OH_NNDevice_GetAllDevicesID(const size_t **allDevicesID, uint32_t *deviceCount)](#oh_nndevice_getalldevicesid) | Obtains the ID of the device connected to NNRt.<br>Each device has a unique and fixed ID, which is returned through a uint32_t array.<br>When device IDs are returned through the size_t array, each element of the array is the ID of a single device. Internal management is used for array memory. The data pointer remains valid before this API is called next time.|
| [OH_NN_ReturnCode OH_NNDevice_GetName(size_t deviceID, const char **name)](#oh_nndevice_getname) | Obtains the name of the specified device.<br>**deviceID** specifies the device ID used to obtain the device name. The device ID needs to be obtained by calling [OH_NNDevice_GetAllDevicesID](capi-neural-network-core-h.md#oh_nndevice_getalldevicesid). If the value of **deviceID** is **0**, the first device in the device list is used by default.  **\*name** is a C-style string ended with **\0**.<br>**\*name** must be a null pointer. Otherwise, the error code [OH_NN_INVALID_PARAMETER](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned. For example, you should define **char\* deviceName = NULL**, and then pass **&deviceName** as an input parameter.|
| [OH_NN_ReturnCode OH_NNDevice_GetType(size_t deviceID, OH_NN_DeviceType *deviceType)](#oh_nndevice_gettype) | Obtains the type of the specified device.<br>**deviceID** specifies the device ID used to obtain the device type. If the value of **deviceID** is **0**, the first device in the device list is used by default. Currently, the following device types are supported:<br>- **OH_NN_CPU**: CPU device.<br>- **OH_NN_GPU**: GPU device.<br>- **OH_NN_ACCELERATOR**: machine learning dedicated accelerator.<br>- **OH_NN_OTHERS**: other device types.|

## Function Description

### OH_NNCompilation_Construct()

```
OH_NNCompilation *OH_NNCompilation_Construct(const OH_NNModel *model)
```

**Description**

Creates an [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance.

After an [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance is created, the OH_NNCompilation module passes the model instance to the underlying device for compilation.

This API creates an [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance based on the passed [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance. The [OH_NNCompilation_SetDevice](capi-neural-network-core-h.md#oh_nncompilation_setdevice) API is called to specify the device for model compilation, and the [OH_NNCompilation_Build](capi-neural-network-core-h.md#oh_nncompilation_build) API is then called to complete model compilation.

In addition to computing device selection, the OH_NNCompilation module supports features such as model cache, performance preference, priority setting, and float16 computing, which can be implemented by the following APIs:

[OH_NNCompilation_SetCache](capi-neural-network-core-h.md#oh_nncompilation_setcache) 

[OH_NNCompilation_SetPerformanceMode](capi-neural-network-core-h.md#oh_nncompilation_setperformancemode) 

[OH_NNCompilation_SetPriority](capi-neural-network-core-h.md#oh_nncompilation_setpriority) 

[OH_NNCompilation_EnableFloat16](capi-neural-network-core-h.md#oh_nncompilation_enablefloat16)

After this API is called to create an [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance, the [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance can be released.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [const OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) *model | Pointer to the [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) * | Pointer to the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance. If the operation fails, **NULL** is returned.|

### OH_NNCompilation_ConstructWithOfflineModelFile()

```
OH_NNCompilation *OH_NNCompilation_ConstructWithOfflineModelFile(const char *modelPath)
```

**Description**

Creates a model compilation instance based on an offline model file.

This API conflicts with the one that utilizes an online model or offline model buffer. You can select only one of the three compilation APIs.

An offline model is one that is offline-compiled by the model converter provided by hardware vendors. As such, it can only be used on designated devices. However, the compilation time of an offline model is generally much shorter than that of the graph construction instance [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md).

During development, offline compilation needs to be performed and offline models need to be deployed in application packages.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| const char *modelPath | Path of the offline model file.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) * | Pointer to the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance. If the operation fails, **NULL** is returned.|

### OH_NNCompilation_ConstructWithOfflineModelBuffer()

```
OH_NNCompilation *OH_NNCompilation_ConstructWithOfflineModelBuffer(const void *modelBuffer, size_t modelSize)
```

**Description**

Creates a model compilation instance based on the offline model buffer.

This API conflicts with the one that utilizes an online model or offline model file. You can select only one of the three compilation APIs.

The returned [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance only saves the **modelBuffer** pointer, but does not copy its data. The **modelBuffer** instance should not be released before the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance is destroyed.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| const void *modelBuffer | Memory for storing offline model files.|
| size_t modelSize | Memory size of the offline model.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) * | Pointer to the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance. If the operation fails, **NULL** is returned.|

### OH_NNCompilation_ConstructForCache()

```
OH_NNCompilation *OH_NNCompilation_ConstructForCache()
```

**Description**

Creates an empty model compilation instance for later recovery from the model cache.

For details about the model cache, see [OH_NNCompilation_SetCache](capi-neural-network-core-h.md#oh_nncompilation_setcache).

The time required for model recovery from the model cache is less than the time required for compilation using [OH_NNModel](capi-neuralnetworkruntime-oh-nnmodel.md).

Call [OH_NNCompilation_SetCache](capi-neural-network-core-h.md#oh_nncompilation_setcache) or [OH_NNCompilation_ImportCacheFromBuffer](capi-neural-network-core-h.md#oh_nncompilation_importcachefrombuffer) and then [OH_NNCompilation_Build](capi-neural-network-core-h.md#oh_nncompilation_build) to complete model recovery.

**Since**: 11

**Returns**

| Type| Description|
| -- | -- |
| [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) * | Pointer to the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance. If the operation fails, **NULL** is returned.|

### OH_NNCompilation_ExportCacheToBuffer()

```
OH_NN_ReturnCode OH_NNCompilation_ExportCacheToBuffer(OH_NNCompilation *compilation,const void *buffer,size_t length,size_t *modelSize)
```

**Description**

Writes the model cache to the specified buffer.

For details about the model cache, see [OH_NNCompilation_SetCache](capi-neural-network-core-h.md#oh_nncompilation_setcache).

The model cache stores the result of [OH_NNCompilation_Build](capi-neural-network-core-h.md#oh_nncompilation_build). Therefore, this API must be called after [OH_NNCompilation_Build](capi-neural-network-core-h.md#oh_nncompilation_build) is complete.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) *compilation | Pointer to the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance.|
| const void *buffer | Pointer to the given memory.|
| size_t length | Memory length. |
| size_t *modelSize | Size of the model cache, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNCompilation_ImportCacheFromBuffer()

```
OH_NN_ReturnCode OH_NNCompilation_ImportCacheFromBuffer(OH_NNCompilation *compilation,const void *buffer,size_t modelSize)
```

**Description**

Reads the model cache from the specified buffer.

For details about the model cache, see [OH_NNCompilation_SetCache](capi-neural-network-core-h.md#oh_nncompilation_setcache).

After calling [OH_NNCompilation_ImportCacheFromBuffer](capi-neural-network-core-h.md#oh_nncompilation_importcachefrombuffer), call [OH_NNCompilation_Build](capi-neural-network-core-h.md#oh_nncompilation_build) to complete model recovery.

The **compilation** instance only stores the **buffer** pointer, but does not copy its data. You cannot release the **buffer** before the **compilation** instance is destroyed.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) *compilation | Pointer to the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance.|
| const void *buffer | Pointer to the given memory.|
| size_t modelSize | Size of the model cache, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNCompilation_AddExtensionConfig()

```
OH_NN_ReturnCode OH_NNCompilation_AddExtensionConfig(OH_NNCompilation *compilation,const char *configName,const void *configValue,const size_t configValueSize)
```

**Description**

Adds extended configurations for custom device attributes.

Some devices have their own attributes, which have not been enabled in NNRt. This API helps you to set custom attributes for these devices.

You need to obtain their names and values from the device vendor's documentation and add them to the model compilation instance. These attributes are passed directly to the device driver. If the device driver cannot parse the attributes, an error is returned.<br>After [OH_NNCompilation_Build](capi-neural-network-core-h.md#oh_nncompilation_build) is called, **configName** and **configValue** can be released.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) *compilation | Pointer to the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance.|
| const char *configName | Configuration name.|
| const void *configValue | Configured value.|
| const size_t configValueSize | Size of the configured value, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNCompilation_SetDevice()

```
OH_NN_ReturnCode OH_NNCompilation_SetDevice(OH_NNCompilation *compilation, size_t deviceID)
```

**Description**

Sets the device for model compilation and computing.

In the compilation phase, you need to specify the device for model compilation and computing. Call [OH_NNDevice_GetAllDevicesID](capi-neural-network-core-h.md#oh_nndevice_getalldevicesid) to obtain available device IDs. Then, call [OH_NNDevice_GetType](capi-neural-network-core-h.md#oh_nndevice_gettype) and [OH_NNDevice_GetType](capi-neural-network-core-h.md#oh_nndevice_gettype) to obtain device information and pass target device IDs to this API.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) *compilation | Pointer to the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance.|
| size_t deviceID | Device ID. If the value is **0**, the first device in the current device list is used by default.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNCompilation_SetCache()

```
OH_NN_ReturnCode OH_NNCompilation_SetCache(OH_NNCompilation *compilation, const char *cachePath, uint32_t version)
```

**Description**

Sets the cache directory and version for model compilation.

On the device that supports model caching, a model can be saved as a cache file after a successful compilation at the device driver layer. The model can be directly read from the cache file, saving the compilation time.

This API performs different operations based on the model cache directory and version:

- If no file exists in the specified model cache directory, cache the built model to the directory and set the cache version to the value of **version**.
- If a complete cached file exists in the specified model cache directory, and its version number is equal to **version**, read the cached file in the directory and pass it to the underlying device to convert it into an executable model instance.
- If a complete cached file exists in the specified model cache directory, but its version is earlier than **version**, update the cached file. After the model is built on the underlying device, the cached file in the cache directory is overwritten and the version is updated to **version**.
- If a complete cached file exists in the specified model cache directory, but its version is later than **version**, the cached file is not read and the error code [OH_NN_INVALID_PARAMETER](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned.
- If the cached file in the specified model cache directory is incomplete or you do not have the file access permission, the error code [OH_NN_INVALID_FILE](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned.
- If the model cache directory does not exist or you do not have the file access permission, the error code [OH_NN_INVALID_PATH](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) *compilation | Pointer to the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance.|
| const char *cachePath | Directory for storing model cache files. This API creates model cache directories for different devices in the cachePath directory. You are advised to use a separate cache directory for each model.|
| uint32_t version | Cached model version.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNCompilation_SetPerformanceMode()

```
OH_NN_ReturnCode OH_NNCompilation_SetPerformanceMode(OH_NNCompilation *compilation,OH_NN_PerformanceMode performanceMode)
```

**Description**

Sets the performance mode for model computing.

NNRt allows you to set the performance mode for model computing to meet the requirements of low power consumption and ultimate performance. If this API is not called to set the performance mode in the compilation phase, the model compilation instance assigns the [OH_NN_PERFORMANCE_NONE](capi-neural-network-runtime-type-h.md#oh_nn_performancemode) mode for the model by default. In this case, the device performs computing in the default performance mode. If this API is called on a device that does not support setting of the performance mode, the error code [OH_NN_UNAVAILABLE_DEVICE](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) *compilation | Pointer to the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance.|
| [OH_NN_PerformanceMode](capi-neural-network-runtime-type-h.md#oh_nn_performancemode) performanceMode | Performance mode for model computing. For details, see [OH_NN_PerformanceMode](capi-neural-network-runtime-type-h.md#oh_nn_performancemode).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNCompilation_SetPriority()

```
OH_NN_ReturnCode OH_NNCompilation_SetPriority(OH_NNCompilation *compilation, OH_NN_Priority priority)
```

**Description**

Sets the priority for model computing.

NNRt allows you to set computing priorities for models. The priorities apply only to models created by the process with the same UID. The settings will not affect models created by processes with different UIDs on different devices. If this API is called on a device that does not support priority setting, the error code [OH_NN_UNAVAILABLE_DEVICE](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) *compilation | Pointer to the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance.|
| [OH_NN_Priority](capi-neural-network-runtime-type-h.md#oh_nn_priority) priority | Sets the priority. For details about the available priorities, see [OH_NN_Priority](capi-neural-network-runtime-type-h.md#oh_nn_priority).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNCompilation_EnableFloat16()

```
OH_NN_ReturnCode OH_NNCompilation_EnableFloat16(OH_NNCompilation *compilation, bool enableFloat16)
```

**Description**

Enables float16 for computing.

By default, the floating-point model uses float32 for computing. If this API is called on a device that supports float16, floating-point model that supports float32 will use float16 for computing, so to reduce memory usage and execution time. This option is invalid for fixed-point models, for example, fixed-point models of the int8 type.<br>If this API is called on a device that does not support float16, the error code [OH_NN_UNAVAILABLE_DEVICE](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) *compilation | Pointer to the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance.|
| bool enableFloat16 | Whether to enable float16. If this parameter is set to **true**, float16 inference is performed. If this parameter is set to **false**, float32 inference is performed.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNCompilation_Build()

```
OH_NN_ReturnCode OH_NNCompilation_Build(OH_NNCompilation *compilation)
```

**Description**

Performs model compilation.

After the compilation configuration is complete, call this API to start model compilation. The model compilation instance pushes the model and compilation options to the device for compilation.

After this API is called, additional compilation operations cannot be performed. If [OH_NNCompilation_SetDevice](capi-neural-network-core-h.md#oh_nncompilation_setdevice), [OH_NNCompilation_SetCache](capi-neural-network-core-h.md#oh_nncompilation_setcache), [OH_NNCompilation_SetPerformanceMode](capi-neural-network-core-h.md#oh_nncompilation_setperformancemode), [OH_NNCompilation_SetPriority](capi-neural-network-core-h.md#oh_nncompilation_setpriority), or [OH_NNCompilation_EnableFloat16](capi-neural-network-core-h.md#oh_nncompilation_enablefloat16) is called, [OH_NN_OPERATION_FORBIDDEN](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) *compilation | Pointer to the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNCompilation_Destroy()

```
void OH_NNCompilation_Destroy(OH_NNCompilation **compilation)
```

**Description**

Destroys an [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance.

This API needs to be used to destroy the model compilation instances created by calling [OH_NNCompilation_Construct](capi-neural-network-core-h.md#oh_nncompilation_construct), [OH_NNCompilation_ConstructWithOfflineModelFile](capi-neural-network-core-h.md#oh_nncompilation_constructwithofflinemodelfile), [OH_NNCompilation_ConstructWithOfflineModelBuffer](capi-neural-network-core-h.md#oh_nncompilation_constructwithofflinemodelbuffer) or [OH_NNCompilation_ConstructForCache](capi-neural-network-core-h.md#oh_nncompilation_constructforcache). If **compilation** or **\*compilation** is a null pointer, this API only prints warning logs but does not perform the destruction operation.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) **compilation | Level-2 pointer to the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance. After the model building instance is destroyed, this API sets **\*compilation** to a null pointer.|

### OH_NNTensorDesc_Create()

```
NN_TensorDesc *OH_NNTensorDesc_Create()
```

**Description**

Creates an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

[NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) describes various tensor attributes, such as the name, data type, shape, and format.

You can create an [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance based on the input [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance by calling the following APIs:

[OH_NNTensor_Create](capi-neural-network-core-h.md#oh_nntensor_create) 

[OH_NNTensor_CreateWithSize](capi-neural-network-core-h.md#oh_nntensor_createwithsize) 

[OH_NNTensor_CreateWithFd](capi-neural-network-core-h.md#oh_nntensor_createwithfd) 

This API copies the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance to [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md). This way, you can create multiple [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instances with the same [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance. If the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance is no longer needed, call [OH_NNTensorDesc_Destroy](capi-neural-network-core-h.md#oh_nntensordesc_destroy) to destroy it.

**Since**: 11

**Returns**

| Type| Description|
| -- | -- |
| [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) * | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance. If the operation fails, **NULL** is returned.|

### OH_NNTensorDesc_Destroy()

```
OH_NN_ReturnCode OH_NNTensorDesc_Destroy(NN_TensorDesc **tensorDesc)
```

**Description**

Destroys an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

If the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance is no longer needed, call this API to destroy it. Otherwise, a memory leak occurs.

If <b>tensorDesc</b> or <b>\*tensorDesc</b> is a null pointer, an error is returned but the object will not be destroyed.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) **tensorDesc | Level-2 pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNTensorDesc_SetName()

```
OH_NN_ReturnCode OH_NNTensorDesc_SetName(NN_TensorDesc *tensorDesc, const char *name)
```

**Description**

Sets the name of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

After an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance is created, call this API to set the tensor name. The value of \*name is a C-style string ending with \0.

If <b>tensorDesc</b> or <b>name</b> is a null pointer, an error is returned.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) *tensorDesc | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.|
| const char *name | Name of the tensor to be set.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNTensorDesc_GetName()

```
OH_NN_ReturnCode OH_NNTensorDesc_GetName(const NN_TensorDesc *tensorDesc, const char **name)
```

**Description**

Obtains the name of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

You can use this API to obtain the name of the specified [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance. The value of **\*name** is a C-style string ending with **\0**.

If <b>tensorDesc</b> or <b>name</b> is a null pointer, an error is returned. As an output parameter, **\*name** must be a null pointer. Otherwise, an error is returned.

For example, you should define **char\* tensorName = NULL** and pass **&tensorName** as a parameter of **name**.

You do not need to release the memory of **name**. When **tensorDesc** is destroyed, it is automatically released.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [const NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) *tensorDesc | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.|
| const char **name | Tensor name.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNTensorDesc_SetDataType()

```
OH_NN_ReturnCode OH_NNTensorDesc_SetDataType(NN_TensorDesc *tensorDesc, OH_NN_DataType dataType)
```

**Description**

Sets the data type of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

After an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance is created, call this API to set the tensor data type.

If <b>tensorDesc</b> is a null pointer, an error is returned.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) *tensorDesc | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.|
| [OH_NN_DataType](capi-neural-network-runtime-type-h.md#oh_nn_datatype) dataType | Tensor data type to be set.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNTensorDesc_GetDataType()

```
OH_NN_ReturnCode OH_NNTensorDesc_GetDataType(const NN_TensorDesc *tensorDesc, OH_NN_DataType *dataType)
```

**Description**

Obtains the data type of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

You can use this API to obtain the data type of the specified [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

If <b>tensorDesc</b> or <b>dataType</b> is a null pointer, an error is returned.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [const NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) *tensorDesc | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.|
| [OH_NN_DataType](capi-neural-network-runtime-type-h.md#oh_nn_datatype) *dataType | Tensor data type.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNTensorDesc_SetShape()

```
OH_NN_ReturnCode OH_NNTensorDesc_SetShape(NN_TensorDesc *tensorDesc, const int32_t *shape, size_t shapeLength)
```

**Description**

Sets the data shape of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

After an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance is created, call this API to set the tensor shape.

If <b>tensorDesc</b> or <b>shape</b> is a null pointer, or <b>shapeLength</b> is 0, an error is returned.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) *tensorDesc | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.|
| const int32_t *shape | List of tensor shapes to be set.|
| size_t shapeLength | Length of the list of tensor shapes.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNTensorDesc_GetShape()

```
OH_NN_ReturnCode OH_NNTensorDesc_GetShape(const NN_TensorDesc *tensorDesc, int32_t **shape, size_t *shapeLength)
```

**Description**

Obtains the shape of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

You can use this API to obtain the shape of the specified [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

If <b>tensorDesc</b>, <b>shape</b>, or <b>shapeLength</b> is a null pointer, an error is returned. As an output parameter, **\*shape** must be a null pointer. Otherwise, an error is returned.

For example, you should define **int32_t\* tensorShape = NULL** and pass **&tensorShape** as a parameter of **shape**.

You do not need to release the memory of **shape**. When **tensorDesc** is destroyed, it is automatically released.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [const NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) *tensorDesc | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.|
| int32_t **shape | List of tensor shapes.|
| size_t *shapeLength | Length of the list of tensor shapes.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNTensorDesc_SetFormat()

```
OH_NN_ReturnCode OH_NNTensorDesc_SetFormat(NN_TensorDesc *tensorDesc, OH_NN_Format format)
```

**Description**

Sets the data format of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

After an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance is created, call this API to set [OH_NN_Format](capi-neural-network-runtime-type-h.md#oh_nn_format) of the tensor.

If <b>tensorDesc</b> is a null pointer, an error is returned.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) *tensorDesc | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.|
| [OH_NN_Format](capi-neural-network-runtime-type-h.md#oh_nn_format) format | Tensor data format to be set.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNTensorDesc_GetFormat()

```
OH_NN_ReturnCode OH_NNTensorDesc_GetFormat(const NN_TensorDesc *tensorDesc, OH_NN_Format *format)
```

**Description**

Obtains the data format of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

You can use this API to obtain [OH_NN_Format](capi-neural-network-runtime-type-h.md#oh_nn_format) of the specified [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

If <b>tensorDesc</b> or <b>format</b> is a null pointer, an error is returned.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [const NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) *tensorDesc | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.|
| [OH_NN_Format](capi-neural-network-runtime-type-h.md#oh_nn_format) *format | Tensor data format.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNTensorDesc_GetElementCount()

```
OH_NN_ReturnCode OH_NNTensorDesc_GetElementCount(const NN_TensorDesc *tensorDesc, size_t *elementCount)
```

**Description**

Obtains the number of elements in an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

You can use this API to obtain the number of elements in the specified [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance. To obtain the size of tensor data, call [OH_NNTensorDesc_GetByteSize](capi-neural-network-core-h.md#oh_nntensordesc_getbytesize).

If the tensor shape is dynamically variable, this API returns an error code and **elementCount** is **0**.

If <b>tensorDesc</b> or <b>elementCount</b> is a null pointer, an error is returned.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [const NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) *tensorDesc | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.|
| size_t *elementCount | Number of elements.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNTensorDesc_GetByteSize()

```
OH_NN_ReturnCode OH_NNTensorDesc_GetByteSize(const NN_TensorDesc *tensorDesc, size_t *byteSize)
```

**Description**

Obtains the number of bytes occupied by the tensor data obtained through calculation based on the shape and data type of an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

You can use this API to obtain the number of bytes occupied by the tensor data obtained through calculation based on the shape and data type of the specified [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

If the tensor shape is dynamically variable, this API returns an error code and **byteSize** is **0**.

To obtain the number of elements in the tensor data, call [OH_NNTensorDesc_GetElementCount](capi-neural-network-core-h.md#oh_nntensordesc_getelementcount).

If <b>tensorDesc</b> or <b>byteSize</b> is a null pointer, an error is returned.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [const NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) *tensorDesc | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.|
| size_t *byteSize | Size of the returned data, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNTensor_Create()

```
NN_Tensor *OH_NNTensor_Create(size_t deviceID, NN_TensorDesc *tensorDesc)
```

**Description**

Creates an [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance from [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md).

This API uses [OH_NNTensorDesc_GetByteSize](capi-neural-network-core-h.md#oh_nntensordesc_getbytesize) to calculate the number of bytes of tensor data and allocate device memory for it. The device driver directly obtains tensor data in zero-copy mode.

This API copies **tensorDesc** to [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md). Therefore, if **tensorDesc** is no longer needed, destroy it by calling [OH_NNTensorDesc_Destroy](capi-neural-network-core-h.md#oh_nntensordesc_destroy).

If the tensor shape is dynamic, an error is returned.

<b>deviceID</b> indicates the selected device. If the value is **0**, the first device in the current device list is used by default.

**tensorDesc is mandatory**. If it is a null pointer, an error is returned.

If the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance is no longer needed, destroy it by calling [OH_NNTensor_Destroy](capi-neural-network-core-h.md#oh_nntensor_destroy).

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| size_t deviceID | Device ID. If the value is **0**, the first device in the current device list is used by default.|
| [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) *tensorDesc | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) * | Pointer to the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance. If the operation fails, **NULL** is returned.|

### OH_NNTensor_CreateWithSize()

```
NN_Tensor *OH_NNTensor_CreateWithSize(size_t deviceID, NN_TensorDesc *tensorDesc, size_t size)
```

**Description**

Creates an [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance based on the specified memory size and [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

This API uses **size** as the number of bytes of tensor data and allocates device memory to it. The device driver directly obtains tensor data in zero-copy mode.

Note that this API copies **tensorDesc** to [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md). Therefore, if **tensorDesc** is no longer needed, destroy it by calling [OH_NNTensorDesc_Destroy](capi-neural-network-core-h.md#oh_nntensordesc_destroy).

**deviceID** indicates the ID of the selected device. If the value is **0**, the first device is used.

**tensorDesc** is mandatory. If it is a null pointer, an error is returned.

The value of **size** must be greater than or equal to the number of bytes occupied by **tensorDesc**, which can be obtained by calling [OH_NNTensorDesc_GetByteSize](capi-neural-network-core-h.md#oh_nntensordesc_getbytesize). Otherwise, an error is returned. If the tensor shape is dynamic, <b>size</b> is not checked.

If the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance is no longer needed, destroy it by calling [OH_NNTensor_Destroy](capi-neural-network-core-h.md#oh_nntensor_destroy).

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| size_t deviceID | Device ID. If the value is **0**, the first device in the current device list is used by default.|
| [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) *tensorDesc | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.|
| size_t size | Size of the tensor data to be allocated.|

**Returns**

| Type| Description|
| -- | -- |
| [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) * | Pointer to the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance. If the operation fails, **NULL** is returned.|

### OH_NNTensor_CreateWithFd()

```
NN_Tensor *OH_NNTensor_CreateWithFd(size_t deviceID,NN_TensorDesc *tensorDesc,int fd,size_t size,size_t offset)
```

**Description**

Creates an [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance based on the specified file descriptor of the shared memory and [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.

This API reuses the shared memory corresponding to **fd**, which may source from another [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance. When the tensor created by calling [OH_NNTensor_Destroy](capi-neural-network-core-h.md#oh_nntensor_destroy) is destroyed, the memory storing the tensor data is not released.

Note that this API copies **tensorDesc** to [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md). Therefore, if **tensorDesc** is no longer needed, destroy it by calling [OH_NNTensorDesc_Destroy](capi-neural-network-core-h.md#oh_nntensordesc_destroy).<br><b>deviceID</b> indicates the selected device. If the value is **0**, the first device in the current device list is used by default.

**tensorDesc** is mandatory. If the pointer is null, an error is returned.

If the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance is no longer needed, destroy it by calling [OH_NNTensor_Destroy](capi-neural-network-core-h.md#oh_nntensor_destroy).

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| size_t deviceID | Device ID. If the value is **0**, the first device in the current device list is used by default.|
| [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) *tensorDesc | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance.|
| int fd | **fd** of the shared memory to be used.|
| size_t size | Size of the shared memory to be used.|
| size_t offset | Offset of the shared memory to be used.|

**Returns**

| Type| Description|
| -- | -- |
| [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) * | Pointer to the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance. If the operation fails, **NULL** is returned.|

### OH_NNTensor_Destroy()

```
OH_NN_ReturnCode OH_NNTensor_Destroy(NN_Tensor **tensor)
```

**Description**

Destroys an [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance.

If the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance is no longer needed, call this API to destroy it. Otherwise, a memory leak occurs.

If <b>tensor</b> or <b>*tensor</b> is a null pointer, an error is returned but the object will not be destroyed.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) **tensor | Level-2 pointer to the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNTensor_GetTensorDesc()

```
NN_TensorDesc *OH_NNTensor_GetTensorDesc(const NN_Tensor *tensor)
```

**Description**

Obtains an [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance of [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md).

You can use this API to obtain the pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance of the specified [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance.

You can obtain tensor attributes of various types from the returned [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance, such as the name, data format, data type, and shape.

You should not destroy the returned [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance because it points to an internal instance of [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md). Otherwise, once [OH_NNTensor_Destroy](capi-neural-network-core-h.md#oh_nntensor_destroy) is called, a crash may occur due to double memory release.

If <b>Tensor</b> is a null pointer, a null pointer is returned.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [const NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) *tensor | Pointer to the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) * | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance. If the operation fails, **NULL** is returned.|

### OH_NNTensor_GetDataBuffer()

```
void *OH_NNTensor_GetDataBuffer(const NN_Tensor *tensor)
```

**Description**

Obtains the memory address of [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) data.

You can read/write data from/to tensor data memory. The data memory is mapped from the shared memory on the device. Therefore, the device driver can directly obtain tensor data in zero-copy mode.

Only tensor data in the [offset, size) segment in the corresponding shared memory can be used. **offset** indicates the offset in the shared memory and can be obtained by calling [OH_NNTensor_GetOffset](capi-neural-network-core-h.md#oh_nntensor_getoffset). **size** indicates the total size of the shared memory, which can be obtained by calling [OH_NNTensor_GetSize](capi-neural-network-core-h.md#oh_nntensor_getsize).

If <b>Tensor</b> is a null pointer, a null pointer is returned.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [const NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) *tensor | Pointer to the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| void * | Pointer to the tensor data memory. If the operation fails, a null pointer is returned.|

### OH_NNTensor_GetFd()

```
OH_NN_ReturnCode OH_NNTensor_GetFd(const NN_Tensor *tensor, int *fd)
```

**Description**

Obtains the file descriptor (**fd**) of the shared memory where [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) data is stored.

**fd** corresponds to a device shared memory and can be used by another [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) through [OH_NNTensor_CreateWithFd](capi-neural-network-core-h.md#oh_nntensor_createwithfd).

If <b>tensor</b> or <b>fd</b> is a null pointer, an error is returned.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [const NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) *tensor | Pointer to the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance.|
| int *fd | **fd** of the shared memory.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNTensor_GetSize()

```
OH_NN_ReturnCode OH_NNTensor_GetSize(const NN_Tensor *tensor, size_t *size)
```

**Description**

Obtains the size of the shared memory where the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) data is stored.

The value of **size** is the same as that of [OH_NNTensor_CreateWithSize](capi-neural-network-core-h.md#oh_nntensor_createwithsize) and [OH_NNTensor_CreateWithFd](capi-neural-network-core-h.md#oh_nntensor_createwithfd). However, for a tensor created by using [OH_NNTensor_Create](capi-neural-network-core-h.md#oh_nntensor_create), the value of **size** is equal to the number of bytes actually occupied by the tensor data, which can be obtained by calling [OH_NNTensorDesc_GetByteSize](capi-neural-network-core-h.md#oh_nntensordesc_getbytesize).

 Only tensor data in the [offset, size) segment in the shared memory corresponding to the **fd** can be used. **offset** indicates the offset in the shared memory and can be obtained by calling [OH_NNTensor_GetOffset](capi-neural-network-core-h.md#oh_nntensor_getoffset). **size** indicates the total size of the shared memory, which can be obtained by calling [OH_NNTensor_GetSize](capi-neural-network-core-h.md#oh_nntensor_getsize).

If <b>tensor</b> or <b>size</b> is a null pointer, an error is returned.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [const NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) *tensor | Pointer to the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance.|
| size_t *size | Size of the shared memory where the returned data is located.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNTensor_GetOffset()

```
OH_NN_ReturnCode OH_NNTensor_GetOffset(const NN_Tensor *tensor, size_t *offset)
```

**Description**

Obtains the offset of [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) data in the shared memory.

**offset** indicates the offset of tensor data in the corresponding shared memory. It can be used by another [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) together with **fd** and **size** of the shared memory through [OH_NNTensor_CreateWithFd](capi-neural-network-core-h.md#oh_nntensor_createwithfd).

 Only tensor data in the [offset, size) segment in the shared memory corresponding to the **fd** can be used. **offset** indicates the offset in the shared memory and can be obtained by calling [OH_NNTensor_GetOffset](capi-neural-network-core-h.md#oh_nntensor_getoffset). **size** indicates the total size of the shared memory, which can be obtained by calling [OH_NNTensor_GetSize](capi-neural-network-core-h.md#oh_nntensor_getsize).

If <b>tensor</b> or <b>offset</b> is a null pointer, an error is returned.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [const NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) *tensor | Pointer to the [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) instance.|
| size_t *offset | Offset for the fd of the tensor.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNExecutor_Construct()

```
OH_NNExecutor *OH_NNExecutor_Construct(OH_NNCompilation *compilation)
```

**Description**

Creates an [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) executor instance.

This API constructs a model inference executor for a device based on the specified [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance. Use [OH_NNExecutor_SetInput](capi-neural-network-runtime-h.md#oh_nnexecutor_setinput) to set the model input data. After the input data is set, call [OH_NNExecutor_Run](capi-neural-network-runtime-h.md#oh_nnexecutor_run) to perform inference and then call [OH_NNExecutor_SetOutput](capi-neural-network-runtime-h.md#oh_nnexecutor_setoutput) to obtain the computing result.  After an [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance is created through the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance, destroy the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance if it is no longer needed.

**Since**: 9

**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) *compilation | Pointer to the [OH_NNCompilation](capi-neuralnetworkruntime-oh-nncompilation.md) instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) * | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance. If the operation fails, NULL is returned.|

### OH_NNExecutor_GetOutputShape()

```
OH_NN_ReturnCode OH_NNExecutor_GetOutputShape(OH_NNExecutor *executor,uint32_t outputIndex,int32_t **shape,uint32_t *shapeLength)
```

**Description**

Obtains the dimension information about the output tensor.

You can use this API to obtain information about the specified output dimension and number of dimensions after a single inference is performed by calling [OH_NNExecutor_Run](capi-neural-network-runtime-h.md#oh_nnexecutor_run). It is commonly used in dynamic shape input and output scenarios.

If the value of **outputIndex** reaches or exceeds the number of output tensors, an error is returned. You can obtain the number of output tensors by calling [OH_NNExecutor_GetOutputCount](capi-neural-network-core-h.md#oh_nnexecutor_getoutputcount).

As an output parameter, **\*shape** cannot be a null pointer. Otherwise, an error is returned. For example, you should define **int32_t\* tensorShape = NULL** and pass **&tensorShape** as an input parameter.

You do not need to release the memory of **shape**. It is released with **executor**.

**Since**: 9

**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|
| uint32_t outputIndex | Output index value, which is the same as the sequence of the output data when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called. Assume that **outputIndices** is {4, 6, 8} when [OH_NNModel_SpecifyInputsAndOutputs](capi-neural-network-runtime-h.md#oh_nnmodel_specifyinputsandoutputs) is called. When you obtain information about the output dimension, set the value of this parameter to {0, 1, 2}.|
| int32_t **shape | Pointer to the int32_t array. The value of each element in the array is the length of the output tensor in each dimension.|
| uint32_t *shapeLength | Pointer to the uint32_t type. The number of output dimensions is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNExecutor_Destroy()

```
void OH_NNExecutor_Destroy(OH_NNExecutor **executor)
```

**Description**

Destroys an executor instance to release the memory occupied by it.

This API needs to be called to release the executor instance created by calling [OH_NNExecutor_Construct](capi-neural-network-core-h.md#oh_nnexecutor_construct). Otherwise, a memory leak occurs.  If **executor** or **\*executor** is a null pointer, this API only prints the warning log and does not execute the release logic.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) **executor | Level-2 pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|

### OH_NNExecutor_GetInputCount()

```
OH_NN_ReturnCode OH_NNExecutor_GetInputCount(const OH_NNExecutor *executor, size_t *inputCount)
```

**Description**

Obtains the number of input tensors.

You can obtain the number of input tensors from **executor**, and then use [OH_NNExecutor_CreateInputTensorDesc](capi-neural-network-core-h.md#oh_nnexecutor_createinputtensordesc) to create a tensor description based on the specified tensor index.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [const OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|
| size_t *inputCount | Number of returned input tensors.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNExecutor_GetOutputCount()

```
OH_NN_ReturnCode OH_NNExecutor_GetOutputCount(const OH_NNExecutor *executor, size_t *outputCount)
```

**Description**

Obtains the number of output tensors.

You can obtain the number of output tensors from **executor**, and then use [OH_NNExecutor_CreateOutputTensorDesc](capi-neural-network-core-h.md#oh_nnexecutor_createoutputtensordesc) to create a tensor description based on the specified tensor index.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [const OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|
| size_t *outputCount | Number of returned output tensors.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNExecutor_CreateInputTensorDesc()

```
NN_TensorDesc *OH_NNExecutor_CreateInputTensorDesc(const OH_NNExecutor *executor, size_t index)
```

**Description**

Creates the description of an input tensor based on the specified index value.

The description contains all types of attribute values of the tensor. If the value of **index** reaches or exceeds the number of input tensors, an error is returned. You can obtain the number of input tensors by calling [OH_NNExecutor_GetInputCount](capi-neural-network-core-h.md#oh_nnexecutor_getinputcount).

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [const OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|
| size_t index | Index value of the input tensor.|

**Returns**

| Type| Description|
| -- | -- |
| [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) * | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance. If the operation fails, **NULL** is returned.|

### OH_NNExecutor_CreateOutputTensorDesc()

```
NN_TensorDesc *OH_NNExecutor_CreateOutputTensorDesc(const OH_NNExecutor *executor, size_t index)
```

**Description**

Creates the description of an output tensor based on the specified index value.

The description contains all types of attribute values of the tensor. If the value of **index** reaches or exceeds the number of output tensors, an error is returned. You can obtain the number of output tensors by calling [OH_NNExecutor_GetOutputCount](capi-neural-network-core-h.md#oh_nnexecutor_getoutputcount).

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [const OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|
| size_t index | Index value of the output tensor.|

**Returns**

| Type| Description|
| -- | -- |
| [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) * | Pointer to the [NN_TensorDesc](capi-neuralnetworkruntime-nn-tensordesc.md) instance. If the operation fails, **NULL** is returned.|

### OH_NNExecutor_GetInputDimRange()

```
OH_NN_ReturnCode OH_NNExecutor_GetInputDimRange(const OH_NNExecutor *executor,size_t index,size_t **minInputDims,size_t **maxInputDims,size_t *shapeLength)
```

**Description**

Obtains the dimension range of all input tensors.

If the input tensor has a dynamic shape, the dimension range supported by the tensor may vary according to device. You can call this API to obtain the dimension range supported by the current device. **\*minInputDims** saves the minimum dimension of the specified input tensor (the number of dimensions matches the shape), while **\*maxInputDims** saves the maximum dimension.

For example, if an input tensor has a dynamic shape of [-1, -1, -1, 3], **\*minInputDims** may be [1, 10, 10, 3], and **\*maxInputDims** may be [100, 1024, 1024, 3].

If the value of **index** reaches or exceeds the number of input tensors, an error is returned. You can obtain the number of input tensors by calling [OH_NNExecutor_GetInputCount](capi-neural-network-core-h.md#oh_nnexecutor_getinputcount).

As output parameters, <b>\*minInputDims</b> and <b>\*maxInputDims</b> cannot be null pointers. Otherwise, an error is returned. For example, you should define **int32_t\* minInDims = NULL**, and then pass **&minInDims** as an input parameter.

You do not need to release the memory of <b>minInputDims</b> and <b>maxInputDims</b>. It is released with <b>executor</b>.

**Since**: 11

**Parameters**

| Name| Description|
| -- | -- |
| [const OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|
| size_t index | Index value of the input tensor.|
| size_t **minInputDims | Pointer to the returned array, which saves the minimum dimension of the specified input tensor (the number of dimensions matches the shape).|
| size_t **maxInputDims | Pointer to the returned array, which saves the maximum dimension of the specified input tensor (the number of dimensions matches the shape).|
| size_t *shapeLength | Number of dimensions of the returned input tensor, which is the same as the shape.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNExecutor_SetOnRunDone()

```
OH_NN_ReturnCode OH_NNExecutor_SetOnRunDone(OH_NNExecutor *executor, NN_OnRunDone onRunDone)
```

**Description**

Sets the callback processing function invoked when the asynchronous inference ends.

For details about the callback function, see [NN_OnRunDone](capi-neural-network-runtime-type-h.md#nn_onrundone).

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|
| [NN_OnRunDone](capi-neural-network-runtime-type-h.md#nn_onrundone) onRunDone | Handle of the callback function [NN_OnRunDone](capi-neural-network-runtime-type-h.md#nn_onrundone).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNExecutor_SetOnServiceDied()

```
OH_NN_ReturnCode OH_NNExecutor_SetOnServiceDied(OH_NNExecutor *executor, NN_OnServiceDied onServiceDied)
```

**Description**

Sets the callback processing function invoked when the device driver service terminates unexpectedly during asynchronous inference.

For details about the callback function, see [NN_OnServiceDied](capi-neural-network-runtime-type-h.md#nn_onservicedied).

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|
| [NN_OnServiceDied](capi-neural-network-runtime-type-h.md#nn_onservicedied) onServiceDied | Handle of the callback function [NN_OnServiceDied](capi-neural-network-runtime-type-h.md#nn_onservicedied).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNExecutor_RunSync()

```
OH_NN_ReturnCode OH_NNExecutor_RunSync(OH_NNExecutor *executor,NN_Tensor *inputTensor[],size_t inputCount,NN_Tensor *outputTensor[],size_t outputCount)
```

**Description**

Performs synchronous inference.

You need to create input and output tensors by calling [OH_NNTensor_Create](capi-neural-network-core-h.md#oh_nntensor_create), [OH_NNTensor_CreateWithSize](capi-neural-network-core-h.md#oh_nntensor_createwithsize), or [OH_NNTensor_CreateWithFd](capi-neural-network-core-h.md#oh_nntensor_createwithfd). Then, use [OH_NNTensor_GetDataBuffer](capi-neural-network-core-h.md#oh_nntensor_getdatabuffer) to obtain the pointer to tensor data and copy the input data to it. The executor performs model inference, generates the inference result, and writes the result to the output tensor.

If the output tensor has a dynamic shape, you can obtain the actual shape of the output tensor by calling [OH_NNExecutor_GetOutputShape](capi-neural-network-core-h.md#oh_nnexecutor_getoutputshape). Alternatively, obtain the tensor description from the input tensor by calling [OH_NNTensor_GetTensorDesc](capi-neural-network-core-h.md#oh_nntensor_gettensordesc), and then obtain the actual shape by calling [OH_NNTensorDesc_GetShape](capi-neural-network-core-h.md#oh_nntensordesc_getshape).

**Since**: 11


**Parameters**

| Name                                                                  | Description|
|-----------------------------------------------------------------------| -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|
| [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) *inputTensor[]                                          | Array of input tensors.|
| size_t inputCount                                                     | Number of input tensors.|
| [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) *outputTensor[]                                             | Array of output tensors.|
| size_t outputCount                                                    | Number of output tensors.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNExecutor_RunAsync()

```
OH_NN_ReturnCode OH_NNExecutor_RunAsync(OH_NNExecutor *executor,NN_Tensor *inputTensor[],size_t inputCount,NN_Tensor *outputTensor[],size_t outputCount,int32_t timeout,void *userData)
```

**Description**

Performs asynchronous inference.

You need to create input and output tensors by calling [OH_NNTensor_Create](capi-neural-network-core-h.md#oh_nntensor_create), [OH_NNTensor_CreateWithSize](capi-neural-network-core-h.md#oh_nntensor_createwithsize), or [OH_NNTensor_CreateWithFd](capi-neural-network-core-h.md#oh_nntensor_createwithfd). Then, use [OH_NNTensor_GetDataBuffer](capi-neural-network-core-h.md#oh_nntensor_getdatabuffer) to obtain the pointer to tensor data and copy the input data to it. The executor performs model inference, generates the inference result, and writes the result to the output tensor.

If the output tensor has a dynamic shape, you can obtain the actual shape of the output tensor by calling [OH_NNExecutor_GetOutputShape](capi-neural-network-core-h.md#oh_nnexecutor_getoutputshape). Alternatively, obtain the tensor description from the input tensor by calling [OH_NNTensor_GetTensorDesc](capi-neural-network-core-h.md#oh_nntensor_gettensordesc), and then obtain the actual shape by calling [OH_NNTensorDesc_GetShape](capi-neural-network-core-h.md#oh_nntensordesc_getshape).

This API works in non-blocking mode and returns the result immediately after being called. You can obtain the inference result and execution return status through the [NN_OnRunDone](capi-neural-network-runtime-type-h.md#nn_onrundone) callback. If the device driver service stops abnormally during execution, you can use the [NN_OnServiceDied](capi-neural-network-runtime-type-h.md#nn_onservicedied) callback for exception processing.

You can set the NN_OnRunDone](capi-neural-network-runtime-type-h.md#nn_onrundone) and [NN_OnServiceDied](capi-neural-network-runtime-type-h.md#nn_onservicedied) callbacks by calling [OH_NNExecutor_SetOnRunDone](capi-neural-network-core-h.md#oh_nnexecutor_setonrundone) and [OH_NNExecutor_SetOnServiceDied](capi-neural-network-core-h.md#oh_nnexecutor_setonservicedied).

If the inference times out, it is terminated immediately and the error code [OH_NN_TIMEOUT](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned through the [NN_OnRunDone](capi-neural-network-runtime-type-h.md#nn_onrundone) callback.

**userData** is the identifier used to distinguish different asynchronous inferences and is returned as the first parameter in the callback. You can use any data that can distinguish different inferences as the identifier.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) *executor | Pointer to the [OH_NNExecutor](capi-neuralnetworkruntime-oh-nnexecutor.md) instance.|
| [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) *inputTensor[] | Array of input tensors.|
| size_t inputCount | Number of input tensors.|
| [NN_Tensor](capi-neuralnetworkruntime-nn-tensor.md) *outputTensor[] | Array of output tensors.|
| size_t outputCount | Number of output tensors.|
| int32_t timeout | Timeout interval of asynchronous inference, in ms. For example, **1000** indicates that the timeout interval is 1000 ms.|
| void *userData | Identifier of asynchronous inference.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNDevice_GetAllDevicesID()

```
OH_NN_ReturnCode OH_NNDevice_GetAllDevicesID(const size_t **allDevicesID, uint32_t *deviceCount)
```

**Description**

Obtains the ID of the device connected to NNRt.

Each device has a unique and fixed ID, which is returned through a uint32_t array.

When device IDs are returned through the size_t array, each element of the array is the ID of a single device. Internal management is used for array memory. The data pointer remains valid before this API is called next time.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const size_t **allDevicesID | Pointer to the **size_t** array. The input *allDevicesID must be a null pointer. Otherwise, the error code [OH_NN_INVALID_PARAMETER](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned.|
| uint32_t *deviceCount | Pointer of the uint32_t type, which is used to return the length of **\*allDevicesID**.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNDevice_GetName()

```
OH_NN_ReturnCode OH_NNDevice_GetName(size_t deviceID, const char **name)
```

**Description**

Obtains the name of the specified device.

**deviceID** specifies the device ID used to obtain the device name. The device ID needs to be obtained by calling [OH_NNDevice_GetAllDevicesID](capi-neural-network-core-h.md#oh_nndevice_getalldevicesid). If the value of **deviceID** is **0**, the first device in the device list is used by default. **\*name** is a C-style string ended with **'\0'**. **\*name** must be a null pointer. Otherwise, the error code [OH_NN_INVALID_PARAMETER](capi-neural-network-runtime-type-h.md#oh_nn_returncode) is returned. For example, you should define **char\* deviceName = NULL**, and then pass **&deviceName** as an input parameter.

**Since**: 9

**Parameters**

| Name| Description|
| -- | -- |
| size_t deviceID | Device ID. If the value of **deviceID** is **0**, the first device in the device list is used by default.|
| const char **name | Pointer to the char array, which saves the returned device name.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|

### OH_NNDevice_GetType()

```
OH_NN_ReturnCode OH_NNDevice_GetType(size_t deviceID, OH_NN_DeviceType *deviceType)
```

**Description**

Obtains the type of the specified device.

**deviceID** specifies the device ID used to obtain the device type. If the value of **deviceID** is **0**, the first device in the device list is used by default. Currently, the following device types are supported:

- **OH_NN_CPU**: CPU device.

- **OH_NN_GPU**: GPU device.
- **OH_NN_ACCELERATOR**: machine learning dedicated accelerator.
- * - **OH_NN_OTHERS**: other device types.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| size_t deviceID | Device ID. If the value of **deviceID** is **0**, the first device in the device list is used by default.|
| [OH_NN_DeviceType](capi-neural-network-runtime-type-h.md#oh_nn_devicetype) *deviceType | Pointer to the [OH_NN_DeviceType](capi-neural-network-runtime-type-h.md#oh_nn_devicetype) instance. The device type information is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode) | Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error is returned. For details about the error codes, see [OH_NN_ReturnCode](capi-neural-network-runtime-type-h.md#oh_nn_returncode).|
