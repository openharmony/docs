# Main Thread Jank Event Overview

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @Chenyufan466765692-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

## Introduction

When the main thread of an application executes a time-consuming task, you may perceive jank. However, if the jank duration does not reach the threshold specified for [application freeze detection](appfreeze-guidelines.md), no fault log is generated. To better locate and analyze issues, you can refer to the [main thread jank event detection principles](apptask-timeout-guidelines.md#detection-principles) and analyze the execution status of main-thread tasks based on the generated [main thread jank event log specifications](apptask-timeout-guidelines.md#log-specifications).

This document introduces the detection principles for main thread jank and the meaning and specifications of related fields.

## Detection Principles

For details, see [main thread jank event detection principles](apptask-timeout-guidelines.md#main-thread-timeout-detection).

> **NOTE**
>
> When you install and start an application by clicking **Debug** in DevEco Studio, timeout detection for the current project is automatically disabled to prevent timeout detection from affecting the debugging process.

## Available APIs

To learn how to subscribe to main thread jank events through HiAppEvent, see the following documents. Both ArkTS and C/C++ APIs are available. Choose the one that fits your scenario.

- [Subscribing to Main Thread Jank Events (ArkTS)](hiappevent-watcher-mainthreadjank-events-arkts.md)

- [Subscribing to Main Thread Jank Events (C/C++)](hiappevent-watcher-mainthreadjank-events-ndk.md)

> **NOTE**
>
> Main thread jank events can be subscribed to through HiAppEvent in [application clones](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/app-clone) and atomic services. Since API version 22, this capability is also supported in [input method applications](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/inputmethod-application-guide).

## Custom Parameters

The **setEventConfig** API does not provide the capability to automatically stop stack sampling when a main thread jank event ends. Since API version 22, the **configEventPolicy** API is provided for this purpose.

### setEventConfig

| API| Description|
| -------- | -------- |
| [setEventConfig(name: string, config: Record&lt;string, ParamType>): Promise&lt;void>](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventseteventconfig15) | Sets parameters for main thread stack sampling. |

### Parameters of setEventConfig

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the main thread jank event. Use the constant **hiappevent.event.MAIN_THREAD_JANK**.|
| config | Record&lt;string, ParamType> | Yes| Configuration parameters for main thread jank stack sampling.|

The main thread jank stack sampling configuration parameters are defined as follows.

> **NOTE**
>
> **log_type** is mandatory.
>
> If **log_type** is **0** or **2**, do not set other parameters.
>
> If **log_type** is **1**, all parameters must be set.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| log_type | string | Yes| Type of **MAIN_THREAD_JANK** event logs to collect.<br>**log_type=0**: Default value. When the main thread times out twice in a row within 150 ms to 450 ms, call stacks are collected. When the main thread timeout reaches 450 ms, traces are collected.<br>**log_type=1**: Collect only call stacks.<br>**log_type=2**: Collect only traces.|
| sample_interval | string | No| Main thread jank detection interval and sampling interval, in ms.<br>Default value: **150**. Value range: [50, 500].<br>The system performs timeout detection based on the configured **sample_interval** and uses it as the interval for periodic task detection.|
| ignore_startup_time | string | No| Time during startup for which main thread jank detection is ignored, in seconds. Minimum value: **3**. Default value: **10**.<br>No timeout detection is performed for a period after the thread starts. Some processes take a long time to start, and collecting complete timeout sampling stacks during that period is of limited value. Therefore, detection is skipped within the custom startup interval.|
| sample_count | string | No| Number of samplings for main thread jank. When the system detects that the task execution duration of the current main thread reaches the sampling threshold, it periodically collects stacks, once at each interval, for a total of **sample_count** times.<br>Default value: **10**.<br>Minimum value: **1**. The maximum value must be dynamically calculated together with the custom **sample_interval**. Formula: **sample_count &lt;= (2500 / sample_interval - 4)**.|
| report_times_per_app | string | No| Number of reports for main thread jank stack sampling within the lifecycle of a PID for the same application. It can be configured only once within one lifecycle.<br>Default value: **1**, unit: times.<br>When **Developer options** is enabled, the range is [1, 3] per hour.<br>When **Developer options** is disabled, the range is [1, 3] per day.|

1. **sample_count**:

   (1) **2500** means that, according to the system rule, the time from detection to reporting of a main thread jank event cannot exceed 2.5 seconds (2500 ms). Therefore, the configured **sample_count** cannot exceed the maximum value calculated using the formula.

   (2) **4** means the first timeout interval detection time, the second timeout interval detection time (the system provides two chances to detect a repeated timeout event), and the time required to collect and report stack information.

   (3) Configure this parameter according to your scenario.

2. Parameter examples

   The following examples show **log_type** values **0**, **1**, and **2** for the **setEventConfig** API.

   (1) **log_type=0**, used to sample stacks or traces.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog, hiAppEvent } from '@kit.PerformanceAnalysisKit';

   let params: Record<string, hiAppEvent.ParamType> = {
     "log_type": "0"
   };
   hiAppEvent.setEventConfig(hiAppEvent.event.MAIN_THREAD_JANK, params).then(() => {
     hilog.info(0x0000, 'hiAppEvent', `Setting default value successfully.`);
   }).catch((err: BusinessError) => {
     hilog.error(0x0000, 'hiAppEvent', `Failed to set default value. Code: ${err.code}, message: ${err.message}`);
   });
   ```

   (2) **log_type=1**, used to collect only call stacks.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog, hiAppEvent } from '@kit.PerformanceAnalysisKit';

   let params: Record<string, hiAppEvent.ParamType> = {
     "log_type": "1",
     "sample_interval": "100",
     "ignore_startup_time": "11",
     "sample_count": "21",
     "report_times_per_app": "3"
   };
   hiAppEvent.setEventConfig(hiAppEvent.event.MAIN_THREAD_JANK, params).then(() => {
     hilog.info(0x0000, 'hiAppEvent', `Successfully set sampling stack parameters.`);
   }).catch((err: BusinessError) => {
     hilog.error(0x0000, 'hiAppEvent', `Failed to set sample stack value. Code: ${err.code}, message: ${err.message}`);
   });
   ```

   (3) **log_type=2**, used to collect only traces.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { hilog, hiAppEvent } from '@kit.PerformanceAnalysisKit';

   let params: Record<string, hiAppEvent.ParamType> = {
     "log_type": "2"
   };
   hiAppEvent.setEventConfig(hiAppEvent.event.MAIN_THREAD_JANK, params).then(() => {
     hilog.info(0x0000, 'hiAppEvent', `Set to only collect trace successfully.`);
   }).catch((err: BusinessError) => {
     hilog.error(0x0000, 'hiAppEvent', `Failed to set only collect trace. code: ${err.code}, message: ${err.message}`);
   });
   ```

### configEventPolicy

| API| Description|
| -------- | -------- |
| [configEventPolicy(policy: EventPolicy): Promise&lt;void>](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventconfigeventpolicy22) | Sets parameters for main thread stack sampling and supports automatically stopping sampling when jank ends. |

### Parameters of configEventPolicy

You can use the HiAppEvent APIs described above to configure stack sampling parameters in [EventPolicy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#eventpolicy22).

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| mainThreadJankPolicy | [MainThreadJankPolicy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#mainthreadjankpolicy22) | No| Yes| Configuration policy for main thread jank events.|

**Examples**

The following examples show **logType** values **0**, **1**, and **2** for the **configEventPolicy** API.

(1) **logType=0**, used to sample stacks or traces. Only **autoStopSampling** needs to be configured. Default values are used for other parameters.

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog, hiAppEvent } from '@kit.PerformanceAnalysisKit';

let policy: hiAppEvent.EventPolicy = {
  "mainThreadJankPolicy" : {
    "logType": 0, // Type of logs to collect.
    "autoStopSampling": true // Stop sampling when jank ends.
  }
};
hiAppEvent.configEventPolicy(policy).then(() => {
  hilog.info(0x0000, 'hiAppEvent', `Setting default value successfully.`);
}).catch((err: BusinessError) => {
  hilog.error(0x0000, 'hiAppEvent', `Failed to set default value. Code: ${err.code}, message: ${err.message}`);
});
```

(2) **logType=1**, used to collect only call stacks. The threshold for triggering detection is user-defined.

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog, hiAppEvent } from '@kit.PerformanceAnalysisKit';

let policy: hiAppEvent.EventPolicy = {
  "mainThreadJankPolicy" : {
    "logType": 1, // Type of logs to collect.
    "sampleInterval": 70, // Detection threshold and stack sampling interval.
    "ignoreStartupTime": 11, // Time during startup for which main thread jank detection is ignored.
    "sampleCount": 20, // Number of main thread jank samplings.
    "reportTimesPerApp": 3, // Number of main thread jank sampling reports.
    "autoStopSampling": true // Stop sampling when jank ends.
  }
};
hiAppEvent.configEventPolicy(policy).then(() => {
  hilog.info(0x0000, 'hiAppEvent', `Successfully set sampling stack parameters.`);
}).catch((err: BusinessError) => {
  hilog.error(0x0000, 'hiAppEvent', `Failed to set sample stack value. Code: ${err.code}, message: ${err.message}`);
});
```

(3) **logType=2**, used to collect only traces. Other parameters do not take effect and do not need to be set.

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog, hiAppEvent } from '@kit.PerformanceAnalysisKit';

let policy: hiAppEvent.EventPolicy = {
  "mainThreadJankPolicy" : {
    "logType": 2 // Type of logs to collect.
  }
};
hiAppEvent.configEventPolicy(policy).then(() => {
  hilog.info(0x0000, 'hiAppEvent', `Set to only collect trace successfully.`);
}).catch((err: BusinessError) => {
  hilog.error(0x0000, 'hiAppEvent', `Failed to set only collect trace. code: ${err.code}, message: ${err.message}`);
});
```

### OH_HiAppEvent_SetEventConfig

| API| Description|
| -------- | -------- |
| [int OH_HiAppEvent_SetEventConfig(const char\* name, HiAppEvent_Config\* config)](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md#oh_hiappevent_seteventconfig) | Sets parameters for main thread stack sampling. |

### Parameters of OH_HiAppEvent_SetEventConfig

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | const char\* | Yes| Name of the main thread jank event. The predefined macro can be **EVENT_MAIN_THREAD_JANK** or **EVENT_MAIN_THREAD_JANK_V2**.|
| config | HiAppEvent_Config\* | Yes| Configuration parameters for main thread jank stack sampling. You can use [OH_HiAppEvent_SetConfigItem](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md#oh_hiappevent_setconfigitem) to set items in **config**.|

**name** = **EVENT_MAIN_THREAD_JANK**

This API does not provide the capability to automatically stop stack sampling when a main thread jank event ends. Configure **config** as follows.

> **NOTE**
>
> **MAIN_THREAD_JANK_PARAM_LOG_TYPE** is mandatory.
>
> When **MAIN_THREAD_JANK_PARAM_LOG_TYPE** is **"0"** or **"2"**, no other configuration items are required.
>
> When **MAIN_THREAD_JANK_PARAM_LOG_TYPE** is **"1"**, all configuration items must be set.
>
> All configuration item values are string literals or character pointers that can be converted to integers.

For API version 21 and earlier, only related strings can be used as configuration item names.

For API version 22 and later, configuration item names can use predefined macros and related strings. Using macros is recommended to avoid unexpected results caused by manually written strings.

The following value ranges are described based on the converted variable types.

| Item| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| Macro: **MAIN_THREAD_JANK_PARAM_LOG_TYPE**<br>String: **log_type** | const char\* | Yes| Type of logs to collect.<br>**"0"**: Default value. When the main thread times out twice in a row within 150 ms to 450 ms, call stacks are collected. When the main thread timeout reaches 450 ms, traces are collected.<br>**"1"**: Collect only call stacks.<br>**"2"**: Collect only traces.|
| Macro: **MAIN_THREAD_JANK_PARAM_SAMPLE_INTERVAL**<br>String: **sample_interval** | const char\* | No| Main thread jank detection interval and sampling interval, in ms.<br>Default value: **150**. Value range: [50, 500].<br>The system performs timeout detection based on the configured **MAIN_THREAD_JANK_PARAM_SAMPLE_INTERVAL** and uses that value as the interval for periodic task detection.|
| Macro: **MAIN_THREAD_JANK_PARAM_IGNORE_STARTUP_TIME**<br>String: **ignore_startup_time** | const char\* | No| Time during startup for which main thread jank detection is ignored, in seconds.<br>Minimum value: **3**. Default value: **10**.<br>No timeout detection is performed for a period after the thread starts. Some processes take a long time to start, and collecting complete timeout sampling stacks during that period is of limited value. Therefore, detection is skipped within the custom startup interval.|
| Macro: **MAIN_THREAD_JANK_PARAM_SAMPLE_COUNT**<br>String: **sample_count** | const char\* | No| Number of samplings for main thread jank. When the system detects that the task execution duration of the current main thread reaches the sampling threshold, it periodically collects stacks, once at each interval, for a total of **MAIN_THREAD_JANK_PARAM_SAMPLE_COUNT** times.<br>Default value: **10**.<br>Minimum value: **1**. The maximum value must be dynamically calculated together with the custom **MAIN_THREAD_JANK_PARAM_SAMPLE_INTERVAL**. Formula: **MAIN_THREAD_JANK_PARAM_SAMPLE_COUNT &lt;= (2500 / MAIN_THREAD_JANK_PARAM_SAMPLE_INTERVAL - 4)**.|
| Macro: **MAIN_THREAD_JANK_PARAM_REPORT_TIMES_PER_APP**<br>String: **report_times_per_app** | const char\* | No| Number of reports for main thread jank stack sampling within the lifecycle of a PID for the same application. It can be configured only once within one lifecycle.<br>Default value: **1**, unit: times.<br>When **Developer options** is enabled, the range is [1, 3] per hour.<br>When **Developer options** is disabled, the range is [1, 3] per day.|

1. **MAIN_THREAD_JANK_PARAM_SAMPLE_COUNT**:

   (1) **2500** means that, according to the system rule, the time from detection to reporting of a main thread jank event cannot exceed 2.5 seconds (2500 ms). Therefore, the configured value of **MAIN_THREAD_JANK_PARAM_SAMPLE_COUNT** cannot exceed the maximum value calculated using the formula.

   (2) **4** means the first timeout interval detection time, the second timeout interval detection time (the system provides two chances to detect a repeated timeout event), and the time required to collect and report stack information.

   (3) Configure this parameter according to your scenario.

2. Parameter examples

   The following examples show **MAIN_THREAD_JANK_PARAM_LOG_TYPE** values **"0"**, **"1"**, and **"2"** in **config** for the **OH_HiAppEvent_SetEventConfig** API.

   (1) **MAIN_THREAD_JANK_PARAM_LOG_TYPE="0"**, used to sample stacks or traces.

   ```c++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hiappevent/hiappevent.h"

   #undef LOG_TAG
   #define LOG_TAG "testTag"

   HiAppEvent_Config* config = OH_HiAppEvent_CreateConfig();
   OH_HiAppEvent_SetConfigItem(config, MAIN_THREAD_JANK_PARAM_LOG_TYPE, "0");
   int ret = OH_HiAppEvent_SetEventConfig(EVENT_MAIN_THREAD_JANK, config);
   if (ret == HIAPPEVENT_SUCCESS) {
       OH_LOG_INFO(LogType::LOG_APP, "Setting default value successfully.");
   }
   OH_HiAppEvent_DestroyConfig(config);
   ```

   (2) **MAIN_THREAD_JANK_PARAM_LOG_TYPE="1"**, used to collect only call stacks.

   ```c++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hiappevent/hiappevent.h"

   #undef LOG_TAG
   #define LOG_TAG "testTag"

   HiAppEvent_Config* config = OH_HiAppEvent_CreateConfig();
   OH_HiAppEvent_SetConfigItem(config, MAIN_THREAD_JANK_PARAM_LOG_TYPE, "1");
   OH_HiAppEvent_SetConfigItem(config, MAIN_THREAD_JANK_PARAM_SAMPLE_INTERVAL, "100");
   OH_HiAppEvent_SetConfigItem(config, MAIN_THREAD_JANK_PARAM_IGNORE_STARTUP_TIME, "11");
   OH_HiAppEvent_SetConfigItem(config, MAIN_THREAD_JANK_PARAM_SAMPLE_COUNT, "21");
   OH_HiAppEvent_SetConfigItem(config, MAIN_THREAD_JANK_PARAM_REPORT_TIMES_PER_APP, "3");

   int ret = OH_HiAppEvent_SetEventConfig(EVENT_MAIN_THREAD_JANK, config);
   if (ret == HIAPPEVENT_SUCCESS) {
       OH_LOG_INFO(LogType::LOG_APP, "Successfully set sampling stack parameters.");
   }
   OH_HiAppEvent_DestroyConfig(config);
   ```

   (3) **MAIN_THREAD_JANK_PARAM_LOG_TYPE="2"**, used to collect only traces.

   ```c++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hiappevent/hiappevent.h"

   #undef LOG_TAG
   #define LOG_TAG "testTag"

   HiAppEvent_Config* config = OH_HiAppEvent_CreateConfig();
   OH_HiAppEvent_SetConfigItem(config, MAIN_THREAD_JANK_PARAM_LOG_TYPE, "2");

   int ret = OH_HiAppEvent_SetEventConfig(EVENT_MAIN_THREAD_JANK, config);
   if (ret == HIAPPEVENT_SUCCESS) {
       OH_LOG_INFO(LogType::LOG_APP, "Set to only collect trace successfully");
   }
   OH_HiAppEvent_DestroyConfig(config);
   ```

**name** = **EVENT_MAIN_THREAD_JANK_V2**

Since API version 22, **name** can be **EVENT_MAIN_THREAD_JANK_V2**. In this case, the API supports automatically stopping stack sampling when a main thread jank event ends. Configure **config** as follows.

> **NOTE**
>
> Configuration item names are related predefined macros.
>
> All configuration items in **config** are optional. If they are not configured or are empty, default values are used.
>
> When **MAIN_THREAD_JANK_PARAM_LOG_TYPE** is **"0"**, only **MAIN_THREAD_JANK_PARAM_AUTO_STOP_SAMPLING** needs to be set. Default values are used for other configuration items.
>
> When **MAIN_THREAD_JANK_PARAM_LOG_TYPE** is **"2"**, other configuration items do not take effect and do not need to be set.
>
> If **MAIN_THREAD_JANK_PARAM_AUTO_STOP_SAMPLING** is **"true"** or **"false"**, it is converted to the Boolean type. Values of other configuration items are string literals or character pointers that can be converted to integers.

The following value ranges are described based on the converted variable types.

| Item| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| MAIN_THREAD_JANK_PARAM_LOG_TYPE | const char\* | No| Type of logs to collect.<br>**"0"**: Default value. When the main thread times out twice in a row within 150 ms to 450 ms, call stacks are collected. When the main thread timeout reaches 450 ms, traces are collected.<br>**"1"**: Collect only call stacks.<br>**"2"**: Collect only traces.|
| MAIN_THREAD_JANK_PARAM_SAMPLE_INTERVAL | const char\* | No| Main thread jank detection interval and sampling interval, in ms.<br>Default value: **150**. Value range: [50, 500].<br>The system performs timeout detection based on the configured **MAIN_THREAD_JANK_PARAM_SAMPLE_INTERVAL** and uses that value as the interval for periodic task detection.|
| MAIN_THREAD_JANK_PARAM_IGNORE_STARTUP_TIME | const char\* | No| Time during startup for which main thread jank detection is ignored, in seconds.<br>Minimum value: **3**. Default value: **10**.<br>No timeout detection is performed for a period after the thread starts. Some processes take a long time to start, and collecting complete timeout sampling stacks during that period is of limited value. Therefore, detection is skipped within the custom startup interval.|
| MAIN_THREAD_JANK_PARAM_SAMPLE_COUNT | const char\* | No| Number of samplings for main thread jank. When the system detects that the task execution duration of the current main thread reaches the sampling threshold and exceeds the sampling limit, it starts periodically collecting stacks, once at each interval, for a total of **MAIN_THREAD_JANK_PARAM_SAMPLE_COUNT** times.<br>Default value: **10**.<br>Minimum value: **1**. The maximum value must be dynamically calculated together with the custom **MAIN_THREAD_JANK_PARAM_SAMPLE_INTERVAL**. Formula: **MAIN_THREAD_JANK_PARAM_SAMPLE_COUNT &lt;= (2500 / MAIN_THREAD_JANK_PARAM_SAMPLE_INTERVAL - 4)**.|
| MAIN_THREAD_JANK_PARAM_REPORT_TIMES_PER_APP | const char\* | No| Number of reports for main thread jank stack sampling within the lifecycle of a PID for the same application. It can be configured only once within one lifecycle.<br>Default value: **1**, unit: times.<br>When **Developer options** is enabled, the range is [1, 3] per hour.<br>When **Developer options** is disabled, the range is [1, 3] per day.|
| MAIN_THREAD_JANK_PARAM_AUTO_STOP_SAMPLING | const char\* | No| Whether to automatically stop main thread stack sampling when a main thread jank event ends.<br>**true**: Sampling stops when jank ends or when the configured sampling count is reached.<br>**false**: Sampling stops only when the configured sampling count is reached.<br>Default value: **false**.|

1. **MAIN_THREAD_JANK_PARAM_SAMPLE_COUNT**:

   (1) **2500** means that, according to the system rule, the time from detection to reporting of a main thread jank event cannot exceed 2.5 seconds (2500 ms). Therefore, the configured value of **MAIN_THREAD_JANK_PARAM_SAMPLE_COUNT** cannot exceed the maximum value calculated using the formula.

   (2) **4** means the first timeout interval detection time, the second timeout interval detection time (the system provides two chances to detect a repeated timeout event), and the time required to collect and report stack information.

   (3) Configure this parameter according to your scenario.

2. Parameter examples

   The following examples show **MAIN_THREAD_JANK_PARAM_LOG_TYPE** values **"0"**, **"1"**, and **"2"** in **config** for the **OH_HiAppEvent_SetEventConfig** API.

   (1) **MAIN_THREAD_JANK_PARAM_LOG_TYPE="0"**, used to sample stacks or traces.

   ```c++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hiappevent/hiappevent.h"

   #undef LOG_TAG
   #define LOG_TAG "testTag"

   HiAppEvent_Config* config = OH_HiAppEvent_CreateConfig();
   OH_HiAppEvent_SetConfigItem(config, MAIN_THREAD_JANK_PARAM_LOG_TYPE, "0");
   OH_HiAppEvent_SetConfigItem(config, MAIN_THREAD_JANK_PARAM_AUTO_STOP_SAMPLING, "true");
   int ret = OH_HiAppEvent_SetEventConfig(EVENT_MAIN_THREAD_JANK_V2, config);
   if (ret == HIAPPEVENT_SUCCESS) {
       OH_LOG_INFO(LogType::LOG_APP, "Setting default value successfully.");
   }
   OH_HiAppEvent_DestroyConfig(config);
   ```

   (2) **MAIN_THREAD_JANK_PARAM_LOG_TYPE="1"**, used to collect only call stacks.

   ```c++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hiappevent/hiappevent.h"

   #undef LOG_TAG
   #define LOG_TAG "testTag"

   HiAppEvent_Config* config = OH_HiAppEvent_CreateConfig();
   OH_HiAppEvent_SetConfigItem(config, MAIN_THREAD_JANK_PARAM_LOG_TYPE, "1");
   OH_HiAppEvent_SetConfigItem(config, MAIN_THREAD_JANK_PARAM_SAMPLE_INTERVAL, "100");
   OH_HiAppEvent_SetConfigItem(config, MAIN_THREAD_JANK_PARAM_IGNORE_STARTUP_TIME, "11");
   OH_HiAppEvent_SetConfigItem(config, MAIN_THREAD_JANK_PARAM_SAMPLE_COUNT, "21");
   OH_HiAppEvent_SetConfigItem(config, MAIN_THREAD_JANK_PARAM_REPORT_TIMES_PER_APP, "3");
   OH_HiAppEvent_SetConfigItem(config, MAIN_THREAD_JANK_PARAM_AUTO_STOP_SAMPLING, "true");

   int ret = OH_HiAppEvent_SetEventConfig(EVENT_MAIN_THREAD_JANK_V2, config);
   if (ret == HIAPPEVENT_SUCCESS) {
       OH_LOG_INFO(LogType::LOG_APP, "Successfully set sampling stack parameters.");
   }
   OH_HiAppEvent_DestroyConfig(config);
   ```

   (3) **MAIN_THREAD_JANK_PARAM_LOG_TYPE="2"**, used to collect only traces.

   ```c++
   #include "napi/native_api.h"
   #include "hilog/log.h"
   #include "hiappevent/hiappevent.h"

   #undef LOG_TAG
   #define LOG_TAG "testTag"

   HiAppEvent_Config* config = OH_HiAppEvent_CreateConfig();
   OH_HiAppEvent_SetConfigItem(config, MAIN_THREAD_JANK_PARAM_LOG_TYPE, "2");

   int ret = OH_HiAppEvent_SetEventConfig(EVENT_MAIN_THREAD_JANK_V2, config);
   if (ret == HIAPPEVENT_SUCCESS) {
       OH_LOG_INFO(LogType::LOG_APP, "Set to only collect trace successfully");
   }
   OH_HiAppEvent_DestroyConfig(config);
   ```

## Event Fields

| Name| Type| Description|
| -------- | -------- | -------- |
| time | number | Time when the event is triggered, in ms.|
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| pid | number | Process ID of the application.|
| uid | number | User ID of the application.|
| begin_time | number | Start time of the main thread task.|
| end_time | number | End time of the main thread task.|
| external_log | string[] | Path of the main thread jank log file. **To prevent new log files from failing to be written because the directory storage exceeds the limit (see `log_over_limit`), delete the log files promptly after they are processed.**|
| log_over_limit | boolean | Whether the total size of generated main thread jank log files and existing log files exceeds the upper limit of 10 MB. The value **true** indicates that the limit is exceeded and log writing fails. The value **false** indicates that the limit is not exceeded.|
| app_start_jiffies_time | number | When developers obtain a main thread jank event, this field indicates the task start time. **If stack sampling is triggered, the start time information is printed.**|
| heaviest_stack | string | Call stack information printed multiple times in the generated main thread jank log file. **If stack sampling is triggered, repeatedly printed call stack information is included.**|
