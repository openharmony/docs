# hidebug_type.h


## Overview

Defines the structs of the HiDebug module. \@kit PerformanceAnalysisKit

**Library**: libohhidebug.so

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Since**: 12

**Related module**: [HiDebug](_hi_debug.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[HiDebug_ThreadCpuUsage](_hi_debug___thread_cpu_usage.md) | Defines the CPU usage of all threads in an application. | 
| struct&nbsp;&nbsp;[HiDebug_SystemMemInfo](_hi_debug___system_mem_info.md) | Defines the system memory information. | 
| struct&nbsp;&nbsp;[HiDebug_NativeMemInfo](_hi_debug___native_mem_info.md) | Defines the local memory information of an application process. | 
| struct&nbsp;&nbsp;[HiDebug_MemoryLimit](_hi_debug___memory_limit.md) | Defines the memory limit of an application process. | 


### Macros

| Name| Description| 
| -------- | -------- |
| [HIDEBUG_TRACE_TAG_FFRT](_hi_debug.md#hidebug_trace_tag_ffrt)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 13) | Indicates a function flow runtime (FFRT) task. | 
| [HIDEBUG_TRACE_TAG_COMMON_LIBRARY](_hi_debug.md#hidebug_trace_tag_common_library)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 16) | Indicates the common library subsystem. | 
| [HIDEBUG_TRACE_TAG_HDF](_hi_debug.md#hidebug_trace_tag_hdf)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 18) | Indicates the HDF subsystem. | 
| [HIDEBUG_TRACE_TAG_NET](_hi_debug.md#hidebug_trace_tag_net)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 23) | Indicates the Network. | 
| [HIDEBUG_TRACE_TAG_NWEB](_hi_debug.md#hidebug_trace_tag_nweb)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 24) | Indicates the NWeb. | 
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_AUDIO](_hi_debug.md#hidebug_trace_tag_distributed_audio)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 27) | Indicates the distributed audio. | 
| [HIDEBUG_TRACE_TAG_FILE_MANAGEMENT](_hi_debug.md#hidebug_trace_tag_file_management)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 29) | Indicates the file management. | 
| [HIDEBUG_TRACE_TAG_OHOS](_hi_debug.md#hidebug_trace_tag_ohos)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 30) | Indicates the OpenHarmony OS. | 
| [HIDEBUG_TRACE_TAG_ABILITY_MANAGER](_hi_debug.md#hidebug_trace_tag_ability_manager)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 31) | Indicates the Ability Manager. | 
| [HIDEBUG_TRACE_TAG_CAMERA](_hi_debug.md#hidebug_trace_tag_camera)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 32) | Indicates the camera module. | 
| [HIDEBUG_TRACE_TAG_MEDIA](_hi_debug.md#hidebug_trace_tag_media)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 33) | Indicates the media module. | 
| [HIDEBUG_TRACE_TAG_IMAGE](_hi_debug.md#hidebug_trace_tag_image)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 34) | Indicates the image module. | 
| [HIDEBUG_TRACE_TAG_AUDIO](_hi_debug.md#hidebug_trace_tag_audio)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 35) | Indicates the audio module. | 
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_DATA](_hi_debug.md#hidebug_trace_tag_distributed_data)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 36) | Indicates the distributed data management. | 
| [HIDEBUG_TRACE_TAG_GRAPHICS](_hi_debug.md#hidebug_trace_tag_graphics)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 38) | Indicates the graphics module. | 
| [HIDEBUG_TRACE_TAG_ARKUI](_hi_debug.md#hidebug_trace_tag_arkui)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 39) | Indicates the ArkUI development framework. | 
| [HIDEBUG_TRACE_TAG_NOTIFICATION](_hi_debug.md#hidebug_trace_tag_notification)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 40) | Indicates the notification module. | 
| [HIDEBUG_TRACE_TAG_MISC](_hi_debug.md#hidebug_trace_tag_misc)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 41) | Indicates the MISC module. | 
| [HIDEBUG_TRACE_TAG_MULTIMODAL_INPUT](_hi_debug.md#hidebug_trace_tag_multimodal_input)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 42) | Indicates the multimodal input module. | 
| [HIDEBUG_TRACE_TAG_RPC](_hi_debug.md#hidebug_trace_tag_rpc)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 46) | Indicates a remote procedure call (RPC). | 
| [HIDEBUG_TRACE_TAG_ARK](_hi_debug.md#hidebug_trace_tag_ark)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 47) | Indicates a JavaScript virtual machine (JSVM). | 
| [HIDEBUG_TRACE_TAG_WINDOW_MANAGER](_hi_debug.md#hidebug_trace_tag_window_manager)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 48) | Indicates the window manager. | 
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_SCREEN](_hi_debug.md#hidebug_trace_tag_distributed_screen)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 50) | Indicates the distributed screen. | 
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_CAMERA](_hi_debug.md#hidebug_trace_tag_distributed_camera)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 51) | Indicates the distributed camera. | 
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_FRAMEWORK](_hi_debug.md#hidebug_trace_tag_distributed_hardware_framework)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 52) | Indicates the distributed hardware framework. | 
| [HIDEBUG_TRACE_TAG_GLOBAL_RESOURCE_MANAGER](_hi_debug.md#hidebug_trace_tag_global_resource_manager)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 53) | Indicates the global resource management. | 
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_HARDWARE_DEVICE_MANAGER](_hi_debug.md#hidebug_trace_tag_distributed_hardware_device_manager)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 54) | Indicates the distributed hardware device management. | 
| [HIDEBUG_TRACE_TAG_SAMGR](_hi_debug.md#hidebug_trace_tag_samgr)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 55) | Indicates the Samgr (SA). | 
| [HIDEBUG_TRACE_TAG_POWER_MANAGER](_hi_debug.md#hidebug_trace_tag_power_manager)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 56) | Indicates the power manager. | 
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_SCHEDULER](_hi_debug.md#hidebug_trace_tag_distributed_scheduler)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 57) | Indicates the distributed scheduler. | 
| [HIDEBUG_TRACE_TAG_DISTRIBUTED_INPUT](_hi_debug.md#hidebug_trace_tag_distributed_input)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 59) | Indicates the distributed input. | 
| [HIDEBUG_TRACE_TAG_BLUETOOTH](_hi_debug.md#hidebug_trace_tag_bluetooth)&nbsp;&nbsp;&nbsp;(1ULL &lt;&lt; 60) | Indicates the Bluetooth. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [HiDebug_ErrorCode](_hi_debug.md#hidebug_errorcode-1) [HiDebug_ErrorCode](_hi_debug.md#hidebug_errorcode) | Defines an enum for the error codes used in the HiDebug module. | 
| typedef struct [HiDebug_ThreadCpuUsage](_hi_debug___thread_cpu_usage.md) [HiDebug_ThreadCpuUsage](_hi_debug.md#hidebug_threadcpuusage) | Defines a struct for the CPU usage of all threads of an application. | 
| typedef [HiDebug_ThreadCpuUsage](_hi_debug___thread_cpu_usage.md) \* [HiDebug_ThreadCpuUsagePtr](_hi_debug.md#hidebug_threadcpuusageptr) | Defines the pointer to **HiDebug_ThreadCpuUsage** . | 
| typedef struct [HiDebug_SystemMemInfo](_hi_debug___system_mem_info.md) [HiDebug_SystemMemInfo](_hi_debug.md#hidebug_systemmeminfo) | Defines a struct for the system memory information. | 
| typedef struct [HiDebug_NativeMemInfo](_hi_debug___native_mem_info.md) [HiDebug_NativeMemInfo](_hi_debug.md#hidebug_nativememinfo) | Defines a struct for the local memory information of an application process. | 
| typedef struct [HiDebug_MemoryLimit](_hi_debug___memory_limit.md) [HiDebug_MemoryLimit](_hi_debug.md#hidebug_memorylimit) | Defines a struct for the memory limit of an application process. | 
| typedef enum [HiDebug_TraceFlag](_hi_debug.md#hidebug_traceflag-1) [HiDebug_TraceFlag](_hi_debug.md#hidebug_traceflag) | Defines an enum for the thread types for trace collection. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [HiDebug_ErrorCode](_hi_debug.md#hidebug_errorcode-1) {<br>HIDEBUG_SUCCESS = 0,<br>HIDEBUG_INVALID_ARGUMENT = 401,<br>HIDEBUG_TRACE_CAPTURED_ALREADY = 11400102,<br>HIDEBUG_NO_PERMISSION = 11400103,<br>HIDEBUG_TRACE_ABNORMAL = 11400104,<br>HIDEBUG_NO_TRACE_RUNNING = 11400105<br>} | Enumerates the error codes used in the HiDebug module. | 
| [HiDebug_TraceFlag](_hi_debug.md#hidebug_traceflag-1) {<br>HIDEBUG_TRACE_FLAG_MAIN_THREAD = 1,<br>HIDEBUG_TRACE_FLAG_ALL_THREADS = 2<br>} | Enumerates the thread types for trace collection. | 
