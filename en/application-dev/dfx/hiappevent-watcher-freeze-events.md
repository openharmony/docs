# Application Freeze Event Overview
<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @rr_cn-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## Overview

AppFreeze (application freeze) means that an application does not respond to user operations (for example, clicking) for a specified period of time. To address application freeze problems, the system provides the application freeze detection, maintenance and debugging log capturing, and log reporting capabilities to help you locate faults.

## Detection Principles

For details, see [Application Freeze Detection Principles](appfreeze-guidelines.md#detection-principles).

## Available APIs

You can subscribe to the application freeze event **hiAppEvent.event.APP_FREEZE** using the APIs provided by HiAppEvent. When detecting an application freeze, the system captures maintenance and debugging information and sends the freeze event to the application process through HiAppEvent.

- [Subscribing to Application Freeze Events (ArkTS)](hiappevent-watcher-freeze-events-arkts.md)

- [Subscribing to Application Freeze Events (C/C++)](hiappevent-watcher-freeze-events-ndk.md)

## Event Fields

### params

The **params** attribute in the event information is described as follows.

| Name| Type| Description|
| -------- | -------- | -------- |
| time | number | Event triggering time, in ms.|
| foreground | boolean | Whether the application is running in the foreground. The value **true** indicates that the application is in the foreground, and the value **false** indicates the opposite.|
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| process_name | string | Process name of the application.|
| pid | number | Process ID of an application.|
| uid | number | User ID of an application.|
| uuid | string | Error ID, which is generated based on fault information and uniquely identifies crash faults of the same type.|
| exception | object | Exception information. For details, see **exception**.|
| hilog | string[] | Log information.|
| event_handler | string[] | Events not yet handled by the main thread.|
| event_handler_size_3s | string | Number of tasks in the task stack at 3s during the [THREAD_BLOCK_6S event](appfreeze-guidelines.md#thread_block_6s-application-main-thread-timeout). This parameter is available only in the application freeze event.|
| event_handler_size_6s | string | Number of tasks in the task stack at 6s during the [THREAD_BLOCK_6S event](appfreeze-guidelines.md#thread_block_6s-application-main-thread-timeout). This parameter is available only in the application freeze event.|
| peer_binder | string[] | Binder call information.|
| threads | object[] | Full thread call stack. For details, see **thread**.|
| memory | object | Memory information. For details, see **memory**.|
| external_log<sup>12+</sup> | string[] | Path of the error log file. If the directory files exceed the threshold (for details, see **log_over_limit**), new log files may fail to be written. Therefore, delete the log files immediately after they are processed.|
| log_over_limit<sup>12+</sup> | boolean | Whether the size of generated fault log files and existing log files exceeds the upper limit (5 MB). The value **true** indicates that the upper limit is exceeded and logs fail to be written. The value **false** indicates that the upper limit is not exceeded.|

### exception

| Name| Type| Description|
| -------- | -------- | -------- |
| name | string | Exception type.|
| message | string | Exception cause.|

### thread

| Name| Type| Description|
| -------- | -------- | -------- |
| thread_name | string | Thread name.|
| tid | number | Thread ID.|
| frames | object[] | Thread call stack. For details, see **frame**.|

### frame

Native frame

| Name| Type| Description|
| -------- | -------- | -------- |
| symbol | string | Function name. If the name length exceeds 256 bytes, the name is deleted to prevent unknown issues.|
| file | string | File name.|
| buildId | string | Unique file ID. The file may not contain **buildId**. For details, see [Log Specifications](cppcrash-guidelines.md#common-faults).|
| pc | string | Hexadecimal byte offset of the executed instruction within the file.|
| offset | number | Byte offset of the executed instruction within the function.|

JS frame

| Name| Type| Description|
| -------- | -------- | -------- |
| file | string | File name.|
| packageName | string | Package name of the module.|
| symbol | string | Function name.|
| line | number | Code line number.|
| column | number | Code line number.|

### memory

| Name| Type| Description|
| -------- | -------- | -------- |
| rss | number | Size of the memory allocated for a process, in KB.|
| vss | number | Size of the virtual memory applied by a process from the system, in KB.|
| pss | number | Size of the physical memory actually used by a process, in KB.|
| sys_free_mem | number | Size of free memory, in KB.|
| sys_avail_mem | number | Size of available memory, in KB.|
| sys_total_mem | number | Total memory size, in KB.|

## Customizing Parameters for Application Freeze Events

### Available APIs

| Name| Description|
| -------- | -------- |
| setEventParam(params: Record&lt;string, ParamType>, domain: string, name?: string): Promise&lt;void> | Sets custom parameters for application freeze events.|

### Setting Parameters

You can use this API to subscribe to the application freeze event **hiAppEvent.event.APP_FREEZE**. For details, see [hiAppEvent.setEventParam](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventseteventparam12).
