# trace.h

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--SE: @MontSaintMichel-->
<!--TSE: @gcw_KuLfPSbe-->

## Overview

Defines APIs of the HiTraceMeter module for performance trace. The vertical bar (|) is used as the separator in user-mode trace format. Therefore, the string parameters passed by the HiTraceMeter APIs must exclude this character to avoid trace parsing exceptions.<br> The maximum length of a user-mode trace is 512 characters. Excess characters will be truncated.<br>

**File to include**: <hitrace/trace.h>

**Library**: libhitrace_ndk.z.so

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 10

**Related module**: [HiTrace](capi-hitrace.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [HiTraceId](capi-hitrace-hitraceid.md) | HiTraceId | Defines a **HiTraceId** instance.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [HiTraceId_Valid](#hitraceid_valid) | HiTraceId_Valid | Enumerates whether a **HiTraceId** instance is valid.|
| [HiTrace_Version](#hitrace_version) | HiTrace_Version | Enumerates the HiTrace versions.|
| [HiTrace_Flag](#hitrace_flag) | HiTrace_Flag | Enumerates the HiTrace flags.|
| [HiTrace_Tracepoint_Type](#hitrace_tracepoint_type) | HiTrace_Tracepoint_Type | Enumerates the HiTrace tracepoint types.|
| [HiTrace_Communication_Mode](#hitrace_communication_mode) | HiTrace_Communication_Mode | Enumerates the HiTrace communication modes.|
| [HiTrace_Output_Level](#hitrace_output_level) | HiTrace_Output_Level | Enumerates the HiTrace output levels. The trace output level lower than the threshold does not take effect. The log version threshold is **HITRACE_LEVEL_INFO**, and the nolog version threshold is **HITRACE_LEVEL_COMMERCIAL**.|

### Functions

| Name| Description|
| -- | -- |
| [HiTraceId OH_HiTrace_BeginChain(const char *name, int flags)](#oh_hitrace_beginchain) | Starts tracing a process. This API starts tracing, creates a **HiTraceId** instance, and sets it to the TLS of the calling thread. This API works only when it is called for the first time.|
| [void OH_HiTrace_EndChain()](#oh_hitrace_endchain) | Stops tracing the process and clears the trace ID of the calling thread if the given trace ID is valid. Otherwise, no operation is performed.  |
| [HiTraceId OH_HiTrace_GetId()](#oh_hitrace_getid) | Obtains the trace ID of the calling thread. If the calling thread does not have a trace ID, an invalid trace ID is returned. Obtains the trace ID in TLS of the calling thread. |
| [void OH_HiTrace_SetId(const HiTraceId *id)](#oh_hitrace_setid) | Sets the trace ID of the calling thread. If the ID is invalid, no operation is performed. This API sets a **HiTraceId** instance to the TLS of the calling thread.|
| [void OH_HiTrace_ClearId(void)](#oh_hitrace_clearid) | Clears the trace ID of the calling thread and invalidates it. This API clears the **HiTraceId** instance in the TLS of the calling thread.|
| [HiTraceId OH_HiTrace_CreateSpan(void)](#oh_hitrace_createspan) | Creates a span ID based on the trace ID of the calling thread. This API generates a new span and corresponding **HiTraceId** instance based on the **HiTraceId** instance in the TLS of the calling thread.|
| [void OH_HiTrace_Tracepoint(HiTrace_Communication_Mode mode, HiTrace_Tracepoint_Type type, const HiTraceId *id, const char *fmt, ...)](#oh_hitrace_tracepoint) | Prints HiTrace information, including the trace ID. This API prints trace point information, including the communication mode, trace point type, timestamp, and span.|
| [void OH_HiTrace_InitId(HiTraceId *id)](#oh_hitrace_initid) | Initializes a **HiTraceId** instance.|
| [void OH_HiTrace_IdFromBytes(HiTraceId *id, const uint8_t *pIdArray, int len)](#oh_hitrace_idfrombytes) | Creates a **HiTraceId** instance based on a byte array.|
| [bool OH_HiTrace_IsIdValid(const HiTraceId *id)](#oh_hitrace_isidvalid) | Checks whether a **HiTraceId** instance is valid.  |
| [bool OH_HiTrace_IsFlagEnabled(const HiTraceId *id, HiTrace_Flag flag)](#oh_hitrace_isflagenabled) | Checks whether the specified trace flag is enabled in a **HiTraceId** instance.  |
| [void OH_HiTrace_EnableFlag(const HiTraceId *id, HiTrace_Flag flag)](#oh_hitrace_enableflag) | Enables the specified trace flag in a **HiTraceId** instance. Sets trace flags in a **HiTraceId** instance.|
| [int OH_HiTrace_GetFlags(const HiTraceId *id)](#oh_hitrace_getflags) | Obtains the trace flags in a **HiTraceId** instance.|
| [void OH_HiTrace_SetFlags(HiTraceId *id, int flags)](#oh_hitrace_setflags) | Sets trace flags in a **HiTraceId** instance.|
| [uint64_t OH_HiTrace_GetChainId(const HiTraceId *id)](#oh_hitrace_getchainid) | Obtains a trace chain ID.|
| [void OH_HiTrace_SetChainId(HiTraceId *id, uint64_t chainId)](#oh_hitrace_setchainid) | Sets the trace chain ID in a **HiTraceId** instance.|
| [uint64_t OH_HiTrace_GetSpanId(const HiTraceId *id)](#oh_hitrace_getspanid) | Obtains the span ID in a **HiTraceId** instance.|
| [void OH_HiTrace_SetSpanId(HiTraceId *id, uint64_t spanId)](#oh_hitrace_setspanid) | Sets the span ID in a **HiTraceId** instance.|
| [uint64_t OH_HiTrace_GetParentSpanId(const HiTraceId *id)](#oh_hitrace_getparentspanid) | Obtains the parent span ID in a **HiTraceId** instance.|
| [void OH_HiTrace_SetParentSpanId(HiTraceId *id, uint64_t parentSpanId)](#oh_hitrace_setparentspanid) | Sets the **ParentSpanId** in a **HiTraceId** instance.|
| [int OH_HiTrace_IdToBytes(const HiTraceId* id, uint8_t* pIdArray, int len)](#oh_hitrace_idtobytes) | Converts a **HiTraceId** instance into a byte array for caching or transfer.|
| [void OH_HiTrace_StartTrace(const char *name)](#oh_hitrace_starttrace) | Marks the start of a synchronous trace. This API is used with **OH_HiTrace_FinishTrace** in pairs.<br> The two APIs can be nested. The stack data structure is used for matching during trace parsing.<br> Since API version 19, you are advised to use the **OH_HiTrace_StartTraceEx** API to specify the trace output level.<br>|
| [void OH_HiTrace_FinishTrace(void)](#oh_hitrace_finishtrace) | Marks the end of a synchronous trace. This API must be used with **OH_HiTrace_StartTrace** in pairs. During trace parsing, the system matches it with the **OH_HiTrace_StartTrace** API recently invoked in the service process.<br> Since API version 19, you are advised to use the **OH_HiTrace_FinishTraceEx** API to specify the trace output level.<br>|
| [void OH_HiTrace_StartAsyncTrace(const char *name, int32_t taskId)](#oh_hitrace_startasynctrace) | Marks the start of an asynchronous trace. This API is used to start tracing before an asynchronous operation. The start and end of an asynchronous trace do not occur in sequence. Therefore, a unique task ID is required to identify them.<br> It must be used with **OH_HiTrace_FinishAsyncTrace** in pairs. The start and end identified by the same name and task ID constitute an asynchronous trace task.<br> If multiple trace tasks with the same name need to be performed at the same time or a trace task needs to be performed multiple times concurrently, different task IDs must be specified.<br> If the trace tasks with the same name are not performed at the same time, the same **taskId** can be used.<br> Since API version 19, you are advised to use the **OH_HiTrace_StartAsyncTraceEx** API to specify the trace output level and category.<br>|
| [void OH_HiTrace_FinishAsyncTrace(const char *name, int32_t taskId)](#oh_hitrace_finishasynctrace) | Marks the end of an asynchronous trace. This API is called in the callback function after an asynchronous trace is complete.<br> It is used with **OH_HiTrace_StartAsyncTrace** in pairs. Its name and task ID must be the same as those of **OH_HiTrace_StartAsyncTrace**.<br> Since API version 19, you are advised to use the **OH_HiTrace_FinishAsyncTraceEx** API to specify the trace output level.<br>|
| [void OH_HiTrace_CountTrace(const char *name, int64_t count)](#oh_hitrace_counttrace) | Traces the value change of an integer variable based on its name. This API can be executed for multiple times to trace the value change of a given integer variable at different time points.<br> Since API version 19, you are advised to use the **OH_HiTrace_CountTraceEx** API to specify the trace output level.<br>|
| [void OH_HiTrace_StartTraceEx(HiTrace_Output_Level level, const char *name, const char *customArgs)](#oh_hitrace_starttraceex) | Marks the start of a synchronous trace task with the trace output level specified. This API is used with **OH_HiTrace_FinishTraceEx** in pairs.<br> The two APIs can be nested. The stack data structure is used for matching during trace parsing.<br>|
| [void OH_HiTrace_FinishTraceEx(HiTrace_Output_Level level)](#oh_hitrace_finishtraceex) | Marks the end of a synchronous trace task with the trace output level specified. It must be used with **OH_HiTrace_StartTraceEx** in pairs. Its level must be the same as those of **OH_HiTrace_StartTraceEx**.<br> During trace data parsing, the system matches it with the **OH_HiTrace_StartTraceEx** API recently invoked in the service process.<br>|
| [void OH_HiTrace_StartAsyncTraceEx(HiTrace_Output_Level level, const char *name, int32_t taskId, const char *customCategory, const char *customArgs)](#oh_hitrace_startasynctraceex) | Marks the start of an asynchronous trace task with the trace output level specified. This API is used to start tracing before an asynchronous operation. The start and end of an asynchronous trace do not occur in sequence. Therefore, a unique task ID is required to identify them.<br> It is used with **OH_HiTrace_FinishAsyncTraceEx** in pairs. The start and end identified by the same name and task ID constitute an asynchronous trace task.<br> If multiple trace tasks with the same name need to be performed at the same time or a trace task needs to be performed multiple times concurrently, different task IDs must be specified.<br> If the trace tasks with the same name are not performed at the same time, the same **taskId** can be used.<br> Task IDs of different processes does not interfere with each other.<br>|
| [void OH_HiTrace_FinishAsyncTraceEx(HiTrace_Output_Level level, const char *name, int32_t taskId)](#oh_hitrace_finishasynctraceex) | Marks the end of an asynchronous trace task with the trace output level specified. This API is used to stop tracing after an asynchronous operation is complete, for example, in a callback function.<br> It is used with **OH_HiTrace_StartAsyncTraceEx** in pairs. Its level, name and task ID must be the same as those of **OH_HiTrace_StartAsyncTraceEx**.<br>|
| [void OH_HiTrace_CountTraceEx(HiTrace_Output_Level level, const char *name, int64_t count)](#oh_hitrace_counttraceex) | Marks an integer variable trace task with the trace output level specified.|
| [bool OH_HiTrace_IsTraceEnabled(void)](#oh_hitrace_istraceenabled) | Checks whether trace capture is enabled for an application. If not, HiTraceMeter performance tracing is invalid.|

## Enum Description

### HiTraceId_Valid

```
enum HiTraceId_Valid
```

**Description**

Enumerates whether a **HiTraceId** instance is valid.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12

| Enum Item| Description|
| -- | -- |
| HITRACE_ID_INVALID = 0 | Invalid **HiTraceId**.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|
| HITRACE_ID_VALID = 1 | Valid **HiTraceId**.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|

### HiTrace_Version

```
enum HiTrace_Version
```

**Description**

Enumerates the HiTrace versions.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12

| Enum Item| Description|
| -- | -- |
| HITRACE_VER_1 = 0 | Version 1.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|

### HiTrace_Flag

```
enum HiTrace_Flag
```

**Description**

Enumerates the HiTrace flags.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12

| Enum Item| Description|
| -- | -- |
| HITRACE_FLAG_DEFAULT = 0 | Default value.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|
| HITRACE_FLAG_INCLUDE_ASYNC = 1 << 0 | Both synchronous and asynchronous calls are traced. By default, only synchronous calls are traced.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|
| HITRACE_FLAG_DONOT_CREATE_SPAN = 1 << 1 | No spans are created. By default, spans are created.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|
| HITRACE_FLAG_TP_INFO = 1 << 2 | Trace points are automatically added to spans. By default, no trace point is added.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|
| HITRACE_FLAG_NO_BE_INFO = 1 << 3 | Information about the start and end of the trace task is not printed. By default, information about the start and end of the trace task is printed.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|
| HITRACE_FLAG_DONOT_ENABLE_LOG = 1 << 4 | The ID is not added to the log. By default, the ID is added to the log.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|
| HITRACE_FLAG_FAULT_TRIGGER = 1 << 5 | Tracing is triggered by faults.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|
| HITRACE_FLAG_D2D_TP_INFO = 1 << 6 | Only the device-to-device tracing point information in the span is output. By default, the device-to-device tracing point information is not output.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|

### HiTrace_Tracepoint_Type

```
enum HiTrace_Tracepoint_Type
```

**Description**

Enumerates the HiTrace tracepoint types.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12

| Enum Item| Description|
| -- | -- |
| HITRACE_TP_CS = 0 | CS trace point.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|
| HITRACE_TP_CR = 1 | CR trace point.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|
| HITRACE_TP_SS = 2 | SS trace point.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|
| HITRACE_TP_SR = 3 | SR trace point.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|
| HITRACE_TP_GENERAL = 4 | General trace point.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|

### HiTrace_Communication_Mode

```
enum HiTrace_Communication_Mode
```

**Description**

Enumerates the HiTrace communication modes.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12

| Enum Item| Description|
| -- | -- |
| HITRACE_CM_DEFAULT = 0 | Unspecified.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|
| HITRACE_CM_THREAD = 1 | Inter-thread communication.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|
| HITRACE_CM_PROCESS = 2 | Inter-process communication (IPC).<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|
| HITRACE_CM_DEVICE = 3 | Inter-device communication.<br>**Since**: 12<br>**System capability**: SystemCapability.HiviewDFX.HiTrace|

### HiTrace_Output_Level

```
enum HiTrace_Output_Level
```

**Description**

Enumerates the HiTrace output levels. The trace output level lower than the threshold does not take effect. The log version threshold is **HITRACE_LEVEL_INFO**, and the nolog version threshold is **HITRACE_LEVEL_COMMERCIAL**.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 19

| Enum Item| Description                                   |
| -- |---------------------------------------|
| HITRACE_LEVEL_DEBUG = 0 | Level used only for debugging, which has the lowest priority.<br>**Since**: 19               |
| HITRACE_LEVEL_INFO = 1 | Level for the log version.<br>**Since**: 19                        |
| HITRACE_LEVEL_CRITICAL = 2 | Level for the log version, which has a higher priority than **INFO**.<br>**Since**: 19|
| HITRACE_LEVEL_COMMERCIAL = 3 | Level for the nolog version, which has the highest priority.<br>**Since**: 19                |
| HITRACE_LEVEL_MAX = HITRACE_LEVEL_COMMERCIAL | The maximum output level.<br>**Since**: 19                            |


## Function Description

### OH_HiTrace_BeginChain()

```
HiTraceId OH_HiTrace_BeginChain(const char *name, int flags)
```

**Description**

Starts tracing a process. This API starts tracing, creates a **HiTraceId** instance, and sets it to the TLS of the calling thread. This API works only when it is called for the first time.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char *name | Name of the traced service.|
| int flags | Trace flag. For details, see [HiTrace_Flag](capi-trace-h.md#hitrace_flag).|

**Returns**

| Type| Description|
| -- | -- |
| [HiTraceId](capi-hitrace-hitraceid.md) | Generated HiTrace ID. For details, see [HiTraceId](capi-hitrace-hitraceid.md).|

### OH_HiTrace_EndChain()

```
void OH_HiTrace_EndChain()
```

**Description**

Stops tracing the process and clears the trace ID of the calling thread if the given trace ID is valid. Otherwise, no operation is performed.  

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12

### OH_HiTrace_GetId()

```
HiTraceId OH_HiTrace_GetId()
```

**Description**

Obtains the trace ID of the calling thread. If the calling thread does not have a trace ID, an invalid trace ID is returned. Obtains the trace ID in TLS of the calling thread. 

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| [HiTraceId](capi-hitrace-hitraceid.md) | [HiTraceId](capi-hitrace-hitraceid.md) of the calling thread. If the calling thread does not have a **HiTraceId**, an invalid **HiTraceId** is returned.|

### OH_HiTrace_SetId()

```
void OH_HiTrace_SetId(const HiTraceId *id)
```

**Description**

Sets the trace ID of the calling thread. If the ID is invalid, no operation is performed. This API sets a **HiTraceId** instance to the TLS of the calling thread.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const HiTraceId](capi-hitrace-hitraceid.md) *id | HiTrace ID of the calling thread. For details, see [HiTraceId](capi-hitrace-hitraceid.md).|

### OH_HiTrace_ClearId()

```
void OH_HiTrace_ClearId(void)
```

**Description**

Clears the trace ID of the calling thread and invalidates it. This API clears the **HiTraceId** instance in the TLS of the calling thread.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12

### OH_HiTrace_CreateSpan()

```
HiTraceId OH_HiTrace_CreateSpan(void)
```

**Description**

Creates a span ID based on the trace ID of the calling thread. This API generates a new span and corresponding **HiTraceId** instance based on the **HiTraceId** instance in the TLS of the calling thread.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12

**Returns**

| Type| Description|
| -- | -- |
| [HiTraceId](capi-hitrace-hitraceid.md) | Span ID. For details, see [HiTraceId](capi-hitrace-hitraceid.md). If the span ID cannot be created, the ID of the calling thread is traced.|

### OH_HiTrace_Tracepoint()

```
void OH_HiTrace_Tracepoint(HiTrace_Communication_Mode mode, HiTrace_Tracepoint_Type type, const HiTraceId *id, const char *fmt, ...)
```

**Description**

Prints HiTrace information, including the trace ID. This API prints trace point information, including the communication mode, trace point type, timestamp, and span.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [HiTrace_Communication_Mode](capi-trace-h.md#hitrace_communication_mode) mode | Trace communication mode. For details, see [HiTrace_Communication_Mode](capi-trace-h.md#hitrace_communication_mode).|
| [HiTrace_Tracepoint_Type](capi-trace-h.md#hitrace_tracepoint_type) type | Trace information type. For details, see [HiTrace_Tracepoint_Type](capi-trace-h.md#hitrace_tracepoint_type).|
| [const HiTraceId](capi-hitrace-hitraceid.md) *id | Trace ID to be printed. For details, see [HiTraceId](capi-hitrace-hitraceid.md).|
| const char *fmt | Custom information to print.|

### OH_HiTrace_InitId()

```
void OH_HiTrace_InitId(HiTraceId *id)
```

**Description**

Initializes a **HiTraceId** instance.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [HiTraceId](capi-hitrace-hitraceid.md) *id | [HiTraceId](capi-hitrace-hitraceid.md) to initialize.|

### OH_HiTrace_IdFromBytes()

```
void OH_HiTrace_IdFromBytes(HiTraceId *id, const uint8_t *pIdArray, int len)
```

**Description**

Creates a **HiTraceId** instance based on a byte array.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [HiTraceId](capi-hitrace-hitraceid.md) *id | [HiTraceId](capi-hitrace-hitraceid.md) to create.|
| const uint8_t *pIdArray | Byte array.|
| int len | Length of the byte array.|

### OH_HiTrace_IsIdValid()

```
bool OH_HiTrace_IsIdValid(const HiTraceId *id)
```

**Description**

Checks whether a **HiTraceId** instance is valid.  

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const HiTraceId](capi-hitrace-hitraceid.md) *id | Trace ID to check. For details, see [HiTraceId](capi-hitrace-hitraceid.md).|

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns **true** if the **HiTraceId** instance is valid; returns **false** otherwise.|

### OH_HiTrace_IsFlagEnabled()

```
bool OH_HiTrace_IsFlagEnabled(const HiTraceId *id, HiTrace_Flag flag)
```

**Description**

Checks whether the specified trace flag is enabled in a **HiTraceId** instance.  

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const HiTraceId](capi-hitrace-hitraceid.md) *id | Trace ID to check. For details, see [HiTraceId](capi-hitrace-hitraceid.md).|
| [HiTrace_Flag](capi-trace-h.md#hitrace_flag) flag | Flag to check. For details, see [HiTrace_Flag](capi-trace-h.md#hitrace_flag).|

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns **true** if the specified trace flag is enabled; returns **false** otherwise.|

### OH_HiTrace_EnableFlag()

```
void OH_HiTrace_EnableFlag(const HiTraceId *id, HiTrace_Flag flag)
```

**Description**

Enables the specified trace flag in a **HiTraceId** instance. Sets trace flags in a **HiTraceId** instance.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const HiTraceId](capi-hitrace-hitraceid.md) *id | Trace ID. For details, see [HiTraceId](capi-hitrace-hitraceid.md).|
| [HiTrace_Flag](capi-trace-h.md#hitrace_flag) flag | Trace flag to enable. For details, see [HiTrace_Flag](capi-trace-h.md#hitrace_flag).|

### OH_HiTrace_GetFlags()

```
int OH_HiTrace_GetFlags(const HiTraceId *id)
```

**Description**

Obtains the trace flags in a **HiTraceId** instance.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const HiTraceId](capi-hitrace-hitraceid.md) *id | **HiTraceId** instance. For details, see [HiTraceId](capi-hitrace-hitraceid.md).|

**Returns**

| Type| Description|
| -- | -- |
| int | Trace flags set in the specified **HiTraceId** instance.|

### OH_HiTrace_SetFlags()

```
void OH_HiTrace_SetFlags(HiTraceId *id, int flags)
```

**Description**

Sets trace flags in a **HiTraceId** instance.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [HiTraceId](capi-hitrace-hitraceid.md) *id | **HiTraceId** instance. For details, see [HiTraceId](capi-hitrace-hitraceid.md).|
| int flags | Trace flag to set. For details, see [HiTrace_Flag](capi-trace-h.md#hitrace_flag).|

### OH_HiTrace_GetChainId()

```
uint64_t OH_HiTrace_GetChainId(const HiTraceId *id)
```

**Description**

Obtains a trace chain ID.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const HiTraceId](capi-hitrace-hitraceid.md) *id | **HiTraceId** instance. For details, see [HiTraceId](capi-hitrace-hitraceid.md).|

**Returns**

| Type| Description|
| -- | -- |
| uint64_t | Returns the trace chain ID of the specified **HiTraceId** instance.|

### OH_HiTrace_SetChainId()

```
void OH_HiTrace_SetChainId(HiTraceId *id, uint64_t chainId)
```

**Description**

Sets the trace chain ID in a **HiTraceId** instance.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [HiTraceId](capi-hitrace-hitraceid.md) *id | **HiTraceId** instance. For details, see [HiTraceId](capi-hitrace-hitraceid.md).|
| uint64_t chainId | Trace chain ID to set.|

### OH_HiTrace_GetSpanId()

```
uint64_t OH_HiTrace_GetSpanId(const HiTraceId *id)
```

**Description**

Obtains the span ID in a **HiTraceId** instance.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const HiTraceId](capi-hitrace-hitraceid.md) *id | **HiTraceId** instance. For details, see [HiTraceId](capi-hitrace-hitraceid.md).|

**Returns**

| Type| Description|
| -- | -- |
| uint64_t | Returns the span ID in the specified **HiTraceId** instance.|

### OH_HiTrace_SetSpanId()

```
void OH_HiTrace_SetSpanId(HiTraceId *id, uint64_t spanId)
```

**Description**

Sets the span ID in a **HiTraceId** instance.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [HiTraceId](capi-hitrace-hitraceid.md) *id | **HiTraceId** instance.|
| uint64_t spanId | Span ID to set.|

### OH_HiTrace_GetParentSpanId()

```
uint64_t OH_HiTrace_GetParentSpanId(const HiTraceId *id)
```

**Description**

Obtains the parent span ID in a **HiTraceId** instance.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const HiTraceId](capi-hitrace-hitraceid.md) *id | **HiTraceId** instance. For details, see [HiTraceId](capi-hitrace-hitraceid.md).|

**Returns**

| Type| Description|
| -- | -- |
| uint64_t | Returns the parent span ID in the specified **HiTraceId** instance.|

### OH_HiTrace_SetParentSpanId()

```
void OH_HiTrace_SetParentSpanId(HiTraceId *id, uint64_t parentSpanId)
```

**Description**

Sets the **ParentSpanId** in a **HiTraceId** instance.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [HiTraceId](capi-hitrace-hitraceid.md) *id | **HiTraceId** instance. For details, see [HiTraceId](capi-hitrace-hitraceid.md).|
| uint64_t parentSpanId | Parent span ID to set.|

### OH_HiTrace_IdToBytes()

```
int OH_HiTrace_IdToBytes(const HiTraceId* id, uint8_t* pIdArray, int len)
```

**Description**

Converts a **HiTraceId** instance into a byte array for caching or transfer.

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [const HiTraceId](capi-hitrace-hitraceid.md)* id | **HiTraceId** to convert. For details, see [HiTraceId](capi-hitrace-hitraceid.md).|
| uint8_t* pIdArray | Byte array.|
| int len | Length of the byte array.|

**Returns**

| Type| Description|
| -- | -- |
| int | Returns the length of the byte array after conversion.|

### OH_HiTrace_StartTrace()

```
void OH_HiTrace_StartTrace(const char *name)
```

**Description**

Marks the start of a synchronous trace. This API is used with **OH_HiTrace_FinishTrace** in pairs.<br> The two APIs can be nested. The stack data structure is used for matching during trace parsing.<br> Since API version 19, you are advised to use the **OH_HiTrace_StartTraceEx** API to specify the trace output level.<br>

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const char *name | Name of a synchronous trace.|

### OH_HiTrace_FinishTrace()

```
void OH_HiTrace_FinishTrace(void)
```

**Description**

Marks the end of a synchronous trace. This API must be used with **OH_HiTrace_StartTrace** in pairs. During trace parsing, the system matches it with the **OH_HiTrace_StartTrace** API recently invoked in the service process.<br> Since API version 19, you are advised to use the **OH_HiTrace_FinishTraceEx** API to specify the trace output level.<br>

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 10

### OH_HiTrace_StartAsyncTrace()

```
void OH_HiTrace_StartAsyncTrace(const char *name, int32_t taskId)
```

**Description**

Marks the start of an asynchronous trace. This API is used to start tracing before an asynchronous operation. The start and end of an asynchronous trace do not occur in sequence. Therefore, a unique task ID is required to identify them.<br> It must be used with **OH_HiTrace_FinishAsyncTrace** in pairs. The start and end identified by the same name and task ID constitute an asynchronous trace task.<br> If multiple trace tasks with the same name need to be performed at the same time or a trace task needs to be performed multiple times concurrently, different task IDs must be specified.<br> If the trace tasks with the same name are not performed at the same time, the same **taskId** can be used.<br> Since API version 19, you are advised to use the **OH_HiTrace_StartAsyncTraceEx** API to specify the trace output level and category.<br>

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const char *name | Name of the asynchronous trace.|
| int32_t taskId | ID of the asynchronous trace. The start and end of an asynchronous trace task do not occur in sequence. Therefore, the start and end of an asynchronous trace need to be matched based on the task name and the unique task ID together.|

### OH_HiTrace_FinishAsyncTrace()

```
void OH_HiTrace_FinishAsyncTrace(const char *name, int32_t taskId)
```

**Description**

Marks the end of an asynchronous trace. This API is called in the callback function after an asynchronous trace is complete.<br> It is used with **OH_HiTrace_StartAsyncTrace** in pairs. Its name and task ID must be the same as those of **OH_HiTrace_StartAsyncTrace**.<br> Since API version 19, you are advised to use the **OH_HiTrace_FinishAsyncTraceEx** API to specify the trace output level.<br>

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const char *name | Name of the asynchronous trace.|
| int32_t taskId | ID of the asynchronous trace. The start and end of an asynchronous trace task do not occur in sequence. Therefore, the start and end of an asynchronous trace need to be matched based on the task name and the unique task ID together.|

### OH_HiTrace_CountTrace()

```
void OH_HiTrace_CountTrace(const char *name, int64_t count)
```

**Description**

Traces the value change of an integer variable based on its name. This API can be executed for multiple times to trace the value change of a given integer variable at different time points.<br> Since API version 19, you are advised to use the **OH_HiTrace_CountTraceEx** API to specify the trace output level.<br>

**System capability**: SystemCapability.HiviewDFX.HiTrace

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const char *name | Name of the integer variable. It does not need to be the same as the real variable name.|
| int64_t count | Integer value.|

### OH_HiTrace_StartTraceEx()

```
void OH_HiTrace_StartTraceEx(HiTrace_Output_Level level, const char *name, const char *customArgs)
```

**Description**

Marks the start of a synchronous trace task with the trace output level specified. This API is used with **OH_HiTrace_FinishTraceEx** in pairs.<br> The two APIs can be nested. The stack data structure is used for matching during trace parsing.<br>

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [HiTrace_Output_Level](capi-trace-h.md#hitrace_output_level) level | Trace output level.|
| const char *name | Name of a synchronous trace.|
| const char *customArgs | Key-value pair. Use commas (,) to separate multiple key-value pairs, for example, "key1=value1,key2=value2".|

### OH_HiTrace_FinishTraceEx()

```
void OH_HiTrace_FinishTraceEx(HiTrace_Output_Level level)
```

**Description**

Marks the end of a synchronous trace task with the trace output level specified. It must be used with **OH_HiTrace_StartTraceEx** in pairs. Its level must be the same as those of **OH_HiTrace_StartTraceEx**.<br> During trace data parsing, the system matches it with the **OH_HiTrace_StartTraceEx** API recently invoked in the service process.<br>

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [HiTrace_Output_Level](capi-trace-h.md#hitrace_output_level) level | Trace output level.|

### OH_HiTrace_StartAsyncTraceEx()

```
void OH_HiTrace_StartAsyncTraceEx(HiTrace_Output_Level level, const char *name, int32_t taskId, const char *customCategory, const char *customArgs)
```

**Description**

Marks the start of an asynchronous trace task with the trace output level specified. This API is used to start tracing before an asynchronous operation. The start and end of an asynchronous trace do not occur in sequence. Therefore, a unique task ID is required to identify them.<br> It is used with **OH_HiTrace_FinishAsyncTraceEx** in pairs. The start and end identified by the same name and task ID constitute an asynchronous trace task.<br> If multiple trace tasks with the same name need to be performed at the same time or a trace task needs to be performed multiple times concurrently, different task IDs must be specified.<br> If the trace tasks with the same name are not performed at the same time, the same **taskId** can be used.<br> Task IDs of different processes does not interfere with each other.<br>

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [HiTrace_Output_Level](capi-trace-h.md#hitrace_output_level) level | Trace output level.|
| const char *name | Name of the asynchronous trace.|
| int32_t taskId | ID of the asynchronous trace.|
| const char *customCategory | Custom category name, which is used to collect asynchronous trace data of the same type.|
| const char *customArgs | Key-value pair. Use commas (,) to separate multiple key-value pairs, for example, "key1=value1,key2=value2".|

### OH_HiTrace_FinishAsyncTraceEx()

```
void OH_HiTrace_FinishAsyncTraceEx(HiTrace_Output_Level level, const char *name, int32_t taskId)
```

**Description**

Marks the end of an asynchronous trace task with the trace output level specified. This API is used to stop tracing after an asynchronous operation is complete, for example, in a callback function.<br> It is used with **OH_HiTrace_StartAsyncTraceEx** in pairs. Its level, name and task ID must be the same as those of **OH_HiTrace_StartAsyncTraceEx**.<br>

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [HiTrace_Output_Level](capi-trace-h.md#hitrace_output_level) level | Trace output level.|
| const char *name | Name of the asynchronous trace.|
| int32_t taskId | ID of the asynchronous trace.|

### OH_HiTrace_CountTraceEx()

```
void OH_HiTrace_CountTraceEx(HiTrace_Output_Level level, const char *name, int64_t count)
```

**Description**

Marks an integer variable trace task with the trace output level specified.

**Since**: 19


**Parameters**

| Name| Description|
| -- | -- |
| [HiTrace_Output_Level](capi-trace-h.md#hitrace_output_level) level | Trace output level.|
| const char *name | Name of the integer variable. It does not need to be the same as the actual variable name.|
| int64_t count | Integer value.|

### OH_HiTrace_IsTraceEnabled()

```
bool OH_HiTrace_IsTraceEnabled(void)
```

**Description**

Checks whether trace capture is enabled for an application. If not, HiTraceMeter performance tracing is invalid.

**Since**: 19

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns **true** if the application trace capture is enabled and the HiTraceMeter performance tracing takes effect;<br> returns **false** otherwise.|
