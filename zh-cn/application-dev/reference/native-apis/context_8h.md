# context.h


## 概述

提供了Context相关的接口，可以配置运行时信息。

**自从：**

9

**相关模块：**

[MindSpore](_mind_spore.md)


## 汇总


### 类型定义

| 类型定义名称 | 描述 |
| -------- | -------- |
| [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) | Mindspore的上下文信息的指针，该指针会指向Context。 |
| [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) | Mindspore的运行设备信息的指针。 |


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_AI_ContextCreate](_mind_spore.md#oh_ai_contextcreate) () | 创建一个上下文的对象。 |
| [OH_AI_ContextDestroy](_mind_spore.md#oh_ai_contextdestroy) (OH_AI_ContextHandle \*context) | 释放上下文对象。 |
| [OH_AI_ContextSetThreadNum](_mind_spore.md#oh_ai_contextsetthreadnum) (OH_AI_ContextHandle context, int32_t thread_num) | 设置运行时的线程数量。 |
| [OH_AI_ContextGetThreadNum](_mind_spore.md#oh_ai_contextgetthreadnum) (const OH_AI_ContextHandle context) | 获取线程数量。 |
| [OH_AI_ContextSetThreadAffinityMode](_mind_spore.md#oh_ai_contextsetthreadaffinitymode) (OH_AI_ContextHandle context, int mode) | 设置运行时线程绑定CPU核心的策略，按照CPU物理核频率分为大、中、小三种类型的核心，并且仅需绑大核或者绑中核，不需要绑小核。 |
| [OH_AI_ContextGetThreadAffinityMode](_mind_spore.md#oh_ai_contextgetthreadaffinitymode) (const OH_AI_ContextHandle context) | 获取运行时线程绑定CPU核心的策略。 |
| [OH_AI_ContextSetThreadAffinityCoreList](_mind_spore.md#oh_ai_contextsetthreadaffinitycorelist) (OH_AI_ContextHandle context, const int32_t \*core_list, size_t core_num) | 设置运行时线程绑定CPU核心的列表。 |
| [OH_AI_ContextGetThreadAffinityCoreList](_mind_spore.md#oh_ai_contextgetthreadaffinitycorelist) (const OH_AI_ContextHandle context, size_t \*core_num) | 获取CPU绑核列表。 |
| [OH_AI_ContextSetEnableParallel](_mind_spore.md#oh_ai_contextsetenableparallel) (OH_AI_ContextHandle context, bool is_parallel) | 设置运行时是否支持并行。 |
| [OH_AI_ContextGetEnableParallel](_mind_spore.md#oh_ai_contextgetenableparallel) (const OH_AI_ContextHandle context) | 获取是否支持算子间并行。 |
| [OH_AI_ContextAddDeviceInfo](_mind_spore.md#oh_ai_contextadddeviceinfo) (OH_AI_ContextHandle context, OH_AI_DeviceInfoHandle device_info) | 添加运行设备信息。 |
| [OH_AI_DeviceInfoCreate](_mind_spore.md#oh_ai_deviceinfocreate) (OH_AI_DeviceType device_type) | 创建一个设备信息对象。 |
| [OH_AI_DeviceInfoDestroy](_mind_spore.md#oh_ai_deviceinfodestroy) (OH_AI_DeviceInfoHandle \*device_info) | 释放设备信息实例。 |
| [OH_AI_DeviceInfoSetProvider](_mind_spore.md#oh_ai_deviceinfosetprovider) (OH_AI_DeviceInfoHandle device_info, const char \*provider) | 设置供应商的名称。 |
| [OH_AI_DeviceInfoGetProvider](_mind_spore.md#oh_ai_deviceinfogetprovider) (const OH_AI_DeviceInfoHandle device_info) | 获取生产商的名称。 |
| [OH_AI_DeviceInfoSetProviderDevice](_mind_spore.md#oh_ai_deviceinfosetproviderdevice) (OH_AI_DeviceInfoHandle device_info, const char \*device) | 设置生产商设备的名称。 |
| [OH_AI_DeviceInfoGetProviderDevice](_mind_spore.md#oh_ai_deviceinfogetproviderdevice) (const OH_AI_DeviceInfoHandle device_info) | 获取生产商设备的名称。 |
| [OH_AI_DeviceInfoGetDeviceType](_mind_spore.md#oh_ai_deviceinfogetdevicetype) (const OH_AI_DeviceInfoHandle device_info) | 获取设备的类型。 |
| [OH_AI_DeviceInfoSetEnableFP16](_mind_spore.md#oh_ai_deviceinfosetenablefp16) (OH_AI_DeviceInfoHandle device_info, bool is_fp16) | 设置是否开启float16推理模式，仅CPU/GPU设备可用。 |
| [OH_AI_DeviceInfoGetEnableFP16](_mind_spore.md#oh_ai_deviceinfogetenablefp16) (const OH_AI_DeviceInfoHandle device_info) | 获取是否开启float16推理模式, 仅CPU/GPU设备可用。 |
| [OH_AI_DeviceInfoSetFrequency](_mind_spore.md#oh_ai_deviceinfosetfrequency) (OH_AI_DeviceInfoHandle device_info, int frequency) | 设置NPU的频率，仅NPU设备可用。 |
| [OH_AI_DeviceInfoGetFrequency](_mind_spore.md#oh_ai_deviceinfogetfrequency) (const OH_AI_DeviceInfoHandle device_info) | 获取NPU的频率类型，仅NPU设备可用。 |
