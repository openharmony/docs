# MindSpore


## 概述

提供MindSpore Lite的模型推理相关接口，该模块下的接口是非线程安全的。

**起始版本：** 9

## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [context.h](context_8h.md) | 提供了Context相关的接口，可以配置运行时信息。<br/>引用文件：&lt;mindspore/context.h&gt;<br/>库：libmindspore_lite_ndk.so |
| [data_type.h](data__type_8h.md) | 声明了张量的数据的类型。<br/>引用文件：&lt;mindspore/data_type.h&gt;<br/>库：libmindspore_lite_ndk.so |
| [format.h](format_8h.md) | 提供张量数据的排列格式。<br/>引用文件：&lt;mindspore/format.h&gt;<br/>库：libmindspore_lite_ndk.so |
| [model.h](model_8h.md) | 提供了模型相关接口，可以用于模型创建、模型推理等。<br/>引用文件：&lt;mindspore/model.h&gt;<br/>库：libmindspore_lite_ndk.so |
| [status.h](status_8h.md) | 提供了MindSpore Lite运行时的状态码。<br/>引用文件：&lt;mindspore/status.h&gt;<br/>库：libmindspore_lite_ndk.so |
| [tensor.h](tensor_8h.md) | 提供了张量相关的接口，可用于创建和修改张量信息。<br/>引用文件：&lt;mindspore/tensor.h&gt;<br/>库：libmindspore_lite_ndk.so |
| [types.h](types_8h.md) | 提供了MindSpore Lite支持的模型文件类型和设备类型。<br/>引用文件：&lt;mindspore/types.h&gt;<br/>库：libmindspore_lite_ndk.so |


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) | 张量数组结构体，用于存储张量数组指针和张量数组长度 |
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) | 维度信息，最大的维度为**OH_AI_MAX_SHAPE_NUM**。 |
| [OH_AI_CallBackParam](_o_h___a_i___call_back_param.md) | 回调函数中传入的算子信息。 |


### 宏定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_AI_MAX_SHAPE_NUM](#oh_ai_max_shape_num) 32 | 张量维度的最大值。 |


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_AI_ContextHandle](#oh_ai_contexthandle) | MindSpore的上下文信息的指针，该指针会指向Context。 |
| [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) | MindSpore的运行设备信息的指针。 |
| [OH_AI_DataType](#oh_ai_datatype) | MSTensor保存的数据支持的类型。 |
| [OH_AI_Format](#oh_ai_format) | MSTensor保存的数据支持的排列格式。 |
| [OH_AI_ModelHandle](#oh_ai_modelhandle) | 指向模型对象的指针。 |
| [OH_AI_TrainCfgHandle](#oh_ai_traincfghandle) | 指向训练配置对象的指针。 |
| [OH_AI_TensorHandleArray](#oh_ai_tensorhandlearray) | 张量数组结构体，用于存储张量数组指针和张量数组长度 |
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) | 维度信息，最大的维度为**OH_AI_MAX_SHAPE_NUM**。 |
| [OH_AI_CallBackParam](#oh_ai_callbackparam) | 回调函数中传入的算子信息。 |
| [OH_AI_KernelCallBack](#oh_ai_kernelcallback)) (const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) outputs, const [OH_AI_CallBackParam](_o_h___a_i___call_back_param.md) kernel_Info) | 回调函数指针。 |
| [OH_AI_Status](#oh_ai_status) | MindSpore的状态码 |
| [OH_AI_TensorHandle](#oh_ai_tensorhandle) | 指向张量对象句柄 |
| [OH_AI_ModelType](#oh_ai_modeltype) | 模型文件的类型 |
| [OH_AI_DeviceType](#oh_ai_devicetype) | 设备类型信息，包含了目前支持的设备类型。 |
| [OH_AI_NNRTDeviceType](#oh_ai_nnrtdevicetype) | NNRt管理的硬件设备类型 |
| [OH_AI_PerformanceMode](#oh_ai_performancemode) | NNRt硬件的工作性能模式 |
| [OH_AI_Priority](#oh_ai_priority) | NNRt推理任务优先级 |
| [OH_AI_OptimizationLevel](#oh_ai_optimizationlevel) | 训练优化等级。 |
| [OH_AI_QuantizationType](#oh_ai_quantizationtype) | 量化类型信息。 |
| [NNRTDeviceDesc](#nnrtdevicedesc) | NNRt设备信息描述，包含设备ID，设备名称等信息。 |
| [OH_AI_AllocatorHandle](#oh_ai_allocatorhandle) | 指向内存分配器对象句柄。 |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [OH_AI_DataType](#oh_ai_datatype) {<br/>OH_AI_DATATYPE_UNKNOWN = 0, OH_AI_DATATYPE_OBJECTTYPE_STRING = 12, OH_AI_DATATYPE_OBJECTTYPE_LIST = 13, OH_AI_DATATYPE_OBJECTTYPE_TUPLE = 14,<br/>OH_AI_DATATYPE_OBJECTTYPE_TENSOR = 17, OH_AI_DATATYPE_NUMBERTYPE_BEGIN = 29, OH_AI_DATATYPE_NUMBERTYPE_BOOL = 30, OH_AI_DATATYPE_NUMBERTYPE_INT8 = 32,<br/>OH_AI_DATATYPE_NUMBERTYPE_INT16 = 33, OH_AI_DATATYPE_NUMBERTYPE_INT32 = 34, OH_AI_DATATYPE_NUMBERTYPE_INT64 = 35, OH_AI_DATATYPE_NUMBERTYPE_UINT8 = 37,<br/>OH_AI_DATATYPE_NUMBERTYPE_UINT16 = 38, OH_AI_DATATYPE_NUMBERTYPE_UINT32 = 39, OH_AI_DATATYPE_NUMBERTYPE_UINT64 = 40, OH_AI_DATATYPE_NUMBERTYPE_FLOAT16 = 42,<br/>OH_AI_DATATYPE_NUMBERTYPE_FLOAT32 = 43, OH_AI_DATATYPE_NUMBERTYPE_FLOAT64 = 44, OH_AI_DATATYPE_NUMBERTYPE_END = 46, OH_AI_DataTypeInvalid = INT32_MAX<br/>} | MSTensor保存的数据支持的类型。 |
| [OH_AI_Format](#oh_ai_format) {<br/>OH_AI_FORMAT_NCHW = 0, OH_AI_FORMAT_NHWC = 1, OH_AI_FORMAT_NHWC4 = 2, OH_AI_FORMAT_HWKC = 3,<br/>OH_AI_FORMAT_HWCK = 4, OH_AI_FORMAT_KCHW = 5, OH_AI_FORMAT_CKHW = 6, OH_AI_FORMAT_KHWC = 7,<br/>OH_AI_FORMAT_CHWK = 8, OH_AI_FORMAT_HW = 9, OH_AI_FORMAT_HW4 = 10, OH_AI_FORMAT_NC = 11,<br/>OH_AI_FORMAT_NC4 = 12, OH_AI_FORMAT_NC4HW4 = 13, OH_AI_FORMAT_NCDHW = 15, OH_AI_FORMAT_NWC = 16,<br/>OH_AI_FORMAT_NCW = 17<br/>} | MSTensor保存的数据支持的排列格式。 |
| [OH_AI_CompCode](#oh_ai_compcode) { <br/>OH_AI_COMPCODE_CORE = 0x00000000u, <br/>OH_AI_COMPCODE_MD = 0x10000000u, <br/>OH_AI_COMPCODE_ME = 0x20000000u, <br/>OH_AI_COMPCODE_MC = 0x30000000u, <br/>OH_AI_COMPCODE_LITE = 0xF0000000u<br/> } | MindSpore不同组件的代码。
| [OH_AI_Status](#oh_ai_status) {<br/>OH_AI_STATUS_SUCCESS = 0, OH_AI_STATUS_CORE_FAILED = OH_AI_COMPCODE_CORE \| 0x1, OH_AI_STATUS_LITE_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -1), OH_AI_STATUS_LITE_NULLPTR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -2),<br/>OH_AI_STATUS_LITE_PARAM_INVALID = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -3), OH_AI_STATUS_LITE_NO_CHANGE = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -4), OH_AI_STATUS_LITE_SUCCESS_EXIT = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -5), OH_AI_STATUS_LITE_MEMORY_FAILED = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -6),<br/>OH_AI_STATUS_LITE_NOT_SUPPORT = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -7), OH_AI_STATUS_LITE_THREADPOOL_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -8), OH_AI_STATUS_LITE_UNINITIALIZED_OBJ = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -9), OH_AI_STATUS_LITE_OUT_OF_TENSOR_RANGE = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -100),<br/>OH_AI_STATUS_LITE_INPUT_TENSOR_ERROR, OH_AI_STATUS_LITE_REENTRANT_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -102), OH_AI_STATUS_LITE_GRAPH_FILE_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -200), OH_AI_STATUS_LITE_NOT_FIND_OP = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -300),<br/>OH_AI_STATUS_LITE_INVALID_OP_NAME = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -301), OH_AI_STATUS_LITE_INVALID_OP_ATTR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -302), OH_AI_STATUS_LITE_OP_EXECUTE_FAILURE, OH_AI_STATUS_LITE_FORMAT_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -400),<br/>OH_AI_STATUS_LITE_INFER_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -500), OH_AI_STATUS_LITE_INFER_INVALID, OH_AI_STATUS_LITE_INPUT_PARAM_INVALID<br/>} | MindSpore的状态码 |
| [OH_AI_ModelType](#oh_ai_modeltype) { OH_AI_MODELTYPE_MINDIR = 0, OH_AI_MODELTYPE_INVALID = 0xFFFFFFFF } | 模型文件的类型 |
| [OH_AI_DeviceType](#oh_ai_devicetype) {<br/>OH_AI_DEVICETYPE_CPU = 0, OH_AI_DEVICETYPE_GPU, OH_AI_DEVICETYPE_KIRIN_NPU, OH_AI_DEVICETYPE_NNRT = 60,<br/>OH_AI_DEVICETYPE_INVALID = 100<br/>} | 设备类型信息，包含了目前支持的设备类型。 |
| [OH_AI_NNRTDeviceType](#oh_ai_nnrtdevicetype) { OH_AI_NNRTDEVICE_OTHERS = 0, OH_AI_NNRTDEVICE_CPU = 1, OH_AI_NNRTDEVICE_GPU = 2, OH_AI_NNRTDEVICE_ACCELERATOR = 3 } | NNRt管理的硬件设备类型 |
| [OH_AI_PerformanceMode](#oh_ai_performancemode) {<br/>OH_AI_PERFORMANCE_NONE = 0, OH_AI_PERFORMANCE_LOW = 1, OH_AI_PERFORMANCE_MEDIUM = 2, OH_AI_PERFORMANCE_HIGH = 3,<br/>OH_AI_PERFORMANCE_EXTREME = 4<br/>} | NNRt硬件的工作性能模式 |
| [OH_AI_Priority](#oh_ai_priority) { OH_AI_PRIORITY_NONE = 0, OH_AI_PRIORITY_LOW = 1, OH_AI_PRIORITY_MEDIUM = 2, OH_AI_PRIORITY_HIGH = 3 } | NNRt推理任务优先级 |
| [OH_AI_OptimizationLevel](#oh_ai_optimizationlevel) {<br/>OH_AI_KO0 = 0, OH_AI_KO2 = 2, OH_AI_KO3 = 3, OH_AI_KAUTO = 4,<br/>OH_AI_KOPTIMIZATIONTYPE = 0xFFFFFFFF<br/>} | 训练优化等级。 |
| [OH_AI_QuantizationType](#oh_ai_quantizationtype) { OH_AI_NO_QUANT = 0, OH_AI_WEIGHT_QUANT = 1, OH_AI_FULL_QUANT = 2, OH_AI_UNKNOWN_QUANT_TYPE = 0xFFFFFFFF } | 量化类型信息。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_AI_ContextCreate](#oh_ai_contextcreate) () | 创建一个上下文的对象。注意：此接口需跟[OH_AI_ContextDestroy](#oh_ai_contextdestroy)配套使用。 |
| [OH_AI_ContextDestroy](#oh_ai_contextdestroy) ([OH_AI_ContextHandle](#oh_ai_contexthandle) \*context) | 释放上下文对象。 |
| [OH_AI_ContextSetThreadNum](#oh_ai_contextsetthreadnum) ([OH_AI_ContextHandle](#oh_ai_contexthandle) context, int32_t thread_num) | 设置运行时的线程数量。 |
| [OH_AI_ContextGetThreadNum](#oh_ai_contextgetthreadnum) (const [OH_AI_ContextHandle](#oh_ai_contexthandle) context) | 获取线程数量。 |
| [OH_AI_ContextSetThreadAffinityMode](#oh_ai_contextsetthreadaffinitymode) ([OH_AI_ContextHandle](#oh_ai_contexthandle) context, int mode) | 设置运行时线程绑定CPU核心的策略，按照CPU物理核频率分为大、中、小三种类型的核心，并且仅需绑大核或者绑中核，不需要绑小核。 |
| [OH_AI_ContextGetThreadAffinityMode](#oh_ai_contextgetthreadaffinitymode) (const [OH_AI_ContextHandle](#oh_ai_contexthandle) context) | 获取运行时线程绑定CPU核心的策略。 |
| [OH_AI_ContextSetThreadAffinityCoreList](#oh_ai_contextsetthreadaffinitycorelist) ([OH_AI_ContextHandle](#oh_ai_contexthandle) context, const int32_t \*core_list, size_t core_num) | 设置运行时线程绑定CPU核心的列表。 |
| [OH_AI_ContextGetThreadAffinityCoreList](#oh_ai_contextgetthreadaffinitycorelist) (const [OH_AI_ContextHandle](#oh_ai_contexthandle) context, size_t \*core_num) | 获取CPU绑核列表。 |
| [OH_AI_ContextSetEnableParallel](#oh_ai_contextsetenableparallel) ([OH_AI_ContextHandle](#oh_ai_contexthandle) context, bool is_parallel) | 设置运行时是否支持并行。此接口特性当前未开启，设置无效。 |
| [OH_AI_ContextGetEnableParallel](#oh_ai_contextgetenableparallel) (const [OH_AI_ContextHandle](#oh_ai_contexthandle) context) | 获取是否支持算子间并行。 |
| [OH_AI_ContextAddDeviceInfo](#oh_ai_contextadddeviceinfo) ([OH_AI_ContextHandle](#oh_ai_contexthandle) context, [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 将一个用户定义的运行设备信息附加到推理上下文中。 |
| [OH_AI_DeviceInfoCreate](#oh_ai_deviceinfocreate) ([OH_AI_DeviceType](#oh_ai_devicetype) device_type) | 创建一个设备信息对象。 |
| [OH_AI_DeviceInfoDestroy](#oh_ai_deviceinfodestroy) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) \*device_info) | 释放设备信息实例。注意：设备信息实例被添加到context后，无须调用者手动释放。 |
| [OH_AI_DeviceInfoSetProvider](#oh_ai_deviceinfosetprovider) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, const char \*provider) | 设置生产商的名称。 |
| [OH_AI_DeviceInfoGetProvider](#oh_ai_deviceinfogetprovider) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 获取生产商的名称。 |
| [OH_AI_DeviceInfoSetProviderDevice](#oh_ai_deviceinfosetproviderdevice) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, const char \*device) | 设置生产商设备的名称。 |
| [OH_AI_DeviceInfoGetProviderDevice](#oh_ai_deviceinfogetproviderdevice) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 获取生产商设备的名称。 |
| [OH_AI_DeviceInfoGetDeviceType](#oh_ai_deviceinfogetdevicetype) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 获取设备的类型。 |
| [OH_AI_DeviceInfoSetEnableFP16](#oh_ai_deviceinfosetenablefp16) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, bool is_fp16) | 设置是否开启float16推理模式，仅CPU/GPU设备可用。 |
| [OH_AI_DeviceInfoGetEnableFP16](#oh_ai_deviceinfogetenablefp16) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 获取是否开启float16推理模式, 仅CPU/GPU设备可用。 |
| [OH_AI_DeviceInfoSetFrequency](#oh_ai_deviceinfosetfrequency) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, int frequency) | 设置NPU的频率，仅NPU设备可用。 |
| [OH_AI_DeviceInfoGetFrequency](#oh_ai_deviceinfogetfrequency) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 获取NPU的频率类型，仅NPU设备可用。 |
| [OH_AI_GetAllNNRTDeviceDescs](#oh_ai_getallnnrtdevicedescs) (size_t \*num) | 获取系统中所有NNRt硬件设备的描述信息。 |
| [OH_AI_GetElementOfNNRTDeviceDescs](#oh_ai_getelementofnnrtdevicedescs) ([NNRTDeviceDesc](#nnrtdevicedesc) \*descs, size_t index) | 获取NNRt设备描述信息数组中的元素指针。 |
| [OH_AI_DestroyAllNNRTDeviceDescs](#oh_ai_destroyallnnrtdevicedescs) ([NNRTDeviceDesc](#nnrtdevicedesc) \*\*desc) | 销毁从[OH_AI_GetAllNNRTDeviceDescs](#oh_ai_getallnnrtdevicedescs)获取的NNRt描写信息实例数组。 |
| [OH_AI_GetDeviceIdFromNNRTDeviceDesc](#oh_ai_getdeviceidfromnnrtdevicedesc) (const [NNRtDeviceDesc](#nnrtdevicedesc) \*desc) | 从特定的NNRt设备描述信息实例获取NNRt设备ID。注意，此ID只对NNRt有效。 |
| [OH_AI_GetNameFromNNRTDeviceDesc](#oh_ai_getnamefromnnrtdevicedesc) (const [NNRTDeviceDesc](#nnrtdevicedesc) \*desc) | 从特定的NNRt设备描述信息实例获取NNRt设备名称。 |
| [OH_AI_GetTypeFromNNRtDeviceDesc](#oh_ai_gettypefromnnrtdevicedesc) (const [NNRTDeviceDesc](#nnrtdevicedesc) \*desc) | 从特定的NNRt设备描述信息实例获取NNRt设备类型。 |
| [OH_AI_CreateNNRTDeviceInfoByName](#oh_ai_creatennrtdeviceinfobyname) (const char \*name) | 查找指定名称的NNRt设备，根据找到的第一个设备信息，创建NNRt设备信息。 |
| [OH_AI_CreateNNRTDeviceInfoByType](#oh_ai_creatennrtdeviceinfobytype) ([OH_AI_NNRTDeviceType](#oh_ai_nnrtdevicetype) type) | 查找指定类型的NNRt设备，根据找到的第一个设备信息，创建NNRt设备信息。 |
| [OH_AI_DeviceInfoSetDeviceId](#oh_ai_deviceinfosetdeviceid) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, size_t device_id) | 设置NNRt设备ID，仅NNRt设备可用。 |
| [OH_AI_DeviceInfoGetDeviceId](#oh_ai_deviceinfogetdeviceid) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 获取NNRt设备ID，仅NNRt设备可用。 |
| [OH_AI_DeviceInfoSetPerformanceMode](#oh_ai_deviceinfosetperformancemode) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, [OH_AI_PerformanceMode](#oh_ai_performancemode) mode) | 设置NNRt性能模式，仅NNRt设备可用。 |
| [OH_AI_DeviceInfoGetPerformanceMode](#oh_ai_deviceinfogetperformancemode) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 获取NNRt性能模式，仅NNRt设备可用。 |
| [OH_AI_DeviceInfoSetPriority](#oh_ai_deviceinfosetpriority) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, [OH_AI_Priority](#oh_ai_priority) priority) | 设置NNRt任务优先级，仅NNRt设备可用。 |
| [OH_AI_DeviceInfoGetPriority](#oh_ai_deviceinfogetpriority) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 获取NNRt任务优先级，仅NNRt设备可用。 |
| [OH_AI_DeviceInfoAddExtension](#oh_ai_deviceinfoaddextension) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, const char \*name, const char \*value, size_t value_size) | 向设备信息中添加键/值对形式的扩展配置。只对NNRt设备信息有效。 |
| [OH_AI_ModelCreate](#oh_ai_modelcreate) () | 创建一个模型对象。 |
| [OH_AI_ModelDestroy](#oh_ai_modeldestroy) ([OH_AI_ModelHandle](#oh_ai_modelhandle) \*model) | 释放一个模型对象。 |
| [OH_AI_ModelBuild](#oh_ai_modelbuild) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const void \*model_data, size_t data_size, [OH_AI_ModelType](#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](#oh_ai_contexthandle) model_context) | 从内存缓冲区加载并编译MindSpore模型。 |
| [OH_AI_ModelBuildFromFile](#oh_ai_modelbuildfromfile) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const char \*model_path, [OH_AI_ModelType](#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](#oh_ai_contexthandle) model_context) | 通过模型文件加载并编译MindSpore模型。 |
| [OH_AI_ModelResize](#oh_ai_modelresize) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) \*shape_infos, size_t shape_info_num) | 调整已编译模型的输入形状。 |
| [OH_AI_ModelPredict](#oh_ai_modelpredict) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) \*outputs, const [OH_AI_KernelCallBack](#oh_ai_kernelcallback) before, const [OH_AI_KernelCallBack](#oh_ai_kernelcallback) after) | 执行模型推理。 |
| [OH_AI_ModelGetInputs](#oh_ai_modelgetinputs) (const [OH_AI_ModelHandle](#oh_ai_modelhandle) model) | 获取模型的输入张量数组结构体。 |
| [OH_AI_ModelGetOutputs](#oh_ai_modelgetoutputs) (const [OH_AI_ModelHandle](#oh_ai_modelhandle) model) | 获取模型的输出张量数组结构体。 |
| [OH_AI_ModelGetInputByTensorName](#oh_ai_modelgetinputbytensorname) (const [OH_AI_ModelHandle](#oh_ai_modelhandle) model, const char \*tensor_name) | 通过张量名获取模型的输入张量。 |
| [OH_AI_ModelGetOutputByTensorName](#oh_ai_modelgetoutputbytensorname) (const [OH_AI_ModelHandle](#oh_ai_modelhandle) model, const char \*tensor_name) | 通过张量名获取模型的输出张量。 |
| [OH_AI_TrainCfgCreate](#oh_ai_traincfgcreate) () | 创建训练配置对象指针，仅用于端侧训练。 |
| [OH_AI_TrainCfgDestroy](#oh_ai_traincfgdestroy) ([OH_AI_TrainCfgHandle](#oh_ai_traincfghandle) \*train_cfg) | 销毁训练配置对象指针，仅用于端侧训练。 |
| [OH_AI_TrainCfgGetLossName](#oh_ai_traincfggetlossname) ([OH_AI_TrainCfgHandle](#oh_ai_traincfghandle) train_cfg, size_t \*num) | 获取损失函数的名称列表，仅用于端侧训练。 |
| [OH_AI_TrainCfgSetLossName](#oh_ai_traincfgsetlossname) ([OH_AI_TrainCfgHandle](#oh_ai_traincfghandle) train_cfg, const char \*\*loss_name, size_t num) | 设置损失函数的名称列表，仅用于端侧训练。 |
| [OH_AI_TrainCfgGetOptimizationLevel](#oh_ai_traincfggetoptimizationlevel) ([OH_AI_TrainCfgHandle](#oh_ai_traincfghandle) train_cfg) | 获取训练配置的优化等级，仅用于端侧训练。 |
| [OH_AI_TrainCfgSetOptimizationLevel](#oh_ai_traincfgsetoptimizationlevel) ([OH_AI_TrainCfgHandle](#oh_ai_traincfghandle) train_cfg, [OH_AI_OptimizationLevel](#oh_ai_optimizationlevel) level) | 设置训练配置的优化等级，仅用于端侧训练。 |
| [OH_AI_TrainModelBuild](#oh_ai_trainmodelbuild) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const void \*model_data, size_t data_size, [OH_AI_ModelType](#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](#oh_ai_contexthandle) model_context, const [OH_AI_TrainCfgHandle](#oh_ai_traincfghandle) train_cfg) | 从内存缓冲区加载训练模型，并将模型编译至可在Device上运行的状态，仅用于端侧训练。 |
| [OH_AI_TrainModelBuildFromFile](#oh_ai_trainmodelbuildfromfile) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const char \*model_path, [OH_AI_ModelType](#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](#oh_ai_contexthandle) model_context, const [OH_AI_TrainCfgHandle](#oh_ai_traincfghandle) train_cfg) | 根据路径读取加载训练模型，并将模型编译至可在Device上运行的状态，仅用于端侧训练。 |
| [OH_AI_RunStep](#oh_ai_runstep) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const [OH_AI_KernelCallBack](#oh_ai_kernelcallback) before, const [OH_AI_KernelCallBack](#oh_ai_kernelcallback) after) | 单步训练模型，仅用于端侧训练。 |
| [OH_AI_ModelSetLearningRate](#oh_ai_modelsetlearningrate) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, float learning_rate) | 设置训练的学习率，仅用于端侧训练。 |
| [OH_AI_ModelGetLearningRate](#oh_ai_modelgetlearningrate) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model) | 获取训练的学习率，仅用于端侧训练。 |
| [OH_AI_ModelGetWeights](#oh_ai_modelgetweights) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model) | 获取模型的所有权重Tensors，仅用于端侧训练。 |
| [OH_AI_ModelUpdateWeights](#oh_ai_modelupdateweights) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) new_weights) | 更新模型的权重Tensor内容，仅用于端侧训练。 |
| [OH_AI_ModelGetTrainMode](#oh_ai_modelgettrainmode) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model) | 获取训练模式。 |
| [OH_AI_ModelSetTrainMode](#oh_ai_modelsettrainmode) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, bool train) | 设置训练模式，仅用于端侧训练。 |
| [OH_AI_ModelSetupVirtualBatch](#oh_ai_modelsetupvirtualbatch) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, int virtual_batch_multiplier, float lr, float momentum) | OH_AI_API [OH_AI_Status](#oh_ai_status)<br/>设置虚拟batch用于训练，仅用于端侧训练。 |
| [OH_AI_ExportModel](#oh_ai_exportmodel) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, [OH_AI_ModelType](#oh_ai_modeltype) model_type, const char \*model_file, [OH_AI_QuantizationType](#oh_ai_quantizationtype) quantization_type, bool export_inference_only, char \*\*output_tensor_name, size_t num) | 导出训练模型，仅用于端侧训练。 |
| [OH_AI_ExportModelBuffer](#oh_ai_exportmodelbuffer) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, [OH_AI_ModelType](#oh_ai_modeltype) model_type, char \*\*model_data, size_t \*data_size, [OH_AI_QuantizationType](#oh_ai_quantizationtype) quantization_type, bool export_inference_only, char \*\*output_tensor_name, size_t num) | 导出训练模型内存缓存，仅用于端侧训练。  |
| [OH_AI_ExportWeightsCollaborateWithMicro](#oh_ai_exportweightscollaboratewithmicro) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, [OH_AI_ModelType](#oh_ai_modeltype) model_type, const char \*weight_file, bool is_inference, bool enable_fp16, char \*\*changeable_weights_name, size_t num) | 导出模型权重,只能用于micro推理，仅用于端侧训练。 |
| [OH_AI_TensorCreate](#oh_ai_tensorcreate) (const char \*name, [OH_AI_DataType](#oh_ai_datatype) type, const int64_t \*shape, size_t shape_num, const void \*data, size_t data_len) | 创建一个张量对象。 |
| [OH_AI_TensorDestroy](#oh_ai_tensordestroy) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) \*tensor) | 释放张量对象。 |
| [OH_AI_TensorClone](#oh_ai_tensorclone) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | 深拷贝一个张量。 |
| [OH_AI_TensorSetName](#oh_ai_tensorsetname) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, const char \*name) | 设置张量的名称。 |
| [OH_AI_TensorGetName](#oh_ai_tensorgetname) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | 获取张量的名称。 |
| [OH_AI_TensorSetDataType](#oh_ai_tensorsetdatatype) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, [OH_AI_DataType](#oh_ai_datatype) type) | 设置张量的数据类型。 |
| [OH_AI_TensorGetDataType](#oh_ai_tensorgetdatatype) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | 获取张量类型。 |
| [OH_AI_TensorSetShape](#oh_ai_tensorsetshape) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, const int64_t \*shape, size_t shape_num) | 设置张量的形状。 |
| [OH_AI_TensorGetShape](#oh_ai_tensorgetshape) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, size_t \*shape_num) | 获取张量的形状。 |
| [OH_AI_TensorSetFormat](#oh_ai_tensorsetformat) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, [OH_AI_Format](#oh_ai_format) format) | 设置张量数据的排列方式。 |
| [OH_AI_TensorGetFormat](#oh_ai_tensorgetformat) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | 获取张量数据的排列方式。 |
| [OH_AI_TensorSetData](#oh_ai_tensorsetdata) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, void \*data) | 设置张量的数据。 |
| [OH_AI_TensorGetData](#oh_ai_tensorgetdata) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | 获取张量数据的指针。 |
| [OH_AI_TensorGetMutableData](#oh_ai_tensorgetmutabledata) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | 获取可变的张量数据指针。如果数据为空则会开辟内存。 |
| [OH_AI_TensorGetElementNum](#oh_ai_tensorgetelementnum) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | 获取张量元素数量。 |
| [OH_AI_TensorGetDataSize](#oh_ai_tensorgetdatasize) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | 获取张量中的数据的字节数大小。 |
| [OH_AI_TensorSetUserData](#oh_ai_tensorsetuserdata) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, void \*data, size_t data_size) | 设置张量为用户自行管理的数据。此接口常用于复用用户数据作为模型输入，可减少一次数据拷贝。 <br/>注意：此数据对于张量来说是外部数据，张量销毁时不会主动释放，由调用者负责释放。另外，在此张量使用过程中，调用者须确保此数据有效。 |
| [OH_AI_TensorGetAllocator](#oh_ai_tensorgetallocator)([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | 获取内存分配器。此接口主要是提供一种获取张量的内存分配器的方法。 |
| [OH_AI_TensorSetAllocator](#oh_ai_tensorsetallocator)([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, [OH_AI_AllocatorHandle](#oh_ai_allocatorhandle) allocator) | 设置内存分配器。此接口主要是提供一种设置内存分配器的方法，tensor的内存将由这个分配器分配。 |


## 宏定义说明


### OH_AI_MAX_SHAPE_NUM

```
#define OH_AI_MAX_SHAPE_NUM   32
```

**描述**

维度信息，最大的维度为**OH_AI_MAX_SHAPE_NUM**。

**起始版本：** 9


## 类型定义说明


### NNRTDeviceDesc

```
typedef struct NNRTDeviceDesc NNRTDeviceDesc
```

**描述**

NNRt设备信息描述，包含设备ID，设备名称等信息。

**起始版本：** 10

### OH_AI_AllocatorHandle

```
typedef void *OH_AI_AllocatorHandle
```

**描述**

指向内存分配器对象句柄。

**起始版本：** 12

### OH_AI_CallBackParam

```
typedef struct OH_AI_CallBackParam OH_AI_CallBackParam
```

**描述**

回调函数中传入的算子信息。

**起始版本：** 9


### OH_AI_ContextHandle

```
typedef void* OH_AI_ContextHandle
```

**描述**

MindSpore的上下文信息的指针，该指针会指向Context。

**起始版本：** 9


### OH_AI_DataType

```
typedef enum OH_AI_DataType OH_AI_DataType
```

**描述**

MSTensor保存的数据支持的类型。

**起始版本：** 9


### OH_AI_DeviceInfoHandle

```
typedef void* OH_AI_DeviceInfoHandle
```

**描述**

MindSpore的运行设备信息的指针。

**起始版本：** 9


### OH_AI_DeviceType

```
typedef enum OH_AI_DeviceType OH_AI_DeviceType
```

**描述**

设备类型信息，包含了目前支持的设备类型。

**起始版本：** 9


### OH_AI_Format

```
typedef enum OH_AI_Format OH_AI_Format
```

**描述**

MSTensor保存的数据支持的排列格式。

**起始版本：** 9


### OH_AI_KernelCallBack

```
typedef bool(* OH_AI_KernelCallBack) (const OH_AI_TensorHandleArray inputs, const OH_AI_TensorHandleArray outputs, const OH_AI_CallBackParam kernel_Info)
```

**描述**

回调函数指针。

该函数指针是用于设置[OH_AI_ModelPredict](#oh_ai_modelpredict)函数参数中的两个回调函数。 该指针指向的函数需要包含三个参数，其中inputs和outputs对应了算子的输入和输出张量，kernel_Info表示当前算子的信息。 可以通过回调函数监控算子执行的情况，例如统计算子的执行时间，校验算子的正确性等等。

**起始版本：** 9


### OH_AI_ModelHandle

```
typedef void* OH_AI_ModelHandle
```

**描述**

指向模型对象的指针。

**起始版本：** 9


### OH_AI_ModelType

```
typedef enum OH_AI_ModelType OH_AI_ModelType
```

**描述**

模型文件的类型

**起始版本：** 9


### OH_AI_NNRTDeviceType

```
typedef enum OH_AI_NNRTDeviceType OH_AI_NNRTDeviceType
```

**描述**

NNRt管理的硬件设备类型

**起始版本：** 10


### OH_AI_PerformanceMode

```
typedef enum OH_AI_PerformanceMode OH_AI_PerformanceMode
```

**描述**

NNRt硬件的工作性能模式

**起始版本：** 10


### OH_AI_Priority

```
typedef enum OH_AI_Priority OH_AI_Priority
```

**描述**

NNRt推理任务优先级

**起始版本：** 10


### OH_AI_Status

```
typedef enum OH_AI_Status OH_AI_Status
```

**描述**

MindSpore的状态码

**起始版本：** 9


### OH_AI_TensorHandle

```
typedef void* OH_AI_TensorHandle
```

**描述**

指向张量对象句柄

**起始版本：** 9


### OH_AI_TensorHandleArray

```
typedef struct OH_AI_TensorHandleArray OH_AI_TensorHandleArray
```

**描述**

张量数组结构体，用于存储张量数组指针和张量数组长度

**起始版本：** 9


### OH_AI_TrainCfgHandle

```
typedef void* OH_AI_TrainCfgHandle
```

**描述**

指向训练配置对象的指针。

**起始版本：** 11


## 枚举类型说明


### OH_AI_CompCode

```
enum OH_AI_CompCode
```

**描述**

MindSpore不同组件的代码

**起始版本：** 9

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AI_COMPCODE_CORE | MindSpore Core的代码 |
| OH_AI_COMPCODE_MD   | MindSpore MindData的代码。 |
| OH_AI_COMPCODE_ME   | MindSpore MindExpression的代码。 |
| OH_AI_COMPCODE_MC   | MindSpore的代码。 |
| OH_AI_COMPCODE_LITE | MindSpore Lite的代码 |


### OH_AI_DataType

```
enum OH_AI_DataType
```

**描述**

MSTensor保存的数据支持的类型。

**起始版本：** 9

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AI_DATATYPE_UNKNOWN | 未知的数据类型 |
| OH_AI_DATATYPE_OBJECTTYPE_STRING | String数据类型 |
| OH_AI_DATATYPE_OBJECTTYPE_LIST | List数据类型 |
| OH_AI_DATATYPE_OBJECTTYPE_TUPLE | Tuple数据类型 |
| OH_AI_DATATYPE_OBJECTTYPE_TENSOR | TensorList数据类型 |
| OH_AI_DATATYPE_NUMBERTYPE_BEGIN | Number类型的起始 |
| OH_AI_DATATYPE_NUMBERTYPE_BOOL | Bool数据类型 |
| OH_AI_DATATYPE_NUMBERTYPE_INT8 | Int8数据类型 |
| OH_AI_DATATYPE_NUMBERTYPE_INT16 | 表示Int16数据类型 |
| OH_AI_DATATYPE_NUMBERTYPE_INT32 | 表示Int32数据类型 |
| OH_AI_DATATYPE_NUMBERTYPE_INT64 | 表示Int64数据类型 |
| OH_AI_DATATYPE_NUMBERTYPE_UINT8 | 表示UInt8数据类型 |
| OH_AI_DATATYPE_NUMBERTYPE_UINT16 | 表示UInt16数据类型 |
| OH_AI_DATATYPE_NUMBERTYPE_UINT32 | 表示UInt32数据类型 |
| OH_AI_DATATYPE_NUMBERTYPE_UINT64 | 表示UInt64数据类型 |
| OH_AI_DATATYPE_NUMBERTYPE_FLOAT16 | 表示Float16数据类型 |
| OH_AI_DATATYPE_NUMBERTYPE_FLOAT32 | 表示Float32数据类型 |
| OH_AI_DATATYPE_NUMBERTYPE_FLOAT64 | 表示Float64数据类型 |
| OH_AI_DATATYPE_NUMBERTYPE_END | 表示Number类型的结尾 |
| OH_AI_DataTypeInvalid | 表示无效的数据类型 |


### OH_AI_DeviceType

```
enum OH_AI_DeviceType
```

**描述**

设备类型信息，包含了目前支持的设备类型。

**起始版本：** 9

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AI_DEVICETYPE_CPU | 设备类型是CPU |
| OH_AI_DEVICETYPE_GPU | 设备类型是GPU<br/>该配置为上游开源社区选项，在OpenHarmony上不支持 |
| OH_AI_DEVICETYPE_KIRIN_NPU | 设备类型是麒麟NPU<br/>该配置为上游开源社区选项，在OpenHarmony上不支持<br/>如需使用KIRIN_NPU请通过OH_AI_DEVICETYPE_NNRT配置 |
| OH_AI_DEVICETYPE_NNRT | 设备类型是NNRt（Neural Network Runtime, 神经网络运行时是面向AI领域的跨芯片推理计算运行时）<br/>OHOS设备范围是[60,80)。 |
| OH_AI_DEVICETYPE_INVALID | 设备类型无效 |


### OH_AI_Format

```
enum OH_AI_Format
```

**描述**

MSTensor保存的数据支持的排列格式。

**起始版本：** 9

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AI_FORMAT_NCHW | 按批次N、通道C、高度H和宽度W的顺序存储张量数据。 |
| OH_AI_FORMAT_NHWC | 按批次N、高度H、宽度W和通道C的顺序存储张量数据。 |
| OH_AI_FORMAT_NHWC4 | 按批次N、高度H、宽度W和通道C的顺序存储张量数据，其中C轴是4字节对齐格式。 |
| OH_AI_FORMAT_HWKC | 按高度H、宽度W、核数K和通道C的顺序存储张量数据。 |
| OH_AI_FORMAT_HWCK | 按高度H、宽度W、通道C和核数K的顺序存储张量数据。 |
| OH_AI_FORMAT_KCHW | 按核数K、通道C、高度H和宽度W的顺序存储张量数据。 |
| OH_AI_FORMAT_CKHW | 按通道C、核数K、高度H和宽度W的顺序存储张量数据。 |
| OH_AI_FORMAT_KHWC | 按核数K、高度H、宽度W和通道C的顺序存储张量数据。 |
| OH_AI_FORMAT_CHWK | 按通道C、高度H、宽度W和核数K的顺序存储张量数据。 |
| OH_AI_FORMAT_HW | 按高度H和宽度W的顺序存储张量数据。 |
| OH_AI_FORMAT_HW4 | 按高度H和宽度W的顺序存储张量数据，其中W轴是4字节对齐格式。 |
| OH_AI_FORMAT_NC | 按批次N和通道C的顺序存储张量数据。 |
| OH_AI_FORMAT_NC4 | 按批次N和通道C的顺序存储张量数据，其中C轴是4字节对齐格式。 |
| OH_AI_FORMAT_NC4HW4 | 按批次N、通道C、高度H和宽度W的顺序存储张量数据，其中C轴和W轴是4字节对齐格式。 |
| OH_AI_FORMAT_NCDHW | 按批次N、通道C、深度D、高度H和宽度W的顺序存储张量数据。 |
| OH_AI_FORMAT_NWC | 按批次N、宽度W和通道C的顺序存储张量数据。 |
| OH_AI_FORMAT_NCW | 按批次N、通道C和宽度W的顺序存储张量数据。 |


### OH_AI_ModelType

```
enum OH_AI_ModelType
```

**描述**

模型文件的类型

**起始版本：** 9

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AI_MODELTYPE_MINDIR | 模型类型是MindIR，对应的模型文件后缀为.ms。 |
| OH_AI_MODELTYPE_INVALID | 模型类型无效 |


### OH_AI_NNRTDeviceType

```
enum OH_AI_NNRTDeviceType
```

**描述**

NNRt管理的硬件设备类型

**起始版本：** 10

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AI_NNRTDEVICE_OTHERS | 设备类型不属于以下3种，则属于其它 |
| OH_AI_NNRTDEVICE_CPU | CPU设备 |
| OH_AI_NNRTDEVICE_GPU | GPU设备 |
| OH_AI_NNRTDEVICE_ACCELERATOR | 特定的加速设备 |


### OH_AI_OptimizationLevel

```
enum OH_AI_OptimizationLevel
```

**描述：**

训练优化等级。

**起始版本：**

**11**

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AI_KO0 | 无优化等级。 |
| OH_AI_KO2 | 将网络转换为float16, 保持批量归一化层和损失函数为float32。 |
| OH_AI_KO3 | 将网络转换为float16, 包括批量归一化层 |
| OH_AI_KAUTO | 根据设备选择优化等级。 |
| OH_AI_KOPTIMIZATIONTYPE | 无效优化等级。 |


### OH_AI_PerformanceMode

```
enum OH_AI_PerformanceMode
```

**描述**

NNRt硬件的工作性能模式

**起始版本：** 10

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AI_PERFORMANCE_NONE | 无特殊设置 |
| OH_AI_PERFORMANCE_LOW | 低功耗模式 |
| OH_AI_PERFORMANCE_MEDIUM | 功耗-性能均衡模式 |
| OH_AI_PERFORMANCE_HIGH | 高性能模式 |
| OH_AI_PERFORMANCE_EXTREME | 极致性能模式 |


### OH_AI_Priority

```
enum OH_AI_Priority
```

**描述**

NNRt推理任务优先级

**起始版本：** 10

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AI_PRIORITY_NONE | 无优先级偏好 |
| OH_AI_PRIORITY_LOW | 低优先级任务 |
| OH_AI_PRIORITY_MEDIUM | 中优先级任务 |
| OH_AI_PRIORITY_HIGH | 高优先级 |


### OH_AI_QuantizationType

```
enum OH_AI_QuantizationType
```

**描述：**

量化类型信息。

**起始版本：**

**11**

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AI_NO_QUANT | 不做量化 |
| OH_AI_WEIGHT_QUANT | 权重量化 |
| OH_AI_FULL_QUANT | 全量化 |
| OH_AI_UNKNOWN_QUANT_TYPE | 无效量化类型 |


### OH_AI_Status

```
enum OH_AI_Status
```

**描述**

MindSpore的状态码

**起始版本：** 9

| 枚举值 | 描述 |
| -------- | -------- |
| OH_AI_STATUS_SUCCESS | 通用的成功状态码 |
| OH_AI_STATUS_CORE_FAILED | MindSpore Core 失败状态码 |
| OH_AI_STATUS_LITE_ERROR | MindSpore Lite 异常状态码 |
| OH_AI_STATUS_LITE_NULLPTR | MindSpore Lite 空指针状态码 |
| OH_AI_STATUS_LITE_PARAM_INVALID | MindSpore Lite 参数异常状态码 |
| OH_AI_STATUS_LITE_NO_CHANGE | MindSpore Lite 未改变状态码 |
| OH_AI_STATUS_LITE_SUCCESS_EXIT | MindSpore Lite 没有错误但是退出的状态码 |
| OH_AI_STATUS_LITE_MEMORY_FAILED | MindSpore Lite 内存分配失败的状态码 |
| OH_AI_STATUS_LITE_NOT_SUPPORT | MindSpore Lite 功能未支持的状态码 |
| OH_AI_STATUS_LITE_THREADPOOL_ERROR | MindSpore Lite 线程池异常状态码 |
| OH_AI_STATUS_LITE_UNINITIALIZED_OBJ | MindSpore Lite 未初始化状态码 |
| OH_AI_STATUS_LITE_OUT_OF_TENSOR_RANGE | MindSpore Lite 张量溢出错误的状态码 |
| OH_AI_STATUS_LITE_INPUT_TENSOR_ERROR | MindSpore Lite 输入张量异常的状态码 |
| OH_AI_STATUS_LITE_REENTRANT_ERROR | MindSpore Lite 重入异常的状态码 |
| OH_AI_STATUS_LITE_GRAPH_FILE_ERROR | MindSpore Lite 文件异常状态码 |
| OH_AI_STATUS_LITE_NOT_FIND_OP | MindSpore Lite 未找到算子的状态码 |
| OH_AI_STATUS_LITE_INVALID_OP_NAME | MindSpore Lite 无效算子状态码 |
| OH_AI_STATUS_LITE_INVALID_OP_ATTR | MindSpore Lite 无效算子超参数状态码 |
| OH_AI_STATUS_LITE_OP_EXECUTE_FAILURE | MindSpore Lite 算子执行失败的状态码 |
| OH_AI_STATUS_LITE_FORMAT_ERROR | MindSpore Lite 张量格式异常状态码 |
| OH_AI_STATUS_LITE_INFER_ERROR | MindSpore Lite 形状推理异常状态码 |
| OH_AI_STATUS_LITE_INFER_INVALID | MindSpore Lite 无效的形状推理的状态码 |
| OH_AI_STATUS_LITE_INPUT_PARAM_INVALID | MindSpore Lite 用户输入的参数无效状态码 |


## 函数说明


### OH_AI_ContextAddDeviceInfo()

```
OH_AI_API void OH_AI_ContextAddDeviceInfo (OH_AI_ContextHandle context, OH_AI_DeviceInfoHandle device_info )
```

**描述**

将一个用户定义的运行设备信息附加到推理上下文中。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向上下文信息实例的[OH_AI_ContextHandle](#oh_ai_contexthandle)。 |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |


### OH_AI_ContextCreate()

```
OH_AI_API OH_AI_ContextHandle OH_AI_ContextCreate ()
```

**描述**

创建一个上下文的对象。注意：此接口需跟[OH_AI_ContextDestroy](#oh_ai_contextdestroy)配套使用。

**起始版本：** 9

**返回：**

指向上下文信息的[OH_AI_ContextHandle](#oh_ai_contexthandle)。


### OH_AI_ContextDestroy()

```
OH_AI_API void OH_AI_ContextDestroy (OH_AI_ContextHandle * context)
```

**描述**

释放上下文对象。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向[OH_AI_ContextHandle](#oh_ai_contexthandle)的二级指针，上下文销毁后会对context置为空指针。 |


### OH_AI_ContextGetEnableParallel()

```
OH_AI_API bool OH_AI_ContextGetEnableParallel (const OH_AI_ContextHandle context)
```

**描述**

获取是否支持算子间并行。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向上下文信息实例的[OH_AI_ContextHandle](#oh_ai_contexthandle)。 |

**返回：**

是否支持并行。true 为支持并行, false 为不支持并行。


### OH_AI_ContextGetThreadAffinityCoreList()

```
OH_AI_API const int32_t* OH_AI_ContextGetThreadAffinityCoreList (const OH_AI_ContextHandle context, size_t * core_num )
```

**描述**

获取CPU绑核列表。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向上下文信息实例的[OH_AI_ContextHandle](#oh_ai_contexthandle)。 |
| core_num | 该参数是输出参数，表示核的数量。 |

**返回：**

CPU绑核列表。此列表对象由[OH_AI_ContextHandle](#oh_ai_contexthandle)管理，调用者无须手动释放。


### OH_AI_ContextGetThreadAffinityMode()

```
OH_AI_API int OH_AI_ContextGetThreadAffinityMode (const OH_AI_ContextHandle context)
```

**描述**

获取运行时线程绑定CPU核心的策略。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向上下文信息实例的[OH_AI_ContextHandle](#oh_ai_contexthandle)。 |

**返回：**

绑核策略。一共有三种策略，0为不绑核, 1为大核优先, 2为中核优先。


### OH_AI_ContextGetThreadNum()

```
OH_AI_API int32_t OH_AI_ContextGetThreadNum (const OH_AI_ContextHandle context)
```

**描述**

获取线程数量。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向上下文信息实例的[OH_AI_ContextHandle](#oh_ai_contexthandle)。 |

**返回：**

当前的线程数量。


### OH_AI_ContextSetEnableParallel()

```
OH_AI_API void OH_AI_ContextSetEnableParallel (OH_AI_ContextHandle context, bool is_parallel )
```

**描述**

设置运行时是否支持并行。此接口特性当前未开启，设置无效。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向上下文信息实例的[OH_AI_ContextHandle](#oh_ai_contexthandle)。 |
| is_parallel | 是否支持并行。true 为支持并行, false 为不支持并行。 |


### OH_AI_ContextSetThreadAffinityCoreList()

```
OH_AI_API void OH_AI_ContextSetThreadAffinityCoreList (OH_AI_ContextHandle context, const int32_t * core_list, size_t core_num )
```

**描述**

设置运行时线程绑定CPU核心的列表。

例如：当core_list=[2,6,8]时，则线程会在CPU的第2,6,8个核心上运行。 如果对于同一个上下文对象，调用了[OH_AI_ContextSetThreadAffinityMode](#oh_ai_contextsetthreadaffinitymode)和[OH_AI_ContextSetThreadAffinityCoreList](#oh_ai_contextsetthreadaffinitycorelist) 这两个函数，则仅[OH_AI_ContextSetThreadAffinityCoreList](#oh_ai_contextsetthreadaffinitycorelist)的core_list参数生效，而[OH_AI_ContextSetThreadAffinityMode](#oh_ai_contextsetthreadaffinitymode)的 mode参数不生效。

**起始版本：** 9

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

**描述**

设置运行时线程绑定CPU核心的策略，按照CPU物理核频率分为大、中、小三种类型的核心，并且仅需绑大核或者绑中核，不需要绑小核。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向上下文信息实例的[OH_AI_ContextHandle](#oh_ai_contexthandle)。 |
| mode | 绑核策略。一共有三种策略，0为不绑核, 1为大核优先, 2为中核优先。 |


### OH_AI_ContextSetThreadNum()

```
OH_AI_API void OH_AI_ContextSetThreadNum (OH_AI_ContextHandle context, int32_t thread_num )
```

**描述**

设置运行时的线程数量。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| context | 指向上下文信息实例的[OH_AI_ContextHandle](#oh_ai_contexthandle) |
| thread_num | 运行时的线程数量。 |


### OH_AI_CreateNNRTDeviceInfoByName()

```
OH_AI_API OH_AI_DeviceInfoHandle OH_AI_CreateNNRTDeviceInfoByName (const char * name)
```

**描述**

查找指定名称的NNRt设备，根据找到的第一个设备信息，创建NNRt设备信息。

**起始版本：** 10

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| name | 目标NNRt设备名。 |

**返回：**

指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。


### OH_AI_CreateNNRTDeviceInfoByType()

```
OH_AI_API OH_AI_DeviceInfoHandle OH_AI_CreateNNRTDeviceInfoByType (OH_AI_NNRTDeviceType type)
```

**描述**

查找指定类型的NNRt设备，根据找到的第一个设备信息，创建NNRt设备信息。

**起始版本：** 10

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| type | [OH_AI_NNRTDeviceType](#oh_ai_nnrtdevicetype) 目标NNRt设备类型。 |

**返回：**

指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。


### OH_AI_DestroyAllNNRTDeviceDescs()

```
OH_AI_API void OH_AI_DestroyAllNNRTDeviceDescs (NNRTDeviceDesc ** desc)
```

**描述**

销毁从[OH_AI_GetAllNNRTDeviceDescs](#oh_ai_getallnnrtdevicedescs)获取的NNRt描写信息实例数组。

**起始版本：** 10

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| desc | 指向NNRt设备描述信息实例数组的二重指针。销毁结束，desc指向内容会被置为NULL。 |


### OH_AI_DeviceInfoAddExtension()

```
OH_AI_API OH_AI_Status OH_AI_DeviceInfoAddExtension (OH_AI_DeviceInfoHandle device_info, const char * name, const char * value, size_t value_size )
```

**描述**

向设备信息中添加键/值对形式的扩展配置。只对NNRt设备信息有效。

注意：当前仅支持{"CachePath": "YourCachePath"}，{"CacheVersion": "YouCacheVersion"}，{"QuantBuffer": "YourQuantBuffer"}，{"ModelName": "YourModelName"}，{"isProfiling": "YourisProfiling"}，{"opLayout": "YouropLayout"}，{"InputDims": "YourInputDims"}，{"DynamicDims": "YourDynamicDims"}，{"QuantConfigData": "YourQuantConfigData"}，{"BandMode": "YourBandMode"}，{"NPU_FM_SHARED": "YourNPU_FM_SHARED"} 11种键值对配置，用户根据使用情况替换具体的值。

**起始版本：** 10

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |
| name | 单个扩展项的键，格式为C字符串。 |
| value | 单个扩展项的值内容首地址。 |
| value_size | 单个扩展项的值内容长度。 |

**返回：**

[OH_AI_Status](#oh_ai_status) 执行状态码，若成功返回OH_AI_STATUS_SUCCESS，失败则返回具体错误码。


### OH_AI_DeviceInfoCreate()

```
OH_AI_API OH_AI_DeviceInfoHandle OH_AI_DeviceInfoCreate (OH_AI_DeviceType device_type)
```

**描述**

创建一个设备信息对象。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_type | 设备类型, 具体见[OH_AI_DeviceType](#oh_ai_devicetype)。 |

**返回：**

指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。


### OH_AI_DeviceInfoDestroy()

```
OH_AI_API void OH_AI_DeviceInfoDestroy (OH_AI_DeviceInfoHandle * device_info)
```

**描述**

释放设备信息实例。注意：设备信息实例被添加到context后，无须调用者手动释放。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |


### OH_AI_DeviceInfoGetDeviceId()

```
OH_AI_API size_t OH_AI_DeviceInfoGetDeviceId (const OH_AI_DeviceInfoHandle device_info)
```

**描述**

获取NNRt设备ID，仅NNRt设备可用。

**起始版本：** 10

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |

**返回：**

NNRt设备ID。


### OH_AI_DeviceInfoGetDeviceType()

```
OH_AI_API OH_AI_DeviceType OH_AI_DeviceInfoGetDeviceType (const OH_AI_DeviceInfoHandle device_info)
```

**描述**

获取设备的类型。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |

**返回：**

生产商设备类型。


### OH_AI_DeviceInfoGetEnableFP16()

```
OH_AI_API bool OH_AI_DeviceInfoGetEnableFP16 (const OH_AI_DeviceInfoHandle device_info)
```

**描述**

获取是否开启float16推理模式, 仅CPU/GPU设备可用。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |

**返回：**

设置是否开启float16推理模式。


### OH_AI_DeviceInfoGetFrequency()

```
OH_AI_API int OH_AI_DeviceInfoGetFrequency (const OH_AI_DeviceInfoHandle device_info)
```

**描述**

获取NPU的频率类型，仅NPU设备可用。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |

**返回：**

NPU的频率类型。取值范围为0-4，1表示低功耗，2表示平衡，3表示高性能，4表示超高性能。


### OH_AI_DeviceInfoGetPerformanceMode()

```
OH_AI_API OH_AI_PerformanceMode OH_AI_DeviceInfoGetPerformanceMode (const OH_AI_DeviceInfoHandle device_info)
```

**描述**

获取NNRt性能模式，仅NNRt设备可用。

**起始版本：** 10

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |

**返回：**

[OH_AI_PerformanceMode](#oh_ai_performancemode) NNRt性能模式。


### OH_AI_DeviceInfoGetPriority()

```
OH_AI_API OH_AI_Priority OH_AI_DeviceInfoGetPriority (const OH_AI_DeviceInfoHandle device_info)
```

**描述**

获取NNRt任务优先级，仅NNRt设备可用。

**起始版本：** 10

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |

**返回：**

[OH_AI_Priority](#oh_ai_priority) NNRt任务优先级。


### OH_AI_DeviceInfoGetProvider()

```
OH_AI_API const char* OH_AI_DeviceInfoGetProvider (const OH_AI_DeviceInfoHandle device_info)
```

**描述**

获取生产商的名称。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |

**返回：**

生产商的名称。


### OH_AI_DeviceInfoGetProviderDevice()

```
OH_AI_API const char* OH_AI_DeviceInfoGetProviderDevice (const OH_AI_DeviceInfoHandle device_info)
```

**描述**

获取生产商设备的名称。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |

**返回：**

生产商设备的名称。


### OH_AI_DeviceInfoSetDeviceId()

```
OH_AI_API void OH_AI_DeviceInfoSetDeviceId (OH_AI_DeviceInfoHandle device_info, size_t device_id )
```

**描述**

设置NNRt设备ID，仅NNRt设备可用。

**起始版本：** 10

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |
| device_id | NNRt设备ID。 |


### OH_AI_DeviceInfoSetEnableFP16()

```
OH_AI_API void OH_AI_DeviceInfoSetEnableFP16 (OH_AI_DeviceInfoHandle device_info, bool is_fp16 )
```

**描述**

设置是否开启float16推理模式，仅CPU/GPU设备可用。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |
| is_fp16 | 是否开启float16推理模式。 |


### OH_AI_DeviceInfoSetFrequency()

```
OH_AI_API void OH_AI_DeviceInfoSetFrequency (OH_AI_DeviceInfoHandle device_info, int frequency )
```

**描述**

设置NPU的频率，仅NPU设备可用。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |
| frequency | 频率类型，取值范围为0-4，默认是3。1表示低功耗，2表示平衡，3表示高性能，4表示超高性能。 |


### OH_AI_DeviceInfoSetPerformanceMode()

```
OH_AI_API void OH_AI_DeviceInfoSetPerformanceMode (OH_AI_DeviceInfoHandle device_info, OH_AI_PerformanceMode mode )
```

**描述**

设置NNRt性能模式，仅NNRt设备可用。

**起始版本：** 10

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |
| mode | [OH_AI_PerformanceMode](#oh_ai_performancemode) NNRt性能模式。 |


### OH_AI_DeviceInfoSetPriority()

```
OH_AI_API void OH_AI_DeviceInfoSetPriority (OH_AI_DeviceInfoHandle device_info, OH_AI_Priority priority )
```

**描述**

设置NNRt任务优先级，仅NNRt设备可用。

**起始版本：** 10

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |
| priority | [OH_AI_Priority](#oh_ai_priority) NNRt任务优先级。 |


### OH_AI_DeviceInfoSetProvider()

```
OH_AI_API void OH_AI_DeviceInfoSetProvider (OH_AI_DeviceInfoHandle device_info, const char * provider )
```

**描述**

设置生产商的名称。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |
| provider | 生产商的名称。 |


### OH_AI_DeviceInfoSetProviderDevice()

```
OH_AI_API void OH_AI_DeviceInfoSetProviderDevice (OH_AI_DeviceInfoHandle device_info, const char * device )
```

**描述**

设置生产商设备的名称。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| device_info | 指向设备信息实例的[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)。 |
| device | 生产商设备名称。例如: CPU。 |


### OH_AI_ExportModel()

```
OH_AI_API OH_AI_Status OH_AI_ExportModel (OH_AI_ModelHandle model, OH_AI_ModelType model_type, const char * model_file, OH_AI_QuantizationType quantization_type, bool export_inference_only, char ** output_tensor_name, size_t num )
```

**描述**

导出训练模型，仅用于端侧训练。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| model_type | 模型文件类型，具体见[OH_AI_ModelType](#oh_ai_modeltype)。 |
| model_file | 导出的模型文件路径。 |
| quantization_type | 量化类型。 |
| export_inference_only | 是否导出推理模型。 |
| output_tensor_name | 设置导出模型的输出Tensor，默认为空表示全量导出。 |
| num | 输出Tensor的数量。 |

**返回：**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回OH_AI_Status::OH_AI_STATUS_SUCCESS则证明创建成功。

### OH_AI_ExportModelBuffer()

```
OH_AI_API OH_AI_Status OH_AI_ExportModelBuffer (OH_AI_ModelHandle model, OH_AI_ModelType model_type, char ** model_data, size_t * data_size, OH_AI_QuantizationType quantization_type, bool export_inference_only, char ** output_tensor_name, size_t num )
```
**描述**
导出训练模型内存缓存，仅用于端侧训练。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。  |
| model_type | 模型文件类型，具体见[OH_AI_ModelType](#oh_ai_modeltype)。  |
| model_data | 指向导出模型文件缓冲区的指针。  |
| data_size | 缓冲区大小。  |
| quantization_type | 量化类型。  |
| export_inference_only | 是否导出推理模型。  |
| output_tensor_name | 设置导出模型的输出Tensor，默认为空表示全量导出。  |
| num | 输出Tensor的数量。  |

**返回：**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回OH_AI_Status::OH_AI_STATUS_SUCCESS则证明创建成功。


### OH_AI_ExportWeightsCollaborateWithMicro()

```
OH_AI_API OH_AI_Status OH_AI_ExportWeightsCollaborateWithMicro (OH_AI_ModelHandle model, OH_AI_ModelType model_type, const char * weight_file, bool is_inference, bool enable_fp16, char ** changeable_weights_name, size_t num )
```

**描述**

导出模型权重,只能用于micro推理，仅用于端侧训练。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| model_type | 模型文件类型，具体见[OH_AI_ModelType](#oh_ai_modeltype)。 |
| weight_file | 导出的权重文件路径。 |
| is_inference | 是否导出推理模型，当前只支持设置为true。 |
| enable_fp16 | 浮点权重是否保存为float16格式。 |
| changeable_weights_name | shape可变的权重Tensor名称。 |
| num | shape可变的权重Tensor名称的数量。 |

**返回：**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回OH_AI_Status::OH_AI_STATUS_SUCCESS则证明创建成功。


### OH_AI_GetAllNNRTDeviceDescs()

```
OH_AI_API NNRTDeviceDesc* OH_AI_GetAllNNRTDeviceDescs (size_t * num)
```

**描述**

获取系统中所有NNRt硬件设备的描述信息。

**起始版本：** 10

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| num | 输出参数，返回设备数量。 |

**返回：**

指向NNRt设备描述信息实例数组的指针。当获取失败时，返回NULL。


### OH_AI_GetDeviceIdFromNNRTDeviceDesc()

```
OH_AI_API size_t OH_AI_GetDeviceIdFromNNRTDeviceDesc (const NNRTDeviceDesc * desc)
```

**描述**

从特定的NNRt设备描述信息实例获取NNRt设备ID。注意，此ID只对NNRt有效。

**起始版本：** 10

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| desc | 指向NNRt设备描述信息实例的指针。 |

**返回：**

NNRt设备ID。


### OH_AI_GetElementOfNNRTDeviceDescs()

```
OH_AI_API NNRTDeviceDesc* OH_AI_GetElementOfNNRTDeviceDescs (NNRTDeviceDesc * descs, size_t index )
```

**描述**

获取NNRt设备描述信息数组中的元素指针。

**起始版本：** 10

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| descs | NNRt设备描述信息数组。 |
| index | 数组元素索引。 |

**返回：**

NNRt设备描述信息类型指针。


### OH_AI_GetNameFromNNRTDeviceDesc()

```
OH_AI_API const char* OH_AI_GetNameFromNNRTDeviceDesc (const NNRTDeviceDesc * desc)
```

**描述**

从特定的NNRt设备描述信息实例获取NNRt设备名称。

**起始版本：** 10

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| desc | 指向NNRt设备描述信息实例的指针。 |

**返回：**

NNRt设备名称，指向一个常量字符串的指针，该常量字符串由desc持有，调用者无需单独释放此指针。


### OH_AI_GetTypeFromNNRTDeviceDesc()

```
OH_AI_API OH_AI_NNRTDeviceType OH_AI_GetTypeFromNNRTDeviceDesc (const NNRTDeviceDesc * desc)
```

**描述**

从特定的NNRt设备描述信息实例获取NNRt设备类型。

**起始版本：** 10

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| desc | 指向NNRt设备描述信息实例的指针。 |

**返回：**

[OH_AI_NNRTDeviceType](#oh_ai_nnrtdevicetype) NNRt设备类型。


### OH_AI_ModelBuild()

```
OH_AI_API OH_AI_Status OH_AI_ModelBuild (OH_AI_ModelHandle model, const void * model_data, size_t data_size, OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context )
```

**描述**

从内存缓冲区加载并编译MindSpore模型。

注意，同一个[OH_AI_ContextHandle](#oh_ai_contexthandle)对象仅能传递给[OH_AI_ModelBuild](#oh_ai_modelbuild)或者[OH_AI_ModelBuildFromFile](#oh_ai_modelbuildfromfile)一次， 如果多次调用该函数需要创建多个不同的[OH_AI_ContextHandle](#oh_ai_contexthandle)。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| model_data | 内存中已经加载的模型数据地址。 |
| data_size | 模型数据的长度。 |
| model_type | 模型文件类型，具体见[OH_AI_ModelType](#oh_ai_modeltype)。 |
| model_context | 模型运行时的上下文环境，具体见 [OH_AI_ContextHandle](#oh_ai_contexthandle)。 |

**返回：**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回OH_AI_Status::OH_AI_STATUS_SUCCESS则证明创建成功。


### OH_AI_ModelBuildFromFile()

```
OH_AI_API OH_AI_Status OH_AI_ModelBuildFromFile (OH_AI_ModelHandle model, const char * model_path, OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context )
```

**描述**

通过模型文件加载并编译MindSpore模型。

注意，同一个[OH_AI_ContextHandle](#oh_ai_contexthandle)对象仅能传递给[OH_AI_ModelBuild](#oh_ai_modelbuild)或者[OH_AI_ModelBuildFromFile](#oh_ai_modelbuildfromfile)一次， 如果多次调用该函数需要创建多个不同的[OH_AI_ContextHandle](#oh_ai_contexthandle)。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| model_path | 模型文件路径。 |
| model_type | 模型文件类型，具体见[OH_AI_ModelType](#oh_ai_modeltype)。 |
| model_context | 模型运行时的上下文环境，具体见 [OH_AI_ContextHandle](#oh_ai_contexthandle)。 |

**返回：**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回OH_AI_Status::OH_AI_STATUS_SUCCESS则证明创建成功。


### OH_AI_ModelCreate()

```
OH_AI_API OH_AI_ModelHandle OH_AI_ModelCreate ()
```

**描述**

创建一个模型对象。

**起始版本：** 9

**返回：**

模型对象指针。


### OH_AI_ModelDestroy()

```
OH_AI_API void OH_AI_ModelDestroy (OH_AI_ModelHandle * model)
```

**描述**

释放一个模型对象。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |


### OH_AI_ModelGetInputByTensorName()

```
OH_AI_API OH_AI_TensorHandle OH_AI_ModelGetInputByTensorName (const OH_AI_ModelHandle model, const char * tensor_name )
```

**描述**

通过张量名获取模型的输入张量。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| tensor_name | 张量名称。 |

**返回：**

tensor_name所对应的输入张量的张量指针，如果输入中没有该张量则返回空。


### OH_AI_ModelGetInputs()

```
OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetInputs (const OH_AI_ModelHandle model)
```

**描述**

获取模型的输入张量数组结构体。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |

**返回：**

模型输入对应的张量数组结构体。


### OH_AI_ModelGetLearningRate()

```
OH_AI_API float OH_AI_ModelGetLearningRate (OH_AI_ModelHandle model)
```

**描述**

获取训练的学习率，仅用于端侧训练。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |

**返回：**

学习率，没有设置优化器时为0.0。


### OH_AI_ModelGetOutputByTensorName()

```
OH_AI_API OH_AI_TensorHandle OH_AI_ModelGetOutputByTensorName (const OH_AI_ModelHandle model, const char * tensor_name )
```

**描述**

通过张量名获取模型的输出张量。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| tensor_name | 张量名称。 |

**返回：**

tensor_name所对应的输入张量的张量指针，如果输出中没有该张量则返回空。


### OH_AI_ModelGetOutputs()

```
OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetOutputs (const OH_AI_ModelHandle model)
```

**描述**

获取模型的输出张量数组结构体。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |

**返回：**

模型输出对应的张量数组结构体。


### OH_AI_ModelGetTrainMode()

```
OH_AI_API bool OH_AI_ModelGetTrainMode (OH_AI_ModelHandle model)
```

**描述**

获取训练模式。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |

**返回：**

表示是否是训练模式。


### OH_AI_ModelGetWeights()

```
OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetWeights (OH_AI_ModelHandle model)
```

**描述**

获取模型的所有权重Tensors，仅用于端侧训练。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |

**返回：**

模型的所有权重Tensor。


### OH_AI_ModelPredict()

```
OH_AI_API OH_AI_Status OH_AI_ModelPredict (OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs, OH_AI_TensorHandleArray * outputs, const OH_AI_KernelCallBack before, const OH_AI_KernelCallBack after )
```

**描述**

执行模型推理。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| inputs | 模型输入对应的张量数组结构体。 |
| outputs | 模型输出对应的张量数组结构体的指针。 |
| before | 模型推理前执行的回调函数。 |
| after | 模型推理后执行的回调函数。 |

**返回：**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回OH_AI_Status::OH_AI_STATUS_SUCCESS则证明创建成功。


### OH_AI_ModelResize()

```
OH_AI_API OH_AI_Status OH_AI_ModelResize (OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs, OH_AI_ShapeInfo * shape_infos, size_t shape_info_num )
```

**描述**

调整已编译模型的输入形状。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| inputs | 模型输入对应的张量数组结构体。 |
| shape_infos | 输入形状信息数组，按模型输入顺序排列的由形状信息组成的数组，模型会按顺序依次调整张量形状。 |
| shape_info_num | 形状信息数组的长度。 |

**返回：**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回OH_AI_Status::OH_AI_STATUS_SUCCESS则证明创建成功。


### OH_AI_ModelSetLearningRate()

```
OH_AI_API OH_AI_Status OH_AI_ModelSetLearningRate (OH_AI_ModelHandle model, float learning_rate )
```

**描述**

设置训练的学习率，仅用于端侧训练。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| learning_rate | 学习率 |

**返回：**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回OH_AI_Status::OH_AI_STATUS_SUCCESS则证明创建成功。


### OH_AI_ModelSetTrainMode()

```
OH_AI_API OH_AI_Status OH_AI_ModelSetTrainMode (OH_AI_ModelHandle model, bool train )
```

**描述**

设置训练模式，仅用于端侧训练。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| train | 是否为训练模式。 |

**返回：**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回OH_AI_Status::OH_AI_STATUS_SUCCESS则证明创建成功。


### OH_AI_ModelSetupVirtualBatch()

```
OH_AI_API OH_AI_Status OH_AI_ModelSetupVirtualBatch (OH_AI_ModelHandle model, int virtual_batch_multiplier, float lr, float momentum )
```

**描述**

设置虚拟batch用于训练，仅用于端侧训练。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| virtual_batch_multiplier | 虚拟batch乘法器，当设置值小于1时，表示禁用虚拟batch。 |
| lr | 学习率，默认为-1.0f。 |
| momentum | 动量，默认为-1.0f。 |

**返回：**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回OH_AI_Status::OH_AI_STATUS_SUCCESS则证明创建成功。


### OH_AI_ModelUpdateWeights()

```
OH_AI_API OH_AI_Status OH_AI_ModelUpdateWeights (OH_AI_ModelHandle model, const OH_AI_TensorHandleArray new_weights )
```

**描述**

更新模型的权重Tensor内容，仅用于端侧训练。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| new_weights | 要更新的权重Tensor。 |

**返回：**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回OH_AI_Status::OH_AI_STATUS_SUCCESS则证明创建成功。


### OH_AI_RunStep()

```
OH_AI_API OH_AI_Status OH_AI_RunStep (OH_AI_ModelHandle model, const OH_AI_KernelCallBack before, const OH_AI_KernelCallBack after )
```

**描述**

单步训练模型，仅用于端侧训练。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| before | 模型推理前执行的回调函数。 |
| after | 模型推理后执行的回调函数。 |

**返回：**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回OH_AI_Status::OH_AI_STATUS_SUCCESS则证明创建成功。


### OH_AI_TensorClone()

```
OH_AI_API OH_AI_TensorHandle OH_AI_TensorClone (OH_AI_TensorHandle tensor)
```

**描述**

深拷贝一个张量。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 待拷贝张量的指针。 |

**返回：**

指向新张量对象句柄。


### OH_AI_TensorCreate()

```
OH_AI_API OH_AI_TensorHandle OH_AI_TensorCreate (const char * name, OH_AI_DataType type, const int64_t * shape, size_t shape_num, const void * data, size_t data_len )
```

**描述**

创建一个张量对象。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| name | 张量名称 |
| type | 张量的数据类型 |
| shape | 张量的维度数组。 |
| shape_num | 张量维度数组长度。 |
| data | 指向数据的指针。 |
| data_len | 数据的长度。 |

**返回：**

指向张量对象句柄。

### OH_AI_TensorGetAllocator()

```
OH_AI_API OH_AI_AllocatorHandle OH_AI_TensorGetAllocator(OH_AI_TensorHandle tensor)
```

**描述**

获取内存分配器。此接口主要是提供一种获取张量的内存分配器的方法。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |

**返回：**

内存分配器的句柄。


### OH_AI_TensorDestroy()

```
OH_AI_API void OH_AI_TensorDestroy (OH_AI_TensorHandle * tensor)
```

**描述**

释放张量对象。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 指向张量句柄的二级指针。 |


### OH_AI_TensorGetData()

```
OH_AI_API const void* OH_AI_TensorGetData (const OH_AI_TensorHandle tensor)
```

**描述**

获取张量数据的指针。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |

**返回：**

张量数据的指针。


### OH_AI_TensorGetDataSize()

```
OH_AI_API size_t OH_AI_TensorGetDataSize (const OH_AI_TensorHandle tensor)
```

**描述**

获取张量中的数据的字节数大小。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |

**返回：**

张量数据的字节数大小。


### OH_AI_TensorGetDataType()

```
OH_AI_API OH_AI_DataType OH_AI_TensorGetDataType (const OH_AI_TensorHandle tensor)
```

**描述**

获取张量类型。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |

**返回：**

张量的数据类型。


### OH_AI_TensorGetElementNum()

```
OH_AI_API int64_t OH_AI_TensorGetElementNum (const OH_AI_TensorHandle tensor)
```

**描述**

获取张量元素数量。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |

**返回：**

张量的元素数量。


### OH_AI_TensorGetFormat()

```
OH_AI_API OH_AI_Format OH_AI_TensorGetFormat (const OH_AI_TensorHandle tensor)
```

**描述**

获取张量数据的排列方式。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |

**返回：**

张量数据的排列方式。


### OH_AI_TensorGetMutableData()

```
OH_AI_API void* OH_AI_TensorGetMutableData (const OH_AI_TensorHandle tensor)
```

**描述**

获取可变的张量数据指针。如果数据为空则会开辟内存。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |

**返回：**

张量数据的指针。


### OH_AI_TensorGetName()

```
OH_AI_API const char* OH_AI_TensorGetName (const OH_AI_TensorHandle tensor)
```

**描述**

获取张量的名称。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |

**返回：**

张量的名称。


### OH_AI_TensorGetShape()

```
OH_AI_API const int64_t* OH_AI_TensorGetShape (const OH_AI_TensorHandle tensor, size_t * shape_num )
```

**描述**

获取张量的形状。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |
| shape_num | 该参数是输出参数，形状数组的长度会写入该变量。 |

**返回：**

形状数组。

### OH_AI_TensorSetAllocator()

```
OH_AI_API OH_AI_Status OH_AI_TensorSetAllocator(OH_AI_TensorHandle tensor, OH_AI_AllocatorHandle allocator)
```

**描述**

设置内存分配器。此接口主要是提供一种设置内存分配器的方法，tensor的内存将由这个分配器分配。

**起始版本：** 12

**参数:**

| 名称      | 描述                 |
| --------- | -------------------- |
| tensor    | 张量对象句柄。       |
| allocator | 内存分配器对象句柄。 |

**返回：**

执行状态码。若成功返回OH_AI_STATUS_SUCCESS，否则返回具体错误码。


### OH_AI_TensorSetData()

```
OH_AI_API void OH_AI_TensorSetData (OH_AI_TensorHandle tensor, void * data )
```

**描述**

设置张量的数据。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |
| data | 指向数据的指针。 |


### OH_AI_TensorSetDataType()

```
OH_AI_API void OH_AI_TensorSetDataType (OH_AI_TensorHandle tensor, OH_AI_DataType type )
```

**描述**

设置张量的数据类型。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |
| type | 数据类型，具体见[OH_AI_DataType](#oh_ai_datatype)。 |


### OH_AI_TensorSetFormat()

```
OH_AI_API void OH_AI_TensorSetFormat (OH_AI_TensorHandle tensor, OH_AI_Format format )
```

**描述**

设置张量数据的排列方式。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |
| format | 张量数据排列方式。 |


### OH_AI_TensorSetName()

```
OH_AI_API void OH_AI_TensorSetName (OH_AI_TensorHandle tensor, const char * name )
```

**描述**

设置张量的名称。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |
| name | 张量名称。 |


### OH_AI_TensorSetShape()

```
OH_AI_API void OH_AI_TensorSetShape (OH_AI_TensorHandle tensor, const int64_t * shape, size_t shape_num )
```

**描述**

设置张量的形状。

**起始版本：** 9

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |
| shape | 形状数组。 |
| shape_num | 张量形状数组长度。 |


### OH_AI_TensorSetUserData()

```
OH_AI_API OH_AI_Status OH_AI_TensorSetUserData (OH_AI_TensorHandle tensor, void * data, size_t data_size )
```

**描述**

设置张量为用户自行管理的数据。此接口常用于复用用户数据作为模型输入，可减少一次数据拷贝。 注意：此数据对于张量来说是外部数据，张量销毁时不会主动释放，由调用者负责释放。另外，在此张量 使用过程中，调用者须确保此数据有效。

**起始版本：** 10

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| tensor | 张量对象句柄。 |
| data | 用户数据首地址。 |
| data_size | 用户数据长度。 |

**返回：**

执行状态码。若成功返回OH_AI_STATUS_SUCCESS，否则返回具体错误码。


### OH_AI_TrainCfgCreate()

```
OH_AI_API OH_AI_TrainCfgHandle OH_AI_TrainCfgCreate ()
```

**描述**

创建训练配置对象指针，仅用于端侧训练。

**起始版本：** 11

**返回：**

训练配置对象指针。


### OH_AI_TrainCfgDestroy()

```
OH_AI_API void OH_AI_TrainCfgDestroy (OH_AI_TrainCfgHandle * train_cfg)
```

**描述**

销毁训练配置对象指针，仅用于端侧训练。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| train_cfg | 训练配置对象指针。 |


### OH_AI_TrainCfgGetLossName()

```
OH_AI_API char** OH_AI_TrainCfgGetLossName (OH_AI_TrainCfgHandle train_cfg, size_t * num )
```

**描述**

获取损失函数的名称列表，仅用于端侧训练。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| train_cfg | 训练配置对象指针。 |
| num | 损失函数数量。 |

**返回：**

损失函数的名称列表。


### OH_AI_TrainCfgGetOptimizationLevel()

```
OH_AI_API OH_AI_OptimizationLevel OH_AI_TrainCfgGetOptimizationLevel (OH_AI_TrainCfgHandle train_cfg)
```

**描述**

获取训练配置的优化等级，仅用于端侧训练。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| train_cfg | 训练配置对象指针。 |

**返回：**

优化等级。


### OH_AI_TrainCfgSetLossName()

```
OH_AI_API void OH_AI_TrainCfgSetLossName (OH_AI_TrainCfgHandle train_cfg, const char ** loss_name, size_t num )
```

**描述**

设置损失函数的名称列表，仅用于端侧训练。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| train_cfg | 训练配置对象指针。 |
| loss_name | 损失函数的名称列表。 |
| num | 损失函数数量。 |


### OH_AI_TrainCfgSetOptimizationLevel()

```
OH_AI_API void OH_AI_TrainCfgSetOptimizationLevel (OH_AI_TrainCfgHandle train_cfg, OH_AI_OptimizationLevel level )
```

**描述**

设置训练配置的优化等级，仅用于端侧训练。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| train_cfg | 训练配置对象指针。 |
| level | 优化等级。 |


### OH_AI_TrainModelBuild()

```
OH_AI_API OH_AI_Status OH_AI_TrainModelBuild (OH_AI_ModelHandle model, const void * model_data, size_t data_size, OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context, const OH_AI_TrainCfgHandle train_cfg )
```

**描述**

从内存缓冲区加载训练模型，并将模型编译至可在Device上运行的状态，仅用于端侧训练。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| model_data | 指向存储读入模型文件缓冲区的指针。 |
| data_size | 缓冲区大小。 |
| model_type | 模型文件类型，具体见[OH_AI_ModelType](#oh_ai_modeltype)。 |
| model_context | 模型运行时的上下文环境，具体见 [OH_AI_ContextHandle](#oh_ai_contexthandle)。 |
| train_cfg | 训练配置对象指针。 |

**返回：**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回OH_AI_Status::OH_AI_STATUS_SUCCESS则证明创建成功。


### OH_AI_TrainModelBuildFromFile()

```
OH_AI_API OH_AI_Status OH_AI_TrainModelBuildFromFile (OH_AI_ModelHandle model, const char * model_path, OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context, const OH_AI_TrainCfgHandle train_cfg )
```

**描述**

根据路径读取加载训练模型，并将模型编译至可在Device上运行的状态，仅用于端侧训练。

**起始版本：** 11

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| model | 模型对象指针。 |
| model_path | 模型文件路径。 |
| model_type | 模型文件类型，具体见[OH_AI_ModelType](#oh_ai_modeltype)。 |
| model_context | 模型运行时的上下文环境，具体见 [OH_AI_ContextHandle](#oh_ai_contexthandle)。 |
| train_cfg | 训练配置对象指针。 |

**返回：**

枚举类型的状态码[OH_AI_Status](#oh_ai_status)，若返回OH_AI_Status::OH_AI_STATUS_SUCCESS则证明创建成功。
