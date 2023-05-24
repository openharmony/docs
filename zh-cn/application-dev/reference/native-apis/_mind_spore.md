# MindSpore


## 概述

提供MindSpore Lite的模型推理相关接口。

\@Syscap SystemCapability.Ai.MindSpore

**起始版本：**

9


## 汇总


### 文件

| 名称                            | 描述                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| [context.h](context_8h.md)      | 提供了Context相关的接口，可以配置运行时信息。<br>引用文件：\<mindspore/context.h> |
| [data_type.h](data__type_8h.md) | 声明了张量的数据的类型。<br>引用文件：\<mindspore/data_type.h> |
| [format.h](format_8h.md)        | 提供张量数据的排列格式。<br>引用文件：\<mindspore/format.h>  |
| [model.h](model_8h.md)          | 提供了模型相关接口，可以用于模型创建、模型推理等。<br>引用文件：\<mindspore/model.h> |
| [status.h](status_8h.md)        | 提供了Mindspore Lite运行时的状态码。<br>引用文件：\<mindspore/status.h> |
| [tensor.h](tensor_8h.md)        | 提供了张量相关的接口，可用于创建和修改张量信息。<br>引用文件：\<mindspore/tensor.h> |
| [types.h](types_8h.md)          | 提供了MindSpore Lite支持的模型文件类型和设备类型。<br>引用文件：\<mindspore/types.h> |


### 结构体

| 名称                                                         | 描述                                                 |
| ------------------------------------------------------------ | ---------------------------------------------------- |
| [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) | 张量数组结构体，用于存储张量数组指针和张量数组长度。 |
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md)                | 维度信息，最大的维度为**MS_MAX_SHAPE_NUM**。         |
| [OH_AI_CallBackParam](_o_h___a_i___call_back_param.md)       | 回调函数中传入的算子信息。                           |


### 宏定义

| 名称                                             | 描述                                         |
| ------------------------------------------------ | -------------------------------------------- |
| [OH_AI_MAX_SHAPE_NUM](#oh_ai_max_shape_num)   32 | 张量维度的最大值。 |


### 类型定义

| 名称                                                         | 描述                                               |
| ------------------------------------------------------------ | -------------------------------------------------- |
| [OH_AI_ContextHandle](#oh_ai_contexthandle)                  | Mindspore的上下文信息的指针，该指针会指向Context。 |
| [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle)            | Mindspore的运行设备信息的指针。                    |
| [OH_AI_DataType](#oh_ai_datatype)                            | MSTensor保存的数据支持的类型。                     |
| [OH_AI_Format](#oh_ai_format)                                | MSTensor保存的数据支持的排列格式。                 |
| [OH_AI_ModelHandle](#oh_ai_modelhandle)                      | 指向模型对象的指针。                               |
| [OH_AI_TensorHandleArray](#oh_ai_tensorhandlearray)          | 张量数组结构体，用于存储张量数组指针和张量数组长度 |
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md)                | 维度信息，最大的维度为MS_MAX_SHAPE_NUM。           |
| [OH_AI_CallBackParam](#oh_ai_callbackparam)                  | 回调函数中传入的算子信息。                         |
| [OH_AI_KernelCallBack](#oh_ai_kernelcallback)) (const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) outputs, const [OH_AI_CallBackParam](_o_h___a_i___call_back_param.md) kernel_Info) | 回调函数指针。                                     |
| [OH_AI_Status](#oh_ai_status)                                | Minspore的状态码。                                 |
| [OH_AI_TensorHandle](#oh_ai_tensorhandle)                    | 指向张量对象句柄。                                 |
| [OH_AI_ModelType](#oh_ai_modeltype)                          | 模型文件的类型。                                   |
| [OH_AI_DeviceType](#oh_ai_devicetype)                        | 设备类型信息，包含了目前支持的设备类型。           |
| [OH_AI_NNRTDeviceType](#oh_ai_nnrtdevicetype)                | NNRT管理的硬件设备类型                             |
| [OH_AI_PerformanceMode](#oh_ai_performancemode)              | NNRT硬件的工作性能模式                             |
| [OH_AI_Priority](#oh_ai_priority)                            | NNRT推理任务优先级                                 |
| [NNRTDeviceDesc](#nnrtdevicedesc)                            | NNRT设备信息描述，包含设备ID，设备名称等信息。     |


### 枚举

| 名称                                                         | 描述                                     |
| ------------------------------------------------------------ | ---------------------------------------- |
| [OH_AI_DataType](#oh_ai_datatype-1) {<br/>OH_AI_DATATYPE_UNKNOWN = 0, <br/>OH_AI_DATATYPE_OBJECTTYPE_STRING = 12, <br/>OH_AI_DATATYPE_OBJECTTYPE_LIST = 13, <br/>OH_AI_DATATYPE_OBJECTTYPE_TUPLE = 14,<br/>OH_AI_DATATYPE_OBJECTTYPE_TENSOR = 17, <br/>OH_AI_DATATYPE_NUMBERTYPE_BEGIN = 29,<br/> OH_AI_DATATYPE_NUMBERTYPE_BOOL = 30,<br/> OH_AI_DATATYPE_NUMBERTYPE_INT8 = 32,<br/>OH_AI_DATATYPE_NUMBERTYPE_INT16 = 33, <br/>OH_AI_DATATYPE_NUMBERTYPE_INT32 = 34, <br/>OH_AI_DATATYPE_NUMBERTYPE_INT64 = 35, <br/>OH_AI_DATATYPE_NUMBERTYPE_UINT8 = 37,<br/>OH_AI_DATATYPE_NUMBERTYPE_UINT16 = 38, <br/>OH_AI_DATATYPE_NUMBERTYPE_UINT32 = 39,<br/> OH_AI_DATATYPE_NUMBERTYPE_UINT64 = 40, <br/>OH_AI_DATATYPE_NUMBERTYPE_FLOAT16 = 42,<br/>OH_AI_DATATYPE_NUMBERTYPE_FLOAT32 = 43, <br/>OH_AI_DATATYPE_NUMBERTYPE_FLOAT64 = 44, <br/>OH_AI_DATATYPE_NUMBERTYPE_END = 46,<br/> OH_AI_DataTypeInvalid = INT32_MAX<br/>} | MSTensor保存的数据支持的类型。           |
| [OH_AI_Format](#oh_ai_format-1) {<br/>OH_AI_FORMAT_NCHW = 0,<br/> OH_AI_FORMAT_NHWC = 1, <br/>OH_AI_FORMAT_NHWC4 = 2, <br/>OH_AI_FORMAT_HWKC = 3,<br/>OH_AI_FORMAT_HWCK = 4, <br/>OH_AI_FORMAT_KCHW = 5, <br/>OH_AI_FORMAT_CKHW = 6,<br/> OH_AI_FORMAT_KHWC = 7,<br/>OH_AI_FORMAT_CHWK = 8,<br/> OH_AI_FORMAT_HW = 9, <br/>OH_AI_FORMAT_HW4 = 10,<br/> OH_AI_FORMAT_NC = 11,<br/>OH_AI_FORMAT_NC4 = 12, <br/>OH_AI_FORMAT_NC4HW4 = 13, <br/>OH_AI_FORMAT_NCDHW = 15,<br/> OH_AI_FORMAT_NWC = 16,<br/>OH_AI_FORMAT_NCW = 17<br/>} | MSTensor保存的数据支持的排列格式。       |
| [OH_AI_CompCode](#oh_ai_compcode) { <br/>OH_AI_COMPCODE_CORE = 0x00000000u, <br/>OH_AI_COMPCODE_LITE = 0xF0000000u<br/> } | Minspore不同组件的代码。                 |
| [OH_AI_Status](#oh_ai_status-1) {<br/>OH_AI_STATUS_SUCCESS = 0, OH_AI_STATUS_CORE_FAILED = OH_AI_COMPCODE_CORE \| 0x1, OH_AI_STATUS_LITE_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -1), OH_AI_STATUS_LITE_NULLPTR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -2),<br/>OH_AI_STATUS_LITE_PARAM_INVALID = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -3), OH_AI_STATUS_LITE_NO_CHANGE = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -4), OH_AI_STATUS_LITE_SUCCESS_EXIT = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -5), OH_AI_STATUS_LITE_MEMORY_FAILED = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -6),<br/>OH_AI_STATUS_LITE_NOT_SUPPORT = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -7), OH_AI_STATUS_LITE_THREADPOOL_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -8), OH_AI_STATUS_LITE_UNINITIALIZED_OBJ = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -9), OH_AI_STATUS_LITE_OUT_OF_TENSOR_RANGE = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -100),<br/>OH_AI_STATUS_LITE_INPUT_TENSOR_ERROR, OH_AI_STATUS_LITE_REENTRANT_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -102), OH_AI_STATUS_LITE_GRAPH_FILE_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -200), OH_AI_STATUS_LITE_NOT_FIND_OP = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -300),<br/>OH_AI_STATUS_LITE_INVALID_OP_NAME = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -301), OH_AI_STATUS_LITE_INVALID_OP_ATTR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -302), OH_AI_STATUS_LITE_OP_EXECUTE_FAILURE, OH_AI_STATUS_LITE_FORMAT_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -400),<br/>OH_AI_STATUS_LITE_INFER_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -500), OH_AI_STATUS_LITE_INFER_INVALID, OH_AI_STATUS_LITE_INPUT_PARAM_INVALID<br/>} | Minspore的状态码。                       |
| [OH_AI_ModelType](#oh_ai_modeltype-1) { <br/>OH_AI_MODELTYPE_MINDIR = 0, <br/>OH_AI_MODELTYPE_INVALID = 0xFFFFFFFF <br/>} | 模型文件的类型。                         |
| [OH_AI_DeviceType](#oh_ai_devicetype-1) {<br/>OH_AI_DEVICETYPE_CPU = 0, <br/>OH_AI_DEVICETYPE_GPU, <br/>OH_AI_DEVICETYPE_KIRIN_NPU, <br/>OH_AI_DEVICETYPE_NNRT = 60,<br/>OH_AI_DEVICETYPE_INVALID = 100<br/>} | 设备类型信息，包含了目前支持的设备类型。 |
| [OH_AI_NNRTDeviceType](#oh_ai_nnrtdevicetype-1) { <br/>OH_AI_NNRTDEVICE_OTHERS = 0, <br/>OH_AI_NNRTDEVICE_CPU = 1, <br/>OH_AI_NNRTDEVICE_GPU = 2, <br/>OH_AI_NNRTDEVICE_ACCELERATOR = 3<br/> } | NNRT管理的硬件设备类型。                 |
| [OH_AI_PerformanceMode](#oh_ai_performancemode-1) {<br/>OH_AI_PERFORMANCE_NONE = 0, <br/>OH_AI_PERFORMANCE_LOW = 1, <br/>OH_AI_PERFORMANCE_MEDIUM = 2,<br/> OH_AI_PERFORMANCE_HIGH = 3,<br/>OH_AI_PERFORMANCE_EXTREME = 4<br/>} | NNRT硬件的工作性能模式。                 |
| [OH_AI_Priority](#oh_ai_priority-1) { <br/>OH_AI_PRIORITY_NONE = 0, <br/>OH_AI_PRIORITY_LOW = 1, <br/>OH_AI_PRIORITY_MEDIUM = 2, <br/>OH_AI_PRIORITY_HIGH = 3 <br/>} | NNRT推理任务优先级。                     |


### 函数

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_AI_ContextCreate](#oh_ai_contextcreate) ()               | 创建一个上下文的对象。                                       |
| [OH_AI_ContextDestroy](#oh_ai_contextdestroy) ([OH_AI_ContextHandle](#oh_ai_contexthandle) \*context) | 释放上下文对象。                                             |
| [OH_AI_ContextSetThreadNum](#oh_ai_contextsetthreadnum) ([OH_AI_ContextHandle](#oh_ai_contexthandle) context, int32_t thread_num) | 设置运行时的线程数量。                                       |
| [OH_AI_ContextGetThreadNum](#oh_ai_contextgetthreadnum) (const [OH_AI_ContextHandle](#oh_ai_contexthandle) context) | 获取线程数量。                                               |
| [OH_AI_ContextSetThreadAffinityMode](#oh_ai_contextsetthreadaffinitymode) ([OH_AI_ContextHandle](#oh_ai_contexthandle) context, int mode) | 设置运行时线程绑定CPU核心的策略，按照CPU物理核频率分为大、中、小三种类型的核心，并且仅需绑大核或者绑中核，不需要绑小核。 |
| [OH_AI_ContextGetThreadAffinityMode](#oh_ai_contextgetthreadaffinitymode) (const [OH_AI_ContextHandle](#oh_ai_contexthandle) context) | 获取运行时线程绑定CPU核心的策略。                            |
| [OH_AI_ContextSetThreadAffinityCoreList](#oh_ai_contextsetthreadaffinitycorelist) ([OH_AI_ContextHandle](#oh_ai_contexthandle) context, const int32_t \*core_list, size_t core_num) | 设置运行时线程绑定CPU核心的列表。                            |
| [OH_AI_ContextGetThreadAffinityCoreList](#oh_ai_contextgetthreadaffinitycorelist) (const [OH_AI_ContextHandle](#oh_ai_contexthandle) context, size_t \*core_num) | 获取CPU绑核列表。                                            |
| [OH_AI_ContextSetEnableParallel](#oh_ai_contextsetenableparallel) ([OH_AI_ContextHandle](#oh_ai_contexthandle) context, bool is_parallel) | 设置运行时是否支持并行。                                     |
| [OH_AI_ContextGetEnableParallel](#oh_ai_contextgetenableparallel) (const [OH_AI_ContextHandle](#oh_ai_contexthandle) context) | 获取是否支持算子间并行。                                     |
| [OH_AI_ContextAddDeviceInfo](#oh_ai_contextadddeviceinfo) ([OH_AI_ContextHandle](#oh_ai_contexthandle) context, [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 添加运行设备信息。                                           |
| [OH_AI_DeviceInfoCreate](#oh_ai_deviceinfocreate) ([OH_AI_DeviceType](#oh_ai_devicetype) device_type) | 创建一个设备信息对象。                                       |
| [OH_AI_DeviceInfoDestroy](#oh_ai_deviceinfodestroy) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) \*device_info) | 释放设备信息实例。                                           |
| [OH_AI_DeviceInfoSetProvider](#oh_ai_deviceinfosetprovider) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, const char \*provider) | 设置供应商的名称。                                           |
| [OH_AI_DeviceInfoGetProvider](#oh_ai_deviceinfogetprovider) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 获取生产商的名称。                                           |
| [OH_AI_DeviceInfoSetProviderDevice](#oh_ai_deviceinfosetproviderdevice) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, const char \*device) | 设置生产商设备的名称。                                       |
| [OH_AI_DeviceInfoGetProviderDevice](#oh_ai_deviceinfogetproviderdevice) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 获取生产商设备的名称。                                       |
| [OH_AI_DeviceInfoGetDeviceType](#oh_ai_deviceinfogetdevicetype) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 获取设备的类型。                                             |
| [OH_AI_DeviceInfoSetEnableFP16](#oh_ai_deviceinfosetenablefp16) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, bool is_fp16) | 设置是否开启float16推理模式，仅CPU/GPU设备可用。             |
| [OH_AI_DeviceInfoGetEnableFP16](#oh_ai_deviceinfogetenablefp16) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 获取是否开启float16推理模式, 仅CPU/GPU设备可用。             |
| [OH_AI_DeviceInfoSetFrequency](#oh_ai_deviceinfosetfrequency) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, int frequency) | 设置NPU的频率，仅NPU设备可用。                               |
| [OH_AI_DeviceInfoGetFrequency](#oh_ai_deviceinfogetfrequency) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 获取NPU的频率类型，仅NPU设备可用。                           |
| [OH_AI_GetAllNNRTDeviceDescs](#oh_ai_getallnnrtdevicedescs) (size_t \*num) | 获取系统中所有NNRT硬件设备的描述信息。                       |
| [OH_AI_DestroyAllNNRTDeviceDescs](#oh_ai_destroyallnnrtdevicedescs) ([NNRTDeviceDesc](#nnrtdevicedesc) \*\*desc) | 销毁从[OH_AI_GetAllNNRTDeviceDescs](#oh_ai_getallnnrtdevicedescs)获取的NNRT描写信息实例数组。 |
| [OH_AI_GetDeviceIdFromNNRTDeviceDesc](#oh_ai_getdeviceidfromnnrtdevicedesc) (const [NNRTDeviceDesc](#nnrtdevicedesc) \*desc) | 从特定的NNRT设备描述信息实例获取NNRT设备ID。注意，此ID只对NNRT有效。 |
| [OH_AI_GetNameFromNNRTDeviceDesc](#oh_ai_getnamefromnnrtdevicedesc) (const [NNRTDeviceDesc](#nnrtdevicedesc) \*desc) | 从特定的NNRT设备描述信息实例获取NNRT设备名称。               |
| [OH_AI_GetTypeFromNNRTDeviceDesc](#oh_ai_gettypefromnnrtdevicedesc) (const [NNRTDeviceDesc](#nnrtdevicedesc) \*desc) | 从特定的NNRT设备描述信息实例获取NNRT设备类型。               |
| [OH_AI_CreateNNRTDeviceInfoByName](#oh_ai_creatennrtdeviceinfobyname) (const char \*name) | 查找指定名称的NNRT设备，根据找到的第一个设备信息，创建NNRT设备信息。 |
| [OH_AI_CreateNNRTDeviceInfoByType](#oh_ai_creatennrtdeviceinfobytype) ([OH_AI_NNRTDeviceType](#oh_ai_nnrtdevicetype) type) | 查找指定类型的NNRT设备，根据找到的第一个设备信息，创建NNRT设备信息。 |
| [OH_AI_DeviceInfoSetDeviceId](#oh_ai_deviceinfosetdeviceid) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, size_t device_id) | 设置NNRT设备ID，仅NNRT设备可用。                             |
| [OH_AI_DeviceInfoGetDeviceId](#oh_ai_deviceinfogetdeviceid) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 获取NNRT设备ID，仅NNRT设备可用。                             |
| [OH_AI_DeviceInfoSetPerformanceMode](#oh_ai_deviceinfosetperformancemode) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, [OH_AI_PerformanceMode](#oh_ai_performancemode) mode) | 设置NNRT性能模式，仅NNRT设备可用。                           |
| [OH_AI_DeviceInfoGetPerformanceMode](#oh_ai_deviceinfogetperformancemode) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 获取NNRT性能模式，仅NNRT设备可用。                           |
| [OH_AI_DeviceInfoSetPriority](#oh_ai_deviceinfosetpriority) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, [OH_AI_Priority](#oh_ai_priority) priority) | 设置NNRT任务优先级，仅NNRT设备可用。                         |
| [OH_AI_DeviceInfoGetPriority](#oh_ai_deviceinfogetpriority) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | 获取NNRT任务优先级，仅NNRT设备可用。                         |
| [OH_AI_ModelCreate](#oh_ai_modelcreate) ()                   | 创建一个模型对象。                                           |
| [OH_AI_ModelDestroy](#oh_ai_modeldestroy) ([OH_AI_ModelHandle](#oh_ai_modelhandle) \*model) | 释放一个模型对象。                                           |
| [OH_AI_ModelBuild](#oh_ai_modelbuild) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const void \*model_data, size_t data_size, [OH_AI_ModelType](#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](#oh_ai_contexthandle) model_context) | 从内存缓冲区加载并编译MindSpore模型。                        |
| [OH_AI_ModelBuildFromFile](#oh_ai_modelbuildfromfile) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const char \*model_path, [OH_AI_ModelType](#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](#oh_ai_contexthandle) model_context) | 通过模型文件加载并编译MindSpore模型。                        |
| [OH_AI_ModelResize](#oh_ai_modelresize) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) \*shape_infos, size_t shape_info_num) | 调整已编译模型的输入形状。                                   |
| [OH_AI_ModelPredict](#oh_ai_modelpredict) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) \*outputs, const [OH_AI_KernelCallBack](#oh_ai_kernelcallback) before, const [OH_AI_KernelCallBack](#oh_ai_kernelcallback) after) | 执行模型推理。                                               |
| [OH_AI_ModelGetInputs](#oh_ai_modelgetinputs) (const [OH_AI_ModelHandle](#oh_ai_modelhandle) model) | 获取模型的输入张量数组结构体。                               |
| [OH_AI_ModelGetOutputs](#oh_ai_modelgetoutputs) (const [OH_AI_ModelHandle](#oh_ai_modelhandle) model) | 获取模型的输出张量数组结构体。                               |
| [OH_AI_ModelGetInputByTensorName](#oh_ai_modelgetinputbytensorname) (const [OH_AI_ModelHandle](#oh_ai_modelhandle) model, const char \*tensor_name) | 通过张量名获取模型的输入张量。                               |
| [OH_AI_ModelGetOutputByTensorName](#oh_ai_modelgetoutputbytensorname) (const [OH_AI_ModelHandle](#oh_ai_modelhandle) model, const char \*tensor_name) | 通过张量名获取模型的输出张量。                               |
| [OH_AI_TensorCreate](#oh_ai_tensorcreate) (const char \*name, [OH_AI_DataType](#oh_ai_datatype) type, const int64_t \*shape, size_t shape_num, const void \*data, size_t data_len) | 创建一个张量对象。                                           |
| [OH_AI_TensorDestroy](#oh_ai_tensordestroy) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) \*tensor) | 释放张量对象。                                               |
| [OH_AI_TensorClone](#oh_ai_tensorclone) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | 深拷贝一个张量。                                             |
| [OH_AI_TensorSetName](#oh_ai_tensorsetname) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, const char \*name) | 设置张量的名称。                                             |
| [OH_AI_TensorGetName](#oh_ai_tensorgetname) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | 获取张量的名称。                                             |
| [OH_AI_TensorSetDataType](#oh_ai_tensorsetdatatype) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, [OH_AI_DataType](#oh_ai_datatype) type) | 设置张量的数据类型。                                         |
| [OH_AI_TensorGetDataType](#oh_ai_tensorgetdatatype) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | 获取张量类型。                                               |
| [OH_AI_TensorSetShape](#oh_ai_tensorsetshape) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, const int64_t \*shape, size_t shape_num) | 设置张量的形状。                                             |
| [OH_AI_TensorGetShape](#oh_ai_tensorgetshape) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, size_t \*shape_num) | 获取张量的形状。                                             |
| [OH_AI_TensorSetFormat](#oh_ai_tensorsetformat) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, [OH_AI_Format](#oh_ai_format) format) | 设置张量数据的排列方式。                                     |
| [OH_AI_TensorGetFormat](#oh_ai_tensorgetformat) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | 获取张量数据的排列方式。                                     |
| [OH_AI_TensorSetData](#oh_ai_tensorsetdata) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, void \*data) | 设置张量的数据。                                             |
| [OH_AI_TensorGetData](#oh_ai_tensorgetdata) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | 获取张量数据的指针。                                         |
| [OH_AI_TensorGetMutableData](#oh_ai_tensorgetmutabledata) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | 获取可变的张量数据指针。如果数据为空则会开辟内存。           |
| [OH_AI_TensorGetElementNum](#oh_ai_tensorgetelementnum) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | 获取张量元素数量。                                           |
| [OH_AI_TensorGetDataSize](#oh_ai_tensorgetdatasize) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | 获取张量中的数据的字节数大小。                               |


## 宏定义说明


### OH_AI_MAX_SHAPE_NUM


```
#define OH_AI_MAX_SHAPE_NUM   32
```

**描述：**

张量维度的最大值。


## 类型定义说明


### NNRTDeviceDesc


```
typedef struct NNRTDeviceDesc NNRTDeviceDesc
```

**描述：**

NNRT设备信息描述，包含设备ID，设备名称等信息。

**起始版本：**

10


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

模型文件的类型。


### OH_AI_NNRTDeviceType


```
typedef enum OH_AI_NNRTDeviceType OH_AI_NNRTDeviceType
```

**描述：**

NNRT管理的硬件设备类型。

**起始版本：**

10


### OH_AI_PerformanceMode


```
typedef enum OH_AI_PerformanceMode OH_AI_PerformanceMode
```

**描述：**

NNRT硬件的工作性能模式。

**起始版本：**

10


### OH_AI_Priority


```
typedef enum OH_AI_Priority OH_AI_Priority
```

**描述：**

NNRT推理任务优先级。

**起始版本：**

10


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


## 枚举类型说明


### OH_AI_CompCode


```
enum OH_AI_CompCode
```

**描述：**

Minspore不同组件的代码。

| 枚举值              | 描述                  |
| ------------------- | --------------------- |
| OH_AI_COMPCODE_CORE | Minspore Core的代码。 |
| OH_AI_COMPCODE_LITE | Minspore Lite的代码。 |


### OH_AI_DataType


```
enum OH_AI_DataType
```

**描述：**

MSTensor保存的数据支持的类型。

| 枚举值                            | 描述                   |
| --------------------------------- | ---------------------- |
| OH_AI_DATATYPE_UNKNOWN            | 未知的数据类型。       |
| OH_AI_DATATYPE_OBJECTTYPE_STRING  | String数据类型。       |
| OH_AI_DATATYPE_OBJECTTYPE_LIST    | List数据类型。         |
| OH_AI_DATATYPE_OBJECTTYPE_TUPLE   | Tuple数据类型。        |
| OH_AI_DATATYPE_OBJECTTYPE_TENSOR  | TensorList数据类型。   |
| OH_AI_DATATYPE_NUMBERTYPE_BEGIN   | Number类型的起始。     |
| OH_AI_DATATYPE_NUMBERTYPE_BOOL    | Bool数据类型。         |
| OH_AI_DATATYPE_NUMBERTYPE_INT8    | Int8数据类型。         |
| OH_AI_DATATYPE_NUMBERTYPE_INT16   | 表示Int16数据类型。    |
| OH_AI_DATATYPE_NUMBERTYPE_INT32   | 表示Int32数据类型。    |
| OH_AI_DATATYPE_NUMBERTYPE_INT64   | 表示Int64数据类型。    |
| OH_AI_DATATYPE_NUMBERTYPE_UINT8   | 表示UInt8数据类型。    |
| OH_AI_DATATYPE_NUMBERTYPE_UINT16  | 表示UInt16数据类型。   |
| OH_AI_DATATYPE_NUMBERTYPE_UINT32  | 表示UInt32数据类型。   |
| OH_AI_DATATYPE_NUMBERTYPE_UINT64  | 表示UInt64数据类型。   |
| OH_AI_DATATYPE_NUMBERTYPE_FLOAT16 | 表示Float16数据类型。  |
| OH_AI_DATATYPE_NUMBERTYPE_FLOAT32 | 表示Float32数据类型。  |
| OH_AI_DATATYPE_NUMBERTYPE_FLOAT64 | 表示Float64数据类型。  |
| OH_AI_DATATYPE_NUMBERTYPE_END     | 表示Number类型的结尾。 |
| OH_AI_DataTypeInvalid             | 表示无效的数据类型。   |


### OH_AI_DeviceType


```
enum OH_AI_DeviceType
```

**描述：**

设备类型信息，包含了目前支持的设备类型。

| 枚举值                     | 描述                                    |
| -------------------------- | --------------------------------------- |
| OH_AI_DEVICETYPE_CPU       | 设备类型是CPU。                         |
| OH_AI_DEVICETYPE_GPU       | 设备类型是GPU。预留选项， 暂不支持。    |
| OH_AI_DEVICETYPE_KIRIN_NPU | 设备类型是麒麟NPU。预留选项，暂不支持。 |
| OH_AI_DEVICETYPE_NNRT      | 设备类型是NNRt。OHOS设备范围是[60,80)。 |
| OH_AI_DEVICETYPE_INVALID   | 设备类型无效。                          |


### OH_AI_Format


```
enum OH_AI_Format
```

**描述：**

MSTensor保存的数据支持的排列格式。

| 枚举值              | 描述             |
| ------------------- | ---------------- |
| OH_AI_FORMAT_NCHW   | 表示NCHW排列。   |
| OH_AI_FORMAT_NHWC   | 表示NHWC排列。   |
| OH_AI_FORMAT_NHWC4  | 表示NHWC4排列。  |
| OH_AI_FORMAT_HWKC   | 表示HWKC排列。   |
| OH_AI_FORMAT_HWCK   | 表示HWCK排列。   |
| OH_AI_FORMAT_KCHW   | 表示KCHW排列。   |
| OH_AI_FORMAT_CKHW   | 表示CKHW排列。   |
| OH_AI_FORMAT_KHWC   | 表示KHWC排列。   |
| OH_AI_FORMAT_CHWK   | 表示CHWK排列。   |
| OH_AI_FORMAT_HW     | 表示HW排列。     |
| OH_AI_FORMAT_HW4    | 表示HW4排列。    |
| OH_AI_FORMAT_NC     | 表示NC排列。     |
| OH_AI_FORMAT_NC4    | 表示NC4排列。    |
| OH_AI_FORMAT_NC4HW4 | 表示NC4HW4排列。 |
| OH_AI_FORMAT_NCDHW  | 表示NCDHW排列。  |
| OH_AI_FORMAT_NWC    | 表示NWC排列。    |
| OH_AI_FORMAT_NCW    | 表示NCW排列。    |


### OH_AI_ModelType


```
enum OH_AI_ModelType
```

**描述：**

模型文件的类型。

| 枚举值                  | 描述               |
| ----------------------- | ------------------ |
| OH_AI_MODELTYPE_MINDIR  | 模型类型是MindIR。 |
| OH_AI_MODELTYPE_INVALID | 模型类型无效。     |


### OH_AI_NNRTDeviceType


```
enum OH_AI_NNRTDeviceType
```

**描述：**

NNRT管理的硬件设备类型。

**起始版本**：

10

| 枚举值                       | 描述                                |
| ---------------------------- | ----------------------------------- |
| OH_AI_NNRTDEVICE_OTHERS      | 设备类型不属于以下3种，则属于其它。 |
| OH_AI_NNRTDEVICE_CPU         | CPU设备。                           |
| OH_AI_NNRTDEVICE_GPU         | GPU设备。                           |
| OH_AI_NNRTDEVICE_ACCELERATOR | 特定的加速设备。                    |


### OH_AI_PerformanceMode


```
enum OH_AI_PerformanceMode
```

**描述：**

NNRT硬件的工作性能模式。

**起始版本**：

10

| 枚举值                    | 描述                |
| ------------------------- | ------------------- |
| OH_AI_PERFORMANCE_NONE    | 无特殊设置。        |
| OH_AI_PERFORMANCE_LOW     | 低功耗模式。        |
| OH_AI_PERFORMANCE_MEDIUM  | 功耗-性能均衡模式。 |
| OH_AI_PERFORMANCE_HIGH    | 高性能模式。        |
| OH_AI_PERFORMANCE_EXTREME | 极致性能模式。      |


### OH_AI_Priority


```
enum OH_AI_Priority
```

**描述：**

NNRT推理任务优先级。

**起始版本**：

10

| 枚举值                | 描述           |
| --------------------- | -------------- |
| OH_AI_PRIORITY_NONE   | 无优先级偏好。 |
| OH_AI_PRIORITY_LOW    | 低优先级任务。 |
| OH_AI_PRIORITY_MEDIUM | 中优先级任务。 |
| OH_AI_PRIORITY_HIGH   | 高优先级。     |


### OH_AI_Status


```
enum OH_AI_Status
```

**描述：**

Minspore的状态码。

| 枚举值                                | 描述                                      |
| ------------------------------------- | ----------------------------------------- |
| OH_AI_STATUS_SUCCESS                  | 通用的成功状态码。                        |
| OH_AI_STATUS_CORE_FAILED              | Mindspore Core 失败状态码。               |
| OH_AI_STATUS_LITE_ERROR               | Mindspore Lite 异常状态码。               |
| OH_AI_STATUS_LITE_NULLPTR             | Mindspore Lite 空指针状态码。             |
| OH_AI_STATUS_LITE_PARAM_INVALID       | Mindspore Lite 参数异常状态码。           |
| OH_AI_STATUS_LITE_NO_CHANGE           | Mindspore Lite 未改变状态码。             |
| OH_AI_STATUS_LITE_SUCCESS_EXIT        | Mindspore Lite 没有错误但是退出的状态码。 |
| OH_AI_STATUS_LITE_MEMORY_FAILED       | Mindspore Lite 内存分配失败的状态码。     |
| OH_AI_STATUS_LITE_NOT_SUPPORT         | Mindspore Lite 功能未支持的状态码。       |
| OH_AI_STATUS_LITE_THREADPOOL_ERROR    | Mindspore Lite 线程池异常状态码。         |
| OH_AI_STATUS_LITE_UNINITIALIZED_OBJ   | Mindspore Lite 未初始化状态码。           |
| OH_AI_STATUS_LITE_OUT_OF_TENSOR_RANGE | Mindspore Lite 张量溢出错误的状态码。     |
| OH_AI_STATUS_LITE_INPUT_TENSOR_ERROR  | Mindspore Lite 输入张量异常的状态码。     |
| OH_AI_STATUS_LITE_REENTRANT_ERROR     | Mindspore Lite 重入异常的状态码。         |
| OH_AI_STATUS_LITE_GRAPH_FILE_ERROR    | Mindspore Lite 文件异常状态码。           |
| OH_AI_STATUS_LITE_NOT_FIND_OP         | Mindspore Lite 未找到算子的状态码。       |
| OH_AI_STATUS_LITE_INVALID_OP_NAME     | Mindspore Lite 无效算子状态码。           |
| OH_AI_STATUS_LITE_INVALID_OP_ATTR     | Mindspore Lite 无效算子超参数状态码。     |
| OH_AI_STATUS_LITE_OP_EXECUTE_FAILURE  | Mindspore Lite 算子执行失败的状态码。     |
| OH_AI_STATUS_LITE_FORMAT_ERROR        | Mindspore Lite 张量格式异常状态码。       |
| OH_AI_STATUS_LITE_INFER_ERROR         | Mindspore Lite 形状推理异常状态码。       |
| OH_AI_STATUS_LITE_INFER_INVALID       | Mindspore Lite 无效的形状推理的状态码。   |
| OH_AI_STATUS_LITE_INPUT_PARAM_INVALID | Mindspore Lite 用户输入的参数无效状态码。 |


