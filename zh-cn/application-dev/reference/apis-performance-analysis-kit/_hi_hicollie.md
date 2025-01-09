# HiCollie


## 概述

本模块对外提供检测业务线程卡死、卡顿，以及上报卡死事件及函数执行超时的检测能力。

**系统能力：** SystemCapability.HiviewDFX.HiCollie

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [hicollie.h](hicollie_8h.md) | 定义HiCollie模块的功能。 |


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| struct  [HiCollie_DetectionParam](_hi_hicollie___detection_param.md) | 设置检测业务线程卡顿的相关参数。 |
| struct  [HiCollie_SetTimerParam](_hi_hicollie___set_timer_param.md) | 设置检测业务线程Timer超时检测的相关参数。 |

### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [HiCollie_ErrorCode](errorcode-hiviewdfx-hicollie.md) [HiCollie_ErrorCode](#hicollie_errorcode) | 错误码定义。 | 
| typedef enum [HiCollie_Flag](#hicollie) [HiCollie_Flag](#hicollie_flag) | 超时发生后，行为信号定义。 | 
| typedef void(\* [OH_HiCollie_Task](#oh_hicollie_task)) (void) | 函数指针, 用户自定义回调函数内容，该回调函数用于周期性检测应用业务线程任务执行情况。 | 
| typedef void(\* [OH_HiCollie_BeginFunc](#oh_hicollie_beginfunc)) (const char \*name) | 函数指针, 用户自定义回调函数内容，该回调函数放在应用业务线程处理事件之前。 | 
| typedef void(\* [OH_HiCollie_EndFunc](#oh_hicollie_endfunc)) (const char \*name) | 函数指针, 用户自定义回调函数内容，该回调函数放在应用业务线程处理事件之后。 | 
| typedef void(\* [OH_HiCollie_Callback](#oh_hicollie_callback)) (void \*) | 函数指针, 用户自定义回调函数内容，该回调函数放在应用业务线程超时发生之后。 | 
| typedef struct [HiCollie_DetectionParam](_hi_hicollie___detection_param.md) [HiCollie_DetectionParam](#hicollie_detectionparam) | 用户可以自定义检测业务线程卡顿的相关参数。 | 
| typedef struct [HiCollie_SetTimerParam](_hi_hicollie___set_timer_param.md) [HiCollie_SetTimerParam](#hicollie_settimerparam) | 用户可以自定义业务线程Timer超时检测的输入参数。 | 

### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [HiCollie_Flag](#hicollie_flag) { **HICOLLIE_SUCCESS** = 0, **HICOLLIE_INVALID_ARGUMENT** = 401, **HICOLLIE_WRONG_THREAD_CONTEXT** = 29800001, **HICOLLIE_REMOTE_FAILED** = 29800002, **HICOLLIE_INVALID_TIMER_NAME** = 29800003, **HICOLLIE_INVALID_TIMEOUT_VALUE** = 29800004, **HICOLLIE_WRONG_PROCESS_CONTEXT** = 29800005, **HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM** = 29800006} | 返回错误码枚举。  | 
| [HiCollie_Flag](#hicollie_flag) { **HICOLLIE_FLAG_DEFAULT** = (~0), **HICOLLIE_FLAG_NOOP** = (0), **HICOLLIE_FLAG_LOG** = (1 << 0), **HICOLLIE_FLAG_RECOVERY** = (1 << 1) } | 超时发生后，行为信号定义枚举。  | 

### 函数

| 名称 | 描述 | 
| -------- | -------- |
| HiCollie_ErrorCode [OH_HiCollie_Init_StuckDetection](_hi_hicollie.md#oh_hicollie_init_stuckdetection) (OH_HiCollie_Task task) | 注册应用业务线程卡死的周期性检测任务。  | 
| HiCollie_ErrorCode [OH_HiCollie_Init_JankDetection](_hi_hicollie.md#oh_hicollie_init_jankdetection) (OH_HiCollie_BeginFunc\* beginFunc, OH_HiCollie_EndFunc\* endFunc, HiCollie_DetectionParam param) | 注册应用业务线程卡顿检测的回调函数。  | 
| HiCollie_ErrorCode [OH_HiCollie_Report](_hi_hicollie.md#oh_hicollie_report) (bool\* isSixSecond) | 用于上报应用业务线程卡死事件，生成超时故障日志，辅助定位应用超时问题。结合OH_HiCollie_Init_StuckDetection接口配套使用，先初始化卡死检测，出现卡死时，再上报事件。  | 
| HiCollie_ErrorCode [OH_HiCollie_SetTimer](_hi_hicollie.md#oh_hicollie_settimer) (HiCollieSetParam param, int\* id) | 用于设置注册应用业务线程Timer超时检测任务。结合OH_HiCollie_CancelTimer接口配套使用，OH_HiCollie_SetTimer设置超时检测任务，执行函数或代码后，OH_HiCollie_CancelTimer通过timer id将该任务取消；若取消不及时，即超时发生可执行回调函数，生成超时故障日志，辅助定位应用超时问题。  | 
| HiCollie_ErrorCode [OH_HiCollie_CancelTimer](_hi_hicollie.md#oh_hicollie_canceltimer) (int id) | 根据timer id用于取消应用业务线程Timer超时检测任务。  | 


## 类型定义说明


### HiCollie_ErrorCode

```
typedef enum HiCollie_ErrorCode HiCollie_ErrorCode
```

**描述**

错误码定义。

**起始版本：** 12


### HiCollie_Flag

```
typedef enum HiCollie_Flag HiCollie_Flag
```

**描述**

超时发生后，行为信号定义枚举。

**起始版本：** 16


### OH_HiCollie_Task

```
typedef void (*OH_HiCollie_Task)(void)
```

**描述**

应用业务线程卡死检测回调函数。业务线程会定时执行该回调函数，检查线程完成情况，判定已经注册的线程是否卡死。

**起始版本：** 12


### OH_HiCollie_BeginFunc

```
typedef void (*OH_HiCollie_BeginFunc)(const char* eventName)
```

**描述**

应用业务线程卡顿检测回调函数。该回调函数放在应用业务线程处理事件之前，用于记录线程开始处理事件时间。

**起始版本：** 12


### OH_HiCollie_EndFunc

```
typedef void (*OH_HiCollie_EndFunc)(const char* eventName)
```

**描述**

应用业务线程卡顿检测回调函数。该回调函数放在应用业务线程处理事件之后，用于检测线程处理该事件是否出现卡顿情况。

**起始版本：** 12


### OH_HiCollie_Callback

```
typedef void (*OH_HiCollie_Callback)(void*)
```

**描述**

应用业务线程超时检测回调函数。该回调函数放在应用业务线程超时发生之后，用于执行用户在线程Timer超时发生时自定义的行为。

**起始版本：** 16


### HiCollie_DetectionParam

```
typedef struct HiCollie_DetectionParam HiCollie_DetectionParam
```

**描述**

用户可以自定义检测业务线程卡顿的相关参数，如：设置卡顿阈值。

**起始版本：** 12


### HiCollie_SetTimerParam

```
typedef struct HiCollie_SetTimerParam HiCollie_SetTimerParam
```

**描述**

用户可以自定义业务线程Timer超时检测的输入参数，如：设置timeout阈值，name任务名称。

**起始版本：** 16


## 枚举类型说明


### HiCollie_ErrorCode

```
enum HiCollie_Flag
```
**描述**
函数返回错误码。

**起始版本：** 16

| 枚举值 | 描述 | 
| -------- | -------- |
| HICOLLIE_SUCCESS | 成功 | 
| HICOLLIE_INVALID_ARGUMENT | 无效参数 | 
| HICOLLIE_WRONG_THREAD_CONTEXT | 错误的线程上下文 | 
| HICOLLIE_REMOTE_FAILED | 远程调用失败 | 
| HICOLLIE_INVALID_TIMER_NAME | 无效的Timer名称（仅为OH_HiCollie_SetTimer函数返回错误码） | 
| HICOLLIE_INVALID_TIMEOUT_VALUE | 无效的超时时间阈值（仅为OH_HiCollie_SetTimer函数返回错误码） | 
| HICOLLIE_WRONG_PROCESS_CONTEXT | 错误的进程上下文（仅为OH_HiCollie_SetTimer函数返回错误码）| 
| HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM | 错误的进程ID参数（仅为OH_HiCollie_SetTimer函数返回错误码） | 


### HiCollie_Flag

```
enum HiCollie_Flag
```
**描述**
行为信号类型。

超时发生后，行为信号定义枚举。

**起始版本：** 16

| 枚举值 | 描述 | 
| -------- | -------- |
| HICOLLIE_FLAG_DEFAULT | 默认执行回调，生成日志及恢复查杀（应用进程不查杀） | 
| HICOLLIE_FLAG_NOOP | 仅执行回调函数 | 
| HICOLLIE_FLAG_LOG | 执行回调函数及生成超时故障日志 | 
| HICOLLIE_FLAG_RECOVERY | 执行回调函数及恢复查杀（应用进程不查杀） | 


## 函数说明


### OH_HiCollie_Init_StuckDetection

```
HiCollie_ErrorCode OH_HiCollie_Init_StuckDetection(OH_HiCollie_Task task)
```

**描述**

注册应用业务线程卡死的周期性检测任务。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| task | 用户实现的回调函数, 定时检测业务线程卡死情况。如果用户想要取消检测，可以传空指针。 |


**返回：**

返回设置回调函数结果。如果返回结果为HICOLLIE_SUCCESS，代表初始化业务线程卡死检测成功。其他返回结果依次为HICOLLIE_INVALID_TIMER_NAME、HICOLLIE_INVALID_TIMEOUT_VALUE、HICOLLIE_WRONG_PROCESS_CONTEXT及HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM。


### OH_HiCollie_Init_JankDetection

```
HiCollie_ErrorCode OH_HiCollie_Init_JankDetection(OH_HiCollie_BeginFunc* beginFunc, OH_HiCollie_EndFunc* endFunc, HiCollie_DetectionParam param);
```

**描述**

注册应用业务线程卡顿检测的回调函数。线程卡顿监控功能需要开发者实现两个卡顿检测回调函数, 分别放在业务线程处理事件的前后。作为插桩函数，监控业务线程处理事件执行情况。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| beginFunc | 用户实现的回调函数, 调用位置：业务线程处理事件之前。如果用户想要取消检测，beginFunc和endFunc需要同时传空指针。 |
| endFunc | 用户实现的回调函数, 调用位置：业务线程处理事件之后。如果用户想要取消检测，beginFunc和endFunc需要同时传空指针。 |
| param | 用户自定义线程卡顿参数，扩展参数以供后续开发使用。见[HiCollie_DetectionParam](_hi_hicollie___detection_param.md) |

**返回：**

返回设置回调函数结果。如果返回结果为0，代表初始化业务线程卡顿检测成功。


### OH_HiCollie_Report

```
HiCollie_ErrorCode OH_HiCollie_Report(bool* isSixSecond);
```

**描述**

用于上报应用业务线程卡死事件，生成超时故障日志，辅助定位应用超时问题。结合OH_HiCollie_Init_StuckDetection接口配套使用，先初始化卡死检测，出现卡死时，再上报事件。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| isSixSecond | bool指针，如果卡住6秒，则为true。如果卡住3秒，则为False。 |


**返回：**

返回设置回调函数上报结果。如果返回结果为0，代表初始化业务线程上报卡死事件成功。


### OH_HiCollie_SetTimer

```
HiCollie_ErrorCode OH_HiCollie_SetTimer(HiCollie_SetTimerParam param, int *id);
```

**描述**

启动函数执行时长检测定时器。结合OH_HiCollie_CancelTimer接口配套使用，OH_HiCollie_SetTimer设置超时检测任务，执行函数或代码后，OH_HiCollie_CancelTimer通过timer id将该任务取消；若取消不及时，即超时发生可执行回调函数，特定行为信号下生成超时故障日志，辅助定位应用超时问题。

**起始版本：** 16

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| param | HiCollie_SetTimerParam结构体。结构体包含任务名称字符指针（非空字符串），超时时间阈值（大于0），回调函数，回调函数参数以及超时发生后行为信号。 |
| id | int指针类型，timer超时检测任务id，int指针作为入参，启动函数执行完毕后更新id中存储的值。 |


**返回：**

返回启动检测器Timer的结果。结果为HICOLLIE_SUCCESS，代表成功。


### OH_HiCollie_CancelTimer

```
HiCollie_ErrorCode OH_HiCollie_CancelTimer(int id);
```

**描述**

根据timer id取消函数执行时长检测定时器。

**起始版本：** 16

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| id | int类型，timer超时检测器任务id，可据此id取消特定的函数执行时长检测定时器任务。 |


**返回：**

无返回值。