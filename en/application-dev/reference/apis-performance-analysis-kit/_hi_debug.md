# HiDebug


## Overview

Provides APIs for debugging.

You can use the APIs to obtain CPU usage, memory information, heap information, and capture traces. 

**Since**: 12


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [hidebug.h](hidebug_8h.md) | Defines the APIs for debugging.|
| [hidebug_type.h](hidebug__type_8h.md) | Defines the structs of the HiDebug module.|


### Structs

| Name| Description|
| -------- | -------- |
| struct  [HiDebug_ThreadCpuUsage](_hi_debug___thread_cpu_usage.md) | Defines the CPU usage of all threads of an application.|
| struct  [HiDebug_SystemMemInfo](_hi_debug___system_mem_info.md) | Defines the system memory information.|
| struct  [HiDebug_NativeMemInfo](_hi_debug___native_mem_info.md) | Defines the local memory information of an application process.|
| struct  [HiDebug_MemoryLimit](_hi_debug___memory_limit.md) | Defines the memory limit of an application process.|


### Macros

| Name| Description|
| -------- | -------- |
| [HIDEBUG_TRACE_TAG_FFRT](#hidebug_trace_tag_ffrt)   (1ULL &lt;&lt; 13) | Indicates the FFRT task.|
| [HIDEBUG_TRACE_TAG_COMMON_LIBRARY](#hidebug_trace_tag_common_library)   (1ULL &lt;&lt; 16) | Indicates the common library subsystem.|
| [HIDEBUG_TRACE_TAG_HDF](#hidebug_trace_tag_hdf)   (1ULL &lt;&lt; 18) | Indicates the HDF subsystem.|
| [HIDEBUG_TRACE_TAG_NET](#hidebug_trace_tag_net)   (1ULL &lt;&lt; 23) | Indicates the network.|
| [HIDEBUG_TRACE_TAG_NWEB](#hidebug_trace_tag_nweb)   (1ULL &lt;&lt; 24) | Indicates the NWeb.|
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_AUDIO](#hidebug_trace_tag_distributed_audio)   (1ULL &lt;&lt; 27) | Indicates the distributed audio.|
| [HIDEBUG_TRACE_TAG_FILE_MANAGEMENT](#hidebug_trace_tag_file_management)   (1ULL &lt;&lt; 29) | Indicates the file management.|
| [HIDEBUG_TRACE_TAG_OHOS](#hidebug_trace_tag_ohos)   (1ULL &lt;&lt; 30) | Indicates the OpenHarmony OS.|
| [HIDEBUG_TRACE_TAG_ABILITY_MANAGER](#hidebug_trace_tag_ability_manager)   (1ULL &lt;&lt; 31) | Indicates the ability manager.|
| [HIDEBUG_TRACE_TAG_CAMERA](#hidebug_trace_tag_camera)   (1ULL &lt;&lt; 32) | Indicates the camera module.|
| [HIDEBUG_TRACE_TAG_MEDIA](#hidebug_trace_tag_media)   (1ULL &lt;&lt; 33) | Indicates the media module.|
| [HIDEBUG_TRACE_TAG_IMAGE](#hidebug_trace_tag_image)   (1ULL &lt;&lt; 34) | Indicates the image module.|
| [HIDEBUG_TRACE_TAG_AUDIO](#hidebug_trace_tag_audio)   (1ULL &lt;&lt; 35) | Indicates the audio module.|
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_DATA](#hidebug_trace_tag_distributed_data)   (1ULL &lt;&lt; 36) | Indicates the distributed data management.|
| [HIDEBUG_TRACE_TAG_GRAPHICS](#hidebug_trace_tag_graphics)   (1ULL &lt;&lt; 38) | Indicates the graphics module.|
| [HIDEBUG_TRACE_TAG_ARKUI](#hidebug_trace_tag_arkui)   (1ULL &lt;&lt; 39) | Indicates the ArkUI development framework.|
| [HIDEBUG_TRACE_TAG_NOTIFICATION](#hidebug_trace_tag_notification)   (1ULL &lt;&lt; 40) | Indicates the notification module.|
| [HIDEBUG_TRACE_TAG_MISC](#hidebug_trace_tag_misc)   (1ULL &lt;&lt; 41) | Indicates the MISC module.|
| [HIDEBUG_TRACE_TAG_MULTIMODAL_INPUT](#hidebug_trace_tag_multimodal_input)   (1ULL &lt;&lt; 42) | Indicates the multimodal input module.|
| [HIDEBUG_TRACE_TAG_RPC](#hidebug_trace_tag_rpc)   (1ULL &lt;&lt; 46) | Indicates the RPC.|
| [HIDEBUG_TRACE_TAG_ARK](#hidebug_trace_tag_ark)   (1ULL &lt;&lt; 47) | Indicates the JSVM.|
| [HIDEBUG_TRACE_TAG_WINDOW_MANAGER](#hidebug_trace_tag_window_manager)   (1ULL &lt;&lt; 48) | Indicates the window manager.|
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_SCREEN](#hidebug_trace_tag_distributed_screen)   (1ULL &lt;&lt; 50) | Indicates the distributed screen.|
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_CAMERA](#hidebug_trace_tag_distributed_camera)   (1ULL &lt;&lt; 51) | Indicates the distributed camera.|
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_FRAMEWORK](#hidebug_trace_tag_distributed_hardware_framework)   (1ULL &lt;&lt; 52) | Indicates the distributed hardware framework.|
| [HIDEBUG_TRACE_TAG_GLOBAL_RESOURCE_MANAGER](#hidebug_trace_tag_global_resource_manager)   (1ULL &lt;&lt; 53) | Indicates the global resource manager.|
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_DEVICE_MANAGER](#hidebug_trace_tag_distributed_hardware_device_manager)   (1ULL &lt;&lt; 54) | Indicates the distributed hardware device manager.|
| [HIDEBUG_TRACE_TAG_SAMGR](#hidebug_trace_tag_samgr)   (1ULL &lt;&lt; 55) | Indicates the service ability manager (SAMGR).|
| [HIDEBUG_TRACE_TAG_POWER_MANAGER](#hidebug_trace_tag_power_manager)   (1ULL &lt;&lt; 56) | Indicates the power manager.|
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_SCHEDULER](#hidebug_trace_tag_distributed_scheduler)   (1ULL &lt;&lt; 57) | Indicates the distributed scheduler.|
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_INPUT](#hidebug_trace_tag_distributed_input)   (1ULL &lt;&lt; 59) | Indicates the distributed input.|
| [HIDEBUG_TRACE_TAG_BLUETOOTH](#hidebug_trace_tag_bluetooth)   (1ULL &lt;&lt; 60) | Indicates the Bluetooth.|


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [HiDebug_ErrorCode](#hidebug_errorcode-1) [HiDebug_ErrorCode](#hidebug_errorcode) | Defines an enum for error codes.|
| typedef struct [HiDebug_ThreadCpuUsage](_hi_debug___thread_cpu_usage.md) [HiDebug_ThreadCpuUsage](#hidebug_threadcpuusage) | Defines a struct for the CPU usage of all threads of an application.|
| typedef [HiDebug_ThreadCpuUsage](_hi_debug___thread_cpu_usage.md) \* [HiDebug_ThreadCpuUsagePtr](#hidebug_threadcpuusageptr) | Defines the pointer to **HiDebug_ThreadCpuUsage**.|
| typedef struct [HiDebug_SystemMemInfo](_hi_debug___system_mem_info.md) [HiDebug_SystemMemInfo](#hidebug_systemmeminfo) | Defines a struct for the system memory information.|
| typedef struct [HiDebug_NativeMemInfo](_hi_debug___native_mem_info.md) [HiDebug_NativeMemInfo](#hidebug_nativememinfo) | Defines a struct for the local memory information of the application process.|
| typedef struct [HiDebug_MemoryLimit](_hi_debug___memory_limit.md) [HiDebug_MemoryLimit](#hidebug_memorylimit) | Defines a struct for the memory limit of an application process.|
| typedef enum [HiDebug_TraceFlag](#hidebug_traceflag-1) [HiDebug_TraceFlag](#hidebug_traceflag) | Defines an enum for the types of threads for trace collection.|


### Enums

| Name| Description|
| -------- | -------- |
| [HiDebug_ErrorCode](#hidebug_errorcode-1) {<br>HIDEBUG_SUCCESS = 0,<br>HIDEBUG_INVALID_ARGUMENT = 401,<br>HIDEBUG_TRACE_CAPTURED_ALREADY = 11400102,<br>HIDEBUG_NO_PERMISSION = 11400103,<br>HIDEBUG_TRACE_ABNORMAL = 11400104,<br>HIDEBUG_NO_TRACE_RUNNING = 11400105<br>} | Enumerates the error codes used in the HiDebug module.|
| [HiDebug_TraceFlag](#hidebug_traceflag-1) {<br>HIDEBUG_TRACE_FLAG_MAIN_THREAD = 1, HIDEBUG_TRACE_FLAG_ALL_THREADS = 2<br>} | Enumerates the types of the threads for trace collection.|


### Functions

| Name| Description|
| -------- | -------- |
| double [OH_HiDebug_GetSystemCpuUsage](#oh_hidebug_getsystemcpuusage) () | Obtains the CPU usage of the system.|
| double [OH_HiDebug_GetAppCpuUsage](#oh_hidebug_getappcpuusage) () | Obtains the CPU usage of an application.|
| [HiDebug_ThreadCpuUsagePtr](#hidebug_threadcpuusageptr) [OH_HiDebug_GetAppThreadCpuUsage](#oh_hidebug_getappthreadcpuusage) () | Obtains the CPU usage of all threads of an application.|
| void [OH_HiDebug_FreeThreadCpuUsage](#oh_hidebug_freethreadcpuusage) ([HiDebug_ThreadCpuUsagePtr](#hidebug_threadcpuusageptr) \*threadCpuUsage) | Releases the **HiDebug_ThreadCpuUsagePtr**.|
| void [OH_HiDebug_GetSystemMemInfo](#oh_hidebug_getsystemmeminfo) ([HiDebug_SystemMemInfo](_hi_debug___system_mem_info.md) \*systemMemInfo) | Obtains system memory information.|
| void [OH_HiDebug_GetAppNativeMemInfo](#oh_hidebug_getappnativememinfo) ([HiDebug_NativeMemInfo](_hi_debug___native_mem_info.md) \*nativeMemInfo) | Obtains the memory information of an application process.|
| void [OH_HiDebug_GetAppMemoryLimit](#oh_hidebug_getappmemorylimit) ([HiDebug_MemoryLimit](_hi_debug___memory_limit.md) \*memoryLimit) | Obtains the memory limit of an application process.|
| [HiDebug_ErrorCode](#hidebug_errorcode) [OH_HiDebug_StartAppTraceCapture](#oh_hidebug_startapptracecapture) ([HiDebug_TraceFlag](#hidebug_traceflag) flag, uint64_t tags, uint32_t limitSize, char \*fileName, uint32_t length) | Starts application trace collection.|
| [HiDebug_ErrorCode](#hidebug_errorcode) [OH_HiDebug_StopAppTraceCapture](#oh_hidebug_stopapptracecapture) () | Stops application trace collection.|


## Macro Description


### HIDEBUG_TRACE_TAG_ABILITY_MANAGER

```
#define HIDEBUG_TRACE_TAG_ABILITY_MANAGER   (1ULL << 31)
```

**Description**

Indicates the ability manager.

**Since**: 12


### HIDEBUG_TRACE_TAG_ARK

```
#define HIDEBUG_TRACE_TAG_ARK   (1ULL << 47)
```

**Description**

Indicates the JSVM.

**Since**: 12


### HIDEBUG_TRACE_TAG_ARKUI

```
#define HIDEBUG_TRACE_TAG_ARKUI   (1ULL << 39)
```

**Description**

Indicates the ArkUI development framework.

**Since**: 12


### HIDEBUG_TRACE_TAG_AUDIO

```
#define HIDEBUG_TRACE_TAG_AUDIO   (1ULL << 35)
```

**Description**

Indicates the audio module.

**Since**: 12


### HIDEBUG_TRACE_TAG_BLUETOOTH

```
#define HIDEBUG_TRACE_TAG_BLUETOOTH   (1ULL << 60)
```

**Description**

Indicates the Bluetooth.

**Since**: 12


### HIDEBUG_TRACE_TAG_CAMERA

```
#define HIDEBUG_TRACE_TAG_CAMERA   (1ULL << 32)
```

**Description**

Indicates the camera module.

**Since**: 12


### HIDEBUG_TRACE_TAG_COMMON_LIBRARY

```
#define HIDEBUG_TRACE_TAG_COMMON_LIBRARY   (1ULL << 16)
```

**Description**

Indicates the common library subsystem.

**Since**: 12


### HIDEBUG_TRACE_TAG_DISTRIBUTED_AUDIO

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_AUDIO   (1ULL << 27)
```

**Description**

Indicates the distributed audio.

**Since**: 12


### HIDEBUG_TRACE_TAG_DISTRIBUTED_CAMERA

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_CAMERA   (1ULL << 51)
```

**Description**

Indicates the distributed camera.

**Since**: 12


### HIDEBUG_TRACE_TAG_DISTRIBUTED_DATA

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_DATA   (1ULL << 36)
```

**Description**

Indicates the distributed data management.

**Since**: 12


### HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_DEVICE_MANAGER

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_DEVICE_MANAGER   (1ULL << 54)
```

**Description**

Indicates the distributed hardware device manager.

**Since**: 12


### HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_FRAMEWORK

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_FRAMEWORK   (1ULL << 52)
```

**Description**

Indicates the distributed hardware framework.

**Since**: 12


### HIDEBUG_TRACE_TAG_DISTRIBUTED_INPUT

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_INPUT   (1ULL << 59)
```

**Description**

Indicates the distributed input.

**Since**: 12


### HIDEBUG_TRACE_TAG_DISTRIBUTED_SCHEDULER

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_SCHEDULER   (1ULL << 57)
```

**Description**

Indicates the distributed scheduler.

**Since**: 12


### HIDEBUG_TRACE_TAG_DISTRIBUTED_SCREEN

```
#define HIDEBUG_TRACE_TAG_DISTRIBUTED_SCREEN   (1ULL << 50)
```

**Description**

Indicates the distributed screen.

**Since**: 12


### HIDEBUG_TRACE_TAG_FFRT

```
#define HIDEBUG_TRACE_TAG_FFRT   (1ULL << 13)
```

**Description**

Indicates the FFRT task.

**Since**: 12


### HIDEBUG_TRACE_TAG_FILE_MANAGEMENT

```
#define HIDEBUG_TRACE_TAG_FILE_MANAGEMENT   (1ULL << 29)
```

**Description**

Indicates the file management.

**Since**: 12


### HIDEBUG_TRACE_TAG_GLOBAL_RESOURCE_MANAGER

```
#define HIDEBUG_TRACE_TAG_GLOBAL_RESOURCE_MANAGER   (1ULL << 53)
```

**Description**

Indicates the global resource manager.

**Since**: 12


### HIDEBUG_TRACE_TAG_GRAPHICS

```
#define HIDEBUG_TRACE_TAG_GRAPHICS   (1ULL << 38)
```

**Description**

Indicates the graphics module.

**Since**: 12


### HIDEBUG_TRACE_TAG_HDF

```
#define HIDEBUG_TRACE_TAG_HDF   (1ULL << 18)
```

**Description**

Indicates the HDF subsystem.

**Since**: 12


### HIDEBUG_TRACE_TAG_IMAGE

```
#define HIDEBUG_TRACE_TAG_IMAGE   (1ULL << 34)
```

**Description**

Indicates the image module.

**Since**: 12


### HIDEBUG_TRACE_TAG_MEDIA

```
#define HIDEBUG_TRACE_TAG_MEDIA   (1ULL << 33)
```

**Description**

Indicates the media module.

**Since**: 12


### HIDEBUG_TRACE_TAG_MISC

```
#define HIDEBUG_TRACE_TAG_MISC   (1ULL << 41)
```

**Description**

Indicates the MISC module.

**Since**: 12


### HIDEBUG_TRACE_TAG_MULTIMODAL_INPUT

```
#define HIDEBUG_TRACE_TAG_MULTIMODAL_INPUT   (1ULL << 42)
```

**Description**

Indicates the multimodal input module.

**Since**: 12


### HIDEBUG_TRACE_TAG_NET

```
#define HIDEBUG_TRACE_TAG_NET   (1ULL << 23)
```

**Description**

Indicates the network.

**Since**: 12


### HIDEBUG_TRACE_TAG_NOTIFICATION

```
#define HIDEBUG_TRACE_TAG_NOTIFICATION   (1ULL << 40)
```

**Description**

Indicates the notification module.

**Since**: 12


### HIDEBUG_TRACE_TAG_NWEB

```
#define HIDEBUG_TRACE_TAG_NWEB   (1ULL << 24)
```

**Description**

Indicates the NWeb.

**Since**: 12


### HIDEBUG_TRACE_TAG_OHOS

```
#define HIDEBUG_TRACE_TAG_OHOS   (1ULL << 30)
```

**Description**

Indicates the OpenHarmony OS.

**Since**: 12


### HIDEBUG_TRACE_TAG_POWER_MANAGER

```
#define HIDEBUG_TRACE_TAG_POWER_MANAGER   (1ULL << 56)
```

**Description**

Indicates the power manager.

**Since**: 12


### HIDEBUG_TRACE_TAG_RPC

```
#define HIDEBUG_TRACE_TAG_RPC   (1ULL << 46)
```

**Description**

Indicates the RPC.

**Since**: 12


### HIDEBUG_TRACE_TAG_SAMGR

```
#define HIDEBUG_TRACE_TAG_SAMGR   (1ULL << 55)
```

**Description**

Indicates the service ability manager (SAMGR).

**Since**: 12


### HIDEBUG_TRACE_TAG_WINDOW_MANAGER

```
#define HIDEBUG_TRACE_TAG_WINDOW_MANAGER   (1ULL << 48)
```

**Description**

Indicates the window manager.

**Since**: 12


## Type Description


### HiDebug_ErrorCode

```
typedef enum HiDebug_ErrorCode HiDebug_ErrorCode
```

**Description**

Defines an enum for error codes.

**Since**: 12


### HiDebug_MemoryLimit

```
typedef struct HiDebug_MemoryLimit HiDebug_MemoryLimit
```

**Description**

Defines a struct for the memory limit of an application process.

**Since**: 12


### HiDebug_NativeMemInfo

```
typedef struct HiDebug_NativeMemInfo HiDebug_NativeMemInfo
```

**Description**

Defines a struct for the local memory information of the application process.

**Since**: 12


### HiDebug_SystemMemInfo

```
typedef struct HiDebug_SystemMemInfo HiDebug_SystemMemInfo
```

**Description**

Defines a struct for the system memory information.

**Since**: 12


### HiDebug_ThreadCpuUsage

```
typedef struct HiDebug_ThreadCpuUsage HiDebug_ThreadCpuUsage
```

**Description**

Defines a struct for the CPU usage of all threads of an application.

**Since**: 12


### HiDebug_ThreadCpuUsagePtr

```
typedef HiDebug_ThreadCpuUsage* HiDebug_ThreadCpuUsagePtr
```

**Description**

Defines the pointer to **HiDebug_ThreadCpuUsage**.

**Since**: 12


### HiDebug_TraceFlag

```
typedef enum HiDebug_TraceFlag HiDebug_TraceFlag
```

**Description**

Defines an enum for the types of threads for trace collection.

**Since**: 12


## Enum Description


### HiDebug_ErrorCode

```
enum HiDebug_ErrorCode
```

**Description**

Enumerates the error codes used in the HiDebug module.

**Since**: 12

| Value| Description|
| -------- | -------- |
| HIDEBUG_SUCCESS | Execution successful.|
| HIDEBUG_INVALID_ARGUMENT | Invalid parameter type or incorrect parameter value.|
| HIDEBUG_TRACE_CAPTURED_ALREADY | Repeated collection.|
| HIDEBUG_NO_PERMISSION | No file write permission.|
| HIDEBUG_TRACE_ABNORMAL | Abnormal trace status.|


### HiDebug_TraceFlag

```
enum HiDebug_TraceFlag
```

**Description**

Enumerates the types of the threads for trace collection.

**Since**: 12

| Value| Description|
| -------- | -------- |
| HIDEBUG_TRACE_FLAG_MAIN_THREAD | Only the main thread of the current application.|
| HIDEBUG_TRACE_FLAG_ALL_THREADS | All threads of the current application.|


## Function Description


### OH_HiDebug_FreeThreadCpuUsage()

```
void OH_HiDebug_FreeThreadCpuUsage (HiDebug_ThreadCpuUsagePtr * threadCpuUsage)
```

**Description**

Releases the **HiDebug_ThreadCpuUsagePtr**.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| threadCpuUsage | Pointer to the buffer that stores the available CPU for all threads of the application. For details, see [HiDebug_ThreadCpuUsagePtr](#hidebug_threadcpuusageptr). The input parameter is obtained by **OH_HiDebug_GetAppThreadCpuUsage()**.|


### OH_HiDebug_GetAppCpuUsage()

```
double OH_HiDebug_GetAppCpuUsage ()
```

**Description**

Obtains the CPU usage of an application.

**Since**: 12

**Returns**

Returns the application CPU usage obtained if the operation is successful. Returns **0** if the operation fails.


### OH_HiDebug_GetAppMemoryLimit()

```
void OH_HiDebug_GetAppMemoryLimit (HiDebug_MemoryLimit * memoryLimit)
```

**Description**

Obtains the memory limit of an application process.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| memoryLimit | Pointer to the [HiDebug_MemoryLimit](_hi_debug___memory_limit.md) to obtain. If the struct is empty, the function call fails.|


### OH_HiDebug_GetAppNativeMemInfo()

```
void OH_HiDebug_GetAppNativeMemInfo (HiDebug_NativeMemInfo * nativeMemInfo)
```

**Description**

Obtains the memory information of an application process.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| nativeMemInfo | Pointer to the [HiDebug_NativeMemInfo](_hi_debug___native_mem_info.md) to obtain. If the struct is empty, the function call fails.|


### OH_HiDebug_GetAppThreadCpuUsage()

```
HiDebug_ThreadCpuUsagePtr OH_HiDebug_GetAppThreadCpuUsage ()
```

**Description**

Obtains the CPU usage of all threads of an application.

**Since**: 12

**Returns**

Returns the CPU usage of all threads. For details, see [HiDebug_ThreadCpuUsagePtr](#hidebug_threadcpuusageptr). Returns **null** if the function fails to be called.


### OH_HiDebug_GetSystemCpuUsage()

```
double OH_HiDebug_GetSystemCpuUsage ()
```

**Description**

Obtains the CPU usage of the system.

**Since**: 12

**Returns**

Returns the system CPU usage if the operation is successful. Returns **0** if the operation fails.

### OH_HiDebug_GetSystemMemInfo()

```
void OH_HiDebug_GetSystemMemInfo (HiDebug_SystemMemInfo * systemMemInfo)
```

**Description**

Obtains system memory information.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| systemMemInfo | Pointer to the [HiDebug_SystemMemInfo](_hi_debug___system_mem_info.md) to obtain. If the struct is empty, the function call fails.|


### OH_HiDebug_StartAppTraceCapture()

```
HiDebug_ErrorCode OH_HiDebug_StartAppTraceCapture (HiDebug_TraceFlag flag, uint64_t tags, uint32_t limitSize, char * fileName, uint32_t length )
```

**Description**

Starts application trace collection.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| flag | Type of the thread (the main thread or all threads of the application) to trace.|
| tags | Modules or subsystems to trace.|
| limitSize | Maximum size of the trace file (in bytes), which is 500 MB.|
| fileName | Buffer for the output trace file.|
| length | Length of the buffer for the output trace file.|

**Returns**

0 - The operation is successful. 401 - The **fileName** parameter is a null pointer, the input **length** parameter is too small, or the value of **limitSize** is **0** or smaller than **0**. 11400102 - A trace is already started. 11400103 - You do not have the permission to start the trace function. 11400104 - An internal system error occurs.


### OH_HiDebug_StopAppTraceCapture()

```
HiDebug_ErrorCode OH_HiDebug_StopAppTraceCapture ()
```

**Description**

Stops application trace collection.

**Since**: 12

**Returns**

0 - The operation is successful. 11400104 - An internal system error occurs. 11400105 - No trace is being performed.

### OH_HiDebug_GetGraphicsMemory();
```
HiDebug_ErrorCode OH_HiDebug_GetGraphicsMemory(uint32_t *value);
```

**Description**

Obtains the size of the GPU memory.

**Since**: 14

**Parameters**

| Name| Description                             |
| -------- |---------------------------------|
| value | Pointer to the variable that stores the size (in KB) of the obtained GPU memory.|

**Returns**

0 - The operation is successful. 401- The input parameter is invalid. 11400104 - An internal system error occurs. 
