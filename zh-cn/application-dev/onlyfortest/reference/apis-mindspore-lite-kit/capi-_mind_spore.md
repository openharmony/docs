# MindSpore


## 概述

提供MindSpore Lite的模型推理相关接口，该模块下的接口是非线程安全的。

**起始版本：** 9

## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [egl.h](capi-context_8h.md) | 提供了Context相关的接口，可以配置运行时信息。<br/>引用文件：&lt;mindspore/context.h&gt;<br/>库：libmindspore_lite_ndk.so |
| [oh_fileio.h](capi-data__type_8h.md) | 声明了张量的数据的类型。<br/>引用文件：&lt;mindspore/data_type.h&gt;<br/>库：libmindspore_lite_ndk.so |
| [uscript.h](capi-format_8h.md) | 提供张量数据的排列格式。<br/>引用文件：&lt;mindspore/format.h&gt;<br/>库：libmindspore_lite_ndk.so |
| [resmgr_common.h](capi-model_8h.md)| 提供了模型相关接口，可以用于模型创建、模型推理等。<br/>引用文件：&lt;mindspore/model.h&gt;<br/>库：libmindspore_lite_ndk.so |
| [oh_fileio.h](capi-status_8h.md) | 提供了MindSpore Lite运行时的状态码。<br/>引用文件：&lt;mindspore/status.h&gt;<br/>库：libmindspore_lite_ndk.so |
| [ohprint.h](capi-tensor_8h.md) | 提供了张量相关的接口，可用于创建和修改张量信息。<br/>引用文件：&lt;mindspore/tensor.h&gt;<br/>库：libmindspore_lite_ndk.so |
| [jsvm_types.h](capi-types_8h.md)| 提供了MindSpore Lite支持的模型文件类型和设备类型。<br/>引用文件：&lt;mindspore/types.h&gt;<br/>库：libmindspore_lite_ndk.so |


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| OH_AI_TensorHandleArray | 张量数组结构体，用于存储张量数组指针和张量数组长度。 |
| OH_AI_ShapeInfo | 维度信息，最大的维度为**OH_AI_MAX_SHAPE_NUM**。 |
| OH_AI_CallBackParam | 回调函数中传入的算子信息。 |


### 宏定义

| 名称 | 描述 |
| -------- | -------- |
| OH_AI_MAX_SHAPE_NUM 32 | 张量维度的最大值。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| OH_AI_ContextHandle | MindSpore的上下文信息的指针，该指针会指向Context。 |
| OH_AI_DeviceInfoHandle | MindSpore的运行设备信息的指针。 |
| OH_AI_DataType | MSTensor保存的数据支持的类型。 |
| OH_AI_Format | MSTensor保存的数据支持的排列格式。 |
| OH_AI_ModelHandle | 指向模型对象的指针。 |
| OH_AI_TrainCfgHandle | 指向训练配置对象的指针。 |
| OH_AI_TensorHandleArray | 张量数组结构体，用于存储张量数组指针和张量数组长度。 |
| OH_AI_ShapeInfo | 维度信息，最大的维度为**OH_AI_MAX_SHAPE_NUM**。 |
| OH_AI_CallBackParam | 回调函数中传入的算子信息。 |
| OH_AI_KernelCallBack (const OH_AI_TensorHandleArray inputs, const OH_AI_TensorHandleArray outputs, const OH_AI_CallBackParam kernel_Info) | 回调函数指针。 |

### 枚举

| 名称 | 描述 |
| -------- | -------- |
| OH_AI_DataType {<br/>OH_AI_DATATYPE_UNKNOWN = 0, OH_AI_DATATYPE_OBJECTTYPE_STRING = 12, OH_AI_DATATYPE_OBJECTTYPE_LIST = 13, OH_AI_DATATYPE_OBJECTTYPE_TUPLE = 14,<br/>OH_AI_DATATYPE_OBJECTTYPE_TENSOR = 17, OH_AI_DATATYPE_NUMBERTYPE_BEGIN = 29, OH_AI_DATATYPE_NUMBERTYPE_BOOL = 30, OH_AI_DATATYPE_NUMBERTYPE_INT8 = 32,<br/>OH_AI_DATATYPE_NUMBERTYPE_INT16 = 33, OH_AI_DATATYPE_NUMBERTYPE_INT32 = 34, OH_AI_DATATYPE_NUMBERTYPE_INT64 = 35, OH_AI_DATATYPE_NUMBERTYPE_UINT8 = 37,<br/>OH_AI_DATATYPE_NUMBERTYPE_UINT16 = 38, OH_AI_DATATYPE_NUMBERTYPE_UINT32 = 39, OH_AI_DATATYPE_NUMBERTYPE_UINT64 = 40, OH_AI_DATATYPE_NUMBERTYPE_FLOAT16 = 42,<br/>OH_AI_DATATYPE_NUMBERTYPE_FLOAT32 = 43, OH_AI_DATATYPE_NUMBERTYPE_FLOAT64 = 44, OH_AI_DATATYPE_NUMBERTYPE_END = 46, OH_AI_DataTypeInvalid = INT32_MAX<br/>} | MSTensor保存的数据支持的类型。 |
| OH_AI_Format {<br/>OH_AI_FORMAT_NCHW = 0, OH_AI_FORMAT_NHWC = 1, OH_AI_FORMAT_NHWC4 = 2, OH_AI_FORMAT_HWKC = 3,<br/>OH_AI_FORMAT_HWCK = 4, OH_AI_FORMAT_KCHW = 5, OH_AI_FORMAT_CKHW = 6, OH_AI_FORMAT_KHWC = 7,<br/>OH_AI_FORMAT_CHWK = 8, OH_AI_FORMAT_HW = 9, OH_AI_FORMAT_HW4 = 10, OH_AI_FORMAT_NC = 11,<br/>OH_AI_FORMAT_NC4 = 12, OH_AI_FORMAT_NC4HW4 = 13, OH_AI_FORMAT_NCDHW = 15, OH_AI_FORMAT_NWC = 16,<br/>OH_AI_FORMAT_NCW = 17<br/>} | MSTensor保存的数据支持的排列格式。 |
| OH_AI_CompCode { <br/>OH_AI_COMPCODE_CORE = 0x00000000u, <br/>OH_AI_COMPCODE_MD = 0x10000000u, <br/>OH_AI_COMPCODE_ME = 0x20000000u, <br/>OH_AI_COMPCODE_MC = 0x30000000u, <br/>OH_AI_COMPCODE_LITE = 0xF0000000u<br/> } | MindSpore不同组件的代码。 |
| OH_AI_Status {<br/>OH_AI_STATUS_SUCCESS = 0, OH_AI_STATUS_CORE_FAILED = OH_AI_COMPCODE_CORE \| 0x1, OH_AI_STATUS_LITE_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -1), OH_AI_STATUS_LITE_NULLPTR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -2),<br/>OH_AI_STATUS_LITE_PARAM_INVALID = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -3), OH_AI_STATUS_LITE_NO_CHANGE = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -4), OH_AI_STATUS_LITE_SUCCESS_EXIT = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -5), OH_AI_STATUS_LITE_MEMORY_FAILED = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -6),<br/>OH_AI_STATUS_LITE_NOT_SUPPORT = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -7), OH_AI_STATUS_LITE_THREADPOOL_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -8), OH_AI_STATUS_LITE_UNINITIALIZED_OBJ = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -9), OH_AI_STATUS_LITE_OUT_OF_TENSOR_RANGE = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -100),<br/>OH_AI_STATUS_LITE_INPUT_TENSOR_ERROR, OH_AI_STATUS_LITE_REENTRANT_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -102), OH_AI_STATUS_LITE_GRAPH_FILE_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -200), OH_AI_STATUS_LITE_NOT_FIND_OP = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -300),<br/>OH_AI_STATUS_LITE_INVALID_OP_NAME = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -301), OH_AI_STATUS_LITE_INVALID_OP_ATTR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -302), OH_AI_STATUS_LITE_OP_EXECUTE_FAILURE, OH_AI_STATUS_LITE_FORMAT_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -400),<br/>OH_AI_STATUS_LITE_INFER_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -500), OH_AI_STATUS_LITE_INFER_INVALID, OH_AI_STATUS_LITE_INPUT_PARAM_INVALID<br/>} | MindSpore的状态码。 |
| OH_AI_ModelType { OH_AI_MODELTYPE_MINDIR = 0, OH_AI_MODELTYPE_INVALID = 0xFFFFFFFF } | 模型文件的类型。 |
| OH_AI_DeviceType {<br/>OH_AI_DEVICETYPE_CPU = 0, OH_AI_DEVICETYPE_GPU, OH_AI_DEVICETYPE_KIRIN_NPU, OH_AI_DEVICETYPE_NNRT = 60,<br/>OH_AI_DEVICETYPE_INVALID = 100<br/>} | 设备类型信息，包含了目前支持的设备类型。 |
| OH_AI_NNRTDeviceType { OH_AI_NNRTDEVICE_OTHERS = 0, OH_AI_NNRTDEVICE_CPU = 1, OH_AI_NNRTDEVICE_GPU = 2, OH_AI_NNRTDEVICE_ACCELERATOR = 3 } | NNRt管理的硬件设备类型。 |
| OH_AI_PerformanceMode {<br/>OH_AI_PERFORMANCE_NONE = 0, OH_AI_PERFORMANCE_LOW = 1, OH_AI_PERFORMANCE_MEDIUM = 2, OH_AI_PERFORMANCE_HIGH = 3,<br/>OH_AI_PERFORMANCE_EXTREME = 4<br/>} | NNRt硬件的工作性能模式。 |
| OH_AI_Priority { OH_AI_PRIORITY_NONE = 0, OH_AI_PRIORITY_LOW = 1, OH_AI_PRIORITY_MEDIUM = 2, OH_AI_PRIORITY_HIGH = 3 } | NNRt推理任务优先级。 |
| OH_AI_OptimizationLevel {<br/>OH_AI_KO0 = 0, OH_AI_KO2 = 2, OH_AI_KO3 = 3, OH_AI_KAUTO = 4,<br/>OH_AI_KOPTIMIZATIONTYPE = 0xFFFFFFFF<br/>} | 训练优化等级。 |
| OH_AI_QuantizationType { OH_AI_NO_QUANT = 0, OH_AI_WEIGHT_QUANT = 1, OH_AI_FULL_QUANT = 2, OH_AI_UNKNOWN_QUANT_TYPE = 0xFFFFFFFF } | 量化类型信息。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| OH_AI_ContextCreate () | 创建一个上下文的对象。注意：此接口需跟OH_AI_ContextDestroy配套使用。 |
| OH_AI_ContextDestroy (OH_AI_ContextHandle \*context) | 释放上下文对象。 |
| OH_AI_ContextSetThreadNum (OH_AI_ContextHandle context, int32_t thread_num) | 设置运行时的线程数量。 |
| OH_AI_ContextGetThreadNum (const OH_AI_ContextHandle context) | 获取线程数量。 |
| OH_AI_ContextSetThreadAffinityMode (OH_AI_ContextHandle context, int mode) | 设置运行时线程绑定CPU核心的策略，按照CPU物理核频率分为大、中、小三种类型的核心，并且仅需绑大核或者绑中核，不需要绑小核。 |
| OH_AI_ContextGetThreadAffinityMode (const OH_AI_ContextHandle context) | 获取运行时线程绑定CPU核心的策略。 |
| OH_AI_ContextSetThreadAffinityCoreList (OH_AI_ContextHandle context, const int32_t \*core_list, size_t core_num) | 设置运行时线程绑定CPU核心的列表。 |
| OH_AI_ContextGetThreadAffinityCoreLis (const OH_AI_ContextHandle context, size_t \*core_num) | 获取CPU绑核列表。 |
| OH_AI_ContextSetEnableParallel (OH_AI_ContextHandle context, bool is_parallel) | 设置运行时是否支持并行。此接口特性当前未开启，设置无效。 |
| OH_AI_ContextGetEnableParallel (const OH_AI_ContextHandle context) | 获取是否支持算子间并行。 |
| OH_AI_ContextAddDeviceInfo (OH_AI_ContextHandle context, OH_AI_DeviceInfoHandle device_info) | 将一个用户定义的运行设备信息附加到推理上下文中。 |
| OH_AI_DeviceInfoCreate (OH_AI_DeviceType device_type) | 创建一个设备信息对象。 |
| OH_AI_DeviceInfoDestroy (OH_AI_DeviceInfoHandle \*device_info) | 释放设备信息实例。注意：设备信息实例被添加到context后，无须调用者手动释放。 |
| OH_AI_DeviceInfoSetProvider (OH_AI_DeviceInfoHandle device_info, const char \*provider) | 设置生产商的名称。 |
| OH_AI_DeviceInfoGetProvider (const OH_AI_DeviceInfoHandle device_info) | 获取生产商的名称。 |
| OH_AI_DeviceInfoSetProviderDevice (OH_AI_DeviceInfoHandle device_info, const char \*device) | 设置生产商设备的名称。 |
| OH_AI_DeviceInfoGetProviderDevice (const OH_AI_DeviceInfoHandle device_info) | 获取生产商设备的名称。 |
| OH_AI_DeviceInfoGetDeviceType (const OH_AI_DeviceInfoHandle device_info) | 获取设备的类型。 |
| OH_AI_DeviceInfoSetEnableFP16 (OH_AI_DeviceInfoHandle device_info, bool is_fp16) | 设置是否开启float16推理模式，仅CPU/GPU设备可用。 |
| OH_AI_DeviceInfoGetEnableFP16 (const OH_AI_DeviceInfoHandle device_info) | 获取是否开启float16推理模式, 仅CPU/GPU设备可用。 |
| H_AI_DeviceInfoSetFrequency (OH_AI_DeviceInfoHandle device_info, int frequency) | 设置NPU的频率，仅NPU设备可用。 |
| OH_AI_DeviceInfoGetFrequency (const OH_AI_DeviceInfoHandle device_info) | 获取NPU的频率类型，仅NPU设备可用。 |
| OH_AI_GetAllNNRTDeviceDescs (size_t \*num) | 获取系统中所有NNRt硬件设备的描述信息。 |
| OH_AI_GetElementOfNNRTDeviceDescs (NNRTDeviceDesc \*descs, size_t index) | 获取NNRt设备描述信息数组中的元素指针。 |
| OH_AI_DestroyAllNNRTDeviceDescs (NNRTDeviceDesc \*\*desc) | 销毁从OH_AI_GetAllNNRTDeviceDescs获取的NNRt描写信息实例数组。 |
| OH_AI_GetDeviceIdFromNNRTDeviceDesc (const NNRtDeviceDesc \*desc) | 从特定的NNRt设备描述信息实例获取NNRt设备ID。注意，此ID只对NNRt有效。 |
| OH_AI_GetNameFromNNRTDeviceDesc (const NNRTDeviceDesc \*desc) | 从特定的NNRt设备描述信息实例获取NNRt设备名称。 |