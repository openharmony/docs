# trace.h


## 概述

HiTraceMeter模块打点接口定义，通过这些接口实现性能打点相关功能。

使用示例：

同步时间片跟踪事件：

  
```
OH_HiTrace_StartTrace("hitraceTest");
OH_HiTrace_FinishTrace();
```

结果输出：

  
```
<...>-1668 (----—) [003] .... 135.059377: tracing_mark_write: B|1668|H:hitraceTest
<...>-1668 (----—) [003] .... 135.059415: tracing_mark_write: E|1668|
```

异步时间片跟踪事件：

  
```
OH_HiTrace_StartAsyncTrace("hitraceTest", 123);
OH_HiTrace_FinishAsyncTrace("hitraceTest", 123);
```

结果输出：

  
```
<...>-2477 (----—) [001] .... 396.427165: tracing_mark_write: S|2477|H:hitraceTest 123
<...>-2477 (----—) [001] .... 396.427196: tracing_mark_write: F|2477|H:hitraceTest 123
```

整数值跟踪事件：

  
```
OH_HiTrace_CountTrace("hitraceTest", 500);
```

结果输出：

  
```
<...>-2638 (----—) [002] .... 458.904382: tracing_mark_write: C|2638|H:hitraceTest 500
```

**库：** libhitrace_ndk.z.so

**引用文件：**

&lt;hitrace/trace.h&gt;

**起始版本：**

10

**相关模块：**

[Hitrace](_hitrace.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[HiTraceId](_hi_trace_id.md) | HiTraceId定义。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [HiTraceId_Valid](_hitrace.md#hitraceid_valid) [HiTraceId_Valid](_hitrace.md#hitraceid_valid) | HiTraceId是否有效标志。  | 
| typedef enum [HiTrace_Version](_hitrace.md#hitrace_version) [HiTrace_Version](_hitrace.md#hitrace_version) | HiTrace版本号。  | 
| typedef enum [HiTrace_Flag](_hitrace.md#hitrace_flag) [HiTrace_Flag](_hitrace.md#hitrace_flag) | HiTrace标志位。  | 
| typedef enum [HiTrace_Tracepoint_Type](_hitrace.md#hitrace_tracepoint_type) [HiTrace_Tracepoint_Type](_hitrace.md#hitrace_tracepoint_type) | HiTrace打点类型。  | 
| typedef enum [HiTrace_Communication_Mode](_hitrace.md#hitrace_communication_mode) [HiTrace_Communication_Mode](_hitrace.md#hitrace_communication_mode) | HiTrace通信模式枚举。  | 
| typedef struct [HiTraceId](_hi_trace_id.md) [HiTraceId](_hi_trace_id.md) | 系统跟踪Id。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [HiTraceId_Valid](_hitrace.md#hitraceid_valid) { HITRACE_ID_INVALID = 0, HITRACE_ID_VALID = 1 } | HiTraceId是否有效标志。  | 
| [HiTrace_Version](_hitrace.md#hitrace_version) { HITRACE_VER_1 = 0 } | HiTrace版本号。  | 
| [HiTrace_Flag](_hitrace.md#hitrace_flag) {<br/>HITRACE_FLAG_DEFAULT = 0, HITRACE_FLAG_INCLUDE_ASYNC = 1 &lt;&lt; 0, HITRACE_FLAG_DONOT_CREATE_SPAN = 1 &lt;&lt; 1, HITRACE_FLAG_TP_INFO = 1 &lt;&lt; 2,<br/>HITRACE_FLAG_NO_BE_INFO = 1 &lt;&lt; 3, HITRACE_FLAG_DONOT_ENABLE_LOG = 1 &lt;&lt; 4, HITRACE_FLAG_FAULT_TRIGGER = 1 &lt;&lt; 5, HITRACE_FLAG_D2D_TP_INFO = 1 &lt;&lt; 6<br/>} | HiTrace标志位。  | 
| [HiTrace_Tracepoint_Type](_hitrace.md#hitrace_tracepoint_type) {<br/>HITRACE_TP_CS = 0, HITRACE_TP_CR = 1, HITRACE_TP_SS = 2, HITRACE_TP_SR = 3,<br/>HITRACE_TP_GENERAL = 4<br/>} | HiTrace打点类型。  | 
| [HiTrace_Communication_Mode](_hitrace.md#hitrace_communication_mode) { HITRACE_CM_DEFAULT = 0, HITRACE_CM_THREAD = 1, HITRACE_CM_PROCESS = 2, HITRACE_CM_DEVICE = 3 } | HiTrace通信模式枚举。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [HiTraceId](_hi_trace_id.md) [OH_HiTrace_BeginChain](_hitrace.md#oh_hitrace_beginchain) (const char \*name, int flags) | 开始跟踪进程实现。  | 
| void [OH_HiTrace_EndChain](_hitrace.md#oh_hitrace_endchain) () | 如果给定的跟踪ID有效，则停止进程跟踪并清除当前线程的跟踪ID，否则不执行任何操作。  | 
| [HiTraceId](_hi_trace_id.md) [OH_HiTrace_GetId](_hitrace.md#oh_hitrace_getid) () | 获取当前线程的跟踪ID，如果没有属于当前线程的跟踪ID，则返回一个无效的跟踪ID。  | 
| void [OH_HiTrace_SetId](_hitrace.md#oh_hitrace_setid) (const [HiTraceId](_hi_trace_id.md) \*id) | 将id设置为当前线程的跟踪id。如果ID无效，则不执行任何操作。  | 
| void [OH_HiTrace_ClearId](_hitrace.md#oh_hitrace_clearid) (void) | 清除当前线程的跟踪ID并将其设置为无效。  | 
| [HiTraceId](_hi_trace_id.md) [OH_HiTrace_CreateSpan](_hitrace.md#oh_hitrace_createspan) (void) | 根据当前线程的跟踪id创建一个新的span id。  | 
| void [OH_HiTrace_Tracepoint](_hitrace.md#oh_hitrace_tracepoint) ([HiTrace_Communication_Mode](_hitrace.md#hitrace_communication_mode) mode, [HiTrace_Tracepoint_Type](_hitrace.md#hitrace_tracepoint_type) type, const [HiTraceId](_hi_trace_id.md) \*id, const char \*fmt,...) | 打印hitrace信息，包括跟踪ID信息。  | 
| void [OH_HiTrace_InitId](_hitrace.md#oh_hitrace_initid) ([HiTraceId](_hi_trace_id.md) \*id) | 初始化HiTraceId结构体。  | 
| void [OH_HiTrace_IdFromBytes](_hitrace.md#oh_hitrace_idfrombytes) ([HiTraceId](_hi_trace_id.md) \*id, const uint8_t \*pIdArray, int len) | 根据字节数组创建跟踪HiTraceId结构体。  | 
| bool [OH_HiTrace_IsIdValid](_hitrace.md#oh_hitrace_isidvalid) (const [HiTraceId](_hi_trace_id.md) \*id) | 判断trace id是否有效。  | 
| bool [OH_HiTrace_IsFlagEnabled](_hitrace.md#oh_hitrace_isflagenabled) (const [HiTraceId](_hi_trace_id.md) \*id, [HiTrace_Flag](_hitrace.md#hitrace_flag) flag) | 判断跟踪id是否启用了跟踪标志。  | 
| void [OH_HiTrace_EnableFlag](_hitrace.md#oh_hitrace_enableflag) (const [HiTraceId](_hi_trace_id.md) \*id, [HiTrace_Flag](_hitrace.md#hitrace_flag) flag) | 启用跟踪ID的指定跟踪标志。  | 
| int [OH_HiTrace_GetFlags](_hitrace.md#oh_hitrace_getflags) (const [HiTraceId](_hi_trace_id.md) \*id) | 获取HiTraceId结构体中设置的标志位。  | 
| void [OH_HiTrace_SetFlags](_hitrace.md#oh_hitrace_setflags) ([HiTraceId](_hi_trace_id.md) \*id, int flags) | 设置跟踪标志位到HiTraceId结构体中。  | 
| uint64_t [OH_HiTrace_GetChainId](_hitrace.md#oh_hitrace_getchainid) (const [HiTraceId](_hi_trace_id.md) \*id) | 获取跟踪链ID。  | 
| void [OH_HiTrace_SetChainId](_hitrace.md#oh_hitrace_setchainid) ([HiTraceId](_hi_trace_id.md) \*id, uint64_t chainId) | 设置跟踪链ID到HiTraceId结构体中。  | 
| uint64_t [OH_HiTrace_GetSpanId](_hitrace.md#oh_hitrace_getspanid) (const [HiTraceId](_hi_trace_id.md) \*id) | 获取当前HiTraceId结构体中的分支ID。  | 
| void [OH_HiTrace_SetSpanId](_hitrace.md#oh_hitrace_setspanid) ([HiTraceId](_hi_trace_id.md) \*id, uint64_t spanId) | 设置分支ID到HiTraceId结构体中。  | 
| uint64_t [OH_HiTrace_GetParentSpanId](_hitrace.md#oh_hitrace_getparentspanid) (const [HiTraceId](_hi_trace_id.md) \*id) | 获取当前HiTraceId结构体中的父分支ID。  | 
| void [OH_HiTrace_SetParentSpanId](_hitrace.md#oh_hitrace_setparentspanid) ([HiTraceId](_hi_trace_id.md) \*id, uint64_t parentSpanId) | 设置HiTraceId结构的parentSpanId字符。  | 
| int [OH_HiTrace_IdToBytes](_hitrace.md#oh_hitrace_idtobytes) (const [HiTraceId](_hi_trace_id.md) \*id, uint8_t \*pIdArray, int len) | 将HiTraceId结构体转换为字节数组，用于缓存或者通信传递。  | 
| void [OH_HiTrace_StartTrace](_hitrace.md#oh_hitrace_starttrace) (const char \*name) | 标记一个同步跟踪耗时任务的开始。  | 
| void [OH_HiTrace_FinishTrace](_hitrace.md#oh_hitrace_finishtrace) (void) | 标记一个同步跟踪耗时任务的结束。  | 
| void [OH_HiTrace_StartAsyncTrace](_hitrace.md#oh_hitrace_startasynctrace) (const char \*name, int32_t taskId) | 标记一个异步跟踪耗时任务的开始。  | 
| void [OH_HiTrace_FinishAsyncTrace](_hitrace.md#oh_hitrace_finishasynctrace) (const char \*name, int32_t taskId) | 标记一个异步跟踪耗时任务的结束。  | 
| void [OH_HiTrace_CountTrace](_hitrace.md#oh_hitrace_counttrace) (const char \*name, int64_t count) | 用于跟踪给定整数变量名和整数值。  | 
