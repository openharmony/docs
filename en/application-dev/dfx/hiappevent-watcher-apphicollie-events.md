# Task Execution Timeout Event Overview

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @Chenyufan466765692-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @jinqiuheng-->

## Overview

Task execution timeout means that the execution duration of the service code logic to be monitored exceeds the expected duration. To better locate and analyze issues, you can use the [Task Execution Timeout Detection](apptask-timeout-guidelines.md#task-execution-timeout-detection) mechanism and analyze task execution timeouts based on the generated [log specifications](apptask-timeout-guidelines.md#log-specifications).

This document describes the detection principles for task execution timeout and the meaning and specifications of related fields.

## Detection Principles

For details, see [Task Execution Timeout Detection Principles](apptask-timeout-guidelines.md#task-execution-timeout-detection).

## Available APIs

To learn how to subscribe to task execution timeout events through HiAppEvent, see the following documents. Both ArkTS and C/C++ APIs are available. Choose the one that fits your scenario.

- [Subscribing to Task Execution Timeout Events (ArkTS)](hiappevent-watcher-apphicollie-events-arkts.md)

- [Subscribing to Task Execution Timeout Events (C/C++)](hiappevent-watcher-apphicollie-events-ndk.md)

> **NOTE**
>
> Task execution timeout events can be subscribed to through HiAppEvent in [application clones](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/app-clone). They are not supported in atomic services. Since API version 22, this capability is also supported in [input method applications](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/inputmethod-application-guide).

## Event Fields

### params

The **params** field in task execution timeout event information is described as follows:

| Name| Type| Description|
| -------- | -------- | -------- |
| time | number | Time when the event is triggered, in ms.|
| foreground | boolean | Whether the application is in the foreground. The value **true** indicates that the application is in the foreground, and **false** indicates that it is in the background.|
| bundle_version | string | Application version.|
| process_name | string | Process name of the application.|
| pid | number | Process ID of the application.|
| uid | number | User ID of the application.|
| uuid | string | Fault fingerprint generated from fault information and used to identify crash faults with the same characteristics.|
| exception | object | Exception information. For details, see [exception](#exception).|
| hilog | string[] | Log information.|
| peer_binder | string[] | Binder call information, including the binder call chain and related stack capture information.|
| memory | object | Memory information. For details, see [memory](#memory).|
| external_log | string[] | Path of the fault log file. **To prevent new log files from failing to be written because the directory storage exceeds the limit (see `log_over_limit`), delete the log files promptly after they are processed.**|
| log_over_limit | boolean | Whether the total size of generated fault log files and existing log files exceeds the upper limit of 5 MB. The value **true** indicates that the limit is exceeded and log writing fails. The value **false** indicates that the limit is not exceeded.<br>When minidump is enabled, the upper limit is adjusted to 35 MB. When minidump is disabled, the upper limit is restored to 5 MB.|
| external_callback_log | string | Custom callback log information, which can be written through [OH_HiCollie_SetFreezeCallback](../reference/apis-performance-analysis-kit/capi-hicollie-h.md#oh_hicollie_setfreezecallback).<br>**NOTE**: Supported since API version 24.|

### exception

The **exception** field is described as follows:

| Name| Type| Description|
| -------- | -------- | -------- |
| name | string | Exception type.|
| message | string | Cause of the exception.|

### memory

The **memory** field is described as follows:

| Name| Type| Description|
| -------- | -------- | -------- |
| rss | number | Actual memory used by the process, in KB.|
| vss | number | Virtual memory requested by the process from the system, in KB.|
| pss | number | Physical memory actually used by the process, in KB.|
| sys_free_mem | number | Free memory size, in KB.|
| sys_avail_mem | number | Available memory size, in KB.|
| sys_total_mem | number | Total memory size, in KB.|
