# Main Thread Jank Event Overview

## Introduction

When an application's main thread executes a time-consuming task, you may detect that the application freezes. However, the freeze time does not reach the threshold specified by [application freeze detection](appfreeze-guidelines.md). Therefore, no fault log is generated. To better locate and analyze problems, you can use [main thread jank event detection principles](apptask-timeout-guidelines.md) and [main thread jank event log specifications](apptask-timeout-guidelines.md) to proactively analyze the task execution status of the main thread.

## Detection Principles

For details, see [main thread jank event detection principles](apptask-timeout-guidelines.md#detection-principles).

## Available APIs

You can use the APIs provided by HiAppEvent to subscribe to the main thread jank event **hiAppEvent.event.MAIN_THREAD_JANK**. When the system detects a main thread jank event, it captures maintenance and debugging information and sends the callback to the application process through HiAppEvent.

- [Subscribing to Main Thread Jank Events (ArkTS)](hiappevent-watcher-mainthreadjank-events-arkts.md)

- [Subscribing to Main Thread Jank Events (C/C++)](hiappevent-watcher-mainthreadjank-events-ndk.md)

## Custom Parameters

### Available APIs

| API| Description|
| -------- | -------- |
| setEventConfig(name: string, config: Record&lt;string, ParamType>): Promise&lt;void> | Sets the parameters of the main thread jank event that triggers the stack sampling. Currently, only the **MAIN_THREAD_JANK** event parameter can be customized. Therefore, the value of **name** is **MAIN_THREAD_JANK**. |

### Setting Parameters

You can use the API provided by HiAppEvent to customize the parameters for collecting the **MAIN_THREAD_JANK** event in **Record<string, ParamType>**.

> **NOTE**
>
> When **log_type** is set to **0** or **2**, you do not need to set other parameters.
>
> When **log_type** is set to **1**, configure the following parameters: **sample_interval**, **ignore_startup_time**, **sample_count**, and **report_times_per_app**.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| log_type | string | Yes| Type of MAIN_THREAD_JANK event logs to collect.<br>**log_type=0**: When the main thread experiences two consecutive timeouts between 150 ms and 450 ms, a call stack capture is triggered. When the timeout exceeds 450 ms, a trace capture is triggered. This is the default value.<br>**log_type=1**: Only the call stack is captured, and the threshold for triggering the detection is customized.<br>**log_type=2**: Only the trace data is captured.|
| sample_interval | string | No| Interval for the main thread jank event detection and sampling, in milliseconds.<br>The value range is [50, 500].<br>The system performs the check based on the custom interval and uses the interval for the periodic check.|
| ignore_startup_time | string | No| Time window after thread startup during which no checks are performed, in seconds. The minimum value is **3** and the default value is **10**.<br>Do not perform timeout detection within a specified period of time after the thread is started. For the process that takes time to start, it is not necessary to capture the full stack. You can set this parameter to prevent the check from being performed within the custom startup time.|
| sample_count | string | No| Number of sampling times for the main thread jank event. After detecting that the main thread processing time exceeds the threshold, the system starts periodic stack sampling for **sample_count** times.<br>The minimum value is 1. The maximum value can be calculated based on the custom value of **sample_interval** as follows: <br>**sample_count** ≤ (2500/**sample_interval** - 4)|
| report_times_per_app | string | No| Number of sampling reporting times for the main thread jank event of the processes with the same PID of an application. This parameter can be set only once for the processes with the same PID.<br>Default value: **1**<br>When the **Developer options** is enabled, the value range is [1, 3] per hour.<br>When the **Developer options** is disabled, the value range is [1, 3] per day.|

1. **sample_count**:
   (1) The value **2500** (ms) indicates the maximum time allowed for a main thread jank event to be reported after being detected. Therefore, the value of **sample_count** cannot be greater than the maximum value calculated based on the formula.

   (2) The value **4** indicates the number of check intervals, that is, the first check interval, the twice second check intervals, and the interval for collecting and reporting stack information.

   (3) You need to set the parameters as required.

2.  
   The following examples describe how to configure the triggering conditions for the **MAIN_THREAD_JANK** event using three types of **log_type**.

   (1) Set **log_type** to **0** to sample the stack or trace.

   ```
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

   (2) Set **log_type** to **1** to collect only the call stack.

   ```
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

   (3) Set **log_type** to **2** to collect only the trace.

   ```
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

## Event Fields

| Name| Type| Description|
| -------- | -------- | -------- |
| time | number | Event triggering time, in ms.|
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| pid | number | Process ID of the application.|
| uid | number | User ID of the application.|
| begin_time | number | Begin time of a task in the main thread.|
| end_time | number | End time of a task in the main thread.|
| external_log | string[] | Path of the generated log files. If the directory files exceed the threshold (for details, see **log_over_limit**), new log files may fail to be written. Therefore, delete the log files immediately after they are processed.|
| log_over_limit | boolean | Whether the size of generated log files and existing log files exceeds the upper limit (10 MB). The value **true** indicates that the upper limit is exceeded and logs fail to be written. The value **false** indicates that the upper limit is not exceeded.|
| app_start_jiffies_time | number | Start time of the task when the main thread jank event occurs. The information is printed in the sampling stack.|
| heaviest_stack | string | Call stack that is generated multiple times in the log file. The information is printed in the sampling stack.|
