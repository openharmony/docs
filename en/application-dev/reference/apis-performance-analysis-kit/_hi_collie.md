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
| struct&nbsp;&nbsp;[HiCollie_DetectionParam](_hi_collie___detection_param.md) | Defines the parameters of the service thread jank event detection. Note that these parameters are deprecated in API version 12 and reserved for extension only. |


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [HiCollie_ErrorCode](#hicollie_errorcode) [HiCollie_ErrorCode](#hicollie_errorcode) | Defines an enum for the error codes used in the HiCollie module. |
| typedef void(\* [OH_HiCollie_Task](#oh_hicollie_task)) (void) | Defines a function used to check whether a service thread is stuck.<br>This function is called by HiCollie every 3 seconds in an independent thread.<br>For example, this function can send messages to service threads. When a service thread receives a message, a flag is set. By checking the flag, HiCollie can determine whether a service thread is stuck.|
| typedef void(\* [OH_HiCollie_BeginFunc](#oh_hicollie_beginfunc)) (const char \*eventName) | Defines a function used to record the start time of the service thread event during jank event detection. This function is used before event processing. |
| typedef void(\* [OH_HiCollie_EndFunc](#oh_hicollie_endfunc)) (const char \*eventName) | Defines a function used to check whether a service thread is janky during event processing. This function is used after event processing.<br>By checking the execution duration of the processing events, HiCollie determines the duration of each event. If the duration is greater than 150 ms but less than 450 ms, a jank event is reported.|
| typedef struct [HiCollie_DetectionParam](_hi_collie___detection_param.md) [HiCollie_DetectionParam](#hicollie_detectionparam) | Defines a struct for the parameters of the service thread jank event detection. Note that these parameters are deprecated in API version 12 and reserved for extension only. |


### Enums

| Name| Description|
| -------- | -------- |
| [HiCollie_ErrorCode](#hicollie_errorcode) { HICOLLIE_SUCCESS = 0, HICOLLIE_INVALID_ARGUMENT = 401, HICOLLIE_WRONG_THREAD_CONTEXT = 29800001, HICOLLIE_REMOTE_FAILED = 29800002 } | Enumerates the error codes used in the HiCollie module.  | 


### Functions

| Name| Description|
| -------- | -------- |
| [HiCollie_ErrorCode](#hicollie_errorcode) [OH_HiCollie_Init_StuckDetection](#oh_hicollie_init_stuckdetection) ([OH_HiCollie_Task](#oh_hicollie_task) task) | Registers a callback used to periodically detect service thread stuck events.   |
| [HiCollie_ErrorCode](#hicollie_errorcode) [OH_HiCollie_Init_JankDetection](#oh_hicollie_init_jankdetection) ([OH_HiCollie_BeginFunc](#oh_hicollie_beginfunc) \*beginFunc, [OH_HiCollie_EndFunc](#oh_hicollie_endfunc) \*endFunc, [HiCollie_DetectionParam](_hi_collie___detection_param.md) param) | Registers a callback used to detect service thread jank events.<br>To monitor service thread jank events, you can implement two callbacks as instrumentation functions, placing them before and after the service thread event.  |
| [HiCollie_ErrorCode](#hicollie_errorcode) [OH_HiCollie_Report](#oh_hicollie_report) (bool \*isSixSecond) | Reports a service thread stuck event and generates timeout logs to help locate application timeout events.<br>This API is used together with **OH_HiCollie_Init_StuckDetection()**, which initializes the stuck event detection at first, and then **OH_HiCollie_Report()** reports the stuck event when it occurs.|


## Type Description


### HiCollie_DetectionParam

```
typedef struct HiCollie_DetectionParamHiCollie_DetectionParam
```
**Description**
Defines a struct for the parameters of the service thread jank event detection. Note that these parameters are deprecated in API version 12 and reserved for extension only.

**Since**: 12


### HiCollie_ErrorCode

```
typedef enum HiCollie_ErrorCode HiCollie_ErrorCode
```
**Description**
Defines an enum for the error codes used in the HiCollie module.

**Since**: 12


### OH_HiCollie_BeginFunc

```
typedef void (*OH_HiCollie_BeginFunc)(const char* eventName)
```
**Description**
Defines a function used to record the start time of the service thread event during jank event detection. This function is used before event processing.

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
Defines a function used to check whether a service thread is janky during event processing. This function is used after event processing.

By checking the execution duration of the processing events, HiCollie determines the duration of each event. If the duration is greater than 150 ms but less than 450 ms, a jank event is reported.

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

For example, this function can send messages to service threads. When a service thread receives a message, a flag is set. By checking the flag, HiCollie can determine whether a service thread is stuck.

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
| HICOLLIE_INVALID_ARGUMENT  | The parameter is invalid. Possible causes: 1. The parameter value is incorrect. 2. The parameter type is incorrect.&nbsp;&nbsp; | 
| HICOLLIE_WRONG_THREAD_CONTEXT  | This function is not called in a service thread.&nbsp;&nbsp; | 
| HICOLLIE_REMOTE_FAILED  | The remote call fails.&nbsp;&nbsp; | 


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

**HICOLLIE_WRONG_THREAD_CONTEXT 29800001** - The called thread is incorrect. This function cannot be called from the main thread.


### OH_HiCollie_Init_StuckDetection()

```
HiCollie_ErrorCode OH_HiCollie_Init_StuckDetection (OH_HiCollie_Task task)
```
**Description**
Registers a callback used to periodically detect service thread stuck events.  

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| task | A periodic detection task that is executed every 3 seconds to check whether a service thread is stuck. |

**Returns**

**HICOLLIE_SUCCESS 0** - The operation is successful.

**HICOLLIE_WRONG_THREAD_CONTEXT 29800001** - The called thread is incorrect. This function cannot be called from the main thread.


### OH_HiCollie_Report()

```
HiCollie_ErrorCode OH_HiCollie_Report (bool * isSixSecond)
```
**Description**
Reports a service thread stuck event and generates timeout logs to help locate application timeout events.

This API is used together with **OH_HiCollie_Init_StuckDetection()**, which initializes the stuck event detection at first, and then **OH_HiCollie_Report()** reports the stuck event when it occurs.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| isSixSecond | Pointer to a Boolean value.  If the service thread is stuck for 6s, the value is **true**. If the service thread is stuck for 3s, the value is **false**. |

**Returns**

**HICOLLIE_SUCCESS 0** - The operation is successful.

**HICOLLIE_INVALID_ARGUMENT 401** - The parameter is invalid. Both the begin and end functions must have values or be empty. Otherwise, this error code is returned.

**HICOLLIE_WRONG_THREAD_CONTEXT 29800001** - The called thread is incorrect. This function cannot be called from the main thread.

**HICOLLIE_REMOTE_FAILED 29800002** - The remote call fails.
