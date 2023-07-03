# MindSpore


Provides APIs related to MindSpore Lite model inference.


@Syscap SystemCapability.Ai.MindSpore


**Since**

9


## Summary


### File

| Name| Description|
| -------- | -------- |
| [context.h](context_8h.md) | Provides **Context** APIs for configuring runtime information.<br>File to include: \<mindspore/context.h>|
| [data_type.h](data__type_8h.md) | Declares tensor data types.<br>File to include: \<mindspore/data_type.h>|
| [format.h](format_8h.md) | Declares tensor data formats.<br>File to include: \<mindspore/format.h>|
| [model.h](model_8h.md) | Provides model-related APIs for model creation and inference.<br>File to include: \<mindspore/model.h>|
| [status.h](status_8h.md) | Provides the status codes of MindSpore Lite.<br>File to include: \<mindspore/status.h>|
| [tensor.h](tensor_8h.md) | Provides APIs for creating and modifying tensor information.<br>File to include: \<mindspore/tensor.h>|
| [types.h](types_8h.md) | Provides the model file types and device types supported by MindSpore Lite.<br>File to include: \<mindspore/types.h>|


### Structs

| Name| Description|
| -------- | -------- |
| [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) | Defines the tensor array structure, which is used to store the tensor array pointer and tensor array length.|
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) | Defines dimension information. The maximum dimension is set by **MS_MAX_SHAPE_NUM**.|
| [OH_AI_CallBackParam](_o_h___a_i___call_back_param.md) | Defines the operator information passed in a callback.|


### Macro Definition

| Name| Description|
| -------- | -------- |
| [OH_AI_MAX_SHAPE_NUM](#oh_ai_max_shape_num)   32 | Defines dimension information. The maximum dimension is set by **MS_MAX_SHAPE_NUM**.|


### Types

| Name| Description|
| -------- | -------- |
| [OH_AI_ContextHandle](#oh_ai_contexthandle) | Defines the pointer to the MindSpore context. |
| [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) | Defines the pointer to the MindSpore device information.|
| [OH_AI_DataType](#oh_ai_datatype-1) | Declares data types supported by MSTensor.|
| [OH_AI_Format](#oh_ai_format-1) | Declares data formats supported by MSTensor.|
| [OH_AI_ModelHandle](#oh_ai_modelhandle) | Defines the pointer to a model object.|
| [OH_AI_TensorHandleArray](#oh_ai_tensorhandlearray) | Defines the tensor array structure, which is used to store the tensor array pointer and tensor array length.|
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) | Defines dimension information. The maximum dimension is set by **MS_MAX_SHAPE_NUM**.|
| [OH_AI_CallBackParam](#oh_ai_callbackparam) | Defines the operator information passed in a callback.|
| [OH_AI_KernelCallBack](#oh_ai_kernelcallback)| Defines the pointer to a callback.|
| [OH_AI_Status](#oh_ai_status-1) | Defines MindSpore status codes.|
| [OH_AI_TensorHandle](#oh_ai_tensorhandle) | Defines the handle of a tensor object.|
| [OH_AI_ModelType](#oh_ai_modeltype-1) | Defines model file types.|
| [OH_AI_DeviceType](#oh_ai_devicetype-1) | Defines the supported device types.|


### Enums

| Name| Description|
| -------- | -------- |
| [OH_AI_DataType](#oh_ai_datatype-1) {<br>OH_AI_DATATYPE_UNKNOWN = 0,<br>OH_AI_DATATYPE_OBJECTTYPE_STRING = 12,<br>OH_AI_DATATYPE_OBJECTTYPE_LIST = 13, <br>OH_AI_DATATYPE_OBJECTTYPE_TUPLE = 14, <br>OH_AI_DATATYPE_OBJECTTYPE_TENSOR = 17, <br>OH_AI_DATATYPE_NUMBERTYPE_BEGIN = 29,<br>OH_AI_DATATYPE_NUMBERTYPE_BOOL = 30,<br>OH_AI_DATATYPE_NUMBERTYPE_INT8 = 32, <br>OH_AI_DATATYPE_NUMBERTYPE_INT16 = 33, <br>OH_AI_DATATYPE_NUMBERTYPE_INT32 = 34, <br>OH_AI_DATATYPE_NUMBERTYPE_INT64 = 35, <br>OH_AI_DATATYPE_NUMBERTYPE_UINT8 = 37, <br>OH_AI_DATATYPE_NUMBERTYPE_UINT16 = 38,<br>OH_AI_DATATYPE_NUMBERTYPE_UINT32 = 39, <br>OH_AI_DATATYPE_NUMBERTYPE_UINT64 = 40, <br>OH_AI_DATATYPE_NUMBERTYPE_FLOAT16 = 42, <br>OH_AI_DATATYPE_NUMBERTYPE_FLOAT32 = 43, <br>OH_AI_DATATYPE_NUMBERTYPE_FLOAT64 = 44,<br>OH_AI_DATATYPE_NUMBERTYPE_END = 46,<br>OH_AI_DataTypeInvalid = INT32_MAX } | Declares data types supported by MSTensor.|
| [OH_AI_Format](#oh_ai_format-1) {<br>OH_AI_FORMAT_NCHW = 0,<br>OH_AI_FORMAT_NHWC = 1,<br>OH_AI_FORMAT_NHWC4 = 2,<br>OH_AI_FORMAT_HWKC = 3,<br>OH_AI_FORMAT_HWCK = 4,<br>OH_AI_FORMAT_KCHW = 5,<br>OH_AI_FORMAT_CKHW = 6,<br>OH_AI_FORMAT_KHWC = 7,<br>OH_AI_FORMAT_CHWK = 8,<br>OH_AI_FORMAT_HW = 9,<br>OH_AI_FORMAT_HW4 = 10,<br>OH_AI_FORMAT_NC = 11,<br>OH_AI_FORMAT_NC4 = 12,<br>OH_AI_FORMAT_NC4HW4 = 13,<br>OH_AI_FORMAT_NCDHW = 15,<br>OH_AI_FORMAT_NWC = 16,<br>OH_AI_FORMAT_NCW = 17 } | Declares data formats supported by MSTensor.|
| [OH_AI_CompCode](#oh_ai_compcode) {<br>OH_AI_COMPCODE_CORE = 0x00000000u,<br>OH_AI_COMPCODE_LITE = 0xF0000000u } | Defines MindSpore component codes. |
| [OH_AI_Status](#oh_ai_status-1) {<br>OH_AI_STATUS_SUCCESS = 0,<br>OH_AI_STATUS_CORE_FAILED = OH_AI_COMPCODE_CORE \| 0x1, <br>OH_AI_STATUS_LITE_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -1), <br>OH_AI_STATUS_LITE_NULLPTR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -2),<br>OH_AI_STATUS_LITE_PARAM_INVALID = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -3),<br>OH_AI_STATUS_LITE_NO_CHANGE = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -4),<br>OH_AI_STATUS_LITE_SUCCESS_EXIT = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -5),<br>OH_AI_STATUS_LITE_MEMORY_FAILED = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -6),<br>OH_AI_STATUS_LITE_NOT_SUPPORT = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -7),<br>OH_AI_STATUS_LITE_THREADPOOL_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -8),<br>OH_AI_STATUS_LITE_UNINITIALIZED_OBJ = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -9),<br>OH_AI_STATUS_LITE_OUT_OF_TENSOR_RANGE, <br>OH_AI_STATUS_LITE_INPUT_TENSOR_ERROR,<br>OH_AI_STATUS_LITE_REENTRANT_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -102),<br>OH_AI_STATUS_LITE_GRAPH_FILE_ERROR,<br>OH_AI_STATUS_LITE_NOT_FIND_OP = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -300),   OH_AI_STATUS_LITE_INVALID_OP_NAME = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -301),<br>OH_AI_STATUS_LITE_INVALID_OP_ATTR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -302),<br>OH_AI_STATUS_LITE_OP_EXECUTE_FAILURE,<br>OH_AI_STATUS_LITE_FORMAT_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -400),<br>OH_AI_STATUS_LITE_INFER_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -500),<br>OH_AI_STATUS_LITE_INFER_INVALID = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -501),<br>OH_AI_STATUS_LITE_INPUT_PARAM_INVALID } | Defines MindSpore status codes.|
| [OH_AI_ModelType](#oh_ai_modeltype-1) {<br>OH_AI_MODELTYPE_MINDIR = 0,<br>OH_AI_MODELTYPE_INVALID = 0xFFFFFFFF } | Defines model file types.|
| [OH_AI_DeviceType](#oh_ai_devicetype-1) {<br>OH_AI_DEVICETYPE_CPU = 0,<br>OH_AI_DEVICETYPE_KIRIN_GPU,<br>OH_AI_DEVICETYPE_KIRIN_NPU,<br>OH_AI_DEVICETYPE_NNRT = 60,<br>OH_AI_DEVICETYPE_INVALID = 100 } | Defines the supported device types.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_AI_ContextCreate](#oh_ai_contextcreate) () | Creates a context object.|
| [OH_AI_ContextDestroy](#oh_ai_contextdestroy) (OH_AI_ContextHandle \*context) | Destroys a context object.|
| [OH_AI_ContextSetThreadNum](#oh_ai_contextsetthreadnum) (OH_AI_ContextHandle context, int32_t thread_num) | Sets the number of runtime threads.|
| [OH_AI_ContextGetThreadNum](#oh_ai_contextgetthreadnum) (const OH_AI_ContextHandle context) | Obtains the number of threads.|
| [OH_AI_ContextSetThreadAffinityMode](#oh_ai_contextsetthreadaffinitymode) (OH_AI_ContextHandle context, int mode) | Sets the affinity mode for binding runtime threads to CPU cores, which are classified into large, medium, and small cores based on the CPU frequency. You only need to bind the large or medium cores, but not small cores.|
| [OH_AI_ContextGetThreadAffinityMode](#oh_ai_contextgetthreadaffinitymode) (const OH_AI_ContextHandle context) | Obtains the affinity mode for binding runtime threads to CPU cores.|
| [OH_AI_ContextSetThreadAffinityCoreList](#oh_ai_contextsetthreadaffinitycorelist) (OH_AI_ContextHandle context, const int32_t \*core_list, <br>size_t core_num) | Sets the list of CPU cores bound to a runtime thread.|
| [OH_AI_ContextGetThreadAffinityCoreList](#oh_ai_contextgetthreadaffinitycorelist) (const OH_AI_ContextHandle context, size_t \*core_num) | Obtains the list of bound CPU cores.|
| [OH_AI_ContextSetEnableParallel](#oh_ai_contextsetenableparallel) (OH_AI_ContextHandle context, bool is_parallel) | Sets whether to enable parallelism between operators. The setting is ineffective because the feature of this API is not yet available.|
| [OH_AI_ContextGetEnableParallel](#oh_ai_contextgetenableparallel) (const OH_AI_ContextHandle context) | Checks whether parallelism between operators is supported.|
| [OH_AI_ContextAddDeviceInfo](#oh_ai_contextadddeviceinfo) (OH_AI_ContextHandle context, OH_AI_DeviceInfoHandle device_info) | Attaches the custom device information to the inference context.|
| [OH_AI_DeviceInfoCreate](#oh_ai_deviceinfocreate) (OH_AI_DeviceType device_type) | Creates a device information object.|
| [OH_AI_DeviceInfoDestroy](#oh_ai_deviceinfodestroy) (OH_AI_DeviceInfoHandle \*device_info) | Destroys a device information object. Note: After the device information instance is added to the context, the caller does not need to destroy it manually.|
| [OH_AI_DeviceInfoSetProvider](#oh_ai_deviceinfosetprovider) (OH_AI_DeviceInfoHandle device_info, const char \*provider) | Sets the provider name.|
| [OH_AI_DeviceInfoGetProvider](#oh_ai_deviceinfogetprovider) (const OH_AI_DeviceInfoHandle device_info) | Obtains the provider name.|
| [OH_AI_DeviceInfoSetProviderDevice](#oh_ai_deviceinfosetproviderdevice) (OH_AI_DeviceInfoHandle device_info, const char \*device) | Sets the name of a provider device.|
| [OH_AI_DeviceInfoGetProviderDevice](#oh_ai_deviceinfogetproviderdevice) (const OH_AI_DeviceInfoHandle device_info) | Obtains the name of a provider device.|
| [OH_AI_DeviceInfoGetDeviceType](#oh_ai_deviceinfogetdevicetype) (const OH_AI_DeviceInfoHandle device_info) | Obtains the device type.|
| [OH_AI_DeviceInfoSetEnableFP16](#oh_ai_deviceinfosetenablefp16) (OH_AI_DeviceInfoHandle device_info, bool is_fp16) | Sets whether to enable float16 inference. This function is available only for CPU and GPU devices.|
| [OH_AI_DeviceInfoGetEnableFP16](#oh_ai_deviceinfogetenablefp16) (const OH_AI_DeviceInfoHandle device_info) | Checks whether float16 inference is enabled. This function is available only for CPU and GPU devices.|
| [OH_AI_DeviceInfoSetFrequency](#oh_ai_deviceinfosetfrequency) (OH_AI_DeviceInfoHandle device_info, int frequency) | Sets the NPU frequency type. This function is available only for NPU devices.|
| [OH_AI_DeviceInfoGetFrequency](#oh_ai_deviceinfogetfrequency) (const OH_AI_DeviceInfoHandle device_info) | Obtains the NPU frequency type. This function is available only for NPU devices.|
| [OH_AI_ModelCreate](#oh_ai_modelcreate) () | Creates a model object.|
| [OH_AI_ModelDestroy](#oh_ai_modeldestroy) (OH_AI_ModelHandle \*model) | Destroys a model object.|
| [OH_AI_ModelBuild](#oh_ai_modelbuild) (OH_AI_ModelHandle model, const void \*model_data, size_t data_size, OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context) | Loads and builds a MindSpore model from the memory buffer.|
| [OH_AI_ModelBuildFromFile](#oh_ai_modelbuildfromfile) (OH_AI_ModelHandle model, const char \*model_path, <br>OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context) | Loads and builds a MindSpore model from a model file.|
| [OH_AI_ModelResize](#oh_ai_modelresize) (OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs, OH_AI_ShapeInfo \*shape_infos, size_t shape_info_num) | Adjusts the input tensor shapes of a built model.|
| [OH_AI_ModelPredict](#oh_ai_modelpredict) (OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs, OH_AI_TensorHandleArray \*outputs, const OH_AI_KernelCallBack before, <br>const OH_AI_KernelCallBack after) | Performs model inference.|
| [OH_AI_ModelGetInputs](#oh_ai_modelgetinputs) (const OH_AI_ModelHandle model) | Obtains the input tensor array structure of a model.|
| [OH_AI_ModelGetOutputs](#oh_ai_modelgetoutputs) (const OH_AI_ModelHandle model) | Obtains the output tensor array structure of a model.|
| [OH_AI_ModelGetInputByTensorName](#oh_ai_modelgetinputbytensorname) (const OH_AI_ModelHandle model, const char \*tensor_name) | Obtains the input tensor of a model by tensor name.|
| [OH_AI_ModelGetOutputByTensorName](#oh_ai_modelgetoutputbytensorname) (const OH_AI_ModelHandle model, const char \*tensor_name) | Obtains the output tensor of a model by tensor name.|
| [OH_AI_TensorCreate](#oh_ai_tensorcreate) (const char \*name, OH_AI_DataType type, const int64_t \*shape, <br>size_t shape_num, const void \*data, size_t data_len) | Creates a tensor object.|
| [OH_AI_TensorDestroy](#oh_ai_tensordestroy) (OH_AI_TensorHandle \*tensor) | Destroys a tensor object.|
| [OH_AI_TensorClone](#oh_ai_tensorclone) (OH_AI_TensorHandle tensor) | Deeply copies a tensor.|
| [OH_AI_TensorSetName](#oh_ai_tensorsetname) (OH_AI_TensorHandle tensor, const char \*name) | Sets the tensor name.|
| [OH_AI_TensorGetName](#oh_ai_tensorgetname) (const OH_AI_TensorHandle tensor) | Obtains the tensor name.|
| [OH_AI_TensorSetDataType](#oh_ai_tensorsetdatatype) (OH_AI_TensorHandle tensor, OH_AI_DataType type) | Sets the data type of a tensor.|
| [OH_AI_TensorGetDataType](#oh_ai_tensorgetdatatype) (const OH_AI_TensorHandle tensor) | Obtains the tensor type.|
| [OH_AI_TensorSetShape](#oh_ai_tensorsetshape) (OH_AI_TensorHandle tensor, const int64_t \*shape, size_t shape_num) | Sets the tensor shape.|
| [OH_AI_TensorGetShape](#oh_ai_tensorgetshape) (const OH_AI_TensorHandle tensor, size_t \*shape_num) | Obtains the tensor shape.|
| [OH_AI_TensorSetFormat](#oh_ai_tensorsetformat) (OH_AI_TensorHandle tensor, OH_AI_Format format) | Sets the tensor data format.|
| [OH_AI_TensorGetFormat](#oh_ai_tensorgetformat) (const OH_AI_TensorHandle tensor) | Obtains the tensor data format.|
| [OH_AI_TensorSetData](#oh_ai_tensorsetdata) (OH_AI_TensorHandle tensor, void \*data) | Sets the tensor data.|
| [OH_AI_TensorGetData](#oh_ai_tensorgetdata) (const OH_AI_TensorHandle tensor) | Obtains the pointer to tensor data.|
| [OH_AI_TensorGetMutableData](#oh_ai_tensorgetmutabledata) (const OH_AI_TensorHandle tensor) | Obtains the pointer to variable tensor data. If the data is empty, memory will be allocated.|
| [OH_AI_TensorGetElementNum](#oh_ai_tensorgetelementnum) (const OH_AI_TensorHandle tensor) | Obtains the number of tensor elements.|
| [OH_AI_TensorGetDataSize](#oh_ai_tensorgetdatasize) (const OH_AI_TensorHandle tensor) | Obtains the number of bytes of the tensor data.|


## **Macro Description**


### OH_AI_MAX_SHAPE_NUM


```
#define OH_AI_MAX_SHAPE_NUM   32
```

**Description**

Defines dimension information. The maximum dimension is set by **MS_MAX_SHAPE_NUM**.


## **Type Description**


### OH_AI_CallBackParam


```
typedef struct OH_AI_CallBackParam OH_AI_CallBackParam
```

**Description**

Defines the operator information passed in a callback.


### OH_AI_ContextHandle


```
typedef void* OH_AI_ContextHandle
```

**Description**

Defines the pointer to the MindSpore context. 


### OH_AI_DataType


```
typedef enum OH_AI_DataType OH_AI_DataType
```

**Description**

Declares data types supported by MSTensor.


### OH_AI_DeviceInfoHandle


```
typedef void* OH_AI_DeviceInfoHandle
```

**Description**

Defines the pointer to the MindSpore device information.


### OH_AI_DeviceType


```
typedef enum OH_AI_DeviceType OH_AI_DeviceType
```

**Description**

Defines the supported device types.


### OH_AI_Format


```
typedef enum OH_AI_Format OH_AI_Format
```

**Description**

Declares data formats supported by MSTensor.


### OH_AI_KernelCallBack


```
typedef bool(* OH_AI_KernelCallBack) (const OH_AI_TensorHandleArray inputs, const OH_AI_TensorHandleArray outputs, const OH_AI_CallBackParam kernel_Info)
```

**Description**

Defines the pointer to a callback.

This pointer is used to set the two callback functions in [OH_AI_ModelPredict](#oh_ai_modelpredict). Each callback function must contain three parameters, where **inputs** and **outputs** indicate the input and output tensors of the operator, and **kernel_Info** indicates information about the current operator. You can use the callback functions to monitor the operator execution status, for example, operator execution time and the operator correctness.


### OH_AI_ModelHandle


```
typedef void* OH_AI_ModelHandle
```

**Description**

Defines the pointer to a model object.


### OH_AI_ModelType


```
typedef enum OH_AI_ModelType OH_AI_ModelType
```

**Description**

Defines model file types.


### OH_AI_Status


```
typedef enum OH_AI_Status OH_AI_Status
```

**Description**

Defines MindSpore status codes.


### OH_AI_TensorHandle


```
typedef void* OH_AI_TensorHandle
```

**Description**

Defines the handle of a tensor object.


### OH_AI_TensorHandleArray


```
typedef struct OH_AI_TensorHandleArray OH_AI_TensorHandleArray
```

**Description**

Defines the tensor array structure, which is used to store the tensor array pointer and tensor array length.


## **Enum Description**


### OH_AI_CompCode


```
enum OH_AI_CompCode
```

**Description**

Defines MindSpore component codes. 

| Value| Description|
| -------- | -------- |
| OH_AI_COMPCODE_CORE | MindSpore Core code|
| OH_AI_COMPCODE_LITE | MindSpore Lite code|


### OH_AI_DataType


```
enum OH_AI_DataType
```

**Description**

Declares data types supported by MSTensor.

| Value| Description|
| -------- | -------- |
| OH_AI_DATATYPE_UNKNOWN | Unknown data type.|
| OH_AI_DATATYPE_OBJECTTYPE_STRING | String data.|
| OH_AI_DATATYPE_OBJECTTYPE_LIST | List data.|
| OH_AI_DATATYPE_OBJECTTYPE_TUPLE | Tuple data.|
| OH_AI_DATATYPE_OBJECTTYPE_TENSOR | TensorList data.|
| OH_AI_DATATYPE_NUMBERTYPE_BEGIN | Beginning of the number type.|
| OH_AI_DATATYPE_NUMBERTYPE_BOOL | Bool data.|
| OH_AI_DATATYPE_NUMBERTYPE_INT8 | Int8 data.|
| OH_AI_DATATYPE_NUMBERTYPE_INT16 | Int16 data.|
| OH_AI_DATATYPE_NUMBERTYPE_INT32 | Int32 data.|
| OH_AI_DATATYPE_NUMBERTYPE_INT64 | Int64 data.|
| OH_AI_DATATYPE_NUMBERTYPE_UINT8 | UInt8 data.|
| OH_AI_DATATYPE_NUMBERTYPE_UINT16 | UInt16 data .|
| OH_AI_DATATYPE_NUMBERTYPE_UINT32 | UInt32 data.|
| OH_AI_DATATYPE_NUMBERTYPE_UINT64 | UInt64 data.|
| OH_AI_DATATYPE_NUMBERTYPE_FLOAT16 | Float16 data.|
| OH_AI_DATATYPE_NUMBERTYPE_FLOAT32 | Float32 data.|
| OH_AI_DATATYPE_NUMBERTYPE_FLOAT64 | Float64 data.|
| OH_AI_DATATYPE_NUMBERTYPE_END | End of the number type.|
| OH_AI_DataTypeInvalid | Invalid data type.|


### OH_AI_DeviceType


```
enum OH_AI_DeviceType
```

**Description**

Defines the supported device types.

| Value| Description|
| -------- | -------- |
| OH_AI_DEVICETYPE_CPU | Device type: CPU|
| OH_AI_DEVICETYPE_GPU | Device type: GPU Reserved|
| OH_AI_DEVICETYPE_KIRIN_NPU | Device type: Kirin NPU Reserved|
| OH_AI_DEVICETYPE_NNRT | Device type: NNRt OHOS device range: [60, 80)|
| OH_AI_DEVICETYPE_INVALID | Invalid device type|


### OH_AI_Format


```
enum OH_AI_Format
```

**Description**

Declares data formats supported by MSTensor.

| Value             | Description            |
| ------------------- | ---------------- |
| OH_AI_FORMAT_NCHW   | Tensor data is stored in the sequence of batch number N, channel C, height H, and width W.  |
| OH_AI_FORMAT_NHWC   | Tensor data is stored in the sequence of batch number N, height H, width W, and channel C.  |
| OH_AI_FORMAT_NHWC4  | Tensor data is stored in the sequence of batch number N, height H, width W, and channel C. The C axis is 4-byte aligned.  |
| OH_AI_FORMAT_HWKC   | Tensor data is stored in the sequence of height H, width W, core count K, and channel C.   |
| OH_AI_FORMAT_HWCK   | Tensor data is stored in the sequence of height H, width W, channel C, and core count K.  |
| OH_AI_FORMAT_KCHW   | Tensor data is stored in the sequence of core count K, channel C, height H, and width W.  |
| OH_AI_FORMAT_CKHW   | Tensor data is stored in the sequence of channel C, core count K, height H, and width W.  |
| OH_AI_FORMAT_KHWC   | Tensor data is stored in the sequence of core count K, height H, width W, and channel C.   |
| OH_AI_FORMAT_CHWK   | Tensor data is stored in the sequence of channel C, height H, width W, and core count K.  |
| OH_AI_FORMAT_HW     | Tensor data is stored in the sequence of height H and width W.    |
| OH_AI_FORMAT_HW4    | Tensor data is stored in the sequence of height H and width W. The W axis is 4-byte aligned.   |
| OH_AI_FORMAT_NC     | Tensor data is stored in the sequence of batch number N and channel C.    |
| OH_AI_FORMAT_NC4    | Tensor data is stored in the sequence of batch number N and channel C. The C axis is 4-byte aligned.    |
| OH_AI_FORMAT_NC4HW4 | Tensor data is stored in the sequence of batch number N, channel C, height H, and width W. The C axis and W axis are 4-byte aligned.|
| OH_AI_FORMAT_NCDHW  | Tensor data is stored in the sequence of batch number N, channel C, depth D, height H, and width W. |
| OH_AI_FORMAT_NWC    | Tensor data is stored in the sequence of batch number N, width W, and channel C.   |
| OH_AI_FORMAT_NCW    | Tensor data is stored in the sequence of batch number N, channel C, and width W.   |


### OH_AI_ModelType


```
enum OH_AI_ModelType
```

**Description**

Defines model file types.

| Value| Description|
| -------- | -------- |
| OH_AI_MODELTYPE_MINDIR | Model type of MindIR. The extension of the model file name is **.ms**.|
| OH_AI_MODELTYPE_INVALID | Invalid model type.|


### OH_AI_Status


```
enum OH_AI_Status
```

**Description**

Defines MindSpore status codes.

| Value| Description|
| -------- | -------- |
| OH_AI_STATUS_SUCCESS | Success.|
| OH_AI_STATUS_CORE_FAILED | MindSpore Core failure.|
| OH_AI_STATUS_LITE_ERROR | MindSpore Lite error.|
| OH_AI_STATUS_LITE_NULLPTR | MindSpore Lite null pointer.|
| OH_AI_STATUS_LITE_PARAM_INVALID | MindSpore Lite invalid parameters.|
| OH_AI_STATUS_LITE_NO_CHANGE | MindSpore Lite no change.|
| OH_AI_STATUS_LITE_SUCCESS_EXIT | MindSpore Lite exit without errors.|
| OH_AI_STATUS_LITE_MEMORY_FAILED | MindSpore Lite memory allocation failure.|
| OH_AI_STATUS_LITE_NOT_SUPPORT | MindSpore Lite not supported.|
| OH_AI_STATUS_LITE_THREADPOOL_ERROR | MindSpore Lite thread pool error.|
| OH_AI_STATUS_LITE_UNINITIALIZED_OBJ | MindSpore Lite uninitialized.|
| OH_AI_STATUS_LITE_OUT_OF_TENSOR_RANGE | MindSpore Lite tensor overflow.|
| OH_AI_STATUS_LITE_INPUT_TENSOR_ERROR | MindSpore Lite input tensor error.|
| OH_AI_STATUS_LITE_REENTRANT_ERROR | MindSpore Lite reentry error.|
| OH_AI_STATUS_LITE_GRAPH_FILE_ERROR | MindSpore Lite file error.|
| OH_AI_STATUS_LITE_NOT_FIND_OP | MindSpore Lite operator not found.|
| OH_AI_STATUS_LITE_INVALID_OP_NAME | MindSpore Lite invalid operators.|
| OH_AI_STATUS_LITE_INVALID_OP_ATTR | MindSpore Lite invalid operator hyperparameters.|
| OH_AI_STATUS_LITE_OP_EXECUTE_FAILURE | MindSpore Lite operator execution failure.|
| OH_AI_STATUS_LITE_FORMAT_ERROR | MindSpore Lite tensor format error.|
| OH_AI_STATUS_LITE_INFER_ERROR | MindSpore Lite shape inference error.|
| OH_AI_STATUS_LITE_INFER_INVALID | MindSpore Lite invalid shape inference.|
| OH_AI_STATUS_LITE_INPUT_PARAM_INVALID | MindSpore Lite invalid input parameters.|


## **Function Description**


### OH_AI_ContextAddDeviceInfo()


```
OH_AI_API void OH_AI_ContextAddDeviceInfo (OH_AI_ContextHandle context, OH_AI_DeviceInfoHandle device_info )
```

**Description**

Attaches the custom device information to the inference context.

**Parameters**

| Name| Description|
| -------- | -------- |
| context | [OH_AI_ContextHandle](#oh_ai_contexthandle) that points to the context instance.|
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|


### OH_AI_ContextCreate()


```
OH_AI_API OH_AI_ContextHandle OH_AI_ContextCreate ()
```

**Description**

Creates a context object.

**Returns**

[OH_AI_ContextHandle](#oh_ai_contexthandle) that points to the context instance.


### OH_AI_ContextDestroy()


```
OH_AI_API void OH_AI_ContextDestroy (OH_AI_ContextHandle * context)
```

**Description**

Destroys a context object.

**Parameters**

| Name| Description|
| -------- | -------- |
| context | Level-2 pointer to [OH_AI_ContextHandle](#oh_ai_contexthandle). After the context is destroyed, the pointer is set to null. |


### OH_AI_ContextGetEnableParallel()


```
OH_AI_API bool OH_AI_ContextGetEnableParallel (const OH_AI_ContextHandle context)
```

**Description**

Checks whether parallelism between operators is supported.

**Parameters**

| Name| Description|
| -------- | -------- |
| context | [OH_AI_ContextHandle](#oh_ai_contexthandle) that points to the context instance.|

**Returns**

Whether parallelism between operators is supported. The value **true** means that parallelism between operators is supported, and the value **false** means the opposite.


### OH_AI_ContextGetThreadAffinityCoreList()


```
OH_AI_API const int32_t* OH_AI_ContextGetThreadAffinityCoreList (const OH_AI_ContextHandle context, size_t * core_num )
```

**Description**

Obtains the list of bound CPU cores.

**Parameters**

| Name| Description|
| -------- | -------- |
| context | [OH_AI_ContextHandle](#oh_ai_contexthandle) that points to the context instance.|
| core_num | Number of CPU cores.|

**Returns**

Specifies the CPU core binding list. This list is managed by [OH_AI_ContextHandle](#oh_ai_contexthandle). The caller does not need to destroy it manually.


### OH_AI_ContextGetThreadAffinityMode()


```
OH_AI_API int OH_AI_ContextGetThreadAffinityMode (const OH_AI_ContextHandle context)
```

**Description**

Obtains the affinity mode for binding runtime threads to CPU cores.

**Parameters**

| Name| Description|
| -------- | -------- |
| context | [OH_AI_ContextHandle](#oh_ai_contexthandle) that points to the context instance.|

**Returns**

Affinity mode. **0**: no affinities; **1**: big cores first; **2**: medium cores first


### OH_AI_ContextGetThreadNum()


```
OH_AI_API int32_t OH_AI_ContextGetThreadNum (const OH_AI_ContextHandle context)
```

**Description**

Obtains the number of threads.

**Parameters**

| Name| Description|
| -------- | -------- |
| context | [OH_AI_ContextHandle](#oh_ai_contexthandle) that points to the context instance.|

**Returns**

Number of threads.


### OH_AI_ContextSetEnableParallel()


```
OH_AI_API void OH_AI_ContextSetEnableParallel (OH_AI_ContextHandle context, bool is_parallel )
```

**Description**

Sets whether to enable parallelism between operators. The setting is ineffective because the feature of this API is not yet available.

**Parameters**

| Name| Description|
| -------- | -------- |
| context | [OH_AI_ContextHandle](#oh_ai_contexthandle) that points to the context instance.|
| is_parallel | Whether parallelism between operators is supported. The value **true** means that parallelism between operators is supported, and the value **false** means the opposite.|


### OH_AI_ContextSetThreadAffinityCoreList()


```
OH_AI_API void OH_AI_ContextSetThreadAffinityCoreList (OH_AI_ContextHandle context, const int32_t * core_list, size_t core_num )
```

**Description**

Sets the list of CPU cores bound to a runtime thread.

For example, if **core_list** is set to **[2,6,8]**, threads run on the 2nd, 6th, and 8th CPU cores. If [OH_AI_ContextSetThreadAffinityMode](#oh_ai_contextsetthreadaffinitymode) and [OH_AI_ContextSetThreadAffinityCoreList](#oh_ai_contextsetthreadaffinitycorelist) are called for the same context object, the **core_list** parameter of [OH_AI_ContextSetThreadAffinityCoreList](#oh_ai_contextsetthreadaffinitycorelist) takes effect, but the **mode** parameter of [OH_AI_ContextSetThreadAffinityMode](#oh_ai_contextsetthreadaffinitymode) does not.

**Parameters**

| Name| Description|
| -------- | -------- |
| context | [OH_AI_ContextHandle](#oh_ai_contexthandle) that points to the context instance.|
| core_list | List of bound CPU cores.|
| core_num | Number of cores, which indicates the length of **core_list**.|


### OH_AI_ContextSetThreadAffinityMode()


```
OH_AI_API void OH_AI_ContextSetThreadAffinityMode (OH_AI_ContextHandle context, int mode )
```

**Description**

Sets the affinity mode for binding runtime threads to CPU cores, which are classified into large, medium, and small cores based on the CPU frequency. You only need to bind the large or medium cores, but not small cores.

**Parameters**

| Name| Description|
| -------- | -------- |
| context | [OH_AI_ContextHandle](#oh_ai_contexthandle) that points to the context instance.|
| mode | Affinity mode. **0**: no affinities; **1**: big cores first; **2**: medium cores first|


### OH_AI_ContextSetThreadNum()


```
OH_AI_API void OH_AI_ContextSetThreadNum (OH_AI_ContextHandle context, int32_t thread_num )
```

**Description**

Sets the number of runtime threads.

**Parameters**

| Name| Description|
| -------- | -------- |
| context | [OH_AI_ContextHandle](#oh_ai_contexthandle) that points to the context instance.|
| thread_num | Number of runtime threads.|


### OH_AI_DeviceInfoCreate()


```
OH_AI_API OH_AI_DeviceInfoHandle OH_AI_DeviceInfoCreate (OH_AI_DeviceType device_type)
```

**Description**

Creates a device information object.

**Parameters**

| Name| Description|
| -------- | -------- |
| device_type | Device type, which is specified by [OH_AI_DeviceType](#oh_ai_devicetype-1).|

**Returns**

[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.


### OH_AI_DeviceInfoDestroy()


```
OH_AI_API void OH_AI_DeviceInfoDestroy (OH_AI_DeviceInfoHandle * device_info)
```

**Description**

Destroys a device information object. Note: After the device information instance is added to the context, the caller does not need to destroy it manually.

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|


### OH_AI_DeviceInfoGetDeviceType()


```
OH_AI_API OH_AI_DeviceType OH_AI_DeviceInfoGetDeviceType (const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Obtains the device type.

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|

**Returns**

Type of the provider device.


### OH_AI_DeviceInfoGetEnableFP16()


```
OH_AI_API bool OH_AI_DeviceInfoGetEnableFP16 (const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Checks whether float16 inference is enabled. This function is available only for CPU and GPU devices.

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|

**Returns**

Whether float16 inference is enabled.


### OH_AI_DeviceInfoGetFrequency()


```
OH_AI_API int OH_AI_DeviceInfoGetFrequency (const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Obtains the NPU frequency type. This API is available only for NPU devices.

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|

**Returns**

NPU frequency type. The value ranges from **0** to **4**. **1**: low power consumption; **2**: balanced; **3**: high performance; **4**: ultra-high performance


### OH_AI_DeviceInfoGetProvider()


```
OH_AI_API const char* OH_AI_DeviceInfoGetProvider (const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Obtains the provider name.

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|

**Returns**

Provider name.


### OH_AI_DeviceInfoGetProviderDevice()


```
OH_AI_API const char* OH_AI_DeviceInfoGetProviderDevice (const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Obtains the name of a provider device.

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|

**Returns**

Name of the provider device.


### OH_AI_DeviceInfoSetEnableFP16()


```
OH_AI_API void OH_AI_DeviceInfoSetEnableFP16 (OH_AI_DeviceInfoHandle device_info, bool is_fp16 )
```

**Description**

Sets whether to enable float16 inference. This function is available only for CPU and GPU devices.

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|
| is_fp16 | Whether to enable the float16 inference mode.|


### OH_AI_DeviceInfoSetFrequency()


```
OH_AI_API void OH_AI_DeviceInfoSetFrequency (OH_AI_DeviceInfoHandle device_info, int frequency )
```

**Description**

Sets the NPU frequency type. This function is available only for NPU devices.

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|
| frequency | NPU frequency type. The value ranges from **0** to **4**. The default value is **3**. **1**: low power consumption; **2**: balanced; **3**: high performance; **4**: ultra-high performance|


### OH_AI_DeviceInfoSetProvider()


```
OH_AI_API void OH_AI_DeviceInfoSetProvider (OH_AI_DeviceInfoHandle device_info, const char * provider )
```

**Description**

Sets the provider name.

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|
| provider | Provider name.|


### OH_AI_DeviceInfoSetProviderDevice()


```
OH_AI_API void OH_AI_DeviceInfoSetProviderDevice (OH_AI_DeviceInfoHandle device_info, const char * device )
```

**Description**

Sets the name of a provider device.

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|
| device | Name of the provider device, for example, CPU.|


### OH_AI_ModelBuild()


```
OH_AI_API OH_AI_Status OH_AI_ModelBuild (OH_AI_ModelHandle model, const void * model_data, size_t data_size, OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context )
```

**Description**

Loads and builds a MindSpore model from the memory buffer.
Note that the same [OH_AI_ContextHandle](#oh_ai_contexthandle) object can only be passed to [OH_AI_ModelBuildFromFile](#oh_ai_modelbuildfromfile) or [OH_AI_ModelBuild](#oh_ai_modelbuild) once. If you call this function multiple times, make sure that you create multiple [OH_AI_ContextHandle](#oh_ai_contexthandle) objects accordingly.

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|
| model_data | Address of the loaded model data in the memory.|
| data_size | Length of the model data.|
| model_type | Model file type, which is specified by [OH_AI_ModelType](#oh_ai_modeltype-1).|
| model_context | Model runtime context, which is specified by [OH_AI_ContextHandle](#oh_ai_contexthandle).|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status-1). The value **MSStatus::kMSStatusSuccess** indicates that the operation is successful.


### OH_AI_ModelBuildFromFile()


```
OH_AI_API OH_AI_Status OH_AI_ModelBuildFromFile (OH_AI_ModelHandle model, const char * model_path, OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context )
```

**Description**

Loads and builds a MindSpore model from a model file.
Note that the same [OH_AI_ContextHandle](#oh_ai_contexthandle) object can only be passed to [OH_AI_ModelBuildFromFile](#oh_ai_modelbuildfromfile) or [OH_AI_ModelBuild](#oh_ai_modelbuild) once. If you call this function multiple times, make sure that you create multiple [OH_AI_ContextHandle](#oh_ai_contexthandle) objects accordingly.

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|
| model_path | Path of the model file.|
| model_type | Model file type, which is specified by [OH_AI_ModelType](#oh_ai_modeltype-1).|
| model_context | Model runtime context, which is specified by [OH_AI_ContextHandle](#oh_ai_contexthandle).|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status-1). The value **MSStatus::kMSStatusSuccess** indicates that the operation is successful.


### OH_AI_ModelCreate()


```
OH_AI_API OH_AI_ModelHandle OH_AI_ModelCreate ()
```

**Description**

Creates a model object.

**Returns**

Pointer to the model object.


### OH_AI_ModelDestroy()


```
OH_AI_API void OH_AI_ModelDestroy (OH_AI_ModelHandle * model)
```

**Description**

Destroys a model object.

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|


### OH_AI_ModelGetInputByTensorName()


```
OH_AI_API OH_AI_TensorHandle OH_AI_ModelGetInputByTensorName (const OH_AI_ModelHandle model, const char * tensor_name )
```

**Description**

Obtains the input tensor of a model by tensor name.

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|
| tensor_name | Tensor name.|

**Returns**

Pointer to the input tensor indicated by **tensor_name**. If the tensor does not exist in the input, **null** will be returned.


### OH_AI_ModelGetInputs()


```
OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetInputs (const OH_AI_ModelHandle model)
```

**Description**

Obtains the input tensor array structure of a model.

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|

**Returns**

Tensor array structure corresponding to the model input.


### OH_AI_ModelGetOutputByTensorName()


```
OH_AI_API OH_AI_TensorHandle OH_AI_ModelGetOutputByTensorName (const OH_AI_ModelHandle model, const char * tensor_name )
```

**Description**

Obtains the output tensor of a model by tensor name.

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|
| tensor_name | Tensor name.|

**Returns**

Pointer to the input tensor indicated by **tensor_name**. If the tensor does not exist, **null** will be returned.


### OH_AI_ModelGetOutputs()


```
OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetOutputs (const OH_AI_ModelHandle model)
```

**Description**

Obtains the output tensor array structure of a model.

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|

**Returns**

Tensor array structure corresponding to the model output.


### OH_AI_ModelPredict()


```
OH_AI_API OH_AI_Status OH_AI_ModelPredict (OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs, OH_AI_TensorHandleArray * outputs, const OH_AI_KernelCallBack before, const OH_AI_KernelCallBack after )
```

**Description**

Performs model inference.

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|
| inputs | Tensor array structure corresponding to the model input.|
| outputs | Pointer to the tensor array structure corresponding to the model output.|
| before | Callback function executed before model inference.|
| after | Callback function executed after model inference.|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status-1). The value **MSStatus::kMSStatusSuccess** indicates that the operation is successful.


### OH_AI_ModelResize()


```
OH_AI_API OH_AI_Status OH_AI_ModelResize (OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs, OH_AI_ShapeInfo * shape_infos, size_t shape_info_num )
```

**Description**

Adjusts the input tensor shapes of a built model.

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|
| inputs | Tensor array structure corresponding to the model input.|
| shape_infos | Input shape information array, which consists of tensor shapes arranged in the model input sequence. The model adjusts the tensor shapes in sequence.|
| shape_info_num | Length of the shape information array.|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status-1). The value **MSStatus::kMSStatusSuccess** indicates that the operation is successful.


### OH_AI_TensorClone()


```
OH_AI_API OH_AI_TensorHandle OH_AI_TensorClone (OH_AI_TensorHandle tensor)
```

**Description**

Clones a tensor.

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Pointer to the tensor to clone.|

**Returns**

Defines the handle of a tensor object.


### OH_AI_TensorCreate()


```
OH_AI_API OH_AI_TensorHandle OH_AI_TensorCreate (const char *name, OH_AI_DataType type, const int64_t * shape, size_t shape_num, const void * data, size_t data_len )
```

**Description**

Creates a tensor object.

**Parameters**

| Name| Description|
| -------- | -------- |
| name | Tensor name.|
| type | Tensor data type.|
| shape | Tensor dimension array.|
| shape_num | Length of the tensor dimension array.|
| data | Data pointer.|
| data_len | Data length.|

**Returns**

Defines the handle of a tensor object.


### OH_AI_TensorDestroy()


```
OH_AI_API void OH_AI_TensorDestroy (OH_AI_TensorHandle * tensor)
```

**Description**

Destroys a tensor object.

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Level-2 pointer to the tensor handle.|


### OH_AI_TensorGetData()


```
OH_AI_API const void* OH_AI_TensorGetData (const OH_AI_TensorHandle tensor)
```

**Description**

Obtains the pointer to tensor data.

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|

**Returns**

Pointer to tensor data.


### OH_AI_TensorGetDataSize()


```
OH_AI_API size_t OH_AI_TensorGetDataSize (const OH_AI_TensorHandle tensor)
```

**Description**

Obtains the number of bytes of the tensor data.

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|

**Returns**

Number of bytes of the tensor data.


### OH_AI_TensorGetDataType()


```
OH_AI_API OH_AI_DataType OH_AI_TensorGetDataType (const OH_AI_TensorHandle tensor)
```

**Description**

Obtains the tensor type.

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|

**Returns**

Tensor data type.


### OH_AI_TensorGetElementNum()


```
OH_AI_API int64_t OH_AI_TensorGetElementNum (const OH_AI_TensorHandle tensor)
```

**Description**

Obtains the number of tensor elements.

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|

**Returns**

Number of tensor elements.


### OH_AI_TensorGetFormat()


```
OH_AI_API OH_AI_Format OH_AI_TensorGetFormat (const OH_AI_TensorHandle tensor)
```

**Description**

Obtains the tensor data format.

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|

**Returns**

Tensor data format.


### OH_AI_TensorGetMutableData()


```
OH_AI_API void* OH_AI_TensorGetMutableData (const OH_AI_TensorHandle tensor)
```

**Description**

Obtains the pointer to variable tensor data. If the data is empty, memory will be allocated.

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|

**Returns**

Pointer to tensor data.


### OH_AI_TensorGetName()


```
OH_AI_API const char* OH_AI_TensorGetName (const OH_AI_TensorHandle tensor)
```

**Description**

Obtains the name of a tensor.

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|

**Returns**

Tensor name.


### OH_AI_TensorGetShape()


```
OH_AI_API const int64_t* OH_AI_TensorGetShape (const OH_AI_TensorHandle tensor, size_t * shape_num )
```

**Description**

Obtains the tensor shape.

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|
| shape_num | Length of the tensor shape array.|

**Returns**

Shape array.


### OH_AI_TensorSetData()


```
OH_AI_API void OH_AI_TensorSetData (OH_AI_TensorHandle tensor, void * data )
```

**Description**

Sets the tensor data.

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|
| data | Data pointer.|


### OH_AI_TensorSetDataType()


```
OH_AI_API void OH_AI_TensorSetDataType (OH_AI_TensorHandle tensor, OH_AI_DataType type )
```

**Description**

Sets the tensor data type.

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|
| type | Data type, which is specified by [OH_AI_DataType](#oh_ai_datatype-1).|


### OH_AI_TensorSetFormat()


```
OH_AI_API void OH_AI_TensorSetFormat (OH_AI_TensorHandle tensor, OH_AI_Format format )
```

**Description**

Sets the tensor data format.

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|
| format | Tensor data format.|


### OH_AI_TensorSetName()


```
OH_AI_API void OH_AI_TensorSetName (OH_AI_TensorHandle tensor, const char *name )
```

**Description**

Sets the tensor name.

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|
| name | Tensor name.|


### OH_AI_TensorSetShape()


```
OH_AI_API void OH_AI_TensorSetShape (OH_AI_TensorHandle tensor, const int64_t * shape, size_t shape_num )
```

**Description**

Sets the tensor shape.

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|
| shape | Shape array.|
| shape_num | Length of the tensor shape array.|
