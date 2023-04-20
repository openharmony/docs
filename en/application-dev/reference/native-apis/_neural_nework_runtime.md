

### OH_NNCompilation_Construct()

  
```
OH_NNCompilation* OH_NNCompilation_Construct (const OH_NNModel * model)
```
**Description**<br>
Creates a compilation instance of the [OH_NNCompilation](#oh_nncompilation) type.

After the OH_NNModel module completes model construction, APIs provided by the OH_NNCompilation module pass the model to underlying device for compilation. This method creates a [OH_NNCompilation](#oh_nncompilation) instance based on the passed [OH_NNModel](#oh_nnmodel) instance. The [OH_NNCompilation_SetDevice](#oh_nncompilation_setdevice) method is called

to set the device to compile on, and [OH_NNCompilation_Build](#oh_nncompilation_build) is then called to complete compilation.

In addition to computing device selection, the OH_NNCompilation module supports features such as model caching, performance preference, priority setting, and float16 computing, which can be implemented by the following methods:

- [OH_NNCompilation_SetCache](#oh_nncompilation_setcache)

- [OH_NNCompilation_SetPerformanceMode](#oh_nncompilation_setperformancemode)

- [OH_NNCompilation_SetPriority](#oh_nncompilation_setpriority)

- [OH_NNCompilation_EnableFloat16](#oh_nncompilation_enablefloat16)

After [OH_NNCompilation](#oh_nncompilation) is created by calling this method, the [OH_NNModel](#oh_nnmodel) instance can be released.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| model | Pointer to the [OH_NNModel](#oh_nnmodel) instance.  | 

**Returns**

Returns the pointer to a [OH_NNCompilation](#oh_nncompilation) instance.


### OH_NNCompilation_Destroy()

  
```
void OH_NNCompilation_Destroy (OH_NNCompilation ** compilation)
```
**Description**<br>
Releases the **Compilation** object.

This method needs to be called to release the compilation instance created by calling [OH_NNCompilation_Construct](#oh_nncompilation_construct). Otherwise, memory leak will occur.

If **compilation** or **\*compilation** is a null pointer, this method only prints warning logs and does not execute the release logic.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| compilation | Level-2 pointer to the [OH_NNCompilation](#oh_nncompilation) instance. After a compilation instance is destroyed, this method sets **\*compilation** to a null pointer.  | 


### OH_NNCompilation_EnableFloat16()

  
```
OH_NN_ReturnCode OH_NNCompilation_EnableFloat16 (OH_NNCompilation * compilation, bool enableFloat16 )
```
**Description**<br>
Enables float16 for computing.

Currently, Neural Network Runtime supports only float32 and int8. If this method is called on a device that supports float16, float16 will be used for computing the float32 model to reduce memory usage and execution time.

If this method is called on the device that does not support float16, the OH_NN_UNAVALIDABLE_DEVICE error code is returned.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| compilation | Pointer to the [OH_NNCompilation](#oh_nncompilation) instance.  | 
| enableFloat16 | Indicates whether to enable float16. If this parameter is set to **true**, float16 inference is performed. If this parameter is set to **false**, float32 inference is performed.  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNCompilation_SetCache()

  
```
OH_NN_ReturnCode OH_NNCompilation_SetCache (OH_NNCompilation * compilation, const char * cachePath, uint32_t version )
```
**Description**<br>
Set the cache directory and version of the compiled model.

On the device that supports caching, a model can be saved as a cache file after being compiled at the device driver layer. The model can be directly read from the cache file in the next compilation, saving recompilation time. This method performs different operations based on the passed cache directory and version:

- No file exists in the cache directory: Caches the compiled model to the directory and sets the cache version to **version**.

- A complete cache file exists in the cache directory, and its version is **version**: Reads the cache file in the path and passes the data to the underlying device for conversion into executable model instances.

- A complete cache file exists in the cache directory, and its version is earlier than **version**: When model compilation is complete on the underlying device, overwrites the cache file and changes the version number to **version**.

- A complete cache file exists in the cache directory, and its version is later than **version**: Returns the OH_NN_INVALID_PARAMETER error code without reading the cache file.

- The cache file in the cache directory is incomplete or you do not have the permission to access the cache file. Returns the OH_NN_INVALID_FILE error code.

- The cache directory does not exist or you do not have the access permission. Returns the OH_NN_INVALID_PATH error code.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| compilation | Pointer to the [OH_NNCompilation](#oh_nncompilation) instance.  | 
| cachePath | Directory for storing model cache files. This method creates directories for different devices in the **cachePath** directory. You are advised to use a separate cache directory for each model.  | 
| version | Cache version.  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNCompilation_SetDevice()

  
```
OH_NN_ReturnCode OH_NNCompilation_SetDevice (OH_NNCompilation * compilation, size_t deviceID )
```
**Description**<br>
Specifies the device for model compilation and computing.

In the compilation phase, you need to specify the device for model compilation and computing. Call [OH_NNDevice_GetAllDevicesID](#oh_nndevice_getalldevicesid) to obtain available device IDs. Call [OH_NNDevice_GetType](#oh_nndevice_gettype) and [OH_NNDevice_GetName](#oh_nndevice_getname) to obtain device information and pass target device IDs to this method for setting.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| compilation | Pointer to the [OH_NNCompilation](#oh_nncompilation) instance.  | 
| deviceID | Device ID.  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNCompilation_SetPerformanceMode()

  
```
OH_NN_ReturnCode OH_NNCompilation_SetPerformanceMode (OH_NNCompilation * compilation, OH_NN_PerformanceMode performanceMode )
```
**Description**<br>
Sets the performance mode for model computing.

Neural Network Runtime allows you to set the performance mode for model computing to meet the requirements of low power consumption and ultimate performance. If this method is not called to set the performance mode in the compilation phase, the compilation instance assigns the OH_NN_PERFORMANCE_NONE mode for the model by default. In this case, the device performs computing in the default performance mode.

If this method is called on the device that does not support the setting of the performance mode, the OH_NN_UNAVALIDABLE_DEVICE error code is returned.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| compilation | Pointer to the [OH_NNCompilation](#oh_nncompilation) instance.  | 
| performanceMode | Performance mode. For details about the available performance modes, see [OH_NN_PerformanceMode](#oh_nn_performancemode).  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNCompilation_SetPriority()

  
```
OH_NN_ReturnCode OH_NNCompilation_SetPriority (OH_NNCompilation * compilation, OH_NN_Priority priority )
```
**Description**<br>
Sets the model computing priority.

Neural Network Runtime allows you to set computing priorities for models.

The priorities apply only to models created by the process with the same UID. The settings will not affect models created by processes with different UIDs on different devices.

If this method is called on the device that does not support the priority setting, the OH_NN_UNAVALIDABLE_DEVICE error code is returned.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| compilation | Pointer to the [OH_NNCompilation](#oh_nncompilation) instance.  | 
| priority | Priority. For details about the optional priorities, see [OH_NN_Priority](#oh_nn_priority).  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNDevice_GetAllDevicesID()

  
```
OH_NN_ReturnCode OH_NNDevice_GetAllDevicesID (const size_t ** allDevicesID, uint32_t * deviceCount )
```
**Description**<br>
Obtains the ID of the device connected to Neural Network Runtime.

Each device has a unique and fixed ID in Neural Network Runtime. This method returns device IDs on the current device through the uint32_t array.

Device IDs are returned through the size_t array. Each element of the array is the ID of a single device. The array memory is managed by Neural Network Runtime. The data pointer is valid before this method is called next time.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| allDevicesID | Pointer to the size_t array. The input **\*allDevicesID** must be a null pointer. Otherwise, OH_NN_INVALID_PARAMETER is returned. | 
| deviceCount | Pointer of the uint32_t type, which is used to return the length of **(\*allDevicesID)**.  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNDevice_GetName()

  
```
OH_NN_ReturnCode OH_NNDevice_GetName (size_t deviceID, const char ** name )
```
**Description**<br>
Obtains the name of the specified device.

**deviceID** specifies the device whose name will be obtained. The device ID needs to be obtained by calling [OH_NNDevice_GetAllDevicesID](#oh_nndevice_getalldevicesid).

 **Parameters**

| Name | Description | 
| -------- | -------- |
| deviceID | Device ID.  | 
| name | Pointer to the char array. The passed **(\*char)** must be a null pointer. Otherwise, OH_NN_INVALID_PARAMETER is returned. The value of **(\*name)** is a C-style string ended with **'\0'**.  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNDevice_GetType()

  
```
OH_NN_ReturnCode OH_NNDevice_GetType (size_t deviceID, OH_NN_DeviceType * deviceType )
```
**Description**<br>
Obtains the type information of the specified device.

**deviceID** specifies the device whose type will be obtained. Currently, Neural Network Runtime supports the following device types:

- **OH_NN_CPU**: CPU device.

- **OH_NN_GPU**: GPU device.

- **OH_NN_ACCELERATOR**: machine learning dedicated accelerator.

- **OH_NN_OTHERS**: other hardware types.
参数返回Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode). since 9 版本1.0 


### OH_NNExecutor_AllocateInputMemory()

  
```
OH_NN_Memory* OH_NNExecutor_AllocateInputMemory (OH_NNExecutor * executor, uint32_t inputIndex, size_t length )
```
**Description**<br>
Allocates shared memory to a single input on a device.

Neural Network Runtime provides a method for proactively allocating shared memory on a device. By specifying the executor and input index value, this method allocates shared memory whose size is specified by **length** on the device associated with a single input and returns the operation result through the [OH_NN_Memory](_o_h___n_n___memory.md) instance.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| executor | Pointer to the [OH_NNExecutor](#oh_nnexecutor) instance.  | 
| inputIndex | Input index value, which is in the same sequence of the data input when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. Assume that the value of **inputIndices** is **{1, 5, 9}** when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. In the memory input application, the index value for the three inputs is **{0, 1, 2}**. | 
| length | Memory size to be applied for, in bytes.  | 

**Returns**

Pointer to a [OH_NN_Memory](_o_h___n_n___memory.md) instance.


### OH_NNExecutor_AllocateOutputMemory()

  
```
OH_NN_Memory* OH_NNExecutor_AllocateOutputMemory (OH_NNExecutor * executor, uint32_t outputIndex, size_t length )
```
**Description**<br>
Allocates shared memory to a single output on a device.

Neural Network Runtime provides a method for proactively allocating shared memory on a device. By specifying the executor and output index value, this method allocates shared memory whose size is specified by **length** on the device associated with a single output and returns the operation result through the [OH_NN_Memory](_o_h___n_n___memory.md) instance.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| executor | Pointer to the [OH_NNExecutor](#oh_nnexecutor) instance.  | 
| outputIndex | Output Index value, which is in the same sequence of the data output when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. Assume that the value of **outputIndices** is **{4, 6, 8}** when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. In output memory application, the index value for the three outputs is **{0, 1, 2}**. | 
| length | Memory size to be applied for, in bytes.  | 

**Returns**

Pointer to a [OH_NN_Memory](_o_h___n_n___memory.md) instance.


### OH_NNExecutor_Construct()

  
```
OH_NNExecutor* OH_NNExecutor_Construct (OH_NNCompilation * compilation)
```
**Description**<br>
Creates an executor instance of the [OH_NNExecutor](#oh_nnexecutor) type.

This method constructs a model inference executor associated with the device based on the passed compiler. Use [OH_NNExecutor_SetInput](#oh_nnexecutor_setinput) to set the model input data. After the input data is set, call [OH_NNExecutor_Run](#oh_nnexecutor_run) to perform inference and then call [OH_NNExecutor_SetOutput](#oh_nnexecutor_setoutput) to obtain the computing result.

After calling this method to create the [OH_NNExecutor](#oh_nnexecutor) instance, you can release the [OH_NNCompilation](#oh_nncompilation) instance if you do not need to create any other executors.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| compilation | Pointer to the [OH_NNCompilation](#oh_nncompilation) instance.  | 

**Returns**

Pointer to a [OH_NNExecutor](#oh_nnexecutor) instance.


### OH_NNExecutor_Destroy()

  
```
void OH_NNExecutor_Destroy (OH_NNExecutor ** executor)
```
**Description**<br>
Destroys an executor instance to release the memory occupied by the executor.

This method needs to be called to release the executor instance created by calling [OH_NNExecutor_Construct](#oh_nnexecutor_construct). Otherwise, memory leak will occur.

If **executor** or **\*executor** is a null pointer, this method only prints warning logs and does not execute the release logic.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| executor | Level-2 pointer to the [OH_NNExecutor](#oh_nnexecutor) instance.  | 


### OH_NNExecutor_DestroyInputMemory()

  
```
void OH_NNExecutor_DestroyInputMemory (OH_NNExecutor * executor, uint32_t inputIndex, OH_NN_Memory ** memory )
```
**Description**<br>
Releases the input memory to which the [OH_NN_Memory](_o_h___n_n___memory.md) instance points.

This method needs to be called to release the memory instance created by calling [OH_NNExecutor_AllocateInputMemory](#oh_nnexecutor_allocateinputmemory). Otherwise, memory leak will occur. The mapping between **inputIndex** and **memory** must be the same as that in memory instance creation.

If **memory** or **\*memory** is a null pointer, this method only prints warning logs and does not execute the release logic.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| executor | Pointer to the [OH_NNExecutor](#oh_nnexecutor) instance.  | 
| inputIndex | Input index value, which is in the same sequence of the data input when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. Assume that the value of **inputIndices** is **{1, 5, 9}** when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. In memory input release, the index value for the three inputs is **{0, 1, 2}**. | 
| memory | Level-2 pointer to the [OH_NN_Memory](_o_h___n_n___memory.md) instance. After shared memory is destroyed, this method sets **\*memory** to a null pointer.  | 


### OH_NNExecutor_DestroyOutputMemory()

  
```
void OH_NNExecutor_DestroyOutputMemory (OH_NNExecutor * executor, uint32_t outputIndex, OH_NN_Memory ** memory )
```
**Description**<br>
Releases the output memory to which the [OH_NN_Memory](_o_h___n_n___memory.md) instance points.

This method needs to be called to release the memory instance created by calling [OH_NNExecutor_AllocateOutputMemory](#oh_nnexecutor_allocateoutputmemory). Otherwise, memory leak will occur. The mapping between **outputIndex** and **memory** must be the same as that in memory instance creation.

If **memory** or **\*memory** is a null pointer, this method only prints warning logs and does not execute the release logic.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| executor | Pointer to the [OH_NNExecutor](#oh_nnexecutor) instance.  | 
| outputIndex | Output Index value, which is in the same sequence of the data output when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. Assume that the value of **outputIndices** is **{4, 6, 8}** when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. In output memory release, the index value for the three outputs is **{0, 1, 2}**. | 
| memory | Level-2 pointer to the [OH_NN_Memory](_o_h___n_n___memory.md) instance. After shared memory is destroyed, this method sets **\*memory** to a null pointer.  | 


### OH_NNExecutor_GetOutputShape()

  
```
OH_NN_ReturnCode OH_NNExecutor_GetOutputShape (OH_NNExecutor * executor, uint32_t outputIndex, int32_t ** shape, uint32_t * shapeLength )
```
**Description**<br>
Obtains the dimension information about the output tensor.

After [OH_NNExecutor_Run](#oh_nnexecutor_run) is called to complete a single inference, call this method to obtain the specified output dimension information and number of dimensions. It is commonly used in dynamic shape input and output scenarios.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| executor | Pointer to the [OH_NNExecutor](#oh_nnexecutor) instance.  | 
| outputIndex | Output Index value, which is in the same sequence of the data output when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. Assume that **outputIndices** is **{4, 6, 8}** when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. When [OH_NNExecutor_GetOutputShape](#oh_nnexecutor_getoutputshape) is called to obtain dimension information about the output tensor, **outputIndices** is **{0, 1, 2}**. | 
| shape | Pointer to the int32_t array. The value of each element in the array is the length of the output tensor in each dimension.  | 
| shapeLength | Pointer to the uint32_t type. The number of output dimensions is returned.  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNExecutor_Run()

  
```
OH_NN_ReturnCode OH_NNExecutor_Run (OH_NNExecutor * executor)
```
**Description**<br>
Performs inference.

Performs end-to-end inference and computing of the model on the device associated with the executor.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| executor | Pointer to the [OH_NNExecutor](#oh_nnexecutor) instance.  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNExecutor_SetInput()

  
```
OH_NN_ReturnCode OH_NNExecutor_SetInput (OH_NNExecutor * executor, uint32_t inputIndex, const OH_NN_Tensor * tensor, const void * dataBuffer, size_t length )
```
**Description**<br>
Sets the single input data for a model.

This method copies the data whose length is specified by **length** (in bytes) in **dataBuffer** to the shared memory of the underlying device. **inputIndex** specifies the input to be set and **tensor** sets information such as the input shape, type, and quantization parameters.

Neural Network Runtime supports models with dynamical shape input. For fixed shape input and dynamic shape input scenarios, this method uses different processing policies.

- Fixed shape input: The attributes of **tensor** must be the same as those of the tensor added by calling [OH_NNModel_AddTensor](#oh_nnmodel_addtensor) in the composition phase.

- Dynamic shape input: In the composition phase, because the shape is not fixed, each value in **tensor.dimensions** must be greater than **0** in the method calls to determine the shape input in the calculation phase. When setting the shape, you can modify only the dimension whose value is **-1**. Assume that **[-1, 224, 224, 3]** is input as the the dimension of A in the composition phase. When this method is called, only the size of the first dimension can be modified, for example, to **[3, 224, 224, 3]**. If other dimensions are adjusted, OH_NN_INVALID_PARAMETER is returned.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| executor | Pointer to the [OH_NNExecutor](#oh_nnexecutor) instance.  | 
| inputIndex | Input index value, which is in the same sequence of the data input when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. Assume that the value of **inputIndices** is **{1, 5, 9}** when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. In input settings, the index value for the three inputs is **{0, 1, 2}**. | 
| tensor | Sets the tensor corresponding to the input data.  | 
| dataBuffer | Pointer to the input data.  | 
| length | Length of the data buffer, in bytes.  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNExecutor_SetInputWithMemory()

  
```
OH_NN_ReturnCode OH_NNExecutor_SetInputWithMemory (OH_NNExecutor * executor, uint32_t inputIndex, const OH_NN_Tensor * tensor, const OH_NN_Memory * memory )
```
**Description**<br>
Specifies the hardware shared memory pointed to by the [OH_NN_Memory](_o_h___n_n___memory.md) instance as the shared memory used by a single input.

In scenarios where memory needs to be managed by yourself, this method binds the execution input to the [OH_NN_Memory](_o_h___n_n___memory.md) memory instance. During computing, the underlying device reads the input data from the shared memory pointed to by the memory instance. By using this method, concurrent execution of input setting, computing, and read can be implemented to improve inference efficiency of a data flow.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| executor | Pointer to the [OH_NNExecutor](#oh_nnexecutor) instance.  | 
| inputIndex | Input index value, which is in the same sequence of the data input when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. Assume that the value of **inputIndices** is **{1, 5, 9}** when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. When the input shared memory is specified, the index value for the three inputs is **{0, 1, 2}**. | 
| tensor | Pointer to [OH_NN_Tensor](_o_h___n_n___tensor.md), used to set the tensor corresponding to a single input.  | 
| memory | Pointer to [OH_NN_Memory](_o_h___n_n___memory.md).  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNExecutor_SetOutput()

  
```
OH_NN_ReturnCode OH_NNExecutor_SetOutput (OH_NNExecutor * executor, uint32_t outputIndex, void * dataBuffer, size_t length )
```
**Description**<br>
Sets the buffer for a single output of a model.

This method binds the buffer to which **dataBuffer** points to the output specified by **outputIndex**. The length of the buffer is specified by **length**.

After [OH_NNExecutor_Run](#oh_nnexecutor_run) is called to complete a single model inference, Neural Network Runtime compares the length of the buffer to which **dataBuffer** points with the length of the output data and returns different results based on the actual situation.

- If the buffer length is greater than or equal to the data length, the inference result is copied to the buffer and OH_NN_SUCCESS is returned. You can read the inference result from **dataBuffer**.

- If the buffer length is smaller than the data length, [OH_NNExecutor_Run](#oh_nnexecutor_run) returns OH_NN_INVALID_PARAMETER and generates a log indicating that the buffer is too small.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| executor | Pointer to the [OH_NNExecutor](#oh_nnexecutor) instance.  | 
| outputIndex | Output Index value, which is in the same sequence of the data output when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. Assume that the value of **outputIndices** is **{4, 6, 8}** when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. In output buffer settings, the index value for the three outputs is **{0, 1, 2}**. | 
| dataBuffer | Pointer to the output data.  | 
| length | Length of the data buffer, in bytes.  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNExecutor_SetOutputWithMemory()

  
```
OH_NN_ReturnCode OH_NNExecutor_SetOutputWithMemory (OH_NNExecutor * executor, uint32_t outputIndex, const OH_NN_Memory * memory )
```
**Description**<br>
Specifies the hardware shared memory pointed to by the [OH_NN_Memory](_o_h___n_n___memory.md) instance as the shared memory used by a single output.

In scenarios where memory needs to be managed by yourself, this method binds the execution output to the [OH_NN_Memory](_o_h___n_n___memory.md) memory instance. When computing is performed, the underlying hardware directly writes the computing result to the shared memory to which the memory instance points. By using this method, concurrent execution of input setting, computing, and read can be implemented to improve inference efficiency of a data flow.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| executor | Executor.  | 
| outputIndex | Output Index value, which is in the same sequence of the data output when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. Assume that the value of **outputIndices** is **{4, 6, 8}** when [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) is called. When output shared memory is specified, the index value for the three outputs is **{0, 1, 2}**. | 
| memory | Pointer to [OH_NN_Memory](_o_h___n_n___memory.md).  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNModel_AddOperation()

  
```
OH_NN_ReturnCode OH_NNModel_AddOperation (OH_NNModel * model, OH_NN_OperationType op, const OH_NN_UInt32Array * paramIndices, const OH_NN_UInt32Array * inputIndices, const OH_NN_UInt32Array * outputIndices )
```
**Description**<br>
Adds an operator to a model instance.

This method is used to add an operator to a model instance. The operator type is specified by **op**, and the operator parameters, inputs, and outputs are specified by **paramIndices**, **inputIndices**, and **outputIndices** respectively. This method verifies the attributes of operator parameters and the number of input and output parameters. These attributes must be correctly set when [OH_NNModel_AddTensor](#oh_nnmodel_addtensor) is called to add tensors. For details about the expected parameters, input attributes, and output attributes of each operator, see [OH_NN_OperationType](#oh_nn_operationtype).

**paramIndices**, **inputIndices**, and **outputIndices** store index values of tensors. Index values are determined by the sequence in which tensors are added to the model. For details about how to add a tensor, see [OH_NNModel_AddTensor](#oh_nnmodel_addtensor).

If unnecessary parameters are added for adding an operator, this method returns OH_NN_INVALID_PARAMETER. If no operator parameter is set, the operator uses the default parameter value. For details about the default values, see [OH_NN_OperationType](#oh_nn_operationtype).

 **Parameters**

| Name | Description | 
| -------- | -------- |
| model | Pointer to the [OH_NNModel](#oh_nnmodel) instance.  | 
| op | Specifies the type of an operator to be added. For details, see the enumerated values of [OH_NN_OperationType](#oh_nn_operationtype).  | 
| paramIndices | Pointer to the **[OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md)** instance, which is used to set operator parameters.  | 
| inputIndices | Pointer to the **[OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md)** instance, which is used to set the operator input.  | 
| outputIndices | Pointer to the **[OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md)** instance, which is used to set the operator output.  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNModel_AddTensor()

  
```
OH_NN_ReturnCode OH_NNModel_AddTensor (OH_NNModel * model, const OH_NN_Tensor * tensor )
```
**Description**<br>
Adds a tensor to a model instance.

The data node and operator parameters in the Neural Network Runtime model are composed of tensors of the model. This method is used to add tensors to a model instance based on the **tensor** parameter. The sequence of adding tensors is specified by the index value recorded in the model. The [OH_NNModel_SetTensorData](#oh_nnmodel_settensordata), [OH_NNModel_AddOperation](#oh_nnmodel_addoperation), and [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) methods specifies tensors based on the index value.

Neural Network Runtime supports inputs and outputs of the dynamic shape. When adding a data node with a dynamic shape, you need to set the dimensions that support dynamic changes in **tensor.dimensions** to **-1**. For example, if **tensor.dimensions** of a four-dimensional tensor is set to **[1, -1, 2, 2]**, the second dimension supports dynamic changes.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| model | Pointer to the [OH_NNModel](#oh_nnmodel) instance.  | 
| tensor | Pointer to the [OH_NN_Tensor](_o_h___n_n___tensor.md) tensor. The tensor specifies the attributes of the tensor added to the model instance.  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNModel_Construct()

  
```
OH_NNModel* OH_NNModel_Construct (void )
```
**Description**<br>
Creates a model instance of the [OH_NNModel](#oh_nnmodel) type and uses other APIs provided by OH_NNModel to construct the model instance.

Before composition, call [OH_NNModel_Construct](#oh_nnmodel_construct) to create a model instance. Based on the model topology, call the [OH_NNModel_AddTensor](#oh_nnmodel_addtensor), [OH_NNModel_AddOperation](#oh_nnmodel_addoperation), and [OH_NNModel_SetTensorData](#oh_nnmodel_settensordata) methods to fill in the data and operator nodes of the model, and then call [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) to specify the inputs and outputs of the model. After the model topology is constructed, call [OH_NNModel_Finish](#oh_nnmodel_finish) to build the model.

After a model instance is used, you need to destroy it by calling [OH_NNModel_Destroy](#oh_nnmodel_destroy) to avoid memory leak.

**Returns**

Returns the pointer to a [OH_NNModel](#oh_nnmodel) instance.


### OH_NNModel_Destroy()

  
```
void OH_NNModel_Destroy (OH_NNModel ** model)
```
**Description**<br>
Releases a model instance.

This method needs to be called to release the model instance created by calling [OH_NNModel_Construct](#oh_nnmodel_construct). Otherwise, memory leak will occur.

If **model** or **\*model** is a null pointer, this method only prints warning logs and does not execute the release logic.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| model | Level-2 pointer to the [OH_NNModel](#oh_nnmodel) instance. After a model instance is destroyed, this method sets **\*model** to a null pointer.  | 


### OH_NNModel_Finish()

  
```
OH_NN_ReturnCode OH_NNModel_Finish (OH_NNModel * model)
```
**Description**<br>
Completes model composition.

After the model topology is set up, call this method to indicate that the composition is complete. After this method is called, additional composition operations cannot be performed. If [OH_NNModel_AddTensor](#oh_nnmodel_addtensor), [OH_NNModel_AddOperation](#oh_nnmodel_addoperation), [OH_NNModel_SetTensorData](#oh_nnmodel_settensordata), and [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) are called, OH_NN_OPERATION_FORBIDDEN is returned.

Before calling [OH_NNModel_GetAvailableOperations](#oh_nnmodel_getavailableoperations) and [OH_NNCompilation_Construct](#oh_nncompilation_construct), you must call this method to complete composition.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| model | Pointer to the [OH_NNModel](#oh_nnmodel) instance.  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNModel_GetAvailableOperations()

  
```
OH_NN_ReturnCode OH_NNModel_GetAvailableOperations (OH_NNModel * model, size_t deviceID, const bool ** isSupported, uint32_t * opCount )
```
**Description**<br>
Queries whether the device supports operators in the model. The support status is indicated by the Boolean value.

Queries whether underlying device supports operators in a model instance. The device is specified by **deviceID**, and the result is represented by the array pointed by **isSupported**. If the ith operator is supported, the value of **(\*isSupported)**[i] is **true**. Otherwise, the value is **false**.

After this method is successfully executed, **(\*isSupported)** points to the bool array that records the operator support status. The operator quantity for the array length is the same as that for the model instance. The memory corresponding to this array is managed by Neural Network Runtime and is automatically destroyed after the model instance is destroyed or this method is called again.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| model | Pointer to the [OH_NNModel](#oh_nnmodel) instance.  | 
| deviceID | Device ID to be queried, which can be obtained by using [OH_NNDevice_GetAllDevicesID](#oh_nndevice_getalldevicesid).  | 
| isSupported | Pointer to the bool array. When this method is called, **(\*isSupported)** must be a null pointer. Otherwise, OH_NN_INVALID_PARAMETER is returned. | 
| opCount | Number of operators in a model instance, corresponding to the length of the **(\*isSupported)** array.  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNModel_SetTensorData()

  
```
OH_NN_ReturnCode OH_NNModel_SetTensorData (OH_NNModel * model, uint32_t index, const void * dataBuffer, size_t length )
```
**Description**<br>
Sets the tensor value.

For tensors with constant values (such as model weights), you need to use this method in the composition phase. The index value of a tensor is determined by the sequence in which the tensor is added to the model. For details about how to add a tensor, see [OH_NNModel_AddTensor](#oh_nnmodel_addtensor).

 **Parameters**

| Name | Description | 
| -------- | -------- |
| model | Pointer to the [OH_NNModel](#oh_nnmodel) instance.  | 
| index | Index value of a tensor.  | 
| dataBuffer | Pointer to real data.  | 
| length | Length of the data buffer.  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


### OH_NNModel_SpecifyInputsAndOutputs()

  
```
OH_NN_ReturnCode OH_NNModel_SpecifyInputsAndOutputs (OH_NNModel * model, const OH_NN_UInt32Array * inputIndices, const OH_NN_UInt32Array * outputIndices )
```
**Description**<br>
Specifies the inputs and outputs of a model.

A tensor must be specified as the end-to-end inputs and outputs of a model instance. This type of tensor cannot be set using [OH_NNModel_SetTensorData](#oh_nnmodel_settensordata). The **OH_NNExecutor** method needs to be called in the execution phase to set the input and output data.

The index value of a tensor is determined by the sequence in which the tensor is added to the model. For details about how to add a tensor, see [OH_NNModel_AddTensor](#oh_nnmodel_addtensor).

Currently, the model inputs and outputs cannot be set asynchronously.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| model | Pointer to the [OH_NNModel](#oh_nnmodel) instance.  | 
| inputIndices | Pointer to the **[OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md)** instance, which is used to set the operator input.  | 
| outputIndices | Pointer to the **[OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md)** instance, which is used to set the operator output.  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).