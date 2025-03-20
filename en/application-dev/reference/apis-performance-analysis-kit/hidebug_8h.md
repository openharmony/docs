# hidebug.h


## Overview

Defines the functions for debugging.

**Library**: libohhidebug.so

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**File to include**: <hidebug/hidebug.h>

**Since**: 12

**Related module**: [HiDebug](_hi_debug.md)


## Summary


### Function

| Name| Description| 
| -------- | -------- |
| double [OH_HiDebug_GetSystemCpuUsage](_hi_debug.md#oh_hidebug_getsystemcpuusage) () | Obtains the CPU usage of the system. | 
| double [OH_HiDebug_GetAppCpuUsage](_hi_debug.md#oh_hidebug_getappcpuusage) () | Obtains the CPU usage of an application. | 
| [HiDebug_ThreadCpuUsagePtr](_hi_debug.md#hidebug_threadcpuusageptr) [OH_HiDebug_GetAppThreadCpuUsage](_hi_debug.md#oh_hidebug_getappthreadcpuusage) () | Obtains the CPU usage of all threads of an application. | 
| void [OH_HiDebug_FreeThreadCpuUsage](_hi_debug.md#oh_hidebug_freethreadcpuusage) ([HiDebug_ThreadCpuUsagePtr](_hi_debug.md#hidebug_threadcpuusageptr) \*threadCpuUsage) | Releases the thread data struct. | 
| void [OH_HiDebug_GetSystemMemInfo](_hi_debug.md#oh_hidebug_getsystemmeminfo) ([HiDebug_SystemMemInfo](_hi_debug___system_mem_info.md) \*systemMemInfo) | Obtains system memory information. | 
| void [OH_HiDebug_GetAppNativeMemInfo](_hi_debug.md#oh_hidebug_getappnativememinfo) ([HiDebug_NativeMemInfo](_hi_debug___native_mem_info.md) \*nativeMemInfo) | Obtains the memory information of an application. | 
| void [OH_HiDebug_GetAppMemoryLimit](_hi_debug.md#oh_hidebug_getappmemorylimit) ([HiDebug_MemoryLimit](_hi_debug___memory_limit.md) \*memoryLimit) | Obtains the memory limit of an application. | 
| [HiDebug_ErrorCode](_hi_debug.md#hidebug_errorcode) [OH_HiDebug_StartAppTraceCapture](_hi_debug.md#oh_hidebug_startapptracecapture) ([HiDebug_TraceFlag](_hi_debug.md#hidebug_traceflag) flag, uint64_t tags, uint32_t limitSize, char \*fileName, uint32_t length) | Starts tracing of an application. | 
| [HiDebug_ErrorCode](_hi_debug.md#hidebug_errorcode) [OH_HiDebug_StopAppTraceCapture](_hi_debug.md#oh_hidebug_stopapptracecapture) () | Stops application tracing. | 
| [HiDebug_ErrorCode](_hi_debug.md#hidebug_errorcode) [OH_HiDebug_GetGraphicsMemory](_hi_debug.md#oh_hidebug_getgraphicsmemory) (uint32_t \*value) | Obtains the size of the GPU memory. | 
