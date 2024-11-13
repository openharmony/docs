# hidebug.h


## 概述

定义HiDebug模块的调试功能。

**库：** libohhidebug.so

**系统能力：** SystemCapability.HiviewDFX.HiProfiler.HiDebug

**引用文件：** &lt;hidebug/hidebug.h&gt;

**起始版本：** 12

**相关模块：**[HiDebug](_hi_debug.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| double [OH_HiDebug_GetSystemCpuUsage](_hi_debug.md#oh_hidebug_getsystemcpuusage) () | 获取系统的CPU资源占用情况百分比。  | 
| double [OH_HiDebug_GetAppCpuUsage](_hi_debug.md#oh_hidebug_getappcpuusage) () | 获取进程的CPU使用率百分比。  | 
| [HiDebug_ThreadCpuUsagePtr](_hi_debug.md#hidebug_threadcpuusageptr) [OH_HiDebug_GetAppThreadCpuUsage](_hi_debug.md#oh_hidebug_getappthreadcpuusage) () | 获取应用所有线程CPU使用情况。  | 
| void [OH_HiDebug_FreeThreadCpuUsage](_hi_debug.md#oh_hidebug_freethreadcpuusage) ([HiDebug_ThreadCpuUsagePtr](_hi_debug.md#hidebug_threadcpuusageptr) \*threadCpuUsage) | 释放线程数据结构。  | 
| void [OH_HiDebug_GetSystemMemInfo](_hi_debug.md#oh_hidebug_getsystemmeminfo) ([HiDebug_SystemMemInfo](_hi_debug___system_mem_info.md) \*systemMemInfo) | 获取系统内存信息。  | 
| void [OH_HiDebug_GetAppNativeMemInfo](_hi_debug.md#oh_hidebug_getappnativememinfo) ([HiDebug_NativeMemInfo](_hi_debug___native_mem_info.md) \*nativeMemInfo) | 获取应用程序进程的内存信息。  | 
| void [OH_HiDebug_GetAppMemoryLimit](_hi_debug.md#oh_hidebug_getappmemorylimit) ([HiDebug_MemoryLimit](_hi_debug___memory_limit.md) \*memoryLimit) | 获取应用程序进程的内存限制。  | 
| [HiDebug_ErrorCode](_hi_debug.md#hidebug_errorcode) [OH_HiDebug_StartAppTraceCapture](_hi_debug.md#oh_hidebug_startapptracecapture) ([HiDebug_TraceFlag](_hi_debug.md#hidebug_traceflag) flag, uint64_t tags, uint32_t limitSize, char \*fileName, uint32_t length) | 启动应用trace采集。  | 
| [HiDebug_ErrorCode](_hi_debug.md#hidebug_errorcode) [OH_HiDebug_StopAppTraceCapture](_hi_debug.md#oh_hidebug_stopapptracecapture) () | 停止采集应用程序trace。  | 
| [HiDebug_ErrorCode](_hi_debug.md#hidebug_errorcode) [OH_HiDebug_GetGraphicsMemory](_hi_debug.md#oh_hidebug_getgraphicsmemory) ()     | 获取应用显存大小。   |
