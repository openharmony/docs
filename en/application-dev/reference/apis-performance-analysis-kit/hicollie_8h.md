# hicollie.h


## Overview

HiCollie provides APIs for detecting service thread stuck and jank events and reporting stuck events.

**Library**: libohhicollie.so

**System capability**: SystemCapability.HiviewDFX.HiProfiler.HiCollie

**File to include**: <hicollie/hicollie.h>

**Since**: 12

**Related module**: [HiCollie](_hi_collie.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[HiCollie_DetectionParam](_hi_collie___detection_param.md) | Defines the parameters of the service thread jank event detection. Note that these parameters are deprecated in API version 12 and reserved for extension only. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) | Defines an enum for the error codes used in the HiCollie module. | 
| typedef void(\* [OH_HiCollie_Task](_hi_collie.md#oh_hicollie_task)) (void) | Defines a function used to check whether a service thread is stuck.<br>This function is called by HiCollie every 3 seconds in an independent thread.<br>For example, this function can send messages to service threads. When a service thread receives a message, a flag is set. By checking the flag, HiCollie can determine whether a service thread is stuck.| 
| typedef void(\* [OH_HiCollie_BeginFunc](_hi_collie.md#oh_hicollie_beginfunc)) (const char \*eventName) | Defines a function used to record the start time of the service thread event during jank event detection. This function is used before event processing. | 
| typedef void(\* [OH_HiCollie_EndFunc](_hi_collie.md#oh_hicollie_endfunc)) (const char \*eventName) | Defines a function used to check whether a service thread is janky during event processing. This function is used after event processing.<br>By checking the execution duration of the processing events, HiCollie determines the duration of each event. If the duration is greater than 150 ms but less than 450 ms, a jank event is reported.| 
| typedef struct [HiCollie_DetectionParam](_hi_collie___detection_param.md) [HiCollie_DetectionParam](_hi_collie.md#hicollie_detectionparam) | Defines a struct for the parameters of the service thread jank event detection. Note that these parameters are deprecated in API version 12 and reserved for extension only. | 


### Enums

| Name| Description| 
| -------- | -------- |
 | [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) { [HICOLLIE_SUCCESS](_hi_collie.md) = 0, [HICOLLIE_INVALID_ARGUMENT](_hi_collie.md) = 401, [HICOLLIE_WRONG_THREAD_CONTEXT](_hi_collie.md) = 29800001, [HICOLLIE_REMOTE_FAILED](_hi_collie.md) = 29800002 } | Enumerates the error codes used in the HiCollie module.  | 


### Functions

| Name| Description| 
| -------- | -------- |
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Init_StuckDetection](_hi_collie.md#oh_hicollie_init_stuckdetection) ([OH_HiCollie_Task](_hi_collie.md#oh_hicollie_task) task) | Registers a callback used to periodically detect service thread stuck events.   | 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Init_JankDetection](_hi_collie.md#oh_hicollie_init_jankdetection) ([OH_HiCollie_BeginFunc](_hi_collie.md#oh_hicollie_beginfunc) \*beginFunc, [OH_HiCollie_EndFunc](_hi_collie.md#oh_hicollie_endfunc) \*endFunc, [HiCollie_DetectionParam](_hi_collie___detection_param.md) param) | Registers a callback used to detect service thread jank events.<br>To monitor service thread jank events, you can implement two callbacks as instrumentation functions, placing them before and after the service thread event.  | 
| [HiCollie_ErrorCode](_hi_collie.md#hicollie_errorcode) [OH_HiCollie_Report](_hi_collie.md#oh_hicollie_report) (bool \*isSixSecond) | Reports a service thread stuck event and generates timeout logs to help locate application timeout events.<br>This API is used together with **OH_HiCollie_Init_StuckDetection()**, which initializes the stuck event detection at first, and then **OH_HiCollie_Report()** reports the stuck event when it occurs.| 
