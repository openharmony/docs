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


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [HiCollie_ErrorCode](#hicollie_errorcode) [HiCollie_ErrorCode](#hicollie_errorcode) | Defines an enum for the error codes used in the HiCollie module. | 
| typedef void(\* [OH_HiCollie_Task](#oh_hicollie_task)) (void) | Defines a function used to check whether a service thread is stuck.<br>This function is called by HiCollie every 3 seconds in an independent thread.<br>For example, this function can be used to send a message to a service thread and set a flag after the service thread receives the message. Then the flag is checked to determine whether the service thread is stuck.| 
| typedef void(\* [OH_HiCollie_BeginFunc](#oh_hicollie_beginfunc)) (const char \*eventName) | Defines a function used to record the begin time when a service thread processes an event. This function is used in the jank event detection.<br>HiCollie checks the duration of each event. If the duration exceeds the preset threshold, a jank event is reported.<br>This function is inserted before each event is processed.| 
| typedef void(\* [OH_HiCollie_EndFunc](#oh_hicollie_endfunc)) (const char \*eventName) | Defines a function used to check whether a service thread is janky when processing an event. This function is used in the jank event detection.<br>HiCollie checks the duration of each event. If the duration exceeds the preset threshold, a jank event is reported.<br>This function is inserted after each event is processed.| 
| typedef struct [HiCollie_DetectionParam](_hi_collie___detection_param.md) [HiCollie_DetectionParam](#hicollie_detectionparam) | Defines a struct for the parameters of the jank event detection. Note that this type is supported since API 12. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [HiCollie_ErrorCode](#hicollie_errorcode) {<br/>HICOLLIE_SUCCESS = 0, <br/>HICOLLIE_INVALID_ARGUMENT = 401, <br/>HICOLLIE_WRONG_THREAD_CONTEXT = 29800001, <br/>HICOLLIE_REMOTE_FAILED = 29800002<br/>} | Enumerates the error codes used in the HiCollie module. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [HiCollie_ErrorCode](#hicollie_errorcode) [OH_HiCollie_Init_StuckDetection](#oh_hicollie_init_stuckdetection) ([OH_HiCollie_Task](#oh_hicollie_task) task) | Registers a callback used to periodically detect service thread stuck events.  <br>By default, the **BUSSINESS_THREAD_BLOCK_3S** event is reported when the thread is blocked for 3s and the **BUSSINESS_THREAD_BLOCK_6S** event is reported when the thread is blocked for 6s.| 
| [HiCollie_ErrorCode](#hicollie_errorcode) [OH_HiCollie_Init_JankDetection](#oh_hicollie_init_jankdetection) ([OH_HiCollie_BeginFunc](#oh_hicollie_beginfunc) \*beginFunc, [OH_HiCollie_EndFunc](#oh_hicollie_endfunc) \*endFunc, [HiCollie_DetectionParam](_hi_collie___detection_param.md) param) | Registers a callback used to detect service thread jank events.<br>To monitor service thread jank events, you can implement two callbacks as instrumentation functions, placing them before and after the service thread event.  | 
| [HiCollie_ErrorCode](#hicollie_errorcode) [OH_HiCollie_Report](#oh_hicollie_report) (bool \*isSixSecond) | Reports a service thread stuck event and generates logs to help locate application stuck issues.<br>Call **OH_HiCollie_Init_StuckDetection()** or **OH_HiCollie_Init_StuckDetectionWithTimeout()** to initialize the detection task.<br>If the task times out, call **OH_HiCollie_Report()** to report the stuck event based on the service logic.|


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
| HICOLLIE_SUCCESS  | The operation is successful.| 
| HICOLLIE_INVALID_ARGUMENT  | The parameter is invalid. Possible causes: 1. The parameter value is incorrect. 2. The parameter type is incorrect. | 
| HICOLLIE_WRONG_THREAD_CONTEXT  | This function is not called in a service thread.| 
| HICOLLIE_REMOTE_FAILED  | The remote call fails.| 


## Function Description


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
