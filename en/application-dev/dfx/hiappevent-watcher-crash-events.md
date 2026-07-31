# Crash Event Overview

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @chenshi51-->
<!--Designer: @Maplestory91-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=2127b60c8b93aed6c0fbd46139186a0afec1bcc8 translatedAt=2026-07-31T01:27:14.624Z pushedAt=2026-07-31T03:43:02.254Z -->

## Overview

A crash is an unexpected exit of an application process. Specifically, crash events occur in the following scenarios:

1. **NativeCrash** events are generated when the native code does not process [crash signals](cppcrash-guidelines.md#crash-signals).

2. **JsError** events are generated when ArkTS/JS code does not process exceptions.

This topic describes the crash event detection principles, field meanings, and specifications. For details about how to use the ArkTs and C/C++ APIs provided by HiAppEvent to subscribe to system crash events, see the following documents: Currently, ArkTS and C/C++ APIs are provided. You can select the APIs as required.

- [Subscribing to Crash Events (ArkTS)](hiappevent-watcher-crash-events-arkts.md)

- [Subscribing to Crash Events (C/C++)](hiappevent-watcher-crash-events-ndk.md)

> **NOTE**
>
> Crash events can be subscribed to using HiAppEvent in [application clones](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/app-clone) and atomic services. Since API version 22, HiAppEvent can be used to subscribe to crash events in [input method applications](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/inputmethod-application-guide)

## Detection Principles

### NativeCrash

Based on the POSIX signal mechanism, the process crash detection capability of the system is implemented as follows: When a process crashes, it receives a crash signal, enters the system signal registration handling process, collects crash information, generates an event, and reports the event to the crash event subscriber of the application process.

The system detects a process crash as follows:

1. After a process crashes, it receives a crash signal from the kernel, which is processed by the signal processing module registered by the process during startup.

2. After receiving the crash signal, the process saves the current process context and forks a child process to execute the ProcessDump command to capture crash information.

3. After collecting crash information, the ProcessDump process reports it to the HiView process. The HiView process stores the event information in the [application sandbox](../file-management/app-sandbox-directory.md).

4. The crash event watcher registered by HiAppEvent listens for the file changes in the application sandbox directory and delivers the event callback to the application process.

### JsError

In ArkTS, the JsError crash detection detects global exceptions, collects the error object types (such as **Error**, **TypeError**, and **ReferenceError**), and reports them to the HiView process. The HiView process stores the event information in the [application sandbox](../file-management/app-sandbox-directory.md). The crash event watcher registered by HiAppEvent listens for the file changes in the application sandbox directory and delivers the event callback to the application process, helping you quickly locate and rectify faults.

## Customizing Specifications

### setEventConfig API Description

Since API version 20, crash log specifications can be customized.

The system provides the common NativeCrash log generation feature and allows you to set crash log parameters to meet your requirements.

| Name| Description|
| -------- | -------- |
| setEventConfig(name: string, config: Record&lt;string, ParamType>): Promise&lt;void> | Sets crash log parameters. The **name** parameter must be set to the crash event name constant **hiappevent.event.APP_CRASH**. This API supports only **NativeCrash**.|

### setEventConfig Parameter Setting Description

You can set the crash log printing specifications in **Record <string, ParamType>** by using the API provided by HiAppEvent. The specific parameter descriptions are as follows.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| extend_pc_lr_printing | boolean | No| The value **true** means to print the memory values of the 248 bytes before and 256 bytes after the PC and LR in the 64-bit system, or print the memory values of the 124 bytes before and 128 bytes after the PC and LR in the 32-bit system.<br>The value **false** means to print the memory values of the 16 bytes before and 232 bytes after the PC and LR in the 64-bit system, or print the memory values of the 8 bytes before and 116 bytes after the PC and LR in the 32-bit system.<br>Default value: **false**.|
| log_file_cutoff_sz_bytes | number | No | Unit: byte. Value range: [0, 5242880].<br/>If set, the crash log size is truncated as per the configured parameter value.<br/>If not set, the default value 0 indicates that crash logs are not truncated. |
| simplify_vma_printing | boolean | No| The value **true** means to print only the Virtual Memory Area (VMA) mapping information of the addresses in the crash log, that is, **Maps** in the crash log, to reduce the log size.<br>The value **false** means to print all VMA mapping information.<br>Default value: **false**.|

The following is an example of parameter configuration:

```text
let configParams: Record<string, hiAppEvent.ParamType> = {
    "extend_pc_lr_printing": true, // Enable the functionality of printing the memory values near the PC and LR.
    "log_file_cutoff_sz_bytes": 102400, // Truncate the crash log to 100 KB.
    "simplify_vma_printing": true // Enable simplified printing of maps.
};
```

Taking a 64-bit system as an example, refer to [Subscribing to Crash Events (ArkTS)](hiappevent-watcher-crash-events-arkts.md#how-to-develop) to complete crash event subscription and log configuration parameter settings, and then obtain the NativeCrash type crash log content through the [external_log](#params) field. The log prints the following list of enabled configuration parameters:

```text
...
Build info:OpenHarmony 6.0.0.33
Enabled app log configs:    <- List of enabled configuration parameters. Only the configuration parameters that are not set to the default values are printed.
Extend pc lr printing:true  <- Set extend_pc_lr_printing to true.
Log cut off size:102400B    <- Truncate the crash log to 100 KB.
Simplify maps printing:true <- Set simplify vma_printing to true.
Timestamp:2025-05-17 19:17:07.000
...
```

For details about the crash log, see [Application Crash Log Configured by HiAppEvent](cppcrash-guidelines.md#application-crash-log-configured-by-hiappevent).

### OH_HiAppEvent_SetEventConfig

Starting from **API version 24**, crash log specification customization is supported, such as printing the memory content of the extended byte range of the PC and LR registers, truncating crash logs, printing the VMA to which addresses appearing in the crash log belong, and merging app logs. When an app crash fault occurs, the system can collect and report the crash log according to the set crash log specifications, helping you locate issues.

Starting from **API version 26.0.0**, enabling [minidump](performance-analysis-kit-terminology.md#minidump) is supported.

| API | Description |
| --- | --- |
| int [OH_HiAppEvent_SetEventConfig](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md#oh_hiappevent_seteventconfig)(const char* name, HiAppEvent_Config* config) | Custom crash log specification setting, an API for merging app logs. **Only supports NativeCrash type crashes.**|

### OH_HiAppEvent_SetEventConfig Parameter Settings

| Name | Type | Mandatory | Description |
| --- | --- | --- | --- |
| name | const char* | Yes | App crash event name, which is the macro **EVENT_APP_CRASH**. |
| config | HiAppEvent_Config* | Yes | App crash event configuration parameter. You can use the [OH_HiAppEvent_SetConfigItem](../reference/apis-performance-analysis-kit/capi-hiappevent-h.md#oh_hiappevent_setconfigitem) function to set configuration items for the config parameter. |

| Configuration Item Name | Type | Mandatory Configuration | Description |
| --- | --- | --- | --- |
| Macro: OH_APP_CRASH_PARAM_EXTEND_PC_LR_PRINTING<br/>String: extend_pc_lr_printing | const char* | No | Whether to print the memory content in the extended byte range of PC and LR registers.<br/>"true": For a 64-bit system, prints the memory values in the range of 248 bytes forward and 256 bytes backward from the PC and LR register addresses. For a 32-bit system, prints the memory values in the range of 124 bytes forward and 128 bytes backward from the PC and LR register addresses.<br/>"false": For a 64-bit system, prints the memory values in the range of 16 bytes forward and 232 bytes backward from the PC and LR register addresses. For a 32-bit system, prints the memory values in the range of 8 bytes forward and 116 bytes backward from the PC and LR register addresses.<br/>Default when omitted: "false".<br>**Note:** Supported from API version 24. |
| Macro: OH_APP_CRASH_PARAM_LOG_FILE_CUTOFF_SZ_BYTES<br/>String: log_file_cutoff_sz_bytes | const char* | No | Whether to truncate the crash log (CPP_CRASH log, minidump), in bytes. Value range: [0, 5242880].<br/>If set, the crash log size is truncated as specified by the parameter value.<br/>If not set, the default value 0 indicates that the crash log is not truncated.<br>**Note:** Supported from API version 24. |
| Macro: OH_APP_CRASH_PARAM_SIMPLIFY_VMA_PRINTING<br/>String: simplify_vma_printing | const char* | No | Whether to print the VMA (Virtual Memory Area) mapping information to which the addresses appearing in the crash log belong.<br/>"true": Prints only the VMA mapping information (i.e., Maps in the crash log) to which the addresses appearing in the crash log belong, to reduce the log size.<br/>"false": Prints all VMA mapping information.<br/>Default when omitted: "false".<br>**Note:** Supported from API version 24. |
| Macro: OH_APP_CRASH_PARAM_MERGE_CPPCRASH_APP_LOG<br/>String: merge_cppcrash_app_log | const char* | No | Whether to merge app sandbox logs.<br/>"true": Merges app logs in the Native Crash scenario.<br/>"false": Does not merge app-generated logs.<br/>The app log path read by the framework is: sandbox path + app package name + _CppCrash_AppMerge.log, for example: /data/storage/el2/log/com.samples.eventsub_CppCrash_AppMerge.log<br/>If you choose to generate the merged log in the signal handler, the maximum generation time is 5s. If it exceeds 5s, the app-generated log cannot be merged.<br/>**NOTE**<br/>The merged log generated by the app must exist in the sandbox path.<br>**Note:** Supported from API version 24. |
| Macro: OH_APP_CRASH_PARAM_COLLECT_MINIDUMP<br/>String: collect_minidump | const char* | No | Whether to enable minidump. The default value is "false".<!--RP1--><br/>"true": The upper limit of the total size of generated and existing fault log files determined by the log_over_limit field in [params](#params) is adjusted to 35 MB.<br/>"false": The upper limit of the total size of generated and existing fault log files determined by the log_over_limit field is restored to 5 MB.<!--RP1End--><br/>**Note:** This configuration item is persistent. The value remains unchanged until the app resets it.<br>Supported from API version 26.0.0. |

The following is an example of parameter configuration:

For OH_HiAppEvent_SetEventConfig configuration, refer to [Subscribing to Crash Events (C/C++)](hiappevent-watcher-crash-events-ndk.md#how-to-develop) to complete crash event subscription and log configuration parameter settings, and then obtain the crash log file path through the [external_log](#params) field.

### configEventPolicy

Starting from **API version 24**, page switch log configuration is supported. When an app crash occurs, the system can collect and report the page switch log, helping you locate issues.

Starting from **API version 26.0.0**, crash log specification customization is supported. The system provides the common NativeCrash log generation feature and allows you to set crash log configuration parameters to meet your customization requirements for log content.

| API | Description |
| -------- | -------- |
| [configEventPolicy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventconfigeventpolicy22) (policy: EventPolicy): Promise&lt;void>| Sets crash event policy parameters, including enabling page switching log collection for crash events and setting crash log configuration parameters. This API uses a promise to return the result. |

### configEventPolicy Parameter Settings

You can set crash log configuration parameters and enable page switch log collection for crash events by configuring the parameters of [EventPolicy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#eventpolicy22).

| Name       | Type    | Read-only | Optional | Description                                         |
| ---------- | ------- | ---- | ---- | ------------------------------------------ |
| appCrashPolicy | [AppCrashPolicy](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#appcrashpolicy24) | No | Yes   | Crash event configuration policy. |

The following is an example of parameter configuration:

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog, hiAppEvent } from '@kit.PerformanceAnalysisKit';

let policy: hiAppEvent.EventPolicy = {
    appCrashPolicy: {
      pageSwitchLogEnable: true, // Enable page switching logging. Supported from API version 24.
      extendPcLrPrinting: true, // Enable extended printing of memory values near the PC and LR registers. Supported from API version 26.0.0.
      logFileCutoffSzBytes: 102400, // Truncate the crash log to 100 KB. Supported from API version 26.0.0.
      simplifyVmaPrinting: true, // Enable simplified maps printing. Supported from API version 26.0.0.
      collectMinidump: true // In native crash scenarios, enable minidump. Supported from API version 26.0.0.
    }
};
hiAppEvent.configEventPolicy(policy).then(() => {
    hilog.info(0x0000, 'hiAppEvent', `Set crash config policy successfully.`);
}).catch((err: BusinessError) => {
    hilog.error(0x0000, 'hiAppEvent', `Failed to set crash config policy. code: ${err.code}, message: ${err.message}`);
});
```

## Fields

### params

**params** is the event parameter object in [AppEventInfo](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#appeventinfo), which consists of a parameter name and a parameter value.

The fields contained in **params** of a system event are defined by the event.

The following table lists the common information predefined in the crash event.

| Name| Type| Description|
| -------- | -------- | -------- |
| time | number | Event triggering time, in ms.|
| crash_type | string | Crash type, which can be **NativeCrash** (native exception) or **JsError** (JS exception). For details about the detection method, see [C++ Crash (Process Crash) Detection](cppcrash-guidelines.md) and [JS Crash (Process Crash) Detection](jscrash-guidelines.md).|
| foreground | boolean | Whether the application is running in the foreground. The value **true** indicates that the application is in the foreground, and the value **false** indicates the opposite.|
| release_type | string | Application version type. The value **release** indicates that the application is a [release-type application](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-compilation-options-customizing-guide#section192461528194916), and the value **debug** indicates that the application is a [debug-type application](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-compilation-options-customizing-guide#section192461528194916).<br>Note: This field is supported since API version 23.|
| cpu_abi | string | ABI type.<br>Note: This field is supported since API version 23.|
| app_running_unique_id | string | Unique ID associated with the app runtime.<br>**Note:** This parameter is supported since API version 24. |
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| pid | number | Process ID of an application.|
| uid | number | User ID of an application.|
| uuid | string | Error ID, which is generated based on fault information and uniquely identifies crash faults of the same type.|
| exception | object | Exception information. For details, see [exception](#exception). Contains brief fault information. For complete fault information, see the external_log file. |
| hilog | string[] | Log information, which displays a maximum of 100 lines of HiLog logs. For more logs, see the fault log file.|
| process_life_time | number | Lifetime of the faulty process, in seconds.<br>Note: This field is supported since API version 22.|
| memory | object | Memory information. For details, see [memory](#memory).<br>Note: This field is supported since API version 22.|
| threads | object[] | Full thread call stack. For details, see [thread](#thread). This field applies only to **NativeCrash** events.|
| external_log<sup></sup> | string[] | Path to the fault log file in the [application sandbox directory](../file-management/app-sandbox-directory.md). You can read the fault log file content through the path. **To prevent new log file write failures caused by directory space exceeding the limit, delete log files promptly after processing. For the limit specification, see the log_over_limit field.** |
| log_over_limit | boolean | Whether the total size of generated and existing fault log files exceeds the 5 MB upper limit. The value **true** indicates that the limit is exceeded and log writing fails; **false** indicates that the limit is not exceeded.<br>When [minidump](performance-analysis-kit-terminology.md#minidump) is enabled, the upper limit is adjusted to 35 MB; when minidump is disabled, the upper limit is restored to 5 MB. |
| process_name | string | Name of the faulty process.<br>Note: This field is supported since API version 21.|
| page_switch_log | string | Page transition log path. For details about the log, see [Page Switch Logs](pageswitch-log.md).<br>**Note:** Supported since API version 24. |

### exception

**exception** of **JsError**

| Name| Type| Description|
| -------- | -------- | -------- |
| name | string | Exception type.|
| message | string | Exception cause.|
| stack | string | Exception call stack.|
| thread_name | string | Thread name.<br>Note: This field is supported since API version 21.|
| caught_by_errormanager | boolean | Whether the error manager capture is registered. true: The error manager capture is registered; false: The error manager capture is not registered.<br>**Note:** This field is supported from API version 26.0.0. |
| uncatchable_fault | boolean | Whether it is an uncatchable exception type. Currently, only OutOfMemoryError is included. true: Uncatchable exception type; false: Catchable exception type.<br>**Note:** This field is supported from API version 26.0.0. |

**exception** of **NativeCrash**

| Name| Type| Description|
| -------- | -------- | -------- |
| message | string | Exception cause.|
| signal | object | Signal information. For details, see [signal](#signal).|
| thread_name | string | Thread name.|
| tid | number | Thread ID.|
| frames | object[] | Thread call stack. For details, see [frame](#frame).|

### signal

For details, see [C++ Crash (Process Crash) Detection Implementation Principles](cppcrash-guidelines.md#implementation-principles).

| Name| Type| Description|
| -------- | -------- | -------- |
| signo | number | Signal value.|
| code | number | Level-2 signal category.|
| address | string | Address where an access error occurs.|

### thread

| Name| Type| Description|
| -------- | -------- | -------- |
| thread_name | string | Thread name.|
| tid | number | Thread ID.|
| frames | object[] | Thread call stack. For details, see [frame](#frame).|

### frame

Native **frame**

| Name| Type| Description|
| -------- | -------- | -------- |
| file | string | File name.|
| symbol | string | Function name. The symbol may be empty due to the following reasons:<br>1. The function name is not saved in the binary file.<br>2. The function name is deleted because it contains more than 256 bytes.|
| buildId | string | Build ID from the **.note.gnu.build-id** section of the ELF file. |
| pc | string | Hexadecimal byte offset of the executed instruction within the file.|
| offset | number | Byte offset of the executed instruction within the function.|

For details, see [Call stack frame](cppcrash-guidelines.md#common-faults).

Js **frame**

| Name| Type| Description|
| -------- | -------- | -------- |
| file | string | File name.|
| packageName | string | Package name of the module.|
| symbol | string | Function name.|
| line | number | Code line number.|
| column | number | Code column number.|

For details, see [JS hybrid stack frame](cppcrash-guidelines.md#common-faults).

### memory

| Name| Type| Description|
| -------- | -------- | -------- |
| rss | number | Actual memory size occupied by the process, in KB. Corresponds to the Process Memory field in the [cppcrash log](cppcrash-guidelines.md#log-specifications) or [jscrash log](jscrash-guidelines.md#log-specifications). |
| sys_free_mem | number | Free memory size, in KB. Corresponds to the Free value of the Device Memory field in the [cppcrash log](cppcrash-guidelines.md#log-specifications) or [jscrash log](jscrash-guidelines.md#log-specifications). |
| sys_avail_mem | number | Available memory size, in KB. Corresponds to the Available value of the Device Memory field in the [cppcrash log](cppcrash-guidelines.md#log-specifications) or [jscrash log](jscrash-guidelines.md#log-specifications). |
| sys_total_mem | number | Total memory size, in KB. Corresponds to the Total value of the Device Memory field in the [cppcrash log](cppcrash-guidelines.md#log-specifications) or [jscrash log](jscrash-guidelines.md#log-specifications). |

## Customizing Crash Event Parameters

Currently, the crash event reports common system crash information, which may not meet your specific requirements. Therefore, the **setEventParam** method is provided to customize event reporting information.

### APIs

| Name| Description|
| -------- | -------- |
| setEventParam(params: Record&lt;string, ParamType>, domain: string, name?: string): Promise&lt;void> | Sets custom event parameters.|