# NeuralNeworkRuntime


## Overview

Provides APIs of Neural Network Runtime for accelerating the model inference.

Provides APIs for accelerating the Neural Network Runtime model inference.

\@Syscap SystemCapability.Ai.NeuralNetworkRuntime

**Since:**
9


## Summary


### Files

| Name | Description | 
| -------- | -------- |
| [neural_network_runtime.h](neural__network__runtime_8h.md) | Defines the Neural Network Runtime APIs. The AI inference framework uses the Native APIs provided by Neural Network Runtime to construct and compile models and perform inference and computing on acceleration hardware. Note: Currently, the APIs of Neural Network Runtime do not support multi-thread calling. <br>File to Include: <neural_network_runtime/neural_network_runtime.h> | 
| [neural_network_runtime_type.h](neural__network__runtime__type_8h.md) | Defines the structure and enumeration for Neural Network Runtime. <br>File to Include: <neural_network_runtime/neural_network_runtime_type.h>  | 


### Structs

| Name | Description | 
| -------- | -------- |
| [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) | This structure is used to store a 32-bit unsigned integer array.  | 
| [OH_NN_QuantParam](_o_h___n_n___quant_param.md) | Quantization information.  | 
| [OH_NN_Tensor](_o_h___n_n___tensor.md) | Defines the tensor structure.  | 
| [OH_NN_Memory](_o_h___n_n___memory.md) | Defines the memory structure.  | 


### Types

| Name | Description | 
| -------- | -------- |
| [OH_NNModel](#oh_nnmodel) | Defines the handles of models for Neural Network Runtime.  | 
| [OH_NNCompilation](#oh_nncompilation) | Defines the compiler handle for Neural Network Runtime.  | 
| [OH_NNExecutor](#oh_nnexecutor) | Defines the executor handle for Neural Network Runtime.  | 
| [OH_NN_UInt32Array](#oh_nn_uint32array) | This structure is used to store a 32-bit unsigned integer array.  | 
| [OH_NN_QuantParam](#oh_nn_quantparam) | Quantization information.  | 
| [OH_NN_Tensor](#oh_nn_tensor) | Defines the tensor structure.  | 
| [OH_NN_Memory](#oh_nn_memory) | Defines the memory structure.  | 


### Enums

| Name | Description | 
| -------- | -------- |
| [OH_NN_PerformanceMode](#oh_nn_performancemode) {<br/>OH_NN_PERFORMANCE_NONE = 0, OH_NN_PERFORMANCE_LOW = 1, OH_NN_PERFORMANCE_MEDIUM = 2, OH_NN_PERFORMANCE_HIGH = 3,<br/>OH_NN_PERFORMANCE_EXTREME = 4<br/>} | Defines the hardware performance mode.  | 
| [OH_NN_Priority](#oh_nn_priority) { OH_NN_PRIORITY_NONE = 0, OH_NN_PRIORITY_LOW = 1, OH_NN_PRIORITY_MEDIUM = 2, OH_NN_PRIORITY_HIGH = 3 } | Defines the model inference task priority.  | 
| [OH_NN_ReturnCode](#oh_nn_returncode) {<br/>OH_NN_SUCCESS = 0, OH_NN_FAILED = 1, OH_NN_INVALID_PARAMETER = 2, OH_NN_MEMORY_ERROR = 3,<br/>OH_NN_OPERATION_FORBIDDEN = 4, OH_NN_NULL_PTR = 5, OH_NN_INVALID_FILE = 6, OH_NN_UNAVALIDABLE_DEVICE = 7,<br/>OH_NN_INVALID_PATH = 8<br/>} | Defines error codes for Neural Network Runtime.  | 
| [OH_NN_FuseType](#oh_nn_fusetype) : int8_t { OH_NN_FUSED_NONE = 0, OH_NN_FUSED_RELU = 1, OH_NN_FUSED_RELU6 = 2 } | Defines activation function types in the fusion operator for Neural Network Runtime.  | 
| [OH_NN_Format](#oh_nn_format) { OH_NN_FORMAT_NONE = 0, OH_NN_FORMAT_NCHW = 1, OH_NN_FORMAT_NHWC = 2 } | Defines the layout type of tensor data.  | 
| [OH_NN_DeviceType](#oh_nn_devicetype) { OH_NN_OTHERS = 0, OH_NN_CPU = 1, OH_NN_GPU = 2, OH_NN_ACCELERATOR = 3 } | Defines device types supported by Neural Network Runtime.  | 
| [OH_NN_DataType](#oh_nn_datatype) {<br/>OH_NN_UNKNOWN = 0, OH_NN_BOOL = 1, OH_NN_INT8 = 2, OH_NN_INT16 = 3,<br/>OH_NN_INT32 = 4, OH_NN_INT64 = 5, OH_NN_UINT8 = 6, OH_NN_UINT16 = 7,<br/>OH_NN_UINT32 = 8, OH_NN_UINT64 = 9, OH_NN_FLOAT16 = 10, OH_NN_FLOAT32 = 11,<br/>OH_NN_FLOAT64 = 12<br/>} | Defines tensor data types supported by Neural Network Runtime.  | 
| [OH_NN_OperationType](#oh_nn_operationtype) {<br/>OH_NN_OPS_ADD = 1, OH_NN_OPS_AVG_POOL = 2, OH_NN_OPS_BATCH_NORM = 3, OH_NN_OPS_BATCH_TO_SPACE_ND = 4,<br/>OH_NN_OPS_BIAS_ADD = 5, OH_NN_OPS_CAST = 6, OH_NN_OPS_CONCAT = 7, OH_NN_OPS_CONV2D = 8,<br/>OH_NN_OPS_CONV2D_TRANSPOSE = 9, OH_NN_OPS_DEPTHWISE_CONV2D_NATIVE = 10, OH_NN_OPS_DIV = 11, OH_NN_OPS_ELTWISE = 12,<br/>OH_NN_OPS_EXPAND_DIMS = 13, OH_NN_OPS_FILL = 14, OH_NN_OPS_FULL_CONNECTION = 15, OH_NN_OPS_GATHER = 16,<br/>OH_NN_OPS_HSWISH = 17, OH_NN_OPS_LESS_EQUAL = 18, OH_NN_OPS_MATMUL = 19, OH_NN_OPS_MAXIMUM = 20,<br/>OH_NN_OPS_MAX_POOL = 21, OH_NN_OPS_MUL = 22, OH_NN_OPS_ONE_HOT = 23, OH_NN_OPS_PAD = 24,<br/>OH_NN_OPS_POW = 25, OH_NN_OPS_SCALE = 26, OH_NN_OPS_SHAPE = 27, OH_NN_OPS_SIGMOID = 28,<br/>OH_NN_OPS_SLICE = 29, OH_NN_OPS_SOFTMAX = 30, OH_NN_OPS_SPACE_TO_BATCH_ND = 31, OH_NN_OPS_SPLIT = 32,<br/>OH_NN_OPS_SQRT = 33, OH_NN_OPS_SQUARED_DIFFERENCE = 34, OH_NN_OPS_SQUEEZE = 35, OH_NN_OPS_STACK = 36,<br/>OH_NN_OPS_STRIDED_SLICE = 37, OH_NN_OPS_SUB = 38, OH_NN_OPS_TANH = 39, OH_NN_OPS_TILE = 40,<br/>OH_NN_OPS_TRANSPOSE = 41, OH_NN_OPS_REDUCE_MEAN = 42, OH_NN_OPS_RESIZE_BILINEAR = 43, OH_NN_OPS_RSQRT = 44,<br/>OH_NN_OPS_RESHAPE = 45, OH_NN_OPS_PRELU = 46, OH_NN_OPS_RELU = 47, OH_NN_OPS_RELU6 = 48,<br/>OH_NN_OPS_LAYER_NORM = 49, OH_NN_OPS_REDUCE_PROD = 50, OH_NN_OPS_REDUCE_ALL = 51, OH_NN_OPS_QUANT_DTYPE_CAST = 52,<br/>OH_NN_OPS_TOP_K = 53, OH_NN_OPS_ARG_MAX = 54, OH_NN_OPS_UNSQUEEZE = 55, OH_NN_OPS_GELU = 56<br/>} | Defines operator types supported by Neural Network Runtime.  | 
| [OH_NN_TensorType](#oh_nn_tensortype) {<br/>OH_NN_TENSOR = 0, OH_NN_ADD_ACTIVATIONTYPE = 1, OH_NN_AVG_POOL_KERNEL_SIZE = 2, OH_NN_AVG_POOL_STRIDE = 3,<br/>OH_NN_AVG_POOL_PAD_MODE = 4, OH_NN_AVG_POOL_PAD = 5, OH_NN_AVG_POOL_ACTIVATION_TYPE = 6, OH_NN_BATCH_NORM_EPSILON = 7,<br/>OH_NN_BATCH_TO_SPACE_ND_BLOCKSIZE = 8, OH_NN_BATCH_TO_SPACE_ND_CROPS = 9, OH_NN_CONCAT_AXIS = 10, OH_NN_CONV2D_STRIDES = 11,<br/>OH_NN_CONV2D_PAD = 12, OH_NN_CONV2D_DILATION = 13, OH_NN_CONV2D_PAD_MODE = 14, OH_NN_CONV2D_ACTIVATION_TYPE = 15,<br/>OH_NN_CONV2D_GROUP = 16, OH_NN_CONV2D_TRANSPOSE_STRIDES = 17, OH_NN_CONV2D_TRANSPOSE_PAD = 18, OH_NN_CONV2D_TRANSPOSE_DILATION = 19,<br/>OH_NN_CONV2D_TRANSPOSE_OUTPUT_PADDINGS = 20, OH_NN_CONV2D_TRANSPOSE_PAD_MODE = 21, OH_NN_CONV2D_TRANSPOSE_ACTIVATION_TYPE = 22, OH_NN_CONV2D_TRANSPOSE_GROUP = 23,<br/>OH_NN_DEPTHWISE_CONV2D_NATIVE_STRIDES = 24, OH_NN_DEPTHWISE_CONV2D_NATIVE_PAD = 25, OH_NN_DEPTHWISE_CONV2D_NATIVE_DILATION = 26, OH_NN_DEPTHWISE_CONV2D_NATIVE_PAD_MODE = 27,<br/>OH_NN_DEPTHWISE_CONV2D_NATIVE_ACTIVATION_TYPE = 28, OH_NN_DIV_ACTIVATIONTYPE = 29, OH_NN_ELTWISE_MODE = 30, OH_NN_FULL_CONNECTION_AXIS = 31,<br/>OH_NN_FULL_CONNECTION_ACTIVATIONTYPE = 32, OH_NN_MATMUL_TRANSPOSE_A = 33, OH_NN_MATMUL_TRANSPOSE_B = 34, OH_NN_MATMUL_ACTIVATION_TYPE = 35,<br/>OH_NN_MAX_POOL_KERNEL_SIZE = 36, OH_NN_MAX_POOL_STRIDE = 37, OH_NN_MAX_POOL_PAD_MODE = 38, OH_NN_MAX_POOL_PAD = 39,<br/>OH_NN_MAX_POOL_ACTIVATION_TYPE = 40, OH_NN_MUL_ACTIVATION_TYPE = 41, OH_NN_ONE_HOT_AXIS = 42, OH_NN_PAD_CONSTANT_VALUE = 43,<br/>OH_NN_SCALE_ACTIVATIONTYPE = 44, OH_NN_SCALE_AXIS = 45, OH_NN_SOFTMAX_AXIS = 46, OH_NN_SPACE_TO_BATCH_ND_BLOCK_SHAPE = 47,<br/>OH_NN_SPACE_TO_BATCH_ND_PADDINGS = 48, OH_NN_SPLIT_AXIS = 49, OH_NN_SPLIT_OUTPUT_NUM = 50, OH_NN_SPLIT_SIZE_SPLITS = 51,<br/>OH_NN_SQUEEZE_AXIS = 52, OH_NN_STACK_AXIS = 53, OH_NN_STRIDED_SLICE_BEGIN_MASK = 54, OH_NN_STRIDED_SLICE_END_MASK = 55,<br/>OH_NN_STRIDED_SLICE_ELLIPSIS_MASK = 56, OH_NN_STRIDED_SLICE_NEW_AXIS_MASK = 57, OH_NN_STRIDED_SLICE_SHRINK_AXIS_MASK = 58, OH_NN_SUB_ACTIVATIONTYPE = 59,<br/>OH_NN_REDUCE_MEAN_KEEP_DIMS = 60, OH_NN_RESIZE_BILINEAR_NEW_HEIGHT = 61, OH_NN_RESIZE_BILINEAR_NEW_WIDTH = 62, OH_NN_RESIZE_BILINEAR_PRESERVE_ASPECT_RATIO = 63,<br/>OH_NN_RESIZE_BILINEAR_COORDINATE_TRANSFORM_MODE = 64, OH_NN_RESIZE_BILINEAR_EXCLUDE_OUTSIDE = 65, OH_NN_LAYER_NORM_BEGIN_NORM_AXIS = 66, OH_NN_LAYER_NORM_EPSILON = 67,<br/>OH_NN_LAYER_NORM_BEGIN_PARAM_AXIS = 68, OH_NN_LAYER_NORM_ELEMENTWISE_AFFINE = 69, OH_NN_REDUCE_PROD_KEEP_DIMS = 70, OH_NN_REDUCE_ALL_KEEP_DIMS = 71,<br/>OH_NN_QUANT_DTYPE_CAST_SRC_T = 72, OH_NN_QUANT_DTYPE_CAST_DST_T = 73, OH_NN_TOP_K_SORTED = 74, OH_NN_ARG_MAX_AXIS = 75,<br/>OH_NN_ARG_MAX_KEEPDIMS = 76, OH_NN_UNSQUEEZE_AXIS = 77<br/>} | Enumerates the tensor data types.  | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_NNModel_Construct](#oh_nnmodel_construct) (void) | Creates a model instance of the [OH_NNModel](#oh_nnmodel) type and uses other APIs provided by OH_NNModel to construct the model instance.  | 
| [OH_NNModel_AddTensor](#oh_nnmodel_addtensor) ([OH_NNModel](#oh_nnmodel) \*model, const [OH_NN_Tensor](_o_h___n_n___tensor.md) \*tensor) | Adds a tensor to a model instance.  | 
| [OH_NNModel_SetTensorData](#oh_nnmodel_settensordata) ([OH_NNModel](#oh_nnmodel) \*model, uint32_t index, const void \*dataBuffer, size_t length) | Sets the tensor value.  | 
| [OH_NNModel_AddOperation](#oh_nnmodel_addoperation) ([OH_NNModel](#oh_nnmodel) \*model, [OH_NN_OperationType](#oh_nn_operationtype) op, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*paramIndices, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*inputIndices, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*outputIndices) | Adds an operator to a model instance.  | 
| [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) ([OH_NNModel](#oh_nnmodel) \*model, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*inputIndices, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*outputIndices) | Specifies the inputs and outputs of a model.  | 
| [OH_NNModel_Finish](#oh_nnmodel_finish) ([OH_NNModel](#oh_nnmodel) \*model) | Completes model composition.  | 
| [OH_NNModel_Destroy](#oh_nnmodel_destroy) ([OH_NNModel](#oh_nnmodel) \*\*model) | Releases a model instance.  | 
| [OH_NNModel_GetAvailableOperations](#oh_nnmodel_getavailableoperations) ([OH_NNModel](#oh_nnmodel) \*model, size_t deviceID, const bool \*\*isSupported, uint32_t \*opCount) | Queries whether the device supports operators in the model. The support status is indicated by the Boolean value.  | 
| [OH_NNCompilation_Construct](#oh_nncompilation_construct) (const [OH_NNModel](#oh_nnmodel) \*model) | Creates a compilation instance of the [OH_NNCompilation](#oh_nncompilation) type.  | 
| [OH_NNCompilation_SetDevice](#oh_nncompilation_setdevice) ([OH_NNCompilation](#oh_nncompilation) \*compilation, size_t deviceID) | Specifies the device for model compilation and computing.  | 
| [OH_NNCompilation_SetCache](#oh_nncompilation_setcache) ([OH_NNCompilation](#oh_nncompilation) \*compilation, const char \*cachePath, uint32_t version) | Set the cache directory and version of the compiled model.  | 
| [OH_NNCompilation_SetPerformanceMode](#oh_nncompilation_setperformancemode) ([OH_NNCompilation](#oh_nncompilation) \*compilation, [OH_NN_PerformanceMode](#oh_nn_performancemode) performanceMode) | Sets the performance mode for model computing.  | 
| [OH_NNCompilation_SetPriority](#oh_nncompilation_setpriority) ([OH_NNCompilation](#oh_nncompilation) \*compilation, [OH_NN_Priority](#oh_nn_priority) priority) | Sets the model computing priority.  | 
| [OH_NNCompilation_EnableFloat16](#oh_nncompilation_enablefloat16) ([OH_NNCompilation](#oh_nncompilation) \*compilation, bool enableFloat16) | Enables float16 for computing.  | 
| [OH_NNCompilation_Build](#oh_nncompilation_build) ([OH_NNCompilation](#oh_nncompilation) \*compilation) | Compiles a model.  | 
| [OH_NNCompilation_Destroy](#oh_nncompilation_destroy) ([OH_NNCompilation](#oh_nncompilation) \*\*compilation) | Releases the **Compilation** object.  | 
| [OH_NNExecutor_Construct](#oh_nnexecutor_construct) ([OH_NNCompilation](#oh_nncompilation) \*compilation) | [OH_NNExecutor](#oh_nnexecutor) \*<br/>Creates an executor instance of the [OH_NNExecutor](#oh_nnexecutor) type.  | 
| [OH_NNExecutor_SetInput](#oh_nnexecutor_setinput) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t inputIndex, const [OH_NN_Tensor](_o_h___n_n___tensor.md) \*tensor, const void \*dataBuffer, size_t length) | Sets the single input data for a model.  | 
| [OH_NNExecutor_SetOutput](#oh_nnexecutor_setoutput) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t outputIndex, void \*dataBuffer, size_t length) | Sets the buffer for a single output of a model.  | 
| [OH_NNExecutor_GetOutputShape](#oh_nnexecutor_getoutputshape) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t outputIndex, int32_t \*\*shape, uint32_t \*shapeLength) | Obtains the dimension information about the output tensor.  | 
| [OH_NNExecutor_Run](#oh_nnexecutor_run) ([OH_NNExecutor](#oh_nnexecutor) \*executor) | Performs inference.  | 
| [OH_NNExecutor_AllocateInputMemory](#oh_nnexecutor_allocateinputmemory) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t inputIndex, size_t length) | Allocates shared memory to a single input on a device.  | 
| [OH_NNExecutor_AllocateOutputMemory](#oh_nnexecutor_allocateoutputmemory) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t outputIndex, size_t length) | Allocates shared memory to a single output on a device.  | 
| [OH_NNExecutor_DestroyInputMemory](#oh_nnexecutor_destroyinputmemory) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t inputIndex, [OH_NN_Memory](_o_h___n_n___memory.md) \*\*memory) | Releases the input memory to which the [OH_NN_Memory](_o_h___n_n___memory.md) instance points.  | 
| [OH_NNExecutor_DestroyOutputMemory](#oh_nnexecutor_destroyoutputmemory) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t outputIndex, [OH_NN_Memory](_o_h___n_n___memory.md) \*\*memory) | Releases the output memory to which the [OH_NN_Memory](_o_h___n_n___memory.md) instance points.  | 
| [OH_NNExecutor_SetInputWithMemory](#oh_nnexecutor_setinputwithmemory) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t inputIndex, const [OH_NN_Tensor](_o_h___n_n___tensor.md) \*tensor, const [OH_NN_Memory](_o_h___n_n___memory.md) \*memory) | Specifies the hardware shared memory pointed to by the [OH_NN_Memory](_o_h___n_n___memory.md) instance as the shared memory used by a single input.  | 
| [OH_NNExecutor_SetOutputWithMemory](#oh_nnexecutor_setoutputwithmemory) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t outputIndex, const [OH_NN_Memory](_o_h___n_n___memory.md) \*memory) | Specifies the hardware shared memory pointed to by the [OH_NN_Memory](_o_h___n_n___memory.md) instance as the shared memory used by a single output.  | 
| [OH_NNExecutor_Destroy](#oh_nnexecutor_destroy) ([OH_NNExecutor](#oh_nnexecutor) \*\*executor) | Destroys an executor instance to release the memory occupied by the executor.  | 
| [OH_NNDevice_GetAllDevicesID](#oh_nndevice_getalldevicesid) (const size_t \*\*allDevicesID, uint32_t \*deviceCount) | Obtains the ID of the device connected to Neural Network Runtime.  | 
| [OH_NNDevice_GetName](#oh_nndevice_getname) (size_t deviceID, const char \*\*name) | Obtains the name of the specified device.  | 
| [OH_NNDevice_GetType](#oh_nndevice_gettype) (size_t deviceID, [OH_NN_DeviceType](#oh_nn_devicetype) \*deviceType) | Obtains the type information of the specified device.  | 


## Type Description


### OH_NN_Memory

  
```
typedef struct OH_NN_MemoryOH_NN_Memory
```
**Description**<br>
Defines the memory structure.


### OH_NN_QuantParam

  
```
typedef struct OH_NN_QuantParamOH_NN_QuantParam
```
**Description**<br>
Quantization information.

In quantization scenarios, the 32-bit floating-point data type is quantized into the fixed-point data type according to the following formula:

s and z are quantization parameters, which are stored by **scale** and **zeroPoint** in [OH_NN_QuantParam](_o_h___n_n___quant_param.md). r is a floating point number, q is the quantization result, q_min is the lower bound of the quantization result, and q_max is an upper bound of a quantization result. The calculation method is as follows:

The clamp function is defined as follows:


### OH_NN_Tensor

  
```
typedef struct OH_NN_TensorOH_NN_Tensor
```
**Description**<br>
Defines the tensor structure.

It is usually used to construct data nodes and operator parameters in a model graph. When constructing a tensor, you need to specify the data type, number of dimensions, dimension information, and quantization information.


### OH_NN_UInt32Array

  
```
typedef struct OH_NN_UInt32ArrayOH_NN_UInt32Array
```
**Description**<br>
This structure is used to store a 32-bit unsigned integer array.


### OH_NNCompilation

  
```
typedef struct OH_NNCompilationOH_NNCompilation
```
**Description**<br>
Defines the compiler handle for Neural Network Runtime.


### OH_NNExecutor

  
```
typedef struct OH_NNExecutorOH_NNExecutor
```
**Description**<br>
Defines the executor handle for Neural Network Runtime.


### OH_NNModel

  
```
typedef struct OH_NNModelOH_NNModel
```
**Description**<br>
Defines the handles of models for Neural Network Runtime.


## Enum Description


### OH_NN_DataType

  
```
enum OH_NN_DataType
```
**Description**<br>
Defines tensor data types supported by Neural Network Runtime.

| Name | Description | 
| -------- | -------- |
| OH_NN_UNKNOWN  | Unknown type | 
| OH_NN_BOOL  | bool | 
| OH_NN_INT8  | int8 | 
| OH_NN_INT16  | int16 | 
| OH_NN_INT32  | int32 | 
| OH_NN_INT64  | int64 | 
| OH_NN_UINT8  | uint8 | 
| OH_NN_UINT16  | uint16 | 
| OH_NN_UINT32  | uint32 | 
| OH_NN_UINT64  | uint64 | 
| OH_NN_FLOAT16  | float16 | 
| OH_NN_FLOAT32  | float32 | 
| OH_NN_FLOAT64  | float64 | 


### OH_NN_DeviceType

  
```
enum OH_NN_DeviceType
```
**Description**<br>
Defines device types supported by Neural Network Runtime.

| Name | Description | 
| -------- | -------- |
| OH_NN_OTHERS  | Devices that are not CPU, GPU, or dedicated accelerator | 
| OH_NN_CPU  | CPU device | 
| OH_NN_GPU  | GPU device | 
| OH_NN_ACCELERATOR  | Dedicated hardware accelerator | 


### OH_NN_Format

  
```
enum OH_NN_Format
```
**Description**<br>
Defines the layout type of tensor data.

| Name | Description | 
| -------- | -------- |
| OH_NN_FORMAT_NONE  | The tensor does not have a specific layout type (such as scalar or vector). | 
| OH_NN_FORMAT_NCHW  | The tensor arranges data in NCHW format. | 
| OH_NN_FORMAT_NHWC  | The tensor arranges data in NHWC format. | 


### OH_NN_FuseType

  
```
enum OH_NN_FuseType : int8_t
```
**Description**<br>
Defines activation function types in the fusion operator for Neural Network Runtime.

| Name | Description | 
| -------- | -------- |
| OH_NN_FUSED_NONE  | The fusion activation function is not specified. | 
| OH_NN_FUSED_RELU  | Fusion relu activation function | 
| OH_NN_FUSED_RELU6  | Fusion relu6 activation function | 


### OH_NN_OperationType

  
```
enum OH_NN_OperationType
```
**Description**<br>
Defines operator types supported by Neural Network Runtime.

| Name | Description | 
| -------- | -------- |
| OH_NN_OPS_ADD  | Returns the tensor of the sum of the elements corresponding to two input tensors.<br/>Inputs:<br/>- **input1**: first input tensor, of the Boolean or number type.<br/>- **input2**: second input tensor, whose data type must be the same as that of the first tensor.<br/>Parameters:<br/>- **activationType** is an integer constant which is contained in **FuseType**. The specified activation function is called before output.<br/>Outputs:<br/>- **output**: sum of **input1** and **input2**. The data shape is the same as that of the input after broadcasting, and the data type is the same as that of the input with a higher precision.  | 
| OH_NN_OPS_AVG_POOL  | Apply 2D average pooling to the input tensor, which now must be in NHWC format. The int8 quantization input is supported.<br/>If the input contains the **padMode** parameter:<br/>Inputs:<br/>- **input**: tensor.<br/>Parameters:<br/>- **kernelSize** indicates the kernel size used to obtain the average value. It is an int array [kernel_height, kernel_width]. The first number indicates the kernel height, and the second number indicates the kernel width.<br/>- **strides** indicates the distance of kernel moving. The value is an int array [stride_height, stride_width]. The first number indicates the moving step in height, and the second number indicates the moving step in width.<br/>- **padMode**: padding mode, which is optional. The value is of the int type and can be **0** (same) or **1** (valid). The nearest neighbor value is used for padding. **0** (same): The height and width of the output are the same as those of the input. The total padding quantity is calculated horizontally and vertically and evenly distributed to the top, bottom, left, and right if possible. Otherwise, the last additional padding will be completed from the bottom and right. **1** (valid): The possible maximum height and width of the output will be returned in case of no padding. Excessive pixels will be discarded.<br/>- **activationType** is an integer constant which is contained in **FuseType**. The specified activation function is called before output.<br/>If the input contains the **padList** parameter:<br/>Inputs:<br/>- **input**: tensor.<br/>Parameters:<br/>- **kernelSize** indicates the kernel size used to obtain the average value. It is an int array [kernel_height, kernel_width]. The first number indicates the kernel height, and the second number indicates the kernel width.<br/>- **strides** indicates the distance of kernel moving. The value is an int array [stride_height, stride_width]. The first number indicates the moving step in height, and the second number indicates the moving step in width.<br/>- **padList**: padding around **input**. It is an int array [top, bottom, left, right], and the nearest neighbor values are used for padding.<br/>- **activationType** is an integer constant which is contained in **FuseType**. The specified activation function is called before output.<br/>Outputs:<br/>- **output**: average pooling result of the input.  | 
| OH_NN_OPS_BATCH_NORM  | Batch normalization is performed on a tensor to scale and shift tensor elements, relieving potential covariate shift in a batch of data.<br/>Inputs:<br/>- **input**: n-dimensional tensor of shape [N, ..., C]. The nth dimension is the number of channels.<br/>- **scale**: 1D tensor of the scaling factor used to scale the first normalized tensor.<br/>- **offset**: 1D tensor used to move to the first normalized tensor.<br/>- **mean**: 1D tensor of the overall mean value. It is used only for inference. In case of training, this parameter must be left empty.<br/>- **variance**: 1D tensor used for the overall variance. It is used only for inference. In case of training, this parameter must be left empty.<br/>Parameters:<br/>- **epsilon**: fixed small additional value.<br/>Outputs:<br/>- **output**: n-dimensional output tensor whose shape and data type are the same as those of the input.  | 
| OH_NN_OPS_BATCH_TO_SPACE_ND  | Divides the batch dimension of a 4D tensor into small blocks by **block_shape**, and interleaves these blocks back into the spatial dimension.<br/>Parameters:<br/>- **input**: input tensor. The dimension will be divided into small blocks, and these blocks will be interleaved into the spatial dimension.<br/>Outputs:<br/>- **blockSize**: size of each block to be interleaved into the spatial dimension. The value is an array [height_block, width_block].<br/>- **crops**: elements truncated from the spatial dimension of the output. The value is a 2D array [[crop0_start, crop0_end], [crop1_start, crop1_end]] with the shape of (2, 2).<br/>Outputs:<br/>- **output**. Assume that the shape of **input** is (n,h,w,c) and the shape of **output** is (n',h',w',c'): n' = n / (block_shape[0] \* block_shape[1]) h' = h \* block_shape[0] - crops[0][0] - crops[0][1] w' = w \* block_shape[1] - crops[1][0] - crops[1][1] c'= c  | 
| OH_NN_OPS_BIAS_ADD  | Offsets the data in each dimension of the input tensor.<br/>Inputs:<br/>- **input**: input tensor, which can have two to five dimensions.<br/>- **bias**: offset of the number of input dimensions.<br/>Outputs:<br/>- **output**: sum of the input tensor and the bias in each dimension.  | 
| OH_NN_OPS_CAST  | Converts the data type in the input tensor.<br/>Inputs:<br/>- **input**: input tensor.<br/>- **type**: converted data type.<br/>Outputs:<br/>- **output**: converted tensor.  | 
| OH_NN_OPS_CONCAT  | Connects tensors in a specified dimension.<br/>Inputs:<br/>- **input**: N input tensors.<br/>Parameters:<br/>- **axis**: dimension for connecting tensors.<br/>Outputs:<br/>- **output**: result of connecting N tensors along the axis.  | 
| OH_NN_OPS_CONV2D  | 2D convolutional layer.<br/>If the input contains the **padMode** parameter:<br/>Inputs:<br/>- **input**: input tensor.<br/>- **weight**: convolution weight in [outChannel, kernelHeight, kernelWidth, inChannel/group] format. The value of **inChannel** must be exactly divided by the value of **group**.<br/>- **bias**: bias of the convolution. It is an array with a length of **[outChannel]**. In quantization scenarios, the **bias** parameter does not require quantization parameters. The quantization version requires data input of the **OH_NN_INT32** type. The actual quantization parameters are determined by **input** and **weight**.<br/>Parameters:<br/>- **stride**: movement stride of the convolution kernel in height and width. It is an int array [strideHeight, strideWidth].<br/>- **dilation**: dilation size of the convolution kernel in height and width. It is an int array [dilationHeight, dilationWidth]. The value must be greater than or equal to **1** and cannot exceed the height and width of **input**.<br/>- **padMode**: padding mode of **input**. The value is of the int type and can be **0** (same) or **1** (valid). **0** (same): The height and width of the output are the same as those of the input. The total padding quantity is calculated horizontally and vertically and evenly distributed to the top, bottom, left, and right if possible. Otherwise, the last additional padding will be completed from the bottom and right.<br/>  **1** (valid): The possible maximum height and width of the output will be returned in case of no padding. The excessive pixels will be discarded.<br/>- **group**: number of groups in which the input is divided by **in_channel**. The value is of the int type. If **group** is **1**, it is a conventional convolution. If **group** is greater than **1** and less than or equal to **in_channel**, it is a group convolution.<br/>- **activationType** is an integer constant which is contained in **FuseType**. The specified activation function is called before output.<br/>If the input contains the **padList** parameter:<br/>Inputs:<br/>- **input**: input tensor.<br/>- **weight**: convolution weight in [outChannel, kernelHeight, kernelWidth, inChannel/group] format. The value of **inChannel** must be exactly divided by the value of **group**.<br/>- **bias**: bias of the convolution. It is an array with a length of **[outChannel]**. In quantization scenarios, the **bias** parameter does not require quantization parameters. The quantization version requires data input of the **OH_NN_INT32** type. The actual quantization parameters are determined by **input** and **weight**.<br/>Parameters:<br/>- **stride**: movement stride of the convolution kernel in height and width. It is an int array [strideHeight, strideWidth].<br/>- **dilation**: dilation size of the convolution kernel in height and width. It is an int array [dilationHeight, dilationWidth]. The value must be greater than or equal to **1** and cannot exceed the height and width of **input**.<br/>- **padList**: padding around **input**. It is an int array [top, bottom, left, right].<br/>- **group**: number of groups in which the input is divided by **in_channel**. The value is of the int type. If **group** is **1**, it is a conventional convolution. If **group** is **in_channel**, it is depthwiseConv2d. In this case, group==in_channel==out_channel. If **group** is greater than **1** and less than **in_channel**, it is a group convolution. In this case, out_channel==group.<br/>- **activationType** is an integer constant which is contained in **FuseType**. The specified activation function is called before output.<br/>Outputs:<br/>- **output**: convolution computing result.  | 
| OH_NN_OPS_CONV2D_TRANSPOSE  | 2D convolution transposition.<br/>If the input contains the **padMode** parameter:<br/>Inputs:<br/>- **input**: input tensor.<br/>- **weight**: convolution weight in [outChannel, kernelHeight, kernelWidth, inChannel/group] format. The value of **inChannel** must be exactly divided by the value of **group**.<br/>- **bias**: bias of the convolution. It is an array with a length of **[outChannel]**. In quantization scenarios, the **bias** parameter does not require quantization parameters. The quantization version requires data input of the **OH_NN_INT32** type. The actual quantization parameters are determined by **input** and **weight**.<br/>- **stride**: movement stride of the convolution kernel in height and width. It is an int array [strideHeight, strideWidth].<br/>Parameters:<br/>- **dilation**: dilation size of the convolution kernel in height and width. It is an int array [dilationHeight, dilationWidth]. The value must be greater than or equal to **1** and cannot exceed the height and width of **input**.<br/>- **padMode**: padding mode of **input**. The value is of the int type and can be **0** (same) or **1** (valid). **0** (same): The height and width of the output are the same as those of the input. The total padding quantity is calculated horizontally and vertically and evenly distributed to the top, bottom, left, and right if possible. Otherwise, the last additional padding will be completed from the bottom and right. **1** (valid): The possible maximum height and width of the output will be returned in case of no padding. The excessive pixels will be discarded.<br/>- **group**: number of groups in which the input is divided by **in_channel**. The value is of the int type. If **group** is **1**, it is a conventional convolution. If **group** is greater than **1** and less than or equal to **in_channel**, it is a group convolution.<br/>- **outputPads**: padding along the height and width of the output tensor. The value is an int or a tuple. It can be a single integer to specify the same value for all spatial dimensions. The amount of output padding along a dimension must be less than the stride along this dimension.<br/>- **activationType** is an integer constant which is contained in **FuseType**. The specified activation function is called before output.<br/>If the input contains the **padList** parameter:<br/>Inputs:<br/>- **input**: input tensor.<br/>- **weight**: convolution weight in [outChannel, kernelHeight, kernelWidth, inChannel/group] format. The value of **inChannel** must be exactly divided by the value of **group**.<br/>- **bias**: bias of the convolution. It is an array with a length of **[outChannel]**. In quantization scenarios, the **bias** parameter does not require quantization parameters. The quantization version requires data input of the **OH_NN_INT32** type. The actual quantization parameters are determined by **input** and **weight**.<br/>Parameters:<br/>- **stride**: movement stride of the convolution kernel in height and width. It is an int array [strideHeight, strideWidth].<br/>- **dilation**: dilation size of the convolution kernel in height and width. It is an int array [dilationHeight, dilationWidth]. The value must be greater than or equal to **1** and cannot exceed the height and width of **input**.<br/>- **padList**: padding around **input**. It is an int array [top, bottom, left, right].<br/>- **group**: number of groups in which the input is divided by **in_channel**. The value is of the int type. If **group** is **1**, it is a conventional convolution. If **group** is greater than **1** and less than or equal to **in_channel**, it is a group convolution.<br/>- **outputPads**: padding along the height and width of the output tensor. The value is an int or a tuple. It can be a single integer to specify the same value for all spatial dimensions. The amount of output padding along a dimension must be less than the stride along this dimension.<br/>- **activationType** is an integer constant which is contained in **FuseType**. The specified activation function is called before output.<br/>Outputs:<br/>**output**: computing result after convolution and transposition. | 
| OH_NN_OPS_DEPTHWISE_CONV2D_NATIVE  | 2D depthwise separable convolution.<br/>If the input contains the **padMode** parameter:<br/>Inputs:<br/>- **input**: input tensor.<br/>- **weight**: convolution weight in [outChannel, kernelHeight, kernelWidth, 1] format. **outChannel** is equal to **channelMultiplier** multiplied by **inChannel**.<br/>- **bias**: bias of the convolution. It is an array with a length of **[outChannel]**. In quantization scenarios, the **bias** parameter does not require quantization parameters. The quantization version requires data input of the **OH_NN_INT32** type. The actual quantization parameters are determined by **input** and **weight**.<br/>Parameters:<br/>- **stride**: movement stride of the convolution kernel in height and width. It is an int array [strideHeight, strideWidth].<br/>- **dilation**: dilation size of the convolution kernel in height and width. It is an int array [dilationHeight, dilationWidth]. The value must be greater than or equal to **1** and cannot exceed the height and width of **input**.<br/>- **padMode**: padding mode of **input**. The value is of the int type and can be **0** (same) or **1** (valid). **0** (same): The height and width of the output are the same as those of the input. The total padding quantity is calculated horizontally and vertically and evenly distributed to the top, bottom, left, and right if possible. Otherwise, the last additional padding will be completed from the bottom and right.<br/>  **1** (valid): The possible maximum height and width of the output will be returned in case of no padding. The excessive pixels will be discarded.<br/>- **activationType** is an integer constant which is contained in **FuseType**. The specified activation function is called before output.<br/>If the input contains the **padList** parameter:<br/>Inputs:<br/>- **input**: input tensor.<br/>- **weight**: convolution weight in [outChannel, kernelHeight, kernelWidth, 1] format. **outChannel** is equal to **channelMultiplier** multiplied by **inChannel**.<br/>- **bias**: bias of the convolution. It is an array with a length of **[outChannel]**. In quantization scenarios, the **bias** parameter does not require quantization parameters. The quantization version requires data input of the **OH_NN_INT32** type. The actual quantization parameters are determined by **input** and **weight**.<br/>Parameters:<br/>- **stride**: movement stride of the convolution kernel in height and width. It is an int array [strideHeight, strideWidth].<br/>- **dilation**: dilation size of the convolution kernel in height and width. It is an int array [dilationHeight, dilationWidth]. The value must be greater than or equal to **1** and cannot exceed the height and width of **input**.<br/>- **padList**: padding around **input**. It is an int array [top, bottom, left, right].<br/>- **activationType** is an integer constant which is contained in **FuseType**. The specified activation function is called before output.<br/>Outputs:<br/>- **output**: convolution computing result.  | 
| OH_NN_OPS_DIV  | Divides two input scalars or tensors.<br/>Inputs:<br/>- **input1**: first input, which is a number, a bool, or a tensor whose data type is number or Boolean.<br/>- **input2**: second input, which must meet the following requirements: If the first input is a tensor, the second input can be a real number, a Boolean value, or a tensor whose data type is real number or Boolean value. If the first input is a real number or Boolean value, the second input must be a tensor whose data type is real number or Boolean value.<br/>Parameters:<br/>- **activationType** is an integer constant which is contained in **FuseType**. The specified activation function is called before output.<br/>Outputs:<br/>- **output**: result of dividing **input1** by **input2**.  | 
| OH_NN_OPS_ELTWISE  | Sets parameters to perform product (dot product), sum (addition and subtraction), or max (larger value) on the input.<br/>Inputs:<br/>- **input1**: first input tensor.<br/>- **input2**: second input tensor.<br/>Parameters:<br/>- **mode**: operation mode. The value is an enumerated value.<br/>Outputs:<br/>- **output**: computing result, which has the same data type and shape of **output** and **input1**.  | 
| OH_NN_OPS_EXPAND_DIMS  | Adds an additional dimension to a tensor in the given dimension.<br/>Inputs:<br/>- **input**: input tensor.<br/>- **axis**: index of the dimension to be added. The value is of the int32_t type and must be a constant in the range [-dim-1, dim].<br/>Outputs:<br/>- **output**: tensor after dimension expansion.  | 
| OH_NN_OPS_FILL  | Creates a tensor of the specified dimensions and fills it with a scalar.<br/>Inputs:<br/>- **value**: scalar used to fill the tensor.<br/>- **shape**: dimensions of the tensor to be created.<br/>Outputs:<br/>- **output**: generated tensor, which has the same data type as **value**. The tensor shape is specified by the **shape** parameter.  | 
| OH_NN_OPS_FULL_CONNECTION  | Full connection. The entire input is used as the feature map for feature extraction.<br/>Inputs:<br/>- **input**: full-connection input tensor.<br/>- **weight**: weight tensor for a full connection.<br/>- **bias**: full-connection bias. In quantization scenarios, no quantized parameter is required for this parameter. If quantization is required, the data must be of the OH_NN_INT32 type. The actual quantization parameters are determined by **input** and **weight**.<br/>Parameters:<br/>- **activationType** is an integer constant which is contained in **FuseType**. The specified activation function is called before output.<br/>Outputs:<br/>- **output**: computed tensor.<br/>If the input contains the **axis** parameter:<br/>Inputs:<br/>- **input**: full-connection input tensor.<br/>- **weight**: weight tensor for a full connection.<br/>- **bias**: full-connection bias. In quantization scenarios, no quantized parameter is required for this parameter. If quantization is required, the data must be of the OH_NN_INT32 type. The actual quantization parameters are determined by **input** and **weight**.<br/>Parameters:<br/>- **axis**: axis in which the full connection is applied. The specified axis and its following axes are converted into a 1D tensor for applying the full connection.<br/>- **activationType** is an integer constant which is contained in **FuseType**. The specified activation function is called before output.<br/>Outputs:<br/>- **output**: computed tensor.  | 
| OH_NN_OPS_GATHER  | Returns the slice of the input tensor based on the specified index and axis.<br/>Inputs:<br/>- **input**: tensor to be sliced.<br/>- **inputIndices**: indices of the specified input on the axis. The value is an array of the int type and must be in the range [0,input.shape[axis]).<br/>- **axis**: axis on which **input** is sliced. The value is an array with one element of the int32_t type.<br/>Outputs:<br/>- **output**: sliced tensor.  | 
| OH_NN_OPS_HSWISH  | Calculate the **Hswish** activation value of the input.<br/>Inputs:<br/>- An n-dimensional input tensor.<br/>Outputs:<br/>- n-dimensional **Hswish** activation value. The data type is the same as that of **shape** and **input**.  | 
| OH_NN_OPS_LESS_EQUAL  | For **input1** and **input2**, calculate the result of input1[i]&lt;=input2[i] for each pair of elements, where i is the index of each element in the input tensor.<br/>Inputs:<br/>- **input1**, which can be a real number, Boolean value, or tensor whose data type is real number or NN_BOOL.<br/>- **input2**, which can be a real number or a Boolean value if **input1** is a tensor and must be a tensor with the data type of real number or NN_BOOL if **input1** is not a tensor.<br/>Outputs:<br/>- A tensor of the data type NN_BOOL. When a quantization model is used, the quantization parameters of the output cannot be omitted. However, values of the quantization parameters do not affect the result.  | 
| OH_NN_OPS_MATMUL  | Calculate the inner product of **input1** and **input2**.<br/>Inputs:<br/>- **input1**: n-dimensional input tensor.<br/>- **input2**: n-dimensional input tensor.<br/>Parameters:<br/>- **TransposeX**: Boolean value indicating whether to transpose **input1**.<br/>- **TransposeY**: Boolean value indicating whether to transpose **input2**.<br/>Outputs:<br/>- **output**: inner product obtained after calculation. In case of type!=NN_UNKNOWN, the output data type is determined by **type**. In case of type==NN_UNKNOWN, the output data type depends on the data type converted during computing of **inputX** and **inputY**.  | 
| OH_NN_OPS_MAXIMUM  | Calculates the maximum of **input1** and **input2** element-wise. The inputs of **input1** and **input2** comply with the implicit type conversion rules to make the data types consistent. \* The inputs must be two tensors or one tensor and one scalar. When the inputs are two tensors, their data types cannot be both NN_BOOL. Their shapes can be broadcast to the same size. When the inputs are one tensor and one scalar, the scalar must be a constant.<br/>Inputs:<br/>- **input1**: n-dimensional input tensor of the real number or NN_BOOL type.<br/>- **input2**: n-dimensional input tensor of the real number or NN_BOOL type.<br/>Outputs:<br/>- **output**: n-dimensional output tensor. The **shape** and data type of **output** are the same as those of the two inputs with a higher precision.  | 
| OH_NN_OPS_MAX_POOL  | Applies 2D maximum pooling to the input tensor.<br/>If the input contains the **padMode** parameter:<br/>Inputs:<br/>- **input**: tensor.<br/>Parameters:<br/>- **kernelSize**: kernel size used to obtain the maximum. It is an int array [kernel_height, kernel_width]. The first number indicates the kernel height, and the second number indicates the kernel width.<br/>- **strides** indicates the distance of kernel moving. The value is an int array [stride_height, stride_width]. The first number indicates the moving step in height, and the second number indicates the moving step in width.<br/>- **padMode**: padding mode, which is optional. The value is of the int type and can be **0** (same) or **1** (valid). The nearest neighbor value is used for padding. **0** (same): The height and width of the output are the same as those of the input. The total padding quantity is calculated horizontally and vertically and evenly distributed to the top, bottom, left, and right if possible. Otherwise, the last additional padding will be completed from the bottom and right.<br/>  **1** (valid): The possible maximum height and width of the output will be returned in case of no padding. The excessive pixels will be discarded.<br/>- **activationType** is an integer constant which is contained in **FuseType**. The specified activation function is called before output.<br/>If the input contains the **padList** parameter:<br/>Inputs:<br/>- **input**: tensor.<br/>Parameters:<br/>- **kernelSize**: kernel size used to obtain the maximum. It is an int array [kernel_height, kernel_width]. The first number indicates the kernel height, and the second number indicates the kernel width.<br/>- **strides** indicates the distance of kernel moving. The value is an int array [stride_height, stride_width]. The first number indicates the moving step in height, and the second number indicates the moving step in width.<br/>- **padList**: padding around **input**. It is an int array [top, bottom, left, right], and the nearest neighbor values are used for padding.<br/>- **activationType** is an integer constant which is contained in **FuseType**. The specified activation function is called before output.<br/>Outputs:<br/>- **output**: tensor obtained after maximum pooling is applied to the input.  | 
| OH_NN_OPS_MUL  | Multiplies elements in the same positions of **inputX** and **inputY** to obtain the output. If **inputX** and **inputY** have different shapes, expand them to the same shape through broadcast and then perform multiplication.<br/>Inputs:<br/>- **input1**: n-dimensional tensor.<br/>- **input2**: n-dimensional tensor.<br/>Parameters:<br/>- **activationType** is an integer constant which is contained in **FuseType**. The specified activation function is called before output.<br/>Outputs:<br/>- Product of each element of **input1** and **input2**.  | 
| OH_NN_OPS_ONE_HOT  | Generates a one-hot tensor based on the positions specified by **indices**. The positions specified by **indices** are determined by **on_value**, and other positions are determined by **off_value**.<br/>Inputs:<br/>- **indices**: n-dimensional tensor. Each element in **indices** determines the position of **on_value** in each one-hot vector.<br/>- **depth**: integer scalar that determines the depth of the one-hot vector. The value of **depth** must be greater than **0**.<br/>- **on_value**: scalar that specifies a valid value in the one-hot vector.<br/>- **off_value**: scalar that specifies the values of other posistions in the one-hot vector except the valid value.<br/>Parameters:<br/>- **axis**: integer scalar that specifies the dimension for inserting the one-hot. Assume that the shape of **indices** is [N, C], and the value of **depth** is D. When **axis** is **0**, the shape of the output is [D, N, C]. When **axis** is **-1**, the shape of the output is [N, C, D]. When **axis** is **1**, the shape of the output is [N, D, C].<br/>Outputs:<br/>- **output**: (n+1)-dimensional tensor if **indices** is an n-dimensional tensor. The output shape is determined by **indices** and **axis**.  | 
| OH_NN_OPS_PAD  | Pads **inputX** in the specified dimensions.<br/>Inputs:<br/>- **inputX**: n-dimensional tensor in [BatchSize, ...] format.<br/>- **paddings**: 2D tensor that specifies the length to pad in each dimension. The shape is [n, 2]. For example, **paddings[i][0]** indicates the number of paddings to be added preceding **inputX** in the ith dimension. **paddings[i][1]** indicates the number of paddings to be added following **inputX** in the ith dimension.<br/>Parameters:<br/>- **padValues**: value to be added to the pad operation. The value is a constant with the same data type as **inputX**.<br/>Outputs:<br/>- **output**: n-dimensional tensor after padding, with the same dimensions and data type as **inputX**. The shape is determined by **inputX** and **paddings**. output.shape[i] = input.shape[i] + paddings[i][0]+paddings[i][1]  | 
| OH_NN_OPS_POW  | Calculates the **y** power of each element in **input**. The inputs must be two tensors or one tensor and one scalar. When the inputs are two tensors, their data types cannot be both NN_BOOL, and their shapes must be the same. When the inputs are one tensor and one scalar, the scalar must be a constant.<br/>Inputs:<br/>- **input**: real number, Boolean value, or tensor whose data type is real number or NN_BOOL.<br/>- **y**: real number, Boolean value, or tensor whose data type is real number or NN_BOOL.<br/>Outputs:<br/>- **output**: tensor, whose shape is determined by the shape of **input** and **y** after broadcasting.  | 
| OH_NN_OPS_SCALE  | Scales a tensor.<br/>Inputs:<br/>- **input**: n-dimensional tensor.<br/>- **scale**: scaling tensor.<br/>- **bias**: bias tensor.<br/>Parameters:<br/>- **axis**: dimensions to be scaled.<br/>- **activationType** is an integer constant which is contained in **FuseType**. The specified activation function is called before output.<br/>Outputs:<br/>- **output**: scaled n-dimensional tensor, whose data type is the same as that of **input** and shape is determined by **axis**.  | 
| OH_NN_OPS_SHAPE  | Calculates the shape of the input tensor.<br/>Inputs:<br/>- **input**: n-dimensional tensor.<br/>Outputs:<br/>- **output**: integer array representing the dimensions of the input tensor.  | 
| OH_NN_OPS_SIGMOID  | Applies the **sigmoid** operation to the input tensor.<br/>Inputs:<br/>- **input**: n-dimensional tensor.<br/>Outputs:<br/>- **output**: result of the **sigmoid** operation. It is an n-dimensional tensor with the same data type and shape as **input**.  | 
| OH_NN_OPS_SLICE  | Slices a tensor of the specified size from the input in each dimension.<br/>Inputs:<br/>- **input**: n-dimensional input tensor.<br/>- **begin**: start of the slice, which is an array of integers greater than or equal to 0.<br/>- **size**: slice length, which is an array of integers greater than or equal to 0. Assume that a dimension is **i** and 1&lt;=size[i]&lt;=input.shape[i]-begin[i].<br/>Outputs:<br/>- **output**: n-dimensional tensor obtained by slicing. The **TensorType**, shape, and size of the output are the same as those of the input.  | 
| OH_NN_OPS_SOFTMAX  | Applies the **softmax** operation to the input tensor.<br/>Inputs:<br/>- **input**: n-dimensional input tensor.<br/>Parameters:<br/>- **axis**: dimension in which the **softmax** operation is performed. The value is of the int64 type. It is an integer in the range [-n, n).<br/>Outputs:<br/>- **output**: result of the **softmax** operation. It is an n-dimensional tensor with the same data type and shape as **input**.  | 
| OH_NN_OPS_SPACE_TO_BATCH_ND  | Divides a 4D tensor into small blocks and combines these blocks in the original batch. The number of blocks is **blockShape[0]** multiplied by **blockShape[1]**.<br/>Inputs:<br/>- **input**: 4D tensor.<br/>Parameters:<br/>- **blockShape**: a pair of integers. Each of them is greater than or equal to **1**.<br/>- **paddings**: a pair of arrays. Each of them consists of two integers. The four integers that form **paddings** must be greater than or equal to **0**. **paddings[0][0]** and **paddings[0][1]** specify the number of paddings in the third dimension, and **paddings[1][0]** and **paddings[1][1]** specify the number of paddings in the fourth dimension.<br/>Outputs:<br/>- **output**: 4D tensor with the same data type as **input**. The shape is determined by **input**, **blockShape**, and **paddings**. Assume that the input shape is [n,c,h,w], then: output.shape[0] = n \* blockShape[0] \* blockShape[1] output.shape[1] = c output.shape[2] = (h + paddings[0][0] + paddings[0][1]) / blockShape[0] output.shape[3] = (w + paddings[1][0] + paddings[1][1]) / blockShape[1] (h + paddings[0][0] + paddings[0][1]) and (w + paddings[1][0] + paddings[1][1]) is exactly divisible by (h + paddings[0][0] + paddings[0][1]) and (w + paddings[1][0] + paddings[1][1]).  | 
| OH_NN_OPS_SPLIT  | Splits the input into multiple tensors along the axis dimension. The number of tensors is specified by **outputNum**.<br/>Inputs:<br/>- **input**: n-dimensional tensor.<br/>Parameters:<br/>- **outputNum**: number of output tensors. The data type is long.<br/>- **size_splits**: size of each tensor split from the input. The value is a 1D tensor of the int type. If **size_splits** is empty, the input will be evenly split into tensors of the same size. In this case, **input.shape[axis]** can be exactly divisible by **outputNum**. If **size_splits** is not empty, the sum of all its elements must be equal to **input.shape[axis]**.<br/>- **axis**: splitting dimension of the int type.<br/>Outputs:<br/>- **outputs**: array of n-dimensional tensors, with the same data type and dimensions. The data type of each tensor is the same as that of **input**.  | 
| OH_NN_OPS_SQRT  | Calculates the square root of a tensor.<br/>Inputs:<br/>- **input**: n-dimensional tensor.<br/>Outputs:<br/>- **output**: square root of the input. It is an n-dimensional tensor with the same data type and shape as **input**.  | 
| OH_NN_OPS_SQUARED_DIFFERENCE  | Calculates the square of the difference between two tensors. The **SquaredDifference** operator supports tensor and tensor subtraction. If two tensors have different **TensorTypes**, the Sub operator converts the low-precision tensor to a high-precision one. If two tensors have different shapes, the two tensors can be extended to tensors with the same shape through broadcast.<br/>Inputs:<br/>- **input1**: minuend, which is a tensor of the NN_FLOAT16, NN_FLOAT32, NN_INT32, or NN_BOOL type.<br/>- **input2**: subtrahend, which is a tensor of the NN_FLOAT16, NN_FLOAT32, NN_INT32, or NN_BOOL type.<br/>Outputs:<br/>- **output**: square of the difference between two inputs. The output shape is determined by**input1** and **input2**. If they have the same shape, the output tensor has the same shape as them. If they have different shapes, perform the broadcast operation on **input1** and **input2** and perform subtraction. **TensorType** of the output is the same as that of the input tensor with higher precision.  | 
| OH_NN_OPS_SQUEEZE  | Removes the dimension with a length of 1 from the specified axis. The int8 quantization input is supported. Assume that the input shape is [2, 1, 1, 2, 2] and axis is [0,1], the output shape is [2, 1, 2, 2], which means the dimension whose length is 0 between dimensions 0 and dimension 1 is removed.<br/>Inputs:<br/>- **input**: n-dimensional tensor.<br/>Parameters:<br/>- **axis**: dimension to be removed. The value is of int64_t type and can be an integer in the range [-n, n) or an array.<br/>Outputs:<br/>- **output**: output tensor.  | 
| OH_NN_OPS_STACK  | Stacks multiple tensors along the specified axis. If each tensor has n dimensions before stacking, the output tensor will have n+1 dimensions.<br/>Inputs:<br/>- **input**: input for stacking, which can contain multiple n-dimensional tensors. Each of them must have the same shape and type.<br/>Parameters:<br/>- **axis**: dimension for tensor stacking, which is an integer. The value range is [-(n+1),(n+1)), which means a negative number is allowed.<br/>Outputs:<br/>- **output**: stacking result of the input along the axis dimension. The value is an n+1-dimensional tensor and has the same **TensorType** as the input.  | 
| OH_NN_OPS_STRIDED_SLICE  | Slices a tensor with the specified stride.<br/>Inputs:<br/>- **input**: n-dimensional input tensor.<br/>- **begin**: start of slicing, which is a 1D tensor. The length of **begin** is n. **begin[i]** specifies the start of slicing in the ith dimension.<br/>- **end**: end of slicing, which is a 1D tensor. The length of **end** is n. **end[i]** specifies the end of slicing in the ith dimension.<br/>- **strides**: slicing stride, which is a 1D tensor. The length of **strides** is n. strides[i] specifies the stride at which the tensor is sliced in the ith dimension.<br/>Parameters:<br/>- **beginMask**: an integer used to mask **begin**. **beginMask** is represented in binary code. In case of binary(beginMask)[i]==1, for the ith dimension, elements are sliced from the first element at **strides[i]** until the end[i]-1 element.<br/>- **endMask**: an integer used to mask **end**. **endMask** is represented in binary code. In case of binary(endMask)[i]==1, elements are sliced from the element at the **begin[i]** position in the ith dimension until the tensor boundary at **strides[i]**.<br/>- **ellipsisMask**: integer used to mask **begin** and **end**. **ellipsisMask** is represented in binary code. In case of binary(ellipsisMask)[i]==1, elements are sliced from the first element at **strides[i]** in the ith dimension until the tensor boundary. Only one bit of **binary(ellipsisMask)** can be a non-zero value.<br/>- **newAxisMask**: new dimension, which is an integer. **newAxisMask** is represented in binary code. In case of binary(newAxisMask)[i]==1, a new dimension whose length is 1 is inserted into the ith dimension.<br/>- **shrinkAxisMask**: shrinking dimension, which is an integer. \* **shrinkAxisMask** is represented in binary code. In the case of binary(shrinkAxisMask)[i]==1, all elements in the ith dimension will be discarded, and the length of the ith dimension is shrunk to **1**.<br/>Outputs:<br/>- A tensor, with the same data type as **input**. The number of dimensions of the output tensor is rank(input[0])+1.  | 
| OH_NN_OPS_SUB  | Calculates the difference between two tensors.<br/>Inputs:<br/>- **input1**: minuend, which is a tensor.<br/>- **input2**: subtrahend, which is a tensor.<br/>Parameters:<br/>- **activationType** is an integer constant which is contained in **FuseType**. The specified activation function is called before output.<br/>Outputs:<br/>- **output**: difference between the two tensors. The output shape is determined by**input1** and **input2**. If they have the same shape, the output tensor has the same shape as them. If they have different shapes, perform the broadcast operation on **input1** and **input2** and perform subtraction. **TensorType** of the output is the same as that of the input tensor with higher precision.  | 
| OH_NN_OPS_TANH  | Computes hyperbolic tangent of the input tensor.<br/>Inputs:<br/>- **input**: n-dimensional tensor.<br/>Outputs:<br/>- **output**: hyperbolic tangent of the input. The **TensorType** and tensor shape are the same as those of the input.  | 
| OH_NN_OPS_TILE  | Copies a tensor the specified times.<br/>Inputs:<br/>- **input**: n-dimensional tensor.<br/>- **multiples**: number of times that the input tensor is copied in each dimension. The value is a 1D tensor. The length m is not less than the number of dimensions, that is, n.<br/>Outputs:<br/>- An m-dimensional tensor whose **TensorType** is the same as that of the input. If **input** and **multiples** have the same length, **input** and **output** have the same number of dimensions. If the length of **multiples** is greater than n, 1 is used to fill the input dimension, and then the input is copied in each dimension the specified times to obtain the m-dimensional tensor.  | 
| OH_NN_OPS_TRANSPOSE  | Transposes data of **input 0** based on **permutation**.<br/>Inputs:<br/>- **input**: n-dimensional tensor to be transposed.<br/>- **permutation**: The value is a 1D tensor whose length is the same as the number of dimensions of **input 0**.<br/>Outputs:<br/>- **output**: n-dimensional tensor. **TensorType** of **output 0** is the same as that of **input 0**, and the output shape is determined by the shape and **permutation** of **input 0**.  | 
| OH_NN_OPS_REDUCE_MEAN  | Calculates the average value in the specified dimension. If **keepDims** is set to **false**, the number of dimensions is reduced for the input; if **keepDims** is set to **true**, the number of dimensions is retained.<br/>Inputs:<br/>- **input**: n-dimensional input tensor, where n is less than 8.<br/>- **axis**: dimension used to calculate the average value. The value is a 1D tensor. The value range of each element in **axis** is [–n, n).<br/>Parameters:<br/>- **keepDims**: indicates whether to retain the dimension. The value is a Boolean value.<br/>Outputs:<br/>- **output**: m-dimensional output tensor whose data type is the same as that of the input. If **keepDims** is **false**, m==n. If **keepDims** is **true**, m&lt;n.  | 
| OH_NN_OPS_RESIZE_BILINEAR  | The Bilinear method is used to deform the input based on the given parameters.<br/>Inputs:<br/>- **input**: 4D input tensor. Each element in the input cannot be less than 0. The input layout must be [batchSize, height, width, channels].<br/>Parameters:<br/>- **newHeight**: resized height of the 4D tensor.<br/>- **newWidth**: resized width of the 4D tensor.<br/>- **preserveAspectRatio**: indicates whether to maintain the height/width ratio of **input** after resizing.<br/>- **coordinateTransformMode**: coordinate transformation method used by the resize operation. The value is an int32 integer. Currently, the following methods are supported:<br/>- **excludeOutside**: an int64 floating point number. When its value is **1**, the sampling weight of the part that exceeds the boundary of **input** is set to **0**, and other weights are normalized.<br/>Outputs:<br/>- **output**: n-dimensional tensor, with the same shape and data type as **input**.  | 
| OH_NN_OPS_RSQRT  | Calculates the reciprocal of the square root of a tensor.<br/>Inputs:<br/>- **input**: n-dimensional tensor, where n is less than 8. Each element of the tensor cannot be less than 0.<br/>Outputs:<br/>- **output**: n-dimensional tensor, with the same shape and data type as **input**.  | 
| OH_NN_OPS_RESHAPE  | Reshapes a tensor.<br/>Inputs:<br/>- **input**: n-dimensional input tensor.<br/>- **InputShape**: shape of the output tensor. The value is a 1D constant tensor.<br/>Outputs:<br/>- **output**: tensor whose data type is the same as that of **input** and shape is determined by **InputShape**.  | 
| OH_NN_OPS_PRELU  | Calculates the PReLU activation value of **input** and **weight**.<br/>Inputs:<br/>- **input**: n-dimensional tensor. If n is greater than or equal to 2, **inputX** must be [BatchSize, ..., Channels]. The second dimension is the number of channels.<br/>- **weight**: 1D tensor. The length of **weight** must be 1 or equal to the number of channels. If the length of **weight** is 1, all channels share the same weight. If the length of **weight** is equal to the number of channels, each channel exclusively has a weight. If n is less than 2 for **inputX**, the **weight** length must be 1.<br/>Outputs:<br/>**output**: PReLU activation value of **x**, with the same shape and data type as **inputX**. | 
| OH_NN_OPS_RELU  | Calculates the Relu activation value of **input**.<br/>Inputs:<br/>- **input**: n-dimensional input tensor.<br/>Outputs:<br/>- **output**: n-dimensional tensor, with the same data type and shape as the input tensor.  | 
| OH_NN_OPS_RELU6  | Calculates the Relu6 activation value of the input, that is, calculate min(max(x, 0), 6) for each element x in the input.<br/>Inputs:<br/>- **input**: n-dimensional input tensor.<br/>Outputs:<br/>- **output**: n-dimensional Relu6 tensor, with the same data type and shape as the input tensor.  | 
| OH_NN_OPS_LAYER_NORM  | Applies layer normalization for a tensor from the specified axis.<br/>Inputs:<br/>- **input**: n-dimensional input tensor.<br/>- **gamma**: m-dimensional tensor. The dimensions of **gamma** must be the same as the shape of the part of the input tensor to normalize.<br/>- **beta**: m-dimensional tensor with the same shape as **gamma**.<br/>Parameters:<br/>- **beginAxis** is an NN_INT32 scalar that specifies the axis from which normalization starts. The value range is [1, rank(input)).<br/>- **epsilon** is a scalar of NN_FLOAT32. It is a tiny amount in the normalization formula. The common value is 1e-7.<br/>Outputs:<br/>- **output**: n-dimensional tensor, with the same data type and shape as the input tensor.  | 
| OH_NN_OPS_REDUCE_PROD  | Calculates the accumulated value for a tensor along the specified dimension.<br/>Inputs:<br/>- **input**: n-dimensional input tensor, where n is less than 8.<br/>- **axis**: dimension used to calculate the product. The value is a 1D tensor. The value range of each element in **axis** is [–n, n).<br/>Parameters:<br/>- **keepDims**: indicates whether to retain the dimension. The value is a Boolean value. When its value is **true**, the number of output dimensions is the same as that of the input. When its value is **false**, the number of output dimensions is reduced.<br/>Outputs:<br/>- **output**: m-dimensional output tensor whose data type is the same as that of the input. If **keepDims** is **false**, m==n. If **keepDims** is **true**, m&lt;n.  | 
| OH_NN_OPS_REDUCE_ALL  | Operates the logical OR in the specified dimension. If **keepDims** is set to **false**, the number of dimensions is reduced for the input; if **keepDims** is set to **true**, the number of dimensions is retained.<br/>Inputs:<br/>- A n-dimensional input tensor, where n is less than 8.<br/>- A 1D tensor specifying the dimension used to operate the logical OR. The value range of each element in **axis** is [–n, n).<br/>Parameters:<br/>- **keepDims**: indicates whether to retain the dimension. The value is a Boolean value.<br/>Outputs:<br/>- **output**: m-dimensional output tensor whose data type is the same as that of the input. If **keepDims** is **false**, m==n. If **keepDims** is **true**, m&lt;n.  | 
| OH_NN_OPS_QUANT_DTYPE_CAST  | Converts the data type.<br/>Inputs:<br/>- **input**: n-dimensional tensor.<br/>Parameters:<br/>- **src_t**: data type of the input.<br/>- **dst_t**: data type of the output.<br/>Outputs:<br/>- **output**: n-dimensional tensor. The data type is determined by **input2**. The output shape is the same as the input shape.  | 
| OH_NN_OPS_TOP_K  | Obtains the values and indices of the largest k entries in the last dimension.<br/>Inputs:<br/>- **input**: n-dimensional tensor.<br/>- **input** k: first k records of data and their indices.<br/>Parameters:<br/>- **sorted**: order of sorting. The value **true** means descending and **false** means ascending.<br/>Outputs:<br/>- **output0**: largest k elements in each slice of the last dimension.<br/>- **output1**: index of the value in the last dimension of the input.  | 
| OH_NN_OPS_ARG_MAX  | Returns the index of the maximum tensor value across axes.<br/>Inputs:<br/>- **input**: n-dimensional tensor (N, ∗), where ∗ means any number of additional dimensions.<br/>Parameters:<br/>- **axis**: dimension for calculating the index of the maximum.<br/>- **keep_dims**: indicates whether to maintain the input tensor dimension. The value is a Boolean value.<br/>Outputs:<br/>- **output**: index of the maximum input tensor on the axis. The value is a tensor.  | 
| OH_NN_OPS_UNSQUEEZE  | Adds a dimension based on the value of **axis**.<br/>Inputs:<br/>- **input**: n-dimensional tensor.<br/>Parameters:<br/>- **axis**: dimension to be added. The value of **axis** can be an integer or an array of integers. The value range of the integer is [-n, n).<br/>Outputs:<br/>- **output**: output tensor.  | 
| OH_NN_OPS_GELU  | Gaussian error linear unit activation function. The int quantization input is not supported. output=0.5∗input∗(1+tanh(input/2))<br/>Inputs:<br/>- An n-dimensional input tensor.<br/>Outputs:<br/>- **output**: n-dimensional tensor, with the same data type and shape as the input tensor.  | 


### OH_NN_PerformanceMode

  
```
enum OH_NN_PerformanceMode
```
**Description**<br>
Defines the hardware performance mode.

| Name | Description | 
| -------- | -------- |
| OH_NN_PERFORMANCE_NONE  | No performance mode preference | 
| OH_NN_PERFORMANCE_LOW  | Low power consumption mode | 
| OH_NN_PERFORMANCE_MEDIUM  | Medium performance mode | 
| OH_NN_PERFORMANCE_HIGH  | High performance mode | 
| OH_NN_PERFORMANCE_EXTREME  | Ultimate performance mode | 


### OH_NN_Priority

  
```
enum OH_NN_Priority
```
**Description**<br>
Defines the model inference task priority.

| Name | Description | 
| -------- | -------- |
| OH_NN_PRIORITY_NONE  | No priority preference | 
| OH_NN_PRIORITY_LOW  | Low priority | 
| OH_NN_PRIORITY_MEDIUM  | Medium priority | 
| OH_NN_PRIORITY_HIGH  | High priority | 


### OH_NN_ReturnCode

  
```
enum OH_NN_ReturnCode
```
**Description**<br>
Defines error codes for Neural Network Runtime.

| Name | Description | 
| -------- | -------- |
| OH_NN_SUCCESS  | The operation is successful. | 
| OH_NN_FAILED  | The operation failed. | 
| OH_NN_INVALID_PARAMETER  | Invalid parameter. | 
| OH_NN_MEMORY_ERROR  | Memory-related error, for example, insufficient memory, memory data copy failure, or memory application failure. | 
| OH_NN_OPERATION_FORBIDDEN  | Invalid operation. | 
| OH_NN_NULL_PTR  | Null pointer exception | 
| OH_NN_INVALID_FILE  | Invalid file. | 
| OH_NN_UNAVALIDABLE_DEVICE  | A hardware error occurs, for example, HDL service crash. | 
| OH_NN_INVALID_PATH  | Invalid path. | 


### OH_NN_TensorType

  
```
enum OH_NN_TensorType
```
**Description**<br>
Enumerates the tensor data types.

Tensors are usually used to set the input, output, and operator parameters of a model. When a tensor is used as the input or output of a model (or operator), set the tensor type to OH_NN_TENSOR. When the tensor is used as an operator parameter, select an enumerated value other than OH_NN_TENSOR as the tensor type. Assume that the **pad** parameter of the OH_NN_OPS_CONV2D operator is being set. You need to set the **type** attribute of the [OH_NN_Tensor](_o_h___n_n___tensor.md) instance to OH_NN_CONV2D_PAD. The settings of other operator parameters are similar. The enumerated values are named in the format OH_NN_{Operator name}_{Attribute name}.

| Name | Description | 
| -------- | -------- |
| OH_NN_TENSOR  | This enumerated value is used when the tensor is used as the input or output of a model (or operator). | 
| OH_NN_ADD_ACTIVATIONTYPE  | This enumerated value is used when the tensor is used as the **activationType** parameter of the Add operator. | 
| OH_NN_AVG_POOL_KERNEL_SIZE  | This enumerated value is used when the tensor is used as the **kernel_size** parameter of the AvgPool operator. | 
| OH_NN_AVG_POOL_STRIDE  | This enumerated value is used when the tensor is used as the **stride** parameter of the AvgPool operator. | 
| OH_NN_AVG_POOL_PAD_MODE  | This enumerated value is used when the tensor is used as the **pad_mode** parameter of the AvgPool operator. | 
| OH_NN_AVG_POOL_PAD  | This enumerated value is used when the tensor is used as the **pad** parameter of the AvgPool operator. | 
| OH_NN_AVG_POOL_ACTIVATION_TYPE  | This enumerated value is used when the tensor is used as the **activation_type** parameter of the AvgPool operator. | 
| OH_NN_BATCH_NORM_EPSILON  | This enumerated value is used when the tensor is used as the **eosilon** parameter of the BatchNorm operator. | 
| OH_NN_BATCH_TO_SPACE_ND_BLOCKSIZE  | This enumerated value is used when the tensor is used as the **blockSize** parameter of the BatchToSpaceND operator. | 
| OH_NN_BATCH_TO_SPACE_ND_CROPS  | This enumerated value is used when the tensor is used as the **crops** parameter of the BatchToSpaceND operator. | 
| OH_NN_CONCAT_AXIS  | This enumerated value is used when the tensor is used as the **axis** parameter of the Concat operator. | 
| OH_NN_CONV2D_STRIDES  | This enumerated value is used when the tensor is used as the **strides** parameter of the Conv2D operator. | 
| OH_NN_CONV2D_PAD  | This enumerated value is used when the tensor is used as the **pad** parameter of the Conv2D operator. | 
| OH_NN_CONV2D_DILATION  | This enumerated value is used when the tensor is used as the **dilation** parameter of the Conv2D operator. | 
| OH_NN_CONV2D_PAD_MODE  | This enumerated value is used when the tensor is used as the **padMode** parameter of the Conv2D operator. | 
| OH_NN_CONV2D_ACTIVATION_TYPE  | This enumerated value is used when the tensor is used as the **activationType** parameter of the Conv2D operator. | 
| OH_NN_CONV2D_GROUP  | This enumerated value is used when the tensor is used as the **group** parameter of the Conv2D operator. | 
| OH_NN_CONV2D_TRANSPOSE_STRIDES  | This enumerated value is used when the tensor is used as the **strides** parameter of the Conv2DTranspose operator. | 
| OH_NN_CONV2D_TRANSPOSE_PAD  | This enumerated value is used when the tensor is used as the **pad** parameter of the Conv2DTranspose operator. | 
| OH_NN_CONV2D_TRANSPOSE_DILATION  | This enumerated value is used when the tensor is used as the **dilation** parameter of the Conv2DTranspose operator. | 
| OH_NN_CONV2D_TRANSPOSE_OUTPUT_PADDINGS  | This enumerated value is used when the tensor is used as the **outputPaddings** parameter of the Conv2DTranspose operator. | 
| OH_NN_CONV2D_TRANSPOSE_PAD_MODE  | This enumerated value is used when the tensor is used as the **padMode** parameter of the Conv2DTranspose operator. | 
| OH_NN_CONV2D_TRANSPOSE_ACTIVATION_TYPE  | This enumerated value is used when the tensor is used as the **activationType** parameter of the Conv2DTranspose operator. | 
| OH_NN_CONV2D_TRANSPOSE_GROUP  | This enumerated value is used when the tensor is used as the **group** parameter of the Conv2DTranspose operator. | 
| OH_NN_DEPTHWISE_CONV2D_NATIVE_STRIDES  | This enumerated value is used when the tensor is used as the **strides** parameter of the DepthwiseConv2dNative operator. | 
| OH_NN_DEPTHWISE_CONV2D_NATIVE_PAD  | This enumerated value is used when the tensor is used as the **pad** parameter of the DepthwiseConv2dNative operator. | 
| OH_NN_DEPTHWISE_CONV2D_NATIVE_DILATION  | This enumerated value is used when the tensor is used as the **dilation** parameter of the DepthwiseConv2dNative operator. | 
| OH_NN_DEPTHWISE_CONV2D_NATIVE_PAD_MODE  | This enumerated value is used when the tensor is used as the **padMode** parameter of the DepthwiseConv2dNative operator. | 
| OH_NN_DEPTHWISE_CONV2D_NATIVE_ACTIVATION_TYPE  | This enumerated value is used when the tensor is used as the **activationType** parameter of the DepthwiseConv2dNative operator. | 
| OH_NN_DIV_ACTIVATIONTYPE  | This enumerated value is used when the tensor is used as the **activationType** parameter of the Div operator. | 
| OH_NN_ELTWISE_MODE  | This enumerated value is used when the tensor is used as the **mode** parameter of the Eltwise operator. | 
| OH_NN_FULL_CONNECTION_AXIS  | This enumerated value is used when the tensor is used as the **axis** parameter of the FullConnection operator. | 
| OH_NN_FULL_CONNECTION_ACTIVATIONTYPE  | This enumerated value is used when the tensor is used as the **activationType** parameter of the FullConnection operator. | 
| OH_NN_MATMUL_TRANSPOSE_A  | This enumerated value is used when the tensor is used as the **transposeA** parameter of the Matmul operator. | 
| OH_NN_MATMUL_TRANSPOSE_B  | This enumerated value is used when the tensor is used as the **transposeB** parameter of the Matmul operator. | 
| OH_NN_MATMUL_ACTIVATION_TYPE  | This enumerated value is used when the tensor is used as the **activationType** parameter of the Matmul operator. | 
| OH_NN_MAX_POOL_KERNEL_SIZE  | This enumerated value is used when the tensor is used as the **kernel_size** parameter of the MaxPool operator. | 
| OH_NN_MAX_POOL_STRIDE  | This enumerated value is used when the tensor is used as the **stride** parameter of the MaxPool operator. | 
| OH_NN_MAX_POOL_PAD_MODE  | This enumerated value is used when the tensor is used as the **pad_mode** parameter of the MaxPool operator. | 
| OH_NN_MAX_POOL_PAD  | This enumerated value is used when the tensor is used as the **pad** parameter of the MaxPool operator. | 
| OH_NN_MAX_POOL_ACTIVATION_TYPE  | This enumerated value is used when the tensor is used as the **activation_type** parameter of the MaxPool operator. | 
| OH_NN_MUL_ACTIVATION_TYPE  | This enumerated value is used when the tensor is used as the **activationType** parameter of the Mul operator. | 
| OH_NN_ONE_HOT_AXIS  | This enumerated value is used when the tensor is used as the **axis** parameter of the OneHot operator. | 
| OH_NN_PAD_CONSTANT_VALUE  | This enumerated value is used when the tensor is used as the **constant_value** parameter of the Pad operator. | 
| OH_NN_SCALE_ACTIVATIONTYPE  | This enumerated value is used when the tensor is used as the **activationType** parameter of the Scale operator. | 
| OH_NN_SCALE_AXIS  | This enumerated value is used when the tensor is used as the **axis** parameter of the Scale operator. | 
| OH_NN_SOFTMAX_AXIS  | This enumerated value is used when the tensor is used as the **axis** parameter of the Softmax operator. | 
| OH_NN_SPACE_TO_BATCH_ND_BLOCK_SHAPE  | This enumerated value is used when the tensor is used as the **BlockShape** parameter of the SpaceToBatchND operator. | 
| OH_NN_SPACE_TO_BATCH_ND_PADDINGS  | This enumerated value is used when the tensor is used as the **Paddings** parameter of the SpaceToBatchND operator. | 
| OH_NN_SPLIT_AXIS  | This enumerated value is used when the tensor is used as the **Axis** parameter of the Split operator. | 
| OH_NN_SPLIT_OUTPUT_NUM  | This enumerated value is used when the tensor is used as the **OutputNum** parameter of the Split operator. | 
| OH_NN_SPLIT_SIZE_SPLITS  | This enumerated value is used when the tensor is used as the **SizeSplits** parameter of the Split operator. | 
| OH_NN_SQUEEZE_AXIS  | This enumerated value is used when the tensor is used as the **Axis** parameter of the Squeeze operator. | 
| OH_NN_STACK_AXIS  | This enumerated value is used when the tensor is used as the **Axis** parameter of the Stack operator. | 
| OH_NN_STRIDED_SLICE_BEGIN_MASK  | This enumerated value is used when the tensor is used as the **BeginMask** parameter of the StridedSlice operator. | 
| OH_NN_STRIDED_SLICE_END_MASK  | This enumerated value is used when the tensor is used as the **EndMask** parameter of the StridedSlice operator. | 
| OH_NN_STRIDED_SLICE_ELLIPSIS_MASK  | This enumerated value is used when the tensor is used as the **EllipsisMask** parameter of the StridedSlice operator. | 
| OH_NN_STRIDED_SLICE_NEW_AXIS_MASK  | This enumerated value is used when the tensor is used as the **NewAxisMask** parameter of the StridedSlice operator. | 
| OH_NN_STRIDED_SLICE_SHRINK_AXIS_MASK  | This enumerated value is used when the tensor is used as the **ShrinkAxisMask** parameter of the StridedSlice operator. | 
| OH_NN_SUB_ACTIVATIONTYPE  | This enumerated value is used when the tensor is used as the **ActivationType** parameter of the Sub operator. | 
| OH_NN_REDUCE_MEAN_KEEP_DIMS  | This enumerated value is used when the tensor is used as the **keep_dims** parameter of the ReduceMean operator. | 
| OH_NN_RESIZE_BILINEAR_NEW_HEIGHT  | This enumerated value is used when the tensor is used as the **new_height** parameter of the ResizeBilinear operator. | 
| OH_NN_RESIZE_BILINEAR_NEW_WIDTH  | This enumerated value is used when the tensor is used as the **new_width** parameter of the ResizeBilinear operator. | 
| OH_NN_RESIZE_BILINEAR_PRESERVE_ASPECT_RATIO  | This enumerated value is used when the tensor is used as the **preserve_aspect_ratio** parameter of the ResizeBilinear operator. | 
| OH_NN_RESIZE_BILINEAR_COORDINATE_TRANSFORM_MODE  | This enumerated value is used when the tensor is used as the **coordinate_transform_mode** parameter of the ResizeBilinear operator. | 
| OH_NN_RESIZE_BILINEAR_EXCLUDE_OUTSIDE  | This enumerated value is used when the tensor is used as the **exclude_outside** parameter of the ResizeBilinear operator. | 
| OH_NN_LAYER_NORM_BEGIN_NORM_AXIS  | This enumerated value is used when the tensor is used as the **beginNormAxis** parameter of the LayerNorm operator. | 
| OH_NN_LAYER_NORM_EPSILON  | This enumerated value is used when the tensor is used as the **epsilon** parameter of the LayerNorm operator. | 
| OH_NN_LAYER_NORM_BEGIN_PARAM_AXIS  | This enumerated value is used when the tensor is used as the **beginParamsAxis** parameter of the LayerNorm operator. | 
| OH_NN_LAYER_NORM_ELEMENTWISE_AFFINE  | This enumerated value is used when the tensor is used as the **elementwiseAffine** parameter of the LayerNorm operator. | 
| OH_NN_REDUCE_PROD_KEEP_DIMS  | This enumerated value is used when the tensor is used as the **keep_dims** parameter of the ReduceProd operator. | 
| OH_NN_REDUCE_ALL_KEEP_DIMS  | This enumerated value is used when the tensor is used as the **keep_dims** parameter of the ReduceAll operator. | 
| OH_NN_QUANT_DTYPE_CAST_SRC_T  | This enumerated value is used when the tensor is used as the **src_t** parameter of the QuantDTypeCast operator. | 
| OH_NN_QUANT_DTYPE_CAST_DST_T  | This enumerated value is used when the tensor is used as the **dst_t** parameter of the QuantDTypeCast operator. | 
| OH_NN_TOP_K_SORTED  | This enumerated value is used when the tensor is used as the **Sorted** parameter of the Topk operator. | 
| OH_NN_ARG_MAX_AXIS  | This enumerated value is used when the tensor is used as the **axis** parameter of the ArgMax operator. | 
| OH_NN_ARG_MAX_KEEPDIMS  | This enumerated value is used when the tensor is used as the **keepDims** parameter of the ArgMax operator. | 
| OH_NN_UNSQUEEZE_AXIS  | This enumerated value is used when the tensor is used as the **Axis** parameter of the Unsqueeze operator. | 


## Function Description


### OH_NNCompilation_Build()

  
```
OH_NN_ReturnCode OH_NNCompilation_Build (OH_NNCompilation * compilation)
```
**Description**<br>
Compiles a model.

After the compilation configuration is complete, call this method to return the compilation result. The compilation instance pushes the model and compilation options to the device for compilation. After this method is called, additional compilation operations cannot be performed. If the [OH_NNCompilation_SetDevice](#oh_nncompilation_setdevice), [OH_NNCompilation_SetCache](#oh_nncompilation_setcache), [OH_NNCompilation_SetPerformanceMode](#oh_nncompilation_setperformancemode), [OH_NNCompilation_SetPriority](#oh_nncompilation_setpriority), and [OH_NNCompilation_EnableFloat16](#oh_nncompilation_enablefloat16) methods are called, OH_NN_OPERATION_FORBIDDEN is returned.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| compilation | Pointer to the [OH_NNCompilation](#oh_nncompilation) instance.  | 

**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).



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

**Parameters**

| Name | Description | 
| -------- | -------- |
| deviceID | Device ID. |
| deviceType | Pointer to the [OH_NN_DeviceType](#oh_nn_devicetype) instance. The device type information is returned. |
 
**Returns**

Execution result of the function. If the operation is successful, **OH_NN_SUCCESS** is returned. If the operation fails, an error code is returned. For details about the error codes, see [OH_NN_ReturnCode](#oh_nn_returncode).


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