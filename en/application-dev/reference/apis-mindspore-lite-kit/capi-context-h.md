# context.h

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--Designer: @zhuguodong8; @jjfeing-->
<!--Tester: @principal87-->
<!--Adviser: @ge-yafang-->

## Overview

Provides context-related APIs for configuring runtime information. These APIs are non-thread-safe.

**File to include**: <mindspore/context.h>

**Library**: libmindspore_lite_ndk.so

**System capability**: SystemCapability.Ai.MindSpore

**Since**: 9

**Related module**: [MindSpore](capi-mindspore.md)

## Summary

### Structs

| Name                                                          | typedef Keyword| Description                               |
|--------------------------------------------------------------|------------|-----------------------------------|
| [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) | void*      | Defines the pointer to the MindSpore Lite context.|
| [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md)   | void*          | Defines the pointer to the MindSpore Lite device information.                                 |

### Functions

| Name| Description|
| -- | -- |
| [OH_AI_API OH_AI_ContextHandle OH_AI_ContextCreate()](#oh_ai_contextcreate) | Creates a context object. This API must be used together with **OH_AI_ContextDestroy**.|
| [OH_AI_API void OH_AI_ContextDestroy(OH_AI_ContextHandle *context)](#oh_ai_contextdestroy) | Destroys a context object.|
| [OH_AI_API void OH_AI_ContextSetThreadNum(OH_AI_ContextHandle context, int32_t thread_num)](#oh_ai_contextsetthreadnum) | Sets the number of runtime threads.|
| [OH_AI_API int32_t OH_AI_ContextGetThreadNum(const OH_AI_ContextHandle context)](#oh_ai_contextgetthreadnum) | Obtains the number of threads.|
| [OH_AI_API void OH_AI_ContextSetThreadAffinityMode(OH_AI_ContextHandle context, int mode)](#oh_ai_contextsetthreadaffinitymode) | Sets the affinity mode for binding runtime threads to CPU cores, which are classified into large, medium, and small cores based on the CPU frequency. You only need to bind the large or medium cores, but not small cores.|
| [OH_AI_API int OH_AI_ContextGetThreadAffinityMode(const OH_AI_ContextHandle context)](#oh_ai_contextgetthreadaffinitymode) | Obtains the affinity mode for binding runtime threads to CPU cores.|
| [OH_AI_API void OH_AI_ContextSetThreadAffinityCoreList(OH_AI_ContextHandle context, const int32_t *core_list,size_t core_num)](#oh_ai_contextsetthreadaffinitycorelist) | Sets the list of CPU cores bound to a runtime thread.<br> For example, if **core_list** is set to **[2,6,8]**, threads run on the 2nd, 6th, and 8th CPU cores.<br> If [OH_AI_ContextSetThreadAffinityMode](capi-context-h.md#oh_ai_contextsetthreadaffinitymode) and [OH_AI_ContextSetThreadAffinityCoreList](capi-context-h.md#oh_ai_contextsetthreadaffinitycorelist) are called for the same context object,<br> the **core_list** parameter of [OH_AI_ContextSetThreadAffinityCoreList](capi-context-h.md#oh_ai_contextsetthreadaffinitycorelist) takes effect, but the **mode** parameter of [OH_AI_ContextSetThreadAffinityMode](capi-context-h.md#oh_ai_contextsetthreadaffinitymode) does not.|
| [OH_AI_API const int32_t *OH_AI_ContextGetThreadAffinityCoreList(const OH_AI_ContextHandle context, size_t *core_num)](#oh_ai_contextgetthreadaffinitycorelist) | Obtains the list of bound CPU cores.|
| [OH_AI_API void OH_AI_ContextSetEnableParallel(OH_AI_ContextHandle context, bool is_parallel)](#oh_ai_contextsetenableparallel) | Sets whether to enable parallelism between operators. The setting is ineffective because the feature of this API is not yet available.|
| [OH_AI_API bool OH_AI_ContextGetEnableParallel(const OH_AI_ContextHandle context)](#oh_ai_contextgetenableparallel) | Checks whether parallelism between operators is supported.|
| [OH_AI_API void OH_AI_ContextAddDeviceInfo(OH_AI_ContextHandle context, OH_AI_DeviceInfoHandle device_info)](#oh_ai_contextadddeviceinfo) | Attaches the custom device information to the inference context.|
| [OH_AI_API OH_AI_DeviceInfoHandle OH_AI_DeviceInfoCreate(OH_AI_DeviceType device_type)](#oh_ai_deviceinfocreate) | Creates a device information object.|
| [OH_AI_API void OH_AI_DeviceInfoDestroy(OH_AI_DeviceInfoHandle *device_info)](#oh_ai_deviceinfodestroy) | Destroys a device information object. Note: After the device information instance is added to the context, the caller does not need to destroy it manually.|
| [OH_AI_API void OH_AI_DeviceInfoSetProvider(OH_AI_DeviceInfoHandle device_info, const char *provider)](#oh_ai_deviceinfosetprovider) | Sets the name of the provider.|
| [OH_AI_API const char *OH_AI_DeviceInfoGetProvider(const OH_AI_DeviceInfoHandle device_info)](#oh_ai_deviceinfogetprovider) | Obtains the provider name.|
| [OH_AI_API void OH_AI_DeviceInfoSetProviderDevice(OH_AI_DeviceInfoHandle device_info, const char *device)](#oh_ai_deviceinfosetproviderdevice) | Sets the name of a provider device.|
| [OH_AI_API const char *OH_AI_DeviceInfoGetProviderDevice(const OH_AI_DeviceInfoHandle device_info)](#oh_ai_deviceinfogetproviderdevice) | Obtains the name of a provider device.|
| [OH_AI_API OH_AI_DeviceType OH_AI_DeviceInfoGetDeviceType(const OH_AI_DeviceInfoHandle device_info)](#oh_ai_deviceinfogetdevicetype) | Obtains the device type.|
| [OH_AI_API void OH_AI_DeviceInfoSetEnableFP16(OH_AI_DeviceInfoHandle device_info, bool is_fp16)](#oh_ai_deviceinfosetenablefp16) | Sets whether to enable float16 inference. This function is available only for CPU and GPU devices.|
| [OH_AI_API bool OH_AI_DeviceInfoGetEnableFP16(const OH_AI_DeviceInfoHandle device_info)](#oh_ai_deviceinfogetenablefp16) | Checks whether float16 inference is enabled. This function is available only for CPU and GPU devices.|
| [OH_AI_API void OH_AI_DeviceInfoSetFrequency(OH_AI_DeviceInfoHandle device_info, int frequency)](#oh_ai_deviceinfosetfrequency) | Sets the NPU frequency type. This function is available only for NPU devices.|
| [OH_AI_API int OH_AI_DeviceInfoGetFrequency(const OH_AI_DeviceInfoHandle device_info)](#oh_ai_deviceinfogetfrequency) | Obtains the NPU frequency type. This function is available only for NPU devices.|
| [OH_AI_API NNRTDeviceDesc *OH_AI_GetAllNNRTDeviceDescs(size_t *num)](#oh_ai_getallnnrtdevicedescs) | Obtains the descriptions of all NNRt devices in the system.|
| [OH_AI_API NNRTDeviceDesc *OH_AI_GetElementOfNNRTDeviceDescs(NNRTDeviceDesc *descs, size_t index)](#oh_ai_getelementofnnrtdevicedescs) | Obtains the pointer to an element in the NNRt device description array.|
| [OH_AI_API void OH_AI_DestroyAllNNRTDeviceDescs(NNRTDeviceDesc **desc)](#oh_ai_destroyallnnrtdevicedescs) | Destroys the NNRt device description array obtained by [OH_AI_GetAllNNRTDeviceDescs](capi-context-h.md#oh_ai_getallnnrtdevicedescs).|
| [OH_AI_API size_t OH_AI_GetDeviceIdFromNNRTDeviceDesc(const NNRTDeviceDesc *desc)](#oh_ai_getdeviceidfromnnrtdevicedesc) | Obtains the NNRt device ID from the specified NNRt device description. Note that this ID is valid only for NNRt devices.|
| [OH_AI_API const char *OH_AI_GetNameFromNNRTDeviceDesc(const NNRTDeviceDesc *desc)](#oh_ai_getnamefromnnrtdevicedesc) | Obtains the NNRt device name from the specified NNRt device description.|
| [OH_AI_API OH_AI_NNRTDeviceType OH_AI_GetTypeFromNNRTDeviceDesc(const NNRTDeviceDesc *desc)](#oh_ai_gettypefromnnrtdevicedesc) | Obtains the NNRt device type from the specified NNRt device description.|
| [OH_AI_API OH_AI_DeviceInfoHandle OH_AI_CreateNNRTDeviceInfoByName(const char *name)](#oh_ai_creatennrtdeviceinfobyname) | Searches for the NNRt device with the specified name and creates the NNRt device information based on the information about the first found NNRt device.|
| [OH_AI_API OH_AI_DeviceInfoHandle OH_AI_CreateNNRTDeviceInfoByType(OH_AI_NNRTDeviceType type)](#oh_ai_creatennrtdeviceinfobytype) | Searches for the NNRt device with the specified type and creates the NNRt device information based on the information about the first found NNRt device.|
| [OH_AI_API void OH_AI_DeviceInfoSetDeviceId(OH_AI_DeviceInfoHandle device_info, size_t device_id)](#oh_ai_deviceinfosetdeviceid) | Sets the NNRt device ID. This function is available only for NNRt devices.|
| [OH_AI_API size_t OH_AI_DeviceInfoGetDeviceId(const OH_AI_DeviceInfoHandle device_info)](#oh_ai_deviceinfogetdeviceid) | Obtains the NNRt device ID. This function is available only for NNRt devices.|
| [OH_AI_API void OH_AI_DeviceInfoSetPerformanceMode(OH_AI_DeviceInfoHandle device_info, OH_AI_PerformanceMode mode)](#oh_ai_deviceinfosetperformancemode) | Sets the NNRt performance mode. This function is available only for NNRt devices.|
| [OH_AI_API OH_AI_PerformanceMode OH_AI_DeviceInfoGetPerformanceMode(const OH_AI_DeviceInfoHandle device_info)](#oh_ai_deviceinfogetperformancemode) | Obtains the NNRt performance mode. This function is available only for NNRt devices.|
| [OH_AI_API void OH_AI_DeviceInfoSetPriority(OH_AI_DeviceInfoHandle device_info, OH_AI_Priority priority)](#oh_ai_deviceinfosetpriority) | Sets the priority of an NNRt task. This function is available only for NNRt devices.|
| [OH_AI_API OH_AI_Priority OH_AI_DeviceInfoGetPriority(const OH_AI_DeviceInfoHandle device_info)](#oh_ai_deviceinfogetpriority) | Obtains the priority of an NNRt task. This function is available only for NNRt devices.|
| [OH_AI_API OH_AI_Status OH_AI_DeviceInfoAddExtension(OH_AI_DeviceInfoHandle device_info, const char *name,const char *value, size_t value_size)](#oh_ai_deviceinfoaddextension) | Adds extended configuration in the form of key/value pairs to the device information. This function is available only for NNRt devices.<br>Currently, only the following 11 keys are supported: {"CachePath": "YourCachePath"}, {"CacheVersion": "YourCacheVersion"},<br> {"QuantBuffer": "YourQuantBuffer"}, {"ModelName": "YourModelName"},<br> {"isProfiling": "YourProfilingSwitch"}, {"opLayout": "YourOpLayout"},<br> {"InputDims": "YourInputDims"}, {"DynamicDims": "YourDynamicDims"}<br> {"QuantConfigData": "YourQuantConfigData"}, {"BandMode": "YourBandMode"}, and<br> and {"NPU_FM_SHARED": "YourNPU_FM_SHARED"}. You can configure the value of each key based on the actual requirement.|

## Function Description

### OH_AI_ContextCreate()

```
OH_AI_API OH_AI_ContextHandle OH_AI_ContextCreate()
```

**Description**

Creates a context object. This API must be used together with **OH_AI_ContextDestroy**.

**Since**: 9

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) | [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) that points to the context.|

### OH_AI_ContextDestroy()

```
OH_AI_API void OH_AI_ContextDestroy(OH_AI_ContextHandle *context)
```

**Description**

Destroys a context object.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) *context | Level-2 pointer to [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md). After the context is destroyed, the context is set to a null pointer.|

### OH_AI_ContextSetThreadNum()

```
OH_AI_API void OH_AI_ContextSetThreadNum(OH_AI_ContextHandle context, int32_t thread_num)
```

**Description**

Sets the number of runtime threads.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) context | [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) that points to the context instance.|
| int32_t thread_num | Number of runtime threads. The length is subject to system restrictions.|

### OH_AI_ContextGetThreadNum()

```
OH_AI_API int32_t OH_AI_ContextGetThreadNum(const OH_AI_ContextHandle context)
```

**Description**

Obtains the number of threads.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) context | [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) that points to the context instance.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API int32_t | Number of threads.|

### OH_AI_ContextSetThreadAffinityMode()

```
OH_AI_API void OH_AI_ContextSetThreadAffinityMode(OH_AI_ContextHandle context, int mode)
```

**Description**

Sets the affinity mode for binding runtime threads to CPU cores, which are classified into large, medium, and small cores based on the CPU frequency. You only need to bind the large or medium cores, but not small cores.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) context | [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) that points to the context instance.|
| int mode | Affinity mode. **0**: no affinities; **1**: big cores first; **2**: medium cores first|

### OH_AI_ContextGetThreadAffinityMode()

```
OH_AI_API int OH_AI_ContextGetThreadAffinityMode(const OH_AI_ContextHandle context)
```

**Description**

Obtains the affinity mode for binding runtime threads to CPU cores.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) context | [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) that points to the context instance.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API int | Affinity mode. **0**: no affinities; **1**: big cores first; **2**: medium cores first|

### OH_AI_ContextSetThreadAffinityCoreList()

```
OH_AI_API void OH_AI_ContextSetThreadAffinityCoreList(OH_AI_ContextHandle context, const int32_t *core_list,size_t core_num)
```

**Description**

Sets the list of CPU cores bound to a runtime thread.<br> For example, if **core_list** is set to **[2,6,8]**, threads run on the 2nd, 6th, and 8th CPU cores.<br> If [OH_AI_ContextSetThreadAffinityMode](capi-context-h.md#oh_ai_contextsetthreadaffinitymode) and [OH_AI_ContextSetThreadAffinityCoreList](capi-context-h.md#oh_ai_contextsetthreadaffinitycorelist) are called for the same context object,<br> the **core_list** parameter of [OH_AI_ContextSetThreadAffinityCoreList](capi-context-h.md#oh_ai_contextsetthreadaffinitycorelist) takes effect, but the **mode** parameter of [OH_AI_ContextSetThreadAffinityMode](capi-context-h.md#oh_ai_contextsetthreadaffinitymode) does not.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) context | [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) that points to the context instance.|
| const int32_t *core_list | List of bound CPU cores.|
| size_t core_num | Number of cores, which indicates the length of **core_list**.|

### OH_AI_ContextGetThreadAffinityCoreList()

```
OH_AI_API const int32_t *OH_AI_ContextGetThreadAffinityCoreList(const OH_AI_ContextHandle context, size_t *core_num)
```

**Description**

Obtains the list of bound CPU cores.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) context | [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) that points to the context instance.|
| size_t *core_num | Number of CPU cores.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API const int32_t * | List of bound CPU cores. This list is managed by [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md). The caller does not need to destroy it manually.|

### OH_AI_ContextSetEnableParallel()

```
OH_AI_API void OH_AI_ContextSetEnableParallel(OH_AI_ContextHandle context, bool is_parallel)
```

**Description**

Sets whether to enable parallelism between operators. The setting is ineffective because the feature of this API is not yet available.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) context | [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) that points to the context instance.|
| bool is_parallel | Whether parallelism between operators is supported. The value **true** indicates that parallelism between operators is supported, and the value **false** indicates the opposite.|

### OH_AI_ContextGetEnableParallel()

```
OH_AI_API bool OH_AI_ContextGetEnableParallel(const OH_AI_ContextHandle context)
```

**Description**

Checks whether parallelism between operators is supported.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) context | [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) that points to the context instance.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API bool | Whether parallelism between operators is supported. The value **true** indicates that parallelism between operators is supported, and the value **false** indicates the opposite.|

### OH_AI_ContextAddDeviceInfo()

```
OH_AI_API void OH_AI_ContextAddDeviceInfo(OH_AI_ContextHandle context, OH_AI_DeviceInfoHandle device_info)
```

**Description**

Attaches the custom device information to the inference context.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) context | [OH_AI_ContextHandle](capi-mindspore-oh-ai-contexthandle.md) that points to the context instance.|
| [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|

### OH_AI_DeviceInfoCreate()

```
OH_AI_API OH_AI_DeviceInfoHandle OH_AI_DeviceInfoCreate(OH_AI_DeviceType device_type)
```

**Description**

Creates a device information object.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_DeviceType](capi-types-h.md#oh_ai_devicetype) device_type | Device type, which is specified by [OH_AI_DeviceType](capi-types-h.md#oh_ai_devicetype).|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|

### OH_AI_DeviceInfoDestroy()

```
OH_AI_API void OH_AI_DeviceInfoDestroy(OH_AI_DeviceInfoHandle *device_info)
```

**Description**

Destroys a device information object. Note: After the device information instance is added to the context, the caller does not need to destroy it manually.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) *device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|

### OH_AI_DeviceInfoSetProvider()

```
OH_AI_API void OH_AI_DeviceInfoSetProvider(OH_AI_DeviceInfoHandle device_info, const char *provider)
```

**Description**

Sets the name of the provider.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|
| const char *provider | Provider name. The string length is subject to system restrictions.|

### OH_AI_DeviceInfoGetProvider()

```
OH_AI_API const char *OH_AI_DeviceInfoGetProvider(const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Obtains the provider name.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API const char * | Provider name.|

### OH_AI_DeviceInfoSetProviderDevice()

```
OH_AI_API void OH_AI_DeviceInfoSetProviderDevice(OH_AI_DeviceInfoHandle device_info, const char *device)
```

**Description**

Sets the name of a provider device.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|
| const char *device | Name of the provider device, for example, CPU. The string length is subject to system restrictions.|

### OH_AI_DeviceInfoGetProviderDevice()

```
OH_AI_API const char *OH_AI_DeviceInfoGetProviderDevice(const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Obtains the name of a provider device.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API const char * | Name of the provider device.|

### OH_AI_DeviceInfoGetDeviceType()

```
OH_AI_API OH_AI_DeviceType OH_AI_DeviceInfoGetDeviceType(const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Obtains the device type.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|

**Returns**

| Type                                                            | Description|
|----------------------------------------------------------------| -- |
| OH_AI_API [OH_AI_DeviceType](capi-types-h.md#oh_ai_devicetype) | Type of the provider device.|

### OH_AI_DeviceInfoSetEnableFP16()

```
OH_AI_API void OH_AI_DeviceInfoSetEnableFP16(OH_AI_DeviceInfoHandle device_info, bool is_fp16)
```

**Description**

Sets whether to enable float16 inference. This function is available only for CPU and GPU devices.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|
| bool is_fp16 | Whether to enable the float16 inference mode. The value **true** means to enable the float16 inference mode, and the value **false** means the opposite.|

### OH_AI_DeviceInfoGetEnableFP16()

```
OH_AI_API bool OH_AI_DeviceInfoGetEnableFP16(const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Checks whether float16 inference is enabled. This function is available only for CPU and GPU devices.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API bool | Whether to enable the float16 inference mode. The value **true** means to enable the float16 inference mode, and the value **false** means the opposite.|

### OH_AI_DeviceInfoSetFrequency()

```
OH_AI_API void OH_AI_DeviceInfoSetFrequency(OH_AI_DeviceInfoHandle device_info, int frequency)
```

**Description**

Sets the NPU frequency type. This function is available only for NPU devices.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|
| int frequency | NPU frequency type. The value ranges from **0** to **4**. The default value is **3**. Meanings of each value: **0**: auto system adjustment; **1**: low power consumption; **2**: balanced; **3**: high performance; **4**: ultra-high performance.|

### OH_AI_DeviceInfoGetFrequency()

```
OH_AI_API int OH_AI_DeviceInfoGetFrequency(const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Obtains the NPU frequency type. This function is available only for NPU devices.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API int | NPU frequency type. Meanings of each value: **0**: auto system adjustment; **1**: low power consumption; **2**: balanced; **3**: high performance; **4**: ultra-high performance.|

### OH_AI_GetAllNNRTDeviceDescs()

```
OH_AI_API NNRTDeviceDesc *OH_AI_GetAllNNRTDeviceDescs(size_t *num)
```

**Description**

Obtains the descriptions of all NNRt devices in the system.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| size_t *num | Number of NNRt devices.|

**Returns**

| Type                            | Description|
|--------------------------------| -- |
| OH_AI_API [NNRTDeviceDesc](capi-mindspore-nnrtdevicedesc.md) * | Pointer to the NNRt device description array. If the operation fails, **NULL** is returned.|

### OH_AI_GetElementOfNNRTDeviceDescs()

```
OH_AI_API NNRTDeviceDesc *OH_AI_GetElementOfNNRTDeviceDescs(NNRTDeviceDesc *descs, size_t index)
```

**Description**

Obtains the pointer to an element in the NNRt device description array.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [NNRTDeviceDesc](capi-mindspore-nnrtdevicedesc.md) *descs | NNRt device description array.|
| size_t index | Index of an array element.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [NNRTDeviceDesc](capi-mindspore-nnrtdevicedesc.md) * | Pointer to the NNRt device description. |

### OH_AI_DestroyAllNNRTDeviceDescs()

```
OH_AI_API void OH_AI_DestroyAllNNRTDeviceDescs(NNRTDeviceDesc **desc)
```

**Description**

Destroys the NNRt device description array obtained by [OH_AI_GetAllNNRTDeviceDescs](capi-context-h.md#oh_ai_getallnnrtdevicedescs).

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [NNRTDeviceDesc](capi-mindspore-nnrtdevicedesc.md) **desc | Double pointer to the NNRt device description array. After the operation is complete, the content pointed to by **desc** is set to **NULL**.|

### OH_AI_GetDeviceIdFromNNRTDeviceDesc()

```
OH_AI_API size_t OH_AI_GetDeviceIdFromNNRTDeviceDesc(const NNRTDeviceDesc *desc)
```

**Description**

Obtains the NNRt device ID from the specified NNRt device description. Note that this ID is valid only for NNRt devices.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NNRTDeviceDesc](capi-mindspore-nnrtdevicedesc.md) *desc | Pointer to the NNRt device description.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API size_t | NNRt device ID.|

### OH_AI_GetNameFromNNRTDeviceDesc()

```
OH_AI_API const char *OH_AI_GetNameFromNNRTDeviceDesc(const NNRTDeviceDesc *desc)
```

**Description**

Obtains the NNRt device name from the specified NNRt device description.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NNRTDeviceDesc](capi-mindspore-nnrtdevicedesc.md) *desc | Pointer to the NNRt device description.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API const char * | NNRt device name. The value is a pointer that points to a constant string, which is held by **desc**. The caller does not need to destroy it separately.|

### OH_AI_GetTypeFromNNRTDeviceDesc()

```
OH_AI_API OH_AI_NNRTDeviceType OH_AI_GetTypeFromNNRTDeviceDesc(const NNRTDeviceDesc *desc)
```

**Description**

Obtains the NNRt device type from the specified NNRt device description.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [NNRTDeviceDesc](capi-mindspore-nnrtdevicedesc.md) *desc | Pointer to the NNRt device description.|

**Returns**

| Type                                                                    | Description|
|------------------------------------------------------------------------| -- |
| OH_AI_API [OH_AI_NNRTDeviceType](capi-types-h.md#oh_ai_nnrtdevicetype) | NNRt device type, which is specified by [OH_AI_NNRTDeviceType](capi-types-h.md#oh_ai_nnrtdevicetype).|

### OH_AI_CreateNNRTDeviceInfoByName()

```
OH_AI_API OH_AI_DeviceInfoHandle OH_AI_CreateNNRTDeviceInfoByName(const char *name)
```

**Description**

Searches for the NNRt device with the specified name and creates the NNRt device information based on the information about the first found NNRt device.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const char *name | Name of the target NNRt device. The string length is subject to system restrictions.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|

### OH_AI_CreateNNRTDeviceInfoByType()

```
OH_AI_API OH_AI_DeviceInfoHandle OH_AI_CreateNNRTDeviceInfoByType(OH_AI_NNRTDeviceType type)
```

**Description**

Searches for the NNRt device with the specified type and creates the NNRt device information based on the information about the first found NNRt device.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_NNRTDeviceType](capi-types-h.md#oh_ai_nnrtdevicetype) type | NNRt device type, which is specified by [OH_AI_NNRTDeviceType](capi-types-h.md#oh_ai_nnrtdevicetype).|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|

### OH_AI_DeviceInfoSetDeviceId()

```
OH_AI_API void OH_AI_DeviceInfoSetDeviceId(OH_AI_DeviceInfoHandle device_info, size_t device_id)
```

**Description**

Sets the NNRt device ID. This function is available only for NNRt devices.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|
| size_t device_id | NNRt device ID.|

### OH_AI_DeviceInfoGetDeviceId()

```
OH_AI_API size_t OH_AI_DeviceInfoGetDeviceId(const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Obtains the NNRt device ID. This function is available only for NNRt devices.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API size_t | NNRt device ID.|

### OH_AI_DeviceInfoSetPerformanceMode()

```
OH_AI_API void OH_AI_DeviceInfoSetPerformanceMode(OH_AI_DeviceInfoHandle device_info, OH_AI_PerformanceMode mode)
```

**Description**

Sets the NNRt performance mode. This function is available only for NNRt devices.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|
| [OH_AI_PerformanceMode](capi-types-h.md#oh_ai_performancemode) mode | NNRt performance mode, which is specified by [OH_AI_PerformanceMode](capi-types-h.md#oh_ai_performancemode).|

### OH_AI_DeviceInfoGetPerformanceMode()

```
OH_AI_API OH_AI_PerformanceMode OH_AI_DeviceInfoGetPerformanceMode(const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Obtains the NNRt performance mode. This function is available only for NNRt devices.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|

**Returns**

| Type                                                                      | Description|
|--------------------------------------------------------------------------| -- |
| OH_AI_API [OH_AI_PerformanceMode](capi-types-h.md#oh_ai_performancemode) | NNRt performance mode, which is specified by [OH_AI_PerformanceMode](capi-types-h.md#oh_ai_performancemode).|

### OH_AI_DeviceInfoSetPriority()

```
OH_AI_API void OH_AI_DeviceInfoSetPriority(OH_AI_DeviceInfoHandle device_info, OH_AI_Priority priority)
```

**Description**

Sets the priority of an NNRt task. This function is available only for NNRt devices.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|
| [OH_AI_Priority](capi-types-h.md#oh_ai_priority) priority | NNRt task priority, which is specified by [OH_AI_Priority](capi-types-h.md#oh_ai_priority).|

### OH_AI_DeviceInfoGetPriority()

```
OH_AI_API OH_AI_Priority OH_AI_DeviceInfoGetPriority(const OH_AI_DeviceInfoHandle device_info)
```

**Description**

Obtains the priority of an NNRt task. This function is available only for NNRt devices.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AI_API [OH_AI_Priority](capi-types-h.md#oh_ai_priority) | NNRt task priority, which is specified by [OH_AI_Priority](capi-types-h.md#oh_ai_priority).|

### OH_AI_DeviceInfoAddExtension()

```
OH_AI_API OH_AI_Status OH_AI_DeviceInfoAddExtension(OH_AI_DeviceInfoHandle device_info, const char *name,const char *value, size_t value_size)
```

**Description**

Adds extended configuration in the form of key/value pairs to the device information. This function is available only for NNRt devices.<br>Currently, only the following 11 keys are supported: {"CachePath": "YourCachePath"}, {"CacheVersion": "YourCacheVersion"},<br> {"QuantBuffer": "YourQuantBuffer"}, {"ModelName": "YourModelName"},<br> {"isProfiling": "YourProfilingSwitch"}, {"opLayout": "YourOpLayout"},<br> {"InputDims": "YourInputDims"}, {"DynamicDims": "YourDynamicDims"}<br> {"QuantConfigData": "YourQuantConfigData"}, {"BandMode": "YourBandMode"}, and<br> and {"NPU_FM_SHARED": "YourNPU_FM_SHARED"}. You can configure the value of each key based on the actual requirement.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) device_info | [OH_AI_DeviceInfoHandle](capi-mindspore-oh-ai-DeviceInfoHandle.md) that points to the device information instance.|
| const char *name | Key in an extended key/value pair. The value is a C string. The value contains up to 128 characters.|
| const char *value |  Start address of the value in an extended key/value pair. The string length is subject to system restrictions.|
| size_t value_size | Length of the value in an extended key/value pair.|

**Returns**

| Type                                                     | Description|
|---------------------------------------------------------| -- |
| OH_AI_API [OH_AI_Status](capi-status-h.md#oh_ai_status) | Status code enumerated by [OH_AI_Status](capi-status-h.md#oh_ai_status). The value **OH_AI_STATUS_SUCCESS** indicates that the operation is successful. If the operation fails, an error code is returned.|
