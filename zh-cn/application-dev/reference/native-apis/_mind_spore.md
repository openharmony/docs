# MindSpore


提供MindSpore Lite的模型推理相关接口。


@Syscap SystemCapability.Ai.MindSpore


**自从：**


9


## 汇总


### 文件

| 文件名称 | 描述 |
| -------- | -------- |
| [context.h](context_8h.md) | 提供了Context相关的接口，可以配置运行时信息。 |
| [data_type.h](data__type_8h.md) | 声明了张量的数据的类型。 |
| [format.h](format_8h.md) | 提供张量数据的排列格式。 |
| [model.h](model_8h.md) | 提供了模型相关接口，可以用于模型创建、模型推理等。 |
| [status.h](status_8h.md) | 提供了Mindspore Lite运行时的状态码。 |
| [tensor.h](tensor_8h.md) | 提供了张量相关的接口，可用于创建和修改张量信息。 |
| [types.h](types_8h.md) | 提供了MindSpore Lite支持的模型文件类型和设备类型。 |


### 结构体

| 结构体名称 | 描述 |
| -------- | -------- |
| [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) | 张量数组结构体，用于存储张量数组指针和张量数组长度。 |
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) | 维度信息，最大的维度为**MS_MAX_SHAPE_NUM**。 |
| [OH_AI_CallBackParam](_o_h___a_i___call_back_param.md) | 回调函数中传入的算子信息。 |


### 宏定义

| 宏定义名称 | 描述 |
| -------- | -------- |
| [OH_AI_MAX_SHAPE_NUM](#oh_ai_max_shape_num)   32 | 维度信息，最大的维度为**MS_MAX_SHAPE_NUM**。 |


### 类型定义

| 类型定义名称 | 描述 |
| -------- | -------- |
| [OH_AI_ContextHandle](#oh_ai_contexthandle) | Mindspore的上下文信息的指针，该指针会指向Context。 |
| [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) | Mindspore的运行设备信息的指针。 |
| [OH_AI_DataType](#oh_ai_datatype) | MSTensor保存的数据支持的类型。 |
| [OH_AI_Format](#oh_ai_format) | MSTensor保存的数据支持的排列格式。 |
| [OH_AI_ModelHandle](#oh_ai_modelhandle) | 指向模型对象的指针。 |
| [OH_AI_TensorHandleArray](#oh_ai_tensorhandlearray) | 张量数组结构体，用于存储张量数组指针和张量数组长度。 |
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) | 维度信息，最大的维度为**MS_MAX_SHAPE_NUM**。 |
| [OH_AI_CallBackParam](#oh_ai_callbackparam) | 回调函数中传入的算子信息。 |
| [OH_AI_KernelCallBack](#oh_ai_kernelcallback)) (const OH_AI_TensorHandleArray inputs, const OH_AI_TensorHandleArray outputs, const OH_AI_CallBackParam kernel_Info) | 回调函数指针。 |
| [OH_AI_Status](#oh_ai_status) | Minspore的状态码。 |
| [OH_AI_TensorHandle](#oh_ai_tensorhandle) | 指向张量对象句柄。 |
| [OH_AI_ModelType](#oh_ai_modeltype) | 模型文件的类型。 |
| [OH_AI_DeviceType](#oh_ai_devicetype) | 设备类型，该信息。 |


### 枚举

| 枚举名称 | 描述 |
| -------- | -------- |
| [OH_AI_DataType](#oh_ai_datatype) {<br/>OH_AI_DATATYPE_UNKNOWN = 0,<br/>OH_AI_DATATYPE_OBJECTTYPE_STRING = 12,<br/>OH_AI_DATATYPE_OBJECTTYPE_LIST = 13, <br/>OH_AI_DATATYPE_OBJECTTYPE_TUPLE = 14, <br/>OH_AI_DATATYPE_OBJECTTYPE_TENSOR = 17, <br/>OH_AI_DATATYPE_NUMBERTYPE_BEGIN = 29,<br/>OH_AI_DATATYPE_NUMBERTYPE_BOOL = 30,<br/>OH_AI_DATATYPE_NUMBERTYPE_INT8 = 32, <br/>OH_AI_DATATYPE_NUMBERTYPE_INT16 = 33, <br/>OH_AI_DATATYPE_NUMBERTYPE_INT32 = 34, <br/>OH_AI_DATATYPE_NUMBERTYPE_INT64 = 35, <br/>OH_AI_DATATYPE_NUMBERTYPE_UINT8 = 37, <br/>OH_AI_DATATYPE_NUMBERTYPE_UINT16 = 38,<br/>OH_AI_DATATYPE_NUMBERTYPE_UINT32 = 39, <br/>OH_AI_DATATYPE_NUMBERTYPE_UINT64 = 40, <br/>OH_AI_DATATYPE_NUMBERTYPE_FLOAT16 = 42, <br/>OH_AI_DATATYPE_NUMBERTYPE_FLOAT32 = 43, <br/>OH_AI_DATATYPE_NUMBERTYPE_FLOAT64 = 44,<br/>OH_AI_DATATYPE_NUMBERTYPE_END = 46,<br/>OH_AI_DataTypeInvalid = INT32_MAX } | MSTensor保存的数据支持的类型。 |
| [OH_AI_Format](#oh_ai_format) {<br/>OH_AI_FORMAT_NCHW = 0,<br/>OH_AI_FORMAT_NHWC = 1,<br/>OH_AI_FORMAT_NHWC4 = 2,<br/>OH_AI_FORMAT_HWKC = 3,<br/>OH_AI_FORMAT_HWCK = 4,<br/>OH_AI_FORMAT_KCHW = 5,<br/>OH_AI_FORMAT_CKHW = 6,<br/>OH_AI_FORMAT_KHWC = 7,<br/>OH_AI_FORMAT_CHWK = 8,<br/>OH_AI_FORMAT_HW = 9,<br/>OH_AI_FORMAT_HW4 = 10,<br/>OH_AI_FORMAT_NC = 11,<br/>OH_AI_FORMAT_NC4 = 12,<br/>OH_AI_FORMAT_NC4HW4 = 13,<br/>OH_AI_FORMAT_NCDHW = 15,<br/>OH_AI_FORMAT_NWC = 16,<br/>OH_AI_FORMAT_NCW = 17 } | MSTensor保存的数据支持的排列格式。 |
| [OH_AI_CompCode](#oh_ai_compcode) {<br/>OH_AI_COMPCODE_CORE = 0x00000000u,<br/>OH_AI_COMPCODE_LITE = 0xF0000000u } | Minspore不同组件的代码、 |
| [OH_AI_Status](#oh_ai_status) {<br/>OH_AI_STATUS_SUCCESS = 0,<br/>OH_AI_STATUS_CORE_FAILED = OH_AI_COMPCODE_CORE \| 0x1, <br/>OH_AI_STATUS_LITE_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -1), <br/>OH_AI_STATUS_LITE_NULLPTR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -2),<br/>OH_AI_STATUS_LITE_PARAM_INVALID = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -3),<br/>OH_AI_STATUS_LITE_NO_CHANGE = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -4),<br/>OH_AI_STATUS_LITE_SUCCESS_EXIT = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -5),<br/>OH_AI_STATUS_LITE_MEMORY_FAILED = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -6),<br/>OH_AI_STATUS_LITE_NOT_SUPPORT = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -7),<br/>OH_AI_STATUS_LITE_THREADPOOL_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -8),<br/>OH_AI_STATUS_LITE_UNINITIALIZED_OBJ = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -9),<br/>OH_AI_STATUS_LITE_OUT_OF_TENSOR_RANGE, <br/>OH_AI_STATUS_LITE_INPUT_TENSOR_ERROR,<br/>OH_AI_STATUS_LITE_REENTRANT_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -102),<br/>OH_AI_STATUS_LITE_GRAPH_FILE_ERROR,<br/>OH_AI_STATUS_LITE_NOT_FIND_OP = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -300),   OH_AI_STATUS_LITE_INVALID_OP_NAME = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -301),<br/>OH_AI_STATUS_LITE_INVALID_OP_ATTR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -302),<br/>OH_AI_STATUS_LITE_OP_EXECUTE_FAILURE,<br/>OH_AI_STATUS_LITE_FORMAT_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -400),<br/>OH_AI_STATUS_LITE_INFER_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -500),<br/>OH_AI_STATUS_LITE_INFER_INVALID = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -501),<br/>OH_AI_STATUS_LITE_INPUT_PARAM_INVALID } | Minspore的状态码。 |
| [OH_AI_ModelType](#oh_ai_modeltype) {<br/>OH_AI_MODELTYPE_MINDIR = 0,<br/>OH_AI_MODELTYPE_INVALID = 0xFFFFFFFF } | 模型文件的类型。 |
| [OH_AI_DeviceType](#oh_ai_devicetype) {<br/>OH_AI_DEVICETYPE_CPU = 0,<br/>OH_AI_DEVICETYPE_KIRIN_NPU,<br/>OH_AI_DEVICETYPE_INVALID = 100 } | 设备类型，该信息。 |


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_AI_ContextCreate](#oh_ai_contextcreate) () | 创建一个上下文的对象。 |
| [OH_AI_ContextDestroy](#oh_ai_contextdestroy) (OH_AI_ContextHandle \*context) | 释放上下文对象。 |
| [OH_AI_ContextSetThreadNum](#oh_ai_contextsetthreadnum) (OH_AI_ContextHandle context, int32_t thread_num) | 设置运行时的线程数量。 |
| [OH_AI_ContextGetThreadNum](#oh_ai_contextgetthreadnum) (const OH_AI_ContextHandle context) | 获取线程数量。 |
| [OH_AI_ContextSetThreadAffinityMode](#oh_ai_contextsetthreadaffinitymode) (OH_AI_ContextHandle context, int mode) | 设置运行时线程绑定CPU核心的策略，按照CPU物理核频率分为大、中、小三种类型的核心，并且仅需绑大核或者绑中核，不需要绑小核。 |
| [OH_AI_ContextGetThreadAffinityMode](#oh_ai_contextgetthreadaffinitymode) (const OH_AI_ContextHandle context) | 获取运行时线程绑定CPU核心的策略。 |
| [OH_AI_ContextSetThreadAffinityCoreList](#oh_ai_contextsetthreadaffinitycorelist) (OH_AI_ContextHandle context, const int32_t \*core_list, <br/>size_t core_num) | 设置运行时线程绑定CPU核心的列表。 |
| [OH_AI_ContextGetThreadAffinityCoreList](#oh_ai_contextgetthreadaffinitycorelist) (const OH_AI_ContextHandle context, size_t \*core_num) | 获取CPU绑核列表。 |
| [OH_AI_ContextSetEnableParallel](#oh_ai_contextsetenableparallel) (OH_AI_ContextHandle context, bool is_parallel) | 设置运行时是否支持并行。 |
| [OH_AI_ContextGetEnableParallel](#oh_ai_contextgetenableparallel) (const OH_AI_ContextHandle context) | 获取是否支持算子间并行。 |
| [OH_AI_ContextAddDeviceInfo](#oh_ai_contextadddeviceinfo) (OH_AI_ContextHandle context, OH_AI_DeviceInfoHandle device_info) | 添加运行设备信息。 |
| [OH_AI_DeviceInfoCreate](#oh_ai_deviceinfocreate) (OH_AI_DeviceType device_type) | 创建一个设备信息对象。 |
| [OH_AI_DeviceInfoDestroy](#oh_ai_deviceinfodestroy) (OH_AI_DeviceInfoHandle \*device_info) | 释放设备信息实例。 |
| [OH_AI_DeviceInfoSetProvider](#oh_ai_deviceinfosetprovider) (OH_AI_DeviceInfoHandle device_info, const char \*provider) | 设置供应商的名称。 |
| [OH_AI_DeviceInfoGetProvider](#oh_ai_deviceinfogetprovider) (const OH_AI_DeviceInfoHandle device_info) | 获取生产商的名称。 |
| [OH_AI_DeviceInfoSetProviderDevice](#oh_ai_deviceinfosetproviderdevice) (OH_AI_DeviceInfoHandle device_info, const char \*device) | 设置生产商设备的名称。 |
| [OH_AI_DeviceInfoGetProviderDevice](#oh_ai_deviceinfogetproviderdevice) (const OH_AI_DeviceInfoHandle device_info) | 获取生产商设备的名称。 |
| [OH_AI_DeviceInfoGetDeviceType](#oh_ai_deviceinfogetdevicetype) (const OH_AI_DeviceInfoHandle device_info) | 获取设备的类型。 |
| [OH_AI_DeviceInfoSetEnableFP16](#oh_ai_deviceinfosetenablefp16) (OH_AI_DeviceInfoHandle device_info, bool is_fp16) | 设置是否开启float16推理模式，仅CPU/GPU设备可用。 |
| [OH_AI_DeviceInfoGetEnableFP16](#oh_ai_deviceinfogetenablefp16) (const OH_AI_DeviceInfoHandle device_info) | 获取是否开启float16推理模式, 仅CPU/GPU设备可用。 |
| [OH_AI_DeviceInfoSetFrequency](#oh_ai_deviceinfosetfrequency) (OH_AI_DeviceInfoHandle device_info, int frequency) | 设置NPU的频率，仅NPU设备可用。 |
| [OH_AI_DeviceInfoGetFrequency](#oh_ai_deviceinfogetfrequency) (const OH_AI_DeviceInfoHandle device_info) | 获取NPU的频率类型，仅NPU设备可用。 |
| [OH_AI_ModelCreate](#oh_ai_modelcreate) () | 创建一个模型对象。 |
| [OH_AI_ModelDestroy](#oh_ai_modeldestroy) (OH_AI_ModelHandle \*model) | 释放一个模型对象。 |
| [OH_AI_ModelBuild](#oh_ai_modelbuild) (OH_AI_ModelHandle model, const void \*model_data, size_t data_size, OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context) | 从内存缓冲区加载并编译MindSpore模型。 |
| [OH_AI_ModelBuildFromFile](#oh_ai_modelbuildfromfile) (OH_AI_ModelHandle model, const char \*model_path, <br/>OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context) | 通过模型文件加载并编译MindSpore模型。 |
| [OH_AI_ModelResize](#oh_ai_modelresize) (OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs, OH_AI_ShapeInfo \*shape_infos, size_t shape_info_num) | 调整已编译模型的输入形状。 |
| [OH_AI_ModelPredict](#oh_ai_modelpredict) (OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs, OH_AI_TensorHandleArray \*outputs, const OH_AI_KernelCallBack before, <br/>const OH_AI_KernelCallBack after) | 执行模型推理。 |
| [OH_AI_ModelGetInputs](#oh_ai_modelgetinputs) (const OH_AI_ModelHandle model) | 获取模型的输入张量数组结构体。 |
| [OH_AI_ModelGetOutputs](#oh_ai_modelgetoutputs) (const OH_AI_ModelHandle model) | 获取模型的输出张量数组结构体。 |
| [OH_AI_ModelGetInputByTensorName](#oh_ai_modelgetinputbytensorname) (const OH_AI_ModelHandle model, const char \*tensor_name) | 通过张量名获取模型的输入张量。 |
| [OH_AI_ModelGetOutputByTensorName](#oh_ai_modelgetoutputbytensorname) (const OH_AI_ModelHandle model, const char \*tensor_name) | 通过张量名获取模型的输出张量。 |
| [OH_AI_TensorCreate](#oh_ai_tensorcreate) (const char \*name, OH_AI_DataType type, const int64_t \*shape, <br/>size_t shape_num, const void \*data, size_t data_len) | 创建一个张量对象。 |
| [OH_AI_TensorDestroy](#oh_ai_tensordestroy) (OH_AI_TensorHandle \*tensor) | 释放张量对象。 |
| [OH_AI_TensorClone](#oh_ai_tensorclone) (OH_AI_TensorHandle tensor) | 深拷贝一个张量。 |
| [OH_AI_TensorSetName](#oh_ai_tensorsetname) (OH_AI_TensorHandle tensor, const char \*name) | 设置张量的名称。 |
| [OH_AI_TensorGetName](#oh_ai_tensorgetname) (const OH_AI_TensorHandle tensor) | 获取张量的名称。 |
| [OH_AI_TensorSetDataType](#oh_ai_tensorsetdatatype) (OH_AI_TensorHandle tensor, OH_AI_DataType type) | 设置张量的数据类型。 |
| [OH_AI_TensorGetDataType](#oh_ai_tensorgetdatatype) (const OH_AI_TensorHandle tensor) | 获取张量类型。 |
| [OH_AI_TensorSetShape](#oh_ai_tensorsetshape) (OH_AI_TensorHandle tensor, const int64_t \*shape, size_t shape_num) | 设置张量的形状。 |
| [OH_AI_TensorGetShape](#oh_ai_tensorgetshape) (const OH_AI_TensorHandle tensor, size_t \*shape_num) | 获取张量的形状。 |
| [OH_AI_TensorSetFormat](#oh_ai_tensorsetformat) (OH_AI_TensorHandle tensor, OH_AI_Format format) | 设置张量数据的排列方式。 |
| [OH_AI_TensorGetFormat](#oh_ai_tensorgetformat) (const OH_AI_TensorHandle tensor) | 获取张量数据的排列方式。 |
| [OH_AI_TensorSetData](#oh_ai_tensorsetdata) (OH_AI_TensorHandle tensor, void \*data) | 设置张量的数据。 |
| [OH_AI_TensorGetData](#oh_ai_tensorgetdata) (const OH_AI_TensorHandle tensor) | 获取张量数据的指针。 |
| [OH_AI_TensorGetMutableData](#oh_ai_tensorgetmutabledata) (const OH_AI_TensorHandle tensor) | 获取可变的张量数据指针。如果数据为空则会开辟内存。 |
| [OH_AI_TensorGetElementNum](#oh_ai_tensorgetelementnum) (const OH_AI_TensorHandle tensor) | 获取张量元素数量。 |
| [OH_AI_TensorGetDataSize](#oh_ai_tensorgetdatasize) (const OH_AI_TensorHandle tensor) | 获取张量中的数据的字节数大小。 |


## **宏定义说明**


### OH_AI_MAX_SHAPE_NUM


```
#define OH_AI_MAX_SHAPE_NUM   32
```

**描述：**

维度信息，最大的维度为**MS_MAX_SHAPE_NUM**。


## **类型定义说明**


### OH_AI_CallBackParam


```
typedef struct OH_AI_CallBackParam OH_AI_CallBackParam
```

**描述：**

回调函数中传入的算子信息。


### OH_AI_ContextHandle


```
typedef void* OH_AI_ContextHandle
```

**描述：**

Mindspore的上下文信息的指针，该指针会指向Context。


### OH_AI_DataType


```
typedef enum OH_AI_DataType OH_AI_DataType
```

**描述：**

MSTensor保存的数据支持的类型。


### OH_AI_DeviceInfoHandle


```
typedef void* OH_AI_DeviceInfoHandle
```

**描述：**

Mindspore的运行设备信息的指针。


### OH_AI_DeviceType


```
typedef enum OH_AI_DeviceType OH_AI_DeviceType
```

**描述：**

设备类型信息，包含了目前支持的设备类型。


### OH_AI_Format


```
typedef enum OH_AI_Format OH_AI_Format
```

**描述：**

MSTensor保存的数据支持的排列格式。


### OH_AI_KernelCallBack


```
typedef bool(* OH_AI_KernelCallBack) (const OH_AI_TensorHandleArray inputs, const OH_AI_TensorHandleArray outputs, const OH_AI_CallBackParam kernel_Info)
```

**描述：**

回调函数指针。

该函数指针是用于设置[OH_AI_ModelPredict](#oh_ai_modelpredict)函数参数中的两个回调函数。 该指针指向的函数需要包含三个参数，其中inputs和outputs对应了算子的输入和输出张量，kernel_Info表示当前算子的信息。 可以通过回调函数监控算子执行的情况，例如统计算子的执行时间，校验算子的正确性等等。


### OH_AI_ModelHandle


```
typedef void* OH_AI_ModelHandle
```

**描述：**

指向模型对象的指针。


### OH_AI_ModelType


```
typedef enum OH_AI_ModelType OH_AI_ModelType
```

**描述：**

模型文件的类型


### OH_AI_Status


```
typedef enum OH_AI_Status OH_AI_Status
```

**描述：**

Minspore的状态码。


### OH_AI_TensorHandle


```
typedef void* OH_AI_TensorHandle
```

**描述：**

指向张量对象句柄。


### OH_AI_TensorHandleArray


```
typedef struct OH_AI_TensorHandleArray OH_AI_TensorHandleArray
```

**描述：**

张量数组结构体，用于存储张量数组指针和张量数组长度。


## **枚举类型说明**


### OH_AI_CompCode


```
enum OH_AI_CompCode
```

**描述：**

Minspore不同组件的代码。

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AI_COMPCODE_CORE | Minspore Core的代码。 |
| OH_AI_COMPCODE_LITE | Minspore Lite的代码。 |


### OH_AI_DataType


```
enum OH_AI_DataType
```

**描述：**

MSTensor保存的数据支持的类型。

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AI_DATATYPE_UNKNOWN | 未知的数据类型。 |
| OH_AI_DATATYPE_OBJECTTYPE_STRING | String数据类型。 |
| OH_AI_DATATYPE_OBJECTTYPE_LIST | List数据类型。 |
| OH_AI_DATATYPE_OBJECTTYPE_TUPLE | Tuple数据类型。 |
| OH_AI_DATATYPE_OBJECTTYPE_TENSOR | TensorList数据类型。 |
| OH_AI_DATATYPE_NUMBERTYPE_BEGIN | Number类型的起始。 |
| OH_AI_DATATYPE_NUMBERTYPE_BOOL | Bool数据类型。 |
| OH_AI_DATATYPE_NUMBERTYPE_INT8 | Int8数据类型。 |
| OH_AI_DATATYPE_NUMBERTYPE_INT16 | 表示Int16数据类型。 |
| OH_AI_DATATYPE_NUMBERTYPE_INT32 | 表示Int32数据类型。 |
| OH_AI_DATATYPE_NUMBERTYPE_INT64 | 表示Int64数据类型。 |
| OH_AI_DATATYPE_NUMBERTYPE_UINT8 | 表示UInt8数据类型。 |
| OH_AI_DATATYPE_NUMBERTYPE_UINT16 | 表示UInt16数据类型。 |
| OH_AI_DATATYPE_NUMBERTYPE_UINT32 | 表示UInt32数据类型。 |
| OH_AI_DATATYPE_NUMBERTYPE_UINT64 | 表示UInt64数据类型。 |
| OH_AI_DATATYPE_NUMBERTYPE_FLOAT16 | 表示Float16数据类型。 |
| OH_AI_DATATYPE_NUMBERTYPE_FLOAT32 | 表示Float32数据类型。 |
| OH_AI_DATATYPE_NUMBERTYPE_FLOAT64 | 表示Float64数据类型。 |
| OH_AI_DATATYPE_NUMBERTYPE_END | 表示Number类型的结尾。 |
| OH_AI_DataTypeInvalid | 表示无效的数据类型。 |


### OH_AI_DeviceType


```
enum OH_AI_DeviceType
```

**描述：**

设备类型信息，包含了目前支持的设备类型。

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AI_DEVICETYPE_CPU | 设备类型是CPU。 |
| OH_AI_DEVICETYPE_KIRIN_NPU | 设备类型是麒麟NPU。 |
| OH_AI_DEVICETYPE_INVALID | 设备类型无效。 |


### OH_AI_Format


```
enum OH_AI_Format
```

**描述：**

MSTensor保存的数据支持的排列格式。

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AI_FORMAT_NCHW | 表示NCHW排列。 |
| OH_AI_FORMAT_NHWC | 表示NHWC排列。 |
| OH_AI_FORMAT_NHWC4 | 表示NHWC4排列。 |
| OH_AI_FORMAT_HWKC | 表示HWKC排列。 |
| OH_AI_FORMAT_HWCK | 表示HWCK排列。 |
| OH_AI_FORMAT_KCHW | 表示KCHW排列。 |
| OH_AI_FORMAT_CKHW | 表示CKHW排列。 |
| OH_AI_FORMAT_KHWC | 表示KHWC排列。 |
| OH_AI_FORMAT_CHWK | 表示CHWK排列。 |
| OH_AI_FORMAT_HW | 表示HW排列。 |
| OH_AI_FORMAT_HW4 | 表示HW4排列。 |
| OH_AI_FORMAT_NC | 表示NC排列。 |
| OH_AI_FORMAT_NC4 | 表示NC4排列。 |
| OH_AI_FORMAT_NC4HW4 | 表示NC4HW4排列。 |
| OH_AI_FORMAT_NCDHW | 表示NCDHW排列。 |
| OH_AI_FORMAT_NWC | 表示NWC排列。 |
| OH_AI_FORMAT_NCW | 表示NCW排列。 |


### OH_AI_ModelType


```
enum OH_AI_ModelType
```

**描述：**

模型文件的类型。

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AI_MODELTYPE_MINDIR | 模型类型是MindIR。 |
| OH_AI_MODELTYPE_INVALID | 模型类型无效。 |


### OH_AI_Status


```
enum OH_AI_Status
```

**描述：**

Minspore的状态码。

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AI_STATUS_SUCCESS | 通用的成功状态码。 |
| OH_AI_STATUS_CORE_FAILED | Mindspore Core 失败状态码。 |
| OH_AI_STATUS_LITE_ERROR | Mindspore Lite 异常状态码。 |
| OH_AI_STATUS_LITE_NULLPTR | Mindspore Lite 空指针状态码。 |
| OH_AI_STATUS_LITE_PARAM_INVALID | Mindspore Lite 参数异常状态码。 |
| OH_AI_STATUS_LITE_NO_CHANGE | Mindspore Lite 未改变状态码。 |
| OH_AI_STATUS_LITE_SUCCESS_EXIT | Mindspore Lite 没有错误但是退出的状态码。 |
| OH_AI_STATUS_LITE_MEMORY_FAILED | Mindspore Lite 内存分配失败的状态码。 |
| OH_AI_STATUS_LITE_NOT_SUPPORT | Mindspore Lite 功能未支持的状态码。 |
| OH_AI_STATUS_LITE_THREADPOOL_ERROR | Mindspore Lite 线程池异常状态码。 |
| OH_AI_STATUS_LITE_UNINITIALIZED_OBJ | Mindspore Lite 未初始化状态码。 |
| OH_AI_STATUS_LITE_OUT_OF_TENSOR_RANGE | Mindspore Lite 张量溢出错误的状态码。 |
| OH_AI_STATUS_LITE_INPUT_TENSOR_ERROR | Mindspore Lite 输入张量异常的状态码。 |
| OH_AI_STATUS_LITE_REENTRANT_ERROR | Mindspore Lite 重入异常的状态码。 |
| OH_AI_STATUS_LITE_GRAPH_FILE_ERROR | Mindspore Lite 文件异常状态码。 |
| OH_AI_STATUS_LITE_NOT_FIND_OP | Mindspore Lite 未找到算子的状态码。 |
| OH_AI_STATUS_LITE_INVALID_OP_NAME | Mindspore Lite 无效算子状态码。 |
| OH_AI_STATUS_LITE_INVALID_OP_ATTR | Mindspore Lite 无效算子超参数状态码。 |
| OH_AI_STATUS_LITE_OP_EXECUTE_FAILURE | Mindspore Lite 算子执行失败的状态码。 |
| OH_AI_STATUS_LITE_FORMAT_ERROR | Mindspore Lite 张量格式异常状态码。 |
| OH_AI_STATUS_LITE_INFER_ERROR | Mindspore Lite 形状推理异常状态码。 |
| OH_AI_STATUS_LITE_INFER_INVALID | Mindspore Lite 无效的形状推理的状态码。 |
| OH_AI_STATUS_LITE_INPUT_PARAM_INVALID | Mindspore Lite 用户输入的参数无效状态码。 |


## **函数说明**


### OH_AI_ContextAddDeviceInfo()


```
OH_AI_API void OH_AI_ContextAddDeviceInfo (OH_AI_ContextHandle context, OH_AI_DeviceInfoHandle device_info )
```

**描述：**

添加运行设备信息。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向上下文信息实例的[OH_AI_ContextHandle](#oh_ai_contexthandle)。 |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |


### OH_AI_ContextCreate()


```
OH_AI_API OH_AI_ContextHandle OH_AI_ContextCreate ()
```

**描述：**

创建一个上下文的对象。

**返回:**

指向上下文信息的[OH_AI_ContextHandle](#oh_ai_contexthandle)。


### OH_AI_ContextDestroy()


```
OH_AI_API void OH_AI_ContextDestroy (OH_AI_ContextHandle * context)
```

**描述：**

释放上下文对象。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向[OH_AI_ContextHandle](#oh_ai_contexthandle)的二级指针，上下文销毁后会对context置为空指针。 |


### OH_AI_ContextGetEnableParallel()


```
OH_AI_API bool OH_AI_ContextGetEnableParallel (const OH_AI_ContextHandle context)
```

**描述：**

获取是否支持算子间并行。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向上下文信息实例的[OH_AI_ContextHandle](#oh_ai_contexthandle)。 |

**返回:**

是否支持并行。true 为支持并行, false 为不支持并行。


### OH_AI_ContextGetThreadAffinityCoreList()


```
OH_AI_API const int32_t* OH_AI_ContextGetThreadAffinityCoreList (const OH_AI_ContextHandle context, size_t * core_num )
```

**描述：**

获取CPU绑核列表。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向上下文信息实例的[OH_AI_ContextHandle](#oh_ai_contexthandle)。 |
| core_num | 该参数是输出参数，表示核的数量。 |

**返回:**

CPU绑核列表。


### OH_AI_ContextGetThreadAffinityMode()


```
OH_AI_API int OH_AI_ContextGetThreadAffinityMode (const OH_AI_ContextHandle context)
```

**描述：**

获取运行时线程绑定CPU核心的策略。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向上下文信息实例的[OH_AI_ContextHandle](#oh_ai_contexthandle)。 |

**返回:**

绑核策略。一共有三种策略，0为不绑核, 1为大核优先, 2为小核优先。


### OH_AI_ContextGetThreadNum()


```
OH_AI_API int32_t OH_AI_ContextGetThreadNum (const OH_AI_ContextHandle context)
```

**描述：**

获取线程数量。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向上下文信息实例的[OH_AI_ContextHandle](#oh_ai_contexthandle)。 |

**返回:**

当前的线程数量。


### OH_AI_ContextSetEnableParallel()


```
OH_AI_API void OH_AI_ContextSetEnableParallel (OH_AI_ContextHandle context, bool is_parallel )
```

**描述：**

设置运行时是否支持并行。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向上下文信息实例的[OH_AI_ContextHandle](#oh_ai_contexthandle)。 |
| is_parallel | 是否支持并行。true 为支持并行, false 为不支持并行。 |


### OH_AI_ContextSetThreadAffinityCoreList()


```
OH_AI_API void OH_AI_ContextSetThreadAffinityCoreList (OH_AI_ContextHandle context, const int32_t * core_list, size_t core_num )
```

**描述：**

设置运行时线程绑定CPU核心的列表。

例如：当core_list=[2,6,8]时，则线程会在CPU的第2,6,8个核心上运行。 如果对于同一个上下文对象，调用了[OH_AI_ContextSetThreadAffinityMode](#oh_ai_contextsetthreadaffinitymode)和[OH_AI_ContextSetThreadAffinityCoreList](#oh_ai_contextsetthreadaffinitycorelist) 这两个函数，则仅[OH_AI_ContextSetThreadAffinityCoreList](#oh_ai_contextsetthreadaffinitycorelist)的core_list参数生效，而[OH_AI_ContextSetThreadAffinityMode](#oh_ai_contextsetthreadaffinitymode)的 mode参数不生效。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向上下文信息实例的[OH_AI_ContextHandle](#oh_ai_contexthandle)。 |
| core_list | CPU绑核的列表。 |
| core_num | 核的数量，它就代表**core_list**的长度。 |


### OH_AI_ContextSetThreadAffinityMode()


```
OH_AI_API void OH_AI_ContextSetThreadAffinityMode (OH_AI_ContextHandle context, int mode )
```

**描述：**

设置运行时线程绑定CPU核心的策略，按照CPU物理核频率分为大、中、小三种类型的核心，并且仅需绑大核或者绑中核，不需要绑小核。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向上下文信息实例的[OH_AI_ContextHandle](#oh_ai_contexthandle)。 |
| mode | 绑核策略。一共有三种策略，0为不绑核, 1为大核优先, 2为中核优先。 |


### OH_AI_ContextSetThreadNum()


```
OH_AI_API void OH_AI_ContextSetThreadNum (OH_AI_ContextHandle context, int32_t thread_num )
```

**描述：**

设置运行时的线程数量。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向上下文信息实例的[OH_AI_ContextHandle](#oh_ai_contexthandle) |
| thread_num | 运行时的线程数量。 |


### OH_AI_DeviceInfoCreate()


```
OH_AI_API OH_AI_DeviceInfoHandle OH_AI_DeviceInfoCreate (OH_AI_DeviceType device_type)
```

**描述：**

创建一个设备信息对象。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_type | 设备类型, 具体见[OH_AI_DeviceType](#oh_ai_devicetype)。 |

**返回:**

指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。


### OH_AI_DeviceInfoDestroy()


```
OH_AI_API void OH_AI_DeviceInfoDestroy (OH_AI_DeviceInfoHandle * device_info)
```

**描述：**

释放设备信息实例。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |


### OH_AI_DeviceInfoGetDeviceType()


```
OH_AI_API OH_AI_DeviceType OH_AI_DeviceInfoGetDeviceType (const OH_AI_DeviceInfoHandle device_info)
```

**描述：**

获取设备的类型。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |

**返回:**

生产商设备类型。


### OH_AI_DeviceInfoGetEnableFP16()


```
OH_AI_API bool OH_AI_DeviceInfoGetEnableFP16 (const OH_AI_DeviceInfoHandle device_info)
```

**描述：**

获取是否开启float16推理模式, 仅CPU/GPU设备可用。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |

**返回:**

设置是否开启float16推理模式。


### OH_AI_DeviceInfoGetFrequency()


```
OH_AI_API int OH_AI_DeviceInfoGetFrequency (const OH_AI_DeviceInfoHandle device_info)
```

**描述：**

获取NPU的频率类型，仅NPU设备可用。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |

**返回:**

NPU的频率类型。取值范围为0-4，1表示低功耗，2表示平衡，3表示高性能，4表示超高性能。


### OH_AI_DeviceInfoGetProvider()


```
OH_AI_API const char* OH_AI_DeviceInfoGetProvider (const OH_AI_DeviceInfoHandle device_info)
```

**描述：**

获取生产商的名称。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |

**返回:**

生产商的名称。


### OH_AI_DeviceInfoGetProviderDevice()


```
OH_AI_API const char* OH_AI_DeviceInfoGetProviderDevice (const OH_AI_DeviceInfoHandle device_info)
```

**描述：**

获取生产商设备的名称。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |

**返回:**

生产商设备的名称。


### OH_AI_DeviceInfoSetEnableFP16()


```
OH_AI_API void OH_AI_DeviceInfoSetEnableFP16 (OH_AI_DeviceInfoHandle device_info, bool is_fp16 )
```

**描述：**

设置是否开启float16推理模式，仅CPU/GPU设备可用。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |
| is_fp16 | 是否开启float16推理模式。 |


### OH_AI_DeviceInfoSetFrequency()


```
OH_AI_API void OH_AI_DeviceInfoSetFrequency (OH_AI_DeviceInfoHandle device_info, int frequency )
```

**描述：**

设置NPU的频率，仅NPU设备可用。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |
| frequency | 频率类型，取值范围为0-4，默认是3。1表示低功耗，2表示平衡，3表示高性能，4表示超高性能。 |


### OH_AI_DeviceInfoSetProvider()


```
OH_AI_API void OH_AI_DeviceInfoSetProvider (OH_AI_DeviceInfoHandle device_info, const char * provider )
```

**描述：**

设置供应商的名称。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |
| provider | 供应商的名称。 |


### OH_AI_DeviceInfoSetProviderDevice()


```
OH_AI_API void OH_AI_DeviceInfoSetProviderDevice (OH_AI_DeviceInfoHandle device_info, const char * device )
```

**描述：**

设置生产商设备的名称。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |
| device | 生产商设备名称。 例如: CPU。 |


### OH_AI_ModelBuild()


```
OH_AI_API OH_AI_Status OH_AI_ModelBuild (OH_AI_ModelHandle model, const void * model_data, size_t data_size, OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context )
```

**描述：**

从内存缓冲区加载并编译MindSpore模型。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| model_data | 内存中已经加载的模型数据地址。 |
| data_size | 模型数据的长度。 |
| model_type | 模型文件类型，具体见[OH_AI_ModelType](#oh_ai_modeltype)。 |
| model_context | 模型运行时的上下文环境，具体见 [OH_AI_ContextHandle](#oh_ai_contexthandle)。 |

**返回:**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回MSStatus::kMSStatusSuccess则证明创建成功。


### OH_AI_ModelBuildFromFile()


```
OH_AI_API OH_AI_Status OH_AI_ModelBuildFromFile (OH_AI_ModelHandle model, const char * model_path, OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context )
```

**描述：**

通过模型文件加载并编译MindSpore模型。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| model_path | 模型文件路径。 |
| model_type | 模型文件类型，具体见[OH_AI_ModelType](#oh_ai_modeltype)。 |
| model_context | 模型运行时的上下文环境，具体见 [OH_AI_ContextHandle](#oh_ai_contexthandle)。 |

**返回:**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回MSStatus::kMSStatusSuccess则证明创建成功。


### OH_AI_ModelCreate()


```
OH_AI_API OH_AI_ModelHandle OH_AI_ModelCreate ()
```

**描述：**

创建一个模型对象。

**返回:**

模型对象指针。


### OH_AI_ModelDestroy()


```
OH_AI_API void OH_AI_ModelDestroy (OH_AI_ModelHandle * model)
```

**描述：**

释放一个模型对象。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |


### OH_AI_ModelGetInputByTensorName()


```
OH_AI_API OH_AI_TensorHandle OH_AI_ModelGetInputByTensorName (const OH_AI_ModelHandle model, const char * tensor_name )
```

**描述：**

通过张量名获取模型的输入张量。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| tensor_name | 张量名称。 |

**返回:**

tensor_name所对应的输入张量的张量指针，如果输入中没有该张量则返回空。


### OH_AI_ModelGetInputs()


```
OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetInputs (const OH_AI_ModelHandle model)
```

**描述：**

获取模型的输入张量数组结构体。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |

**返回:**

模型输入对应的张量数组结构体。


### OH_AI_ModelGetOutputByTensorName()


```
OH_AI_API OH_AI_TensorHandle OH_AI_ModelGetOutputByTensorName (const OH_AI_ModelHandle model, const char * tensor_name )
```

**描述：**

通过张量名获取模型的输出张量。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| tensor_名称 | 张量名称。 |

**返回:**

tensor_name所对应的输入张量的张量指针，如果输出中没有该张量则返回空。


### OH_AI_ModelGetOutputs()


```
OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetOutputs (const OH_AI_ModelHandle model)
```

**描述：**

获取模型的输出张量数组结构体。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |

**返回:**

模型输出对应的张量数组结构体。


### OH_AI_ModelPredict()


```
OH_AI_API OH_AI_Status OH_AI_ModelPredict (OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs, OH_AI_TensorHandleArray * outputs, const OH_AI_KernelCallBack before, const OH_AI_KernelCallBack after )
```

**描述：**

执行模型推理。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| inputs | 模型输入对应的张量数组结构体。 |
| outputs | 模型输出对应的张量数组结构体的指针。 |
| before | 模型推理前执行的回调函数。 |
| after | 模型推理后执行的回调函数。 |

**返回:**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回MSStatus::kMSStatusSuccess则证明创建成功。


### OH_AI_ModelResize()


```
OH_AI_API OH_AI_Status OH_AI_ModelResize (OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs, OH_AI_ShapeInfo * shape_infos, size_t shape_info_num )
```

**描述：**

调整已编译模型的输入形状。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| inputs | 模型输入对应的张量数组结构体。 |
| shape_infos | 输入形状信息数组，按模型输入顺序排列的由形状信息组成的数组，模型会按顺序依次调整张量形状。 |
| shape_info_num | 形状信息数组的长度。 |

**返回:**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回MSStatus::kMSStatusSuccess则证明创建成功。


### OH_AI_TensorClone()


```
OH_AI_API OH_AI_TensorHandle OH_AI_TensorClone (OH_AI_TensorHandle tensor)
```

**描述：**

深拷贝一个张量。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 待拷贝张量的指针。 |

**返回:**

指向新张量对象句柄。


### OH_AI_TensorCreate()


```
OH_AI_API OH_AI_TensorHandle OH_AI_TensorCreate (const char *name, OH_AI_DataType type, const int64_t * shape, size_t shape_num, const void * data, size_t data_len )
```

**描述：**

创建一个张量对象。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| 名称 | 张量名称 |
| type | 张量的数据类型 |
| shape | 张量的维度数组。 |
| shape_num | 张量维度数组长度。 |
| data | 指向数据的指针。 |
| data_len | 数据的长度。 |

**返回:**

指向张量对象句柄。


### OH_AI_TensorDestroy()


```
OH_AI_API void OH_AI_TensorDestroy (OH_AI_TensorHandle * tensor)
```

**描述：**

释放张量对象。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 指向张量句柄的二级指针。 |


### OH_AI_TensorGetData()


```
OH_AI_API const void* OH_AI_TensorGetData (const OH_AI_TensorHandle tensor)
```

**描述：**

获取张量数据的指针。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |

**返回:**

张量数据的指针。


### OH_AI_TensorGetDataSize()


```
OH_AI_API size_t OH_AI_TensorGetDataSize (const OH_AI_TensorHandle tensor)
```

**描述：**

获取张量中的数据的字节数大小。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |

**返回:**

张量数据的字节数大小。


### OH_AI_TensorGetDataType()


```
OH_AI_API OH_AI_DataType OH_AI_TensorGetDataType (const OH_AI_TensorHandle tensor)
```

**描述：**

获取张量类型。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |

**返回:**

张量的数据类型。


### OH_AI_TensorGetElementNum()


```
OH_AI_API int64_t OH_AI_TensorGetElementNum (const OH_AI_TensorHandle tensor)
```

**描述：**

获取张量元素数量。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |

**返回:**

张量的元素数量。


### OH_AI_TensorGetFormat()


```
OH_AI_API OH_AI_Format OH_AI_TensorGetFormat (const OH_AI_TensorHandle tensor)
```

**描述：**

获取张量数据的排列方式。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |

**返回:**

张量数据的排列方式。


### OH_AI_TensorGetMutableData()


```
OH_AI_API void* OH_AI_TensorGetMutableData (const OH_AI_TensorHandle tensor)
```

**描述：**

获取可变的张量数据指针。如果数据为空则会开辟内存。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |

**返回:**

张量数据的指针。


### OH_AI_TensorGetName()


```
OH_AI_API const char* OH_AI_TensorGetName (const OH_AI_TensorHandle tensor)
```

**描述：**

获取张量的名称。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |

**返回:**

张量的名称。


### OH_AI_TensorGetShape()


```
OH_AI_API const int64_t* OH_AI_TensorGetShape (const OH_AI_TensorHandle tensor, size_t * shape_num )
```

**描述：**

获取张量的形状。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |
| shape_num | 该参数是输出参数，形状数组的长度会写入该变量。 |

**返回:**

形状数组。


### OH_AI_TensorSetData()


```
OH_AI_API void OH_AI_TensorSetData (OH_AI_TensorHandle tensor, void * data )
```

**描述：**

设置张量的数据。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |
| data | 指向数据的指针。 |


### OH_AI_TensorSetDataType()


```
OH_AI_API void OH_AI_TensorSetDataType (OH_AI_TensorHandle tensor, OH_AI_DataType type )
```

**描述：**

设置张量的数据类型。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |
| type | 数据类型，具体见[OH_AI_DataType](#oh_ai_datatype)。 |


### OH_AI_TensorSetFormat()


```
OH_AI_API void OH_AI_TensorSetFormat (OH_AI_TensorHandle tensor, OH_AI_Format format )
```

**描述：**

设置张量数据的排列方式。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |
| format | 张量数据排列方式。 |


### OH_AI_TensorSetName()


```
OH_AI_API void OH_AI_TensorSetName (OH_AI_TensorHandle tensor, const char *name )
```

**描述：**

设置张量的名称。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |
| 名称 | 张量名称。 |


### OH_AI_TensorSetShape()


```
OH_AI_API void OH_AI_TensorSetShape (OH_AI_TensorHandle tensor, const int64_t * shape, size_t shape_num )
```

**描述：**

设置张量的形状。

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |
| shape | 形状数组。 |
| shape_num | 张量形状数组长度。 |
