# hicollie.h


## Overview

HiCollie provides APIs for detecting service thread stuck and jank events and reporting stuck events.

**Library**: libohhicollie.so

**System capability**: SystemCapability.HiviewDFX.HiCollie

**Since**: 12

**Related module**: [HiCollie](_hi_collie.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[HiCollie_DetectionParam](_hi_collie___detection_param.md) | Defines the parameters of the jank event detection. Note that this struct is supported since API 12. | 
| struct&nbsp;&nbsp;[HiCollie_SetTimerParam](_hi_collie___set_timer_param.md) | Defines the input parameters of the **OH_HiCollie_SetTimer** function. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) | Defines an enum for the error codes used in the HiCollie module. | 
| typedef void(\* [OH_HiCollie_Task](_hi_collie.md#oh_hicollie_task)) (void) | Defines a function used to check whether a service thread is stuck.<br>This function is called by HiCollie every 3 seconds in an independent thread.<br>For example, this function can be used to send a message to a service thread and set a flag after the service thread receives the message. Then the flag is checked to determine whether the service thread is stuck.| 
| typedef void(\* [OH_HiCollie_BeginFunc](_hi_collie.md#oh_hicollie_beginfunc)) (const char \*eventName) | Defines a function used to record the begin time when a service thread processes an event. This function is used in the jank event detection.<br>HiCollie checks the duration of each event. If the duration exceeds the preset threshold, a jank event is reported.<br>This function is inserted before each event is processed.| 
| typedef void(\* [OH_HiCollie_EndFunc](_hi_collie.md#oh_hicollie_endfunc)) (const char \*eventName) | Defines a function used to check whether a service thread is janky when processing an event. This function is used in the jank event detection.<br>HiCollie checks the duration of each event. If the duration exceeds the preset threshold, a jank event is reported.<br>This function is inserted after each event is processed.| 
| typedef struct [HiCollie_DetectionParam](_hi_collie___detection_param.md) [HiCollie_DetectionParam](_hi_collie.md#hicollie_detectionparam) | Defines a struct for the parameters of the jank event detection. Note that this type is supported since API 12. | 
| typedef void(\* [OH_HiCollie_Callback](_hi_collie.md#oh_hicollie_callback)) (void \*) | Defines a callback function to be executed when [OH_HiCollie_CancelTimer](_hi_collie.md#oh_hicollie_canceltimer) is not called within the custom task timeout period after [OH_HiCollie_SetTimer](_hi_collie.md#oh_hicollie_settimer) is called. | 
| typedef enum [HiCollie_Flag](_hi_collie.md#hicollie_flag) [HiCollie_Flag](_hi_collie.md#hicollie_flag) | Defines an enum for the executions to be performed when a function times out. | 
| typedef struct [HiCollie_SetTimerParam](_hi_collie___set_timer_param.md) [HiCollie_SetTimerParam](_hi_collie.md#hicollie_settimerparam) | Defines a struct for the input parameters of the **OH_HiCollie_SetTimer** function. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) {<br>HICOLLIE_SUCCESS = 0, <br>HICOLLIE_INVALID_ARGUMENT = 401, <br>HICOLLIE_WRONG_THREAD_CONTEXT = 29800001, <br>HICOLLIE_REMOTE_FAILED = 29800002, <br>HICOLLIE_INVALID_TIMER_NAME = 29800003, <br>HICOLLIE_INVALID_TIMEOUT_VALUE = 29800004, <br>HICOLLIE_WRONG_PROCESS_CONTEXT = 29800005, <br>HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM = 29800006<br>} | Defines an enum for the error codes used in the HiCollie module. | 
| [HiCollie_Flag](_hi_collie.md#hicollie_flag) {<br>HICOLLIE_FLAG_DEFAULT = (~0), <br>HICOLLIE_FLAG_NOOP = (0), <br>HICOLLIE_FLAG_LOG = (1 &lt;&lt; 0), <br>HICOLLIE_FLAG_RECOVERY = (1 &lt;&lt; 1)<br>} | Defines an enum for the executions to be performed when a function times out. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Init_StuckDetection](_hi_collie.md#oh_hicollie_init_stuckdetection) ([OH_HiCollie_Task](_hi_collie.md#oh_hicollie_task) task) | Registers a callback used to periodically detect service thread stuck events.  <br>By default, the **BUSSINESS_THREAD_BLOCK_3S** event is reported when the thread is blocked for 3s and the **BUSSINESS_THREAD_BLOCK_6S** event is reported when the thread is blocked for 6s.| 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Init_StuckDetectionWithTimeout](_hi_collie.md#oh_hicollie_init_stuckdetectionwithtimeout) ([OH_HiCollie_Task](_hi_collie.md#oh_hicollie_task) task, uint32_t stuckTimeout) | Registers a callback used to periodically detect service thread stuck events.  <br>You can set the interval for the stuck event detection. The value range is [3, 15], in seconds.| 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Init_JankDetection](_hi_collie.md#oh_hicollie_init_jankdetection) ([OH_HiCollie_BeginFunc](_hi_collie.md#oh_hicollie_beginfunc) \*beginFunc, [OH_HiCollie_EndFunc](_hi_collie.md#oh_hicollie_endfunc) \*endFunc, [HiCollie_DetectionParam](_hi_collie___detection_param.md) param) | Registers a callback used to detect service thread jank events.<br>To monitor service thread jank events, you can implement two callbacks as instrumentation functions, placing them before and after the service thread event.  | 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Report](_hi_collie.md#oh_hicollie_report) (bool \*isSixSecond) | Reports a service thread stuck event and generates logs to help locate application stuck issues.<br>Call **OH_HiCollie_Init_StuckDetection()** or **OH_HiCollie_Init_StuckDetectionWithTimeout()** to initialize the detection task.<br>If the task times out, call **OH_HiCollie_Report()** to report the stuck event based on the service logic.| 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_SetTimer](_hi_collie.md#oh_hicollie_settimer) ([HiCollie_SetTimerParam](_hi_collie___set_timer_param.md) param, int \*id) | Registers a timer to check whether the execution time of a function or code block exceeds the custom time.<br>This API is used together with the **OH_HiCollie_CancelTimer** API. It must be used before the time-consuming function is called.| 
| void [OH_HiCollie_CancelTimer](_hi_collie.md#oh_hicollie_canceltimer) (int id) | Cancels a timer based on the ID.<br>This API is used together with the **OH_HiCollie_SetTimer** API. It must be used after the function or code block is executed.<br>If a timer is not canceled within the custom time, a callback function is executed to generate fault logs for the specified timeout event.| 
