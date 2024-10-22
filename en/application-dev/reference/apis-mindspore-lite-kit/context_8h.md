# context.h


## Overview

Provides context-related APIs for configuring runtime information. These APIs are non-thread-safe.

**Since**

9

**Related Modules**

[MindSpore](_mind_spore.md)


## Summary


### Types

| Name| Description|
| -------- | -------- |
| [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) | Defines the pointer to the MindSpore context. |
| [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) | Defines the pointer to the MindSpore device information.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_AI_ContextCreate](_mind_spore.md#oh_ai_contextcreate) () | Creates a context object.|
| [OH_AI_ContextDestroy](_mind_spore.md#oh_ai_contextdestroy) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) \*context) | Destroys a context object.|
| [OH_AI_ContextSetThreadNum](_mind_spore.md#oh_ai_contextsetthreadnum) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, int32_t thread_num) | Sets the number of runtime threads.|
| [OH_AI_ContextGetThreadNum](_mind_spore.md#oh_ai_contextgetthreadnum) (const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context) | Obtains the number of threads.|
| [OH_AI_ContextSetThreadAffinityMode](_mind_spore.md#oh_ai_contextsetthreadaffinitymode) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, int mode) | Sets the affinity mode for binding runtime threads to CPU cores, which are classified into large, medium, and small cores based on the CPU frequency. You only need to bind the large or medium cores, but not small cores.|
| [OH_AI_ContextGetThreadAffinityMode](_mind_spore.md#oh_ai_contextgetthreadaffinitymode) (const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context) | Obtains the affinity mode for binding runtime threads to CPU cores.|
| [OH_AI_ContextSetThreadAffinityCoreList](_mind_spore.md#oh_ai_contextsetthreadaffinitycorelist) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, const int32_t \*core_list, size_t core_num) | Sets the list of CPU cores bound to a runtime thread.|
| [OH_AI_ContextGetThreadAffinityCoreList](_mind_spore.md#oh_ai_contextgetthreadaffinitycorelist) (const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, size_t \*core_num) | Obtains the list of bound CPU cores.|
| [OH_AI_ContextSetEnableParallel](_mind_spore.md#oh_ai_contextsetenableparallel) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, bool is_parallel) | Sets whether to enable parallelism between operators. The setting is ineffective because the feature of this API is not yet available.|
| [OH_AI_ContextGetEnableParallel](_mind_spore.md#oh_ai_contextgetenableparallel) (const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context) | Checks whether parallelism between operators is supported.|
| [OH_AI_ContextAddDeviceInfo](_mind_spore.md#oh_ai_contextadddeviceinfo) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | Attaches the custom device information to the inference context.|
| [OH_AI_DeviceInfoCreate](_mind_spore.md#oh_ai_deviceinfocreate) ([OH_AI_DeviceType](_mind_spore.md#oh_ai_devicetype) device_type) | Creates a device information object.|
| [OH_AI_DeviceInfoDestroy](_mind_spore.md#oh_ai_deviceinfodestroy) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) \*device_info) | Destroys a device information object. Note: After the device information instance is added to the context, the caller does not need to destroy it manually.|
| [OH_AI_DeviceInfoSetProvider](_mind_spore.md#oh_ai_deviceinfosetprovider) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, const char \*provider) | Sets the provider name.|
| [OH_AI_DeviceInfoGetProvider](_mind_spore.md#oh_ai_deviceinfogetprovider) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | Obtains the provider name.|
| [OH_AI_DeviceInfoSetProviderDevice](_mind_spore.md#oh_ai_deviceinfosetproviderdevice) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, const char \*device) | Sets the name of a provider device.|
| [OH_AI_DeviceInfoGetProviderDevice](_mind_spore.md#oh_ai_deviceinfogetproviderdevice) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | Obtains the name of a provider device.|
| [OH_AI_DeviceInfoGetDeviceType](_mind_spore.md#oh_ai_deviceinfogetdevicetype) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | Obtains the device type.|
| [OH_AI_DeviceInfoSetEnableFP16](_mind_spore.md#oh_ai_deviceinfosetenablefp16) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, bool is_fp16) | Sets whether to enable float16 inference. This function is available only for CPU and GPU devices.|
| [OH_AI_DeviceInfoGetEnableFP16](_mind_spore.md#oh_ai_deviceinfogetenablefp16) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | Checks whether float16 inference is enabled. This function is available only for CPU and GPU devices.|
| [OH_AI_DeviceInfoSetFrequency](_mind_spore.md#oh_ai_deviceinfosetfrequency) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, int frequency) | Sets the NPU frequency type. This function is available only for NPU devices.|
| [OH_AI_DeviceInfoGetFrequency](_mind_spore.md#oh_ai_deviceinfogetfrequency) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | Obtains the NPU frequency type. This function is available only for NPU devices.|
| [OH_AI_GetAllNNRTDeviceDescs](_mind_spore.md#oh_ai_getallnnrtdevicedescs) (size_t \*num) | Obtains the descriptions of all NNRt devices in the system.|
| [OH_AI_GetElementOfNNRTDeviceDescs](_mind_spore.md#oh_ai_getelementofnnrtdevicedescs) (NNRTDeviceDesc \*descs, size_t index) | Obtains the pointer to an element in the NNRt device description array.|
| [OH_AI_DestroyAllNNRTDeviceDescs](_mind_spore.md#oh_ai_destroyallnnrtdevicedescs) ([NNRTDeviceDesc](_mind_spore.md#nnrtdevicedesc) \*\*desc) | Destroys the NNRt device description array obtained by [OH_AI_GetAllNNRTDeviceDescs](_mind_spore.md#oh_ai_getallnnrtdevicedescs).|
| [OH_AI_GetDeviceIdFromNNRTDeviceDesc](_mind_spore.md#oh_ai_getdeviceidfromnnrtdevicedesc) (const [NNRTDeviceDesc](_mind_spore.md#nnrtdevicedesc) \*desc) | Obtains the NNRt device ID from the specified NNRt device description. Note that this ID is valid only for NNRt devices.|
| [OH_AI_GetNameFromNNRTDeviceDesc](_mind_spore.md#oh_ai_getnamefromnnrtdevicedesc) (const [NNRTDeviceDesc](_mind_spore.md#nnrtdevicedesc) \*desc) | Obtains the NNRt device name from the specified NNRt device description.|
| [OH_AI_GetTypeFromNNRTDeviceDesc](_mind_spore.md#oh_ai_gettypefromnnrtdevicedesc) (const [NNRTDeviceDesc](_mind_spore.md#nnrtdevicedesc) \*desc) | Obtains the NNRt device type from the specified NNRt device description.|
| [OH_AI_CreateNNRTDeviceInfoByName](_mind_spore.md#oh_ai_creatennrtdeviceinfobyname) (const char \*name) | Searches for the NNRt device with the specified name and creates the NNRt device information based on the information about the first found NNRt device.|
| [OH_AI_CreateNNRTDeviceInfoByType](_mind_spore.md#oh_ai_creatennrtdeviceinfobytype) ([OH_AI_NNRTDeviceType](_mind_spore.md#oh_ai_nnrtdevicetype) type) | Searches for the NNRt device with the specified type and creates the NNRt device information based on the information about the first found NNRt device.|
| [OH_AI_DeviceInfoSetDeviceId](_mind_spore.md#oh_ai_deviceinfosetdeviceid) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, size_t device_id) | Sets the ID of an NNRt device. This function is available only for NNRt devices.|
| [OH_AI_DeviceInfoGetDeviceId](_mind_spore.md#oh_ai_deviceinfogetdeviceid) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | Obtains the ID of an NNRt device. This function is available only for NNRt devices.|
| [OH_AI_DeviceInfoSetPerformanceMode](_mind_spore.md#oh_ai_deviceinfosetperformancemode) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, [OH_AI_PerformanceMode](_mind_spore.md#oh_ai_performancemode) mode) | Sets the performance mode of an NNRt device. This function is available only for NNRt devices.|
| [OH_AI_DeviceInfoGetPerformanceMode](_mind_spore.md#oh_ai_deviceinfogetperformancemode) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | Obtains the performance mode of an NNRt device. This function is available only for NNRt devices.|
| [OH_AI_DeviceInfoSetPriority](_mind_spore.md#oh_ai_deviceinfosetpriority) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, [OH_AI_Priority](_mind_spore.md#oh_ai_priority) priority) | Sets the priority of an NNRt task. This function is available only for NNRt devices.|
| [OH_AI_DeviceInfoGetPriority](_mind_spore.md#oh_ai_deviceinfogetpriority) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | Obtains the priority of an NNRt task. This function is available only for NNRt devices.|
| [OH_AI_DeviceInfoAddExtension](_mind_spore.md#oh_ai_deviceinfoaddextension) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, const char \*name, const char \*value, size_t value_size) | Adds extended configuration in the form of key/value pairs to the device information. This function is available only for NNRt device information.|
