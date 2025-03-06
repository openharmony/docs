# MindSpore


## Overview

Provides APIs related to MindSpore Lite model inference. The APIs in this module are non-thread-safe.

**Since**: 9

## Summary


### Files

| Name| Description|
| -------- | -------- |
| [context.h](context_8h.md) | Provides **Context** APIs for configuring runtime information.<br>File to include: &lt;mindspore/context.h&gt;<br>Library: libmindspore_lite_ndk.so|
| [data_type.h](data__type_8h.md) | Declares tensor data types.<br>File to include: &lt;mindspore/data_type.h&gt;<br>Library: libmindspore_lite_ndk.so|
| [format.h](format_8h.md) | Declares tensor data formats.<br>File to include: &lt;mindspore/format.h&gt;<br>Library: libmindspore_lite_ndk.so|
| [model.h](model_8h.md) | Provides model-related APIs for model creation and inference.<br>File to include: &lt;mindspore/model.h&gt;<br>Library: libmindspore_lite_ndk.so|
| [status.h](status_8h.md) | Provides the status codes of MindSpore Lite.<br>File to include: &lt;mindspore/status.h&gt;<br>Library: libmindspore_lite_ndk.so|
| [tensor.h](tensor_8h.md) | Provides APIs for creating and modifying tensor information.<br>File to include: &lt;mindspore/tensor.h&gt;<br>Library: libmindspore_lite_ndk.so|
| [types.h](types_8h.md) | Provides the model file types and device types supported by MindSpore Lite.<br>File to include: &lt;mindspore/types.h&gt;<br>Library: libmindspore_lite_ndk.so|


### Structs

| Name| Description|
| -------- | -------- |
| [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) | Defines the tensor array structure, which is used to store the tensor array pointer and tensor array length.|
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) | Defines dimension information. The maximum dimension is set by **OH_AI_MAX_SHAPE_NUM**.|
| [OH_AI_CallBackParam](_o_h___a_i___call_back_param.md) | Defines the operator information passed in a callback.|


### Macro Definition

| Name| Description|
| -------- | -------- |
| [OH_AI_MAX_SHAPE_NUM](#oh_ai_max_shape_num) 32 | Defines dimension information. The maximum dimension is set by **MS_MAX_SHAPE_NUM**.|


### Types

| Name| Description|
| -------- | -------- |
| [OH_AI_ContextHandle](#oh_ai_contexthandle) | Defines the pointer to the MindSpore context. |
| [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) | Defines the pointer to the MindSpore device information.|
| [OH_AI_DataType](#oh_ai_datatype) | Declares data types supported by MSTensor.|
| [OH_AI_Format](#oh_ai_format) | Declares data formats supported by MSTensor.|
| [OH_AI_ModelHandle](#oh_ai_modelhandle) | Defines the pointer to a model object.|
| [OH_AI_TrainCfgHandle](#oh_ai_traincfghandle) | Defines the pointer to a training configuration object.|
| [OH_AI_TensorHandleArray](#oh_ai_tensorhandlearray) | Defines the tensor array structure, which is used to store the tensor array pointer and tensor array length.|
| [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) | Defines dimension information. The maximum dimension is set by **OH_AI_MAX_SHAPE_NUM**.|
| [OH_AI_CallBackParam](#oh_ai_callbackparam) | Defines the operator information passed in a callback.|
| [OH_AI_KernelCallBack](#oh_ai_kernelcallback)) (const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) outputs, const [OH_AI_CallBackParam](_o_h___a_i___call_back_param.md) kernel_Info) | Defines the pointer to a callback.|
| [OH_AI_Status](#oh_ai_status) | Defines MindSpore status codes.|
| [OH_AI_TensorHandle](#oh_ai_tensorhandle) | Defines the handle of a tensor object.|
| [OH_AI_ModelType](#oh_ai_modeltype) | Defines model file types.|
| [OH_AI_DeviceType](#oh_ai_devicetype) | Defines the supported device types.|
| [OH_AI_NNRTDeviceType](#oh_ai_nnrtdevicetype) | Defines NNRt device types.|
| [OH_AI_PerformanceMode](#oh_ai_performancemode) | Defines performance modes of the NNRt device.|
| [OH_AI_Priority](#oh_ai_priority) | Defines NNRt inference task priorities.|
| [OH_AI_OptimizationLevel](#oh_ai_optimizationlevel) | Defines training optimization levels.|
| [OH_AI_QuantizationType](#oh_ai_quantizationtype) | Defines quantization types.|
| [NNRTDeviceDesc](#nnrtdevicedesc) | Defines NNRt device information, including the device ID and device name.|
| [OH_AI_AllocatorHandle](#oh_ai_allocatorhandle) | Defines the handle of the memory allocator.|


### Enums

| Name| Description|
| -------- | -------- |
| [OH_AI_DataType](#oh_ai_datatype) {<br>OH_AI_DATATYPE_UNKNOWN = 0, OH_AI_DATATYPE_OBJECTTYPE_STRING = 12, OH_AI_DATATYPE_OBJECTTYPE_LIST = 13, OH_AI_DATATYPE_OBJECTTYPE_TUPLE = 14,<br>OH_AI_DATATYPE_OBJECTTYPE_TENSOR = 17, OH_AI_DATATYPE_NUMBERTYPE_BEGIN = 29, OH_AI_DATATYPE_NUMBERTYPE_BOOL = 30, OH_AI_DATATYPE_NUMBERTYPE_INT8 = 32,<br>OH_AI_DATATYPE_NUMBERTYPE_INT16 = 33, OH_AI_DATATYPE_NUMBERTYPE_INT32 = 34, OH_AI_DATATYPE_NUMBERTYPE_INT64 = 35, OH_AI_DATATYPE_NUMBERTYPE_UINT8 = 37,<br>OH_AI_DATATYPE_NUMBERTYPE_UINT16 = 38, OH_AI_DATATYPE_NUMBERTYPE_UINT32 = 39, OH_AI_DATATYPE_NUMBERTYPE_UINT64 = 40, OH_AI_DATATYPE_NUMBERTYPE_FLOAT16 = 42,<br>OH_AI_DATATYPE_NUMBERTYPE_FLOAT32 = 43, OH_AI_DATATYPE_NUMBERTYPE_FLOAT64 = 44, OH_AI_DATATYPE_NUMBERTYPE_END = 46, OH_AI_DataTypeInvalid = INT32_MAX<br>} | Declares data types supported by MSTensor.|
| [OH_AI_Format](#oh_ai_format) {<br>OH_AI_FORMAT_NCHW = 0, OH_AI_FORMAT_NHWC = 1, OH_AI_FORMAT_NHWC4 = 2, OH_AI_FORMAT_HWKC = 3,<br>OH_AI_FORMAT_HWCK = 4, OH_AI_FORMAT_KCHW = 5, OH_AI_FORMAT_CKHW = 6, OH_AI_FORMAT_KHWC = 7,<br>OH_AI_FORMAT_CHWK = 8, OH_AI_FORMAT_HW = 9, OH_AI_FORMAT_HW4 = 10, OH_AI_FORMAT_NC = 11,<br>OH_AI_FORMAT_NC4 = 12, OH_AI_FORMAT_NC4HW4 = 13, OH_AI_FORMAT_NCDHW = 15, OH_AI_FORMAT_NWC = 16,<br>OH_AI_FORMAT_NCW = 17<br>} | Declares data formats supported by MSTensor.|
| [OH_AI_CompCode](#oh_ai_compcode) { <br>OH_AI_COMPCODE_CORE = 0x00000000u, <br>OH_AI_COMPCODE_MD = 0x10000000u, <br>OH_AI_COMPCODE_ME = 0x20000000u, <br>OH_AI_COMPCODE_MC = 0x30000000u, <br>OH_AI_COMPCODE_LITE = 0xF0000000u<br> } | Defines MindSpore component codes. |
| [OH_AI_Status](#oh_ai_status) {<br>OH_AI_STATUS_SUCCESS = 0, OH_AI_STATUS_CORE_FAILED = OH_AI_COMPCODE_CORE \| 0x1, OH_AI_STATUS_LITE_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -1), OH_AI_STATUS_LITE_NULLPTR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -2),<br>OH_AI_STATUS_LITE_PARAM_INVALID = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -3), OH_AI_STATUS_LITE_NO_CHANGE = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -4), OH_AI_STATUS_LITE_SUCCESS_EXIT = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -5), OH_AI_STATUS_LITE_MEMORY_FAILED = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -6),<br>OH_AI_STATUS_LITE_NOT_SUPPORT = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -7), OH_AI_STATUS_LITE_THREADPOOL_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -8), OH_AI_STATUS_LITE_UNINITIALIZED_OBJ = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -9), OH_AI_STATUS_LITE_OUT_OF_TENSOR_RANGE = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -100),<br>OH_AI_STATUS_LITE_INPUT_TENSOR_ERROR, OH_AI_STATUS_LITE_REENTRANT_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -102), OH_AI_STATUS_LITE_GRAPH_FILE_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -200), OH_AI_STATUS_LITE_NOT_FIND_OP = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -300),<br>OH_AI_STATUS_LITE_INVALID_OP_NAME = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -301), OH_AI_STATUS_LITE_INVALID_OP_ATTR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -302), OH_AI_STATUS_LITE_OP_EXECUTE_FAILURE, OH_AI_STATUS_LITE_FORMAT_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -400),<br>OH_AI_STATUS_LITE_INFER_ERROR = OH_AI_COMPCODE_LITE \| (0x0FFFFFFF &amp; -500), OH_AI_STATUS_LITE_INFER_INVALID, OH_AI_STATUS_LITE_INPUT_PARAM_INVALID<br>} | Defines MindSpore status codes.|
| [OH_AI_ModelType](#oh_ai_modeltype) { OH_AI_MODELTYPE_MINDIR = 0, OH_AI_MODELTYPE_INVALID = 0xFFFFFFFF } | Defines model file types.|
| [OH_AI_DeviceType](#oh_ai_devicetype) {<br>OH_AI_DEVICETYPE_CPU = 0, OH_AI_DEVICETYPE_GPU, OH_AI_DEVICETYPE_KIRIN_NPU, OH_AI_DEVICETYPE_NNRT = 60,<br>OH_AI_DEVICETYPE_INVALID = 100<br>} | Defines the supported device types.|
| [OH_AI_NNRTDeviceType](#oh_ai_nnrtdevicetype) { OH_AI_NNRTDEVICE_OTHERS = 0, OH_AI_NNRTDEVICE_CPU = 1, OH_AI_NNRTDEVICE_GPU = 2, OH_AI_NNRTDEVICE_ACCELERATOR = 3 } | Defines NNRt device types.|
| [OH_AI_PerformanceMode](#oh_ai_performancemode) {<br>OH_AI_PERFORMANCE_NONE = 0, OH_AI_PERFORMANCE_LOW = 1, OH_AI_PERFORMANCE_MEDIUM = 2, OH_AI_PERFORMANCE_HIGH = 3,<br>OH_AI_PERFORMANCE_EXTREME = 4<br>} | Defines performance modes of the NNRt device.|
| [OH_AI_Priority](#oh_ai_priority) { OH_AI_PRIORITY_NONE = 0, OH_AI_PRIORITY_LOW = 1, OH_AI_PRIORITY_MEDIUM = 2, OH_AI_PRIORITY_HIGH = 3 } | Defines NNRt inference task priorities.|
| [OH_AI_OptimizationLevel](#oh_ai_optimizationlevel) {<br>OH_AI_KO0 = 0, OH_AI_KO2 = 2, OH_AI_KO3 = 3, OH_AI_KAUTO = 4,<br>OH_AI_KOPTIMIZATIONTYPE = 0xFFFFFFFF<br>} | Defines training optimization levels.|
| [OH_AI_QuantizationType](#oh_ai_quantizationtype) { OH_AI_NO_QUANT = 0, OH_AI_WEIGHT_QUANT = 1, OH_AI_FULL_QUANT = 2, OH_AI_UNKNOWN_QUANT_TYPE = 0xFFFFFFFF } | Defines quantization types.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_AI_ContextCreate](#oh_ai_contextcreate) () | Creates a context object. This API must be used together with [OH_AI_ContextDestroy](#oh_ai_contextdestroy).|
| [OH_AI_ContextDestroy](#oh_ai_contextdestroy) ([OH_AI_ContextHandle](#oh_ai_contexthandle) \*context) | Destroys a context object.|
| [OH_AI_ContextSetThreadNum](#oh_ai_contextsetthreadnum) ([OH_AI_ContextHandle](#oh_ai_contexthandle) context, int32_t thread_num) | Sets the number of runtime threads.|
| [OH_AI_ContextGetThreadNum](#oh_ai_contextgetthreadnum) (const [OH_AI_ContextHandle](#oh_ai_contexthandle) context) | Obtains the number of threads.|
| [OH_AI_ContextSetThreadAffinityMode](#oh_ai_contextsetthreadaffinitymode) ([OH_AI_ContextHandle](#oh_ai_contexthandle) context, int mode) | Sets the affinity mode for binding runtime threads to CPU cores, which are classified into large, medium, and small cores based on the CPU frequency. You only need to bind the large or medium cores, but not small cores.|
| [OH_AI_ContextGetThreadAffinityMode](#oh_ai_contextgetthreadaffinitymode) (const [OH_AI_ContextHandle](#oh_ai_contexthandle) context) | Obtains the affinity mode for binding runtime threads to CPU cores.|
| [OH_AI_ContextSetThreadAffinityCoreList](#oh_ai_contextsetthreadaffinitycorelist) ([OH_AI_ContextHandle](#oh_ai_contexthandle) context, const int32_t \*core_list, size_t core_num) | Sets the list of CPU cores bound to a runtime thread.|
| [OH_AI_ContextGetThreadAffinityCoreList](#oh_ai_contextgetthreadaffinitycorelist) (const [OH_AI_ContextHandle](#oh_ai_contexthandle) context, size_t \*core_num) | Obtains the list of bound CPU cores.|
| [OH_AI_ContextSetEnableParallel](#oh_ai_contextsetenableparallel) ([OH_AI_ContextHandle](#oh_ai_contexthandle) context, bool is_parallel) | Sets whether to enable parallelism between operators. The setting is ineffective because the feature of this API is not yet available.|
| [OH_AI_ContextGetEnableParallel](#oh_ai_contextgetenableparallel) (const [OH_AI_ContextHandle](#oh_ai_contexthandle) context) | Checks whether parallelism between operators is supported.|
| [OH_AI_ContextAddDeviceInfo](#oh_ai_contextadddeviceinfo) ([OH_AI_ContextHandle](#oh_ai_contexthandle) context, [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | Attaches the custom device information to the inference context.|
| [OH_AI_DeviceInfoCreate](#oh_ai_deviceinfocreate) ([OH_AI_DeviceType](#oh_ai_devicetype) device_type) | Creates a device information object.|
| [OH_AI_DeviceInfoDestroy](#oh_ai_deviceinfodestroy) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) \*device_info) | Destroys a device information object. Note: After the device information instance is added to the context, the caller does not need to destroy it manually.|
| [OH_AI_DeviceInfoSetProvider](#oh_ai_deviceinfosetprovider) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, const char \*provider) | Sets the name of the provider.|
| [OH_AI_DeviceInfoGetProvider](#oh_ai_deviceinfogetprovider) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | Obtains the provider name.|
| [OH_AI_DeviceInfoSetProviderDevice](#oh_ai_deviceinfosetproviderdevice) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, const char \*device) | Sets the name of a provider device.|
| [OH_AI_DeviceInfoGetProviderDevice](#oh_ai_deviceinfogetproviderdevice) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | Obtains the name of a provider device.|
| [OH_AI_DeviceInfoGetDeviceType](#oh_ai_deviceinfogetdevicetype) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | Obtains the device type.|
| [OH_AI_DeviceInfoSetEnableFP16](#oh_ai_deviceinfosetenablefp16) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, bool is_fp16) | Sets whether to enable float16 inference. This function is available only for CPU and GPU devices.|
| [OH_AI_DeviceInfoGetEnableFP16](#oh_ai_deviceinfogetenablefp16) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | Checks whether float16 inference is enabled. This function is available only for CPU and GPU devices.|
| [OH_AI_DeviceInfoSetFrequency](#oh_ai_deviceinfosetfrequency) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, int frequency) | Sets the NPU frequency type. This function is available only for NPU devices.|
| [OH_AI_DeviceInfoGetFrequency](#oh_ai_deviceinfogetfrequency) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | Obtains the NPU frequency type. This function is available only for NPU devices.|
| [OH_AI_GetAllNNRTDeviceDescs](#oh_ai_getallnnrtdevicedescs) (size_t \*num) | Obtains the descriptions of all NNRt devices in the system.|
| [OH_AI_GetElementOfNNRTDeviceDescs](#oh_ai_getelementofnnrtdevicedescs) ([NNRTDeviceDesc](#nnrtdevicedesc) \*descs, size_t index) | Obtains the pointer to an element in the NNRt device description array.|
| [OH_AI_DestroyAllNNRTDeviceDescs](#oh_ai_destroyallnnrtdevicedescs) ([NNRTDeviceDesc](#nnrtdevicedesc) \*\*desc) | Destroys the NNRt device description array obtained by [OH_AI_GetAllNNRTDeviceDescs](#oh_ai_getallnnrtdevicedescs).|
| [OH_AI_GetDeviceIdFromNNRTDeviceDesc](#oh_ai_getdeviceidfromnnrtdevicedesc) (const [NNRtDeviceDesc](#nnrtdevicedesc) \*desc) | Obtains the NNRt device ID from the specified NNRt device description. Note that this ID is valid only for NNRt devices.|
| [OH_AI_GetNameFromNNRTDeviceDesc](#oh_ai_getnamefromnnrtdevicedesc) (const [NNRTDeviceDesc](#nnrtdevicedesc) \*desc) | Obtains the NNRt device name from the specified NNRt device description.|
| [OH_AI_GetTypeFromNNRtDeviceDesc](#oh_ai_gettypefromnnrtdevicedesc) (const [NNRTDeviceDesc](#nnrtdevicedesc) \*desc) | Obtains the NNRt device type from the specified NNRt device description.|
| [OH_AI_CreateNNRTDeviceInfoByName](#oh_ai_creatennrtdeviceinfobyname) (const char \*name) | Searches for the NNRt device with the specified name and creates the NNRt device information based on the information about the first found NNRt device.|
| [OH_AI_CreateNNRTDeviceInfoByType](#oh_ai_creatennrtdeviceinfobytype) ([OH_AI_NNRTDeviceType](#oh_ai_nnrtdevicetype) type) | Searches for the NNRt device with the specified type and creates the NNRt device information based on the information about the first found NNRt device.|
| [OH_AI_DeviceInfoSetDeviceId](#oh_ai_deviceinfosetdeviceid) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, size_t device_id) | Sets the NNRt device ID. This function is available only for NNRt devices.|
| [OH_AI_DeviceInfoGetDeviceId](#oh_ai_deviceinfogetdeviceid) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | Obtains the NNRt device ID. This function is available only for NNRt devices.|
| [OH_AI_DeviceInfoSetPerformanceMode](#oh_ai_deviceinfosetperformancemode) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, [OH_AI_PerformanceMode](#oh_ai_performancemode) mode) | Sets the NNRt performance mode. This function is available only for NNRt devices.|
| [OH_AI_DeviceInfoGetPerformanceMode](#oh_ai_deviceinfogetperformancemode) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | Obtains the NNRt performance mode. This function is available only for NNRt devices.|
| [OH_AI_DeviceInfoSetPriority](#oh_ai_deviceinfosetpriority) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, [OH_AI_Priority](#oh_ai_priority) priority) | Sets the priority of an NNRt task. This function is available only for NNRt devices.|
| [OH_AI_DeviceInfoGetPriority](#oh_ai_deviceinfogetpriority) (const [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info) | Obtains the priority of an NNRt task. This function is available only for NNRt devices.|
| [OH_AI_DeviceInfoAddExtension](#oh_ai_deviceinfoaddextension) ([OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) device_info, const char \*name, const char \*value, size_t value_size) | Adds extended configuration in the form of key/value pairs to the device information. This function is available only for NNRt devices.|
| [OH_AI_ModelCreate](#oh_ai_modelcreate) () | Creates a model object.|
| [OH_AI_ModelDestroy](#oh_ai_modeldestroy) ([OH_AI_ModelHandle](#oh_ai_modelhandle) \*model) | Destroys a model object.|
| [OH_AI_ModelBuild](#oh_ai_modelbuild) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const void \*model_data, size_t data_size, [OH_AI_ModelType](#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](#oh_ai_contexthandle) model_context) | Loads and builds a MindSpore model from the memory buffer.|
| [OH_AI_ModelBuildFromFile](#oh_ai_modelbuildfromfile) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const char \*model_path, [OH_AI_ModelType](#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](#oh_ai_contexthandle) model_context) | Loads and builds a MindSpore model from a model file.|
| [OH_AI_ModelResize](#oh_ai_modelresize) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, [OH_AI_ShapeInfo](_o_h___a_i___shape_info.md) \*shape_infos, size_t shape_info_num) | Adjusts the input tensor shapes of a built model.|
| [OH_AI_ModelPredict](#oh_ai_modelpredict) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) inputs, [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) \*outputs, const [OH_AI_KernelCallBack](#oh_ai_kernelcallback) before, const [OH_AI_KernelCallBack](#oh_ai_kernelcallback) after) | Performs model inference.|
| [OH_AI_ModelGetInputs](#oh_ai_modelgetinputs) (const [OH_AI_ModelHandle](#oh_ai_modelhandle) model) | Obtains the input tensor array structure of a model.|
| [OH_AI_ModelGetOutputs](#oh_ai_modelgetoutputs) (const [OH_AI_ModelHandle](#oh_ai_modelhandle) model) | Obtains the output tensor array structure of a model.|
| [OH_AI_ModelGetInputByTensorName](#oh_ai_modelgetinputbytensorname) (const [OH_AI_ModelHandle](#oh_ai_modelhandle) model, const char \*tensor_name) | Obtains the input tensor of a model by tensor name.|
| [OH_AI_ModelGetOutputByTensorName](#oh_ai_modelgetoutputbytensorname) (const [OH_AI_ModelHandle](#oh_ai_modelhandle) model, const char \*tensor_name) | Obtains the output tensor of a model by tensor name.|
| [OH_AI_TrainCfgCreate](#oh_ai_traincfgcreate) () | Creates the pointer to the training configuration object. This API is used only for on-device training.|
| [OH_AI_TrainCfgDestroy](#oh_ai_traincfgdestroy) ([OH_AI_TrainCfgHandle](#oh_ai_traincfghandle) \*train_cfg) | Destroys the pointer to the training configuration object. This API is used only for on-device training.|
| [OH_AI_TrainCfgGetLossName](#oh_ai_traincfggetlossname) ([OH_AI_TrainCfgHandle](#oh_ai_traincfghandle) train_cfg, size_t \*num) | Obtains the list of loss functions, which are used only for on-device training.|
| [OH_AI_TrainCfgSetLossName](#oh_ai_traincfgsetlossname) ([OH_AI_TrainCfgHandle](#oh_ai_traincfghandle) train_cfg, const char \*\*loss_name, size_t num) | Sets the list of loss functions, which are used only for on-device training.|
| [OH_AI_TrainCfgGetOptimizationLevel](#oh_ai_traincfggetoptimizationlevel) ([OH_AI_TrainCfgHandle](#oh_ai_traincfghandle) train_cfg) | Obtains the optimization level of the training configuration object. This API is used only for on-device training.|
| [OH_AI_TrainCfgSetOptimizationLevel](#oh_ai_traincfgsetoptimizationlevel) ([OH_AI_TrainCfgHandle](#oh_ai_traincfghandle) train_cfg, [OH_AI_OptimizationLevel](#oh_ai_optimizationlevel) level) | Sets the optimization level of the training configuration object. This API is used only for on-device training.|
| [OH_AI_TrainModelBuild](#oh_ai_trainmodelbuild) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const void \*model_data, size_t data_size, [OH_AI_ModelType](#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](#oh_ai_contexthandle) model_context, const [OH_AI_TrainCfgHandle](#oh_ai_traincfghandle) train_cfg) | Loads a training model from the memory buffer and compiles the model to a state ready for running on the device. This API is used only for on-device training.|
| [OH_AI_TrainModelBuildFromFile](#oh_ai_trainmodelbuildfromfile) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const char \*model_path, [OH_AI_ModelType](#oh_ai_modeltype) model_type, const [OH_AI_ContextHandle](#oh_ai_contexthandle) model_context, const [OH_AI_TrainCfgHandle](#oh_ai_traincfghandle) train_cfg) | Loads the training model from the specified path and compiles the model to a state ready for running on the device. This API is used only for on-device training.|
| [OH_AI_RunStep](#oh_ai_runstep) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const [OH_AI_KernelCallBack](#oh_ai_kernelcallback) before, const [OH_AI_KernelCallBack](#oh_ai_kernelcallback) after) | Defines a single-step training model. This API is used only for on-device training.|
| [OH_AI_ModelSetLearningRate](#oh_ai_modelsetlearningrate) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, float learning_rate) | Sets the learning rate for model training. This API is used only for on-device training.|
| [OH_AI_ModelGetLearningRate](#oh_ai_modelgetlearningrate) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model) | Obtains the learning rate for model training. This API is used only for on-device training.|
| [OH_AI_ModelGetWeights](#oh_ai_modelgetweights) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model) | Obtains all weight tensors of a model. This API is used only for on-device training.|
| [OH_AI_ModelUpdateWeights](#oh_ai_modelupdateweights) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, const [OH_AI_TensorHandleArray](_o_h___a_i___tensor_handle_array.md) new_weights) | Updates the weight tensors of a model. This API is used only for on-device training.|
| [OH_AI_ModelGetTrainMode](#oh_ai_modelgettrainmode) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model) | Obtains the training mode.|
| [OH_AI_ModelSetTrainMode](#oh_ai_modelsettrainmode) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, bool train) | Sets the training mode. This API is used only for on-device training.|
| [OH_AI_ModelSetupVirtualBatch](#oh_ai_modelsetupvirtualbatch) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, int virtual_batch_multiplier, float lr, float momentum) | OH_AI_API [OH_AI_Status](#oh_ai_status)<br>Sets the virtual batch for training. This API is used only for on-device training.|
| [OH_AI_ExportModel](#oh_ai_exportmodel) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, [OH_AI_ModelType](#oh_ai_modeltype) model_type, const char \*model_file, [OH_AI_QuantizationType](#oh_ai_quantizationtype) quantization_type, bool export_inference_only, char \*\*output_tensor_name, size_t num) | Exports a training model. This API is used only for on-device training.|
| [OH_AI_ExportModelBuffer](#oh_ai_exportmodelbuffer) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, [OH_AI_ModelType](#oh_ai_modeltype) model_type, char \*\*model_data, size_t \*data_size, [OH_AI_QuantizationType](#oh_ai_quantizationtype) quantization_type, bool export_inference_only, char \*\*output_tensor_name, size_t num) | Exports the memory cache of the training model. This API is used only for on-device training. |
| [OH_AI_ExportWeightsCollaborateWithMicro](#oh_ai_exportweightscollaboratewithmicro) ([OH_AI_ModelHandle](#oh_ai_modelhandle) model, [OH_AI_ModelType](#oh_ai_modeltype) model_type, const char \*weight_file, bool is_inference, bool enable_fp16, char \*\*changeable_weights_name, size_t num) | Exports the weight file of the training model for micro inference. This API is used only for on-device training.|
| [OH_AI_TensorCreate](#oh_ai_tensorcreate) (const char \*name, [OH_AI_DataType](#oh_ai_datatype) type, const int64_t \*shape, size_t shape_num, const void \*data, size_t data_len) | Creates a tensor object.|
| [OH_AI_TensorDestroy](#oh_ai_tensordestroy) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) \*tensor) | Destroys a tensor object.|
| [OH_AI_TensorClone](#oh_ai_tensorclone) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | Clones a tensor.|
| [OH_AI_TensorSetName](#oh_ai_tensorsetname) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, const char \*name) | Sets the tensor name.|
| [OH_AI_TensorGetName](#oh_ai_tensorgetname) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | Obtains the tensor name.|
| [OH_AI_TensorSetDataType](#oh_ai_tensorsetdatatype) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, [OH_AI_DataType](#oh_ai_datatype) type) | Sets the data type of a tensor.|
| [OH_AI_TensorGetDataType](#oh_ai_tensorgetdatatype) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | Obtains the tensor type.|
| [OH_AI_TensorSetShape](#oh_ai_tensorsetshape) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, const int64_t \*shape, size_t shape_num) | Sets the tensor shape.|
| [OH_AI_TensorGetShape](#oh_ai_tensorgetshape) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, size_t \*shape_num) | Obtains the tensor shape.|
| [OH_AI_TensorSetFormat](#oh_ai_tensorsetformat) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, [OH_AI_Format](#oh_ai_format) format) | Sets the tensor data format.|
| [OH_AI_TensorGetFormat](#oh_ai_tensorgetformat) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | Obtains the tensor data format.|
| [OH_AI_TensorSetData](#oh_ai_tensorsetdata) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, void \*data) | Sets the tensor data.|
| [OH_AI_TensorGetData](#oh_ai_tensorgetdata) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | Obtains the pointer to tensor data.|
| [OH_AI_TensorGetMutableData](#oh_ai_tensorgetmutabledata) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | Obtains the pointer to variable tensor data. If the data is empty, memory will be allocated.|
| [OH_AI_TensorGetElementNum](#oh_ai_tensorgetelementnum) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | Obtains the number of tensor elements.|
| [OH_AI_TensorGetDataSize](#oh_ai_tensorgetdatasize) (const [OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | Obtains the number of bytes of the tensor data.|
| [OH_AI_TensorSetUserData](#oh_ai_tensorsetuserdata) ([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, void \*data, size_t data_size) | Sets the tensor as the user data. This function allows you to reuse user data as the model input, which helps to reduce data copy by one time.<br>> **NOTE**<br>The user data is type of external data for the tensor and is not automatically released when the tensor is destroyed. The caller needs to release the data separately. In addition, the caller must ensure that the user data is valid during use of the tensor.|
| [OH_AI_TensorGetAllocator](#oh_ai_tensorgetallocator)([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor) | Obtains a memory allocator. The allocator is responsible for allocating memory for tensors.|
| [OH_AI_TensorSetAllocator](#oh_ai_tensorsetallocator)([OH_AI_TensorHandle](#oh_ai_tensorhandle) tensor, [OH_AI_AllocatorHandle](#oh_ai_allocatorhandle) allocator) | Sets the memory allocator. The allocator is responsible for allocating memory for tensors.|


## Macro Description


### OH_AI_MAX_SHAPE_NUM

```
#define OH_AI_MAX_SHAPE_NUM   32
```

**Description**

Defines dimension information. The maximum dimension is set by **OH_AI_MAX_SHAPE_NUM**.

**Since**: 9


## Type Description


### NNRTDeviceDesc

```
typedef struct NNRTDeviceDesc NNRTDeviceDesc
```

**Description**

Defines NNRt device information, including the device ID and device name.

**Since**: 10

### OH_AI_AllocatorHandle

```
typedef void *OH_AI_AllocatorHandle
```

**Description**

Handle of the memory allocator.

**Since**: 12

### OH_AI_CallBackParam

```
typedef struct OH_AI_CallBackParam OH_AI_CallBackParam
```

**Description**

Defines the operator information passed in a callback.

**Since**: 9


### OH_AI_ContextHandle

```
typedef void* OH_AI_ContextHandle
```

**Description**

Defines the pointer to the MindSpore context. 

**Since**: 9


### OH_AI_DataType

```
typedef enum OH_AI_DataType OH_AI_DataType
```

**Description**

Declares data types supported by MSTensor.

**Since**: 9


### OH_AI_DeviceInfoHandle

```
typedef void* OH_AI_DeviceInfoHandle
```

**Description**

Defines the pointer to the MindSpore device information.

**Since**: 9


### OH_AI_DeviceType

```
typedef enum OH_AI_DeviceType OH_AI_DeviceType
```

**Description**

Defines the supported device types.

**Since**: 9


### OH_AI_Format

```
typedef enum OH_AI_Format OH_AI_Format
```

**Description**

Declares data formats supported by MSTensor.

**Since**: 9


### OH_AI_KernelCallBack

```
typedef bool(* OH_AI_KernelCallBack) (const OH_AI_TensorHandleArray inputs, const OH_AI_TensorHandleArray outputs, const OH_AI_CallBackParam kernel_Info)
```

**Description**

Defines the pointer to a callback.

This pointer is used to set the two callback functions in [OH_AI_ModelPredict](#oh_ai_modelpredict). Each callback function must contain three parameters, where **inputs** and **outputs** indicate the input and output tensors of the operator, and **kernel_Info** indicates information about the current operator. You can use the callback functions to monitor the operator execution status, for example, operator execution time and the operator correctness.

**Since**: 9


### OH_AI_ModelHandle

```
typedef void* OH_AI_ModelHandle
```

**Description**

Defines the pointer to a model object.

**Since**: 9


### OH_AI_ModelType

```
typedef enum OH_AI_ModelType OH_AI_ModelType
```

**Description**

Defines model file types.

**Since**: 9


### OH_AI_NNRTDeviceType

```
typedef enum OH_AI_NNRTDeviceType OH_AI_NNRTDeviceType
```

**Description**

Defines NNRt device types.

**Since**: 10


### OH_AI_PerformanceMode

```
typedef enum OH_AI_PerformanceMode OH_AI_PerformanceMode
```

**Description**

Defines performance modes of the NNRt device.

**Since**: 10


### OH_AI_Priority

```
typedef enum OH_AI_Priority OH_AI_Priority
```

**Description**

Defines NNRt inference task priorities.

**Since**: 10


### OH_AI_Status

```
typedef enum OH_AI_Status OH_AI_Status
```

**Description**

Defines MindSpore status codes.

**Since**: 9


### OH_AI_TensorHandle

```
typedef void* OH_AI_TensorHandle
```

**Description**

Handle of a tensor object.

**Since**: 9


### OH_AI_TensorHandleArray

```
typedef struct OH_AI_TensorHandleArray OH_AI_TensorHandleArray
```

**Description**

Defines the tensor array structure, which is used to store the tensor array pointer and tensor array length.

**Since**: 9


### OH_AI_TrainCfgHandle

```
typedef void* OH_AI_TrainCfgHandle
```

**Description**

Defines the pointer to a training configuration object.

**Since**: 11


## Enum Description


### OH_AI_CompCode

```
enum OH_AI_CompCode
```

**Description**

Defines MindSpore component codes. 

**Since**: 9

| Value| Description|
| -------- | -------- |
| OH_AI_COMPCODE_CORE | MindSpore Core code.|
| OH_AI_COMPCODE_MD   | MindSpore MindData code.|
| OH_AI_COMPCODE_ME   | MindSpore MindExpression code.|
| OH_AI_COMPCODE_MC   | MindSpore code.|
| OH_AI_COMPCODE_LITE | MindSpore Lite code.|


### OH_AI_DataType

```
enum OH_AI_DataType
```

**Description**

Declares data types supported by MSTensor.

**Since**: 9

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
| OH_AI_DATATYPE_NUMBERTYPE_UINT16 | UInt16 data.|
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

**Since**: 9

| Value| Description|
| -------- | -------- |
| OH_AI_DEVICETYPE_CPU | Device type: CPU|
| OH_AI_DEVICETYPE_GPU | GPU.<br>This configuration is open for upstream open source projects and is not supported by OpenHarmony.|
| OH_AI_DEVICETYPE_KIRIN_NPU | Kirin NPU.<br>This configuration is open for upstream open source projects and is not supported by OpenHarmony.<br>To use KIRIN_NPU, set **OH_AI_DEVICETYPE_NNRT**.|
| OH_AI_DEVICETYPE_NNRT | NNRt, a cross-chip inference and computing runtime oriented to the AI field.<br>OHOS device range: [60, 80)|
| OH_AI_DEVICETYPE_INVALID | Invalid device type.|


### OH_AI_Format

```
enum OH_AI_Format
```

**Description**

Declares data formats supported by MSTensor.

**Since**: 9

| Value| Description|
| -------- | -------- |
| OH_AI_FORMAT_NCHW | Tensor data is stored in the sequence of batch number N, channel C, height H, and width W.|
| OH_AI_FORMAT_NHWC | Tensor data is stored in the sequence of batch number N, height H, width W, and channel C.|
| OH_AI_FORMAT_NHWC4 | Tensor data is stored in the sequence of batch number N, height H, width W, and channel C. The C axis is 4-byte aligned.|
| OH_AI_FORMAT_HWKC | Tensor data is stored in the sequence of height H, width W, core count K, and channel C.|
| OH_AI_FORMAT_HWCK | Tensor data is stored in the sequence of height H, width W, channel C, and core count K.|
| OH_AI_FORMAT_KCHW | Tensor data is stored in the sequence of core count K, channel C, height H, and width W.|
| OH_AI_FORMAT_CKHW | Tensor data is stored in the sequence of channel C, core count K, height H, and width W.|
| OH_AI_FORMAT_KHWC | Tensor data is stored in the sequence of core count K, height H, width W, and channel C.|
| OH_AI_FORMAT_CHWK | Tensor data is stored in the sequence of channel C, height H, width W, and core count K.|
| OH_AI_FORMAT_HW | Tensor data is stored in the sequence of height H and width W.|
| OH_AI_FORMAT_HW4 | Tensor data is stored in the sequence of height H and width W. The W axis is 4-byte aligned.|
| OH_AI_FORMAT_NC | Tensor data is stored in the sequence of batch number N and channel C.|
| OH_AI_FORMAT_NC4 | Tensor data is stored in the sequence of batch number N and channel C. The C axis is 4-byte aligned.|
| OH_AI_FORMAT_NC4HW4 | Tensor data is stored in the sequence of batch number N, channel C, height H, and width W. The C axis and W axis are 4-byte aligned.|
| OH_AI_FORMAT_NCDHW | Tensor data is stored in the sequence of batch number N, channel C, depth D, height H, and width W.|
| OH_AI_FORMAT_NWC | Tensor data is stored in the sequence of batch number N, width W, and channel C.|
| OH_AI_FORMAT_NCW | Tensor data is stored in the sequence of batch number N, channel C, and width W.|


### OH_AI_ModelType

```
enum OH_AI_ModelType
```

**Description**

Defines model file types.

**Since**: 9

| Value| Description|
| -------- | -------- |
| OH_AI_MODELTYPE_MINDIR | Model type of MindIR. The extension of the model file name is **.ms**.|
| OH_AI_MODELTYPE_INVALID | Invalid model type.|


### OH_AI_NNRTDeviceType

```
enum OH_AI_NNRTDeviceType
```

**Description**

Defines NNRt device types.

**Since**: 10

| Value| Description|
| -------- | -------- |
| OH_AI_NNRTDEVICE_OTHERS | Others (any device type except the following three types).|
| OH_AI_NNRTDEVICE_CPU | CPU.|
| OH_AI_NNRTDEVICE_GPU | GPU.|
| OH_AI_NNRTDEVICE_ACCELERATOR | Specific acceleration device.|


### OH_AI_OptimizationLevel

```
enum OH_AI_OptimizationLevel
```

**Description**

Defines training optimization levels.

**Since**

**11**

| Value| Description|
| -------- | -------- |
| OH_AI_KO0 | No optimization level.|
| OH_AI_KO2 | Converts the precision type of the network to float16 and keeps the precision type of the batch normalization layer and loss function as float32.|
| OH_AI_KO3 | Converts the precision type of the network (including the batch normalization layer) to float16.|
| OH_AI_KAUTO | Selects an optimization level based on the device.|
| OH_AI_KOPTIMIZATIONTYPE | Invalid optimization level.|


### OH_AI_PerformanceMode

```
enum OH_AI_PerformanceMode
```

**Description**

Defines performance modes of the NNRt device.

**Since**: 10

| Value| Description|
| -------- | -------- |
| OH_AI_PERFORMANCE_NONE | No special settings.|
| OH_AI_PERFORMANCE_LOW | Low power consumption.|
| OH_AI_PERFORMANCE_MEDIUM | Power consumption and performance balancing.|
| OH_AI_PERFORMANCE_HIGH | High performance.|
| OH_AI_PERFORMANCE_EXTREME | Ultimate performance.|


### OH_AI_Priority

```
enum OH_AI_Priority
```

**Description**

Defines NNRt inference task priorities.

**Since**: 10

| Value| Description|
| -------- | -------- |
| OH_AI_PRIORITY_NONE | No priority preference.|
| OH_AI_PRIORITY_LOW | Low priority.|
| OH_AI_PRIORITY_MEDIUM | Medium priority.|
| OH_AI_PRIORITY_HIGH | High priority.|


### OH_AI_QuantizationType

```
enum OH_AI_QuantizationType
```

**Description**

Defines quantization types.

**Since**

**11**

| Value| Description|
| -------- | -------- |
| OH_AI_NO_QUANT | No quantification.|
| OH_AI_WEIGHT_QUANT | Weight quantization.|
| OH_AI_FULL_QUANT | Full quantization.|
| OH_AI_UNKNOWN_QUANT_TYPE | Invalid quantization type.|


### OH_AI_Status

```
enum OH_AI_Status
```

**Description**

Defines MindSpore status codes.

**Since**: 9

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
| OH_AI_STATUS_LITE_NOT_SUPPORT | MindSpore Lite function not supported.|
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


## Function Description


### OH_AI_ContextAddDeviceInfo()

```
OH_AI_API void OH_AI_ContextAddDeviceInfo (OH_AI_ContextHandle context, OH_AI_DeviceInfoHandle device_info )
```

**Description**

Attaches the custom device information to the inference context.

**Since**: 9

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

Creates a context object. This API must be used together with [OH_AI_ContextDestroy](#oh_ai_contextdestroy).

**Since**: 9

**Returns**

[OH_AI_ContextHandle](#oh_ai_contexthandle) that points to the context instance.


### OH_AI_ContextDestroy()

```
OH_AI_API void OH_AI_ContextDestroy (OH_AI_ContextHandle * context)
```

**Description**

Destroys a context object.

**Since**: 9

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

**Since**: 9

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

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| context | [OH_AI_ContextHandle](#oh_ai_contexthandle) that points to the context instance.|
| core_num | Number of CPU cores.|

**Returns**

CPU core binding list. This list is managed by [OH_AI_ContextHandle](#oh_ai_contexthandle). The caller does not need to destroy it manually.


### OH_AI_ContextGetThreadAffinityMode()

```
OH_AI_API int OH_AI_ContextGetThreadAffinityMode (const OH_AI_ContextHandle context)
```

**Description**

Obtains the affinity mode for binding runtime threads to CPU cores.

**Since**: 9

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

**Since**: 9

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

**Since**: 9

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

**Since**: 9

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

**Since**: 9

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

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| context | [OH_AI_ContextHandle](#oh_ai_contexthandle) that points to the context instance.|
| thread_num | Number of runtime threads.|


### OH_AI_CreateNNRTDeviceInfoByName()

```
OH_AI_API OH_AI_DeviceInfoHandle OH_AI_CreateNNRTDeviceInfoByName (const char * name)
```

**Description**

Searches for the NNRt device with the specified name and creates the NNRt device information based on the information about the first found NNRt device.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| name | Name of the target NNRt device.|

**Returns**

[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.


### OH_AI_CreateNNRTDeviceInfoByType()

```
OH_AI_API OH_AI_DeviceInfoHandle OH_AI_CreateNNRTDeviceInfoByType (OH_AI_NNRTDeviceType type)
```

**Description**

Searches for the NNRt device with the specified type and creates the NNRt device information based on the information about the first found NNRt device.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| type | NNRt device type, which is specified by [OH_AI_NNRTDeviceType](#oh_ai_nnrtdevicetype).|

**Returns**

[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.


### OH_AI_DestroyAllNNRTDeviceDescs()

```
OH_AI_API void OH_AI_DestroyAllNNRTDeviceDescs (NNRTDeviceDesc ** desc)
```

**Description**

Destroys the NNRt device description array obtained by [OH_AI_GetAllNNRTDeviceDescs](#oh_ai_getallnnrtdevicedescs).

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| desc | Double pointer to the array of the NNRt device descriptions. After the operation is complete, the content pointed to by **desc** is set to **NULL**.|


### OH_AI_DeviceInfoAddExtension()

```
OH_AI_API OH_AI_Status OH_AI_DeviceInfoAddExtension (OH_AI_DeviceInfoHandle device_info, const char * name, const char * value, size_t value_size )
```

**Description**

Adds extended configuration in the form of key/value pairs to the device information. This function is available only for NNRt devices.

Note: Currently, only 11 key-value pairs are supported, including: {"CachePath": "YourCachePath"}, {"CacheVersion": "YouCacheVersion"}, {"QuantBuffer": "YourQuantBuffer"}, {"ModelName": "YourModelName"}, {"isProfiling": "YourisProfiling"}, {"opLayout": "YouropLayout"}, {"InputDims": "YourInputDims"}, {"DynamicDims": "YourDynamicDims"}, {"QuantConfigData": "YourQuantConfigData"}, {"BandMode": "YourBandMode"}, {"NPU_FM_SHARED": "YourNPU_FM_SHARED"}. Replace them as required.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|
| name | Key in an extended key/value pair. The value is a C string.|
| value |  Start address of the value in an extended key/value pair.|
| value_size | Length of the value in an extended key/value pair.|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.


### OH_AI_DeviceInfoCreate()

```
OH_AI_API OH_AI_DeviceInfoHandle OH_AI_DeviceInfoCreate (OH_AI_DeviceType device_type)
```

**Description**

Creates a device information object.

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| device_type | Device type, which is specified by [OH_AI_DeviceType](#oh_ai_devicetype).|

**Returns**

[OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.


### OH_AI_DeviceInfoDestroy()

```
OH_AI_API void OH_AI_DeviceInfoDestroy (OH_AI_DeviceInfoHandle * device_info)
```

**Description**

Destroys a device information object. Note: After the device information instance is added to the context, the caller does not need to destroy it manually.

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|


### OH_AI_DeviceInfoGetDeviceId()

```
OH_AI_API size_t OH_AI_DeviceInfoGetDeviceId (const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Obtains the NNRt device ID. This function is available only for NNRt devices.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|

**Returns**

NNRt device ID.


### OH_AI_DeviceInfoGetDeviceType()

```
OH_AI_API OH_AI_DeviceType OH_AI_DeviceInfoGetDeviceType (const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Obtains the device type.

**Since**: 9

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

**Since**: 9

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

Obtains the NPU frequency type. This function is available only for NPU devices.

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|

**Returns**

NPU frequency type. The value ranges from **0** to **4**. **1**: low power consumption; **2**: balanced; **3**: high performance; **4**: ultra-high performance


### OH_AI_DeviceInfoGetPerformanceMode()

```
OH_AI_API OH_AI_PerformanceMode OH_AI_DeviceInfoGetPerformanceMode (const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Obtains the NNRt performance mode. This function is available only for NNRt devices.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|

**Returns**

NNRt performance mode, which is specified by [OH_AI_PerformanceMode](#oh_ai_performancemode).


### OH_AI_DeviceInfoGetPriority()

```
OH_AI_API OH_AI_Priority OH_AI_DeviceInfoGetPriority (const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Obtains the priority of an NNRt task. This function is available only for NNRt devices.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|

**Returns**

NNRt task priority, which is specified by [OH_AI_Priority](#oh_ai_priority).


### OH_AI_DeviceInfoGetProvider()

```
OH_AI_API const char* OH_AI_DeviceInfoGetProvider (const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Obtains the provider name.

**Since**: 9

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

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|

**Returns**

Name of the provider device.


### OH_AI_DeviceInfoSetDeviceId()

```
OH_AI_API void OH_AI_DeviceInfoSetDeviceId (OH_AI_DeviceInfoHandle device_info, size_t device_id )
```

**Description**

Sets the NNRt device ID. This function is available only for NNRt devices.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|
| device_id | NNRt device ID.|


### OH_AI_DeviceInfoSetEnableFP16()

```
OH_AI_API void OH_AI_DeviceInfoSetEnableFP16 (OH_AI_DeviceInfoHandle device_info, bool is_fp16 )
```

**Description**

Sets whether to enable float16 inference. This function is available only for CPU and GPU devices.

**Since**: 9

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

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|
| frequency | NPU frequency type. The value ranges from **0** to **4**. The default value is **3**. **1**: low power consumption; **2**: balanced; **3**: high performance; **4**: ultra-high performance|


### OH_AI_DeviceInfoSetPerformanceMode()

```
OH_AI_API void OH_AI_DeviceInfoSetPerformanceMode (OH_AI_DeviceInfoHandle device_info, OH_AI_PerformanceMode mode )
```

**Description**

Sets the NNRt performance mode. This function is available only for NNRt devices.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|
| mode | NNRt performance mode, which is specified by [OH_AI_PerformanceMode](#oh_ai_performancemode).|


### OH_AI_DeviceInfoSetPriority()

```
OH_AI_API void OH_AI_DeviceInfoSetPriority (OH_AI_DeviceInfoHandle device_info, OH_AI_Priority priority )
```

**Description**

Sets the priority of an NNRt task. This function is available only for NNRt devices.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|
| priority | NNRt task priority, which is specified by [OH_AI_Priority](#oh_ai_priority).|


### OH_AI_DeviceInfoSetProvider()

```
OH_AI_API void OH_AI_DeviceInfoSetProvider (OH_AI_DeviceInfoHandle device_info, const char * provider )
```

**Description**

Sets the name of the provider.

**Since**: 9

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

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| device_info | [OH_AI_DeviceInfoHandle](#oh_ai_deviceinfohandle) that points to a device information instance.|
| device | Name of the provider device, for example, CPU.|


### OH_AI_ExportModel()

```
OH_AI_API OH_AI_Status OH_AI_ExportModel (OH_AI_ModelHandle model, OH_AI_ModelType model_type, const char * model_file, OH_AI_QuantizationType quantization_type, bool export_inference_only, char ** output_tensor_name, size_t num )
```

**Description**

Exports a training model. This API is used only for on-device training.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|
| model_type | Model file type, which is specified by [OH_AI_ModelType](#oh_ai_modeltype).|
| model_file | Path of the exported model file.|
| quantization_type | Quantization type.|
| export_inference_only | Whether to export an inference model.|
| output_tensor_name | Output tensor of the exported model. This parameter is left blank by default, which indicates full export.|
| num | Number of output tensors.|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.

### OH_AI_ExportModelBuffer()

```
OH_AI_API OH_AI_Status OH_AI_ExportModelBuffer (OH_AI_ModelHandle model, OH_AI_ModelType model_type, char ** model_data, size_t * data_size, OH_AI_QuantizationType quantization_type, bool export_inference_only, char ** output_tensor_name, size_t num )
```
**Description**
Exports the memory cache of the training model. This API is used only for on-device training.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object. |
| model_type | Model file type, which is specified by [OH_AI_ModelType](#oh_ai_modeltype). |
| model_data | Pointer to the buffer that stores the exported model file. |
| data_size | Buffer size. |
| quantization_type | Quantization type. |
| export_inference_only | Whether to export an inference model. |
| output_tensor_name | Output tensor of the exported model. This parameter is left blank by default, which indicates full export. |
| num | Number of output tensors. |

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.


### OH_AI_ExportWeightsCollaborateWithMicro()

```
OH_AI_API OH_AI_Status OH_AI_ExportWeightsCollaborateWithMicro (OH_AI_ModelHandle model, OH_AI_ModelType model_type, const char * weight_file, bool is_inference, bool enable_fp16, char ** changeable_weights_name, size_t num )
```

**Description**

Exports the weight file of the training model for micro inference. This API is used only for on-device training.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|
| model_type | Model file type, which is specified by [OH_AI_ModelType](#oh_ai_modeltype).|
| weight_file | Path of the exported weight file.|
| is_inference | Whether to export inference models. Currently, this parameter can only be set to **true**.|
| enable_fp16 | Whether to save floating-point weights in float16 format.|
| changeable_weights_name | Name of the weight tensor with a variable shape.|
| num | Number of weight tensors with a variable shape.|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.


### OH_AI_GetAllNNRTDeviceDescs()

```
OH_AI_API NNRTDeviceDesc* OH_AI_GetAllNNRTDeviceDescs (size_t * num)
```

**Description**

Obtains the descriptions of all NNRt devices in the system.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| num | Number of NNRt devices.|

**Returns**

Pointer to the array of the NNRt device descriptions. If the operation fails, **NULL** is returned.


### OH_AI_GetDeviceIdFromNNRTDeviceDesc()

```
OH_AI_API size_t OH_AI_GetDeviceIdFromNNRTDeviceDesc (const NNRTDeviceDesc * desc)
```

**Description**

Obtains the NNRt device ID from the specified NNRt device description. Note that this ID is valid only for NNRt devices.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| desc | Pointer to the NNRt device description.|

**Returns**

NNRt device ID.


### OH_AI_GetElementOfNNRTDeviceDescs()

```
OH_AI_API NNRTDeviceDesc* OH_AI_GetElementOfNNRTDeviceDescs (NNRTDeviceDesc * descs, size_t index )
```

**Description**

Obtains the pointer to an element in the NNRt device description array.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| descs | NNRt device description array.|
| index | Index of an array element.|

**Returns**

Pointer to an element in the NNRt device description array.


### OH_AI_GetNameFromNNRTDeviceDesc()

```
OH_AI_API const char* OH_AI_GetNameFromNNRTDeviceDesc (const NNRTDeviceDesc * desc)
```

**Description**

Obtains the NNRt device name from the specified NNRt device description.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| desc | Pointer to the NNRt device description.|

**Returns**

NNRt device name. The value is a pointer that points to a constant string, which is held by **desc**. The caller does not need to destroy it separately.


### OH_AI_GetTypeFromNNRTDeviceDesc()

```
OH_AI_API OH_AI_NNRTDeviceType OH_AI_GetTypeFromNNRTDeviceDesc (const NNRTDeviceDesc * desc)
```

**Description**

Obtains the NNRt device type from the specified NNRt device description.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| desc | Pointer to the NNRt device description.|

**Returns**

NNRt device type, which is specified by [OH_AI_NNRTDeviceType](#oh_ai_nnrtdevicetype).


### OH_AI_ModelBuild()

```
OH_AI_API OH_AI_Status OH_AI_ModelBuild (OH_AI_ModelHandle model, const void * model_data, size_t data_size, OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context )
```

**Description**

Loads and builds a MindSpore model from the memory buffer.

Note that the same {\@Link OH_AI_ContextHandle} object can only be passed to {\@Link OH_AI_ModelBuild} or {\@Link OH_AI_ModelBuildFromFile} once. If you call this function multiple times, make sure that you create multiple {\@Link OH_AI_ContextHandle} objects accordingly.

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|
| model_data | Address of the loaded model data in the memory.|
| data_size | Length of the model data.|
| model_type | Model file type, which is specified by [OH_AI_ModelType](#oh_ai_modeltype).|
| model_context | Model runtime context, which is specified by [OH_AI_ContextHandle](#oh_ai_contexthandle).|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.


### OH_AI_ModelBuildFromFile()

```
OH_AI_API OH_AI_Status OH_AI_ModelBuildFromFile (OH_AI_ModelHandle model, const char * model_path, OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context )
```

**Description**

Loads and builds a MindSpore model from a model file.

Note that the same {\@Link OH_AI_ContextHandle} object can only be passed to {\@Link OH_AI_ModelBuild} or {\@Link OH_AI_ModelBuildFromFile} once. If you call this function multiple times, make sure that you create multiple {\@Link OH_AI_ContextHandle} objects accordingly.

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|
| model_path | Path of the model file.|
| model_type | Model file type, which is specified by [OH_AI_ModelType](#oh_ai_modeltype).|
| model_context | Model runtime context, which is specified by [OH_AI_ContextHandle](#oh_ai_contexthandle).|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.


### OH_AI_ModelCreate()

```
OH_AI_API OH_AI_ModelHandle OH_AI_ModelCreate ()
```

**Description**

Creates a model object.

**Since**: 9

**Returns**

Pointer to the model object.


### OH_AI_ModelDestroy()

```
OH_AI_API void OH_AI_ModelDestroy (OH_AI_ModelHandle * model)
```

**Description**

Destroys a model object.

**Since**: 9

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

**Since**: 9

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

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|

**Returns**

Tensor array structure corresponding to the model input.


### OH_AI_ModelGetLearningRate()

```
OH_AI_API float OH_AI_ModelGetLearningRate (OH_AI_ModelHandle model)
```

**Description**

Obtains the learning rate for model training. This API is used only for on-device training.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|

**Returns**

Learning rate. If no optimizer is set, the value is **0.0**.


### OH_AI_ModelGetOutputByTensorName()

```
OH_AI_API OH_AI_TensorHandle OH_AI_ModelGetOutputByTensorName (const OH_AI_ModelHandle model, const char * tensor_name )
```

**Description**

Obtains the output tensor of a model by tensor name.

**Since**: 9

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

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|

**Returns**

Tensor array structure corresponding to the model output.


### OH_AI_ModelGetTrainMode()

```
OH_AI_API bool OH_AI_ModelGetTrainMode (OH_AI_ModelHandle model)
```

**Description**

Obtains the training mode.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|

**Returns**

Whether the training mode is used.


### OH_AI_ModelGetWeights()

```
OH_AI_API OH_AI_TensorHandleArray OH_AI_ModelGetWeights (OH_AI_ModelHandle model)
```

**Description**

Obtains all weight tensors of a model. This API is used only for on-device training.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|

**Returns**

All weight tensors of the model.


### OH_AI_ModelPredict()

```
OH_AI_API OH_AI_Status OH_AI_ModelPredict (OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs, OH_AI_TensorHandleArray * outputs, const OH_AI_KernelCallBack before, const OH_AI_KernelCallBack after )
```

**Description**

Performs model inference.

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|
| inputs | Tensor array structure corresponding to the model input.|
| outputs | Pointer to the tensor array structure corresponding to the model output.|
| before | Callback function executed before model inference.|
| after | Callback function executed after model inference.|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.


### OH_AI_ModelResize()

```
OH_AI_API OH_AI_Status OH_AI_ModelResize (OH_AI_ModelHandle model, const OH_AI_TensorHandleArray inputs, OH_AI_ShapeInfo * shape_infos, size_t shape_info_num )
```

**Description**

Adjusts the input tensor shapes of a built model.

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|
| inputs | Tensor array structure corresponding to the model input.|
| shape_infos | Input shape information array, which consists of tensor shapes arranged in the model input sequence. The model adjusts the tensor shapes in sequence.|
| shape_info_num | Length of the shape information array.|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.


### OH_AI_ModelSetLearningRate()

```
OH_AI_API OH_AI_Status OH_AI_ModelSetLearningRate (OH_AI_ModelHandle model, float learning_rate )
```

**Description**

Sets the learning rate for model training. This API is used only for on-device training.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| learning_rate | Learning rate.|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.


### OH_AI_ModelSetTrainMode()

```
OH_AI_API OH_AI_Status OH_AI_ModelSetTrainMode (OH_AI_ModelHandle model, bool train )
```

**Description**

Sets the training mode. This API is used only for on-device training.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|
| train | Whether the training mode is used.|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.


### OH_AI_ModelSetupVirtualBatch()

```
OH_AI_API OH_AI_Status OH_AI_ModelSetupVirtualBatch (OH_AI_ModelHandle model, int virtual_batch_multiplier, float lr, float momentum )
```

**Description**

Sets the virtual batch for training. This API is used only for on-device training.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|
| virtual_batch_multiplier | Virtual batch multiplier. If the value is less than **1**, the virtual batch is disabled.|
| lr | Learning rate. The default value is **-1.0f**.|
| momentum | Momentum. The default value is **-1.0f**.|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.


### OH_AI_ModelUpdateWeights()

```
OH_AI_API OH_AI_Status OH_AI_ModelUpdateWeights (OH_AI_ModelHandle model, const OH_AI_TensorHandleArray new_weights )
```

**Description**

Updates the weight tensors of a model. This API is used only for on-device training.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| new_weights | Weight tensors to be updated.|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.


### OH_AI_RunStep()

```
OH_AI_API OH_AI_Status OH_AI_RunStep (OH_AI_ModelHandle model, const OH_AI_KernelCallBack before, const OH_AI_KernelCallBack after )
```

**Description**

Defines a single-step training model. This API is used only for on-device training.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|
| before | Callback function executed before model inference.|
| after | Callback function executed after model inference.|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.


### OH_AI_TensorClone()

```
OH_AI_API OH_AI_TensorHandle OH_AI_TensorClone (OH_AI_TensorHandle tensor)
```

**Description**

Clones a tensor.

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Pointer to the tensor to clone.|

**Returns**

Handle of a tensor object.


### OH_AI_TensorCreate()

```
OH_AI_API OH_AI_TensorHandle OH_AI_TensorCreate (const char * name, OH_AI_DataType type, const int64_t * shape, size_t shape_num, const void * data, size_t data_len )
```

**Description**

Creates a tensor object.

**Since**: 9

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

Handle of a tensor object.

### OH_AI_TensorGetAllocator()

```
OH_AI_API OH_AI_AllocatorHandle OH_AI_TensorGetAllocator(OH_AI_TensorHandle tensor)
```

**Description**

Obtains a memory allocator. The allocator is responsible for allocating memory for tensors.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|

**Returns**

Handle of the memory allocator.


### OH_AI_TensorDestroy()

```
OH_AI_API void OH_AI_TensorDestroy (OH_AI_TensorHandle * tensor)
```

**Description**

Destroys a tensor object.

**Since**: 9

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

**Since**: 9

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

**Since**: 9

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

**Since**: 9

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

**Since**: 9

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

**Since**: 9

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

**Since**: 9

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

Obtains the tensor name.

**Since**: 9

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

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|
| shape_num | Length of the tensor shape array.|

**Returns**

Shape array.

### OH_AI_TensorSetAllocator()

```
OH_AI_API OH_AI_Status OH_AI_TensorSetAllocator(OH_AI_TensorHandle tensor, OH_AI_AllocatorHandle allocator)
```

**Description**

Sets the memory allocator. The allocator is responsible for allocating memory for tensors.

**Since**: 12

**Parameters**

| Name     | Description                |
| --------- | -------------------- |
| tensor    | Handle of the tensor object.      |
| allocator | Handle of the memory allocator.|

**Returns**

Execution status code. The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.


### OH_AI_TensorSetData()

```
OH_AI_API void OH_AI_TensorSetData (OH_AI_TensorHandle tensor, void * data )
```

**Description**

Sets the tensor data.

**Since**: 9

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

Sets the data type of a tensor.

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|
| type | Data type, which is specified by [OH_AI_DataType](#oh_ai_datatype).|


### OH_AI_TensorSetFormat()

```
OH_AI_API void OH_AI_TensorSetFormat (OH_AI_TensorHandle tensor, OH_AI_Format format )
```

**Description**

Sets the tensor data format.

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|
| format | Tensor data format.|


### OH_AI_TensorSetName()

```
OH_AI_API void OH_AI_TensorSetName (OH_AI_TensorHandle tensor, const char * name )
```

**Description**

Sets the tensor name.

**Since**: 9

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

**Since**: 9

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|
| shape | Shape array.|
| shape_num | Length of the tensor shape array.|


### OH_AI_TensorSetUserData()

```
OH_AI_API OH_AI_Status OH_AI_TensorSetUserData (OH_AI_TensorHandle tensor, void * data, size_t data_size )
```

**Description**

Sets the tensor as the user data. This function allows you to reuse user data as the model input, which helps to reduce data copy by one time. > **NOTE**<br>The user data is type of external data for the tensor and is not automatically released when the tensor is destroyed. The caller needs to release the data separately. In addition, the caller must ensure that the user data is valid during use of the tensor.

**Since**: 10

**Parameters**

| Name| Description|
| -------- | -------- |
| tensor | Handle of the tensor object.|
| data | Start address of user data.|
| data_size | Length of the user data length.|

**Returns**

Execution status code. The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.


### OH_AI_TrainCfgCreate()

```
OH_AI_API OH_AI_TrainCfgHandle OH_AI_TrainCfgCreate ()
```

**Description**

Creates the pointer to the training configuration object. This API is used only for on-device training.

**Since**: 11

**Returns**

Pointer to the training configuration object.


### OH_AI_TrainCfgDestroy()

```
OH_AI_API void OH_AI_TrainCfgDestroy (OH_AI_TrainCfgHandle * train_cfg)
```

**Description**

Destroys the pointer to the training configuration object. This API is used only for on-device training.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| train_cfg | Pointer to the training configuration object.|


### OH_AI_TrainCfgGetLossName()

```
OH_AI_API char** OH_AI_TrainCfgGetLossName (OH_AI_TrainCfgHandle train_cfg, size_t * num )
```

**Description**

Obtains the list of loss functions, which are used only for on-device training.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| train_cfg | Pointer to the training configuration object.|
| num | Number of loss functions.|

**Returns**

List of loss functions.


### OH_AI_TrainCfgGetOptimizationLevel()

```
OH_AI_API OH_AI_OptimizationLevel OH_AI_TrainCfgGetOptimizationLevel (OH_AI_TrainCfgHandle train_cfg)
```

**Description**

Obtains the optimization level of the training configuration object. This API is used only for on-device training.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| train_cfg | Pointer to the training configuration object.|

**Returns**

Optimization level.


### OH_AI_TrainCfgSetLossName()

```
OH_AI_API void OH_AI_TrainCfgSetLossName (OH_AI_TrainCfgHandle train_cfg, const char ** loss_name, size_t num )
```

**Description**

Sets the list of loss functions, which are used only for on-device training.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| train_cfg | Pointer to the training configuration object.|
| loss_name | List of loss functions.|
| num | Number of loss functions.|


### OH_AI_TrainCfgSetOptimizationLevel()

```
OH_AI_API void OH_AI_TrainCfgSetOptimizationLevel (OH_AI_TrainCfgHandle train_cfg, OH_AI_OptimizationLevel level )
```

**Description**

Sets the optimization level of the training configuration object. This API is used only for on-device training.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| train_cfg | Pointer to the training configuration object.|
| level | Optimization level.|


### OH_AI_TrainModelBuild()

```
OH_AI_API OH_AI_Status OH_AI_TrainModelBuild (OH_AI_ModelHandle model, const void * model_data, size_t data_size, OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context, const OH_AI_TrainCfgHandle train_cfg )
```

**Description**

Loads a training model from the memory buffer and compiles the model to a state ready for running on the device. This API is used only for on-device training.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|
| model_data | Pointer to the buffer for storing the model file to be read.|
| data_size | Buffer size.|
| model_type | Model file type, which is specified by [OH_AI_ModelType](#oh_ai_modeltype).|
| model_context | Model runtime context, which is specified by [OH_AI_ContextHandle](#oh_ai_contexthandle).|
| train_cfg | Pointer to the training configuration object.|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.


### OH_AI_TrainModelBuildFromFile()

```
OH_AI_API OH_AI_Status OH_AI_TrainModelBuildFromFile (OH_AI_ModelHandle model, const char * model_path, OH_AI_ModelType model_type, const OH_AI_ContextHandle model_context, const OH_AI_TrainCfgHandle train_cfg )
```

**Description**

Loads the training model from the specified path and compiles the model to a state ready for running on the device. This API is used only for on-device training.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| model | Pointer to the model object.|
| model_path | Path of the model file.|
| model_type | Model file type, which is specified by [OH_AI_ModelType](#oh_ai_modeltype).|
| model_context | Model runtime context, which is specified by [OH_AI_ContextHandle](#oh_ai_contexthandle).|
| train_cfg | Pointer to the training configuration object.|

**Returns**

Status code enumerated by [OH_AI_Status](#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.
