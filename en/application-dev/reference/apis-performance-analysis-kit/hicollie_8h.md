# hicollie.h

## Overview

HiCollie provides APIs for detecting service thread stuck and jank events and reporting stuck events.

**Library**: libohhicollie.so

**System capability**: SystemCapability.HiviewDFX.HiCollie

**File to include**: <hicollie/hicollie.h>

**Since**: 12

**Related module**: [HiCollie](_hi_hicollie.md)


## Summary

### Structs

| Name| Description|
| -------- | -------- |
| struct&nbsp;&nbsp;[HiCollie_DetectionParam](_hi_hicollie___detection_param.md) | Defines the parameters of service thread jank event detection. Note that these parameters are deprecated in API version 12 and reserved for extension only. |
| struct&nbsp;&nbsp;[HiCollie_SetTimerParam](_hi_hicollie___set_timer_param.md) | Defines the parameters of the **OH_HiCollie_SetTimer** function. |

### Types

| Name| Description|
| -------- | -------- |
| typedef enum [HiCollie_ErrorCode](_hi_hicollie.md#hicollie_errorcode)[HiCollie_ErrorCode](_hi_hicollie.md#hicollie_errorcode) | Defines an enum for error codes. |
| typedef void(\* [OH_HiCollie_Task](_hi_hicollie.md#oh_hicollie_task)) (void) | Defines a function to check whether a stuck event occurs in a service thread. This function is called by HiCollie every 3 seconds in an independent thread. For example, this function can send messages to service threads. When a service thread receives a message, a flag is set. By checking the flag, you can determine whether a stuck event occurs in the service thread. |
| typedef void(\* [OH_HiCollie_BeginFunc](_hi_hicollie.md#oh_hicollie_beginfunc)) (const char \*eventName) | Defines a function to record the start time of event processing in the service thread during jank event detection. This function is used before event processing. |
| typedef void(\* [OH_HiCollie_EndFunc](_hi_hicollie.md#oh_hicollie_endfunc)) (const char \*eventName) | Defines a function to check whether a jank event occurs in a service thread during event processing. This function is used after event processing. By checking the execution duration of the processing events, HiCollie determines the duration of each event. If the execution duration is greater than 150 ms but less than 450 ms, a jank event is reported. |
| typedef struct [HiCollie_DetectionParam](_hi_hicollie___detection_param.md)[HiCollie_DetectionParam](_hi_hicollie.md#hicollie_detectionparam) | Defines a struct for HiCollie detection parameters. Note that these parameters are deprecated in API version 12 and reserved for extension only. |
| typedef void(\* [OH_HiCollie_Callback](_hi_hicollie.md#oh_hicollie_callback)) (void \*) | Defines a function for timeout detection. |
| typedef enum [HiCollie_Flag](_hi_hicollie.md#hicollie_flag)[HiCollie_Flag](_hi_hicollie.md#hicollie_flag) | Defines an enum for executions to be performed when a function times out. |
| typedef struct [HiCollie_SetTimerParam](_hi_hicollie___set_timer_param.md)[HiCollie_SetTimerParam](_hi_hicollie.md#hicollie_settimerparam) | Defines a struct for the parameters of the **OH_HiCollie_SetTimer** function. |

### Enums

| Name| Description|
| -------- | -------- |
| [HiCollie_ErrorCode](_hi_hicollie.md#hicollie_errorcode) {<br>[HICOLLIE_SUCCESS](_hi_hicollie.md) = 0, [HICOLLIE_INVALID_ARGUMENT](_hi_hicollie.md) = 401, [HICOLLIE_WRONG_THREAD_CONTEXT](_hi_hicollie.md) = 29800001, [HICOLLIE_REMOTE_FAILED](_hi_hicollie.md) = 29800002,<br>[HICOLLIE_INVALID_TIMER_NAME](_hi_hicollie.md) = 29800003, [HICOLLIE_INVALID_TIMEOUT_VALUE](_hi_hicollie.md) = 29800004, [HICOLLIE_WRONG_PROCESS_CONTEXT](_hi_hicollie.md) = 29800005, [HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM](_hi_hicollie.md) = 29800006<br>} | Enumerates the error codes used in the HiCollie module. |
| [HiCollie_Flag](_hi_hicollie.md#hicollie_flag) { [HICOLLIE_FLAG_DEFAULT](_hi_hicollie.md) = (~0), **HICOLLIE_FLAG_NOOP** = (0), **HICOLLIE_FLAG_LOG** = (1 &lt;&lt; 0), **HICOLLIE_FLAG_RECOVERY** = (1 &lt;&lt; 1) } | Enumerates the executions to be performed when a function times out. |

### Functions

| Name| Description|
| -------- | -------- |
| [HiCollie_ErrorCode](_hi_hicollie.md#hicollie_errorcode)[OH_HiCollie_Init_StuckDetection](_hi_hicollie.md#oh_hicollie_init_stuckdetection) ([OH_HiCollie_Task](_hi_hicollie.md#oh_hicollie_task) task) | Registers a callback to periodically detect service thread stuck events. |
| [HiCollie_ErrorCode](_hi_hicollie.md#hicollie_errorcode)[OH_HiCollie_Init_JankDetection](_hi_hicollie.md#oh_hicollie_init_jankdetection) ([OH_HiCollie_BeginFunc](_hi_hicollie.md#oh_hicollie_beginfunc) \*beginFunc, [OH_HiCollie_EndFunc](_hi_hicollie.md#oh_hicollie_endfunc) \*endFunc, [HiCollie_DetectionParam](_hi_hicollie___detection_param.md) param) | Registers a callback to detect service thread jank events. |
| [HiCollie_ErrorCode](_hi_hicollie.md#hicollie_errorcode)[OH_HiCollie_Report](_hi_hicollie.md#oh_hicollie_report) (bool \*isSixSecond) | Enables a timer for checking the function execution duration. This API is used together with the **OH_HiCollie_SetTimer** and **OH_HiCollie_CancelTimer** APIs. The **OH_HiCollie_SetTimer** API is used to set a timeout detection task, and the **OH_HiCollie_CancelTimer** API is used to cancel the task based on the timer ID.<br>If a task is not canceled in a timely manner, that is, a timeout occurs, a callback can be executed to generate a timeout fault log for a specific behavior flag, helping locate application timeout issues. |
| [HiCollie_ErrorCode](_hi_hicollie.md#hicollie_errorcode)[OH_HiCollie_SetTimer](_hi_hicollie.md#oh_hicollie_settimer) ([HiCollie_SetTimerParam](_hi_hicollie___set_timer_param.md) param, int \*id) | Sets a timeout detection task before a time-consuming function is called. |
| void [OH_HiCollie_CancelTimer](_hi_hicollie.md#oh_hicollie_canceltimer) (int id) | Cancels a timer immediately after a time-consuming function is called. |
