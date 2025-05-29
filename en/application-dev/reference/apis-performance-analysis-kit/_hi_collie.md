# HiCollie


## Overview

Provides the APIs for detecting service thread jank and stuck events. Note that these APIs must be called in non-main threads.

The following capabilities are supported:

(1) Register a periodic check task for application service thread stuck events.

(2) Register a callback for the check of application service thread jank events.

(2) Report an application service thread stuck event.

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [hicollie.h](hicollie_8h.md) | HiCollie provides APIs for checking service thread stuck and jank events and reporting stuck events. |

### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[HiCollie_DetectionParam](_hi_collie___detection_param.md) | Defines the parameters of the jank event detection. Note that this struct is supported since API 12. | 
| struct&nbsp;&nbsp;[HiCollie_SetTimerParam](_hi_collie___set_timer_param.md) | Defines the input parameters of the **OH_HiCollie_SetTimer** function. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [HiCollie_ErrorCode](#hicollie_errorcode) [HiCollie_ErrorCode](#hicollie_errorcode) | Defines an enum for the error codes used in the HiCollie module. | 
| typedef void(\* [OH_HiCollie_Task](#oh_hicollie_task)) (void) | Defines a function used to check whether a service thread is stuck.<br>This function is called by HiCollie every 3 seconds in an independent thread.<br>For example, this function can be used to send a message to a service thread and set a flag after the service thread receives the message. Then the flag is checked to determine whether the service thread is stuck.| 
| typedef void(\* [OH_HiCollie_BeginFunc](#oh_hicollie_beginfunc)) (const char \*eventName) | Defines a function used to record the begin time when a service thread processes an event. This function is used in the jank event detection.<br>HiCollie checks the duration of each event. If the duration exceeds the preset threshold, a jank event is reported.<br>This function is inserted before each event is processed.| 
| typedef void(\* [OH_HiCollie_EndFunc](#oh_hicollie_endfunc)) (const char \*eventName) | Defines a function used to check whether a service thread is janky when processing an event. This function is used in the jank event detection.<br>HiCollie checks the duration of each event. If the duration exceeds the preset threshold, a jank event is reported.<br>This function is inserted after each event is processed.| 
| typedef struct [HiCollie_DetectionParam](_hi_collie___detection_param.md) [HiCollie_DetectionParam](#hicollie_detectionparam) | Defines a struct for the parameters of the jank event detection. Note that this type is supported since API 12. | 
| typedef void(\* [OH_HiCollie_Callback](#oh_hicollie_callback)) (void \*) | Defines a callback function to be executed when [OH_HiCollie_CancelTimer](#oh_hicollie_canceltimer) is not called within the custom task timeout period after [OH_HiCollie_SetTimer](#oh_hicollie_settimer)) is called. | 
| typedef enum [HiCollie_Flag](#hicollie_flag) [HiCollie_Flag](#hicollie_flag) | Defines an enum for the executions to be performed when a function times out. | 
| typedef struct [HiCollie_SetTimerParam](_hi_collie___set_timer_param.md) [HiCollie_SetTimerParam](#hicollie_settimerparam) | Defines a struct for the input parameters of the **OH_HiCollie_SetTimer** function. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [HiCollie_ErrorCode](#hicollie_errorcode) {<br>HICOLLIE_SUCCESS = 0, HICOLLIE_INVALID_ARGUMENT = 401, HICOLLIE_WRONG_THREAD_CONTEXT = 29800001, HICOLLIE_REMOTE_FAILED = 29800002,<br>HICOLLIE_INVALID_TIMER_NAME = 29800003, HICOLLIE_INVALID_TIMEOUT_VALUE = 29800004, HICOLLIE_WRONG_PROCESS_CONTEXT = 29800005, HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM = 29800006<br>} | Enumerates the error codes used in the HiCollie module. | 
| [HiCollie_Flag](#hicollie_flag) { HICOLLIE_FLAG_DEFAULT = (~0), **HICOLLIE_FLAG_NOOP** = (0), **HICOLLIE_FLAG_LOG** = (1 &lt;&lt; 0), **HICOLLIE_FLAG_RECOVERY** = (1 &lt;&lt; 1) } | Enumerates the executions to be performed when a function times out. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [HiCollie_ErrorCode](#hicollie_errorcode) [OH_HiCollie_Init_StuckDetection](#oh_hicollie_init_stuckdetection) ([OH_HiCollie_Task](#oh_hicollie_task) task) | Registers a callback used to periodically detect service thread stuck events.  <br>By default, the **BUSSINESS_THREAD_BLOCK_3S** event is reported when the thread is blocked for 3s and the **BUSSINESS_THREAD_BLOCK_6S** event is reported when the thread is blocked for 6s.| 
| [HiCollie_ErrorCode](#hicollie_errorcode) [OH_HiCollie_Init_StuckDetectionWithTimeout](#oh_hicollie_init_stuckdetectionwithtimeout) ([OH_HiCollie_Task](#oh_hicollie_task) task, uint32_t stuckTimeout) | Registers a callback used to periodically detect service thread stuck events.  <br>You can set the interval for the stuck event detection. The value range is [3, 15], in seconds.| 
| [HiCollie_ErrorCode](#hicollie_errorcode) [OH_HiCollie_Init_JankDetection](#oh_hicollie_init_jankdetection) ([OH_HiCollie_BeginFunc](#oh_hicollie_beginfunc) \*beginFunc, [OH_HiCollie_EndFunc](#oh_hicollie_endfunc) \*endFunc, [HiCollie_DetectionParam](_hi_collie___detection_param.md) param) | Registers a callback used to detect service thread jank events.<br>To monitor service thread jank events, you can implement two callbacks as instrumentation functions, placing them before and after the service thread event.  | 
| [HiCollie_ErrorCode](#hicollie_errorcode) [OH_HiCollie_Report](#oh_hicollie_report) (bool \*isSixSecond) | Reports a service thread stuck event and generates logs to help locate application stuck issues.<br>Call **OH_HiCollie_Init_StuckDetection()** or **OH_HiCollie_Init_StuckDetectionWithTimeout()** to initialize the detection task.<br>If the task times out, call **OH_HiCollie_Report()** to report the stuck event based on the service logic.| 
| [HiCollie_ErrorCode](#hicollie_errorcode) [OH_HiCollie_SetTimer](#oh_hicollie_settimer) ([HiCollie_SetTimerParam](_hi_collie___set_timer_param.md) param, int \*id) | Registers a timer to check whether the execution time of a function or code block exceeds the custom time.<br>This API is used together with the **OH_HiCollie_CancelTimer** API.| 
| void [OH_HiCollie_CancelTimer](#oh_hicollie_canceltimer) (int id) | Cancels a timer based on the ID.<br>This API is used together with the **OH_HiCollie_SetTimer** API. It must be used after the function or code block is executed.<br>If a timer is not canceled within the custom time, a callback function is executed to generate fault logs for the specified timeout event.| 


## Type Description


### HiCollie_DetectionParam

```
typedef struct HiCollie_DetectionParamHiCollie_DetectionParam
```
**Description**
Defines a struct for the parameters of the jank event detection. Note that this type is supported since API 12.

**Since**: 12


### HiCollie_ErrorCode

```
typedef enum HiCollie_ErrorCodeHiCollie_ErrorCode
```
**Description**
Defines an enum for the error codes used in the HiCollie module.

**Since**: 12


### HiCollie_Flag

```
typedef enum HiCollie_FlagHiCollie_Flag
```
**Description**
Defines an enum for the executions to be performed when a function times out.

**Since**: 18


### HiCollie_SetTimerParam

```
typedef struct HiCollie_SetTimerParamHiCollie_SetTimerParam
```
**Description**
Defines a struct for the input parameters of the **OH_HiCollie_SetTimer** function.

**Since**: 18


### OH_HiCollie_BeginFunc

```
typedef void(* OH_HiCollie_BeginFunc) (const char *eventName)
```
**Description**
Defines a function used to record the begin time when a service thread processes an event. This function is used in the jank event detection.

HiCollie checks the duration of each event. If the duration exceeds the preset threshold, a jank event is reported.

This function is inserted before each event is processed.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| eventName | Name of the service thread event. | 


### OH_HiCollie_Callback

```
typedef void(* OH_HiCollie_Callback) (void *)
```
**Description**
Defines a callback function to be executed when [OH_HiCollie_CancelTimer](#oh_hicollie_canceltimer) is not called within the custom task timeout period after [OH_HiCollie_SetTimer](#oh_hicollie_settimer)) is called.

**Since**: 18


### OH_HiCollie_EndFunc

```
typedef void(* OH_HiCollie_EndFunc) (const char *eventName)
```
**Description**
Defines a function used to check whether a service thread is janky when processing an event. This function is used in the jank event detection.

HiCollie checks the duration of each event. If the duration exceeds the preset threshold, a jank event is reported.

This function is inserted after each event is processed.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| eventName | Name of the service thread event. | 


### OH_HiCollie_Task

```
typedef void(* OH_HiCollie_Task) (void)
```
**Description**
Defines a function used to check whether a service thread is stuck.

This function is called by HiCollie every 3 seconds in an independent thread.

For example, this function can be used to send a message to a service thread and set a flag after the service thread receives the message. Then the flag is checked to determine whether the service thread is stuck.

**Since**: 12


## Enum Description


### HiCollie_ErrorCode

```
enum HiCollie_ErrorCode
```
**Description**
Enumerates the error codes used in the HiCollie module.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| HICOLLIE_SUCCESS  | The operation is successful.&nbsp;&nbsp; | 
| HICOLLIE_INVALID_ARGUMENT  | The parameter is invalid.&nbsp;&nbsp; | 
| HICOLLIE_WRONG_THREAD_CONTEXT  | The called thread is incorrect.&nbsp;&nbsp; | 
| HICOLLIE_REMOTE_FAILED  | The remote call fails.&nbsp;&nbsp; | 
| HICOLLIE_INVALID_TIMER_NAME  | The timer name is invalid.<br>**Since**: 18| 
| HICOLLIE_INVALID_TIMEOUT_VALUE  | The function execution timeout value is invalid.<br>**Since**: 18| 
| HICOLLIE_WRONG_PROCESS_CONTEXT  | The process to be accessed is incorrect.<br>**Since**: 18| 
| HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM  | The pointer used to save the returned timer ID is null.<br>**Since**: 18| 


### HiCollie_Flag

```
enum HiCollie_Flag
```
**Description**
Enumerates the executions to be performed when a function times out.

**Since**: 18

| Value| Description| 
| -------- | -------- |
| HICOLLIE_FLAG_DEFAULT  | Generates logs and locates, kills, and recovers the process. This is the default value.&nbsp;&nbsp; | 


## Function Description


### OH_HiCollie_CancelTimer()

```
void OH_HiCollie_CancelTimer (int id)
```
**Description**
Cancels a timer based on the ID.

This API is used together with the **OH_HiCollie_SetTimer** API. It must be used after the function or code block is executed.

If a timer is not canceled within the custom time, a callback function is executed to generate fault logs for the specified timeout event.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| id | Timer ID updated after the [OH_HiCollie_SetTimer](#oh_hicollie_settimer) function is executed. | 


### OH_HiCollie_Init_JankDetection()

```
HiCollie_ErrorCode OH_HiCollie_Init_JankDetection (OH_HiCollie_BeginFunc * beginFunc, OH_HiCollie_EndFunc * endFunc, HiCollie_DetectionParam param )
```
**Description**
Registers a callback used to detect service thread jank events.

To monitor service thread jank events, you can implement two callbacks as instrumentation functions, placing them before and after the service thread event.  

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| beginFunc | The function used before the service thread event detection. | 
| endFunc | The function used after the service thread event detection. | 
| param | The extended parameter provided for subsequent development. | 

**Returns**

**HICOLLIE_SUCCESS 0** - The operation is successful.

**HICOLLIE_INVALID_ARGUMENT 401** - The parameter is invalid. Both the begin and end functions must have values or be empty. Otherwise, this error code is returned.

**HICOLLIE_WRONG_THREAD_CONTEXT 29800001** - The called thread is incorrect. This function should be called in a non-main thread.

For details, see [HiCollie_ErrorCode](#hicollie_errorcode).


### OH_HiCollie_Init_StuckDetection()

```
HiCollie_ErrorCode OH_HiCollie_Init_StuckDetection (OH_HiCollie_Task task)
```
**Description**
Registers a callback used to periodically detect service thread stuck events.  

By default, the **BUSSINESS_THREAD_BLOCK_3S** event is reported when the thread is blocked for 3s and the **BUSSINESS_THREAD_BLOCK_6S** event is reported when the thread is blocked for 6s.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| task | A periodic detection task that is executed every 3 seconds to check whether a service thread is stuck. | 

**Returns**

**HICOLLIE_SUCCESS 0** - The operation is successful.

**HICOLLIE_WRONG_THREAD_CONTEXT 29800001** - The called thread is incorrect. This function should be called in a non-main thread.

For details, see [HiCollie_ErrorCode](#hicollie_errorcode).


### OH_HiCollie_Init_StuckDetectionWithTimeout()

```
HiCollie_ErrorCode OH_HiCollie_Init_StuckDetectionWithTimeout (OH_HiCollie_Task task, uint32_t stuckTimeout )
```
**Description**
Registers a callback used to periodically detect service thread stuck events.  

You can set the interval for the stuck event detection. The value range is [3, 15], in seconds.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| task | A periodic detection task that is executed every **stuckTimeout** time to check whether a service thread is stuck. | 
| stuckTimeout | Threshold for reporting a service thread stuck event, in seconds. When the task execution time exceeds the value of **stuckTimeout**, a stuck warning event is reported. When the task execution time exceeds twice the value of **stuckTimeout**, a stuck event is reported.<br> The maximum value is **15s** and the minimum value is **3s**.| 

**Returns**

**HICOLLIE_SUCCESS 0** - The operation is successful.

**HICOLLIE_INVALID_ARGUMENT 401** - The threshold value is incorrect.

**HICOLLIE_WRONG_THREAD_CONTEXT 29800001** - The called thread is incorrect. This function should be called in a non-main thread.

For details, see [HiCollie_ErrorCode](#hicollie_errorcode).


### OH_HiCollie_Report()

```
HiCollie_ErrorCode OH_HiCollie_Report (bool * isSixSecond)
```
**Description**
Reports a service thread stuck event and generates logs to help locate application stuck issues.

Call **OH_HiCollie_Init_StuckDetection()** or **OH_HiCollie_Init_StuckDetectionWithTimeout()** to initialize the detection task.

If the task times out, call **OH_HiCollie_Report()** to report the stuck event based on the service logic.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| isSixSecond | Pointer to a Boolean value.  If the service thread is stuck for 6s, the value is **true**. If the service thread is stuck for 3s, the value is **false**. | 

**Returns**

**HICOLLIE_SUCCESS 0** - The operation is successful.

**HICOLLIE_INVALID_ARGUMENT 401** - The parameter is invalid. Both the begin and end functions must have values or be empty. Otherwise, this error code is returned.

**HICOLLIE_WRONG_THREAD_CONTEXT 29800001** - The called thread is incorrect. This function should be called in a non-main thread.

**HICOLLIE_REMOTE_FAILED 29800002** - The remote call fails. The IPC remote service fails to be called.

For details, see [HiCollie_ErrorCode](#hicollie_errorcode).


### OH_HiCollie_SetTimer()

```
HiCollie_ErrorCode OH_HiCollie_SetTimer (HiCollie_SetTimerParam param, int * id )
```
**Description**
Registers a timer to check whether the execution time of a function or code block exceeds the custom time.

This API is used together with the **OH_HiCollie_CancelTimer** API.

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| param | Input parameters. For details, see [HiCollie_SetTimerParam](#hicollie_settimerparam).| 
| id | Pointer to the returned timer ID, which cannot be null. | 

**Returns**

**HICOLLIE_SUCCESS 0** - The operation is successful.

**HICOLLIE_INVALID_TIMER_NAME 29800003** - The timer name is invalid. It cannot be null or an empty string.

**HICOLLIE_INVALID_TIMEOUT_VALUE 29800004** - The timeout value is invalid.

**HICOLLIE_WRONG_PROCESS_CONTEXT 29800005** - The accessed detection process context is invalid. This function cannot be called in the appspawn and nativespawn processes.

**HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM 29800006** - The pointer to the returned timer ID is invalid. The value cannot be null.

For details, see [HiCollie_ErrorCode](#hicollie_errorcode).
