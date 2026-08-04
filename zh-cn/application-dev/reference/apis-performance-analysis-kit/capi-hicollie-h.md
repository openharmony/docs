# hicollie.h

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @Chenyufan466765692-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

## 概述

HiCollie模块提供检测业务线程卡死、卡顿，以及上报卡死事件的能力。

**引用文件：** <hicollie/hicollie.h>

**库：** libohhicollie.so

**系统能力：** SystemCapability.HiviewDFX.HiCollie

**起始版本：** 12

**相关模块：** [HiCollie](capi-hicollie.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [HiCollie_DetectionParam](capi-hicollie-hicollie-detectionparam.md) | HiCollie_DetectionParam | 检测业务线程卡顿的相关参数，可用于应用线程卡顿检测与分析等场景。请注意，从API version 12及以上支持。 |
| [HiCollie_SetTimerParam](capi-hicollie-hicollie-settimerparam.md) | HiCollie_SetTimerParam | 定义OH_HiCollie_SetTimer函数的输入参数，用于设置定时器监控任务的名称、任务超时时间阈值、超时回调函数及执行动作标志。<br> 使用场景：适用于需要监控任务执行时间的场景，帮助开发者监控和处理任务超时问题。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [HiCollie_ErrorCode](#hicollie_errorcode) | HiCollie_ErrorCode | 错误码定义。 |
| [HiCollie_Flag](#hicollie_flag) | HiCollie_Flag | 定义函数执行超时时发生的动作。 |
| [OH_HiCollie_Freeze_Type](#oh_hicollie_freeze_type) | OH_HiCollie_Freeze_Type | 定义FreezeCallback返回的冻屏类型。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_HiCollie_Task)(void)](#oh_hicollie_task) | OH_HiCollie_Task | 在业务线程卡死检测中，通过实现该函数来检测业务线程是否卡住。<br> HiCollie将在业务线程中每3秒调用一次该函数。<br> 例如：该函数可实现向业务线程发送消息，在业务线程接收到消息之后，设置一个标记，检查这个标记，确定业务线程是否卡住。 |
| [typedef void (\*OH_HiCollie_BeginFunc)(const char* eventName)](#oh_hicollie_beginfunc) | OH_HiCollie_BeginFunc | 卡顿检测中，该函数用于记录业务线程处理事件的开始时间。<br> 由HiCollie检查事件的执行时间，如果超过预设阈值，上报jank事件。<br> 该函数在每个事件处理前插入，与[OH_HiCollie_EndFunc](capi-hicollie-h.md#oh_hicollie_endfunc)接口配套使用。 |
| [typedef void (\*OH_HiCollie_EndFunc)(const char* eventName)](#oh_hicollie_endfunc) | OH_HiCollie_EndFunc | 卡顿检测中，该函数记录业务线程处理事件的结束时间，并检查业务线程处理事件是否卡顿。<br> 由HiCollie检查事件的执行时间，如果超过预设阈值，上报jank事件。<br> 该函数在每个事件处理后插入，与[OH_HiCollie_BeginFunc](capi-hicollie-h.md#oh_hicollie_beginfunc)接口配套使用。 |
| [HiCollie_ErrorCode OH_HiCollie_Init_StuckDetection(OH_HiCollie_Task task)](#oh_hicollie_init_stuckdetection) | - | 注册应用业务线程卡死的周期性检测任务。Hicollie通过在业务线程中定期调用用户实现的回调函数，检查业务线程是否能够正常响应，从而判断线程是否卡死。<br> 用户实现回调函数，用于定时检测业务线程卡死情况。<br> **说明：**<br> - 默认检测时间：3s上报BUSSINESS_THREAD_BLOCK_3S告警事件，6s上报BUSSINESS_THREAD_BLOCK_6S卡死事件。<br> - 该接口使用默认的3s和6s检测时间。如果需要自定义检测时间，请使用OH_HiCollie_Init_StuckDetectionWithTimeout接口。<br> - 仅能在非主线程中调用该接口。 |
| [HiCollie_ErrorCode OH_HiCollie_Init_StuckDetectionWithTimeout(OH_HiCollie_Task task, uint32_t stuckTimeout)](#oh_hicollie_init_stuckdetectionwithtimeout) | - | 注册应用业务线程卡死的周期性检测任务。用户实现回调函数，用于定时检测业务线程卡死情况。<br> 开发者可以设置卡死检测时间，可设置的时间范围：[3, 15]，单位：秒。<br>**说明：**<br> - 如果默认的3s和6s检测时间不满足实际业务需求，使用该接口可以自定义卡死检测时间；否则建议使用OH_HiCollie_Init_StuckDetection接口。<br> - 仅能在非主线程中调用该接口。 |
| [HiCollie_ErrorCode OH_HiCollie_Init_JankDetection(OH_HiCollie_BeginFunc* beginFunc, OH_HiCollie_EndFunc* endFunc, HiCollie_DetectionParam param)](#oh_hicollie_init_jankdetection) | - | 注册应用业务线程卡顿检测的回调函数。<br> 线程卡顿监控功能需要开发者实现两个卡顿检测回调函数，分别放在业务线程处理事件的前后。作为插桩函数，监控业务线程处理事件执行情况。<br> **说明：** <br> 仅能在非主线程中调用该接口。 |
| [HiCollie_ErrorCode OH_HiCollie_Report(bool* isSixSecond)](#oh_hicollie_report) | - | 上报应用业务线程卡死事件，生成卡死故障日志，辅助定位应用卡死问题。<br> 先调用OH_HiCollie_Init_StuckDetection或OH_HiCollie_Init_StuckDetectionWithTimeout接口，初始化检测的task。<br> 如果task任务超时，结合业务逻辑，调用OH_HiCollie_Report接口上报卡死事件。<br> **说明：**<br> - 仅能在非主线程中调用该接口。<br> - 该接口仅对[release版本应用](../../dfx/performance-analysis-kit-terminology.md#release版本应用)生效。<br> - 该接口对[debug版本应用](../../dfx/performance-analysis-kit-terminology.md#debug版本应用)不生效。 |
| [HiCollie_ErrorCode OH_HiCollie_ReportInputBlock()](#oh_hicollie_reportinputblock) | - | 上报应用输入无响应事件，生成卡死故障日志，辅助定位应用卡死问题。<br> 如果在PC或平板设备上，还会弹窗提示用户继续等待或关闭应用，其他设备不会弹窗。建议如下两种方式使用该接口。<br> 方式一（推荐）：<br> 该接口配合OH_HiCollie_Report、OH_HiCollie_Init_StuckDetection或OH_HiCollie_Init_StuckDetectionWithTimeout接口使用。业务线程通过上述接口周期性检测自身卡死情况。<br> 当满足业务线程卡死且有输入事件（如屏幕点击、鼠标点击、键盘输入等）条件时再调用OH_HiCollie_ReportInputBlock接口。<br> 方式二：业务线程不通过OH_HiCollie_Report、OH_HiCollie_Init_StuckDetection或OH_HiCollie_Init_StuckDetectionWithTimeout接口也能检测自身卡死情况。此时应用结合业务线程卡死情况和输入事件再调用OH_HiCollie_ReportInputBlock接口。<br> **说明：**<br> - 该接口可以在主线程使用，比如输入事件需要先经过主线程再封装传递给业务线程处理，业务线程卡死时维护一个状态标志位，主线程结合业务线程的卡死状态标志位和输入事件再调用该接口。<br> - 该接口仅对[release版本应用](../../dfx/performance-analysis-kit-terminology.md#release版本应用)生效。<br> - 该接口对[debug版本应用](../../dfx/performance-analysis-kit-terminology.md#debug版本应用)不生效。 |
| [typedef void (\*OH_HiCollie_Callback)(void*)](#oh_hicollie_callback) | OH_HiCollie_Callback | 当用户调用[OH_HiCollie_SetTimer](capi-hicollie-h.md#oh_hicollie_settimer)后，未在其自定义的任务超时时间阈值内调用[OH_HiCollie_CancelTimer](capi-hicollie-h.md#oh_hicollie_canceltimer)，回调函数将被执行。 |
| [HiCollie_ErrorCode OH_HiCollie_SetTimer(HiCollie_SetTimerParam param, int *id)](#oh_hicollie_settimer) | - | 注册定时器，用于检测函数或代码块执行是否超过自定义时间。<br> 该接口创建一个定时器，在指定的超时时间内如果未调用OH_HiCollie_CancelTimer取消定时器，则触发回调函数执行预设的动作。<br> 结合OH_HiCollie_CancelTimer接口配套使用，应在调用耗时的函数之前使用。 |
| [void OH_HiCollie_CancelTimer(int id)](#oh_hicollie_canceltimer) | - | 取消定时器。<br> 结合OH_HiCollie_SetTimer接口配套使用，执行函数或代码块后使用，OH_HiCollie_CancelTimer通过id将该任务取消；<br> 若未在自定义时间内取消，则执行回调函数，在特定自定义超时动作下，生成故障日志。 |
| [typedef size_t (\*OH_HiCollie_FreezeCallback)(OH_HiCollie_Freeze_Type type, void* buffer, size_t size)](#oh_hicollie_freezecallback) | OH_HiCollie_FreezeCallback | 冻屏事件使用的回调[OH_HiCollie_SetFreezeCallback](capi-hicollie-h.md#oh_hicollie_setfreezecallback)。 |
| [void* OH_HiCollie_SetFreezeCallback(OH_HiCollie_FreezeCallback callback)](#oh_hicollie_setfreezecallback) | - | 将冻屏回调设置进系统，系统将在冻屏事件发生时回调此函数。 |
| [HiCollie_ErrorCode OH_HiCollie_AssociateProcessReport(bool isFreezeEvent)](#oh_hicollie_associateprocessreport) | - | 报告一个进程的冻屏事件，此时会生成APP_HICOLLIE类型HiAppEvent事件。 |

## 枚举类型说明

### HiCollie_ErrorCode

```c
enum HiCollie_ErrorCode
```

**描述**

错误码定义。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| HICOLLIE_SUCCESS  = 0 | 成功。 |
| HICOLLIE_INVALID_ARGUMENT  = 401 | 无效参数。 |
| HICOLLIE_WRONG_THREAD_CONTEXT = 29800001 | 在错误的线程中调用接口。 |
| HICOLLIE_REMOTE_FAILED = 29800002 | 远程调用错误。 |
| HICOLLIE_INVALID_TIMER_NAME = 29800003 | 无效的函数执行超时检测器名称。<br>**起始版本：** 18 |
| HICOLLIE_INVALID_TIMEOUT_VALUE = 29800004 | 无效的函数执行超时时间阈值。<br>**起始版本：** 18                  |
| HICOLLIE_WRONG_PROCESS_CONTEXT = 29800005 | 函数执行超时检测接入进程错误。<br>**起始版本：** 18                 |
| HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM = 29800006 | 用于保存返回的计时器id的指针不应为NULL。<br>**起始版本：** 18         |
| OH_HICOLLIE_REACH_REPORT_LIMIT = 29800007 | 上报频率超过限制。<br>**起始版本：** 24         |

### HiCollie_Flag

```c
enum HiCollie_Flag
```

**描述**

定义函数执行超时时发生的动作。

**起始版本：** 18

| 枚举项 | 描述 |
| -- | -- |
| HICOLLIE_FLAG_DEFAULT = (~0) | 默认动作，生成日志及执行恢复动作。 |
| HICOLLIE_FLAG_NOOP = (0) | 仅执行回调函数。 |
| HICOLLIE_FLAG_LOG = (1 << 0) | 生成日志。 |
| HICOLLIE_FLAG_RECOVERY = (1 << 1) | 执行恢复动作。 |

### OH_HiCollie_Freeze_Type

```c
enum OH_HiCollie_Freeze_Type
```

**描述**

定义FreezeCallback返回的冻屏类型。

**起始版本：** 24

| 枚举项 | 描述 |
| -- | -- |
| OH_THREAD_BLOCK_3S | 主线程超时一个周期。|
| OH_THREAD_BLOCK_6S | 主线程超时两个周期。|
| OH_LIFECYCLE_HALF_TIMEOUT | Ability生命周期超时一个周期。|
| OH_LIFECYCLE_TIMEOUT | Ability生命周期超时两个周期。|
| OH_APP_INPUT_BLOCK | 输入事件超时。|
| OH_BUSINESS_THREAD_BLOCK_3S | 通过[OH_HiCollie_Report](capi-hicollie-h.md#oh_hicollie_report)上报3S冻屏事件。|
| OH_BUSINESS_THREAD_BLOCK_6S | 通过[OH_HiCollie_Report](capi-hicollie-h.md#oh_hicollie_report)上报6S冻屏事件。|
| OH_BUSINESS_INPUT_BLOCK | 通过[OH_HiCollie_ReportInputBlock](capi-hicollie-h.md#oh_hicollie_reportinputblock)上报冻屏事件。|


## 函数说明

### OH_HiCollie_Task()

```c
typedef void (*OH_HiCollie_Task)(void)
```

**描述**

在业务线程卡死检测中，通过实现该函数来检测业务线程是否卡住。<br> HiCollie将在业务线程中每3秒调用一次该函数。<br> 例如：该函数可实现向业务线程发送消息，在业务线程接收到消息之后，设置一个标记，检查这个标记，确定业务线程是否卡住。

**起始版本：** 12

### OH_HiCollie_BeginFunc()

```c
typedef void (*OH_HiCollie_BeginFunc)(const char* eventName)
```

**描述**

卡顿检测中，该函数用于记录业务线程处理事件的开始时间。<br> 由HiCollie检查事件的执行时间，如果超过预设阈值，上报jank事件。<br> 该函数在每个事件处理前插入，与[OH_HiCollie_EndFunc](capi-hicollie-h.md#oh_hicollie_endfunc)接口配套使用。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char\* eventName | 业务线程处理事件的名称，字符串类型。用于标识事件的唯一名称，应与[OH_HiCollie_EndFunc](capi-hicollie-h.md#oh_hicollie_endfunc)的名称保持一致。 |

### OH_HiCollie_EndFunc()

```c
typedef void (*OH_HiCollie_EndFunc)(const char* eventName)
```

**描述**

卡顿检测中，该函数记录业务线程处理事件的结束时间，并检查业务线程处理事件是否卡顿。<br> 由HiCollie检查事件的执行时间，如果超过预设阈值，上报jank事件。<br> 该函数在每个事件处理后插入，与[OH_HiCollie_BeginFunc](capi-hicollie-h.md#oh_hicollie_beginfunc)接口配套使用。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char\* eventName | 业务线程处理事件的名称，字符串类型。用于标识事件的唯一名称，应与[OH_HiCollie_BeginFunc](capi-hicollie-h.md#oh_hicollie_beginfunc)的名称保持一致。 |

### OH_HiCollie_Init_StuckDetection()

```c
HiCollie_ErrorCode OH_HiCollie_Init_StuckDetection(OH_HiCollie_Task task)
```

**描述**

注册应用业务线程卡死的周期性检测任务。Hicollie通过在业务线程中定期调用用户实现的回调函数，检查业务线程是否能够正常响应，从而判断线程是否卡死。<br>用户实现回调函数，用于定时检测业务线程卡死情况。

> **说明：**
>
> - 默认检测时间：3s上报BUSSINESS_THREAD_BLOCK_3S告警事件，6s上报BUSSINESS_THREAD_BLOCK_6S卡死事件。
>
> - 该接口使用默认的3s和6s检测时间。如果需要自定义检测时间，请使用OH_HiCollie_Init_StuckDetectionWithTimeout接口。
>
> - 仅能在非主线程中调用该接口。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_HiCollie_Task](capi-hicollie-h.md#oh_hicollie_task) task | 每3秒执行一次的周期性检测任务，用于检测业务线程是否卡住。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [HiCollie_ErrorCode](capi-hicollie-h.md#hicollie_errorcode) | <ul><br>         <li> HICOLLIE_SUCCESS 0 - 成功。</li><br>         <li> HICOLLIE_WRONG_THREAD_CONTEXT 29800001 - 调用线程错误。仅能在非主线程中调用该函数。</li><br>         </ul> |

### OH_HiCollie_Init_StuckDetectionWithTimeout()

```c
HiCollie_ErrorCode OH_HiCollie_Init_StuckDetectionWithTimeout(OH_HiCollie_Task task, uint32_t stuckTimeout)
```

**描述**

注册应用业务线程卡死的周期性检测任务。用户实现回调函数，用于定时检测业务线程卡死情况。<br> 开发者可以设置卡死检测时间，可设置的时间范围：[3, 15]，单位：秒。

> **说明：**
>
> - 如果默认的3s和6s检测时间不满足实际业务需求，使用该接口可以自定义卡死检测时间；否则建议使用OH_HiCollie_Init_StuckDetection接口。
>
> - 仅能在非主线程中调用该接口。

**起始版本：** 18

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_HiCollie_Task](capi-hicollie-h.md#oh_hicollie_task) task | 每stuckTimeout时间执行一次的周期性检测任务，用于检测业务线程是否卡住。 |
| uint32_t stuckTimeout | 检测业务线程卡死时间。任务执行超过stuckTimeout时间上报卡死告警事件；任务超过stuckTimeout * 2时间上报卡死事件。<br> 单位：s。规定：最大值15s，最小值3s。超过取值范围，接口调用失败。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [HiCollie_ErrorCode](capi-hicollie-h.md#hicollie_errorcode) | <ul><br>         <li> HICOLLIE_SUCCESS 0 - 成功。</li><br>         <li> HICOLLIE_INVALID_ARGUMENT 401 - 卡死检测时间设置错误。</li><br>         <li> HICOLLIE_WRONG_THREAD_CONTEXT 29800001 - 调用线程错误。仅能在非主线程中调用该函数。</li><br>         </ul> |

### OH_HiCollie_Init_JankDetection()

```c
HiCollie_ErrorCode OH_HiCollie_Init_JankDetection(OH_HiCollie_BeginFunc* beginFunc, OH_HiCollie_EndFunc* endFunc, HiCollie_DetectionParam param)
```

**描述**

注册应用业务线程卡顿检测的回调函数。<br> 线程卡顿监控功能需要开发者实现两个卡顿检测回调函数，分别放在业务线程处理事件的前后。作为插桩函数，监控业务线程处理事件执行情况。

> **说明：**
>
> 仅能在非主线程中调用该接口。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_HiCollie_BeginFunc](capi-hicollie-h.md#oh_hicollie_beginfunc)* beginFunc | 业务线程执行任务前的回调函数，函数指针类型。需要在业务线程处理每个事件之前调用，用于记录业务线程处理事件的开始时间。 |
| [OH_HiCollie_EndFunc](capi-hicollie-h.md#oh_hicollie_endfunc)* endFunc | 业务线程执行任务后的回调函数，函数指针类型。需要在业务线程处理每个事件之后调用，用于记录业务线程处理事件的结束时间，并检查业务线程处理事件是否卡顿。 |
| [HiCollie_DetectionParam](capi-hicollie-hicollie-detectionparam.md) param | 扩展参数以供将来使用。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [HiCollie_ErrorCode](capi-hicollie-h.md#hicollie_errorcode) | <ul><br>         <li> HICOLLIE_SUCCESS 0 - 成功。</li><br>         <li> HICOLLIE_INVALID_ARGUMENT 401 - 开始函数和结束函数两者都必须有值或为空，否则将返回该错误值。</li><br>         <li> HICOLLIE_WRONG_THREAD_CONTEXT 29800001 - 调用线程错误。仅能在非主线程中调用该函数。</li><br>         </ul> |

### OH_HiCollie_Report()

```c
HiCollie_ErrorCode OH_HiCollie_Report(bool* isSixSecond)
```

**描述**

上报应用业务线程卡死事件，生成卡死故障日志，辅助定位应用卡死问题。<br> 先调用OH_HiCollie_Init_StuckDetection或OH_HiCollie_Init_StuckDetectionWithTimeout接口，初始化检测的task。<br> 如果task任务超时，结合业务逻辑，调用OH_HiCollie_Report接口上报卡死事件。

> **说明：**
>
> - 仅能在非主线程中调用该接口。
>
> - 该接口仅对[release版本应用](../../dfx/performance-analysis-kit-terminology.md#release版本应用)生效。
>
> - 该接口对[debug版本应用](../../dfx/performance-analysis-kit-terminology.md#debug版本应用)不生效。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| bool* isSixSecond | 布尔指针，指向的布尔值表示业务线程卡死时长。如果卡住6秒，则为true，如果卡住3秒，则为false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [HiCollie_ErrorCode](capi-hicollie-h.md#hicollie_errorcode) | <ul><br>         <li> HICOLLIE_SUCCESS 0 - 成功。</li><br>         <li> HICOLLIE_INVALID_ARGUMENT 401 - 开始函数和结束函数两者都必须有值或为空，否则将返回该错误值。</li><br>         <li> HICOLLIE_WRONG_THREAD_CONTEXT 29800001 - 调用线程错误。仅能在非主线程中调用该函数。</li><br>         <li> HICOLLIE_REMOTE_FAILED 29800002 - 远程调用错误。请求IPC远程服务失败。</li><br>         </ul> |

### OH_HiCollie_ReportInputBlock()

```c
HiCollie_ErrorCode OH_HiCollie_ReportInputBlock()
```

**描述**

上报应用输入无响应事件，生成卡死故障日志，辅助定位应用卡死问题。<br> 如果在PC或平板设备上，还会弹窗提示用户继续等待或关闭应用，其他设备不会弹窗。建议如下两种方式使用该接口。<br> 方式一（推荐）：<br> 该接口配合OH_HiCollie_Report、OH_HiCollie_Init_StuckDetection或OH_HiCollie_Init_StuckDetectionWithTimeout接口使用。业务线程通过上述接口周期性检测自身卡死情况。<br> 当满足业务线程卡死且有输入事件（如屏幕点击、鼠标点击、键盘输入等）条件时再调用OH_HiCollie_ReportInputBlock接口。<br> 方式二：业务线程不通过OH_HiCollie_Report、OH_HiCollie_Init_StuckDetection或OH_HiCollie_Init_StuckDetectionWithTimeout接口也能检测自身卡死情况。此时应用结合业务线程卡死情况和输入事件再调用OH_HiCollie_ReportInputBlock接口。

> **说明：**
>
> - 该接口可以在主线程使用，比如输入事件需要先经过主线程再封装传递给业务线程处理，业务线程卡死时维护一个状态标志位，主线程结合业务线程的卡死状态标志位和输入事件再调用该接口。
>
> - 该接口仅对[release版本应用](../../dfx/performance-analysis-kit-terminology.md#release版本应用)生效。
>
> - 该接口对[debug版本应用](../../dfx/performance-analysis-kit-terminology.md#debug版本应用)不生效。

**起始版本：** 24

**返回：**

| 类型 | 说明 |
| -- | -- |
| [HiCollie_ErrorCode](capi-hicollie-h.md#hicollie_errorcode) | <ul><br>         <li> HICOLLIE_SUCCESS 0 - 成功。</li><br>         <li> HICOLLIE_REMOTE_FAILED 29800002 - 远程调用错误。请求IPC远程服务失败。</li><br>         </ul> |

### OH_HiCollie_Callback()

```c
typedef void (*OH_HiCollie_Callback)(void*)
```

**描述**

当用户调用[OH_HiCollie_SetTimer](capi-hicollie-h.md#oh_hicollie_settimer)后，未在其自定义的任务超时时间阈值内调用[OH_HiCollie_CancelTimer](capi-hicollie-h.md#oh_hicollie_canceltimer)，回调函数将被执行。

**起始版本：** 18

### OH_HiCollie_SetTimer()

```c
HiCollie_ErrorCode OH_HiCollie_SetTimer(HiCollie_SetTimerParam param, int *id)
```

**描述**

注册定时器，用于检测函数或代码块执行是否超过自定义时间。<br> 该接口创建一个定时器，在指定的超时时间内如果未调用OH_HiCollie_CancelTimer取消定时器，则触发回调函数执行预设的动作。<br> 结合OH_HiCollie_CancelTimer接口配套使用，应在调用耗时的函数之前使用。

**起始版本：** 18

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [HiCollie_SetTimerParam](capi-hicollie-hicollie-settimerparam.md) param | 定时器配置参数，结构体类型。<br> 该接口用于定义定时器的名称、超时时间、回调函数等配置信息。详细接口参考[HiCollie_SetTimerParam](capi-hicollie-hicollie-settimerparam.md)。 |
| int *id | 返回的计时器id的指针不应为NULL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [HiCollie_ErrorCode](capi-hicollie-h.md#hicollie_errorcode) | <ul><br>         <li> [HICOLLIE_SUCCESS](capi-hicollie-h.md#hicollie_errorcode) 0 - 成功。</li><br>         <li> [HICOLLIE_INVALID_TIMER_NAME](capi-hicollie-h.md#hicollie_errorcode) 29800003 - 无效的计时器名称，不应为NULL或空字符串。</li><br>         <li> [HICOLLIE_INVALID_TIMEOUT_VALUE](capi-hicollie-h.md#hicollie_errorcode) 29800004 - 无效的超时值。</li><br>         <li> [HICOLLIE_WRONG_PROCESS_CONTEXT](capi-hicollie-h.md#hicollie_errorcode) 29800005 - 无效的接入检测进程上下文，appspawn与nativespawn进程中不可调用。</li><br>         <li> [HICOLLIE_WRONG_TIMER_ID_OUTPUT_PARAM](capi-hicollie-h.md#hicollie_errorcode) 29800006 - 用于保存返回的计时器id的指针，不应该为NULL。</li><br>         </ul> |

### OH_HiCollie_CancelTimer()

```c
void OH_HiCollie_CancelTimer(int id)
```

**描述**

取消定时器。<br> 结合OH_HiCollie_SetTimer接口配套使用，执行函数或代码块后使用，OH_HiCollie_CancelTimer通过id将该任务取消；<br> 若未在自定义时间内取消，则执行回调函数，在特定自定义超时动作下，生成故障日志。

**起始版本：** 18

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int id | 执行[OH_HiCollie_SetTimer](capi-hicollie-h.md#oh_hicollie_settimer)函数后更新的计时器id。 |

### OH_HiCollie_FreezeCallback()

```c
typedef size_t (*OH_HiCollie_FreezeCallback)(OH_HiCollie_Freeze_Type type, void* buffer, size_t size)
```

**描述**

冻屏事件使用的回调[OH_HiCollie_SetFreezeCallback](capi-hicollie-h.md#oh_hicollie_setfreezecallback)。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| OH_HiCollie_Freeze_Type type | 冻屏事件类型。具体类型详见：[OH_HiCollie_Freeze_Type](capi-hicollie-h.md#oh_hicollie_freeze_type)。 |
| void\* buffer | 系统提供日志缓冲区，字节数组指针。<br>          用于在冻屏回调中写入自定义日志信息，写入的内容将被迁移到APP_FREEZE或APP_HICOLLIE事件中，需要按照字节数组格式写入数据。 |
| size_t size | 可以使用的缓冲区大小，最大值为64KB。如果超过上限，可能导致应用crash。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| size_t | 已使用的缓冲区大小，单位字节。 |

> **注意：**
>
> 返回值超过64KB时，日志内容可能为空。

### OH_HiCollie_SetFreezeCallback()

```c
void* OH_HiCollie_SetFreezeCallback(OH_HiCollie_FreezeCallback callback)
```

**描述**

将冻屏回调设置进系统，系统将在冻屏事件发生时回调此函数。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_HiCollie_FreezeCallback](capi-hicollie-h.md#oh_hicollie_freezecallback) callback | 回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| void* | 返回该进程之前设置的回调函数。如果是首次调用，则返回NULL。 |

### OH_HiCollie_AssociateProcessReport()

```c
HiCollie_ErrorCode OH_HiCollie_AssociateProcessReport(bool isFreezeEvent)
```

**描述**

报告一个进程的冻屏事件，此时会生成APP_HICOLLIE类型HiAppEvent事件。

**起始版本：** 24

**参数：**

| 参数项 | 描述 |
| -- | -- |
| bool isFreezeEvent | 上报事件类型。true：上报6S冻屏事件。false：上报3S冻屏事件。 |


> **说明：**
>
> BUSINESS_THREAD_BLOCK_3S、BUSINESS_THREAD_BLOCK_6S等同于BUSSINESS_THREAD_BLOCK_3S、BUSSINESS_THREAD_BLOCK_6S。

**返回：**

| 类型 | 说明 |
| -- | -- |
| [HiCollie_ErrorCode](capi-hicollie-h.md#hicollie_errorcode) | <ul><br>         <li> HICOLLIE_SUCCESS 0 - 成功。</li><br>         <li> OH_HICOLLIE_REACH_REPORT_LIMIT：29800007 - 上报频率过高。</li><br>         </ul> |

> **说明：**
>
> 1分钟内最多上报1次。
