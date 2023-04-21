# context.h


## Overview

Provides **Context** APIs for configuring runtime information.

**Since:**
9

**Related Modules:**

[MindSpore](_mind_spore.md)


## Summary


### Types

| Name | Description | 
| -------- | -------- |
| [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) | Defines the pointer to the MindSpore context.  | 
| [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) | Defines the pointer to the MindSpore device information.  | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_AI_ContextCreate](_mind_spore.md#oh_ai_contextcreate) () | Creates a context object.  | 
| [OH_AI_ContextDestroy](_mind_spore.md#oh_ai_contextdestroy) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) \*context) | Destroys a context object.  | 
| [OH_AI_ContextSetThreadNum](_mind_spore.md#oh_ai_contextsetthreadnum) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, int32_t thread_num) | Sets the number of runtime threads.  | 
| [OH_AI_ContextGetThreadNum](_mind_spore.md#oh_ai_contextgetthreadnum) (const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context) | Obtains the number of threads.  | 
| [OH_AI_ContextSetThreadAffinityMode](_mind_spore.md#oh_ai_contextsetthreadaffinitymode) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, int mode) | Sets the affinity mode for binding runtime threads to CPU cores, which are categorized into little cores and big cores depending on the CPU frequency.  | 
| [OH_AI_ContextGetThreadAffinityMode](_mind_spore.md#oh_ai_contextgetthreadaffinitymode) (const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context) | Obtains the affinity mode for binding runtime threads to CPU cores.  | 
| [OH_AI_ContextSetThreadAffinityCoreList](_mind_spore.md#oh_ai_contextsetthreadaffinitycorelist) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, const int32_t \*core_list, size_t core_num) | Sets the list of CPU cores bound to a runtime thread.  | 
| [OH_AI_ContextGetThreadAffinityCoreList](_mind_spore.md#oh_ai_contextgetthreadaffinitycorelist) (const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, size_t \*core_num) | Obtains the list of bound CPU cores.  | 
| [OH_AI_ContextSetEnableParallel](_mind_spore.md#oh_ai_contextsetenableparallel) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, bool is_parallel) | Sets whether to enable parallelism between operators.  | 
| [OH_AI_ContextGetEnableParallel](_mind_spore.md#oh_ai_contextgetenableparallel) (const [OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context) | Checks whether parallelism between operators is supported.  | 
| [OH_AI_ContextAddDeviceInfo](_mind_spore.md#oh_ai_contextadddeviceinfo) ([OH_AI_ContextHandle](_mind_spore.md#oh_ai_contexthandle) context, [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | Adds information about a running device.  | 
| [OH_AI_DeviceInfoCreate](_mind_spore.md#oh_ai_deviceinfocreate) ([OH_AI_DeviceType](_mind_spore.md#oh_ai_devicetype) device_type) | Creates a device information object.  | 
| [OH_AI_DeviceInfoDestroy](_mind_spore.md#oh_ai_deviceinfodestroy) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) \*device_info) | Destroys a device information instance.  | 
| [OH_AI_DeviceInfoSetProvider](_mind_spore.md#oh_ai_deviceinfosetprovider) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, const char \*provider) | Sets the name of a provider.  | 
| [OH_AI_DeviceInfoGetProvider](_mind_spore.md#oh_ai_deviceinfogetprovider) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | Obtains the provider name.  | 
| [OH_AI_DeviceInfoSetProviderDevice](_mind_spore.md#oh_ai_deviceinfosetproviderdevice) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, const char \*device) | Sets the name of a provider device.  | 
| [OH_AI_DeviceInfoGetProviderDevice](_mind_spore.md#oh_ai_deviceinfogetproviderdevice) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | Obtains the name of a provider device.  | 
| [OH_AI_DeviceInfoGetDeviceType](_mind_spore.md#oh_ai_deviceinfogetdevicetype) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | Obtains the type of a provider device.  | 
| [OH_AI_DeviceInfoSetEnableFP16](_mind_spore.md#oh_ai_deviceinfosetenablefp16) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, bool is_fp16) | Sets whether to enable float16 inference. This function is available only for CPU/GPU devices.  | 
| [OH_AI_DeviceInfoGetEnableFP16](_mind_spore.md#oh_ai_deviceinfogetenablefp16) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | Checks whether float16 inference is enabled. This function is available only for CPU/GPU devices.  | 
| [OH_AI_DeviceInfoSetFrequency](_mind_spore.md#oh_ai_deviceinfosetfrequency) ([OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info, int frequency) | Sets the NPU frequency type. This function is available only for NPU devices.  | 
| [OH_AI_DeviceInfoGetFrequency](_mind_spore.md#oh_ai_deviceinfogetfrequency) (const [OH_AI_DeviceInfoHandle](_mind_spore.md#oh_ai_deviceinfohandle) device_info) | Obtains the NPU frequency type. This function is available only for NPU devices.  | 
