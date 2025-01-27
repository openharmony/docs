# HiCollie

## 概述

提供检测业务线程卡死或卡顿的能力。请注意：要在非业务线程中调用

本模块函数可用于： （1）注册应用业务线程卡死的周期性检测任务； （2）注册应用业务线程卡顿检测的回调函数； （3）上报应用业务线程卡死事件。

**系统能力：** SystemCapability.HiviewDFX.HiCollie

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 |
| -------- | -------- |
| [hicollie.h](hicollie_8h.md) | HiCollie模块对外提供检测业务线程卡死、卡顿，以及上报卡死事件的能力。  |

### 结构体

| 名称 | 描述 |
| -------- | -------- |
| struct&nbsp;&nbsp;[HiCollie_DetectionParam](_hi_hicollie___detection_param.md) | 用于检测业务线程卡顿的参数。 请注意，这些参数对API 12无效，仅用于扩展。  |
| struct&nbsp;&nbsp;[HiCollie_SetTimerParam](_hi_hicollie___set_timer_param.md) | 定义OH_HiCollie_SetTimer函数的输入参数。  |

### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [HiCollie_ErrorCode](#hicollie_errorcode)[HiCollie_ErrorCode](#hicollie_errorcode) | 错误码定义  |
| typedef void(\* [OH_HiCollie_Task](#oh_hicollie_task)) (void) | 在业务线程卡死检测中，通过实现该函数来检测业务线程是否卡住。 HiCollie将在独立线程中每3秒调用一次该函数。 例如：该函数可实现向业务线程发送消息。在业务线程接收到消息之后，设置一个标记，通过检查这个标记，可以知道业务线程是否卡住。  |
| typedef void(\* [OH_HiCollie_BeginFunc](#oh_hicollie_beginfunc)) (const char \*eventName) | 事件处理前调用该函数。在卡顿检测中, 通过实现该函数来记录业务线程处理事件的开始时间。  |
| typedef void(\* [OH_HiCollie_EndFunc](#oh_hicollie_endfunc)) (const char \*eventName) | 事件处理后调用该函数。在卡顿检测中, 通过实现该函数来检测业务线程处理事件是否卡顿。 通过检查处理事件的执行时间，HiCollie将知道每个事件的持续时间。如果超过预设阈值(150ms~450ms)，将报告jank事件。  |
| typedef struct [HiCollie_DetectionParam](_hi_hicollie___detection_param.md)[HiCollie_DetectionParam](#hicollie_detectionparam) | 用于检测业务线程卡顿的参数。 请注意，这些参数对API 12无效，仅用于扩展。  |
| typedef void(\* [OH_HiCollie_Callback](#oh_hicollie_callback)) (void \*) | 启动函数执行超时检测。  |
| typedef enum [HiCollie_Flag](#hicollie_flag)[HiCollie_Flag](#hicollie_flag) | 定义函数执行超时时发生的动作。  |
| typedef struct [HiCollie_SetTimerParam](_hi_hicollie___set_timer_param.md)[HiCollie_SetTimerParam](#hicollie_settimerparam) | 定义OH_HiCollie_SetTimer函数的输入参数。  |

### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [HiCollie_ErrorCode](#hicollie_errorcode) {<br/>HICOLLIE_SUCCESS = 0, HICOLLIE_INVALID_ARGUMENT = 401, HICOLLIE_WRONG_THREAD_CONTEXT = 29800001, HICOLLIE_REMOTE_FAILED = 29800002,<br/>HICOLLIE_INVALID_TIMER_NAME = 29800003, HICOLLIE_INVALID_TIMEOUT_VALUE = 29800004, HICOLLIE_WRONG_PROCESS_CONTEXT = 29800005, HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM = 29800006<br/>} | 错误码定义  |
| [HiCollie_Flag](#hicollie_flag) { HICOLLIE_FLAG_DEFAULT = (~0), **HICOLLIE_FLAG_NOOP** = (0), **HICOLLIE_FLAG_LOG** = (1 &lt;&lt; 0), **HICOLLIE_FLAG_RECOVERY** = (1 &lt;&lt; 1) } | 定义函数执行超时时发生的动作。  |

### 函数

| 名称 | 描述 |
| -------- | -------- |
| [HiCollie_ErrorCode](#hicollie_errorcode)[OH_HiCollie_Init_StuckDetection](#oh_hicollie_init_stuckdetection) ([OH_HiCollie_Task](#oh_hicollie_task) task) | 注册应用业务线程卡死的周期性检测任务。  |
| [HiCollie_ErrorCode](#hicollie_errorcode)[OH_HiCollie_Init_JankDetection](#oh_hicollie_init_jankdetection) ([OH_HiCollie_BeginFunc](#oh_hicollie_beginfunc) \*beginFunc, [OH_HiCollie_EndFunc](#oh_hicollie_endfunc) \*endFunc, [HiCollie_DetectionParam](_hi_hicollie___detection_param.md) param) | 注册应用业务线程卡顿检测的回调函数。  |
| [HiCollie_ErrorCode](#hicollie_errorcode)[OH_HiCollie_Report](#oh_hicollie_report) (bool \*isSixSecond) | 上报应用业务线程卡死事件。  |
| [HiCollie_ErrorCode](#hicollie_errorcode)[OH_HiCollie_SetTimer](#oh_hicollie_settimer) ([HiCollie_SetTimerParam](_hi_hicollie___set_timer_param.md) param, int \*id) | 此函数应在调用耗时的函数之前使用。  |
| void [OH_HiCollie_CancelTimer](#oh_hicollie_canceltimer) (int id) | 根据timer id取消函数执行时长检测定时器。  |

## 类型定义说明

### HiCollie_DetectionParam

```
typedef struct HiCollie_DetectionParamHiCollie_DetectionParam
```

**描述**
用于检测业务线程卡顿的参数。 请注意，这些参数对API 12无效，仅用于扩展。

**起始版本：** 12

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
定义函数执行超时时发生的动作。

**起始版本：** 16

### HiCollie_SetTimerParam

```
typedef struct HiCollie_SetTimerParamHiCollie_SetTimerParam
```

**描述**
定义OH_HiCollie_SetTimer函数的输入参数。

**起始版本：** 16

### OH_HiCollie_BeginFunc

```
typedef void (*OH_HiCollie_BeginFunc)(const char* eventName)
```

**描述**
事件处理前调用该函数。在卡顿检测中, 通过实现该函数来记录业务线程处理事件的开始时间。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| eventName | 业务线程处理事件的名字。  |

### OH_HiCollie_Callback

```
typedef void(* OH_HiCollie_Callback) (void *)
```

**描述**
启动函数执行超时检测。

**起始版本：** 16

### OH_HiCollie_EndFunc

```
typedef void(* OH_HiCollie_EndFunc) (const char *eventName)
```

**描述**
事件处理后调用该函数。在卡顿检测中, 通过实现该函数来检测业务线程处理事件是否卡顿。 通过检查处理事件的执行时间，HiCollie将知道每个事件的持续时间。如果超过预设阈值(150ms~450ms)，将报告jank事件。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| eventName | Business thread processing event name。  |

### OH_HiCollie_Task

```
typedef void(* OH_HiCollie_Task) (void)
```

**描述**
在业务线程卡死检测中，通过实现该函数来检测业务线程是否卡住。 HiCollie将在独立线程中每3秒调用一次该函数。 例如：该函数可实现向业务线程发送消息。在业务线程接收到消息之后，设置一个标记，通过检查这个标记，可以知道业务线程是否卡住。

**起始版本：** 12

## 枚举类型说明

### HiCollie_ErrorCode

```
enum HiCollie_ErrorCode
```

**描述**
错误码定义

**起始版本：** 12

| 枚举值 | 描述 |
| -------- | -------- |
| HICOLLIE_SUCCESS  | 成功。&nbsp;&nbsp; |
| HICOLLIE_INVALID_ARGUMENT  | 无效参数，可能的原因： 1.参数传值问题 2.参数类型问题。&nbsp;&nbsp; |
| HICOLLIE_WRONG_THREAD_CONTEXT  | 检测的线程错误：在业务线程中调用。&nbsp;&nbsp; |
| HICOLLIE_REMOTE_FAILED  | 远程调用错误。&nbsp;&nbsp; |
| HICOLLIE_INVALID_TIMER_NAME  | 无效的函数执行超时检测器名称。<br/>**起始版本：** 16 |
| HICOLLIE_INVALID_TIMEOUT_VALUE  | 无效的函数执行超时时间阈值。<br/>**起始版本：** 16 |
| HICOLLIE_WRONG_PROCESS_CONTEXT  | 函数执行超时检测接入进程错误。<br/>**起始版本：** 16 |
| HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM  | 错误的函数执行超时检测id参数。<br/>**起始版本：** 16 |

### HiCollie_Flag

```
enum HiCollie_Flag
```

**描述**
定义函数执行超时时发生的动作。

**起始版本：** 16

| 枚举值 | 描述 |
| -------- | -------- |
| HICOLLIE_FLAG_DEFAULT  | 默认动作，生成日志及查杀恢复。&nbsp;&nbsp; |
| HICOLLIE_FLAG_NOOP  | 仅执行回调函数。&nbsp;&nbsp; |
| HICOLLIE_FLAG_LOG  | 生成日志。&nbsp;&nbsp; |
| HICOLLIE_FLAG_RECOVERY  | 执行查杀恢复。&nbsp;&nbsp; |

## 函数说明

### OH_HiCollie_CancelTimer()

```
void OH_HiCollie_CancelTimer (int id)
```

**描述**
根据timer id取消函数执行时长检测定时器。

**起始版本：** 16

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| id | 执行[OH_HiCollie_SetTimer](#oh_hicollie_settimer)函数后更新的计时器id，可据此id取消特定的函数执行时长检测定时器任务。  |

### OH_HiCollie_Init_JankDetection()

```
HiCollie_ErrorCode OH_HiCollie_Init_JankDetection (OH_HiCollie_BeginFunc * beginFunc, OH_HiCollie_EndFunc * endFunc, HiCollie_DetectionParam param )
```

**描述**
注册应用业务线程卡顿检测的回调函数。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| beginFunc | 检测业务线程处理事件前的函数。  |
| endFunc | 检测业务线程处理事件后的函数。  |
| param | 扩展参数以供将来使用。  |

**返回：**

HICOLLIE_SUCCESS 0 - 成功。 HICOLLIE_INVALID_ARGUMENT 401 - 开始函数和结束函数两者都必须有值或为空，否则将返回该错误值。 HICOLLIE_WRONG_THREAD_CONTEXT 29800001 - 调用线程错误。无法从主线程调用该函数。

### OH_HiCollie_Init_StuckDetection()

```
HiCollie_ErrorCode OH_HiCollie_Init_StuckDetection (OH_HiCollie_Task task)
```

**描述**
注册应用业务线程卡死的周期性检测任务。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| task | 每3秒执行一次的周期性检测任务，用于检测业务线程是否卡住。  |

**返回：**

HICOLLIE_SUCCESS 0 - 成功。 HICOLLIE_WRONG_THREAD_CONTEXT 29800001 - 调用线程错误。无法从主线程调用该函数。

### OH_HiCollie_Report()

```
HiCollie_ErrorCode OH_HiCollie_Report (bool * isSixSecond)
```

**描述**
上报应用业务线程卡死事件。

**起始版本：** 12

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| isSixSecond | 布尔指针。布尔指针的值。如果卡住6秒，则为真。如果卡住3秒，则为False。  |

**返回：**

HICOLLIE_SUCCESS 0 - 成功。 HICOLLIE_INVALID_ARGUMENT 401 - 开始函数和结束函数两者都必须有值或为空，否则将返回该错误值。 HICOLLIE_WRONG_THREAD_CONTEXT 29800001 - 调用线程错误。无法从主线程调用该函数。 HICOLLIE_REMOTE_FAILED 29800002 - 远程调用错误。

### OH_HiCollie_SetTimer()

```
HiCollie_ErrorCode OH_HiCollie_SetTimer (HiCollie_SetTimerParam param, int * id )
```

**描述**
此函数应在调用耗时的函数之前使用。

**起始版本：** 16

**参数:**

| 名称 | 描述 |
| -------- | -------- |
| param | 定义输入参数。  |
| id | 用于保存返回的计时器id的指针，它不应为NULL。  |

**返回：**

HICOLLIE_SUCCESS 0 - 成功。 HICOLLIE_INVALID_TIMER_NAME 29800003 - 无效的计时器名称，不应为NULL或空字符串。 HICOLLIE_INVALID_TIMEOUT_VALUE 29800004 - 无效的超时值。 HICOLLIE_WRONG_PROCESS_CONTEXT 29800005 - 无效的接入检测进程上下文，appspawn与nativespawn进程中不可调用。 HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM 29800006 - 用于保存返回的计时器id的指针，不应该为NULL。
