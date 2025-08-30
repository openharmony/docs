# hidebug.h

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @hello_harmony; @yu_haoqiaida-->
<!--SE: @kutcherzhou1-->
<!--TSE: @gcw_KuLfPSbe-->

## Overview

Defines the APIs for debugging.

**File to include**: <hidebug/hidebug.h>

**Library**: libohhidebug.so

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiDebug

**Since**: 12

**Related module**: [HiDebug](capi-hidebug.md)

## Summary

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [double OH_HiDebug_GetSystemCpuUsage()](#oh_hidebug_getsystemcpuusage) | - | Obtains the CPU usage of the system. Note that this API involves cross-process communication and takes a long time. Therefore, you are advised not to call this API in the main thread.|
| [double OH_HiDebug_GetAppCpuUsage()](#oh_hidebug_getappcpuusage) | - | Obtains the CPU usage of an application. Note that this API involves cross-process communication and takes a long time. Therefore, you are advised not to call this API in the main thread.|
| [HiDebug_ThreadCpuUsagePtr OH_HiDebug_GetAppThreadCpuUsage()](#oh_hidebug_getappthreadcpuusage) | - | Obtains the CPU usage of all threads of an application. Note that this API involves cross-process communication and takes a long time. Therefore, you are advised not to call this API in the main thread.|
| [void OH_HiDebug_FreeThreadCpuUsage(HiDebug_ThreadCpuUsagePtr *threadCpuUsage)](#oh_hidebug_freethreadcpuusage) | - | Releases the **HiDebug_ThreadCpuUsagePtr**.|
| [void OH_HiDebug_GetSystemMemInfo(HiDebug_SystemMemInfo *systemMemInfo)](#oh_hidebug_getsystemmeminfo) | - | Obtains system memory information.|
| [void OH_HiDebug_GetAppNativeMemInfo(HiDebug_NativeMemInfo *nativeMemInfo)](#oh_hidebug_getappnativememinfo) | - | Obtains the memory information of an application process. Note that this API needs to read the **/proc/{pid}/smaps_rollup** node information, which takes a long time. Therefore, you are advised not to call this API in the main thread.|
| [void OH_HiDebug_GetAppNativeMemInfoWithCache(HiDebug_NativeMemInfo *nativeMemInfo, bool forceRefresh)](#oh_hidebug_getappnativememinfowithcache) | - | Obtains the memory information of an application process. This API has a cache mechanism to improve its performance. The cache value is valid for 5 minutes. Note that this API needs to read the **/proc/{pid}/smaps_rollup** node information, which takes a long time. Therefore, you are advised not to call this API in the main thread.|
| [void OH_HiDebug_GetAppMemoryLimit(HiDebug_MemoryLimit *memoryLimit)](#oh_hidebug_getappmemorylimit) | - | Obtains the memory limit of an application process.|
| [HiDebug_ErrorCode OH_HiDebug_StartAppTraceCapture(HiDebug_TraceFlag flag, uint64_t tags, uint32_t limitSize,char* fileName, uint32_t length)](#oh_hidebug_startapptracecapture) | - | Starts application trace collection.|
| [HiDebug_ErrorCode OH_HiDebug_StopAppTraceCapture()](#oh_hidebug_stopapptracecapture) | - | Stops application trace collection.|
| [HiDebug_ErrorCode OH_HiDebug_GetGraphicsMemory(uint32_t *value)](#oh_hidebug_getgraphicsmemory) | - | Obtains the size of the GPU memory. Note that this API involves multiple cross-process communications and may take more than 1 second. Therefore, you are advised not to call this API in the main thread.|
| [int OH_HiDebug_BacktraceFromFp(HiDebug_Backtrace_Object object, void* startFp, void** pcArray, int size)](#oh_hidebug_backtracefromfp) | - | Performs stack back-tracing based on the given fp address. This function is async-signal-safe.|
| [typedef void (\*OH_HiDebug_SymbolicAddressCallback)(void* pc, void* arg, const HiDebug_StackFrame* frame)](#oh_hidebug_symbolicaddresscallback) | OH_HiDebug_SymbolicAddressCallback | If the [OH_HiDebug_SymbolicAddress](capi-hidebug-h.md#oh_hidebug_symbolicaddress) API is successfully called, the parsed stack information is returned to the caller through this function. Note that this API involves multiple I/O operations and takes a long time. Therefore, you are advised not to call this API in the main thread.|
| [HiDebug_ErrorCode OH_HiDebug_SymbolicAddress(HiDebug_Backtrace_Object object, void* pc, void* arg,OH_HiDebug_SymbolicAddressCallback callback)](#oh_hidebug_symbolicaddress) | - | Obtains detailed symbol information based on the specified PC address. This function is not asyn-signal-safe.|
| [HiDebug_Backtrace_Object OH_HiDebug_CreateBacktraceObject(void)](#oh_hidebug_createbacktraceobject) | - | Creates an object for stack back-tracing and parsing. This function is not asyn-signal-safe.|
| [void OH_HiDebug_DestroyBacktraceObject(HiDebug_Backtrace_Object object)](#oh_hidebug_destroybacktraceobject) | - | Destroys the object created by [OH_HiDebug_CreateBacktraceObject](capi-hidebug-h.md#oh_hidebug_createbacktraceobject) to release the resources applied for during stack back-tracing and parsing. This function is not asyn-signal-safe.|
| [HiDebug_ErrorCode OH_HiDebug_SetMallocDispatchTable(struct HiDebug_MallocDispatch *dispatchTable)](#oh_hidebug_setmallocdispatchtable) | - | Sets the MallocDisaptch table of the system C library to replace the custom memory operation functions (such as **malloc**, **free**, **calloc**, **realloc**, **mmap**, and **munmap**). The MallocDisaptch table is a struct that encapsulates memory operation functions such as **malloc**, **calloc**, **realloc**, and **free** in the system C library. HiDebug_MallocDispatch is only a part of the MallocDisaptch struct.|
| [HiDebug_MallocDispatch* OH_HiDebug_GetDefaultMallocDispatchTable(void)](#oh_hidebug_getdefaultmallocdispatchtable) | - | Obtains the default MallocDispatch table of the system C library. You can call [OH_HiDebug_RestoreMallocDispatchTable](capi-hidebug-h.md#oh_hidebug_restoremallocdispatchtable) to restore the table.|
| [void OH_HiDebug_RestoreMallocDispatchTable(void)](#oh_hidebug_restoremallocdispatchtable) | - | Restores the MallocDispatch table of the system C library.|

## Function Description

### OH_HiDebug_GetSystemCpuUsage()

```
double OH_HiDebug_GetSystemCpuUsage()
```

**Description**

Obtains the CPU usage of the system. Note that this API involves cross-process communication and takes a long time. Therefore, you are advised not to call this API in the main thread.

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| double | Returns the system CPU usage if the operation is successful. Returns **0** if the operation fails.|

### OH_HiDebug_GetAppCpuUsage()

```
double OH_HiDebug_GetAppCpuUsage()
```

**Description**

Obtains the CPU usage of an application. Note that this API involves cross-process communication and takes a long time. Therefore, you are advised not to call this API in the main thread.

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| double | Returns the application CPU usage obtained if the operation is successful. If **0** is returned, the CPU usage of the current application is too low.|

### OH_HiDebug_GetAppThreadCpuUsage()

```
HiDebug_ThreadCpuUsagePtr OH_HiDebug_GetAppThreadCpuUsage()
```

**Description**

Obtains the CPU usage of all threads of an application. Note that this API involves cross-process communication and takes a long time. Therefore, you are advised not to call this API in the main thread.

**Since**: 12

**Returns**

| Type| Description                                                                                          |
| -- |----------------------------------------------------------------------------------------------|
| [HiDebug_ThreadCpuUsagePtr](capi-hidebug-hidebug-threadcpuusage.md) | CPU usage of all threads. For details, see [HiDebug_ThreadCpuUsagePtr](capi-hidebug-hidebug-threadcpuusage.md).<br>         If null is returned, the thread data may not be obtained.|

### OH_HiDebug_FreeThreadCpuUsage()

```
void OH_HiDebug_FreeThreadCpuUsage(HiDebug_ThreadCpuUsagePtr *threadCpuUsage)
```

**Description**

Releases the **HiDebug_ThreadCpuUsagePtr**.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [HiDebug_ThreadCpuUsagePtr](capi-hidebug-hidebug-threadcpuusage.md) *threadCpuUsage | Pointer to the available CPU buffer of all threads of the application. For details, see [HiDebug_ThreadCpuUsagePtr](capi-hidebug-hidebug-threadcpuusage.md). The input parameter is obtained by **OH_HiDebug_GetAppThreadCpuUsage()**.|

### OH_HiDebug_GetSystemMemInfo()

```
void OH_HiDebug_GetSystemMemInfo(HiDebug_SystemMemInfo *systemMemInfo)
```

**Description**

Obtains system memory information.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [HiDebug_SystemMemInfo](capi-hidebug-hidebug-systemmeminfo.md) *systemMemInfo | Pointer to [HiDebug_SystemMemInfo](capi-hidebug-hidebug-systemmeminfo.md). If the struct data is empty after the function is called, the calling fails.|

### OH_HiDebug_GetAppNativeMemInfo()

```
void OH_HiDebug_GetAppNativeMemInfo(HiDebug_NativeMemInfo *nativeMemInfo)
```

**Description**

Obtains the memory information of an application process. Note that this API needs to read the **/proc/{pid}/smaps_rollup** node information, which takes a long time. Therefore, you are advised not to call this API in the main thread.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [HiDebug_NativeMemInfo](capi-hidebug-hidebug-nativememinfo.md) *nativeMemInfo | Pointer to [HiDebug_NativeMemInfo](capi-hidebug-hidebug-nativememinfo.md). If the struct data is empty after the function is called, the calling fails.|

### OH_HiDebug_GetAppNativeMemInfoWithCache()

```
void OH_HiDebug_GetAppNativeMemInfoWithCache(HiDebug_NativeMemInfo *nativeMemInfo, bool forceRefresh)
```

**Description**

Obtains the memory information of an application process. This API has a cache mechanism to improve its performance. The cache value is valid for 5 minutes. Note that this API needs to read the **/proc/{pid}/smaps_rollup** node information, which takes a long time. Therefore, you are advised not to call this API in the main thread.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [HiDebug_NativeMemInfo](capi-hidebug-hidebug-nativememinfo.md) *nativeMemInfo | Pointer to [HiDebug_NativeMemInfo](capi-hidebug-hidebug-nativememinfo.md). If the struct data is empty after the function is called, the calling fails.|
| bool forceRefresh |  Whether to ignore the cache validity and forcibly update the cache value.<br>                      The value **true** means to directly obtain the current memory data and update the cache value.<br>                      The value **false** means to directly return the cache value if the cache is valid and obtain the current memory data and update the cache value if the cache is invalid.|

### OH_HiDebug_GetAppMemoryLimit()

```
void OH_HiDebug_GetAppMemoryLimit(HiDebug_MemoryLimit *memoryLimit)
```

**Description**

Obtains the memory limit of an application process.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [HiDebug_MemoryLimit](capi-hidebug-hidebug-memorylimit.md) *memoryLimit | Pointer to [HiDebug_MemoryLimit](capi-hidebug-hidebug-memorylimit.md). If the struct data is empty after the function is called, the calling fails.|

### OH_HiDebug_StartAppTraceCapture()

```
HiDebug_ErrorCode OH_HiDebug_StartAppTraceCapture(HiDebug_TraceFlag flag, uint64_t tags, uint32_t limitSize,char* fileName, uint32_t length)
```

**Description**

Starts application trace collection.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [HiDebug_TraceFlag](capi-hidebug-type-h.md#hidebug_traceflag) flag | Type of the thread (the main thread or all threads of the application) to trace.|
| uint64_t tags | Modules or subsystems to trace.|
| uint32_t limitSize | Maximum size of the trace file (in bytes), which is 500 MB.|
| char* fileName | Buffer for the output trace file.|
| uint32_t length | Length of the buffer for the output trace file.|

**Returns**

| Type| Description|
| -- | -- |
| [HiDebug_ErrorCode](capi-hidebug-type-h.md#hidebug_errorcode) | **0** - The operation is successful.<br>         [HIDEBUG_INVALID_ARGUMENT](capi-hidebug-type-h.md#hidebug_errorcode) 401 - The **fileName** parameter is a null pointer, the input **length** parameter is too small, or the **limitSize** parameter is less than or equal to 0.<br>         **11400102** - A trace is already started.<br>         **11400103** - You do not have the permission to start the trace function.<br>         **11400104** - An internal system error occurs.|

### OH_HiDebug_StopAppTraceCapture()

```
HiDebug_ErrorCode OH_HiDebug_StopAppTraceCapture()
```

**Description**

Stops application trace collection.

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| [HiDebug_ErrorCode](capi-hidebug-type-h.md#hidebug_errorcode) | **0** - The operation is successful.<br>         **11400104** - An internal system error occurs.<br>         **11400105** - No trace collection is running.|

### OH_HiDebug_GetGraphicsMemory()

```
HiDebug_ErrorCode OH_HiDebug_GetGraphicsMemory(uint32_t *value)
```

**Description**

Obtains the size of the GPU memory. Note that this API involves multiple cross-process communications and may take more than 1 second. Therefore, you are advised not to call this API in the main thread.

**Since**: 14


**Parameters**

| Name| Description|
| -- | -- |
| uint32_t *value | Pointer to the variable that stores the size (in KB) of the obtained GPU memory.|

**Returns**

| Type| Description|
| -- | -- |
| [HiDebug_ErrorCode](capi-hidebug-type-h.md#hidebug_errorcode) | **0** - The API is obtained successfully.<br>          **401** - The parameter is a null pointer, which is invalid.<br>          **11400104** - An internal system error occurs.|

### OH_HiDebug_BacktraceFromFp()

```
int OH_HiDebug_BacktraceFromFp(HiDebug_Backtrace_Object object, void* startFp, void** pcArray, int size)
```

**Description**

Performs stack back-tracing based on the given fp address. This function is async-signal-safe.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [HiDebug_Backtrace_Object](capi-hidebug-hidebug-backtrace-object--8h.md) object | Object obtained by the [OH_HiDebug_CreateBacktraceObject](capi-hidebug-h.md#oh_hidebug_createbacktraceobject) API for stack backtracing.|
| void* startFp | Start frame pointer for stack backtracing.|
| void** pcArray | Array of PC addresses obtained from stack backtracing.|
| int size | Length of the PC address array obtained by stack backtracing.|

**Returns**

| Type| Description|
| -- | -- |
| int | Number of stack frames that are successfully backtraced and written to **pcArray**. If 0 is returned, stack backtracing may fail.|

### OH_HiDebug_SymbolicAddressCallback()

```
typedef void (*OH_HiDebug_SymbolicAddressCallback)(void* pc, void* arg, const HiDebug_StackFrame* frame)
```

**Description**

If the [OH_HiDebug_SymbolicAddress](capi-hidebug-h.md#oh_hidebug_symbolicaddress) API is successfully called, the parsed stack information is returned to the caller through this function. Note that this API involves multiple I/O operations and takes a long time. Therefore, you are advised not to call this API in the main thread.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| void* pc | PC address transferred to the [OH_HiDebug_SymbolicAddress](capi-hidebug-h.md#oh_hidebug_symbolicaddress) API for parsing.|
|  void* arg | arg value of the [OH_HiDebug_SymbolicAddress](capi-hidebug-h.md#oh_hidebug_symbolicaddress) API.|
| [ const HiDebug_StackFrame](capi-hidebug-hidebug-stackframe.md)* frame | Pointer to [HiDebug_StackFrame](capi-hidebug-hidebug-stackframe.md), which is obtained by parsing the PC address passed to the [OH_HiDebug_SymbolicAddress](capi-hidebug-h.md#oh_hidebug_symbolicaddress) API. What the pointer points to is valid only in the function scope.|

### OH_HiDebug_SymbolicAddress()

```
HiDebug_ErrorCode OH_HiDebug_SymbolicAddress(HiDebug_Backtrace_Object object, void* pc, void* arg,OH_HiDebug_SymbolicAddressCallback callback)
```

**Description**

Obtains detailed symbol information based on the specified PC address. This function is not asyn-signal-safe.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [HiDebug_Backtrace_Object](capi-hidebug-hidebug-backtrace-object--8h.md) object | Object created by the [OH_HiDebug_CreateBacktraceObject](capi-hidebug-h.md#oh_hidebug_createbacktraceobject) API.|
| void* pc | PC address obtained through the [OH_HiDebug_BacktraceFromFp](capi-hidebug-h.md#oh_hidebug_backtracefromfp) API.|
| void* arg | Reserved custom parameter. After the symbol is successfully parsed, this parameter is passed to [OH_HiDebug_SymbolicAddressCallback](capi-hidebug-h.md#oh_hidebug_symbolicaddresscallback).|
| [OH_HiDebug_SymbolicAddressCallback](capi-hidebug-h.md#oh_hidebug_symbolicaddresscallback) callback | Callback used to return the parsed stack information.|

**Returns**

| Type| Description|
| -- | -- |
| [HiDebug_ErrorCode](capi-hidebug-type-h.md#hidebug_errorcode) | For details, see [HiDebug_ErrorCode](capi-hidebug-type-h.md#hidebug_errorcode).<br>         [HIDEBUG_SUCCESS](capi-hidebug-type-h.md#hidebug_errorcode): The detailed stack information is successfully obtained, and the callback input by the function is called.<br>         [HIDEBUG_INVALID_ARGUMENT](capi-hidebug-type-h.md#hidebug_errorcode): Invalid parameter.<br>         [HIDEBUG_INVALID_SYMBOLIC_PC_ADDRESS](capi-hidebug-type-h.md#hidebug_errorcode): Failed to find the corresponding symbol based on the input PC address.|

### OH_HiDebug_CreateBacktraceObject()

```
HiDebug_Backtrace_Object OH_HiDebug_CreateBacktraceObject(void)
```

**Description**

Creates an object for stack backtracing and parsing. This function is not asyn-signal-safe.

**Since**: 20

**Returns**

| Type| Description|
| -- | -- |
| [HiDebug_Backtrace_Object](capi-hidebug-hidebug-backtrace-object--8h.md) | Pointer to the created object. If the object fails to be created, NULL is returned.|

### OH_HiDebug_DestroyBacktraceObject()

```
void OH_HiDebug_DestroyBacktraceObject(HiDebug_Backtrace_Object object)
```

**Description**

Destroys the object created by [OH_HiDebug_CreateBacktraceObject](capi-hidebug-h.md#oh_hidebug_createbacktraceobject) to release the resources applied for during stack backtracing and parsing. This function is not asyn-signal-safe.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [HiDebug_Backtrace_Object](capi-hidebug-hidebug-backtrace-object--8h.md) object | Object to destroy.|

### OH_HiDebug_SetMallocDispatchTable()

```
HiDebug_ErrorCode OH_HiDebug_SetMallocDispatchTable(struct HiDebug_MallocDispatch *dispatchTable)
```

**Description**

Sets the MallocDisaptch table of the system C library to replace the custom memory operation functions (such as **malloc**, **free**, **calloc**, **realloc**, **mmap**, and **munmap**). The MallocDisaptch table is a struct that encapsulates memory operation functions such as **malloc**, **calloc**, **realloc**, and **free** in the system C library. **HiDebug_MallocDispatch** is only a part of the **MallocDisaptch** struct.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [struct HiDebug_MallocDispatch](capi-hidebug-hidebug-mallocdispatch.md) *dispatchTable | Pointer to the [HiDebug_MallocDispatch](capi-hidebug-hidebug-mallocdispatch.md) struct that contains the custom memory operation functions.|

**Returns**

| Type| Description|
| -- | -- |
| [HiDebug_ErrorCode](capi-hidebug-type-h.md#hidebug_errorcode) | For details, see [HiDebug_ErrorCode](capi-hidebug-type-h.md#hidebug_errorcode).<br>         [HIDEBUG_SUCCESS](capi-hidebug-type-h.md#hidebug_errorcode): The custom memory operation function is set successfully.<br>         [HIDEBUG_INVALID_ARGUMENT](capi-hidebug-type-h.md#hidebug_errorcode): Invalid parameter.|

### OH_HiDebug_GetDefaultMallocDispatchTable()

```
HiDebug_MallocDispatch* OH_HiDebug_GetDefaultMallocDispatchTable(void)
```

**Description**

Obtains the default MallocDispatch table of the system C library. You can call [OH_HiDebug_RestoreMallocDispatchTable](capi-hidebug-h.md#oh_hidebug_restoremallocdispatchtable) to restore the table.

**Since**: 20

**Returns**

| Type| Description|
| -- | -- |
| HiDebug_MallocDispatch* | Pointer to the default [HiDebug_MallocDispatch](capi-hidebug-hidebug-mallocdispatch.md) struct of the current C library.|

### OH_HiDebug_RestoreMallocDispatchTable()

```
void OH_HiDebug_RestoreMallocDispatchTable(void)
```

**Description**

Restores the MallocDispatch table of the system C library.

**Since**: 20
