# Crash Event Overview
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @chenshi51-->
<!--Designer: @Maplestory-->
<!--Tester: @yufeifei-->
<!--Adviser: @foryourself-->

## Overview

A crash is an unexpected exit of an application process. Specifically, crash events occur in the following scenarios:

1. **NativeCrash** events are generated when the native code does not process [crash signals](cppcrash-guidelines.md#crash-signals).

2. **JsError** events are generated when ArkTS/JS code does not process exceptions.

This topic describes the crash event detection principles, field meanings, and specifications. For details about how to use the ArkTs and C/C++ APIs provided by HiAppEvent to subscribe to system crash events, see the following documents: Currently, ArkTS and C/C++ APIs are provided. You can select the APIs as required.

- [Subscribing to Crash Events (ArkTS)](hiappevent-watcher-crash-events-arkts.md)

- [Subscribing to Crash Events (C/C++)](hiappevent-watcher-crash-events-ndk.md)

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

## Customizing Crash Log Specifications

Since API version 20, crash log specifications can be customized.

The system provides the common **NativeCrash** log generation functionality. However, some applications have specific requirements on the **NativeCrash** log content. Therefore, you need to set crash log parameters.

### **Available APIs**

| Name| Description|
| -------- | -------- |
| setEventConfig(name: string, config: Record&lt;string, ParamType>): Promise&lt;void> | Sets crash log parameters. The **name** parameter must be set to the crash event name constant **hiappevent.event.APP_CRASH**. This API supports only **NativeCrash**.|

### **Parameters**

You can set the crash log printing specifications in **Record <string, ParamType>** by using the API provided by HiAppEvent. The specific parameter descriptions are as follows.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| extend_pc_lr_printing | boolean | No| The value **true** means to print the memory values of 248 bytes before and 256 bytes after the PC and LR on 64-bit system, or 124 bytes before and 128 bytes after on 32-bit systems.<br>The value **false** means to print the memory values of 16 bytes before and 232 bytes after the PC and LR on 64-bit system, or 8 bytes before and 116 bytes after on 32-bit systems.<br>Default value: **false**.|
| log_file_cutoff_sz_bytes | number | No| The value ranges from 0 to 5242880, in bytes.<br>The crash log is truncated to the specified size when this parameter is set.<br>Otherwise, the default value **0** is used, which means no truncation.|
| simplify_vma_printing | boolean | No| The value **true** means to print only the Virtual Memory Area (VMA) mapping information of the addresses in the crash log, that is, **Maps** in the crash log, to reduce the log size.<br>The value **false** means to print all VMA mapping information.<br>Default value: **false**.|

The following is an example of parameter settings:

```text
let configParams: Record<string, hiAppEvent.ParamType> = {
    "extend_pc_lr_printing": true, // Enable the functionality of printing the memory values near the PC and LR.
    "log_file_cutoff_sz_bytes": 102400, // Truncate the crash log to 100 KB.
    "simplify_vma_printing": true // Enable simplified printing of maps.
};
```

For example, on the 32-bit system, subscribe to crash events and set log configuration parameters by referring to [Subscribing to Crash Events (ArkTS)](hiappevent-watcher-crash-events-arkts.md#how-to-develop) and obtain the **NativeCrash** log content through the [external_log](#params) field. The following enabled configuration parameters are printed in the log:

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

## Fields

### params

The **params** parameter in the event information is described as follows.

| Name| Type| Description|
| -------- | -------- | -------- |
| time | number | Event triggering time, in ms.|
| crash_type | string | Crash type, which can be **NativeCrash** (native exception) or **JsError** (JS exception). For details about the detection method, see [C++ Crash (Process Crash) Detection](cppcrash-guidelines.md) and [JS Crash (Process Crash) Detection](jscrash-guidelines.md).|
| foreground | boolean | Whether the application is running in the foreground. The value **true** indicates that the application is in the foreground, and the value **false** indicates the opposite.|
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| pid | number | Process ID of an application.|
| uid | number | User ID of an application.|
| uuid | string | Error ID, which is generated based on fault information and uniquely identifies crash faults of the same type.|
| exception | object | Exception information in brief. For details, see [exception](#exception). For details about all fault information, see the **external_log** file.|
| hilog | string[] | Log information, which displays a maximum of 100 lines of HiLog logs. For more logs, see the fault log file.|
| threads | object[] | Full thread call stack. For details, see [thread](#thread). This field applies only to **NativeCrash** events.|
| external_log<sup></sup> | string[] | [Application sandbox path](../file-management/app-sandbox-directory.md) of the fault log file. You can read the fault log file through the path. To avoid failed writing of new log files due to insufficient directory space, delete the log files after they are processed. For details about the threshold, see the **log_over_limit** field.|
| log_over_limit | boolean | Whether the total size of the generated and existing fault log files exceeds the upper limit 5 MB. The value **true** indicates that the upper limit is exceeded and logs fail to be written. The value **false** indicates that the upper limit is not exceeded.|

### exception

**exception** of **JsError**

| Name| Type| Description|
| -------- | -------- | -------- |
| name | string | Exception type.|
| message | string | Exception cause.|
| stack | string | Exception call stack.|

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
| buildId | string | Unique file ID. The file may not contain **buildId**. For details, see [C++ Crash (Process Crash) Log Specifications](cppcrash-guidelines.md#common-faults).|
| pc | string | Hexadecimal byte offset of the executed instruction within the file.|
| offset | number | Byte offset of the executed instruction within the function.|

Js **frame**

| Name| Type| Description|
| -------- | -------- | -------- |
| file | string | File name.|
| packageName | string | Package name of the module.|
| symbol | string | Function name.|
| line | number | Code line number.|
| column | number | Code column number.|

## Customizing Crash Event Parameters

Currently, the crash event reports common system crash information, which may not meet your specific requirements. Therefore, the **setEventParam** method is provided to customize event reporting information.

### APIs

| Name| Description|
| -------- | -------- |
| setEventParam(params: Record&lt;string, ParamType>, domain: string, name?: string): Promise&lt;void> | Sets custom event parameters.|
