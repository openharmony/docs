# HiCollie


## Overview

HiCollie provides APIs for detecting service thread stuck and jank events and reporting service thread stuck events.

**Since**: 12


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [hicollie.h](hicollie_8h.md) | Defines APIs for debugging.|


### Structs

| Name| Description|
| -------- | -------- |
| struct  [HiCollie_DetectionParam](_hi_hicollie___detection_param.md) | Defines the parameters of the jank event detection.|


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [HiCollie_ErrorCode](errorcode-hiviewdfx-hicollie.md) [HiCollie_ErrorCode](#hicollie_errorcode) | Defines an enum for error codes.| 
| typedef void(\* [OH_HiCollie_Task](#oh_hicollie_task)) (void) | Defines the pointer to the user-defined callback. This callback is used to periodically check the processing event on the application service thread.| 
| typedef void(\* [OH_HiCollie_BeginFunc](#oh_hicollie_beginfunc)) (const char \*name) | Defines the pointer to the user-defined callback. This callback is used before the service thread processes the event.| 
| typedef void(\* [OH_HiCollie_EndFunc](#oh_hicollie_endfunc)) (const char \*name) | Defines the pointer to the user-defined callback. This callback is used after the service thread processed the event.| 
| typedef struct [HiCollie_DetectionParam](_hi_hicollie___detection_param.md) [HiCollie_DetectionParam](#hicollie_detectionparam) | Defines a struct for the parameters of the user-defined jank event detection.| 


## Type Description


### HiCollie_ErrorCode

```
typedef enum HiCollie_ErrorCode HiCollie_ErrorCode
```

**Description**

Defines an enum for error codes.

**Since**: 12


### OH_HiCollie_Task

```
typedef void (*OH_HiCollie_Task)(void)
```

**Description**

Defines the pointer to the user-defined callback for the stuck event detection. This callback is used to periodically check whether the processing event on the service thread is stuck.

**Since**: 12


### OH_HiCollie_BeginFunc

```
typedef void (*OH_HiCollie_BeginFunc)(const char* eventName)
```

**Description**

Defines the pointer to the user-defined callback for the jank event detection. This callback is used before the service thread processes the event to record the start time of the processing event.

**Since**: 12


### OH_HiCollie_EndFunc

```
typedef void (*OH_HiCollie_EndFunc)(const char* eventName)
```

**Description**

Defines the pointer to the user-defined callback for the jank event detection. This callback is used after the service thread processed the event to check whether the thread is jank.

**Since**: 12


### HiCollie_DetectionParam

```
typedef struct HiCollie_DetectionParam HiCollie_DetectionParam
```

**Description**

Defines the pointer to the parameters of the user-defined jank event detection, such as the threshold of the jank event.

**Since**: 12


### Functions

| Name| Description| 
| -------- | -------- |
| HiCollie_ErrorCode [OH_HiCollie_Init_StuckDetection](_hi_hicollie.md#oh_hicollie_init_stuckdetection) (OH_HiCollie_Task task) | Registers a callback to periodically detect service thread stuck events. | 
| HiCollie_ErrorCode [OH_HiCollie_Init_JankDetection](_hi_hicollie.md#oh_hicollie_init_jankdetection) (OH_HiCollie_BeginFunc\* beginFunc, OH_HiCollie_EndFunc\* endFunc, HiCollie_DetectionParam param) | Registers a callback to detect service thread jank events. | 
| HiCollie_ErrorCode [OH_HiCollie_Report](_hi_hicollie.md#oh_hicollie_report) (bool\* isSixSecond) | Reports service thread stuck events and generates timeout logs to help locate application timeout events. This API is used together with **OH_HiCollie_Init_StuckDetection()**, which initializes the stuck event detection at first, and then **OH_HiCollie_Report()** reports the stuck event when it occurs. | 


## Function Description


### OH_HiCollie_Init_StuckDetection

```
HiCollie_ErrorCode OH_HiCollie_Init_StuckDetection(OH_HiCollie_Task task)
```

**Description**

Registers a callback to periodically detect service thread stuck events.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| task | Callback used to periodically check whether the service thread is stuck. If you want to cancel the detection, pass a null pointer.|


**Returns**

 Returns **0** if the stuck event detection is successfully initialized.


### OH_HiCollie_Init_JankDetection

```
HiCollie_ErrorCode OH_HiCollie_Init_JankDetection(OH_HiCollie_BeginFunc* beginFunc, OH_HiCollie_EndFunc* endFunc, HiCollie_DetectionParam param);
```

**Description**

Registers a callback to detect service thread jank events. To monitor thread jank events, you can implement two callbacks as instrumentation functions, placing them before and after the service thread processes the event.  

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| beginFunc | Callback used before the service thread processes the event. If you want to cancel the detection, pass a null pointer to **beginFunc** and **endFunc**.|
| endFunc | Callback used after the service thread processed the event. If you want to cancel the detection, pass a null pointer to **beginFunc** and **endFunc**.|
| param | Custom extended parameter used in the jank detection, which is provided for future development. See [HiCollie_DetectionParam](_hi_hicollie___detection_param.md).|

**Returns**

 Returns **0** if the jank event detection is successfully initialized.


### OH_HiCollie_Report

```
HiCollie_ErrorCode OH_HiCollie_Report(bool* isSixSecond);
```

**Description**

Reports service thread stuck events and generates timeout logs to help locate application timeout events. This API is used together with **OH_HiCollie_Init_StuckDetection()**, which initializes the stuck event detection at first, and then **OH_HiCollie_Report()** reports the stuck event when it occurs.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| isSixSecond | Pointer to the boolean variable, whose value is **true** when the service thread is stuck for 6s. If the service thread is stuck for 3s, the value is **false**.|


**Returns**

 Returns **0** if the stuck event reporting function is successfully initialized.
