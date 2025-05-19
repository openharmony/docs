# Hitrace


## 概述

hiTraceMeter为开发者提供系统性能打点接口。

开发者通过在自己的业务逻辑中的关键代码位置调用HiTraceMeter系统跟踪提供的API接口，能够有效进行关键执行流程耗时度量和问题定位。

hitraceChain为开发者提供跨线程、跨进程的分布式跟踪能力。

HiTraceChain支持在业务执行流程中，生成和传递唯一跟踪标识，在业务流程中输出的各类调试信息中（包括应用事件、系统事件、日志等）携带该跟踪标识。 在调试、问题定位过程中，开发人员可以通过该唯一跟踪标识将本次业务流程端到端的各类信息快速关联起来。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [trace.h](trace_8h.md) | HiTraceMeter模块打点接口定义，通过这些接口实现性能打点相关功能。  | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[HiTraceId](_hi_trace_id.md) | HiTraceId定义。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [HiTraceId_Valid](#hitraceid_valid) [HiTraceId_Valid](#hitraceid_valid) | HiTraceId是否有效标志。  | 
| typedef enum [HiTrace_Version](#hitrace_version) [HiTrace_Version](#hitrace_version) | HiTrace版本号。  | 
| typedef enum [HiTrace_Flag](#hitrace_flag) [HiTrace_Flag](#hitrace_flag) | HiTrace标志位。  | 
| typedef enum [HiTrace_Tracepoint_Type](#hitrace_tracepoint_type) [HiTrace_Tracepoint_Type](#hitrace_tracepoint_type) | HiTrace打点类型。  | 
| typedef enum [HiTrace_Communication_Mode](#hitrace_communication_mode) [HiTrace_Communication_Mode](#hitrace_communication_mode) | HiTrace通信模式枚举。  | 
| typedef enum [HiTrace_Output_Level](#hitrace_output_level) [HiTrace_Output_Level](#hitrace_output_level) | HiTrace输出级别。  | 
|  typedef struct [HiTraceId](_hi_trace_id.md)**HiTraceId** |  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [HiTraceId_Valid](#hitraceid_valid) { HITRACE_ID_INVALID = 0, HITRACE_ID_VALID = 1 } | HiTraceId是否有效标志。  | 
| [HiTrace_Version](#hitrace_version) { HITRACE_VER_1 = 0 } | HiTrace版本号。  | 
| [HiTrace_Flag](#hitrace_flag) {<br/>HITRACE_FLAG_DEFAULT = 0, HITRACE_FLAG_INCLUDE_ASYNC = 1 &lt;&lt; 0, HITRACE_FLAG_DONOT_CREATE_SPAN = 1 &lt;&lt; 1, HITRACE_FLAG_TP_INFO = 1 &lt;&lt; 2,<br/>HITRACE_FLAG_NO_BE_INFO = 1 &lt;&lt; 3, HITRACE_FLAG_DONOT_ENABLE_LOG = 1 &lt;&lt; 4, HITRACE_FLAG_FAULT_TRIGGER = 1 &lt;&lt; 5, HITRACE_FLAG_D2D_TP_INFO = 1 &lt;&lt; 6<br/>} | HiTrace标志位。  | 
| [HiTrace_Tracepoint_Type](#hitrace_tracepoint_type) {<br/>HITRACE_TP_CS = 0, HITRACE_TP_CR = 1, HITRACE_TP_SS = 2, HITRACE_TP_SR = 3,<br/>HITRACE_TP_GENERAL = 4<br/>} | HiTrace打点类型。  | 
| [HiTrace_Communication_Mode](#hitrace_communication_mode) { HITRACE_CM_DEFAULT = 0, HITRACE_CM_THREAD = 1, HITRACE_CM_PROCESS = 2, HITRACE_CM_DEVICE = 3 } | HiTrace通信模式枚举。  | 
| [HiTrace_Output_Level](#hitrace_output_level) {<br/>HITRACE_LEVEL_DEBUG = 0, HITRACE_LEVEL_INFO = 1, HITRACE_LEVEL_CRITICAL = 2, HITRACE_LEVEL_COMMERCIAL = 3,<br/>HITRACE_LEVEL_MAX = HITRACE_LEVEL_COMMERCIAL<br/>} | HiTrace输出级别。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [HiTraceId](_hi_trace_id.md) [OH_HiTrace_BeginChain](#oh_hitrace_beginchain) (const char \*name, int flags) | 开始跟踪进程实现。  | 
| void [OH_HiTrace_EndChain](#oh_hitrace_endchain) () | 如果给定的跟踪ID有效，则停止进程跟踪并清除当前线程的跟踪ID，否则不执行任何操作。  | 
| [HiTraceId](_hi_trace_id.md) [OH_HiTrace_GetId](#oh_hitrace_getid) () | 获取当前线程的跟踪ID，如果没有属于当前线程的跟踪ID，则返回一个无效的跟踪ID。  | 
| void [OH_HiTrace_SetId](#oh_hitrace_setid) (const [HiTraceId](_hi_trace_id.md) \*id) | 将id设置为当前线程的跟踪id。如果ID无效，则不执行任何操作。  | 
| void [OH_HiTrace_ClearId](#oh_hitrace_clearid) (void) | 清除当前线程的跟踪ID并将其设置为无效。  | 
| [HiTraceId](_hi_trace_id.md) [OH_HiTrace_CreateSpan](#oh_hitrace_createspan) (void) | 根据当前线程的跟踪id创建一个新的span id。  | 
| void [OH_HiTrace_Tracepoint](#oh_hitrace_tracepoint) ([HiTrace_Communication_Mode](#hitrace_communication_mode) mode, [HiTrace_Tracepoint_Type](#hitrace_tracepoint_type) type, const [HiTraceId](_hi_trace_id.md) \*id, const char \*fmt,...) | 打印hitrace信息，包括跟踪ID信息。  | 
| void [OH_HiTrace_InitId](#oh_hitrace_initid) ([HiTraceId](_hi_trace_id.md) \*id) | 初始化HiTraceId结构体。  | 
| void [OH_HiTrace_IdFromBytes](#oh_hitrace_idfrombytes) ([HiTraceId](_hi_trace_id.md) \*id, const uint8_t \*pIdArray, int len) | 根据字节数组创建跟踪HiTraceId结构体。  | 
| bool [OH_HiTrace_IsIdValid](#oh_hitrace_isidvalid) (const [HiTraceId](_hi_trace_id.md) \*id) | 判断trace id是否有效。  | 
| bool [OH_HiTrace_IsFlagEnabled](#oh_hitrace_isflagenabled) (const [HiTraceId](_hi_trace_id.md) \*id, [HiTrace_Flag](#hitrace_flag) flag) | 判断跟踪id是否启用了跟踪标志。  | 
| void [OH_HiTrace_EnableFlag](#oh_hitrace_enableflag) (const [HiTraceId](_hi_trace_id.md) \*id, [HiTrace_Flag](#hitrace_flag) flag) | 启用跟踪ID的指定跟踪标志。  | 
| int [OH_HiTrace_GetFlags](#oh_hitrace_getflags) (const [HiTraceId](_hi_trace_id.md) \*id) | 获取HiTraceId结构体中设置的标志位。  | 
| void [OH_HiTrace_SetFlags](#oh_hitrace_setflags) ([HiTraceId](_hi_trace_id.md) \*id, int flags) | 设置跟踪标志位到HiTraceId结构体中。  | 
| uint64_t [OH_HiTrace_GetChainId](#oh_hitrace_getchainid) (const [HiTraceId](_hi_trace_id.md) \*id) | 获取跟踪链ID。  | 
| void [OH_HiTrace_SetChainId](#oh_hitrace_setchainid) ([HiTraceId](_hi_trace_id.md) \*id, uint64_t chainId) | 设置跟踪链ID到HiTraceId结构体中。  | 
| uint64_t [OH_HiTrace_GetSpanId](#oh_hitrace_getspanid) (const [HiTraceId](_hi_trace_id.md) \*id) | 获取当前HiTraceId结构体中的分支ID。  | 
| void [OH_HiTrace_SetSpanId](#oh_hitrace_setspanid) ([HiTraceId](_hi_trace_id.md) \*id, uint64_t spanId) | 设置分支ID到HiTraceId结构体中。  | 
| uint64_t [OH_HiTrace_GetParentSpanId](#oh_hitrace_getparentspanid) (const [HiTraceId](_hi_trace_id.md) \*id) | 获取当前HiTraceId结构体中的父分支ID。  | 
| void [OH_HiTrace_SetParentSpanId](#oh_hitrace_setparentspanid) ([HiTraceId](_hi_trace_id.md) \*id, uint64_t parentSpanId) | 设置HiTraceId结构的parentSpanId字符。  | 
| int [OH_HiTrace_IdToBytes](#oh_hitrace_idtobytes) (const [HiTraceId](_hi_trace_id.md) \*id, uint8_t \*pIdArray, int len) | 将HiTraceId结构体转换为字节数组，用于缓存或者通信传递。  | 
| void [OH_HiTrace_StartTrace](#oh_hitrace_starttrace) (const char \*name) | 标记一个同步跟踪耗时任务的开始。  | 
| void [OH_HiTrace_FinishTrace](#oh_hitrace_finishtrace) (void) | 标记一个同步跟踪耗时任务的结束。  | 
| void [OH_HiTrace_StartAsyncTrace](#oh_hitrace_startasynctrace) (const char \*name, int32_t taskId) | 标记一个异步跟踪耗时任务的开始。  | 
| void [OH_HiTrace_FinishAsyncTrace](#oh_hitrace_finishasynctrace) (const char \*name, int32_t taskId) | 标记一个异步跟踪耗时任务的结束。  | 
| void [OH_HiTrace_CountTrace](#oh_hitrace_counttrace) (const char \*name, int64_t count) | 用于跟踪给定整数变量名和整数值。  | 
| void [OH_HiTrace_StartTraceEx](#oh_hitrace_starttraceex) ([HiTrace_Output_Level](#hitrace_output_level) level, const char \*name, const char \*customArgs) | 标记一个同步跟踪耗时任务的开始，分级控制跟踪输出。  | 
| void [OH_HiTrace_FinishTraceEx](#oh_hitrace_finishtraceex) ([HiTrace_Output_Level](#hitrace_output_level) level) | 标记一个同步跟踪耗时任务的结束，分级控制跟踪输出。  | 
| void [OH_HiTrace_StartAsyncTraceEx](#oh_hitrace_startasynctraceex) ([HiTrace_Output_Level](#hitrace_output_level) level, const char \*name, int32_t taskId, const char \*customCategory, const char \*customArgs) | 标记一个异步跟踪耗时任务的开始，分级控制跟踪输出。  | 
| void [OH_HiTrace_FinishAsyncTraceEx](#oh_hitrace_finishasynctraceex) ([HiTrace_Output_Level](#hitrace_output_level) level, const char \*name, int32_t taskId) | 标记一个异步跟踪耗时任务的结束，分级控制跟踪输出。  | 
| void [OH_HiTrace_CountTraceEx](#oh_hitrace_counttraceex) ([HiTrace_Output_Level](#hitrace_output_level) level, const char \*name, int64_t count) | 标记一个跟踪的整数变量，分级控制跟踪输出。  | 
| bool [OH_HiTrace_IsTraceEnabled](#oh_hitrace_istraceenabled) (void) | 判断当前是否开启应用trace捕获。应用trace捕获未开启时，HiTraceMeter性能跟踪打点无效。  | 


## 类型定义说明


### HiTrace_Communication_Mode

```
typedef enum HiTrace_Communication_ModeHiTrace_Communication_Mode
```
**描述**
HiTrace通信模式枚举。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12


### HiTrace_Flag

```
typedef enum HiTrace_FlagHiTrace_Flag
```
**描述**
HiTrace标志位。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12


### HiTrace_Output_Level

```
typedef enum HiTrace_Output_LevelHiTrace_Output_Level
```
**描述**
HiTrace输出级别。

低于系统跟踪输出级别阈值的打点将不会生效。log版本阈值为HITRACE_LEVEL_INFO；nolog版本阈值为HITRACE_LEVEL_COMMERCIAL。



**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 19


### HiTrace_Tracepoint_Type

```
typedef enum HiTrace_Tracepoint_Type HiTrace_Tracepoint_Type
```
**描述**
HiTrace打点类型。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12


### HiTrace_Version

```
typedef enum HiTrace_Version HiTrace_Version
```
**描述**
HiTrace版本号。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12


### HiTraceId_Valid

```
typedef enum HiTraceId_Valid HiTraceId_Valid
```
**描述**
HiTraceId是否有效标志。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12


## 枚举类型说明


### HiTrace_Communication_Mode

```
enum HiTrace_Communication_Mode
```
**描述**
HiTrace通信模式枚举。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| HITRACE_CM_DEFAULT | 未指明。 | 
| HITRACE_CM_THREAD | 线程间通信。 | 
| HITRACE_CM_PROCESS | 进程间通信。 | 
| HITRACE_CM_DEVICE | 设备间通信。 | 


### HiTrace_Flag

```
enum HiTrace_Flag
```
**描述**
HiTrace标志位。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| HITRACE_FLAG_DEFAULT | 默认值。 | 
| HITRACE_FLAG_INCLUDE_ASYNC | 跟踪同步和异步调用，默认仅跟踪同步调用。 | 
| HITRACE_FLAG_DONOT_CREATE_SPAN | 不创建span，默认创建span。 | 
| HITRACE_FLAG_TP_INFO | 在span中输出跟踪点信息，默认不输出跟踪点信息。 | 
| HITRACE_FLAG_NO_BE_INFO | 不输出开始和结束信息，默认输出开始和结束信息。 | 
| HITRACE_FLAG_DONOT_ENABLE_LOG | 不添加id到日志中，默认添加id到日志中。 | 
| HITRACE_FLAG_FAULT_TRIGGER | 跟踪是由故障触发的。 | 
| HITRACE_FLAG_D2D_TP_INFO | 仅输出span中的设备到设备跟踪点信息，默认不输出设备到设备跟踪点信息。 | 


### HiTrace_Output_Level

```
enum HiTrace_Output_Level
```
**描述**
HiTrace输出级别。

低于系统跟踪输出级别阈值的打点将不会生效。log版本阈值为HITRACE_LEVEL_INFO；nolog版本阈值为HITRACE_LEVEL_COMMERCIAL。



**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 19

| 枚举值 | 描述 | 
| -------- | -------- |
| HITRACE_LEVEL_DEBUG  | 仅用于调试的输出级别，优先级最低。 | 
| HITRACE_LEVEL_INFO  | 用于log版本的输出级别。 | 
| HITRACE_LEVEL_CRITICAL  | 用于log版本的输出级别，优先级高于HITRACE_LEVEL_INFO。 | 
| HITRACE_LEVEL_COMMERCIAL  | 用于nolog版本的输出级别，优先级最高。 | 
| HITRACE_LEVEL_MAX  | 输出级别范围限制。 | 


### HiTrace_Tracepoint_Type

```
enum HiTrace_Tracepoint_Type
```
**描述**
HiTrace打点类型。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| HITRACE_TP_CS  | 客户端发送。 | 
| HITRACE_TP_CR  | 客户端接收。 | 
| HITRACE_TP_SS  | 服务端发送。 | 
| HITRACE_TP_SR  | 服务端接收。 | 
| HITRACE_TP_GENERAL  | 整体信息。 | 


### HiTrace_Version

```
enum HiTrace_Version
```
**描述**
HiTrace版本号。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| HITRACE_VER_1  | 版本1。 | 


### HiTraceId_Valid

```
enum HiTraceId_Valid
```
**描述**
HiTraceId是否有效标志。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| HITRACE_ID_INVALID  | 无效HiTraceId。 | 
| HITRACE_ID_VALID  | 有效HiTraceId。 | 


## 函数说明


### OH_HiTrace_BeginChain()

```
HiTraceId OH_HiTrace_BeginChain (const char * name, int flags )
```
**描述**
开始跟踪进程实现。

启动跟踪；生成HiTraceId结构体并设置到当前线程TLS中。第一次调用有效，否则无效。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 跟踪业务名。  | 
| flags | 跟踪功能标志，见[HiTrace_Flag](#hitrace_flag)。  | 

**返回：**

生成的HitraceId，见[HiTraceId](_hi_trace_id.md)。


### OH_HiTrace_ClearId()

```
void OH_HiTrace_ClearId (void )
```
**描述**
清除当前线程的跟踪ID并将其设置为无效。

清除当前线程TLS中的HiTraceId结构体。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12


### OH_HiTrace_CountTrace()

```
void OH_HiTrace_CountTrace (const char * name, int64_t count )
```
**描述**
用于跟踪给定整数变量名和整数值。

多次执行该接口可以跟踪给定整数变量在不同时刻的数值变化。

从API version 19开始，建议使用OH_HiTrace_CountTraceEx接口，以便分级控制跟踪输出。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 整数变量跟踪的名字，不必与真实变量名相同。  | 
| count | 整数值。 | 


### OH_HiTrace_CountTraceEx()

```
void OH_HiTrace_CountTraceEx (HiTrace_Output_Level level, const char * name, int64_t count )
```
**描述**
标记一个跟踪的整数变量，分级控制跟踪输出。

**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| level | 跟踪输出优先级。  | 
| name | 整数变量的名称，不必与实际变量名相同。  | 
| count | 整数值。 | 


### OH_HiTrace_CreateSpan()

```
HiTraceId OH_HiTrace_CreateSpan (void )
```
**描述**
根据当前线程的跟踪id创建一个新的span id。

根据当前线程TLS中的HiTraceId结构体，生成新的子分支以及对应的新HiTraceI结构体。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**返回：**

有效的跨度跟踪ID，见[HiTraceId](_hi_trace_id.md)。否则，如果不允许创建跨度，则跟踪当前线程的ID。


### OH_HiTrace_EnableFlag()

```
void OH_HiTrace_EnableFlag (const HiTraceId * id, HiTrace_Flag flag )
```
**描述**
启用跟踪ID的指定跟踪标志。

设置某跟踪标志位到HiTraceId结构体中。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| id | 需要启用标志的跟踪ID，见[HiTraceId](_hi_trace_id.md)。  | 
| flag | 跟踪ID中需要启用的指定跟踪标志，见[HiTrace_Flag](#hitrace_flag)。 | 


### OH_HiTrace_EndChain()

```
void OH_HiTrace_EndChain ()
```
**描述**
如果给定的跟踪ID有效，则停止进程跟踪并清除当前线程的跟踪ID，否则不执行任何操作。

停止跟踪；清除当前线程TLS中HiTraceId内容。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12


### OH_HiTrace_FinishAsyncTrace()

```
void OH_HiTrace_FinishAsyncTrace (const char * name, int32_t taskId )
```
**描述**
标记一个异步跟踪耗时任务的结束。

在异步操作完成后如回调函数中调用，进行结束打点。

和OH_HiTrace_StartAsyncTrace配对使用，参数name和taskId必须与异步跟踪的开始打点接口的对应参数值保持一致。

从API version 19开始，建议使用OH_HiTrace_FinishAsyncTraceEx接口，以便分级控制跟踪输出。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 异步跟踪的名字。  | 
| taskId | 异步跟踪的ID。异步跟踪开始和结束由于不是顺序发生的，所以需要通过name和每次执行唯一的taskId进行开始和结束的匹配。 | 


### OH_HiTrace_FinishAsyncTraceEx()

```
void OH_HiTrace_FinishAsyncTraceEx (HiTrace_Output_Level level, const char * name, int32_t taskId )
```
**描述**
标记一个异步跟踪耗时任务的结束，分级控制跟踪输出。

用于在异步操作完成后进行结束打点，例如在回调函数中调用。

和OH_HiTrace_StartAsyncTraceEx配对使用，参数level、name和taskId必须与异步跟踪开始打点接口的对应参数值保持一致。



**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| level | 跟踪输出优先级。  | 
| name | 异步跟踪的名字。  | 
| taskId | 异步跟踪的ID。 | 


### OH_HiTrace_FinishTrace()

```
void OH_HiTrace_FinishTrace (void )
```
**描述**
标记一个同步跟踪耗时任务的结束。

必须和OH_HiTrace_StartTrace配对使用。跟踪解析时，和其前执行流程中最近的OH_HiTrace_StartTrace进行匹配。

从API version 19开始，建议使用OH_HiTrace_FinishTraceEx接口，以便分级控制跟踪输出。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 10


### OH_HiTrace_FinishTraceEx()

```
void OH_HiTrace_FinishTraceEx (HiTrace_Output_Level level)
```
**描述**
标记一个同步跟踪耗时任务的结束，分级控制跟踪输出。

必须和OH_HiTrace_StartTraceEx配对使用，参数level必须与同步跟踪的开始打点接口OH_HiTrace_StartTraceEx的对应参数值一致。

跟踪数据解析时，和其前执行流程中最近的OH_HiTrace_StartTraceEx进行匹配。



**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| level | 跟踪输出优先级。 | 


### OH_HiTrace_GetChainId()

```
uint64_t OH_HiTrace_GetChainId (const HiTraceId * id)
```
**描述**
获取跟踪链ID。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| id | 需要获取跟踪链ID的HiTraceId结构体，见[HiTraceId](_hi_trace_id.md)。 | 

**返回：**

HiTraceId结构体中设置的跟踪链ID。


### OH_HiTrace_GetFlags()

```
int OH_HiTrace_GetFlags (const HiTraceId * id)
```
**描述**
获取HiTraceId结构体中设置的标志位。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| id | 需要获取标志位的HiTraceId结构体，见[HiTraceId](_hi_trace_id.md)。 | 

**返回：**

HiTraceId结构体中设置的标志位。


### OH_HiTrace_GetId()

```
HiTraceId OH_HiTrace_GetId ()
```
**描述**
获取当前线程的跟踪ID，如果没有属于当前线程的跟踪ID，则返回一个无效的跟踪ID。

从当前线程TLS中获取跟踪标识。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**返回：**

当前线程的[HiTraceId](_hi_trace_id.md)。如果调用线程没有HiTraceId，则返回无效的HiTraceId。


### OH_HiTrace_GetParentSpanId()

```
uint64_t OH_HiTrace_GetParentSpanId (const HiTraceId * id)
```
**描述**
获取当前HiTraceId结构体中的父分支ID。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| id | 需要获取父分支ID的HiTraceId结构体中，见[HiTraceId](_hi_trace_id.md)。 | 

**返回：**

HiTraceId结构体中设置的父分支ID。


### OH_HiTrace_GetSpanId()

```
uint64_t OH_HiTrace_GetSpanId (const HiTraceId * id)
```
**描述**
获取当前HiTraceId结构体中的分支ID。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| id | 需要获取分支ID的HiTraceId结构体，见[HiTraceId](_hi_trace_id.md)。 | 

**返回：**

HiTraceId结构体中设置的分支ID。


### OH_HiTrace_IdFromBytes()

```
void OH_HiTrace_IdFromBytes (HiTraceId * id, const uint8_t * pIdArray, int len )
```
**描述**
根据字节数组创建跟踪HiTraceId结构体。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| id | 需要创建的[HiTraceId](_hi_trace_id.md)。  | 
| pIdArray | 字节数组。  | 
| len | 字节数组长度。 | 


### OH_HiTrace_IdToBytes()

```
int OH_HiTrace_IdToBytes (const HiTraceId * id, uint8_t * pIdArray, int len )
```
**描述**
将HiTraceId结构体转换为字节数组，用于缓存或者通信传递。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| id | 需要转换的HiTraceId，见[HiTraceId](_hi_trace_id.md)。  | 
| pIdArray | 字节数组。  | 
| len | 字节数组长度。 | 

**返回：**

转换后的字节数组长度。


### OH_HiTrace_InitId()

```
void OH_HiTrace_InitId (HiTraceId * id)
```
**描述**
初始化HiTraceId结构体。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| id | 需要初始化的[HiTraceId](_hi_trace_id.md)。 | 


### OH_HiTrace_IsFlagEnabled()

```
bool OH_HiTrace_IsFlagEnabled (const HiTraceId * id, HiTrace_Flag flag )
```
**描述**
判断跟踪id是否启用了跟踪标志。

HiTraceId结构体的某标志是否置位。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| id | 需要判断的Trace id，见[HiTraceId](_hi_trace_id.md)。  | 
| flag | 需要判断的flag，见[HiTrace_Flag](#hitrace_flag)。  | 

**返回：**

如果跟踪ID已启用标志，则为true。


### OH_HiTrace_IsIdValid()

```
bool OH_HiTrace_IsIdValid (const HiTraceId * id)
```
**描述**
判断trace id是否有效。

HiTraceId结构体是否有效。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| id | 需要判断的Trace id，见[HiTraceId](_hi_trace_id.md)。  | 

**返回：**

如果跟踪ID有效，则为True；否则为false。


### OH_HiTrace_IsTraceEnabled()

```
bool OH_HiTrace_IsTraceEnabled (void )
```
**描述**
判断当前是否开启应用trace捕获。应用trace捕获未开启时，HiTraceMeter性能跟踪打点无效。



**起始版本：** 19

**返回：**

返回true表示当前开启应用trace捕获，HiTraceMeter性能跟踪打点可生效；

返回false表示当前未开启应用trace捕获，HiTraceMeter性能跟踪打点无效。


### OH_HiTrace_SetChainId()

```
void OH_HiTrace_SetChainId (HiTraceId * id, uint64_t chainId )
```
**描述**
设置跟踪链ID到HiTraceId结构体中。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| id | 需要设置跟踪链ID的HiTraceId结构体，见[HiTraceId](_hi_trace_id.md)。  | 
| chainId | 需要设置的跟踪链ID。 | 


### OH_HiTrace_SetFlags()

```
void OH_HiTrace_SetFlags (HiTraceId * id, int flags )
```
**描述**
设置跟踪标志位到HiTraceId结构体中。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| id | 需要设置跟踪标志位的HiTraceId结构体，见[HiTraceId](_hi_trace_id.md)。  | 
| flags | 跟踪ID中需要设置的指定跟踪标志，见[HiTrace_Flag](#hitrace_flag)。 | 


### OH_HiTrace_SetId()

```
void OH_HiTrace_SetId (const HiTraceId * id)
```
**描述**
将id设置为当前线程的跟踪id。如果ID无效，则不执行任何操作。

设置HiTraceId结构体内容到当前线程TLS中。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| id | 将id设置为当前线程的跟踪id，见[HiTraceId](_hi_trace_id.md)。 | 


### OH_HiTrace_SetParentSpanId()

```
void OH_HiTrace_SetParentSpanId (HiTraceId * id, uint64_t parentSpanId )
```
**描述**
设置HiTraceId结构的parentSpanId字符。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| id | 需要设置父分支ID的HiTraceId结构体中，见[HiTraceId](_hi_trace_id.md)。  | 
| parentSpanId | 需要设置的父分支ID。 | 


### OH_HiTrace_SetSpanId()

```
void OH_HiTrace_SetSpanId (HiTraceId * id, uint64_t spanId )
```
**描述**
设置分支ID到HiTraceId结构体中。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| id | 需要设置分支ID的HiTraceId结构体。  | 
| spanId | 需要设置的分支ID。 | 


### OH_HiTrace_StartAsyncTrace()

```
void OH_HiTrace_StartAsyncTrace (const char * name, int32_t taskId )
```
**描述**
标记一个异步跟踪耗时任务的开始。

用于在异步操作前调用进行开始打点，异步跟踪开始和结束数据由于不是顺序发生的，所以解析时需要通过一个唯一的taskId进行识别。

必须和OH_HiTrace_FinishAsyncTrace配对使用，参数name和taskId相同的开始与结束打点相匹配，构成一个异步跟踪耗时任务。

如果有多个相同name的任务需要跟踪或者对同一个任务跟踪多次，并且任务同时被执行，则每次调用的taskId不相同。

如果具有相同name的任务是串行执行的，则taskId可以相同。

从API version 19开始，建议使用OH_HiTrace_StartAsyncTraceEx接口，以便分级控制跟踪输出与跟踪聚类。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 异步跟踪的名字。  | 
| taskId | 异步跟踪的ID。 异步跟踪开始和结束由于不是顺序发生的，所以需要通过name和每次执行唯一的taskId进行开始和结束的匹配。 | 


### OH_HiTrace_StartAsyncTraceEx()

```
void OH_HiTrace_StartAsyncTraceEx (HiTrace_Output_Level level, const char * name, int32_t taskId, const char * customCategory, const char * customArgs )
```
**描述**
标记一个异步跟踪耗时任务的开始，分级控制跟踪输出。

用于在异步操作执行前进行开始打点，异步跟踪开始和结束数据由于不是顺序发生的，所以解析时需要通过一个唯一的taskId进行识别。

和OH_HiTrace_FinishAsyncTraceEx配对使用，参数name和taskId相同的开始与结束打点相匹配，构成一个异步跟踪耗时任务。

如果有多个相同name的任务需要跟踪或者对同一个任务跟踪多次，并且任务同时被执行，则每次调用的taskId不相同。

如果具有相同name的任务是串行执行的，则taskId可以相同。

不同进程的taskId不会相互干扰。



**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| level | 跟踪输出优先级。  | 
| name | 异步跟踪的名字。  | 
| taskId | 异步跟踪的ID。  | 
| customCategory | 自定义聚类名称，用于聚合同一类异步跟踪打点。  |
| customArgs | 键值对，多个键值对使用逗号分隔，例"key1=value1,key2=value2"。 | 


### OH_HiTrace_StartTrace()

```
void OH_HiTrace_StartTrace (const char * name)
```
**描述**
标记一个同步跟踪耗时任务的开始。

同步跟踪打点接口OH_HiTrace_StartTrace和OH_HiTrace_FinishTrace必须配对使用。

OH_HiTrace_StartTrace和OH_HiTrace_FinishTrace函数对可以嵌套使用，跟踪解析时使用栈式数据结构进行匹配。

从API version 19开始，建议使用OH_HiTrace_StartTraceEx接口，以便分级控制跟踪输出。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 跟踪的名字。 | 


### OH_HiTrace_StartTraceEx()

```
void OH_HiTrace_StartTraceEx (HiTrace_Output_Level level, const char * name, const char * customArgs )
```
**描述**
标记一个同步跟踪耗时任务的开始，分级控制跟踪输出。

同步跟踪打点接口OH_HiTrace_StartTraceEx和OH_HiTrace_FinishTraceEx必须配对使用。

OH_HiTrace_StartTraceEx和OH_HiTrace_FinishTraceEx函数对可以嵌套使用，跟踪解析时使用栈式数据结构进行匹配。



**起始版本：** 19

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| level | 跟踪输出优先级。  | 
| name | 同步跟踪的名字。  | 
| customArgs | 键值对，多个键值对使用逗号分隔，例"key1=value1,key2=value2"。 | 


### OH_HiTrace_Tracepoint()

```
void OH_HiTrace_Tracepoint (HiTrace_Communication_Mode mode, HiTrace_Tracepoint_Type type, const HiTraceId * id, const char * fmt,  ... )
```
**描述**
打印hitrace信息，包括跟踪ID信息。

输出埋点信息，包括通信方式、埋点类型、时间戳、分支等信息。

**系统能力：** SystemCapability.HiviewDFX.HiTrace

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mode | 跟踪通信模式，见[HiTrace_Communication_Mode](#hitrace_communication_mode)。  | 
| type | 跟踪信息类型，见[HiTrace_Tracepoint_Type](#hitrace_tracepoint_type)。  | 
| id | 需要打印的跟踪ID，见[HiTraceId](_hi_trace_id.md)。  | 
| fmt | 需要打印的自定义信息。 | 


## 变量说明


### chainId

```
uint64_t HiTraceId::chainId
```
**描述**
HiTraceId的链Id。


### flags

```
uint64_t HiTraceId::flags
```
**描述**
HiTraceId的标志位。


### parentSpanId

```
uint64_t HiTraceId::parentSpanId
```
**描述**
HiTraceId的父跨度号。


### spanId

```
uint64_t HiTraceId::spanId
```
**描述**
HiTraceId的当前跨度号。


### valid

```
uint64_t HiTraceId::valid
```
**描述**
HiTraceId是否有效。


### ver

```
uint64_t HiTraceId::ver
```
**描述**
HiTraceId的版本号。
