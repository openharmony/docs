# trace.h


## Overview

Defines APIs of the HiTraceMeter module for performance trace.

Example

Synchronous time slice trace event:

  
```
OH_HiTrace_StartTrace("hitraceTest");
OH_HiTrace_FinishTrace();
```

Output:

  
```
<...>-1668 (----—) [003] .... 135.059377: tracing_mark_write: B|1668|H:hitraceTest
<...>-1668 (----—) [003] .... 135.059415: tracing_mark_write: E|1668|
```

Asynchronous time slice trace event:

  
```
OH_HiTrace_StartAsyncTrace("hitraceTest", 123);
OH_HiTrace_FinishAsyncTrace("hitraceTest", 123);
```

Output:

  
```
<...>-2477 (----—) [001] .... 396.427165: tracing_mark_write: S|2477|H:hitraceTest 123
<...>-2477 (----—) [001] .... 396.427196: tracing_mark_write: F|2477|H:hitraceTest 123
```

Integer value trace event:

  
```
OH_HiTrace_CountTrace("hitraceTest", 500);
```

Output:

  
```
<...>-2638 (----—) [002] .... 458.904382: tracing_mark_write: C|2638|H:hitraceTest 500
```

**File to include**:

&lt;hitrace/trace.h&gt;

**Since**

10

**Related Modules**

[Hitrace](_hitrace.md)


## Summary

### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[HiTraceId](_hi_trace_id.md) | Defines the **HiTraceId** instance. | 

### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [HiTraceId_Valid](_hitrace.md#hitraceid_valid) [HiTraceId_Valid](_hitrace.md#hitraceid_valid) | Defines an enum for whether a **HiTraceId** instance is valid. | 
| typedef enum [HiTrace_Version](_hitrace.md#hitrace_version) [HiTrace_Version](_hitrace.md#hitrace_version) | Defines an enum for the version number of **HiTrace**. | 
| typedef enum [HiTrace_Flag](_hitrace.md#hitrace_flag) [HiTrace_Flag](_hitrace.md#hitrace_flag) | Defines an enum for the flag of **HiTrace**. | 
| typedef enum [HiTrace_Tracepoint_Type](_hitrace.md#hitrace_tracepoint_type) [HiTrace_Tracepoint_Type](_hitrace.md#hitrace_tracepoint_type) | Defines an enum for the tracepoint type of **HiTrace**. | 
| typedef enum [HiTrace_Communication_Mode](_hitrace.md#hitrace_communication_mode) [HiTrace_Communication_Mode](_hitrace.md#hitrace_communication_mode) |  | 
|  typedef struct [HiTraceId](_hi_trace_id.md)**HiTraceId** |  | 


### Enums

| Name| Description| 
| -------- | -------- |
| [HiTraceId_Valid](_hitrace.md#hitraceid_valid) { [HITRACE_ID_INVALID](_hitrace.md) = 0, [HITRACE_ID_VALID](_hitrace.md) = 1 } | Enumerates whether a **HiTraceId** instance is valid. | 
| [HiTrace_Version](_hitrace.md#hitrace_version) { [HITRACE_VER_1](_hitrace.md) = 0 } | Enumerates the version numbers of **HiTrace**. | 
| [HiTrace_Flag](_hitrace.md#hitrace_flag) {<br>[HITRACE_FLAG_DEFAULT](_hitrace.md) = 0, [HITRACE_FLAG_INCLUDE_ASYNC](_hitrace.md) = 1 &lt;&lt; 0, [HITRACE_FLAG_DONOT_CREATE_SPAN](_hitrace.md) = 1 &lt;&lt; 1, [HITRACE_FLAG_TP_INFO](_hitrace.md) = 1 &lt;&lt; 2,<br>[HITRACE_FLAG_NO_BE_INFO](_hitrace.md) = 1 &lt;&lt; 3, [HITRACE_FLAG_DONOT_ENABLE_LOG](_hitrace.md) = 1 &lt;&lt; 4, [HITRACE_FLAG_FAULT_TRIGGER](_hitrace.md) = 1 &lt;&lt; 5, [HITRACE_FLAG_D2D_TP_INFO](_hitrace.md) = 1 &lt;&lt; 6<br>} | Defines an enum for the flag of **HiTrace**. | 
| [HiTrace_Tracepoint_Type](_hitrace.md#hitrace_tracepoint_type) {<br>[HITRACE_TP_CS](_hitrace.md) = 0, [HITRACE_TP_CR](_hitrace.md) = 1, [HITRACE_TP_SS](_hitrace.md) = 2, [HITRACE_TP_SR](_hitrace.md) = 3,<br>[HITRACE_TP_GENERAL](_hitrace.md) = 4<br>} | Enumerates the tracepoint types of **HiTrace**. | 
| [HiTrace_Communication_Mode](_hitrace.md#hitrace_communication_mode) { [HITRACE_CM_DEFAULT](_hitrace.md) = 0, [HITRACE_CM_THREAD](_hitrace.md) = 1, [HITRACE_CM_PROCESS](_hitrace.md) = 2, [HITRACE_CM_DEVICE](_hitrace.md) = 3 } |  | 


### Functions

| Name| Description| 
| -------- | -------- |
| [HiTraceId](_hi_trace_id.md) [OH_HiTrace_BeginChain](_hitrace.md#oh_hitrace_beginchain) (const char \*name, int flags) | Starts tracing a process. | 
| void [OH_HiTrace_EndChain](_hitrace.md#oh_hitrace_endchain) () | Stops tracing the process and clears the trace ID of the calling thread if the given trace ID is valid. Otherwise, no operation is performed. | 
| [HiTraceId](_hi_trace_id.md) [OH_HiTrace_GetId](_hitrace.md#oh_hitrace_getid) () | Obtains the trace ID of the calling thread. If the calling thread does not have a trace ID, an invalid trace ID is returned. | 
| void [OH_HiTrace_SetId](_hitrace.md#oh_hitrace_setid) (const [HiTraceId](_hi_trace_id.md) \*id) | Sets the trace ID of the calling thread. If the ID is invalid, no operation is performed. | 
| void [OH_HiTrace_ClearId](_hitrace.md#oh_hitrace_clearid) (void) | Clears the trace ID of the calling thread and invalidates it. | 
| [HiTraceId](_hi_trace_id.md) [OH_HiTrace_CreateSpan](_hitrace.md#oh_hitrace_createspan) (void) | Creates a span ID based on the trace ID of the calling thread. | 
| void [OH_HiTrace_Tracepoint](_hitrace.md#oh_hitrace_tracepoint) ([HiTrace_Communication_Mode](_hitrace.md#hitrace_communication_mode) mode, [HiTrace_Tracepoint_Type](_hitrace.md#hitrace_tracepoint_type) type, const [HiTraceId](_hi_trace_id.md) \*id, const char \*fmt,...) | Prints HiTrace information, including the trace ID. | 
| void [OH_HiTrace_InitId](_hitrace.md#oh_hitrace_initid) ([HiTraceId](_hi_trace_id.md) \*id) | Initializes a **HiTraceId** instance. | 
| void [OH_HiTrace_IdFromBytes](_hitrace.md#oh_hitrace_idfrombytes) ([HiTraceId](_hi_trace_id.md) \*id, const uint8_t \*pIdArray, int len) | Creates a **HiTraceId** instance based on a byte array. | 
| bool [OH_HiTrace_IsIdValid](_hitrace.md#oh_hitrace_isidvalid) (const [HiTraceId](_hi_trace_id.md) \*id) | Checks whether a **HiTraceId** instance is valid. | 
| bool [OH_HiTrace_IsFlagEnabled](_hitrace.md#oh_hitrace_isflagenabled) (const [HiTraceId](_hi_trace_id.md) \*id, [HiTrace_Flag](_hitrace.md#hitrace_flag) flag) | Checks whether the specified trace flag is enabled in a **HiTraceId** instance. | 
| void [OH_HiTrace_EnableFlag](_hitrace.md#oh_hitrace_enableflag) (const [HiTraceId](_hi_trace_id.md) \*id, [HiTrace_Flag](_hitrace.md#hitrace_flag) flag) | Enables the specified trace flag in a **HiTraceId** instance. | 
| int [OH_HiTrace_GetFlags](_hitrace.md#oh_hitrace_getflags) (const [HiTraceId](_hi_trace_id.md) \*id) | Obtains the trace flags in a **HiTraceId** instance. | 
| void [OH_HiTrace_SetFlags](_hitrace.md#oh_hitrace_setflags) ([HiTraceId](_hi_trace_id.md) \*id, int flags) | Sets trace flags in a **HiTraceId** instance. | 
| uint64_t [OH_HiTrace_GetChainId](_hitrace.md#oh_hitrace_getchainid) (const [HiTraceId](_hi_trace_id.md) \*id) | Obtains a trace chain ID. | 
| void [OH_HiTrace_SetChainId](_hitrace.md#oh_hitrace_setchainid) ([HiTraceId](_hi_trace_id.md) \*id, uint64_t chainId) | Sets the trace chain ID in a **HiTraceId** instance. | 
| uint64_t [OH_HiTrace_GetSpanId](_hitrace.md#oh_hitrace_getspanid) (const [HiTraceId](_hi_trace_id.md) \*id) | Obtains the span ID in a **HiTraceId** instance. | 
| void [OH_HiTrace_SetSpanId](_hitrace.md#oh_hitrace_setspanid) ([HiTraceId](_hi_trace_id.md) \*id, uint64_t spanId) | Sets the span ID in a **HiTraceId** instance. | 
| uint64_t [OH_HiTrace_GetParentSpanId](_hitrace.md#oh_hitrace_getparentspanid) (const [HiTraceId](_hi_trace_id.md) \*id) | Obtains the parent span ID in a **HiTraceId** instance. | 
| void [OH_HiTrace_SetParentSpanId](_hitrace.md#oh_hitrace_setparentspanid) ([HiTraceId](_hi_trace_id.md) \*id, uint64_t parentSpanId) | Sets the **ParentSpanId** in a **HiTraceId** instance. | 
| int [OH_HiTrace_IdToBytes](_hitrace.md#oh_hitrace_idtobytes) (const [HiTraceId](_hi_trace_id.md) \*id, uint8_t \*pIdArray, int len) | Converts a **HiTraceId** instance into a byte array for caching or transfer. | 
| void [OH_HiTrace_StartTrace](_hitrace.md#oh_hitrace_starttrace) (const char \*name) | Marks the start of a synchronous trace. | 
| void [OH_HiTrace_FinishTrace](_hitrace.md#oh_hitrace_finishtrace) (void) | Marks the end of a synchronous trace. | 
| void [OH_HiTrace_StartAsyncTrace](_hitrace.md#oh_hitrace_startasynctrace) (const char \*name, int32_t taskId) | Marks the start of an asynchronous trace. | 
| void [OH_HiTrace_FinishAsyncTrace](_hitrace.md#oh_hitrace_finishasynctrace) (const char \*name, int32_t taskId) | Marks the end of an asynchronous trace. | 
| void [OH_HiTrace_CountTrace](_hitrace.md#oh_hitrace_counttrace) (const char \*name, int64_t count) | Traces the value change of an integer variable based on its name. | 
