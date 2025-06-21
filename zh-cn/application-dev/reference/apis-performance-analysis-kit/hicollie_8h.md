# hicollie.h


## 概述

HiCollie模块对外提供检测业务线程卡死、卡顿，以及上报卡死事件的能力。

**库：** libohhicollie.so

**系统能力：** SystemCapability.HiviewDFX.HiCollie

**起始版本：** 12

**相关模块：**[HiCollie](_hi_collie.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[HiCollie_DetectionParam](_hi_collie___detection_param.md) | 检测业务线程卡顿的相关参数。请注意，API 12及以上支持。  | 
| struct&nbsp;&nbsp;[HiCollie_SetTimerParam](_hi_collie___set_timer_param.md) | 定义OH_HiCollie_SetTimer函数的输入参数。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) | 错误码定义。  | 
| typedef void(\* [OH_HiCollie_Task](_hi_collie.md#oh_hicollie_task)) (void) | 在业务线程卡死检测中，通过实现该函数来检测业务线程是否卡住。<br/>HiCollie将在独立线程中每3秒调用一次该函数。<br/>例如：该函数可实现向业务线程发送消息，在业务线程接收到消息之后，设置一个标记，检查这个标记，确定业务线程是否卡住。 | 
| typedef void(\* [OH_HiCollie_BeginFunc](_hi_collie.md#oh_hicollie_beginfunc)) (const char \*eventName) | 卡顿检测中,函数用于记录业务线程处理事件的开始时间。<br/>检查处理事件的执行时间，HiCollie将检查每个事件的持续时间。如果超过预设阈值，上报jank事件。<br/>该函数是在每个事件处理之前插入的回调函数。 | 
| typedef void(\* [OH_HiCollie_EndFunc](_hi_collie.md#oh_hicollie_endfunc)) (const char \*eventName) | 卡顿检测中, 该函数用于检测业务线程处理事件是否卡顿。<br/>检查处理事件的执行时间，HiCollie将检查每个事件的持续时间。如果超过预设阈值，上报jank事件。<br/>该函数是在每个事件处理之后插入的回调函数。 | 
| typedef struct [HiCollie_DetectionParam](_hi_collie___detection_param.md) [HiCollie_DetectionParam](_hi_collie.md#hicollie_detectionparam) | 检测业务线程卡顿的相关参数。请注意，API 12及以上支持。  | 
| typedef void(\* [OH_HiCollie_Callback](_hi_collie.md#oh_hicollie_callback)) (void \*) | 当用户调用[OH_HiCollie_SetTimer](_hi_collie.md#oh_hicollie_settimer)后，未在其自定义的任务超时时间阈值内调用[OH_HiCollie_CancelTimer](_hi_collie.md#oh_hicollie_canceltimer)，回调函数将被执行。  | 
| typedef enum [HiCollie_Flag](_hi_collie.md#hicollie_flag) [HiCollie_Flag](_hi_collie.md#hicollie_flag) | 定义函数执行超时时发生的动作。  | 
| typedef struct [HiCollie_SetTimerParam](_hi_collie___set_timer_param.md) [HiCollie_SetTimerParam](_hi_collie.md#hicollie_settimerparam) | 定义OH_HiCollie_SetTimer函数的输入参数。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) {<br/>HICOLLIE_SUCCESS = 0, <br/>HICOLLIE_INVALID_ARGUMENT = 401, <br/>HICOLLIE_WRONG_THREAD_CONTEXT = 29800001, <br/>HICOLLIE_REMOTE_FAILED = 29800002, <br/>HICOLLIE_INVALID_TIMER_NAME = 29800003, <br/>HICOLLIE_INVALID_TIMEOUT_VALUE = 29800004, <br/>HICOLLIE_WRONG_PROCESS_CONTEXT = 29800005, <br/>HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM = 29800006<br/>} | 错误码定义。  | 
| [HiCollie_Flag](_hi_collie.md#hicollie_flag) {<br/>HICOLLIE_FLAG_DEFAULT = (~0), <br/>HICOLLIE_FLAG_NOOP = (0), <br/>HICOLLIE_FLAG_LOG = (1 &lt;&lt; 0), <br/>HICOLLIE_FLAG_RECOVERY = (1 &lt;&lt; 1)<br/>} | 定义函数执行超时时发生的动作。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Init_StuckDetection](_hi_collie.md#oh_hicollie_init_stuckdetection) ([OH_HiCollie_Task](_hi_collie.md#oh_hicollie_task) task) | 注册应用业务线程卡死的周期性检测任务。用户实现回调函数, 用于定时检测业务线程卡死情况。<br/>默认检测时间：3s上报BUSSINESS_THREAD_BLOCK_3S告警事件，6s上报BUSSINESS_THREAD_BLOCK_6S卡死事件。 | 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Init_StuckDetectionWithTimeout](_hi_collie.md#oh_hicollie_init_stuckdetectionwithtimeout) ([OH_HiCollie_Task](_hi_collie.md#oh_hicollie_task) task, uint32_t stuckTimeout) | 注册应用业务线程卡死的周期性检测任务。用户实现回调函数, 用于定时检测业务线程卡死情况。<br/>开发者可以设置卡死检测时间，可设置的时间范围：[3, 15]，单位：秒。 | 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Init_JankDetection](_hi_collie.md#oh_hicollie_init_jankdetection) ([OH_HiCollie_BeginFunc](_hi_collie.md#oh_hicollie_beginfunc) \*beginFunc, [OH_HiCollie_EndFunc](_hi_collie.md#oh_hicollie_endfunc) \*endFunc, [HiCollie_DetectionParam](_hi_collie___detection_param.md) param) | 注册应用业务线程卡顿检测的回调函数。<br/>线程卡顿监控功能需要开发者实现两个卡顿检测回调函数, 分别放在业务线程处理事件的前后。作为插桩函数，监控业务线程处理事件执行情况。 | 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Report](_hi_collie.md#oh_hicollie_report) (bool \*isSixSecond) | 上报应用业务线程卡死事件，生成卡死故障日志，辅助定位应用卡死问题。<br/>先调用OH_HiCollie_Init_StuckDetection或OH_HiCollie_Init_StuckDetectionWithTimeout接口，初始化检测的task；<br/>如果task任务超时，结合业务逻辑，调用OH_HiCollie_Report接口上报卡死事件。 | 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_SetTimer](_hi_collie.md#oh_hicollie_settimer) ([HiCollie_SetTimerParam](_hi_collie___set_timer_param.md) param, int \*id) | 注册定时器，用于检测函数或代码块执行是否超过自定义时间。<br/>结合OH_HiCollie_CancelTimer接口配套使用，应在调用耗时的函数之前使用。 | 
| void [OH_HiCollie_CancelTimer](_hi_collie.md#oh_hicollie_canceltimer) (int id) | 取消定时器。<br/>结合OH_HiCollie_SetTimer接口配套使用，执行函数或代码块后使用，OH_HiCollie_CancelTimer通过id将该任务取消；<br/>若未在自定义时间内取消，则执行回调函数，在特定自定义超时动作下，生成故障日志。 | 
