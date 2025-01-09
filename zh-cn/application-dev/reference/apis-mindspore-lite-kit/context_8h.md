# context.h


## 概述

提供了Context相关的接口，可以配置运行时信息，该接口是非线程安全的。

**起始版本：**

9

**相关模块：**

[MindSpore](_mind_spore.md)


## 汇总


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) | MindSpore的上下文信息的指针，该指针会指向Context。 |
| [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) | MindSpore的运行设备信息的指针。 |


### 函数

| 名称 | 描述 |
| -------- | -------- |
| [OH_AI_ContextCreate](_mind_spore.md#oh_ai_contextcreate) () | 创建一个上下文的对象。注意：此接口需跟[OH_AI_ContextDestroy](_mind_spore.md#oh_ai_contextdestroy)配套使用。 |
| [OH_AI_ContextDestroy](_mind_spore.md#oh_ai_contextdestroy) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) \*context) | 释放上下文对象。 |
| [OH_AI_ContextSetThreadNum](_mind_spore.md#oh_ai_contextsetthreadnum) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, int32_t thread_num) | 设置运行时的线程数量。 |
| [OH_AI_ContextGetThreadNum](_mind_spore.md#oh_ai_contextgetthreadnum) (const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context) | 获取线程数量。 |
| [OH_AI_ContextSetThreadAffinityMode](_mind_spore.md#oh_ai_contextsetthreadaffinitymode) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, int mode) | 设置运行时线程绑定CPU核心的策略，按照CPU物理核频率分为大、中、小三种类型的核心，并且仅需绑大核或者绑中核，不需要绑小核。 |
| [OH_AI_ContextGetThreadAffinityMode](_mind_spore.md#oh_ai_contextgetthreadaffinitymode) (const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context) | 获取运行时线程绑定CPU核心的策略。 |
| [OH_AI_ContextSetThreadAffinityCoreList](_mind_spore.md#oh_ai_contextsetthreadaffinitycorelist) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, const int32_t \*core_list, size_t core_num) | 设置运行时线程绑定CPU核心的列表。 |
| [OH_AI_ContextGetThreadAffinityCoreList](_mind_spore.md#oh_ai_contextgetthreadaffinitycorelist) (const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, size_t \*core_num) | 获取CPU绑核列表。 |
| [OH_AI_ContextSetEnableParallel](_mind_spore.md#oh_ai_contextsetenableparallel) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, bool is_parallel) | 设置运行时是否支持并行。此接口特性当前未开启，设置无效。 |
| [OH_AI_ContextGetEnableParallel](_mind_spore.md#oh_ai_contextgetenableparallel) (const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context) | 获取是否支持算子间并行。 |
| [OH_AI_ContextAddDeviceInfo](_mind_spore.md#oh_ai_contextadddeviceinfo) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | 将一个用户定义的运行设备信息附加到推理上下文中。 |
| [OH_AI_DeviceInfoCreate](_mind_spore.md#oh_ai_deviceinfocreate) ([OH_AI_DeviceType](_mind_spore.md#oh_ai_devicetype) device_type) | 创建一个设备信息对象。 |
| [OH_AI_DeviceInfoDestroy](_mind_spore.md#oh_ai_deviceinfodestroy) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) \*device_info) | 释放设备信息实例。注意：设备信息实例被添加到context后，无需调用者手动释放。 |
| [OH_AI_DeviceInfoSetProvider](_mind_spore.md#oh_ai_deviceinfosetprovider) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, const char \*provider) | 设置生产商的名称。 |
| [OH_AI_DeviceInfoGetProvider](_mind_spore.md#oh_ai_deviceinfogetprovider) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | 获取生产商的名称。 |
| [OH_AI_DeviceInfoSetProviderDevice](_mind_spore.md#oh_ai_deviceinfosetproviderdevice) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, const char \*device) | 设置生产商设备的名称。 |
| [OH_AI_DeviceInfoGetProviderDevice](_mind_spore.md#oh_ai_deviceinfogetproviderdevice) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | 获取生产商设备的名称。 |
| [OH_AI_DeviceInfoGetDeviceType](_mind_spore.md#oh_ai_deviceinfogetdevicetype) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | 获取设备的类型。 |
| [OH_AI_DeviceInfoSetEnableFP16](_mind_spore.md#oh_ai_deviceinfosetenablefp16) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, bool is_fp16) | 设置是否开启float16推理模式，仅CPU/GPU设备可用。 |
| [OH_AI_DeviceInfoGetEnableFP16](_mind_spore.md#oh_ai_deviceinfogetenablefp16) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | 获取是否开启float16推理模式, 仅CPU/GPU设备可用。 |
| [OH_AI_DeviceInfoSetFrequency](_mind_spore.md#oh_ai_deviceinfosetfrequency) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, int frequency) | 设置NPU的频率，仅NPU设备可用。 |
| [OH_AI_DeviceInfoGetFrequency](_mind_spore.md#oh_ai_deviceinfogetfrequency) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | 获取NPU的频率类型，仅NPU设备可用。 |
| [OH_AI_GetAllNNRTDeviceDescs](_mind_spore.md#oh_ai_getallnnrtdevicedescs) (size_t \*num) | 获取系统中所有NNRT硬件设备的描述信息。 |
| [OH_AI_GetElementOfNNRTDeviceDescs](_mind_spore.md#oh_ai_getelementofnnrtdevicedescs) (NNRTDeviceDesc \*descs, size_t index) | 获取NNRT设备描述信息数组中的元素指针。 |
| [OH_AI_DestroyAllNNRTDeviceDescs](_mind_spore.md#oh_ai_destroyallnnrtdevicedescs) ([NNRTDeviceDesc](_mind_spore.md#nnrtdevicedesc) \*\*desc) | 销毁从[OH_AI_GetAllNNRTDeviceDescs](_mind_spore.md#oh_ai_getallnnrtdevicedescs)获取的NNRT描写信息实例数组。 |
| [OH_AI_GetDeviceIdFromNNRTDeviceDesc](_mind_spore.md#oh_ai_getdeviceidfromnnrtdevicedesc) (const [NNRTDeviceDesc](_mind_spore.md#nnrtdevicedesc) \*desc) | 从特定的NNRT设备描述信息实例获取NNRT设备ID。注意，此ID只对NNRT有效。 |
| [OH_AI_GetNameFromNNRTDeviceDesc](_mind_spore.md#oh_ai_getnamefromnnrtdevicedesc) (const [NNRTDeviceDesc](_mind_spore.md#nnrtdevicedesc) \*desc) | 从特定的NNRT设备描述信息实例获取NNRT设备名称。 |
| [OH_AI_GetTypeFromNNRTDeviceDesc](_mind_spore.md#oh_ai_gettypefromnnrtdevicedesc) (const [NNRTDeviceDesc](_mind_spore.md#nnrtdevicedesc) \*desc) | 从特定的NNRT设备描述信息实例获取NNRT设备类型。 |
| [OH_AI_CreateNNRTDeviceInfoByName](_mind_spore.md#oh_ai_creatennrtdeviceinfobyname) (const char \*name) | 查找指定名称的NNRT设备，根据找到的第一个设备信息，创建NNRT设备信息。 |
| [OH_AI_CreateNNRTDeviceInfoByType](_mind_spore.md#oh_ai_creatennrtdeviceinfobytype) ([OH_AI_NNRTDeviceType](_mind_spore.md#oh_ai_nnrtdevicetype) type) | 查找指定类型的NNRT设备，根据找到的第一个设备信息，创建NNRT设备信息。 |
| [OH_AI_DeviceInfoSetDeviceId](_mind_spore.md#oh_ai_deviceinfosetdeviceid) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, size_t device_id) | 设置NNRT设备ID，仅NNRT设备可用。 |
| [OH_AI_DeviceInfoGetDeviceId](_mind_spore.md#oh_ai_deviceinfogetdeviceid) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | 获取NNRT设备ID，仅NNRT设备可用。 |
| [OH_AI_DeviceInfoSetPerformanceMode](_mind_spore.md#oh_ai_deviceinfosetperformancemode) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, [OH_AI_PerformanceMode](_mind_spore.md#oh_ai_performancemode) mode) | 设置NNRT性能模式，仅NNRT设备可用。 |
| [OH_AI_DeviceInfoGetPerformanceMode](_mind_spore.md#oh_ai_deviceinfogetperformancemode) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | 获取NNRT性能模式，仅NNRT设备可用。 |
| [OH_AI_DeviceInfoSetPriority](_mind_spore.md#oh_ai_deviceinfosetpriority) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, [OH_AI_Priority](_mind_spore.md#oh_ai_priority) priority) | 设置NNRT任务优先级，仅NNRT设备可用。 |
| [OH_AI_DeviceInfoGetPriority](_mind_spore.md#oh_ai_deviceinfogetpriority) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | 获取NNRT任务优先级，仅NNRT设备可用。 |
| [OH_AI_DeviceInfoAddExtension](_mind_spore.md#oh_ai_deviceinfoaddextension) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, const char \*name, const char \*value, size_t value_size) | 向设备信息中添加键/值对形式的扩展配置。只对NNRT设备信息有效。 |
