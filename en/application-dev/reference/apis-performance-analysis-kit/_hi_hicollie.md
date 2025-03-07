# HiCollie

## Overview

Provides the APIs for detecting service thread jank and stuck events. Note that these APIs must be called in non-service threads.

The following capabilities are supported: (1) Register a periodic detection task for application service thread stuck events; (2) Register a callback for the detection of application service thread jank events; (3) Report application service thread stuck events.

**System capability**: SystemCapability.HiviewDFX.HiCollie

**Since**: 12


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [hicollie.h](hicollie_8h.md) | HiCollie provides APIs for detecting service thread stuck and jank events and reporting stuck events. |

### Structs

| Name| Description|
| -------- | -------- |
| struct&nbsp;&nbsp;[HiCollie_DetectionParam](_hi_hicollie___detection_param.md) | Defines the parameters of the service thread jank event detection. Note that these parameters are deprecated in API version 12 and reserved for extension only. |
| struct&nbsp;&nbsp;[HiCollie_SetTimerParam](_hi_hicollie___set_timer_param.md) | Defines the parameters of the **OH_HiCollie_SetTimer** function. |

### Types

| Name| Description|
| -------- | -------- |
| typedef enum [HiCollie_ErrorCode](#hicollie_errorcode)[HiCollie_ErrorCode](#hicollie_errorcode) | Defines an enum for the error codes used in the HiCollie module. |
| typedef void(\* [OH_HiCollie_Task](#oh_hicollie_task)) (void) | Defines a function to check whether a stuck event occurs in a service thread. This function is called by HiCollie every 3 seconds in an independent thread. For example, this function can send messages to service threads. When a service thread receives a message, a flag is set. By checking the flag, you can determine whether a stuck event occurs in the service thread. |
| typedef void(\* [OH_HiCollie_BeginFunc](#oh_hicollie_beginfunc)) (const char \*eventName) | Defines a function to record the start time of event processing in the service thread during jank event detection. This function is used before event processing. |
| typedef void(\* [OH_HiCollie_EndFunc](#oh_hicollie_endfunc)) (const char \*eventName) | Defines a function to check whether a jank event occurs in a service thread during event processing. This function is used after event processing. By checking the execution duration of the processing events, HiCollie determines the duration of each event. If the execution duration is greater than 150 ms but less than 450 ms, a jank event is reported. |
| typedef struct [HiCollie_DetectionParam](_hi_hicollie___detection_param.md)[HiCollie_DetectionParam](#hicollie_detectionparam) | Defines a struct for the parameters of the service thread jank event detection. Note that these parameters are deprecated in API version 12 and reserved for extension only. |
| typedef void(\* [OH_HiCollie_Callback](#oh_hicollie_callback)) (void \*) | Defines a function for timeout detection. |
| typedef enum [HiCollie_Flag](#hicollie_flag)[HiCollie_Flag](#hicollie_flag) | Defines an enum for the executions to be performed when a function times out. |
| typedef struct [HiCollie_SetTimerParam](_hi_hicollie___set_timer_param.md)[HiCollie_SetTimerParam](#hicollie_settimerparam) | Defines a struct for the parameters of the **OH_HiCollie_SetTimer** function. |

### Enums

| Name| Description|
| -------- | -------- |
| [HiCollie_ErrorCode](#hicollie_errorcode) {<br>HICOLLIE_SUCCESS = 0, HICOLLIE_INVALID_ARGUMENT = 401, HICOLLIE_WRONG_THREAD_CONTEXT = 29800001, HICOLLIE_REMOTE_FAILED = 29800002,<br>HICOLLIE_INVALID_TIMER_NAME = 29800003, HICOLLIE_INVALID_TIMEOUT_VALUE = 29800004, HICOLLIE_WRONG_PROCESS_CONTEXT = 29800005, HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM = 29800006<br>} | Enumerates the error codes used in the HiCollie module. |
| [HiCollie_Flag](#hicollie_flag) { HICOLLIE_FLAG_DEFAULT = (~0), **HICOLLIE_FLAG_NOOP** = (0), **HICOLLIE_FLAG_LOG** = (1 &lt;&lt; 0), **HICOLLIE_FLAG_RECOVERY** = (1 &lt;&lt; 1) } | Enumerates the executions to be performed when a function times out. |

### Functions

| Name| Description|
| -------- | -------- |
| [HiCollie_ErrorCode](#hicollie_errorcode)[OH_HiCollie_Init_StuckDetection](#oh_hicollie_init_stuckdetection) ([OH_HiCollie_Task](#oh_hicollie_task) task) | Registers a callback to periodically detect service thread stuck events. |
| [HiCollie_ErrorCode](#hicollie_errorcode)[OH_HiCollie_Init_JankDetection](#oh_hicollie_init_jankdetection) ([OH_HiCollie_BeginFunc](#oh_hicollie_beginfunc) \*beginFunc, [OH_HiCollie_EndFunc](#oh_hicollie_endfunc) \*endFunc, [HiCollie_DetectionParam](_hi_hicollie___detection_param.md) param) | Registers a callback to detect service thread jank events. |
| [HiCollie_ErrorCode](#hicollie_errorcode)[OH_HiCollie_Report](#oh_hicollie_report) (bool \*isSixSecond) | Reports an application service thread stuck event. |
| [HiCollie_ErrorCode](#hicollie_errorcode)[OH_HiCollie_SetTimer](#oh_hicollie_settimer) ([HiCollie_SetTimerParam](_hi_hicollie___set_timer_param.md) param, int \*id) | Sets a timer before a time-consuming function is called. |
| void [OH_HiCollie_CancelTimer](#oh_hicollie_canceltimer) (int id) | Cancels a timer based on the timer ID. |

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


### HiCollie_Flag

```
typedef enum HiCollie_Flag HiCollie_Flag
```

**Description**

Defines an enum for the executions to be performed when a function times out.

**Since**: 16

### HiCollie_SetTimerParam

```
typedef struct HiCollie_SetTimerParamHiCollie_SetTimerParam
```

**Description**

Defines a struct for the parameters of the **OH_HiCollie_SetTimer** function.

**Since**: 16

### OH_HiCollie_BeginFunc

```
typedef void (*OH_HiCollie_BeginFunc)(const char* eventName)
```

**Description**

Defines a function to record the start time of event processing in the service thread during jank event detection. This function is used before event processing.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| eventName | Name of the event processed in the service thread. |

### OH_HiCollie_Callback

```
typedef void(* OH_HiCollie_Callback) (void *)
```

**Description**

Defines a function for timeout detection.

**Since**: 16

### OH_HiCollie_EndFunc

```
typedef void(* OH_HiCollie_EndFunc) (const char *eventName)
```

**Description**

Defines a function to check whether a jank event occurs in a service thread during event processing. This function is used after event processing. By checking the execution duration of the processing events, HiCollie determines the duration of each event. If the execution duration is greater than 150 ms but less than 450 ms, a jank event is reported.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| eventName | Name of the processing event in a service thread. |

### OH_HiCollie_Task

```
typedef void(* OH_HiCollie_Task) (void)
```

**Description**

Defines a function to check whether a stuck event occurs in a service thread. This function is called by HiCollie every 3 seconds in an independent thread. For example, this function can send messages to service threads. When a service thread receives a message, a flag is set. By checking the flag, you can determine whether a stuck event occurs in the service thread.

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
| HICOLLIE_WRONG_THREAD_CONTEXT  | The detection is called in an incorrect thread. Possible cause: The detection is called in a service thread.&nbsp;&nbsp; |
| HICOLLIE_REMOTE_FAILED  | The remote calling fails.&nbsp;&nbsp; |
| HICOLLIE_INVALID_TIMER_NAME  | The timer name is invalid.<br>**Since**: 16|
| HICOLLIE_INVALID_TIMEOUT_VALUE  | The function execution timeout value is invalid.<br>**Since**: 16|
| HICOLLIE_WRONG_PROCESS_CONTEXT  | The process to be accessed is incorrect.<br>**Since**: 16|
| HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM  | The timer ID is incorrect.<br>**Since**: 16|

### HiCollie_Flag

```
enum HiCollie_Flag
```

**Description**

Enumerates the executions to be performed when a function times out.

**Since**: 16

| Value| Description|
| -------- | -------- |
| HICOLLIE_FLAG_DEFAULT  | Generates logs, locates and kills the process, and recovers the process. This is the default value.&nbsp;&nbsp; |
| HICOLLIE_FLAG_NOOP  | Executes only the callback.&nbsp;&nbsp; |
| HICOLLIE_FLAG_LOG  | Generates logs.&nbsp;&nbsp; |
| HICOLLIE_FLAG_RECOVERY  | Locates and kills the process, and recovers it.&nbsp;&nbsp; |

## Function Description

### OH_HiCollie_CancelTimer()

```
void OH_HiCollie_CancelTimer (int id)
```

**Description**

Cancels a timer based on the timer ID.

**Since**: 16

**Parameters**

| Name| Description|
| -------- | -------- |
| id | Timer ID updated after the [OH_HiCollie_SetTimer](#oh_hicollie_settimer) function is executed. You can cancel a timer task based on this ID. |

### OH_HiCollie_Init_JankDetection()

```
HiCollie_ErrorCode OH_HiCollie_Init_JankDetection (OH_HiCollie_BeginFunc * beginFunc, OH_HiCollie_EndFunc * endFunc, HiCollie_DetectionParam param )
```

**Description**

Registers a callback to detect service thread jank events.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| beginFunc | The function used before the service thread event detection. |
| endFunc | The function used after the service thread event detection. |
| param | The extended parameter provided for subsequent development. |

**Returns**

**HICOLLIE_SUCCESS 0** - The operation is successful. **HICOLLIE_INVALID_ARGUMENT 401** - The parameter is invalid. Both the begin and end functions must have values or be empty. Otherwise, this error code is returned. **HICOLLIE_WRONG_THREAD_CONTEXT 29800001** - The calling thread is incorrect. This function cannot be called from the main thread.

### OH_HiCollie_Init_StuckDetection()

```
HiCollie_ErrorCode OH_HiCollie_Init_StuckDetection (OH_HiCollie_Task task)
```

**Description**

Registers a callback to periodically detect service thread stuck events.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| task | A periodic detection task that is executed every 3 seconds to check whether a stuck event occurs in a service thread. |

**Returns**

**HICOLLIE_SUCCESS 0** - The operation is successful. **HICOLLIE_WRONG_THREAD_CONTEXT 29800001** - The calling thread is incorrect. This function cannot be called from the main thread.

### OH_HiCollie_Report()

```
HiCollie_ErrorCode OH_HiCollie_Report (bool * isSixSecond)
```

**Description**

Reports an application service thread stuck event.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| isSixSecond | Pointer to a Boolean value.  If the service thread is stuck for 6s, the value is **true**. If the service thread is stuck for 3s, the value is **false**. |

**Returns**

**HICOLLIE_SUCCESS 0** - The operation is successful. **HICOLLIE_INVALID_ARGUMENT 401** - The parameter is invalid. Both the begin and end functions must have values or be empty. Otherwise, this error code is returned. **HICOLLIE_WRONG_THREAD_CONTEXT 29800001** - The calling thread is incorrect. This function cannot be called from the main thread. **HICOLLIE_REMOTE_FAILED 29800002** - The remote call fails.

### OH_HiCollie_SetTimer()

```
HiCollie_ErrorCode OH_HiCollie_SetTimer (HiCollie_SetTimerParam param, int * id )
```

**Description**

Sets a timer before a time-consuming function is called.

**Since**: 16

**Parameters**

| Name| Description|
| -------- | -------- |
| param | Input parameters. |
| id | Pointer to the returned timer ID, which cannot be null. |

**Returns**

**HICOLLIE_SUCCESS 0** - The operation is successful. **HICOLLIE_INVALID_TIMER_NAME 29800003** - The timer name is invalid. It cannot be null or an empty string. **HICOLLIE_INVALID_TIMEOUT_VALUE 29800004** - The timeout value is invalid. **HICOLLIE_WRONG_PROCESS_CONTEXT 29800005** - The accessed detection process context is invalid. This function cannot be called in the appspawn and nativespawn processes. **HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM 29800006** - The pointer to the returned timer ID is invalid. The value cannot be null.
