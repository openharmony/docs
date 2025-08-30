# hicollie.h

## Overview

HiCollie provides APIs for checking service thread stuck and jank events and reporting stuck events.

**File to include**: <hicollie/hicollie.h>

**Library**: libohhicollie.so

**System capability**: SystemCapability.HiviewDFX.HiCollie

**Since**: 12

**Related module**: [HiCollie](capi-hicollie.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [HiCollie_DetectionParam](capi-hicollie-hicollie-detectionparam.md) | HiCollie_DetectionParam | Defines the parameters of the jank event detection. Note that this struct is supported since API 12.|
| [HiCollie_SetTimerParam](capi-hicollie-hicollie-settimerparam.md) | HiCollie_SetTimerParam | Defines the input parameters of the **OH_HiCollie_SetTimer** function.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [HiCollie_ErrorCode](#hicollie_errorcode) | HiCollie_ErrorCode | Enumerates the error codes used in the HiCollie module.|
| [HiCollie_Flag](#hicollie_flag) | HiCollie_Flag | Enumerates the actions to be performed when a function times out.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_HiCollie_Task)(void)](#oh_hicollie_task) | OH_HiCollie_Task | Defines a function used to check whether a service thread is stuck.<br> This function is called by HiCollie every 3 seconds in an independent thread.<br> For example, this function can be used to send a message to a service thread and set a flag after the service thread receives the message. Then the flag is checked to determine whether the service thread is stuck.|
| [typedef void (\*OH_HiCollie_BeginFunc)(const char* eventName)](#oh_hicollie_beginfunc) | OH_HiCollie_BeginFunc | Defines a function used to record the begin time when a service thread processes an event. This function is used in the jank event detection.<br> HiCollie checks the duration of each event. If the duration exceeds the preset threshold, a jank event is reported.<br> This function is inserted before each event is processed.|
| [typedef void (\*OH_HiCollie_EndFunc)(const char* eventName)](#oh_hicollie_endfunc) | OH_HiCollie_EndFunc | Defines a function used to check whether a service thread is janky when processing an event. This function is used in the jank event detection.<br> HiCollie checks the duration of each event. If the duration exceeds the preset threshold, a jank event is reported.<br> This function is inserted after each event is processed.|
| [HiCollie_ErrorCode OH_HiCollie_Init_StuckDetection(OH_HiCollie_Task task)](#oh_hicollie_init_stuckdetection) | - | Registers a callback used to periodically detect service thread stuck events.  <br> By default, the **BUSSINESS_THREAD_BLOCK_3S** event is reported when the thread is blocked for 3s and the **BUSSINESS_THREAD_BLOCK_6S** event is reported when the thread is blocked for 6s.|
| [HiCollie_ErrorCode OH_HiCollie_Init_StuckDetectionWithTimeout(OH_HiCollie_Task task, uint32_t stuckTimeout)](#oh_hicollie_init_stuckdetectionwithtimeout) | - | Registers a callback used to periodically detect service thread stuck events.  <br> You can set the interval for the stuck event detection. The value range is [3, 15], in seconds.|
| [HiCollie_ErrorCode OH_HiCollie_Init_JankDetection(OH_HiCollie_BeginFunc* beginFunc,OH_HiCollie_EndFunc* endFunc, HiCollie_DetectionParam param)](#oh_hicollie_init_jankdetection) | - | Registers a callback used to detect service thread jank events.<br> To monitor service thread jank events, you can implement two callbacks as instrumentation functions, placing them before and after the service thread event.  |
| [HiCollie_ErrorCode OH_HiCollie_Report(bool* isSixSecond)](#oh_hicollie_report) | - | Reports a service thread stuck event and generates logs to help locate application stuck issues.<br> Call **OH_HiCollie_Init_StuckDetection()** or **OH_HiCollie_Init_StuckDetectionWithTimeout()** to initialize the detection task.<br> If the task times out, call **OH_HiCollie_Report()** to report the stuck event based on the service logic.|
| [typedef void (\*OH_HiCollie_Callback)(void*)](#oh_hicollie_callback) | OH_HiCollie_Callback | Triggered when [OH_HiCollie_CancelTimer](capi-hicollie-h.md#oh_hicollie_canceltimer) is not called within the custom task timeout period after [OH_HiCollie_SetTimer](capi-hicollie-h.md#oh_hicollie_settimer) is called.|
| [HiCollie_ErrorCode OH_HiCollie_SetTimer(HiCollie_SetTimerParam param, int *id)](#oh_hicollie_settimer) | - | Registers a timer to check whether the execution time of a function or code block exceeds the custom time.<br> This API is used together with the **OH_HiCollie_CancelTimer** API.|
| [void OH_HiCollie_CancelTimer(int id)](#oh_hicollie_canceltimer) | - | Cancels a timer based on the ID.<br> This API is used together with the **OH_HiCollie_SetTimer** API. It must be used after the function or code block is executed.<br> If a timer is not canceled within the custom time, a callback function is executed to generate fault logs for the specified timeout event.|

## Enum Description

### HiCollie_ErrorCode

```
enum HiCollie_ErrorCode
```

**Description**

Enumerates the error codes used in the HiCollie module.

**Since**: 12

| Enum Item| Description                             |
| -- |---------------------------------|
| HICOLLIE_SUCCESS  = 0 | The operation is successful.                            |
| HICOLLIE_INVALID_ARGUMENT  = 401 | The parameter is invalid.                          |
| HICOLLIE_WRONG_THREAD_CONTEXT = 29800001 | The called thread is incorrect.                        |
| HICOLLIE_REMOTE_FAILED = 29800002 | The remote call fails.                        |
| HICOLLIE_INVALID_TIMER_NAME = 29800003 | The timer name is invalid.<br>**Since**: 18|
| HICOLLIE_INVALID_TIMEOUT_VALUE = 29800004 | The function execution timeout value is invalid.<br>**Since**: 18                 |
| HICOLLIE_WRONG_PROCESS_CONTEXT = 29800005 | The process to be accessed is incorrect.<br>**Since**: 18                |
| HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM = 29800006 | The pointer used to save the returned timer ID is null.<br>**Since**: 18        |

### HiCollie_Flag

```
enum HiCollie_Flag
```

**Description**

Enumerates the actions to be performed when a function times out.

**Since**: 18

| Enum Item| Description|
| -- | -- |
| HICOLLIE_FLAG_DEFAULT = (~0) | Generates logs and locates, kills, and recovers the process. This is the default value.|
| HICOLLIE_FLAG_NOOP = (0) | Executes only the callback.|
| HICOLLIE_FLAG_LOG = (1 << 0) | Generates logs.|
| HICOLLIE_FLAG_RECOVERY = (1 << 1) | Terminates the process and triggers recovery.|


## Function Description

### OH_HiCollie_Task()

```
typedef void (*OH_HiCollie_Task)(void)
```

**Description**

Defines a function used to check whether a service thread is stuck.<br> This function is called by HiCollie every 3 seconds in an independent thread.<br> For example, this function can be used to send a message to a service thread and set a flag after the service thread receives the message. Then the flag is checked to determine whether the service thread is stuck.

**Since**: 12

### OH_HiCollie_BeginFunc()

```
typedef void (*OH_HiCollie_BeginFunc)(const char* eventName)
```

**Description**

Defines a function used to record the begin time when a service thread processes an event. This function is used in the jank event detection.<br> HiCollie checks the duration of each event. If the duration exceeds the preset threshold, a jank event is reported.<br> This function is inserted before each event is processed.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char* eventName | Name of the service thread event.|

### OH_HiCollie_EndFunc()

```
typedef void (*OH_HiCollie_EndFunc)(const char* eventName)
```

**Description**

Defines a function used to check whether a service thread is janky when processing an event. This function is used in the jank event detection.<br> HiCollie checks the duration of each event. If the duration exceeds the preset threshold, a jank event is reported.<br> This function is inserted after each event is processed.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char* eventName | Name of the service thread event.|

### OH_HiCollie_Init_StuckDetection()

```
HiCollie_ErrorCode OH_HiCollie_Init_StuckDetection(OH_HiCollie_Task task)
```

**Description**

Registers a callback used to periodically detect service thread stuck events.  <br> By default, the **BUSSINESS_THREAD_BLOCK_3S** event is reported when the thread is blocked for 3s and the **BUSSINESS_THREAD_BLOCK_6S** event is reported when the thread is blocked for 6s.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_HiCollie_Task](capi-hicollie-h.md#oh_hicollie_task) task | A periodic detection task that is executed every 3 seconds to check whether a service thread is stuck.|

**Returns**

| Type| Description|
| -- | -- |
| [HiCollie_ErrorCode](capi-hicollie-h.md#hicollie_errorcode) | [HICOLLIE_SUCCESS](capi-hicollie-h.md#hicollie_errorcode) 0 - Operation successful.<br>         [HICOLLIE_WRONG_THREAD_CONTEXT](capi-hicollie-h.md#hicollie_errorcode) 29800001 - Incorrect calling thread. This function should be called in a non-main thread.<br>         For details, see [HiCollie_ErrorCode](capi-hicollie-h.md#hicollie_errorcode).|

### OH_HiCollie_Init_StuckDetectionWithTimeout()

```
HiCollie_ErrorCode OH_HiCollie_Init_StuckDetectionWithTimeout(OH_HiCollie_Task task, uint32_t stuckTimeout)
```

**Description**

Registers a callback used to periodically detect service thread stuck events.  <br> You can set the interval for the stuck event detection. The value range is [3, 15], in seconds.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_HiCollie_Task](capi-hicollie-h.md#oh_hicollie_task) task | Periodic detection task that is executed every **stuckTimeout** time to check whether a service thread is stuck.|
| uint32_t stuckTimeout | Threshold for reporting a service thread stuck event, in seconds. When the task execution time exceeds the value of **stuckTimeout**, a stuck warning event is reported. When the task execution time exceeds twice the value of **stuckTimeout**, a stuck event is reported.<br>          The maximum value is **15s** and the minimum value is **3s**.|

**Returns**

| Type| Description|
| -- | -- |
| [HiCollie_ErrorCode](capi-hicollie-h.md#hicollie_errorcode) | [HICOLLIE_SUCCESS](capi-hicollie-h.md#hicollie_errorcode) 0 - Operation successful.<br> 		   [HICOLLIE_INVALID_ARGUMENT](capi-hicollie-h.md#hicollie_errorcode) 401 - Invalid detection time.<br>         [HICOLLIE_WRONG_THREAD_CONTEXT](capi-hicollie-h.md#hicollie_errorcode) 29800001 - Incorrect calling thread. This function should be called in a non-main thread.<br>         For details, see [HiCollie_ErrorCode](capi-hicollie-h.md#hicollie_errorcode).|

### OH_HiCollie_Init_JankDetection()

```
HiCollie_ErrorCode OH_HiCollie_Init_JankDetection(OH_HiCollie_BeginFunc* beginFunc,OH_HiCollie_EndFunc* endFunc, HiCollie_DetectionParam param)
```

**Description**

Registers a callback used to detect service thread jank events.<br> To monitor service thread jank events, you can implement two callbacks as instrumentation functions, placing them before and after the service thread event.  

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_HiCollie_BeginFunc](capi-hicollie-h.md#oh_hicollie_beginfunc)* beginFunc | Function used before the service thread event detection.|
| [OH_HiCollie_EndFunc](capi-hicollie-h.md#oh_hicollie_endfunc)* endFunc | Function used after the service thread event detection.|
| [HiCollie_DetectionParam](capi-hicollie-hicollie-detectionparam.md) param | Extended parameter for future use.|

**Returns**

| Type| Description|
| -- | -- |
| [HiCollie_ErrorCode](capi-hicollie-h.md#hicollie_errorcode) | [HICOLLIE_SUCCESS](capi-hicollie-h.md#hicollie_errorcode) 0 - Operation successful.<br> 		   [HICOLLIE_INVALID_ARGUMENT](capi-hicollie-h.md#hicollie_errorcode) 401 - The begin and end functions are not both set or both unset; they must either both have valid values or both be empty.<br>         [HICOLLIE_WRONG_THREAD_CONTEXT](capi-hicollie-h.md#hicollie_errorcode) 29800001 - Incorrect calling thread. This function should be called in a non-main thread.<br>         For details, see [HiCollie_ErrorCode](capi-hicollie-h.md#hicollie_errorcode).|

### OH_HiCollie_Report()

```
HiCollie_ErrorCode OH_HiCollie_Report(bool* isSixSecond)
```

**Description**

Reports a service thread stuck event and generates logs to help locate application stuck issues.<br> Call **OH_HiCollie_Init_StuckDetection()** or **OH_HiCollie_Init_StuckDetectionWithTimeout()** to initialize the detection task.<br> If the task times out, call **OH_HiCollie_Report()** to report the stuck event based on the service logic.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| bool* isSixSecond | Pointer to a Boolean value.  If the service thread is stuck for 6s, the value is **true**. If the service thread is stuck for 3s, the value is **false**.|

**Returns**

| Type| Description|
| -- | -- |
| [HiCollie_ErrorCode](capi-hicollie-h.md#hicollie_errorcode) | [HICOLLIE_SUCCESS](capi-hicollie-h.md#hicollie_errorcode) 0 - Operation successful.<br> 		   [HICOLLIE_INVALID_ARGUMENT](capi-hicollie-h.md#hicollie_errorcode) 401 - The begin and end functions are not both set or both unset; they must either both have valid values or both be empty.<br>         [HICOLLIE_WRONG_THREAD_CONTEXT](capi-hicollie-h.md#hicollie_errorcode) 29800001 - Incorrect calling thread. This function should be called in a non-main thread.<br>         [HICOLLIE_REMOTE_FAILED](capi-hicollie-h.md#hicollie_errorcode) 29800002 - Remote call error. The IPC remote service fails to be called.<br>         For details, see [HiCollie_ErrorCode](capi-hicollie-h.md#hicollie_errorcode).|

### OH_HiCollie_Callback()

```
typedef void (*OH_HiCollie_Callback)(void*)
```

**Description**

Triggered when [OH_HiCollie_CancelTimer](capi-hicollie-h.md#oh_hicollie_canceltimer) is not called within the custom task timeout period after [OH_HiCollie_SetTimer](capi-hicollie-h.md#oh_hicollie_settimer) is called.

**Since**: 18

### OH_HiCollie_SetTimer()

```
HiCollie_ErrorCode OH_HiCollie_SetTimer(HiCollie_SetTimerParam param, int *id)
```

**Description**

Registers a timer to check whether the execution time of a function or code block exceeds the custom time.<br> This API is used together with the **OH_HiCollie_CancelTimer** API.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [HiCollie_SetTimerParam](capi-hicollie-hicollie-settimerparam.md) param | Input parameters.|
| int *id | Pointer to the returned timer ID, which cannot be null.|

**Returns**

| Type| Description|
| -- | -- |
| [HiCollie_ErrorCode](capi-hicollie-h.md#hicollie_errorcode) | [HICOLLIE_SUCCESS](capi-hicollie-h.md#hicollie_errorcode) 0 - Operation successful.<br> 		   [HICOLLIE_INVALID_TIMER_NAME](capi-hicollie-h.md#hicollie_errorcode) 29800003 - Invalid timer name. The timer name cannot be NULL or an empty string.<br>         [HICOLLIE_INVALID_TIMEOUT_VALUE](capi-hicollie-h.md#hicollie_errorcode) 29800004 - Invalid timeout value.<br>         [HICOLLIE_WRONG_PROCESS_CONTEXT](capi-hicollie-h.md#hicollie_errorcode) 29800005 - Invalid process context for detection. This function cannot be called in the **appspawn** and **nativespawn** processes.<br>         [HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM](capi-hicollie-h.md#hicollie_errorcode) 29800006 - The pointer used to save the returned timer ID is NULL.<br>         For details, see [HiCollie_ErrorCode](capi-hicollie-h.md#hicollie_errorcode).|

### OH_HiCollie_CancelTimer()

```
void OH_HiCollie_CancelTimer(int id)
```

**Description**

Cancels a timer based on the ID.<br> This API is used together with the **OH_HiCollie_SetTimer** API. It must be used after the function or code block is executed.<br> If a timer is not canceled within the custom time, a callback function is executed to generate fault logs for the specified timeout event.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| int id | Timer ID updated after the [OH_HiCollie_SetTimer](capi-hicollie-h.md#oh_hicollie_settimer) function is executed.|
