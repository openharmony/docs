# hicollie.h


## 概述

HiCollie模块对外提供检测业务线程卡死、卡顿，以及上报卡死事件的能力。

**库：** libohhicollie.so

**系统能力：** SystemCapability.HiviewDFX.HiCollie

**引用文件：** &lt;hicollie/hicollie.h&gt;

**起始版本：** 12

**相关模块：** [HiCollie](_hi_collie.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[HiCollie_DetectionParam](_hi_collie___detection_param.md) | 检测业务线程卡顿的相关参数。请注意，API 12及以上支持。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) | 错误码定义。  | 
| typedef void(\* [OH_HiCollie_Task](_hi_collie.md#oh_hicollie_task)) (void) | 在业务线程卡死检测中，通过实现该函数来检测业务线程是否卡住。<br/>HiCollie将在独立线程中每3秒调用一次该函数。<br/>例如：该函数可实现向业务线程发送消息，在业务线程接收到消息之后，设置一个标记，检查这个标记，确定业务线程是否卡住。 | 
| typedef void(\* [OH_HiCollie_BeginFunc](_hi_collie.md#oh_hicollie_beginfunc)) (const char \*eventName) | 卡顿检测中,函数用于记录业务线程处理事件的开始时间。<br/>检查处理事件的执行时间，HiCollie将检查每个事件的持续时间。如果超过预设阈值，上报jank事件。<br/>该函数是在每个事件处理之前插入的回调函数。 | 
| typedef void(\* [OH_HiCollie_EndFunc](_hi_collie.md#oh_hicollie_endfunc)) (const char \*eventName) | 卡顿检测中, 该函数用于检测业务线程处理事件是否卡顿。<br/>检查处理事件的执行时间，HiCollie将检查每个事件的持续时间。如果超过预设阈值，上报jank事件。<br/>该函数是在每个事件处理之后插入的回调函数。 | 
| typedef struct [HiCollie_DetectionParam](_hi_collie___detection_param.md) [HiCollie_DetectionParam](_hi_collie.md#hicollie_detectionparam) | 检测业务线程卡顿的相关参数。请注意，API 12及以上支持。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) {<br/>HICOLLIE_SUCCESS = 0, <br/>HICOLLIE_INVALID_ARGUMENT = 401, <br/>HICOLLIE_WRONG_THREAD_CONTEXT = 29800001, <br/>HICOLLIE_REMOTE_FAILED = 29800002 } | 错误码定义。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode)[OH_HiCollie_Init_StuckDetection](_hi_collie.md#oh_hicollie_init_stuckdetection) ([OH_HiCollie_Task](_hi_collie.md#oh_hicollie_task) task) | 注册应用业务线程卡死的周期性检测任务。用户实现回调函数, 用于定时检测业务线程卡死情况。<br/>默认检测时间：3s上报BUSSINESS_THREAD_BLOCK_3S告警事件，6s上报BUSSINESS_THREAD_BLOCK_6S卡死事件。 | 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode)[OH_HiCollie_Init_JankDetection](_hi_collie.md#oh_hicollie_init_jankdetection) ([OH_HiCollie_BeginFunc](_hi_collie.md#oh_hicollie_beginfunc) \*beginFunc, [OH_HiCollie_EndFunc](_hi_collie.md#oh_hicollie_endfunc) \*endFunc, [HiCollie_DetectionParam](_hi_collie___detection_param.md) param) | 注册应用业务线程卡顿检测的回调函数。<br/>线程卡顿监控功能需要开发者实现两个卡顿检测回调函数, 分别放在业务线程处理事件的前后。作为插桩函数，监控业务线程处理事件执行情况。 | 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode)[OH_HiCollie_Report](_hi_collie.md#oh_hicollie_report) (bool \*isSixSecond) | 上报应用业务线程卡死事件，生成卡死故障日志，辅助定位应用卡死问题。<br/>先调用OH_HiCollie_Init_StuckDetection或OH_HiCollie_Init_StuckDetectionWithTimeout接口，初始化检测的task；<br/>如果task任务超时，结合业务逻辑，调用OH_HiCollie_Report接口上报卡死事件。 | 
