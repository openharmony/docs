# hicollie.h


## 概述

HiCollie模块对外提供检测业务线程卡死、卡顿，以及上报卡死事件的能力。

**库：** libohhicollie.so

**系统能力：** SystemCapability.HiviewDFX.HiCollie

**引用文件：** &lt;hicollie/hicollie.h&gt;

**起始版本：** 12

**相关模块：**[HiCollie](_hi_collie.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[HiCollie_DetectionParam](_hi_collie___detection_param.md) | 用于检测业务线程卡顿的参数。请注意，这些参数对API 12无效，仅用于扩展。  | 
| struct&nbsp;&nbsp;[HiCollie_SetTimerParam](_hi_collie___set_timer_param.md) | 定义OH_HiCollie_SetTimer函数的输入参数。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) | 错误码定义。  | 
| typedef void(\* [OH_HiCollie_Task](_hi_collie.md#oh_hicollie_task)) (void) | 在业务线程卡死检测中，通过实现该函数来检测业务线程是否卡住。<br/>HiCollie将在独立线程中每3秒调用一次该函数。<br/>例如：该函数可实现向业务线程发送消息。在业务线程接收到消息之后，设置一个标记，通过检查这个标记，可以知道业务线程是否卡住。 | 
| typedef void(\* [OH_HiCollie_BeginFunc](_hi_collie.md#oh_hicollie_beginfunc)) (const char \*eventName) | 事件处理前调用该函数。在卡顿检测中, 通过实现该函数来记录业务线程处理事件的开始时间。  | 
| typedef void(\* [OH_HiCollie_EndFunc](_hi_collie.md#oh_hicollie_endfunc)) (const char \*eventName) | 事件处理后调用该函数。在卡顿检测中, 通过实现该函数来检测业务线程处理事件是否卡顿。<br/>通过检查处理事件的执行时间，HiCollie将知道每个事件的持续时间。如果超过预设阈值(150ms~450ms)，将上报卡顿事件。 | 
| typedef struct [HiCollie_DetectionParam](_hi_collie___detection_param.md) [HiCollie_DetectionParam](_hi_collie.md#hicollie_detectionparam) | 用于检测业务线程卡顿的参数。请注意，这些参数对API 12无效，仅用于扩展。  | 
| typedef void(\* [OH_HiCollie_Callback](_hi_collie.md#oh_hicollie_callback)) (void \*) | 超时发生时执行的回调函数。  | 
| typedef enum [HiCollie_Flag](_hi_collie.md#hicollie_flag) [HiCollie_Flag](_hi_collie.md#hicollie_flag) | 定义函数执行超时时发生的动作。  | 
| typedef struct [HiCollie_SetTimerParam](_hi_collie___set_timer_param.md) [HiCollie_SetTimerParam](_hi_collie.md#hicollie_settimerparam) | 定义OH_HiCollie_SetTimer函数的输入参数。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) {<br/>[HICOLLIE_SUCCESS](_hi_collie.md) = 0, [HICOLLIE_INVALID_ARGUMENT](_hi_collie.md) = 401, [HICOLLIE_WRONG_THREAD_CONTEXT](_hi_collie.md) = 29800001, [HICOLLIE_REMOTE_FAILED](_hi_collie.md) = 29800002,<br/>[HICOLLIE_INVALID_TIMER_NAME](_hi_collie.md) = 29800003, [HICOLLIE_INVALID_TIMEOUT_VALUE](_hi_collie.md) = 29800004, [HICOLLIE_WRONG_PROCESS_CONTEXT](_hi_collie.md) = 29800005, [HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM](_hi_collie.md) = 29800006<br/>} | 错误码定义。  | 
| [HiCollie_Flag](_hi_collie.md#hicollie_flag) { [HICOLLIE_FLAG_DEFAULT](_hi_collie.md) = (~0), [HICOLLIE_FLAG_NOOP](_hi_collie.md) = (0), [HICOLLIE_FLAG_LOG](_hi_collie.md) = (1 &lt;&lt; 0), [HICOLLIE_FLAG_RECOVERY](_hi_collie.md) = (1 &lt;&lt; 1) } | 定义函数执行超时时发生的动作。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Init_StuckDetection](_hi_collie.md#oh_hicollie_init_stuckdetection) ([OH_HiCollie_Task](_hi_collie.md#oh_hicollie_task) task) | 注册应用业务线程卡死的周期性检测任务。用户实现回调函数, 用于定时检测业务线程卡死情况。  | 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Init_StuckDetectionWithTimeout](_hi_collie.md#oh_hicollie_init_stuckdetectionwithtimeout) ([OH_HiCollie_Task](_hi_collie.md#oh_hicollie_task) task, uint32_t stuckTimeout) | 注册应用业务线程卡死的周期性检测任务。用户实现回调函数, 用于定时检测业务线程卡死情况。开发者可以设置卡死检测时间。  | 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Init_JankDetection](_hi_collie.md#oh_hicollie_init_jankdetection) ([OH_HiCollie_BeginFunc](_hi_collie.md#oh_hicollie_beginfunc) \*beginFunc, [OH_HiCollie_EndFunc](_hi_collie.md#oh_hicollie_endfunc) \*endFunc, [HiCollie_DetectionParam](_hi_collie___detection_param.md) param) | 注册应用业务线程卡顿检测的回调函数。<br/>线程卡顿监控功能需要开发者实现两个卡顿检测回调函数, 分别放在业务线程处理事件的前后。作为插桩函数，监控业务线程处理事件执行情况。 | 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Report](_hi_collie.md#oh_hicollie_report) (bool \*isSixSecond) | 用于上报应用业务线程卡死事件，生成超时故障日志，辅助定位应用超时问题。<br/>结合OH_HiCollie_Init_StuckDetection接口配套使用，先初始化卡死检测，出现卡死时，再上报事件。 | 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_SetTimer](_hi_collie.md#oh_hicollie_settimer) ([HiCollie_SetTimerParam](_hi_collie___set_timer_param.md) param, int \*id) | 注册函数执行时长检测定时器。结合OH_HiCollie_CancelTimer接口配套使用，应在调用耗时的函数之前使用。  | 
| void [OH_HiCollie_CancelTimer](_hi_collie.md#oh_hicollie_canceltimer) (int id) | 取消函数执行时长检测定时器。<br/>结合OH_HiCollie_SetTimer接口配套使用，执行函数或代码后，OH_HiCollie_CancelTimer通过timer id将该任务取消，应在调用耗时的函数之后使用；<br/>若取消不及时，即超时发生可执行回调函数，特定行为信号下生成超时故障日志，调用耗时函数后立即取消计时器。 | 
