# HiCollie


## 概述

本模块对外提供检测业务线程卡死、卡顿，以及上报卡死事件的能力。

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


### 类型定义

| 名称 | 描述 |
| -------- | -------- |
| typedef enum [HiCollie_ErrorCode](errorcode-hiviewdfx-hicollie.md) [HiCollie_ErrorCode](#hicollie_errorcode) | 错误码定义。 | 
| typedef void(\* [OH_HiCollie_Task](#oh_hicollie_task)) (void) | 函数指针, 用户自定义回调函数内容，该回调函数用于周期性检测应用业务线程任务执行情况。 | 
| typedef void(\* [OH_HiCollie_BeginFunc](#oh_hicollie_beginfunc)) (const char \*name) | 函数指针, 用户自定义回调函数内容，该回调函数放在应用业务线程处理事件之前。 | 
| typedef void(\* [OH_HiCollie_EndFunc](#oh_hicollie_endfunc)) (const char \*name) | 函数指针, 用户自定义回调函数内容，该回调函数放在应用业务线程处理事件之后。 | 
| typedef struct [HiCollie_DetectionParam](_hi_hicollie___detection_param.md) [HiCollie_DetectionParam](#hicollie_detectionparam) | 用户可以自定义检测业务线程卡顿的相关参数。 | 


## 类型定义说明


### HiCollie_ErrorCode

```
typedef enum HiCollie_ErrorCode HiCollie_ErrorCode
```

**描述**

错误码定义。

**起始版本：** 12


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


### HiCollie_DetectionParam

```
typedef struct HiCollie_DetectionParam HiCollie_DetectionParam
```

**描述**

用户可以自定义检测业务线程卡顿的相关参数，如：设置卡顿阈值。

**起始版本：** 12


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| HiCollie_ErrorCode [OH_HiCollie_Init_StuckDetection](_hi_hicollie.md#oh_hicollie_init_stuckdetection) (OH_HiCollie_Task task) | 注册应用业务线程卡死的周期性检测任务。  | 
| HiCollie_ErrorCode [OH_HiCollie_Init_JankDetection](_hi_hicollie.md#oh_hicollie_init_jankdetection) (OH_HiCollie_BeginFunc\* beginFunc, OH_HiCollie_EndFunc\* endFunc, HiCollie_DetectionParam param) | 注册应用业务线程卡顿检测的回调函数。  | 
| HiCollie_ErrorCode [OH_HiCollie_Report](_hi_hicollie.md#oh_hicollie_report) (bool\* isSixSecond) | 用于上报应用业务线程卡死事件，生成超时故障日志，辅助定位应用超时问题。结合OH_HiCollie_Init_StuckDetection接口配套使用，先初始化卡死检测，出现卡死时，再上报事件。  | 


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

返回设置回调函数结果。如果返回结果为0，代表初始化业务线程卡死检测成功。


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
