# hicollie.h


## Overview

HiCollie provides APIs for detecting service thread stuck and jank events and reporting stuck events.

**Library**: libohhicollie.so

**System capability**: SystemCapability.HiviewDFX.HiCollie

**File to include**: <hicollie/hicollie.h>

**Since**: 12

**Related module**: [HiCollie](_hi_collie.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[HiCollie_DetectionParam](_hi_collie___detection_param.md) | Defines the parameters of the service thread jank event detection. Note that these parameters are deprecated in API version 12 and reserved for extension only. | 
| struct&nbsp;&nbsp;[HiCollie_SetTimerParam](_hi_collie___set_timer_param.md) | Defines the input parameters of the **OH_HiCollie_SetTimer** function. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) | Defines an enum for the error codes used in the HiCollie module. | 
| typedef void(\* [OH_HiCollie_Task](_hi_collie.md#oh_hicollie_task)) (void) | Defines a function used to check whether a service thread is stuck.<br>This function is called by HiCollie every 3 seconds in an independent thread.<br>For example, this function can send messages to service threads. When a service thread receives a message, a flag is set. By checking the flag, HiCollie can determine whether a service thread is stuck.| 
| typedef void(\* [OH_HiCollie_BeginFunc](_hi_collie.md#oh_hicollie_beginfunc)) (const char \*eventName) | Defines a function used to record the start time of the service thread event during jank event detection. This function is used before event processing. | 
| typedef void(\* [OH_HiCollie_EndFunc](_hi_collie.md#oh_hicollie_endfunc)) (const char \*eventName) | Defines a function used to check whether a service thread is janky during event processing. This function is used after event processing.<br>By checking the execution duration of the processing events, HiCollie determines the duration of each event. If the duration is greater than 150 ms but less than 450 ms, a jank event is reported.| 
| typedef struct [HiCollie_DetectionParam](_hi_collie___detection_param.md) [HiCollie_DetectionParam](_hi_collie.md#hicollie_detectionparam) | Defines a struct for the parameters of the service thread jank event detection. Note that these parameters are deprecated in API version 12 and reserved for extension only. | 
| typedef void(\* [OH_HiCollie_Callback](_hi_collie.md#oh_hicollie_callback)) (void \*) | Defines a callback executed when a timeout occurs. | 
| typedef enum [HiCollie_Flag](_hi_collie.md#hicollie_flag) [HiCollie_Flag](_hi_collie.md#hicollie_flag) | Defines an enum for the executions to be performed when a function times out. | 
| typedef struct [HiCollie_SetTimerParam](_hi_collie___set_timer_param.md) [HiCollie_SetTimerParam](_hi_collie.md#hicollie_settimerparam) | Defines a struct for the input parameters of the **OH_HiCollie_SetTimer** function. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) {<br>[HICOLLIE_SUCCESS](_hi_collie.md) = 0, [HICOLLIE_INVALID_ARGUMENT](_hi_collie.md) = 401, [HICOLLIE_WRONG_THREAD_CONTEXT](_hi_collie.md) = 29800001, [HICOLLIE_REMOTE_FAILED](_hi_collie.md) = 29800002,<br>[HICOLLIE_INVALID_TIMER_NAME](_hi_collie.md) = 29800003, [HICOLLIE_INVALID_TIMEOUT_VALUE](_hi_collie.md) = 29800004, [HICOLLIE_WRONG_PROCESS_CONTEXT](_hi_collie.md) = 29800005, [HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM](_hi_collie.md) = 29800006<br>} | Enumerates the error codes used in the HiCollie module. | 
| [HiCollie_Flag](_hi_collie.md#hicollie_flag) { [HICOLLIE_FLAG_DEFAULT](_hi_collie.md) = (~0), [HICOLLIE_FLAG_NOOP](_hi_collie.md) = (0), [HICOLLIE_FLAG_LOG](_hi_collie.md) = (1 &lt;&lt; 0), [HICOLLIE_FLAG_RECOVERY](_hi_collie.md) = (1 &lt;&lt; 1) } | Enumerates the executions to be performed when a function times out. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Init_StuckDetection](_hi_collie.md#oh_hicollie_init_stuckdetection) ([OH_HiCollie_Task](_hi_collie.md#oh_hicollie_task) task) | Registers a callback used to periodically detect service thread stuck events.   | 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Init_StuckDetectionWithTimeout](_hi_collie.md#oh_hicollie_init_stuckdetectionwithtimeout) ([OH_HiCollie_Task](_hi_collie.md#oh_hicollie_task) task, uint32_t stuckTimeout) | Registers a callback used to periodically detect service thread stuck events.  You can set the detection time. | 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Init_JankDetection](_hi_collie.md#oh_hicollie_init_jankdetection) ([OH_HiCollie_BeginFunc](_hi_collie.md#oh_hicollie_beginfunc) \*beginFunc, [OH_HiCollie_EndFunc](_hi_collie.md#oh_hicollie_endfunc) \*endFunc, [HiCollie_DetectionParam](_hi_collie___detection_param.md) param) | Registers a callback used to detect service thread jank events.<br>To monitor service thread jank events, you can implement two callbacks as instrumentation functions, placing them before and after the service thread event.  | 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Report](_hi_collie.md#oh_hicollie_report) (bool \*isSixSecond) | Reports a service thread stuck event and generates timeout logs to help locate application timeout events.<br>This API is used together with **OH_HiCollie_Init_StuckDetection()**, which initializes the stuck event detection at first, and then **OH_HiCollie_Report()** reports the stuck event when it occurs.| 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_SetTimer](_hi_collie.md#oh_hicollie_settimer) ([HiCollie_SetTimerParam](_hi_collie___set_timer_param.md) param, int \*id) | Registers a timer for checking the function execution duration before the time-consuming function is called. This API is used together with the **OH_HiCollie_CancelTimer** API. | 
| void [OH_HiCollie_CancelTimer](_hi_collie.md#oh_hicollie_canceltimer) (int id) | Cancels a timer for checking the function execution duration based on timer ID after the function or code is executed.<br>This API is used together with the **OH_HiCollie_SetTimer** API.<br>If this API is not called in time, when a timeout occurs, the callback can be called to generate a timeout fault log and cancel the timer immediately after the time-consuming function is called.| 
